F009A388: 9de3bf98                 save    %sp, -0x68, %sp
F009A38C: 113c04c5                 sethi   %hi(dword_F0131558), %o0
F009A390: e0022158                 ld      [%o0+%lo(dword_F0131558)], %l0
F009A394: 80a42000                 cmp     %l0, 0
F009A398: 0280000a                 be      loc_F009A3C0
F009A39C: a2102000                 mov     0, %l1
F009A3A0: d0042004                 ld      [%l0+4], %o0
F009A3A4: 80a20018                 cmp     %o0, %i0
F009A3A8: 02800034                 be      loc_F009A478
F009A3AC: a2100010                 mov     %l0, %l1
F009A3B0: e0040000                 ld      [%l0], %l0
F009A3B4: 80a42000                 cmp     %l0, 0
F009A3B8: 32bffffb                 bne,a   loc_F009A3A4
F009A3BC: d0042004                 ld      [%l0+4], %o0
F009A3C0: 113c04c5                 sethi   %hi(dword_F0131554), %o0
F009A3C4: e0022154                 ld      [%o0+%lo(dword_F0131554)], %l0
F009A3C8: 80a42000                 cmp     %l0, 0
F009A3CC: 32800019                 bne,a   loc_F009A430
F009A3D0: f0242004                 st      %i0, [%l0+4]
F009A3D4: 113c04c5                 sethi   %hi(dword_F0131558), %o0
F009A3D8: d0022158                 ld      [%o0+%lo(dword_F0131558)], %o0
F009A3DC: 80a22000                 cmp     %o0, 0
F009A3E0: 02800004                 be      loc_F009A3F0
F009A3E4: 113c045c                 sethi   %hi(aMbqStoreTooMan), %o0! "mbq_store: too many callers"
F009A3E8: 7ffdeb62                 call    _panic
F009A3EC: 90122250                 bset    %lo(aMbqStoreTooMan), %o0! "mbq_store: too many callers"
F009A3F0: 96102008                 mov     8, %o3
F009A3F4: 113c04c59012209c         set     unk_F013149C, %o0
F009A3FC: 94022090                 add     %o0, 0x90, %o2
F009A400: 92102080                 mov     0x80, %o1
F009A404: d4224008                 st      %o2, [%o1+%o0]
F009A408: 9402bff0                 inc     -0x10, %o2
F009A40C: 9682ffff                 inccc   -1, %o3
F009A410: 1cbffffd                 bpos    loc_F009A404
F009A414: 92027ff0                 inc     -0x10, %o1
F009A418: 113c04c59012209c         set     unk_F013149C, %o0
F009A420: 133c04c5                 sethi   %hi(dword_F0131554), %o1
F009A424: d0226154                 st      %o0, [%o1+%lo(dword_F0131554)]
F009A428: a0100008                 mov     %o0, %l0
F009A42C: f0242004                 st      %i0, [%l0+4]
F009A430: f2242008                 st      %i1, [%l0+8]
F009A434: f424200c                 st      %i2, [%l0+0xC]
F009A438: 80a6a000                 cmp     %i2, 0
F009A43C: d2040000                 ld      [%l0], %o1
F009A440: 113c04c5                 sethi   %hi(dword_F0131554), %o0
F009A444: 12800005                 bne     loc_F009A458
F009A448: d2222154                 st      %o1, [%o0+%lo(dword_F0131554)]
F009A44C: 113c045c                 sethi   %hi(aWarningMbCallb), %o0! "Warning: MB callback stored at priority"...
F009A450: 7ffde882                 call    _printf
F009A454: 90122270                 bset    %lo(aWarningMbCallb), %o0! "Warning: MB callback stored at priority"...
F009A458: 80a46000                 cmp     %l1, 0
F009A45C: 3280000d                 bne,a   loc_F009A490
F009A460: c0240000                 clr     [%l0]
F009A464: 133c04c5                 sethi   %hi(dword_F0131558), %o1
F009A468: d0026158                 ld      [%o1+%lo(dword_F0131558)], %o0
F009A46C: d0240000                 st      %o0, [%l0]
F009A470: 10800009                 ba      loc_F009A494
F009A474: e0226158                 st      %l0, [%o1+%lo(dword_F0131558)]
F009A478: 133c04c59212613c         set     dword_F013153C, %o1
F009A480: d0026004                 ld      [%o1+4], %o0
F009A484: 90022001                 inc     %o0
F009A488: 10800011                 ba      locret_F009A4CC
F009A48C: d0226004                 st      %o0, [%o1+4]
F009A490: e0244000                 st      %l0, [%l1]
F009A494: 153c04c5                 sethi   %hi(dword_F013153C), %o2
F009A498: d002a13c                 ld      [%o2+%lo(dword_F013153C)], %o0
F009A49C: 173c04c5                 sethi   %hi(dword_F0131550), %o3
F009A4A0: d202e150                 ld      [%o3+%lo(dword_F0131550)], %o1
F009A4A4: 90022001                 inc     %o0
F009A4A8: d022a13c                 st      %o0, [%o2+%lo(dword_F013153C)]
F009A4AC: 92026001                 inc     %o1
F009A4B0: 9412a13c                 bset    %lo(dword_F013153C), %o2
F009A4B4: d002a00c                 ld      [%o2+0xC], %o0
F009A4B8: 80a24008                 cmp     %o1, %o0
F009A4BC: 16800003                 bge     loc_F009A4C8
F009A4C0: d222e150                 st      %o1, [%o3+%lo(dword_F0131550)]
F009A4C4: 92100008                 mov     %o0, %o1
F009A4C8: d222a00c                 st      %o1, [%o2+0xC]
F009A4CC: 81c7e008                 ret
F009A4D0: 81e80000                 restore
