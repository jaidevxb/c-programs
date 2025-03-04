/* 1. Swap two numbers using a third variable */
#include <stdio.h>
int main() {
    int a, b, temp;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    // Swapping values using a temporary variable
    temp = a;
    a = b;
    b = temp;
    printf("After swapping: %d %d", a, b);
    return 0;
}

/* 2. Store two student details using structure */
#include <stdio.h>
struct Student {
    char name[50];
    int age;
};
int main() {
    struct Student s1, s2;
    printf("Enter name and age of student 1: ");
    scanf("%s %d", s1.name, &s1.age);
    printf("Enter name and age of student 2: ");
    scanf("%s %d", s2.name, &s2.age);
    // Displaying student details
    printf("Student 1: %s, Age: %d\n", s1.name, s1.age);
    printf("Student 2: %s, Age: %d\n", s2.name, s2.age);
    return 0;
}

/* 3. Arithmetic operations using operators */
#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    // Performing basic arithmetic operations
    printf("Sum: %d\n", a + b);
    printf("Difference: %d\n", a - b);
    printf("Product: %d\n", a * b);
    printf("Quotient: %d\n", a / b);
    printf("Remainder: %d\n", a % b);
    return 0;
}

/* 4. Append to an existing file */
#include <stdio.h>
int main() {
    FILE *fp;
    char text[100];
    char ch;

    fp = fopen("records.txt", "a+");  
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Contents before appending:\n");
    rewind(fp);  
    while((ch = fgetc(fp)) != EOF) {  
        putchar(ch);  
    }

    printf("\nEnter text to append: ");
    scanf("%s", text);  
    fputs(text, fp);  
    fclose(fp);

    fp = fopen("records.txt", "r");  
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("\nContents after appending:\n");
    while((ch = fgetc(fp)) != EOF) {  
        putchar(ch);  
    }

    fclose(fp);
    printf("\nRecord added successfully!\n");
    return 0;
}


/* 5. Logical, relational, conditional operators */
#include <stdio.h>
int main() {
    int a = 5, b = 10;
    // Using relational operator
    printf("Relational: %d\n", a < b);
    // Using logical operator
    printf("Logical: %d\n", (a > 2 && b > 5));
    // Using conditional (ternary) operator
    int c = (a > b) ? a : b;
    printf("Conditional: %d\n", c);
    return 0;
}

/* 6. Write a block of structure elements to file using fwrite() */
#include <stdio.h>
struct Bike {
    char name[50];
    float average;
    float price;
};

