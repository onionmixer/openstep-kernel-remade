# 커널 소스 복원 작업계획 — 보관 §772–777

`02_plan/RECONSTRUCTION_PLAN.md` 의 §772–777(m68k `__DATA,__data` 검증(D176·D177)과 디스크 정리)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-09, D026 방식, 사용자 지시 “RECONSTRUCTION_PLAN.md 문서에서 진행이 완료된 내용은 기존의 규칙처럼 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 772. 남은 M4 점검 — 행 단위·바이트 단위로 다시 센 결과 (조사만, 2026-11-08; 07·상태표 불변, 커밋 안 함)

목적: 사용자 질문 "남은 작업" 에 답하려고 상태표(`06_reconstruction/m68k-m4-status.tsv`, 객체 76)와 인벤토리(`m68k-m4-inventory.tsv`, 188 행)를 python 으로 다시 셌습니다. 코드 변경은 없습니다.

### 772.1 정정 (제 오류)
- 직전 보고의 "미수락 행 14 개" 는 제 산수 오류였습니다. 올바른 값: 188 행 − 상태 도구의 `rows_covered` 151(행 148 + 쪼개져 덮인 행 3) = 37 = 부분 행 20(`rows_tiled` 아닌 부분 행; 상태 도구는 이 20 행의 `bytes_min` 47048 B 를 합계에 넣지 않음) + 그 밖 17(`m68k-165` 와 자료 행 `m68k-381`–`396`).
- 직전 보고의 "`m68k-165` 는 새 소스를 쓸지 결정 필요" 는 틀렸습니다. 행 165(`_ns_callout_init`·`_ns_timer_init`, [0x404e3a8, 0x404e420) 120 B)는 07 `v183.34/m68k/src/kern/ns_timer.c`(계획 468, M5 덮어쓰기)가 이미 덮고, §468 의 자리 지정 L1 에서 큐 여덟 함수가 MATCH 였습니다(`02_plan/RECONSTRUCTION_PLAN.md` 3996·4203 행의 "고른 까닭"과 보관 파일 `02_plan/plans/RECONSTRUCTION_PLAN-448-469.md` 970·1044·1079 행에 기록). 이 120 B 는 M4 가 아니라 M5 에서 끝난 것을 인벤토리 분류가 M4 로 남긴 것입니다.

### 772.2 바이트 단위 결과 (python)
- 부분 행 20 개와 행 165 의 행 범위 [start_lo, end_hi) 를 수락 객체 76 개의 [start, end) 로 덮어 보면, 행 165 의 120 B 만 비고 부분 행 20 개는 빈틈 0 B 입니다(함수 표 `m68k-functions.tsv` 기준 미수락 함수도 행 165 의 2 개뿐). 따라서 상태표의 78.15 % 는 행을 합계에 넣지 않는 규칙에서 나온 하한이고, 코드 바이트의 실제 미수락은 (행 165 를 M5 로 보면) 0 B 입니다. 한계: 함수 표에 없는 코드 바이트는 보지 않았습니다.
- M4 수락 객체는 `__text` 기준입니다. `__data` 는 36 객체가 낸 L1 구간(전부 byte_differences 0·refs_differ 0·refs_unverified 0)이 `__DATA,__data`(0x40ad964, 22552 B)의 6785 B(30.09 %)를 덮습니다. 빈 구간 6 곳 합 15767 B: [0x40adb34, 0x40b082c) 11512 · [0x40b087c, 0x40b122e) 2482 · [0x40b125f, 0x40b1260) 1 · [0x40b128c, 0x40b14a6) 538 · [0x40b206c, 0x40b207c) 16 · [0x40b2cba, 0x40b317c) 1218.
- 자료 행 16 개(`m68k-381`–`396`, 자료 구간 상한 합 11270 B): `ev`·`km`·`od`·`snd_dspdev`·`kernel_pmon` 의 `__data` 안에 시작 번지가 있는 5 개(`m68k-390`–`394`)는 이미 수락 객체가 덮고, 나머지 11 개(`init_sysent`·`tty_conf`·`uipc_proto`·`vfs_conf`·`in_proto`·`ufs_tables`·`param`·`counters`·`conf`·`ioconf`·`vers`)는 위 빈 구간 안에 있습니다. 이 11 개의 x86 쪽 소스는 07 에 있습니다(`init_sysent.c`·`vfs_conf.c`·`uipc_proto.c`·`conf/{ioconf,param,vers}.c`·`bsd/dev/i386/conf.c` 등; `find` 로 확인).
- **(정정됨, 772.4)** 빈 `__data` 15767 B 는 M4 수락 객체만 센 값입니다. M5 객체의 `__data` 는 이미 검증되어 있어서 실제 미검증은 7789 B 입니다.

### 772.3 다음에 정할 것 (코딩 전, 사용자 결정 필요)
- (사용자 결정 2026-11-08: 가 — `__data` 검증을 M4 범위에 넣고 도구를 확장) M4 수락 도구(`m4_m68k_status.py`·probe)는 `__text` 크기·시작 번지를 전제로 하므로 `__text` 가 없는 자료 전용 객체를 받으려면 도구 변경이 필요합니다. `__data` 15767 B 의 검증을 M4 범위로 넣을지, M5 의 `__data` 검증으로 따로 둘지는 사용자 결정입니다. 결정 뒤에 계획·codex 검토(코딩 전)를 합니다.


### 772.4 정정 (제 오류, 같은 날): M5 객체의 `__data` 는 이미 검증되어 있음
- 772.2 의 "M5 L1 은 `__data: unverified` 로 남음" 은 틀렸습니다. 근거로 든 `in_bootp` 줄은 §503 당시(초기) 상태였습니다. M5 객체의 최신 L1 기록(`08_build/artifacts/m*p*/**/l1-x86-*.json` 21156 개를 객체별로 가장 큰 계획 번호로 고름; 객체 207)을 python 으로 세면: 자료 구간이 있는 객체 95(전부 `byte_differences` 0; 배치 "given by symbol" 69·"inferred, verified by L1d" 26), 없는 112. 예: `m5p488-a1/l1-x86-tty.json` 의 `__DATA,__data` 0x40ae25e 590 B 가 `given by symbol`·차이 0.
- 그래서 M4 객체와 M5 95 객체의 검증된 `__data` 범위를 합쳐 다시 계산한 결과(`scratch/p772/data_cov.json`): 덮은 것 14763 B(65.46 %), 못 덮은 것 7789 B, 빈 구간 18 곳. 772.2 의 15767 B·"M5 도 섞임" 은 이 값으로 대체합니다. **(773.6 에서 다시 정정: M4 객체는 36 이 아니라 37, M4/M5 겹침 4 B, `ns_timer` 8 B 는 §469 가 검증 → 최종 14771 B·미포함 7781 B·실제 작업 7776 B)**
- 빈 구간 18 곳의 정체(원본 바이트·기호표·자료 지도의 owner 로 확인):
  - 1 B 짜리 5 곳(0x40ae955·0x40aeb6b·0x40aee5d·0x40af2d7·0x40b125f): 모두 값 0, 기호·owner 없음 — 정렬 채움으로 보입니다(소유 객체는 이 계획에서 정하지 않음).
  - 자료 전용 객체 11 개의 본체(773.6: 이 목록에서 `ns_timer` 8 B 는 빠짐): `init_sysent` 1476(`_sysent`·`_nsysent`), `tty_conf` 484, `uipc_proto` 170, `vfs_conf` 164, `in_proto` 354(`_inetsw`·`_inetdomain`, owner 에 `ip_input` 도 있음), `ufs_tables` 620, `param` 234, `counters` 20(값 0), `conf` 2482(`_bdevsw`·`_cdevsw` 등), `ioconf` 와 `vers`(구간 0x40b2cba–0x40b317c 1218 B 안).
  - owner 없음: 0x40b128c–0x40b14a6 538 B(`_vol_check_delay`·`_fc_thread_init` 등 기호 10), 0x40b206c–0x40b207c 16 B(`_scsi_sdswlist`), 0x40b2cba–0x40b30c4 1034 B(`_bus_cinit`·`_bus_dinit`; 자동 생성 `ioconf` 구간으로 보이나 미확인), `ns_timer` 의 8 B(값 0, 기호 없음; owner `x86-ns_timer`) — 773.6 에서 이미 검증됨으로 정정.
  - 1 B 5 곳을 뺀 실제 미검증 `__data`: 7784 B (python: 7789 − 5) — 773.6 에서 7776 B 로 정정.


## 773. 남은 `__data` 7784 B 검증 계획 — 1 단계는 진단만 (사용자 결정 "가", 코딩 전, 2026-11-08; 07·상태표 불변)

### 773.1 목표와 범위
- 목표: §772.4 의 미검증 `__data` 구간(1 B 정렬 채움 5 곳 제외 13 곳, 7784 B)을 원본 바이트와 같은 객체 `__data` 로 재현해 L1 으로 확인합니다. 사용자가 M4 범위에 넣는 쪽("가")을 골랐으므로 결과는 M4 수락 체계에 기록합니다(방식은 773.4).
- 범위 밖: `__bss`(기존 zerofill 절차 그대로), 1 B 채움(원본 값 0 확인만 하고 소유를 정하지 않음), 새 기능 추가(재구성만; 모든 변경은 원본 바이트가 요구).

### 773.2 단위(미검증 구간 → 후보 소스; 모두 후보일 뿐 바이트로 확인 전)
| 구간 | B | 기호 | 같은 이름 소스(찾음: `find` 로 01_resources·07 전체) |
|---|---|---|---|
| 0x40adb54 | 1476 | `_sysent`·`_nsysent` | 07 `src/bsd/kern/init_sysent.c`, NeXTMach `bsd/init_sysent.c` |
| 0x40ae4ac | 484 | `_linesw`·`_nldisp` | 07 `src/bsd/kern/tty_conf.c`, NeXTMach `bsd/tty_conf.c` |
| 0x40ae694 | 170 | `_unixsw`·`_unixdomain` | 07 `src/bsd/kern/uipc_proto.c` |
| 0x40ae796 | 164 | `_vfssw`·`_vfsNVFS` | 07 `src/bsd/vfs/vfs_conf.c` |
| 0x40ae95e | 354 | `_inetsw`·`_inetdomain` | 07 `src/bsd/netinet/in_proto.c`(owner 에 `ip_input` 도 있음 — 경계 확인 필요) |
| 0x40af336 | 620 | `_around`·`_inside`·`_fragtbl124` 등 | 07 `src/bsd/ufs/ufs_tables.c` |
| 0x40af65e | 234 | `_bsd_copyright`·`_cmu_copyright`·`_next_copyright` 등 | 07 `src/conf/param.c` |
| 0x40af768 | 20 | `_c_thread_*`(값 0) | 07 `src/kern/counters.c` |
| 0x40b087c | 2482 | `_bdevsw`·`_cdevsw` 등 | x86 판 07 `src/bsd/dev/i386/conf.c` 는 i386 용이므로 m68k 소스가 아님; NeXTMach `next/conf.c`(m68k)가 후보 |
| 0x40b2cba–0x40b317c | 1218 | `_bus_cinit`·`_bus_dinit`(1034 B, 생성 구간으로 보임)·`_pseudo_inits`(`ioconf`)·`_version*`(`vers`) | 07 `src/conf/ioconf.c`·`vers.c` 는 x86 판(773.6: `vers.c:11` 은 1999 `RELEASE_I386`, 원본은 1997 `RELEASE_M68K`); `ioconf` 표 생성 후보 코드는 NeXTMach `src/config/mkioconf.c` |
| 0x40b128c | 538 | `_vol_check_delay`·`_fc_thread_init` 등 10 | owner 없음 — D0 에서 소유 객체부터 찾음 |
| 0x40b206c | 16 | `_scsi_sdswlist` | owner 없음(scsi 계열 추정) |
| ~~`ns_timer` 8 B~~ | 8 | — | **삭제(773.6)**: §469 최종 객체 `F469__ns_timer.o` 의 L1 이 `[0x40af93c, 0x40af944)` 를 검증함 |

