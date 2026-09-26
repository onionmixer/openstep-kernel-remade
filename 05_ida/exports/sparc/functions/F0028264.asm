F0028264: 9de3bf50                 save    %sp, -0xB0, %sp! int
F0028268: a0100018                 mov     %i0, %l0
F002826C: d0040000                 ld      [%l0], %o0
F0028270: 92102000                 mov     0, %o1
F0028274: 94100019                 mov     %i1, %o2! int
F0028278: 96102000                 mov     0, %o3! int
F002827C: 7ffff9d2                 call    _lookupname
F0028280: 9807bfb4                 add     %fp, var_4C, %o4! int
F0028284: b0920000                 orcc    %o0, %g0, %i0
F0028288: 1280000f                 bne     locret_F00282C4
F002828C: b207bfb8                 add     %fp, var_48, %i1
F0028290: d007bfb4                 ld      [%fp+var_4C], %o0
F0028294: 7ffff83e                 call    _vno_stat
F0028298: 92100019                 mov     %i1, %o1
F002829C: b0100008                 mov     %o0, %i0
F00282A0: 40000231                 call    _vn_rele
F00282A4: d007bfb4                 ld      [%fp+var_4C], %o0
F00282A8: 80a62000                 cmp     %i0, 0
F00282AC: 12800006                 bne     locret_F00282C4
F00282B0: 90100019                 mov     %i1, %o0! int
F00282B4: d2042004                 ld      [%l0+4], %o1! int
F00282B8: 4001bf85                 call    _copyout
F00282BC: 94102040                 mov     0x40, %o2 ! '@'
F00282C0: b0100008                 mov     %o0, %i0
F00282C4: 81c7e008                 ret
F00282C8: 81e80000                 restore
