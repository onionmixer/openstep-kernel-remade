F008C610: 9de3bf90                 save    %sp, -0x70, %sp
F008C614: 7fff6e20                 call    _port_reference
F008C618: 90100018                 mov     %i0, %o0
F008C61C: 113c04d0                 sethi   %hi(_active_threads), %o0
F008C620: 92100018                 mov     %i0, %o1
F008C624: d0022260                 ld      [%o0+%lo(_active_threads)], %o0
F008C628: 94102006                 mov     6, %o2
F008C62C: d002200c                 ld      [%o0+0xC], %o0
F008C630: 7fff6e01                 call    _object_copyout
F008C634: 9607bff4                 add     %fp, var_C, %o3
F008C638: f007bff4                 ld      [%fp+var_C], %i0
F008C63C: 81c7e008                 ret
F008C640: 81e80000                 restore
