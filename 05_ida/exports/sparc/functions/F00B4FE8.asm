F00B4FE8: 9de3bf68                 save    %sp, -0x98, %sp
F00B4FEC: 113c02d4901221d8         set     _esp_handle_cmd_start, %o0
F00B4FF4: d027bfc8                 st      %o0, [%fp+var_38]
F00B4FF8: 113c02d49012227c         set     _esp_handle_cmd_done, %o0
F00B5000: d027bfcc                 st      %o0, [%fp+var_34]
F00B5004: 113c02d4901222f4         set     _esp_handle_msg_out, %o0
F00B500C: d027bfd0                 st      %o0, [%fp+var_30]
F00B5010: 113c02d4901223e0         set     _esp_handle_msg_out_done, %o0
F00B5018: d027bfd4                 st      %o0, [%fp+var_2C]
F00B501C: 113c02d7901221d4         set     _esp_handle_msg_in, %o0
F00B5024: d027bfd8                 st      %o0, [%fp+var_28]
F00B5028: 113c02d79012221c         set     _esp_handle_more_msgin, %o0
F00B5030: d027bfdc                 st      %o0, [%fp+var_24]
F00B5034: 113c02d7901222a0         set     _esp_handle_msg_in_done, %o0
F00B503C: d027bfe0                 st      %o0, [%fp+var_20]
F00B5040: 113c02d590122174         set     _esp_handle_clearing, %o0
F00B5048: d027bfe4                 st      %o0, [%fp+var_1C]
F00B504C: 113c02d590122274         set     _esp_handle_data, %o0
F00B5054: d027bfe8                 st      %o0, [%fp+var_18]
F00B5058: 113c02d6901220a4         set     _esp_handle_data_done, %o0
F00B5060: d027bfec                 st      %o0, [%fp+var_14]
F00B5064: 113c02d790122028         set     _esp_handle_c_cmplt, %o0
F00B506C: d027bff0                 st      %o0, [%fp+var_10]
F00B5070: 233c0479                 sethi   -0xFEE1C00, %l1
F00B5074: a007bff8                 add     %fp, var_8, %l0
F00B5078: d00e2041                 ldub    [%i0+0x41], %o0
F00B507C: 80a2201a                 cmp     %o0, 0x1A
F00B5080: 12800006                 bne     loc_F00B5098
F00B5084: 80a22000                 cmp     %o0, 0
F00B5088: 40000017                 call    _esp_handle_unknown
F00B508C: 90100018                 mov     %i0, %o0
F00B5090: 10800011                 ba      loc_F00B50D4
F00B5094: 80a22002                 cmp     %o0, 2
F00B5098: 02800004                 be      loc_F00B50A8
F00B509C: 80a2200b                 cmp     %o0, 0xB
F00B50A0: 28800008                 bleu,a  loc_F00B50C0
F00B50A4: 912a2002                 sll     %o0, 2, %o0
F00B50A8: 90100018                 mov     %i0, %o0
F00B50AC: 92102003                 mov     3, %o1
F00B50B0: 40000acf                 call    _esplog
F00B50B4: 94146128                 or      %l1, 0x128, %o2
F00B50B8: 10800006                 ba      loc_F00B50D0
F00B50BC: 90102007                 mov     7, %o0
F00B50C0: 90040008                 add     %l0, %o0, %o0
F00B50C4: d2023fcc                 ld      [%o0-0x34], %o1
F00B50C8: 9fc24000                 call    %o1
F00B50CC: 90100018                 mov     %i0, %o0
F00B50D0: 80a22002                 cmp     %o0, 2
F00B50D4: 22bfffea                 be,a    loc_F00B507C
F00B50D8: d00e2041                 ldub    [%i0+0x41], %o0
F00B50DC: 81c7e008                 ret
F00B50E0: 91e80008                 restore %g0, %o0, %o0
