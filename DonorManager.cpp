//donor manager donor managing tool developed by Noushad Bhuiyan.
//test
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <cstring>
#include <fstream>
#include <cmath>
#include <conio.h>
#include <windows.h>

using namespace std;

char welcome_page();
void login_As_Admin();
int donorcount = 0;

char pass[25] = "spirit of Hopee";
map <int,string> donname;
map <int,string> donaddress;
map <int,string> donphone;
map <int,int> donage;
map <int,int> donweight;
map <int,string> donprof;
map <int,string> dongender;
vector <pair <int,int> > donortype;

void blood_donors_by_districts();
void kidney_donors_by_districts();
void eye_donors_by_districts();
void blood_donors_by_groups();
void all_blood_donors();
void view_a_blood_donor();
void all_eye_donors();
void all_kidney_donors();
void view_a_eye_donor();
void view_a_kidney_donor();
void blood();
void eye();
void kidney();

void database(int a)
{
    unsigned int j;
    system("CLS");
    int flag =0;
    char choice;
    ifstream print;
    ofstream write;
    string input, inp;

    write.open("database.txt");
    write << "\n\n\t\t\t    ***************************\n";
    write << "\t\t\t    <<< Full Database View >>>";
    write << "\n\t\t\t    ***************************";



    for (unsigned int i =0; i<donortype.size(); i++)
    {


        if (donortype[i].first >= 1 && donortype[i].first <=8)
        {
            if (flag == 0)
            {
                write << "\n\n\t\t\t\tBlood Donors: \n";
                write << "  \t\t\t __________________________________";
                write << "\n\t\t\t|ID|        Name        |";
                write << " District |\n\t\t\t|__|____________________";
                write << "|__________|\n";
                flag = 1;
            }
            write <<"\t\t\t|";
            write.width(2);
            write << donortype[i].second;
            write.fill(' ');
            write <<"|";
            write.width(20);
            write << donname[i+1];
            write.fill(' ');
            write << "|" ;
            write.width(10);
            write <<donaddress[i+1];
            write.fill(' ');
            write << "|\n";
            write << "\t\t\t|__|____________________|__________|\n";
        }

    }

    if (flag == 0)
    {
        write << "\n\n\t\t\tBlood Donors: (did not";
        write << "registered yet !)\n";
    }
    flag = 0;

    for (unsigned int i = 0; i<donortype.size(); i++)
    {

        if (donortype[i].first == 9)
        {
            if (flag == 0)
            {
                write << "\n\n\t\t\t\tEye Donors: \n";
                write << "  \t\t\t __________________________________";
                write << "\n\t\t\t|ID|        Name        |";
                write << " District |\n\t\t\t|__|____________________";
                write << "|__________|\n";
                flag = 1;
            }
            write <<"\t\t\t|";
            write.width(2);
            write << donortype[i].second;
            write.fill(' ');
            write <<"|";
            write.width(20);
            write << donname[i+1];
            write.fill(' ');
            write << "|" ;
            write.width(10);
            write <<donaddress[i+1];
            write.fill(' ');
            write << "|\n";
            write << "\t\t\t|__|____________________|__________|\n";

        }

    }

    if (flag == 0)
    {
        write << "\n\n\t\t\tEye Donors: (did not";
        write << " registered yet !)\n";
    }
    flag = 0;

    for (unsigned int i =0; i<donortype.size(); i++)
    {

        if (donortype[i].first == 10)
        {
            if (flag == 0)
            {
                write << "\n\n\t\t\t\tKidney Donors: \n";
                write << "  \t\t\t __________________________________";
                write << "\n\t\t\t|ID|        Name        |";
                write << " District |\n\t\t\t|__|____________________";
                write << "|__________|\n";
                flag = 1;
            }
            write <<"\t\t\t|";
            write.width(2);
            write << donortype[i].second;
            write.fill(' ');
            write <<"|";
            write.width(20);
            write << donname[i+1];
            write.fill(' ');
            write << "|" ;
            write.width(10);
            write <<donaddress[i+1];
            write.fill(' ');
            write << "|\n";
            write << "\t\t\t|__|____________________|__________|\n";
        }
    }

    if (flag == 0)
    {
        write << "\n\n\t\t\tKidney Donors: (";
        write << "did not registered yet !)\n";
    }
    write.close();
    system("CLS");
    print.open("database.txt");
    while (getline(print, inp))
    {
        cout << inp << endl;
    }

    if (a == 0)
    {
        wor:
        cout << "\n\n\n\t\t\tEnter 'X' To Go To The Admin Menu: ";
        cin >> choice;
        if (choice =='x' || choice == 'X')
        {
                login_As_Admin();
        }
        else
        {
            system("CLS");
            cout << "\n\n\t\t\tENTER A VALID CHOICE !";
            goto wor;
        }
    }

}


