

typedef unsigned int uint;

class String{
private:
	char* buffer;
	uint mcapacity;
public:
	String(){};
	String(const char* str);
	String(const String& str);
	~String();
	uint length()const;
	const char* c_str()const;
	bool empty()const;
	bool operator == (const String& str) const;
	bool operator == (const char* str) const;
	void operator = (const String& str);
	char* operator +(const String& str)const;
	void operator += (const String& str);
	void clean();
	void shrink_to_fit();
	uint capacity() const;
	char* tokenize(const char character, const String& str);

};