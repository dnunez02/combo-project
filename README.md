combo-project
=============

Some way to document fighting game combos.

TODO: Find a decent representation for attacks and movements.

May use base 10, read left to right [i.e. translate from Capcom notation to numpad notation]
However, is there a better one?

Movements:

|     |     |     |
|:---:|:---:|:---:|
| JB  |  J  | JF  |
|  B  |  S  |  F  |
| CB  |  C  | CF  |

QCF, QCB, HCF, HCB, 360, FF (dash), BB(dash), CJ (superjump), DP (dragon punch: F -> C -> CF), xx (cancels)

Attacks:

(Could use base 6 interpretation)

|    |    |    |
|:--:|:--:|:--:|
| LP | MP | HP |
| LK | MK | HK |

P (any punch), K (any kick), PP, KK, combinations of attacks (e.g. LP+LK)

Must allow for custom combinations of buttons unique to characers. (e.g. Stancels (QCF.P+K), Fly, etc.)

TODO: Parse a full combo in Capcom notation (e.g. s.LP, c.MK, s.HP, j.LK, j.MK, QCB.HK, QCF.PP)
