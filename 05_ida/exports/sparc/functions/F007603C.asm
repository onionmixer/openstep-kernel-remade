F007603C: 9de3bf98                 save    %sp, -0x68, %sp
F0076040: 053c0442                 sethi   %hi(_stack_check_usage), %g2
F0076044: c400a290                 ld      [%g2+%lo(_stack_check_usage)], %g2
F0076048: 80a0a000                 cmp     %g2, 0
F007604C: 0280000a                 be      locret_F0076074
F0076050: b2102000                 mov     0, %i1
F0076054: 0537ab6f8410a2ef         set     -0x21524111, %g2
F007605C: 86102000                 mov     0, %g3
F0076060: c420c018                 st      %g2, [%g3+%i0]
F0076064: b2066001                 inc     %i1
F0076068: 80a66ffc                 cmp     %i1, 0xFFC
F007606C: 08bffffd                 bleu    loc_F0076060
F0076070: 8600e004                 inc     4, %g3
F0076074: 81c7e008                 ret
F0076078: 81e80000                 restore
