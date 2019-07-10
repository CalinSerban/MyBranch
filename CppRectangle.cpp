#include "CppRectangle.h"
#include <QDebug>
#include <QThread>

CppRectangle::CppRectangle()
{
    pSum1 = new Sum();
}

CppRectangle::~CppRectangle()
{
    delete pSum1;
    pSum1 = nullptr;
}

void CppRectangle::calculateStuff1()
{
    QThread* pThread = new QThread();
    pSum1->moveToThread(pThread);
    connect(pThread, SIGNAL(started()), pSum1, SLOT(printNumbers()));
    connect(pSum1, SIGNAL(finishToPrint()), pThread, SLOT(quit()));
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
