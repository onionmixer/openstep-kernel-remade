F000FA18: 9de3bf98                 save    %sp, -0x68, %sp
F000FA1C: 40021c5b                 call    _splusclock
F000FA20: 01000000                 nop
F000FA24: d2160000                 lduh    [%i0], %o1
F000FA28: 92027fff                 inc     -1, %o1
F000FA2C: d2360000                 sth     %o1, [%i0]
F000FA30: 932a6010                 sll     %o1, 16, %o1
F000FA34: 80a26000                 cmp     %o1, 0
F000FA38: 1280000a                 bne     loc_F000FA60
F000FA3C: a0100008                 mov     %o0, %l0
F000FA40: 90100018                 mov     %i0, %o0
F000FA44: 400161d7                 call    _kfree
F000FA48: 9210202a                 mov     0x2A, %o1 ! '*'
F000FA4C: 153c042c                 sethi   %hi(_cractive), %o2
F000FA50: d202a1c8                 ld      [%o2+%lo(_cractive)], %o1
F000FA54: 90100010                 mov     %l0, %o0
F000FA58: 92027fff                 inc     -1, %o1
F000FA5C: d222a1c8                 st      %o1, [%o2+%lo(_cractive)]
F000FA60: 40021cb1                 call    _splx
F000FA64: 01000000                 nop
F000FA68: 81c7e008                 ret
F000FA6C: 81e80000                 restore
