F0062720: 9de3bf90                 save    %sp, -0x70, %sp
F0062724: 90960000                 orcc    %i0, %g0, %o0
F0062728: 12800004                 bne     loc_F0062738
F006272C: 92100019                 mov     %i1, %o1
F0062730: 1080000e                 ba      locret_F0062768
F0062734: b0102010                 mov     0x10, %i0
F0062738: 94102001                 mov     1, %o2
F006273C: 7fffdbe8                 call    _ipc_object_translate
F0062740: 9607bff4                 add     %fp, var_C, %o3
F0062744: 80a22000                 cmp     %o0, 0
F0062748: 12800008                 bne     locret_F0062768
F006274C: b0100008                 mov     %o0, %i0
F0062750: d007bff4                 ld      [%fp+var_C], %o0
F0062754: 7fffe06e                 call    _ipc_port_set_seqno
F0062758: 9210001a                 mov     %i2, %o1
F006275C: d007bff4                 ld      [%fp+var_C], %o0
F0062760: b0102000                 mov     0, %i0
F0062764: c0220000                 clr     [%o0]
F0062768: 81c7e008                 ret
F006276C: 81e80000                 restore
