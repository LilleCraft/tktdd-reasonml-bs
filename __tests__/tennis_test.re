open Jest;

open Expect;

open Tennis;

describe("Test Tooling", () =>
  test("Given a Player 1 the other player is Player 2", () =>
    expect(other_player(PlayerOne) |> string_of_player) |> toEqual("Player 2")
  )
);

describe("Test Game transitions", () => {
  test("Given deuce when player wins then score is correct", () =>
    expect(score_when_deuce(PlayerOne) |> string_of_score)
    |> toEqual("Advantage Player 1")
  );
  test(
    "Given advantage when advantaged player wins then score is Game to the advantaged player",
    () => {
      let advantagedPlayer = PlayerOne;
      let winner = advantagedPlayer;
      expect(score_when_advantage(advantagedPlayer, winner) |> string_of_score)
      |> toEqual("Game Player 1");
    }
  );
  test("Given advantage when the other player wins then score is Deuce", () => {
    let advantagedPlayer = PlayerOne;
    let winner = other_player(advantagedPlayer);
    expect(score_when_advantage(advantagedPlayer, winner) |> string_of_score)
    |> toEqual("Deuce");
  });
  /* Tests bellow need more conception on types to be implemented */
  test(
    "Given player: 40 when player at 40 wins then score is Game for this player",
    () =>
    expect(false) |> toEqual(true)
  );
  test("Given player: 40 | other : 30 when other wins then score is Deuce", () =>
    expect(false) |> toEqual(true)
  );
  test("Given player: 40 | other : 15 when other wins then score is 40/15", () =>
    expect(false) |> toEqual(true)
  );
  test(
    "Given player: 15 | other : 15 when player wins then score is 30/15", () =>
    expect(false) |> toEqual(true)
  );
  test("Given player: 0  | other : 15 when other wins then score is 0/30", () =>
    expect(false) |> toEqual(true)
  );
  test(
    "Given player: 30 | other : 15 when player wins then score is 40/15", () =>
    expect(false) |> toEqual(true)
  );
});