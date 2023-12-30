#include "destroy.h"

void destroy(GameValue *game_value, int ball_number) {
    WIN->~RenderWindow();
}
