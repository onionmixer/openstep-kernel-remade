F0086500: 9de3bf98                 save    %sp, -0x68, %sp
F0086504: 113c0463                 sethi   %hi(_pmap_initialized), %o0
F0086508: d0022190                 ld      [%o0+%lo(_pmap_initialized)], %o0
F008650C: 80a22000                 cmp     %o0, 0
F0086510: 02800004                 be      loc_F0086520
F0086514: 113c0446                 sethi   %hi(aVmMemAllocFrom), %o0! "vm_mem_alloc_from_regions: pmap_initial"...
F0086518: 7ffe3b16                 call    _panic
F008651C: 901222e8                 bset    %lo(aVmMemAllocFrom), %o0! "vm_mem_alloc_from_regions: pmap_initial"...
F0086520: 113c04f3                 sethi   %hi(_mem_region), %o0
F0086524: 153c04f4                 sethi   %hi(_num_regions), %o2
F0086528: d202a330                 ld      [%o2+%lo(_num_regions)], %o1
F008652C: 98122030                 or      %o0, %lo(_mem_region), %o4
F0086530: 912a6003                 sll     %o1, 3, %o0
F0086534: 90220009                 sub     %o0, %o1, %o0
F0086538: 912a2002                 sll     %o0, 2, %o0
F008653C: 9002000c                 add     %o0, %o4, %o0
F0086540: 80a30008                 cmp     %o4, %o0
F0086544: 1a800029                 bcc     loc_F00865E8
F0086548: 9a200019                 neg     %i1, %o5
F008654C: 213c04f4                 sethi   -0xFEC3000, %l0
F0086550: 233c04f0                 sethi   -0xFEC4000, %l1
F0086554: 8610000a                 mov     %o2, %g3
F0086558: 8410000c                 mov     %o4, %g2
F008655C: 96032014                 add     %o4, 0x14, %o3
F0086560: d002c000                 ld      [%o3], %o0
F0086564: 90023fff                 inc     -1, %o0
F0086568: 90020019                 add     %o0, %i1, %o0
F008656C: 920a000d                 and     %o0, %o5, %o1
F0086570: d002e004                 ld      [%o3+4], %o0
F0086574: 94024018                 add     %o1, %i0, %o2
F0086578: 80a28008                 cmp     %o2, %o0
F008657C: 38800013                 bgu,a   loc_F00865C8
F0086580: d200e330                 ld      [%g3+0x330], %o1
F0086584: d422c000                 st      %o2, [%o3]
F0086588: 94102000                 mov     0, %o2
F008658C: 96100018                 mov     %i0, %o3
F0086590: d0042390                 ld      [%l0+0x390], %o0
F0086594: 98102003                 mov     3, %o4
F0086598: 90023fff                 inc     -1, %o0
F008659C: 90020019                 add     %o0, %i1, %o0
F00865A0: 900a000d                 and     %o0, %o5, %o0
F00865A4: d0242390                 st      %o0, [%l0+0x390]
F00865A8: 4000575a                 call    _pmap_map
F00865AC: 9a102001                 mov     1, %o5
F00865B0: d2042390                 ld      [%l0+0x390], %o1
F00865B4: 90024018                 add     %o1, %i0, %o0
F00865B8: d0242390                 st      %o0, [%l0+0x390]
F00865BC: d0246110                 st      %o0, [%l1+0x110]
F00865C0: 1080000d                 ba      locret_F00865F4
F00865C4: b0100009                 mov     %o1, %i0
F00865C8: 9803201c                 inc     0x1C, %o4
F00865CC: 912a6003                 sll     %o1, 3, %o0
F00865D0: 90220009                 sub     %o0, %o1, %o0
F00865D4: 912a2002                 sll     %o0, 2, %o0
F00865D8: 90020002                 add     %o0, %g2, %o0
F00865DC: 80a30008                 cmp     %o4, %o0
F00865E0: 0abfffe0                 bcs     loc_F0086560
F00865E4: 9602e01c                 inc     0x1C, %o3
F00865E8: 113c0446                 sethi   %hi(aVmMemAllocFrom_0), %o0! "vm_mem_alloc_from_regions"
F00865EC: 7ffe3ae1                 call    _panic
F00865F0: 90122318                 bset    %lo(aVmMemAllocFrom_0), %o0! "vm_mem_alloc_from_regions"
F00865F4: 81c7e008                 ret
F00865F8: 81e80000                 restore
