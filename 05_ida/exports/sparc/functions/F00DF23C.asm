F00DF23C: 9de3bf98                 save    %sp, -0x68, %sp
F00DF240: 80a62000                 cmp     %i0, 0
F00DF244: 12800004                 bne     loc_F00DF254
F00DF248: c026c000                 clr     [%i3]
F00DF24C: 10800014                 ba      locret_F00DF29C
F00DF250: b01020ca                 mov     0xCA, %i0
F00DF254: 113c0505                 sethi   %hi(paChannel), %o0! id
F00DF258: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DF25C: 40004985                 call    _objc_msgSend
F00DF260: 90100018                 mov     %i0, %o0! id
F00DF264: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DF268: 40004982                 call    _objc_msgSend
F00DF26C: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DF270: 133c0504                 sethi   %hi(paGetvaluesCount), %o1
F00DF274: 9410001a                 mov     %i2, %o2
F00DF278: 9610001b                 mov     %i3, %o3
F00DF27C: 98100019                 mov     %i1, %o4
F00DF280: d20263e0                 ld      [%o1+%lo(paGetvaluesCount)], %o1! SEL
F00DF284: 4000497b                 call    _objc_msgSend
F00DF288: 9a100018                 mov     %i0, %o5
F00DF28C: 912a2018                 sll     %o0, 24, %o0
F00DF290: 80a00008                 cmp     %g0, %o0
F00DF294: b0403fff                 addc    %g0, -1, %i0
F00DF298: b00e20d2                 and     %i0, 0xD2, %i0
F00DF29C: 81c7e008                 ret
F00DF2A0: 81e80000                 restore
