#include <iostream>

void bubblesort1A(int arr[], int n) {
	bool sorted = false;
	while (!sorted){
		sorted = true;
		for (int i = 0; i < n - 1; i++){
			if (arr[i] > arr[i + 1]){
				swap(arr[i], arr[i + 1]);
				sorted = false;
			}
		}
		n--;
	}
}

template <typename T> void Vector<T>::expand() {
	if (size < capacity) return;// no need to expand
	if (capacity < DEFAYLT_CAPACITY) capacity = DEFAYLT_CAPACITY;// ensure minimum capacity
	T* oldElem = elem; // keep the old address
	elem = new T[capacity <<= 1]; // double the capacity
	for (int i = 0; i < size; i++) 
		elem[i] = oldElem[i]; // copy old elements
	delete[] oldElem; // free the old space
}

template <typename T> void Vector<T>::shrink() {
	if (capacity < DEFAYLT_CAPACITY<<1) return; // no need to shrink
	if (size > capacity >>2) return; // no need to shrink
	T* oldElem = elem; // keep the old address
	elem = new T[capacity >>= 1]; // halve the capacity
	for (int i = 0; i < size; i++) 
		elem[i] = oldElem[i]; // copy old elements
	delete[] oldElem; // free the old space
}

template <typename T>T& Vector<T>::operator[](Rank r) const {
	return elem[r];// return element at rank r
}

template <typename T> void permute(Vector<T>& V) {
	for (int i = V.size(); i > 0; i--) // from the end to the beginning
		swap(V[i - 1], V[rand() % i]); // swap the last element with a random one among the first i elements
}

template <typename T> Rank Vector<T>::find(T const& e, Rank lo, Rank hi){
	while ((lo < hi--) && (e != elem[hi])); // from the end to the beginning
	return hi; // return the rank of the found element, or lo-1 if not found
}

template <typename T> Rank Vector<T>::insert(Rank r,T const& e){
	expand(); // ensure space
	for (int i = size; i > r; i--) 
		elem[i] = elem[i - 1]; // shift elements to the right
	elem[r] = e; // insert the new element
	size++; // increase size
	return r; // return the rank of the inserted element
}

template<typename T> T Vector<T>::remove(Rank r) {
	T e = elem[r]; // keep the element to be removed
	for (int i = r; i < size - 1; i++) 
		elem[i] = elem[i + 1]; // shift elements to the left
	size--; // decrease size
	shrink(); // ensure space
	return e; // return the removed element
}

template <typename T> int Vector<T>::deduplicate() {
	int oldSize = size; // keep the old size
	Rank i = 1; // start from the second element
	while (i < size) // traverse the vector
		(find(elem[i], 0, i) < 0) ? i++ : remove(i); // if elem[i] is not found in the previous part, move to the next; otherwise, remove it
	return oldSize - size; // return the number of removed elements
}

#include "..\fibonacci\Fib.h"
template <typename T> static Rank fibSearch(T* A, T const& e, Rank lo, Rank hi) {
	Fib fib(hi - lo); // create a Fibonacci number generator
	while (lo < hi) {
		while (hi - lo < fib.get()) fib.prev(); // find the largest Fibonacci number less than the range size
		Rank mi = lo + fib.get() - 1; // calculate the mid index
		if (e < A[mi]) hi = mi; // search in the left part
		else if (A[mi] < e) lo = mi + 1; // search in the right part
		else return mi; // element found
	}
	return -1; // element not found
}
