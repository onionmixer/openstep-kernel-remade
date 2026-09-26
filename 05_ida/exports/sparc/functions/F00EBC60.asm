F00EBC60: 9de3bf90                 save    %sp, -0x70, %sp
F00EBC64: 40000d49                 call    _object_getClassName
F00EBC68: 90100018                 mov     %i0, %o0
F00EBC6C: 94100008                 mov     %o0, %o2
F00EBC70: 9010001a                 mov     %i2, %o0
F00EBC74: 133c03f392126198         set     aS0xX_0, %o1! "<%s: 0x%x>"
F00EBC7C: 7ffe81ae                 call    _NXPrintf
F00EBC80: 96100018                 mov     %i0, %o3
F00EBC84: 7ffe81a9                 call    _NXFlush
F00EBC88: 9010001a                 mov     %i2, %o0
F00EBC8C: 81c7e008                 ret
F00EBC90: 81e80000                 restore
