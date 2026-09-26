F00DE114: 9de3bf98                 save    %sp, -0x68, %sp
F00DE118: 80a62000                 cmp     %i0, 0
F00DE11C: 12800004                 bne     loc_F00DE12C
F00DE120: 94100019                 mov     %i1, %o2
F00DE124: 10800020                 ba      locret_F00DE1A4
F00DE128: b01020ca                 mov     0xCA, %i0
F00DE12C: 133c0505                 sethi   %hi(paCheckowner), %o1
F00DE130: d2026018                 ld      [%o1+%lo(paCheckowner)], %o1! SEL
F00DE134: 40004dcf                 call    _objc_msgSend
F00DE138: 90100018                 mov     %i0, %o0
F00DE13C: 912a2018                 sll     %o0, 24, %o0
F00DE140: 80a22000                 cmp     %o0, 0
F00DE144: 02800017                 be      loc_F00DE1A0
F00DE148: 113c0505                 sethi   %hi(paAudiodevice), %o0
F00DE14C: e2022224                 ld      [%o0+%lo(paAudiodevice)], %l1
F00DE150: 90100018                 mov     %i0, %o0! id
F00DE154: 40004dc7                 call    _objc_msgSend
F00DE158: 92100011                 mov     %l1, %o1
F00DE15C: 94102000                 mov     0, %o2
F00DE160: 9610001a                 mov     %i2, %o3
F00DE164: 133c0505                 sethi   %hi(paSetparameterTo), %o1! SEL
F00DE168: e00260fc                 ld      [%o1+%lo(paSetparameterTo)], %l0
F00DE16C: 98100018                 mov     %i0, %o4
F00DE170: 40004dc0                 call    _objc_msgSend
F00DE174: 92100010                 mov     %l0, %o1! SEL
F00DE178: 90100018                 mov     %i0, %o0! id
F00DE17C: 40004dbd                 call    _objc_msgSend
F00DE180: 92100011                 mov     %l1, %o1
F00DE184: 92100010                 mov     %l0, %o1! SEL
F00DE188: 94102001                 mov     1, %o2
F00DE18C: 9610001b                 mov     %i3, %o3
F00DE190: 40004db8                 call    _objc_msgSend
F00DE194: 98100018                 mov     %i0, %o4
F00DE198: 10800003                 ba      locret_F00DE1A4
F00DE19C: b0102000                 mov     0, %i0
F00DE1A0: b01020c8                 mov     0xC8, %i0
F00DE1A4: 81c7e008                 ret
F00DE1A8: 81e80000                 restore
