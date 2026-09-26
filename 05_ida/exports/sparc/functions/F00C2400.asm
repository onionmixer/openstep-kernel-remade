F00C2400: 9de3bf98                 save    %sp, -0x68, %sp
F00C2404: 113c04fb                 sethi   %hi(_mousedev), %o0
F00C2408: d6522240                 ldsh    [%o0+%lo(_mousedev)], %o3
F00C240C: 80a2ffff                 cmp     %o3, -1
F00C2410: 12800006                 bne     loc_F00C2428
F00C2414: 9410000b                 mov     %o3, %o2
F00C2418: 113c0484                 sethi   %hi(aNoMouseDeviceP), %o0! "no mouse device present\n"
F00C241C: 7ffd488f                 call    _printf
F00C2420: 90122268                 bset    %lo(aNoMouseDeviceP), %o0! "no mouse device present\n"
F00C2424: 3080000b                 ba,a    locret_F00C2450
F00C2428: 900aa07f                 and     %o2, 0x7F, %o0
F00C242C: 932a2004                 sll     %o0, 4, %o1
F00C2430: 92024008                 add     %o1, %o0, %o1
F00C2434: 932a6003                 sll     %o1, 3, %o1
F00C2438: 113c04fb90122260         set     _zs_tty, %o0
F00C2440: 92024008                 add     %o1, %o0, %o1
F00C2444: d4326038                 sth     %o2, [%o1+0x38]
F00C2448: 40000004                 call    _msopen
F00C244C: 9010000b                 mov     %o3, %o0
F00C2450: 81c7e008                 ret
F00C2454: 81e80000                 restore
