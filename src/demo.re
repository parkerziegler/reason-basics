/* reason-basics */
/* let's learn some Reason */

/* commenting in Reason */

/* To log out to the console we can use BuckleScript's JS module */
Js.log("Hello, BuckleScript and Reason! – Luv BuckleScript");
/* We can also use Reason's native print_endline */
print_endline("Hello, BuckleScript and Reason! – Luv Reason");
/* Note that print_endline can only print strings. To print data structures use Js.log.
Future support for this in the language is coming to Reason. */
/* To print other types, use Reason's type coercion methods */
print_endline(string_of_int(1));
print_endline(string_of_bool(true));

/* Variables */
/* Variables in Reason are defined using let.
There is no concept of const in Reason. */
let myVar = "myVar";

/* Characters and Strings */
/* Reason differentiates between characters - single quoted - and strings - double quoted. */
let x = 'x';
let y = 'y';

/* Pattern matching a Character */
let isXY = (char) : bool =>
    switch (char) {
        | 'x' | 'y' => true
        | _ => false
    };

/* To convert characters to strings, use String.make, passing 1 as the first arg */
let stringFromChar: string = String.make(1, x) ++ String.make(1, y);
print_endline(stringFromChar);

/* Strings are concatenated using the ++ operator */
let greeting = "hello";
let space = " ";
let name = "P-Doo";
print_endline(greeting ++ space ++ name);

/* Special characters in strings need to be escaped using \ */
let oneSlash = "\\";
print_endline(oneSlash);

/* Reason also supports multiline strings, similar to tagged template literals */
let multiLineString = {|Hello
Parkie
Doo|};
print_endline(multiLineString);

/* To use unicode characters in a string in Reason, use js| |js */
let unicodeString = {js|••∆∆••|js};
print_endline(unicodeString);

/* To interpolate variables in multiline strings, use surround the string in j| |j */
let style = "background-color: papayawhip";
let cssStyle = {j|$style|j};
print_endline(cssStyle);

/* The String module gives us access to common string operators like length access */
let length: int = String.length(greeting);
print_endline(string_of_int(length));

/* And substrings */
let sub: string = String.sub(greeting, 1, 3);
print_endline(sub);

/* Conditionals */
/* Coonditionals work similarly to JavaScript. However, an `if` statement without an `else`
implictly evaluates to else { () }, the unit type. */
let displayGreeting = true;
if (displayGreeting) {
  let message = "Enjoying my ridiculous commentary yet?";
  print_endline(message);
};

/* Ifs are evaluated to their body content – their is no need for a return statement */
let goodRT = true;
let content = if (goodRT) {
    "This tweet has good RT."
} else {
    "This tweet has bad RT."
};
print_endline(content);

/* There is also support for the ternary operator. */
let greatRT = goodRT ? "Most certainly." : "Not so much.";
print_endline(greatRT);

/* Scoping */
/* Variables are block-scoped and can be anonymously scoped */
let anonymousScope = {
    let name = "Parker";
    let place = "Seattle";
    print_endline(name);
    print_endline(place);
};

/* Name and Place are inaccessible here because they are held
by the anonymous scope created above. Attempting to access them
will throw an error! */

/* Types! */
/* Reason is backed by OCaml's top notch type system. */
/* We can explicitly type our variables, although this is not required.
Reason will infer types for us. */
let petalLength: int = 5;

/* We can also alias types. */
type flowerType = int;

/* And then use them! */
let sepalLength: flowerType = 20;

/* We type function returns by annotating the argument. */
let flowerLength = (petal: int, sepal: int) : int => petal + sepal;

/* To print we need to call string_of_int to cast our int result to a string! */
print_endline(string_of_int(flowerLength(petalLength, sepalLength)));

/* Boolean */
/* Boolean comparisons in Reason are similar to JS */
/* === represents referential equality while == represents structural equality */
/* Be careful using ==, Reason will warn you about this! */
let myTuple = ("Parkie", "is", 1);
let compareBool = tuple : bool => tuple === myTuple;
print_endline(string_of_bool(compareBool(myTuple)));

