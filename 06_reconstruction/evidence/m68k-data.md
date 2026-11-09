# m68k `__DATA,__data` 자료 단위 10 개 — 계획 772–774 (2026-11-08, D176)

원본: `03_original/m68k/binaries/mach_kernel`(SHA-256 `dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75`), `__DATA,__data` = 0x40ad964, 22552 B.
증거 수준: 바이트 일치만이다. 같은 바이트를 내는 소스가 원본 소스라는 증명이 아니다.

## 단위(전부 `OBJECT_MATCH`, `__data` 크기·주소가 목표와 같고 byte/ref 차이 0, 배치 `given by symbol`)

| 단위 | 목표 구간 | B | 소스 | 종류 |
|---|---|---:|---|---|
| `init_sysent` | [0x40adb54, 0x40ae118) | 1476 | 07 `v183.34/m68k/src/bsd/kern/init_sysent.c`(덮어쓰기: 07 본 파일 + 표지 8 줄) | C |
| `tty_conf` | [0x40ae4ac, 0x40ae690) | 484 | 07 `src/bsd/kern/tty_conf.c` 그대로 | A |
| `uipc_proto` | [0x40ae694, 0x40ae73e) | 170 | 07 `src/bsd/kern/uipc_proto.c` 그대로 | A |
| `vfs_conf` | [0x40ae796, 0x40ae83a) | 164 | 07 `src/bsd/vfs/vfs_conf.c` 그대로 | A |
| `in_proto` | [0x40ae95e, 0x40aeac0) | 354 | 07 `src/bsd/netinet/in_proto.c` 그대로 | A |
| `ufs_tables` | [0x40af336, 0x40af5a2) | 620 | 07 `src/bsd/ufs/ufs_tables.c` 그대로 | A |
| `param` | [0x40af65e, 0x40af748) | 234 | 07 `src/conf/param.c` 그대로 | A |
| `counters` | [0x40af768, 0x40af77c) | 20 | 07 `src/kern/counters.c` 그대로 | A |
| `fd_global` | [0x40b128c, 0x40b14a6) | 538 (+ `__cstring` 370, 내용으로 참조 확인) | 07 새 파일 `src/machdep/m68k/fd_global.c` = NeXTMach `nextdev/fd_global.c` + 포함 줄 2 | B |
| `scsiconf` | [0x40b206c, 0x40b207c) | 16 | 07 새 파일 `src/machdep/m68k/scsiconf.c` = NeXTMach `nextdev/scsiconf.c` + 포함 줄 6 치환 + `<next/cpu.h>` 줄 제거 | B |

합 4076 B(python).

## 확인한 것

