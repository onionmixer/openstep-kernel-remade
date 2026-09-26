F006A328: 9de3bf98                 save    %sp, -0x68, %sp
F006A32C: 113c000090122000         set     dword_F0000000, %o0! mhp
F006A334: 92100018                 mov     %i0, %o1! segname
F006A338: 7fffff4e                 call    _getsectbynamefromheader
F006A33C: 94100019                 mov     %i1, %o2
F006A340: 81c7e008                 ret
F006A344: 91e80008                 restore %g0, %o0, %o0
