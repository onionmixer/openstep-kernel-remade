F009C04C: 9de3bf98                 save    %sp, -0x68, %sp
F009C050: d006200c                 ld      [%i0+0xC], %o0
F009C054: d002200c                 ld      [%o0+0xC], %o0
F009C058: 92100018                 mov     %i0, %o1
F009C05C: d0022024                 ld      [%o0+0x24], %o0
F009C060: 40000d68                 call    _pmap_activate
F009C064: 94102000                 mov     0, %o2
F009C068: 113c04d0                 sethi   %hi(_active_threads), %o0
F009C06C: f0222260                 st      %i0, [%o0+%lo(_active_threads)]
F009C070: 90100018                 mov     %i0, %o0
F009C074: 92102000                 mov     0, %o1
F009C078: d602202c                 ld      [%o0+0x2C], %o3
F009C07C: 153c04f0                 sethi   %hi(_active_stacks), %o2
F009C080: d622a058                 st      %o3, [%o2+%lo(_active_stacks)]
F009C084: d6022028                 ld      [%o0+0x28], %o3
F009C088: 153c0428                 sethi   %hi(_active_pcb), %o2
F009C08C: 7fffe27b                 call    _load_context
F009C090: d622a024                 st      %o3, [%o2+%lo(_active_pcb)]
F009C094: 81c7e008                 ret
F009C098: 81e80000                 restore
