F00B40D0: 9de3bf28                 save    %sp, -0xD8, %sp
F00B40D4: e2060000                 ld      [%i0], %l1
F00B40D8: d0044000                 ld      [%l1], %o0
F00B40DC: 7fff8b0a                 call    _splr
F00B40E0: a4102000                 mov     0, %l2
F00B40E4: 80a66000                 cmp     %i1, 0
F00B40E8: 12800014                 bne     loc_F00B4138
F00B40EC: a6100008                 mov     %o0, %l3
F00B40F0: 40000c41                 call    _esp_reset_bus
F00B40F4: 90100011                 mov     %l1, %o0
F00B40F8: 90100011                 mov     %l1, %o0
F00B40FC: d4046080                 ld      [%l1+0x80], %o2
F00B4100: 1302aea592126100         set     0xABA9500, %o1
F00B4108: 9402a001                 inc     %o2
F00B410C: 400002b4                 call    _esp_dopoll
F00B4110: d4246080                 st      %o2, [%l1+0x80]
F00B4114: 80a22000                 cmp     %o0, 0
F00B4118: 0280002d                 be      loc_F00B41CC
F00B411C: 90100011                 mov     %l1, %o0
F00B4120: 92102003                 mov     3, %o1
F00B4124: 153c0479                 sethi   %hi(aResetScsiBusFa), %o2! "reset scsi bus failed"
F00B4128: 40000eb1                 call    _esplog
F00B412C: 9412a010                 bset    %lo(aResetScsiBusFa), %o2! "reset scsi bus failed"
F00B4130: 10800031                 ba      loc_F00B41F4
F00B4134: d00c6041                 ldub    [%l1+0x41], %o0
F00B4138: d00c6041                 ldub    [%l1+0x41], %o0
F00B413C: d2162004                 lduh    [%i0+4], %o1
F00B4140: 80a22000                 cmp     %o0, 0
F00B4144: d00e2006                 ldub    [%i0+6], %o0
F00B4148: 932a6003                 sll     %o1, 3, %o1
F00B414C: 90120009                 bset    %o1, %o0
F00B4150: 12800028                 bne     loc_F00B41F0
F00B4154: b2100008                 mov     %o0, %i1
F00B4158: 912a2010                 sll     %o0, 16, %o0
F00B415C: 913a200e                 sra     %o0, 14, %o0
F00B4160: 90020011                 add     %o0, %l1, %o0
F00B4164: d00220b8                 ld      [%o0+0xB8], %o0
F00B4168: 80a22000                 cmp     %o0, 0
F00B416C: 32800022                 bne,a   loc_F00B41F4
F00B4170: d00c6041                 ldub    [%l1+0x41], %o0
F00B4174: d0046080                 ld      [%l1+0x80], %o0
F00B4178: 80a22000                 cmp     %o0, 0
F00B417C: 3280001e                 bne,a   loc_F00B41F4
F00B4180: d00c6041                 ldub    [%l1+0x41], %o0
F00B4184: a007bf88                 add     %fp, var_78, %l0
F00B4188: 90100010                 mov     %l0, %o0
F00B418C: 92100018                 mov     %i0, %o1
F00B4190: 40000c96                 call    _esp_makeproxy_cmd
F00B4194: 9410200c                 mov     0xC, %o2
F00B4198: 7fffff09                 call    _esp_start
F00B419C: 90100010                 mov     %l0, %o0
F00B41A0: 80a22001                 cmp     %o0, 1
F00B41A4: 1280000c                 bne     loc_F00B41D4
F00B41A8: 912e6010                 sll     %i1, 16, %o0
F00B41AC: d00fbfb0                 ldub    [%fp+var_50], %o0
F00B41B0: 80a22000                 cmp     %o0, 0
F00B41B4: 12800008                 bne     loc_F00B41D4
F00B41B8: 912e6010                 sll     %i1, 16, %o0
F00B41BC: d00fbff3                 ldub    [%fp+var_D], %o0
F00B41C0: 80a22001                 cmp     %o0, 1
F00B41C4: 12800004                 bne     loc_F00B41D4
F00B41C8: 912e6010                 sll     %i1, 16, %o0
F00B41CC: 10800009                 ba      loc_F00B41F0
F00B41D0: a4102001                 mov     1, %l2
F00B41D4: 913a200e                 sra     %o0, 14, %o0
F00B41D8: 94020011                 add     %o0, %l1, %o2
F00B41DC: d202a0b8                 ld      [%o2+0xB8], %o1
F00B41E0: 9007bf88                 add     %fp, var_78, %o0
F00B41E4: 80a24008                 cmp     %o1, %o0
F00B41E8: 22800002                 be,a    loc_F00B41F0
F00B41EC: c022a0b8                 clr     [%o2+0xB8]
F00B41F0: d00c6041                 ldub    [%l1+0x41], %o0
F00B41F4: 80a22000                 cmp     %o0, 0
F00B41F8: 12800004                 bne     loc_F00B4208
F00B41FC: 90100011                 mov     %l1, %o0
F00B4200: 400000bd                 call    _esp_ustart
F00B4204: 92102000                 mov     0, %o1
F00B4208: 7fff8ac7                 call    _splx
F00B420C: 90100013                 mov     %l3, %o0
F00B4210: 81c7e008                 ret
F00B4214: 91e80012                 restore %g0, %l2, %o0
