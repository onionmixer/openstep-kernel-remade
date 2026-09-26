F003252C: 9de3bf98                 save    %sp, -0x68, %sp
F0032530: d40e0000                 ldub    [%i0], %o2
F0032534: a40e3f80                 and     %i0, -0x80, %l2
F0032538: d204a004                 ld      [%l2+4], %o1
F003253C: 80a66000                 cmp     %i1, 0
F0032540: d014a008                 lduh    [%l2+8], %o0
F0032544: 940aa00f                 and     %o2, 0xF, %o2
F0032548: 952aa002                 sll     %o2, 2, %o2
F003254C: 9202400a                 add     %o1, %o2, %o1
F0032550: d224a004                 st      %o1, [%l2+4]
F0032554: 9022000a                 sub     %o0, %o2, %o0
F0032558: 12800028                 bne     loc_F00325F8
F003255C: d034a008                 sth     %o0, [%l2+8]
F0032560: 90102000                 mov     0, %o0
F0032564: 7fffacfe                 call    _m_get
F0032568: 9210200b                 mov     0xB, %o1
F003256C: 96920000                 orcc    %o0, %g0, %o3
F0032570: 028000a1                 be      loc_F00327F4
F0032574: 133c04d9                 sethi   %hi(_ipq), %o1
F0032578: d402e004                 ld      [%o3+4], %o2
F003257C: d00260b0                 ld      [%o1+%lo(_ipq)], %o0
F0032580: b202c00a                 add     %o3, %o2, %i1
F0032584: d022c00a                 st      %o0, [%o3+%o2]
F0032588: 901260b0                 or      %o1, %lo(_ipq), %o0
F003258C: d0266004                 st      %o0, [%i1+4]
F0032590: d00260b0                 ld      [%o1+%lo(_ipq)], %o0
F0032594: f2222004                 st      %i1, [%o0+4]
F0032598: f22260b0                 st      %i1, [%o1+%lo(_ipq)]
F003259C: 9010203c                 mov     0x3C, %o0 ! '<'
F00325A0: d02e6008                 stb     %o0, [%i1+8]
F00325A4: d00e2009                 ldub    [%i0+9], %o0
F00325A8: d02e6009                 stb     %o0, [%i1+9]
F00325AC: d0162004                 lduh    [%i0+4], %o0
F00325B0: d036600a                 sth     %o0, [%i1+0xA]
F00325B4: f2266010                 st      %i1, [%i1+0x10]
F00325B8: f226600c                 st      %i1, [%i1+0xC]
F00325BC: d006200c                 ld      [%i0+0xC], %o0
F00325C0: d0266014                 st      %o0, [%i1+0x14]
F00325C4: d0062010                 ld      [%i0+0x10], %o0
F00325C8: a0100019                 mov     %i1, %l0
F00325CC: 10800046                 ba      loc_F00326E4
F00325D0: d0266018                 st      %o0, [%i1+0x18]
F00325D4: d0342002                 sth     %o0, [%l0+2]
F00325D8: 900c3f80                 and     %l0, -0x80, %o0
F00325DC: d4142006                 lduh    [%l0+6], %o2
F00325E0: 92100011                 mov     %l1, %o1
F00325E4: 94028009                 add     %o2, %o1, %o2
F00325E8: 7fffae7e                 call    _m_adj
F00325EC: d4342006                 sth     %o2, [%l0+6]
F00325F0: 1080003e                 ba      loc_F00326E8
F00325F4: d2042010                 ld      [%l0+0x10], %o1
F00325F8: e006600c                 ld      [%i1+0xC], %l0
F00325FC: 80a40019                 cmp     %l0, %i1
F0032600: 2280000c                 be,a    loc_F0032630
F0032604: d2042010                 ld      [%l0+0x10], %o1
F0032608: d2562006                 ldsh    [%i0+6], %o1
F003260C: d0542006                 ldsh    [%l0+6], %o0
F0032610: 80a20009                 cmp     %o0, %o1
F0032614: 34800007                 bg,a    loc_F0032630
F0032618: d2042010                 ld      [%l0+0x10], %o1
F003261C: e004200c                 ld      [%l0+0xC], %l0
F0032620: 80a40019                 cmp     %l0, %i1
F0032624: 32bffffb                 bne,a   loc_F0032610
F0032628: d0542006                 ldsh    [%l0+6], %o0
F003262C: d2042010                 ld      [%l0+0x10], %o1
F0032630: 80a24019                 cmp     %o1, %i1
F0032634: 0280002a                 be      loc_F00326DC
F0032638: 80a40019                 cmp     %l0, %i1
F003263C: d0526006                 ldsh    [%o1+6], %o0
F0032640: d2526002                 ldsh    [%o1+2], %o1
F0032644: d4562006                 ldsh    [%i0+6], %o2
F0032648: 90020009                 add     %o0, %o1, %o0
F003264C: a222000a                 sub     %o0, %o2, %l1
F0032650: 80a46000                 cmp     %l1, 0
F0032654: 04800022                 ble     loc_F00326DC
F0032658: 80a40019                 cmp     %l0, %i1
F003265C: d0562002                 ldsh    [%i0+2], %o0
F0032660: 80a44008                 cmp     %l1, %o0
F0032664: 16800065                 bge     loc_F00327F8
F0032668: 153c04d9                 sethi   -0xFEC9C00, %o2
F003266C: 900e3f80                 and     %i0, -0x80, %o0
F0032670: 7fffae5c                 call    _m_adj
F0032674: 92100011                 mov     %l1, %o1
F0032678: d0162006                 lduh    [%i0+6], %o0
F003267C: d2162002                 lduh    [%i0+2], %o1
F0032680: 90020011                 add     %o0, %l1, %o0
F0032684: d0362006                 sth     %o0, [%i0+6]
F0032688: 92224011                 sub     %o1, %l1, %o1
F003268C: 10800013                 ba      loc_F00326D8
F0032690: d2362002                 sth     %o1, [%i0+2]
F0032694: d0562002                 ldsh    [%i0+2], %o0
F0032698: d4542006                 ldsh    [%l0+6], %o2
F003269C: 92024008                 add     %o1, %o0, %o1
F00326A0: 80a2400a                 cmp     %o1, %o2
F00326A4: 24800011                 ble,a   loc_F00326E8
F00326A8: d2042010                 ld      [%l0+0x10], %o1
F00326AC: d0542002                 ldsh    [%l0+2], %o0
F00326B0: a222400a                 sub     %o1, %o2, %l1
F00326B4: 80a44008                 cmp     %l1, %o0
F00326B8: 26bfffc7                 bl,a    loc_F00325D4
F00326BC: 90220011                 sub     %o0, %l1, %o0
F00326C0: e004200c                 ld      [%l0+0xC], %l0
F00326C4: d0042010                 ld      [%l0+0x10], %o0
F00326C8: 7fffad67                 call    _m_freem
F00326CC: 900a3f80                 and     %o0, -0x80, %o0
F00326D0: 40000074                 call    _ip_deq
F00326D4: d0042010                 ld      [%l0+0x10], %o0
F00326D8: 80a40019                 cmp     %l0, %i1
F00326DC: 32bfffee                 bne,a   loc_F0032694
F00326E0: d2562006                 ldsh    [%i0+6], %o1
F00326E4: d2042010                 ld      [%l0+0x10], %o1
F00326E8: 40000065                 call    _ip_enq
F00326EC: 90100018                 mov     %i0, %o0
F00326F0: e006600c                 ld      [%i1+0xC], %l0
F00326F4: 80a40019                 cmp     %l0, %i1
F00326F8: 0280000b                 be      loc_F0032724
F00326FC: a2102000                 mov     0, %l1
F0032700: d0542006                 ldsh    [%l0+6], %o0
F0032704: 80a20011                 cmp     %o0, %l1
F0032708: 32800043                 bne,a   locret_F0032814
F003270C: b0102000                 mov     0, %i0
F0032710: d0542002                 ldsh    [%l0+2], %o0
F0032714: e004200c                 ld      [%l0+0xC], %l0
F0032718: 80a40019                 cmp     %l0, %i1
F003271C: 12bffff9                 bne     loc_F0032700
F0032720: a2044008                 add     %l1, %o0, %l1
F0032724: d0042010                 ld      [%l0+0x10], %o0
F0032728: d00a2001                 ldub    [%o0+1], %o0
F003272C: 80a22000                 cmp     %o0, 0
F0032730: 32800039                 bne,a   locret_F0032814
F0032734: b0102000                 mov     0, %i0
F0032738: e006600c                 ld      [%i1+0xC], %l0
F003273C: a40c3f80                 and     %l0, -0x80, %l2
F0032740: d6048000                 ld      [%l2], %o3
F0032744: 90100012                 mov     %l2, %o0
F0032748: c0248000                 clr     [%l2]
F003274C: 7fffadff                 call    _m_cat
F0032750: 9210000b                 mov     %o3, %o1
F0032754: e004200c                 ld      [%l0+0xC], %l0
F0032758: 80a40019                 cmp     %l0, %i1
F003275C: 2280000b                 be,a    loc_F0032788
F0032760: f006600c                 ld      [%i1+0xC], %i0
F0032764: 960c3f80                 and     %l0, -0x80, %o3
F0032768: e004200c                 ld      [%l0+0xC], %l0
F003276C: 90100012                 mov     %l2, %o0
F0032770: 7fffadf6                 call    _m_cat
F0032774: 9210000b                 mov     %o3, %o1
F0032778: 80a40019                 cmp     %l0, %i1
F003277C: 12bffffb                 bne     loc_F0032768
F0032780: 960c3f80                 and     %l0, -0x80, %o3
F0032784: f006600c                 ld      [%i1+0xC], %i0
F0032788: e2362002                 sth     %l1, [%i0+2]
F003278C: d0066014                 ld      [%i1+0x14], %o0
F0032790: d026200c                 st      %o0, [%i0+0xC]
F0032794: d0066018                 ld      [%i1+0x18], %o0
F0032798: d0262010                 st      %o0, [%i0+0x10]
F003279C: d2064000                 ld      [%i1], %o1
F00327A0: d0066004                 ld      [%i1+4], %o0
F00327A4: d0226004                 st      %o0, [%o1+4]
F00327A8: d4066004                 ld      [%i1+4], %o2
F00327AC: d2064000                 ld      [%i1], %o1
F00327B0: 900e7f80                 and     %i1, -0x80, %o0
F00327B4: 7fffacc0                 call    _m_free
F00327B8: d2228000                 st      %o1, [%o2]
F00327BC: d20e0000                 ldub    [%i0], %o1
F00327C0: a40e3f80                 and     %i0, -0x80, %l2
F00327C4: d014a008                 lduh    [%l2+8], %o0
F00327C8: 920a600f                 and     %o1, 0xF, %o1
F00327CC: 932a6002                 sll     %o1, 2, %o1
F00327D0: 90020009                 add     %o0, %o1, %o0
F00327D4: d034a008                 sth     %o0, [%l2+8]
F00327D8: d20e0000                 ldub    [%i0], %o1
F00327DC: d004a004                 ld      [%l2+4], %o0
F00327E0: 920a600f                 and     %o1, 0xF, %o1
F00327E4: 932a6002                 sll     %o1, 2, %o1
F00327E8: 90220009                 sub     %o0, %o1, %o0
F00327EC: 1080000a                 ba      locret_F0032814
F00327F0: d024a004                 st      %o0, [%l2+4]
F00327F4: 153c04d9                 sethi   -0xFEC9C00, %o2
F00327F8: 9412a0d0                 bset    0xD0, %o2
F00327FC: d202a01c                 ld      [%o2+0x1C], %o1
F0032800: 90100012                 mov     %l2, %o0
F0032804: 92026001                 inc     %o1
F0032808: 7fffad17                 call    _m_freem
F003280C: d222a01c                 st      %o1, [%o2+0x1C]
F0032810: b0102000                 mov     0, %i0
F0032814: 81c7e008                 ret
F0032818: 81e80000                 restore
