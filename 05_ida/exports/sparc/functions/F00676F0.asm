F00676F0: 9de3bf88                 save    %sp, -0x78, %sp
F00676F4: 80a62000                 cmp     %i0, 0
F00676F8: 0280002a                 be      loc_F00677A0
F00676FC: 80a6a004                 cmp     %i2, 4
F0067700: 18800028                 bgu     loc_F00677A0
F0067704: a0102000                 mov     0, %l0
F0067708: 80a4001a                 cmp     %l0, %i2
F006770C: 1a80000c                 bcc     loc_F006773C
F0067710: 80a42003                 cmp     %l0, 3
F0067714: 9407bff8                 add     %fp, var_8, %o2
F0067718: 92102000                 mov     0, %o1
F006771C: a0042001                 inc     %l0
F0067720: d0024019                 ld      [%o1+%i1], %o0
F0067724: 80a4001a                 cmp     %l0, %i2
F0067728: d022bff0                 st      %o0, [%o2-0x10]
F006772C: 9402a004                 inc     4, %o2
F0067730: 0abffffb                 bcs     loc_F006771C
F0067734: 92026004                 inc     4, %o1
F0067738: 80a42003                 cmp     %l0, 3
F006773C: 3480000b                 bg,a    loc_F0067768
F0067740: a0062064                 add     %i0, 0x64, %l0 ! 'd'
F0067744: 9207bff8                 add     %fp, var_8, %o1
F0067748: 912c2002                 sll     %l0, 2, %o0
F006774C: 90020009                 add     %o0, %o1, %o0
F0067750: c0223ff0                 clr     [%o0-0x10]
F0067754: a0042001                 inc     %l0
F0067758: 80a42003                 cmp     %l0, 3
F006775C: 04bffffd                 ble     loc_F0067750
F0067760: 90022004                 inc     4, %o0
F0067764: a0062064                 add     %i0, 0x64, %l0 ! 'd'
F0067768: d0040000                 ld      [%l0], %o0
F006776C: 80a22000                 cmp     %o0, 0
F0067770: 12bffffe                 bne     loc_F0067768
F0067774: 01000000                 nop
F0067778: 4000bdcc                 call    _simple_lock_try
F006777C: 90100010                 mov     %l0, %o0
F0067780: 80a22000                 cmp     %o0, 0
F0067784: 02bffff9                 be      loc_F0067768
F0067788: 01000000                 nop
F006778C: d0062068                 ld      [%i0+0x68], %o0
F0067790: 80a22000                 cmp     %o0, 0
F0067794: 12800005                 bne     loc_F00677A8
F0067798: a0102000                 mov     0, %l0
F006779C: c0262064                 clr     [%i0+0x64]
F00677A0: 10800022                 ba      locret_F0067828
F00677A4: b0102004                 mov     4, %i0
F00677A8: 9607bff8                 add     %fp, var_8, %o3
F00677AC: 94100018                 mov     %i0, %o2
F00677B0: d202a078                 ld      [%o2+0x78], %o1
F00677B4: a0042001                 inc     %l0
F00677B8: d002fff0                 ld      [%o3-0x10], %o0
F00677BC: 80a42003                 cmp     %l0, 3
F00677C0: d022a078                 st      %o0, [%o2+0x78]
F00677C4: d222fff0                 st      %o1, [%o3-0x10]
F00677C8: 9602e004                 inc     4, %o3
F00677CC: 04bffff9                 ble     loc_F00677B0
F00677D0: 9402a004                 inc     4, %o2
F00677D4: c0262064                 clr     [%i0+0x64]
F00677D8: a0102000                 mov     0, %l0
F00677DC: b007bff8                 add     %fp, var_8, %i0
F00677E0: d0063ff0                 ld      [%i0-0x10], %o0
F00677E4: 80a22000                 cmp     %o0, 0
F00677E8: 02800007                 be      loc_F0067804
F00677EC: a0042001                 inc     %l0
F00677F0: 80a23fff                 cmp     %o0, -1
F00677F4: 02800004                 be      loc_F0067804
F00677F8: 01000000                 nop
F00677FC: 7fffce48                 call    _ipc_port_release_send
F0067800: 01000000                 nop
F0067804: 80a42003                 cmp     %l0, 3
F0067808: 04bffff6                 ble     loc_F00677E0
F006780C: b0062004                 inc     4, %i0
F0067810: 80a6a000                 cmp     %i2, 0
F0067814: 02800004                 be      loc_F0067824
F0067818: 90100019                 mov     %i1, %o0
F006781C: 40000261                 call    _kfree
F0067820: 932ea002                 sll     %i2, 2, %o1
F0067824: b0102000                 mov     0, %i0
F0067828: 81c7e008                 ret
F006782C: 81e80000                 restore