int main() {
    FILE *fp;
    struct Bike b;
    char choice;

    fp = fopen("bikes.dat", "wb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    do {
        printf("Enter name, average, price: ");
        scanf("%s %f %f", b.name, &b.average, &b.price);
        fwrite(&b, sizeof(b), 1, fp);
        printf("Continue? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    fclose(fp);

    fp = fopen("bikes.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }
    printf("\nStored Bike Details:\n");
    while (fread(&b, sizeof(b), 1, fp) == 1) {
        printf("Name: %s, Average: %.2f, Price: %.2f\n", b.name, b.average, b.price);
    }

    fclose(fp);
    return 0;
}


/* 7. Even or Odd using if-else */
#include <stdio.h>
int main() {
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    // Checking even or odd
    if (num % 2 == 0)
        printf("Even\n");
    else
        printf("Odd\n");
    return 0;
}

/* 8. Print pattern */
#include <stdio.h>
int main() {
    int i, j;
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

/* 9. Allocate memory for books using calloc */
#include <stdio.h>
#include <stdlib.h>

// Struct is now globally accessible
struct Book {
    char author[50], name[50];
    int id;
};
int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book *books = (struct Book *)calloc(n, sizeof(struct Book));

    for (int i = 0; i < n; i++) {
        printf("Enter author, name, and ID for book %d: ", i + 1);
        scanf("%s %s %d", books[i].author, books[i].name, &books[i].id);
    }

    printf("Books:\n");
    for (int i = 0; i < n; i++) {
        printf("%s by %s (ID: %d)\n", books[i].name, books[i].author, books[i].id);
    }

    free(books);
    return 0;
}


/* 10. Check if a number is palindrome */
#include <stdio.h>
int main() {
    int num, ld, rev = 0, temp;
    printf("Enter a number: ");
    scanf("%d", &num);
    temp = num;
    while (temp != 0) {
        ld = temp % 10;
        rev = rev * 10 + ld;
        temp /= 10;
    }
    if (num == rev)
        printf("Palindrome\n");
    else
        printf("Not a Palindrome\n");
    return 0;
}

/* 11. Print number pattern */
#include <stdio.h>
int main() {
    int i, j;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
    for (i = 1; i <= 3; i++) {
        for (j = 3; j >= i; j--) {
            printf("%d", j);
        }
        printf("\n");
    }
    return 0;
}

/* 12. Logical, relational, conditional operators */
#include <stdio.h>
int main() {
    int a = 5, b = 10;
    // Using relational operator
    printf("Relational: %d\n", a < b);
    // Using logical operator
    printf("Logical: %d\n", (a > 2 && b > 5));
    // Using conditional (ternary) operator
    int c = (a > b) ? a : b;
    printf("Conditional: %d\n", c);
    return 0;
}

/* 13. Store and display 3 student details using structure */
#include <stdio.h>
struct Student {
    char name[50];
    int age;
};
int main() {
    struct Student s[3];
    for (int i = 0; i < 3; i++) {
        printf("Enter name and age: ");
        scanf("%s %d", s[i].name, &s[i].age);
    }
    for (int i = 0; i < 3; i++) {
        printf("%s %d\n", s[i].name, s[i].age);
    }
    return 0;
}

/* 14. Check Leap Year using goto */
#include <stdio.h>
int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);
    if (year % 4 == 0)
        goto leap;
    printf("Not a leap year\n");
    return 0;
    leap:
    printf("Leap year\n");
    return 0;
}

/* 15. Addition of two max 10x10 matrices */
#include <stdio.h>
int main() {
    int A[10][10], B[10][10], sum[10][10], i, j, row, col;
    printf("Enter the number of rows and columns for the matrices: ");
    scanf("%d %d", &row, &col);

    printf("Enter elements of the first matrix: \n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    printf("Enter elements of the second matrix: \n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    printf("Sum Matrix:\n");
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            sum[i][j] = A[i][j] + B[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// 16. Arithmetic operations by switch operator
#include <stdio.h>
int main() {
    int a, b;
    char op;
    printf("Enter two numbers and an operator (+, -, *, /): ");
    scanf("%d %d %c", &a, &b, &op);

    // Using switch to perform arithmetic operations
    switch (op) {
        case '+': printf("Sum: %d\n", a + b); break;
        case '-': printf("Difference: %d\n", a - b); break;
        case '*': printf("Product: %d\n", a * b); break;
        case '/': printf("Quotient: %d\n", a / b); break;
        default: printf("Invalid operator\n");
    }
    return 0;
}

// 17. Name, D.O.B, age of students - Nested structure
#include <stdio.h>
struct DOB {
    int day, month, year;
};
struct Student {
    char name[50];
    struct DOB dob;
    int age;
};
int main() {
    struct Student s;
    printf("Enter name, DOB (dd mm yyyy), and age: ");
    scanf("%s %d %d %d %d", s.name, &s.dob.day, &s.dob.month, &s.dob.year, &s.age);

    // Displaying student details
    printf("Name: %s\nDOB: %d/%d/%d\nAge: %d\n", s.name, s.dob.day, s.dob.month, s.dob.year, s.age);
    return 0;
}

// 18. Write a C program to find the number of arguments and their names
#include <stdio.h>
int main(int argc, char *argv[]) {
    // argc gives the number of arguments, argv stores the arguments
    printf("Number of arguments: %d\n", argc);
    printf("Argument names:\n");
    for (int i = 0; i < argc; i++) {
        printf("%s\n", argv[i]);
    }
    return 0;
}

// 19. Write a C program to insert an element in an array
#include <stdio.h>
int main() {
    int arr[100], n, pos, val;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position and value to insert: ");
    scanf("%d %d", &pos, &val);

    // Shifting elements to make space for the new element
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = val;
    n++;

    printf("Array after insertion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

// 20. Take input numbers and provide sum of odd and even numbers separately
#include <stdio.h>
int main() {
    int n, num, even_sum = 0, odd_sum = 0;
    printf("Enter number of inputs: ");
    scanf("%d", &n);
    printf("Enter numbers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &num);
        if (num % 2 == 0) even_sum += num; // Even number
        else odd_sum += num;               // Odd number
    }
    printf("Sum of even numbers: %d\n", even_sum);
    printf("Sum of odd numbers: %d\n", odd_sum);
    return 0;
}

// 21. Check if a string is a palindrome or not
#include <stdio.h>
#include <string.h>
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int len = strlen(str), flag = 1;

    // Checking if the string is a palindrome
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            flag = 0;
            break;
        }
    }
    if (flag) printf("Palindrome\n");
    else printf("Not a Palindrome\n");
    return 0;
}

// 22. Print the pattern
#include <stdio.h>
int main() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

// 23. Use dynamic memory allocation (calloc) to store author, book name, and book ID
#include <stdio.h>
#include <stdlib.h>

// Struct is now globally accessible
struct Book {
    char author[50], name[50];
    int id;
};
int main() {
    int n;
    printf("Enter number of books: ");
    scanf("%d", &n);

    struct Book *books = (struct Book *)calloc(n, sizeof(struct Book));

    for (int i = 0; i < n; i++) {
        printf("Enter author, name, and ID for book %d: ", i + 1);
        scanf("%s %s %d", books[i].author, books[i].name, &books[i].id);
    }
    printf("Books:\n");
    for (int i = 0; i < n; i++) {
        printf("%s by %s (ID: %d)\n", books[i].name, books[i].author, books[i].id);
    }
    free(books);
    return 0;
}

// 24. Matrix Multiplication
#include <stdio.h>
int main() {
    int A[10][10], B[10][10], result[10][10], r1, c1, r2, c2, i, j, k;
    printf("Enter rows and columns for first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter rows and columns for second matrix: ");
    scanf("%d %d", &r2, &c2);

    if (c1 != r2) {
        printf("Matrix multiplication not possible!\n");
        return 0;
    }

    printf("Enter elements of first matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c1; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (i = 0; i < r2; i++) {
        for (j = 0; j < c2; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix multiplication logic
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            result[i][j] = 0;
            for (k = 0; k < c1; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("Resultant matrix:\n");
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}

// 25. Given year is leap or not using goto statement
#include <stdio.h>
int main() {
    int year;
    printf("Enter a year: ");
    scanf("%d", &year);

    // Leap year logic using goto
    if (year % 4 == 0)
        goto leap;
    printf("Not a leap year\n");
    return 0;

    leap:
    printf("Leap year\n");
    return 0;
}

// 26. Write a program to get 10 numbers in an array and find the greatest among them
#include <stdio.h>
int main() {
    int arr[10], i, max;
    printf("Enter 10 numbers: ");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    // Finding the greatest number
    max = arr[0];
    for (i = 1; i < 10; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("Greatest number: %d\n", max);
    return 0;
}

// 27. Get 3 student details using struct
#include <stdio.h>
struct Student {
    char name[50];
    int age;
};
int main() {
    struct Student s[3];
    for (int i = 0; i < 3; i++) {
        printf("Enter name and age for student %d: ", i + 1);
        scanf("%s %d", s[i].name, &s[i].age);
    }

    // Displaying student details
    printf("Student Details:\n");
    for (int i = 0; i < 3; i++) {
        printf("Name: %s, Age: %d\n", s[i].name, s[i].age);
    }
    return 0;
}

// 28. Write a program to find the roots of a quadratic equation
#include <stdio.h>
#include <math.h>
int main() {
    float a, b, c, discriminant, root1, root2;
    printf("Enter coefficients a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    discriminant = b * b - 4 * a * c;

    // Calculating roots based on discriminant
    if (discriminant > 0) {
        root1 = (-b + sqrt(discriminant)) / (2 * a);
        root2 = (-b - sqrt(discriminant)) / (2 * a);
        printf("Roots are real and different: %.2f, %.2f\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("Roots are real and same: %.2f\n", root1);
    } else {
        printf("Roots are complex and imaginary.\n");
    }
    return 0;
}

// 29. Write a program to get information of students using union
#include <stdio.h>
union Student {
    char name[50];
    int age;
    float marks;
};
int main() {
    union Student s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Name: %s\n", s.name);

    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Age: %d\n", s.age);

    printf("Enter marks: ");
    scanf("%f", &s.marks);
    printf("Marks: %.2f\n", s.marks);

    // Union can store only one value at a time
    printf("Size of union: %d bytes\n", sizeof(s));
    return 0;
}

// 30. Check if given input is three using if and if true, perform addition and multiplication
#include <stdio.h>
int main() {
    int a, b, c;
    printf("Enter three numbers: ");
    int n = scanf("%d %d %d", &a, &b, &c);

    // Check input are 3
    if (n == 3) {
        printf("Sum: %d\n", a + b + c);
        printf("Product: %d\n", a * b * c);
    } else {
        printf("Inputs are not all 3.\n");
    }
    return 0;
}

// 31. Display student's name, gender, and account number using struct
#include <stdio.h>
struct Student {
    char name[50];
    char gender;
    int acc_no;
};
int main() {
    struct Student s;
    printf("Enter name, gender (M/F), and account number: ");
    scanf("%s %c %d", s.name, &s.gender, &s.acc_no);

    // Displaying student details
    printf("Name: %s\nGender: %c\nAccount Number: %d\n", s.name, s.gender, s.acc_no);
    return 0;
}

// 32. Separate odd and even numbers using while loop for given n numbers
#include <stdio.h>
int main() {
    int n, i;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Even numbers: ");
    for (i = 1; i <= n; i++) {
        if (i % 2 == 0) 
            printf("%d ", i);
    }
    printf("\nOdd numbers: ");
    for (i = 1; i <= n; i++) {
        if (i % 2 != 0)
            printf("%d ", i);
    }
    return 0;
}

// 33. Use structure to make student data for two students
#include <stdio.h>
struct Student {
    char name[50];
    int age;
};
int main() {
    struct Student s1, s2;
    printf("Enter name and age for student 1: ");
    scanf("%s %d", s1.name, &s1.age);
    printf("Enter name and age for student 2: ");
    scanf("%s %d", s2.name, &s2.age);

    // Displaying student details
    printf("Student 1: %s, Age: %d\n", s1.name, s1.age);
    printf("Student 2: %s, Age: %d\n", s2.name, s2.age);
    return 0;
}

// 34. Logical, relational, conditional operators
#include <stdio.h>
int main() {
    int a = 5, b = 10;
    // Relational operator
    printf("Relational: %d\n", a < b);
    // Logical operator
    printf("Logical: %d\n", (a > 2 && b > 5));
    // Conditional (ternary) operator
    int c = (a > b) ? a : b;
    printf("Conditional: %d\n", c);
    return 0;
}

// 35. Copy one file to another file
#include <stdio.h>
int main() {
    FILE *fp1, *fp2;
    char ch;
    fp1 = fopen("source.txt", "r");
    fp2 = fopen("destination.txt", "w");

    if (fp1 == NULL || fp2 == NULL) {
        printf("File not found!\n");
        return 0;
    }
    // Copying content from source to destination
    while ((ch = fgetc(fp1)) != EOF) {
        fputc(ch, fp2);
    }
    printf("File copied successfully!\n");

    fclose(fp1);
    fclose(fp2);

    fp2 = fopen("destination.txt", "r");
    if (fp2 == NULL) {
        printf("File not found!\n");
        return 0;
    }
    printf("Contents in destination after Copying \n");
    while((ch = fgetc(fp2)) != EOF){
        putchar(ch);
    }
    fclose(fp2);
    return 0;
}


// 36. Print odd and even numbers up to n
#include <stdio.h>
int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("Even numbers: ");
    for (int i = 1; i <= n; i++) {
        if (i % 2 == 0) printf("%d ", i);
    }

    printf("\nOdd numbers: ");
    for (int i = 1; i <= n; i++) {
        if (i % 2 != 0) printf("%d ", i);
    }
    return 0;
}

// 37. Save student data in union and print its size
#include <stdio.h>
union Student {
    char name[50];
    int age;
    float marks;
};
int main() {
    union Student s;
    printf("Enter name: ");
    scanf("%s", s.name);
    printf("Name: %s\n", s.name);

    printf("Enter age: ");
    scanf("%d", &s.age);
    printf("Age: %d\n", s.age);

    printf("Enter marks: ");
    scanf("%f", &s.marks);
    printf("Marks: %.2f\n", s.marks);

    // Union can store only one value at a time
    printf("Size of union: %d bytes\n", sizeof(s));
    return 0;
}

// 38. Sum of two values using call by value
#include <stdio.h>
int sum(int a, int b) {
    return a + b;
}
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    // Sum using call by value
    printf("Sum: %d\n", sum(a, b));
    return 0;
}

// 39. Factorial by do-while loop
#include <stdio.h>
int main() {
    int n, fact = 1, i = 1;
    printf("Enter a number: ");
    scanf("%d", &n);

    // Calculating factorial using do-while loop
    do {
        fact *= i;
        i++;
    } while (i <= n);

    printf("Factorial of %d: %d\n", n, fact);
    return 0;
}

// 40. Matrix Multiplication
// 41. Preprocessor directives
#include <stdio.h>
#define PI 3.14
#define SQUARE(x) (x * x)
#ifndef MIN
    #define MAX(a,b) (a > b) ? a : b
#endif
#define DEBUG 1
int main() {
    int r = 5;
    printf("Area of circle: %.2f\n", PI * SQUARE(r));
    printf("Max of 5 and 10 is : %d\n", MAX(5,10));
    #if DEBUG
        printf("Debugging is enabled\n");  // This code will be included if DEBUG is defined as 1
    #else
        printf("Debugging is disabled\n");
    #endif
    #undef PI
    // prinf("PI is %d", PI); wont work as pi is undefined
    return 0;
}

// 42. Get inputs in an array, delete an element, and print the remaining elements
#include <stdio.h>
int main() {
    int arr[100], n, pos;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // Deleting element by shifting
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;

    printf("Array after deletion: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}

// C Program Using All Preprocessor Directives:
#include <stdio.h> 
#include <stdlib.h>

#define MAX 100  // Defining a constant for maximum value
#ifdef MAX
    #define PI 3.14  // Define PI if MAX is defined
#else
    #define PI 3.14159  // Use a different value of PI if MAX is not defined
#endif
#ifndef MIN  // Check if MIN is not defined
    #define MIN 10  // Define MIN if it's not already defined
#endif
#undef MAX  // Undefine the MAX constant
#line 100 "preprocessor_example.c"  // Set the line number to 100

int main() {
    #if defined(PI)
        printf("PI is defined: %.2f\n", PI);  // Output the value of PI
    #else
        printf("PI is not defined\n");
    #endif
    printf("The value of MIN is: %d\n", MIN);
    printf("The current line is 100, as set by #line.\n");
    return 0;
}

// Sort
#include <stdio.h>
int main() {
    int n, i, j, temp;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Enter the elements: ");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("Sorted elements: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

// 3. Sum of Two Numbers and Display Odd and Even Numbers Separately:
#include <stdio.h>
int main() {
    int a, b, sum;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    sum = a + b;
    printf("Sum: %d\n", sum);
    
    printf("Odd numbers between 1 and %d: ", sum);
    for(int i = 1; i <= sum; i++) {
        if(i % 2 != 0)
            printf("%d ", i);
    }
    
    printf("\nEven numbers between 1 and %d: ", sum);
    for(int i = 1; i <= sum; i++) {
        if(i % 2 == 0)
            printf("%d ", i);
    }
    
    return 0;
}

// 4. Dynamic Memory Allocation Using Malloc and Realloc:
#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    // Malloc to allocate memory
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return 1;  
    }
    
    printf("Enter elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Realloc to resize memory
    printf("Enter new number of elements: ");
    scanf("%d", &n);
    
    arr = (int*)realloc(arr, n * sizeof(int));
    if (arr == NULL) {
        printf("Memory reallocation failed!\n");
        return 1; 
    }
    printf("Enter new elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("Elements: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    free(arr);  // Free allocated memory
    return 0;
}

// 6. Append Mode to Open File and Add Records:
#include <stdio.h>
int main() {
    FILE *fp;
    char text[100];
    char ch;

    fp = fopen("records.txt", "a+");  
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("Contents before appending:\n");
    rewind(fp);  
    while((ch = fgetc(fp)) != EOF) {  
        putchar(ch);  
    }

    printf("\nEnter text to append: ");
    scanf("%s", text);  
    fputs(text, fp);  
    fclose(fp);

    fp = fopen("records.txt", "r");  
    if(fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    printf("\nContents after appending:\n");
    while((ch = fgetc(fp)) != EOF) {  
        putchar(ch);  
    }

    fclose(fp);
    printf("\nRecord added successfully!\n");
    return 0;
}

// 7. Check Whether a Given Number is Prime:
#include <stdio.h>
int main() {
    int num, i, flag = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    for(i = 2; i <= num / 2; i++) {
        if(num % i == 0) {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
        printf("%d is a prime number.\n", num);
    else
        printf("%d is not a prime number.\n", num);
    
    return 0;
}

// GCD
#include <stdio.h>
int main() {
    int a, b;

    // Input two numbers
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    // Using Euclid's algorithm to find GCD
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    printf("GCD of the entered numbers is: %d\n", a);
    return 0;
}


// 8. Sum the Square and Cube of Array Elements Using Pointers:
#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    int *ptr = arr;
    
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++)
        scanf("%d", ptr + i);

    int sumSquare = 0, sumCube = 0;
    for(int i = 0; i < n; i++) {
        sumSquare += *(ptr + i) * *(ptr + i);
        sumCube += *(ptr + i) * *(ptr + i) * *(ptr + i);
    }
    
    printf("Sum of squares: %d\n", sumSquare);
    printf("Sum of cubes: %d\n", sumCube);
    
    return 0;
}

// 11. Exchange Two Values Using Call by Reference:
#include <stdio.h>
void exchange(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    exchange(&a, &b);
    printf("After swapping: a = %d, b = %d\n", a, b);
    
    return 0;
}

// Call by value
#include <stdio.h>

// Function to swap values (call by value)
void exchange(int x, int y) {
    int temp = x;
    x = y;
    y = temp;
    
    printf("Inside function: a = %d, b = %d\n", x, y);
}

int main() {
    int a, b;
    
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    printf("Before swapping: a = %d, b = %d\n", a, b);
    
    exchange(a, b);
    printf("After swapping (in main): a = %d, b = %d\n", a, b);
    return 0;
}

// 12. Find the Largest of Three Numbers Using Command Line Argument:
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Please enter exactly 3 numbers\n");
        return 1;
    }
    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);
    
    int largest = (a > b) ? (a > c ? a : c) : (b > c ? b : c);
    printf("Largest number: %d\n", largest);
    
    return 0;
}

// 15. Swapping Without Using Third Variable:
#include <stdio.h>
int main() {
    int a, b;
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    
    a = a + b;
    b = a - b;
    a = a - b;
    
    printf("After swapping: a = %d, b = %d\n", a, b);
    
    return 0;
}

// 16. Memory Allocation to Get 3 Student Marks for N Subjects and Calculate Sum and Average:
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of subjects: ");
    scanf("%d", &n);
    
    float *marks = (float*)malloc(3 * n * sizeof(float));
    float sum = 0;
    for(int i = 0; i < 3; i++) {
        printf("Enter marks for student %d: ", i + 1);
        for(int j = 0; j < n; j++) {
            scanf("%f", &marks[i * n + j]);
            sum += marks[i * n + j];
        }
    }
    printf("Sum of marks: %.2f\n", sum);
    printf("Average marks: %.2f\n", sum / (3 * n));
    
    free(marks);
    return 0;
}

// EACH STUDENT SUM AVG
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of subjects: ");
    scanf("%d", &n);
    
    float *marks = (float*)malloc(3 * n * sizeof(float));

    for(int i = 0; i < 3; i++) {
        float studentSum = 0;  
        printf("Enter marks for student %d: ", i + 1);
        for(int j = 0; j < n; j++) {
            scanf("%f", &marks[i * n + j]);
            studentSum += marks[i * n + j]; 
        }
        printf("Sum of marks for student %d: %.2f\n", i + 1, studentSum);
        printf("Average marks for student %d: %.2f\n", i + 1, studentSum / n);
    }
    free(marks);
    
    return 0;
}


// SUM AVG using pointers
#include <stdio.h>
int main() {
    int n, i, sum = 0;
    float avg;
    
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    int arr[n];
    int *ptr = arr;  // Pointer to array
    
    printf("Enter %d numbers: ", n);
    for (i = 0; i < n; i++) {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    
    avg = (float)sum / n;
    
    printf("Sum = %d\n", sum);
    printf("Average = %.2f\n", avg);
    
    return 0;
}

// Normalisation Matrix
#include <stdio.h>

int main() {
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d %d", &rows, &cols);

    float matrix[rows][cols], min, max;

    printf("Enter matrix elements:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%f", &matrix[i][j]);
        }
    }

    // Find min and max
    min = max = matrix[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) min = matrix[i][j];
            if (matrix[i][j] > max) max = matrix[i][j];
        }
    }

    // Normalize the matrix
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = (matrix[i][j] - min) / (max - min);
        }
    }

    // Print normalized matrix
    printf("\nNormalized Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%.2f ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}

// Max of 6 Number
#include <stdio.h>

int main() {
    int a, b, c, d, e, f, max;
    printf("Enter six numbers: ");
    scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);

    // Finding the greatest number using if-else if conditions
    if (a >= b && a >= c && a >= d && a >= e && a >= f)
        max = a;
    else if (b >= c && b >= d && b >= e && b >= f)
        max = b;
    else if (c >= d && c >= e && c >= f)
        max = c;
    else if (d >= e && d >= f)
        max = d;
    else if (e >= f)
        max = e;
    else
        max = f;

    // Printing the greatest number
    printf("The greatest number is: %d\n", max);

    return 0;
}

// C to F and vice versa
#include <stdio.h>

int main() {
    float fahrenheit, celsius;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - 32) * 5 / 9;
    printf("Temperature in Celsius: %.2f\n", celsius);
    return 0;
}

#include <stdio.h>

int main() {
    float celsius, fahrenheit;
    printf("Enter temperature in Celsius: ");
    scanf("%f", &celsius);
    fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit);
    return 0;
}

