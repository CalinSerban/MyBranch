#ifndef CPPRECTANGLE_H
#define CPPRECTANGLE_H
#include <QObject>

//new class
class Sum : public QObject
{
    Q_OBJECT

public slots:
    void printNumbers();

signals:
    void finishToPrint();
};

class CppRectangle : public QObject
{
    Q_OBJECT
    Q_PROPERTY(double width READ width WRITE setWidth NOTIFY widthChanged)
    Q_PROPERTY(double height READ height WRITE setHeight NOTIFY heightChanged)
    Q_PROPERTY(int progress READ progress WRITE setProgress NOTIFY progressChanged)

    double dWidth;
    double dHeight;
    int iProgress;
    Sum* pSum2;
public:
    CppRectangle();
    ~CppRectangle();

    void setWidth(const double& width)
    {
        dWidth = width;
        emit widthChanged();
    }

    double width() const
    {
        return dWidth;
    }

    void setHeight(const double& height) //set height
    {
        dHeight = height;
        emit heightChanged();
    }

    double height() const //get height
    {
        return dHeight;
    }

    void setProgress(int progress)
    {
        iProgress = progress;
        emit progressChanged(progress);
    }

    int progress()
    {
        return iProgress;
    }

    Q_INVOKABLE void calculateStuff1();
    Q_INVOKABLE void calculateStuff2();

signals:
    void widthChanged();
    void heightChanged();
    void progressChanged(int progress);
};

#endif // CPPRECTANGLE_H
