#include<iostream>

using namespace std;

int n,e,t,start;
float adj_mat[1000][1000];

void solution(){
 cin >> n >> e >> t;
 for(int i=0;i<1000;i++){
    for(int j=0;j<1000;j++){
        adj_mat[i][j]=0;
    }
 }
 for(int i=0;i<e;i++){
    int u,v;
    float probab;
    cin >> u >> v >> probab;
    adj_mat[u][v]=probab;
 }
 cin >> start;
 int num_traversals = t/10;
 int curr_node = start;
 while(num_traversals>0){
    int next_node=-1;
    int max_probab=0;
    for(int i=0;i<n;i++){
        if(adj_mat[curr_node][i]>max_probab){
            max_probab=adj_mat[curr_node][i];
            next_node=i;
        }
    }
    if(next_node==-1){
        cout << "Exited the last lab" << endl;
        return;
    }
    curr_node=next_node;
    num_traversals--;
 }
 cout << "After " << t << " minutes, at node : "<< curr_node << endl;
}

int main(){
 int test_cases;
 cin >> test_cases;
 while(test_cases>0){
    test_cases--;
    solution();
 }
 return 0;
}
