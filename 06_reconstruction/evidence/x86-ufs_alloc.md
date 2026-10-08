# x86 `src/bsd/ufs/ufs_alloc.c` (plan 214 (S5-P190), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 214 (S5-P190). Final run `s5p190-it2`; 07 file SHA-256 `517622399947dd1a6f71c09ad2f4ab4fc6de41e29c1595f2a4c6e415eafc3ff2`; diff `x86-ufs_alloc.diff`.

- Object [0x13b714, 0x13d830) 8476 B, 18 functions (_verify_and_swap_cg, _alloc, _fsfull, _fssleep, _fspause, _realloccg, _ialloc, _dirpref, _blkpref, _hashalloc, _fragextend, _alloccg, _alloccgblk, _ialloccg, _free_block, _ifree, _mapsearch, _fserr). Front `89 ec 5d c3`, back `55 89 e5 83`, next symbol 0x13d830.
- Final OBJECT_MATCH (`09_validation/reconstruction/s5p190-it2-l1-ufs_alloc-F-20261002.json`). Grade **A**.

Object extent [0x13b714, 0x13d830) is a reconstruction choice: no fill before 0x13b714 (4-byte aligned after the previous ret), 0x90 fill before alloc 0x13b768, ufs_bmap starts at 0x13d830; no call to verify_and_swap_cg exists in the kernel (it is inlined; confirmed by the build). Diagnosis 13 failed on the one-argument btodb; diagnosis build s5p190-d1 (NeXTMach text with a temporary btodb, not 07) matched 8 functions. The codex review of plan 214 found no wrong fact (facts 0, 4 are inferences; fact 5 completed: the previous block is left unset when bap is null or indx <= 0). Iterations: it1 all sizes match, blkpref and free_block differ; free_block prints bno (original 0x13d05a); variants s5p190-v1..v4 for blkpref (e1b chosen: swapped-first conditional, second entry assigned to prevblk); it2 all 18 functions match, extern relocation names match (relcheck 0).

## plan 397·398 고침(2026-10-08)
- `#endif QUOTA` 뒤에 참조 없는 `static const int ufs_alloc_const_4 = 4;` 를 넣었습니다(D058, D024, 근거 없는 꼴; 이름·주인 파일 모름, 링크 순서상 swapfs 다음 객체). 원본 `__TEXT,__const` 0x1d1280 4 B.
- 진단(07 손대지 않음): s6p397-ua1·ua2. 최종: 07 에서 재빌드 s6l1-g1a(행 155, 06_reconstruction/l2_build_forms-s6p398.tsv), L1 `09_validation/reconstruction/s6l1-g1a-l1-155.json` OBJECT_MATCH (`--place __TEXT,__const=0x1d1280`), `cc -M` 의존 모두 07. 07 파일 SHA-256 `aa049fac960545d6288962850f67bfbb032fd520e06bfc6585a670c1f30a11a2`.
- diff `06_reconstruction/evidence/x86-ufs_alloc.diff` 를 다시 만들었습니다.
