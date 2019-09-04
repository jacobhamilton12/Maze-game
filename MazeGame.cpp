// implementation of MazeGame functions

#include "MazeGame.h"

MazeGame::MazeGame(string filename)
{
  save_out.open(out_name);
  ifstream in;
  in.open(filename);
  if (!in) {
    cerr << "Wrong maze tiles file: " + filename << endl;
    throw IncorrectFile();
  }
  save_out << "Maze tiles file: " << filename << endl << endl;
  in >> maze;
}

MazeGame::~MazeGame()
{

  save_out.close();
}

void MazeGame::start_game(istream & is)
{
  // implement this function
  for(int r = 0; r <  maze.get_tiles().size(); ++r){
    for(int c = 0; c < maze.get_tiles()[r].size(); ++c){
      if(maze.get_tiles()[r][c]->tile_char == 'S'){
        MazePlayer *mp = new MazePlayer(Position(r,c));
        players.push_back(mp);
      } 
    }

  }
  print_maze();
  update_loop(is);
}

// Important: if you use cout << something
// do the same with save_out << something
// Otherwise, the file output.txt would be incorrect

void MazeGame::update_loop(istream & is)
{
  int pnum = 0; // player's number
      
  for(auto player : players) {
    pnum++;
    // implement code here
    string inp;
    bool b = false;

    while(!b){
      cout << "Player " << pnum << " position : (" << player->get_position().row << "," << player->get_position().col << ")\n";
      save_out << "Player " << pnum << " position : (" << player->get_position().row << "," << player->get_position().col << ")\n";
      cout << "Enter player " << pnum << "\'s number " << player->move_number() << " move: ";
      save_out << "Enter player " << pnum << "\'s number " << player->move_number() << " move: ";
      cin >> inp;
      save_out << inp << "\n";
      if(inp == "up" || inp == "u"){
        if(maze.can_move_to_tile(Position(player->get_position().row -1, player->get_position().col))){
          cout << "Hello\n";
          player->set_position(player->take_turn(inp));
          b = true;
        }
        else{
            cout << "Cant move that way, try again\n";
            save_out << "Cant move that way, try again\n";
          }
      }
      else if(inp == "down" || inp == "d"){
        if(maze.can_move_to_tile(Position(player->get_position().row +1, player->get_position().col))){
          player->set_position(player->take_turn(inp));
          b = true;
        }
        else{
            cout << "Cant move that way, try again\n";
            save_out << "Cant move that way, try again\n";
          }
      }
      else if(inp == "right" || inp == "r"){
          if(maze.can_move_to_tile(Position(player->get_position().row , player->get_position().col +1))){
            player->set_position(player->take_turn(inp));
            b = true;
          }
          else{
            cout << "Cant move that way, try again\n";
            save_out << "Cant move that way, try again\n";
          }
      }
      else if(inp == "left" || inp == "l"){
          if(maze.can_move_to_tile(Position(player->get_position().row , player->get_position().col -1))){
            player->set_position(player->take_turn(inp));
            b = true;
          }
          else{
            cout << "Cant move that way, try again\n";
            save_out << "Cant move that way, try again\n";
          }
      }
      else{
            cout << "Cant move that way, try again\n";
            save_out << "Cant move that way, try again\n";
      }
    }
    
    print_maze();
    if(maze.is_tile_end(player->get_position())){
        cout << "Player " << pnum << " has won!!\n";
        save_out << "Player " << pnum << " has won!!\n";
        return;
    }
  }

  update_loop(is);
}

void MazeGame::print_maze()
{
  vector<string> grid;
  for(auto row : maze.get_tiles()) {
    string tiles = "";
    
    for(auto t : row) {
      tiles += t->tile_char;
    }

    grid.push_back(tiles);
  }

  for(auto player : players)
    grid[player->get_position().row][player->get_position().col] = 'P';

  cout << " ";
  save_out << " ";
  
  for(int i = 0; i < grid[0].size(); i++) {
    cout << i;
    save_out << i;
  }

  cout << endl;
  save_out << endl;
  
  for(int i = 0; i < grid.size(); i++) {
    cout << i << grid[i] << endl;
    save_out << i << grid[i] << endl;
  }
}

