#include <iostream>
#include <math.h>
#include <string>
#include <fstream>
#include <stdlib.h>
#include <locale.h>
#include <bits/stdc++.h>
#include <unistd.h>
using namespace std;

class Functions
{
    private:
    string up,pwd,mail;
    int ay,wcp;

public:


    void main1()
    {
        system("clear");
        int opts;
        cout<<"\n\n\t\t\t\t▬▬▬▬▬▬▬▬▬▬▬▬▬\n\t\t\t\t    \e[1mך∑ʄ∆∩\e[0m   \n\t\t\t\t▬▬▬▬▬▬▬▬▬▬▬▬▬\n\n";
        cout<<"\n\tHey \033[32mAnon\033[0m, Welcome to Linear Equations and Function Analysis!\n\tA coordinate geometry Calculator and Function Analyzer.\n\n";
        cout<<"\t   \033[36m[1] Sign in\n\t   [2] Sign up\n\t   [3] Forgot Password?\n\t   [4] Continue as \033[32mAnon\033[36m (calculation history will not be saved)\n\t   [5] Docs\033[0m\n\n";
        cout<<"\tEnter the \e[1mnumber \e[0mbefore the options to operate the program: ";
        cin>>opts;

        if (opts == 1)
        {
            ay=0;
            system("clear");
            in();
        }

        if (opts == 2)
        {
            system("clear");
            reg();
        }
        if (opts == 3)
        {
            system("clear");
            lpass();
        }
        if (opts == 4)
        {
            ay=1;
            system("clear");
            anonmenu();
        }

        if (opts == 5)
        {
            system("clear");
            docs();
        }


    }

