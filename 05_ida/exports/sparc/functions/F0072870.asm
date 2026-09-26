F0072870: 9de3bf90                 save    %sp, -0x70, %sp
F0072874: 9210001a                 mov     %i2, %o1
F0072878: 113c04d0                 sethi   %hi(_active_threads), %o0
F007287C: 80a66001                 cmp     %i1, 1
F0072880: 0280000e                 be      loc_F00728B8
F0072884: e0022260                 ld      [%o0+%lo(_active_threads)], %l0
F0072888: 80a66001                 cmp     %i1, 1
F007288C: 14800007                 bg      loc_F00728A8
F0072890: 80a66002                 cmp     %i1, 2
F0072894: 80a66000                 cmp     %i1, 0
F0072898: 0280000f                 be      loc_F00728D4
F007289C: 80a62000                 cmp     %i0, 0
F00728A0: 10800066                 ba      locret_F0072A38
F00728A4: b0102004                 mov     4, %i0
F00728A8: 02800008                 be      loc_F00728C8
F00728AC: 01000000                 nop
F00728B0: 10800062                 ba      locret_F0072A38
F00728B4: b0102004                 mov     4, %i0
F00728B8: 40000062                 call    _thread_depress_priority
F00728BC: 90100010                 mov     %l0, %o0
F00728C0: 10800005                 ba      loc_F00728D4
F00728C4: 80a62000                 cmp     %i0, 0
F00728C8: 7fffcff8                 call    _thread_will_wait_with_timeout
F00728CC: 90100010                 mov     %l0, %o0
F00728D0: 80a62000                 cmp     %i0, 0
F00728D4: 02800048                 be      loc_F00729F4
F00728D8: 92100018                 mov     %i0, %o1
F00728DC: d004200c                 ld      [%l0+0xC], %o0
F00728E0: 94102000                 mov     0, %o2
F00728E4: d0022088                 ld      [%o0+0x88], %o0
F00728E8: 7fff9b7d                 call    _ipc_object_translate
F00728EC: 9607bff4                 add     %fp, var_C, %o3
F00728F0: a2920000                 orcc    %o0, %g0, %l1
F00728F4: 12800041                 bne     loc_F00729F8
F00728F8: 80a62000                 cmp     %i0, 0
F00728FC: d207bff4                 ld      [%fp+var_C], %o1
F0072900: d4026008                 ld      [%o1+8], %o2
F0072904: 80a2a000                 cmp     %o2, 0
F0072908: 16800038                 bge     loc_F00729E8
F007290C: d007bff4                 ld      [%fp+var_C], %o0
F0072910: 1100003f901223ff         set     0xFFFF, %o0
F0072918: 900a8008                 and     %o2, %o0, %o0
F007291C: 80a22001                 cmp     %o0, 1
F0072920: 12800032                 bne     loc_F00729E8
F0072924: d007bff4                 ld      [%fp+var_C], %o0
F0072928: 40009098                 call    _splusclock
F007292C: f2026014                 ld      [%o1+0x14], %i1
F0072930: b4100008                 mov     %o0, %i2
F0072934: b0066020                 add     %i1, 0x20, %i0 ! ' '
F0072938: d0060000                 ld      [%i0], %o0
F007293C: 80a22000                 cmp     %o0, 0
F0072940: 12bffffe                 bne     loc_F0072938
F0072944: 01000000                 nop
F0072948: 40009158                 call    _simple_lock_try
F007294C: 90100018                 mov     %i0, %o0
F0072950: 80a22000                 cmp     %o0, 0
F0072954: 02bffff9                 be      loc_F0072938
F0072958: 01000000                 nop
F007295C: d2066190                 ld      [%i1+0x190], %o1
F0072960: d0042190                 ld      [%l0+0x190], %o0
F0072964: 80a24008                 cmp     %o1, %o0
F0072968: 1280001c                 bne     loc_F00729D8
F007296C: 01000000                 nop
F0072970: 7ffffd24                 call    _rem_runq
F0072974: 90100019                 mov     %i1, %o0
F0072978: 80a22000                 cmp     %o0, 0
F007297C: 02800017                 be      loc_F00729D8
F0072980: 01000000                 nop
F0072984: c0266020                 clr     [%i1+0x20]
F0072988: 400090e7                 call    _splx
F007298C: 9010001a                 mov     %i2, %o0
F0072990: d007bff4                 ld      [%fp+var_C], %o0
F0072994: c0220000                 clr     [%o0]
F0072998: d0066060                 ld      [%i1+0x60], %o0
F007299C: 80a22002                 cmp     %o0, 2
F00729A0: 12800009                 bne     loc_F00729C4
F00729A4: 113c01ca                 sethi   -0xFF8D800, %o0
F00729A8: 113c04d2                 sethi   %hi(_processor_ptr), %o0
F00729AC: d20221b0                 ld      [%o0+%lo(_processor_ptr)], %o1
F00729B0: d006605c                 ld      [%i1+0x5C], %o0
F00729B4: d0226120                 st      %o0, [%o1+0x120]
F00729B8: 90102001                 mov     1, %o0
F00729BC: d0226124                 st      %o0, [%o1+0x124]
F00729C0: 113c01ca                 sethi   -0xFF8D800, %o0
F00729C4: 9012203c                 bset    0x3C, %o0 ! '<'
F00729C8: 7ffffb77                 call    _thread_run
F00729CC: 92100019                 mov     %i1, %o1
F00729D0: 10800014                 ba      loc_F0072A20
F00729D4: d0042064                 ld      [%l0+0x64], %o0
F00729D8: c0266020                 clr     [%i1+0x20]
F00729DC: 400090d2                 call    _splx
F00729E0: 9010001a                 mov     %i2, %o0
F00729E4: d007bff4                 ld      [%fp+var_C], %o0
F00729E8: c0220000                 clr     [%o0]
F00729EC: 1080000a                 ba      loc_F0072A14
F00729F0: 113c01ca                 sethi   -0xFF8D800, %o0
F00729F4: 80a62000                 cmp     %i0, 0
F00729F8: 02800006                 be      loc_F0072A10
F00729FC: 80a4600f                 cmp     %l1, 0xF
F0072A00: 12800005                 bne     loc_F0072A14
F0072A04: 113c01ca                 sethi   -0xFF8D800, %o0
F0072A08: 1080000c                 ba      locret_F0072A38
F0072A0C: b0102004                 mov     4, %i0
F0072A10: 113c01ca                 sethi   -0xFF8D800, %o0
F0072A14: 7ffffb4b                 call    _thread_block_with_continuation
F0072A18: 9012203c                 bset    0x3C, %o0 ! '<'
F0072A1C: d0042064                 ld      [%l0+0x64], %o0! thread
F0072A20: 80a22000                 cmp     %o0, 0
F0072A24: 06800005                 bl      locret_F0072A38
F0072A28: b0102000                 mov     0, %i0
F0072A2C: 4000004a                 call    _thread_depress_abort
F0072A30: 90100010                 mov     %l0, %o0
F0072A34: b0102000                 mov     0, %i0
F0072A38: 81c7e008                 ret
F0072A3C: 81e80000                 restore
