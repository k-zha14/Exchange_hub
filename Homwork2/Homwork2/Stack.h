template <typename T> class Stack{
private:
	T* val;
	int _top;
	int length;
public:
	Stack(int m=100){
		length = m;
		val = new T[m];
		_top = 0;
	}
	~Stack(){
		delete[] val;
	}
	bool isEmpty(){
		return !_top;
	}
	bool push(T temp){
		_top++;
		if(_top<length+1){
			val[_top] = temp;
			return true;
		}
		else{
			return false;
		}
	}
	T pop(){
		if(!isEmpty()){
			int i = _top;
			_top--;
			return val[i];
		}
		else
			return NULL;
	}
	T top(){
		return val[_top];
	}
};
