F00BD244: 9de3bf90                 save    %sp, -0x70, %sp
F00BD248: 133c0504                 sethi   %hi(paReverttovgamod), %o1
F00BD24C: e002626c                 ld      [%o1+%lo(paReverttovgamod)], %l0
F00BD250: 233c04c8                 sethi   %hi(dword_F0132064), %l1
F00BD254: d0046064                 ld      [%l1+%lo(dword_F0132064)], %o0! id
F00BD258: 133c0504                 sethi   %hi(paRespondsto), %o1
F00BD25C: d2026270                 ld      [%o1+%lo(paRespondsto)], %o1! SEL
F00BD260: 4000d184                 call    _objc_msgSend
F00BD264: 94100010                 mov     %l0, %o2
F00BD268: 912a2018                 sll     %o0, 24, %o0
F00BD26C: 80a22000                 cmp     %o0, 0
F00BD270: 02800007                 be      locret_F00BD28C
F00BD274: d0046064                 ld      [%l1+%lo(dword_F0132064)], %o0! id
F00BD278: 4000d17e                 call    _objc_msgSend
F00BD27C: 92100010                 mov     %l0, %o1
F00BD280: 11000062                 sethi   0x18800, %o0
F00BD284: 4000235a                 call    _IODelay
F00BD288: 90122288                 bset    0x288, %o0
F00BD28C: 81c7e008                 ret
F00BD290: 81e80000                 restore
