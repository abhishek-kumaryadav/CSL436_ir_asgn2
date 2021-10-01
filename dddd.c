#include <stdio.h>
int FindString(char *Str, const char *SubStr)
{
    size_t count = 0, x, y;
    size_t Str_len = strlen(Str);
    size_t SubStr_len = strlen(SubStr);
    size_t diff = Str_len - SubStr_len;

    if (SubStr_len > Str_len)
        return 0;
    int countOuter = 0;
    for (x = 0; x <= diff; x++)
    {
        for (y = 0; y < SubStr_len; y++)
        {
            if (Str[x + y] == SubStr[y])
                count++;
            else
            {
                count = 0;
                break;
            }
        }
        if (count == SubStr_len)
            countOuter++;
    }
    return countOuter;
}
int main()
{
    printf("Hello World");
    return 0;
}