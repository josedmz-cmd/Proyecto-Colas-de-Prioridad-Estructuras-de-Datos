#pragma once

#define DEFAULT_MAX 1024

#include <iostream>
#include <stdexcept>
#include "List.h"

using std::runtime_error;
using std::cout;
using std::endl;

template <typename E>
class ArrayList : public List<E> {
private:
	E* elements;
	int max;
	int size;
	int pos;

public:
	ArrayList(int max = DEFAULT_MAX) {
		elements = new E[max];
		this->max = max;
		size = pos = 0;
	}

	~ArrayList() {
		delete[] elements;
	}

	void insert(E element) {
		if (size == max)
			throw runtime_error("List is full");
		for (int i = size; i > pos; i--)
			elements[i] = elements[i - 1];
		elements[pos] = element;
		size++;
	}

	void append(E element) {
		if (size == max)
			throw runtime_error("List is full");
		elements[size] = element;
		size++;
	}

	void set_element(E element) {
		if (pos == size)
			throw runtime_error("No current element");
		elements[pos] = element;
	}

	E get_Element() {
		if (pos == size)
			throw runtime_error("No current element");
		return elements[pos];
	}

	E remove() {
		if (size == 0)
			throw runtime_error("List is empty");
		if (pos == size)
			throw runtime_error("No current element");
		E element = elements[pos];
		for (int i = pos; i < size; i++)
			elements[i] = elements[i + 1];
		size--;
		return element;
	}

	void clear() {
		pos = size = 0;
	}

	void go_to_start() {
		pos = 0;
	}

	void go_to_end() {
		pos = size;
	}

	void go_to_pos(int pos) {
		if (pos < 0 || pos > size)
			throw runtime_error("Index out of bounds");
		this->pos = pos;
	}

	void next() {
		if (pos < size)
			pos++;
	}

	void previous() {
		if (pos > 0)
			pos--;
	}

	bool at_start() {
		return pos == 0;
	}

	bool at_end() {
		return pos == size;
	}

	int get_pos() {
		return pos;
	}

	int get_size() {
		return size;
	}

	void print() {
		cout << "(";
		for (int i = 0; i < size; i++) {
			cout << elements[i];
			if (i == pos)
				cout << "*";
			if (i < size - 1)
				cout << ", ";
		}
		cout << ")" << endl;
	}
};