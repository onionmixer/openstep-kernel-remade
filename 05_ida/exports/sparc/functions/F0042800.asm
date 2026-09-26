F0042800: 9de3bf40                 save    %sp, -0xC0, %sp
F0042804: 113c04cf                 sethi   %hi(_active_u), %o0
F0042808: d80221d8                 ld      [%o0+%lo(_active_u)], %o4
F004280C: d2060000                 ld      [%i0], %o1
F0042810: 113c04d190122230         set     _hostname, %o0
F0042818: d403201c                 ld      [%o4+0x1C], %o2
F004281C: d027bfac                 st      %o0, [%fp+var_54]
F0042820: d003201c                 ld      [%o4+0x1C], %o0
F0042824: d652a002                 ldsh    [%o2+2], %o3
F0042828: 80a26000                 cmp     %o1, 0
F004282C: d0522004                 ldsh    [%o0+4], %o0
F0042830: 9402a00a                 inc     0xA, %o2
F0042834: d627bfa8                 st      %o3, [%fp+var_58]
F0042838: 12800033                 bne     loc_F0042904
F004283C: d027bfa4                 st      %o0, [%fp+var_5C]
F0042840: c027bfa0                 clr     [%fp+var_60]
F0042844: 9807bff8                 add     %fp, var_8, %o4
F0042848: d6528000                 ldsh    [%o2], %o3
F004284C: 80a2ffff                 cmp     %o3, -1
F0042850: 0280000a                 be      loc_F0042878
F0042854: d207bfa0                 ld      [%fp+var_60], %o1! unsigned __int32 *
F0042858: 9402a002                 inc     2, %o2! unsigned int
F004285C: 912a6002                 sll     %o1, 2, %o0
F0042860: 9002000c                 add     %o0, %o4, %o0
F0042864: d6223fc0                 st      %o3, [%o0-0x40]
F0042868: 92026001                 inc     %o1
F004286C: 80a2600f                 cmp     %o1, 0xF
F0042870: 04bffff6                 ble     loc_F0042848
F0042874: d227bfa0                 st      %o1, [%fp+var_60]
F0042878: a007bfb0                 add     %fp, var_50, %l0
F004287C: 7fff41c4                 call    _getthetime
F0042880: 90100010                 mov     %l0, %o0
F0042884: 90100018                 mov     %i0, %o0! XDR *
F0042888: 40000b19                 call    _xdr_u_long
F004288C: 92100010                 mov     %l0, %o1
F0042890: 80a22000                 cmp     %o0, 0
F0042894: 0280001c                 be      loc_F0042904
F0042898: 90100018                 mov     %i0, %o0! XDR *
F004289C: 9207bfac                 add     %fp, var_54, %o1! char **
F00428A0: 40000c57                 call    _xdr_string
F00428A4: 941020ff                 mov     0xFF, %o2
F00428A8: 80a22000                 cmp     %o0, 0
F00428AC: 02800016                 be      loc_F0042904
F00428B0: 90100018                 mov     %i0, %o0! XDR *
F00428B4: 40000ae8                 call    _xdr_int
F00428B8: 9207bfa8                 add     %fp, var_58, %o1! int *
F00428BC: 80a22000                 cmp     %o0, 0
F00428C0: 02800011                 be      loc_F0042904
F00428C4: 90100018                 mov     %i0, %o0! XDR *
F00428C8: 40000ae3                 call    _xdr_int
F00428CC: 9207bfa4                 add     %fp, var_5C, %o1
F00428D0: 80a22000                 cmp     %o0, 0
F00428D4: 0280000c                 be      loc_F0042904
F00428D8: 90100018                 mov     %i0, %o0! XDR *
F00428DC: 9207bfb8                 add     %fp, var_48, %o1! char **
F00428E0: 9407bfa0                 add     %fp, var_60, %o2! unsigned int *
F00428E4: 1b3c0115                 sethi   %hi(_xdr_int), %o5! xdrproc_t
F00428E8: 96102010                 mov     0x10, %o3! unsigned int
F00428EC: 98102004                 mov     4, %o4! unsigned int
F00428F0: 40000c84                 call    _xdr_array
F00428F4: 9a136054                 bset    %lo(_xdr_int), %o5
F00428F8: 80a22000                 cmp     %o0, 0
F00428FC: 12800003                 bne     locret_F0042908
F0042900: b0102001                 mov     1, %i0
F0042904: b0102000                 mov     0, %i0
F0042908: 81c7e008                 ret
F004290C: 81e80000                 restore
