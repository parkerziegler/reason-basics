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
/* Coonditionals work similarly to JavaScript */
let displayGreeting = true;
if (displayGreeting) {
  let message = "Enjoying my ridiculous commentary yet?";
  print_endline(message);
};

/* Ifs can be written and evaluated inline, and are evaluated to
their body content – their is no need for a return statement */
let goodRT = true;
let content = if (goodRT) {
    "This tweet has good RT."
} else {
    "This tweet has bad RT."
};
print_endline(content);

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