#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int getInt8(uint8_t *var, uint8_t min, uint8_t max)
{
    bool retVal = 0;
    uint32_t newVar;
    fflush(stdin);
    retVal = !scanf("%d", &newVar);

    if (min > newVar || newVar > max || retVal == 1)
    {
        printf("\n Your value is out of range!!!");
        retVal = 1;
    }
    else
    {
        *var = (uint8_t)newVar;
    }
    return retVal;
}

int main(int argc, char const *argv[])
{
    uint8_t lol;
    printf("%d", getInt8(&lol, 5, 20));
    return 0;
}
