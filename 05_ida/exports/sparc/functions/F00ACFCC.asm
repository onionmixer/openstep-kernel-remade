F00ACFCC: 9de3bf90                 save    %sp, -0x70, %sp
F00ACFD0: 90100018                 mov     %i0, %o0
F00ACFD4: f2064000                 ld      [%i1], %i1
F00ACFD8: 9410001a                 mov     %i2, %o2
F00ACFDC: 9610001b                 mov     %i3, %o3
F00ACFE0: 9336601e                 srl     %i1, 30, %o1
F00ACFE4: 80a26000                 cmp     %o1, 0
F00ACFE8: 02800007                 be      loc_F00AD004
F00ACFEC: 9810001c                 mov     %i4, %o4
F00ACFF0: 80a26003                 cmp     %o1, 3
F00ACFF4: 2280000b                 be,a    loc_F00AD020
F00ACFF8: f227bff4                 st      %i1, [%fp+var_C]
F00ACFFC: 1080000c                 ba      locret_F00AD02C
F00AD000: b0102003                 mov     3, %i0
F00AD004: f227bff4                 st      %i1, [%fp+var_C]
F00AD008: 9007bff4                 add     %fp, var_C, %o0
F00AD00C: 9210000a                 mov     %o2, %o1
F00AD010: 7ffffecc                 call    sub_F00ACB40
F00AD014: 9410000c                 mov     %o4, %o2
F00AD018: 10800005                 ba      locret_F00AD02C
F00AD01C: b0100008                 mov     %o0, %i0
F00AD020: 7fffff44                 call    sub_F00ACD30
F00AD024: 9207bff4                 add     %fp, var_C, %o1
F00AD028: b0100008                 mov     %o0, %i0
F00AD02C: 81c7e008                 ret
F00AD030: 81e80000                 restore
