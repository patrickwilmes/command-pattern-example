#include <iostream>
#include <vector>

class MoveCommand {
public:
    MoveCommand(int x, int y): x(x), y(y) {}

    [[nodiscard]] int get_x() const {
        return x;
    }

    [[nodiscard]] int get_y() const {
        return y;
    }

private:
    int x;
    int y;
};

class Entity {
public:
    Entity(int x, int y): current_x(x), current_y(y) {}

    void move(MoveCommand move_command) {
        move_commands.push_back(move_command);
        move_to(move_command.get_x(), move_command.get_y());
        tell();
    }

    void revert_last() {
        move_commands.pop_back();
        MoveCommand last_move = move_commands.back();
        move_to(last_move.get_x(), last_move.get_y());
        tell();
    }

private:
    void move_to(int x, int y) {
        current_x = x;
        current_y = y;
    }
    void tell() const {
        std::cout << "I am at " << current_x << ", " << current_y << "\n" << std::flush;
    }
private:
    std::vector<MoveCommand> move_commands{};
    int current_x;
    int current_y;
};

class Game {
public:
    void play_game() {
        Entity entity(0, 0);
        entity.move(MoveCommand(1, 1));
        entity.move(MoveCommand(2, 2));
        entity.revert_last();
    }
};

int main() {
    Game game;
    game.play_game();
    return 0;
}
