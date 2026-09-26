F008EE2C: 9de3bf98                 save    %sp, -0x68, %sp
F008EE30: 7ffde182                 call    _strlen
F008EE34: 90100018                 mov     %i0, %o0! __dst
F008EE38: 4000dc3e                 call    _IOMalloc
F008EE3C: 90022001                 inc     %o0
F008EE40: 7ffde1ba                 call    _strcpy
F008EE44: 92100018                 mov     %i0, %o1
F008EE48: 81c7e008                 ret
F008EE4C: 91e80008                 restore %g0, %o0, %o0