// GCD w and w/o recursion
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)  
        return a;            // Base case
    return gcd(b, a % b);    // Recursive step
}

int main() {
    int num1, num2;

    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = gcd(num1, num2);

    printf("GCD of %d and %d is: %d\n", num1, num2, result);

    return 0;
}

#include <stdio.h>

int main() {
    int a, b;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);

    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }

    printf("GCD is: %d\n", a);

    return 0;
}

// Factorial w and w/o recursion 
#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    return n * factorial(n - 1);
}

int main() {
    int num;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0)
        printf("Factorial is not defined for negative numbers.\n");
    else
        printf("Factorial of %d is: %d\n", num, factorial(num));
    return 0;
}
#include <stdio.h>

int main() {
    int num, factorial = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num < 0) {
        printf("Factorial is not defined for negative numbers.\n");
    } 
    else {
        for (int i = 1; i <= num; i++) {
            factorial *= i;
        }
        printf("Factorial of %d is: %d\n", num, factorial);
    }
    return 0;
}


// Prime or Not
#include <stdio.h>

int main() {
    int num, isPrime = 1;

    printf("Enter a number: ");
    scanf("%d", &num);

    if (num <= 1) {
        isPrime = 0;  // 0 and 1 are not prime
    } else {
        for (int i = 2; i * i <= num; i++) {  
            if (num % i == 0) {
                isPrime = 0;  // Not a prime if divisible
                break;
            }
        }
    }

    if (isPrime) {
        printf("%d is a prime number.\n", num);
    } else {
        printf("%d is not a prime number.\n", num);
    }

    return 0;
}

