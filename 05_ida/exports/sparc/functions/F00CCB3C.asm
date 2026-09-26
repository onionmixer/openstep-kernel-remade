F00CCB3C: 9de3bf90                 save    %sp, -0x70, %sp
F00CCB40: d0062158                 ld      [%i0+0x158], %o0
F00CCB44: 80a22000                 cmp     %o0, 0
F00CCB48: 12800006                 bne     loc_F00CCB60
F00CCB4C: 113c0330                 sethi   -0xFF34000, %o0
F00CCB50: d006215c                 ld      [%i0+0x15C], %o0
F00CCB54: 80a22000                 cmp     %o0, 0
F00CCB58: 02800005                 be      loc_F00CCB6C
F00CCB5C: 113c0330                 sethi   -0xFF34000, %o0
F00CCB60: 9012228c                 bset    0x28C, %o0
F00CCB64: 7ffe8584                 call    _ns_untimeout
F00CCB68: 92100018                 mov     %i0, %o1
F00CCB6C: 7fffe55c                 call    _IOGetTimestamp
F00CCB70: 90062158                 add     %i0, 0x158, %o0
F00CCB74: 8610001a                 mov     %i2, %g3
F00CCB78: 84102000                 mov     0, %g2
F00CCB7C: 9330e01b                 srl     %g3, 27, %o1
F00CCB80: 9128a005                 sll     %g2, 5, %o0
F00CCB84: 98124008                 or      %o1, %o0, %o4
F00CCB88: 9b28e005                 sll     %g3, 5, %o5
F00CCB8C: 9aa34003                 subcc   %o5, %g3, %o5
F00CCB90: 98630002                 subc    %o4, %g2, %o4
F00CCB94: 9733601a                 srl     %o5, 26, %o3
F00CCB98: 952b2006                 sll     %o4, 6, %o2
F00CCB9C: 9012c00a                 or      %o3, %o2, %o0
F00CCBA0: 932b6006                 sll     %o5, 6, %o1
F00CCBA4: 92a2400d                 subcc   %o1, %o5, %o1
F00CCBA8: 9062000c                 subc    %o0, %o4, %o0
F00CCBAC: 9b32601d                 srl     %o1, 29, %o5
F00CCBB0: 992a2003                 sll     %o0, 3, %o4
F00CCBB4: 9413400c                 or      %o5, %o4, %o2
F00CCBB8: 972a6003                 sll     %o1, 3, %o3
F00CCBBC: 9682c003                 addcc   %o3, %g3, %o3
F00CCBC0: 94428002                 addc    %o2, %g2, %o2
F00CCBC4: 9332e01a                 srl     %o3, 26, %o1
F00CCBC8: 912aa006                 sll     %o2, 6, %o0
F00CCBCC: 98124008                 or      %o1, %o0, %o4
F00CCBD0: 9b2ae006                 sll     %o3, 6, %o5
F00CCBD4: 113c03309012228c         set     sub_F00CC28C, %o0
F00CCBDC: d41e2158                 ldd     [%i0+0x158], %o2
F00CCBE0: 92100018                 mov     %i0, %o1
F00CCBE4: 9682c00d                 addcc   %o3, %o5, %o3
F00CCBE8: 9442800c                 addc    %o2, %o4, %o2
F00CCBEC: d43a6158                 std     %o2, [%o1+0x158]
F00CCBF0: 7ffe8559                 call    _ns_abstimeout
F00CCBF4: 98102004                 mov     4, %o4
F00CCBF8: 81c7e008                 ret
F00CCBFC: 81e80000                 restore
