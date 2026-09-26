F00B8114: 9de3bf90                 save    %sp, -0x70, %sp
F00B8118: 153c04fc                 sethi   %hi(_scsi_spl), %o2
F00B811C: d002a0c0                 ld      [%o2+%lo(_scsi_spl)], %o0
F00B8120: d2060000                 ld      [%i0], %o1
F00B8124: 80a20009                 cmp     %o0, %o1
F00B8128: 26800002                 bl,a    loc_F00B8130
F00B812C: 90100009                 mov     %o1, %o0
F00B8130: 400001cd                 call    _scsi_rinit
F00B8134: d022a0c0                 st      %o0, [%o2+0xC0]
F00B8138: 113c0474                 sethi   %hi(_scsi_conf), %o0
F00B813C: d20222f8                 ld      [%o0+%lo(_scsi_conf)], %o1
F00B8140: 80a26000                 cmp     %o1, 0
F00B8144: 0280003e                 be      locret_F00B823C
F00B8148: a21222f8                 or      %o0, %lo(_scsi_conf), %l1
F00B814C: 113c04fca61220d0         set     _scsibuscookies, %l3
F00B8154: 113c04fca8122110         set     _scsibusctlrs, %l4
F00B815C: 253c04fc                 sethi   -0xFEC1000, %l2
F00B8160: a0046012                 add     %l1, 0x12, %l0
F00B8164: d2044000                 ld      [%l1], %o1! __s2
F00B8168: d0066020                 ld      [%i1+0x20], %o0
F00B816C: 80a24008                 cmp     %o1, %o0
F00B8170: 3280002f                 bne,a   loc_F00B822C
F00B8174: a2046018                 inc     0x18, %l1
F00B8178: d006600c                 ld      [%i1+0xC], %o0! __s1
F00B817C: 7ffd400c                 call    _strcmp
F00B8180: d2043ffa                 ld      [%l0-6], %o1
F00B8184: 80a22000                 cmp     %o0, 0
F00B8188: 32800029                 bne,a   loc_F00B822C
F00B818C: a2046018                 inc     0x18, %l1
F00B8190: d04c3ffe                 ldsb    [%l0-2], %o0
F00B8194: d406602c                 ld      [%i1+0x2C], %o2
F00B8198: 80a28008                 cmp     %o2, %o0
F00B819C: 32800024                 bne,a   loc_F00B822C
F00B81A0: a2046018                 inc     0x18, %l1
F00B81A4: d20c2002                 ldub    [%l0+2], %o1
F00B81A8: 900a60ff                 and     %o1, 0xFF, %o0
F00B81AC: 80a2200f                 cmp     %o0, 0xF
F00B81B0: 18800008                 bgu     loc_F00B81D0
F00B81B4: 912a2002                 sll     %o0, 2, %o0
F00B81B8: d0020013                 ld      [%o0+%l3], %o0
F00B81BC: 80a22000                 cmp     %o0, 0
F00B81C0: 02800009                 be      loc_F00B81E4
F00B81C4: 80a20018                 cmp     %o0, %i0
F00B81C8: 02800008                 be      loc_F00B81E8
F00B81CC: 912a6002                 sll     %o1, 2, %o0
F00B81D0: 113c047c                 sethi   %hi(aSDIllegalScsiB), %o0! "%s%d: illegal SCSI bus\n"
F00B81D4: d206600c                 ld      [%i1+0xC], %o1
F00B81D8: 7ffd7120                 call    _printf
F00B81DC: 90122160                 bset    %lo(aSDIllegalScsiB), %o0! "%s%d: illegal SCSI bus\n"
F00B81E0: 30800017                 ba,a    locret_F00B823C
F00B81E4: 912a6002                 sll     %o1, 2, %o0
F00B81E8: f0220013                 st      %i0, [%o0+%l3]
F00B81EC: f2220014                 st      %i1, [%o0+%l4]
F00B81F0: d4043ff2                 ld      [%l0-0xE], %o2
F00B81F4: d6043ff6                 ld      [%l0-0xA], %o3
F00B81F8: d84c2001                 ldsb    [%l0+1], %o4
F00B81FC: da4c3fff                 ldsb    [%l0-1], %o5
F00B8200: 90100018                 mov     %i0, %o0
F00B8204: c44c0000                 ldsb    [%l0], %g2
F00B8208: 92100019                 mov     %i1, %o1
F00B820C: 4000000e                 call    sub_F00B8244
F00B8210: c423a05c                 st      %g2, [%sp+0x70+var_14]
F00B8214: 80a22000                 cmp     %o0, 0
F00B8218: 02800005                 be      loc_F00B822C
F00B821C: a2046018                 inc     0x18, %l1
F00B8220: d004a0a0                 ld      [%l2+0xA0], %o0
F00B8224: 90022001                 inc     %o0
F00B8228: d024a0a0                 st      %o0, [%l2+0xA0]
F00B822C: d0044000                 ld      [%l1], %o0
F00B8230: 80a22000                 cmp     %o0, 0
F00B8234: 12bfffcc                 bne     loc_F00B8164
F00B8238: a0042018                 inc     0x18, %l0
F00B823C: 81c7e008                 ret
F00B8240: 81e80000                 restore
