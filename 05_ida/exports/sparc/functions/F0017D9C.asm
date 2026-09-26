F0017D9C: 9de3bf98                 save    %sp, -0x68, %sp
F0017DA0: 40000cd2                 call    _ttynty
F0017DA4: 90100018                 mov     %i0, %o0
F0017DA8: 153c04d4                 sethi   %hi(_cons_tp), %o2
F0017DAC: d202a290                 ld      [%o2+%lo(_cons_tp)], %o1
F0017DB0: 80a60009                 cmp     %i0, %o1
F0017DB4: 12800017                 bne     loc_F0017E10
F0017DB8: a0100008                 mov     %o0, %l0
F0017DBC: 113c04d490122190         set     _cons, %o0
F0017DC4: d022a290                 st      %o0, [%o2+%lo(_cons_tp)]
F0017DC8: 1308001a                 sethi   0x20006800, %o1
F0017DCC: d4162038                 lduh    [%i0+0x38], %o2
F0017DD0: 92126308                 bset    0x308, %o1
F0017DD4: 952aa010                 sll     %o2, 16, %o2
F0017DD8: 913aa010                 sra     %o2, 16, %o0
F0017DDC: 9532a018                 srl     %o2, 24, %o2
F0017DE0: 972aa001                 sll     %o2, 1, %o3
F0017DE4: 9602c00a                 add     %o3, %o2, %o3
F0017DE8: 972ae002                 sll     %o3, 2, %o3
F0017DEC: 9622c00a                 sub     %o3, %o2, %o3
F0017DF0: 972ae002                 sll     %o3, 2, %o3
F0017DF4: 153c04729412a1f0         set     _cdevsw, %o2
F0017DFC: 9602c00a                 add     %o3, %o2, %o3
F0017E00: d802e010                 ld      [%o3+0x10], %o4
F0017E04: 94102000                 mov     0, %o2
F0017E08: 9fc30000                 call    %o4
F0017E0C: 96102000                 mov     0, %o3
F0017E10: 90100018                 mov     %i0, %o0
F0017E14: 7ffffb07                 call    _ttyflush
F0017E18: 92102003                 mov     3, %o1
F0017E1C: 153c04cf                 sethi   %hi(_active_u), %o2
F0017E20: d002a1d8                 ld      [%o2+%lo(_active_u)], %o0
F0017E24: d0020000                 ld      [%o0], %o0
F0017E28: d2022014                 ld      [%o0+0x14], %o1
F0017E2C: 11000010                 sethi   0x4000, %o0
F0017E30: 808a4008                 btst    %o0, %o1
F0017E34: 22800005                 be,a    loc_F0017E48
F0017E38: d402a1d8                 ld      [%o2+%lo(_active_u)], %o2
F0017E3C: c0242008                 clr     [%l0+8]
F0017E40: c024200c                 clr     [%l0+0xC]
F0017E44: d402a1d8                 ld      [%o2+%lo(_active_u)], %o2
F0017E48: d002a164                 ld      [%o2+0x164], %o0
F0017E4C: 80a20018                 cmp     %o0, %i0
F0017E50: 32800008                 bne,a   loc_F0017E70
F0017E54: c0362044                 clrh    [%i0+0x44]
F0017E58: d4028000                 ld      [%o2], %o2
F0017E5C: d202a028                 ld      [%o2+0x28], %o1
F0017E60: 11100000                 sethi   0x40000000, %o0
F0017E64: 902a4008                 andn    %o1, %o0, %o0
F0017E68: d022a028                 st      %o0, [%o2+0x28]
F0017E6C: c0362044                 clrh    [%i0+0x44]
F0017E70: c0262040                 clr     [%i0+0x40]
F0017E74: c02e2047                 clrb    [%i0+0x47]
F0017E78: 4001fb50                 call    _spltty
F0017E7C: c0262084                 clr     [%i0+0x84]
F0017E80: a0100008                 mov     %o0, %l0
F0017E84: 7ffff894                 call    _selthreadclear
F0017E88: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F0017E8C: 7ffff892                 call    _selthreadclear
F0017E90: 90062028                 add     %i0, 0x28, %o0 ! '('
F0017E94: 4001fba4                 call    _splx
F0017E98: 90100010                 mov     %l0, %o0
F0017E9C: 81c7e008                 ret
F0017EA0: 81e80000                 restore
