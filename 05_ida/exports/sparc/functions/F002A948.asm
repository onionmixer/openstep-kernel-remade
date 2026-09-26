F002A948: 9de3bf98                 save    %sp, -0x68, %sp
F002A94C: c6064000                 ld      [%i1], %g3
F002A950: c4068000                 ld      [%i2], %g2
F002A954: 80a0c002                 cmp     %g3, %g2
F002A958: 12800007                 bne     locret_F002A974
F002A95C: b0102000                 mov     0, %i0
F002A960: c4166004                 lduh    [%i1+4], %g2
F002A964: c616a004                 lduh    [%i2+4], %g3
F002A968: 84188003                 btog    %g3, %g2
F002A96C: 80a00002                 cmp     %g0, %g2
F002A970: b0603fff                 subc    %g0, -1, %i0
F002A974: 81c7e008                 ret
F002A978: 81e80000                 restore
