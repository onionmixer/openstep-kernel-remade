F008CEB4: 9de3bf88                 save    %sp, -0x78, %sp
F008CEB8: 113c0504                 sethi   %hi(paInit), %o0
F008CEBC: d202202c                 ld      [%o0+%lo(paInit)], %o1! SEL
F008CEC0: d8068000                 ld      [%i2], %o4
F008CEC4: d606a004                 ld      [%i2+4], %o3
F008CEC8: 153c0506                 sethi   %hi(stru_F0141B9C.super_class), %o2
F008CECC: d402a3a0                 ld      [%o2+%lo(stru_F0141B9C.super_class)], %o2
F008CED0: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008CED4: f027bff0                 st      %i0, [%fp+var_10]
F008CED8: d427bff4                 st      %o2, [%fp+var_C]
F008CEDC: 400192a8                 call    _objc_msgSendSuper
F008CEE0: a003000b                 add     %o4, %o3, %l0
F008CEE4: d2068000                 ld      [%i2], %o1
F008CEE8: d227bfe8                 st      %o1, [%fp+var_18]
F008CEEC: d006a004                 ld      [%i2+4], %o0
F008CEF0: d027bfec                 st      %o0, [%fp+var_14]
F008CEF4: 90824008                 addcc   %o1, %o0, %o0
F008CEF8: 02800004                 be      loc_F008CF08
F008CEFC: 80a20009                 cmp     %o0, %o1
F008CF00: 08800003                 bleu    loc_F008CF0C
F008CF04: 90102000                 mov     0, %o0
F008CF08: 90102001                 mov     1, %o0
F008CF0C: 80a22000                 cmp     %o0, 0
F008CF10: 12800008                 bne     loc_F008CF30
F008CF14: 80a6e000                 cmp     %i3, 0
F008CF18: 113c0503                 sethi   %hi(paFree), %o0! id
F008CF1C: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F008CF20: 40019254                 call    _objc_msgSend
F008CF24: 90100018                 mov     %i0, %o0
F008CF28: 10800011                 ba      locret_F008CF6C
F008CF2C: b0100008                 mov     %o0, %i0
F008CF30: 02800004                 be      loc_F008CF40
F008CF34: f8262004                 st      %i4, [%i0+4]
F008CF38: 10800008                 ba      loc_F008CF58
F008CF3C: f6262010                 st      %i3, [%i0+0x10]
F008CF40: 113c0506                 sethi   %hi(paKernbusrange), %o0
F008CF44: d0022278                 ld      [%o0+%lo(paKernbusrange)], %o0! id
F008CF48: 133c0504                 sethi   %hi(paClass), %o1! SEL
F008CF4C: 40019249                 call    _objc_msgSend
F008CF50: d2026014                 ld      [%o1+%lo(paClass)], %o1
F008CF54: d0262010                 st      %o0, [%i0+0x10]
F008CF58: c0262014                 clr     [%i0+0x14]
F008CF5C: c0262018                 clr     [%i0+0x18]
F008CF60: e026200c                 st      %l0, [%i0+0xC]
F008CF64: d0068000                 ld      [%i2], %o0
F008CF68: d0262008                 st      %o0, [%i0+8]
F008CF6C: 81c7e008                 ret
F008CF70: 81e80000                 restore
