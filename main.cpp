#include <HW_3.h>


int main() {
    Queue<int> test_queue;

    test_queue.push(10);
    test_queue.push(20);
    test_queue.push(30);
    test_queue.push(40);
    test_queue.push(50);
    test_queue.push(60);
    test_queue.push(70);
    test_queue.push(80);
    test_queue.push(90);
    test_queue.push(100);

    cout << "Test queue size = " << test_queue.size() << endl;

    for (int i = test_queue.size(); i > 0; i--) {
        cout << "Item: " << 11 - i << " = " << test_queue.front() << endl;
        test_queue.pop_front();
    }

    Queue<int> test_queue2;
    test_queue2.push(1);
    test_queue2.push(2);
    test_queue2.push(3);
    test_queue2.push(4);

    cout << endl;

    cout << "///// Creating New Queue /////" << endl;

    Queue<int> test_queue3;
    for (int j = test_queue2.size(); j > 0; j--) {
        cout << "Item: " << 5 - j << " = " << test_queue2.front() << endl;
        test_queue3.push(test_queue2.front());
        test_queue2.pop_front();
    }

    cout << "Moving First Item to Rear" << endl;
    test_queue3.move_to_rear();

    for (int k = test_queue3.size(); k > 0; k--) {
        cout << "Item: " << 5 - k << " = " << test_queue3.front() << endl;
        test_queue3.pop_front();
    }

    cout << endl;

    cout << "///// Creating New Vector /////" << endl;

    const vector<int> test_vector = {1, 2, 5, 4, 5, 6, 7, 8, 9, 10, 11, 5, 12};

    for (int i = 0; i < test_vector.size(); i++) {
        cout << "Index " << i << " = " << test_vector[i] << endl;
    }

    cout << "Last Occurrence of 5: Index " << last_occurrence(test_vector, 5) << endl;

    cout << endl;

    cout << "///// Creating New Queue /////" << endl;

    Queue<int> test_queue4, test_queue5;

    test_queue4.push(33);
    test_queue4.push(11);
    test_queue4.push(88);
    test_queue4.push(99);
    test_queue4.push(33);
    test_queue4.push(44);
    test_queue4.push(22);

    for (int j = test_queue4.size(); j > 0; j--) {
        cout << "Item: " << 8 - j << " = " << test_queue4.front() << endl;
        test_queue5.push(test_queue4.front());
        test_queue4.pop_front();
    }

    cout << "Sorting Queue items " << endl;
    Q_insertion_sort(test_queue5);

    cout << "Sorted Queue size = " << test_queue5.size() << endl;

    int size = test_queue5.size();  // Store the size once

    for (int k = 0; k < size; k++) {
        cout << "Index " << k << " = " << test_queue5.front() << endl;
        test_queue5.pop_front();
    }

    return 0;
}
