F006DE68: 9de3bf98                 save    %sp, -0x68, %sp
F006DE6C: 113c04f0                 sethi   %hi(_miniMonState), %o0
F006DE70: 80a66000                 cmp     %i1, 0
F006DE74: 0280001e                 be      loc_F006DEEC
F006DE78: f4222280                 st      %i2, [%o0+%lo(_miniMonState)]
F006DE7C: 113c043f                 sethi   %hi(aSystemPanic_0), %o0! "System Panic:\n"
F006DE80: 4000005e                 call    _safe_prf
F006DE84: 90122330                 bset    %lo(aSystemPanic_0), %o0! "System Panic:\n"
F006DE88: 113c043f90122340         set     aS_2, %o0! "%s\n"
F006DE90: 133c04d4                 sethi   %hi(_panicstr), %o1
F006DE94: d2026228                 ld      [%o1+%lo(_panicstr)], %o1
F006DE98: 213c043f                 sethi   -0xFEF0400, %l0
F006DE9C: 333c043f                 sethi   -0xFEF0400, %i1
F006DEA0: 40000056                 call    _safe_prf
F006DEA4: 353c043f                 sethi   -0xFEF0400, %i2
F006DEA8: 113c043f                 sethi   %hi(aTypeRToRebootO), %o0! "(Type 'r' to reboot or 'm' for monitor)"
F006DEAC: 40000053                 call    _safe_prf
F006DEB0: 90122348                 bset    %lo(aTypeRToRebootO), %o0! "(Type 'r' to reboot or 'm' for monitor)"
F006DEB4: 40009a58                 call    _miniMonTryGetchar
F006DEB8: 01000000                 nop
F006DEBC: 80a22072                 cmp     %o0, 0x72 ! 'r'
F006DEC0: 12800007                 bne     loc_F006DEDC
F006DEC4: 80a2206d                 cmp     %o0, 0x6D ! 'm'
F006DEC8: 4000004c                 call    _safe_prf
F006DECC: 90142370                 or      %l0, 0x370, %o0
F006DED0: 40009a3f                 call    _miniMonReboot
F006DED4: 90166380                 or      %i1, 0x380, %o0
F006DED8: 30bffff7                 ba,a    loc_F006DEB4
F006DEDC: 12bffff6                 bne     loc_F006DEB4
F006DEE0: 01000000                 nop
F006DEE4: 40000045                 call    _safe_prf
F006DEE8: 9016a388                 or      %i2, 0x388, %o0
F006DEEC: 113c043f                 sethi   %hi(aNextstepMiniMo), %o0! "NEXTSTEP Mini-monitor\n"
F006DEF0: 40000042                 call    _safe_prf
F006DEF4: 90122390                 bset    %lo(aNextstepMiniMo), %o0! "NEXTSTEP Mini-monitor\n"
F006DEF8: 353c043f                 sethi   %hi(aS_3), %i2! "%s> "
F006DEFC: 113c04beb212209c         set     unk_F012F89C, %i1
F006DF04: 9016a3a8                 or      %i2, %lo(aS_3), %o0! "%s> "
F006DF08: 4000003c                 call    _safe_prf
F006DF0C: 92100018                 mov     %i0, %o1
F006DF10: 90100019                 mov     %i1, %o0
F006DF14: 7fffff9a                 call    sub_F006DD7C
F006DF18: 92102080                 mov     0x80, %o1
F006DF1C: 7fffff5d                 call    sub_F006DC90
F006DF20: 90100019                 mov     %i1, %o0
F006DF24: 80a22000                 cmp     %o0, 0
F006DF28: 12bffff8                 bne     loc_F006DF08
F006DF2C: 9016a3a8                 or      %i2, 0x3A8, %o0
F006DF30: 81c7e008                 ret
F006DF34: 81e80000                 restore
