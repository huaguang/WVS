#pragma once
#include "Data.h"
#include "MyThreadPool.h"
#include "SQLiTest.h"
#include "Item.h"
#include "TestJob.h"
#include "TestManager.h"

// CConfigDlg 对话框

class CConfigDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CConfigDlg)

public:
	CConfigDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CConfigDlg();

	void setGlobalData(CData *pData, CMyThreadPool *pThreadPool, TestManager* pTestManager);



// 对话框数据
	enum { IDD = IDD_CONFIG_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();		//加载测试用例
	afx_msg void OnBnClickedButton1();	//存储测试用例
	afx_msg void OnBnClickedButton3();	//load configuration  其中包括设置测试类型，难以从界面上扩展，可以使用配置文件
	afx_msg void OnBnClickedButton2();	//开始单条测试
	afx_msg LRESULT OnTestJob(WPARAM wParam, LPARAM lParam);	//单条测试完成的通知消息处理函数
	afx_msg void OnBnClickedButton5();	//为单条测试添加参数
	afx_msg void OnBnClickedButton4();  //为单条测试清空参数

	CData *m_pData;
	CMyThreadPool *m_pThreadPool;
	TestManager* m_pTestManager;
	
	
	UINT m_crawlerLayer;// 爬行深度
	UINT m_numOfThread;
	BOOL m_isUseProxy;
	CString m_proxy;
	BOOL m_useErrorBased = TRUE;
	BOOL m_useBoolBased = TRUE;
	BOOL m_useTimeBased = TRUE;

	
	//一下参数均为测试单条url准备
	CString m_testUrl;// 测试单个网址的url
	CString m_testArgs; // 测试单个网址的参数
	CString m_testCookie;// 测试单个网址的cookie
	Item *pTestItem;
	vector<Field>*pTestArgs;
	CString m_testArgName;
	CString m_testArgValue;	
	BOOL m_methodRadio; 	
	BOOL m_testSQLi;// 该参数是否进行XSS测试
	BOOL m_testXSS;// 该参数是否进行xss测试
};
