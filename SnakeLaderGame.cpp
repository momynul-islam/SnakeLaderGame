#include <bits/stdc++.h>

using namespace std;

class Display{

public :
    void displayBoard(){
        cout << "\t\t\t\t\t ------------------ \n";
        cout << "\t\t\t\t\t| Snake Lader Game |\n";
        cout << "\t\t\t\t\t ------------------ \n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\t47\t|\t46\t|\t45(S,9) |\t44\t|\t43\t|\t42\t|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\t36\t|\t37\t|\t38\t|\t39\t|\t40\t|\t41\t|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\t35(L,38)|\t34(S,22)|\t33\t|\t32(S,13)|\t31\t|\t30\t|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\t24\t|\t25(S,14)|\t26(L,41)|\t27\t|\t28(S,16)|\t29\t|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\t23\t|\t22\t|\t21(S,7) |\t20\t|\t19\t|\t18(L,24)|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\t12(S,5)|\t13(L,27)|\t14\t|\t15(S,7)|\t16\t|\t17\t|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\t11\t|\t10(L,23)|\t 9\t|\t 8\t|\t 7\t|\t 6(L,20)|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    cout << "|\tStart\t|\t 1\t|\t 2\t|\t 3\t|\t 4(L,17)|\t 5\t|\n";
    cout << " ----------------------------------------------------------------------------------------------- \n";
    }
};

class Player{

public :
    int currentPosition;
    bool fastValid;
    Player(){
        currentPosition = 0;
    }
        bool isThereALader(){
        return currentPosition == 4 || currentPosition == 6 || currentPosition == 10 || currentPosition == 13
                || currentPosition == 18 || currentPosition == 26 || currentPosition == 35;
    }
    bool isThereASnake(){
                return currentPosition == 12 || currentPosition == 15 || currentPosition == 21 || currentPosition == 25
                || currentPosition == 28 || currentPosition == 32 || currentPosition == 34 || currentPosition ==45;
    }
    int climbLader(int data){
        int value = data;
       switch (value){
            case 4:
                return 17;
            case 6:
                return 20;
            case 10:
                return 23;
            case 13:
                return 27;
            case 18:
                return 24;
            case 26:
                return 41;
            case 35:
                return 38;
        }
        return 0;
    }
    int biteSnake(int data){
        int value = data;
        switch (value){
            case 15:
                return 7;
            case 21:
                return 7;
            case 25:
                return 14;
            case 28:
                return 16;
            case 12:
                return 5;
            case 45:
                return 9;
            case 34:
                return 22;
            case 32:
                return 13;
        }
        return 0;
    }
    bool lastValidation(int data){
        return data > 47;
    }
    bool fastValidation(int data){
        return data == 1;
    }
    bool winer(int index,int data){
        if(index == 0 && data == 47){
            cout << "Player 1 win the game !!!\n";
            return true;
        }
        else if(index == 1 && data == 47){
            cout << "Player 2 win the game !!!\n";
            return true;
        }
        return false;
    }

};

int main(){

    Player players[2];
    Display display;
    char ch;
    int index = 0,diceValue,temp = 0;
    bool winerFound = false;

    while(!winerFound){
        display.displayBoard();
        cout << "\nPress R to Roll a dice...\n";
        cin >> ch;
        system("CLS");
        if(index == 0){
           diceValue  = (rand()%10)/3;
           if(diceValue == 0)
                diceValue = 1;
           cout << "Player 1: " << diceValue << endl;

           temp = players[index].currentPosition;
           players[index].currentPosition += diceValue;

           if(!players[index].fastValid){
                players[index].fastValid = players[index].fastValidation(players[index].currentPosition);
                if(!players[index].fastValid){
                    players[index].currentPosition = 0;
                    cout << "Current Position - \nplayer 1: " << players[0].currentPosition << " player 2: " << players[1].currentPosition << endl;
                    index++;
                    continue;
                }
           }

           if(players[index].lastValidation(players[index].currentPosition))
            players[index].currentPosition = temp;

           if(players[index].isThereALader()){
            cout << "Lader !!!\n";
            diceValue = players[index].climbLader(players[index].currentPosition);
            players[index].currentPosition = diceValue;
           }
           else if(players[index].isThereASnake()){
            cout << "Snake !!!\n";
            diceValue = players[index].biteSnake(players[index].currentPosition);
            players[index].currentPosition = diceValue;
           }
           winerFound = players[index].winer(index,players[index].currentPosition);
           index++;
        }
        else{
           diceValue  = (rand()%10)/3;
           if(diceValue == 0)
                diceValue = 1;
           cout << "Player 2: " << diceValue << endl;

           temp = players[index].currentPosition;
           players[index].currentPosition += diceValue;

           if(!players[index].fastValid){
            players[index].fastValid = players[index].fastValidation(players[index].currentPosition);
            if(!players[index].fastValid){
                players[index].currentPosition = 0;
                cout << "Current Position - \nplayer 1: " << players[0].currentPosition << " player 2: " << players[1].currentPosition << endl;
                index--;
                continue;
            }
           }

           if(players[index].lastValidation(players[index].currentPosition))
            players[index].currentPosition = temp;

            if(players[index].isThereALader()){
             cout << "Lader !!!\n";
             diceValue = players[index].climbLader(players[index].currentPosition);
             players[index].currentPosition = diceValue;
           }
           else if(players[index].isThereASnake()){
            cout << "Snake !!!\n";
            diceValue = players[index].biteSnake(players[index].currentPosition);
            players[index].currentPosition = diceValue;
           }
           winerFound = players[index].winer(index,players[index].currentPosition);
           index--;
        }

        cout << "Current Position - \nplayer 1: " << players[0].currentPosition << " player 2: " << players[1].currentPosition << endl;

    }

        }
