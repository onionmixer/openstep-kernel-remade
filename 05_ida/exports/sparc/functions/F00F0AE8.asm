F00F0AE8: f00ef09c                 ldub    [%i3-0xF64], %i0
F00F0AEC: f00ef13c                 ldub    [%i3-0xEC4], %i0
F00F0AF0: f00ef16c                 ldub    [%i3-0xE94], %i0
F00F0AF4: 00000000                 illtrap
F00F0AF8: 9de3bf98                 save    %sp, -0x68, %sp
F00F0AFC: 90100019                 mov     %i1, %o0! __ptr
F00F0B00: 7ffddde1                 call    _realloc
F00F0B04: 9210001a                 mov     %i2, %o1
F00F0B08: 81c7e008                 ret
F00F0B0C: 91e80008                 restore %g0, %o0, %o0