// Array of pointers
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    int *arr[3] = {&a, &b, &c};  // Array of pointers

    // Access values through pointers
    for (int i = 0; i < 3; i++) {
        printf("%d ", *arr[i]);
    }

    return 0;
}

// Pointer to Array
#include <stdio.h>

int main() {
    int arr[5] = {10, 20, 30, 40, 50};
    int *ptr = arr;  // Pointer to the first element of the array

    // Access elements using pointer
    for (int i = 0; i < 5; i++) {
        printf("Element %d: %d\n", i, *(ptr + i));
    }

    return 0;
}

// Fibo w and w/o recursion
#include <stdio.h>

int fibonacci(int n) {
    if (n <= 1) 
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Fibonacci sequence: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", fibonacci(i));
    }
    return 0;
}


#include <stdio.h>
int main() {
    int n, first = 0, second = 1, next;

    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("%d %d ", first, second); // Print the first two terms

    for (int i = 2; i < n; i++) {
        next = first + second;
        printf("%d ", next);
        first = second;
        second = next;
    }

    return 0;
}

// Count vowels and consonants 
#include <stdio.h>

int main() {
    char str[100];
    int vowels = 0, consonants = 0;

    printf("Enter a string: ");
    scanf(" %[^\n]", str); // Reads string with spaces

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||  
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }

    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}

