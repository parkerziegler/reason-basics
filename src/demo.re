/* reason-basics */
/* Not that this repository uses Reason's v3 syntax. */
/* Let's learn some Reason! */

/* Here's how we comment in Reason. */

/* To log out to the console we can use BuckleScript's JS module. */
Js.log("Hello, BuckleScript and Reason! Luv BuckleScript");
/* We can also use Reason's native print_* modules. */
print_endline("Hello, BuckleScript and Reason! Luv Reason");
/* Note that print_endline can only print strings. To print data structures use Js.log.
Future support for this in the language is coming to Reason. */

/* To print other types, you can either use Reason's type coercion methods or print_* modules. */
print_endline(string_of_int(1));
print_endline(string_of_bool(true));
/* If you use print_* methods, you need to use print_newline to
get a new line. print_endline() appends the new line for you. */
print_int(1);
print_newline();
print_float(1.0);
print_newline();

/* Variables */
/* Variables in Reason are defined using let.
There is no concept of const in Reason as there is in JS. */
let myVar = "myVar";
let myInt = 1;

/* Characters and Strings */
/* Reason differentiates between characters - single quoted - and strings - double quoted. */
let x = 'x';
let y = 'y';

/* Example of pattern matching a character. */
let isXY = (char) : bool =>
    switch (char) {
        | 'x' | 'y' => true
        | _ => false
    };

/* To convert characters to strings, use String.make, passing 1 as the first arg. */
let stringFromChar: string = String.make(1, x) ++ String.make(1, y);
print_endline(stringFromChar);

/* Strings are concatenated using the ++ operator. */
let greeting = "Hello";
let space = " ";
let name = "P-Doo";
let exclamation = "!";
print_endline(greeting ++ space ++ name ++ exclamation);

/* We can operate on strings using String methods from the standard library (Reason's built in methods). */
let whitespaceString = "   __trim me__   ";
let trimmedString = String.trim(whitespaceString);
print_endline(trimmedString);
let atString = String.map((c) => {
    switch (c) {
    | ' ' => '@';
    | _ => c;
    };
}, whitespaceString);
print_endline(atString);

/* Special characters in strings need to be escaped using \. */
let slash = "\\";
print_endline(slash);

/* Reason also supports multiline strings, similar to JS template literals. They are demarcated using {| |}*/
let multilineString = {|Hello
Reasonable
Folks!|};
print_endline(multilineString);
/* String methods work the same on multiline strings. For example,
to convert a multiline string to a singleline string. */
let singlelineString = String.map((c) => {
    switch (c) {
    | '\n' => ' '
    | _ => c
    }
}, multilineString);
print_endline(singlelineString);

/* To interpolate variables in multiline strings, surround the string in j| |j. */
let style = "background-color: papayawhip";
let cssStyle = {j|$style|j};
print_endline(cssStyle);

/* To use unicode characters in a string in Reason, use js| |js */
let unicodeString = {js|••∆∆••|js};
print_endline(unicodeString);

/* To get string lengths and substrings... */
let background = "background-color: aquamarine";
let strLength: int = String.length(background);
print_endline(string_of_int(strLength));
let subStr: string = String.sub(background, 0, String.index(background, '-'));
print_endline(subStr);

/* Conditionals */
/* Coonditionals work similarly to JS. However, an `if` statement without an `else`
implictly evaluates to else { () }, the unit type. */
let displayGreeting = true;
if (displayGreeting) {
  let message = "Enjoying my ridiculous commentary yet?";
  print_endline(message);
};

/* Conditionals are evaluated to their body content – there is no need for a return statement. */
let good = true;
let content = if (good) {
    "This tweet is good."
} else {
    "This tweet is bad. Please make it better."
};
print_endline(content);
/* It is essential that there be an else block evaluating to a string
in the block above. If there wasn't, content would be assigned the unit
type, although it is intended to be a string. This will yield a compiler error. */

/* There is also support for the ternary operator. */
let retweet = good ? "Most certainly." : "Eh, don't think so.";
print_endline(retweet);

/* Scoping */
/* Variables are block-scoped by default.
let bindings can create anonymous scopes by using {}. */
let anonymousScope = {
    let name = "Parker";
    let company = "Formidable";
    let place = "Seattle";
    print_endline({j|$name works at $company in $place.|j});
};

/* name, company, and place are inaccessible here because they are held
by the anonymous scope created above. Attempting to access them
outside of their scope will throw an error! */

