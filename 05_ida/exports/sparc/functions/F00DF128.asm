F00DF128: 9de3bf98                 save    %sp, -0x68, %sp
F00DF12C: 80a62000                 cmp     %i0, 0
F00DF130: 12800004                 bne     loc_F00DF140
F00DF134: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DF138: 10800013                 ba      locret_F00DF184
F00DF13C: b01020ca                 mov     0xCA, %i0
F00DF140: d2022058                 ld      [%o0+0x58], %o1! SEL
F00DF144: 400049cb                 call    _objc_msgSend
F00DF148: 90100018                 mov     %i0, %o0! id
F00DF14C: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DF150: 400049c8                 call    _objc_msgSend
F00DF154: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DF158: 133c0504                 sethi   %hi(paSetparametersT), %o1
F00DF15C: 94100019                 mov     %i1, %o2
F00DF160: 9610001b                 mov     %i3, %o3
F00DF164: 9810001a                 mov     %i2, %o4
F00DF168: d20263fc                 ld      [%o1+%lo(paSetparametersT)], %o1! SEL
F00DF16C: 400049c1                 call    _objc_msgSend
F00DF170: 9a100018                 mov     %i0, %o5
F00DF174: 912a2018                 sll     %o0, 24, %o0
F00DF178: 80a00008                 cmp     %g0, %o0
F00DF17C: b0403fff                 addc    %g0, -1, %i0
F00DF180: b00e20d2                 and     %i0, 0xD2, %i0
F00DF184: 81c7e008                 ret
F00DF188: 81e80000                 restore
