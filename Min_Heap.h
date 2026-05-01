#pragma once
#include <stdexcept>
#include <iostream>

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class Min_Heap {
private:
	E* elements;
	int max;
	int size;

	int leftChild(int pos) {
		return 2 * pos + 1;
	}

	int rightChild(int pos) {
		return 2 * pos + 2;
	}

	int parent(int pos) {
		return (pos - 1) / 2;
	}

	void swap(int pos1, int pos2) {
		E temp = elements[pos1];
		elements[pos1] = elements[pos2];
		elements[pos2] = temp;
	}

	void cascadeUp(int pos) {
		while (pos > 0 and elements[pos] < elements[parent(pos)]) {
			swap(pos, parent(pos));
			pos = parent(pos);
		}
	}

	bool isLeaf(int pos) {
		return leftChild(pos) >= size;
	}

	int minChild(int pos) {
		if (rightChild(pos) < size and elements[rightChild(pos)] < elements[leftChild(pos)])
			return rightChild(pos);
		return leftChild(pos);
	}

	void cascadeDown(int pos) {
		while (!isLeaf(pos) and elements[minChild(pos)] < elements[pos]) {
			int newPos = minChild(pos);
			swap(pos, newPos);
			pos = newPos;
		}
	}

public:
	Min_Heap(int max = 1024) { //DEFAULT_MAX
		elements = new E[max];
		this->max = max;
		size = 0;
	}

	~Min_Heap() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max)
			throw runtime_error("Heap is full.");
		elements[size] = element;
		cascadeUp(size);
		size++;
	}

	E first() {
		if (size == 0)
			throw runtime_error("Heap is empty.");
		return elements[0];
	}

	E removeFirts() {
		return remove(0);
	}

	E remove(int pos) {
		if (size == 0)
			throw runtime_error("Heap is empty.");
		if (pos < 0 or pos >= size)
			throw runtime_error("Invalid index.");
		swap(pos, size - 1);
		size--;
		cascadeDown(pos);
		return elements[size];
	}

	int getSize() {
		return size;
	}

	bool isEmpty() {
		return size == 0;
	}

	void clear() {
		size == 0;
	}

	void print() {
		cout << "[";
		for (int i = 0; i < size; i++) {
			cout << elements[i];
			if (i != size - 1)
				cout << ",";
		}
		cout << "]" << endl;
	}
};
