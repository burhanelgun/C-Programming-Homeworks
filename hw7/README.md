Part 1 


While our spy, Ali, runs away from the enemy base after a failed infiltration operation, he is shot by the enemy commander.
Fortunately, he does not die but passes out. After a while, Ali opens his eyes and he figures out that he is in a maze. The
enemy commander gives him a chance to live in one condition – He must exit from the maze to live. Because Ali gives no
damage to the enemy. There is one thing that the commander does not know. You, the tech guy, hacked the CCTV system
of the maze and you will help Ali to escape from the maze.
The maze built from tiles that has three different attributes. These are explained below.
- Distance: Tiles has different road length. The distance value is integer.
- Comfort Level: Some of the tiles are made with stone and some other tiles are made with sand. So, Ali can walk
on the stone tiles easier than sand. The comfortLevel value is integer.
- Danger Level: Some of the tiles are more dangerous from other tiles. The dangerLevel value is integer.
In addition to these attributes, the commander sets up some traps on the maze. If there is a trap on a tile and you pass
through that tile, you will take damage of the value that trap can give. The trapDamage value is integer.
You will calculate and three types of escape route and give them to Ali. These are described below.
- Shortest Path: The route that minimize the total distance value.
- Comfortable Path: The route that minimize the total comfortLevel value.
- Safest Path: The route that minimize the total dangerLevel value.
Beware that Ali is wounded and bleeding. He has a MAX_LIFE and the it decreases over time. The time step in this problem
is a tile. If you move by one tile Ali’s life decreases by one unit.
- Shortest Path: Decreases 4 unit.
- Comfortable Path: Decreases 2 unit.
- Safest Path: Decreases 6 unit.
If Ali caught by a trap, Ali’s life decreases by the amount of traps damage.
