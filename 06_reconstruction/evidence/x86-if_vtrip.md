# x86 `src/bsd/net/if_vtrip.c` (plan 381 (S5-P359), 2026-10-07)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 381 (S5-P359). Final run `s5p381-it1`; 07 file SHA-256 `61b8444fa40eb09990a8f8caea9969db388a2cacd9225200c50cf0dfbafb68ee`; diff `x86-if_vtrip.diff`.

- Object [0x11fb84, 0x1209ea) 3686 B, 11 functions (_SRHash, _SRIsEqual, (static vtrip_output), (static vtrip_input), (static vtrip_attach), _vtrip_config, (static vtrip_control), (static vtrip_getbuf), _nullsap_input, (static llc_reply), (static llc_send)). Front `c3 00 00 00`, back `00 00 55 89`, next symbol 0x1209ec.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p381-it1-l1-if_vtrip-F-20261002.json`). Grade **A**.

Token-ring IP/null-SAP layer. __text [0x11fb84, 0x1209ea) 3686 B (if_venip ends 0x11fb81, 00 x 3 before; netbuf 0x1209ec, 00 x 2 after); 11 functions (SRHash, SRIsEqual, vtrip_config, nullsap_input and SRTablePrototype are original symbols; the static names are inferred); __TEXT,__const [0x1d11d8, 0x1d1209) 49 B; __DATA,__data [0x1db870, 0x1db91b) 171 B verified by L1d. Diagnostics s5p377-vt1..vt18, b*, d*, vs1, v4s1..v4s4 (v4s4 OBJECT_MATCH), s5p381-vc1 (07 candidate OBJECT_MATCH); IOTokenRing with the plan 381 tokensr.h s5p381-tr1/tr2 OBJECT_MATCH. Codex review of plan 381 (gpt-6.1-sol) verified (tokensr.h key comment, earlier size notes corrected). Final s5p381-it1 from 07: OBJECT_MATCH (14), relcheck 0; IOTokenRing rebuilt from 07 with the new tokensr.h s5p381-tok OBJECT_MATCH (41).

## plan 397·398 고침(2026-10-08)
- 파일 끝에 호출되지 않는 `static __inline__ void vtrip_sr_overflow_message()`(add_sr 넘침 문자열 하나)를 넣었습니다(D058, D024, 근거 없는 꼴; 이름·꼴 모름). GCC 2.7 은 호출되지 않는 인라인 함수의 문자열을 남깁니다(plan 397 B2-3). `__data` 171 → 208 B, 둘째 문자열 0x1db91b.
- 진단(07 손대지 않음): s6p397-vt1. 최종: 07 에서 재빌드 s6l1-g1a(행 313, 06_reconstruction/l2_build_forms-s6p398.tsv), L1 `09_validation/reconstruction/s6l1-g1a-l1-313.json` OBJECT_MATCH, `cc -M` 의존 모두 07. 07 파일 SHA-256 `a860dd46c9c12406b2f723be4e7889b80e45a58f6e5b5aef73a0e46fca1e0d5a`.
- diff `06_reconstruction/evidence/x86-if_vtrip.diff` 를 다시 만들었습니다.
