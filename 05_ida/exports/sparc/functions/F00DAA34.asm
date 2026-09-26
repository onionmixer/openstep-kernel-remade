F00DAA34: 9de3bf88                 save    %sp, -0x78, %sp
F00DAA38: d0062004                 ld      [%i0+4], %o0! id
F00DAA3C: 133c0505                 sethi   %hi(paChannelwilladd), %o1! SEL
F00DAA40: 40005b8c                 call    _objc_msgSend
F00DAA44: d202608c                 ld      [%o1+%lo(paChannelwilladd)], %o1
F00DAA48: 912a2018                 sll     %o0, 24, %o0
F00DAA4C: 80a22000                 cmp     %o0, 0
F00DAA50: 02800029                 be      loc_F00DAAF4
F00DAA54: 113c0505                 sethi   %hi(paStreamclass), %o0! id
F00DAA58: d2022088                 ld      [%o0+%lo(paStreamclass)], %o1! SEL
F00DAA5C: 40005b85                 call    _objc_msgSend
F00DAA60: 90100018                 mov     %i0, %o0! id
F00DAA64: 133c0503                 sethi   %hi(paAlloc), %o1! SEL
F00DAA68: 40005b82                 call    _objc_msgSend
F00DAA6C: d20263f0                 ld      [%o1+%lo(paAlloc)], %o1
F00DAA70: fa23a05c                 st      %i5, [%sp+0x78+var_1C]
F00DAA74: 133c0505                 sethi   %hi(paInitchannelTag), %o1
F00DAA78: 94100018                 mov     %i0, %o2
F00DAA7C: 9610001a                 mov     %i2, %o3
F00DAA80: 9810001b                 mov     %i3, %o4
F00DAA84: d2026084                 ld      [%o1+%lo(paInitchannelTag)], %o1! SEL
F00DAA88: 40005b7a                 call    _objc_msgSend
F00DAA8C: 9a10001c                 mov     %i4, %o5
F00DAA90: b4920000                 orcc    %o0, %g0, %i2
F00DAA94: 02800018                 be      loc_F00DAAF4
F00DAA98: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DAA9C: d0062010                 ld      [%i0+0x10], %o0! id
F00DAAA0: 40005b74                 call    _objc_msgSend
F00DAAA4: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DAAA8: d006200c                 ld      [%i0+0xC], %o0! id
F00DAAAC: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00DAAB0: 40005b70                 call    _objc_msgSend
F00DAAB4: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00DAAB8: 80a22000                 cmp     %o0, 0
F00DAABC: 32800010                 bne,a   loc_F00DAAFC
F00DAAC0: d006200c                 ld      [%i0+0xC], %o0
F00DAAC4: 113c0505                 sethi   %hi(paCreatechannelb), %o0! id
F00DAAC8: d2022080                 ld      [%o0+%lo(paCreatechannelb)], %o1! SEL
F00DAACC: 40005b69                 call    _objc_msgSend
F00DAAD0: 90100018                 mov     %i0, %o0
F00DAAD4: 912a2018                 sll     %o0, 24, %o0
F00DAAD8: 80a22000                 cmp     %o0, 0
F00DAADC: 32800008                 bne,a   loc_F00DAAFC
F00DAAE0: d006200c                 ld      [%i0+0xC], %o0
F00DAAE4: d0062010                 ld      [%i0+0x10], %o0! id
F00DAAE8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DAAEC: 40005b61                 call    _objc_msgSend
F00DAAF0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DAAF4: 10800015                 ba      locret_F00DAB48
F00DAAF8: b0102000                 mov     0, %i0
F00DAAFC: 133c0504                 sethi   %hi(paAddobject), %o1
F00DAB00: d20260a4                 ld      [%o1+%lo(paAddobject)], %o1! SEL
F00DAB04: 40005b5b                 call    _objc_msgSend
F00DAB08: 9410001a                 mov     %i2, %o2
F00DAB0C: d0062010                 ld      [%i0+0x10], %o0! id
F00DAB10: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DAB14: 40005b57                 call    _objc_msgSend
F00DAB18: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DAB1C: 113c0506                 sethi   %hi(paAudiochannel), %o0
F00DAB20: d00222d0                 ld      [%o0+%lo(paAudiochannel)], %o0! id
F00DAB24: 133c0505                 sethi   %hi(paAddstream), %o1
F00DAB28: d202607c                 ld      [%o1+%lo(paAddstream)], %o1! SEL
F00DAB2C: 40005b51                 call    _objc_msgSend
F00DAB30: 9410001a                 mov     %i2, %o2
F00DAB34: d006c000                 ld      [%i3], %o0
F00DAB38: 40000b6d                 call    _audio_enroll_stream_port
F00DAB3C: 92102001                 mov     1, %o1
F00DAB40: 912a2018                 sll     %o0, 24, %o0
F00DAB44: b13a2018                 sra     %o0, 24, %i0
F00DAB48: 81c7e008                 ret
F00DAB4C: 81e80000                 restore
