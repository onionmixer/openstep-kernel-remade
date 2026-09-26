F0075BA4: 9de3bf98                 save    %sp, -0x68, %sp
F0075BA8: 90100018                 mov     %i0, %o0! thread
F0075BAC: 133c04d3                 sethi   %hi(_default_pset), %o1! new_set
F0075BB0: 7ffffffa                 call    _thread_assign
F0075BB4: 921263c0                 bset    %lo(_default_pset), %o1
F0075BB8: 81c7e008                 ret
F0075BBC: 91e80008                 restore %g0, %o0, %o0
