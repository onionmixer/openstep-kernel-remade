F00119B0: 9de3bf90                 save    %sp, -0x70, %sp
F00119B4: 113c04cf                 sethi   %hi(_active_u), %o0
F00119B8: d20221d8                 ld      [%o0+%lo(_active_u)], %o1
F00119BC: 113c04d0                 sethi   %hi(_master_cpu), %o0
F00119C0: d00220c8                 ld      [%o0+%lo(_master_cpu)], %o0
F00119C4: b4100018                 mov     %i0, %i2
F00119C8: 80a22000                 cmp     %o0, 0
F00119CC: 02800005                 be      loc_F00119E0
F00119D0: e2024000                 ld      [%o1], %l1
F00119D4: 113c042c                 sethi   %hi(aIssigNotOnMast), %o0! "issig not on master"
F00119D8: 40000de6                 call    _panic
F00119DC: 90122258                 bset    %lo(aIssigNotOnMast), %o0! "issig not on master"
F00119E0: a0046070                 add     %l1, 0x70, %l0 ! 'p'
F00119E4: d0040000                 ld      [%l0], %o0
F00119E8: 80a22000                 cmp     %o0, 0
F00119EC: 12bffffe                 bne     loc_F00119E4
F00119F0: 01000000                 nop
F00119F4: 4002152d                 call    _simple_lock_try
F00119F8: 90100010                 mov     %l0, %o0
F00119FC: 80a22000                 cmp     %o0, 0
F0011A00: 02bffff9                 be      loc_F00119E4
F0011A04: 01000000                 nop
F0011A08: 1080001e                 ba      loc_F0011A80
F0011A0C: d0046074                 ld      [%l1+0x74], %o0
F0011A10: c0246070                 clr     [%l1+0x70]
F0011A14: 80a26000                 cmp     %o1, 0
F0011A18: 02800008                 be      loc_F0011A38
F0011A1C: 113c04d0                 sethi   %hi(_active_threads), %o0
F0011A20: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0011A24: 80a20009                 cmp     %o0, %o1
F0011A28: 0280013b                 be      locret_F0011F14
F0011A2C: b0102000                 mov     0, %i0
F0011A30: 40018e0b                 call    _thread_hold
F0011A34: 01000000                 nop
F0011A38: 40018322                 call    _thread_block
F0011A3C: 01000000                 nop
F0011A40: 113c04d0                 sethi   %hi(_active_threads), %o0
F0011A44: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F0011A48: d002218c                 ld      [%o0+0x18C], %o0
F0011A4C: 808a2003                 btst    3, %o0
F0011A50: 1280012e                 bne     loc_F0011F08
F0011A54: a0046070                 add     %l1, 0x70, %l0 ! 'p'
F0011A58: d0040000                 ld      [%l0], %o0
F0011A5C: 80a22000                 cmp     %o0, 0
F0011A60: 12bffffe                 bne     loc_F0011A58
F0011A64: 01000000                 nop
F0011A68: 40021510                 call    _simple_lock_try
F0011A6C: 90100010                 mov     %l0, %o0
F0011A70: 80a22000                 cmp     %o0, 0
F0011A74: 02bffff9                 be      loc_F0011A58
F0011A78: 01000000                 nop
F0011A7C: d0046074                 ld      [%l1+0x74], %o0
F0011A80: 80a22000                 cmp     %o0, 0
F0011A84: 32bfffe3                 bne,a   loc_F0011A10
F0011A88: d2046078                 ld      [%l1+0x78], %o1
F0011A8C: d0046078                 ld      [%l1+0x78], %o0
F0011A90: 80a22000                 cmp     %o0, 0
F0011A94: 32bfffdf                 bne,a   loc_F0011A10
F0011A98: d2046078                 ld      [%l1+0x78], %o1
F0011A9C: 2d3c04cf                 sethi   -0xFECC400, %l6
F0011AA0: aa102001                 mov     1, %l5
F0011AA4: 11000007ae1222f8         set     0x1EF8, %l7
F0011AAC: 293c04d0                 sethi   -0xFECC000, %l4
F0011AB0: 113c04cfb21221d8         set     _active_u, %i1
F0011AB8: d405a1dc                 ld      [%l6+0x1DC], %o2! jumptable F0011DF0 cases 0,3,4,7,12
F0011ABC: d04aa048                 ldsb    [%o2+0x48], %o0
F0011AC0: 80a22000                 cmp     %o0, 0
F0011AC4: 02800008                 be      loc_F0011AE4
F0011AC8: 90023fff                 inc     -1, %o0
F0011ACC: d202a04c                 ld      [%o2+0x4C], %o1
F0011AD0: 912d4008                 sll     %l5, %o0, %o0
F0011AD4: 92124008                 bset    %o0, %o1
F0011AD8: d222a04c                 st      %o1, [%o2+0x4C]
F0011ADC: d005a1dc                 ld      [%l6+0x1DC], %o0
F0011AE0: c02a2048                 clrb    [%o0+0x48]
F0011AE4: e005a1dc                 ld      [%l6+0x1DC], %l0
F0011AE8: d2046018                 ld      [%l1+0x18], %o1
F0011AEC: d404601c                 ld      [%l1+0x1C], %o2
F0011AF0: d004204c                 ld      [%l0+0x4C], %o0
F0011AF4: d6046028                 ld      [%l1+0x28], %o3
F0011AF8: 90120009                 bset    %o1, %o0
F0011AFC: 922a000a                 andn    %o0, %o2, %o1
F0011B00: 948ae010                 andcc   %o3, 0x10, %o2
F0011B04: 12800005                 bne     loc_F0011B18
F0011B08: 11000004                 sethi   0x1000, %o0
F0011B0C: d0046020                 ld      [%l1+0x20], %o0
F0011B10: 922a4008                 bclr    %o0, %o1
F0011B14: 11000004                 sethi   0x1000, %o0
F0011B18: 808ac008                 btst    %o0, %o3
F0011B1C: 02800003                 be      loc_F0011B28
F0011B20: 11000cc0                 sethi   0x330000, %o0! int
F0011B24: 922a4008                 bclr    %o0, %o1
F0011B28: 80a26000                 cmp     %o1, 0
F0011B2C: 028000f0                 be      loc_F0011EEC
F0011B30: 80a6a000                 cmp     %i2, 0
F0011B34: 02800004                 be      loc_F0011B44
F0011B38: 80a2a000                 cmp     %o2, 0
F0011B3C: 128000f2                 bne     loc_F0011F04
F0011B40: 01000000                 nop
F0011B44: 7fffd91a                 call    _ffs
F0011B48: 90100009                 mov     %o1, %o0
F0011B4C: b0100008                 mov     %o0, %i0
F0011B50: 90063fff                 add     %i0, -1, %o0
F0011B54: a52d4008                 sll     %l5, %o0, %l2
F0011B58: 808c8017                 btst    %l7, %l2
F0011B5C: 22800008                 be,a    loc_F0011B7C
F0011B60: d0046018                 ld      [%l1+0x18], %o0
F0011B64: f02c2048                 stb     %i0, [%l0+0x48]
F0011B68: d205a1dc                 ld      [%l6+0x1DC], %o1
F0011B6C: d002604c                 ld      [%o1+0x4C], %o0
F0011B70: 902a0012                 bclr    %l2, %o0
F0011B74: d022604c                 st      %o0, [%o1+0x4C]
F0011B78: d0046018                 ld      [%l1+0x18], %o0
F0011B7C: f02c6017                 stb     %i0, [%l1+0x17]
F0011B80: d2046028                 ld      [%l1+0x28], %o1
F0011B84: 902a0012                 bclr    %l2, %o0
F0011B88: d0246018                 st      %o0, [%l1+0x18]
F0011B8C: 1100000490122010         set     0x1010, %o0
F0011B94: 920a4008                 and     %o1, %o0, %o1! char *
F0011B98: 80a26010                 cmp     %o1, 0x10
F0011B9C: 12800075                 bne     loc_F0011D70
F0011BA0: 113c04cf                 sethi   -0xFECC400, %o0
F0011BA4: d0046044                 ld      [%l1+0x44], %o0! unsigned int
F0011BA8: 7ffffe73                 call    _psignal
F0011BAC: 92102014                 mov     0x14, %o1
F0011BB0: d0052260                 ld      [%l4+0x260], %o0
F0011BB4: a6102000                 mov     0, %l3
F0011BB8: 40022895                 call    _pcb_synch
F0011BBC: d024606c                 st      %o0, [%l1+0x6C]
F0011BC0: e0046068                 ld      [%l1+0x68], %l0
F0011BC4: d0040000                 ld      [%l0], %o0
F0011BC8: 80a22000                 cmp     %o0, 0
F0011BCC: 12bffffe                 bne     loc_F0011BC4
F0011BD0: 01000000                 nop
F0011BD4: 400214b5                 call    _simple_lock_try
F0011BD8: 90100010                 mov     %l0, %o0
F0011BDC: 80a22000                 cmp     %o0, 0
F0011BE0: 02bffff9                 be      loc_F0011BC4
F0011BE4: 01000000                 nop
F0011BE8: d0042044                 ld      [%l0+0x44], %o0
F0011BEC: 90022001                 inc     %o0
F0011BF0: 80a22001                 cmp     %o0, 1
F0011BF4: 12800003                 bne     loc_F0011C00
F0011BF8: d0242044                 st      %o0, [%l0+0x44]
F0011BFC: a6102001                 mov     1, %l3
F0011C00: c0240000                 clr     [%l0]
F0011C04: 80a4e000                 cmp     %l3, 0
F0011C08: 2280000d                 be,a    loc_F0011C3C
F0011C0C: ea246074                 st      %l5, [%l1+0x74]
F0011C10: 4001865d                 call    _task_hold
F0011C14: 90100010                 mov     %l0, %o0
F0011C18: ea246074                 st      %l5, [%l1+0x74]
F0011C1C: c0246070                 clr     [%l1+0x70]
F0011C20: 90100010                 mov     %l0, %o0
F0011C24: 4001867e                 call    _task_dowait
F0011C28: 92102001                 mov     1, %o1
F0011C2C: 40018d8c                 call    _thread_hold
F0011C30: d0052260                 ld      [%l4+0x260], %o0
F0011C34: 10800004                 ba      loc_F0011C44
F0011C38: 90102006                 mov     6, %o0
F0011C3C: c0246070                 clr     [%l1+0x70]
F0011C40: 90102006                 mov     6, %o0
F0011C44: d2046028                 ld      [%l1+0x28], %o1
F0011C48: d02c6013                 stb     %o0, [%l1+0x13]
F0011C4C: d0046044                 ld      [%l1+0x44], %o0
F0011C50: 920a7fdf                 and     %o1, -0x21, %o1
F0011C54: 40000465                 call    _wakeup
F0011C58: d2246028                 st      %o1, [%l1+0x28]
F0011C5C: 40018299                 call    _thread_block
F0011C60: a0046070                 add     %l1, 0x70, %l0 ! 'p'
F0011C64: d0040000                 ld      [%l0], %o0
F0011C68: 80a22000                 cmp     %o0, 0
F0011C6C: 12bffffe                 bne     loc_F0011C64
F0011C70: 01000000                 nop
F0011C74: 4002148d                 call    _simple_lock_try
F0011C78: 90100010                 mov     %l0, %o0
F0011C7C: 80a22000                 cmp     %o0, 0
F0011C80: 02bffff9                 be      loc_F0011C64
F0011C84: 01000000                 nop
F0011C88: c0246074                 clr     [%l1+0x74]
F0011C8C: f04c6017                 ldsb    [%l1+0x17], %i0
F0011C90: 80a62020                 cmp     %i0, 0x20 ! ' '
F0011C94: 04800017                 ble     loc_F0011CF0
F0011C98: d0052260                 ld      [%l4+0x260], %o0
F0011C9C: b0063fe0                 inc     -0x20, %i0
F0011CA0: 92102002                 mov     2, %o1
F0011CA4: 40017c63                 call    _clear_wait
F0011CA8: 94102000                 mov     0, %o2
F0011CAC: d0052260                 ld      [%l4+0x260], %o0
F0011CB0: d0246078                 st      %o0, [%l1+0x78]
F0011CB4: c0246070                 clr     [%l1+0x70]
F0011CB8: d0052260                 ld      [%l4+0x260], %o0
F0011CBC: 40018632                 call    _task_hold
F0011CC0: d002200c                 ld      [%o0+0xC], %o0
F0011CC4: d0052260                 ld      [%l4+0x260], %o0
F0011CC8: d002200c                 ld      [%o0+0xC], %o0
F0011CCC: 40018654                 call    _task_dowait
F0011CD0: 92102000                 mov     0, %o1
F0011CD4: d205a1dc                 ld      [%l6+0x1DC], %o1
F0011CD8: d0026028                 ld      [%o1+0x28], %o0
F0011CDC: d027bff0                 st      %o0, [%fp+var_10]
F0011CE0: d202602c                 ld      [%o1+0x2C], %o1
F0011CE4: 90100018                 mov     %i0, %o0! int
F0011CE8: 7fffea8b                 call    _exit
F0011CEC: d227bff4                 st      %o1, [%fp+var_C]
F0011CF0: d002218c                 ld      [%o0+0x18C], %o0
F0011CF4: 808a2003                 btst    3, %o0
F0011CF8: 12800083                 bne     loc_F0011F04
F0011CFC: 01000000                 nop
F0011D00: d0046028                 ld      [%l1+0x28], %o0
F0011D04: 808a2010                 btst    0x10, %o0
F0011D08: 12800007                 bne     loc_F0011D24
F0011D0C: 80a62000                 cmp     %i0, 0
F0011D10: 808c8017                 btst    %l7, %l2
F0011D14: 1280000e                 bne     loc_F0011D4C
F0011D18: d205a1dc                 ld      [%l6+0x1DC], %o1
F0011D1C: 10800011                 ba      loc_F0011D60
F0011D20: d0046018                 ld      [%l1+0x18], %o0
F0011D24: 02bfff66                 be      loc_F0011ABC
F0011D28: d405a1dc                 ld      [%l6+0x1DC], %o2
F0011D2C: 90063fff                 add     %i0, -1, %o0
F0011D30: d204601c                 ld      [%l1+0x1C], %o1
F0011D34: a52d4008                 sll     %l5, %o0, %l2
F0011D38: 808a4012                 btst    %l2, %o1
F0011D3C: 0280000c                 be      loc_F0011D6C
F0011D40: 808c8017                 btst    %l7, %l2
F0011D44: 02800006                 be      loc_F0011D5C
F0011D48: d205a1dc                 ld      [%l6+0x1DC], %o1
F0011D4C: d002604c                 ld      [%o1+0x4C], %o0
F0011D50: 90120012                 bset    %l2, %o0
F0011D54: 10bfff59                 ba      loc_F0011AB8! jumptable F0011DF0 cases 0,3,4,7,12
F0011D58: d022604c                 st      %o0, [%o1+0x4C]
F0011D5C: d0046018                 ld      [%l1+0x18], %o0
F0011D60: 90120012                 bset    %l2, %o0
F0011D64: 10bfff55                 ba      loc_F0011AB8! jumptable F0011DF0 cases 0,3,4,7,12
F0011D68: d0246018                 st      %o0, [%l1+0x18]
F0011D6C: 113c04cf                 sethi   -0xFECC400, %o0
F0011D70: d20221d8                 ld      [%o0+0x1D8], %o1
F0011D74: 912e2002                 sll     %i0, 2, %o0
F0011D78: 90020009                 add     %o0, %o1, %o0
F0011D7C: d0022030                 ld      [%o0+0x30], %o0
F0011D80: 80a22001                 cmp     %o0, 1
F0011D84: 22800052                 be,a    loc_F0011ECC
F0011D88: d0046028                 ld      [%l1+0x28], %o0
F0011D8C: 14800006                 bg      loc_F0011DA4
F0011D90: 80a22003                 cmp     %o0, 3
F0011D94: 80a22000                 cmp     %o0, 0
F0011D98: 22800006                 be,a    loc_F0011DB0
F0011D9C: d0546032                 ldsh    [%l1+0x32], %o0
F0011DA0: 3080005c                 ba,a    def_F0011DF0! jumptable F0011DF0 default case, cases 8-11
F0011DA4: 2280004a                 be,a    loc_F0011ECC
F0011DA8: d0046028                 ld      [%l1+0x28], %o0
F0011DAC: 30800059                 ba,a    def_F0011DF0! jumptable F0011DF0 default case, cases 8-11
F0011DB0: 80a22000                 cmp     %o0, 0
F0011DB4: 12800009                 bne     loc_F0011DD8
F0011DB8: 92063ff0                 add     %i0, -0x10, %o1
F0011DBC: d0066004                 ld      [%i1+4], %o0
F0011DC0: c02a2048                 clrb    [%o0+0x48]
F0011DC4: d2066004                 ld      [%i1+4], %o1
F0011DC8: d002604c                 ld      [%o1+0x4C], %o0
F0011DCC: 902a0012                 bclr    %l2, %o0
F0011DD0: 10bfff3a                 ba      loc_F0011AB8! jumptable F0011DF0 cases 0,3,4,7,12
F0011DD4: d022604c                 st      %o0, [%o1+0x4C]
F0011DD8: 80a2600c                 cmp     %o1, 0xC! switch 13 cases
F0011DDC: 1880004d                 bgu     def_F0011DF0! jumptable F0011DF0 default case, cases 8-11
F0011DE0: 113c0047                 sethi   %hi(jpt_F0011DF0), %o0
F0011DE4: 901221f8                 bset    %lo(jpt_F0011DF0), %o0
F0011DE8: 932a6002                 sll     %o1, 2, %o1
F0011DEC: d0024008                 ld      [%o1+%o0], %o0
F0011DF0: 81c20000                 jmp     %o0! switch jump
F0011DF4: 01000000                 nop
F0011E2C: d0046044                 ld      [%l1+0x44], %o0! jumptable F0011DF0 cases 2,5,6
F0011E30: 133c04d1                 sethi   %hi(_init_proc), %o1
F0011E34: d2026338                 ld      [%o1+%lo(_init_proc)], %o1! char *
F0011E38: 80a20009                 cmp     %o0, %o1
F0011E3C: 32800008                 bne,a   loc_F0011E5C
F0011E40: d0046028                 ld      [%l1+0x28], %o0
F0011E44: 90100011                 mov     %l1, %o0! unsigned int
F0011E48: 7ffffdcb                 call    _psignal
F0011E4C: 92102009                 mov     9, %o1! char *
F0011E50: 10bfff1b                 ba      loc_F0011ABC
F0011E54: d405a1dc                 ld      [%l6+0x1DC], %o2
F0011E58: d0046028                 ld      [%l1+0x28], %o0! jumptable F0011DF0 case 1
F0011E5C: 808a2010                 btst    0x10, %o0
F0011E60: 12bfff17                 bne     loc_F0011ABC
F0011E64: d405a1dc                 ld      [%l6+0x1DC], %o2
F0011E68: d0046044                 ld      [%l1+0x44], %o0! unsigned int
F0011E6C: 7ffffdc2                 call    _psignal
F0011E70: 92102014                 mov     0x14, %o1
F0011E74: 4000002a                 call    _stop
F0011E78: 90100011                 mov     %l1, %o0
F0011E7C: ea246074                 st      %l5, [%l1+0x74]
F0011E80: c0246070                 clr     [%l1+0x70]
F0011E84: 4001820f                 call    _thread_block
F0011E88: a0046070                 add     %l1, 0x70, %l0 ! 'p'
F0011E8C: d0040000                 ld      [%l0], %o0
F0011E90: 80a22000                 cmp     %o0, 0
F0011E94: 12bffffe                 bne     loc_F0011E8C
F0011E98: 01000000                 nop
F0011E9C: 40021403                 call    _simple_lock_try
F0011EA0: 90100010                 mov     %l0, %o0
F0011EA4: 80a22000                 cmp     %o0, 0
F0011EA8: 02bffff9                 be      loc_F0011E8C
F0011EAC: 01000000                 nop
F0011EB0: c0246074                 clr     [%l1+0x74]
F0011EB4: d0052260                 ld      [%l4+0x260], %o0
F0011EB8: d002218c                 ld      [%o0+0x18C], %o0
F0011EBC: 808a2003                 btst    3, %o0
F0011EC0: 02bffeff                 be      loc_F0011ABC
F0011EC4: d405a1dc                 ld      [%l6+0x1DC], %o2
F0011EC8: 3080000f                 ba,a    loc_F0011F04
F0011ECC: 808a2010                 btst    0x10, %o0
F0011ED0: 12bffefb                 bne     loc_F0011ABC
F0011ED4: d405a1dc                 ld      [%l6+0x1DC], %o2
F0011ED8: 113c042c                 sethi   %hi(aIssig), %o0! "issig\n"
F0011EDC: 400009df                 call    _printf
F0011EE0: 90122270                 bset    %lo(aIssig), %o0! "issig\n"
F0011EE4: 10bffef6                 ba      loc_F0011ABC
F0011EE8: d405a1dc                 ld      [%l6+0x1DC], %o2
F0011EEC: c02c6017                 clrb    [%l1+0x17]
F0011EF0: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F0011EF4: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F0011EF8: b0102000                 mov     0, %i0
F0011EFC: 10800005                 ba      def_F0011DF0! jumptable F0011DF0 default case, cases 8-11
F0011F00: c02a2048                 clrb    [%o0+0x48]
F0011F04: c0246070                 clr     [%l1+0x70]
F0011F08: 10800003                 ba      locret_F0011F14
F0011F0C: b0102001                 mov     1, %i0
F0011F10: c0246070                 clr     [%l1+0x70]! jumptable F0011DF0 default case, cases 8-11
F0011F14: 81c7e008                 ret
F0011F18: 81e80000                 restore
