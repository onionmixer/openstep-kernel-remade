F0063330: 9de3bf88                 save    %sp, -0x78, %sp
F0063334: 80a62000                 cmp     %i0, 0
F0063338: 02800018                 be      loc_F0063398
F006333C: e007a05c                 ld      [%fp+arg_5C], %l0
F0063340: 90100018                 mov     %i0, %o0
F0063344: 92100019                 mov     %i1, %o1
F0063348: 7fffe1cd                 call    _ipc_right_lookup_write
F006334C: 9407bff4                 add     %fp, var_C, %o2
F0063350: 80a22000                 cmp     %o0, 0
F0063354: 3280005a                 bne,a   locret_F00634BC
F0063358: b0102004                 mov     4, %i0
F006335C: 90100018                 mov     %i0, %o0
F0063360: 92100019                 mov     %i1, %o1
F0063364: d407bff4                 ld      [%fp+var_C], %o2
F0063368: 9607bff0                 add     %fp, var_10, %o3
F006336C: 7fffe655                 call    _ipc_right_info
F0063370: 9807bfec                 add     %fp, var_14, %o4
F0063374: 80a22000                 cmp     %o0, 0
F0063378: 32800051                 bne,a   locret_F00634BC
F006337C: b0102004                 mov     4, %i0
F0063380: d207bff0                 ld      [%fp+var_10], %o1
F0063384: 110005c0                 sethi   0x170000, %o0
F0063388: 808a4008                 btst    %o0, %o1
F006338C: 12800005                 bne     loc_F00633A0
F0063390: 11000080                 sethi   0x20000, %o0
F0063394: c0262008                 clr     [%i0+8]
F0063398: 10800049                 ba      locret_F00634BC
F006339C: b0102004                 mov     4, %i0
F00633A0: 808a4008                 btst    %o0, %o1
F00633A4: 0280003e                 be      loc_F006349C
F00633A8: d007bff4                 ld      [%fp+var_C], %o0
F00633AC: f2022004                 ld      [%o0+4], %i1
F00633B0: d0064000                 ld      [%i1], %o0
F00633B4: 80a22000                 cmp     %o0, 0
F00633B8: 12bffffe                 bne     loc_F00633B0
F00633BC: 01000000                 nop
F00633C0: 4000ceba                 call    _simple_lock_try
F00633C4: 90100019                 mov     %i1, %o0
F00633C8: 80a22000                 cmp     %o0, 0
F00633CC: 02bffff9                 be      loc_F00633B0
F00633D0: 01000000                 nop
F00633D4: c0262008                 clr     [%i0+8]
F00633D8: d0066030                 ld      [%i1+0x30], %o0
F00633DC: 80a22000                 cmp     %o0, 0
F00633E0: 02800024                 be      loc_F0063470
F00633E4: b0100008                 mov     %o0, %i0
F00633E8: d0060000                 ld      [%i0], %o0
F00633EC: 80a22000                 cmp     %o0, 0
F00633F0: 12bffffe                 bne     loc_F00633E8
F00633F4: 01000000                 nop
F00633F8: 4000ceac                 call    _simple_lock_try
F00633FC: 90100018                 mov     %i0, %o0
F0063400: 80a22000                 cmp     %o0, 0
F0063404: 02bffff9                 be      loc_F00633E8
F0063408: 01000000                 nop
F006340C: d0062008                 ld      [%i0+8], %o0
F0063410: 80a22000                 cmp     %o0, 0
F0063414: 06800013                 bl      loc_F0063460
F0063418: 90100018                 mov     %i0, %o0
F006341C: 7fffe0ca                 call    _ipc_pset_remove
F0063420: 92100019                 mov     %i1, %o1
F0063424: d0062004                 ld      [%i0+4], %o0
F0063428: c0260000                 clr     [%i0]
F006342C: 80a22000                 cmp     %o0, 0
F0063430: 12800010                 bne     loc_F0063470
F0063434: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F0063438: d0062008                 ld      [%i0+8], %o0
F006343C: 92126300                 bset    %lo(_ipc_object_zones), %o1
F0063440: 912a2001                 sll     %o0, 1, %o0
F0063444: 91322011                 srl     %o0, 17, %o0
F0063448: 912a2002                 sll     %o0, 2, %o0
F006344C: d0020009                 ld      [%o0+%o1], %o0
F0063450: 40005760                 call    _zfree
F0063454: 92100018                 mov     %i0, %o1
F0063458: 10800007                 ba      loc_F0063474
F006345C: 96102000                 mov     0, %o3
F0063460: d606200c                 ld      [%i0+0xC], %o3
F0063464: c0260000                 clr     [%i0]
F0063468: 10800004                 ba      loc_F0063478
F006346C: d406603c                 ld      [%i1+0x3C], %o2
F0063470: 96102000                 mov     0, %o3
F0063474: d406603c                 ld      [%i1+0x3C], %o2
F0063478: c0264000                 clr     [%i1]
F006347C: d2066038                 ld      [%i1+0x38], %o1
F0063480: 90102001                 mov     1, %o0
F0063484: d0274000                 st      %o0, [%i5]
F0063488: d0240000                 st      %o0, [%l0]
F006348C: d6268000                 st      %o3, [%i2]
F0063490: d226c000                 st      %o1, [%i3]
F0063494: 10800009                 ba      loc_F00634B8
F0063498: d4270000                 st      %o2, [%i4]
F006349C: c0262008                 clr     [%i0+8]
F00634A0: c0274000                 clr     [%i5]
F00634A4: c0240000                 clr     [%l0]
F00634A8: c0268000                 clr     [%i2]
F00634AC: 90103fff                 mov     -1, %o0
F00634B0: d026c000                 st      %o0, [%i3]
F00634B4: c0270000                 clr     [%i4]
F00634B8: b0102000                 mov     0, %i0
F00634BC: 81c7e008                 ret
F00634C0: 81e80000                 restore
