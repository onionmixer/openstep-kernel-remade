F00A3180: 9de3bf98                 save    %sp, -0x68, %sp
F00A3184: 133c04f792126270         set     _pmap_info, %o1
F00A318C: d0026100                 ld      [%o1+0x100], %o0
F00A3190: 90022001                 inc     %o0
F00A3194: d0226100                 st      %o0, [%o1+0x100]
F00A3198: e0062008                 ld      [%i0+8], %l0
F00A319C: 80a42000                 cmp     %l0, 0
F00A31A0: 0280000b                 be      loc_F00A31CC
F00A31A4: 92100010                 mov     %l0, %o1
F00A31A8: d0042008                 ld      [%l0+8], %o0
F00A31AC: 80a22000                 cmp     %o0, 0
F00A31B0: 12800007                 bne     loc_F00A31CC
F00A31B4: 80a42000                 cmp     %l0, 0
F00A31B8: e0042014                 ld      [%l0+0x14], %l0
F00A31BC: 80a42000                 cmp     %l0, 0
F00A31C0: 32bffffb                 bne,a   loc_F00A31AC
F00A31C4: d0042008                 ld      [%l0+8], %o0
F00A31C8: 80a42000                 cmp     %l0, 0
F00A31CC: 12800033                 bne     locret_F00A3298
F00A31D0: a0100009                 mov     %o1, %l0
F00A31D4: 80a42000                 cmp     %l0, 0
F00A31D8: 22800025                 be,a    loc_F00A326C
F00A31DC: d2060000                 ld      [%i0], %o1
F00A31E0: 2b3c04f7                 sethi   -0xFEC2400, %l5
F00A31E4: 113c04f7a2122270         set     _pmap_info, %l1
F00A31EC: 293c04f7                 sethi   -0xFEC2400, %l4
F00A31F0: 273c04f7                 sethi   -0xFEC2400, %l3
F00A31F4: d0042018                 ld      [%l0+0x18], %o0
F00A31F8: d00a200d                 ldub    [%o0+0xD], %o0
F00A31FC: 80a22001                 cmp     %o0, 1
F00A3200: 12800009                 bne     loc_F00A3224
F00A3204: 90023ffe                 inc     -2, %o0
F00A3208: 901563a0                 or      %l5, 0x3A0, %o0
F00A320C: 7ffff891                 call    _del_any_pool
F00A3210: 92100010                 mov     %l0, %o1
F00A3214: d004602c                 ld      [%l1+0x2C], %o0
F00A3218: 90023fff                 inc     -1, %o0
F00A321C: 1080000b                 ba      loc_F00A3248
F00A3220: d024602c                 st      %o0, [%l1+0x2C]
F00A3224: 900a20ff                 and     %o0, 0xFF, %o0
F00A3228: 80a22001                 cmp     %o0, 1
F00A322C: 18800007                 bgu     loc_F00A3248
F00A3230: 901523d0                 or      %l4, 0x3D0, %o0
F00A3234: 7ffff887                 call    _del_any_pool
F00A3238: 92100010                 mov     %l0, %o1
F00A323C: d0046020                 ld      [%l1+0x20], %o0
F00A3240: 90023fff                 inc     -1, %o0
F00A3244: d0246020                 st      %o0, [%l1+0x20]
F00A3248: d004e380                 ld      [%l3+0x380], %o0
F00A324C: 7fff57e1                 call    _zfree
F00A3250: 92100010                 mov     %l0, %o1
F00A3254: e4042018                 ld      [%l0+0x18], %l2
F00A3258: e0042014                 ld      [%l0+0x14], %l0
F00A325C: 80a42000                 cmp     %l0, 0
F00A3260: 32bfffe6                 bne,a   loc_F00A31F8
F00A3264: d0042018                 ld      [%l0+0x18], %o0
F00A3268: d2060000                 ld      [%i0], %o1
F00A326C: d0062004                 ld      [%i0+4], %o0
F00A3270: d0226004                 st      %o0, [%o1+4]
F00A3274: d6062004                 ld      [%i0+4], %o3
F00A3278: 92100018                 mov     %i0, %o1
F00A327C: d4024000                 ld      [%o1], %o2
F00A3280: 113c04f7                 sethi   %hi(_garbage_zone), %o0
F00A3284: d0022220                 ld      [%o0+%lo(_garbage_zone)], %o0
F00A3288: 7fff57d2                 call    _zfree
F00A328C: d422c000                 st      %o2, [%o3]
F00A3290: 7fff817d                 call    _kmem_free
F00A3294: 90100012                 mov     %l2, %o0
F00A3298: 81c7e008                 ret
F00A329C: 81e80000                 restore
