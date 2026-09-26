F00EDFE0: 9de3bf98                 save    %sp, -0x68, %sp
F00EDFE4: 90100018                 mov     %i0, %o0! info
F00EDFE8: d2064000                 ld      [%i1], %o1! data1
F00EDFEC: 7fffffcf                 call    _NXPtrIsEqual
F00EDFF0: d4068000                 ld      [%i2], %o2
F00EDFF4: 81c7e008                 ret
F00EDFF8: 91e80008                 restore %g0, %o0, %o0
