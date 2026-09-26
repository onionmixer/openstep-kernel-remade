F005DBE4: 9de3bf98                 save    %sp, -0x68, %sp
F005DBE8: e0068000                 ld      [%i2], %l0
F005DBEC: 110007c0                 sethi   0x1F0000, %o0
F005DBF0: 920c0008                 and     %l0, %o0, %o1
F005DBF4: 110000c0                 sethi   0x30000, %o0
F005DBF8: 80a24008                 cmp     %o1, %o0
F005DBFC: 22800033                 be,a    loc_F005DCC8
F005DC00: 90100018                 mov     %i0, %o0
F005DC04: 1880000a                 bgu     loc_F005DC2C
F005DC08: 11000040                 sethi   0x10000, %o0
F005DC0C: 80a24008                 cmp     %o1, %o0
F005DC10: 0280002d                 be      loc_F005DCC4
F005DC14: 11000080                 sethi   0x20000, %o0
F005DC18: 80a24008                 cmp     %o1, %o0
F005DC1C: 22800014                 be,a    loc_F005DC6C
F005DC20: f406a004                 ld      [%i2+4], %i2
F005DC24: 1080006e                 ba      loc_F005DDDC
F005DC28: 113c043d                 sethi   -0xFEF0C00, %o0
F005DC2C: 11000200                 sethi   0x80000, %o0
F005DC30: 80a24008                 cmp     %o1, %o0
F005DC34: 0280006e                 be      loc_F005DDEC
F005DC38: 01000000                 nop
F005DC3C: 18800007                 bgu     loc_F005DC58
F005DC40: 11000100                 sethi   0x40000, %o0
F005DC44: 80a24008                 cmp     %o1, %o0
F005DC48: 02800034                 be      loc_F005DD18
F005DC4C: 90100018                 mov     %i0, %o0
F005DC50: 10800063                 ba      loc_F005DDDC
F005DC54: 113c043d                 sethi   -0xFEF0C00, %o0
F005DC58: 11000400                 sethi   0x100000, %o0
F005DC5C: 80a24008                 cmp     %o1, %o0
F005DC60: 1280005f                 bne     loc_F005DDDC
F005DC64: 113c043d                 sethi   -0xFEF0C00, %o0
F005DC68: 30800061                 ba,a    loc_F005DDEC
F005DC6C: d0068000                 ld      [%i2], %o0
F005DC70: 80a22000                 cmp     %o0, 0
F005DC74: 12bffffe                 bne     loc_F005DC6C
F005DC78: 01000000                 nop
F005DC7C: 4000e48b                 call    _simple_lock_try
F005DC80: 9010001a                 mov     %i2, %o0
F005DC84: 80a22000                 cmp     %o0, 0
F005DC88: 02bffff9                 be      loc_F005DC6C
F005DC8C: 01000000                 nop
F005DC90: c0262008                 clr     [%i0+8]
F005DC94: d006a018                 ld      [%i2+0x18], %o0
F005DC98: d206a01c                 ld      [%i2+0x1C], %o1
F005DC9C: 90022001                 inc     %o0
F005DCA0: d026a018                 st      %o0, [%i2+0x18]
F005DCA4: 92026001                 inc     %o1
F005DCA8: d226a01c                 st      %o1, [%i2+0x1C]
F005DCAC: d006a004                 ld      [%i2+4], %o0
F005DCB0: 90022001                 inc     %o0
F005DCB4: d026a004                 st      %o0, [%i2+4]
F005DCB8: c0268000                 clr     [%i2]
F005DCBC: 10800014                 ba      loc_F005DD0C
F005DCC0: f426c000                 st      %i2, [%i3]
F005DCC4: 90100018                 mov     %i0, %o0
F005DCC8: 94100019                 mov     %i1, %o2
F005DCCC: f206a004                 ld      [%i2+4], %i1
F005DCD0: 9610001a                 mov     %i2, %o3
F005DCD4: 7ffff874                 call    _ipc_right_check
F005DCD8: 92100019                 mov     %i1, %o1
F005DCDC: 80a22000                 cmp     %o0, 0
F005DCE0: 12800016                 bne     loc_F005DD38
F005DCE4: 11001000                 sethi   0x400000, %o0
F005DCE8: c0262008                 clr     [%i0+8]
F005DCEC: d006601c                 ld      [%i1+0x1C], %o0
F005DCF0: 90022001                 inc     %o0
F005DCF4: d026601c                 st      %o0, [%i1+0x1C]
F005DCF8: d0066004                 ld      [%i1+4], %o0
F005DCFC: 90022001                 inc     %o0
F005DD00: d0266004                 st      %o0, [%i1+4]
F005DD04: c0264000                 clr     [%i1]
F005DD08: f226c000                 st      %i1, [%i3]
F005DD0C: 90102011                 mov     0x11, %o0
F005DD10: 10800035                 ba      loc_F005DDE4
F005DD14: d0270000                 st      %o0, [%i4]
F005DD18: 94100019                 mov     %i1, %o2
F005DD1C: e206a004                 ld      [%i2+4], %l1
F005DD20: 9610001a                 mov     %i2, %o3
F005DD24: 7ffff860                 call    _ipc_right_check
F005DD28: 92100011                 mov     %l1, %o1
F005DD2C: 80a22000                 cmp     %o0, 0
F005DD30: 02800006                 be      loc_F005DD48
F005DD34: 11001000                 sethi   0x400000, %o0
F005DD38: 808c0008                 btst    %o0, %l0
F005DD3C: 0280002c                 be      loc_F005DDEC
F005DD40: 01000000                 nop
F005DD44: 3080002d                 ba,a    loc_F005DDF8
F005DD48: d006a008                 ld      [%i2+8], %o0
F005DD4C: 80a22000                 cmp     %o0, 0
F005DD50: 02800008                 be      loc_F005DD70
F005DD54: 92100011                 mov     %l1, %o1
F005DD58: 90100018                 mov     %i0, %o0
F005DD5C: 94100019                 mov     %i1, %o2
F005DD60: 7ffff803                 call    _ipc_right_dncancel
F005DD64: 9610001a                 mov     %i2, %o3
F005DD68: 10800003                 ba      loc_F005DD74
F005DD6C: a0100008                 mov     %o0, %l0
F005DD70: a0102000                 mov     0, %l0
F005DD74: c0244000                 clr     [%l1]
F005DD78: c026a004                 clr     [%i2+4]
F005DD7C: 90100018                 mov     %i0, %o0
F005DD80: 92100019                 mov     %i1, %o1
F005DD84: 7fffd83d                 call    _ipc_entry_dealloc
F005DD88: 9410001a                 mov     %i2, %o2
F005DD8C: 7ffff4ac                 call    _ipc_port_copy_send
F005DD90: d0062044                 ld      [%i0+0x44], %o0
F005DD94: c0262008                 clr     [%i0+8]
F005DD98: 80a42000                 cmp     %l0, 0
F005DD9C: 02800005                 be      loc_F005DDB0
F005DDA0: b0100008                 mov     %o0, %i0
F005DDA4: 90100010                 mov     %l0, %o0
F005DDA8: 7fffec91                 call    _ipc_notify_port_deleted
F005DDAC: 92100019                 mov     %i1, %o1
F005DDB0: 80a62000                 cmp     %i0, 0
F005DDB4: 02800006                 be      loc_F005DDCC
F005DDB8: 80a63fff                 cmp     %i0, -1
F005DDBC: 02800004                 be      loc_F005DDCC
F005DDC0: 90100018                 mov     %i0, %o0
F005DDC4: 7fffed8e                 call    _ipc_notify_port_deleted_compat
F005DDC8: 92100019                 mov     %i1, %o1
F005DDCC: e226c000                 st      %l1, [%i3]
F005DDD0: 90102012                 mov     0x12, %o0! char *
F005DDD4: 10800004                 ba      loc_F005DDE4
F005DDD8: d0270000                 st      %o0, [%i4]
F005DDDC: 7ffedce5                 call    _panic
F005DDE0: 901223c0                 bset    0x3C0, %o0
F005DDE4: 10800007                 ba      locret_F005DE00
F005DDE8: b0102000                 mov     0, %i0
F005DDEC: c0262008                 clr     [%i0+8]
F005DDF0: 10800004                 ba      locret_F005DE00
F005DDF4: b0102011                 mov     0x11, %i0
F005DDF8: c0262008                 clr     [%i0+8]
F005DDFC: b010200f                 mov     0xF, %i0
F005DE00: 81c7e008                 ret
F005DE04: 81e80000                 restore
