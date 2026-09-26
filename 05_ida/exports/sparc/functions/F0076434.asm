F0076434: 9de3bf98                 save    %sp, -0x68, %sp
F0076438: 053c04f28610a328         set     _swapin_queue, %g3
F0076440: c620e004                 st      %g3, [%g3+4]
F0076444: c620a328                 st      %g3, [%g2+0x328]
F0076448: 053c04f2                 sethi   %hi(_swapper_lock_data), %g2
F007644C: c020a330                 clr     [%g2+%lo(_swapper_lock_data)]
F0076450: 81c7e008                 ret
F0076454: 81e80000                 restore
