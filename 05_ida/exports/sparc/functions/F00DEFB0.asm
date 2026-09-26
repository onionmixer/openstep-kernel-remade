F00DEFB0: 9de3bf98                 save    %sp, -0x68, %sp
F00DEFB4: 80a62000                 cmp     %i0, 0
F00DEFB8: 12800004                 bne     loc_F00DEFC8
F00DEFBC: c026c000                 clr     [%i3]
F00DEFC0: 10800011                 ba      locret_F00DF004
F00DEFC4: b01020ca                 mov     0xCA, %i0
F00DEFC8: 113c0505                 sethi   %hi(paAudiodevice), %o0! id
F00DEFCC: d2022224                 ld      [%o0+%lo(paAudiodevice)], %o1! SEL
F00DEFD0: 40004a28                 call    _objc_msgSend
F00DEFD4: 90100018                 mov     %i0, %o0! id
F00DEFD8: 133c0504                 sethi   %hi(paGetvaluesCount), %o1
F00DEFDC: 9410001a                 mov     %i2, %o2
F00DEFE0: 9610001b                 mov     %i3, %o3
F00DEFE4: 98100019                 mov     %i1, %o4
F00DEFE8: d20263e0                 ld      [%o1+%lo(paGetvaluesCount)], %o1! SEL
F00DEFEC: 40004a21                 call    _objc_msgSend
F00DEFF0: 9a100018                 mov     %i0, %o5
F00DEFF4: 912a2018                 sll     %o0, 24, %o0
F00DEFF8: 80a00008                 cmp     %g0, %o0
F00DEFFC: b0403fff                 addc    %g0, -1, %i0
F00DF000: b00e20d2                 and     %i0, 0xD2, %i0
F00DF004: 81c7e008                 ret
F00DF008: 81e80000                 restore
