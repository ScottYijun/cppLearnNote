#include <iostream>
using namespace std;

int main()
{
    char a;
    char *str1 = &a;
    const char *str2 = "AAA";

    //strcpy(str1, "hello");
    cout << "str1====" << str1 << endl;

    //str2[0] = 'B';
    cout << "str2====" << str2 << endl;

    return 0;
}
