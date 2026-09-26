F00DF0E4: 9de3bf98                 save    %sp, -0x68, %sp
F00DF0E8: 80a62000                 cmp     %i0, 0
F00DF0EC: 0280000c                 be      loc_F00DF11C
F00DF0F0: c0264000                 clr     [%i1]
F00DF0F4: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DF0F8: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DF0FC: 400049dd                 call    _objc_msgSend
F00DF100: 90100018                 mov     %i0, %o0! id
F00DF104: 133c0504                 sethi   %hi(paChannelcountli), %o1! SEL
F00DF108: 400049da                 call    _objc_msgSend
F00DF10C: d20263cc                 ld      [%o1+%lo(paChannelcountli)], %o1
F00DF110: d0264000                 st      %o0, [%i1]
F00DF114: 10800003                 ba      locret_F00DF120
F00DF118: b0102000                 mov     0, %i0
F00DF11C: b01020ca                 mov     0xCA, %i0
F00DF120: 81c7e008                 ret
F00DF124: 81e80000                 restore