void updateinfo()
    {
        system("CLS");
        tryagain:
        database(1);
        int id;
        css:
        cout << "\n\n\n\t\t\t< Enter the Donor ID to Edit The Information >";
        cout << "\n\t\t\t< Enter '0' to go back to Admin Menu >";
        cout << "\n\n\t\t\t\tEnter 'your choice: ";
        cin >> id;

        switch (id)
        {
            case 0 : login_As_Admin();
            break;

            default:int age = donage[id] ,weight = donweight[id];
        char choice,input;
        string name = donname[id] ,profession = donprof[id];
        string district = donaddress[id], phone = donphone[id], gender = dongender[id];

        if (id <= donorcount && id!=0)
        {
            system("CLS");
            tryer:
            cout <<"\n\n\t\t\tYou've Entered Donor ID: " << id;
            cout <<"\n\t\t\tWhich belongs to: \n\n";
            cout << "\t\t\t\tname: " << donname[id];
            cout << "\n\t\t\t\tage: " << donage[id];
            cout << "\n\t\t\t\tweight: " << donweight[id];
            cout << "\n\t\t\t\tprofession: " << donprof[id];
            cout << "\n\t\t\t\tgender: " << dongender[id];
            cout << "\n\t\t\t\tdistrict: " << donaddress[id];
            cout << "\n\t\t\t\tcontact: " << donphone[id];
            cout << "\n\n\t\t\tHe/She is a: ";

            switch(donortype[id-1].first)
            {
                case 1: cout << "A positive blood donor\n";
                break;

                case 2: cout << "A negative blood donor\n";
                break;

                case 3: cout << "AB positive blood donor\n";
                break;

                case 4: cout << "AB negative blood donor\n";
                break;

                case 5: cout << "B positive blood donor\n";
                break;

                case 6: cout << "B negative blood donor\n";
                break;

                case 7: cout << "O positive blood donor\n";
                break;

                case 8: cout << "O negative blood donor\n";
                break;

                case 9: cout << "eye donor\n";
                break;

                case 10: cout << "kidney donor\n";
                break;
            }

            cout << "\n\n\t\t\tDo you want to edit?";
            cout << "\n\n\t\t\t\t(1) Edit";
            cout << "\n\n\t\t\t\t(2) Go to Admin Menu";
            cout << "\n\n\t\tEnter Your Choice: ";
            choice = getch();
            switch(choice)
                {
                    case '2': login_As_Admin();
                    break;

                    case '1': system("CLS");
                    cout << "\n\n\t\tEnter donor's name: (previously stored as \"" << donname[id] << "\" )\n\t\t\t\t";
                    cin >> name;
                    cout << "\n\n\t\tEnter donor's age: (previously stored  \"" << donage[id] << "\" )\n\t\t\t\t";
                    cin >> age;
                    cout << "\n\n\t\tEnter donor's weight: (previously stored  \"" << donweight[id] << "\" )\n\t\t\t\t";
                    cin >> weight;
                    cout << "\n\n\t\tEnter donor's district: (previously stored  \"" << donaddress[id] << "\" )\n\t\t\t\t";
                    cin >> district;
                    cout << "\n\n\t\tEnter donor's gender: (previously stored  \"" << dongender[id] << "\" )\n\t\t\t\t";
                    cin >> district;
                    cout << "\n\n\t\tEnter donor's profession: (previously stored  \"" << donprof[id] << "\" )\n\t\t\t";
                    cin >> profession;
                    cout << "\n\n\tEnter donor's phone number: (previously stored  \"" << donphone[id] << "\" )\n\t\t\t";
                    cin >> phone;
                    donname[id] = name;
                    donage[id] = age;
                    donweight[id] = weight;
                    donaddress[id] = district;
                    donprof[id] = profession;
                    donphone[id] = phone;
                    system("CLS");
                    cout << "\n\n\t\t\tThe informations have been\n\t\t\tupdated under admin protocol\n\n";
                    goto tryagain;
                    break;

                    default : system("CLS");
                    cout << "ENTER A VALID INPUT !";
                    goto tryer;

                }
        }
        else
        {
                system("CLS");
                trie:
                cout << "\n\n\t\t\tDonor ID is not available!";
                cout << "\n\n\t\t\t(1)Go To admin Menu";
                cout << "\n\t\t\t(2)Try Again";
                cout << "\n\n\t\tEnter Your Choice: ";
                choice = getch();
                switch(choice)
                {
                    case '1': login_As_Admin();
                    break;

                    case '2': system("CLS");
                    goto tryagain;
                    break;

                    default : system("CLS");
                    cout << "ENTER A VALID INPUT !";
                    goto trie;

                }

            }
            break;
        }

    }

void deleteinfo()
{
    int id;
    char choice;
    system("CLS");
    cout << "\n\n\t\t\tEnter a Donor ID to delete an donor's data: ";
    cin >> id;

    if (id <= donorcount && id!=0)
    {
        system("CLS");
        cout <<"\n\n\t\t\tYou've Entered Donor ID: " << id;
        cout <<"\n\t\t\tWhich belongs to: \n\n";
        cout << "\t\t\t\tname: " << donname[id];
        cout << "\n\t\t\t\tage: " << donage[id];
        cout << "\n\t\t\t\tweight: " << donweight[id];
        cout << "\n\t\t\t\tprofession: " << donprof[id];
        cout << "\n\t\t\t\tdistrict: " << donaddress[id];
        cout << "\n\t\t\t\tcontact: " << donphone[id] << endl <<endl;

        cout << "\t\t\tAre you sure you want to delete\n\t\t\tdata of this donor from database?\n\n";
        cout << "\n\t\t\t<Enter 'Y' for yes / 'N' for no>  ";
        choice = getch();
        switch(choice)
        {
            case 'n':
            case 'N': login_As_Admin();
               break;
            case 'y':
            case 'Y':   donorcount--;
                                donortype.erase(donortype.begin()+(id-1));

                            system("CLS");
                            swing:
                            cout << "\n\n\t\t\tThe informations have been\n\t\t\tdeleted under admin protocol\n\n";
                            cout << "\n\n\t\t\t(1) Go To Admin Menu";
                            cout << "\n\t\t\t(2) Delete another donor information";
                            cout << "\n\n\t\t\t\tEnter Your Choice: ";
                            choice = getch();
                            switch(choice)
                            {
                                case '1': login_As_Admin();
                                break;
                                case '2' : deleteinfo();
                                break;
                                default: system("CLS");
                                cout << "\n\n\t\t\t\tENTER A VALID INPUT ! ";
                                goto swing;
                            }
        }
    }

    else
    {
        system("CLS");
        swings:
            cout << "\n\n\t\t\tDonor ID is not available!";
            cout << "\n\n\t\t\t(1)Go To admin Menu";
            cout << "\n\t\t\t(2)Try Again";
                cout << "\n\n\t\tEnter Your Choice: ";
             choice = getch();
             switch(choice)
                            {
                                case '1': login_As_Admin();
                                break;
                                case '2' : deleteinfo();
                                break;
                                default: system("CLS");
                                cout << "\n\n\t\t\t\tENTER A VALID INPUT ! ";
                                goto swings;
                            }
    }

}

void Donor_finder()
    {
        char choice;
       system("CLS");
       donfin:
       system("color 2F");
        cout <<"\n\n\n\t\t\t\ Here searching a donor is pretty much easy\n\t\t\t\t\ What type of donor do you need?\n";
        cout <<"\n\n\n\t\t\t\t    (1) Blood donors\n\n";
         cout <<" \t\t\t\t    (2) Eye donors\n\n";
          cout <<" \t\t\t\t    (3) Kidney donors\n\n";
          cout <<" \t\t\t\t    (4) Main menu\n\n";
           cout <<"\n\n\t\t\t\tEnter your choice: ";
           choice = getch();
           switch (choice)
           {
                case '1' : blood();
                break;

                case '2': eye();
                break;

                case '3': kidney();
                break;

                case '4': welcome_page();
                break;

                default:
                system("CLS");
                cout << "\n\t\t\t\tENTER A VALID CHOICE\n";
                goto donfin;

           }

}
void register_as_donor();
void resetpass();

void showlogo()
{

    printf("\t\t\                   .':odxkkkxdl:'");
    printf("\n\t\t\                ,d0NMMMMMMMMMMWNOl'");
    printf("\n\t\t\              ,x0KNWWWWWNNNWWWWMNKOo.");
    printf("\n\t\t\             ;dolkNWWWWN0OOXWNWWNxldd,");
    printf("\n\t\t\            ,l::kNWWWWWNOdkXWWWWWXx::l.");
    printf("\n\t\t\           .::,dXMMWWWWWKOKWWWWWMWKo,::");
    printf("\n\t\t\           .:;:OWWWNKkdO0xOkxOKNWWNx;::.");
    printf("\n\t\t\           .c;;kNMWO,  lklx:  ,OMWNd;::.");
    printf("\n\t\t\            ,:,c0NNo   .'...  .dWNk:,:'");
     printf("\n\t\t\           .;,,ck0;           cKx:',,.");
     printf("\n\t\t\            .,:,;:.           ':,;:,");
     printf("\n\t\t\              .;::,.         .,::,.");
     printf("\n\t\t\                .',.        .;,..    ");

    printf("\n\n");
    cout <<"\t\t  ////\n\t\t (*)~~^`*-  spirit of Hopee donor manager : \t  \\\\\\\\\\\n\t\t  \\\\\\\\\\ \t\ta donor managing tool   -*`^~~(*)\n\t\t\t\t\t\t\t\t\   /////";

}

