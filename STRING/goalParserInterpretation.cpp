/* You own a Goal Parser that can interpret a string command. The command consists of an alphabet of "G", "()" and/or "(al)" in some order. 
The Goal Parser will interpret "G" as the string "G", "()" as the string "o", and "(al)" as the string "al". 
The interpreted strings are then concatenated in the original order.
Given the string command, return the Goal Parser's interpretation of command. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string interpret(string command) {
        string res = "";
        for(int i = 0 ; i < command.size() ; i++){
            if(command[i]=='G') res += "G";
            else if(command[i]=='(' && command[i+1]==')') res += "o";
            else if(command[i]=='(' && command[i+1]=='a') res += "al";
            else if(command[i] == 'l' || command[i] == ')') continue;
        }
        return res;
    }
};