F00EB3C0: 9de3bf90                 save    %sp, -0x70, %sp
F00EB3C4: 94968000                 orcc    %i2, %g0, %o2
F00EB3C8: 32800004                 bne,a   loc_F00EB3D8
F00EB3CC: d2062004                 ld      [%i0+4], %o1
F00EB3D0: 10800015                 ba      locret_F00EB424
F00EB3D4: b0102000                 mov     0, %i0
F00EB3D8: d0062008                 ld      [%i0+8], %o0
F00EB3DC: 912a2002                 sll     %o0, 2, %o0
F00EB3E0: 96020009                 add     %o0, %o1, %o3
F00EB3E4: 80a2400b                 cmp     %o1, %o3
F00EB3E8: 3a80000a                 bcc,a   loc_F00EB410
F00EB3EC: 133c0506                 sethi   -0xFEBE800, %o1
F00EB3F0: d0024000                 ld      [%o1], %o0
F00EB3F4: 80a2000a                 cmp     %o0, %o2
F00EB3F8: 0280000b                 be      locret_F00EB424
F00EB3FC: 92026004                 inc     4, %o1
F00EB400: 80a2400b                 cmp     %o1, %o3
F00EB404: 2abffffc                 bcs,a   loc_F00EB3F4
F00EB408: d0024000                 ld      [%o1], %o0
F00EB40C: 133c0506                 sethi   -0xFEBE800, %o1
F00EB410: 90100018                 mov     %i0, %o0! id
F00EB414: d2026234                 ld      [%o1+0x234], %o1! SEL
F00EB418: 40001916                 call    _objc_msgSend
F00EB41C: d6062008                 ld      [%i0+8], %o3
F00EB420: b0100008                 mov     %o0, %i0
F00EB424: 81c7e008                 ret
F00EB428: 81e80000                 restore