char main_page()
{
    char c ;
    system("CLS");
    work:
    system("color F0");
    showlogo();
    cout << "\n\n\n\t\t\t___________________________________ ";
    cout << "\n\n\t\t\t   Developed by Noushad Bhuiyan";
    cout << "\n\t\t\t___________________________________ ";
    cout << "\n\n\n\n\t\t\t< Press 'E' to enter / 'X' to exit program: > ";
    c = getch();
    if (c!='e' && c!='x' && c!='E' && c!='X')
    {
           system("CLS");
           cout <<"\n\t\t\t\t PLEASE ENTER A VALID INPUT\n\n";
            goto work;
    }

    if (c == 'x' || c == 'X')
     {
        system("CLS");
        cout <<"\n\n\n\t\t\tThis session >>>>\n\n\n\t\t\tTotal donors registered: " << donorcount << endl<< endl<< endl<< endl<< endl;
        return 0;
     }

    for (int i=0; i<50; i++)
    {

        cout <<"\n\n\n\n\n\n\n\n\n\t\t\t\t\tLoading...\n\n";
        for (int j=0; j<i; j++)
        {
            cout << "  ";
        }
        cout << " >>>>>>>>";
        system("CLS");
    }

    if (c  == 'e' || c=='E')
     {
            welcome_page();
     }

}

char welcome_page()
{
     char choice;
    system("CLS");
    work_1:
    system("color 3F");
    showlogo();
    cout << "\n\n\t\t\t\t(1)  Login as administrator.\n";
    cout << "\n\t\t\t\t(2)  Find a donor.\n";
    cout << "\n\t\t\t\t(3)  Register as a donor.\n";
    cout << "\n\t\t\t\t(4)  Exit.\n\n\t\t\tEnter your choice: ";
     choice = getch();
    if (choice!= '1' &&choice!= '2' && choice!= '3' &&choice!= '4')
    {
        system("CLS");
        cout << "\n\n\n\t\t\t\tENTER A VALID CHOICE";
        goto work_1;
    }
        switch (choice)
        {
                case '1': login_As_Admin();
                                break;
                case '2': Donor_finder();
                                break;
                case '3': register_as_donor();
                                break;
                default: system("CLS");
        cout <<"\n\n\n\t\t\tThis session >>>>\n\n\n\t\t\tTotal donors registered: " << donorcount << endl<< endl<< endl<< endl<< endl;
                                return 0;

        }

}

void login_As_Admin()
{
    system("CLS");
    system("color 0A");
    int flag =0;
    char choice, inp , passinp[25];


    work_3:

    cout <<"\n\n\n\t\t\t::: Enter your admin password :::\n";
    cout << "\n\t\t\t\t      ";

    for(int i =0; ; i++)
    {
        inp = getch();

        if (inp == 13)
        {
                break;
        }
        else
        {
            if (inp == pass[i])
            {
                flag = 1;
            }
            else if (inp == '\b')
            {
                i--;
                flag = 1;
            }

            else
            {
                flag = 0;
            }

        }
        if (inp != '\b')
        {
            cout << "*";
        }
    }

   if (flag ==1)
   {
            system("CLS");
            work_admn:
            cout << "\n\n\n\t\t\t\tHello Admin ! \n";
            cout << "\n\t\t\t\t(1) Generate The Database\n";
            cout << "\n\t\t\t\t(2) Update donor info\n";
            cout << "\n\t\t\t\t(3) Delete donor info\n";
            cout << "\n\t\t\t\t(4) Reset password\n";
            cout << "\n\t\t\t\t(5) Main menu\n\n";
            cout <<"\t\t\t\t  Enter your choice: ";
            cin >> choice;
                    switch (choice)
             {
                    case '1': database(0);
                    break;

                    case '2':updateinfo();
                    break;

                    case '3': deleteinfo();
                    break;

                    case '4': resetpass();
                    break;

                    case'5': welcome_page();
                    break;


                    default:
                                    system("CLS");
                                    cout << "\t\t\t\tENTER A VALID CHOICE";
                                    goto work_admn;

             }
   }
   else
   {
        system("CLS");
        cout << "\t\t\tACCESS DENIED!  ENTER A VALID PASSWORD!";
        goto work_3;

   }


}

void resetpass()
{
    char inp,c,d,passchk[25] ;
    int flag =0;
    reset:
    cout << "\n\n\n\t\t\tEnter older password: ";

        for(int i =0; ; i++)
    {
        inp = getch();

        if (inp == 13)
        {
                break;
        }
        else
        {
                if (inp == pass[i])
                {
                        flag =1;
                }
                else
                {
                        flag =0;
                }
        }
        cout << "*";
    }

    if (flag==1)
    {
        system ("CLS");
        cout << "\n\t\t\tEnter new password: ";
            for(int i =0; ; i++)
    {
        inp = getch();

        if (inp == 13)
        {
                break;
        }
        else
        {
                passchk [i] = inp;
        }
        cout << "*";
    }

        strcpy(pass,passchk);
        upd:

        cout << "\n\n\t\t\tNew Password Updated.\n\n\t\t\t   (1) Admin menu\n\n";
       cout << "\t\t\tEnter your choice: ";
        d = getch();
        if (d!='1')
        {
            goto upd;
        }
        else
        {
            login_As_Admin();
        }
    }

    else
    {
        wrongpass:
        cout << "\n\n\n\t\t\tACCESS DENIED! You entered a wrong password\n\n\t\t\t (1) Try again\n\t\t\t\n\t\t\t (2) Admin menu\t\t\t\n\n\t\t\tEnter your choice: ";
          c = getch();
        if (c == '1')
        {
            goto reset;
        }
        else if (c == '2')
        {
            login_As_Admin();
        }
        else
        {
                system("CLS");
                cout << "\n\n\n\t\t\tENTER A VALID CHOICE";
                goto wrongpass;
        }
    }

}

