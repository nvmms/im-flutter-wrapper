//
//  RCIMIWMessagePushOptions.h
//  RongIMWrapper
//
//  Created by RongCloud on 2/15/22.
//

#import <Foundation/Foundation.h>
#import <RongIMWrapper/RCIMIWDefines.h>

@class RCIMIWIOSPushOptions;
@class RCIMIWAndroidPushOptions;
@class RCIMIWHarmonyPushOptions;

NS_ASSUME_NONNULL_BEGIN

#pragma mark - RCIMIWMessagePushOptions

@interface RCIMIWMessagePushOptions : NSObject

/*!
 是否关闭通知
 YES: 关闭通知（不发送通知）
 NO: 不关闭通知（发送通知）
 默认 NO
 */
@property (nonatomic, assign) BOOL disableNotification;

/*!
 是否屏蔽通知标题
 YES:  不显示通知标题
 NO: 显示通知标题
 
 @discussion 默认情况下融云单聊消息通知标题为用户名、群聊消息为群名称，设置后不会再显示通知标题。
 @discussion 此属性只针目标用户为 iOS 平台时有效，Android 第三方推送平台的通知标题为必填项，所以暂不支持。
 */
@property (nonatomic, assign) BOOL disablePushTitle;

/*!
 推送标题
 如果没有设置，会使用下面的默认标题显示规则
 默认标题显示规则：
    内置消息：单聊通知标题显示为发送者名称，群聊通知标题显示为群名称。
    自定义消息：默认不显示标题。
 */
@property (nonatomic, copy) NSString *pushTitle;

/*!
 推送内容
 优先使用 RCIMIWMessagePushOptions 的 pushContent。如果一个接口 RCIMIWMessage 和 pushContent 同时存在，且 RCIMIWMessagePushOptions.pushContent 为有效值，会优先使用  RCIMIWMessagePushOptions.pushContent 当做最终的 pushContent，例如  sendMessage 、 sendMediaMessage、recallMessage 接口。
 */
@property (nonatomic, copy) NSString *pushContent;

/*!
 远程推送附加信息
 优先使用 MessagePushConfig 的 pushData。如果一个接口 RCMessage 和 pushData 同时存在，且 MessagePushConfig.pushData 为有效值，会优先使用 MessagePushConfig.pushData 当做最终的 pushData，例如  sendMessage 、 sendMediaMessage 接口。
 */
@property (nonatomic, copy) NSString *pushData;

/*!
 是否强制显示通知详情
 当目标用户通过 RCIMIWEngine 中的 changePushContentShowStatus 设置推送不显示消息详情时，可通过此参数，强制设置该条消息显示推送详情。
 */
@property (nonatomic, assign) BOOL forceShowDetailContent;

/*!
 推送模板 ID，设置后根据目标用户通过 SDK 的 changePushLanguage 设置的语言环境，匹配模板中设置的语言内容进行推送，未匹配成功时使用默认内容进行推送，模板内容在“开发者后台-自定义推送文案”中进行设置。
 注： pushTitle 和 pushContent 优先级高于模板 ID（templateId）中对应的标题和推送内容。
 */
@property (nonatomic, copy) NSString *templateId;

@property (nonatomic, assign) BOOL voIPPush;

/*!
 iOS 平台相关配置
 */
@property (nonatomic, strong) RCIMIWIOSPushOptions *iOSPushOptions;

/*!
 Android 平台相关配置
 */
@property (nonatomic, strong) RCIMIWAndroidPushOptions *androidPushOptions;

@property (nonatomic, strong) RCIMIWHarmonyPushOptions *harmonyPushOptions;

@end

#pragma mark - RCIMIWIOSPushOptions

@interface RCIMIWIOSPushOptions : NSObject

/*!
 iOS 平台通知栏分组 ID
 相同的 thread-id 推送分为一组
 iOS10 开始支持
 */
@property (nonatomic, copy) NSString *threadId;

/*!
 iOS 标识推送的类型
 如果不设置后台默认取消息类型字符串，如 RC:TxtMsg
 */
@property (nonatomic, copy) NSString *category;

/*!
 iOS 平台通知覆盖 ID
 apnsCollapseId 相同时，新收到的通知会覆盖老的通知，最大 64 字节
 iOS10 开始支持
 */
@property (nonatomic, copy) NSString *apnsCollapseId;

/*!
 iOS 富文本推送内容
 */
@property (nonatomic, copy) NSString *richMediaUri;

/// iOS 推送级别. 默认值 "active"
/// "passive" 被动通知：即并不需要及时关注的通知，类似餐馆推荐通知
/// "active"   主动通知（默认的）：默认的通知，即人们可能想知道的，类似最喜欢的体育比赛的最新比分
/// "time-sensitive" 时效性通知：需要人们立刻注意的通知，类似账户安全问题或快递动态
/// "critical" 重要通知：关于个人健康或直接影响到设备拥有者的公共安全事件且需要立刻关注的，这类通知很少，一般是来自公共政府机构或健康 App。
@property (nonatomic, copy) NSString *interruptionLevel;

@end

#pragma mark - RCIMIWAndroidPushOptions

@interface RCIMIWAndroidPushOptions : NSObject

/*!
 Android 平台 Push 唯一标识
 目前支持小米、华为推送平台，默认开发者不需要进行设置，当消息产生推送时，消息的 messageUId 作为 notificationId 使用。
 */
