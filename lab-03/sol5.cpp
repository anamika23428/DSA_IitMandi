#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int pre(char c){
    if(c=='^'){return 3;}
    else if(c=='/'||c=='*'){return 2;}
    else if(c=='+'||c=='-'){return 1;}
    return 0;
}

int main(){
    string s;
    cin>>s;
    stack<char> st;
    string ans="";
    for(int i=0;i<s.length();i++){
        if(s[i]=='('){st.push(s[i]);}
        else if(s[i]==')'){
            while(!st.empty() && st.top()!='(' ){
                ans+=st.top();
                st.pop();
            }
        st.pop();}
        else if(('a'<=s[i] && s[i]<='z' )|| ('A'<=s[i] && s[i]<='Z')){
            ans+=s[i];
        }
        else{
            while(!st.empty() && pre(st.top())>=pre(s[i])){
                ans+=st.top();
                st.pop();
        }
        st.push(s[i]);
        }
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();}

            cout<<ans<<endl;

}