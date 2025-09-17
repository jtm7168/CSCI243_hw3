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
 *
 * Implements a 20x20 Conway's Game of Life Grid with wraparound edges.
 * The program runs for 50 generations, printing the grid to stdout.
*/

#include <stdio.h>
#include <stdlib.h>

#define GRID_SIZE 20 // fix 7: Replaced magic number for grid size
#define MAX_GEN 50 //fix 7: Number of generations

void header(void)
{
      printf("\n\t..Welcome to the Game of life..\n");
}
/**
 * count_neighbors - counts live neighbors for a cell with wrap-around
 * @size: size of gride
 * @life: current life grid
 * @row: row index of the cell
 * @col: column index of the cell
 *
 * Returns the number of live neighbors ('*') around the given cell
 */
int count_neighbors(int size, char life[][size], int row, int col)
{
	int dr;
	int dc;
	int r;
	int c;
	int count = 0;

	for(dr = -1; dr <= 1; dr++)
	{
		for(dc = -1; dc <= 1; dc++)
		{
			if(dr == 0 && dc == 0)
			{
				continue; // skip the cell itself
			}
			r = (row + dr + size) % size; // wrap row
			c = (col + dc + size) % size; // wrap col
			if(life[r][c] == '*')
			{
				count++;
			}
		}
	}
	return count;
}

/**
 * next_generation - computes the next life grid based on Conway's rules
 * @size: size of grid
 * @life: current life grid (updated in place)
 *
 * Uses a temporary grid to compute the next state, then copies back
 */
void next_generation(int size, char life[][size])
{
	char next[size][size];
	int row;
	int col;
	int neighbors;
	
	// Compute the next states
	for(row = 0; row < size; row++)
	{
		for(col = 0; col < size; col++)
		{
			neighbors = count_neighbors(size, life, row, col);
			if((life[row][col] == '*') && (neighbors == 2 || neighbors == 3))
			{
				next[row][col] = '*'; // survives
			}
			else if((life[row][col] == ' ') && (neighbors == 3))
			{
				next[row][col] = '*'; // birth
			}
			else
			{
				next[row][col] = ' '; // death
			}
		}
	}

	// Copy next state back to life grid
	for(row = 0; row < size; row++)
	{
		for(col = 0; col < size; col++)
		{
			life[row][col] = next[row][col];
		}
	}
}

/**
 * print_grid - prints the current life grid
 * @size: size of grid
 * @life: currnt life grid
 */
void print_grid(int size, char life[][size])
{
	int row;
	int col;
	for(row = 0; row < size; row++)
	{
		for(col = 0; col < size; col++)
		{
			printf("%c", life[row][col]);
		}
		puts("");
	}
}

int main(int argc, char *argv[])
{
      char life[GRID_SIZE][GRID_SIZE];
      int orgs, gen;
      int i, row, col; // fix 6: removed declared but unused variables 'a' and 'b'
      // fix 6: removed declared but unused variables 'ans', 'y', and 'x'
      if (argc != 2)
      {
	      return 1;
      }
      header();

      // convert command line argument to an int
      orgs = strtol( argv[1], NULL, 10 );

      // Initialize grid to empty
      for(row = 0; row < GRID_SIZE; row++)
      {
	      for(col = 0; col < GRID_SIZE; col++)
	      {
		      life[row][col] = ' ';
	      }
      }

      srand(31);

      // Place organisms, avoiding collisions
      for(i = 0; i<orgs; )
      {
	      row = rand() % GRID_SIZE;
	      col = rand() % GRID_SIZE;
	      if(life[row][col] == ' ')
	      {
		      life[row][col] = '*';
		      i++;
	      }
      }

      // Print initial grid
      print_grid(GRID_SIZE, life);
      printf("generation: 0 \n");

      // Run 50 generations
      for(gen = 1; gen < MAX_GEN; gen++)
      {
	      next_generation(GRID_SIZE, life);
	      print_grid(GRID_SIZE, life);
	      printf("generation: %d\n", gen);
      }

      return 0;
}