@property (nonatomic, copy) NSString *notificationId;

/*!
 小米的渠道 ID
 该条消息针对小米使用的推送渠道，如开发者集成了小米推送，需要指定 channelId 时，可向 Android 端研发人员获取，channelId 由开发者自行创建。
 */
@property (nonatomic, copy) NSString *channelIdMi;

/*!
 华为的渠道 ID
 该条消息针对华为使用的推送渠道，如开发者集成了华为推送，需要指定 channelId 时，可向 Android 端研发人员获取，channelId 由开发者自行创建。
 */
@property (nonatomic, copy) NSString *channelIdHW;

/*!
 华为推送消息分类
 
 社交通讯:即时通讯[IM],音频、视频通话[VOIP]
 服务提醒:订阅[SUBSCRIPTION],出行[TRAVEL],健康[HEALTH],工作事项提醒[WORK],帐号动态[ACCOUNT],订单&物流[EXPRESS],财务[FINANCE],系统提示[SYSTEM_REMINDER],邮件[MAIL]
 资讯营销类:内容资讯/新闻/财经动态/生活资讯/社交动态/调研/其他[MARKETING]
 营销活动:产品促销/功能推荐/运营活动/MARKETING
 更多信息请参考华为消息分类标准文档: https://developer.huawei.com/consumer/cn/doc/development/HMSCore-Guides/message-classification-0000001149358835
 
 @discussion 默认值为 null，如果为 null，则以服务配置为准
 
 @since 5.4.0
 */
@property (nonatomic, copy) NSString *categoryHW;

/*!
 OPPO 的渠道 ID
 该条消息针对 OPPO 使用的推送渠道，如开发者集成了 OPPO 推送，需要指定 channelId 时，可向 Android 端研发人员获取，channelId 由开发者自行创建。
 */
@property (nonatomic, copy) NSString *channelIdOPPO;

/*!
 VIVO 推送通道类型
 开发者集成了 VIVO 推送，需要指定推送类型时，可进行设置。
 目前可选值 "0"(运营消息) 和  "1"(系统消息)
 */
@property (nonatomic, assign) RCIMIWVIVOPushType pushTypeVIVO;

/*!
 FCM 通知类型推送时所使用的分组 id
 */
@property (nonatomic, copy) NSString *collapseKeyFCM;

/*!
 FCM 通知类型的推送所使用的通知图片 url
 */
@property (nonatomic, copy) NSString *imageUrlFCM;

/*!
 华为推送消息级别
 */
@property (nonatomic, assign) RCIMIWImportanceHW importanceHW;

/*!
 华为通知栏消息右侧大图标 URL
 如果不设置，则不展示通知栏右侧图标。URL使用的协议必须是HTTPS协议，取值样例：https://example.com/image.png。
 图标文件须小于 512KB，图标建议规格大小：40dp x 40dp，弧角大小为 8dp，超出建议规格大小的图标会存在图片压缩或显示不全的情况。
 */
@property (nonatomic, copy) NSString *imageUrlHW;

/*!
 小米 Large icon 链接
 Large icon 可以出现在大图版和多字版消息中，显示在右边。国内版仅 MIUI12 以上版本支持，以下版本均不支持；国际版支持。图片要求：大小 120 * 120px，格式为 png 或者 jpg 格式。
 */
//@property (nonatomic, copy) NSString *imageUrlMi;

/*!
 FCM 通知的频道 ID
 该应用程序必须使用此频道 ID 创建一个频道，然后才能收到带有该频道 ID 的任何通知。如果您未在请求中发送此频道 ID，或者如果应用尚未创建提供的频道 ID，则 FCM 使用应用清单中指定的频道 ID。
 */
@property (nonatomic, copy) NSString *channelIdFCM;


/*!
 Vivo 推送消息分类
 
 系统消息分类
 即时消息[IM],账号与资产[ACCOUNT],日程待办[TODO],设备信息[DEVICE_REMINDER],订单与物流[ORDER],订阅提醒[SUBSCRIPTION]
 运营消息分类
 新闻[NEWS],内容推荐[CONTENT],运营活动[MARKETING],社交动态[SOCIAL]
 更多信息请参考 Vivo 消息分类标准文档: https://dev.vivo.com.cn/documentCenter/doc/359
 
 @discussion 默认值为 null，如果为 null，则以服务配置为准
 
 @since 5.4.3
 */
@property (nonatomic, copy) NSString *categoryVivo;

/*!
 荣耀推送消息级别
 */
@property (nonatomic, assign) RCIMIWImportanceHonor importanceHonor;

@property (nonatomic, copy) NSString *imageUrlHonor;

@end

@interface RCIMIWHarmonyPushOptions : NSObject

/// HarmonyOS通知栏消息右侧大图标 URL
///
///通知栏右侧图片，格式支持 png、jpg、jpeg、heif、gif、bmp，图片长*宽<25000像素，图片不满足要求的情况下，终端不能显示通知消息。
@property (nonatomic, copy, nullable) NSString *imageUrl;

/// HarmonyOS推送消息分类：
/// - 社交通讯：消息自分类标识，默认为空。category 取值必须为大写字母
/// 参考： https://developer.huawei.com/consumer/cn/doc/HMSCore-Guides/message-classification-0000001149358835

/// 默认值为 null，如果为 null，则以服务配置为准
///
@property (nonatomic, copy, nullable) NSString *category;

@end

NS_ASSUME_NONNULL_END
