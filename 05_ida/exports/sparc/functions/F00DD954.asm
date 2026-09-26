F00DD954: 9de3bf90                 save    %sp, -0x70, %sp
F00DD958: 7fffb28e                 call    _IOHostPrivSelf
F00DD95C: a2100018                 mov     %i0, %l1
F00DD960: a0920000                 orcc    %o0, %g0, %l0
F00DD964: 12800009                 bne     loc_F00DD988
F00DD968: 80a64010                 cmp     %i1, %l0
F00DD96C: 113c03f1                 sethi   %hi(aAudioCannotGet), %o0! "Audio: cannot get kernel port (must run"...
F00DD970: 7fffa1e1                 call    _IOLog
F00DD974: 90122368                 bset    %lo(aAudioCannotGet), %o0! "Audio: cannot get kernel port (must run"...
F00DD978: 113c03f1                 sethi   %hi(aResetSndDevPor), %o0! "reset_snd_dev_port"
F00DD97C: 7fffa1de                 call    _IOLog
F00DD980: 901223a0                 bset    %lo(aResetSndDevPor), %o0! "reset_snd_dev_port"
F00DD984: 80a64010                 cmp     %i1, %l0
F00DD988: 1280002d                 bne     locret_F00DDA3C
F00DD98C: b0102000                 mov     0, %i0
F00DD990: 113c0505                 sethi   %hi(paOutputchannel), %o0
F00DD994: f2022218                 ld      [%o0+%lo(paOutputchannel)], %i1
F00DD998: 90100011                 mov     %l1, %o0! id
F00DD99C: 40004fb5                 call    _objc_msgSend
F00DD9A0: 92100019                 mov     %i1, %o1
F00DD9A4: 133c0505                 sethi   %hi(paUsersndport), %o1! SEL
F00DD9A8: 40004fb2                 call    _objc_msgSend
F00DD9AC: d202621c                 ld      [%o1+%lo(paUsersndport)], %o1
F00DD9B0: 7ffe2640                 call    _task_self
F00DD9B4: a0100008                 mov     %o0, %l0
F00DD9B8: 400058ad                 call    _port_deallocate_EXTERNAL
F00DD9BC: 92100010                 mov     %l0, %o1
F00DD9C0: 80a22000                 cmp     %o0, 0
F00DD9C4: 02800004                 be      loc_F00DD9D4
F00DD9C8: 113c03f0                 sethi   %hi(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DD9CC: 7fffa1ca                 call    _IOLog
F00DD9D0: 90122118                 bset    %lo(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DD9D4: 7ffe2637                 call    _task_self
F00DD9D8: 01000000                 nop
F00DD9DC: 40005861                 call    _port_allocate_EXTERNAL
F00DD9E0: 9207bff4                 add     %fp, var_C, %o1
F00DD9E4: 80a22000                 cmp     %o0, 0
F00DD9E8: 22800006                 be,a    loc_F00DDA00
F00DD9EC: 113c0505                 sethi   -0xFEBEC00, %o0
F00DD9F0: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DD9F4: 7fffa1c0                 call    _IOLog
F00DD9F8: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DD9FC: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DDA00: d2022220                 ld      [%o0+0x220], %o1! SEL
F00DDA04: f007bff4                 ld      [%fp+var_C], %i0
F00DDA08: 40004f9a                 call    _objc_msgSend
F00DDA0C: 90100011                 mov     %l1, %o0! id
F00DDA10: 133c0505                 sethi   %hi(paSetusersndport), %o1! SEL
F00DDA14: e002602c                 ld      [%o1+%lo(paSetusersndport)], %l0
F00DDA18: 94100018                 mov     %i0, %o2
F00DDA1C: 40004f95                 call    _objc_msgSend
F00DDA20: 92100010                 mov     %l0, %o1! SEL
F00DDA24: 90100011                 mov     %l1, %o0! id
F00DDA28: 40004f92                 call    _objc_msgSend
F00DDA2C: 92100019                 mov     %i1, %o1
F00DDA30: 92100010                 mov     %l0, %o1! SEL
F00DDA34: 40004f8f                 call    _objc_msgSend
F00DDA38: 94100018                 mov     %i0, %o2
F00DDA3C: 81c7e008                 ret
F00DDA40: 81e80000                 restore
