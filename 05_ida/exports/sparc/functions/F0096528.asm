F0096528: 9de3bfa0                 save    %sp, -0x60, %sp
F009652C: 83480000                 rdhpr   %hpstate, %g1
F0096530: 84286020                 andn    %g1, 0x20, %g2
F0096534: 81888000                 saved
F0096538: 01000000                 nop
F009653C: 01000000                 nop
F0096540: 01000000                 nop
F0096544: 90100000                 clr     %o0
F0096548: 133c000892126000         set     _start, %o1
F0096550: 17000020                 sethi   0x8000, %o3
F0096554: 94100009                 mov     %o1, %o2
F0096558: c0028000                 ld      [%o2], %g0
F009655C: 90022020                 inc     0x20, %o0 ! ' '
F0096560: 80a2000b                 cmp     %o0, %o3
F0096564: 04bffffd                 ble     loc_F0096558
F0096568: 94024008                 add     %o1, %o0, %o2
F009656C: 3b100000                 sethi   0x40000000, %i5
F0096570: 90102000                 mov     0, %o0
F0096574: 9210200e                 mov     0xE, %o1
F0096578: 39200000                 sethi   0x80000000, %i4
F009657C: b4102000                 mov     0, %i2
F0096580: a416801d                 or      %i2, %i5, %l2
F0096584: d0bc81c0                 stda    %o0, [%l2]0xE
F0096588: 31010000                 sethi   0x4000000, %i0
F009658C: 37030000                 sethi   0xC000000, %i3
F0096590: a416001c                 or      %i0, %i4, %l2
F0096594: a4168012                 bset    %i2, %l2
F0096598: 94102000                 mov     0, %o2
F009659C: 96102000                 mov     0, %o3
F00965A0: d4bc81c0                 stda    %o2, [%l2]0xE
F00965A4: a6102000                 mov     0, %l3
F00965A8: b2168018                 or      %i2, %i0, %i1
F00965AC: a52ce003                 sll     %l3, 3, %l2
F00965B0: a4164012                 bset    %i1, %l2
F00965B4: 94102000                 mov     0, %o2
F00965B8: 96102000                 mov     0, %o3
F00965BC: d4bc81e0                 stda    %o2, [%l2]0xF
F00965C0: a604e001                 inc     %l3
F00965C4: 80a4e003                 cmp     %l3, 3
F00965C8: 04bffffa                 ble     loc_F00965B0
F00965CC: a52ce003                 sll     %l3, 3, %l2
F00965D0: 25010000                 sethi   0x4000000, %l2
F00965D4: b0060012                 add     %i0, %l2, %i0
F00965D8: 80a6001b                 cmp     %i0, %i3
F00965DC: 24bfffee                 ble,a   loc_F0096594
F00965E0: a416001c                 or      %i0, %i4, %l2
F00965E4: b406a020                 inc     0x20, %i2 ! ' '
F00965E8: 80a6afe0                 cmp     %i2, 0xFE0
F00965EC: 04bfffe6                 ble     loc_F0096584
F00965F0: a416801d                 or      %i2, %i5, %l2
F00965F4: 81884000                 saved
F00965F8: 01000000                 nop
F00965FC: 01000000                 nop
F0096600: 01000000                 nop
F0096604: 81c7e008                 ret
F0096608: 81e80000                 restore
