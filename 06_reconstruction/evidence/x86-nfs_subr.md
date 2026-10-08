# x86 `src/bsd/nfs/nfs_subr.c` (plan 280 (S5-P270), 2026-10-04)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 280 (S5-P270). Final run `s5p270-it1`; 07 file SHA-256 `18df1561e2c23c0b9992d3dffc6e641169a400b4cb240025017fb21514251291`; diff `x86-nfs_subr.diff`.

- Object [0x12ea98, 0x12fdea) 4946 B, 23 functions ((static clget), _nfs_netboot_prealloc, (static clfree), _rfscall, _vattr_to_sattr, _setdiropargs, _setdirgid, _setdirmode, _rnode_cache_clear, _makenfsnode, (static rp_addhash), _rp_rmhash, (static rm_free), _rinactive, _rfree, (static rfind), _rinval, _rflush, _newname, _rlock, _runlock, _rlock_timeout, (static rlock_awaken)). Front `89 ec 5d c3`, back `00 00 55 89`, next symbol 0x1310c4.
- Final L1 `09_validation/reconstruction/s5p270-it1-l1-nfs_subr-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred. Grade **P**.

plan 280 (2026-10-04): the object does not end at 0x12fd1c. The byte after runlock (0x12fd1b) is 0x90, compiler alignment inside an object, and the next linker padding is 00 00 at 0x12fdea; so rlock_timeout (0x12fd1c) and the static routine 0x12fdd0 belong to nfs_subr.c. __text is now [0x12ea98, 0x12fdea) 4946 B, 23 functions. No reference tree has rlock_timeout; the SDK nfs/rnode.h has RTIMEDOUT under NeXT. The only caller is 0x133e1d (nfs_vnodeops area, rp and 5). Scratch s5p270-w1 and it1 (s5p270-it1) from 07: __text and __data 0 differences, 22 MATCH + newname MATCH_UNVERIFIED, relcheck 0; zerofill re-run with the known placements minus nfs_subr itself (zerofill-known-s5p270-20261004.json, 43 entries). The codex review of plan 280 confirmed the bytes and asked for the end (0x12fdea) and the padding rule to be stated precisely and for the routine name to be marked as a choice (verified, fixed). Earlier record (plan 186): Object extent [0x12ea98, 0x12fd1c): clget precedes nfs_netboot_prealloc without a symbol (called at 0x12eda6 and 0x12ef44); objects.tsv seq 97 text_start 0x12ed7c. Staged variant s5p159-v1 (statics) gave the original layout. Iterations: it1 vattr_to_sattr ternaries and rfscall +16; it2 if/else form; rfscall's CLNT_GETERR absent in the original; it3 rnode_cache_clear reloads rpfreelist; it4 __text 20 MATCH + newname MATCH_UNVERIFIED (static newnum in __bss). nfs_cache_check takes 4 arguments in this kernel (to be reflected in nfs_client.c). Grade P: __bss reference-inferred.

## Earlier record (plan 186, superseded by plan 280)

> # x86 `src/bsd/nfs/nfs_subr.c` (plan 186 (S5-P159), 2026-10-02)
>
> Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 186 (S5-P159). Final run `s5p159-it4`; 07 file SHA-256 `b744d6aa603a658947abc8abcc5e234b3f98732c9551417847b10c5fa88cd5c5`; diff `x86-nfs_subr.diff`.
>
> - Object [0x12ea98, 0x12fd1b) 4739 B, 21 functions ((static clget), _nfs_netboot_prealloc, (static clfree), _rfscall, _vattr_to_sattr, _setdiropargs, _setdirgid, _setdirmode, _rnode_cache_clear, _makenfsnode, (static rp_addhash), _rp_rmhash, (static rm_free), _rinactive, _rfree, (static rfind), _rinval, _rflush, _newname, _rlock, _runlock). Front `89 ec 5d c3`, back `90 55 89 e5`, next symbol 0x12fd1c.
> - Final L1 `09_validation/reconstruction/s5p159-it4-l1-nfs_subr-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.
>
> Object extent [0x12ea98, 0x12fd1c): clget precedes nfs_netboot_prealloc without a symbol (called at 0x12eda6 and 0x12ef44); objects.tsv seq 97 text_start 0x12ed7c. Staged variant s5p159-v1 (statics) gave the original layout. Iterations: it1 vattr_to_sattr ternaries and rfscall +16; it2 if/else form; rfscall's CLNT_GETERR absent in the original; it3 rnode_cache_clear reloads rpfreelist; it4 __text 20 MATCH + newname MATCH_UNVERIFIED (static newnum in __bss). nfs_cache_check takes 4 arguments in this kernel (to be reflected in nfs_client.c). Grade P: __bss reference-inferred.

## plan 397·398 고침(2026-10-08)
- `extern int nrnode;` 를 `int nrnode = 0;` 로 바꿨습니다(D058; 원본 `_nrnode` 는 `__data` 0x1dc2c0, nfs_subr 데이터 오프셋 0). nfs_server.c 끝도 바이트로는 같아 사용자가 골랐습니다. 등급 P 그대로(`__bss` 만 미확정).
- 진단(07 손대지 않음): s6p397-nr1·nr2. 최종: 07 에서 재빌드 s6l1-g1a(행 355, 06_reconstruction/l2_build_forms-s6p398.tsv), L1 `09_validation/reconstruction/s6l1-g1a-l1-355.json` NOT_MATCH, `cc -M` 의존 모두 07. 07 파일 SHA-256 `219ea0e0c32113ef1f25922f48f6bd54d2040f239fe1bf9400bba8b4b22bf8a9`.
- diff `06_reconstruction/evidence/x86-nfs_subr.diff` 를 다시 만들었습니다.
