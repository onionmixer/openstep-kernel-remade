F0076E70: 9de3bf98                 save    %sp, -0x68, %sp
F0076E74: 40007f45                 call    _splusclock
F0076E78: 01000000                 nop
F0076E7C: a2100008                 mov     %o0, %l1
F0076E80: 113c04c3a0122320         set     dword_F0130F20, %l0
F0076E88: d0040000                 ld      [%l0], %o0
F0076E8C: 80a22000                 cmp     %o0, 0
F0076E90: 12bffffe                 bne     loc_F0076E88
F0076E94: 01000000                 nop
F0076E98: 40008004                 call    _simple_lock_try
F0076E9C: 90100010                 mov     %l0, %o0
F0076EA0: 80a22000                 cmp     %o0, 0
F0076EA4: 02bffff9                 be      loc_F0076E88
F0076EA8: 01000000                 nop
F0076EAC: d0062020                 ld      [%i0+0x20], %o0
F0076EB0: 80a22000                 cmp     %o0, 0
F0076EB4: 02800007                 be      loc_F0076ED0
F0076EB8: 113c04c3                 sethi   %hi(dword_F0130F20), %o0
F0076EBC: c0222320                 clr     [%o0+%lo(dword_F0130F20)]
F0076EC0: 113c0442                 sethi   %hi(aCalloutentryfr), %o0! "calloutEntryFree"
F0076EC4: 7ffe78ab                 call    _panic
F0076EC8: 901223d0                 bset    %lo(aCalloutentryfr), %o0! "calloutEntryFree"
F0076ECC: 113c04c3                 sethi   -0xFECF400, %o0
F0076ED0: c0222320                 clr     [%o0+0x320]
F0076ED4: 40007f94                 call    _splx
F0076ED8: 90100011                 mov     %l1, %o0
F0076EDC: 90100018                 mov     %i0, %o0
F0076EE0: 7fffc4b0                 call    _kfree
F0076EE4: 92102028                 mov     0x28, %o1 ! '('
F0076EE8: 81c7e008                 ret
F0076EEC: 81e80000                 restore
