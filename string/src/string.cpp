#include "../string.hpp"

#include <algorithm>

// ctor size_t
String::String(std::size_t n)
    : data_(new char[n + 1]),
      size_(n),
      capacity_(n) {
  data_[n] = '\0';
}

// ctor C-style
String::String(const char* str)
    : String(strlen(str)) {
  std::copy(str, str + size_ + 1, data_);
}

// ctor char
String::String(char c)
    : String(static_cast<std::size_t>(1)) {
  data_[0] = c;
}

// ctor (c, char)
String::String(std::size_t n, char c)
    : String(n) {
  std::fill(data_, data_ + n, c);
  data_[n] = '\0';
}

// ctor String
String::String(const String& other)
    : String(other.size_) {
  std::copy(other.data_, other.data_ + other.size_, data_);
}

// ctor default
String::String()
    : String(static_cast<std::size_t>(0)) {
}

// Length()
std::size_t String::Length() const {
  return size_;
}

// Size()
std::size_t String::Size() const {
  return size_;
}

// Capacity()
std::size_t String::Capacity() const {
  return capacity_;
}

// NewCapacity()
void String::NewCapacity(size_t new_capacity) {
  char* new_data = new char[new_capacity + 1];
  std::copy(data_, data_ + size_ + 1, new_data);
  delete[] data_;
  data_ = new_data;
  capacity_ = new_capacity;
}

// PushBack(char c)
void String::PushBack(char c) {
  if (size_ == capacity_) {
    NewCapacity((size_ == 0) ? 1 : capacity_ * 2);
  }
  data_[size_] = c;
  data_[++size_] = '\0';
}

// PopBack()
void String::PopBack() {
  data_[size_ - 1] = '\0';
  size_--;
}

// const Front() const
const char& String::Front() const {
  return data_[0];
}

// const Front() const
char& String::Front() {
  return data_[0];
}

// Back()
const char& String::Back() const {
  return data_[size_ - 1];
}

// const Back() const
char& String::Back() {
  return data_[size_ - 1];
}

// Empty()
bool String::Empty() const {
  return size_ == 0;
}

// Clear()
void String::Clear() {
  size_ = 0;
  data_[0] = '\0';
}

// ShrinkToFit()
void String::ShrinkToFit() {
  NewCapacity(size_);
}

// Data()
char* String::Data() {
  return data_;
}

// const Data()
const char* String::Data() const {
  return data_;
}

// []
char& String::operator[](std::size_t index) {
  return data_[index];
}

// const[]
const char& String::operator[](std::size_t index) const {
  return data_[index];
}

// Swap()
void String::Swap(String& other) {
  std::swap(data_, other.data_);
  std::swap(size_, other.size_);
  std::swap(capacity_, other.capacity_);
}

// =
String& String::operator=(const String& str) {
  String tmp = str;
  Swap(tmp);
  return *this;
}

// Substr()
String String::Substr(std::size_t start, std::size_t count) const {
  String result(count);
  std::copy(data_ + start, data_ + start + count, result.data_);
  return result;
}

// +=
String& String::operator+=(const String& str) {
  if (capacity_ < size_ + str.size_) {
    NewCapacity(std::max(capacity_ * 2, size_ + str.size_));
  }
  std::copy(str.data_, str.data_ + str.size_ + 1, data_ + size_);
  size_ = size_ + str.size_;
  return *this;
}

// +
String operator+(const String& lhs, const String& rhs) {
  String result(lhs);
  result += rhs;
  return result;
}

// ==
bool operator==(const String& lhs, const String& rhs) {
  if (lhs.size_ != rhs.size_) {
    return false;
  }
  for (std::size_t i = 0; i < lhs.size_; ++i) {
    if (lhs[i] != rhs[i]) {
      return false;
    }
  }
  return true;
}

// <
bool operator<(const String& lhs, const String& rhs) {
  std::size_t min_size = std::min(lhs.size_, rhs.size_);
  for (std::size_t i = 0; i < min_size; ++i) {
    if (lhs[i] < rhs[i]) {
      return true;
    } else if (lhs[i] > rhs[i]) {
      return false;
    }
  }
  return lhs.size_ < rhs.size_;
}

// >
bool operator>(const String& lhs, const String& rhs) {
  return rhs < lhs;
}

// <=
bool operator<=(const String& lhs, const String& rhs) {
  return !(rhs < lhs);
}

// >=
bool operator>=(const String& lhs, const String& rhs) {
  return !(lhs < rhs);
}

// IsSpace
bool IsSpace(char c) {
  return std::isspace(static_cast<unsigned char>(c)) != 0;
}

// IgnoreSpaces
void IgnoreSpaces(std::istream& istream) {
  using CharTraits = std::istream::traits_type;

  char c = '\0';
  while (istream.good()) {
    c = CharTraits::to_char_type(istream.get());
    if (!IsSpace(c)) {
      istream.unget();
      return;
    }
  }
}

// >>
std::istream& operator>>(std::istream& istream, String& str) {
  using CharTraits = std::istream::traits_type;

  IgnoreSpaces(istream);
  str.Clear();

  char c = '\0';
  while (istream.good()) {
    c = CharTraits::to_char_type(istream.get());
    if (!istream.good()) {
      break;
    }
    if (IsSpace(c)) {
      istream.unget();
      break;
    }
    str.PushBack(c);
  }
  return istream;
}

// <<
std::ostream& operator<<(std::ostream& ostream, const String& str) {
  ostream.write(str.Data(), str.Size());
  return ostream;
}

// Find()
std::size_t String::Find(const String& substr) const {
  if (substr.size_ > size_) {
    return size_;
  }

  for (std::size_t index = 0; index <= size_ - substr.size_; ++index) {
    if (std::memcmp(data_ + index, substr.data_, substr.size_) == 0) {
      return index;
    }
  }
  return size_;
}

// Rfind()
std::size_t String::Rfind(const String& substr) const {
  if (substr.size_ > size_) {
    return size_;
  }

  for (std::size_t index = size_ - substr.size_ + 1; index > 0; --index) {
    std::size_t pos = index - 1;
    if (std::memcmp(data_ + pos, substr.data_, substr.size_) == 0) {
      return pos;
    }
  }
  return size_;
}

// dtor!!!
String::~String() {
  delete[] data_;
}
