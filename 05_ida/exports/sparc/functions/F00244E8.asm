F00244E8: 9de3bf98                 save    %sp, -0x68, %sp
F00244EC: 80a66000                 cmp     %i1, 0
F00244F0: 0680000a                 bl      locret_F0024518
F00244F4: b4100018                 mov     %i0, %i2
F00244F8: b13e6003                 sra     %i1, 3, %i0
F00244FC: 872e2003                 sll     %i0, 3, %g3
F0024500: 86264003                 sub     %i1, %g3, %g3
F0024504: 84102001                 mov     1, %g2
F0024508: f20e8018                 ldub    [%i2+%i0], %i1
F002450C: 85288003                 sll     %g2, %g3, %g2
F0024510: 842e4002                 andn    %i1, %g2, %g2
F0024514: c42e8018                 stb     %g2, [%i2+%i0]
F0024518: 81c7e008                 ret
F002451C: 81e80000                 restore