    void reg()
    {
        string uname, pword,email,u;
        cout<<endl<<"\033[34m\t\e[1mNew User Registration\033[0m\e[0m"<<endl<<endl;
        cout<<"\t | Username: ";
        cin>>uname;

        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        cout<<endl;
        cout<<endl<<"\t\033[0mPlease wait while checking if "<<uname<<" already exits...\033[0m"<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));
        if (u == uname) {
            cout<<endl<<"\033[31m\tUser already exists!!\033[0m"<<endl<<"\tChoose another name"<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(1100));
            system("clear");
            reg();}
        else{
        cout<<endl<<"\033[32m\tUser name Avaialbe!!\033[0m"<<endl<<endl;
        up = uname;
        cout<<"\t | Password: ";
        cin>>pword;
        pwd = pword;
        cout<<"\t | Email (optional for resetting password) : ";
        cin>>email;
        mail = email;
        ofstream file;
        file.open("Users/"+uname+".txt");
        file << uname <<endl << pword<<endl <<email;
        file.close();
        //up = uname;
        cout<<endl<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));
        cout<<"\t\033[32mAccount Created! Signing in...\033[0m"<<endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout<<endl;
        system("clear");
        umenu();}
    }

    void cname () {

    string uname,chname, np, u, p,email,e;
    np = pwd; email = mail;uname=up;
        cout<<endl<<"\033[31m\t\e[1mChange Username:\033[0m\e[0m"<<endl<<endl;
        cout<<"\tEnter your Desired Username to begin changing username"<<endl;
        cout<<"\t | Username: "; cin>>chname;
        ifstream read("Users/"+chname+".txt");
        getline(read, u);
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));
        cout<<endl<<"\t\033[0mPlease wait while checking if "<<chname<<" exits...\033[0m"<<endl;
        if (u == chname) {
            cout<<endl<<"\033[31m\tUser already exists!!\033[0m"<<endl<<"\tUsername could not be changed."<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            cname();

            }
            else{
            cout<<endl<<"\033[32m\tUsername Changed!!\033[0m"<<endl;
            up = chname;
                ofstream file;
                filesystem::remove("Users/"+uname+".txt");
                file.open("Users/"+chname+".txt");
                file << chname <<endl << np<<endl <<email;
                file.close();
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("clear");
                umenu();


            }
        }


    void cpass(){
        string uname, np, u, p,email,e;
        cout<<endl<<"\033[31m\t\e[1mChange Password\033[0m\e[0m"<<endl<<endl;
        uname = up;
        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        getline(read,p);
        getline(read,e);
            cout<<endl<<"\tHello,"<<uname<<endl<<"\tEnter email provided while signing up: "; cin>>email;
            cout<<endl<<"\t\033[0mPlease wait while your email is being verified...\033[0m"<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            if (e == email){
                ofstream file;
                cout<<endl<<"\033[32m\tEmail Matched!\033[0m"<<endl;
                cout<<"\t | New Password: "; cin>>np;
                file.open("Users/"+uname+".txt");
                file << uname <<endl << np<<endl <<email;
                file.close();
                cout<<endl<<"\033[32m\tPassword Change done, Redirecting to Menu Page...\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("clear");
                umenu();

            }
            else{
                cout<<endl<<"\033[31m\tInvalid Email!!\033[0m"<<endl<<"\tPassword could not be Changed."<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            main1();
            }
    }


    void lpass(){
        string uname, np, u, p,email,e;
        cout<<endl<<"\033[31m\t\e[1mPassword Reset:\033[0m\e[0m"<<endl<<endl;
        cout<<"\tEnter your Username to search for account and then reset it"<<endl;
        cout<<"\t | Username: "; cin>>uname;
        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        getline(read,p);
        getline(read,e);
        cout<<endl;
        this_thread::sleep_for(chrono::milliseconds(600));
        cout<<endl<<"\t\033[0mPlease wait while your account is being found...\033[0m"<<endl;
        if (u == uname) {
            cout<<endl<<"\033[32m\tAccount Found!\033[0m"<<endl;
            cout<<endl<<"\tHello,"<<uname<<endl<<"\tEnter the email provided while signing up: "; cin>>email;
            cout<<endl<<"\t\033[0mPlease wait while your email is being verified...\033[0m"<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
            if (e == email){
                ofstream file;
                cout<<endl<<"\033[32m\tEmail Matched!\033[0m"<<endl;
                cout<<"\t | New Password: "; cin>>np;
                file.open("Users/"+uname+".txt");
                file << uname <<endl << np<<endl <<email;
                file.close();
                cout<<endl<<"\033[32m\tPassword reset done, Redirecting to Login Page...\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(1000));
                system("clear");
                in();

            }
            else{
                cout<<endl<<"\033[31m\tInvalid Email!!\033[0m"<<endl<<"\tPassword could not be resetted."<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            main1();
            }
        }
        else {
            cout<<endl<<"\033[31m\tInvalid Username!!\033[0m"<<endl<<"\tPassword could not be resetted."<<endl<<endl;
            this_thread::sleep_for(chrono::milliseconds(1020));
            system("clear");
            main1();
        }
    }
    void in()
    {
        int opr;
        ofstream file;
        ofstream hfile;
        string uname, pword, u, p,e;
        cout<<endl<<"\033[32m\t\e[1mExisting User Login\033[0m\e[0m"<<endl<<endl;
        cout<<"\t | Username: ";
        cin>>uname;
        cout<<"\t | Password: ";
        cin>>pword;
        ifstream read("Users/"+uname+".txt");
        getline(read, u);
        getline(read, p);
        getline(read, e);

        if (u == uname && p == pword)
        {
            ifstream read("Users/"+uname+".txt");
            getline(read, u);
            up = u;
            pwd = pword;
            mail = e;
            file.open("History/"+uname+".txt");
            file << uname<<" Logged In"<<endl;
            file.close();
            hfile.open("History/"+uname+"_calculations.txt");
            hfile <<"[IN] "<<uname<<" Logged In"<<endl;
            hfile.close();
            system("clear");
            umenu();
        }
        else {
                cout<<endl;
            this_thread::sleep_for(chrono::milliseconds(600));
        cout<<"\t\033[31mIncorrect Information\033[0m"<<endl;
        int lch;
        cout<<"[1] Reset Password\t[2] Try Again\t[3]Sign Up\t[4]Anon: ";cin>>lch;
        if (lch == 1){
            system("clear");
            lpass();
        }
        if(lch == 2) {
            system("clear");
            in();
        }
        if(lch == 3) {
            system("clear");
            reg();
        }
        if(lch == 4) {
            system("clear");
            anonmenu();
        }

        }

    }

    void dis_1()
    {

        double a,b,c,d,dis=0,ab,cd;
        system("clear");
        cout<<endl<<"\033[35m\t\e[1mDistance between two Points:\033[0m\e[0m\n"<<endl<<endl;
        cout<<"\t | Enter coordinates of first point (x1 , y1) : ";
        cin>>a>>b;
        cout<<"\t | Enter coordinates of first point (x2, y2) : ";
        cin>>c>>d;
        ab = (a-c)*(a-c);
        cd = (b-d)*(b-d);
        dis = sqrt(ab+cd);
        cout<<endl<<std::noshowpos<<" \033[35m\t\e[1m |\033[0m\e[0m Distance between ("<<a<<","<<b<<") and ("<<b<<","<<d<<") is: "<<dis<<endl<<endl;
        int uh = ay;

            string uname;
            uname = up;
            if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F1] "<<"Inputs: ("<<a<<","<<b<<") -- Output: "<<dis<<endl;}
        else{

        }


        int choose,any;
        any = ay;
        cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";
        cin>>choose;
        if (choose == 1)
        {
            dis_1();
        }
        if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
        if (choose == 0)
        {
            system("clear");
            main1();
        }


    }

    void pol() {
        system("clear");
        double rx, x,y,r,theta;
        system("clear");
        cout<<endl<<"\033[35m\t\e[1mCartesian to Polar Conversion:\033[0m\e[0m\n"<<endl<<endl;
        cout<<"\t| Enter Coordinate (x1,y1): "; cin>>x>>y;
        rx = (x*x)+(y*y);
        r = sqrt(rx);
        theta = (atan(y/x))*57.29577;
        cout<<endl<<" \033[35m\t\e[1m|\033[0m\e[0m Polar Coordinates (r,theta) : ("<<r<<","<<theta<<")"<<endl;
        cout<<endl;

        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F2] "<<"Inputs: ("<<x<<","<<y<<") -- Output: ("<<r<<","<<theta<<")"<<endl;}else{}

        int choose,any;
        any = ay;
        cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";
        cin>>choose;
        if (choose == 1)
        {
            pol();
        }
        if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
        if (choose == 0)
        {
            system("clear");
            main1();
        }
    }

    void diff() {
        system("clear");
        double ara[1000],pww[1000];
    int i,t,mp,j,dp,k;
    char ch;
    cout<<endl<<"\033[35m\t\e[1mDifferentiate a Function:\033[0m\e[0m\n"<<endl<<endl<<"\tA function follows: y = ax^n+bx^(n-1)+cx^(n-2)+...+yx+z"<<endl<<"\tWhere a,b,c....z are some constant values and n is the max power"<<endl;
    cout<<endl<<"\t| Enter Max Power of x: "; cin>>mp;
    t= mp+1;
    dp=mp-1;
    cout<<endl<<"\t| Enter "<<"\e[1m"<<t<<"\e[0m"<<" Constant values:"<<endl;
    for (i =1, ch ='a';i<=t && ch <='z';i++, ch++){
        if (ch >= 'z') {
                ch = 'A';
        if (ch >= 'Z') {
                ch = 'a';
        if (ch >= 'z') ch = 'A';
        }
        }
        cout<<"\t "<<ch<<" : "; cin>>ara[i];
        pww[i]=i;
    }
    cout<<endl<<"\tPlease wait...";
    cout<<endl<<endl;
    this_thread::sleep_for(chrono::milliseconds(600));
    if (mp>1){cout<<"\t\033[32mDifferentiation done!\033[0m"<<endl<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m \033[35m\e[1mdy/dx\e[0m\033[0m = ";
    for (i= 1,j=dp,k=mp; i<=mp && j>=1 && k>=1;i++,j--,k--){
        cout<<std::showpos<<pww[k]*ara[i]<<"x";
        if (j> 1) cout<<"^"<<std::noshowpos<<pww[j];
        if (j == 1) cout<<std::showpos<<ara[i+1]<<std::noshowpos;
        if(pww[j]==1) break;
    }
    cout<<endl<<endl;}
    if (mp==0){
        cout<<endl<<endl;
    this_thread::sleep_for(chrono::milliseconds(600));
    cout<<"\t\033[32mDifferentiation done!\033[0m"<<endl<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m \033[35m\e[1mdy/dx\e[0m\033[0m = 0";
    }

    if (mp==1){
        cout<<endl<<endl;
    this_thread::sleep_for(chrono::milliseconds(600));
    cout<<"\t\033[32mDifferentiation done!\033[0m"<<endl<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m \033[35m\e[1mdy/dx\e[0m\033[0m = "<<ara[1];
    }

cout<<endl<<endl;
    int choose,any;
    any=ay;
        cout<<std::noshowpos<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";
        cin>>choose;
        if (choose == 1)
        {
            diff();
        }
        if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
        if (choose == 0)
        {
            system("clear");
            main1();
        }


    }

    void dis_2() {
        system("clear");
        double x ,y ,s1=0,s2=0,s3=0,dis;
    cout<<endl<<"\033[35m\t\e[1mDistance of a Point from Origin:\033[0m\e[0m\n"<<endl<<endl;
    cout<<"\tEnter the X and Y coordinates : ";
    cin>>x>>y;
    s1 = x*x;
    s2 = y*y;
    s3 = s1 + s2;
    dis = sqrt(s3);
   cout<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m Distance of ("<<x<<","<<y<<") from O(0,0) : "<<dis<<" units."<<endl<<endl;


            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F6] "<<"Inputs: ("<<x<<","<<y<<") -- Output: "<<dis<<endl;}
            else{}

   cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";
    int choose,any;any=ay;
    cin>>choose;

    if (choose == 1) {
        dis_2();
    }
    if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
    if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
    if (choose == 0) {
        system("clear");
        main1();
    }

    }

    void slopeq(){
        system("clear");
    double slope = 0, a,b,c,angle;
	cout<<endl<<"\033[35m\t\e[1mQuadrant of a Point:\033[0m\e[0m\n"<<endl<<endl;
	cout<<"\t> Readme\n";
	cout<<"\tThe equation of a straight line should be following:\n\t* ax+by+c=0 \n\t* the operator signs depend on the constant values.\n";
	cout<<"\tAs Example: if it is 12x+13y+23=0, then a = 12, b = 13, c = 23\n \tand if it is 12x-13y-23 =0, then a = 12, b = -13, c = -23.\n";
	cout<<"\n";
	cout<<"\t | Enter the values of a b and c::\n";
	cout<<"\t   a: ";
	cin>>a;
	cout<<"\t   b: ";
    cin>>b;
	cout<<"\t   c: ";
    cin>>c;
	cout<<"\n";
	slope = -b/a;
    cout<<"\033[35m\t\e[1m|\033[0m\e[0m Slope of the St. line is : " <<std::noshowpos<<slope<<endl<<endl;
    if (slope < 0 ) {
            angle=90 + ((-1)*(atan(slope)*57.29577));
            cout<<"\033[35m\t\e[1m>\033[0m\e[0m It makes "<<angle<<" degree with respect to X axis"<<endl<<endl;

            cout<<"       .\t\t|"<<endl<<"          .\t\t|"<<endl<<"             .\t\t|"<<endl<<"                .\t|"<<endl<<"                   .\t|  ("<<angle<<")"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|."<<endl<<"\t\t\t|   ."<<endl<<"\t\t\t|      ."<<endl<<"\t\t\t|         ."<<endl<<"\t\t\t|            ."<<endl;

    }
    if (slope > 0 ) {
            angle=90 + ((-1)*(atan(slope)*57.29577));
            cout<<"\033[35m\t\e[1m>\033[0m\e[0m It makes "<<angle<<" degree with respect to X axis"<<endl<<endl;
            cout<<"\t\t\t|               ."<<endl<<"\t\t\t|            ."<<endl<<"\t\t\t|         ."<<endl<<"\t\t\t|      ."<<endl<<"\t\t\t|   .\t("<<angle<<")"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t               .|"<<endl<<"\t            .\t|"<<endl<<"\t         .\t|"<<endl<<"\t      .\t\t|"<<endl<<"\t   .\t\t|"<<endl;
    }

        string uname;
            int uh = ay;if(uh==0){uname = up;
            ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F9] "<<"Inputs: ("<<a<<","<<b<<","<<c<<") -- Output: ("<<slope<<","<<angle<<")"<<endl;} else{}

    int choose,any;
    any=ay;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		slopeq();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}


}

void qua()
{
    system("clear");
     cout<<endl<<"\033[35m\t\e[1mQuadrant of a Point:\033[0m\e[0m\n"<<endl<<endl;

   double a,b,x,y;
   cout<<"\t| Enter two coordinates (X,Y): ";cin>>a>>b;
   x=a;
   y=b;
   cout<<endl;
   if(a > 0.00 && b > 0.00){
        cout<<"\033[35m\t\e[1m|\033[0m\e[0m Point ("<<a<<","<<b<<") lies in the 1st Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 1st Quadrant)"<<endl;} else{}

   }
   else if(a < 0.00 && b > 0.00) {
        cout<<"\033[35m\t\e[1m|\033[0m\e[0m Point ("<<a<<","<<b<<") lies in the 2nd Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<")\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 2nd Quadrant)"<<endl;}else{}
   }
   else if(a < 0.00 && b < 0.00){
      cout<<"\033[35m\t\e[1m|\033[0m\e[0m Point ("<<a<<","<<b<<")lies in the 3rd Quadrant.\n"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<")\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 3rd Quadrant)"<<endl;}else{}
   }
   else if(a > 0.00 && b < 0.00){
            cout<<"\033[35m\t\e[1m|\033[0m\e[0m Point ("<<a<<","<<b<<")lies in the 4th Quadrant.\n"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t----------------------------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in 4th Quadrant)"<<endl;}else{}
   }

   else{
      cout<<"\033[35m\t\e[1m|\033[0m\e[0m Point ("<<a<<","<<b<<") lies in the Origin.\n";
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F4] "<<"Inputs: ("<<x<<","<<y<<") -- Output: (Lies in the origin)"<<endl;} else{}
   }


       int choose,any;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;
	any = ay;

	if (choose == 1) {
		qua();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}


}

void mircor ()
{
    system("clear");
	double x1,y1, mx, my, mo,x,y;
	int c;
	cout<<endl<<"\033[35m\t\e[1mMirror of a Point:\033[0m\e[0m\n"<<endl<<endl;
	cout<<"\t[1] Mirror with respect to X axis\n";
	cout<<"\t[2] Mirror with respect to Y axis\n";
	cout<<"\t[3] Mirror with respect to Origin\n";
	cout<<"\t[4] Mirror with respect to another Point\n";

	cout<<"\n\tChoose and option: ";
	cin>>c;

	if (c == 1) {
        cout<<endl<<"\t\033[34m> With respect to X axis:\033[0m"<<endl;
		cout<<"\t| Enter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"\033[35m\t\e[1m|\033[0m\e[0m Mirror of ("<<x1<<","<<y1<<") w.r.t X axis is ("<<x1<<","<<-y1<<")\n"<<endl;

		cout<<"\t\t\t|"<<endl<<"\t\t\t|\t.   ("<<x1<<","<<y1<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t--------------(0,0)--------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t.   ("<<x1<<","<<-y1<<") mirror"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t X axis is ("<<x1<<","<<-y1<<")"<<endl;}else{}
	}

	if (c == 2) {
        cout<<endl<<"\t\033[34m> With respect to Y axis:\033[0m"<<endl;
		cout<<"\t| Enter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"\033[35m\t\e[1m|\033[0m\e[0m Mirror of ("<<x1<<","<<y1<<") w.r.t Y axis is ("<<-x1<<","<<y1<<")\n"<<endl;
		cout<<"\tmirror("<<-x1<<","<<y1<<")\t|"<<endl<<"\t\t.\t|\t.   ("<<x1<<","<<y1<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t Y axis is ("<<-x1<<","<<y1<<")"<<endl;} else{}
	}

	if (c == 3) {
        cout<<endl<<"\t\033[34m> With respect to Origin:\033[0m"<<endl;
		cout<<"\t| Enter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"\033[35m\t\e[1m|\033[0m\e[0m Mirror of ("<<x1<<","<<y1<<") w.r.t Origin is ("<<-x1<<","<<-y1<<")\n"<<endl;
		double a,b;
		a=x1;
		b=y1;
        if( a > 0.00 && b > 0.00){
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t.   ("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t(("<<-a<<","<<-b<<")) .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t origin is ("<<-x1<<","<<-y1<<")"<<endl;} else{}

   }
        if(a < 0.00 && b > 0.00) {
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<") .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t. (("<<-a<<","<<-b<<"))"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }
        if(a < 0.00 && b < 0.00){
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t. (("<<-a<<","<<-b<<"))"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
        cout<<"\t----------------------------------"<<endl;
        cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t("<<a<<","<<b<<") .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }
        if(a > 0.00 && b < 0.00){
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t(("<<-a<<","<<-b<<")) .\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t----------------------------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|\t. ("<<a<<","<<b<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
   }

   cout<<endl<<"\t[Graph: ((x,y)) are the mirrored points]"<<endl;

	}

	if (c == 4) {
        cout<<endl<<"\t\033[34m> With respect to another Point:\033[0m"<<endl;
		cout<<"\t| Enter coordinates of the point: ";
		cin>>x1;
		cin>>y1;
		cout<<"\t| Enter coordinates of the mirroring point: ";
		cin>>mx;
		cin>>my;
		x = (2*mx)-x1;
		y = (2*my)-y1;
		cout<<"\033[35m\t\e[1m|\033[0m\e[0m Mirror of ("<<x1<<","<<y1<<") w.r.t ("<<mx<<","<<my<<") is ("<<x<<","<<y<<")\n"<<endl;

            cout<<"\t\t\t|"<<endl<<"\t("<<x<<","<<y<<") ."<<"\t|\t. ("<<mx<<","<<my<<")"<<"\t\t. ("<<x1<<","<<y1<<")"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            cout<<"\t--------------(0,0)--------------"<<endl;
            cout<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl<<"\t\t\t|"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F5] "<<"Mirror of ("<<x1<<","<<y1<<") w.r.t ("<<mx<<","<<my<<") is ("<<x1<<","<<-y1<<")"<<endl;}else{}

	}


	 int choose,any;any=ay;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		mircor();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}

void invelyz (){
    system("clear");
 int budget,n,i,tot=0, product_count[10000];
    double ivst, pricedata[10000], invested, invested_1, sell_price,x,y,z,profit,pro_sim = 0,rem_blnc = 0;
   cout<<endl<<"\033[35m\t\e[1mBusiness Analysis:\033[0m\e[0m\n"<<endl<<endl;
    cout<<"\t\e[1mInstructions:\e[0m\n\t1. Enter your total budget\n";
    cout<<"\t2.Enter the number of products you are intend to sell\n";
    cout<<"\t\033[32m(i.e. If you are planning to sell {A,B,C} then number of products is 3)\n";
    cout<<"\t\033[0m3. Enter Price per product\n";
    cout<<"\t4. Enter product counts\n";
    cout<<"\t5. Enter the percentage amount of your needed profit\n";
    cout<<"\n\n";
    cout<<"\t | Enter Your Budget: ";
    cin>>budget;
    cout<<"\t | Number of Products: ";
    cin>>n;
    for (i = 1; i <= n; i++) {
        cout<<"\t   | \033[0mPrice of product " << i<<" : ";
       cin>>pricedata[i];
        cout<<"\t   |\033[0mQuantity of product " << i<<" : ";
       cin>>product_count[i];
        ivst = pricedata[i]*product_count[i];
        invested += ivst;
        rem_blnc = budget - invested;

        if (rem_blnc <= 0 || pricedata[i+1] >= rem_blnc) {
            cout<<"\033[31m\n\t\tBUDGET EXCEEDED OR NO INVESTMENT LEFT\n\n";
            break;
            }
            else {
                tot++;
                cout<<"\t \033[35m| Remaining Balance : \033[0m"<< rem_blnc<<endl;
            }

    }
    int tot1=0;
    if (rem_blnc == 0 ) tot1 = tot+1;
    else tot1 = tot;
   cout<<"\t\033[0m------------------------------------------\n";
    for (i = 1; i<= tot1; i++) {
        ivst = pricedata[i]*product_count[i];
        cout<<"\t | Price of product "<< i<<"  is " << pricedata[i]<<endl;
        cout<<"\t | Quantity of product "<< i<<"  is "<< product_count[i]<<endl;
        cout<<"\t | Total Price of product "<< i<< " is "<< ivst<<endl;
        cout<<"\t------------------------------------------\n";
        invested_1 += ivst;
        if (pricedata[i] == 0) break;
    }
   cout<<"\t\033[32m | Total Invested: "<< invested_1<<endl;

    cout<<"\033[0m\t=========================================\n\n";
    cout<<"\033[0m\t | How much profit do you want? ";
    cin>>profit;
    pro_sim = profit/100;
    sell_price = invested_1 + (invested_1*pro_sim);
    cout<<"\n\n\033[0m\t------------------------------------------\n";
    cout<<"\n\033[35m\t\e[1m|\033[0m\e[0m Total Selling Price should be: "<< sell_price<<endl;
    cout<<"\n\033[0m\t------------------------------------------\n";
    double dsp = 0, dsp1 = 0;
    dsp = sell_price-invested_1;
    dsp1 = dsp/tot1;
    for (i = 1; i<= tot1; i++) {
        cout<<"\033[35m\t\e[1m|\033[0m\e[0m Sell the product "<< i<<" for \033[35m\t\e[1m"<< (pricedata[i]*pro_sim)+pricedata[i]<<"\033[0m\e[0m "<<endl;
        cout<<"\t------------------------------------------\n";
        //if (pricedata[i] == 0) break;
    }

            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F14] "<<"Budget: "<<budget<<", Invested: "<<invested_1<<"Selling Price: "<<sell_price<<endl;}else{}

    int choose,any;any=ay;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		invelyz();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}

void isect()
 {
     system("clear");
    double a1,b1,c1,a2,b2,c2,x1=0,y1=0,d=0,xx=0,yy=0;
    cout<<endl<<"\033[35m\t\e[1mIntersect Point of St Lines:\033[0m\e[0m\n"<<endl<<endl;
    cout<<"\t | Enter constant values for a1,b1,c1 respectively: ";
    cin>>a1>>b1>>c1;
    cout<<"\n";
    cout<<"\t | Enter constant values for a2,b2,c2 respectively: ";
    cin>>a2>>b2>>c2;
    cout<<"\n";
    cout<<"\t  > The equation of the straight line (1) is: "<<a1<<"x"<<std::showpos<<b1<<"y"<<c1 <<"= 0\n";
    cout<<"\t  > The equation of the straight line (2) is: "<<std::noshowpos<<a2<<"x"<<std::showpos<<b2<<"y"<<c2 <<"= 0\n"<<endl;

    d = (a1*b2)-(b1*a2);
    if (a1*b2 != a2*b1) {
        xx = (b1*c2)-(b2*c1);
        yy = (c1*a2)-(c2*a1);
        x1 = xx/d;
        y1 = yy/d;
       cout<<"\033[35m\t\e[1m|\033[0m\e[0m Intersect Point: ("<<std::noshowpos<<x1<<","<<y1<<")"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F10] "<<"Intersect Points: ("<<x1<<","<<y1<<")"<<endl;}else{}
    }
    else {
            cout<<"\033[35m\t\e[1m|\033[0m\e[0m The Lines are parallel to each other, hence there is no Intersect point"<<endl;
     string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F10] "<<"Parallel Lines"<<endl;}else{}
    }


 int choose,any;any=ay;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		isect();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
 }



void ntgrate ()
{

    system("clear");
    int a=0,b=0,c=0,d,e,mp,n,var,terms,i,j;
    char chars, sign1, sign2,sign,sign3,sign4,sign5,sign6,sign7,sign8,sign9,sign10,sign11;
    char powr;
    cout<<"\n\033[35m\t\e[1mIntigrate a Function\033[0m\e[0m\n";
    cout<<"\n";
    cout<<"\tIntegration of a Function is limited to only one term\n";
    cout<<"\t| Enter the power (n) of x (x^n): ";
    cin>>mp;
    terms = mp+1;
    int ara[terms],cont;
    cout<<"\t| Enter Constant value with x (if no, enter 1): ";
    cin>>cont;



            cout<<"\n\t--------------------------\n";
            cout<<"\tThe Equation is y = "<<cont<<"x^"<<mp<<endl;
            cout<<"\t--------------------------\n";
            cout<<"\033[35m\t\e[1m|\033[0m\e[0m INTEGRATION of Y:\n";
            cout<<"\t--------------------------\n";
            cout<<"\033[35m\t\e[1mint(y) dx \033[0m\e[0m = ("<<cont<<"/"<<mp+1<<")*x^"<<mp+1<<endl;

    int choose,any;any=ay;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		ntgrate();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}

}


void pdig() {

    {
        system("clear");

    double price,oprice,pdiff;
    int a,b,c,d,e,f,g,h,i,j,k,l,choose,any;any=ay;

    cout<<endl<<"\033[35m\t\e[1mProfit Diagram:\033[0m\e[0m\n"<<endl<<endl;
    cout<<"\tIf you are running a shop and you have some good amount of\n\tcompetitors around you, calculate the\n\tprobability if you can attract more customers\n\tby your service!"<<endl;

    cout<<endl<<"\t | Enter the price of your most iconic product: ";
    cin>>price;
    cout<<endl<<"\t> Enter \033[32m1\033[0m if \033[32myes/true\033[0m and \033[31m0\033[0m if \033[31mno/false\033[0m: "<<endl;
    cout<<endl<<"\t | Is there any other shop selling this product? ";
    cin>>a;
    if (a >0 ){
    cout<<"\t | Whats the price of the product they are selling for? ";
    cin>>oprice;
    cout<<"\t | Do they provide any warranty/after sales service? ";
    cin>>b;
    cout<<"\t | Do you provide any warranty/after sales service? ";
    cin>>c;
    cout<<"\t | Are they providing any offers with the product? ";
    cin>>d;
    cout<<"\t | Are you providing any offers with the product? ";
    cin>>e;
    cout<<endl<<"\t> Which shop is more organized & consumer friendly? "<<endl;
    cout<<"\t | Type \033[32m1\033[0m if \033[32myours\033[0m and \033[31m0\033[0m if \033[31mtheirs\033[0m ";
    cin>>f;
    pdiff = oprice - price;

    int fb,fc,fd,fe,ff,pl;
    fb = b*30;
    fc = c*30;
    fd = d*40;
    fe = e*40;
    if (f == 1) {
        ff = f*20;
    }
    if (f == 0) {
        ff = 0;
    }
    if (pdiff > 0) {
        pl = 10;
    }
    if (pdiff < 0 ) {
        pl = -8;
    }
    if (pdiff == 0){
        if (c+e+f > b+d+1) {
            pl = 5;
        }
        if (c+e+f < b+d+1) {
            pl = 0;
        }
    }

    int sum = 0;
    sum = fc + fe + ff+pl;
    cout<<endl;
    cout<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m You will Attract "<<sum<<" percent of the customers!"<<endl<<endl;;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F15] "<<"You will Attract "<<sum<<" percent of the customers!"<<endl;}else{}
    }
    else {
        cout<<"\033[35m\t\e[1m|\033[0m\e[0m You are the only player in the field, Play as you like!!"<<endl<<endl;
        string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F15] "<<"You are the only player in the field, Play as you like!"<<endl;}else{}
    }


    cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";
    cin>>choose;

    if (choose == 1) {
            system("clear");
            pdig();
    }
    if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
    if (choose == 0) {
        system("clear");
        main1();
    }

}

}



void maxima(){

    system("clear");
    double a,b,c,x=0,y=0;
    cout<<endl<<"\033[35m\t\e[1mMaxima/Minima of a Function:\033[0m\e[0m\n"<<endl<<endl;
    cout<<"\t| Enter the values of a, b, c respectively:"<<endl;
    cout<<"\t   a: "; cin>>a;
    cout<<"\t   b: "; cin>>b;
    cout<<"\t   c: "; cin>>c;
    cout<<endl<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m The function is y = "<<a<<"x^2"<<std::showpos<<b<<"x"<<std::showpos<<c<<std::noshowpos<<endl;
    if ( a >0 ){
            x = ((-1)*b)/(2*a);
            y = (a*(x*x))+(b*x)+c;

        cout<<"\033[35m\t\e[1m|\033[0m\e[0m The above function has minima value.\n\033[35m\t\e[1m|\033[0m\e[0m The minima coordinates are ("<<x<<","<<y<<")"<<endl;
       string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F11] "<<"Minima: ("<<x<<","<<y<<")"<<endl;}else{}
    }
    else {
        x = ((-1)*b)/(2*a);
            y = (a*(x*x))+(b*x)+c;
            cout<<"\033[35m\t\e[1m|\033[0m\e[0m The above function has maxima value"<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m The maxima coordinates are ("<<x<<","<<y<<")"<<endl;
            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F11] "<<"Maxima: ("<<x<<","<<y<<")"<<endl;}else{}
    }


    cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";
int choose,any;any=ay;
    cin>>choose;

    if (choose == 1) {
        maxima();
    }
    if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
    if (choose == 0) {
        system("clear");
        main1();
    }


}

void angle()
{
    system("clear");
    cout<<endl<<"\033[35m\t\e[1mAngle in x axis of a Point:\033[0m\e[0m\n"<<endl<<endl;
     cout<<"\t| Enter the X and Y coordinates : ";
    setlocale(LC_ALL, "");

    double x ,y ,hor = 0, lob = 0, b = 0.596227, k=0, theta = 0 , k2 =0;

    cin>>x>>y;
    k = y/x;
    theta = atan(k);
    theta = theta * 57.29577;
    cout<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m Angle made by ("<<x<<","<<y<<") is "<<theta<<" degrees"<<endl;

    string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F7] "<<"Input: ("<<x<<","<<y<<") Angle: "<<theta<<endl;}else{}

    int choose,any;any=ay;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		angle();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}

void eqgen(){
    system("clear");
    double x1,y1,x2,y2,a,b;
    cout<<endl<<"\033[35m\t\e[1mStraight Line Equation Generator:\033[0m\e[0m\n"<<endl<<endl;
    cout<<"\t| Enter (x1,y1), (x2,y2) respectively: "; cin>>x1>>y1>>x2>>y2;
    a = x1-x2;
    b = y1-y2;
    cout<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m Equation: "<<b<<"x"<<std::showpos<<-a<<"y"<<(-b*x1)+(a*y1)<<"= 0"<<endl;

            string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F8] "<<"Input: ("<<x1<<","<<y1<<","<<x2<<","<<y2<<") Equation: "<<b<<"x"<<std::showpos<<-a<<"y"<<(-b*x1)+(a*y1)<<"= 0"<<endl;}else{}

    int choose,any;any=ay;
	cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		eqgen();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}
}


void car()
{
    system("clear");
	 double x, y, r, theta,thetain,PI = 3.1416;
	 cout<<endl<<"\033[35m\t\e[1mPolar to Cartesian Conversion:\033[0m\e[0m\n"<<endl<<endl;
	 cout<<"\t| Enter radius of polar coordinate (r): ";
	 cin>>r;
	 cout<<"\t| Enter angle of polar coordinate in degree (theta): ";
	 cin>>thetain;

	 theta = thetain * PI/180;

	 x = r * cos(theta);

	 y = r * sin(theta);

	cout<<endl<<"\033[35m\t\e[1m|\033[0m\e[0m Cartesian coordinates are (x,y) : (" << x<<"," << y<<")"<<endl;

	string uname;
            uname = up;
            int uh = ay;if(uh==0){ofstream outfile;
            outfile.open("History/"+uname+"_calculations.txt", std::ios_base::app);
            outfile<<"[F3] "<<"Inputs: ("<<r<<","<<thetain<<") -- Output: ("<<x<<","<<y<<")"<<endl;} else{}

	int choose,any;any=ay;
    cout<<endl<<"\t\033[32m\e[1m[1]\e[0m\33[0m Calculate Again\t\033[36m\e[1m[2]\e[0m\33[0m Return to Menu\t\033[31m\e[1m[0]\e[0m\33[0m Exit: ";

	cin>>choose;

	if (choose == 1) {
		car();
	}
	if (choose == 2&& any == 0)
        {
            system("clear");
            umenu();
        }
        if (choose == 2&& any == 1)
        {
            system("clear");
            anonmenu();
        }
	if (choose == 0) {
		system("clear");
		main1();
	}

}

void umenu()
    {
        string uname = up,bpm,bmark;
        int opr;
        ifstream read("Q/BPob/Score/"+uname+"_bpob.txt");
        getline(read, bpm);
        bmark = bpm;
        ofstream outfile;
        cout<<"\n\t----------------"<<endl;
        cout<<"\tHello, "<<uname<<endl;
        cout<<"\t----------------\n\n";
        cout<<"\033[35m\t\e[1mCoordinate Geometry\033[0m\e[0m\n";
        cout<<"\t\033[35m\e[1m[1]\033[0m\e[0m  Distance between two points\n";
        cout<<"\t\033[35m\e[1m[2]\033[0m\e[0m  Cartesian to Polar Conversion\n";
        cout<<"\t\033[35m\e[1m[3]\033[0m\e[0m  Polar to Cartesian Conversion\n";
        cout<<"\t\033[35m\e[1m[4]\033[0m\e[0m  Quadrant of a Coordinate\n";
        cout<<"\t\033[35m\e[1m[5]\033[0m\e[0m  Mirror of a point\n";
        cout<<"\t\033[35m\e[1m[6]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n";
        cout<<"\t\033[35m\e[1m[7]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n";
        cout<<"\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n";
        cout<<"\t\033[36m\e[1m[8]\033[0m\e[0m  St. Line Equation Generator\n";
        cout<<"\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n";
        cout<<"\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n";
        cout<<"\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n";
        cout<<"\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n";
        cout<<"\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n";
        cout<<"\t\033[33m\e[1m[13]\033[0m\e[0m  Integrate a Function\n";
        cout<<"\n\n\033[32m\t\e[1mBusiness Analysis\033[0m\e[0m\n";
        cout<<"\t\033[32m\e[1m[14]\033[0m\e[0m  Invest Analysis\n";
        cout<<"\t\033[32m\e[1m[15]\033[0m\e[0m  Profit Diagram\n";
        cout<<"\n\n";
        cout<<"\033[35m\t\e[1mAccount Settings\033[0m\e[0m\n";
        cout<<"\t\033[35m\e[1m[20]\033[0m\e[0m  Surfing History\t\033[35m\e[1m[21]\033[0m\e[0m  Calculation History"<<endl;
        cout<<"\t\033[35m\e[1m[22]\033[0m\e[0m  Change Username\t\033[35m\e[1m[23]\033[0m\e[0m  Change Password"<<endl;
        cout<<endl;
        cout<<"\t\033[34m\e[1m[25]\033[0m\e[0m Practice Maths \t\033[31m\e[1m[0]\033[0m\e[0m Log Out ("<<uname<<")"<<endl<<endl;
        cout<<"\t | Choose: ";
        cin>>opr;
        if (opr == 0)
        {
            system("clear");
            main1();
        }
        if(opr ==1 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Distance between two points"<<endl;
            dis_1();

        }
        if(opr ==2 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Cartesian to Polar Conversion"<<endl;
            pol();
        }
        if(opr ==3 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Polar to Cartesian Conversion"<<endl;
            car();

        }
        if(opr ==4 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Quadrant of a Point"<<endl;
            qua();

        }
        if(opr ==5 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Mirror of a Point"<<endl;
            system("clear");
            mircor();

        }
        if(opr ==6 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Distance of a Coordinate from O(0,0)"<<endl;
            dis_2();
        }
        if(opr ==7 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Angle made by a point"<<endl;
            angle();
        }
        if(opr ==8)
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened St. Line Equation generator"<<endl;
            eqgen();
        }
        if(opr ==9 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Slope of a st. Line"<<endl;
            slopeq();
        }
        if(opr ==10)
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Intersect Point of two st. Line"<<endl;
            isect();
        }
        if(opr ==11)
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Maxima/Minima of a Function"<<endl;
            maxima();
        }
        if(opr ==12 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Differentiator"<<endl;
            system("clear");
            diff();
        }
        if(opr ==13 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Integrator"<<endl;
            system("clear");
            ntgrate();
        }
        if(opr ==14 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Invest Analysis"<<endl;
            system("clear");
            invelyz();
        }
        if(opr ==15 )
        {
            outfile.open("History/"+uname+".txt", std::ios_base::app);
            outfile <<uname<<" Opened Profit Diagram"<<endl;
            system("clear");
            pdig();
        }
            if (opr == 20){
            system("clear");
            clrh();

        }
        if (opr == 21){
            system("clear");
            calh();

        }
        if (opr == 22){
            system("clear");
            cname();

        }
        if (opr == 23){
            system("clear");
            cpass();

        }
        if (opr == 25){
            system("clear");
            prac();

        }

    }


    void clrh() {

            string a1,a2,a3,a4,a5,a6,a7,uname=up;
            ifstream read("History/"+uname+".txt");
            getline(read, a1);
            getline(read, a2);
            getline(read, a3);
            getline(read, a4);
            getline(read, a5);
            getline(read, a6);
            getline(read, a7);
            cout<<endl<<"\033[35m\t\e[1mRecent History\033[0m\e[0m ("<<uname<<")"<<endl;
            if ( a1.empty() ){
                    cout<<endl<<"\t(no surfing history)!"<<endl;
                    int choose;
                    cout<<endl<<"\t[2] Return to Menu: "; cin>>choose;
                    if (choose==2) {
                        system("clear");
                        umenu();
                    }

            }
            else {
                    cout<<"\t"<<a1<<endl<<"\t"<<a2<<endl<<"\t"<<a3<<endl<<"\t"<<a4<<endl<<"\t"<<a5<<endl<<"\t"<<a6<<endl<<"\t"<<a7<<endl;
            int clh;
            cout<<endl<<"\t[1] Clear History\t[2] Return to Menu: "; cin>>clh;
            if (clh == 1){
                ofstream file;
                file.open("History/"+uname+".txt");
                file <<"";
                file.close();
                cout<<endl<<"\tPlease wait...";
                cout<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                cout<<"\t\033[32mHistory Cleared!\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                system("clear");
                clrh();
            }
            if (clh == 2){
                system("clear");
                umenu();
            }


    }
    }


    void calh() {

            string a1,a2,a3,a4,a5,a6,a7,uname=up;
            ifstream read("History/"+uname+"_calculations.txt");
            getline(read, a1);
            getline(read, a2);
            getline(read, a3);
            getline(read, a4);
            getline(read, a5);
            getline(read, a6);
            getline(read, a7);
            cout<<endl<<"\033[35m\t\e[1mRecent History\033[0m\e[0m ("<<uname<<")"<<endl;
            if ( a1.empty() ){
                    cout<<endl<<"\t(no calculation history)!"<<endl;
                    int choose;
                    cout<<endl<<"\t[2] Return to Menu: "; cin>>choose;
                    if (choose==2) {
                        system("clear");
                        umenu();
                    }

            }
            else {
                    cout<<"\t"<<a1<<endl<<"\t"<<a2<<endl<<"\t"<<a3<<endl<<"\t"<<a4<<endl<<"\t"<<a5<<endl<<"\t"<<a6<<endl<<"\t"<<a7<<endl;
            int clh;
            cout<<endl<<"\t[1] Clear History\t[2] Return to Menu: "; cin>>clh;
            if (clh == 1){
                ofstream file;
                file.open("History/"+uname+"_calculations.txt");
                file <<"";
                file.close();
                cout<<endl<<"\tPlease wait...";
                cout<<endl<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                cout<<"\t\033[32mHistory Cleared!\033[0m"<<endl;
                this_thread::sleep_for(chrono::milliseconds(600));
                system("clear");
                calh();
            }
            if (clh == 2){
                system("clear");
                umenu();
            }


    }
    }


    void anonmenu()
    {
        int opr;
        cout<<"\n\t----------------"<<endl;
        cout<<"\tHello, Anon!"<<endl;
        cout<<"\t----------------\n\n";
        cout<<"\033[35m\t\e[1mCoordinate Geometry\033[0m\e[0m\n";
        cout<<"\t\033[35m\e[1m[1]\033[0m\e[0m  Distance between two points\n";
        cout<<"\t\033[35m\e[1m[2]\033[0m\e[0m  Polar to Cartesian Conversion\n";
        cout<<"\t\033[35m\e[1m[3]\033[0m\e[0m  Cartesian to Polar Conversion\n";
        cout<<"\t\033[35m\e[1m[4]\033[0m\e[0m  Quadrant of a Coordinate\n";
        cout<<"\t\033[35m\e[1m[5]\033[0m\e[0m  Mirror of a point\n";
        cout<<"\t\033[35m\e[1m[6]\033[0m\e[0m  Distance of a Coordinate from O(0,0)\n";
        cout<<"\t\033[35m\e[1m[7]\033[0m\e[0m  Angle made by the point with respect to x & y axis.\n";
        cout<<"\n\n\033[36m\t\e[1mStraight Lines\033[0m\e[0m\n";
        cout<<"\t\033[36m\e[1m[8]\033[0m\e[0m  St. Line Equation Generator\n";
        cout<<"\t\033[36m\e[1m[9]\033[0m\e[0m  Slope of a st. Line\n";
        cout<<"\t\033[36m\e[1m[10]\033[0m\e[0m Intersect Point of two st. lines\n";
        cout<<"\n\n\033[33m\t\e[1mCurves Analysis\033[0m\e[0m\n";
        cout<<"\t\033[33m\e[1m[11]\033[0m\e[0m  Maxima & Minima of a Function\n";
        cout<<"\t\033[33m\e[1m[12]\033[0m\e[0m  Differentiation of a Function\n";
        cout<<"\t\033[33m\e[1m[13]\033[0m\e[0m  Integrate a Function\n";
        cout<<"\n\n\033[32m\t\e[1mBusiness Analysis\033[0m\e[0m\n";
        cout<<"\t\033[32m\e[1m[14]\033[0m\e[0m  Invest Analysis\n";
        cout<<"\t\033[32m\e[1m[15]\033[0m\e[0m  Profit Diagram\n";
        cout<<"\n\n";
        cout<<"\t\033[31m\e[1m[0]\033[0m\e[0m  Exit"<<endl<<endl;
        cout<<"\t | Choose: ";
        cin>>opr;
        if (opr == 0)
        {
            system("clear");
            main1();
        }
        if(opr ==1 )
        {
            system("clear");
            dis_1();

        }
        if(opr ==2 )
        {
            system("clear");
            pol();
        }
        if(opr ==3 )
        {
            system("clear");
            car();
        }
        if(opr ==4 )
        {
            system("clear");
            qua();

        }
        if(opr ==5 )
        {
            system("clear");
            mircor();

        }
        if(opr ==6 )
        {
            system("clear");
            dis_2();
        }
        if(opr ==7 )
        {
            system("clear");
            angle();
        }
        if(opr ==8)
        {
            system("clear");
            eqgen();
        }
        if(opr ==9 )
        {
            system("clear");
            slopeq();
        }
        if(opr == 10 )
        {
            system("clear");
            isect();
        }
        if(opr == 11 )
        {
            system("clear");
            maxima();
        }
        if(opr ==12 )
        {

            system("clear");
            diff();
        }
        if(opr ==13 )
        {
            system("clear");
            ntgrate();
        }
        if(opr ==14 )
        {
            system("clear");
            invelyz();
        }
        if(opr ==15 )
        {
            system("clear");
            pdig();
        }

    }


    void docs(){

        cout<<"\n\033[35m\t\e[1mRead Me\033[0m\e[0m\n";
        cout<<"\t\033[35m______________________________\033[0m\n\n";
        cout<<"\n\033[35m\t\e[1mIntro\033[0m\e[0m\n";
        cout<<"\tHello user, Thank you for using \e[1mLinear Equations & Function Analysis\e[0m\n";
        cout<<"\tThis is a simple calculator that solves maths related to both\n\tLinear and Continious Functions. Since the";
        cout<<" beginnig of the\n\tjourney of our programming, we have been thinking of some ways\n\tto integrate programming with mathematics. We asked ";
        cout<<"our course\n\tinstructors about it and later found out that programming and\n";
        cout<<"\tMathematics are interconnected. So we started studying more about\n\tprogramming and started to solve problems on online platforms.\n\tAnd later by getting ";
        cout<<"motivated by our CSE100 course instructor,\n\thonorable \e[1mMuhammad Mohsin Kabir\e[0m, We chose this very fun project.\n";
        cout<<"\n";
        cout<<"\n\033[35m\t\e[1mAbout LEFAN\033[0m\e[0m\n";
        cout<<"\tLEFAN is a c++ based math calculator. We have tried to use\n\tlogics and arguments to build a *almost* useful tool for the\n\tpeople who share love for geometry and maths. Mathematics\n";
        cout<<"\tindeed has always been the greatest field of study till current date\n\tAnd";
        cout<<" since Maths and Programming are both accompany each other,\n\tSo the project LEFAN not only made us writing lines of codes,\n\tbut also helping us on developing critical analysis, logic building\n\tunderstanding a lot of untouched *by us* features of programming and\n";
        cout<<"\tmathematics.";
        cout<<"\n\n";
        cout<<"\n\033[35m\t\e[1mSimilar Project(s) Elsewhere\033[0m\e[0m\n";
        cout<<"\tSince LEFAN is a calculator and there are *indeed* a large amount\n\tof calculators everywhere, so it is certain that there\n\tmight be a lot of simillar projects. Even there are some dedicated\n";
        cout<<"\tonline calculators for solving differential/integral/probability/\n\tgeometry/trigonometry/algebric functions and many more! But\n\tas our knowledge is hardly limited and it was our first project,\n\tTeam LEFAN did very good in our opinion. As it is not always about,\n";
        cout<<"\tIt was already created so better not try on it, rather its\n\tmore about getting deep inside of every aspect of knowledge.\n\tThere might be some simillar projects roaming around, But\n\tThe joy of completing it does not villify it.\n\t";
        cout<<"\n\n";
        cout<<"\n\033[35m\t\e[1mResources\033[0m\e[0m\n";
        cout<<"\tSince it can be said that we are pretty much new in the sea of c++,\n\twe had to study on it a lot. Solving maths problems,\n\tso that the outputs tend to most accurate possible, we had to\n\tknock on some doors of online forums and QnA based platforms.\n";
        cout<<"\tBut it was certainly limited to study rather than being some copycats.\n";
        cout<<"\n\n";
        cout<<"\n\033[35m\t\e[1mFuture\033[0m\e[0m\n";
        cout<<"\tWe have faith that we can do a lot better in the future. All these\n\tlimitations right now will no longer prohibit us from what\n\twe want to achieve, we dream of. We are intended to study on\n\tprogramming more and more, understanding why we are binded by these\n\tlimitations now and figure out the ways to overcome them.\n";
        cout<<"\n\n";
        cout<<"\n\033[35m\t\e[1mBehind LEFAN\033[0m\e[0m\n\n";
        cout<<"\t | Mumtahina Ahmed\n";
        cout<<"\t   Dept. of CSE , BUBT\n";
        cout<<"\t   Intake 47, Section 1\n";
        cout<<"\n";
        cout<<"\t | Rajieb Rojarieo\n";
        cout<<"\t   Dept. of CSE , BUBT\n";
        cout<<"\t   Intake 47, Section 1\n";
        cout<<"\n";
        cout<<"\t | Saria Alam\n";
        cout<<"\t   Dept. of CSE , BUBT\n";
        cout<<"\t   Intake 47, Section 1\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n\033[35m\t\e[1mThanking\033[0m\e[0m\n\n";
        cout<<"\t | Muhammad Mohsin Kabir sir\n";
        cout<<"\t | Badsha Faisal sir\n";
        cout<<"\t | Abu Quwsar Ohi sir\n";
        cout<<"\t | Nowshed Al Nur sir\n";
        cout<<"\t | Stackoverflow\n";
        cout<<"\t | geeksforgeeks\n";
        cout<<"\t | BUBT\n";
        cout<<"\t | Coffee\n";
        cout<<"\t | Whoever Helped & Encouraged\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n";
        cout<<"\n\033[35m\t\e[1mLEFAN\033[0m\e[0m - Dedicated to you.\n\n";
        cout<<"\n";
        int choose;
        cout<<endl<<"\t\033[36m\e[1m[0]\e[0m\33[0m Return to Menu: ";

	cin>>choose;
	if (choose == 0) {
		main1();
	}

cout<<endl;
    }


    void prac(){

        int cp;

        cout<<"\n\033[35m\t\e[1mWelcome to Maths Playground\033[0m\e[0m\n";
        cout<<"\t\033[35m\e[1m[1]\033[0m\e[0m  Beginner Problems\n";
        cout<<"\t     | Topics: Easy Algebra, Geometry, Matrix, Vector"<<endl;

        cout<<"\t\033[35m\e[1m[2]\033[0m\e[0m  BrainFreeze Problems\n";
        cout<<"\t     | Topics: Check yourself ;)"<<endl;


        cout<<"\n\t | Choose: ";
        cin>>cp;
        wcp = cp;
                playground();
    }

    void playground() {
        system("clear");
        string qbank,q,o1,o2,o3,o4,a,uname,cat,qcat;
        uname = up;
        int in,aa,line,wcat,sk=0;
        wcat = wcp;
        if (wcat == 1 ){
                qbank="bpob";
                cat = "BPob";
                qcat="Beginner Problems";
        }
        if (wcat == 2) {
                qbank="bfreeze";
                cat = "BFreeze";
                qcat="Brainfreeze Problems";
        }

        cout<<"\n\033[35m\t\e[1m"<<qcat<<"\033[0m\e[0m";
        int ta=0,wa=0,ca=0;
        double bmark = 0;
        cout<<endl<<endl;
        ifstream qfile("Questions/"+qbank+".txt");
        int totq = 0,totl=0;
        string lineq;
        while (std::getline(qfile, lineq)){
                ++totl;
        }
        qfile.close();
        totq = totl/6;
        //cout<<totq<<endl<<endl<<endl;
        ifstream read("Questions/"+qbank+".txt");
        for(int i =1; i<=totq;i++){
            getline(read, q);
            getline(read,o1);
            getline(read,o2);
            getline(read,o3);
            getline(read,o4);
            getline(read,a);
            aa = stoi(a);
            cout<<"\t\033[35m\e[1m["<<i<<"]\033[0m\e[0m "<<q<<endl;
            cout<<"\t"<<o1<<endl<<"\t"<<o2<<endl<<"\t"<<o3<<endl<<"\t"<<o4<<endl;
            cout<<"\n\t | Answer: "; cin>>in;
            if(in == aa) {
                bmark++;
                ca++;
                cout<<endl<<"\033[32m\tCorrect Answer!!\033[0m"<<endl<<endl;
            }
            else {
                if(in == 0){
                    bmark = bmark;
                    sk++;
                    cout<<endl<<"\033[33m\tQuestion Skiped ;)\033[0m"<<endl<<endl;
                }
                else{
                bmark = bmark-0.25;
                wa++;
                cout<<endl<<"\033[31m\t Wrong Answer!!\033[0m\n\t | Correct Answer: \033[32m("<<a<<")\033[0m"<<endl<<endl;
                }
            }
            line++;
        }
        //bm=bmark;

        cout<<"\tTotal Questions: "<<ca+sk+wa<<"\tTotal Answered: "<<ca+wa<<"\n\tWrong: "<<wa<<"\t\tScore: "<<bmark<<endl<<endl;
        int choose;
        cout<<endl<<"\t\033[36m\e[1m[0]\e[0m\33[0m Return to Menu: ";

        cin>>choose;
        if (choose == 0) {
		system("clear");
		umenu();
	}

    }

};


int main()
{
    Functions ob;
    ob.main1();

}
