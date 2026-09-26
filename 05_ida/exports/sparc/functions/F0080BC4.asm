F0080BC4: 9de3bf98                 save    %sp, -0x68, %sp
F0080BC8: d0062004                 ld      [%i0+4], %o0
F0080BCC: 80a22020                 cmp     %o0, 0x20 ! ' '
F0080BD0: 1280000c                 bne     loc_F0080C00
F0080BD4: 90103ed0                 mov     -0x130, %o0
F0080BD8: d0060000                 ld      [%i0], %o0
F0080BDC: 80a22000                 cmp     %o0, 0
F0080BE0: 06800007                 bl      loc_F0080BFC
F0080BE4: 133c0445                 sethi   %hi(dword_F0111700), %o1
F0080BE8: d0062018                 ld      [%i0+0x18], %o0
F0080BEC: d2026300                 ld      [%o1+%lo(dword_F0111700)], %o1
F0080BF0: 80a20009                 cmp     %o0, %o1
F0080BF4: 02800005                 be      loc_F0080C08
F0080BF8: 01000000                 nop
F0080BFC: 90103ed0                 mov     -0x130, %o0
F0080C00: 10800017                 ba      locret_F0080C5C
F0080C04: d026601c                 st      %o0, [%i1+0x1C]
F0080C08: 7fff9b5b                 call    _convert_port_to_space
F0080C0C: d0062008                 ld      [%i0+8], %o0! task
F0080C10: a0100008                 mov     %o0, %l0
F0080C14: 94066024                 add     %i1, 0x24, %o2 ! '$'! dnr_total
F0080C18: d206201c                 ld      [%i0+0x1C], %o1! name
F0080C1C: 7fff7a93                 call    _mach_port_dnrequest_info
F0080C20: 9606602c                 add     %i1, 0x2C, %o3 ! ','
F0080C24: d026601c                 st      %o0, [%i1+0x1C]
F0080C28: 7fff9be3                 call    _space_deallocate
F0080C2C: 90100010                 mov     %l0, %o0
F0080C30: d006601c                 ld      [%i1+0x1C], %o0
F0080C34: 80a22000                 cmp     %o0, 0
F0080C38: 12800009                 bne     locret_F0080C5C
F0080C3C: 90102030                 mov     0x30, %o0 ! '0'
F0080C40: d0266004                 st      %o0, [%i1+4]
F0080C44: 113c0445                 sethi   %hi(dword_F0111704), %o0
F0080C48: d0022304                 ld      [%o0+%lo(dword_F0111704)], %o0
F0080C4C: d0266020                 st      %o0, [%i1+0x20]
F0080C50: 113c0445                 sethi   %hi(dword_F0111708), %o0
F0080C54: d0022308                 ld      [%o0+%lo(dword_F0111708)], %o0
F0080C58: d0266028                 st      %o0, [%i1+0x28]
F0080C5C: 81c7e008                 ret
F0080C60: 81e80000                 restore