### 773.3 단계
1. **D0 진단(07 불변; 773.6 으로 도구 전제 정정):** 후보 소스를 M5 와 같은 옵션을 명시적으로 복제한 새 진단 명령(`m5_m68k_srcvar.cc_line` 은 계획 429·430 명령에 같은 소스 경로가 있어야 해서 이 11 소스에는 쓸 수 없음)으로 컴파일해 일반 `l1_compare.py`(`m0_m68k_l1.py` 래퍼는 `__text` 를 요구함)의 `--place-from-image` 등으로 `__DATA,__data` 를 원본 구간에 놓고 `byte_differences`·`refs_differ`·`refs_unverified` 를 단위별로 기록합니다. 먼저 확인할 것: (가) L1 이 `__text` 없는 객체를 받는지, (나) 컴파일이 m68k 에서 되는지, (다) 소유 객체가 없는 3 곳(538·16·1034 B)과 `ns_timer` 8 B 의 소유자. 실기 컴파일(`kr_run.py`)과 L1 은 새 run ID(대문자 금지·재사용 금지)로 합니다.
2. **D1 판정:** D0 결과를 단위별로 SAME(차이 0·참조 확인) / 소스 수정 필요(07 표시 줄 또는 m68k 덮어쓰기) / 새 소스 필요로 나눕니다. 새 소스·가칭 이름·머리 파일 위치가 생기면 사용자 결정(AskUserQuestion)을 받습니다.
3. **D2 07 반영·수락(코딩 전 계획·codex 검토를 한 번 더):** 수락 기록 형식과 상태 도구 변경(773.4)을 정한 뒤 구현합니다.

### 773.4 수락 체계 확장(D2 에서 확정; 지금은 설계 가설)
- 현재 M4 도구는 인벤토리 행의 `__text` 범위(`span`)·`text_size`·L1 `__TEXT,__text` 배치를 전제로 합니다(`m4_m68k_probe.py:150–`·`:337–354`·`m4_m68k_status.py:200–`). `__text` 없는 객체를 그대로 넣으면 `full_span`·`text_size` 가 맞지 않으므로, 가설: 자료 전용 객체는 별도 종류("data-only")로 두고 상태표에 `data_bytes`·L1 `__data` 구간을 적으며, 기존 코드 바이트 지표(78.15 %)와 섞지 않고 `__data` 지표(검증 B / 22552 B)를 따로 냅니다. 기존 76 객체와 상태표 행은 바꾸지 않습니다.
- 회귀 관문(미리 정함): 기존 M4 객체 76 의 객체 해시·상태표 76 행 불변, M5 205 줄 회귀, x86 입력·gate 같음, 07 스냅샷 차이는 의도한 파일만.

### 773.5 위험(미리 적음)
- `conf`(m68k)·`ioconf`·`vers`·생성 구간은 x86 판 소스가 정답이 아닐 수 있습니다(NeXTMach `next/conf.c` 는 1990 판이라 1997 원본과 다를 수 있음). 같으면 바이트로, 다르면 원본 바이트에서 직접 쓰는 방식(D174 와 같은 선례)이 되며 그때 사용자 확인이 필요합니다.
- 참조 텍스트는 후보일 뿐이고 바이트 일치만 증거입니다(`AGENTS.md`). 같은 바이트의 중복 문자열 때문에 원본 소스와 같다는 증명은 아닙니다.


### 773.6 codex 검토 판정표 (회신 task `kv1wkbdmv`; 전건 이 세션에서 다시 열거나 실행해 확인)

내가 틀렸던 것(먼저): ① M4 `__data` 객체는 36 개·6785 B 가 아니라 **37 개·6789 B**(상태표 행마다 최종 해시가 맞는 L1 기록을 골라 python 으로 재계산) ② "M4/M5 겹침 0" 은 틀림 — **`tty_pty` 4 B**(`m4p764/m4p764-a1/l1-tty_pty-F.json` 과 `m4p764/m5compare/l1-x86-tty_pty.json` 이 둘 다 [0x40ae690, 0x40ae694) 를 검증: 겹침 검사 출력) ③ `ns_timer` 8 B 를 미검증으로 센 것 — 최신 기록 glob 에 `x86-ns_timer` 가 없었을 뿐 §469 최종 객체가 이미 검증 ④ `m3_m68k_config.py` 를 ioconf 생성 도구로 적은 것(문서 머리 1–16 행은 `DRIVERKIT 0` 가설 시험) ⑤ "ioconf·vers 는 x86 판일 가능성" — 실제로 x86 판임.

| codex 주장 | 내 검증(명령·열람) | 판정 |
|---|---|---|
| 14763 B·7789 B·18 구간·1 B 5곳·7784 B 는 glob 방식으로 재현됨 | `scratch/p772/cov2.py` 출력: base union 14763·gaps 18·7789 | ✅ |
| M4 37 객체·6789 B, M4 단독 빈 구간 7곳·15763 B | 같은 출력 `M4 data sections 37 6789`, `M4 union 6789 gaps 7 15763` | ✅ (내 36·6785·15767 이 틀림) |
| M5 객체 207·자료 95·합 7978 B, glob 21156 | 같은 출력 | ✅ |
| `tty_pty` 4 B 겹침 | 같은 출력 `OVERLAP M4:tty_pty M5:x86-tty_pty 0x40ae690 0x40ae694` | ✅ |
| `ns_timer` 8 B 는 §469 가 검증, 보충 시 14771 B·미포함 7781 B·작업 7776 B(12 구간) | `l1-F469.json` `__DATA,__data` size 8·address 67828028(=0x40af93c)·차이 0·`inferred, verified by L1d`; 입력 해시 둘 다 python 으로 일치(`mach_kernel`·`F469__ns_timer.o`); 합집합 재계산 14771·gaps 17·7781·non-1B 7776·12 | ✅ |
| `stage_m68k.py:443–444` 가 ns_timer 가 205 줄에 없다고 적음 | 440–446 행 열람: 443·444 행 주석 "ns_timer is not among the 205 reference lines" | ✅ |
| `m0_m68k_l1.py:155–159`·`:360` 이 `__text` 를 요구 | 155–159(`tidx`·`drop('no external __text symbol')`)·360(`ts = … [0]`) 열람 | ✅ |
| `m5_m68k_srcvar.cc_line` 은 계획 429·430 명령에 같은 소스 경로가 정확히 하나여야 함, 자료 전용 소스 11 개는 `hits 0` | `m5_m68k_srcvar.py:33,105–112` 열람; python 으로 11 개 직접 호출: 10 개 `AssertionError 0`(init_sysent·tty_conf·uipc_proto·vfs_conf·in_proto·ufs_tables·param·counters·ioconf·vers), `kern/ns_timer.c` 만 찾음 | ✅ |
| `m4_m68k_probe.py` 59·69(명세 키 제한), 168–169(함수 표 경계), 181–183(행 정확 좌표), 350·359–360(`full_span`·판정), 389–392(gate); `m4_m68k_status.py` 202–203·216·219–223·234–240 | 각 줄을 sed 로 열어 내용 확인(위 출력) | ✅ |
| `vers.c:11` 은 1999 `RELEASE_I386`, 원본 `_version` 은 1997 `RELEASE_M68K` | `sed 8,11p 07_kernel/src/conf/vers.c`; python 으로 원본 0x40b3119 부터 읽음: `NeXT Mach 4.2: Sun Apr 27 13:42:14 PDT 1997; …RELEASE_M68K` | ✅ |
| 버스 표 생성 후보 코드는 NeXTMach `src/config/mkioconf.c:1317,1351` | 두 줄 열람(`bus_cinit[]`·`bus_dinit[]` 출력) | ✅ |
| `_vol_check_delay` 등 후보는 NeXTMach `nextdev/fd_global.c:24,31–33,61,94,118,145,153,161`, `_scsi_sdswlist` 는 `nextdev/scsiconf.c:74` | 각 줄 열람(`vol_check_delay`·`fc_thread_init`·`fc_thread_timer_started`·`fcdriver`·`fd_drive_info`…, `scsi_sdswlist[]`) | ✅ (후보일 뿐, 원본 객체 소유는 미확인) |
| 표의 기호 줄 번호(`S:`) | 대부분 일치; 내 검사 목록의 4 곳 불일치는 codex 가 범위(276–280·3202–3205)로 적은 것을 내가 한 점으로 읽은 탓이고 범위 안에 있음(279·277·3202·3203) | ✅ |
| 일반 `l1_compare.py` 는 `__text` 없는 객체를 받음, 단 `--place-from-image` 는 기호 이동량이 하나일 때만 | `l1_compare.py:269–299`·`:467–479` 열람(앞서 직접 읽음) | ⚖️ 코드 읽기만; 실제 객체 실행은 D0 |
| 자료 전용 종류 추가는 `data_bytes` 열만으로 안 됨(위 줄들과 충돌), 자료용 별도 규칙·기록 형식이 핵심 | 위 줄 열람과 일치 | ✅ 채택 |
| `l1_compare.py:411–412` 가 크기 0 섹션을 판정에서 제외 | 405–426 행 열람: 줄 번호는 410(`if not s['size']:`)–411(`continue`)로 codex 보다 1 줄 앞; 내용은 사실. 추가 발견: 413 행 `st not in ('ok', 'placement-only', 'literal')` — `placement-only`·`literal` 도 사유 없이 통과 | ✅ (줄 번호는 정정; 수락 기준에 반영: 자료 섹션 상태가 `ok` 여야 하며 `placement-only` 는 재현으로 받지 않음) |
| 1 B 5곳은 미해결로 유지 | 원본 값 0·기호 없음은 내 계산과 일치; 해석은 후보 | ✅ 채택(편입하지 않음) |
| M4/M5 `M:` 자료 지도 줄 번호들(M:5·16·17…) | **열지 않음** | ⚠️ 미확인 — 계획서에 옮기지 않음 |

