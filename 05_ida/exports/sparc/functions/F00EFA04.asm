F00EFA04: 9de3bf98                 save    %sp, -0x68, %sp
F00EFA08: d2062004                 ld      [%i0+4], %o1
F00EFA0C: d0062010                 ld      [%i0+0x10], %o0
F00EFA10: 808a2002                 btst    2, %o0
F00EFA14: 12800003                 bne     loc_F00EFA20
F00EFA18: 90100018                 mov     %i0, %o0
F00EFA1C: d0060000                 ld      [%i0], %o0
F00EFA20: d0022010                 ld      [%o0+0x10], %o0
F00EFA24: 808a2004                 btst    4, %o0
F00EFA28: 12800029                 bne     locret_F00EFACC
F00EFA2C: 80a26000                 cmp     %o1, 0
F00EFA30: 2280000e                 be,a    loc_F00EFA68
F00EFA34: d0062010                 ld      [%i0+0x10], %o0
F00EFA38: d0026010                 ld      [%o1+0x10], %o0
F00EFA3C: 808a2002                 btst    2, %o0
F00EFA40: 12800003                 bne     loc_F00EFA4C
F00EFA44: 90100009                 mov     %o1, %o0
F00EFA48: d0024000                 ld      [%o1], %o0
F00EFA4C: d0022010                 ld      [%o0+0x10], %o0
F00EFA50: 808a2004                 btst    4, %o0
F00EFA54: 32800005                 bne,a   loc_F00EFA68
F00EFA58: d0062010                 ld      [%i0+0x10], %o0
F00EFA5C: 7fffffea                 call    sub_F00EFA04
F00EFA60: 90100009                 mov     %o1, %o0
F00EFA64: d0062010                 ld      [%i0+0x10], %o0
F00EFA68: 808a2002                 btst    2, %o0
F00EFA6C: 12800003                 bne     loc_F00EFA78
F00EFA70: 90100018                 mov     %i0, %o0
F00EFA74: d0060000                 ld      [%i0], %o0
F00EFA78: d0022010                 ld      [%o0+0x10], %o0
F00EFA7C: 808a2004                 btst    4, %o0
F00EFA80: 12800013                 bne     locret_F00EFACC
F00EFA84: 01000000                 nop
F00EFA88: d0062010                 ld      [%i0+0x10], %o0
F00EFA8C: 808a2002                 btst    2, %o0
F00EFA90: 12800005                 bne     loc_F00EFAA4
F00EFA94: 92100018                 mov     %i0, %o1
F00EFA98: d2060000                 ld      [%i0], %o1
F00EFA9C: d0062010                 ld      [%i0+0x10], %o0
F00EFAA0: 808a2002                 btst    2, %o0
F00EFAA4: 12800003                 bne     loc_F00EFAB0
F00EFAA8: 90100018                 mov     %i0, %o0
F00EFAAC: d0060000                 ld      [%i0], %o0
F00EFAB0: d0022010                 ld      [%o0+0x10], %o0
F00EFAB4: 90122004                 bset    4, %o0
F00EFAB8: d0226010                 st      %o0, [%o1+0x10]
F00EFABC: 133c0505                 sethi   %hi(paInitialize), %o1! SEL
F00EFAC0: 90100018                 mov     %i0, %o0! id
F00EFAC4: 4000076b                 call    _objc_msgSend
F00EFAC8: d20263ec                 ld      [%o1+%lo(paInitialize)], %o1
F00EFACC: 81c7e008                 ret
F00EFAD0: 81e80000                 restore
