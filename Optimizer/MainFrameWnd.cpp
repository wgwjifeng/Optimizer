#include "stdafx.h"
#include "MainFrameWnd.h"


CMainFrameWnd::CMainFrameWnd(CDuiString strXMLPath)
	:m_strXMLPath(strXMLPath)
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

LPCTSTR CMainFrameWnd::GetWindowClassName(void) const
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
		if (msg.pSender->GetName() == _T("footer"))
		{
			MessageBox(NULL, _T("test"), _T("test"), MB_OK);
		}
	}
}

void CMainFrameWnd::InitWindow()
{
}

LRESULT CMainFrameWnd::MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled)
{
	if (uMsg == WM_KEYDOWN)
	{
		switch (wParam)
		{
		// ÆÁ±Î»Ø³µºÍESC
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

