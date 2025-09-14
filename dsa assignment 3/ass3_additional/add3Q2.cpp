#include <iostream>
using namespace std;

class SpecialStack {
    int arr[100];   
    int topIndex;
    int minEle;     
public:
    SpecialStack() { topIndex = -1; }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(int x) {
        if (isEmpty()) {
            topIndex++;
            arr[topIndex] = x;
            minEle = x;
        } 
        else if (x >= minEle) {
            topIndex++;
            arr[topIndex] = x;
        } 
        else {
          
            topIndex++;
            arr[topIndex] = 2 * x - minEle;
            minEle = x;
        }
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return;
        }

        int t = arr[topIndex];
        topIndex--;

        if (t < minEle) {
           
            minEle = 2 * minEle - t;
        }
    }

    int top() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        int t = arr[topIndex];
        if (t >= minEle) return t;
        else return minEle; 
    }

    int getMin() {
        if (isEmpty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return minEle;
    }
};

int main() {
    SpecialStack st;
    st.push(5);
    st.push(3);
    st.push(7);
    st.push(2);

    cout << "Current Min: " << st.getMin() << endl; 
    cout << "Top: " << st.top() << endl;            

    st.pop();
    cout << "After popping, Min: " << st.getMin() << endl; 
    cout << "Top: " << st.top() << endl;                   

    return 0;
}

