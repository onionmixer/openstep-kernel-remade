F008A708: 9de3bf98                 save    %sp, -0x68, %sp
F008A70C: 113c04f090122200         set     _vm_alloc_lock, %o0
F008A714: 7fff797d                 call    _lock_init
F008A718: 92102001                 mov     1, %o1
F008A71C: 81c7e008                 ret
F008A720: 81e80000                 restore
