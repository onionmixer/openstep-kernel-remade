F00D96F8: 9de3be80                 save    %sp, -0x180, %sp
F00D96FC: f027bff0                 st      %i0, [%fp+var_10]
F00D9700: 9007bff0                 add     %fp, var_10, %o0! objc_super *
F00D9704: 133c0508                 sethi   %hi(stru_F014222C.ext), %o1
F00D9708: d6026258                 ld      [%o1+%lo(stru_F014222C.ext)], %o3
F00D970C: 9410001a                 mov     %i2, %o2
F00D9710: 133c0504                 sethi   %hi(paInitfromdevice), %o1
F00D9714: d627bff4                 st      %o3, [%fp+var_C]
F00D9718: 173c03f0                 sethi   %hi(aKernelserverin), %o3! "KernelServerInstance"
F00D971C: d20262fc                 ld      [%o1+%lo(paInitfromdevice)], %o1! SEL
F00D9720: 40006097                 call    _objc_msgSendSuper
F00D9724: a412e208                 or      %o3, %lo(aKernelserverin), %l2! "KernelServerInstance"
F00D9728: 80a22000                 cmp     %o0, 0
F00D972C: 02800042                 be      loc_F00D9834
F00D9730: 113c0506                 sethi   %hi(paAttachinterrup_0), %o0! id
F00D9734: d20220e8                 ld      [%o0+%lo(paAttachinterrup_0)], %o1! SEL
F00D9738: 4000604e                 call    _objc_msgSend
F00D973C: 90100018                 mov     %i0, %o0
F00D9740: 80a22000                 cmp     %o0, 0
F00D9744: 328000de                 bne,a   locret_F00D9ABC
F00D9748: b0102000                 mov     0, %i0
F00D974C: 7ffe36d9                 call    _task_self
F00D9750: 01000000                 nop
F00D9754: a0100008                 mov     %o0, %l0
F00D9758: 113c0504                 sethi   %hi(paInterruptport_0), %o0
F00D975C: e8022308                 ld      [%o0+%lo(paInterruptport_0)], %l4
F00D9760: 90100018                 mov     %i0, %o0! id
F00D9764: 40006043                 call    _objc_msgSend
F00D9768: 92100014                 mov     %l4, %o1
F00D976C: 92100008                 mov     %o0, %o1
F00D9770: 90100010                 mov     %l0, %o0
F00D9774: 40006ba3                 call    _port_set_backlog_EXTERNAL
F00D9778: 94102010                 mov     0x10, %o2
F00D977C: 113c0505                 sethi   %hi(paReset), %o0! id
F00D9780: d20220ec                 ld      [%o0+%lo(paReset)], %o1! SEL
F00D9784: 4000603b                 call    _objc_msgSend
F00D9788: 90100018                 mov     %i0, %o0
F00D978C: 912a2018                 sll     %o0, 24, %o0
F00D9790: 80a22000                 cmp     %o0, 0
F00D9794: 02800028                 be      loc_F00D9834
F00D9798: 113c0505                 sethi   %hi(paInitaudiohardw), %o0! id
F00D979C: d20220e8                 ld      [%o0+%lo(paInitaudiohardw)], %o1! SEL
F00D97A0: 40006034                 call    _objc_msgSend
F00D97A4: 90100018                 mov     %i0, %o0
F00D97A8: 113c0504                 sethi   %hi(paConfigtable_0), %o0! id
F00D97AC: d2022310                 ld      [%o0+%lo(paConfigtable_0)], %o1! SEL
F00D97B0: 40006030                 call    _objc_msgSend
F00D97B4: 9010001a                 mov     %i2, %o0
F00D97B8: 80a22000                 cmp     %o0, 0
F00D97BC: 12800005                 bne     loc_F00D97D0
F00D97C0: 133c0504                 sethi   -0xFEBF000, %o1
F00D97C4: 113c03f0                 sethi   %hi(aAudioNoConfigt), %o0! "Audio: no configTable\n"
F00D97C8: 10800025                 ba      loc_F00D985C
F00D97CC: 90122220                 bset    %lo(aAudioNoConfigt), %o0! "Audio: no configTable\n"
F00D97D0: d20260e8                 ld      [%o1+0xE8], %o1! SEL
F00D97D4: 153c03f0                 sethi   %hi(aServerName), %o2! "Server Name"
F00D97D8: 40006026                 call    _objc_msgSend
F00D97DC: 9412a238                 bset    %lo(aServerName), %o2! "Server Name"
F00D97E0: a0100008                 mov     %o0, %l0
F00D97E4: 90100012                 mov     %l2, %o0! __s
F00D97E8: 7ffcb714                 call    _strlen
F00D97EC: a207bee8                 add     %fp, var_118, %l1
F00D97F0: 94102100                 mov     0x100, %o2
F00D97F4: 94228008                 sub     %o2, %o0, %o2! __n
F00D97F8: 90100011                 mov     %l1, %o0! __dst
F00D97FC: 7ffcb848                 call    _strncpy
F00D9800: 92100010                 mov     %l0, %o1! __s2
F00D9804: 90100011                 mov     %l1, %o0! name
F00D9808: 7ffcae9c                 call    _strcat
F00D980C: 92100012                 mov     %l2, %o1
F00D9810: 40006153                 call    _objc_lookUpClass
F00D9814: 90100011                 mov     %l1, %o0
F00D9818: 94920000                 orcc    %o0, %g0, %o2
F00D981C: 12800008                 bne     loc_F00D983C
F00D9820: 113c0505                 sethi   -0xFEBEC00, %o0
F00D9824: 113c03f090122248         set     aAudioNoKernelS, %o0! "Audio: no kernel server instance class "...
F00D982C: 7fffb232                 call    _IOLog
F00D9830: 92100011                 mov     %l1, %o1
F00D9834: 108000a2                 ba      locret_F00D9ABC
F00D9838: b0102000                 mov     0, %i0
F00D983C: d20220e4                 ld      [%o0+0xE4], %o1! SEL
F00D9840: 4000600c                 call    _objc_msgSend
F00D9844: 9010000a                 mov     %o2, %o0
F00D9848: 80a22000                 cmp     %o0, 0
F00D984C: 12800007                 bne     loc_F00D9868
F00D9850: 01000000                 nop
F00D9854: 113c03f090122278         set     aAudioNoKernelS_0, %o0! "Audio: no kernel server instance\n"
F00D985C: 7fffb226                 call    _IOLog
F00D9860: b0102000                 mov     0, %i0
F00D9864: 30800096                 ba,a    locret_F00D9ABC
F00D9868: 4000101c                 call    _audioKernServInit
F00D986C: 01000000                 nop
F00D9870: 4000239b                 call    _audio_makeIMuLawTab
F00D9874: 01000000                 nop
F00D9878: 7fffb1ae                 call    _IOMalloc
F00D987C: 90102020                 mov     0x20, %o0 ! ' '
F00D9880: d0262174                 st      %o0, [%i0+0x174]
F00D9884: 113c0506                 sethi   %hi(paIoaudio), %o0
F00D9888: f40222d4                 ld      [%o0+%lo(paIoaudio)], %i2
F00D988C: 113c0505                 sethi   %hi(paInstance_0), %o0! id
F00D9890: d20220e0                 ld      [%o0+%lo(paInstance_0)], %o1! SEL
F00D9894: 40005ff7                 call    _objc_msgSend
F00D9898: 9010001a                 mov     %i2, %o0
F00D989C: 80a22000                 cmp     %o0, 0
F00D98A0: 02800004                 be      loc_F00D98B0
F00D98A4: 113c03f0                 sethi   %hi(aAudioReplacing), %o0! "Audio: replacing previously registered "...
F00D98A8: 7fffb213                 call    _IOLog
F00D98AC: 901222a0                 bset    %lo(aAudioReplacing), %o0! "Audio: replacing previously registered "...
F00D98B0: 9010001a                 mov     %i2, %o0! id
F00D98B4: 133c0505                 sethi   %hi(paSetinstance), %o1
F00D98B8: d20260dc                 ld      [%o1+%lo(paSetinstance)], %o1! SEL
F00D98BC: 40005fed                 call    _objc_msgSend
F00D98C0: 94100018                 mov     %i0, %o2
F00D98C4: 113c0506                 sethi   %hi(paAudiochannel), %o0
F00D98C8: e40222d0                 ld      [%o0+%lo(paAudiochannel)], %l2
F00D98CC: 113c0503                 sethi   %hi(paAlloc), %o0
F00D98D0: e60223f0                 ld      [%o0+%lo(paAlloc)], %l3
F00D98D4: 90100012                 mov     %l2, %o0! id
F00D98D8: 40005fe6                 call    _objc_msgSend
F00D98DC: 92100013                 mov     %l3, %o1
F00D98E0: 94100018                 mov     %i0, %o2
F00D98E4: 133c0505                 sethi   %hi(paInitondeviceRe), %o1! SEL
F00D98E8: e20260d8                 ld      [%o1+%lo(paInitondeviceRe)], %l1
F00D98EC: 96102001                 mov     1, %o3
F00D98F0: 40005fe0                 call    _objc_msgSend
F00D98F4: 92100011                 mov     %l1, %o1
F00D98F8: 94100008                 mov     %o0, %o2
F00D98FC: d4262128                 st      %o2, [%i0+0x128]
F00D9900: 133c0505                 sethi   %hi(paAddchannel), %o1! SEL
F00D9904: e00260d4                 ld      [%o1+%lo(paAddchannel)], %l0
F00D9908: 9010001a                 mov     %i2, %o0! id
F00D990C: 40005fd9                 call    _objc_msgSend
F00D9910: 92100010                 mov     %l0, %o1! SEL
F00D9914: 90100012                 mov     %l2, %o0! id
F00D9918: 40005fd6                 call    _objc_msgSend
F00D991C: 92100013                 mov     %l3, %o1
F00D9920: 92100011                 mov     %l1, %o1! SEL
F00D9924: 94100018                 mov     %i0, %o2
F00D9928: 40005fd2                 call    _objc_msgSend
F00D992C: 96102000                 mov     0, %o3
F00D9930: 94100008                 mov     %o0, %o2
F00D9934: d426212c                 st      %o2, [%i0+0x12C]
F00D9938: 9010001a                 mov     %i2, %o0! id
F00D993C: 40005fcd                 call    _objc_msgSend
F00D9940: 92100010                 mov     %l0, %o1! SEL
F00D9944: 113c0505                 sethi   %hi(paSetlocalchanne), %o0
F00D9948: e00220d0                 ld      [%o0+%lo(paSetlocalchanne)], %l0
F00D994C: 94102000                 mov     0, %o2
F00D9950: d0062128                 ld      [%i0+0x128], %o0! id
F00D9954: 40005fc7                 call    _objc_msgSend
F00D9958: 92100010                 mov     %l0, %o1
F00D995C: 92100010                 mov     %l0, %o1! SEL
F00D9960: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9964: 40005fc3                 call    _objc_msgSend
F00D9968: 94102000                 mov     0, %o2
F00D996C: 7ffe3651                 call    _task_self
F00D9970: 01000000                 nop
F00D9974: 40006940                 call    _port_set_allocate_EXTERNAL
F00D9978: 9207bee4                 add     %fp, var_11C, %o1
F00D997C: 92920000                 orcc    %o0, %g0, %o1
F00D9980: 02800004                 be      loc_F00D9990
F00D9984: 113c03f0                 sethi   %hi(aAudioPortSetAl), %o0! "Audio: port_set_allocate: %d\n"
F00D9988: 7fffb1db                 call    _IOLog
F00D998C: 90122148                 bset    %lo(aAudioPortSetAl), %o0! "Audio: port_set_allocate: %d\n"
F00D9990: 90100018                 mov     %i0, %o0! id
F00D9994: d407bee4                 ld      [%fp+var_11C], %o2
F00D9998: 92100014                 mov     %l4, %o1! SEL
F00D999C: 40005fb5                 call    _objc_msgSend
F00D99A0: d4262138                 st      %o2, [%i0+0x138]
F00D99A4: e0062138                 ld      [%i0+0x138], %l0
F00D99A8: 7ffe3642                 call    _task_self
F00D99AC: a2100008                 mov     %o0, %l1
F00D99B0: 92100010                 mov     %l0, %o1
F00D99B4: 400068ed                 call    _port_set_add_EXTERNAL
F00D99B8: 94100011                 mov     %l1, %o2
F00D99BC: 80a22000                 cmp     %o0, 0
F00D99C0: 02800004                 be      loc_F00D99D0
F00D99C4: 113c03f0                 sethi   %hi(aAudioPortSetAd), %o0! "Audio: port_set_add\n"
F00D99C8: 7fffb1cb                 call    _IOLog
F00D99CC: 90122130                 bset    %lo(aAudioPortSetAd), %o0! "Audio: port_set_add\n"
F00D99D0: 7ffe3638                 call    _task_self
F00D99D4: 01000000                 nop
F00D99D8: 40006862                 call    _port_allocate_EXTERNAL
F00D99DC: 9207bee4                 add     %fp, var_11C, %o1
F00D99E0: 80a22000                 cmp     %o0, 0
F00D99E4: 02800004                 be      loc_F00D99F4
F00D99E8: 113c03f0                 sethi   %hi(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00D99EC: 7fffb1c2                 call    _IOLog
F00D99F0: 90122100                 bset    %lo(aAudioPortAlloc), %o0! "Audio: port_allocate"
F00D99F4: e007bee4                 ld      [%fp+var_11C], %l0
F00D99F8: e2062138                 ld      [%i0+0x138], %l1
F00D99FC: 7ffe362d                 call    _task_self
F00D9A00: e0262134                 st      %l0, [%i0+0x134]
F00D9A04: 92100011                 mov     %l1, %o1
F00D9A08: 400068d8                 call    _port_set_add_EXTERNAL
F00D9A0C: 94100010                 mov     %l0, %o2
F00D9A10: 80a22000                 cmp     %o0, 0
F00D9A14: 22800006                 be,a    loc_F00D9A2C
F00D9A18: 92102001                 mov     1, %o1
F00D9A1C: 113c03f0                 sethi   %hi(aAudioPortSetAd), %o0! "Audio: port_set_add\n"
F00D9A20: 7fffb1b5                 call    _IOLog
F00D9A24: 90122130                 bset    %lo(aAudioPortSetAd), %o0! "Audio: port_set_add\n"
F00D9A28: 92102001                 mov     1, %o1! SEL
F00D9A2C: d0062134                 ld      [%i0+0x134], %o0
F00D9A30: 7fffc21e                 call    _IOConvertPort
F00D9A34: 94102000                 mov     0, %o2
F00D9A38: d0262134                 st      %o0, [%i0+0x134]
F00D9A3C: 113c0506                 sethi   %hi(paAudiocommand), %o0
F00D9A40: d00222cc                 ld      [%o0+%lo(paAudiocommand)], %o0! id
F00D9A44: 40005f8b                 call    _objc_msgSend
F00D9A48: 92100013                 mov     %l3, %o1
F00D9A4C: 133c0506                 sethi   %hi(paInitport), %o1
F00D9A50: d2026068                 ld      [%o1+%lo(paInitport)], %o1! SEL
F00D9A54: 40005f87                 call    _objc_msgSend
F00D9A58: d4062134                 ld      [%i0+0x134], %o2
F00D9A5C: d0262130                 st      %o0, [%i0+0x130]
F00D9A60: 90100018                 mov     %i0, %o0! id
F00D9A64: 133c0505                 sethi   %hi(paSettimeout), %o1
F00D9A68: d202618c                 ld      [%o1+%lo(paSettimeout)], %o1! SEL
F00D9A6C: 40005f81                 call    _objc_msgSend
F00D9A70: 94103fff                 mov     -1, %o2
F00D9A74: 113c035c90122228         set     sub_F00D7228, %o0
F00D9A7C: 7fffc191                 call    _IOForkThread
F00D9A80: 92100018                 mov     %i0, %o1
F00D9A84: a0100008                 mov     %o0, %l0
F00D9A88: 7fffc1c8                 call    _IOSetThreadPolicy
F00D9A8C: 92102002                 mov     2, %o1
F00D9A90: 90100010                 mov     %l0, %o0
F00D9A94: 7fffc1b6                 call    _IOSetThreadPriority
F00D9A98: 9210201e                 mov     0x1E, %o1
F00D9A9C: 113c035c901223bc         set     sub_F00D73BC, %o0
F00D9AA4: 7fffc187                 call    _IOForkThread
F00D9AA8: 92100018                 mov     %i0, %o1
F00D9AAC: 113c0504                 sethi   %hi(paRegisterdevice), %o0! id
F00D9AB0: d202225c                 ld      [%o0+%lo(paRegisterdevice)], %o1! SEL
F00D9AB4: 40005f6f                 call    _objc_msgSend
F00D9AB8: 90100018                 mov     %i0, %o0
F00D9ABC: 81c7e008                 ret
F00D9AC0: 81e80000                 restore
