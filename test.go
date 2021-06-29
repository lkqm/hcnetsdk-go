package hcnetsdk

import (
	"github.com/lkqm/hcnetsdk/model"
	"testing"
)

type deviceInfo struct {
	host     string
	username string
	password string
}

var testDevice1 = &deviceInfo{host: "192.168.0.199", username: "admin", password: "kjl442333"}

func testBeforeLogin(t *testing.T) (int, *model.HcnetsdkError) {
	userId, err := Login(testDevice1.host, testDevice1.username, testDevice1.password)
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
