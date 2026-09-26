F006E124: 9de3bf98                 save    %sp, -0x68, %sp
F006E128: 4000a5f8                 call    _clock_value
F006E12C: 90102001                 mov     1, %o0
F006E130: b686c009                 addcc   %i3, %o1, %i3
F006E134: b4468008                 addc    %i2, %o0, %i2
F006E138: 90100018                 mov     %i0, %o0
F006E13C: 9410001a                 mov     %i2, %o2
F006E140: 9610001b                 mov     %i3, %o3
F006E144: 400022a6                 call    _calloutDispatchDelayed
F006E148: 92100019                 mov     %i1, %o1
F006E14C: 81c7e008                 ret
F006E150: 81e80000                 restore
