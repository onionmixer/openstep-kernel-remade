F00BBEB8: 9de3bf98                 save    %sp, -0x68, %sp
F00BBEBC: 7fff6b6f                 call    _spl1
F00BBEC0: a2103fff                 mov     -1, %l1
F00BBEC4: a8100008                 mov     %o0, %l4
F00BBEC8: 113c04c6a0122048         set     unk_F0131848, %l0
F00BBED0: d0062018                 ld      [%i0+0x18], %o0
F00BBED4: 80a22000                 cmp     %o0, 0
F00BBED8: 0480001c                 ble     loc_F00BBF48
F00BBEDC: a6102000                 mov     0, %l3
F00BBEE0: 11000800aa122020         set     0x200020, %l5
F00BBEE8: d006203c                 ld      [%i0+0x3C], %o0
F00BBEEC: 808a0015                 btst    %l5, %o0
F00BBEF0: 02800004                 be      loc_F00BBF00
F00BBEF4: 90062018                 add     %i0, 0x18, %o0
F00BBEF8: 10800003                 ba      loc_F00BBF04
F00BBEFC: 92102000                 mov     0, %o1
F00BBF00: 92102080                 mov     0x80, %o1
F00BBF04: 7ffd829c                 call    _ndqb
F00BBF08: 01000000                 nop
F00BBF0C: a2920000                 orcc    %o0, %g0, %l1
F00BBF10: 0280000e                 be      loc_F00BBF48
F00BBF14: 01000000                 nop
F00BBF18: a404c011                 add     %l3, %l1, %l2
F00BBF1C: 80a4a800                 cmp     %l2, 0x800
F00BBF20: 1880000a                 bgu     loc_F00BBF48
F00BBF24: 90062018                 add     %i0, 0x18, %o0
F00BBF28: 92100010                 mov     %l0, %o1
F00BBF2C: 7ffd8235                 call    _q_to_b
F00BBF30: 94100011                 mov     %l1, %o2
F00BBF34: a0040011                 add     %l0, %l1, %l0
F00BBF38: d0062018                 ld      [%i0+0x18], %o0
F00BBF3C: 80a22000                 cmp     %o0, 0
F00BBF40: 14bfffea                 bg      loc_F00BBEE8
F00BBF44: a6100012                 mov     %l2, %l3
F00BBF48: 7fff6b77                 call    _splx
F00BBF4C: 90100014                 mov     %l4, %o0
F00BBF50: 80a4e000                 cmp     %l3, 0
F00BBF54: 04800013                 ble     loc_F00BBFA0
F00BBF58: 113c04c6                 sethi   %hi(unk_F0131848), %o0
F00BBF5C: a0122048                 or      %o0, %lo(unk_F0131848), %l0
F00BBF60: 9004c010                 add     %l3, %l0, %o0
F00BBF64: 80a40008                 cmp     %l0, %o0
F00BBF68: 1a80000e                 bcc     loc_F00BBFA0
F00BBF6C: 01000000                 nop
F00BBF70: 293c04fd                 sethi   %hi(_kmId), %l4
F00BBF74: 273c0504                 sethi   -0xFEBF000, %l3
F00BBF78: a4100008                 mov     %o0, %l2
F00BBF7C: d0052240                 ld      [%l4+%lo(_kmId)], %o0! id
F00BBF80: d40c0000                 ldub    [%l0], %o2
F00BBF84: d204e228                 ld      [%l3+0x228], %o1! SEL
F00BBF88: 4000d63a                 call    _objc_msgSend
F00BBF8C: 940aa07f                 and     %o2, 0x7F, %o2
F00BBF90: a0042001                 inc     %l0
F00BBF94: 80a40012                 cmp     %l0, %l2
F00BBF98: 0abffffa                 bcs     loc_F00BBF80
F00BBF9C: d0052240                 ld      [%l4+0x240], %o0! FILE *
F00BBFA0: 7fff6b36                 call    _spl1
F00BBFA4: 01000000                 nop
F00BBFA8: 80a46000                 cmp     %l1, 0
F00BBFAC: 1280000d                 bne     loc_F00BBFE0
F00BBFB0: a8100008                 mov     %o0, %l4
F00BBFB4: 7ffd81c5                 call    _getc
F00BBFB8: 90062018                 add     %i0, 0x18, %o0
F00BBFBC: 133c005a                 sethi   %hi(_ttrstrt), %o1
F00BBFC0: 940a207f                 and     %o0, 0x7F, %o2
F00BBFC4: 90126310                 or      %o1, %lo(_ttrstrt), %o0! int
F00BBFC8: 7ffd3818                 call    _timeout
F00BBFCC: 92100018                 mov     %i0, %o1
F00BBFD0: d0062040                 ld      [%i0+0x40], %o0
F00BBFD4: 90122001                 bset    1, %o0
F00BBFD8: 1080000a                 ba      loc_F00BC000
F00BBFDC: d0262040                 st      %o0, [%i0+0x40]
F00BBFE0: d0062018                 ld      [%i0+0x18], %o0
F00BBFE4: 80a22000                 cmp     %o0, 0
F00BBFE8: 04800006                 ble     loc_F00BC000
F00BBFEC: 90102004                 mov     4, %o0
F00BBFF0: 133c02ef921262b8         set     sub_F00BBEB8, %o1
F00BBFF8: 7fff77c0                 call    _callout_dispatch
F00BBFFC: 94100018                 mov     %i0, %o2
F00BC000: d4062040                 ld      [%i0+0x40], %o2
F00BC004: d20e204a                 ldub    [%i0+0x4A], %o1
F00BC008: 900abfdf                 and     %o2, -0x21, %o0
F00BC00C: d0262040                 st      %o0, [%i0+0x40]
F00BC010: 920a601f                 and     %o1, 0x1F, %o1
F00BC014: 113c042d90122360         set     _ttlowat, %o0
F00BC01C: 932a6001                 sll     %o1, 1, %o1
F00BC020: d2524008                 ldsh    [%o1+%o0], %o1
F00BC024: d0062018                 ld      [%i0+0x18], %o0
F00BC028: 80a20009                 cmp     %o0, %o1
F00BC02C: 14800013                 bg      loc_F00BC078
F00BC030: 808aa040                 btst    0x40, %o2 ! '@'
F00BC034: 02800005                 be      loc_F00BC048
F00BC038: 900abf9f                 and     %o2, -0x61, %o0
F00BC03C: d0262040                 st      %o0, [%i0+0x40]
F00BC040: 7ffd5b6a                 call    _wakeup
F00BC044: 90062018                 add     %i0, 0x18, %o0
F00BC048: d006202c                 ld      [%i0+0x2C], %o0
F00BC04C: 80a22000                 cmp     %o0, 0
F00BC050: 0280000a                 be      loc_F00BC078
F00BC054: 13000004                 sethi   0x1000, %o1
F00BC058: d4062040                 ld      [%i0+0x40], %o2
F00BC05C: 7ffd682e                 call    _selwakeup
F00BC060: 920a8009                 and     %o2, %o1, %o1
F00BC064: c026202c                 clr     [%i0+0x2C]
F00BC068: d2062040                 ld      [%i0+0x40], %o1
F00BC06C: 11000004                 sethi   0x1000, %o0
F00BC070: 902a4008                 andn    %o1, %o0, %o0
F00BC074: d0262040                 st      %o0, [%i0+0x40]
F00BC078: 7fff6b2b                 call    _splx
F00BC07C: 90100014                 mov     %l4, %o0
F00BC080: 81c7e008                 ret
F00BC084: 81e80000                 restore
