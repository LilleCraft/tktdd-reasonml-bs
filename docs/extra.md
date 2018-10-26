# Use tennis API

You beat the Tennis Kata ヾ(⌐♡_♡)ノ ♪♬

And now you want to design a visual couter for a tennis game.

## UI Components with ReasonReact

### Introduction

The Document Object Model (DOM) is a programming interface for HTML, XML and SVG documents. The DOM provides a representation of the document as a structured group of nodes and objects that have properties and methods. Nodes can also have event handlers attached to them, and once that event is triggered the event handlers get executed. Essentially, it connects web pages to scripts or programming languages.

The main idea of react is to compose a web application with components.

The DOM has 2 main problems :

- lack of encapsulation
  - Web components & Angular solution is Shadow DOM
  - React solution is react component
- low performance to alter three nodes
  - React use Virtual DOM : The Virtual DOM is an abstraction of the HTML DOM. It is lightweight and detached from the browser-specific implementation details. Since the DOM itself was already an abstraction, the virtual DOM is, in fact, an abstraction of an abstraction.
  - There are other implementations of virtual DOM (Mithril, Inferno, Vue.js, ...)

### React

[React](https://reactjs.org/) is a declarative, efficient, and flexible JavaScript library for building user interfaces.
React has a few different kinds of components.

This is an exemple of "Stateless components" which is just a function returning JSX :

```js
const myComponent = () => (
  <div className="members-list">
    <h1> A list of members </h1>
    <ul>
      <li>Negan</li>
      <li>Carl</li>
    </ul>
  </div>
);
```

This funny tag syntax is neither a string nor HTML.

It is called [JSX](https://reactjs.org/docs/introducing-jsx.html), and it is a syntax extension to JavaScript. JSX may remind you of a template language, but it comes with the full power of JavaScript.

JSX contains regular HTML tags or other React components.
There are few differences, but you can notice that _class_ property is replace by _className_

React is a UI library, we will consider to generate React component from ReasonML, but remember there are lot of way to use it.

### Reason React

[ReasonReact](https://reasonml.github.io/reason-react/) is a safer, simpler way to build React components, in Reason.

This is a sample of an Hello World component.

```OCaml
module App = {
let component = ReasonReact.statelessComponent("App");

let make = _children => {
    ...component,
    render: (self) =>
      <div>{ReasonReact.stringToElement("hello world")}</div>
  };
};

ReactDOMRe.renderToElementWithId(<App/>,"index");
```

A component in Reason is a module with a let binding which must be named `component` and a a function `make` that return a record with a render function.
This component is a Stateless component which means it cannot have state.

#### Score component

We will create a r[educer component](https://reasonml.github.io/reason-react/docs/en/state-actions-reducer.html)

Edit [./src/score.re](./src/score.re) :

```OCaml
open Tennis;

type action =
  | ScorePlayerOne
  | ScorePlayerTwo
  | NewGame;

type state = {score: score};
let component = ReasonReact.reducerComponent("Score");

let make = (_children) => {
  ...component,
  initialState: () => {score : newGame},
  reducer: (action, state) =>
  switch (action) {
  | ScorePlayerOne => ReasonReact.Update({score:score(state.score, PlayerOne) })
  | ScorePlayerTwo => ReasonReact.Update({score:score(state.score, PlayerTwo) })
  | NewGame => ReasonReact.Update({score : newGame})
  },
  render: (self) => {
    let strScore = string_of_score(self.state.score);
    <div>
        <h1>{ReasonReact.stringToElement(strScore)}</h1>

       ( switch self.state.score {
        | Game(p) => <button onClick=((_)=>self.send(NewGame)) >{ReasonReact.stringToElement("New Game")}</button>
        | _ => (<div>{ReasonReact.stringToElement("Who scored ?")}
                <button onClick=((_)=>self.send(ScorePlayerOne)) >{ReasonReact.stringToElement(" Player 1 ")}</button>
                <button onClick=((_)=>self.send(ScorePlayerTwo)) >{ReasonReact.stringToElement(" Player 2 ")}</button>
                </div>)
        })

    </div>
  }
};
```

Then we will mount it our App in [./src/app.re](./src/app.re)

```OCaml
module App = {
let component = ReasonReact.statelessComponent("App");

let make = _children => {
    ...component,
    render: (self) =>
      <div>{ReasonReact.stringToElement("hello world")}</div>
  };
};

ReactDOMRe.renderToElementWithId(<App/>,"index");
```

## Exercice

- Create a new component that will score the number of Game for each player
- Adapt the project to manage Set :
  - A player win a Set after gaining 6 Game
  - A player must have a minimum advance of 2 Games to win a Set
  - If both player won 6 Game, the player who win the 7th Game, aka "tie-break", win the Set