채택하는 계획 변경:
- 수치를 14771 B(65.50 %)·미포함 7781 B·실제 작업 7776 B(12 구간)로 바꿉니다(위 표 ✅ 행).
- 순서를 codex 제안대로 바꿉니다: **증거 목록 보완(수락 기록에서 객체·소스·명령·L1 연결; glob 최신 기록만으로 판정하지 않음) → 커버리지 정정(이 절) → 단위별 대상·컴파일 명령·수락 조건 확정 → D0(07 불변) → 단위별 수정 계획 검토 → 07 반영·회귀·수락.**
- 자료 수락 기준을 D0 전에 정합니다: SAME = 차이·`refs_differ`·`refs_unverified` 0 **그리고** 섹션 크기 > 0·배치 주소가 목표 구간과 같음·기호 대응이 맞음(크기 0 객체의 성공을 재현으로 받지 않음).
- 회귀 대상에 `ns_timer`(205 줄 밖)를 포함합니다. 함수·자료 포인터 표는 주소 상수·바이트 배열로 덮어 맞추지 않고 원본이 요구하는 기호·재배치 관계를 보존합니다. 참고 소스를 컴파일되게 하려는 스텁·기능 활성화는 하지 않습니다(재구성만). 참조 텍스트를 채택하면 출처·리비전·라이선스·변경 기록을 D2 관문에 둡니다.
- 도구 방침: 기존 단정을 느슨하게 하지 않고 자료용 경로를 따로 둡니다(원본 섹션 경계·양의 크기·기호 오프셋·자료 배치·재배치 검증 요구). 기존 객체의 자료 증거와 새 자료 전용 객체를 구분합니다.


### 773.7 D0 진단 결과 (2026-11-08; 07·상태표·도구 불변; 기록 `09_validation/reconstruction/m4-m68k-p773-d0-20261108.json`, SHA-256 앞 16 자 `0e9cd2b5d9c3a758`)
- 방법: 기존 M4 스테이지 `08_build/runs/tools/m4p770a1-stage`(11 MB)와 계획 430 다수 옵션 묶음(python 으로 113 줄 중 같은 묶음임을 확인)으로 실기 `/bin/cc -arch m68k` 컴파일 후 일반 `l1_compare.py --place-from-image`(`m0_m68k_cause.run_l1`). 실행 ID: `m4p772-d0-1`(07 소스 10 개 그대로), `m4p772-d0b-1`(NeXTMach 3 파일 그대로: 1990 포함 경로·설정 개수 헤더가 없어 컴파일 실패 — 기록용), `d0b-2`(`fd_global.c`·`scsiconf.c` 에 D104 포함 치환만), `d0c-1`(07 `init_sysent.c` 에 두 항목만 NeXTMach 줄). 명령 파일 `08_build/artifacts/m4p772/`, 진단 사본 `scratch/p772/d0b-src/src/diag772/`.
- 판정 기준(773.6 대로): `OBJECT_MATCH`·사유 없음·`__data` 크기가 목표 구간과 같고 주소가 목표와 같음·차이 0·`refs_differ` 0·`refs_unverified` 0·배치 `given by symbol`·입력 해시 일치(python assert). **10 단위 모두 통과, 4076 B.**
  - A. 07 소스 그대로(2046 B): `tty_conf` 484·`uipc_proto` 170·`vfs_conf` 164·`in_proto` 354·`ufs_tables` 620·`param` 234·`counters` 20.
  - B. NeXTMach 파일 + D104 포함 치환(554 B): `nextdev/fd_global.c` → [0x40b128c, +538)(`__cstring` 370 B 는 "literal, 내용으로 참조 확인"), `nextdev/scsiconf.c` → [0x40b206c, +16). 치환은 `<next/printf.h>`→`<kernserv/printf.h>`·`<next/psl.h>`→`<m68k/psl.h>`·`<nextdev/disk.h>`→`<dev/disk.h>`·`<nextdev/busvar.h>`→`<dev/busvar.h>`·`<nextdev/scsireg.h>`→`<dev/m68k/scsireg.h>`·`<nextdev/scsivar.h>`→`<dev/m68k/scsivar.h>`(기존 `scsi.c` 67–71 행의 선례).
  - C. 07 `init_sysent.c` + 두 항목(1476 B): 07(x86 판)의 139 번 `nosys,0`·151 번 `nosys,0` 이 원본 m68k 와 달랐고(처음 비교: 바이트 1(`+1209`, 원본 2)·참조 2 — python 으로 풀면 139 번 호출이 원본 `_sigreturn`, 151 번이 `_machparam`·인자 2), NeXTMach `bsd/init_sysent.c:321`(`syss(sigreturn,0)`)·`:342`(`syss(machparam,2)`) 줄로 바꾼 사본이 `OBJECT_MATCH`(참조 184/184). 나머지 항목(152 `setprivexec`·153 `getposix` 등)은 07 그대로 원본과 같음.
- 남은 3 단위 3700 B(= 7776 − 4076, python): `vers` 108(x86 `vers.c` 는 1999 `RELEASE_I386` 줄이라 크기 110·불일치; 원본은 1997 `RELEASE_M68K`), `ioconf` 1110(= `_bus_cinit`·`_bus_dinit` 1034 + `_pseudo_inits` 기호 구간 76(유효 40 + 0 인 36, 774.7); x86 `ioconf.c` 는 `__data` 24 B 뿐이고 5 바이트 다름), `conf` 2482(NeXTMach `next/conf.c` 는 설정 개수 헤더 `ldd.h`·`km.h`·`ev.h`·`vol.h` 등이 없어 컴파일 못 함: `d0b-1`). 재료: NeXTMach `conf/`(`MASTER.next`·`files.NeXT`·`param.c`·`version*`)와 설정 도구 `src/config/`(`mkioconf.c`·`mkheaders.c`) — 이것으로 m68k `ioconf.c`·개수 헤더를 만들 수 있는지는 미확인.
- 알아둘 점: 이는 진단이며 07 반영·수락이 아닙니다. B·C 는 07 에 새 파일(`fd_global.c`·`scsiconf.c`)과 m68k 덮어쓰기(`init_sysent.c`)가 필요하고(출처·변경 기록·고지), A 7 개는 소스 변경이 없습니다. 7 개 A 는 소스를 그대로 쓰므로 "원본과 같은 소스" 증명이 아니라 바이트 일치만 증거입니다(원칙).
- 다음(D1·D2, 코딩 전 계획+codex 검토): ① 수락 경로(자료 전용 객체를 M4 상태 도구에 넣는 방식, 773.4) ② 남은 3 단위(`vers` 바이트에서 쓰기·`ioconf`·`conf` 의 설정 도구 경로 또는 바이트에서 쓰기 — D174 와 같은 선례인지 사용자 확인) ③ 새 파일 이름·머리 파일 위치.


## 774. m68k 자료 구간 수락 경로 — 단위 10 개(4076 B)의 07 반영·수락 계획 (코딩 전, 2026-11-08)

### 774.1 범위와 근거
- 대상: §773.7 의 D0 통과 10 단위. A(07 그대로 7: `tty_conf`·`uipc_proto`·`vfs_conf`·`in_proto`·`ufs_tables`·`param`·`counters`), B(NeXTMach `nextdev/fd_global.c`·`scsiconf.c` + D104 포함 치환 2), C(07 `init_sysent.c` + 139·151 번 두 항목 1). 합 4076 B.
- 범위 밖(사용자 확인 뒤 별도): `vers` 108·`ioconf` 1110·`conf` 2482 (774.6). 1 B 채움 5곳은 미해결로 둠.
- 사실(이 세션에서 열어 확인): 덮어쓰기 규칙 `stage_m68k.py:580–617` `check_derived` 는 "표지 없는 줄이 07 본 파일과 같아야 함(삭제·변경 금지)" 이므로 C 의 두 항목은 기존 `nosys` 줄을 지우지 못하고 `#if !m68k` / 기존 줄 / `#else` / NeXTMach 줄 / `#endif` 를 표지 줄로 삽입해야 합니다(`init_main` 덮어쓰기의 `#ifndef m68k` 선례, 계획서 §454). `m4_m68k_probe.py:205–232` 의 M4 컴파일 줄은 소스의 x86 줄 옵션을 쓰고(D0 는 계획 430 다수 묶음을 썼음), `scsi.c:67–71` 에 D104 포함 치환 선례가 있음.
- 원칙: 재구성만(원본 바이트가 요구하는 변경만), 참조 텍스트는 후보(바이트 일치만 증거), 기존 단정 불완화.

### 774.2 설계
1. **07 변경(최소):**
   - 새 파일 `07_kernel/src/machdep/m68k/fd_global.c`·`scsiconf.c`(NeXTMach `nextdev/` 원문 + 포함 치환 줄에 계획 표지; 원래 고지·머리 보존; D013). `M4FILES[774]` 등록(`stage_m68k.py`), 각 파일은 스테이지 `src/machdep/m68k/` 로 들어가며 기존 규칙(모든 `.c` 등록)을 따름.
   - 새 덮어쓰기 `07_kernel/v183.34/m68k/src/bsd/kern/init_sysent.c` = 07 본 파일 + 표지 줄(`MARKERS` 에 계획 774 등록, 파일별 줄 수 일치). x86 트리 불변: `x86gate` 7 묶음 모두 같음.
   - `PROVENANCE.tsv`·`MODIFICATIONS.md`(출처 URL·커밋·경로:줄·고지·변경)와 `06_reconstruction/evidence/m68k-<이름>.md`·diff 갱신(기존 형식).
2. **수락 도구는 새로 만들고 기존 probe/status 단정은 건드리지 않음**(codex §773.6: `m4_m68k_probe.py:59,69,168–169,181–183,350,359–360,389–392`·`m4_m68k_status.py:202–203,216,219–223,234–240` 은 `__text`·행 좌표를 전제 → 완화하면 기존 76 객체 판정이 흔들림). 새 `10_tools/reconstruction/m4_m68k_data.py`:
   - `spec`: 단위(이름·소스 rel·목표 주소·크기·종류 A/B/C), 스테이지 계획 번호.
   - `check`: 단위마다 (가) 컴파일 stderr·종료 0 (나) L1 `OBJECT_MATCH`·사유 [] (다) `__DATA,__data` 크기 = 목표 크기·주소 = 목표 주소·차이 0·`refs_differ` 0·`refs_unverified` 0·배치 `given by symbol`(`placement-only`·`literal` 은 `__data` 로는 불인정) (라) `__TEXT,__text` 크기 0·허용 절은 `__data`·`__cstring`(`literal`)만, 그 밖 절 내용 있으면 실패 (마) 정의 전역 기호가 원본 기호표와 이름·주소가 같고 정의 기호 집합이 원본의 해당 구간 기호와 같음, 정의되지 않은 이름은 모두 원본에 있음 (바) 입력 해시(객체·`mach_kernel`) 일치 (사) 단위 사이 범위 겹침 0.
   - `coverage`: 검증된 `__data` 범위를 **명시 기록 목록(해시 고정)** 에서 모아 합집합·빈 구간을 계산: M4 는 상태표 행마다 L1 기록의 입력 객체 해시 = 상태표 `obj_sha256`; M5 는 계획 764 `m5compare` 205 객체(기록 해시 고정) + 205 줄 밖 3 객체(`ns_timer` §469 기록·`kern_exec` §445·`mach_process` §444: 각 최종 기록 존재와 해시 확인); 새 자료 단위. glob 의 "객체별 최신 계획 번호" 방식은 쓰지 않음(codex §773.6 반례 `ns_timer`).
   - 출력: `06_reconstruction/m68k-data-status.tsv`(범위당 한 줄: 목표 범위·출처 기록 경로·SHA-256·종류) + 요약(덮은 B·빈 구간 목록·1 B 채움 별도). 기존 `m68k-m4-status.tsv`·코드 바이트 지표(78.15 %)는 바꾸지 않고 `__data` 지표를 따로 냄.
