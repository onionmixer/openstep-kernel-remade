F005D3B0: 9de3bf98                 save    %sp, -0x68, %sp
F005D3B4: e2068000                 ld      [%i2], %l1
F005D3B8: 11000040                 sethi   0x10000, %o0
F005D3BC: 808c4008                 btst    %o0, %l1
F005D3C0: 0280004d                 be      loc_F005D4F4
F005D3C4: a6102000                 mov     0, %l3
F005D3C8: 1100003f901223ff         set     0xFFFF, %o0
F005D3D0: a40c4008                 and     %l1, %o0, %l2
F005D3D4: 80a4a001                 cmp     %l2, 1
F005D3D8: 08800047                 bleu    loc_F005D4F4
F005D3DC: 90100018                 mov     %i0, %o0
F005D3E0: 94100019                 mov     %i1, %o2
F005D3E4: e006a004                 ld      [%i2+4], %l0
F005D3E8: 9610001a                 mov     %i2, %o3
F005D3EC: 7ffffaae                 call    _ipc_right_check
F005D3F0: 92100010                 mov     %l0, %o1
F005D3F4: 80a22000                 cmp     %o0, 0
F005D3F8: 02800007                 be      loc_F005D414
F005D3FC: 11001000                 sethi   0x400000, %o0
F005D400: 808c4008                 btst    %o0, %l1
F005D404: 1280003d                 bne     locret_F005D4F8
F005D408: b010200f                 mov     0xF, %i0
F005D40C: 1080003b                 ba      locret_F005D4F8
F005D410: b0102011                 mov     0x11, %i0
F005D414: 80a4a002                 cmp     %l2, 2
F005D418: 3280002b                 bne,a   loc_F005D4C4
F005D41C: d004201c                 ld      [%l0+0x1C], %o0
F005D420: 11000080                 sethi   0x20000, %o0
F005D424: 808c4008                 btst    %o0, %l1
F005D428: 22800009                 be,a    loc_F005D44C
F005D42C: d006a008                 ld      [%i2+8], %o0
F005D430: d004201c                 ld      [%l0+0x1C], %o0
F005D434: 90022001                 inc     %o0
F005D438: d024201c                 st      %o0, [%l0+0x1C]
F005D43C: d0042004                 ld      [%l0+4], %o0
F005D440: 90022002                 inc     2, %o0
F005D444: 1080001d                 ba      loc_F005D4B8
F005D448: d0242004                 st      %o0, [%l0+4]
F005D44C: 80a22000                 cmp     %o0, 0
F005D450: 02800007                 be      loc_F005D46C
F005D454: 90100018                 mov     %i0, %o0
F005D458: 92100010                 mov     %l0, %o1
F005D45C: 94100019                 mov     %i1, %o2
F005D460: 7ffffa43                 call    _ipc_right_dncancel
F005D464: 9610001a                 mov     %i2, %o3
F005D468: a6100008                 mov     %o0, %l3
F005D46C: 90100018                 mov     %i0, %o0
F005D470: 92100010                 mov     %l0, %o1
F005D474: 94100019                 mov     %i1, %o2
F005D478: 7fffdc4e                 call    _ipc_hash_delete
F005D47C: 9610001a                 mov     %i2, %o3
F005D480: 11000800                 sethi   0x200000, %o0
F005D484: 808c4008                 btst    %o0, %l1
F005D488: 22800006                 be,a    loc_F005D4A0
F005D48C: d004201c                 ld      [%l0+0x1C], %o0
F005D490: 90100018                 mov     %i0, %o0
F005D494: 7fffeab7                 call    _ipc_marequest_cancel
F005D498: 92100019                 mov     %i1, %o1
F005D49C: d004201c                 ld      [%l0+0x1C], %o0
F005D4A0: 90022001                 inc     %o0
F005D4A4: d024201c                 st      %o0, [%l0+0x1C]
F005D4A8: d0042004                 ld      [%l0+4], %o0
F005D4AC: 90022001                 inc     %o0
F005D4B0: d0242004                 st      %o0, [%l0+4]
F005D4B4: c026a004                 clr     [%i2+4]
F005D4B8: 113fff80                 sethi   -0x20000, %o0
F005D4BC: 10800008                 ba      loc_F005D4DC
F005D4C0: 900c4008                 and     %l1, %o0, %o0
F005D4C4: 90022002                 inc     2, %o0
F005D4C8: d024201c                 st      %o0, [%l0+0x1C]
F005D4CC: d0042004                 ld      [%l0+4], %o0
F005D4D0: 90022002                 inc     2, %o0
F005D4D4: d0242004                 st      %o0, [%l0+4]
F005D4D8: 90047ffe                 add     %l1, -2, %o0
F005D4DC: d0268000                 st      %o0, [%i2]
F005D4E0: c0240000                 clr     [%l0]
F005D4E4: e026c000                 st      %l0, [%i3]
F005D4E8: e6270000                 st      %l3, [%i4]
F005D4EC: 10800003                 ba      locret_F005D4F8
F005D4F0: b0102000                 mov     0, %i0
F005D4F4: b0102011                 mov     0x11, %i0
F005D4F8: 81c7e008                 ret
F005D4FC: 81e80000                 restore
