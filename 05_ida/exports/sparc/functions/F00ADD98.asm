F00ADD98: 9de3bf98                 save    %sp, -0x68, %sp
F00ADD9C: d4068000                 ld      [%i2], %o2
F00ADDA0: 13200000                 sethi   0x80000000, %o1
F00ADDA4: d0064000                 ld      [%i1], %o0
F00ADDA8: 922a8009                 andn    %o2, %o1, %o1
F00ADDAC: 912a201f                 sll     %o0, 31, %o0
F00ADDB0: 92124008                 bset    %o0, %o1
F00ADDB4: d2268000                 st      %o1, [%i2]
F00ADDB8: d2066004                 ld      [%i1+4], %o1
F00ADDBC: 80a26005                 cmp     %o1, 5! switch 6 cases
F00ADDC0: 1880008a                 bgu     def_F00ADDD4! jumptable F00ADDD4 default case, case 3
F00ADDC4: 113c02b7                 sethi   %hi(jpt_F00ADDD4), %o0
F00ADDC8: 901221dc                 bset    %lo(jpt_F00ADDD4), %o0
F00ADDCC: 932a6002                 sll     %o1, 2, %o1
F00ADDD0: d0024008                 ld      [%o1+%o0], %o0
F00ADDD4: 81c20000                 jmp     %o0! switch jump
F00ADDD8: 01000000                 nop
F00ADDF4: d2068000                 ld      [%i2], %o1! jumptable F00ADDD4 case 0
F00ADDF8: 111fffc0                 sethi   0x7FFF0000, %o0
F00ADDFC: 10800005                 ba      loc_F00ADE10
F00ADE00: 902a4008                 andn    %o1, %o0, %o0
F00ADE04: d0068000                 ld      [%i2], %o0! jumptable F00ADDD4 case 2
F00ADE08: 131fffc0                 sethi   0x7FFF0000, %o1
F00ADE0C: 90120009                 bset    %o1, %o0
F00ADE10: d0268000                 st      %o0, [%i2]
F00ADE14: c036a002                 clrh    [%i2+2]
F00ADE18: c0270000                 clr     [%i4]
F00ADE1C: c026c000                 clr     [%i3]
F00ADE20: 10800072                 ba      def_F00ADDD4! jumptable F00ADDD4 default case, case 3
F00ADE24: c0274000                 clr     [%i5]
F00ADE28: d0068000                 ld      [%i2], %o0! jumptable F00ADDD4 cases 4,5
F00ADE2C: 131fffc0                 sethi   0x7FFF0000, %o1
F00ADE30: 90120009                 bset    %o1, %o0
F00ADE34: d0268000                 st      %o0, [%i2]
F00ADE38: d006600c                 ld      [%i1+0xC], %o0
F00ADE3C: 13000020                 sethi   0x8000, %o1
F00ADE40: 10800063                 ba      loc_F00ADFCC
F00ADE44: 90120009                 bset    %o1, %o0
F00ADE48: d2066008                 ld      [%i1+8], %o1! jumptable F00ADDD4 case 1
F00ADE4C: 1100000f901223ff         set     0x3FFF, %o0
F00ADE54: 94024008                 add     %o1, %o0, %o2
F00ADE58: 80a2a000                 cmp     %o2, 0
F00ADE5C: 1480002c                 bg      loc_F00ADF0C
F00ADE60: d4266008                 st      %o2, [%i1+8]
F00ADE64: 90100019                 mov     %i1, %o0
F00ADE68: 92102001                 mov     1, %o1
F00ADE6C: 400002bd                 call    _fpu_rightshift
F00ADE70: 9222400a                 sub     %o1, %o2, %o1
F00ADE74: 90100018                 mov     %i0, %o0
F00ADE78: 7ffffde0                 call    sub_F00AD5F8
F00ADE7C: 92100019                 mov     %i1, %o1
F00ADE80: d206600c                 ld      [%i1+0xC], %o1
F00ADE84: 1100003f901223ff         set     0xFFFF, %o0
F00ADE8C: 80a24008                 cmp     %o1, %o0
F00ADE90: 18800006                 bgu     loc_F00ADEA8
F00ADE94: 111fffc0                 sethi   0x7FFF0000, %o0
F00ADE98: d2068000                 ld      [%i2], %o1
F00ADE9C: 902a4008                 andn    %o1, %o0, %o0
F00ADEA0: 1080000b                 ba      loc_F00ADECC
F00ADEA4: d0268000                 st      %o0, [%i2]
F00ADEA8: 90100018                 mov     %i0, %o0
F00ADEAC: 92102000                 mov     0, %o1
F00ADEB0: d4068000                 ld      [%i2], %o2
F00ADEB4: 171fffc0                 sethi   0x7FFF0000, %o3
F00ADEB8: 962a800b                 andn    %o2, %o3, %o3
F00ADEBC: 15000040                 sethi   0x10000, %o2
F00ADEC0: 9612c00a                 bset    %o2, %o3
F00ADEC4: 40000300                 call    _fpu_set_exception
F00ADEC8: d6268000                 st      %o3, [%i2]
F00ADECC: d006200c                 ld      [%i0+0xC], %o0
F00ADED0: 808a2001                 btst    1, %o0
F00ADED4: 02800004                 be      loc_F00ADEE4
F00ADED8: 90100018                 mov     %i0, %o0
F00ADEDC: 400002fa                 call    _fpu_set_exception
F00ADEE0: 92102002                 mov     2, %o1
F00ADEE4: d0060000                 ld      [%i0], %o0
F00ADEE8: 808a2004                 btst    4, %o0
F00ADEEC: 02800037                 be      loc_F00ADFC8
F00ADEF0: 90100018                 mov     %i0, %o0
F00ADEF4: 400002f4                 call    _fpu_set_exception
F00ADEF8: 92102002                 mov     2, %o1
F00ADEFC: d006200c                 ld      [%i0+0xC], %o0
F00ADF00: 900a3ffe                 and     %o0, -2, %o0
F00ADF04: 10800031                 ba      loc_F00ADFC8
F00ADF08: d026200c                 st      %o0, [%i0+0xC]
F00ADF0C: 90100018                 mov     %i0, %o0
F00ADF10: 7ffffdba                 call    sub_F00AD5F8
F00ADF14: 92100019                 mov     %i1, %o1
F00ADF18: d4066008                 ld      [%i1+8], %o2
F00ADF1C: 1100001f901223fe         set     0x7FFE, %o0
F00ADF24: 80a28008                 cmp     %o2, %o0
F00ADF28: 04800020                 ble     loc_F00ADFA8
F00ADF2C: 90100018                 mov     %i0, %o0
F00ADF30: 400002e5                 call    _fpu_set_exception
F00ADF34: 92102003                 mov     3, %o1
F00ADF38: 90100018                 mov     %i0, %o0
F00ADF3C: 400002e2                 call    _fpu_set_exception
F00ADF40: 92102000                 mov     0, %o1
F00ADF44: d0060000                 ld      [%i0], %o0
F00ADF48: 808a2008                 btst    8, %o0
F00ADF4C: 22800006                 be,a    loc_F00ADF64
F00ADF50: d2064000                 ld      [%i1], %o1
F00ADF54: d006200c                 ld      [%i0+0xC], %o0
F00ADF58: 900a3ffe                 and     %o0, -2, %o0
F00ADF5C: d026200c                 st      %o0, [%i0+0xC]
F00ADF60: d2064000                 ld      [%i1], %o1
F00ADF64: 7ffffd93                 call    sub_F00AD5B0
F00ADF68: 90100018                 mov     %i0, %o0
F00ADF6C: 80a22000                 cmp     %o0, 0
F00ADF70: 32bfffa6                 bne,a   loc_F00ADE08
F00ADF74: d0068000                 ld      [%i2], %o0
F00ADF78: d2068000                 ld      [%i2], %o1
F00ADF7C: 111fffc0                 sethi   0x7FFF0000, %o0
F00ADF80: 902a4008                 andn    %o1, %o0, %o0
F00ADF84: 131fff80                 sethi   0x7FFE0000, %o1
F00ADF88: 90120009                 bset    %o1, %o0
F00ADF8C: d0268000                 st      %o0, [%i2]
F00ADF90: 90103fff                 mov     -1, %o0
F00ADF94: d036a002                 sth     %o0, [%i2+2]
F00ADF98: 90103fff                 mov     -1, %o0
F00ADF9C: d026c000                 st      %o0, [%i3]
F00ADFA0: 10800011                 ba      loc_F00ADFE4
F00ADFA4: d0270000                 st      %o0, [%i4]
F00ADFA8: d0068000                 ld      [%i2], %o0
F00ADFAC: 131fffc0                 sethi   0x7FFF0000, %o1
F00ADFB0: 922a0009                 andn    %o0, %o1, %o1
F00ADFB4: 113fffe0                 sethi   -0x8000, %o0
F00ADFB8: 902a8008                 andn    %o2, %o0, %o0
F00ADFBC: 912a2010                 sll     %o0, 16, %o0
F00ADFC0: 92124008                 bset    %o0, %o1
F00ADFC4: d2268000                 st      %o1, [%i2]
F00ADFC8: d006600c                 ld      [%i1+0xC], %o0
F00ADFCC: d036a002                 sth     %o0, [%i2+2]
F00ADFD0: d0066010                 ld      [%i1+0x10], %o0
F00ADFD4: d026c000                 st      %o0, [%i3]
F00ADFD8: d0066014                 ld      [%i1+0x14], %o0
F00ADFDC: d0270000                 st      %o0, [%i4]
F00ADFE0: d0066018                 ld      [%i1+0x18], %o0
F00ADFE4: d0274000                 st      %o0, [%i5]
F00ADFE8: 81c7e008                 ret! jumptable F00ADDD4 default case, case 3
F00ADFEC: 81e80000                 restore
