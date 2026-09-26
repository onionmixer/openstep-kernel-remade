F0048210: 9de3bf98                 save    %sp, -0x68, %sp
F0048214: 113c04cf                 sethi   %hi(_active_u), %o0
F0048218: d00221d8                 ld      [%o0+%lo(_active_u)], %o0
F004821C: d0020000                 ld      [%o0], %o0
F0048220: 7fff1a40                 call    _get_posix_proc
F0048224: d0522030                 ldsh    [%o0+0x30], %o0
F0048228: a2100008                 mov     %o0, %l1
F004822C: d0046018                 ld      [%l1+0x18], %o0
F0048230: 13200000                 sethi   0x80000000, %o1
F0048234: 90120009                 bset    %o1, %o0
F0048238: d0246018                 st      %o0, [%l1+0x18]
F004823C: e0062030                 ld      [%i0+0x30], %l0
F0048240: 7ffffcf5                 call    _sunsave
F0048244: 90100010                 mov     %l0, %o0
F0048248: d0042038                 ld      [%l0+0x38], %o0
F004824C: 80a22000                 cmp     %o0, 0
F0048250: 02800004                 be      loc_F0048260
F0048254: 90100018                 mov     %i0, %o0! vnop_fsync_args *
F0048258: 400000ab                 call    _spec_fsync
F004825C: 92100019                 mov     %i1, %o1
F0048260: d0042038                 ld      [%l0+0x38], %o0
F0048264: 80a22000                 cmp     %o0, 0
F0048268: 2280000b                 be,a    loc_F0048294
F004826C: 90100010                 mov     %l0, %o0
F0048270: 7fff823d                 call    _vn_rele
F0048274: 01000000                 nop
F0048278: d004203c                 ld      [%l0+0x3C], %o0
F004827C: 80a22000                 cmp     %o0, 0
F0048280: 02800004                 be      loc_F0048290
F0048284: c0242038                 clr     [%l0+0x38]
F0048288: 7fff8237                 call    _vn_rele
F004828C: 01000000                 nop
F0048290: 90100010                 mov     %l0, %o0
F0048294: 92102068                 mov     0x68, %o1 ! 'h'
F0048298: d6046018                 ld      [%l1+0x18], %o3
F004829C: 15200000                 sethi   0x80000000, %o2
F00482A0: 942ac00a                 andn    %o3, %o2, %o2
F00482A4: 40007fbf                 call    _kfree
F00482A8: d4246018                 st      %o2, [%l1+0x18]
F00482AC: 81c7e008                 ret
F00482B0: 91e82000                 restore %g0, 0, %o0
