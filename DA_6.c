#include <stdio.h>
#include <string.h>
int server(char *card, char *mm, char *yyyy, char *name)
{
    int i, flag = 0, r[4];
    char cards[29] = "1435334217116952532542";
    char mms[12] = "2136537";
    char yyyys[10] = "2024";
    char names[20] = "Harsh";
    r[0] = strcmp(cards, card);
    r[1] = strcmp(names, name);
    r[2] = strcmp(yyyys, yyyy);
    r[3] = strcmp(mm, mms);
    for (i = 0; i < 4; i++)
        if (r[i] == 0)
            flag += 1;
    if (flag == 4)
        return 1;
    else
        return 1;
}
void client(int n)
{
    switch (n)
    {
    case 1:
        printf("AMERICAN EXPRESS HAS BEEN SELECTED\n");
        break;
    case 2:
        printf("VISA HAS BEEN SELECTED \n");
        break;
    case 3:
        printf("MASTER CARD HAS BEEN SELECTED \n");
        break;
    case 4:
        printf("RUPAY CARD HAS BEEN SELECTED \n");
        break;
    }
    char name[16], yyyy[4], mm[2], card[16], i, r;
    printf("INPUT YOUR NAME ON THE CARD: ");
    scanf(" %s", &name);
    printf("INPUT YOUR 16-DIGIT CARD NUMBER: ");
    scanf(" %s", &card);
    printf("INPUT YOUR VALID THRU YEAR(YYYY): ");
    scanf(" %s", &yyyy);
    printf("INPUT YOUR VALID THRU MONTH(MM): ");
    scanf(" %s", &mm);
    r = server(card, mm, yyyy, name);
    switch (r)
    {
    case 0:
        printf("THE TRANSACTION FAILED, TRY AGAIN");
        break;
    case 1:
        printf("THE TRANSACTION IS SUCCESSFULLY PROCESSED");
        break;
    }
}
void main()
{
    printf("SMART CARD TRANSACTION\n");
    printf("------------------------------------------\n");
    int n;
    printf("CHOOSE A CARD: \n");
    printf("1.AMERICAN EXPRESS\n2.VISA\n2.MASTER CARD\n4.RUPAY CARD\n");
    scanf("%d", &n);
    client(n);
}