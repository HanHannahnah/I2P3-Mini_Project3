#include <iostream>
#include <sstream>
#include <cstdint>

#include "./state.hpp"
#include "../config.hpp"

#define King 9000
#define Queen 900
#define Rook 500
#define Bishop 300
#define Knight 300
#define Pawn 100

//White
const int wKingTable[6][5] = {
    -30,-40,-50,-40,-30,
    -30,-40,-50,-40,-30,
    -20,-30,-40,-30,-20,
    -10,-20,-20,-20,-10,
     20,  0,  0,  0, 20,
     20, 20,  0, 20, 20
};
const int wQueenTable[6][5] = {
    -20,-10, -5,-10,-20,
    -10,  0,  0,  0,-10,
    -10,  0,  5,  0,-10,
      0,  5,  5,  0, -5,
    -10,  5,  5,  0,-10,
    -20,-10, -5,-10,-20
};
const int wRookTable[6][5] = {
      0,  0,  0,  0,  0,
      5, 10, 10, 10,  5,
     -5,  0,  0,  0, -5,
     -5,  0,  0,  0, -5,
     -5,  0,  0,  0, -5,
      0,  0,  5,  0,  0
};
const int wBishopTable[6][5] = {
    -20,-10,-10,-10,-20,
    -10,  0,  0,  0,-10,
    -10,  5, 10,  5,-10,
    -10, 10, 10, 10,-10,
    -10,  5,  0,  5,-10,
    -20,-10,-10,-10,-20
};
const int wKnightTable[6][5] = {
    -50,-40,-30,-40,-50,
    -30,  5, 15,  5,-30,
    -30, 10, 20, 10,-30,
    -30,  5, 15,  5,-30,
    -40,  0,  5,  0,-40,
    -50,-40,-30,-40,-50
};
const int wPawnTable[6][5] = {
     0,  0,  0,  0,  0,
    50, 50, 50, 50, 50,
    10, 20, 30, 20, 10,
     5, -5,  0, -5,  5,
     5, 10,-20, 10,  5,
     0,  0,  0,  0,  0
};

// Black
const int bKingTable[6][5] = {
     20, 30,  0, 30, 20,
    -10,-20,-20,-20,-10,
    -20,-30,-40,-30,-20,
    -30,-40,-50,-40,-30,
    -30,-40,-50,-40,-30,
    -30,-40,-50,-40,-30
};
const int bQueenTable[6][5] = {
    -20,-10, -5,-10,-20,
    -10,  0,  0,  0,-10,
      0,  0,  5,  0, -5,
    -10,  5,  5,  0,-10,
    -10,  0,  5,  0,-10,
    -20,-10, -5,-10,-20
};
const int bRookTable[6][5] = {
      0,  0,  5,  0,  0,
     -5,  0,  0,  0, -5,
     -5,  0,  0,  0, -5,
     -5,  0,  0,  0, -5,
      5, 10, 10, 10,  5,
      0,  0,  0,  0,  0
};
const int bBishopTable[6][5] = {
    -20,-10,-10,-10,-20,
    -10,  5,  0,  5,-10,
    -10, 10, 10, 10,-10,
    -10,  5, 10,  5,-10,
    -10,  0,  0,  0,-10,
    -20,-10,-10,-10,-20
};
const int bKnightTable[6][5] = {
    -50,-40,-30,-40,-50,
    -40,-20,  5,-20,-40,
    -30,  5, 15,  5,-30,
    -30, 10, 15, 10,-30,
    -40,-20,  0,-20,-40,
    -50,-40,-30,-40,-50
};
const int bPawnTable[6][5] = {
      0,  0,  0,  0,  0,
      5, 10,-20, 10,  5,
      5, 10, 25, 10,  5,
     10, 20, 30, 20, 10,
     50, 50, 50, 50, 50,
      0,  0,  0,  0,  0
};

/**
 * @brief evaluate the state
 * 
 * @return int 
 */
