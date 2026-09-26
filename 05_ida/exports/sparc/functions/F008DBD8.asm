F008DBD8: 9de3bf80                 save    %sp, -0x80, %sp
F008DBDC: 9410001a                 mov     %i2, %o2
F008DBE0: 80a76000                 cmp     %i5, 0
F008DBE4: 02800029                 be      loc_F008DC88
F008DBE8: f827a054                 st      %i4, [%fp+arg_54]
F008DBEC: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008DBF0: d206c000                 ld      [%i3], %o1
F008DBF4: 9607bfe0                 add     %fp, var_20, %o3
F008DBF8: d227bfe0                 st      %o1, [%fp+var_20]
F008DBFC: d806e004                 ld      [%i3+4], %o4
F008DC00: 133c0504                 sethi   %hi(paInitwithrangeS), %o1
F008DC04: d202608c                 ld      [%o1+%lo(paInitwithrangeS)], %o1! SEL
F008DC08: d827bfe4                 st      %o4, [%fp+var_1C]
F008DC0C: 193c0507                 sethi   %hi(stru_F0141BEC.ext), %o4
F008DC10: d8032018                 ld      [%o4+%lo(stru_F0141BEC.ext)], %o4
F008DC14: f027bff0                 st      %i0, [%fp+var_10]
F008DC18: 40018f59                 call    _objc_msgSendSuper
F008DC1C: d827bff4                 st      %o4, [%fp+var_C]
F008DC20: 80a22000                 cmp     %o0, 0
F008DC24: 12800004                 bne     loc_F008DC34
F008DC28: 9007bfe8                 add     %fp, var_18, %o0
F008DC2C: 1080001c                 ba      locret_F008DC9C
F008DC30: b0102000                 mov     0, %i0
F008DC34: d023a040                 st      %o0, [%sp+0x80+var_40]
F008DC38: 113c0504                 sethi   %hi(paMappedrange_0), %o0
F008DC3C: d2022090                 ld      [%o0+%lo(paMappedrange_0)], %o1! SEL
F008DC40: 90100018                 mov     %i0, %o0! id
F008DC44: 40018f0b                 call    _objc_msgSend
F008DC48: 01000000                 nop
F008DC4C: 00000008                 illtrap
F008DC50: d007bfe8                 ld      [%fp+var_18], %o0
F008DC54: 9407a054                 add     %fp, arg_54, %o2
F008DC58: d207bfec                 ld      [%fp+var_14], %o1
F008DC5C: 9610001d                 mov     %i5, %o3
F008DC60: da07a05c                 ld      [%fp+arg_5C], %o5
F008DC64: 40000063                 call    __KernBusMemoryCreateMapping
F008DC68: 98102000                 mov     0, %o4
F008DC6C: 80a22000                 cmp     %o0, 0
F008DC70: 12800007                 bne     loc_F008DC8C
F008DC74: 113c0503                 sethi   -0xFEBF400, %o0
F008DC78: d007a054                 ld      [%fp+arg_54], %o0
F008DC7C: fa262010                 st      %i5, [%i0+0x10]
F008DC80: 10800007                 ba      locret_F008DC9C
F008DC84: d0262014                 st      %o0, [%i0+0x14]
F008DC88: 113c0503                 sethi   -0xFEBF400, %o0! id
F008DC8C: d20223fc                 ld      [%o0+0x3FC], %o1! SEL
F008DC90: 40018ef8                 call    _objc_msgSend
F008DC94: 90100018                 mov     %i0, %o0
F008DC98: b0100008                 mov     %o0, %i0
F008DC9C: 81c7e008                 ret
F008DCA0: 81e80000                 restore
