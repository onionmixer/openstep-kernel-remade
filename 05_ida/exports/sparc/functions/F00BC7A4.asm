F00BC7A4: 9de3bf90                 save    %sp, -0x70, %sp
F00BC7A8: a0062170                 add     %i0, 0x170, %l0
F00BC7AC: d0040000                 ld      [%l0], %o0
F00BC7B0: 80a22000                 cmp     %o0, 0
F00BC7B4: 12bffffe                 bne     loc_F00BC7AC
F00BC7B8: 01000000                 nop
F00BC7BC: 7fff69bb                 call    _simple_lock_try
F00BC7C0: 90100010                 mov     %l0, %o0
F00BC7C4: 80a22000                 cmp     %o0, 0
F00BC7C8: 02bffff9                 be      loc_F00BC7AC
F00BC7CC: 13200000                 sethi   0x80000000, %o1
F00BC7D0: d0062124                 ld      [%i0+0x124], %o0
F00BC7D4: d4062168                 ld      [%i0+0x168], %o2
F00BC7D8: 90120009                 bset    %o1, %o0
F00BC7DC: d206216c                 ld      [%i0+0x16C], %o1
F00BC7E0: 80a28009                 cmp     %o2, %o1
F00BC7E4: 12800015                 bne     loc_F00BC838
F00BC7E8: d0262124                 st      %o0, [%i0+0x124]
F00BC7EC: a0062170                 add     %i0, 0x170, %l0
F00BC7F0: 90062128                 add     %i0, 0x128, %o0
F00BC7F4: 92100010                 mov     %l0, %o1
F00BC7F8: 7ffed271                 call    _thread_sleep
F00BC7FC: 94102001                 mov     1, %o2
F00BC800: d0040000                 ld      [%l0], %o0
F00BC804: 80a22000                 cmp     %o0, 0
F00BC808: 12bffffe                 bne     loc_F00BC800
F00BC80C: 01000000                 nop
F00BC810: 7fff69a6                 call    _simple_lock_try
F00BC814: 90100010                 mov     %l0, %o0
F00BC818: 80a22000                 cmp     %o0, 0
F00BC81C: 02bffff9                 be      loc_F00BC800
F00BC820: 01000000                 nop
F00BC824: d2062168                 ld      [%i0+0x168], %o1
F00BC828: d006216c                 ld      [%i0+0x16C], %o0
F00BC82C: 80a24008                 cmp     %o1, %o0
F00BC830: 02bffff1                 be      loc_F00BC7F4
F00BC834: 90062128                 add     %i0, 0x128, %o0
F00BC838: d006216c                 ld      [%i0+0x16C], %o0
F00BC83C: 92022001                 add     %o0, 1, %o1
F00BC840: 912a2002                 sll     %o0, 2, %o0
F00BC844: 90020018                 add     %o0, %i0, %o0
F00BC848: 80a26010                 cmp     %o1, 0x10
F00BC84C: 12800003                 bne     loc_F00BC858
F00BC850: d4022128                 ld      [%o0+0x128], %o2
F00BC854: 92102000                 mov     0, %o1
F00BC858: d226216c                 st      %o1, [%i0+0x16C]
F00BC85C: c0262170                 clr     [%i0+0x170]
F00BC860: d2062124                 ld      [%i0+0x124], %o1
F00BC864: 11200000                 sethi   0x80000000, %o0
F00BC868: 902a4008                 andn    %o1, %o0, %o0
F00BC86C: d0262124                 st      %o0, [%i0+0x124]
F00BC870: 81c7e008                 ret
F00BC874: 91e8000a                 restore %g0, %o2, %o0
