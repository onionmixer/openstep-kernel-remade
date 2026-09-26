04031BD6: 4856                     pea     (a6)
04031BD8: 2c4f                     movea.l sp,a6
04031BDA: 4879040a7a14             pea     (aSpecBadop).l; "spec_badop"
04031BE0: 61fffffda084             bsr.l   _panic
