F00588FC: 9de3bf98                 save    %sp, -0x68, %sp
F0058900: a0062008                 add     %i0, 8, %l0
F0058904: d0040000                 ld      [%l0], %o0
F0058908: 80a22000                 cmp     %o0, 0
F005890C: 12bffffe                 bne     loc_F0058904
F0058910: 01000000                 nop
F0058914: 4000f965                 call    _simple_lock_try
F0058918: 90100010                 mov     %l0, %o0
F005891C: 80a22000                 cmp     %o0, 0
F0058920: 02bffff9                 be      loc_F0058904
F0058924: 01000000                 nop
F0058928: d006200c                 ld      [%i0+0xC], %o0
F005892C: 80a22000                 cmp     %o0, 0
F0058930: 0280004d                 be      loc_F0058A64
F0058934: 90100018                 mov     %i0, %o0
F0058938: 7fffec41                 call    _ipc_entry_lookup
F005893C: 92100019                 mov     %i1, %o1
F0058940: 92920000                 orcc    %o0, %g0, %o1
F0058944: 02800048                 be      loc_F0058A64
F0058948: 11000080                 sethi   0x20000, %o0
F005894C: d4024000                 ld      [%o1], %o2
F0058950: 808a8008                 btst    %o0, %o2
F0058954: 02800034                 be      loc_F0058A24
F0058958: f2026004                 ld      [%o1+4], %i1
F005895C: a0100019                 mov     %i1, %l0
F0058960: d0040000                 ld      [%l0], %o0
F0058964: 80a22000                 cmp     %o0, 0
F0058968: 12bffffe                 bne     loc_F0058960
F005896C: 01000000                 nop
F0058970: 4000f94e                 call    _simple_lock_try
F0058974: 90100010                 mov     %l0, %o0
F0058978: 80a22000                 cmp     %o0, 0
F005897C: 02bffff9                 be      loc_F0058960
F0058980: 01000000                 nop
F0058984: c0262008                 clr     [%i0+8]
F0058988: f0042030                 ld      [%l0+0x30], %i0
F005898C: 80a62000                 cmp     %i0, 0
F0058990: 22800039                 be,a    loc_F0058A74
F0058994: a0042040                 inc     0x40, %l0 ! '@'
F0058998: d0060000                 ld      [%i0], %o0
F005899C: 80a22000                 cmp     %o0, 0
F00589A0: 12bffffe                 bne     loc_F0058998
F00589A4: 01000000                 nop
F00589A8: 4000f940                 call    _simple_lock_try
F00589AC: 90100018                 mov     %i0, %o0
F00589B0: 80a22000                 cmp     %o0, 0
F00589B4: 02bffff9                 be      loc_F0058998
F00589B8: 01000000                 nop
F00589BC: d0062008                 ld      [%i0+8], %o0
F00589C0: 80a22000                 cmp     %o0, 0
F00589C4: 16800007                 bge     loc_F00589E0
F00589C8: 90100018                 mov     %i0, %o0
F00589CC: c0260000                 clr     [%i0]
F00589D0: c0240000                 clr     [%l0]
F00589D4: 31040010                 sethi   0x10004000, %i0
F00589D8: 10800036                 ba      locret_F0058AB0
F00589DC: b016200a                 bset    0xA, %i0
F00589E0: 40000b59                 call    _ipc_pset_remove
F00589E4: 92100010                 mov     %l0, %o1
F00589E8: d0062004                 ld      [%i0+4], %o0
F00589EC: c0260000                 clr     [%i0]
F00589F0: 80a22000                 cmp     %o0, 0
F00589F4: 1280000a                 bne     loc_F0058A1C
F00589F8: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F00589FC: d0062008                 ld      [%i0+8], %o0
F0058A00: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0058A04: 912a2001                 sll     %o0, 1, %o0
F0058A08: 91322011                 srl     %o0, 17, %o0
F0058A0C: 912a2002                 sll     %o0, 2, %o0
F0058A10: d0020009                 ld      [%o0+%o1], %o0
F0058A14: 400081ef                 call    _zfree
F0058A18: 92100018                 mov     %i0, %o1
F0058A1C: 10800016                 ba      loc_F0058A74
F0058A20: a0042040                 inc     0x40, %l0 ! '@'
F0058A24: 11000200                 sethi   0x80000, %o0
F0058A28: 808a8008                 btst    %o0, %o2
F0058A2C: 0280000e                 be      loc_F0058A64
F0058A30: a0100019                 mov     %i1, %l0
F0058A34: d0040000                 ld      [%l0], %o0
F0058A38: 80a22000                 cmp     %o0, 0
F0058A3C: 12bffffe                 bne     loc_F0058A34
F0058A40: 01000000                 nop
F0058A44: 4000f919                 call    _simple_lock_try
F0058A48: 90100010                 mov     %l0, %o0
F0058A4C: 80a22000                 cmp     %o0, 0
F0058A50: 02bffff9                 be      loc_F0058A34
F0058A54: 01000000                 nop
F0058A58: c0262008                 clr     [%i0+8]
F0058A5C: 10800006                 ba      loc_F0058A74
F0058A60: a0042010                 inc     0x10, %l0
F0058A64: c0262008                 clr     [%i0+8]
F0058A68: 31040010                 sethi   0x10004000, %i0
F0058A6C: 10800011                 ba      locret_F0058AB0
F0058A70: b0162002                 bset    2, %i0
F0058A74: d0066004                 ld      [%i1+4], %o0
F0058A78: 90022001                 inc     %o0
F0058A7C: d0266004                 st      %o0, [%i1+4]
F0058A80: d0040000                 ld      [%l0], %o0
F0058A84: 80a22000                 cmp     %o0, 0
F0058A88: 12bffffe                 bne     loc_F0058A80
F0058A8C: 01000000                 nop
F0058A90: 4000f906                 call    _simple_lock_try
F0058A94: 90100010                 mov     %l0, %o0
F0058A98: 80a22000                 cmp     %o0, 0
F0058A9C: 02bffff9                 be      loc_F0058A80
F0058AA0: b0102000                 mov     0, %i0
F0058AA4: c0264000                 clr     [%i1]
F0058AA8: f226c000                 st      %i1, [%i3]
F0058AAC: e0268000                 st      %l0, [%i2]
F0058AB0: 81c7e008                 ret
F0058AB4: 81e80000                 restore
