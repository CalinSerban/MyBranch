#include "CppRectangle.h"
#include <QDebug>
#include <QThread>

CppRectangle::CppRectangle()
{
    pSum = new Sum();
}

CppRectangle::~CppRectangle()
{
    delete pSum;
    pSum = nullptr;
}

void CppRectangle::calculateStuff1()
{
    QThread* pThread = new QThread();
    pSum->moveToThread(pThread);
    connect(pThread, SIGNAL(started()), pSum, SLOT(printNumbers()));
    connect(pSum, SIGNAL(finishToPrint()), pThread, SLOT(quit()));
    pThread->start();
}

void CppRectangle::calculateStuff2()
{
    for(int i = 0; i <= 100; ++i)
    {
        setProgress(i);
    }
}

void Sum::printNumbers()
{
    for (int i = 0; i < 100000; ++i)
    {
        emit(finishToPrint());
    }
}
