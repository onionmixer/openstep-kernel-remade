F00CA884: 9de3bf90                 save    %sp, -0x70, %sp
F00CA888: e0062004                 ld      [%i0+4], %l0
F00CA88C: 7ffd8576                 call    _if_ipackets
F00CA890: 90100010                 mov     %l0, %o0
F00CA894: 9202001a                 add     %o0, %i2, %o1
F00CA898: 7ffd858b                 call    _if_ipackets_set
F00CA89C: 90100010                 mov     %l0, %o0
F00CA8A0: 81c7e008                 ret
F00CA8A4: 81e80000                 restore
