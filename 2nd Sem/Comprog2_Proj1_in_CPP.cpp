//FLORES, Earl John C.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
#define MAX 50
#define items 5
#define TIME 10

struct Player{
    string Name;
    string Password;
    int Ascore;
    int Sscore;
    int Mscore;
    int Dscore;
    int Bscore;
};
class File{
    virtual void Save()= 0;
    virtual void Retrieve()=0;
};
class User: public File{
private:
    Player Users[MAX];
    float CompAve(Player u);
    int last;
public:
    void setUser(Player user){Users[last++] = user;}
    void setLast(int Last){last = Last;}
    int getLast(){return last;}
    int Add(Player u);
    int Sub(Player u);
    int Mul(Player u);
    int Div(Player u);
    void Fast(Player u);
    int Menu();
    int GameMenu(Player u);
    void init();
    bool isFull();
    bool isEmpty();
    int Fpass(Player u);
    int Locate(Player u);
    int Login();
    int Signin(Player u);
    void Sort();
    int Lead();
    void Alead();
    void Slead();
    void Mlead();
    void Dlead();
    void Blead();
    void Save()override;
    void Retrieve()override;
};


float average;
Player user1;
User user;
int main (){
    int n;
    user.init();
    user.Retrieve();
    while(1){
        switch(user.Menu()){
        case 1:
            if (user.isEmpty()){
                cout<<"Sign-up first to play.\n";
                getchar(); getchar();
                break;
            }
            system("cls");
            if(user.Login()==-1){getchar();break;}
            user.Lead();
            while(1){
                system("cls");
                int choice = user.GameMenu(user1);
                if(choice == 7){user.Save(); break;}
                switch(choice){
                    case 1:
                        system("cls"); user.Lead(); break;
                    case 2:
                        system("cls"); cout<<"Addition Game\n";
                        srand(time(NULL));
                        n = user.Add(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl; system("pause");
                        system("cls"); user.Alead();
                        system("pause"); user.Sort();continue;
                    case 3:
                        system("cls"); cout<<"Subtraction Game\n";
                        srand(time(NULL));
                        n = user.Sub(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl;system("pause");
                        system("cls"); user.Slead();
                        system("pause");user.Sort();continue;
                    case 4:
                        system("cls"); cout<<"Multiplication Game\n";
                        srand(time(NULL));
                        n = user.Mul(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl;system("pause");
                        system("cls"); user.Mlead();
                        system("pause");user.Sort(); continue;
                    case 5:
                        system("cls"); cout<<"Division Game\n";
                        srand(time(NULL));
                        n = user.Div(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl;system("pause");
                        system("cls"); user.Dlead(); system("pause");
                        user.Sort(); continue;
                    case 6:
                        system("cls"); srand(time(NULL));user.Fast(user1);
                        system("cls");user.Blead();system("pause");user.Sort();continue;
                    default: cout<<"Enter 1-7 ONLY!\n";getchar();getchar();continue;
                    }
            }break;
        case 2:
            system("cls");
            cin.ignore();
            cout<<"Player Sign-in\n";
            cout<<"--------------------------\n";
            cout<<"Enter username: "; getline(cin,user1.Name);
            if(user.Locate(user1) !=-1){
                cout<<"Player already exists\n";
                system("pause"); break;
            }
            cout<<"Enter password: ";getline(cin,user1.Password);
            user.Signin(user1); break;
        case 3:
            cout<<"Recorded Successfully.\nThank you for playing.\n";
            user.Save(); exit(0);
        default: cout<<"Enter 1-3 ONLY!\n"; getchar();break;
        }
    }return 0;
}
void User::init(){
    last = -1;
}
bool User::isFull(){
    if(last == MAX-1) return true; return false;
}
bool User::isEmpty(){
    if(last == -1) return true; return false;
}
int User::Locate(Player u){
    for (int i = 0; i<= last; i++){
        if(strcasecmp(u.Name.c_str(),Users[i].Name.c_str())==0){
            return i;
        }
    }return -1;
}
int User::Fpass(Player u){
    int i= Locate(u);
    if(i == -1) return -1;
    if(strcasecmp(u.Password.c_str(),Users[i].Password.c_str())==0)
    return i;
    return -1;
}
int User::Signin(Player u){
    if(isFull()){
        cout<<"Number of players is full\n"; system("pause"); return -1;
    }
    if(this->Locate(u)!=-1){
        cout<<"Player already exists!\n"; system("pause"); return -1;
    }
    last++;
    Users[last]=u;
    Users[last].Ascore = 0;
    Users[last].Sscore = 0;
    Users[last].Mscore = 0;
    Users[last].Dscore = 0;
    Users[last].Bscore = 0;
    return 0;
}
int User::Login(){
    cin.ignore();
    cout<<"Player Log-in\n";
    cout<<"--------------------------\n";
    cout<<"Enter username: "; getline(cin,user1.Name);
    if(this ->Locate(user1) == -1){
            cout<<"Player does not exist yet. Sign up first.\n";
            return -1;
        }
    cout<<"Enter password: ";getline(cin,user1.Password);
    if(this->Fpass(user1) == -1){
        cout<<"Wrong password\n";
        return -1;
    }
    cout<<"Welcome, "<<user1.Name<<endl; system("pause");
    return 0;
}
int User::Add(Player u){
    int x, y, c = 0, ans,i =Locate(u);
    for(int i=1;i<=items;i++){
    x = rand() %100+1;
    y = rand() %100+1;
    cout<<i<< ".) "<<x<<" + "<<y<<" = ";
    cin>>ans;
    if(ans== x+y){
        cout<<"\033[1;32mCorrect\033[0m\n";
        c++;}else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x+y <<endl;
    }
    Users[i].Ascore = c;
    return c;
}
int User::Sub(Player u){
    int x, y, c = 0, ans,i = user.Locate(u);
    for(int i=1;i<=items;i++){
    x = rand()%100+1;
    y = rand()%100+1;
    do{x = rand()%100+1;y = rand()%100+1;}while(x<y);
    cout<<i<< ".) "<<x<<" - "<<y<<" = ";
    cin>>ans;
    if(ans== x-y){
        cout<<"\033[1;32mCorrect\033[0m\n";
        c++;}else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x-y<<endl;
    }
    Users[i].Sscore = c;
    return c;
}
int User::Mul(Player u){
    int x, y, c = 0, ans, i = user.Locate(u);
    for(int i=1;i<=items;i++){
    x = rand() %20+1;
    y = rand() %20+1;
    cout<<i<< ".) "<<x<<" x "<<y<<" = ";
    cin>>ans;
    if(ans== x*y){
        cout<<"\033[1;32mCorrect\033[0m\n";
        c++;}else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x*y<<endl;
    }
    Users[i].Mscore = c;
    return c;
}
int User::Div(Player u){
    int x, y, c = 0, ans, i = user.Locate(u);
    for(int i=1;i<=items;i++){
    x = rand()%100+1;
    y = rand()%100+1;
    do{
    x = rand()%100+1;
    y = rand()%100+1;
    } while(x%y != 0);
    cout<<i<< ".) "<<x<<" / "<<y<<" = ";
    cin>>ans;
    if(ans== x/y){
        cout<<"\033[1;32mCorrect\033[0m\n";
        c++;}else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x/y<<endl;
    }
    Users[i].Dscore = c;
    return c;
}
int User::Menu(){
    system("cls");
    int op;
    cout<<"--------------------------\n";
    cout<<"Basic Arithmetic Game\n";
    cout<<"--------------------------\n";
    cout<<"1. Log-in\n2. Sign-in\n3. Save and Exit\n";
    cout<<"--------------------------\n";
    cout<<"Enter (1-3): "; cin>>op;
    return op;
}
int User::GameMenu(Player u){
    int gop;
    cout<<"--------------------------\n";
    cout<<"Basic Arithmetic Game\n";
    cout<<"--------------------------\n";
    cout<<"Playing as: "<<user1.Name<<endl;
    cout<<"--------------------------\n1. Leaderboards\n";
    cout<<"2. Addition\n3. Subtraction\n4. Multiplication\n5. Division\n6. Blitz Game\n7. Return to Main Menu\n";
    cout<<"Enter (1-7): "; cin>>gop;
    return gop;
}
int User::Lead(){
    system("cls");
    float ave; int i,limit = (last < 10)? last:10;
    cout<<"------------------------------------------------------\n";
    cout<<"\t\tTop 10 Leaderboards\n";
    cout<<"------------------------------------------------------\n";
    cout<<"\tName\tScore +\tScore -\tScore x\tScore /\tAverage\n";
    cout<<"------------------------------------------------------\n";
    user.Sort();
    for (i = 0;i<=limit;i++){
        ave = user.CompAve(Users[i]);
        cout<<i+1<<".) "<<Users[i].Name<<"\t"<<Users[i].Ascore<<"\t"<<Users[i].Sscore<<"\t"<<Users[i].Mscore<<"\t"<<Users[i].Dscore<<"\t"<<ave<<endl;
    }
    user.Blead(); user.Sort(); system("pause");

    return 1;
}
void User::Alead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    Player tUser;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (Users[i].Ascore < Users[j].Ascore) {
                tUser = Users[i];
                Users[i] = Users[j];
                Users[j] = tUser;
            }
        }
    }
    cout<<"---------------------------------\n";
    cout<<" Top 10. Addition Leaderboards\n";
    cout<<"---------------------------------\n";
    cout<<"Name\t\tScore \n";
    cout<<"------------------------------\n";
    for (i = 0;i<=limit;i++){
        if (i==0)cout<<"\033[1;33m";else cout<<"\033[0;37m";
        cout<<i+1<<".) "<<Users[i].Name<<"\t"<<Users[i].Ascore<<"\n";
    }
}
void User::Slead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    Player tUser;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (Users[i].Sscore < Users[j].Sscore) {
                tUser = Users[i];
                Users[i] = Users[j];
                Users[j] = tUser;
            }
        }
    }
    cout<<"------------------------------------\n";
    cout<<" Top 10. Substraction Leaderboards\n";
    cout<<"------------------------------------\n";
    cout<<"Name\t\tScore \n";
    cout<<"---------------------------------\n";
    for (i = 0;i<=limit;i++){
        if (i==0)cout<<"\033[1;33m";else cout<<"\033[0;37m";
        cout<<i+1<<".) "<<Users[i].Name<<"\t"<<Users[i].Sscore<<"\n";
    }
}
void User::Mlead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    Player tUser;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (Users[i].Mscore < Users[j].Mscore) {
                tUser = Users[i];
                Users[i] = Users[j];
                Users[j] = tUser;
            }
        }
    }
    cout<<"--------------------------------------\n";
    cout<<" Top 10. Multiplication Leaderboards\n";
    cout<<"--------------------------------------\n";
    cout<<"Name\t\tScore \n";
    cout<<"------------------------------\n";
    for (i = 0;i<=limit;i++){
        if (i==0)cout<<"\033[1;33m";else cout<<"\033[0;37m";
        cout<<i+1<<".) "<<Users[i].Name<<"\t"<<Users[i].Mscore<<"\n";
    }
}
void User::Dlead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    Player tUser;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (Users[i].Dscore < Users[j].Dscore) {
                tUser = Users[i];
                Users[i] = Users[j];
                Users[j] = tUser;
            }
        }
    }
    cout<<"--------------------------------\n";
    cout<<" Top 10. Division Leaderboards\n";
    cout<<"--------------------------------\n";
    cout<<"Name\t\tScore \n";
    cout<<"------------------------------------\n";
    for (i = 0;i<=limit;i++){
        if (i==0)cout<<"\033[1;33m";else cout<<"\033[0;37m";
        cout<<i+1<<".) "<<Users[i].Name<<"\t"<<Users[i].Dscore<<"\n";
    }
}
void User::Blead(){
    int i,limit = (last < 10)? last:10;
    Player tUser;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (Users[i].Bscore < Users[j].Bscore) {
                tUser = Users[i];
                Users[i] = Users[j];
                Users[j] = tUser;
            }
        }
    }
    cout<<"\n------------------------------------------------------\n";
    cout<<"\t\tTop 10. Blitz Game Leaderboards\n";
    cout<<"------------------------------------------------------\n";
    cout<<"\tName\t\tHighest Score \n";
    cout<<"------------------------------------------------------\n";
    for (i = 0;i<=limit;i++){
        if (i==0)cout<<"\033[1;33m";else cout<<"\033[0;37m";
        cout<<i+1<<".) "<<Users[i].Name<<"\t"<<Users[i].Bscore<<"\n";
    }
}
float User::CompAve(Player u){
    return (u.Ascore + u.Sscore + u.Mscore + u.Dscore)/4.0;
}
void User::Sort(){
    Player tUser;
    int i,j;
    for (i = 0; i <last; i++){
        for (j = i + 1; j <=last; j++){
            if(CompAve(Users[i])<CompAve(Users[j])){
                tUser = Users[i];
                Users[i] = Users[j];
                Users[j] = tUser;
            }

        }
    }
}
void User::Save(){
    ofstream rec("Leaderboards.txt");
    if(rec.is_open()){
        for(int i=0;i<=last;i++){
            rec << Users[i].Name <<"\n"<< Users[i].Password<<"\n"
            <<Users[i].Ascore<<" "<<Users[i].Sscore<<" "
            <<Users[i].Mscore<<" "<<Users[i].Dscore<<" "
            <<Users[i].Bscore<<endl;
        }
    }
    rec.close();
}
void User::Retrieve(){
    ifstream rec("Leaderboards.txt");
    last = -1;
    while(true){
        Player Ruser;
        if(!getline(rec,Ruser.Name))break;
        if(!getline(rec,Ruser.Password))break;
        if(!(rec >> Ruser.Ascore >> Ruser.Sscore >> Ruser.Mscore
             >> Ruser.Dscore >> Ruser.Bscore)) break;
        rec.ignore();
        Users[++last] = Ruser;
    }
    rec.close();
}
void User::Fast(Player u){
    int x,y,ans, score =0,opr,i=user.Locate(u), num=1;
    time_t start,now;
    cout<<"Blitz game! Answer as many as you can under "<<TIME<<" seconds.\n";
    cout<<"Press Enter to start\n";
    getchar(); getchar();

    start = time(NULL);

    while(1){
        time(&now);
        if(difftime(now,start)>= TIME)break;
        opr = rand()%4+1;
        if(opr == 1){
            x = rand() %10+1;
            y = rand() %10+1;
            cout<<num<<".) "<<x<<" + "<<y<<" = ";
            cin>>ans;
            num++;
            if(ans== x+y){
                cout<<"\033[1;32mCorrect\033[0m\n";
                score++;}
            else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x+y <<endl;
        }
        else if(opr == 2){
            do{x = rand()%10+1;y = rand()%10+1;}while(x<y);
            cout<<num<< ".) "<<x<<" - "<<y<<" = ";
            cin>>ans;
            num++;
            if(ans== x-y){
                cout<<"\033[1;32mCorrect\033[0m\n";
                score++;}else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x-y<<endl;
        }
        else if(opr == 3){
            x = rand() %10+1;
            y = rand() %10+1;
            cout<<num<< ".) "<<x<<" x "<<y<<" = ";
            cin>>ans;
            num++;
            if(ans== x*y){
                cout<<"\033[1;32mCorrect\033[0m\n";
                score++;}
            else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x*y<<endl;
        }
        else {
            do{
            x = rand()%10+1;
            y = rand()%10+1;
            } while(x%y != 0);
            cout<<num<< ".) "<<x<<" / "<<y<<" = ";
            cin>>ans;
            num++;
            if(ans== x/y){
                cout<<"\033[1;32mCorrect\033[0m\n";
                score++;}
            else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x/y<<endl;
        }
    }
    Users[i].Bscore = score;
    system("cls");
    cout<<"Time's up! You got "<<score<<" correct answers.\n";
    system("pause");
}
