F00CCD38: 9de3bf90                 save    %sp, -0x70, %sp
F00CCD3C: d0062128                 ld      [%i0+0x128], %o0
F00CCD40: 80a22000                 cmp     %o0, 0
F00CCD44: 06800006                 bl      loc_F00CCD5C
F00CCD48: a210001b                 mov     %i3, %l1
F00CCD4C: 7ffd7b56                 call    _nb_free
F00CCD50: 9010001a                 mov     %i2, %o0
F00CCD54: 10800048                 ba      locret_F00CCE74
F00CCD58: b0102032                 mov     0x32, %i0 ! '2'
F00CCD5C: 7ffd7b5f                 call    _nb_size
F00CCD60: 9010001a                 mov     %i2, %o0
F00CCD64: d2062138                 ld      [%i0+0x138], %o1
F00CCD68: 80a20009                 cmp     %o0, %o1
F00CCD6C: 0880000f                 bleu    loc_F00CCDA8
F00CCD70: 90100018                 mov     %i0, %o0! id
F00CCD74: 133c0504                 sethi   %hi(paName), %o1
F00CCD78: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CCD7C: 213c03ec                 sethi   %hi(aSNetoutputBadF), %l0! "%s: netOutput bad frame size=%d\n"
F00CCD80: 400092bc                 call    _objc_msgSend
F00CCD84: a01421e8                 bset    %lo(aSNetoutputBadF), %l0! "%s: netOutput bad frame size=%d\n"
F00CCD88: a2100008                 mov     %o0, %l1
F00CCD8C: 7ffd7b53                 call    _nb_size
F00CCD90: 9010001a                 mov     %i2, %o0
F00CCD94: 94100008                 mov     %o0, %o2! size_t
F00CCD98: 90100010                 mov     %l0, %o0
F00CCD9C: 7fffe4d6                 call    _IOLog
F00CCDA0: 92100011                 mov     %l1, %o1
F00CCDA4: 30800031                 ba,a    loc_F00CCE68
F00CCDA8: d00ee008                 ldub    [%i3+8], %o0
F00CCDAC: 808a2080                 btst    0x80, %o0
F00CCDB0: 0280000b                 be      loc_F00CCDDC
F00CCDB4: 92102000                 mov     0, %o1
F00CCDB8: d00ee00e                 ldub    [%i3+0xE], %o0
F00CCDBC: 808a2001                 btst    1, %o0
F00CCDC0: 12800006                 bne     loc_F00CCDD8
F00CCDC4: 920a201f                 and     %o0, 0x1F, %o1
F00CCDC8: 90027ffe                 add     %o1, -2, %o0
F00CCDCC: 80a22010                 cmp     %o0, 0x10
F00CCDD0: 08800004                 bleu    loc_F00CCDE0
F00CCDD4: 80a26000                 cmp     %o1, 0
F00CCDD8: 92103fff                 mov     -1, %o1
F00CCDDC: 80a26000                 cmp     %o1, 0
F00CCDE0: 16800003                 bge     loc_F00CCDEC
F00CCDE4: a002600e                 add     %o1, 0xE, %l0
F00CCDE8: a0100009                 mov     %o1, %l0
F00CCDEC: 80a42000                 cmp     %l0, 0
F00CCDF0: 06800016                 bl      loc_F00CCE48
F00CCDF4: 90100018                 mov     %i0, %o0
F00CCDF8: 9010001a                 mov     %i2, %o0
F00CCDFC: 7ffd7b64                 call    _nb_grow_top
F00CCE00: 92100010                 mov     %l0, %o1
F00CCE04: 7ffd7b24                 call    _nb_map
F00CCE08: 9010001a                 mov     %i2, %o0
F00CCE0C: b6100008                 mov     %o0, %i3
F00CCE10: 90100011                 mov     %l1, %o0! void *
F00CCE14: 9210001b                 mov     %i3, %o1! void *
F00CCE18: 7fff1f3e                 call    _bcopy
F00CCE1C: 94100010                 mov     %l0, %o2
F00CCE20: 90100018                 mov     %i0, %o0! id
F00CCE24: 9410001a                 mov     %i2, %o2
F00CCE28: d60ec000                 ldub    [%i3], %o3
F00CCE2C: 133c0506                 sethi   %hi(paTransmit), %o1
F00CCE30: d2026050                 ld      [%o1+%lo(paTransmit)], %o1! SEL
F00CCE34: 960ae0f0                 and     %o3, 0xF0, %o3
F00CCE38: 4000928e                 call    _objc_msgSend
F00CCE3C: d62ec000                 stb     %o3, [%i3]
F00CCE40: 1080000d                 ba      locret_F00CCE74
F00CCE44: b0102000                 mov     0, %i0
F00CCE48: 133c0504                 sethi   %hi(paName), %o1
F00CCE4C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00CCE50: 213c03ec                 sethi   %hi(aSBadMacHeader), %l0! "%s: bad mac header\n"
F00CCE54: 40009287                 call    _objc_msgSend
F00CCE58: a0142210                 bset    %lo(aSBadMacHeader), %l0! "%s: bad mac header\n"
F00CCE5C: 92100008                 mov     %o0, %o1
F00CCE60: 7fffe4a5                 call    _IOLog
F00CCE64: 90100010                 mov     %l0, %o0
F00CCE68: 7ffd7b0f                 call    _nb_free
F00CCE6C: 9010001a                 mov     %i2, %o0
F00CCE70: b0102028                 mov     0x28, %i0 ! '('
F00CCE74: 81c7e008                 ret
F00CCE78: 81e80000                 restore
