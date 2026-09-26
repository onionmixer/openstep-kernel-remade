F00C8218: 9de3bf90                 save    %sp, -0x70, %sp
F00C821C: d00621a4                 ld      [%i0+0x1A4], %o0
F00C8220: 80a22000                 cmp     %o0, 0
F00C8224: 02800007                 be      loc_F00C8240
F00C8228: 133c0504                 sethi   %hi(paName), %o1
F00C822C: 90100018                 mov     %i0, %o0
F00C8230: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C8234: 213c03eb                 sethi   %hi(aSSOnPartition0), %l0! "%s: %s on partition != 0\n"
F00C8238: 1080001d                 ba      loc_F00C82AC
F00C823C: a01422e0                 bset    %lo(aSSOnPartition0), %l0! "%s: %s on partition != 0\n"
F00C8240: 113c0506                 sethi   %hi(paIsanyblockdevo), %o0! id
F00C8244: d202212c                 ld      [%o0+%lo(paIsanyblockdevo)], %o1! SEL
F00C8248: 4000a58a                 call    _objc_msgSend
F00C824C: 90100018                 mov     %i0, %o0
F00C8250: 912a2018                 sll     %o0, 24, %o0
F00C8254: 80a22000                 cmp     %o0, 0
F00C8258: 02800007                 be      loc_F00C8274
F00C825C: 133c0504                 sethi   %hi(paName), %o1
F00C8260: 90100018                 mov     %i0, %o0
F00C8264: d2026008                 ld      [%o1+%lo(paName)], %o1
F00C8268: 213c03eb                 sethi   %hi(aSSWithOpenBloc), %l0! "%s: %s with open block devices\n"
F00C826C: 10800010                 ba      loc_F00C82AC
F00C8270: a0142300                 bset    %lo(aSSWithOpenBloc), %l0! "%s: %s with open block devices\n"
F00C8274: 113c0506                 sethi   %hi(paIsanyotheropen), %o0! id
F00C8278: d2022128                 ld      [%o0+%lo(paIsanyotheropen)], %o1! SEL
F00C827C: 4000a57d                 call    _objc_msgSend
F00C8280: 90100018                 mov     %i0, %o0
F00C8284: 912a2018                 sll     %o0, 24, %o0
F00C8288: 80a22000                 cmp     %o0, 0
F00C828C: 12800004                 bne     loc_F00C829C
F00C8290: 90100018                 mov     %i0, %o0! id
F00C8294: 1080000c                 ba      locret_F00C82C4
F00C8298: b0102000                 mov     0, %i0
F00C829C: 133c0504                 sethi   %hi(paName), %o1
F00C82A0: d2026008                 ld      [%o1+%lo(paName)], %o1! SEL
F00C82A4: 213c03eba0142320         set     aSSWithOtherPar, %l0! "%s: %s with other partitions open\n"
F00C82AC: 4000a571                 call    _objc_msgSend
F00C82B0: b0103d2b                 mov     -0x2D5, %i0
F00C82B4: 92100008                 mov     %o0, %o1
F00C82B8: 90100010                 mov     %l0, %o0
F00C82BC: 7ffff78e                 call    _IOLog
F00C82C0: 9410001a                 mov     %i2, %o2
F00C82C4: 81c7e008                 ret
F00C82C8: 81e80000                 restore
