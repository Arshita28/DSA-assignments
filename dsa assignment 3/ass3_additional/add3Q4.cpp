#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter number of days: ";
    cin >> n;

    int temperatures[1000]; 
    int answer[1000];
    int stack[1000];        
    int top = -1;           
    cout << "Enter temperatures: ";
    for (int i = 0; i < n; i++) {
        cin >> temperatures[i];
        answer[i] = 0;  
    }

    for (int i = 0; i < n; i++) {
        while (top >= 0 && temperatures[i] > temperatures[stack[top]]) {
            int prev = stack[top--]; 
            answer[prev] = i - prev;
        }
        stack[++top] = i; 
    }

    cout << "Answer: ";
    for (int i = 0; i < n; i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}

