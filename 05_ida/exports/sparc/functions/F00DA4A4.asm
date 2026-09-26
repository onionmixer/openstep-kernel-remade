F00DA4A4: 9de3bf88                 save    %sp, -0x78, %sp
F00DA4A8: c027bfec                 clr     [%fp+var_14]
F00DA4AC: c027bfe8                 clr     [%fp+var_18]
F00DA4B0: e2062024                 ld      [%i0+0x24], %l1
F00DA4B4: d4046008                 ld      [%l1+8], %o2
F00DA4B8: 90062024                 add     %i0, 0x24, %o0 ! '$'
F00DA4BC: 80a2000a                 cmp     %o0, %o2
F00DA4C0: 12800004                 bne     loc_F00DA4D0
F00DA4C4: d204600c                 ld      [%l1+0xC], %o1
F00DA4C8: 10800003                 ba      loc_F00DA4D4
F00DA4CC: 9010000a                 mov     %o2, %o0
F00DA4D0: 9002a008                 add     %o2, 8, %o0
F00DA4D4: d2222004                 st      %o1, [%o0+4]
F00DA4D8: 90062024                 add     %i0, 0x24, %o0 ! '$'
F00DA4DC: 80a20009                 cmp     %o0, %o1
F00DA4E0: 12800003                 bne     loc_F00DA4EC
F00DA4E4: 90026008                 add     %o1, 8, %o0
F00DA4E8: 90100009                 mov     %o1, %o0
F00DA4EC: d4220000                 st      %o2, [%o0]
F00DA4F0: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DA4F4: d0062010                 ld      [%i0+0x10], %o0! id
F00DA4F8: 40005cde                 call    _objc_msgSend
F00DA4FC: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DA500: d006200c                 ld      [%i0+0xC], %o0! id
F00DA504: 133c0504                 sethi   %hi(paCount_0), %o1! SEL
F00DA508: 40005cda                 call    _objc_msgSend
F00DA50C: d20260b8                 ld      [%o1+%lo(paCount_0)], %o1
F00DA510: a4920000                 orcc    %o0, %g0, %l2
F00DA514: 22800056                 be,a    loc_F00DA66C
F00DA518: d0062010                 ld      [%i0+0x10], %o0
F00DA51C: d0062050                 ld      [%i0+0x50], %o0
F00DA520: 80a22000                 cmp     %o0, 0
F00DA524: 0280003f                 be      loc_F00DA620
F00DA528: 133c0505                 sethi   %hi(paDataencoding_0), %o1! SEL
F00DA52C: d0062004                 ld      [%i0+4], %o0! id
F00DA530: 40005cd0                 call    _objc_msgSend
F00DA534: d2026140                 ld      [%o1+%lo(paDataencoding_0)], %o1
F00DA538: 80a22259                 cmp     %o0, 0x259
F00DA53C: 22800018                 be,a    loc_F00DA59C
F00DA540: d0062004                 ld      [%i0+4], %o0
F00DA544: 18800006                 bgu     loc_F00DA55C
F00DA548: 80a22258                 cmp     %o0, 0x258
F00DA54C: 22800009                 be,a    loc_F00DA570
F00DA550: d0062004                 ld      [%i0+4], %o0
F00DA554: 10800029                 ba      loc_F00DA5F8
F00DA558: d0062058                 ld      [%i0+0x58], %o0
F00DA55C: 80a2225a                 cmp     %o0, 0x25A
F00DA560: 2280001d                 be,a    loc_F00DA5D4
F00DA564: d0062004                 ld      [%i0+4], %o0
F00DA568: 10800024                 ba      loc_F00DA5F8
F00DA56C: d0062058                 ld      [%i0+0x58], %o0! id
F00DA570: 133c0505                 sethi   %hi(paChannelcount_0), %o1! SEL
F00DA574: 40005cbf                 call    _objc_msgSend
F00DA578: d20261c8                 ld      [%o1+%lo(paChannelcount_0)], %o1
F00DA57C: 9607bfec                 add     %fp, var_14, %o3
F00DA580: d4044000                 ld      [%l1], %o2
F00DA584: 9807bfe8                 add     %fp, var_18, %o4
F00DA588: d2046004                 ld      [%l1+4], %o1
F00DA58C: 40001f9f                 call    _audio_linear16_peak
F00DA590: 9532a001                 srl     %o2, 1, %o2
F00DA594: 10800019                 ba      loc_F00DA5F8
F00DA598: d0062058                 ld      [%i0+0x58], %o0! id
F00DA59C: 133c0505                 sethi   %hi(paChannelcount_0), %o1! SEL
F00DA5A0: 40005cb4                 call    _objc_msgSend
F00DA5A4: d20261c8                 ld      [%o1+%lo(paChannelcount_0)], %o1
F00DA5A8: d2046004                 ld      [%l1+4], %o1
F00DA5AC: 9607bfec                 add     %fp, var_14, %o3
F00DA5B0: d4044000                 ld      [%l1], %o2
F00DA5B4: 40001fd5                 call    _audio_linear8_peak
F00DA5B8: 9807bfe8                 add     %fp, var_18, %o4
F00DA5BC: 1080000f                 ba      loc_F00DA5F8
F00DA5C0: d0062058                 ld      [%i0+0x58], %o0! id
F00DA5C4: e2262030                 st      %l1, [%i0+0x30]
F00DA5C8: d2246008                 st      %o1, [%l1+8]
F00DA5CC: 10800038                 ba      loc_F00DA6AC
F00DA5D0: d224600c                 st      %o1, [%l1+0xC]
F00DA5D4: 133c0505                 sethi   %hi(paChannelcount_0), %o1! SEL
F00DA5D8: 40005ca6                 call    _objc_msgSend
F00DA5DC: d20261c8                 ld      [%o1+%lo(paChannelcount_0)], %o1
F00DA5E0: d2046004                 ld      [%l1+4], %o1
F00DA5E4: 9607bfec                 add     %fp, var_14, %o3
F00DA5E8: d4044000                 ld      [%l1], %o2
F00DA5EC: 40001f3e                 call    _audio_mulaw8_peak
F00DA5F0: 9807bfe8                 add     %fp, var_18, %o4
F00DA5F4: d0062058                 ld      [%i0+0x58], %o0
F00DA5F8: d207bfec                 ld      [%fp+var_14], %o1
F00DA5FC: a0062060                 add     %i0, 0x60, %l0 ! '`'
F00DA600: d6062054                 ld      [%i0+0x54], %o3
F00DA604: 40002027                 call    _audio_add_peak
F00DA608: 94100010                 mov     %l0, %o2
F00DA60C: d006205c                 ld      [%i0+0x5C], %o0
F00DA610: d207bfe8                 ld      [%fp+var_18], %o1
F00DA614: d6062054                 ld      [%i0+0x54], %o3
F00DA618: 40002022                 call    _audio_add_peak
F00DA61C: 94100010                 mov     %l0, %o2
F00DA620: a0102000                 mov     0, %l0
F00DA624: 80a40012                 cmp     %l0, %l2
F00DA628: 3a800011                 bcc,a   loc_F00DA66C
F00DA62C: d0062010                 ld      [%i0+0x10], %o0
F00DA630: 293c0504                 sethi   -0xFEBF000, %l4
F00DA634: 273c0505                 sethi   -0xFEBEC00, %l3
F00DA638: d006200c                 ld      [%i0+0xC], %o0! id
F00DA63C: d20520c8                 ld      [%l4+0xC8], %o1! SEL
F00DA640: 40005c8c                 call    _objc_msgSend
F00DA644: 94100010                 mov     %l0, %o2
F00DA648: d204e09c                 ld      [%l3+0x9C], %o1! SEL
F00DA64C: a0042001                 inc     %l0
F00DA650: d6044000                 ld      [%l1], %o3
F00DA654: 40005c87                 call    _objc_msgSend
F00DA658: 94100011                 mov     %l1, %o2
F00DA65C: 80a40012                 cmp     %l0, %l2
F00DA660: 2abffff7                 bcs,a   loc_F00DA63C
F00DA664: d006200c                 ld      [%i0+0xC], %o0
F00DA668: d0062010                 ld      [%i0+0x10], %o0! id
F00DA66C: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DA670: 40005c80                 call    _objc_msgSend
F00DA674: d2026244                 ld      [%o1+%lo(paUnlock)], %o1! size_t
F00DA678: d0046004                 ld      [%l1+4], %o0! void *
F00DA67C: 7ffee9f7                 call    _bzero
F00DA680: d2062040                 ld      [%i0+0x40], %o1
F00DA684: 9206202c                 add     %i0, 0x2C, %o1 ! ','
F00DA688: d006202c                 ld      [%i0+0x2C], %o0
F00DA68C: 80a24008                 cmp     %o1, %o0
F00DA690: 22bfffcd                 be,a    loc_F00DA5C4
F00DA694: e226202c                 st      %l1, [%i0+0x2C]
F00DA698: d0062030                 ld      [%i0+0x30], %o0
F00DA69C: d024600c                 st      %o0, [%l1+0xC]
F00DA6A0: d2246008                 st      %o1, [%l1+8]
F00DA6A4: e2262030                 st      %l1, [%i0+0x30]
F00DA6A8: e2222008                 st      %l1, [%o0+8]
F00DA6AC: d0062034                 ld      [%i0+0x34], %o0
F00DA6B0: 90023fff                 inc     -1, %o0
F00DA6B4: d0262034                 st      %o0, [%i0+0x34]
F00DA6B8: 81c7e008                 ret
F00DA6BC: 81e80000                 restore
