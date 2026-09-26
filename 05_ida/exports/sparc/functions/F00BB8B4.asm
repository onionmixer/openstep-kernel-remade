F00BB8B4: 9de3bf98                 save    %sp, -0x68, %sp
F00BB8B8: 113c04d4                 sethi   %hi(_cons_tp), %o0
F00BB8BC: e0022290                 ld      [%o0+%lo(_cons_tp)], %l0
F00BB8C0: d24c2047                 ldsb    [%l0+0x47], %o1
F00BB8C4: 912a6001                 sll     %o1, 1, %o0
F00BB8C8: 90020009                 add     %o0, %o1, %o0
F00BB8CC: 912a2004                 sll     %o0, 4, %o0
F00BB8D0: 133c042e921260cc         set     _linesw, %o1
F00BB8D8: 90020009                 add     %o0, %o1, %o0
F00BB8DC: d2022004                 ld      [%o0+4], %o1
F00BB8E0: 9fc24000                 call    %o1
F00BB8E4: 90100010                 mov     %l0, %o0
F00BB8E8: 7ffd712d                 call    _ttyclose
F00BB8EC: 90100010                 mov     %l0, %o0
F00BB8F0: 81c7e008                 ret
F00BB8F4: 91e82000                 restore %g0, 0, %o0
