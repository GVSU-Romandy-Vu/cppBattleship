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

    for (int i = 0; i < WIDTH; i++){
        for (int j = 0; j < HEIGHT; j++){
            this->grid[(i * 10) + j] = other.grid[(i * 10) + j];
        }
    }
    /*Maybe test this out
    for (int i = 0; i < WIDTH * HEIGHT; i++){
        this->grid[i] = other.grid[i];
    }
    */

}

/**Set the reference/memory address of this board to "other board"
 * and return that reference.
 * Other is constant, so we can't swap it. */
Board& Board::operator=(const Board& other){

    this->visible = other.visible;

    //Might not work
    this->grid = other.grid;
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
    return this->_grid[index];
}

/*No known return type.
Internal[]
*/

Board::Internal Board::operator[](int index){
    int* row_point = &grid[10 * index];
    Internal copy = Internal(row_point);
    //Return type is Internal
    //In the Board class
    return copy;
    
    /*First: Defined in Board class. Second: Defined in Internal class
    Board x = Board();
    x[0][1];
    x[0];
    x[0][1][2];
    */
}

/**Print out the board data*/
std::ostream& operator<<(std::ostream& os, Board const& b){
}

int Board::count() const{
    
}

bool Board::operator< (const Board& other){
}