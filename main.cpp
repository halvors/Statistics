#include <stdio.h>

using namespace std;

void printTable(double **table, int rows, int columns) {
    printf("Frekvens:\t");
    printf("Relativ:\t");
    printf("Kumulativ:\t");

    for (int row = 0; row < rows; row++) {

            printf("%f\t", table[column][row]);
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
    double **table = new double*[columns];

    for (int i = 0; i < columns; i++) {
        table[i] = new double[rows];
    }

    // Loop through thew array and gather values for each index.
    for (int i = 0; i < rows; i++) {
        int value;

        printf("Enter number value for index %i: ", i + 1);
        scanf("%o", &value);

        table[0][i] = value;
    }

    // Calculate the sum of all values.
    double sum = 0;

    for (int i = 0; i < rows; i++) {
        sum += table[0][i];

        printf("Adding value: %f\n", table[0][i]);
    }

    printf("Sum is: %f\n", sum);

    // Calculate the "relativ frekvens" values.
    for (int i = 0; i < rows; i++) {
        table[1][i] = table[0][i] / sum;
    }

    // Calculate the "kumulativ frekvens" values.
    for (int i = 0; i < rows; i++) {
        table[2][i] = table[0][i] / sum;
    }

    printTable(table, rows, columns);

    return 0;
}
