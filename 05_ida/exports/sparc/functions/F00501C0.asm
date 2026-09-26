F00501C0: 9de3bf98                 save    %sp, -0x68, %sp
F00501C4: d0062024                 ld      [%i0+0x24], %o0
F00501C8: 92100019                 mov     %i1, %o1
F00501CC: 80a24008                 cmp     %o1, %o0
F00501D0: 1a800004                 bcc     loc_F00501E0
F00501D4: 113c043b                 sethi   -0xFEF1400, %o0! char *
F00501D8: 10800009                 ba      locret_F00501FC
F00501DC: b0102000                 mov     0, %i0
F00501E0: 7fff111e                 call    _printf
F00501E4: 90122158                 bset    0x158, %o0
F00501E8: 90100018                 mov     %i0, %o0
F00501EC: 133c043b                 sethi   %hi(aBadBlock), %o1! "bad block"
F00501F0: 7fffea38                 call    _fserr
F00501F4: 92126168                 bset    %lo(aBadBlock), %o1! "bad block"
F00501F8: b0102001                 mov     1, %i0
F00501FC: 81c7e008                 ret
F0050200: 81e80000                 restore
