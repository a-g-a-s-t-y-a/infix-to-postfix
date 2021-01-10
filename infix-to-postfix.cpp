#include<bits/stdc++.h>


using namespace std;

//macros-------------------------------------------
#define deb(x) cout<<#x<<" : "<<x<<endl
#define print(x) cout<<x<<endl
#define ll long long int
#define fastio ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define nl "\n"


//functions prototype------------------------------

int getPriority(char);

//solve function-----------------------------------

void solve(void){
    string s,exp;
    int n,x;
    cin>>n;
    cin>>s;
    int p,pPrev;
    stack <char> stk;
    exp = "";
    bool added;
    for(char c:s){
        //cout<<c<<endl;
        if(c>='A'&&c<='Z'){
            exp+=c;
        }
        else if(c=='('){
            stk.push(c);
        }
        else if(c==')'){
            while(stk.top()!='('){
                exp+=(stk.top());
                stk.pop();
            }
            stk.pop();
        }
        else{
            p = getPriority(c);
            added =0;
            while(!added){
                if(stk.empty()){stk.push(c);break;}
                pPrev = getPriority(stk.top());
                if(pPrev>=p){
                    exp+=(stk.top());
                    stk.pop();
                }else{
                    stk.push(c);
                    added =1;
                }

            }

        }
        
    }
    while(!stk.empty()){
        exp+=(stk.top());
        stk.pop();
    }
    cout<<exp<<endl;
        

}


//main function-----------------------------------
int main(){
    fastio;
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    ll test=1;
    cin>>test;
    while(test--){
        solve();
    }
    return 0;
}

int getPriority(char c){
    switch(c){
        case '(' :{
            return 0;
        }break;
        case ')' :{
            return 0;
        }break;
        case '+' :{
            return 1;
        }break;
        case '-' :{
            return 1;
        }break;
        case '*' :{
            return 2;
        }break;
        case '/' :{
            return 2;
        }break;
        case '^' :{
            return 3;
        }break;
    }
    return -1;
}