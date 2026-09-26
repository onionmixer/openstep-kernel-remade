F0044748: 9de3bf90                 save    %sp, -0x70, %sp
F004474C: 90100019                 mov     %i1, %o0
F0044750: 9210001a                 mov     %i2, %o1
F0044754: 4000002d                 call    sub_F0044808
F0044758: 9407bff4                 add     %fp, var_C, %o2
F004475C: 94920000                 orcc    %o0, %g0, %o2
F0044760: 02800007                 be      loc_F004477C
F0044764: 01000000                 nop
F0044768: d002a00c                 ld      [%o2+0xC], %o0
F004476C: 80a2001b                 cmp     %o0, %i3
F0044770: 0280000d                 be      loc_F00447A4
F0044774: b0102000                 mov     0, %i0
F0044778: 3080000c                 ba,a    locret_F00447A8
F004477C: 40008e3d                 call    _kalloc
F0044780: 90102010                 mov     0x10, %o0
F0044784: 94100008                 mov     %o0, %o2
F0044788: f222a004                 st      %i1, [%o2+4]
F004478C: f422a008                 st      %i2, [%o2+8]
F0044790: 133c04bd                 sethi   %hi(dword_F012F558), %o1
F0044794: d0026158                 ld      [%o1+%lo(dword_F012F558)], %o0
F0044798: f622a00c                 st      %i3, [%o2+0xC]
F004479C: d0228000                 st      %o0, [%o2]
F00447A0: d4226158                 st      %o2, [%o1+%lo(dword_F012F558)]
F00447A4: b0102001                 mov     1, %i0
F00447A8: 81c7e008                 ret
F00447AC: 81e80000                 restore
