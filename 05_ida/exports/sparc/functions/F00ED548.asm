F00ED548: 9de3bf88                 save    %sp, -0x78, %sp
F00ED54C: a2100018                 mov     %i0, %l1
F00ED550: 9007bff0                 add     %fp, var_10, %o0
F00ED554: d023a040                 st      %o0, [%sp+0x78+var_38]
F00ED558: 90100011                 mov     %l1, %o0! table
F00ED55C: 40000222                 call    _NXInitHashState
F00ED560: 01000000                 nop
F00ED564: 00000008                 illtrap
F00ED568: 40000d7c                 call    _NXZoneFromPtr
F00ED56C: 90100011                 mov     %l1, %o0
F00ED570: a0100008                 mov     %o0, %l0
F00ED574: d4042004                 ld      [%l0+4], %o2
F00ED578: 9fc28000                 call    %o2
F00ED57C: 92102014                 mov     0x14, %o1
F00ED580: b0100008                 mov     %o0, %i0
F00ED584: d0044000                 ld      [%l1], %o0
F00ED588: d0260000                 st      %o0, [%i0]
F00ED58C: c0262004                 clr     [%i0+4]
F00ED590: d0046010                 ld      [%l1+0x10], %o0
F00ED594: d0262010                 st      %o0, [%i0+0x10]
F00ED598: d2046008                 ld      [%l1+8], %o1
F00ED59C: d2262008                 st      %o1, [%i0+8]
F00ED5A0: 90100010                 mov     %l0, %o0
F00ED5A4: 40000d75                 call    _NXZoneCalloc
F00ED5A8: 94102008                 mov     8, %o2! data
F00ED5AC: d026200c                 st      %o0, [%i0+0xC]
F00ED5B0: 90100011                 mov     %l1, %o0! table
F00ED5B4: 9207bff0                 add     %fp, var_10, %o1! state
F00ED5B8: 40000216                 call    _NXNextHashState
F00ED5BC: 9407bfec                 add     %fp, var_14, %o2
F00ED5C0: 80a22000                 cmp     %o0, 0
F00ED5C4: 02800006                 be      locret_F00ED5DC
F00ED5C8: 90100018                 mov     %i0, %o0! table
F00ED5CC: 400000ab                 call    _NXHashInsert
F00ED5D0: d207bfec                 ld      [%fp+var_14], %o1
F00ED5D4: 10bffff8                 ba      loc_F00ED5B4
F00ED5D8: 90100011                 mov     %l1, %o0
F00ED5DC: 81c7e008                 ret
F00ED5E0: 81e80000                 restore
