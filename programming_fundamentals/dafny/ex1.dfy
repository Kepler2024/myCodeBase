/* file     : exercise.dfy */
/* author   : Harry (qilin2603379191@gmail.com) */
/* version  : 1.0 */

ghost function f(n: nat): nat
{
  if n <= 1 then n else f(n-1) + f(n-2)
}

lemma lemmaFib(m: nat, n: nat)
  requires m >= 1 && n >= 1
  ensures  f(m + n - 1) == f(m) * f(n) + f(m - 1) * f(n - 1)
  decreases n
{
  if n == 1 {
    assert f(1) == 1;
    assert f(0) == 0;
    assert f(m + 1 - 1) == f(m);
    assert f(m) == f(m) * f(1) + f(m - 1) * f(0);
  } else if n == 2 {
    // Base case n=2
    assert f(2) == 1;
    assert f(1) == 1;
    assert f(0) == 0;
    assert f(m + 2 - 1) == f(m + 1);
    assert f(m + 1) == f(m) + f(m - 1);
    assert f(m + n - 1) == f(m) * f(2) + f(m - 1) * f(1);
  } else {
    // Inductive case n >= 3
    lemmaFib(m, n - 1);
    lemmaFib(m, n - 2);

    assert f(m + n - 1) == f(m + n - 2) + f(m + n - 3);

    assert f(m + n - 2) == f(m) * f(n - 1) + f(m - 1) * f(n - 2);
    assert f(m + n - 3) == f(m) * f(n - 2) + f(m - 1) * f(n - 3);

    assert f(m + n - 1) ==
      (f(m) * f(n - 1) + f(m - 1) * f(n - 2)) +
      (f(m) * f(n - 2) + f(m - 1) * f(n - 3));

    assert f(m + n - 1) ==
      f(m) * (f(n - 1) + f(n - 2)) +
      f(m - 1) * (f(n - 2) + f(n - 3));

    assert f(n) == f(n - 1) + f(n - 2);
    assert f(n - 1) == f(n - 2) + f(n - 3);
    assert f(m + n - 1) ==
      f(m) * f(n) + f(m - 1) * f(n - 1);
  }
}