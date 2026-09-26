F0074894: 9de3bf98                 save    %sp, -0x68, %sp
F0074898: 213c04d0                 sethi   %hi(_active_threads), %l0
F007489C: 80a62000                 cmp     %i0, 0
F00748A0: 12800004                 bne     loc_F00748B0
F00748A4: e4042260                 ld      [%l0+%lo(_active_threads)], %l2
F00748A8: 10800086                 ba      locret_F0074AC0
F00748AC: b0102004                 mov     4, %i0
F00748B0: 7fffc969                 call    _ipc_thread_disable
F00748B4: 90100018                 mov     %i0, %o0
F00748B8: 80a60012                 cmp     %i0, %l2
F00748BC: 12800020                 bne     loc_F007493C
F00748C0: d0042260                 ld      [%l0+0x260], %o0
F00748C4: 400088b1                 call    _splusclock
F00748C8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00748CC: a6100008                 mov     %o0, %l3
F00748D0: d0040000                 ld      [%l0], %o0
F00748D4: 80a22000                 cmp     %o0, 0
F00748D8: 12bffffe                 bne     loc_F00748D0
F00748DC: 01000000                 nop
F00748E0: 40008972                 call    _simple_lock_try
F00748E4: 90100010                 mov     %l0, %o0
F00748E8: 80a22000                 cmp     %o0, 0
F00748EC: 02bffff9                 be      loc_F00748D0
F00748F0: 01000000                 nop
F00748F4: d0062188                 ld      [%i0+0x188], %o0
F00748F8: 80a22000                 cmp     %o0, 0
F00748FC: 02800006                 be      loc_F0074914
F0074900: 01000000                 nop
F0074904: d006218c                 ld      [%i0+0x18C], %o0
F0074908: c0262188                 clr     [%i0+0x188]
F007490C: 90122002                 bset    2, %o0
F0074910: d026218c                 st      %o0, [%i0+0x18C]
F0074914: c0262020                 clr     [%i0+0x20]
F0074918: 113c04cf                 sethi   %hi(_need_ast), %o0
F007491C: d2022160                 ld      [%o0+%lo(_need_ast)], %o1
F0074920: 92126002                 bset    2, %o1
F0074924: d2222160                 st      %o1, [%o0+%lo(_need_ast)]
F0074928: d0022160                 ld      [%o0+%lo(_need_ast)], %o0
F007492C: 400088fe                 call    _splx
F0074930: 90100013                 mov     %l3, %o0
F0074934: 10800063                 ba      locret_F0074AC0
F0074938: b0102000                 mov     0, %i0
F007493C: e202200c                 ld      [%o0+0xC], %l1
F0074940: d0044000                 ld      [%l1], %o0
F0074944: 80a22000                 cmp     %o0, 0
F0074948: 12bffffe                 bne     loc_F0074940
F007494C: 01000000                 nop
F0074950: 40008956                 call    _simple_lock_try
F0074954: 90100011                 mov     %l1, %o0
F0074958: 80a22000                 cmp     %o0, 0
F007495C: 02bffff9                 be      loc_F0074940
F0074960: 01000000                 nop
F0074964: 40008889                 call    _splusclock
F0074968: 01000000                 nop
F007496C: 80a60012                 cmp     %i0, %l2
F0074970: 1a800018                 bcc     loc_F00749D0
F0074974: a6100008                 mov     %o0, %l3
F0074978: a0062020                 add     %i0, 0x20, %l0 ! ' '
F007497C: d0040000                 ld      [%l0], %o0
F0074980: 80a22000                 cmp     %o0, 0
F0074984: 12bffffe                 bne     loc_F007497C
F0074988: 01000000                 nop
F007498C: 40008947                 call    _simple_lock_try
F0074990: 90100010                 mov     %l0, %o0
F0074994: 80a22000                 cmp     %o0, 0
F0074998: 02bffff9                 be      loc_F007497C
F007499C: 01000000                 nop
F00749A0: a004a020                 add     %l2, 0x20, %l0 ! ' '
F00749A4: d0040000                 ld      [%l0], %o0
F00749A8: 80a22000                 cmp     %o0, 0
F00749AC: 12bffffe                 bne     loc_F00749A4
F00749B0: 01000000                 nop
F00749B4: 4000893d                 call    _simple_lock_try
F00749B8: 90100010                 mov     %l0, %o0
F00749BC: 80a22000                 cmp     %o0, 0
F00749C0: 02bffff9                 be      loc_F00749A4
F00749C4: 01000000                 nop
F00749C8: 10800017                 ba      loc_F0074A24
F00749CC: d0046008                 ld      [%l1+8], %o0
F00749D0: a004a020                 add     %l2, 0x20, %l0 ! ' '
F00749D4: d0040000                 ld      [%l0], %o0
F00749D8: 80a22000                 cmp     %o0, 0
F00749DC: 12bffffe                 bne     loc_F00749D4
F00749E0: 01000000                 nop
F00749E4: 40008931                 call    _simple_lock_try
F00749E8: 90100010                 mov     %l0, %o0
F00749EC: 80a22000                 cmp     %o0, 0
F00749F0: 02bffff9                 be      loc_F00749D4
F00749F4: 01000000                 nop
F00749F8: a0062020                 add     %i0, 0x20, %l0 ! ' '
F00749FC: d0040000                 ld      [%l0], %o0
F0074A00: 80a22000                 cmp     %o0, 0
F0074A04: 12bffffe                 bne     loc_F00749FC
F0074A08: 01000000                 nop
F0074A0C: 40008927                 call    _simple_lock_try
F0074A10: 90100010                 mov     %l0, %o0
F0074A14: 80a22000                 cmp     %o0, 0
F0074A18: 02bffff9                 be      loc_F00749FC
F0074A1C: 01000000                 nop
F0074A20: d0046008                 ld      [%l1+8], %o0
F0074A24: 80a22000                 cmp     %o0, 0
F0074A28: 02800006                 be      loc_F0074A40
F0074A2C: 01000000                 nop
F0074A30: d004a188                 ld      [%l2+0x188], %o0
F0074A34: 80a22000                 cmp     %o0, 0
F0074A38: 1280000b                 bne     loc_F0074A64
F0074A3C: 01000000                 nop
F0074A40: c024a020                 clr     [%l2+0x20]
F0074A44: c0262020                 clr     [%i0+0x20]
F0074A48: 400088b7                 call    _splx
F0074A4C: 90100013                 mov     %l3, %o0! target_act
F0074A50: c0244000                 clr     [%l1]
F0074A54: 7fffff90                 call    _thread_terminate
F0074A58: 90100012                 mov     %l2, %o0
F0074A5C: 10800019                 ba      locret_F0074AC0
F0074A60: b0102005                 mov     5, %i0
F0074A64: c024a020                 clr     [%l2+0x20]
F0074A68: c0244000                 clr     [%l1]
F0074A6C: d0062188                 ld      [%i0+0x188], %o0
F0074A70: 80a22000                 cmp     %o0, 0
F0074A74: 0280000f                 be      loc_F0074AB0
F0074A78: 01000000                 nop
F0074A7C: c0262188                 clr     [%i0+0x188]
F0074A80: c0262020                 clr     [%i0+0x20]
F0074A84: 400088a8                 call    _splx
F0074A88: 90100013                 mov     %l3, %o0
F0074A8C: 90100018                 mov     %i0, %o0
F0074A90: 4000002e                 call    _thread_halt
F0074A94: 92102001                 mov     1, %o1
F0074A98: 7fffc903                 call    _ipc_thread_terminate
F0074A9C: 90100018                 mov     %i0, %o0
F0074AA0: 7ffffe43                 call    _thread_deallocate
F0074AA4: 90100018                 mov     %i0, %o0
F0074AA8: 10800006                 ba      locret_F0074AC0
F0074AAC: b0102000                 mov     0, %i0
F0074AB0: c0262020                 clr     [%i0+0x20]
F0074AB4: 4000889c                 call    _splx
F0074AB8: 90100013                 mov     %l3, %o0
F0074ABC: b0102005                 mov     5, %i0
F0074AC0: 81c7e008                 ret
F0074AC4: 81e80000                 restore
