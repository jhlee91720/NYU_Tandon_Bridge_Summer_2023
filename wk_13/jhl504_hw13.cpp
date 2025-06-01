#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstdio>
using namespace std;


//initial settings----------------------------------------------------------------------//
const int ANT = 100;
const int DOODLEBUG = 5;
enum Move {UP, DOWN, LEFT, RIGHT};

//Organism-------------------------------------------------------------------------------//
class Organism {
   protected:
    int x_position;
    int y_position;
   public:
        Organism (int new_x_position, int new_y_position) {
            x_position = new_x_position;
            y_position = new_y_position;
        }
        int get_x_position () {return x_position;};
        int get_y_position () {return y_position;};
        virtual void move (int move) = 0;
        virtual char get () = 0;
        virtual int get_step () = 0;
};

//Ant------------------------------------------------------------------------------------//
class Ant : public Organism {
    private:
        int step;
    public:
        Ant (int new_x_position, int new_y_position) : Organism (new_x_position, new_y_position) {
            step = 0;
        }
        void move (int move);
        int get_step () {return step;}
        char get () {return 'O';}


};

void Ant :: move (int move){
    switch (move)
	{
	case UP:
		y_position++;
		break;
	case DOWN:
		y_position--;
		break;
	case LEFT:
		x_position--;
		break;
	case RIGHT:
		x_position++;
		break;
	}
	if (step == 3)
	{
		step = 0;
	}
	else
	{
		step++;
	}
	return;
}

//Doodlbug-------------------------------------------------------------------------------//
class Doodlebug : public Organism {
    private:
        int step;
        int starve;
    public:
        Doodlebug (int new_x_position, int new_y_position) : Organism (new_x_position, new_y_position) {
            step = 0;
            starve = 0;
        }
        void move (int move);
        int get_step () {return step;}
        int get_starve () {return starve;}
        char get () {return 'O';}
        void add_starve () {
            starve++;
        }
        void reset_starve (){
            starve = 0;
        }
};

void Doodlebug :: move (int move){
    switch (move)
	{
	case UP:
		y_position++;
		break;
	case DOWN:
		y_position--;
		break;
	case LEFT:
		x_position--;
		break;
	case RIGHT:
		x_position++;
		break;
	}
	if (step == 8)
	{
		step = 0;
	}
	else
	{
		step++;
	}
	return;
}

//Main-----------------------------------------------------------------------------------//
//outputs the game on the console
void display(Organism *arr[]);

//checking what is in the spot (ant, doodle, or empty) when the function is called
int check (Organism* arr[], int x_position, int y_position){
	for (int i = 0; i < 400; i++){
		if (arr[i] != NULL && arr[i] -> get_x_position() == x_position && arr[i] -> get_y_position() == y_position)
			return 1;
	}
	return -1;
}

