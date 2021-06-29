package model

import "strconv"

type HcnetsdkError struct {
	Code int  `json:"Code"` // 错误码
	Msg  string `json:"Msg"`  // 错误码描述
}

func NewHcnetsdkError(code int, msg string) *HcnetsdkError {
	return &HcnetsdkError{Code: code, Msg: msg}
}

func (p *HcnetsdkError) Error() string {
	return strconv.FormatInt(int64(p.Code), 10) + "," + p.Msg
}

/**
 * 是否是密码或用户名错误.
 */
func (p *HcnetsdkError) IsPasswordError() bool {
	return p.Code == 1
}

/**
 * 是否是设备离线错误.
 */
func (p *HcnetsdkError) IsDeviceOfflineError() bool {
	return p.Code == 7
}
