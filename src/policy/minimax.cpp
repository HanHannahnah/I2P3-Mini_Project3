#include <cstdlib>
#include <limits.h>
#include <algorithm>
#include <iostream>
using namespace std;

#include "../state/state.hpp"
#include "./minimax.hpp"


/**
 * @brief get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */
Move Minimax::get_move(State *state, int depth, Minimax a){
    if(!state->legal_actions.size())
        state->get_legal_actions();

    auto actions = state->legal_actions;
    int num = (rand()+100)%actions.size();
    Move action = actions[num];

    while (1){
        if (a.vis[num] == 1){
            num = (rand()+depth)%actions.size();
            action = actions[num];
            continue;
        }
        else{
            a.vis[num] = 1;
            break;
        }
    }

    State* s = state->next_state(action);
    int temp = a.minimax(*s, depth - 1, false);

    if (temp > a.highest_value){
        a.best_move = action;
        a.highest_value = temp;
    }

    return a.best_move;

    /*int value = INT_MIN;
    Move best_move = state->legal_actions[0];
  
    for (Move action : state->legal_actions){
        State* s = state->next_state(action);

        int temp = a.minimax(*s, depth - 1, false);

        if (temp > value){
            value = temp;
            best_move = action;
        }
    }

    return best_move;*/
}

int Minimax::minimax(State& state, int depth, bool maximizingPlayer){

    if (depth == 0 || state.legal_actions.size() == 0)
        return state.evaluate();

    if (maximizingPlayer){
        int value = INT_MIN;

        for (auto next_action : state.legal_actions){
            State* s = state.next_state(next_action);

            value = max(value, minimax(*s, depth - 1, false));
        }

        return value;
    }
    else {
        int value = INT_MAX;

        for (auto next_action : state.legal_actions){
            State* s = state.next_state(next_action);

            value = min(value, minimax(*s, depth - 1, true));
        }

        return value;
    }
}