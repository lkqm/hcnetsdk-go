package hcnetsdk

import (
	"unsafe"
)

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
