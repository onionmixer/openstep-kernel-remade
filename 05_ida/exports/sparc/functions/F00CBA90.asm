F00CBA90: 9de3bf90                 save    %sp, -0x70, %sp
F00CBA94: a0102000                 mov     0, %l0
F00CBA98: 9010001a                 mov     %i2, %o0! __s1
F00CBA9C: 133c03d3                 sethi   %hi(_IFCONTROL_SETFLAGS), %o1! "setflags"
F00CBAA0: 7ffcf1c3                 call    _strcmp
F00CBAA4: 921260d0                 bset    %lo(_IFCONTROL_SETFLAGS), %o1! "setflags"
F00CBAA8: 80a22000                 cmp     %o0, 0
F00CBAAC: 0280003a                 be      locret_F00CBB94
F00CBAB0: 9010001a                 mov     %i2, %o0! __s1
F00CBAB4: 133c03d3                 sethi   %hi(_IFCONTROL_GETADDR), %o1! "getaddr"
F00CBAB8: 7ffcf1bd                 call    _strcmp
F00CBABC: 921260e8                 bset    %lo(_IFCONTROL_GETADDR), %o1! "getaddr"
F00CBAC0: 80a22000                 cmp     %o0, 0
F00CBAC4: 12800007                 bne     loc_F00CBAE0
F00CBAC8: 9010001a                 mov     %i2, %o0
F00CBACC: 90062150                 add     %i0, 0x150, %o0! __s1
F00CBAD0: 9210001b                 mov     %i3, %o1! void *
F00CBAD4: 7fff240f                 call    _bcopy
F00CBAD8: 94102006                 mov     6, %o2
F00CBADC: 3080002e                 ba,a    locret_F00CBB94
F00CBAE0: 133c03e5                 sethi   %hi(aPromiscuousOn), %o1! "promiscuous-on"
F00CBAE4: 7ffcf1b2                 call    _strcmp
F00CBAE8: 92126188                 bset    %lo(aPromiscuousOn), %o1! "promiscuous-on"
F00CBAEC: 80a22000                 cmp     %o0, 0
F00CBAF0: 12800008                 bne     loc_F00CBB10
F00CBAF4: 9010001a                 mov     %i2, %o0
F00CBAF8: d006212c                 ld      [%i0+0x12C], %o0! id
F00CBAFC: 133c0506                 sethi   %hi(paSend), %o1
F00CBB00: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CBB04: 4000975b                 call    _objc_msgSend
F00CBB08: 94102005                 mov     5, %o2
F00CBB0C: 30800022                 ba,a    locret_F00CBB94
F00CBB10: 133c03e5                 sethi   %hi(aPromiscuousOff), %o1! "promiscuous-off"
F00CBB14: 7ffcf1a6                 call    _strcmp
F00CBB18: 921261a8                 bset    %lo(aPromiscuousOff), %o1! "promiscuous-off"
F00CBB1C: 80a22000                 cmp     %o0, 0
F00CBB20: 12800008                 bne     loc_F00CBB40
F00CBB24: 9010001a                 mov     %i2, %o0
F00CBB28: d006212c                 ld      [%i0+0x12C], %o0! id
F00CBB2C: 133c0506                 sethi   %hi(paSend), %o1
F00CBB30: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00CBB34: 4000974f                 call    _objc_msgSend
F00CBB38: 94102006                 mov     6, %o2
F00CBB3C: 30800016                 ba,a    locret_F00CBB94
F00CBB40: 133c03e5                 sethi   %hi(aAddMulticast), %o1! "add-multicast"
F00CBB44: 7ffcf19a                 call    _strcmp
F00CBB48: 92126178                 bset    %lo(aAddMulticast), %o1! "add-multicast"
F00CBB4C: 80a22000                 cmp     %o0, 0
F00CBB50: 12800006                 bne     loc_F00CBB68
F00CBB54: 9010001a                 mov     %i2, %o0
F00CBB58: 90100018                 mov     %i0, %o0! __s1
F00CBB5C: 133c0506                 sethi   %hi(paEnablemulticas), %o1
F00CBB60: 1080000b                 ba      loc_F00CBB8C
F00CBB64: d202604c                 ld      [%o1+%lo(paEnablemulticas)], %o1
F00CBB68: 133c03e5                 sethi   %hi(aRmvMulticast), %o1! "rmv-multicast"
F00CBB6C: 7ffcf190                 call    _strcmp
F00CBB70: 92126198                 bset    %lo(aRmvMulticast), %o1! "rmv-multicast"
F00CBB74: 80a22000                 cmp     %o0, 0
F00CBB78: 32800007                 bne,a   locret_F00CBB94
F00CBB7C: a0102016                 mov     0x16, %l0
F00CBB80: 90100018                 mov     %i0, %o0! id
F00CBB84: 133c0506                 sethi   %hi(paDisablemultica), %o1
F00CBB88: d2026048                 ld      [%o1+%lo(paDisablemultica)], %o1! SEL
F00CBB8C: 40009739                 call    _objc_msgSend
F00CBB90: 9410001b                 mov     %i3, %o2
F00CBB94: 81c7e008                 ret
F00CBB98: 91e80010                 restore %g0, %l0, %o0
