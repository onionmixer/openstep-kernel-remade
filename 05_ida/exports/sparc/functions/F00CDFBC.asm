F00CDFBC: 9de3bf90                 save    %sp, -0x70, %sp
F00CDFC0: 90100018                 mov     %i0, %o0! id
F00CDFC4: 133c0505                 sethi   %hi(paAllocsdbuf), %o1
F00CDFC8: d20263d4                 ld      [%o1+%lo(paAllocsdbuf)], %o1! SEL
F00CDFCC: 40008e29                 call    _objc_msgSend
F00CDFD0: 94102000                 mov     0, %o2
F00CDFD4: a0100008                 mov     %o0, %l0
F00CDFD8: 90102005                 mov     5, %o0
F00CDFDC: d0240000                 st      %o0, [%l0]
F00CDFE0: 90100018                 mov     %i0, %o0! id
F00CDFE4: 133c0505                 sethi   %hi(paEnqueuesdbuf), %o1
F00CDFE8: 94100010                 mov     %l0, %o2
F00CDFEC: d8042020                 ld      [%l0+0x20], %o4
F00CDFF0: 17200000                 sethi   0x80000000, %o3
F00CDFF4: d20263d0                 ld      [%o1+%lo(paEnqueuesdbuf)], %o1! SEL
F00CDFF8: 962b000b                 andn    %o4, %o3, %o3
F00CDFFC: 40008e1d                 call    _objc_msgSend
F00CE000: d6242020                 st      %o3, [%l0+0x20]
F00CE004: 90100018                 mov     %i0, %o0! id
F00CE008: 133c0505                 sethi   %hi(paFreesdbuf), %o1
F00CE00C: d20263cc                 ld      [%o1+%lo(paFreesdbuf)], %o1! SEL
F00CE010: 40008e18                 call    _objc_msgSend
F00CE014: 94100010                 mov     %l0, %o2
F00CE018: 81c7e008                 ret
F00CE01C: 81e80000                 restore
