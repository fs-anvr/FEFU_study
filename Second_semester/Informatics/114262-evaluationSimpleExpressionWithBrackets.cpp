#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

bool operation(char c){
    return c=='+' || c=='-' || c=='*' ||  c=='/';
}

int prioritet(char op) {
    if (op == '+' || op == '-')return 1;
    else if (op == '*' || op == '/')return 2;
    else return -1;
}

void action(vector<double> &value, char op) {
    double right = value.back();
    value.pop_back();
    double left = value.back();
    value.pop_back();
    if (op == '+')value.push_back((int)(left + right));
    else if (op == '-')value.push_back((int)(left - right));
    else if (op == '*')value.push_back(left * right);
    else if (op == '/')value.push_back(floor(left / right));
}

long long calculus(string &phrase){
    vector<double>value;
    vector<char>op;
    for(int i=0; i<phrase.size(); i++){
        if(phrase[i]=='('){
            op.push_back('(');
        }
        else if(phrase[i]==')'){
            while(op.back()!='('){
                action(value, op.back());
                op.pop_back();
            }
            op.pop_back();
        }
        else if(operation(phrase[i])){
            char zn=phrase[i];
            while(!op.empty() && prioritet(op.back())>=prioritet(zn)){
                action(value, op.back());
                op.pop_back();
            }
            op.push_back(zn);
        }
        else{
            string number;
            while(i<phrase.size() && isdigit(phrase[i]))number+=phrase[i++];
            i--;
            value.push_back(stod(number));
        }
    }
    while(!op.empty()){
        action(value, op.back());
        op.pop_back();
    }
    return floor(value.back());
}

int main() {
    string phrase;
    cin>>phrase;
    cout<<calculus(phrase);
    return 0;
}
/*
⠄⠄⠄⠄⣠⣄⣀⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⣼⡟⠉⠉⠄⠄⠄⠄⢀⣀⣀⣀⡀⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢿⣇⠄⠄⠄⠄⣠⣶⣿⠿⣿⣿⡿⣷⡀⠸⣿⣶⡀⠄⠄
⠄⠄⠄⠘⢿⣆⠄⣠⣾⣿⣿⣿⣶⣿⣿⣶⣿⠁⠄⣠⣿⡇⠄⠄
⠄⠄⠄⠄⠈⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⢛⣁⣤⣴⣿⠟⠁⠄⠄
⠄⠄⠄⠄⠄⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠟⠋⠁⠄⠄⠄⠄
⠄⠄⠄⠄⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡟⠁⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⣿⣿⡟⠉⠉⠄⠄⠈⣿⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⢸⣿⣿⠁⠄⠄⠄⠄⠄⢻⣿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⣾⣿⠇⠄⠄⠄⠄⠄⠄⠄⢿⣿⠄⠄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠹⢿⠁⡀⠄⠄⠄⠄⠄⠄⠸⣿⣶⡄⠄⠄⠄⠄⠄⠄⠄
⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠄⠉⠄⠄⠄⠄⠄⠄⠄⠄⠄
 */