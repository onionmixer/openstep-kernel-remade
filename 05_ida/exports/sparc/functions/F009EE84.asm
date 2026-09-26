F009EE84: 9de3bf98                 save    %sp, -0x68, %sp
F009EE88: 92100019                 mov     %i1, %o1
F009EE8C: d227a048                 st      %o1, [%fp+arg_48]
F009EE90: 173c04f79612e270         set     _pmap_info, %o3
F009EE98: d402e080                 ld      [%o3+0x80], %o2
F009EE9C: 90100018                 mov     %i0, %o0
F009EEA0: 9402a001                 inc     %o2
F009EEA4: d422e080                 st      %o2, [%o3+0x80]
F009EEA8: 7ffff6c4                 call    _pmap_page_table_entry
F009EEAC: 94102000                 mov     0, %o2
F009EEB0: 94920000                 orcc    %o0, %g0, %o2
F009EEB4: 22800027                 be,a    locret_F009EF50
F009EEB8: b0102000                 mov     0, %i0
F009EEBC: d00aa00d                 ldub    [%o2+0xD], %o0
F009EEC0: 80a22003                 cmp     %o0, 3
F009EEC4: 12800007                 bne     loc_F009EEE0
F009EEC8: 80a22002                 cmp     %o0, 2
F009EECC: d007a048                 ld      [%fp+arg_48], %o0
F009EED0: d2028000                 ld      [%o2], %o1
F009EED4: 9132200a                 srl     %o0, 10, %o0
F009EED8: 1080000a                 ba      loc_F009EF00
F009EEDC: 900a20fc                 and     %o0, 0xFC, %o0
F009EEE0: 32800006                 bne,a   loc_F009EEF8
F009EEE4: d00fa048                 ldub    [%fp+arg_48], %o0
F009EEE8: d017a048                 lduh    [%fp+arg_48], %o0
F009EEEC: d2028000                 ld      [%o2], %o1
F009EEF0: 10800004                 ba      loc_F009EF00
F009EEF4: 900a20fc                 and     %o0, 0xFC, %o0
F009EEF8: d2028000                 ld      [%o2], %o1
F009EEFC: 912a2002                 sll     %o0, 2, %o0
F009EF00: 90024008                 add     %o1, %o0, %o0
F009EF04: d2020000                 ld      [%o0], %o1
F009EF08: 900a6003                 and     %o1, 3, %o0
F009EF0C: 80a22002                 cmp     %o0, 2
F009EF10: 12800010                 bne     locret_F009EF50
F009EF14: b0102000                 mov     0, %i0
F009EF18: d00aa00d                 ldub    [%o2+0xD], %o0
F009EF1C: 80a22003                 cmp     %o0, 3
F009EF20: 32800007                 bne,a   loc_F009EF3C
F009EF24: 91326008                 srl     %o1, 8, %o0
F009EF28: 93326008                 srl     %o1, 8, %o1
F009EF2C: d007a048                 ld      [%fp+arg_48], %o0
F009EF30: 932a600c                 sll     %o1, 12, %o1
F009EF34: 10800006                 ba      loc_F009EF4C
F009EF38: 900a2fff                 and     %o0, 0xFFF, %o0
F009EF3C: 912a200c                 sll     %o0, 12, %o0
F009EF40: d407a048                 ld      [%fp+arg_48], %o2
F009EF44: 133fff00                 sethi   -0x40000, %o1
F009EF48: 922a8009                 andn    %o2, %o1, %o1
F009EF4C: b0020009                 add     %o0, %o1, %i0
F009EF50: 81c7e008                 ret
F009EF54: 81e80000                 restore
