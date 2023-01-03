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
How and what (streams) to rotate?
in georgian rotation is essential for the words.
we need to rotate core of the word.
georgian verbs defines structure of the sentence. 
== mamam shvils sakhli aushena. ==
== aushena mamam shvils sakhli. ==
== sakhli aushena mamam shvils. ==
== shvils sakhli aushena mamam. ==
mamam  aushena
shvils aushena
sakhli aushena

mamam.aushena(shvils, sakhli)
aushena(mamam, shvils, sakhli)

        shvils  ____  ____  cccc  ____
        sakhli  ____  bbbb  ____  ____
        shvils  ____  ____  cccc  ____
                sakhli  ____  bbbb  ____  ____
                mamam   aaaa  ____  ____  ____
                aushena ____  ____  ____  ____
                .                             
        mamam   aaaa  ____  ____  ____
        aushena ____  ____  ____  ____
        .       
stream
stream is tuple of (operation, opened_event, closed_event)
