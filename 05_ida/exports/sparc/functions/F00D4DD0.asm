F00D4DD0: 9de3bf90                 save    %sp, -0x70, %sp
F00D4DD4: e0062168                 ld      [%i0+0x168], %l0
F00D4DD8: d0042008                 ld      [%l0+8], %o0
F00D4DDC: 920ea004                 and     %i2, 4, %o1
F00D4DE0: 900a2004                 and     %o0, 4, %o0
F00D4DE4: 80a20009                 cmp     %o0, %o1
F00D4DE8: 02800029                 be      loc_F00D4E8C
F00D4DEC: 80a26000                 cmp     %o1, 0
F00D4DF0: 0280000c                 be      loc_F00D4E20
F00D4DF4: 90100018                 mov     %i0, %o0! id
F00D4DF8: 94102001                 mov     1, %o2
F00D4DFC: 96042018                 add     %l0, 0x18, %o3
F00D4E00: 9810001b                 mov     %i3, %o4
F00D4E04: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D4E08: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D4E0C: 40007299                 call    _objc_msgSend
F00D4E10: 9a102000                 mov     0, %o5
F00D4E14: d0042008                 ld      [%l0+8], %o0
F00D4E18: 1080000b                 ba      loc_F00D4E44
F00D4E1C: 90122004                 bset    4, %o0! id
F00D4E20: 94102002                 mov     2, %o2
F00D4E24: 96042018                 add     %l0, 0x18, %o3
F00D4E28: 9810001b                 mov     %i3, %o4
F00D4E2C: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D4E30: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D4E34: 4000728f                 call    _objc_msgSend
F00D4E38: 9a102000                 mov     0, %o5
F00D4E3C: d0042008                 ld      [%l0+8], %o0
F00D4E40: 900a3ffb                 and     %o0, -5, %o0
F00D4E44: d0242008                 st      %o0, [%l0+8]
F00D4E48: d00c2033                 ldub    [%l0+0x33], %o0
F00D4E4C: 91322001                 srl     %o0, 1, %o0
F00D4E50: d20c2033                 ldub    [%l0+0x33], %o1
F00D4E54: 900a2002                 and     %o0, 2, %o0
F00D4E58: 920a60fd                 and     %o1, 0xFD, %o1
F00D4E5C: 92124008                 bset    %o0, %o1
F00D4E60: d22c2033                 stb     %o1, [%l0+0x33]
F00D4E64: d00c2033                 ldub    [%l0+0x33], %o0
F00D4E68: 808a2002                 btst    2, %o0
F00D4E6C: 02800005                 be      loc_F00D4E80
F00D4E70: 01000000                 nop
F00D4E74: d004200c                 ld      [%l0+0xC], %o0
F00D4E78: 10800004                 ba      loc_F00D4E88
F00D4E7C: 90122100                 bset    0x100, %o0
F00D4E80: d004200c                 ld      [%l0+0xC], %o0
F00D4E84: 900a3eff                 and     %o0, -0x101, %o0
F00D4E88: d024200c                 st      %o0, [%l0+0xC]
F00D4E8C: d0042008                 ld      [%l0+8], %o0
F00D4E90: b40ea001                 and     %i2, 1, %i2
F00D4E94: 900a2001                 and     %o0, 1, %o0
F00D4E98: 80a2001a                 cmp     %o0, %i2
F00D4E9C: 02800018                 be      locret_F00D4EFC
F00D4EA0: 80a6a000                 cmp     %i2, 0
F00D4EA4: 0280000c                 be      loc_F00D4ED4
F00D4EA8: 90100018                 mov     %i0, %o0! id
F00D4EAC: 94102003                 mov     3, %o2
F00D4EB0: 96042018                 add     %l0, 0x18, %o3
F00D4EB4: 9810001b                 mov     %i3, %o4
F00D4EB8: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D4EBC: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D4EC0: 4000726c                 call    _objc_msgSend
F00D4EC4: 9a102000                 mov     0, %o5
F00D4EC8: d0042008                 ld      [%l0+8], %o0
F00D4ECC: 1080000b                 ba      loc_F00D4EF8
F00D4ED0: 90122001                 bset    1, %o0! id
F00D4ED4: 94102004                 mov     4, %o2
F00D4ED8: 96042018                 add     %l0, 0x18, %o3
F00D4EDC: 9810001b                 mov     %i3, %o4
F00D4EE0: 133c0505                 sethi   %hi(paPosteventAtAtt), %o1
F00D4EE4: d2026314                 ld      [%o1+%lo(paPosteventAtAtt)], %o1! SEL
F00D4EE8: 40007262                 call    _objc_msgSend
F00D4EEC: 9a102000                 mov     0, %o5
F00D4EF0: d0042008                 ld      [%l0+8], %o0
F00D4EF4: 900a3ffe                 and     %o0, -2, %o0
F00D4EF8: d0242008                 st      %o0, [%l0+8]
F00D4EFC: 81c7e008                 ret
F00D4F00: 81e80000                 restore
