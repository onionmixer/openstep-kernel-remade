F00147B4: 9de3bf98                 save    %sp, -0x68, %sp
F00147B8: f427a04c                 st      %i2, [%fp+arg_4C]
F00147BC: f627a050                 st      %i3, [%fp+arg_50]
F00147C0: f827a054                 st      %i4, [%fp+arg_54]
F00147C4: 400208f1                 call    _splusclock
F00147C8: fa27a058                 st      %i5, [%fp+arg_58]
F00147CC: b4100008                 mov     %o0, %i2
F00147D0: 40000026                 call    sub_F0014868
F00147D4: 90100018                 mov     %i0, %o0
F00147D8: 90100019                 mov     %i1, %o0
F00147DC: b007a04c                 add     %fp, arg_4C, %i0
F00147E0: 92100018                 mov     %i0, %o1
F00147E4: 94102004                 mov     4, %o2
F00147E8: 40000039                 call    _prf
F00147EC: 96102000                 mov     0, %o3
F00147F0: 4002094d                 call    _splx
F00147F4: 9010001a                 mov     %i2, %o0
F00147F8: 113c04d4                 sethi   %hi(_log_open), %o0
F00147FC: d0022178                 ld      [%o0+%lo(_log_open)], %o0
F0014800: 80a22000                 cmp     %o0, 0
F0014804: 12800006                 bne     loc_F001481C
F0014808: 90100019                 mov     %i1, %o0
F001480C: 92100018                 mov     %i0, %o1
F0014810: 94102001                 mov     1, %o2
F0014814: 4000002e                 call    _prf
F0014818: 96102000                 mov     0, %o3
F001481C: 7fffff16                 call    _logwakeup
F0014820: b0102000                 mov     0, %i0
F0014824: 40020940                 call    _splx
F0014828: 9010001a                 mov     %i2, %o0
F001482C: 81c7e008                 ret
F0014830: 81e80000                 restore
