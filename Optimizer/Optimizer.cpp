﻿// Optimizer.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Optimizer.h"

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPTSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	HRESULT hr = ::CoInitialize(NULL);
	if (FAILED(hr))
	{
		return 0;
	}

	::CoUninitialize();

	return 0;
}