#include <stdio.h>
#include <math.h>
void display(int arr[][10], int p, int q)
{
    for (int i = 0; i < p; i++)
    {
        printf("|\t");
        for (int j = 0; j < q; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("|\n");
    }
}

void matrixPower(int arrResult[][10], int arr1[][10], int arr2[][10], int p)
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < p; j++)
        {
            arrResult[i][j] = 0;
            for (int k = 0; k < p; k++)
            {
                arrResult[i][j] = arrResult[i][j] + arr1[i][k] * arr2[k][j];
            }
        }
    }
}

int matrixInput(int arr[][10], int p, int q)
{
    for (int i = 0; i < p; i++)
    {
        printf("\aEnter Elements Of %d Row:\n", i + 1);
        for (int j = 0; j < q; j++)
        {
            printf("a[%d][%d] = ", i + 1, j + 1);
            scanf("%d", &arr[i][j]);
        }
        printf("\n");
    }
}

int determinantOFMatrix(int a[][10])
{
    int det;
    return det = (a[0][0] * a[1][1] * a[2][2]) - (a[0][0] * a[2][1] * a[1][2]) - (a[0][1] * a[1][0] * a[2][2]) + (a[0][1] * a[2][0] * a[1][2]) + (a[0][2] * a[1][0] * a[2][1]) - (a[0][2] * a[2][0] * a[1][1]);
}

void main()
{
    int a[10][10], b[10][10], c[10][10], d[10][10], e[10][10], det, i, j, k, p, q, r, s, t, oper, trace, minor;
    double x, y, z, root1, root2, rp, deter, ip;
    printf("Welcome to Matix Calculator!\n");
repeat:
    printf("\nPress \n'1' for Addition\n'2' for Subtraction\n'3' for Multiplication\n");
    printf("'4' for Square\n'5' for Cube\n'6' for A^4\n'7' for Determinant of Matrix of Order 3\n");
    printf("'8' for Characteristic Equation of matrix of Order 3\n'9' for Roots of Quadratic Equation\n");
    scanf("%d", &oper);

    if (1 <= oper && oper <= 3)
    {
        printf("\aEnter the Number of Rows and Columns of Matrix A:\n");
        scanf("%d %d", &p, &q);
        printf("\aEnter the Number of Rows and Columns of Matrix B:\n");
        scanf("%d %d", &r, &s);
        printf("\a\tEnter the elements of Matrix A:\n"); // input element of Matrix A
        matrixInput(a, p, q);
        printf("\a\tEnter the element of Matrix B:\n"); // input element of Matrix B
        matrixInput(b, r, s);
        printf("\aMatrix A is given below:\n"); // Output element of Matrix A
        display(a, p, q);
        printf("\n");
        printf("\aMatrix B is given below:\n"); // Output element of Matrix B
        display(b, r, s);
        printf("\n");
        switch (oper) // Operations
        {
        case 1: // Addition
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < s; j++)
                {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            printf("\aAddition of Matrix A and Matrix B is given below:\n");
            display(c, p, s);
            break;

        case 2: // Subtraction
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < s; j++)
                {
                    c[i][j] = a[i][j] - b[i][j];
                }
            }
            printf("\aSubtraction of Matrix A and Matrix B is given below:\n");
            display(c, p, s);
            break;

        case 3: // Multiplication
            if (q != r)
            {
                printf("\aMultiplication is not Possible!\n");
                printf("\aAs No. of columns of A is not equals to No. of rows of B\n");
            }
            else
            {
                for (i = 0; i < p; i++)
                {
                    for (j = 0; j < s; j++)
                    {
                        c[i][j] = 0;
                        for (k = 0; k < r; k++)
                        {
                            c[i][j] = c[i][j] + a[i][k] * b[k][j];
                        }
                    }
                }
                printf("\aProduct of Matrix A and Matrix B is given below:\n");
                display(c, p, s);
            }
            break;
        }
    }
    else if (4 <= oper && oper <= 6)
    {
        printf("\aEnter the Order of Matrix:\n");
        scanf("%d", &p);
        printf("\t\aEnter the elements of Matrix:\n");
        matrixInput(a, p, p);
        printf("\aMatrix is given below:\n"); // Output element of Matrix A
        display(a, p, p);

        switch (oper)
        {
        case 4:
            printf("\aSquare of Matrix is given below:\n");
            matrixPower(c, a, a, p);
            display(c, p, p);
            break;

        case 5:
            printf("\aCube of Matrix is given below:\n");
            matrixPower(c, a, a, p);
            matrixPower(d, c, a, p);
            display(d, p, p);
            break;

        case 6:
            printf("\aA^4 of Matrix is given below:\n");
            matrixPower(c, a, a, p);
            matrixPower(e, c, c, p);
            display(e, p, p);
            break;
        }
    }
    else if (oper == 7 || oper == 8)
    {
        p = 3;
        printf("\t\aEnter the elements of Matrix:\n");
        matrixInput(a, p, p);
        printf("\aMatrix is given below:\n"); // Output element of Matrix A
        display(a, p, p);
        det = determinantOFMatrix(a);
        if (oper == 4)
            printf("Determinant of Matrix is %d\n", det);

        else
        {
            trace = a[0][0] + a[1][1] + a[2][2];
            minor = a[1][1] * a[2][2] - a[2][1] * a[1][2] + a[0][0] * a[2][2] - a[2][0] * a[0][2] + a[0][0] * a[1][1] - a[1][0] * a[0][1];
            printf("Characteristic Equation = ");
            printf("A^3- (%d)A^2 + (%d)A - (%d) = 0\n", trace, minor, det);
        }
    }
    else if (oper == 9)
    {
        printf("Coefficient of x^2 = ");
        scanf("%lf", &x);
        printf("Coefficient of x = ");
        scanf("%lf", &y);
        printf("Constant term = ");
        scanf("%lf", &z);
        deter = y * y - 4 * x * z;
        if (deter > 0)
        {
            root2 = (-y - sqrt(deter)) / (2 * x);
            root1 = (-y + sqrt(deter)) / (2 * x);
            printf("\nFirst Root = %.2lf\nSecond Root = %.2lf\n", root1, root2);
        }
        else if (deter == 0)
        {
            root1 = root2 = -y / (2 * x);
            printf("\nFirst Root = Second Root = %.2lf\n", root1);
        }
        else
        {
            rp = -y / (2 * x);
            ip = sqrt(-deter) / (2 * x);
            printf("\nRoots are imaginary\n");
            printf("First Root = %.2lf+%.2lfi \nSecond Root = %.2lf-%.2lfi\n", rp, ip, rp, ip);
        }
    }
    else
        printf("\aYou Entered wrong Operator!\n");

    printf("\n*******\n");
    printf("Do you want to calculate more ?\n");
    printf("Press '1' for Yes and '2' for No\n");
    scanf("%d", &t);
    if (t == 1)
        goto repeat;
    else
        printf("Thanks for using me!");
}
