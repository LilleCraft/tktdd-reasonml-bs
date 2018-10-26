/* Types */
type player =
  | PlayerOne
  | PlayerTwo;

type point = int; /* surely not the best choice */

type pointsData = {
  playerOne: point,
  playerTwo: point
};

type score =
  /* surely incomplete */
  | Points(pointsData)
  | Deuce
  | Game(player);

/* Type transformation functions */
let string_of_score: score => string = score => "replace this with your code";

let string_of_player = player =>
  switch player {
  | PlayerOne => "Player 1"
  | PlayerTwo => "Player 2"
  };

/* Tooling functions */
let other_player = player =>
  switch player {
  | PlayerOne => PlayerTwo
  | PlayerTwo => PlayerOne
  };

let increment_point: point => option(point) = point => None;

/* Score management functions */
let score_when_deuce: player => score = winner => Deuce;

let score_when_advantage: (player, player) => score =
  (advantagedPlayer, winner) => Deuce;

let score_when_forty: (player, player) => score = (current, winner) => Deuce;

let score_when_game: player => score = winner => Deuce;

let score: (score, player) => score = (currentScore, winner) => Deuce;