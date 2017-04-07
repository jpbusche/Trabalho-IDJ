#include <fstream>
#include "TileMap.h"


using namespace std;

TileMap::TileMap(string file, TileSet * tileSet) {
	Load(file);
	SetTileSet(tileSet);
}

void TileMap::Load(string file) {
	int n;
	fstream tileFile(file);
	tileFile >> mapWidth;
	tileFile.ignore(2, ',');
	tileFile >> mapHeight;
	tileFile.ignore(2, ',');
	tileFile >> mapDepth;
	tileFile.ignore(2, ',');
	while(tileFile >> n) {
		tileMatrix.push_back(n - 1);
		tileFile.ignore(2, ',');
	}
}

void TileMap::SetTileSet(TileSet * imageSet) {
	tileSet = imageSet;
}

int & TileMap::At(int x, int y, int z) {
	int index = (z * mapWidth * mapHeight) + (x * mapHeight) + y;
	return tileMatrix[index];
}

void TileMap::RenderLayer(int layer, int cameraX, int cameraY) {
	for(int i = 0; i < mapWidth; i++) {
		for(int j = 0; j < mapHeight; j++) {
			int index = At(i, j, layer);
			int posX = i * tileSet->GetTileWidth();
			int posY = j * tileSet->GetTileHeight();
			tileSet->Render(index, posX, posY);
		}
	}
}

void TileMap::Render(int cameraX, int cameraY) {
	for(int i = 0; i < mapDepth; i++) {
		RenderLayer(i);
	}
}

int TileMap::GetWidth() {
	return mapWidth;
}

int TileMap::GetHeight(){
	return mapHeight;
}

int TileMap::GetDepth(){
	return mapDepth;
}