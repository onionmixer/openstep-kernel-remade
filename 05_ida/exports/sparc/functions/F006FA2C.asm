F006FA2C: 9de3b990                 save    %sp, -0x670, %sp
F006FA30: a2100018                 mov     %i0, %l1
F006FA34: 90100011                 mov     %l1, %o0! void *
F006FA38: a007b9f0                 add     %fp, var_610, %l0
F006FA3C: 92100010                 mov     %l0, %o1! void *
F006FA40: f0064000                 ld      [%i1], %i0
F006FA44: 40009433                 call    _bcopy
F006FA48: 94102604                 mov     0x604, %o2
F006FA4C: 80a62007                 cmp     %i0, 7
F006FA50: 08800008                 bleu    loc_F006FA70
F006FA54: d807b9f0                 ld      [%fp+var_610], %o4
F006FA58: 1100003f901223ff         set     0xFFFF, %o0
F006FA60: 940b0008                 and     %o4, %o0, %o2
F006FA64: 80a28018                 cmp     %o2, %i0
F006FA68: 0280000c                 be      loc_F006FA98
F006FA6C: 11004000                 sethi   0x1000000, %o0
F006FA70: 113c0440901220f8         set     aKdpPacketBadLe, %o0! "kdp_packet bad len pkt %d hdr %d\n"
F006FA78: 92100018                 mov     %i0, %o1
F006FA7C: d607b9f0                 ld      [%fp+var_610], %o3
F006FA80: 1500003f9412a3ff         set     0xFFFF, %o2
F006FA88: 7ffff95c                 call    _safe_prf
F006FA8C: 940ac00a                 and     %o3, %o2, %o2
F006FA90: 10800025                 ba      locret_F006FB24
F006FA94: b0102000                 mov     0, %i0
F006FA98: 808b0008                 btst    %o0, %o4
F006FA9C: 02800009                 be      loc_F006FAC0
F006FAA0: 113c0440                 sethi   %hi(aKdpPacketReply), %o0! "kdp_packet reply recvd req %x seq %x\n"
F006FAA4: 90122120                 bset    %lo(aKdpPacketReply), %o0! "kdp_packet reply recvd req %x seq %x\n"
F006FAA8: 93332019                 srl     %o4, 25, %o1
F006FAAC: 95332010                 srl     %o4, 16, %o2
F006FAB0: 7ffff952                 call    _safe_prf
F006FAB4: 940aa0ff                 and     %o2, 0xFF, %o2
F006FAB8: 1080001b                 ba      locret_F006FB24
F006FABC: b0102000                 mov     0, %i0
F006FAC0: 97332019                 srl     %o4, 25, %o3
F006FAC4: 80a2e00e                 cmp     %o3, 0xE
F006FAC8: 1880000f                 bgu     loc_F006FB04
F006FACC: 90100010                 mov     %l0, %o0
F006FAD0: 153c04409412a0b8         set     unk_F01100B8, %o2
F006FAD8: 972ae002                 sll     %o3, 2, %o3
F006FADC: d602c00a                 ld      [%o3+%o2], %o3
F006FAE0: 92100019                 mov     %i1, %o1! void *
F006FAE4: 9fc2c000                 call    %o3
F006FAE8: 9410001a                 mov     %i2, %o2
F006FAEC: b0100008                 mov     %o0, %i0
F006FAF0: 90100010                 mov     %l0, %o0! void *
F006FAF4: d4064000                 ld      [%i1], %o2! size_t
F006FAF8: 40009406                 call    _bcopy
F006FAFC: 92100011                 mov     %l1, %o1
F006FB00: 30800009                 ba,a    locret_F006FB24
F006FB04: 113c044090122148         set     aKdpPacketBadRe, %o0! "kdp_packet bad request %x len %d seq %x"...
F006FB0C: 9210000b                 mov     %o3, %o1
F006FB10: 97332010                 srl     %o4, 16, %o3
F006FB14: d807b9f4                 ld      [%fp+var_60C], %o4
F006FB18: 7ffff938                 call    _safe_prf
F006FB1C: 960ae0ff                 and     %o3, 0xFF, %o3
F006FB20: b0102000                 mov     0, %i0
F006FB24: 81c7e008                 ret
F006FB28: 81e80000                 restore