- 진단(07 불변): D0 `m4p772-d0-1`·`d0b-2`·`d0c-1`(기록 `09_validation/reconstruction/m4-m68k-p773-d0-20261108.json`), D1 `m4p772-d1-1`(기록 `m4-m68k-p774-d1-20261108.json`).
- 수락 실행: `m4p774-a1`(명령 23: M5 재빌드 3 + 단위 10×(`-c`,`-M`)), 스테이지 `08_build/runs/tools/m4p774-base-stage`(`stage_m68k.py --plan 774 stage`). 모든 명령 종료 0·stderr 비어 있음.
- 새 도구 `10_tools/reconstruction/m4_m68k_data.py check`(기록 `m4-m68k-p774-check-20261108.json`): run 상태가 정확히 `00..22` 이고 전부 0, 모든 `.err`(컴파일·`-M`)가 0 B, `run.cmd` RUN 줄이 `cmd` 가 만드는 줄과 같음; 단위마다 소스가 스테이지 매니페스트·07 파일과 같고 원본 경로가 `07_kernel/` 아래, L1 입력이 정확히 {객체, 고정된 커널 이미지}, L1 `OBJECT_MATCH`, `__data` 기준(크기·주소·차이 0·`given by symbol`; `placement-only`·`literal` 은 `__data` 로 불인정), `__text` 내용 없음·그 밖 절 내용 없음(literal `__cstring` 만 허용), **정의 전역 기호 집합이 원본의 목표 구간 기호 집합과 같고(양방향) 각각 원본 주소에 있음**, COMMON·미정의 이름이 모두 원본에 있음(D136), `-M` 출력이 `이름.o: src/src/<소스> <헤더…>` 꼴이고 토큰이 모두 `src/` 아래·i386 없음·스테이지 매니페스트에 있고 run 안 헤더 내용 해시가 매니페스트와 같음, 참조 객체가 검사 객체와 다른 파일·다른 run 디렉터리이고 해시가 명세에 고정됨 + `canon` 같음, 단위 범위 겹침 0.
- 변이 시험(`selftest`, 기록 `m4-m68k-p774-selftest-20261108.json`): 변조 28 건이 모두 거부되고 대조군 5 건이 수락됨(건너뛴 시험 없음; 필요한 파일이 없으면 시험 실패). 거부된 것: 자료 한 바이트·목표 주소·크기·`placement-only`·`refs_differ`·원본 기호표에서 정의 기호 삭제·기호 주소·원본에 있는 기호를 객체가 정의하지 않음·**객체의 정의 기호 하나를 실제로 지움(`N_EXT` 비트 해제)**·원본에 없는 COMMON(`_disk_chip`, 명세에 해시 고정한 대조 객체)·L1 뒤 객체 변조·`__data` 없는 객체·커널 이미지 해시 변조·범위 겹침·상태 키 이상·상태 0 아님·공백 stderr·`-M` 의존의 밖 경로(`/outside/i386/evil.h`)·매니페스트에 없는 헤더·헤더 내용 불일치·잘못된 의존 대상·컴파일 옵션 제거·참조 객체가 검사 객체 자신/같은 run/해시 미고정·check 뒤 L1 기록 변경·check 뒤 refresh 객체 변경·다른 명세의 check 기록.
- 회귀: `stage_m68k.py --plan 770 stage` 재스테이지 = 기존 `m4p770a1-stage`(1034 파일 해시 같음); 774 스테이지 − 770 스테이지 = 추가 2(`fd_global.c`·`scsiconf.c`)·변경 1(`init_sysent.c`); x86gate 일곱 묶음 모두 같음·`v183` 경로 0; M5 205 줄(`--plan 774 cmd`)이 계획 764 것과 계획 번호만 빼고 같고 764 수락 스테이지와의 차이가 새 파일·`init_sysent.c` 뿐이라 M5 회귀 생략; `m4_m68k_status.py` 재실행 결과 `06_reconstruction/m68k-m4-status.tsv` 와 바이트 같음(76 객체, 78.15 %); 07 스냅샷 차이 = 새 파일 3 + `PROVENANCE.tsv`·`MODIFICATIONS.md`.

## 차이의 근거

- `init_sysent`: 07 본 파일은 x86 표라 139 번·151 번이 `nosys` 이다. 원본 m68k `_sysent` 는 139 번이 `_sigreturn`(인자 0), 151 번이 `_machparam`(인자 2)이다(python: 처음 비교에서 바이트 `+1209`(원본 2)·참조 2 곳 차이). NeXTMach `bsd/init_sysent.c:321`(`syss(sigreturn,0)`)·`:342`(`syss(machparam,2)`) 줄과 같다. 덮어쓰기는 07 줄을 지우지 않고 `#if !m68k` / 07 줄 / `#else` / 후보 줄 / `#endif` 표지 삽입(`stage_m68k.py` `check_derived` 통과; 표지 없는 줄을 바꾼 대조는 거부). `m68k` 매크로는 값 1 로 정의됨(전처리 출력).
- `scsiconf`: `<next/cpu.h>`(`scsiconf.c:25`)가 불러오는 `u_short disk_chip;`(`cpu.h:67`)가 COMMON `_disk_chip` 을 내는데 원본 기호표에 없다. 줄을 제거하면(D107 선례 `snd_dspreg.h`) COMMON 이름이 모두 원본에 있고 `OBJECT_MATCH` 이다. 이 제거는 D107 선례를 적용한 것이며 새 사용자 결정이 아니다.
- B 두 파일은 원본 객체의 소유 파일임이 확인된 것이 아니라 이름·바이트가 맞는 NeXTMach 후보이다.

## 커버리지(`m4_m68k_data.py coverage`, 기록 `m4-m68k-p774-coverage-20261108.json`, 표 `06_reconstruction/m68k-data-status.tsv`)

