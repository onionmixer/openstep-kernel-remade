F003BB44: 9de3bf58                 save    %sp, -0xA8, %sp
F003BB48: 90100018                 mov     %i0, %o0
F003BB4C: 40000135                 call    sub_F003C020
F003BB50: 9210001a                 mov     %i2, %o1
F003BB54: b0920000                 orcc    %o0, %g0, %i0
F003BB58: 32800005                 bne,a   loc_F003BB6C
F003BB5C: d0062024                 ld      [%i0+0x24], %o0
F003BB60: 90102046                 mov     0x46, %o0 ! 'F'
F003BB64: 10800016                 ba      locret_F003BBBC
F003BB68: d0264000                 st      %o0, [%i1]
F003BB6C: d4022004                 ld      [%o0+4], %o2
F003BB70: d402a00c                 ld      [%o2+0xC], %o2
F003BB74: 9fc28000                 call    %o2
F003BB78: 9207bfb8                 add     %fp, var_48, %o1
F003BB7C: 80a22000                 cmp     %o0, 0
F003BB80: 1280000d                 bne     loc_F003BBB4
F003BB84: d0264000                 st      %o0, [%i1]
F003BB88: 7ffff80c                 call    _nfstsize
F003BB8C: 01000000                 nop
F003BB90: d0266004                 st      %o0, [%i1+4]
F003BB94: d007bfbc                 ld      [%fp+var_44], %o0
F003BB98: d0266008                 st      %o0, [%i1+8]
F003BB9C: d007bfc0                 ld      [%fp+var_40], %o0
F003BBA0: d026600c                 st      %o0, [%i1+0xC]
F003BBA4: d007bfc4                 ld      [%fp+var_3C], %o0
F003BBA8: d0266010                 st      %o0, [%i1+0x10]
F003BBAC: d007bfc8                 ld      [%fp+var_38], %o0
F003BBB0: d0266014                 st      %o0, [%i1+0x14]
F003BBB4: 7fffb3ec                 call    _vn_rele
F003BBB8: 90100018                 mov     %i0, %o0
F003BBBC: 81c7e008                 ret
F003BBC0: 81e80000                 restore