3. **실기 빌드 순서:** `stage_m68k.py --plan 774 stage`(새 스테이지, 이름 새로) → x86gate → 새 run ID 로 컴파일 줄(소스당 `-c` 한 줄 + `-M` 의존 한 줄: 포함 경로가 SDK/07 어디서 왔는지, i386 헤더 0 확인) → collect → `m4_m68k_data.py check`. 컴파일 옵션은 probe 와 같은 규칙(소스의 x86 줄; 없으면 계획 430 다수 묶음)으로 하고, D0 객체와 `canon`·`obj_sig` 가 같음을 확인(다르면 원인 기록 뒤 L1 재판정).
4. **회귀 관문(미리 정함):** (가) 기존 M4 객체 76 의 `obj_sha256`·상태표 76 행 바이트 단위 불변(상태 도구 재실행 결과 파일 같음) (나) 스테이지 차이 = 새 파일 2 + 덮어쓰기 1 + 등록뿐 (다) `stage_m68k.py --plan 774 cmd` 의 205 줄이 §764 것과 계획 번호 정규화 후 같으면 M5 회귀 생략, 다르면 M5 205 회귀(§761.2 기준) (라) x86gate 일곱 모두 같음 (마) 07 스냅샷 차이가 의도한 파일만(`snap07.py` 계열) (바) 최종 run 은 collect 하지 않는 규칙이 이 도구에는 해당하지 않음 — 이 도구는 collect 된 `out/` 를 읽음(상태 도구와 다름; 확인 필요).

### 774.3 D1 진단(코딩 전 확인, 07 불변)
1. C 의 조건 컴파일 꼴(`#if !m68k … #else … #endif`)이 D0c 의 치환 꼴과 같은 객체 바이트를 내는지(`m68k` 매크로가 `-arch m68k` 에서 정의되는지는 `init_main` 덮어쓰기와 같은 방식으로 확인).
2. 소스의 x86 줄 옵션과 계획 430 다수 묶음의 차이(`cmd_cmd` 의 옵션 차이 출력과 같은 방법)와 A·B·C 객체 `canon` 동일성.
3. `fd_global.c`·`scsiconf.c` 가 `M4SRC`(machdep/m68k)에서 컴파일될 때 포함 경로(`-Isrc/src/machdep`, `<dev/…>`)와 `"fd.h"` 따옴표 포함(`fd_global.c:12`)이 풀리는지(D0b-2 는 `src/src/diag772/` 에서 컴파일됨: 위치가 달라 따옴표 포함의 탐색 기준이 다를 수 있음).
4. 증거 목록(M4 76 객체 + M5 205+3 객체; 774.7: M4+M5 합집합)이 §773.6 의 14771 B 와 같은지(774.7 에서 재확인함: 같음).
5. 새 파일 이름이 기존 객체·심볼과 겹치지 않는지(`_fcdriver`·`_vol_check_delay` 등 정의가 M4 `fd_*.c` 와 중복되지 않는지: 이미 수락된 `fd_subr` 등이 정의하는 전역과 비교).

### 774.4 위험(미리 적음)
- B 의 두 파일은 "원본 객체의 소유 파일"이 확인된 것이 아니라 이름·바이트가 맞는 NeXTMach 후보입니다(바이트 일치만 증거; 같은 바이트의 다른 소스일 가능성). 증거 문서에 이 한계를 적습니다.
- C 는 07 본 파일이 x86 판(`restoration edit`)이라 m68k 에서 두 항목이 달랐다는 사실이 바이트로 확인된 것이며, NeXTMach 의 해당 줄은 후보입니다. 덮어쓰기는 이 두 항목만 바꿔야 하고 다른 항목은 건드리지 않습니다(기능 추가 금지).
- 새 도구는 기존 도구보다 검사가 느슨해지지 않도록 변이 시험을 넣습니다(객체 바이트 한 개 변조, 주소 한 개 변경, 크기 0 객체, `placement-only` 절 → 모두 거부되어야 함).

### 774.5 산출물
`m4_m68k_data.py`, `06_reconstruction/m68k-data-status.tsv`, 확인 기록 `09_validation/reconstruction/m4-m68k-p774-*.json`, 증거 `06_reconstruction/evidence/m68k-data-*.md`, PROVENANCE·MODIFICATIONS·DECISIONS 갱신, HANDOFF·계획서 결과 절. 커밋은 하지 않음.

### 774.6 사용자 결정이 필요한 것 (구현 전에 AskUserQuestion)
- `vers`(원본 바이트에서 쓴 m68k 덮어쓰기 `conf/vers.c`), `ioconf`(원본 바이트가 `mkioconf` 꼴 표로 구조체 경계까지 풀림(774.7): 컨트롤러 `fc0`·`sc0`·`oc0`+센티널, 장치 20(+센티널; `fd0`·`sd0–6`·`st0–1`·`sg0–3`·`od0–1`·`en0`·`dsp0`·`np0`·`sound0`)·`pseudo_inits` 유효 4 항목 40 B(`pty_init` 32·`venip_config` 1·`zsintsetup` 2·`enintsetup` 1 + 영 센티널; 뒤 36 B 는 모두 0 이고 소유 근거 없음 — 774.7) — NeXTMach `conf/MASTER.next:119–221` 의 1990 판 장치 목록과 거의 같고 `sg` 개수·`en` init 등이 다름), `conf`(NeXTMach `next/conf.c` + 설정 개수 헤더 `ldd.h`·`km.h`·`ev.h`·`vol.h` 등을 새로 만들어야 컴파일됨)을 FPSP D174 방식("NeXTMach 맞는 부분 + 나머지는 원본 바이트")으로 써도 되는지, 생성 헤더를 둘 곳.


### 774.7 codex 검토 판정표 (회신 task `ksl74zee2`; 전건 이 세션에서 다시 열거나 실행해 확인) 와 계획 보완

내가 틀렸던 것(먼저): ① `EXCEPTS[774]` 와 `OVLFROM` 등록이 계획에 없었음(`--plan` 은 `int(a[1]) in EXCEPTS` 일 때만 받음 `stage_m68k.py:814`; 새 덮어쓰기는 `OVLFROM` 기본 0 이라 과거 계획 스테이지에도 적용됨 `:206`·`:672`) ② D0 의 `OBJECT_MATCH` 를 정의 기호 전체의 통과로 확대할 뻔함 — `scsiconf` 객체에는 원본에 없는 COMMON `_disk_chip` 이 있음 ③ "`_pseudo_inits` 76·완전히 풀림" 은 과도: 유효 40 B + 0 인 36 B ④ 774.3 D1-4 의 "M5 쪽 … 합집합" 은 M4+M5 합집합이라고 써야 함(위에서 고침) ⑤ `MASTER.next` 인용 범위에서 pty 줄(`:118`)을 빠뜨림.

