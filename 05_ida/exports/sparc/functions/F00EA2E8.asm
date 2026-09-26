F00EA2E8: 9de3bf98                 save    %sp, -0x68, %sp
F00EA2EC: 9410001a                 mov     %i2, %o2
F00EA2F0: 80a6400a                 cmp     %i1, %o2
F00EA2F4: 32800004                 bne,a   loc_F00EA304
F00EA2F8: f04e0000                 ldsb    [%i0], %i0
F00EA2FC: 1080002a                 ba      locret_F00EA3A4
F00EA300: b0102001                 mov     1, %i0
F00EA304: 80a6202a                 cmp     %i0, 0x2A ! '*'
F00EA308: 22800012                 be,a    loc_F00EA350
F00EA30C: 80a66000                 cmp     %i1, 0
F00EA310: 14800007                 bg      loc_F00EA32C
F00EA314: 80a62040                 cmp     %i0, 0x40 ! '@'
F00EA318: 80a62025                 cmp     %i0, 0x25 ! '%'
F00EA31C: 0280000d                 be      loc_F00EA350
F00EA320: 80a66000                 cmp     %i1, 0
F00EA324: 10800020                 ba      locret_F00EA3A4
F00EA328: b0102000                 mov     0, %i0
F00EA32C: 1280001e                 bne     locret_F00EA3A4
F00EA330: b0102000                 mov     0, %i0
F00EA334: 133c0505                 sethi   %hi(paIsequal), %o1! SEL
F00EA338: 90100019                 mov     %i1, %o0! id
F00EA33C: 40001d4d                 call    _objc_msgSend
F00EA340: d2026150                 ld      [%o1+%lo(paIsequal)], %o1
F00EA344: 912a2018                 sll     %o0, 24, %o0
F00EA348: 10800017                 ba      locret_F00EA3A4
F00EA34C: b13a2018                 sra     %o0, 24, %i0
F00EA350: 12800004                 bne     loc_F00EA360
F00EA354: 80a2a000                 cmp     %o2, 0
F00EA358: 10800005                 ba      loc_F00EA36C
F00EA35C: 9010000a                 mov     %o2, %o0
F00EA360: 32800008                 bne,a   loc_F00EA380
F00EA364: d24e4000                 ldsb    [%i1], %o1! __s2
F00EA368: 90100019                 mov     %i1, %o0! __s
F00EA36C: 7ffc7433                 call    _strlen
F00EA370: 01000000                 nop
F00EA374: 80a00008                 cmp     %g0, %o0
F00EA378: 1080000b                 ba      locret_F00EA3A4
F00EA37C: b0603fff                 subc    %g0, -1, %i0
F00EA380: d04a8000                 ldsb    [%o2], %o0
F00EA384: 80a24008                 cmp     %o1, %o0
F00EA388: 12800007                 bne     locret_F00EA3A4
F00EA38C: b0102000                 mov     0, %i0
F00EA390: 90100019                 mov     %i1, %o0! __s1
F00EA394: 7ffc7786                 call    _strcmp
F00EA398: 9210000a                 mov     %o2, %o1
F00EA39C: 80a00008                 cmp     %g0, %o0
F00EA3A0: b0603fff                 subc    %g0, -1, %i0
F00EA3A4: 81c7e008                 ret
F00EA3A8: 81e80000                 restore
