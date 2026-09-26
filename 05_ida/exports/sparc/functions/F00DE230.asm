F00DE230: 9de3bf98                 save    %sp, -0x68, %sp
F00DE234: 80a62000                 cmp     %i0, 0
F00DE238: 02800004                 be      loc_F00DE248
F00DE23C: 80a6a000                 cmp     %i2, 0
F00DE240: 12800004                 bne     loc_F00DE250
F00DE244: 90100018                 mov     %i0, %o0! id
F00DE248: 10800017                 ba      locret_F00DE2A4
F00DE24C: b01020ca                 mov     0xCA, %i0
F00DE250: 133c0505                 sethi   %hi(paCheckowner), %o1
F00DE254: d2026018                 ld      [%o1+%lo(paCheckowner)], %o1! SEL
F00DE258: 40004d86                 call    _objc_msgSend
F00DE25C: 9410001a                 mov     %i2, %o2
F00DE260: 912a2018                 sll     %o0, 24, %o0
F00DE264: 80a22000                 cmp     %o0, 0
F00DE268: 12800004                 bne     loc_F00DE278
F00DE26C: 90100018                 mov     %i0, %o0! id
F00DE270: 1080000d                 ba      locret_F00DE2A4
F00DE274: b01020c8                 mov     0xC8, %i0
F00DE278: 133c0505                 sethi   %hi(paAddstreamtagUs), %o1
F00DE27C: d2026010                 ld      [%o1+%lo(paAddstreamtagUs)], %o1! SEL
F00DE280: 9410001b                 mov     %i3, %o2
F00DE284: 96100019                 mov     %i1, %o3
F00DE288: 9810001a                 mov     %i2, %o4
F00DE28C: 40004d79                 call    _objc_msgSend
F00DE290: 9a10001c                 mov     %i4, %o5
F00DE294: 912a2018                 sll     %o0, 24, %o0
F00DE298: 80a00008                 cmp     %g0, %o0
F00DE29C: b0403fff                 addc    %g0, -1, %i0
F00DE2A0: b00e2005                 and     %i0, 5, %i0
F00DE2A4: 81c7e008                 ret
F00DE2A8: 81e80000                 restore
