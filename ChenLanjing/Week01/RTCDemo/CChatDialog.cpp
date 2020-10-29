// CChatDialog.cpp : implementation file
// �����

#include "pch.h"
#include "RTCDemo.h"
#include "CChatDialog.h"
#include "afxdialogex.h"


// CChatDialog dialog
// ��̬����  IMPLEMENT_DYNCREATE(class_name, base_class_name )
// class_name �����ࣨ�ӣ���
// base_class_name ���ࣨ������
IMPLEMENT_DYNAMIC(CChatDialog, CDialogEx)

// ���캯��
// �ø���Ĺ��캯���������Լ��Ĵ���
CChatDialog::CChatDialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CHATDIALOG, pParent)
{

}

// ��������
CChatDialog::~CChatDialog()
{
}

// ������������ؼ���������
void CChatDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	// �ѱ����Ϳؼ������������
	// pDX��ָ��CDataExchange�����ָ��
	// ���ֽṹΪָ�������ṩ�˽������ݽ����Ļ�����Ҳ�����ṹ��ָ��
	// IDC_EMSG�ǿؼ�ID
	// m_strMessage��ΪIDC_EMSG�ؼ�������һ��CString�ͱ���
	DDX_Control(pDX, IDC_CHAT, m_chat);
	DDX_Control(pDX, IDC_INPUT, m_input);
}

// ��ʼ��
void CChatDialog::Init(const CString& name, const CString& room)
{
	m_name = name;
	m_room = room;
}

// �궨��
// �����Ϣ��Ӧ����,Ϊÿ����Ϣ����������һ�����
BEGIN_MESSAGE_MAP(CChatDialog, CDialogEx)
	ON_BN_CLICKED(IDC_SEND, &CChatDialog::OnBnClickedSend)
END_MESSAGE_MAP()


// CChatDialog message handlers

// ��ʼ���Ի���
BOOL CChatDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  Add extra initialization here
	CString winTitle;
	winTitle.Format(L"RoomID - %s", m_room);
	// �ı�ָ�����ڵı��������ı�����
	// ���ָ��������һ���ؼ�����ı�ؼ����ı����ݡ�
	// SetWindowText�������ı�����Ӧ�ó����еĿؼ����ı�����
	SetWindowText(winTitle);

	CString helloText;
	helloText.Format(L"Hello, %s\r\n", m_name);
	m_chat.SetWindowText(helloText);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

// �Ի����ݱ༭
void CChatDialog::OnBnClickedSend()
{
	CString strText;
	m_chat.GetWindowText(strText);
	strText += "\r\n";

	CString strInput;
	m_input.GetWindowText(strInput);
	strText += strInput;

	m_input.SetWindowText(L"");
	m_chat.SetWindowText(strText);
}

