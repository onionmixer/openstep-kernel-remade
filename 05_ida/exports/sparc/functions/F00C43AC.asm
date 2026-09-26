F00C43AC: 9de3bf90                 save    %sp, -0x70, %sp
F00C43B0: 90100018                 mov     %i0, %o0! id
F00C43B4: 133c0504                 sethi   %hi(paStringforkey), %o1! SEL
F00C43B8: e002610c                 ld      [%o1+%lo(paStringforkey)], %l0
F00C43BC: 9410001a                 mov     %i2, %o2
F00C43C0: 4000b52c                 call    _objc_msgSend
F00C43C4: 92100010                 mov     %l0, %o1
F00C43C8: a2100008                 mov     %o0, %l1
F00C43CC: 90100018                 mov     %i0, %o0! id
F00C43D0: 92100010                 mov     %l0, %o1! SEL
F00C43D4: 153c04ba                 sethi   %hi(aPromName_0), %o2! "Prom Name"
F00C43D8: 4000b526                 call    _objc_msgSend
F00C43DC: 9412a250                 bset    %lo(aPromName_0), %o2! "Prom Name"
F00C43E0: 80a22000                 cmp     %o0, 0
F00C43E4: 02800008                 be      loc_F00C4404
F00C43E8: 133c04ba                 sethi   %hi(aPseudo_0), %o1! "pseudo"
F00C43EC: 7ffd0f70                 call    _strcmp
F00C43F0: 92126260                 bset    %lo(aPseudo_0), %o1! "pseudo"
F00C43F4: 80a00008                 cmp     %g0, %o0
F00C43F8: 90603fff                 subc    %g0, -1, %o0
F00C43FC: 10800003                 ba      loc_F00C4408
F00C4400: a0100008                 mov     %o0, %l0
F00C4404: a0102001                 mov     1, %l0
F00C4408: 7fffffe0                 call    sub_F00C4388
F00C440C: 9010001a                 mov     %i2, %o0
F00C4410: 912a2018                 sll     %o0, 24, %o0
F00C4414: 80a22000                 cmp     %o0, 0
F00C4418: 12800004                 bne     loc_F00C4428
F00C441C: 80a46000                 cmp     %l1, 0
F00C4420: 02800026                 be      locret_F00C44B8
F00C4424: 01000000                 nop
F00C4428: 7fffffd8                 call    sub_F00C4388
F00C442C: 9010001a                 mov     %i2, %o0
F00C4430: 912a2018                 sll     %o0, 24, %o0
F00C4434: 913a2018                 sra     %o0, 24, %o0
F00C4438: 80a22001                 cmp     %o0, 1
F00C443C: 3280000c                 bne,a   loc_F00C446C
F00C4440: f027bff0                 st      %i0, [%fp+var_10]
F00C4444: 80a42000                 cmp     %l0, 0
F00C4448: 32800009                 bne,a   loc_F00C446C
F00C444C: f027bff0                 st      %i0, [%fp+var_10]
F00C4450: 90100018                 mov     %i0, %o0! id
F00C4454: 133c0504                 sethi   %hi(paParseintrresou), %o1
F00C4458: d2026390                 ld      [%o1+%lo(paParseintrresou)], %o1! SEL
F00C445C: 4000b505                 call    _objc_msgSend
F00C4460: 9410001a                 mov     %i2, %o2
F00C4464: 1080000c                 ba      loc_F00C4494
F00C4468: 94100008                 mov     %o0, %o2
F00C446C: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00C4470: 133c0507                 sethi   %hi(stru_F0141E6C.super_class), %o1
F00C4474: d6026270                 ld      [%o1+%lo(stru_F0141E6C.super_class)], %o3
F00C4478: 9410001a                 mov     %i2, %o2
F00C447C: 133c0504                 sethi   %hi(paAllocateresour_0), %o1
F00C4480: d2026078                 ld      [%o1+%lo(paAllocateresour_0)], %o1! SEL
F00C4484: 4000b53e                 call    _objc_msgSendSuper
F00C4488: d627bff4                 st      %o3, [%fp+var_C]
F00C448C: 1080000b                 ba      locret_F00C44B8
F00C4490: b0100008                 mov     %o0, %i0
F00C4494: 80a2a000                 cmp     %o2, 0
F00C4498: 02800007                 be      loc_F00C44B4
F00C449C: 90100018                 mov     %i0, %o0! id
F00C44A0: 133c0504                 sethi   %hi(paSetresourcesFo), %o1
F00C44A4: d2026118                 ld      [%o1+%lo(paSetresourcesFo)], %o1! SEL
F00C44A8: 4000b4f2                 call    _objc_msgSend
F00C44AC: 9610001a                 mov     %i2, %o3
F00C44B0: 30800002                 ba,a    locret_F00C44B8
F00C44B4: b0102000                 mov     0, %i0
F00C44B8: 81c7e008                 ret
F00C44BC: 81e80000                 restore
