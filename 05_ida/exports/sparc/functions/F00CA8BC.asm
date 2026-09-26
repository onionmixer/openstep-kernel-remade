F00CA8BC: 9de3bf90                 save    %sp, -0x70, %sp
F00CA8C0: e0062004                 ld      [%i0+4], %l0
F00CA8C4: 7ffd8570                 call    _if_ierrors
F00CA8C8: 90100010                 mov     %l0, %o0
F00CA8CC: 92022001                 add     %o0, 1, %o1
F00CA8D0: 7ffd8585                 call    _if_ierrors_set
F00CA8D4: 90100010                 mov     %l0, %o0
F00CA8D8: 81c7e008                 ret
F00CA8DC: 81e80000                 restore
