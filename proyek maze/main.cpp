#include <iostream>
#include <vector>
#include <chrono>
#include <conio.h>
using namespace std;


char mapp1[30][70] = {
    // Legend:
    // '#' = Wall, ' ' = Path, 'E' = Exit, 'B' = Button,'D' = door butuh key,'K' = key,'P' = portal;
    // '1' = Entrance Player 1, '2' = Entrance Player 2

    "#####################################################################",
    "#1             T              K    ###                             2#",
    "# ####### ### ######################## ######################T#######",
    "#      B    #                ###        ###                         #",
    "###########T################ ### ########### ################### ####",
    "#                 ###         ##            #               # ## ####",
    "# ################### ###########D########### ### ######### # ##   K#",
    "# ###               ###                     ###        ###     # ## #",
    "# ### ########################### ############################## ## #",
    "# ###         ###                T                          ####   B#",
    "# ########### ### ############# #####################################",
    "#             ##      ###          ###                      ####K  P#",
    "########D############## ### ############### ########### ###   D  ####",
    "#               ###      ##        B    ###               #### ######",
    "# ########### ########### ########### ##################### ## ######",
    "# ###       ###                                     ###    ### ######",
    "# ### ### ######## ################### ####################### ######",
    "#     ### ###        ###            ###                 ###    ######",
    "# ### ######## ######### ########## ######## ########## #### ########",
    "#P###         D                ###          #       ###      ########",
    "################# ##############################################B####",
    "###                                                         #### ####",
    "### ####################################################### #### ####",
    "### ####           ######K#################################         #",
    "###T#### #### #### ######T###################################### ####",
    "### #### ####B####T                                              ####",
    "###K     ######### ##################################################",
    "################## ##################################################",
    "#      B  D                                          D             E#",
    "#####################################################################"
};

void printmap(char currentmap[30][70]) {
    for (int i = 0; i < 30; ++i) {
        for (int j = 0; j < 70; ++j) {
            cout << currentmap[i][j];
        }
        cout << endl;
    }
}
void menuawal (int &menu){
    cout << "== maze ==\n1. play\n2. Leaderboard\n0. Exit\n";
    do {
        cout << ">> ";
        cin >> menu;
    }while (menu < 0 || menu >2);

}
void menulvl (int &level){
    cout << "== Level ==\n1. Level 1\n2. Level 2\n3. level 3\n0. back \n";
        do {
        cout << ">> ";
        cin >> level;
    }while (level < 0 || level >3);
}
void salincurrent(char mapp[30][70], char currentmap[30][70]){
     for (int i = 0; i < 30 ; i++){
        for (int j = 0; j<70;j++){
            currentmap[i][j]= mapp[i][j];
        }
    }

}
void letakb(vector <vector <int>> &lokasib,char currentmap[30][70]){
    for (int i = 0;i<30;i++){
        for (int j = 0;j<70;j++){
            if (currentmap [i][j]== 'B'){
                lokasib.push_back({i,j});
            }
        }
    }
}
void letakT(vector<vector<int>>&lokasit,char currentmap[30][70]){
     for (int i = 0;i<30;i++){
        for (int j = 0;j<70;j++){
            if (currentmap [i][j]== 'T'){
                lokasit.push_back({i,j});
            }
        }
     }
}
void penggunaanbutton (int px1,int py1,int px2,int py2,vector<vector<int>> lokasib,char currentmap[30][70],vector<vector<int>> lokasit){
    bool button = false;
    for (int i = 0; i < lokasib.size(); i++) {
        if ((px1 == lokasib[i][1] && py1 == lokasib[i][0]) || (px2 == lokasib[i][1] && py2 == lokasib[i][0])) {
            button = true;
        }
    }
    if (button) {
        for (int i = 0; i < lokasit.size(); i++) {
            currentmap[lokasit[i][0]][lokasit[i][1]] = ' ';
        }
    } else {
        for (int i = 0; i < lokasit.size(); i++) {
            currentmap[lokasit[i][0]][lokasit[i][1]] = 'T';
        }
    }

    for (int i = 0; i < lokasib.size(); i++) {
        if (currentmap[lokasib[i][0]][lokasib[i][1]] == ' ') {
            currentmap[lokasib[i][0]][lokasib[i][1]] = 'B';
        }
    }

}
void ambilkunci(int px1,int py1,int px2,int py2,char currentmap[30][70],int &kunci){
    if (currentmap [py1][px1+1]== 'K'){
        currentmap [py1][px1+1]= ' ';
        kunci++;
    }if (currentmap [py1][px1-1]== 'K'){
        currentmap [py1][px1-1]= ' ';
        kunci++;
    }if (currentmap [py1+1][px1]== 'K'){
        currentmap [py1+1][px1]= ' ';
        kunci++;
    }if (currentmap [py1-1][px1]== 'K'){
        currentmap [py1-1][px1]= ' ';
        kunci++;
    }if (currentmap [py2][px2+1]== 'K'){
        currentmap [py2][px2+1]= ' ';
        kunci++;
    }if (currentmap [py2][px2-1]== 'K'){
        currentmap [py2][px2-1]= ' ';
        kunci++;
    }if (currentmap [py2+1][px2]== 'K'){
        currentmap [py2+1][px2]= ' ';
        kunci++;
    }if (currentmap [py2-1][px2]== 'K'){
        currentmap [py2-1][px2]= ' ';
        kunci++;
    }
}

