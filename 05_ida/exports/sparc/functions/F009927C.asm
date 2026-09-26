F009927C: 9de3bf90                 save    %sp, -0x70, %sp
F0099280: d0060000                 ld      [%i0], %o0
F0099284: 808a2010                 btst    0x10, %o0
F0099288: 02800007                 be      loc_F00992A4
F009928C: 113c04f0                 sethi   -0xFEC4000, %o0
F0099290: d006202c                 ld      [%i0+0x2C], %o0
F0099294: d0022068                 ld      [%o0+0x68], %o0
F0099298: d002200c                 ld      [%o0+0xC], %o0
F009929C: 10800003                 ba      loc_F00992A8
F00992A0: ec022024                 ld      [%o0+0x24], %l6
F00992A4: ec022100                 ld      [%o0+0x100], %l6
F00992A8: aa103fff                 mov     -1, %l5
F00992AC: a0103fff                 mov     -1, %l0
F00992B0: a2103fff                 mov     -1, %l1
F00992B4: d0062020                 ld      [%i0+0x20], %o0
F00992B8: a407bff4                 add     %fp, var_C, %l2
F00992BC: d2062014                 ld      [%i0+0x14], %o1
F00992C0: 940a2fff                 and     %o0, 0xFFF, %o2
F00992C4: 9202400a                 add     %o1, %o2, %o1
F00992C8: 92026fff                 inc     0xFFF, %o1
F00992CC: a732600c                 srl     %o1, 12, %l3
F00992D0: 80a4e000                 cmp     %l3, 0
F00992D4: 0480002d                 ble     loc_F0099388
F00992D8: a8100008                 mov     %o0, %l4
F00992DC: 31000004                 sethi   0x1000, %i0
F00992E0: 90100016                 mov     %l6, %o0
F00992E4: 92100014                 mov     %l4, %o1
F00992E8: 40000f6c                 call    _pmap_getpte
F00992EC: 94100012                 mov     %l2, %o2
F00992F0: 80a47fff                 cmp     %l1, -1
F00992F4: 02800015                 be      loc_F0099348
F00992F8: d2048000                 ld      [%l2], %o1
F00992FC: 900a6003                 and     %o1, 3, %o0
F0099300: 80a22002                 cmp     %o0, 2
F0099304: 32800022                 bne,a   locret_F009938C
F0099308: b0103fff                 mov     -1, %i0
F009930C: 40005e9e                 call    _bustype
F0099310: 91326008                 srl     %o1, 8, %o0
F0099314: 80a44008                 cmp     %l1, %o0
F0099318: 3280001d                 bne,a   locret_F009938C
F009931C: b0103fff                 mov     -1, %i0
F0099320: 80a46002                 cmp     %l1, 2
F0099324: 22800015                 be,a    loc_F0099378
F0099328: a0042001                 inc     %l0
F009932C: d0048000                 ld      [%l2], %o0
F0099330: 91322008                 srl     %o0, 8, %o0
F0099334: 80a20010                 cmp     %o0, %l0
F0099338: 02800010                 be      loc_F0099378
F009933C: a0042001                 inc     %l0
F0099340: 10800013                 ba      locret_F009938C
F0099344: b0103fff                 mov     -1, %i0
F0099348: 900a6003                 and     %o1, 3, %o0
F009934C: 80a22002                 cmp     %o0, 2
F0099350: 12bffffc                 bne     loc_F0099340
F0099354: a1326008                 srl     %o1, 8, %l0
F0099358: 40005e8b                 call    _bustype
F009935C: 90100010                 mov     %l0, %o0
F0099360: a2100008                 mov     %o0, %l1
F0099364: 80a46002                 cmp     %l1, 2
F0099368: 12800003                 bne     loc_F0099374
F009936C: aa100010                 mov     %l0, %l5
F0099370: aa102000                 mov     0, %l5
F0099374: a0042001                 inc     %l0
F0099378: a604ffff                 inc     -1, %l3
F009937C: 80a4e000                 cmp     %l3, 0
F0099380: 14bfffd8                 bg      loc_F00992E0
F0099384: a8050018                 add     %l4, %i0, %l4
F0099388: b0100015                 mov     %l5, %i0
F009938C: 81c7e008                 ret
F0099390: 81e80000                 restore
