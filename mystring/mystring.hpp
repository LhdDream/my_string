#ifndef MYSTRING_HPP
#define MYSTRING_HPP
/* code */
#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
class String
{
  friend ostream &operator<<(ostream &out, String &obj);
  friend istream &operator>>(istream &in,String &obj);
  public:
    String();
    String(const String &obj);
    String(const char *test);
    ~String();

  public:
    String &operator=(const String &p_obj);
    String &operator=(const char *p_test);
    char &operator[](int size); //返回一个引用,char类型
    String &operator+=(const String &obj);
    String &operator+=(const char *test);
    bool operator==(const char * test);
    bool operator!=(const String &obj);
    bool operator!=(const char * test);
    bool operator>(const char * test);
    bool operator>(const String & obj);
    bool operator<(const char * test);
    bool operator<(const String & obj);
 public:
    int size();
    int find(const char test,int pos );
    bool empty();
    int length();
  private:
    char *temp;
    int m_temp;
};

String::String()
{
    // cout << "fffffffffffff" << endl;
    m_temp = 0;
    temp = new char [m_temp+1];//一个字节
    strcpy(temp,"");
}
String::String(const char * test)
{
    // 考虑空串情况
    // cout << "ffffffffff" << endl;
    if(test == NULL)
    {
        m_temp = 0;
        temp = new char[m_temp + 1]; //一个字节
        strcpy(temp,"");
    }
    else
    {
        m_temp = strlen(test);
        temp = new char [m_temp + 1];
        strcpy(temp,test);
    }
}
String::String(const String &obj)
{
    if (obj.temp == NULL)
    {
        m_temp = 0;
        temp = new char[m_temp + 1]; //一个字节
        strcpy(temp, "");
    }
    if(temp != NULL)
    {
        delete []temp;
    }
    m_temp = obj.m_temp;
    temp = new char [m_temp + 1];
    strcpy(temp,obj.temp);
}
String::~String()
{
    // cout << "fffffffffffff" << endl;
    if(temp != NULL)
    {
        delete []temp;
        temp = NULL;
    }
    m_temp = 0;
}
String& String::operator=(const String &p_obj)
{
    if(temp != NULL)
    {
        delete [] temp;
    }
    if(p_obj.temp == NULL)
    {
        m_temp = 0;
        temp = new char[m_temp + 1]; //一个字节
        strcpy(temp, "");
    }
    else
    {
        m_temp = p_obj.m_temp;
        temp = new char[m_temp + 1];
        strcpy(temp, p_obj.temp);
    }
}
String& String::operator=(const char * p_test)
{
    if(p_test == NULL)
    {
        m_temp = 0;
        temp = new char[m_temp + 1]; //一个字节
        strcpy(temp, "");
    }
    else
    {
        m_temp = strlen (p_test);
        temp = new char[m_temp + 1];
        strcpy(temp, p_test);
    }
}
char& String::operator[](int size)
{
    if(size < 0 || size > m_temp)
    {
        cout << " 数组越界" << endl;
    }
    return temp[size];
}
String & String::operator+=(const char *test)
{
    char * kiosk;
    if(temp != NULL)
    {
        kiosk = new char[m_temp + 1];
        strcpy(kiosk, temp);
        delete [] temp ;
    }
    if(test != NULL)
    {
        m_temp += strlen(test);
        temp = new char [m_temp + 1];
        strcpy(temp,kiosk);
        strcat(temp,test);
    }
}
String & String::operator+=(const String &obj)
{
    char *kiosk;
    if (temp != NULL)
    {
        kiosk = new char[m_temp + 1];
        strcpy(kiosk, temp);
        delete[] temp;
    }
    if(obj.temp != NULL)
    {
        m_temp += obj.m_temp;
        temp = new char[m_temp + 1];
        strcpy(temp, kiosk);
        strcat(temp,obj.temp);
    }
}
int String::size()
{
    return m_temp;
}
//重载左移操作符号
//重载在标准输出之中
ostream &operator<<(ostream &out, String &obj)
{
    out <<obj.temp;
    return out;
}
istream &operator>>(istream &in,String &obj)
{
    in >> obj.temp;
    return in;
}
bool String::operator==(const char *test)
{
    int size = strlen(test);
    if(size != m_temp)
    {
        return false;
    }
    else
    {
        for(int i = 0 ; i <size ; i++)
        {
            if(temp[i] != test[i])
            {
                return false;
            }
        }
    }
    return true;
}
bool String::operator!=(const String &obj)
{
    int flag = 0;
    int size = obj.m_temp;
    if(size < m_temp)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if(temp[i] != obj.temp[i])
        {
            flag = 1;
        }
    }

    if(flag == 1)
        return true;
    else
        return false;
}
bool String::operator!=(const char *test)
{
    int flag = 0;
    int size = strlen(test);
    if (size < m_temp)
    {
        return false;
    }
    for (int i = 0; i < size; i++)
    {
        if (temp[i] != test[i])
        {
            flag = 1;
        }
    }
    if (flag == 1)
        return true;
    else
        return false;
}
bool String::operator>(const char *test)
{
   if(strcmp(temp,test) > 0 )
   {
       return true;
   }
   return false;
}
bool String::operator>(const String &obj)
{
    if (strcmp(temp, obj.temp) > 0)
    {
        return true;
    }
    return false;
}
bool String::operator<(const char *test)
{
    if (strcmp(test,temp) > 0)
    {
        return true;
    }
    return false;
}
bool String::operator<(const String &obj)
{
    if (strcmp(obj.temp, temp) > 0)
    {
        return true;
    }
    return false;
}
bool String::empty()
{
    if(temp == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int String::length()
{
    return m_temp;
}
int String::find(const char test,int pos)
{
  int size_length = m_temp;
  while(pos != size_length)
  {
    if(temp[pos] == test)
    {
        return pos;
    }
    else if(temp[size_length] == test)
    {
        return size_length;
    }    
    pos++;
    size_length--;
  }
  return 0;
}
#endif //mystring.hpp
