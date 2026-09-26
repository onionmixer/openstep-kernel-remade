F00D95F0: 9de3bf90                 save    %sp, -0x70, %sp
F00D95F4: 113c04bb                 sethi   %hi(unk_F012EEFC), %o0
F00D95F8: 932ea018                 sll     %i2, 24, %o1
F00D95FC: d04a22fc                 ldsb    [%o0+%lo(unk_F012EEFC)], %o0
F00D9600: 933a6018                 sra     %o1, 24, %o1
F00D9604: 80a24008                 cmp     %o1, %o0
F00D9608: 02800032                 be      locret_F00D96D0
F00D960C: 80a26000                 cmp     %o1, 0
F00D9610: 02800023                 be      loc_F00D969C
F00D9614: 133c0505                 sethi   %hi(paDescriptorsize), %o1
F00D9618: d0062128                 ld      [%i0+0x128], %o0! id
F00D961C: 153c04bb                 sethi   %hi(dword_F012EF00), %o2
F00D9620: d20261a4                 ld      [%o1+%lo(paDescriptorsize)], %o1! SEL
F00D9624: 40006093                 call    _objc_msgSend
F00D9628: c022a300                 clr     [%o2+%lo(dword_F012EF00)]
F00D962C: 253c04bb                 sethi   %hi(dword_F012EF04), %l2
F00D9630: d024a304                 st      %o0, [%l2+%lo(dword_F012EF04)]
F00D9634: 113c0505                 sethi   %hi(paInterruptclear), %o0! id
F00D9638: d20220f0                 ld      [%o0+%lo(paInterruptclear)], %o1! SEL
F00D963C: 4000608d                 call    _objc_msgSend
F00D9640: 90100018                 mov     %i0, %o0
F00D9644: 133c04bb                 sethi   %hi(dword_F012EF08), %o1
F00D9648: d0226308                 st      %o0, [%o1+%lo(dword_F012EF08)]
F00D964C: d0062128                 ld      [%i0+0x128], %o0! id
F00D9650: 133c0505                 sethi   %hi(paChannelbuffer), %o1! SEL
F00D9654: 40006087                 call    _objc_msgSend
F00D9658: d20261ac                 ld      [%o1+%lo(paChannelbuffer)], %o1
F00D965C: a2100008                 mov     %o0, %l1
F00D9660: d0062128                 ld      [%i0+0x128], %o0! id
F00D9664: 133c0505                 sethi   %hi(paLocalchannel), %o1
F00D9668: d20261a8                 ld      [%o1+%lo(paLocalchannel)], %o1! SEL
F00D966C: 153c0505                 sethi   %hi(paStartdmaforcha), %o2
F00D9670: 40006080                 call    _objc_msgSend
F00D9674: e002a1a0                 ld      [%o2+%lo(paStartdmaforcha)], %l0
F00D9678: 94100008                 mov     %o0, %o2
F00D967C: 90100018                 mov     %i0, %o0! id
F00D9680: 92100010                 mov     %l0, %o1! SEL
F00D9684: 96102001                 mov     1, %o3
F00D9688: da04a304                 ld      [%l2+0x304], %o5
F00D968C: 40006079                 call    _objc_msgSend
F00D9690: 98100011                 mov     %l1, %o4
F00D9694: 1080000e                 ba      loc_F00D96CC
F00D9698: 113c04bb                 sethi   -0xFED1400, %o0
F00D969C: d0062128                 ld      [%i0+0x128], %o0! id
F00D96A0: 133c0505                 sethi   %hi(paLocalchannel), %o1
F00D96A4: d20261a8                 ld      [%o1+%lo(paLocalchannel)], %o1! SEL
F00D96A8: 153c0505                 sethi   %hi(paStopdmaforchan), %o2
F00D96AC: 40006071                 call    _objc_msgSend
F00D96B0: e002a184                 ld      [%o2+%lo(paStopdmaforchan)], %l0
F00D96B4: 94100008                 mov     %o0, %o2
F00D96B8: 90100018                 mov     %i0, %o0! id
F00D96BC: 92100010                 mov     %l0, %o1! SEL
F00D96C0: 4000606c                 call    _objc_msgSend
F00D96C4: 96102001                 mov     1, %o3
F00D96C8: 113c04bb                 sethi   -0xFED1400, %o0
F00D96CC: f42a22fc                 stb     %i2, [%o0+0x2FC]
F00D96D0: 81c7e008                 ret
F00D96D4: 81e80000                 restore
