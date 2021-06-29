package hcnetsdk

import (
	"bytes"
	"fmt"
	"github.com/lkqm/hcnetsdk/model"
	"io"
	"io/ioutil"
	"os"
	"testing"
	"time"
	"unsafe"
)

func TestLogin(t *testing.T) {
	userId, _ := testBeforeLogin(t)
	testAfterLogout(userId, t)
}

func TestDoAction(t *testing.T) {
	_, err := DoAction(testDevice1.host, testDevice1.username, testDevice1.password, func(userId int) (interface{}, *model.HcnetsdkError) {
		return IsOnline(userId), nil
	})
	if err != nil {
		t.Errorf("执行失败：%s", err)
		return
	}
}

func TestReboot(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}

	err = Reboot(userId)
	if err != nil {
		t.Errorf("重启设备失败：%s", err)
	}
}

func TestIsOnline(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}
	online := IsOnline(userId)
	if !online {
		t.Errorf("设备应该是在线")
	}
}

func TestSetupDeploy(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}
	handle, err := SetupDeploy(userId, testMessageCallBack, testExceptionCallBack)
	if err != nil {
		t.Errorf("布防失败：%s", err)
		return
	}
	if handle < 0 {
		t.Errorf("布防失败：%s", err)
		return
	}
	time.Sleep(120 * time.Second)
}

func testMessageCallBack(lCommand uint32, pAlarmer *model.NetDvrAlarmer, pAlarmInfo []byte, pUserData unsafe.Pointer) int32 {
	if lCommand == 4370 {
		print(pAlarmer)
	}
	return 1
}

func testExceptionCallBack(dwType uint32, lUserID int32, lHandle int32, pUser unsafe.Pointer) {
	fmt.Print(lUserID)
}

func TestRealPlay(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}
	handle, err := RealPlay(userId, testRealDataCallBack)
	if err != nil {
		t.Errorf("设置实时流回调：%s", err)
		return
	}
	if handle < 0 {
		t.Errorf("设置实时流回调：%s", err)
		return
	}
	time.Sleep(10 * time.Second)
	_, _ = StopRealPlay(int(handle))
}

var testVideoHeaderBytes []byte // 视频头信息

func testRealDataCallBack(lPlayHandle int32, dwDataType uint32, pbuffer []byte, dwBufSize uint32, pUser unsafe.Pointer) {
	if dwDataType == 1 {
		// 头数据
		testVideoHeaderBytes = pbuffer
	} else if dwDataType == 2 && dwBufSize > 0 {
		// 视频流
		videoFile := "/tmp/test.mp4"
		if _, err := os.Stat(videoFile); os.IsNotExist(err) {
			err := ioutil.WriteFile(videoFile, testVideoHeaderBytes, os.ModePerm)
			if err != nil {
				fmt.Print("写入头文件失败:", err)
			}
		}
		file, err := os.OpenFile(videoFile, os.O_APPEND|os.O_WRONLY, 0666)
		if err != nil {
			fmt.Println("打开文件失败")
		}
		defer file.Close()
		_, err = io.Copy(file, bytes.NewReader(pbuffer))
		if err != nil {
			fmt.Print("写入视频文件失败: ", err)
		}
	}
}

func TestGetDeviceTime(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}
	deviceTime, err := GetDeviceTime(userId)
	if err != nil {
		t.Errorf("获取设备时间失败：%s", err)
		return
	}
	if deviceTime == nil {
		t.Errorf("获取设备时间失败：%s", err)
		return
	}
	t.Log("当前设备时间：", deviceTime)
}

func TestSetDeviceTime(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}
	err = SetDeviceTime(userId, time.Now())
	if err != nil {
		t.Errorf("设置设备时间失败：%s", err)
		return
	}
}

func TestPassThrough(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}
	xml := `
<?xml version="1.0" encoding="UTF-8"?><DeviceInfo xmlns="http://www.hikvision.com/ver20/XMLSchema" version="2.0">
<deviceName>IP CAMERA</deviceName>
<deviceID>d9b04000-d0fb-11b2-80e4-988b0a0e517f</deviceID>
<deviceDescription>IPCamera</deviceDescription>
<deviceLocation>hangzhou</deviceLocation>
<systemContact>Hikvision.China</systemContact>
<model>DS-2CD7A47FWD-XZS</model>
<serialNumber>DS-2CD7A47FWD-XZS20190228AACHC96234444</serialNumber>
<macAddress>98:8b:0a:0e:51:7f</macAddress>
<firmwareVersion>V5.6.1</firmwareVersion>
<firmwareReleasedDate>build 190603</firmwareReleasedDate>
<encoderVersion>V7.3</encoderVersion>
<encoderReleasedDate>build 190527</encoderReleasedDate>
<bootVersion>V1.3.4</bootVersion>
<bootReleasedDate>100316</bootReleasedDate>
<hardwareVersion>0x0</hardwareVersion>
<deviceType>IPCamera</deviceType>
<telecontrolID>88</telecontrolID>
<supportBeep>false</supportBeep>
<supportVideoLoss>false</supportVideoLoss>
<firmwareVersionInfo>B-R-H3-0</firmwareVersionInfo>
</DeviceIno>
`
	response, err := PassThrough(userId, "PUT /ISAPI/System/deviceInfo", xml)
	if err != nil {
		t.Errorf("透传失败：%s", err)
		return
	}
	t.Log("透传结果：", response)
}

func TestModifyPassword(t *testing.T) {
	userId, err := testBeforeLogin(t)
	if err != nil {
		return
	}
	err = ModifyPassword(userId, testDevice1.username, "wxb123456")
	if err != nil {
		t.Errorf("修改密码失败：%s", err)
		return
	}
	// 还原密码
	err = ModifyPassword(userId, testDevice1.username, testDevice1.password)
	if err != nil {
		t.Errorf("还原修改密码失败: %s", err)
	}
	return
}

func TestGetSdkVersion(t *testing.T) {
	version := GetSdkVersion()
	t.Log("当前sdk版本", version)
}
