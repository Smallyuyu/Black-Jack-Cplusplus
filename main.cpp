#include <bits/stdc++.h>
#include <windows.h>
#include "PlayerPoint.h"
#include "PlayerPoint.cpp"
using namespace std;
#define chen ios::sync_with_stdio(0);cin.tie(0)

struct rk{
    int label;
    int money;
};

map<int,int> mp = {
    {10 , 1},
    {11 , 1},
    {12 , 1},
    {13 , 1}
};

map<int,string> card_to_imgur = {
    {1 , "A"},
    {2 , "2"},
    {3 , "3"},
    {4 , "4"},
    {5 , "5"},
    {6 , "6"},
    {7 , "7"},
    {8 , "8"},
    {9 , "9"},
    {10 , "10"},
    {11 , "J"},
    {12 , "Q"},
    {13 , "K"}
};

map<int,int> card_to_point = {
    {1 , 11},
    {2 , 2},
    {3 , 3},
    {4 , 4},
    {5 , 5},
    {6 , 6},
    {7 , 7},
    {8 , 8},
    {9 , 9},
    {10 , 10},
    {11 , 10},
    {12 , 10},
    {13 , 10}
};

void gotoxy(int xpos, int ypos)
{
  COORD scrn;
  HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
  scrn.X = xpos; scrn.Y = ypos;
  SetConsoleCursorPosition(hOuput,scrn);
}

void printmenu(int i){
    gotoxy(50, 1);
    cout<<"Player "<<i + 1;
    cout<<"   ";
    gotoxy(50,2);
    cout<<"1. Hit";
    gotoxy(50,3);
    cout<<"2. Stand";
}

void print_card(int i , int size, int card){
    gotoxy((size - 1) * 9,i * 9 + 3);
    cout<<"O-------O";
    gotoxy((size - 1) * 9,i * 9 + 4);
    cout<<"|       |";
    gotoxy((size - 1) * 9,i * 9 + 5);
    cout<<"|       |";
    gotoxy((size - 1) * 9,i * 9 + 6);
    cout<<"|       |";
    gotoxy((size - 1) * 9,i * 9 + 7);
    cout<<"|       |";
    gotoxy((size - 1) * 9,i * 9 + 8);
    cout<<"|       |";
    gotoxy((size - 1) * 9,i * 9 + 9);
    cout<<"O-------O";
    if(card % 13 + 1 == 10){
        gotoxy((size - 1) * 9 + 1,i * 9 + 4);
        cout<<"10";
        gotoxy(size * 9 - 3,i * 9 + 8);
        cout<<"10";
    }
    else{
        gotoxy((size - 1) * 9 + 1,i * 9 + 4);
        cout<<card_to_imgur[card % 13 + 1];
        gotoxy(size * 9 - 2,i * 9 + 8);
        cout<<card_to_imgur[card % 13 + 1];
    }
    if(card % 4 == 0){
        gotoxy((size - 1) * 9 + 4,i * 9 + 5);
        cout<<"O";
        gotoxy((size - 1) * 9 + 3,i * 9 + 6);
        cout<<"O";
        gotoxy((size - 1) * 9 + 5,i * 9 + 6);
        cout<<"O";
        gotoxy((size - 1) * 9 + 3,i * 9 + 7);
        cout<<"/";
        gotoxy((size - 1) * 9 + 4,i * 9 + 7);
        cout<<"_";
        gotoxy((size - 1) * 9 + 5,i * 9 + 7);
        cout<<"\\";
    }
    else if(card % 4 == 1){
        gotoxy((size - 1) * 9 + 3,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 5,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 3,i * 9 + 7);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 5,i * 9 + 7);
        cout<<"/";
    }
    else if(card % 4 == 2){
        gotoxy((size - 1) * 9 + 4,i * 9 + 5);
        cout<<"_";
        gotoxy((size - 1) * 9 + 3,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 5,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 2,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 6,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 2,i * 9 + 6);
        cout<<"|";
        gotoxy((size - 1) * 9 + 6,i * 9 + 6);
        cout<<"|";
        gotoxy((size - 1) * 9 + 3,i * 9 + 7);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 5,i * 9 + 7);
        cout<<"/";
    }
    else if (card % 4 == 3){
        gotoxy((size - 1) * 9 + 4,i * 9 + 4);
        cout<<"_";
        gotoxy((size - 1) * 9 + 3,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 5,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 2,i * 9 + 6);
        cout<<"/";
        gotoxy((size - 1) * 9 + 6,i * 9 + 6);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 3,i * 9 + 6);
        cout<<"_";
        gotoxy((size - 1) * 9 + 5,i * 9 + 6);
        cout<<"_";
        gotoxy((size - 1) * 9 + 3,i * 9 + 7);
        cout<<"/";
        gotoxy((size - 1) * 9 + 5,i * 9 + 7);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 4,i * 9 + 7);
        cout<<"_";
    }
}

