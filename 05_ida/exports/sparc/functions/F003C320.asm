F003C320: 9de3bf98                 save    %sp, -0x68, %sp
F003C324: d0060000                 ld      [%i0], %o0
F003C328: 80a22001                 cmp     %o0, 1
F003C32C: 3480001b                 bg,a    loc_F003C398
F003C330: 113c0433                 sethi   -0xFEF3400, %o0
F003C334: 80a22000                 cmp     %o0, 0
F003C338: 06800017                 bl      loc_F003C394
F003C33C: 133c04ea                 sethi   %hi(_unixauthtab), %o1
F003C340: 113c0433                 sethi   %hi(_MAXCLIENTS), %o0
F003C344: d0022180                 ld      [%o0+%lo(_MAXCLIENTS)], %o0
F003C348: 921263a0                 bset    %lo(_unixauthtab), %o1
F003C34C: 912a2003                 sll     %o0, 3, %o0
F003C350: 90020009                 add     %o0, %o1, %o0
F003C354: 80a24008                 cmp     %o1, %o0
F003C358: 1a80000a                 bcc     loc_F003C380
F003C35C: 94100008                 mov     %o0, %o2
F003C360: d0026004                 ld      [%o1+4], %o0
F003C364: 80a20018                 cmp     %o0, %i0
F003C368: 2280000f                 be,a    locret_F003C3A4
F003C36C: c0324000                 clrh    [%o1]
F003C370: 92026008                 inc     8, %o1
F003C374: 80a2400a                 cmp     %o1, %o2
F003C378: 2abffffb                 bcs,a   loc_F003C364
F003C37C: d0026004                 ld      [%o1+4], %o0
F003C380: d0062020                 ld      [%i0+0x20], %o0
F003C384: d2022010                 ld      [%o0+0x10], %o1
F003C388: 9fc24000                 call    %o1
F003C38C: 90100018                 mov     %i0, %o0
F003C390: 30800005                 ba,a    locret_F003C3A4
F003C394: 113c0433                 sethi   -0xFEF3400, %o0! char *
F003C398: d2060000                 ld      [%i0], %o1
F003C39C: 7fff60af                 call    _printf
F003C3A0: 901221a8                 bset    0x1A8, %o0
F003C3A4: 81c7e008                 ret
F003C3A8: 81e80000                 restore
