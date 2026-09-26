F009131C: 9de3bf90                 save    %sp, -0x70, %sp
F0091320: d0062004                 ld      [%i0+4], %o0
F0091324: 80a2206c                 cmp     %o0, 0x6C ! 'l'
F0091328: 12800018                 bne     loc_F0091388
F009132C: 90103ed0                 mov     -0x130, %o0
F0091330: d0060000                 ld      [%i0], %o0
F0091334: 80a22000                 cmp     %o0, 0
F0091338: 06800013                 bl      loc_F0091384
F009133C: 133c0448                 sethi   %hi(dword_F0112274), %o1
F0091340: d0062018                 ld      [%i0+0x18], %o0
F0091344: d2026274                 ld      [%o1+%lo(dword_F0112274)], %o1
F0091348: 80a20009                 cmp     %o0, %o1
F009134C: 1280000f                 bne     loc_F0091388
F0091350: 90103ed0                 mov     -0x130, %o0
F0091354: d0062020                 ld      [%i0+0x20], %o0
F0091358: 133c0448                 sethi   %hi(dword_F0112278), %o1
F009135C: d2026278                 ld      [%o1+%lo(dword_F0112278)], %o1
F0091360: 80a20009                 cmp     %o0, %o1
F0091364: 12800009                 bne     loc_F0091388
F0091368: 90103ed0                 mov     -0x130, %o0
F009136C: d0062064                 ld      [%i0+0x64], %o0
F0091370: 133c0448                 sethi   %hi(dword_F011227C), %o1
F0091374: d202627c                 ld      [%o1+%lo(dword_F011227C)], %o1
F0091378: 80a20009                 cmp     %o0, %o1
F009137C: 02800005                 be      loc_F0091390
F0091380: 92102200                 mov     0x200, %o1
F0091384: 90103ed0                 mov     -0x130, %o0
F0091388: 1080001d                 ba      locret_F00913FC
F009138C: d026601c                 st      %o0, [%i1+0x1C]
F0091390: d0062008                 ld      [%i0+8], %o0
F0091394: 7fff4fbe                 call    _convert_port_to_host
F0091398: d227bff4                 st      %o1, [%fp+var_C]
F009139C: 94062024                 add     %i0, 0x24, %o2 ! '$'
F00913A0: d206201c                 ld      [%i0+0x1C], %o1
F00913A4: 98066024                 add     %i1, 0x24, %o4 ! '$'
F00913A8: d6062068                 ld      [%i0+0x68], %o3
F00913AC: 7ffffc2e                 call    _kern_IOGetCharValues
F00913B0: 9a07bff4                 add     %fp, var_C, %o5
F00913B4: 80a22000                 cmp     %o0, 0
F00913B8: 12800011                 bne     locret_F00913FC
F00913BC: d026601c                 st      %o0, [%i1+0x1C]
F00913C0: 113c0448                 sethi   %hi(dword_F0112280), %o0
F00913C4: d4022280                 ld      [%o0+%lo(dword_F0112280)], %o2
F00913C8: d207bff4                 ld      [%fp+var_C], %o1
F00913CC: d4266020                 st      %o2, [%i1+0x20]
F00913D0: 113fffc09012200f         set     -0xFFF1, %o0
F00913D8: 940a8008                 and     %o2, %o0, %o2
F00913DC: 900a6fff                 and     %o1, 0xFFF, %o0
F00913E0: 912a2004                 sll     %o0, 4, %o0
F00913E4: 94128008                 bset    %o0, %o2
F00913E8: d4266020                 st      %o2, [%i1+0x20]
F00913EC: 92026003                 inc     3, %o1
F00913F0: 920a7ffc                 and     %o1, -4, %o1
F00913F4: 92026024                 inc     0x24, %o1 ! '$'
F00913F8: d2266004                 st      %o1, [%i1+4]
F00913FC: 81c7e008                 ret
F0091400: 81e80000                 restore
