F006DC90: 9de3bf98                 save    %sp, -0x68, %sp
F006DC94: a2102000                 mov     0, %l1
F006DC98: 113c043f                 sethi   %hi(_miniMonCommands), %o0
F006DC9C: d2022188                 ld      [%o0+%lo(_miniMonCommands)], %o1
F006DCA0: 80a26000                 cmp     %o1, 0
F006DCA4: 02800010                 be      loc_F006DCE4
F006DCA8: a0122188                 or      %o0, %lo(_miniMonCommands), %l0
F006DCAC: d0040000                 ld      [%l0], %o0
F006DCB0: 7fffffdd                 call    sub_F006DC24
F006DCB4: 92100018                 mov     %i0, %o1
F006DCB8: 80a22000                 cmp     %o0, 0
F006DCBC: 32800006                 bne,a   loc_F006DCD4
F006DCC0: a004200c                 inc     0xC, %l0
F006DCC4: 80a46000                 cmp     %l1, 0
F006DCC8: 12800020                 bne     loc_F006DD48
F006DCCC: a2100010                 mov     %l0, %l1
F006DCD0: a004200c                 inc     0xC, %l0
F006DCD4: d0040000                 ld      [%l0], %o0
F006DCD8: 80a22000                 cmp     %o0, 0
F006DCDC: 12bffff4                 bne     loc_F006DCAC
F006DCE0: 01000000                 nop
F006DCE4: 113c044a                 sethi   %hi(_miniMonMDCommands), %o0
F006DCE8: d20220a0                 ld      [%o0+%lo(_miniMonMDCommands)], %o1
F006DCEC: 80a26000                 cmp     %o1, 0
F006DCF0: 02800010                 be      loc_F006DD30
F006DCF4: a01220a0                 or      %o0, %lo(_miniMonMDCommands), %l0
F006DCF8: d0040000                 ld      [%l0], %o0
F006DCFC: 7fffffca                 call    sub_F006DC24
F006DD00: 92100018                 mov     %i0, %o1
F006DD04: 80a22000                 cmp     %o0, 0
F006DD08: 32800006                 bne,a   loc_F006DD20
F006DD0C: a004200c                 inc     0xC, %l0
F006DD10: 80a46000                 cmp     %l1, 0
F006DD14: 12800010                 bne     loc_F006DD54
F006DD18: a2100010                 mov     %l0, %l1
F006DD1C: a004200c                 inc     0xC, %l0
F006DD20: d0040000                 ld      [%l0], %o0
F006DD24: 80a22000                 cmp     %o0, 0
F006DD28: 12bffff4                 bne     loc_F006DCF8
F006DD2C: 01000000                 nop
F006DD30: 80a46000                 cmp     %l1, 0
F006DD34: 3280000d                 bne,a   loc_F006DD68
F006DD38: d2046004                 ld      [%l1+4], %o1
F006DD3C: 113c043f                 sethi   %hi(aInvalidCommand), %o0! "Invalid command - type '?' for help\n"
F006DD40: 10800007                 ba      loc_F006DD5C
F006DD44: 90122308                 bset    %lo(aInvalidCommand), %o0! "Invalid command - type '?' for help\n"
F006DD48: 113c043f                 sethi   %hi(aAmbiguousComma), %o0! "Ambiguous command - type '?' for help\n"
F006DD4C: 10800004                 ba      loc_F006DD5C
F006DD50: 901222b8                 bset    %lo(aAmbiguousComma), %o0! "Ambiguous command - type '?' for help\n"
F006DD54: 113c043f901222e0         set     aAmbiguousComma_0, %o0! "Ambiguous command - type '?' for help\n"
F006DD5C: 400000a7                 call    _safe_prf
F006DD60: b0102001                 mov     1, %i0
F006DD64: 30800004                 ba,a    locret_F006DD74
F006DD68: 9fc24000                 call    %o1
F006DD6C: 90100018                 mov     %i0, %o0
F006DD70: b0100008                 mov     %o0, %i0
F006DD74: 81c7e008                 ret
F006DD78: 81e80000                 restore