// enum default and custom
#include <stdio.h>
enum Day { SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY };
int main() {
    enum Day today = WEDNESDAY;
    printf("Today is day number: %d\n", today);
    if (today == WEDNESDAY) {
        printf("Mid-week grind!\n");
    }

    return 0;
}

#include <stdio.h>
enum Level {
    LOW = 1,  
    MEDIUM = 5,  
    HIGH = 10
};

int main() {
    enum Level danger = HIGH;

    printf("Danger level: %d\n", danger);

    if (danger == HIGH) {
        printf("Warning! High danger level.\n");
    }

    return 0;
}

// 2022
#include <stdio.h>
struct stud {
    char name[50];
    int marks[3];
    int total;
};
int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);
    struct stud s[n];
    for (int i = 0; i < n; i++) {
        s[i].total = 0;
        printf("\nEnter details for Student %d:\n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].name);
        
        for (int j = 0; j < 3; j++) {
            printf("Marks in subject %d: ", j + 1);
            scanf("%d", &s[i].marks[j]);
            s[i].total += s[i].marks[j];
        }
    }
    // Displaying marks statement
    printf("\nStudent Marks Statement:\n");
    printf("-------------------------------------\n");
    printf("Name\tSub 1\tSub 2\tSub 3\tTotal\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < n; i++)
        printf("%s\t%d\t\t%d\t\t%d\t\t%d\n", s[i].name, s[i].marks[0], s[i].marks[1], s[i].marks[2], s[i].total);
    return 0;
}

#include <stdio.h>

int main() {
    char str[100];
    FILE *fp;
    int count = 0;

    printf("Enter a string: ");
    gets(str);

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' ||
            str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U') {
            count++;
        }
    }

    fp = fopen("count.txt", "w");
    fprintf(fp, "Number of vowels: %d\n", count);
    fclose(fp);

    printf("Vowel count written to 'count.txt'.\n");

    return 0;
}

