#include <iostream>
using namespace std;

class Process {
public:
    int id;
    int burst;
    Process* next;
    Process* prev;

    Process(int pid, int b) : id(pid), burst(b), next(this), prev(this) {}
};

void insertProcess(Process*& head, Process*& tail, Process* newProcess) {
    if (!head) {
        head = tail = newProcess;
    } else {
        tail->next = newProcess;
        newProcess->prev = tail;
        newProcess->next = head;
        head->prev = newProcess;
        tail = newProcess;
    }
}

void roundRobin(Process*& head, Process*& tail, int timeQuantum) {
    if (!head) return;
    Process* current = head;
    while (head) {
        current->burst -= timeQuantum;
        cout << "P" << current->id << " ";
        if (current->burst <= 0) {
            if (current == current->next) {
                delete current;
                head = tail = nullptr;
                break;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            if (current == head) head = current->next;
            if (current == tail) tail = current->prev;
            Process* temp = current;
            current = current->next;
            delete temp;
        } else {
            current = current->next;
        }
    }
}

int main() {
    int n, tq;
    cin >> n;
    Process* head = nullptr;
    Process* tail = nullptr;
    for (int i = 0; i < n; i++) {
        int burst;
        cin >> burst;
        Process* p = new Process(i + 1, burst);
        insertProcess(head, tail, p);
    }
    cin >> tq;
    roundRobin(head, tail, tq);
    cout << endl;
    return 0;
}
