#include "JDM/JDM.hpp"

class GameWindow : public JDM::Window {
public:
    GameWindow()
        : JDM::Window("TEST", {30, 30, 500, 500}) {
    }

private:
    const void initAllObjects() {
    }
    const void update() {
    }
};

int main(int argc, char** argv) {
    std::make_shared<GameWindow>()->run();
    return 0;
}