void print_dealer_card(int i, int size ,int card){
    if(size >= 3 && size <= 4) i++;
    else if(size >= 5) i = i + 2;
    if(size % 2 == 1) size = 1;
    else size = 2;
    gotoxy((size - 1) * 9 + 90,i * 9 + 3);
    cout<<"O-------O";
    gotoxy((size - 1) * 9 + 90,i * 9 + 4);
    cout<<"|       |";
    gotoxy((size - 1) * 9 + 90,i * 9 + 5);
    cout<<"|       |";
    gotoxy((size - 1) * 9 + 90,i * 9 + 6);
    cout<<"|       |";
    gotoxy((size - 1) * 9 + 90,i * 9 + 7);
    cout<<"|       |";
    gotoxy((size - 1) * 9 + 90,i * 9 + 8);
    cout<<"|       |";
    gotoxy((size - 1) * 9 + 90,i * 9 + 9);
    cout<<"O-------O";
    if(card % 13 + 1 == 10){
        gotoxy((size - 1) * 9 + 1 + 90,i * 9 + 4);
        cout<<"10";
        gotoxy(size * 9 - 3 + 90,i * 9 + 8);
        cout<<"10";
    }
    else{
        gotoxy((size - 1) * 9 + 1 + 90,i * 9 + 4);
        cout<<card_to_imgur[card % 13 + 1];
        gotoxy(size * 9 - 2 + 90,i * 9 + 8);
        cout<<card_to_imgur[card % 13 + 1];
    }
    if(card % 4 == 0){
        gotoxy((size - 1) * 9 + 4 + 90,i * 9 + 5);
        cout<<"O";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 6);
        cout<<"O";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 6);
        cout<<"O";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 7);
        cout<<"/";
        gotoxy((size - 1) * 9 + 4 + 90,i * 9 + 7);
        cout<<"_";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 7);
        cout<<"\\";
    }
    else if(card % 4 == 1){
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 7);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 7);
        cout<<"/";
    }
    else if(card % 4 == 2){
        gotoxy((size - 1) * 9 + 4 + 90,i * 9 + 5);
        cout<<"_";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 2 + 90,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 6 + 90,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 2 + 90,i * 9 + 6);
        cout<<"|";
        gotoxy((size - 1) * 9 + 6 + 90,i * 9 + 6);
        cout<<"|";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 7);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 7);
        cout<<"/";
    }
    else if (card % 4 == 3){
        gotoxy((size - 1) * 9 + 4 + 90,i * 9 + 4);
        cout<<"_";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 5);
        cout<<"/";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 5);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 2 + 90,i * 9 + 6);
        cout<<"/";
        gotoxy((size - 1) * 9 + 6 + 90,i * 9 + 6);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 6);
        cout<<"_";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 6);
        cout<<"_";
        gotoxy((size - 1) * 9 + 3 + 90,i * 9 + 7);
        cout<<"/";
        gotoxy((size - 1) * 9 + 5 + 90,i * 9 + 7);
        cout<<"\\";
        gotoxy((size - 1) * 9 + 4 + 90,i * 9 + 7);
        cout<<"_";
    }
}

vector<int> shuffle(vector<int> arr){
    for(int i = 0 ; i < 52 ; i++){
        arr.push_back(i + 1);
    }

    for(int i = 0 ; i < 52 ; i++){
        Sleep(rand()%100);
        int r = rand() % (52);
        int t = arr[i];
        arr[i] = arr[r];
        arr[r] = t;
    }
    return arr;
}

