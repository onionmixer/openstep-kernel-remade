F0014474: 9de3bf98                 save    %sp, -0x68, %sp
F0014478: 113c04d4                 sethi   %hi(_log_open), %o0
F001447C: d0022178                 ld      [%o0+%lo(_log_open)], %o0
F0014480: 80a22000                 cmp     %o0, 0
F0014484: 02800004                 be      locret_F0014494
F0014488: 113c04d4                 sethi   %hi(dword_F013518C), %o0
F001448C: 40018a99                 call    _calloutEntryDispatch
F0014490: d002218c                 ld      [%o0+%lo(dword_F013518C)], %o0
F0014494: 81c7e008                 ret
F0014498: 81e80000                 restore
