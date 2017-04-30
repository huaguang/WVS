#pragma once
#include "CHttpClient.h"
#include "MyThreadPool.h"
#include "Item.h"
#include "Data.h"
#include "TestManager.h"
#include "MonitorJob.h"
#define WM_TEST_JOB	WM_USER+9

class TestJob :public CJob
{
public:
	TestJob(HWND hwnd, Item*pItem, CData*pData, TestManager*pTestManager);
	~TestJob();
	void Run(void*ptr);
private:
	Item* m_pItem;
	CData* m_pData;
	TestManager* m_pTestManager;
	HWND m_hwnd;
};

