F00DAFA8: 9de3bf90                 save    %sp, -0x70, %sp
F00DAFAC: d006201c                 ld      [%i0+0x1C], %o0
F00DAFB0: 80a22000                 cmp     %o0, 0
F00DAFB4: 32800016                 bne,a   loc_F00DB00C
F00DAFB8: d0062028                 ld      [%i0+0x28], %o0
F00DAFBC: d0062060                 ld      [%i0+0x60], %o0
F00DAFC0: 808a001b                 btst    %i3, %o0
F00DAFC4: 0280004c                 be      locret_F00DB0F4
F00DAFC8: 92102000                 mov     0, %o1
F00DAFCC: d006205c                 ld      [%i0+0x5C], %o0
F00DAFD0: 7fffbcb6                 call    _IOConvertPort
F00DAFD4: 94102001                 mov     1, %o2
F00DAFD8: a2100008                 mov     %o0, %l1
F00DAFDC: 92102000                 mov     0, %o1
F00DAFE0: d0062010                 ld      [%i0+0x10], %o0
F00DAFE4: 7fffbcb1                 call    _IOConvertPort
F00DAFE8: 94102001                 mov     1, %o2
F00DAFEC: 92100008                 mov     %o0, %o1
F00DAFF0: 90100011                 mov     %l1, %o0! id
F00DAFF4: 94100008                 mov     %o0, %o2
F00DAFF8: 98102000                 mov     0, %o4
F00DAFFC: d6062018                 ld      [%i0+0x18], %o3
F00DB000: 4000273c                 call    __NXAudioReplyStreamStatus
F00DB004: 9a10001a                 mov     %i2, %o5
F00DB008: 3080003b                 ba,a    locret_F00DB0F4
F00DB00C: 133c0504                 sethi   %hi(paLock), %o1! SEL
F00DB010: 40005a18                 call    _objc_msgSend
F00DB014: d2026000                 ld      [%o1+%lo(paLock)], %o1
F00DB018: d006202c                 ld      [%i0+0x2C], %o0
F00DB01C: a206202c                 add     %i0, 0x2C, %l1 ! ','
F00DB020: 80a44008                 cmp     %l1, %o0
F00DB024: 02800030                 be      loc_F00DB0E4
F00DB028: 113c0505                 sethi   %hi(paCreatesndreply), %o0! id
F00DB02C: d2022078                 ld      [%o0+%lo(paCreatesndreply)], %o1! SEL
F00DB030: 40005a10                 call    _objc_msgSend
F00DB034: 90100018                 mov     %i0, %o0
F00DB038: e006202c                 ld      [%i0+0x2C], %l0
F00DB03C: 80a44010                 cmp     %l1, %l0
F00DB040: 2280002a                 be,a    loc_F00DB0E8
F00DB044: d0062028                 ld      [%i0+0x28], %o0
F00DB048: a4100011                 mov     %l1, %l2
F00DB04C: d0042018                 ld      [%l0+0x18], %o0
F00DB050: 808a001b                 btst    %i3, %o0
F00DB054: 02800020                 be      loc_F00DB0D4
F00DB058: 92102000                 mov     0, %o1
F00DB05C: d004201c                 ld      [%l0+0x1C], %o0
F00DB060: 7fffbc92                 call    _IOConvertPort
F00DB064: 94102001                 mov     1, %o2
F00DB068: 80a6a002                 cmp     %i2, 2
F00DB06C: 12800008                 bne     loc_F00DB08C
F00DB070: a2100008                 mov     %o0, %l1
F00DB074: d0062034                 ld      [%i0+0x34], %o0
F00DB078: d4042014                 ld      [%l0+0x14], %o2
F00DB07C: 4000197f                 call    _audio_snd_reply_paused
F00DB080: 92100011                 mov     %l1, %o1
F00DB084: 10800011                 ba      loc_F00DB0C8
F00DB088: d0062034                 ld      [%i0+0x34], %o0
F00DB08C: 80a6a003                 cmp     %i2, 3
F00DB090: 12800008                 bne     loc_F00DB0B0
F00DB094: 80a6a004                 cmp     %i2, 4
F00DB098: d0062034                 ld      [%i0+0x34], %o0
F00DB09C: d4042014                 ld      [%l0+0x14], %o2
F00DB0A0: 40001982                 call    _audio_snd_reply_resumed
F00DB0A4: 92100011                 mov     %l1, %o1
F00DB0A8: 10800008                 ba      loc_F00DB0C8
F00DB0AC: d0062034                 ld      [%i0+0x34], %o0
F00DB0B0: 12800006                 bne     loc_F00DB0C8
F00DB0B4: d0062034                 ld      [%i0+0x34], %o0
F00DB0B8: d4042014                 ld      [%l0+0x14], %o2
F00DB0BC: 40001963                 call    _audio_snd_reply_aborted
F00DB0C0: 92100011                 mov     %l1, %o1
F00DB0C4: d0062034                 ld      [%i0+0x34], %o0
F00DB0C8: 92102021                 mov     0x21, %o1 ! '!'
F00DB0CC: 7ffe2b02                 call    _msg_send
F00DB0D0: 941023e8                 mov     0x3E8, %o2
F00DB0D4: e004203c                 ld      [%l0+0x3C], %l0
F00DB0D8: 80a48010                 cmp     %l2, %l0
F00DB0DC: 32bfffdd                 bne,a   loc_F00DB050
F00DB0E0: d0042018                 ld      [%l0+0x18], %o0
F00DB0E4: d0062028                 ld      [%i0+0x28], %o0! id
F00DB0E8: 133c0504                 sethi   %hi(paUnlock), %o1! SEL
F00DB0EC: 400059e1                 call    _objc_msgSend
F00DB0F0: d2026244                 ld      [%o1+%lo(paUnlock)], %o1
F00DB0F4: 81c7e008                 ret
F00DB0F8: 81e80000                 restore