#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i;

    printf("Enter a string: ");
    gets(str1);
    // Copying string without strcpy
    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }
    str2[i] = '\0'; // Null-terminate the copied string
    printf("Copied string: %s\n", str2);
    return 0;
}

#include <stdio.h>
int main() {
    char S1[50], S2[50], S3[100];
    int i = 0, j = 0;

    // Reading strings
    printf("Enter first string (S1): ");
    gets(S1);
    printf("Enter second string (S2): ");
    gets(S2);

    // Copy S1 to S3
    while (S1[i] != '\0') {
        S3[i] = S1[i];
        i++;
    }
    // Add a space between the strings
    S3[i] = ' ';
    i++;
    // Copy S2 to S3
    while (S2[j] != '\0') {
        S3[i] = S2[j];
        i++;
        j++;
    }
    S3[i] = '\0';
    printf("Concatenated string (S3): %s\n", S3);
    return 0;
}
#include <stdio.h>
#include <string.h>

struct stud {
    int rollNo;
    char name[50];
    float marks;
    char grade;
};

int main() {
    int n, i;
    char searchName[50];
    printf("Enter number of students: ");
    scanf("%d", &n);
    struct stud s[n];
    for (i = 0; i < n; i++) {
        printf("Enter roll no, name, marks, and grade for student %d:\n", i + 1);
        scanf("%d", &s[i].rollNo);
        scanf(" %[^\n]", s[i].name);  // Read full name
        scanf("%f %c", &s[i].marks, &s[i].grade);
    }

    printf("\nEnter student name to search marks: ");
    scanf(" %[^\n]", searchName);

    for (i = 0; i < n; i++) {
        if (strcmp(s[i].name, searchName) == 0) {
            printf("Marks of %s: %.2f\n", s[i].name, s[i].marks);
            return 0;
        }
    }
    printf("Student not found!\n");
    return 0;
}
#include <stdio.h>

