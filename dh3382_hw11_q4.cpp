#include <iostream>
using namespace std;

const int ARR_SIZE = 6;

void printArr(int arr[], int arrSize);
int solveJumpIt(int board[], int columnsLeft);
int main() {
    int jumpArr [ARR_SIZE] = {0, 3, 2, 6, 1, 10};

    printArr(jumpArr, ARR_SIZE);
    cout<<solveJumpIt(jumpArr, ARR_SIZE)<<endl;

    return 0;
}
void printArr(int arr[], int arrSize){
    for(int i = 0; i < arrSize; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
int solveJumpIt(int board[], int columnsLeft){
    if(columnsLeft <= 3)
            return board[columnsLeft - 1];
    else if(columnsLeft == 2)
        return(board[0]);
    else{
        if(solveJumpIt(board, columnsLeft - 2) >= solveJumpIt(board, columnsLeft - 1))
            return board[columnsLeft - 1] + solveJumpIt(board, columnsLeft - 1);
        else
            return board[columnsLeft - 1] + solveJumpIt(board, columnsLeft - 2);
        }
}