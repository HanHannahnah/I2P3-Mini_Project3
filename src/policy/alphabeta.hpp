#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Alphabeta{
public:
  Move best_move;
  int highest_value;
  int vis[];
  static Move get_move(State *state, int depth, Alphabeta a);
  int alphabeta(State& state, int depth, int alpha, int beta, bool maximizingPlayer);
};