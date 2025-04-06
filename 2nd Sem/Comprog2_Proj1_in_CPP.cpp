//FLORES, Earl John C.
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
using namespace std;
#define MAX 50
#define items 5
#define TIME 10
int last;
struct Player{
    string Name;
    string Password;
    int Ascore;
    int Sscore;
    int Mscore;
    int Dscore;
    int Bscore;
};

class User{
protected:
Player Users[MAX];
float CompAve(int asc,int ssc,int msc,int dvc);
public:
    int Add(Player u);
    int Sub(Player u);
    int Mul(Player u);
    int Div(Player u);
    void Fast(Player u);
    int Menu();
    int GameMenu();
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
    void Save();
    void Retrieve();
    void Reloc(string n,string p, int aSc, int sSc, int mSc, int dSc,int bSc);
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
                int choice = user.GameMenu();
                if(choice == 7){user.Save(); break;}
                switch(choice){
                    case 1:
                        system("cls"); user.Lead(); break;
                    case 2:
                        system("cls"); cout<<"Addition Game\n";
                        srand(time(NULL));
                        n = user.Add(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl;
                        system("cls"); user.Alead(); user.Sort();
                        system("pause"); continue;
                    case 3:
                        system("cls"); cout<<"Subtraction Game\n";
                        srand(time(NULL));
                        n = user.Sub(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl;
                        system("cls"); user.Slead(); user.Sort();
                        system("pause"); continue;
                    case 4:
                        system("cls"); cout<<"Multiplication Game\n";
                        srand(time(NULL));
                        n = user.Mul(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl;
                        system("cls"); user.Mlead();user.Sort();
                        system("pause"); continue;
                    case 5:
                        system("cls"); cout<<"Division Game\n";
                        srand(time(NULL));
                        n = user.Div(user1);
                        cout<<"You got "<<n<<" out of "<<items<<endl;
                        system("cls"); user.Dlead();user.Sort();
                        system("pause"); continue;
                    case 6:
                        system("cls"); srand(time(NULL));user.Fast(user1);
                        system("cls");user.Blead();system("pause");user.Sort();continue;
                    default: cout<<"Enter 1-7 ONLY!\n";getchar();getchar();continue;
                    }
            }break;
        case 2:
            system("cls");
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
    if(last == MAX-1); return true; return false;
}
bool User::isEmpty(){
    if(last == -1); return true; return false;
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
        cout<<"Number of players is full\n";
        system("pause");
        return 0;
    }
    if(this->Locate(u)!=-1){
        cout<<"Player already exists!\n";
        return 0;
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
    cout<<"Welcome, "<<user1.Name<<endl;
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
        printf("\033[1;32mCorrect\033[0m\n");
        c++;}else cout<<"\033[1;31mWrong\033[0m, the correct answer is "<<x-y<<endl;
    }
    Users[i].Sscore = c;
    return c;
}
int User::Mul(Player u){
    int x, y, c = 0, ans, i = user.Locate(u);
    for(int i=1;i<=items;i++){
    x = rand() %50+1;
    y = rand() %50+1;
    cout<<i<< ".) "<<x<<" x "<<y<<" = ";
    cin>>ans;
    if(ans== x*y){
        printf("\033[1;32mCorrect\033[0m\n");
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
    printf("--------------------------\n");
    printf("Basic Arithmetic Game\n");
    printf("--------------------------\n");
    printf("1. Log-in\n2. Sign-in\n3. Save and Exit\n");
    printf("--------------------------\n");
    printf("Enter (1-3): "); cin>>op;
    return op;
}
int User::GameMenu(){
    int gop;
    printf("--------------------------\n");
    printf("Basic Arithmetic Game\n");
    printf("--------------------------\n");
    printf("1. Leaderboards\n");
    printf("2. Addition\n3. Subtraction\n4. Multiplication\n5. Division\n6. Blitz Game\n7. Return to Main Menu\n");
    printf("Enter (1-7): "); cin>>gop;
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
    for (i = 0;i<=limit;i++){
        ave = user.CompAve(Users[i].Ascore,Users[i].Sscore,Users[i].Mscore,Users[i].Dscore);
        cout<<i+1<<".) "<<Users[i].Name<<"\t"<<Users[i].Ascore<<"\t"<<Users[i].Sscore<<"\t"<<Users[i].Mscore<<"\t"<<Users[i].Dscore<<"\t"<<ave<<endl;
    }
    user.Blead();
    system("pause");

    return 1;
}
void User::Alead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    string tname, tpass;
    int tAdd, tSub, tMul, tDiv,tblit;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (Users[i].Ascore < Users[j].Ascore) {
                tname = Users[i].Name;
                Users[i].Name = Users[j].Name;
                Users[j].Name = tname;
                tAdd = adSc[i];
                adSc[i] = adSc[j];
                adSc[j] = tAdd;
                tSub = subSc[i];
                subSc[i] = subSc[j];
                subSc[j] = tSub;
                tMul = mulSc[i];
                mulSc[i] = mulSc[j];
                mulSc[j] = tMul;
                tDiv = divSc[i];
                divSc[i] = divSc[j];
                divSc[j] = tDiv;
                tblit = blitzSc[i];
                blitzSc[i] = blitzSc[j];
                blitzSc[j] = tblit;
            }
        }
    }
    printf("---------------------------------\n");
    printf(" Top 10. Addition Leaderboards\n");
    printf("---------------------------------\n");
    printf("Name\t\tScore \n");
    printf("------------------------------\n");
    for (i = 0;i<=limit;i++){
        if (i==0)printf("\033[1;33m");else printf("\033[0;37m");
        printf("%d.) %s\t%d\n", i+1, name[i],adSc[i]);
    }
}
void User::Slead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    char tname[31], tpass[31];
    int tAdd, tSub, tMul, tDiv,tblit;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (subSc[i] < subSc[j]) {
                strcpy(tname, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tname);
                strcpy(tpass, password[i]);
                strcpy(password[i], password[j]);
                strcpy(password[j], tpass);

                tAdd = adSc[i];
                adSc[i] = adSc[j];
                adSc[j] = tAdd;
                tSub = subSc[i];
                subSc[i] = subSc[j];
                subSc[j] = tSub;
                tMul = mulSc[i];
                mulSc[i] = mulSc[j];
                mulSc[j] = tMul;
                tDiv = divSc[i];
                divSc[i] = divSc[j];
                divSc[j] = tDiv;
                tblit = blitzSc[i];
                blitzSc[i] = blitzSc[j];
                blitzSc[j] = tblit;
            }
        }
    }
    cout<<"------------------------------------\n";
    cout<<" Top 10. Substraction Leaderboards\n";
    cout<<"------------------------------------\n";
    cout<<"Name\t\tScore \n";
    cout<<"---------------------------------\n";
    for (i = 0;i<=limit;i++){
        if (i==0)printf("\033[1;33m");else printf("\033[0;37m");
        printf("%d.) %s\t%d\n", i+1, name[i],subSc[i]);
    }
    return 1;
}
void User::Mlead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    char tname[31], tpass[31];
    int tAdd, tSub, tMul, tDiv,tblit;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (mulSc[i] < mulSc[j]) {
                strcpy(tname, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tname);
                strcpy(tpass, password[i]);
                strcpy(password[i], password[j]);
                strcpy(password[j], tpass);

                tAdd = adSc[i];
                adSc[i] = adSc[j];
                adSc[j] = tAdd;
                tSub = subSc[i];
                subSc[i] = subSc[j];
                subSc[j] = tSub;
                tMul = mulSc[i];
                mulSc[i] = mulSc[j];
                mulSc[j] = tMul;
                tDiv = divSc[i];
                divSc[i] = divSc[j];
                divSc[j] = tDiv;
                tblit = blitzSc[i];
                blitzSc[i] = blitzSc[j];
                blitzSc[j] = tblit;
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
        printf("%d.) %s\t%d\n", i+1, name[i],mulSc[i]);
    }
}
void User::Dlead(){
    system("cls");
    int i,limit = (last < 10)? last:10;
    char tname[31], tpass[31];
    int tAdd, tSub, tMul, tDiv,tblit;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (divSc[i] < divSc[j]) {
                strcpy(tname, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tname);
                strcpy(tpass, password[i]);
                strcpy(password[i], password[j]);
                strcpy(password[j], tpass);

                tAdd = adSc[i];
                adSc[i] = adSc[j];
                adSc[j] = tAdd;
                tSub = subSc[i];
                subSc[i] = subSc[j];
                subSc[j] = tSub;
                tMul = mulSc[i];
                mulSc[i] = mulSc[j];
                mulSc[j] = tMul;
                tDiv = divSc[i];
                divSc[i] = divSc[j];
                divSc[j] = tDiv;
                tblit = blitzSc[i];
                blitzSc[i] = blitzSc[j];
                blitzSc[j] = tblit;
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
        printf("%d.) %s\t%d\n", i+1, name[i],divSc[i]);
    }
}
void User::Blead(){
    int i,limit = (last < 10)? last:10;
    char tname[31], tpass[31];
    int tAdd, tSub, tMul, tDiv,tblit;
    for (i = 0; i < last; i++) {
        for (int j = i + 1; j <= last; j++) {
            if (blitzSc[i] < blitzSc[j]) {
                strcpy(tname, name[i]);
                strcpy(name[i], name[j]);
                strcpy(name[j], tname);
                strcpy(tpass, password[i]);
                strcpy(password[i], password[j]);
                strcpy(password[j], tpass);

                tAdd = adSc[i];
                adSc[i] = adSc[j];
                adSc[j] = tAdd;
                tSub = subSc[i];
                subSc[i] = subSc[j];
                subSc[j] = tSub;
                tMul = mulSc[i];
                mulSc[i] = mulSc[j];
                mulSc[j] = tMul;
                tDiv = divSc[i];
                divSc[i] = divSc[j];
                divSc[j] = tDiv;
                tblit = blitzSc[i];
                blitzSc[i] = blitzSc[j];
                blitzSc[j] = tblit;
            }
        }
    }
    cout<<"\n------------------------------------------------------\n";
    cout<<"\t\tTop 10. Blitz Game Leaderboards\n";
    cout<<"------------------------------------------------------\n";
    cout<<"\tName\t\tHighest Score \n");
    cout<<("------------------------------------------------------\n";
    for (i = 0;i<=limit;i++){
        if (i==0)cout<<"\033[1;33m";else cout<<"\033[0;37m" ;
        printf("%d.) %s\t\t%d\n", i+1, name[i],blitzSc[i]);
    }
}
float User::CompAve(int asc,int ssc,int msc,int dvc){
    return (asc + ssc + msc + dvc)/4.0;
}
void User::Sort(){
    char tname[31],tpass[31];
    int tAdd,tSub,tMul,tDiv, tblit,i,j;
    for (i = 0; i <last; i++){
        for (j = i + 1; j <=last; j++){
            if(compAve(adSc[i],subSc[i],mulSc[i],divSc[i])<compAve(adSc[j],subSc[j],mulSc[j],divSc[j])){
                strcpy(tname, name[i]);
                strcpy(name[i],name[j]);
                strcpy(name[j], tname);

                strcpy(tpass, password[i]);
                strcpy(password[i],password[j]);
                strcpy(password[j],tpass);

                tAdd = adSc[i];
                adSc[i] = adSc[j];
                adSc[j] = tAdd;

                tSub = subSc[i];
                subSc[i] = subSc[j];
                subSc[j] = tSub;

                tMul = mulSc[i];
                mulSc[i] = mulSc[j];
                mulSc[j] = tMul;

                tDiv = divSc[i];
                divSc[i] = divSc[j];
                divSc[j] = tDiv;

                tblit = blitzSc[i];
                blitzSc[i]=blitzSc[j];
                blitzSc[j]=tblit;
            }
        }
    }

}
void User::Save(){
    FILE *fp = fopen("leaderboards.txt","w+");
    if (fp == NULL){
        printf("File not found.\n");
        system("pause");
    }else{
        for (int i = 0; i <=last; i++){
            fprintf(fp,"%s\n%s\n%d %d %d %d %d\n", name[i],password[i],adSc[i],subSc[i],mulSc[i],divSc[i],blitzSc[i]);
        }
    fclose(fp);
    }
}
void User::Retrieve(){
    FILE *fp = fopen("leaderboards.txt","r+");
    char n[31],p[31];
    int aSc,sSc,mSc,dSc,bSc;
    if(fp == NULL){
        printf("No player yet\n");
        return;
    }
    while(!feof(fp)){
        fscanf(fp, " %[^\n]\n%[^\n]\n%d %d %d %d %d\n",n, p,&aSc,&sSc,&mSc,&dSc,&bSc);
        reloc(n,p,aSc,sSc,mSc,dSc,bSc);
    }
    fclose(fp);
}
void User::Reloc(char n[], char p[],int aSc, int sSc, int mSc, int dSc,int bSc){
    last++;
    strcpy(name[last], n);
    strcpy(password[last], p);
    adSc[last] = aSc;
    subSc[last] = sSc;
    mulSc[last] = mSc;
    divSc[last] = dSc;
    blitzSc[last] = bSc;
}
void User::Fast(Player u){
    int x,y,ans, score =0,opr,i=user.Locate(u);
    time_t start,now;
    printf("Blitz game! Answer as many as you can under %d seconds.\n",TIME);
    printf("Press Enter to start\n");
    getchar(); getchar();

    start = time(NULL);

    while(1){
        time(&now);
        if(difftime(now,start)>= TIME)break;
        opr = rand()%4+1;
        if(opr == 1){
            x = rand()%10+1;
            y = rand()%10+1;
            cout<<i<< ".) "<<x<<" + "<<y<<" = "; cin>>ans;
            if(ans == x + y){
                score++;printf("\033[1;32mCorrect\033[0m\n");}
            else printf("\033[1;31mWrong\033[0m, the correct answer is %d\n", x+y);
        }
        else if(opr == 2){
            do{x = rand()%10+1;y = rand()%10+1;}while(x<y);
            cout<<i<< ".) "<<x<<" - "<<y<<" = "; cin>>ans;
            if(ans == x - y){
                score++;printf("\033[1;32mCorrect\033[0m\n");}
            else printf("\033[1;31mWrong\033[0m, the correct answer is %d\n", x-y);
        }
        else if(opr == 3){
            x = rand()%10+1;
            y = rand()%10+1;
            cout<<i<< ".) "<<x<<" x "<<y<<" = "; cin>>ans;
            if(ans == x * y){
                score++;cout"\033[1;32mCorrect\033[0m\n";}
            else printf("\033[1;31mWrong\033[0m, the correct answer is %d\n", x*y);
        }
       else {
            x = rand()%10+1;
            y = rand()%10+1;
            do{
            x = rand()%10+1;
            y = rand()%10+1;
            } while(x%y != 0);
            cout<<i<< ".) "<<x<<" / "<<y<<" = "; cin>>ans;
            if(ans == x / y){
                score++;printf("\033[1;32mCorrect\033[0m\n");}
            else printf("\033[1;31mWrong\033[0m, the correct answer is %d\n", x/y);
        }
    }
    Users[i].blitzSc = score;
    system("cls");
    printf("Time's up! You got %d correct answers.\n",score);
    system("pause");
}