/* Types! */
/* Reason is backed by OCaml's top notch type system. */
/* We can explicitly type our variables, although this is not required.
Reason will often infer types for us. */
let petalLength: int = 5;

/* We can also alias types. */
type sepalLength = int;

/* And then use them! */
let sepalLength: sepalLength = 20;

/* We type function returns by annotating the argument. */
let flowerLength = (petal: int, sepal: sepalLength) : int => petal + sepal;
print_endline(string_of_int(flowerLength(petalLength, sepalLength)));

/* Boolean */
/* Boolean comparisons in Reason are similar to JS. */
/* === represents referential equality while == represents structural equality */
/* Be careful using ==, Reason will warn you about this! */
let myTuple = ("Parkie", "is", 1);
let compareBool = tuple : bool => tuple === myTuple;
print_endline(string_of_bool(compareBool(myTuple)));

/* This line will yield "polymorphic comparison introduced (maybe unsafe)". */
print_endline(string_of_bool(('M', 23) == ('M', 23)));
/* This line produces no warnings. */
print_endline(string_of_bool(('M', 23) === ('M', 23)));

/* Integers and Floats */
/* Reason has concepts of both integers and floats
as opposed to just JS numbers. */
let githubStars: int = 9;
let squareInt = (num: int) : int => num * num;
print_endline(string_of_int(squareInt(githubStars)));

/* To work with ints, use methods from Reason's Pervasives module.
These are already available in the scope. */
let start: int = 1;
+ start; /* unary add */
- start; /* unary minus */
let remainder = 20 mod 5; /* modulo */
print_endline(string_of_int(remainder));

/* Floats have a unique operand syntax, apending "." to +, -, *, / operators. */
let pi: float = 3.1415926;
let circleArea = (radius: float) : float => pi *. radius *. radius;
print_endline(string_of_float(circleArea(20.0)));
let radius = sqrt(circleArea(20.0)) /. pi;
print_endline(string_of_float(radius));

/* Tuples */
/* Tuples are immutable, ordered, finite at creation, and of heterogeneous type
(though they can be all the same type). */
/* Tuple types just mimic the shape of the tuples they represent! */
let myTuple: (char, string, int, string) = ('A', "wonderful", 100, "tuple");

/* There are special methods for getting tuple elements for tuples of length 2. */
/* These are avialable on the Pervasives module. */
let twoTuple: (string, string) = ("It", "Me");
let first: string = fst(twoTuple);
let second: string = snd(twoTuple);
print_endline(first);
print_endline(second);

/* Most tuple elements are accessed using destructuring */
let (_, _, third: int, _) = myTuple;
print_endline(string_of_int(third));

/* Tuples are especially useful for pattern matching multiple parameters. */
let rotate = (x, y) => {
    switch (x, y) {
    | (180, -180) => print_endline({j|Rotate $x, $y|j})
    | (90, -90) => print_endline({j|Turn $x, $y|j})
    | (_, _) => print_endline("Hold steady!")
    }
};

rotate(180, -180);
rotate(90, -90);
rotate(50, 70);

/* Records */
/* Records are similar to JS objects, but are lighter, immutable by default,
fixed in field names and types, faster, more rigidly typed. */
/* Record types are required – the compiler will error if they are not included! */
/* Prepend a mutable property with the mutable keyword. */
type team = {
    name: string,
    mutable rank: int,
    average: float
};

let redSox: team = {
    name: "Red Sox",
    rank: 1,
    average: 0.326
};

/* Record keys are accessed via dot notation */
print_endline(redSox.name);
print_endline(string_of_float(redSox.average));

/* New records are created immutably from old records using the spread operator. */
/* However, spread cannot add new fields as records are constrained by type. */
let redSoxUpdate = {
    ...redSox,
    average: 0.418
};

print_endline(string_of_float(redSoxUpdate.average));

/* Existing records can be updated mutably using = */
redSox.rank = redSox.rank + 1;
print_endline(string_of_int(redSox.rank));

/* Records also have punning in Reason, similar to ES6 object shorthand syntax. This
allows you to provide just the key name if the value matches. */
let capital = "Olympia";
let population = 6000000;
type state = {
    capital: string,
    population: int
};

let washington: state = {
    capital,
    population
};

/* You can also pun with types! */
type place = {
    state,
    team
};

let seattle: place = {
    state: washington,
    team: {
        name: "Mariners",
        rank: 3,
        average: 0.298
    }
};

