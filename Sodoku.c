#include <stdio.h>
#include <stdbool.h>

#define n 9

void print_sodoku(int arr[n][n]) {
	int i = 0;
	while (i < n) {
		int j = 0;
		while (j < n) {
			printf("%d ",arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

int is_blank(int grid[n][n], int row, int col, int num) {
	int x = 0;
	while(x < 9) {
		if (grid[row][x] == num) {
			return false;
		}
		x++;
	}
	x = 0;
	while (x < 9) {
		if (grid[x][col] == num) {
			return false;
		}
		x++;
	}
	int first_row = row - row % 3;
	int first_col = col - col % 3;
	int i = 0;
	while (i < 3) {
		int j = 0;
		while (j < 3) {
			if (grid[i + first_row][j + first_col] == num) {
				return false;
			}
			j++;
		}
		i++;
	}
	return true;
}

int solve_sodoku (int grid[n][n], int row, int col) {
	if (row == n - 1 && col == n) {
		return true;
	} if (col == n) {
		row++;
		col = 0;
	} if (grid[row][col] > 0) {
		return solve_sodoku (grid, row, col + 1);
	}
	int num = 1;
	while (num <= n) {
		if (is_blank (grid, row, col, num) == true) {
			grid[row][col] = num;
			if (solve_sodoku (grid, row, col + 1) == true) {
				return true;
			}
		}
		grid[row][col] = 0;
		num++;
	}
	return false;
}

int main() {
	int grid[n][n] = {{0, 0, 0, 6, 8, 0, 9, 0, 0},
	{0, 0, 0, 0, 0, 3, 6, 0, 0},
	{0, 0, 0, 9, 0, 1, 0, 0, 4},
	{0, 3, 0, 0, 0, 0, 0, 7, 0},
	{0, 9, 5, 0, 0, 7, 1, 6, 0},
	{0, 6, 7, 0, 9, 0, 5, 3, 0},
	{0, 0, 0, 2, 0, 9, 0, 0, 0},
	{0, 0, 0, 5, 0, 8, 7, 0, 0},
	{6, 0, 0, 7, 0, 0, 8, 9, 1}};

	if (solve_sodoku (grid, 0, 0) == true) {
		print_sodoku (grid);
	} else {
		printf("No solution exists");
	}
	return 0;
}

