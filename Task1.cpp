#include<bits/stdc++.h>
using namespace std;
int main() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distrib(1, 100);

    int targetNumber = distrib(gen);   // — Generate the  number

    cout<<"NUMBER GUESSING GAME \n";
    int guessNum ;
    cout<<"Enter Your Guess : ";
    cin>>guessNum;
    int attempts = 0;
    
    do{
       if(guessNum > targetNumber){
            cout<<"The guess is higher.\n";
        }
        else if(guessNum < targetNumber){
            cout<<"The guess is Low.\n";
        }
        cout<<"Enter Your Guess : ";
        cin>>guessNum;
        attempts++;
    }while(guessNum != targetNumber);
    
    cout<<"Congratulation your guess is correct!\n";
    cout<<"Total attempts : "<<attempts<<endl;
    return 0;
}