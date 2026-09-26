F0015CA8: 9de3bf90                 save    %sp, -0x70, %sp! int
F0015CAC: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0015CB0: e00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %l0
F0015CB4: d0042124                 ld      [%l0+0x124], %o0
F0015CB8: a2042058                 add     %l0, 0x58, %l1 ! 'X'
F0015CBC: 80a22000                 cmp     %o0, 0
F0015CC0: 1680000b                 bge     loc_F0015CEC
F0015CC4: e6042024                 ld      [%l0+0x24], %l3
F0015CC8: 40017278                 call    _thread_wait_result
F0015CCC: 01000000                 nop
F0015CD0: 90023ffe                 inc     -2, %o0
F0015CD4: 80a22001                 cmp     %o0, 1
F0015CD8: 18800004                 bgu     loc_F0015CE8
F0015CDC: 90102004                 mov     4, %o0
F0015CE0: 10800003                 ba      loc_F0015CEC
F0015CE4: d0242124                 st      %o0, [%l0+0x124]
F0015CE8: c0242124                 clr     [%l0+0x124]
F0015CEC: d00460cc                 ld      [%l1+0xCC], %o0
F0015CF0: 80a22000                 cmp     %o0, 0
F0015CF4: 3480005e                 bg,a    loc_F0015E6C
F0015CF8: d20460cc                 ld      [%l1+0xCC], %o1
F0015CFC: 193c04cf                 sethi   -0xFECC400, %o4
F0015D00: d20321d8                 ld      [%o4+0x1D8], %o1
F0015D04: 90100011                 mov     %l1, %o0
F0015D08: e4024000                 ld      [%o1], %l2
F0015D0C: 17001000                 sethi   0x400000, %o3
F0015D10: d404a028                 ld      [%l2+0x28], %o2
F0015D14: a01321d8                 or      %o4, 0x1D8, %l0
F0015D18: 9412800b                 bset    %o3, %o2
F0015D1C: d424a028                 st      %o2, [%l2+0x28]
F0015D20: d404c000                 ld      [%l3], %o2
F0015D24: 173c04d4                 sethi   %hi(_nselcoll), %o3
F0015D28: e802e230                 ld      [%o3+%lo(_nselcoll)], %l4
F0015D2C: 40000074                 call    _selscan
F0015D30: 92046060                 add     %l1, 0x60, %o1 ! '`'
F0015D34: d2042004                 ld      [%l0+4], %o1
F0015D38: d0226030                 st      %o0, [%o1+0x30]
F0015D3C: d0042004                 ld      [%l0+4], %o0
F0015D40: d04a2038                 ldsb    [%o0+0x38], %o0
F0015D44: 80a22000                 cmp     %o0, 0
F0015D48: 12800048                 bne     loc_F0015E68
F0015D4C: d02460cc                 st      %o0, [%l1+0xCC]
F0015D50: d0042004                 ld      [%l0+4], %o0
F0015D54: d0022030                 ld      [%o0+0x30], %o0
F0015D58: 80a22000                 cmp     %o0, 0
F0015D5C: 32800044                 bne,a   loc_F0015E6C
F0015D60: d20460cc                 ld      [%l1+0xCC], %o1
F0015D64: d00460c8                 ld      [%l1+0xC8], %o0
F0015D68: 80a22000                 cmp     %o0, 0
F0015D6C: 32800040                 bne,a   loc_F0015E6C
F0015D70: d20460cc                 ld      [%l1+0xCC], %o1
F0015D74: 40020385                 call    _splusclock
F0015D78: 01000000                 nop
F0015D7C: d204e010                 ld      [%l3+0x10], %o1
F0015D80: 80a26000                 cmp     %o1, 0
F0015D84: 02800014                 be      loc_F0015DD4
F0015D88: a0100008                 mov     %o0, %l0
F0015D8C: 7ffff480                 call    _getthetime
F0015D90: 9007bff0                 add     %fp, var_10, %o0
F0015D94: d207bff0                 ld      [%fp+var_10], %o1
F0015D98: d00460c0                 ld      [%l1+0xC0], %o0
F0015D9C: 80a24008                 cmp     %o1, %o0
F0015DA0: 14800009                 bg      loc_F0015DC4
F0015DA4: 01000000                 nop
F0015DA8: 3280000c                 bne,a   loc_F0015DD8
F0015DAC: d204a028                 ld      [%l2+0x28], %o1
F0015DB0: d207bff4                 ld      [%fp+var_C], %o1
F0015DB4: d00460c4                 ld      [%l1+0xC4], %o0
F0015DB8: 80a24008                 cmp     %o1, %o0
F0015DBC: 26800007                 bl,a    loc_F0015DD8
F0015DC0: d204a028                 ld      [%l2+0x28], %o1
F0015DC4: 400203d8                 call    _splx
F0015DC8: 90100010                 mov     %l0, %o0
F0015DCC: 10800028                 ba      loc_F0015E6C
F0015DD0: d20460cc                 ld      [%l1+0xCC], %o1
F0015DD4: d204a028                 ld      [%l2+0x28], %o1
F0015DD8: 11001000                 sethi   0x400000, %o0
F0015DDC: 808a4008                 btst    %o0, %o1
F0015DE0: 02800006                 be      loc_F0015DF8
F0015DE4: 113c04d4                 sethi   %hi(_nselcoll), %o0
F0015DE8: d0022230                 ld      [%o0+%lo(_nselcoll)], %o0
F0015DEC: 80a20014                 cmp     %o0, %l4
F0015DF0: 02800009                 be      loc_F0015E14
F0015DF4: 11001000                 sethi   0x400000, %o0
F0015DF8: 11001000                 sethi   0x400000, %o0
F0015DFC: 902a4008                 andn    %o1, %o0, %o0
F0015E00: d024a028                 st      %o0, [%l2+0x28]
F0015E04: 400203c8                 call    _splx
F0015E08: 90100010                 mov     %l0, %o0
F0015E0C: 10bfffbd                 ba      loc_F0015D00
F0015E10: 193c04cf                 sethi   -0xFECC400, %o4! int
F0015E14: 902a4008                 andn    %o1, %o0, %o0
F0015E18: d024a028                 st      %o0, [%l2+0x28]
F0015E1C: 90103fff                 mov     -1, %o0
F0015E20: d02460cc                 st      %o0, [%l1+0xCC]
F0015E24: d004e010                 ld      [%l3+0x10], %o0
F0015E28: 80a22000                 cmp     %o0, 0
F0015E2C: 0280000a                 be      loc_F0015E54
F0015E30: 113c04d4                 sethi   %hi(_selwait), %o0
F0015E34: 90122238                 bset    %lo(_selwait), %o0
F0015E38: 9210201a                 mov     0x1A, %o1
F0015E3C: 153c00579412a0a8         set     _selcont, %o2
F0015E44: 7ffff312                 call    _sleep_with_continuation_and_deadline
F0015E48: 960460c0                 add     %l1, 0xC0, %o3! int
F0015E4C: 10800008                 ba      loc_F0015E6C
F0015E50: d20460cc                 ld      [%l1+0xCC], %o1
F0015E54: 90122238                 bset    0x238, %o0
F0015E58: 9210201a                 mov     0x1A, %o1
F0015E5C: 153c0057                 sethi   %hi(_selcont), %o2
F0015E60: 7ffff286                 call    _sleep_with_continuation
F0015E64: 9412a0a8                 bset    %lo(_selcont), %o2! int
F0015E68: d20460cc                 ld      [%l1+0xCC], %o1
F0015E6C: d004c000                 ld      [%l3], %o0
F0015E70: 80a26000                 cmp     %o1, 0
F0015E74: 9002201f                 inc     0x1F, %o0
F0015E78: 12800017                 bne     loc_F0015ED4
F0015E7C: a1322005                 srl     %o0, 5, %l0
F0015E80: d204e004                 ld      [%l3+4], %o1! int
F0015E84: 80a26000                 cmp     %o1, 0
F0015E88: 02800005                 be      loc_F0015E9C
F0015E8C: 90046060                 add     %l1, 0x60, %o0 ! '`'! int
F0015E90: 4002088f                 call    _copyout
F0015E94: 952c2002                 sll     %l0, 2, %o2! int
F0015E98: d02460cc                 st      %o0, [%l1+0xCC]
F0015E9C: d204e008                 ld      [%l3+8], %o1! int
F0015EA0: 80a26000                 cmp     %o1, 0
F0015EA4: 02800005                 be      loc_F0015EB8
F0015EA8: 90046080                 add     %l1, 0x80, %o0! int
F0015EAC: 40020888                 call    _copyout
F0015EB0: 952c2002                 sll     %l0, 2, %o2! int
F0015EB4: d02460cc                 st      %o0, [%l1+0xCC]
F0015EB8: d204e00c                 ld      [%l3+0xC], %o1! int
F0015EBC: 80a26000                 cmp     %o1, 0
F0015EC0: 02800005                 be      loc_F0015ED4
F0015EC4: 900460a0                 add     %l1, 0xA0, %o0! int
F0015EC8: 40020881                 call    _copyout
F0015ECC: 952c2002                 sll     %l0, 2, %o2
F0015ED0: d02460cc                 st      %o0, [%l1+0xCC]
F0015ED4: d20460cc                 ld      [%l1+0xCC], %o1
F0015ED8: 80a26000                 cmp     %o1, 0
F0015EDC: 02800004                 be      loc_F0015EEC
F0015EE0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0015EE4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0015EE8: d22a2038                 stb     %o1, [%o0+0x38]
F0015EEC: 40024b1a                 call    _unix_syscall_return
F0015EF0: d00460cc                 ld      [%l1+0xCC], %o0
F0015EF4: 81c7e008                 ret
F0015EF8: 81e80000                 restore
