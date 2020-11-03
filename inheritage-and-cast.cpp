
#include <vector>
#include <iostream>

using namespace std;

class Shape
{
 public:
  virtual int perimeter() = 0;
  virtual int aera() = 0;
  virtual const char *name() = 0;

};

class Square : public Shape
{
 public:
  Square(int side):m_side(side) {};
  virtual ~Square() {};

  virtual int perimeter() {return 4 * m_side;};
  virtual int aera() {return m_side * m_side;};
  virtual const char *name() {return m_name;};

 private:
  const char *m_name = "Square";
  int m_side;
};

class Rectangle : public Shape
{
 public:
  Rectangle(int length, int width):m_length(length), m_width(width)  {};
  virtual ~Rectangle() {};

  virtual int perimeter() {return 2 * m_length + 2 * m_width;};
  virtual int aera() {return m_length *  m_width;};
  virtual const char *name() {return m_name;};

 private:
  const char *m_name = "Rectangle";
  int m_length;
  int m_width;
};

struct Raw {
  char m_raw[sizeof(Square)];
};


int main(int argc, char *argv[])
{

  vector<Shape*> v;

  v.push_back(new Square(2));
  v.push_back(new Rectangle(2,3));

  // get vector content
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << (*it)->name() << ": "  << "perimeter:" << (*it)->perimeter() << ", aera:" << (*it)->aera() << endl;
  }

  // static cast : check only at compilation time
  for (auto it = v.begin(); it != v.end(); ++it) {
    cout << "static_cast<Rectangle *> of " << (*it)->name() << " is "
         << ((static_cast<Rectangle *>(*it))!=nullptr?"OK":"detect wrong cast !!!") << endl;
  }

  // dynamic cast : check at runtime and return nullptr if not suitable
  for (auto it = v.begin(); it != v.end(); ++it) {
    Rectangle * rect = (dynamic_cast<Rectangle *>(*it));
    cout << "dynamic_cast<Rectangle *> of " << (*it)->name() << " is "
         << (rect!=nullptr?"OK":"detect wrong cast !!!") << endl;
  }

  // reinterpret_cast
  for (auto it = v.begin(); it != v.end(); ++it) {
    Raw *params = (reinterpret_cast<Raw *>(*it));

    cout << "reinterpret_cast <Raw *> of " << (*it)->name() << " is "
         << (params!=nullptr?"OK":"detect wrong cast !!!");

    // manipulate the result for fun
    for(uint i=0; i < sizeof(Square); i++) {
      cout << params->m_raw[i];
    }
    cout << endl;

  }

  return 0;
}
