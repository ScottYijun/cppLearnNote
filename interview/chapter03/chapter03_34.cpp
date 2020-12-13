#include <iostream>
using namespace std;

void GetMemory(char *p, int num)
{
    p = (char *)malloc(sizeof(char) * num);
}

void GetMemory2(char **p, int num)
{
    *p = (char*)malloc(sizeof(char)*num);
}

void GetMemory3(char* &p, int num)
{
    p = (char*)malloc(sizeof(char)*num);
}

char *GetMemory4(int num)
{
    char *p = (char*)malloc(sizeof(char)*num);
    return p;
}

int main()
{
    char *str1 = NULL;
    char *str2 = NULL;
    char *str3 = NULL;
    char *str4 = NULL;
    //GetMemory(str1, 20);
    GetMemory2(&str2, 20);
    GetMemory3(str3, 20);
    str4 = GetMemory4(20);

    strcpy(str2, "GetMemory 2");
    strcpy(str3, "GetMemory 3");
    strcpy(str4, "GetMemory 4");

    cout << "str1 == NULL ? " << (str1 == NULL ? "yes" : "no") << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;

    free(str2);
    free(str3);
    free(str4);
    str2 = NULL;
    str3 = NULL;
    str4 = NULL;

    return 0;
}