- 검증된 `__data` 범위 143 행(M4 37·M5 94·M5 재빌드 2·이번 자료 단위 10)의 합집합 18847 B / 22552 B = 83.57 %. 이전 14771 B(M4+M5) + 4076 B = 18847 B(python).
- 증거는 명시 목록(M4 상태표 76 행의 L1 입력 해시, M5 `m4p764/m5compare` 205 개, 205 줄 밖 세 객체는 이번 실행 `m4p774-a1` 의 재빌드)이며 명세 `pins` 의 집합 해시(M4 `6a1176da…`, M5 `94af9e6d…`)와 같아야 하고, check 기록의 객체·L1 해시와 모든 L1 입력 파일을 다시 해시해 확인한다(어긋나면 coverage 가 실패함: 변이 시험). M4/M5 겹침은 `tty_pty` 4 B 뿐.
- 205 줄 밖 `kern_exec`·`mach_process`·`ns_timer` 는 과거 객체가 오래된 `machdep/m68k/thread.h` 로 빌드되어 있었으므로 현재 스테이지로 다시 만들어 L1 로 확인했다(`canon` 이 과거 객체와 같음; `obj_sig` 는 `stabs` 개수만 다름: `kern_exec` 1232 대 1207, `mach_process` 644 대 619, `ns_timer` 942 대 883).
- (계획 777 에서 해소, 아래 "계획 776–777" 절) 아직 미검증 3700 B: `conf` [0x40b087c, 0x40b122e) 2482 B, `ioconf`+`vers` 구간 [0x40b2cba, 0x40b317c) 1218 B. 1 B 틈 5곳(0x40ae955·0x40aeb6b·0x40aee5d·0x40af2d7·0x40b125f)은 값 0 이고 기호가 없지만 정렬 채움이라는 해석은 후보이며 검증된 바이트로 세지 않는다.

## M7 의무

- 이번 단위 객체 10 개의 전역 정의(SECT) 기호 45 개(M5 재빌드 3 개를 더하면 73 개)는 서로 겹치지 않고 이미 수락된 M4(읽을 수 있는 75 개; `fpsp` 객체 파일은 수집 트리에 없고 그 기호는 원본 text 주소에 있음)·M5 205 객체의 정의와 겹치지 않음(python, `scratch/p772/dupsym2.py`). 링크 때 COMMON 정의 자리와 합침은 기존 M4 와 같은 규칙.
- `fd_global.c`·`scsiconf.c` 는 `-Isrc/generated`(`fd.h`·`sd.h`·`st.h`·`sg.h`·`sc.h` 등 생성 헤더)가 필요하다.


## 계획 776–777 (2026-11-08, D177): `conf`·`ioconf`·`vers` 3664 B

사용자 응답(AskUserQuestion "세 단위 모두", D177): FPSP D174 와 같은 방식 — NeXTMach 와 맞는 부분은 그대로, 원본 바이트에서만 알 수 있는 부분은 직접 씀. 모두 바이트 일치만 증거이며 원본 소스와 같다는 증명이 아니다.

| 단위 | 목표 구간 | B | 07 파일 | NeXTMach 와의 관계 |
|---|---|---:|---|---|
| `conf` | [0x40b087c, 0x40b122e) | 2482 | 새 `src/machdep/m68k/conf.c` | NeXTMach `next/conf.c`(505 행) + 표시 줄: `cdevsw` 43/43 항목 일치, `bdevsw` 0–7 은 `fdsize`(1)·`sdsize`(6) 두 칸만 다름, `bdevsw` 8–23 은 원본 바이트에서만 앎 |
| `ioconf` | [0x40b2cba, 0x40b30ec) | 1074 | 새 `src/machdep/m68k/ioconf.c` | 원본 바이트에서 쓴 `mkioconf.c NeXT_ioconf()`·`NeXT_pseudo_inits()` 출력 꼴(텍스트 복사 없음) |
| `vers` | [0x40b3110, 0x40b317c) | 108 | 새 `src/machdep/m68k/vers.c` | 원본 바이트에서 쓴 `newvers` 출력 꼴(x86 `conf/vers.c` 선례) |

