F0013D2C: 9de3bf98                 save    %sp, -0x68, %sp
F0013D30: 80a66020                 cmp     %i1, 0x20 ! ' '
F0013D34: 18800027                 bgu     locret_F0013DD0
F0013D38: 92067fff                 add     %i1, -1, %o1
F0013D3C: 90102001                 mov     1, %o0
F0013D40: a32a0009                 sll     %o0, %o1, %l1
F0013D44: 11000007901222f8         set     0x1EF8, %o0
F0013D4C: 808c4008                 btst    %o0, %l1
F0013D50: 32800009                 bne,a   loc_F0013D74
F0013D54: d006200c                 ld      [%i0+0xC], %o0
F0013D58: 113c042d                 sethi   %hi(aSignalD), %o0! "signal = %d\n"
F0013D5C: 4000023f                 call    _printf
F0013D60: 90122040                 bset    %lo(aSignalD), %o0! "signal = %d\n"
F0013D64: 113c042d                 sethi   %hi(aThreadPsignalS), %o0! "thread_psignal: signal is not an except"...
F0013D68: 40000502                 call    _panic
F0013D6C: 90122050                 bset    %lo(aThreadPsignalS), %o0! "thread_psignal: signal is not an except"...
F0013D70: d006200c                 ld      [%i0+0xC], %o0
F0013D74: e002203c                 ld      [%o0+0x3C], %l0
F0013D78: d0042020                 ld      [%l0+0x20], %o0
F0013D7C: 808a0011                 btst    %l1, %o0
F0013D80: 02800006                 be      loc_F0013D98
F0013D84: b2042070                 add     %l0, 0x70, %i1 ! 'p'
F0013D88: d0042028                 ld      [%l0+0x28], %o0
F0013D8C: 808a2010                 btst    0x10, %o0
F0013D90: 02800010                 be      locret_F0013DD0
F0013D94: 01000000                 nop
F0013D98: d0064000                 ld      [%i1], %o0
F0013D9C: 80a22000                 cmp     %o0, 0
F0013DA0: 12bffffe                 bne     loc_F0013D98
F0013DA4: 01000000                 nop
F0013DA8: 40020c40                 call    _simple_lock_try
F0013DAC: 90100019                 mov     %i1, %o0
F0013DB0: 80a22000                 cmp     %o0, 0
F0013DB4: 02bffff9                 be      loc_F0013D98
F0013DB8: 01000000                 nop
F0013DBC: d2062084                 ld      [%i0+0x84], %o1
F0013DC0: d002604c                 ld      [%o1+0x4C], %o0
F0013DC4: 90120011                 bset    %l1, %o0
F0013DC8: d022604c                 st      %o0, [%o1+0x4C]
F0013DCC: c0242070                 clr     [%l0+0x70]
F0013DD0: 81c7e008                 ret
F0013DD4: 81e80000                 restore
