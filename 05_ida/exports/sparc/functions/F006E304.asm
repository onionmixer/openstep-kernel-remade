F006E304: 9de3bf88                 save    %sp, -0x78, %sp
F006E308: 90100018                 mov     %i0, %o0
F006E30C: 92100019                 mov     %i1, %o1
F006E310: 94102000                 mov     0, %o2
F006E314: 961023e8                 mov     0x3E8, %o3
F006E318: 7ffe5eb6                 call    __udivdi3
F006E31C: f03fbff0                 std     %i0, [%fp+var_10]
F006E320: d03fbff0                 std     %o0, [%fp+var_10]
F006E324: 90100018                 mov     %i0, %o0
F006E328: 92100019                 mov     %i1, %o1
F006E32C: 94102000                 mov     0, %o2
F006E330: 961023e8                 mov     0x3E8, %o3
F006E334: 7ffe5ea5                 call    __umoddi3
F006E338: 01000000                 nop
F006E33C: d227bfec                 st      %o1, [%fp+var_14]
F006E340: d41fbff0                 ldd     [%fp+var_10], %o2
F006E344: d6268000                 st      %o3, [%i2]
F006E348: 9210000a                 mov     %o2, %o1
F006E34C: 90102000                 mov     0, %o0
F006E350: d226a004                 st      %o1, [%i2+4]
F006E354: 81c7e008                 ret
F006E358: 81e80000                 restore