int State::evaluate(){
  // [TODO] design your own evaluation function
  
  int white_pt = 0;
  int black_pt = 0;
  int score;

  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 5; j++){
        if (board.board[0][i][j] == 1){
          white_pt += Pawn;
          white_pt += wPawnTable[i][j];
        }
        else if (board.board[0][i][j] == 2){
          white_pt += Rook;
          white_pt += wRookTable[i][j];
        }
        else if (board.board[0][i][j] == 3){
          white_pt += Knight;
          white_pt += wKnightTable[i][j];
        }
        else if (board.board[0][i][j] == 4){
          white_pt += Bishop;
          white_pt += wBishopTable[i][j];
        }
        else if (board.board[0][i][j] == 5){
          white_pt += Queen;
          white_pt += wQueenTable[i][j];
        }
        else if (board.board[0][i][j] == 6){
          white_pt += King;
          white_pt += wKingTable[i][j];
        }
    }
  }

  for (int i = 0; i < 6; i++){
    for (int j = 0; j < 5; j++){
        if (board.board[1][i][j] == 1){
          black_pt += Pawn;
          black_pt += bPawnTable[i][j];
        }
        else if (board.board[1][i][j] == 2){
          black_pt += Rook;
          black_pt += bRookTable[i][j];
        }
        else if (board.board[1][i][j] == 3){
          black_pt += Knight;
          black_pt += bKnightTable[i][j];
        }
        else if (board.board[1][i][j] == 4){
          black_pt += Bishop;
          black_pt += bBishopTable[i][j];
        }
        else if (board.board[1][i][j] == 5){
          black_pt += Queen;
          black_pt += bQueenTable[i][j];
        }
        else if (board.board[1][i][j] == 6){
          black_pt += King;
          black_pt += bKingTable[i][j];
        }
    }
  }


  if (player == 1)
    score = black_pt - white_pt;
  else 
    score = white_pt - black_pt;

  return score;
  
}


/**
 * @brief return next state after the move
 * 
 * @param move 
 * @return State* 
 */
State* State::next_state(Move move){
  Board next = this->board;
  Point from = move.first, to = move.second;
  
  int8_t moved = next.board[this->player][from.first][from.second];
  //promotion for pawn
  if(moved == 1 && (to.first==BOARD_H-1 || to.first==0)){
    moved = 5;
  }
  if(next.board[1-this->player][to.first][to.second]){
    next.board[1-this->player][to.first][to.second] = 0;
  }
  
  next.board[this->player][from.first][from.second] = 0;
  next.board[this->player][to.first][to.second] = moved;
  
  State* next_state = new State(next, 1-this->player);
  
  if(this->game_state != WIN)
    next_state->get_legal_actions();
  return next_state;
}


static const int move_table_rook_bishop[8][7][2] = {
  {{0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}},
  {{0, -1}, {0, -2}, {0, -3}, {0, -4}, {0, -5}, {0, -6}, {0, -7}},
  {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}},
  {{-1, 0}, {-2, 0}, {-3, 0}, {-4, 0}, {-5, 0}, {-6, 0}, {-7, 0}},
  {{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}, {6, 6}, {7, 7}},
  {{1, -1}, {2, -2}, {3, -3}, {4, -4}, {5, -5}, {6, -6}, {7, -7}},
  {{-1, 1}, {-2, 2}, {-3, 3}, {-4, 4}, {-5, 5}, {-6, 6}, {-7, 7}},
  {{-1, -1}, {-2, -2}, {-3, -3}, {-4, -4}, {-5, -5}, {-6, -6}, {-7, -7}},
};
static const int move_table_knight[8][2] = {
  {1, 2}, {1, -2},
  {-1, 2}, {-1, -2},
  {2, 1}, {2, -1},
  {-2, 1}, {-2, -1},
};
static const int move_table_king[8][2] = {
  {1, 0}, {0, 1}, {-1, 0}, {0, -1}, 
  {1, 1}, {1, -1}, {-1, 1}, {-1, -1},
};


/**
 * @brief get all legal actions of now state
 * 
 */
