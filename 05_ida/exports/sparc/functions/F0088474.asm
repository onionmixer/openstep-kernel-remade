F0088474: 9de3bf98                 save    %sp, -0x68, %sp
F0088478: d0562018                 ldsh    [%i0+0x18], %o0
F008847C: 80a22002                 cmp     %o0, 2
F0088480: 0480000d                 ble     loc_F00884B4
F0088484: 92102000                 mov     0, %o1
F0088488: f0062028                 ld      [%i0+0x28], %i0
F008848C: 80a62000                 cmp     %i0, 0
F0088490: 0280000a                 be      loc_F00884B8
F0088494: 808ea002                 btst    2, %i2
F0088498: d0060000                 ld      [%i0], %o0
F008849C: 80a22000                 cmp     %o0, 0
F00884A0: 12800006                 bne     loc_F00884B8
F00884A4: 808ea002                 btst    2, %i2
F00884A8: d006200c                 ld      [%i0+0xC], %o0
F00884AC: 9332201f                 srl     %o0, 31, %o1
F00884B0: 921a6001                 btog    1, %o1
F00884B4: 808ea002                 btst    2, %i2
F00884B8: 12800005                 bne     loc_F00884CC
F00884BC: 113c04f0                 sethi   -0xFEC4000, %o0
F00884C0: 80a26000                 cmp     %o1, 0
F00884C4: 12800030                 bne     locret_F0088584
F00884C8: 01000000                 nop
F00884CC: b0122230                 or      %o0, 0x230, %i0
F00884D0: d0060000                 ld      [%i0], %o0
F00884D4: 80a22000                 cmp     %o0, 0
F00884D8: 12bffffe                 bne     loc_F00884D0
F00884DC: 01000000                 nop
F00884E0: 40003a72                 call    _simple_lock_try
F00884E4: 90100018                 mov     %i0, %o0
F00884E8: 80a22000                 cmp     %o0, 0
F00884EC: 02bffff9                 be      loc_F00884D0
F00884F0: 80a6a000                 cmp     %i2, 0
F00884F4: 02800006                 be      loc_F008850C
F00884F8: 80a6a001                 cmp     %i2, 1
F00884FC: 2280001a                 be,a    loc_F0088564
F0088500: d206601c                 ld      [%i1+0x1C], %o1
F0088504: 1080001f                 ba      loc_F0088580
F0088508: 113c04f0                 sethi   -0xFEC4000, %o0
F008850C: d006601c                 ld      [%i1+0x1C], %o0
F0088510: 808a2400                 btst    0x400, %o0
F0088514: 2280000a                 be,a    loc_F008853C
F0088518: d206601c                 ld      [%i1+0x1C], %o1
F008851C: 40005bf4                 call    _pmap_is_modified
F0088520: d0066024                 ld      [%i1+0x24], %o0
F0088524: 80a22000                 cmp     %o0, 0
F0088528: 32800005                 bne,a   loc_F008853C
F008852C: d206601c                 ld      [%i1+0x1C], %o1
F0088530: 7fffff77                 call    sub_F008830C
F0088534: 90100019                 mov     %i1, %o0
F0088538: 30800007                 ba,a    loc_F0088554
F008853C: 11000010                 sethi   0x4000, %o0
F0088540: 808a4008                 btst    %o0, %o1
F0088544: 02800004                 be      loc_F0088554
F0088548: 01000000                 nop
F008854C: 40000464                 call    _vm_page_deactivate
F0088550: 90100019                 mov     %i1, %o0
F0088554: 400054a9                 call    _pmap_remove_all
F0088558: d0066024                 ld      [%i1+0x24], %o0
F008855C: 10800009                 ba      loc_F0088580
F0088560: 113c04f0                 sethi   -0xFEC4000, %o0
F0088564: 11000010                 sethi   0x4000, %o0
F0088568: 808a4008                 btst    %o0, %o1
F008856C: 02800005                 be      loc_F0088580
F0088570: 113c04f0                 sethi   -0xFEC4000, %o0
F0088574: 4000045a                 call    _vm_page_deactivate
F0088578: 90100019                 mov     %i1, %o0
F008857C: 113c04f0                 sethi   -0xFEC4000, %o0
F0088580: c0222230                 clr     [%o0+0x230]
F0088584: 81c7e008                 ret
F0088588: 81e80000                 restore
