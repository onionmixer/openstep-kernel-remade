F002D918: 9de3bf88                 save    %sp, -0x78, %sp
F002D91C: d016200c                 lduh    [%i0+0xC], %o0
F002D920: 808a2080                 btst    0x80, %o0
F002D924: 12800027                 bne     loc_F002D9C0
F002D928: f4068000                 ld      [%i2], %i2
F002D92C: d016e008                 lduh    [%i3+8], %o0
F002D930: 80a22007                 cmp     %o0, 7
F002D934: 08800023                 bleu    loc_F002D9C0
F002D938: 9207bff0                 add     %fp, var_10, %o1! void *
F002D93C: d006e004                 ld      [%i3+4], %o0! void *
F002D940: 94102008                 mov     8, %o2! size_t
F002D944: 40019c73                 call    _bcopy
F002D948: 9006c008                 add     %i3, %o0, %o0
F002D94C: d017bff0                 lduh    [%fp+var_10], %o0
F002D950: d417bff2                 lduh    [%fp+var_E], %o2
F002D954: 80a22001                 cmp     %o0, 1
F002D958: 113c0430                 sethi   %hi(_arpethertempl), %o0
F002D95C: 12800019                 bne     loc_F002D9C0
F002D960: 92122354                 or      %o0, %lo(_arpethertempl), %o1
F002D964: d00a6004                 ldub    [%o1+4], %o0
F002D968: d20a6005                 ldub    [%o1+5], %o1
F002D96C: 90020009                 add     %o0, %o1, %o0
F002D970: 912a2001                 sll     %o0, 1, %o0
F002D974: d256e008                 ldsh    [%i3+8], %o1
F002D978: 90022008                 inc     8, %o0
F002D97C: 80a24008                 cmp     %o1, %o0
F002D980: 0a800010                 bcs     loc_F002D9C0
F002D984: 912aa010                 sll     %o2, 16, %o0
F002D988: 933a2010                 sra     %o0, 16, %o1
F002D98C: 80a26800                 cmp     %o1, 0x800
F002D990: 02800005                 be      loc_F002D9A4
F002D994: 11000004                 sethi   0x1000, %o0
F002D998: 80a24008                 cmp     %o1, %o0
F002D99C: 12800009                 bne     loc_F002D9C0
F002D9A0: 01000000                 nop
F002D9A4: f427bfec                 st      %i2, [%fp+var_14]
F002D9A8: 90100018                 mov     %i0, %o0
F002D9AC: 92100019                 mov     %i1, %o1
F002D9B0: 9407bfec                 add     %fp, var_14, %o2
F002D9B4: 40000007                 call    _in_arpinput
F002D9B8: 9610001b                 mov     %i3, %o3
F002D9BC: 30800003                 ba,a    locret_F002D9C8
F002D9C0: 7fffc0a9                 call    _m_freem
F002D9C4: 9010001b                 mov     %i3, %o0
F002D9C8: 81c7e008                 ret
F002D9CC: 81e80000                 restore
