#ifndef CPPRECTANGLE_H
#define CPPRECTANGLE_H
#include <QObject>

class CppRectangle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged)

    double dfWidth;
    double dfHeight;
public:

    void setWidth(const double& width)
    {
        dfWidth = width;
        emit widthChanged();
    }

    double width() const
    {
        return dfWidth;
    }

    void setHeight(const double& height)
    {
        dfHeight = height;
        emit heightChanged();
    }

    double height() const
    {
        return dfHeight;
    }

    Q_INVOKABLE void showRectangleSize();

signals:
    void widthChanged();
    void heightChanged();

};

#endif // CPPRECTANGLE_H
