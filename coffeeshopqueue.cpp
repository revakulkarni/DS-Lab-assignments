#include<iostream>
#define SIZE 10
using namespace std;

class coffeeshop {
public:
    int token_queue[SIZE];
    int rear, front;

    coffeeshop() {
        rear = -1;
        front = -1;
    }

    int isfull() {
        if (rear == SIZE - 1) {
            return 1;
        } else {
            return 0;
        }
    }

    int isempty() {
        if (front == -1 || front > rear) {
            return 1;
        } else {
            return 0;
        }
    }

    void Enqueue(int t) {
        if (isfull()) {
            cout << "Queue is full." << endl;
        } else {
            if (front == -1) {   // first insertion
                front = 0;
            }
            rear = rear + 1;
            token_queue[rear] = t;
        }
    }

    int Dequeue() {
        if (isempty()) {
            cout << "Queue is Empty" << endl;
            return -1;   // unchanged
        } else {
            int t = token_queue[front];
            front = front + 1;
            return t;   // unchanged
        }
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        cout << "Current queue: ";
        for (int i = front; i <= rear; i++) {
            cout << token_queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    coffeeshop shop;
    int token, choice;
    char c;

    do {
        cout << "-----WELCOME to COFFEE SHOP----\n1. Get token\n2. Process token\n3. Display queue\n4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter token number for the new customer: ";
                cin >> token;
                shop.Enqueue(token);
                break;
            }
            case 2: {
                token = shop.Dequeue();
                if (token != -1) {
                    cout << "Customer " << token << " is being served." << endl;
                }
                break;
            }
            case 3: {
                shop.display();
                break;
            }
            case 4: {
                cout << "Exiting the program." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

        cout << "Do you want to continue (Y/N)? ";
        cin >> c;
    } while (c == 'Y' || c == 'y');

    cout << "Program stopped." << endl;
    return 0;
}
