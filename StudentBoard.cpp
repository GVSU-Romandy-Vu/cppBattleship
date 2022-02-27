#include "Board.hpp"
#include "BoardValues.hpp"
#include <algorithm>
#include <iostream>


//keyword "new" always returns a pointer (dynamically created)
//symbol "::" signifies where function is defined
//DO NOT CREATE A REFERENCE INSIDE A FUNCTION

Board::Board(){
    grid = new int[WIDTH * HEIGHT];
    visible = false;
}

Board::Board(const Board& other){

    
    this->visible = other.visible;

    this->grid = new int[WIDTH * HEIGHT];

    for (int i = 0; i < HEIGHT; i++){
        for (int j = 0; j < WIDTH; j++){
            this->grid[(i * 10) + j] = other.grid[(i * 10) + j];
        }
    }

}

/**Set the reference/memory address of this board to "other board"
 * and return that reference.
 * Other is constant, so we can't swap it. */
Board& Board::operator=(const Board& other){

    this->visible = other.visible;

    /*Might not work
    this->grid = other.grid;
    return *this; */
    for(int i = 0; i < WIDTH * HEIGHT; i++){
    	grid[i] = other.grid[i];
    }
	    
   return *this;

}

Board::~Board(){
    delete grid;
}

void Board::setVisible(bool v){
    this->visible = v;
}
/*Return the reference of an int from the index operation.
AKA: Internal[][] */

int& Board::Internal::operator[](int index){
    if(index >= WIDTH){
        throw std::out_of_range(std::to_string(index) + " is greater than or equal to width of " + std::to_string(WIDTH));
    }
    return _grid[index];
}

/*No known return type.
Internal[]
*/

Board::Internal Board::operator[](int index){
    if(index >= HEIGHT){
        throw std::out_of_range(std::to_string(index) + " is greater than or equal to grid height of " + std::to_string(HEIGHT));
    }
        return Board::Internal(grid+(index * WIDTH));
    
    
    /*First: Defined in Board class. Second: Defined in Internal class
    Board x = Board();
    x[0][1];
    x[0];
    x[0][1][2];
    */
}

/**Print out the board data*/

std::ostream& operator<<(std::ostream& os, Board const& b){
    char ch;
    Board data = b;

    for (int row = 0; row < HEIGHT; row++){
        std::cout<<"\t"<<row;
    }
    std::cout<<std::endl;

    std::cout<<"\t---------------------------------------------------------------------------------"<<std::endl;
    for (int row = 0; row < HEIGHT; row++){
        
        std::cout<<row<<"|\t";
        
        for (int col = 0; col < WIDTH; col++){
            ch = data[row][col];
            if(!data.visible && (ch == CARRIER || ch == BATTLESHIP || ch == DESTROYER || ch == SUBMARINE || ch == PATROLBOAT)){
                //ch = EMPTY;
            }
            std::cout<<ch<<"\t";
        }

        std::cout<<std::endl;

    }
    
    return os;
}

int Board::count() const{
    Board data = *this;
    int hits = 0;
    
    for(int row = 0; row < WIDTH; row++){
        for(int col = 0; col < HEIGHT; col++){
            if(data[row][col] == HIT){
                hits++;
            }
        }
    }

    return hits;
    
}

bool Board::operator< (const Board& other){
    return this->count() < other.count(); 
}
