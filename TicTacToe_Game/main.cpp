#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
class TicTacToe_Game {
private:
    string player1,player2;
    char player1_char,player2_char;
    char position[10]={'0','1','2','3','4','5','6','7','8','9'};
    bool check_char;
    void Game()
    {
        cout<<"\t\t\t\t         -----------------------------------"<<endl<<endl;
        cout<<"\t\t\t\t***************( This TicTacToe_Game )***************\n"<<endl;
        cout<<"\t\t\t\t         -------Made By Saeed Youseef-------\n\n\n"<<endl;
    }
    void welcome()
    {
        cout<<endl<<endl<<"------------------------------------"<<endl;
        cout<<" Welcome player1: "<<player1<<endl;
        cout<<" Your Char: "<<player1_char<<endl;
        cout<<" Welcome player2: "<<player2<<endl;
        cout<<" Your Char: "<<player2_char<<endl;
        cout<<"------------------------------------"<<endl;
    }
    void defintion_player()
    {
        Game();
        cout<<"Enter Player1 Name: ";
        cin>>player1;
        cout<<endl;

        cout<<"Choose Your Char(X Or O): ";
        cin>>player1_char;
        cout<<endl;

        cout<<"Enter Player2 Name: ";
        cin>>player2;
        cout<<endl;

        player1_char=toupper(player1_char);
        if(player1_char=='X'){
            player2_char='O';
            check_char=true;
        }
        else{
            player2_char='X';
            check_char=false;
        }

        system("cls");
        Game();
        welcome();
    }
    void grid()
    {
        cout<<"-------------"<<endl;
        cout<<"| "<<position[1]<<" | "<<position[2]<<" | "<<position[3]<<" |"<<endl;
        cout<<"-------------"<<endl;
        cout<<"| "<<position[4]<<" | "<<position[5]<<" | "<<position[6]<<" |"<<endl;
        cout<<"-------------"<<endl;
        cout<<"| "<<position[7]<<" | "<<position[8]<<" | "<<position[9]<<" |"<<endl;
        cout<<"-------------"<<endl;
    }
    void play()
    {
        int number_of_plays=9,pos=0,tt=0,pp=0,nowinner=1;
        grid();
        while(number_of_plays)
        {
            if(number_of_plays&1){
                cout<<"Player1 Choose Position: ";cin>>pos;
            }
            else {
                cout<<"Player2 Choose Position: ";cin>>pos;
            }
            if(pos<1||pos>9)
            {
                pp=1;
            }
            else if(position[pos]!='X'&&position[pos]!='O')
            {
                if(number_of_plays&1)
                    position[pos]=player1_char;
                else
                    position[pos]=player2_char;
                number_of_plays--;
            }
            else {
                tt=1;
            }
            system("cls");
            Game();
            welcome();
            grid();
            if(tt){
                tt=0;
                cout<<"Choose Other The Positoin Bloked!! "<<endl;
            }
            if(pp)
            {
                pp=0;
                cout<<"Choose Position From 1 To 9!! "<<endl;
            }
            if(check_winner(position)&&(number_of_plays&1))
            {
                cout<<"The Player "<<player2<<" Is Winner"<<endl;nowinner=0;
                break;
            }
            else if(check_winner(position))
            {
                cout<<"The Player "<<player1<<" Is Winner"<<endl;nowinner=0;
                break;
            }
        }
        if(nowinner)
            cout<<"NO WINNER HARD LUCK !!"<<endl;
    }
    bool check_winner(char a[]) {
        if((position[1]==position[2]&&position[1]==position[3]&&position[2]==position[3])||
           (position[4]==position[5]&&position[4]==position[6]&&position[5]==position[6])||
           (position[7]==position[8]&&position[7]==position[9]&&position[8]==position[9])||
           (position[1]==position[4]&&position[1]==position[7]&&position[4]==position[7])||
           (position[2]==position[5]&&position[2]==position[8]&&position[5]==position[8])||
           (position[3]==position[6]&&position[3]==position[9]&&position[6]==position[9])||
           (position[1]==position[5]&&position[1]==position[9]&&position[5]==position[9])||
           (position[3]==position[5]&&position[3]==position[7]&&position[5]==position[7]))
            return true;
        else
            return false;

    }
public:
    static void Play_the_game()
    {
        int again;
        do {
            TicTacToe_Game play;
            play.defintion_player();
            play.play();
            cout<<"\nENTER 1 IF NEED PLAY AGAIN ELSE 0:";cin>>again;
            system("cls");
        }while(again);
        cout<<"GOOD BYE"<<endl;
    }

};

int main()
{
    TicTacToe_Game::Play_the_game();
    return 0;
}



