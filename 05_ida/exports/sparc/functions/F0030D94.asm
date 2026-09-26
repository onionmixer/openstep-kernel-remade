F0030D94: 9de3bf98                 save    %sp, -0x68, %sp
F0030D98: f606c000                 ld      [%i3], %i3
F0030D9C: 80a76015                 cmp     %i5, 0x15
F0030DA0: 1880004d                 bgu     locret_F0030ED4
F0030DA4: e207a05c                 ld      [%fp+arg_5C], %l1
F0030DA8: d0164000                 lduh    [%i1], %o0
F0030DAC: 80a22002                 cmp     %o0, 2
F0030DB0: 12800049                 bne     locret_F0030ED4
F0030DB4: 01000000                 nop
F0030DB8: f2066004                 ld      [%i1+4], %i1
F0030DBC: 80a66000                 cmp     %i1, 0
F0030DC0: 02800045                 be      locret_F0030ED4
F0030DC4: 90077ff2                 add     %i5, -0xE, %o0
F0030DC8: 80a22003                 cmp     %o0, 3
F0030DCC: 08800006                 bleu    loc_F0030DE4
F0030DD0: 80a76006                 cmp     %i5, 6
F0030DD4: 02800004                 be      loc_F0030DE4
F0030DD8: 80a76001                 cmp     %i5, 1
F0030DDC: 1280000a                 bne     loc_F0030E04
F0030DE0: 113c0432                 sethi   -0xFEF3800, %o0
F0030DE4: b4102000                 mov     0, %i2
F0030DE8: b8102000                 mov     0, %i4
F0030DEC: 80a76006                 cmp     %i5, 6
F0030DF0: 02800004                 be      loc_F0030E00
F0030DF4: b6102000                 mov     0, %i3
F0030DF8: 113c00c3a2122320         set     _in_rtchange, %l1
F0030E00: 113c0432                 sethi   -0xFEF3800, %o0
F0030E04: e0060000                 ld      [%i0], %l0
F0030E08: 90122010                 bset    0x10, %o0
F0030E0C: 80a40018                 cmp     %l0, %i0
F0030E10: 02800031                 be      locret_F0030ED4
F0030E14: fa0f4008                 ldub    [%i5+%o0], %i5
F0030E18: 912f2010                 sll     %i4, 16, %o0
F0030E1C: b9322010                 srl     %o0, 16, %i4
F0030E20: 912ea010                 sll     %i2, 16, %o0
F0030E24: b5322010                 srl     %o0, 16, %i2
F0030E28: d004200c                 ld      [%l0+0xC], %o0
F0030E2C: 80a20019                 cmp     %o0, %i1
F0030E30: 32800026                 bne,a   loc_F0030EC8
F0030E34: e0040000                 ld      [%l0], %l0
F0030E38: d004201c                 ld      [%l0+0x1C], %o0
F0030E3C: 80a22000                 cmp     %o0, 0
F0030E40: 02800016                 be      loc_F0030E98
F0030E44: 80a72000                 cmp     %i4, 0
F0030E48: 02800007                 be      loc_F0030E64
F0030E4C: 80a6e000                 cmp     %i3, 0
F0030E50: d0142018                 lduh    [%l0+0x18], %o0
F0030E54: 80a2001c                 cmp     %o0, %i4
F0030E58: 3280001c                 bne,a   loc_F0030EC8
F0030E5C: e0040000                 ld      [%l0], %l0
F0030E60: 80a6e000                 cmp     %i3, 0
F0030E64: 02800007                 be      loc_F0030E80
F0030E68: 80a6a000                 cmp     %i2, 0
F0030E6C: d0042014                 ld      [%l0+0x14], %o0
F0030E70: 80a2001b                 cmp     %o0, %i3
F0030E74: 32800015                 bne,a   loc_F0030EC8
F0030E78: e0040000                 ld      [%l0], %l0
F0030E7C: 80a6a000                 cmp     %i2, 0
F0030E80: 02800008                 be      loc_F0030EA0
F0030E84: 80a76000                 cmp     %i5, 0
F0030E88: d0142010                 lduh    [%l0+0x10], %o0
F0030E8C: 80a2001a                 cmp     %o0, %i2
F0030E90: 02800004                 be      loc_F0030EA0
F0030E94: 80a76000                 cmp     %i5, 0
F0030E98: 1080000c                 ba      loc_F0030EC8
F0030E9C: e0040000                 ld      [%l0], %l0
F0030EA0: 02800005                 be      loc_F0030EB4
F0030EA4: 90100010                 mov     %l0, %o0
F0030EA8: d004201c                 ld      [%l0+0x1C], %o0
F0030EAC: fa322056                 sth     %i5, [%o0+0x56]
F0030EB0: 90100010                 mov     %l0, %o0
F0030EB4: 80a46000                 cmp     %l1, 0
F0030EB8: 02800004                 be      loc_F0030EC8
F0030EBC: e0040000                 ld      [%l0], %l0
F0030EC0: 9fc44000                 call    %l1
F0030EC4: 01000000                 nop
F0030EC8: 80a40018                 cmp     %l0, %i0
F0030ECC: 32bfffd8                 bne,a   loc_F0030E2C
F0030ED0: d004200c                 ld      [%l0+0xC], %o0
F0030ED4: 81c7e008                 ret
F0030ED8: 81e80000                 restore
