F00D7228: 9de3bf80                 save    %sp, -0x80, %sp
F00D722C: a407bfe0                 add     %fp, var_20, %l2
F00D7230: 110008c8a8122325         set     0x232325, %l4
F00D7238: 273c0505                 sethi   -0xFEBEC00, %l3
F00D723C: 90102018                 mov     0x18, %o0
F00D7240: d024a004                 st      %o0, [%l2+4]
F00D7244: 113c0505                 sethi   %hi(paDeviceportset), %o0! id
F00D7248: d20220c8                 ld      [%o0+%lo(paDeviceportset)], %o1! SEL
F00D724C: 40006989                 call    _objc_msgSend
F00D7250: 90100018                 mov     %i0, %o0
F00D7254: d024a00c                 st      %o0, [%l2+0xC]
F00D7258: 113c0505                 sethi   %hi(paTimeout), %o0! id
F00D725C: d2022190                 ld      [%o0+%lo(paTimeout)], %o1! SEL
F00D7260: 40006984                 call    _objc_msgSend
F00D7264: 90100018                 mov     %i0, %o0
F00D7268: 94100008                 mov     %o0, %o2
F00D726C: 90100012                 mov     %l2, %o0
F00D7270: 7ffe3afb                 call    _msg_receive
F00D7274: 92102100                 mov     0x100, %o1
F00D7278: a2100008                 mov     %o0, %l1
F00D727C: 80a47f35                 cmp     %l1, -0xCB
F00D7280: 02800025                 be      loc_F00D7314
F00D7284: 80a46000                 cmp     %l1, 0
F00D7288: 32800039                 bne,a   loc_F00D736C
F00D728C: 113c0504                 sethi   -0xFEBF000, %o0
F00D7290: d204a014                 ld      [%l2+0x14], %o1
F00D7294: 80a24014                 cmp     %o1, %l4
F00D7298: 12800005                 bne     loc_F00D72AC
F00D729C: 80a26385                 cmp     %o1, 0x385
F00D72A0: 113c0505                 sethi   %hi(paInterruptoccur_2), %o0
F00D72A4: 1080002e                 ba      loc_F00D735C
F00D72A8: d20220c4                 ld      [%o0+%lo(paInterruptoccur_2)], %o1
F00D72AC: 12800005                 bne     loc_F00D72C0
F00D72B0: 80a26384                 cmp     %o1, 0x384
F00D72B4: 113c0505                 sethi   %hi(paInputchannel), %o0
F00D72B8: 10800006                 ba      loc_F00D72D0
F00D72BC: d2022220                 ld      [%o0+%lo(paInputchannel)], %o1
F00D72C0: 1280000c                 bne     loc_F00D72F0
F00D72C4: 80a26386                 cmp     %o1, 0x386
F00D72C8: 113c0505                 sethi   %hi(paOutputchannel), %o0! id
F00D72CC: d2022218                 ld      [%o0+%lo(paOutputchannel)], %o1! SEL
F00D72D0: 40006968                 call    _objc_msgSend
F00D72D4: 90100018                 mov     %i0, %o0! id
F00D72D8: 94100008                 mov     %o0, %o2
F00D72DC: d204e0c0                 ld      [%l3+0xC0], %o1! SEL
F00D72E0: 40006964                 call    _objc_msgSend
F00D72E4: 90100018                 mov     %i0, %o0
F00D72E8: 10bfffd6                 ba      loc_F00D7240
F00D72EC: 90102018                 mov     0x18, %o0
F00D72F0: 32800005                 bne,a   loc_F00D7304
F00D72F4: 113c03f0                 sethi   -0xFF04000, %o0
F00D72F8: 113c0505                 sethi   %hi(paCommandoccurre), %o0
F00D72FC: 10800018                 ba      loc_F00D735C
F00D7300: d20220bc                 ld      [%o0+%lo(paCommandoccurre)], %o1
F00D7304: 7fffbb7c                 call    _IOLog
F00D7308: 901222d0                 bset    0x2D0, %o0
F00D730C: 10bfffcd                 ba      loc_F00D7240
F00D7310: 90102018                 mov     0x18, %o0
F00D7314: 113c0505                 sethi   %hi(paIsinputactive_0), %o0! id
F00D7318: d2022210                 ld      [%o0+%lo(paIsinputactive_0)], %o1! SEL
F00D731C: 40006955                 call    _objc_msgSend
F00D7320: 90100018                 mov     %i0, %o0
F00D7324: 912a2018                 sll     %o0, 24, %o0
F00D7328: 80a22000                 cmp     %o0, 0
F00D732C: 3280000b                 bne,a   loc_F00D7358
F00D7330: 113c0506                 sethi   -0xFEBE800, %o0
F00D7334: 113c0505                 sethi   %hi(paIsoutputactive_0), %o0! id
F00D7338: d202220c                 ld      [%o0+%lo(paIsoutputactive_0)], %o1! SEL
F00D733C: 4000694d                 call    _objc_msgSend
F00D7340: 90100018                 mov     %i0, %o0
F00D7344: 912a2018                 sll     %o0, 24, %o0
F00D7348: 80a22000                 cmp     %o0, 0
F00D734C: 22bfffbd                 be,a    loc_F00D7240
F00D7350: 90102018                 mov     0x18, %o0
F00D7354: 113c0506                 sethi   -0xFEBE800, %o0! id
F00D7358: d20220a0                 ld      [%o0+0xA0], %o1! SEL
F00D735C: 40006945                 call    _objc_msgSend
F00D7360: 90100018                 mov     %i0, %o0
F00D7364: 10bfffb7                 ba      loc_F00D7240
F00D7368: 90102018                 mov     0x18, %o0! id
F00D736C: d2022008                 ld      [%o0+8], %o1! SEL
F00D7370: 40006940                 call    _objc_msgSend
F00D7374: 90100018                 mov     %i0, %o0! id
F00D7378: 133c0506                 sethi   %hi(paDevicekind_0), %o1
F00D737C: a0100008                 mov     %o0, %l0
F00D7380: d20261d0                 ld      [%o1+%lo(paDevicekind_0)], %o1! SEL
F00D7384: 4000693b                 call    _objc_msgSend
F00D7388: 90100018                 mov     %i0, %o0
F00D738C: 133c03f0                 sethi   %hi(aSSThreadMsgRec), %o1! "%s: %s thread: msg_receive returns %d\n"
F00D7390: 94100008                 mov     %o0, %o2
F00D7394: 901262f0                 or      %o1, %lo(aSSThreadMsgRec), %o0! "%s: %s thread: msg_receive returns %d\n"
F00D7398: 92100010                 mov     %l0, %o1
F00D739C: 7fffbb56                 call    _IOLog
F00D73A0: 96100011                 mov     %l1, %o3
F00D73A4: 7fffcb9e                 call    _IOExitThread
F00D73A8: 01000000                 nop
F00D73AC: 10bfffa5                 ba      loc_F00D7240
F00D73B0: 90102018                 mov     0x18, %o0