/* This line will yield "polymorphic comparison introduced (maybe unsafe)" */
print_endline(string_of_bool(('M', 23) == ('M', 23)));
/* This line is ok */
print_endline(string_of_bool(('M', 23) === ('M', 23)));

/* Integers and Floats */
/* Reason has concepts of both integers and floats
as opposed to just JS numbers */
let aGreatNumber: int = 20;
let sqaureInt = (num: int) : int => num * num;
print_endline(string_of_int(sqaureInt(aGreatNumber)));

/* Floats have a unique operand syntax, apending "." to +, -, *, / */
let aGreatFloat: float = 3.1415926;
let circleArea = (num: float) : float => aGreatFloat *. num *. num;
print_endline(string_of_float(circleArea(314.2)));

/* Tuples */
/* Tuples are immutable, ordered, finite at creation, and of heterogeneous type
(though they can be all the same type). */
/* Tuple types just mimic the shape of the tuples they represent! */
let aDopeTuple: (char, string, int, string) = ('a', "Dope", 44, "tuple");

/* There are special methods for getting tuple elements for tuples of length 2. */
/* Use the Pervasives module to get access to them */
let twoTuple: (string, string) = ("It", "Me");
let first: string = Pervasives.fst(twoTuple);
let second: string = Pervasives.snd(twoTuple);
print_endline(first);
print_endline(second);

/* Most tuple elements are accessed using destructuring */
let (_, _, thirdIdx: int, _) = aDopeTuple;
print_endline(string_of_int(thirdIdx));

/* Tuples are especially useful for pattern matching multiple possible combinations. */
let rotate = (x, y) => {
    switch (x, y) {
    | (180, -180) => print_endline({j|rotate $x, $y|j})
    | (90, -90) => print_endline({j|turn $x, $y|j})
    | (_, _) => print_endline({j|nothing|j})
    }
};

rotate(180, -180);
rotate(90, -90);

/* Records */
/* Records are similar to JS objects, but are lighter, immutable by default,
fixed in field names and types, faster, more rigidly typed. */
/* Record types are required – the compiler will error if they are not included! */
/* Prepend the type with mutable to indicate a mutable field. */
type team = {
    name: string,
    mutable rank: int,
    average: float
};

let redSox: team = {
    name: "Red Sox",
    rank: 1,
    average: 5.6
};

/* Record keys are accessed via dot notation */
print_endline(redSox.name);
print_endline(string_of_float(redSox.average));

/* New records are created immutably from old records using the spread operator */
/* However, spread cannot add new fields as records are constrained by type */
let redSoxUpdate = {
    ...redSox,
    average: 6.8
};

print_endline(string_of_float(redSoxUpdate.average));

/* Existing records can be updated mutably using = */
redSox.rank = redSox.rank + 1;
print_endline(string_of_int(redSox.rank));

/* Records also have punning in Reason, similar to ES6 object shorthand syntax. This
allows you to provide just the key name if the value matches */
let capital = "Olympia";
type state = {
    capital: string,
    population: int
};

let washington: state = {
    capital,
    population: 6000000
};

/* You can also pun with types! */
type place = {
    state,
    team: string
};

let seattle = {
    state: washington,
    team: "Mariners"
};

/* While records are somewhat similar to JS objects, you have to be more cognizant of their types. */
/* Use records for data that doesn't change shape. Records are compiled to JS arrays with array index
access, making them blazingly fast. Changing the type of a record can also help flag where you need
to update your data strucutres, making debugging easier! */

/* Variant */
/* Variants are a unique data structure in Reason. They allow us to express this or that relationships. */
type veryCoolVariant = 
  | Dope /* These are called a variant's constructors or tags */
  | Sweet
  | NotBad
  | AF;

/* Variants are typically moved with Reason's switch statement to pattern match */
let urStatus = (status) : string =>
    switch (status) {
    | Dope => "You are dope!";
    | Sweet => "You are sweet!";
    | NotBad => "You are not bad!";
    | AF => "You are dope af!";
    };

