# 커널 소스 복원 작업계획 — 보관 §470–482

`02_plan/RECONSTRUCTION_PLAN.md` 의 §470–482(m68k M5: 코드 차이가 남은 19 객체 조사와 `kern_exit`·`kern_proc`·`kalloc`·`mfs_prim`·`cmu_syscalls`·`time_stamp`·`mach_clock`·`igmp`·`kern_fork`·`ipc_mig`·`nfs_client`(보류)·`ufs_subr`·`mach_net`·`netif`·`miniMon`)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-10-23, D026 방식, 사용자 지시 “02_plan/RECONSTRUCTION_PLAN.md 문서를 알맞게 정리”). 본문은 `---` 아래부터입니다.

---

## 470. M5-27 세부 계획 — 코드 차이가 남은 m68k 19 객체의 현재 상태 조사(survey; 07 변경 없음; 코딩 전, 2026-10-16)

사용자 지시(2026-10-16): 남은 작업의 2 번(M5 코드 차이 객체)을 진행합니다. 앞서 "차이가 작은 것부터" 를 권했습니다.

배경:
- 대상은 netif, miniMon, igmp, time_stamp, mfs_prim, nfs_client, kern_fork, cmu_syscalls, ufs_subr, kern_exit, ipc_mig, kalloc, kern_proc, mach_clock, tty, callout, kdp_udp, mach_net, swapfs 입니다.
- 이전 차이 수치는 §441 객체(`08_build/runs/m3p441-cc1`)와 scratchpad 도구로 낸 것이고, scratchpad 집계는 남아 있지 않습니다. 그 뒤 07·덮어쓰기·헤더가 여러 번 바뀌었으므로 지금 상태로 다시 잽니다.
- 원본 객체 범위는 `06_reconstruction/m68k-objects.tsv` 에 19 개 모두 정확한 값(start_lo = start_hi, end_lo = end_hi)으로 있습니다.
  - 크기: netif 1550, miniMon 922, igmp 1420, time_stamp 200, mfs_prim 4360, nfs_client 1224, kern_fork 1468, cmu_syscalls 1682, ufs_subr 1806, kern_exit 3262, ipc_mig 2346, kalloc 764, kern_proc 1824, mach_clock 964, tty 13698, callout 2994, kdp_udp 2238, mach_net 1700, swapfs 3908 B(표의 bytes 열).

방법(읽기 전용 분석; 07 은 바꾸지 않습니다):
1. 컴파일:
   - `stage_m68k.py --plan 469 cmd` 와 같은 205 줄(`ref_lines`)에서 19 객체의 줄만 골라 출력만 바꿉니다(`O470__<base>.o`).
   - 바탕은 지금 스테이징 `m0p469-a1-stage` 이고, run 은 `m5p470-s1` 입니다.
   - 모든 명령이 종료 0 이어야 하고, 19 객체가 모두 있어야 합니다.
2. 실기 읽기 전용 otool: 19 객체의 `otool -tv` 목록을 `08_build/artifacts/m5p470/otool/` 에 받습니다.
3. 새 도구 `10_tools/reconstruction/m5_m68k_survey.py`(읽기 전용; `cmd`·`otool`·`report`)를 만듭니다. 객체마다 다음을 기록합니다.
   - SHA-256, §441 객체와 `canon` 이 같은지. 다르면 그 뒤 바뀐 것이 있다는 뜻이므로 표시합니다.
   - L1(`--place-from-image`) 판정·이유.
   - 원본 범위 시작으로 텍스트 자리를 준 L1(`--place __TEXT,__text=<start>`)의 함수별 판정. 크기가 처음 달라지는 함수 뒤는 주소가 밀려 참고만 합니다.
   - 텍스트 크기와 원본 범위 크기, 그 차(python).
   - 원본 기호표에서 그 범위의 외부 텍스트 함수 이름으로 낸 구간 비교(`m0_m68k_cause.compare_object`). 객체에 없는 이름은 따로 적습니다.
   - 명령 단위 정렬 비교: 객체 otool 목록과 원본 목록(`08_build/artifacts/m0p414/otool-V10/image.txt`, 범위 안)을 `m0_m68k_cause` 의 정규화(절대 주소·분기 목적지 가림)로 맞춘 뒤 `difflib` 로 정렬합니다. 같지 않은 묶음 수·명령 수와 묶음이 속한 함수를 적습니다.
   - 원본에 없는 미정의 기호와 COMMON 기호.
   - 정렬 결과로 객체를 차이가 작은 순서로 줄 세웁니다. 기준은 같지 않은 명령 수, 그다음 크기 차입니다(python).
4. 기록: `09_validation/reconstruction/m5-m68k-survey-20261016.json` 과 계획의 표(§470.x).
   - 표를 보고 다음 절(§471~)에서 객체마다 원인 가설과 변형 계획을 따로 세웁니다. 이번 절에서는 07 을 바꾸지 않습니다.
5. 통과 조건(조사의 성립):
   - 19 객체가 모두 컴파일되어야 합니다.
   - 객체마다 원본 범위가 기호표의 외부 기호와 맞아야 합니다. 범위 시작은 기호이거나, 기호 없는 정적 함수이면 그 사실을 적습니다.
   - 정렬 비교는 객체 텍스트 크기와 원본 범위 크기를 함께 적습니다.

### 470.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §470 은 "그 뒤 07·덮어쓰기·헤더가 여러 번 바뀌었다" 고 적었습니다. 그런데 `m0p441-stage` 와 `m0p469-a1-stage` 의 manifest 를 비교하면 바뀐 25 개는 모두 이 19 객체와 무관한 `.c` 파일이고, 헤더 변경은 0 입니다(python). 그러니 19 객체의 입력은 §441 이후 그대로이고, §441 객체가 지금 상태를 나타냅니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 19 크기 = 끝 − 시작, 경계 정확 | python(`m68k-objects.tsv`) | ✅ |
| miniMon·kdp_udp·mach_net 은 이름 없는 함수에서 시작 | python(시작 주소에 기호표 이름 없음) | ✅ |
| cmu_syscalls·tty 범위 안에 점프 표 데이터(60·28·28 B) | 검토자 판독 | ⏭️ 줄 비교에서 "데이터 섞임" 으로 표시만 함 |
| 205 줄에서 19 줄을 고를 수 있음(m3p429-cc2 3, m3p432-int 16), 모두 `RUN`·`-O2` | 도구가 assert 로 확인 | ✅ 구현에서 assert |
| `base` 는 `L2_…__` 접두를 포함, 출력 접두만 바꿀 것 | `stage_m68k.cmd_cmd` 의 치환 방식 | ✅ |
| §441 이 19 객체의 알맞은 기준(입력 변경 없음) | 두 manifest 비교 python(바뀐 25 파일 목록) | ✅ 위 제 오류 |
| `canon` 만으로는 기호·COMMON·절 속성 비교가 빠짐 | `m3_m68k_diag.py:34-43` | ✅ obj_sig 도 함께 |
| 정규화가 상대 주소·사적 데이터 기호 표기로 가짜 차이를 냄 | 검토자 예시 | ⚖️ 줄 비교는 순위용 추정으로만 씀(판정 근거 아님). 숫자를 모두 가린 표기로 비교 |
| `compare_object` 는 첫 외부 기호 앞 정적 코드를 빼먹음(miniMon 196·kdp_udp 1292·mach_net 518 B) | 설계상 사실(`ext_spans` 는 외부 기호부터) | ✅ 앞부분 구간을 따로 둠 |
| 마지막 원본 구간이 객체 경계를 넘음(mfs_prim 끝 다음 기호 0x404e174, ufs_subr 0x4039e24) | python(끝 주소가 기호가 아님, 다음 기호) | ✅ 객체 범위로 자름 |
| 없는/남는 이름을 따로 보고해야 함 | `compare_object` 는 객체 기호만 돎 | ✅ |
| 시작 주소 자리 L1 은 고정 배치 진단으로만 의미 | 설계(§469 와 같음) | ✅ |
| 레지스터 차이와 구조 차이를 묶음별로 나눌 것 | 설계 | ✅ |
| 순위 계산식과 비교 범위를 밝힐 것 | 설계 | ✅ |

계획 수정(§470 의 3 을 대체):
- 컴파일(1)은 그대로 둡니다. 입력이 같으므로 결과가 §441 객체와 `canon`·obj_sig 모두 같아야 합니다(확인용).
- 구간을 원본과 객체에서 같은 규칙으로 만듭니다.
  - 앞부분 구간: [범위 시작, 첫 외부 기호)
  - 외부 기호마다: [그 기호, 다음 외부 기호 또는 범위 끝). 정적 함수는 앞 외부 함수에 들어갑니다.
  - 원본은 범위 끝에서 자르고, 객체는 텍스트 끝까지입니다.
  - 이름으로 짝을 짓고, 원본에만 있거나 객체에만 있는 이름을 따로 적습니다.
- 구간마다 길이 둘, 재배치 자리를 가린 바이트 같음 여부, 같지 않으면 명령 줄 비교를 적습니다.
  - 줄 비교: otool 줄을 연산자 + 피연산자로 하고 16 진 수를 모두 `N` 으로 가려 레지스터만 남깁니다. `SequenceMatcher(autojunk=False)` 로 정렬합니다.
  - 같지 않은 묶음마다 객체·원본 줄 수를 적고 종류를 나눕니다. **R** 은 줄 수와 연산자 순서가 같고 피연산자(레지스터)만 다른 것, **S** 는 그 밖입니다.
- 순위: 점수 = 같지 않은 묶음의 (객체 줄 + 원본 줄) 합, 같으면 |텍스트 크기 차| 순입니다(python). 비교한 바이트 범위(덮음)도 함께 적습니다. 점수는 다음 절의 대상을 고르는 추정치일 뿐이고 판정 근거가 아닙니다.
- L1 두 가지(자동 배치, 범위 시작 자리)를 적습니다.
- 입력 증거로 스테이징 manifest SHA, 명령 줄, 객체·목록 SHA, 정규화 메모를 적습니다.

### 470.2 조사 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-survey-20261016.json`

- run `m5p470-s1`(명령 19 개 모두 종료 0; 바탕 `m0p469-a1-stage`). 실기 krsha256 과 호스트 SHA-256 이 19 개 모두 같습니다.
- 19 객체 모두 §441 객체와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같습니다(입력이 그대로라는 §470.1 판단과 맞음).
- 순위표(점수 = 같지 않은 묶음의 객체 줄 + 원본 줄; 크기 차 = 객체 텍스트 − 원본 범위; R/S = 레지스터만 다른 묶음 / 그 밖의 묶음 수):

| 순위 | 객체 | 점수 | 크기 차(B) | R | S | 다른 구간 |
|---:|---|---:|---:|---:|---:|---|
| 1 | kalloc | 4 | 0 | 0 | 1 | `_realloc` |
| 2 | kern_fork | 5 | 0 | 1 | 1 | `_switch_unix_context` |
| 3 | nfs_client | 6 | 0 | 1 | 0 | `_nfs_attrcache_va` |
| 4 | kern_exit | 11 | -30 | 0 | 2 | `_do_exit` |
| 5 | kern_proc | 17 | 26 | 0 | 2 | `_alloc_posix_proc` |
| 6 | ipc_mig | 18 | 6 | 8 | 0 | `_msg_rpc` |
| 7 | mfs_prim | 20 | -48 | 0 | 4 | `_mfs_init` |
| 8 | cmu_syscalls | 31 | -2 | 0 | 2 | `_table` |
| 9 | ufs_subr | 65 | 54 | 10 | 5 | `_bufstats` |
| 10 | igmp | 71 | -28 | 2 | 7 | `_igmp_input`, `_igmp_joingroup`, `_igmp_leavegroup`, `_igmp_fasttimo` |
| 11 | mach_clock | 71 | 94 | 4 | 4 | `_clock_interrupt`, `_mach_clock_bootstrap` |
| 12 | mach_net | 74 | -66 | 2 | 7 | `_netipc_listen` |
| 13 | time_stamp | 80 | 24 | 1 | 7 | `_kern_timestamp` |
| 14 | tty | 101 | 16 | 25 | 9 | `_ttysetspec`, `_ttyinput`, `_ttyblkin`, `_ttcooked`, `_ttread`, `_ttyretype` |
| 15 | netif | 105 | 48 | 7 | 8 | `_if_ioctl`, `_if_collisions_set`, `_iflist_next`, `_if_detach`, `_if_attach`, `_if_output_mbuf` |
| 16 | miniMon | 154 | -74 | 1 | 7 | `<prefix>`, `_miniMonInit`, `_miniMonLoop`, `_safe_prf` |
| 17 | kdp_udp | 382 | -72 | 7 | 11 | `<prefix>`, `_kdp_raise_exception` |
| 18 | callout | 568 | 134 | 9 | 24 | `_calloutInitialize`, `_calloutDispatchDelayed`, `_calloutRemove`, `_calloutRemoveAll`, `_calloutEntryDispatchDelayed`, `_calloutEntryDispatchWithArgumentDelayed`, `_calloutEntryRemove` |
| 19 | swapfs | 1505 | -146 | 24 | 30 | `_logswap`, `_compress_data`, `_uncompress_data` |

- 앞쪽 다섯의 차이 내용(otool 목록 나란히; 원본 주소의 기호는 symbols.tsv):
  - `kalloc` `_realloc`: 비교 피연산자 순서만 다릅니다. 우리는 `cmpl a4,d0; bls`, 원본은 `cmpl d0,a4; bcc` 입니다(크기 같음).
  - `kern_fork` `_switch_unix_context`:
    - 원본은 공통 기호 `_active_u`(8 B)의 +4 와 +0 에 절대 주소로 바로 씁니다(`movel a0@(0x80:w),0x40b57d4:l` … `0x40b57d0:l`).
    - 우리는 `lea _active_u+4,a1` 뒤 `a1@`·`a1@(-4)` 로 씁니다.
  - `nfs_client` `_nfs_attrcache_va`: 레지스터 하나만 다릅니다(`moveq #124,d1` 대 `d0`).
  - `kern_exit` `_do_exit`(원본 30 B 김):
    - 원본에만 `moveb _machine_type,d0; beq …; cmpb #2,d0; bne …; … movew a1@(0x30:w),a1; movel a1,sp@-; bsr _od_unlock_check` 묶음이 있습니다. m68k(NeXT 광디스크) 전용 호출로 보입니다.
  - `kern_proc` `_alloc_posix_proc`(우리 26 B 김):
    - 원본은 `kalloc(30)` 뒤 `bzero(p, 30)` 을 부르고 `clrl a2@` 를 한 뒤 p 를 돌려줍니다.
    - 우리는 상수 틀(__const)을 통째로 복사합니다.
- 줄 비교는 순위용 추정입니다. `cmu_syscalls` 의 차이는 점프 표(데이터) 자리에 걸쳐 있어 해석에 주의해야 합니다(§470.1).
- 다음: 위 다섯을 한 절씩(§471~) 계획합니다. 원본 바이트·참고 코드(NeXTMach)에서 원인을 확인하고, 변형 시험, codex 교차검토, 사용자 결정 순서로 갑니다.

## 471. M5-28 세부 계획 — m68k `kern_exit`(`od_unlock_check`)·`kern_proc`(`alloc_posix_proc`)·`kalloc`(`realloc` 비교 꼴)(코딩 전, 2026-10-16)

§470.2 순위의 앞쪽 가운데, 원인을 원본 바이트와 참고 코드로 설명할 수 있는 셋을 다룹니다. `kern_fork`·`nfs_client` 는 §465 에서 시험한 꼴로 풀리지 않았고, 새 가설이 아직 없으므로 뒤로 미룹니다.

확인한 사실(§470 목록·기호표·참고 코드를 직접 읽음):
- **`kern_exit` `_do_exit`**(원본이 30 B 더 김):
  - 원본은 `bsr _crfree` 뒤에 다음을 둡니다. `moveb _machine_type,d0; beq L; cmpb #2,d0; bne S; L: movel d4,a1; movew a1@(0x30:w),a1; movel a1,sp@-; bsr _od_unlock_check`. 곧 `machine_type` 이 0 또는 2 이면 `od_unlock_check(p->p_pid)` 입니다.
  - 기호는 `_machine_type` 0x40b61ac(공통), `_od_unlock_check` 0x407a3ac 입니다.
  - NeXTMach `bsd/kern_exit.c:193-197` 은 같은 자리(`crfree(utask->uu_cred);` 바로 뒤)에 `#if NeXT` / `#if NOD > 0` / `od_unlock_check(p->p_pid);` 를 둡니다. 원본 m68k 는 여기에 기계 종류 조건이 더해진 꼴입니다.
  - 07 `kern_exit.c` 는 198 행 `crfree` 뒤에 이 블록이 없습니다(x86 원본에 맞춤). 07 의 `od.h` 는 `NOD 0` 이고, 07 에서 `NOD` 를 쓰는 곳은 없습니다(`#import <od.h>` 한 줄뿐).
  - 기계 종류 상수는 NeXTMach `next/scr.h:34-37`(`NeXT_CUBE 0`·`NeXT_X15 2`)에 있습니다. m68k 덮어쓰기 `kern_uname.c` 가 같은 줄을 D076 으로 복사해 썼습니다. `machine_type` 은 SDK `bsd/m68k/cpu.h:51` 의 `extern u_char` 입니다.
- **`kern_proc` `_alloc_posix_proc`**(우리가 26 B 더 김):
  - 원본은 `kalloc(0x1e)` 뒤에 `bzero(px, 0x1e)`(`_bzero` 0x4092e12), `clrl a2@` 를 하고 px 를 돌려줍니다.
  - 07 은 411 행 `static const struct posix_proc posix_proc_zero = { 0 };` 와 419 행 `*px = posix_proc_zero;`(x86 원본에 맞춘 꼴)입니다.
  - `struct posix_proc` 의 첫 필드는 `pid_t p_pid` 입니다(SDK `bsd/sys/proc.h:258`). 따라서 `clrl a2@` 는 `px->p_pid = 0` 에 해당합니다.
  - 우리 m68k 객체에는 `__TEXT,__const`(상수 틀)가 있습니다(L1 사유 `__TEXT,__const: unverified`).
- **`kalloc` `_realloc`**:
  - 비교 피연산자 순서만 다릅니다. 원본은 `cmpl d0,a4; bcc`(`size - *sizep`, 같거나 크면 `*sizep` 쪽)이고, 우리는 `cmpl a4,d0; bls` 입니다.
  - 07 은 `if (size < *sizep) bcopy(addr, new+2, size); else bcopy(addr, new+2, *sizep);`(07 `kern/kalloc.c` 313–316 행)입니다.
  - §465 의 T(삼항식)는 크기가 754 B 로 줄었고, R(`size >= *sizep`)은 다른 불일치였습니다.

