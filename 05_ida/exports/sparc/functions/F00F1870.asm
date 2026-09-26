F00F1870: 9de3bfa0                 save    %sp, -0x60, %sp
F00F1874: 233c04bc                 sethi   %hi(__objc_multithread_mask), %l1
F00F1878: e2046130                 ld      [%l1+%lo(__objc_multithread_mask)], %l1
F00F187C: a28c4018                 andcc   %l1, %i0, %l1
F00F1880: 3280000e                 bne,a   loc_F00F18B8
F00F1884: d0062000                 ld      [%i0], %o0
F00F1888: 80960000                 tst     %i0
F00F188C: 1280001f                 bne     loc_F00F1908
F00F1890: 01000000                 nop
F00F1894: c607e008                 ld      [%i7+8], %g3
F00F1898: 053ff000                 sethi   -0x400000, %g2
F00F189C: 8088c002                 btst    %g2, %g3
F00F18A0: 02800004                 be      loc_F00F18B0
F00F18A4: 01000000                 nop
F00F18A8: 81c7e008                 ret
F00F18AC: 81e80000                 restore
F00F18B0: 81c7e00c                 jmp     %i7+0xC
F00F18B4: 81e80000                 restore
F00F18B8: e8022020                 ld      [%o0+0x20], %l4
F00F18BC: e6052000                 ld      [%l4], %l3
F00F18C0: a4052008                 add     %l4, 8, %l2
F00F18C4: a20e4013                 and     %i1, %l3, %l1
F00F18C8: ad2c6002                 sll     %l1, 2, %l6
F00F18CC: e8048016                 ld      [%l2+%l6], %l4
F00F18D0: 80950000                 tst     %l4
F00F18D4: 22800009                 be,a    loc_F00F18F8
F00F18D8: 92100019                 mov     %i1, %o1
F00F18DC: ea052000                 ld      [%l4], %l5
F00F18E0: 80a54019                 cmp     %l5, %i1
F00F18E4: 22800007                 be,a    loc_F00F1900
F00F18E8: d0052008                 ld      [%l4+8], %o0
F00F18EC: a2046001                 inc     %l1
F00F18F0: 10bffff6                 ba      loc_F00F18C8
F00F18F4: a20c4013                 and     %l1, %l3, %l1
F00F18F8: 7ffffa53                 call    __class_lookupMethodAndLoadCache
F00F18FC: 01000000                 nop
F00F1900: 81c20000                 jmp     %o0
F00F1904: 81e80000                 restore
F00F1908: 2f3c04bcae15e0d8         set     _messageLock, %l7
F00F1910: a2102001                 mov     1, %l1
F00F1914: e27dc000                 swap    [%l7], %l1
F00F1918: 80944000                 tst     %l1
F00F191C: 12bffffe                 bne     loc_F00F1914
F00F1920: a2102001                 mov     1, %l1
F00F1924: d0062000                 ld      [%i0], %o0
F00F1928: e8022020                 ld      [%o0+0x20], %l4
F00F192C: e6052000                 ld      [%l4], %l3
F00F1930: a4052008                 add     %l4, 8, %l2
F00F1934: a20e4013                 and     %i1, %l3, %l1
F00F1938: ad2c6002                 sll     %l1, 2, %l6
F00F193C: e8048016                 ld      [%l2+%l6], %l4
F00F1940: 80950000                 tst     %l4
F00F1944: 22800009                 be,a    loc_F00F1968
F00F1948: 92100019                 mov     %i1, %o1
F00F194C: ea052000                 ld      [%l4], %l5
F00F1950: 80a54019                 cmp     %l5, %i1
F00F1954: 22800007                 be,a    loc_F00F1970
F00F1958: d0052008                 ld      [%l4+8], %o0
F00F195C: a2046001                 inc     %l1
F00F1960: 10bffff6                 ba      loc_F00F1938
F00F1964: a20c4013                 and     %l1, %l3, %l1
F00F1968: 7ffffa37                 call    __class_lookupMethodAndLoadCache
F00F196C: 01000000                 nop
F00F1970: c07dc000                 swap    [%l7], %g0
F00F1974: 81c20000                 jmp     %o0
F00F1978: 81e80000                 restore
