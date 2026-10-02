# x86 `memcmp.c` 목적 파일 — `_bcmp`, `_memcmp` (S5-P1, 2026-10-01)

원본: `03_original/x86/binaries/mach_kernel` SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`.

## 후보 소스
- `07_kernel/src/machdep/i386/libc/memcmp.c` = `01_resources/upstream/darwin01/kernel/machdep/i386/libc/memcmp.c` 바이트 그대로(SHA-256 `90baa67753428cf024e59de4a31db0c36fcfe2c92ba8fc6f503b3754b752f45c`, 두 파일 동일).
- 출처 아카이브 `kernel-1.tar.gz` SHA-256 `0c19349be454d7162f497b55a7735b443f5506694215e2f3f5f026b597a54a01`. 라이선스 APSL 1.0, 파일 머리말 유지, 원문 사본 `07_kernel/LICENSES/APSL-1.0.txt`(= `darwin01/architecture/APPLE_LICENSE`, SHA-256 앞 16 자리 `99ddf37269bd2cee`).
- 정의: `bcmp`(106 행), `memcmp`(112 행), `static inline` 도우미 `simple_fwd_char_cmp`(68 행)·`simple_fwd_int_cmp`(85 행). 목적 파일 심볼은 `_bcmp`(0)·`_memcmp`(40) 둘뿐 → 도우미는 독립 기호 없이 `memcmp` 안으로 인라인됐다. 원본에도 따로 함수가 없으므로 원본 함수 행을 만들지 않는다.

## 빌드(실기, `kr_run.py` 실행 `s5p1-memcmp-1`)
- 공통 `-arch i386 -static -fno-common -fwritable-strings -traditional-cpp`, 기준 `-O4`(Darwin `conf/Makefile.i386` 의 libc 규칙), 대조군 `-O2`, `-O4 -funroll-all-loops`. 전처리에서 `SIREG` 는 `"S"` 로 전개.

## 대조(`l1_compare.py --place-from-image --ranges`)
| 옵션 | `_bcmp` | `_memcmp` | 목적 파일 | 결과 파일 |
|---|---|---|---|---|
| `-O4` | MATCH | MATCH | OBJECT_MATCH | `09_validation/reconstruction/s5p1-l1-O4-20261001.json` |
| `-O2` | MATCH | MATCH | OBJECT_MATCH | `s5p1-l1-O2-20261001.json` |
| `-O4 -funroll-all-loops` | MATCH | MATCH | OBJECT_MATCH | `s5p1-l1-O4u-20261001.json` |
세 옵션 모두 일치 → 이 파일에서는 옵션을 구분할 수 없음(기준 옵션 일치로 승격).

## 경계 증명서(Python)
- 목적 파일 `__text` 207 B, 정렬 2^2, 원본 배치 0x1012fc–0x1013cb(끝 제외), Ghidra `_memcmp` 끝(포함) 0x1013ca 와 맞음.
- 앞 틈 0x1012f9–0x1012fc: 3 B `00 00 00` = 0x1012f9 를 2^2 로 맞추는 최소 길이 3.
- 뒤 틈 0x1013cb–0x1013cc: 1 B `00` = 최소 길이 1(다음 기여의 정렬 2^2 가정과 일치).
- 링커 채움 값 0x00 은 실기 `ld` 링크 T1(`s1b-t1-kernel-4`)의 C 목적 파일 사이 채움 `00` 과 같다. 정렬이 없는 어셈블리 기여는 채움 없이 붙었다 → 틈 길이는 다음 기여의 정렬로 정해진다.
- 등급 A 는 이 목적 파일의 기여 범위에만 해당. 이웃 구간 seq 0(`memchr.c`, C)·seq 2(bcopy 무리, B)의 등급은 바뀌지 않는다.

## 의미와 한계
`compared`/`high` = "이 후보 소스를 위 옵션으로 빌드한 결과가 원본 바이트와 모든 참조를 재현한다"는 강한 증거. 역사적 원 소스가 이 파일과 같은지, 실행 동작은 확인하지 않았다(미결).

## 위치 이동 기록 (2026-10-01, 계획 18.1-7)
- 옛 위치 `07_kernel/src/arch/x86/libc/memcmp.c` → 새 위치 `07_kernel/src/machdep/i386/libc/memcmp.c`(Darwin 트리 배치). 파일 SHA-256 동일(`90baa677…`).
- 옛 실행 `08_build/runs/s5p1-memcmp-1`(입력 경로가 옛 위치)과 그 대조 결과 `09_validation/reconstruction/s5p1-l1-*-20261001.json` 은 그대로 둔다.
- 새 위치에서 다시 빌드(`s5p1-memcmp-reloc-1`, 같은 명령): `-O4` 목적 파일이 옛 실행의 것과 바이트 동일(SHA-256 앞 16 자리 `7abef6a8abca6ef6`), 대조 `09_validation/reconstruction/s5p1-reloc-l1-O4-20261001.json` 에서 `_bcmp`·`_memcmp` MATCH, OBJECT_MATCH.
