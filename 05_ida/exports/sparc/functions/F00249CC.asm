F00249CC: 9de3bf98                 save    %sp, -0x68, %sp
F00249D0: 80a66000                 cmp     %i1, 0
F00249D4: 16800003                 bge     loc_F00249E0
F00249D8: 84100019                 mov     %i1, %g2
F00249DC: 84066007                 add     %i1, 7, %g2
F00249E0: 8538a003                 sra     %g2, 3, %g2
F00249E4: 84060002                 add     %i0, %g2, %g2
F00249E8: 8408a00f                 and     %g2, 0xF, %g2
F00249EC: 8728a001                 sll     %g2, 1, %g3
F00249F0: 8600c002                 add     %g3, %g2, %g3
F00249F4: 8728e002                 sll     %g3, 2, %g3
F00249F8: 053c04cf8410a300         set     _bufhash, %g2
F0024A00: 8600c002                 add     %g3, %g2, %g3
F0024A04: f400e004                 ld      [%g3+4], %i2
F0024A08: 80a68003                 cmp     %i2, %g3
F0024A0C: 22800015                 be,a    locret_F0024A60
F0024A10: b0102000                 mov     0, %i0
F0024A14: 37000040                 sethi   0x10000, %i3
F0024A18: c406a024                 ld      [%i2+0x24], %g2
F0024A1C: 80a08019                 cmp     %g2, %i1
F0024A20: 3280000c                 bne,a   loc_F0024A50
F0024A24: f406a004                 ld      [%i2+4], %i2
F0024A28: c406a040                 ld      [%i2+0x40], %g2
F0024A2C: 80a08018                 cmp     %g2, %i0
F0024A30: 32800008                 bne,a   loc_F0024A50
F0024A34: f406a004                 ld      [%i2+4], %i2
F0024A38: c4068000                 ld      [%i2], %g2
F0024A3C: 8088801b                 btst    %i3, %g2
F0024A40: 32800004                 bne,a   loc_F0024A50
F0024A44: f406a004                 ld      [%i2+4], %i2
F0024A48: 10800006                 ba      locret_F0024A60
F0024A4C: b0102001                 mov     1, %i0
F0024A50: 80a68003                 cmp     %i2, %g3
F0024A54: 32bffff2                 bne,a   loc_F0024A1C
F0024A58: c406a024                 ld      [%i2+0x24], %g2
F0024A5C: b0102000                 mov     0, %i0
F0024A60: 81c7e008                 ret
F0024A64: 81e80000                 restore
