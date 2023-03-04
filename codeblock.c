#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void password();
void heading();
void mainMenu();
void addAccount();
void viewAccount();
void searchComputer();
void editAccount();
void deleteAccount();
void help();
void ext();

//struct for id
struct computer_info{
    int id;
    char name[10];
    char author[10];
    int quantity;
    int rack;
};
struct computer_info a;
FILE *file, *file2;
//file for "1st" file read and "file2" for edit file
//struct for id End

int main()
{
  system("color 02");
  password();
}
//mainMenu work
void mainMenu()
{
    system("cls");

    int n;
    printf("\n\n\t\t ****** Main Menu *****\n");

    //mainMenu list
    printf("\n\t\t 1. Add Account\n");
    printf("\n\t\t 2. View Account list\n");
    printf("\n\t\t 3. Search Computer\n");
    printf("\n\t\t 4. Edit Account\n");
    printf("\n\t\t 5. Delete Account\n");
    printf("\n\t\t 6. Help\n");
    printf("\n\t\t 7. Exit\n\n");

    printf("\n\t\t************************\n");
    printf("\t\t Enter your Choice: ");
    scanf("%d", &n);

    if(n == 1)
    {
        addAccount();
    }
    else if(n == 2)
    {
        viewAccount();
    }
    else if(n == 3)
    {
        searchComputer();
    }
    else if(n == 4)
    {
        editAccount();
    }
    else if(n == 5)
    {
        deleteAccount();
    }
    else if(n == 6)
    {
        help();
    }
    else if(n == 7)
    {
        ext();
    }
    else
    {
        printf("\n\t\tYour choice is Wrong!\n\t\t Try again...");

        fflush(stdin);
        getchar();

        mainMenu();
    }
}

void heading()
{
  system("cls");
  printf("\n\t\t\t ####################\n");
  printf("\t\t\t | Cyber-Cafe S-500 |\n");
  printf("\t\t\t ####################");
}

void password()
{
  heading();

  char pwd1[10] = {"admin"};
  char pwd2[10];

  printf("\n\n\t\t\t Enter Password: ");
  scanf("%s", &pwd2);

  if(strcmp(pwd1, pwd2)==0)
  {
    printf("\n\n\t\t\t Match Password!\n");
    printf("\n\t\t\t Press Enter...");
  }
  else
  {
      printf("\n\n\n\n\n\t\t\t Wrong Password:( \n");
      printf("\n\t\t\t Try again...");

      fflush(stdin);
      getchar();

      password();
  }
//call mainMenu
  fflush(stdin);
  getchar();
  mainMenu();
}

void addAccount()
{
    system("cls");
    int d, count = 0;

    printf("\n\n \t\t ********Add Account **********\n\n");

    file = fopen("account.bat", "ab+");

    printf("\t\t Enter ID: ");
    scanf("%d", &d);

    rewind(file);
    while(fread(&a, sizeof(a),1,file)==1){
        if(d == a.id){
            printf("\n\n\t\t This Account is Already in Cafe...");
            count = 1;
        }
    }
    if(count == 1){
        fflush(stdin);
        getchar();

        mainMenu();
    }

    a.id = d;

    printf("\n\t\t Enter Name: ");
    scanf("%s", a.name);

    printf("\t\t Enter Author: ");
    scanf("%s", a.author);

    printf("\t\t Enter  Hour: ");
    scanf("%d", &a.quantity);

    printf("\t\t Enter Computer No: ");
    scanf("%d", &a.rack);

    fseek(file, 0, SEEK_END);
    fwrite(&a, sizeof(a),1,file);
    fclose(file);

    printf("\n\n\t\t Add Account sucessefully!");

    fflush(stdin);
    getchar();

    mainMenu();
}

//for vies Account list
void viewAccount()
{
    system("cls");

    int count = 0;
    int avelableh;

    printf("\t\t\t********************\n");
    printf("\t\t ******* View Account List *********\n");
    printf("\t\t\t********************\n\n\n");

    printf("\t\tId\tName\tAuthor\tHour\tComputer No\n\n");

    //for open file
    file = fopen("account.bat","rb");

    while(fread(&a, sizeof(a), 1, file) == 1)
    {
        printf("\t\t%d", a.id);
        printf("\t%s", a.name);
        printf("\t%s", a.author);
        printf("\t%d", a.quantity);
        printf("\t%d\n", a.rack);

        //for total hours calculation
        count = count + a.quantity;
        //for avelable hours calculation
        avelableh = 2500 - a.quantity;

    }

    fclose(file);

    printf("\n\n\n\t\t total Hours: %d",count);
    printf("\n\t\t Avelable Hours: %d", avelableh);

    printf("\n\n\t\t Press Ente...");
    fflush(stdin);
    getchar();

    mainMenu();
}

