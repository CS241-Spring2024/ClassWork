#include <stdio.h>
void printMessage(char * m);

int main()
{
    printMessage("A");
    printMessage("B");
}

void printMessage(char * m)
{
    for (int i = 0; i< 5; i++)
    {
        printf("%s\n", m);
    }
}
