package model

// 保持go数据类型和c类型映射一致

//==================公共==================//
// 坐标
type NetVcaRect struct {
	FX      float32 // 边界框左上角点的X轴坐标，取值范围[0.000,1]
	FY      float32 // 边界框左上角点的Y轴坐标，取值范围[0.000,1]
	FWidth  float32 // 边界框的宽度，取值范围[0.000,1]
	FHeight float32 // 边界框的高度，取值范围[0.000,1]
}

// 设备信息
type NetVcaDevInfo struct {
	StruDevIP     NetDvrIpAddr // 报警通道对应设备的IP地址
	WPort         uint16       // 报警通道对应设备的端口号
	ByChannel     byte         // 警通道对应设备的通道号，参数值即表示通道号。比如，byChannel=1，表示通道1
	ByIvmsChannel byte         // SDK接入设备的通道号
}

// 告警目标信息
type NetVcaTargetInfo struct {
	DwID    uint32     // 目标ID，人员密度过高报警时为0
	TruRect NetVcaRect // 目标边界框
	ByRes   [4]byte    // 保留，置为0
}

// IP地址
type NetDvrIpAddr struct {
	SIpV4 [16]byte
	SIpV6 [128]byte
}

// 日期
type NetDvrDate struct{
	WYear uint16
	ByMonth byte
	ByDay byte
}

// 时间
type NetDvrTimeV30 struct{
	WYear uint16
	ByMonth byte
	ByDay byte
	ByHour  byte
	ByMinute byte
	BySecond byte
	ByISO8601 byte
	WMilliSec  uint16
	CTimeDifferenceH uint8
	CTimeDifferenceM uint8
}

//==================公共结束==================//

// 回调消息
type NetDvrAlarmer struct {
	ByUserIDValid     byte
	BySerialValid     byte
	ByVersionValid    byte
	ByDeviceNameValid byte
	ByMacAddrValid    byte
	ByLinkPortValid   byte
	ByDeviceIPValid   byte
	BySocketIPValid   byte
	LUserID           int32
	SSerialNumber     [48]byte
	DwDeviceVersion   uint32
	SDeviceName       [32]byte
	ByMacAddr         [6]byte
	WLinkPort         uint16
	SDeviceIP         [128]byte
	SSocketIP         [128]byte
	ByIpProtocol      byte
	ByRes2            [11]byte
}

// 人脸抓拍结果
type NetVcaFaceSnapResult struct {
	DwSize                    uint32             // 结构体大小
	DwRelativeTime            uint32             // 相对时标
	DwAbsTime                 uint32             // 绝对时标
	DwFacePicID               uint32             // 人脸图ID，用于人脸跟踪时产生轨迹，像行为分析一样保存在码流信息里面有播放库去解析并显示轨迹
	DwFaceScore               uint32             // 人脸评分，范围：0~100
	StruTargetInfo            NetVcaTargetInfo   // 报警目标信息
	StruRect                  NetVcaRect         // 人脸子图区域
	StruDevInfo               NetVcaDevInfo      // 前端设备信息
	DwFacePicLen              uint32             // 人脸子图的长度，为0表示没有图片，大于0表示有图片
	DwBackgroundPicLen        uint32             // 背景图的长度，为0表示没有图片，大于0表示有图片(保留)
	BySmart                   byte               // 0- iDS设备返回（默认值），1- SMART设备返回
	ByAlarmEndMark            byte               // 报警结束标记：0- 保留，1- 结束标记（该字段结合人脸ID字段使用，表示该ID对应的下报警结束，用于判断报警结束，提取识别图片数据中，清晰度最高的图片）
	ByRepeatTimes             byte               // 重复报警次数：0-无意义
	ByUploadEventDataType     byte               // 人脸图片数据长传方式：0-二进制数据，1-URL
	StruFeature               NetVcaHumanFeature // 人体属性
	FStayDuration             float32            // 停留画面中时间（单位：秒）
	SStorageIP                [16]byte           // 存储服务IP地址
	WStoragePort              uint16             // 存储服务端口号
	WDevInfoIvmsChannelEx     uint16             //
	ByFacePicQuality          byte               // 人脸子图图片质量评估等级，0-低等质量，1-中等质量，2-高等质量
	ByUIDLen                  byte               // 上传报警的标识长度
	ByLivenessDetectionStatus byte               // 活体检测状态: 0-保留，1-未知(检测失败)，2-非真人人脸
	ByAddInfo                 byte               // 附加信息标识位：0-无附加信息，1-有附加信息
	PUIDBuffer                *byte              // 标识指针，byUIDLen为1时有效，通过byUIDLen和pUIDBuffer的内容判断是否是同一次抓拍结果
	PAddInfoBuffer            *byte              // 附加信息指针，byAddInfo为1时有效，指向NET_VCA_FACESNAP_ADDINFO结构体，指针指向内存大小为固定大小即NET_VCA_FACESNAP_ADDINFO结构体的大小
	ByTimeDiffFlag            byte               // 时差字段是否有效：0-时差无效，1-时差有效
	CTimeDifferenceH          byte               // 与UTC的时差（小时），-12 ... +14，+表示东区,，byTimeDiffFlag为1时有效
	CTimeDifferenceM          byte               // 与UTC的时差（分钟），-30, 30, 45，+表示东区，byTimeDiffFlag为1时有效
	ByBrokenNetHttp           byte               // 断网续传标志位：0-非重传数据，1-重传数据
	PBuffer1                  *byte              // 人脸子图的图片数据
	PBuffer2                  *byte              // 背景图的图片数据
}

