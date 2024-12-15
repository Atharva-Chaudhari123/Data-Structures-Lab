#include<iostream>
#include<stack> 
#include<cctype> 
#include<string>
using namespace std ;

bool isPalindrome(string str){
    stack<char> s ;

    for(char c : str){
        s.push(c) ;
    }

    for (char c : str) {
        if(c != s.top()){
            return false; 
        }
        s.pop() ;
    }
    return true ;
}   
string preprocesing(string str){
    string processed = "" ;
    for(char ch :  str){
        if(isalnum(ch)){
            processed += tolower(ch) ;
        }
    }
    return processed ;
}


int main(){
    cout << "Enter any string : " ;
    string str ;
    getline(cin, str) ;

    cout<<str  <<endl;
    string str2 = preprocesing(str);

    if(isPalindrome(str2)){
        cout<<"String is palindrome" ;
    }
    else{
        cout<<"Not palindrome " ;
    }
}



