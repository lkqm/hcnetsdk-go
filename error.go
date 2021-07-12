package hcnetsdk

import "C"
import (
	"strconv"
)

// 海康网络sdk自定义错误
type HcnetError struct {
	Code int    `json:"Code"` // 错误码
	Msg  string `json:"Msg"`  // 错误码描述
}

func NewHcnetsdkError(code int, msg string) *HcnetError {
	return &HcnetError{Code: code, Msg: msg}
}

func (p *HcnetError) Error() string {
	return strconv.FormatInt(int64(p.Code), 10) + "," + p.Msg
}

func (p *HcnetError) IsPasswordError() bool {
	return p.Code == 1
}

func (p *HcnetError) IsDeviceOfflineError() bool {
	return p.Code == 7
}
