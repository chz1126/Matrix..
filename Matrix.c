#include <stdio.h>
#include <stdlib.h>

// 定义矩阵结构体
typedef struct {
    int rows;    // 行数
    int cols;    // 列数
    int **data;  // 指向矩阵数据的指针
} Matrix;

// 创建矩阵
Matrix createMatrix(int rows, int cols) {
    Matrix mat;
    mat.rows = rows;
    mat.cols = cols;
    mat.data = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        mat.data[i] = (int *)malloc(cols * sizeof(int));
    }
    return mat;
}

// 释放矩阵内存
void freeMatrix(Matrix *mat) {
    for (int i = 0; i < mat->rows; i++) {
        free(mat->data[i]);
    }
    free(mat->data);
}

// 打印矩阵
void printMatrix(Matrix mat) {
    for (int i = 0; i < mat.rows; i++) {
        for (int j = 0; j < mat.cols; j++) {
            printf("%d ", mat.data[i][j]);
        }
        printf("\n");
    }
}

// 矩阵加法
Matrix addMatrix(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Matrices are not the same size.\n");
        exit(1);
    }
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] + b.data[i][j];
        }
    }
    return result;
}

// 矩阵减法
Matrix subtractMatrix(Matrix a, Matrix b) {
    if (a.rows != b.rows || a.cols != b.cols) {
        printf("Matrices are not the same size.\n");
        exit(1);
    }
    Matrix result = createMatrix(a.rows, a.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < a.cols; j++) {
            result.data[i][j] = a.data[i][j] - b.data[i][j];
        }
    }
    return result;
}

// 矩阵乘法
Matrix multiplyMatrix(Matrix a, Matrix b) {
    if (a.cols != b.rows) {
        printf("Matrices cannot be multiplied.\n");
        exit(1);
    }
    Matrix result = createMatrix(a.rows, b.cols);
    for (int i = 0; i < a.rows; i++) {
        for (int j = 0; j < b.cols; j++) {
            result.data[i][j] = 0;
            for (int k = 0; k < a.cols; k++) {
                result.data[i][j] += a.data[i][k] * b.data[k][j];
            }
        }
    }
    return result;
}

int main() {
    // 示例使用
    Matrix mat1 = createMatrix(2, 2);
    mat1.data[0][0] = 1; mat1.data[0][1] = 2;
    mat1.data[1][0] = 3; mat1.data[1][1] = 4;

    Matrix mat2 = createMatrix(2, 2);
    mat2.data[0][0] = 5; mat2.data[0][1] = 6;
    mat2.data[1][0] = 7; mat2.data[1][1] = 8;

    printf("Matrix 1:\n");
    printMatrix(mat1);
    printf("Matrix 2:\n");
    printMatrix(mat2);

    Matrix sum = addMatrix(mat1, mat2);
    printf("Sum:\n");
    printMatrix(sum);

    Matrix diff = subtractMatrix(mat1, mat2);
    printf("Difference:\n");
    printMatrix(diff);

    Matrix prod = multiplyMatrix(mat1, mat2);
    printf("Product:\n");
    printMatrix(prod);

    // 释放内存
    freeMatrix(&mat1);
    freeMatrix(&mat2);
    freeMatrix(&sum);
    freeMatrix(&diff);
    freeMatrix(&prod);

    return 0;
}
