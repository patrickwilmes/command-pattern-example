# Command Pattern Example

This repository contains an example of the Command Pattern in C++.
We have 2 actors in this example:
1. The game instance controlling the whole flow
2. The Entity able to move around

In order to control where the entity goes, we use a MoveCommand. This class simply
encapsulates the new coordinates of the entity. The game instance creates those move
commands and passes them to the entity. The entity then executes the command and
moves to the new coordinates.

In this example, executes the command directly. But it's also valid to queue up the commands
and apply many at a time. The only important thing to keep in mind, is to keep the order of
the commands.

The example also shows one of the huge benefits of the command pattern: Undoing commands. Here
we can revert our last move, which brings the entity back to the previous location.
