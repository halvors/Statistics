#include <stdio.h>

using namespace std;

void printTable(double **table, int rows, int columns) {
    printf("Antall (frekvens):\t");
    printf("Kumulativ frekvens:\t");
    printf("Kumulativ relativ frekvens:\t");
    printf("\n");

    for (int row = 0; row < rows; row++) {
        for (int column = 0; column < columns; column++) {
            printf("%f\t\t", table[row][column]);
        }

        printf("\n");
    }
}

int main() {
    // Send initial information about this program.
    printf("Welcome to Statistics 0.1!\n");
    printf("We will help you calculate the table for this math task.\n");
    printf("All you have to do is to enter the data below.\n\n");

    int length;

    // Get input from the user.
    printf("Enter the amount of numbers you want to enter: ");
    scanf("%o", &length);

    // Define the bounds for the new array.
    int rows = length;
    int columns = 3;

    // Create the multidimensional table.
    double **table = new double*[rows];

    for (int i = 0; i < rows; i++) {
        table[i] = new double[columns];
    }

    // Loop through thew array and gather values for each index.
    for (int i = 0; i < rows; i++) {
        int value;

        printf("Enter number value for index %i: ", i + 1);
        scanf("%o", &value);

        table[i][0] = value;
    }

    // Calculate the sum of all values at column 0.
    double sum = 0;

    for (int i = 0; i < rows; i++) {
        sum += table[i][0];
    }

    // Calculate the "kumulativ frekvens" values for column 1.
    double lastIndex = 0;

    for (int i = 0; i < rows; i++) {
        lastIndex += table[i][0];
        table[i][1] = lastIndex;
    }

    // Calculate the "kumulativ relativ frekvens" values for column 2.
    for (int i = 0; i < rows; i++) {
        table[i][2] = (table[i][1] / lastIndex) * 100;
    }

    printTable(table, rows, columns);

    printf("Sum is: %f\n", sum);

    delete[] table;

    return 0;
}
