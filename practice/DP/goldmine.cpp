#include<iospace>
using namespace std;
#define MAX 100

int getMax(int gold[][MAX],int m, int n)
{
    int goldTable[m][n];
    memset(goldTable,0,sizeof(goldTable));

    for(int col=n-1;col>=0;col--)
    {
        for(int row=m-1;row>=0;row--)
        {
            int right= (col==n-1)?0:gold[row][col+1];

            int right_up=(col==n-1||row==0)?0:gold[row-1][col+1];

            int right_down=(col==n-1||row==m-1)?0:gold[row+1][col+1];

            goldTable[row][col]=gold[row][col]+max(right,right_up,right_down);
        }
    }

    int res = goldTable[0][0]; 
    for (int i=1; i<m; i++) 
        res = max(res, goldTable[i][0]); 
    return res;
}

int main() 
{ 
    int gold[MAX][MAX]= { {1, 3, 1, 5}, 
        {2, 2, 4, 1}, 
        {5, 0, 2, 3}, 
        {0, 6, 1, 2} 
    }; 
    int m = 4, n = 4; 
    cout << getMaxGold(gold, m, n); 
    return 0; 
} 
