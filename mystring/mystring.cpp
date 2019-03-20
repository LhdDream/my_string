 #include "mystring.hpp"
// // #include <iostream>
//#include <string>
using namespace std;
int main()
{
    String s5 = "ababaaabg";  
    String s6(s5.begin(),s5.end());
    cout << s6 << endl;
    return 0;
}