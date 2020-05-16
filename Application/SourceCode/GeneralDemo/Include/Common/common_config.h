#ifndef GENERAL_DEMO_COMMON_CONFIG_H
#define GENERAL_DEMO_COMMON_CONFIG_H

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#define CPS_VERSION "V1.0.0"
#define APP_NAME tr("Demo 客户端")
#define ABOUTUS tr("关于我们")
#define ABOUTINFO tr("<h2>Demo 客户端 V1.0.0</h2><p>Copyright IMSBU</p><p>This client need an about description.</p>"
#define STATUS_NAME tr("状态：")
#define XMPP_STATUS_ONLINE tr("在线")
#define XMPP_STATUS_AWAY tr("暂时离开")
#define XMPP_STATUS_DND tr("忙碌")
#define XMPP_STATUS_INVISIBLE tr("不在线")
#define XMPP_LOGIN tr("登录")

#define FILE_MENU tr("&文件")
#define FILE_OPEN_ACTION tr("&打开")
#define FILE_SAVE_ACTION tr("&保存")
#define FILE_SAVEAS_ACTION tr("&另存为")
#define FILE_RECENT_ACTION tr("&最近使用")
#define FILE_SAVEIMAGE_ACTION tr("&保存截图")
#define FILE_QUIT_ACTION tr("&退出")

#define PANELS_MENU tr("&视图")
#define PANELS_FULLSCREEN_ACTION tr("&全屏")

#define PLUGIN_MENU tr("&插件窗口")

#define SELECT_MENU tr("&选择")
#define THEME_MENU tr("&主题")
#define THEME_WINDOWS_ACTION tr("&windows")
#define THEME_DARCULA_ACTION tr("&darcula")
#define LANGUAGE_MENU tr("&语言")
#define LANGUAGE_CHINESE_ACTION tr("&中文")
#define LANGUAGE_ENGLISH_ACTION tr("&英语")

#define HELP_MENU tr("&帮助")
#define HELP_OPENWIKI_ACTION tr("&打开wiki")
#define HELP_ABOUTUS_ACTION tr("&关于我们")

#define PANEL_SETTING tr("设置")
#define PANEL_FUNCTION tr("功能窗口")

#define TOOL_OPENVISUALIZATION tr("打开可视化")
#define TOOL_CLOSEVISUALIZATION tr("关闭可视化")
#define TOOL_SETTING tr("设置")
#define TOOL_FUNCTION tr("功能")
#define TOOL_OPENVIDEO tr("打开视频")
#define TOOL_CLOSEVIDEO tr("关闭视频")
 
#define TOOLWIDGET_IMS tr("即时消息")
#define TOOLWIDGET_CV tr("计算机视觉")
#define TOOLWIDGET_3D tr("3D")
#define TOOLWIDGET_WEB tr("Web Engine")
#define TOOLWIDGET_OTHER tr("其他")

#define SCREENSHOT_SAVEIMAGE tr("保存图片")
#define SCREENSHOT_ERROR tr("错误")
#define SCREENSHOT_SAVEERROR tr("将图像写入文件失败")
#define SCREENSHOT_SUPPORTEDFORMATS tr("支持的图像格式有：")
#define SCREENSHOT_ALLWINDOW tr("保存整个demo窗口")
#define SCREENSHOT_ORIGINAL_RESOLUTION tr("图像将以原始分辨率保存。")

#define DOCK_WIDGET_A tr("插件窗口A")
#define DOCK_WIDGET_B tr("插件窗口B")

#define SAFE_DELETE(p) {if (p != 0) {delete p; p = NULL;}}

#endif // GENERAL_DEMO_COMMON_CONFIG_H
