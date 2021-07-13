package hcnetsdk

import (
	"testing"
)

type deviceInfo struct {
	ip       string
	port     int
	username string
	password string
}

var testDevice1 = &deviceInfo{ip: "192.168.0.199", port: 8000, username: "admin", password: "kjl442333"}

func testBeforeLogin(t *testing.T) (int, error) {
	userId, err := Login(testDevice1.ip, testDevice1.port, testDevice1.username, testDevice1.password)
	if err != nil {
		t.Errorf("登录失败: %s", err)
	} else if userId < 0 {
		t.Errorf("登录返回userId错误: %d", userId)
	}
	return userId, err
}

func testAfterLogout(userId int, t *testing.T) {
	err := Logout(userId)
	if err != nil {
		t.Errorf("注销失败：%s", err)
	}
	Close()
}