print_endline(urStatus(AF));

/* Variants need explicit definitions. Import them by calling the module they reside in. */
let team: Team.seattleVariant = Mariners;

/* Variant constructors can also take arguments. Check out seattleArgVariant in Team.re, which
has the following shape:
type seattleArgVariant =
  | Mariners(player)
  | Sonics(player, year)
  | Seahawks
  | Sounders;

This looks a lot like function arguments! We can use this to our advantage in pattern matching!
*/

type bostonArgVariant =
  | RedSox(string)
  | Celtics(string, int)
  | Bruins;

let myVar = RedSox("Mookie Betts");

let namePlayer = (teamArg) =>
    switch (teamArg) {
    | RedSox(name) => {j|You chose $name|j}
    | Celtics(name, year) => year < 2008 ? name : "Big 3"
    | Bruins => "Zdeno Chara"
    };

print_endline(namePlayer(myVar));
print_endline(namePlayer(Celtics("Larry Bird", 2009)));
print_endline(namePlayer(Celtics("Larry Bird", 1984)));

/* The standalone library exposes some cool variants for you. */
/* type option('a) = None | Some('a); - this allows yo to define types that can be nullable or undefined */
/* For example -> option(int) types a variable as a nullable integer */

/* List & Array */
/* Lists are homogenous, immutable, and fast at prepending items. */

/* Lists look a lot like arrays in JS. */
let fibNum: list(int) = [1, 1, 2, 3, 5, 8, 13, 21];

/* To prepend to a list, use the spread operator. This doesn't mutate the original list.
fibNumHeadZero shares its elements with fibNum, making it very efficient. */
let fibNumHeadZero = [0, ...fibNum];

/* It's important to note that using double spread [a, ...b, ...c] is not allowed in Reason. */

/* To access an arbitrary list item use List.nth */
let myNum = List.nth(fibNum, 4);

/* To get the length of the list use List.length */
let length: int = List.length(fibNum);
let lastItem: int = List.nth(fibNum, length - 1);

/* Arrays are like lists, but are mutable and optimized for random access and updates.
They are fix-sized on native, but flexibly-sized on JS. */
/* Arrays are denoted with [| and |]. */
let fibArray: array(int) = [|1, 1, 2, 3, 5, 8, 13, 21|];

/* Array access and update is similar to JS */
let length: int = Array.length(fibArray);
let lastItem: int = fibArray[length - 1];
fibArray[2] = 500;

/* You can also use Array.get and Array.set from the standard library. */
Array.set(fibArray, 2, 1000);
Array.get(fibArray, 2);

/* To convert an array to a list use ArrayLabels module. */
let fibList: list(int) = ArrayLabels.to_list(fibArray);
let fibBackAsArray: array(int) = ArrayLabels.of_list(fibList);

/* Function */
/* Functions are declared using => with a return expression. Single line functions can be inline.
Multiline functions should be surrounded by {} */

/* In Reason, all functions have arguments. If no explicit args are passed, we pass the "()" value,
which is called "unit" in Reason. */
let noArg = () : unit => print_endline("This is unit!");
let add = (x) => x + x;
let square = (x) => x * x;

/* A preview of the pipe operator! */
let addAndSquare = (x) => x |> add |> square;
print_endline(string_of_int(addAndSquare(4)));

/* Reason also has a concept of labeled arguments. Because Reason supports currying, we can use
labeled arguments to specify args in any order. */
let stringIntConcat = (~int: int, ~str: string) => string_of_int(int) ++ " " ++ str;
let res = stringIntConcat(~str="is an int.", ~int=50);
print_endline(res);

/* You can also alias labeled arguments to use in a function. */
let calcTriangleArea = (~base as b, ~height as h) => 0.5 *. b *. h;
print_endline(string_of_float(calcTriangleArea(2.0, 7.0)));

/* Currying */
/* Reason functions can automatically be partially called. */
let multiply = (x, y) => x * y;
let multiplyByFive = multiply(5);
let res = multiplyByFive(6);
print_endline(string_of_int(res));

