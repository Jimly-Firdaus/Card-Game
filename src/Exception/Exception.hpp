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

struct InvalidInput : public exception
{
	const char *what() const throw()
	{
		return "Invalid input!";
	}
};

struct FileNotFound : public exception
{
	const char *what() const throw()
	{
		return "File not found!";
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
		return "telah dimatikan sebelumnya";
	}
};

struct WrongAbilityCard: public exception
{
	const char *what() const throw()
	{
		return "Eits, tidak bisa. Kamu tidak punya kartu Ability ";
	}
};

struct LeftOne: public exception
{
	const char *what() const throw()
	{
		return "Sayangnya poin hadiah sudah bernilai 1. Poin hadiah tidak berubah.. Giliran dilanjut!";
	}
};

struct AllTargetUsedAbilityCard: public exception
{
	const char* what() const throw()
	{
		return "Eits, ternyata semua pemain sudah memakai kartu kemampuan. Yah, kamu sendiri deh, kemampuanmu menjadi abilityless. Yah, penggunaan kartu ini sia-sia.";
	}
};

#endif