#include <iostream>

class Fixed
{
  private:
	int _Value;
	static const int _RawBits;

  public:
	Fixed();
	Fixed(const Fixed &copy);
	Fixed &operator=(const Fixed &copy);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
};