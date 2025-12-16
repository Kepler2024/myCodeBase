// problem 4:
// name:      ....... (fill in your name)
// s-number: s....... (fill in your student number)
// table:     ....... (fill in your table number)

method problem4(a: nat, b: nat, c: nat) returns (x: nat, y: nat, z: nat)
  ensures x <= y <= z
  ensures x + y + z == a + b + c
{
  x,y,z := a,b,c;
  while (x > y || y > z)
    invariant x+y+z == a + b + c
    decreases x,y
  {
    if x > y {
      x := x - 1;
      y := y + 1;
    }
    if y > z {
      y := y - 1;
      z := z + 1;
    }
  }
}