void register_as_donor();
void bloodreg()
{
    int age ,weight ;
    char choice,input , back2menu;
    string name,profession,district,phone,gender;
    system("CLS");
    system("color 4F");
    cout << "\n\n\t\t\tEnter your Name (MAX 20): ";
    cin >> name;
    cout << "\n\n\t\t\tEnter your age: ";
    cin >> age;
    cout << "\n\n\t\t\tEnter your weight: ";
    cin >> weight;
    if (age <18 || weight <50)
    {

        mainmenu:
        system("CLS");
        cout << "\n\n\t\t\tSorry your health is not perfect for donating blood.\n\n\n\t\t\t(1) Main Menu\n\n\n\t\t\tEnter your choice: ";
        choice = getch();
        if (choice =='1')
            {welcome_page();}
        else
        {goto mainmenu;}
    }
    else
    {
        donorcount++;
        cout << "\n\n\t\t\tYour Gender: ";
        cin >> gender;
        cout << "\n\n\t\t\tYour Profession: ";
        cin >> profession;
        cout << "\n\n\t\t\tYour District: ";
        cin >> district;
        transform(district.begin(), district.end(),district.begin(), ::tolower);
        cout << "\n\n\t\t\tContact Number: ";
                cin>>phone;
        bloody:
            system("CLS");
        cout << "\n\t\t\tWelcome "<< name << ".\t\tDonor ID: "<<donorcount;
        cout << "\n\n\t\t\tEnter your blood group (with RH factor)\n";
        cout << "\n\t\t\t\t(1) A positive";
        cout << "\t\t(2) A negative\n";
        cout << "\n\t\t\t\t(3) AB positive";
        cout << "\t\t(4) AB negative\n";
        cout << "\n\t\t\t\t(5) B positive";
        cout << "\t\t(6) B negative\n";
        cout << "\n\t\t\t\t(7) O positive";
        cout << "\t\t(8) O negative\n\n";
        cout <<" \t\t\t\t  Enter your choice: ";
        choice = getch();
        if (choice > '0' && choice <'9')
        {
            system("CLS");
            confirming:
            cout << "\n\n\t\t\t#  Your information  # \n";
            cout << "\n\n\t\tName: "<< name;
            cout << "\t\tAge: "<< age;
            cout << "\n\n\t\tWeight: "<< weight;
            cout << "\t\tGender: "<< gender;
            cout << "\n\n\t\tProfession: "<<profession;
            cout << "\tDistrict: "<< district;
            cout << "\n\n\t\tContact number: "<<phone;
            cout <<"\n\n\t\t\tConfirm your registration? 'Y' / 'N\n\n\t\t\tEnter your choice: " ;
            input = getch();
            if (input == 'n' || input == 'N')
            {
                    donorcount --;
                    register_as_donor();
            }
            else if (input != 'y' & input!= 'Y')
            {

                system("CLS");
                cout << "\n\t\t\tENTER A VALID INPUT";
                goto bloody;

            }
        }
    else
    {
         system("CLS");
        cout << "\n\t\t\tENTER A VALID INPUT BETWEEN (1-8)";
        goto bloody;
    }

    donname[donorcount] = name;
    donaddress[donorcount] = district;
    donage[donorcount] = age;
    donweight[donorcount] = weight;
    dongender[donorcount] = gender;
    donphone[donorcount] = phone;
    donprof[donorcount] = profession;

     switch (choice)
     {

            case '1': donortype.push_back(make_pair(1,donorcount));
            break;

            case '2': donortype.push_back(make_pair(2,donorcount));
            break;

            case '3': donortype.push_back(make_pair(3,donorcount));
            break;

            case '4': donortype.push_back(make_pair(4,donorcount));
            break;

            case '5': donortype.push_back(make_pair(5,donorcount));
            break;

            case '6': donortype.push_back(make_pair(6,donorcount));
            break;

            case '7': donortype.push_back(make_pair(7,donorcount));
            break;

            case '8': donortype.push_back(make_pair(8,donorcount));
            break;

            default: system("CLS");
                            cout << "\n\n\n\t\t\tENTER A VALID CHOICE";
                            goto bloody;

     }
     system("CLS");
     backs:
     cout << "\n\n\t\t\tCongratulation "<<name<<"! You are\n\n\t\t\tsuccessfully registered as a blood donor.";
     cout << "\n\n\t\t\t\t(1) Main Menu\n\t\t\t\t(2) Donor Registration Menu\n\n\n\t\t\t\tEnter your choice: ";
     back2menu = getch();
     switch (back2menu)
     {
            case '1' : welcome_page();
            break;

            case '2' : register_as_donor();
            break;

            default: system("CLS");
            cout << "\n\t\t\t\tENTER A VALID CHOICE\n";
            goto backs;


     }

    }

}

void eyereg()
{
    int age ,weight ;
    char choice,input,b;
    string name,profession,district,phone,gender;
    system("CLS");
    eyework:
    cout << "\n\n\t\t\tEyes are precious thing to mankind.\n\tA wise man utilizes the gift while alive, and after death too..";
    cout << "\n\n\tYou have to follow the do's and not do's to be an eye donor: \n\n\n\n\t\t\t";
    cout << ">> must be not a diabetic patient\n";
    cout << "\n\t\t\t>> must be not a hypentensioned patient\n";
    cout << " \n\t\t\t>> must be not a cancer patient.";
    cout << "\n\n\n\t\tI agree and I'm able to be an smart profiled donor.\n\n\t\t\t<Enter 'Y' for yes / 'N' for no>";
        cout <<"\n\n\t\t\t\t  Enter your choice: ";
        choice = getch();
        if (choice == 'n' || choice == 'N')
        {
            register_as_donor();
        }
        else if (choice == 'Y'  || choice =='y')
        {
            system("CLS");
            donorcount++;
            cout << "\n\n\t\t\tEnter your Name (MAX 20): ";
            cin >> name;
            cout << "\n\n\t\t\tEnter your age: ";
            cin >> age;
            cout << "\n\n\t\t\tEnter your weight: ";
            cin >> weight;
            cout << "\n\n\t\t\tYour Gender: ";
            cin >> gender;
            cout << "\n\n\t\t\tYour Profession: ";
            cin >> profession;
            cout << "\n\n\t\t\tYour District: ";
            cin >> district;
            transform(district.begin(), district.end(),district.begin(), ::tolower);
            cout << "\n\n\t\t\tContact Number: ";
            cin>>phone;
            system("CLS");
                       confirm:
            cout << "\n\n\t\t\t#  Your information  # \n";
            cout << "\n\n\t\tDonor ID: "<< donorcount <<"\n\t\tName: "<< name;
            cout << "\t\tAge: "<< age;
            cout << "\n\n\t\tWeight: "<< weight;
            cout << "\t\tGender: "<< gender;
            cout << "\n\n\t\tProfession: "<<profession;
            cout << "\tDistrict: "<< district;
            cout << "\n\n\t\tContact number: "<<phone;
            cout <<"\n\n\t\t\tConfirm your registration? 'Y' / 'N\n\n\t\t\tEnter your choice: " ;
            input = getch();
            if (input == 'n' || input == 'N')
            {
                donorcount --;
                register_as_donor();
            }
            else if (input != 'y' & input!= 'Y')
            {

            system("CLS");
            cout << "\n\t\t\tENTER A VALID INPUT";
            goto confirm;

            }
            donortype.push_back(make_pair(9,donorcount));
            donname[donorcount] = name;
            donaddress[donorcount] = district;
            donage[donorcount] = age;
            donweight[donorcount] = weight;
            dongender[donorcount] = gender;
            donphone[donorcount] = phone;
            donprof[donorcount] = profession;
            system("CLS");
     backs:
     if (input == 'y' || input == 'Y')
     {
        cout << "\n\n\t\t\tCongratulation "<<name<<"! You are\n\n\t\t\tsuccessfully registered as an eye donor.";
     cout << "\n\n\t\t\t\t(1) Main Menu\n\t\t\t\t(2) Donor Registration Menu\n\n\n\t\t\t\tEnter your choice: ";
      b = getch();
     switch (b)
     {
            case '1' : welcome_page();
            break;

            case '2' : register_as_donor();
            break;

            default: system("CLS");
            cout << "\n\t\t\t\tENTER A VALID CHOICE\n";
            goto backs;

     }


     }

        }

        else
        {
            system("CLS");
            cout << "\n\n\t\t\tENTER A VALID INPUT :)\n";
            goto eyework;
        }

}

