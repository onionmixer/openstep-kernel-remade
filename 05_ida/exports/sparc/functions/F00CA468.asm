F00CA468: 9de3bf98                 save    %sp, -0x68, %sp
F00CA46C: 7fff082b                 call    __io_vm_task_self
F00CA470: 01000000                 nop
F00CA474: 92100018                 mov     %i0, %o1! address
F00CA478: 7fff010a                 call    _vm_deallocate
F00CA47C: 94100019                 mov     %i1, %o2
F00CA480: 81c7e008                 ret
F00CA484: 91e82000                 restore %g0, 0, %o0
