#ifndef TILE_H
#define TILE_H

#include <iostream>

using namespace std;

class Tile
{
public:
  char tile_char = 'O';

public:
  virtual bool try_walk()
  {
    return false;
  }

  virtual bool is_start()
  {
    return false;
  }

  virtual bool is_end()
  {
    return false;
  }
};

class WallTile : public Tile
{
  // implement this class
  public:
  WallTile(){tile_char = 'W';}
};

class EmptyTile : public Tile
{
  // implement this class
  public:
  bool try_walk(){return true;}
  EmptyTile(){tile_char = 'X';}
};

class StartingTile : public EmptyTile
{
  // implement this class
  public:
  bool is_start(){return true;}
  StartingTile(){tile_char = 'S';}
};

class EndingTile : public EmptyTile
{
  // implement this class
public:
  bool is_end(){return true;}
  EndingTile(){tile_char = 'E';}
};

ostream & operator << (ostream &out, const Tile &t);
istream & operator >> (istream &in,  Tile *&t);

#endif
