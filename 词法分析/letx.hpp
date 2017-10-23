//
//  letx.hpp
//  词法分析
//
//  Created by 魏晓 on 10/23/17.
//  Copyright © 2017 魏晓. All rights reserved.
//

#ifndef letx_hpp
#define letx_hpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstdio>
typedef struct Trie{
    Trie* next[36];
    bool isEnd;
    int loc;
    Trie(){
        isEnd=false;
        loc=INT32_MAX;
        for(int i=0;i<36;i++) next[i]=nullptr;
    }
}Dic;//字典书存放变量
class Vname { // 存读取到的变量，并且把变量存放在字典书中方便查找
private:
    Dic *root;
public:
    Vname() { root = new Dic(); }
    ~Vname() { free(root); }
    void add(const std::string&str, int loc); // 添加
    void add(std::vector<std::string> strs);
    int find(const std::string &str); // 查找
    void free(Dic *p); // 释放
};
typedef struct ansstruct{
    std::string sign;
    std::string type;
    unsigned int hang;
    unsigned int lie;
    std::string state;
    ansstruct(std::string a,std::string b,unsigned int c, unsigned int d,std::string e){
        sign=a;
        type=b;
        hang=c;
        lie=d;
        state=e;
    }
}Ans;
class Lexical { // 词法分析
private:
    std::vector<std::string> keyword;
    std::map<std::string,std::string>optrs;//jia jian cheng chu fu hao
    Vname indetifiers; // 标识符
    std::map<std::string,int>constants; // 常量
    std::vector<std::string> strings; // 字符串
    std::string chars; // 字符
    unsigned int row,column,cha;
    //bool isFirst; // 输出的第一个结果
    std::string in; // 输入
    std::string cut(int i, int j); // 截取in的字符串[i, j)
    std::vector<Ans> Lans;//存放输入
public:
    Lexical();
    ~Lexical();
    std::string processspace(std::string str);
    bool isKey(const std::string &str); // 是否为关键字
    std::string isOptr(std::string str); // 是否为运算符
    bool isId(const std::string &str); // 是否为标识符
    bool isNum(std::string str); // 是否数值
    bool isString(const std::string &str); // 是否字符串
    bool isChar(const std::string &str); // 是否字符
    void show();//zhanshu
    void analysis();
    void run();
};
#endif /* letx_hpp */
