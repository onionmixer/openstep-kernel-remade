F0011170: 9de3bf98                 save    %sp, -0x68, %sp
F0011174: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0011178: d40421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o2
F001117C: e202a024                 ld      [%o2+0x24], %l1
F0011180: d2046004                 ld      [%l1+4], %o1
F0011184: 80a26020                 cmp     %o1, 0x20 ! ' '
F0011188: 08800005                 bleu    loc_F001119C
F001118C: a61421dc                 or      %l0, %lo(dword_F0133DDC), %l3
F0011190: 90102016                 mov     0x16, %o0
F0011194: 1080006d                 ba      locret_F0011348
F0011198: d02aa038                 stb     %o0, [%o2+0x38]
F001119C: d0044000                 ld      [%l1], %o0
F00111A0: 80a22000                 cmp     %o0, 0
F00111A4: 04800051                 ble     loc_F00112E8
F00111A8: 80a23fff                 cmp     %o0, -1
F00111AC: 7ffff4c5                 call    _pfind
F00111B0: 01000000                 nop
F00111B4: a4920000                 orcc    %o0, %g0, %l2
F00111B8: 32800005                 bne,a   loc_F00111CC
F00111BC: d404fffc                 ld      [%l3-4], %o2
F00111C0: d20421dc                 ld      [%l0+0x1DC], %o1
F00111C4: 10800060                 ba      loc_F0011344
F00111C8: 90102003                 mov     3, %o0
F00111CC: d0028000                 ld      [%o2], %o0
F00111D0: d2022014                 ld      [%o0+0x14], %o1
F00111D4: 11000010                 sethi   0x4000, %o0
F00111D8: 808a4008                 btst    %o0, %o1
F00111DC: 22800032                 be,a    loc_F00112A4
F00111E0: d002a01c                 ld      [%o2+0x1C], %o0
F00111E4: 7ffff64f                 call    _get_posix_proc
F00111E8: d054a030                 ldsh    [%l2+0x30], %o0
F00111EC: 7ffff9e0                 call    _suser
F00111F0: a0100008                 mov     %o0, %l0
F00111F4: 80a22000                 cmp     %o0, 0
F00111F8: 12800025                 bne     loc_F001128C
F00111FC: 113c04cf                 sethi   -0xFECC400, %o0
F0011200: d004fffc                 ld      [%l3-4], %o0
F0011204: d6542004                 ldsh    [%l0+4], %o3
F0011208: d202201c                 ld      [%o0+0x1C], %o1
F001120C: d0526002                 ldsh    [%o1+2], %o0
F0011210: 80a2000b                 cmp     %o0, %o3
F0011214: 2280001e                 be,a    loc_F001128C
F0011218: 113c04cf                 sethi   -0xFECC400, %o0
F001121C: d4542006                 ldsh    [%l0+6], %o2
F0011220: 80a2000a                 cmp     %o0, %o2
F0011224: 2280001a                 be,a    loc_F001128C
F0011228: 113c04cf                 sethi   -0xFECC400, %o0
F001122C: d2526006                 ldsh    [%o1+6], %o1
F0011230: 80a2400b                 cmp     %o1, %o3
F0011234: 02800015                 be      loc_F0011288
F0011238: 80a2400a                 cmp     %o1, %o2
F001123C: 02800014                 be      loc_F001128C
F0011240: 113c04cf                 sethi   -0xFECC400, %o0
F0011244: d0046004                 ld      [%l1+4], %o0
F0011248: 80a22013                 cmp     %o0, 0x13
F001124C: 32800013                 bne,a   loc_F0011298
F0011250: 113c04cf                 sethi   -0xFECC400, %o0
F0011254: 7ffff633                 call    _get_posix_proc
F0011258: d054a030                 ldsh    [%l2+0x30], %o0
F001125C: d204fffc                 ld      [%l3-4], %o1
F0011260: e0022010                 ld      [%o0+0x10], %l0
F0011264: d2024000                 ld      [%o1], %o1
F0011268: 7ffff62e                 call    _get_posix_proc
F001126C: d0526030                 ldsh    [%o1+0x30], %o0
F0011270: d0022010                 ld      [%o0+0x10], %o0
F0011274: d2042008                 ld      [%l0+8], %o1
F0011278: d0022008                 ld      [%o0+8], %o0
F001127C: 80a24008                 cmp     %o1, %o0
F0011280: 12800006                 bne     loc_F0011298
F0011284: 113c04cf                 sethi   -0xFECC400, %o0
F0011288: 113c04cf                 sethi   -0xFECC400, %o0
F001128C: d00221dc                 ld      [%o0+0x1DC], %o0
F0011290: 1080000f                 ba      loc_F00112CC
F0011294: c02a2038                 clrb    [%o0+0x38]
F0011298: d20221dc                 ld      [%o0+0x1DC], %o1
F001129C: 1080002a                 ba      loc_F0011344
F00112A0: 90102001                 mov     1, %o0
F00112A4: d2522002                 ldsh    [%o0+2], %o1
F00112A8: 80a26000                 cmp     %o1, 0
F00112AC: 22800009                 be,a    loc_F00112D0
F00112B0: d2046004                 ld      [%l1+4], %o1
F00112B4: d054a02c                 ldsh    [%l2+0x2C], %o0
F00112B8: 80a24008                 cmp     %o1, %o0
F00112BC: 02800004                 be      loc_F00112CC
F00112C0: d20421dc                 ld      [%l0+0x1DC], %o1
F00112C4: 10800020                 ba      loc_F0011344
F00112C8: 90102001                 mov     1, %o0! unsigned int
F00112CC: d2046004                 ld      [%l1+4], %o1! char *
F00112D0: 80a26000                 cmp     %o1, 0
F00112D4: 0280001d                 be      locret_F0011348
F00112D8: 01000000                 nop
F00112DC: 400000a6                 call    _psignal
F00112E0: 90100012                 mov     %l2, %o0
F00112E4: 30800019                 ba,a    locret_F0011348
F00112E8: 02800006                 be      loc_F0011300
F00112EC: 80a22000                 cmp     %o0, 0
F00112F0: 0280000a                 be      loc_F0011318
F00112F4: 90100009                 mov     %o1, %o0
F00112F8: 1080000d                 ba      loc_F001132C
F00112FC: d2044000                 ld      [%l1], %o1
F0011300: 90100009                 mov     %o1, %o0
F0011304: 92102000                 mov     0, %o1
F0011308: 40000023                 call    _killpg1
F001130C: 94102001                 mov     1, %o2
F0011310: 1080000d                 ba      loc_F0011344
F0011314: d20421dc                 ld      [%l0+0x1DC], %o1
F0011318: 92102000                 mov     0, %o1
F001131C: 4000001e                 call    _killpg1
F0011320: 94102000                 mov     0, %o2
F0011324: 10800008                 ba      loc_F0011344
F0011328: d20421dc                 ld      [%l0+0x1DC], %o1
F001132C: 94102000                 mov     0, %o2
F0011330: d0046004                 ld      [%l1+4], %o0
F0011334: 40000018                 call    _killpg1
F0011338: 92200009                 neg     %o1
F001133C: 133c04cf                 sethi   %hi(dword_F0133DDC), %o1
F0011340: d20261dc                 ld      [%o1+%lo(dword_F0133DDC)], %o1
F0011344: d02a6038                 stb     %o0, [%o1+0x38]
F0011348: 81c7e008                 ret
F001134C: 81e80000                 restore
