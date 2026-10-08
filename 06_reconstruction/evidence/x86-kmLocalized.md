# x86 `src/bsd/dev/i386/kmLocalized.c` (plan 340 (S5-P330), 2026-10-06)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 340 (S5-P330). Final run `s5p340-it1`; 07 file SHA-256 `ba01db8c35d80729706c96256dd3516129b8aa212331a97afeea84407da18759`; diff `x86-kmLocalized.diff`.

- Object [0x197988, 0x1979e4) 92 B, 1 functions (_kmLocalizeString). Front `c3 00 00 00`, back `55 89 e5 83`, next symbol 0x1979e4.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p340-it1-l1-kmLocalized-F-20261002.json`). Grade **A**.

Object [0x197988, 0x1979e4) 92 B (00 x 3 before after the ret of kmGraphics' drawGraphicPanel: at 0x197984; no fill after, next VGASetGraphicsMode 0x1979e4): kmLocalizeString; __data [0x1e3e94, 0x1e41fc) 872 B (kmLocalizedStrings table 140 B and strings 732 B) verified; no bss. Diagnostic s5p341-a5 OBJECT_MATCH. Codex review of plan 340 (gpt-6.1-sol) verified (wording on the compiler language corrected). s5p340-it1 from 07: OBJECT_MATCH, relcheck 0.
