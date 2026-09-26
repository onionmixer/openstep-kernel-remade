F0091F3C: 9de3bf98                 save    %sp, -0x68, %sp
F0091F40: 113c0448a41223a8         set     unk_F01123A8, %l2
F0091F48: 153c0471                 sethi   %hi(_bdevsw), %o2
F0091F4C: 113c0472                 sethi   %hi(_nblkdev), %o0
F0091F50: d20221ec                 ld      [%o0+%lo(_nblkdev)], %o1
F0091F54: 9412a3ac                 bset    %lo(_bdevsw), %o2
F0091F58: 912a6001                 sll     %o1, 1, %o0
F0091F5C: 90020009                 add     %o0, %o1, %o0
F0091F60: 912a2003                 sll     %o0, 3, %o0
F0091F64: 9202000a                 add     %o0, %o2, %o1
F0091F68: 80a28009                 cmp     %o2, %o1
F0091F6C: 113c04c4                 sethi   %hi(unk_F0131000), %o0
F0091F70: 1a80001a                 bcc     loc_F0091FD8
F0091F74: a0122000                 or      %o0, %lo(unk_F0131000), %l0
F0091F78: 113c0248961220f0         set     _sdopen, %o3
F0091F80: 9810000a                 mov     %o2, %o4
F0091F84: 1b3c04c4                 sethi   -0xFECF000, %o5
F0091F88: d0028000                 ld      [%o2], %o0
F0091F8C: 80a2000b                 cmp     %o0, %o3
F0091F90: 3280000f                 bne,a   loc_F0091FCC
F0091F94: 9402a018                 inc     0x18, %o2
F0091F98: 9222800c                 sub     %o2, %o4, %o1
F0091F9C: 912a6002                 sll     %o1, 2, %o0
F0091FA0: 90020009                 add     %o0, %o1, %o0
F0091FA4: 932a2004                 sll     %o0, 4, %o1
F0091FA8: 90020009                 add     %o0, %o1, %o0
F0091FAC: 932a2008                 sll     %o0, 8, %o1
F0091FB0: 90020009                 add     %o0, %o1, %o0
F0091FB4: 932a2010                 sll     %o0, 16, %o1
F0091FB8: 90020009                 add     %o0, %o1, %o0
F0091FBC: 90200008                 neg     %o0
F0091FC0: 913a2003                 sra     %o0, 3, %o0
F0091FC4: 10800005                 ba      loc_F0091FD8
F0091FC8: d0236240                 st      %o0, [%o5+0x240]
F0091FCC: 80a28009                 cmp     %o2, %o1
F0091FD0: 2abfffef                 bcs,a   loc_F0091F8C
F0091FD4: d0028000                 ld      [%o2], %o0
F0091FD8: 153c0472                 sethi   %hi(_cdevsw), %o2
F0091FDC: 113c0474                 sethi   %hi(_nchrdev), %o0
F0091FE0: d2022154                 ld      [%o0+%lo(_nchrdev)], %o1
F0091FE4: 9412a1f0                 bset    %lo(_cdevsw), %o2
F0091FE8: 912a6001                 sll     %o1, 1, %o0
F0091FEC: 90020009                 add     %o0, %o1, %o0
F0091FF0: 912a2002                 sll     %o0, 2, %o0
F0091FF4: 90220009                 sub     %o0, %o1, %o0
F0091FF8: 912a2002                 sll     %o0, 2, %o0
F0091FFC: 9202000a                 add     %o0, %o2, %o1
F0092000: 80a28009                 cmp     %o2, %o1
F0092004: 1a80001b                 bcc     loc_F0092070
F0092008: 113c0248                 sethi   %hi(_sdopen), %o0
F009200C: 961220f0                 or      %o0, %lo(_sdopen), %o3
F0092010: 9810000a                 mov     %o2, %o4
F0092014: 1b3c04c4                 sethi   -0xFECF000, %o5
F0092018: d0028000                 ld      [%o2], %o0
F009201C: 80a2000b                 cmp     %o0, %o3
F0092020: 32800011                 bne,a   loc_F0092064
F0092024: 9402a02c                 inc     0x2C, %o2 ! ','
F0092028: 9422800c                 sub     %o2, %o4, %o2
F009202C: 932aa005                 sll     %o2, 5, %o1
F0092030: 9222400a                 sub     %o1, %o2, %o1
F0092034: 932a6005                 sll     %o1, 5, %o1
F0092038: 9202400a                 add     %o1, %o2, %o1
F009203C: 912a6003                 sll     %o1, 3, %o0
F0092040: 92024008                 add     %o1, %o0, %o1! size_t
F0092044: 912a600f                 sll     %o1, 15, %o0
F0092048: 90220009                 sub     %o0, %o1, %o0
F009204C: 912a2002                 sll     %o0, 2, %o0
F0092050: 9002000a                 add     %o0, %o2, %o0
F0092054: 90200008                 neg     %o0
F0092058: 913a2002                 sra     %o0, 2, %o0
F009205C: 10800005                 ba      loc_F0092070
F0092060: d0236244                 st      %o0, [%o5+0x244]
F0092064: 80a28009                 cmp     %o2, %o1
F0092068: 2abfffed                 bcs,a   loc_F009201C
F009206C: d0028000                 ld      [%o2], %o0
F0092070: 90100010                 mov     %l0, %o0! void *
F0092074: 40000b79                 call    _bzero
F0092078: 92102240                 mov     0x240, %o1
F009207C: a2102000                 mov     0, %l1
F0092080: 293c04c4                 sethi   -0xFECF000, %l4
F0092084: 273c04c4                 sethi   -0xFECF000, %l3
F0092088: a0042022                 inc     0x22, %l0 ! '"'
F009208C: 90102044                 mov     0x44, %o0 ! 'D'
F0092090: 972c6003                 sll     %l1, 3, %o3
F0092094: d4052244                 ld      [%l4+0x244], %o2
F0092098: a2046001                 inc     %l1
F009209C: d204e240                 ld      [%l3+0x240], %o1
F00920A0: 952aa008                 sll     %o2, 8, %o2
F00920A4: 9412800b                 bset    %o3, %o2
F00920A8: d4343ffe                 sth     %o2, [%l0-2]
F00920AC: 932a6008                 sll     %o1, 8, %o1
F00920B0: 9212400b                 bset    %o3, %o1
F00920B4: d2340000                 sth     %o1, [%l0]
F00920B8: 4000cf9e                 call    _IOMalloc
F00920BC: a0042024                 inc     0x24, %l0 ! '$'
F00920C0: d0248000                 st      %o0, [%l2]
F00920C4: c0220000                 clr     [%o0]
F00920C8: 80a4600f                 cmp     %l1, 0xF
F00920CC: 04bffff0                 ble     loc_F009208C
F00920D0: a404a004                 inc     4, %l2
F00920D4: 81c7e008                 ret
F00920D8: 81e80000                 restore
