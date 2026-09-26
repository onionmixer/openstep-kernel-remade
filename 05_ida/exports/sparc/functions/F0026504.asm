F0026504: 9de3bf98                 save    %sp, -0x68, %sp
F0026508: d056200e                 ldsh    [%i0+0xE], %o0
F002650C: 80a22001                 cmp     %o0, 1
F0026510: 12800008                 bne     loc_F0026530
F0026514: e2062018                 ld      [%i0+0x18], %l1
F0026518: d0062008                 ld      [%i0+8], %o0
F002651C: 808a2180                 btst    0x180, %o0
F0026520: 02800004                 be      loc_F0026530
F0026524: 90100018                 mov     %i0, %o0
F0026528: 400000e6                 call    _vno_bsd_unlock
F002652C: 92102180                 mov     0x180, %o1
F0026530: d2062008                 ld      [%i0+8], %o1
F0026534: d456200e                 ldsh    [%i0+0xE], %o2
F0026538: 40000aaf                 call    _vn_close
F002653C: 90100011                 mov     %l1, %o0
F0026540: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F0026544: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F0026548: d02a6038                 stb     %o0, [%o1+0x38]
F002654C: d056200e                 ldsh    [%i0+0xE], %o0
F0026550: 80a22001                 cmp     %o0, 1
F0026554: 12800005                 bne     loc_F0026568
F0026558: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F002655C: 40000982                 call    _vn_rele
F0026560: 90100011                 mov     %l1, %o0
F0026564: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F0026568: f04a2038                 ldsb    [%o0+0x38], %i0
F002656C: 81c7e008                 ret
F0026570: 81e80000                 restore
