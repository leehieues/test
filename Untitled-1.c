#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

int getInt8(uint8_t *var, uint8_t min, uint8_t max)
{
    bool retVal = 0;                                                            /*variable to return you enter value is ok or not*/
    uint32_t newVar;                                                            /* variable to receive your value*/
    fflush(stdin);
    retVal = !scanf("%d", &newVar);                                             /* check data get from keyboard is not type charater */
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


int getInt16(uint16_t *var, uint16_t min, uint16_t max)
{
    bool retVal = 0;                                                            /*variable to return you enter value is ok or not*/
    uint32_t newVar;                                                            /* variable to receive your value*/
    fflush(stdin);
    retVal = !scanf("%d", &newVar);                                             /* check data get from keyboard is not type charater */
    if (min > newVar || newVar > max || retVal == 1)
    {
        printf("\n Your value is out of range!!!");
        retVal = 1;
    }
    else
    {
        *var = (uint16_t)newVar;
    }
    return retVal;
}

void addEle(uint8_t *assign, uint8_t *index, uint8_t length);
void delEle(uint8_t *assign, uint8_t *index);
void showLink(uint8_t *assign, uint8_t *index, uint8_t length);

int main(void)
{
    uint8_t length = 20;
    uint8_t assign[20] = {[0 ... 19] = 0xFFu};
    uint8_t index[21] = {[0 ... 20] = 0xFFu};                                   /* consider element 21 is head of link list */
    uint8_t comm = 0;                                                           /* comm get your command from keyboard */
    do
    {
        printf("\n\n 1: add one element\n 2: delete one element\n 3: show link\n 4: exit\nEnter your cammand: ");
        getInt8(&comm, 1, 4);
        switch (comm)
        {
        case 1:
            addEle(assign, index, length);                                               /* add one element */
            break;
        case 2:
            delEle(assign, index);                                               /* delete one element */
            break;
        case 3:
            showLink(assign, index, length);                                             /* show link list or array */
            break;
        case 4:
            printf("\n Exit \n");                                                /* exit program */
            break;
        default:
            printf("\n EEROR!!! Your command is not correct!!!");
            break;
        }
        fflush(stdin);
        getchar();                                                               /* wait user continue */
    } while (comm != 4);
    return 0;
}

void addEle(uint8_t *assign, uint8_t *index, uint8_t length)
{
    uint8_t data = 0;                                                                /* data get value what you want to add from keyboard */
    uint8_t posi = 0;                                                                /* posi get position in array where you want to add element */
    uint8_t next = index[20];                                                        /* next is variable keep index of next element, its move and check the link from beggin to end */
    uint8_t retVal = 0;                                                              /* retVal to check data get from keybroad is ok or not */

    printf("\nposi: ");
    retVal = getInt8(&posi, 0, length - 1);
    if (retVal == 1)                                                    /* check position is out of range or not */
    {
        printf("\n ERROR!!!This position out of range\n Enter position in range 0 -> 19");
    }
    else if (assign[posi] != 0xFFu)                                                  /* check position had elemnent or not */
    {
        printf("\n ERROR!!!This position had a element\n Do not enter these position :");
        while (next != 0xFFu)                                                        /* show the positions had element */
        {
            printf(" %d ", next);
            next = index[next];
        }
    }
    else                                                                             /* add element */
    {
        printf("data: ");
        retVal = getInt8(&data, 0, 100);
        if (retVal == 1 || data > 100)                                               /* data you want to add is out of range or not */
        {
            printf("\n ERROR!!! This value out of range\n Enter value in range 0 -> 100");
        }
        else
        {
            next = 20;                                                                    /* next = head */
            if (index[20] != 0xFFu)                                                       /* check link list empty or not */
            {
                while (index[next] != 0xFFu && data > assign[index[next]])                /* find correct position in link to add element */
                {
                    next = index[next];
                }
            }
            if (assign[index[next]] == data)                                              /* check link list had this element or not */
            {
                printf("\n ERROR!!! There is this value in link");
            }
            else /* add elemnt */
            {
                assign[posi] = data;
                index[posi] = index[next];
                index[next] = posi;
                printf("\n Add element successful");
            }
        }
    }
}

void delEle(uint8_t *assign, uint8_t *index)
{
    uint8_t del = 0;                                                        /*del is variable keep value what you want to delete */
    uint8_t next = 20;                                                      /* next is variable keep index of next element, its move and check the link from beggin to end */
    uint8_t tail = 0;                                                       /* tail = 1 inform that "next" is at end of link */
    uint8_t retVal = 0;                                                     /* retVal to check data get from keybroad is ok or not */

    printf("\n The value you want to delete:");
    retVal = getInt8(&del, 0, 100);

    if (retVal == 1 || del > 100)                                           /* check your value out of range or not */
    {
        printf("\n ERROR!!! Your value out of range\n Enter value in range 0 -> 100");
    }
    else if (index[20] == 0xFFu)                                             /* check link list is empty or not */
    {
        printf("\n Link is empty");
    }
    else                                                                     /* delete element */
    {
        while (index[next] != 0xFFu && del > assign[index[next]])            /* find correct position in link to delete element */
        {
            next = index[next];
        }
        if (del == assign[index[next]])                                      /* check link list have this element or not */
        {
            assign[index[next]] = 0xFFu;
            index[next] = index[index[next]];
            printf("\n Delete successful");
        }
        else
        {
            printf("\n Link dont have that element");
        }
    }
}

void showLink(uint8_t *assign, uint8_t *index, uint8_t length)
{
    uint8_t next = index[20];                                                /* next is variable keep index of next element, its move and check the link from beggin to end */
    uint8_t comm = 0;                                                        /* comm get command you chose from keybroad */
    printf("\n 1: show link list\n 2: show array\n enter your command: ");
    uint8_t retVal = getInt8(&comm, 1, 2);                                         /* retVal to check data get from keybroad is ok or not */
    if (comm == 1 && retVal == 0)                                            /* show link list */
    {
        if (index[20] == 0xFFu)
        {
            printf("\nLink is empty\n");
        }
        else
        {
            printf("\nlink:\n");
            while (next != 0xFFu)
            {
                printf("(%d):%d   ", next, assign[next]);
                next = index[next];
            }
        }
    }
    else if (comm == 2 && retVal == 0)                                       /* show array */
    {
        printf("\nArray:\n");
        uint8_t i;
        for (i = 0; i < length; i++)
        {
            if (assign[i] == 0xFFu)
            {
                printf("%d:   ", i);
            }
            else
            {
                printf("(%d):%d   ", i, assign[i]);
            }
        }
    }
}
