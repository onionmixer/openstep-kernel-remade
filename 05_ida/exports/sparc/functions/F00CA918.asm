F00CA918: 9de3bf90                 save    %sp, -0x70, %sp
F00CA91C: e0062004                 ld      [%i0+4], %l0
F00CA920: 7ffd854d                 call    _if_opackets
F00CA924: 90100010                 mov     %l0, %o0
F00CA928: 92022001                 add     %o0, 1, %o1
F00CA92C: 7ffd8562                 call    _if_opackets_set
F00CA930: 90100010                 mov     %l0, %o0
F00CA934: 81c7e008                 ret
F00CA938: 81e80000                 restore
