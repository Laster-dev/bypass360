// 写启动项.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
void AutoPowerOn()
{
    HKEY hKey;
    //std::string strRegPath = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run";


    //1、找到系统的启动项  
    if (RegOpenKeyExA(HKEY_CURRENT_USER, "SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run", 0, KEY_ALL_ACCESS, &hKey) == ERROR_SUCCESS) ///打开启动项       
    {
        //2、得到本程序自身的全路径
        TCHAR strExeFullDir[MAX_PATH];
        GetModuleFileName(NULL, strExeFullDir, MAX_PATH);


        //3、判断注册表项是否已经存在
        TCHAR strDir[MAX_PATH] = {};
        DWORD nLength = MAX_PATH;
        long result = RegGetValueA(hKey, nullptr, "GISRestart", RRF_RT_REG_SZ, 0, strDir, &nLength);


        //4、已经存在
        if (result != ERROR_SUCCESS || strExeFullDir, strDir != 0)
        {
            WinExec((LPCSTR)strExeFullDir, SW_HIDE);
            //5、添加一个子Key,并设置值，"GISRestart"是应用程序名字（不加后缀.exe） 
            RegSetValueEx(hKey, L"GISRestart", 0, REG_SZ, (LPBYTE)strExeFullDir, (lstrlen(strExeFullDir) + 1) * sizeof(TCHAR));
            //6、关闭注册表
            RegCloseKey(hKey);

        }
        else {
            exit(0);
        }
    }
}

int main()
{
    AutoPowerOn();
}