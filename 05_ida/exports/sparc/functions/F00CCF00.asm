F00CCF00: 9de3bf90                 save    %sp, -0x70, %sp
F00CCF04: d0062154                 ld      [%i0+0x154], %o0! id
F00CCF08: 133c0506                 sethi   %hi(paOper_0), %o1
F00CCF0C: d202603c                 ld      [%o1+%lo(paOper_0)], %o1! SEL
F00CCF10: 40009258                 call    _objc_msgSend
F00CCF14: a0102000                 mov     0, %l0
F00CCF18: 80a22002                 cmp     %o0, 2
F00CCF1C: 2280001c                 be,a    loc_F00CCF8C
F00CCF20: 90100018                 mov     %i0, %o0
F00CCF24: 14800006                 bg      loc_F00CCF3C
F00CCF28: 80a22004                 cmp     %o0, 4
F00CCF2C: 80a22001                 cmp     %o0, 1
F00CCF30: 22800006                 be,a    loc_F00CCF48
F00CCF34: d0062128                 ld      [%i0+0x128], %o0
F00CCF38: 30800029                 ba,a    locret_F00CCFDC
F00CCF3C: 22800022                 be,a    loc_F00CCFC4
F00CCF40: d0062154                 ld      [%i0+0x154], %o0
F00CCF44: 30800026                 ba,a    locret_F00CCFDC
F00CCF48: 80a22000                 cmp     %o0, 0
F00CCF4C: 0680000a                 bl      loc_F00CCF74
F00CCF50: 90100018                 mov     %i0, %o0! id
F00CCF54: 133c0506                 sethi   %hi(paResetandenable), %o1
F00CCF58: d2026038                 ld      [%o1+%lo(paResetandenable)], %o1! SEL
F00CCF5C: 40009245                 call    _objc_msgSend
F00CCF60: 94102001                 mov     1, %o2
F00CCF64: 912a2018                 sll     %o0, 24, %o0
F00CCF68: 80a22000                 cmp     %o0, 0
F00CCF6C: 22800002                 be,a    loc_F00CCF74
F00CCF70: a0102005                 mov     5, %l0
F00CCF74: d0062154                 ld      [%i0+0x154], %o0! id
F00CCF78: 133c0506                 sethi   %hi(paDone), %o1
F00CCF7C: d2026034                 ld      [%o1+%lo(paDone)], %o1! SEL
F00CCF80: 4000923c                 call    _objc_msgSend
F00CCF84: 94100010                 mov     %l0, %o2
F00CCF88: 30800015                 ba,a    locret_F00CCFDC
F00CCF8C: 133c0506                 sethi   %hi(paResetandenable), %o1
F00CCF90: d2026038                 ld      [%o1+%lo(paResetandenable)], %o1! SEL
F00CCF94: 40009237                 call    _objc_msgSend
F00CCF98: 94102000                 mov     0, %o2
F00CCF9C: 133c0506                 sethi   %hi(paDone), %o1
F00CCFA0: d0062154                 ld      [%i0+0x154], %o0! id
F00CCFA4: 94102000                 mov     0, %o2
F00CCFA8: d8062128                 ld      [%i0+0x128], %o4
F00CCFAC: 17200000                 sethi   0x80000000, %o3
F00CCFB0: d2026034                 ld      [%o1+%lo(paDone)], %o1! SEL
F00CCFB4: 962b000b                 andn    %o4, %o3, %o3
F00CCFB8: 4000922e                 call    _objc_msgSend
F00CCFBC: d6262128                 st      %o3, [%i0+0x128]
F00CCFC0: 30800007                 ba,a    locret_F00CCFDC
F00CCFC4: 133c0506                 sethi   %hi(paDone), %o1
F00CCFC8: d2026034                 ld      [%o1+%lo(paDone)], %o1! SEL
F00CCFCC: 40009229                 call    _objc_msgSend
F00CCFD0: 94102000                 mov     0, %o2
F00CCFD4: 7ffff492                 call    _IOExitThread
F00CCFD8: 01000000                 nop
F00CCFDC: 81c7e008                 ret
F00CCFE0: 81e80000                 restore
