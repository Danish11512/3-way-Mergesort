#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <algorithm>
using namespace std;

bool bfs(int * residualgraph, int s, int t, int n, int *augmentedpath){
   //create an array for visited, and mark all of them as not visited
   bool visitedarr[n];
   for(int i = 0; i<n; i++){
       visitedarr[i] = false;
   }

   // create queue, push in source and mark it as visited

   queue <int> bfsqueue;
   visitedarr[s] = true;
   augmentedpath[s] = -1;
   bfsqueue.push(s);

   // bfs loop
   while(!bfsqueue.empty()){
      int popped = bfsqueue.front();
      bfsqueue.pop();

      for(int i = 0; i<n; i++){
          if(!visitedarr[i] && *(residualgraph + popped*n + i)>0){

              bfsqueue.push(i);
              augmentedpath[i] = popped;
              visitedarr[i] = true;

          }
      }
   }
   return visitedarr[t];
}


void maximum_flow(int n, int s, int t, int *cap, int *flow){
    int augmentedpath[n];
    int bottleneck = INT_MAX;
    int *residualgraph = new int[n*n];

    // filling residual graph with copies
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            *(residualgraph + i*n + j) = *(cap + i*n + j);
        }
    }

    *(flow + s*n + t) = *(cap + s*n + t);
    *(residualgraph + s*n + t) = 0;

//    get bottleneck and update graph
    while(bfs(residualgraph, s, t, n, augmentedpath)){
        // finding min/ bottleneck
        for (int i = t; i > s; i = augmentedpath[i]) {
            bottleneck = min(bottleneck, *(residualgraph + augmentedpath[i] * n + i));
        }
        // update flow and residual graph
        for ( int i = t; i>s; i = augmentedpath[i]){
            *(residualgraph + augmentedpath[i] * n + i) -= bottleneck;
            *(flow + augmentedpath[i] * n + i) += bottleneck;
        }
    }
    delete[] residualgraph;
}



int main()
{  int cap[1000][1000], flow[1000][1000];
    int i,j, flowsum;
    for(i=0; i< 1000; i++)
        for( j =0; j< 1000; j++ )
            cap[i][j] = 0;

    for(i=0; i<499; i++)
        for( j=i+1; j<500; j++)
            cap[i][j] = 2;
    for(i=1; i<500; i++)
        cap[i][500 + (i/2)] =4;
    for(i=500; i < 750; i++ )
    { cap[i][i-250]=3;
        cap[i][750] = 1;
        cap[i][751] = 1;
        cap[i][752] = 5;
    }
    cap[751][753] = 5;
    cap[752][753] = 5;
    cap[753][750] = 20;
    for( i=754; i< 999; i++)
    {  cap[753][i]=1;
        cap[i][500]=3;
        cap[i][498]=5;
        cap[i][1] = 100;
    }
    cap[900][999] = 1;
    cap[910][999] = 1;
    cap[920][999] = 1;
    cap[930][999] = 1;
    cap[940][999] = 1;
    cap[950][999] = 1;
    cap[960][999] = 1;
    cap[970][999] = 1;
    cap[980][999] = 1;
    cap[990][999] = 1;
    printf("prepared capacity matrix, now executing maxflow code\n");
    maximum_flow(1000,0,999,&(cap[0][0]),&(flow[0][0]));
    for(i=0; i<=999; i++)
        for(j=0; j<=999; j++)
        {  if( flow[i][j] > cap[i][j] )
            {  printf("Capacity violated\n"); exit(0);}
        }
    for(i=0; i<=999; i++)
        for(j=0; j<=999; j++)
        {  if( flow[i][j] < 0 )
            {  printf("Flow value negative\n"); exit(0);}
        }
    for(i=1; i<999; i++)
    {  int inflow, outflow;
        inflow = 0;
        for( j=0; j <= 999; j++ )
            inflow += flow[j][i];
        outflow = 0;
        for( j=0; j <= 999; j++ )
            outflow += flow[i][j];
        if( inflow != outflow )
        {  printf("Flow conservation fails at vertex %d\n",i); exit(0);}
    }
    printf("Flow is a valid flow\n");
    flowsum = 0;
    for(i=0; i<=999; i++)
        flowsum += flow[0][i];
    printf("Outflow of  0 is %d, should be 10\n", flowsum);
    flowsum = 0;
    for(i=0; i<=999; i++)
        flowsum += flow[i][999];
    printf("Inflow of 999 is %d, should be 10\n", flowsum);

    printf("End Test\n");
}
