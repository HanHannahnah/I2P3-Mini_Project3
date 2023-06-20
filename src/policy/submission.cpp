#include <cstdlib>
#include <limits.h>
using namespace std;

#include "../state/state.hpp"
#include "./submission.hpp"


/**
 * @brief get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Submission::get_move(State *state, Move m, int depth, Submission a){

    State* s = state->next_state(m);
    int temp = a.submission(*s, depth , INT_MIN, INT_MAX, false);

    if (temp >= a.highest_value){
        a.best_move = m;
        a.highest_value = temp;
    }

    return a.best_move;
}

int Submission::submission(State& state, int depth, int alpha, int beta, bool maximizingPlayer){

    if (depth == 0 || state.legal_actions.size() == 0)
        return state.evaluate();

    if (maximizingPlayer){
        int value = INT_MIN;

        for (auto next_action : state.legal_actions){
            State* s = state.next_state(next_action);
            value = max(value, submission(*s, depth - 1, alpha, beta, false));

            alpha = max(alpha, value);
            if (alpha >= beta)
                break;
        }

        return alpha;
    }
    else {
        int value = INT_MAX;

        for (auto next_action : state.legal_actions){
            State* s = state.next_state(next_action);
            value = min(value, submission(*s, depth - 1, alpha, beta, true));
        
            beta = min(beta, value);
            if (beta <= alpha)
                break;
        }

        return beta;
    }

}