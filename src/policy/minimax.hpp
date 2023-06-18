#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Minimax{
public:
  Move best_move;
  int highest_value;
  int vis[];
  static Move get_move(State *state, int depth, Minimax a);
  int minimax(State& state, int depth, bool maximizingPlayer);
};