void bukapintu(int px1,int py1,int px2,int py2,char currentmap[30][70],int &kunci){
    if (currentmap [py1][px1+1]== 'D'){
        currentmap [py1][px1+1]= ' ';
        kunci--;
    }if (currentmap [py1][px1-1]== 'D'){
        currentmap [py1][px1-1]= ' ';
        kunci--;
    }if (currentmap [py1+1][px1]== 'D'){
        currentmap [py1+1][px1]= ' ';
        kunci--;
    }if (currentmap [py1-1][px1]== 'D'){
        currentmap [py1-1][px1]= ' ';
        kunci--;
    }if (currentmap [py2][px2+1]== 'D'){
        currentmap [py2][px2+1]= ' ';
        kunci--;
    }if (currentmap [py2][px2-1]== 'D'){
        currentmap [py2][px2-1]= ' ';
        kunci--;
    }if (currentmap [py2+1][px2]== 'D'){
        currentmap [py2+1][px2]= ' ';
        kunci--;
    }if (currentmap [py2-1][px2]== 'D'){
        currentmap [py2-1][px2]= ' ';
        kunci--;
    }

}
void masukportal(int &px1,int &py1,int &px2,int &py2,int portal[99][99],int jumlahportal,char currentmap[30][70]){
    for (int i=0;i<jumlahportal;i++){
        if(i%2==0){
            if ((px1 == portal[i][1]) && (py1 == portal[i][0])){
                px1 = portal [i+1][1];
                py1 = portal [i+1][0];
                currentmap[portal[i][0]][portal[i][1]]='P';
                return;
            }
            if (px2 == portal[i][1]&& py2 == portal[i][0]){
                px2 = portal [i+1][1];
                py2 = portal [i+1][0];
                currentmap[portal[i][0]][portal[i][1]]='P';
                return;
            }
            if (currentmap[portal[i+1][0]][portal[i+1][1]]==' ') {
                currentmap[portal[i+1][0]][portal[i+1][1]]='P';
                return;
            }
        }
        if(i%2==1){
            if ((px1 == portal[i][1]&& py1==portal[i][0])){
                px1 = portal [i-1][1];
                py1 = portal [i-1][0];
                currentmap[portal[i][0]][portal[i][1]]='P';
                return;
            }
            if (px2 == portal[i][1]&&py2==portal[i][0]){
                px2 = portal [i-1][1];
                py2 = portal [i-1][0];
                currentmap[portal[i][0]][portal[i][1]]='P';
                return;
            }
            if (currentmap[portal[i-1][0]][portal[i-1][1]]==' ') {
                currentmap[portal[i-1][0]][portal[i-1][1]]='P';
                return;
            }
        }
    }

}

