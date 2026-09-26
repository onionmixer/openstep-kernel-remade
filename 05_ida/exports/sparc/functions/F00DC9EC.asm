F00DC9EC: 9de3bf90                 save    %sp, -0x70, %sp
F00DC9F0: f027bff0                 st      %i0, [%fp+var_10]
F00DC9F4: 113c0508                 sethi   %hi(stru_F01422CC.ext), %o0! objc_super *
F00DC9F8: 9410001a                 mov     %i2, %o2
F00DC9FC: 9610001b                 mov     %i3, %o3
F00DCA00: 9810001c                 mov     %i4, %o4
F00DCA04: d20222f8                 ld      [%o0+%lo(stru_F01422CC.ext)], %o1
F00DCA08: 9a10001d                 mov     %i5, %o5
F00DCA0C: d227bff4                 st      %o1, [%fp+var_C]
F00DCA10: 133c0505                 sethi   %hi(paCanconvertregi), %o1
F00DCA14: d2026068                 ld      [%o1+%lo(paCanconvertregi)], %o1! SEL
F00DCA18: 400053d9                 call    _objc_msgSendSuper
F00DCA1C: 9007bff0                 add     %fp, var_10, %o0
F00DCA20: 912a2018                 sll     %o0, 24, %o0
F00DCA24: 80a22000                 cmp     %o0, 0
F00DCA28: 3280001b                 bne,a   locret_F00DCA94
F00DCA2C: b0102001                 mov     1, %i0
F00DCA30: 80a72002                 cmp     %i4, 2
F00DCA34: 02800015                 be      loc_F00DCA88
F00DCA38: 80a72004                 cmp     %i4, 4
F00DCA3C: 02800013                 be      loc_F00DCA88
F00DCA40: 11000015                 sethi   0x5400, %o0
F00DCA44: 94122222                 or      %o0, 0x222, %o2
F00DCA48: 80a6c00a                 cmp     %i3, %o2
F00DCA4C: 12800007                 bne     loc_F00DCA68
F00DCA50: 1100002b                 sethi   0xAC00, %o0
F00DCA54: d2062064                 ld      [%i0+0x64], %o1
F00DCA58: 90122044                 bset    0x44, %o0 ! 'D'
F00DCA5C: 80a24008                 cmp     %o1, %o0
F00DCA60: 0280000c                 be      loc_F00DCA90
F00DCA64: 1100002b                 sethi   0xAC00, %o0
F00DCA68: 90122044                 bset    0x44, %o0 ! 'D'
F00DCA6C: 80a6c008                 cmp     %i3, %o0
F00DCA70: 32800009                 bne,a   locret_F00DCA94
F00DCA74: b0102000                 mov     0, %i0
F00DCA78: d0062064                 ld      [%i0+0x64], %o0
F00DCA7C: 80a2000a                 cmp     %o0, %o2
F00DCA80: 02800005                 be      locret_F00DCA94
F00DCA84: b0102001                 mov     1, %i0
F00DCA88: 10800003                 ba      locret_F00DCA94
F00DCA8C: b0102000                 mov     0, %i0
F00DCA90: b0102001                 mov     1, %i0
F00DCA94: 81c7e008                 ret
F00DCA98: 81e80000                 restore
