package model

import (
	"strings"
	"unsafe"
)

/*
 * 设备信息
 */
type DeviceInfo struct {
	UserId       int  // 登录Id
	Ip           string // 设备ip
	DeviceName   string // 设备名称
	SerialNumber string // 设备序列号
	MacAddr      string // 设备mac地址
}

func NewDeviceInfo(alarm *NetDvrAlarmer) *DeviceInfo {
	d := new(DeviceInfo)
	if alarm.ByUserIDValid == 1 {
		d.UserId = int(alarm.LUserID)
	}
	if alarm.ByDeviceIPValid == 1 {
		d.Ip = newString(alarm.SDeviceIP[:])
	}
	if alarm.ByDeviceNameValid == 1 {
		d.DeviceName = newString(alarm.SDeviceName[:])
	}
	if alarm.BySerialValid == 1 {
		d.SerialNumber = newString(alarm.SSerialNumber[:])
	}
	if alarm.ByMacAddrValid == 1 {
		d.MacAddr = newString(alarm.ByMacAddr[:])
	}
	return d
}

/**
 * ISAPI协议透传响应结果
 */
type PassThroughResponse struct {
	Bytes  []byte         // 数据
	Status ResponseStatus // 状态
}

type ResponseStatus struct {
	RequestUrl    string `xml:"requestURL"`    // 请求的地址
	StatusCode    int32  `xml:"statusCode"`    // 状态码
	SubStatusCode int32  `xml:"subStatusCode"` // 子状态码
	StatusString  string `xml:"statusString"`  // 状态码描述
}

type DvrUpgradeParam struct {
	UpgradeType uint32
	Filename    string
	Inbuffer    unsafe.Pointer
	BufferLen   uint32
}

type UpgradeResponse struct {
	Handle int64 // 升级句柄
	State  int   // 升级状态
}

func newString(bytes []byte) string {
	return strings.TrimRight(string(bytes), string(rune(0)))
}