| codex 주장 | 내 검증(명령·열람) | 판정 |
|---|---|---|
| D0 10 단위 모두 OBJECT_MATCH·크기·주소·차이 0, 합 4076 B, 진단 JSON 해시 `0e9cd2b5…0a3c` | `sha256sum` 출력 `0e9cd2b5d9c3a7587a59940f0d0d4f827820b0702241648c8c78318b227b0a3c`; D0 때 python assert 로 10/10·4076 확인(§773.7) | ✅ |
| `check_derived` 는 `#if !m68k`/기존 줄/`#else`/후보 줄/`#endif` 꼴 표지 삽입을 허용, 본 파일에 표지가 있으면 거부, 기존 줄에 표지 금지 | `stage_m68k.py:580–617` 열람 + 직접 메모리 시험: 두 항목에 8 줄 삽입한 사본 `PASS`; 표지 없는 줄(`adjtime` 인자)을 바꾼 음성 대조 `rejected: overlay source differs from 07 main file` | ✅ |
| `--plan 774` 에는 `EXCEPTS[774]` 필요; 새 덮어쓰기에는 `OVLFROM` 필요; `M4FILES[774]` 는 누적 목록 | `stage_m68k.py:814`(`in EXCEPTS`)·`:206`(`OVLFROM = {tty_pty: 764}` 선례)·`:670–674`(`PLAN < OVLFROM.get(rel,0)` 이면 건너뜀)·`:654–658`(전 계획 합집합으로 미등록 검사, `M4FILES[max(k<=PLAN)]` 만 복사) 열람 | ✅ |
| x86gate 는 M4SRC 등록 검사를 하지 않음(별도 경로) | `:720–726` 열람(`x86_prefix()` 묶음 매니페스트 검사) | ✅ |
| `m68k` 조건부 선택 선례 | `grep` 출력: `init_main.c:251–257`·`ufs_vnodeops.c:399,404`·`kern_exec.c:482,537`·`mach_process.c:170`·`ufs_inode.c:471` 등 `#if m68k`/`#ifndef m68k`(정확한 매크로 값은 전처리로 확인하지 않음 → D1) | ⚖️ 선례는 사실, 값은 미확인 |
| `"fd.h"` 는 `machdep/m68k/` 위치에서 `-Isrc/generated` 로 풀림(선례 `fd_subr.c:28`, `v183.34/m68k/generated/fd.h`) | `fd_subr.c:28` 열람(`#import "fd.h"`), 생성 헤더 목록에 `fd.h` 있음; 새 위치에서의 `-M` 은 미실행 | ⚖️ 선례 사실, 새 파일 확인은 D1 |
| coverage: M4 76(자료 37, 6789 B)·M5 208(자료 96, 7986 B)·겹침 4 B(`tty_pty`)·합집합 14771·빈 구간 17·7781·1 B 제외 12 구간·7776 | `scratch/p772/cov3.py` 출력(입력 해시 전부 assert 일치: M5 `m5compare` 205 + `ns_timer` 8 B·`kern_exec` 270 B·`mach_process` 자료 없음; M4 는 상태표 해시로 고른 76) | ✅ |
| `kern_exec`·`mach_process`(·`ns_timer`) 증거는 오래된 `machdep/m68k/thread.h` 로 빌드됨 | `m5p444-fin1`·`m5p445-fin1`·`m5p469-a1`(+var 런)의 `src/src/machdep/m68k/thread.h` SHA `e472f042eb0655f5`, 현재 스테이지·07 덮어쓰기 `9c2b3e04273da339`(`git status`: 07 덮어쓰기 `thread.h` 는 미커밋 수정) | ✅ (원본 바이트 증거로는 유효, 현재 의존 헤더로 재빌드한 증거는 아님: 해당 자료 278 B) |
| 새 객체의 전역 SECT 정의는 기존 M4 강한 정의와 충돌 없음; `_fcdriver`·`_vol_check_delay`·`_scsi_sdswlist` 원본 이름·주소와 맞음 | 내 `scratch/p772/dupsym.py`(SECT 만): 새 13 객체 정의 50, 기존 M4 75 + M5 205 와 겹침 `{}`; `fd_global` SECT 10·`scsiconf` SECT 1 모두 원본에 있음 | ✅ |
| `scsiconf` 에 원본에 없는 COMMON `_disk_chip`(값 2) 유입, 원인은 `<next/cpu.h>`; 기존 수락 M4 객체에는 그런 COMMON 이 없음 | python: `scsiconf` COMMON 32 중 원본에 없는 것 `{'_disk_chip': 2}`·`fd_global` 29 중 0·UNDF 모두 원본에 있음; `cpu.h:67` `u_short disk_chip;`; 수락 M4 76 객체 중 원본에 없는 COMMON 이름을 가진 것 0; D107 선례: `snd_dspreg.h:12` 의 `<next/cpu.h>` 제거 주석 열람 | ✅ |
| 일반 L1 은 COMMON 을 자료 절로 검사하지 않음 | `l1_compare.py:407–426` 열람(절 단위 판정) | ✅ |
| `bus_cinit` 3 항목+센티널(38 B 단위 152 B)·`bus_dinit` 20 항목+센티널(42 B 단위 882 B)·`pseudo_inits` 유효 4 항목(센티널까지 40 B), 뒤 36 B 는 0 | 내 python 디코드(앞서): C0–C2 와 영 항목, D0–D19 와 영 항목, 풀이된 장치 이름·주소 일치; `pseudo_inits` 76 B 중 32 B 뒤 44 B 가 모두 0(그 중 첫 8 B 가 센티널) | ✅ |
| `MASTER.next`: sg 는 `:153` `sg0` 뿐, `en` 은 `:191` 장치뿐(`enintsetup` 없음), pty 32 는 `:118` | 앞서 `grep -n` 출력(118·124·153·166·191 줄) | ✅ |
| 새 도구는 `out/`(collect 후)를 읽어야 하며 기존 상태 도구는 `stage/` 를 읽음 | `kr_run.py:352–359`(`os.rename(stage, out)`)·`m4_m68k_status.py:145–148` 열람 | ✅ |
| NeXTMach `fd_global.c:1–11`·`scsiconf.c:1–12` 머리 고지 보존 필요 | 두 머리 열람(저작·HISTORY 주석) | ✅ |
| 출처 기록 선례 `PROVENANCE.tsv:1155`·`MODIFICATIONS.md:706` | 두 줄 열람(`fd_subr.c` 행) | ✅ |

계획 보완(채택):
1. **등록:** `EXCEPTS[774] = dict(EXCEPTS[770])`, `OVLFROM['src/bsd/kern/init_sysent.c'] = 774`, `M4FILES[774] = list(M4FILES[770]) + ['fd_global.c','scsiconf.c']`; 표지 키는 `MARKERS['plan 774 (m68k)']={rel: 8}` 처럼 줄 수를 맞춤. 과거 계획(≤770) 재스테이지가 바이트 같음을 확인하는 관문을 회귀에 추가.
2. **COMMON 감사:** 새 도구의 기호 검사 (마)를 둘로 나눔 — 대상 `__data` 의 SECT 정의 기호가 원본과 이름·주소가 같고, **COMMON 이름은 모두 원본에 있어야 함**(기존 수락 객체와 같은 기준, D136). `scsiconf` 의 `_disk_chip` 은 `<next/cpu.h>`(`scsiconf.c:25`) 제거(D107 선례)가 가능한지 D1 에서 진단: 제거해도 `OBJECT_MATCH`·COMMON 이름 전부 원본에 있으면 채택(제거는 표지 줄로 기록), 안 되면 사용자에게 올림.
3. **증거의 현재성:** 현재 스테이지 기준 재빌드가 없는 M5 객체(`kern_exec`·`mach_process`·`ns_timer`)는 이 계획의 스테이지에서 재빌드해 L1 로 확인하고, 되지 않으면 coverage 표에 "역사적 증거(오래된 헤더)" 로 표시해 현재 증거와 구분.
4. **D1 진단 보강:** 최종 위치(`src/machdep/m68k/` 의 새 파일 2 개)·최종 옵션(소스의 x86 줄 옵션 규칙)·조건부 꼴·`-M` 의존(헤더 출처, i386 헤더 0)으로 07 불변(scratch 스테이지)에서 컴파일·L1·COMMON 감사; `canon`/`obj_sig` 를 D0 객체와 비교; `m68k` 매크로 값은 전처리 출력으로 확인.
5. **x86gate·과거 스테이지·상태표 불변은 "검증할 조건"** 으로 구현 뒤 실제 비교(지금은 사실이 아님).
6. **변이 시험 추가:** 기호 누락·추가 COMMON·입력 해시 불일치·중복 구간·크기 0 객체·`placement-only` 절을 새 도구가 모두 거부해야 함.
7. §774.6 의 별도 3 단위(`vers`·`ioconf`·`conf`)는 이번 10 단위 수락 근거에 섞지 않음(D174 유사성은 근거가 아님).


### 774.8 D1 진단 결과 (2026-11-08; 07·상태표·도구 불변; 기록 `09_validation/reconstruction/m4-m68k-p774-d1-20261108.json`, 실행 `m4p772-d1-1`)
- 스테이지: `scratch/p772/d1-src`(= 계획 770 스테이지 `m4p770a1-stage` 사본 + 최종 위치의 새 파일 `src/machdep/m68k/fd_global.c`·`scsiconf.c`(포함 치환만)·`scsiconf_nocpu.c`(`<next/cpu.h>` 줄 제거판) + 조건부 꼴 `init_sysent.c`(`#if !m68k`/기존 줄/`#else`/후보 줄/`#endif` 표지 삽입 8 줄) + `diag772/mtest.c`). 컴파일은 소스의 x86 줄 옵션 규칙 = 계획 430 옵션(python: 8 소스 모두 옵션 차이 없음, `fd_subr` M4 줄과 같음).
- 결과(전부 `m0_m68k_cause.run_l1`, 입력 해시 assert):
  - `fd_global` OBJECT_MATCH 538 B(주소·차이·참조 0), COMMON 29 개 모두 원본에 있음, `canon`·`obj_sig` 가 D0 객체와 같음.
  - `scsiconf`(`<next/cpu.h>` 포함) OBJECT_MATCH 16 B 이나 **COMMON `_disk_chip` 은 원본에 없음**(codex 지적 사실). `scsiconf_nocpu`(제거판) OBJECT_MATCH 16 B·COMMON 이름 전부 원본에 있음·`canon` 이 D0 와 같음(`obj_sig` 는 COMMON 하나가 없어져 다름: 예상대로). → 제거판 채택 후보(D107 선례 `snd_dspreg.h:12`).
  - `init_sysent`(조건부 꼴) OBJECT_MATCH 1476 B·참조 184/184·`canon`·`obj_sig` 가 D0c 와 같음. `m68k` 매크로는 전처리 출력으로 **정의되며 값 1**(`int m68k_macro_value = 1 ;`).
  - `-M` 의존: `fd_global` 159·`scsiconf` 123·제거판 122·`init_sysent` 20 헤더, i386 헤더 0.
  - 현재 스테이지로 다시 만든 M5 세 객체: `kern_exec` OBJECT_MATCH(자료 270 B), `mach_process` OBJECT_MATCH, `ns_timer` NOT_MATCH(사유 `__bss` 하나; 자료 8 B 차이 0); 셋 모두 과거 객체와 `canon` 같음, `obj_sig` 는 `stabs` 개수만 다름(1232 대 1207; `thread.h` 변경 영향) → 과거 증거가 현재 스테이지에서도 같은 바이트 결과로 재현됨.
- 결론: 774.7 의 보완 2·3·4 가 D1 에서 해소됨(남은 보완 1·5·6 은 구현 단계에서 검증).


### 774.9 구현·수락 결과와 codex 구현 검토 판정표 (2026-11-08; 커밋 안 함)

결과(요약): 단위 10 개(4076 B) 수락 — 실기 run `m4p774-a1`, 도구 `10_tools/reconstruction/m4_m68k_data.py`, 기록 `09_validation/reconstruction/m4-m68k-p774-{check,selftest,coverage}-20261108.json`, 상태표 `06_reconstruction/m68k-data-status.tsv`(143 행), 증거 `06_reconstruction/evidence/m68k-data.md`·`m68k-{fd_global,scsiconf,init_sysent}.diff`. 검증된 `__data` 18847 / 22552 B = 83.57 %(14771 + 4076, python), 미검증 3705 B = `conf` [0x40b087c, 0x40b122e) 2482 + [0x40b2cba, 0x40b317c) 1218(`ioconf`·`vers`) + 1 B 틈 5곳(값 0·기호 없음, 검증된 바이트로 세지 않음). 07 변경: 새 `src/machdep/m68k/fd_global.c`·`scsiconf.c`, 새 덮어쓰기 `v183.34/m68k/src/bsd/kern/init_sysent.c`(07 본 파일 + 표지 8 줄), 기록 `PROVENANCE.tsv`(1252 행·중복 0)·`MODIFICATIONS.md`·`DECISIONS.md` D176. 등록: `stage_m68k.py` `M4FILES[774]`·`OVLFROM`·`EXCEPTS[774]`·`MARKERS['plan 774 (m68k)']`.

회귀(실제로 실행): `--plan 770 stage` 재스테이지 = 기존 `m4p770a1-stage`(1034 파일 해시 같음); 774 − 770 = 추가 2 + 변경 1; 774 − 764 수락 스테이지 = 추가 `adb.c`·`adb.h`·`fd_global.c`·`fpsp.h`·`fpsp.s`·`scsiconf.c` + 변경 `init_sysent.c`; x86gate 일곱 묶음 같음·`v183` 경로 0; `--plan 774 cmd` 205 줄이 764 것과 계획 번호 정규화 후 같아 M5 회귀 생략; `m4_m68k_status.py` 재실행 결과가 `m68k-m4-status.tsv` 와 바이트 같음(76 객체·78.15 %); 07 스냅샷 차이 = 새 파일 3 + 기록 2.

