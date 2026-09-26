F00CB8EC: 9de3bf90                 save    %sp, -0x70, %sp
F00CB8F0: 7ffd8069                 call    _nb_map
F00CB8F4: 9010001a                 mov     %i2, %o0
F00CB8F8: a0100008                 mov     %o0, %l0
F00CB8FC: 7ffd8077                 call    _nb_size
F00CB900: 9010001a                 mov     %i2, %o0
F00CB904: d20c0000                 ldub    [%l0], %o1
F00CB908: 808a6001                 btst    1, %o1
F00CB90C: 0280001e                 be      locret_F00CB984
F00CB910: a2100008                 mov     %o0, %l1
F00CB914: 90100018                 mov     %i0, %o0! id
F00CB918: 133c0506                 sethi   %hi(paIsunwantedmult), %o1
F00CB91C: d2026058                 ld      [%o1+%lo(paIsunwantedmult)], %o1! SEL
F00CB920: 400097d4                 call    _objc_msgSend
F00CB924: 94100010                 mov     %l0, %o2
F00CB928: 912a2018                 sll     %o0, 24, %o0
F00CB92C: 80a22000                 cmp     %o0, 0
F00CB930: 12800015                 bne     locret_F00CB984
F00CB934: 113c0506                 sethi   %hi(paAllocatenetbuf), %o0! id
F00CB938: d2022080                 ld      [%o0+%lo(paAllocatenetbuf)], %o1! SEL
F00CB93C: 400097cd                 call    _objc_msgSend
F00CB940: 90100018                 mov     %i0, %o0
F00CB944: a0920000                 orcc    %o0, %g0, %l0
F00CB948: 0280000f                 be      locret_F00CB984
F00CB94C: a204600e                 inc     0xE, %l1
F00CB950: 7ffd8051                 call    _nb_map
F00CB954: 9010001a                 mov     %i2, %o0
F00CB958: 96100008                 mov     %o0, %o3
F00CB95C: 90100010                 mov     %l0, %o0
F00CB960: 92102000                 mov     0, %o1
F00CB964: 7ffd8071                 call    _nb_write
F00CB968: 94100011                 mov     %l1, %o2
F00CB96C: 94100010                 mov     %l0, %o2
F00CB970: d006214c                 ld      [%i0+0x14C], %o0! id
F00CB974: 133c0506                 sethi   %hi(paHandleinputpac), %o1
F00CB978: d2026054                 ld      [%o1+%lo(paHandleinputpac)], %o1! SEL
F00CB97C: 400097bd                 call    _objc_msgSend
F00CB980: 96102000                 mov     0, %o3
F00CB984: 81c7e008                 ret
F00CB988: 81e80000                 restore
