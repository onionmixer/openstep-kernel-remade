F0024274: 9de3bf50                 save    %sp, -0xB0, %sp
F0024278: 113c04d4                 sethi   %hi(_rootvfs), %o0
F002427C: e0022160                 ld      [%o0+%lo(_rootvfs)], %l0
F0024280: 80a42000                 cmp     %l0, 0
F0024284: 22800021                 be,a    locret_F0024308
F0024288: b0102016                 mov     0x16, %i0
F002428C: 233c04cf                 sethi   -0xFECC400, %l1
F0024290: d2042004                 ld      [%l0+4], %o1
F0024294: d4026008                 ld      [%o1+8], %o2
F0024298: 90100010                 mov     %l0, %o0
F002429C: 9fc28000                 call    %o2
F00242A0: 9207bfb4                 add     %fp, var_4C, %o1
F00242A4: 80a22000                 cmp     %o0, 0
F00242A8: 32800018                 bne,a   locret_F0024308
F00242AC: b0100008                 mov     %o0, %i0
F00242B0: d007bfb4                 ld      [%fp+var_4C], %o0
F00242B4: d40461d8                 ld      [%l1+0x1D8], %o2
F00242B8: d202201c                 ld      [%o0+0x1C], %o1
F00242BC: d6026014                 ld      [%o1+0x14], %o3
F00242C0: d402a01c                 ld      [%o2+0x1C], %o2
F00242C4: 9fc2c000                 call    %o3
F00242C8: 9207bfb8                 add     %fp, var_48, %o1
F00242CC: 80a22000                 cmp     %o0, 0
F00242D0: 22800004                 be,a    loc_F00242E0
F00242D4: d007bfc4                 ld      [%fp+var_3C], %o0
F00242D8: 1080000c                 ba      locret_F0024308
F00242DC: b0100008                 mov     %o0, %i0
F00242E0: 80a60008                 cmp     %i0, %o0
F00242E4: 32800005                 bne,a   loc_F00242F8
F00242E8: e0040000                 ld      [%l0], %l0
F00242EC: e0264000                 st      %l0, [%i1]
F00242F0: 10800006                 ba      locret_F0024308
F00242F4: b0102000                 mov     0, %i0
F00242F8: 80a42000                 cmp     %l0, 0
F00242FC: 32bfffe6                 bne,a   loc_F0024294
F0024300: d2042004                 ld      [%l0+4], %o1
F0024304: b0102016                 mov     0x16, %i0
F0024308: 81c7e008                 ret
F002430C: 81e80000                 restore
