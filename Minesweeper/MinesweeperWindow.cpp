#include "MinesweeperWindow.h"
#include <iostream>
#include <random>

MinesweeperWindow::MinesweeperWindow(int x, int y, int width, int height, int mines, const string &title) : 
	// Initialiser medlemsvariabler, bruker konstruktoren til AnimationWindow-klassen
	AnimationWindow{x, y, width * cellSize, (height + 1) * cellSize, title},
	width{width}, height{height}, mines{mines}
{
	// Legg til alle tiles i vinduet
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			tiles.emplace_back(new Tile{ Point{j * cellSize, i * cellSize}, cellSize});
			tiles.back()->setCallback(std::bind(&MinesweeperWindow::cb_click, this));
			auto temp = tiles.back().get();
			add(*temp); 
		}
	}

	//Plasserer ut tilfeldige miner 
	int i = 0;
	while(i < mines){
		int pos = rand() % tiles.size();
		if(!tiles.at(pos)->getMine()) {
			tiles.at(pos)->setMine(true);
			i++;
	}
}
}

vector<Point> MinesweeperWindow::adjacentPoints(Point xy) const {
	vector<Point> points;
	for (int di = -1; di <= 1; ++di) {
		for (int dj = -1; dj <= 1; ++dj) {
			if (di == 0 && dj == 0) {
				continue;
			}

			Point neighbour{ xy.x + di * cellSize,xy.y + dj * cellSize };
			if (inRange(neighbour)) {
				points.push_back(neighbour);
			}
		}
	}
	return points;
}

int MinesweeperWindow::countMines(vector<Point> coords) const {
	int miner = 0;

	for(Point p : coords){
		if(at(p) -> getMine()){
			miner++;
		}
	}
	return miner;
}

void MinesweeperWindow::openTile(Point xy) {

	shared_ptr<Tile>& tile = at(xy);

	if(tile -> getState() != Cell::closed){
		return;
	}

	if(tile->getMine()){
		//gameLost();
		//tile ->open();
		return;
	} /*else {
		tile -> open();
		if(countMines(adjacentPoints(xy)) > 0){
			tile -> setAdjMines(countMines(adjacentPoints(xy)));
		}
	}*/

	tile -> open();

	vector<Point> adjPoints = adjacentPoints(xy);
	int adjMines = countMines(adjPoints);

	if (adjMines > 0) { 
		// Hvis det er miner i naerheten setter vi labelen
		tile->setAdjMines(adjMines);
	}
	else {
		// Hvis det ikke er noen miner i naerheten vil vi aapne tilene rundt rekursivt 
		for (Point p : adjPoints) {
			openTile(p);
		}
	}

}

void MinesweeperWindow::flagTile(Point xy) {	

	at(xy) -> flag();

	/*if(at(xy) -> getState() != Cell::closed){
		at(xy) -> flag();
	}

	if(at(xy) -> getState() == Cell::flagged){
		minesLeftUser--;
	}*/


}

//Kaller openTile ved venstreklikk og flagTile ved hoyreklikk
void MinesweeperWindow::cb_click() {
	
	Point xy{this->get_mouse_coordinates()};
	//std::cout << xy.x << " " << xy.y <<": " << xy.x / (cellSize) + (xy.y / cellSize) * width<<"\n";

	if (!inRange(xy)) {
		return;
	}
	if (this->is_left_mouse_button_down()) {
		openTile(xy);
	}
	else if(this->is_right_mouse_button_down()){
		flagTile(xy);
	}
}


