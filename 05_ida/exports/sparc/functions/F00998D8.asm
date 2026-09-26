F00998D8: 9de3bf98                 save    %sp, -0x68, %sp
F00998DC: 90100018                 mov     %i0, %o0
F00998E0: 40000007                 call    _map_addr_to_dvma_pfn
F00998E4: 92100019                 mov     %i1, %o1
F00998E8: 133c04f6                 sethi   %hi(_ioptes), %o1
F00998EC: f0026308                 ld      [%o1+%lo(_ioptes)], %i0
F00998F0: 912a2002                 sll     %o0, 2, %o0
F00998F4: 81c7e008                 ret
F00998F8: 91ee0008                 restore %i0, %o0, %o0