/* While records are somewhat similar to JS objects, you have to be more cognizant of their types. */
/* Use records for data that doesn't change shape. Records are compiled to JS arrays with array index
access, making them fast. Changing the type of a record can also help flag where you need
to update your data strucutres, making debugging easier! */

/* If you are interested in using JS native objects, Reason provides a shorthand syntax. This involves
wrapping key names with double quotes (""). */
let jsObject = {
    "response": {
        "data": {
            "starCount": 9,
            "watchers": 2
        },
        "code": 200
    }
};
/* To access fields, use the ## notation. */
let starCount: int = jsObject##response##data##starCount;
print_endline(string_of_int(starCount));

/* Variant */
/* Variants are a unique data structure in Reason. They allow us to express this or that relationships. */
type tweetQuality = 
  | Dope /* These are called a variant's constructors or tags. */
  | Sweet
  | NotBad
  | AF;

/* Variants are typically moved with Reason's switch statement to pattern match */
let tweetStatus = (status) : string =>
    switch (status) {
    | Dope => "That was a dope tweet!";
    | Sweet => "Pretty sweet tweet!";
    | NotBad => "Not great, but not bad!";
    | AF => "Pretty af tweet my friend!";
    };

print_endline(tweetStatus(AF));

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
open Team;
let player: Team.bostonVariant = RedSox("Mookie Betts");
let namePlayer = (arg) =>
    switch (arg) {
    | RedSox(name) => {j|You chose $name|j}
    | Celtics(name, year) => year < 2008 ? name : "Big 3"
    | Patriots => "Malcolm Butler"
    | Bruins => "Zdeno Chara"
    };

print_endline(namePlayer(player));
print_endline(namePlayer(Celtics("Larry Bird", 2009)));
print_endline(namePlayer(Celtics("Larry Bird", 1984)));

/* The standalone library exposes some cool variants for you. */
/* type option('a) = None | Some('a); - this allows you to define types that can be nullable or undefined. */
/* For example -> option(int) types a variable as a nullable integer */
let isNull = true;
let possiblyNullInt: option(int) = if (isNull) {
    None
} else {
    Some(5);
};
let checkNull = (num: option(int)) => {
    switch (num) {
    | Some(int) => false;
    | None => true;
    }
};
print_endline(string_of_bool(checkNull(possiblyNullInt)));

/* List & Array */
/* Lists are homogenous, immutable, and fast at prepending items. */

/* Lists look a lot like arrays in JS. */
let fibList: list(int) = [1, 1, 2, 3, 5, 8, 13, 21];

/* To prepend to a list, use the spread operator. This doesn't mutate the original list.
fibListHeadZero shares its elements with fibList, making it very efficient. */
let fibListHeadZero = [0, ...fibList];

/* It's important to note that using double spread [a, ...b, ...c] is not allowed in Reason. */

/* To access an arbitrary list item use List.nth */
let five = List.nth(fibList, 4);
print_endline(string_of_int(five));

/* To get the length of the list use List.length. */
let length: int = List.length(fibList);
let lastItem: int = List.nth(fibList, length - 1);

/* The List module in Reason comes with built-in methods for operating
on lists. */
let reverse = List.rev(fibList);
let sum = List.fold_left((acc, el) => acc + el, 0, fibList);
print_endline(string_of_int(sum));
let thirteen = List.find((item) => item === 13, fibList);
print_endline(string_of_int(thirteen));
let aboveTen = List.filter((item) => item > 10, fibList);
List.iter((item) => {
    print_endline(string_of_int(item));
}, aboveTen);

/* Arrays are like lists, but are mutable and optimized for random access and updates.
They are of fixed size on native, but flexibly sized on JS. */
/* Arrays are denoted with [| and |]. */
let fibArray: array(int) = [|1, 1, 2, 3, 5, 8, 13, 21|];

/* Array access and update is similar to JS. */
let length: int = Array.length(fibArray);
let lastItem: int = fibArray[length - 1];
fibArray[2] = 500;

/* You can also use Array.get and Array.set from the standard library. */
Array.set(fibArray, 2, 1000);
Array.get(fibArray, 2);

/* To convert an array to a list use ArrayLabels module. */
let fibArrayAsList: list(int) = ArrayLabels.to_list(fibArray);
let fibListAsArray: array(int) = ArrayLabels.of_list(fibArrayAsList);

/* Reason also supports multi-dimensional arrays. The first two
arguments specify the dimensions of the array, whilte the third
arg fills the array entries initially. */
let multiDemArray = Array.make_matrix(2, 2, "Initial.");
Js.log(multiDemArray);

