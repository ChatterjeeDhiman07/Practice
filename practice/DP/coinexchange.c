#include<stdio.h>
#include<stdlib.h>

int count(int S[], int m, int n)
{
    int i,j,x,y;
    int table[n+1][m];

    for (i=0; i<m; i++) 
        table[0][i] = 1; 
     for (i = 1; i < n+1; i++) 
    { 
        for (j = 0; j < m; j++) 
        { 
            // Count of solutions including S[j] 
            x = (i-S[j] >= 0)? table[i - S[j]][j]: 0; 
  
            // Count of solutions excluding S[j] 
            y = (j >= 1)? table[i][j-1]: 0; 
  
            // total count 
            table[i][j] = x + y; 
        }
    }
    return table[n][m-1];
}

int main() 
{ 
    int arr[] = {1, 2, 3, 4}; 
    int m = sizeof(arr)/sizeof(arr[0]); 
    int n = 7; 
    printf(" %d ", count(arr, m, n)); 
    return 0; 
} 
