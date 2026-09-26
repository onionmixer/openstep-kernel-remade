F00DEE98: 9de3bf98                 save    %sp, -0x68, %sp
F00DEE9C: 80a62000                 cmp     %i0, 0
F00DEEA0: 12800004                 bne     loc_F00DEEB0
F00DEEA4: 94100019                 mov     %i1, %o2
F00DEEA8: 1080001a                 ba      locret_F00DEF10
F00DEEAC: b01020ca                 mov     0xCA, %i0
F00DEEB0: 133c0505                 sethi   %hi(paCheckowner), %o1
F00DEEB4: d2026018                 ld      [%o1+%lo(paCheckowner)], %o1! SEL
F00DEEB8: 40004a6e                 call    _objc_msgSend
F00DEEBC: 90100018                 mov     %i0, %o0
F00DEEC0: 912a2018                 sll     %o0, 24, %o0
F00DEEC4: 80a22000                 cmp     %o0, 0
F00DEEC8: 12800004                 bne     loc_F00DEED8
F00DEECC: 113c0505                 sethi   -0xFEBEC00, %o0! id
F00DEED0: 10800010                 ba      locret_F00DEF10
F00DEED4: b01020c8                 mov     0xC8, %i0
F00DEED8: d2022224                 ld      [%o0+0x224], %o1! SEL
F00DEEDC: 40004a65                 call    _objc_msgSend
F00DEEE0: 90100018                 mov     %i0, %o0! id
F00DEEE4: 9410001a                 mov     %i2, %o2
F00DEEE8: 133c0504                 sethi   %hi(paSetparametersT), %o1
F00DEEEC: 9610001c                 mov     %i4, %o3
F00DEEF0: 9810001b                 mov     %i3, %o4
F00DEEF4: d20263fc                 ld      [%o1+%lo(paSetparametersT)], %o1! SEL
F00DEEF8: 40004a5e                 call    _objc_msgSend
F00DEEFC: 9a100018                 mov     %i0, %o5
F00DEF00: 912a2018                 sll     %o0, 24, %o0
F00DEF04: 80a00008                 cmp     %g0, %o0
F00DEF08: b0403fff                 addc    %g0, -1, %i0
F00DEF0C: b00e20d2                 and     %i0, 0xD2, %i0
F00DEF10: 81c7e008                 ret
F00DEF14: 81e80000                 restore
