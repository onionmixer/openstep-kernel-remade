F00C6934: 9de3bf90                 save    %sp, -0x70, %sp
F00C6938: 9410001a                 mov     %i2, %o2
F00C693C: 80a2bbb3                 cmp     %o2, -0x44D
F00C6940: 22800015                 be,a    locret_F00C6994
F00C6944: b0102016                 mov     0x16, %i0
F00C6948: 14800007                 bg      loc_F00C6964
F00C694C: 80a2bbb4                 cmp     %o2, -0x44C
F00C6950: 80a2bbb2                 cmp     %o2, -0x44E
F00C6954: 22800010                 be,a    locret_F00C6994
F00C6958: b0102006                 mov     6, %i0
F00C695C: 10800006                 ba      loc_F00C6974
F00C6960: 113c0507                 sethi   -0xFEBE400, %o0
F00C6964: 12800004                 bne     loc_F00C6974
F00C6968: 113c0507                 sethi   -0xFEBE400, %o0! objc_super *
F00C696C: 1080000a                 ba      locret_F00C6994
F00C6970: b0102006                 mov     6, %i0
F00C6974: d20222e8                 ld      [%o0+0x2E8], %o1
F00C6978: f027bff0                 st      %i0, [%fp+var_10]
F00C697C: d227bff4                 st      %o1, [%fp+var_C]
F00C6980: 133c0504                 sethi   %hi(paErrnofromretur), %o1
F00C6984: d2026194                 ld      [%o1+%lo(paErrnofromretur)], %o1! SEL
F00C6988: 4000abfd                 call    _objc_msgSendSuper
F00C698C: 9007bff0                 add     %fp, var_10, %o0
F00C6990: b0100008                 mov     %o0, %i0
F00C6994: 81c7e008                 ret
F00C6998: 81e80000                 restore
