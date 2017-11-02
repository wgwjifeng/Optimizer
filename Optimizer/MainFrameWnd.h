#pragma once

class CMainFrameWnd : public WindowImplBase
{
public:
	CMainFrameWnd(CDuiString strXMLPath);
	~CMainFrameWnd();

protected:
	virtual CDuiString			GetSkinFolder();
	virtual CDuiString			GetSkinFile();
	virtual LPCTSTR				GetWindowClassName() const;

	virtual void				Notify(TNotifyUI& msg);
	virtual void				InitWindow();

	virtual LRESULT				MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, bool& bHandled);
	virtual LRESULT				OnCreate(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);

private:
	CDuiString	m_strXMLPath;
	SHORT		m_sSelector;

	CButtonUI*	m_pExitButton;
	CButtonUI*	m_pApplyButton;

	COptionUI*	m_pOptHome;
	COptionUI*	m_pOptNetBar;
	COptionUI*	m_pOptFastMode;
};

