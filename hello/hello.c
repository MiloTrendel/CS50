#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // get input from the user
    string name = get_string("What is your name? ");

    // greets the user using his name
    printf("Hello, %s\n", name);
}