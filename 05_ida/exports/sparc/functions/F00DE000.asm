F00DE000: 9de3bf98                 save    %sp, -0x68, %sp
F00DE004: 113c0506                 sethi   %hi(paAudiochannel), %o0
F00DE008: d00222d0                 ld      [%o0+%lo(paAudiochannel)], %o0! id
F00DE00C: 133c0505                 sethi   %hi(paStreamforuserp), %o1
F00DE010: d2026020                 ld      [%o1+%lo(paStreamforuserp)], %o1! SEL
F00DE014: 40004e17                 call    _objc_msgSend
F00DE018: 94100018                 mov     %i0, %o2
F00DE01C: 80a22000                 cmp     %o0, 0
F00DE020: 12800006                 bne     locret_F00DE038
F00DE024: b0100008                 mov     %o0, %i0
F00DE028: 113c03f2                 sethi   %hi(aAudioServerCan_0), %o0! "Audio: server can't translate port to s"...
F00DE02C: 7fffa032                 call    _IOLog
F00DE030: 90122088                 bset    %lo(aAudioServerCan_0), %o0! "Audio: server can't translate port to s"...
F00DE034: b0102000                 mov     0, %i0
F00DE038: 81c7e008                 ret
F00DE03C: 81e80000                 restore
