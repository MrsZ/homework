#pragma once
#include "afxdialogex.h"

// ��ȡ��ǰ·��
void getCurrentPath(CString& path);

// �жϵ�ǰ·�����Ƿ����
bool hasInitFile(const CString path);

// ������Ϣ�����淿�������û���
struct Info
{
	CString room;
	CString	name;
};

// �������ļ��ж�ȡ��Ϣ
Info readInitFile(const CString path);

// �������Ϣд�������ļ�
void writeInitFile(const CString path, const CString room_id, const CString username);