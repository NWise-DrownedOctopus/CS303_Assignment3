//
// Created by nicho on 4/8/2025.
//

#include "HW_3.h"


void Q_insertion_sort(Queue<int>& q) {
    // Step 1: Copy queue to vector
    std::vector<int> temp;
    while (!q.empty()) {
        temp.push_back(q.front());
        q.pop_front();
    }

    // Step 2: Perform insertion sort on vector
    int i, j, key;
    bool insertionNeeded = false;
    for (j = 1; j < temp.size(); j++) {
        key = temp[j];
        insertionNeeded = false;
        for (i = j - 1; i >= 0; i--) {
            if (key < temp[i]) {
                temp[i + 1] = temp[i]; // shift right
                insertionNeeded = true;
            } else {
                break;
            }
        }
        if (insertionNeeded)
            temp[i + 1] = key;
    }

    // Step 3: Reinsert sorted values back into queue
    for (int i = temp.size() - 1; i >= 0; i--) {
        q.push(temp[i]);
    }
}