void State::get_legal_actions(){
  // [Optional]
  // This method is not very efficient
  // You can redesign it
  this->game_state = NONE;
  std::vector<Move> all_actions;
  auto self_board = this->board.board[this->player];
  auto oppn_board = this->board.board[1 - this->player];
  
  int now_piece, oppn_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece=self_board[i][j])){
        // std::cout << this->player << "," << now_piece << ' ';
        switch (now_piece){
          case 1: //pawn
            if(this->player && i<BOARD_H-1){
              //black
              if(!oppn_board[i+1][j] && !self_board[i+1][j])
                all_actions.push_back(Move(Point(i, j), Point(i+1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i+1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i+1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i+1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }else if(!this->player && i>0){
              //white
              if(!oppn_board[i-1][j] && !self_board[i-1][j])
                all_actions.push_back(Move(Point(i, j), Point(i-1, j)));
              if(j<BOARD_W-1 && (oppn_piece=oppn_board[i-1][j+1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j+1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
              if(j>0 && (oppn_piece=oppn_board[i-1][j-1])>0){
                all_actions.push_back(Move(Point(i, j), Point(i-1, j-1)));
                if(oppn_piece==6){
                  this->game_state = WIN;
                  this->legal_actions = all_actions;
                  return;
                }
              }
            }
            break;
          
          case 2: //rook
          case 4: //bishop
          case 5: //queen
            int st, end;
            switch (now_piece){
              case 2: st=0; end=4; break; //rook
              case 4: st=4; end=8; break; //bishop
              case 5: st=0; end=8; break; //queen
              default: st=0; end=-1;
            }
            for(int part=st; part<end; part+=1){
              auto move_list = move_table_rook_bishop[part];
              for(int k=0; k<std::max(BOARD_H, BOARD_W); k+=1){
                int p[2] = {move_list[k][0] + i, move_list[k][1] + j};
                
                if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) break;
                now_piece = self_board[p[0]][p[1]];
                if(now_piece) break;
                
                all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));
                
                oppn_piece = oppn_board[p[0]][p[1]];
                if(oppn_piece){
                  if(oppn_piece==6){
                    this->game_state = WIN;
                    this->legal_actions = all_actions;
                    return;
                  }else
                    break;
                };
              }
            }
            break;
          
          case 3: //knight
            for(auto move: move_table_knight){
              int x = move[0] + i;
              int y = move[1] + j;
              
              if(x>=BOARD_H || x<0 || y>=BOARD_W || y<0) continue;
              now_piece = self_board[x][y];
              if(now_piece) continue;
              all_actions.push_back(Move(Point(i, j), Point(x, y)));
              
              oppn_piece = oppn_board[x][y];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;
          
          case 6: //king
            for(auto move: move_table_king){
              int p[2] = {move[0] + i, move[1] + j};
              
              if(p[0]>=BOARD_H || p[0]<0 || p[1]>=BOARD_W || p[1]<0) continue;
              now_piece = self_board[p[0]][p[1]];
              if(now_piece) continue;
              
              all_actions.push_back(Move(Point(i, j), Point(p[0], p[1])));
              
              oppn_piece = oppn_board[p[0]][p[1]];
              if(oppn_piece==6){
                this->game_state = WIN;
                this->legal_actions = all_actions;
                return;
              }
            }
            break;
        }
      }
    }
  }
  std::cout << "\n";
  this->legal_actions = all_actions;
}


const char piece_table[2][7][5] = {
  {" ", "♙", "♖", "♘", "♗", "♕", "♔"},
  {" ", "♟", "♜", "♞", "♝", "♛", "♚"}
};
/**
 * @brief encode the output for command line output
 * 
 * @return std::string 
 */
std::string State::encode_output(){
  std::stringstream ss;
  int now_piece;
  for(int i=0; i<BOARD_H; i+=1){
    for(int j=0; j<BOARD_W; j+=1){
      if((now_piece = this->board.board[0][i][j])){
        ss << std::string(piece_table[0][now_piece]);
      }else if((now_piece = this->board.board[1][i][j])){
        ss << std::string(piece_table[1][now_piece]);
      }else{
        ss << " ";
      }
      ss << " ";
    }
    ss << "\n";
  }
  return ss.str();
}


/**
 * @brief encode the state to the format for player
 * 
 * @return std::string 
 */
std::string State::encode_state(){
  std::stringstream ss;
  ss << this->player;
  ss << "\n";
  for(int pl=0; pl<2; pl+=1){
    for(int i=0; i<BOARD_H; i+=1){
      for(int j=0; j<BOARD_W; j+=1){
        ss << int(this->board.board[pl][i][j]);
        ss << " ";
      }
      ss << "\n";
    }
    ss << "\n";
  }
  return ss.str();
}