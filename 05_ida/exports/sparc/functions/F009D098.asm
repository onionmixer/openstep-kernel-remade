F009D098: 9de3bf98                 save    %sp, -0x68, %sp
F009D09C: f227a048                 st      %i1, [%fp+arg_48]
F009D0A0: 153c04f79412a270         set     _pmap_info, %o2
F009D0A8: d202a050                 ld      [%o2+0x50], %o1
F009D0AC: 90100018                 mov     %i0, %o0
F009D0B0: 92026001                 inc     %o1
F009D0B4: d222a050                 st      %o1, [%o2+0x50]
F009D0B8: c0268000                 clr     [%i2]
F009D0BC: d207a048                 ld      [%fp+arg_48], %o1
F009D0C0: 7ffffe3e                 call    _pmap_page_table_entry
F009D0C4: 94102000                 mov     0, %o2
F009D0C8: 94920000                 orcc    %o0, %g0, %o2
F009D0CC: 0280002a                 be      locret_F009D174
F009D0D0: 01000000                 nop
F009D0D4: d00aa00d                 ldub    [%o2+0xD], %o0
F009D0D8: 80a22003                 cmp     %o0, 3
F009D0DC: 12800007                 bne     loc_F009D0F8
F009D0E0: 80a22002                 cmp     %o0, 2
F009D0E4: d007a048                 ld      [%fp+arg_48], %o0
F009D0E8: d2028000                 ld      [%o2], %o1
F009D0EC: 9132200a                 srl     %o0, 10, %o0
F009D0F0: 1080000a                 ba      loc_F009D118
F009D0F4: 900a20fc                 and     %o0, 0xFC, %o0
F009D0F8: 32800006                 bne,a   loc_F009D110
F009D0FC: d00fa048                 ldub    [%fp+arg_48], %o0
F009D100: d017a048                 lduh    [%fp+arg_48], %o0
F009D104: d2028000                 ld      [%o2], %o1
F009D108: 10800004                 ba      loc_F009D118
F009D10C: 900a20fc                 and     %o0, 0xFC, %o0
F009D110: d2028000                 ld      [%o2], %o1
F009D114: 912a2002                 sll     %o0, 2, %o0
F009D118: 92024008                 add     %o1, %o0, %o1
F009D11C: d2024000                 ld      [%o1], %o1
F009D120: d2268000                 st      %o1, [%i2]
F009D124: d00aa00d                 ldub    [%o2+0xD], %o0
F009D128: 80a22003                 cmp     %o0, 3
F009D12C: 12800007                 bne     loc_F009D148
F009D130: 97326008                 srl     %o1, 8, %o3
F009D134: 133ffc00                 sethi   -0x100000, %o1
F009D138: 922ac009                 andn    %o3, %o1, %o1
F009D13C: 113ffc00                 sethi   -0x100000, %o0
F009D140: 10800008                 ba      loc_F009D160
F009D144: 902a4008                 andn    %o1, %o0, %o0
F009D148: 912ae00c                 sll     %o3, 12, %o0
F009D14C: d407a048                 ld      [%fp+arg_48], %o2
F009D150: 133fff00                 sethi   -0x40000, %o1
F009D154: 922a8009                 andn    %o2, %o1, %o1
F009D158: 90020009                 add     %o0, %o1, %o0
F009D15C: 9132200c                 srl     %o0, 12, %o0
F009D160: 9212c008                 or      %o3, %o0, %o1
F009D164: d00ea003                 ldub    [%i2+3], %o0
F009D168: 932a6008                 sll     %o1, 8, %o1
F009D16C: 90120009                 bset    %o1, %o0
F009D170: d0268000                 st      %o0, [%i2]
F009D174: 81c7e008                 ret
F009D178: 81e80000                 restore
