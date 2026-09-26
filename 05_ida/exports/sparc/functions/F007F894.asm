F007F894: 9de3bf90                 save    %sp, -0x70, %sp
F007F898: d0062004                 ld      [%i0+4], %o0
F007F89C: 80a22020                 cmp     %o0, 0x20 ! ' '
F007F8A0: 1280000c                 bne     loc_F007F8D0
F007F8A4: 90103ed0                 mov     -0x130, %o0
F007F8A8: d0060000                 ld      [%i0], %o0
F007F8AC: 80a22000                 cmp     %o0, 0
F007F8B0: 06800007                 bl      loc_F007F8CC
F007F8B4: 133c0445                 sethi   %hi(dword_F011143C), %o1
F007F8B8: d0062018                 ld      [%i0+0x18], %o0
F007F8BC: d202603c                 ld      [%o1+%lo(dword_F011143C)], %o1
F007F8C0: 80a20009                 cmp     %o0, %o1
F007F8C4: 02800005                 be      loc_F007F8D8
F007F8C8: 01000000                 nop
F007F8CC: 90103ed0                 mov     -0x130, %o0
F007F8D0: 10800024                 ba      locret_F007F960
F007F8D4: d026601c                 st      %o0, [%i1+0x1C]
F007F8D8: 7fffa027                 call    _convert_port_to_space
F007F8DC: d0062008                 ld      [%i0+8], %o0
F007F8E0: a0100008                 mov     %o0, %l0
F007F8E4: 94066044                 add     %i1, 0x44, %o2 ! 'D'
F007F8E8: 9606602c                 add     %i1, 0x2C, %o3 ! ','
F007F8EC: 98066034                 add     %i1, 0x34, %o4 ! '4'
F007F8F0: d206201c                 ld      [%i0+0x1C], %o1
F007F8F4: 9a06603c                 add     %i1, 0x3C, %o5 ! '<'
F007F8F8: d423a05c                 st      %o2, [%sp+0x70+var_14]
F007F8FC: 7fff8e8d                 call    _port_status
F007F900: 94066024                 add     %i1, 0x24, %o2 ! '$'
F007F904: d026601c                 st      %o0, [%i1+0x1C]
F007F908: 7fffa0ab                 call    _space_deallocate
F007F90C: 90100010                 mov     %l0, %o0
F007F910: d006601c                 ld      [%i1+0x1C], %o0
F007F914: 80a22000                 cmp     %o0, 0
F007F918: 12800012                 bne     locret_F007F960
F007F91C: 90102048                 mov     0x48, %o0 ! 'H'
F007F920: d0266004                 st      %o0, [%i1+4]
F007F924: 113c0445                 sethi   %hi(dword_F0111440), %o0
F007F928: d0022040                 ld      [%o0+%lo(dword_F0111440)], %o0
F007F92C: d0266020                 st      %o0, [%i1+0x20]
F007F930: 113c0445                 sethi   %hi(dword_F0111444), %o0
F007F934: d0022044                 ld      [%o0+%lo(dword_F0111444)], %o0
F007F938: d0266028                 st      %o0, [%i1+0x28]
F007F93C: 113c0445                 sethi   %hi(dword_F0111448), %o0
F007F940: d0022048                 ld      [%o0+%lo(dword_F0111448)], %o0
F007F944: d0266030                 st      %o0, [%i1+0x30]
F007F948: 113c0445                 sethi   %hi(dword_F011144C), %o0
F007F94C: d002204c                 ld      [%o0+%lo(dword_F011144C)], %o0
F007F950: d0266038                 st      %o0, [%i1+0x38]
F007F954: 113c0445                 sethi   %hi(dword_F0111450), %o0
F007F958: d0022050                 ld      [%o0+%lo(dword_F0111450)], %o0
F007F95C: d0266040                 st      %o0, [%i1+0x40]
F007F960: 81c7e008                 ret
F007F964: 81e80000                 restore
