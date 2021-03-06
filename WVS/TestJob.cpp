#include "stdafx.h"
#include "TestJob.h"

TestJob::TestJob(HWND hwnd, Item*pItem, Data*pData, TestManager*pTestManager)
{
	m_pItem = pItem;
	m_pData = pData;
	m_pTestManager = pTestManager;
	m_hwnd = hwnd;
}

TestJob::~TestJob()
{

}

void TestJob::Run(void*ptr)
{
	clock_t start = clock();
	m_pTestManager->clearResult();
	m_pTestManager->test(m_pWorkThread->getHttpClient(), m_pItem);
	SendMessage(m_hwnd, WM_TEST_JOB, 0, start);
}
