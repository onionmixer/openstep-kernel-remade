F00B4984: 9de3bf98                 save    %sp, -0x68, %sp
F00B4988: 94100018                 mov     %i0, %o2
F00B498C: d002a094                 ld      [%o2+0x94], %o0
F00B4990: d20aa043                 ldub    [%o2+0x43], %o1
F00B4994: 90022001                 inc     %o0
F00B4998: 920a6007                 and     %o1, 7, %o1
F00B499C: 80a26002                 cmp     %o1, 2
F00B49A0: 02800006                 be      loc_F00B49B8
F00B49A4: d022a094                 st      %o0, [%o2+0x94]
F00B49A8: d002a09c                 ld      [%o2+0x9C], %o0
F00B49AC: d00a2010                 ldub    [%o0+0x10], %o0
F00B49B0: 900a207f                 and     %o0, 0x7F, %o0
F00B49B4: d02aa043                 stb     %o0, [%o2+0x43]
F00B49B8: d00aa043                 ldub    [%o2+0x43], %o0
F00B49BC: 900a2007                 and     %o0, 7, %o0
F00B49C0: 80a22002                 cmp     %o0, 2
F00B49C4: 12800008                 bne     loc_F00B49E4
F00B49C8: 133c0479                 sethi   -0xFEE1C00, %o1
F00B49CC: d00aa041                 ldub    [%o2+0x41], %o0
F00B49D0: b0102002                 mov     2, %i0
F00B49D4: d02aa042                 stb     %o0, [%o2+0x42]
F00B49D8: 90102001                 mov     1, %o0
F00B49DC: 10800006                 ba      locret_F00B49F4
F00B49E0: d02aa041                 stb     %o0, [%o2+0x41]
F00B49E4: 9010000a                 mov     %o2, %o0
F00B49E8: 40000ccb                 call    _esp_printstate
F00B49EC: 92126028                 bset    0x28, %o1 ! '('
F00B49F0: b0102006                 mov     6, %i0
F00B49F4: 81c7e008                 ret
F00B49F8: 81e80000                 restore
