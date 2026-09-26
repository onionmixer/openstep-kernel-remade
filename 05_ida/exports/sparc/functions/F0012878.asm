F0012878: 9de3bf98                 save    %sp, -0x68, %sp
F001287C: 233c04cf                 sethi   %hi(_active_u), %l1
F0012880: d00461d8                 ld      [%l1+%lo(_active_u)], %o0
F0012884: 400210c1                 call    _splusclock
F0012888: e0020000                 ld      [%o0], %l0
F001288C: 80a42000                 cmp     %l0, 0
F0012890: 02800004                 be      loc_F00128A0
F0012894: a4100008                 mov     %o0, %l2
F0012898: 900e607f                 and     %i1, 0x7F, %o0
F001289C: d02c2011                 stb     %o0, [%l0+0x11]
F00128A0: 80a66019                 cmp     %i1, 0x19
F00128A4: 34800003                 bg,a    loc_F00128B0
F00128A8: 92102001                 mov     1, %o1
F00128AC: 92102000                 mov     0, %o1
F00128B0: 40017909                 call    _assert_wait
F00128B4: 90100018                 mov     %i0, %o0
F00128B8: 80a66019                 cmp     %i1, 0x19
F00128BC: 04800054                 ble     loc_F0012A0C
F00128C0: 80a42000                 cmp     %l0, 0
F00128C4: 02800024                 be      loc_F0012954
F00128C8: 113c04d0                 sethi   %hi(_active_threads), %o0
F00128CC: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F00128D0: d002618c                 ld      [%o1+0x18C], %o0
F00128D4: 808a2003                 btst    3, %o0
F00128D8: 12800017                 bne     loc_F0012934
F00128DC: 113c04d0                 sethi   -0xFECC000, %o0
F00128E0: d0026084                 ld      [%o1+0x84], %o0
F00128E4: d2042018                 ld      [%l0+0x18], %o1
F00128E8: d002204c                 ld      [%o0+0x4C], %o0
F00128EC: 94924008                 orcc    %o1, %o0, %o2
F00128F0: 02800019                 be      loc_F0012954
F00128F4: 01000000                 nop
F00128F8: d0042028                 ld      [%l0+0x28], %o0
F00128FC: 808a2010                 btst    0x10, %o0
F0012900: 12800008                 bne     loc_F0012920
F0012904: 01000000                 nop
F0012908: d0042020                 ld      [%l0+0x20], %o0
F001290C: d204201c                 ld      [%l0+0x1C], %o1
F0012910: 90120009                 bset    %o1, %o0
F0012914: 80aa8008                 andncc  %o2, %o0, %g0
F0012918: 0280000f                 be      loc_F0012954
F001291C: 01000000                 nop
F0012920: 7ffffc24                 call    _issig
F0012924: 90102001                 mov     1, %o0
F0012928: 80a22000                 cmp     %o0, 0
F001292C: 0280000a                 be      loc_F0012954
F0012930: 113c04d0                 sethi   -0xFECC000, %o0
F0012934: d0022260                 ld      [%o0+0x260], %o0
F0012938: 92102002                 mov     2, %o1
F001293C: 4001793d                 call    _clear_wait
F0012940: 94102001                 mov     1, %o2
F0012944: 400210e7                 call    _spl0
F0012948: 01000000                 nop
F001294C: 10800043                 ba      loc_F0012A58
F0012950: 80a6a000                 cmp     %i2, 0
F0012954: 400210e3                 call    _spl0
F0012958: 01000000                 nop
F001295C: 113c04cf                 sethi   %hi(_active_u), %o0
F0012960: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F0012964: 113c04d0                 sethi   %hi(_master_cpu), %o0
F0012968: d20220c8                 ld      [%o0+%lo(_master_cpu)], %o1
F001296C: d002a1ac                 ld      [%o2+0x1AC], %o0
F0012970: 80a26000                 cmp     %o1, 0
F0012974: 90022001                 inc     %o0
F0012978: 02800005                 be      loc_F001298C
F001297C: d022a1ac                 st      %o0, [%o2+0x1AC]
F0012980: 113c042c                 sethi   %hi(aUnixSleepOnSla), %o0! "unix sleep: on slave?\n"
F0012984: 40000735                 call    _printf
F0012988: 901222f0                 bset    %lo(aUnixSleepOnSla), %o0! "unix sleep: on slave?\n"
F001298C: 40017b6d                 call    _thread_block_with_continuation
F0012990: 9010001a                 mov     %i2, %o0
F0012994: 80a42000                 cmp     %l0, 0
F0012998: 0280002c                 be      loc_F0012A48
F001299C: 113c04d0                 sethi   %hi(_active_threads), %o0
F00129A0: d2022260                 ld      [%o0+%lo(_active_threads)], %o1
F00129A4: d002618c                 ld      [%o1+0x18C], %o0
F00129A8: 808a2003                 btst    3, %o0
F00129AC: 1280002b                 bne     loc_F0012A58
F00129B0: 80a6a000                 cmp     %i2, 0
F00129B4: d0026084                 ld      [%o1+0x84], %o0
F00129B8: d2042018                 ld      [%l0+0x18], %o1
F00129BC: d002204c                 ld      [%o0+0x4C], %o0
F00129C0: 94924008                 orcc    %o1, %o0, %o2
F00129C4: 02800021                 be      loc_F0012A48
F00129C8: 01000000                 nop
F00129CC: d0042028                 ld      [%l0+0x28], %o0
F00129D0: 808a2010                 btst    0x10, %o0
F00129D4: 12800008                 bne     loc_F00129F4
F00129D8: 01000000                 nop
F00129DC: d0042020                 ld      [%l0+0x20], %o0
F00129E0: d204201c                 ld      [%l0+0x1C], %o1
F00129E4: 90120009                 bset    %o1, %o0
F00129E8: 80aa8008                 andncc  %o2, %o0, %g0
F00129EC: 02800017                 be      loc_F0012A48
F00129F0: 01000000                 nop
F00129F4: 7ffffbef                 call    _issig
F00129F8: 90102001                 mov     1, %o0
F00129FC: 80a22000                 cmp     %o0, 0
F0012A00: 12800016                 bne     loc_F0012A58
F0012A04: 80a6a000                 cmp     %i2, 0
F0012A08: 30800010                 ba,a    loc_F0012A48
F0012A0C: 400210b5                 call    _spl0
F0012A10: 01000000                 nop
F0012A14: d40461d8                 ld      [%l1+0x1D8], %o2
F0012A18: 113c04d0                 sethi   %hi(_master_cpu), %o0
F0012A1C: d20220c8                 ld      [%o0+%lo(_master_cpu)], %o1! int
F0012A20: d002a1ac                 ld      [%o2+0x1AC], %o0
F0012A24: 80a26000                 cmp     %o1, 0
F0012A28: 90022001                 inc     %o0
F0012A2C: 02800005                 be      loc_F0012A40
F0012A30: d022a1ac                 st      %o0, [%o2+0x1AC]
F0012A34: 113c042c                 sethi   %hi(aUnixSleepOnSla_0), %o0! "unix sleep: on slave?\n"
F0012A38: 40000708                 call    _printf
F0012A3C: 90122308                 bset    %lo(aUnixSleepOnSla_0), %o0! "unix sleep: on slave?\n"
F0012A40: 40017b40                 call    _thread_block_with_continuation
F0012A44: 9010001a                 mov     %i2, %o0
F0012A48: 400210b7                 call    _splx
F0012A4C: 90100012                 mov     %l2, %o0
F0012A50: 1080000d                 ba      locret_F0012A84
F0012A54: b0102000                 mov     0, %i0
F0012A58: 02800005                 be      loc_F0012A6C
F0012A5C: 808e6100                 btst    0x100, %i1
F0012A60: 40020821                 call    _call_continuation
F0012A64: 9010001a                 mov     %i2, %o0
F0012A68: 808e6100                 btst    0x100, %i1
F0012A6C: 12800006                 bne     locret_F0012A84
F0012A70: b0102001                 mov     1, %i0
F0012A74: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0012A78: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0! jmp_buf
F0012A7C: 400210ba                 call    _longjmp
F0012A80: 90022028                 inc     0x28, %o0 ! '('
F0012A84: 81c7e008                 ret
F0012A88: 81e80000                 restore
