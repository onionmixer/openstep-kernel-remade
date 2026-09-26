F00F247C: 9de3bf98                 save    %sp, -0x68, %sp
F00F2480: 113c04f6                 sethi   %hi(_NXArgv), %o0
F00F2484: 80a62000                 cmp     %i0, 0
F00F2488: 0280001f                 be      loc_F00F2504
F00F248C: d20221a8                 ld      [%o0+%lo(_NXArgv)], %o1
F00F2490: d006200c                 ld      [%i0+0xC], %o0
F00F2494: 80a22003                 cmp     %o0, 3
F00F2498: 3280001c                 bne,a   locret_F00F2508
F00F249C: f0024000                 ld      [%o1], %i0
F00F24A0: 7fffffe0                 call    sub_F00F2420
F00F24A4: 01000000                 nop
F00F24A8: 9202201c                 add     %o0, 0x1C, %o1
F00F24AC: d0022014                 ld      [%o0+0x14], %o0
F00F24B0: 94024008                 add     %o1, %o0, %o2
F00F24B4: 80a2400a                 cmp     %o1, %o2
F00F24B8: 3a800014                 bcc,a   locret_F00F2508
F00F24BC: b0102000                 mov     0, %i0
F00F24C0: d0024000                 ld      [%o1], %o0
F00F24C4: 80a22006                 cmp     %o0, 6
F00F24C8: 32800007                 bne,a   loc_F00F24E4
F00F24CC: d0026004                 ld      [%o1+4], %o0
F00F24D0: d0026010                 ld      [%o1+0x10], %o0
F00F24D4: 80a20018                 cmp     %o0, %i0
F00F24D8: 22800009                 be,a    loc_F00F24FC
F00F24DC: f0026008                 ld      [%o1+8], %i0
F00F24E0: d0026004                 ld      [%o1+4], %o0
F00F24E4: 92024008                 add     %o1, %o0, %o1
F00F24E8: 80a2400a                 cmp     %o1, %o2
F00F24EC: 2abffff6                 bcs,a   loc_F00F24C4
F00F24F0: d0024000                 ld      [%o1], %o0
F00F24F4: 10800005                 ba      locret_F00F2508
F00F24F8: b0102000                 mov     0, %i0
F00F24FC: 10800003                 ba      locret_F00F2508
F00F2500: b0024018                 add     %o1, %i0, %i0
F00F2504: f0024000                 ld      [%o1], %i0
F00F2508: 81c7e008                 ret
F00F250C: 81e80000                 restore
