F00AEC1C: 9de3bf98                 save    %sp, -0x68, %sp
F00AEC20: 808e2003                 btst    3, %i0
F00AEC24: 02800004                 be      loc_F00AEC34
F00AEC28: 01000000                 nop
F00AEC2C: 10800013                 ba      locret_F00AEC78
F00AEC30: b0102005                 mov     5, %i0
F00AEC34: 7fff6cf0                 call    _fuword
F00AEC38: 90100018                 mov     %i0, %o0
F00AEC3C: a0100008                 mov     %o0, %l0
F00AEC40: 80a43fff                 cmp     %l0, -1
F00AEC44: 3280000c                 bne,a   loc_F00AEC74
F00AEC48: e0264000                 st      %l0, [%i1]
F00AEC4C: 7fff6cca                 call    _fubyte
F00AEC50: 90100018                 mov     %i0, %o0
F00AEC54: 80a23fff                 cmp     %o0, -1
F00AEC58: 32800007                 bne,a   loc_F00AEC74
F00AEC5C: e0264000                 st      %l0, [%i1]
F00AEC60: f026a020                 st      %i0, [%i2+0x20]
F00AEC64: 90102001                 mov     1, %o0
F00AEC68: d026a028                 st      %o0, [%i2+0x28]
F00AEC6C: 10800003                 ba      locret_F00AEC78
F00AEC70: b0102006                 mov     6, %i0
F00AEC74: b0102000                 mov     0, %i0
F00AEC78: 81c7e008                 ret
F00AEC7C: 81e80000                 restore
