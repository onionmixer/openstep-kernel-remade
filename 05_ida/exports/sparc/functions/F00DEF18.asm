F00DEF18: 9de3bf98                 save    %sp, -0x68, %sp
F00DEF1C: 80a62000                 cmp     %i0, 0
F00DEF20: 0280000e                 be      loc_F00DEF58
F00DEF24: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DEF28: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DEF2C: 40004a51                 call    _objc_msgSend
F00DEF30: 90100018                 mov     %i0, %o0! id
F00DEF34: 133c0504                 sethi   %hi(paGetparametersV), %o1
F00DEF38: 94100019                 mov     %i1, %o2
F00DEF3C: 9610001b                 mov     %i3, %o3
F00DEF40: 9810001a                 mov     %i2, %o4
F00DEF44: d20263e8                 ld      [%o1+%lo(paGetparametersV)], %o1! SEL
F00DEF48: 40004a4a                 call    _objc_msgSend
F00DEF4C: 9a100018                 mov     %i0, %o5
F00DEF50: 10800003                 ba      locret_F00DEF5C
F00DEF54: b0102000                 mov     0, %i0
F00DEF58: b01020ca                 mov     0xCA, %i0
F00DEF5C: 81c7e008                 ret
F00DEF60: 81e80000                 restore
