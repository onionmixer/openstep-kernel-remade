F00BDA30: 9de3bf88                 save    %sp, -0x78, %sp
F00BDA34: 133c04cb                 sethi   %hi(dword_F0132F20), %o1
F00BDA38: d2026320                 ld      [%o1+%lo(dword_F0132F20)], %o1
F00BDA3C: d237bfec                 sth     %o1, [%fp+var_14]
F00BDA40: 133c04cb                 sethi   %hi(dword_F0132F24), %o1
F00BDA44: d6026324                 ld      [%o1+%lo(dword_F0132F24)], %o3
F00BDA48: 90100018                 mov     %i0, %o0
F00BDA4C: 133c04cb                 sethi   %hi(dword_F0132F28), %o1
F00BDA50: d4026328                 ld      [%o1+%lo(dword_F0132F28)], %o2
F00BDA54: d637bfee                 sth     %o3, [%fp+var_12]
F00BDA58: 9402a00c                 inc     0xC, %o2
F00BDA5C: 133c04cb                 sethi   %hi(dword_F0132F2C), %o1
F00BDA60: d602632c                 ld      [%o1+%lo(dword_F0132F2C)], %o3
F00BDA64: d437bfe8                 sth     %o2, [%fp+var_18]
F00BDA68: 9602e03e                 inc     0x3E, %o3 ! '>'
F00BDA6C: 133c0481                 sethi   %hi(off_F0120548), %o1
F00BDA70: d2026148                 ld      [%o1+%lo(off_F0120548)], %o1
F00BDA74: d637bfea                 sth     %o3, [%fp+var_16]
F00BDA78: d227bff0                 st      %o1, [%fp+var_10]
F00BDA7C: d402200c                 ld      [%o0+0xC], %o2
F00BDA80: 9fc28000                 call    %o2
F00BDA84: 9207bfe8                 add     %fp, var_18, %o1
F00BDA88: 81c7e008                 ret
F00BDA8C: 81e80000                 restore
