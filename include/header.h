int find_road(int **world, int size_world, int x1, int x2, int y1, int y2);


/*
int fun_right(int **a, int *pointer, int m, int n, int** road ) {
	if( ((*pointer)+1) <= m) {
		if(a[*pointer, *(pointer+1)] != 0) {
			pointer[1] ++;
			**road = pointer[0];
			*((*road)+1) = pointer[1];
			return 0;
		}
		else
			return 1;
	}
	return 2;
}

int fun_left(int **a, int *pointer, int m, int n, int** road ) {
	if( ((*pointer)-1) <= m) {
		if(a[*pointer, *(pointer-1)] != 0) {
			pointer[1] --;
			**road = pointer[0];
			*((*road)+1) = pointer[1];
			return 0;
		}
		else
			return 1;
	}
	return 2;
}

int fun_down(int **a, int *pointer, int m, int n, int** road ) {
	if( (*(pointer+1)+1) <= n) {
		if(a[*(pointer+1), *pointer] != 0) {
			pointer[0] ++;
			**road = pointer[0];
			*((*road)+1) = pointer[1];
			return 0;
		}
		else
			return 1;
	}
	return 2;
}

int fun_up(int **a, int *pointer, int m, int n, int** road ) {
	if( (*(pointer+1)-1) >= n) {
		if(a[*(pointer-1), *pointer] != 0) {
			pointer[0] --;
			**road = pointer[0];
			*((*road)+1) = pointer[1];
			return 0;
		}
		else
			return 1;
	}
	return 2;
}



int** fun(int **a, int *x, int *y, int m, int n) {
	//поверить что x и y не одна и таже точка, проверка на нольб на коректность введёных данных
	int **road;
	int len=0;
	road = new int* [2];
	road[0] = new int [n*m];
	road[1] = new int [n*m];

	int* pointer;
	*pointer = *x; 
	*(pointer+1) = *(x+1);

	for(int i=0; i< (m*n); i++) {
		road[1,i]=0;
		road[2,i]=0;
	}

	if((*x+*(x+1))>(*y+*(y+1))) {
		int* box;
		box = x;
		x = y;
		y = box;
	}

	int right, down;
	int i = 0, j =0;
	while( (i == 0) && (j == 0)) {
		if(*pointer > *y) {
			i = fun_down(a, pointer, m, n, (road+2*len));
			len ++;
		}
		if(*(pointer+1) > *(y+1)) {
			i = fun_right(a, pointer, m, n, (road+2*len));
			len++;
		}
	}
	return road;
}*/