내가 틀렸던 것(먼저, codex 구현 검토 task `khhppah2r` 로 확인): ① 첫 구현의 `check_unit` 은 객체가 낸 기호가 원본에 있는지만 보고 **원본 구간의 기호를 객체가 정의했는지는 보지 않아** 정의 기호를 지운 객체도 통과함(재현: 첫 구현 코드로 `_linesw` 의 `N_EXT` 를 지운 객체 → `[]`, 새 코드 → `missing ['_linesw']`); 계획 774.2 의 "정의 기호 집합이 원본의 해당 구간 기호와 같음" 을 구현하지 않았음 ② 상태 키·stderr 공백·`-M` 밖 경로·헤더 내용 해시·커널 이미지 해시·컴파일 명령·참조 객체 독립성·check→coverage 해시 재검증이 없었음 ③ `selftest` 가 "기호 누락" 을 원본 기호 사전에서 지우는 방식이라 실제 누락을 못 잡았고 대조 파일이 없으면 시험을 건너뜀 ④ 증거 문서의 "열 가지 변조"(실제 11 개 거부), STABS "1232 대 1207"(`kern_exec` 만), 전역 기호 "50 개"(D0 진단 객체 glob; 최종은 45 개, refresh 포함 73 개) ⑤ 참조 객체 규칙을 "바이트가 달라야 함" 으로 지나치게 엄격하게 넣었다가 A 단위 7 개에서 D0 객체와 최종 객체가 바이트까지 같음(재현성)을 보고 "다른 파일·다른 run 디렉터리·해시 고정" 으로 바꿈.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 정의 기호를 지운 객체가 L1·`check_unit`·`cmd_check` 를 통과함 | 첫 구현 백업(`scratch/p772/backup/m4_m68k_data.py.v1`)에 지운 객체를 넣어 `check_unit` → `[]`; 새 코드 → 거부(위) | ✅ → 양방향 비교 구현, 실제 `N_EXT` 해제 변이 시험 추가 |
| `check` 가 상태 키·stderr 공백·`-M` stderr·`-M` 밖 경로·헤더 내용 해시·커널 해시·컴파일 명령을 검사하지 않음 | 첫 구현 코드 줄 열람(`status = dict(zip…)` 개수·값만, `.strip()`, `-M` `.err` 미열람, `(src/\S+\.h)` 정규식, 객체 해시만); 새 코드에 각 검사 + 변이 시험 28 건 중 해당 항목 모두 거부(`selftest` 출력) | ✅ |
| 참조 객체가 자기 자신이어도 `canon` 비교를 통과함 | 코드 열람(비교 대상이 `u['ref']` 뿐) + 새 시험 `reference is the object itself`·`from the same run`·`hash not pinned` 거부 | ✅ (규칙은 774.9 ⑤ 로 조정) |
| coverage 가 refresh 객체·저장된 L1 해시를 다시 확인하지 않음 | 코드 열람; 새 시험 `L1 record changed after check`·`refresh object changed after check` 거부; 증거 집합 핀(`pins`) 추가 | ✅ |
| 커버리지 수치 18847 / 3700 / 1 B 5곳 / 빈 구간 | `coverage` 재실행: covered 18847·work 3700·gaps≥2 두 곳·1 B 틈 5곳 모두 값 0·기호 없음 | ✅ |
| 07 변경·등록·스테이지 회귀가 계획과 같음 | 위 회귀 항목(내가 직접 실행) | ✅ |
| 증거 문서 수치 오류(11 vs 열 가지, STABS, 50 vs 45/73) | python: 선테스트 JSON `controls` 12 중 거부 11; `obj_sig` 의 `stabs`: `kern_exec` 1232/1207·`mach_process` 644/619·`ns_timer` 942/883; 최종 객체 SECT 45·refresh 포함 73 | ✅ → 문서 수정 |
| D176 의 '사용자 선택 (가)' 는 과장이 아님; cpu.h 제거는 D107 선례 적용이라고 정직하게 기록됨 | 내가 기록한 문장과 사용자 실제 답 "가 로 진행입니다" 대조, `PROVENANCE`·`MODIFICATIONS`·증거 문서 열람 | ✅ |
| 자료 단위에 대한 소유 파일 확정 아님·바이트 일치만 증거 | 증거 문서에 한계 문장 있음 | ✅ |
| 새 도구가 기존 상태 도구보다 느슨한 `-M` 검사를 함 | 상태 도구 `m4_m68k_status.py:145–148`(출력 해시 확인) 열람 + 새 도구에 전체 토큰·내용 해시 검사 추가 | ✅ |

남은 한계(정직하게): 새 도구의 증거는 L1 기록 파일과 객체·L1 해시로 고정되지만, 그 L1 기록을 만든 `l1_compare.py`·`m0_m68k_cause.py` 자체의 신뢰는 기존 M4/M5 와 같은 수준이다. `fpsp` 객체 파일은 수집 트리에 없어 전역 기호 겹침 검사에서 읽지 못했다(그 기호는 원본 text 주소에 있고 이번 단위는 `__data` 주소에 있음). x86gate 는 이번에 새로 실행해 7/7 같음(`08_build/artifacts/m4p774/x86gate`).

다음(사용자 결정 필요): 남은 3700 B 의 쓰기 방식 — `vers`(원본 바이트에서 쓰기), `ioconf`(원본 바이트가 `mkioconf` 꼴 표로 구조체 경계까지 풀림), `conf`(NeXTMach `next/conf.c` + 설정 개수 헤더) 에 D174 와 같은 방식을 적용할지(774.6).


## 775. 디스크 정리 — 중복 스테이지 디렉터리 3848 개 삭제 (사용자 지시 "디스크 정리 진행", 2026-11-08)

- 상황: 저장소 볼륨 여유 3.7 GB(저장소 자체는 약 46 GB, `08_build` 35 GB). `08_build/` 는 전부 git 추적 밖(`.gitignore:65`, `:13`)이라 삭제하면 복구할 수 없으므로 "다시 만들 수 있는 사본"만 지운다.
- 기준(python 으로 직접 해시): `08_build/runs/tools/*-stage` 디렉터리의 모든 파일이 그 스테이지를 입력으로 쓴 완료된 run(`prepare.json` 의 `src`, `DONE`, `input.actual == input.expected`)의 `08_build/runs/<run>/src/<경로>` 와 경로·SHA-256 이 같을 것. 첫 판정은 run 입력 목록에 `run.cmd`·`run.sh` 두 개가 더 있는 것을 몰라 "같음"을 0 건으로 냈고(내 조건 오류), 부분집합 조건으로 고쳐 4114 개가 중복으로 나왔다. 지우기 전에 후보 3848 개의 모든 파일(1,468,748 개)을 run 복사본과 다시 직접 비교해 불일치 0 을 확인했다.
- 제외(지우지 않음): `10_tools` 코드와 `08_build/artifacts` 명세·probe json 이 이름으로 가리키는 스테이지 99 개, x86 기본 스테이지 `s6l*-g*-stage` 168 개(`stage_m68k.py` `base_stage()` 가 복사 원본으로 씀), `m4p774-base-stage`·`m4p770a1-stage`, run 이 쓰지 않은 365 개(588 MB), 복사본이 일치하지 않는 12 개. 매니페스트(`*.manifest.json`)는 전부 남김. run 디렉터리·L1 기록·`09_validation`·`08_build/artifacts` 는 건드리지 않음.
- 절차: 삭제 전에 격리 디렉터리로 이름만 옮기고(되돌릴 수 있음) 검증 → 통과 후 삭제. 검증: `m4_m68k_status.py` 출력이 `06_reconstruction/m68k-m4-status.tsv` 와 바이트 같음(76 객체), `m4_m68k_data.py check`(검증 4076 B)·`coverage` 결과 TSV 가 `m68k-data-status.tsv` 와 같음, `stage_m68k.py --plan 774`·`--plan 770 stage` 의 매니페스트가 저장본과 같음, x86gate 7/7 같음.
- 결과: 3848 개 디렉터리·1,468,748 파일·7463 MB(겉보기 크기) 삭제, 볼륨 사용 927 G → 916 G(여유 3.7 GB → 15 GB). 삭제 목록과 복사본 위치와 복원 방법: `09_validation/reconstruction/disk-cleanup-p775-stage-dirs-20261108.json`(복원: `cp -a 08_build/runs/<run_copy>/src/. 08_build/runs/tools/<stage>/`).
- 남은 큰 항목(손대지 않음): `08_build/runs` 의 run 디렉터리 약 4700 개(약 17 GB; 각각 입력 사본 포함, 증거), `09_validation/images` 5.2 GB·`reports` 2.9 GB, `08_build/artifacts` 2.3 GB(plan 별 x86gate 사본 등), `11_emulation` 1.9 GB. 이들을 줄이려면 어떤 기록이 어느 run 을 가리키는지 따로 조사해야 하며 사용자 확인이 필요하다.


## 776. 남은 `__data` 3700 B (`vers`·`ioconf`·`conf`) — 1 단계는 진단만 (코딩 전, 2026-11-08; 07·상태표·도구 불변)

