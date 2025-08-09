#include "betGamObj.h"
#include "Menu.h"

auto main() -> int
{
    std::srand(static_cast<unsigned>(time(NULL)));

    auto game = betGamObj();

    game.run(); 

}