// 人脸特征信息
type NetVcaHumanFeature struct {
	ByAgeGroup       byte    // 年龄段，0xffffffff表示全部（不关注年龄段），详见枚举类型：HUMAN_AGE_GROUP_ENUM
	BySex            byte    // 性别：1- 男，2- 女
	ByEyeGlass       byte    // 是否戴眼镜：1- 不戴，2- 戴
	ByAge            byte    // 年龄
	ByAgeDeviation   byte    // 年龄误差值，如byAge为15、byAgeDeviation为1，表示实际人脸图片年龄的为14~16之间
	ByRes0           byte    // 保留
	ByMask           byte    // 是否戴口罩：0-表示“未知”（算法不支持）；1- 不戴口罩；2-戴口罩；0xff-算法支持，但是没有识别出来
	BySmile          byte    // 是否微笑：0-表示“未知”（算法不支持）；1- 不微笑；2- 微笑；0xff-算法支持，但是没有识别出来
	ByFaceExpression byte    // 表情，详见枚举类型：FACE_EXPRESSION_GROUP_ENUM
	ByRes1           byte    // 保留
	ByRes2           byte    // 保留
	ByHat            byte    // 帽子：0- 不支持；1- 不戴帽子；2- 戴帽子；0xff- 未知,算法支持未检出
	ByRes            [4]byte // 保留
}

// 刷证回调信息
type NetDvrIdCardInfoAlarm struct{
	DwSize uint32
	StruIDCardCfg NetDvrIdCardInfo
	DwMajor uint32
	DwMinor uint32
	StruSwipeTime NetDvrTimeV30
	ByNetUser[16] byte
	StruRemoteHostAddr NetDvrIpAddr
	DwCardReaderNo uint32
	DwDoorNo uint32
	DwPicDataLen uint32
	PPicData *byte
	ByCardType byte
	ByDeviceNo byte
	ByMask byte
	ByRes2 byte
	DwFingerPrintDataLen uint32
	PFingerPrintData *byte
	DwCapturePicDataLen uint32
	PCapturePicData *byte
	DwCertificatePicDataLen uint32
	PCertificatePicData *byte
	ByCardReaderKind byte
	ByRes3 [2]byte
	ByIDCardInfoExtend byte
	PIDCardInfoExtend *byte
	ByRes [172]byte
}

type NetDvrIdCardInfo struct {
	DwSize uint32
	ByName [128] byte
	StruBirth NetDvrDate
	ByAddr [280] byte
	ByIDNum [32] byte
	ByIssuingAuthority [128] byte
	StruStartDate NetDvrDate
	StruEndDate NetDvrDate
	ByTermOfValidity byte
	BySex byte
	ByNation byte
	ByRes [101] byte
}
