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

The source file for this repository is currently housed in `src/index.re`. To compile the Reason code to BuckleScript and then to JS:

```sh
yarn run build
```

To compile the file and watch for changes on save:

```sh
yarn run start
```

To run the code and see the output in your terminal:

```sh
node src/index.bs.js
```

This expects that you have Node @6 or later installed on your machine.

## Editor

If you use `vscode`, you can use `Cmd + Shift + B` (on macOS) or `Windows + Shift + B` (on Windows) to build automatically.

## Extensions

If you use `vscode`, I recommend installing the [OCcaml and Reason IDE](https://marketplace.visualstudio.com/items?itemName=freebroccolo.reasonml) for an awesome Reason-writing experience.

## Let's Learn Reason

**Note: These are the same contents as `index.re`, just written in Markdown for your viewing pleasure.**

Note that this repository uses Reason's v3 syntax.

```reason
/* Here's how we comment in Reason. */
```

To log out to the console we can use BuckleScript's JS module.

```reason
Js.log("Hello, BuckleScript and Reason! Luv BuckleScript");
/* "Hello, BuckleScript and Reason! Luv BuckleScript" */
```

To log out multiple arguments, we need to use BuckleScript's `Js.logX` functions. These are specifically designed to type `log` functions with different [arity](http://2ality.com/2017/12/functions-reasonml.html#terminology-arity).

```reason
Js.log2("This can log", "two values.");
/* "This can log", "two values." */
```

We can also use Reason's native `print_*` modules.

```reason
print_endline("Hello, BuckleScript and Reason! Luv Reason");
/* "Hello, BuckleScript and Reason! Luv Reason" */
```

Note that `print_endline` can only print strings. To print data structures use `Js.log`. Future support for this in the language is coming to Reason.

To print other types, you can either use Reason's type coercion methods or `print_*` modules.

```reason
print_endline(string_of_int(1));
print_endline(string_of_bool(true));

/*
"1"
"true"
*/
```

If you use `print_*` methods, you need to use `print_newline()` to get a new line. `print_endline()` appends the new line for you.

```reason
print_int(1);
print_newline();
print_float(1.0);
print_newline();

/*
1
1.
*/
```

### Variables

Variables in Reason are defined using `let`. There is no concept of `const` in Reason as there is in JS.

```reason
let myVar = "myVar";
let myInt = 1;
```

### Characters and Strings

Reason differentiates between characters - single quoted - and strings - double quoted.

```reason
let x = 'x';
let y = 'y';
```

Example of pattern matching a character.

```reason
let isXY = char : bool =>
  switch (char) {
  | 'x'
  | 'y' => true
  | _ => false
  };
```

To convert characters to strings, you can use `String.make`, passing 1 as the first arg.

```reason
let stringFromChar: string = String.make(1, x) ++ String.make(1, y);
print_endline(stringFromChar);

/* "xy" */
```

If you want to create strings from functions using numerical indexes, use `String.init`.

```reason
let stringFromInit: string =
  String.init(3, i =>
    switch (i) {
    | i when i < 2 => 'a'
    | _ => 'b'
    }
  );

print_endline(stringFromInit);

/* "aab" */
```

Strings are concatenated using the `++` operator.

```reason
let greeting = "Hello";
let space = " ";
let name = "P-Doo";
let exclamation = "!";

print_endline(greeting ++ space ++ name ++ exclamation);

/* "Hello P-Doo! */
```

We can operate on strings using methods from the `String` module of the standard library (Reason's built in methods).

```reason
let whitespaceString = "   __trim me__   ";
let trimmedString = String.trim(whitespaceString);

print_endline(trimmedString);

/* "__trim me__" */

let atString =
  String.map(
    c =>
      switch (c) {
      | ' ' => '@'
      | _ => c
      },
    whitespaceString
  );

print_endline(atString);
/* "@@@__trim@me__@@@" */
```

Special characters in strings need to be escaped using `\`.

```reason
let slash = "\\";

print_endline(slash);
```

Reason also supports multiline strings, similar to JS template literals. They are demarcated using `{| |}`.

```reason
let multilineString = {|Hello
Reasonable
Folks!|};

print_endline(multilineString);
```

`String` methods work the same on multiline strings. For example, to convert a multiline string to a singleline string:

```
let singlelineString =
  String.map(
    c =>
      switch (c) {
      | '\n' => ' '
      | _ => c
      },
    multilineString
  );

print_endline(singlelineString);
```

To interpolate variables in multiline strings, surround the string in `j| |j`.

```reason
let style = "background-color: papayawhip";
let cssStyle = {j|$style|j};

print_endline(cssStyle);
```

To use unicode characters in a string in Reason, use `js| |js`.

```reason
let unicodeString = {js|••∆∆••|js};

print_endline(unicodeString);
```

To get string lengths and substrings:

```reason
let background = "background-color: aquamarine";
let strLength: int = String.length(background);

print_endline(string_of_int(strLength));

let subStr: string =
  String.sub(background, 0, String.index(background, '-'));

print_endline(subStr);
```

### Conditionals

Coonditionals work similarly to JS. However, an `if` statement without an `else` implictly evaluates to `else { () }`, the `unit` type.

```reason
let displayGreeting = true;

if (displayGreeting) {
  let message = "Enjoying my ridiculous commentary yet?";
  print_endline(message);
};
```

Conditionals are evaluated to their body content – there is no need for a `return` statement.

```reason
let good = true;
let content =
  if (good) {"This tweet is good."} else {
    "This tweet is bad. Please make it better."
  };

print_endline(content);
```

It is essential that there be an `else` block evaluating to a string in the block above. If there wasn't, `content` would be assigned the `unit` type, although it is intended to be a string. This will yield a compiler error. There is also support for the ternary operator.

```reason
let retweet = good ? "Most certainly." : "Eh, don't think so.";

print_endline(retweet);
```

### Scoping

Variables are block-scoped by default. `let` bindings can create anonymous scopes by using `{}`. \*/

```reason
let anonymousScope = {
  let name = "Parker";
  let company = "Formidable";
  let place = "Seattle";
  print_endline({j|$name works at $company in $place.|j});
};
```

`name`, `company`, and `place` are inaccessible here because they are held by the anonymous scope created above. Attempting to access them outside of their scope will throw an error!

### Types!

Reason is backed by OCaml's top notch type system. We can explicitly type our variables, although this is not required. Reason will often infer types for us.

```reason
let petalLength: int = 5;
```

We can also alias types.

```reason
type sepalLength = int;
```

And then use them!

```reason
let sepalLength: sepalLength = 20;
```

We type function returns by annotating the argument.

```reason
let flowerLength = (petal: int, sepal: sepalLength) : int => petal + sepal;

print_endline(string_of_int(flowerLength(petalLength, sepalLength)));
```

### Boolean

Boolean comparisons in Reason are similar to JS. `===` represents referential equality while `==` represents structural equality. Be careful using `==`, Reason will warn you about this!

```reason
let myTuple = ("Parkie", "is", 1);
let compareBool = tuple : bool => tuple === myTuple;

print_endline(string_of_bool(compareBool(myTuple)));
```

This line will yield `polymorphic comparison introduced (maybe unsafe)`.

```reason
print_endline(string_of_bool(('M', 23) == ('M', 23)));
```

This line produces no warnings.

```reason
print_endline(string_of_bool(('M', 23) === ('M', 23)));
```

### Integers and Floats

Reason has concepts of both integers and floats as opposed to just JS numbers.

```reason
let githubStars: int = 9;
let squareInt = (num: int) : int => num * num;

print_endline(string_of_int(squareInt(githubStars)));
```

To work with ints, use methods from Reason's `Pervasives` module. These are already available in scope.

```reason
let start: int = 1;
+ start; /* unary add */
- start; /* unary minus */
let remainder = 20 mod 5; /* modulo */

print_endline(string_of_int(remainder));
```

Floats have a unique operand syntax, apending `.` to `+`, `-`, `*`, `/` operators.

```reason
let pi: float = 3.1415926;
let circleArea = (radius: float) : float => pi *. radius *. radius;

print_endline(string_of_float(circleArea(20.0)));

let radius = sqrt(circleArea(20.0)) /. pi;

print_endline(string_of_float(radius));
```

### Tuples

Tuples are immutable, ordered, finite at creation, and of heterogeneous type (though they can be all the same type). Tuple types just mimic the shape of the tuples they represent!

```reason
let myTuple: (char, string, int, string) = ('A', "wonderful", 100, "tuple");
```

There are special methods for getting tuple elements for tuples of length 2. These are avialable on the `Pervasives` module.

```reason
let twoTuple: (string, string) = ("It", "Me");
let first: string = fst(twoTuple);
let second: string = snd(twoTuple);

print_endline(first);
print_endline(second);
```

Most tuple elements are accessed using destructuring.

```reason
let (_, _, third: int, _) = myTuple;
print_endline(string_of_int(third));
```

Tuples are especially useful for pattern matching multiple parameters.

```reason
let rotate = (x, y) =>
  switch (x, y) {
  | (180, (-180)) => print_endline({j|Rotate $x, $y|j})
  | (90, (-90)) => print_endline({j|Turn $x, $y|j})
  | (_, _) => print_endline("Hold steady!")
  };

rotate(180, -180);

rotate(90, -90);

rotate(50, 70);
```

### Records

Records are similar to JS objects, but are lighter, immutable by default, fixed in field names and types, faster, more rigidly typed. Record types are required – the compiler will error if they are not included! Be sure to prepend a mutable property with the `mutable` keyword.

```reason
type team = {
  name: string,
  mutable rank: int,
  average: float,
};

let redSox: team = {name: "Red Sox", rank: 1, average: 0.326};
```

Record keys are accessed via dot notation.

```reason
print_endline(redSox.name);
print_endline(string_of_float(redSox.average));
```

New records are created immutably from old records using the `spread` operator. However, `spread` cannot add new fields as records are constrained by type.

```reason
let redSoxUpdate = {...redSox, average: 0.418};

print_endline(string_of_float(redSoxUpdate.average));
```

Existing records can be updated mutably using `=`.

```reason
redSox.rank = redSox.rank + 1;

print_endline(string_of_int(redSox.rank));
```

Records also have punning in Reason, similar to ES6 object shorthand syntax. This allows you to provide just the `key` name if the `value` matches.

```reason
let capital = "Olympia";
let population = 6000000;

type state = {
  capital: string,
  population: int,
};

let washington: state = {capital, population};
```

You can also pun with types!

```reason
type place = {
  state,
  team,
};

let seattle: place = {
  state: washington,
  team: {
    name: "Mariners",
    rank: 3,
    average: 0.298,
  },
};
```

While records are somewhat similar to JS objects, you have to be more cognizant of their types. Use records for data that doesn't change shape. Records are compiled to JS arrays with array index access, making them fast. Changing the type of a record can also help flag where you need to update your data structures, making debugging easier!

If you are interested in using JS native objects, Reason provides a shorthand syntax. This involves wrapping key names with double quotes ("").

```reason
type jsObject = {.
  "response": {.
    "data": {.
      "starCount": int,
      "watchers": int
    },
    "code": int
  }
};

let jsObject: jsObject = {
  "response": {
    "data": {
      "starCount": 9,
      "watchers": 2
    },
    "code": 200
  }
};
```

To access fields, use the `##` notation.

```reason
let starCount: int = jsObject##response##data##starCount;

print_endline(string_of_int(starCount));
```

### Variant

Variants are a unique data structure in Reason. They allow us to express _this_ or _that_ relationships.

```reason
type tweetQuality =
  | Dope /* These are called a variant's constructors or tags. */
  | Sweet
  | NotBad
  | AF;
```

Variants are typically used with Reason's switch statement to pattern match.

```reason
let tweetStatus = status : string =>
  switch (status) {
  | Dope => "That was a dope tweet!"
  | Sweet => "Pretty sweet tweet!"
  | NotBad => "Not great, but not bad!"
  | AF => "Pretty af tweet my friend!"
  };

print_endline(tweetStatus(AF));
```

Variants need explicit definitions. Import them by calling the module they reside in.

```reason
let team: Team.seattleVariant = Mariners;
```

Variant constructors can also take arguments. Check out `seattleVariant` in `Team.re`, which has the following shape:

```reason
type seattleVariant =
  | Mariners(player)
  | Sonics(player, year)
  | Seahawks
  | Sounders;
```

This looks a lot like function arguments! We can use this to our advantage in pattern matching!

```reason
open Team;

let player: Team.bostonVariant = RedSox("Mookie Betts");

let namePlayer = arg =>
  switch (arg) {
  | RedSox(name) => {j|You chose $name|j}
  | Celtics(name, year) => year < 2008 ? name : "Big 3"
  | Patriots => "Malcolm Butler"
  | Bruins => "Zdeno Chara"
  };

print_endline(namePlayer(player));
print_endline(namePlayer(Celtics("Larry Bird", 2009)));
print_endline(namePlayer(Celtics("Larry Bird", 1984)));
```

The standalone library exposes some cool variants for you.
`type option('a) = None | Some('a);` - this allows you to define types that can be `null`able or `undefined`. For example, `option(int)` types a variable as a nullable integer.

```reason
let isNull = true;

let possiblyNullInt: option(int) =
  if (isNull) {
    None;
  } else {
    Some(5);
  };

let checkNull = (num: option(int)) =>
  switch (num) {
  | Some(int) => false
  | None => true
  };

print_endline(string_of_bool(checkNull(possiblyNullInt)));
```

### List & Array

Lists are of homogenous type, immutable, and fast at prepending items. Lists look a lot like arrays in JS.

```reason
let fibList: list(int) = [1, 1, 2, 3, 5, 8, 13, 21];
```

To prepend to a list, use the `spread` operator. This doesn't mutate the original list. Instead, the new list maintains a link to the `spread`ed list. For example, `fibListHeadZero` below shares its elements with `fibList`, making it very efficient.

```reason
let fibListHeadZero = [0, ...fibList];
```

It's important to note that using double spread, i.e. `[a, ...b, ...c]` is not allowed in Reason. To access an arbitrary list item use `List.nth` from the `List` module.

```reason
let five = List.nth(fibList, 4);

print_endline(string_of_int(five));
```

To get the length of the list use `List.length`.

```reason
let length: int = List.length(fibList);
let lastItem: int = List.nth(fibList, length - 1);
```

The `List` module comes with additional built-in methods for operating on lists.

```reason
let reverse = List.rev(fibList);

let sum = List.fold_left((acc, el) => acc + el, 0, fibList);

print_endline(string_of_int(sum));

let thirteen = List.find(item => item === 13, fibList);

print_endline(string_of_int(thirteen));

let aboveTen = List.filter(item => item > 10, fibList);

List.iter(item => print_endline(string_of_int(item)), aboveTen);
```

Arrays are like lists, but are mutable and optimized for random access and updates. They are of fixed size on native, but flexibly sized on JS. Arrays are denoted with `[|` and `|]` on either end.

```reason
let fibArray: array(int) = [|1, 1, 2, 3, 5, 8, 13, 21|];
```

Array access and update is similar to JS.

```reason
let length: int = Array.length(fibArray);
let lastItem: int = fibArray[length - 1];
fibArray[2] = 500;
```

You can also use `Array.get` and `Array.set` from the standard library.

```reason
fibArray[2] = 1000;

print_endline(string_of_int(fibArray[2]));
```

To convert an array to a list use the `.to_list` function in the `ArrayLabels` module.

```reason
let fibArrayAsList: list(int) = ArrayLabels.to_list(fibArray);
let fibListAsArray: array(int) = ArrayLabels.of_list(fibArrayAsList);
```

Reason also supports multi-dimensional arrays. The first two arguments specify the dimensions of the array, while the third arg
provides the initial value with which fill the array.

```reason
let multiDemArray = Array.make_matrix(2, 2, "Initial.");
Js.log(multiDemArray);
```

### Function

Functions are declared using `=>`. Single line functions are permitted. Multiline functions should be surrounded by `{}`. In Reason, all functions have arguments. If no explicit args are passed, we pass `()`, the `unit` type.

```reason
let noArg = () : unit => print_endline("This is unit!");
let add = x => x + x;
let square = x => x * x;
```

A preview of the pipe operator!

```reason
let addAndSquare = x => x |> add |> square;

print_endline(string_of_int(addAndSquare(4)));
```

Reason also has a concept of labeled arguments. Because Reason supports currying, we can use labeled arguments to specify args in any order.

```reason
let concatStringInt = (~int: int, ~str: string) =>
  string_of_int(int) ++ " " ++ str;

print_endline(concatStringInt(~str="is an int.", ~int=50));
```

You can also alias labeled arguments to use in a function.

```reason
let calcTriangleArea = (~base as b: float, ~height as h: float) : float =>
  0.5 *. b *. h;

print_endline(string_of_float(calcTriangleArea(~base=2.0, ~height=7.0)));
```

### Currying

Reason functions can automatically be partially called. In fact, all functions in Reason accept a single argument!

```reason
let multiply = (x, y) => x * y;
let multiplyByFive = multiply(5);
let result = multiplyByFive(6);

print_endline(string_of_int(result));
```

The multiply function above is equivalent to:

```reason
let multiply = (x, y) => x * y;
```

OCaml optimizes this for us as a way to avoid unnecessary function allocation.

### Optional Labeled Arguments

Labeled args can be made optional in Reason using `=?`

```reason
let sayHello = (~greeting as g, ~name=?, ()) => {
  let person =
    switch (name) {
    | None => ""
    | Some(a) => a
    };
  print_endline(g ++ " " ++ person);
};

sayHello(~greeting="Marhaba", ());

sayHello(~greeting="Ahlan ya", ~name="Parker", ());
```

Notice the parens `()` in the third index of the function definition and call above. Without it, Reason can't parse the function. Both `greeting` and `name` can be curried and applied out of order, so it's unclear what something like `sayHello(~greeting="Aloha")` would mean. OCaml parses the `()` as indicating that the optional labeled arg is omitted. Otherwise, it parses the function as the curried function waiting for `name` to be applied.

```reason
/* Here we are calling the actual function sayHello as defined above. */
let actualFunction = sayHello(~greeting="Marhaba", ());

/* Here we return a function that could accept the ~name argument. */
let curriedFunction = sayHello(~greeting="Marhaba");

curriedFunction(~name="Parker", ());
```

Sometimes, you don't know whether the value you're forwarding to a function is None or Some(val). In this case, you can provide an explictly passed option type.

```reason
let possibleName: option(string) = Some("Formidable");

sayHello(~greeting="Hi ya", ~name=?possibleName, ());
```

If `possibleName` had the constructor `None`, the above function would still work!

You can also provide default values, like JS. Just specify them using `=` in the argument definition. Below, `Aloha` will be the value of `greeting` unless an explicit value is passed.

```reason
let sayHello = (~greeting="Aloha", ~name=?, ()) => {
  let person =
    switch (name) {
    | None => ""
    | Some(a) => a
    };
  print_endline(greeting ++ " " ++ person);
};

sayHello();
```

### Recursive Functions

To define a recursive function use the `rec` keyword.

```reason
let rec factorial = (num: int) =>
  if (num === 0) {
    1;
  } else {
    num * factorial(num - 1);
  };

print_endline(string_of_int(factorial(5)));
```

### Mutually Recursive Functions

Functions can recursively call each other in Reason. Use the `and` keyword to make this happen. The example below also previews how we use `exception` in Reason to create custom errors.

```reason
exception FactorialArgument(string);

let rec factorialEven = (num: int) =>
  if (num === 0) {
    1;
  } else {
    switch (num mod 2) {
    /* Pattern match to check if the number is even or odd. */
    | 0 => num * factorialOdd(num - 1)
    | 1 =>
      raise(
        FactorialArgument(
          "factorialEven only accepts even-numbered arguments."
        )
      )
    | _ => 1
    };
  }
and factorialOdd = (num: int) =>
  if (num === 0) {
    1;
  } else {
    switch (num mod 2) {
    | 0 =>
      raise(
        FactorialArgument(
          "factorialOdd only accepts odd-numbered arguments."
        )
      )
    | 1 => num * factorialEven(num - 1)
    | _ => 1
    };
  };

print_endline(string_of_int(factorialEven(6)));

print_endline(string_of_int(factorialOdd(5)));
```

The following call would throw our `FactorialArgument` `exception`, saying that `factorialEven` only accepts even-numbered arguments.

```reason
print_endline(string_of_int(factorialEven(5)));
```

If you're coming from JS, the usefulness of the above pattern comes into play because Reason / OCaml does not hoist variable or function declarations! Consider how you would call two functions, a and b, that call one another. This is possible in JS because function declarations are hoisted to the top of the scope. Since Reason has no hoisting, mutual recursion is one technique for solving this problem.

### More on Types

You can create parameterized types in Reason to make types more expressive. They act like functions, accepting parameters and returning types. Type parameters are prefixed with `'`.

```reason
type measurements('a) = ('a, 'a);
type measurementsInt = measurements(int);
type measurementsString = measurements(string);

/* inline */
let modalSize: measurements(int) = (150, 300);
let modalArea = fst(modalSize) * snd(modalSize);

print_endline(string_of_int(modalArea));

let dialogSize: measurements(string) = ("500", "1000");
let (w, h) = dialogSize;
let dialogDescription = {j|This dialog is $w by $h px|j};

print_endline(dialogDescription);
```

Most of the time, Reason's type inference will take care of typing arguments for you!

Types can also make use of variants.

```reason
type httpResult('a, 'b) =
  | Success('a)
  | Failure('b);

type payload = {
  data: string,
  code: int,
};
```

The composed type `httpResult` expects two args, and applies those to `Success` and `Failure` constructors.

```reason
let result: httpResult(payload, int) = Success({data: "Woohoo", code: 200});
let errResult: httpResult(payload, int) = Failure(404);
```

Because Reason's type system allows for type-level functions, there isn't need for much type boilerplate. For example, we can use `list(int)` and `list(string)` rather than needing to create a new primitive type for each, i.e. `listOfInt` and `listOfString`. This makes Reason's type system supremely expressive, while still providing the scaffolding of a rock solid type system. Enjoy!

### Mutually Recursive Types

Types, like functions, can be mutually recursive.

```reason
type professor = {courses: list(course)}
and course = {
  name: string,
  professor,
};
```

### Destructuring

Destructuring is a common pattern in Reason and is useful for pulling data out of structures.

```reason
let teams = ("Mariners", "Red Sox", "Astros", "Twins");
let (ms, bosox, stros, twins) = teams;

print_endline(
  {j|$ms, $bosox, $stros, $twins === Parkie-Doo's playoff picks.|j}
);
```

Here's how to destructure a Reason record. It looks a lot like object destructuring in JS.

```
type album = {
  name: string,
  artist: string,
  year: int,
};

let myFavoriteAlbum: album = {
  name: "Illinois",
  artist: "Sufjan Stevens",
  year: 2004,
};

let {name, artist, year} = myFavoriteAlbum;

print_endline({j|$artist wrote $name in $year.|j});
```

You can also alias variables when you destructure them, all in a single line! This is similar to ES6 destructuring.

```
let {name: n, artist: a, year: y} = myFavoriteAlbum;

print_endline({j|$a wrote $n in $y.|j});
```

You can even destructure and alias function arguments!

```
type exclamation = {
  phrase: string,
  volume: float,
};

let exclaim = (~exclamation as {phrase} as exclamation) =>
  /* You have access to both exclamation (the record) and
     the phrase property as a destructured variable. */
  print_endline(
    {j|And lo, Parkie-Doo shouted, $phrase at $exclamation.volume DB.|j}
  );

exclaim(~exclamation={phrase: "Breathtaking, this Reason!", volume: 120.7});
```

### Pattern Matching

Pattern matching is a great way to match your data against a set of values. Pattern matching is best used in tandem with variants – when does this way, we get nice, comprehensive assistance from the type system, which checks for unmatched cases.

```reason
type victory =
  | NailBiter(int)
  | BlowOut(int)
  | OT(string, int);

let myVictory: victory = OT("8:03", 1);
```

Pattern matching allows us to destructure variants, handling each case separately. To see the compiler warn you about an unmatched case, try commenting out `BlowOut` below.

```reason
let myOTVictory =
  switch (myVictory) {
  | NailBiter(margin) => {j|Yeesh, close game. Nice win by $margin.|j}
  | BlowOut(margin) => {j|Damn, what a blowout. $margin runs is impressive|j}
  | OT(time, margin) => {j|It took $time to win by $margin. But a win's a win.|j}
  };

print_endline(myOTVictory);
```

We can switch on other cases with other data structures as well. For example, an `array(int)`.

```reason
let arr = [|500, 600|];

let handleArray = (array: array(int)) =>
  switch (array) {
  | [|500, 601|] => print_endline("This is a very specific case.")
  | [|500, _|] =>
    print_endline("You have two items in this array, and the first is 500.")
  | [|_, _|] => print_endline("You have two items in this array.")
  | _ => print_endline("This is the default.")
  };

handleArray(arr);
handleArray([|500, 601|]);
handleArray([|101, 102|]);
handleArray([|1|]);
```

You can even pattern match a set of results to a particular outcome. For example, let's map errors on the server to particular outcomes.

```reason
type httpResultWithCode =
  | Success(int, list(string))
  | Failure(int);

let handleResult = (res: httpResultWithCode) =>
  switch (res) {
  | Success(200, data) =>
    let f = (acc, el) => acc ++ " " ++ el;
    /* We're using fold_left here to concatenate strings. fold_left is similar to
       reduce, but for lists! */
    let resString = ListLabels.fold_left(~f, ~init="", data);
    print_endline({j|data: $resString|j});
  | Failure(500)
  | Failure(502) => print_endline("Server error.")
  | Failure(404) => print_endline("Not found.")
  | _ => print_endline("We don't know what happened, sorry!")
  };

handleResult(Failure(500));
handleResult(Failure(502));
handleResult(Success(200, ["You", "Rock"]));
handleResult(Success(201, ["You", "Are", "Still", "Great"]));
```

You can also use `when` clauses to check specific conditions on a case. This is like adding a little bit of `if` sugar to your pattern matching logic. Expanding on our previous example above:

```reason
let isServerError = err => err === 500;
let isBadGateway = err => err === 502;

let handleResult = (res: httpResultWithCode) =>
  switch (res) {
  | Success(200, data) =>
    let f = (acc, el) => acc ++ " " ++ el;
    let resString = ListLabels.fold_left(~f, ~init="", data);
    print_endline({j|data: $resString|j});
  | Failure(errCode) when isServerError(errCode) =>
    print_endline("Server error.")
  | Failure(errCode) when isBadGateway(errCode) =>
    print_endline("Bad gateway. Getaway? Who knows?")
  | Failure(404) => print_endline("Not found.")
  | _ => print_endline("We don't know what happened, sorry!")
  };

handleResult(Failure(500));
handleResult(Failure(502));
```

You can also nest patterns, meaning we can pattern match on nested properties of data structures.

```reason
type composer = {
  name: string,
  concertos: int,
};

let evaluateComposer = (composer: composer) =>
  switch (composer) {
  | {name: "Beethoven" | "Mozart" | "Debussy"} => "What high class. How fancy!"
  | composer when composer.concertos <= 7 => "Not too bad, but nothing special."
  | _ => "Just another composer"
  };

print_endline(evaluateComposer({name: "Debussy", concertos: 57}));
print_endline(evaluateComposer({name: "Jerry", concertos: 7}));
```

### Mutation

`let` bindings are, by default, immutable. If you need to mutate a `let` binding wrap the value with the `ref` keyword.

```reason
let mutableVar = ref("mutable");
```

To access it, use the `^` operator.

```reason
let mutableReference = mutableVar^;
```

To reassign a mutable variable, use the `:=` operator.

```reason
mutableVar := "mutated";

print_endline(mutableVar^);
```

However, you can also mutate variables simply by shadowing them with another let binding.

```reason
let shadow = "First I am this!";

print_endline(shadow);

let shadow = "But now I've been shadowed!";

print_endline(shadow);
```

### Imperative Loops

`for` loops in Reason iterate from a start up to and including an end value.

```reason
let repeatCapitalize = (~times: int, ~str: string) => {
  let result = ref("");
  for (time in 1 to times) {
    switch (time mod 2) {
    | 0 => result := result^ ++ String.capitalize(str)
    | 1 => result := result^ ++ str
    | _ => result := result^ ++ str
    };
  };
  result^;
};

print_endline(repeatCapitalize(~times=5, ~str="reason"));
```

You can also use the `downto` operator to iterate down from a number.

```reason
let factorialSum = (~num: int) : int => {
  let result = ref(0);
  for (n in num downto 0) {
    result := result^ + n;
  };
  result^;
};

print_endline(string_of_int(factorialSum(~num=5)));
```

In general, `Array` and `List` methods with likely get you closer to what you're looking for than `for` loops, but they are great to know about. You can also use `while` loops in the same manner as you do in JS.

```reason
let count = ref(1);

while (count < ref(5)) {
  print_endline("We are while looping!");
  count := count^ + 1;
};
```

Use mutable bindings like above to break out of loops. Reason has no concept of a `break` keyword like JS.

### JSX

Reason natively supports JSX. Calls like:

```reason
<div foo={bar}> child1 child2 </div>
```

become:

```reason
([@JSX] div(~foo=bar, ~children=[child1, child2], ()));
```

The `[@JSX]` syntax flags a function as wanting to format as JSX. This allows any library in Reason, not just ReasonReact, to take advantage of JSX.

### Externals

Externals are how Reason communicates with other languages, often JS. One of the most common ways you use externals is to load modules. For example, let's load the `findS` function from the `findS` module in this repo.

```reason
[@bs.module "./findS"] external findS : string => int = "";

let twoS = findS("strings");

print_endline(string_of_int(twoS));
```

Sweet! We called a JS function from Reason! The annotations above allow us to type the function `findS` from the `findS` module and return a typesafe reference to that module. Let's look at how we might get access to a scoped function, like `Math.random`.

```reason
[@bs.val] [@bs.scope "Math"] external random : unit => float = "random";

[@bs.val] [@bs.scope "Math"] external floor : float => int = "floor";
```

In the definition above, we are saying there is a method on the `Math` scope called `random`. It takes the `unit` type as an argument and returns a `float`. We alias it to the name `random` for use in Reason. Now we can use it!

```reason
let getRandomInt = (~max as m: float) =>
  floor(random() *. float_of_int(floor(m)));

print_endline(string_of_int(getRandomInt(~max=100.0)));
```

### Object

Most of the time in Reason you'll be using a record to store named values. But sometimes, you'll want an object. Note than an object in Reason is not the same as a JS object. Prefix public values on the object with the `pub` keyword. `val` can be used to define a value on the object that is not externally accessible. `pri` can define private methods.

```reason
let anUntypedReasonObject = {pub city = "Burlington"; val state = "Vermont"};

print_endline(anUntypedReasonObject#city);
```

Reason objects don't need type definitions. If we do define them, the object _must_ have the shape of the type provided.

```reason
type locale = {
  .
  city: string,
  state: string,
  population: int,
};

let burlington: locale = {
  pub city = "Burlington";
  pub state = "Vermont";
  pub population = 56000
};

print_endline(string_of_int(burlington#population));
```

Two dots, known as elision, indicates that this object is open and can have properties other than the originally typed properties. Open objects are polymorphic and require a type parameter.

```reason
type localeOpen('a) = {.. getPlace: unit => string} as 'a;
```

Objects in Reason have a `this` context, which points at the object itself.

```reason
let vt: localeOpen({. getPlace: unit => string}) = {
  val address = "100 Church St";
  val city = "Burlington";
  val zipCode = "05712";
  pub getPlace = () =>
    address ++ ", " ++ city ++ " " ++ zipCode ++ ". " ++ this#addOn();
  pri addOn = () => "Didn't ya know?"
};

print_endline(vt#getPlace());
```

For the most part, you'll use either records or JS objects to achieve what you're used to in JS. Reason has a nice syntax for defining a JS object. This involves just wrapping the object keys in `""` and using `##` for access.

```reason
let reason = {"color": "orange", "language": "reason", "users": 5000};

print_endline(reason##language);
```

Mutating a JS Object involves letting BuckleScript know that we have a mutable key-value pair. To do this, annotate the type with `@bs.set`. Then, to mutate it, use `#=`.

```
type language = {
  .
  [@bs.set] "color": string,
  "language": string,
  "users": int,
};

[@bs.module "./findS"] external myJSObject : language = "";

print_endline(myJSObject##language);

myJSObject##color#="orange";

print_endline(myJSObject##color);
```

### Module

Modules in Reason can contain type defs, `let` bindings, nested modules, almost anything. Use the `module` keyword to create one.

```reason
module Earth = {
  let continents = [|
    "Africa",
    "Antarctica",
    "Asia",
    "Australia",
    "Europe",
    "North America",
    "South America",
  |];
  let pickContinent = (idx: int) => continents[idx];
};

let aussie = Earth.pickContinent(3);

print_endline(aussie);
```

We can also access nested modules! Check out the `Team` module, which has a nested `Boston` module.

```reason
print_endline(Team.Boston.team);
```

While Reason has great module inference - no `import`s! - it can be useful to explictly `open` a module using the `open` keyword. This brings
the module into scope. We can locally `open` a module for just a specific function like so:

```reason
let fact =
  Team.Boston.(
    switch (team) {
    | "Red Sox" => "The Red Sox are DOPE."
    | _ => "Eh, don't really care."
    }
  );

print_endline(fact);
```

Global `open` is useful good for getting everything in another module. Be careful though, this can introduce unwanted naming collisions / shadowing if modules have members with shared names!

```reason
open Team.Boston;
```

Modules can also extend one another, fulfilling the role of inheritcance or mixins in traditional OOP languages.

```reason
module ExtendedBoston = {
  include Team.Boston;
  let basketball = "Celtics";
};

print_endline(ExtendedBoston.team);

print_endline(ExtendedBoston.basketball);
```

### Promises

Promises in Reason are handled via BuckleScript using the `Js.Promise.*` methods. Note the `.` passed as the first argument to `resolve` below. This serves as a flag letting BuckleScript know this is an uncurried function. This was introduced in BuckleScript 2.2.2. If using an older version of bs-platform, you can use `[@bs] resolve(100)` for the same effect.

```reason
let promise = Js.Promise.make((~resolve, ~reject as _) => resolve(. 100));

exception Failure(string);
let failedPromise = Js.Promise.make((~resolve as _, ~reject) => reject(. Failure("Rejected!")));

promise
|> Js.Promise.then_(res => {
    Js.log(res);
    Js.Promise.resolve(res);
})
|> Js.Promise.then_(res => {
    Js.log("That's all folks!");
    Js.Promise.resolve(res - 100);
})
|> Js.Promise.catch(err => {
    Js.log2("Failure!!", err);
    Js.Promise.resolve(-1);
});

failedPromise
|> Js.Promise.then_(res => {
    Js.log(res);
    Js.Promise.resolve(res);
})
|> Js.Promise.then_(res => {
    Js.Promise.resolve(res - 100);
})
|> Js.Promise.catch(err => {
    Js.log2("Failure!!", err);
    Js.Promise.resolve(-1);
});
```

### Exception

Exceptions are a special kind of variant, and not used often in Reason.

The function below shows how to use the `Not_found` `exception` using the `raise` keyword.

```reason
let aFunkyList = ["Parliament", "Funkadelic", "George Clinton"];
  if (List.exists(item => item === "Stevie Wonder", aFunkyList)) {
      print_endline("Yay Stevie!");
  } else {
      /* Here we raise the Not_found constructor of the Exception variant. */
      raise(Not_found);
  };
```
