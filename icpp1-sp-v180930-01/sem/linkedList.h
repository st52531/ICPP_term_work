#ifndef LINKEDLIST_H
#define LINKEDLIST_H
template<typename T>
struct LinkedList {
	template<typename T>
	struct Element {
		T data;
		Element<T> *previous = nullptr;
		Element() {}
	};
private:
	Element<T> *peak;
public:
	~LinkedList();
	LinkedList();
	void insertLast(T data);
	void deleteLast();
	bool isInList(T data)const;
	T getPeak();
};
template<typename T>
LinkedList<T>::LinkedList() {
	peak = nullptr;
}
template<typename T>
LinkedList<T>::~LinkedList() {
	Element<T>* temp = new Element<T>;
	while (peak != nullptr) {
		temp = peak->previous;
		delete peak;
		peak = temp;
	}
	delete temp;
}
template<typename T>
void LinkedList<T>::insertLast(T data) {
	Element<T>* newE = new Element<T>;
	newE->data = data;
	newE->previous = nullptr;
	if (peak == nullptr) {
		peak = newE;
	}
	else {
		newE->previous = peak;
		peak = newE;
	}
	delete newE;
}
template<typename T>
void LinkedList<T>::deleteLast() {
	Element<T>* temp = new Element<T>;
	temp = peak;
	peak = peak->previous;
	delete temp;
}

template<typename T>
bool LinkedList<T>::isInList(T data) const{
	Element<T>* el = new Element<T>;
	el = peak;
	while (el != nullptr) {
		if (operator==(el->data, data)) {
			delete el;
			return true;
		}
		el = el->previous;
	}
	delete el;
	return false;
}
template<typename T>
T LinkedList<T>::getPeak() {
	return peak->data;
}
template<typename T>
bool operator==(T const& a, T const& b) {
	return a.x == b.x && a.y == b.y;
}

#endif