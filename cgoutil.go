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
	"strings"
	"time"
	"unsafe"
)

func newString(bytes []byte) string {
	return strings.TrimRight(string(bytes), string(rune(0)))
}

// cgo复制C.BYTE切片数组
func cgoCopyBytesByCBytes(bytes []C.byte) []byte {
	return C.GoBytes(unsafe.Pointer(&bytes[0]), C.int(len(bytes)))
}

// cgo转换C.BYTE数组到字符串, 自动去除末尾0字节
func cgoConvertCBytesToString(bytes []C.byte) string {
	return strings.TrimRight(string(cgoCopyBytesByCBytes(bytes)), string(rune(0)))
}

// 布尔值代表的数字
func boolIntValue(value bool) int {
	if value {
		return 1
	}
	return 0
}

// 转换海康的时间轴
func convertHikAbsTime(absTime uint32) int64 {
	year := int(absTime>>26 + 2000)
	month := int(absTime >> 22 & 15)
	day := int(absTime >> 17 & 31)
	hour := int(absTime >> 12 & 31)
	minute := int(absTime >> 6 & 63)
	second := int(absTime & 63)

	date := time.Date(year, time.Month(month), day, hour, minute, second, 0, time.UTC)
	return date.Unix() * 1000
}

// 转换海康时间类型: NET_DVR_DATE
func convertNetDvrDate(dvrDate C.NET_DVR_DATE) time.Time {
	year := int(dvrDate.wYear)
	month := time.Month(int(dvrDate.byMonth))
	day := int(dvrDate.byDay)
	return time.Date(year, month, day, 0, 0, 0, 0, time.UTC)
}
