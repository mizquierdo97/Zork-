typedef unsigned int uint;

template <class TYPE>
class Vector{
private:
	TYPE* buffer;
	uint capacity = 5;
	uint num_elements = 0;

public:

	Vector(){

		buffer = new TYPE[capacity];

	}

	Vector(const Vector& other_array){
		capacity = other_array.capacity;
		num_elements = other_array.num_elements;
		buffer = new TYPE[capacity];
		for (uint i = 0; i < num_elements; i++){
			buffer[i] = other_array.buffer[i];
		}
	}

	~Vector(){
		delete[] buffer;

	}
	void push_back(const TYPE& element){

		TYPE* temp = nullptr;

		if (capacity == num_elements){
			capacity = capacity * 2;
			temp = new TYPE[capacity];

			for (uint i = 0; i < num_elements; i++){
				*(temp + i) = *(buffer + i);

			}
			delete[] buffer;
			buffer = temp;

			temp[num_elements] = element;
		}

		*(buffer + num_elements++) = element;

	}

	void push_front(const TYPE& element){

		if (capacity == num_elements){
			capacity = capacity * 2;
			for (uint i = num_elements; i > 0; i--){
				*(buffer + i) = *(buffer + (i - 1));
			}
			buffer[0] = element;
		}
		for (uint i = num_elements; i > 0; i--){
			*(buffer + i) = *(buffer + (i - 1));
		}
		buffer[0] = element;
	}
	
};