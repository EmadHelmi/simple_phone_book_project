#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
using namespace std;

class Contact
{
    public:
        string f_name;
        string l_name;
        string home_number;
        string mobile_number;
        string group;
};
//Global Parameters
string file_name = "contacts.txt";
string file_path = "."; // . means the current directory
vector<Contact> contacts;

//Function Headers
int add_item();
int del_item();
int src_item();
int shw_group();

int read_file(string, string);
int write_file(string, string);

int main()
{
    read_file(file_name, file_path);
    
    cout << "########## WELCOME TO THE PHONE BOOK PROJECT ##########" << endl;
    cout << endl ;

    int choice;
    while(true)
    {
        cout << endl;
        cout << "Pleas choose one of the following actions:" << endl;
        cout << "1. Add contact(s) to the phone book" << endl;
        cout << "2. Delete a contact from the phone book" << endl;
        cout << "3. Search for a phone number in the phone book" << endl;
        cout << "4. Show an specific group of contacts in the phone book" << endl;
        cout << "5. exit from the phone book" << endl;
        cout << "Please choose an option [1-5]: " ;
        cin >> choice;

        if(choice == 1)
        {
            add_item();
            write_file(file_name, file_path);
        }
        else if(choice == 2)
        {
            del_item();
            write_file(file_name, file_path);
        }
        else if(choice == 3)
        {
            int fail = src_item();
        }
        else if(choice == 4)
        {
            shw_group();
        }
        else if(choice == 5)
        {
            system("CLS");
            break;
        }
        else
        {
            cout << "SORRY! YOU CHOOSE A WRONG OPTION :(";
            system("CLS");
            continue;
        }
    }
}

int read_file(string in_file, string in_path)
{
    ifstream infile(in_file.c_str());
    string fname, lname, hnumber, mnumber, grp;
    int line_number = 1;
    while(infile >> fname >> lname >> hnumber >> mnumber >> grp)
    {   
        if( line_number == 1 || line_number == 2)
        {
            line_number ++;
            continue;
        }
        // cout << fname << "\t" << lname << "\t" << hnumber << "\t" << mnumber << "\t" << grp << "\t" << endl;
        Contact temp;
        
        temp.f_name = fname;
        temp.l_name = lname;
        temp.home_number = hnumber;
        temp.mobile_number = mnumber;
        temp.group = grp;

        contacts.push_back(temp);

        line_number ++;
    }

    return 0;
}

int write_file(string out_file, string out_path)
{
    ofstream outfile(out_file.c_str());
    
    outfile << "FirstName       LastName        PhoneNum        MobileNum       Group" << endl ;
    outfile << "=========       ========        ========        =========       =====" << endl ;

    for (int i = 0; i < contacts.size(); i++)
    {
        int sp = 16;
        int ln, rm;
        outfile << contacts[i].f_name ;
        
        ln = contacts[i].f_name.length();
        rm = sp - ln;
        for(int j = 0; j < rm; j++)
        {
            outfile << " " ;
        }
        outfile << contacts[i].l_name ;

        ln = contacts[i].l_name.length();
        rm = sp - ln;
        for(int j = 0; j < rm; j++)
        {
            outfile << " " ;
        } 
        outfile << contacts[i].home_number ;

        ln = contacts[i].home_number.length();
        rm = sp - ln;
        for(int j = 0; j < rm; j++)
        {
            outfile << " " ;
        }
        outfile << contacts[i].mobile_number ;

        ln = contacts[i].mobile_number.length();
        rm = sp - ln;
        for(int j = 0; j < rm; j++)
        {
            outfile << " " ;
        }
        outfile << contacts[i].group << endl;

    }
}

