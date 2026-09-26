F0057124: 9de3bf90                 save    %sp, -0x70, %sp
F0057128: e006201c                 ld      [%i0+0x1C], %l0
F005712C: 1100003f                 sethi   0xFC00, %o0
F0057130: e4062014                 ld      [%i0+0x14], %l2
F0057134: 90122300                 bset    0x300, %o0
F0057138: e2062020                 ld      [%i0+0x20], %l1
F005713C: a80ca0ff                 and     %l2, 0xFF, %l4
F0057140: 900c8008                 and     %l2, %o0, %o0
F0057144: a7322008                 srl     %o0, 8, %l3
F0057148: d0040000                 ld      [%l0], %o0
F005714C: 80a22000                 cmp     %o0, 0
F0057150: 12bffffe                 bne     loc_F0057148
F0057154: 01000000                 nop
F0057158: 4000ff54                 call    _simple_lock_try
F005715C: 90100010                 mov     %l0, %o0
F0057160: 80a22000                 cmp     %o0, 0
F0057164: 02bffff9                 be      loc_F0057148
F0057168: 01000000                 nop
F005716C: d0042008                 ld      [%l0+8], %o0
F0057170: 80a22000                 cmp     %o0, 0
F0057174: 36800009                 bge,a   loc_F0057198
F0057178: d0042004                 ld      [%l0+4], %o0
F005717C: 90100019                 mov     %i1, %o0
F0057180: 92100010                 mov     %l0, %o1
F0057184: 94100014                 mov     %l4, %o2
F0057188: 40000b73                 call    _ipc_object_copyout_dest
F005718C: 9607bff4                 add     %fp, var_C, %o3
F0057190: 10800014                 ba      loc_F00571E0
F0057194: 80a46000                 cmp     %l1, 0
F0057198: 90023fff                 inc     -1, %o0
F005719C: d0242004                 st      %o0, [%l0+4]
F00571A0: c0240000                 clr     [%l0]
F00571A4: 80a22000                 cmp     %o0, 0
F00571A8: 1280000c                 bne     loc_F00571D8
F00571AC: 90103fff                 mov     -1, %o0
F00571B0: 133c04ef                 sethi   %hi(_ipc_object_zones), %o1
F00571B4: d0042008                 ld      [%l0+8], %o0
F00571B8: 92126300                 bset    %lo(_ipc_object_zones), %o1
F00571BC: 912a2001                 sll     %o0, 1, %o0
F00571C0: 91322011                 srl     %o0, 17, %o0
F00571C4: 912a2002                 sll     %o0, 2, %o0
F00571C8: d0020009                 ld      [%o0+%o1], %o0
F00571CC: 40008801                 call    _zfree
F00571D0: 92100010                 mov     %l0, %o1
F00571D4: 90103fff                 mov     -1, %o0
F00571D8: d027bff4                 st      %o0, [%fp+var_C]
F00571DC: 80a46000                 cmp     %l1, 0
F00571E0: 02800008                 be      loc_F0057200
F00571E4: 80a47fff                 cmp     %l1, -1
F00571E8: 02800006                 be      loc_F0057200
F00571EC: 90100011                 mov     %l1, %o0
F00571F0: 40000aab                 call    _ipc_object_destroy
F00571F4: 92100013                 mov     %l3, %o1
F00571F8: 10800003                 ba      loc_F0057204
F00571FC: 94102000                 mov     0, %o2
F0057200: 94100011                 mov     %l1, %o2
F0057204: 113fffc0                 sethi   -0x10000, %o0
F0057208: 900c8008                 and     %l2, %o0, %o0
F005720C: 932d2008                 sll     %l4, 8, %o1
F0057210: 9214c009                 bset    %l3, %o1
F0057214: 90120009                 bset    %o1, %o0
F0057218: d0262014                 st      %o0, [%i0+0x14]
F005721C: d426201c                 st      %o2, [%i0+0x1C]
F0057220: d007bff4                 ld      [%fp+var_C], %o0
F0057224: 80a4a000                 cmp     %l2, 0
F0057228: 16800007                 bge     locret_F0057244
F005722C: d0262020                 st      %o0, [%i0+0x20]
F0057230: d2062018                 ld      [%i0+0x18], %o1
F0057234: 9006202c                 add     %i0, 0x2C, %o0 ! ','
F0057238: 92026014                 inc     0x14, %o1
F005723C: 7ffff721                 call    _ipc_kmsg_clean_body
F0057240: 92060009                 add     %i0, %o1, %o1
F0057244: 81c7e008                 ret
F0057248: 81e80000                 restore
