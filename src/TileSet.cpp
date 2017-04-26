#include "TileSet.h"

using namespace std;

TileSet::TileSet(int w, int h, string file) : tileWidth(w), tileHeight(h) {
	tileSet.Open(file);
	columns = tileSet.GetWidth() / tileWidth;
	rows = tileSet.GetHeight() / tileHeight; 
} 

void TileSet::Render(unsigned index, float x, float y) {
	if(index >= 0 && index <= ((rows * columns) - 1)) {
		int posX = tileWidth * (index % columns);
		int posY = tileHeight * (index / columns);
		tileSet.SetClip(posX, posY, tileWidth, tileHeight);
		tileSet.Render(x, y);	
	}
}

int TileSet::GetTileWidth() {
	return tileWidth;
}

int TileSet::GetTileHeight() {
	return tileHeight;
}