F00CC1EC: 9de3bf90                 save    %sp, -0x70, %sp
F00CC1F0: 273c04cc                 sethi   %hi(dword_F01330C8), %l3
F00CC1F4: d004e0c8                 ld      [%l3+%lo(dword_F01330C8)], %o0
F00CC1F8: 80a22000                 cmp     %o0, 0
F00CC1FC: 12800022                 bne     locret_F00CC284
F00CC200: 133c0504                 sethi   %hi(paMethodfor), %o1
F00CC204: e0026240                 ld      [%o1+%lo(paMethodfor)], %l0
F00CC208: 133c0506                 sethi   %hi(paReceivepacketL), %o1! SEL
F00CC20C: d4026018                 ld      [%o1+%lo(paReceivepacketL)], %o2
F00CC210: 90100018                 mov     %i0, %o0! id
F00CC214: 40009597                 call    _objc_msgSend
F00CC218: 92100010                 mov     %l0, %o1
F00CC21C: 233c04cc                 sethi   %hi(dword_F01330CC), %l1
F00CC220: d02460cc                 st      %o0, [%l1+%lo(dword_F01330CC)]
F00CC224: 133c0506                 sethi   %hi(paSendpacketLeng), %o1! SEL
F00CC228: d4026014                 ld      [%o1+%lo(paSendpacketLeng)], %o2
F00CC22C: 90100018                 mov     %i0, %o0! id
F00CC230: 40009590                 call    _objc_msgSend
F00CC234: 92100010                 mov     %l0, %o1
F00CC238: 253c04cc                 sethi   %hi(dword_F01330D0), %l2
F00CC23C: d024a0d0                 st      %o0, [%l2+%lo(dword_F01330D0)]
F00CC240: 133c0506                 sethi   %hi(paResetandenable), %o1! SEL
F00CC244: d4026038                 ld      [%o1+%lo(paResetandenable)], %o2
F00CC248: 90100018                 mov     %i0, %o0! id
F00CC24C: 40009589                 call    _objc_msgSend
F00CC250: 92100010                 mov     %l0, %o1
F00CC254: 94100008                 mov     %o0, %o2
F00CC258: 113c04cc                 sethi   %hi(dword_F01330D4), %o0
F00CC25C: d20460cc                 ld      [%l1+%lo(dword_F01330CC)], %o1
F00CC260: 80a26000                 cmp     %o1, 0
F00CC264: 02800008                 be      locret_F00CC284
F00CC268: d42220d4                 st      %o2, [%o0+%lo(dword_F01330D4)]
F00CC26C: d004a0d0                 ld      [%l2+%lo(dword_F01330D0)], %o0
F00CC270: 80a22000                 cmp     %o0, 0
F00CC274: 02800004                 be      locret_F00CC284
F00CC278: 80a2a000                 cmp     %o2, 0
F00CC27C: 32800002                 bne,a   locret_F00CC284
F00CC280: f024e0c8                 st      %i0, [%l3+0xC8]
F00CC284: 81c7e008                 ret
F00CC288: 81e80000                 restore
