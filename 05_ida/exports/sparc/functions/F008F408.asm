F008F408: 9de3bf90                 save    %sp, -0x70, %sp
F008F40C: e007a040                 ld      [%fp+arg_40], %l0
F008F410: d006200c                 ld      [%i0+0xC], %o0! id
F008F414: 133c0504                 sethi   %hi(paInitstate), %o1
F008F418: d2026104                 ld      [%o1+%lo(paInitstate)], %o1! SEL
F008F41C: e023a040                 st      %l0, [%sp+0x70+var_30]
F008F420: 40018914                 call    _objc_msgSend
F008F424: 01000000                 nop
F008F428: 00000008                 illtrap
F008F42C: 81c7e00c                 jmp     %i7+0xC
F008F430: 91e80010                 restore %g0, %l0, %o0
