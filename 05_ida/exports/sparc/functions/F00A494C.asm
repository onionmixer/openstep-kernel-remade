F00A494C: 9de3bf98                 save    %sp, -0x68, %sp
F00A4950: 153c04f3                 sethi   %hi(_mem_region), %o2
F00A4954: 113c04f4                 sethi   %hi(_num_regions), %o0
F00A4958: d2022330                 ld      [%o0+%lo(_num_regions)], %o1
F00A495C: 9412a030                 bset    %lo(_mem_region), %o2
F00A4960: 912a6003                 sll     %o1, 3, %o0
F00A4964: 90220009                 sub     %o0, %o1, %o0
F00A4968: 912a2002                 sll     %o0, 2, %o0
F00A496C: 9002000a                 add     %o0, %o2, %o0
F00A4970: 80a28008                 cmp     %o2, %o0
F00A4974: 1a800013                 bcc     loc_F00A49C0
F00A4978: 84100018                 mov     %i0, %g2
F00A497C: 9a200019                 neg     %i1, %o5
F00A4980: 98100008                 mov     %o0, %o4
F00A4984: 9602a014                 add     %o2, 0x14, %o3
F00A4988: d002c000                 ld      [%o3], %o0
F00A498C: 90023fff                 inc     -1, %o0
F00A4990: 90020019                 add     %o0, %i1, %o0
F00A4994: b00a000d                 and     %o0, %o5, %i0
F00A4998: d002e004                 ld      [%o3+4], %o0
F00A499C: 92060002                 add     %i0, %g2, %o1
F00A49A0: 80a24008                 cmp     %o1, %o0
F00A49A4: 18800004                 bgu     loc_F00A49B4
F00A49A8: 9402a01c                 inc     0x1C, %o2
F00A49AC: 10800009                 ba      locret_F00A49D0
F00A49B0: d222c000                 st      %o1, [%o3]
F00A49B4: 80a2800c                 cmp     %o2, %o4
F00A49B8: 0abffff4                 bcs     loc_F00A4988
F00A49BC: 9602e01c                 inc     0x1C, %o3
F00A49C0: 113c0465                 sethi   %hi(aGetFromMemRegi), %o0! "get_from_mem_regions"
F00A49C4: 7ffdc1eb                 call    _panic
F00A49C8: 901223e0                 bset    %lo(aGetFromMemRegi), %o0! "get_from_mem_regions"
F00A49CC: b0102000                 mov     0, %i0
F00A49D0: 81c7e008                 ret
F00A49D4: 81e80000                 restore
