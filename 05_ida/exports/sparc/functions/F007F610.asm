F007F610: 9de3bf98                 save    %sp, -0x68, %sp
F007F614: d0062004                 ld      [%i0+4], %o0
F007F618: 80a22020                 cmp     %o0, 0x20 ! ' '
F007F61C: 1280000c                 bne     loc_F007F64C
F007F620: 90103ed0                 mov     -0x130, %o0
F007F624: d0060000                 ld      [%i0], %o0
F007F628: 80a22000                 cmp     %o0, 0
F007F62C: 06800007                 bl      loc_F007F648
F007F630: 133c0445                 sethi   %hi(dword_F011141C), %o1
F007F634: d0062018                 ld      [%i0+0x18], %o0
F007F638: d202601c                 ld      [%o1+%lo(dword_F011141C)], %o1
F007F63C: 80a20009                 cmp     %o0, %o1
F007F640: 02800005                 be      loc_F007F654
F007F644: 01000000                 nop
F007F648: 90103ed0                 mov     -0x130, %o0
F007F64C: 10800013                 ba      locret_F007F698
F007F650: d026601c                 st      %o0, [%i1+0x1C]
F007F654: 7fffa0c8                 call    _convert_port_to_space
F007F658: d0062008                 ld      [%i0+8], %o0
F007F65C: a0100008                 mov     %o0, %l0
F007F660: d206201c                 ld      [%i0+0x1C], %o1
F007F664: 7fff8ea9                 call    _port_type
F007F668: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007F66C: d026601c                 st      %o0, [%i1+0x1C]
F007F670: 7fffa151                 call    _space_deallocate
F007F674: 90100010                 mov     %l0, %o0
F007F678: d006601c                 ld      [%i1+0x1C], %o0
F007F67C: 80a22000                 cmp     %o0, 0
F007F680: 12800006                 bne     locret_F007F698
F007F684: 90102028                 mov     0x28, %o0 ! '('
F007F688: d0266004                 st      %o0, [%i1+4]
F007F68C: 113c0445                 sethi   %hi(dword_F0111420), %o0
F007F690: d0022020                 ld      [%o0+%lo(dword_F0111420)], %o0
F007F694: d0266020                 st      %o0, [%i1+0x20]
F007F698: 81c7e008                 ret
F007F69C: 81e80000                 restore