### 776.1 사실(이 세션에서 열어 확인; python 디코드)
- 대상(계획 772.4·774.9): `conf` [0x40b087c, 0x40b122e) 2482 B, `ioconf`+`vers` [0x40b2cba, 0x40b317c) 1218 B. 사용자 결정 774.6(D174 와 같은 방식을 적용할지)은 **아직 답을 받지 못했다.** 이 계획의 1 단계 D0 는 결정과 무관한 진단(07 불변, scratch 스테이지)이고, 07 반영(2 단계)은 결정 뒤에 한다.
- `conf` 2482 B = `bdevsw` 576(24 항목 × 24 B) + `nblkdev` 4(=24) + `cdevsw` 1892(43 항목 × 44 B) + `nchrdev` 4(=43) + `mem_no` 4(=3) + `swapdev` 2(`0x0400` = `makedev(4,0)`)(python: 576+4+1892+4+4+2 = 2482 = 구간 길이). 원본 기호 6 개: `_bdevsw`·`_nblkdev`(0x40b0abc)·`_cdevsw`(0x40b0ac0)·`_nchrdev`(0x40b1224)·`_mem_no`(0x40b1228)·`_swapdev`(0x40b122c). NeXTMach `next/conf.c`(505 행, 1990)와 구조가 같다(`bdevsw[]`·`nblkdev = sizeof…`·`cdevsw[]`·`nchrdev`·`mem_no = 3`·`swapdev = makedev(4, 0)`)이나 항목 배치가 다르다: 원본 `bdevsw` 는 1 `fd`(`fdsize` 포함)·2 `od`·5 `nodev,nulldev,nodev…`·6 `sd`(`sdsize` 포함)·그 밖 `nodev` 로 24 항목, NeXTMach 판은 `ldd`·`rd`·`sw` 슬롯과 `fd`·`sd` 의 크기 칸이 `nodev` 이다. 원본 `cdevsw` 43 항목: 0 `cn*`, 1 `nodev` 전부(ldd 없음), 2 `sy*`, 3 `mm*`, 4·5 `pts*`·`ptc*`, 6 `log*`, 7 sw, 8 `np_*`, 9 `od*`, 10 `ev*`, 11 `zs*`, 12 `km*`, 13 `vid*`, 14 `sd*`, 15–31 `seltrue` 만(17 개 같은 항목), 32 `nulldev` 줄, 33 `sg*`, 34 `st*`, 35·37·38 `seltrue`/`nulldev` 변형, 36 `snd_unix_ioctl`, 39 `nps_*`, 40 `evsioctl`, 41 `fd*`, 42 `vol*`. NeXTMach `conf.c` 는 `<ldd.h>`·`<od.h>`·`<rd.h>`·`<sd.h>`·`<fd.h>`·`<zs.h>`·`<km.h>`·`<sg.h>`·`<st.h>`·`<ev.h>`·`<vol.h>`·`<sound.h>`·`<iplmeas.h>`·`<nfsmeas.h>`·`<np.h>`·`<pty.h>` 개수 헤더를 부른다. 07 `v183.34/m68k/generated/` 에는 `od·rd·sd·sc·sg·st·fd·zs·np·sound·iplmeas` 가 있고 `ldd·km·ev·vol·nfsmeas·pty` 가 없다(앞서 컴파일 실패 `m4p772-d0b-1`).
- `ioconf`: `bus_cinit`(0x40b2cba, 38 B × 4 = 152 B: `fcdriver`(csr 0x2014100)·`scdriver`(0x2014000)·`ocdriver`(0x2012000) + 영 항목)·`bus_dinit`(0x40b2d52, 42 B × 21 = 882 B: `fd0`·`sd0–6`·`st0–1`·`sg0–3`·`od0–1`·`en0`(0x2006000)·`dsp0`(0x20000d0)·`np0`(0x200f000)·`sound0`(0x200e000) + 영 항목)·`pseudo_inits`(0x40b30c4: 유효 4 항목 `{32,pty_init}`·`{1,venip_config}`·`{2,zsintsetup}`·`{1,enintsetup}` + `{0,0}` = 40 B). 생성기 NeXTMach `src/config/mkioconf.c:1317–1443` 가 `bus_cinit[]`·`bus_dinit[]`·`pseudo_inits[]`(`NeXT_pseudo_inits`: `0,	0,` 로 끝)를 이 꼴로 쓴다. `pseudo_inits` 40 B 뒤 [0x40b30ec, 0x40b3110) 36 B 는 모두 0 이고 기호가 없다 — 소유 근거 없음(`vers` 앞 채움인지 다른 파일의 자료인지 모름). 07 `src/conf/ioconf.c`(x86)는 이미 "생성기 출력 꼴을 원본 바이트에서 쓴 것(plan 398), config 실행이 아님" 이라고 밝힌 선례다.
- `vers`: 원본 [0x40b3110, +108): `version_major=4`·`version_minor=2`·`version_variant[]=""`·`version[]="NeXT Mach 4.2: Sun Apr 27 13:42:14 PDT 1997; root(rcbuilder):Objects/mk-183.34.obj~4/RELEASE_M68K\n"`(정수 8 + 빈 variant 1 + 문자열 98 + 끝 NUL 1 = 108 B, 채움 0 B — 776.5 에서 "1 B 채움" 정정). 07 `src/conf/vers.c`(x86)는 1999 `RELEASE_I386` 문자열이라 안 맞음(773.7).

### 776.2 D0 진단(결정과 무관; 07 불변)
1. `vers`: 07 `conf/vers.c` 와 같은 줄 꼴에 문자열만 원본 바이트로 바꾼 사본을 컴파일 → L1(`__data` 108 B·기호 4 개).
2. `ioconf`: 07 `conf/ioconf.c`(x86) 꼴 + `mkioconf.c` 출력 꼴(`extern` 선언, `bus_cinit[]`·`bus_dinit[]`의 `&fcdriver` 등 항목, `pseudo_inits[]`)로 원본 바이트에서 쓴 사본 → 컴파일 → L1. 36 B 영 구간이 이 객체의 `__data` 크기에 들어가는지 확인.
3. `conf`: NeXTMach `next/conf.c` 를 D104 포함 치환 + 개수 헤더(없는 6 개는 진단용으로 시도한 값 1/0)로 컴파일해 항목별 차이를 python 으로 분류: (가) 그대로 맞음 (나) 슬롯 값만 다름(예: `fdsize`·`sdsize` 칸) (다) 항목 수·배치가 다름. 개수 헤더 값: `conf.c` 는 `#if N… > 0` 만 쓰므로 원본 항목 이름에서 정해지는 것은 0 인지 양수인지뿐이고 양수의 크기(예: `NKM` 1 인지 2 인지)는 바이트로 정해지지 않는다(776.5 정정) — 항목별로 "0/양수" 로 기록.
4. 각 사본은 `m4_m68k_data.py check_unit` 기준(기호 집합 양방향·COMMON 감사 포함)으로 판정하고, 결과를 "NeXTMach 와 맞는 부분 / 원본 바이트에서 직접 쓴 부분"으로 줄 단위 비율로 적는다.

### 776.3 2 단계(결정 뒤)
- 07 반영은 D174 와 같은 형식(NeXTMach 텍스트 + 원본 바이트로 쓴 줄 표시)이고, 새 개수 헤더는 `v183.34/m68k/generated/` 의 **덮어쓰기 경로**(`stage_m68k.py` `OVL` 복사, `OVLFROM` 에 774 이후 첫 계획 번호 등록; `M4HEADERS` 아님 — 776.5 정정)로 둔다. `m4_m68k_data.py` 에 단위 3 개를 추가하되 기존 검사를 완화하지 않으며, 1 B 틈 5곳과 36 B 영 구간은 검증된 바이트로 세지 않는다(소유 불명 영 바이트).
- 회귀 관문: 774 와 같음(기존 M4 상태표 바이트 같음·x86gate·재스테이지·M5 205 명령 비교·07 스냅샷).

### 776.4 위험(미리 적음)
- `conf`·`ioconf` 는 항목이 대부분 바이트로 정해져 "원본 소스가 이렇게 생겼다"는 증명이 아니라 같은 바이트를 내는 한 형태일 뿐이다(증거 수준: 바이트 일치).
- 1990 NeXTMach 와 1997 원본의 슬롯 차이(`bdevsw` 24 항목 등)는 1997 설정에서 온 것으로 보이나 설정 파일이 없어 확인 불가 — 새 기능 추가가 아니라 원본 바이트가 요구하는 항목이다.
- 개수 헤더 값(`NKM`·`NEV`·`NVOL` …)이 어떤 설정에서 왔는지는 바이트로 정해지지 않는 부분이 있을 수 있다(같은 바이트를 내는 다른 값). 그 경우 사용자 결정(D107 꼴)으로 올린다.


### 776.5 codex 검토 판정표 (회신 task `kc67gthmp`; 전건 이 세션에서 다시 열거나 실행해 확인) 와 계획 수정

내가 틀렸던 것(먼저): ① `vers` "끝 0 과 1 B 채움" — 실제는 8+1+98+1 = 108 B, 채움 0 ② 헤더 등록 경로를 `M4HEADERS` 라 적었으나 `v183.34/m68k/generated/` 는 덮어쓰기 경로(`stage_m68k.py:674–687`, `OVLFROM`) ③ "개수 헤더 값은 추측이 아님" — `#if N… > 0` 이라 0/양수만 정해짐 ④ "`bdevsw` 0·3·4·7–23 이 모두 nodev 항목" — 0·7 은 `psize` 가 `nodev`, 3·4·8–23 은 `psize`·`flags` 가 NULL 0 이라 같은 초기화가 아님 ⑤ "35·37·38 변형" 에서 37 은 `nulldev` 가 없는 `seltrue` 만 항목(15–31 과 같음) ⑥ `ioconf` 를 1110 B 단위로 잡으면 36 B 영 구간이 검증된 범위에 들어가 버림 — 단위는 1074 B.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `conf` 2482 = 576+4+1892+4+4+2, 기호 6 개, `nblkdev` 24·`nchrdev` 43·`mem_no` 3·`swapdev` 0x0400 | 앞서 python 디코드 + 합 계산(출력 2482 = 2482) | ✅ |
| `bdevsw` 0·7 `psize=nodev`, 3·4·8–23 은 NULL 0, 1 `fdsize`, 6 `sdsize` | 앞서 디코드 출력(B0…B23) | ✅ |
| `cdevsw` 15–31 이 같은 항목 17 개, 37 도 같은 항목 | 앞서 디코드(`same as previous` 16–31, C37 = C15 꼴) | ✅ |
| NeXTMach `bdevsw` 8 항목(예약 24 는 주석), `cdevsw` 43 항목 | python: `/*0*/…` 주석 계수 8·43, 매크로 전개 후 8·43 | ✅ |
| 후보 개수값(`NLDD=0 NOD=2 NRD=0 NSD=7 NFD=1 NZS=2 NKM=1 NSG=4 NST=2 NEV=1 NVOL=1 NSOUND=1 NIPLMEAS=0 NNFSMEAS=0 NNP=1 NPTY=32 NeXT=1 DEBUG=0`)로 전개하면 `cdevsw` 43 항목 전부 일치, `bdevsw` 앞 8 항목은 `fdsize`(1)·`sdsize`(6) 칸만 다름 | 내가 직접 `cpp -P -undef -traditional` 로 NeXTMach `conf.c` 를 전개해 항목별 비교: `cdevsw mismatches []`, `bdevsw first 8 mismatch idx [1, 6]` | ✅ (컴파일·L1 검증은 아님: 전개 비교) |
| 없는 개수 헤더 `ldd km ev vol nfsmeas pty`, 있는 헤더와 값(`od` 2·1, `rd` 0, `sd` 7, `sg` 4, `st` 2, `fd` 1·1, `zs` 2, `np` 1, `sound` 1, `iplmeas` 0) | python `os.path.exists` 와 각 파일 첫 줄 출력 | ✅ |
| 개수 헤더는 설정(장치 목록·`f_needs`)에서 만들어지며 소스 import 로 자동 생성되지 않음 | `mkheaders.c:58–64`·`:78–135` | ⏭️ **열지 않음**(내용은 계획에 쓰지 않음) |
| `bus_ctrl` 38 B·`bus_device` 42 B(2 B 정렬)·`bus_cinit` 3+센티널 152 B·`bus_dinit` 20+센티널 882 B·`pseudo_inits` 유효 40 B | 앞서 디코드(C0–C2, D0–D19, 센티널, `pseudo_inits` 4 항목) | ✅ |
| 36 B(`[0x40b30ec, 0x40b3110)`)가 모두 0, 반열린 구간에 기호 없음(끝 포함하면 `_version_major`) | python 출력 `36 True`, `symbols … []` | ✅ (소유 불명) |
| `vers` 108 B = 8+1+98+1, 채움 없음 | python 출력 `8 + 1 + 98 + 1 = 108` | ✅ (내 "1 B 채움" 이 틀림) |
| `v183.34/m68k/generated/` 는 `OVL`+`OVLFROM` 경로, `M4HEADERS` 는 별도 | `stage_m68k.py:642–652`·`:674–690`·`:207` 열람 | ✅ |
| `check_unit` 의 정의 기호 검사는 external SECT 만; static 자료는 못 봄; coverage 는 L1 `__data` 전체 크기를 집계하므로 36 B 를 단위에서 제외하려면 단위 크기를 1074 B 로 해야 함 | `m4_m68k_data.py` 코드 설계(내가 쓴 것)와 일치: `defined` 는 `ext` 만, `data_range` 는 L1 섹션 크기 | ✅ |
| x86 `conf/ioconf.c` 에 "written from the original bytes (plan 398)" 문장 | 앞서 `ioconf.c:2–6` 열람 | ✅ |
| D0(후보 소스 작성·컴파일)을 결정 전에 하는 것이 774.6 의 "구현 전에 AskUserQuestion" 과 충돌할 수 있음 | 계획 `:4873–4874` 문장 열람 | ✅ 채택 → D0 의 "후보 소스 작성" 은 결정 뒤로 미룸(읽기 전용 분석은 이미 끝남) |

