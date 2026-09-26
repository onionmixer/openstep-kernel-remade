F006DF44: 9de3bf98                 save    %sp, -0x68, %sp
F006DF48: 113c043f                 sethi   %hi(aMiniMonitorCom), %o0! "Mini-monitor commands:\n"
F006DF4C: 4000002b                 call    _safe_prf
F006DF50: 901223b0                 bset    %lo(aMiniMonitorCom), %o0! "Mini-monitor commands:\n"
F006DF54: 113c043f                 sethi   %hi(aHelpPrintThisM), %o0! "?,help - Print this message\n"
F006DF58: 40000028                 call    _safe_prf
F006DF5C: 901223c8                 bset    %lo(aHelpPrintThisM), %o0! "?,help - Print this message\n"
F006DF60: 113c043f                 sethi   %hi(_miniMonCommands), %o0
F006DF64: d2022188                 ld      [%o0+%lo(_miniMonCommands)], %o1
F006DF68: 80a26000                 cmp     %o1, 0
F006DF6C: 0280000f                 be      loc_F006DFA8
F006DF70: b0122188                 or      %o0, %lo(_miniMonCommands), %i0
F006DF74: 213c043f                 sethi   -0xFEF0400, %l0
F006DF78: d4062008                 ld      [%i0+8], %o2
F006DF7C: 80a2a000                 cmp     %o2, 0
F006DF80: 22800006                 be,a    loc_F006DF98
F006DF84: b006200c                 inc     0xC, %i0
F006DF88: d2060000                 ld      [%i0], %o1
F006DF8C: 4000001b                 call    _safe_prf
F006DF90: 901423e8                 or      %l0, 0x3E8, %o0
F006DF94: b006200c                 inc     0xC, %i0
F006DF98: d0060000                 ld      [%i0], %o0
F006DF9C: 80a22000                 cmp     %o0, 0
F006DFA0: 32bffff7                 bne,a   loc_F006DF7C
F006DFA4: d4062008                 ld      [%i0+8], %o2
F006DFA8: 113c044a                 sethi   %hi(_miniMonMDCommands), %o0
F006DFAC: d20220a0                 ld      [%o0+%lo(_miniMonMDCommands)], %o1
F006DFB0: 80a26000                 cmp     %o1, 0
F006DFB4: 0280000f                 be      locret_F006DFF0
F006DFB8: b01220a0                 or      %o0, %lo(_miniMonMDCommands), %i0
F006DFBC: 213c043f                 sethi   -0xFEF0400, %l0
F006DFC0: d4062008                 ld      [%i0+8], %o2
F006DFC4: 80a2a000                 cmp     %o2, 0
F006DFC8: 22800006                 be,a    loc_F006DFE0
F006DFCC: b006200c                 inc     0xC, %i0
F006DFD0: d2060000                 ld      [%i0], %o1
F006DFD4: 40000009                 call    _safe_prf
F006DFD8: 901423f8                 or      %l0, 0x3F8, %o0
F006DFDC: b006200c                 inc     0xC, %i0
F006DFE0: d0060000                 ld      [%i0], %o0
F006DFE4: 80a22000                 cmp     %o0, 0
F006DFE8: 32bffff7                 bne,a   loc_F006DFC4
F006DFEC: d4062008                 ld      [%i0+8], %o2
F006DFF0: 81c7e008                 ret
F006DFF4: 91e82001                 restore %g0, 1, %o0
