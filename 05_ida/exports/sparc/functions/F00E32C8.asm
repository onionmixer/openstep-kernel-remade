F00E32C8: 9de3bf98                 save    %sp, -0x68, %sp
F00E32CC: d6062004                 ld      [%i0+4], %o3
F00E32D0: 9002ff98                 add     %o3, -0x68, %o0
F00E32D4: 80a22100                 cmp     %o0, 0x100
F00E32D8: 18800005                 bgu     loc_F00E32EC
F00E32DC: d00e2003                 ldub    [%i0+3], %o0
F00E32E0: 80a22001                 cmp     %o0, 1
F00E32E4: 22800005                 be,a    loc_F00E32F8
F00E32E8: d0062018                 ld      [%i0+0x18], %o0
F00E32EC: 90103ed0                 mov     -0x130, %o0
F00E32F0: 1080002a                 ba      locret_F00E3398
F00E32F4: d026601c                 st      %o0, [%i1+0x1C]
F00E32F8: 133c03e6                 sethi   %hi(dword_F00F9A1C), %o1
F00E32FC: d202621c                 ld      [%o1+%lo(dword_F00F9A1C)], %o1
F00E3300: 80a20009                 cmp     %o0, %o1
F00E3304: 1280001d                 bne     loc_F00E3378
F00E3308: 90103ed0                 mov     -0x130, %o0
F00E330C: d0062020                 ld      [%i0+0x20], %o0
F00E3310: 133c03e6                 sethi   %hi(dword_F00F9A20), %o1
F00E3314: d2026220                 ld      [%o1+%lo(dword_F00F9A20)], %o1
F00E3318: 80a20009                 cmp     %o0, %o1
F00E331C: 12800017                 bne     loc_F00E3378
F00E3320: 90103ed0                 mov     -0x130, %o0
F00E3324: d4062064                 ld      [%i0+0x64], %o2
F00E3328: 133fffc09212600c         set     -0xFFF4, %o1
F00E3330: 1100880090122008         set     0x2200008, %o0
F00E3338: 920a8009                 and     %o2, %o1, %o1
F00E333C: 80a24008                 cmp     %o1, %o0
F00E3340: 1280000e                 bne     loc_F00E3378
F00E3344: 90103ed0                 mov     -0x130, %o0
F00E3348: 9132a004                 srl     %o2, 4, %o0
F00E334C: 980a2fff                 and     %o0, 0xFFF, %o4
F00E3350: 912b2002                 sll     %o4, 2, %o0
F00E3354: 90022068                 inc     0x68, %o0 ! 'h'
F00E3358: 80a2c008                 cmp     %o3, %o0
F00E335C: 12800007                 bne     loc_F00E3378
F00E3360: 90103ed0                 mov     -0x130, %o0
F00E3364: d006200c                 ld      [%i0+0xC], %o0
F00E3368: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00E336C: d206201c                 ld      [%i0+0x1C], %o1
F00E3370: 7fffc81a                 call    _EvSetParameterInt
F00E3374: 96062068                 add     %i0, 0x68, %o3 ! 'h'
F00E3378: d026601c                 st      %o0, [%i1+0x1C]
F00E337C: d006601c                 ld      [%i1+0x1C], %o0
F00E3380: 80a22000                 cmp     %o0, 0
F00E3384: 12800005                 bne     locret_F00E3398
F00E3388: 96102020                 mov     0x20, %o3 ! ' '
F00E338C: 90102001                 mov     1, %o0
F00E3390: d02e6003                 stb     %o0, [%i1+3]
F00E3394: d6266004                 st      %o3, [%i1+4]
F00E3398: 81c7e008                 ret
F00E339C: 81e80000                 restore
