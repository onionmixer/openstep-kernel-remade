F00B09E4: 9de3bf98                 save    %sp, -0x68, %sp
F00B09E8: 113c0470                 sethi   %hi(_dev_opslist), %o0
F00B09EC: 10800009                 ba      loc_F00B0A10
F00B09F0: e00223d0                 ld      [%o0+%lo(_dev_opslist)], %l0
F00B09F4: 9fc24000                 call    %o1
F00B09F8: 90100018                 mov     %i0, %o0
F00B09FC: 80a22000                 cmp     %o0, 0
F00B0A00: 22800004                 be,a    loc_F00B0A10
F00B0A04: e0040000                 ld      [%l0], %l0
F00B0A08: 10800007                 ba      locret_F00B0A24
F00B0A0C: f0042004                 ld      [%l0+4], %i0
F00B0A10: d0042004                 ld      [%l0+4], %o0
F00B0A14: 80a22000                 cmp     %o0, 0
F00B0A18: 32bffff7                 bne,a   loc_F00B09F4
F00B0A1C: d2022004                 ld      [%o0+4], %o1
F00B0A20: b0102000                 mov     0, %i0
F00B0A24: 81c7e008                 ret
F00B0A28: 81e80000                 restore
