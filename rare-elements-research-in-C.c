#include<stdio.h>
#include<stdlib.h>
int n, c, **rare, **area,**visited, ***dist;

int min(int a, int b)
{
	return a>b? b:a;
}
int max(int a, int b)
{
	return a>b?a:b;
}

void bfs(int k, int i, int j, int dis)
{
	if(i<0 || i>n-1 || j<0 || j>n-1) return;
	if(area[i][j]==0) return;

	//printf("%d %d %d %d\n" ,i ,j,k,dist[i][j][k]);
	if(visited[i][j] != 0 && dist[i][j][k] < dis)
	return;

	visited[i][j]=1;
	dist[i][j][k] = dis;

	bfs(k, i+1,j,dis+1);
	bfs(k, i-1,j,dis+1);
	bfs(k, i,j+1,dis+1);
	bfs(k, i,j-1,dis+1);
	//visited[i][j]=0;
}


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d %d",&n,&c);
		int i,j,k;
		rare=(int**)malloc(2*sizeof(int*));
		for(i=0;i<c;i++)
		{
			rare[i]=(int*)malloc(2*sizeof(int));
			scanf("%d %d", &rare[i][0], &rare[i][1]);
			rare[i][0]--;
			rare[i][1]--;
		}

		area=(int**)malloc(n*sizeof(int*));
		visited=(int**)malloc(n*sizeof(int*));
		dist=(int***)malloc(n*sizeof(int**));
		for(i=0;i<n;i++)
		{
			area[i]=(int*)malloc(n*sizeof(int));
			visited[i]=(int*)malloc(n*sizeof(int));
			dist[i]=(int**)malloc(n*sizeof(int*));
			for(j=0;j<n;j++)
			{
				visited[i][j]=0;
				scanf("%d", &area[i][j]);
				dist[i][j]=(int*)malloc(c*sizeof(int));
				for(k=0;k<c;k++)
				{
					dist[i][j][k]=-1;
				}
			}
		}

		for(i=0;i<c;i++)
		{
			bfs(i,rare[i][0], rare[i][1], 0);
			for(j=0;j<n;j++)
			{
				for(k=0;k<n;k++)
					visited[j][k]=0;
			}
		}
		int ans=1000007, fl=0;
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(area[i][j]==1){
					int mx=0;
					for(k=0;k<c;k++)
					{
						if(dist[i][j][k]==-1) fl=1;
						//printf("%d ",dist[i][j][k]);
						if(dist[i][j][k]>mx)
							mx=dist[i][j][k];
					}
					if(ans>mx)
					{
						ans=mx;
					}
				}
				//printf("\n");
			}
		}
		if(fl==1) printf("No answer\n");
		else
		printf("%d\n", ans);
		free(dist);
		free(area); free(rare); free (visited);
	}

	return 0;
}




/*
Samsung wants to explore some of the rare elements for its semiconductor manufacturing.
Scientists use one vehicle to explore the region in order to find the rare elements.
The vehicle can move only in explored region where roads have already been constructed.
The vehicle cannot move on unexplored region where roads are not there.
In the current situation, rare elements are present in explored region only.
Unexplored regions do not contain any rare elements.

Square region is provided for exploration. Roads are represented by 1 and where roads
are not present that area is represented by 0. Rare elements will only be on the roads
where regions have already been explored. Vehicle can move in four directions – up, down, left and right.

The shortest path for vehicle to a rare element position is called Moving Path.
The longest of the paths to all rare elements from a region called Longest Distance.

Scientists need to construct one research center so that the research center will
be at the position where the longest path to the rare elements will be shortest.
This is called Shortest Longest Distance.

Constraints:
The region provided will be square region i.e. NxN (where 5 <=  N <= 20).
There can be minimum of 2 rare elements and maximum of 4 rare elements, i.e. 2 <= C <= 4.
Roads are represented by 1 while no road area is represented by 0.
Vehicle can move only on roads in explored area.
The rare elements will only be present where road are there. Rare elements will not be present
where roads are not present.
Vehicle can move in UP, DOWN, LEFT and RIGHT directions.
The starting index for rare element is considers as 1.
 

Input:
First line will be the number of test cases. Second line will indicate region area (N) and
number of rare elements (C). Next C lines will contain the position of rare elements.
After that N lines will provide the region details where to tell where roads are present
and where roads are not present.
 
Output:
Output #testcase followed by space and then shortest longest distance.


5
5 2
4 3
3 4
1 1 0 0 0
1 1 0 0 0
1 1 1 1 1
1 1 1 0 1
1 1 1 1 1
8 2
5 6
6 4
1 1 1 1 1 1 0 0
1 1 1 1 1 1 1 0
1 1 0 1 0 1 1 0
1 1 1 1 0 1 1 0
1 1 1 1 1 1 1 0
1 1 1 1 1 1 1 0
0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0
10 3
8 2
5 3
7 1
0 0 0 1 1 1 1 1 1 0
1 1 1 1 1 1 1 1 1 0
1 0 0 1 0 0 0 0 1 0
1 1 1 1 1 1 1 1 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
1 1 1 0 0 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1
15 4
11 15
15 9
1 2
14 3
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 0 1 0 0 0 1 0 0 0 0 1 1 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
0 0 1 0 0 0 1 1 1 1 1 1 1 0 1
0 0 1 1 1 1 1 1 1 1 1 1 1 1 1
20 4
13 6
20 4
1 2
17 16
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 0 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 0 0
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 1 1 1 0 0 1 1
1 0 1 1 1 1 1 1 1 1 1 1 1 1 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 0 1 0 0 0 0 0 0 0 1 0 0 0 1 1 0 0 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 1 1 1 1 1 1 1 1 1 1 0 0 0 0 0 0 0 0 0

Output
#1 1
#2 2
#3 2
#4 12
#5 15
*/

