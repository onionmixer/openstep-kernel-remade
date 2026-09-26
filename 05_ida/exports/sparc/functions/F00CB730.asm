F00CB730: 9de3bf90                 save    %sp, -0x70, %sp
F00CB734: d0062130                 ld      [%i0+0x130], %o0
F00CB738: 80a22000                 cmp     %o0, 0
F00CB73C: 12800006                 bne     loc_F00CB754
F00CB740: 113c032c                 sethi   -0xFF35000, %o0
F00CB744: d0062134                 ld      [%i0+0x134], %o0
F00CB748: 80a22000                 cmp     %o0, 0
F00CB74C: 02800005                 be      loc_F00CB760
F00CB750: 113c032c                 sethi   -0xFF35000, %o0
F00CB754: 90122194                 bset    0x194, %o0
F00CB758: 7ffe8a87                 call    _ns_untimeout
F00CB75C: 92100018                 mov     %i0, %o1
F00CB760: 7fffea5f                 call    _IOGetTimestamp
F00CB764: 90062130                 add     %i0, 0x130, %o0
F00CB768: 8610001a                 mov     %i2, %g3
F00CB76C: 84102000                 mov     0, %g2
F00CB770: 9330e01b                 srl     %g3, 27, %o1
F00CB774: 9128a005                 sll     %g2, 5, %o0
F00CB778: 98124008                 or      %o1, %o0, %o4
F00CB77C: 9b28e005                 sll     %g3, 5, %o5
F00CB780: 9aa34003                 subcc   %o5, %g3, %o5
F00CB784: 98630002                 subc    %o4, %g2, %o4
F00CB788: 9733601a                 srl     %o5, 26, %o3
F00CB78C: 952b2006                 sll     %o4, 6, %o2
F00CB790: 9012c00a                 or      %o3, %o2, %o0
F00CB794: 932b6006                 sll     %o5, 6, %o1
F00CB798: 92a2400d                 subcc   %o1, %o5, %o1
F00CB79C: 9062000c                 subc    %o0, %o4, %o0
F00CB7A0: 9b32601d                 srl     %o1, 29, %o5
F00CB7A4: 992a2003                 sll     %o0, 3, %o4
F00CB7A8: 9413400c                 or      %o5, %o4, %o2
F00CB7AC: 972a6003                 sll     %o1, 3, %o3
F00CB7B0: 9682c003                 addcc   %o3, %g3, %o3
F00CB7B4: 94428002                 addc    %o2, %g2, %o2
F00CB7B8: 9332e01a                 srl     %o3, 26, %o1
F00CB7BC: 912aa006                 sll     %o2, 6, %o0
F00CB7C0: 98124008                 or      %o1, %o0, %o4
F00CB7C4: 9b2ae006                 sll     %o3, 6, %o5
F00CB7C8: 113c032c90122194         set     sub_F00CB194, %o0
F00CB7D0: d41e2130                 ldd     [%i0+0x130], %o2
F00CB7D4: 92100018                 mov     %i0, %o1
F00CB7D8: 9682c00d                 addcc   %o3, %o5, %o3
F00CB7DC: 9442800c                 addc    %o2, %o4, %o2
F00CB7E0: d43a6130                 std     %o2, [%o1+0x130]
F00CB7E4: 7ffe8a5c                 call    _ns_abstimeout
F00CB7E8: 98102004                 mov     4, %o4
F00CB7EC: 81c7e008                 ret
F00CB7F0: 81e80000                 restore
