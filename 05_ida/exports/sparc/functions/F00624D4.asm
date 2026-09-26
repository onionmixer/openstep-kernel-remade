F00624D4: 9de3bf88                 save    %sp, -0x78, %sp
F00624D8: 80a62000                 cmp     %i0, 0
F00624DC: 12800004                 bne     loc_F00624EC
F00624E0: 80a6a004                 cmp     %i2, 4
F00624E4: 10800030                 ba      locret_F00625A4
F00624E8: b0102010                 mov     0x10, %i0
F00624EC: 08800004                 bleu    loc_F00624FC
F00624F0: 90100018                 mov     %i0, %o0
F00624F4: 1080002c                 ba      locret_F00625A4
F00624F8: b0102012                 mov     0x12, %i0
F00624FC: 92100019                 mov     %i1, %o1
F0062500: 7fffe55f                 call    _ipc_right_lookup_write
F0062504: 9407bff4                 add     %fp, var_C, %o2
F0062508: a0920000                 orcc    %o0, %g0, %l0
F006250C: 32800026                 bne,a   locret_F00625A4
F0062510: b0100010                 mov     %l0, %i0
F0062514: 90100018                 mov     %i0, %o0
F0062518: 92100019                 mov     %i1, %o1
F006251C: d407bff4                 ld      [%fp+var_C], %o2
F0062520: 9607bff0                 add     %fp, var_10, %o3
F0062524: 7fffe9e7                 call    _ipc_right_info
F0062528: 9807bfec                 add     %fp, var_14, %o4
F006252C: a0920000                 orcc    %o0, %g0, %l0
F0062530: 3280001d                 bne,a   locret_F00625A4
F0062534: b0100010                 mov     %l0, %i0
F0062538: c0262008                 clr     [%i0+8]
F006253C: 9006a010                 add     %i2, 0x10, %o0
F0062540: 94102001                 mov     1, %o2
F0062544: d207bff0                 ld      [%fp+var_10], %o1
F0062548: 912a8008                 sll     %o2, %o0, %o0
F006254C: 808a4008                 btst    %o0, %o1
F0062550: 02800013                 be      loc_F006259C
F0062554: 80a6a003                 cmp     %i2, 3
F0062558: 18800006                 bgu     loc_F0062570
F006255C: 80a6a001                 cmp     %i2, 1
F0062560: 3a800010                 bcc,a   loc_F00625A0
F0062564: d426c000                 st      %o2, [%i3]
F0062568: 10800007                 ba      loc_F0062584
F006256C: d007bfec                 ld      [%fp+var_14], %o0
F0062570: 80a6a004                 cmp     %i2, 4
F0062574: 02800004                 be      loc_F0062584
F0062578: d007bfec                 ld      [%fp+var_14], %o0
F006257C: 10800004                 ba      loc_F006258C
F0062580: 113c043e                 sethi   -0xFEF0800, %o0! char *
F0062584: 10800007                 ba      loc_F00625A0
F0062588: d026c000                 st      %o0, [%i3]
F006258C: 7ffecaf9                 call    _panic
F0062590: 90122038                 bset    0x38, %o0 ! '8'
F0062594: 10800004                 ba      locret_F00625A4
F0062598: b0100010                 mov     %l0, %i0
F006259C: c026c000                 clr     [%i3]
F00625A0: b0100010                 mov     %l0, %i0
F00625A4: 81c7e008                 ret
F00625A8: 81e80000                 restore
