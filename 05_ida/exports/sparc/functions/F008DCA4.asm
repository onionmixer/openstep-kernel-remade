F008DCA4: 9de3bf80                 save    %sp, -0x80, %sp
F008DCA8: 80a72000                 cmp     %i4, 0
F008DCAC: 02800027                 be      loc_F008DD48
F008DCB0: 9410001a                 mov     %i2, %o2
F008DCB4: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F008DCB8: d206c000                 ld      [%i3], %o1
F008DCBC: 9607bfe0                 add     %fp, var_20, %o3
F008DCC0: d227bfe0                 st      %o1, [%fp+var_20]
F008DCC4: d806e004                 ld      [%i3+4], %o4
F008DCC8: 133c0504                 sethi   %hi(paInitwithrangeS), %o1
F008DCCC: d202608c                 ld      [%o1+%lo(paInitwithrangeS)], %o1! SEL
F008DCD0: d827bfe4                 st      %o4, [%fp+var_1C]
F008DCD4: 193c0507                 sethi   %hi(stru_F0141BEC.ext), %o4
F008DCD8: d8032018                 ld      [%o4+%lo(stru_F0141BEC.ext)], %o4
F008DCDC: f027bff0                 st      %i0, [%fp+var_10]
F008DCE0: 40018f27                 call    _objc_msgSendSuper
F008DCE4: d827bff4                 st      %o4, [%fp+var_C]
F008DCE8: 80a22000                 cmp     %o0, 0
F008DCEC: 12800004                 bne     loc_F008DCFC
F008DCF0: 9007bfe8                 add     %fp, var_18, %o0
F008DCF4: 1080001a                 ba      locret_F008DD5C
F008DCF8: b0102000                 mov     0, %i0
F008DCFC: d023a040                 st      %o0, [%sp+0x80+var_40]
F008DD00: 113c0504                 sethi   %hi(paMappedrange_0), %o0
F008DD04: d2022090                 ld      [%o0+%lo(paMappedrange_0)], %o1! SEL
F008DD08: 90100018                 mov     %i0, %o0! id
F008DD0C: 40018ed9                 call    _objc_msgSend
F008DD10: 01000000                 nop
F008DD14: 00000008                 illtrap
F008DD18: 94062014                 add     %i0, 0x14, %o2
F008DD1C: 9610001c                 mov     %i4, %o3
F008DD20: d007bfe8                 ld      [%fp+var_18], %o0
F008DD24: 98102001                 mov     1, %o4
F008DD28: d207bfec                 ld      [%fp+var_14], %o1
F008DD2C: 40000031                 call    __KernBusMemoryCreateMapping
F008DD30: 9a10001d                 mov     %i5, %o5
F008DD34: 80a22000                 cmp     %o0, 0
F008DD38: 12800005                 bne     loc_F008DD4C
F008DD3C: 113c0503                 sethi   -0xFEBF400, %o0
F008DD40: 10800007                 ba      locret_F008DD5C
F008DD44: f8262010                 st      %i4, [%i0+0x10]
F008DD48: 113c0503                 sethi   -0xFEBF400, %o0! id
F008DD4C: d20223fc                 ld      [%o0+0x3FC], %o1! SEL
F008DD50: 40018ec8                 call    _objc_msgSend
F008DD54: 90100018                 mov     %i0, %o0
F008DD58: b0100008                 mov     %o0, %i0
F008DD5C: 81c7e008                 ret
F008DD60: 81e80000                 restore
