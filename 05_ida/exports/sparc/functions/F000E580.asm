F000E580: 9de3bf98                 save    %sp, -0x68, %sp
F000E584: 133c04d2                 sethi   %hi(_freeproc), %o1
F000E588: d00262e0                 ld      [%o1+%lo(_freeproc)], %o0
F000E58C: 80a22000                 cmp     %o0, 0
F000E590: 02800010                 be      locret_F000E5D0
F000E594: 233c04bc                 sethi   %hi(dword_F012F1FC), %l1
F000E598: a0100009                 mov     %o1, %l0
F000E59C: 253c04d3                 sethi   -0xFECB400, %l2
F000E5A0: d00461fc                 ld      [%l1+%lo(dword_F012F1FC)], %o0
F000E5A4: d20422e0                 ld      [%l0+0x2E0], %o1
F000E5A8: 90023fff                 inc     -1, %o0
F000E5AC: d4026008                 ld      [%o1+8], %o2
F000E5B0: d02461fc                 st      %o0, [%l1+0x1FC]
F000E5B4: d004a2a0                 ld      [%l2+0x2A0], %o0
F000E5B8: 4001ab06                 call    _zfree
F000E5BC: d42422e0                 st      %o2, [%l0+0x2E0]
F000E5C0: d00422e0                 ld      [%l0+0x2E0], %o0
F000E5C4: 80a22000                 cmp     %o0, 0
F000E5C8: 12bffff7                 bne     loc_F000E5A4
F000E5CC: d00461fc                 ld      [%l1+0x1FC], %o0
F000E5D0: 81c7e008                 ret
F000E5D4: 81e80000                 restore
