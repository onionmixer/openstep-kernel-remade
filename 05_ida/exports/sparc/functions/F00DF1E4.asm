F00DF1E4: 9de3bf98                 save    %sp, -0x68, %sp
F00DF1E8: 80a62000                 cmp     %i0, 0
F00DF1EC: 02800011                 be      loc_F00DF230
F00DF1F0: c0268000                 clr     [%i2]
F00DF1F4: 113c0505                 sethi   %hi(paChannel), %o0! id
F00DF1F8: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DF1FC: 4000499d                 call    _objc_msgSend
F00DF200: 90100018                 mov     %i0, %o0! id
F00DF204: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DF208: 4000499a                 call    _objc_msgSend
F00DF20C: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DF210: 133c0504                 sethi   %hi(paGetsupportedpa), %o1
F00DF214: 94100019                 mov     %i1, %o2
F00DF218: 9610001a                 mov     %i2, %o3
F00DF21C: d20263e4                 ld      [%o1+%lo(paGetsupportedpa)], %o1! SEL
F00DF220: 40004994                 call    _objc_msgSend
F00DF224: 98100018                 mov     %i0, %o4
F00DF228: 10800003                 ba      locret_F00DF234
F00DF22C: b0102000                 mov     0, %i0
F00DF230: b01020ca                 mov     0xCA, %i0
F00DF234: 81c7e008                 ret
F00DF238: 81e80000                 restore
