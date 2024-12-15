/*
Problem Statement: In any language program mostly syntax error occurs due to unbalancing 
delimiter such as (),{},[]. Write C++ program using stack to check whether given expression is 
well parenthesized or not. 
*/

#include<iostream>
#include<stack> 
#include<string>
using namespace std ; 

bool isBalanced(string str){
    stack<char> s; 

    for (char ch : str){
        if(ch == '(' or ch== '{' or ch=='['){
            s.push(ch) ;
        }
        else if(ch == ')' or ch == '}' or ch==']'){

         if (s.empty()) {
            return false;  // Closing bracket without an opening bracket
    }

          char top = s.top() ;
          s.pop() ;
          if((ch == ')' && top != '(' ) ||
            (ch == ']' && top != '[' ) ||
            (ch == '}' && top != '{' )) {
                return false ;
            }

        }

    }

    if(s.empty()){
        return true ;
    }
    else{
        return false ;
    }
}

int main(){
    string str ;
    cout<<"Enter expression : " ;
    cin >> str ;

    if(isBalanced(str)){
        cout<< "Expression is balanced :)" ;
    }
    else{
        cout<<"Expression is unbalanced" ;
    }
}