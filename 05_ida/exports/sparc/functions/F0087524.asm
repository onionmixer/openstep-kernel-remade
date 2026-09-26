F0087524: 9de3bf98                 save    %sp, -0x68, %sp
F0087528: 920e207f                 and     %i0, 0x7F, %o1
F008752C: 932a6003                 sll     %o1, 3, %o1
F0087530: 113c04f590122030         set     _vm_object_hashtable, %o0
F0087538: d6024008                 ld      [%o1+%o0], %o3
F008753C: 92024008                 add     %o1, %o0, %o1
F0087540: 80a2400b                 cmp     %o1, %o3
F0087544: 02800019                 be      locret_F00875A8
F0087548: 193c04f4                 sethi   -0xFEC3000, %o4
F008754C: d002e008                 ld      [%o3+8], %o0
F0087550: d0022028                 ld      [%o0+0x28], %o0
F0087554: 80a20018                 cmp     %o0, %i0
F0087558: 32800011                 bne,a   loc_F008759C
F008755C: d602c000                 ld      [%o3], %o3
F0087560: d402c000                 ld      [%o3], %o2
F0087564: 80a2400a                 cmp     %o1, %o2
F0087568: 12800004                 bne     loc_F0087578
F008756C: d002e004                 ld      [%o3+4], %o0
F0087570: 10800003                 ba      loc_F008757C
F0087574: d0226004                 st      %o0, [%o1+4]
F0087578: d022a004                 st      %o0, [%o2+4]
F008757C: 80a24008                 cmp     %o1, %o0
F0087580: 22800003                 be,a    loc_F008758C
F0087584: d4224000                 st      %o2, [%o1]
F0087588: d4220000                 st      %o2, [%o0]
F008758C: d00323f8                 ld      [%o4+0x3F8], %o0
F0087590: 7fffc710                 call    _zfree
F0087594: 9210000b                 mov     %o3, %o1
F0087598: 30800004                 ba,a    locret_F00875A8
F008759C: 80a2400b                 cmp     %o1, %o3
F00875A0: 32bfffec                 bne,a   loc_F0087550
F00875A4: d002e008                 ld      [%o3+8], %o0
F00875A8: 81c7e008                 ret
F00875AC: 81e80000                 restore
