# reason-basics
A repository for folks learning the Reason programming language.

## Purpose
This repository is a place for newcomers to the Reason community to get to know the very basics of the language through simple examples. Much of what you see here is condensed or modified [from the docs](https://reasonml.github.io/docs/en/overview.html). The docs are an excellent resource and provide a high-level explanation for design decisions behind the language. However, they can feel a little overwhelming for first-time programmers and first-time Reason users. This repo hopes to simplify some of the language and provide very clear, concise examples to get you up and running with Reason. If you find anything confusing, overly complicated, or just plain wrong, [open an issue](https://github.com/parkerziegler/reason-basics/issues) or [create a pull request](https://github.com/parkerziegler/reason-basics/pulls).

## Installation
Follow the same standard steps for cloning and installing this repo locally:

```sh
git clone https://github.com/parkerziegler/reason-basics.git
cd reason-basics
yarn install
```

## Running the Code
The source file for this repository is currently housed in `src/demo.re`. To compile the Reason code to BuckleScript and then to JS:

```sh
yarn run build
```

To compile the file and watch for changes on save:

```sh
yarn run start
```

To run the code and see the output in your terminal:

```sh
node src/demo.bs.js
```

This expects that you have Node @6 or later installed on your machine.

## Editor
If you use `vscode`, you can use `Cmd + Shift + B` (on macOS) or `Windows + Shift + B` (on Windows) to build automatically.

## Extensions
If you use `vscode`, I recommend installing the [OCcaml and Reason IDE](https://marketplace.visualstudio.com/items?itemName=freebroccolo.reasonml) for an awesome Reason-writing experience.