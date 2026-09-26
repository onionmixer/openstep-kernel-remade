F00B74F0: 9de3bf98                 save    %sp, -0x68, %sp
F00B74F4: 113c0478                 sethi   %hi(_esp_softc), %o0
F00B74F8: e00221a8                 ld      [%o0+%lo(_esp_softc)], %l0
F00B74FC: 80a42000                 cmp     %l0, 0
F00B7500: 02800017                 be      loc_F00B755C
F00B7504: 113c02dd                 sethi   -0xFF48C00, %o0
F00B7508: 80a42000                 cmp     %l0, 0
F00B750C: 02800014                 be      loc_F00B755C
F00B7510: 113c02dd                 sethi   -0xFF48C00, %o0
F00B7514: d0042004                 ld      [%l0+4], %o0
F00B7518: 80a22000                 cmp     %o0, 0
F00B751C: 2280000d                 be,a    loc_F00B7550
F00B7520: e0042028                 ld      [%l0+0x28], %l0
F00B7524: 7fff7df8                 call    _splr
F00B7528: d0040000                 ld      [%l0], %o0
F00B752C: d2042084                 ld      [%l0+0x84], %o1
F00B7530: 80a26000                 cmp     %o1, 0
F00B7534: 02800004                 be      loc_F00B7544
F00B7538: a2100008                 mov     %o0, %l1
F00B753C: 4000000f                 call    _esp_watchsubr
F00B7540: 90100010                 mov     %l0, %o0
F00B7544: 7fff7df8                 call    _splx
F00B7548: 90100011                 mov     %l1, %o0
F00B754C: e0042028                 ld      [%l0+0x28], %l0
F00B7550: 80a42000                 cmp     %l0, 0
F00B7554: 12bfffee                 bne     loc_F00B750C
F00B7558: 113c02dd                 sethi   -0xFF48C00, %o0
F00B755C: 133c043e                 sethi   %hi(_hz), %o1
F00B7560: d40263e0                 ld      [%o1+%lo(_hz)], %o2
F00B7564: 901220f0                 bset    0xF0, %o0! int
F00B7568: 7ffd4ab0                 call    _timeout
F00B756C: 92102000                 mov     0, %o1
F00B7570: 81c7e008                 ret
F00B7574: 81e80000                 restore
