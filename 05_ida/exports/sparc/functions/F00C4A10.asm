F00C4A10: 9de3bf90                 save    %sp, -0x70, %sp
F00C4A14: 113c04cc                 sethi   %hi(dword_F013304C), %o0
F00C4A18: d002204c                 ld      [%o0+%lo(dword_F013304C)], %o0! id
F00C4A1C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00C4A20: 4000b394                 call    _objc_msgSend
F00C4A24: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00C4A28: 113c04cc                 sethi   %hi(dword_F0133044), %o0
F00C4A2C: d2022044                 ld      [%o0+%lo(dword_F0133044)], %o1
F00C4A30: 90122044                 bset    %lo(dword_F0133044), %o0
F00C4A34: 80a24008                 cmp     %o1, %o0
F00C4A38: 02800018                 be      loc_F00C4A98
F00C4A3C: 96100008                 mov     %o0, %o3
F00C4A40: d0024000                 ld      [%o1], %o0
F00C4A44: 80a2001a                 cmp     %o0, %i2
F00C4A48: 32800011                 bne,a   loc_F00C4A8C
F00C4A4C: d2026014                 ld      [%o1+0x14], %o1
F00C4A50: d4026014                 ld      [%o1+0x14], %o2
F00C4A54: 80a2800b                 cmp     %o2, %o3
F00C4A58: 02800004                 be      loc_F00C4A68
F00C4A5C: d0026018                 ld      [%o1+0x18], %o0
F00C4A60: 10800003                 ba      loc_F00C4A6C
F00C4A64: 9202a014                 add     %o2, 0x14, %o1
F00C4A68: 9210000b                 mov     %o3, %o1
F00C4A6C: 80a2000b                 cmp     %o0, %o3
F00C4A70: 02800004                 be      loc_F00C4A80
F00C4A74: d0226004                 st      %o0, [%o1+4]
F00C4A78: 10800003                 ba      loc_F00C4A84
F00C4A7C: 90022014                 inc     0x14, %o0
F00C4A80: 9010000b                 mov     %o3, %o0
F00C4A84: 10800005                 ba      loc_F00C4A98
F00C4A88: d4220000                 st      %o2, [%o0]
F00C4A8C: 80a2400b                 cmp     %o1, %o3
F00C4A90: 32bfffed                 bne,a   loc_F00C4A44
F00C4A94: d0024000                 ld      [%o1], %o0
F00C4A98: 113c04cc                 sethi   %hi(dword_F013304C), %o0
F00C4A9C: d002204c                 ld      [%o0+%lo(dword_F013304C)], %o0! id
F00C4AA0: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00C4AA4: 4000b373                 call    _objc_msgSend
F00C4AA8: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00C4AAC: 81c7e008                 ret
F00C4AB0: 81e80000                 restore
