F006E18C: 9de3bf90                 save    %sp, -0x70, %sp
F006E190: 4000a2c1                 call    _splnet
F006E194: f03fbff0                 std     %i0, [%fp+var_10]
F006E198: a0100008                 mov     %o0, %l0
F006E19C: 113c004b901221e8         set     _wakeup, %o0
F006E1A4: a207bff0                 add     %fp, var_10, %l1
F006E1A8: 92100011                 mov     %l1, %o1
F006E1AC: d41fbff0                 ldd     [%fp+var_10], %o2
F006E1B0: 7fffffdd                 call    _ns_timeout
F006E1B4: 98102001                 mov     1, %o4
F006E1B8: 90100011                 mov     %l1, %o0! unsigned int
F006E1BC: 7ffe912f                 call    _sleep
F006E1C0: 92102018                 mov     0x18, %o1
F006E1C4: 4000a2d8                 call    _splx
F006E1C8: 90100010                 mov     %l0, %o0
F006E1CC: 81c7e008                 ret
F006E1D0: 81e80000                 restore
