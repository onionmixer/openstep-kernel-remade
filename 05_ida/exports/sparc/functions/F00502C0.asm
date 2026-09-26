F00502C0: 9de3bf98                 save    %sp, -0x68, %sp
F00502C4: d6062038                 ld      [%i0+0x38], %o3
F00502C8: 80a2e002                 cmp     %o3, 2
F00502CC: 22800014                 be,a    loc_F005031C
F00502D0: 973ea002                 sra     %i2, 2, %o3
F00502D4: 14800007                 bg      loc_F00502F0
F00502D8: 80a2e004                 cmp     %o3, 4
F00502DC: 80a2e001                 cmp     %o3, 1
F00502E0: 22800017                 be,a    loc_F005033C
F00502E4: 913ea003                 sra     %i2, 3, %o0
F00502E8: 1080001b                 ba      loc_F0050354
F00502EC: 113c043b                 sethi   -0xFEF1400, %o0
F00502F0: 02800006                 be      loc_F0050308
F00502F4: 80a2e008                 cmp     %o3, 8
F00502F8: 12800017                 bne     loc_F0050354
F00502FC: 113c043b                 sethi   -0xFEF1400, %o0
F0050300: 10800017                 ba      locret_F005035C
F0050304: c02e401a                 clrb    [%i1+%i2]
F0050308: 973ea001                 sra     %i2, 1, %o3
F005030C: 920ea001                 and     %i2, 1, %o1
F0050310: 932a6002                 sll     %o1, 2, %o1
F0050314: 10800005                 ba      loc_F0050328
F0050318: 9010200f                 mov     0xF, %o0
F005031C: 920ea003                 and     %i2, 3, %o1
F0050320: 932a6001                 sll     %o1, 1, %o1
F0050324: 90102003                 mov     3, %o0
F0050328: d40e400b                 ldub    [%i1+%o3], %o2
F005032C: 912a0009                 sll     %o0, %o1, %o0
F0050330: 902a8008                 andn    %o2, %o0, %o0! char *
F0050334: 1080000a                 ba      locret_F005035C
F0050338: d02e400b                 stb     %o0, [%i1+%o3]
F005033C: 920ea007                 and     %i2, 7, %o1
F0050340: d40e4008                 ldub    [%i1+%o0], %o2
F0050344: 932ac009                 sll     %o3, %o1, %o1
F0050348: 922a8009                 andn    %o2, %o1, %o1
F005034C: 10800004                 ba      locret_F005035C
F0050350: d22e4008                 stb     %o1, [%i1+%o0]
F0050354: 7fff1387                 call    _panic
F0050358: 90122180                 bset    0x180, %o0
F005035C: 81c7e008                 ret
F0050360: 81e80000                 restore
