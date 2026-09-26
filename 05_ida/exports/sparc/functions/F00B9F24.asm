F00B9F24: 9de3bf98                 save    %sp, -0x68, %sp
F00B9F28: 86100018                 mov     %i0, %g3
F00B9F2C: 8530e003                 srl     %g3, 3, %g2
F00B9F30: 8088e020                 btst    0x20, %g3 ! ' '
F00B9F34: 02800003                 be      loc_F00B9F40
F00B9F38: b008a008                 and     %g2, 8, %i0
F00B9F3C: b0162020                 bset    0x20, %i0 ! ' '
F00B9F40: 8088e004                 btst    4, %g3
F00B9F44: 32800002                 bne,a   loc_F00B9F4C
F00B9F48: b0162002                 bset    2, %i0
F00B9F4C: 8088e002                 btst    2, %g3
F00B9F50: 32800002                 bne,a   locret_F00B9F58
F00B9F54: b0162080                 bset    0x80, %i0
F00B9F58: 81c7e008                 ret
F00B9F5C: 81e80000                 restore
