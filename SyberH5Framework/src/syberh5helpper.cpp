#include "syberh5helpper.h"
#include <cenvironment.h>
#include <QApplication>
#include <QDir>
#include <QDebug>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <csystempackagemanager.h>
#include <time.h>
#include <iostream>
#include<sys/timeb.h>

using namespace std;

SyberH5Helpper::SyberH5Helpper(QObject *parent) : QObject(parent)
{
    // fib2循环数量
    fib2Number = 40;

    // 运行几次
    runNumber = 5;

    // 数组循环数量 900M
    arrNumber = 10000000; // 900;

    // 每个数组的大小
    itemArrSize = 1024;// 1024*1024;
}

int SyberH5Helpper::newArrStart()
{
    cout << "\n创建数组\n" << endl;
    emit resultStr("创建数组");

    startNewArr();

    return 0;
}

int SyberH5Helpper::fib2Start()
{
    cout << "\n斐波那契数列\n" << endl;
    emit resultStr("斐波那契数列");
    for (int i = 1; i <= runNumber; i++) {
        emit resultStr("第" + QString::number(i)  + "次");

        cout << "第" << i << "次: " << endl;
        startFib();
    }
    return 0;
}

void SyberH5Helpper::setFib2Number(int value)
{
    qDebug() << "----- fib2循环数量 :  " << value;
    // fib2循环数量
    fib2Number = value;
}

void SyberH5Helpper::setRunNumber(int value)
{
    qDebug() << "----- 运行几次 :  " << value;
    // 运行几次
    runNumber = value;
}

void SyberH5Helpper::setArrNumber(int value)
{
    qDebug() << "----- 数组循环数量 :  " << value;

    // 数组循环数量 900M
    arrNumber = value;
}

int SyberH5Helpper::fib2(int n)
{
    if(n == 0)
      return 0;
    if(n == 1)
      return 1;
    return fib2(n-1)+fib2(n-2);
}


int SyberH5Helpper::startFib() {

    time_t t1;
    time(&t1);
    cout << "开始时间: " << t1 << endl;
    emit resultStr("开始时间: " + QString::number(t1));

    for (int i = 0; i <= fib2Number; i++) {
        result = fib2(i);
    }

    time_t t2;
    time(&t2);
    emit resultStr("结束时间: " + QString::number(t2));
    emit resultStr("用时: " + QString::number(t2-t1)  + "秒" );

    cout << "结束时间: " << t2 << endl;
    cout << "用时: " << t2-t1 << endl;
    return 0;
}

int SyberH5Helpper::startNewArr() {

    struct timeb t1,t2;

    u_int64_t t;

    ftime(&t1); /* 求得当前时间 */

    u_int64_t star_t = t1.time*1000 + t1.millitm;

    cout << "开始时间: " << star_t << endl;

    emit resultStr("开始时间: " + QString::number(star_t));

    u_int64_t tmp = 0;

    for (u_int64_t i = 1; i <= arrNumber; i++) {
        tmp = tmp + i;
    }

    cout << "tmp: " << tmp << endl;


    ftime(&t2); /* 求得当前时间 */

    u_int64_t end_t = t2.time*1000 + t2.millitm;


    t= end_t - star_t; /* 计算时间差 */

    emit resultStr("结束时间: " + QString::number(end_t));
    emit resultStr("用时: " + QString::number(t) + "毫秒");
    emit resultStr("运行数值: " + QString::number(tmp));

    cout << "结束时间: " << end_t << endl;
    cout << "用时: " << t << endl;

    return 0;
}
