#include <iostream>
using namespace std;

/*******************************************************************************
 * Global variable
*******************************************************************************/

const int COL_SIZE = 5;

/*******************************************************************************
 * Function prototypes
*******************************************************************************/

int total(const int[][COL_SIZE], const int);
double average(const int[][COL_SIZE], const int);
void userInit(int[][COL_SIZE], const int);

/*******************************************************************************
 * Description:
 * Starting point of the program. Declares and initializes a 2D array. Displays
 * the total sum and the average value. Repeats but with user values.
 *
 * Input:
 * N/A
 *
 * Output:
 * An integer that signals the exit code to the operating system (OS)
*******************************************************************************/

int main() {
    // declare and initialize a 2D array
    const int ROW_SIZE = 4;
    int table[ROW_SIZE][COL_SIZE] = {
        {117, -76, 128, -68,  85},
        {105,  34, -79,  54, 105},
        {-85, 151, 133, -50, 173},
        {-38, -20, 185, 173, -49},
    };

    // display the calculations
    cout << "Total: " << total(table, ROW_SIZE) << endl;
    cout << "Average: " << average(table, ROW_SIZE) << endl;

    // now let the user try
    cout << "\nNow it's your turn!\n";

    // create 2D array for the user
    const int USER_ROW_SIZE = 2;
    int userTable[USER_ROW_SIZE][COL_SIZE];

    // call the functions for the user's 2D array
    userInit(userTable, USER_ROW_SIZE);
    cout << "Your Total: " << total(userTable, USER_ROW_SIZE) << endl;
    cout << "Your Average: " << average(userTable, USER_ROW_SIZE) << endl;

    // terminate
    return 0;
}

/*******************************************************************************
 * Description:
 * Calculates the total sum of the values inside the given 2D array.
 *
 * Input:
 * ARR      - a constant 2D array of integers
 * ROW_SIZE - a constant integer representing the number of rows in `ARR`
 *
 * Output:
 * The total sum
*******************************************************************************/

int total(const int ARR[][COL_SIZE], const int ROW_SIZE) {
    int sum = 0;

    for (int row = 0; row < ROW_SIZE; row++) {
        for (int col = 0; col < COL_SIZE; col++) {
            sum += ARR[row][col];
        }
    }

    return sum;
}

/*******************************************************************************
 * Description:
 * Calculates the average value inside the given 2D array.
 *
 * Input:
 * ARR      - a constant 2D array of integers
 * ROW_SIZE - a constant integer representing the number of rows in `ARR`
 *
 * Output:
 * The average value
*******************************************************************************/

double average(const int ARR[][COL_SIZE], const int ROW_SIZE) {
    int sum = total(ARR, ROW_SIZE);
    int numElems = ROW_SIZE * COL_SIZE;
    return static_cast<double>(sum) / static_cast<double>(numElems);
}

/*******************************************************************************
 * Description:
 * Allows the user to initialize the given 2D array.
 *
 * Input:
 * twoDeeArr - a 2D array of integers
 * ROW_SIZE  - a constant integer representing the number of rows in `twoDeeArr`
 *
 * Output:
 * N/A
*******************************************************************************/

void userInit(int twoDeeArr[][COL_SIZE], const int ROW_SIZE) {
    for (int i = 0; i < ROW_SIZE; i++) {
        cout << "Enter " << COL_SIZE
             << " numbers in a row ("
             << i + 1 << "/" << ROW_SIZE << "): ";

        for (int j = 0; j < COL_SIZE; j++) {
            cin >> twoDeeArr[i][j];
        }
    }
}
