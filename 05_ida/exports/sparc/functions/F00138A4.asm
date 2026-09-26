F00138A4: 9de3bf98                 save    %sp, -0x68, %sp
F00138A8: 113c04cf                 sethi   %hi(dword_F0133DDC), %o0
F00138AC: d00221dc                 ld      [%o0+%lo(dword_F0133DDC)], %o0
F00138B0: 7ffff02f                 call    _suser
F00138B4: e0022024                 ld      [%o0+0x24], %l0
F00138B8: 80a22000                 cmp     %o0, 0
F00138BC: 02800004                 be      locret_F00138CC
F00138C0: 113c04d1                 sethi   %hi(_hostid), %o0
F00138C4: d2040000                 ld      [%l0], %o1
F00138C8: d2222228                 st      %o1, [%o0+%lo(_hostid)]
F00138CC: 81c7e008                 ret
F00138D0: 81e80000                 restore
