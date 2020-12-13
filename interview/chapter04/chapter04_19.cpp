#include <iostream>
using namespace std;

char LowerCaseAlphabets[] = {
    'a','b','c','d','e','f','g','h',
    'i','j','k','l','m','n','o','p',
    'q','r','s','t','u','v','w','x','y','z'};

char UpperCaseAlphabets[] = {
    'A','B','C','D','E','F','G','H',
    'I','J','K','L','M','N','O','P',
    'Q','R','S','T','U','V','W','X','Y','Z'};

char GetFourthChar(char chrSource, char alphabets[])
{
    for (int i = 0; i < 26; i++)
    {
        if (alphabets[i] == chrSource)
        {
            int index = (i + 4) % 26;
            return alphabets[index];
        }
    }
    return '\0';
}

void ReplaceChars(char chars[], int len)
{
    for (int i = 0; i < len; i++)
    {
        if ('a' <= chars[i] && chars[i] <= 'z')
        {
            chars[i] = GetFourthChar(chars[i], LowerCaseAlphabets);
        }
        else if('A' <= chars[i] && chars[i] <= 'Z')
        {
            chars[i] = GetFourthChar(chars[i], UpperCaseAlphabets);
        }
    }
};
void ReverseString(char str[], int len) //·­×ªÕû¸ö×Ö·û´®
{
    int begin = 0, end = len - 1;
    if (str[end] == '\0')
        end--;

    char hold;
    while (begin < end)
    {
        hold = str[begin];
        str[begin] = str[end];
        str[end] = hold;

        begin++;
        end--;
    }
};

void EncodeString(char str[], int len)
{
    ReplaceChars(str, len);             //Ìæ´ú×Ö·û
    ReverseString(str, len);            //·­×ªÕû¸ö×Ö·û´®
}

int main()
{
    char hello[] = "hasd11H";

    EncodeString(hello, strlen(hello));
    cout << hello << endl;

    return 0;
}

