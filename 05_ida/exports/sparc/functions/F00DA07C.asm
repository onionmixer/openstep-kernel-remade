F00DA07C: 9de3bf90                 save    %sp, -0x70, %sp
F00DA080: 113c03f0                 sethi   %hi(aAudiochannelFr), %o0! "AudioChannel: -free not supported\n"
F00DA084: 7fffb01c                 call    _IOLog
F00DA088: 901223c8                 bset    %lo(aAudiochannelFr), %o0! "AudioChannel: -free not supported\n"
F00DA08C: f027bff0                 st      %i0, [%fp+var_10]
F00DA090: 133c0508                 sethi   %hi(stru_F014227C.super_class), %o1
F00DA094: d4026280                 ld      [%o1+%lo(stru_F014227C.super_class)], %o2
F00DA098: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00DA09C: 133c0503                 sethi   %hi(paFree), %o1
F00DA0A0: d20263fc                 ld      [%o1+%lo(paFree)], %o1! SEL
F00DA0A4: 40005e36                 call    _objc_msgSendSuper
F00DA0A8: d427bff4                 st      %o2, [%fp+var_C]
F00DA0AC: 81c7e008                 ret
F00DA0B0: 91e80008                 restore %g0, %o0, %o0
