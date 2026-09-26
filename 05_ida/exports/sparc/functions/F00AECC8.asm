F00AECC8: 9de3bf98                 save    %sp, -0x68, %sp
F00AECCC: 9210001b                 mov     %i3, %o1
F00AECD0: 80a6200f                 cmp     %i0, 0xF
F00AECD4: 18800010                 bgu     loc_F00AED14
F00AECD8: 9410001c                 mov     %i4, %o2
F00AECDC: 80a62000                 cmp     %i0, 0
F00AECE0: 12800005                 bne     loc_F00AECF4
F00AECE4: 80a62007                 cmp     %i0, 7
F00AECE8: c0224000                 clr     [%o1]
F00AECEC: 10800017                 ba      locret_F00AED48
F00AECF0: b0102000                 mov     0, %i0
F00AECF4: 18800005                 bgu     loc_F00AED08
F00AECF8: 912e2002                 sll     %i0, 2, %o0
F00AECFC: 9002200c                 inc     0xC, %o0
F00AED00: 10800010                 ba      loc_F00AED40
F00AED04: d0064008                 ld      [%i1+%o0], %o0
F00AED08: 9002200c                 inc     0xC, %o0
F00AED0C: 1080000d                 ba      loc_F00AED40
F00AED10: d0064008                 ld      [%i1+%o0], %o0
F00AED14: 912e2002                 sll     %i0, 2, %o0
F00AED18: 90023fc0                 inc     -0x40, %o0
F00AED1C: b4068008                 add     %i2, %o0, %i2
F00AED20: 113c0000                 sethi   -0x10000000, %o0
F00AED24: 80a68008                 cmp     %i2, %o0
F00AED28: 38800006                 bgu,a   loc_F00AED40
F00AED2C: d0068000                 ld      [%i2], %o0
F00AED30: 7fffffbb                 call    __fp_read_word
F00AED34: 9010001a                 mov     %i2, %o0
F00AED38: 10800004                 ba      locret_F00AED48
F00AED3C: b0100008                 mov     %o0, %i0
F00AED40: b0102000                 mov     0, %i0
F00AED44: d0224000                 st      %o0, [%o1]
F00AED48: 81c7e008                 ret
F00AED4C: 81e80000                 restore
