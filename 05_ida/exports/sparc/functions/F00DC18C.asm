F00DC18C: 9de3bf80                 save    %sp, -0x80, %sp
F00DC190: d206a00c                 ld      [%i2+0xC], %o1
F00DC194: d0068000                 ld      [%i2], %o0
F00DC198: 233c04d0                 sethi   %hi(_page_mask), %l1
F00DC19C: e00460d8                 ld      [%l1+%lo(_page_mask)], %l0
F00DC1A0: a4224008                 sub     %o1, %o0, %l2
F00DC1A4: a02a0010                 andn    %o0, %l0, %l0
F00DC1A8: 7ffe7b3b                 call    _kern_serv_kernel_task_port
F00DC1AC: a6220010                 sub     %o0, %l0, %l3
F00DC1B0: 92100010                 mov     %l0, %o1
F00DC1B4: 9607bfec                 add     %fp, var_14, %o3
F00DC1B8: 9807bfe8                 add     %fp, var_18, %o4
F00DC1BC: da0460d8                 ld      [%l1+%lo(_page_mask)], %o5
F00DC1C0: 94048013                 add     %l2, %l3, %o2
F00DC1C4: 9402800d                 add     %o2, %o5, %o2
F00DC1C8: 400060bb                 call    _vm_read_EXTERNAL
F00DC1CC: 942a800d                 bclr    %o5, %o2
F00DC1D0: 92920000                 orcc    %o0, %g0, %o1
F00DC1D4: 02800004                 be      loc_F00DC1E4
F00DC1D8: 113c03f1                 sethi   %hi(aAudioVmReadRet), %o0! "Audio: vm_read returned %d\n"
F00DC1DC: 7fffa7c6                 call    _IOLog
F00DC1E0: 90122198                 bset    %lo(aAudioVmReadRet), %o0! "Audio: vm_read returned %d\n"
F00DC1E4: d007bfec                 ld      [%fp+var_14], %o0
F00DC1E8: 80a4a000                 cmp     %l2, 0
F00DC1EC: 02800035                 be      locret_F00DC2C0
F00DC1F0: a2020013                 add     %o0, %l3, %l1
F00DC1F4: 92102000                 mov     0, %o1
F00DC1F8: d006a01c                 ld      [%i2+0x1C], %o0
F00DC1FC: 7fffb82b                 call    _IOConvertPort
F00DC200: 94102001                 mov     1, %o2
F00DC204: 92102000                 mov     0, %o1
F00DC208: a0100008                 mov     %o0, %l0
F00DC20C: d0062010                 ld      [%i0+0x10], %o0
F00DC210: 7fffb826                 call    _IOConvertPort
F00DC214: 94102001                 mov     1, %o2
F00DC218: d206201c                 ld      [%i0+0x1C], %o1
F00DC21C: 80a26000                 cmp     %o1, 0
F00DC220: 1280000a                 bne     loc_F00DC248
F00DC224: 92100008                 mov     %o0, %o1
F00DC228: 90100010                 mov     %l0, %o0
F00DC22C: d6062018                 ld      [%i0+0x18], %o3
F00DC230: 94100008                 mov     %o0, %o2
F00DC234: d806a014                 ld      [%i2+0x14], %o4
F00DC238: 9a100011                 mov     %l1, %o5
F00DC23C: 400022d0                 call    __NXAudioReplyRecordedData
F00DC240: e423a05c                 st      %l2, [%sp+0x80+var_24]
F00DC244: 3080001f                 ba,a    locret_F00DC2C0
F00DC248: d0062034                 ld      [%i0+0x34], %o0
F00DC24C: 80a22000                 cmp     %o0, 0
F00DC250: 12800014                 bne     loc_F00DC2A0
F00DC254: 92100010                 mov     %l0, %o1
F00DC258: 7fffa736                 call    _IOMalloc
F00DC25C: 11000008                 sethi   0x2000, %o0
F00DC260: d0262034                 st      %o0, [%i0+0x34]
F00DC264: 92102001                 mov     1, %o1
F00DC268: d22a2003                 stb     %o1, [%o0+3]
F00DC26C: d2062034                 ld      [%i0+0x34], %o1
F00DC270: 90102018                 mov     0x18, %o0
F00DC274: d0226004                 st      %o0, [%o1+4]
F00DC278: d0062034                 ld      [%i0+0x34], %o0
F00DC27C: c0222008                 clr     [%o0+8]
F00DC280: d0062034                 ld      [%i0+0x34], %o0
F00DC284: c022200c                 clr     [%o0+0xC]
F00DC288: d0062034                 ld      [%i0+0x34], %o0
F00DC28C: c0222010                 clr     [%o0+0x10]
F00DC290: d0062034                 ld      [%i0+0x34], %o0
F00DC294: c0222014                 clr     [%o0+0x14]
F00DC298: 92100010                 mov     %l0, %o1
F00DC29C: d0062034                 ld      [%i0+0x34], %o0
F00DC2A0: 96100011                 mov     %l1, %o3
F00DC2A4: d406a014                 ld      [%i2+0x14], %o2
F00DC2A8: 40001494                 call    _audio_snd_reply_recorded_data
F00DC2AC: 98100012                 mov     %l2, %o4
F00DC2B0: 92102021                 mov     0x21, %o1 ! '!'
F00DC2B4: d0062034                 ld      [%i0+0x34], %o0
F00DC2B8: 7ffe2687                 call    _msg_send
F00DC2BC: 941023e8                 mov     0x3E8, %o2
F00DC2C0: 81c7e008                 ret
F00DC2C4: 81e80000                 restore
