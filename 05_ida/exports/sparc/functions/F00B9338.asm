F00B9338: 9de3bf98                 save    %sp, -0x68, %sp
F00B933C: 94100018                 mov     %i0, %o2
F00B9340: 920aa01f                 and     %o2, 0x1F, %o1
F00B9344: 80a26009                 cmp     %o1, 9
F00B9348: 14800007                 bg      loc_F00B9364
F00B934C: 80a2a03f                 cmp     %o2, 0x3F ! '?'
F00B9350: 113c047d901220ec         set     unk_F011F4EC, %o0
F00B9358: 932a6002                 sll     %o1, 2, %o1
F00B935C: 1080000c                 ba      locret_F00B938C
F00B9360: f0024008                 ld      [%o1+%o0], %i0
F00B9364: 02800008                 be      loc_F00B9384
F00B9368: 313c04c6                 sethi   %hi(unk_F0131808), %i0
F00B936C: b0162008                 bset    %lo(unk_F0131808), %i0
F00B9370: 90100018                 mov     %i0, %o0! char *
F00B9374: 133c047d                 sethi   %hi(aUnknownDeviceT), %o1! "<unknown device type 0x%x>"
F00B9378: 7ffd6cfc                 call    _sprintf
F00B937C: 921261c0                 bset    %lo(aUnknownDeviceT), %o1! "<unknown device type 0x%x>"
F00B9380: 30800003                 ba,a    locret_F00B938C
F00B9384: 313c047db01621b0         set     aNotPresent, %i0! "Not Present"
F00B938C: 81c7e008                 ret
F00B9390: 81e80000                 restore
