F004D6D4: 9de3bf98                 save    %sp, -0x68, %sp
F004D6D8: 113c04d0                 sethi   %hi(_active_threads), %o0
F004D6DC: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F004D6E0: 7ffffe8f                 call    sub_F004D11C
F004D6E4: 90100018                 mov     %i0, %o0
F004D6E8: d006200c                 ld      [%i0+0xC], %o0
F004D6EC: 80a22000                 cmp     %o0, 0
F004D6F0: 16800008                 bge     loc_F004D710
F004D6F4: 80a42000                 cmp     %l0, 0
F004D6F8: 133c04eb                 sethi   %hi(_ds_call), %o1
F004D6FC: d4026180                 ld      [%o1+%lo(_ds_call)], %o2
F004D700: 90100018                 mov     %i0, %o0
F004D704: 9fc28000                 call    %o2
F004D708: 92100019                 mov     %i1, %o1
F004D70C: 30800008                 ba,a    locret_F004D72C
F004D710: 02800005                 be      loc_F004D724
F004D714: 90100018                 mov     %i0, %o0
F004D718: d0042050                 ld      [%l0+0x50], %o0
F004D71C: d026603c                 st      %o0, [%i1+0x3C]
F004D720: 90100018                 mov     %i0, %o0
F004D724: 7fffff4c                 call    sub_F004D454
F004D728: 92100019                 mov     %i1, %o1
F004D72C: 81c7e008                 ret
F004D730: 81e80000                 restore
