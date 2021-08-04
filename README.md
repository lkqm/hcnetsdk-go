# hcnetsdk-go

海康网络HCNetSDK二次封装的Go库.

```
go get github.com/lkqm/hcnetsdk-go
```

## 示例
```
// Get Device Time
func main() {
	userId, err := hcnetsdk.Login(ip, port, user, password)
	if err != nil {
		fmt.Printf("Login device error: %s", err)
		return
	}
	date, err := hcnetsdk.GetDeviceTime(userId)
	if err != nil {
		fmt.Printf("Get device time error: %s", err)
		return
	}
	fmt.Printf("Current device time: %s", date)
}
```

提示: 依赖于cgo调用海康提供动态库, 需要安装c编译环境, windows下推荐使用MinGW.

## 特性

- 登录 (Login)
- 注销 (Logout)
- 执行操作 (DoAction)
- 获取错误 (LastError)
- 布防 (SetupAlarm)
- 透传 (PassThrough)
- 设备配置 (GetNvrConfig, SetNvrConfig)
- 修改密码 (ModifyPassword)
- ...
