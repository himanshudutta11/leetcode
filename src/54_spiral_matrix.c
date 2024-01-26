/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdio.h>
#include <stdlib.h>
/*int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  int numRows = matrixSize;
  int numCols = *matrixColSize;
  printf("Spiral order \n");
  int *out = (int *)malloc(numRows*numCols*sizeof(int));
  int i = 0; 
  int j = 0;
  int k = 0;
  int right = 0;
  int left = 0;
  int top = 0;
  int bottom = 0;
  while(k < numRows*numCols)
  {
    printf("Spiral order k = %d \n", k);
    for(; j < numCols-right; j++)
    {
      out[k++] = matrix[i][j];
    }
    right++; i++;
    for(; i < numRows-bottom; i++)
    {
      out[k++] = matrix[i][j];
    }
    bottom++; j--;
    for(; j >= left; j--)
    {
      out[k++] = matrix[i][j];
    }
    left++; i--;
    for(; i > top; i--)
    {
      out[k++] = matrix[i][j];
    }
    top++; j++;
  }
  return out;  
}
*/
/*
int* spiralOrder(int** matrix, int matrixRowSize, int matrixColSize) {
  int top, bottom, left, right, where;
  int i;
  int *p = (int *)malloc(matrixRowSize * matrixColSize * sizeof(int));
  if (!p) {
     return p;
  }

  i = 0;
  top = 0;
  left = 0;
  bottom = matrixRowSize;
  right = matrixColSize;

  while (i < matrixRowSize * matrixColSize) {
  if (top < bottom) {
      where = left;
      while (where < right) 
      { // on top, left -> right
        p[i++] = matrix[top][where];
        where ++;
      }
      top ++;
    }
    if (right > left) {
      where = top;
      while (where < bottom) { // on right, top -> bottom
        p[i++] = matrix[where][right - 1];
        where ++;
      }
      right --;
    }
    if (bottom > top) { // on bottom, right -> left
      where = right;
      while (where > left) {
        p[i++] = matrix[bottom - 1][where - 1];
        where --;
      }
      bottom --;
    }
    if (left < right) { // on left, bottom -> top
      where = bottom;
      while (where > top) {
        p[i++] = matrix[where - 1][left];
        where --;
      }
      left ++;
    }
  }

  return p;
}*/

int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  int rows = matrixSize;
  int cols = *matrixColSize;

  int *array = (int *)calloc(rows*cols, sizeof(int));

  int i = 0;
  int top = 0;
  int left = 0;
  int bottom = rows;
  int right = cols;
  int index;

  while(i < rows * cols)
  {
    /* First==> Top left to right */
    if(top < bottom)
    {
      index = left;
      while(index < right)
      {
        array[i++] = matrix[top][index];
        index++;
      }
      top++;
    }
    /* Second==> Top right to bottom */
    if(right > left)
    {
      index = top;
      while(index < bottom)
      {
        array[i++] = matrix[index][right-1];
        index++;
      }
      right--;
    }
    /* 3rd ==> Bottom right to left */
    if(bottom > top)
    {
      index = right;
      while(index > left)
      {
        array[i++] = matrix[bottom-1][index-1];
        index--;
      }
      bottom--;
    }
    /* 4th ==>  Bottom left to Top left */
    if(left < right)
    {
      index = bottom;
      while (index > top)
      {
        array[i++] = matrix[index-1][left];
        index--;
      }
      left++;
    }
  }

  *returnSize = i;
  return array;

}

int main()
{
    int *ret;
    int mat[3][3] = {
                {4 , 5, 6},
                {1 , 2, 14},
                {11 , 2, 1},
                };
    int **matrix = (int **)calloc(3, sizeof(int *));
    for(int i = 0; i < 3; i++)
    {
        matrix[i] = (int *)calloc(3, sizeof(int));
    } 

    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            matrix[i][j] = mat[i][j];
        }
    } 

    int col = 3;
    int retsize;
    printf("Before the spiral order\n");
    ret = spiralOrder(matrix, 3, &col, &retsize);
//    ret = spiralOrder(matrix, 3, 3);
    printf("After the spiral order\n");

    for(int i = 0; i < 9; i++)
    {
        printf("ret[%d] = %d\n", i , ret[i]);
    }
    return 0;               
}