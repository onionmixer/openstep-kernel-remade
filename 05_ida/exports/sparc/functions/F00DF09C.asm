F00DF09C: 9de3bf98                 save    %sp, -0x68, %sp
F00DF0A0: 80a62000                 cmp     %i0, 0
F00DF0A4: 0280000d                 be      loc_F00DF0D8
F00DF0A8: c0268000                 clr     [%i2]
F00DF0AC: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DF0B0: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DF0B4: 400049ef                 call    _objc_msgSend
F00DF0B8: 90100018                 mov     %i0, %o0! id
F00DF0BC: 133c0504                 sethi   %hi(paGetdataencodin), %o1
F00DF0C0: 94100019                 mov     %i1, %o2
F00DF0C4: d20263d0                 ld      [%o1+%lo(paGetdataencodin)], %o1! SEL
F00DF0C8: 400049ea                 call    _objc_msgSend
F00DF0CC: 9610001a                 mov     %i2, %o3
F00DF0D0: 10800003                 ba      locret_F00DF0DC
F00DF0D4: b0102000                 mov     0, %i0
F00DF0D8: b01020ca                 mov     0xCA, %i0
F00DF0DC: 81c7e008                 ret
F00DF0E0: 81e80000                 restore
