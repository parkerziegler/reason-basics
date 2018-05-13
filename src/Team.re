type seattleVariant = Mariners | Sonics | Seahawks | Sounders;

type bostonVariant =
  | RedSox(string)
  | Celtics(string, int)
  | Patriots
  | Bruins;

module Boston = {
  let team = "Red Sox";
}