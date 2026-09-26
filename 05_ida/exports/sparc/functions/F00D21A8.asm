F00D21A8: 9de3bf90                 save    %sp, -0x70, %sp
F00D21AC: d0062134                 ld      [%i0+0x134], %o0
F00D21B0: 80a68008                 cmp     %i2, %o0
F00D21B4: 02800004                 be      loc_F00D21C4
F00D21B8: a0102000                 mov     0, %l0
F00D21BC: 1080001f                 ba      locret_F00D2238
F00D21C0: b0103d3e                 mov     -0x2C2, %i0
F00D21C4: d0062110                 ld      [%i0+0x110], %o0! id
F00D21C8: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00D21CC: 40007da9                 call    _objc_msgSend
F00D21D0: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00D21D4: d04e21d0                 ldsb    [%i0+0x1D0], %o0
F00D21D8: 80a22001                 cmp     %o0, 1
F00D21DC: 32800004                 bne,a   loc_F00D21EC
F00D21E0: 92102001                 mov     1, %o1
F00D21E4: 10800010                 ba      loc_F00D2224
F00D21E8: a0103d2b                 mov     -0x2D5, %l0
F00D21EC: d04e21d1                 ldsb    [%i0+0x1D1], %o0
F00D21F0: 80a22000                 cmp     %o0, 0
F00D21F4: 12800007                 bne     loc_F00D2210
F00D21F8: d22e21d0                 stb     %o1, [%i0+0x1D0]
F00D21FC: d22e21d1                 stb     %o1, [%i0+0x1D1]
F00D2200: 90102040                 mov     0x40, %o0 ! '@'
F00D2204: d02621cc                 st      %o0, [%i0+0x1CC]
F00D2208: 90102020                 mov     0x20, %o0 ! ' '
F00D220C: d02621c4                 st      %o0, [%i0+0x1C4]
F00D2210: 90100018                 mov     %i0, %o0! id
F00D2214: 133c0505                 sethi   %hi(paSeteventport), %o1
F00D2218: d2026354                 ld      [%o1+%lo(paSeteventport)], %o1! SEL
F00D221C: 40007d95                 call    _objc_msgSend
F00D2220: 9410001b                 mov     %i3, %o2
F00D2224: d0062110                 ld      [%i0+0x110], %o0! id
F00D2228: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00D222C: 40007d91                 call    _objc_msgSend
F00D2230: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00D2234: b0100010                 mov     %l0, %i0
F00D2238: 81c7e008                 ret
F00D223C: 81e80000                 restore
