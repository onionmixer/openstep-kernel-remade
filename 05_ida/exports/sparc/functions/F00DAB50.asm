F00DAB50: 9de3bf90                 save    %sp, -0x70, %sp
F00DAB54: 113c0505                 sethi   %hi(paUserport), %o0! id
F00DAB58: d20220b4                 ld      [%o0+%lo(paUserport)], %o1! SEL
F00DAB5C: 40005b45                 call    _objc_msgSend
F00DAB60: 9010001a                 mov     %i2, %o0
F00DAB64: 40000b62                 call    _audio_enroll_stream_port
F00DAB68: 92102000                 mov     0, %o1
F00DAB6C: d0062010                 ld      [%i0+0x10], %o0! id
F00DAB70: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DAB74: 40005b3f                 call    _objc_msgSend
F00DAB78: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DAB7C: d006200c                 ld      [%i0+0xC], %o0! id
F00DAB80: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00DAB84: 40005b3b                 call    _objc_msgSend
F00DAB88: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00DAB8C: 80a22001                 cmp     %o0, 1
F00DAB90: 3280002f                 bne,a   loc_F00DAC4C
F00DAB94: d006200c                 ld      [%i0+0xC], %o0
F00DAB98: d0062010                 ld      [%i0+0x10], %o0! id
F00DAB9C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DABA0: 40005b34                 call    _objc_msgSend
F00DABA4: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DABA8: 113c0505                 sethi   %hi(paIsread), %o0! id
F00DABAC: d2022214                 ld      [%o0+%lo(paIsread)], %o1! SEL
F00DABB0: 40005b30                 call    _objc_msgSend
F00DABB4: 90100018                 mov     %i0, %o0
F00DABB8: 912a2018                 sll     %o0, 24, %o0
F00DABBC: 80a22000                 cmp     %o0, 0
F00DABC0: 02800009                 be      loc_F00DABE4
F00DABC4: d0062004                 ld      [%i0+4], %o0! id
F00DABC8: 133c0505                 sethi   %hi(paAudiocommand_0), %o1! SEL
F00DABCC: 40005b29                 call    _objc_msgSend
F00DABD0: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1
F00DABD4: 133c0506                 sethi   %hi(paSend), %o1
F00DABD8: d2026060                 ld      [%o1+%lo(paSend)], %o1
F00DABDC: 10800008                 ba      loc_F00DABFC
F00DABE0: 94102006                 mov     6, %o2
F00DABE4: 133c0505                 sethi   %hi(paAudiocommand_0), %o1! SEL
F00DABE8: 40005b22                 call    _objc_msgSend
F00DABEC: d20261f8                 ld      [%o1+%lo(paAudiocommand_0)], %o1
F00DABF0: 133c0506                 sethi   %hi(paSend), %o1
F00DABF4: d2026060                 ld      [%o1+%lo(paSend)], %o1! SEL
F00DABF8: 94102007                 mov     7, %o2
F00DABFC: 40005b1d                 call    _objc_msgSend
F00DAC00: 01000000                 nop
F00DAC04: d0062010                 ld      [%i0+0x10], %o0! id
F00DAC08: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DAC0C: 40005b19                 call    _objc_msgSend
F00DAC10: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DAC14: d0062058                 ld      [%i0+0x58], %o0
F00DAC18: 80a22000                 cmp     %o0, 0
F00DAC1C: 22800005                 be,a    loc_F00DAC30
F00DAC20: d006205c                 ld      [%i0+0x5C], %o0
F00DAC24: 40001e88                 call    _audio_clear_peaks
F00DAC28: 92102010                 mov     0x10, %o1
F00DAC2C: d006205c                 ld      [%i0+0x5C], %o0
F00DAC30: 80a22000                 cmp     %o0, 0
F00DAC34: 22800005                 be,a    loc_F00DAC48
F00DAC38: c0262064                 clr     [%i0+0x64]
F00DAC3C: 40001e82                 call    _audio_clear_peaks
F00DAC40: 92102010                 mov     0x10, %o1
F00DAC44: c0262064                 clr     [%i0+0x64]
F00DAC48: d006200c                 ld      [%i0+0xC], %o0! id
F00DAC4C: 133c0504                 sethi   %hi(paRemoveobject), %o1
F00DAC50: d20260ac                 ld      [%o1+%lo(paRemoveobject)], %o1! SEL
F00DAC54: 40005b07                 call    _objc_msgSend
F00DAC58: 9410001a                 mov     %i2, %o2
F00DAC5C: 113c0506                 sethi   %hi(paAudiochannel), %o0
F00DAC60: d00222d0                 ld      [%o0+%lo(paAudiochannel)], %o0! id
F00DAC64: 133c0505                 sethi   %hi(paRemovestream), %o1
F00DAC68: d2026094                 ld      [%o1+%lo(paRemovestream)], %o1! SEL
F00DAC6C: 40005b01                 call    _objc_msgSend
F00DAC70: 9410001a                 mov     %i2, %o2
F00DAC74: 113c0503                 sethi   %hi(paFree), %o0! id
F00DAC78: d20223fc                 ld      [%o0+%lo(paFree)], %o1! SEL
F00DAC7C: 40005afd                 call    _objc_msgSend
F00DAC80: 9010001a                 mov     %i2, %o0
F00DAC84: d0062010                 ld      [%i0+0x10], %o0! id
F00DAC88: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DAC8C: 40005af9                 call    _objc_msgSend
F00DAC90: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DAC94: 81c7e008                 ret
F00DAC98: 81e80000                 restore
