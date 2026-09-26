F00CA860: 9de3bf90                 save    %sp, -0x70, %sp
F00CA864: e0062004                 ld      [%i0+4], %l0
F00CA868: 7ffd857f                 call    _if_ipackets
F00CA86C: 90100010                 mov     %l0, %o0
F00CA870: 92022001                 add     %o0, 1, %o1
F00CA874: 7ffd8594                 call    _if_ipackets_set
F00CA878: 90100010                 mov     %l0, %o0
F00CA87C: 81c7e008                 ret
F00CA880: 81e80000                 restore