- 새 개수 헤더 `ldd.h`(`NLDD 0`, 바이트로 확정)·`km.h`·`ev.h`·`vol.h`(`1`, 바이트는 양수만 정함 = hypothesis)는 `06_reconstruction/config_options-m68k.tsv` 에 행 4 개를 더하고 `gen_config_headers.py --arch m68k` 로 만들어 `v183.34/m68k/generated/`(덮어쓰기 경로, `OVLFROM` = 777)에 둔다. `pty.h`(`NPTY 32`)·`nfsmeas.h`(`NNFSMEAS 0`)는 07 `generated/` 에 이미 있고 값이 같아 건드리지 않음(기존 M5 소스 `tty_pty.c`·`nfs_*.c` 가 포함). 생성기를 다시 돌려도 기존 헤더는 바이트 같음(07 스냅샷).
- 원본 구조(python 디코드): `bdevsw` 24×24 B·`cdevsw` 43×44 B·`nblkdev` 24·`nchrdev` 43·`mem_no` 3·`swapdev` `0x0400`(2 B); `bus_cinit` 38 B×4(3+센티널)·`bus_dinit` 42 B×21(20+센티널, `sd` 슬레이브 `'?'`=63)·`pseudo_inits` 유효 40 B; `vers` = 8 + 1 + 98 + 1 B(채움 0).
- 미해결: `pseudo_inits` 뒤 [0x40b30ec, 0x40b3110) 36 B 는 모두 0 이고 기호가 없다(소유 불명; 채움 배열을 추가하지 않음). 1 B 틈 5곳(0x40ae955·0x40aeb6b·0x40aee5d·0x40af2d7·0x40b125f)도 같은 종류.
- `ioconf.c` 는 생성기가 쓰는 `nextdev/busvar.h` 대신 `dev/busvar.h` 를 포함(D104 선례, 1997 스테이지에 없는 경로); 첫 컴파일이 그 한 줄로 실패했고(`m4p777-d0-1`) 고쳐서 통과(`d0-2`).

확인(전부 실제 실행): 진단 D0 `m4p777-d0-2`·`d0-3`(scratch 스테이지, 07 불변; `d0-1` 은 `ioconf` 실패로 수집 거부), 수락 run `m4p777-a1`(명령 29: M5 재빌드 3 + 단위 13×2; 모두 종료 0·stderr 0 B), `m4_m68k_data.py check`(13 단위 전부 OK, 검증 7740 B = 4076 + 3664)·`selftest`(변이 28 거부·대조군 5 수락)·`coverage`(146 행; 검증된 `__data` 22511 / 22552 B = 99.82 %; 남은 41 B = 1 B 틈 5 + 36 B 영 구간), 기록 `09_validation/reconstruction/m4-m68k-p777-{check,selftest,coverage}-20261108.json`, 표 `06_reconstruction/m68k-data-status.tsv`(146 행으로 갱신; 이전 143 행 판은 계획 774 기록).
회귀: `--plan 770`·`774 stage` 재스테이지의 `files` 목록(경로·출처·해시)이 저장본과 같음(774 는 매니페스트 전체가 같고, 770 은 저장본의 `base` 필드가 `m0p770-a1-stage`·재생성이 `s6ln-g1a-stage` 라 전체는 다름); 777 − 774 = 추가 7(소스 3 + 헤더 4)·변경 0; 777 − 764 수락 스테이지 = 새 파일·`init_sysent.c` 뿐; x86gate 7/7·`v183` 경로 0; `--plan 777 cmd` 205 줄이 764 것과 계획 번호 정규화 후 같음(M5 회귀 생략); `m4_m68k_status.py` 결과가 `m68k-m4-status.tsv` 와 바이트 같음(76 객체·78.15 %); 07 스냅샷 차이 = 새 파일 7(+ 기록).

도구 보강(codex 구현 검토 `kpciowl01` 뒤, 같은 날): 계획 777 `check`·`coverage` 가 계획 774 판보다 엄격해졌다 — `_log/status` 원문이 정확히 `00 0 … 28 0`(중복·짝 없는 토큰·순서 이상 거부), `_log` 파일 집합이 `NN.err`·`NN.out`·`status` 와 정확히 같음(없는 `.err` 거부), 단위마다 `-M` 의존 목록 해시를 명세에 고정(`deps_sha256`; 헤더가 빠진 목록 거부), check 기록과 명세의 항목 집합·크기·`verified_bytes` 합계 대조(단위가 빠지거나 중복되거나 합계가 다르면 coverage 거부). 변이 시험은 음성 39 건 거부·대조군 7 건 수락(건너뜀 없음). 계획 774 기록(`m4-m68k-p774-*`)은 이전 도구 판의 역사 기록이며 현재 도구 해시와 맞지 않는다; 현재 수락 근거는 `m4-m68k-p777-*` 와 `m68k-data-status.tsv`(146 행)이다.

