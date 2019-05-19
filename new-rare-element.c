#include<stdio.h>
#include<stdlib.h>

int n,c,**rare,**area,**visited,***dist;

void bfs(int k,int i,int j,int dis){
 if(i<0 || i>n-1 || j<0 || j>n-1){
    return;
 }
 if(area[i][j]==0){
    return;
 }

 if(visited[i][j]!=0 && dist[i][j][k]<dist){
    return;
 }

 visited[i][j]=1;
 dist[i][j][k]=dis;

 bfs(k,i+1,j,dis+1);
 bfs(k,i-1,j,dis+1);
 bfs(k,i,j+1,dis+1);
 bfs(k,i,j-1,dis+1);
}

int main(){
int t;
scanf("%d", &t);
while(t--)
 {
    scanf("%d %d",&n,&c);
    int i,j,k;
    rare = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++){
        rare[i] = (int*)malloc(2*sizeof(int));
        scanf("%d %d",&rare[i][0],&rare[i][1]);
        rare[i][0]--;
        rare[i][1]--;
    }

    area = (int**)malloc(n*sizeof(int*));
    visited = (int**)malloc(n*sizeof(int*));
    dist = (int**)malloc(n*sizeof(int*));
    for(i=0;i<n;i++)
    {
        area[i]=(int*)malloc(n*sizeof(int));
        visited[i]=(int*)malloc(n*sizeof(int));
        dist[i]=(int*)malloc(n*sizeof(int*));
        for(j=0;j<n;j++)
        {
            visited[i][j]=0;
            scanf("%d",&area[i][j]);
            dist[i][j]=(int*)malloc(c*sizeof(int));
            for(int k=0;k<c;k++){
                dist[i][j][k]=-1;
            }
        }
    }
    for(i=0;i<c;i++)
    {
        bfs(i,rare[i][0],rare[i][1],0);
        for(j=0;j<n;j++)
        {
            for(k=0;k<n;k++)
            {
                visited[j][k]=0;
            }
        }
    }
    int ans=1000007,f1=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            if(area[i][j]==1)
            {
                int mx;
                for(k=0;k<c;k++)
                {
                    if(dist[i][j][k]==-1)
                    {
                        f1=1;
                    }
                    if(dist[i][j][k]>mx)
                    {
                        mx=dist[i][j][k];
                    }
                }
                if(ans>mx)
                {
                    mx = ans;
                }
            }
        }
    }
    if(f1==1){
        printf("No Answer\n");
    }
    else{
        printf("%d\n", ans);
        free(dist);
        free(area);free(visited);free(rare);
    }
 }
return 0;
}

