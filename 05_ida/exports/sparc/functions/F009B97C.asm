F009B97C: 9de3bf98                 save    %sp, -0x68, %sp
F009B980: 7fffed20                 call    _getpsr
F009B984: b13e2018                 sra     %i0, 24, %i0
F009B988: 913a2018                 sra     %o0, 24, %o0
F009B98C: 808a200f                 btst    0xF, %o0
F009B990: 02800004                 be      loc_F009B9A0
F009B994: b00e200f                 and     %i0, 0xF, %i0
F009B998: 1080000e                 ba      locret_F009B9D0
F009B99C: b0102002                 mov     2, %i0
F009B9A0: 80a62007                 cmp     %i0, 7
F009B9A4: 08800004                 bleu    loc_F009B9B4
F009B9A8: 80a62001                 cmp     %i0, 1
F009B9AC: 10800009                 ba      locret_F009B9D0
F009B9B0: b0102008                 mov     8, %i0
F009B9B4: 08800004                 bleu    loc_F009B9C4
F009B9B8: 80a62000                 cmp     %i0, 0
F009B9BC: 10800005                 ba      locret_F009B9D0
F009B9C0: b0102004                 mov     4, %i0
F009B9C4: 02800003                 be      locret_F009B9D0
F009B9C8: b0102001                 mov     1, %i0
F009B9CC: b0102003                 mov     3, %i0
F009B9D0: 81c7e008                 ret
F009B9D4: 81e80000                 restore
