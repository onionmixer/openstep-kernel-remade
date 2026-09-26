F0024C48: 9de3bf98                 save    %sp, -0x68, %sp
F0024C4C: a2100018                 mov     %i0, %l1
F0024C50: 11000008                 sethi   0x2000, %o0
F0024C54: 80a44008                 cmp     %l1, %o0
F0024C58: 04800004                 ble     loc_F0024C68
F0024C5C: 113c042f                 sethi   %hi(aGeteblkSizeToo), %o0! "geteblk: size too big"
F0024C60: 7fffc144                 call    _panic
F0024C64: 90122350                 bset    %lo(aGeteblkSizeToo), %o0! "geteblk: size too big"
F0024C68: 400000ad                 call    _getnewbuf
F0024C6C: 213c04cf                 sethi   %hi(unk_F0133E68), %l0
F0024C70: b0100008                 mov     %o0, %i0
F0024C74: d2060000                 ld      [%i0], %o1
F0024C78: 15000040                 sethi   0x10000, %o2
F0024C7C: 9212400a                 bset    %o2, %o1
F0024C80: 400215fd                 call    _bfree
F0024C84: d2260000                 st      %o1, [%i0]
F0024C88: d2062008                 ld      [%i0+8], %o1
F0024C8C: d0062004                 ld      [%i0+4], %o0
F0024C90: d0226004                 st      %o0, [%o1+4]
F0024C94: d4062004                 ld      [%i0+4], %o2
F0024C98: a0142268                 bset    %lo(unk_F0133E68), %l0
F0024C9C: d2062008                 ld      [%i0+8], %o1
F0024CA0: 90100018                 mov     %i0, %o0
F0024CA4: 4000027b                 call    sub_F0025690
F0024CA8: d222a008                 st      %o1, [%o2+8]
F0024CAC: c036201c                 clrh    [%i0+0x1C]
F0024CB0: c0262028                 clr     [%i0+0x28]
F0024CB4: d0042004                 ld      [%l0+4], %o0
F0024CB8: d0262004                 st      %o0, [%i0+4]
F0024CBC: e0262008                 st      %l0, [%i0+8]
F0024CC0: d2042004                 ld      [%l0+4], %o1
F0024CC4: 90100018                 mov     %i0, %o0
F0024CC8: f0226008                 st      %i0, [%o1+8]
F0024CCC: f0242004                 st      %i0, [%l0+4]
F0024CD0: 40000007                 call    _brealloc
F0024CD4: 92100011                 mov     %l1, %o1
F0024CD8: 80a22000                 cmp     %o0, 0
F0024CDC: 02bfffe3                 be      loc_F0024C68
F0024CE0: 01000000                 nop
F0024CE4: 81c7e008                 ret
F0024CE8: 81e80000                 restore
