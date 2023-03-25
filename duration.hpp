#pragma once

#include<iostream>

class Duration {
  private:
int secs;
int minute; 
int hour;

  public:
Duration();
Duration(int);
Duration(int,int,int);
Duration(const std::string&);

Duration(const Duration&);
Duration(Duration&&);

Duration& operator=(const Duration&);
Duration& operator=(Duration&&);

const int& get_h() const;
const int& get_m() const;
const int& get_s() const;

Duration& set_s(const int&) ;
Duration& set_m(const int&) ;
Duration& set_h(const int&) ;

bool operator==(const Duration&);
bool operator!=(const Duration&);
bool operator>(const Duration&);
bool operator<(const Duration&);
bool operator>=(const Duration&);
bool operator<=(const Duration&);

operator bool() const;
bool operator!() const;

Duration& operator+=(const Duration&);
Duration& operator+(Duration&);
Duration& operator-=(const Duration&);
Duration& operator-(Duration&);
Duration& operator*(const int&);
Duration& operator*=(const int&);
Duration& operator/(const int&);
Duration& operator/=(const int&);

friend std::ostream& operator<<(std::ostream&, const Duration&);
friend std::istream& operator>>(std::istream&, Duration&);
};


