#include<iostream>

using namespace std;

int n,e;
bool edge[100][100];
bool visited[100];
int k,l;
int path[100];

void reset(){
 for(int i=0;i<100;i++){
    for(int j=0;j<100;j++){
        edge[i][j]=false;
    }
    visited[i]=false;
    path[i]=-1;
 }
 k=-2;
 l=-2;
}

void input(){
 cin >> n >> e;
 for(int i=0;i<e;i++){
    int x,y;
    cin >> x >> y;
    edge[x][y]=true;
 }
}

int rec(int node,int counter){
 path[counter]=node;
 for(int y=0;y<n;y++){
    if(edge[node][y]){
        if(visited[y]){
            // found a cycle
            k=y;
            l=node;
            return -1;
        }
        visited[y]=true;
        int i = rec(y,counter+1);
        if(i==-1){
            return -1;
        }
        visited[y]=false;
    }
 }
}

void output(){
 cout << endl;
 if(k==-2){
    // no loop
    cout << -1 << endl;
    return;
 }
 if(k==-2){
    cout << path[0]<< endl;
    return;
 }
 int start_idx=0;
 for(int i=0;i<100;i++){
    if(path[i]==k){
        start_idx=i;
    }
 }
 for(int i=start_idx;i<100;i++){
     if(path[i] == l){
        cout << path[i] << "->";
        break;
     }
    cout << path[i] << "->";
 }
 cout << path[start_idx];
 cout << endl;
}

void driver(){
 for(int x=0;x<n;x++){
    visited[x]=true;
    path[0]=x;
    for(int y=0;y<n;y++){
        if(edge[x][y]){
            if(visited[y]){
                if(x==y){
                    // self loop
                    k=-1;
                    break;
                }
            }
            visited[y]=true;
            int ret = rec(y,1);
            if(ret == -1){
                return;
            }
            visited[y]=false;
        }
    }
 }
}

int main(){
 int test;
 cin >> test;
 while(test>0){
    test--;
    reset();
    input();
    driver();
    output();
 }
}
