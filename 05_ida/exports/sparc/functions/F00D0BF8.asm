F00D0BF8: 9de3bf88                 save    %sp, -0x78, %sp
F00D0BFC: d0062120                 ld      [%i0+0x120], %o0
F00D0C00: 80a22000                 cmp     %o0, 0
F00D0C04: 2280001c                 be,a    loc_F00D0C74
F00D0C08: d2062124                 ld      [%i0+0x124], %o1
F00D0C0C: d0062124                 ld      [%i0+0x124], %o0
F00D0C10: 80a22000                 cmp     %o0, 0
F00D0C14: 1680000e                 bge     loc_F00D0C4C
F00D0C18: 90100018                 mov     %i0, %o0
F00D0C1C: d0062128                 ld      [%i0+0x128], %o0! id
F00D0C20: d41e2108                 ldd     [%i0+0x108], %o2
F00D0C24: d81e2110                 ldd     [%i0+0x110], %o4
F00D0C28: 133c0506                 sethi   %hi(paReleasescsi3ta), %o1
F00D0C2C: d2026004                 ld      [%o1+%lo(paReleasescsi3ta)], %o1! SEL
F00D0C30: 40008310                 call    _objc_msgSend
F00D0C34: f023a05c                 st      %i0, [%sp+0x78+var_1C]
F00D0C38: d2062124                 ld      [%i0+0x124], %o1
F00D0C3C: 11200000                 sethi   0x80000000, %o0
F00D0C40: 902a4008                 andn    %o1, %o0, %o0! id
F00D0C44: 1080000a                 ba      loc_F00D0C6C
F00D0C48: d0262124                 st      %o0, [%i0+0x124]
F00D0C4C: 133c0504                 sethi   %hi(paName), %o1
F00D0C50: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D0C54: 213c03ed                 sethi   %hi(aSClearreservat), %l0! "%s: clearReservation, no valid target\n"
F00D0C58: 40008306                 call    _objc_msgSend
F00D0C5C: a01422e0                 bset    %lo(aSClearreservat), %l0! "%s: clearReservation, no valid target\n"
F00D0C60: 92100008                 mov     %o0, %o1
F00D0C64: 7fffd524                 call    _IOLog
F00D0C68: 90100010                 mov     %l0, %o0
F00D0C6C: c0262120                 clr     [%i0+0x120]
F00D0C70: d2062124                 ld      [%i0+0x124], %o1
F00D0C74: 11200000                 sethi   0x80000000, %o0
F00D0C78: 902a4008                 andn    %o1, %o0, %o0
F00D0C7C: d0262124                 st      %o0, [%i0+0x124]
F00D0C80: 81c7e008                 ret
F00D0C84: 81e80000                 restore
