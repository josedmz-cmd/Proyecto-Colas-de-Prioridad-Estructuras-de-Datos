#pragma once

#include <iostream>
#include <stdexcept>
#include "Priority_Queue.h"
#include "Min_Heap.h"
#include "Pair.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class Heap_Priority_Queue : public Priority_Queue<E> {
private:
	Min_Heap<Pair<int, E>>* pairs;

public:
	Heap_Priority_Queue(int max = 1024) {
		pairs = new Min_Heap<Pair<int, E>>(max);
	}

	~Heap_Priority_Queue() {
		delete pairs;
	}

	void insert(E element, int priority) {
		Pair<int, E> p(priority, element);
		pairs->insert(p);
	}

	E min() {
		Pair<int, E> p = pairs->first();
		return p.value;
	}

	E removeMin() {
		Pair<int, E> p = pairs->removeFirts();
		return p.value;
	}

	void clear() {
		pairs->clear();
	}

	int getSize() {
		return pairs->getSize();
	}

	bool is_empty() {
		return pairs->isEmpty();
	}

	void print() {
		pairs->print();
	}
};
