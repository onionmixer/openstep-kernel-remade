F009B9D8: 9de3bf98                 save    %sp, -0x68, %sp
F009B9DC: 901022a4                 mov     0x2A4, %o0
F009B9E0: 193c045e                 sethi   %hi(aPcb), %o4! "pcb"
F009B9E4: 13000152                 sethi   0x54800, %o1
F009B9E8: 1500002a9412a100         set     0xA900, %o2
F009B9F0: 96102000                 mov     0, %o3
F009B9F4: 7fff7151                 call    _zinit
F009B9F8: 981322d8                 bset    %lo(aPcb), %o4! "pcb"
F009B9FC: 133c04f7                 sethi   %hi(_pcb_zone), %o1
F009BA00: d0226200                 st      %o0, [%o1+%lo(_pcb_zone)]
F009BA04: 81c7e008                 ret
F009BA08: 81e80000                 restore
