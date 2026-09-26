F009F734: 9de3bf98                 save    %sp, -0x68, %sp
F009F738: 053c04f78410a270         set     _pmap_info, %g2
F009F740: c600a0a0                 ld      [%g2+0xA0], %g3
F009F744: 8600e001                 inc     %g3
F009F748: c620a0a0                 st      %g3, [%g2+0xA0]
F009F74C: 053c04f0                 sethi   %hi(_kernel_pmap), %g2
F009F750: f000a100                 ld      [%g2+%lo(_kernel_pmap)], %i0
F009F754: 81c7e008                 ret
F009F758: 81e80000                 restore
