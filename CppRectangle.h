#ifndef CPPRECTANGLE_H
#define CPPRECTANGLE_H
#include <QObject>

class CppRectangle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged)

<<<<<<< Updated upstream
    double dWidth;
    double dHeight;

=======
    double dfWidth;
    double dHeight;
>>>>>>> Stashed changes
public:

    void setWidth(const double& width)
    {
        dWidth = width;
        emit widthChanged();
    }

    double width() const
    {
        return dWidth;
    }

    void setHeight(const double& dfHeight)
    {
<<<<<<< Updated upstream
        dHeight = dfHeight;
=======
        dHeight = height;
>>>>>>> Stashed changes
        emit heightChanged();
    }

    double height() const
    {
        return dHeight;
    }

    Q_INVOKABLE void showRectangleSize();

signals:
    void widthChanged();
    void heightChanged();
};

#endif // CPPRECTANGLE_H
