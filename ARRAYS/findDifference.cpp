/* You are given two strings s and t.
String t is generated by random shuffling string s and then add one more letter at a random position.
Return the letter that was added to t. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i = 0 ; i < t.length() ; i++){
            if(!s.find(t[i])) return t[i];
        }
    }
};