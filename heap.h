//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        data[size] = idx; //Insert at the end
        upheap(size, weightArr); //Restore the minheap
        size++; //Increase size of the heap
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        return -1; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        while (pos > 0) {
            int parent = (pos - 1) / 2; //Calculates the index of the parent node of pos
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }else{
                break;
            }
        }
    }

    void downheap(int pos, int weightArr[]) {
        while (true) {
            int left  = 2 * pos + 1; //Calculates the index of the left child of the parent
            int right = 2 * pos + 2; //Calculates the index of the right child of the parent

            if (left >= size) break; //Check if leaf

            int smallestChild = left;
            if (right < size && weightArr[data[right]] < weightArr[data[left]]) { //Determine the smaller child
                smallestChild = right;
            }

            if (weightArr[data[pos]] <= weightArr[data[smallestChild]]) { //If parent is <= smallest child the heap property holds
                break;
            }

            swap(data[pos], data[smallestChild]); //Swap with smallest child and continue downward
            pos = smallestChild;
        }
    }
};

#endif