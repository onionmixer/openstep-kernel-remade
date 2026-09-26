F00BDDF8: 9de3bf98                 save    %sp, -0x68, %sp
F00BDDFC: b0102050                 mov     0x50, %i0 ! 'P'
F00BDE00: 353fbff8                 sethi   -0x1002000, %i2
F00BDE04: c40ea016                 ldub    [%i2+0x16], %g2
F00BDE08: 80a0a013                 cmp     %g2, 0x13
F00BDE0C: 1280001b                 bne     loc_F00BDE78
F00BDE10: 86102022                 mov     0x22, %g3 ! '"'
F00BDE14: c40ea050                 ldub    [%i2+0x50], %g2
F00BDE18: 8528a018                 sll     %g2, 24, %g2
F00BDE1C: b138a018                 sra     %g2, 24, %i0
F00BDE20: 852e2010                 sll     %i0, 16, %g2
F00BDE24: 8530a010                 srl     %g2, 16, %g2
F00BDE28: 80a0a009                 cmp     %g2, 9
F00BDE2C: 18800004                 bgu     loc_F00BDE3C
F00BDE30: 80a0a078                 cmp     %g2, 0x78 ! 'x'
F00BDE34: 10800004                 ba      loc_F00BDE44
F00BDE38: b0102050                 mov     0x50, %i0 ! 'P'
F00BDE3C: 38800002                 bgu,a   loc_F00BDE44
F00BDE40: b0102078                 mov     0x78, %i0 ! 'x'
F00BDE44: 053fbff8                 sethi   -0x1002000, %g2
F00BDE48: c408a051                 ldub    [%g2+0x51], %g2
F00BDE4C: 8528a018                 sll     %g2, 24, %g2
F00BDE50: 8738a018                 sra     %g2, 24, %g3
F00BDE54: 8528e010                 sll     %g3, 16, %g2
F00BDE58: 8530a010                 srl     %g2, 16, %g2
F00BDE5C: 80a0a009                 cmp     %g2, 9
F00BDE60: 18800004                 bgu     loc_F00BDE70
F00BDE64: 80a0a030                 cmp     %g2, 0x30 ! '0'
F00BDE68: 10800004                 ba      loc_F00BDE78
F00BDE6C: 86102022                 mov     0x22, %g3 ! '"'
F00BDE70: 38800002                 bgu,a   loc_F00BDE78
F00BDE74: 86102030                 mov     0x30, %g3 ! '0'
F00BDE78: f0366002                 sth     %i0, [%i1+2]
F00BDE7C: c6364000                 sth     %g3, [%i1]
F00BDE80: c0366004                 clrh    [%i1+4]
F00BDE84: c0366006                 clrh    [%i1+6]
F00BDE88: 81c7e008                 ret
F00BDE8C: 81e80000                 restore
