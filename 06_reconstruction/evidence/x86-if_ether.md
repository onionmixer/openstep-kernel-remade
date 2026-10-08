# x86 `src/bsd/netinet/if_ether.c` (plan 173 (S5-P146), 2026-10-02)

Original SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`. plan 173 (S5-P146). Final run `s5p146-it2`; 07 file SHA-256 `3623ad1528ca574e9973bff410a92409001c47c110a8ebd9f09d8bef93dbd8cd`; diff `x86-if_ether.diff`.

- Object [0x1220b4, 0x123440) 5004 B, 11 functions (_arptimer, _arpwhohas, _arpresolve, _arpinput, _in_arpinput, _arptfree, _arptnew, _arpioctl, _revarpinput, _localetheraddr, _ether_sprintf). Front `89 ec 5d c3`, back `55 89 e5 56`, next symbol 0x123440.
- Final L1 `09_validation/reconstruction/s5p146-it2-l1-if_ether-F-20261002.json`: __text/__const 0 byte differences; __DATA,__bss reference-inferred only. Grade **P**.

Built with -DMULTICAST -DPOSIX_KERN -D_POSIX_SOURCE. Iterations: it1 arpwhohas (and its two inlined copies in arpresolve) kept &sa in a register only without the 3Mb else; staged variants v1 (3Mb else under `#if NEN > 0`) -> arpwhohas 0 differences, v2 (no condition) 6; it2 (v1 applied) __text 5004 B and __data with 0 differences, 9 functions MATCH, localetheraddr/ether_sprintf MATCH_UNVERIFIED through __bss. nomc diagnostic compile (no -DMULTICAST) exit 0. Grade P: __bss reference-inferred.

## plan 401 고침(2026-10-08)
- plan 401: #import <netinet/in_var.h> added (as Darwin 0.1 if_ether.c:85); its tentative in_ifaddr and ipintrq are first mentioned here, before in.c, as in the original __common
- 공통 기호 요청만 바뀌어 `__text`·`__data` 바이트는 그대로입니다: plan 401 재빌드(s6l3-*, 402 객체)에서 이 객체의 L1 이 이전 결과와 같습니다. 이 고침으로 공통 기호 417 개의 배치가 원본과 같아졌고, 07 에서 다시 링크·strip 한 커널(run s6p402-ln1)이 원본과 바이트 단위로 같습니다. 07 파일 SHA-256 `075223fe7599973f485cba46f7ef6e2d9141b32382ff27508a79f09423c3da97`.
- diff `06_reconstruction/evidence/x86-if_ether.diff` 를 다시 만들었습니다.

## plan 404 고침(2026-10-08, D061)
- notice added: line marked plan 401 (Darwin): Apple APSL 1.0 (notice in file; 07_kernel/LICENSES/APSL-1.0.txt). 주석만 바뀌었습니다(07 파일 SHA-256 `15bb8893d3b9100aa8de7f8204a9f1836cff25c6cd16dedd8e0f73bfb658c582`); diff 를 다시 만들었습니다.
