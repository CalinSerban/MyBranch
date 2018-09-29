#include "CppRectangle.h"
#include <QDebug>

void CppRectangle::showRectangleSize()
{
    qDebug()<<"Width: "<<width()<<" Height: "<<height();
}