int main(){
    //chen;
    int rounds,players;
    int flag1 = 0, flag2 = 0;

    while(flag1 == 0){
        gotoxy(0,0);
        cout<<"How Many Rounds? ";
        cin>>rounds;
        if(rounds > 0 && rounds < 4){
            flag1 = 1;
        }

    }

    while(flag2 == 0){
        gotoxy(0,1);
        cout<<"How Many Players? ";
        cin>>players;
        if(players > 1 && players < 5){
            flag2 = 1;
        }
    }
    //清屏
    for(int i = 0 ; i < 116 ; i++){
        gotoxy(0, i);
        cout<<"                                                      ";
    }

    //Reloading
    gotoxy(0,0);
    cout<<"Reloading";
    for(int i = 0 ; i < 3 ; i++){
        Sleep(700);
        cout<<" .";
    }
    Sleep(700);

    //清屏
    for(int i = 0 ; i < 116 ; i++){
        gotoxy(0, i);
        cout<<"                                                      ";
    }

    //找莊家
    int dealer_num = rand() % (players);
    playerpoint player[players];
    playerpoint dealer;
    int op,lower = 1000;
    vector<int> pokercard;
    vector<int> arr;
    int max;
    int min;
    int cnt;
    int over_num = 0;
    for(int w = 0 ; w < rounds ; w++){
        if(over_num == players - 1) break;
        if(w != 0){
            //找莊家
            max = 0;
            for(int j = 0 ; j < players ; j++){
                if((player[j].get_live() == 1) && (player[j].get_gain() > max)){
                    max = player[j].get_gain();
                    dealer_num = j;
                }
            }
            cnt = 1;
            for(int j = 1 ; j < players ; j++){
                if(player[j].get_gain() == player[0].get_gain()){
                    cnt++;
                }
            }
            min = 0;
            if(cnt == (players - over_num)){
                for(int j = 0 ; j < players ; j++){
                    if((player[j].get_live() == 1) && (player[j].get_money() < min)){
                        min = player[j].get_money();
                        dealer_num = j;
                    }
                }
            }
        }
        gotoxy(0,0);
        cout<<"Round "<<w + 1<<"                ";

        //初始化玩家
        for(int j = 0 ; j < players ; j++){
            player[j].set_arr(arr);
            player[j].set_flag(0);
            player[j].set_bet(0);
            player[j].set_point_sum(0);
            player[j].set_double_flag(0);
            player[j].set_insurance_bet(0);
            player[j].set_s_live(1);
            player[j].set_gain(0);
            player[j].set_surrender_flag(0);
            player[j].set_had_ace(0);
        }

        int Insurance_Flag = 0;
        //初始化flag
        for(int j = 0 ; j < players ; j++){
            player[j].set_flag(0);
        }

        //洗牌
        pokercard = shuffle(pokercard);
        stack<int> st;
        for(int j = 0 ; j < 52 ; j++){
            st.push(pokercard[j]);
        }

        //下注
        int bet;
        int k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num){
                continue;
            }
            if(player[i].get_live() == 0){
                continue;
            }
            gotoxy(20,k * 9 + 2);
            k++;
            cout<<"                          ";
        }

        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num){
                continue;
            }
            if(player[i].get_live() == 0){
                continue;
            }
            gotoxy(0,k * 9 + 1);
            cout<<"Player "<<i + 1;
            cout<<"                  ";
            gotoxy(0,k * 9 + 2);
            cout<<"Your Money: ";
            cout<<player[i].get_money()<<"        ";
            k++;
        }

        k = 0;
        int i = 0;
        while(i < players){
            if(i == dealer_num){
                i++;
                continue;
            }
            if(player[i].get_live() == 0){
                i++;
                continue;
            }
            gotoxy(20,k * 9 + 2);
            cout<<"Your Bet: ";
            gotoxy(31,k * 9 + 2);
            cin>>bet;
            if(bet > player[i].get_money()){
                gotoxy(31,k * 9 + 2);
                cout<<"No Balance";
                i--;
                k--;
            }
            else if(bet < lower){ //1000
                gotoxy(31,k * 9 + 2);
                cout<<"Too Little";
                i--;
                k--;
            }
            else {
                gotoxy(31,k * 9 + 2);
                cout<<"            ";
                gotoxy(31,k * 9 + 2);
                cout<<bet;
                player[i].set_bet(bet);
            }
            i++;
            k++;
        }
        gotoxy(90,1);
        cout<<"Player "<<dealer_num + 1<<" (Dealer) ";

        //發第一輪牌
        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num){
                continue;
            }
            if(player[i].get_live() == 0){
                continue;
            }
            if(card_to_point[st.top() % 13 + 1] == 1){
                player[i].set_had_ace(1);
            }
            player[i].point_plus(card_to_point[st.top() % 13 + 1]);
            player[i].push(st.top());
            print_card(k,player[i].get_size(),st.top());
            st.pop();
            k++;
        }
        if(card_to_point[st.top() % 13 + 1] == 1) Insurance_Flag = 1; //確認明牌是否為 A
        if(card_to_point[st.top() % 13 + 1] == 1){
            player[i].set_had_ace(1);
        }
        player[dealer_num].point_plus(card_to_point[st.top() % 13 + 1]);
        player[dealer_num].push(st.top());
        print_dealer_card(0,player[dealer_num].get_size(),st.top());
        st.pop();

        //發第二輪牌
        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num){
                continue;
            }
            if(player[i].get_live() == 0){
                continue;
            }
            if(card_to_point[st.top() % 13 + 1] == 1){
                player[i].set_had_ace(1);
            }
            player[i].point_plus(card_to_point[st.top() % 13 + 1]);
            player[i].push(st.top());
            print_card(k,player[i].get_size(),st.top());
            st.pop();
            k++;
        }
        if(card_to_point[st.top() % 13 + 1] == 1){
            player[i].set_had_ace(1);
        }
        player[dealer_num].point_plus(card_to_point[st.top() % 13 + 1]);
        player[dealer_num].push(st.top());
        print_dealer_card(0,player[dealer_num].get_size(),st.top());
        st.pop();
        
        string op2;

        //購買保險
        k = 0;
        if(Insurance_Flag == 1){
            //選擇是否購買保險
            for(int i = 0 ; i < players ; i++){
                if(i == dealer_num){
                    continue;
                }
                if(player[i].get_live() == 0){
                    continue;
                }
                gotoxy(11,k * 9 + 1);
                cout<<"Player "<<i + 1<<'\n'<<", Insurance: yes/no?  ";
                cin>>op2;
                cout<<'\n';
                while(op2 != "yes" && op2 !="No"){
                    cin>>op2;
                }
                if(op2 == "yes"){
                    if(player[i].get_money() * 2 > player[i].get_bet() / 2){
                        player[i].set_flag(1);
                        player[i].set_insurance_bet(player[i].get_bet() / 2);
                        player[i].bank((-1) * player[i].get_insurance_bet());
                    }
                }
                k++;
            }

            //是否兩張21點
            k = 0;
            if(mp.find(player[dealer_num].top()) != mp.end()){
                for(int i = 0 ; i < players ; i++){
                    if(i == dealer_num) continue;
                    if(player[i].get_live() == 0){
                        continue;
                    }
                    if(player[i].get_flag() == 1){
                        player[i].bank(player[i].get_insurance_bet() * 2);
                        player[i].bank_gain(player[i].get_insurance_bet());
                    }
                    k++;
                }
            }
        }

        //確認是否符合double資格
        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num) continue;
            if(player[i].get_live() == 0){
                continue;
            }
            if((player[i].get_point_sum() == 11) && (player[i].get_bet() * 2 < player[i].get_money())){
                player[i].set_double_flag(1);
                gotoxy(11,k * 9 + 1);
                cout<<", Double: Yes/No?  ";
                cin>>op2;
                if(op2 == "Yes"){
                    player[i].set_bet(player[i].get_bet() * 2);
                }
            }
            k++;
        }
        //顯示點數
        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num) continue;
            if(player[i].get_live() == 0){
                continue;
            }
            gotoxy(20,k * 9 + 2);
            k++;
            cout<<"Your Point: ";
            cout<<player[i].get_point_sum();
            cout<<"   ";
        }
        gotoxy(90,2);
        cout<<"Your Point: ";
        cout<<player[dealer_num].get_point_sum();
        cout<<"    ";
        //投降
        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num) continue;
            if(player[i].get_live() == 0){
                continue;
            }
            gotoxy(11,k * 9 + 1);
            cout<<", Surrender: Yes/No?  ";
            cin>>op2;
            if(op2 == "Yes"){
                player[i].set_s_live(0);
                player[i].set_surrender_flag(1);
                player[i].bank((-1) * player[i].get_bet() / 2);
            }
            gotoxy(11,k * 9 + 1);
            cout<<"                                 ";
            k++;
        }

        //玩家要牌
        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num) continue;
            if(player[i].get_live() == 0){
                continue;
            }
            if(player[i].get_s_live() == 0){
                continue;
            }
            printmenu(i);
            gotoxy(59,1);
            while(cin>>op){
                //操作
                //判斷存活
                if(player[i].get_point_sum() > 21){
                    if(player[i].get_had_ace() == 1){
                        player[i].set_point_sum(player[i].get_point_sum() - 10);
                    }
                    else{
                        player[i].set_s_live(0);
                        player[i].set_point_sum(-1);
                        gotoxy(10,k * 9 + 1);
                        cout<<" OVER!";
                        break;
                    }
                }
                if(op == 1){ //HIT
                    player[i].point_plus(card_to_point[st.top() % 13 + 1]);
                    player[i].push(st.top());
                    print_card(k,player[i].get_size(),st.top());
                    st.pop();
                    gotoxy(20,k * 9 + 2);
                    cout<<"Your Point: ";
                    cout<<player[i].get_point_sum();
                    cout<<"   ";  
                }
                else if(op == 2){ //STAND
                    break;
                }
                //判斷存活
                if(player[i].get_point_sum() > 21){
                    if(player[i].get_had_ace() == 1){
                        player[i].set_point_sum(player[i].get_point_sum() - 10);
                    }
                    else{
                        player[i].set_point_sum(-1);
                        player[i].set_s_live(0);
                        gotoxy(10,k * 9 + 1);
                        cout<<" OVER!";
                        break;
                    }
                }
                //過五關
                if(player[i].get_size() == 5){
                    gotoxy(10,k * 9 + 1);
                    cout<<" SUCCESS!";
                    break;
                }
                //是否21點
                if(player[i].get_point_sum() == 21){
                    break;
                }
                gotoxy(59,1);
            }
            k++;
        }

        //判斷要多少點才能不賠
        int S_num = 0;
        int balance = 0;
        for(int i = 1 ; i <= 20 ; i++){
            balance = 0;
            for(int j = 0 ; j < players ; j++){
                if(j == dealer_num) continue;
                if(i >= player[j].get_point_sum()){
                    balance = balance + player[j].get_bet();
                }
                else{
                    balance = balance - player[j].get_bet();
                }
            }
            if(balance >= 0){
                S_num = i;
                break;
            }
        }
        if(S_num < 17) S_num = 17;

        //莊家要牌
        while(player[dealer_num].get_point_sum() < S_num){
            player[dealer_num].point_plus(card_to_point[st.top() % 13 + 1]);
            player[dealer_num].push(st.top());
            print_dealer_card(0,player[dealer_num].get_size(),st.top());
            st.pop();
            gotoxy(90,2);
            cout<<"Your Point: ";
            cout<<player[dealer_num].get_point_sum();
            cout<<"    ";
            if(player[dealer_num].get_point_sum() > 21){
                if(player[dealer_num].get_had_ace() == 1){
                    player[dealer_num].set_point_sum(player[dealer_num].get_point_sum() - 9);
                }
                else{
                    player[dealer_num].set_s_live(0);
                    player[dealer_num].set_point_sum(-2);
                    cout<<" OVER!";
                    break;
                }
            }
            Sleep(1500);
        }
        Sleep(1500);

        //局結算
        vector<int>tmp;
        int win = 0;

        //莊家過五關
        if(player[dealer_num].get_size() == 5){
            for(int i = 0 ; i < players ; i++){
                if(i == dealer_num) continue;
                player[i].bank((-1) * player[i].get_bet() * 3);
                player[dealer_num].bank(player[i].get_bet() * 3);
            }
        }
        //莊家順子
        else if((player[dealer_num].get_size() == 3) && player[dealer_num].get_point_sum() == 21){
            tmp = player[dealer_num].get_arr();
            sort(tmp.begin(),tmp.end());
            if(tmp[0] == 6 && tmp[1] == 7 && tmp[2] == 8){
                for(int i = 0 ; i < players ; i++){
                    if(i == dealer_num) continue;
                    player[i].bank((-1) * player[i].get_bet() * 3);
                    player[dealer_num].bank(player[i].get_bet() * 3);
                }
            }
        }

        //莊家無特殊牌型
        else{
            for(int i = 0 ; i < players ; i++){
                win = 0;
                if(i == dealer_num) continue;
                if(player[i].get_surrender_flag() == 1) continue;

                //閒家贏
                if(((player[i].get_point_sum() >= player[dealer_num].get_point_sum()) && (player[i].get_s_live() == 1)) || ((player[i].get_s_live() == 1) && (player[dealer_num].get_s_live() == 0))){
                    player[i].bank(player[i].get_bet());
                    player[dealer_num].bank((-1) * player[i].get_bet());
                    win = 1;
                }

                //閒家輸
                else if((player[i].get_point_sum() < player[dealer_num].get_point_sum()) || ((player[i].get_s_live() == 0) && (player[dealer_num].get_s_live() == 1))){
                    player[i].bank((-1) * player[i].get_bet());
                    player[dealer_num].bank(player[i].get_bet());
                }

                //過五關
                if(player[i].get_size() == 5){
                    if(win == 1){
                        player[i].bank(player[i].get_bet() * 2);
                        player[dealer_num].bank((-1) * player[i].get_bet() * 2);
                    }
                    else{
                        player[i].bank(player[i].get_bet() * 4);
                        player[dealer_num].bank((-1) * player[i].get_bet() * 4);
                    }
                }

                //順子
                if((player[i].get_size() == 3)  && (player[i].get_point_sum() > player[dealer_num].get_point_sum())){
                    if(player[i].get_point_sum() == 21){
                        tmp = player[i].get_arr();
                        sort(tmp.begin(),tmp.end());
                        if(tmp[0] == 6 && tmp[1] == 7 && tmp[2] == 8){
                            if(win == 1){
                                player[i].bank(player[i].get_bet() * 2);
                                player[dealer_num].bank((-1) * player[i].get_bet() * 2);
                            }
                            else{
                                player[i].bank(player[i].get_bet() * 4);
                                player[dealer_num].bank((-1) * player[i].get_bet() * 4);
                            }
                        }
                    }
                }
            }
        }

        //判斷存亡
        if(player[i].get_money() < 1000){
            player[i].set_live(0);
            over_num++;
        }

        //顯示結算局錢
        k = 0;
        for(int i = 0 ; i < players ; i++){
            if(i == dealer_num){
                continue;
            }
            if(player[i].get_live() == 0){
                continue;
            }
            gotoxy(0,k * 9 + 2);
            cout<<"Your Money: ";
            cout<<player[i].get_money()<<"     ";
            cout<<"GAIN: "<<player[i].get_money() - player[i].get_intial_money()<<"  ";
            k++;
        }
        for(int i = 0 ; i < players ; i++){
            player[i].set_gain(player[i].get_money() - player[i].get_intial_money());
            player[i].set_intial_money(player[i].get_money());
        }
        Sleep(4000);

        //清屏
        for(int i = 0 ; i < 116 ; i++){
            gotoxy(0, i);
            cout<<"                                                      ";
        }

        //淘汰
        for(int i = 0 ; i < players ; i++){
            if(player[i].get_money() < 1000){
                player[i].set_live(0);
            }
        }

        //Reloading
        gotoxy(0, 0);
        cout<<"Reloading";
        for(int i = 0 ; i < 3 ; i++){
            Sleep(700);
            cout<<" .";
        }
        Sleep(700);

        //結算排名
        rk end[5];
        for(int i = 0 ; i < players ; i++){
            end[i].label = i + 1;
            end[i].money = player[i].get_money();
        }
        for(int i = 0 ; i < players - 1; i++){
            for(int j = i + 1 ; j < players ; j++){
                if(end[j].money > end[i].money){
                    rk tmp;
                    tmp = end[j];
                    end[j] = end[i];
                    end[i] = tmp;
                }
            }
        }
        gotoxy(0,0);
        for(int i = 0 ; i < players ; i++){
            cout<<"Player: "<<end[i].label<<", Balance: "<<end[i].money<<", Rank: "<<i + 1<<'\n';

        }
        Sleep(5000);

        //清屏
        for(int i = 0 ; i < 116 ; i++){
            gotoxy(0, i);
            cout<<"                                                      ";
        }
    }
    
    //結算排名
    rk end[5];
    for(int i = 0 ; i < players ; i++){
        end[i].label = i + 1;
        end[i].money = player[i].get_money();
    }

    for(int i = 0 ; i < players - 1; i++){
        for(int j = i + 1 ; j < players ; j++){
               if(end[j].money > end[i].money){
                rk tmp;
                tmp = end[j];
                end[j] = end[i];
                end[i] = tmp;
            }
        }
    }

    //清屏
    for(int i = 0 ; i < 116 ; i++){
        gotoxy(0, i);
        cout<<"                                                      ";
    }

    //Reloading
    gotoxy(0,0);
    cout<<"Reloading";
    for(int i = 0 ; i < 3 ; i++){
        Sleep(700);
        cout<<" .";
    }
    Sleep(700);

    //顯示最終結果
    gotoxy(0,0);
    for(int i = 0 ; i < players ; i++){
        cout<<"Player: "<<end[i].label<<", Balance: "<<end[i].money<<", Rank: "<<i + 1<<'\n';
    }
    cout<<"End GAME"<<'\n';

    system("pause");
    return 0;
}