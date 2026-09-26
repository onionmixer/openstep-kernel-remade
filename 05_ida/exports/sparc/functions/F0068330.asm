F0068330: 9de3bf98                 save    %sp, -0x68, %sp
F0068334: 133c04bd90126270         set     dword_F012F670, %o0
F006833C: d0222004                 st      %o0, [%o0+4]
F0068340: d0226270                 st      %o0, [%o1+0x270]
F0068344: 113c04f0901220e0         set     _stack_queue_lock, %o0
F006834C: 4000026f                 call    _lock_init
F0068350: 92102001                 mov     1, %o1
F0068354: 113c04bd                 sethi   %hi(dword_F012F678), %o0
F0068358: 13000010                 sethi   0x4000, %o1
F006835C: d2222278                 st      %o1, [%o0+%lo(dword_F012F678)]
F0068360: 113c0447                 sethi   %hi(_page_size), %o0
F0068364: d002213c                 ld      [%o0+%lo(_page_size)], %o0
F0068368: 90020009                 add     %o0, %o1, %o0
F006836C: 7ffe78a5                 call    _udiv
F0068370: 90023fff                 inc     -1, %o0
F0068374: 133c04bd                 sethi   %hi(dword_F012F67C), %o1
F0068378: d022627c                 st      %o0, [%o1+%lo(dword_F012F67C)]
F006837C: 81c7e008                 ret
F0068380: 81e80000                 restore
