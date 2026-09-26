F00B2048: 9de3bf98                 save    %sp, -0x68, %sp
F00B204C: 80a62000                 cmp     %i0, 0
F00B2050: 0280001f                 be      locret_F00B20CC
F00B2054: 113c0474                 sethi   %hi(aKeyboardClick), %o0! "keyboard-click?"
F00B2058: f0062028                 ld      [%i0+0x28], %i0
F00B205C: a01221a8                 or      %o0, %lo(aKeyboardClick), %l0! "keyboard-click?"
F00B2060: 92100010                 mov     %l0, %o1
F00B2064: 7ffffc27                 call    _getproplen
F00B2068: 90100018                 mov     %i0, %o0
F00B206C: a2920000                 orcc    %o0, %g0, %l1
F00B2070: 14800007                 bg      loc_F00B208C
F00B2074: 90100018                 mov     %i0, %o0
F00B2078: 113c0474901221b8         set     aNoSProperty, %o0! "No \"%s\" property\n"
F00B2080: 7ffd8976                 call    _printf
F00B2084: 92100010                 mov     %l0, %o1
F00B2088: 30800011                 ba,a    locret_F00B20CC
F00B208C: 7ffffc23                 call    _getlongprop
F00B2090: 92100010                 mov     %l0, %o1
F00B2094: b0920000                 orcc    %o0, %g0, %i0
F00B2098: 0280000d                 be      locret_F00B20CC
F00B209C: 133c0474                 sethi   %hi(aTrue), %o1! "true"
F00B20A0: 7ffd5843                 call    _strcmp
F00B20A4: 921261d0                 bset    %lo(aTrue), %o1! "true"
F00B20A8: 80a22000                 cmp     %o0, 0
F00B20AC: 12800006                 bne     loc_F00B20C4
F00B20B0: 90100018                 mov     %i0, %o0
F00B20B4: 133c04fb                 sethi   %hi(_keyclick), %o1
F00B20B8: 90102001                 mov     1, %o0
F00B20BC: d0226250                 st      %o0, [%o1+%lo(_keyclick)]
F00B20C0: 90100018                 mov     %i0, %o0
F00B20C4: 7ffed837                 call    _kfree
F00B20C8: 92100011                 mov     %l1, %o1
F00B20CC: 81c7e008                 ret
F00B20D0: 81e80000                 restore
