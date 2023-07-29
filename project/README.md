
# C-games


## Vedio Demo

https://youtu.be/p-MX1p9-3Xc




# Hi, I'm Ayush desai! 👋


## 🚀 About Me
I'm 19 and I'm a software engineering student at sarvajanik university surat, india.


## Snake game

The player controls a long, thin creature, resembling a snake, which roams around on a bordered plane, picking up food, trying to avoid hitting the edges of the playing area. Each time the snake eats a piece of food, its tail grows longer and score increase by 10 point , making the game increasingly difficult. this game is based on C language.

### Functions

#### 1. Boundry

this function prints the play area of the snake game and also print snake and food using loops. i have used "system("cls");" from conio.h header file to clear screen and print new updated game data.

#### 2. Setup

this function randomly choose the place for food.

#### 3. Input

this fuction detect the input and change the snakes direction accordingly. i have used kbhit() that detects input from keyboard without stoping program (not like scanf()).

#### 4. imp

this function passes the position of the snakes head to the it's next tail(*) using array.

### use

press "W" to move ahed and "A" to go left and "D" to go right and "S" to go down. catch the food and avoid hitting walls.



## Tic Tac Toe

### Functions

#### 1. Demo

to tell user which number to enter for differnt positions.

#### 2. print Board

to print tic tac toe board according to user or computers move.

#### 3. Check empty

to check empty positions in board.

#### 4. Player's move

to show players move according to players input.

#### 5. Computer move

to show computers randomly choosed position.

#### 6. Check winner

to check if player or computer has won the game or not.

#### 7. print winner

to print winners name

### USE

enter the position for your move as shown in demo. then computer will play it's move and coubtinue.....





## Deployment

To deploy this project run

```bash
  make c-games.c
  ./c-games
```


## Lessons Learned

part of a snake game where i have to increase the size of the snake( to make it longer after eating food) was a bit difficult. i got many errors but finally did it using array. i counted the pieces of the snake and stored the first heads x and y posion in array and then passed it to the next piece whene head is updated with new positions of x and y.
## 🔗 Links
[![vedio demo](https://img.shields.io/badge/vedio_demo-000?style=for-the-badge&logo=ko-fi&logoColor=white)](https://youtu.be/p-MX1p9-3Xc)