수정된 계획:
- 단위 경계: `conf` 2482 B, `ioconf` [0x40b2cba, 0x40b30ec) 1074 B(= 152 + 882 + 40), `vers` 108 B → 합 3664 B. 그 사이 [0x40b30ec, 0x40b3110) 36 B(전부 0, 기호 없음, 소유 불명)는 1 B 틈 5곳과 같은 "미해결 영 바이트" 로 남기며 임의 채움 배열을 추가하지 않는다.
- 읽기 전용 분석 결과: NeXTMach `conf.c` + 개수 후보값은 `cdevsw` 43/43 항목과 `bdevsw` 6/8 항목(+ `fdsize`·`sdsize` 두 칸 차이)이 일치하고, `bdevsw` 8–23(16 항목, `{nodev,nodev,nodev,nodev,0,0}`)은 원본 바이트에서만 알 수 있음. `ioconf`·`vers` 는 구조가 바이트로 완전히 풀리고 07 에 x86 선례(원본 바이트에서 쓴 생성기 출력 꼴)가 있음.
- D0 의 "후보 소스 작성·컴파일" 과 07 반영은 사용자 결정(774.6) 뒤에 한다. 결정에 필요한 위 사실은 이 절에 모았다.


## 777. `conf`·`ioconf`·`vers` 3664 B 의 07 반영·수락 결과 (사용자 결정 D177 "세 단위 모두", 2026-11-08; 커밋 안 함)

결과(요약): 단위 3 개를 07 에 반영해 수락했다 — 새 `src/machdep/m68k/conf.c`(NeXTMach `next/conf.c` + 표시 줄)·`ioconf.c`·`vers.c`(원본 바이트에서 쓴 생성기 출력 꼴)와 새 개수 헤더 `v183.34/m68k/generated/{ldd,km,ev,vol}.h`(`config_options-m68k.tsv` 행 4 개 → `gen_config_headers.py --arch m68k`; 기존 `pty.h`·`nfsmeas.h` 는 값이 같아 그대로). 실기 run `m4p777-a1`(명령 29, 전부 종료 0·stderr 0 B)에서 13 단위(기존 10 + 새 3) `OBJECT_MATCH`, 검증 7740 B(= 4076 + 3664, python), 검증된 `__data` **22511 / 22552 B = 99.82 %**, 미검증 41 B = 1 B 틈 5곳 + 소유 불명 영 36 B([0x40b30ec, 0x40b3110)). 기록 `09_validation/reconstruction/m4-m68k-p777-{check,selftest,coverage}-20261108.json`, 표 `06_reconstruction/m68k-data-status.tsv`(146 행), 명세 `08_build/artifacts/m4p777/spec.json`, 증거 `06_reconstruction/evidence/m68k-data.md`("계획 776–777" 절)·`m68k-conf.diff`, `PROVENANCE.tsv`(1259 행·중복 0)·`MODIFICATIONS.md`·D177. 등록: `stage_m68k.py` `M4FILES[777]`·`OVLFROM`(헤더 4 개)·`EXCEPTS[777]`.

회귀(실제로 실행): `--plan 770`·`774 stage` 재스테이지의 `files` 목록 동일(774 는 매니페스트 전체 동일, 770 은 `base` 필드만 다름); 777 − 774 = 추가 7(소스 3 + 헤더 4)·변경 0; 777 − 764 수락 스테이지 = 새 파일들과 `init_sysent.c` 뿐; x86gate 7/7·`v183` 경로 0; `--plan 777 cmd` 205 줄이 764 것과 정규화 후 같음(M5 회귀 생략); `m4_m68k_status.py` 결과가 `m68k-m4-status.tsv` 와 바이트 같음(76 객체·78.15 %); 스테이지 전체에서 새 헤더 이름을 맨 이름으로 포함하는 파일은 `conf.c` 하나; 07 스냅샷 차이 = 새 파일 7 + 기록 2.

내가 틀렸던 것(먼저): ① 사용자 응답 때 개수 헤더를 6 개라 적었으나 `pty`·`nfsmeas` 는 이미 있어 새로 만든 것은 4 개 — D177 에 정정해 적음(D0 가 두 헤더를 같은 값으로 덮어써서 통과한 것을 구현 전에 알아챘음) ② 776.1 의 `vers` "1 B 채움"(실제 채움 0)·"헤더를 `M4HEADERS` 로 등록"(실제는 덮어쓰기 경로)·"개수 헤더 값은 추측이 아님"(0/양수만 정해짐) — 776.5 에서 정정 ③ `ioconf` 를 1110 B 단위로 잡으려 했음(36 B 영 구간이 검증 범위에 들어감) → 1074 B ④ 첫 `ioconf.c` 컴파일이 `nextdev/busvar.h` 경로로 실패(`m4p777-d0-1`) ⑤ 새 도구(`m4_m68k_data.py`)에 느슨한 곳이 남아 있었음 — codex 구현 검토가 상태 원문 중복·짝 없는 토큰, stderr 파일 부재, 의존 목록의 헤더 누락, check 기록에서 단위 삭제를 통과시키는 반례 5 건을 찾았고 나도 재현했다(아래) ⑥ 보강 직후 새 대조군 둘이 실패한 것은 시험 코드의 `n = len(status)` 가 토큰 수를 센 내 오류(검사 쪽 결함 아님).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `conf.c` 변경이 서술과 정확히 같고 고지 보존, `cdevsw` 43/43·`bdevsw` 두 칸 차이 | 내가 `cpp -P -undef -traditional` 전개 비교(앞서): `cdevsw mismatches []`·`bdevsw first 8 mismatch idx [1, 6]`; 저장 diff `m68k-conf.diff` 91 행 열람 | ✅ |
| `ioconf.c`·`vers.c` 가 원본 바이트와 같음 | 컴파일 후 L1 `OBJECT_MATCH`(조건: 크기·주소·차이 0·기호 집합 양방향) | ✅ |
| 774·777 재스테이지 매니페스트 동일, 770 은 `files` 만 동일(`base` 필드가 `m0p770-a1-stage` 대 `s6ln-g1a-stage`) | 저장 `m4p770a1-stage.manifest.json` 의 `base` 를 python 으로 읽음: `m0p770-a1-stage`; 내 비교 함수는 `files` 만 비교했음 | ✅ → 증거 문서 문구 정정 |
| 새 헤더가 M5 소스 입력에 영향 없음(`pty.h`·`nfsmeas.h` 불변, 새 헤더 포함 소스 없음) | 스테이지 전 `.c .h .s .m` 에서 정규식 전수 검색 결과 `conf.c` 하나; 앞서 `pty.h`(`NPTY 32`)·`nfsmeas.h`(`NNFSMEAS 0`) 내용 확인 | ✅ |
| `m4p777-a1` 상태 00–28·stderr 0 B·RUN 줄 일치·13 단위 재판정 통과 | `check` 재실행 OK 13/13, `expected_lines` 로 명령 파일 재생성이 실행에 쓴 파일과 `cmp` 동일 | ✅ |
| coverage 22511/22552, 빈 구간 1 B 5곳 + 36 B, 모두 0·기호 없음 | `coverage` 출력(`work 36`, 빈 구간 크기 `[1,1,1,1,1,36]`), 36 B 가 모두 0 임을 python 으로 확인 | ✅ |
| PROVENANCE 7 행 해시·MODIFICATIONS 4 행이 맞음, D177 이 6→4 차이를 정직하게 적음, `km/ev/vol` hypothesis·`ldd` confirmed 적절 | 해시는 생성 시 `hashlib` 로 계산; D177 문장 열람 | ✅ |
| `config_options-m68k.tsv:24`·`PROVENANCE.tsv` 의 "모든 칸이 nodev" 는 부정확(`bdevsw[0]` 은 포인터 5 칸 nodev, flags 0) | python 디코드: `bdevsw[0]` = (nodev ×5, 0) | ✅ → 두 곳 정정 |
| 자동 검사에 누락 5 건: ① stderr 파일을 없애도 통과 ② status 중복 키 통과 ③ 짝 없는 토큰 통과 ④ `-M` 에서 헤더를 지워도 통과 ⑤ check 기록에서 `conf` 를 지우고 `verified_bytes` 를 유지해도 coverage 성공 | 각각 현재 함수에 반례를 넣어 재현: 상태 중복 `True`·짝 없는 토큰 `True`(통과)·소스만 있는 의존 목록 `True`·`conf` 없는 check 기록 `True`; `.err` 부재는 코드(`glob` 은 존재하는 파일만)로 확인 | ✅ → 모두 고침(strict 상태 토큰, `_log` 파일 집합, `deps_sha256` 고정, 항목·크기·합계 대조) + 변이 시험 11 건 추가(음성 39·대조군 7) |
| 소스는 원칙 부합(기능 추가·임의 채움 배열 없음), 고지 보존, "텍스트 복사 없음" 은 독립 확정 불가 | 내 확인: 36 B 채움 배열을 넣지 않았음; `ioconf`·`vers` 는 원본 바이트에서 쓴 것이라 외부 텍스트를 복사하지 않았음(내가 쓴 것) — 독립 증명은 불가 | ⚖️ 사실이나 증명은 내가 쓴 것에 대한 진술 |

남은 한계: ① 1 B 틈 5곳과 36 B 는 값 0·기호 없음이지만 소유자·정렬 채움 여부 미확정 — 검증된 바이트로 세지 않음 ② `km`·`ev`·`vol` 개수 1 은 가설(바이트는 양수만 정함) ③ `pseudo_inits` 뒤 36 B 를 채우려면 근거가 필요하나 임의 배열은 추가하지 않음 ④ 모든 단위가 바이트 일치만 증거이며 원본 소스와 같다는 증명이 아님.
