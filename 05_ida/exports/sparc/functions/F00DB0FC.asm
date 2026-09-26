F00DB0FC: 9de3bf90                 save    %sp, -0x70, %sp
F00DB100: 92102000                 mov     0, %o1
F00DB104: d006e01c                 ld      [%i3+0x1C], %o0
F00DB108: 7fffbc68                 call    _IOConvertPort
F00DB10C: 94102001                 mov     1, %o2
F00DB110: 92102000                 mov     0, %o1
F00DB114: a0100008                 mov     %o0, %l0
F00DB118: d0062010                 ld      [%i0+0x10], %o0
F00DB11C: 7fffbc63                 call    _IOConvertPort
F00DB120: 94102001                 mov     1, %o2
F00DB124: d206201c                 ld      [%i0+0x1C], %o1
F00DB128: 80a26000                 cmp     %o1, 0
F00DB12C: 12800015                 bne     loc_F00DB180
F00DB130: 92100008                 mov     %o0, %o1
F00DB134: 80a6a004                 cmp     %i2, 4
F00DB138: 12800007                 bne     loc_F00DB154
F00DB13C: 90100010                 mov     %l0, %o0
F00DB140: d006e038                 ld      [%i3+0x38], %o0
F00DB144: 80a22000                 cmp     %o0, 0
F00DB148: 32800002                 bne,a   loc_F00DB150
F00DB14C: b4102006                 mov     6, %i2
F00DB150: 90100010                 mov     %l0, %o0
F00DB154: d6062018                 ld      [%i0+0x18], %o3
F00DB158: 94100008                 mov     %o0, %o2
F00DB15C: d806e014                 ld      [%i3+0x14], %o4
F00DB160: 400026e4                 call    __NXAudioReplyStreamStatus
F00DB164: 9a10001a                 mov     %i2, %o5
F00DB168: 92920000                 orcc    %o0, %g0, %o1
F00DB16C: 02800023                 be      locret_F00DB1F8
F00DB170: 113c03f1                 sethi   %hi(aAsReplystreams), %o0! "AS: replyStreamStatus returns %d\n"
F00DB174: 7fffabe0                 call    _IOLog
F00DB178: 90122030                 bset    %lo(aAsReplystreams), %o0! "AS: replyStreamStatus returns %d\n"
F00DB17C: 3080001f                 ba,a    locret_F00DB1F8
F00DB180: 113c0505                 sethi   %hi(paCreatesndreply), %o0! id
F00DB184: d2022078                 ld      [%o0+%lo(paCreatesndreply)], %o1! SEL
F00DB188: 400059ba                 call    _objc_msgSend
F00DB18C: 90100018                 mov     %i0, %o0
F00DB190: 80a6a000                 cmp     %i2, 0
F00DB194: 12800008                 bne     loc_F00DB1B4
F00DB198: 80a6a001                 cmp     %i2, 1
F00DB19C: d0062034                 ld      [%i0+0x34], %o0
F00DB1A0: d406e014                 ld      [%i3+0x14], %o2
F00DB1A4: 40001911                 call    _audio_snd_reply_started
F00DB1A8: 92100010                 mov     %l0, %o1
F00DB1AC: 10800010                 ba      loc_F00DB1EC
F00DB1B0: d0062034                 ld      [%i0+0x34], %o0
F00DB1B4: 12800008                 bne     loc_F00DB1D4
F00DB1B8: 80a6a005                 cmp     %i2, 5
F00DB1BC: d0062034                 ld      [%i0+0x34], %o0
F00DB1C0: d406e014                 ld      [%i3+0x14], %o2
F00DB1C4: 40001915                 call    _audio_snd_reply_completed
F00DB1C8: 92100010                 mov     %l0, %o1
F00DB1CC: 10800008                 ba      loc_F00DB1EC
F00DB1D0: d0062034                 ld      [%i0+0x34], %o0
F00DB1D4: 12800006                 bne     loc_F00DB1EC
F00DB1D8: d0062034                 ld      [%i0+0x34], %o0
F00DB1DC: d406e014                 ld      [%i3+0x14], %o2
F00DB1E0: 400018f6                 call    _audio_snd_reply_overflow
F00DB1E4: 92100010                 mov     %l0, %o1
F00DB1E8: d0062034                 ld      [%i0+0x34], %o0
F00DB1EC: 92102021                 mov     0x21, %o1 ! '!'
F00DB1F0: 7ffe2ab9                 call    _msg_send
F00DB1F4: 941023e8                 mov     0x3E8, %o2
F00DB1F8: 81c7e008                 ret
F00DB1FC: 81e80000                 restore
