F00DF00C: 9de3bf98                 save    %sp, -0x68, %sp
F00DF010: 80a62000                 cmp     %i0, 0
F00DF014: 0280001f                 be      loc_F00DF090
F00DF018: c0274000                 clr     [%i5]
F00DF01C: 113c0505                 sethi   %hi(paAudiodevice), %o0
F00DF020: e0022224                 ld      [%o0+%lo(paAudiodevice)], %l0
F00DF024: 90100018                 mov     %i0, %o0! id
F00DF028: 40004a12                 call    _objc_msgSend
F00DF02C: 92100010                 mov     %l0, %o1
F00DF030: 133c0504                 sethi   %hi(paAcceptscontinu), %o1! SEL
F00DF034: 40004a0f                 call    _objc_msgSend
F00DF038: d20263dc                 ld      [%o1+%lo(paAcceptscontinu)], %o1! SEL
F00DF03C: 912a2018                 sll     %o0, 24, %o0
F00DF040: 913a2018                 sra     %o0, 24, %o0
F00DF044: d0264000                 st      %o0, [%i1]
F00DF048: 90100018                 mov     %i0, %o0! id
F00DF04C: 40004a09                 call    _objc_msgSend
F00DF050: 92100010                 mov     %l0, %o1
F00DF054: 9410001a                 mov     %i2, %o2
F00DF058: 133c0504                 sethi   %hi(paGetsamplingrat_0), %o1
F00DF05C: d20263d8                 ld      [%o1+%lo(paGetsamplingrat_0)], %o1! SEL
F00DF060: 40004a04                 call    _objc_msgSend
F00DF064: 9610001b                 mov     %i3, %o3
F00DF068: 90100018                 mov     %i0, %o0! id
F00DF06C: 40004a01                 call    _objc_msgSend
F00DF070: 92100010                 mov     %l0, %o1
F00DF074: 9410001c                 mov     %i4, %o2
F00DF078: 133c0504                 sethi   %hi(paGetsamplingrat), %o1
F00DF07C: d20263d4                 ld      [%o1+%lo(paGetsamplingrat)], %o1! SEL
F00DF080: 400049fc                 call    _objc_msgSend
F00DF084: 9610001d                 mov     %i5, %o3
F00DF088: 10800003                 ba      locret_F00DF094
F00DF08C: b0102000                 mov     0, %i0
F00DF090: b01020ca                 mov     0xCA, %i0
F00DF094: 81c7e008                 ret
F00DF098: 81e80000                 restore
