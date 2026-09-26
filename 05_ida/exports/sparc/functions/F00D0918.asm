F00D0918: 9de3bf90                 save    %sp, -0x70, %sp
F00D091C: 9610001b                 mov     %i3, %o3
F00D0920: d0062124                 ld      [%i0+0x124], %o0
F00D0924: 21200000                 sethi   0x80000000, %l0
F00D0928: 808a0010                 btst    %l0, %o0
F00D092C: 02800016                 be      loc_F00D0984
F00D0930: 9810001c                 mov     %i4, %o4
F00D0934: d2068000                 ld      [%i2], %o1
F00D0938: d0062108                 ld      [%i0+0x108], %o0
F00D093C: 80a24008                 cmp     %o1, %o0
F00D0940: 3280004c                 bne,a   locret_F00D0A70
F00D0944: b6102007                 mov     7, %i3
F00D0948: d206a004                 ld      [%i2+4], %o1
F00D094C: d006210c                 ld      [%i0+0x10C], %o0
F00D0950: 80a24008                 cmp     %o1, %o0
F00D0954: 32800047                 bne,a   locret_F00D0A70
F00D0958: b6102007                 mov     7, %i3
F00D095C: d206a008                 ld      [%i2+8], %o1
F00D0960: d0062110                 ld      [%i0+0x110], %o0
F00D0964: 80a24008                 cmp     %o1, %o0
F00D0968: 32800042                 bne,a   locret_F00D0A70
F00D096C: b6102007                 mov     7, %i3
F00D0970: d206a00c                 ld      [%i2+0xC], %o1
F00D0974: d0062114                 ld      [%i0+0x114], %o0
F00D0978: 80a24008                 cmp     %o1, %o0
F00D097C: 22800004                 be,a    loc_F00D098C
F00D0980: d0062128                 ld      [%i0+0x128], %o0! id
F00D0984: 1080003b                 ba      locret_F00D0A70
F00D0988: b6102007                 mov     7, %i3
F00D098C: 133c0505                 sethi   %hi(paExecutescsi3re_0), %o1
F00D0990: d2026360                 ld      [%o1+%lo(paExecutescsi3re_0)], %o1! SEL
F00D0994: 400083b7                 call    _objc_msgSend
F00D0998: 9410001a                 mov     %i2, %o2
F00D099C: b6100008                 mov     %o0, %i3
F00D09A0: 80a6e002                 cmp     %i3, 2
F00D09A4: 12800011                 bne     loc_F00D09E8
F00D09A8: 80a6e003                 cmp     %i3, 3
F00D09AC: d006a050                 ld      [%i2+0x50], %o0
F00D09B0: d0274000                 st      %o0, [%i5]
F00D09B4: d006a054                 ld      [%i2+0x54], %o0
F00D09B8: d0276004                 st      %o0, [%i5+4]
F00D09BC: d006a058                 ld      [%i2+0x58], %o0
F00D09C0: d0276008                 st      %o0, [%i5+8]
F00D09C4: d006a05c                 ld      [%i2+0x5C], %o0
F00D09C8: d027600c                 st      %o0, [%i5+0xC]
F00D09CC: d006a060                 ld      [%i2+0x60], %o0
F00D09D0: d0276010                 st      %o0, [%i5+0x10]
F00D09D4: d006a064                 ld      [%i2+0x64], %o0
F00D09D8: d0276014                 st      %o0, [%i5+0x14]
F00D09DC: d006a068                 ld      [%i2+0x68], %o0
F00D09E0: 10800024                 ba      locret_F00D0A70
F00D09E4: d0276018                 st      %o0, [%i5+0x18]
F00D09E8: 12800022                 bne     locret_F00D0A70
F00D09EC: 01000000                 nop
F00D09F0: d006211c                 ld      [%i0+0x11C], %o0
F00D09F4: 808a0010                 btst    %l0, %o0
F00D09F8: 0280001e                 be      locret_F00D0A70
F00D09FC: 90100018                 mov     %i0, %o0! id
F00D0A00: 133c0505                 sethi   %hi(paGetsense), %o1
F00D0A04: d2026364                 ld      [%o1+%lo(paGetsense)], %o1! SEL
F00D0A08: 4000839a                 call    _objc_msgSend
F00D0A0C: 9410001d                 mov     %i5, %o2
F00D0A10: b6920000                 orcc    %o0, %g0, %i3
F00D0A14: 12800004                 bne     loc_F00D0A24
F00D0A18: 90100018                 mov     %i0, %o0! id
F00D0A1C: 10800015                 ba      locret_F00D0A70
F00D0A20: b6102002                 mov     2, %i3
F00D0A24: 133c0504                 sethi   %hi(paName), %o1
F00D0A28: 213c03ed                 sethi   %hi(aSRequestSenseO), %l0! "%s: Request Sense on target %d lun %d f"...
F00D0A2C: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00D0A30: 40008390                 call    _objc_msgSend
F00D0A34: a01422a8                 bset    %lo(aSRequestSenseO), %l0! "%s: Request Sense on target %d lun %d f"...
F00D0A38: a2100008                 mov     %o0, %l1
F00D0A3C: 9010001b                 mov     %i3, %o0
F00D0A40: 133c04bb                 sethi   %hi(_IOScStatusStrings), %o1
F00D0A44: e81e2108                 ldd     [%i0+0x108], %l4
F00D0A48: 92126100                 bset    %lo(_IOScStatusStrings), %o1
F00D0A4C: e41e2110                 ldd     [%i0+0x110], %l2
F00D0A50: 7fffd5ba                 call    _IOFindNameForValue
F00D0A54: b6102003                 mov     3, %i3
F00D0A58: 98100008                 mov     %o0, %o4
F00D0A5C: 90100010                 mov     %l0, %o0
F00D0A60: 92100011                 mov     %l1, %o1
F00D0A64: 94100015                 mov     %l5, %o2
F00D0A68: 7fffd5a3                 call    _IOLog
F00D0A6C: 96100013                 mov     %l3, %o3
F00D0A70: 81c7e008                 ret
F00D0A74: 91e8001b                 restore %g0, %i3, %o0
