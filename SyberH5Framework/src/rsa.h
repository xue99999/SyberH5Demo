/**
 * @Name    : RSA.h
 * @Date    : 2017-04-11-22.25.57
 * @Author  : Silenceneo (silenceneo_xw@163.com)
 * @Link    : http://www.cnblogs.com/Silenceneo-xw/
 * @Version : 2.0
 */

#ifndef __RSA_H__
#define __RSA_H__

#include <ostream>
#include "./biginteger.h"
class RSA {
public:
    RSA() {}
    RSA(const unsigned len) { init(len); }    // 利用len初始化对象
    ~RSA() {}

    void init(const unsigned);// 初始化,产生公私钥对

    BigInteger encryptByPublic(const BigInteger &);    // 公钥加密
    BigInteger decryptByPrivate(const BigInteger &);// 私钥解密

    // 以下主要用于数字签名
    BigInteger encryptByPrivate(const BigInteger &);// 私钥加密
    BigInteger decryptByPublic(const BigInteger &);    // 公钥解密
protected:
    friend std::ostream & operator << (std::ostream &, const RSA &);// 输出相关数据
private:
    BigInteger createOddNum(unsigned);// 生成一个大奇数,参数为其长度
    bool isPrime(const BigInteger &, const unsigned);// 判断是否为素数
    BigInteger createRandomSmaller(const BigInteger &);// 随机创建一个更小的数
    BigInteger createPrime(unsigned, const unsigned);// 生成一个大素数,参数为其长度
    void createExponent(const BigInteger &);// 根据提供的欧拉数生成公钥、私钥指数
public:
    BigInteger n, e;// 公钥
private:
    BigInteger d;// 私钥
    BigInteger p, q;// 大素数p和q
    BigInteger eul;// n的欧拉函数
};

#endif // __RSA_H__
