F00D78D4: 9de3bf90                 save    %sp, -0x70, %sp
F00D78D8: 113c0505                 sethi   %hi(paIsinputactive_0), %o0! id
F00D78DC: d2022210                 ld      [%o0+%lo(paIsinputactive_0)], %o1! SEL
F00D78E0: 400067e4                 call    _objc_msgSend
F00D78E4: 90100018                 mov     %i0, %o0
F00D78E8: 912a2018                 sll     %o0, 24, %o0
F00D78EC: 80a22000                 cmp     %o0, 0
F00D78F0: 1280000e                 bne     locret_F00D7928
F00D78F4: 113c0505                 sethi   %hi(paIsoutputactive_0), %o0! id
F00D78F8: d202220c                 ld      [%o0+%lo(paIsoutputactive_0)], %o1! SEL
F00D78FC: 400067dd                 call    _objc_msgSend
F00D7900: 90100018                 mov     %i0, %o0
F00D7904: 912a2018                 sll     %o0, 24, %o0
F00D7908: 80a22000                 cmp     %o0, 0
F00D790C: 12800007                 bne     locret_F00D7928
F00D7910: 90100018                 mov     %i0, %o0! id
F00D7914: 133c0505                 sethi   %hi(paAttempttostart), %o1
F00D7918: d2026208                 ld      [%o1+%lo(paAttempttostart)], %o1! SEL
F00D791C: 9410001a                 mov     %i2, %o2
F00D7920: 400067d4                 call    _objc_msgSend
F00D7924: 96102000                 mov     0, %o3
F00D7928: 81c7e008                 ret
F00D792C: 81e80000                 restore
