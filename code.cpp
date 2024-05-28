#include <bits/stdc++.h>
using namespace std;

void fileio(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

struct Node
{
    int val;
    Node* next;
};

int main(){
fileio();

Node *x = new Node(); 
Node *y = new Node(); 
y->val=18;
x->val=21;
x->next=y;
cout<<(x->next->val);

}
