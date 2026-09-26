F00EE014: 9de3bf98                 save    %sp, -0x68, %sp
F00EE018: 90100018                 mov     %i0, %o0! info
F00EE01C: d2064000                 ld      [%i1], %o1! data1
F00EE020: 7fffffc6                 call    _NXStrIsEqual
F00EE024: d4068000                 ld      [%i2], %o2
F00EE028: 81c7e008                 ret
F00EE02C: 91e80008                 restore %g0, %o0, %o0
