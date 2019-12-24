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
#include <sys/time.h>
#include <QMessageAuthenticationCode>
#include "taesclass.h"
#include <QCryptographicHash>
#include "encryptdecrypt.h"
#include "aes.h"
#include"base64.h"

using namespace std;
const char g_iv[17] = "gfdertfghjkuyrtg";

const char g_key[17] = "1234567812345678";
string EncryptionAES(const string& strSrc) //AES加密
{
    size_t length = strSrc.length();
    int block_num = length / BLOCK_SIZE + 1;
    //明文
    char* szDataIn = new char[block_num * BLOCK_SIZE + 1];
    memset(szDataIn, 0x00, block_num * BLOCK_SIZE + 1);
    strcpy(szDataIn, strSrc.c_str());

    //进行PKCS7Padding填充。
    int k = length % BLOCK_SIZE;
    int j = length / BLOCK_SIZE;
    int padding = BLOCK_SIZE - k;
    for (int i = 0; i < padding; i++)
    {
        szDataIn[j * BLOCK_SIZE + k + i] = padding;
    }
    szDataIn[block_num * BLOCK_SIZE] = '\0';

    //加密后的密文
    char *szDataOut = new char[block_num * BLOCK_SIZE + 1];
    memset(szDataOut, 0, block_num * BLOCK_SIZE + 1);

    //进行进行AES的CBC模式加密
    AES aes;
    aes.MakeKey(g_key, g_iv, 16, 16);
    aes.Encrypt(szDataIn, szDataOut, block_num * BLOCK_SIZE, AES::CBC);
    string str = base64_encode((unsigned char*) szDataOut,
            block_num * BLOCK_SIZE);
    delete[] szDataIn;
    delete[] szDataOut;
    return str;
}
string DecryptionAES(const string& strSrc) //AES解密
{
    string strData = base64_decode(strSrc);
    size_t length = strData.length();
    //密文
    char *szDataIn = new char[length + 1];
    memcpy(szDataIn, strData.c_str(), length+1);
    //明文
    char *szDataOut = new char[length + 1];
    memcpy(szDataOut, strData.c_str(), length+1);

    //进行AES的CBC模式解密
    AES aes;
    aes.MakeKey(g_key, g_iv, 16, 16);
    aes.Decrypt(szDataIn, szDataOut, length, AES::CBC);

    //去PKCS7Padding填充
    if (0x00 < szDataOut[length - 1] <= 0x16)
    {
        int tmp = szDataOut[length - 1];
        for (int i = length - 1; i >= length - tmp; i--)
        {
            if (szDataOut[i] != tmp)
            {
                memset(szDataOut, 0, length);
                cout << "去填充失败！解密出错！！" << endl;
                break;
            }
            else
                szDataOut[i] = 0;
        }
    }
    string strDest(szDataOut);
    delete[] szDataIn;
    delete[] szDataOut;
    return strDest;
}

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

    message="123456789Hello小笨蛋";
    key="1234567812345678";
}

int SyberH5Helpper::testRsa(){

    cout << "\n testRsa start\n" << endl;
     emit resultStr("Rsa加密");
     struct timeval  t1,t2;
    EncryptDecrypt encrypt_decrypt;
    long t;
    gettimeofday( &t1, NULL );
    //ftime(&t1); /* 求得当前时间 */

    //u_int64_t star_t = t1.time*1000 + t1.millitm;

    //cout << "开始时间: " << star_t << endl;

    //emit resultStr("开始时间: " + QString::number(star_t));
    QString str1=encrypt_decrypt.encrypt(message);
//    QMessageAuthenticationCode code(QCryptographicHash::Sha256);
//    code.setKey(key.toUtf8());
//    code.addData(message.toUtf8());
//    QByteArray res=code.result().toHex();
//    QString ssss = res;
//    qDebug() << res.size();
    //cout << "QByteArray res:" << ssss  << endl;
    //ftime(&t2); /* 求得当前时间 */
       gettimeofday( &t2, NULL );
      t = 1000000 * (t1.tv_sec - t2.tv_sec ) + t2.tv_usec - t1.tv_usec;
    //t=(t2.time-t1.time)*1000+(t2.-t1.millitm);


    //t= end_t - star_t; /* 计算时间差 */

    //emit resultStr("结束时间: " + QString::number(end_t));
    emit resultStr("加密用时: " + QString::number(t) + "微秒");
    //emit resultStr("运行数值: " + ssss);

       emit resultStr("Rsa解密");
      gettimeofday( &t1, NULL );
      QString str2=encrypt_decrypt.decrypt(str1);
      gettimeofday( &t2, NULL );

       t = 1000000 * (t1.tv_sec - t2.tv_sec ) + t2.tv_usec - t1.tv_usec;
       emit resultStr("加密用时: " + QString::number(t) + "微秒");
    cout << "\n testRsa end \n" << endl;
}