void kidneyreg()
{
    int age ,weight ;
    char choice,input,c ;
    string name,profession,district,phone,gender;
    system("CLS");
    kid:
    cout << "\n\n\n\n   I, the undersigned, understand that in making application to spirit of HopeeE donor\n   managing tool for expense reimbursement, I am required to provide certain\n   information for donating kidney.\n\n";
    cout << "   I accept all terms and condition and I'm eager to be kidney donor.\n   People can contact me through given information for transplanting kidney.\n\n\n\t\t\t";
    cout <<"Enter 'Y' for yes / 'N' for no";
    cout << "\n\n\t\t\tEnter your choice: ";
    choice = getch();

    if (choice == 'n' || choice== 'N')
    {
        register_as_donor();
    }
    else if ( choice != 'y' && choice != 'Y')
    {
        system("CLS");
        cout << "\n\n\t\t\tENTER A VALID INPUT !";
        goto kid;
    }

   else
   {
        system("CLS");
            donorcount++;
        cout << "\n\n\t\t\tEnter your Name (MAX 20): ";
        cin >> name;
        cout << "\n\n\t\t\tEnter your age: ";
        cin >> age;
        cout << "\n\n\t\t\tEnter your weight: ";
        cin >> weight;
        cout << "\n\n\t\t\tYour Gender: ";
        cin >> gender;
        cout << "\n\n\t\t\tYour Profession: ";
        cin >> profession;
        cout << "\n\n\t\t\tYour District: ";
        cin >> district;
        transform(district.begin(), district.end(),district.begin(), ::tolower);
        cout << "\n\n\t\t\tContact Number: ";
        cin>>phone;
        system("CLS");
        confirmkid:
        cout << "\n\n\t\t\t#  Your information  # \n";
        cout << "\n\n\t\tDonor ID: "<< donorcount <<"\n\t\tName: "<< name;
        cout << "\t\tAge: "<< age;
        cout << "\n\n\t\tWeight: "<< weight;
        cout << "\t\tGender: "<< gender;
        cout << "\n\n\t\tProfession: "<<profession;
        cout << "\tDistrict: "<< district;
        cout << "\n\n\t\tContact number: "<<phone;
        cout <<"\n\n\t\t\tConfirm your registration? 'Y' / 'N\n\n\t\t\tEnter your choice: " ;
        input = getch();

        if (input == 'n' || input == 'N')
        {
                donorcount --;
                register_as_donor();
        }
        else if (input != 'y' & input!= 'Y')
        {

        system("CLS");
        cout << "\n\t\t\tENTER A VALID INPUT";
        goto confirmkid;

        }
            donortype.push_back(make_pair(10,donorcount));
            donname[donorcount] = name;
            donaddress[donorcount] = district;
            donage[donorcount] = age;
            donweight[donorcount] = weight;
            dongender[donorcount] = gender;
            donphone[donorcount] = phone;
            donprof[donorcount] = profession;
            system("CLS");
     backs:
     cout << "\n\n\t\t\tCongratulation "<<name<<"! You are\n\n\t\t\tsuccessfully registered as a kidney donor.";
     cout << "\n\n\t\t\t\t(1) Main Menu\n\t\t\t\t(2) Donor Registration Menu\n\n\n\t\t\t\tEnter your choice: ";
     c = getch();
     switch (c)
     {
            case '1' : welcome_page();
            break;

            case '2' : register_as_donor();
            break;

            default: system("CLS");
            cout << "\n\t\t\t\tENTER A VALID CHOICE\n";
            goto backs;


     }
   }

}

void register_as_donor()
{
    char choice;
    system("CLS");
    work_2:
    system("color 5F");

    cout << "\n\n\t\t\tWelcome. Register yourself as a donor!\n\t\t\tlet us know what do you want to donate in future?";
    cout << "\n\n\t\t\t\t(1) Blood donate\n";
    cout << "\n\t\t\t\t(2) Eye donate\n";
    cout << "\n\t\t\t\t(3) Kidney donate\n";
    cout << "\n\t\t\t\t\(4) Main Menu\n\n";
    cout <<" \t\t\t\t  Enter your choice: ";
    choice = getch();

     switch (choice)
     {
            case '1': bloodreg();
            break;

            case '2': eyereg();
            break;

            case '3': kidneyreg();
            break;

            case '4': welcome_page();
            break;

            default: system("CLS");
                            cout <<"\n\t\t\t\t PLEASE ENTER A VALID INPUT";
                            goto work_2;

     }

}

void blood()
{
    char choice;
    system("CLS");
    blooddons:
    int counter =0;
    for (unsigned int i =0; i<donortype.size(); i++)
        {
            if (donortype[i].first >= 1 && donortype[i].first <=8)
            {
               counter++;

            }

        }
    cout << "\n\n\t\t\tTotal blood donors registered: " << counter;
    cout << "\n\n\n\t\t\t(1) List donors by districts";
    cout << "\n\n\t\t\t(2) List donors by blood groups";
    cout << "\n\n\t\t\t(3) View the full blood donor list";
    cout << "\n\n\t\t\t(4) View a donor's full information";
    cout << "\n\n\t\t\t(5) Back to Donor Finding Menu";
    cout <<"\n\n\n\t\t\t\tEnter your choice: ";
    choice = getch();

    switch(choice)
    {
        case '1' : blood_donors_by_districts();
                    break;
        case '2' : blood_donors_by_groups();
                    break;
        case '3' : all_blood_donors();
                    break;
        case '4' : view_a_blood_donor();
                    break;
        case '5' : Donor_finder();
        break;
        default : system("CLS");
                    cout << "\t\t\tENTER A VALID INPUT!";
                    goto blooddons;
    }
}

