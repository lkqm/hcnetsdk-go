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
	"github.com/lkqm/hcnetsdk/model"
	"unsafe"
)

//------------------消息回调------------------//
var messageCallBackHooks = make(map[int]MSGCallBackFunc)

type MSGCallBackFunc func(lCommand uint32, pAlarmer *model.NetDvrAlarmer, pAlarmInfo []byte, pUserData unsafe.Pointer) int32

//export fMSGCallBackGo
func fMSGCallBackGo(lCommand C.LONG, pAlarmer C.LPNET_DVR_ALARMER, pAlarmInfo *C.char, dwBufLen C.DWORD, pUser unsafe.Pointer) C.BOOL {
	userId := int(pAlarmer.lUserID)
	messageCallBackHook := messageCallBackHooks[userId]
	if messageCallBackHook != nil {
		alarmer := (*model.NetDvrAlarmer)(unsafe.Pointer(pAlarmer))
		buffer := C.GoBytes(unsafe.Pointer(pAlarmInfo), C.int(dwBufLen))
		return C.BOOL(messageCallBackHook(uint32(lCommand), alarmer, buffer, pUser))
	}
	return C.BOOL(1)
}

//------------------异常回调------------------//

var exceptionCallBackHooks = make(map[int]FExceptionCallBackFunc)

type FExceptionCallBackFunc func(dwType uint32, lUserID int32, lHandle int32, pUser unsafe.Pointer)

//export fExceptionCallBackGo
func fExceptionCallBackGo(dwType C.DWORD, lUserID C.LONG, lHandle C.LONG, pUser *C.void) {
	exceptionCallBackHook := exceptionCallBackHooks[int(lUserID)]
	if exceptionCallBackHook != nil {
		exceptionCallBackHook(uint32(dwType), int32(lUserID), int32(lHandle), unsafe.Pointer(pUser))
	}
}

//------------------视频流回调------------------//

var realDataCallBackHooks = make(map[int]FRealDataCallBackFunc)

type FRealDataCallBackFunc func(lPlayHandle int32, dwDataType uint32, pbuffer []byte, dwBufSize uint32, pUser unsafe.Pointer)

//export fRealDataCallBackGo
func fRealDataCallBackGo(lPlayHandle C.LONG, dwDataType C.DWORD, pBuffer *C.BYTE, dwBufSize C.DWORD, pUser *C.void) {
	userId := *(*int)(unsafe.Pointer(pUser))
	realDataCallBackHook := realDataCallBackHooks[userId]
	if realDataCallBackHook != nil {
		bytes := C.GoBytes(unsafe.Pointer(pBuffer), C.int(dwBufSize))
		realDataCallBackHook(int32(lPlayHandle), uint32(dwDataType), bytes, uint32(dwBufSize), unsafe.Pointer(pUser))
	}
}
