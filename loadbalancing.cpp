#include <iostream>
using namespace std;

int main(){
    int servers;
    cout<<"B24CE1134\n";
    cout << "Enter the number of servers: ";
    cin >> servers;
    if(servers <= 0){
        cout << "Invalid number of servers!" << endl;
        return 0;
    }

    int *serverLoad = new int[servers]; // To store request count for each server
    for(int i = 0; i < servers; i++) serverLoad[i] = 0;

    int requestID;
    char choice;
    cout << "\n--- Load Balancer Started ---\n";

    do{
        cout << "Enter request ID (integer): ";
        cin >> requestID;
        int hash_val = requestID % servers;
        serverLoad[hash_val]++; // Increase load on selected server
        cout << "Request " << requestID << " is assigned to Server " << hash_val << endl;
        cout << "Do you want to add another request? (y/n): ";
        cin >> choice;

    }while(choice == 'y' || choice == 'Y');

    cout << "\n--- Load Balancer Stopped ---\n";

    // Summary of loads
    cout << "\nServer Load Summary:\n";
    for(int i = 0; i < servers; i++){
        cout << "Server " << i << ": " << serverLoad[i] << " requests\n";
    }

    delete[] serverLoad;
    return 0;
}
