F00DDFC0: 9de3bf98                 save    %sp, -0x68, %sp
F00DDFC4: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DDFC8: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DDFCC: 133c0505                 sethi   %hi(paChannelforuser), %o1
F00DDFD0: d2026024                 ld      [%o1+%lo(paChannelforuser)], %o1! SEL
F00DDFD4: 40004e27                 call    _objc_msgSend
F00DDFD8: 94100018                 mov     %i0, %o2
F00DDFDC: 80a22000                 cmp     %o0, 0
F00DDFE0: 12800006                 bne     locret_F00DDFF8
F00DDFE4: b0100008                 mov     %o0, %i0
F00DDFE8: 113c03f2                 sethi   %hi(aAudioServerCan), %o0! "Audio: server can't translate port to c"...
F00DDFEC: 7fffa042                 call    _IOLog
F00DDFF0: 90122058                 bset    %lo(aAudioServerCan), %o0! "Audio: server can't translate port to c"...
F00DDFF4: b0102000                 mov     0, %i0
F00DDFF8: 81c7e008                 ret
F00DDFFC: 81e80000                 restore
