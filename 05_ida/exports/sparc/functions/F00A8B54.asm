F00A8B54: 9de3bf98                 save    %sp, -0x68, %sp
F00A8B58: 113c04d0                 sethi   %hi(_active_threads), %o0
F00A8B5C: e4022260                 ld      [%o0+%lo(_active_threads)], %l2
F00A8B60: e604a084                 ld      [%l2+0x84], %l3
F00A8B64: 113c04cf                 sethi   %hi(_active_u), %o0
F00A8B68: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F00A8B6C: e004c000                 ld      [%l3], %l0
F00A8B70: 80a62000                 cmp     %i0, 0
F00A8B74: 02800025                 be      def_F00A8B98! jumptable F00A8B98 default case, cases 0-2,4-16
F00A8B78: e2020000                 ld      [%o0], %l1
F00A8B7C: 92063ff5                 add     %i0, -0xB, %o1
F00A8B80: 80a26011                 cmp     %o1, 0x11! switch 18 cases
F00A8B84: 18800021                 bgu     def_F00A8B98! jumptable F00A8B98 default case, cases 0-2,4-16
F00A8B88: 113c02a2                 sethi   %hi(jpt_F00A8B98), %o0
F00A8B8C: 901223a0                 bset    %lo(jpt_F00A8B98), %o0
F00A8B90: 932a6002                 sll     %o1, 2, %o1
F00A8B94: d0024008                 ld      [%o1+%o0], %o0
F00A8B98: 81c20000                 jmp     %o0! switch jump
F00A8B9C: 01000000                 nop
F00A8BE8: 7ffe7fbc                 call    _fspause! jumptable F00A8B98 case 17
F00A8BEC: 90102000                 mov     0, %o0
F00A8BF0: 80a22000                 cmp     %o0, 0
F00A8BF4: 02800005                 be      def_F00A8B98! jumptable F00A8B98 default case, cases 0-2,4-16
F00A8BF8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00A8BFC: d20221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o1
F00A8C00: 90102002                 mov     2, %o0
F00A8C04: d02a6039                 stb     %o0, [%o1+0x39]
F00A8C08: d04ce039                 ldsb    [%l3+0x39], %o0! jumptable F00A8B98 default case, cases 0-2,4-16
F00A8C0C: 80a22003                 cmp     %o0, 3
F00A8C10: 3280001b                 bne,a   loc_F00A8C7C
F00A8C14: d004a18c                 ld      [%l2+0x18C], %o0
F00A8C18: 80a62000                 cmp     %i0, 0
F00A8C1C: 22800008                 be,a    loc_F00A8C3C
F00A8C20: d2040000                 ld      [%l0], %o1
F00A8C24: f024202c                 st      %i0, [%l0+0x2C]! jumptable F00A8B98 case 3
F00A8C28: d0040000                 ld      [%l0], %o0
F00A8C2C: 13000400                 sethi   0x100000, %o1
F00A8C30: 90120009                 bset    %o1, %o0
F00A8C34: 1080000c                 ba      loc_F00A8C64
F00A8C38: d0240000                 st      %o0, [%l0]
F00A8C3C: 11000400                 sethi   0x100000, %o0
F00A8C40: 902a4008                 andn    %o1, %o0, %o0
F00A8C44: d0240000                 st      %o0, [%l0]
F00A8C48: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F00A8C4C: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F00A8C50: d0022030                 ld      [%o0+0x30], %o0
F00A8C54: d024202c                 st      %o0, [%l0+0x2C]
F00A8C58: d00261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o0
F00A8C5C: d0022034                 ld      [%o0+0x34], %o0
F00A8C60: d0242030                 st      %o0, [%l0+0x30]
F00A8C64: d2042008                 ld      [%l0+8], %o1
F00A8C68: d0042008                 ld      [%l0+8], %o0
F00A8C6C: d2242004                 st      %o1, [%l0+4]
F00A8C70: 90022004                 inc     4, %o0
F00A8C74: d0242008                 st      %o0, [%l0+8]
F00A8C78: d004a18c                 ld      [%l2+0x18C], %o0
F00A8C7C: 808a2003                 btst    3, %o0
F00A8C80: 32800021                 bne,a   loc_F00A8D04
F00A8C84: d004a18c                 ld      [%l2+0x18C], %o0
F00A8C88: d04c6017                 ldsb    [%l1+0x17], %o0
F00A8C8C: 80a22000                 cmp     %o0, 0
F00A8C90: 12800013                 bne     loc_F00A8CDC
F00A8C94: 01000000                 nop
F00A8C98: d2046018                 ld      [%l1+0x18], %o1
F00A8C9C: d004e04c                 ld      [%l3+0x4C], %o0
F00A8CA0: 94924008                 orcc    %o1, %o0, %o2
F00A8CA4: 22800018                 be,a    loc_F00A8D04
F00A8CA8: d004a18c                 ld      [%l2+0x18C], %o0
F00A8CAC: d0046028                 ld      [%l1+0x28], %o0
F00A8CB0: 808a2010                 btst    0x10, %o0
F00A8CB4: 32800009                 bne,a   loc_F00A8CD8
F00A8CB8: d04c6017                 ldsb    [%l1+0x17], %o0
F00A8CBC: d0046020                 ld      [%l1+0x20], %o0
F00A8CC0: d204601c                 ld      [%l1+0x1C], %o1
F00A8CC4: 90120009                 bset    %o1, %o0
F00A8CC8: 80aa8008                 andncc  %o2, %o0, %g0
F00A8CCC: 2280000e                 be,a    loc_F00A8D04
F00A8CD0: d004a18c                 ld      [%l2+0x18C], %o0
F00A8CD4: d04c6017                 ldsb    [%l1+0x17], %o0
F00A8CD8: 80a22000                 cmp     %o0, 0
F00A8CDC: 12800007                 bne     loc_F00A8CF8
F00A8CE0: 01000000                 nop
F00A8CE4: 7ffda333                 call    _issig
F00A8CE8: 90102000                 mov     0, %o0
F00A8CEC: 80a22000                 cmp     %o0, 0
F00A8CF0: 22800005                 be,a    loc_F00A8D04
F00A8CF4: d004a18c                 ld      [%l2+0x18C], %o0
F00A8CF8: 7ffda495                 call    _psig
F00A8CFC: 01000000                 nop
F00A8D00: d004a18c                 ld      [%l2+0x18C], %o0
F00A8D04: 808a2003                 btst    3, %o0
F00A8D08: 02800006                 be      loc_F00A8D20
F00A8D0C: 113c04d2                 sethi   -0xFECB800, %o0
F00A8D10: 7fff30ff                 call    _thread_halt_self
F00A8D14: 01000000                 nop
F00A8D18: 10bfffd9                 ba      loc_F00A8C7C
F00A8D1C: d004a18c                 ld      [%l2+0x18C], %o0
F00A8D20: d00221b0                 ld      [%o0+0x1B0], %o0
F00A8D24: d404a04c                 ld      [%l2+0x4C], %o2
F00A8D28: d202212c                 ld      [%o0+0x12C], %o1
F00A8D2C: d8022108                 ld      [%o0+0x108], %o4
F00A8D30: c4022124                 ld      [%o0+0x124], %g2
F00A8D34: da026108                 ld      [%o1+0x108], %o5
F00A8D38: d6026104                 ld      [%o1+0x104], %o3
F00A8D3C: d004a060                 ld      [%l2+0x60], %o0
F00A8D40: 808aa002                 btst    2, %o2
F00A8D44: 12800020                 bne     loc_F00A8DC4
F00A8D48: d204a058                 ld      [%l2+0x58], %o1
F00A8D4C: 80a32000                 cmp     %o4, 0
F00A8D50: 34800020                 bg,a    loc_F00A8DD0
F00A8D54: 90102001                 mov     1, %o0
F00A8D58: 80a22002                 cmp     %o0, 2
F00A8D5C: 22800007                 be,a    loc_F00A8D78
F00A8D60: 80a36000                 cmp     %o5, 0
F00A8D64: 14800005                 bg      loc_F00A8D78
F00A8D68: 80a36000                 cmp     %o5, 0
F00A8D6C: 80a22001                 cmp     %o0, 1
F00A8D70: 0280000d                 be      loc_F00A8DA4
F00A8D74: 80a36000                 cmp     %o5, 0
F00A8D78: 02800015                 be      loc_F00A8DCC
F00A8D7C: 80a2c009                 cmp     %o3, %o1
F00A8D80: 06800014                 bl      loc_F00A8DD0
F00A8D84: 90102000                 mov     0, %o0
F00A8D88: 14800012                 bg      loc_F00A8DD0
F00A8D8C: 90102001                 mov     1, %o0
F00A8D90: 80a0a000                 cmp     %g2, 0
F00A8D94: 1280000f                 bne     loc_F00A8DD0
F00A8D98: 90102000                 mov     0, %o0
F00A8D9C: 1080000d                 ba      loc_F00A8DD0
F00A8DA0: 90102001                 mov     1, %o0
F00A8DA4: 80a0a000                 cmp     %g2, 0
F00A8DA8: 1280000a                 bne     loc_F00A8DD0
F00A8DAC: 90102000                 mov     0, %o0
F00A8DB0: 80a36000                 cmp     %o5, 0
F00A8DB4: 04800007                 ble     loc_F00A8DD0
F00A8DB8: 80a2c009                 cmp     %o3, %o1
F00A8DBC: 06800006                 bl      loc_F00A8DD4
F00A8DC0: 80a22000                 cmp     %o0, 0
F00A8DC4: 10800003                 ba      loc_F00A8DD0
F00A8DC8: 90102001                 mov     1, %o0
F00A8DCC: 90102000                 mov     0, %o0
F00A8DD0: 80a22000                 cmp     %o0, 0
F00A8DD4: 0280000b                 be      loc_F00A8E00
F00A8DD8: 113c04cf                 sethi   %hi(_active_u), %o0
F00A8DDC: d40221d8                 ld      [%o0+%lo(_active_u)], %o2
F00A8DE0: 113c026f                 sethi   %hi(_thread_exception_return), %o0
F00A8DE4: d202a1b0                 ld      [%o2+0x1B0], %o1
F00A8DE8: 901223e4                 bset    %lo(_thread_exception_return), %o0
F00A8DEC: 92026001                 inc     %o1
F00A8DF0: 7fff2254                 call    _thread_block_with_continuation
F00A8DF4: d222a1b0                 st      %o1, [%o2+0x1B0]
F00A8DF8: 10bfffa1                 ba      loc_F00A8C7C
F00A8DFC: d004a18c                 ld      [%l2+0x18C], %o0
F00A8E00: 7fffcc79                 call    _thread_exception_return
F00A8E04: 01000000                 nop
F00A8E08: 81c7e008                 ret
F00A8E0C: 81e80000                 restore