void eye()
{
    char choice;
    system("CLS");
    eyedons:
    int counter =0;
    for (unsigned int i =0; i<donortype.size(); i++)
        {
            if (donortype[i].first ==9)
            {
               counter++;

            }

        }
    cout << "\n\n\t\t\tTotal eye donors registered: " << counter;
    cout << "\n\n\n\t\t\t(1) List donors by districts";
    cout << "\n\n\t\t\t(2) View the full eye donor list";
    cout << "\n\n\t\t\t(3) View a donor's full information";
    cout << "\n\n\t\t\t(4) Back to Donor Finding Menu";
    cout <<"\n\n\n\t\t\t\tEnter your choice: ";
    choice = getch();

    switch(choice)
    {
        case '1' : eye_donors_by_districts();
                    break;
        case '2' : all_eye_donors();
                    break;
        case '3' : view_a_eye_donor();
                    break;
        case '4' : Donor_finder();
        break;
        default : system("CLS");
                    cout << "\t\t\tENTER A VALID INPUT!";
                    goto eyedons;
    }
}

void kidney()
{
    char choice;
    system("CLS");
    kidneydons:
    int counter =0;
    for (unsigned int i =0; i<donortype.size(); i++)
        {
            if (donortype[i].first == 10)
            {
               counter++;

            }

        }
    cout << "\n\n\t\t\tTotal kidney donors registered: " << counter;
    cout << "\n\n\n\t\t\t(1) List donors by districts";
    cout << "\n\n\t\t\t(2) View the full kidney donor list";
    cout << "\n\n\t\t\t(3) View a donor's full information";
    cout << "\n\n\t\t\t(4) Back to Donor Finding Menu";
    cout <<"\n\n\n\t\t\t\tEnter your choice: ";

    choice = getch();

    switch(choice)
    {
        case '1' : kidney_donors_by_districts();
                    break;
        case '2' : all_kidney_donors();
                    break;
        case '3' : view_a_kidney_donor();
                    break;
        case '4' : Donor_finder();
        break;
        default : system("CLS");
                    cout << "\t\t\tENTER A VALID INPUT!";
                    goto kidneydons;
    }

}

void blood_donors_by_districts()
{
    system("CLS");
    int flag =0, namelength,addresslength,j = 0;
    char choice;
    ifstream print;
    ofstream write;
    string input, inp;
    cout << "\t\t\tEnter a district name to search a donor: ";
    cin >> input;
    transform(input.begin(), input.end(),input.begin(), ::tolower);
    for (unsigned int i =0; i<donortype.size(); i++)
        {

            if (donortype[i].first >=1 && donortype[i].first <=8)
            {
                if (input == donaddress[i+1])
                {

                    if (flag == 0)
                    {
                        write.open("blood_donors_by_districs.txt");
                        write << "\n\t\t\t<<< Blood Donors From \""<< input <<"\" >>>\n\n";
                        write << "  \t\t\t __________________________________";
                        write << "\n\t\t\t|ID|        Name        |";
                        write << " District |\n\t\t\t|__|____________________";
                        write << "|__________|\n";
                        flag = 1;
                    }
                    write <<"\t\t\t|";
                    write.width(2);
                    write << donortype[i].second;
                    write.fill(' ');
                    write <<"|";
                    write.width(20);
                    write << donname[i+1];
                    write.fill(' ');
                    write << "|" ;
                    write.width(10);
                    write <<donaddress[i+1];
                    write.fill(' ');
                    write << "|\n";
                    write << "\t\t\t|__|____________________|__________|\n";

                }

            }

        }
        write.close();
        if (flag == 0)
        {
            system("CLS");
            write << "\n\n\t\t\t! No such donor belong to the district !";
            write.close();
            blooo:
            cout << "\n\n\t\tOops! There is no such registered donor from this district :(";
            cout << "\n\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto blooo;
            }

        }
        else
        {
            flag = 0;
            system("CLS");
            wah:
            print.open("blood_donors_by_districs.txt");
            while (getline(print, inp))
            {
                cout << inp << endl;
            }
            cout << "\n\t\t\t\t(1) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();
            switch(choice)
            {

                case '1': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto wah;
            }


        }

}

void eye_donors_by_districts()
{
    system("CLS");
    int flag =0,j,namelength,addresslength;
    char choice;
    ifstream print;
    ofstream write;
    string input, inp;
    cout << "\t\t\tEnter a district name to search a donor: ";
    cin >> input;
    transform(input.begin(), input.end(),input.begin(), ::tolower);

    write.open("eye_donors_by_districs.txt");
    write << "\n\t\t\t<<< Eye Donors From \""<< input <<"\" >>>\n\n";
    write << "  \t\t\t __________________________________";
    write << "\n\t\t\t|ID|        Name        |";
    write << " District |\n\t\t\t|__|____________________";
    write << "|__________|\n";
    for (unsigned int i =0; i<donortype.size(); i++)
        {

            if (donortype[i].first == 9)
            {
                if (input == donaddress[i+1])
                {
                    flag = 1;
                    write <<"\t\t\t|";
                    write.width(2);
                    write << donortype[i].second;
                    write.fill(' ');
                    write <<"|";
                    write.width(20);
                    write << donname[i+1];
                    write.fill(' ');
                    write << "|" ;
                    write.width(10);
                    write <<donaddress[i+1];
                    write.fill(' ');
                    write << "|\n";
                    write << "\t\t\t|__|____________________|__________|\n";
                }

            }

        }
        write.close();
        if (flag == 0)
        {
            system("CLS");
            write << "\n\n\t\t\t! No such donor belong to the district !";
            write.close();
            blooo:
            cout << "\n\n\t\tOops! There is no such registered donor from this district :(";
            cout << "\n\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto blooo;
            }

        }
        else
        {
            flag = 0;
            system("CLS");
            wahs:
            print.open("eye_donors_by_districs.txt");
            while (getline(print, inp))
            {
                cout << inp << endl;
            }
            cout << "\n\t\t\t\t(1) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();
            switch(choice)
            {

                case '1': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto wahs;
            }

        }

}

