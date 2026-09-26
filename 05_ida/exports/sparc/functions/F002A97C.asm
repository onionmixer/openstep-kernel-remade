F002A97C: 9de3bf60                 save    %sp, -0xA0, %sp
F002A980: 40000519                 call    _if_private
F002A984: 90100018                 mov     %i0, %o0
F002A988: d2168000                 lduh    [%i2], %o1
F002A98C: a006a002                 add     %i2, 2, %l0
F002A990: 80a26000                 cmp     %o1, 0
F002A994: 02800006                 be      loc_F002A9AC
F002A998: e2022014                 ld      [%o0+0x14], %l1
F002A99C: 80a26002                 cmp     %o1, 2
F002A9A0: 22800024                 be,a    loc_F002AA30
F002A9A4: d206a004                 ld      [%i2+4], %o1
F002A9A8: 30800066                 ba,a    loc_F002AB40
F002A9AC: 90100010                 mov     %l0, %o0! void *
F002A9B0: 9207bfda                 add     %fp, var_26, %o1! void *
F002A9B4: 4001a857                 call    _bcopy
F002A9B8: 94102006                 mov     6, %o2
F002A9BC: 113c0430                 sethi   %hi(unk_F010C266), %o0
F002A9C0: d216a00e                 lduh    [%i2+0xE], %o1
F002A9C4: 90122266                 bset    %lo(unk_F010C266), %o0
F002A9C8: 80a26806                 cmp     %o1, 0x806
F002A9CC: 12800061                 bne     loc_F002AB50
F002A9D0: d2322006                 sth     %o1, [%o0+6]
F002A9D4: 90100019                 mov     %i1, %o0
F002A9D8: 92102000                 mov     0, %o1
F002A9DC: 94102002                 mov     2, %o2
F002A9E0: 173c0430                 sethi   %hi(unk_F010C278), %o3
F002A9E4: 40000451                 call    _nb_write
F002A9E8: 9612e278                 bset    %lo(unk_F010C278), %o3
F002A9EC: 400004fe                 call    _if_private
F002A9F0: 90100018                 mov     %i0, %o0
F002A9F4: d0020000                 ld      [%o0], %o0
F002A9F8: 808a2001                 btst    1, %o0
F002A9FC: 02800009                 be      loc_F002AA20
F002AA00: 92102070                 mov     0x70, %o1 ! 'p'
F002AA04: 90102082                 mov     0x82, %o0
F002AA08: d02fbfe6                 stb     %o0, [%fp+var_1A]
F002AA0C: d00fbfe0                 ldub    [%fp+var_20], %o0
F002AA10: d22fbfe7                 stb     %o1, [%fp+var_19]
F002AA14: 90122080                 bset    0x80, %o0
F002AA18: 1080004e                 ba      loc_F002AB50
F002AA1C: d02fbfe0                 stb     %o0, [%fp+var_20]
F002AA20: d00fbfe0                 ldub    [%fp+var_20], %o0
F002AA24: 900a207f                 and     %o0, 0x7F, %o0
F002AA28: 1080004a                 ba      loc_F002AB50
F002AA2C: d02fbfe0                 stb     %o0, [%fp+var_20]
F002AA30: 90100018                 mov     %i0, %o0
F002AA34: 400004ec                 call    _if_private
F002AA38: d227bfd4                 st      %o1, [%fp+var_2C]
F002AA3C: d0022010                 ld      [%o0+0x10], %o0
F002AA40: d027bfcc                 st      %o0, [%fp+var_34]
F002AA44: 400004e8                 call    _if_private
F002AA48: 90100018                 mov     %i0, %o0
F002AA4C: 9207bfd0                 add     %fp, var_30, %o1
F002AA50: d223a05c                 st      %o1, [%sp+0xA0+var_44]
F002AA54: 92022008                 add     %o0, 8, %o1
F002AA58: 90100018                 mov     %i0, %o0
F002AA5C: 9407bfcc                 add     %fp, var_34, %o2
F002AA60: 96100019                 mov     %i1, %o3
F002AA64: a007bfda                 add     %fp, var_26, %l0
F002AA68: 9807bfd4                 add     %fp, var_2C, %o4
F002AA6C: 40000b08                 call    _arpresolve
F002AA70: 9a100010                 mov     %l0, %o5
F002AA74: 80a22000                 cmp     %o0, 0
F002AA78: 12800004                 bne     loc_F002AA88
F002AA7C: 01000000                 nop
F002AA80: 10800057                 ba      locret_F002ABDC
F002AA84: b0102000                 mov     0, %i0
F002AA88: 400004d7                 call    _if_private
F002AA8C: 90100018                 mov     %i0, %o0
F002AA90: d0020000                 ld      [%o0], %o0
F002AA94: 808a2001                 btst    1, %o0
F002AA98: 02800023                 be      loc_F002AB24
F002AA9C: d00fbfe0                 ldub    [%fp+var_20], %o0
F002AAA0: d00fbfda                 ldub    [%fp+var_26], %o0
F002AAA4: 91322007                 srl     %o0, 7, %o0
F002AAA8: 80a22000                 cmp     %o0, 0
F002AAAC: 02800008                 be      loc_F002AACC
F002AAB0: 901020c2                 mov     0xC2, %o0
F002AAB4: d02fbfe6                 stb     %o0, [%fp+var_1A]
F002AAB8: d00fbfe0                 ldub    [%fp+var_20], %o0
F002AABC: 92102070                 mov     0x70, %o1 ! 'p'
F002AAC0: d22fbfe7                 stb     %o1, [%fp+var_19]
F002AAC4: 10800019                 ba      loc_F002AB28
F002AAC8: 90122080                 bset    0x80, %o0
F002AACC: 400004c6                 call    _if_private
F002AAD0: 90100018                 mov     %i0, %o0
F002AAD4: d20fbfda                 ldub    [%fp+var_26], %o1! data
F002AAD8: 808a6080                 btst    0x80, %o1
F002AADC: 12800014                 bne     loc_F002AB2C
F002AAE0: d0022004                 ld      [%o0+4], %o0! table
F002AAE4: 40030af6                 call    _NXHashGet
F002AAE8: 92100010                 mov     %l0, %o1
F002AAEC: 92920000                 orcc    %o0, %g0, %o1
F002AAF0: 02800003                 be      loc_F002AAFC
F002AAF4: 90102000                 mov     0, %o0
F002AAF8: 9002600c                 add     %o1, 0xC, %o0! void *
F002AAFC: 80a22000                 cmp     %o0, 0
F002AB00: 02800008                 be      loc_F002AB20
F002AB04: 9207bfe6                 add     %fp, var_1A, %o1! void *
F002AB08: d40a0000                 ldub    [%o0], %o2! size_t
F002AB0C: 4001a801                 call    _bcopy
F002AB10: 940aa01f                 and     %o2, 0x1F, %o2
F002AB14: d00fbfe0                 ldub    [%fp+var_20], %o0
F002AB18: 10800004                 ba      loc_F002AB28
F002AB1C: 90122080                 bset    0x80, %o0
F002AB20: d00fbfe0                 ldub    [%fp+var_20], %o0
F002AB24: 900a207f                 and     %o0, 0x7F, %o0
F002AB28: d02fbfe0                 stb     %o0, [%fp+var_20]
F002AB2C: 113c043090122266         set     unk_F010C266, %o0
F002AB34: 92102800                 mov     0x800, %o1
F002AB38: 10800006                 ba      loc_F002AB50
F002AB3C: d2322006                 sth     %o1, [%o0+6]
F002AB40: 400003d9                 call    _nb_free
F002AB44: 90100019                 mov     %i1, %o0
F002AB48: 10800025                 ba      locret_F002ABDC
F002AB4C: b010202f                 mov     0x2F, %i0 ! '/'
F002AB50: 90100019                 mov     %i1, %o0
F002AB54: 4000040e                 call    _nb_grow_top
F002AB58: 92102008                 mov     8, %o1
F002AB5C: 90100019                 mov     %i1, %o0
F002AB60: 92102000                 mov     0, %o1
F002AB64: 94102008                 mov     8, %o2
F002AB68: 173c0430                 sethi   %hi(unk_F010C266), %o3
F002AB6C: 400003ef                 call    _nb_write
F002AB70: 9612e266                 bset    %lo(unk_F010C266), %o3
F002AB74: 4000049c                 call    _if_private
F002AB78: 90100018                 mov     %i0, %o0
F002AB7C: 92100019                 mov     %i1, %o1
F002AB80: d00a2018                 ldub    [%o0+0x18], %o0
F002AB84: 9407bfd8                 add     %fp, var_28, %o2
F002AB88: d02fbfd8                 stb     %o0, [%fp+var_28]
F002AB8C: 90102040                 mov     0x40, %o0 ! '@'
F002AB90: d02fbfd9                 stb     %o0, [%fp+var_27]
F002AB94: 40000413                 call    _if_output
F002AB98: 90100011                 mov     %l1, %o0
F002AB9C: a0920000                 orcc    %o0, %g0, %l0
F002ABA0: 02800009                 be      loc_F002ABC4
F002ABA4: 01000000                 nop
F002ABA8: 400004b3                 call    _if_oerrors
F002ABAC: 90100018                 mov     %i0, %o0
F002ABB0: 92022001                 add     %o0, 1, %o1
F002ABB4: 400004c8                 call    _if_oerrors_set
F002ABB8: 90100018                 mov     %i0, %o0
F002ABBC: 10800008                 ba      locret_F002ABDC
F002ABC0: b0100010                 mov     %l0, %i0
F002ABC4: 400004a4                 call    _if_opackets
F002ABC8: 90100018                 mov     %i0, %o0
F002ABCC: 92022001                 add     %o0, 1, %o1
F002ABD0: 400004b9                 call    _if_opackets_set
F002ABD4: 90100018                 mov     %i0, %o0
F002ABD8: b0100010                 mov     %l0, %i0
F002ABDC: 81c7e008                 ret
F002ABE0: 81e80000                 restore
