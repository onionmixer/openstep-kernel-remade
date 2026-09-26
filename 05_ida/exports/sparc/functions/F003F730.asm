F003F730: 9de3bf98                 save    %sp, -0x68, %sp
F003F734: 4000058f                 call    _sync_vp
F003F738: 90100018                 mov     %i0, %o0
F003F73C: 90100018                 mov     %i0, %o0
F003F740: 92100019                 mov     %i1, %o1
F003F744: 9410001a                 mov     %i2, %o2
F003F748: 7fffe898                 call    _nfsgetattr
F003F74C: 96102000                 mov     0, %o3
F003F750: 81c7e008                 ret
F003F754: 91e80008                 restore %g0, %o0, %o0
