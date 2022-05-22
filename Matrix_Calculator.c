#include <stdio.h>
#include <math.h>

void main()
{ 
    int a[10][10], b[10][10], c[10][10], d[10][10], e[10][10], det, i, j, k, p, q, r, s, t, oper, trace, minor;
    double x, y, z, root1, root2, rp, deter,ip;
    printf("Welcome to Matix Calculator!\n");
repeat:
    printf("\nPress \n'1' for Addition\n'2' for Subtraction\n'3' for Multiplication\n");
    printf("'4' for Square\n'5' for Cube\n'6' for A^4\n'7' for Determinant of Matrix of Order 3\n");
    printf("'8' for Characteristic Equation of matrix of Order 3\n'9' for Roots of Quadratic Equation\n");
    scanf("%d", &oper);
    if (oper > 9)
        printf("\aYou Entered wrong Operator!\n");
    else if (oper < 1)
        printf("\aYou Entered wrong Operator");

    else if (oper == 9) // Roots
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
            ip = sqrt(-deter)/ (2 * x);
            
            printf("\nRoots are imaginary\n");
            
            printf("First Root = %.2lf+%.2lfi \nSecond Root = %.2lf-%.2lfi\n", rp,ip, rp, ip);
        }
    }

    else if (oper > 3)
    {
        printf("\aEnter the Order of Matrix:\n");
        scanf("%d", &p);

        printf("\t\aEnter the elements of Matrix:\n");
        for (i = 0; i < p; i++)
        {
            printf("\aEnter Elements Of %d Row:\n", i + 1);
            for (j = 0; j < p; j++)
            {
                printf("a[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
            printf("\n");
        }

        printf("\aMatrix is given below:\n"); // Output element of Matrix A
        for (i = 0; i < p; i++)
        {
            printf("|\t");
            for (j = 0; j < p; j++)
            {
                printf("%d\t", a[i][j]);
            }
            printf("|\n");
        }

        printf("\n");

        // for Square
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < p; j++)
            {
                c[i][j] = 0;
                for (k = 0; k < p; k++)
                {
                    c[i][j] = c[i][j] + a[i][k] * a[k][j];
                }
            }
        }
        // for Cube
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < p; j++)
            {
                d[i][j] = 0;
                for (k = 0; k < p; k++)
                {
                    d[i][j] = d[i][j] + c[i][k] * a[k][j];
                }
            }
        }
        // for A^4
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < p; j++)
            {
                e[i][j] = 0;
                for (k = 0; k < p; k++)
                {
                    e[i][j] = e[i][j] + c[i][k] * c[k][j];
                }
            }
        }

        // for Determinant
        det = (a[0][0] * a[1][1] * a[2][2]) - (a[0][0] * a[2][1] * a[1][2]) - (a[0][1] * a[1][0] * a[2][2]) + (a[0][1] * a[2][0] * a[1][2]) + (a[0][2] * a[1][0] * a[2][1]) - (a[0][2] * a[2][0] * a[1][1]);

        // Characteristic Equation
        trace = a[0][0] + a[1][1] + a[2][2];
        minor = a[1][1] * a[2][2] - a[2][1] * a[1][2] + a[0][0] * a[2][2] - a[2][0] * a[0][2] + a[0][0] * a[1][1] - a[1][0] * a[0][1];

        switch (oper) // output Square
        {
        case 4:
            printf("\aSquare of Matrix is given below:\n");
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < p; j++)
                {
                    printf("%d\t", c[i][j]);
                }

                printf("\n");
            }
            break;

        case 5: // output Cube

            printf("\aCube of Matrix is given below:\n");
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < p; j++)
                {
                    printf("%d\t", d[i][j]);
                }

                printf("\n");
            }
            break;

        case 6: // output A^4

            printf("\aA^4 of Matrix is given below:\n");
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < p; j++)
                {
                    printf("%d\t", e[i][j]);
                }

                printf("\n");
            }
            break;

        case 7: // output Determinant
            if (p == 3)
            {
                printf("Determinant of Matrix A is %d\n", det);
            }
            else
            {
                printf("Error! Order is not 3\n");
            }
            break;

        case 8: // Characteristic Equation
            if (p == 3)
            {
                printf("Characteristic Equation = ");
                printf("A^3- (%d)A^2 + (%d)A - (%d) = 0\n", trace, minor, det);
            }
            else
            {
                printf("Error! Order is not 3\n");
            }
            break;

        default:
            printf("You Entered a wrong Keyword!\n");
        }
    }

    else
    {

        printf("\aEnter the Number of Rows and Columns of Matrix A:\n");
        scanf("%d %d", &p, &q);
        printf("\aEnter the Number of Rows and Columns of Matrix B:\n");
        scanf("%d %d", &r, &s);

        printf("\a\tEnter the elements of Matrix A:\n"); // input element of Matrix A
        for (i = 0; i < p; i++)
        {
            printf("\aEnter Elements Of %d Row:\n", i + 1);
            for (j = 0; j < q; j++)
            {
                printf("a[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &a[i][j]);
            }
            printf("\n");
        }

        printf("\a\tEnter the element of Matrix B:\n"); // input element of Matrix B
        for (i = 0; i < r; i++)
        {
            printf("\aEnter Elements Of %d Row:\n", i + 1);
            for (j = 0; j < s; j++)
            {
                printf("b[%d][%d] = ", i + 1, j + 1);
                scanf("%d", &b[i][j]);
            }
            printf("\n");
        }

        printf("\aMatrix A is given below:\n"); // Output element of Matrix A
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("%d\t", a[i][j]);
            }
            printf("\n");
        }

        printf("\n");

        printf("\aMatrix B is given below:\n"); // Output element of Matrix B
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < s; j++)
            {
                printf("%d\t", b[i][j]);
            }

            printf("\n");
        }

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
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < s; j++)
                {
                    printf("%d\t", c[i][j]);
                }

                printf("\n");
            }
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
            for (i = 0; i < p; i++)
            {
                for (j = 0; j < s; j++)
                {
                    printf("%d\t", c[i][j]);
                }

                printf("\n");
            }
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
                for (i = 0; i < p; i++)
                {
                    for (j = 0; j < s; j++)
                    {
                        printf("%d\t", c[i][j]);
                    }

                    printf("\n");
                }
            }
            break;

        default:
            printf("\aYou Entered Wrong Operator\n");
        }
    }

    printf("Do you want to calculate more ?\n");
    printf("Press '1' for Yes and '2' for No\n");
    scanf("%d", &t);

    if (t == 1)
        goto repeat;

    else
        printf("Thanks for using me!");
}
