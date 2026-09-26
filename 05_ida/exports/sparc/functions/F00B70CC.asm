F00B70CC: 9de3bf98                 save    %sp, -0x68, %sp
F00B70D0: 912e6010                 sll     %i1, 16, %o0
F00B70D4: 913a200e                 sra     %o0, 14, %o0
F00B70D8: 90020018                 add     %o0, %i0, %o0
F00B70DC: d2062080                 ld      [%i0+0x80], %o1
F00B70E0: e20220b8                 ld      [%o0+0xB8], %l1
F00B70E4: 92026001                 inc     %o1
F00B70E8: d4046018                 ld      [%l1+0x18], %o2
F00B70EC: 80a26000                 cmp     %o1, 0
F00B70F0: d2262080                 st      %o1, [%i0+0x80]
F00B70F4: 932aa005                 sll     %o2, 5, %o1
F00B70F8: 9222400a                 sub     %o1, %o2, %o1
F00B70FC: 912a6006                 sll     %o1, 6, %o0
F00B7100: 90220009                 sub     %o0, %o1, %o0
F00B7104: 912a2003                 sll     %o0, 3, %o0
F00B7108: 9002000a                 add     %o0, %o2, %o0
F00B710C: 0280002f                 be      loc_F00B71C8
F00B7110: a12a2006                 sll     %o0, 6, %l0
F00B7114: 2702aea5                 sethi   0xABA9400, %l3
F00B7118: 293c047a                 sethi   -0xFEE1800, %l4
F00B711C: 253c047a                 sethi   -0xFEE1800, %l2
F00B7120: d00e2041                 ldub    [%i0+0x41], %o0
F00B7124: 80a22000                 cmp     %o0, 0
F00B7128: 02800007                 be      loc_F00B7144
F00B712C: 90100018                 mov     %i0, %o0
F00B7130: 7ffff6ab                 call    _esp_dopoll
F00B7134: 9214e100                 or      %l3, 0x100, %o1
F00B7138: 80a22000                 cmp     %o0, 0
F00B713C: 12800013                 bne     loc_F00B7188
F00B7140: 901522d8                 or      %l4, 0x2D8, %o0
F00B7144: d0062080                 ld      [%i0+0x80], %o0
F00B7148: 80a22000                 cmp     %o0, 0
F00B714C: 0280001f                 be      loc_F00B71C8
F00B7150: 90100018                 mov     %i0, %o0
F00B7154: 932e6010                 sll     %i1, 16, %o1
F00B7158: 7ffff4e7                 call    _esp_ustart
F00B715C: 933a6010                 sra     %o1, 16, %o1
F00B7160: 80a22001                 cmp     %o0, 1
F00B7164: 12800016                 bne     loc_F00B71BC
F00B7168: d0062080                 ld      [%i0+0x80], %o0
F00B716C: 10800011                 ba      loc_F00B71B0
F00B7170: 80a22000                 cmp     %o0, 0
F00B7174: 7ffff69a                 call    _esp_dopoll
F00B7178: 92100010                 mov     %l0, %o1
F00B717C: 80a22000                 cmp     %o0, 0
F00B7180: 02800007                 be      loc_F00B719C
F00B7184: 9014a2f8                 or      %l2, 0x2F8, %o0! char *
F00B7188: 7ffd7534                 call    _printf
F00B718C: 01000000                 nop
F00B7190: 4000019f                 call    _esp_abort_curcmd
F00B7194: 90100018                 mov     %i0, %o0
F00B7198: 30800015                 ba,a    locret_F00B71EC
F00B719C: d00c6029                 ldub    [%l1+0x29], %o0
F00B71A0: 80a22000                 cmp     %o0, 0
F00B71A4: 02800006                 be      loc_F00B71BC
F00B71A8: d0062080                 ld      [%i0+0x80], %o0
F00B71AC: 80a22000                 cmp     %o0, 0
F00B71B0: 12bffff1                 bne     loc_F00B7174
F00B71B4: 90100018                 mov     %i0, %o0
F00B71B8: d0062080                 ld      [%i0+0x80], %o0
F00B71BC: 80a22000                 cmp     %o0, 0
F00B71C0: 32bfffd9                 bne,a   loc_F00B7124
F00B71C4: d00e2041                 ldub    [%i0+0x41], %o0
F00B71C8: d00e2041                 ldub    [%i0+0x41], %o0
F00B71CC: 80a22000                 cmp     %o0, 0
F00B71D0: 12800007                 bne     locret_F00B71EC
F00B71D4: 90100018                 mov     %i0, %o0
F00B71D8: 932e6010                 sll     %i1, 16, %o1
F00B71DC: 933a6010                 sra     %o1, 16, %o1
F00B71E0: 92026001                 inc     %o1
F00B71E4: 7ffff4c4                 call    _esp_ustart
F00B71E8: 920a603f                 and     %o1, 0x3F, %o1
F00B71EC: 81c7e008                 ret
F00B71F0: 81e80000                 restore
