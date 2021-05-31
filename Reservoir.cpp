#include <iostream>
using namespace std;

class Reservior {
	char* m_name;
	char* m_type;
	int m_width;
	int m_height;
	int m_deep;
public:
	explicit Reservior(const char* name, const char* m_type, int width, int height, int deep);
	Reservior(const Reservior& res);
	~Reservior();
	int getVolume() const;
	friend ostream& operator<<(ostream& out, const Reservior& res);
	Reservior& operator=(const Reservior& res);
	Reservior& copy(const Reservior& res);
	bool comparisonOfTypes(const Reservior& res) const;
	int getSurfaceArea() const;
	void comparisonSurfaceAreas(const Reservior& res) const;
	Reservior& setName(const char* name);
	Reservior& setType(const char* type);
	Reservior& setSizeReservior(int width, int height, int deep);
	char* getName() const { return m_name; }
	char* getType() const { return m_type; }
	Reservior& addReservior();
	Reservior& delReservior();

};
Reservior::Reservior(const char* name = "", const char* type = "", int width = 0, int height = 0, int deep = 0)
	: m_width(width), m_height(height), m_deep(deep)
{
	m_name = new char[strlen(name) + 1];
	strcpy_s(m_name, strlen(name) + 1, name);
	m_type = new char[strlen(type) + 1];
	strcpy_s(m_type, strlen(type) + 1, type);

}
Reservior::Reservior(const Reservior& res)
	:m_name(res.m_name), m_type(res.m_type), m_width(res.m_width), m_height(res.m_height), m_deep(res.m_deep)
{

}
Reservior::~Reservior() {
	delete[]m_name;
	delete[]m_type;
}

int Reservior::getVolume() const { return m_width*m_height*m_deep; }

ostream& operator<<(ostream& out, const Reservior& res) {
	out << "Name of the reservoir: " << res.m_name << endl
		<< "Type of reservoir: " << res.m_type << endl
		<< "Surface area of the reservoir" << res.getSurfaceArea() << endl;
	return out;
}
Reservior& Reservior::operator=(const Reservior& res) {
	if (&res == this) return *this;
	m_name = new char[strlen(res.m_name) + 1];
	strcpy_s(m_name, strlen(res.m_name) + 1, res.m_name);
	m_type = new char[strlen(res.m_type) + 1];
	strcpy_s(m_type, strlen(res.m_type) + 1, res.m_type);
	m_width = res.m_width;
	m_height = res.m_height;
	m_deep = res.m_deep;
}
Reservior& Reservior::copy(const Reservior& res) {
	*this = res;
	return *this;
}
bool Reservior::comparisonOfTypes(const Reservior& res) const {
	if (strcmp(m_type, res.m_type) == 0) {
		cout << "Reservoirs of the same type: " << m_type << " - " << res.m_type << endl;
		return true;
	}
	else {
		cout << "Reservoirs of different types: " << m_type << " - " << res.m_type << endl;
		return false;
	}
}
int Reservior::getSurfaceArea() const { return m_width * m_height; }
void Reservior::comparisonSurfaceAreas(const Reservior& res) const {
	if (comparisonOfTypes(res)) {
		if(getSurfaceArea() > res.getSurfaceArea())
		cout << "The area of " << m_name << " is larger than the area of " << res.m_name << endl;
		else if(getSurfaceArea() < res.getSurfaceArea())
			cout << "The area of " << m_name << " is less than the area of " << res.m_name << endl;
		else
			cout << "The area of " << m_name << " is equal to the area of " << res.m_name << endl;

	}
	else {
		cout << "It is impossible to compare the area of reservoirs as they are of different types.";
	}

}
Reservior& Reservior::setName(const char* name = "") {
	delete[]m_name;
	m_name = new char[strlen(name) + 1];
	strcpy_s(m_name, strlen(name) + 1, name);
	return *this;
}
Reservior& Reservior::setType(const char* type = "") {
	delete[]m_type;
	m_type = new char[strlen(type) + 1];
	strcpy_s(m_type, strlen(type) + 1, type);
	return *this;
}
Reservior& Reservior::setSizeReservior(int width, int height, int deep) {
	m_width = width;
	m_height = height;
	m_deep = deep;
	return *this;
}
Reservior& Reservior::addReservior() {
	return  *this;

}
Reservior& Reservior::delReservior() {
	return *this;
}
int main()
{
	Reservior* res = new Reservior[4]{	Reservior{"Baikal", "Lake", 150, 190, 30}, 
						Reservior{"Pyasino", "Lake", 350, 160, 15},
						Reservior{"Volga", "River", 1500, 100, 25},
						Reservior{"Black sea", "Sea", 700, 450, 60} };
	cout << sizeof(res[0]) + sizeof(res[1]);
	delete[]res;
}

