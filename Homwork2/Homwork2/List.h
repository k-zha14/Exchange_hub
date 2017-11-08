//
// Created by Kai Zhao on 2017/11/1.
//
#include <iostream>

#ifndef C_WORKSPACE_LIST_H
#define C_WORKSPACE_LIST_H

#endif //C_WORKSPACE_LIST_H
template <typename T> struct Node{
	Node(){};//for header and trailer
    Node(const T& data)
            :_data(data),
            _pre(NULL),
            _next(NULL){}

    T _data;
    Node<T>* _pre;
    Node<T>* _next;
	//inserted as precessor, return new node
	Node<T>* insertAsPred(const	T & e){
		Node<T>* newNode = new Node<T>(e);
		newNode->_next = this;
		this->_pre = newNode;
	}
	//inserted as successor, return new node  
	Node<T>* insertAsSucc(const T & e){
		Node<T>* newNode = new Node<T>(e);
		newNode->_pre = this;
		this->_next = newNode;
	}

};

template <typename T> class List{

private:
	int _size;
	Node<T> *header, *trailer;
public:
	List(){
		header = new Node<T>();
		trailer = new Node<T>();
		header->_next = trailer; header->_pre = NULL;
		trailer->_pre = header; trailer->_next = NULL;
		_size = 0;
	}
	~List(){
		Node<T>* pCur = header;
		while(pCur->_next != NULL){
			Node<T>* pDel = pCur;
			pCur = pCur->_next;
			pCur->_pre = NULL;
			delete pDel;
			_size--;
		}
		delete trailer;
	}
	//return size()
	int size(){
		return _size;
	}
	//front
	T front(){
		return header->_next->_data;
	}

	//push in the front
	void PushFront(const T &data){
		Node<T>* temp = new Node<T>(data);
		temp->_next = header->_next;
		temp->_next->_pre = temp;
		temp->_pre = header;
		header->_next = temp;
		_size++;
	}
	//push int the back
	void PushBack(const T &data){
		Node<T>* temp = new Node<T>(data);
		temp->_pre = trailer->_pre;
		temp->_pre->_next = temp;
		temp->_next = trailer;
		trailer->_pre = temp;
		_size++;
	}

	//pop from the trailer
	T PopBack(){
		Node<T>* temp = trailer->_pre;
		trailer->_pre = temp->_pre;
		temp->_pre->_next = trailer;
		T backup = temp->_data;
		delete temp;
		--_size;
		return backup;
	}
	//pop from the beginner
	T PopFront(){
		Node<T>* temp = header->_next;
		header->_next = temp->_next;
		temp->_next->_pre = header;
		T backup = temp->_data;
		delete temp;
		_size--;
		return backup;
	}

	//print from the beginning to the end
/*	void Print(){
		Node<T>* temp = header;
		while (temp->_next != trailer)
		{
			temp = temp->_next;
			cout << temp->_data << "	";
		}
		cout << endl;
	}
*/
};