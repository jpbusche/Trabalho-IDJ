#include <iostream>
#include "TileSet.h"

using namespace std;

TileSet::TileSet(int w, int h, string file) : tileWidth(w), tileHeight(h), tileSet(Sprite(file)) {
	rows = tileSet.GetWidth() / tileWidth;
	columns =tileSet.GetHeight() / tileHeight; 
} 

void TileSet::Render(unsigned index, float x, float y) {
	if(index > 0 && index < ((rows * columns) - 1)) {
		tileSet.SetClip(x, y, tileWidth, tileHeight);
		tileSet.Render(x, y);	
	} else {
		printf("Index passado nao eh valido\n");
		exit(1);
	}
}

int TileSet::GetTileWidth() {
	return tileWidth;
}

int TileSet::GetTileHeight() {
	return tileHeight;
}