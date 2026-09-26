F008F3AC: 9de3bf90                 save    %sp, -0x70, %sp
F008F3B0: e007a040                 ld      [%fp+arg_40], %l0
F008F3B4: d0062010                 ld      [%i0+0x10], %o0! id
F008F3B8: 133c0504                 sethi   %hi(paInitstate), %o1
F008F3BC: d2026104                 ld      [%o1+%lo(paInitstate)], %o1! SEL
F008F3C0: e023a040                 st      %l0, [%sp+0x70+var_30]
F008F3C4: 4001892b                 call    _objc_msgSend
F008F3C8: 01000000                 nop
F008F3CC: 00000008                 illtrap
F008F3D0: 81c7e00c                 jmp     %i7+0xC
F008F3D4: 91e80010                 restore %g0, %l0, %o0
