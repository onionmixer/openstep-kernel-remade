F00B1118: 9de3bf98                 save    %sp, -0x68, %sp
F00B111C: a2100018                 mov     %i0, %l1
F00B1120: 90100011                 mov     %l1, %o0
F00B1124: 7ffffff7                 call    _getproplen
F00B1128: 92100019                 mov     %i1, %o1! size_t
F00B112C: a0920000                 orcc    %o0, %g0, %l0
F00B1130: 04800011                 ble     locret_F00B1174
F00B1134: b0102000                 mov     0, %i0
F00B1138: 7ffedbce                 call    _kalloc
F00B113C: 90100010                 mov     %l0, %o0! void *
F00B1140: b0100008                 mov     %o0, %i0
F00B1144: 7fff8f45                 call    _bzero
F00B1148: 92100010                 mov     %l0, %o1
F00B114C: 80a62000                 cmp     %i0, 0
F00B1150: 32800006                 bne,a   loc_F00B1168
F00B1154: 90100011                 mov     %l1, %o0
F00B1158: 113c0471                 sethi   %hi(aGetlongpropKal), %o0! "getlongprop: kalloc failed"
F00B115C: 7ffd9005                 call    _panic
F00B1160: 90122290                 bset    %lo(aGetlongpropKal), %o0! "getlongprop: kalloc failed"
F00B1164: 90100011                 mov     %l1, %o0
F00B1168: 92100019                 mov     %i1, %o1
F00B116C: 7ffff7a6                 call    _prom_getprop
F00B1170: 94100018                 mov     %i0, %o2
F00B1174: 81c7e008                 ret
F00B1178: 81e80000                 restore
