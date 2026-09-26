F001E598: 9de3bf98                 save    %sp, -0x68, %sp
F001E59C: c6062008                 ld      [%i0+8], %g3
F001E5A0: c4066008                 ld      [%i1+8], %g2
F001E5A4: c420e00c                 st      %g2, [%g3+0xC]
F001E5A8: c6066008                 ld      [%i1+8], %g3
F001E5AC: c4062008                 ld      [%i0+8], %g2
F001E5B0: c420e00c                 st      %g2, [%g3+0xC]
F001E5B4: 05000004                 sethi   0x1000, %g2
F001E5B8: c436203e                 sth     %g2, [%i0+0x3E]
F001E5BC: 07000008                 sethi   0x2000, %g3
F001E5C0: c4162006                 lduh    [%i0+6], %g2
F001E5C4: c6362042                 sth     %g3, [%i0+0x42]
F001E5C8: 8410a022                 bset    0x22, %g2 ! '"'
F001E5CC: c4362006                 sth     %g2, [%i0+6]
F001E5D0: c0366026                 clrh    [%i1+0x26]
F001E5D4: c036602a                 clrh    [%i1+0x2A]
F001E5D8: c4166006                 lduh    [%i1+6], %g2
F001E5DC: 8410a012                 bset    0x12, %g2
F001E5E0: c4366006                 sth     %g2, [%i1+6]
F001E5E4: 81c7e008                 ret
F001E5E8: 91e82001                 restore %g0, 1, %o0
