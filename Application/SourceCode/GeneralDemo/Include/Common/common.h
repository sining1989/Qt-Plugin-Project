#ifndef GENERAL_DEMO_COMMON_H
#define GENERAL_DEMO_COMMON_H

#include <QString>
#include <QDir>
#include <QCoreApplication>

#pragma once
#pragma warning ( disable : 4099 )

#define DB_PATH "/db/demo.db"
namespace general_demo
{
	#define DELETEPTR(ptr) if(NULL != ptr){ \
		delete ptr; \
		ptr = NULL; \
		}


	typedef enum {
		UI_EN,
		UI_ZH
	}LANGUAGE;

	extern bool isDirExist(QString fullPath);
	extern QString GetModulePath();
	extern bool isFileOrFolder(const std::string fileName);
	extern int g_iThemeId; // 0: Windows theme, 1: Darcula theme

} // end namespace general_demo

#endif // GENERAL_DEMO_COMMON_H
