F00851C4: 9de3bf90                 save    %sp, -0x70, %sp
F00851C8: 90100018                 mov     %i0, %o0
F00851CC: 92100019                 mov     %i1, %o1
F00851D0: 7ffffcb6                 call    _vm_map_lookup_entry
F00851D4: 9407bff4                 add     %fp, var_C, %o2
F00851D8: 80a22000                 cmp     %o0, 0
F00851DC: 12800005                 bne     loc_F00851F0
F00851E0: e007bff4                 ld      [%fp+var_C], %l0
F00851E4: d007bff4                 ld      [%fp+var_C], %o0
F00851E8: 10800016                 ba      loc_F0085240
F00851EC: e0022004                 ld      [%o0+4], %l0
F00851F0: d0042008                 ld      [%l0+8], %o0
F00851F4: 80a64008                 cmp     %i1, %o0
F00851F8: 08800005                 bleu    loc_F008520C
F00851FC: 9006200c                 add     %i0, 0xC, %o0
F0085200: 92100010                 mov     %l0, %o1
F0085204: 7ffffd43                 call    __vm_map_clip_start
F0085208: 94100019                 mov     %i1, %o2
F008520C: a206203c                 add     %i0, 0x3C, %l1 ! '<'
F0085210: d0044000                 ld      [%l1], %o0
F0085214: 80a22000                 cmp     %o0, 0
F0085218: 12bffffe                 bne     loc_F0085210
F008521C: 01000000                 nop
F0085220: 40004722                 call    _simple_lock_try
F0085224: 90100011                 mov     %l1, %o0
F0085228: 80a22000                 cmp     %o0, 0
F008522C: 02bffff9                 be      loc_F0085210
F0085230: 01000000                 nop
F0085234: d0040000                 ld      [%l0], %o0
F0085238: d0262038                 st      %o0, [%i0+0x38]
F008523C: c026203c                 clr     [%i0+0x3C]
F0085240: d0062040                 ld      [%i0+0x40], %o0
F0085244: d0022008                 ld      [%o0+8], %o0
F0085248: 80a20019                 cmp     %o0, %i1
F008524C: 0a800005                 bcs     loc_F0085260
F0085250: 9006200c                 add     %i0, 0xC, %o0
F0085254: d0040000                 ld      [%l0], %o0
F0085258: d0262040                 st      %o0, [%i0+0x40]
F008525C: 9006200c                 add     %i0, 0xC, %o0
F0085260: 80a40008                 cmp     %l0, %o0
F0085264: 02800035                 be      locret_F0085338
F0085268: 2b3c04f4                 sethi   -0xFEC3000, %l5
F008526C: a8100008                 mov     %o0, %l4
F0085270: d0042008                 ld      [%l0+8], %o0
F0085274: 80a2001a                 cmp     %o0, %i2
F0085278: 1a800030                 bcc     locret_F0085338
F008527C: 01000000                 nop
F0085280: d004200c                 ld      [%l0+0xC], %o0
F0085284: 80a68008                 cmp     %i2, %o0
F0085288: 1a800005                 bcc     loc_F008529C
F008528C: 9006200c                 add     %i0, 0xC, %o0
F0085290: 92100010                 mov     %l0, %o1
F0085294: 7ffffd57                 call    __vm_map_clip_end
F0085298: 9410001a                 mov     %i2, %o2
F008529C: e6042004                 ld      [%l0+4], %l3
F00852A0: f2042008                 ld      [%l0+8], %i1
F00852A4: e404200c                 ld      [%l0+0xC], %l2
F00852A8: d0142028                 lduh    [%l0+0x28], %o0
F00852AC: 80a22000                 cmp     %o0, 0
F00852B0: 02800005                 be      loc_F00852C4
F00852B4: e2042010                 ld      [%l0+0x10], %l1
F00852B8: 90100018                 mov     %i0, %o0
F00852BC: 7fffff95                 call    _vm_map_entry_unwire
F00852C0: 92100010                 mov     %l0, %o1
F00852C4: d0056340                 ld      [%l5+0x340], %o0
F00852C8: 80a44008                 cmp     %l1, %o0
F00852CC: 32800008                 bne,a   loc_F00852EC
F00852D0: d006202c                 ld      [%i0+0x2C], %o0
F00852D4: d2042014                 ld      [%l0+0x14], %o1
F00852D8: 90100011                 mov     %l1, %o0
F00852DC: 94248019                 sub     %l2, %i1, %o2
F00852E0: 400009b1                 call    _vm_object_page_remove
F00852E4: 9402400a                 add     %o1, %o2, %o2
F00852E8: d006202c                 ld      [%i0+0x2C], %o0
F00852EC: 80a22000                 cmp     %o0, 0
F00852F0: 32800008                 bne,a   loc_F0085310
F00852F4: d0062024                 ld      [%i0+0x24], %o0
F00852F8: d2042014                 ld      [%l0+0x14], %o1
F00852FC: 90100011                 mov     %l1, %o0
F0085300: 94248019                 sub     %l2, %i1, %o2
F0085304: 4000072d                 call    _vm_object_pmap_remove
F0085308: 9402400a                 add     %o1, %o2, %o2
F008530C: d0062024                 ld      [%i0+0x24], %o0
F0085310: 92100019                 mov     %i1, %o1
F0085314: 40005f9a                 call    _pmap_remove
F0085318: 94100012                 mov     %l2, %o2
F008531C: 90100018                 mov     %i0, %o0
F0085320: 7fffff83                 call    _vm_map_entry_delete
F0085324: 92100010                 mov     %l0, %o1
F0085328: a0100013                 mov     %l3, %l0
F008532C: 80a40014                 cmp     %l0, %l4
F0085330: 32bfffd1                 bne,a   loc_F0085274
F0085334: d0042008                 ld      [%l0+8], %o0
F0085338: 81c7e008                 ret
F008533C: 91e82000                 restore %g0, 0, %o0