## 계획 781 (2026-11-09; 계획 779–780 뒤의 `__data` 지표)

- 무엇이 바뀌었나: 계획 780 에서 `fpsp` 가 자기 `__data` 36 B(9 칸)와 함께 다시 수락되었습니다. 그래서 소유 불명이던 [0x40b30ec, 0x40b3110) 36 B 가 `fpsp` 의 검증된 범위가 되었습니다. 기호 이름은 원본에 없으므로 임시 작성 이름입니다(D178, D024).
- 도구 `m4_m68k_data.py` 를 최소로 바꿨습니다(이전 판 사본 `scratch/p781/m4_m68k_data.py.before781`).
  - spec 의 선택 키 `m5compare`(없으면 이전 상수)를 `pins`·`coverage` 가 씁니다.
  - `selftest` 는 검사 기록 경로를 인수로 받습니다.
  - 양성 대조는 실제 spec·도구 해시로 검증해, 낡은 기록이면 거부합니다.
- spec `08_build/artifacts/m4p781/spec.json`: 계획 777 의 단위 13·R 3·기준 객체·의존 목록 해시·대조군은 그대로 두었습니다. 기준 스테이지는 `m4p779-base-stage`, M5 근거는 `08_build/artifacts/m4p779/m5compare`, 고정 해시는 새 값입니다.
- run `m4p781-a1`(수집, 명령 29, 명령 줄은 777 과 계획 번호만 다름) 결과:
  - `check`(`m4-m68k-p781-check-20261109.json`): 16/16 OK, 검증 7740 B.
  - `selftest`(`m4-m68k-p781-selftest-20261109.json`): 음성 39·양성 7, 777 과 같은 대조군·같은 결과.
  - 따로 시험한 것: `m5compare` 가 없으면 이전 M5 고정 해시 `94af9e6d…` 가 그대로 나옵니다. spec 해시나 도구 해시를 바꾼 낡은 기록은 거부됩니다.
- R·D 회귀(`m4-m68k-p781-rd-20261109.json`, 기준 `m4p777-a1/out`): 16 객체 모두 `canon`·헤더·절이 같습니다.
  - 11 객체는 파일째 같습니다.
  - `pmap.h` 를 포함하는 5 객체(`fd_global`·`scsiconf`·`kern_exec`·`mach_process`·`ns_timer`)는 COMMON `_pv_head_table`·`_pv_list_zone` 만 더해졌습니다(STABS 각 +2, 판정하지 않음).
- `coverage`(`m4-m68k-p781-coverage-20261109.json`, 표 `06_reconstruction/m68k-data-status.tsv`):
  - 147 범위(M4 38·M5 94·M5-refresh 2·M4-data 13)이고, 덮은 바이트는 **22547 / 22552 B = 99.98 %** 입니다.
  - 빈 구간은 1 B 정렬 채움 다섯 곳 5 B 뿐입니다(원본 0·기호 없음; P2 링크에서 ld 의 정렬 채움으로 설명됨, 계획 778.17). 2 B 이상의 빈 구간은 0 이고, 겹침은 `tty_pty` 4 B 뿐입니다.
  - 이전 표와 비교하면 새 범위는 `fpsp` [0x40b30ec, 0x40b3110) 하나이고, 빠진 범위는 없습니다.
- 계획 777 의 기록을 다시 검증하려면 이전 도구 사본과 계획 779 이전 상태표 사본(`scratch/p781/m68k-m4-status.tsv.before779`)이 함께 필요합니다(방법은 `m4-m68k-p781-rd-20261109.json` 의 `replay_plan777`).
- 한계: 바이트 일치는 원본 소스의 증명이 아닙니다. `fpsp` 칸의 이름·형·배열 꼴은 정해지지 않았습니다.
