#include "Tile.h"
#include <map>

// For aa sette labelfarge i henhold til hvor mange miner som er rundt
const std::map<int, TDT4102::Color> minesToColor{{1, TDT4102::Color::blue},
												{2, TDT4102::Color::red},
												{3, TDT4102::Color::dark_green},
												{4, TDT4102::Color::dark_magenta},
												{5, TDT4102::Color::dark_blue},
												{6, TDT4102::Color::dark_cyan},
												{7, TDT4102::Color::dark_red},
												{8, TDT4102::Color::gold}};

// For aa sette Tilelabel i henhold til state
const std::map<Cell, std::string> cellToSymbol{{Cell::closed, ""},
									 			{Cell::open, ""},
									 	  		{Cell::flagged, "|>"}};

Tile::Tile(TDT4102::Point pos, int size) : 
	Button({pos.x, pos.y}, 1.5*size, size, "") {
		setButtonColor(TDT4102::Color::silver);
	}

void Tile::open()
{
	if(state != Cell::flagged){
		this->setButtonColor(TDT4102::Color::white);
		state = Cell::open;

		if(isMine){
			set_label("X");
			set_label_color(TDT4102::Color::red);
		}
	}
}

void Tile::flag()
{
	if(state == Cell::flagged){
		state = Cell::closed;
		set_label(cellToSymbol.at(Cell::closed));
	}

	switch (state){
		case Cell::closed:
			set_label(cellToSymbol.at(Cell::flagged));
			state = Cell::flagged;
			set_label_color(TDT4102::Color::black);
			break;
		case Cell::flagged:
			set_label(cellToSymbol.at(Cell::closed));
			state = Cell::closed;
			break;
		case Cell::open:; //Kan ikke flagge en åpen rute
	}
}

bool Tile::getMine(){
	return isMine;
}

void Tile::setMine(bool r){
	isMine = r;
}

void Tile::setAdjMines(int n){
	assert(n >= 1 && n <= 8); //Sjekker for range til input er mellom 1-8

	set_label(std::to_string(n));
	setLabelColor(minesToColor.at(n));
}

