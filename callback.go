package hcnetsdk

/*
#cgo CFLAGS: -I./include
#cgo windows LDFLAGS: -L${SRCDIR}/libs/windows -lHCCore -lHCNetSDK
#cgo linux LDFLAGS: -L${SRCDIR}/libs/linux -lHCCore -lHCNetSDK
#cgo darwin LDFLAGS: -L${SRCDIR}/libs/darwin -lHCCore -lHCNetSDK
#include "HCNetSDK.h"
*/
import "C"
import (
	"unsafe"
)

//------------------消息回调------------------//

var messageCallBackHooks = make(map[int]MessageCallBack)

type MessageCallBack func(lCommand uint32, pAlarmer *NetDvrAlarmer, pAlarmInfo []byte, pUserData unsafe.Pointer) int32

//export fMSGCallBackGo
func fMSGCallBackGo(lCommand C.LONG, pAlarmer C.LPNET_DVR_ALARMER, pAlarmInfo *C.char, dwBufLen C.DWORD, pUser unsafe.Pointer) C.BOOL {
	userId := int(pAlarmer.lUserID)
	callback := messageCallBackHooks[userId]
	if callback != nil {
		alarmer := (*NetDvrAlarmer)(unsafe.Pointer(pAlarmer))
		buffer := C.GoBytes(unsafe.Pointer(pAlarmInfo), C.int(dwBufLen))
		return C.BOOL(callback(uint32(lCommand), alarmer, buffer, pUser))
	}
	return C.BOOL(1)
}

//------------------异常回调------------------//

var exceptionCallBackHooks = make(map[int]ExceptionCallBack)

type ExceptionCallBack func(dwType uint32, lUserID int32, lHandle int32, pUser interface{})

//export fExceptionCallBackGo
func fExceptionCallBackGo(dwType C.DWORD, lUserID C.LONG, lHandle C.LONG, pUser *C.void) {
	callback := exceptionCallBackHooks[int(lUserID)]
	if callback != nil {
		callback(uint32(dwType), int32(lUserID), int32(lHandle), pUser)
	}
}

//------------------视频流回调------------------//

var realDataCallBackHooks = make(map[int]RealDataCallBack)

type RealDataCallBack func(lPlayHandle int32, dwDataType uint32, pbuffer []byte, dwBufSize uint32, pUser interface{})

//export fRealDataCallBackGo
func fRealDataCallBackGo(lPlayHandle C.LONG, dwDataType C.DWORD, pBuffer *C.BYTE, dwBufSize C.DWORD, pUser *C.void) {
	userData := *(*realDataCallBackDataWrapper)(unsafe.Pointer(pUser))
	callback := realDataCallBackHooks[userData.UserId]
	if callback != nil {
		bytes := C.GoBytes(unsafe.Pointer(pBuffer), C.int(dwBufSize))
		callback(int32(lPlayHandle), uint32(dwDataType), bytes, uint32(dwBufSize), userData.Data)
	}
}

// 用户自定义数据包装
type realDataCallBackDataWrapper struct {
	UserId int         // 用户登录句柄
	Data   interface{} // 传递数据
}
