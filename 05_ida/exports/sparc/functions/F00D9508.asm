F00D9508: 9de3bf90                 save    %sp, -0x70, %sp
F00D950C: 113c04bb                 sethi   %hi(unk_F012EEFC), %o0
F00D9510: 932ea018                 sll     %i2, 24, %o1
F00D9514: d04a22fc                 ldsb    [%o0+%lo(unk_F012EEFC)], %o0
F00D9518: 933a6018                 sra     %o1, 24, %o1
F00D951C: 80a24008                 cmp     %o1, %o0
F00D9520: 02800032                 be      locret_F00D95E8
F00D9524: 80a26000                 cmp     %o1, 0
F00D9528: 02800023                 be      loc_F00D95B4
F00D952C: 133c0505                 sethi   %hi(paDescriptorsize), %o1
F00D9530: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9534: 153c04bb                 sethi   %hi(dword_F012EF00), %o2
F00D9538: d20261a4                 ld      [%o1+%lo(paDescriptorsize)], %o1! SEL
F00D953C: 400060cd                 call    _objc_msgSend
F00D9540: c022a300                 clr     [%o2+%lo(dword_F012EF00)]
F00D9544: 253c04bb                 sethi   %hi(dword_F012EF04), %l2
F00D9548: d024a304                 st      %o0, [%l2+%lo(dword_F012EF04)]
F00D954C: 113c0505                 sethi   %hi(paInterruptclear), %o0! id
F00D9550: d20220f0                 ld      [%o0+%lo(paInterruptclear)], %o1! SEL
F00D9554: 400060c7                 call    _objc_msgSend
F00D9558: 90100018                 mov     %i0, %o0
F00D955C: 133c04bb                 sethi   %hi(dword_F012EF08), %o1
F00D9560: d0226308                 st      %o0, [%o1+%lo(dword_F012EF08)]
F00D9564: d006212c                 ld      [%i0+0x12C], %o0! id
F00D9568: 133c0505                 sethi   %hi(paChannelbuffer), %o1! SEL
F00D956C: 400060c1                 call    _objc_msgSend
F00D9570: d20261ac                 ld      [%o1+%lo(paChannelbuffer)], %o1
F00D9574: a2100008                 mov     %o0, %l1
F00D9578: d006212c                 ld      [%i0+0x12C], %o0! id
F00D957C: 133c0505                 sethi   %hi(paLocalchannel), %o1
F00D9580: d20261a8                 ld      [%o1+%lo(paLocalchannel)], %o1! SEL
F00D9584: 153c0505                 sethi   %hi(paStartdmaforcha), %o2
F00D9588: 400060ba                 call    _objc_msgSend
F00D958C: e002a1a0                 ld      [%o2+%lo(paStartdmaforcha)], %l0
F00D9590: 94100008                 mov     %o0, %o2
F00D9594: 90100018                 mov     %i0, %o0! id
F00D9598: 92100010                 mov     %l0, %o1! SEL
F00D959C: 96102000                 mov     0, %o3
F00D95A0: da04a304                 ld      [%l2+0x304], %o5
F00D95A4: 400060b3                 call    _objc_msgSend
F00D95A8: 98100011                 mov     %l1, %o4
F00D95AC: 1080000e                 ba      loc_F00D95E4
F00D95B0: 113c04bb                 sethi   -0xFED1400, %o0
F00D95B4: d006212c                 ld      [%i0+0x12C], %o0! id
F00D95B8: 133c0505                 sethi   %hi(paLocalchannel), %o1
F00D95BC: d20261a8                 ld      [%o1+%lo(paLocalchannel)], %o1! SEL
F00D95C0: 153c0505                 sethi   %hi(paStopdmaforchan), %o2
F00D95C4: 400060ab                 call    _objc_msgSend
F00D95C8: e002a184                 ld      [%o2+%lo(paStopdmaforchan)], %l0
F00D95CC: 94100008                 mov     %o0, %o2
F00D95D0: 90100018                 mov     %i0, %o0! id
F00D95D4: 92100010                 mov     %l0, %o1! SEL
F00D95D8: 400060a6                 call    _objc_msgSend
F00D95DC: 96102000                 mov     0, %o3
F00D95E0: 113c04bb                 sethi   -0xFED1400, %o0
F00D95E4: f42a22fc                 stb     %i2, [%o0+0x2FC]
F00D95E8: 81c7e008                 ret
F00D95EC: 81e80000                 restore
