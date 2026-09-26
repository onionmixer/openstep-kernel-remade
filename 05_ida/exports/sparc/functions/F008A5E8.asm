F008A5E8: 9de3bf98                 save    %sp, -0x68, %sp
F008A5EC: 053c04f6                 sethi   %hi(_gc_lock), %g2
F008A5F0: c020a190                 clr     [%g2+%lo(_gc_lock)]
F008A5F4: 053c04f6                 sethi   %hi(_gc_active), %g2
F008A5F8: c020a188                 clr     [%g2+%lo(_gc_active)]
F008A5FC: 81c7e008                 ret
F008A600: 81e80000                 restore
