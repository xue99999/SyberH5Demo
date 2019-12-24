/**
 * @Name    : EncryptDecrypt.h
 * @Date    : 2017-04-11-22.29.58
 * @Author  : Silenceneo (silenceneo_xw@163.com)
 * @Link    : http://www.cnblogs.com/Silenceneo-xw/
 * @Version : 2.0
 */
#include"QtCore"
#ifndef __ENCRYPTDECRYPT_H__
#define __ENCRYPTDECRYPT_H__

#include <string>
#include <QString>
#include "rsa.h"
#include"biginteger.h"
class EncryptDecrypt {
public:
    EncryptDecrypt() {}
    ~EncryptDecrypt() {}

    void menu();    // 菜单显示
    QString encrypt(QString str);    // 加密
    QString decrypt(QString str);    // 解密
    void print();    // 打印RSA相关信息
    void reset();    // 重置RSA相关信息
protected:
    void load(int);    // 根据给定位数加载RSA对象
    bool islegal(const std::string &);// 判断输入字符串是否合法
private:
    RSA rsa;
};

#endif // __ENCRYPTDECRYPT_H__
