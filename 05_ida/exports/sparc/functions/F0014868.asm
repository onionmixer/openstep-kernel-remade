F0014868: 9de3bf98                 save    %sp, -0x68, %sp
F001486C: 4000029a                 call    _logchar
F0014870: 9010203c                 mov     0x3C, %o0 ! '<'
F0014874: 90100018                 mov     %i0, %o0
F0014878: 9210200a                 mov     0xA, %o1
F001487C: 94102004                 mov     4, %o2
F0014880: 96102000                 mov     0, %o3
F0014884: 98102000                 mov     0, %o4
F0014888: 400001fb                 call    sub_F0015074
F001488C: 9a102000                 mov     0, %o5
F0014890: 40000291                 call    _logchar
F0014894: 9010203e                 mov     0x3E, %o0 ! '>'
F0014898: 81c7e008                 ret
F001489C: 81e80000                 restore
