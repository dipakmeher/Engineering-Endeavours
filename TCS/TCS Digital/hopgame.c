#include <stdio.h>
int MAX(int a, int b, int c)
              {
                             if(a>b && a>c)
                             {
                                           return a;
                             }
                             else if(b>c)
              {
                             return b;
              }
              else
              {
                             return c;
              }
}
int max_score(int stone_val[], int n,
                             int curr_stone_index,
                             int multi_factor,
                             int is_double_step_taken)
              {
              if(curr_stone_index>= n)
                             {
                                           return 0;
                             }
                                           int score = 0;
              if(curr_stone_index != -1)
                             {
                                           score = multi_factor * stone_val[curr_stone_index];
                             }
                             // No Skipping
                             // Moving to next stone
                             int val1 = max_score(stone_val, n,
              curr_stone_index + 1,
                                                                                      1, // multipli. factor
              is_double_step_taken);
                             // Skipping once
                             // multi factor = 2
                             int val2 = max_score(stone_val, n,
curr_stone_index + 2,
                                                                                      2, // multipli. factor
is_double_step_taken);
                             int val3 = 0;
if(is_double_step_taken == 0)
                             {
                                           val3 = max_score(stone_val, n,
curr_stone_index + 3,
                                                                                      3, // multipli. factor
                                                                                      1 /* set double step taken */);
                             }
                             int max_score_among_3_options = MAX(val1, val2, val3);
                             int total_Score = score + max_score_among_3_options;
                             return total_Score;
                             }
int main()
{
                             // int n = 3;
                             // int stone_val[] = {4,2,3};
                             int n = 6;
                             int stone_val[] = {4,5,6,7,4,5};
printf("%d", max_score(stone_val, n,
                                                                                      -1, // Current step
1, // Multi factor
                                                                                      0 /* Double step taken */));
                             return 0;
}