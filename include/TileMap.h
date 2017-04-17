#ifndef TILEMAP_H
#define TILEMAP_H

#include <string>
#include <vector>
#include "SDL2/SDL.h"
#include "TileSet.h"

using namespace std;

class TileMap {
	public:
		TileMap(string file, TileSet * tileSet);

		void Load(string file);
		void SetTileSet(TileSet * tileSet);
		void Render(int cameraX = 0, int cameraY = 0);
		void RenderLayer(int layer, int cameraX = 0, int cameraY = 0);
		int & At(int x, int y, int z = 0);
		int GetWidth();
		int GetHeight();
		int GetDepth();

	private:
		vector<int> tileMatrix;
		TileSet * tileSet;
		int mapWidth;
		int mapHeight;
		int mapDepth;
};

#endif