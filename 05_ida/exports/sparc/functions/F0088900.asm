F0088900: 9de3bf98                 save    %sp, -0x68, %sp
F0088904: 113c04f698122150         set     _vm_page_template, %o4
F008890C: c0232014                 clr     [%o4+0x14]
F0088910: c0232018                 clr     [%o4+0x18]
F0088914: c033201c                 clrh    [%o4+0x1C]
F0088918: c0232024                 clr     [%o4+0x24]
F008891C: c0232028                 clr     [%o4+0x28]
F0088920: c023202c                 clr     [%o4+0x2C]
F0088924: 84102000                 mov     0, %g2
F0088928: a2100018                 mov     %i0, %l1
F008892C: 912e6003                 sll     %i1, 3, %o0
F0088930: 90220019                 sub     %o0, %i1, %o0
F0088934: 912a2002                 sll     %o0, 2, %o0
F0088938: 9a044008                 add     %l1, %o0, %o5
F008893C: 80a4400d                 cmp     %l1, %o5
F0088940: 11000400                 sethi   0x100000, %o0
F0088944: d603201c                 ld      [%o4+0x1C], %o3
F0088948: 15000200                 sethi   0x80000, %o2
F008894C: d2032020                 ld      [%o4+0x20], %o1
F0088950: 9612e400                 bset    0x400, %o3
F0088954: d623201c                 st      %o3, [%o4+0x1C]
F0088958: 902a4008                 andn    %o1, %o0, %o0
F008895C: 13000800                 sethi   0x200000, %o1
F0088960: 922a0009                 andn    %o0, %o1, %o1
F0088964: 942a400a                 andn    %o1, %o2, %o2
F0088968: d4232020                 st      %o2, [%o4+0x20]
F008896C: 11000020                 sethi   0x8000, %o0
F0088970: 902ac008                 andn    %o3, %o0, %o0
F0088974: 13000010                 sethi   0x4000, %o1
F0088978: 922a0009                 andn    %o0, %o1, %o1
F008897C: 11000008                 sethi   0x2000, %o0
F0088980: 902a4008                 andn    %o1, %o0, %o0
F0088984: 17000004                 sethi   0x1000, %o3
F0088988: 962a000b                 andn    %o0, %o3, %o3
F008898C: d623201c                 st      %o3, [%o4+0x1C]
F0088990: 11200000                 sethi   0x80000000, %o0
F0088994: 94128008                 bset    %o0, %o2
F0088998: 11100000                 sethi   0x40000000, %o0
F008899C: 902a8008                 andn    %o2, %o0, %o0
F00889A0: 13080000                 sethi   0x20000000, %o1
F00889A4: 922a0009                 andn    %o0, %o1, %o1
F00889A8: 11040000                 sethi   0x10000000, %o0
F00889AC: 902a4008                 andn    %o1, %o0, %o0
F00889B0: 13020000                 sethi   0x8000000, %o1
F00889B4: 922a0009                 andn    %o0, %o1, %o1
F00889B8: 11010000                 sethi   0x4000000, %o0
F00889BC: 902a4008                 andn    %o1, %o0, %o0
F00889C0: 13008000                 sethi   0x2000000, %o1
F00889C4: 922a0009                 andn    %o0, %o1, %o1
F00889C8: 15004000                 sethi   0x1000000, %o2
F00889CC: 942a400a                 andn    %o1, %o2, %o2
F00889D0: 11002000                 sethi   0x800000, %o0
F00889D4: 902a8008                 andn    %o2, %o0, %o0
F00889D8: d0232020                 st      %o0, [%o4+0x20]
F00889DC: 960af7ff                 and     %o3, -0x801, %o3
F00889E0: d623201c                 st      %o3, [%o4+0x1C]
F00889E4: 113c04f6                 sethi   %hi(_vm_page_queue_free_lock), %o0
F00889E8: c02220f8                 clr     [%o0+%lo(_vm_page_queue_free_lock)]
F00889EC: 113c04f0                 sethi   %hi(_vm_page_queue_lock), %o0
F00889F0: c0222230                 clr     [%o0+%lo(_vm_page_queue_lock)]
F00889F4: 133c04f390126010         set     _vm_page_queue_free, %o0
F00889FC: d0222004                 st      %o0, [%o0+4]
F0088A00: d0226010                 st      %o0, [%o1+0x10]
F0088A04: 133c04f390126008         set     _vm_page_queue_active, %o0
F0088A0C: d0222004                 st      %o0, [%o0+4]
F0088A10: d0226008                 st      %o0, [%o1+8]
F0088A14: 133c04f090126228         set     _vm_page_queue_inactive, %o0
F0088A1C: d0222004                 st      %o0, [%o0+4]
F0088A20: 1a800011                 bcc     loc_F0088A64
F0088A24: d0226228                 st      %o0, [%o1+0x228]
F0088A28: 113c04d0                 sethi   %hi(_page_mask), %o0
F0088A2C: d80220d8                 ld      [%o0+%lo(_page_mask)], %o4
F0088A30: 94046014                 add     %l1, 0x14, %o2
F0088A34: 9638000c                 xnor    %g0, %o4, %o3
F0088A38: a204601c                 inc     0x1C, %l1
F0088A3C: d202a004                 ld      [%o2+4], %o1
F0088A40: 80a4400d                 cmp     %l1, %o5
F0088A44: d0028000                 ld      [%o2], %o0
F0088A48: 920a400b                 and     %o1, %o3, %o1
F0088A4C: 9002000c                 add     %o0, %o4, %o0
F0088A50: 900a000b                 and     %o0, %o3, %o0
F0088A54: 92224008                 sub     %o1, %o0, %o1
F0088A58: 84008009                 add     %g2, %o1, %g2
F0088A5C: 0abffff7                 bcs     loc_F0088A38
F0088A60: 9402a01c                 inc     0x1C, %o2
F0088A64: 173c0447                 sethi   %hi(_vm_page_bucket_count), %o3
F0088A68: d002e138                 ld      [%o3+%lo(_vm_page_bucket_count)], %o0
F0088A6C: 80a22000                 cmp     %o0, 0
F0088A70: 32800010                 bne,a   loc_F0088AB0
F0088A74: 233c0447                 sethi   -0xFEEE400, %l1
F0088A78: 90102001                 mov     1, %o0
F0088A7C: 133c04f4                 sethi   %hi(_page_shift), %o1
F0088A80: d2026348                 ld      [%o1+%lo(_page_shift)], %o1
F0088A84: 95308009                 srl     %g2, %o1, %o2
F0088A88: 80a2000a                 cmp     %o0, %o2
F0088A8C: 1a800008                 bcc     loc_F0088AAC
F0088A90: d022e138                 st      %o0, [%o3+%lo(_vm_page_bucket_count)]
F0088A94: 9210000b                 mov     %o3, %o1
F0088A98: d0026138                 ld      [%o1+0x138], %o0
F0088A9C: 912a2001                 sll     %o0, 1, %o0
F0088AA0: 80a2000a                 cmp     %o0, %o2
F0088AA4: 0abffffd                 bcs     loc_F0088A98
F0088AA8: d0226138                 st      %o0, [%o1+0x138]
F0088AAC: 233c0447                 sethi   -0xFEEE400, %l1
F0088AB0: d4046138                 ld      [%l1+0x138], %o2
F0088AB4: 113c04f6                 sethi   %hi(_vm_page_hash_mask), %o0
F0088AB8: 9202bfff                 add     %o2, -1, %o1
F0088ABC: 808a400a                 btst    %o2, %o1
F0088AC0: 02800005                 be      loc_F0088AD4
F0088AC4: d2222140                 st      %o1, [%o0+%lo(_vm_page_hash_mask)]
F0088AC8: 113c0447                 sethi   %hi(aVmPageBootstra), %o0! "vm_page_bootstrap: WARNING -- strange p"...
F0088ACC: 7ffe2ee3                 call    _printf
F0088AD0: 90122188                 bset    %lo(aVmPageBootstra), %o0! "vm_page_bootstrap: WARNING -- strange p"...
F0088AD4: d0046138                 ld      [%l1+0x138], %o0
F0088AD8: 92102004                 mov     4, %o1
F0088ADC: 7ffff689                 call    _vm_alloc_from_regions
F0088AE0: 912a2003                 sll     %o0, 3, %o0! void *
F0088AE4: 213c04f6                 sethi   %hi(_vm_page_buckets), %l0
F0088AE8: d2046138                 ld      [%l1+0x138], %o1! size_t
F0088AEC: d0242138                 st      %o0, [%l0+%lo(_vm_page_buckets)]
F0088AF0: 400030da                 call    _bzero
F0088AF4: 932a6003                 sll     %o1, 3, %o1
F0088AF8: 9a102000                 mov     0, %o5
F0088AFC: d0046138                 ld      [%l1+0x138], %o0
F0088B00: 80a34008                 cmp     %o5, %o0
F0088B04: 1a80000b                 bcc     loc_F0088B30
F0088B08: d4042138                 ld      [%l0+%lo(_vm_page_buckets)], %o2
F0088B0C: 96100008                 mov     %o0, %o3
F0088B10: 9210000a                 mov     %o2, %o1
F0088B14: c0226004                 clr     [%o1+4]
F0088B18: 912b6003                 sll     %o5, 3, %o0
F0088B1C: c0228008                 clr     [%o2+%o0]
F0088B20: 9a036001                 inc     %o5
F0088B24: 80a3400b                 cmp     %o5, %o3
F0088B28: 0abffffb                 bcs     loc_F0088B14
F0088B2C: 92026008                 inc     8, %o1
F0088B30: 113c0447                 sethi   %hi(_page_size), %o0
F0088B34: d202213c                 ld      [%o0+%lo(_page_size)], %o1
F0088B38: 213c0442                 sethi   %hi(_zdata_size), %l0
F0088B3C: 912a6003                 sll     %o1, 3, %o0! void *
F0088B40: 7ffff670                 call    _vm_alloc_from_regions
F0088B44: d02423f4                 st      %o0, [%l0+%lo(_zdata_size)]
F0088B48: 133c04f2                 sethi   %hi(_zdata), %o1! size_t
F0088B4C: d02263a0                 st      %o0, [%o1+%lo(_zdata)]
F0088B50: 400030c2                 call    _bzero
F0088B54: d20423f4                 ld      [%l0+%lo(_zdata_size)], %o1
F0088B58: 213c04f4                 sethi   %hi(_map_data_size), %l0
F0088B5C: 90102320                 mov     0x320, %o0! void *
F0088B60: d0242370                 st      %o0, [%l0+%lo(_map_data_size)]
F0088B64: 7ffff667                 call    _vm_alloc_from_regions
F0088B68: 92102004                 mov     4, %o1
F0088B6C: 133c04f4                 sethi   %hi(_map_data), %o1! size_t
F0088B70: d0226368                 st      %o0, [%o1+%lo(_map_data)]
F0088B74: 400030b9                 call    _bzero
F0088B78: d2042370                 ld      [%l0+%lo(_map_data_size)], %o1
F0088B7C: 213c04f4                 sethi   %hi(_kentry_data_size), %l0
F0088B80: 11000058                 sethi   0x16000, %o0! void *
F0088B84: d0242360                 st      %o0, [%l0+%lo(_kentry_data_size)]
F0088B88: 7ffff65e                 call    _vm_alloc_from_regions
F0088B8C: 92102004                 mov     4, %o1
F0088B90: 133c04f4                 sethi   %hi(_kentry_data), %o1! size_t
F0088B94: d0226358                 st      %o0, [%o1+%lo(_kentry_data)]
F0088B98: 400030b0                 call    _bzero
F0088B9C: d2042360                 ld      [%l0+%lo(_kentry_data_size)], %o1
F0088BA0: a2100018                 mov     %i0, %l1
F0088BA4: 912e6003                 sll     %i1, 3, %o0
F0088BA8: 90220019                 sub     %o0, %i1, %o0
F0088BAC: 912a2002                 sll     %o0, 2, %o0
F0088BB0: 90044008                 add     %l1, %o0, %o0
F0088BB4: 80a44008                 cmp     %l1, %o0
F0088BB8: 3a80002a                 bcc,a   loc_F0088C60
F0088BBC: 133c04f3                 sethi   -0xFEC3400, %o1
F0088BC0: 273c04d0                 sethi   -0xFECC000, %l3
F0088BC4: 253c04f4                 sethi   -0xFEC3000, %l2
F0088BC8: a8100008                 mov     %o0, %l4
F0088BCC: a0046014                 add     %l1, 0x14, %l0
F0088BD0: d804e0d8                 ld      [%l3+0xD8], %o4
F0088BD4: d4042004                 ld      [%l0+4], %o2
F0088BD8: 92102004                 mov     4, %o1
F0088BDC: d0040000                 ld      [%l0], %o0
F0088BE0: 9638000c                 xnor    %g0, %o4, %o3
F0088BE4: 940a800b                 and     %o2, %o3, %o2
F0088BE8: 9002000c                 add     %o0, %o4, %o0
F0088BEC: 900a000b                 and     %o0, %o3, %o0
F0088BF0: d604a348                 ld      [%l2+0x348], %o3
F0088BF4: 94228008                 sub     %o2, %o0, %o2
F0088BF8: 9532800b                 srl     %o2, %o3, %o2
F0088BFC: 912aa001                 sll     %o2, 1, %o0
F0088C00: 9002000a                 add     %o0, %o2, %o0
F0088C04: 7ffff63f                 call    _vm_alloc_from_regions
F0088C08: 912a2004                 sll     %o0, 4, %o0! void *
F0088C0C: d804e0d8                 ld      [%l3+0xD8], %o4
F0088C10: d0244000                 st      %o0, [%l1]
F0088C14: d4042004                 ld      [%l0+4], %o2
F0088C18: d2040000                 ld      [%l0], %o1
F0088C1C: 9638000c                 xnor    %g0, %o4, %o3
F0088C20: 940a800b                 and     %o2, %o3, %o2
F0088C24: 9202400c                 add     %o1, %o4, %o1
F0088C28: 920a400b                 and     %o1, %o3, %o1
F0088C2C: d604a348                 ld      [%l2+0x348], %o3
F0088C30: 94228009                 sub     %o2, %o1, %o2
F0088C34: 9532800b                 srl     %o2, %o3, %o2
F0088C38: 932aa001                 sll     %o2, 1, %o1
F0088C3C: 9202400a                 add     %o1, %o2, %o1! size_t
F0088C40: 40003086                 call    _bzero
F0088C44: 932a6004                 sll     %o1, 4, %o1
F0088C48: a204601c                 inc     0x1C, %l1
F0088C4C: 80a44014                 cmp     %l1, %l4
F0088C50: 0abfffe0                 bcs     loc_F0088BD0
F0088C54: a004201c                 inc     0x1C, %l0
F0088C58: 133c04f3                 sethi   -0xFEC3400, %o1
F0088C5C: a2100018                 mov     %i0, %l1
F0088C60: 912e6003                 sll     %i1, 3, %o0
F0088C64: 90220019                 sub     %o0, %i1, %o0
F0088C68: 912a2002                 sll     %o0, 2, %o0
F0088C6C: 90044008                 add     %l1, %o0, %o0
F0088C70: 80a44008                 cmp     %l1, %o0
F0088C74: 1a800044                 bcc     loc_F0088D84
F0088C78: c0226000                 clr     [%o1]
F0088C7C: a8100009                 mov     %o1, %l4
F0088C80: 033c04f3a6106014         set     dword_F013CC14, %l3
F0088C88: 8604fffc                 add     %l3, -4, %g3
F0088C8C: 09000004                 sethi   0x1000, %g4
F0088C90: 113c04d0                 sethi   %hi(_page_mask), %o0
F0088C94: e40220d8                 ld      [%o0+%lo(_page_mask)], %l2
F0088C98: 9604600c                 add     %l1, 0xC, %o3
F0088C9C: 113c04f4                 sethi   %hi(_page_shift), %o0
F0088CA0: 9e380012                 xnor    %g0, %l2, %o7
F0088CA4: e0022348                 ld      [%o0+%lo(_page_shift)], %l0
F0088CA8: d002e008                 ld      [%o3+8], %o0
F0088CAC: 9a102000                 mov     0, %o5
F0088CB0: d202e00c                 ld      [%o3+0xC], %o1
F0088CB4: 90020012                 add     %o0, %l2, %o0
F0088CB8: 900a000f                 and     %o0, %o7, %o0
F0088CBC: d022e008                 st      %o0, [%o3+8]
F0088CC0: d402e008                 ld      [%o3+8], %o2
F0088CC4: 920a400f                 and     %o1, %o7, %o1
F0088CC8: c402e008                 ld      [%o3+8], %g2
F0088CCC: d222e00c                 st      %o1, [%o3+0xC]
F0088CD0: d002e00c                 ld      [%o3+0xC], %o0
F0088CD4: 95328010                 srl     %o2, %l0, %o2
F0088CD8: d422fff8                 st      %o2, [%o3-8]
F0088CDC: 91320010                 srl     %o0, %l0, %o0
F0088CE0: d202fff8                 ld      [%o3-8], %o1
F0088CE4: d022fffc                 st      %o0, [%o3-4]
F0088CE8: 90220009                 sub     %o0, %o1, %o0
F0088CEC: d2052000                 ld      [%l4], %o1
F0088CF0: d022c000                 st      %o0, [%o3]
F0088CF4: d8044000                 ld      [%l1], %o4
F0088CF8: 92024008                 add     %o1, %o0, %o1
F0088CFC: d002c000                 ld      [%o3], %o0
F0088D00: 80a34008                 cmp     %o5, %o0
F0088D04: 1a800018                 bcc     loc_F0088D64
F0088D08: d2252000                 st      %o1, [%l4]
F0088D0C: 113c0447                 sethi   %hi(_page_size), %o0
F0088D10: d402213c                 ld      [%o0+%lo(_page_size)], %o2
F0088D14: 9203201c                 add     %o4, 0x1C, %o1
F0088D18: c4226008                 st      %g2, [%o1+8]
F0088D1C: d0006014                 ld      [%g1+0x14], %o0
F0088D20: 80a20003                 cmp     %o0, %g3
F0088D24: 32800003                 bne,a   loc_F0088D30
F0088D28: d8220000                 st      %o4, [%o0]
F0088D2C: d824fffc                 st      %o4, [%l3-4]
F0088D30: d0227fe8                 st      %o0, [%o1-0x18]
F0088D34: c6230000                 st      %g3, [%o4]
F0088D38: d820e004                 st      %o4, [%g3+4]
F0088D3C: d0024000                 ld      [%o1], %o0
F0088D40: 90120004                 bset    %g4, %o0
F0088D44: d0224000                 st      %o0, [%o1]
F0088D48: 92026030                 inc     0x30, %o1 ! '0'
F0088D4C: 98032030                 inc     0x30, %o4 ! '0'
F0088D50: d002c000                 ld      [%o3], %o0
F0088D54: 9a036001                 inc     %o5
F0088D58: 80a34008                 cmp     %o5, %o0
F0088D5C: 0abfffef                 bcs     loc_F0088D18
F0088D60: 8400800a                 add     %g2, %o2, %g2
F0088D64: a204601c                 inc     0x1C, %l1
F0088D68: 912e6003                 sll     %i1, 3, %o0
F0088D6C: 90220019                 sub     %o0, %i1, %o0
F0088D70: 912a2002                 sll     %o0, 2, %o0
F0088D74: 90060008                 add     %i0, %o0, %o0
F0088D78: 80a44008                 cmp     %l1, %o0
F0088D7C: 0abfffcb                 bcs     loc_F0088CA8
F0088D80: 9602e01c                 inc     0x1C, %o3
F0088D84: 113c04f0                 sethi   %hi(_virtual_avail), %o0
F0088D88: f0022110                 ld      [%o0+%lo(_virtual_avail)], %i0
F0088D8C: 133c04f3                 sethi   %hi(_vm_pages_needed_lock), %o1
F0088D90: 113c04d0                 sethi   %hi(_page_mask), %o0
F0088D94: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F0088D98: c0226020                 clr     [%o1+%lo(_vm_pages_needed_lock)]
F0088D9C: b0060008                 add     %i0, %o0, %i0
F0088DA0: b02e0008                 bclr    %o0, %i0
F0088DA4: 81c7e008                 ret
F0088DA8: 81e80000                 restore
