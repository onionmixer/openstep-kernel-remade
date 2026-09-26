F000DCF8: 9de3bf98                 save    %sp, -0x68, %sp
F000DCFC: 90102294                 mov     0x294, %o0
F000DD00: 1300014a                 sethi   0x52800, %o1
F000DD04: 150000299412a100         set     0xA500, %o2
F000DD0C: 96102000                 mov     0, %o3
F000DD10: 193c042c                 sethi   %hi(aUtasks), %o4! "utasks"
F000DD14: 4001a889                 call    _zinit
F000DD18: 98132098                 bset    %lo(aUtasks), %o4! "utasks"
F000DD1C: 133c04d3                 sethi   %hi(_u_task_zone), %o1
F000DD20: d0226288                 st      %o0, [%o1+%lo(_u_task_zone)]
F000DD24: 90102128                 mov     0x128, %o0
F000DD28: 13000094                 sethi   0x25000, %o1
F000DD2C: 150000129412a200         set     0x4A00, %o2
F000DD34: 96102000                 mov     0, %o3
F000DD38: 193c042c                 sethi   %hi(aUthreads), %o4! "uthreads"
F000DD3C: 4001a87f                 call    _zinit
F000DD40: 981320a0                 bset    %lo(aUthreads), %o4! "uthreads"
F000DD44: 133c04d3                 sethi   %hi(_u_thread_zone), %o1
F000DD48: d0226290                 st      %o0, [%o1+%lo(_u_thread_zone)]
F000DD4C: 81c7e008                 ret
F000DD50: 81e80000                 restore
