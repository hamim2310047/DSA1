#include<iostream>
using namespace std;

int front1 = -1, rear1 = -1, front2 = -1, rear2 = -1, n=3;
int arr1[10], arr2[10];

void enqueue(int arr[], int &front, int &rear, int item) {
    if (rear >= n - 1) {
        cout << "Overflow" << endl;
        return;
    } else {
        if (front == -1 && rear == -1) {
            front++;
            rear++;
            arr[rear] = item;
        } else {
            rear++;
            arr[rear] = item;
        }
    }
}

int dequeue(int arr[], int &front, int &rear) {
    if (front == -1 && rear == -1 || front > rear) {
        cout << "Underflow" << endl;
    }
    int y = arr[front];
    front++;
    return y;
}

void push(int item) {
    enqueue(arr1, front1, rear1, item);
}

int pop() {
    if (front1 == -1 && rear1 == -1) {
        cout << "Empty" << endl;
        return -1;
    }
    while (front1 != rear1) {
        int x = dequeue(arr1, front1, rear1);
        enqueue(arr2, front2, rear2, x);
    }
    int popped_element = dequeue(arr1, front1, rear1);
    swap(arr1, arr2);
    swap(front1, front2);
    swap(rear1, rear2);
    front2 = -1;
    rear2 = -1;
    return popped_element;
}
void display() {
    for (int i = front1; i <= rear1; i++) {
        cout << arr1[i] << " ";
    }
    for (int i = rear2; i >= front2&&front2!=-1; i--) {
        cout << arr2[i] << " ";
    }
    cout << endl;
}

int main() {
    push(10);
    display();
    push(15);
    display();
    push(20);
    display();
    push(30);
    cout << "deleted Item: " << pop() << endl;
    display();
    push(25);
    display();
    cout << "deleted Item: " << pop() << endl;
    cout << "deleted Item: " << pop() << endl;
    cout << "deleted Item: " << pop() << endl;
    pop();
    return 0;
}
