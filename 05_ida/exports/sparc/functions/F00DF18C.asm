F00DF18C: 9de3bf98                 save    %sp, -0x68, %sp
F00DF190: 80a62000                 cmp     %i0, 0
F00DF194: 02800011                 be      loc_F00DF1D8
F00DF198: 113c0505                 sethi   %hi(paChannel), %o0! id
F00DF19C: d2022058                 ld      [%o0+%lo(paChannel)], %o1! SEL
F00DF1A0: 400049b4                 call    _objc_msgSend
F00DF1A4: 90100018                 mov     %i0, %o0! id
F00DF1A8: 133c0505                 sethi   %hi(paAudiodevice), %o1! SEL
F00DF1AC: 400049b1                 call    _objc_msgSend
F00DF1B0: d2026224                 ld      [%o1+%lo(paAudiodevice)], %o1
F00DF1B4: 133c0504                 sethi   %hi(paGetparametersV), %o1
F00DF1B8: 94100019                 mov     %i1, %o2
F00DF1BC: 9610001b                 mov     %i3, %o3
F00DF1C0: 9810001a                 mov     %i2, %o4
F00DF1C4: d20263e8                 ld      [%o1+%lo(paGetparametersV)], %o1! SEL
F00DF1C8: 400049aa                 call    _objc_msgSend
F00DF1CC: 9a100018                 mov     %i0, %o5
F00DF1D0: 10800003                 ba      locret_F00DF1DC
F00DF1D4: b0102000                 mov     0, %i0
F00DF1D8: b01020ca                 mov     0xCA, %i0
F00DF1DC: 81c7e008                 ret
F00DF1E0: 81e80000                 restore
