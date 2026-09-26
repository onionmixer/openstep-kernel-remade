F00582C0: 9de3bf98                 save    %sp, -0x68, %sp
F00582C4: 113c04ef                 sethi   %hi(_ipc_marequest_size), %o0
F00582C8: d0022358                 ld      [%o0+%lo(_ipc_marequest_size)], %o0
F00582CC: 80a2001a                 cmp     %o0, %i2
F00582D0: 2a800002                 bcs,a   loc_F00582D8
F00582D4: b4100008                 mov     %o0, %i2
F00582D8: a4102000                 mov     0, %l2
F00582DC: 80a4801a                 cmp     %l2, %i2
F00582E0: 1a800020                 bcc     loc_F0058360
F00582E4: 113c043d                 sethi   -0xFEF0C00, %o0
F00582E8: 293c04ef                 sethi   -0xFEC4400, %l4
F00582EC: a6102000                 mov     0, %l3
F00582F0: a2102000                 mov     0, %l1
F00582F4: d2052360                 ld      [%l4+0x360], %o1
F00582F8: 912ca003                 sll     %l2, 3, %o0
F00582FC: a0024008                 add     %o1, %o0, %l0
F0058300: d0040000                 ld      [%l0], %o0
F0058304: 80a22000                 cmp     %o0, 0
F0058308: 12bffffe                 bne     loc_F0058300
F005830C: 01000000                 nop
F0058310: 4000fae6                 call    _simple_lock_try
F0058314: 90100010                 mov     %l0, %o0
F0058318: 80a22000                 cmp     %o0, 0
F005831C: 02bffff9                 be      loc_F0058300
F0058320: 01000000                 nop
F0058324: d0042004                 ld      [%l0+4], %o0
F0058328: 80a22000                 cmp     %o0, 0
F005832C: 02800006                 be      loc_F0058344
F0058330: 01000000                 nop
F0058334: d002200c                 ld      [%o0+0xC], %o0
F0058338: 80a22000                 cmp     %o0, 0
F005833C: 12bffffe                 bne     loc_F0058334
F0058340: a2046001                 inc     %l1
F0058344: c0240000                 clr     [%l0]
F0058348: e224c019                 st      %l1, [%l3+%i1]
F005834C: a404a001                 inc     %l2
F0058350: 80a4801a                 cmp     %l2, %i2
F0058354: 0abfffe7                 bcs     loc_F00582F0
F0058358: a604e004                 inc     4, %l3
F005835C: 113c043d                 sethi   -0xFEF0C00, %o0
F0058360: d0022018                 ld      [%o0+0x18], %o0
F0058364: d0260000                 st      %o0, [%i0]
F0058368: 113c04ef                 sethi   %hi(_ipc_marequest_size), %o0
F005836C: f0022358                 ld      [%o0+%lo(_ipc_marequest_size)], %i0
F0058370: 81c7e008                 ret
F0058374: 81e80000                 restore