int main()
{
int menu;
do{
    int level,py1,px1,py2,px2;
    menuawal(menu);
    char currentmap [30][70];
    char key;
    int portal[99][99];
    int kunci =0;
    int jumlahportal;
    bool flag=true,selesai=true;
    bool playerexit1 = false,playerexit2=false;
    vector <vector<int>> lokasib;
    vector <vector<int>> lokasit;

    if (menu == 1){
        lokasib.clear();
        menulvl(level);
        do{
            system("cls");
            if (level == 1){
                if (flag){

                    salincurrent(mapp1,currentmap);
                    printmap(currentmap);
                    px1 = 1;
                    py1= 1;
                    px2 = 67;
                    py2 = 1;
                    flag = false;
                    portal[0][0]=19;
                    portal[0][1]=1;
                    portal[1][0]=11;
                    portal[1][1]=67;
                    jumlahportal = 2;

                }else {
                    if (!playerexit1){

                        currentmap [py1][px1]= '1';
                    }
                    if (!playerexit2){

                        currentmap [py2][px2]= '2';
                    }
                    printmap(currentmap);

                }
            }
            letakb(lokasib,currentmap);
            letakT(lokasit,currentmap);

            key = getch();
            if (key =='w' && (currentmap[py1-1][px1]== ' ' || currentmap[py1-1][px1]== 'B'|| currentmap[py1-1][px1]== 'E'|| currentmap[py1-1][px1]== 'P')){
                currentmap[py1][px1]=' ';
                if (currentmap[py1-1][px1]== 'E'){
                    playerexit1=true;

                }else {
                    py1 = py1-1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);
                }

            }
            if (key =='s' && (currentmap[py1+1][px1]== ' '  || currentmap[py1+1][px1]== 'B'||currentmap[py1+1][px1]== 'E'|| currentmap[py1+1][px1]== 'P')){
                currentmap[py1][px1]=' ';
                if (currentmap[py1+1][px1]== 'E'){
                   playerexit1=true;
                }else {
                    py1 = py1+1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);
                }
            }
            if (key =='a' && (currentmap[py1][px1-1]== ' '|| currentmap[py1][px1-1]== 'B'||currentmap[py1][px1-1]== 'E'|| currentmap[py1][px1-1]== 'P')){
                currentmap[py1][px1]=' ';
                 if (currentmap[py1][px1-1]== 'E'){
                    playerexit1=true;
                }else{
                    px1 = px1-1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);
                }
            }
            if (key =='d' && (currentmap[py1][px1+1]== ' '||currentmap[py1][px1+1]== 'B'|| currentmap[py1][px1+1]== 'E'|| currentmap[py1][px1+1]== 'P')){
                currentmap[py1][px1]=' ';
                if (currentmap[py1][px1+1]== 'E'){
                    playerexit1=true;
                }else {
                    px1 = px1+1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);
                }
            }

            if (key =='i' && (currentmap[py2-1][px2]== ' ' || currentmap[py2-1][px2]== 'B'|| currentmap[py2-1][px2]=='E'|| currentmap[py2-1][px2]== 'P')){
                currentmap[py2][px2]=' ';
                if ( currentmap[py2-1][px2]=='E'){
                    playerexit2=true;
                }else {
                    py2 = py2-1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);
                }
            }
            if (key =='k' && (currentmap[py2+1][px2]== ' ' || currentmap[py2+1][px2]== 'B' || currentmap[py2+1][px2]=='E'|| currentmap[py2+1][px2]== 'P')){
                currentmap[py2][px2]=' ';
                if ( currentmap[py2+1][px2]=='E'){
                    playerexit2=true;

                }else {

                    py2 = py2+1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);
                }
            }
            if (key =='j' && (currentmap[py2][px2-1]== ' '|| currentmap[py2][px2-1]== 'B'||currentmap[py2][px2-1]=='E'|| currentmap[py2][px2-1]== 'P')){

                currentmap[py2][px2]= ' ';
                if (currentmap[py2][px2-1]=='E'){
                    playerexit2 = true;

                }else {
                    px2 = px2-1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);
                }
            }
            if (key =='l' && (currentmap[py2][px2+1]== ' '|| currentmap[py2][px2+1]== 'B' || currentmap[py2][px2+1]=='E' || currentmap[py2][px2+1]== 'P' )){

                currentmap[py2][px2]= ' ';
                if (currentmap[py2][px2+1]=='E'){
                    playerexit2=true;
                }else{

                    px2 = px2+1;
                    penggunaanbutton (px1,py1,px2,py2,lokasib,currentmap,lokasit);
                    masukportal(px1,py1,px2,py2,portal,jumlahportal,currentmap);

                }

            }if (key == 'e'){
                ambilkunci(px1,py1,px2,py2,currentmap,kunci);
                if (kunci >0){
                    bukapintu(px1,py1,px2,py2,currentmap,kunci);
                }
            }
            if (playerexit1 && playerexit2){
                selesai = false;
                cout << "anjai menang"<<endl;
                system("pause");
            }
        }while (selesai);
    }

}while (menu!=0);
    return 0;
}
