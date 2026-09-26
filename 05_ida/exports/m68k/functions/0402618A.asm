0402618A: 4e56ffc4                 link    a6,#-$3C
0402618E: 2f2e0010                 move.l  arg_8(a6),-(sp)
04026192: 2f2e000c                 move.l  arg_4(a6),-(sp)
04026196: 486effc6                 pea     var_3A(a6)
0402619A: 2f2e0008                 move.l  arg_0(a6),-(sp)
0402619E: 61ff00000318             bsr.l   _nfsgetattr
040261A4: 4e5e                     unlk    a6
040261A6: 4e75                     rts
