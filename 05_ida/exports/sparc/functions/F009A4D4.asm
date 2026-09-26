F009A4D4: 9de3bf98                 save    %sp, -0x68, %sp
F009A4D8: 113c04c5                 sethi   %hi(dword_F0131558), %o0
F009A4DC: e0022158                 ld      [%o0+%lo(dword_F0131558)], %l0
F009A4E0: 80a42000                 cmp     %l0, 0
F009A4E4: 02800034                 be      locret_F009A5B4
F009A4E8: a2102000                 mov     0, %l1
F009A4EC: 92102000                 mov     0, %o1
F009A4F0: 253c04c5                 sethi   -0xFECEC00, %l2
F009A4F4: a8100008                 mov     %o0, %l4
F009A4F8: 273c04c5                 sethi   -0xFECEC00, %l3
F009A4FC: d004200c                 ld      [%l0+0xC], %o0
F009A500: 80a20018                 cmp     %o0, %i0
F009A504: 0680001d                 bl      loc_F009A578
F009A508: 80a46000                 cmp     %l1, 0
F009A50C: d6042004                 ld      [%l0+4], %o3
F009A510: 02800009                 be      loc_F009A534
F009A514: d4042008                 ld      [%l0+8], %o2
F009A518: d0040000                 ld      [%l0], %o0
F009A51C: d204a154                 ld      [%l2+0x154], %o1
F009A520: d0244000                 st      %o0, [%l1]
F009A524: d2240000                 st      %o1, [%l0]
F009A528: e024a154                 st      %l0, [%l2+0x154]
F009A52C: 10800008                 ba      loc_F009A54C
F009A530: e0044000                 ld      [%l1], %l0
F009A534: d2040000                 ld      [%l0], %o1
F009A538: d004a154                 ld      [%l2+0x154], %o0
F009A53C: d2252158                 st      %o1, [%l4+0x158]
F009A540: d0240000                 st      %o0, [%l0]
F009A544: e024a154                 st      %l0, [%l2+0x154]
F009A548: a0100009                 mov     %o1, %l0
F009A54C: d204e150                 ld      [%l3+0x150], %o1
F009A550: 9010000a                 mov     %o2, %o0
F009A554: 92027fff                 inc     -1, %o1
F009A558: 9fc2c000                 call    %o3
F009A55C: d224e150                 st      %o1, [%l3+0x150]
F009A560: 92100008                 mov     %o0, %o1
F009A564: 80a27fff                 cmp     %o1, -1
F009A568: 02800013                 be      locret_F009A5B4
F009A56C: 113c04c5                 sethi   -0xFECEC00, %o0
F009A570: 10800005                 ba      loc_F009A584
F009A574: 80a42000                 cmp     %l0, 0
F009A578: a2100010                 mov     %l0, %l1
F009A57C: e0040000                 ld      [%l0], %l0
F009A580: 80a42000                 cmp     %l0, 0
F009A584: 32bfffdf                 bne,a   loc_F009A500
F009A588: d004200c                 ld      [%l0+0xC], %o0
F009A58C: 80a27fff                 cmp     %o1, -1
F009A590: 02800009                 be      locret_F009A5B4
F009A594: 113c04c5                 sethi   %hi(dword_F0131558), %o0
F009A598: d0022158                 ld      [%o0+%lo(dword_F0131558)], %o0
F009A59C: 80a22000                 cmp     %o0, 0
F009A5A0: 02800005                 be      locret_F009A5B4
F009A5A4: 113c0269                 sethi   %hi(sub_F009A5BC), %o0
F009A5A8: 901221bc                 bset    %lo(sub_F009A5BC), %o0
F009A5AC: 7ffffd28                 call    _softcall
F009A5B0: 92102000                 mov     0, %o1
F009A5B4: 81c7e008                 ret
F009A5B8: 81e80000                 restore
