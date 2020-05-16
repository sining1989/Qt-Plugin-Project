#include "common.h"

namespace general_demo
{
	int general_demo::g_iThemeId = 0;
	bool isDirExist(QString fullPath)
	{
		QDir dir(fullPath);
		if (dir.exists())
		{
			return true;
		}
		else
		{
			bool ok = dir.mkdir(fullPath);
			return ok;
		}
	}
	
	QString	GetModulePath()
	{
		QString strPath = QCoreApplication::applicationFilePath();
		return  strPath.left(strPath.lastIndexOf(QString("/")) + 1);
	}

	bool isFileOrFolder(const std::string fileName)
	{
		const char* path = fileName.c_str();
		struct _stat buf = { 0 };
		_stat(path, &buf);
		return buf.st_mode & _S_IFDIR;
	}
	

} // end namespace general_demo

