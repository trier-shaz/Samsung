#include <stdio.h>

#define Int int
#define If if
#define MAX_N  11
#define true   1
#define false  0

int Array[MAX_N][MAX_N];

Int Path[MAX_N][MAX_N]; // Save the path that has passed

Int Visited[MAX_N][MAX_N]; // Mark the path that passed

int Answer[MAX_N][MAX_N];

int Max_Jewes;

int N;

void SavePath()
{
     int i,j;
     for(i=0;i<N;i++)
     {
      for(j=0;j<N;j++)
      {
        Answer[i][j] = Path[i][j];

      }

     }
}

int Visit(int i, int j, int total)
{
     int ret = 0;
     Path[i][j] = 3 ;
     Visited[i][j] = true ;
     If ((i ==0)&&(j == 0)&&(Array[i][j] == 2)) // If the first node is 2 , total plus 1
     {
       total++;

     }
     If ((i == N-1)&&(j == N-1)) // If the end point is reached, it is judged that the result of this traversal is compared with the largest of all previous times. If it is greater than the previous result, Save this maximum and this path
     {
      if(total > Max_Jewes)
      {
        Max_Jewes = total ;
        SavePath();
      }

      Visited[i][j] = false ; // Mark the end point as unscanned so that the next traversal can also scan to that point
      return 1;

     }
    if((j+1) <= (N-1))//down
    {
     If ((!Visited[i][j+1])&&(Array[i][j+1] != 1)) // If the point below the point has not been scanned, and the point below the point Not for the wall ( 1 )
     {
     If (Array[i][j+1] == 2) // If there is a treasure, add 1 to the total and continue traversing
      Visit(i, j+1, total+1);
     else
      Visit(i, j+1, total); // If there is no treasure, the total is unchanged, continue to traverse

      Path[i][j+1] = Array[i][j+1] ; // dead angle, restore the value of path after rollback

     }
    }

    if((j-1) >= 0)//up
    {
     if((!Visited[i][j-1])&&(Array[i][j-1] != 1))
     {
      if(Array[i][j-1] == 2)
       Visit(i , j-1, total+1);
      else
       Visit(i , j-1, total);

      Path[i][j-1] = Array[i][j-1] ;
     }
    }

    if((i+1) <= (N-1))//right
    {
     if((!Visited[i+1][j])&&(Array[i+1][j] != 1))
     {
      if(Array[i+1][j] == 2)
        Visit(i+1 , j, total+1);
      else
        Visit(i+1 , j, total);

       Path[i+1][j] = Array[i+1][j] ;
      }
     }

    if((i-1) >= 0)//left
    {
     if((!Visited[i-1][j])&&(Array[i-1][j] != 1))
     {
      if(Array[i-1][j] == 2)
        Visit(i-1 , j, total+1);
      else
        Visit(i-1 , j, total);

      Path[i-1][j] = Array[i-1][j];
     }
    }
   Visited[i][j] = false ;
   return -1;
}

int main(void)
{
   int T, test_case;
   // freopen("sample_input.txt", "r", stdin);
  //  setbuf(stdout, NULL);

   scanf("%d", &T);
   for(test_case = 0; test_case < T; test_case++)
   {
    int i ,j ;
    //total = 0 ;
    Max_Jewes = -1 ;
    scanf("%d",&N);
    for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
     {
      scanf("%d",&Array[i][j]);
      Path[i][j] = Array[i][j];

     }
    }

   for(i=0;i<N;i++)
   {
    for(j=0;j<N;j++)
    {
     Visited[i][j] = false ; // // Initialize the traversal flag
    }
   }

   Visit(0 , 0, 0);
   printf("Case #%d\n", test_case+1);

   //printf("%d\n", Answer);

    for(i=0;i<N;i++)
    {
     for(j=0;j<N;j++)
     {
      printf("%d ",Answer[i][j]);
     }
      printf("\n");
    }
     printf("%d\n", Max_Jewes);
   }

return 0;
}
