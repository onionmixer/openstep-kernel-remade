F0091404: 9de3bf98                 save    %sp, -0x68, %sp
F0091408: d6062004                 ld      [%i0+4], %o3
F009140C: 80a2e067                 cmp     %o3, 0x67 ! 'g'
F0091410: 0880002c                 bleu    loc_F00914C0
F0091414: 90103ed0                 mov     -0x130, %o0
F0091418: d0060000                 ld      [%i0], %o0
F009141C: 80a22000                 cmp     %o0, 0
F0091420: 36800004                 bge,a   loc_F0091430
F0091424: d0062018                 ld      [%i0+0x18], %o0
F0091428: 10800026                 ba      loc_F00914C0
F009142C: 90103ed0                 mov     -0x130, %o0
F0091430: 133c0448                 sethi   %hi(dword_F0112284), %o1
F0091434: d2026284                 ld      [%o1+%lo(dword_F0112284)], %o1
F0091438: 80a20009                 cmp     %o0, %o1
F009143C: 12800021                 bne     loc_F00914C0
F0091440: 90103ed0                 mov     -0x130, %o0
F0091444: d0062020                 ld      [%i0+0x20], %o0
F0091448: 133c0448                 sethi   %hi(dword_F0112288), %o1
F009144C: d2026288                 ld      [%o1+%lo(dword_F0112288)], %o1
F0091450: 80a20009                 cmp     %o0, %o1
F0091454: 1280001b                 bne     loc_F00914C0
F0091458: 90103ed0                 mov     -0x130, %o0
F009145C: d4062064                 ld      [%i0+0x64], %o2
F0091460: 133fffc09212600c         set     -0xFFF4, %o1
F0091468: 1100880090122008         set     0x2200008, %o0
F0091470: 920a8009                 and     %o2, %o1, %o1
F0091474: 80a24008                 cmp     %o1, %o0
F0091478: 12800012                 bne     loc_F00914C0
F009147C: 90103ed0                 mov     -0x130, %o0
F0091480: 9132a004                 srl     %o2, 4, %o0
F0091484: 900a2fff                 and     %o0, 0xFFF, %o0
F0091488: 912a2002                 sll     %o0, 2, %o0
F009148C: 90022068                 inc     0x68, %o0 ! 'h'
F0091490: 80a2c008                 cmp     %o3, %o0
F0091494: 1280000b                 bne     loc_F00914C0
F0091498: 90103ed0                 mov     -0x130, %o0
F009149C: 7fff4f99                 call    _convert_port_to_host_priv
F00914A0: d0062008                 ld      [%i0+8], %o0
F00914A4: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00914A8: d8062064                 ld      [%i0+0x64], %o4
F00914AC: 96062068                 add     %i0, 0x68, %o3 ! 'h'
F00914B0: d206201c                 ld      [%i0+0x1C], %o1
F00914B4: 99332004                 srl     %o4, 4, %o4
F00914B8: 7ffffbff                 call    _kern_IOSetIntValues
F00914BC: 980b2fff                 and     %o4, 0xFFF, %o4
F00914C0: d026601c                 st      %o0, [%i1+0x1C]
F00914C4: 81c7e008                 ret
F00914C8: 81e80000                 restore
