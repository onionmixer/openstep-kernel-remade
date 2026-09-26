F00DDA44: 9de3bf90                 save    %sp, -0x70, %sp
F00DDA48: 113c0506                 sethi   %hi(paIoaudio), %o0
F00DDA4C: d00222d4                 ld      [%o0+%lo(paIoaudio)], %o0! id
F00DDA50: 133c0505                 sethi   %hi(paInstance_0), %o1! SEL
F00DDA54: 40004f87                 call    _objc_msgSend
F00DDA58: d20260e0                 ld      [%o1+%lo(paInstance_0)], %o1
F00DDA5C: a2100019                 mov     %i1, %l1
F00DDA60: 92102001                 mov     1, %o1
F00DDA64: d22c6003                 stb     %o1, [%l1+3]
F00DDA68: 92102018                 mov     0x18, %o1
F00DDA6C: d2246004                 st      %o1, [%l1+4]
F00DDA70: c0246008                 clr     [%l1+8]
F00DDA74: c024600c                 clr     [%l1+0xC]
F00DDA78: d2062010                 ld      [%i0+0x10], %o1
F00DDA7C: d2246010                 st      %o1, [%l1+0x10]
F00DDA80: c0246014                 clr     [%l1+0x14]
F00DDA84: d2062014                 ld      [%i0+0x14], %o1
F00DDA88: 80a26000                 cmp     %o1, 0
F00DDA8C: 02800004                 be      loc_F00DDA9C
F00DDA90: a8100008                 mov     %o0, %l4
F00DDA94: 10800117                 ba      locret_F00DDEF0
F00DDA98: b0102000                 mov     0, %i0
F00DDA9C: 80a52000                 cmp     %l4, 0
F00DDAA0: 22800114                 be,a    locret_F00DDEF0
F00DDAA4: b0102001                 mov     1, %i0
F00DDAA8: 273c04bb                 sethi   %hi(dword_F012EF4C), %l3
F00DDAAC: d004e34c                 ld      [%l3+%lo(dword_F012EF4C)], %o0
F00DDAB0: 80a22000                 cmp     %o0, 0
F00DDAB4: 3280004b                 bne,a   loc_F00DDBE0
F00DDAB8: c02e6003                 clrb    [%i1+3]
F00DDABC: 253c04cc                 sethi   %hi(dword_F01330E0), %l2
F00DDAC0: d004a0e0                 ld      [%l2+%lo(dword_F01330E0)], %o0
F00DDAC4: 133c037b                 sethi   %hi(_audio_port_gone), %o1
F00DDAC8: 7ffe7366                 call    _kern_serv_port_death_proc
F00DDACC: 921260fc                 bset    %lo(_audio_port_gone), %o1
F00DDAD0: 7ffe25f8                 call    _task_self
F00DDAD4: 01000000                 nop
F00DDAD8: 40005822                 call    _port_allocate_EXTERNAL
F00DDADC: 9207bff4                 add     %fp, var_C, %o1
F00DDAE0: 80a22000                 cmp     %o0, 0
F00DDAE4: 02800004                 be      loc_F00DDAF4
F00DDAE8: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDAEC: 7fffa182                 call    _IOLog
F00DDAF0: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDAF4: 133c0377a01262f8         set     _audioMessages, %l0
F00DDAFC: 94100010                 mov     %l0, %o2
F00DDB00: d207bff4                 ld      [%fp+var_C], %o1
F00DDB04: 173c04bb                 sethi   %hi(_outPort), %o3
F00DDB08: d004a0e0                 ld      [%l2+0xE0], %o0
F00DDB0C: d222e340                 st      %o1, [%o3+%lo(_outPort)]
F00DDB10: 7ffe7325                 call    _kern_serv_port_serv
F00DDB14: 96100009                 mov     %o1, %o3
F00DDB18: 92920000                 orcc    %o0, %g0, %o1
F00DDB1C: 02800004                 be      loc_F00DDB2C
F00DDB20: 113c03f1                 sethi   %hi(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDB24: 7fffa174                 call    _IOLog
F00DDB28: 90122318                 bset    %lo(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDB2C: 7ffe25e1                 call    _task_self
F00DDB30: 01000000                 nop
F00DDB34: 4000580b                 call    _port_allocate_EXTERNAL
F00DDB38: 9207bff4                 add     %fp, var_C, %o1
F00DDB3C: 80a22000                 cmp     %o0, 0
F00DDB40: 02800004                 be      loc_F00DDB50
F00DDB44: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDB48: 7fffa16b                 call    _IOLog
F00DDB4C: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDB50: 94100010                 mov     %l0, %o2
F00DDB54: d207bff4                 ld      [%fp+var_C], %o1
F00DDB58: 173c04bb                 sethi   %hi(_inPort), %o3
F00DDB5C: d004a0e0                 ld      [%l2+0xE0], %o0
F00DDB60: d222e344                 st      %o1, [%o3+%lo(_inPort)]
F00DDB64: 7ffe7310                 call    _kern_serv_port_serv
F00DDB68: 96100009                 mov     %o1, %o3
F00DDB6C: 92920000                 orcc    %o0, %g0, %o1
F00DDB70: 02800004                 be      loc_F00DDB80
F00DDB74: 113c03f1                 sethi   %hi(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDB78: 7fffa15f                 call    _IOLog
F00DDB7C: 90122318                 bset    %lo(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDB80: 7ffe25cc                 call    _task_self
F00DDB84: 01000000                 nop
F00DDB88: 400057f6                 call    _port_allocate_EXTERNAL
F00DDB8C: 9207bff4                 add     %fp, var_C, %o1
F00DDB90: 80a22000                 cmp     %o0, 0
F00DDB94: 02800004                 be      loc_F00DDBA4
F00DDB98: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDB9C: 7fffa156                 call    _IOLog
F00DDBA0: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDBA4: 94100010                 mov     %l0, %o2
F00DDBA8: d207bff4                 ld      [%fp+var_C], %o1
F00DDBAC: 173c04bb                 sethi   %hi(_sndPort), %o3
F00DDBB0: d004a0e0                 ld      [%l2+0xE0], %o0
F00DDBB4: d222e348                 st      %o1, [%o3+%lo(_sndPort)]
F00DDBB8: 7ffe72fb                 call    _kern_serv_port_serv
F00DDBBC: 96100009                 mov     %o1, %o3
F00DDBC0: 92920000                 orcc    %o0, %g0, %o1
F00DDBC4: 02800004                 be      loc_F00DDBD4
F00DDBC8: 113c03f1                 sethi   %hi(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDBCC: 7fffa14a                 call    _IOLog
F00DDBD0: 90122318                 bset    %lo(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDBD4: 90102001                 mov     1, %o0
F00DDBD8: d024e34c                 st      %o0, [%l3+0x34C]
F00DDBDC: c02e6003                 clrb    [%i1+3]
F00DDBE0: 90102028                 mov     0x28, %o0 ! '('
F00DDBE4: d0266004                 st      %o0, [%i1+4]
F00DDBE8: 90102001                 mov     1, %o0
F00DDBEC: d0266014                 st      %o0, [%i1+0x14]
F00DDBF0: 90102006                 mov     6, %o0
F00DDBF4: d02c6018                 stb     %o0, [%l1+0x18]
F00DDBF8: 90102020                 mov     0x20, %o0 ! ' '
F00DDBFC: d02c6019                 stb     %o0, [%l1+0x19]
F00DDC00: d0046018                 ld      [%l1+0x18], %o0
F00DDC04: 133fffc09212600f         set     -0xFFF1, %o1
F00DDC0C: 900a0009                 and     %o0, %o1, %o0
F00DDC10: 90122038                 bset    0x38, %o0 ! '8'
F00DDC14: 900a3ff8                 and     %o0, -8, %o0
F00DDC18: 7fffb1de                 call    _IOHostPrivSelf
F00DDC1C: d0246018                 st      %o0, [%l1+0x18]
F00DDC20: 92920000                 orcc    %o0, %g0, %o1
F00DDC24: 32800007                 bne,a   loc_F00DDC40
F00DDC28: d006201c                 ld      [%i0+0x1C], %o0
F00DDC2C: 113c03f1                 sethi   %hi(aAudioCannotGet), %o0! "Audio: cannot get kernel port (must run"...
F00DDC30: 7fffa131                 call    _IOLog
F00DDC34: 90122368                 bset    %lo(aAudioCannotGet), %o0! "Audio: cannot get kernel port (must run"...
F00DDC38: 108000ae                 ba      locret_F00DDEF0
F00DDC3C: b0102001                 mov     1, %i0
F00DDC40: 80a20009                 cmp     %o0, %o1
F00DDC44: 22800006                 be,a    loc_F00DDC5C
F00DDC48: d0062024                 ld      [%i0+0x24], %o0
F00DDC4C: c024601c                 clr     [%l1+0x1C]
F00DDC50: c0246020                 clr     [%l1+0x20]
F00DDC54: 10800083                 ba      loc_F00DDE60
F00DDC58: c0246024                 clr     [%l1+0x24]
F00DDC5C: 80a22000                 cmp     %o0, 0
F00DDC60: 02800077                 be      loc_F00DDE3C
F00DDC64: 213c04bb                 sethi   %hi(_inPort), %l0
F00DDC68: d2042344                 ld      [%l0+%lo(_inPort)], %o1
F00DDC6C: 80a26000                 cmp     %o1, 0
F00DDC70: 22800010                 be,a    loc_F00DDCB0
F00DDC74: 213c04bb                 sethi   -0xFED1400, %l0
F00DDC78: 113c04cc                 sethi   %hi(dword_F01330E0), %o0
F00DDC7C: 7ffe7207                 call    _kern_serv_port_gone
F00DDC80: d00220e0                 ld      [%o0+%lo(dword_F01330E0)], %o0
F00DDC84: 7ffe258b                 call    _task_self
F00DDC88: e0042344                 ld      [%l0+%lo(_inPort)], %l0
F00DDC8C: 400057f8                 call    _port_deallocate_EXTERNAL
F00DDC90: 92100010                 mov     %l0, %o1
F00DDC94: 80a22000                 cmp     %o0, 0
F00DDC98: 02800006                 be      loc_F00DDCB0
F00DDC9C: 213c04bb                 sethi   -0xFED1400, %l0
F00DDCA0: 113c03f0                 sethi   %hi(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DDCA4: 7fffa114                 call    _IOLog
F00DDCA8: 90122118                 bset    %lo(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DDCAC: 213c04bb                 sethi   -0xFED1400, %l0
F00DDCB0: d2042340                 ld      [%l0+0x340], %o1
F00DDCB4: 80a26000                 cmp     %o1, 0
F00DDCB8: 22800010                 be,a    loc_F00DDCF8
F00DDCBC: 213c04bb                 sethi   -0xFED1400, %l0
F00DDCC0: 113c04cc                 sethi   %hi(dword_F01330E0), %o0
F00DDCC4: 7ffe71f5                 call    _kern_serv_port_gone
F00DDCC8: d00220e0                 ld      [%o0+%lo(dword_F01330E0)], %o0
F00DDCCC: 7ffe2579                 call    _task_self
F00DDCD0: e0042340                 ld      [%l0+0x340], %l0
F00DDCD4: 400057e6                 call    _port_deallocate_EXTERNAL
F00DDCD8: 92100010                 mov     %l0, %o1
F00DDCDC: 80a22000                 cmp     %o0, 0
F00DDCE0: 02800006                 be      loc_F00DDCF8
F00DDCE4: 213c04bb                 sethi   -0xFED1400, %l0
F00DDCE8: 113c03f0                 sethi   %hi(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DDCEC: 7fffa102                 call    _IOLog
F00DDCF0: 90122118                 bset    %lo(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DDCF4: 213c04bb                 sethi   -0xFED1400, %l0
F00DDCF8: d2042348                 ld      [%l0+0x348], %o1
F00DDCFC: 80a26000                 cmp     %o1, 0
F00DDD00: 0280000d                 be      loc_F00DDD34
F00DDD04: 113c04cc                 sethi   %hi(dword_F01330E0), %o0
F00DDD08: 7ffe71e4                 call    _kern_serv_port_gone
F00DDD0C: d00220e0                 ld      [%o0+%lo(dword_F01330E0)], %o0
F00DDD10: 7ffe2568                 call    _task_self
F00DDD14: e0042348                 ld      [%l0+0x348], %l0
F00DDD18: 400057d5                 call    _port_deallocate_EXTERNAL
F00DDD1C: 92100010                 mov     %l0, %o1
F00DDD20: 80a22000                 cmp     %o0, 0
F00DDD24: 02800004                 be      loc_F00DDD34
F00DDD28: 113c03f0                 sethi   %hi(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DDD2C: 7fffa0f2                 call    _IOLog
F00DDD30: 90122118                 bset    %lo(aAudioPortDeall), %o0! "Audio: port_deallocate\n"
F00DDD34: 7ffe255f                 call    _task_self
F00DDD38: 01000000                 nop
F00DDD3C: 40005789                 call    _port_allocate_EXTERNAL
F00DDD40: 9207bff4                 add     %fp, var_C, %o1
F00DDD44: 80a22000                 cmp     %o0, 0
F00DDD48: 02800004                 be      loc_F00DDD58
F00DDD4C: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDD50: 7fffa0e9                 call    _IOLog
F00DDD54: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDD58: 253c04cc                 sethi   %hi(dword_F01330E0), %l2
F00DDD5C: 133c0377a01262f8         set     _audioMessages, %l0
F00DDD64: 94100010                 mov     %l0, %o2
F00DDD68: d207bff4                 ld      [%fp+var_C], %o1
F00DDD6C: 173c04bb                 sethi   %hi(_outPort), %o3
F00DDD70: d004a0e0                 ld      [%l2+%lo(dword_F01330E0)], %o0
F00DDD74: d222e340                 st      %o1, [%o3+%lo(_outPort)]
F00DDD78: 7ffe728b                 call    _kern_serv_port_serv
F00DDD7C: 96100009                 mov     %o1, %o3
F00DDD80: 92920000                 orcc    %o0, %g0, %o1
F00DDD84: 02800004                 be      loc_F00DDD94
F00DDD88: 113c03f1                 sethi   %hi(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDD8C: 7fffa0da                 call    _IOLog
F00DDD90: 90122318                 bset    %lo(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDD94: 7ffe2547                 call    _task_self
F00DDD98: 01000000                 nop
F00DDD9C: 40005771                 call    _port_allocate_EXTERNAL
F00DDDA0: 9207bff4                 add     %fp, var_C, %o1
F00DDDA4: 80a22000                 cmp     %o0, 0
F00DDDA8: 02800004                 be      loc_F00DDDB8
F00DDDAC: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDDB0: 7fffa0d1                 call    _IOLog
F00DDDB4: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDDB8: 94100010                 mov     %l0, %o2
F00DDDBC: d207bff4                 ld      [%fp+var_C], %o1
F00DDDC0: 173c04bb                 sethi   %hi(_inPort), %o3
F00DDDC4: d004a0e0                 ld      [%l2+0xE0], %o0
F00DDDC8: d222e344                 st      %o1, [%o3+%lo(_inPort)]
F00DDDCC: 7ffe7276                 call    _kern_serv_port_serv
F00DDDD0: 96100009                 mov     %o1, %o3
F00DDDD4: 92920000                 orcc    %o0, %g0, %o1
F00DDDD8: 02800004                 be      loc_F00DDDE8
F00DDDDC: 113c03f1                 sethi   %hi(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDDE0: 7fffa0c5                 call    _IOLog
F00DDDE4: 90122318                 bset    %lo(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDDE8: 7ffe2532                 call    _task_self
F00DDDEC: 01000000                 nop
F00DDDF0: 4000575c                 call    _port_allocate_EXTERNAL
F00DDDF4: 9207bff4                 add     %fp, var_C, %o1
F00DDDF8: 80a22000                 cmp     %o0, 0
F00DDDFC: 02800004                 be      loc_F00DDE0C
F00DDE00: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDE04: 7fffa0bc                 call    _IOLog
F00DDE08: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00DDE0C: 94100010                 mov     %l0, %o2
F00DDE10: d207bff4                 ld      [%fp+var_C], %o1
F00DDE14: 173c04bb                 sethi   %hi(_sndPort), %o3
F00DDE18: d004a0e0                 ld      [%l2+0xE0], %o0
F00DDE1C: d222e348                 st      %o1, [%o3+%lo(_sndPort)]
F00DDE20: 7ffe7261                 call    _kern_serv_port_serv
F00DDE24: 96100009                 mov     %o1, %o3
F00DDE28: 92920000                 orcc    %o0, %g0, %o1
F00DDE2C: 02800004                 be      loc_F00DDE3C
F00DDE30: 113c03f1                 sethi   %hi(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDE34: 7fffa0b0                 call    _IOLog
F00DDE38: 90122318                 bset    %lo(aAudioCreateaud), %o0! "Audio: createAudioPorts error %d\n"
F00DDE3C: 113c04bb                 sethi   %hi(_inPort), %o0
F00DDE40: d0022344                 ld      [%o0+%lo(_inPort)], %o0
F00DDE44: d024601c                 st      %o0, [%l1+0x1C]
F00DDE48: 113c04bb                 sethi   %hi(_outPort), %o0
F00DDE4C: d2022340                 ld      [%o0+%lo(_outPort)], %o1! SEL
F00DDE50: 113c04bb                 sethi   %hi(_sndPort), %o0
F00DDE54: d0022348                 ld      [%o0+%lo(_sndPort)], %o0
F00DDE58: d2246020                 st      %o1, [%l1+0x20]
F00DDE5C: d0246024                 st      %o0, [%l1+0x24]
F00DDE60: 113c0505                 sethi   %hi(paOutputchannel), %o0
F00DDE64: e0022218                 ld      [%o0+%lo(paOutputchannel)], %l0
F00DDE68: 90100014                 mov     %l4, %o0! id
F00DDE6C: 40004e81                 call    _objc_msgSend
F00DDE70: 92100010                 mov     %l0, %o1
F00DDE74: 133c0505                 sethi   %hi(paSetuserchannel), %o1
F00DDE78: e6026028                 ld      [%o1+%lo(paSetuserchannel)], %l3
F00DDE7C: 133c04bb                 sethi   %hi(_outPort), %o1! SEL
F00DDE80: d4026340                 ld      [%o1+%lo(_outPort)], %o2
F00DDE84: 40004e7b                 call    _objc_msgSend
F00DDE88: 92100013                 mov     %l3, %o1! SEL
F00DDE8C: 90100014                 mov     %l4, %o0! id
F00DDE90: 40004e78                 call    _objc_msgSend
F00DDE94: 92100010                 mov     %l0, %o1
F00DDE98: 133c0505                 sethi   %hi(paSetusersndport), %o1! SEL
F00DDE9C: e402602c                 ld      [%o1+%lo(paSetusersndport)], %l2
F00DDEA0: 233c04bb                 sethi   %hi(_sndPort), %l1
F00DDEA4: d4046348                 ld      [%l1+%lo(_sndPort)], %o2
F00DDEA8: 40004e72                 call    _objc_msgSend
F00DDEAC: 92100012                 mov     %l2, %o1! SEL
F00DDEB0: 113c0505                 sethi   %hi(paInputchannel), %o0
F00DDEB4: e0022220                 ld      [%o0+%lo(paInputchannel)], %l0
F00DDEB8: 90100014                 mov     %l4, %o0! id
F00DDEBC: 40004e6d                 call    _objc_msgSend
F00DDEC0: 92100010                 mov     %l0, %o1
F00DDEC4: 133c04bb                 sethi   %hi(_inPort), %o1! SEL
F00DDEC8: d4026344                 ld      [%o1+%lo(_inPort)], %o2
F00DDECC: 40004e69                 call    _objc_msgSend
F00DDED0: 92100013                 mov     %l3, %o1! SEL
F00DDED4: 90100014                 mov     %l4, %o0! id
F00DDED8: 40004e66                 call    _objc_msgSend
F00DDEDC: 92100010                 mov     %l0, %o1! SEL
F00DDEE0: d4046348                 ld      [%l1+%lo(_sndPort)], %o2
F00DDEE4: 40004e63                 call    _objc_msgSend
F00DDEE8: 92100012                 mov     %l2, %o1
F00DDEEC: b0102001                 mov     1, %i0
F00DDEF0: 81c7e008                 ret
F00DDEF4: 81e80000                 restore
