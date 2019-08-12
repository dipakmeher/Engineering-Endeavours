#include<stdio.h>
int main()
{
         int m;
         scanf("%d", &m);
         int pile[m];
         for(int i = 0; i< m; i++)
         {
                       scanf("%d", &pile[i]);
         }
         int N;
         scanf("%d", &N);
         int numbers[100];
         int num = 1;
         for(int i = 0; i < 100; i++)
         {
                       numbers[i] = num++;
         }
         int arr[100][100];
         int count = 0;
         while(count < m)
         {
                       int r = pile[count];
                       int c = 100 / pile[count];
                       if(pile[count] % 2 != 0)
                       {
                                     c = c + 1;
                       }
                       int num = 0;
                       int x = 0;
                       int flag = 0;
                       for(int i = 0; i < r; i++)
                       {
                                     num = x;
                                     for(int j = 0; j < c; j++)
                                     {
                                                    if(j == 0)
                                                    {
                                                                  arr[i][j] = numbers[num];
                                                                  num = num + pile[count];
                                                    }
                                                    else
                                                    {
                                                                  int val = numbers[num];
                                                                  num = num + pile[count];
                                                                  if(val > 100)
                                                                  {
                                                                                 break;
                                                                  }
                                                                  else
                                                                  {
                                                                                 arr[i][j] = val;
                                                                  }
                                                    }
                                     }
                                     x++;
                       }
                       int index = 0;
                       for(int i = 0; i < r; i++)
                       {
                                     for(int j = 0; j < c; j++)
                                     {
                                                    if(arr[i][j] != 0)
                                                    {
                                                                  numbers[index++] = arr[i][j];
                                                    }
                                     }
                       }
                       count++;
         }
         printf("%d", numbers[N - 1]);
 
         }
 