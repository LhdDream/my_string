#ifndef MYSTRING_HPP
#define MYSTRING_HPP
/* code */
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <iterator>
using namespace std;
class String
{
    friend ostream &operator<<(ostream &out, String &obj);
    friend istream &operator>>(istream &in, String &obj);
  public:
    String();
    String(const String &obj);
    String(const char *test);
    String(int n,const char test);
    ~String();

  public:
    class iterator
    {
      friend ostream &operator<<(ostream &out, iterator &obj)
      {
          out << obj.test;
          return out;
      }
      public:
        iterator(const char *p_test = nullptr) : test(p_test)
        {
        }
        ~iterator()
        {
        }
      public:
        char operator *()
        {
            return test[0];
        }
        iterator& operator++()
        {
            test++;
            return *this;
        }
        iterator operator++(int)
        {
           const  char * g_test = test;
           test++;
           return iterator(g_test);
        }
        iterator& operator--()
        {
            test--;
            return *this;
        }
        iterator operator--(int)
        {
            const char * g_test = test;
            test--;
            return iterator(g_test);
        }
        iterator& operator=(const iterator &arg)
        {
            test = arg.test;
            return * this;
        }
        bool operator==(const iterator & arg) const
        {
            return arg.test == this->test;
        }
        bool operator!=(const iterator & arg) const
        {
            return arg.test != this->test;
        }
        const char * operator->() const
        {
            return test;
        }  
      private:
        const char *test;
    };
  public:
    String(iterator begin, iterator end);
  public:
    String &operator=(const String &p_obj);
    String &operator=(const char *p_test);
    char &operator[](int size); //返回一个引用,char类型
    String &operator+=(const String &obj);
    String &operator+=(const char *test);
    bool operator==(const char * test) ;
    bool operator==(const String &obj) ;
    bool operator!=(const String &obj) ;
    bool operator!=(const char * test) ;
    bool operator>(const char * test) ;
    bool operator>(const String & obj) ;
    bool operator<(const char * test) ;
    bool operator<(const String & obj) ;
 public:
    int size();
    int find(const char test,int pos ) const ;
    int find(const char * test,int pos) ;
    int find(const String &s,int pos ) ;
    bool empty();
    int length();
    String& insert(int pos ,  const char * test);
    String& append(const char * test);
    String& append(int pos , const char test);
    String& append(const String &s);
    String& append(const String &s,int pos,int n);
    String& replace(int begin,int end,const char test);
    String& erase(int pos ,int len);
    String& swap(const char * test);
    String& swap(const String & obj);
    String& substr(int begin,int end);
    const char * c_str() const;
    char& at(int n);
    int compare(const String &s) const;
    int compare(const char *s) const;
    int copy(char *s,int n,int pos = 0) const;
 public:
    void  get_next(int *nextval) ;
    iterator begin() const
    {
        return iterator(temp);
    }
    iterator end() const
    {
        return iterator(temp+m_temp);
    }
 private:
    char *temp;
    int m_temp;
    int nextval[255];
 
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
String::String(int n, const char test)
{
   m_temp = n;
   temp = new char [m_temp];
   for(int i = 0 ;i < n ;i ++)
   {
       temp[i] = test;
   }
}
String::String(iterator begin, iterator end)
{
    int g = 0;
    temp  = new char [100];
    for(String::iterator i = begin; i != end;i++)
    {
        temp[g] = *i;
        g++;
    }
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
char &String::at(int n)
{
    if(n < 0 || n>m_temp)
    {
        throw 0;
    }
    return temp[n];
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
bool String::operator==(const String & obj)
{
    int size = strlen(obj.temp);
    if (size != m_temp)
    {
        return false;
    }
    else
    {
        for (int i = 0; i < size; i++)
        {
            if (temp[i] != obj.temp[i])
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
int String::find(const char test,int pos) const
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
int String::find(const char * test,int pos) 
{
    int i = pos;//i用于主串S当前
    int j = 1;//j用于子串T
    int size = strlen(test);
    get_next(nextval);
    char p_test[100];
    sprintf(p_test,"%d",size);
    strcat(p_test,test);
    while(i <= m_temp-1 && j <= size)
    {
        if(j == 0 || temp[i] == p_test[j])
        {
            i++;
            j++;
        }
        else//指针后退重新开始匹配
        {
          j = nextval[j]; //j退回合适的位置,i值不变
        }
    }
    if( j >= size)
        return i-size+1;
    else
        return 0;
}
int String::find(const String &s, int pos)
{
    int i = pos; //i用于主串S当前
    int j = 1;   //j用于子串T
    int size = strlen(s.temp);
    get_next(nextval);
    char p_test[100];
    sprintf(p_test, "%d", size);
    strcat(p_test,s.temp);
    while (i <= m_temp - 1 && j <= size)
    {
        if (j == 0 || temp[i] == p_test[j])
        {
            i++;
            j++;
        }
        else //指针后退重新开始匹配
        {
            j = nextval[j]; //j退回合适的位置,i值不变
        }
    }
    if (j >= size)
        return i - size + 1;
    else
        return 0;
} 
//next数组， next[j] = 0 是j =1的情况下，其他情况下为Max,此集和不为空的情况下，其他情况均为1
void  String::get_next( int * nextval)
{
   //我可真是个蠢才
   //数组带错
   int i,j;
   i = 1;
   j = 0;
   nextval[1] = 0;
   char test[100];
   sprintf(test,"%d",m_temp);
   strcat(test,temp);
   while(i < m_temp )
   {
       if(j == 0 ||test[i] == test[j])
       {
           ++i;
           ++j;
           if(test[i] != test[j])//当前字符和前缀字符不相同的时候
                 nextval[i] = j; // 则当前的j为nextval在i位置上的值
            else
                nextval[i] = nextval[j];//如果与前缀字符相同的话
       }
       else
       {
            j = nextval[j];
       }
   }
}
String& String::insert(int pos, const char *test)
{
   int k = 0,j = 0,i = 0;
   int size = strlen(test) + pos;
   char p_test[100];
   for(i = pos ;i < m_temp;i++)
   {
       p_test[k] = temp[i];
       k++;
   }
   i = 0;
   for(j = pos; j <= size; j++)
   {
       temp[j] = test[i];
       i++;
   }
   m_temp += strlen(test);
   j = 0 ;
   for(i = size ; i <= m_temp;i++)
   {
       temp[i] = p_test[j];
       j ++;
   }
   temp [m_temp] ='\0';
   return *this;
}
String & String::append(const char *test)
{
    strcat(temp,test);
    m_temp += strlen(test);
    return *this;
}
String &String::append(int pos, const char test)
{
    char p_test[100];
    int i = 0;
    for(i = 0;i < pos ; i++)
    {
        p_test[i] = test;
    }
    p_test[i] = '\0';
    strcat(temp, p_test);
    m_temp += strlen(p_test);
    return *this;
}
String &String::replace(int begin, int end, const char test)
{
    if(end >m_temp)
    {
        cout << "error is too" << endl;
    }
    for(int i = begin-1;i<end;i++)
    {
        temp[i] = test;
    }
    return *this;
}
String &String::erase(int pos, int len)
{
    char test[100];
    int k = 0;
    for(int i = pos+len ; i<m_temp ; i++)
    {
        test[k]= temp[i];
        k++;
    }
    for(int j = 0;j < k ; j++)
    {
        temp[j+pos] = test[j];
    }
    m_temp = m_temp - len;
    temp[m_temp] = '\0';
    return * this;
}
String &String::swap(const char *test)
{
   char p_test[100];
   int size = strlen(test);
   strcpy(p_test,test);
   p_test[size] = '\0';
   strcpy(temp,p_test);
   return * this;
}
String & String::swap(const String & obj)
{
    char p_test[100],g_test[100];
    int size = strlen(obj.temp);
    strcpy(p_test, obj.temp);
    strcpy(g_test,temp);
    p_test[size] = '\0';
    g_test[m_temp] ='\0';
    strcpy(temp, p_test);
    strcpy(obj.temp,g_test);
    return *this;
}
String & String::substr(int begin, int end)
{
    char test[100];
    int k = 0,i = 0;
    if(end > m_temp-1)
    {
        cout << "error" << endl;
    }
    for(i = 0 ;i < begin;i++)
    {
        test[k] = temp[i];
        k++;
    }
    for( i = end + 1; i < m_temp ;i++)
    {
        test[k] = temp[i];
        k++;
    }
    strcpy(temp,test);
    return *this;
}
const char * String::c_str()  const 
{
    return temp;
}
String &String::append(const String &s)
{
    strcat(temp, s.temp);
    m_temp += strlen(s.temp);
    return *this;
}
String &String::append(const String &s, int pos, int n)
{
    char test[100];
    int k = 0;
    for(int i = pos ;i < n ;i++)
    {
        test[k] = s.temp[i];
        k++;
    }
    strcat(temp,test);
    m_temp += strlen(test);
    return * this;
}
int String::compare(const String &s) const
{
    return temp == s.temp;
}
int String::compare(const char *s) const
{
    return temp == s;
}
int String::copy(char *s, int n, int pos ) const
{
    if(n < strlen(s))
    {
        throw 0;
    }
    int k = 0;
    for(int i = pos ; i < pos+n ;i++)
    {
        s[k] = temp[i];
        k++;
    }
}
#endif //mystring.hpp
