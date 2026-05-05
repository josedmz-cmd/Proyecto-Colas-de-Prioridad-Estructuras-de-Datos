#pragma once
template <typename E>
class List {
public:
	List() {}
	List(const List<E>& other) = delete;
	void operator=(const List<E>& other) = delete;
	virtual ~List() {}
	virtual void insert(E element) = 0;
	virtual void append(E element) = 0;
	virtual void set_element(E element) = 0;
	virtual E get_Element() = 0;
	virtual E remove() = 0;
	virtual void clear() = 0;
	virtual void go_to_start() = 0;
	virtual void go_to_end() = 0;
	virtual void go_to_pos(int pos) = 0;
	virtual void next() = 0;
	virtual void previous() = 0;
	virtual bool at_start() = 0;
	virtual bool at_end() = 0;
	virtual int get_pos() = 0;
	virtual int get_size() = 0;
	virtual void print() = 0;
};
