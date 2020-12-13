#include <iostream>
using namespace std;

int main()
{
    char str1[]         = "abc";
    char str2[]         = "abc";
    const char str3[]   = "abc";
    const char str4[]   = "abc";
    const char *str5    = "abc";
    const char *str6    = "abc";
    //char *str7 = "abc";
    //char *str8 = "abc";
    char *str7 = str1;
    char *str8 = str2;

    cout << "(str1 == str2) = " << (str1 == str2) << endl;
    cout << "(str3 == str4) = " << (str3 == str4) << endl;
    cout << "(str5 == str6) = " << (str5 == str6) << endl;
    cout << "(str6 == str7) = " << (str6 == str7) << endl;
    cout << "(str7 == str8) = " << (str7 == str8) << endl;

    cout << "str1 == " << &str1 << endl;
    printf("str1====%p\n", str1);
    cout << "str2 == " << &str2 << endl;
    printf("str2====%p\n", str2);
    cout << "str3 == " << &str3 << endl;
    printf("str3====%p\n", str3);
    cout << "str4 == " << &str4 << endl;
    printf("str4====%p\n", str4);
    cout << "str5 == " << &str5 << endl;
    printf("str5====%p\n", str5);
    cout << "str6 == " << &str6 << endl;
    printf("str6====%p\n", str6);
    cout << "str7 == " << &str7 << endl;
    printf("str7====%p\n", str7);
    cout << "str8 == " << &str8 << endl;
    printf("str8====%p\n", str8);
    return 0;
}
