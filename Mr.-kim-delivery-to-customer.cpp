/*
#include<iostream>

using namespace std;

int d[12][12];
int x[12],y[12];
int visited[12];
int n;
int min_distance = 1e9;

int abs(int x){
 if(x>0){
    return x;
 }
 else{
    return -x;
 }
}

void preprocess_distance(){
 for(int i=0;i<n+2;i++){
    for(int j=0;j<n+2;j++){
        d[i][j] = abs(x[i]-x[j])+abs(y[i]-y[j]);
    }
 }
}

void calculate(int source,int destination,int distance_so_far){
 distance_so_far = distance_so_far+d[source][destination];
 if(distance_so_far>min_distance){
    return;
 }

 if(destination == n+1){
    for(int i=0;i<=n+1;i++){
        if(visited[i]==0){
            return;
        }
    }
 if(distance_so_far<min_distance){
    min_distance=distance_so_far;
 }
 return;
}

 for(int i=1;i<=n+1;i++){
    if(visited[i]==0){
        visited[i]=1;
        calculate(destination,i,distance_so_far);
        visited[i]=0;
    }
 }

}

int main(){

 for(int i=1;i<=10;i++){
    min_distance = 1e9;
    cin >> n;
    cin >> x[0] >> y[0];
    cin >> x[n+1] >> y[n+1];

    for(int j=1;j<=n;j++){
        cin >> x[j] >> y[j];
        visited[j]=0;
    }
    preprocess_distance();
    visited[0]=1;
    visited[n+1]=0;
    calculate(0,0,0);
    cout << "Case no. : " << i << " " << min_distance << endl;

 }
return 0;
}
*/

#include<iostream>

using namespace std;

int dp[13][1<<12];
int x[13],y[13];
int n;

int abs(int x){
 if(x>0)
    return x;
 else
    return -x;
}

int calc(int p,int mask){
 if(p==0){
    return (mask!=0)*1e9;
 }
 int &ret = dp[p][mask];
 if(ret != -1){
    return ret;
 }
 ret = 1e9;
 for(int i=0;i<=n;i++){
    if(mask & (1<<i)){
        int dist = abs(x[p]-x[i])+abs(y[p]-y[i]);
        ret = min(ret,calc(i,mask ^ (1<<i))+dist);
    }
 }
 return ret;
}

int main(){
 for(int i=0;i<10;i++){
    cin >> n;
    cin >> x[n+1] >> y[n+1];
    cin >> x[0] >> y[0];
    for(int j=1;j<=n;j++){
        cin >> x[j] >> y[j];
    }
 for(int i=0;i<13;i++){
    for(int j=0;j<(1<<12);j++){
        dp[i][j] = -1;
    }
 }
 int ans = calc(n+1,(1<<(n+1))-1);
 cout << "#" << i+1 << " " << ans << endl;
}
return 0;
}
