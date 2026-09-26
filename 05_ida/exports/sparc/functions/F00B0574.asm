F00B0574: 9de3bf98                 save    %sp, -0x68, %sp
F00B0578: c44e0000                 ldsb    [%i0], %g2
F00B057C: b4102000                 mov     0, %i2
F00B0580: 80a0a000                 cmp     %g2, 0
F00B0584: 02800020                 be      locret_F00B0604
F00B0588: f20e0000                 ldub    [%i0], %i1
F00B058C: 84067fd0                 add     %i1, -0x30, %g2
F00B0590: 8408a0ff                 and     %g2, 0xFF, %g2
F00B0594: 80a0a009                 cmp     %g2, 9
F00B0598: 18800005                 bgu     loc_F00B05AC
F00B059C: 852e6018                 sll     %i1, 24, %g2
F00B05A0: 8538a018                 sra     %g2, 24, %g2
F00B05A4: 10800011                 ba      loc_F00B05E8
F00B05A8: b200bfd0                 add     %g2, -0x30, %i1
F00B05AC: 84067f9f                 add     %i1, -0x61, %g2
F00B05B0: 8408a0ff                 and     %g2, 0xFF, %g2
F00B05B4: 80a0a005                 cmp     %g2, 5
F00B05B8: 18800005                 bgu     loc_F00B05CC
F00B05BC: 852e6018                 sll     %i1, 24, %g2
F00B05C0: 8538a018                 sra     %g2, 24, %g2
F00B05C4: 10800009                 ba      loc_F00B05E8
F00B05C8: b200bfa9                 add     %g2, -0x57, %i1
F00B05CC: 84067fbf                 add     %i1, -0x41, %g2
F00B05D0: 8408a0ff                 and     %g2, 0xFF, %g2
F00B05D4: 80a0a005                 cmp     %g2, 5
F00B05D8: 1880000b                 bgu     locret_F00B0604
F00B05DC: 852e6018                 sll     %i1, 24, %g2
F00B05E0: 8538a018                 sra     %g2, 24, %g2
F00B05E4: b200bfc9                 add     %g2, -0x37, %i1
F00B05E8: b0062001                 inc     %i0
F00B05EC: 852ea004                 sll     %i2, 4, %g2
F00B05F0: c64e0000                 ldsb    [%i0], %g3
F00B05F4: b4008019                 add     %g2, %i1, %i2
F00B05F8: 80a0e000                 cmp     %g3, 0
F00B05FC: 12bfffe4                 bne     loc_F00B058C
F00B0600: f20e0000                 ldub    [%i0], %i1
F00B0604: 81c7e008                 ret
F00B0608: 91e8001a                 restore %g0, %i2, %o0
