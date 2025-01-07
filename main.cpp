#include <iostream>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <iomanip>
#include <string>
#include <thread>// for sleep
#include <stdlib.h>// for system
#include <iomanip>// for setw
#include <fstream>
#include <chrono>
#include <algorithm>
#include <map>


using namespace std;
using namespace std::chrono;

vector<string> rainbowColors = {
    "\033[31m", // Red
    "\033[33m", // Yellow
    "\033[32m", // Green
    "\033[36m", // Cyan
    "\033[34m", // Blue
    "\033[35m", // Magenta
    "\033[0m"   // Reset
};

// Function to clear the console
void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to print the big word "MAZE" centered on the screen
void printBigWordCentered() {
    vector<vector<string>> patterns = {
        { // M
            "*     * ",
            "**   ** ",
            "* * * * ",
            "*  *  * ",
            "*     * "
        },
        { // A
            "  ***  ",
            " *   * ",
            " ***** ",
            " *   * ",
            " *   * "
        },
        { // Z
            " ***** ",
            "    *  ",
            "   *   ",
            "  *    ",
            " ***** "
        },
        { // E
            " ***** ",
            " *     ",
            " ****  ",
            " *     ",
            " ***** "
        }
    };

    // Assuming default console dimensions (80x24)
    const int consoleWidth = 80;
    const int consoleHeight = 24;

    // Calculate the total width of the word "MAZE"
    int wordWidth = 0;
    for (const auto &pattern : patterns) {
        wordWidth += pattern[0].size() + 1; // Add 1 space between letters
    }

    // Calculate offsets
    int horizontalOffset = (consoleWidth - wordWidth) / 2;
    int verticalOffset = (consoleHeight - 5) / 2; // 5 rows for the word

    // Print blank lines for vertical centering
    for (int i = 0; i < verticalOffset; ++i) {
        cout << endl;
    }

    // Print each row of the big word
    for (int row = 0; row < 5; ++row) { // 5 rows for each letter
        cout << string(horizontalOffset, ' '); // Print spaces for horizontal centering
        int colorIndex = 0;
        for (const auto &pattern : patterns) {
            cout << rainbowColors[colorIndex % rainbowColors.size()]
                 << pattern[row] << " ";
            ++colorIndex;
        }
        cout << rainbowColors.back() << endl; // Reset color
    }
}


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
    "# ########### ########### ########### ##################### ##      #",
    "# ###       ###                                     ###    ### ######",
    "# ### ### ######## ################### #######################  #####",
    "#     ### ###        ###            ###                 ###     #####",
    "# ### ######## ######### ########## ######## ########## #### ##     #",
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
char mapp2[30][70] = {
    "#####################################################################",
    "#1       D             #P           ###    K     D                 2#",
    "### ########### ### ############### ### ######## ########### ### ####",
    "#   ###K        ###       ###            ###             ###B###   K#",
    "# ################### ######### ########### ######T##################",
    "# ###B           ##   ##      B    ##         ###           #P   DDK#",
    "# ############## ### ####### ###### ######### ### ######### ###### ##",
    "# ###        ###           ###      ###       ###   K###           ##",
    "# ### ###### #############P###### ####################### ###### ####",
    "# ###T##P              B###               ###               ##     B#",
    "# ### ################### ### #####D##### ###T############# ######T##",
    "#      ###    ###            ###P   ###B              ###    ###    #",
    "#####################################################################",
    "#P      T        ##                P###     P###K         # ###    P#",
    "### ###########  ## ###################T###########D#####T#####T#####",
    "#   ###K        P##            ###            ###                ####",
    "# ### ####################### ####### ######## ###############D######",
    "# #               ###           ###      ###           ###          #",
    "# # ############## ### ######## ##### ######## ########### ##########",
    "#    B##          ###     D                 #                 #    P#",
    "###D#########D############################# ### ################K####",
    "#K    #     #                  ###B             ###P   D       ###  #",
    "### ##### ### ####################### ########################P######",
    "#   ###       ######D   K  ######### ################### ## ###   DE#",
    "###T###############  ##### #       ### ####                  K#P#####",
    "###     ###########   B##   ## ### ### ######## #####################",
    "#######D###########T##### # # ###               #    ###            #",
    "###K                ##### ### ################# ######### ########T##",
    "#P      B         P###               D           ##P           D   P#",
    "#####################################################################"
};
// map ke 3
char mapp3[30][70] = {
    // Legend:
    // '#' = Wall, ' ' = Path, 'E' = Exit, 'B' = Button, 'D' = Door (needs key), 'K' = Key, 'P' = Portal
    // '1' = Entrance Player 1, '2' = Entrance Player 2

    "#####################################################################",
    "#1            K                ###                  D              2#",
    "# ########### ################### ########### ##################### #",
    "#             #    B         ###      ###   ###         ###        ##",
    "### ######### ####### #####  ### ##### ### ####### ##### ############",
    "#   ###              ###   T     ###           ###   T             ##",
    "# ##### ############ ######### ########## ######## ########## #######",
    "#         ###    ###    ###                     ###          ###   ##",
    "######### ### ####### ##### ####################### ######### #######",
    "#      B     ###          ###       T             ###         B   ###",
    "# ############### ########################### ######## ########## ###",
    "#              ###         K    ####     ###         ###       P   ##",
    "###### ########### ########### ##### ####### ########### ############",
    "#       ###        ###  ###  B  ###           ###           #########",
    "# ##### ### ########## ########### ########## ######## ########### ##",
    "# ###             ###       T                ###       ###         ##",
    "# ### ### ######################## ########## ##### ### ######### ###",
    "# ### ###                ###      ###          ### ###    ###   #####",
    "# ### ######## ########### #### ######## ######### ##### #####    ###",
    "#         ###            ###      ###                 ###    ########",
    "###### #################### ###################### ##################",
    "#    P       ####   ######       ###            ###         ###   ###",
    "########### ##### ########### ########### ######### ######### #######",
    "#       ###       T        ###   K              ###      T     ######",
    "########### ##################### ############################# #####",
    "#          ###   B                ###   ####    ###       ###    E###",
    "# ######## ######## ################## ################# ############",
    "# ###      ###      ###             B       T       ###           ###",
    "# ### ######################## ########### ########### ##############",
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
// ACE : tulisan maze di hapus karna di ganti pakai yg gede
void menuawal (int &menu){
    cout<< rainbowColors[2] <<"                                1. Play\n                                2. Leaderboard\n                                0. Exit\n";
    do {
        cout << "                                >> ";
        cin >> menu;
    }while (menu < 0 || menu >2);

}
void menulvl (int &level){
    system("cls");
    printBigWordCentered();
    cout << rainbowColors[2]<< "                                == Level ==\n                                1. Level 1\n                                2. Level 2\n                                3. Level 3\n                                0. Back \n";
        do {
        cout << "                                >> ";
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
void ambilkunci(int px1,int py1,int px2,int py2,char currentmap[30][70],int &kunci1,int &kunci2){
    if (currentmap [py1][px1+1]== 'K'){
        currentmap [py1][px1+1]= ' ';
        kunci1++;
    }if (currentmap [py1][px1-1]== 'K'){
        currentmap [py1][px1-1]= ' ';
        kunci1++;
    }if (currentmap [py1+1][px1]== 'K'){
        currentmap [py1+1][px1]= ' ';
        kunci1++;
    }if (currentmap [py1-1][px1]== 'K'){
        currentmap [py1-1][px1]= ' ';
        kunci1++;
    }if (currentmap [py2][px2+1]== 'K'){
        currentmap [py2][px2+1]= ' ';
        kunci2++;
    }if (currentmap [py2][px2-1]== 'K'){
        currentmap [py2][px2-1]= ' ';
        kunci2++;
    }if (currentmap [py2+1][px2]== 'K'){
        currentmap [py2+1][px2]= ' ';
        kunci2++;
    }if (currentmap [py2-1][px2]== 'K'){
        currentmap [py2-1][px2]= ' ';
        kunci2++;
    }
}

void bukapintu1(int px1,int py1,int px2,int py2,char currentmap[30][70],int &kunci1){
    if (currentmap [py1][px1+1]== 'D'){
        currentmap [py1][px1+1]= ' ';
        kunci1--;
    }if (currentmap [py1][px1-1]== 'D'){
        currentmap [py1][px1-1]= ' ';
        kunci1--;
    }if (currentmap [py1+1][px1]== 'D'){
        currentmap [py1+1][px1]= ' ';
        kunci1--;
    }if (currentmap [py1-1][px1]== 'D'){
        currentmap [py1-1][px1]= ' ';
        kunci1--;

    }
}
void bukapintu2(int px1,int py1,int px2,int py2,char currentmap[30][70],int &kunci2){
    if (currentmap [py2][px2+1]== 'D'){
        currentmap [py2][px2+1]= ' ';
        kunci2--;
    }if (currentmap [py2][px2-1]== 'D'){
        currentmap [py2][px2-1]= ' ';
        kunci2--;
    }if (currentmap [py2+1][px2]== 'D'){
        currentmap [py2+1][px2]= ' ';
        kunci2--;
    }if (currentmap [py2-1][px2]== 'D'){
        currentmap [py2-1][px2]= ' ';
        kunci2--;
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

struct highscoresentry{
    string name;
    float time;
};

map <int, vector <highscoresentry>> highscoresperlevel;

bool comparescores(const highscoresentry &a, const highscoresentry &b){
    return a.time < b.time;
}

void savehighscores(const string &filename){
    ofstream file(filename);
    if(file.is_open()){
        for(const auto &levelscores : highscoresperlevel){
            file << "Level " << levelscores.first << ":\n";
            for(const auto &entry : levelscores.second){
                file << entry.name << " " << entry.time << "\n";
            }
            file << "\n";
        }
    }
    file.close();
}

void loadhighscores(const string &filename){
    ifstream file(filename);
    if(file.is_open()){
        string line;
        while(getline(file, line)){
            if(line.find("Level ") == 0){
                int level = stoi(line.substr(6));
                highscoresperlevel[level] = {};
                while(getline(file, line) && !line.empty()){
                    highscoresentry entry;
                    stringstream ss(line);
                    if(ss >> entry.name >> entry.time){
                        highscoresperlevel[level].push_back(entry);
                    }
                }
            }
        }
        file.close();
    }
}

void tophighscores(int level){
    vector <highscoresentry> &highscores = highscoresperlevel[level];
    sort(highscores.begin(), highscores.end(), comparescores);
    cout << "== Highscores Level " << level << " ==\n" ;
    int count = min((int)highscores.size(), 5);
    for(int i = 0; i < count; i++){
        cout << i + 1 << ". " << highscores[i].name << " " << highscores[i].time << " second\n";
    }
    cout << "Press any key to exit\n";
    getch();
    system("cls");
    printBigWordCentered();
}

int main()
{

    clearConsole();
    printBigWordCentered();
    int menu;
    string highscorefilename = "highscores.txt";
    loadhighscores(highscorefilename);
do{
    int level,py1,px1,py2,px2;
    menuawal(menu);
    char currentmap [30][70];
    char key;
    int portal[99][99];
    int kunci1 =0,kunci2=0;
    int jumlahportal;
    bool flag=true,selesai=true;
    bool playerexit1 = false,playerexit2=false;
    vector <vector<int>> lokasib;
    vector <vector<int>> lokasit;
    string name;

    if (menu == 1){
        lokasib.clear();
        menulvl(level);
        auto start = high_resolution_clock::now();
        do{
            if(level == 0){
                system("cls");
                printBigWordCentered();
                break;
            }
            system("cls");
            cout << "Player 1 key: " << setw(39) << left<< kunci1 << "Player 2 key: "  <<  kunci2<<endl;
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
             if (level == 2){
                if (flag){
                    salincurrent(mapp2,currentmap);
                    printmap(currentmap);
                    px1 = 1;
                    py1= 1;
                    px2 = 67;
                    py2 = 1;
                    flag = false;
                    portal[0][0]=9;
                    portal[0][1]=8;
                    portal[1][0]=1;
                    portal[1][1]=24;
                    portal[2][0]=8;
                    portal[2][1]=26;
                    portal[3][0]=5;
                    portal[3][1]=61;
                    portal[4][0]=11;
                    portal[4][1]=32;
                    portal[5][0]=13;
                    portal[5][1]=1;
                    portal[6][0]=15;
                    portal[6][1]=16;
                    portal[7][0]=13;
                    portal[7][1]=67;
                    portal[8][0]=13;
                    portal[8][1]=44;
                    portal[9][0]=28;
                    portal[9][1]=1;
                    portal[10][0]=13;
                    portal[10][1]=35;
                    portal[11][0]=19;
                    portal[11][1]=67;
                    portal[12][0]=28;
                    portal[12][1]=18;
                    portal[13][0]=21;
                    portal[13][1]=51;
                    portal[14][0]=22;
                    portal[14][1]=62;
                    portal[15][0]=28;
                    portal[15][1]=51;
                    portal[16][0]=28;
                    portal[16][1]=67;
                    portal[17][0]=24;
                    portal[17][1]=63;
                    jumlahportal = 18;
                }
                else {
                    if (!playerexit1){
                        currentmap [py1][px1]= '1';
                    }
                    if (!playerexit2){
                        currentmap [py2][px2]= '2';
                    }
                    printmap(currentmap);
                }
            }
            if (level == 3){
                    if (flag){
                    salincurrent(mapp3, currentmap);
                    printmap(currentmap);
                    px1 = 1;
                    py1= 1;
                    px2 = 67;
                    py2 = 1;
                    flag = false;
                    portal[0][0] = 11;
                    portal[0][1] = 5;
                    portal[1][0] = 21;
                    portal[1][1] = 64;
                    jumlahportal = 2;
                    }
                    else {
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
                ambilkunci(px1,py1,px2,py2,currentmap,kunci1,kunci2);
                if (kunci1 >0){
                    bukapintu1(px1,py1,px2,py2,currentmap,kunci1);
                }
                if (kunci2 >0){
                    bukapintu2(px1,py1,px2,py2,currentmap,kunci2);
                }
            }if (key == 'x'){
                system("cls");
                printBigWordCentered();
                selesai = false;
            }
            if (playerexit1 && playerexit2){
                auto endd = high_resolution_clock::now();
                selesai = false;
                duration <float> time = endd - start;
                cout << "Anjay menang"<<endl;
                cout << "Player name: ";
                cin >> name;
                highscoresperlevel[level].push_back({name, time.count()});
                sort(highscoresperlevel[level].begin(), highscoresperlevel[level].end(), comparescores);
                savehighscores(highscorefilename);
                system("pause");
            }
        }while ( selesai);
    }
    else if(menu == 2){
        int chooselevel;

        do{
            // menampilkan tulisan maze besar sehabis memilih level
            system("cls");
            printBigWordCentered();
            cout << rainbowColors[2]<< "                                == Highscores ==\n                                1. Level 1\n                                2. Level 2\n                                3. Level 3\n                                0. Back\n                                >> ";
            cin >> chooselevel;
        }while(chooselevel < 0 || chooselevel > 3);
        if(chooselevel == 0){
            system("cls");
            printBigWordCentered();
            continue;
        }
        else if(chooselevel >= 1 && chooselevel <= 3){
            tophighscores(chooselevel);
            continue;
        }
        else{
            system("pause");
            system("cls");
            printBigWordCentered();
            continue;
        }
    }

}while (menu!=0);
savehighscores(highscorefilename);
    return 0;
}
