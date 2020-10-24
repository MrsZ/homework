
// RTCDemoDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "RTCDemo.h"
#include "RTCDemoDlg.h"
#include "afxdialogex.h"
#include "CChatDialog.h"
#include "utils.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CRTCDemoDlg dialog



CRTCDemoDlg::CRTCDemoDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RTCDEMO_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRTCDemoDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_NAME, m_room);
	DDX_Control(pDX, IDC_USER, m_name);
}

BEGIN_MESSAGE_MAP(CRTCDemoDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, &CRTCDemoDlg::OnBnClickedLogin)
END_MESSAGE_MAP()


// CRTCDemoDlg message handlers

BOOL CRTCDemoDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon


	// ���浱ǰ��·��
	CString path;
	getCurrentPath(path);
	// ����ȫ�������ļ�
	// ��Ϊ����init dialogʱ����õģ�������֮�������ط�����ֱ�ӵ���
	configPath = path + L"\\webrtc.ini";
	BOOL flag = hasInitFile(configPath);

	if (flag) {
		Info info = readInitFile(configPath);
		// ����ֱ�Ӿ͸�ֵ�ˣ����û�ж�ȡ����Ӧ����Ϣ��info���ص��ֶζ��ǿ��ַ���
		// ���ʹ��SetWindowTextW��������Ҫ�����ж�info�ж�Ӧ�ֶ��Ƿ�Ϊ���ٽ������õ�����
		// ��ô��ý����жϣ������Ӧ�ֶ�Ϊ�վͲ�ִ��SetWindowTextW
		// ����û�н��и����ε��о���
		this->m_room.SetWindowTextW(info.room);
		this->m_name.SetWindowTextW(info.name);
	}

	/*
	 * ����GetPrivateProfileString�ӿ�ʵ��
	 */
	// ��ini�ļ��ж�ȡ����
	//CString room_name, user_name;
	//CString path;
	//getCurrentPath(path);
	//path.Append(L"\\webrtc.ini");
	//::GetPrivateProfileString(L"WebRTC", L"room", L"", room_name.GetBuffer(MAX_PATH), MAX_PATH, path);
	//::GetPrivateProfileString(L"WebRTC", L"name",  L"", user_name.GetBuffer(MAX_PATH), MAX_PATH, path);
	//room_name.ReleaseBuffer();
	//user_name.ReleaseBuffer();
	//this->m_room.SetWindowTextW(room_name);
	//this->m_name.SetWindowTextW(user_name);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CRTCDemoDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CRTCDemoDlg::OnPaint()
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
HCURSOR CRTCDemoDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CRTCDemoDlg::OnBnClickedLogin()
{
	CString user_name, room_name;
	m_name.GetWindowText(user_name);
	m_room.GetWindowText(room_name);

	// �����жϣ�user_name ��room_name ������Ϊ��
	if (room_name.GetLength() == 0) {
		AfxMessageBox(L"����������Ϊ��");
		return;
	}
	if (user_name.GetLength() == 0) {
		AfxMessageBox(L"�û�������Ϊ��");
		return;
	}
	

	// ���û��������Ϣ�����������ļ���
	// ���Ǳ����room_name�Լ�user_nameһֱ�������µ�
	writeInitFile(configPath,room_name, user_name);

	/*
	  ����ķ�ʽ�ǲ���WINAPIʵ��
	*/
	//CString path;
	//getCurrentPath(path);
	//path.Append(L"\\webrtc.ini");
	//::WritePrivateProfileString(L"WebRTC", L"room", room_name, path);
	//::WritePrivateProfileString(L"WebRTC", L"name", user_name ,path);

	CChatDialog chat_dlg;
	chat_dlg.Init(user_name, room_name);
	chat_dlg.DoModal();
}
