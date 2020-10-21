#include "pch.h"
#include "utils.h"

// ��ȡ��ǰexe�ļ�������Ŀ¼
void getCurrentPath(CString& path) {
	HMODULE module = GetModuleHandle(0);
	CString temp;
	GetModuleFileName(module, temp.GetBufferSetLength(MAX_PATH + 1), MAX_PATH);
	// fullpath ��exe�ļ���·��
	CString fullpath(temp);
	int nPos = fullpath.ReverseFind(TEXT('\\'));
	
	if (nPos < 0)
		path = L"";
	else
		path = fullpath.Left(nPos);
}

// �ж��Ƿ���������ļ�
bool hasInitFile(const CString path) {
	if (PathFileExists(path)) {
		return true;
	}
	return false;
}

// ��ֵд�������ļ�
void writeInitFile(const CString path,  const CString room_id, const CString username) {
	// ���ļ���ʱ����մ���
	CStdioFile file(path, CStdioFile::modeWrite|CStdioFile::modeCreate);
	file.WriteString(L"room=");
	file.WriteString(room_id);
	file.WriteString(L"\n");
	file.WriteString(L"name=");
	file.WriteString(username);
	file.Close();
}

// ���ݸ�ֵ��info
void assignInfo(const CString content, const int pos, Info& info) {
	if (content.Left(pos).Compare(L"room")==0) {
		info.room = content.Right(content.GetLength()-pos-1);
	}
	else if (content.Left(pos).Compare(L"name")==0) {
		info.name = content.Right(content.GetLength()-pos-1);
	}
}


// ��ȡ�����ļ��е����ݣ����ҷ���
Info readInitFile(const CString path) {
	CStdioFile file(path, CFile::modeRead);
	CString content;
	// ����info����
	Info info;
	while (file.ReadString(content)) {
		int pos = content.Find(L"=", 0);
		assignInfo(content, pos, info);
	}
	file.Close();
	return info;
}
