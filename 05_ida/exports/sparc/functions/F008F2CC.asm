F008F2CC: 9de3bf90                 save    %sp, -0x70, %sp
F008F2D0: d0062010                 ld      [%i0+0x10], %o0! id
F008F2D4: 133c0504                 sethi   %hi(paRemovekey), %o1
F008F2D8: d2026080                 ld      [%o1+%lo(paRemovekey)], %o1! SEL
F008F2DC: 40018965                 call    _objc_msgSend
F008F2E0: 9410001a                 mov     %i2, %o2
F008F2E4: 80a22000                 cmp     %o0, 0
F008F2E8: 02800004                 be      locret_F008F2F8
F008F2EC: b0102000                 mov     0, %i0
F008F2F0: 7ffffedb                 call    sub_F008EE5C
F008F2F4: b0102001                 mov     1, %i0
F008F2F8: 81c7e008                 ret
F008F2FC: 81e80000                 restore
