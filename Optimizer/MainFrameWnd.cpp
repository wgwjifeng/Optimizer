#include "stdafx.h"
#include "resource.h"
#include "MainFrameWnd.h"


CMainFrameWnd::CMainFrameWnd(CDuiString strXMLPath)
	: m_strXMLPath(strXMLPath)
	, m_sSelector(-1)
	, m_pExitButton(nullptr)
	, m_pApplyButton(nullptr)
	, m_pOptHome(nullptr)
	, m_pOptNetBar(nullptr)
	, m_pOptFastMode(nullptr)
{
}


CMainFrameWnd::~CMainFrameWnd()
{
}

CDuiString CMainFrameWnd::GetSkinFolder()
{
	return m_PaintManager.GetInstancePath();
}

CDuiString CMainFrameWnd::GetSkinFile()
{
	return m_strXMLPath;
}

LPCTSTR CMainFrameWnd::GetWindowClassName() const
{
	return _T("MainFrameWnd");
}

void CMainFrameWnd::Notify(TNotifyUI & msg)
{
	__super::Notify(msg);

	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		if (msg.pSender->GetName() == _T("btn_close"))
		{
			Close();
			PostQuitMessage(0);
		}
		if (msg.pSender->GetName() == _T("btn_apply"))
		{
			CDuiString strMessage;
			strMessage.Format(_T("当前选择 %d"), m_sSelector);
			MessageBox(NULL, strMessage, NULL, MB_OK);
			//m_pApplyButton->SetBkColor(0xFF999999);
			//m_pApplyButton->SetText(_T("正在设置..."));
		}
		if (msg.pSender->GetName() == _T("opt_home"))
		{
			m_sSelector = 0;
		}
		if (msg.pSender->GetName() == _T("opt_netbar"))
		{
			m_sSelector = 1;
		}
		if (msg.pSender->GetName() == _T("opt_fastmode"))
		{
			m_sSelector = 2;
		}
	}
}

void CMainFrameWnd::InitWindow()
{
	m_pApplyButton = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_apply")));
	m_pExitButton = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_exit")));

	// options
	// m_pOptHome = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_home")));
	// m_pOptNetBar = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_netbar")));
	// m_pOptFastMode = static_cast<COptionUI*>(m_PaintManager.FindControl(_T("opt_fastmode")));
}

LRESULT CMainFrameWnd::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	if (uMsg == WM_KEYDOWN)
	{
		switch (wParam)
		{
		// 屏蔽回车和ESC
		case VK_RETURN:
		case VK_ESCAPE:
			return FALSE;
		default:
			break;
		}
	}

	return FALSE;
}

LRESULT CMainFrameWnd::OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
	__super::OnCreate(uMsg, wParam, lParam, bHandled);

	return 0;
}

