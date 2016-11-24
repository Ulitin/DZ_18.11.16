#include "header.h"

void go_step(int **world, int x1, int x2, int size_world, int i){
	if (world[x1][x2] == i) {
		if (x1 >= 1) {
			if (((world[x1 - 1][x2] + 1) > i) || (world[x1 - 1][x2] == 0)) {
				world[x1 - 1][x2] = i + 1;
			}
		}
		if (x1 < (size_world - 1)) {
			if (((world[x1 + 1][x2] + 1) > i) || (world[x1 + 1][x2] == 0)) {
				world[x1 + 1][x2] = i + 1;
			}
		}
		if (x2 >= 1) {
			if (((world[x1][x2 - 1] + 1) >= i) || (world[x1][x2 - 1] == 0)) {
				world[x1][x2 - 1] = i + 1;
			}
		}
		if (x2 < (size_world - 1)) {
			if (((world[x1][x2 + 1] + 1)>= 1) || (world[x1][x2 + 1] == 1)) {
				world[x1][x2 + 1] = i + 1;
		}
		}
	}
}

int control_road(int **world, int x1, int x2, int size_world){
	if (x1 >= 1) {
		if (world[x1 - 1][x2] >= 1) {
			return world[x1 - 1][x2];
		}
	}
	if(x1 < (size_world - 1)){
		if (world[x1 + 1][x2] >= 1) {
			return world[x1 + 1][x2];
		}
	}
	if (x2 >= 1) {
		if (world[x1][x2 - 1] >= 1) {
			return world[x1][x2 - 1];
		}
	}
	if (x2 < (size_world - 1)) {
		if (world[x1][x2 + 1] >= 1) {
			return world[x1][x2 + 1];
		}
	}
	return 0;
}

int wave(int **world, int size_world, int x1, int x2, int y1, int y2){
	int long_road = 0, q = 1;
	bool flag = true;
	world[y1][y2] = 1;
	while ((long_road == 0) && (flag == true)) {
		for (int i = 0; i < size_world; i++) {
			for (int j = 0; j < size_world; j++) {
				if (world[i][j] >= 1) {
					go_step(world, i, j, size_world ,q);
				}
			}
		}
		q++;
		long_road = control_road(world, x1, x2, size_world);
	}
	return long_road - 1;
}

void copy_mas(int **copy_mas, int **mas, int size_mas){
	for (int i = 0; i < size_mas; i++) {
		for(int j = 0; j < size_mas; j++){
			copy_mas[i][j] = mas[i][j];
		}
	}
}

int find_road(int **world, int size_world, int x1, int x2, int y1, int y2) {
	if ((world == 0) || (size_world <= 0) || (x1 < 0) || (x2 < 0) || (x1 >= size_world) || (x2 >= size_world) || (y1 < 0) || (y2 < 0) || (y1 >= size_world) || (y2 >= size_world)) {
		throw 1;
	}
	if ((x1 == y1) && (x2 == y2)){
		return 0;
	}
	int **copy_world;
	int long_road;
	copy_world = new int *[size_world];
	for (int i = 0; i < size_world; i++) {
		copy_world[i] = new int [size_world];
	}
	copy_mas(copy_world, world, size_world);
	long_road = wave(copy_world, size_world, x1, x2, y1, y2);
	return long_road;
}



