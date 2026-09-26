F006DD7C: 9de3bf98                 save    %sp, -0x68, %sp
F006DD80: a0100018                 mov     %i0, %l0
F006DD84: b2067fff                 inc     -1, %i1
F006DD88: 40009aa8                 call    _miniMonGetchar
F006DD8C: 01000000                 nop
F006DD90: 80a2200a                 cmp     %o0, 0xA
F006DD94: 2280002b                 be,a    locret_F006DE40
F006DD98: c02e0000                 clrb    [%i0]
F006DD9C: 14800006                 bg      loc_F006DDB4
F006DDA0: 80a2200d                 cmp     %o0, 0xD
F006DDA4: 80a22008                 cmp     %o0, 8
F006DDA8: 0280000d                 be      loc_F006DDDC
F006DDAC: 80a66000                 cmp     %i1, 0
F006DDB0: 30800018                 ba,a    loc_F006DE10
F006DDB4: 02800006                 be      loc_F006DDCC
F006DDB8: 80a22015                 cmp     %o0, 0x15
F006DDBC: 22800012                 be,a    loc_F006DE04
F006DDC0: b0100010                 mov     %l0, %i0
F006DDC4: 10800013                 ba      loc_F006DE10
F006DDC8: 80a66000                 cmp     %i1, 0
F006DDCC: 40009ab2                 call    _miniMonPutchar
F006DDD0: 9010200a                 mov     0xA, %o0
F006DDD4: 1080001b                 ba      locret_F006DE40
F006DDD8: c02e0000                 clrb    [%i0]
F006DDDC: 40009aae                 call    _miniMonPutchar
F006DDE0: 90102020                 mov     0x20, %o0 ! ' '
F006DDE4: 80a60010                 cmp     %i0, %l0
F006DDE8: 02bfffe8                 be      loc_F006DD88
F006DDEC: 01000000                 nop
F006DDF0: 40009aa9                 call    _miniMonPutchar
F006DDF4: 90102008                 mov     8, %o0
F006DDF8: b0063fff                 inc     -1, %i0
F006DDFC: 10bfffe3                 ba      loc_F006DD88
F006DE00: b2066001                 inc     %i1
F006DE04: 40009aa4                 call    _miniMonPutchar
F006DE08: 9010200a                 mov     0xA, %o0
F006DE0C: 30bfffdf                 ba,a    loc_F006DD88
F006DE10: 02800005                 be      loc_F006DE24
F006DE14: 01000000                 nop
F006DE18: d02e0000                 stb     %o0, [%i0]
F006DE1C: 10bfffda                 ba      loc_F006DD84
F006DE20: b0062001                 inc     %i0
F006DE24: 40009a9c                 call    _miniMonPutchar
F006DE28: 90102008                 mov     8, %o0
F006DE2C: 40009a9a                 call    _miniMonPutchar
F006DE30: 90102020                 mov     0x20, %o0 ! ' '
F006DE34: 40009a98                 call    _miniMonPutchar
F006DE38: 90102008                 mov     8, %o0
F006DE3C: 30bfffd3                 ba,a    loc_F006DD88
F006DE40: 81c7e008                 ret
F006DE44: 81e80000                 restore