int add_item()
{
    system("CLS");
    int number ;
    cout << "How many contacts do you want to add? ";
    cin >> number;
    for (int i = 0; i < number; i++)
    {
        cout << "########## NOTE ##########" << endl;
        
        cout << "IF YOU WANT TO LEAVE BLANK A FIELD PLEASE TYPE '-' SIGN !" << endl;
        cout << "FIRST NAME AND LAST NAME MUST BE TYPED YOU CANNOT LEAVE THEM EMPTY !" << endl;
        cout << "PHONE NUMBER AND MOBILE NUMBER CANNOT BE EMPTY TOGETHER ONE OF THEM (AT LEAST) MUST BE TYPED !" << endl ;
        cout << "GROUP NAME MUST BE TYPED AND MUST BE ONE OF THE FOLLOWING CHOICES: ";
        cout << "family, " << "friend, " << "collegue !" << endl; 

        cout << "##########################" << endl;
        cout << endl << endl ;


        cout << "Please fill below for details of contact number " << i + 1 << ":" << endl;
        
        string fname;
        cout << "First Name: ";
        cin >> fname;

        while(fname == "-")
        {
            cout << "YOU CANNOT LEAVE THE FIRST NAME EMPTY :( !" << endl;
            cout << "First Name: ";
            cin >> fname;
        }

        string lname;
        cout << "Last Name: ";
        cin >> lname;

        while(lname == "-")
        {
            cout << "YOU CANNOT LEAVE THE LAST NAME EMPTY :( !" << endl;
            cout << "Last Name: ";
            cin >> lname;
        }

        string hnumber;
        cout << "Phone Number: ";
        cin >> hnumber;

        string mnumber;
        cout << "Mobile Number: ";
        cin >> mnumber;

        while(hnumber == "-" && mnumber == "-")
        {
            cout << "YOU CANNOT LEAVE BOTH PHONE AND MOBILE NUMBER EMPTY :( !" << endl;
            
            cout << "Phone Number: ";
            cin >> hnumber;

            cout << "Mobile Number: ";
            cin >> mnumber;
        }
        
        string grp;
        bool fail = true;
        while(fail)
        {
            cout << "Group Name: ";
            cin >> grp;
            
            if (grp == "-")
            {
                cout << "YOU CANNOT LEAVE THE GROUP NAME EMPTY :( !" << endl;
                continue;
            }
            else if (grp != "family" && grp != "collegue" && grp != "friend")
            {
                cout << "YOUR GROUP NAME CHOICE IS NOT IN THE POSSIBLE CHOICES PLEAS READ THE NOTES AGAIN :)" << endl;
                continue;
            }

            fail = false;
        }

        Contact temp;
        
        temp.f_name = fname;
        temp.l_name = lname;
        temp.home_number = hnumber;
        temp.mobile_number = mnumber;
        temp.group = grp;

        contacts.push_back(temp);       
        cout << "####################" << endl;
    }
}

int del_item()
{
    system("CLS");
    cout << "########## NOTE ##########" << endl;
    
    cout << "YOU CAN JUST DELETE A CONTACT BY PHONE OR MOBILE NUMBER !" << endl;
    
    cout << "##########################" << endl;
    cout << endl << endl ;

    string delnum;
    cout << "Please enter the number of the contact you want to delete: ";
    cin >> delnum;

    bool found = false;
    cout << "FirstName       LastName        PhoneNum        MobileNum       Group" << endl ;
    cout << "=========       ========        ========        =========       =====" << endl ;
    for (int i = 0; i < contacts.size(); i++)
    {
        if(delnum == contacts[i].home_number || delnum == contacts[i].mobile_number)
        {
            found = true;

            int sp = 16;
            int ln, rm;

            cout << contacts[i].f_name ;
            ln = contacts[i].f_name.length();
            rm = sp - ln;
            for(int j = 0; j < rm; j++)
            {
                cout << " " ;
            }

            cout << contacts[i].l_name ;
            ln = contacts[i].l_name.length();
            rm = sp - ln;
            for(int j = 0; j < rm; j++)
            {
                cout << " " ;
            }

            cout << contacts[i].home_number ;
            ln = contacts[i].home_number.length();
            rm = sp - ln;
            for(int j = 0; j < rm; j++)
            {
                cout << " " ;
            }

            cout << contacts[i].mobile_number;
            ln = contacts[i].mobile_number.length();
            rm = sp - ln;
            for(int j = 0; j < rm; j++)
            {
                cout << " " ;
            }

            cout << contacts[i].group << endl;

            string sure;
            cout << "Are you sure want to delete this contact?? [y / n]: ";
            cin >> sure;

            while(sure != "n" && sure != "y")
            {
                cout << "Are you sure want to delete this contact?? [y / n]: ";
                cin >> sure;
            }

            if(sure == "y")
            {
                contacts.erase(contacts.begin() + i);
                cout << "Contact deleted successfully :)!" << endl;
                return 0;
            }
            else
            {
                cout << "Contact does not delete :) !" << endl;
            }
        }
        if(!found)
        {
            cout << "There is no contact with this number :(" << endl;
            return 1;
        }
    }

    if(!found)
    {
        cout << "There is no contact with that number !" << endl;
    }
    
    return 0;
}

