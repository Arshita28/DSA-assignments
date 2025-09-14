#include <iostream>
using namespace std;

int main() {
    int A[] = {1, 3, 0, 2, 5};
    int n = sizeof(A) / sizeof(A[0]);

    int stack[100];  
    int top = -1;

    cout << "Nearest smaller elements: ";

    for (int i = 0; i < n; i++) {
        while (top >= 0 && stack[top] >= A[i]) {
            top--;
        }

        if (top == -1)
            cout << -1 << " ";
        else
            cout << stack[top] << " ";

        stack[++top] = A[i];
    }

    cout << endl;
    return 0;
}

