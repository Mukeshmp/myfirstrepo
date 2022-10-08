#include<stdio.h>
#include<string.h>
#include<windows.h>
#include<stdlib.h>
void menu();
void createaccount();
void update();
void withdraworadd();
void record();
void accountdetails();
void delete();
struct
{
    char firstname[40],secondname[40];
    char pan[10];
    char email[50],newemail[50];
    char aadhar[50];
    char pincode[10];
    char address[50],newaddress[50];
    char mobile[20],newmobile[20];
    int dd,newdd;
    int mm,newmm;
    int yy,newyy;
    int type;
    double amount;
}entry;
void main()
{
    char pw[20];
    char ch;
    retry:
    system("cls");
    printf("\n\n===================================================\n\n");
    printf("                  ENGINEER'S BANK\n\n");
    printf("\t Please Enter Your Password to access  :  ");
    scanf("%s",pw);
    if(strcmp(pw,"c4")==0)
    {
        printf("\n\n\t\tLog in Successfully......");
        printf("\n\n\tTaking you to main menu............");
        sleep(3);
        menu();
    }
    else
    {
        printf("Oups....Password wrong !..");
        re_try_pw_ch:
        printf("\n\nEnter 1 to re try or 0 to Exit.. : ");
        scanf(" %c",&ch);
        if(ch==49)
        {
            goto retry;
        }
        else if(ch==48)
        {
            printf("\t\tThank you\n");
            exit(0);
        }
        else
        {
            printf("\n\tInvalid choice..Please re-enter... : ");
            goto re_try_pw_ch;
        }
    }
}
void menu()
{
    char choice;
    //while(1)
    {
        system("cls");
        printf("\n\n===================================================\n\n");
        printf("         WELCOME TO ENGINEER'S BANK\n\n");
        printf(" 1 . Create an account  \n");
        printf(" 2 . Update \n");
        printf(" 3 . Get Your Account Details\n");
        printf(" 4 . Withdraw / Add amount \n");
        printf(" 5 . Get All Records\n");
        printf(" 6 . Delete Account \n");
        printf(" 7 . Exit\n");
        printf("\n\n===================================================\n\n");
        printf("ENTER YOUR CHOICE HERE --> : ");
        scanf(" %c",&choice);
        switch(choice)
        {
            case 49 : createaccount();
                        break;
            case 50 : update();
                        break;
            case 51 : accountdetails();
                        break;
            case 52 :  withdraworadd();
                        break;
            case 53 :  record();
                        break;
            case 54 :  delete();
                        break;
            case 55 : exit(0);
            default : printf("\n\t\tInvalid Input....Please RE-ENTER....");
                        sleep(2);
                        menu();
        }
    }
}
void createaccount()
{
    system("cls");
    char c,t,mbl[20],name[20],surname[20],submit,ch1;
    int j=0,temp;
    double acc;
    FILE *fptr;
    fptr=fopen("cosdetails.dat","a+");
    re_try_details:
    printf("\n\n===================================================\n\n");
    printf("\t\tCREATE ACCOUNT\n\n");
    printf("1 . savings\n2 . current\n3 . Zero\n");
    printf("Enter your account type : ");
    scanf("%d",&entry.type);
    printf("\nEnter Ammount : ");
    scanf("%lf",&entry.amount);
    printf("\n\tFill up the details below\n");
    printf("\nPlease enter your Full Name : ");
    scanf("%s %s",entry.firstname,entry.secondname);
    while (1)
    {
    printf("\nPlease enter your mobile number : ");
    scanf("%s",entry.mobile);
    while(fscanf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",&temp,&acc,name,surname,mbl,&entry.dd,&entry.mm,&entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode)!=EOF)
    {
        if (strcmp(mbl,entry.mobile)==0)
        {
            printf("\n\tEntered MOBILE number is already in USE...\n");
            printf("Please RE-ENTER....");
            sleep(2);
            system("cls");
            goto re_try_details;
        }
    }
    if (strlen(entry.mobile)!=10)
        {
            printf("Mobile number must be 10 digits.......Please re enter.... \n");
        }
    else 
        {
            break;
        }
    }
    while (1)
    {
        printf("\nPlease enter your DOB(dd/mm/yyyy)format : ");
        scanf("%d/%d/%d",&entry.dd,&entry.mm,&entry.yy);
        if(entry.yy>=2005)
        {
            printf("You are not Eligible....\n\nPlease re-enter ........\n");
        }
        else 
            break;
    }
    while(1)
    {
        printf("\nPlease enter your PAN number : ");
        scanf("%s",entry.pan);
        if (strlen(entry.pan)!=6)
        {
            printf("Invalid pan number........Please re-enter...\n");
        }
        else 
        {
            break;
        }
    }
    while(1)
    {
        printf("\nPlease enter your AADHAR number : ");
        scanf(" ");
        gets(entry.aadhar);
        if (strlen(entry.aadhar)!=12)
        {
            printf("Invalid Aadhar number.....Please re-enter....\n");
        }
        else
        {
            break;
        }
    }
    printf("\nPlease enter your E-mail id : ");
    //scanf(" ");
    gets(entry.email);
    //scanf("%c",&c);
    printf("\nPlease enter your address : ");
    gets(entry.address);
    while(1)
    {
        printf("\nPlease enter your area Pincode  number : ");
        scanf("%s",entry.pincode);
        if(strlen(entry.pincode)!=6)
        {
            printf("Invalid Pincode no. .....Please re-enter....\n");
        }
        else
        {
            break;
        }
    }
    re_try_submit:
    printf("\n\t Please enter 1 to SUBMIT or 0 to RE-ENTER : ");
    scanf(" %c",&submit);
    if (submit==49)
    {
        fprintf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
        fclose(fptr);
        printf("\n\n\t\tSubmitted successfully.....\n");
        re_try_details_ch:
        printf("\n\n\n\tPlease enter 1 to go MAIN MENU or 0 to EXIT : ");
        scanf(" %c",&ch1);
        if(ch1==49)
            menu();
        else if(ch1==48)
        {
            printf("\t\tThank you\n");
            exit(0);
        }
        else
        {
            printf("\n\tInvalid choice..Please re-enter... : ");
            goto re_try_details_ch;
        }
    }
    else if(submit==48)
    {
        system("cls");
        goto re_try_details;
    }
    else
    {
        printf("\nInvalid choice....please re-enter");
        goto re_try_submit;
    }
}
void update()
{
    int i=0;
    char mobile[20],ch,ch1;
    FILE *fptr,*newfptr;
    fptr=fopen("cosdetails.dat","r");
    newfptr=fopen("newcosdetails.dat","w");
    system("cls");
    printf("\n\n===================================================\n\n");
    printf("\t\tUPDATE DETAILS\n\n");
    printf("\tEnter your mobile number: ");
    scanf("%s",mobile);
    while(fscanf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s",&entry.type,&entry.amount,&entry.firstname,&entry.secondname,&entry.mobile,&entry.dd,&entry.mm,&entry.yy,&entry.pan,&entry.aadhar,&entry.email,&entry.address,&entry.pincode)!=EOF)
    {
        if(strcmp(entry.mobile,mobile)==0)
        {
            i=1;
            re_try_Update:
            printf("\nAccount holder name : %s %s\n",entry.firstname,entry.secondname);
            printf("\tWhat you want to update.....\n");
            printf("1 . Mobile no.\n");
            printf("2 . E-mail\n");
            printf("3 . DOB\n");
            printf("4 . Address\n");
            printf("Enter your choice : ");
            scanf(" %c",&ch);
            if (ch==49)
            {
                printf("\n\tEnter new Mobile no. : ");
                scanf("%s",entry.newmobile);
                strcpy(entry.mobile,entry.newmobile);
                fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
            }
            else if (ch==50)
            {
                printf("\n\tEnter new E-mail : ");
                scanf("%s",entry.newemail);
                strcpy(entry.email,entry.newemail);
                fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
            }
            else if (ch==51)
            {
                printf("\n\tEnter new DOB (dd/mm/yyyy) format : ");
                scanf("%d/%d/%d",&entry.newdd,&entry.newmm,&entry.newyy);
                entry.dd=entry.newdd;
                entry.mm=entry.newmm;
                entry.yy=entry.newyy;
                fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
            }
            else if (ch==52)
            {
                printf("\n\tEnter new Address : ");
                scanf("%s",entry.newaddress);
                strcpy(entry.address,entry.newaddress);
                fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
            }
            else
            {
                printf("\n\tInvalid Input....Please re-enter....\n");
                goto re_try_Update;
            }
        }
        else
        {
            fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
        }
    }
    fclose(fptr);
    fclose(newfptr);
    newfptr=fopen("newcosdetails.dat","r");
    fptr=fopen("cosdetails.dat","w");
    while(fscanf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",&entry.type,&entry.amount,&entry.firstname,&entry.secondname,&entry.mobile,&entry.dd,&entry.mm,&entry.yy,&entry.pan,&entry.aadhar,&entry.email,&entry.address,&entry.pincode)!=EOF)
    {
        fprintf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
    }
    fclose(fptr);
    fclose(newfptr);
    if (i!=1)
    {
        printf("\n\tRECORD NOT FOUND....\n");
        try_update_reenter:
        printf("\nEnter 1 to RE-ENTER or 0 to go to MAIN MENU : ");
        scanf(" %c",&ch1);
        if (ch1==49)
        {
            update();
        }
        else if (ch1==48)
        {
            menu();
        }
        else
        {
            printf("\n\tInvalid choice.....Please re-enter...\n");
            goto try_update_reenter;
        }
    }
    else
    {
        printf("\n\tUPDATED SUCCESSFULLY\n");
        try_update_reenter_2:
        printf("\n\nEnter 1 to go to MAIN MENU or 0 to EXIT : ");
        scanf(" %c",&ch1);
        if (ch1==49)
        {
            menu();
        }
        else if (ch1==48)
        {
            printf("\n\tTHANK YOU");
            exit(0);
        }
        else
        {
            printf("\n\tInvalid choice.....Please re-enter...\n");
            goto try_update_reenter_2;
        }
    }
}
void accountdetails()
{
    int ch,i=0,ch1;
    char mobile[20],c;
    system("cls");
    FILE *view;
    view=fopen("cosdetails.dat","r");
    system("cls");
    printf("\n\n===================================================\n\n");
    printf("\t\tACCOUNT DETAILS\n\n");
    printf("\tEnter your mobile number: ");
    scanf("%s",mobile);
    while(fscanf(view,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",&entry.type,&entry.amount,entry.firstname,entry.secondname,entry.mobile,&entry.dd,&entry.mm,&entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode)!=EOF)
    {
        if (strcmp(mobile,entry.mobile)==0)
        {
            i=1;
            printf("\n\tNAME          :  %s %s\n",entry.firstname,entry.secondname);
            printf(" \tDOB           :  %d/%d/%d\n",entry.dd,entry.mm,entry.yy);
            printf(" \tMOBILE NO.    :  %s\n",entry.mobile);
            printf(" \tAADHAR NO.    :  %s\n",entry.aadhar);
            printf(" \tPAN NO.       :  %s\n",entry.pan);
            printf(" \tE-MAIL ID     :  %s\n",entry.email);
            printf(" \tADDRESS       :  %s\n",entry.address);
            printf(" \tPINCODE       :  %s\n",entry.pincode);
            if (entry.type==1)
                printf(" \tACCOUNT TYPE  :  Savings\n");
            if(entry.type==2)
                printf("\t ACCOUNT TYPE  :  Current\n");
            if(entry.type==3)
                printf(" \tACCOUNT TYPE  :  Zero\n");
            printf("\tAvailable Balance : %lf\n",entry.amount);
        }
    }
    fclose(view);
    if(i!=1)
    {
        printf("\n\tRecord not found......\n");
        re_try_record:
        printf("\nEnter 1 to RE-ENTER or 0 to go MAIN MENU : ");
        scanf(" %c",&c);
        if(c==49)
        {
            accountdetails();
        }
        else if(c==48)
        {
            menu();
        }
        else
        {
            printf("\n\tInvalid input.....Please re-enter... \n");
            goto re_try_record;
        }
    }
    else
    {
        re_try_record_2:
        printf("\n\nEnter 1 to RE-ENTER or 0 to go MAIN MENU  : ");
        scanf(" %c",&c);
        if(c==49)
        {
            accountdetails();
        }
        else if(c==48)
        {
            menu();
        }
        else
        {
            printf("\n\tInvalid input.....Please re-enter... \n");
            goto re_try_record_2;
        }
    }
}
void withdraworadd()
{
    system("cls");
    FILE *fptr,*newfptr;
    fptr=fopen("cosdetails.dat","r");
    newfptr=fopen("newcosdetails.dat","w");
    char mobile[20],ch,ch1;
    int i=0;
    double amount;
    printf("\n\n===================================================\n\n");
    printf("\t\tWITHDRAW / ADD AMOUNT\n");
    printf("\n\tEnter Your MOBILE number : ");
    scanf("%s",mobile);
    while(fscanf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s",&entry.type,&entry.amount,&entry.firstname,&entry.secondname,&entry.mobile,&entry.dd,&entry.mm,&entry.yy,&entry.pan,&entry.aadhar,&entry.email,&entry.address,&entry.pincode)!=EOF)
    {
        if(strcmp(mobile,entry.mobile)==0)
        {
            i=1;
            re_try_add:
            printf("\n  Account holder name : %s %s\n",entry.firstname,entry.secondname);
            printf("  \n\tPlease choose from this....\n");
            printf("     1 . Add Amount\n");
            printf("     2 . Withdraw Amount\n");
            printf("\nEnter Your choice : ");
            scanf(" %c",&ch);
            if (ch==49)
            {
                printf("\nEnter Amount to add : ");
                scanf("%lf",&amount);
                entry.amount=entry.amount+amount;
                fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
                printf("\n\tSuccessfully Added.....");
            }
            else if (ch==50)
            {
                printf("\nEnter Amount to Withdraw : ");
                scanf("%lf",&amount);
                entry.amount=entry.amount-amount;
                fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
                printf("\n\tSuccessfully Withdrawn.....");
            }
            else 
            {
                printf("\n\n\tInvalid choice....Please RE-ENTER....");
                goto re_try_add;
            }
        }
        else 
        {
            fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
        }
    }
    fclose(fptr);
    fclose(newfptr);
    newfptr=fopen("newcosdetails.dat","r");
    fptr=fopen("cosdetails.dat","w");
    while(fscanf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",&entry.type,&entry.amount,&entry.firstname,&entry.secondname,&entry.mobile,&entry.dd,&entry.mm,&entry.yy,&entry.pan,&entry.aadhar,&entry.email,&entry.address,&entry.pincode)!=EOF)
    {
        fprintf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
    }
    fclose(newfptr);
    fclose(fptr);
    if (i!=1)
    {
        printf("\n\tRecord not found....\n");
        re_try_Record_:
        printf("\nEnter 1 to RE-ENTER or 0 to go to MAIN MENU : ");
        scanf(" %c",&ch1);
        if(ch1==49)
        {
            withdraworadd();
        }
        else if(ch1==48)
        {
            menu();
        }
        else
        {
            printf("\nInvalid choice....Please RE-ENTER.....");
            goto re_try_Record_;
        }
    }
    else
    {
        re_try_Record_1:
        printf("\n\nEnter 1 to go to MAIN MENU or 0 to EXIT :  ");
        scanf(" %c",&ch1);
        if(ch1==49)
        {
            menu();
        }
        else if(ch1==48)
        {
            exit(0);
        }
        else
        {
            printf("\nInvalid choice....Please RE-ENTER.....");
            goto re_try_Record_1;
        }
    }
}
void record()
{
    system("cls");
    int i=1;
    char ch;
    FILE *fptr;
    fptr=fopen("cosdetails.dat","r");
    printf("\n\n===================================================\n\n");
    printf("\t\t\tRECORDS\n");
    printf("\n\tNAME         \tMOBILE    \tACCOUNT BALANCE\n\n");
    while(fscanf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",&entry.type,&entry.amount,entry.firstname,entry.secondname,entry.mobile,&entry.dd,&entry.mm,&entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode)!=EOF)
    {
        printf("  %d . \t%s %s\t%s\t%lf\n",i,entry.firstname,entry.secondname,entry.mobile,entry.amount);
        i=i+1;
    }
    fclose(fptr);
    if(i==1)
    {
        printf("\n\n\t\tNO RECORD\n\n");
    }
    re_try_all:
    printf("\nEnter 1 to goto MAIN MENU or 0 to EXIT : ");
    scanf(" %c",&ch);
    if (ch==49)
    {
        menu();
    }
    else if (ch==48)
    {
        exit(0);
    }
    else
    {
        printf("\n\n\tInvalid Choice....Please RE-ENTER....");
        goto re_try_all;
    }
}
void delete()
{
    system("cls");
    FILE *fptr,*newfptr;
    fptr=fopen("cosdetails.dat","r");
    newfptr=fopen("newcosdetails.dat","w");
    char mobile[20],ch,ch1;
    int i=0;
    printf("\n\n===================================================\n\n");
    printf("\t\tDELETE ACCOUNT\n");
    printf("\n\tEnter Your MOBILE number : ");
    scanf("%s",mobile);
    while(fscanf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s",&entry.type,&entry.amount,&entry.firstname,&entry.secondname,&entry.mobile,&entry.dd,&entry.mm,&entry.yy,&entry.pan,&entry.aadhar,&entry.email,&entry.address,&entry.pincode)!=EOF)
    {
        if(strcmp(mobile,entry.mobile)!=0)
        {
            fprintf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
        }
        else
        {
            printf("\n\tAccount Deleted...");
            i=1;
        }
    }
    fclose(fptr);
    fclose(newfptr);
    newfptr=fopen("newcosdetails.dat","r");
    fptr=fopen("cosdetails.dat","w");
    while(fscanf(newfptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",&entry.type,&entry.amount,&entry.firstname,&entry.secondname,&entry.mobile,&entry.dd,&entry.mm,&entry.yy,&entry.pan,&entry.aadhar,&entry.email,&entry.address,&entry.pincode)!=EOF)
    {
        fprintf(fptr,"%d %lf %s %s %s %d %d %d %s %s %s %s %s\n",entry.type,entry.amount,entry.firstname,entry.secondname,entry.mobile,entry.dd,entry.mm,entry.yy,entry.pan,entry.aadhar,entry.email,entry.address,entry.pincode);
    }
    fclose(newfptr);
    fclose(fptr);
    if (i==1)
    {
        re_try_delete:
        printf("\n\nEnter 1 togo MAIN MENU or 0 to EXIT : ");
        scanf(" %c",&ch);
        if (ch==49)
        {
            menu();
        }
        else if (ch==48)
        {
            printf("\n\n\t\tTHANK YOU");
            exit(0);
        }
        else
        {
            printf("\nInvalid Choice....Please RE-ENTER .....");
            goto re_try_delete;
        }
    }
    else
    {
        printf("\n\n\t\tNO RECORD FOUND");
        re_try_delete_1:
        printf("\n\nEnter 1 to RE-ENTER  or 0 to goto MAIN MENU : ");
        scanf(" %c",&ch);
        if (ch==49)
        {
            delete();
        }
        else if (ch==48)
        {
            menu();
        }
        else
        {
            printf("\nInvalid Choice....Please RE-ENTER .....");
            goto re_try_delete_1;
        }
    }
}