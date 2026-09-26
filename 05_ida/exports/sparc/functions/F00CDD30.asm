F00CDD30: 9de3bf10                 save    %sp, -0xF0, %sp
F00CDD34: a207bf90                 add     %fp, var_70, %l1
F00CDD38: 90100011                 mov     %l1, %o0! void *
F00CDD3C: 7fff1c47                 call    _bzero
F00CDD40: 92102060                 mov     0x60, %o1 ! '`'
F00CDD44: 90100018                 mov     %i0, %o0! id
F00CDD48: d20e2188                 ldub    [%i0+0x188], %o1
F00CDD4C: 94102000                 mov     0, %o2
F00CDD50: d22fbf90                 stb     %o1, [%fp+var_70]
F00CDD54: d60e2189                 ldub    [%i0+0x189], %o3
F00CDD58: 19200000                 sethi   0x80000000, %o4
F00CDD5C: d62fbf91                 stb     %o3, [%fp+var_6F]
F00CDD60: 96102014                 mov     0x14, %o3
F00CDD64: d627bfa8                 st      %o3, [%fp+var_58]
F00CDD68: d607bfac                 ld      [%fp+var_54], %o3
F00CDD6C: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CDD70: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CDD74: 9612c00c                 bset    %o4, %o3
F00CDD78: 40008ebe                 call    _objc_msgSend
F00CDD7C: d627bfac                 st      %o3, [%fp+var_54]
F00CDD80: a0100008                 mov     %o0, %l0
F00CDD84: 90102003                 mov     3, %o0
F00CDD88: d0240000                 st      %o0, [%l0]
F00CDD8C: e2242014                 st      %l1, [%l0+0x14]
F00CDD90: 90100018                 mov     %i0, %o0! id
F00CDD94: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CDD98: 94100010                 mov     %l0, %o2
F00CDD9C: d8042020                 ld      [%l0+0x20], %o4
F00CDDA0: 17100000                 sethi   0x40000000, %o3
F00CDDA4: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CDDA8: 9813000b                 bset    %o3, %o4
F00CDDAC: 17200000                 sethi   0x80000000, %o3
F00CDDB0: 962b000b                 andn    %o4, %o3, %o3
F00CDDB4: d6242020                 st      %o3, [%l0+0x20]
F00CDDB8: c02fbf94                 clrb    [%fp+var_6C]
F00CDDBC: da07bf94                 ld      [%fp+var_6C], %o5
F00CDDC0: 19003800                 sethi   0xE00000, %o4
F00CDDC4: d60e2189                 ldub    [%i0+0x189], %o3
F00CDDC8: 982b400c                 andn    %o5, %o4, %o4
F00CDDCC: 960ae007                 and     %o3, 7, %o3
F00CDDD0: 972ae015                 sll     %o3, 21, %o3
F00CDDD4: 9813000b                 bset    %o3, %o4
F00CDDD8: 40008ea6                 call    _objc_msgSend
F00CDDDC: d827bf94                 st      %o4, [%fp+var_6C]
F00CDDE0: 90100018                 mov     %i0, %o0! id
F00CDDE4: 94100010                 mov     %l0, %o2
F00CDDE8: d607bfb0                 ld      [%fp+var_50], %o3
F00CDDEC: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CDDF0: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CDDF4: 80a0000b                 cmp     %g0, %o3
F00CDDF8: 40008e9e                 call    _objc_msgSend
F00CDDFC: b0402000                 addc    %g0, 0, %i0
F00CDE00: 81c7e008                 ret
F00CDE04: 81e80000                 restore