void kidney_donors_by_districts()
{
    system("CLS");
    int flag =0, j , namelength, addresslength;
    char choice;
    ifstream print;
    ofstream write;
    string input, inp;
    cout << "\t\t\tEnter a district name to search a donor: ";
    cin >> input;
    transform(input.begin(), input.end(),input.begin(), ::tolower);

     write.open("kidney_donors_by_districs.txt");
    write << "\n\t\t\t<<< Kidney Donors From \""<< input <<"\" >>>\n\n";
    write << "\n\t\t\t<<< Eye Donors From \""<< input <<"\" >>>\n\n";
    write << "  \t\t\t __________________________________";
    write << "\n\t\t\t|ID|        Name        |";
    write << " District |\n\t\t\t|__|____________________";
    write << "|__________|\n";
    for (unsigned int i =0; i<donortype.size(); i++)
        {

            if (donortype[i].first == 10)
            {
                    if (input == donaddress[i+1])
                    {

                        flag = 1;
                        write <<"\t\t\t|";
                        write.width(2);
                        write << donortype[i].second;
                        write.fill(' ');
                        write <<"|";
                        write.width(20);
                        write << donname[i+1];
                        write.fill(' ');
                        write << "|" ;
                        write.width(10);
                        write <<donaddress[i+1];
                        write.fill(' ');
                        write << "|\n";
                        write << "\t\t\t|__|____________________|__________|\n";

                    }

            }

        }
        if (flag == 0)
        {
            system("CLS");
            write << "\n\n\t\t\t! No such donor belong to the district !";
            write.close();
            blooo:
            cout << "\n\n\t\tOops! There is no such registered donor from this district :(";
            cout << "\n\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
             choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto blooo;
            }

        }
        else
        {
            flag = 0;
            system("CLS");
            wahk:
            print.open("kidney_donors_by_districs.txt");
            while (getline(print, inp))
            {
                cout << inp << endl;
            }
            cout << "\n\t\t\t\t(1) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();
            switch(choice)
            {

                case '1': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto wahk;
            }

        }

}

void all_blood_donors()
{
    char choice;
    string inp;
    ifstream print;
    ofstream write;
    int j;

    write.open("blooddonors.txt");
    write << "\n\t\t\t<<< Full Lists of Blood Donors >>>\n\n";
    write << "  \t\t\t __________________________________";
    write << "\n\t\t\t|ID|        Name        |";
    write << " District |\n\t\t\t|__|____________________";
    write << "|__________|\n";

        for (unsigned int i =0; i<donortype.size(); i++)
        {


            if (donortype[i].first >= 1 && donortype[i].first <=8)
            {
                write <<"\t\t\t|";
                write.width(2);
                write << donortype[i].second;
                write.fill(' ');
                write <<"|";
                write.width(20);
                write << donname[i+1];
                write.fill(' ');
                write << "|" ;
                write.width(10);
                write <<donaddress[i+1];
                write.fill(' ');
                write << "|\n";
                write << "\t\t\t|__|____________________|__________|\n";
            }

        }
        write.close();
    system("CLS");
    waha:
    print.open("blooddonors.txt");
    while (getline(print, inp))
    {
        cout << inp << endl;
    }
    cout << "\n\t\t\t\t(1) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();
            switch(choice)
            {

                case '1': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto waha;
            }


}

void blood_donors_by_groups()
{
    int j=0;
    string inp;
    ifstream print;
    ofstream write;
    char choice;
    system("CLS");
    workin:
    cout << "\n\n\t\t\tEnter A Blood Group For Searching Donor  ";
    cout << "\n\t\t\t\t(1) A positive";
    cout << "\t\t(2) A negative\n";
    cout << "\n\t\t\t\t(3) AB positive";
    cout << "\t\t(4) AB negative\n";
    cout << "\n\t\t\t\t(5) B positive";
    cout << "\t\t(6) B negative\n";
    cout << "\n\t\t\t\t(7) O positive";
    cout << "\t\t(8) O negative\n\n";
    cout <<" \t\t\t\t  Enter your choice: ";
    choice = getch();
    if (choice > 48 && choice < 57)
    {

        for (unsigned int i =0; i<donortype.size(); i++)
            {

                if (donortype[i].first == (choice-48))
                {
                    if (j == 0)
                    {
                        write.open("blood_donors_by_groups.txt");
                        write << "\n\t\t\t<<< Lists of Blood Donors >>>\n\n";
                        write << "  \t\t\t __________________________________";
                        write << "\n\t\t\t|ID|        Name        |";
                        write << " District |\n\t\t\t|__|____________________";
                        write << "|__________|\n";
                        j = 1;
                    }

                    write <<"\t\t\t|";
                    write.width(2);
                    write << donortype[i].second;
                    write.fill(' ');
                    write <<"|";
                    write.width(20);
                    write << donname[i+1];
                    write.fill(' ');
                    write << "|" ;
                    write.width(10);
                    write <<donaddress[i+1];
                    write.fill(' ');
                    write << "|\n";
                    write << "\t\t\t|__|____________________|__________|\n";

                }

            }
            write.close();
            system("CLS");
            if (j == 1)
            {
                print.open("blood_donors_by_groups.txt");
                while (getline(print, inp))
                {
                    cout << inp << endl;
                }
            }

                wahaa:
                    if (j!= 1)
                    {
                        cout << "\n\n\t\t\tOops! No such donor of this blood group.";
                    }
                cout << "\n\n\t\t\t\t(1) Donor Finding Menu";
                cout << "\n\t\t\tEnter your choice: ";
                choice = getch();
                switch(choice)
                {

                    case '1': Donor_finder();
                    break;

                    default: system("CLS");
                    cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                    goto wahaa;
                }


    }

    else
    {
        system("CLS");
        cout << "\n\n\t\t\tENTER A VALID INPUT";
        goto workin;
    }

}

void all_eye_donors()
{
    char choice;
    string inp;
    ifstream print;
    ofstream write;
    int namelength,j,addresslength;

    write.open("eyedonors.txt");
    write << "\n\t\t\t<<< Full Lists of Eye Donors >>>\n\n";
    write << "  \t\t\t __________________________________";
        write << "\n\t\t\t|ID|        Name        |";
        write << " District |\n\t\t\t|__|____________________";
        write << "|__________|\n";

        for (unsigned int i =0; i<donortype.size(); i++)
        {


            if (donortype[i].first == 9)
            {
                write <<"\t\t\t|";
                write.width(2);
                write << donortype[i].second;
                write.fill(' ');
                write <<"|";
                write.width(20);
                write << donname[i+1];
                write.fill(' ');
                write << "|" ;
                write.width(10);
                write <<donaddress[i+1];
                write.fill(' ');
                write << "|\n";
                write << "\t\t\t|__|____________________|__________|\n";
            }

        }
        write.close();
    system("CLS");
    wahaa:
    print.open("eyedonors.txt");
    while (getline(print, inp))
    {
        cout << inp << endl;
    }
    cout << "\n\t\t\t\t(1) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();
            switch(choice)
            {

                case '1': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto wahaa;
            }


}

