#include "CppRectangle.h"
#include <QDebug>
#include <QThread>

CppRectangle::CppRectangle()
{
    pSum2 = new Sum();
}

CppRectangle::~CppRectangle()
{
    delete pSum2;
    pSum2 = nullptr;
}

void CppRectangle::calculateStuff1()
{
    QThread* pThread = new QThread();
    pSum2->moveToThread(pThread);
    connect(pThread, SIGNAL(started()), pSum2, SLOT(printNumbers()));
    connect(pSum2, SIGNAL(finishToPrint()), pThread, SLOT(quit()));
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