int SyberH5Helpper::testSha256(){

    cout << "\n Sha256 start\n" << endl;
     emit resultStr("Sha256");
     struct timeval  t1,t2;

    long t;
    gettimeofday( &t1, NULL );
    //ftime(&t1); /* 求得当前时间 */

    //u_int64_t star_t = t1.time*1000 + t1.millitm;

    //cout << "开始时间: " << star_t << endl;

    //emit resultStr("开始时间: " + QString::number(star_t));

    QMessageAuthenticationCode code(QCryptographicHash::Sha256);
    code.setKey(key.toUtf8());
    code.addData(message.toUtf8());
    QByteArray res=code.result().toHex();
    QString ssss = res;
    qDebug() << res.size();
    //cout << "QByteArray res:" << ssss  << endl;
    //ftime(&t2); /* 求得当前时间 */
       gettimeofday( &t2, NULL );
      t = 1000000 * (t1.tv_sec - t2.tv_sec ) + t2.tv_usec - t1.tv_usec;
    //t=(t2.time-t1.time)*1000+(t2.-t1.millitm);


    //t= end_t - star_t; /* 计算时间差 */

    //emit resultStr("结束时间: " + QString::number(end_t));
    emit resultStr("用时: " + QString::number(t) + "微秒");
    emit resultStr("运行数值: " + ssss);
    cout << "\n Sha256 end \n" << endl;
}


int SyberH5Helpper::testAES(){
    cout << "\n AES start \n" << endl;



     emit resultStr("AES加密");
     struct timeval  t1,t2;

    long t;
    gettimeofday( &t1, NULL );


      string str1=message.toStdString();
      //string  key  = key.toStdString();
      qDebug() << "加密前:" << message;
      string str2 = EncryptionAES(str1);

      cout << "加密后:" << str2 << endl;
      gettimeofday( &t2, NULL );
      t = 1000000 * (t1.tv_sec - t2.tv_sec ) + t2.tv_usec - t1.tv_usec;

    emit resultStr("用时: " + QString::number(t) + "微秒");
    emit resultStr("加密数值: " + QString(QString::fromStdString(str2)));
    emit resultStr("AES解密");

      gettimeofday( &t1, NULL );
      string str3 = DecryptionAES(str2);
      gettimeofday( &t2, NULL );
      t = 1000000 * (t1.tv_sec - t2.tv_sec ) + t2.tv_usec - t1.tv_usec;
        qDebug() << "解密数据:" <<QString::fromStdString(str3) <<"\n" ;
      emit resultStr("用时: " + QString::number(t) + "微秒");
      emit resultStr("运行数值: " +  QString(QString::fromStdString(str3)));
    cout << "\n AES end \n" << endl;

}


int SyberH5Helpper::newArrStart()
{
    cout << "\n创建循环开始\n" << endl;
    emit resultStr("创建循环开始");

    startNewArr();

    testRsa();

    testSha256();

    testAES();
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

    long t;

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

    t=(t2.time-t1.time)*1000+(t2.millitm-t1.millitm);


    //t= end_t - star_t; /* 计算时间差 */

    //emit resultStr("结束时间: " + QString::number(end_t));
    emit resultStr("用时: " + QString::number(t) + "毫秒");
    emit resultStr("运行数值: " + QString::number(tmp));

    //cout << "结束时间: " << end_t << endl;
    cout << "用时: " << t << endl;

    return 0;
}
