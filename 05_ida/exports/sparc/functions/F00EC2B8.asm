F00EC2B8: 9de3bf98                 save    %sp, -0x68, %sp
F00EC2BC: 80a62000                 cmp     %i0, 0
F00EC2C0: 12800006                 bne     loc_F00EC2D8
F00EC2C4: 90102000                 mov     0, %o0
F00EC2C8: 133c03e892126148         set     aReallocatingNi, %o1! "reallocating nil object"
F00EC2D0: 4000118c                 call    ___objc_error
F00EC2D4: 94102000                 mov     0, %o2
F00EC2D8: 40000fd8                 call    __objc_getFreedObjectClass
F00EC2DC: 01000000                 nop
F00EC2E0: d2060000                 ld      [%i0], %o1
F00EC2E4: 80a24008                 cmp     %o1, %o0
F00EC2E8: 32800008                 bne,a   loc_F00EC308
F00EC2EC: d0060000                 ld      [%i0], %o0
F00EC2F0: 90100018                 mov     %i0, %o0
F00EC2F4: 133c03e892126160         set     aReallocatingFr, %o1! "reallocating freed object"
F00EC2FC: 40001181                 call    ___objc_error
F00EC300: 94102000                 mov     0, %o2
F00EC304: d0060000                 ld      [%i0], %o0
F00EC308: d0022014                 ld      [%o0+0x14], %o0! id
F00EC30C: 80a64008                 cmp     %i1, %o0
F00EC310: 1a80000a                 bcc     loc_F00EC338
F00EC314: 01000000                 nop
F00EC318: 40000b9c                 call    _object_getClassName
F00EC31C: 90100018                 mov     %i0, %o0
F00EC320: 94100008                 mov     %o0, %o2
F00EC324: 90100018                 mov     %i0, %o0
F00EC328: 133c03e892126180         set     aSURequestedSiz, %o1! "(%s, %u) requested size too small"
F00EC330: 40001174                 call    ___objc_error
F00EC334: 96100019                 mov     %i1, %o3
F00EC338: 40000fc0                 call    __objc_getFreedObjectClass
F00EC33C: e0060000                 ld      [%i0], %l0
F00EC340: d0260000                 st      %o0, [%i0]
F00EC344: d6068000                 ld      [%i2], %o3
F00EC348: 9010001a                 mov     %i2, %o0! id
F00EC34C: 92100018                 mov     %i0, %o1
F00EC350: 9fc2c000                 call    %o3
F00EC354: 94100019                 mov     %i1, %o2
F00EC358: 80a22000                 cmp     %o0, 0
F00EC35C: 3280000c                 bne,a   loc_F00EC38C
F00EC360: e0220000                 st      %l0, [%o0]
F00EC364: 40000b89                 call    _object_getClassName
F00EC368: 90100018                 mov     %i0, %o0
F00EC36C: 94100008                 mov     %o0, %o2
F00EC370: 90100018                 mov     %i0, %o0
F00EC374: 133c03e892126128         set     aFailedOutOfMem, %o1! "failed -- out of memory(%s, %u)"
F00EC37C: 40001161                 call    ___objc_error
F00EC380: 96100019                 mov     %i1, %o3
F00EC384: 10800003                 ba      locret_F00EC390
F00EC388: b0102000                 mov     0, %i0
F00EC38C: b0100008                 mov     %o0, %i0
F00EC390: 81c7e008                 ret
F00EC394: 81e80000                 restore
