F00A4864: 9de3bf98                 save    %sp, -0x68, %sp
F00A4868: 113c0464                 sethi   %hi(_phys_avail), %o0
F00A486C: e0022394                 ld      [%o0+%lo(_phys_avail)], %l0
F00A4870: 80a42000                 cmp     %l0, 0
F00A4874: 0280000a                 be      loc_F00A489C
F00A4878: 80a62000                 cmp     %i0, 0
F00A487C: d0042004                 ld      [%l0+4], %o0
F00A4880: 7fffffd9                 call    _insert_in_mem_regions
F00A4884: d204200c                 ld      [%l0+0xC], %o1
F00A4888: e0042010                 ld      [%l0+0x10], %l0
F00A488C: 80a42000                 cmp     %l0, 0
F00A4890: 32bffffc                 bne,a   loc_F00A4880
F00A4894: d0042004                 ld      [%l0+4], %o0
F00A4898: 80a62000                 cmp     %i0, 0
F00A489C: 0280002a                 be      locret_F00A4944
F00A48A0: 113c04f0                 sethi   %hi(_mem_size), %o0
F00A48A4: d2022108                 ld      [%o0+%lo(_mem_size)], %o1
F00A48A8: 80a60009                 cmp     %i0, %o1
F00A48AC: 1a800026                 bcc     locret_F00A4944
F00A48B0: 153c04f4                 sethi   %hi(_num_regions), %o2
F00A48B4: f0222108                 st      %i0, [%o0+%lo(_mem_size)]
F00A48B8: d002a330                 ld      [%o2+%lo(_num_regions)], %o0
F00A48BC: 98a24018                 subcc   %o1, %i0, %o4
F00A48C0: 932a2003                 sll     %o0, 3, %o1
F00A48C4: 92224008                 sub     %o1, %o0, %o1
F00A48C8: 932a6002                 sll     %o1, 2, %o1
F00A48CC: 113c04f390122014         set     dword_F013CC14, %o0
F00A48D4: 0280001c                 be      locret_F00A4944
F00A48D8: 92024008                 add     %o1, %o0, %o1
F00A48DC: 8402201c                 add     %o0, 0x1C, %g2
F00A48E0: 9a10000a                 mov     %o2, %o5
F00A48E4: 94026018                 add     %o1, 0x18, %o2
F00A48E8: 80a24002                 cmp     %o1, %g2
F00A48EC: 0a800016                 bcs     locret_F00A4944
F00A48F0: 01000000                 nop
F00A48F4: d6028000                 ld      [%o2], %o3
F00A48F8: d002bffc                 ld      [%o2-4], %o0
F00A48FC: 9022c008                 sub     %o3, %o0, %o0
F00A4900: 80a2000c                 cmp     %o0, %o4
F00A4904: 3880000a                 bgu,a   loc_F00A492C
F00A4908: 9022c00c                 sub     %o3, %o4, %o0
F00A490C: 98230008                 sub     %o4, %o0, %o4
F00A4910: c022bff8                 clr     [%o2-8]
F00A4914: c022bffc                 clr     [%o2-4]
F00A4918: d0036330                 ld      [%o5+0x330], %o0
F00A491C: c0228000                 clr     [%o2]
F00A4920: 90023fff                 inc     -1, %o0
F00A4924: 10800004                 ba      loc_F00A4934
F00A4928: d0236330                 st      %o0, [%o5+0x330]
F00A492C: d0228000                 st      %o0, [%o2]
F00A4930: 98102000                 mov     0, %o4
F00A4934: 9402bfe4                 inc     -0x1C, %o2
F00A4938: 80a32000                 cmp     %o4, 0
F00A493C: 12bfffeb                 bne     loc_F00A48E8
F00A4940: 92027fe4                 inc     -0x1C, %o1
F00A4944: 81c7e008                 ret
F00A4948: 81e80000                 restore