struct Date {
    int day;
    int month;
    int year;
};

struct Employee {
    int empCode;
    char name[50];
    float salary;
    int deptNo;
    struct Date doj;
};

int main() {
    int n, i; 
    printf("Enter the number of employees: ");
    scanf("%d", &n);
    struct Employee emp[n];
    // Storing employee details
    for (i = 0; i < n; i++) {
        printf("\nEnter details for employee %d (Code Name Salary DeptNo DD MM YYYY):\n", i + 1);
        scanf("%d %s %f %d %d %d %d", 
              &emp[i].empCode, emp[i].name, &emp[i].salary, &emp[i].deptNo, 
              &emp[i].doj.day, &emp[i].doj.month, &emp[i].doj.year);
    }
    // Displaying employee details
    printf("\nEmployee Details:\n");
    for (i = 0; i < n; i++) {
        printf("\nEmployee %d:\n", i + 1);
        printf("Code: %d\n", emp[i].empCode);
        printf("Name: %s\n", emp[i].name);
        printf("Salary: %.2f\n", emp[i].salary);
        printf("Department No: %d\n", emp[i].deptNo);
        printf("Date of Join: %02d-%02d-%04d\n", emp[i].doj.day, emp[i].doj.month, emp[i].doj.year);
    }

    return 0;
}

