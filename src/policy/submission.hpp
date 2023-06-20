#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for random policy, 
 * your policy class should have get_move method
 */
class Submission{
public:
  Move best_move;
  int highest_value;
  int vis[];
  static Move get_move(State *state, Move m, int depth, Submission a);
  int submission(State& state, int depth, int alpha, int beta, bool maximizingPlayer);
};