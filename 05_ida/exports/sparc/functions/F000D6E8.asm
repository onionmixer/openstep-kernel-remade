F000D6E8: 9de3bf98                 save    %sp, -0x68, %sp
F000D6EC: 40000528                 call    _alloc_posix_proc
F000D6F0: a0102000                 mov     0, %l0
F000D6F4: 133c04cf                 sethi   %hi(_active_u), %o1
F000D6F8: d20261d8                 ld      [%o1+%lo(_active_u)], %o1
F000D6FC: d202601c                 ld      [%o1+0x1C], %o1
F000D700: d2526002                 ldsh    [%o1+2], %o1
F000D704: 80a26000                 cmp     %o1, 0
F000D708: 0280001f                 be      loc_F000D784
F000D70C: a8100008                 mov     %o0, %l4
F000D710: 113c04d3                 sethi   %hi(_allproc), %o0
F000D714: e4022278                 ld      [%o0+%lo(_allproc)], %l2
F000D718: 80a4a000                 cmp     %l2, 0
F000D71C: 0280000b                 be      loc_F000D748
F000D720: 113c04d3                 sethi   -0xFECB400, %o0
F000D724: d054a02c                 ldsh    [%l2+0x2C], %o0
F000D728: 80a20009                 cmp     %o0, %o1
F000D72C: 22800002                 be,a    loc_F000D734
F000D730: a0042001                 inc     %l0
F000D734: e404a008                 ld      [%l2+8], %l2
F000D738: 80a4a000                 cmp     %l2, 0
F000D73C: 32bffffb                 bne,a   loc_F000D728
F000D740: d054a02c                 ldsh    [%l2+0x2C], %o0
F000D744: 113c04d3                 sethi   -0xFECB400, %o0
F000D748: e4022270                 ld      [%o0+0x270], %l2
F000D74C: 80a4a000                 cmp     %l2, 0
F000D750: 0280000d                 be      loc_F000D784
F000D754: 113c04cf                 sethi   %hi(_active_u), %o0
F000D758: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000D75C: d002201c                 ld      [%o0+0x1C], %o0
F000D760: d2522002                 ldsh    [%o0+2], %o1
F000D764: d054a02c                 ldsh    [%l2+0x2C], %o0
F000D768: 80a20009                 cmp     %o0, %o1
F000D76C: 22800002                 be,a    loc_F000D774
F000D770: a0042001                 inc     %l0
F000D774: e404a008                 ld      [%l2+8], %l2
F000D778: 80a4a000                 cmp     %l2, 0
F000D77C: 32bffffb                 bne,a   loc_F000D768
F000D780: d054a02c                 ldsh    [%l2+0x2C], %o0
F000D784: 233c04d2                 sethi   %hi(_freeproc), %l1
F000D788: e60462e0                 ld      [%l1+%lo(_freeproc)], %l3
F000D78C: 80a4e000                 cmp     %l3, 0
F000D790: 1280000f                 bne     loc_F000D7CC
F000D794: 01000000                 nop
F000D798: 4000036a                 call    _getproc
F000D79C: 01000000                 nop
F000D7A0: a6920000                 orcc    %o0, %g0, %l3
F000D7A4: 12800007                 bne     loc_F000D7C0
F000D7A8: d00462e0                 ld      [%l1+%lo(_freeproc)], %o0
F000D7AC: 113c042c                 sethi   %hi(aProc), %o0! "proc"
F000D7B0: 40001ea9                 call    _tablefull
F000D7B4: 90122078                 bset    %lo(aProc), %o0! "proc"
F000D7B8: 10800005                 ba      loc_F000D7CC
F000D7BC: 80a4e000                 cmp     %l3, 0
F000D7C0: d024e008                 st      %o0, [%l3+8]
F000D7C4: e62462e0                 st      %l3, [%l1+0x2E0]
F000D7C8: 80a4e000                 cmp     %l3, 0
F000D7CC: 0280000a                 be      loc_F000D7F4
F000D7D0: 113c04cf                 sethi   %hi(_active_u), %o0
F000D7D4: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F000D7D8: d002201c                 ld      [%o0+0x1C], %o0
F000D7DC: d0522002                 ldsh    [%o0+2], %o0
F000D7E0: 80a22000                 cmp     %o0, 0
F000D7E4: 0280000b                 be      loc_F000D810
F000D7E8: 80a42064                 cmp     %l0, 0x64 ! 'd'
F000D7EC: 0480000a                 ble     loc_F000D814
F000D7F0: 233c04cf                 sethi   -0xFECC400, %l1
F000D7F4: 400004f0                 call    _free_posix_proc
F000D7F8: 90100014                 mov     %l4, %o0
F000D7FC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000D800: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F000D804: 9010200b                 mov     0xB, %o0
F000D808: 10800022                 ba      loc_F000D890
F000D80C: d02a6038                 stb     %o0, [%o1+0x38]
F000D810: 233c04cf                 sethi   -0xFECC400, %l1
F000D814: 92100018                 mov     %i0, %o1
F000D818: d00461d8                 ld      [%l1+0x1D8], %o0
F000D81C: 94100014                 mov     %l4, %o2
F000D820: e4020000                 ld      [%o0], %l2
F000D824: a21461d8                 bset    0x1D8, %l1
F000D828: 4000002a                 call    _cloneproc
F000D82C: 90100012                 mov     %l2, %o0
F000D830: a0100008                 mov     %o0, %l0
F000D834: 113c04d0                 sethi   %hi(_active_threads), %o0
F000D838: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F000D83C: 4002394d                 call    _thread_dup
F000D840: 92100010                 mov     %l0, %o1
F000D844: d2042084                 ld      [%l0+0x84], %o1
F000D848: d054a030                 ldsh    [%l2+0x30], %o0
F000D84C: d0226030                 st      %o0, [%o1+0x30]
F000D850: d2042084                 ld      [%l0+0x84], %o1
F000D854: 90102001                 mov     1, %o0
F000D858: d0226034                 st      %o0, [%o1+0x34]
F000D85C: d004200c                 ld      [%l0+0xC], %o0
F000D860: d0022038                 ld      [%o0+0x38], %o0
F000D864: 4001835b                 call    _microtime
F000D868: 90022238                 inc     0x238, %o0
F000D86C: d004200c                 ld      [%l0+0xC], %o0
F000D870: d2022038                 ld      [%o0+0x38], %o1
F000D874: 90102001                 mov     1, %o0
F000D878: d0326240                 sth     %o0, [%o1+0x240]
F000D87C: d4046004                 ld      [%l1+4], %o2
F000D880: d254e030                 ldsh    [%l3+0x30], %o1
F000D884: 90100010                 mov     %l0, %o0! target_act
F000D888: 40019f44                 call    _thread_resume
F000D88C: d222a030                 st      %o1, [%o2+0x30]
F000D890: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F000D894: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F000D898: c0222034                 clr     [%o0+0x34]
F000D89C: 81c7e008                 ret
F000D8A0: 81e80000                 restore
