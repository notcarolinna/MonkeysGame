## Monkey Simulation
This project aims to simulate a game involving monkeys and coconuts. It reads information .txt files, each containing details about the initial setup of a game round. The files follow a specific format, ensuring proper data parsing.
Each file begins with the number of rounds to simulate. Then, for each monkey, there are instructions on whom to pass coconuts based on whether the round number is even or odd. Monkeys are identified by numbers, starting from 0. 
Following this, the initial number of coconuts for each monkey is provided, along with the number of stones in each coconut.

### Compilation
To compile the project, it is necessary to have g++ installed and compile using the following command line in the terminal:

```
g++ Data.cpp Reader.cpp University.cpp -o University
./University
```

### Operation

#### Macaquinho 

- Represents a monkey in the game.
- Attributes:
  - macacoVencedor: ID of the winning monkey.
  - macacoImpar: ID of the monkey to whom the current monkey sends coconuts during odd rounds.
  - macacoPar: ID of the monkey to whom the current monkey sends coconuts during even rounds.
  - cocosImpar: Number of coconuts to be sent during odd rounds.
  - cocosPar: Number of coconuts to be sent during even rounds.
- Methods:
  - getMacacoVencedor(): Returns the ID of the winning monkey.
  - getMacacoImpar(): Returns the ID of the monkey to whom coconuts are sent during odd rounds.
  - getMacacoPar(): Returns the ID of the monkey to whom coconuts are sent during even rounds.
  - addCocosImpares(int Cocos): Adds coconuts to be sent during odd rounds.
  - addCocosPares(int Cocos): Adds coconuts to be sent during even rounds.
  - getCocos(): Returns the total number of coconuts.
  - getCocosImpar(): Returns the number of coconuts to be sent during odd rounds.
  - getCocosPar(): Returns the number of coconuts to be sent during even rounds.

 ### Partida
- Manages the game rounds and determines the winner.
- Constructor:
  - Partida(Macaquinho** macaquinhos, Reader reader): Initializes a game with the provided monkeys and reader object.
- Methods:
  - Vencedor(): Determines the winner of the game.
  - IniciarPartida(): Starts the game by executing the specified number of rounds.

### Reader
- Reads input data from text files and initializes the game.
- Constructor:
  - Reader(std::string arquivo): Initializes the reader with the provided file name.
- Methods:
  - Dados(): Reads and parses data from the input file.
  - getRodadas(): Returns the number of rounds to be played.
  - getMacaquinhos(): Returns an array of pointers to monkeys.
  - getTotalMacaquinhos(): Returns the total number of monkeys.

### Main Function 
Executes the game simulation for multiple cases specified by input files. It measures the execution time for each case and outputs the winner of each game round.