/* is equivalent to */
let multiply = (x) => (y) => x * y;

/* OCaml optimizes this for us as a way to avoid unnecessary function allocation. */

/* Optional Labeled Arguments */
/* Labeled args can be made optional in Reason using =? */
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

/* Notice the parens () in the function definition and call above. Without it, Reason can't parse the
function. Both greeting and name can be curried and applied out of order, so it's unclear what 
something like sayHello(~greeting) would mean. OCaml parses the () as indicating that the optional 
labeled arg is omitted. Otherwise, it parses the function as the curried function waiting for name
to be applied. */
let actualFunction = sayHello(~greeting="Marhaba", ());
let curriedFunction = sayHello(~greeting="Marhaba");

/* Sometimes, you don't know whether the value you're forwarding to a function is None or Some(val).
In this case, you can provide an explictly passed optional. */
let possibleName: option(string) = Some("Formidable");
sayHello(~greeting="Hi ya", ~name=?possibleName, ());

/* If possibleName had the constructor None, the above function would still work! */
/* You can also provide default values, like ES6. */
let sayHello = (~greeting="Aloha", ~name=?, ()) => {
    let person =
        switch (name) {
        | None => ""
        | Some(a) => a
        };
    print_endline(greeting ++ " " ++ person);
};

sayHello(());

/* Recursive Functions */
/* To define a recursive function use the "rec" keyword. */
let rec factorial = (num: int) => {
    if (num === 0) {
        1
    } else {
        num * factorial(num - 1)
    }
};
print_endline(string_of_int(factorial(5)));

/* Mutually Recursive Functions */
/* Functions can recursively call each other in Reason. Use the "and" keyword to make this happen. */
let rec factorialEven = (num: int) => {
    if (num === 0) {
        1
    } else {
        num * factorialOdd(num - 1)
    }
} and factorialOdd = (num: int) => num * factorialEven(num - 1);
print_endline(string_of_int(factorialEven(6)));

/* If you're coming from JS, the usefulness of the above pattern comes into play because
Reason / OCaml does not hoist variable or function declarations! */

/* More on Types */
/* You can create parameterized types in Reason to make types more expressive. */
/* They act like functions, accepting parameters and returning types. */
type measurements('a) = ('a, 'a);
type measurementsInt = measurements(int);
type measurementsString = measurements(string);

/* inline */
let modalSize: measurements(int) = (150, 300);
let dialogSize: measurements(string) = ("500", "1000");

/* Most of the time, type inference will take care of this for you. */
/* Types can also make use of variants. */
type httpResult('a, 'b) =
  | Success('a)
  | Failure('b);

type payload = {
    data: string,
    code: int
};

/* The composed type httpResult expects two args, and applies those to Success and Failure constructors. */
let result: httpResult(payload, int) = Success({ data: "Woohoo", code: 200 });
let errResult: httpResult(payload, int) = Failure(404);

/* Mutually Recursive Types */
/* Types, like functions, can be mutually recursive. */
type professor = {
    course: list(course)
} and course = {
    professor: professor
};

/* Destructuring */
/* Destructuring is a common pattern in Reason and is useful for pulling data out of structures. */
let teams = ("Mariners", "Red Sox", "Astros", "Twins");
let (ms, bosox, stros, ts) = teams;
print_endline(ms);

/* You can also alias named fields. */
type musicRecord = {
    album: string,
    artist: string
};

let myRecord = {
    album: "Illinois",
    artist: "Sufjan Stevens"
};
let { album: al, artist: ar } = myRecord;
print_endline(al);

/* You can even destructure and alias function args! */
type wowza = {
    exclamation: string
};
let destructured = (~wowza as {exclamation} as wowZA) => {
    /* You have access to both exclamation as the string and
    wowZA as the original record here. */
    print_endline(exclamation);
    print_endline(wowZA.exclamation);
};
destructured(~wowza={exclamation: "Breathtaking, this Reason!"});