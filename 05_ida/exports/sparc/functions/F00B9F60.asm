F00B9F60: 9de3bf98                 save    %sp, -0x68, %sp
F00B9F64: 86100018                 mov     %i0, %g3
F00B9F68: 8528e003                 sll     %g3, 3, %g2
F00B9F6C: 8088e020                 btst    0x20, %g3 ! ' '
F00B9F70: 02800003                 be      loc_F00B9F7C
F00B9F74: b008a040                 and     %g2, 0x40, %i0
F00B9F78: b0162020                 bset    0x20, %i0 ! ' '
F00B9F7C: 8088e002                 btst    2, %g3
F00B9F80: 32800002                 bne,a   loc_F00B9F88
F00B9F84: b0162004                 bset    4, %i0
F00B9F88: 8088e080                 btst    0x80, %g3
F00B9F8C: 32800002                 bne,a   locret_F00B9F94
F00B9F90: b0162002                 bset    2, %i0
F00B9F94: 81c7e008                 ret
F00B9F98: 81e80000                 restore
