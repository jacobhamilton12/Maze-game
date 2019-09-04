#include "Tile.h"

// output a tile character
ostream & operator << (ostream &out, const Tile &t)
{
  out << t.tile_char;
  return out;
}

// *& is a reference to a pointer
// here t is a reference to Tile*
// read in a tile character, and return in t a Tile object
istream & operator >> (istream &in,  Tile *&t)
{
  // implement this function
  char c;
  in >> c;
  
  switch(c){
  	case 'W':
  		
  		
  		t = new WallTile();
  		//t->tile_char = c;
  	  break;
  	case 'E':
  		
  		
  		t = new EndingTile();
  	  break;
  	case 'X':
  		
  		
  		t = new EmptyTile();
  	  break;
  	case 'S':
  		
  		t = new StartingTile();

  	  break;
  }

  return in;
}
