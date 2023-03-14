#ifndef GAME_EXCEPTION
#define GAME_EXCEPTION

#include <exception>
using namespace std;

struct MapElementNotFound : public exception
{
	const char *what() const throw()
	{
		return "Cannot find value!";
	}
};

struct PairVectorOutOfBound : public exception
{
	const char *what() const throw()
	{
		return "Cannot access more than 2 element!";
	}
};

struct NoPairFound : public exception
{
	const char *what() const throw()
	{
		return "No pair found!";
	}
};

// Add your own exception here
struct WrongChoice : public exception
{
	const char *what() const throw()
	{
		return "Your choice is wrong!";
	}
};

struct UncounterCombo : public exception
{
	const char *what() const throw()
	{
		return "Found uncountered combo!";
	}
};

struct HaveBeenUsed : public exception
{
	const char *what() const throw()
	{
		return "Card has been used!";
	}
};

#endif