#include <stdio.h>

int main() {
    FILE *fp;
    char ch;
    long length;
    // Open the file in read mode
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    // Move the file pointer to the end of the file
    fseek(fp, 0, SEEK_END);
    length = ftell(fp);
    // Read the file in reverse order
    printf("File contents in reverse order:\n");
    for (long i = length - 1; i >= 0; i--) {
        fseek(fp, i, SEEK_SET);
        ch = fgetc(fp);
        putchar(ch);
    }
    fclose(fp);
    return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main() {
    int *ptr;
    int n, i;
    // Ask user for number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    // 1. malloc
    ptr = (int *)malloc(n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        return 1;
    }

    printf("Memory successfully allocated using malloc.\n");

    // Take input
    for (i = 0; i < n; i++)
        scanf("%d", &ptr[i]); // (p+i)
    // Print array
    printf("Elements: ");
    for (i = 0; i < n; i++)
        printf("%d ", ptr[i]); // *(p+i)
    printf("\n");

    // 2. realloc
    printf("Enter new size: ");
    scanf("%d", &n);
    ptr = (int *)realloc(ptr, n * sizeof(int));

    if (ptr == NULL) {
        printf("Memory not reallocated.\n");
        return 1;
    }

    printf("Memory successfully reallocated using realloc.\n");

    // Initialize new elements
    for (i = 0; i < n; i++) {
        ptr[i] = i + 1;
    }
    // Print new array
    printf("Updated elements: ");
    for (i = 0; i < n; i++) {
        printf("%d ", ptr[i]);
    }
    printf("\n");
    // 3. free
    free(ptr);
    printf("Memory successfully freed.\n");

    return 0;
}
#include <stdio.h>

int main() {
    char str[100];
    char *ptr;
    int count = 0;
    // Input the string
    printf("Enter a string: ");
    gets(str); // Using gets to take input
    ptr = str; // Pointer points to the string
    // Traverse the string using pointer
    while (*ptr != '\0') {
        // Check for vowels
        if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u' ||
            *ptr == 'A' || *ptr == 'E' || *ptr == 'I' || *ptr == 'O' || *ptr == 'U') {
            count++;
        }
        ptr++; // Move pointer to next character
    }
    // Print the result
    printf("Number of vowels: %d\n", count);
    return 0;
}

#include <stdio.h>
#include <ctype.h>
int main() {
    FILE *inputFile, *outputFile;
    char ch;
    inputFile = fopen("input.txt", "r");
    outputFile = fopen("output.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    while ((ch = fgetc(inputFile)) != EOF) {
        if (islower(ch)) {
            ch = toupper(ch);  // Convert lowercase to uppercase
        }
        fputc(ch, outputFile);  // Write to output file
    }
    printf("File copied with lowercase letters converted to uppercase.\n");
    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

#include <stdio.h>
struct Status {
    unsigned int isOnline : 1;   // 1 bit for online status (0 or 1)
    unsigned int isAdmin  : 1;   // 1 bit for admin status (0 or 1)
    unsigned int errorCode : 3;  // 3 bits for error codes (0-7)
};

int main() {
    struct Status user;

    user.isOnline = 1;
    user.isAdmin = 0;
    user.errorCode = 5;

    printf("User Status:\n");
    printf("Online: %u\n", user.isOnline);
    printf("Admin: %u\n", user.isAdmin);
    printf("Error Code: %u\n", user.errorCode);

    return 0;
}

// Storage Classes
#include <stdio.h>
int main() {
    auto int x = 10;  // Local variable with automatic storage
    printf("Auto: %d\n", x);
    return 0;
}
#include <stdio.h>
int main() {
    register int count = 5;  // Fast access, no address (&count)  
    printf("Register: %d\n", count);
    return 0;
}
#include <stdio.h>
void countCalls() {
    static int count = 0;  // Persists across function calls
    count++;
    printf("Static (Local): %d\n", count);
}
int main() {
    countCalls();
    countCalls();
    return 0;
}
#include <stdio.h>
static int globalVar = 100;  // Accessible only in this file
int main() {
    printf("Static (Global): %d\n", globalVar);
    return 0;
}
#include <stdio.h>
int globalVar = 50;  // Global variable definition
// 2nd file
#include <stdio.h>
extern int globalVar;  // Access globalVar from file1
int main() {
    printf("Extern: %d\n", globalVar);
    return 0;
}

#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "Hello, World!";
    char *pos;

    // Using strchr to find the first occurrence of a character
    pos = strchr(str, 'W');
    if (pos != NULL)
        printf("Character 'W' found at position: %ld\n", pos - str + 1);
    else
        printf("Character 'W' not found.\n");
    // Using strstr to find a substring
    pos = strstr(str, "World");
    if (pos != NULL)
        printf("Substring 'World' found at position: %ld\n", pos - str + 1);
    else
        printf("Substring 'World' not found.\n");
    return 0;
}


// End







    
