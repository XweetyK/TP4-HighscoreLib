#include <iostream>
#include <list>
using namespace std;
#define INIT 4

struct Nodo {
	char name[INIT]{ 'A','A','A'};
	int score = 000000000;
};
class Scoreboard {
private:
	list <Nodo> * sBoard;
public:
	Scoreboard() {
	sBoard = new list <Nodo>;
	};
	~Scoreboard() {
		delete sBoard;
	};
	void insertScr(char _name[INIT], int _score) {
		Nodo _nodo;
		for (int i = 0; i < INIT; i++)
		{
			_nodo.name[i] = _name[i];
		}
		_nodo.score = _score;
		sBoard->push_back(_nodo);
		
	}
	Nodo showScrMax() {
		Nodo _nodo;
		if (!sBoard->empty()) {
			_nodo = sBoard->front();
			sBoard->pop_front();
			sBoard->push_back(_nodo);
			return _nodo;
		}
	}
	void resetScr() {
		sBoard->clear();
	}
};
int main() {
	Scoreboard* score= new Scoreboard;
	int n;
	char c[INIT]{ 'a','b','c' };
	char d[INIT]{ 'a','b','h' };
	char e[INIT]{ 'a','h','c' };
	char f[INIT]{ 'h','b','c' };
	n = 3;
	score->insertScr(c, n);
	score->insertScr(d, n);
	score->insertScr(e, n);
	score->insertScr(f, n);
	for (int i = 0; i < 4; i++)
	{
		Nodo _nodo = score->showScrMax();
		cout << _nodo.name << " "<<_nodo.score<<endl;
	}
	cin.get();
}