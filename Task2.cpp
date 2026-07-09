#include<bits/stdc++.h>
using namespace std;

int main() {
     cout<<"SIMPLE CALCULATOR\n";
     cout<<"Enter the value of numbers.\n";
     float num1, num2;
     cout<<"num1 : ";
     cin>>num1;
     cout<<"num2 : ";
     cin>>num2;
     float result = 0;
     
     cout<<"Choose operator (+, -, *, /) : ";
     char op;//+ , - , * , /
     cin>>op;
     
     switch(op){
        case '+' :
            cout<<"You Chose ADD.\n";
            result = num1 + num2;
            cout<<num1<<"+"<<num2<<" = "<<result<<endl;
            break;
            
        case '-' :
            cout<<"You Chose SUBTRACTION.\n";
            result = num1 - num2;
            cout<<num1<<"-"<<num2<<" = "<<result<<endl;
            break;
              
        case '*' :
            cout<<"You Chose MULTIPLICATION.\n";
            result = num1 * num2;
            cout<<num1<<"*"<<num2<<" = "<<result<<endl;
            break;    
            
        case '/' :
            cout<<"You Chose DIVISION.\n";
            if(num2 == 0){
                cout<<"Error! Division by zero.\n";
            }
            else{
                result = num1 / num2;
                cout<<num1<<"/"<<num2<<" = "<<result<<endl;  
            }
            break;
            
        default:
                cout<<"Invalid operator!\n";
                break;
     }

    return 0;
}