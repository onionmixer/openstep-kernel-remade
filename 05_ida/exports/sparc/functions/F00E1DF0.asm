F00E1DF0: 9de3bf98                 save    %sp, -0x68, %sp
F00E1DF4: 9210001b                 mov     %i3, %o1
F00E1DF8: 80a26001                 cmp     %o1, 1
F00E1DFC: 02800035                 be      loc_F00E1ED0
F00E1E00: b536a001                 srl     %i2, 1, %i2
F00E1E04: 80a26001                 cmp     %o1, 1
F00E1E08: 14800007                 bg      loc_F00E1E24
F00E1E0C: 80a26003                 cmp     %o1, 3
F00E1E10: 80a26000                 cmp     %o1, 0
F00E1E14: 02800008                 be      loc_F00E1E34
F00E1E18: b536a001                 srl     %i2, 1, %i2
F00E1E1C: 10800048                 ba      loc_F00E1F3C
F00E1E20: 113c03f2                 sethi   -0xFF03800, %o0
F00E1E24: 02800018                 be      loc_F00E1E84
F00E1E28: b406bfff                 inc     -1, %i2
F00E1E2C: 10800044                 ba      loc_F00E1F3C
F00E1E30: 113c03f2                 sethi   -0xFF03800, %o0
F00E1E34: b406bfff                 inc     -1, %i2
F00E1E38: 80a6bfff                 cmp     %i2, -1
F00E1E3C: 02800042                 be      locret_F00E1F44
F00E1E40: 01000000                 nop
F00E1E44: d2560000                 ldsh    [%i0], %o1
F00E1E48: b406bfff                 inc     -1, %i2
F00E1E4C: b0062002                 inc     2, %i0
F00E1E50: d0560000                 ldsh    [%i0], %o0
F00E1E54: 80a6bfff                 cmp     %i2, -1
F00E1E58: 92024008                 add     %o1, %o0, %o1
F00E1E5C: b0062002                 inc     2, %i0
F00E1E60: 900a6001                 and     %o1, 1, %o0
F00E1E64: 92024008                 add     %o1, %o0, %o1
F00E1E68: 9132601f                 srl     %o1, 31, %o0
F00E1E6C: 90024008                 add     %o1, %o0, %o0
F00E1E70: 91322001                 srl     %o0, 1, %o0
F00E1E74: d0364000                 sth     %o0, [%i1]
F00E1E78: 12bffff3                 bne     loc_F00E1E44
F00E1E7C: b2066002                 inc     2, %i1
F00E1E80: 30800031                 ba,a    locret_F00E1F44
F00E1E84: 80a6bfff                 cmp     %i2, -1
F00E1E88: 0280002f                 be      locret_F00E1F44
F00E1E8C: 01000000                 nop
F00E1E90: d24e0000                 ldsb    [%i0], %o1
F00E1E94: b406bfff                 inc     -1, %i2
F00E1E98: b0062001                 inc     %i0
F00E1E9C: d04e0000                 ldsb    [%i0], %o0
F00E1EA0: 80a6bfff                 cmp     %i2, -1
F00E1EA4: 92024008                 add     %o1, %o0, %o1
F00E1EA8: b0062001                 inc     %i0
F00E1EAC: 900a6001                 and     %o1, 1, %o0
F00E1EB0: 92024008                 add     %o1, %o0, %o1
F00E1EB4: 9132601f                 srl     %o1, 31, %o0
F00E1EB8: 90024008                 add     %o1, %o0, %o0
F00E1EBC: 91322001                 srl     %o0, 1, %o0
F00E1EC0: d02e4000                 stb     %o0, [%i1]
F00E1EC4: 12bffff3                 bne     loc_F00E1E90
F00E1EC8: b2066001                 inc     %i1
F00E1ECC: 3080001e                 ba,a    locret_F00E1F44
F00E1ED0: b406bfff                 inc     -1, %i2
F00E1ED4: 80a6bfff                 cmp     %i2, -1
F00E1ED8: 0280001b                 be      locret_F00E1F44
F00E1EDC: 113c03e5                 sethi   %hi(_audio_muLaw), %o0
F00E1EE0: b61223c4                 or      %o0, %lo(_audio_muLaw), %i3
F00E1EE4: d20e0000                 ldub    [%i0], %o1
F00E1EE8: b406bfff                 inc     -1, %i2
F00E1EEC: b0062001                 inc     %i0
F00E1EF0: d00e0000                 ldub    [%i0], %o0
F00E1EF4: 932a6001                 sll     %o1, 1, %o1
F00E1EF8: d252401b                 ldsh    [%o1+%i3], %o1
F00E1EFC: 912a2001                 sll     %o0, 1, %o0
F00E1F00: d052001b                 ldsh    [%o0+%i3], %o0
F00E1F04: b0062001                 inc     %i0
F00E1F08: 92024008                 add     %o1, %o0, %o1
F00E1F0C: 900a6001                 and     %o1, 1, %o0
F00E1F10: 92024008                 add     %o1, %o0, %o1
F00E1F14: 9132601f                 srl     %o1, 31, %o0
F00E1F18: 90024008                 add     %o1, %o0, %o0
F00E1F1C: 912a200f                 sll     %o0, 15, %o0
F00E1F20: 40000238                 call    _audio_shortToMulaw
F00E1F24: 913a2010                 sra     %o0, 16, %o0
F00E1F28: d02e4000                 stb     %o0, [%i1]
F00E1F2C: 80a6bfff                 cmp     %i2, -1
F00E1F30: 12bfffed                 bne     loc_F00E1EE4
F00E1F34: b2066001                 inc     %i1
F00E1F38: 30800003                 ba,a    locret_F00E1F44
F00E1F3C: 7fff906e                 call    _IOLog
F00E1F40: 90122238                 bset    0x238, %o0
F00E1F44: 81c7e008                 ret
F00E1F48: 81e80000                 restore
