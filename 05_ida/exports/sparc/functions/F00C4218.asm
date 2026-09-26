F00C4218: 9de3bf90                 save    %sp, -0x70, %sp
F00C421C: b006001a                 add     %i0, %i2, %i0
F00C4220: c40e2010                 ldub    [%i0+0x10], %g2
F00C4224: 80a0a001                 cmp     %g2, 1
F00C4228: 38800003                 bgu,a   locret_F00C4234
F00C422C: b0102001                 mov     1, %i0
F00C4230: b0102000                 mov     0, %i0
F00C4234: 81c7e008                 ret
F00C4238: 81e80000                 restore
