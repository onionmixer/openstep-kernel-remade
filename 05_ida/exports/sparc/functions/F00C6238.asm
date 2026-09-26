F00C6238: 9de3bf98                 save    %sp, -0x68, %sp
F00C623C: 80a62000                 cmp     %i0, 0
F00C6240: 02800005                 be      locret_F00C6254
F00C6244: 84102001                 mov     1, %g2
F00C6248: b0863fff                 inccc   -1, %i0
F00C624C: 12bfffff                 bne     loc_F00C6248
F00C6250: 8528a001                 sll     %g2, 1, %g2
F00C6254: 81c7e008                 ret
F00C6258: 91e80002                 restore %g0, %g2, %o0
