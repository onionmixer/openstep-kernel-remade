F008A820: 9de3bf98                 save    %sp, -0x68, %sp
F008A824: 80a62000                 cmp     %i0, 0
F008A828: 12800004                 bne     loc_F008A838
F008A82C: 96100019                 mov     %i1, %o3
F008A830: 1080001a                 ba      locret_F008A898
F008A834: b0102004                 mov     4, %i0
F008A838: 80a6a000                 cmp     %i2, 0
F008A83C: 12800005                 bne     loc_F008A850
F008A840: 80a6e000                 cmp     %i3, 0
F008A844: c022c000                 clr     [%o3]
F008A848: 10800014                 ba      locret_F008A898
F008A84C: b0102000                 mov     0, %i0
F008A850: 02800004                 be      loc_F008A860
F008A854: 113c04d0                 sethi   -0xFECC000, %o0
F008A858: 10800005                 ba      loc_F008A86C
F008A85C: d0062014                 ld      [%i0+0x14], %o0
F008A860: d00220d8                 ld      [%o0+0xD8], %o0
F008A864: d202c000                 ld      [%o3], %o1
F008A868: 902a4008                 andn    %o1, %o0, %o0
F008A86C: d022c000                 st      %o0, [%o3]
F008A870: 113c04d0                 sethi   %hi(_page_mask), %o0
F008A874: d80220d8                 ld      [%o0+%lo(_page_mask)], %o4
F008A878: 92102000                 mov     0, %o1
F008A87C: 94102000                 mov     0, %o2
F008A880: 90100018                 mov     %i0, %o0
F008A884: 9a06800c                 add     %i2, %o4, %o5
F008A888: 982b400c                 andn    %o5, %o4, %o4
F008A88C: 7fffe751                 call    _vm_map_find
F008A890: 9a10001b                 mov     %i3, %o5
F008A894: b0100008                 mov     %o0, %i0
F008A898: 81c7e008                 ret
F008A89C: 81e80000                 restore