int src_item()
{
    system("CLS");
    cout << "########## NOTE ##########" << endl;
    cout << "YOU JUST CAN SEARCH BASED ON FIRST NAME OR LAST NAME";
    cout << "##########################" << endl;

    int choice;
    cout << "Choose based on what feature do you want to search:" << endl;
    cout << "1. Based on first name" << endl ;
    cout << "2. Based on last name" << endl ;
    cout << "Please enter 1 or 2: ";
    cin >> choice;

    if(choice == 1)
    {
        string fname;
        cout << "Please enter the first name you want to search: ";
        cin >> fname;
        cout << "FirstName       LastName        PhoneNum        MobileNum       Group" << endl ;
        cout << "=========       ========        ========        =========       =====" << endl ;
        for (int i = 0; i < contacts.size(); i++)
        {
            if(contacts[i].f_name == fname)
            {
                int sp = 16;
                int ln, rm;

                cout << contacts[i].f_name ;
                ln = contacts[i].f_name.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].l_name ;
                ln = contacts[i].l_name.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].home_number ;
                ln = contacts[i].home_number.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].mobile_number;
                ln = contacts[i].mobile_number.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].group << endl;
            }
        }
    }
    else if(choice == 2)
    {
        string lname;
        cout << "Please enter the last name you want to search: ";
        cin >> lname;
        cout << "FirstName       LastName        PhoneNum        MobileNum       Group" << endl ;
        cout << "=========       ========        ========        =========       =====" << endl ;
        for (int i = 0; i < contacts.size(); i++)
        {
            if(contacts[i].l_name == lname)
            {
                int sp = 16;
                int ln, rm;

                cout << contacts[i].f_name ;
                ln = contacts[i].f_name.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].l_name ;
                ln = contacts[i].l_name.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].home_number ;
                ln = contacts[i].home_number.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].mobile_number;
                ln = contacts[i].mobile_number.length();
                rm = sp - ln;
                for(int j = 0; j < rm; j++)
                {
                    cout << " " ;
                }

                cout << contacts[i].group << endl;
            }
        }
    }
    else
    {
        cout << "Sorry you choose a wrong option please try again :(" << endl;
        return 1;
    }

    return 0;
}

int shw_group()
{
    system("CLS");
    string grpname;
    cout << "Pleas enter the group name: ";
    cin >> grpname;

    while(grpname != "family" && grpname != "collegue" && grpname != "friend")
    {
        cout << "YOUR GROUP NAME CHOICE IS NOT IN THE POSSIBLE CHOICES PLEAS READ THE NOTES AGAIN :)" << endl;
        cin >> grpname;
    }
    cout << "FirstName       LastName        PhoneNum        MobileNum" << endl ;
    cout << "=========       ========        ========        =========" << endl ;
    for (int i = 0; i < contacts.size(); i++)
    {
        if(contacts[i].group == grpname)
        {            
            int sp = 16;
            int ln, rm;

            cout << contacts[i].f_name ;
            ln = contacts[i].f_name.length();
            rm = sp - ln;
            for(int j = 0; j < rm; j++)
            {
                cout << " " ;
            }

            cout << contacts[i].l_name ;
            ln = contacts[i].l_name.length();
            rm = sp - ln;
            for(int j = 0; j < rm; j++)
            {
                cout << " " ;
            }

            cout << contacts[i].home_number ;
            ln = contacts[i].home_number.length();
            rm = sp - ln;
            for(int j = 0; j < rm; j++)
            {
                cout << " " ;
            }

            cout << contacts[i].mobile_number << endl ;
        }
    }

    return 0;
}