/// http://www.dreamincode.net/forums/topic/55572-conways-game-of-life/
/// downloaded by copy-paste on 8/19/2015 and modified to use an infinite loop
/// and have different Rule functions.
///
/// This code needs serious work in these areas:
/// <ol>
/// <li>  syntax: there are a number of warnings that cause errors.
/// </li>
/// <li>  semantics: the game algorithm implementation is incorrect.
/// </li>
/// <li>  design: the implementation needs function and value refactoring.
/// </li>
/// <li>  style: formatting is poor; the mix of TAB and spaces indentation
/// needs correction, and spacing between tokens is inconsistent.
/// The course style puts the '{' at the end of the function header, not
/// on a line of its own. You should make the formatting consistent.
/// </li>
/// <li>  documentation: documentation is non-existent except for this block.
/// </li>
/// </ol>
///
/**
 * good-life.c
 * Conway's Game of Life - Student Version for CSCI243_hw3
 * Contributing author: Celestyn Michalski
 * Date: 09/17/2025
*/
#include <stdio.h>
#include <stdlib.h>

void header(void)
{
      printf("\n\t..Welcome to the Game of life..\n");
}

void survivalRule(char life[][20]) //fix 5: x and y are never used
{
      int row, col;
      int neighbors = 0;
      for(row = 1; row<19; row++)
      {
         for(col = 1; col<19; col++)
         {
            if(life[row][col]== '*') // fix 3: Use single char comparison instead of string literals
            {
               if(life[row - 1][col - 1] == '*')
                  ++neighbors;
               if(life[row - 1][col] == '*')
                  ++neighbors;
               if(life[row - 1][col + 1] == '*')
                  ++neighbors;
               if(life[row][col - 1] == '*')
                  ++neighbors;
               if(life[row][col + 1] == '*')
                  ++neighbors;
               if(life[row + 1][col - 1] == '*')
                  ++neighbors;
               if(life[row + 1][col] == '*')
                  ++neighbors;
               if(life[row + 1][col + 1] == '*')
                  ++neighbors;
               if(neighbors == 2 || neighbors == 3)
               {
                  life[row][col] = '*'; //fix 2: corrected '==' to '=' for assignment
               }
            }
         }
      }
      return;
}

void birthRule(char life[][20]) // fix 5: x and y are never used
{
      int row, col;
      int neighbors = 0;
      for(row = 1; row<19; row++)
      {
         for(col = 1; col<19; col++)
         {
            if(life[row][col]== ' ') // fix 3: Use single char comparison instead of string literals.
            {
               if(life[row - 1][col - 1] == '*')
                  neighbors++;
               if(life[row - 1][col] == '*')
                  neighbors++;
               if(life[row - 1][col + 1] == '*')
                  neighbors++;
               if(life[row][col - 1] == '*')
                  neighbors++;
               if(life[row][col + 1] == '*')
                  neighbors++;
               if(life[row + 1][col - 1] == '*')
                  neighbors++;
               if(life[row + 1][col] == '*')
                  neighbors++;
               if(life[row + 1][col + 1] == '*')
                  neighbors++;
               if(neighbors == 3)
               {
                   life[row][col] = '*'; // fix 2: corrected '==' to '=' for assignment
               }
            }
         }
      }
      return;
}


int main(int argc, char *args[])
{
      char life[20][20];
      int orgs; // fix 6: removed declared but unused variable 'gens'
      int i, row, col; // fix 6: removed declared but unused variables 'a' and 'b'
      int count = 0;
      // fix 6: removed declared but unused variables 'ans', 'y', and 'x'
      if (argc != 2) { return 1; }
      header();

      // convert command line argument to an int
      orgs = strtol( args[1], NULL, 10 );

      srand( 31 );

      for(i = 0; i<orgs; i++)
      {
          row = rand();
          row %= 20;
          col = rand();
          col %= 20;
          life[row][col] = '*'; // fix 2: corrected '==' to '=' for assignment
      }

      for(row = 0; row<20; row++)
      {
          for(col = 0; col<20; col++)
          {
              if(life[row][col] != '*')
                  life[row][col] = ' '; //fix 2: correct '==' to '=' for assignment
          }
      }

      for(row = 0; row<20; row++)
      {
          for(col = 0; col<20; col++)
          {
              printf("%c", life[row][col]); // fix 1: use %c for a single char, not %s
          }
          puts(" ");
      }

      for (count = 0; count < 50; count++) // fix 4: limit program to 50 generations.
      {
          birthRule(life); // fix 5: x and y are never used.
          survivalRule(life); // fix 5: x and y are never used.
          for(row = 0; row<20; row++)
          {
              for(col = 0; col<20; col++)
              {
                  printf("%c", life[row][col]); // fix 1: use %c for a single char, not %s
              }
              puts(" ");
          }
          printf("\ngeneration: %d\n", count);
          count++;
      }

      return 0;
}

