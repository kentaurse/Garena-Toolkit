
// Garena ToolkitDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Garena Toolkit.h"
#include "Garena ToolkitDlg.h"
#include "afxdialogex.h"
#include "afxwin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CGarenaToolkitDlg dialog



CGarenaToolkitDlg::CGarenaToolkitDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GARENA_TOOLKIT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGarenaToolkitDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CGarenaToolkitDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HOTKEY()
END_MESSAGE_MAP()


// CGarenaToolkitDlg message handlers

BOOL CGarenaToolkitDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	RegisterHotKey(m_hWnd, 1, 0, 'Q');      // Register 'Q' as the hotkey
	RegisterHotKey(m_hWnd, 2, 0, 'W');      // Register 'W' as the hotkey
	RegisterHotKey(m_hWnd, 3, 0, 'E');      // Register 'E' as the hotkey
	RegisterHotKey(m_hWnd, 4, 0, 'R');      // Register 'R' as the hotkey
	RegisterHotKey(m_hWnd, 5, 0, '3');      // Register '3' as the hotkey
	RegisterHotKey(m_hWnd, 6, 0, '4');      // Register '4' as the hotkey
	RegisterHotKey(m_hWnd, 7, 0, '5');      // Register '5' as the hotkey
	RegisterHotKey(m_hWnd, 8, 0, 'Y');      // Register '5' as the hotkey
	//RegisterHotKey(m_hWnd, 8, 0, VK_RETURN); // Register Enter key as the hotkey

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGarenaToolkitDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGarenaToolkitDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CGarenaToolkitDlg::mouseClick(int x, int y) {
	POINT originalPos;
	GetCursorPos(&originalPos);
	SetCursorPos(x, y);

	INPUT input = { 0 };
	input.type = INPUT_MOUSE;

	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	Sleep(10);
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));

	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	Sleep(10);
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));
	SetCursorPos(originalPos.x, originalPos.y);

	input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
	SendInput(1, &input, sizeof(INPUT));
	Sleep(10);
	input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
	SendInput(1, &input, sizeof(INPUT));
	SetCursorPos(originalPos.x, originalPos.y);
}

void CGarenaToolkitDlg::OnHotKey(UINT nHotKeyId, UINT nKey1, UINT nKey2)
{
	int x = 1387, y = 1035;
	switch (nHotKeyId)
	{
	case 1: // 'Q' key
		mouseClick(x, y);
		break;
	case 2: // 'W' key
		mouseClick(x + 78, y);
		break;
	case 3: // 'E' key
		mouseClick(x + 2 * 78, y);
		break;
	case 4: // 'R' key
		mouseClick(x + 3 * 78, y);
		break;
	case 5: // '3' key
		mouseClick(x + 78, y-100);
		break;
	case 6: // '4' key
		mouseClick(x + 2 * 78, y-100);
		break;
	case 7: // '5' key
		mouseClick(x + 3 * 78, y-100);
		break;
	case 8: // 'Y' key
		INPUT input;
		input.type = INPUT_KEYBOARD;
		input.ki.wVk = VK_F1;
		input.ki.dwFlags = 0; // 0 for key press
		SendInput(1, &input, sizeof(INPUT));
		break;
	default:
		// Handle other hotkeys or unexpected cases
		break;
	}

	CDialogEx::OnHotKey(nHotKeyId, nKey1, nKey2);
}