int main () {
    const int GRID_SIZE = 400;
    Organism* grid[GRID_SIZE] = {0};
    srand(time(0));


    //setting the intial layout with 5 doodlebugs
    for (int i = 0; i < 400; i++){
        int check_curr_row = rand() % 20;
        int check_curr_column = rand() % 20;

        if (check(grid, check_curr_row, check_curr_column) == -1){
            grid[i] = new Doodlebug(check_curr_row, check_curr_column);
        }
        else{
            i--;
        }
    }
    //setting the intial layout with 100 ants 
    for (int i = DOODLEBUG; i < (DOODLEBUG + ANT); i++){
        int check_curr_row = rand() % 20;
        int check_curr_column = rand() % 20;
        if (check(grid, check_curr_row, check_curr_column) == -1)
            grid[i] = new Ant(check_curr_row, check_curr_column);
        else
            i--;
    }


    while (true){
        display(grid);
        getchar();

     //----------------------------------DOODLEBUG MECHANISM----------------------------------//
        //checking the grid one by one...
        for (int i = 0; i < 400; i++){
            //locating a doodlebug...
            if (grid[i] != NULL && grid[i] -> get() == 'X'){ 
                int y_position = grid[i] -> get_y_position();
                int x_position = grid[i] -> get_x_position();
                int temp[4];
                    temp[0] = check(grid, x_position, y_position + 1); //up
                    temp[1] = check(grid, x_position, y_position - 1); //down
                    temp[2] = check(grid, x_position - 1, y_position); //left
                    temp[3] = check(grid, x_position + 1, y_position); //right
                //If there is a doodlbug on a spot and meets an ant,
                //then, its starve time is resetted and the doodlbug moves.
                if (temp[UP] != -1 && grid[temp[UP]] -> get() == 'O'){
                    delete grid[temp[UP]];
                    grid[temp[UP]] = NULL;
                    grid[i] -> move(UP);
                    ((Doodlebug*) grid[i]) -> reset_starve();
                }
                else if (temp[DOWN] != -1 && grid[temp[DOWN]] -> get() == 'O'){
                    delete grid[temp[DOWN]];
                    grid[temp[DOWN]] = NULL;
                    grid[i] -> move(DOWN);
                    ((Doodlebug*) grid[i]) -> reset_starve();
                }
                else if (temp[LEFT] != -1 && grid[temp[LEFT]] -> get() == 'O'){
                    delete grid[temp[LEFT]];
                    grid[temp[LEFT]] = NULL;
                    grid[i] -> move(LEFT);
                    ((Doodlebug*) grid[i]) -> reset_starve();
                }
                else if (temp[RIGHT] != -1 && grid[temp[RIGHT]] -> get() == 'O'){
                    delete grid[temp[RIGHT]];
                    grid[temp[RIGHT]] = NULL;
                    grid[i] -> move(RIGHT);
                    ((Doodlebug*) grid[i]) -> reset_starve();
                }
                //otherwise, the doodlebug moves and starve++
                else {
                    switch (rand() % 4) {
					case LEFT:
						if (x_position != 0 && check(grid, x_position - 1, y_position) == -1)
							grid[i] -> move(LEFT);
						break;
					case RIGHT:
						if (x_position != 19 && check(grid, x_position + 1, y_position) == -1)
							grid[i] -> move(RIGHT);
						break;
					case UP:
						if (y_position != 0 && check(grid, x_position, y_position - 1) == -1)
							grid[i] -> move(UP);
						break;
					case DOWN:
						if (y_position != 19 && check(grid, x_position, y_position + 1) == -1)
							grid[i] -> move(DOWN);
						break;
					}
                    ((Doodlebug*) grid[i]) -> add_starve();
                }
                //if the doodlebug has moved 8 times
                if (grid[i] -> get_step() == 8){
                    int temp = 0;

                    while (grid[temp] != NULL)
                        temp++;
                    
                    //then, the doodlebug breeds a new doodlebug on nearby spot of any four directions
                    //if not, the doodlebug keeps moving
                    if (x_position != 0 && check(grid, x_position - 1, y_position) == -1)
                        grid[temp] = new Doodlebug (x_position - 1, y_position);
                    else if (x_position != 19 && check(grid, x_position + 1, y_position) == -1)
                        grid[temp] = new Doodlebug (x_position + 1, y_position);
                    else if (y_position != 0 && check(grid, x_position, y_position - 1) == -1)
                        grid[temp] = new Doodlebug (x_position, y_position -1);
                    else if (y_position != 19 && check(grid, x_position, y_position + 1) == -1)
                        grid[temp] = new Doodlebug (x_position, y_position + 1);
                }
                // if the doodlebug moves 3 times, it dies and gets removed from the grid.
                if (((Doodlebug*) grid[i]) -> get_starve() == 3) {
                    delete grid [i];
                    grid[i] = NULL;
                }
            }
        }


     //------------------------------------ANT MECHANISM-------------------------------------//
        //checking the grid one by one...
        for (int i = 0; i < 400; i++){
            //locating an ant...
            if (grid[i] != NULL && grid[i] -> get() == 'O'){ 
                int y_position = grid[i] -> get_y_position();
                int x_position = grid[i] -> get_x_position();
                //the ant moves
                switch (rand() % 4){
					case LEFT:
						if (x_position != 0 && check(grid, x_position - 1, y_position) == -1)
							grid[i] -> move(LEFT);
						break;
					case RIGHT:
						if (x_position != 19 && check(grid, x_position + 1, y_position) == -1)
							grid[i] -> move(RIGHT);
						break;
					case UP:
						if (y_position != 0 && check(grid, x_position, y_position - 1) == -1)
							grid[i] -> move(UP);
						break;
					case DOWN:
						if (y_position != 19 && check(grid, x_position, y_position + 1) == -1)
							grid[i] -> move(DOWN);
						break;                    
                }
                //the ant breeds after 3 moves
                if (grid[i] -> get_step() == 3){
                    int temp = 0;

                    while (grid[temp] != NULL)
                        temp++;
                    
                    //then, the ant breeds a new ant on nearby spot of any four directions
                    //if not, the ant keeps moving
                    if (x_position != 0 && check(grid, x_position - 1, y_position) == -1)
                        grid[temp] = new Doodlebug (x_position - 1, y_position);
                    else if (x_position != 19 && check(grid, x_position + 1, y_position) == -1)
                        grid[temp] = new Doodlebug (x_position + 1, y_position);
                    else if (y_position != 0 && check(grid, x_position, y_position - 1) == -1)
                        grid[temp] = new Doodlebug (x_position, y_position -1);
                    else if (y_position != 19 && check(grid, x_position, y_position + 1) == -1)
                        grid[temp] = new Doodlebug (x_position, y_position + 1);
                }
            }
        }
    }
    return 0;
}

void display (Organism* arr[]){
    char grid[20][20] = {0};
    int ant_count = 0, doodle_count = 0;

    for (int i = 0; i < 400; i++){
        if (arr[i] != NULL){
            grid[arr[i] -> get_x_position()][arr[i] -> get_y_position()] = arr[i] -> get();

            if(arr[i] -> get() == 'O'){
                ant_count++;
            }
            else if (arr[i] -> get() == 'X'){
                doodle_count++;
            }
        }
    }

    for (int i = 0; i < 20; i++){
        for (int j = 0; j < 20; j++){
            if(grid[i][j] == 0){
                cout << "-";
            }
            else {
                cout << grid[i][j];
            }
        }
        cout << endl;
    }
    cout << "Ant: " << ant_count << "\t" << "Doodlebug: " << doodle_count << endl;
}