/* file     : missing.dfy */
/* author   : Harry (qilin2603379191@gmail.com) */
/* date     : 2025/10/22 */
/* version  : 1.0 */
/* description:
 * Simple Dafny IO program to find the missing digit among 0..9.
 * Input: 9 digits (distinct, between 0..9).
 * Output: the missing digit.
 */

include "io.dfy"

method Main()
{
  var sum: int := 0;
  var i: int := 0;

  // loop to read exactly 9 digits
  while i < 9
    decreases 9 - i   // ensures termination
  {
    var d: nat := IO.ReadNat();
    sum := sum + d as int;
    i := i + 1;
  }

  // the sum of digits 0..9 is 45
  // missing digit = 45 - sum of input digits
  var missing := 45 - sum;
  
  print missing, "\n";
}