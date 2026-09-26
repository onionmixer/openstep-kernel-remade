F0012CD8: 9de3bf88                 save    %sp, -0x78, %sp
F0012CDC: f027a044                 st      %i0, [%fp+arg_44]
F0012CE0: f227a048                 st      %i1, [%fp+arg_48]
F0012CE4: f427a04c                 st      %i2, [%fp+arg_4C]
F0012CE8: f627a050                 st      %i3, [%fp+arg_50]
F0012CEC: f827a054                 st      %i4, [%fp+arg_54]
F0012CF0: 90102001                 mov     1, %o0
F0012CF4: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0012CF8: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0012CFC: d027bfec                 st      %o0, [%fp+var_14]
F0012D00: d04a6040                 ldsb    [%o1+0x40], %o0
F0012D04: 808a2080                 btst    0x80, %o0
F0012D08: 1280000b                 bne     loc_F0012D34
F0012D0C: 961421dc                 or      %l0, %lo(dword_F0133DDC), %o3
F0012D10: 90123f80                 bset    -0x80, %o0
F0012D14: d02a6040                 stb     %o0, [%o1+0x40]
F0012D18: d407a050                 ld      [%fp+arg_50], %o2
F0012D1C: 113c042c                 sethi   %hi(aSSSPausing), %o0! "[%s: %s%s, pausing ...]\r\n"
F0012D20: d202fffc                 ld      [%o3-4], %o1
F0012D24: 90122320                 bset    %lo(aSSSPausing), %o0! "[%s: %s%s, pausing ...]\r\n"
F0012D28: d607a054                 ld      [%fp+arg_54], %o3
F0012D2C: 4000065d                 call    _uprintf
F0012D30: 92026008                 inc     8, %o1
F0012D34: 9207bff0                 add     %fp, var_10, %o1! void *
F0012D38: d00421dc                 ld      [%l0+0x1DC], %o0! void *
F0012D3C: 94102008                 mov     8, %o2! size_t
F0012D40: 40020774                 call    _bcopy
F0012D44: 90022028                 inc     0x28, %o0 ! '('
F0012D48: d00421dc                 ld      [%l0+0x1DC], %o0! jmp_buf
F0012D4C: 40021002                 call    _setjmp
F0012D50: 90022028                 inc     0x28, %o0 ! '('
F0012D54: 80a22000                 cmp     %o0, 0
F0012D58: 32800008                 bne,a   loc_F0012D78
F0012D5C: c027bfec                 clr     [%fp+var_14]
F0012D60: d007a048                 ld      [%fp+arg_48], %o0
F0012D64: d407a044                 ld      [%fp+arg_44], %o2
F0012D68: 9fc28000                 call    %o2
F0012D6C: d207a04c                 ld      [%fp+arg_4C], %o1
F0012D70: 10800003                 ba      loc_F0012D7C
F0012D74: 9007bff0                 add     %fp, var_10, %o0
F0012D78: 9007bff0                 add     %fp, var_10, %o0! void *
F0012D7C: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0012D80: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1! void *
F0012D84: 94102008                 mov     8, %o2! size_t
F0012D88: 40020762                 call    _bcopy
F0012D8C: 92026028                 inc     0x28, %o1 ! '('
F0012D90: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0012D94: d04a2040                 ldsb    [%o0+0x40], %o0
F0012D98: 808a2080                 btst    0x80, %o0
F0012D9C: 12800005                 bne     locret_F0012DB0
F0012DA0: f007bfec                 ld      [%fp+var_14], %i0
F0012DA4: 40000005                 call    _rpcont
F0012DA8: 01000000                 nop
F0012DAC: f007bfec                 ld      [%fp+var_14], %i0
F0012DB0: 81c7e008                 ret
F0012DB4: 81e80000                 restore
