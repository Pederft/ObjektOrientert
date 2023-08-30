#pragma once
#include "AnimationWindow.h"
#include "widgets/Button.h"

// De forskjellige tilstandene en Tile kan vaere i
enum class Cell { closed, open, flagged }; 

class Tile : public TDT4102::Button
{
	Cell state = Cell::closed;
	void set_label(std::string s) { this->setLabel(s);}
	void set_label_color(TDT4102::Color c) {this->setLabelColor(c);}
	bool isMine = false;
public:
	Tile(TDT4102::Point pos, int size);

	void open();
	void flag();
	bool getMine();
	void setMine(bool r);
	void setAdjMines(int n);

	Cell getState() const { return state; };
};
