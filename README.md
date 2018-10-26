# tktdd-reasonml-bs

TKTDD in [ReasonML](https://reasonml.github.io) + [Buckelscript](https://bucklescript.github.io)

During this kata we will user ReasonML compiled to Javascript thanks to Buckelscript

## First time with ReasonML ?

You should do an [Iteration 0](./docs/zeros.md)

## Tennis

A tennis match consists of multiple sets that again are played as several games, in the kata, you only have to implement the scoring system for a single game:

- Each player can have either of these points in one game: Love, 15, 30, 40.
- If you have 40 and you win the ball, you win the game. There are, however, special rules.
- If both have 40, the players are deuce.
- If the game is in deuce, the winner of a ball will have advantage and game ball.
- If the player with advantage wins the ball, (s)he wins the game.
- If the player without advantage wins, they are back at deuce.

This problem is easy enough that it's fun to play with, but difficult enough that it's fun to play with.
<br/>(∩ ｀-´)⊃━☆ﾟ.\*･｡ﾟ

### Setup

clone this repository and run

```sh
npm i
```

You may need a [plugin for your editor](https://reasonml.github.io/docs/en/editor-plugins)

### Players

In tennis, there are two players, which we can easily model with a discriminated union (a variant) :

```OCaml
type player =
  | PlayerOne
  | PlayerTwo;
```

### Winning the game

#### Advantage

When one of the players have the advantage in tennis, the result can go one of two ways: either the player with the advantage wins the ball, in which case he or she wins the game, or the other player wins, in which case the next score is deuce.

#### Forty

When one of the players have forty points, there are three possible outcomes of the next ball:

- If the player with forty points wins the ball, (s)he wins the game.
- If the other player has thirty points, and wins the ball, the score is deuce.
- If the other player has less than thirty points, and wins the ball, his or her points increases to the next level (from love to fifteen, or from fifteen to thirty).

### Challenge

You get some tests in `__tests__/tennis_test.re` folder which should serve you as a specification of what you can code.
This Kata will consist in several iterations.
At the end of each iteration you score the number of green tests ! (•̀ᴗ•́)و
Between iterations you will the animator will give you some clues to improve the safety and confidence in your code.

#### Next iterations

Your are free to cheat ... But you shouldn't do it if you really whant to learn something :

- [Before I start the second iteration](./1.md)
- [Before I start the third iteration](2.md)
- [Before I start the forth iteration](./3.md)
- [Before I start the fifth iteration](./4.md)
- [Before I start the sixth iteration](./5.md)
- [Before I start the seventh iteration](./6.md)
- [The Kata was too easy and I have time to kill](./extra.md)