/* Function */
/* Functions are declared using => with a return expression. Single line functions can be inline.
Multiline functions should be surrounded by {}. */

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
let concatStringInt = (~int: int, ~str: string) => string_of_int(int) ++ " " ++ str;
print_endline(concatStringInt(~str="is an int.", ~int=50));

/* You can also alias labeled arguments to use in a function. */
let calcTriangleArea = (~base as b: float, ~height as h: float) : float => 0.5 *. b *. h;
print_endline(string_of_float(calcTriangleArea(~base=2.0, ~height=7.0)));

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

/* Pattern Matching */
type victory = 
  | NailBiter(int)
  | BlowOut(int)
  | OT(string, int);

let myVictory = OT("8:03", 1);

/* Pattern matching allows us to destructure things like variants, handling each case separately.
The compiler will also let you know of an unhandled case. Try commenting out BlowOut below. */
let myOTVictory = switch (myVictory) {
| NailBiter(margin) => "Yeesh, close game. Nice win by " ++ string_of_int(margin) ++ "."
| BlowOut(margin) => "Damn, what a blowout. " ++ string_of_int(margin) ++ " runs is impressive."
| OT(time, margin) => "It took you " ++ time ++ " to win by " ++ string_of_int(margin) ++ "."
};

print_endline(myOTVictory);

/* We can switch on other cases with other data structures as well. */
let arr = [|500, 600|];

let handleArray = (array: array(int)) => {
    switch (arr) {
    | [|500, 601|] => print_endline("This is a very specific case.");
    | [|_, _|] => print_endline("You have two items in this array.");
    | _ => print_endline("This is the default.");
    };
};

handleArray(arr);

/* You can even pattern match a set of results to a particular outcome. */
type httpResultWithCode =
  | Success(int, list(string))
  | Failure(int);

let handleResult = (res: httpResultWithCode) => {
    switch (res) {
    | Success(200, data) => {
        let f = (acc, el) => acc ++ " " ++ el;
        let resString = ListLabels.fold_left(~f=f, ~init="", data);
        print_endline("You've got data." ++ resString ++ ".")
    };
    | Failure(500) | Failure(502) => print_endline("Things got messed up :(.");
    | Failure(404) => print_endline("We couldn't find that, sorry :(.");
    };
};

handleResult(Failure(500));
handleResult(Success(200, ["You", "Rock"]));

/* You can also use when clauses to check specific conditions on a case. */
/* Expanding on our previous example above: */
let isServerError = (err) => err === 500;

let handleResult = (res: httpResultWithCode) => {
    switch (res) {
    | Success(200, data) => {
        let f = (acc, el) => acc ++ " " ++ el;
        let resString = ListLabels.fold_left(~f=f, ~init="", data);
        print_endline("You've got data." ++ resString ++ ".")
    };
    | Failure(errCode) when isServerError(errCode) => print_endline("Things got messed up on the server :(.");
    | Failure(errCode) => print_endline("Bad gateway. Getaway? Who knows? :(.")
    | Failure(404) => print_endline("We couldn't find that, sorry :(.");
    };
};

handleResult(Failure(500));
handleResult(Failure(502));

type composer = {
    name: string,
    concertos: int
};

/* You can also nest patterns! */
let nested = (composer: composer) =>
    switch (composer) {
    | {name: "Beethoven" | "Mozart" | "Debussy"} => "Wowza!"
    | composer when composer.concertos <= 7 => "Boo!"
    | _ => "Just another composer"
};

print_endline(nested({name: "Debussy", concertos: 57}));
print_endline(nested({name: "Jerry", concertos: 7}));

/* Mutation */
/* let bindings are, by default, immutable. If you need to mutate a let binding you can use the ref keyword. */
let mutableVar = ref("mutable");

/* To access it, use the postfix ^ operator. */
let newMutableVar = mutableVar^;

/* And assignment uses the := operator. */
mutableVar := "NewMutableVar";
print_endline(mutableVar^);

/* However, you can also mutate variables simply by shadowing them with another let binding. */
let shadow = "Shadow Me!";
print_endline(shadow);
let shadow = "But now I'm this!";
print_endline(shadow);

/* Imperative Loops */
/* For loops in Reason iterate from a start up to and including an end value. */
let starter = 1;
let ender = 100;

