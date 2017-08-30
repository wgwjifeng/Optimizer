﻿// Optimizer.cpp: 定义应用程序的入口点。
//

#include "stdafx.h"
#include "Optimizer.h"

#include "MainFrameWnd.h"

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

	// 设置关联实例
	CPaintManagerUI::SetInstance(hInstance);
	// 设置皮肤路径
	CPaintManagerUI::SetResourceZip(IDR_SKINZIP);
	//CPaintManagerUI::SetCurrentPath(CPaintManagerUI::GetInstancePath());
	//CPaintManagerUI::SetResourcePath(_T("Skin"));
	//CPaintManagerUI::SetResourcePath(CPaintManagerUI::GetInstancePath() + _T("Skin"));
	//CPaintManagerUI::SetResourceZip(_T("Skin.zip"));

	CMainFrameWnd* pFrame = new CMainFrameWnd(_T("MainFrame.xml"));

	pFrame->Create(NULL, _T("BarOptimizer"), UI_WNDSTYLE_DIALOG, 0);
	pFrame->CenterWindow();
	pFrame->ShowWindow();

	CPaintManagerUI::MessageLoop();

	if (nullptr != pFrame)
	{
		delete pFrame;
	}

	::CoUninitialize();

	return 0;
}