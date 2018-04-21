/* commenting in Reason */

/* logging with Js */
Js.log("Hello, BuckleScript and Reason!");

/* character declaration - notice single quotes */
let x = 'x';
let y = 'y';

/* pattern matching a character */
let isXY = (char) =>
    switch (char) {
        | 'x' | 'y' => true
        | _ => false
    };

/* variable declaration and string concatenation */
let greeting = "hello";
let numGreeting = " P-Doo";
Js.log(greeting ++ numGreeting);

/* escape special characters */
let oneSlash = "\\";
Js.log(oneSlash);

/* multiline strings */
let multiLineString = {|Hello
Parkie
Doo|};
print_endline(multiLineString);

/* string interpolation */
let style = "background-color: papayawhip";
let cssStyle = {j|$style|j};
print_endline(cssStyle);

/* common string methods */
let length: int = String.length(greeting);
print_endline(string_of_int(length));

let sub: string = String.sub(greeting, 1, 3);
print_endline(sub);

/* if statements with block-scoping */
let displayGreeting = true;
if (displayGreeting) {
  let message = "Enjoying my ridiculous commentary yet";

  /* logging natively in Reason */
  print_endline(message);
};

/* anonymous scoping */
let anonScope = {
    let name = "Parker";
    let place = "Seattle";
    print_endline(name);
    print_endline(place);
};

/* name and place are inaccessible here b/c they are held
by anonScope above. attempting to access them will throw an error! */
/* print_endline(name);
print_endline(place); */

/* Types! */
/* we can alias types */
type flowerType = int;
let petalLength: int = 5;

/* and use aliases types */
let sepalLength: flowerType = 20;

/* and type function returns */
let flowerLength = (petal: int, sepal: int) : int => petal + sepal;

/* to print we need to call string_of_int to cast our int result to a string */
print_endline(string_of_int(flowerLength(petalLength, sepalLength)));

/* Boolean */
let myTuple = ("Parkie", "is", 1);
let compareBool = tuple => tuple === myTuple;
print_endline(string_of_bool(compareBool(myTuple)));

print_endline(string_of_bool(('M', 23) == ('M', 23)));
print_endline(string_of_bool(('M', 23) === ('M', 23)));

/* Integers and Floats */
/* Reason has concepts of both integers and floats
as opposed to just JS numbers */
let aGreatNumber: int = 20;
let sqaureInt = (num: int) : int => num * num;
print_endline(string_of_int(sqaureInt(aGreatNumber)));

/* floats have a unique operand syntax */
let aGreatFloat: float = 3.1415926;
let circleArea = (num: float) : float => aGreatFloat *. num *. num;
print_endline(string_of_float(circleArea(314.2)));

/* Tuples */
/* tuples are immutable, ordered, finite at creation, and of heterogeneous type
(though they can be all the same type */
let aDopeTuple: (char, string, int, string) = ('a', "Dope", 44, "tuple");
/* notice that tuple types just mimic the shape! */

/* there are special methods for getting tuple elements for tuples of length 2 */
let twoTuple: (string, string) = ("It", "Me");
let first: string = Pervasives.fst(twoTuple);
let second: string = Pervasives.snd(twoTuple);
print_endline(first);
print_endline(second);

/* most tuple elements are accessed using destructuring */
let (_, _, thirdIdx: int, _) = aDopeTuple;
print_endline(string_of_int(thirdIdx));

/* tuples are especially useful for pattern matching multiple possible combinations */
let rotate = (x, y) => {
    switch (x, y) {
    | (180, -180) => print_endline({j|rotate $x, $y|j})
    | (90, -90) => print_endline({j|turn $x, $y|j})
    }
};

rotate(180, -180);
rotate(90, -90);