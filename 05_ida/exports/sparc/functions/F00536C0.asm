F00536C0: 9de3bf90                 save    %sp, -0x70, %sp
F00536C4: b8100018                 mov     %i0, %i4
F00536C8: e2072030                 ld      [%i4+0x30], %l1
F00536CC: d0146044                 lduh    [%l1+0x44], %o0
F00536D0: 808a2001                 btst    1, %o0
F00536D4: 0280000b                 be      loc_F0053700
F00536D8: f227bff4                 st      %i1, [%fp+var_C]
F00536DC: 90122010                 bset    0x10, %o0
F00536E0: d0346044                 sth     %o0, [%l1+0x44]
F00536E4: 90100011                 mov     %l1, %o0! unsigned int
F00536E8: 7ffefbe4                 call    _sleep
F00536EC: 9210200a                 mov     0xA, %o1
F00536F0: d0146044                 lduh    [%l1+0x44], %o0
F00536F4: 808a2001                 btst    1, %o0
F00536F8: 12bffffa                 bne     loc_F00536E0
F00536FC: 90122010                 bset    0x10, %o0
F0053700: b0102000                 mov     0, %i0
F0053704: d0146044                 lduh    [%l1+0x44], %o0
F0053708: 3b3c04cf                 sethi   -0xFECC400, %i5
F005370C: f2046040                 ld      [%l1+0x40], %i1
F0053710: 2f3c04d4                 sethi   -0xFECB000, %l7
F0053714: e8046050                 ld      [%l1+0x50], %l4
F0053718: 90122001                 bset    1, %o0
F005371C: d0346044                 sth     %o0, [%l1+0x44]
F0053720: ec052030                 ld      [%l4+0x30], %l6
F0053724: d0052048                 ld      [%l4+0x48], %o0
F0053728: a610001a                 mov     %i2, %l3
F005372C: aa2ec008                 andn    %i3, %o0, %l5
F0053730: 92258015                 sub     %l6, %l5, %o1
F0053734: d0052050                 ld      [%l4+0x50], %o0
F0053738: 80a2401a                 cmp     %o1, %i2
F005373C: 1a800003                 bcc     loc_F0053748
F0053740: a536c008                 srl     %i3, %o0, %l2
F0053744: a6100009                 mov     %o1, %l3
F0053748: 90100011                 mov     %l1, %o0
F005374C: 92100012                 mov     %l2, %o1
F0053750: d60761dc                 ld      [%i5+0x1DC], %o3
F0053754: 94102020                 mov     0x20, %o2 ! ' '
F0053758: e04ae038                 ldsb    [%o3+0x38], %l0
F005375C: 98102000                 mov     0, %o4
F0053760: c02ae038                 clrb    [%o3+0x38]
F0053764: 7fffdce4                 call    _bmap
F0053768: 96054013                 add     %l5, %l3, %o3
F005376C: d20761dc                 ld      [%i5+0x1DC], %o1
F0053770: d4052064                 ld      [%l4+0x64], %o2
F0053774: d64a6038                 ldsb    [%o1+0x38], %o3
F0053778: 992a000a                 sll     %o0, %o2, %o4
F005377C: 80a2e000                 cmp     %o3, 0
F0053780: 12800005                 bne     loc_F0053794
F0053784: e02a6038                 stb     %l0, [%o1+0x38]
F0053788: 80a32000                 cmp     %o4, 0
F005378C: 3680000a                 bge,a   loc_F00537B4
F0053790: d0046070                 ld      [%l1+0x70], %o0
F0053794: 113c043c90122270         set     aIoErrorOnPageo, %o0! "IO error on pageout: error = %d.\n"
F005379C: d4070000                 ld      [%i4], %o2
F00537A0: 9210000b                 mov     %o3, %o1
F00537A4: 7fff03ad                 call    _printf
F00537A8: d222a034                 st      %o1, [%o2+0x34]
F00537AC: 10800035                 ba      loc_F0053880
F00537B0: 1b00003f                 sethi   0xFC00, %o5
F00537B4: 9206c013                 add     %i3, %l3, %o1
F00537B8: 80a24008                 cmp     %o1, %o0
F00537BC: 38800002                 bgu,a   loc_F00537C4
F00537C0: d2246070                 st      %o1, [%l1+0x70]
F00537C4: 80a4a00b                 cmp     %l2, 0xB
F00537C8: 34800011                 bg,a    loc_F005380C
F00537CC: e4052030                 ld      [%l4+0x30], %l2
F00537D0: d2052050                 ld      [%l4+0x50], %o1
F00537D4: 9004a001                 add     %l2, 1, %o0
F00537D8: d4046070                 ld      [%l1+0x70], %o2
F00537DC: 912a0009                 sll     %o0, %o1, %o0
F00537E0: 80a28008                 cmp     %o2, %o0
F00537E4: 2a800004                 bcs,a   loc_F00537F4
F00537E8: d0052048                 ld      [%l4+0x48], %o0
F00537EC: 10800008                 ba      loc_F005380C
F00537F0: e4052030                 ld      [%l4+0x30], %l2
F00537F4: d2052034                 ld      [%l4+0x34], %o1
F00537F8: 902a8008                 andn    %o2, %o0, %o0
F00537FC: 90020009                 add     %o0, %o1, %o0
F0053800: d205204c                 ld      [%l4+0x4C], %o1
F0053804: 90023fff                 inc     -1, %o0
F0053808: a40a0009                 and     %o0, %o1, %l2
F005380C: 80a4c016                 cmp     %l3, %l6
F0053810: 12800007                 bne     loc_F005382C
F0053814: 90100019                 mov     %i1, %o0
F0053818: 9210000c                 mov     %o4, %o1
F005381C: 7fff4493                 call    _getblk
F0053820: 94100012                 mov     %l2, %o2
F0053824: 10800006                 ba      loc_F005383C
F0053828: a0100008                 mov     %o0, %l0
F005382C: 9210000c                 mov     %o4, %o1
F0053830: 7fff433c                 call    _bread
F0053834: 94100012                 mov     %l2, %o2
F0053838: a0100008                 mov     %o0, %l0
F005383C: d0042028                 ld      [%l0+0x28], %o0
F0053840: 90248008                 sub     %l2, %o0, %o0
F0053844: 80a4c008                 cmp     %l3, %o0
F0053848: 34800002                 bg,a    loc_F0053850
F005384C: a6100008                 mov     %o0, %l3
F0053850: d0040000                 ld      [%l0], %o0
F0053854: 808a2004                 btst    4, %o0
F0053858: 02800018                 be      loc_F00538B8
F005385C: 90100010                 mov     %l0, %o0
F0053860: d4070000                 ld      [%i4], %o2
F0053864: d254201c                 ldsh    [%l0+0x1C], %o1
F0053868: 7fff4400                 call    _brelse
F005386C: d222a034                 st      %o1, [%o2+0x34]
F0053870: 113c043c                 sethi   %hi(aIoErrorOnPageo_0), %o0! "IO error on pageout (bread)\n"
F0053874: 7fff0379                 call    _printf
F0053878: 90122298                 bset    %lo(aIoErrorOnPageo_0), %o0! "IO error on pageout (bread)\n"
F005387C: 1b00003f                 sethi   0xFC00, %o5
F0053880: d0146044                 lduh    [%l1+0x44], %o0
F0053884: 9a1363fe                 bset    0x3FE, %o5
F0053888: 900a000d                 and     %o0, %o5, %o0
F005388C: 808a2010                 btst    0x10, %o0
F0053890: 02800008                 be      loc_F00538B0
F0053894: d0346044                 sth     %o0, [%l1+0x44]
F0053898: 1b00003f9a1363ef         set     0xFFEF, %o5
F00538A0: 900a000d                 and     %o0, %o5, %o0
F00538A4: d0346044                 sth     %o0, [%l1+0x44]
F00538A8: 7ffefd50                 call    _wakeup
F00538AC: 90100011                 mov     %l1, %o0
F00538B0: 10800043                 ba      locret_F00539BC
F00538B4: b0102002                 mov     2, %i0
F00538B8: 94100013                 mov     %l3, %o2
F00538BC: b4268013                 sub     %i2, %l3, %i2
F00538C0: da07bff4                 ld      [%fp+var_C], %o5
F00538C4: b606c013                 add     %i3, %l3, %i3
F00538C8: d2042020                 ld      [%l0+0x20], %o1
F00538CC: 90034018                 add     %o5, %i0, %o0
F00538D0: b0060013                 add     %i0, %l3, %i0
F00538D4: 40013062                 call    _copy_from_phys
F00538D8: 92024015                 add     %o1, %l5, %o1
F00538DC: 9004c015                 add     %l3, %l5, %o0
F00538E0: 80a20016                 cmp     %o0, %l6
F00538E4: 12800009                 bne     loc_F0053908
F00538E8: 90100010                 mov     %l0, %o0
F00538EC: d2020000                 ld      [%o0], %o1
F00538F0: 15001000                 sethi   0x400000, %o2
F00538F4: 9212400a                 bset    %o2, %o1
F00538F8: 7fff43d4                 call    _bawrite
F00538FC: d2220000                 st      %o1, [%o0]
F0053900: 10800005                 ba      loc_F0053914
F0053904: d2146044                 lduh    [%l1+0x44], %o1
F0053908: 7fff43bf                 call    _bdwrite
F005390C: 90100010                 mov     %l0, %o0
F0053910: d2146044                 lduh    [%l1+0x44], %o1
F0053914: 9015e148                 or      %l7, 0x148, %o0
F0053918: d4146064                 lduh    [%l1+0x64], %o2
F005391C: 92126042                 bset    0x42, %o1 ! 'B'
F0053920: d2346044                 sth     %o1, [%l1+0x44]
F0053924: 940ab3ff                 and     %o2, -0xC01, %o2
F0053928: 40006b2a                 call    _microtime
F005392C: d4346064                 sth     %o2, [%l1+0x64]
F0053930: d0146044                 lduh    [%l1+0x44], %o0
F0053934: 808a2004                 btst    4, %o0
F0053938: 02800003                 be      loc_F0053944
F005393C: d005e148                 ld      [%l7+0x148], %o0
F0053940: d0246074                 st      %o0, [%l1+0x74]
F0053944: d0146044                 lduh    [%l1+0x44], %o0
F0053948: 808a2002                 btst    2, %o0
F005394C: 02800003                 be      loc_F0053958
F0053950: d005e148                 ld      [%l7+0x148], %o0
F0053954: d024607c                 st      %o0, [%l1+0x7C]
F0053958: d0146044                 lduh    [%l1+0x44], %o0
F005395C: 808a2040                 btst    0x40, %o0 ! '@'
F0053960: 02800005                 be      loc_F0053974
F0053964: 80a6a000                 cmp     %i2, 0
F0053968: c024604c                 clr     [%l1+0x4C]
F005396C: d005e148                 ld      [%l7+0x148], %o0
F0053970: d0246084                 st      %o0, [%l1+0x84]
F0053974: 02800004                 be      loc_F0053984
F0053978: 80a4e000                 cmp     %l3, 0
F005397C: 32bfff6b                 bne,a   loc_F0053728
F0053980: d0052048                 ld      [%l4+0x48], %o0
F0053984: d2146044                 lduh    [%l1+0x44], %o1
F0053988: 1100003f901223fe         set     0xFFFE, %o0
F0053990: 920a4008                 and     %o1, %o0, %o1
F0053994: 808a6010                 btst    0x10, %o1
F0053998: 02800008                 be      loc_F00539B8
F005399C: d2346044                 sth     %o1, [%l1+0x44]
F00539A0: 1100003f901223ef         set     0xFFEF, %o0
F00539A8: 900a4008                 and     %o1, %o0, %o0
F00539AC: d0346044                 sth     %o0, [%l1+0x44]
F00539B0: 7ffefd0e                 call    _wakeup
F00539B4: 90100011                 mov     %l1, %o0
F00539B8: b0102000                 mov     0, %i0
F00539BC: 81c7e008                 ret
F00539C0: 81e80000                 restore
