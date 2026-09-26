F00CA3A4: 9de3bf98                 save    %sp, -0x68, %sp
F00CA3A8: 7fff086d                 call    __io_vm_task_pmap
F00CA3AC: 90100018                 mov     %i0, %o0
F00CA3B0: 7fff52ea                 call    _pmap_extract
F00CA3B4: 92100019                 mov     %i1, %o1
F00CA3B8: d0268000                 st      %o0, [%i2]
F00CA3BC: 80a00008                 cmp     %g0, %o0
F00CA3C0: b0403fff                 addc    %g0, -1, %i0
F00CA3C4: b00e3d3e                 and     %i0, -0x2C2, %i0
F00CA3C8: 81c7e008                 ret
F00CA3CC: 81e80000                 restore
