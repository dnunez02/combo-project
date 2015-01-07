combo-project
=============

Some way to document fighting game combos.

Uses a base 10, read left to right [i.e. translate from Capcom notation to numpad notation]
However, is there a better one?

Movements:

|     |     |     |
|:---:|:---:|:---:|
| JB  |  J  | JF  |
|  B  |  S  |  F  |
| CB  |  C  | CF  |

QCF, QCB, HCF, HCB, 360, FF (dash), BB(dash), CJ (superjump), DP (dragon punch: F -> C -> CF), xx (cancels)

Attacks:

Uses an octal representation.

|    |    |    |    |
|:--:|:--:|:--:|:--:|
| LP | MP | HP | P  |
| LK | MK | HK | K  |

P (any punch), K (any kick), PP, KK, combinations of attacks (e.g. LP+LK)

Must allow for custom combinations of buttons unique to characers. (e.g. Stancels (QCF.P+K), Fly, etc.)

Can parse a full combo in Capcom notation with notes and print back in numerical notation (e.g. s.LP, c.MK, s.HP, j.LK, j.MK, QCB.HK, QCF.PP)

Current Grammar for a Combo
```
COMBO := MOVE | MOVE,COMBO
MOVE := DIR.ATTACK NOTE | DIR | ATTACK
DIR := jb | j | jf | b | s | f | cb | c | cf
ATK := lp | mp | hp | p | lk | mk | hk | k
NOTE := EMPTY | (STRING)
STRING := EMPTY | Combinations of letters, punctuation, numbers, etc.
EMPTY := nothing at all
```
