#define _CRT_SECURE_NO_WARNINGS

//LEARNPROGRAMO-PROGRAMMING MADE SIMPLE
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include "translate.h"
#include "message.h"
#include<windows.h>

#define ANS 15
#define ACS 4
COORD coord = { 0,0 }; // this is global variable
void gotoxy(int x, int y)
{
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*declaration of checking functions*/
void c_code(char[]);
int check(char[]);

/*structure declaration*/
typedef struct
{
    char name[ANS], code[ACS];
    float rate;
    int quantity;
} rec;
rec item;

/*declaration of display functions*/
void curser(int);
void dbill();
void d_mainmenu();
void display(rec*, int, int);
void window(int, int, int, int);
void dis_con();
void d_search();
void highlight(int, int);

/*declaration of main menu functions*/
void bill();
void edit();
void add();
void del();
void exit();

/*declaration of display submenu functions*/
void d_code();
void d_rate();
void d_quan();
void d_all();
void langSelection();

//start of main
int main()
{
    d_mainmenu();
    return 0;
}

void d_mainmenu()
{
    int i;
    char ch;
    const char* menu[] = { "   Calculate Bill","   Add Goods","   Edit Goods","   Display All ","   Search", "   Delete Goods", "   Change Language","   Exit" };
    system("cls");
    //textbackground(11);
    //textcolor(0);
    //_setcursortype(_NOCURSOR);
    window(25, 50, 20, 32);
    gotoxy(33, 18);
    printTranslateLang(main_menu);
    for (i = 0; i <= 7; i++)
    {
        gotoxy(30, 22 + i + 1);
        printf("%s\n\n\n", menu[i]);
    }
    curser(8);
}

void d_search()
{
    char ch;
    int i;
    const char* menu[] = { "   By Code","   By Rate","   By Quantity","   Back to main menu" };
    system("cls");
    //textbackground(11);
    //textcolor(0);
    window(25, 50, 20, 32);
    gotoxy(33, 18);
    printTranslateLang(search_menu);
    for (i = 0; i <= 3; i++)
    {
        gotoxy(30, 22 + i + 1);
        printf("%s\n\n\n", menu[i]);
    }
    curser(4);
}

/*function for cursor movement*/
void curser(int no)
{
    int count = 1;
    char ch = '0';
    gotoxy(30, 23);
    while (1)
    {
        switch (ch)
        {
        case 80:
            count++;
            if (count == no + 1) count = 1;
            break;
        case 72:
            count--;
            if (count == 0) count = no;
            break;
        }
        highlight(no, count);
        ch = _getch();
        if (ch == '\r')
        {
            if (no == 8)
            {
                if (count == 1) bill();
                else if (count == 2) add();
                else if (count == 3) edit();
                else if (count == 4) d_all();
                else if (count == 5) d_search();
                else if (count == 6) del();
                else if (count == 7) langSelection();
                else   exit(0);
            }
            if (no == 4)
            {
                if (count == 1) d_code();
                else if (count == 2)d_rate();
                else if (count == 3) d_quan();
                else d_mainmenu();
            }
        }
    }
}

void highlight(int no, int count)
{
    if (no == 4)
    {
        //textbackground(11);
        //textcolor(0);
        gotoxy(30, 23);
        printTranslateLang(by_code);
        //printf("   By Code          ");
        gotoxy(30, 24);
        printTranslateLang(by_rate);
        //printf("   By Rate          ");
        gotoxy(30, 25);
        printTranslateLang(by_quantity);
        //printf("   By Quantity      ");
        gotoxy(30, 26);
        printTranslateLang(back_to_main_menu);
        //printf("   Back to main menu");
        //textcolor(0);
        //textbackground(2);
        switch (count)
        {
        case 1:
            gotoxy(30, 23);
            printTranslateLang(by_code2);
            //printf(" - By Code          ");
            break;
        case 2:
            gotoxy(30, 24);
            printTranslateLang(by_rate2);
            //printf(" - By Rate          ");
            break;
        case 3:
            gotoxy(30, 25);
            printTranslateLang(by_quantity2);
            //printf(" - By Quantity      ");
            break;
        case 4:
            gotoxy(30, 26);
            printTranslateLang(back_to_main_menu2);
            //printf(" - Back to main menu");
            break;
        }
    }

    if (no == 8)
    {
        //textbackground(11);
        //textcolor(0);
        gotoxy(30, 23);
        printTranslateLang(calculate_bill);
        //printf("   Calculate Bill ");
        gotoxy(30, 24);
        printTranslateLang(add_goods);
        //printf("   Add Goods      ");
        gotoxy(30, 25);
        printTranslateLang(edit_goods);
        //printf("   Edit Goods     ");
        gotoxy(30, 26);
        printTranslateLang(display_all);
        //printf("   Display All    ");
        gotoxy(30, 27);
        printTranslateLang(search);
        //printf("   Search         ");
        gotoxy(30, 28);
        printTranslateLang(delete_goods);
        //printf("   Delete Goods   ");
        gotoxy(30, 29);
        printTranslateLang(change_language);
        //printf("   Change Language");
        gotoxy(30, 30);
        printTranslateLang(cexit);
        //printf("   Exit           ");
        //textcolor(0);
        //textbackground(2);
        switch (count)
        {
        case 1:
            gotoxy(30, 23);
            printTranslateLang(calculate_bill2);
            //printf(" - Calculate Bill ");
            break;
        case 2:
            gotoxy(30, 24);
            printTranslateLang(add_goods2);
            //printf(" - Add Goods      ");
            break;
        case 3:
            gotoxy(30, 25);
            printTranslateLang(edit_goods2);
            //printf(" - Edit Goods     ");
            break;
        case 4:
            gotoxy(30, 26);
            printTranslateLang(display_all2);
            //printf(" - Display All    ");
            break;
        case 5:
            gotoxy(30, 27);
            printTranslateLang(search2);
            //printf(" - Search         ");
            break;
        case 6:
            gotoxy(30, 28);
            printTranslateLang(delete_goods2);
            //printf(" - Delete Goods   ");
            break;
        case 7:
            gotoxy(30, 29);
            printTranslateLang(change_language2);
            //printf(" - Change Language");
            break;
        case 8:
            gotoxy(30, 30);
            printTranslateLang(cexit2);
            //printf(" - Exit           ");
            break;
        }
    }
}

void bill()
{
    char x[4] = { 0 };
    int j = 29, q = 0, size = 0, i = 1;
    float total = 0, gtotal = 0;
    FILE* file;
    file = fopen("record.txt", "r+b");
    rewind(file);
    system("cls");
    dbill();
    gotoxy(26, 15);
    printTranslateLang(enter_end_to_finish_input);
    //printf("enter  \"end\" to finish input");
    while (1)
    {
        gotoxy(25, 18);
        printf("                    ");
        gotoxy(25, 19);
        printf("                    ");
        gotoxy(25, 18);
        printTranslateLang(enter_item_code);
        //printf("enter item code:");
        scanf("%s", x);
        if (strcmp(x, "end") == 0)
            break;
        gotoxy(25, 19);
        printTranslateLang(enter_quantity);
        //printf("enter quantity:");
        scanf("%d", &q);
        rewind(file);
        while (fread(&item, sizeof(item), 1, file))
        {
            if ((strcmp(item.code, x) == 0))
            {
                total = item.rate * q;
                gotoxy(11, j);
                printf("%4d", i);
                printf("%9s", item.name);
                printf("%13d", q);
                printf("%15.2f", item.rate);
                printf("%13.2f", total);
                gtotal = gtotal + total;
                size = sizeof(item);
                item.quantity = item.quantity - q;
                j += 2;
                i++;
                fseek(file, -size, SEEK_CUR);
                fwrite(&item, sizeof(item), 1, file);
                break;
            }
        }
    }
    if (gtotal != 0)
    {
        gotoxy(30, j + 5);
        printTranslateLang(total_amount_nrs, gtotal);
        //printf("TOTAL AMOUNT = NRs. %6.2f", gtotal);
    }
    fclose(file);
    _getch();
    d_mainmenu();
}
/*function to display bill window*/
void dbill()
{
    int i;
    gotoxy(20, 10);
    //;
    for (i = 1; i <= 10; i++)
        printf("*");
    printTranslateLang(fashion_wear);
    //printf(" * FASHION WEAR * ");
    for (i = 1; i <= 10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30, 11);
    printTranslateLang(departmental_store);
    //printf("Departmental Store");
    //textcolor(1);
    gotoxy(32, 25);
    printTranslateLang(customers_bill);
    //printf("CUSTOMER'S BILL");
    //textcolor(8);
    gotoxy(13, 27);
    printTranslateLang(sn_itemname_quantity_rate_total);
    //printf("SN.   Item Name     Quantity     Rate          Total");

}
/*function to add records*/
void add()
{
    FILE* file;
    char y[ACS], x[12];
    system("cls");
    //textbackground(11);
    //textcolor(0);
    gotoxy(25, 25);
    printTranslateLang(enter_new_record_yn);
    //printf("Enter new record(Y/N)?");
    while (toupper(_getche()) == 'Y')
    {
        system("cls");
        file = fopen("record.txt", "ab");
        c_code(y);
        strcpy(item.code, y);
        gotoxy(22, 28);
        printTranslateLang(enter_rate_of_the_item);
        //printf("Enter rate of the item:");
        scanf("%f", &item.rate);
        gotoxy(22, 30);
        printTranslateLang(enter_quantity_of_the_item);
        //printf("Enter quantity of the item:");
        scanf("%d", &item.quantity);
        gotoxy(22, 32);
        printTranslateLang(enter_name_of_the_item);
        //printf("Enter name of the item:");
        scanf("%s", item.name);
        fseek(file, 0, SEEK_END);
        fwrite(&item, sizeof(item), 1, file);
        fclose(file);
        gotoxy(22, 34);
        printTranslateLang(enter_new_record_yn);
        //printf("Enter new record(Y/N)?");

    }
    d_mainmenu();
}

/*function to check availability of code*/
void c_code(char y[])
{
    int flag;
    FILE* file;
    file = fopen("record.txt", "rb");
    while (1)
    {
        system("cls");
        window(20, 58, 23, 36);
        gotoxy(32, 18);
        printTranslateLang(add_articles);
        //printf(" ADD ARTICLES ");
        flag = 1;
        rewind(file);
        gotoxy(22, 25);
        printTranslateLang(enter_new_code_of_the_article);
        //printf("Enter new code of the article:");
        scanf(" %[^\n]", y);
        while (fread(&item, sizeof(item), 1, file) == 1)
        {
            if (strcmp(y, item.code) == 0)
            {
                flag = 0;
                gotoxy(26, 30);
                printTranslateLang(code_already_exists);
                //printf("code already exists");
                gotoxy(29, 32);
                printTranslateLang(enter_again);
                //printf("enter again");
                _getch();
                break;
            }
        }
        if (flag == 1)
            break;
    }
}

/*function for editing*/
void edit()
{
    int flag = 0, choice;
    char x[ACS], y[ACS];
    FILE* file = NULL;
    int size;
    system("cls");
    //textcolor(0);
    //textbackground(11);
    window(20, 63, 20, 46);
    gotoxy(35, 18);
    printTranslateLang(edit_records);
    //printf("EDIT RECORDS");
    ;
    gotoxy(25, 23);
    printTranslateLang(enter_item_code);
    //printf("enter item code: ");
    scanf("%s", x);
    flag = check(x);
    if (flag == 0)
    {
        file = fopen("record.txt", "r+b");
        rewind(file);
        while (fread(&item, sizeof(item), 1, file))
        {
            if (strcmp(item.code, x) == 0)
            {
                //textcolor(0);
                gotoxy(25, 27);
                printTranslateLang(name_s, item.name);
                //printf("name       = %s", item.name);
                gotoxy(25, 28);
                printTranslateLang(code_s, item.code);
                //printf("code       = %s", item.code);
                gotoxy(25, 29);
                printTranslateLang(rate_g, item.rate);
                //printf("rate       = %g", item.rate);
                gotoxy(25, 30);
                printTranslateLang(quantity_d, item.quantity);
                //printf("quantity   = %d", item.quantity);
                gotoxy(25, 32);;
                printTranslateLang(do_you_want_to_edit_this_code_yn);
                //printf("Do you want to edit this record?(y/n):");
                fflush(file);
                if (toupper(_getche()) == 'Y')
                {
                    //textcolor(0);
                    gotoxy(25, 34);
                    printTranslateLang(o_edit_name);
                    //printf("1- edit name ");
                    gotoxy(25, 35);
                    printTranslateLang(t_edit_code);
                    //printf("2- edit code ");
                    gotoxy(25, 36);
                    printTranslateLang(t_edit_rate);
                    //printf("3- edit rate ");
                    gotoxy(25, 37);
                    printTranslateLang(f_edit_quantity);
                    //printf("4- edit quantity ");
                    gotoxy(25, 39); ;
                    printTranslateLang(enter_your_choice_1234);
                    //printf(" enter your choice(1, 2, 3, 4) ");
                    scanf("%d", &choice);
                    switch (choice)
                    {
                    case 1:
                        system("cls");
                        window(23, 48, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(edit_records);
                        //printf("EDIT RECORDS");
                        gotoxy(25, 24);
                        printTranslateLang(enter_new_name);
                        //printf(" enter new name: ");
                        scanf("%s", item.name);
                        size = sizeof(item);
                        fseek(file, -size, SEEK_CUR);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    case 2:
                        system("cls");
                        window(23, 65, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(edit_records);
                        //printf("EDIT RECORDS");
                        gotoxy(25, 24);
                        c_code(y);
                        strcpy(item.code, y);
                        size = sizeof(item);
                        fseek(file, -size, SEEK_CUR);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    case 3:
                        system("cls");
                        window(23, 65, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(edit_records);
                        //printf("EDIT RECORDS");
                        gotoxy(25, 24);
                        printTranslateLang(enter_new_rate);
                        //printf(" enter new rate: ");
                        scanf("%f", &item.rate);
                        size = sizeof(item);
                        fseek(file, -size, SEEK_CUR);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    case 4:
                        system("cls");
                        window(23, 65, 20, 40);
                        gotoxy(35, 18);
                        printTranslateLang(edit_records);
                        //printf("EDIT RECORDS");
                        gotoxy(25, 24);
                        printTranslateLang(enter_new_quantity);
                        //printf(" enter new quantity: ");
                        scanf("%d", &item.quantity);
                        size = sizeof(item);
                        fseek(file, -size, 1);
                        fwrite(&item, sizeof(item), 1, file);
                        break;
                    }
                    gotoxy(27, 30);
                    printTranslateLang(item_edited);
                    //printf("--- item edited---");
                    break;
                }
            }
        }
    }
    if (flag == 1)
    {
        gotoxy(32, 30);
        printTranslateLang(item_does_not_exist);
        //printf("Item does not exist.");
        gotoxy(36, 32);
        printTranslateLang(try_again);
        //printf("TRY AGAIN");
    }
    _getch();
    fclose(file);
    d_mainmenu();
}

/*function to display all records*/
void d_all()
{
    int i, j = 1;
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        display(&item, i, j);
        i++;
        j++;
        if ((j % 20) == 0)
        {
            gotoxy(27, 47);/*textcolor(0)*/;
            printTranslateLang(press_any_key_to_see_more);
            //printf("Press any key to see more...........");
            _getch();
            system("cls");
            dis_con();
            i = 26;
            continue;
        }
    }
    _getch();
    if (i == 26)
    {
        gotoxy(24, 30);
        printTranslateLang(no_articles_found);
        //printf("-- no articles found --");
    }
    _getch();
    fclose(file);
    d_mainmenu();
}

/*function to display by quantity*/
void d_quan()
{
    int i, j = 1;
    int a, b;
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    gotoxy(16, 20);;
    printTranslateLang(enter_lower_range);
    //printf("Enter lower range: ");
    scanf("%d", &a);
    gotoxy(16, 21);
    printTranslateLang(enter_upper_range);
    //printf("Enter upper range:");
    scanf("%d", &b);
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if ((item.quantity >= a) && (item.quantity <= b))
        {
            display(&item, i, j);
            i++;
            j++;
            if ((j % 20) == 0)
            {
                gotoxy(27, 47);
                printTranslateLang(press_any_key_to_see_more);
                //printf("Press any key to see more...........");
                _getch();
                system("cls");
                dis_con();
                i = 26;
                continue;
            }
        }
    }
    _getch();
    if (i == 26)
    {
        gotoxy(28, 30);
        printTranslateLang(no_items_found);
        //printf(" No items found.");
    }
    _getch();
    d_search();
    fclose(file);
}

/*function to display by rate*/
void d_rate()
{
    int i, j = 1;
    float a, b;
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    gotoxy(16, 20);;
    printTranslateLang(enter_lower_range);
    //printf("enter lower range: ");
    scanf("%f", &a);
    gotoxy(16, 21);
    printTranslateLang(enter_upper_range);
    //printf("enter upper range: ");
    scanf("%f", &b);
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if ((item.rate >= a) && (item.rate <= b))
        {
            display(&item, i, j);
            i++;
            j++;
            if ((j % 20) == 0)
            {
                gotoxy(27, 47);
                printTranslateLang(press_any_key_to_see_more);
                //printf("press any key to see more...........");
                _getch();
                system("cls");
                dis_con();
                i = 26;
                continue;
            }
        }
    }
    _getch();
    if (i == 26)
    {
        gotoxy(28, 30);
        printTranslateLang(no_item_found);
        //printf(" no item found ");
    }
    _getch();
    fclose(file);
    d_search();
}

/*function to display by code*/
void d_code()
{
    int i, j = 1;
    char x[4] = { 0 };
    FILE* file;
    dis_con();
    file = fopen("record.txt", "rb");
    rewind(file);
    i = 26;
    gotoxy(16, 20);;
    printTranslateLang(enter_item_code);
    //printf("enter item code: ");
    scanf("%s", x);
    fflush(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if ((strcmp(item.code, x) == 0))
        {
            display(&item, i, j);
            i++;
            j++;
            break;
        }
    }
    if (i == 26)
    {
        gotoxy(28, 30);
        printTranslateLang(no_item_found);
        //printf("no item found");
    }
    _getch();
    fclose(file);
    d_search();
}

/*function to display window for item display*/
void dis_con()
{
    int i;
    system("cls");
    gotoxy(20, 10);
    ;
    for (i = 1; i <= 10; i++)
        printf("*");
    printTranslateLang(fashion_wear);
    // printf(" * FASHION WEAR * ");
    for (i = 1; i <= 10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30, 11);
    printTranslateLang(departmental_store);
    //printf("Departmental Store");
    //textcolor(1);
    gotoxy(32, 17);
    printTranslateLang(records);
    //printf("RECORDS");
    //textcolor(8);
    gotoxy(18, 23);
    printTranslateLang(sn_itemname_itemcode_rate_quantity);
    //printf("SN   Item Name   Item Code      Rate     Quantity");
}

/*function to display in screen*/
void display(rec* item, int i, int j)
{
    gotoxy(16, i);//textcolor(13);
    printf("%4d", j);
    printf("%9s", item->name);
    printf("%12s", item->code);
    printf("%14.2f", item->rate);
    printf("%11d", item->quantity);
}

/*function to delete records*/
void del()
{
    int flag;
    char x[ANS];
    FILE* file = NULL, * file1=NULL;
    system("cls");
    //textbackground(11);
    //textcolor(0);
    window(23, 51, 25, 34);
    gotoxy(29, 18);
    printTranslateLang(delete_articles);
    //printf("DELETE ARTICLES");
    gotoxy(27, 27);
    printTranslateLang(enter_item_code);
    //printf("enter item code: ");
    scanf("%s", x);
    flag = check(x);
    if (flag == 0)
    {
        file1 = fopen("record1.txt", "ab");
        file = fopen("record.txt", "rb");
        rewind(file);
        while (fread(&item, sizeof(item), 1, file))
        {
            if (strcmp(item.code, x) != 0)
                fwrite(&item, sizeof(item), 1, file1);
        }
        gotoxy(27, 29);
        printTranslateLang(item_deleted);
        //printf("---item deleted---");
        remove("record.txt");
        rename("record1.txt", "record.txt");
    }
    if (flag == 1)
    {
        gotoxy(25, 29);
        printTranslateLang(item_does_not_exist);
        //printf("---item does not exist---");
        gotoxy(30, 31);
        printTranslateLang(try_again);
        //printf("TRY AGAIN");
    }
    fclose(file1);
    fclose(file);
    _getch();
    d_mainmenu();
}

/*function to check validity of code while editing and deleting*/
int check(char x[ANS])
{
    FILE* file;
    int flag = 1;
    file = fopen("record.txt", "rb");
    rewind(file);
    while (fread(&item, sizeof(item), 1, file))
    {
        if (strcmp(item.code, x) == 0)
        {
            flag = 0;
            break;
        }
    }
    fclose(file);
    return flag;
}

/*function to display box*/
void window(int a, int b, int c, int d)
{
    int i;
    system("cls");
    gotoxy(20, 10);
    //textcolor(1);
    for (i = 1; i <= 10; i++)
        printf("*");
    printTranslateLang(fashion_wear);
    //printf(" * FASHION WEAR * ");
    for (i = 1; i <= 10; i++)
        printf("*");
    printf("\n\n");
    gotoxy(30, 11);
    printTranslateLang(departmental_store);
    //printf("Departmental Store");
    //textcolor(4);
    for (i = a; i <= b; i++)
    {
        gotoxy(i, 17);
        printf("\xcd");
        gotoxy(i, 19);
        printf("\xcd");
        gotoxy(i, c);
        printf("\xcd");
        gotoxy(i, d);
        printf("\xcd");
    }

    gotoxy(a, 17);
    printf("\xc9");
    gotoxy(a, 18);
    printf("\xba");
    gotoxy(a, 19);
    printf("\xc8");
    gotoxy(b, 17);
    printf("\xbb");
    gotoxy(b, 18);
    printf("\xba");
    gotoxy(b, 19);
    printf("\xbc");
    //textcolor(4);
    for (i = c; i <= d; i++)
    {
        gotoxy(a, i);
        printf("\xba");
        gotoxy(b, i);
        printf("\xba");
    }
    gotoxy(a, c);
    printf("\xc9");
    gotoxy(a, d);
    printf("\xc8");
    gotoxy(b, c);
    printf("\xbb");
    gotoxy(b, d);
    printf("\xbc");
    //textbackground(11);
    //textcolor(0);
}
/*function to change language*/
void langSelection()
{
    system("cls");
    window(15, 61, 20, 30);
    gotoxy(16, 18);
    printTranslateLang(change_language3);
    //this variable keeps language setting that stored in file
    char langConfig[2 + 1] = { 0 };
    //language selection from console 0=en 1=tr
    int  langSelection = 0;

    //get current language setting from lang.conf file its "en" or "tr"
    getTranslateLang(langConfig);

    //set application language setting but setting is not set to file
    setTranslateLang(langConfig, false);

    //ask for language
    gotoxy(16, 22);
    printTranslateLang(for_english_press);
    gotoxy(16, 24);
    printTranslateLang(for_turkish_press);
    //get input
    gotoxy(16, 27);
    printTranslateLang(confirm_lang_change);
    scanf("%d", &langSelection);


    if (langSelection == APP_LANG_TR)
    {
        //if TR selected then set application language to Turkish 
        setTranslateLang(TURKISH_L, true);
    }
    else {
        //other cases set language to English 
        setTranslateLang(ENGLISH_L, true);
    }
    //setTranslateLang("tr",true);

    //getTranslateLang(langConfig);
    //printTranslateLang(current_lang_setting);
    //printf(":[%s]\n",langConfig);

    //printTranslateLang(welcome_to_my_program);
    //printf("\n");
    //printTranslateLang(lets_translate_messages);
    //printf("\n");

    return main();
} 
