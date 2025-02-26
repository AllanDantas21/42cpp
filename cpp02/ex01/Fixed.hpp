#include <cmath>
#include <iostream>

class Fixed
{
  private:
	int _Value;
	static const int _RawBits;

  public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed(const int n);
	Fixed(const float n);
	~Fixed();

	Fixed &operator=(const Fixed &copy);
	int getRawBits(void) const;
	int toInt(void) const;
	float toFloat(void) const;
	void setRawBits(int const raw);
};

std::ostream &operator<<(std::ostream &os, const Fixed &Fixed);