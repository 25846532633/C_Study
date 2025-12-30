//#include <stdio.h>
//#include <stdbool.h>
//
//bool searchMatrix(int matrix[][4], int row, int col, int target)
//{
//	if (row == 0 || col == 0)//行列皆为0
//		return false;
//	int i = 0, j = 0;
//	while (i < row && j < col)
//	{
//		if (matrix[i][j] == target)
//			return true;
//		else if (matrix[i][j] > target)
//		{
//			j--;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return false;
//}
//
//
//int main() {
//	int matrix[][4] = {
//		{1, 3, 5, 7},
//		{2, 4, 8, 9},
//		{6, 10, 11, 12},
//		{13, 14, 15, 16}
//	};
//	int target = 10;
//
//	if (searchMatrix(matrix, 4, 4, target)) {
//		printf("找到 %d\n", target);
//	}
//	else {
//		printf("未找到 %d\n", target);
//	}
//
//	return 0;
//}