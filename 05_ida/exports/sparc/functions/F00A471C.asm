F00A471C: 9de3bf98                 save    %sp, -0x68, %sp
F00A4720: 213c000c                 sethi   %hi(_bootops), %l0
F00A4724: d0042038                 ld      [%l0+%lo(_bootops)], %o0
F00A4728: 7fffffea                 call    _check_boot_version
F00A472C: d0020000                 ld      [%o0], %o0
F00A4730: 253c0464                 sethi   %hi(_old_memlist), %l2
F00A4734: d024a380                 st      %o0, [%l2+%lo(_old_memlist)]
F00A4738: d0042038                 ld      [%l0+%lo(_bootops)], %o0
F00A473C: 133c0465                 sethi   %hi(aMemoryUpdate_1), %o1! "memory-update"
F00A4740: d4022030                 ld      [%o0+0x30], %o2
F00A4744: 9fc28000                 call    %o2
F00A4748: 92126388                 bset    %lo(aMemoryUpdate_1), %o1! "memory-update"
F00A474C: 80a22000                 cmp     %o0, 0
F00A4750: 32800009                 bne,a   loc_F00A4774
F00A4754: 133c04f8                 sethi   -0xFEC2000, %o1
F00A4758: 133c0465                 sethi   %hi(aMemoryUpdate_2), %o1! "memory-update"
F00A475C: d0042038                 ld      [%l0+%lo(_bootops)], %o0
F00A4760: 92126398                 bset    %lo(aMemoryUpdate_2), %o1! "memory-update"
F00A4764: d6022034                 ld      [%o0+0x34], %o3
F00A4768: 9fc2c000                 call    %o3
F00A476C: 94102000                 mov     0, %o2
F00A4770: 133c04f8                 sethi   -0xFEC2000, %o1
F00A4774: 113c04f8901221a0         set     _memlists, %o0
F00A477C: d404a380                 ld      [%l2+0x380], %o2
F00A4780: d0226178                 st      %o0, [%o1+0x178]
F00A4784: d6042038                 ld      [%l0+0x38], %o3
F00A4788: 233c0464                 sethi   %hi(_phys_install), %l1
F00A478C: d602e008                 ld      [%o3+8], %o3
F00A4790: d0246390                 st      %o0, [%l1+%lo(_phys_install)]
F00A4794: d002c000                 ld      [%o3], %o0
F00A4798: 7fffff6e                 call    _copy_memlist
F00A479C: 92126178                 bset    0x178, %o1
F00A47A0: 213c0464                 sethi   %hi(_physmaxpfn), %l0
F00A47A4: d0046390                 ld      [%l1+%lo(_phys_install)], %o0
F00A47A8: 9214238c                 or      %l0, %lo(_physmaxpfn), %o1
F00A47AC: d604a380                 ld      [%l2+0x380], %o3
F00A47B0: 233c0464                 sethi   %hi(_physinstalled), %l1
F00A47B4: 7fffffa5                 call    _installed_top_size
F00A47B8: 94146384                 or      %l1, %lo(_physinstalled), %o2
F00A47BC: d004238c                 ld      [%l0+%lo(_physmaxpfn)], %o0
F00A47C0: 153c0464                 sethi   %hi(_physmax), %o2
F00A47C4: d2046384                 ld      [%l1+%lo(_physinstalled)], %o1
F00A47C8: 912a200c                 sll     %o0, 12, %o0
F00A47CC: d022a388                 st      %o0, [%o2+%lo(_physmax)]
F00A47D0: 932a600c                 sll     %o1, 12, %o1
F00A47D4: 113c04f0                 sethi   %hi(_mem_size), %o0
F00A47D8: d2222108                 st      %o1, [%o0+%lo(_mem_size)]
F00A47DC: 81c7e008                 ret
F00A47E0: 81e80000                 restore
