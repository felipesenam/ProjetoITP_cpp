
#include "lib.hpp"

long int lib::fat(int num)
{
	if(num == 0)
	{
		return 1;
	}
	for(long int i = num - 1; i > 0; i--)
	{
		num *= i;
	}
	return num;
}

long int lib::bin(int n, int i)
{
	return fat(n) / (fat(i) * fat(n - i));
}

double lib::rad(double deg)
{
	return deg * PI / 180;
}

std::string lib::stolower(const std::string& word)
{
	std::stringstream ss;

	for(auto c : word)
	{
		ss << (unsigned char)tolower(c);
	}

	return ss.str();
}

int lib::cstrcmp(const std::string& string1, const std::string& string2)
{
	return strcmp(stolower(string1).c_str(), stolower(string2).c_str());
}

bool isany(const char letter, const std::string& vect)
{
	for(auto l : vect)
	{
		if(letter == l)
		{
			return true;
		}
	}
	return false;
}

bool lib::isany(const std::string& word, const std::string& vect)
{
	for(const auto& wl : word)
	{
		for(const auto& vl : vect)
		{
			if(wl == vl)
			{
				return true;
			}
		}
	}
	return false;
}

size_t lib::chartcount(const std::string& string)
{
	size_t count = string.length();
	for(unsigned char cc : string)
	{
		if(cc == 195 || cc == 194)
		{
			count -= 1;
		}
	}
	return count;
}

Uint32 lib::getpixel(SDL_Surface *surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

	switch (bpp)
	{
		case 1:
			return *p;
		case 2:
			return *(Uint16 *)p;
		case 3:
			if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			{
				return p[0] << 16 | p[1] << 8 | p[2];
			}
			else
			{
				return p[0] | p[1] << 8 | p[2] << 16;
			}
		case 4:
			return *(Uint32 *)p;
		default:
			return 0;
	}
}