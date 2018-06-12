#include "Scoreboard.h"

Scoreboard::Scoreboard()
{
}
Scoreboard::~Scoreboard()
{
}
void Scoreboard::insertScr(char _name[INIT], int _score) {
	int cont = NODOL - 1;
	int num = 0;
	bool classif = false;

	for (int i = 0; i < INIT; i++)
	{
		_nodo.name[i] = _name[i];
	}
	_nodo.score = _score;

	if (_nodo.score > sBoard[9].score) {
		for (int i = 0; i < NODOL - 1; i++)
		{
			sBoard[cont] = sBoard[cont - 1];
			cont--;
		}
		sBoard[0] = _nodo;
	}
	sortScr();
}
void Scoreboard::sortScr() {
	for (int i = 0; i <= NODOL; i++) {
		for (int j = 0; j <= NODOL - 2; j++) {
			if (sBoard[j].score < sBoard[j + 1].score) {
				aux = sBoard[j];
				sBoard[j] = sBoard[j + 1];
				sBoard[j + 1] = aux;
			}
		}
	}
}
Nodo Scoreboard::showScr(int _pos) {
	return sBoard[_pos];
}
void Scoreboard::resetScr() {
	Nodo init;
	for (int i = 0; i < INIT; i++) {
		init.name[i] = 'A';
	}
	init.score = 0;
	for (int i = 0; i < NODOL; i++) {
		sBoard[i] = init;
	}
}
