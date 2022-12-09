Nargo is the C function with fixed parameters.
  b - bark
  o - pith
  r - current Ray number
  t - current Ray text
  a - current text anchor

pith is the structure build by arrays.
it is array of four array and pointer to inner, similar, structure.

[ [], [], [], [], o ]

```c
N(sS      ) { D(B(T(prop),              T(),    T(),  T(),
                B(T("s", term, sS, sS), T(bo),  T(ε), T(ε),
                B(T(),                  T(),    T(),  T(), o))));
}
```
sS is the grammer specification. it must act like a streem
of parsed tokens and it must be rotatable by listener.
we have listener at the core of pith right in the middle.
and we have 

grammer variable is represented with three growing ring.
in first we have proppelers in each ray. so when execution 
will flow in any ring proppeler will iterate flow in inner ring rays.
It will use stack and return semantics.
| | | |
      | | | |   | | | |   | | | |   | | | |
            |         |   |         |
How and what to rotate?
