F00DDEF8: 9de3bf98                 save    %sp, -0x68, %sp
F00DDEFC: d006200c                 ld      [%i0+0xC], %o0
F00DDF00: 80a22000                 cmp     %o0, 0
F00DDF04: 3280000c                 bne,a   loc_F00DDF34
F00DDF08: d0062014                 ld      [%i0+0x14], %o0
F00DDF0C: 90100018                 mov     %i0, %o0
F00DDF10: 7ffffecd                 call    sub_F00DDA44
F00DDF14: 92100019                 mov     %i1, %o1
F00DDF18: 80a22000                 cmp     %o0, 0
F00DDF1C: 3280001d                 bne,a   loc_F00DDF90
F00DDF20: 90100019                 mov     %i1, %o0
F00DDF24: d2062014                 ld      [%i0+0x14], %o1
F00DDF28: 113c03f1                 sethi   %hi(aAudioUnrecogni_1), %o0! "Audio: unrecognized control message %d"...
F00DDF2C: 10800016                 ba      loc_F00DDF84
F00DDF30: 901223b8                 bset    %lo(aAudioUnrecogni_1), %o0! "Audio: unrecognized control message %d"...
F00DDF34: 80a222bb                 cmp     %o0, 0x2BB
F00DDF38: 1480000b                 bg      loc_F00DDF64
F00DDF3C: 90100018                 mov     %i0, %o0
F00DDF40: 400008f5                 call    _snd_server
F00DDF44: 92100019                 mov     %i1, %o1
F00DDF48: 80a22000                 cmp     %o0, 0
F00DDF4C: 32800011                 bne,a   loc_F00DDF90
F00DDF50: 90100019                 mov     %i1, %o0
F00DDF54: d2062014                 ld      [%i0+0x14], %o1
F00DDF58: 113c03f1                 sethi   %hi(aAudioUnrecogni_2), %o0! "Audio: unrecognized snd user message %d"...
F00DDF5C: 1080000a                 ba      loc_F00DDF84
F00DDF60: 901223e0                 bset    %lo(aAudioUnrecogni_2), %o0! "Audio: unrecognized snd user message %d"...
F00DDF64: 40001548                 call    _audio_server
F00DDF68: 92100019                 mov     %i1, %o1
F00DDF6C: 80a22000                 cmp     %o0, 0
F00DDF70: 12800008                 bne     loc_F00DDF90
F00DDF74: 90100019                 mov     %i1, %o0
F00DDF78: d2062014                 ld      [%i0+0x14], %o1
F00DDF7C: 113c03f290122010         set     aAudioUnrecogni_3, %o0! "Audio: unrecognized audio user message "...
F00DDF84: 7fffa05c                 call    _IOLog
F00DDF88: 01000000                 nop
F00DDF8C: 90100019                 mov     %i1, %o0
F00DDF90: 92102001                 mov     1, %o1
F00DDF94: 7ffe1f50                 call    _msg_send
F00DDF98: 941023e8                 mov     0x3E8, %o2
F00DDF9C: 92920000                 orcc    %o0, %g0, %o1
F00DDFA0: 02800004                 be      loc_F00DDFB0
F00DDFA4: 113c03f2                 sethi   %hi(aMsgSendFailedD), %o0! "msg_send failed %d\n"
F00DDFA8: 7fffa053                 call    _IOLog
F00DDFAC: 90122040                 bset    %lo(aMsgSendFailedD), %o0! "msg_send failed %d\n"
F00DDFB0: 90103ecf                 mov     -0x131, %o0
F00DDFB4: d026601c                 st      %o0, [%i1+0x1C]
F00DDFB8: 81c7e008                 ret
F00DDFBC: 81e80000                 restore
