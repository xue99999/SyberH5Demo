#ifndef SYBERH5HELPPER_H
#define SYBERH5HELPPER_H

#include <QObject>
#include <QNetworkReply>
#include <QClipboard>
class SyberH5HelpperPrivate;
class SyberH5Helpper : public QObject
{
    Q_OBJECT
public:
    explicit SyberH5Helpper(QObject *parent = 0);

    Q_INVOKABLE int fib2Start();
    Q_INVOKABLE int newArrStart();


    Q_INVOKABLE void setFib2Number(int value);
    Q_INVOKABLE void setRunNumber(int value);
    Q_INVOKABLE void setArrNumber(int value);


signals:
    void resultStr(QString str);

private:

    // fib2循环数量
    int fib2Number;

    // 运行几次
    int runNumber;

    // 数组循环数量 900M
    int arrNumber;

    // 每个数组的大小
    int itemArrSize;
    int result;

    int startNewArr();
    int startFib();
    int fib2(int n);
};

#endif // SYBERH5HELPPER_H