//for searchComputer
 void searchComputer()
 {
     int d, count = 0;

     system("cls");
     printf("\n\n\t\t ********** searchComputer **********\n");
     printf(" \n\t\t searching....\n\n");

     file = fopen("account.bat", "rb");
     printf("\t\t  Enter ID: ");
     scanf("%d", &d);

     while(fread(&a, sizeof(a),1,file)==1)
     {
        if(d == a.id)
            {
                printf("\n\n\t\t computer is found! \n\n");
                printf("\t\t ID: %d", a.id);
                printf("\n\t\t Name: %s", a.name);
                printf("\n\t\t Author: %s", a.author );
                printf("\n\t\t quantity: %d", a.quantity);
                printf("\n\t\t Rack: %d\n", a.rack);

                count = 1;
            }
    }
    if(count == 0)
            {
                printf("\n\n Computer is Not Found! ");
            }

        printf("\n\n\t\t press Enter...");
        fflush(stdin);
        getchar();

        mainMenu();
 }

 //for edit Account
void editAccount()
{
    int d, count = 0;

    system("cls");

    printf("\n\n\t\t *********** Edit Account *********");

    file = fopen("account.bat", "rb+");
    printf("\n\t\t Enter ID: ");
    scanf("%d", &d);

    while(fread(&a, sizeof(a), 1, file)==1)
    {
        if(d==a.id)
        {
            printf("\n\t\t Computer is Availble!\n");
            printf("\n\n\t\t ID: %d", a.id);

            printf("\n\t\t Enter New Name: ");
            scanf("%s", a.name);

            printf("\n\t\t Enter New Author: ");
            scanf("%s", a.author);

            printf("\n\t\t Enter New Hour: ");
            scanf("%d", &a.quantity);

            printf("\n\t\t Enter New Computer No: ");
            scanf("%d", &a.rack);

            fseek(file, ftell(file)-sizeof(a),0);
            fwrite(&a, sizeof(a), 1, file);
            fclose(file);

            count = 1;
        }
    }
    if(count == 0)
    {
        printf("\n\t\t\t Computer is Not Found!");
    }

    printf("\n\n\t\t Press Enter...");
    fflush(stdin);
    getchar();

    mainMenu();
}

//for Delet Account
void deleteAccount()
{
    system("cls");

    int d, count = 0;

    printf("\n\n\t\t********* Delete Account *********\n");
    printf("\n\n\t\t Enter ID for delet Account: ");
    scanf("%d", &d);

    file = fopen("account.bat", "rb");

    rewind(file);
    while(fread(&a, sizeof(a), 1, file) == 1)
    {
        if(d == a.id)
        {
            printf("\n\t\t Account is Availble!");
            printf("\n\t\t Account Name is: %s", a.name);
            printf("\n\t\t Rack no %d", a.rack);

            count = 1;
        }
    }

    if(count == 0)
    {
        printf("\n\t\t Account is not Availble");
    }
    else{
        file2 = fopen("text.bat", "wb+");

        rewind(file);
        while(fread(&a, sizeof(a), 1, file) == 1)
        {
            if(d != a.id)
            {
                fseek(file2, ftell(file2)-sizeof(a),0);
                fwrite(&a, sizeof(a), 1, file2);
            }
        }
        fclose(file);
        fclose(file2);

        remove("account.bat");
        rename("text.bat", "account.bat");

        file = fopen("account.bat", "rb");
        fclose(file);
    }
    //printf("\n\n\t\t Account Delete Successfull\n");
    printf("\n\n\t\t Press Enter...");
    fflush(stdin);
    getchar();

    mainMenu();
}

//for help
void help()
{
    system("cls");

    printf("\n\n\t\t *************** Help ***************\n\n");
    printf("\n\n\t\t 1. This is a simple cyber cafe managment Project\n");
    printf("\n\n\t\t 2. Password is: admin\n");
    printf("\n\n\t\t 3. How can I Enter your Id...?\n");
    printf("\n\n\t\t 4. See all ffeature under main menu\n");
    printf("\n\n\t\t 5. Press Enter... to back main_menu\n");
    printf("\n\n\t\t\t\t Thank you \n\n");

    printf("\n\t\t Press Enter...");
    fflush(stdin);
    getchar();
    mainMenu();
}

void ext()
{
    system("cls");
    int i;

    printf("\n\n\t\t This is Simple Projcet \n");
    printf("\n\n\n \t\t\t Thank You \n\n");

    printf("\n\t\t\t Wait....");

    fflush(stdin);
    getchar();

    password();
}
