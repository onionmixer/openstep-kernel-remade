F00B527C: 9de3bf98                 save    %sp, -0x68, %sp
F00B5280: 94100018                 mov     %i0, %o2
F00B5284: d052a0b2                 ldsh    [%o2+0xB2], %o0
F00B5288: d20aa044                 ldub    [%o2+0x44], %o1
F00B528C: 912a2002                 sll     %o0, 2, %o0
F00B5290: 9002000a                 add     %o0, %o2, %o0
F00B5294: d60220b8                 ld      [%o0+0xB8], %o3
F00B5298: d002a09c                 ld      [%o2+0x9C], %o0
F00B529C: 808a6010                 btst    0x10, %o1
F00B52A0: 1280000b                 bne     loc_F00B52CC
F00B52A4: c02a200c                 clrb    [%o0+0xC]
F00B52A8: 808a6020                 btst    0x20, %o1 ! ' '
F00B52AC: 3280000c                 bne,a   loc_F00B52DC
F00B52B0: d00aa041                 ldub    [%o2+0x41], %o0
F00B52B4: 133c0479                 sethi   %hi(aCmdTransmissio), %o1! "cmd transmission error"
F00B52B8: 9010000a                 mov     %o2, %o0
F00B52BC: 40000a96                 call    _esp_printstate
F00B52C0: 92126160                 bset    %lo(aCmdTransmissio), %o1! "cmd transmission error"
F00B52C4: 1080000a                 ba      locret_F00B52EC
F00B52C8: b0102006                 mov     6, %i0
F00B52CC: d00ae029                 ldub    [%o3+0x29], %o0
F00B52D0: 90122004                 bset    4, %o0
F00B52D4: d02ae029                 stb     %o0, [%o3+0x29]
F00B52D8: d00aa041                 ldub    [%o2+0x41], %o0
F00B52DC: b0102002                 mov     2, %i0
F00B52E0: d02aa042                 stb     %o0, [%o2+0x42]
F00B52E4: 9010201a                 mov     0x1A, %o0
F00B52E8: d02aa041                 stb     %o0, [%o2+0x41]
F00B52EC: 81c7e008                 ret
F00B52F0: 81e80000                 restore
