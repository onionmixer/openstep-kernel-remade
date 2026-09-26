F00EC5BC: 9de3bf90                 save    %sp, -0x70, %sp
F00EC5C0: 80a6a000                 cmp     %i2, 0
F00EC5C4: 22800029                 be,a    locret_F00EC668
F00EC5C8: b0102000                 mov     0, %i0
F00EC5CC: d006a004                 ld      [%i2+4], %o0! __s1
F00EC5D0: 7ffc6ef7                 call    _strcmp
F00EC5D4: d2062004                 ld      [%i0+4], %o1
F00EC5D8: 80a22000                 cmp     %o0, 0
F00EC5DC: 32800004                 bne,a   loc_F00EC5EC
F00EC5E0: d0062008                 ld      [%i0+8], %o0
F00EC5E4: 10800021                 ba      locret_F00EC668
F00EC5E8: b0102001                 mov     1, %i0
F00EC5EC: 80a22000                 cmp     %o0, 0
F00EC5F0: 0280001d                 be      loc_F00EC664
F00EC5F4: 92100008                 mov     %o0, %o1! __s2
F00EC5F8: a2102000                 mov     0, %l1
F00EC5FC: d0022004                 ld      [%o0+4], %o0
F00EC600: 80a44008                 cmp     %l1, %o0
F00EC604: 36800019                 bge,a   locret_F00EC668
F00EC608: b0102000                 mov     0, %i0
F00EC60C: 253c0504                 sethi   -0xFEBF000, %l2
F00EC610: 912c6002                 sll     %l1, 2, %o0
F00EC614: 90020009                 add     %o0, %o1, %o0
F00EC618: e0022008                 ld      [%o0+8], %l0
F00EC61C: d006a004                 ld      [%i2+4], %o0! __s1
F00EC620: 7ffc6ee3                 call    _strcmp
F00EC624: d2042004                 ld      [%l0+4], %o1
F00EC628: 80a22000                 cmp     %o0, 0
F00EC62C: 02bfffee                 be      loc_F00EC5E4
F00EC630: 90100010                 mov     %l0, %o0! id
F00EC634: d204a018                 ld      [%l2+0x18], %o1! SEL
F00EC638: 4000148e                 call    _objc_msgSend
F00EC63C: 9410001a                 mov     %i2, %o2
F00EC640: 912a2018                 sll     %o0, 24, %o0
F00EC644: 80a22000                 cmp     %o0, 0
F00EC648: 12bfffe7                 bne     loc_F00EC5E4
F00EC64C: a2046001                 inc     %l1
F00EC650: d2062008                 ld      [%i0+8], %o1
F00EC654: d0026004                 ld      [%o1+4], %o0
F00EC658: 80a44008                 cmp     %l1, %o0
F00EC65C: 06bfffee                 bl      loc_F00EC614
F00EC660: 912c6002                 sll     %l1, 2, %o0
F00EC664: b0102000                 mov     0, %i0
F00EC668: 81c7e008                 ret
F00EC66C: 81e80000                 restore
