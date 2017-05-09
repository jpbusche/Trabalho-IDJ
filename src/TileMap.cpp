#include <fstream>
#include <cstdio>
#include "TileMap.h"


using namespace std;

TileMap::TileMap(string file, TileSet * tileSet) {
	Load(file);
	SetTileSet(tileSet);
}

void TileMap::Load(string file) {
	tileMatrix.clear();
	int n;
	fstream tileFile(file);
	if(not tileFile.is_open()) {
		printf("Erro na abertura do arquivo\n");
		exit(1);
	}
	tileFile >> mapWidth;
	tileFile.ignore(2, ',');
	tileFile >> mapHeight;
	tileFile.ignore(2, ',');
	tileFile >> mapDepth;
	tileFile.ignore(2, ',');
	while(tileFile >> n) {
		tileMatrix.emplace_back(n - 1);
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
	for(int i = 0; i < mapHeight; i++) {
		for(int j = 0; j < mapWidth; j++) {
			int index = At(j, i, layer);
			double posX = i * tileSet->GetTileWidth() + cameraX;
			double posY = j * tileSet->GetTileHeight() + cameraY;
			tileSet->Render(index, posX, posY);
		}
	}
}

void TileMap::Render(int cameraX, int cameraY) {
	for(int layer = 0; layer < mapDepth; layer++) {
		RenderLayer(layer, cameraX, cameraY);
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