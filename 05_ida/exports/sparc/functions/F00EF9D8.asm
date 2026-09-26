F00EF9D8: 9de3bf98                 save    %sp, -0x68, %sp
F00EF9DC: 40000f40                 call    _sel_getName
F00EF9E0: 90100019                 mov     %i1, %o0
F00EF9E4: 94100008                 mov     %o0, %o2
F00EF9E8: 90100018                 mov     %i0, %o0
F00EF9EC: 133c03e8921262b0         set     aMessageSSentTo, %o1! "message %s sent to freed object=0x%lx"
F00EF9F4: 400003c3                 call    ___objc_error
F00EF9F8: 96100018                 mov     %i0, %o3
F00EF9FC: 81c7e008                 ret
F00EFA00: 81e80000                 restore
