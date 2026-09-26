F009A70C: 9de3bf98                 save    %sp, -0x68, %sp
F009A710: 808e2400                 btst    0x400, %i0
F009A714: 02800006                 be      loc_F009A72C
F009A718: 808e2800                 btst    0x800, %i0
F009A71C: 113c045c                 sethi   %hi(aMBusBusError), %o0! "\tM-Bus Bus Error\n"
F009A720: 7ffde7ce                 call    _printf
F009A724: 90122368                 bset    %lo(aMBusBusError), %o0! "\tM-Bus Bus Error\n"
F009A728: 808e2800                 btst    0x800, %i0
F009A72C: 02800004                 be      loc_F009A73C
F009A730: 113c045c                 sethi   %hi(aMBusTimeoutErr), %o0! "\tM-Bus Timeout Error\n"
F009A734: 7ffde7c9                 call    _printf
F009A738: 90122380                 bset    %lo(aMBusTimeoutErr), %o0! "\tM-Bus Timeout Error\n"
F009A73C: 11000004                 sethi   0x1000, %o0
F009A740: 808e0008                 btst    %o0, %i0
F009A744: 02800006                 be      loc_F009A75C
F009A748: 808e2001                 btst    1, %i0
F009A74C: 113c045c                 sethi   %hi(aMBusUncorrecta), %o0! "\tM-Bus Uncorrectable Error\n"
F009A750: 7ffde7c2                 call    _printf
F009A754: 90122398                 bset    %lo(aMBusUncorrecta), %o0! "\tM-Bus Uncorrectable Error\n"
F009A758: 808e2001                 btst    1, %i0
F009A75C: 02800007                 be      locret_F009A778
F009A760: 113c045c                 sethi   %hi(aPhysicalAddres), %o0! "\tPhysical Address = (space %x) %x\n"
F009A764: 901223b8                 bset    %lo(aPhysicalAddres), %o0! "\tPhysical Address = (space %x) %x\n"
F009A768: 920e20f0                 and     %i0, 0xF0, %o1
F009A76C: 93326004                 srl     %o1, 4, %o1
F009A770: 7ffde7ba                 call    _printf
F009A774: 94100019                 mov     %i1, %o2
F009A778: 81c7e008                 ret
F009A77C: 81e80000                 restore
