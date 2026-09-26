F00EC28C: 9de3bf98                 save    %sp, -0x68, %sp
F00EC290: 80a62000                 cmp     %i0, 0
F00EC294: 02800007                 be      locret_F00EC2B0
F00EC298: 01000000                 nop
F00EC29C: 40000fe7                 call    __objc_getFreedObjectClass
F00EC2A0: 01000000                 nop
F00EC2A4: d0260000                 st      %o0, [%i0]
F00EC2A8: 7ffdf016                 call    _free
F00EC2AC: 90100018                 mov     %i0, %o0
F00EC2B0: 81c7e008                 ret
F00EC2B4: 91e82000                 restore %g0, 0, %o0
