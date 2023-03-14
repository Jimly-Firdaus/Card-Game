#ifndef GAME_EXCEPTION
#define GAME_EXCEPTION

#include <exception>
using namespace std;

struct MapElementNotFound : public exception {
    const char* what() const throw() {
		return "Cannot find value!";
	}
};

// Add your own exception here
struct WrongChoice : public exception{
	const char* what() const throw(){
		return "Your choice is wrong!";
	}
};

#endif