void all_kidney_donors()
{
    char choice;
    system("CLS");
    string inp;
    ifstream print;
    ofstream write;
    int namelength, addresslength, j;
    write.open("kidneydonors.txt");
    write << "\n\t\t\t<<< Full Lists of Kidney Donors >>>\n\n";
    write << "\n\n\t\t\t\tBlood Donors: \n";
    write << "  \t\t\t __________________________________";
    write << "\n\t\t\t|ID|        Name        |";
    write << " District |\n\t\t\t|__|____________________";
    write << "|__________|\n";

    for (unsigned int i =0; i<donortype.size(); i++)
        {
            if (donortype[i].first == 10)
            {
                write <<"\t\t\t|";
                write.width(2);
                write << donortype[i].second;
                write.fill(' ');
                write <<"|";
                write.width(20);
                write << donname[i+1];
                write.fill(' ');
                write << "|" ;
                write.width(10);
                write <<donaddress[i+1];
                write.fill(' ');
                write << "|\n";
                write << "\t\t\t|__|____________________|__________|\n";

            }

        }
    write.close();
    system("CLS");
    wahaa:
    print.open("kidneydonors.txt");
    while (getline(print, inp))
    {
        cout << inp << endl;
    }
    cout << "\n\t\t\t\t(1) Donor Finding Menu";
            cout << "\n\t\t\tEnter your choice: ";
            choice = getch();
            switch(choice)
            {

                case '1': Donor_finder();
                break;

                default: system("CLS");
                cout << "\n\n\n\t\t\t\tENTER A VALID INPUT";
                goto wahaa;
            }


}
    void view_a_blood_donor()
    {
        string str ,inp;
        ifstream print;
        ofstream write;
        char choice;

        int flag =0 , id;
        system("CLS");
        cout << "\n\n\t\tEnter a donor ID to see the full information of the donor\n";
        cout << "\n\n\t\tEnter donor ID: ";
        cin >> id;
        for (unsigned int i =0; i<donortype.size(); i++)
        {
            if ((donortype[i].second == id)&&donortype[i].first >=1 && donortype[i].first <= 8)
            {
               flag =1;

            }

        }

        if (flag == 1)
        {

            flag = 0;
            str = donname[id] + ".txt";
             write.open(str.c_str());
             write << "\n\n\nName: " << donname[id];
             write << "\n\t\t\tAge: " << donage[id];
             write << "\n\t\t\tWeight: " << donweight[id];
             write << "\n\t\t\tProfession: " << donprof[id];
             write << "\n\t\t\tDistrict: " << donaddress[id];
             write << "\n\t\t\tContact: " << donphone[id];
             write.close();

             system("CLS");
            print.open(str.c_str());
            while (getline(print, inp))
            {
                cout << inp << endl;
            }
            confy:
            cout << "\n\n\n\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\n\t\t\tEnter Your Choice: ";
            choice = getch();
            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default:
                system("CLS");
                cout << "\n\t\t\tENTER A VALID INPUT !";
                goto confy;

            }
        }

        else
        {
            system("CLS");
            conf:
            cout << "\n\n\n\t\t\tsorry! This donor ID belongs to a donor\n\t\t\twho is not a blood donor :(\n\n";
            cout << "\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\n\t\t\tEnter Your Choice: ";
            choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default:
                system("CLS");
                cout << "\n\t\t\tENTER A VALID INPUT !";
                goto conf;

            }
        }
    }

    void view_a_eye_donor()
    {
        string str ,inp;
        ifstream print;
        ofstream write;
        char choice;
        int flag =0 , id;
        system("CLS");
        cout << "\n\n\t\tEnter a donor ID to see the full information of the donor\n";
        cout << "\n\n\t\tEnter donor ID: ";
        cin >> id;
        for (unsigned int i =0; i<donortype.size(); i++)
        {
            if ((donortype[i].second == id)&&donortype[i].first == 9)
            {
               flag =1;

            }

        }

        if (flag == 1)
        {

            flag = 0;
            str = donname[id] + ".txt";
             write.open(str.c_str());
             write << "\n\n\n\t\t\tName: " << donname[id];
             write << "\n\t\t\tAge: " << donage[id];
             write << "\n\t\t\tWeight: " << donweight[id];
             write << "\n\t\t\tProfession: " << donprof[id];
             write << "\n\t\t\tDistrict: " << donaddress[id];
             write << "\n\t\t\tContact: " << donphone[id];
             write.close();

             system("CLS");
            print.open(str.c_str());
            while (getline(print, inp))
            {
                cout << inp << endl;
            }
            confy:
            cout << "\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\n\t\t\tEnter Your Choice: ";
            choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default:
                system("CLS");
                cout << "\n\t\t\tENTER A VALID INPUT !";
                goto confy;

            }
        }

        else
        {
            system("CLS");
            conf:
            cout << "\n\n\n\t\t\tsorry! This donor ID belongs to a donor\n\t\t\twho is not a eye donor :(\n\n";
            cout << "\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\n\t\t\tEnter Your Choice: ";
            choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default:
                system("CLS");
                cout << "\n\t\t\tENTER A VALID INPUT !";
                goto conf;

            }
        }
    }

    void view_a_kidney_donor()
    {

        string str ,inp;
        ifstream print;
        ofstream write;
        char choice;
        int flag =0 , id;
        system("CLS");
        cout << "\n\n\t\tEnter a donor ID to see the full information of the donor\n";
        cout << "\n\n\t\tEnter donor ID: ";
        cin >> id;
        for (unsigned int i =0; i<donortype.size(); i++)
        {
            if ((donortype[i].second == id)&&donortype[i].first == 10)
            {
               flag =1;

            }

        }

        if (flag == 1)
        {

            flag = 0;
            str = donname[id] + ".txt";
             write.open(str.c_str());
             write << "\n\n\n\t\t\tName: " << donname[id];
             write << "\n\t\t\tAge: " << donage[id];
             write << "\n\t\t\tWeight: " << donweight[id];
             write << "\n\t\t\tProfession: " << donprof[id];
             write << "\n\t\t\tDistrict: " << donaddress[id];
             write << "\n\t\t\tContact: " << donphone[id];
             write.close();

             system("CLS");
            print.open(str.c_str());
            while (getline(print, inp))
            {
                cout << inp << endl;
            }
            confy:
            cout << "\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\n\t\t\tEnter Your Choice: ";
            choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default:
                system("CLS");
                cout << "\n\t\t\tENTER A VALID INPUT !";
                goto confy;

            }
        }

        else
        {
            system("CLS");
            conf:
            cout << "\n\n\n\t\t\tsorry! This donor ID belongs to a donor\n\t\t\twho is not a kidney donor :(\n\n";
            cout << "\t\t\t\t(1) Main Menu";
            cout << "\n\t\t\t\t(2) Donor Finding Menu";
            cout << "\n\n\t\t\tEnter Your Choice: ";
            choice = getch();

            switch(choice)
            {
                case '1': welcome_page();
                break;

                case '2': Donor_finder();
                break;

                default:
                system("CLS");
                cout << "\n\t\t\tENTER A VALID INPUT !";
                goto conf;

            }
        }
    }

int main ()
{
    main_page();
    return 0;
}



