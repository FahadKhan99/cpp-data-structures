#include "deque.h"

int main() {
    Deque<int> dq;

    dq.insertFront(10);
    dq.insertRear(20);
    dq.insertFront(5);
    dq.insertRear(25);

    dq.displayForward();   // 5 10 20 25
    dq.displayBackward();  // 25 20 10 5

    std::cout << "Front: " << dq.getFront() << std::endl;  // 5
    std::cout << "Rear: " << dq.getRear() << std::endl;    // 25

    dq.deleteFront();
    dq.deleteRear();

    dq.displayForward();   // 10 20

    return 0;
}
