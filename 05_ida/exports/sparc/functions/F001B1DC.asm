F001B1DC: 9de3bf98                 save    %sp, -0x68, %sp
F001B1E0: b00e20ff                 and     %i0, 0xFF, %i0
F001B1E4: b12e2004                 sll     %i0, 4, %i0
F001B1E8: 113c04bc90122204         set     unk_F012F204, %o0
F001B1F0: b0060008                 add     %i0, %o0, %i0
F001B1F4: d0062008                 ld      [%i0+8], %o0
F001B1F8: 80a22000                 cmp     %o0, 0
F001B1FC: 12800015                 bne     locret_F001B250
F001B200: 113c04d4                 sethi   %hi(_pty_alloc_lock), %o0
F001B204: a01222a0                 or      %o0, %lo(_pty_alloc_lock), %l0
F001B208: 400136ef                 call    _lock_write
F001B20C: 90100010                 mov     %l0, %o0
F001B210: d0062008                 ld      [%i0+8], %o0
F001B214: 80a22000                 cmp     %o0, 0
F001B218: 1280000c                 bne     loc_F001B248
F001B21C: 01000000                 nop
F001B220: 40013394                 call    _kalloc
F001B224: 90102088                 mov     0x88, %o0! void *
F001B228: d0262008                 st      %o0, [%i0+8]
F001B22C: 4001e70b                 call    _bzero
F001B230: 92102088                 mov     0x88, %o1! size_t
F001B234: 4001338f                 call    _kalloc
F001B238: 90102010                 mov     0x10, %o0! void *
F001B23C: d026200c                 st      %o0, [%i0+0xC]
F001B240: 4001e706                 call    _bzero
F001B244: 92102010                 mov     0x10, %o1
F001B248: 4001377b                 call    _lock_done
F001B24C: 90100010                 mov     %l0, %o0
F001B250: 81c7e008                 ret
F001B254: 81e80000                 restore
