#include <cstring>
#include <iostream>

class String {
 public:
  String(const char* str);        // ctor C-style // done
  String(std::size_t n, char c);  // ctor (n, char) // done
  String(char c);                 // ctor char //done

  String();                              // default ctor //done
  String(const String& other);           // ctor copy //done
  String& operator=(const String& str);  // operator = //done

  const char& operator[](std::size_t index) const;  // const [] //done
  char& operator[](std::size_t index);              //[] //done
  String& operator+=(const String& str);            //+= //done

  std::size_t Length() const;    // done
  std::size_t Size() const;      // done
  std::size_t Capacity() const;  // done

  void PushBack(char c);  // done
  void PopBack();         // done

  const char& Front() const;  // done
  char& Front();              // done

  const char& Back() const;  // done
  char& Back();              // done

  std::size_t Find(const String& substring) const;   // done
  std::size_t Rfind(const String& substring) const;  // done

  String Substr(std::size_t start, std::size_t count) const;  // done

  bool Empty() const;  // done
  void Clear();        // done
  void ShrinkToFit();  // done

  char* Data();              // done
  const char* Data() const;  // done

  friend String operator+(const String& lhs, const String& rhs);  // + //done

  friend bool operator==(const String& lhs,
                         const String& rhs);  // == //done

  friend bool operator<(const String& lhs,
                        const String& rhs);  // < //done

  friend bool operator>(const String& lhs,
                        const String& rhs);  // > //done

  friend bool operator<=(const String& lhs,
                         const String& rhs);  // <= //done

  friend bool operator>=(const String& lhs,
                         const String& rhs);  // >= //done

  ~String();  // dtor!!! // done

 private:
  char* data_;
  std::size_t size_;
  std::size_t capacity_;

  String(std::size_t n);                  // вспомогательный конструктор // done
  void Swap(String& other);               // вспомогательный swap //done
  void NewCapacity(size_t new_capacity);  // capacity --> new_capacity //done
};

bool IsSpace(char c);                      // done
void IgnoreSpaces(std::istream& istream);  // done

std::ostream& operator<<(std::ostream& ostream, const String& str);  // << done
std::istream& operator>>(std::istream& istream, String& str);        // >> done
