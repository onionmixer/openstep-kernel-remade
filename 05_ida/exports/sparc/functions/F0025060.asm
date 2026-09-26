F0025060: 9de3bf98                 save    %sp, -0x68, %sp
F0025064: 4001c6c9                 call    _splusclock
F0025068: 01000000                 nop
F002506C: d2060000                 ld      [%i0], %o1
F0025070: 808a6002                 btst    2, %o1
F0025074: 12800009                 bne     loc_F0025098
F0025078: a0100008                 mov     %o0, %l0
F002507C: 90100018                 mov     %i0, %o0! unsigned int
F0025080: 7fffb57e                 call    _sleep
F0025084: 92102014                 mov     0x14, %o1
F0025088: d0060000                 ld      [%i0], %o0
F002508C: 808a2002                 btst    2, %o0
F0025090: 02bffffc                 be      loc_F0025080
F0025094: 90100018                 mov     %i0, %o0
F0025098: 4001c723                 call    _splx
F002509C: 90100010                 mov     %l0, %o0
F00250A0: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F00250A4: d00421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o0
F00250A8: d04a2038                 ldsb    [%o0+0x38], %o0
F00250AC: 80a22000                 cmp     %o0, 0
F00250B0: 12800006                 bne     locret_F00250C8
F00250B4: 01000000                 nop
F00250B8: 4000013a                 call    _geterror
F00250BC: 90100018                 mov     %i0, %o0
F00250C0: d20421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o1
F00250C4: d02a6038                 stb     %o0, [%o1+0x38]
F00250C8: 81c7e008                 ret
F00250CC: 81e80000                 restore