방법(`m5_m68k_srcvar.py`, 객체마다 명세 하나, 바탕 `m0p469-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `O470__…`):
- `kern_exit`(run `m5p471-e1`):
  - `X1`: 머리의 `#import <od.h>` 묶음 뒤에 `extern u_char machine_type;`, `NeXT_CUBE`·`NeXT_X15` 정의, `extern void od_unlock_check();` 를 둡니다. `crfree` 뒤에 `if (machine_type == NeXT_CUBE || machine_type == NeXT_X15) od_unlock_check(p->p_pid);` 를 넣습니다.
  - `X2`: 같은 선언에 `switch (machine_type) { case NeXT_CUBE: case NeXT_X15: od_unlock_check(p->p_pid); }` 꼴입니다.
- `kern_proc`(run `m5p471-p1`):
  - `P1`: 복사를 `bzero((caddr_t)px, sizeof (struct posix_proc)); px->p_pid = 0;` 로 바꾸고 상수 틀 정의를 뺍니다.
  - `P2`: P1 이되 상수 틀 정의를 남깁니다. 쓰이지 않는 static const 가 -O2 에서 나오는지 보는 진단입니다.
- `kalloc`(run `m5p471-k1`):
  - `A1`: `if (*sizep > size)`(가지 그대로)
  - `A2`: `if (*sizep <= size) bcopy(…*sizep) else bcopy(…size)`
  - `A3`: `if (size > *sizep) bcopy(…*sizep) else bcopy(…size)`
- 판정에는 `m5_m68k_nst.py` 의 함수별 K 대비 비교를 쓰지 않습니다(그 도구는 ns_timer 전용). 대신 다음을 봅니다.
  - L1(`--place-from-image`) 판정·사유: `kern_exit` 는 OBJECT_MATCH, `kern_proc`·`kalloc` 는 사유가 `__DATA,__bss: unverified` 하나여야 합니다.
  - 원본에 없는 미정의 기호 0, COMMON·외부 텍스트 정의가 K 와 같음. `kern_proc` 의 지역 기호 `posix_proc_zero` 가 빠지는 것은 예상입니다.
  - 대조 K 가 `control_ref` 를 재현하지 못하면 그 객체는 멈춥니다.
- x86 확인: `kalloc` 의 A 꼴은 본 파일에 둘 수 있는지 `m5_x86_srcvar.py`(바탕 s6l5; 이 세 파일은 s6l5 뒤 바뀌지 않음)로 봅니다. `kern_exit`·`kern_proc` 는 m68k 전용 코드라 덮어쓰기에 둡니다.
- 고르기: 객체마다 기준을 통과한 꼴이 하나면 그것을 쓰고, 바이트로 구별되지 않는 꼴이 여럿이거나 자리(본 파일/덮어쓰기)를 정해야 하면 사용자에게 묻습니다. 없으면 진단을 기록하고 멈춥니다.
- 결정 뒤: 덮어쓰기(`plan 471 (m68k)` 표시, `stage_m68k.py` MARKERS·EXCEPTS[471]·`--plan`), D076 선례대로 NeXTMach `scr.h` 줄과 고지, PROVENANCE·MODIFICATIONS·DECISIONS 를 고칩니다. final 은 `m5_m68k_pc.py cmd2/final` 또는 같은 성격의 검사로 L1 사유와 변형 동일성을 assert 합니다(bss 가 남는 객체는 `m5_m68k_zerofill.py objs`).

### 471.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §471 의 X1 은 `extern u_char machine_type;` 과 상수 정의를 `#import <od.h>`(61 행) 뒤에 두려 했습니다. 그 자리에서는 `u_char` 가 아직 정의되지 않습니다(시스템 헤더는 77–98 행). 또 `machine_type` 은 `sys/user.h:345` 의 `#import <machine/cpu.h>` 를 거쳐 m68k 에서 이미 선언되므로 다시 선언할 필요가 없습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 `_do_exit`: `crfree`(0x4005666) 뒤 0x400566c 스택 정리, 0x400566e 부터 기계 종류 검사, 0x4005684 `od_unlock_check` | 원본 목록 0x4005650–0x40056a0 직접 읽음 | ✅ 주소 문구 고침 |
| d4 = p, `p_pid` 는 +0x30 의 short(부호 확장해 넣음) | 원본 `movew a1@(0x30:w),a1`; 검토자 STABS 판독 | ✅ |
| 우리 객체의 "한 줄 더" 는 뒤로 밀린 `addqw #4,sp`; 원본 32 B − 2 B = 30 B | 객체 목록 0x1b6–0x1f0 직접 읽음; python 32−2 | ✅ |
| `kern_exit` 의 다른 구간은 재배치 밖에서 같음 | §470 기록(다른 구간 `_do_exit` 하나) | ✅ |
| 상수·선언 자리가 틀림(`u_char` 전) / `machine_type` 은 이미 선언됨 | 07 `kern_exit.c` import 줄(61, 77–98), 스테이징 `bsd/sys/user.h:345` | ✅ 위 제 오류 |
| `od_unlock_check` 의 `extern void` 는 근거 없음(NeXTMach 정의는 암묵 int) | 설계 | ✅ 선언 없이 부름(NeXTMach 와 같음) |
| `_alloc_posix_proc` 시작은 0x4007178, 0x400717c 는 a2 저장 | 원본 목록 | ✅ 문구 고침 |
| `struct posix_proc` 30 B, `p_pid` 가 0 자리 32 비트 | 검토자 STABS·python | ⏭️ 시험 객체가 판정 |
| 상수 틀은 유일한 `__const` | 검토자 판독 | ⏭️ P1 객체가 판정 |
| kalloc A1·A2 는 K·R 의 다른 표기라 같은 결과일 수 있고, A3 이 가장 새로운 시험 | 설계 | ✅ 그대로 셋 시험 |
| `cc_line` 은 세 파일 모두 한 줄(cc.cmd); 대조는 `O470__L2_154__kern_exit.o`·`O470__L2_334__kern_proc.o`·`O470__L2_324__kalloc.o` | 도구가 assert 로 확인(실행 때) | ✅ |
| 세 파일 모두 m68k 덮어쓰기 없음, s6l5 와 같음 | `ls v183.34/m68k/src/bsd/kern`·`src/kern`(§471 준비 때) | ✅ |
| `m5_m68k_pc.py` 의 cmd2/final 은 이 파일들에 맞지 않음(FILES 없음, final 은 PC 모양 검사) | §469.1 판정과 같음 | ✅ 새 final 검사 도구 |
| `generated/meta_features.h` 도 `od.h` 를 가져옴(그래도 `NOD` 조건은 없음) | 스테이징 경로 확인 | ⚖️ 결론(NOD 조건 없음) 그대로 |

계획 수정:
- `kern_exit` X1·X2: NeXTMach `scr.h:34,36` 의 `NeXT_CUBE`·`NeXT_X15` 정의를 마지막 `#import`(98 행) 뒤에 둡니다. `machine_type`·`od_unlock_check` 선언은 넣지 않습니다.
- final 검사: 새 도구 `10_tools/reconstruction/m5_m68k_final.py` 를 만듭니다.
  - `cmd`: cc.cmd 의 그 파일 한 줄에서 출력만 `F<plan>__<name>.o` 로 바꿉니다.
  - `check`: 객체마다 다음을 assert 합니다.
    - 고른 변형 객체와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같음
    - L1 사유가 미리 정한 목록과 같음(`kern_exit` 는 빈 목록 = OBJECT_MATCH, 둘은 `['__DATA,__bss: unverified']`)
    - 원본에 없는 미정의 0
    - bss 가 남는 객체는 `m5_m68k_zerofill.py objs` 통과와 이미 정한 후보들과 겹침 0

### 471.2 변형 시험 결과(2026-10-16)

- m68k(run `m5p471-e1`·`-p1`·`-k1`, 명령 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-{kern-exit,kern-proc,kalloc}-variants-p471-20261016.json`). 세 대조 K 모두 §470 객체를 재현했습니다.
  - **`kern_exit` X1 은 OBJECT_MATCH** 입니다(원본에 없는 미정의 0, COMMON·외부 정의 수 K 와 같음). X2(switch 꼴)는 맞지 않습니다. 맞는 꼴이 하나이므로 X1 을 씁니다.
  - **`kern_proc` P1 은 L1 사유가 `__DATA,__bss: unverified` 하나**이고, `__TEXT,__const` 도 없어졌습니다. 상수 틀을 남긴 P2 는 `__const` 가 남아 맞지 않습니다(쓰이지 않는 static const 도 -O2 에서 나옴). 맞는 꼴이 하나이므로 P1 을 씁니다.
  - **`kalloc` A1(`if (*sizep > size)`)은 L1 사유가 bss 하나** 입니다. A2·A3·K 는 `__TEXT,__text: fail` 입니다.
- x86(`m5_x86_srcvar.py`, 바탕 s6l5, run `m5p471-xp1`·`-xk1`; 기록 `m5-x86-{kern-proc,kalloc}-variants-p471-20261016.json`):
  - `kern_proc` P1 은 x86 원본과 다릅니다. 그래서 m68k 덮어쓰기로 둡니다(x86 원본은 상수 틀 복사 꼴).
  - `kalloc` A1 은 x86 원본과 같습니다. 자리(07 본 파일 / m68k 덮어쓰기)를 사용자에게 묻습니다.
  - `kern_exit` X1 은 m68k 전용 호출이므로 덮어쓰기에 둡니다.
- 사용자 결정 **D089**: `kalloc` A1 의 자리는 "07 본 파일 (Recommended)" 입니다. `kern_exit` X1·`kern_proc` P1 은 맞는 꼴이 하나라 그대로 쓰고, m68k 덮어쓰기에 둡니다.

### 471.3 D089 구현 계획(07 본 파일 `kalloc.c` + 덮어쓰기 둘 + x86 전체 재빌드 s6l8 + final 검사 도구; 코딩 전, 2026-10-16)

§469.4 절차를 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: 고른 변형 객체 `08_build/runs/m5p471-e1/out/P471__X1.o`·`m5p471-p1/out/P471__P1.o`·`m5p471-k1/out/P471__A1.o` 를 final 의 REF 로 씁니다. 다시 만들지 않습니다.
1. 07 편집:
   - 본 파일 `kern/kalloc.c` 313 행 `if (size < *sizep)` → `if (*sizep > size)` 로 바꾸고 줄 끝에 `/* plan 471 (D089): … */` 를 붙입니다. 가지는 그대로입니다.
   - 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_exit.c`(새 파일)는 07 본 파일에 줄을 끼우는 꼴입니다.
     - 98 행 뒤에 `plan 471 (m68k) begin … end` 묶음을 둡니다. 내용은 NeXTMach `next/scr.h:1` 고지 줄, `scr.h:34`·`:36` 의 `NeXT_CUBE`·`NeXT_X15` 정의(D076 선례)입니다.
     - 198 행 `crfree` 뒤에 `#if m68k` 묶음으로 `if (machine_type == NeXT_CUBE || machine_type == NeXT_X15)` / `od_unlock_check(p->p_pid);` 를 둡니다. 호출은 NeXTMach `bsd/kern_exit.c:195` 와 같은 글입니다.
   - 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_proc.c`(새 파일):
     - 411 행 상수 틀 정의를 `#ifndef m68k` … `#endif` 로 감쌉니다.
     - 419 행 복사를 `#if m68k` `bzero((caddr_t)px, sizeof (struct posix_proc));` / `px->p_pid = 0;` `#else` 07 줄 `#endif` 로 바꿉니다(작성, D024).
   - 확인: `stage_m68k.check_derived` 로 두 덮어쓰기를 검사하고, 본 파일에 표시 문자열이 없어야 합니다.
2. x86 전체 재빌드 s6l8(일곱 묶음, `L2_FORMS`/`L2_EXPECT` s6p398), 통과 조건은 §469.4 와 같습니다.
3. prefixdiff s6l7↔s6l8(plan 471):
   - 스테이징 차이는 `src/kern/kalloc.c` 하나여야 합니다.
   - `sha_differ_not_rid_only` 는 `x86-kalloc` 하나이고, `differing_non_stabs_equal` 이 true 여야 합니다.
4. 링크 `s6p471-ln1` → `l2_compare` 의 `identical` 과 `cmp` 가 원본과 같아야 합니다.
5. `stage_m68k.py`:
   - `X86[471] = 's6l8'`, `EXCEPTS[471] = EXCEPTS[469]` 에 `x86-kalloc`·`x86-kern_exit`·`x86-kern_proc` 사유를 더합니다.
   - `MARKERS['plan 471 (m68k)']` 를 두 파일의 줄 수와 함께 등록하고, `--plan` 문서를 고칩니다.
   - `--plan 471 stage m0p471-a1-stage` → x86gate(s6l8) → `m0p469-a1-stage` 와의 파일 차이는 셋(`src/kern/kalloc.c`·`src/bsd/kern/kern_exit.c`·`src/bsd/kern/kern_proc.c`)이어야 합니다.
6. final(새 도구 `m5_m68k_final.py`):
   - `cmd PLAN NAME=REL …` 는 cc.cmd 의 그 파일 한 줄에서 출력만 `F471__<name>.o` 로 바꿉니다.
   - `check RUN PLAN RECORD NAME:REF:EXPECTED_REASONS …` 는 객체마다 다음을 assert 합니다.
     - REF 와 `canon`·Mach-O 머리·절 머리·비 STABS 기호가 같음
     - L1 사유가 정확히 기대값과 같음(`kern_exit` 빈 목록, `kern_proc`·`kalloc` `['__DATA,__bss: unverified']`)
     - 원본에 없는 미정의 0
     - bss 가 남는 객체는 `m5_m68k_zerofill.py objs` 통과
     - bss 후보는 §464 후보·§467 nfs·§469 ns_timer 후보와 겹침 0(python)
   - run `m5p471-a1`.
7. 기록:
   - PROVENANCE: kalloc.c 210 행을 그 자리에서 갱신하고, 두 덮어쓰기는 새 행으로 둡니다(중복 0).
   - MODIFICATIONS 세 행, DECISIONS D089 를 적습니다.
   - diff `x86-kalloc-plan471.diff`·`m68k-kern_exit.diff`·`m68k-kern_proc.diff` 를 만들고, evidence `x86-kalloc.md` 에 plan 471 절을 덧붙입니다.
   - 검증 기록은 s6l8 일곱, prefixdiff, link, final, zerofill 입니다.
   - 집계: OBJECT_MATCH +1(`kern_exit`), "코드 검증 + bss 추정" +2(`kern_proc`·`kalloc`), 코드 차이가 남은 객체는 19 → 16 입니다.

### 471.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §471.3 의 3 은 `sha_differ_not_rid_only` 가 `['x86-kalloc']` 이어야 한다고 적었습니다. 그런데 A1 은 줄 수를 바꾸지 않으므로, 같은 파일 이름으로 다시 빌드하면 x86 kalloc 객체가 RID 경로 말고는 아예 같을 수 있습니다. x86 시험 객체 K·A1 은 기호 602 개 가운데 원본 파일 이름 기호 하나만 다르고 `canon` 이 같습니다(python).

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 끼울 자리(kern_exit 98·198 행, kern_proc 411·419 행)가 맞고, 감싸는 꼴은 본 파일 줄을 표시 밖에 두면 파생 검사 통과 | §471 준비 때 줄 읽음; 구현 뒤 실제 `stage` 가 판정 | ✅ |
| X1 의 정의는 `#if m68k` 안(98 행 뒤) — 계획 문구에 명시할 것 | 명세 `spec-kern_exit.json` 의 치환 글 | ✅ 구현에서 `#if m68k` 묶음 |
| `scr.h:1` 고지 줄은 주석뿐 → 비 STABS 영향 없음 | 그 줄은 `/* … */` 한 줄 | ✅ final 은 canon·머리·절·비 STABS 기호만 비교 |
| A1 은 조건 줄만 다름; 줄 끝 주석은 줄 번호 불변 | 명세 치환 글 비교 | ✅ |
| prefixdiff 의 `sha_differ_not_rid_only` 는 `[]` 일 수도 있음 | x86 K·A1 기호 비교 python(차이는 파일 이름 기호 하나) | ✅ 위 제 오류. 기준: `[]` 또는 `['x86-kalloc']`, `differing_non_stabs_equal` true |
| `EXCEPTS[471]` 은 `--plan` 허용에 필요; `stage`·`x86gate` 모두에 `--plan 471` | `main()` 의 `in EXCEPTS` | ✅ |
| `objs` 는 §464 기록만 봄 → 두 새 객체를 한 번에 넣고, §467·§469 후보와는 따로 겹침 검사 | `m5_m68k_zerofill.py:148`; 두 기록의 `summary.candidates`(python) | ✅ |
| 미리 돌린 zerofill: kern_proc [0x40b317c, 0x40b3180) 4 B, kalloc [0x40b3612, 0x40b3712) 256 B, 겹침 없음 | 검토자 계산 | ⏭️ final 이 판정 |
| 기대 사유를 콜론 섞인 인자로 넘기지 말 것 | 설계 | ✅ final 은 JSON 명세 파일을 받음 |

### 471.5 D089 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p471-final-20261016.json`

- 07 편집:
  - 본 파일 `kern/kalloc.c` 313 행을 `if (*sizep > size)` 로 바꾸고 주석을 붙였습니다. 줄 수는 같습니다.
  - 새 덮어쓰기 `v183.34/m68k/src/bsd/kern/kern_exit.c`(표시 줄 9)와 `kern_proc.c`(표시 줄 7)를 만들었습니다. 파생 검사를 통과했고, 본 파일에 표시 문자열은 없습니다.
- x86 전체 재빌드 s6l8:
  - 명령 804 개가 모두 종료 0 입니다(python). check 기록 일곱, 402 행 연속, problem 0, 기준선과 같음 377 입니다.
  - prefixdiff s6l7↔s6l8: 스테이징 차이는 `src/kern/kalloc.c` 하나이고, 키·명령 차이는 없습니다. RID 경로 말고 다른 객체는 없습니다(`[]`, §471.4 의 예상대로).
  - 링크 `s6p471-ln1`: `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 471 stage m0p471-a1-stage` 는 파생 검사를 통과했고, x86gate(s6l8 일곱)는 모두 같으며 v183 경로는 0 입니다. `m0p469-a1-stage` 와의 차이는 세 파일(`kalloc.c`·`kern_exit.c`·`kern_proc.c`)입니다.
  - final run `m5p471-a1`(명령 3 개, 종료 0)에서 `m5_m68k_final.py check` 의 assert 를 모두 통과했습니다.
    - `x86-kern_exit` 은 **OBJECT_MATCH** 입니다.
    - `x86-kern_proc`·`x86-kalloc` 은 L1 사유가 `__DATA,__bss: unverified` 하나입니다.
    - 세 객체 모두 고른 변형과 `canon`·머리·절 머리·비 STABS 기호가 같고, 원본에 없는 미정의는 0 입니다.
  - zerofill(`m5-m68k-p471-zerofill-20261016.json`):
    - kern_proc 은 reference-inferred [0x40b317c, 0x40b3180) 4 B 입니다.
    - kalloc 은 reference-inferred-single [0x40b3612, 0x40b3712) 256 B 입니다.
    - §464 후보와 겹침 0, §467·§469 후보와 겹침 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 170 입니다(+ 명시 배치 `ufs_alloc` 1).
  - "코드 검증 + bss 추정" 은 21 입니다.
  - 코드 차이가 남은 객체는 16 개입니다(netif, miniMon, igmp, time_stamp, mfs_prim, nfs_client, kern_fork, cmu_syscalls, ufs_subr, ipc_mig, mach_clock, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 1097 행(kalloc 210 행 갱신, 덮어쓰기 두 행 새로, 중복 0), MODIFICATIONS 629 행, DECISIONS D089 를 적었습니다.
  - diff 셋을 만들고 `x86-kalloc.md` 에 plan 471 절을 덧붙였습니다.
  - 도구: 새로 만듦 `m5_m68k_survey.py`·`m5_m68k_final.py`, 고침 `stage_m68k.py`(plan 471). 고치기 전 사본은 `08_build/artifacts/m5p471/*.before` 입니다.

## 472. M5-29 세부 계획 — m68k `mfs_prim`(`mfs_map_size` 의 double 계산)·`cmu_syscalls`(`table` 의 스택 정리 자리)(코딩 전, 2026-10-16)

§470.2 순위에서 원인 가설이 분명한 두 객체를 다룹니다. `kern_fork`·`nfs_client`·`ipc_mig` 는 레지스터·주소 배정 차이라 가설이 없어 뒤로 미룹니다.

확인한 사실(§470 목록 `08_build/artifacts/m5p470/otool/`, 원본 목록, 기호표, 참고 코드를 직접 읽음):
- **`mfs_prim` `_mfs_init`**(우리가 48 B 짧음; 다른 구간은 이 하나):
  - 원본(0x404cf06–)은 `kmem_suballoc` 뒤 `_machine_info+16`(`memory_size`, `vm_size_t`)을 읽습니다.
  - 그다음 `fmovel d0,fp0; tstl d0; bge; faddd #4.29496e+09,fp0`(부호 없는 정수 → double), `fmoveml` 로 반올림을 0 방향으로 바꾼 `fmovel fp0,d0`(double → int), `_mfs_map_size` 저장, `cmpl #0x1000000` 상한 순서입니다. 곱셈·나눗셈은 없습니다.
  - 부동소수 코드가 d2 를 써서 원본은 d2 를 저장·복원합니다(앞뒤 한 줄씩 원본에만 있음).
  - 07 `kern/mfs_prim.c:165-167` 은 `(int) ((long long) MFS_MAP_SIZE_PER_UNIT / (long long) MFS_MEMORY_UNIT * (long long) machine_info.memory_size)`(plan 139, Darwin 0.1 `kern/mapfs.c:235-237` 와 같은 글, x86 원본으로 확인됨)입니다.
  - 두 상수는 모두 `1024 * 1024`(07 136–137 행)라 비율이 1 입니다.
  - 가설: 원본 m68k 는 같은 식을 double 로 쓴 판입니다. 비율 1.0 이 접혀 변환만 남은 꼴입니다.
- **`cmu_syscalls` `_table`**(우리가 2 B 짧음):
  - 원본은 `bsr _thread_reference`(0x40024ce) 바로 뒤에 `addqw #0x4,sp` 를 하고 `round_page`·`kmem_alloc_wait` 로 넘어갑니다. 우리는 이 스택 정리를 미룹니다.
  - 그 밖의 차이는 점프 표 값(상대 변위)뿐이고, 이 2 B 이동의 결과입니다.
  - 07 `bsd/kern/cmu_syscalls.c:451-459` 는 `task_lock(task); if (task->thread_count <= 0) { task_unlock(task); u.u_error = ESRCH; return; } th = …; thread_reference(th); task_unlock(task);`(plan 203, x86 원본에서 작성)입니다. `task_lock`·`task_unlock` 은 m68k·NeXTMach 모두 빈 매크로입니다(`kern/lock.h:102-103`, NeXTMach `kern/lock.h:153-154`).
  - 가설: 원본은 `thread_reference` 뒤에 분기(조건문 구조)가 있어 미뤄 둔 스택 정리가 그 자리에서 나왔습니다. 예를 들면 `if (task->thread_count > 0) { th = …; thread_reference(th); } else { …ESRCH…; return; }` 의 then 끝에서 else 를 건너뛰는 분기입니다.

방법(`m5_m68k_srcvar.py`, 객체마다 명세·스테이징·run 을 따로, 바탕 `08_build/runs/tools/m0p471-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체):
- `mfs_prim`(run `m5p472-m1`):
  - `F1`: `(int) ((double) MFS_MAP_SIZE_PER_UNIT / (double) MFS_MEMORY_UNIT * (double) machine_info.memory_size)`
  - `F2`: `(int) (MFS_MAP_SIZE_PER_UNIT / MFS_MEMORY_UNIT * (double) machine_info.memory_size)`
  - `F3`: `(vm_size_t)` 로 바꾼 F1(부호 없는 변환이 되어 달라야 하는 대조)
- `cmu_syscalls`(run `m5p472-c1`):
  - `C1`: `if (task->thread_count > 0) { th = …; thread_reference(th); } else { task_unlock(task); u.u_error = ESRCH; return; } task_unlock(task);`
  - `C2`: `if (task->thread_count <= 0) { task_unlock(task); u.u_error = ESRCH; return; } else { th = …; thread_reference(th); } task_unlock(task);`
- 판정(L1 `--place-from-image`):
  - `mfs_prim` 은 §470 에서 사유가 `__TEXT,__text: unverified` 하나였습니다. 맞으면 OBJECT_MATCH 이거나 bss 만 남아야 합니다.
  - `cmu_syscalls` 도 같은 기준입니다.
  - 원본에 없는 미정의 0, COMMON·외부 정의 수가 K 와 같아야 합니다.
  - 대조 K 가 `control_ref` 를 재현하지 못하면 멈춥니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; 두 파일은 s6l5 뒤 바뀌지 않았는지 실행 전에 확인): 맞은 꼴이 x86 원본과도 같으면 자리를 사용자에게 묻고, 다르면 m68k 덮어쓰기로 둡니다.
- 고르기·결정·구현·final 은 §471 과 같습니다(`m5_m68k_final.py`, x86 본 파일 변경이 있으면 x86 재빌드·링크 cmp). 바이트로 구별되지 않는 꼴이 여럿이면 사용자에게 묻습니다.

### 472.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §472 는 `cmu_syscalls` 점프 표 값을 "상대 변위" 라고 적었습니다. 실제로는 절대 주소(지역 재배치)입니다. 원본 항목 − 객체 시작(0x4002284)과 객체 항목을 비교한 제 계산도 절대 주소로 다룬 것이고, 결과는 변경 지점 앞 0, 뒤 +2 였습니다. 또 원본에서는 뒤쪽 누적 정리가 `addaw #0x14,sp`(0x400252a)로 줄어 있습니다. 우리는 `addaw #0x18,sp`(0x2a4)이고 4 + 0x14 = 0x18 입니다(python). 곧 정리가 둘로 나뉜 꼴입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_mfs_init`: unsigned → double(상수 41f0000000000000) → 0 방향 반올림 int, 곱셈·나눗셈 없음; 뒤의 `mulul` 은 `/ 20` | 원본 목록 0x404cf06–0x404cfd2 직접 읽음 | ✅ |
| GCC 2.7.2 는 `* 1.0` 을 fast-math 없이 접음(`simplify_binary_operation`) | 검토자 인용(외부 소스, 직접 미확인) | ⏭️ 시험이 판정 |
| `(int)(double)memory_size` 직접 변환도 후보로 둘 것 | 설계 | ✅ F4 추가 |
| d2 저장·복원은 FPCR 값을 만드는 데 쓰임 | 원본 목록 `moveq #16,d2; orl d1,d2; andw #0xffdf,d2` | ✅ |
| mfs_prim 다른 구간은 같음(32 구간 중 31) | §470 기록(다른 구간 `_mfs_init` 하나) | ✅ |
| 점프 표는 절대 주소, 뒤쪽 대상은 정확히 +2 | 제 python 계산(15 항목: 0 셋, +2 열둘) | ✅ 위 제 오류(문구) |
| 뒤쪽 정리 `addaw #0x14` 대 `#0x18` | 두 목록 해당 줄 읽음, python 4+0x14 == 0x18 | ✅ |
| ESRCH 공유 경로(원본 0x400235a, 객체 0xd6)는 둘 다 있음 | §471 준비 때 목록(`ble 0x400235a`/`ble 0xd6`) | ✅ |
| C1·C2 모두 미룬 정리를 내보내는 경계를 만듦(C2 는 `expand_end_cond`) | 검토자 인용(직접 미확인) | ⏭️ 시험이 판정 |
| 대조 `O470__L2_078__mfs_prim.o`·`O470__L2_146__cmu_syscalls.o` | `ls 08_build/runs/m5p470-s1/out` | ✅ |
| `m5_m68k_srcvar.py` 는 `control_equals_ref` 를 기록만 함 | 167–168 행(§469.1 에서 읽음) | ✅ 결과에서 따로 확인 |
| `task_lock`/`task_unlock` 정의는 `kern/task.h:133-134` | 스테이징 grep 출력(§472 준비 때) | ✅ 문구 보탬 |

계획 수정:
- `mfs_prim` 에 `F4` = `(int) (double) machine_info.memory_size` 를 더합니다.
- `cmu_syscalls` 의 판정에 "뒤쪽 정리가 `addaw #0x14`" 를 포함하고, L1 결과로 봅니다.
- 두 run 모두 `control_equals_ref` 를 확인합니다.

### 472.2 변형 시험 결과(2026-10-16)

- m68k(run `m5p472-m1`·`-c1`, 명령 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-{mfs-prim,cmu-syscalls}-variants-p472-20261016.json`). 두 대조 K 모두 §470 객체를 재현했습니다(`control_equals_ref` true).
  - **`mfs_prim`: F1·F2·F4 가 OBJECT_MATCH** 이고, 세 객체는 비 STABS 로 같습니다(원본에 없는 미정의 0, COMMON·외부 정의 K 와 같음). F3(`vm_size_t` 변환)은 예상대로 다릅니다. "double 계산" 가설이 맞았습니다.
  - **`cmu_syscalls`: C1·C2 가 OBJECT_MATCH** 이고, 두 객체는 같습니다(같은 조건). "분기 경계" 가설이 맞았습니다.
- x86(`m5_x86_srcvar.py`, 바탕 s6l5; run `m5p472-xm1`·`-xc1`; 기록 `m5-x86-{mfs-prim,cmu-syscalls}-variants-p472-20261016.json`):
  - `mfs_prim` 의 F 꼴은 x86 원본과 다릅니다(x86 원본은 `long long` 꼴). 그래서 m68k 덮어쓰기로 둡니다.
  - `cmu_syscalls` C1·C2 는 x86 원본과 같습니다.
- 바이트로 구별되지 않는 꼴(mfs_prim F1·F2·F4, cmu_syscalls C1·C2)과 `cmu_syscalls` 의 자리를 사용자에게 묻습니다.
- 사용자 결정 **D090**:
  - `mfs_prim` 은 "F1 double 로 바꿈 (Recommended)" 입니다. m68k 덮어쓰기에 둡니다(x86 원본은 `long long` 꼴).
  - `cmu_syscalls` 는 "C2 else 더하기 (Recommended)" 이고, 자리는 "07 본 파일 (Recommended)" 입니다.

### 472.3 D090 구현 계획(07 본 파일 `cmu_syscalls.c` + 덮어쓰기 `mfs_prim.c` + x86 전체 재빌드 s6l9; 코딩 전, 2026-10-16)

§471.3 절차를 그대로 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p472-m1/out/P472__F1.o`·`m5p472-c1/out/P472__C2.o` 를 final 의 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집:
   - 본 파일 `bsd/kern/cmu_syscalls.c` 452–459 행을 C2 꼴로 바꿉니다. `}` 를 `} else {` 로 하고, `th = …`·`thread_reference(th);` 를 들여 쓴 뒤 `}` 를 더합니다(줄 수 +1). `} else {` 줄에 `/* plan 472 (D090): … */` 를 붙입니다.
   - 덮어쓰기 `v183.34/m68k/src/kern/mfs_prim.c`(새 파일): 165–167 행 앞에 `#if m68k /* plan 472 (m68k) begin */` F1 세 줄 `#else /* plan 472 (m68k) end */` 를 두고, 뒤에 `#endif /* plan 472 (m68k) */` 를 둡니다.
   - 확인: `check_derived` 를 통과해야 하고, 본 파일에 표시 문자열이 없어야 합니다. m68k 쪽 글은 python 으로 변형 F1 과 같은지 봅니다(주석·전처리 줄 제외).
2. x86 전체 재빌드 s6l9 를 합니다. 통과 조건은 §469.4 와 같습니다.
3. prefixdiff s6l8↔s6l9(plan 472):
   - 스테이징 차이는 `src/bsd/kern/cmu_syscalls.c` 하나여야 하고, 키·명령 차이는 없어야 합니다.
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-cmu_syscalls']` 여야 합니다. 줄 수가 바뀌어 STABS 가 다를 수 있습니다. `differing_non_stabs_equal` 은 true 여야 합니다.
4. 링크 `s6p472-ln1` → `identical` 과 `cmp` 가 원본과 같아야 합니다.
5. `stage_m68k.py`:
   - `X86[472] = 's6l9'`, `EXCEPTS[472] = EXCEPTS[471]` 에 `x86-cmu_syscalls`·`x86-mfs_prim` 사유를 더합니다.
   - `MARKERS['plan 472 (m68k)']` 를 등록하고 `--plan` 문서를 고칩니다.
   - `--plan 472 stage m0p472-a1-stage` → x86gate(s6l9) → `m0p471-a1-stage` 와의 차이는 둘(`src/bsd/kern/cmu_syscalls.c`·`src/kern/mfs_prim.c`)이어야 합니다.
6. final: `m5_m68k_final.py`(plan 472, 두 객체 모두 기대 사유 빈 목록 = OBJECT_MATCH)로 run `m5p472-a1` 을 돌립니다.
7. 기록:
   - PROVENANCE: cmu_syscalls.c 행을 그 자리에서 갱신하고, mfs_prim 덮어쓰기는 새 행으로 둡니다.
   - MODIFICATIONS 두 행, DECISIONS D090 을 적습니다.
   - diff `x86-cmu_syscalls-plan472.diff`·`m68k-mfs_prim.diff` 를 만들고, evidence md 에 plan 472 절을 덧붙입니다.
   - 집계: OBJECT_MATCH +2, 코드 차이가 남은 객체는 16 → 14 입니다.

### 472.4 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 줄 범위(cmu_syscalls 452–459, mfs_prim 165–167)가 맞고, 줄 끝 주석은 토큰을 바꾸지 않음 | §472.3 작성 때 줄 읽음; 구현 뒤 final 이 판정 | ✅ |
| 덮어쓰기 표시 줄은 6(시작·F1 셋·`#else` 끝·`#endif`) | 구현 뒤 `check_derived` 로 확인 | ✅ |
| x86 에서 이 소스를 쓰는 객체는 `x86-cmu_syscalls` 하나 | s6l8 `cc -M` 기록 grep(파일 1 개) | ✅ |
| x86 C2 는 STABS 1036 대 s6l8 1034 → prefixdiff 에 `['x86-cmu_syscalls']` 로 나올 것 | python obj_sig STABS 수(1036 / 1034) | ✅ 허용 목록에 이미 있음 |
| m68k 다른 객체 영향 없음 | 스테이징 차이 검사가 판정 | ✅ |
| final 은 JSON 명세(`bss_records: []`, 두 객체 사유 빈 목록) | 도구 구조 | ✅ |
| PROVENANCE 553 행 그 자리 갱신, 385 행 유지 + 덮어쓰기 새 행 | 두 행 읽음(§472.3) | ✅ |

### 472.5 D090 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p472-final-20261016.json`

- 07 편집:
  - 본 파일 `bsd/kern/cmu_syscalls.c` 는 806 → 807 행입니다. 주석을 뺀 토큰이 변형 C2 와 같습니다(python).
  - 새 덮어쓰기 `v183.34/m68k/src/kern/mfs_prim.c` 는 표시 줄 6 이고, m68k 가지의 토큰이 F1 과 같습니다. 파생 검사를 통과했습니다.
- x86 전체 재빌드 s6l9:
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6l8↔s6l9: 스테이징 차이는 `src/bsd/kern/cmu_syscalls.c` 하나이고, `sha_differ_not_rid_only` 는 `['x86-cmu_syscalls']`(STABS 만; 비 STABS 같음)입니다.
  - 링크 `s6p472-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 472 stage m0p472-a1-stage` 와 x86gate(s6l9 일곱)가 모두 같고 v183 경로는 0 입니다. `m0p471-a1-stage` 와의 차이는 두 파일입니다.
  - final run `m5p472-a1`(명령 2 개, 종료 0)에서 `m5_m68k_final.py check` 를 통과했습니다. **`x86-mfs_prim`·`x86-cmu_syscalls` 모두 OBJECT_MATCH** 이고, 고른 변형과 서명이 같으며, 원본에 없는 미정의는 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 172 입니다(+ 명시 배치 `ufs_alloc` 1).
  - "코드 검증 + bss 추정" 은 21 입니다.
  - 코드 차이가 남은 객체는 14 개입니다(netif, miniMon, igmp, time_stamp, nfs_client, kern_fork, ufs_subr, ipc_mig, mach_clock, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 1098 행(553 행 갱신, 덮어쓰기 한 행 새로, 중복 0), MODIFICATIONS 631 행, DECISIONS D090 을 적었습니다.
  - diff 둘을 만들고 evidence 두 개에 plan 472 절을 덧붙였습니다.
  - 도구는 `stage_m68k.py`(plan 472)를 고쳤고, 고치기 전 사본은 `08_build/artifacts/m5p472/` 에 있습니다.

## 473. M5-30 세부 계획 — m68k `time_stamp`(`event_set_ts`)·`mach_clock`(`time_of_boot`·`service_timer` 자리)(코딩 전, 2026-10-16)

확인한 사실(§470 목록·원본 목록·기호표·참고 코드를 직접 읽음):
- **`time_stamp` `_kern_timestamp`**(원본 200 B, 우리 224 B):
  - 07 `kern/time_stamp.c` 68–69 행은 m68k 에서 `event_set_ts(&ts)` 를 부릅니다. 이 인라인 함수는 m68k 덮어쓰기 `machdep/m68k/eventc.h`(56 행에서 가져옴; PROVENANCE 1067 행, NeXTMach mk-108.1 `next/eventc.h`)에 있고, 다시 읽는 고리(`do … while (tsp->low_val < temp)`) 꼴입니다(eventc.h 104–114 행).
  - 원본(0x4054aaa–)은 다음 순서입니다.
    - `splusclock()`(0x2600)
    - `*eventc_latch` 읽기, `(h<<16)|(m<<8)|l` 을 `& 0xfffff`
    - `*event_middle ^ low` 의 bit 19 가 서 있으면 `*event_middle += 0x80000`. 그 뒤 `& 0xfff80000` 이 0 이면 `(*event_high)++`
    - `tsp->high_val = *event_high; tsp->low_val = *event_middle | low;`
    - `splx(s)`
  - 곧 하드웨어를 한 번 읽고, `event_sync` 몸체에 마스크를 더한 꼴입니다. 기호는 `_eventc_latch`·`_eventc_h`·`_eventc_m`·`_eventc_l`·`_event_middle`·`_event_high` 입니다.
  - `event_set_ts` 를 쓰는 07 소스는 `time_stamp.c` 하나입니다(grep). `time_stamp.c` 가 56 행 전에 가져오는 헤더는 `eventc.h` 를 부르지 않습니다(`mach/kern_return.h`·`kern/time_stamp.h`·`kern/clock.h` 와 그 아래, `meta_features.h` 확인).
- **`mach_clock`**(원본 964 B, 우리 1058 B):
  - `_clock_interrupt` 에 우리만 있는 64 비트 덩어리 둘이 있습니다. 07 `kern/mach_clock.c` 182·187 행의 `time_of_boot -= / += tickdelta * 1000;`(plan 235, x86 원본에서 넣음)입니다.
  - m68k 원본 기호표에 `_time_of_boot` 은 없습니다. 07 에서 `time_of_boot` 을 쓰는 곳은 이 파일(63 행 정의)과 i386 `machine_clock.c` 뿐입니다.
  - 원본은 정적 함수(spl 0x2300 = `splsched`, `telt->fcn`·`param` 읽고 `set` 지우기, `splx`, 호출 — `service_timer`)를 `_clock_interrupt` 바로 뒤, `_init_timeout_element`(0x404b11e) 앞에 둡니다. 07 은 199 행에 앞선 선언만 두고, 정의는 365–382 행(`host_adjust_time` 뒤)에 있습니다. -O2 는 소스 순서대로 냅니다(§467 과 같은 현상).
  - 레지스터 저장(a3 더 씀)과 분기 길이(`bra.w`/`.b`) 차이는 위 둘의 결과로 봅니다.

방법(`m5_m68k_srcvar.py`, 객체마다 명세·스테이징·run 을 따로, 바탕 `08_build/runs/tools/m0p472-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체):
- `time_stamp`(run `m5p473-t1`): 변형은 `time_stamp.c` 55–57 행의 `#if m68k / #import <machdep/m68k/eventc.h> / #endif` 를 고친 `eventc.h` 의 전문으로 바꿉니다. 고친 곳은 `event_set_ts` 만이고, 헤더 안 import 와 보호 매크로는 그대로입니다.
  - `E1`: `int s; register unsigned int low; s = splusclock(); low = *eventc_latch; low = (*eventc_h << 16) | (*eventc_m << 8) | *eventc_l; low &= EVENT_MASK; if ((low ^ *event_middle) & EVENT_HIGHBIT) { *event_middle += EVENT_HIGHBIT; if ((*event_middle & (~(EVENT_MASK>>1))) == 0) (*event_high)++; } tsp->high_val = *event_high; tsp->low_val = *event_middle | low; splx(s);`
  - `E2`: E1 의 비교를 `(*event_middle ^ low)` 로
  - `E3`: E1 의 증가를 `++*event_high` 로(원본은 증가 뒤 한 번 더 읽음: 0x4054b30)
  - `splusclock` 이 그 자리에서 보이는지는 컴파일이 판정합니다(안 보이면 실패로 기록하고 헤더 import 를 더한 2 차).
- `mach_clock`(run `m5p473-c1`):
  - `M1`: 63 행 정의, 182·187 행을 뺍니다. `service_timer` 정의(365–382 행)를 199 행 앞선 선언 바로 뒤로 옮깁니다(선언은 남김).
  - `M2`: 빼기만 합니다(옮기지 않음).
  - `M3`: 옮기기만 합니다.
- 판정(L1 `--place-from-image`): OBJECT_MATCH 이거나 bss 만 남아야 합니다. 원본에 없는 미정의 0, COMMON·외부 정의는 K 와 같아야 합니다(`mach_clock` 은 `_time_of_boot` 이 빠지는 것이 예상). 대조 K 가 `control_ref` 를 재현하는지(`control_equals_ref`)도 봅니다.
- x86 확인: `mach_clock` M3(옮기기)은 x86 원본과 같은지 `m5_x86_srcvar.py` 로 봅니다. `time_of_boot` 빼기와 `eventc.h` 는 m68k 전용이므로 덮어쓰기에 둡니다(`eventc.h` 는 덮어쓰기 전용 헤더라 그 파일을 고침).
- 고르기·결정·구현·final 은 §471·§472 와 같습니다.

### 473.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §473 은 `service_timer` 정의를 365–382 행이라 적었습니다. 실제로는 365–381 행이고(381 행이 `}`), `mach_clock_bootstrap`(351 행) 바로 뒤에 있습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `_kern_timestamp` 판독이 맞음; 0x4054b30 의 다시 읽기는 실제이나 후위·전위 증가의 증거는 아님 | 원본 목록(§473 작성 때) | ✅ 가설로 둠 |
| `splusclock` 은 `eventc.h:38` → `bsd/m68k/spl.h` → `kernserv/m68k/spl.h` 로 이미 보임 | `eventc.h` import 줄 직접 읽음(37–40 행) | ✅ "컴파일로 판정" 문구 대신 사실로 |
| 헤더 붙여넣기 방식은 이 m68k 시험에서 성립(앞서 `_EVENTC_` 정의 없음) | §473 준비 때 헤더 사슬 grep | ✅ |
| `event_set_ts` 의 다른 사용처 없음; 그래도 `kern/xpr.h` 를 거쳐 헤더를 읽는 객체가 있으니 바뀐 헤더로 다시 짓는 비교가 알맞음 | grep(§473) | ✅ final 단계에서 스테이징 차이와 x86gate 로 봄 |
| `mach_clock` 의 덩어리는 182·187 행, `_time_of_boot` 은 원본에 없음; 원본 0x404b0f0 이 `service_timer` | 원본 목록 0x404b0ec–0x404b0f8 읽음, 기호표 grep | ✅ |
| 크기 차 94 = 42 + 42 + 6 + 2 + 2(덩어리 둘, 저장 꼬리 합침, 분기 길이) | 검토자 계산 | ⏭️ M1 이 판정 |
| E4(= E2 의 피연산자 순서 + E3 의 전위 증가)를 더할 것 | 설계 | ✅ 추가 |
| 두 객체 모두 bss 가 없으므로 기준은 OBJECT_MATCH | §470 기록(사유 `__TEXT,__text: unverified` 하나) | ✅ 기준을 OBJECT_MATCH 로 |
| `service_timer` 끝 줄 381 | 381 행 직접 읽음 | ✅ 위 제 오류 |

### 473.2 변형 시험 결과(2026-10-16)

- `time_stamp`:
  - 1 차 run `m5p473-t1`(명령 5, 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-time-stamp-variants-p473-20261016.json`): E1–E4 는 서로 같은 객체이고 원본과 달랐습니다(`__TEXT,__text: fail`). 대조 K 는 §470 객체를 재현했습니다.
  - otool 비교(`08_build/artifacts/m5p473/otool/P473__E1.txt`)로 보니 남은 차이는 한 곳입니다. 원본은 `orl d0,d1; movel d1,…`(결과를 `low` 의 레지스터에)이고, 우리는 `orl d1,d0` 입니다. 다른 구간 수가 줄어 §446 멈춤 조건에 해당하지 않습니다.
  - 2 차 run `m5p473-t2`(명세 `spec2-time_stamp.json`; 기록 `m5-m68k-time-stamp-variants2-p473-20261016.json`): `tsp->low_val = low | *event_middle;` 로 바꾼 **E5(E1 바탕)·E6(E3 바탕)이 OBJECT_MATCH** 이고, 두 객체는 같습니다. 원본에 없는 미정의 0, 외부 정의는 K 와 같습니다.
  - 1 차에서 XOR 순서(E1/E2)와 증가 꼴(후위/전위, E1/E3)도 객체가 같았습니다. 바이트로 구별되지 않습니다.
- `mach_clock`(run `m5p473-c1`, 명령 4, 모두 종료 0; 기록 `m5-m68k-mach-clock-variants-p473-20261016.json`):
  - **M1 이 OBJECT_MATCH** 입니다(COMMON 에서 `_time_of_boot` 이 빠짐, 그 밖 K 와 같음). M2(빼기만)·M3(옮기기만)은 맞지 않아, 두 원인이 모두 필요합니다.
  - x86(run `m5p473-xc1`; 기록 `m5-x86-mach-clock-variants-p473-20261016.json`): M3(옮기기)은 x86 원본과 같습니다.
- 사용자에게 묻는 것: `time_stamp` 의 꼴(E5/E6), `mach_clock` 의 `service_timer` 옮기기 자리(07 본 파일 / 덮어쓰기)입니다. `time_of_boot` 빼기는 x86 원본에 있는 코드라 덮어쓰기(`#if !m68k` 꼴)로 둡니다.
- 사용자 결정 **D091**:
  - `time_stamp` 는 "E5 후위 증가 (Recommended)" 입니다. m68k 덮어쓰기 헤더 `machdep/m68k/eventc.h` 의 `event_set_ts` 를 E5 꼴로 고칩니다.
  - `mach_clock` 의 `service_timer` 옮기기는 "07 본 파일 (Recommended)" 이고, `time_of_boot` 빼기는 m68k 덮어쓰기에 둡니다.

### 473.3 D091 구현 계획(07 본 파일 `mach_clock.c` + 덮어쓰기 `mach_clock.c`·`eventc.h` + x86 전체 재빌드 s6l10; 코딩 전, 2026-10-16)

§472.3 절차를 따릅니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p473-t2/out/P473__E5.o`·`m5p473-c1/out/P473__M1.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집:
   - 본 파일 `kern/mach_clock.c`: `service_timer` 정의(365–381 행)를 199 행 앞선 선언 바로 뒤로 옮깁니다(M3 와 같은 글). 옮긴 정의 앞에 `/* plan 473 (D091): … */` 한 줄을 둡니다.
   - 덮어쓰기 `v183.34/m68k/src/kern/mach_clock.c`(새 파일): 새 본 파일에 줄을 끼우는 꼴로, `time_of_boot` 정의와 보정 두 줄을 각각 `#ifndef m68k /* plan 473 (m68k) */` … `#endif /* plan 473 (m68k) */` 로 감쌉니다(작성, 원본에 `_time_of_boot` 없음).
   - 덮어쓰기 헤더 `machdep/m68k/eventc.h`: `event_set_ts` 몸체를 E5 로 바꾸고 `/* plan 473 (D091): … */` 를 붙입니다. 이 파일은 본 파일 짝이 없는 덮어쓰기 전용 헤더라 파생 검사 대상이 아닙니다(stage_m68k 규칙은 `.c`).
   - 확인: 파생 검사, 본 파일 표시 문자열 없음을 봅니다. python 으로 본 파일 토큰이 M3 와, 덮어쓰기 m68k 가지가 M1 과, `time_stamp` 에서 펼쳐진 헤더의 `event_set_ts` 가 E5 와 같은지 봅니다.
2. x86 전체 재빌드 s6l10 → check 관문(§469.4 와 같음).
3. prefixdiff s6l9↔s6l10(plan 473):
   - 스테이징 차이는 `src/kern/mach_clock.c` 하나여야 합니다.
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-mach_clock']` 이고, `differing_non_stabs_equal` 은 true 여야 합니다.
4. 링크 `s6p473-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`:
   - `X86[473] = 's6l10'`, `EXCEPTS[473] = EXCEPTS[472]` 에 `x86-mach_clock`·`x86-time_stamp` 사유를 더합니다.
   - `MARKERS['plan 473 (m68k)']` 를 등록하고 `--plan` 문서를 고칩니다.
   - `--plan 473 stage m0p473-a1-stage` → x86gate(s6l10) → `m0p472-a1-stage` 와의 차이는 `src/kern/mach_clock.c`·`src/machdep/m68k/eventc.h` 둘이어야 합니다.
   - `eventc.h` 를 가져오는 다른 m68k 객체는 줄 번호(STABS)만 바뀌고 코드는 그대로일 것입니다(바뀐 함수의 사용처는 `time_stamp` 하나). 이번 final 은 두 객체만 컴파일합니다.
6. final(`m5_m68k_final.py`, plan 473): `time_stamp`·`mach_clock` 모두 OBJECT_MATCH 를 기대합니다. run `m5p473-a1`.
7. 기록:
   - PROVENANCE: 본 파일 `mach_clock.c` 행과 `eventc.h` 1067 행을 그 자리에서 갱신하고, `mach_clock.c` 덮어쓰기는 새 행으로 둡니다.
   - MODIFICATIONS, DECISIONS D091, diff 셋, evidence 를 적습니다.
   - 집계: OBJECT_MATCH +2, 코드 차이가 남은 객체는 14 → 12 입니다.

### 473.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): §473.3 은 x86 재빌드 접두어를 `s6l10` 으로 정했습니다. 그런데 `l2_prefix_diff.py` 의 RID 정규화(86–89 행)는 실행 경로 바이트를 단순 치환합니다. s6l9 객체 가운데 15 개가 경로 `/08_build/runs/s6l9-` 를 품고 있으므로(python), 길이가 다른 접두어(`s6l10` 5 자 대 `s6l9` 4 자)로는 정규화가 같아질 수 없습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 덮어쓰기 표시 6, MARKERS 를 파생 검사 전에 등록 | 구현 때 실제 `check_derived` 로 확인 | ✅ 순서 고침 |
| 새 본 파일 토큰 = M3, 덮어쓰기 m68k 가지 = M1 | 구현 뒤 python 으로 확인 | ✅ |
| `eventc.h` 는 덮어쓰기 전용 헤더로 파생 검사 없이 m68k 층이 이김 | `cmd_stage` 설명(§469 때 읽음) | ✅ |
| `eventc.h` 를 가져오는 다른 객체 12 개는 코드가 그대로일 것(바뀐 함수 사용처는 `time_stamp` 하나), 단 이번 final 로 증명되지는 않음 | grep(§473) | ⚖️ 기대로 기록. 다음 전체 m68k 재컴파일 때 비 STABS 로 확인 |
| final `time_stamp` 는 REF E5 와 네 비교에서 같을 것 | final 이 판정 | ⏭️ |
| x86 M3 는 s6l9 와 비 STABS 같음(STABS 862 대 868) | §473.2 x86 기록(M3 same_as_ref) | ✅ |
| **접두어 길이가 다르면 RID 정규화가 깨짐** | python: 경로를 품은 s6l9 객체 15 개, 길이 4 대 5 | ✅ 위 제 오류. 접두어를 같은 길이의 `s6la` 로 |
| PROVENANCE 595·1067 갱신, 134 유지; 옮긴 `service_timer` 는 작성(D024) 표시 유지 | 행 읽음 | ✅ |

계획 수정: x86 재빌드 접두어는 `s6la`(RID `s6la-g1a` 등), 링크 `s6p473-ln1` 로 합니다. `X86[473] = 's6la'` 이고, prefixdiff 는 `s6l9 s6la` 입니다. 나머지 기준은 그대로입니다.

### 473.5 D091 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p473-final-20261016.json`

- 07 편집:
  - 본 파일 `kern/mach_clock.c` 는 381 → 382 행입니다(정의를 옮기고 주석 한 줄). 토큰이 M3 와 같습니다.
  - 새 덮어쓰기 `v183.34/m68k/src/kern/mach_clock.c` 는 표시 줄 6 이고, m68k 가지의 토큰이 M1 과 같습니다.
  - 덮어쓰기 헤더 `machdep/m68k/eventc.h` 는 135 → 144 행입니다(`event_set_ts` 만 바꿈). `time_stamp.c` 에 펼친 토큰이 E5 와 같습니다.
  - 파생 검사를 통과했습니다(python).
- x86 전체 재빌드 s6la(§473.4 의 같은 길이 접두어):
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6l9↔s6la: 스테이징 차이는 `src/kern/mach_clock.c` 하나이고, `sha_differ_not_rid_only` 는 `['x86-mach_clock']`(STABS 만, 비 STABS 같음)입니다. RID 정규화도 성립했습니다.
  - 링크 `s6p473-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 473 stage m0p473-a1-stage` 와 x86gate(s6la 일곱)가 모두 같고 v183 경로는 0 입니다. `m0p472-a1-stage` 와의 차이는 `src/kern/mach_clock.c`·`src/machdep/m68k/eventc.h` 둘입니다.
  - final run `m5p473-a1`: **`x86-time_stamp`·`x86-mach_clock` 모두 OBJECT_MATCH** 이고, 고른 변형과 서명이 같으며, 원본에 없는 미정의는 0 입니다.
  - `eventc.h` 를 가져오는 다른 m68k 객체 12 개의 코드는 그대로일 것으로 봅니다(바뀐 함수의 사용처는 `time_stamp` 하나). 다음 전체 m68k 재컴파일 때 비 STABS 로 확인합니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 174 입니다(+ 명시 배치 `ufs_alloc` 1).
  - "코드 검증 + bss 추정" 은 21 입니다.
  - 코드 차이가 남은 객체는 12 개입니다(netif, miniMon, igmp, nfs_client, kern_fork, ufs_subr, ipc_mig, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 1099 행(595·1067 행 갱신, 덮어쓰기 한 행 새로, 중복 0), MODIFICATIONS 634 행, DECISIONS D091 을 적었습니다.
  - diff 셋을 만들고 evidence 두 개에 plan 473 절을 덧붙였습니다.

## 474. M5-31 세부 계획 — m68k `igmp`: `IGMP_RANDOM_DELAY` 덧셈 순서와 `igmp_fasttimo` 의 멀티캐스트 순회 함수(코딩 전, 2026-10-16)

확인한 사실(§470 목록, 원본 목록 0x4025be0–0x402616c, 기호표, 참고 코드를 직접 읽음):
- 다른 구간은 `_igmp_input`·`_igmp_joingroup`(크기 같음)과 `_igmp_leavegroup`·`_igmp_fasttimo`(원본이 28 B 김)입니다.
- **덧셈 순서**:
  - 원본 `_igmp_input`·`_igmp_joingroup` 의 지연 계산은 `ipstat.ips_total`(`_ipstat`+0, `movel #_ipstat` 을 레지스터에 두고 `a5@`) + `IA_SIN(in_ifaddr)->sin_addr`(`_in_ifaddr` 의 +4) + 그룹 주소 순서로 더합니다.
  - 07 `bsd/netinet/igmp.c:57-60` 의 `IGMP_RANDOM_DELAY`(x86 원본에서 작성)는 앞 두 항이 반대입니다.
  - m68k 에서 `ntohl` 은 항등이라 덧셈 항 순서가 코드에 그대로 남습니다. 루프 밖으로 올린 적재 순서 차이도 같은 원인으로 봅니다.
- **순회 함수**:
  - 원본은 `_igmp_leavegroup` 뒤에 기호 없는 정적 함수 둘을 둡니다.
    - 0x4025f16: 인자 `step` 으로 `IN_NEXT_MULTI` 매크로 몸체와 같은 명령을 하고 `inm` 을 돌려줍니다.
    - 0x4025f4c: `step->i_ia = in_ifaddr; step->i_inm = 0;` 뒤 0x4025f16 을 불러 그 값을 돌려줍니다.
  - 원본 `_igmp_fasttimo`(0x4025f6a)는 `splnet`, `igmp_timers_are_running = 0` 뒤 `inm = first(&step)` 로 시작해 몸체 끝마다 `inm = next(&step)` 을 부르는 고리입니다.
  - 원본 `_igmp_input` 은 이 함수들을 부르지 않고 매크로를 펼친 꼴입니다(우리와 같음; 원본 `_igmp_input` 안 `bsr` 목록에 0x4025f16·0x4025f4c 없음).
  - 07 `igmp_fasttimo`(214–239 행)는 매크로 꼴입니다. Darwin 0.1 `igmp.c` 도 매크로 꼴이고, 정적 함수가 없습니다(`IGMP_RANDOM_DELAY` 는 Darwin 에서 `random()`).
  - 가설: m68k 원본 `igmp.c` 는 `igmp_leavegroup` 뒤에 `static` 순회 함수 둘(next, first 순서)을 두고 `igmp_fasttimo` 에서만 썼습니다. -O2 는 `inline` 없는 함수를 펼치지 않고 소스 순서대로 냅니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p473-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 `O470__…igmp.o`, run `m5p474-i1`):
- `R`: `IGMP_RANDOM_DELAY` 를 `((ipstat.ips_total + ntohl(IA_SIN(in_ifaddr)->sin_addr.s_addr) + ntohl((multiaddr).s_addr)) % (IGMP_MAX_HOST_REPORT_DELAY * PR_FASTHZ) + 1)` 로 바꿉니다.
- `H`: `igmp_leavegroup` 뒤에 둘을 둡니다.
  - `static struct in_multi *igmp_next_multi(step) struct in_multistep *step; { struct in_multi *inm; IN_NEXT_MULTI(*step, inm); return (inm); }`
  - `static struct in_multi *igmp_first_multi(step) …{ step->i_ia = in_ifaddr; step->i_inm = NULL; return (igmp_next_multi(step)); }`
  - `igmp_fasttimo` 의 고리를 `for (inm = igmp_first_multi(&step); inm != NULL; inm = igmp_next_multi(&step))` 로 바꾸고, `(void) &step;` 줄(plan 251)은 뺍니다. 이름은 작성입니다.
- `RH`: R + H 입니다.
- `RH2`: RH 에서 고리를 `inm = igmp_first_multi(&step); while (inm != NULL) { …; inm = igmp_next_multi(&step); }` 로 쓴 꼴입니다.
- 판정(L1 `--place-from-image`): §470 사유는 `__TEXT,__text: unverified`(bss 있는지 실행으로 확인)입니다. 맞으면 OBJECT_MATCH 이거나 bss 만 남아야 합니다. 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; `igmp.c` 는 s6l5 뒤 바뀌지 않았는지 stage 가 assert): R·H 가 x86 원본과 같은지 봅니다. 같으면 자리를 묻고, 다르면 m68k 덮어쓰기로 둡니다.
- 고르기·결정·구현·final 은 §471–§473 과 같습니다.

### 474.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- §474 는 §470 의 igmp L1 사유를 `__TEXT,__text: unverified` 하나로 적었습니다. 실제로는 text·data·bss 셋 다 unverified 입니다(survey 기록).
- "Darwin 에는 정적 함수가 없다" 는 틀렸습니다. Darwin 에도 `static igmp_sendreport` 가 있습니다. "정적 순회 함수가 없다" 가 맞습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| igmp 의 모든 차이는 R(덧셈 순서)과 H(순회 함수 둘과 그 사용)로 설명됨; `_igmp_leavegroup` 자체는 같고 구간에 이름 없는 함수가 들어감 | §474 작성 때 목록 비교; 검토자 해독(같은 결론) | ✅ 문구 고침 |
| 구조체 오프셋(`i_ia` 0, `i_inm` 4, `inm_timer` 0x10, `inm_next` 0x14, `ia_next` 0x40, `ia_multiaddrs` 0x44) | 원본 명령의 변위와 `in_var.h` 매크로(§474 준비 때 읽음) | ✅ |
| 0x40b3528 = `igmp_all_hosts_group`(bss), 0x40aec04 = `igmp_timers_are_running`(data); data 40 B 가 원본과 같음 | 쓰임새(§474 준비); data 비교는 검토자 | ⏭️ final L1 이 판정 |
| 크기 차 28 = 도우미 84 − 고리 56 | 검토자 계산 | ⏭️ RH 가 판정 |
| H 의 함수 꼴(포인터를 받아 `struct in_multi *` 를 돌려줌), next 가 first 앞; `(void) &step;` 빼기 | 설계 | ✅ |
| §470 사유는 text·data·bss 셋 | survey 기록 python 출력 | ✅ 위 제 오류 |
| `(void) &step;` 은 224 행 | grep | ✅ |
| `_igmp_joingroup` 은 `_ipstat` 를 직접 적재(레지스터 아님), `+4` 는 `in_ifaddr` 가 가리키는 대상 안의 오프셋 | 원본 목록 0x4025ec0–0x4025ed0 | ✅ 문구 고침 |
| x86 중립성은 R·H 를 따로 시험해야 함 | 설계 | ✅ x86 시험에 R·H·RH·RH2 모두 넣음 |

### 474.2 변형 시험 결과(2026-10-16)

- m68k(run `m5p474-i1`, 명령 5 개 모두 종료 0; 기록 `09_validation/reconstruction/m5-m68k-igmp-variants-p474-20261016.json`). 대조 K 는 §470 객체를 재현했습니다.
  - **RH·RH2 는 L1 사유가 `__DATA,__bss: unverified` 하나** 입니다(텍스트·데이터 통과). 두 객체는 같고, 원본에 없는 미정의 0, COMMON·외부 정의는 K 와 같습니다.
  - R 만, H 만으로는 맞지 않습니다. 두 원인이 모두 필요합니다.
- x86(run `m5p474-xi1`, 바탕 s6l5; 기록 `m5-x86-igmp-variants-p474-20261016.json`): R·H·RH·RH2 가 모두 x86 원본과 같습니다. x86 -O3 가 정적 도우미를 펼칩니다.
- 사용자에게 묻는 것: 고리 꼴(RH 의 for / RH2 의 while)과 자리(07 본 파일 / m68k 덮어쓰기)입니다. final 에서는 bss 자리를 zerofill 로 추정합니다.
- 사용자 결정 **D092**: `igmp` 의 고리는 "RH for 문 (Recommended)" 이고, 자리는 "07 본 파일 (Recommended)" 입니다. `IGMP_RANDOM_DELAY` 덧셈 순서와 순회 함수 둘을 07 본 파일에 둡니다.

### 474.3 D092 구현 계획(07 본 파일 `igmp.c` + x86 전체 재빌드 s6lb; 코딩 전, 2026-10-16)

§472.3 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p474-i1/out/P474__RH.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집: 본 파일 `bsd/netinet/igmp.c` 를 RH 와 같은 글로 바꿉니다.
   - `IGMP_RANDOM_DELAY` 의 덧셈 순서를 바꿉니다.
   - `igmp_leavegroup` 뒤에 `igmp_next_multi`·`igmp_first_multi` 를 둡니다(작성, D024).
   - `igmp_fasttimo` 를 for 고리로 하고, `(void) &step;` 은 뺍니다.
   - 바뀐 자리마다 `/* plan 474 (D092): … */` 를 붙입니다.
   - python 으로 주석을 뺀 토큰이 RH 와 같은지 확인합니다.
2. x86 전체 재빌드 s6lb(접두어 길이 4, §473.4)와 check 관문을 거칩니다.
3. prefixdiff s6la↔s6lb(plan 474):
   - 스테이징 차이는 `src/bsd/netinet/igmp.c` 하나여야 합니다.
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-igmp']`, `differing_non_stabs_equal` 은 true 여야 합니다.
4. 링크 `s6p474-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`: `X86[474] = 's6lb'`, `EXCEPTS[474] = EXCEPTS[473]` 에 `x86-igmp` 사유를 더하고, `--plan` 문서를 고칩니다. 표시는 더하지 않습니다(덮어쓰기 없음). `--plan 474 stage m0p474-a1-stage` → x86gate(s6lb) → `m0p473-a1-stage` 와의 차이는 `src/bsd/netinet/igmp.c` 하나여야 합니다.
6. final(`m5_m68k_final.py`, plan 474):
   - `igmp` 의 기대 사유는 `['__DATA,__bss: unverified']` 입니다.
   - zerofill 후보는 §464·§467(nfs)·§469(ns_timer)·§471(kern_proc·kalloc) 후보와 겹치지 않아야 합니다(`bss_records` 에 세 기록).
7. 기록:
   - PROVENANCE 의 `igmp.c` 행을 그 자리에서 갱신하고, MODIFICATIONS·DECISIONS D092·diff·evidence 를 적습니다.
   - 집계: "코드 검증 + bss 추정" +1, 코드 차이가 남은 객체는 12 → 11 입니다.

### 474.4 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 접두어 `s6lb` 는 길이 4, 미사용 | `ls 08_build/runs/tools`(§474.3 작성 전 `s6la` 까지만 있음); 구현 때 prepare 가 기존 이름이면 멈춤 | ✅ |
| 다른 x86·m68k 객체는 `igmp.c` 를 쓰지 않음 | x86 `cc -M` 기록·m68k 소스 검사(검토자); 스테이징 차이 검사가 판정 | ✅ 스테이징 차이로 확인 |
| final 은 `bss_records` 세 기록을 읽고, §464 기록은 `objs` 가 따로 읽음(스키마가 달라 `bss_records` 에 넣지 않음) | `m5_m68k_final.py`·`m5_m68k_zerofill.py:148` 코드 | ✅ |
| 예상 bss 후보 [0x40b3528, 0x40b352c), 겹침 0 | 검토자 계산 | ⏭️ final 이 판정 |
| prefixdiff 관문에 `stage_keys_differ == []`·`cmd_differ == []` 포함 | §469.4 부터 같은 관문 | ✅ |
| PROVENANCE 611 행 그 자리 갱신 | 행 grep | ✅ |

### 474.5 D092 구현 결과(2026-10-16) — 최종 기록 `09_validation/reconstruction/m5-m68k-p474-final-20261016.json`

- 07 편집: 본 파일 `bsd/netinet/igmp.c` 는 292 → 311 행입니다. 주석을 뺀 토큰이 RH 와 같습니다(python).
- x86 전체 재빌드 s6lb:
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6la↔s6lb: 스테이징 차이는 `src/bsd/netinet/igmp.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `['x86-igmp']`(STABS 만, 비 STABS 같음)입니다.
  - 링크 `s6p474-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다.
- m68k:
  - `--plan 474 stage m0p474-a1-stage` 와 x86gate(s6lb 일곱)가 모두 같고, `m0p473-a1-stage` 와의 차이는 `igmp.c` 하나입니다.
  - final run `m5p474-a1`: `x86-igmp` 은 L1 사유가 `__DATA,__bss: unverified` 하나이고, REF 와 서명이 같으며, 미정의는 0 입니다.
  - zerofill(`m5-m68k-p474-zerofill-20261016.json`)은 reference-inferred [0x40b3528, 0x40b352c) 4 B 이고, 이전 후보와 겹침 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 174, "코드 검증 + bss 추정" 은 22 입니다.
  - 코드 차이가 남은 객체는 11 개입니다(netif, miniMon, nfs_client, kern_fork, ufs_subr, ipc_mig, tty, callout, kdp_udp, mach_net, swapfs).
- 기록: PROVENANCE 611 행 갱신(중복 0), MODIFICATIONS, DECISIONS D092, diff, `x86-igmp.md` 를 적었습니다.

## 475. M5-32 세부 계획 — m68k `kern_fork`(`switch_unix_context` 의 주소 묶음)·`nfs_client`(`nfs_attrcache_va` 의 레지스터) 2 차 변형 시험(07 변경 없음; 코딩 전, 2026-10-16)

§470.2 순위 2·3 위입니다. §465 의 1 차 변형(kern_fork E·M, nfs_client B·D)으로는 풀리지 않았습니다. 이번에는 원본 바이트로 범위를 좁힌 뒤 새 꼴을 시험합니다.

확인한 사실(원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, 기호표, 07·SDK·참고 코드를 직접 읽음):
- **`kern_fork`**:
  - 원본 `_switch_unix_context`([0x4006700, 0x4006720))는 `movel a6@(8),a0; movel a0@(0x80),0x40b57d4:l; movel a0@(0xc),a0; movel a0@(0x30),0x40b57d0:l` 입니다.
  - `_active_u` 는 0x40b57d0 의 `__common`(절 6) 기호이고, 다음 기호는 0x40b57d8 `_bfreelist` 입니다. 그러니 두 저장은 `active_u` 의 +4(`uthread`)와 +0(`utask`)입니다.
  - 07 `bsd/kern/kern_fork.c:516-517` 은 `active_u[0].uthread = th->_uthread; active_u[0].utask = th->task->u_address;` 이고, 객체는 `lea _active_u+4,a1` 뒤 `a1@`·`a1@(-4)` 로 씁니다(크기는 같음).
  - 원본에서 바로 이어지는 두 `movel` 이 자료 영역(0x40ad964 이상)의 4 B 떨어진 절대 주소에 쓰는 곳은 60 곳(34 함수)입니다(python; 예: `_host_set_time`, 내림차순인 `_pset_sys_bootstrap`). 그러니 이 컴파일러가 늘 주소를 레지스터에 묶는 것은 아닙니다.
  - SDK `bsd/sys/user.h:350` 은 `#define u (active_u[cpu_number()])`, `:358` 은 `extern struct _u_address active_u[];` 입니다. m68k SDK `bsd/m68k/cpu.h:65-74` 의 `cpu_number()` 는 `NCPUS > 1` 일 때 인라인 함수, 아니면 `(0)` 입니다.
  - NeXTMach mk-108.1·Darwin 0.1·Mach4 에는 `switch_unix_context`·`active_u` 가 없습니다(전수 grep; Mach4 `vm_pageout.c` 의 한 줄은 다른 낱말). 07 의 이 함수는 작성(plan 202, D024)입니다.
- **`nfs_client`**:
  - 원본 `_nfs_attrcache_va`([0x40262ac, 0x4026304))와 객체의 차이는 0x40262d8–0x40262de 의 `moveq #124,d0; addl a2@(0x2e),d0; movel d0,sp@-` 하나입니다. 객체는 같은 자리에 d1 을 씁니다.
  - 이것은 `vtor(vp)->r_attr = *va;`(58 B 구조체 대입 → `_bcopy` 0x4092d2c)의 대상 주소입니다.
  - 07 `bsd/nfs/nfs_client.c:157-168` 은 NeXTMach `nfs/nfs_client.c:147-158` 과 같은 글입니다. `vtor`·`vtomi` 매크로도 SDK 와 NeXTMach 가 같습니다.

가설(근거 약함, 시험으로만 가립니다):
- `kern_fork`: 원본은 첨자를 상수 0 이 아니라 변수나 `u` 매크로로 썼고, 그래서 주소가 상수 주소 CSE 를 거치지 않았을 수 있습니다.
- `nfs_client`: 매개변수의 `register`, 지역 변수 `rp`, 조건 나누기가 의사 레지스터 번호와 배정 순서를 바꿨을 수 있습니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p474-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__…`, run `m5p475-f1`·`m5p475-n1`; 명세는 무시 대상 `08_build/artifacts/m5p475/spec-*.json`):
- `kern_fork`(`switch_unix_context` 몸체 513–518 행만 바꿉니다):
  - `U`: `u.uthread = th->_uthread; u.utask = th->task->u_address;`(SDK `u` 매크로)
  - `C`: 함수 머리에 `int cpu = cpu_number();` 를 두고 `active_u[cpu].uthread …; active_u[cpu].utask …;`
  - `R`: C 와 같되 `register int cpu = cpu_number();`
  - `P`: `register struct _u_address *up = &active_u[cpu_number()];` 뒤 `up->uthread …; up->utask …;`(주소를 레지스터에 두는 꼴; 대조용)
  - `V`: 매개변수를 `register thread_t th;` 로
- `nfs_client`(`nfs_attrcache_va` 157–168 행만 바꿉니다):
  - `R`: 매개변수를 `register struct vnode *vp; register struct vattr *va;` 로
  - `L`: 지역 변수 `struct rnode *rp;` 를 두고, 검사 뒤 `rp = vtor(vp); rp->r_attr = *va;`
  - `Q`: L 과 같되 `register struct rnode *rp;`
  - `S`: 조건을 `if (vp->v_flag & VNOCACHE) return; if (vtomi(vp)->mi_noac) return;` 둘로 나눔
- 판정(L1 `--place-from-image`):
  - `kern_fork` 의 §470 사유는 확인해서 적습니다. 맞는 꼴은 OBJECT_MATCH(또는 §470 에서 이미 남아 있던 bss 사유 하나)여야 합니다.
  - 원본에 없는 미정의는 0 이어야 하고, COMMON·외부 정의는 K 와 같아야 합니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; 두 파일이 s6l5 뒤 그대로인지 stage 가 assert): m68k 에서 맞은 꼴이 x86 원본과 같은지 봅니다.
- 고르기(미리 정함):
  - 대조 K 가 §470 객체를 재현하지 못하면 그 객체는 멈춥니다.
  - 맞는 꼴이 하나이면, 그 꼴과 자리(07 본 파일 또는 m68k 덮어쓰기)를 사용자에게 묻습니다. 자리는 x86 결과를 함께 보고합니다.
  - 맞는 꼴이 여럿이면 사용자에게 묻습니다.
  - 맞는 꼴이 없으면 기록만 하고 07 은 바꾸지 않습니다. 같지 않은 꼴의 차이 모양(레지스터·주소 꼴이 바뀌었는지)은 다음 가설에 씁니다.
- 구현·final 은 §471–§474 와 같습니다.

### 475.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- 초안은 "177 곳"이라고 적었습니다. 그것은 세 줄 창 안에서 겹치는 쌍까지 센 수(64 함수)였습니다. 정의를 "바로 이어지는 두 `movel`, 4 B 차"로 정해 다시 세니 60 곳(34 함수)입니다(python). 위 문장을 고쳤습니다.
- 초안의 판정 규칙은 "§470 에서 남아 있던 bss 사유"를 허용했습니다. 그런데 §470 사유는 kern_fork 가 `__TEXT,__text: fail`·`1 refs differ`, nfs_client 가 `__TEXT,__text: fail` 이고, bss 사유는 없습니다(survey 기록 python 출력). 그러니 둘 다 OBJECT_MATCH 를 요구합니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| bss 허용을 빼고 OBJECT_MATCH 를 요구할 것 | survey 기록의 `l1_reasons`(python) | ✅ 위 제 오류 |
| 명령 차이와 58 B 복사 서술이 맞음; 함수 끝은 배타 끝으로 적을 것 | 원본 목록을 직접 출력(0x4006700–0x400671e `rts`, 0x40262ac–0x4026302 `rts`); `0x3a` = 58 | ✅ 끝을 [시작, 끝) 으로 고침 |
| 다음 기호와의 거리만으로 C 객체 크기를 정할 수는 없음 | 설계 판단(`__common` 기호 크기는 간격으로만 추정) | ⚖️ "+4·+0 은 `struct _u_address` 의 `uthread`·`utask`" 해석은 SDK `user.h:353-356` 에 기댐; 크기 주장은 하지 않음 |
| 변형은 선언·매개변수 줄까지 바꾸므로 "516–517 행만"은 틀림 | `kern_fork.c:513-518`, `nfs_client.c:157-168` 을 읽음 | ✅ 범위를 함수 몸체 전체(513–518, 157–168)로 고침 |
| `u` 매크로를 쓸 수 있고 `u.uthread` 를 깨는 매크로가 없음 | 스테이징 `src/bsd/sys/user.h:350,358`, m68k `user.h` 는 비어 있음; kern_fork.c 가 이미 `u.u_uid` 등을 씀(121 행 등) | ✅ |
| U/C/R/P 는 단일 CPU 구성에서만 같은 뜻 | SDK m68k `cpu.h:65-74`(NCPUS ≤ 1 이면 `(0)`) | ✅ 이 구성에서 같은 뜻; 맞는 꼴이 나오면 보고에 적음 |
| E·M·B·D 를 되풀이하지 않음; E 는 `_active_u` COMMON 이 빠졌으므로 "같은 객체"는 과장 | §465.2 원문(“비 STABS 로 모두 같습니다 … E 는 `_active_u` COMMON 만 빠짐”) | ✅ 되풀이 없음 |
| §470 객체를 대조로 써도 됨, 단 K 재현 확인 유지 | 두 manifest 비교(python): 바뀐 헤더는 `src/machdep/m68k/eventc.h` 하나; 스테이징에서 `eventc.h` 를 가져오는 것은 `time_stamp.c`·두 `xpr.h` 뿐이고, `xpr.h` 를 가져오는 파일 목록에 두 대상 없음(grep) | ✅ |
| 도구는 관문을 보고만 하므로 명시해서 지킬 것 | `m5_m68k_srcvar.py:176`(`control_equals_ref` 는 기록만) | ✅ 아래 관문을 직접 확인 |
| 추가 꼴: nfs 매개변수 하나씩 `register`, 매개변수 선언 순서, cpu 를 선언과 대입으로 나눔 | 설계 | ✅ 아래 변형 추가(탐색용) |

계획 수정(실행 전 고정):
- `kern_fork` 변형 = K·U·C·C2·R·P·V. `C2` 는 `int cpu; cpu = cpu_number();` 로 선언과 대입을 나눈 꼴입니다.
- `nfs_client` 변형 = K·R·R1·R2·O·L·Q·S.
  - `R1`: `register struct vnode *vp;` 만
  - `R2`: `register struct vattr *va;` 만
  - `O`: 매개변수 선언 순서를 `struct vattr *va; struct vnode *vp;` 로
- 관문(직접 확인): 명령 모두 종료 0, 객체 모두 있음, K 가 `control_ref` 와 같음, 각 꼴의 L1 이 OBJECT_MATCH, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같음. 쓰기 순서와 nfs 검사 순서는 바꾸지 않습니다.

### 475.2 변형 시험 결과(2026-10-16)

- m68k run `m5p475-f1`(7 명령)·`m5p475-n1`(8 명령)은 모두 종료 0 입니다. 두 대조 K 는 §470 객체를 재현했습니다(`control_equals_ref: true`).
- **`kern_fork`**(기록 `09_validation/reconstruction/m5-m68k-kern-fork-variants-p475-20261016.json`):
  - **C·C2·R·P 는 OBJECT_MATCH** 입니다. 원본에 없는 미정의 0, COMMON·외부 정의는 K 와 같습니다. 네 객체는 비 STABS 로 서로 같습니다.
  - U·V 는 K 와 같습니다(사유 `__TEXT,__text: fail`·`1 refs differ`). `u` 매크로의 `active_u[(0)]` 와 `register` 매개변수는 주소 꼴을 바꾸지 않습니다.
  - 뜻: 첨자가 상수 0 이면 주소가 레지스터에 묶이고, 첨자를 변수(C·C2·R)나 포인터(P)로 거치면 절대 주소 두 번이 됩니다. 바이트로는 네 꼴을 가를 수 없습니다.
- x86(run `m5p475-xf1`, 바탕 s6l5; 기록 `m5-x86-kern-fork-variants-p475-20261016.json`): 7 명령 모두 종료 0 이고, K·U·C·C2·R·P·V 모두 x86 원본과 같습니다.
- **`nfs_client`**(기록 `m5-m68k-nfs-client-variants-p475-20261016.json`): R·R1·R2·O·L·Q·S 가 모두 K 와 같습니다(비 STABS). 맞는 꼴이 없습니다. 이 꼴들은 d0/d1 배정을 바꾸지 못합니다. 07 은 바꾸지 않습니다.
- 다음: 미리 정한 규칙대로 `kern_fork` 의 꼴(C·C2·R·P 중 하나)과 자리를 사용자에게 묻습니다.
- 사용자 결정 **D093**: `kern_fork` 의 꼴은 "R: register int cpu (Recommended)" 이고, 자리는 "07 본 파일 (Recommended)" 입니다.
  - 질문의 근거 문구 정정: 같은 판 07 m68k 의 지역 변수는 `ast.c:128` 이 `register int mycpu = cpu_number();`, `mach_clock.c:125` 가 `register int my_cpu = cpu_number();` 입니다. 질문에는 둘 다 `mycpu` 로 적었습니다.

### 475.3 D093 구현 계획(07 본 파일 `kern_fork.c` + x86 전체 재빌드 s6lc, 2026-10-16)

제 절차 오류(먼저 밝힘): 앞선 절들은 "구현 계획 → codex 검토 → 07 편집" 순서였습니다. 이번에는 이 절을 쓰기 전에 07 본 파일을 먼저 고쳤습니다(1 단계). 고치기 전 파일은 scratchpad 에 사본으로 두었고, 아래 2 단계부터는 이 계획과 검토를 거친 뒤 진행합니다.

§474.3 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p475-f1/out/P475__R.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집(이미 함): `bsd/kern/kern_fork.c` `switch_unix_context` 를 R 꼴로 바꾸고 `/* plan 475 (D093): … */` 를 붙였습니다. 522 → 524 행이고, 주석을 뺀 토큰이 변형 R 과 같습니다(python). 고치기 전 파일을 `08_build/artifacts/m5p475/kern_fork.c.main.before` 로 옮겨 둡니다.
2. x86 전체 재빌드 s6lc(접두어 길이 4, 미사용 — `ls 08_build/runs/tools` 에 `s6lc` 0 개)와 check 관문을 거칩니다.
3. prefixdiff s6lb↔s6lc(plan 475):
   - 스테이징 차이는 `src/bsd/kern/kern_fork.c` 하나여야 하고, `stage_keys_differ`·`cmd_differ` 는 `[]` 여야 합니다.
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-kern_fork']`, `differing_non_stabs_equal` 은 true 여야 합니다.
4. 링크 `s6p475-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`: `X86[475] = 's6lc'`, `EXCEPTS[475] = EXCEPTS[474]` 에 `x86-kern_fork` 사유를 더하고, `--plan` 문서를 고칩니다. `--plan 475 stage m0p475-a1-stage` → x86gate(s6lc) → `m0p474-a1-stage` 와의 차이는 `src/bsd/kern/kern_fork.c` 하나여야 합니다.
6. final(`m5_m68k_final.py`, plan 475): `kern_fork` 의 기대 사유는 `[]`(OBJECT_MATCH)입니다. bss 객체가 없으므로 `bss_records` 는 비우고 zerofill 은 돌지 않습니다.
7. 기록:
   - PROVENANCE 의 `kern_fork.c` 행을 그 자리에서 갱신합니다(행 수 같음, 중복 0).
   - MODIFICATIONS·DECISIONS D093·diff(`06_reconstruction/evidence/x86-kern_fork-plan475.diff`)·evidence 를 적습니다.
   - 집계: m68k OBJECT_MATCH 174 → 175, 코드 차이가 남은 객체 11 → 10 입니다.

### 475.4 교차검토(codex `gpt-6.1-sol`) 판정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 현재 07 은 주석을 빼면 "고치기 전 + R 치환"과 같음; 표시 꼴은 kalloc·igmp 와 같음 | python 토큰 비교(§475.3 1) | ✅ |
| 주석 "as the m68k original" 은 소스 꼴을 되찾았다는 뜻으로 읽힘(C·C2·R·P 는 바이트로 갈리지 않음) | §475.2 결과(네 꼴 비 STABS 같음) | ✅ 주석을 "an index variable gives the absolute stores of the m68k original" 로 고침 |
| x86 에서 `kern_fork.c` 를 쓰는 객체는 `x86-kern_fork` 하나 | 검토자 python(402 명령·의존 출력) | ⏭️ prefixdiff 의 스테이징·객체 차이로 판정 |
| `stage_m68k.py` 등록 자리: 9·12·21 행 문서, `X86`, `EXCEPTS[475]`(본 파일 변경도 예외 사유가 필요; 481 행에서 참조 객체와 비교) | 9·12·21·282·283·515 행과 476–484 행을 읽음 | ✅ |
| final 은 `reasons: []`·`bss_records: []` 로 동작, REF 해시가 변형 기록과 같음 | `m5_m68k_final.py:83-89` 읽음; python 해시 비교 `True` | ✅ final 명세는 따로 만듦 |
| `s6lc` 미사용, 길이 4 | `ls 08_build/runs/tools | grep -c '^s6lc'` → 0 | ✅ |
| prefixdiff 는 관문을 보고만 함 → 직접 assert | `l2_prefix_diff.py:86-92` 읽음 | ✅ 실행 때 python assert |
| PROVENANCE `kern_fork.c` 행은 546 행 하나 | grep -c 1, awk 546 행 | ✅ 그 자리 갱신 |

### 475.5 D093 구현 결과(2026-10-16) — 기록 `09_validation/reconstruction/m5-m68k-p475-final-20261016.json`

- 07 편집: 본 파일 `bsd/kern/kern_fork.c` 는 522 → 524 행입니다. 주석을 뺀 토큰이 변형 R 과 같습니다(python). 주석은 §475.4 대로 고쳤습니다.
- x86 전체 재빌드 s6lc:
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6lb↔s6lc(python assert 통과): 스테이징 차이는 `src/bsd/kern/kern_fork.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `['x86-kern_fork']`(STABS 만, 비 STABS 같음)입니다.
  - 링크 `s6p475-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다(공통 기호 417 / 417 같음).
- m68k:
  - `stage_m68k.py` 에 `X86[475] = 's6lc'`·`EXCEPTS[475]`(`x86-kern_fork`)를 등록했습니다(531 → 532 행).
  - `--plan 475 stage m0p475-a1-stage` 와 x86gate(s6lc 일곱)가 모두 같고, `m0p474-a1-stage` 와의 차이는 `kern_fork.c` 하나입니다(python assert).
  - final run `m5p475-a1`: **`x86-kern_fork` OBJECT_MATCH**, REF(`P475__R.o`)와 canon·머리·절·기호가 같고, 원본에 없는 미정의는 0 입니다. bss 객체가 없어 zerofill 은 돌지 않았습니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 175(+ 명시 배치 `ufs_alloc` 1), "코드 검증 + bss 추정" 은 22 입니다. 공통부 208 중 198(95.2%)이 코드 검증되었습니다.
  - 코드 차이가 남은 객체는 10 개입니다(netif, miniMon, nfs_client, ufs_subr, ipc_mig, tty, callout, kdp_udp, mach_net, swapfs).
- 기록: PROVENANCE 546 행 그 자리 갱신(1099 행, 중복 0), MODIFICATIONS 636 행, DECISIONS D093(97 행), diff `06_reconstruction/evidence/x86-kern_fork-plan475.diff`, `x86-kern_fork.md`.
- `nfs_client` 는 §475.2 대로 맞는 꼴이 없어 그대로입니다. 다음 가설이 생기면 따로 계획합니다.

## 476. M5-33 세부 계획 — m68k `ipc_mig` `msg_rpc` 의 레지스터 배정(`map` 이 a5 에 있는가)(07 변경 없음; 코딩 전, 2026-10-17)

§470.2 순위 6 위(점수 18, 크기 차 +6, R 묶음 8 개)입니다.

확인한 사실(§470 객체 목록 `08_build/artifacts/m5p470/otool/O470__…ipc_mig.txt` 와 원본 목록 [0x4048e24, 0x4049184)를 명령 단위로 나란히 놓음; 07·Darwin 0.1 을 읽음):
- 원본은 `linkw a6,#-8`, 우리는 `linkw a6,#-12` 입니다. 둘 다 d2–d7·a2–a5 를 저장합니다.
- 원본은 `current_map()`(`active_threads[0]->task->map`, task+8)을 a5 에 둡니다(0x4048e4a `movel a0@(0x8),a5`). 우리는 스택 a6@(-12)에 둡니다. 그 뒤 `ipc_kmsg_copyin_compat`·`ipc_kmsg_copyout_compat` 의 인자 자리(0x4048e96, 0x4049146)도 같은 차이입니다.
- 그 밖의 차이는 임시 레지스터 이름뿐입니다.
  - 커널 서버 분기의 `mqueue = &reply->ip_messages`: 원본 a2, 우리 a1(0x4048f38, 0x4048f42)
  - receive_reply 의 `ip_release(reply)` 임시: 원본 a1, 우리 a5(0x404902a–0x404902e)
  - receive_reply 의 `mqueue`: 원본 a0, 우리 a1(0x404909a, 0x40490c4)
- 원본에서 두 `mqueue` 자리의 레지스터가 다릅니다(a2, a0). 우리는 둘 다 a1 입니다.
- 07 `kern/ipc_mig.c:508-692` `msg_rpc` 는 plan 265 의 작성이고, Darwin 0.1 `kern/ipc_mig.c:322-557` 을 구조 참고로 했습니다(PROVENANCE 626 행).
- 함수 몸체에서 07 과 Darwin 0.1 이 다른 곳(python `difflib`):
  - 07 에는 Darwin 의 `assert` 줄들이 없습니다. 이 구성에서 `MACH_ASSERT` 는 0(`generated/mach_assert.h:1`)이고 `assert(e)` 는 빈 매크로(스테이징 `src/kern/assert.h:65,71`)이므로 코드에 영향이 없습니다.
  - **Darwin 은 커널 서버 분기(`if (dest->ip_receiver == ipc_space_kernel) {`) 안에 `ipc_mqueue_t mqueue;` 를 따로 선언합니다**(함수 머리의 `mqueue` 를 가림). 07 은 함수 머리의 `mqueue` 하나만 씁니다.
  - **Darwin 은 `MACH_RCV_TOO_LARGE` 분기에서 블록 지역 변수 `msg_size_t real_size` 를 거쳐 `msg->msg_size` 에 넣습니다.** 07 은 바로 넣습니다.
  - `ipc_kmsg_get_from_kernel` 의 `MACH_MSG_OPTION_NONE` 인자, `ipc_mqueue_receive` 의 `MACH_RCV_OLD_FORMAT`·끝 인자 `0` 은 Darwin 에만 있습니다. 원본은 07 과 인자 수가 같으므로(원본 목록 0x4048e6a–0x4048e74 네 인자, 0x404909e–0x40490c6 여덟 인자) 그대로 둡니다.
  - Darwin 은 `(!ip_active(reply))`·`(rcv_size < (… + …))` 에 괄호를 더 두고 `SEND_NOTIFY` 쪽을 `{ }` 로 감쌉니다(Darwin `:393`, `:396`, `:434`). 뜻은 같습니다. 나머지는 공백·줄바꿈·주석입니다.

가설(근거 약함): 원본 소스는 Darwin 처럼 커널 서버 분기 안에서 `mqueue` 를 따로 선언했습니다. 선언 하나가 의사 레지스터 하나의 긴 생존 구간을 뜻하지는 않으므로, 이것은 시험으로만 가립니다. `real_size` 블록도 함께 시험합니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p475-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__…ipc_mig.o`, run `m5p476-g1`; 명세는 무시 대상 `08_build/artifacts/m5p476/spec-ipc_mig.json`; `msg_rpc` 몸체만 바꿉니다):
- `B`: 커널 서버 분기의 `{` 바로 뒤에 `ipc_mqueue_t mqueue;` 와 빈 줄을 둡니다(함수 머리의 선언은 그대로).
- `D`: `} else if (mr == MACH_RCV_TOO_LARGE)` 분기를 `{ msg_size_t real_size = (msg_size_t) (mach_msg_size_t) kmsg; msg->msg_size = real_size; }` 로 바꿉니다.
- `BD`: B + D
- 판정(L1 `--place-from-image`):
  - §470 의 사유를 확인해 적습니다. 맞는 꼴은 OBJECT_MATCH(§470 에 bss·data 사유가 있으면 그 사유만 남음)여야 합니다.
  - 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
  - 관문(직접 확인): 명령 모두 종료 0, 객체 모두 있음, K 가 `control_ref` 와 같음.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; `ipc_mig.c` 가 s6l5 뒤 그대로인지 stage 가 assert): 모든 꼴이 x86 원본과 같은지 봅니다. 다르면 자리는 m68k 덮어쓰기 쪽이 됩니다.
- 고르기(미리 정함):
  - 대조 K 가 §470 객체를 재현하지 못하면 멈춥니다.
  - 맞는 꼴이 하나이면 그 꼴과 자리를 사용자에게 묻습니다. 여럿이어도 묻습니다.
  - 없으면 기록만 하고, 남은 차이 모양을 다음 가설에 씁니다.
- 구현·final 은 §475 와 같습니다.

### 476.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- 차이 목록에서 끝의 `moveml` 복원 변위(원본 `a6@(-48)`, 우리 `a6@(-52)`)를 빠뜨렸습니다. 제 나란히 목록 267 행에 있었는데 표시가 없었습니다. 프레임 크기 차(4 B)의 결과입니다.
- "나머지는 공백·줄바꿈·주석"은 틀렸습니다. Darwin 에는 뜻이 같은 괄호 두 곳과 `{ }` 한 곳이 더 있습니다. 위 문장을 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 레지스터 차이 서술은 맞고, 복원 변위 차이가 빠짐; 다른 함수·자료는 같음 | 나란히 목록 267 행; survey 기록 `spans_unequal = ['_msg_rpc']`(python) | ✅ 위 제 오류 |
| §470 L1 사유: 자동 배치 `__TEXT,__text: unverified`(크기 차 6 B) | survey 기록 python 출력 | ✅ 판정은 OBJECT_MATCH 만 받음(bss·data 예외 없음) |
| Darwin 에 괄호·`{ }` 가 더 있음(393·396·434) | Darwin 393·396·434 행, 07 560·595 행을 읽음 | ✅ 위 제 오류; 탐색 변형 P 추가 |
| B·D·BD 는 C89 로 맞고 뜻이 같음; `assert` 는 비어 있음(ipc_kmsg.h 를 거쳐 들어옴) | 07 551·570·653·675 행 쓰임새; assert.h 65·71 행 | ✅ |
| 머리 선언 순서는 이미 Darwin 과 같음 | 07 515–524 행과 Darwin 329–338 행을 읽음 | ✅ 순서 변형은 넣지 않음 |
| 탐색 변형: `register` 를 `map` 에, 안쪽 `mqueue` 에; `kmsg`·`seqno` 는 주소를 쓰므로 `register` 불가 | 07 534·664 행(`&kmsg`, `&seqno`) | ✅ M·BR 추가; `map` 선언·대입 나누기는 평가 순서(space → map → `msg->msg_size`)가 바뀌므로 넣지 않음 |
| "의사 레지스터 하나의 긴 생존 구간" 설명은 근거가 약함 | 설계 판단 | ✅ 가설 문장을 약하게 고침 |
| x86 K 가 s6l5 참조를 재현해야 함; `ipc_mig.c` 는 s6l5 뒤 그대로 | `m5_x86_srcvar.py` stage assert·compare 의 `control_equals_ref` | ✅ 관문으로 확인 |

계획 수정(실행 전 고정): 변형 = K·B·D·BD·P·BDP·M·BR.
- `P`(탐색): Darwin 의 괄호 두 곳과 `SEND_NOTIFY` 의 `{ }` 만
- `BDP`: B + D + P
- `M`(탐색): `register vm_map_t map = current_map();`
- `BR`(탐색): B 의 안쪽 선언을 `register ipc_mqueue_t mqueue;` 로

### 476.2 변형 시험 결과(2026-10-17)

- m68k run `m5p476-g1`·x86 run `m5p476-xg1`(각 8 명령)은 모두 종료 0 입니다. 두 대조 K 는 각 참조(§470 객체, s6l5 객체)를 재현했습니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-ipc-mig-variants-p476-20261017.json`):
  - **B·BD·BDP·BR 는 OBJECT_MATCH** 입니다. 원본에 없는 미정의 0, COMMON·외부 정의는 K 와 같습니다. 네 객체는 비 STABS 로 서로 같습니다.
  - D·P·M 은 K 와 같습니다(사유 `__TEXT,__text: unverified`). `real_size` 블록, 괄호·`{ }`, `register map` 은 코드를 바꾸지 않습니다.
  - 뜻: 원인은 커널 서버 분기 안의 `mqueue` 선언 하나입니다(가설 확인). 바이트로는 B·BD·BDP·BR 을 가를 수 없습니다.
- **x86**(기록 `m5-x86-ipc-mig-variants-p476-20261017.json`): 여덟 꼴 모두 x86 원본과 같습니다.
- 출처: B 의 줄 `ipc_mqueue_t mqueue;` 는 Darwin 0.1 `kern/ipc_mig.c` 의 같은 자리 선언과 글자가 같습니다. 07 본 파일에 넣으면 D061 선례대로 `(Darwin)` 표시와 APSL 고지가 필요합니다.
- 다음: 미리 정한 규칙대로 꼴과 자리를 사용자에게 묻습니다.
- 사용자 결정 **D094**: `ipc_mig` 의 꼴은 "B: 안쪽 mqueue 선언만 (Recommended)" 이고, 자리는 "07 본 파일 (Recommended)" 입니다. D061 선례대로 `(Darwin)` 표시와 APSL 고지를 붙입니다.

### 476.3 D094 구현 계획(07 본 파일 `ipc_mig.c` + x86 전체 재빌드 s6ld; 코딩 전, 2026-10-17)

§475.3 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p476-g1/out/P476__B.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집(`kern/ipc_mig.c`; 고치기 전 파일을 `08_build/artifacts/m5p476/ipc_mig.c.main.before` 로 먼저 옮겨 둠):
   - 커널 서버 분기의 `{` 바로 뒤에 Darwin 0.1 `kern/ipc_mig.c:382` 와 같은 글 `\t\t\tipc_mqueue_t\tmqueue;` 와 빈 줄을 둡니다. 줄 끝에 `/* plan 476 (D094; Darwin): … */` 표시를 붙입니다.
   - 파일 머리의 CMU 고지(1–25 행) 뒤에 kern_fork.c(D061)와 같은 꼴로 "plan 476 (Darwin) 으로 표시한 줄은 Darwin 0.1 kernel/kern/ipc_mig.c:382 와 같다"는 설명과 Darwin 0.1 파일의 APSL 고지(그 파일 1–23 행과 같은 글)를 둡니다.
   - python 으로 주석을 뺀 토큰이 변형 B 와 같은지 확인합니다.
2. x86 전체 재빌드 s6ld(접두어 길이 4, 미사용 — `ls 08_build/runs/tools` 에 `s6ld` 0 개)와 check 관문을 거칩니다.
3. prefixdiff s6lc↔s6ld(plan 476, python assert):
   - 스테이징 차이는 `src/kern/ipc_mig.c` 하나, `stage_keys_differ`·`cmd_differ` 는 `[]`
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-ipc_mig']`, `differing_non_stabs_equal` 은 true
4. 링크 `s6p476-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`: `X86[476] = 's6ld'`, `EXCEPTS[476] = EXCEPTS[475]` 에 `x86-ipc_mig` 사유를 더하고 문서 줄 셋을 고칩니다. `--plan 476 stage m0p476-a1-stage` → x86gate(s6ld) → `m0p475-a1-stage` 와의 차이는 `src/kern/ipc_mig.c` 하나여야 합니다(python assert).
6. final(`m5_m68k_final.py`, plan 476, 명세는 따로): `ipc_mig` 의 기대 사유는 `[]`, `bss_records` 는 `[]` 입니다.
7. 기록:
   - PROVENANCE 626 행(`07_kernel/src/kern/ipc_mig.c`)을 그 자리에서 갱신합니다. 고지 칸에 "plan 476 (Darwin) 줄: Apple APSL 1.0(파일 안 고지; `07_kernel/LICENSES/APSL-1.0.txt`)"를 더합니다(행 수 같음, 중복 0).
   - MODIFICATIONS·DECISIONS D094·diff(`06_reconstruction/evidence/x86-ipc_mig-plan476.diff`)·`x86-ipc_mig.md` 를 적습니다.
   - 집계: m68k OBJECT_MATCH 175 → 176, 코드 차이가 남은 객체 10 → 9 입니다.

### 476.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 탭 간격(`ipc_mqueue_t\tmqueue;`)은 토큰이 B 와 같음; 주석은 STABS 만 바꿈 | Darwin 382 행과 명세의 B 글을 읽음 | ✅ 토큰 비교는 구현 때 python 으로 다시 함 |
| 머리 주석으로 줄 번호가 밀려도 관문(비 STABS 비교, 링크의 `strip -x`)은 그대로 | §475.5 링크 기록에서 원본·재빌드 모두 STABS 0 이고 `cmp` 같음; D061 때 같은 방법으로 통과 | ✅ 재빌드·링크로 다시 확인 |
| 설명 문구는 D061 꼴(`Parts marked "plan NNN (Darwin)" follow Darwin 0.1 kernel/<path> (kernel-1), whose notice is:`)을 따를 것 | `plans/RECONSTRUCTION_PLAN-374-408.md:955` 의 규칙 1 을 읽음 | ✅ 표시는 `plan 476 (Darwin)` 으로 |
| PROVENANCE 는 고지 칸만이 아니라 source_id(`mach4+darwin01`)·개정(kernel-1 압축 파일 SHA)·원본 경로(`darwin01/kernel/kern/ipc_mig.c:382`)도 고칠 것 | 같은 규칙 3; kern_fork 행(546)의 칸 꼴 | ✅ 계획에 더함 |
| final 명세 칸(name·object·rel·ref·ref_sha256·reasons·bss_records) | `m5_m68k_final.py:32-38` | ✅ |
| `s6ld` 미사용, 길이 4 | `ls 08_build/runs/tools | grep -c '^s6ld'` → 0 | ✅ |
| `functions.tsv` 의 `ipc_mig.c` 줄 인용을 다시 맞추고, `_msg_rpc` 행의 "Darwin … structure only" 를 고칠 것 | `functions.tsv:2073` 을 읽음; 같은 규칙 2 | ✅ 계획에 더함 |
| PROVENANCE 626 행이 하나 | awk 626 행 | ✅ |

계획 수정(실행 전 고정):
- 1 단계의 표시는 `/* plan 476 (Darwin): D094; … */`, 머리 설명은 D061 꼴 문구입니다.
- 7 단계에 더합니다:
  - PROVENANCE 626 행: source_id `mach4` → `mach4+darwin01`, 개정 칸에 kernel-1 압축 파일 SHA-256, 원본 경로 칸에 `darwin01/kernel/kern/ipc_mig.c:382 (inner mqueue declaration of msg_rpc)`.
  - `06_reconstruction/functions.tsv`: `07_kernel/src/kern/ipc_mig.c:N` 인용을 모두 새 줄 번호로 옮깁니다(옛 줄과 새 줄의 내용이 같은지 python 으로 확인). `_msg_rpc` 행(x86-0x1589fc)의 "structure only" 를 "plan 476 (D094) 의 한 줄은 Darwin 0.1 과 같음" 으로 고칩니다. 행 수는 같아야 합니다.

### 476.5 D094 구현 결과(2026-10-17) — 기록 `09_validation/reconstruction/m5-m68k-p476-final-20261017.json`

- 07 편집: 본 파일 `kern/ipc_mig.c` 는 767 → 794 행입니다(머리 설명·APSL 고지 25 행, 선언·빈 줄 2 행; python). 주석을 뺀 토큰이 변형 B 와 같습니다(python).
- x86 전체 재빌드 s6ld:
  - 명령 804 개가 모두 종료 0 이고, check 일곱·402 행·problem 0 입니다.
  - prefixdiff s6lc↔s6ld(python assert 통과): 스테이징 차이는 `src/kern/ipc_mig.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `['x86-ipc_mig']`(STABS 만, 비 STABS 같음)입니다.
  - 링크 `s6p476-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다(공통 기호 417 / 417).
- m68k:
  - `stage_m68k.py` 에 `X86[476] = 's6ld'`·`EXCEPTS[476]`(`x86-ipc_mig`)를 등록했습니다(532 → 533 행).
  - `--plan 476 stage m0p476-a1-stage` 와 x86gate(s6ld 일곱)가 모두 같고, `m0p475-a1-stage` 와의 차이는 `ipc_mig.c` 하나입니다(python assert).
  - final run `m5p476-a1`: **`x86-ipc_mig` OBJECT_MATCH**, REF(`P476__B.o`)와 canon·머리·절·기호가 같고, 원본에 없는 미정의는 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 176(+ 명시 배치 `ufs_alloc` 1), "코드 검증 + bss 추정" 은 22 입니다. 공통부 208 중 199(95.7%)가 코드 검증되었습니다.
  - 코드 차이가 남은 객체는 9 개입니다(netif, miniMon, nfs_client, ufs_subr, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 626 행 그 자리 갱신(source_id `mach4+darwin01`, kernel-1 SHA, Darwin 경로, APSL 고지 칸; 1099 행, 중복 0)
  - MODIFICATIONS 637 행, DECISIONS D094(98 행), diff `06_reconstruction/evidence/x86-ipc_mig-plan476.diff`, `x86-ipc_mig.md`
  - `06_reconstruction/functions.tsv` 의 `ipc_mig.c` 줄 인용 6 개를 +25 행 옮김(옛·새 줄 내용 같음 assert; 4763 행 그대로), `_msg_rpc` 행의 출처 문구를 고침

## 477. M5-34 세부 계획 — m68k `nfs_client` `nfs_attrcache_va` 의 반환형(`void`)(07 변경 없음; 코딩 전, 2026-10-17)

§475 에서 `register`·지역 변수·조건 나누기 일곱 꼴로는 풀리지 않았습니다. 이번에는 같은 객체 안의 이웃 함수와 비교해 가설을 세웁니다.

확인한 사실(원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, 기호표, 07·NeXTMach 를 직접 읽음):
- 원본 `_nfs_attrcache`([0x4026266, 0x40262ac))는 `&vtor(vp)->r_attr` 를 `moveq #124,d1; addl a2@(0x2e),d1; movel d1,sp@-` 로 **d1** 에 계산합니다(0x4026288–0x402628e). 이 함수는 §470 에서 이미 원본과 같습니다.
- 원본 `_nfs_attrcache_va`([0x40262ac, 0x4026304))는 같은 식을 **d0** 에 계산합니다(0x40262d8–0x40262de). 우리 객체는 d1 입니다.
- 07 `bsd/nfs/nfs_client.c` 의 두 함수는 모두 반환형을 적지 않은 K&R 함수(암묵 `int`)이고, 값 없는 `return;` 은 앞쪽의 이른 빠져나가기이며 끝은 그냥 떨어집니다(142–152 행, 157–168 행). NeXTMach `nfs/nfs_client.c:147` 도 같습니다.
- 07·SDK·NeXTMach 어디에도 `nfs_attrcache_va` 의 원형 선언은 없습니다(grep). 부르는 곳은 07 `nfs_client.c:342`, `nfs_vnodeops.c:238` 이고(`:1930` 은 `#else NeXT` 쪽이라 빠짐), 모두 반환값을 쓰지 않습니다.
- 원본 전체에서 `moveq #imm,dN; addl …,dN; movel dN,sp@-`(N = 0, 1) 꼴을 python 으로 찾으면 35 함수입니다. d0 을 쓰는 것은 `_nfs_attrcache_va` 하나이고, 34 함수는 d1 입니다. 그 가운데 07 에서 `void` 인 `_exception_raise_continue`(0x4047db0)도 d1 이므로, "`void` 이면 d0" 은 일반 규칙이 아닙니다(반증 자료).

가설(근거: 위의 두 함수 비교; GCC 2.7 내부 동작은 이 저장소에서 확인하지 않은 제 이해이므로 시험으로만 가립니다):
- 원본 `nfs_attrcache_va` 는 `void` 로 선언되었습니다. `int` 함수에서는 반환값 자리(d0)가 배정에 걸려 임시 값이 d1 로 가고, `void` 함수에서는 d0 이 비어 그대로 쓰인다는 해석입니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p476-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_142__nfs_client.o`, run `m5p477-n1`; 명세는 무시 대상 `08_build/artifacts/m5p477/spec-nfs_client.json`):
- `V`: `nfs_attrcache_va(vp, va)` 앞 줄에 `void` 를 둡니다(K&R 꼴: 반환형을 따로 한 줄).
- `W`(탐색): V 와 함께 `nfs_attrcache` 에도 `void` 를 둡니다. `nfs_attrcache` 는 지금 원본과 같으므로, 이 꼴이 `nfs_attrcache` 를 깨면 가설의 방향이 맞다는 반증 검사가 됩니다.
- 판정(L1 `--place-from-image`): §470 사유는 `__TEXT,__text: fail` 하나이므로, 맞는 꼴은 OBJECT_MATCH 여야 합니다. 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다. 관문(명령 종료 0, 객체 있음, K 가 `control_ref` 와 같음)은 직접 확인합니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; stage 가 `nfs_client.c` 가 그대로인지 assert): V 가 x86 원본과 같은지 봅니다.
- 고르기(미리 정함):
  - V 만 OBJECT_MATCH 이면, 맞는 꼴이 하나이므로 그대로 씁니다. 자리(07 본 파일 / m68k 덮어쓰기)는 x86 결과와 함께 사용자에게 묻습니다.
  - 맞는 꼴이 없으면 기록만 합니다.
- 구현·final 은 §475·§476 과 같습니다(x86 재빌드 접두어는 `s6le`).

### 477.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- "값 없는 `return;` 으로 끝납니다" 는 틀렸습니다. `return;` 은 앞쪽의 이른 빠져나가기이고, 함수 끝은 그냥 떨어집니다. 위 문장을 고쳤습니다.
- 부르는 곳에 `nfs_vnodeops.c:1930` 을 넣었는데, 그 줄은 `#else NeXT` 쪽(1927–1932 행)이라 컴파일되지 않습니다. 위 문장을 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 주소·레지스터·줄 범위는 맞음 | 원본 목록 출력(0x4026288 d1, 0x40262d8 d0), 07 142·157 행 | ✅ |
| `return;` 은 이른 빠져나가기, 끝은 떨어짐 | 07 142–152·157–168 행 | ✅ 위 제 오류 |
| `nfs_vnodeops.c:1930` 은 `NeXT` 에서 빠짐 | 1926 `#if NeXT`, 1927 `#else`, 1932 `#endif` | ✅ 위 제 오류 |
| 기제(d0 예약)는 추측; 반증 자료가 섞여 있음 — 암묵 `int` `vattr_to_sattr` 가 d0, `void` `nfs_netboot_prealloc` 가 d0, 암묵 `int` `setdiropargs` 가 d1 | `nfs_subr.c:633`(반환형 없음)·`:393-394`(`void`)를 읽음, 원본 목록 0x4028e04 `movew …,d0`, 0x40289da `movel …,d0` | ✅ 가설은 시험으로만 가림; V 가 맞아도 "원본이 `void` 였다" 의 증명은 아니고 "바이트로 맞는 재구성 꼴" 로 적음 |
| 같은 파일 342 행의 호출은 정의를 보므로 바뀔 수 있음 → 객체 전체 비교가 잡음; `nfs_vnodeops` 는 따로 컴파일되어 영향 없음 | 계획의 비교 단위가 객체 전체임(`m5_m68k_srcvar.py` compare) | ✅ |
| `nfs_vnodeops.c` 의 암묵 `int` 와 `void` 정의는 C 형이 맞지 않음(결과는 쓰지 않음) | 설계 판단 | ⚖️ 이 저장소 C89 기준선과 원본 바이트 쪽 문제는 아님; 맞는 꼴이 나오면 사용자 보고에 적음 |
| W 는 대조 꼴로 쓸모 있음; V·W 둘 다 맞음, W 만 맞음의 처리를 미리 정할 것 | 설계 | ✅ 아래에 더함 |
| x86 확인에 K 를 넣고 `control_equals_ref` 를 볼 것 | `m5_x86_srcvar.py` 는 명세의 K 를 함께 컴파일 | ✅ |

계획 수정(실행 전 고정): 변형 = K·V·W.
- 고르기:
  - V 만 맞음: 맞는 꼴이 하나 → 그 꼴로 정하고, 자리를 묻습니다.
  - V·W 둘 다 맞음: 바이트로 가를 수 없음 → 꼴과 자리를 묻습니다.
  - W 만 맞음: `nfs_attrcache` 도 `void` 여야 한다는 뜻 → 맞는 꼴이 하나이므로 그 꼴로 정하고, 자리를 묻습니다.
  - 아무것도 맞지 않음: 기록만 합니다. W 에서 `nfs_attrcache` 가 바뀌었는지는 함수별로 적습니다.

### 477.2 변형 시험 결과(2026-10-17)

- m68k run `m5p477-n1`·x86 run `m5p477-xn1`(각 3 명령)은 모두 종료 0 입니다. 두 대조 K 는 각 참조(§470 객체, s6l5 객체)를 재현했습니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-nfs-client-variants-p477-20261017.json`): **V·W 는 K 와 같습니다**(비 STABS; 사유 `__TEXT,__text: fail`, 다른 구간은 `_nfs_attrcache_va` 하나). 맞는 꼴이 없습니다.
  - W 에서 `nfs_attrcache` 도 바뀌지 않았습니다. 이 컴파일러에서 반환형(`int`/`void`)은 두 함수의 레지스터 배정을 바꾸지 않습니다. 가설은 반증되었습니다.
- x86(기록 `m5-x86-nfs-client-variants-p477-20261017.json`): K·V·W 모두 x86 원본과 같습니다.
- 07 은 바꾸지 않습니다. `nfs_client` 는 §465·§475·§477 세 차례 시험한 꼴(명시 `bcopy`, 앞선 선언, `register`, 지역 변수, 조건 나누기, 매개변수 순서, 반환형)로 풀리지 않았습니다. 남은 차이는 레지스터 하나(d0/d1)이고, 새 근거가 생기기 전에는 다시 시험하지 않습니다.

## 478. M5-35 세부 계획 — m68k `ufs_subr` `bufstats` 의 `counts` 크기(상수 대 가변 길이 배열)(07 변경 없음; 코딩 전, 2026-10-23)

§470 순위 9 입니다. 다른 구간은 `_bufstats` 하나이고, 나머지 11 함수는 재배치 자리를 가리면 같습니다.

확인한 사실(§470 기록, 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, 기호표, 스테이징 머리, 07·NeXTMach 를 직접 읽음):
- 객체 텍스트 1860 B, 원본 범위 1806 B 로 +54 B 이고, `_bufstats` 가 객체 286 B·원본 232 B 로 그 54 B 전부입니다(python).
- 원본 `_bufstats`([0x40393e8, 0x40394d0)):
  - `linkw a6,#0xfff8` 로 8 B 고정 프레임을 잡고, `moveml d2/d3/d4/a2` 를 저장합니다.
  - `counts` 는 `a6@(0xfffffff8:b,dN:l:4)` 로 씁니다.
  - 고리 상한은 `_m68k_page_size`(0x40b6538)를 레지스터(첫 고리 d3, 셋째 고리 d1)에 읽은 뒤 `movel #0x2000,d0; divsl d3,d0` 처럼 그 레지스터로 나눠 계산합니다(0x4039406–0x403941a, 0x4039494–0x40394a0).
- 우리 객체:
  - `pea a6@; movel sp,a6; moveml d2/d3/d4/a2/a3/a4` 뒤 `movel #0x2000,d0; divsl _m68k_page_size,d0; addql #1,d0; asll #2,d0; subal d0,sp; movel sp,a4` 로 `counts` 를 실행 중 크기로 잡습니다(GNU 가변 길이 배열).
  - 나머지 차이(레지스터 a3/a2·d3/d2, 고리 머리 꼴)는 이 배열이 a4 를 쓰는 데서 따라 나온 것으로 봅니다(가설; 시험으로 가립니다).
- 07 `bsd/ufs/ufs_subr.c:416` 은 `int counts[MAXBSIZE/CLBYTES+1];` 입니다. 계획 207 에서 x86 원본이 이 꼴(`div [page_size]`, `sub esp, eax`; 0x142e55–0x142e69)임을 확인해 넣은 줄입니다.
- NeXTMach mk-108.1 `ufs/ufs_subr.c:406–410`:
  - `#if NeXT` 쪽은 `int counts[MAXBSIZE/NeXT_MIN_CLBYTES+1];	/* must be constant */` 입니다.
  - `#else NeXT` 쪽은 07 과 같은 `CLBYTES` 꼴입니다.
- m68k 스테이징 머리(`08_build/runs/tools/m0p476-a1-stage/src`):
  - `bsd/m68k/machparam.h:21` 은 커널에서 `NBPG` 를 `m68k_page_size` 로 둡니다. 그래서 `CLBYTES`(`bsd/sys/param.h:169`, `CLSIZE*NBPG`)는 변수가 됩니다.
  - `bsd/m68k/machparam.h:30` 은 `M68K_MIN_CLBYTES` 를 `(CLSIZE * M68K_MIN_PAGE_SIZE)` 로 정의합니다. `mach/m68k/vm_param.h:64` 의 `M68K_MIN_PAGE_SIZE` 는 8192 입니다.
  - `CLSIZE` 는 1 입니다(`bsd/m68k/machparam.h:28`).
  - `MAXBSIZE` 는 8192 입니다(`bsd/sys/param.h:215`). 따라서 `MAXBSIZE/M68K_MIN_CLBYTES+1` = 2, `counts` = 8 B 로 원본 프레임과 같습니다(python).
- i386 쪽 스테이징 머리(m68k 스테이징의 `bsd/i386/machparam.h`·`mach/i386/vm_param.h`, x86 s6l5 스테이징 전체)에는 `MIN_CLBYTES` 가 없습니다(grep 0 건).
- 07 `ufs_subr.c` 는 m68k 스테이징 `m0p476-a1-stage`, x86 스테이징 `s6l5-g1a-stage` 의 사본과 SHA-256 이 같습니다.

가설:
- m68k 원본은 `counts` 를 상수 크기 2 로 선언했습니다. NeXTMach `#if NeXT` 꼴의 매크로가 OPENSTEP m68k 머리에서는 `M68K_MIN_CLBYTES` 라는 이름이라는 해석입니다. 그러나 매크로 이름은 원본 바이트로 정해지지 않습니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p476-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_150__ufs_subr.o`, run `m5p478-u1`; 명세는 무시 대상 `08_build/artifacts/m5p478/spec-ufs_subr.json`):
- `M`: 416 행을 `int counts[MAXBSIZE/M68K_MIN_CLBYTES+1];	/* must be constant */` 로 바꿉니다(m68k 전용 꼴; x86 에서는 컴파일되지 않음).
- `C`: 416 행을 `int counts[2];` 로 바꿉니다(두 아키텍처 모두 컴파일됨).
- `MX`: 416 행을 `#if m68k` / M 줄 / `#else m68k` / 지금 줄 / `#endif m68k` 로 감쌉니다(07 본 파일 후보).
- 판정(L1 `--place-from-image`): 맞는 꼴은 OBJECT_MATCH 여야 합니다. 이 객체에는 `__bss` 가 없습니다(`__text`·`__data`·`__cstring` 뿐). 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다. 관문(명령 종료 0, 객체 있음, K 가 `control_ref` 와 같음)은 직접 확인합니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; 명세는 M 을 뺀 K·C·MX 의 별도 파일 `08_build/artifacts/m5p478/spec-ufs_subr-x86.json`):
  - MX 는 x86 원본(K)과 같아야 07 본 파일 후보가 됩니다.
  - C 는 x86 에서 달라질 것으로 예상합니다(고정 배열). 같으면 그 사실을 적습니다.
- 고르기(미리 정함):
  - M·C·MX 가 모두 OBJECT_MATCH 이면 바이트로 가를 수 없으므로, 꼴과 자리(07 본 파일의 `#if m68k` / m68k 덮어쓰기 파일)를 사용자에게 묻습니다.
  - 일부만 맞으면 맞는 꼴만 후보로 하고, 하나이면 그 꼴로 정한 뒤 자리를 묻습니다.
  - 아무것도 맞지 않으면 기록만 하고, 다른 함수별 결과를 적습니다.
- 구현:
  - 07 본 파일이면 x86 전체 재빌드(접두어 `s6le`)·링크 cmp 와 m68k final 을 거칩니다.
  - 덮어쓰기면 m68k final 만 거칩니다. 덮어쓰기 파일은 `07_kernel/v183.34/m68k/src/bsd/ufs/ufs_subr.c` 이고, 출처 기록(PROVENANCE·MODIFICATIONS)을 함께 둡니다.

### 478.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): 원본의 고리 상한을 "`divsl _m68k_page_size,d0`" 으로 적었습니다. 원본은 `_m68k_page_size` 를 d3(셋째 고리는 d1)에 읽은 뒤 그 레지스터로 나눕니다. 메모리 피연산자로 바로 나누는 것은 우리 객체의 가변 길이 배열 크기 계산(0x59c)입니다. 위 문장을 고쳤습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 1860/1806, 286/232, 차 54, 12 함수 중 11 같음 | python(§470 기록의 spans) | ✅ |
| 원본은 쪽 크기를 d3/d1 에 읽어 레지스터로 나눔 | `image.txt` 72330–72345·72380–72385 행(0x4039406 `movel 0x40b6538:l,d3`, 0x403941a `divsl d3,d0`, 0x40394a0 `divsl d1,d0`) | ✅ 위 제 오류 |
| 우리 객체의 가변 길이 배열 줄 | 객체 목록 506–514 행(0x59c `divsl 0x0:l,d0`, `addql`·`asll`) | ✅ |
| `CLSIZE` = 1 을 계산에 밝힐 것 | `bsd/m68k/machparam.h:28` | ✅ 위에 더함 |
| m68k `sizeof int` = 4 | `m0-abi-m68k-20261009.json` 1668–1674 행 | ✅ |
| `cc -arch m68k` 은 `m68k` 를 정의하고 i386 은 정의하지 않음 | `specs-m68k:38` 에 `-Dm68k`, `specs-i386:38` 에 `m68k` 0 건 | ✅ |
| `#else 이름` 꼬리 토큰은 이 컴파일러에서 통과함 | 같은 파일 447–448 행 `#ifdef sun`/`#else sun`(지금 컴파일되는 파일), 07 `kern/time_stamp.c:55` `#if m68k` | ✅ 꼴 유지 |
| K·C·MX 만 담은 x86 명세가 동작함 | `m5_m68k_srcvar.load` 는 대조만 요구, `m5_x86_srcvar` 는 명세의 변형을 돎 | ✅ |
| MX 는 STABS 줄 번호만 바꿀 수 있고, 판정은 STABS 를 빼며 링크는 `strip -x` | `l2_prefix_diff.obj_sig`(비 STABS 기호), `l2_link.py:130`(`strip -x`) | ✅ 최종 cmp 는 그대로 요구 |
| m68k `control_equals_ref` 는 canon 만 비교함 | `m5_m68k_srcvar.py:175` | ✅ K 와 `control_ref` 의 obj_sig 도 python 으로 직접 비교 |
| `__data` 24 B·지역 기호 `_bname.32` 도 판정 범위에 있어야 함 | python(객체 절·기호), canon 과 obj_sig 가 다룸 | ✅ 변형 비교와 final 이 이미 포함 |
| §470 L1 은 텍스트가 자리를 못 잡은 것(`unplaced`)이라 OBJECT_MATCH 가 가능함 | `l1-x86-ufs_subr.json`(`__TEXT,__text` placement `unplaced`, 사유 `unverified`) | ✅ 사유 `[]` 만 받음 |
| x86 K 성공을 요구하고, MX 가 x86 에서 실패할 때의 갈래를 정할 것 | 계획의 고르기 | ✅ 아래에 고정 |
| 고리 꼴(분기 위치·포인터 귀납)이 배열만으로 설명되지 않을 수 있음 → 진단 변형 CL(고리 꼴을 바꾼 꼴)을 미리 넣을 것 | 설계 판단 | ⚖️ 위험은 받아들임. 다만 고리 꼴 변형은 첫 회 결과가 남은 차이를 보여 줄 때 근거를 두고 세웁니다. 첫 회에 맞으면 필요 없습니다 |

계획 수정(실행 전 고정): 변형 = K·M·C·MX(m68k), K·C·MX(x86).
- 관문: 모든 명령 종료 0, 객체 있음, m68k K 가 `control_ref` 와 canon·obj_sig 모두 같음, x86 K 가 s6l5 객체와 같음(`control_equals_ref`).
- 맞는 꼴: m68k 사유 `[]`(OBJECT_MATCH), 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같음.
- 고르기:
  - MX 가 m68k 에서 맞고 x86 에서도 K 와 같으면, 07 본 파일(MX)과 m68k 덮어쓰기(M 또는 C) 모두 가능합니다. 맞는 꼴이 여럿이면 꼴과 자리를 묻습니다.
  - MX 가 x86 에서 다르면 07 본 파일 자리는 없습니다. m68k 에서 맞는 꼴(M·C)로 덮어쓰기를 하고, 맞는 꼴이 둘이면 꼴을 묻습니다.
  - 아무것도 맞지 않으면 기록만 하고, 남은 차이 묶음을 함수 안에서 다시 적어 다음 변형(고리 꼴)의 근거로 씁니다.

### 478.2 변형 시험 결과(2026-10-23)

- m68k run `m5p478-u1`(4 명령)·x86 run `m5p478-xu1`(3 명령)은 모두 종료 0 입니다.
- 관문:
  - m68k K 는 `control_ref`(§470 객체)와 canon·Mach-O 머리·절 머리·비 STABS 기호가 모두 같습니다(python).
  - x86 K 는 s6l5 객체와 같습니다(`control_equals_ref`).
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-ufs-subr-variants-p478-20261023.json`):
  - **M·C·MX 가 모두 OBJECT_MATCH(사유 `[]`)이고, 세 객체는 서로 같습니다**(같은 묶음). 원본에 없는 미정의는 0 이고, COMMON 은 K 와 같습니다.
  - `_bufstats` 는 232 B 로 원본과 같습니다. 원본 바이트로 꼴을 가를 수 없습니다.
  - 기록의 `_locc` 표시 `false` 는 원본 쪽 구간이 다음 기호 0x4039e24(객체 밖, 2274 B)까지 이어져서 생깁니다. 38 B 는 재배치를 가린 뒤 같습니다(`masked_equal_prefix`). §470.1 의 "마지막 원본 구간이 객체 경계를 넘음" 과 같은 현상입니다.
- **x86**(기록 `m5-x86-ufs-subr-variants-p478-20261023.json`):
  - MX 는 x86 원본(K)과 canon·머리·절·비 STABS 기호가 같습니다.
  - C 는 예상대로 다릅니다(고정 배열).
- 고르기(§478.1 규칙): MX 가 두 아키텍처에서 맞으므로 07 본 파일(MX)과 m68k 덮어쓰기(M 또는 C) 모두 가능합니다. 꼴과 자리를 사용자에게 묻습니다.

사용자 결정 D095(2026-10-23): 선택지 "MX: 07 본 파일 #if m68k (Recommended)".

### 478.3 D095 구현 계획(07 본 파일 `ufs_subr.c` + x86 전체 재빌드 s6le; 코딩 전, 2026-10-23)

§476.3 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p478-u1/out/P478__MX.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집(`bsd/ufs/ufs_subr.c`; 고치기 전 파일을 `08_build/artifacts/m5p478/ufs_subr.c.main.before` 로 먼저 옮겨 둠):
   - 416 행 `\tint counts[MAXBSIZE/CLBYTES+1];` 을 변형 MX 의 다섯 줄로 바꿉니다.
   - `#if\tm68k` 줄 끝에 `/* plan 478 (D095): constant size, as the m68k original */` 표시를 붙입니다. 415 행의 계획 207 주석은 그대로 둡니다(x86 쪽 설명).
   - M 줄은 NeXTMach `ufs/ufs_subr.c:407` 의 줄에서 매크로 이름만 `M68K_MIN_CLBYTES` 로 바꾼 것입니다. 파일은 이미 NeXTMach 출처(D013)이므로 새 고지는 필요 없습니다.
   - python 으로 주석을 뺀 토큰이 변형 MX 와 같은지 확인합니다. 파일은 489 → 493 행이 됩니다.
2. x86 전체 재빌드 s6le(접두어 길이 4, 미사용 — `ls 08_build/runs/tools` 에 `s6le` 0 개, `08_build/runs` 에 `s6le`·`s6p478` 0 개)와 check 관문을 거칩니다.
3. prefixdiff s6ld↔s6le(plan 478, python assert):
   - 스테이징 차이는 `src/bsd/ufs/ufs_subr.c` 하나, `stage_keys_differ`·`cmd_differ` 는 `[]`
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-ufs_subr']`, `differing_non_stabs_equal` 은 true
4. 링크 `s6p478-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`: `X86[478] = 's6le'`, `EXCEPTS[478] = EXCEPTS[476]` 에 `x86-ufs_subr` 사유를 더하고 문서 줄 셋을 고칩니다. `--plan 478 stage m0p478-a1-stage` → x86gate(s6le) → `m0p476-a1-stage` 와의 차이는 `src/bsd/ufs/ufs_subr.c` 하나여야 합니다(python assert).
6. final(`m5_m68k_final.py`, plan 478, 명세는 따로): `ufs_subr` 의 기대 사유는 `[]`, `bss_records` 는 `[]` 입니다.
7. 기록:
   - PROVENANCE 558 행(`07_kernel/src/bsd/ufs/ufs_subr.c`)을 그 자리에서 갱신합니다. changes 칸에 plan 478 (D095) 를 더하고 파일 SHA-256 을 새 값으로 바꿉니다(행 수 같음, 중복 0).
   - MODIFICATIONS·DECISIONS D095·diff(`06_reconstruction/evidence/x86-ufs_subr-plan478.diff`)·`x86-ufs_subr.md` 를 적습니다.
   - `06_reconstruction/functions.tsv`: 416 행 뒤의 "edited file" 인용 셋(`_scanc` :449, `_skpc` :465, `_locc` :477)을 +4 행 옮깁니다(옛·새 줄 내용 같음 assert; 4763 행 그대로). 앞쪽 인용(:100–:411)은 그대로입니다.
   - 집계: m68k OBJECT_MATCH 176 → 177, 코드 차이가 남은 객체 9 → 8 입니다.

### 478.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계 순서(REF → 07 → 재빌드·check → prefixdiff → 링크 → 등록·stage·x86gate → final → 기록)에 빠진 단계 없음 | §476.3 과 나란히 읽음 | ✅ |
| 재빌드 prepare·check 모두에 `L2_FORMS`·`L2_EXPECT` 를 주고 §469 의 통과 조건(problem 0, 행 1–402 연속, deps 경고 0, 모든 명령 종료 0)을 밝힐 것 | `plans/RECONSTRUCTION_PLAN-448-469.md` 1289–1290 행 | ✅ 아래에 고정 |
| 링크는 `l2_link.py prepare s6p478-ln1 s6le` → kr_run → `l2_compare.py` → `cmp` | 같은 파일 1295 행 | ✅ |
| `EXCEPTS[478] = dict(EXCEPTS[476], **{…})` 로 476 항목을 건드리지 않을 것 | `stage_m68k.py` 283–284 행의 기존 꼴 | ✅ 그 꼴로 씀 |
| 문서 줄은 9·12·21 행, stage 와 x86gate 모두 `--plan 478` | grep(9·12·21 행) | ✅ |
| manifest 비교는 파일 항목으로 할 것(머리 메타는 바뀜) | §476.5 와 같은 방법 | ✅ |
| final 명세 칸 | `m5_m68k_final.py` 34–37 행 | ✅ |
| `#if` 줄 끝 주석은 토큰을 바꾸지 않고, 같은 꼴의 선례가 있음 | `v183.34/m68k/src/vm/vm_pager.c:97`, 07 `kern_synch.c:388`·`ufs_dsort.c:55` | ✅ 토큰 비교는 구현에서 python 으로 다시 함 |
| 416 행 뒤의 07 줄 인용은 `functions.tsv` 1499–1501 행 셋뿐이고 449→453, 465→469, 477→481 | grep(06·07 전체), 07 449·465·477 행을 읽음 | ✅ `function_candidates.tsv` 는 NeXTMach 줄이라 그대로 |
| PROVENANCE 558 행이 맞고 하나뿐이며, 고지 칸은 그대로 | 558 행을 읽음 | ✅ |
| 집계 176→177, 9→8 은 §476.5 와 맞음(final 통과 조건부) | §476.5 1509–1511 행 | ✅ |
| `s6le`·`s6p478` 미사용 | `ls` 0 건 | ✅ |

### 478.5 D095 구현 결과(2026-10-23) — 기록 `09_validation/reconstruction/m5-m68k-p478-final-20261023.json`

- 07 편집: 본 파일 `bsd/ufs/ufs_subr.c` 는 489 → 493 행입니다. 주석을 뺀 토큰이 변형 MX 와 같습니다(python). 고치기 전 파일은 `08_build/artifacts/m5p478/ufs_subr.c.main.before` 입니다.
- x86 전체 재빌드 s6le:
  - 명령 804 개가 모두 종료 0 이고, check 일곱의 402 행이 1–402 로 이어지며 모두 기준과 같거나 기대대로입니다. problem·deps 경고는 0 입니다(python).
  - prefixdiff s6ld↔s6le(python assert 통과): 스테이징 차이는 `src/bsd/ufs/ufs_subr.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `['x86-ufs_subr']`(STABS 만, 비 STABS 같음)입니다.
  - 링크 `s6p478-ln1` 은 `identical: true` 이고 `cmp` 로 원본과 같습니다(공통 기호 417 / 417).
- m68k:
  - `stage_m68k.py` 에 `X86[478] = 's6le'`·`EXCEPTS[478]`(`x86-ufs_subr`)를 등록하고 문서 줄 셋을 고쳤습니다(533 → 534 행).
  - `--plan 478 stage m0p478-a1-stage` 와 x86gate(s6le 일곱, `08_build/artifacts/m5p478/x86gate`)가 모두 같고, `m0p476-a1-stage` 와의 파일 차이는 `ufs_subr.c` 하나입니다(python assert).
  - final run `m5p478-a1`: **`x86-ufs_subr` OBJECT_MATCH**, REF(`P478__MX.o`)와 canon·머리·절·기호가 같습니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 177(+ 명시 배치 `ufs_alloc` 1), "코드 검증 + bss 추정" 은 22 입니다. 공통부 208 중 200(96.2%)이 코드 검증되었습니다.
  - 코드 차이가 남은 객체는 8 개입니다(netif, miniMon, nfs_client, tty, callout, kdp_udp, mach_net, swapfs).
- 기록:
  - PROVENANCE 558 행 그 자리 갱신(changes 칸과 파일 SHA-256; 1099 행, 중복 0)
  - MODIFICATIONS 638 행, DECISIONS D095(99 행), diff `06_reconstruction/evidence/x86-ufs_subr-plan478.diff`, `x86-ufs_subr.md`
  - `06_reconstruction/functions.tsv` 의 "edited file" 인용 셋(449·465·477)을 +4 행 옮김(옛·새 줄 내용 같음 assert; 4763 행 그대로)

## 479. M5-36 세부 계획 — m68k `mach_net` `netipc_listen` 의 최적화 해제(`#pragma CC_OPT_OFF`)(07 변경 없음; 코딩 전, 2026-10-23)

§470 순위 12 입니다. `nfs_client`(순위 3)는 §477 에서 새 근거가 생길 때까지 미뤘으므로, 그다음인 이 객체를 다룹니다.

확인한 사실(§470 기록, 원본 목록 `08_build/artifacts/m0p414/otool-V10/image.txt`, §470 객체 목록, 07·NeXTMach·Darwin 을 직접 읽음):
- §470 기록(`m5-m68k-survey-20261016.json`):
  - 객체 텍스트 1634 B, 원본 범위 [0x404c758, 0x404cdfc) 1700 B 로 −66 B 입니다.
  - 다른 구간은 `_netipc_listen` 하나이고(객체 156 B, 원본 222 B), 나머지 일곱 구간(앞부분 포함)은 재배치를 가리면 같습니다.
- 원본 `_netipc_listen`([0x404c982, 0x404ca60))은 최적화하지 않은 코드의 꼴입니다.
  - `linkw a6,#0xffec` 로 20 B 프레임을 잡고, a3·a2 를 `movel` 로 하나씩 저장하며, 끝에서 `movel a6@(0xffe4:w),a2` 처럼 프레임에서 되읽습니다.
  - 인자 다섯(0xc–0x1c)을 모두 프레임 지역 변수(−8, −12, −14, −16, −17)로 옮기고, 그 뒤에는 지역 변수를 메모리에서 읽습니다.
  - `movel a6@(0x20:w),d0; tstl d0; bne` 처럼 군더더기 비교가 있고, 0x404ca50 `bra 0x404ca54` 는 바로 다음 명령으로 갑니다.
  - `register` 로 선언한 `lp`·`b` 만 레지스터(a2·a3)에 있습니다.
  - 우리 객체는 `pea a6@; movel sp,a6; moveml d2/d3/d4/d5/a2` 로 시작해 인자를 레지스터에 두는 -O2 꼴입니다.
- NeXTMach mk-108.1 `kern/mach_net.c`:
  - 290 행 `#pragma CC_OPT_OFF` 가 `netipc_listen` 정의 바로 앞에, 337 행 `#pragma CC_OPT_RESTORE` 가 그 정의 바로 뒤에 있습니다.
  - 파일 머리 HISTORY(12–14 행)에 "1-Mar-90 Gregg Kellogg (gk) at NeXT … Turn off optimization around netipc_listen()." 이 있습니다.
- Darwin 0.1 `kernel/kern/mach_net.c`:
  - 320–326 행에서 같은 pragma 를 `#if m68k` 안에 두고, "옛 m68k 컴파일러 버그 때문인 듯" 이라는 주석을 답니다.
  - 370–375 행에서 `#pragma CC_OPT_RESTORE` 도 `#if m68k` 안에 둡니다.
- 컴파일러:
  - i386 컴파일러 사본 `08_build/toolchains/real-i386-20261001/lib-i386/cc1obj`·`cc1plus`·`cc1objplus` 에 `CC_OPT_OFF`·`CC_OPT_ON`·`CC_OPT_RESTORE` 문자열이 있습니다(`strings`).
  - m68k 쪽 컴파일러 모듈은 이 저장소에 사본이 없습니다. 동작은 시험으로 확인합니다.
- 07 `kern/mach_net.c`:
  - 파일은 401 행이고, 원본 바이트로 쓴 파일입니다(D024·D027; PROVENANCE 621 행, 출처 "none").
  - `netipc_listen` 은 165–206 행입니다. pragma 와 `m68k` 는 0 건입니다(grep).
  - 07 은 x86 원본과 같습니다(x86 은 최적화된 꼴). 따라서 x86 원본에는 pragma 가 없거나, 효과가 없도록 조건 안에 있었습니다.
  - m68k 스테이징 `m0p478-a1-stage`, x86 스테이징 `s6l5-g1a-stage`·`s6le-g1a-stage` 의 사본은 07 과 SHA-256 이 같습니다(`601b3df6…`).

가설:
- m68k 원본은 `netipc_listen` 을 `#pragma CC_OPT_OFF` … `#pragma CC_OPT_RESTORE` 로 감싸 컴파일했습니다. x86 쪽은 Darwin 처럼 `#if m68k` 조건으로 빠졌다는 해석입니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p478-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_352__mach_net.o`, run `m5p479-n1`; 명세는 무시 대상 `08_build/artifacts/m5p479/spec-mach_net.json`):
- `N`: 165 행 앞에 `#pragma CC_OPT_OFF`, 206 행 `}` 뒤에 `#pragma CC_OPT_RESTORE` 를 넣습니다(NeXTMach 꼴, 조건 없음).
- `D`: N 의 두 줄을 각각 `#if m68k` / `#endif m68k` 로 감쌉니다(Darwin 의 구조, 07 본 파일 후보). Darwin 의 주석 글은 넣지 않습니다.
- `F`(진단): `#pragma CC_OPT_OFF` 만 넣고 RESTORE 는 넣지 않습니다. 뒤따르는 함수(`netipc_ignore` 등)가 달라지면 RESTORE 자리가 바이트로 정해진다는 확인이 됩니다. 후보가 아닙니다.
- 판정(L1 `--place-from-image`):
  - 맞는 꼴은 OBJECT_MATCH 여야 합니다. §470 사유는 `__TEXT,__text`·`__DATA,__data`·`__DATA,__bss: unverified` 셋입니다. 텍스트가 맞아도 bss 가 남으면 그 사유를 그대로 적고, `__TEXT,__text` 가 같은지를 함수별로 봅니다.
  - 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
  - 관문(명령 종료 0, 객체 있음, K 가 `control_ref` 와 canon·obj_sig 모두 같음)은 직접 확인합니다.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5; 변형 K·N·D):
  - D 는 x86 원본(K)과 같아야 07 본 파일 후보가 됩니다.
  - N 은 i386 컴파일러가 pragma 를 따르면 달라질 것으로 예상합니다. 같으면 그 사실을 적습니다.
- 고르기(미리 정함):
  - N·D 가 m68k 에서 맞고 D 가 x86 에서도 K 와 같으면: 07 본 파일(D)과 m68k 덮어쓰기(N) 모두 가능합니다. 자리를 사용자에게 묻습니다.
  - N 이 x86 에서도 K 와 같으면: 07 본 파일에 N 도 후보가 되므로, 꼴과 자리를 묻습니다.
  - D 가 x86 에서 다르면: 07 본 파일 자리는 없습니다. m68k 덮어쓰기(N)로 정합니다.
  - 아무것도 맞지 않으면: 기록만 하고, 함수 안 남은 차이를 다시 적습니다.
- 구현:
  - 07 본 파일이면 x86 전체 재빌드(접두어 `s6lf`)·링크 cmp 와 m68k final 을 거칩니다.
  - 덮어쓰기면 m68k final 만 거칩니다(`07_kernel/v183.34/m68k/src/kern/mach_net.c`).
  - 출처: pragma 두 줄은 NeXTMach mk-108.1 `kern/mach_net.c:290`·`:337` 과 같은 글이므로 D013 대로 출처와 원 고지(CMU)를 PROVENANCE·MODIFICATIONS 에 적습니다. 같은 줄이 Darwin 0.1(320–326·370–375 행)에도 있으므로, D061 의 Darwin 고지가 필요한지는 꼴을 정할 때 사용자에게 함께 묻습니다.

### 479.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- "07 은 x86 원본과 같습니다" 는 너무 넓게 적었습니다. x86 `mach_net` 의 L1 은 `NOT_MATCH`, 사유 `__DATA,__bss: unverified` 하나입니다(`09_validation/reconstruction/s6l5-g1a-l1-352.json` 의 `object_reasons`). 바이트가 같다는 근거는 x86 전체 링크 cmp(s6p478-ln1)입니다.
- F 가 "RESTORE 자리를 바이트로 정한다" 는 것도 지나쳤습니다. F 는 "`netipc_ignore` 앞에서 최적화가 다시 켜져야 한다" 까지만 보여 줍니다. 두 정의 사이의 다른 자리나 `CC_OPT_ON` 같은 다른 철자는 가르지 못합니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 1700·1634·−66 B, `_netipc_listen` 222/156 B, 다른 일곱 구간 같음 | §470 기록(`extent_size`·`text_size`·`spans` 의 `masked_equal`)을 python 으로 출력 | ✅ |
| 프레임 20 B, 지역 −4(ipl)·−8·−12·−14·−16·−17, a2·a3 저장은 −28·−24 | 원본 목록 0x404c982 `linkw #0xffec`, 0x404ca54 `movel a6@(0xffe4:w),a2`, 0x404ca58 `a6@(0xffe8:w),a3` | ✅ |
| 최적화하지 않은 꼴이라는 해석은 목록과 맞지만, 그때의 플래그나 pragma 철자를 증명하지는 않음 | 같은 목록 | ✅ 맞는 꼴이 나와도 "바이트로 맞는 재구성 꼴" 로 적음 |
| 우리 객체는 -O2 명령으로 컴파일됨 | `08_build/artifacts/m3p430/cc.cmd:116`(`-O2`) | ✅ |
| 저장 순서(src_addr, src_port, dst_addr, dst_port, ipc_port)가 07 과 같아 본문 변경이 필요 없음 | 07 190–195 행과 원본 0x404c9e2–0x404ca04 | ✅ |
| LBHASH(`andb #0xf`)·spl 줄·`addqw #8,sp` 자리는 지금 본문과 어긋나지 않음 | 07 142 행 `% LBHSZ`(16), 원본 0x404ca0a–0x404ca3c | ⚖️ 해석은 맞음. 실제 자리는 시험으로만 확인함 |
| 참고 코드 인용 줄(NeXTMach 12·290·337, Darwin 320·370)이 맞음 | 원문을 열어 줄마다 확인(Darwin 320–326, 370–375) | ✅ |
| 07 메타(401 행, SHA, pragma·m68k 0 건, 스테이징 사본 같음) | python·grep·sha256sum | ✅ |
| x86 원본이 최적화된 꼴이라는 것만으로는 pragma 부재를 증명하지 못함; x86 L1 은 bss 사유가 남음 | `s6l5-g1a-l1-352.json` | ✅ 위 제 오류 |
| 두 꼴 모두 최적화를 끄지 못하면, 본문을 바꾸기 전에 명령 줄 `-O0` 진단을 둘 것 | 설계 판단 | ✅ 조건부 다음 단계로 둠(이번 실행에는 넣지 않음) |
| F 는 RESTORE 의 정확한 자리를 정하지 못함 | 설계 판단 | ✅ 위 제 오류 |
| 바꿀 자리는 겹치지 않는 고유한 글이어야 함 | python: 두 자리 글이 07 에서 각 1 번, 변형 적용 뒤 행 수 K 401·N 403·D 407·F 402, D 의 diff 를 직접 봄 | ✅ |
| bss 판정 기준을 미리 정할 것 | 객체 절(`obj_sig`): `__bss` 24 B 있음; `m5_m68k_final.py` 머리글(사유 `[]` 또는 `['__DATA,__bss: unverified']` 와 zerofill 검사) | ✅ 아래에 고정 |
| x86 K 관문(`control_equals_ref`)을 명시할 것; m68k `summary.match` 는 명령 상태·COMMON 을 보지 않음 | `m5_m68k_srcvar.py` 175–177 행(`match` 는 판정과 미정의만 봄) | ✅ |
| 고르기 규칙을 꼴마다, 빠짐없이 둘 것 | 계획의 고르기 | ✅ 아래로 대체 |
| STABS 는 비교에서 빠지고, 링크 비교로 남김 | `l2_prefix_diff.obj_sig`(비 STABS 기호), `m3_m68k_diag.canon` | ✅ 07 본 파일이면 x86 링크 cmp 를 그대로 요구 |
| 변형 도구의 구간 비교는 앞부분 정적 코드를 빼므로 절 전체 검증이 필요 | `m5_m68k_srcvar.py:157`(`compare_object` 의 외부 구간) | ✅ 텍스트 절 전체는 L1 이 봄: 사유에 `__TEXT,__text` 가 없어야 함 |
| 고지를 구체화할 것; 글이 같다는 것만으로는 어느 참고에서 왔는지 정해지지 않음 | AGENTS.md(고지는 PROVENANCE·MODIFICATIONS 에), D013·D061 | ⚖️ 출처 표기(NeXTMach 만, 또는 Darwin 고지도)는 꼴과 함께 사용자에게 묻습니다 |

계획 수정(실행 전 고정): 변형 = K·N·D·F(m68k), K·N·D(x86).
- 관문:
  - 모든 명령 종료 0, 객체 있음.
  - m68k K 가 `control_ref` 와 canon·obj_sig 모두 같음(python 으로 직접 비교).
  - x86 K 가 s6l5 객체와 같음(`control_equals_ref` true).
- m68k 에서 맞는 꼴:
  - L1 사유가 `[]` 이거나 `['__DATA,__bss: unverified']` 이어야 합니다. 사유에 `__TEXT,__text`·`__DATA,__data`·`__TEXT,__cstring` 이 있으면 맞지 않는 것입니다.
  - 사유가 bss 하나이면 final 에서 `m5_m68k_zerofill.py` 검사(§464 경로)를 거쳐야 받아들입니다.
  - 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
- x86 에서 받아들이는 꼴: K 와 canon·머리·절·비 STABS 기호가 같아야 합니다.
- 고르기(꼴마다):
  - 07 본 파일 후보는 m68k 에서 맞고 x86 에서도 받아들여지는 꼴입니다.
  - 덮어쓰기 후보는 m68k 에서 맞는 꼴입니다.
  - N·D 가 m68k 에서 서로 다르면(전처리 뒤 같은 글이므로 예상 밖) 고르지 않고 원인을 조사합니다.
  - 후보가 하나뿐이면 그 꼴과 자리로 정하고, 둘 이상이면 꼴·자리·고지를 묻습니다.
  - 맞는 꼴이 없으면 기록만 합니다. 텍스트가 여전히 -O2 꼴이면 다음 절에서 `-O0` 진단을 계획합니다.

### 479.2 변형 시험 결과(2026-10-23)

- m68k run `m5p479-n1`(4 명령)·x86 run `m5p479-xn1`(3 명령)은 모두 종료 0 입니다.
- 관문:
  - m68k K 는 `control_ref`(§470 객체)와 canon·obj_sig 가 모두 같습니다(python).
  - x86 K 는 s6l5 객체와 같습니다(`control_equals_ref` true).
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-mach-net-variants-p479-20261023.json`):
  - **N·D 는 사유가 `['__DATA,__bss: unverified']` 하나이고, 두 객체는 서로 같습니다**(같은 묶음).
    - 텍스트는 원본 범위 시작 0x404c758 에 놓이고, `__DATA,__data` 도 맞습니다(L1 `placements`, python 으로 16 진 변환).
    - 모든 외부 함수 구간이 원본과 같고, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같습니다.
  - F 는 `_netipc_ignore`·`_find_listener`·`_mach_net_init`·`_receive_ip_datagram` 이 달라집니다. `netipc_ignore` 앞에서 최적화가 다시 켜져야 합니다(§479.1 의 범위까지만).
  - bss 사유는 final 에서 `m5_m68k_zerofill.py` 검사(§464 경로)를 거쳐야 받아들입니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-mach-net-variants-p479-20261023.json`):
  - D 는 x86 K 와 canon·머리·절·비 STABS 기호가 같습니다.
  - N 은 다릅니다(canon·절·기호). i386 컴파일러도 이 pragma 를 따르므로, 조건 없는 N 은 07 본 파일에 둘 수 없습니다.
- 고르기(§479.1 규칙):
  - 07 본 파일 후보는 D 하나입니다(Darwin 의 `#if m68k` 구조).
  - m68k 덮어쓰기 후보는 N·D 입니다.
  - 후보가 둘 이상이므로 꼴·자리·고지를 사용자에게 묻습니다.

사용자 결정 D096(2026-10-23): 꼴·자리 "D: 07 본 파일 #if m68k (Recommended)", 고지 "NeXTMach 출처만 (Recommended)".

### 479.3 D096 구현 계획(07 본 파일 `mach_net.c` + x86 전체 재빌드 s6lf; 코딩 전, 2026-10-23)

§478.3 과 §474.3(bss 경로)의 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p479-n1/out/P479__D.o` 를 REF 로 씁니다(해시는 변형 기록과 대조).
1. 07 편집(`kern/mach_net.c`; 고치기 전 파일을 `08_build/artifacts/m5p479/mach_net.c.main.before` 로 먼저 옮겨 둠):
   - 165 행 앞과 206 행 `}` 뒤에 변형 D 의 세 줄씩을 넣습니다.
   - 두 `#if\tm68k` 줄 끝에 `/* plan 479 (D096): … */` 표시를 붙입니다. 표시에는 NeXTMach `kern/mach_net.c:290`·`:337` 출처를 적습니다. Darwin 의 주석 글은 쓰지 않습니다. 파일 머리는 바꾸지 않습니다.
   - python 으로 주석을 뺀 토큰이 변형 D 와 같은지 확인합니다. 파일은 401 → 407 행이 됩니다.
2. x86 전체 재빌드 s6lf(접두어 길이 4, 미사용 — `08_build/runs`·`08_build/runs/tools` 에 `s6lf`·`s6p479` 0 개)와 check 관문을 거칩니다. prepare·check 모두에 `L2_FORMS`·`L2_EXPECT` 를 주고, §469 의 통과 조건(problem 0, 행 1–402 연속, deps 경고 0, 모든 명령 종료 0)을 요구합니다.
3. prefixdiff s6le↔s6lf(plan 479, python assert):
   - 스테이징 차이는 `src/kern/mach_net.c` 하나, `stage_keys_differ`·`cmd_differ` 는 `[]`
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-mach_net']`, `differing_non_stabs_equal` 은 true
4. 링크 `s6p479-ln1` → `identical` 과 `cmp` 를 봅니다.
5. `stage_m68k.py`: `X86[479] = 's6lf'`, `EXCEPTS[479] = dict(EXCEPTS[478], **{'x86-mach_net': …})`, 문서 줄 셋(9·12·21 행)을 고칩니다. `--plan 479 stage m0p479-a1-stage` → x86gate(s6lf, `08_build/artifacts/m5p479/x86gate`) → `m0p478-a1-stage` 와의 차이는 `src/kern/mach_net.c` 하나여야 합니다(python assert).
6. final(`m5_m68k_final.py`, plan 479, 명세는 따로):
   - `mach_net` 의 기대 사유는 `['__DATA,__bss: unverified']` 입니다.
   - `bss_records` 는 §467(nfs)·§469(ns_timer)·§471·§474 의 zerofill 기록 넷입니다. §464 기록은 `m5_m68k_zerofill.py objs` 가 따로 읽습니다.
   - zerofill 결과는 `09_validation/reconstruction/m5-m68k-p479-zerofill-20261023.json` 으로 남깁니다.
7. 기록:
   - PROVENANCE 621 행(`07_kernel/src/kern/mach_net.c`)을 그 자리에서 갱신합니다.
     - 출처 칸들에 NeXTMach(저장소 URL·커밋 `f6bdb9c3…`·`mk-108.1/kern/mach_net.c:290,337`)를 더하고, 고지 칸에 CMU 고지(D013)를 적습니다.
     - changes 칸에 plan 479 (D096) 를 더하고 파일 SHA-256 을 새 값으로 바꿉니다(행 수 같음, 중복 0).
   - MODIFICATIONS 끝에 한 행, DECISIONS D096, diff(`06_reconstruction/evidence/x86-mach_net-plan479.diff`), `x86-mach_net.md` 에 절을 덧붙입니다. Darwin 0.1 에도 같은 줄이 `#if m68k` 안에 있다는 사실은 기록에만 적습니다.
   - `06_reconstruction/functions.tsv`: 165 행 이후의 07 줄 인용을 옮깁니다. 165–206 행은 +3, 207 행 이후는 +6 입니다(지금 인용 165→168, 208→214, 247→253, 293→299, 328→334, 339→345; 47·121 은 그대로). 옛·새 줄 내용이 같은지 assert 하고, 파일 행 수는 그대로입니다.
   - 집계: m68k "코드 검증 + bss 추정" 22 → 23, 코드 검증 200 → 201/208, 코드 차이가 남은 객체 8 → 7 입니다.

### 479.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계 순서에 빠진 것 없음; 재빌드·prefixdiff 관문이 §469·§478 과 같음 | §478.3·§474.3 과 나란히 읽음 | ✅ |
| 링크는 `l2_link.py prepare s6p479-ln1 s6lf` → kr_run → `l2_compare.py` → `cmp` 로 적을 것 | §478.4 표(같은 순서) | ✅ 아래에 고정 |
| x86gate 에도 `--plan 479` 를 줄 것(없으면 433), manifest 는 파일 항목으로 비교 | `stage_m68k.py:40`(`PLAN = 433`), §478.4 | ✅ |
| 변형 D 는 옛 165 행 앞·206 행 뒤에 넣고, 401 → 407 행, 165–206 +3·207 이후 +6 | 변형 D 의 diff 를 직접 봄(§479.1), python 행 수 | ✅ |
| 07 줄 인용은 `functions.tsv` 2033–2040 행 여덟뿐이고 옮길 값이 맞음 | grep(06·07 전체), 2033–2040 행 출력(47·121·165·208·247·293·328·339) | ✅ |
| final 이 받는 사유는 `[]` 또는 `['__DATA,__bss: unverified']` 뿐 | `m5_m68k_final.py:34-37`(`load` 의 assert) | ✅ |
| `bss_records` 넷(nfs·ns_timer·p471·p474)이 맞고, §464 기록은 `objs` 가 따로 읽음 | `ls 09_validation/reconstruction/*zerofill*`(m5 기록 여섯), final 96–99 행 | ✅ |
| final 은 `08_build/artifacts/m5p479/<RUN>/zerofill-objs.json` 을 쓸 뿐이고, 09 기록은 따로 복사해야 함 | final 64·90 행; §474 의 09 기록과 `m5p474-a1/zerofill-objs.json` 의 SHA-256 이 같음(python) | ✅ 복사 단계를 더함 |
| `stage_m68k.py` 의 478 항목과 문서 줄 9·12·21 | 285–286 행, grep | ✅ |
| PROVENANCE 7 열, 파일 SHA 는 changes 칸 | 머리 행 출력, 621 행 출력 | ✅ |
| 섞인 출처는 `authored+nextmach`, revision 칸에 D024 와 저장소·커밋을 함께, original_path 에 pragma 자리를 적는 꼴 | 1063·1064·1071·1086 행 | ✅ 그 꼴을 따름 |
| 집계 177+1+22 = 200 → 23·201/208·7 | python(§478.5 수치) | ✅ final 통과 조건부 |

선례와 다른 점(밝혀 둠): 1063–1086 행의 선례는 NeXTMach 줄을 쓸 때 원 파일의 고지 줄을 우리 파일 안에도 넣었습니다. 이번에는 사용자 선택(D096 "NeXTMach 출처만": 고지는 PROVENANCE·MODIFICATIONS 에)과 D013 의 글귀대로 파일 머리를 바꾸지 않습니다. 보고에서 이 차이를 밝힙니다.

계획 수정(실행 전 고정):
- 4: `l2_link.py prepare s6p479-ln1 s6lf` → `kr_run.py` prepare/launch/wait/collect → `l2_compare.py` → `cmp`.
- 5: stage 와 x86gate 모두 `--plan 479` 를 주고, manifest 는 파일 항목으로 비교합니다.
- 6: final 뒤 `08_build/artifacts/m5p479/m5p479-a1/zerofill-objs.json` 을 `09_validation/reconstruction/m5-m68k-p479-zerofill-20261023.json` 으로 복사하고, SHA-256 이 같은지 확인합니다.
- 7: PROVENANCE 621 행은 `authored+nextmach`; revision 칸 `D024 (written from the original bytes); https://github.com/johnsonjh/NeXTMach.git f6bdb9c3268f0eadc545d41bcc0564453b17001e`; original_path 칸 `(none); CC_OPT pragma pair: mk-108.1/kern/mach_net.c:290,337`; license 칸은 지금 글 뒤에 pragma 두 줄의 CMU 고지(D013, 기록만)를 덧붙입니다.

### 479.5 D096 구현 결과(2026-10-23) — 기록 `09_validation/reconstruction/m5-m68k-p479-final-20261023.json`

- 07 편집:
  - 본 파일 `kern/mach_net.c` 는 401 → 407 행입니다(165–167 행과 210–212 행이 새 줄).
  - 주석을 뺀 토큰이 변형 D 와 같고, 차이는 표시 주석을 붙인 `#if` 두 줄뿐입니다(python).
  - 고치기 전 파일은 `08_build/artifacts/m5p479/mach_net.c.main.before` 입니다. REF `P479__D.o` 의 SHA-256 은 변형 기록과 같습니다(`b39febdb…`).
- x86 전체 재빌드 s6lf:
  - 명령 804 개가 모두 종료 0 이고, check 일곱의 402 행이 1–402 로 이어지며 모두 기준과 같거나 기대대로입니다. problem·deps 차이는 0 입니다(python).
  - prefixdiff s6le↔s6lf(python assert 통과): 스테이징 차이는 `src/kern/mach_net.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `['x86-mach_net']`(STABS 만, 비 STABS 같음)입니다.
  - 링크 `s6p479-ln1` 은 `identical: True` 이고 `cmp` 로 원본과 같습니다(공통 기호 417 / 417).
- m68k:
  - `stage_m68k.py` 에 `X86[479] = 's6lf'`·`EXCEPTS[479]`(`x86-mach_net`)를 등록하고 문서 줄 셋을 고쳤습니다(534 → 535 행, `wc -l`).
  - `--plan 479 stage m0p479-a1-stage` 와 `--plan 479 x86gate`(s6lf 일곱, `08_build/artifacts/m5p479/x86gate`)가 모두 같고, `m0p478-a1-stage` 와의 파일 차이는 `src/kern/mach_net.c` 하나입니다(python assert).
  - final run `m5p479-a1`: `x86-mach_net` 은 REF 와 canon·머리·절·기호가 같고, L1 사유는 `__DATA,__bss: unverified` 하나, 원본에 없는 미정의는 0 입니다.
  - zerofill(`m5-m68k-p479-zerofill-20261023.json`, `zerofill-objs.json` 복사본과 SHA-256 같음)은 reference-inferred [0x40b3722, 0x40b373a) 24 B 이고, 이전 네 기록의 후보와 겹침 0 입니다. 24 B 는 객체의 `__bss` 크기와 같습니다(python).
- 집계(python):
  - m68k OBJECT_MATCH 는 177(+ 명시 배치 `ufs_alloc` 1), "코드 검증 + bss 추정" 은 23 입니다. 공통부 208 중 201(96.6%)이 코드 검증되었습니다.
  - 코드 차이가 남은 객체는 7 개입니다(netif, miniMon, nfs_client, tty, callout, kdp_udp, swapfs).
- 기록:
  - PROVENANCE 621 행 그 자리 갱신(`authored+nextmach`, 출처·CMU 고지·changes·파일 SHA-256; 1099 행, 중복 0)
  - MODIFICATIONS 639 행, DECISIONS D096(100 행), diff `06_reconstruction/evidence/x86-mach_net-plan479.diff`, `x86-mach_net.md` 에 절 덧붙임
  - `06_reconstruction/functions.tsv` 의 07 줄 인용 여섯(165·208·247·293·328·339)을 옮김(옛·새 줄 내용 같음 assert; 4764 split 행 그대로)
  - 선례와 다른 점: NeXTMach 고지는 파일에 넣지 않고 기록에만 둡니다(D096, §479.4).

## 480. M5-37 세부 계획 — m68k `netif`: 정적 함수 자리·`if_ioctl` 의 `if_control` 직접 호출·`if_attach` 의 hostid 블록(07 변경 없음; 코딩 전, 2026-10-23)

§470 순위에서 `mach_net` 다음으로 남은 객체 가운데 원인을 원본 바이트로 나눌 수 있는 것입니다(tty 101, netif 105 점; tty 는 레지스터 묶음이 25 개라 뒤로 둡니다).

확인한 사실(§470 기록, 원본 목록 `image.txt`, 원본 `__const`, 기호표, 07·NeXTMach 를 직접 읽음):
- §470 기록: 객체 텍스트 1598 B, 원본 범위 [0x401cab2, 0x401d0c0) 1550 B 로 +48 B 입니다. 다른 구간은 `_if_ioctl`(194/202)·`_if_collisions_set`(18/72)·`_iflist_next`(16/36)·`_if_detach`(140/86)·`_if_attach`(306/250)·`_if_output_mbuf`(180/160) 이고, 나머지 25 구간은 같습니다. L1 사유는 `__TEXT,__text`·`__DATA,__bss: unverified` 입니다.
- 정적 함수 자리:
  - 원본은 `_if_collisions_set`(0x401cd1a, 18 B) 바로 뒤 0x401cd2c 에 이름 없는 54 B 함수를 둡니다. `if_dispatchers`(0x40b3454) 목록을 돌며 `vif_attach(vif_private, arg)` 를 부르는 꼴로, 07 `pingvirtuals`(353–364 행)와 같은 명령 열입니다(우리 객체 0x2e6–0x31c). 원본 `_if_attach` 는 이 주소를 `bsr 0x401cd2c:l` 로 부릅니다.
  - 원본은 `_iflist_next` 뒤 0x401cd80(`moveq #5,d0`)·0x401cd8a(`clrl d0`)에 10 B 함수 둘을 둡니다. `_if_detach` 가 그 주소를 `if_init`·`if_output`·`if_control`·`if_input` 자리(0x2e·0x32·0x36·0x3a)와 `if_getbuf` 자리(0x3e)에 넣습니다. 07 `if_null_func`(EIO = 5)·`if_null_getbuf`(NULL)에 해당하며, 07 에서는 파일 끝(564–575 행)에 있습니다.
  - 따라서 우리 `_if_detach` 구간 140 B = 86 + 54(`pingvirtuals`), `_if_output_mbuf` 구간 180 B = 160 + 20(null 둘)입니다(python).
  - NeXTMach mk-108.1 `net/netif.c` 도 `pingvirtuals`(290–301 행)를 `if_collisions_set`(282 행) 바로 뒤, `if_attach`(304 행) 앞에 둡니다. 그 판에는 `iflist_*`·`if_detach`·null 함수가 없습니다.
- `_if_ioctl`:
  - 원본은 `SIOCADDMULTI`(0x80206931) 갈래에서 `bsr 0x401cad6:l`(`_if_control`)로 함수를 직접 부르고, 넘기는 문자열은 0x40acfba `add-multicast` 입니다.
  - 다른 갈래(`rmv-multicast` 0x40acfc8 등)는 `jsr a2@`(`ifp->if_control` 포인터)입니다. 문자열은 원본 `__const`(0x40ace76, 파일 오프셋 708214)에서 python 으로 읽었습니다.
  - 07 은 123 행에서 `ifp->if_control(...)` 를 부릅니다. 07 `if_control`(70–85 행)은 NULL 검사 뒤 `ifp->if_control` 을 부르는 함수입니다.
  - 나머지 차이는 a1/a2 레지스터 바꿈입니다. 직접 호출에서 따라 나온 것으로 봅니다(가설).
- `_if_attach`:
  - 원본에는 07 429–438 행의 hostid 블록(`if (hostid == 0) { … if_control(…GETADDR…) … hostid = ntohl(…) }`)에 해당하는 명령이 없습니다. 원본은 `bsr 0x401cd2c`(pingvirtuals) 뒤 바로 `movel a2,d0` 로 돌아갑니다.
  - 원본은 `pea a6@` 로 지역 변수 없는 프레임이고, 우리는 `linkw a6,#0xfff8`(`u_char ea[6]`)입니다.
  - 이 블록은 계획 153 에서 x86 원본 바이트로 작성한 것입니다. NeXTMach `if_attach` 에도 없습니다(07 의 `hostid` 3 건은 모두 계획 153 의 줄).
- 컴파일 옵션:
  - x86 은 `-g -O3 -fno-omit-frame-pointer`(`06_reconstruction/l2_build_forms-s6p398.tsv` 328 행)입니다.
  - m68k 는 `-g -O2`(`08_build/runs/m3p429-cc2/run.cmd` 81 행)입니다.
  - §467 에서 x86 `-O3` 는 인라인 후보 정적 함수를 파일 끝으로 미루고, m68k `-O2` 는 소스 순서대로 낸다는 것을 시험으로 확인했습니다(D084). x86 원본에서도 null 둘은 객체 끝(0x12125c·0x121268)에 있습니다.
  - 그러므로 x86 바이트로는 정적 함수의 소스 자리와 `if_control` 직접 호출 여부가 정해지지 않았을 수 있습니다. 가설이며, x86 변형으로 확인합니다.
- 07 `bsd/net/netif.c`:
  - 575 행이고, NeXTMach 바탕에 작성 줄(plan 153)이 더해진 파일입니다(PROVENANCE 458 행).
  - m68k 스테이징 `m0p479-a1-stage`·x86 스테이징 `s6l5-g1a-stage` 사본과 SHA-256 이 같습니다(`85b57a11…`).
- 선례:
  - §467(D084, `nfs_subr`)와 §473(D091, `mach_clock`)에서 m68k 원본 순서에 맞춰 07 본 파일의 정의 자리를 옮겼고, x86 은 그대로였습니다.

가설:
- m68k 원본의 소스는 다음과 같았습니다.
  - `pingvirtuals` 를 `if_collisions_set` 바로 뒤(NeXTMach 자리)에, null 둘을 `iflist_next` 뒤·`if_detach` 앞에 정의합니다.
  - `SIOCADDMULTI` 갈래는 `if_control(netif, …)` 를 부릅니다.
  - hostid 블록은 m68k 에서 컴파일되지 않습니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p479-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_327__netif.o`, run `m5p480-f1`; 명세는 무시 대상 `08_build/artifacts/m5p480/spec-netif.json`):
- `R`(자리): `pingvirtuals` 정의(353–365 행)를 317 행 주석 앞으로, null 둘(564–575 행, 주석 줄 포함)을 `if_detach`(332 행) 앞으로 옮깁니다. 줄 내용은 바꾸지 않고, 51–52 행의 전방 선언은 그대로 둡니다.
- `C`(호출): 123 행 `ifp->if_control(` 를 `if_control(` 로 바꿉니다.
- `HI`·`HN`(hostid): 429–438 행을 `#if i386` … `#endif i386`(HI) 또는 `#ifndef m68k` … `#endif m68k`(HN)로 감쌉니다. 두 꼴은 두 아키텍처 모두 전처리 뒤 같은 글입니다.
- `ALL` = R + C + HI, `ALLN` = R + C + HN. R·C·HI 단독은 바뀐 것마다 어디를 고치는지 보는 진단입니다.
- 판정(L1 `--place-from-image`):
  - 맞는 꼴은 사유가 `[]` 이거나 `['__DATA,__bss: unverified']` 이어야 합니다. 사유가 bss 하나이면 final 의 zerofill 검사를 거칩니다(§479.1 과 같은 규칙).
  - 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
  - 관문: 명령 종료 0, 객체 있음, K 가 `control_ref` 와 canon·obj_sig 모두 같음.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5, 같은 일곱 변형):
  - 07 본 파일 후보는 x86 K 와 canon·머리·절·비 STABS 기호가 같아야 합니다.
  - 관문: x86 K `control_equals_ref` true.
- 고르기(미리 정함, 꼴마다):
  - 07 본 파일 후보는 m68k 에서 맞고 x86 에서도 받아들여지는 꼴입니다. 덮어쓰기 후보는 m68k 에서 맞는 꼴입니다.
  - ALL·ALLN 이 m68k 에서 서로 다르면 고르지 않고 원인을 조사합니다(전처리 뒤 같은 글이므로 예상 밖).
  - 후보가 하나뿐이면 그 꼴과 자리로 정하고, 둘 이상이면 꼴(HI/HN)·자리를 묻습니다.
  - ALL 이 맞지 않으면 기록만 하고, 남은 차이를 함수 안에서 다시 적습니다. 단독 변형의 결과는 진단으로만 씁니다.
- 구현은 §479.3 과 같습니다(07 본 파일이면 x86 재빌드 접두어 `s6lg`·링크 `s6p480-ln1`, final run `m5p480-a1`). 바뀐 줄의 출처: 옮긴 줄은 그대로(NeXTMach·plan 153), `if_control(` 호출과 조건 줄은 작성(D024)입니다.

### 480.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘): "0x401cd80(`moveq #5,d0`)·0x401cd8a(`clrl d0`)" 는 함수 시작 주소와 본문 명령을 섞어 적었습니다. 두 함수는 0x401cd80·0x401cd8a 에서 `pea a6@` 로 시작하고, 본문 명령은 0x401cd84 `moveq #5,d0`·0x401cd8e `clrl d0` 입니다(`image.txt` 35714–35721 행). `_if_detach` 가 넣는 주소는 함수 시작 주소이므로 결론은 같습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| null 함수의 명령 주소 표기가 틀림 | `image.txt` 35714–35721 행 | ✅ 위 제 오류 |
| 크기(1598/1550/+48)와 여섯 구간 쌍, 같은 구간 25 개 | §470 기록을 python 으로 출력(구간 표) | ✅ |
| R 이 구간 넷의 차이(54 B·20 B)를 설명함 | 원본 0x401cd2c–0x401cd62 와 객체 0x2e6–0x31c 를 나란히 읽음, null 둘 | ✅ 시험으로 확인 |
| C 는 원본의 호출 구분과 맞고, 문자열 주소·`__const` 기준이 맞음 | 원본 바이트를 python 으로 읽음(`add-multicast` 0x40acfba, `rmv-multicast` 0x40acfc8) | ✅ |
| `_if_ioctl` 레지스터 차이의 설명은 가설임 | 나란히 비교(a1/a2 바꿈 외 직접 호출 묶음) | ✅ 가설로 둠 |
| H 는 프레임 차이까지 설명함(ea 제거; 56 B; 1598 + 8 − 56 = 1550) | 나란히 비교(우리만 14 줄 + 머리 `linkw`); 계산은 아래 python | ⚖️ 계산은 python 으로 다시 함, 판정은 시험으로 |
| 원천 메타·NeXTMach 자리·plan 153 작성 줄 | PROVENANCE 458 행, NeXTMach 282·290–301·304 행, 07 grep | ✅ |
| 명세가 맞음(고유·겹침 없음·순서) | python(변형 적용, ALL 의 diff 와 끝 줄을 직접 봄) | ✅ |
| HI·HN 은 전처리 뒤 같은 코드 토큰이지만 STABS 는 다를 수 있고 뜻(다른 아키텍처의 정책)이 다름; x86 에도 "예상 밖 차이" 관문을 둘 것 | `specs-i386:38` `-Di386`, `specs-m68k:38` `-Dm68k` | ✅ 아래에 고정 |
| m68k 요약(`summary.match`)은 계획의 관문을 다 보지 않음 | `m5_m68k_srcvar.py` 158–177 행 | ✅ §479 처럼 직접 확인 |
| 덮어쓰기 갈래에 구현 절차가 없음(덮어쓰기는 07 줄을 지우지 않고 표시 줄만 끼워 넣어야 함) | `stage_m68k.py:328` `check_derived`, 17 행 문서 | ✅ 덮어쓰기만 남으면 새 절에서 계획 |
| final 의 `bss_records` 에 §479 기록을 더하고, `functions.tsv` 의 07 줄 인용을 옮길 것 | `m5-m68k-p479-zerofill-20261023.json` 있음, `functions.tsv` 965·978–980·986–987 행 | ✅ 구현 계획에 넣음 |
| x86 위험(R: 정적 함수의 인라인·출력 순서, C: 감싼 함수의 NULL 검사, H: 조건 매크로) | 설계 판단 | ✅ 변형마다 x86 모든 같음 칸을 요구 |

계산(python): 객체 − 원본 = 1598 − 1550 = 48 B; `_if_attach` 구간 306 − 250 = 56 B; `_if_ioctl` 은 원본이 8 B 깁니다. 정적 함수 셋(54 + 20 B)은 자리만 다르므로 크기 차에 들지 않고, 48 = 56 − 8 입니다(1598 + 8 − 56 = 1550).

계획 수정(실행 전 고정):
- 관문(직접 확인): 모든 명령 종료 0, 객체 있음, m68k K 와 `control_ref` 의 canon·obj_sig 같음, x86 K `control_equals_ref` true.
- 맞는 꼴: 사유 `[]` 또는 `['__DATA,__bss: unverified']`, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같음.
- ALL·ALLN 이 m68k 또는 x86 의 비 STABS 비교에서 서로 다르면 고르지 않고 원인을 조사합니다.
- 07 본 파일에 놓을 수 있는 꼴이 없고 덮어쓰기만 남으면, 덮어쓰기 꼴(07 줄을 남기고 표시 줄만 끼우는 꼴)을 새 절에서 따로 계획·시험합니다.
- 구현 때 final 의 `bss_records` 는 §479 까지 다섯 기록이고, `functions.tsv` 의 07 줄 인용(208·319·325·333·566·572)을 옮깁니다.

### 480.2 변형 시험 결과(2026-10-23)

- m68k run `m5p480-f1`·x86 run `m5p480-xf1`(각 7 명령)은 모두 종료 0 입니다.
- 관문:
  - m68k K 는 `control_ref`(§470 객체)와 canon·obj_sig 가 모두 같습니다(python).
  - x86 K 는 s6l5 객체와 같습니다(`control_equals_ref` true).
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-netif-variants-p480-20261023.json`):
  - **ALL·ALLN 은 사유가 `['__DATA,__bss: unverified']` 하나이고, 모든 외부 함수 구간이 원본과 같습니다.** 두 객체는 비 STABS 로 같은 묶음입니다(SHA 는 STABS 때문에 다름).
    - 텍스트는 원본 범위 시작 0x401cab2, `__TEXT,__const` 는 0x40acf6e 에 놓입니다(L1 `placements`).
    - 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같습니다.
  - 단독 변형(진단)은 바뀐 자리만 고칩니다.
    - R 은 `_if_ioctl`·`_if_attach` 만 남깁니다.
    - C 는 `_if_ioctl` 을 고칩니다(a1/a2 레지스터 차이도 함께 사라짐; §480 의 가설이 맞음).
    - HI·HN 은 `_if_attach` 를 고칩니다(서로 같은 묶음).
- **x86**(기록 `09_validation/reconstruction/m5-x86-netif-variants-p480-20261023.json`):
  - 일곱 변형 모두 x86 K 와 canon·머리·절·비 STABS 기호가 같습니다.
  - x86 원본 바이트(`-O3`)로는 정적 함수 자리·`if_control` 직접 호출·hostid 조건이 정해지지 않습니다. §480 의 가설이 맞습니다.
- 고르기(§480.1 규칙):
  - 07 본 파일 후보는 ALL(`#if i386`)·ALLN(`#ifndef m68k`) 둘입니다. 덮어쓰기는 따로 계획이 필요합니다.
  - 후보가 둘이므로 꼴과 자리를 사용자에게 묻습니다.

사용자 결정 D097(2026-10-23): hostid 조건 "#if i386 (Recommended)"(ALL 꼴), 자리 "07 본 파일 (Recommended)".

### 480.3 D097 구현 계획(07 본 파일 `netif.c` + x86 전체 재빌드 s6lg; 코딩 전, 2026-10-23)

§479.3(§479.4 수정 포함)의 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p480-f1/out/P480__ALL.o`(SHA-256 `c9f167a2…`, 변형 기록과 대조)를 REF 로 씁니다.
1. 07 편집(`bsd/net/netif.c`; 고치기 전 파일을 `08_build/artifacts/m5p480/netif.c.main.before` 로 먼저 옮겨 둠):
   - 변형 ALL 의 바꿈을 그대로 넣습니다(정적 함수 셋 옮김, 123 행 `if_control(`, hostid 블록 `#if i386`).
   - 표시를 붙입니다.
     - 옮긴 `pingvirtuals` 앞과 null 둘의 주석 줄 앞에 각각 `/* plan 480 (D097): defined here, as in the m68k original */` 한 줄을 둡니다.
     - 123 행 끝과 `#if\ti386` 줄 끝에 `/* plan 480 (D097): … */` 를 붙입니다.
   - python 으로 주석을 뺀 토큰이 변형 ALL 과 같은지 확인합니다(ALL 은 고치기 전 파일에서 다시 만듦). 파일은 575 → 579 행이 됩니다(ALL 577 행 + 표시 줄 둘).
2. x86 전체 재빌드 s6lg(접두어 길이 4, 미사용)와 check 관문(`L2_FORMS`·`L2_EXPECT`, problem 0, 행 1–402 연속, deps 차이 0, 명령 모두 종료 0; python 집계)을 거칩니다.
3. prefixdiff s6lf↔s6lg(plan 480, python assert):
   - 스테이징 차이는 `src/bsd/net/netif.c` 하나, `stage_keys_differ`·`cmd_differ` 는 `[]`
   - `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-netif']`, `differing_non_stabs_equal` 은 true
4. 링크: `l2_link.py prepare s6p480-ln1 s6lg` → `kr_run.py` → `l2_compare.py` → `cmp` 로 원본과 같아야 합니다.
5. `stage_m68k.py`:
   - `X86[480] = 's6lg'`, `EXCEPTS[480] = dict(EXCEPTS[479], **{'x86-netif': …})` 를 등록하고, 문서 줄 셋(9·12·21 행)을 고칩니다.
   - `--plan 480 stage m0p480-a1-stage` 와 `--plan 480 x86gate 08_build/artifacts/m5p480/x86gate` 를 돌립니다.
   - `m0p479-a1-stage` 와의 파일 항목 차이는 `src/bsd/net/netif.c` 하나여야 합니다(python assert).
6. final(`m5_m68k_final.py`, plan 480, run `m5p480-a1`):
   - `netif` 의 기대 사유는 `['__DATA,__bss: unverified']` 입니다.
   - `bss_records` 는 nfs·ns_timer·p471·p474·p479 의 zerofill 기록 다섯입니다.
   - final 뒤 `08_build/artifacts/m5p480/m5p480-a1/zerofill-objs.json` 을 `09_validation/reconstruction/m5-m68k-p480-zerofill-20261023.json` 으로 복사하고, SHA-256 이 같은지 확인합니다.
7. 기록:
   - PROVENANCE 458 행(`07_kernel/src/bsd/net/netif.c`)을 그 자리에서 갱신합니다. 출처 칸은 그대로(NeXTMach + 작성 줄)이고, changes 칸에 plan 480 (D097) 와 새 파일 SHA-256 을 적습니다(행 수 같음, 중복 0).
   - MODIFICATIONS 끝에 한 행, DECISIONS D097, diff(`06_reconstruction/evidence/x86-netif-plan480.diff`), `x86-netif.md` 에 절을 덧붙입니다.
   - `06_reconstruction/functions.tsv` 의 07 줄 인용(208·319·325·333·566·572)을 옛 줄 내용으로 새 줄을 찾아 옮깁니다. 옛·새 줄 내용이 같은지 assert 하고, 파일 행 수는 그대로입니다. NeXTMach 인용은 바꾸지 않습니다.
   - 집계: "코드 검증 + bss 추정" 23 → 24, 코드 검증 201 → 202/208(97.1%), 코드 차이가 남은 객체 7 → 6 입니다(python).

### 480.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- §480.3 의 7 은 `functions.tsv` 의 07 줄 인용을 명시 경로 꼴(208·319·325·333·566·572)만 적었습니다. 같은 파일을 가리키는 "edited file :N" 꼴 다섯(981–985 행의 367·446·475·497·533)도 옮겨야 합니다.
- §479.5 의 `stage_m68k.py` 행 수 "535 → 536" 은 python `split` 수였습니다. `wc -l` 로는 534 → 535 입니다(§479.5 를 고침). `functions.tsv` 의 "4764 split 행" 은 `wc -l` 4763 과 같은 파일입니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계·관문에 빠진 것 없음(§479.4 수정 포함) | §479.3–479.5 와 나란히 읽음 | ✅ |
| ALL 은 575 → 577 행, 표시 줄 둘로 579 행; 주석만이라 토큰 같음; 표시 꼴은 선례와 같음 | python(변형 적용 행 수), 07 `ufs_subr.c:416`·`mach_net.c:165`(줄 끝), `nfs_subr.c:1140`·`mach_clock.c:201`(독립 줄) | ✅ 구현에서 토큰 비교를 다시 함 |
| 옮길 인용은 열: 명시 경로 다섯(978·979·980·986·987 행)과 "edited file" 다섯(981–985 행) | `sed -n 978,987p` 에서 `07_kernel/src/bsd/net/netif.c:319·325·333·566·572` 와 `edited file :367·446·475·497·533` 출력 | ✅ 위 제 오류 |
| 새 줄 번호(333·339·361·382·463·492·514·550·349·355) | 구현 때 옛 줄 내용으로 새 줄을 찾아 python 으로 정함 | ⏭️ 값은 옮겨 적지 않음(구현에서 assert) |
| 그대로인 인용 23 개(955–977 행) | 317 행 앞의 줄은 바뀌지 않음(ALL 의 첫 바꿈은 123 행 한 줄 안, 행 수 같음) | ✅ 구현의 assert 가 함께 확인 |
| 기대 사유 bss 하나가 맞음 | `l1-m5p480-f1-ALL.json` 의 `object_reasons`(§480.2 에서 출력) | ✅ |
| `bss_records` 다섯, §464 기록은 넣지 않음 | §479.4 판정, `ls` | ✅ |
| `stage_m68k.py` 479 항목(286·287 행)과 문서 줄 9·12·21; 표시 등록은 필요 없음 | grep, `wc -l` 535 | ✅ |
| 집계 24·202/208(97.1%)·6 | python | ✅ final 통과 조건부 |

계획 수정: 7 의 인용 옮김은 `functions.tsv` 에서 `07_kernel/src/bsd/net/netif.c:N` 꼴과, `netif.c` 행(955–987 행)의 `edited file :N` 꼴을 모두 대상으로 합니다. 옛 줄 내용과 같은 새 줄을 찾아 옮기고, 같은 내용의 줄이 둘 이상이면 멈춥니다.

### 480.5 D097 구현 결과(2026-10-23) — 기록 `09_validation/reconstruction/m5-m68k-p480-final-20261023.json`

- 07 편집:
  - 본 파일 `bsd/net/netif.c` 는 575 → 579 행입니다.
  - 주석을 뺀 토큰이 변형 ALL 과 같습니다. ALL 은 고치기 전 파일에서 다시 만들었고, run 의 스테이징 사본과도 같습니다(python).
  - 고치기 전 파일은 `08_build/artifacts/m5p480/netif.c.main.before` 이고, REF `P480__ALL.o` 의 SHA-256 은 변형 기록과 같습니다.
- x86 전체 재빌드 s6lg:
  - 명령 804 개가 모두 종료 0 이고, 402 행이 1–402 로 이어지며 모두 기준과 같거나 기대대로입니다. problem·deps 차이는 0 입니다(python).
  - prefixdiff s6lf↔s6lg(python assert 통과): 스테이징 차이는 `src/bsd/net/netif.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `['x86-netif']`(STABS 만, 비 STABS 같음)입니다.
  - 링크 `s6p480-ln1` 은 `identical file: True` 이고 `cmp` 로 원본과 같습니다(공통 기호 417 / 417).
- m68k:
  - `stage_m68k.py` 에 `X86[480] = 's6lg'`·`EXCEPTS[480]`(`x86-netif`)를 등록하고 문서 줄 셋을 고쳤습니다(535 → 536 행, `wc -l`).
  - `--plan 480 stage m0p480-a1-stage` 와 `--plan 480 x86gate`(s6lg 일곱 모두 같음)를 거쳤고, `m0p479-a1-stage` 와의 파일 항목 차이는 `src/bsd/net/netif.c` 하나입니다(python assert).
  - final run `m5p480-a1`: `x86-netif` 은 REF 와 canon·머리·절·기호가 같고, L1 사유는 `__DATA,__bss: unverified` 하나, 원본에 없는 미정의는 0 입니다.
  - zerofill(`m5-m68k-p480-zerofill-20261023.json`, `zerofill-objs.json` 복사본과 SHA-256 같음)은 reference-inferred [0x40b3454, 0x40b3458) 4 B(`if_dispatchers`)이고, 이전 다섯 기록의 후보와 겹침 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 177(+ 명시 배치 `ufs_alloc` 1), "코드 검증 + bss 추정" 은 24 입니다. 공통부 208 중 202(97.1%)가 코드 검증되었습니다.
  - 코드 차이가 남은 객체는 6 개입니다(miniMon, nfs_client, tty, callout, kdp_udp, swapfs).
- 기록:
  - PROVENANCE 458 행 그 자리 갱신(changes 칸과 파일 SHA-256; 1099 행, 중복 0)
  - MODIFICATIONS 640 행, DECISIONS D097, diff `06_reconstruction/evidence/x86-netif-plan480.diff`, `x86-netif.md` 에 절 덧붙임
  - `06_reconstruction/functions.tsv` 의 netif 인용 33 개를 옛 줄 내용으로 새 줄에 맞췄습니다. 그중 10 개가 옮겨졌고(명시 경로 5, "edited file" 5), 줄 내용이 하나씩만 맞는지 assert 했습니다. 파일은 4763 행 그대로입니다(`wc -l`).

## 481. M5-38 세부 계획 — m68k `miniMon`: 디버거 잠금 호출·`mm_getline` 자리·명령 고리 꼴(07 변경 없음; 코딩 전, 2026-10-23)

§470 순위 16 입니다. `netif` 와 같이 x86 `-O3`·m68k `-O2` 차이로 보이는 함수 순서가 있고, 그 밖에 잠금 호출이 빠진 것이 원인입니다.

확인한 사실(§470 기록, 원본 목록 `image.txt`, 원본 `__cstring`, 기호표, 스테이징 머리, 07·Darwin 을 직접 읽음):
- §470 기록: 객체 텍스트 848 B, 원본 범위 [0x404e00e, 0x404e3a8) 922 B 로 −74 B 입니다. L1 사유는 `__TEXT,__text: fail`(33 refs differ, 3 unverified)·`__DATA,__bss: unverified` 입니다.
- 함수 시작(앞 명령이 `rts` 인 자리)과 크기(python):
  - 원본: 56(mm_match)·140(mm_parse)·162(mm_getline)·28(miniMonInit)·202(miniMonLoop)·10·128·94(safe_prf)·16·86(mm_gdb) = 922 B
  - 우리: 56·140·20(miniMonInit)·162(mm_getline)·204·10·128·94·16·18 = 848 B
  - 원본은 `mm_getline` 을 `miniMonInit` 앞에 둡니다. 차이 −74 = (20 − 28) + (204 − 202) + (18 − 86) 입니다.
- 잠금 호출:
  - 원본 `miniMonInit`(0x404e174)은 `bsr 0x404ab32`(`_simple_lock_alloc`) → `movel d0,0x40c2414`(`__kernDebuggerLock`) → `movel d0,sp@-; bsr 0x40018c2` 입니다.
  - 0x40018c2 는 `rts` 하나인 빈 함수이고 `_simple_lock`·`_simple_lock_init`·`_simple_unlock` 의 주소입니다. 0x40018c4(`_simple_lock_try`)는 `moveq #1,d0; rts` 입니다(기호표, 목록).
  - 원본 `mm_gdb`(0x404e352)는 `simple_lock_try(_kernDebuggerLock)` 가 0 이면 `safe_prf` 로 "Couldn't acquire debugger lock:\n"(0x40a8bba)·"exit from monitor and try again.\n"(0x40a8bdb)을 찍고 1 을 돌려줍니다. 0 이 아니면 `miniMonGdb(line)` 뒤 `simple_unlock` 입니다. 07 `mm_gdb` 의 흐름과 같습니다.
  - 원본 전체에서 0x40018c2·0x40018c4 를 부르는 곳은 `miniMon` 의 세 곳뿐입니다(python, 목록 전체). 다른 객체는 잠금을 빈 매크로로 컴파일한 것입니다.
  - 우리 객체에서는 세 호출이 모두 사라졌습니다(`miniMonInit` 20 B, `mm_gdb` 18 B).
- 머리(m68k 스테이징 `m0p480-a1-stage`):
  - 07 `miniMon.c:15` 는 `#import <kern/lock.h>` 입니다. `kern/lock.h:66` 은 `MACH_SLOCKS` 를 `(NCPUS > 1) || MACH_LDEBUG || DRIVERKIT` 로 두고, 생성 머리에서 `NCPUS 1`·`DRIVERKIT 0` 이므로 101–104 행의 빈 매크로(`simple_lock_init(l)` 는 없음, `simple_lock_try(l)` 는 `TRUE`)가 쓰입니다.
  - SDK `mach/m68k/simple_lock.h` 는 `extern void (simple_lock_init)();` 처럼 괄호 이름의 실체 함수 선언만 둡니다(27·30 행). i386 판은 인라인 함수(xchgl)입니다.
  - `kern/lock.h` 줄을 빼면 `miniMon.c` 의 다른 머리를 거쳐 `kern/lock.h` 가 들어오는 길은 없어 보입니다(python 으로 import 를 따라감; 조건부 컴파일은 무시한 사전 점검).
- Darwin 0.1 `kernel/kern/miniMon.c`(07 의 구조 참고본, D024):
  - 42 행이 `#import <mach/machine/simple_lock.h>` 이고, `kern/lock.h` 는 가져오지 않습니다.
  - `miniMonGetLine`(115 행)을 `miniMonInit`(158 행) 앞에 정의합니다.
  - 명령 고리는 227–232 행의 `for(;;) { …; if (miniMonParseLine(miniMonLine) == FALSE) break; }` 꼴입니다.
- `miniMonLoop` 끝:
  - 원본은 `safe_prf`·`mm_getline`·`mm_parse` 세 호출의 인자를 쌓은 채 `addaw #0x14,sp` 로 한 번에 걷습니다.
  - 우리(07 `do { … } while (mm_parse(mm_line));`, 172–175 행)는 `mm_parse` 앞에서 12 B 를 걷고 `movel #mm_line,sp@` 로 자리를 다시 씁니다.
  - 해석(가설): `do … while` 은 조건 앞에 이어 가기 라벨이 생기고, GCC 가 라벨에서 미룬 스택 정리를 내보냅니다. `for(;;)` 안의 `if … break` 꼴에는 그 라벨이 없습니다.
- 컴파일 옵션: x86 `kern/miniMon.c` 는 `-g -O3`, m68k 는 `-g -O2`(`08_build/runs/m3p429-cc2/run.cmd:88`)입니다.
- 07 `kern/miniMon.c`: 241 행, 작성 파일(D024; PROVENANCE 600 행 `authored`)입니다. m68k·x86 스테이징 사본과 SHA-256 이 같습니다(`0f45a11a…`).

가설:
- m68k 원본 소스는 다음과 같았습니다.
  - 잠금 머리로 `mach/machine/simple_lock.h` 를 가져와 m68k 에서 실체 함수를 부릅니다.
  - `mm_getline` 을 `miniMonInit` 앞에 정의합니다.
  - 명령 고리는 `for(;;)` + `break` 꼴입니다.
- x86 원본은 잠금 코드가 없는 꼴이므로, x86 에서 `mach/machine/simple_lock.h`(인라인 xchgl)를 쓰면 달라질 것으로 예상합니다.

방법(`m5_m68k_srcvar.py`, 바탕 `08_build/runs/tools/m0p480-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체 `08_build/runs/m5p470-s1/out/O470__L2_341__miniMon.o`, run `m5p481-m1`; 명세는 무시 대상 `08_build/artifacts/m5p481/spec-miniMon.json`):
- `O`: 97–140 행(주석·`mm_getline`·빈 줄)을 `miniMonInit`(90 행 `void`) 앞으로 옮깁니다.
- `L`: 172–175 행을 `for (;;) { safe_prf(…); mm_getline(…); if (mm_parse(mm_line) == FALSE) break; }` 로 바꿉니다.
- `I`: 15 행을 `#import <mach/machine/simple_lock.h>` 로 바꿉니다.
- `IX`: 15 행을 `#if m68k` / `#import <mach/machine/simple_lock.h>` / `#else m68k` / `#import <kern/lock.h>` / `#endif m68k` 로 바꿉니다(07 본 파일 후보).
- `ALL` = O + L + I, `ALLX` = O + L + IX. O·L·I·IX 단독은 진단입니다.
- 판정(L1 `--place-from-image`): 맞는 꼴은 사유가 `[]` 또는 `['__DATA,__bss: unverified']` 이고, 원본에 없는 미정의 0 이어야 합니다. COMMON·외부 정의는 K 와 같아야 하고, 미정의 기호는 K 에 `_simple_lock_init`·`_simple_lock_try`·`_simple_unlock` 만 더해질 것으로 예상합니다(셋 모두 원본 기호표에 있음).
- 관문: 명령 종료 0, 객체 있음, m68k K 와 `control_ref` 의 canon·obj_sig 같음, x86 K `control_equals_ref` true.
- x86 확인(`m5_x86_srcvar.py`, 바탕 s6l5, 같은 일곱 변형): 07 본 파일 후보는 x86 K 와 canon·머리·절·비 STABS 기호가 같아야 합니다.
- 고르기(미리 정함, 꼴마다):
  - 07 본 파일 후보는 m68k 에서 맞고 x86 에서도 받아들여지는 꼴입니다. 덮어쓰기 후보는 m68k 에서 맞는 꼴입니다.
  - 후보가 하나뿐이면 그 꼴과 자리로 정하고, 둘 이상이면 묻습니다.
  - `#import <mach/machine/simple_lock.h>` 줄은 Darwin 42 행과 같은 글입니다. 이 줄을 쓰는 꼴이 정해지면 D061(Darwin 고지)을 적용할지도 함께 묻습니다.
  - 맞는 꼴이 없으면 기록만 하고, 남은 차이를 함수 안에서 다시 적습니다(고리 꼴이 남으면 다음 절에서 다른 고리 꼴을 시험).
- 구현은 §480.3 과 같습니다(07 본 파일이면 x86 재빌드 접두어 `s6lh`·링크 `s6p481-ln1`, final run `m5p481-a1`, `bss_records` 는 §480 까지 여섯).

### 481.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

제 오류(먼저 밝힘):
- "x86 원본은 잠금 코드가 없는 꼴" 은 틀렸습니다. x86 스테이징 `s6l5-g1a-stage/generated/driverkit.h` 는 `DRIVERKIT 1` 이고 m68k 는 `0` 입니다. x86 에서는 `MACH_SLOCKS` 가 참이라 지금 07 로도 i386 인라인 잠금(`mach/i386/simple_lock.h`)이 컴파일되고, 그 꼴이 x86 원본과 같습니다.
- `safe_prf` 의 차이를 놓쳤습니다. 원본은 `moveb a0@,d1; extbl d1; movel d1,sp@-`(0x404e320–0x404e324)이고, 우리는 같은 자리에서 d0 을 씁니다(객체 0x30c–0x310). 크기가 같아 함수별 크기 표에 드러나지 않았습니다.

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·크기·−74 B, L1 사유 | §470 기록, python | ✅ |
| 열 함수 비교: mm_match·mm_parse·mm_getline 본문·mm_continue·mm_help·mm_reset 같음; miniMonInit·miniMonLoop·mm_gdb 와 함께 `safe_prf` 의 d1/d0 차이 | 원본 목록 99612–99625 행과 객체 목록 265–276 행을 직접 출력 | ✅ 위 제 오류(safe_prf) |
| O 가 앞부분 경계(358 − 196 = 162 B)를 설명함; 소스 순서는 가설 | python 크기 표 | ✅ |
| 패닉 부분은 이미 같음(`do {} while (0)` 유지) | 나란히 비교(43 줄 같음) | ✅ |
| 잠금 주소·별칭·문자열·`__cstring` 기준 | 목록·기호표·원본 바이트(python) | ✅ |
| "세 호출뿐" 은 맞으나 "다른 객체는 모두 빈 매크로" 는 지나침 | 설계 판단 | ⚖️ 문장을 "다른 객체에서는 직접 호출이 없다" 로 줄임 |
| m68k 머리 해석(66·101–111 행)은 맞음 | `kern/lock.h` 81–90·101–104 행 출력 | ✅ |
| `kern/lock.h` 를 빼면 다른 머리로 빈 매크로가 들어오는 길이 없음 | 내 python import 추적(사전 점검)과 같은 결론 | ⚖️ 시험으로 확인 |
| I 에서는 `simple_lock_alloc` 선언이 없어 암묵 `int` 가 됨 → 원형을 지키는 꼴을 더할 것 | m68k `simple_lock.h` 에 선언 없음(24–30 행), `kern/lock.h:111` 에만 있음 | ✅ IP 를 더함 |
| x86 은 `DRIVERKIT 1` 이라 잠금 코드가 있음 → IX 가 꼭 필요하지는 않음 | `driverkit.h` 두 개 출력 | ✅ 위 제 오류; IX 꼴은 대조로 하나만 남김 |
| L 은 시험할 가설이며, 실패하면 다른 고리 꼴을 둘 것 | 설계 판단 | ✅ 실패하면 다음 절 |
| O·L·I 로 safe_prf 차이는 설명되지 않음 | 위 출력 | ✅ 진단 변형 S1 을 더함 |
| Darwin 줄 인용과 명세가 맞음; ALL/ALLX 같은 글 | python | ✅ |
| x86 명령에는 `-fno-omit-frame-pointer` 도 있음 | `08_build/runs/tools/s6l5-g1a.cmd`(검토자 555 행) | ⏭️ x86 비교는 그 명령 그대로 씀(행동 같음) |
| `summary.match` 로 고르지 말 것; 덮어쓰기 갈래는 따로 계획 | §479.1·§480.1 과 같음 | ✅ |

계획 수정(실행 전 고정; 명세 `spec-miniMon.json`·`spec-miniMon-x86.json` 을 고침):
- 변형: K·O·L·I·IP·S1·ALL·ALLP·ALLPS·ALLXP(m68k·x86 같은 열 개)
  - `IP` = I + 20 행 뒤에 `extern simple_lock_t	simple_lock_alloc(void);`
  - `S1`(진단) = `safe_prf` 에서 `va_end(ap);` 를 `prf(…)` 바로 뒤로 옮김(Darwin 0.1 `miniMon.c` 267–268 행: `prf` 바로 뒤 `va_end`)
  - `ALL` = O + L + I, `ALLP` = O + L + IP, `ALLPS` = ALLP + S1, `ALLXP` = O + L + IX + 원형(대조)
- 기대: ALL·ALLP 는 `safe_prf` 를 뺀 아홉 함수가 원본과 같아야 합니다. `safe_prf` 가 남으면 L1 사유에 `__TEXT,__text` 가 남으므로 맞는 꼴이 아닙니다. 그 경우 ALLPS 를 봅니다.
- 고르기: §481 의 규칙에 더해, ALL·ALLP 가 모두 맞으면(원형 유무가 바이트로 구별 안 됨) 묻습니다. `safe_prf` 만 남으면 나머지를 07 에 넣을지(부분 개선)를 묻지 않고 기록만 하고, safe_prf 를 다음 절에서 따로 다룹니다.

### 481.2 변형 시험 결과(2026-10-23)

- m68k run `m5p481-m1`·x86 run `m5p481-xm1`(각 10 명령)은 모두 종료 0 입니다.
- 관문:
  - m68k K 는 `control_ref` 와 canon·obj_sig 가 같습니다(python).
  - x86 K 는 s6l5 객체와 같습니다(`control_equals_ref` true).
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-miniMon-variants-p481-20261023.json`):
  - **ALL·ALLP·ALLPS·ALLXP 는 서로 같은 객체**이고, 사유는 `__TEXT,__text: fail`·`__DATA,__bss: unverified` 입니다.
  - 텍스트는 원본 범위 시작 0x404e00e 에 놓이고, 열 함수 가운데 아홉은 바이트가 같습니다.
  - 남은 것은 `_safe_prf` 의 3 B(객체 오프셋 786·789·791, `moveb a0@,dN; extbl dN; movel dN,sp@-` 의 d0/d1)뿐입니다(L1 `functions` 의 `byte_differences`·`diff_offsets`).
  - 단독 변형:
    - O 는 순서만 고칩니다(사유는 K 와 같음).
    - L 은 `miniMonLoop` 을 고칩니다. `do … while` 꼴이 스택 정리를 앞당긴다는 가설과 맞습니다.
    - I·IP 는 같은 객체이고, `miniMonInit`·`mm_gdb` 의 잠금 호출을 되살립니다.
    - S1(`va_end` 자리)은 K 와 같은 객체로, `safe_prf` 에 영향이 없습니다.
  - 원본에 없는 미정의는 0, COMMON·외부 정의는 K 와 같습니다.
  - I·ALL 은 `assignment makes pointer from integer without a cast` 경고를 냅니다(`simple_lock_alloc` 암묵 선언). IP·ALLP 는 경고가 없습니다(`_log/04.err`·`00.err`·`05.err`·`01.err`).
- **x86**(기록 `09_validation/reconstruction/m5-x86-miniMon-variants-p481-20261023.json`): 열 변형 모두 x86 K 와 canon·머리·절·비 STABS 기호가 같습니다.
- 고르기(§481.1 규칙): `safe_prf` 만 남았으므로 맞는 꼴은 없습니다. 07 은 바꾸지 않고 기록만 합니다.
  - 남은 d0/d1 은 다음 절(§482)에서 ALLP 를 바탕으로 따로 시험합니다.
  - ALLP 의 세 바꿈(O·L·IP)은 그때 함께 07 에 넣을지 정합니다.

## 482. M5-39 세부 계획 — m68k `miniMon` `safe_prf` 의 레지스터 하나(d1/d0) 진단 변형(07 변경 없음; 코딩 전, 2026-10-23)

§481.2 에서 ALLP(O + L + IP)는 `_safe_prf` 의 3 B 를 뺀 모든 바이트가 원본과 같았습니다. 이 절은 그 3 B 만 다룹니다.

확인한 사실(§481.2 기록, 원본 목록, 07·Darwin 을 직접 읽음):
- 원본 0x404e31c–0x404e324 는 `movel a6@(0xfffc:w),a0; moveb a0@,d1; extbl d1; movel d1,sp@-` 이고, 이어서 `addql #1,a6@(0xfffc:w)` 와 `bsr 0x4094aaa`(`_miniMonPutchar`)입니다(`image.txt` 99612–99625 행). 우리는 같은 명령 열에서 d0 을 씁니다.
- 07 `safe_prf`(204–218 행): `static char buf[512]; char *p = buf; va_list ap;` 를 선언하고, `prf` 뒤 `*p = '\0'; p = buf; while (*p) miniMonPutchar(*p++); va_end(ap);` 입니다. `p` 는 `&p` 로 넘기므로 프레임(−4)에 삽니다.
- `miniMonPutchar` 는 07 `kern/miniMonPrivate.h:58` 에서 `extern void miniMonPutchar(int);` 입니다(Darwin 0.1 과 같은 줄).
- Darwin 0.1 `safe_prf`(259–274 행)는 선언 순서가 `va_list ap; static char buf[512]; char *p = buf;` 이고, `va_end` 를 `prf` 바로 뒤에 둡니다. `va_end` 자리는 §481 S1 에서 영향이 없음을 확인했습니다.
- 비슷한 레지스터 하나 차이(`nfs_client` `nfs_attrcache_va` 의 d0/d1)는 §465·§475·§477 에서 소스 꼴로 풀리지 않았습니다. 이번 차이도 소스 꼴로 정해지지 않을 수 있습니다.

방법(`m5_m68k_srcvar.py`, 바탕 `m0p480-a1-stage`, 대조 K = 07 본 파일, `control_ref` = §470 객체, run `m5p482-s1`; 명세 `08_build/artifacts/m5p482/spec-safe_prf.json`). 모든 꼴은 ALLP 에 더합니다(Q0 = ALLP; 명세 글이 §481 ALLP 와 같음을 python 으로 확인).
- `Q1`: `miniMonPutchar((int)*p++);`(명시 변환)
- `Q2`: 선언 순서를 Darwin 처럼 `va_list ap;` 를 맨 앞으로
- `Q3`: `while (*p != '\0')`
- `Q4`: `p = buf; while (*p)` 를 `for (p = buf; *p; )` 로
- 모든 꼴은 원본의 명령 순서(읽기 → 부호 확장 → 넣기 → `p` 증가 → 호출)를 바꾸지 않는 글만 골랐습니다.
- 판정: Q0 은 §481 ALLP 와 canon 이 같아야 합니다(관문). 맞는 꼴은 L1 사유가 `['__DATA,__bss: unverified']` 하나여야 하고, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같아야 합니다.
- x86 확인(`m5_x86_srcvar.py`, 같은 여섯 변형): 07 본 파일 후보는 x86 K 와 비 STABS 로 같아야 합니다.
- 고르기(미리 정함):
  - 맞는 꼴이 하나면 그 꼴과 ALLP 의 바꿈을 함께 07 본 파일 후보로 하고, 자리·고지(`mach/machine/simple_lock.h` 줄은 Darwin 42 행과 같은 글, D061)를 묻습니다.
  - 둘 이상이면 꼴도 묻습니다.
  - 하나도 맞지 않으면, 이 3 B 는 소스 꼴로 풀리지 않은 것으로 기록합니다. 그때 ALLP 를 07 에 넣을지(텍스트 3 B 를 뺀 나머지가 원본과 같아지는 부분 개선)는 사용자에게 묻습니다. 이 경우 `miniMon` 은 OBJECT_MATCH 집계에 넣지 않습니다.

### 482.1 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 남은 3 B(786·789·791)는 모두 `_safe_prf` 안이고 원본은 d1 | §481.2 의 L1 `functions` 출력 | ✅ |
| "3 B 를 뺀 모든 바이트" 는 텍스트에 한정해야 함(bss 는 추정) | L1 사유(`__DATA,__bss: unverified`) | ✅ 결과 문장에서 "텍스트" 로 한정 |
| 07·원형·Darwin 관찰은 맞고, Darwin 은 `(struct tty *)&p` 변환과 `*p++ = '\0'` 도 다름 | Darwin 259–274 행 | ✅ Q5 를 더함 |
| Q0 = ALLP(명세 적용) | §482 작성 때 python 으로 확인 | ✅ |
| Q1·Q3 는 같은 RTL 일 가능성이 큼; Q2·Q4 는 약하지만 해 볼 만함 | 설계 판단 | ⏭️ 값싼 시험이라 그대로 둠 |
| `prf` 정의는 `int`(07 `subr_prf.c:287`)인데 07 `miniMon.c:19` 는 `extern void prf();` 임 | 두 줄을 직접 읽음; Darwin `miniMon.c` 는 `prf` 를 선언하지 않음(grep) | ✅ Q8(`extern int prf();`)·Q9(선언 없음)를 더함 |
| 안에서 검사하는 고리, `(signed char)` 변환도 후보 | 설계 판단 | ✅ Q6·Q7 을 더함 |
| `char` 매개변수 원형은 진단으로만; 머리 시험은 지금 도구로 못 함 | `m5_m68k_srcvar.py:13`(한 파일만 바꿈) | ✅ 이번에는 넣지 않음 |
| §477 은 반증 자료일 뿐 처방은 아님 | §477.2 기록 | ✅ |
| 관문을 명시하고, 07 본 파일 후보는 두 아키텍처 모두 통과한 꼴만; `summary.match` 로 고르지 말 것 | §479.1·§480.1 과 같음 | ✅ |
| 실패하면 "시험한 꼴이 실패" 로만 적을 것; 새 경고가 없어야 함 | 설계 판단 | ✅ 아래 고정 |

계획 수정(실행 전 고정): 변형 = K·Q0–Q9(m68k·x86 같은 열한 개).
- `Q5` = `*p++ = '\0';`, `Q6` = `for (;;) { if (!*p) break; miniMonPutchar(*p++); }`, `Q7` = `miniMonPutchar((signed char)*p++)`, `Q8` = `extern int prf();`, `Q9` = `prf` 선언 줄 삭제.
- 관문: 모든 명령 종료 0, 객체 있음, m68k K 와 `control_ref` 의 canon·obj_sig 같음, Q0 와 §481 ALLP 객체(`08_build/runs/m5p481-m1/out/P481__ALLP.o`)의 canon·obj_sig 같음, x86 K `control_equals_ref` true.
- 맞는 꼴: m68k 사유 `['__DATA,__bss: unverified']` 하나, 원본에 없는 미정의 0, COMMON·외부 정의가 K 와 같고, 컴파일 경고가 Q0 보다 늘지 않음. 07 본 파일 후보는 x86 에서도 K 와 비 STABS 로 같아야 합니다.
- 실패하면 "Q1–Q9 꼴로는 풀리지 않음" 으로만 기록합니다.

### 482.2 변형 시험 결과(2026-10-23)

- m68k run `m5p482-s1`·x86 run `m5p482-xs1`(각 11 명령)은 모두 종료 0 이고, 컴파일 경고는 모두 0 줄입니다(`_log/*.err` 의 `warning` 수).
- 관문:
  - m68k K 는 `control_ref` 와 obj_sig 가 같습니다.
  - Q0 은 §481 `P481__ALLP.o` 와 canon·obj_sig 가 같습니다.
  - x86 K 는 `control_equals_ref` true 입니다.
- **m68k**(기록 `09_validation/reconstruction/m5-m68k-safe-prf-variants-p482-20261023.json`):
  - **Q8(`extern int prf();`)·Q9(`prf` 선언 없음)는 같은 객체이고, 사유가 `['__DATA,__bss: unverified']` 하나입니다.** 텍스트 바이트 차이는 0 입니다(L1 `functions`).
  - 원본에 없는 미정의는 0, COMMON·외부 정의는 K 와 같습니다.
  - Q1–Q7 은 Q0 과 같은 객체입니다(`_safe_prf` 3 B 그대로).
  - 해석: `prf` 의 정의는 `int`(07 `bsd/kern/subr_prf.c:287`)인데 07 `miniMon.c:19` 는 `void` 로 선언했습니다. 값을 내는 호출이면 d0 이 그 호출의 결과 자리로 잡혀, 뒤의 부호 확장 값이 d1 로 갑니다. 이 기제는 시험 결과로 맞춘 해석입니다.
- **x86**(기록 `09_validation/reconstruction/m5-x86-safe-prf-variants-p482-20261023.json`): 열한 변형 모두 x86 K 와 canon·절·비 STABS 기호가 같습니다.
- 고르기(§481.1·§482.1 규칙):
  - 07 본 파일 후보는 ALLP + Q8, ALLP + Q9 이고, §481 의 I/IP(암묵/원형 `simple_lock_alloc`)도 바이트로 같습니다.
  - 꼴(선언 유무)과 자리, `#import <mach/machine/simple_lock.h>` 줄(Darwin 42 행과 같은 글)의 고지를 사용자에게 묻습니다.

사용자 결정 D098(2026-10-23): 선언 꼴 "둘 다 선언 (Recommended)"(ALLP + Q8: `extern simple_lock_t simple_lock_alloc(void);`·`extern int prf();`), 고지 "작성(D027)으로 둠 (Recommended)", 자리는 07 본 파일.

### 482.3 D098 구현 계획(07 본 파일 `miniMon.c` + x86 전체 재빌드 s6lh; 코딩 전, 2026-10-23)

§480.3(§480.4 수정 포함)의 절차를 따르고, 덮어쓰기는 없습니다. 각 단계가 실패하면 멈추고 보고합니다.
0. 기준 고정: `08_build/runs/m5p482-s1/out/P482__Q8.o`(SHA-256 `68a2a231…`, 변형 기록과 대조)를 REF 로 씁니다.
1. 07 편집(`kern/miniMon.c`; 고치기 전 파일을 `08_build/artifacts/m5p482/miniMon.c.main.before` 로 먼저 옮겨 둠):
   - 변형 Q8 의 바꿈(O·L·I·원형·`extern int prf();`)을 그대로 넣습니다.
   - 표시를 붙입니다.
     - 옮긴 `mm_getline` 주석 앞에 `/* plan 482 (D098): defined here, as in the m68k original */` 한 줄을 둡니다.
     - `#import <mach/machine/simple_lock.h>`, `extern int prf();`, `simple_lock_alloc` 원형, `for (;;) {` 줄 끝에 `/* plan 482 (D098): … */` 를 붙입니다.
   - python 으로 주석을 뺀 토큰이 Q8 과 같은지 확인합니다(Q8 은 고치기 전 파일에서 다시 만들고, run 의 스테이징 사본과도 대조). 파일은 241 → 245 행이 됩니다(Q8 244 행 + 표시 줄 하나).
2. x86 전체 재빌드 s6lh(접두어 미사용)와 check 관문(§480.3 과 같음)을 거칩니다.
3. prefixdiff s6lg↔s6lh(plan 482): 스테이징 차이는 `src/kern/miniMon.c` 하나, 키·명령 차이 없음, `sha_differ_not_rid_only` 는 `[]` 또는 `['x86-miniMon']`, 비 STABS 같음.
4. 링크 `s6p482-ln1` → `l2_compare.py` → `cmp`.
5. `stage_m68k.py`: `X86[482] = 's6lh'`, `EXCEPTS[482] = dict(EXCEPTS[480], **{'x86-miniMon': …})`, 문서 줄 셋. `--plan 482 stage m0p482-a1-stage`·`--plan 482 x86gate 08_build/artifacts/m5p482/x86gate`; `m0p480-a1-stage` 와의 파일 항목 차이는 `src/kern/miniMon.c` 하나.
6. final(run `m5p482-a1`): 기대 사유 `['__DATA,__bss: unverified']`, `bss_records` 는 §480 까지 여섯. zerofill 결과를 `09_validation/reconstruction/m5-m68k-p482-zerofill-20261023.json` 으로 복사하고 SHA-256 을 대조합니다.
7. 기록:
   - PROVENANCE 600 행(`authored`)을 그 자리에서 갱신합니다(changes 칸·새 파일 SHA-256; Darwin 42 행과 같은 import 줄은 D027 로 적음).
   - MODIFICATIONS 한 행, DECISIONS D098, diff `06_reconstruction/evidence/x86-miniMon-plan482.diff`, `x86-miniMon.md` 절.
   - `functions.tsv` 의 miniMon 인용(1841–1848 행의 `07_kernel/src/kern/miniMon.c:N` 과 같은 행의 `edited file :N`)을 옛 줄 내용으로 새 줄을 찾아 옮깁니다(하나씩만 맞는지 assert, 파일 행 수 그대로).
   - 집계: "코드 검증 + bss 추정" 24 → 25, 코드 검증 202 → 203/208(97.6%), 코드 차이가 남은 객체 6 → 5(nfs_client, tty, callout, kdp_udp, swapfs)입니다(python).

### 482.4 교차검토(codex `gpt-6.1-sol`) 판정과 계획 수정

| 검토 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 절차·관문은 §480.3–480.5 를 이어받아 빠진 것 없음; 4 는 `l2_link.py prepare s6p482-ln1 s6lh` → kr_run → `l2_compare.py` → `cmp` | §480.3·§480.4 와 나란히 읽음 | ✅ |
| Q8 에는 `for (;;) {` 가 셋(mm_getline·패닉 입력·명령 고리)이라 표시 자리가 모호함 | Q8 스테이징 사본 grep(아래 출력) | ✅ 명령 고리(`safe_prf("%s> ", prompt);` 바로 앞 줄)만 겨냥하고, 바꿀 글이 한 번만 나오는지 assert |
| 241 → 244 → 245 행, include·`prf`·원형 줄이 Q8 에 있음 | python(변형 적용) | ✅ 구현에서 다시 확인 |
| `functions.tsv` 인용은 1841–1848 행의 명시 경로 여덟뿐이고 "edited file" 꼴은 없음 | 그 행들에서 `edited file` 0 건(grep) | ✅ 새 번호는 구현에서 줄 내용으로 정함 |
| `bss_records` 여섯, 기대 사유 bss 하나 | §480.5·`l1-m5p482-s1-Q8.json` | ✅ |
| `stage_m68k.py` 480 항목 위치, 문서 줄 9·12·21 | grep | ✅ |
| 집계 25·203/208(97.6%)·5 | python | ✅ final 통과 조건부 |

### 482.5 D098 구현 결과(2026-10-23) — 기록 `09_validation/reconstruction/m5-m68k-p482-final-20261023.json`

- 07 편집:
  - 본 파일 `kern/miniMon.c` 는 241 → 245 행입니다.
  - 주석을 뺀 토큰이 변형 Q8 과 같습니다. Q8 은 고치기 전 파일에서 다시 만들었고, run 의 스테이징 사본과도 같습니다(python).
  - 명령 고리 표시는 `safe_prf("%s> ", prompt);` 바로 앞의 `for (;;) {` 에만 붙였습니다(바꿀 글이 한 번만 나오는지 assert).
  - 고치기 전 파일은 `08_build/artifacts/m5p482/miniMon.c.main.before` 이고, REF `P482__Q8.o` 의 SHA-256 은 변형 기록과 같습니다.
- x86 전체 재빌드 s6lh:
  - 명령 804 개 모두 종료 0, 402 행이 1–402 로 이어지고 모두 기준과 같거나 기대대로, problem·deps 차이 0 입니다(python).
  - prefixdiff s6lg↔s6lh(python assert 통과): 스테이징 차이는 `src/kern/miniMon.c` 하나, `sha_differ_not_rid_only` 는 `['x86-miniMon']`(STABS 만)입니다.
  - 링크 `s6p482-ln1` 은 `identical file: True` 이고 `cmp` 로 원본과 같습니다(공통 기호 417 / 417).
- m68k:
  - `stage_m68k.py` 에 `X86[482] = 's6lh'`·`EXCEPTS[482]`(`x86-miniMon`)를 등록하고 문서 줄 셋을 고쳤습니다(536 → 537 행, `wc -l`).
  - `--plan 482 stage m0p482-a1-stage` 와 `--plan 482 x86gate`(s6lh 일곱 모두 같음)를 거쳤고, `m0p480-a1-stage` 와의 파일 항목 차이는 `src/kern/miniMon.c` 하나입니다.
  - final run `m5p482-a1`: REF 와 canon·머리·절·기호가 같고, L1 사유는 `__DATA,__bss: unverified` 하나, 원본에 없는 미정의는 0 입니다.
  - zerofill(`m5-m68k-p482-zerofill-20261023.json`, 복사본 SHA-256 같음)은 reference-inferred [0x40b373a, 0x40b39ba) 640 B 입니다. 512(`buf`) + 128(`mm_line`) = 640 이고(python), 이전 여섯 기록의 후보와 겹침 0 입니다.
- 집계(python):
  - m68k OBJECT_MATCH 는 177(+ 명시 배치 `ufs_alloc` 1), "코드 검증 + bss 추정" 은 25 입니다. 공통부 208 중 203(97.6%)이 코드 검증되었습니다.
  - 코드 차이가 남은 객체는 5 개입니다(nfs_client, tty, callout, kdp_udp, swapfs).
- 기록:
  - PROVENANCE 600 행 그 자리 갱신(1099 행, 중복 0)
  - MODIFICATIONS 641 행, DECISIONS D098, diff `06_reconstruction/evidence/x86-miniMon-plan482.diff`, `x86-miniMon.md` 에 절 덧붙임
  - `functions.tsv` 의 miniMon 인용 여덟을 줄 내용으로 옮김(파일 4763 행 그대로, `wc -l`)
