#include <iostream>
#include <string>
using namespace std;

#define LIMIT 50

struct Person {
    int ticketNo;
    string fullName;
};

class BankQueue {
    private:
        Person data[LIMIT];
        int head;
        int tail;
        int counter;
    public:
        BankQueue() {
            head = 0;
            tail = -1;
            counter = 100;
        }

        bool empty() {
            return tail < head;
        }

        bool full() {
            return tail == LIMIT - 1;
        }

        void joinQueue(string name) {
            if(full()) {
                cout << "Queue is full! Please wait.\n";
                return;
            }
            counter++;
            tail++;
            data[tail].ticketNo = counter;
            data[tail].fullName = name;
            cout << "[JOINED] " << name << " | Ticket: " << counter << " | Behind " << (tail-head) << " people\n";
        }

        void serve() {
            if(empty()) {
                cout << "No customer waiting.\n";
                head = 0;
                tail = -1;
                return;
            }
            cout << "[SERVING] Now serving: " << data[head].fullName << " (Ticket #" << data[head].ticketNo << ")\n";
            head++;
            if(head > tail) {
                head = 0;
                tail = -1;
                cout << "Queue is now empty.\n";
            }
        }

        void showFront() {
            if(empty()) cout << "Queue empty\n";
            else cout << "Next in line: " << data[head].fullName << " Ticket #" << data[head].ticketNo << endl;
        }

        void showAll() {
            if(empty()) {
                cout << ">>> No customers in queue <<<\n";
                return;
            }
            cout << "\n========== QUEUE LINE ==========\n";
            cout << "FRONT ---> ";
            for(int i = head; i <= tail; i++) {
                cout << "[" << data[i].fullName << ":" << data[i].ticketNo << "] ";
                if(i < tail) cout << " -> ";
            }
            cout << " ---> REAR\n";
            cout << "Total waiting: " << (tail-head+1) << endl;
            cout << "================================\n";
        }
};

int main() {
    BankQueue line;
    int opt;
    string cname;
    cout << "========================================\n";
    cout << " BANK CUSTOMER QUEUE - FIFO SYSTEM\n";
    cout << " Real application of Queue Data Structure\n";
    cout << "========================================\n";
    while(true) {
        cout << "\n1.Join Queue (Enqueue)\n2.Serve Customer (Dequeue)\n3.Show Queue\n4.Who is Next?\n0.Exit\n";
        cout << "Select: ";
        cin >> opt;
        if(opt==0) break;
        if(opt==1) { cout << "Enter Name: "; cin >> cname; line.joinQueue(cname); }
        else if(opt==2) line.serve();
        else if(opt==3) line.showAll();
        else if(opt==4) line.showFront();
    }
    return 0;
}