F00D7D78: 9de3bf80                 save    %sp, -0x80, %sp
F00D7D7C: 113c0505                 sethi   %hi(paSamplerate_0), %o0! id
F00D7D80: d20221cc                 ld      [%o0+%lo(paSamplerate_0)], %o1! SEL
F00D7D84: 400066bb                 call    _objc_msgSend
F00D7D88: 90100018                 mov     %i0, %o0
F00D7D8C: d027bfec                 st      %o0, [%fp+var_14]
F00D7D90: 90100018                 mov     %i0, %o0! id
F00D7D94: d4062148                 ld      [%i0+0x148], %o2
F00D7D98: 133c0505                 sethi   %hi(paChannelcount_0), %o1
F00D7D9C: d20261c8                 ld      [%o1+%lo(paChannelcount_0)], %o1! SEL
F00D7DA0: 400066b4                 call    _objc_msgSend
F00D7DA4: d427bfe8                 st      %o2, [%fp+var_18]
F00D7DA8: d027bfe4                 st      %o0, [%fp+var_1C]
F00D7DAC: 113c0505                 sethi   %hi(paEnqueuecount), %o0
F00D7DB0: e00221bc                 ld      [%o0+%lo(paEnqueuecount)], %l0
F00D7DB4: 9010001a                 mov     %i2, %o0! id
F00D7DB8: 400066ae                 call    _objc_msgSend
F00D7DBC: 92100010                 mov     %l0, %o1
F00D7DC0: 80a22000                 cmp     %o0, 0
F00D7DC4: 02800005                 be      loc_F00D7DD8
F00D7DC8: 113c0505                 sethi   %hi(paDequeuedescrip), %o0! id
F00D7DCC: d2022188                 ld      [%o0+%lo(paDequeuedescrip)], %o1! SEL
F00D7DD0: 400066a8                 call    _objc_msgSend
F00D7DD4: 9010001a                 mov     %i2, %o0
F00D7DD8: 9010001a                 mov     %i2, %o0! id
F00D7DDC: 133c0505                 sethi   %hi(paEnqueuedescrip), %o1
F00D7DE0: d20261c0                 ld      [%o1+%lo(paEnqueuedescrip)], %o1! SEL
F00D7DE4: 9407bfec                 add     %fp, var_14, %o2
F00D7DE8: 9607bfe8                 add     %fp, var_18, %o3
F00D7DEC: 400066a1                 call    _objc_msgSend
F00D7DF0: 9807bfe4                 add     %fp, var_1C, %o4
F00D7DF4: 912a2018                 sll     %o0, 24, %o0
F00D7DF8: 80a22000                 cmp     %o0, 0
F00D7DFC: 3280001a                 bne,a   locret_F00D7E64
F00D7E00: b0102000                 mov     0, %i0
F00D7E04: 9010001a                 mov     %i2, %o0! id
F00D7E08: 4000669a                 call    _objc_msgSend
F00D7E0C: 92100010                 mov     %l0, %o1
F00D7E10: 80a22000                 cmp     %o0, 0
F00D7E14: 32800014                 bne,a   locret_F00D7E64
F00D7E18: b0102000                 mov     0, %i0
F00D7E1C: 90100018                 mov     %i0, %o0! id
F00D7E20: 133c0505                 sethi   %hi(paStopdmaforchan_0), %o1
F00D7E24: d20261d8                 ld      [%o1+%lo(paStopdmaforchan_0)], %o1! SEL
F00D7E28: 40006692                 call    _objc_msgSend
F00D7E2C: 9410001a                 mov     %i2, %o2
F00D7E30: 90100018                 mov     %i0, %o0! id
F00D7E34: 133c0505                 sethi   %hi(paSetoutputstart), %o1! SEL
F00D7E38: 94102000                 mov     0, %o2
F00D7E3C: 96102000                 mov     0, %o3
F00D7E40: 4000668c                 call    _objc_msgSend
F00D7E44: d202619c                 ld      [%o1+%lo(paSetoutputstart)], %o1
F00D7E48: 90100018                 mov     %i0, %o0! id
F00D7E4C: 133c0505                 sethi   %hi(paSetlastinterru), %o1! SEL
F00D7E50: 94102000                 mov     0, %o2
F00D7E54: 96102000                 mov     0, %o3
F00D7E58: 40006686                 call    _objc_msgSend
F00D7E5C: d2026200                 ld      [%o1+%lo(paSetlastinterru)], %o1
F00D7E60: b0102001                 mov     1, %i0
F00D7E64: 81c7e008                 ret
F00D7E68: 81e80000                 restore
