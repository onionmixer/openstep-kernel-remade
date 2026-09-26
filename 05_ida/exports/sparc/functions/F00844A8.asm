F00844A8: 9de3bf98                 save    %sp, -0x68, %sp
F00844AC: a2100018                 mov     %i0, %l1
F00844B0: a004603c                 add     %l1, 0x3C, %l0 ! '<'
F00844B4: d0040000                 ld      [%l0], %o0
F00844B8: 80a22000                 cmp     %o0, 0
F00844BC: 12bffffe                 bne     loc_F00844B4
F00844C0: 01000000                 nop
F00844C4: 40004a79                 call    _simple_lock_try
F00844C8: 90100010                 mov     %l0, %o0
F00844CC: 80a22000                 cmp     %o0, 0
F00844D0: 02bffff9                 be      loc_F00844B4
F00844D4: 01000000                 nop
F00844D8: e0046038                 ld      [%l1+0x38], %l0
F00844DC: c024603c                 clr     [%l1+0x3C]
F00844E0: 9204600c                 add     %l1, 0xC, %o1
F00844E4: 80a40009                 cmp     %l0, %o1
F00844E8: 22800002                 be,a    loc_F00844F0
F00844EC: e0046010                 ld      [%l1+0x10], %l0
F00844F0: d0042008                 ld      [%l0+8], %o0
F00844F4: 80a64008                 cmp     %i1, %o0
F00844F8: 0a80000a                 bcs     loc_F0084520
F00844FC: 80a40009                 cmp     %l0, %o1
F0084500: 02800021                 be      loc_F0084584
F0084504: 01000000                 nop
F0084508: d004200c                 ld      [%l0+0xC], %o0
F008450C: 80a20019                 cmp     %o0, %i1
F0084510: 0880001c                 bleu    loc_F0084580
F0084514: b0102001                 mov     1, %i0
F0084518: 1080002c                 ba      locret_F00845C8
F008451C: e0268000                 st      %l0, [%i2]
F0084520: d2042004                 ld      [%l0+4], %o1
F0084524: 10800017                 ba      loc_F0084580
F0084528: e0046010                 ld      [%l1+0x10], %l0
F008452C: 80a20019                 cmp     %o0, %i1
F0084530: 28800014                 bleu,a  loc_F0084580
F0084534: e0042004                 ld      [%l0+4], %l0
F0084538: d0042008                 ld      [%l0+8], %o0
F008453C: 80a64008                 cmp     %i1, %o0
F0084540: 0a800013                 bcs     loc_F008458C
F0084544: b004603c                 add     %l1, 0x3C, %i0 ! '<'
F0084548: e0268000                 st      %l0, [%i2]
F008454C: d0060000                 ld      [%i0], %o0
F0084550: 80a22000                 cmp     %o0, 0
F0084554: 12bffffe                 bne     loc_F008454C
F0084558: 01000000                 nop
F008455C: 40004a53                 call    _simple_lock_try
F0084560: 90100018                 mov     %i0, %o0
F0084564: 80a22000                 cmp     %o0, 0
F0084568: 02bffff9                 be      loc_F008454C
F008456C: 01000000                 nop
F0084570: e0246038                 st      %l0, [%l1+0x38]
F0084574: c024603c                 clr     [%l1+0x3C]
F0084578: 10800014                 ba      locret_F00845C8
F008457C: b0102001                 mov     1, %i0
F0084580: 80a40009                 cmp     %l0, %o1
F0084584: 32bfffea                 bne,a   loc_F008452C
F0084588: d004200c                 ld      [%l0+0xC], %o0
F008458C: d0040000                 ld      [%l0], %o0
F0084590: a004603c                 add     %l1, 0x3C, %l0 ! '<'
F0084594: d0268000                 st      %o0, [%i2]
F0084598: d0040000                 ld      [%l0], %o0
F008459C: 80a22000                 cmp     %o0, 0
F00845A0: 12bffffe                 bne     loc_F0084598
F00845A4: 01000000                 nop
F00845A8: 40004a40                 call    _simple_lock_try
F00845AC: 90100010                 mov     %l0, %o0
F00845B0: 80a22000                 cmp     %o0, 0
F00845B4: 02bffff9                 be      loc_F0084598
F00845B8: b0102000                 mov     0, %i0
F00845BC: d0068000                 ld      [%i2], %o0
F00845C0: d0246038                 st      %o0, [%l1+0x38]
F00845C4: c024603c                 clr     [%l1+0x3C]
F00845C8: 81c7e008                 ret
F00845CC: 81e80000                 restore