for (num in starter to ender) {
    switch (num) {
    | num when num < 50 => print_endline("You're not yet over the hill.");
    | num when num >= 50 => print_endline("Yep, you're there.");
    | _ => print_endline("Don't mind me");
    };
};

/* You can use downto to iterate from an end value down to a start value. */
for (num in ender downto starter) {
    switch (num) {
    | num when num < 50 => print_endline("Full on Benjamin Buttoning now!");
    | num when num >= 50 => print_endline("Starting to Benjamin Button.");
    | _ => print_endline("Don't mind me");
    };
};

/* You can also use while loops in the same manner as you do in JS. */
let count = ref(1);
while (count < ref(5)) {
    print_endline("We are looping!");
    count := count^ + 1;
};

/* Use mutable bindings like above to break out of loops. Reason has no concept of a break keyword like JS. */

/* JSX */
/* Reason natively supports JSX. */
/* Calls like
    <div foo={bar}> child1 child2 </div>

become:
    ([@JSX] div(~foo=bar, ~children=[child1, child2], ()));
*/
/* The [@JSX] syntax flags a function as wanting to format as JSX. This allows any library in Reason, not just
ReasonReact, to take advantage of JSX. */

/* Externals */
/* Externals are how Reason communicates with other languages, often JS. */
/* One of the most common ways you use externals is to load modules. For example,
let's load the findS function from the findS module */
[@bs.module "./findS"] external findS : (string) => int = "";
let twoS = findS("strings");
print_int(twoS);

/* Sweet! We called a JS function from Reason! The annotations above allow us to
type the function findS from the findS module and return a typesafe reference to that module. */

/* Object */
/* Most of the time in Reason you'll be using a record to store named values. But sometimes, you'll want an object. Note than an object in
Reason is not the same as a JS object. Prefix public values on the
object with the pub keyword. */
let anUntypedReasonObject = {
    pub city = "Burlington";
    pub state = "Vermont";
};

print_endline(anUntypedReasonObject#city);

/* Reason objects don't need type definitions. If we do define them,
the object must have the shape of the type provided. */
type spot = {
    .
    city: string,
    state: string,
    population: int
};

let aTypedReasonObject: spot = {
    pub city = "Burlington";
    pub state = "Vermont";
    pub population = 56000;
};

print_int(aTypedReasonObject#population);

/* Two dots, known as elision, indicates that this object is open and
can have properties other than the originally typed properties. Open objects
are polymorphic and require a type parameter. */
type openPlace('a) = {
    ..
    getPlace: unit => string
} as 'a;

/* Objects in Reason have a this context, which points at the object itself. */
let vt: openPlace({. getPlace: unit => string }) = {
    val address = "100 Church St";
    val city = "Burlington";
    val zipCode = "05712";
    pub getPlace = () => address ++ ", " ++ city ++ " " ++ zipCode ++ ". " ++ this#addOn();
    pri addOn = () => "Didn't ya know?"
};

let spot = vt#getPlace();
print_endline(spot);

/* Module */
/* Modules in Reason can contain type defs, let bindings, nested modules, almost anything. Use the module keyword to create one. */
module Earth = {
    let continents = [|"Africa", "Antarctica", "Asia", "Australia", "Europe", "North America", "South America"|];
    let pickContinent = (idx: int) => continents[idx];
};

let aussie = Earth.pickContinent(3);
print_endline(aussie);

/* We can also access nested modules! Check out the Team module,
which has a nested Botson module. */
print_endline(Team.Boston.team);

/* While Reason has great module inference - no imports! - it can be
useful to explictly open a module. */
/* Local open - good for ease of reasoning. */
let fact = Team.Boston.(
    switch (team) {
    | "Red Sox" => "The Red Sox are DOPE."
    | _ => "Eh, don't really care."
    }
);
print_endline(fact);

/* Global open - good for getting everything in another module */
open Team.Boston;

/* Modules can also extend one another, fulfilling the role of inheritcance
or mixins in traditional OOP languages. */
module ExtendedBoston = {
    include Team.Boston;
    let basketball = "Celtics";
};

print_endline(ExtendedBoston.team);
print_endline(ExtendedBoston.basketball);

/* Exception */
/* Exceptions are a special kind of variant, and not used often in Reason. */
/* let aFunkyList = ["Parliament", "Funkadelic", "George Clinton"];
if (List.exists(item => item === "Stevie Wonder", aFunkyList)) {
    print_endline("Yay Stevie!");
} else {
    /* Here we raise the Not_found constructor of the Exception variant */
    raise(Not_found);
}; */