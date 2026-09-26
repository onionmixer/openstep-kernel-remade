F00EDB9C: 9de3bf98                 save    %sp, -0x68, %sp
F00EDBA0: d0060000                 ld      [%i0], %o0
F00EDBA4: d4020000                 ld      [%o0], %o2
F00EDBA8: d0062010                 ld      [%i0+0x10], %o0
F00EDBAC: 9fc28000                 call    %o2
F00EDBB0: 92100019                 mov     %i1, %o1
F00EDBB4: 7ffc633b                 call    _urem
F00EDBB8: d2062008                 ld      [%i0+8], %o1
F00EDBBC: 912a2003                 sll     %o0, 3, %o0
F00EDBC0: d206200c                 ld      [%i0+0xC], %o1
F00EDBC4: a4020009                 add     %o0, %o1, %l2
F00EDBC8: e0020009                 ld      [%o0+%o1], %l0
F00EDBCC: 40000be3                 call    _NXZoneFromPtr
F00EDBD0: 90100018                 mov     %i0, %o0
F00EDBD4: 80a42000                 cmp     %l0, 0
F00EDBD8: 02800080                 be      loc_F00EDDD8
F00EDBDC: a6100008                 mov     %o0, %l3
F00EDBE0: 80a42001                 cmp     %l0, 1
F00EDBE4: 12800018                 bne     loc_F00EDC44
F00EDBE8: 80a42002                 cmp     %l0, 2
F00EDBEC: d404a004                 ld      [%l2+4], %o2
F00EDBF0: 80a6400a                 cmp     %i1, %o2
F00EDBF4: 2280000b                 be,a    loc_F00EDC20
F00EDBF8: f204a004                 ld      [%l2+4], %i1
F00EDBFC: d0060000                 ld      [%i0], %o0
F00EDC00: d6022004                 ld      [%o0+4], %o3
F00EDC04: d0062010                 ld      [%i0+0x10], %o0
F00EDC08: 9fc2c000                 call    %o3
F00EDC0C: 92100019                 mov     %i1, %o1
F00EDC10: 80a22000                 cmp     %o0, 0
F00EDC14: 22800072                 be,a    locret_F00EDDDC
F00EDC18: b0102000                 mov     0, %i0
F00EDC1C: f204a004                 ld      [%l2+4], %i1
F00EDC20: d0062004                 ld      [%i0+4], %o0
F00EDC24: 90023fff                 inc     -1, %o0
F00EDC28: d0262004                 st      %o0, [%i0+4]
F00EDC2C: d0048000                 ld      [%l2], %o0
F00EDC30: 90023fff                 inc     -1, %o0
F00EDC34: d0248000                 st      %o0, [%l2]
F00EDC38: c024a004                 clr     [%l2+4]
F00EDC3C: 10800068                 ba      locret_F00EDDDC
F00EDC40: b0100019                 mov     %i1, %i0
F00EDC44: 12800061                 bne     loc_F00EDDC8
F00EDC48: e204a004                 ld      [%l2+4], %l1
F00EDC4C: d4044000                 ld      [%l1], %o2
F00EDC50: 80a6400a                 cmp     %i1, %o2
F00EDC54: 2280000b                 be,a    loc_F00EDC80
F00EDC58: d0046004                 ld      [%l1+4], %o0
F00EDC5C: d0060000                 ld      [%i0], %o0
F00EDC60: d6022004                 ld      [%o0+4], %o3
F00EDC64: d0062010                 ld      [%i0+0x10], %o0
F00EDC68: 9fc2c000                 call    %o3
F00EDC6C: 92100019                 mov     %i1, %o1
F00EDC70: 80a22000                 cmp     %o0, 0
F00EDC74: 22800006                 be,a    loc_F00EDC8C
F00EDC78: d4046004                 ld      [%l1+4], %o2
F00EDC7C: d0046004                 ld      [%l1+4], %o0
F00EDC80: d024a004                 st      %o0, [%l2+4]
F00EDC84: 10800010                 ba      loc_F00EDCC4
F00EDC88: f2044000                 ld      [%l1], %i1
F00EDC8C: 80a6400a                 cmp     %i1, %o2
F00EDC90: 2280000b                 be,a    loc_F00EDCBC
F00EDC94: d0044000                 ld      [%l1], %o0
F00EDC98: d0060000                 ld      [%i0], %o0
F00EDC9C: d6022004                 ld      [%o0+4], %o3
F00EDCA0: d0062010                 ld      [%i0+0x10], %o0
F00EDCA4: 9fc2c000                 call    %o3
F00EDCA8: 92100019                 mov     %i1, %o1
F00EDCAC: 80a22000                 cmp     %o0, 0
F00EDCB0: 2280004b                 be,a    locret_F00EDDDC
F00EDCB4: b0102000                 mov     0, %i0
F00EDCB8: d0044000                 ld      [%l1], %o0! void *
F00EDCBC: d024a004                 st      %o0, [%l2+4]
F00EDCC0: f2046004                 ld      [%l1+4], %i1
F00EDCC4: 7ffde98f                 call    _free
F00EDCC8: 90100011                 mov     %l1, %o0
F00EDCCC: d0062004                 ld      [%i0+4], %o0
F00EDCD0: 90023fff                 inc     -1, %o0
F00EDCD4: d0262004                 st      %o0, [%i0+4]
F00EDCD8: d0048000                 ld      [%l2], %o0
F00EDCDC: 90023fff                 inc     -1, %o0
F00EDCE0: d0248000                 st      %o0, [%l2]
F00EDCE4: 1080003e                 ba      locret_F00EDDDC
F00EDCE8: b0100019                 mov     %i1, %i0
F00EDCEC: 80a6400a                 cmp     %i1, %o2
F00EDCF0: 2280000b                 be,a    loc_F00EDD1C
F00EDCF4: d2048000                 ld      [%l2], %o1
F00EDCF8: d0060000                 ld      [%i0], %o0
F00EDCFC: d6022004                 ld      [%o0+4], %o3
F00EDD00: d0062010                 ld      [%i0+0x10], %o0
F00EDD04: 9fc2c000                 call    %o3
F00EDD08: 92100019                 mov     %i1, %o1
F00EDD0C: 80a22000                 cmp     %o0, 0
F00EDD10: 2280002e                 be,a    loc_F00EDDC8
F00EDD14: a2046004                 inc     4, %l1
F00EDD18: d2048000                 ld      [%l2], %o1
F00EDD1C: 80a26001                 cmp     %o1, 1
F00EDD20: 02800008                 be      loc_F00EDD40
F00EDD24: f2044000                 ld      [%l1], %i1
F00EDD28: 90100013                 mov     %l3, %o0
F00EDD2C: 92027fff                 inc     -1, %o1
F00EDD30: 40000b92                 call    _NXZoneCalloc
F00EDD34: 94102004                 mov     4, %o2
F00EDD38: 10800003                 ba      loc_F00EDD44
F00EDD3C: a2100008                 mov     %o0, %l1
F00EDD40: a2102000                 mov     0, %l1
F00EDD44: d4048000                 ld      [%l2], %o2
F00EDD48: 9002bfff                 add     %o2, -1, %o0
F00EDD4C: 80a20010                 cmp     %o0, %l0
F00EDD50: 02800007                 be      loc_F00EDD6C
F00EDD54: 90100011                 mov     %l1, %o0! __dst
F00EDD58: 94228010                 sub     %o2, %l0, %o2
F00EDD5C: 9402bfff                 inc     -1, %o2! __len
F00EDD60: d204a004                 ld      [%l2+4], %o1! __src
F00EDD64: 7ffc689b                 call    _memmove
F00EDD68: 952aa002                 sll     %o2, 2, %o2
F00EDD6C: 80a42000                 cmp     %l0, 0
F00EDD70: 0280000b                 be      loc_F00EDD9C
F00EDD74: 952c2002                 sll     %l0, 2, %o2! __len
F00EDD78: d2048000                 ld      [%l2], %o1
F00EDD7C: 932a6002                 sll     %o1, 2, %o1
F00EDD80: 90044009                 add     %l1, %o1, %o0
F00EDD84: 9022000a                 sub     %o0, %o2, %o0
F00EDD88: d604a004                 ld      [%l2+4], %o3
F00EDD8C: 9202400b                 add     %o1, %o3, %o1! __src
F00EDD90: 90023ffc                 inc     -4, %o0! void *
F00EDD94: 7ffc688f                 call    _memmove
F00EDD98: 9222400a                 sub     %o1, %o2, %o1
F00EDD9C: 7ffde959                 call    _free
F00EDDA0: d004a004                 ld      [%l2+4], %o0
F00EDDA4: d0062004                 ld      [%i0+4], %o0
F00EDDA8: 90023fff                 inc     -1, %o0
F00EDDAC: d0262004                 st      %o0, [%i0+4]
F00EDDB0: d0048000                 ld      [%l2], %o0
F00EDDB4: 90023fff                 inc     -1, %o0
F00EDDB8: d0248000                 st      %o0, [%l2]
F00EDDBC: e224a004                 st      %l1, [%l2+4]
F00EDDC0: 10800007                 ba      locret_F00EDDDC
F00EDDC4: b0100019                 mov     %i1, %i0
F00EDDC8: a0043fff                 inc     -1, %l0
F00EDDCC: 80a43fff                 cmp     %l0, -1
F00EDDD0: 32bfffc7                 bne,a   loc_F00EDCEC
F00EDDD4: d4044000                 ld      [%l1], %o2
F00EDDD8: b0102000                 mov     0, %i0
F00EDDDC: 81c7e008                 ret
F00EDDE0: 81e80000                 restore
