F000E270: 9de3bf98                 save    %sp, -0x68, %sp
F000E274: 213c04cf                 sethi   %hi(dword_F0133DDC), %l0
F000E278: d60421dc                 ld      [%l0+%lo(dword_F0133DDC)], %o3
F000E27C: 113c04d0                 sethi   %hi(_page_mask), %o0
F000E280: d00220d8                 ld      [%o0+%lo(_page_mask)], %o0
F000E284: d202e024                 ld      [%o3+0x24], %o1! address
F000E288: d8024000                 ld      [%o1], %o4
F000E28C: 808b0008                 btst    %o0, %o4
F000E290: 12800005                 bne     loc_F000E2A4
F000E294: d4026004                 ld      [%o1+4], %o2! size
F000E298: 808a8008                 btst    %o0, %o2
F000E29C: 02800005                 be      loc_F000E2B0
F000E2A0: 113c04d0                 sethi   -0xFECC000, %o0
F000E2A4: 90102016                 mov     0x16, %o0
F000E2A8: 1080000c                 ba      locret_F000E2D8
F000E2AC: d02ae038                 stb     %o0, [%o3+0x38]
F000E2B0: d0022260                 ld      [%o0+0x260], %o0
F000E2B4: d002200c                 ld      [%o0+0xC], %o0
F000E2B8: d002200c                 ld      [%o0+0xC], %o0! target_task
F000E2BC: 4001f179                 call    _vm_deallocate
F000E2C0: 9210000c                 mov     %o4, %o1
F000E2C4: 80a22000                 cmp     %o0, 0
F000E2C8: 02800004                 be      locret_F000E2D8
F000E2CC: d20421dc                 ld      [%l0+0x1DC], %o1
F000E2D0: 90102016                 mov     0x16, %o0
F000E2D4: d02a6038                 stb     %o0, [%o1+0x38]
F000E2D8: 81c7e008                 ret
F000E2DC: 81e80000                 restore
