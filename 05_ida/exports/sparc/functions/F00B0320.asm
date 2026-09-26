F00B0320: 9de3bf98                 save    %sp, -0x68, %sp
F00B0324: 113c0470                 sethi   %hi(_obp_romvec_version), %o0
F00B0328: d0022278                 ld      [%o0+%lo(_obp_romvec_version)], %o0
F00B032C: 80a22000                 cmp     %o0, 0
F00B0330: 02800005                 be      loc_F00B0344
F00B0334: a0102000                 mov     0, %l0
F00B0338: 80a22002                 cmp     %o0, 2
F00B033C: 12800009                 bne     loc_F00B0360
F00B0340: 80a40019                 cmp     %l0, %i1
F00B0344: 113c000c                 sethi   %hi(_romp), %o0
F00B0348: d2022030                 ld      [%o0+%lo(_romp)], %o1
F00B034C: d4026060                 ld      [%o1+0x60], %o2
F00B0350: 90100018                 mov     %i0, %o0
F00B0354: 9fc28000                 call    %o2
F00B0358: 92100019                 mov     %i1, %o1
F00B035C: 30800010                 ba,a    locret_F00B039C
F00B0360: 1a80000f                 bcc     locret_F00B039C
F00B0364: 233c000c                 sethi   %hi(_romp), %l1
F00B0368: d4046030                 ld      [%l1+%lo(_romp)], %o2
F00B036C: d002a094                 ld      [%o2+0x94], %o0
F00B0370: d602a0b8                 ld      [%o2+0xB8], %o3
F00B0374: 92100018                 mov     %i0, %o1
F00B0378: d0020000                 ld      [%o0], %o0
F00B037C: 9fc2c000                 call    %o3
F00B0380: 94264010                 sub     %i1, %l0, %o2
F00B0384: 80a23fff                 cmp     %o0, -1
F00B0388: 32800002                 bne,a   loc_F00B0390
F00B038C: a0040008                 add     %l0, %o0, %l0
F00B0390: 80a40019                 cmp     %l0, %i1
F00B0394: 0abffff6                 bcs     loc_F00B036C
F00B0398: d4046030                 ld      [%l1+0x30], %o2
F00B039C: 81c7e008                 ret
F00B03A0: 81e80000                 restore
