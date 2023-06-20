#include <iostream>
#include <fstream>
#include <limits.h>

#include "../config.hpp"
#include "../state/state.hpp"
#include "../policy/submission.hpp"


State* root;

/**
 * @brief Read the board from the file
 * 
 * @param fin 
 */
void read_board(std::ifstream& fin) {
  Board board;
  int player;
  fin >> player;

  for (int pl=0; pl<2; pl++) {
    for (int i=0; i<BOARD_H; i++) {
      for (int j=0; j<BOARD_W; j++) {
        int c; fin >> c;
        // std::cout << c << " ";
        board.board[pl][i][j] = c;
      }
      // std::cout << std::endl;
    }
  }
  root = new State(board, player);
  root->get_legal_actions();
}


/**
 * @brief choose a move and then write it into output file
 * 
 * @param fout 
 */
void write_valid_spot(std::ofstream& fout) {
  // Keep updating the output until getting killed.
  Submission a;
  a.highest_value = INT_MIN;

  if(!root->legal_actions.size())
      root->get_legal_actions();

  int depth = 4;

  //while(true) {
    // Choose a random spot.

    for (auto m : root->legal_actions){
      //auto move = root->legal_actions[(rand()+depth)%(root->legal_actions).size()];
      auto move = Submission::get_move(root, m, depth, a);
      fout << move.first.first << " " << move.first.second << " "\
          << move.second.first << " " << move.second.second << std::endl;
    
      fout.flush();
    }

    //depth++;
  //}

}


/**
 * @brief Main function for player
 * 
 * @param argv 
 * @return int 
 */
int main(int, char** argv) {
  srand(RANDOM_SEED);
  std::ifstream fin(argv[1]);
  std::ofstream fout(argv[2]);

  read_board(fin);
  write_valid_spot(fout);

  fin.close();
  fout.close();
  return 0;
}
