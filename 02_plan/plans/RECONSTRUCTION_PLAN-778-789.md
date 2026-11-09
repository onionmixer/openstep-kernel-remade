# 커널 소스 복원 작업계획 — 보관 §778–789

`02_plan/RECONSTRUCTION_PLAN.md` 의 §778–789(M6 확인, M7 링크(D178–D180), 전체 재빌드, M8 QEMU 부팅, 문서 반영; §780 은 절 제목이 없고 §779 안의 결과로 적혀 있음)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-09, D026 방식, 사용자 지시 “RECONSTRUCTION_PLAN.md 문서에서 진행이 완료된 내용은 기존의 규칙처럼 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 778. M6(DriverKit·ObjC) 확인과 M7(링크) 계획 (사용자 지시 "M6(DriverKit·ObjC)과 M7(링크).", 코딩 전, 2026-11-08; 07·상태표·도구·실기 불변)

### 778.1 M6 — m68k 에는 재구성할 대상이 없다(수치는 python)
- 원본 `03_original/m68k/binaries/mach_kernel`(832196 B, SHA-256 `dff6c51c…`) 의 Mach-O 적재 명령을 직접 읽었다: 세그먼트 `__PAGEZERO`·`__TEXT`(절 `__text`·`__cstring`·`__const`)·`__DATA`(절 `__data`·`__bss`·`__common`)뿐이며 `__OBJC` 세그먼트·절과 `__LINKEDIT` 세그먼트가 없다. 심볼 3809 개(전부 외부, 지역 0)에서 정규식 `objc|OBJC|msgSend|^_?IO|^_?NX|\.objc|_class_|IOKit|driverkit`(대소문자 무시)에 걸린 것은 `_ioaccess`·`_ioctl`·`_kern_serv_load_objc` 3 개이며 모두 C 이름이다.
- `06_reconstruction/m68k-text-objects.tsv` 에서 `objc`=1 인 x86 객체 85 개 중 m68k 심볼·본문이 있는 것은 5 개(`swapgeneric`·`km`·`kmDevice`·`SCSIDiskKern`·`SCSIGenericKern`)이고, 그 m68k 본문 주소는 이미 M4/M5 객체가 덮는다(`__text` 틈 0, 778.2).
- 결론: M6 에서 새 파일·객체를 만들지 않는다. 한계: 원본 m68k 바이너리에 ObjC·DriverKit 심볼·절이 없다는 관찰이며, x86 객체 이름 대응이 m68k 번역 단위·구현 언어의 동일성을 증명하지는 않는다.

### 778.2 M7 입력 사실(전부 python; 파일 `scratch/p778/{order,symclosure,common_order,common_order2,verify_codex1,verify_codex2,verify_cstring}.py`, 데이터 `objs.json`·`objpaths.json`)
- 객체 **296** = M4 76(`tty_pty` 포함) + M5 계열 207(M5 204 + 다시 만든 `R` 3: `kern_exec`·`mach_process`·`ns_timer`; 겹치는 M5 `tty_pty` 제외) + 자료 단위 13. 296 파일이 모두 있고 SHA-256 이 기록과 같으며 합계 9254968 B. 텍스트 객체 283.
- 판정(python 집계): `OBJECT_MATCH` 244(M4 54·M5 175·`R` 2·`D` 13), `NOT_MATCH` 52(M4 22 "코드+bss 추정"; M5 29 = bss 만 미검증 26 + `ufs_alloc`(const 만 미검증) 1 + `nfs_client`(텍스트 3 B 차이) 1 + `swapfs`(텍스트 3 B 차이 + const·bss 미검증) 1; `R` 1 = `ns_timer`(bss 미검증)). 텍스트 바이트가 다른 객체는 `nfs_client`·`swapfs` 둘뿐이다.
- 원본 절표: `__text` 0x4000310 + 0xa5a6e(= 678510), `__cstring` 0x40a5d7e + 0x70f8(= 28920), `__const` 0x40ace76 + 0xaec(= 2796), `__data` 0x40ad964 + 0x5818(= 22552), `__bss` 0x40b317c + 0x24cc(= 9420), `__common` 0x40b5648 + 0x142c0(= 82624). 진입 `LC_UNIXTHREAD` pc = 0x4000310 = `_start`. CPU subtype 1(`m4p770-ld-1` 산출물은 subtype 2). 헤더 28 + 적재 명령 688 = 716 B, `__text` 파일 오프셋 784(= 0x310), 사이 68 B 는 모두 0.
- `__text`: 283 객체가 주소순으로 틈·겹침 0, 합 678510 B. 텍스트 객체 이웃 사이에서 `__data`(132)·`__const`(23)·`__bss`(50) 주소가 거꾸로 가는 곳 0(주소가 배정된 객체만). `__data` 145 객체 합 22511 B(틈 `[1,1,1,1,1,36]` = 41 B). `__bss` 50 객체 합 9420 B(틈 0, 추정 배치 포함).
- `__const`: 입력 **25** 객체 합 2796 B(= 절 크기). 주소가 배정된 23 객체는 2785 B, 미배정 `swapfs` 7 B(`73776170667300`)·`ufs_alloc` 4 B(`00000004`). 원본 틈 [0x40acfdb, +11) 의 바이트가 `7377617066730000000004` 로 이 둘의 연결과 정확히 같다(python 비교). 객체 전체 판정은 승격하지 않는다.
- `__cstring`: 객체 163 개 합 29479 B. 같은 문자열을 처음 나온 순서로 한 번만 남기면 28920 B 이고 문자열 집합이 원본과 같다(입력에만 있는 것 0·원본에만 있는 것 0). 자료 단위의 위치를 바꿔 본 조합 672(= 3·1·16·7·2, 문자열이 있는 단위 5 개 `fd_global`·`in_proto`·`ioconf`·`uipc_proto`·`vfs_conf`) 중 합친 결과가 원본 `__cstring` 전체와 바이트가 같은 것이 **32**: `fd_global` 은 `fd_driver` 뒤, `vfs_conf` 는 `vfs_bio` 뒤, `in_proto` 는 `in_pcb` 뒤, `uipc_proto` 는 `uipc_mbuf`·`uipc_pipe` 뒤(둘 다 가능), `ioconf` 는 16 위치 모두 가능.
- 자료 전용 단위 13 개의 링크 위치는 하나로 정해지지 않는다: 자료·상수·bss 주소 단조성을 만족하는 텍스트 객체 사이 위치 수 = `conf` 3·`counters` 6·`fd_global` 3·`in_proto` 1·`init_sysent` 1·`ioconf` 16·`param` 3·`scsiconf` 2·`tty_conf` 1·`ufs_tables` 1·`uipc_proto` 7·`vers` 16·`vfs_conf` 2. 텍스트 주소와 자료 주소를 한 키로 섞어 정렬하면 `__data` 역전이 1 곳 생긴다(그 방식은 쓰지 않는다).
- 심볼 닫힘: 정의 이름 3195·중복 정의 0·COMMON 554 이름(최대 크기 합 81224 B). 정의도 COMMON 도 없는 미정의 이름은 **73 = `__mh_execute_header`(링커 생성, 원본에서 `N_ABS|N_EXT` 값 0x4000000) + 원본 `__common` 이름 72**. 이 72 에 객체가 아예 언급하지 않는 `_bootp` 를 더한 **73 개의 원본 `__common` 이름이 우리 객체 집합에 COMMON 선언으로 없다**. 원본 `__common` 심볼은 613 개이고 객체의 COMMON 554 중 540(합 80970 B)이 그 범위에, 14 개(합 254 B: `_tthiwat`·`_tthog`·`_ttlowat`·`_bufpages`·`_nbuf`·`_etherbroadcastaddr`·`_nmbclusters`·`_fifoinfo`·`_hz`·`_ndquot`·`_tick`·`_time`·`_ncallout`·`_ncsize`)는 원본에서 `__data` 정의다(다른 객체가 정의). 73 개의 원본 주소 간격 합 1604 B 는 변수 크기의 합이 아니다(`82624 − 80970 = 1654`, 차 50 B).
- 원본 `__common` 의 형태: 심볼 `n_desc` 3809 개 모두 0(크기·정렬이 심볼에 없음); 주소 606 개가 4 의 배수, 7 개가 2 mod 4(전부 4 정렬이 아님); 전체 심볼표가 이름순(내림 0); 주소순으로 훑으면 이름순 증가 구간이 87 개(이름이 줄어드는 곳 86).
- COMMON 배치 가설 시험(전부 python): (ⓐ) 객체를 텍스트 순서로 놓고 **COMMON 선언만** 처음 만난 순서로 배정 → 원본 주소와 거꾸로 가는 이웃 81 곳(14 개 `__data` 정의 이름을 빼고 센 값; 이를 넣으면 88). 객체 안 이름순을 더해도 같다 — 우리 객체의 COMMON `nlist` 가 이미 이름순이다(COMMON 이 있는 238 객체·2295 항목에서 객체 안 이름 감소 0). (ⓒ) "증가 구간 하나 = 객체 하나" 라는 조건은 구간 87 개 중 37 개(후보 객체 없음 32·뒤로 가야 함 5)에서 불가능하나, 이는 구간 경계가 객체 경계와 같을 필요가 없으므로 **일반 가설의 반증이 아니다**. (ⓓ) **크기 0 미정의 참조도 처음 만난 것으로 치는** 배정(크기는 나중에 채움) → 612 이름, 거꾸로 가는 이웃 15–17 곳(자료 전용 단위를 첫/마지막 가능 위치에 넣는 두 경우), 순서 유지 최장 부분수열 574–576, 원본과 앞 34 이름 정확히 일치, 원본 첫 구간 21 이름이 모두 `M4:locore` 의 크기 0 미정의 참조에서 처음 나오고 순서가 같다. (ⓓ)는 **시험할 가설**이지 규칙의 확인이 아니다(남은 역전은 재구성 객체와 원래 객체의 참조 집합 차이나 다른 규칙으로 설명해야 함).

### 778.3 실험 설계(순서대로; 각 단계 결과를 보고 다음을 정함)
- **P0 (오프라인·python)** 새 도구 `10_tools/reconstruction/m7_m68k_link.py` 의 `spec`·`check`: 296 객체의 경로·SHA-256·절 크기와 위 수치를 `spec.json` 으로 고정. 링크 순서는 텍스트 객체 283 개의 텍스트 주소순을 뼈대로 하고, 자료 전용 단위는 **허용 위치 집합**(위 수)으로 두며 `__cstring`·COMMON 최초 만남 제약을 더해 후보를 줄인다. 하나로 못 정하면 후보 순서를 모두 실험 변수로 둔다. ld 를 부르지 않는다.
- **P1 (실기, 링커 규칙 탐침 — 전체 링크보다 먼저)**: `as -arch m68k` 로 만든 작은 객체들로 확인할 것 — (1) COMMON 배치: 크기 0 미정의 참조 → 뒤 객체의 COMMON 선언(ⓓ); 객체 순서 교환·COMMON 크기 변경·무관 심볼 추가를 분리; 소스 순서가 아니라 조립 후 실제 `nlist` 순서 기록; 직접 최종 링크 대 `ld -r` 중간 링크; `-d` 의 실제 의미; 같은 이름의 서로 다른 크기·정렬; 정의가 COMMON 을 이기는 경우(14 개)의 크기·정렬 불일치 경고. (2) 형태: 진입 심볼을 가진 최소 실행 파일의 헤더(CPU subtype 1 이 되는 `ld` 옵션/`-arch` 조합)·텍스트 시작 오프셋 0x310 이 되는 조건(헤더 패딩 68 B 는 `-segalign`·`-headerpad` 등 후보; NeXTMach `conf/Makefile.NeXT:30` 의 `LDFLAGS=-p -e _start -segaddr __TEXT ${RELOC} -segalign 4` 는 **옵션 후보일 뿐 원본 빌드 사실이 아님**); `__mh_execute_header` 가 참조될 때만 생기는지·값·타입. (3) 미정의가 있을 때 종료 코드·진단·출력 파일 유무. (4) 문자열 합침 규칙(`__cstring` 중복 제거·순서)과 `__const` 합침.
- **P2 (실기, 전체 링크 1차 — 진단)**: 296 객체(P0 순서). 미정의 73 개 처리는 P1(3) 결과로 정한다. 명령 꼴(`m4p770-ld-1` 선례): `/bin/ld -arch m68k -static -seg1addr 0x4000000 -e _start -o stage/mach_kernel.sys …` 후 `/bin/strip -x`. 입력은 `src/` 아래 서로 다른 이름으로 복사(인자 허용 문자 `[A-Za-z0-9_./=+,:@%-]`). `kr_run.py` 는 명령이 실패해도 다음 명령을 계속 실행하고(`:245–253`) `collect` 는 종료 코드가 0 이 아니거나 EXPECT 가 없으면 거부한다(`:326–345`): 예상 실패 탐침은 성공 산출물을 요구하는 run 과 분리하고, 링크 실패 뒤 `strip` 을 무조건 실행하지 않는다. 미정의를 허용해 얻은 결과는 **진단용**이며 배치 비교 대상으로 쓰지 않는다(누락 COMMON 을 나중에 넣으면 주소와 텍스트 재배치가 달라짐).
- **P3 (73 이름의 정의)**: 대상 = 링커 생성 `__mh_execute_header` 를 뺀 **원본 `__common` 73 이름**(참조되는 72 + 미참조 `_bootp`). 한 새 객체에 모으거나 링크 끝에 붙이면 COMMON 순서가 보존된다는 보장이 없으므로 P1 결과로 정한다. 간격을 크기로 쓰는 것도 미검증(정렬 채움 가능). 링크를 통과시키려는 임시 스텁·임의 크기 정의를 최종 복원으로 채택하지 않는다. 07 에 새 소스·변경이 필요하면 소유 파일 증거(바이트로 정해지는 것과 아닌 것을 분리)를 갖고 **사용자 결정으로 올린다**.
- **P4 (비교, 층별)**: (A) ld 오류·미정의·중복·경고 0 (B) 세그먼트·절 주소·크기·정렬·flags·파일 오프셋, CPU subtype, 헤더 (C) 심볼표: 이름→주소뿐 아니라 타입·섹션·중복·추가/누락(원본 외부 심볼 3809 개, `__mh_execute_header` 포함) (D) `__text`·`__cstring`·`__const`·`__data` 전체 바이트 비교(차이 위치를 객체로 되돌려 대응; 예상 차이는 `nfs_client`·`swapfs` 각 3 B 와 미검증 41 B 주변·bss 추정) (E) `LC_UNIXTHREAD` flavor·count·전체 상태 (F) 파일 전체 바이트(원본에는 `__LINKEDIT` 세그먼트가 없으므로 심볼표·문자열표·패딩 포함). `strip -x` 전·후 파일을 모두 보존. 비교기는 `l2_compare.py` 가 리틀엔디언 고정(`:32–74`)이라 재사용할 수 없고 빅엔디안 비교기를 새로 둔다. 어느 층도 "원본 소스와 같다" 의 증명이 아니라 바이트 일치만 뜻한다.

### 778.4 하지 않는 것·한계
- 이 단계에서 07·상태표·도구·실기 실행을 바꾸지 않았다. 커밋 안 함. GCC 2.7 호환(`08_build/GCC27_COMPATIBILITY.md:45–60`)은 이 링크 실험으로 완료 처리하지 않으며, P3 에서 소스를 채택하면 파일·함수별 `PROVENANCE.tsv`·고지를 관문에 둔다.
- 링크가 된다는 것(A)만으로는 텍스트 바이트 일치(D)가 보장되지 않는다: `__common` 주소가 다르면 COMMON 을 참조하는 텍스트의 절대 주소 바이트가 달라진다. "규칙을 모르면 예측할 수 없다" 는 표현은 쓰지 않는다 — 원본 주소는 관측되어 있고, 순서 지정으로 강제하는 실험도 가능하나 그것은 원래 규칙의 발견과 구분해 기록한다.
- 소유 불명 41 B(`__data`)와 bss 추정 객체의 bss 자리는 링크 결과가 원본과 맞을 때에만 "자리 확인" 으로 센다. M8(QEMU 부팅)·M9(회귀)는 범위 밖.

### 778.5 codex 계획 검토 판정표(2026-11-08; 작업 `k4hs3skzh`; 모든 값은 내가 python 으로 다시 구하거나 파일을 열어 확인)
내가 틀렸던 것(먼저): ① 초안 "역전 88" 은 `__data` 정의 14 개를 넣은 값 — 뺀 값 81 ② "미정의 73 + 헤더" 는 잘못 — 73 은 헤더를 포함하고 원본 `__common` 이름은 72, `_bootp` 가 따로 있어 "객체에 없는 원본 `__common` 이름" 이 73 ③ M5 NOT_MATCH 원인을 "bss 27 + 텍스트 차이 둘" 로 뭉쳤음(실제 bss 만 26·`ufs_alloc` const 만 1·`nfs_client`·`swapfs`) ④ const 를 23 객체로만 적음(입력 25 객체 2796 B) ⑤ 증가 구간=객체 가설의 기각을 일반 가설의 반증처럼 썼고, "규칙을 모르면 예측 불가" 는 과한 표현 ⑥ 자료 전용 단위 위치를 하나의 순서로 놓으려 했음 ⑦ 합·차를 python 없이 계산한 것을 사용자가 지적(재계산해 전부 일치 확인) ⑧ 순서 분석을 "백그라운드로 돈다" 고 보고했으나 명령 앞의 `cat` 이 입력을 기다려 한 번도 실행되지 않았음(4 시간 넘게 몰랐음).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 296 객체·283 텍스트·합 9254968 B·해시 전부 일치 | `order.py`·`objpaths` 점검: 누락 0·해시 불일치 0·합 9254968 | ✅ |
| 244/52, 판정표(M4 54/22, M5 175/29, R 2/1, D 13/0) | `Counter` 출력: M4 54/22, M5 175/29, R 2/1, D 13 | ✅ |
| M5 29 = bss 26 + `ufs_alloc` + `nfs_client` + `swapfs` | `verify_codex1.py`·재집계: bss 만 26, 나머지 세 개 이유 목록 출력 | ✅ (내 초안 오류) |
| 텍스트 678510 B 틈·겹침 0, 역전 0, data 22511·틈 `[1,1,1,1,1,36]`, bss 9420 | 앞서 실행한 집계 출력과 같음 | ✅ |
| const 25 객체 2796 B, 미배정 `swapfs` 7·`ufs_alloc` 4, 틈 바이트 `7377617066730000000004` | 출력: `unplaced [('M5:swapfs',7),('M5:ufs_alloc',4)]`, 틈 11 B 16진 일치, 두 객체 const 16진 연결과 같음 | ✅ |
| 미정의 73 = 헤더 + 72; `_bootp` 미참조; 원본 `__common` 누락 73 | 출력 `unresolved 73 incl header True orig-common among them 72`, `_bootp referenced? 0`, `extra beyond unresolved ['_bootp']` | ✅ |
| COMMON 554/540/14, 80970 B·254 B, 간격 1604 B | 앞서 출력(540, 80970, 254, 1604, 차 50) | ✅ |
| 이름순 증가 구간 87(감소 86) | `common_order.py`/구간 계산 출력 87·86 | ✅ |
| ⓐⓑ 81(14 제외), nlist 가 이미 이름순(238 객체·2295 항목·감소 0) | `common_order2.py` 81/81; `verify_codex1.py` 238·2295·0 | ✅ |
| ⓒ 37 = 후보 없음 32 + 뒤로 5, 구간=객체 조건은 과함 | 재집계 출력 `no candidate 32 backwards 5`; 논리: 최대 증가 구간은 객체 경계를 넘어 이어질 수 있음 | ✅ |
| 미정의 포함 최초 만남: 612 이름·역전 18·LIS 571·앞 34 일치·첫 21 이름 `locore` | 내 재구현: 612 이름, 역전 17(첫 위치)/15(마지막 위치), LIS 574/576, 앞 34, 첫 21 전부 `M4:locore`·순서 같음 | ⚖️ 방향은 맞고 수치는 자료 전용 단위 위치에 따라 다름(codex 18·571 과 정확히 같지는 않음) → 범위로 기록 |
| 원본 `n_desc` 전부 0, 606 개 4 배수·7 개 2 mod 4 | 출력 `Counter({0: 3809})`, `{0: 606, 2: 7}` | ✅ |
| 원본에 `__LINKEDIT` 없음, 헤더 패딩 68 B 전부 0, CPU subtype 1 대 ld-1 산출물 2 | 적재 명령 목록 직접 출력, `set(b[716:784])=={0}`, subtype 1; `m4p770-ld-1/out/h1.out` `cpu (6, 2)` | ✅ |
| `conf/Makefile.NeXT:30` 의 `-segalign 4` | `01_resources/upstream/nextmach/mk-108.1/conf/Makefile.NeXT:30` 열람: `LDFLAGS=-p  -e _start  -segaddr __TEXT ${RELOC}  -segalign 4` | ✅ (옵션 후보로만) |
| cstring 28920·집합 동일·조합 672·32 일치와 위치 제약 | `verify_cstring.py` 출력 그대로(28920·`True`·672·32, 위치 제약 5 건) | ✅ |
| 자료 전용 단위 위치 수(`ioconf`·`vers` 16, `uipc_proto` 7) | `verify_codex2.py` 출력(표) | ✅ |
| 텍스트·자료 혼합 키 정렬은 자료 역전을 만든다 | 출력 `data inversions 1` | ✅ |
| `kr_run.py` 가 실패 후에도 계속 실행(`:245–253`), `collect` 거부(`:326–345`) | 해당 줄 열람: 반복문이 모든 명령을 쓰고 상태 기록, `need(rc == '0'…)`·EXPECT 검사 | ✅ |
| `l2_compare.py` 리틀엔디언 고정(`:32–74`) | 열람: `struct.unpack_from('<7I'…)` 등 `<` 형식 | ✅ |
| `GCC27_COMPATIBILITY.md:45–60` 완료 판정 | 열람: 완료 판정 1–5 항 | ✅ |
| `order.py:49`·`symclosure.py:41`·`common_order.py:38` 이 JSON 을 덮어씀 | 읽기 전용 검토에서 실행하면 안 된다는 지적: 내 스크립트가 `objs.json` 등을 쓰는 것 확인 — 내 작업 파일이라 영향 없음 | ✅ (정보) |
| M6 관찰 수치·원본 절·진입점 정확 | 3 개 이름·85/5·절표 출력 | ✅ |

남은 한계: ① (ⓓ)는 가설이며 실제 `ld` 규칙은 P1 에서 확인 ② 자료 전용 단위 13 개의 링크 위치는 문자열·COMMON 제약으로도 일부만 정해짐 ③ 헤더 패딩 68 B 의 생성 원인 미정 ④ 모든 단위가 바이트 일치만 증거이며 원본 소스와 같다는 증명이 아님.

### 778.6 P1 탐침의 구체 설계 (codex 검토 반영, 코딩 전, 2026-11-08)
추가 사실(python·열람): 실기 `/bin/ld`(SHA-256 `4c6dae19…`, 853564 B)·`/bin/as`(`ff2fa29a…`)·`/bin/strip`(`80cb973b…`)은 m68k VM 의 것과 해시가 같다(`08_build/toolchains/real-cross-20261009/sha256-real-vs-m68kvm.json`). 입력 296 객체의 CPU subtype 은 295 개가 1, `M4:fpsp` 하나만 2(run `m4p770-a2` 의 `cc -arch m68k … -DASSEMBLER … -c fpsp.s`); 원본 커널은 1. NeXT GCC 는 COMMON 을 `.comm NAME,ROUNDED` 로 낸다(`scratch/p725/gccsrc/config/m68k/m68k.h` 의 `ASM_OUTPUT_COMMON`); `01_resources/upstream/next-gcc-2.7.2/config/next/nextstep.h:321` 에 `.zerofill __DATA, __common, NAME, SIZE, ALIGN` 매크로가 정의돼 있으나 그 트리의 `.c`·`.h` 에서 쓰는 곳 0(전수 grep).

탐침 소스(`scratch/p778/p1/src/`, 내가 쓰는 작은 `.s`; 07 아님; 문자열은 모두 `"…\0"` 로 NUL 명시):
- 규칙 대조군: `S.s`(`_start: rts` 만; `__mh_execute_header` 참조 없음), `SH.s`(S + `movl __mh_execute_header,d0`), `UZ.s`(`movl _zeta,d0` 하나), `UA.s`(`movl _alpha,d0` 하나), `C.s`(`.comm _alpha,4`·`.comm _mid,4`·`.comm _zeta,4`), `Cs.s`(C 와 같은 이름, 크기만 8·2·40), `Cx.s`(C + 무관한 외부 정의 `_unrel` 와 무관 미정의 참조 없음).
- 정렬: `AL.s`(`.comm _p1,1`·`_p2,2`·`_p3,4`·`_p4,8`·`_p5,3`·`_p6,1`·`_p7,4`; 이름순 = 선언순), `AR.s`(같은 크기 집합을 역순 이름으로).
- 크기 충돌과 정의 우선 분리: `K1.s`(`.comm _k,2`)·`K2.s`(`.comm _k,8`) — COMMON 끼리; `B1.s`(`.comm _b,8`)·`B2.s`(`.data`·`.globl _b`·`_b: .long 5`) — 정의 대 COMMON.
- 문자열·상수: `T1.s`(`.cstring` `"dup\0"`·`"one\0"`, 텍스트에서 두 문자열 라벨을 `pea` 로 참조), `T2.s`(`"two\0"`·`"dup\0"`, 같은 참조), `Q1.s`·`Q2.s`(`.const` 에 같은 `.long 7`).
- subtype: 실제 `fpsp` 객체(`m4p770-a2/stage/Q770__fpsp_F.o` 복사, SHA-256 `63faf105…`)와 선례 `aux.s`(`m4p770-ld-1/src/aux.s` 복사).

run A `m7p778-p1-1`(collect 할 run; 모든 명령이 0 으로 끝나야 하므로, 처음 쓰는 옵션·니모닉은 넣지 않음):
1. 위 `.s` 를 `as -arch m68k -o stage/X.o src/X.s` 로 하나씩 조립(중괄호 표기 안 씀).
2. 최종 링크 `ld -arch m68k -static -seg1addr 0x4000000 -e _start -o stage/Ln.out …` : L1 = S UZ UA C, L2 = S UA UZ C, L3 = S C UZ UA, L4 = S UZ UA Cs, L5 = S UZ UA Cx, L6 = S AL, L7 = S AR, L8 = S K1 K2, L9 = S B1 B2, L10 = S B2 B1, L11 = S T1 T2, L12 = S T2 T1, L13 = S Q1 Q2, L14 = S 단독(헤더 기호 참조 없음), L15 = SH(헤더 기호 참조), L16 = S fpsp aux(출력 subtype).
3. 중간 링크: `ld -arch m68k -r -o stage/r1.o S UZ UA C` 와 `ld -arch m68k -r -d -o stage/r2.o …`(같은 입력) — 중간 객체 자체를 기록하고, 각각 최종 링크 `R1.out`·`R2.out`.
4. `strip -x -o stage/L1s.out stage/L1.out`(선례 `l2_link.py` 의 `/bin/strip -x -o`), strip 전 L1 도 보존.
5. `EXPECT` 는 `stage/` 를 뺀 이름(`EXPECT L1.out` 등; `kr_run.py:341` 이 `stage/` 를 붙임).
run B `m7p778-p1f-1`(실패할 수 있는 탐침; collect 하지 않음; `EXPECT _log/status`; 입력은 run A 산출물을 `src/` 로 복사해 해시 고정): `/bin/ld`(인자 없음, 사용법은 보조 자료), S UZ 만(미정의: 종료 코드·진단·출력 파일 유무), `ld -force_cpusubtype_ALL` 의 L16, `as -arch m68k` 로 `cpusha bc` 한 줄(`F40.s`; 07 `locore.s:330` 은 이 니모닉을 주석 처리하고 `.word 0xf4f8` 을 씀 → 수용 여부 미지)과 `as -force_cpusubtype_ALL` 판, 헤더 패딩 변형 `-segalign 0x2000`·`-headerpad 0x44`. 판독은 `_log/status`·`.err` 와 함께 `DONE`·LOCK 해제·입력/도구 해시·`output.manifest`·실제 `stage` 파일 목록을 확인한다(명령별 종료 코드는 run 실패가 아님: `kr_run.py:245–253`).

분석(python, 새 빅엔디안 파서; run 결과 파일 해시를 고정한 뒤): 헤더 전 필드, 적재 명령별 크기·`LC_UNIXTHREAD`, 세그먼트·절(주소·크기·오프셋·정렬·flags), `nlist` 의 물리 순서·원래 인덱스·이름·타입·섹션·`n_desc`·값, 주소순 목록(물리 순서와 따로), 재배치(대상 인덱스·종류), `__cstring`·`__const` 바이트. **먼저 조립 객체가 의도한 기호(미정의·COMMON·정의)를 만들었는지** 확인한 뒤 링커 가설을 판정한다.
예측(내 모델로 python 계산; 실제 `ld` 동작의 증거 아님): ⓐ(COMMON 선언만) — L1·L2 모두 `_alpha, _mid, _zeta`; ⓓ(크기 0 미정의 참조도 처음 만남) — L1 `_zeta, _alpha, _mid`, L2 `_alpha, _zeta, _mid`. L3 은 두 가설 모두 C 의 순서. L4(크기만 변경)·L5(무관 기호 추가)는 순서가 L1 과 같아야 각 요인이 무관함을 뜻한다. 크기 최대값(L8)·정의 우선(L9/L10)·정렬(L6/L7)·문자열 중복 제거와 참조 보존(L11/L12)·상수 비합침(L13)·`__mh_execute_header` 생성 조건(L14/L15)·subtype(L16)은 질문으로 둔다(미리 사실로 쓰지 않음). 어느 가설과도 맞지 않으면 그 사실만 기록하고 P2 를 설계하지 않는다.
이 탐침은 07·상태표·M4/M5 객체를 바꾸지 않는다. 결과는 이 `ld` 의 동작 관찰일 뿐 원본 빌드 명령의 증거가 아니다.

#### 778.6.1 codex 검토 판정표(작업 `k6jtjkdjg`)
내가 틀렸던 것(먼저): ① 초안의 문자열을 `"dup"` 처럼 NUL 없이 적음 ② run A 를 "성공을 기대하는 명령만" 이라 했으나 `cpusha`·subtype 혼합·`-r -d` 등 처음 쓰는 것이 섞여 있었음 ③ run B 에 EXPECT 가 필요 없다고 보았음 ④ 크기 4 COMMON 이 정의로 해소돼 남지 않는 것을 못 봄 ⑤ 크기 충돌과 정의 우선을 한 사례(c3)에 섞음 ⑥ `__mh_execute_header` 생성 조건의 대조군(참조 없음)이 없었음 ⑦ `__const` 입력이 없는데 합침을 시험한다고 씀 ⑧ 헤더 패딩 변형이 없었음.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| L1 은 ⓐ·ⓓ 를 구별, u1 `nlist` 가 이름순이어도 `_zeta` 가 추월해 구별력 유지 | 내 모델(python) 출력: L1 A `['_alpha','_delta','_gamma','_odd3','_zeta','_eps','_short2']` D `['_alpha','_zeta',…]` | ✅ |
| L2 는 두 가설 같음, L3 은 c2 COMMON 이 앞 | 같은 모델: L2 A=D, L3 A=D 이고 `_alpha,_eps,_short2` 가 앞 | ✅ |
| 강화 대조군 S·UZ·UA·C: ⓐ 둘 다 `_alpha,_mid,_zeta`, ⓓ `_zeta,_alpha,_mid` / `_alpha,_zeta,_mid` | 같은 모델 출력 일치 | ✅ → 채택 |
| 크기 4 COMMON 이 남지 않음 | 계산: 남는 크기 `[1,2,3,8,8,40,300]`(codex 는 집합으로 `[1,2,3,8,40,300]`) — 4 없음 | ✅ → `C`·`AL` 에 크기 4 |
| `.comm` 은 후보 문법 | `scratch/p725/gccsrc/config/m68k/m68k.h` 의 `ASM_OUTPUT_COMMON` 열람(`.comm NAME,ROUNDED`) — 참고 소스이며 대상 `as` 수용의 증명 아님 | ⚖️ 후보로만 |
| `.cstring` 용례 `nextstep.h:481` | 열람: 481 은 `SECTION_FUNCTION (cstring_section,` 시작 줄, `".cstring"` 는 483 | ⚖️ 줄번호 2 줄 차이 |
| `.ascii "…\0"` 용례 `objc-msg-m68k.s:216` | 열람: 216 `.cstring`, 217 `.align 1`, 218 `L32: .ascii "Does not recognize selector %s\0"` | ⚖️ 사실, 줄번호는 218 |
| `movl _x,d0` `locore.s:243`, `.globl` `locore.s:149`·`aux.s:2` | 열람: 243 `movl _m68k_kernel_mmu_040_tt,d0`, 149 `.globl _start`, aux.s 2 `.globl _copyin` | ✅ |
| `cpusha bc` 는 불확실, `locore.s:330` 은 주석 처리 + `.word 0xf4f8` | 열람: 330 `//	cpusha	bc`, 331 `.word 0xf4f8` | ✅ → run B 로 |
| 인자 없는 `RUN /bin/ld` 허용(`kr_run.py:131`) | 열람: `words[0] == 'RUN' and len(words) >= 2` | ✅ |
| EXPECT 없으면 준비 거부(`:147`) | 열람: `if not runs or not expects: die(...)` | ✅ → run B `EXPECT _log/status` |
| `EXPECT stage/u1.o` 는 `stage/stage/u1.o` 가 됨 | 열람 `:341` `os.path.join(rdir, 'stage', e)`; 선례 `EXPECT aux.o` | ✅ |
| 중괄호 인자 거부 | `ARG_RE` `^[A-Za-z0-9_./=+,:@%-]+$` 에 중괄호 없음 | ✅ |
| 명령 실패는 run FAILED 가 아님, 상태만 기록 | 열람 `:245–253`(명령마다 `echo "NN $?" >> status`) | ✅ |
| run B 는 `_log` 외에 DONE·LOCK·해시·manifest·파일 목록 확인 필요 | 프로토콜상 합당(`collect` 가 하는 검사 `:324–345` 를 수동으로) | ✅ |
| `-r` 결과의 중간 객체 자체 기록, 물리 `nlist` 순서와 주소순 분리, `n_desc`·인덱스·재배치 기록 | 설계 보강 사항(사실 주장 아님) | ✅ 채택 |
| 크기 충돌과 정의 우선 분리, 정의에 크기 필드 없음 | Mach-O `nlist` 구조(12 B: strx·type·sect·desc·value)에 크기 없음 — 내 파서 정의로 확인 | ✅ |
| 원본 적재 명령 `[(1,56),(1,260),(1,260),(2,24),(5,88)]`, 헤더 끝 716·오프셋 784·0 68 B | 내 파서 출력과 같음(세그먼트 3·symtab·unixthread; python 합 688) | ✅ |
| 초안 SHA-256 `1aeb2f96…` | python: `1aeb2f9676379d34507b97671532638281cc435ab67c4c6b298e224e660061f6` | ✅ |

### 778.7 P1 결과 (실기 run `m7p778-p1-1` 수집·`m7p778-p1f-1` 미수집, 2026-11-08; 07·상태표·M4/M5 불변; 기록 `09_validation/reconstruction/m7-m68k-p778-p1-20261108.json`, 파서 `scratch/p778/macho.py`)
- run A: 명령 39 개 모두 종료 0·stderr 0 B, 수집 118 파일. run B: 명령 8 개 중 `/bin/ld`(인자 없음)·미정의 링크 2 개가 종료 1, 나머지 0; 입력·도구 해시 일치(`input.expected`=`input.actual`, `tools.expected`=`tools.actual`), LOCK 해제, `output.manifest` 해시와 실제 파일 해시 일치(python).
- 조립 객체(먼저 확인): 18 개 모두 의도한 기호를 가짐. `as` 는 `nlist` 에 정의 기호를 먼저, 미정의·COMMON 을 이름순으로 둔다(역순 이름으로 선언한 `AR` 도 `_r1…_r7`). 모든 절 정렬 2^0.
- **COMMON 순서 = 가설 ⓓ**: L1(S UZ UA C) `_zeta,_alpha,_mid`; L2(S UA UZ C) `_alpha,_zeta,_mid`; L3(S C UZ UA) `_alpha,_mid,_zeta`; 크기만 바꾼 L4·무관 기호를 넣은 L5 도 L1 과 같은 순서 — 크기 0 미정의 참조도 "처음 만남" 으로 친다. 가설 ⓐ 는 L1 에서 틀림.
- `ld -r` 은 COMMON 을 COMMON 으로 남기며(이름순 `nlist`) 앞선 미정의 참조 정보를 잃어 최종 순서가 `_alpha,_mid,_zeta`(R1); `ld -r -d` 는 중간 객체 안에 `__common` 을 할당해 `_zeta,_alpha,_mid` 를 보존(R2).
- 정렬: 크기 1·2·4·8 은 같은 값으로, 크기 3 은 4 로 정렬(L6: `_p5`(3) 0x10·`_p6`(1) 0x13; L7: `_r3`(3) 0x8). 2 의 거듭제곱으로 올린 크기(관찰 범위 1–8; 40·300 의 상한은 미확인).
- 같은 이름 COMMON 의 크기 충돌(2 대 8): 경고 없이 8(L8). 정의 대 COMMON: 입력 순서와 무관하게 정의(`__data`)가 이기고 COMMON 이 남지 않음(L9·L10), 경고 없음.
- `__cstring`: 처음 나온 순서로 중복 제거(L11 `dup one two`, L12 `two dup one`). `__const`: 합치지 않고 이어 붙임(L13 `0000000700000007`).
- `__mh_execute_header`: 참조가 없으면 생기지 않고(L14), 참조가 있으면 `N_ABS|N_EXT`(0x3) 값 0x4000000(L15) — 원본과 같은 타입·값.
- CPU subtype: `fpsp` 를 넣은 링크는 2(L16); `ld -force_cpusubtype_ALL` 이면 1(F1); `as` 는 `cpusha bc` 를 받아 `f4f8` 을 내고 객체 subtype 2(F40), `as -force_cpusubtype_ALL` 이면 1(F40a). 원본 커널은 1 이므로 둘 중 하나(또는 다른 방법)가 필요하다 — 어느 것이 원래 방법인지는 바이트로 정해지지 않음.
- 헤더 모양: 기본(L1·G1)은 `__PAGEZERO` 0x2000·절을 세그먼트 끝에 붙임(`__text` 0x4001fee). `-headerpad 0x44` 는 기본과 바이트가 같은 파일(G1 = G2). **`-segalign 4`(G3) 는 `__PAGEZERO` 4 B, 헤더 끝 376 → 텍스트 오프셋 444(사이 68 B), 마지막 절 끝 → 세그먼트 끝 2 B** 로 원본의 `__PAGEZERO` 4·사이 68 B·끝 2 B 와 같은 꼴(python). NeXTMach `conf/Makefile.NeXT:30` 의 `-segalign 4` 후보와 맞는다(원본 빌드 명령의 증거는 아님). 단 이 `ld` 출력에는 `__LINKEDIT` 세그먼트가 있고 원본에는 없다(제거 경로 미확인).
- 미정의가 있으면 `ld` 는 종료 1, 진단을 **stdout** 에 `/bin/ld: Undefined symbols:` + 이름으로 내고, 출력 파일을 만들지 않는다(U1). 인자 없는 `ld` 는 사용법 한 줄뿐(옵션 목록 없음).
- `strip -x`(L1→L1s): 기호 6 개 그대로, 파일 8356 → 8304 B.
- 다음 단계에 주는 뜻: ⓓ 규칙에서는 **참조되는 COMMON 의 위치는 처음 참조한 객체가 정하고 정의 객체는 크기만 준다** — 원본 `__common` 의 72 개(참조됨)는 정의를 어디에 두든 위치가 같고, 미참조 `_bootp` 만 선언 위치가 위치를 정한다. 전체 296 객체에 대한 ⓓ 시뮬레이션의 역전 15–17 곳(778.2)이 원본과 다른 참조 집합 때문인지 P0 에서 객체별로 추적한다.

### 778.8 P0 탐색 결과와 P0 도구·P1b 탐침 설계 (코딩 전, 2026-11-08; 07·상태표·도구 불변)
탐색은 읽기 전용 python 입니다(`scratch/p778/p0_explore.py`·`p0_trace.py`·`p0_annot.py`·`p0_refs.py`, codex 검증 `verify_codex3.py`; 결과 `p0_sizes.json`·`p0_trace.json`·`p0_annot.txt`). 아래 수치는 모두 그 출력입니다.

**(1) COMMON 정렬 상한 — P1 기본 옵션과 원본이 다릅니다.**
- 원본 `__common` 613 이름을 주소순으로 놓고, 이웃 두 이름 모두 우리 객체의 COMMON 크기(이름별 최대)가 있는 522 쌍에서 "다음 주소 = 앞 이름 끝을 min(다음 이름 크기를 올린 2 의 거듭제곱, 상한) 으로 올림" 을 시험했습니다. 상한 4 에서 522 쌍 모두 일치하고, 상한 8 에서 84 쌍, 16 에서 122 쌍, 1·2 에서 24 쌍이 어긋납니다. 크기가 4 B 보다 크고 크기를 아는 이름 가운데 주소가 8 의 배수가 아닌 것이 87 개입니다. 마지막 이름 `_traptrace`(4 B, 0x40c9904) 의 끝은 절 끝 0x40c9908 과 같습니다. 원본 절의 정렬 필드는 `__text` 2^2·`__cstring` 2^0·`__const` 2^1·`__data` 2^1·`__bss` 2^1·`__common` 2^2 입니다.
- P1 L7(기본 옵션)은 크기 3 `_r3`(0x4002008, 끝 0x400200b) 다음의 크기 8 `_r4` 를 0x4002010 에 두었습니다(채움 5 B). 출력 `__common` 의 정렬 필드는 2^4 입니다. 따라서 778.7 의 "크기를 2 의 거듭제곱으로 올린 정렬" 은 기본 옵션의 규칙입니다. 원본 링크에는 상한 2^2 에 맞는 조건(옵션, 입력 절 정렬, 다른 버전의 ld 등)이 있었으며, 아직 원인은 모릅니다. 상한 4 는 "우리 크기가 원본 크기와 같다" 는 전제 아래 맞는 규칙일 뿐입니다. 이 컴파일러의 `.comm` 은 반올림한 크기를 냅니다(`scratch/p725/gccsrc/config/m68k/m68k.h:1673–1676` `ASM_OUTPUT_COMMON` 이 `ROUNDED` 출력). 우리 COMMON 크기 가운데 8 B 미만은 2(11 개)·4(358 개)·6(2 개)뿐이고 1·3 은 없습니다.
- `ld` 문자열(로컬 사본 `08_build/toolchains/real-cross-20261009/fat/ld`, SHA-256 앞 16 자리 `4c6dae191006a0ac`)에는 `-noseglinkedit`·`-sectalign`·`-segalign` 의 진단문이 있습니다. "specified alignment (0x%x) for section (__DATA,__common) not used (less than the required alignment in the input fi…" 도 있어, `-sectalign __DATA __common 4` 는 입력이 더 큰 정렬을 요구하면 쓰이지 않을 수 있습니다. 문자열만으로 동작을 정하지는 않습니다.

**(2) 정의 없는 73 이름의 크기 범위**(상한 4 규칙; 앞뒤 이웃을 함께 만족시키는 앞·뒤 방향 가능 집합으로 계산): 간격 합은 1604 B 입니다. 이름별 가능한 최소 크기의 합은 1407 B 이고, 모든 이웃 조건을 동시에 만족하는 최소 합은 1476 B 입니다. 큰 것은 `_curMappingStorage` 729–732, `_bootp` 299–300, `_mem_region` 221–224, `_mouseScaleFactors`·`_mouseScaleThresholds` 37–40, `_kdb_net` 9–12, `_cursorPin` 5–8 이고, `_keySema`·`_totalShmemSize` 는 3–4 입니다. 82624 − 80970 = 1654 B 와 1604 B 의 차 50 B 는 크기를 아는 이름 뒤의 정렬 채움 합(다음 이름의 크기를 모르는 경우 포함)과 같습니다. 정확한 크기는 바이트만으로 정해지지 않고 소스의 형(type)이 정합니다.

**(3) ⓓ 순서 어긋남 추적.** 자료 단위를 데이터·상수·bss 가 단조인 첫/마지막 위치에 넣은 두 순서로 계산했습니다. 612 이름 가운데 순서 유지 최장 부분수열이 574/576 이고 그 밖이 38/36 입니다. **단, 이 두 순서는 문자열 제약(778.2, `verify_cstring.py`: `fd_global` 은 텍스트 순번 210, `uipc_proto` 는 34·35 만 가능)을 지키지 않으므로**(첫 위치의 `fd_global` 208, 마지막 위치의 `uipc_proto` 36), 이 수치와 778.2 의 역전 15–17 곳은 탐색 값일 뿐 판정에 쓰지 않습니다. 첫 위치 기준 38 개의 우리 첫 언급 객체는 `ev_ioctl` 12·`ev_kbd` 4·`ev_mouse` 4·`in_pcb` 3·`fd_global` 3·`ip_input` 2·`sys_generic` 2·`pmap` 2·`adb`·`km`·`scsi`·`snd_dspdev`·`video`·`m68k_init` 각 1 입니다. 38 개 중 24 개가 정의 없는 73 에 속합니다. 원본의 이름순 구간(87 개)과 맞춰 본 해석은 다음과 같으며, 모두 가설입니다.
- 구간 r69(55 이름)에는 `ev`·`ev_ioctl`·`ev_kbd`·`ev_mouse` 가 처음 언급하는 이름이 한 이름순 구간으로 섞여 있습니다. 원본에서는 `ev` 위치(또는 `dma` 와 `ev` 사이)의 객체 하나가 이 이름을 모두 처음 언급했다는 해석과 맞습니다. 이 이름 대부분이 정의 없는 73 입니다.
- r13(17 이름): `subr_prf` 이름 사이에 `_bmap_chip`·`_ip_id`·`_ipq`·`_ipstat` 이 이름순으로 끼고, 이어서 `_rthost`·`_rtnet`·`_rtstat`(우리는 `sys_socket`)·`_udb`·`_udpstat`(우리는 `ip_input`)까지 한 구간입니다. 다음 구간 r14 는 `sys_generic` 의 `_nselcoll`·`_selwait` 입니다.
- r01: `cmu_syscalls` 구간 안에 `_pv_head_table`·`_pv_list_zone`(우리는 `pmap`)이 있습니다. r07: `kern_exit` 구간 안에 `_brightness`·`_scr2` 가 있습니다. r76: `_scsi_ndevices` 가 `sc` 의 `_sc_sc` 와 `scsiconf` 의 `_sd_sd` 사이에 있습니다. r81: `_kdb_net` 이 `if_en` 의 `_etheraddr` 와 `clock` 의 `_new_clock_chip` 사이에 있습니다. r84: `_bootp`·`_cpu_clk`·`_cpu_rev`·`_interrupt_stack` 이 `machdep` 구간 다음의 한 구간입니다.
- r66·r67: `_dma_chip`·`_slot_id` 다음에 따로 `_eventsOpen` 이 옵니다. 우리 `adb` 는 셋 모두 크기 0 미정의로 언급하므로, `adb` 가 처음이면 이름순 `_dma_chip,_eventsOpen,_slot_id` 가 되어야 합니다. 원본에서는 앞의 둘을 `adb` 보다 앞(`vnode_pager` 다음)에서 언급한 객체가 있었다는 뜻이며, 그 객체는 정해지지 않았습니다.
- r72·r73: 우리 `D:fd_global` 은 COMMON 29 개를 선언하고 그중 24 개가 원본 `__common` 이름입니다. 그 가운데 15 이름이 원본에서는 두 구간(r72 `_fd_blk_major`…`_fd_volume_p` 7 개, r73 `_disk_eject_q`…`_vol_check_lock` 8 개)으로 나뉩니다.
- `D:param` 의 `_callout`·`_file` 은 원본 r37 에서 `ufs_vfsops` 다음·`ipc_entry` 앞에 있습니다. 즉 `__common` 도 자료 단위 위치를 제약합니다.
- 원본 절대 주소 값 검사(`p0_refs.py`: 각 이름의 [주소, 주소+크기) 에 드는 4 B 값을 원본 객체 범위에서 2 B 간격으로 셈)는 **참조 판정에 쓰지 않습니다**. 우리 객체의 외부 재배치(긴 꼴 7592 개)를 원본 바이트와 맞춰 보면, 크기를 아는 이름 가운데 46 개 참조의 원본 값이 그 이름의 [주소, 주소+크기) 밖에 있습니다(`od` 27 개 등; 예: `_od_drive`+64 의 원본 값 0x40c3e58 은 `_od_empty` 의 주소, `_od_vol`−218). 따라서 구간 검사는 실제 참조를 놓치고 이웃 이름에 잘못 붙입니다. 이 검사로 말할 수 있는 것은 "맞는 절대 주소 값을 찾지 못했다" 뿐입니다.
- 자료 단위 13 개 중 원본 `__common` 이름을 언급하는 것은 9 개입니다(`conf` 8·`fd_global` 24·`in_proto` 7·`ioconf` 8·`param` 19·`scsiconf` 18·`tty_conf` 8·`uipc_proto` 7·`vfs_conf` 1; `counters`·`init_sysent`·`ufs_tables`·`vers` 0). 13 개 위치 후보의 곱은 1161216 이고, 9 개만의 곱은 12096, 문자열 제약을 지키는 9 개 조합은 576 입니다(3·1·1·16·3·2·1·2·1).
- 우리 객체의 `nlist` 구조(296 객체 전수): 미정의·COMMON 부분열이 모두 이름순이고, 그 뒤에 정의 기호가 오지 않으며, 한 객체 안에 같은 외부 이름이 두 번 나오지 않습니다. 크기 0 미정의 5777 항목은 모두 같은 객체 안에 그 이름을 가리키는 외부 재배치가 있습니다. COMMON 항목에도 재배치가 붙을 수 있습니다(예: `D:fd_global` 의 COMMON `_fc_bcp` 를 `__data` 오프셋 0x3c 의 재배치가 가리킴). 원본 `__common` 이름을 정의(SECT)하는 우리 객체는 없습니다(COMMON 554 이름 중 14 개는 정의에 져서 빠지고 540 개가 남음).

**(4) P0 도구 설계** — `10_tools/reconstruction/m7_m68k_link.py`(python 3 표준 라이브러리만, 읽기 전용, 결과 `09_validation/reconstruction/m7-m68k-p778-p0-20261108.json`):
- 입력: scratch 파일을 쓰지 않습니다. 출처(`06_reconstruction/m68k-m4-status.tsv` 와 각 L1 기록, `08_build/artifacts/m4p764/m5compare/l1-x86-*.json`, `09_validation/reconstruction/m4-m68k-p777-check-20261108.json`)에서 296 객체의 목록·경로·SHA-256·원본 절 주소를 다시 만들고 파일 해시를 대조합니다. 규칙은 `scratch/p778/order.py` 와 같습니다(M5 에서 `tty_pty`·`kern_exec`·`mach_process`·`ns_timer` 제외).
- `spec`: 객체 목록, 텍스트 순서, 자료 단위 후보 위치(데이터·상수·bss 단조), 문자열 바이트 일치 조합(778.2 의 32 개)을 다시 계산해 기록합니다.
- `common`:
  (a) 링커 모델: ⓓ 순서(링크 순서대로 각 객체 `nlist` 물리 순서에서 외부 미정의·COMMON 을 처음 만난 순서), 같은 이름 최대 크기, 정의 우선(정의에 진 이름은 순서에서 빼고 나머지 순서는 유지), 정렬 상한(4·8·없음 매개변수)으로 `__common` 주소를 계산합니다. 정의 없는 73 이름의 크기는 (2) 의 가능 집합에서 고른 값을 "가정" 으로 표시합니다. `_bootp` 는 언급이 없으므로 "합성 선언" 상태로 따로 두고, 그 위치는 맞춘 예측으로 세지 않습니다.
  (b) 검증: 원본 613 이름의 주소를 이름별로 비교하고, 우리 객체의 원본 `__common` 이름에 대한 외부 재배치마다 "예측 주소 + 덧붙임 값 = 원본 바이트" 를 검사합니다. 크기를 가정한 이름에 걸린 결과는 따로 셉니다.
  (c) 최소 변경 배정(동적 계획법): 원본 순서를 객체 순번에 배정하되, 순번은 줄지 않고, 이름순이 거꾸로 가는 곳에서는 순번이 반드시 커지게 합니다. 이름을 우리 첫 언급보다 앞 순번에 두는 것은 "그 앞 객체가 언급을 더 가졌다"(추가 1 건)로 셉니다. 뒤 순번 j 에 두려면 j 보다 앞의 **모든** 언급을 지워야 하며(지움 1 건씩), 그 언급을 가리키는 외부 재배치가 그 객체에 있으면 지울 수 없습니다. 결과는 최소 비용과 함께, 이름마다 최적 순번의 **집합**(같은 비용의 다른 해가 있으면 모두)으로 냅니다. 언급이 하나도 없는 자료 단위 4 개(`counters`·`init_sysent`·`ufs_tables`·`vers`)는 배정 대상에서 뺍니다(가정으로 기록). `_bootp` 의 삽입은 이동 비용과 따로 셉니다.
  (d) 자료 단위 위치: 문자열 제약을 지키는 9 개 단위의 576 조합마다 (c) 의 최소 비용을 계산하고, 최소 비용 조합의 집합을 기록합니다.
- 이 도구는 원본 객체의 선언 집합을 증명하지 않습니다. 바이트(주소 순서와 재배치 값)와 맞는 최소 변경 후보를 낼 뿐입니다. 07 소스를 바꾸는 일은 P3 에서 사용자 결정으로 올립니다. 직접 링크(중간 `ld -r` 없음)는 가정입니다. P1 에서 `ld -r` 이 순서를 바꾼다는 것을 보았기 때문입니다(R1).

**(5) P1b 탐침 방향**(실기, 새 run; 07·객체 불변; 구체 명령은 P0 뒤 따로 적고 codex 검토를 받습니다):
- 판정 값은 절대 주소와 절 안 오프셋 둘 다로 기록합니다. AR 의 크기 순서(4·1·3·8·4·2·1)에서 `_r4` 의 오프셋은 `__common` 시작이 8 의 배수이면 상한 4 에서 0xc, 상한 8 에서 0x10 입니다. 시작이 8 로 나눠 4 가 남으면 두 상한 모두 0xc 입니다(python). 따라서 시작 위치의 두 경우를 모두 만듭니다.
- 고정 입력에 더할 것: 크기 16·40·300 을 정렬이 드러나는 자리에 둔 COMMON, 크기 충돌 앞에 표지 COMMON 을 둔 경우, 초기화 자료 절의 정렬 필드가 2^1·2^2 인 객체, 대상 `cc` 로 컴파일한 C 객체(`char[3]`·`short`·3 B 구조체·`double`; `.comm` 크기·절 정렬·재배치 기록).
- 변형: 기본, `-segalign 4`, `-sectalign __DATA __common 4`, 같은 옵션에 4 보다 큰 값, `-segalign 4` 와 `-sectalign` 의 조합, `-noseglinkedit`(단독과 `-segalign 4` 와 함께).
- `__LINKEDIT` 없음의 비교 항목: 원본은 초기화 절의 끝 = `symoff` 733564, 기호 45708 B 뒤 = `stroff` 779272, 문자열 끝 = 파일 크기 832196(뒤 남는 바이트 0)입니다. 탐침 출력에서 같은 관계, 세그먼트 flags·보호 속성, 파일 범위를 비교합니다. 작은 탐침만으로 원본 파일 전체 배치를 확정하지는 않습니다.
- 실패할 수 있는 명령은 미수집 run 으로 나누고, 명령마다 기대 종료 상태·진단·출력 파일 유무를 미리 적어 판정합니다(`kr_run.py` 는 명령이 실패해도 DONE 을 쓰고(`:262`), `collect` 는 0 이 아닌 상태를 모두 거부함(`:329`)).

**(6) 하지 않는 것·P2 로 넘기는 것**: 전체 링크(P2)는 P0·P1b 결과를 본 뒤 따로 계획하고 codex 검토를 받습니다. P2 계획에는 층별 합격 기준(링크 성공·절 배치·기호 해석·바이트 비교·가정에 기댄 일치)과 이미 아는 예외(크기 미정 이름, `__data` 미검증 41 B, `nfs_client`·`swapfs` 텍스트 차이)를 미리 적습니다. 정의 없는 73 이름의 선언과 (3) 의 언급 차이를 메우는 07 변경은 P3 에서 사용자 결정으로 올립니다. 커밋하지 않습니다.

#### 778.8.1 codex 검토 판정표(작업 `ktr29p7qa`)
내가 틀렸던 것(먼저): ① (2) 의 크기 범위 계산이 다음 이름의 정렬을 그 크기와 따로 고르게 허용해 `_keySema`·`_totalShmemSize`(1–4 → 3–4)·`_bootp`(297–300 → 299–300)를 넓게 잡았고, 최소 합 1401 은 나올 수 없는 값이었습니다(이름별 최소 합 1407, 동시 최소 1476). ② 50 B 를 "선언된 이름 사이" 채움이라 좁게 적었습니다. ③ (3) 의 첫/마지막 위치 순서는 문자열 제약을 어깁니다(778.2 의 역전 15–17 도 같은 순서로 셈). ④ 절대 주소 구간 검사를 참조 판정 근거로 쓰려 했습니다. ⑤ "COMMON 이면 쓰지 않는 선언" 으로 보아 뒤로 옮김을 첫 언급 하나만으로 허용하려 했습니다. ⑥ P1b 판정 값(0xc 대 0x10)이 `__common` 시작 위치에 따라 달라진다는 것을 놓쳤습니다. ⑦ 778.1–778.7 의 한국어를 합니다체가 아닌 문체로 적었습니다(이 절부터 합니다체).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 상한별 불일치 4:0·8:84·16:122·1·2:24, 522 쌍; L7 `_r4` 오프셋 0x10, 정렬 필드 2^4 | `p0_explore.py` 출력과 같음; L7 절 정렬 2^4(`macho.parse`) | ✅ |
| 크기 4 초과·크기 아는 이름 중 8 의 배수 아닌 주소 87 개 | `verify_codex3.py` C2 출력 87 | ✅ 반영 |
| 맞는 규칙일 뿐 원인 아님, GCC 는 `ROUNDED` 출력 | `m68k.h:1673–1676` 열람: `fprintf ((FILE), ",%u\n", (ROUNDED))` | ✅ 반영 |
| `_keySema`·`_totalShmemSize` 3–4, `_bootp` 299–300 | C3 앞·뒤 가능 집합 출력 같음 | ✅ 내 오류 정정 |
| 이름별 최소 합 1407, 동시 최소 1476 | C4 출력 1407·1476 | ✅ 정정 |
| 간격 합 1604, 크기 아는 이름 뒤 채움 50, 합 80970 | C5 출력 50·80970 | ✅ 문구 정정 |
| `nlist` 미정의·COMMON 이름순, 뒤에 정의 없음, 중복 없음 | C6 296 객체 전수 출력 `[] [] []` | ✅ |
| 이름순 감소에서 순번이 반드시 커져야 함 | `as` 가 미정의·COMMON 을 이름순으로 둠(위 C6, 778.7) — 같은 순번에서 감소 불가 | ✅ 반영 |
| COMMON 554·정의에 짐 14·남음 540, 원본 `__common` 이름의 정의 없음 | 별도 python: 554·14·540, SECT 정의 0 | ✅ |
| `fd_global` COMMON `_fc_bcp` 에 `__data` 0x3c 재배치 | C8 출력 `('__data','0x3c')` | ✅ 반영 |
| 뒤로 옮기려면 앞의 모든 언급을 지워야 함 | 설계 논리(ⓓ 는 첫 만남이 정함, 778.7) — 앞 언급이 하나라도 남으면 그 순번이 됨 | ✅ 반영 |
| 미정의 항목 중 재배치 없는 것 0 | C10 출력 5777 중 0 | ✅ 반영 |
| 한 배치에서 DP 비용 37, 뒤로 옮김 0 | 도구를 아직 만들지 않아 재현 안 함 | ⏭️ 문서에 넣지 않음 |
| 최적 해가 여럿(7 이름) → 집합으로 보고 | 수 7 은 재현 안 함; 집합 보고는 설계로 채택 | ⚖️ 설계만 |
| 곱 1161216, 9 개 12096, 문자열 제약 576 | python 곱 1161216·12096·576(3·1·1·16·3·2·1·2·1; `verify_cstring.py` 재실행: 672 중 32, `fd_global` [210]·`uipc_proto` [34,35]) | ✅ 반영 |
| 언급 없는 4 단위가 배정 대상이 되면 위치가 의미 있음 | 설계 논리 맞음 | ✅ 대상에서 빼고 가정으로 기록 |
| `_bootp` 합성 선언 상태 필요 | 언급 0(778.2) | ✅ 반영 |
| 절대 주소 검사는 PC 상대·레지스터 상대 등을 놓침 | 검사 방식(`p0_refs.py` 절대 값만) 열람 | ✅ 판정에서 뺌 |
| 크기 밖 덧붙임 참조 46 개, `_od_drive`+64 → `_od_empty` 주소 0x40c3e58, `_od_vol`−218 | python 재배치 대조: 크기 아는 이름 46(`od` 27 등), 두 예 그대로 | ✅ 반영 |
| 2 B 간격은 자료의 홀수 위치를 놓침; 홀수만 맞는 경우 0 | 검사를 판정에서 뺐으므로 재현 안 함 | ⏭️ |
| AR 판정 값이 시작 위치에 따라 0xc/0x10 또는 0xc/0xc | C20 python 출력 같음 | ✅ 반영 |
| AR.o 는 빈 `__text`(정렬 0) 뿐 | C21 `[('__TEXT','__text',0,0)]` | ✅ 입력 절 대조군 추가 |
| 큰 크기·충돌 앞 표지·4 초과 `-sectalign` 필요; L8 은 할당 하나뿐 | P1 기록 `size_conflict_L8`: `_k` 0x4002000 하나 | ✅ 반영 |
| 대상 `cc` C 객체 필요; 우리 크기에 1·3 없음 | C23 출력 2·4·6 만 | ✅ 반영 |
| 원본 `symoff` 733564 = 초기화 절 끝, 기호 45708 B, `stroff` 779272, 문자열 끝 832196 | C24 출력 같음 | ✅ 반영 |
| 실패 기대 run 은 명령별 기대 판정 필요(`kr_run.py` DONE·collect) | 열람: 252 상태 기록, 262 DONE, 329 `need(rc == '0', ...)` | ✅ 반영 |
| 머리 수치 612·574/576·38/36·24·9·7/8, `fd_global` COMMON 29 중 24 | C26 29·24, 나머지는 내 출력과 같음 | ✅ |
| P2 에 층별 합격 기준 필요, 직접 링크는 가정 | 778.3 P4 층 열람; R1 결과(778.7) | ✅ (6)에 반영 |

### 778.9 P0 결과 (오프라인 python, 2026-11-08; 07·상태표·M4/M5 객체 불변; 실기 사용 안 함)
도구 `10_tools/reconstruction/m7_m68k_link.py`(SHA-256 `0f359ced…`), 기록 `09_validation/reconstruction/m7-m68k-p778-p0-spec-20261108.json`(`spec`)·`m7-m68k-p778-p0-20261108.json`(`common`). `common` 을 두 번 돌려 같은 내용을 얻었습니다. 아래 수치는 모두 도구 출력입니다.
- 입력: 출처 기록에서 다시 만든 296 객체(M4 76·M5 204·R 3·D 13)의 해시가 모두 기록과 같습니다. 텍스트 객체 283 개, 텍스트 678510 B, 틈·겹침 없음. 문자열 조합 672 중 바이트 일치 32(778.2 와 같음).
- 정렬 상한 시험(522 쌍): 상한 4 에서 어긋남 0, 1·2 에서 24, 8 에서 84, 16 에서 122, 상한 없음에서 144 입니다.
- 정의 없는 73 이름: 상한 4 에서 모든 이웃 조건을 함께 만족하는 크기가 있습니다. 간격 합 1604 B, 이름별 최소 합 1407 B 이고, 시뮬레이션에 쓴 "가정" 크기(가장 큰 가능 크기를 왼쪽부터 고름)의 합은 1604 B 입니다.
- 원본 `__common` 이름을 가리키는 우리 객체의 외부 재배치는 7592 개입니다. 크기 0 미정의 언급은 모두 재배치가 있고(재배치 없는 것 0), COMMON 언급 가운데 재배치가 없는 것은 1420 개입니다.
- 최소 변경 배정(DP): 문자열 제약을 지키는 자료 단위 배치 576 개를 모두 계산했습니다. 최소 비용은 37 이고(96 배치), 나머지는 38(96)·39(192)·40(192) 입니다. 최소 비용 배치에서 각 단위의 위치(텍스트 순번)는 `conf` 202–204, `fd_global` 210, `in_proto` 62, `ioconf` 268–283, `param` 118, `scsiconf` 220, `tty_conf` 29, `uipc_proto` 34·35, `vfs_conf` 41 입니다. 즉 `__common` 이 `param` 을 118 로, `scsiconf` 를 220 으로 정합니다.
- 비용 37 은 모두 "앞 객체가 언급을 더 가짐" 이고, 지움(원본에 없었어야 할 언급)은 0 입니다. 그중 1 은 언급이 없는 `_bootp` 의 합성 선언이고 36 은 이동입니다. 객체별 추가 언급: `M4:ev` 20(`_alphaLock`·`_buttonsTied`·`_curBright`·`_curMapLen`·`_curMapping`·`_curMappingStorage`·`_currentScreen`·`_cursorPin`·`_deviceMods`·`_dimmedBrightness`·`_initialKeyRepeat`·`_keyPressed`·`_keyRepeat`·`_mapNotDefault`·`_mouseHandedness`·`_mouseScaleFactors`·`_mouseScaleThresholds`·`_numMouseScales`·`_sessionPrecision`·`_sessionPressure`), `M5:subr_prf` 9(`_bmap_chip`·`_ip_id`·`_ipq`·`_ipstat`·`_rthost`·`_rtnet`·`_rtstat`·`_udb`·`_udpstat`), `M5:cmu_syscalls` 2(`_pv_head_table`·`_pv_list_zone`), `M5:kern_exit` 2(`_brightness`·`_scr2`), `M5:vol` 2(`_dma_chip`·`_slot_id`), `M4:if_en` 1(`_kdb_net`), `M4:miniMonMachdep` 1(`_bootp`). 추가된 이름 37 개 중 26 개가 정의 없는 73 에 속합니다.
- 해가 하나로 정해지지 않는 이름이 7 개입니다: `_rthost`·`_rtnet`·`_rtstat`·`_udb`·`_udpstat` 은 `subr_prf` 또는 `subr_xxx`, `_kdb_net` 은 `if_en`·`in_bootp`·`APM`·`ashldi3`·`bdiv`·`checksum_16`·`clock` 중 하나, `_bootp` 는 `miniMonMachdep`·`next_exception`·`m68k_init` 중 하나입니다. 위 객체별 목록은 가장 앞 객체를 고른 한 해일 뿐입니다.
- 독립 대조: 위 추가 언급을 실제 객체 언급에 넣고 ⓓ 규칙으로 다시 계산하면 613 이름의 순서가 원본과 같습니다. 추가 없이(`_bootp` 만)는 다르고, `_scr2` 하나만 빼도 다릅니다.
- 시뮬레이션(`__common` 시작은 원본 값을 가정): 지금 객체 그대로(+`_bootp` 합성)에서는 상한 4 에서도 주소가 같은 이름이 34 개뿐이고 재배치 7592 중 2002 개만 원본 바이트와 같습니다. DP 배정 순서(원본 순서에 맞춘 것)와 상한 4 에서는 613 주소·절 끝 0x40c9908 이 모두 같고, 재배치 7592 개가 모두 원본 바이트와 같습니다(크기를 아는 이름 6435, 크기를 가정한 이름 1157). 같은 순서라도 상한 8 이면 주소 28 개·재배치 1726 개만 같습니다.
- 뜻: (1) ⓓ 규칙·최대 크기·정의 우선·정렬 상한 4 의 모델은, 원본에서 몇몇 객체가 언급을 더 가졌다고 보면 원본 `__common` 배치와 그것을 가리키는 모든 긴 꼴 재배치를 설명합니다. (2) 원본과 같은 `__common` 을 얻으려면 07 소스에서 위 7 객체(또는 같은 비용의 다른 객체)가 해당 이름을 언급해야 하고(바이트 참조가 없는 선언 — 예: 헤더의 임시 정의), 정의 없는 73 이름에는 크기를 주는 선언이 있어야 합니다. 이 소스 변경은 P3 에서 사용자 결정으로 올립니다. (3) 링크에서 상한 4 를 내는 조건은 아직 모르며 P1b 에서 확인합니다.
- 한계: 이 결과는 바이트와 맞는 최소 변경 후보이며 원본 객체의 선언 집합이나 소스 위치의 증명이 아닙니다. 직접 링크(중간 `ld -r` 없음)와 `__common` 시작 주소는 가정입니다. 언급이 없는 자료 단위 4 개는 배정 대상에서 뺐습니다.

### 778.10 P1b 탐침의 구체 설계 (실행 전, 2026-11-08; 07·상태표·M4/M5 객체 불변)
목적은 778.8 (5) 입니다. 원본 `__common` 의 정렬 상한 4(778.9)를 만드는 링크 조건과, 원본에 `__LINKEDIT` 가 없는 조건을 찾습니다. 결과는 링커 동작의 관찰이며 원본 빌드 명령의 증거가 아닙니다. 링커는 실기 `/bin/ld`(SHA-256 `4c6dae19…`, 내장 문자열 `PROJECT:cctools-209.4.obj~4`, `BUILT:Tue Apr 22 07:55:33 PDT 1997`) 하나뿐이므로, 상한 4 를 찾지 못해도 "원본은 다른 ld" 를 따로 떼어 증명할 수는 없습니다.

고정 입력(`scratch/p778/p1b/src/`, 내가 쓴 작은 파일이며 07 이 아님):
- P1 의 `S.s`·`AR.s`·`K1.s`·`K2.s` 복사본(바이트 같음).
- `M4.s`(`.comm _a0,4`, 시작 위치를 4 B 밀기)·`KM.s`(`.comm _a0,1`, 크기 충돌 앞의 표지)·`AB.s`(`_b1`1·`_b2`16·`_b3`1·`_b4`40·`_b5`1·`_b6`300).
- 초기화 자료 `DH.s`(`.align 1`)·`DA.s`(`.align 2`)·`D3.s`(`.align 3`). 이것은 `__DATA` 안 다른 절의 정렬이 COMMON 정렬을 바꾸는지만 시험하며, 입력 `__common` 절 자체를 만들지는 않습니다.
- `CCs.c`·`CC.c`(같은 내용; 임시 정의 `char c1`·`char c3[3]`·`short sh`·3 B 구조체 `s3`·`double d8`·`int i4`·`char c5[5]`·`char c16[16]` 과 함수 하나).

run A `m7p778-p1b-1`(수집; RUN 17·EXPECT 17; `08_build/artifacts/m7p778/m7p778-p1b-1.cmd`): 이미 성공을 본 꼴만 넣습니다.
- `as` 9 개(`.align 2` 는 `locore.s:166` 에서 쓰임, `.align 1` 도 같은 지시문).
- 커널과 같은 꼴의 `cc -arch m68k -static -c`(CCs).
- 기본 옵션 링크: A1 `S AR`, A2 `S M4 AR`, A3 `S AB`, A4 `S KM K1 K2`, A5 `S DA AR`, A5h `S DH AR`, A7s `S CCs`.

run B `m7p778-p1bf-1`(미수집; RUN 31; `EXPECT _log/status`): 아직 성공을 보지 못한 꼴입니다.
- `as` 10 개(D3 포함)를 다시 하고, `cc -static -c`·`cc -static -S`·비정적 `cc -c` 를 돌립니다.
- 기본 옵션 링크: A6 `S D3 AR`, A7 `S CC`.
- `-segalign 4` 링크: A8 `S AR`, A9 `S M4 AR`, A10 `S AB`, A11 `S KM K1 K2`, A12 `S DA AR`, A12h `S DH AR`, A13 `S CCs`. P1 G3 은 텍스트만 링크했으므로 COMMON·자료가 있는 경우의 성공은 아직 모릅니다. ld 에는 "alignment … of section … greater than the segment alignment" 진단문이 있습니다(실패 예측이 아니라 확인 대상).
- `-sectalign __DATA __common 4`: B1 `S AR`, B2 `S M4 AR`, B3 `S AB`. `-sectalign __DATA __common 10`(16진수 0x10 = 16 B): B4 `S AB`. `-segalign 4 -sectalign __DATA __common 4`: B5 `S AR`, B6 `S AB`.
- `-noseglinkedit`: B7 `S DA AR`. `-segalign 4 -noseglinkedit`: B8 `S DA AR`, B9 `S AB`.

실행 전 확인: 준비된 `08_build/runs/<ID>/src/` 의 각 파일을 원본 파일과 바이트로 비교합니다(NFS 복사 함정, 계획 :155).

run B 판정(명령별):
- ① 먼저 전제 조건을 봅니다. 링크에 쓰는 객체를 만든 명령이 종료 0 이고 그 객체가 Mach-O 이며, run A 의 같은 객체와 해시가 같아야 합니다(CC.o 처럼 run A 에 없는 것은 제외). 이것이 깨지면 그 객체를 쓰는 링크는 "전제 실패" 로 두고 해석하지 않습니다.
- ② 종료 0·출력이 m68k 실행 파일(MH_EXECUTE)이면 "출력 있음" 입니다. 다음을 차례로 봅니다: 기호 해석, 기대한 COMMON 이름·크기·순서, 절·세그먼트 범위의 구조적 타당성, 그리고 옵션이 의도한 효과를 냈는지. "출력은 맞으나 옵션이 효과 없음" 과 "의도한 효과 관찰" 을 구별합니다.
- ③ 종료가 0 이 아니면 "이 꼴로는 안 됨" 이며, stdout·stderr 전문을 남깁니다(진단문으로 옵션 미지원과 다른 실패를 구별).
- ④ 종료 0 이라도 stdout·stderr 의 경고는 전문을 기록합니다(P1 에서 ld 진단이 stdout 으로 나옴).
- ⑤ 손 검사(python): DONE 이 있고 FAILED 가 없으며 LOCK 이 풀렸는지, 입력 해시 두 번(`input.actual`·`input.actual2`)과 `input.expected` 의 일치, 도구 해시, 상태 줄 수·번호, `nonregular`·`hardlinks` 가 비었는지, manifest 의 파일 집합·해시가 실제 stage 파일과 같은지를 봅니다.

미리 적는 예측(python; 각 출력의 실제 `__common` 시작에서 잰 오프셋, ⓓ 순서, 정렬 = min(크기를 올린 2 의 거듭제곱, 상한), 절대 주소 기준):
- AB(`_b1…_b6`): 상한 4 는 시작 위치와 무관하게 `0,4,0x14,0x18,0x40,0x44` 입니다. 상한 8 은 시작이 8 의 배수이면 `0,8,0x18,0x20,0x48,0x50`, 8 로 나눠 4 남으면 `0,4,0x14,0x1c,0x44,0x4c` 입니다. 상한 16 과 상한 없음도 시작 위치마다 정해지며, 상한 없음은 가장 큰 자연 정렬 512 때문에 시작 주소의 512 나머지가 필요합니다. 4 B 정렬된 모든 시작에서 네 모델의 값이 서로 다릅니다.
- AR(`_r1…_r7`): 시작이 8 의 배수이면 상한 4 `0,4,8,0xc,0x14,0x18,0x1a`, 상한 8 이상 `0,4,8,0x10,0x18,0x1c,0x1e` 이고, 8 로 나눠 4 남으면 두 값이 같습니다.
- M4+AR: `_r4` 오프셋이 시작이 8 의 배수이면 모든 상한에서 0x10, 8 로 나눠 4 남으면 상한 4 에서 0x10, 8 이상에서 0x14 입니다. `_a0` 는 전역 이름순에서도 앞이므로, 이 고정 입력은 ⓓ 순서를 다시 시험하지 않습니다(순서 증거는 P1).
- KM+K1+K2: `_k` 를 최종 크기 8 로 정렬하면 상한 4 에서 4, 상한 8 이상에서 8(시작이 8 의 배수일 때)입니다. 처음 본 크기 2 로 정렬하면 2 입니다. 이 고정 입력은 "처음 크기 대 최종 크기" 만 가르고, 앞선 크기 0 미정의 참조의 영향은 가르지 않습니다.
- A5·A5h·A6: 입력 `__data` 정렬(2^2·2^1·2^3)에 따라 AR 오프셋과 출력 정렬 필드가 바뀌는지 봅니다.
- CC: 소스 선언 크기, `CCs.s` 의 `.comm` 피연산자, `CCs.o` 의 COMMON 값을 따로 기록합니다(반올림 규칙). 절 정렬·재배치, 링크 주소, `-static` 유무에 따른 차이도 기록합니다.
- B7·B8: `__LINKEDIT` 유무, 세그먼트 목록·flags·보호 속성, 절 정렬 필드, sizeofcmds 를 봅니다. 원본과 같은 관계(초기화 절의 끝 = `symoff`, `symoff` + 12×nsyms = `stroff`, `stroff` + strsize = 파일 크기)인지도 봅니다. 작은 탐침만으로 원본 파일 전체 배치를 확정하지는 않습니다.
- 결과가 어느 예측과도 맞지 않으면 그 사실만 기록합니다.
- 다루지 못하는 가설: ld 버전 차이, `-force_cpusubtype_ALL`·subtype 2 입력이 COMMON 배치에 주는 영향, 링커 쪽 `-static` 의 유무. 이 탐침의 범위 밖이며, 필요하면 결과를 본 뒤 따로 계획합니다.
- `kr_run.py` 의 도구 해시는 `/bin/as`·`/bin/cc` 만 덮고 `/lib/m68k/as`·`cc1`·`cpp`·specs 는 덮지 않습니다(`08_build/toolchains/real-cross-20261009/sha-a.txt` 에 별도 기록). 컴파일러·어셈블러 차이로 결과를 해석할 때는 그 기록과 맞춰 봅니다.

#### 778.10.1 codex 검토 판정표(작업 `keddmpxwh`)
내가 틀렸던 것(먼저): ① `-segalign 4` 링크(A8–A13)를 "이미 쓴 꼴" 이라 성공 기대 run 에 넣었습니다. G3 은 텍스트만 링크했습니다. ② 상한 없음의 AB 예측을 16 나머지로만 적었습니다(512 나머지 필요). ③ 경고를 stderr 에서만 보려 했습니다. ④ 실제 커널 객체의 `__data` 정렬 2^1 대조군과 컴파일러 쪽 `-static` 을 빠뜨렸습니다. ⑤ run B 의 전제 실패 판정과 손 검사 항목이 모자랐습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| A8–A13 은 G3 이 보이지 않은 꼴 | `m7p778-p1f-1.cmd` 9 줄 G3 = `src/S.o` 하나 | ✅ run B 로 옮김 |
| ld 에 "greater than the segment alignment" 진단문 0x35ec7 | python: 0x35ec7 에 같은 문자열(SHA-256 `4c6dae19…`) | ✅ 확인 대상으로만 |
| `.align 3` 은 문서화된 문법(`04_Directives.rtf:980`, 예 1001) | 열람: 980 근처 `.align` 설명, 1001 근처 `.align 3` 예 | ⚖️ 문법 사실; 실행은 미확인이므로 run B |
| `cc -S -o` 의미(`Compiler.rtf:170`·185) | 열람: `-S` "Stop after the stage of compilation proper", `-o` "applies regardless to whatever sort of output" | ⚖️ 문법 사실; run B |
| `EXPECT CC.s` 통과 가능, `.out` 은 마법 수 검사 없음 | `kr_run.py:340–345` 열람(`.o` 만 마법 수) | ✅ |
| 명령 하나가 실패하면 run A 전체 수집 거부 | `kr_run.py:252`·`:262`·`:329` 열람 | ✅ |
| 명령 수·인자 규칙 통과 | `parse_cmdfile` 직접 호출: 바꾼 뒤 run A 17/17, run B 31/1 | ✅ (수는 바뀐 파일 기준) |
| 예측 표(AB·AR·M4+AR·KM) | 내 python 예측 출력과 같음 | ✅ |
| 상한 없음 AB 는 512 나머지 필요 | 계산 원리(가장 큰 크기 300 → 정렬 512) 맞음 | ✅ 문구 반영 |
| 각 출력의 실제 `__common` 시작으로 판정 | 설계 보강 | ✅ |
| DA/D3 는 입력 `__common` 이 아니라 `__data` 정렬 시험 | 고정 입력 내용 그대로 | ✅ 문구 반영 |
| 커널 객체 `__data` 정렬 2^1(`param`·`ev`) | 이전 기록·`.align 1` 대조군 필요는 설계 판단 | ✅ `DH.s` 추가 |
| KM 은 앞선 크기 0 미정의 영향은 못 가름 | 고정 입력 내용 그대로 | ✅ 문구 반영 |
| 커널 컴파일은 `-static`(`m4p689-a1/run.cmd:2`) | 열람: `RUN /bin/cc -arch m68k -static -traditional-cpp …` | ✅ `CCs` 추가 |
| ld 버전 `cctools-209.4.obj~4`, 1997-04-22 | python 문자열 추출 결과 같음 | ✅ 반영 |
| `-sectalign … 10` 은 16진수 16 | ld 진단문 "not a proper hexadecimal number"(778.8 에서 확인) | ✅ |
| `-noseglinkedit` 와 `-static` 의 정해진 충돌 없음 | 진단문은 `-bundle`·`-dylib` 만(778.8 에서 확인) | ✅ |
| stdout 도 봐야 함 | 778.7: 미정의 진단이 stdout | ✅ 반영 |
| 전제 실패 판정·출력 판정의 층 | 설계 보강 | ✅ 반영 |
| 손 검사 항목(FAILED·두 입력 해시·nonregular·hardlinks·manifest 집합) | `kr_run.py:310–339` 의 collect 검사와 대조 | ✅ 반영 |
| 준비된 `src/` 를 원본과 직접 비교 | 계획 :155 열람(cp -p 빈 파일 함정) | ✅ 반영 |
| 도구 해시가 `/lib/m68k/as` 등을 덮지 않음 | `ALLOWED_TOOLS`(`kr_run.py:39–43`) 열람; `sha-a.txt` 8 줄 `/lib/m68k/as` | ✅ 반영 |
| ID 미등록·디렉터리 없음 | `REGISTRY` 에 `m7p778-p1b` 0 건, `ls` 결과 없음 | ✅ |
| 원본 파일 범위 733564·45708·779272·832196 | 778.8 C24 출력 같음 | ✅ |

### 778.11 P1b 결과 (실기 run `m7p778-p1b-1` 수집·`m7p778-p1bf-1` 미수집, 2026-11-08; 07·상태표·M4/M5 불변; 기록 `09_validation/reconstruction/m7-m68k-p778-p1b-20261108.json`, 판독 `scratch/p778/p1b_analyze.py`)
- run A 는 17 명령이 모두 종료 0 이고 stdout·stderr 가 비어 있어 수집했습니다(52 파일). run B 는 31 명령이 모두 종료 0 이고 진단 출력이 없습니다. 손 검사(778.10 ⑤)도 모두 통과했습니다: DONE, FAILED 없음, LOCK 해제, 입력 해시 두 번·도구 해시 일치, 상태 00–30 모두 0, `nonregular`·`hardlinks` 빔, manifest 의 파일 집합·해시가 실제 파일과 같음. run B 에서 다시 만든 객체 10 개는 run A 의 것과 해시가 같습니다(전제 조건 충족).
- **COMMON 정렬 상한은 출력 `__common` 절의 정렬과 같고, 그 값은 옵션으로 정해집니다.** 판정 입력 AB(`__common` 시작이 16 의 배수)에서:
  - 기본 옵션(A3): `0,0x10,0x20,0x30,0x58,0x60` 으로 상한 16 의 예측과 같고, 절 정렬 필드는 2^4 입니다. 778.7 의 "크기를 2 의 거듭제곱으로 올린 정렬" 은 상한 16 아래에서 본 것입니다(P1 에는 16 B 초과 크기가 없었음).
  - `-segalign 4`(A10)와 `-sectalign __DATA __common 4`(B3)와 둘을 함께 준 경우(B6): 모두 `0,4,0x14,0x18,0x40,0x44` 로 상한 4 의 예측과 같고, 절 정렬 필드는 2^2 입니다. 원본 `__common` 의 정렬 필드 2^2·상한 4(778.9)와 같습니다.
  - `-sectalign __DATA __common 10`(B4): 상한 16(기본과 같은 배치).
  - `-sectalign … 4` 는 입력이 더 큰 정렬을 요구하는 경우에도 경고 없이 쓰였습니다(778.8 의 진단문은 나오지 않음).
- AR·M4+AR 도 각 출력의 실제 시작 위치에서 같은 결론입니다. 기본(A1, 시작 16 의 배수)은 `_r4` 0x10(상한 8 이상)입니다. `-segalign 4`(A8, 16 으로 나눠 12 남음)는 0xc 로 두 상한이 같은 값입니다. `-sectalign … 4`(B1, 시작 16 의 배수)는 0xc(상한 4)입니다.
- 크기 충돌(A4, 기본): `_k`(처음 2, 나중 8)는 오프셋 8 입니다. 정렬은 처음 본 크기가 아니라 최종(최대) 크기로 정해집니다.
- 입력 `__data` 정렬(2^1·2^2·2^3; A5h·A5·A6)은 COMMON 배치를 바꾸지 않습니다(AR 오프셋이 A1 과 같음). 출력 `__data` 정렬 필드는 입력의 값을 따릅니다.
- 대상 `cc`(A7·A7s, `CCs.s`): `.comm` 크기는 짝수로 올립니다. `char` 2, `char[3]` 4, `short` 2, 3 B 구조체 4, `double` 8, `int` 4, `char[5]` 6, `char[16]` 16 입니다. `-static` 유무로 객체 파일은 다르지만 COMMON 값은 같고, 링크 결과(A7 = A7s)는 바이트가 같습니다.
- `__LINKEDIT`: `-noseglinkedit`(B7, B8, B9)는 `__LINKEDIT` 세그먼트를 만들지 않습니다. 적재 명령은 원본과 같은 꼴(세그먼트 3 개·symtab·unixthread, ncmds 5)입니다. B8(`-segalign 4 -noseglinkedit`)은 초기화 절의 끝 = `symoff`, `symoff` + 12×nsyms = `stroff`, `stroff` + strsize = 파일 크기로 원본과 같은 관계입니다. 다만 원본의 초기화 절 끝 733564 는 4 의 배수이므로, `__LINKEDIT` 가 있는 `-segalign 4` 출력(A12: 끝 644 = `symoff` 644)도 같은 관계가 될 수 있어 이 관계만으로는 구별되지 않습니다. 구별하는 것은 세그먼트 목록과 sizeofcmds 입니다.
- 원본과 다른 점: 탐침 출력의 `__TEXT`·`__DATA` 세그먼트 flags 는 4(SG_NORELOC)이고 원본은 0 입니다. 탐침 객체에는 재배치가 거의 없어 이 차이의 원인은 아직 모릅니다(전체 링크 P2 에서 봅니다). `__PAGEZERO` 의 vmsize 4·flags 4, 보호 속성(`__TEXT` 7/5, `__DATA` 7/3), 헤더 flags 1 은 원본과 같습니다.
- 뜻: NeXTMach `conf/Makefile.NeXT:30` 의 후보 옵션 `-segalign 4` 하나로 헤더 뒤 68 B·끝 2 B·`__PAGEZERO` 4(778.7)와 COMMON 상한 4(이 절)가 함께 설명됩니다. `-noseglinkedit` 는 `__LINKEDIT` 없음을 설명합니다. 원본이 실제로 이 옵션으로 링크되었다는 증거는 아닙니다. `-sectalign __DATA __common 4` 도 상한 4 를 만듭니다.
- 다음: P2(전체 링크 1차) 계획을 씁니다. 들어갈 것: `-segalign 4 -noseglinkedit`, subtype 처리 방법, 정의 없는 73 이름과 778.9 의 언급 차이를 어떻게 다룰지(07 변경은 사용자 결정), 층별 합격 기준. 코딩 전에 codex 검토를 받습니다.

### 778.12 P3 조사 계획 — 정의 없는 73 이름과 추가 언급 37 개의 소스 꼴 (코딩 전, 2026-11-08; 07·상태표·도구 불변)
사용자 지시 "다음 작업을 신중하게 진행" 에 따라, 778.11 끝의 결정 요청 가운데 **조사**(읽기 전용·탐침)만 진행합니다. 07 변경안은 조사 결과로 만들어 다시 결정을 받습니다.

**(1) 지금까지 찾은 것**(읽기 전용 python·grep; `scratch/p778/p3_scan.py`, 결과 `p3_hits.json`·`p3_decl.json`; 이 스크립트는 후보를 찾는 정규식이며 C 파서가 아닙니다)
- 내 검색 오류(먼저): `p3_scan.py` 의 `os.walk` 는 맨 위 링크(`01_resources/local_mirrors/headers` → `../../../ref/openstep/headers`)만 따라가고 그 아래 링크 디렉터리는 따라가지 않습니다. 그래서 SDK 헤더를 일부 빠뜨렸고, 그 뒤 `find -L` 로 따로 찾았습니다.
- NeXTMach mk-108.1 헤더에는 이 이름들이 `extern` 없는 임시 정의(포함한 객체마다 COMMON 이 생기는 꼴)로 있습니다. 대부분 `KERNEL`·`ASSEMBLER` 조건 안에 있습니다(예: `next/cpu.h:42,64,81,88`). 원본 커널 기호와 python 으로 맞춘 결과는 다음과 같습니다.
  - `nextdev/ev_vars.h`: 임시 정의 43 개 가운데 37 개가 원본 `__common` 에 있고, 구간 r69 에 36 개, r67 에 1 개(`_eventsOpen`)가 속합니다. 6 개(`evp`·`eventGlobals`·`waitFrameNum`·`versionSet`·`nxCursorData`·`undimmedBrightness`)는 원본에 없습니다. 반대로 원본 r69 에는 이 헤더에 없는 이름(`evg`·`evs`·`eop`·`evScreen`·`evScreenSize`·`screens`·`currentScreen`·`totalShmemSize`·`lastPressure`·`sessionPrecision`·`sessionPressure`·`evRetryMask`·`dimmedBrightness` 등)이 있습니다. 따라서 이 헤더를 그대로 쓰는 가설은 맞지 않습니다. 다만 원본이 `ev_vars.h` 꼴의 헤더를 썼는지, 선언이 소스 파일들에 나뉘어 있었는지는 이것만으로 가를 수 없습니다.
  - `next/cpu.h`: 임시 정의 `master_cpu`·`dma_chip`·`disk_chip`·`machine_type`·`board_rev`·`cpu_type`·`intrmask`·`intr_mask`·`slot_id`·`slot_id_bmap`(조건부). `disk_chip` 은 원본에 없습니다. SDK 1997 `bsd/m68k/cpu.h:45` 이하는 이와 다른 `extern` 선언 묶음(`dma_chip`·`cpu_rev`·`cpu_clk`·`machine_type`·`board_rev`·`cpu_type`·`mon_rev`, `KERNEL || STANDALONE` 조건)입니다.
  - `next/scr.h:114` 이하: `scr1`(원본에 없음)·`scr2`·`brightness`. `next/bmap.h:55`: `bmap_chip`. `next/pmap.h:186` 이하: `pv_head_table`·`pv_list_zone`·`pv_lock_table`(원본에 없음).
  - 07 의 `nextdev/bsd/net/route.h:90`(`rthost`·`rtnet`·`rtstat`), `netinet/ip_var.h:124`(`ipstat`·`ipq`·`ip_id`), `netinet/udp_var.h:50`(`udb`·`udpstat`)는 이미 임시 정의를 가집니다(우리 `in_pcb` 등이 COMMON 으로 언급).
  - NeXTMach `next/next_init.c:94–95` 에 `struct mem_region mem_region[MAX_REGIONS];`·`struct bootp bootp;` 가 있고, `next/nextdbg.c:417` 에 `struct kdb_net kdb_net;` 이 있습니다. 모두 참고 소스의 후보일 뿐 원본의 선언 위치는 아닙니다. 우리 `nextdbg.c:207` 의 형은 `struct kdb_n { char *ri; char *ti; int locked; }` 로 NeXTMach `struct kdb_net`(`next/nextdbg.h:21`)과 다르므로, 후보마다 따로 시험합니다.
- 07 의 m68k 소스는 이 이름들을 파일 안 `extern` 으로 둡니다(예: `ev.c:144`·`ev_ioctl.c:112`·`ev_kbd.c:86`·`ev_mouse.c:67`·`km.c:140`·`video.c:164`·`adb.c:75`·`m68k_init.c:107`).
- 778.9 의 `subr_prf` 추가 언급 9 개 가운데 8 개(`_ip_id`·`_ipq`·`_ipstat`·`_rthost`·`_rtnet`·`_rtstat`·`_udb`·`_udpstat`)는 NeXTMach `mon/global.h:40` → `mon/tftp.h:8,14,16` → `net/route.h`·`netinet/ip_var.h`·`netinet/udp_var.h` 사슬과 맞습니다(`_bmap_chip` 은 이 사슬로 설명되지 않음). 07 `nextmach/mon/global.h:49` 는 이 `#import <mon/tftp.h>` 를 **사용자 결정 D133**(계획 585, `DECISIONS.md:137`)으로 뺐습니다. 이유는 `machdep.c` 컴파일 때 `netinet/ip.h` 의 `struct ip_timestamp` 가 07 `ipc/ipc_port.h:148` 의 `#define ip_timestamp data.timestamp` 와 부딪힌 것입니다(`08_build/runs/m4p584-p1/stage/_log/00.err`). 계획 583(빼기 전)의 M5 `subr_prf` 에서는 COMMON 이 14 개 늘었습니다(python: `_alert_key`·`_etherbroadcastaddr`·`_ifnet`·`_ip_id`·`_ipq`·`_ipstat`·`_km`·`_km_coni`·`_rawintrq`·`_rthost`·`_rtnet`·`_rtstat`·`_udb`·`_udpstat`; 텍스트 바이트와 의미상 외부 재배치는 같고 원시 재배치 표는 다름). 이 증거로 D133 을 다시 여쭐 수 있지만, 다시 여는 것이 유일한 방법이라는 뜻은 아닙니다(아래 (3)).
- `kern_exit.c`(07 `v183.34/m68k/src/bsd/kern/kern_exit.c:99–103`)는 NeXTMach `next/scr.h` 의 기계 형 상수를 파일 안에 두었습니다(plan 471). 원본 `kern_exit` 가 `scr2`·`brightness` 를 언급한다는 778.9 결과는 "`scr.h` 꼴의 선언이 `kern_exit` 에서 살아 있었다" 는 해석과 맞지만 증명은 아닙니다.

**(2) 무엇을 확인할지**
- 가설 꼴: ① 헤더 H 가 이름 N_H 를 임시 정의로 가짐 ② 파일 F 가 이름을 임시 정의로 가짐. ①에서는 H 를 포함한 객체 가운데 **그 선언이 전처리 뒤에도 살아 있는** 객체가 모두 N_H 를 언급하게 됩니다(조건문·`#import` 중복·매크로에 따라 다름). 그러므로 헤더가 있는지만 보는 판정은 쓰지 않고, 후보 변경을 실제로 컴파일한 객체로 판정합니다.
- 예: 원본에서 `dma_chip`·`slot_id` 가 `vol`(링크 순번 207, 텍스트 순번 199)에서 처음이므로, 이 둘의 살아 있는 임시 정의는 `vol` 보다 앞 객체에 있으면 안 됩니다. `board_rev`(원본 첫 언급 `snd_dspdev`, 링크 순번 236)는 같은 헤더에 있더라도 조건에 따라 `vol` 에서는 꺼져 있을 수 있으므로, 함께 살아 있을 때만 그 가설을 버립니다.
- 크기: 실제 컴파일한 `.comm` 크기(반올림 뒤, 778.11)가 778.8 (2) 의 범위 안이어야 하고, 모든 객체에서의 최대 크기로 이웃 조건을 함께 만족해야 합니다(`sizeof` 와 `.comm` 크기는 따로 기록).

**(3) 방법**
- P3a(포함 목록): 각 객체를 만든 컴파일 줄은 296 개 모두 그 run 의 `run.cmd` 에서 `-o` 로 찾을 수 있습니다(python: 실패 0). M4 76·D 13 은 그 run 에 같은 소스의 `-M` 출력이 이미 있으므로 다시 씁니다. M5 204·R 3 은 `-M` 출력이 없으므로, 각 객체를 만든 run 의 당시 stage(M5 `08_build/runs/tools/m0p764-a1-stage`, R `08_build/runs/tools/m4p777-base-stage`; 각 run 의 `prepare.json`)로 새 run 에서 `-M` 을 돌립니다. 컴파일 줄에서 `-c` 를 `-M` 으로 바꾸고 `-o 출력` 한 쌍을 지울 뿐 다른 인자는 그대로 둡니다. 어셈블리 객체도 포함합니다(`locore.s` 의 `-M` 이 `bsd/next/cpu.h` 등을 읽음). STABS 로는 대신할 수 없습니다(296 객체 중 `N_SOL` 등이 있는 것 29). `-M` 출력 형식은 기존 기록과 같은 Make 꼴(`src/...` 상대 경로, 백슬래시 줄 잇기)으로 보며, 다르면 그 사실을 기록합니다. 시간 예산은 미리 정하지 않고 run 의 시작·끝 시각을 기록합니다.
- P3b(후보 변경의 실제 컴파일): 07 을 고치지 않고, scratch 오버레이 stage(당시 stage 의 사본에 후보 헤더·파일 변경을 얹은 것)에서 영향받는 객체(P3a 포함 목록으로 고름)를 실기에서 다시 컴파일합니다. 그 객체들의 실제 `nlist` 를 P0 모델에 넣어 다음을 모두 봅니다.
  - 원본 613 순서·주소와 절 끝, 그리고 재배치 대조
  - 원본에 없는 이름이 새로 할당되는지, 미해결 이름, 정의 우선으로 사라지는 이름, 이름별 최대 크기
  - 자료 단위 13 개의 배치(언급이 새로 생기는 단위 포함)를 다시 찾음
  - 다시 컴파일한 객체의 절 바이트와 의미상 외부 재배치(기호 이름 + 덧붙임 값)가 지금 객체와 같은지(원시 재배치 표와 파일 전체는 기호 번호가 바뀌므로 비교하지 않음)
- 후보 묶음(서로 따로·함께 시험): (a) D133 유지 + 영향받는 m68k 소스에 필요한 선언만 둠 (b) `mon/global.h` 의 `tftp.h` 를 되살리고 `ip_timestamp` 충돌을 따로 푸는 꼴(포함 순서·매크로 범위; 시험 전에는 어느 것도 검증되지 않음) (c) ev 계열은 헤더 하나 대 `ev.c` 안 선언 (d) `scr.h`·`cpu.h` 꼴의 m68k 헤더 대 파일 안 선언 (e) `kdb_net`·`bootp` 는 778.9 의 최적 객체 집합 안의 후보마다 따로 시험합니다. 형은 후보마다 출처를 밝힙니다(예: `KeyMapping` 은 07 `ev_kbd.c:75` 의 판으로 `specialKeys`(`:83`)를 가지며 NeXTMach 판과 다름; `struct mem_region` 은 07 `vm/pmap.h:167`, 배열 크기는 따로 정함).
- 결과 → 07 변경안: 이름마다 넣을 곳(07 경로와 stage 경로)·조건·형·배열 크기·근거(참고 소스 파일:줄과 판)·고지·결과 크기·순서와 주소 시험 결과·회귀 기록·이전 결정(D133 등)과의 관계를 적습니다. 모든 꼴은 "바이트에 맞춘 후보" 로 표시합니다. 공유 헤더(예: `net/route.h`)가 바뀌면 x86 입력·stage 검사와, 필요하면 x86 실기 재빌드·비교도 조건으로 둡니다. 구현이 결정되면 `PROVENANCE.tsv`·`MODIFICATIONS.md`·증거 문서를 고칩니다.

**(4) 하지 않는 것·한계**: 07·상태표·M4/M5 객체를 바꾸지 않습니다. P3b 의 오버레이는 scratch 이며 07 이 아닙니다. 포함 목록은 우리 재구성의 것이며 원본의 포함 관계가 아닙니다. 가설이 순서를 재현해도 원본 소스의 증명이 아닙니다. 바이트가 가르지 못하는 꼴은 사용자 결정으로 올립니다. 778.9 의 결과(직접 링크·후보 배치 가정에 따른 최소 비용 해)는 소스 사실이 아닙니다. 커밋하지 않습니다.

#### 778.12.1 codex 검토 판정표(작업 `kf3i8r9p7`)
내가 틀렸던 것(먼저): ① `vol` 의 순번 207 을 "텍스트 순번" 이라 적었습니다(링크 순번이며 텍스트 순번은 199). ② 검색 스크립트가 링크를 따라간다고 적었으나 `os.walk` 는 맨 위 링크만 따라갑니다. ③ 어셈블리 객체를 헤더 가설의 영향 밖으로 뺐습니다. ④ 모든 객체에 지금 stage 하나를 쓰려 했습니다(객체를 만든 당시 stage 와 다름). ⑤ "1997 판은 다른 헤더" 와 "`board_rev` 가 있으면 안 됨" 을 너무 단정했습니다. ⑥ 헤더가 있는지만으로 언급을 판정하려 했습니다(조건문 무시).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| ev_vars.h 43/37/6, r69 36·r67 1 | python: `43-6 = 37`, `Counter({'r69': 36, 'r67': 1})` | ✅ |
| r69 에 헤더에 없는 이름들 | `p0_annot.txt` 와 위 목록 대조(이전 출력) | ✅ |
| "다른 판" 단정은 과함 | 논리 맞음 | ✅ 문구 고침 |
| cpu.h 선언은 조건부(`:42,64,81,88`) | 열람: `#ifndef ASSEMBLER`·`#ifdef KERNEL`·`#ifdef KERNEL`·`#if KERNEL` | ✅ 반영 |
| SDK cpu.h 는 다른 extern 묶음(`:45`) | 열람: `#if KERNEL \|\| STANDALONE` | ✅ 문구 고침 |
| scr.h:114, bmap.h:55, pmap.h:186 | 열람: `#ifndef ASSEMBLER`·`volatile struct bmap_chip *bmap_chip;`·`#ifdef KERNEL` | ✅ (줄은 각 구역 시작) |
| route.h:90·ip_var.h:124·udp_var.h:50 | 이전 grep 출력과 같음 | ✅ |
| next_init.c:94–95, nextdbg.c:417 | 이전 grep 출력과 같음 | ✅ |
| 파일 안 extern 예(`ev.c:144` 등) | 이전 grep 출력(`ev.c 144 extern EvGlobals *evg;` 등)과 같음 | ✅ |
| `p3_scan.py:12` 는 followlinks 없음, 링크 `../../../ref/openstep/headers` | 열람·`readlink` 출력 같음 | ✅ 내 오류 정정 |
| global.h:40 → tftp.h:8,14,16, bmap_chip 은 설명 안 됨 | 이전 grep 출력 | ✅ |
| D133 요약, `m4p584-p1/stage/_log/00.err` | `DECISIONS.md:137` 열람; err 첫 줄 `In file included from src/src/mon/tftp.h:13,` | ✅ |
| 계획 583 의 subr_prf 새 COMMON 14 | python: 14 개 이름 같음 | ✅ 이름 반영 |
| kern_exit 해석은 가설 | 논리 맞음 | ✅ 문구 고침 |
| `vol` 텍스트 199 / 링크 207, `snd_dspdev` 225/236, `adb` 200/208 | python 출력 같음 | ✅ 내 오류 정정 |
| 살아 있는 선언만 언급이 됨(조건문) | 위 cpu.h 조건 열람 | ✅ 실제 컴파일로 판정 |
| `board_rev` 배제는 함께 살아 있을 때만 | 논리 맞음 | ✅ 반영 |
| 정의 우선을 먼저 적용, 원본에 없는 할당 보고 | P0 도구 `cmd_common` 의 `overridden` 처리 열람 | ✅ 반영 |
| 최적 배치·73/37/7 은 소스 사실 아님 | P0 기록 열람(73·37·7) | ✅ |
| 전체 기호 집합으로 판정 | 설계 보강 | ✅ 반영 |
| 언급이 바뀌면 자료 단위 배치를 다시 찾음 | 도구의 `NOT_TARGET` 고정 열람 | ✅ 반영 |
| 컴파일 줄 296 개 모두 찾을 수 있음 | python: 실패 0 | ✅ |
| `-M` 있음 M4 76·D 13, 없음 M5 204·R 3 | python 같은 수 | ✅ 반영 |
| 어셈블리 객체도 `-M` 이 있음(`locore.o: … cpu.h`) | `m4p754-a1/out/_log/01.out` 열람 | ✅ 내 오류 정정 |
| 당시 stage 는 `m0p764-a1-stage`·`m4p777-base-stage` | `prepare.json` 의 `src` 출력 같음 | ✅ 반영 |
| `-M` 출력 형식 | `m4p754-a1` 의 `locore.o: src/...` 출력 열람 | ✅ |
| STABS 는 대신 못 함(29 대 267) | python: with 29, without 267 | ✅ |
| 시간 예산 근거 없음 | 맞음 | ⚖️ 예산을 두지 않고 시각만 기록(같은 크기의 컴파일 run `m3p764-cc1` 이 이미 끝까지 돈 선례) |
| 크기 탐침은 맥락을 밝혀야 함, sizeof 와 .comm 따로 | 778.11 반올림 결과 | ✅ 반영 |
| `KeyMapping` 은 `ev_kbd.c:75`·`:83`, `mem_region` 은 `pmap.h:167`·`:209` | 열람 같음 | ✅ 반영 |
| `kdb_n` 은 `nextdbg.c:207`, NeXTMach `kdb_net` 은 `nextdbg.h:21` | 열람 같음 | ✅ 반영 |
| COMMON 이 늘면 원시 재배치 표가 바뀜 | python: 텍스트 같음, 원시 재배치 다름, 의미상 외부 재배치 같음 | ✅ 반영 |
| 회귀 기준·x86 범위·D133 대안·출처 계약 | 설계 보강(`PROVENANCE.tsv` 등은 구현 결정 뒤) | ✅ 반영 |

### 778.13 P3a 결과와 첫 오프라인 시험 (2026-11-08; 07·상태표·M4/M5 객체 불변)
- 도구: `m7_m68k_link.py` 에 `depcmd`(`-M` 명령 파일 생성)와 `deps`(포함 목록 기록)를 더했습니다. `spec`·`common` 의 코드는 바꾸지 않았지만 파일 해시는 바뀌었습니다(778.9 기록의 `0f359ced…` → 지금 `3562d1f7…`).
- `-M`: M4 76·D 13 은 각 객체를 만든 run 의 기존 `-M` 출력(상태 0·stderr 빔)을 다시 썼습니다. M5 204 는 새 run `m7p778-dep-1`(src = `08_build/runs/tools/m0p764-a1-stage`), R 3 은 `m7p778-dep-2`(src = `m4p777-base-stage`)에서 만들었습니다. 두 run 의 `src/` 는 각 객체를 만든 run(`m3p764-cc1`·`m4p777-a1`)의 `src/` 와 파일 집합·바이트가 같습니다(python, 1030·1043 파일). 줄 꼴은 기존 선례(`m4p777-a1` 의 `-M` 줄)와 같은 변환(`-c`→`-M`, `-o` 쌍 지움)입니다. 두 run 모두 상태 0 이고 수집했습니다. dep-1 은 2026-11-08T14:01:27Z–14:05:43Z 에 걸렸고, stderr 가 있는 것은 1 개(`if_ether.c:101` `NEN` 재정의 경고)입니다. 기록 `09_validation/reconstruction/m7-m68k-p778-p3a-deps-20261108.json`(SHA-256 `965cc694…`; 296 객체, 의존 항목 22721).
- 링크 순서(778.9 의 보고 배치)에서 각 헤더를 처음 포함하는 객체:
  - `mon/global.h`(11 객체)는 `subr_prf`(25)
  - `machdep/m68k/pmap.h`·`vm/pmap.h`(163)는 `cmu_syscalls`(1)
  - `bsd/dev/m68k/event.h`·`evio.h`(6)는 `ev`(213)
  - `bsd/m68k/cpu.h`(145)는 `cmu_syscalls`(1)
  - `bsd/m68k/bmap.h`(7)는 `km`(222)
  - `net/route.h`(26)는 `sys_socket`(28)
  - `netinet/ip_var.h`(16)는 `in_pcb`(65)
  - `netinet/udp_var.h`(4)는 `ip_input`(68)
  - `vol`(207)이 처음 포함하는 헤더는 `kernserv/insertmsg.h`·`kernserv/prototypes.h`·`bsd/dev/m68k/autoconf.h`·`kernserv/m68k/us_timer.h`·`bsd/dev/voldev.h` 등이고, `kern_exit`(9)는 `sys/wait.h`·`sys/mbuf.h`·`sys/syslog.h` 입니다.
  - 따라서 778.9 의 추가 언급 가운데 `subr_prf`·`cmu_syscalls`·`ev` 의 것은 "그 객체가 처음 포함하는 헤더의 임시 정의" 로 설명될 수 있습니다. `cpu.h` 에 `dma_chip`·`slot_id` 의 살아 있는 임시 정의가 있으면 첫 언급이 `cmu_syscalls` 가 되어 원본(`vol`)과 어긋납니다. `bmap.h` 의 `bmap_chip` 은 `km` 이 처음이라 원본(`subr_prf`)을 설명하지 못합니다. NeXTMach `next/scr.h` 는 `bmap.h` 를 포함하지 않습니다(`:9` 주석뿐).
- 첫 오프라인 시험(실제 컴파일된 객체): 계획 583(D133 이전, `mon/global.h` 가 `mon/tftp.h` 를 포함)의 M5 `subr_prf` 객체 `08_build/runs/m3p583-cc1/out/O583__L2_159__subr_prf.o`(SHA-256 앞 16 자리 `8c0867de8fb68ad6`)는 지금 객체와 `__text` 바이트·의미상 외부 재배치가 같습니다. COMMON 은 11 개 더 많습니다(`_etherbroadcastaddr`·`_ifnet`·`_ip_id`·`_ipq`·`_ipstat`·`_rawintrq`·`_rthost`·`_rtnet`·`_rtstat`·`_udb`·`_udpstat`). 이 객체를 지금 `subr_prf` 대신 넣고 같은 배치로 DP 를 다시 돌리면 최소 비용이 37 에서 29 로 줄고, 줄어든 8 은 정확히 네트워크 이름 8 개입니다. 남는 추가 언급은 `ev` 20·`cmu_syscalls` 2·`kern_exit` 2·`vol` 2·`subr_prf` 1(`_bmap_chip`)·`if_en` 1·`miniMonMachdep` 1(`_bootp`)입니다. 늘어난 다른 이름은 원본 순서를 해치지 않습니다: `_ifnet`·`_rawintrq` 는 이미 `cmu_syscalls` 가 먼저 언급하고, `_etherbroadcastaddr` 는 `__data` 정의가 이깁니다.
- 뜻: D133 이전 꼴(`tftp.h` 포함)이 원본 `__common` 과 더 잘 맞는다는 실제 객체 증거입니다. 다만 D133 의 원인(`machdep.c` 의 `ip_timestamp` 충돌)은 그대로이므로, 되돌릴지와 충돌을 어떻게 풀지는 사용자 결정입니다.
- 다음(P3b): `cmu_syscalls`(`pmap.h` 꼴), `ev` 계열, `kern_exit`(`scr.h` 꼴), `vol`, `bmap_chip`, `kdb_net`·`bootp`, 크기만 필요한 이름의 후보를 scratch 오버레이에서 실제로 컴파일해 같은 방법으로 시험합니다. 07 변경안은 그 뒤 사용자 결정으로 올립니다.

### 778.14 P3b 설계 — 후보 꼴을 scratch 오버레이에서 실제로 컴파일하는 시험 (코딩 전, 2026-11-08; 07·상태표·M4/M5 객체 불변)
사용자 지시 "진행하세요"(778.13 뒤)에 따라 P3b 를 진행합니다. D133 에 대한 결정은 아직 받지 않았으므로 (가) 유지 쪽과 (나) 되살림 쪽을 모두 scratch 에서만 시험합니다. 시험 꼴은 바이트에 맞는지 보려는 것이며 07 변경안이 아닙니다. 변경안은 결과를 보고 따로 결정을 받습니다.

**(1) 기준과 오버레이**
- 기준: 고칠 객체마다 그 객체를 만든 run 의 `src/` 를 씁니다. M4 의 당시 stage 디렉터리(`tools/m4p689a1-stage` 등)는 지금 없습니다. 대신 쓰는 run `src/` 10 개는 `input.expected` 의 모든 항목과 해시가 같습니다(python, 불일치 0): `m3p764-cc1`(M5 `subr_prf`·`cmu_syscalls`·`kern_exit`·`vol`), `m4p689-a1`(`ev`), `m4p727-a2`(`if_en`), `m4p680-a1`(`m68k_init`), `m4p739-a1`(`nextdbg`), `m4p766-a1`(`adb`), `m4p679-a1`(`clock`·`km`·`machdep`·`zscom`), `m4p724-a1`(`ev_ioctl`), `m4p729-a1`(`ev_kbd`), `m4p761-a1`(`video`). 대상 소스는 지금 07 의 해당 판과 바이트가 같습니다(codex 확인을 내가 다시 확인할 항목: 아래 판정표).
- 오버레이: 기준을 `scratch/p778/p3b/<run>/` 에 복사하고, 아래 꼴의 파일만 바꿉니다(정확히 한 번 나오는 문자열을 바꾸고, 기준과의 diff 를 기록). 경로는 기준 기준 상대(`<기준>/src/mon/global.h` 가 run 안에서는 `src/src/mon/global.h`)입니다. 컴파일 줄은 그 객체를 만든 줄 그대로이며 `-o` 출력 이름만 바꿉니다.
- run: 기준 재현 run 1 개(`m3p764-cc1` 의 `src/` 그대로, M5 대상 4 개; 수집; 지금 실기 도구로 다시 만든 `.o` 가 받아들인 객체와 파일째 같아야 함), 그리고 꼴마다 미수집 run(처음 쓰는 꼴이라 실패 가능; 778.10 ⑤ 의 손 검사; 명령마다 종료 상태와 진단문으로 판정)입니다.

**(2) 시험 꼴**(괄호는 778.9 의 원본 첫 언급 객체)
- F1 (나): `mon/global.h` 에 NeXTMach 의 `#import <mon/tftp.h>` 를 되살리고(07 의 plan 585 주석 줄 자리), 07 `nextmach/mon/tftp.h`·`mon/bootp.h` 를 `src/mon/` 에 둡니다. 대상은 `subr_prf`(8 이름)입니다. 진단으로 `mon/global.h` 를 포함하는 나머지 10 객체(`adb`·`clock`·`ev`·`ev_ioctl`·`ev_kbd`·`km`·`m68k_init`·`machdep`·`video`·`zscom`)도 같은 꼴로 컴파일합니다. 그중 `machdep` 은 `ip_timestamp` 충돌로 실패를 예상합니다(`machdep.c:157` 이 `kern/task.h`·`kern/thread.h` 를 `mon/global.h` 보다 먼저 import; `ipc_port.h:148`).
- F1′ (가): `mon/global.h` 는 그대로 두고 `subr_prf.c` 의 `#import <mon/global.h>` 다음에 `#import <mon/tftp.h>` 를 둡니다(같은 두 파일을 `src/mon/` 에 둠). 대상은 `subr_prf` 입니다.
- F2: `machdep/m68k/pmap.h` 의 마지막 `#endif` 앞에 `#ifdef KERNEL` 으로 감싼 `struct pv_entry *pv_head_table;`·`struct zone *pv_list_zone;`(`pmap.c:274–278` 의 `pv_entry_t`, `zalloc.h:83` 의 `struct zone` 과 같은 형)를 둡니다. 대상은 `cmu_syscalls` 입니다.
- F3: `kern_exit.c:99–103` 의 파일 안 상수 묶음 대신 `#import <m68k/scr.h>` 를 둡니다. 새 `src/bsd/m68k/scr.h` 는 NeXTMach `next/scr.h` 의 사본에서 원본에 없는 `scr1` 임시 정의 한 줄을 뺀 것입니다. `kern_exit.c` 가 쓰는 상수는 `NeXT_CUBE`·`NeXT_X15` 뿐이며 값이 같습니다. 대상은 `kern_exit` 입니다.
- F4: `vol.c` 의 import 들 뒤에 파일 범위 `u_short dma_chip;`(보이는 선언 `bsd/m68k/cpu.h:48` `extern u_short dma_chip;` 과 같은 형)·`int slot_id;` 를 둡니다(출처 없는 시험 꼴). 대상은 `vol` 입니다.
- F5: `subr_prf.c` 의 `#import <mon/global.h>` 다음에 `#import <m68k/bmap.h>` 를 둡니다(07 `bsd/m68k/bmap.h:55` 에 `bmap_chip` 임시 정의). F1·F1′ 와 함께 시험합니다. 대상은 `subr_prf` 입니다.
- F6: 새 시험 헤더 `src/machdep/m68k/ev_vars.h` 를 `ev.c` 만 import 합니다(import 묶음 끝). 헤더 내용:
  - `ev_kbd.c:66–67` 의 `NUMKEYCODES`·`NUMMODIFIERS`(값을 `#ifndef` 로 감쌈)
  - `ev_kbd.c:75–85` 의 `KeyMapping` 형 정의(`NX_NUMSPECIALKEYS` 는 `bsd/dev/ev_keymap.h:41`)
  - 50 이름의 임시 정의. 형은 07 `extern` 에서 가져오고, 마우스 배열은 `[MAXMOUSESCALINGS]`(= `NX_MAXMOUSESCALINGS` 20, `ev_types.h:19`; 20×2 = 40 B)로 둡니다.
  - 대상은 `ev` 이며, (나) 쪽에서는 F1 과 함께 컴파일합니다.
- F7: `if_en.c` 의 import 들 뒤에 파일 범위 `struct kdb_n { char *ri; char *ti; int locked; } kdb_net;`(07 `nextdbg.c:207` 의 형)를 둡니다. 대상은 `if_en` 입니다.
- F8: `m68k_init.c` 에 `#import <netinet/in.h>`·`#import <netinet/bootp.h>`(07 `nextdev/bsd/netinet/bootp.h:17` 의 `struct bootp` 은 `struct in_addr` 를 씀)를 두고, 다음 파일 범위 임시 정의를 둡니다. 형은 그 파일과 보이는 헤더의 선언과 같게 합니다.
  - `struct bootp bootp;`
  - `u_char cpu_type, machine_type, mon_rev, board_rev, cpu_clk, cpu_rev;`(SDK `bsd/m68k/cpu.h`)
  - `int intr_mask;`, `int (*reboot_vector)();`(`m68k_init.c:199`), `int vmlog_send;`
  - `struct mem_region mem_region[MAX_REGIONS];`(원소 28 B × `MAX_REGIONS` 8 = 224 B; `vm/pmap.h:167`, `mach/m68k/vm_param.h:82`), `int num_regions;`
  - `volatile int *intrmask;`, `int ncc_chip;`, `int slot_id_bmap;`, `u_long kdb_ipaddr;`(`m68k_init.c:205`), `vm_offset_t interrupt_stack[NCPUS];`(`NCPUS` 1)
  - 이 이름들의 원본 첫 언급은 모두 `m68k_init`(링크 순번 270)과 같거나 앞입니다(python). 대상은 `m68k_init` 이며, (나) 쪽에서는 F1 과 함께 컴파일합니다.
- F9: `nextdbg.c` 에 `struct dbg_pkt *dbg_connect_pkt;`(같은 파일 `:204` 의 `extern` 과 같은 형)를 둡니다. `_dbg_connect_pkt` 의 원본 첫 언급이 `nextdbg`(272)이므로 F8 에 넣으면 순서가 틀립니다. 대상은 `nextdbg` 입니다.
- 이름 묶음(`scratch/p778/p3b_groups.json` 을 F9 로 고쳐 다시 셈): F1 8·F2 2·F3 2·F4 2·F5 1·F6 50·F7 1·F8 17·F9 1, 합집합 84 = 73 + 37 − 26(겹침)입니다. 정의 없는 73 과 추가 언급 37 이 모두 들어 있고, 그 밖의 이름은 없으며, 우리 296 객체 어디에서도 이 이름들은 정의(SECT)되지 않습니다.

**(3) 판정**(python, `m7_m68k_link.py` 의 `parse`)
- 다시 컴파일한 객체와 받아들인 객체를 비교합니다.
  - 절 목록·크기·정렬, `__text`·`__data`·`__const`·`__cstring` 바이트, `__bss` 크기가 같아야 합니다.
  - 정의 기호(이름·절·값)가 같아야 합니다.
  - 재배치는 모두 의미로 비교합니다: 절·주소·길이·PC 상대·형식, 외부는 기호 이름, 지역은 절 번호, 산포는 값.
  - 새 COMMON 은 계획한 이름과, F1·F1′ 에서 이미 관찰된 이름(`_etherbroadcastaddr`·`_ifnet`·`_rawintrq`)만 허용합니다. 최종 링크에서 살아남는 새 할당이 원본에 없으면 실패입니다.
- 모델: 다시 컴파일한 7 객체(`subr_prf`·`cmu_syscalls`·`kern_exit`·`vol`·`ev`·`if_en`·`m68k_init`; `nextdbg` 포함 시 8)로 바꾼 296 객체 집합에 다음을 계산합니다.
  - 합성 선언이나 DP 보정 없는 `model_seq` 순서가 원본 613 순서와 같은지(문자열 제약을 지키는 576 배치 각각)
  - 실제 크기(모든 객체의 최대)·정의 우선·상한 4 에서 주소·절 끝이 같은지, 재배치 7592 개가 원본 바이트와 같은지
  - 크기를 가정한 이름이 남지 않는지
  - DP 보정이 필요하면 따로 보고합니다.
  - (가)·(나)를 따로 계산합니다.
- F1 진단 컴파일의 실패는 진단문으로 분류해 따로 적습니다. 이것은 DP 비용과 다른 범주입니다.

**(4) 하지 않는 것·한계**: 07·상태표·M4/M5 객체를 바꾸지 않습니다. F4·F5·F7·F9 의 위치, F6 의 헤더 이름, F8 에 이름을 모은 것은 출처 없는 시험 선택이며 바이트가 맞는지만 보여 줍니다. 헤더를 포함하는 다른 객체는 (나)의 진단 말고는 다시 컴파일하지 않습니다. 순서는 첫 언급 객체가 정하지만, 다른 객체의 최대 크기·새 이름·코드 영향은 이 시험으로 보이지 않으므로 07 변경 뒤 영향받는 모든 객체를 회귀 검사합니다(778.12 (3)). 커밋하지 않습니다.

#### 778.14.1 codex 검토 판정표(작업 `kg7rgam5j`)
내가 틀렸던 것(먼저): ① F8 의 `int reboot_vector` 는 `m68k_init.c:199` 의 `extern int (*reboot_vector)();` 와 충돌합니다. ② F8 에 `struct bootp` 의 정의가 보이지 않습니다(`m68k_init.c:163` 주석: 일부러 뺌). ③ F6 의 `KeyMapping` 은 `ev_kbd.c` 안의 매크로가 필요하고, 형 정의 끝은 85 줄입니다. ④ `_dbg_connect_pkt` 의 원본 첫 언급은 `nextdbg`(272)로 `m68k_init`(270)보다 뒤입니다. ⑤ M4 의 당시 stage 디렉터리가 없다는 것을 확인하지 않았습니다. ⑥ F1 의 COMMON 허용 목록이 이미 관찰된 이름을 빠뜨렸습니다. ⑦ "다른 객체는 결과에 영향 없음" 은 너무 셌습니다. ⑧ 대상 객체 수(7, `nextdbg` 포함 8)를 8 이라 적었습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `reboot_vector` 형 충돌(`m68k_init.c:199`) | 열람: `extern int (*reboot_vector)();` | ✅ 정정 |
| `struct bootp` 이 보이지 않음(`:163`) | 열람: "struct bootp bootp left out" 주석; 07 `bootp.h:15,17` `struct in_addr` 사용 | ✅ import 두 줄 추가 |
| `KeyMapping` 매크로, 끝 85 줄 | 열람: `ev_kbd.c` 66–67 `NUMKEYCODES 128`·`NUMMODIFIERS 16`, 85 `} KeyMapping;`; `ev_keymap.h:41` `NX_NUMSPECIALKEYS 9` | ✅ 정정 |
| `_dbg_connect_pkt` 첫 언급 `nextdbg` 272 > 270 | python: `first M4:nextdbg 272 m68k_init 270` | ✅ F9 로 옮김 |
| 그대로면 576 배치 모두 순서 틀림, 빼면 96 | 도구 기호 모델 재현은 하지 않음(위 순번으로 원인 확인) | ⚖️ 원인만 확인, 수치는 옮기지 않음 |
| M4 당시 stage 4 개가 없음 | `ls`: 네 디렉터리 모두 없음 | ✅ run `src/` 로 대체 |
| run `src/` 입력 해시 일치 | python: 10 기준 모두 불일치 0 | ✅ |
| 경로는 기준 기준 상대 | `m3p764-cc1/src` 아래 `components generated nextdev src` | ✅ 반영 |
| `global.h`·`pmap.h`·`bmap.h` 있음, `tftp.h`·`bootp.h`·`scr.h` 없음 | 기준 `src/` 확인은 빌더 스크립트가 단정(assert)으로 함 | ⚠️ 빌더에서 확인 |
| 대상 소스가 지금 07 과 같음 | 빌더 스크립트가 07 파일과 바이트 비교 | ⚠️ 빌더에서 확인 |
| F1 COMMON 은 11 개(`_etherbroadcastaddr`·`_ifnet`·`_rawintrq` 포함) | 778.13 python 출력과 같음 | ✅ 허용 목록 고침 |
| 계획 583 `subr_prf` 의 절·재배치 같음 | 778.13 python 출력과 같음 | ✅ |
| `machdep` 충돌 근거(`machdep.c:157`, `ipc_port.h:148`) | `ipc_port.h:148` 은 778.12 에서 열람; `machdep.c:157` 은 빌더 실행 전 열람 | ⚠️ 실행 전 확인 |
| F2 형 호환 | `pmap.c:274–278`, `zalloc.h:83` 열람 | ✅ |
| F3 은 `NeXT_CUBE`·`NeXT_X15` 만 씀 | `kern_exit.c:99–103` 열람(두 정의만) | ✅ |
| F4 `extern u_short dma_chip`(`bsd/m68k/cpu.h:48`) | SDK `cpu.h` 열람(`extern u_short dma_chip;`) | ✅ |
| F5 매크로 충돌 없음 | 확인 안 함 | ⏭️ 컴파일 결과로 판정 |
| F6 형들이 보임(`evio.h`·`video.h`·`port.h`·`kern_types.h`) | 확인 안 함 | ⏭️ 컴파일 결과로 판정 |
| 마우스 배열 20×2 = 40 | python 40; `evio.h:52`, `ev_types.h:19` 열람 | ✅ |
| F7 형은 `nextdbg.c:207` 과 같음 | 열람 | ✅ |
| `mem_region` 28×8 = 224, `MAX_REGIONS` 8 | python 224; `pmap.h:167` 7 필드, `vm_param.h:82` 열람 | ✅ |
| CPU 이름은 `u_char`, `interrupt_stack[NCPUS]`, `NCPUS` 1 | `cpus.h` 열람 `#define NCPUS 1`; SDK `cpu.h` `u_char` | ✅ |
| 첫 포함 객체가 576 배치 모두에서 같음 | 778.13 의 한 배치 결과만 내가 확인 | ⚠️ 모델 단계에서 배치마다 확인 |
| `eventsOpen` 첫 언급 `adb` 208 | 778.13 python | ✅ |
| 합집합 84 | python `73+37-26 = 84` | ✅ |
| 이름들은 어디서도 SECT 정의 아님 | 778.8 python: 원본 `__common` 이름 SECT 정의 0 | ✅ |
| 부분 재컴파일의 한계 | 맞음 | ✅ (4)에 반영 |
| 대상 7 객체 | 셈 맞음 | ✅ 정정 |
| 합성·DP 보정 없는 순서로 판정 | `cmd_common` 의 합성 `_bootp` 열람 | ✅ 반영 |
| 크기·정의·미해결 전체 검사 | 778.12 (3) 와 같음 | ✅ |
| 재배치 비교 필드 확장(산포·지역 포함) | `ext_relocs` 가 산포를 건너뜀(열람) | ✅ 반영 |
| 기준 재현 컴파일 | 맞음 | ⚖️ M5 기준 1 run 만(M4 는 받아들인 객체와 비교) |
| 예상 실패의 별도 범주 | `kr_run.py:252,329` | ✅ 반영 |

### 778.15 P3b 결과 (실기 run 16 개, 2026-11-08; 07·상태표·M4/M5 객체 불변; 기록 `09_validation/reconstruction/m7-m68k-p778-p3b-20261108.json`, 빌더 `scratch/p778/p3b_build.py`, 판독 `scratch/p778/p3b_analyze.py`)
- 내 오류(먼저): 처음 만든 F6 시험 헤더는 `NX_NUMSPECIALKEYS` 의 헤더(`dev/ev_keymap.h`)를 import 하지 않아 `ev` 컴파일이 실패했습니다(run `m7p778-p3b-eva`). F8 (가)는 `netinet/bootp.h` 가 쓰는 `struct ip`·`struct udphdr` 의 헤더를 import 하지 않아 실패했습니다(`m7p778-p3b-ina`). 두 꼴을 고쳐 새 ID `m7p778-p3b-eva2`·`m7p778-p3b-ina2` 로 다시 돌렸습니다. 빌더 파일은 이때 바뀌었으며, 각 run 의 빌더 해시를 기록에 둡니다.
- 운영: 16 run 모두 준비된 `src/` 가 오버레이와 파일 집합·바이트가 같았습니다. 손 검사(DONE·FAILED 없음·LOCK 해제·입력 해시 두 번·도구 해시·`nonregular`/`hardlinks` 빔·manifest 해시)를 모두 통과했습니다. 기준 재현 run(`m7p778-p3b-base`, 수집)의 manifest 와 파일 집합 차이는 `collect` 가 쓰는 `run.json` 하나뿐입니다. 16 대상 소스는 모두 지금 07 의 판과 바이트가 같습니다(빌더 단정).
- 기준 재현: M5 `subr_prf`·`cmu_syscalls`·`kern_exit`·`vol` 을 지금 실기 도구로 다시 만들면 받아들인 객체와 파일째 같습니다(도구 결정성).
- 시험 꼴 컴파일(성공한 모든 것): 받아들인 객체와 절 목록·크기·정렬·바이트, 정의 기호, 의미상 재배치(산포·지역 포함)가 모두 같습니다. 늘어난 것은 COMMON(및 미정의가 COMMON 으로 바뀐 것)뿐이고, 모두 계획한 이름입니다. stderr 는 `km`(아래) 말고는 각 객체를 만든 원래 명령의 stderr 와 같습니다.
  - `subr_prf`(F1′+F5, F1+F5): `_bmap_chip` 과 네트워크 8 이름, 그리고 `_etherbroadcastaddr`·`_ifnet`·`_rawintrq`
  - `cmu_syscalls`(F2): `_pv_head_table`·`_pv_list_zone`
  - `kern_exit`(F3): `_scr2`·`_brightness`(+ `pmap.h` 를 포함하므로 `_pv_*`)
  - `vol`(F4): `_dma_chip`·`_slot_id`(+ `_pv_*`)
  - `ev`(F6, eva2): 50 이름
  - `if_en`(F7): `_kdb_net`
  - `m68k_init`(F8, ina2): 17 이름
  - `nextdbg`(F9): `_dbg_connect_pkt`
- (나) 진단(`mon/global.h` 에 `tftp.h` 되살림): `subr_prf`·`adb`·`clock`·`km`·`ev_kbd`·`video`·`m68k_init` 은 컴파일되고 바이트가 같습니다. `km` 은 `kfree` 원형 경고 두 줄이 새로 나지만 바이트는 같습니다. `ev`·`ev_ioctl`·`machdep`·`zscom` 4 개는 `netinet/ip.h:98` "parse error before `.`"(`ip_timestamp` 충돌)로 실패합니다. 따라서 (나)는 이 4 객체의 충돌을 푸는 꼴이 따로 있어야 합니다.
- 모델(실제로 다시 컴파일한 객체만, 합성 선언·DP 보정 없음; 문자열 제약을 지키는 576 배치):
  - (가)(F1′+F2–F9; 바꾼 객체 8 개)와 (나)(F1+F2–F9; `ev` 는 F1 없이 컴파일한 eva2 의 것)의 결과가 같습니다.
  - 96 배치에서 ⓓ 순서가 원본 613 순서와 정확히 같습니다. 그 배치에서 주소 613 개가 모두 같고 절 끝 0x40c9908 이 같으며, 원본 `__common` 이름을 가리키는 긴 꼴 재배치 7592 개가 모두 원본 바이트와 같습니다.
  - 원본에 없는 새 할당은 0 이고, 크기를 가정한 이름도 0 입니다(살아남는 COMMON 613 = 원본).
  - 나머지 480 배치는 `param`·`scsiconf` 위치가 원본과 맞지 않습니다(첫 어긋남 `_ipc_tree_entry_zone`/`_callout` 384, `_sd_sd`/`_scsi_ndevices` 96).
  - 96 배치의 단위 위치는 778.9 와 같습니다(`param` 118, `scsiconf` 220 등).
  - 비교: 지금 객체 그대로는 정의 없는 73 이름 때문에 링크 자체가 안 됩니다.
- 뜻: 정의 없는 73 이름과 추가 언급 37 은, 아래 일곱 가지 변경만으로 모두 채워집니다. 이 변경들은 코드·자료 바이트를 바꾸지 않습니다.
  - `subr_prf` 의 `mon/tftp.h`·`bmap.h` 포함
  - `pmap.h` 의 임시 정의
  - `kern_exit` 의 `scr.h` 포함
  - `vol` 의 두 선언
  - `ev` 의 변수 헤더
  - `if_en` 의 `kdb_net`
  - `m68k_init` 과 `nextdbg` 의 선언

  이 꼴로 `__common` 이 원본과 바이트 수준으로 맞습니다. 단 F4·F5·F7·F9 의 위치, F6 의 헤더 이름, F8 에 이름을 모은 것은 출처 없는 시험 선택이며 원본 소스의 증명이 아닙니다. 07 에 넣을 꼴은 사용자 결정입니다.
- 한계: 헤더를 바꾸면 그 헤더를 포함하는 다른 객체에도 COMMON 이 생깁니다(예: F2 의 `pmap.h` 163 객체, (나) 의 `mon/global.h` 11 객체). 순서에는 영향이 없지만, 07 변경 뒤 영향받는 모든 객체를 다시 만들어 회귀 검사해야 합니다. 전체 링크(P2)는 아직 하지 않았습니다.

### 778.16 P2 설계 — scratch (가) 객체 집합으로 296 객체 전체 링크 (코딩 전, 2026-11-09; 07·상태표·M4/M5 객체 불변)
사용자 지시 "다음 작업을 진행합니다"(778.15 보고 뒤)에 따라 P2 를 진행합니다. 778.15 의 결정 요청 1·2(D133, 07 에 넣을 꼴)는 아직 받지 않았으므로 07 은 바꾸지 않고, 778.15 의 (가) 시험 객체 8 개를 scratch 에서 그대로 씁니다. 이 링크는 진단이며 수락 판정이 아닙니다.

**(1) 입력 사실**(python `scratch/p778/p2_explore.py`·`verify_codex_p2.py`, 결과 `scratch/p778/p2_explore.json`)
- 객체 296 = 받아들인 객체 288 + 778.15 (가) 의 다시 컴파일한 8 개(`m7p778-p3b-m5a` 의 `subr_prf`·`cmu_syscalls`·`kern_exit`·`vol`, `eva2` 의 `ev`, `ena` 의 `if_en`, `ina2` 의 `m68k_init`, `dba` 의 `nextdbg`; 해시는 기록과 같음). 입력 합 9276848 B.
- 외부 정의 이름 3195(중복 0) + `__common` 613 + `__mh_execute_header` 1 = 3809 로 원본 기호 수와 같고, 이름 집합도 원본과 같습니다(원본에만 0, 우리에만 0). 입력에는 지역 기호 2257 개(STABS 제외)와 STABS 229082 개가 있습니다. 자료 단위에도 STABS 가 있고, 그 일부는 크기 0 인 `__text`(절 1, 값 0)에 붙어 있습니다(예: `ioconf` 142·`conf` 256·`param` 316 개).
- 입력 재배치 28960 개는 모두 4 B 길이이고, 외부 9995(PC 상대 7830 따로)·지역 7367(PC 상대 3214 따로)·산포 554 입니다.
- CPU subtype: 295 객체가 1, `M4:fpsp` 하나가 2 입니다(778.6).
- 링크 순서에서 각 절이 처음 나오는 객체: `__text`·`__data` 0 번, `__cstring` 2 번, `__bss` 12 번, `__const` 27 번. 출력 절이 처음 만난 순서로 생긴다면 `__TEXT` 는 `__text`·`__cstring`·`__const` 로 원본 순서와 같습니다(가정; 관찰로 확인).
- 배치 모의(입력 절마다 그 절의 정렬로 올려 이어 붙임; 시작은 원본 절 시작):
  - `__text` 283 객체 모두 원본 주소와 같고 끝 0x40a5d7e 가 같습니다.
  - `__const` 25 객체, 끝 0x40ad962 가 같고, 주소가 없던 `swapfs`·`ufs_alloc` 는 원본 틈 0x40acfdb·0x40acfe2 에 놓입니다(778.2).
  - `__data` 145 객체: 1 B 채움 5 곳은 홀수 크기 `__data`(`if_ether`·`tcp_output`·`nfs_subr`·`ufs_dir`·`ev_kbd`) 뒤, 정렬 2^1 객체 앞이며 원본 1 B 틈(바이트 0)과 같은 자리입니다. 그러나 `ioconf` 와 `vers` 사이 36 B 영 구간 [0x40b30ec, 0x40b3110)(소유 불명, 777)은 생기지 않습니다. 그래서 `vers` 가 0x40b30ec(원본보다 −36)에 오고 `__data` 가 0x40b3158(원본 0x40b317c)에서 끝납니다.
  - 그 결과 `__bss` 가 36 B 앞에서 시작하고(끝 0x40b5624 는 4 의 배수), `__bss` 50 객체와 `__common` 613 이름이 모두 −36 B 밀린다고 예측합니다. 36 B 를 채우면 `__bss` 50 객체와 `__common` 613 주소·절 끝 0x40c9908 이 모두 원본과 같습니다.
- 자료 단위 위치: 13 단위 모두, 후보 위치 사이의 텍스트 객체는 그 단위가 가진 절(문자열 제외)을 갖지 않습니다(python, 겹침 0). 따라서 위치는 초기화 절 내용을 바꾸지 않는다고 예측합니다. 단 STABS 값(크기 0 `__text` 에 붙은 것)은 위치에 따라 달라집니다.
- 내 오류(먼저): 후보 위치는 텍스트 객체에 대해서만 계산했습니다(`m7_m68k_link.py:160`). 단위끼리 후보 범위가 겹치는 것은 `ioconf`·`vers` 한 쌍뿐이고(python, 모든 쌍), 원본에서 `vers` 의 `__data` 가 더 뒤이므로 `ioconf` ≤ `vers` 여야 합니다(같은 순번이면 `build_order` 가 이름순 `ioconf`, `vers` 로 둠, `:181–182`). 778.15 의 96 배치는 `vers` 를 첫 후보 268 에 고정했으므로 그 가운데 `__data` 순서가 맞는 것은 `ioconf` 268 인 6 개뿐입니다(`conf` 3 × `uipc_proto` 2). `__common` 결과에는 영향이 없습니다(`vers` 는 언급 0). P2 의 링크 순서는 이 조건을 지킵니다.
- 원본 기호표: 3809 개 모두 외부, 이름순, `n_desc` 모두 0, 문자열은 기호 순서대로 strx 4 부터 빈틈없이 채워 52923 B 이고 끝에 0 한 바이트를 더해 52924 B 입니다. P1·P1b 의 ld 출력 외부 기호도 이름순이었습니다. P1 의 `strip -x` 는 기호 6 개를 그대로 두고 문자열표를 92 B 에서 40 B 로 다시 만들었습니다.
- 원본 `LC_UNIXTHREAD`: flavor 1, count 18, pc 0x4000310 말고는 모두 0. 세그먼트: `__PAGEZERO` 0/4·파일 0/0·0/0·절 0·flags 4, `__TEXT` 0x4000000·0xad964·파일 0·0xad964·7/5·절 3·flags 0, `__DATA` 0x40ad964·0x1bfa4·파일 0xad964·0x5818·7/3·절 3·flags 0. 헤더 flags 1, ncmds 5, sizeofcmds 688. 모든 절의 reloff·nreloc·reserved 는 0, 절 flags 는 `__cstring` 2·`__bss`·`__common` 1·나머지 0. 헤더 뒤 [716, 784) 68 B 와 `__const` 뒤 파일 오프셋 0xad962 의 2 B 는 0 입니다.

**(2) run `m7p778-p2-1`**(미수집; 처음 쓰는 꼴이 섞임: 296 객체 링크, `-force_cpusubtype_ALL` 과 `-segalign 4 -noseglinkedit` 의 조합, `-noseglinkedit` 출력의 `strip`; `EXPECT _log/status`; 778.10 ⑤ 의 손 검사)
- 입력: `src/o/<종류>_<이름>.o`(296 사본; 이름은 `NAME_RE` 통과·대소문자 겹침 0), `src/pad36.s`(진단용 채움: `.data` 와 `.long 0` 9 줄; 기호 없음; 07 아님. 선례 P1 `B2.s` 의 `.data`·`.long` 은 `__data` 정렬 2^0 이었음). 준비된 `src/` 를 원래 파일과 바이트로 비교합니다(계획 :155).
- 명령(링크 옵션은 P1b B8 의 꼴 `-arch m68k -static -seg1addr 0x4000000 -e _start -segalign 4 -noseglinkedit` 에 필요한 것만 더함):
  - 00 `as -arch m68k -o stage/pad36.o src/pad36.s`
  - 01 K1: 순서 P(아래)의 296 객체 → `stage/k1.sys`
  - 02 K1F: K1 + `-force_cpusubtype_ALL`(P1 F1 에서 본 옵션) → `stage/k1f.sys`
  - 03 K2F: K1F + `stage/pad36.o` 를 `D_ioconf.o` 바로 뒤에 → `stage/k2f.sys`
  - 04 K3F: K2F 와 같되 순서 Q → `stage/k3f.sys`
  - 05·06·07 `strip -x -o stage/<k1f|k2f|k3f> stage/<…>.sys`(선례 `l2_link.py:130`)
- 순서 P: 텍스트 순서 + 단위 위치 `conf` 202·`uipc_proto` 34·`ioconf` 268·`vers` 268·`counters` 132(그 밖은 하나뿐인 위치). 순서 Q: `conf` 204·`uipc_proto` 35·`ioconf` 283·`vers` 283·`counters` 137. P 는 778.15 의 정확 배치 가운데 하나이고, Q 는 정확 배치를 언급 없는 단위(`vers`·`counters`)의 다른 위치로 넓힌 것입니다. 둘 다 python 으로 다시 확인했습니다: 모든 위치가 후보 안, `model_seq` 가 원본 613 순서와 같음, 자료·상수·bss 주소 역전 0, 합친 `__cstring` 이 원본과 같음, `ioconf` 바로 뒤 `vers`(링크 순번 279·280 / 294·295). 명령 줄 길이는 약 6200 자로 x86 선례(`s6p559-ln1` 8519 자)보다 짧습니다.
- 판독 순서: 각 명령은 앞 명령의 산출물에 기댑니다. 앞 명령이 실패했거나 산출물이 기대와 다르면(예: `pad36.o` 의 `__data` 가 36 B·정렬 2^0·기호 0·재배치 0 이 아님) 뒤 명령은 "전제 실패" 로 두고 해석하지 않습니다.

**(3) 미리 적는 예측과 판정 층**(python; 778.3 P4 의 층). strip 전 `.sys` 와 strip 한 파일은 따로 판정합니다(strip 전에는 지역 기호·STABS 가 있어 기호표가 원본과 같을 수 없음).
- (A) 모든 명령 종료 0, stdout·stderr 빔, 미정의 0.
- K1 와 K1F: 헤더 cpusubtype 필드(4 B)만 다를 수 있다(P1 L16 대 F1 은 오프셋 11 의 1 B 만 달랐음). K2F 와 K3F: 초기화 절 바이트와 외부 기호(이름·형·절·`n_desc`·값)가 같다. `.sys` 파일 전체는 STABS 값·문자열표 때문에 다를 수 있으므로 판정하지 않고 차이만 적습니다. strip 한 `k2f` 와 `k3f` 는 파일째 같다고 예측합니다.
- (B) 헤더·적재 명령(K2F 와 strip 한 `k2f`): 헤더, 세그먼트(주소·크기·파일 범위·보호·절 수·flags), 절(주소·크기·오프셋·정렬·reloff·nreloc·flags·reserved)이 원본과 같다. 세그먼트 flags 는 탐침에서 4, 원본 0 이며 전체 링크의 값은 관찰 대상입니다. strip 한 파일의 `LC_SYMTAB` 은 원본 값(symoff 733564·3809·stroff 779272·52924)과 같다.
- (C) 기호: strip 한 `k2f` 의 3809 개가 물리 순서·이름·형·절·`n_desc`·값·strx 까지 원본과 같고, 문자열표 바이트(끝 채움 포함)도 같다. strip 전 `.sys` 는 외부 기호가 원본 3809 와 같은지 보고 지역·STABS 수를 따로 적습니다. 배치 확인: 입력 객체의 모든 외부 정의 기호에 대해 "출력 값 = 예측 기여 시작 + (입력 값 − 입력 절 주소)" 를 검사합니다(예측 배치 표는 빌더가 씀).
- (D) 절 바이트(K2F): `__text` 는 원본과 6 B 만 다르다 — `nfs_client` 0x40262d8·0x40262da·0x40262df, `swapfs` 0x4032b2a·0x4032b37·0x4032b3b(각 L1 기록의 `first_differences`). `__cstring`·`__const`·`__data` 는 같다. 다른 바이트는 모두 예측 배치 표로 입력 객체·절·오프셋(문자열은 합친 뒤 대응)에 되돌리고, 정렬 채움 바이트는 따로 셉니다. 재배치 자리에 걸리면 그 4 B 의 기대 값(예측 주소 + 덧붙임 값)과 비교합니다.
- K1F: 예측 배치 표로 같은 입력 기여끼리 비교합니다(원시 오프셋 비교는 `vers` 이동과 `__data` 끝 차이도 보임). 위 6 B 말고는 재배치 자리만 다르고, 그 값 차이는 모두 −36 이다. 대상은 외부·지역·산포 재배치 모두이며, PC 상대는 양 끝이 함께 밀리지 않는 한 차이가 없어야 합니다. −36 자리의 수와 종류는 빌더가 실행 전에 계산해 기록하고, 결과와 대조합니다. 다른 꼴의 차이가 나오면 먼저 원인을 찾습니다.
- (E) `LC_UNIXTHREAD` 전체가 원본과 같다.
- (F) strip 한 `k2f` 파일 전체: 위 6 B 와 세그먼트 flags(나온다면) 말고는 같고 크기 832196 B 이다. 헤더 뒤 68 B, `__const` 뒤 2 B, 초기화 절 끝 = `symoff`, `symoff` + 12×3809 = `stroff`, 문자열 끝 = 파일 끝을 따로 봅니다.

**(4) 도구**
- 빌더 `scratch/p778/p2_build.py`(scratch 객체를 쓰므로 scratch): `src/` 디렉터리(사본 해시 확인), 명령 파일 `08_build/artifacts/m7p778/m7p778-p2-1.cmd`(`kr_run.parse_cmdfile` 로 통과 확인), 링크 기록(순서 P·Q, 객체 경로·해시, 링크별 예측 배치 표, K1F 의 −36 예측 자리 목록)을 씁니다. `m7_m68k_link.py` 의 `World`·`build_order`·`model_seq` 를 읽기 전용으로 씁니다.
- 비교기 `10_tools/reconstruction/m7_m68k_compare.py`(새 파일, python 3 표준 라이브러리, 빅엔디안; `l2_compare.py` 는 리틀엔디언 고정이라 쓰지 않음, 778.3): 입력은 출력 파일·원본·링크 기록, 결과는 층 (B)–(F) 의 JSON 입니다.
- 판독 `scratch/p778/p2_analyze.py`: run 손 검사, 층 (A), 전제 실패 판정, 비교기 실행, 기록 `09_validation/reconstruction/m7-m68k-p778-p2-20261109.json`.

**(5) 하지 않는 것·한계**: 07·상태표·M4/M5 객체를 바꾸지 않습니다. `pad36` 은 36 B 영 구간이 남은 유일한 배치 차이인지 보려는 진단용 채움이며 복원으로 채택하지 않습니다. 그 구간의 주인(`ioconf` 끝, `vers` 앞, 다른 단위)은 이 링크로 정하지 않습니다. (나) 객체는 링크하지 않습니다(4 객체가 컴파일되지 않음). `-segalign 4`·`-noseglinkedit`·`-force_cpusubtype_ALL` 은 바이트와 맞는 옵션 후보이며 원본 빌드 명령의 증거가 아닙니다. 바이트 일치는 원본 소스와 같다는 증명이 아닙니다. QEMU 부팅(M8)은 범위 밖입니다. 커밋하지 않습니다.

#### 778.16.1 codex 검토 판정표(작업 `kp84e649d`)
내가 틀렸던 것(먼저): ① `ioconf`·`vers` 순서 조건을 빠뜨렸고, 778.15 의 96 배치 가운데 `__data` 순서가 맞는 것은 6 개뿐입니다. ② K2F·K3F 의 `.sys` 가 파일째 같다고 예측했으나, 자료 단위의 STABS 가 크기 0 `__text` 에 붙어 있어 위치에 따라 값이 바뀝니다. ③ Q 를 "정확 배치에 든다" 고 적었으나 778.15 는 `vers`·`counters` 를 첫 후보로 고정했으므로 Q 는 그것을 넓힌 것입니다. ④ strip 전·후 파일의 판정 층을 나누지 않았고, 문자열표·`n_desc`·reloff·nreloc·채움 바이트 비교를 적지 않았습니다. ⑤ 뒤 명령의 전제 실패 판정을 적지 않았습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| (1) 의 입력 수치 전부 | `p2_explore.py` 출력(296·3195·3809·2257·229082·subtype·첫 절·모의 결과) | ✅ |
| 원본 문자열표 52923 B + 끝 0 한 바이트, `n_desc` 0 | `verify_codex_p2.py` C2: packed 52923, 끝 0, `n_desc` 0 이 아닌 것 0 | ✅ 반영 |
| `ioconf`·`vers` 만 겹침, `candidates` 는 텍스트에만, `build_order` 이름순 | python 모든 쌍: 겹침은 이 쌍뿐(16 위치); `m7_m68k_link.py:160–175`·`:181–182` 열람 | ✅ 내 오류 정정 |
| 96 가운데 `__data` 순서가 맞는 것 6 | `vers` 268 고정이므로 `ioconf` 268 만 가능: python 3×2 = 6 | ✅ 반영 |
| Q 는 "정확 배치" 가 아니라 넓힌 것(`p3b_analyze.py:149`) | 열람: 언급 없는 단위는 `W.cand[k][0]`; Q 는 python 으로 `model_seq` 일치·역전 0 확인 | ✅ 문구 정정 |
| Q 의 문자열 합침이 원본과 같음 | python: P·Q 순서로 처음 나온 순서 중복 제거 → 원본 `__cstring` 과 같음(`True`, `True`; 바꾼 8 객체의 문자열 바이트는 778.15 에서 같음) | ✅ |
| 자료 단위 STABS 가 크기 0 `__text` 에 붙어 위치에 따라 값이 다름 | C5: `ioconf` 142·`vers` 25·`counters` 27·`conf` 256·`uipc_proto` 96 개, 절 1 값 0, `__text` 크기 0 | ✅ 예측 정정 |
| 그 STABS 의 P·Q 출력 값(0x409a8ba 등) | 재현 안 함 | ⏭️ 문서에 넣지 않음 |
| P1 L1/L2 의 문자열표가 입력 순서에 따라 다름 | 재현 안 함(위 STABS 근거로 이미 예측 정정) | ⏭️ |
| `parse_cmdfile` 통과·줄 길이 6178–6215 | 빌더가 `parse_cmdfile` 로 확인할 항목; 내 추정 6201(K1F) | ⚠️ 빌더에서 확인 |
| x86 선례 8518 자(줄바꿈 제외) | 내 출력 8519(줄바꿈 포함) | ✅ |
| `kr_run.py:252` 실패 뒤 계속, `:329` 수집 거부 | 778.10 에서 열람한 줄과 같음 | ✅ 전제 실패 판정 추가 |
| `.data`·`.long` 은 정렬 2^0(`B2.o`) | C6: `('__data', 4, 0)` | ✅ 반영 |
| 재배치 28960 개 모두 4 B, 16 비트 없음 | C7: 총 28960, 길이 필드 모두 2 | ✅ 반영 |
| −36 자리 8766(외부 7595·지역 903·산포 268), 바뀌지 않음 20194, PC 상대 차이 0 | 재현 안 함 | ⚠️ 수치는 옮기지 않고 빌더가 계산 |
| 외부 7592 만 보면 지역·산포 자리를 놓침(`tty_pty` 예) | `ext_relocs` 가 산포를 건너뜀(`m7_m68k_link.py:96–97` 열람); 지역 7367·산포 554 개 있음(C7) | ✅ 모든 종류로 판정 |
| `__bss` 끝 0x40b5624 가 4 의 배수, `__common` −36 | python `0x40b5624 % 4 == 0`(p2_explore 의 모의 끝 값) | ✅ |
| K1 대 K1F: P1 L16/F1 은 오프셋 11 의 1 B 만 다름 | C8: `[(11, 2, 1)]`, 두 파일 76000 B | ✅ 문구 정정(필드 4 B 안에서 다를 수 있음) |
| strip 전후 층 분리, 문자열표 다시 만듦(P1 92 → 40 B) | C9: L1 strsize 92, L1s 40 | ✅ 반영 |
| 원본 reloff·nreloc·reserved 0, 68 B·2 B 영 | C9 출력: 모든 절 0, `[716,784)` 영, `0xad962` 의 2 B 영 | ✅ 반영 |
| 입력 → 출력 대응(문자열 여럿 → 하나), 채움 따로, 재배치 값으로 판정 | 설계 보강 | ✅ 반영 |

### 778.17 P2 결과 (실기 run `m7p778-p2-1` 미수집, 2026-11-09; 07·상태표·M4/M5 객체 불변; 기록 `09_validation/reconstruction/m7-m68k-p778-p2-20261109.json`, 빌더 `scratch/p778/p2_build.py`, 비교기 `10_tools/reconstruction/m7_m68k_compare.py`, 판독 `scratch/p778/p2_analyze.py`)
- 운영: 8 명령 모두 종료 0 이고 stdout·stderr 는 모두 비었습니다. 손 검사(DONE·FAILED 없음·LOCK 해제·입력 해시 두 번·도구 해시·`nonregular`/`hardlinks` 빔·manifest 집합과 해시·상태 00–07)를 모두 통과했습니다. 준비된 `src/` 297 파일은 빌더 출력과 바이트가 같고 빈 파일이 없습니다. 전제: `pad36.o` 는 `__data` 36 B·정렬 2^0·재배치 0·기호 0·바이트 모두 0 으로 기대와 같습니다.
- 비교기 자기 시험: 원본 파일을 K2F 로 비교하면 모든 층이 같고, 채움 바이트 41 B(1 B 다섯 + 36 B)만 따로 셉니다(`scratch/p778/p2/selftest_orig.json`).
- **strip 한 K2F(`k2f`, `pad36` 포함)는 원본과 6 B 만 다릅니다.** 크기 832196 B 가 같고, 차이는 예측한 `nfs_client` 0x40262d8·0x40262da·0x40262df, `swapfs` 0x4032b2a·0x4032b37·0x4032b3b 의 `__text` 6 B(파일 오프셋 156376·156378·156383·207658·207671·207675)뿐입니다. 층별로는 다음과 같습니다.
  - (B) 헤더·적재 명령: 차이 0. 세그먼트 flags 는 `__PAGEZERO` 4·`__TEXT` 0·`__DATA` 0 으로 원본과 같습니다(탐침의 4 는 전체 링크에서 나타나지 않음). subtype 1, `LC_SYMTAB` symoff 733564·3809·stroff 779272·52924.
  - (C) 기호 3809 개의 물리 순서·이름·형·절·`n_desc`·값·strx 가 원본과 같고, 문자열표 바이트도 같습니다. 예측 기호 값과 다른 것 0.
  - (D) `__cstring`·`__const`·`__data` 는 원본과 같고 `__text` 는 위 6 B 만 다릅니다. 입력 기여 453 개 가운데 451 개가 같고, 나머지 두 개(`nfs_client`·`swapfs`)의 차이가 위 6 B 입니다. 채움 41 B 는 원본과 같은 0 입니다.
  - (E) `LC_UNIXTHREAD` 같음. (F) 파일 전체에서 다른 바이트 6.
- K3F(순서 Q)는 strip 하면 K2F 와 파일째 같습니다. strip 전 `.sys` 는 335275 B 가 다르며, 모두 기호표·문자열표 구간(오프셋 1068967–8929840, symoff 733564 뒤)입니다. 자료 단위 STABS 값 때문이라는 예측(778.16.1)과 맞습니다.
- K1(subtype 강제 없음)과 K1F 는 파일 오프셋 11 의 1 B(subtype 2 대 1)만 다릅니다.
- K1F(채움 없음): 예측대로 `__data` 가 22516 B(원본 22552), `__bss`·`__common` 시작이 36 B 앞이고, strip 한 파일이 832160 B(원본보다 36 B 작음)입니다. 입력 기여끼리 비교하면 빌더가 미리 센 재배치 자리 8766 개(외부 `__common` 7592·외부 정의 3·지역 903·산포 268)가 모두 −36 차이이고, 그 밖의 차이는 위 6 B 뿐입니다. 예측 기호 값과 다른 것 0(값이 바뀐 외부 기호 617).
- strip 전 `.sys` 에는 외부 3809·지역 2257·STABS 229082 개가 있고, `strip -x` 는 지역과 STABS 를 모두 지웠습니다.
- 뜻:
  - 링크 옵션 `-arch m68k -static -seg1addr 0x4000000 -e _start -segalign 4 -noseglinkedit -force_cpusubtype_ALL` 과 `strip -x` 로, 이 296 객체 + 36 B 채움은 원본 파일의 헤더·절 배치·기호표·문자열표·`__common` 을 바이트째 재현합니다. 남은 차이는 이미 알던 텍스트 6 B 와 36 B 영 구간의 주인입니다. 이 옵션이 원래 빌드 명령이었다는 증거는 아닙니다.
  - 받아들인 객체만으로는 링크가 되지 않으며(정의 없는 73 이름), 이 결과는 778.15 (가) 의 scratch 객체에 기댑니다. 07 에 넣을 꼴은 여전히 사용자 결정입니다.
  - 36 B 영 구간은 링크 전체에서 `__bss`·`__common` 의 위치를 정합니다. 이 구간을 채우는 것이 원래 객체의 무엇인지(`ioconf` 끝, `vers` 앞, 다른 단위)는 정해지지 않았고, `pad36` 은 복원이 아닙니다.
  - `__data` 의 1 B 틈 다섯 곳은 ld 의 정렬 채움으로 설명됩니다(입력 기여는 모두 원본 주소, 채움 바이트 0).
- 한계: 바이트 일치는 원본 소스의 증명이 아닙니다. 미수집 run 이며, 07 이 정해진 뒤 같은 꼴을 수집 run 으로 다시 만듭니다. QEMU 부팅(M8)은 하지 않았습니다.

### 778.18 P5 — 36 B 영 구간 [0x40b30ec, 0x40b3110) 의 주인 조사와 시험 설계 (코딩 전, 2026-11-09; 07·상태표·M4/M5 객체 불변)
사용자 지시 "진행하세요"(778.17 보고 뒤)에 따라 36 B 영 구간의 주인을 조사합니다. 조사는 읽기 전용이고, 시험은 scratch 오버레이에서만 합니다.

**(1) 조사 결과**(읽기 전용 python·열람)
- 원본 절의 모든 2 B 간격 4 B 값 가운데 [0x40b30e4, 0x40b3118] 에 드는 것은 `__text` 의 7 개뿐입니다(`__cstring`·`__const`·`__data` 0). 7 개 모두 `fpsp` 범위 [0x409ab9c, 0x40a5510) 안에 있고, 앞 2 B 가 `52b9`(`addql #1,<절대 주소>.l`)입니다: 0x40a0a7c→0x40b30f8, 0x40a0b06→0x40b30f4, 0x40a0b66→0x40b3100, 0x40a0ba4→0x40b30fc, 0x40a0bf2→0x40b3108, 0x40a0c24→0x40b3104, 0x40a0c8a→0x40b30f0.
- 07 `src/machdep/m68k/fpsp.s`(D175)는 이 7 곳을 원본 바이트에서 쓴 숫자 주소로 둡니다(`fpsp.s:9308,9352,9386,9409,9437,9457,9491`, 예 `addql #0x1,0x40b30f8:l`). 그래서 받아들인 `fpsp` 객체(`m4p770-a2`)에는 이 자리의 재배치가 없고 `__data` 도 없습니다(절은 `__text` 43380 B 하나, 재배치 1508). 이 소스는 이 링크 주소에서만 원본 바이트를 냅니다.
- 7 곳이 든 처리기와 구간 안 오프셋: `real_bsun` +4·`real_inex` +8·`real_dz` +0xc·`real_unfl` +0x10·`real_ovfl` +0x14·`real_operr` +0x18·`real_snan` +0x1c. +0 과 +0x20 을 가리키는 4 B 값은 원본에 없습니다. 36 B = 4 B × 9 입니다.
- 원본 기호표에는 이 구간의 이름이 없습니다(`_pseudo_inits` 다음 이름이 `_version_major`). 그러나 이것만으로 주인을 정할 수 없습니다. 구간 밖의 외부 이름 + 덧붙임 값도 이 자리를 가리킬 수 있습니다(선례: `locore` 의 외부 `_cnt` 재배치는 덧붙임 4·8·0xc; 계산: `_version_major` − 0x18 = `_pseudo_inits` + 0x34 = 0x40b30f8). 지역 기호·지역 절대 기호도 가능하고, NeXTMach 는 FPSP 를 `ld -r ${TRANS} -o fpsp.o` 로 묶습니다(`fpsp/Makefile:24–27`). 따라서 "9 칸이 `fpsp` 객체의 `__data`" 는 바이트와 맞는지 시험할 **후보** 이며, `ioconf`·`vers` 나 다른 기여가 주인일 가능성을 버리지 않습니다.
- 링크 순서와 맞습니다: `fpsp` 의 텍스트 순번은 272 이고, `ioconf`·`vers` 의 후보 위치(268–283) 안입니다. `ioconf` ≤ 272 < `vers` 이면 ld 는 `ioconf`(끝 0x40b30ec) → `fpsp` 의 `__data` 36 B → `vers`(0x40b3110) 순서로 놓습니다. 272 뒤 텍스트 객체(Mach 사용자 스텁 10 개 273–282)는 `__data` 가 없습니다. NeXTMach `conf/Makefile.template:142,289` 의 링크 줄은 `${LDOBJS}`(`locore.o ${OBJS} ioconf.o`) 뒤에 `vers.o` 를 두고 그 뒤에 `$*.swap ${LIBS}` 가 옵니다. x86 선례(`l2_link.py`)도 스텁 뒤 `vers.o` 입니다.
- 참고 트리에 다른 FPSP 판은 없습니다(파일 이름 검색: NeXTMach `fpsp/` 뿐). NeXTMach `skeleton.sa` 의 `real_*` 처리기에는 이런 증가 명령이 없습니다(`skeleton.sa:49–55` 의 `real_dz` 는 `rte` 로 끝남; 언제 더해졌는지는 이것으로 정하지 않음).

**(2) 시험**(실기 run `m7p778-p5-1`, 미수집; 07 불변)
- 오버레이: `fpsp` 를 만든 run `m4p770-a2` 의 `src/` 를 scratch 에 복사하고(대상 `fpsp.s` 가 07 과 바이트 같음을 확인) `fpsp.s` 만 바꿉니다.
  - V1: 7 곳의 숫자 주소를 지역 이름으로 바꿈(`addql #0x1,<이름>:l`; 이 꼴은 `std_trap:l`·`_cpu_type:l` 로 이미 쓰임). 파일 끝에 `.data` 와 지역 이름 9 개(`.globl` 없음; 각 `.long 0`)를 둡니다(이 꼴은 `locore.s:173–190`·P2 `pad36.s` 에서 쓰임). 이름은 출처 없는 시험 이름입니다.
  - V2: 같은 자리를 이름 하나 + 오프셋(`<이름>+0xc:l`)으로(이 꼴은 아직 쓴 적 없음; 진단). 덧붙임 값이 있으면 산포 재배치가 될 수 있으므로, V1 과의 비교는 재배치 표가 아니라 링크 결과로 합니다.
- 컴파일 줄은 받아들인 객체를 만든 줄 그대로이고 출력 이름만 `stage/fpsp1.o`·`stage/fpsp2.o` 입니다.
- 링크(옵션은 P2 K2F 와 같음, `pad36` 없음, 나머지 295 객체는 P2 와 같음):
  - K4F: 순서 R(`conf` 202·`uipc_proto` 34·`ioconf` 268·`counters` 132·`vers` 283) + `fpsp1.o`
  - K5F: 순서 P(`vers` 268, `fpsp` 앞) + `fpsp1.o` — 순서 조건의 대조군
  - K4F2: 순서 R + `fpsp2.o`
  - 셋 모두 `strip -x`.
- 앞 명령의 산출물이 기대와 다르면 뒤 명령은 전제 실패로 둡니다(P2 와 같음). 링크 기록에는 `fpsp` 의 `__data` 원본 기준 주소 0x40b30ec 를 둡니다(비교기 `m7_m68k_compare.py:179–184` 가 기준 주소를 씀).

**(3) 미리 적는 예측**(빌더가 python 으로 계산)
- `fpsp1.o`: 받아들인 객체와 `__text` 크기·정렬이 같고, 바이트는 7 자리 4 B 만 다릅니다(저장 값 = 객체 안 `__data` 주소 + 오프셋; `__data` 는 `__text` 끝 0xa974 에서 시작한다고 예측). 재배치는 받아들인 것 1508 개 + 지역(절 2, 4 B, PC 상대 아님) 7 개이고, `__data` 36 B·바이트 0·정렬 2^0 이 새로 생깁니다. 외부 기호는 같습니다.
- `fpsp2.o`: 조립되면 절 목록·크기·바이트가 `fpsp1.o` 와 같습니다(재배치 꼴은 다를 수 있어 기록만 함). K4F2 를 strip 한 파일이 K4F 와 같은지로 판정합니다. 두 객체 모두 절 목록·flags·STABS(받아들인 객체는 `-g` 이지만 STABS 0)를 따로 봅니다.
- K4F·K4F2 를 strip 한 파일: P2 의 `k2f` 와 파일째 같다(원본과 6 B 차이, 크기 832196).
- K5F: `__data` 크기는 원본과 같고(`__bss`·`__common` 은 원본 자리), `vers` 기여가 0x40b30ec(−36), `fpsp` 의 `__data` 가 0x40b3158(+0x6c)입니다. 절 바이트에서 다른 것은 `vers` 기여와, `vers` 외부 기호를 가리키는 재배치(−36)·7 자리(+0x6c) 뿐입니다(수는 빌더가 계산). 기호표에서는 `_version`·`_version_major`·`_version_minor`·`_version_variant` 4 개의 값이 −36 입니다.

**(4) 판정과 뜻**: K4F 가 예측대로면, 36 B 는 "`fpsp` 객체의 9 칸 `__data` 이고 링크 순서가 `ioconf` ≤ `fpsp` < `vers`" 라는 가설이 바이트와 맞습니다. 다른 주인(덧붙임 값을 쓴 외부 참조 등)을 배제하지는 못하며, +0·+0x20 칸이 같은 할당에 속하는지도 정하지 못합니다(색인·간접 참조는 이 검사로 보이지 않음). 이것은 원본 소스의 증명도 아닙니다(칸의 이름·형, 한 배열인지 9 개인지, 어느 소스 파일에 있었는지는 바이트로 정해지지 않음). 07 `fpsp.s` 를 바꾸는 일은 D175 의 수락 파일을 바꾸는 것이므로 사용자 결정입니다. 결정 뒤에는 `fpsp` L1 다시 수락(지금 숫자 주소는 객체 비교에서 재배치로 바뀜), `ioconf`·`vers` 위치 조건의 링크 기록 반영이 필요합니다.

**(5) 하지 않는 것**: 07·상태표·M4/M5 객체를 바꾸지 않습니다. 시험 이름은 채택하지 않습니다. 커밋하지 않습니다.

#### 778.18.1 codex 검토 판정표(작업 `kv172tax9`)
내가 틀렸던 것(먼저): ① "기호가 없으니 같은 객체의 지역 참조" 라는 추론은 틀렸습니다 — 구간 밖 외부 이름 + 덧붙임 값도 가능합니다. ② `skeleton.sa` 와의 차이로 "1997 추가" 라고 시기를 붙였습니다. ③ 링크 줄에서 `vers.o` 를 "객체 끝" 이라 적었으나 뒤에 `$*.swap ${LIBS}` 가 있습니다. ④ K5F 예측에 기호표 변화(4 개)를 빠뜨렸습니다. ⑤ V2 의 재배치 꼴(산포 가능)과 비교기의 기준 주소를 생각하지 않았습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 외부 이름 + 덧붙임으로 구간을 가리킬 수 있음(`locore` `_cnt` 덧붙임 0xc·4·8) | python: `Q754__locore_F.o` `_cnt` 덧붙임 `['0x4','0x8','0xc']`; `0x40b3110-0x18 = 0x40b30c4+0x34 = 0x40b30f8` | ✅ 내 오류 정정 |
| NeXTMach 는 FPSP 를 `ld -r` 로 묶음(`fpsp/Makefile:24–27`) | 열람: `fpsp: ${TRANS}` / `ld -r ${TRANS} -o fpsp.o` | ✅ 반영 |
| 7 값·처리기·줄 번호·받아들인 객체(43380 B·정렬 0·재배치 1508·그 자리 재배치 없음) | 내 python 출력(위 (1))과 같음; 07 `fpsp.s` 일곱 줄 열람 | ✅ |
| 모든 바이트 간격 검색에서도 추가 값 없음 | 재현 안 함(내 검사는 2 B 간격) | ⏭️ 문서에 넣지 않음 |
| 시기 단정 삭제 | `skeleton.sa:49–55` 열람(`rte`) | ✅ 문구 정정 |
| R 순서: `__common`·문자열·단조, `ioconf` 끝 0x40b30ec·정렬 2^1, 273–282 는 `__text`·`__const` 만 | 내 텍스트 순서 출력(273–282 `d None`·`b None`) | ✅ (R 은 빌더가 다시 단정) |
| `vers.o` 뒤 `$*.swap ${LIBS}` | `Makefile.template:289` 열람 | ✅ 문구 정정 |
| 객체 안 `__data` 주소 = 텍스트 끝(`monitor` 0x164·정렬 0, `locore` 0x1f74) | python: `M4:monitor` `__data` 0x164·`M4:locore` 0x1f74 | ✅ |
| `monitor` 지역 재배치 저장 값 0x164 | 재현 안 함 | ⏭️ |
| V2 는 산포 재배치가 될 수 있음 | 문서 근거만(재현 안 함) | ⚖️ 비교를 링크 결과로 바꿈 |
| 받아들인 `fpsp` 는 `-g` 인데 STABS 0 | python: stabs 0, nsyms 1088 | ✅ 검사 항목 추가 |
| K5F 에서 `vers` 외부 4 개 값 −36, `_version` 재배치 3 | 4 개는 `vers` 의 외부 정의(778.17 의 외부 정의 −36 재배치 3 과 맞음); 값은 빌더가 계산 | ✅ 예측에 추가 |
| P2 `k2f` 832196 B·6 B 차이 | 778.17 기록 | ✅ |
| 16 비트 절대·PC 상대 16 비트로는 닿지 않음, 색인·간접은 미해결 | 논리 맞음(텍스트 끝에서 구간까지 16 비트 범위 밖); Capstone 결과는 재현 안 함 | ⚖️ 한계로만 적음 |
| 비교기는 기준 주소가 필요(`m7_m68k_compare.py:179–184`) | 열람: `r = rec['ref_layout'][k][sn]` | ✅ 반영 |

### 778.19 P5 결과 (실기 run `m7p778-p5-1` 미수집, 2026-11-09; 07·상태표·M4/M5 객체 불변; 기록 `09_validation/reconstruction/m7-m68k-p778-p5-20261109.json`, 빌더 `scratch/p778/p5_build.py`, 판독 `scratch/p778/p5_analyze.py`)
- 운영: 8 명령 모두 종료 0, stdout·stderr 빔, 손 검사 모두 통과. 준비된 `src/` 1330 파일은 오버레이와 바이트가 같습니다(빈 파일 `generated/cputypes.h` 는 기준 run `m4p770-a2` 에서도 0 B).
- 시험 객체(V1 `fpsp1.o`, V2 `fpsp2.o`): 둘 다 예측과 같습니다.
  - 절은 `__text` 43380 B(정렬 0)와 새 `__data` 36 B(객체 안 0xa974, 정렬 0, 바이트 모두 0)입니다.
  - `__text` 는 받아들인 객체와 7 자리 4 B(28 B)만 다르고, 그 값은 예측한 0xa974 + 오프셋(0xa978–0xa990)입니다.
  - 재배치를 의미로 비교하면 받아들인 1508 개가 모두 그대로이고 새로 7 개가 생깁니다. V1 은 절 2 를 가리키는 지역 재배치(4 B, PC 상대 아님), V2 는 값 0xa974 인 산포 재배치입니다(원시 표의 다른 항목은 지역 기호가 늘어 기호 번호만 밀린 것).
  - 외부 기호는 같고 STABS 는 0 입니다.
- K4F(순서 R: `ioconf` 268 < `fpsp` 272 < `vers` 283, `fpsp1.o`, 채움 없음)를 strip 한 파일은 P2 의 `k2f`(36 B 진단 채움)와 **파일째 같고**, 원본과는 이미 알던 텍스트 6 B 만 다릅니다(크기 832196). `fpsp` 의 `__data` 가 0x40b30ec 에 놓여 원본 36 B 구간을 정확히 채웁니다. K4F2(`fpsp2.o`)도 K4F 와 파일째 같습니다.
- K5F(순서 P: `vers` 가 `fpsp` 앞)는 예측대로입니다.
  - `vers` 가 0x40b30ec, `fpsp` 의 `__data` 가 0x40b3158 에 놓입니다.
  - 미리 센 10 자리(`vers` 외부 정의 참조 3 개 −36, 칸 7 자리 +0x6c)가 모두 맞고, 그 밖의 차이는 텍스트 6 B 뿐입니다. 기호는 `_version` 등 4 개 값만 −36 입니다.
  - 헤더·절 배치·`__bss`·`__common` 은 원본과 같습니다. 파일 차이는 167 B 입니다.
- 뜻: 36 B 영 구간은 "`fpsp` 객체의 `__data` 9 칸(4 B, 값 0, 외부 이름 없음)과 링크 순서 `ioconf` ≤ `fpsp` < `vers`" 로 원본과 바이트째 맞습니다. 칸을 쓰는 곳은 `real_*` 처리기 7 곳(+4–+0x1c)이고, +0·+0x20 칸은 쓰는 곳을 찾지 못했습니다. 이 꼴에서는 진단용 채움 `pad36` 이 필요 없고, 07 `fpsp.s` 의 숫자 주소 7 개는 링크 위치에 기대지 않는 지역 참조가 됩니다.
- 한계: 다른 주인(구간 밖 외부 이름 + 덧붙임 값, 다른 단위의 정적 자료)을 바이트만으로 배제하지는 못합니다. 칸의 이름·형, 배열 하나인지 9 개인지, 원래 어느 `.sa` 파일에 있었는지는 정해지지 않습니다(NeXTMach 는 FPSP 를 `ld -r` 로 묶음). 시험 이름 `p778c*`·`p778cnt` 는 채택하지 않습니다.
- 07 반영(사용자 결정 필요): ① 07 `fpsp.s`(D175 수락 파일)에서 숫자 주소 7 개를 지역 이름으로 바꾸고 `.data` 9 칸을 더할지와 그 이름·꼴 ② 바꾸면 `fpsp` 를 다시 L1 수락(원본 비교에서 7 자리가 재배치가 되고 `__data` 36 B 가 `fpsp` 의 것으로 검증되어, 미검증 41 B 가 1 B 틈 5 곳 5 B 로 줄어듦) ③ 링크 기록의 단위 위치 조건 `ioconf` ≤ 272 < `vers`.

## 779. D178 의 07 반영 — `__common` 선언·`fpsp` 칸·재수락·회귀 (코딩 전 계획, 2026-11-09)
사용자 결정 D178("권장안으로 진행합니다")에 따라 778.15 의 시험 꼴 F1′·F2–F9 와 778.19 의 `fpsp` V1 을 07 에 넣습니다. 원칙: **시험 꼴과 줄 수·줄 위치를 똑같이** 둡니다(설명 주석만 바꾸고, 표지 규칙 때문에 필요한 주석은 같은 줄에 붙임; `nextdbg.c` 처럼 끝 줄바꿈이 없는 파일은 시험 빌더 `p3b_build.py:149` 처럼 줄바꿈 하나를 먼저 더함). 다만 P3b 의 M4 시험(`ev`·`if_en`·`m68k_init`)은 F2(`pmap.h`) 없이 컴파일했고(`p3b_build.py:157` 은 M5 run 에만 적용), `fpsp` 는 지역 이름이 바뀌므로, 07 로 만든 객체가 시험 객체와 파일째 같다고 예측할 수 있는 것은 M5 넷과 `nextdbg` 뿐입니다. 나머지는 차이를 미리 정해 판정합니다(779.3). 출처 없는 위치·이름은 "바이트에 맞춘 작성(D024)" 으로 표시합니다.

### 779.1 07 변경(파일별; 줄 수는 시험 꼴과 같음)
- (F1′·F5) 오버레이 `07_kernel/v183.34/m68k/src/bsd/kern/subr_prf.c` 끝에 두 줄 `#import <mon/tftp.h>`·`#import <m68k/bmap.h>`(각 줄에 표지 `plan 779 (m68k)`). `mon/tftp.h`·`mon/bootp.h`(07 `nextmach/mon/`, 계획 583 의 사본)를 다시 스테이지에 둡니다(`M4HEADERS[779]`; 계획 585 에서 뺀 두 항목). `mon/global.h` 는 바꾸지 않습니다(D133 유지).
- (F2) 오버레이 `07_kernel/v183.34/m68k/src/machdep/m68k/pmap.h` 의 마지막 `#endif` 앞에 네 줄(`#ifdef KERNEL`, `struct pv_entry *pv_head_table;`, `struct zone *pv_list_zone;`, `#endif`). 오버레이 `.h` 는 표지 검사 대상이 아닙니다(`stage_m68k.py:585–622` 는 `.c` 만).
- (F3) 새 `07_kernel/nextmach/next/scr.h` = NeXTMach mk-108.1 `next/scr.h` 의 사본에서 `volatile struct scr1 *scr1;` 한 줄을 빼고 머리에 설명 한 줄을 둔 것(시험 꼴과 같은 줄 수; NeXTMach 고지 보존, D013), 스테이지 `src/bsd/m68k/scr.h`(`M4HEADERS[779]`). 오버레이 `kern_exit.c` 끝에 `#import <m68k/scr.h>` 한 줄(표지). 파일 안 상수(`kern_exit.c:99–103`, plan 471)는 시험 꼴대로 남깁니다(빼는 꼴은 시험하지 않았음).
- (F4) 새 오버레이 `07_kernel/v183.34/m68k/src/bsd/dev/vol.c` = 07 본 파일 + 끝 세 줄(설명·`u_short dma_chip;`·`int slot_id;`, 각 줄 표지). `OVLFROM['src/bsd/dev/vol.c'] = 779`. 07 본 파일 `src/bsd/dev/vol.c` 는 x86 스테이지 g1a 에 해시와 함께 있으므로(`s6ln-g1a-stage.manifest.json`) 바꾸지 않습니다.
- (F6) 새 `07_kernel/src/machdep/m68k/ev_vars.h`(P3b `p3b_build.py:ev_vars_h()` 출력과 같은 줄; 머리 줄 설명만 바꿈; `KeyMapping` 은 07 `ev_kbd.c:66–67,75–85` 의 사본, 50 이름의 형은 07 `extern` 과 같음), `M4HEADERS[779]` 에 `('machdep/m68k/ev_vars.h', 'src/machdep/m68k/ev_vars.h', '07_kernel/src')`. `ev.c` 끝에 `#import "ev_vars.h"` 한 줄.
- (F7) `if_en.c` 끝에 두 줄(설명, `struct kdb_n { … } kdb_net;`). (F8) `m68k_init.c` 끝에 시험 꼴 (가) 의 18 줄(import 다섯·정의). (F9) `nextdbg.c` 끝에 두 줄.
- (`fpsp`) `fpsp.s` 의 7 줄을 `addql #0x1,<이름>:l` 로 바꾸고 파일 끝에 20 줄(설명·`.data`·이름 9 개와 `.long 0`). 이름은 임시 작성 이름 `fpsp_cnt0`–`fpsp_cnt8`(시험 이름 `p778c*` 와 길이가 달라도 객체 바이트에는 영향 없음 — 지역 기호 문자열만 다름; 아래 관문은 이 차이를 따로 셈).
- 등록(`stage_m68k.py`): `M4FILES[779] = list(M4FILES[777])`, `M4HEADERS[779] = list(M4HEADERS[770])` + 위 넷, `OVLFROM` 의 `vol.c`, `MARKERS['plan 779 (m68k)'] = {subr_prf.c: 2, kern_exit.c: 1, vol.c: 3}`, `EXCEPTS[779]`(777 것 + 시험 스테이지와 다를 것이 예정된 객체; `compare` 의 판정 방식을 열어 본 뒤 정함), 머리 설명의 계획 목록.
- 문서: `PROVENANCE.tsv`(7 열; 고친 행: `pmap.h`·`subr_prf.c`·`kern_exit.c`·`tftp.h`·`bootp.h`("계획 583 에서만 스테이지" 문구 고침)·`ev.c`·`if_en.c`·`m68k_init.c`·`nextdbg.c`·`fpsp.s`; 새 행: `scr.h`(NeXTMach 출처), `ev_vars.h`(`KeyMapping` 은 NeXTMach `ev_kbd.c` 계보 — `PROVENANCE.tsv:1236` 과 같은 출처와 고지 — 와 D024 작성 부분을 나눠 적음), 오버레이 `vol.c`), `MODIFICATIONS.md`(행 추가), 증거 `06_reconstruction/evidence/`(`m68k-ev.md`·`m68k-if_en.md`·`m68k-m68k_init.md`·`m68k-nextdbg.md`·`m68k-fpsp.md`(기존 표의 소스 해시는 역사 기록으로 두고 새 판 절을 더함)·`m68k-overlay.md` 절 추가와 diff), 이 계획서 결과 절.

### 779.2 스테이지·관문(실기 전)
- `stage_m68k.py --plan 779 stage` → 새 스테이지. 777 스테이지와의 차이가 새 경로 4 개(`src/mon/tftp.h`·`src/mon/bootp.h`·`src/bsd/m68k/scr.h`·`src/machdep/m68k/ev_vars.h`)와 바뀐 경로 9 개(`subr_prf.c`·`kern_exit.c`·`vol.c`(07 본 파일 → 오버레이)·`pmap.h`·`ev.c`·`if_en.c`·`m68k_init.c`·`nextdbg.c`·`fpsp.s`)와 manifest 뿐인지 python 으로 확인.
- 스테이지의 각 바뀐 파일이 P3b·P5 오버레이의 같은 파일과 줄 수가 같고, 설명 주석 말고는 같은지 python 으로 확인(다르면 멈춤).
- `x86gate` 7/7 같음, `m4_x86_inputs.py` 통과, 07 의 x86 쪽 파일 불변(바꾼 07 경로가 모두 m68k 전용 경로인지).

### 779.3 실기 빌드와 미리 정한 판정
- 비교 도우미(새 `10_tools/reconstruction/m7_m68k_objdiff.py`, python 표준 라이브러리, 읽기 전용): 두 객체에 대해 (a) `canon`(`m3_m68k_diag.py:34–43`) 같음 (b) STABS 를 뺀 기호표를 물리 순서·이름·종류·절·값(COMMON 크기)까지 비교해 "더해진 COMMON 이름 / 미정의 → COMMON 이름 / 그 밖의 차이" 로 나눔 (c) STABS 는 수만 기록하고 판정하지 않음(디버그 기록; 머리 import 로 형 번호가 다시 매겨질 수 있음; strip 한 커널에는 없음) (d) 헤더·절 목록·절 정렬·flags. 판정 "허용" = (a) 같음 + (b) 의 그 밖 차이 0 + 더해진 이름이 객체별 허용 목록 안 + (d) 같음.
- 객체별 허용 목록: `pmap.h` 를 포함한 객체는 `_pv_head_table`·`_pv_list_zone`; 그 밖은 시험 꼴 이름 묶음(`scratch/p778/p3b_groups.json` 의 F1(+`_etherbroadcastaddr`·`_ifnet`·`_rawintrq`)·F3–F9)과 `fpsp` 의 지역 이름(지역 기호는 이름만 다를 수 있음).
- **R1 진단 run**(새 ID, 미수집, 779 스테이지): 다시 만들 M4 객체 모두(받아들인 76 객체의 컴파일 줄; 계획 621–622 의 재현 방식, `m4p621-b1`·`m4p622-r1` 선례)와 M5 205(`--plan 779 cmd`). 판정:
  - 모든 명령 종료 0, stderr 는 각 객체를 만든 원래 명령의 stderr 와 같음(P3b 와 같은 비교).
  - 받아들인 객체(M4 76 + M5 205 기준 `m3-m68k-p764-compare-20261107.json` 의 객체) 대비: 모두 "허용".
  - 시험 객체 대비: M5 `subr_prf`·`cmu_syscalls`·`kern_exit`·`vol` 과 M4 `nextdbg` 는 파일째 같음; `ev`·`if_en`·`m68k_init` 은 "허용" 이고 더해진 이름이 `_pv_*` 뿐; `fpsp` 는 `canon` 같고 기호표 차이가 지역 이름 9 개의 문자열뿐.
  - 위 가운데 하나라도 어긋나면 멈추고 원인을 찾습니다(관문을 낮추지 않음).
- `stage_m68k.py --plan 779 compare` 도 돌려 기존 기록 꼴(`differ_unexpected`·`lost`·`undefined_new_not_in_original`)을 남깁니다. 이 명령은 종료 상태·stderr·COMMON 변화를 판정하지 않으므로(`stage_m68k.py:757–813`) 위 도우미 판정이 주 관문입니다. `EXCEPTS[779] = dict(EXCEPTS[777])`(`EXCEPTS` 는 `canon` 차이의 주석일 뿐 기호 차이를 허락하지 않음; `canon` 은 이번 변경으로 바뀌지 않아야 함).
- **M4 재수락**(최종 run, 새 ID): CODE+BSS_INFERRED 넷(`ev`·`if_en`·`m68k_init`·`nextdbg`)은 계획 779 의 spec(`bss_inferred` 에 넷) + `m5_m68k_zerofill.py objs` 기록, `fpsp`(OBJECT_MATCH)는 계획 780 의 spec(상태 도구가 기록 하나에 한 수락 종류를 적용, `m4_m68k_status.py:167–215`). 두 spec 모두 779 스테이지를 `base` 로 하고, REF 는 R1 진단 run 의 객체(해시 고정; 679 p2 선례). L1 은 원본과 같아야 하고(`fpsp` 는 새 `__data` 36 B 가 원본 [0x40b30ec, +36) 과 비교됨 — 기존 `fpsp1.o` 를 L1 으로 읽어 `OBJECT_MATCH` 인지 실행 전에 확인), zerofill 은 새 정적 bss 자리가 이전 수락 자리와 같고, 받아들인 다른 M4 자리와 겹치지 않음(바꿀 기록은 빼고 전체 겹침 검사)을 따로 봅니다.
- 상태표: 실행 전 지금 상태표를 보관하고, 두 최종 기록·zerofill·증거를 모두 갖춘 뒤 `ACCEPTED` 의 다섯 행을 한꺼번에 바꾸고 두 번 돌려 같은 결과를 얻습니다(그 전에는 원본 해시 검사로 멈추므로 돌리지 않음). 나머지 71 행은 바이트 단위 불변이어야 합니다.
### 779.4 뒤 단계(이 계획에서 하지 않음)
- `__data` 지표 갱신(`fpsp` 36 B 를 검증 바이트로 셈; 새 data spec·run, `selftest` 의 고정 값 손질)과, `pmap.h` 를 포함하는 R 3(`kern_exec`·`mach_process`·`ns_timer`)·D 2(`fd_global`·`scsiconf`)의 재현 — 계획 781. M4 재수락 뒤에는 지금 data 기록의 고정 해시가 맞지 않게 되므로(`m4_m68k_data.py:353–422`) 781 전까지 `__data` 지표는 "779 이전 값" 으로 표시합니다.
- M7 수집 링크(받아들인 객체만; `m7_m68k_link.py` 의 고정 입력 `M5DIR`·`CHECK777`(`:29–30`)를 새 기록으로 바꿔야 섞인 객체 집합이 되지 않음) — 계획 782. 778.17·778.19 와 같은 결과(원본과 텍스트 6 B 차이)가 나와야 합니다.

### 779.5 하지 않는 것·한계
기능 추가 없음(선언·포함·자료 칸만). `kern_exit` 의 파일 안 상수 정리, `mon/global.h` 의 `tftp.h` 되살림은 하지 않습니다. 바이트 일치는 원본 소스의 증명이 아닙니다. 커밋하지 않습니다.

### 779.6 codex 검토 판정표(작업 `ksceug5gb`)
내가 틀렸던 것(먼저): ① P3b 의 M4 시험 객체(`ev`·`if_en`·`m68k_init`)는 F2 없이 컴파일되어 `_pv_*` 가 없으므로, 그것을 REF 로 쓰면 관문이 반드시 실패합니다. ② `fpsp` 지역 이름을 바꾸면 기호 문자열이 달라져 `obj_sig` 도 달라집니다. ③ `stage_m68k compare` 가 M5 회귀 판정을 해 준다고 보았으나, 종료 상태·stderr·COMMON 변화를 판정하지 않습니다. ④ 스테이지 차이를 "새 6·바뀐 8" 로 잘못 셌습니다(새 4·바뀐 9). ⑤ `pmap.h` 를 포함하는 객체(M4 45·M5 113·R 3·D 2)의 회귀를 M5 205 로만 덮으려 했습니다. ⑥ `-M` 의존 목록 비교만으로 기준 차이를 확인했는데, `-imacros` 의 생성 헤더는 그 목록에 없습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 스테이지 경로·표지 수 2/1/3 이 `check_derived` 통과 | `stage_m68k.py:585–622` 열람(표지 줄만 끼워 넣고 나머지는 07 본 파일과 같아야 함); 실제 통과는 구현 뒤 `stage` 로 확인 | ⚖️ 규칙은 확인, 통과는 실행으로 |
| 오버레이 `.h` 는 검사 밖 | 같은 줄 열람(`check_derived` 는 `.c` 오버레이에만 호출) | ✅ |
| `nextdbg.c` 끝 줄바꿈 없음 | `tail -c1`: `nextdbg.c` 만 `/`, 나머지 `\n` | ✅ 반영 |
| 스테이지 차이 새 4·바뀐 9 | 경로 목록을 다시 셈(`vol.c` 는 이미 있는 경로) | ✅ 정정 |
| P3b M4 객체는 F2 없이 컴파일(`_pv_*` 없음) | python: `ev`·`if_en`·`m68k_init` 은 `pmap.h` 의존 True, `_pv_head_table` 없음; `nextdbg` 는 의존 False | ✅ 내 오류 정정 |
| `-imacros` 생성 헤더는 `-M` 밖, `m4p680-a1` 의 `od.h` 가 다름 | python: 기준 6 개 중 `m4p680-a1` 만 `od.h` 다름(`NOD 1` → `NOD 2`·`NOC 1`, 계획 683) | ✅ 반영(R1 에서 판정) |
| 기준 run 과 777 의 `-M` 의존 내용 차이 0 | 내 python: 아홉 대상 모두 0 | ✅ |
| `fpsp` 이름 바꾸면 `obj_sig` 다름(지역 기호 9 개) | `obj_sig` 가 STABS 외 모든 기호를 담음(`l2_prefix_diff.py:48–53`, 에이전트 보고와 codex 일치; 줄 열람은 구현 때) | ⚖️ 판정 방식 바꿈(지역 이름 문자열만 다른지 따로 봄) |
| 기존 `fpsp1.o` 의 L1 `OBJECT_MATCH` | 재현 안 함 | ⚠️ 실행 전에 확인(779.3) |
| `stage_m68k compare` 는 429/432 기준, 상태·stderr·COMMON 판정 없음, `EXCEPTS` 는 `canon` 차이 주석 | `stage_m68k.py:757–813` 은 에이전트와 codex 가 같은 내용; 줄 열람은 도우미 작성 때 | ⚖️ 새 도우미를 주 관문으로 |
| `obj_sig` 는 STABS 수만 담음, P3b 에서 STABS 수가 바뀜(967→969 등) | 재현 안 함 | ⚖️ STABS 는 판정하지 않고 수만 기록 |
| `pmap.h` 의존 M5 113·M4 45·R 3·D 2 | python 같은 수(R·D 이름 같음) | ✅ 반영 |
| 상태 도구는 `m4_headers` 만 의존 해시 확인(오버레이 머리 놓침) | 에이전트 보고 `m4_m68k_status.py:180–197` 과 같음 | ✅ R1 재현 run 으로 덮음 |
| spec 구성·`bss_inferred`·`-DASSEMBLER`·기록 하나에 한 수락 종류 | 에이전트 보고와 같음(`m4_m68k_status.py:167–215`) | ✅ 779/780 나눔 |
| zerofill 은 M5 464 자리와만 비교 → 전체 겹침 검사 필요 | 재현 안 함(구현 때 `m5_m68k_zerofill.py:150–169` 열람) | ⚠️ 구현 때 확인 |
| `m7_m68k_link.py` 의 `M5DIR`·`CHECK777` 고정, data 도구 고정 해시 | `m7_m68k_link.py:29–30` 열람(`M5DIR`·`CHECK777`) | ✅ 781·782 에 적음 |
| `PROVENANCE.tsv` 7 열, `KeyMapping` 계보(`:1236`), `tftp.h`·`bootp.h` 문구(`:1173–1174`), `m68k-fpsp.md:11` 고정 해시 | 열람은 문서 작성 때 | ⚠️ 문서 작성 때 확인 |

### 779.7 결과 (2026-11-09; 커밋 안 함)
- 07 반영: 07 파일 11 개를 시험 파일에서 만들었습니다(`scratch/p779/apply07.py`; 시험 파일이 "07 본 파일 + 더한 줄" 꼴인지 단정한 뒤 시험 주석만 바꿈; 줄 수 같음). 바꾼 파일은 오버레이 `subr_prf.c`·`kern_exit.c`·`pmap.h`, 07 `ev.c`·`if_en.c`·`m68k_init.c`·`nextdbg.c`·`fpsp.s` 이고, 새 파일은 오버레이 `vol.c`·`nextmach/next/scr.h`·`src/machdep/m68k/ev_vars.h` 입니다. 등록은 `stage_m68k.py` 의 `M4FILES[779]`·`M4HEADERS[779]`·`OVLFROM`(`vol.c`)·`MARKERS['plan 779 (m68k)']`(2/1/3)·`EXCEPTS[779]` 입니다.
  - 내 오류: 첫 실행이 오버레이 디렉터리를 만들지 않아 도중에 멈췄고, 그 전에 두 파일이 써졌습니다. 보관본으로 되돌린 뒤("07 본 파일 + 더한 줄" 단정이 다시 통과) 고쳐 다시 돌렸습니다.
  - 주석 문구는 같은 줄 안에서만 다듬었습니다.
- 스테이지 `08_build/runs/tools/m4p779-base-stage`(1047 파일): 777 스테이지와의 차이는 새 경로 4·바뀐 경로 9(`vol.c` 는 출처가 07 본 파일 → 오버레이)와 manifest 의 계획 번호·목록뿐입니다. 13 파일 모두 시험 파일과 줄 수가 같고, 주석·이름 말고 다른 줄이 없습니다. 표지 검사도 통과했습니다.
- x86: `--plan 779 x86gate` 7/7 같음(`v183.34` 경로 0, `08_build/artifacts/m4p779/x86gate/x86gate.json`), `m4-x86-inputs-p779-20261109.json` `ok`. 07 본 파일 `vol.c` 는 그대로입니다(SHA-256 `657799a7…` = x86 스테이지 기록).
- R1 회귀(`09_validation/reconstruction/m4-m68k-p779-r1-20261109.json`; 도우미 `10_tools/reconstruction/m7_m68k_objdiff.py`, 자기 시험 5 쌍 기대대로):
  - run 은 M5 205 `m3p779-cc1`(수집, 2026-11-08T23:22–23:28Z)와 M4 76 `m4p779-r1`(미수집)입니다. 모든 명령이 종료 0 이고, stderr 는 각 객체를 만든 원래 명령과 같습니다.
  - 받아들인 객체와 비교한 280 쌍(M5 205 + `fpsp` 를 뺀 M4 75)과 시험 객체와 비교한 9 쌍, 모두 289 쌍이 "허용" 입니다(`canon`·헤더·절 같음, 그 밖의 기호 차이 0). 더해진 COMMON 의 꼴은 다음과 같습니다.
    - `_pv_*` 만: 152 객체
    - 없음: 121 객체
    - 계획한 이름: 바꾼 소스 객체 7 개
  - 시험 객체 대비: M5 `subr_prf`·`cmu_syscalls`·`kern_exit`·`vol` 과 M4 `nextdbg` 는 파일째 같습니다. `ev`·`if_en`·`m68k_init` 은 `_pv_*` 둘만 더 있습니다. `fpsp` 는 지역 이름 9 개의 문자열만 다릅니다.
  - `--plan 779 compare`(`m3-m68k-p779-compare-20261109.json`)의 요약(`differ` 목록·`object_match` [146, 175]·`differ_unexpected`·`lost` 빔)이 계획 764 와 같습니다.
- 재수락:
  - 계획 779 spec(넷, REF = R1 객체, `bss_inferred`): run `m4p779-a1`, `m4-m68k-p779-final-20261109.json`(SHA-256 `d0e75cd3…`), `gate.ok`. 넷 모두 `provisional` 이고, L1 사유는 `__DATA,__bss: unverified` 뿐입니다.
  - zerofill `m4-m68k-zerofill-p779-20261109.json`(`e03eb72a…`): 넷 모두 `ok`·겹침 0 이고, 정적 bss 자리가 이전 수락 기록(689·727·680·739)과 같습니다(python).
  - 계획 780 spec(`fpsp`): run `m4p780-a1`, `m4-m68k-p780-final-20261109.json`(`0dbea028…`), `gate.ok`, L1 `OBJECT_MATCH`. `__text` 43380 B 이고, `__DATA,__data` 36 B 가 0x40b30ec 에 놓여 차이 0 입니다.
  - `nextdbg` 최종 객체는 P3b 시험 객체와 파일째 같습니다(`b6605e4b…`).
- 상태표: 이전 표를 보관하고 `ACCEPTED` 의 680·689·727·739(zerofill 포함)·770 을 779(4 칸)·780 으로 바꿨습니다. 두 번 돌린 결과가 같습니다(`m4-m68k-status-p779-20261109.json`).
  - 76 행 가운데 바뀐 것은 다섯 행의 계획 번호·기록·객체 해시뿐이고, 71 행은 그대로입니다.
  - 요약도 그대로입니다: 76 객체(OBJECT_MATCH 54·CODE+BSS_INFERRED 22), 행 151/188, 78.15 %.
- 문서:
  - `PROVENANCE.tsv`: 1259 → 1262 행. 열 행을 고치고 새 행 셋을 더했으며 모든 행이 7 열입니다.
  - `MODIFICATIONS.md`: 8 행을 더했습니다.
  - 증거: 새 `06_reconstruction/evidence/m68k-p779.diff`(이전 07 → 새 07; `scr.h` 는 NeXTMach 원본 → 07). 기존 `m68k-ev.diff`·`m68k-m68k_init.diff` 는 지금 남은 이전 07 파일로 다시 만들어지지 않아 역사 기록으로 두었습니다.
  - `m68k-{ev,if_en,m68k_init,nextdbg,fpsp,overlay}.md` 에 계획 779 절을 더했습니다.
  - 결정 D178 을 적었습니다.
- 오프라인 확인(python, 읽기 전용): 새 상태표의 M4 와 `08_build/artifacts/m4p779/m5compare` 의 M5 로 296 객체를 만들고 순서 R(`ioconf` 268·`vers` 283)로 계산했습니다(도구 상수는 메모리에서만 바꿈). 합성 선언·scratch 객체 없이 `__common` 613 순서·주소와 절 끝 0x40c9908 이 원본과 같고, 원본에 없는 할당은 0, 크기를 모르는 이름도 0 입니다.
- 남은 일:
  - 계획 781: `__data` 지표(`fpsp` 36 B 를 검증 바이트로)와 `pmap.h` 를 포함하는 R 3·D 2 의 재현입니다. 그때까지 `m68k-data-status.tsv` 의 값은 "779 이전" 입니다.
  - 계획 782: `m7_m68k_link.py` 의 `M5DIR`·`CHECK777` 를 새 기록으로 바꾸고 수집 run 으로 M7 링크를 다시 만듭니다. 원본과 텍스트 6 B 차이가 예측입니다.

## 781. `__data` 지표 갱신과 R 3·D 2 의 재현 — 계획 779–780 뒤 (코딩 전 계획, 2026-11-09)
사용자 지시 "가장 안전하고 확실한 방법으로 다음 작업을 진행" 에 따라 779.4 의 남은 일 가운데 781 을 먼저 합니다. 782(M7 수집 링크)는 781 이 만든 기록(R·D 객체)을 쓰므로 781 뒤에 따로 계획합니다. 07 은 바꾸지 않습니다.

### 781.1 사실(열람·python)
- `m4_m68k_data.py` 의 `coverage` 는 M4 를 상태표(`STATUS`)의 L1 기록에서, M5 를 고정 상수 `M5CMP = '08_build/artifacts/m4p764/m5compare'`(`:47`, `m5_records` `:367–372`)에서 읽고, 두 집합의 해시를 spec 의 `pins` 와 대조합니다(`:420–422`). 지금 상태표는 계획 779–780 의 객체(`fpsp` 의 `__data` 36 B 포함)를 가리키므로 계획 777 의 `m4_set_sha256` 와 맞지 않습니다.
- `check` 는 run 의 명령 줄·상태·stderr·소스 해시·L1(`OBJECT_MATCH`, `__data` 주소·크기·차이 0)·기호 집합·`-M` 목록(고정 해시 `deps_sha256`)·고정 기준 객체와의 `canon` 을 봅니다. 검사 기록 재검증(`verify_check_record`)은 도구와 spec 의 해시가 같아야 통과합니다(`:388–390`).
- `selftest` 는 검사 기록 경로를 `m4-m68k-p%d-check-20261108.json` 으로 고정합니다(`:586`). `_log/04.out` 은 첫 단위 `tty_conf` 의 `-M` 출력이라는 가정입니다(R 3 줄 뒤; spec 의 순서가 같으면 그대로 맞음).
- 계획 777 의 결과(`m4-m68k-p777-coverage-20261108.json`): 146 범위(M4 37·M5 94·M5-refresh 2·M4-data 13), 덮은 22511 B / 22552 B, 빈 구간 41 B(1 B 다섯 + [0x40b30ec, 0x40b3110) 36 B), 겹침 `tty_pty` 4 B.
- 계획 779 R1 에서 M5 205 는 모두 `canon` 이 같았으므로 `__data` 바이트도 같습니다. 그러나 지표의 근거 기록은 지금 객체(`m4p779/m5compare`)를 가리켜야 782 와 섞이지 않습니다.
- `pmap.h` 를 포함하는 R·D: `kern_exec`·`mach_process`·`ns_timer`·`fd_global`·`scsiconf`(P3a 의존 목록).

### 781.2 도구 변경(최소, 이전 동작 보존)
- `load`: spec 에 선택 키 `m5compare`(문자열 경로)를 허용합니다(필수 키는 그대로, 모르는 키는 계속 거부). 없으면 지금 상수 `M5CMP` 를 씁니다. `m5_records` 가 이 값을 받고, `coverage` 와 `pins` 가 spec 을 읽어 넘깁니다(`pins` 는 지금 spec 을 읽지 않음, `:379–381`).
- `selftest`: 선택 인수 `CHECK.json` 을 더합니다(명령 줄 분기까지). 없으면 지금 고정 경로를 씁니다. 양성 대조 "check record verifies" 는 지금 기록 자신의 spec·도구 해시를 넘겨(`:588–589`) 낡은 기록도 통과시킵니다. 이를 실제 spec·도구 해시로 바꿉니다(검사를 강하게 하는 쪽).
- 그 밖의 검사는 바꾸지 않습니다. 도구 해시가 바뀌므로 계획 777 의 검사 기록은 새 도구로 다시 검증되지 않습니다(역사 기록). 다시 볼 수 있도록 바꾸기 전 도구와 779 이전 상태표(`scratch/p779/m68k-m4-status.tsv.before779`)의 사본과 해시, 그리고 다시 돌리는 방법(`10_tools/reconstruction` 을 모듈 경로로 두고 `STATUS` 를 옛 표로)을 기록에 적습니다.
- 변이 시험: 새 spec 으로 `selftest` 를 돌려 기존 대조군 46 개(음성 39·양성 7)가 그대로 나와야 합니다. 더해 (가) spec 에 `m5compare` 가 없을 때 옛 상수, 있을 때 그 경로를 쓰는지 (나) 낡은 검사 기록(spec 해시를 바꾼 사본)을 양성 대조가 거부하는지를 python 으로 따로 시험합니다.

### 781.3 spec 781 과 실행
- `08_build/artifacts/m4p781/spec.json` = 계획 777 spec 에서 `plan` 781, `base` = `08_build/runs/tools/m4p779-base-stage`, `m5compare` = `08_build/artifacts/m4p779/m5compare`, `pins` = `pins` 명령의 새 값으로 바꾼 것. 단위 13·R 3·기준 객체·`deps_sha256`·대조군은 그대로입니다(같은 기준 객체와 `canon` 이 같아야 함).
- `cmd` → 새 run `m4p781-a1`(준비의 src 는 779 스테이지; 수집 뒤에 `check`, 도구가 `out/` 을 읽음 `:261`) → `check` → `selftest`(CHECK 경로를 명시) → `coverage`.

### 781.4 미리 적는 예측(python 으로 위 기록에서 계산)
- `check`: 16 항목 모두 OK, `verified_bytes` 7740(777 과 같음).
- R·D 회귀(`m7_m68k_objdiff.py`, 기준 = `m4p777-a1/out` 의 같은 이름 `Q777R__`·`Q777D__` → `Q781R__`·`Q781D__`): `fd_global`·`scsiconf`·`kern_exec`·`mach_process`·`ns_timer` 는 더해진 이름이 `_pv_head_table`·`_pv_list_zone` 뿐이고(STABS 는 판정하지 않음), 나머지 11 객체는 파일째 같음. 쌍과 결과를 기록에 남깁니다.
- `coverage`: 147 범위(M4 38·M5 94·M5-refresh 2·M4-data 13), 덮은 22547 B, 빈 구간 5 B(1 B 다섯, 모두 원본 0·기호 없음), 2 B 이상 빈 구간 0, 겹침 `tty_pty` 4 B 만. 새 범위는 `fpsp` [0x40b30ec, 0x40b3110).
- 어느 하나라도 다르면 멈추고 원인을 찾습니다.

### 781.5 문서·782 와의 관계
- 782 전까지 `m7_m68k_link.py` 는 새 M4 상태표와 옛 `CHECK777`·`M5DIR` 을 섞어 읽습니다. 782 에서 두 상수를 781 기록·`m4p779/m5compare` 로 바꿉니다.

`06_reconstruction/m68k-data-status.tsv`(새 coverage 출력), 기록 `09_validation/reconstruction/m4-m68k-p781-{check,selftest,coverage,rd}-20261109.json`, `06_reconstruction/evidence/m68k-data.md` 에 계획 781 절, 계획서 결과 절. 07·상태표는 바꾸지 않습니다. 커밋하지 않습니다.

### 781.6 codex 검토 판정표(작업 `ka83wyfre`)
내가 틀렸던 것(먼저): ① `pins` 가 spec 을 읽지 않는다는 것을 놓쳐, 도구 변경 범위를 `m5_records`·`coverage` 로만 적었습니다. ② `selftest` 의 양성 대조가 낡은 기록을 거르지 못하는 약점을 보지 못했습니다. ③ 옛 기록을 다시 보려면 옛 도구만이 아니라 옛 상태표도 필요하다는 것을 빠뜨렸습니다. ④ `check` 의 요약을 모든 항목에 같게 적었으나, 엄격한 검사는 단위에만 걸리고 R 은 `check_refresh` 로 더 적게 봅니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 781.1 의 줄 번호·동작·777 수치 | 도구를 처음부터 끝까지 열람(`:47`·`:353–372`·`:388–390`·`:420–422`·`:586`); 777 coverage 기록 python 출력(146·22511·41·`tty_pty` 4) | ✅ |
| 엄격한 검사는 단위에만, R 은 `check_refresh` | 열람 `cmd_check` 의 `if kind == 'unit'` 갈래와 `check_refresh`(`:249–256`) | ✅ 문구 보탬 |
| `cmd_pins` 는 spec 을 읽지 않음(`:379`) | 열람 `:379–381` | ✅ 반영 |
| CHECK 인수를 명령 줄 분기까지 | 열람 `__main__` 분기 | ✅ 반영 |
| 양성 대조가 기록 자신의 해시를 넘김(`:589`) | 열람 `:588–589` | ✅ 반영(실제 해시로) |
| `_log/04.out`·고정 단위 이름·대조 객체·기준 객체 해시 통과 | 순서·이름을 그대로 두므로 같음; 해시는 실행 때 `check`·`selftest` 가 단정 | ⚖️ 실행으로 확인 |
| `deps_sha256` 은 목록 해시, 내용은 새 스테이지 manifest 와 비교 → 통과 | 열람 `check_deps`(`:166–190`) | ✅ (통과는 실행으로) |
| 예측 147·38/94/2/13·22547·빈 5·겹침 `tty_pty` | 내 python(도구 함수를 메모리에서 써서 계산) 같은 값, `fpsp` 범위 (67842284, 67842320) | ✅ |
| `fpsp` 의 inferred 배치가 `data_range` 통과 | 열람 `data_range`(차이만 봄) | ✅ |
| `m4p777-a1/out` 객체 → `Q781` 대응, 11 객체 파일째 같음 가능 | 이름 규칙 `expected_lines` 열람(`Q%dR__`·`Q%dD__`); 동일성은 실행으로 | ⚖️ 예측으로만 |
| 옛 도구 재생에는 모듈 경로·옛 상태표 필요 | 열람 `m4_records` 가 `STATUS` 상수를 읽음 | ✅ 반영 |
| 782 전까지 M7 도구가 섞인 입력을 읽음 | `m7_m68k_link.py:29–30` 열람(779 계획 때) | ✅ 반영 |

### 781.7 결과 (2026-11-09; 07·상태표 불변; 커밋 안 함)
- 도구 `m4_m68k_data.py`: 계획대로 세 곳만 바꿨습니다(629 → 635 줄). 바꾸기 전 판과 779 이전 상태표의 사본은 `scratch/p781/` 에 있고, 해시와 다시 돌리는 방법은 `m4-m68k-p781-rd-20261109.json` 에 있습니다.
- spec 781(SHA-256 `662da9ae…`): 777 과 다른 것은 `plan`·`base`·`pins`·`m5compare` 뿐입니다(python 비교). `m5compare` 가 없는 777 spec 으로 `pins` 를 돌리면 M5 고정 해시가 777 값 `94af9e6d…` 그대로입니다.
- run `m4p781-a1`(수집): 명령 29 개는 777 과 계획 번호 말고 같고, 준비된 `src/` 1047 파일은 779 스테이지와 같습니다.
  - `check` 는 16/16 OK, 7740 B 입니다.
  - `selftest` 는 39/7 이고 777 과 같은 결과입니다.
  - 낡은 기록 시험 둘은 모두 거부되었습니다.
- R·D 회귀: 예측과 같습니다(11 객체는 파일째 같고, 5 객체는 `_pv_*` 만 더해짐).
- `coverage`: 예측과 같습니다.
  - 147 범위이고, 덮은 바이트 22547 B(99.98 %)입니다.
  - 빈 구간은 1 B 다섯 곳뿐이고, 겹침은 `tty_pty` 4 B 입니다.
  - 새 범위는 `fpsp` 하나입니다.
  - 새 표 SHA-256 은 `588e907a…` 입니다.
- 증거: `06_reconstruction/evidence/m68k-data.md` 에 계획 781 절을 더했습니다.
- 다음: 계획 782 — `m7_m68k_link.py` 의 `M5DIR`(→ `m4p779/m5compare`)·`CHECK777`(→ 781 검사 기록)를 바꾸고, 받아들인 객체만으로 수집 run 링크를 만들어 원본과 비교합니다. 코딩 전에 계획과 codex 검토를 거칩니다.

## 782. M7 수집 링크 — 받아들인 객체만으로 (코딩 전 계획, 2026-11-09)
사용자 지시 "가장 안전하고 확실한 방법으로 다음 작업을 진행" 에 따라 779.4 의 마지막 남은 일인 782 를 합니다. 07·상태표·`__data` 표는 바꾸지 않습니다.

### 782.1 사실
- `m7_m68k_link.py` 는 M4 를 상태표에서(지금 779–780 객체), M5 를 상수 `M5DIR = '08_build/artifacts/m4p764/m5compare'`(`:29`)에서, R·D 를 상수 `CHECK777 = '…/m4-m68k-p777-check-20261108.json'`(`:30`)에서 읽습니다(`load_objects` `:104–150`). 지금 그대로면 새 M4 와 옛 M5·R·D 가 섞입니다.
- 새 근거: M5 = `08_build/artifacts/m4p779/m5compare`(205 기록; 계획 779), R·D = `09_validation/reconstruction/m4-m68k-p781-check-20261109.json`(16 항목, 계획 781; 결과 항목 구조가 777 기록과 같음).
- 계획 779 의 오프라인 확인(M5 상수만 메모리에서 바꿈, R·D 는 옛 기록)에서 `__common` 613 순서·주소·절 끝이 원본과 같았습니다. R·D 새 객체는 옛 객체에 `_pv_*` 만 더해졌으므로(781) 결과가 같을 것으로 예측합니다.
- `cmd_common` 은 `_bootp` 에 합성 언급을 더하는데(`:561–564`), 이제 `m68k_init` 이 `_bootp` 를 COMMON 으로 언급하므로 합성 언급은 같은 이름과 합쳐져 결과에 영향이 없습니다. 다만 기록의 가정 문구(`:433` "_bootp has no mention: synthetic declaration")는 사실과 달라집니다.
- 링크 꼴은 P2 K2F·P5 K4F 에서 확인한 것입니다: `ld -arch m68k -static -seg1addr 0x4000000 -e _start -segalign 4 -noseglinkedit -force_cpusubtype_ALL`, 그 뒤 `strip -x`. P2 `k2f` 와 P5 `k4f` 는 SHA-256 이 같습니다(`a8b63549…`).

### 782.2 도구 변경(최소)
- `M5DIR` → `08_build/artifacts/m4p779/m5compare`, `CHECK777` → 계획 781 검사 기록(이름은 `CHECK_RD` 로 바꾸고 주석에 이력). `load_objects` 의 단정(M4 76·M5 204·R 3·D 13, 해시 대조)은 그대로입니다.
- `cmd_common` 의 `_bootp` 가정 문구를 사실에 맞게 조건부로 적습니다(언급이 있으면 "mentioned by <객체>; the synthetic mention merges with it"). 머리 설명(`:11–12`)의 입력 설명, `load_objects` 의 `p777` 오류 문구(`:141–145`), 기록 이름표 `plan='778.8 P0 …'`(`:246`·`:425`)도 지금 입력에 맞게 고치고, 기록에 `inputs`(상태표·M5·R/D 기록 경로와 해시)를 더합니다. 계산은 바꾸지 않습니다.
- 바꾸기 전 도구는 `scratch/p782/m7_m68k_link.py.before782` 로 두고 해시를 기록합니다(778 기록은 이전 판으로 만든 것). 이전 결과를 다시 내려면 이전 판에 779 이전 상태표(`scratch/p781/m68k-m4-status.tsv.before779`)가 함께 필요하므로, 그 방법도 기록에 적습니다.
- 이 도구를 읽는 scratch 스크립트(`p2_build.py`·`p5_build.py` 등)는 다시 돌리지 않습니다(역사 기록).

### 782.3 오프라인 기록(실기 전)
- `spec`·`common` 을 새 기록 `09_validation/reconstruction/m7-m68k-p782-{spec,common}-20261109.json` 으로 돌립니다. 예측(python 으로 계산해 실행 전에 확인):
  - 객체 296(M4 76·M5 204·R 3·D 13). 문자열 바이트가 맞는 배치는 **10**(조합 210)입니다. 처음 32 라고 적은 것은 틀렸습니다. `fpsp` 가 이제 텍스트 순번 272 에 `__data` 를 가져 `ioconf` 후보를 268–272, `vers` 후보를 273–283 으로 자르기 때문입니다(python; 779 이전 상태표로는 32 가 다시 나옴). 손으로 단정하던 `ioconf` < `fpsp` < `vers` 가 바이트 제약으로 바뀐 것입니다.
  - 정의 없는 원본 `__common` 이름 0, 원본에 없는 COMMON 할당 0.
  - DP 최소 비용 0(180 배치 가운데 30). 그 배치에서 있는 그대로의 언급으로 613 순서·주소·절 끝이 같고, 재배치 7592 개가 모두 원본 바이트와 같습니다(상한 4; 상한 시험은 612 쌍 모두 0). 이 수치는 상수를 메모리에서 바꿔 미리 돌린 출력(`scratch/p782/common_pred.json`)입니다.

### 782.4 실기 링크(새 run `m7p782-a1`, 수집)
- 빌더 `scratch/p782/build.py`: P5 빌더의 배치 예측·재배치 자리 함수(`layout`·`predict`)만 가져오고, 객체 대체(`p5_build.py:29`)·`fpsp` 합성 객체(`:35–78`)·순서 P(`:94–121`)·`fpsp` 컴파일 명령은 쓰지 않습니다. 객체는 `load_objects` 의 296 개 그대로(대체·시험판 없음)이고, 기준 배치 표에 `fpsp` 의 `__data`(0x40b30ec)가 들어가야 합니다(비교기 `m7_m68k_compare.py:180`). 순서 R(`conf` 202·`uipc_proto` 34·`ioconf` 268·`counters` 132·`vers` 283, 그 밖은 하나뿐인 위치; `ioconf` < `fpsp` < `vers` 단정). 예측 배치가 모든 원본 주소와 같고 예측 외부 기호 3809 개가 원본 값과 같아야 명령 파일을 씁니다.
- 명령: `RUN /bin/ld … -o stage/mach_kernel.sys <296 객체>`, `RUN /bin/strip -x -o stage/mach_kernel stage/mach_kernel.sys`, `EXPECT mach_kernel.sys`, `EXPECT mach_kernel`. 이 꼴은 P2·P5 미수집 run 에서 종료 0 이었으므로 수집 run 으로 합니다.
- 판정(`m7_m68k_compare.py`, 층 B–F; 778.16 (3) 와 같은 기준):
  - strip 한 `mach_kernel` 은 P5 `k4f` 와 파일째 같고(SHA-256 `a8b63549…`), 원본과는 이미 알던 텍스트 6 B(`nfs_client`·`swapfs`)만 다릅니다. 크기 832196 B.
  - 층 B 차이 0, C 는 3809 기호·문자열표가 원본과 같음, D 는 위 6 B 뿐, E 같음.
  - `.sys` 는 외부 기호가 원본과 같고, 지역·STABS 수는 기록만 합니다.
- 어긋나면 멈추고 원인을 찾습니다.

### 782.5 문서·한계
- 기록 `09_validation/reconstruction/m7-m68k-p782-link-20261109.json`: 입력 목록과 해시(상태표·M5·R/D 기록·L1), 링크 기록, 빌더·링크 도구·비교기 해시(비교기는 `World()` 로 지금 상수를 읽음, `:103`), run 수집 기록, 비교 결과 둘(`.sys`·strip), P5 기준 해시. 계획서 결과 절. 07·상태표·`__data` 표는 바꾸지 않습니다.
- 한계: 링크 옵션은 바이트와 맞는 후보이며 원래 빌드 명령의 증거가 아닙니다. 남은 텍스트 6 B(`nfs_client`·`swapfs`)는 M5 의 미해결 차이입니다. QEMU 부팅(M8)은 범위 밖입니다. 커밋하지 않습니다.

### 782.6 codex 검토 판정표(작업 `kl243c9ms`)
내가 틀렸던 것(먼저): ① 문자열 바이트가 맞는 배치를 32 라고 예측했습니다(실제 10; `fpsp` 의 `__data` 가 후보를 자름). ② P5 빌더를 "그대로" 쓴다고 적었으나 객체 대체·합성 `fpsp`·순서 P 는 빼야 합니다. ③ 도구의 낡은 설명·이름표를 `_bootp` 문구 하나로만 보았습니다. ④ 이전 결과를 다시 내려면 옛 상태표도 필요하다는 것을 빠뜨렸습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 문자열 배치 210 조합 중 10 | 내 python(`cmd_spec`, 상수 메모리 변경): `cstring combos 210 byte-identical 10` | ✅ 내 오류 정정 |
| 이유는 `fpsp` `__data` 가 `ioconf` 268–272·`vers` 273–283 으로 자름 | `common_pred` 의 `dp_best_positions` `D:ioconf` [268..272]; 텍스트 순번 272 = `fpsp`(778.17 표) | ✅ |
| `undeclared` 0, DP 최소 0(30/180), 상한 4 에서 613·7592 같음 | 내 `cmd_common` 출력과 같음 | ✅ |
| `joint_sizes` 는 정의 없는 이름 0 에서도 동작 | 같은 출력 `feasible True` | ✅ |
| `_bootp` 는 `m68k_init` 이 크기 300 으로 언급 | 계획 779 의 최종 기록 `defined_symbols` 에 `['_bootp','COMMON',300]` | ✅ |
| 781 검사 기록 키가 777 과 같음 | 열람한 `load_objects`(`:140–146`)가 쓰는 키(`ok`·`l1`·`l1_sha256`·`object`·`obj_sha256`·`kind`·`name`)가 781 기록에 있음 — `cmd_spec`·`cmd_common` 이 그 기록으로 성공 | ✅ |
| P5 빌더의 대체(`:29`)·합성 `fpsp`(`:35–78`)·순서 P(`:94–121`) | P5 빌더 원문(이 세션에서 만든 것)과 같음 | ✅ 반영 |
| 비교기가 `ref_layout[k][sn]` 을 바로 씀(`:180`) | 계획 778.18 때 열람(`r = rec['ref_layout'][k][sn]`) | ✅ 반영 |
| 낡은 설명·이름표(`:11–12`·`:142–145`·`:246`·`:425`) | 열람: M5 `m4p764`, `p777` 오류 문구, `plan='778.8 P0 spec/common'` | ✅ 반영 |
| 옛 결과 재현에는 옛 상태표도 필요(`World()` 가 상태표를 읽음 `:202`) | 열람 `World.__init__` → `load_objects()` → `STATUS` | ✅ 반영 |
| 받아들인 296 객체 대 P5 집합: 177 파일째 같음, 118 은 `_pv_*` 추가, `fpsp` 는 지역 이름 | 재현 안 함(실제 링크 결과로 판정) | ⏭️ 문서에 넣지 않음 |
| P5 `k4f` strip 은 외부 3809·지역 0·STABS 0, 문자열표가 원본과 같음 | 778.19 기록(비교기 출력: `k4f` C 층 `physical_tuples_equal`·`string_table_equal` True) | ✅ |
| 수집 조건(`kr_run.py:326`·`:340–345`), 줄 6209 자, 입력 9292628 B | `kr_run.py` 는 778.16 때 열람; 길이·크기는 빌더가 다시 계산 | ⚖️ 빌더에서 확인 |

### 782.7 결과 (2026-11-09; 07·상태표·`__data` 표 불변; 커밋 안 함)
- 도구 `m7_m68k_link.py`: 계획대로 바꿨습니다(700 → 711 줄).
  - 입력 상수는 `M5DIR` → `m4p779/m5compare`, `CHECK777` → `CHECK_RD`(781 검사 기록)입니다.
  - 설명·오류 문구·기록 이름표를 고쳤고, `inputs()`(상태표·M5·R/D 기록의 해시)와 `_bootp` 가정의 조건부 문구를 더했습니다.
  - 이전 판 사본은 `scratch/p782/m7_m68k_link.py.before782` 입니다. `CHECK777` 를 쓰는 다른 파일은 없습니다(전수 grep).
- 오프라인 기록(`m7-m68k-p782-{spec,common}-20261109.json`): 미리 돌린 예측 출력과 이름표 말고 같습니다.
  - 객체 296, 문자열 바이트가 맞는 배치 10/210, 정의 없는 이름 0.
  - DP 최소 비용 0(30/180 배치), 상한 4 에서 613 순서·주소·절 끝과 재배치 7592 개가 같습니다.
  - 가정 문구는 "`_bootp` mentioned by M4:m68k_init" 입니다.
- 빌더 `scratch/p782/build.py`(P5 의 `layout`·`predict` 를 원문 그대로 씀): 모든 단정을 통과했습니다.
  - 예측 절 시작·끝은 모두 원본과 같고, `fpsp` `__data` 는 0x40b30ec 입니다.
  - 바뀔 재배치 자리는 0, 예측 외부 기호 3809 개는 원본 값과 같습니다.
  - 명령 줄은 6209 자, 입력은 9292628 B 입니다.
- 실기 run `m7p782-a1`(수집): 명령 2 개 모두 종료 0, stdout·stderr 빔. 준비된 `src/` 296 파일은 빌더 출력과 같습니다.
- 비교(`m7_m68k_compare.py`; 기록 `09_validation/reconstruction/m7-m68k-p782-link-20261109.json`):
  - strip 한 `mach_kernel`(832196 B)은 P5 `k4f` 와 **파일째 같고**(SHA-256 `a8b63549…`), 원본과는 텍스트 6 B(`nfs_client` 0x40262d8·0x40262da·0x40262df, `swapfs` 0x4032b2a·0x4032b37·0x4032b3b; 파일 오프셋 156376·156378·156383·207658·207671·207675)만 다릅니다.
  - 층 B(헤더·적재 명령·세그먼트 flags 0)·C(3809 기호·문자열표)·E(진입점)는 원본과 같습니다. D 는 입력 기여 454 개 가운데 452 개가 같고, 정렬 채움 5 B 가 원본과 같습니다.
  - strip 전 `mach_kernel.sys` 는 외부 3809(값 차이 0)·지역 2266·STABS 229318 입니다.
- 뜻: 계획 778 에서 scratch 시험 객체와 진단용 채움으로 얻은 결과를, 이제 받아들인 07 객체만으로 수집 run 에서 같은 바이트로 얻습니다. 남은 차이는 M5 `nfs_client`·`swapfs` 의 텍스트 각 3 B 입니다(계획 778.2 이전부터 아는 차이). 링크 옵션은 바이트와 맞는 후보이며 원래 빌드 명령의 증거가 아닙니다.
- 다음 후보: `nfs_client`·`swapfs` 의 텍스트 6 B, 또는 M8(QEMU 부팅, `--snapshot` 먼저). 사용자 결정입니다.

## 783. 남은 텍스트 6 B — `swapfs_unlock` 진단(새 근거) / `nfs_attrcache_va` 는 보류 (코딩 전 계획, 2026-11-09)
사용자 선택 "1"(782 뒤 결정 요청: `nfs_client`·`swapfs` 의 텍스트 6 B)에 따릅니다. 이 계획은 진단만 하며 07 은 바꾸지 않습니다. 맞는 꼴이 나오면 07 반영(오버레이)은 따로 계획하고 사용자 결정을 받습니다.

### 783.1 사실(원본·우리 수집 링크 `m7p782-a1` 를 capstone 으로 디스어셈블; python)
- `swapfs_unlock`(원본 0x4032b16–0x4032b4c, 우리 `swapfs.c:330–340`):
  - 원본 `move.b $75(a0),d0; move.b d0,d1; andi.b #-2,d1`(낱말 `0201 fffe`)`; move.b d1,$75(a0); btst #1,d0; beq; andi.b #$fc,d1`(`0201 00fc`)`; move.b d1,$75(a0); pea $75(a0); bsr wakeup`.
  - 우리: 첫 마스크 `0201 00fe`(즉시값 254), 둘째 마스크 `0200 00fc` 를 **d0**(옛 값)에 적용하고 `move.b d0,$75(a0)`.
  - 다른 바이트는 0x4032b2a(첫 마스크 즉시값의 위 바이트 `ff`/`00`), 0x4032b37(둘째 `andi` 의 레지스터), 0x4032b3b(저장의 레지스터) 셋입니다.
- §490–494 의 L1 은 세 바이트 차이를 모두 잡았습니다(`l1-m5p493-s1-ALLX.json`). 그러나 명령 단위 설명은 숫자를 가린 목록으로 했으므로(§490·§493 의 "숫자를 가린" 비교) 첫 즉시값의 `fffe`/`00fe` 차이를 설명에 넣지 못했습니다(§493.2 "레지스터 하나"). 바이트 연산에서 즉시값 낱말의 위 바이트는 쓰이지 않지만, 컴파일러가 상수를 부호 있는 값(-2)으로 가졌는지 254 로 가졌는지를 드러냅니다. 원본은 -2 입니다.
- §493 의 남은 객체를 바이트로 다시 보면(python, `08_build/runs/m5p493-s{1,2,3}/out/P493__*.o`): BU10(`char`)·BU12(`u_short`)·BU13(`unsigned`)는 첫 마스크 `00fe`, BU5(`int`)·BU11(`short`)·BU14(`long`)는 `fffe` 입니다. BU5·BU11·BU14 는 둘째 마스크를 원본처럼 d1 에 걸고 저장도 d1 이어서, 0 확장 한 줄(`clrl`/`clrw`)을 빼면 이 함수가 원본과 같은 열입니다(BU5 의 창: `1028 0075 1200 0201 fffe 1141 0075 0800 0001 6712 0201 00fc 1141 0075`).
- 해석(가설; 대상 컴파일러 결과와 맞음): 첫 마스크가 int 의 의미(-2)로 남으면 컴파일러가 두 마스크를 하나로 합치지 않아, 둘째 마스크가 첫 저장값(d1)에 걸립니다. `u_char` 연산으로 좁혀지면 254 가 되고 두 마스크가 합쳐져 d0 에 걸립니다. 그러므로 찾을 꼴은 "0 확장 없이 첫 저장만 부호 있는(또는 int) 의미로 하는 꼴" 입니다. 즉시값 위 바이트가 원본 컴파일러의 내부 표현을 증명하지는 않습니다.
- 둘째 마스크 0xfc 는 d1(이미 bit0 이 0) 에 `~SD_WANTED`(0xfd)를 적용한 것을 컴파일러가 0 인 비트를 알고 줄인 값과도, `~(SD_LOCKED|SD_WANTED)` 와도 같습니다(바이트로는 가를 수 없음).
- `sd_flags` 는 `swapfs.c:61` 의 작성 구조체 필드 `u_char`, `SD_LOCKED` 0x1·`SD_WANTED` 0x2(`:64–65`) 입니다. 이 필드를 쓰는 다른 함수(`swapfs_lock` 등)는 지금 원본과 바이트가 같습니다.
- `swapfs.c` 는 x86 과 함께 쓰는 07 본 파일이므로, 07 반영은 m68k 오버레이(07 본 파일 + 표지 줄; `#if m68k` 꼴)로만 합니다. 그래서 이번 진단은 x86 바이트에 묶이지 않습니다.
- `nfs_attrcache_va`: 원본 d0, 우리 d1(같은 `moveq #$7c; add.l $2e(a2); move.l dN,-(a7)`, 구조체 대입의 `bcopy` 대상 주소). §465·§475·§477·§489 에서 열 가지 넘는 꼴이 모두 실패했고, 원본 전체에서 같은 꼴 35 함수 가운데 d0 은 이 함수 하나뿐입니다(§477). 새 근거가 없으므로 이 계획에서는 시험하지 않고 보류로 둡니다.

### 783.2 진단(도구 `m5_m68k_srcvar.py`; 바탕 `08_build/runs/tools/m4p779-base-stage`; 대조 K = 07 본 파일, `control_ref` = 받아들인 M5 객체 `08_build/runs/m3p779-cc1/out/O779__L2_384__swapfs.o`(이름은 실행 전에 확인))
`swapfs.c:330–340` 의 함수만 바꾸는 변형(나머지 줄 그대로; 대조 둘은 이전 시험의 재현):
- C1(대조, §493 BU10 재현): `char flags = sd->sd_flags;`
- C2(대조, §492 BU3 재현): 임시 변수 없이 `sd->sd_flags &= ~SD_LOCKED; if (sd->sd_flags & SD_WANTED) { sd->sd_flags &= ~SD_WANTED; wakeup(...); }`
- S1: 첫 저장만 `*(char *)&sd->sd_flags = flags & ~SD_LOCKED;`(나머지 K)
- S2: 첫 저장만 `*(signed char *)&sd->sd_flags = flags & ~SD_LOCKED;`
- S3: 첫 저장만 `sd->sd_flags = (char)(flags & ~SD_LOCKED);`
- S4: 지역 보기 `char *fp = (char *)&sd->sd_flags; char flags = *fp; *fp = flags & ~SD_LOCKED; if (flags & SD_WANTED) { *fp &= ~(SD_LOCKED|SD_WANTED); wakeup((caddr_t)fp); }`
- S5: S1 + 둘째 문장 `sd->sd_flags &= ~SD_WANTED;`
- S6: `signed char flags = sd->sd_flags;` + 둘째 `sd->sd_flags = flags & ~(SD_LOCKED|SD_WANTED);`
- F1: 필드만 `char sd_flags`(`:61`), 함수는 K(다른 함수가 바뀌는지 보는 대조)
- F2: F1 + `char flags` + 둘째 `sd->sd_flags &= ~SD_WANTED;`
판정(python, 미리 정함; 도구의 요약 `match` 는 `OBJECT_MATCH` 만 세므로 쓰지 않음):
- 모든 컴파일 종료 0, stderr 는 K 와 같음. K 는 `control_ref`(`O779__L2_384__swapfs.o`, SHA-256 `945b7eaf…`)와 `canon`·기호(COMMON·미정의·외부 정의)가 같음.
- 맞는 꼴: 각 변형의 L1 기록에서 `__TEXT,__text` 의 `byte_differences`·`refs_differ`·`refs_unverified` 가 모두 0, 그 밖의 사유는 K 와 같음(`__TEXT,__const` 미배정·`__DATA,__bss` 추정은 원래 한계 그대로), COMMON·미정의·외부 정의 기호가 K 와 같음. 원본 [0x4032b16, 0x4032b4c) 의 낱말(재배치 자리는 원본 값)과 바이트가 같은지를 python 으로 따로 봅니다.
- 각 변형의 `swapfs_unlock` 원시 바이트와 명령(디스어셈블러는 `fffe` 도 `#$fe` 로 보이므로 바이트를 함께 적음)을 원본과 나란히 기록합니다.
- 맞는 꼴이 여럿이면 모두 기록하고, 07 반영 꼴(오버레이)은 사용자에게 묻습니다. 없으면 기록만 합니다.
- 실행 순서(이 도구는 수집된 `out/` 만 읽음): `stage` → `cmd` → 새 run prepare/launch/wait → 상태·stderr 를 직접 확인 → collect → `compare` → python 판정. 한 명령이라도 실패하면 수집하지 않고, 실패한 변형을 빼고 새 ID 로 다시 돌립니다.

### 783.3 하지 않는 것·한계
07·상태표 불변. 바이트 일치는 원본 소스의 증명이 아닙니다(형 이름·문장 꼴은 바이트가 정하지 못하는 부분이 남음). `nfs_attrcache_va` 는 새 근거가 생기기 전까지 보류합니다. 커밋하지 않습니다.

#### 783.4 codex 검토 판정표(작업 `kx2x6bf7z`)
내가 틀렸던 것(먼저): ① §493 이 즉시값 차이를 "보지 못했다" 고 적었으나 L1 은 세 바이트를 모두 잡았고, 놓친 것은 명령 설명입니다. ② BU10 의 즉시값을 "모른다" 고 적었으나 남은 객체로 바로 볼 수 있었습니다(`00fe`). ③ 도구의 요약 `match` 를 판정에 쓸 수 있다고 보았으나 `OBJECT_MATCH` 만 셉니다. ④ 실행 순서를 정하지 않았고, 이 도구는 수집한 run 만 읽습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 세 바이트 0x4032b2a·0x4032b37·0x4032b3b, 명령 열 | 내 capstone 출력(원본·`m7p782-a1`)과 같음 | ✅ |
| 디스어셈블러가 `fffe` 도 `#$fe` 로 보임 | 내 출력에서 두 쪽 모두 `andi.b #$fe` | ✅ 바이트 함께 기록 |
| L1 은 세 차이를 이미 잡음, 숫자 가림은 §490·§493 의 설명 | 계획 493 원문 열람("숫자를 가린") | ✅ 문구 정정 |
| BU10 `00fe`, BU11·BU14 `fffe`, BU12·BU13 `00fe`, 넓은 형은 d1 + `clr` | python: 남은 P493 객체의 창 바이트(BU5·BU11·BU14 `0201fffe`… `020100fc 11410075`) | ✅ 반영 |
| 상수 부호는 가설(내부 표현 증명 아님) | 논리 맞음 | ✅ 문구 반영 |
| U1 = BU10, U6 = BU3(§492 spec) | BU10 은 위 바이트로 확인; BU3 은 spec 원문을 열지 않음 | ⚖️ 둘 다 대조(C1·C2)로만 둠 |
| 지역 `signed char *` 보기 꼴 제안 | 위 해석과 맞음 | ✅ S1·S2·S4 에 반영 |
| stage 1047 항목·컴파일 줄 `cc.cmd:121`·`control_ref` 해시 | `control_ref` 이름·해시는 내가 `ls`·`sha256sum` 으로 확인; 나머지는 도구가 실행 때 단정 | ⚖️ |
| 요약 `match` 는 `OBJECT_MATCH` 만, `canon` 은 절 전체 | 도구 설명(`m5_m68k_srcvar.py:23–29`)과 `:175–178` 열람 | ✅ 판정을 L1 기록으로 |
| 이 도구는 `out/` 만 읽음 → 수집 뒤 compare | 도구 설명의 compare 와 `:146` 근처(`run_files`) — 줄은 실행 전 확인 | ⚖️ 순서 반영, 실행 때 확인 |
| `nfs_attrcache_va` 보류가 맞음(35 함수 중 d0 하나 재현) | §477 기록과 같음 | ✅ |

### 783.5 결과 (실기 run `m5p783-s1` 수집, 2026-11-09; 07·상태표 불변; 기록 `09_validation/reconstruction/m5-m68k-swapfs-variants-p783-20261109.json`, L1 `08_build/artifacts/m5p783/l1-m5p783-s1-*.json`)
- 운영: 11 명령 모두 종료 0, stderr 0 B. 준비된 `src/` 1058 파일은 stage 와 같습니다. K 는 `control_ref` 와 같습니다(`control_equals_ref` true).
- **F2 가 맞습니다.** F2 는 필드 `char sd_flags`(`swapfs.c:61`), `char flags = sd->sd_flags;`, 둘째 문장 `sd->sd_flags &= ~SD_WANTED;` 입니다.
  - L1 `__TEXT,__text` 3908 B 의 바이트 차이·재배치 차이·미검증 재배치가 모두 0 이고, 사유는 `__TEXT,__const: unverified`·`__DATA,__bss: unverified` 뿐입니다(K 에서 `__text: fail` 이 빠짐).
  - 외부·COMMON·미정의 기호는 K 와 같습니다.
  - `swapfs_unlock` 의 바이트는 원본 [0x4032b16, 0x4032b4c) 와 같고, 다른 것은 링크 전의 `bsr` 변위뿐입니다(python).
- 나머지 변형(L1 텍스트 차이 바이트 수):
  - C1·C2·S1·S2·S3·S5·S6 은 K 와 같은 묶음입니다(3 B). 포인터 형 변환·`signed char` 임시 변수·형 변환 꼴은 컴파일러가 `u_char` 저장으로 좁혀 효과가 없었습니다.
  - S4 는 텍스트가 3904 B 로 4 B 짧아져 뒤가 밀리고 2054 B 가 다릅니다.
  - F1(필드만 `char`)은 1 B 가 다릅니다. 둘째 마스크와 저장은 원본처럼 d1 이 되었고, 남은 것은 0x4032b2a 의 첫 즉시값(`00fe`)입니다(python).
- 뜻: 필드를 부호 있는 바이트로 하면 둘째 마스크가 첫 저장값(d1)에 걸리고(F1), `char flags` 와 `~SD_WANTED` 만 지우는 둘째 문장을 함께 두면 첫 즉시값도 원본처럼 `fffe` 가 됩니다(F2). 바이트 일치이며, 원본이 이 형과 문장이었다는 증명은 아닙니다(같은 바이트를 내는 다른 꼴을 배제하지 않음).
- 07 반영(사용자 결정 필요): `swapfs.c` 는 x86 과 함께 쓰는 07 본 파일입니다. 오버레이는 줄을 끼워 넣기만 할 수 있으므로(`check_derived`), m68k 오버레이 `v183.34/m68k/src/bsd/swapfs/swapfs.c` 에 `#if m68k … #else … #endif` 로 세 줄의 m68k 꼴을 두는 방식(x86 불변)이 가장 안전합니다. 다른 길은 07 본 파일을 바꾸고 x86 이 원본과 같은지 다시 확인하는 것이지만, 지금은 x86 쪽 시험을 하지 않았습니다.
- `nfs_attrcache_va` 는 보류 그대로입니다(783.1).

## 784. D179 — `swapfs` m68k 오버레이(F2), M5 재수락·회귀, M7 수집 링크 다시 (코딩 전 계획, 2026-11-09)
사용자 결정 D179("가": m68k 오버레이)에 따릅니다. 07 본 파일 `src/bsd/swapfs/swapfs.c` 와 x86 은 바꾸지 않습니다.

### 784.1 사실
- F2(783.5)는 `swapfs.c` 의 세 줄을 바꾼 꼴입니다: `:61` `u_char\t\tsd_flags;` → `char\t\tsd_flags;`, `:333` `u_char flags = sd->sd_flags;` → `char flags = …`, `:337` `sd->sd_flags &= ~(SD_LOCKED|SD_WANTED);\t/* plan 494 (D102) */` → `sd->sd_flags &= ~SD_WANTED;`.
- 오버레이 `.c` 는 07 본 파일 + 표지 줄만 끼워 넣을 수 있고(`stage_m68k.py` `check_derived`), 선례는 `init_sysent.c`(계획 774)의 `#if !m68k` / 원래 줄 / `#else` / m68k 줄 / `#endif`(각 표지 줄) 꼴입니다.
- `swapfs.c` 는 `__LINE__`·`assert` 를 직접 쓰지 않습니다(grep 0; 포함하는 머리의 단정 매크로는 `MACH_ASSERT` 0 으로 꺼짐). 줄을 끼우면 디버그 정보(줄 번호, 그리고 783 의 변형 파일과 비교할 때는 `N_SO` 의 파일 이름)만 다르고 컴파일된 내용은 같을 것으로 예측합니다.
- `swapfs.c` 를 포함하는 객체는 `M5:swapfs` 하나입니다(P3a 의존 목록). `EXCEPTS[779]` 에 `x86-swapfs` 가 이미 있습니다(시험 run 기준과 `canon` 이 다름; `differ_unexpected` 에서 빠짐, `stage_m68k.py:799`).

### 784.2 07 변경
- 새 오버레이 `07_kernel/v183.34/m68k/src/bsd/swapfs/swapfs.c` = 07 본 파일에서 세 곳마다 `#if\t!m68k\t/* plan 784 (m68k) */` 를 원래 줄 앞에, `#else\t/* plan 784 (m68k) */`·m68k 줄(표지 주석)·`#endif\t/* plan 784 (m68k) */` 를 원래 줄 뒤에 둡니다(표지 줄 12; 원래 줄은 그대로). `:337` 의 m68k 줄에는 D179 를 적습니다.
- 등록: `OVLFROM['src/bsd/swapfs/swapfs.c'] = 784`, `MARKERS['plan 784 (m68k)'] = {'src/bsd/swapfs/swapfs.c': 12}`, `M4FILES[784] = list(M4FILES[779])`, `EXCEPTS[784] = dict(EXCEPTS[779])`(`x86-swapfs` 의 설명에 계획 784 의 오버레이 꼴을 더함; `EXCEPTS` 는 시험 run 기준과의 `canon` 차이 주석일 뿐이고, 판정은 아래 F2·L1 관문이 함), 머리 설명의 계획 목록.
- 문서: `PROVENANCE.tsv` 새 행(7 열; 출처 = 작성 07 본 파일(해시) + 표지 줄, D024·D179, 프로젝트 작성; NeXTMach 출처를 쓰지 않음), `MODIFICATIONS.md` 한 행, 새 증거 `06_reconstruction/evidence/m68k-swapfs.md`·`m68k-swapfs.diff`(07 본 파일 → 오버레이), D179(적음).

### 784.3 관문과 판정(미리 정함)
1. 스테이지 `m4p784-base-stage`: 779 스테이지와의 차이가 `src/bsd/swapfs/swapfs.c`(출처 07 본 파일 → 오버레이)와 manifest 뿐. 표지 검사 통과.
2. 전처리 동등성: 오버레이를 m68k 조건으로 전처리한 글이 783 의 F2 변형 파일과 줄 번호 말고 같음(python 으로 `#if` 를 풀어 비교).
3. x86: `--plan 784 x86gate` 7/7 같음, `m4-x86-inputs-p784-20261109.json` `ok`, 07 본 파일 `swapfs.c` 해시 불변.
4. M5 205(새 run, 수집; `--plan 784 cmd`): 모두 종료 0, stderr 는 `m3p779-cc1` 과 같음. `swapfs` 말고 204 객체는 `m3p779-cc1` 의 같은 객체와 파일째 같음. `swapfs` 는 783 의 `P783__F2.o` 와 `m7_m68k_objdiff` 로 "허용"(`canon`·헤더·절 목록·STABS 를 뺀 모든 기호가 같음; 더해진 이름 0)이고, 파일째 같음은 요구하지 않습니다(디버그 정보가 다름). L1 `__TEXT,__text` 차이·재배치 차이·미검증 0(사유는 `__const`·`__bss` 미검증만).
5. `--plan 784 compare`(기록 `m3-m68k-p784-compare-20261109.json`, WORKDIR `08_build/artifacts/m4p784/m5compare`): 요약이 779 와 같음(`differ_unexpected`·`lost` 빔). M4 는 바뀐 머리가 없으므로 다시 만들지 않습니다(상태표 불변).
6. M7: `m7_m68k_link.py` 의 `M5DIR` → `08_build/artifacts/m4p784/m5compare`(이전 판 사본 보관). `spec`·`common` 새 기록(예측: 782 와 같은 수치). 링크 빌더(782 빌더의 복사본; run ID 와 출력 경로 `OUT`·`CMD`·`REC`·이름표를 새로) → 수집 run → 비교(strip 한 파일과 `.sys` 둘 다, 782.5 와 같은 입력·도구 해시 기록): strip 한 `mach_kernel` 은 원본과 `nfs_client` 의 3 B(0x40262d8·0x40262da·0x40262df)만 다름, 크기 832196, 층 B·C·E 같음.
- 어느 관문이든 어긋나면 멈추고 원인을 찾습니다.

### 784.4 하지 않는 것·한계
`nfs_attrcache_va`(3 B)는 보류 그대로입니다. `__data` 지표(781)는 `swapfs` 의 `__data` 가 바뀌지 않으므로 다시 만들지 않고, 그 M5 고정 해시가 보관된 `m4p779/m5compare` 를 가리킨다는 것을 결과 절에 적습니다(그 디렉터리는 고치지 않음). 수락 뒤 M5 집계는 코드 검증 207/208(99.52 %)이고 코드 차이가 남은 객체는 `nfs_client` 하나입니다. `swapfs` 는 `__const`·`__bss` 미검증이므로 `OBJECT_MATCH` 로 올리지 않습니다. 바이트 일치는 원본 소스의 증명이 아닙니다. 커밋하지 않습니다.

#### 784.5 codex 검토 판정표(작업 `kwylxtcuu`)
내가 틀렸던 것(먼저): ① 782 빌더는 run ID 만 바꾸면 된다고 적었으나 출력 경로(`OUT`·`CMD`·`REC`)도 고정되어 있어 새로 정해야 합니다(`scratch/p782/build.py:8–12`). ② "STABS 줄 번호만 바뀐다" 는 너무 좁았습니다. 783 변형과 비교하면 `N_SO` 파일 이름도 다릅니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 세 줄의 원문(`:61`·`:333`·`:337`)과 F2 재현 | 783 spec 의 바꿈 쌍이 07 본 파일에서 정확히 한 번씩 나옴을 spec 작성 때 단정함 | ✅ |
| 오버레이 꼴이 실제 `check_derived` 를 통과(표지 12) | 구현 때 `stage` 가 같은 검사를 함 | ⚖️ 실행으로 확인 |
| `m68k` 가 정의되어 `#else` 쪽이 쓰임(774 객체의 139·151 항목) | 계획 777 에서 `init_sysent` 가 OBJECT_MATCH(그 항목이 m68k 쪽일 때만 원본과 같음) | ✅ |
| `N_SO` 이름이 다름, 단정 매크로는 `MACH_ASSERT` 0 | 논리 맞음(783 변형 파일 이름 `p783_F2.c`) | ✅ 문구 정정 |
| 205 명령이 779 와 접두어 말고 같음 | 구현 때 python 으로 다시 비교 | ⚖️ 실행으로 확인 |
| `swapfs` 판정에 `objdiff`(헤더·절·모든 비 STABS 기호) 추가 | 도구가 이미 있음(779) | ✅ 반영 |
| `EXCEPTS` 는 주석만, 설명 보강 | `stage_m68k.py:799` 열람(779 때) | ✅ 반영 |
| 빌더 출력 경로 고정(`build.py:8`) | 열람 `:8–12` | ✅ 내 오류 정정 |
| M7 예측: 원본과 `nfs_client` 3 B, 832196 B | 783.5 의 F2 결과와 782 결과에서 따라 나옴 | ✅ (실행으로 판정) |
| PROVENANCE 7 열·작성 출처, 781 고정 해시는 보관 디렉터리 그대로 | 열람 형식(779 때) | ✅ 반영 |
| M5 집계 207/208(99.5 %) | python `207/208*100 = 99.52` | ✅ 반영 |

### 784.6 결과 (2026-11-09; 커밋 안 함)
- 07: 새 오버레이 `07_kernel/v183.34/m68k/src/bsd/swapfs/swapfs.c`(07 본 파일 812 줄 + 표지 줄 12 = 824 줄). 표지를 빼면 07 본 파일과 같고, m68k 쪽 줄만 고르면 783 의 F2 변형 파일과 같습니다(python, 표지 주석 제외). 등록은 `OVLFROM`·`MARKERS['plan 784 (m68k)']`(12)·`M4FILES[784]`·`EXCEPTS[784]` 입니다. 07 본 파일은 그대로입니다(`git diff` 없음).
- 스테이지 `m4p784-base-stage`: 779 스테이지와의 차이는 `src/bsd/swapfs/swapfs.c` 하나입니다. x86 관문 7/7 같음, `m4-x86-inputs-p784-20261109.json` `ok`. M5 명령 205 줄은 779 와 계획 번호 말고 같습니다.
- M5 205 run `m3p784-cc1`(수집): 204 객체는 `m3p779-cc1` 과 파일째 같고, stderr 205 개가 모두 같습니다.
  - `swapfs` 는 F2 진단 객체와 `canon`·헤더·절·비 STABS 기호가 같습니다(`m7_m68k_objdiff`, STABS 1447 = 1447).
  - L1 `__TEXT,__text` 차이 0·재배치 차이 0·미검증 0 이고, 사유는 `__const`·`__bss` 미검증뿐입니다.
  - `--plan 784 compare` 요약은 779 와 같습니다.
- M5 집계: 코드 검증 207/208(99.52 %)이고, 코드 차이가 남은 객체는 `nfs_client` 하나입니다. `swapfs` 는 `__const`·`__bss` 미검증이라 OBJECT_MATCH 로 올리지 않습니다.
- M7:
  - `m7_m68k_link.py` 의 `M5DIR` 를 `m4p784/m5compare` 로 바꿨습니다(이전 판 사본 `scratch/p784/m7_m68k_link.py.before784`).
  - `spec`·`common` 새 기록은 782 와 같은 수치입니다(문자열 배치 10/210, 정의 없는 이름 0, DP 최소 0(30/180), 상한 4 에서 613·7592 같음).
  - 빌더 `scratch/p784/build.py`(782 빌더 + 새 경로)의 단정을 모두 통과했습니다.
  - 수집 run `m7p784-a1` 은 명령 2 개 모두 종료 0 입니다.
- **strip 한 `mach_kernel`(832196 B)은 원본과 3 B 만 다릅니다**(모두 `nfs_client`: 0x40262d8·0x40262da·0x40262df). 층 B·C(3809 기호·문자열표)·E 는 원본과 같고, D 는 입력 기여 454 개 가운데 453 개가 같습니다. 기록은 `09_validation/reconstruction/m7-m68k-p784-link-20261109.json` 입니다.
- 문서: `PROVENANCE.tsv` 새 행(1263 행, 7 열), `MODIFICATIONS.md` 한 행, 새 증거 `06_reconstruction/evidence/m68k-swapfs.md`·`m68k-swapfs.diff`, D179.
- `__data` 지표(781)는 그대로입니다(`swapfs` 의 `__data` 는 바뀌지 않음; 그 M5 고정 해시는 보관된 `m4p779/m5compare` 를 가리킴).
- 남은 것: `nfs_attrcache_va` 의 레지스터 하나(d0/d1, 3 B)입니다. 새 근거가 생기기 전까지 보류합니다.

## 785. `nfs_attrcache_va` 다시 조사 — 컴파일 옵션 진단 (코딩 전 계획, 2026-11-09; 07·상태표 불변)
사용자 선택 "2"(784 뒤: `nfs_client` 다시 조사)에 따릅니다. 진단만 하며 07 과 빌드 규칙은 바꾸지 않습니다.

### 785.1 사실
- 남은 차이(784.6): `nfs_attrcache_va` 의 `moveq #$7c,dN; add.l $2e(a2),dN; move.l dN,-(a7)`(구조체 대입 `vtor(vp)->r_attr = *va;` 의 `bcopy` 대상 주소)에서 원본 dN = d0, 우리 d1. 그 밖의 바이트는 같습니다(0x40262d8·0x40262da·0x40262df 의 3 B).
- 같은 객체의 이웃 `nfs_attrcache`(원본 0x4026266–0x40262ac)는 같은 식(`vtor(vp)->r_attr` 의 주소, `nattr_to_vattr` 의 셋째 인자)을 원본에서도 d1 에 둡니다. 원본 전체에서 같은 꼴이 나오는 이름 있는 구간 35 개 가운데 d0 은 `nfs_attrcache_va` 하나뿐입니다(§477; 이름 없는 정적 함수는 앞 이름에 묶여 셈).
- 소스 꼴은 §465·§475·§477·§489 에서 열 가지 넘게 시험했지만 레지스터를 바꾸지 못했습니다(명시 `bcopy`·선언 꼴·`register`·지역 변수·조건 나누기·매개변수 순서·`void`·문장 식·내장 함수).
- 지금 M5 컴파일 줄은 `-g -O2`(계획 429 규칙: x86 의 `-g -O3 -fno-omit-frame-pointer` 에서 바꿈)입니다(`m3p784-cc1/run.cmd:145`). 원본 커널 기호표에는 STABS 가 없어(strip) 원본 빌드가 `-g` 를 썼는지는 바이트로 정해지지 않습니다. 컴파일 옵션을 바꾼 `nfs_client` 시험 기록은 없습니다(계획서 grep).
- 가설(시험 대상, 약함): `-g` 나 최적화 단계가 이 함수의 레지스터 배정을 바꿀 수 있습니다. 공개 GCC 2.7.2.3 사본(`scratch/p725/gccsrc`; NeXT 판과 다를 수 있음)에서는 local-alloc 이 `NOTE` 를 세지 않으므로(`local-alloc.c:1143`) `-g` 쪽 가설은 강하지 않습니다. m68k 에 `REG_ALLOC_ORDER` 정의가 없어(grep 0) 낮은 번호부터 찾는데도 d1 이 되는 이유는 소스로 설명되지 않았고, 덤프로 어느 단계에서 정해지는지 보는 것이 가장 정보가 많습니다.

### 785.2 진단 run(새 ID, 미수집; 07 본 파일 그대로, 스테이지 `m4p784-base-stage`)
`m3p784-cc1/run.cmd:145` 의 `nfs_client` 줄을 그대로 쓰고 옵션만 바꾼 컴파일:
- G0: 그대로(`-g -O2`) — 대조, 받아들인 객체(`m3p784-cc1/out/O784__L2_142__nfs_client.o`)와 `canon`·기호가 같아야 함
- G1: `-g` 뺌(`-O2`)
- G2: `-g -O`
- G3: `-g -O2 -fno-omit-frame-pointer`
- G4: `-O`(둘 다 뺌·낮춤)
- G5: `-g -O3`
- G6: `-g -O2 -fno-expensive-optimizations`
- G7: `-g -O2 -fno-cse-follow-jumps`
- G8: `-g -O2 -fno-defer-pop`
- G9: §489 의 BP 소스 꼴(명시 `bcopy` + `void` 선언) + `-g -O2 -fno-defer-pop`(§489 의 BP 는 정리를 미뤄 1220 B 였음)
- R0: G0 과 같은 줄 + 덤프 `-dr -dj -ds -dc -dl -dg -dJ -df`(선례 `m4p728-d1`; `RUNIN stage/rtl0`). `.lreg`·`.greg` 로 대상 의사 레지스터가 어느 단계에서 d1 이 되는지 봅니다.
판정(python, 미리 정함):
- 각 객체를 L1(`l1_compare.py --place-from-image`)으로 원본과 비교합니다. 맞는 꼴은 `OBJECT_MATCH`(텍스트·재배치 차이 0, 사유 없음)이고, 외부·COMMON·미정의 기호가 G0 과 같아야 합니다.
- 옵션이 코드 위치를 옮길 수 있으므로, 각 객체에서 기호로 `nfs_attrcache_va` 를 찾아 그 안의 `moveq #$7c,dN` 열의 레지스터와 텍스트 크기를 적습니다(고정 주소로 보지 않음).
- G0 이 받아들인 객체와 `canon`·비 STABS 기호가 다르면 나머지를 해석하지 않고 멈춥니다.
- 맞는 꼴이 옵션 변경(예: `-g` 없음)이면, 그것이 다른 객체에도 같은 영향을 주는지(받아들인 296 객체가 그 옵션에서도 같은 코드인지)는 이 진단에서 판정하지 않고 다음 계획으로 넘깁니다. 원본 빌드 옵션의 증거로 단정하지 않습니다.
- 맞는 꼴이 없으면 기록만 하고 보류를 이어 갑니다.
- 명령 하나가 실패할 수 있으므로(옵션 수용 여부) 미수집 run 으로 하고(`EXPECT _log/status`), 명령별 상태·stdout·stderr·입력/도구 해시·manifest 를 손으로 확인합니다(778.10 ⑤; `DONE` 만으로 성공이라 하지 않음).

### 785.3 하지 않는 것
07·빌드 규칙·상태표를 바꾸지 않습니다. 커밋하지 않습니다.

#### 785.4 codex 검토 판정표(작업 `kdnigz0or`)
내가 틀렸던 것(먼저): ① "35 함수" 는 이름 있는 구간 35 개입니다. ② `-g` 가설을 근거 없이 그럴듯하게 적었습니다. 공개 소스로는 강하지 않습니다. ③ GCC 사본이 공개 2.7.2.3 이라는 한계를 적지 않았습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 세 바이트·이웃 함수 d1 | 내 capstone 출력(0x4026288 `727c d2aa002e 2f01`)과 같음 | ✅ |
| 이름 있는 구간 35, 함수 후보 44 | 재현 안 함; 문구만 "구간" 으로 고침, 44 는 옮기지 않음 | ⚖️ |
| 사본은 공개 2.7.2.3 | `scratch/p725/plan725_11.md:1–4` 열람 | ✅ 한계 반영 |
| local-alloc 이 `NOTE` 를 세지 않음 | `local-alloc.c:1143` 열람 | ✅ |
| `REG_ALLOC_ORDER` 없음 | `m68k.h` grep 0 | ✅ |
| reload·global 등 다른 근거 줄 | 재현 안 함; 덤프로 볼 항목이므로 문서에 옮기지 않음 | ⏭️ |
| 덤프 선례 `m4p728-d1`, 옵션 | `run.cmd:2` 열람, `.lreg`·`.greg` 등 파일 있음 | ✅ R0 추가 |
| `-fno-expensive-optimizations`·`-fno-cse-follow-jumps`·`-fno-defer-pop`·BP + `-fno-defer-pop` 제안 | 앞선 계획에 없는 시험임(계획서 grep); 효과는 실행으로 | ✅ G6–G9 추가 |
| 위치를 기호로 찾기, G0 재현 실패 시 중단 | 설계 보강 | ✅ 반영 |

### 785.5 옵션 진단 결과와 새 가설 (2026-11-09; 실기 run `m5p785-g1` 미수집; 07 불변)
- 운영: 11 명령 모두 종료 0, stdout 빔, stderr 는 `kfree` 경고뿐입니다(원래 있던 것; `RUNIN` 줄은 절대 경로라 글자 수만 김). 손 검사(778.10 ⑤) 모두 통과. G0 은 받아들인 객체와 파일째 같습니다.
- G1–G9 어느 것도 레지스터를 바꾸지 못했습니다(`moveq #$7c,d1` 그대로; G2·G4·G5·G8·G9 는 크기까지 달라짐). **`-g` 가설은 틀렸습니다.**
- RTL 덤프(R0): combine 뒤에는 `push (mem + 124)` 한 명령이고, `.greg` 에서 reload 가 `(set (reg:SI 1 d1) (const_int 124))` 를 새로 만듭니다. 즉 이 레지스터는 local/global 배정이 아니라 **reload 의 스필 선택** 입니다(`.greg` "Spilling reg 1").
- 공개 GCC 2.7.2.3 사본의 `reload1.c`: `regs_explicitly_used`(`:486` RTL 에 명시적으로 쓰인 하드 레지스터)는 `order_regs_for_reload`(`:3651`)에서 사용 수가 크게 더해지고 `bad_spill_regs` 에 들어가 스필 레지스터로 쓰이지 못합니다(이 사본의 m68k 에 `SMALL_REGISTER_CLASSES` 정의 없음). 공개 판의 동작이며 NeXT 컴파일러의 구현을 증명하지는 않지만, 대상 컴파일러의 덤프와 맞습니다. `last_spill_reg` 는 함수마다 초기화됩니다(`:702`).
- 덤프에서 `nfs_attrcache_va` 의 RTL 에 `d0` 이 명시적으로 나오는 곳은 `(call_insn (set (reg:SI 0 d0) (call "set_attrcache_time")))` 입니다(암묵 `int` 호출). `bcopy` 라이브러리 호출에는 `d0` 이 없습니다. 이웃 `nfs_attrcache` 는 `nattr_to_vattr`(int)의 호출에도 `d0` 이 있습니다.

### 785.6 새 가설과 진단(코딩 전)
- 가설: 원본의 `set_attrcache_time` 은 `void` 입니다. 그러면 `nfs_attrcache_va` 에 `d0` 의 명시적 사용이 없어져 reload 가 `d0` 을 쓰고, `nfs_attrcache` 는 `nattr_to_vattr` 때문에 그대로 `d1` 입니다. §477 의 V·W 는 `nfs_attrcache_va`·`nfs_attrcache` 만 `void` 로 했고 이 함수는 시험하지 않았습니다.
- 진단(도구 `m5_m68k_srcvar.py`, 바탕 `m4p784-base-stage`, 대조 K = 07 본 파일, `control_ref` = `m3p784-cc1/out/O784__L2_142__nfs_client.o`; 수집 뒤 compare):
  - K
  - T1: `static set_attrcache_time();` → `static void set_attrcache_time();`, 정의 머리도 `static void` 로
- 판정(미리 정함): 먼저 모든 컴파일 종료 0, 객체 있음, K 가 `control_ref` 와 같음(`control_equals_ref` true)을 확인합니다. 그 위에서 T1 의 L1 이 `OBJECT_MATCH`(사유 없음, 텍스트 바이트·재배치 차이·미검증 0)이고, 외부·COMMON·미정의 기호 전체(도구는 원본에 없는 미정의만 기록하므로 python 으로 따로)가 K 와 같아야 합니다. 맞으면 07 반영(오버레이 또는 본 파일)은 x86 확인과 함께 따로 계획하고 사용자 결정을 받습니다. 틀리면 기록만 합니다. 바이트 일치는 원본 소스의 증명이 아닙니다(`void` 는 바이트와 맞는 후보이고, 선언 표기(원형 유무)는 바이트로 정해지지 않습니다).

#### 785.7 codex 검토 판정표(작업 `k9yyls0tl`)
내가 틀렸던 것(먼저): ① 수락 관문에 대조 재현과 미정의 기호 전체 비교를 적지 않았습니다. ② `10.err` 에 덤프 안내가 있다고 적었으나 `kfree` 경고뿐입니다. ③ "스필 후보에서 빠진다" 는 정확히는 `bad_spill_regs` 로 금지되는 것입니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 수락 관문에 `control_equals_ref`·상태·미정의 전체 | 도구 설명(`m5_m68k_srcvar.py:23–29`)과 `:145–178` 열람 | ✅ 반영 |
| `regs_explicitly_used`→`bad_spill_regs`, 함수별 초기화 | `reload1.c` 위 줄 열람(`:486`·`:702`·`:3651–3660`); `SMALL_REGISTER_CLASSES` grep | ✅ 문구 정정 |
| 덤프: `.greg` Spilling 1, `(set d1 124)`, 호출의 `(set d0 …)` | 내 python 출력과 같음 | ✅ |
| 호출하는 곳은 둘, 그 뒤 `d0` 을 읽지 않음 | grep 3 줄(선언·호출 둘·정의); 0x402629e·0x40262f2 뒤 명령은 내 디스어셈블 출력(복원·`rts`) | ✅ |
| 함수 몸체가 `d0` 에 값(delta)을 남김 — "값 없음" 은 틀림 | 재현 안 함; 문서에 "값을 쓰는 곳이 없다" 만 적음 | ⏭️ |
| `10.err` 는 `kfree` 뿐 | `cat` 출력 | ✅ 정정 |
| 표기(원형 유무)는 바이트로 안 정해짐 | 논리 맞음 | ✅ 문구 반영 |

### 785.8 T1 결과 (실기 run `m5p785-t1` 수집, 2026-11-09; 07·상태표 불변; 기록 `09_validation/reconstruction/m5-m68k-nfs-client-variants-p785-20261109.json`, L1 `08_build/artifacts/m5p785/l1-m5p785-t1-*.json`)
- 운영: 2 명령 모두 종료 0. stderr 는 두 변형 모두 `kfree` 경고 한 줄씩이고 파일 이름 말고 같습니다. `control_equals_ref` true(K = `O784__L2_142__nfs_client.o`).
- **T1 은 L1 `OBJECT_MATCH`** 입니다(사유 없음, `__TEXT,__text` 1224 B 의 바이트 차이·재배치 차이·미검증 0). 외부·COMMON·미정의 기호 37 개가 K 와 같습니다(python). K 는 이전과 같이 3 B(오프셋 334·336·341)가 다릅니다.
- 뜻: `set_attrcache_time` 이 `void` 이면 `nfs_attrcache_va` 의 RTL 에서 `d0` 의 명시적 사용이 사라져 reload 가 `d0` 을 쓰고, `nfs_attrcache` 는 `nattr_to_vattr` 때문에 `d1` 그대로입니다. 네 차례의 소스 꼴 시험이 이 함수의 반환형은 건드리지 않았던 것입니다. 원본이 `void` 였다는 것은 바이트와 맞는 후보이며 증명은 아니고, 선언 표기(원형 유무)는 바이트로 정해지지 않습니다.
- 07 반영(사용자 결정 필요): `nfs_client.c` 도 x86 과 함께 쓰는 07 본 파일입니다. (가) m68k 오버레이(D179 와 같은 꼴, 두 줄; x86 불변) (나) 07 본 파일 수정 + x86 재확인.

## 786. D180 — `nfs_client` m68k 오버레이(T1), M5 재수락·회귀, M7 수집 링크 다시 (코딩 전 계획, 2026-11-09)
사용자 결정 D180('"가" 로 진행합니다.': m68k 오버레이)에 따릅니다. 07 본 파일 `src/bsd/nfs/nfs_client.c` 와 x86 은 바꾸지 않습니다.

### 786.1 사실
- T1(785.8)은 `nfs_client.c` 의 두 곳을 바꾼 꼴입니다: `:137` `static set_attrcache_time();\t/* plan 199: … */` → `static void set_attrcache_time();`, `:170` `static` → `static void`(`:171` 은 `set_attrcache_time(vp)`).
- 진단 객체 `08_build/runs/m5p785-t1/out/P785__T1.o` 는 L1 `OBJECT_MATCH` 입니다(사유 없음, `__TEXT,__text` 1224 B 차이 0).
- 오버레이 `.c` 규칙(`stage_m68k.py` `check_derived`, `:594–631`): 07 본 파일 + 표지 줄. 선례는 `swapfs.c`(계획 784).
- `nfs_client.c` 에는 `__LINE__`·`__FILE__`·`assert` 가 없습니다(grep 0). `kfree` 경고는 `:309` 입니다(`m3p784-cc1/out/_log/143.err`).
- `07_kernel/v183.34/m68k/src/bsd/nfs/` 디렉터리는 아직 없습니다.
- `--plan 784 compare` 에서 `x86-nfs_client` 는 `sections_differ` 빔·`verdict` `NOT_MATCH`·`ref_verdict` `NOT_MATCH`·`exception` 빔입니다. T1 은 기준 run(`m3p432-int`)과 코드가 달라지므로, `EXCEPTS` 에 `x86-nfs_client` 가 없으면 `differ_unexpected` 에 들어갑니다(`stage_m68k.py:802`). 따라서 `EXCEPTS[786]` 에 이 객체를 새로 넣습니다.

### 786.2 07 변경과 도구
- 새 오버레이 `07_kernel/v183.34/m68k/src/bsd/nfs/nfs_client.c`(434 + 8 = 442 줄; python). 두 곳 모두 `#if\t!m68k\t/* plan 786 (m68k) */` / 원래 줄 / `#else\t/* plan 786 (m68k) */` / m68k 줄(표지 주석, D180) / `#endif\t/* plan 786 (m68k) */`:
  - `:137` 의 m68k 줄: `static void set_attrcache_time();\t/* plan 786 (m68k): D180, variant T1 of plan 785 */`
  - `:170` 의 m68k 줄: `static void\t/* plan 786 (m68k): D180 */`
- 등록: `OVLFROM['src/bsd/nfs/nfs_client.c'] = 786`, `MARKERS['plan 786 (m68k)'] = {'src/bsd/nfs/nfs_client.c': 8}`, `M4FILES[786] = list(M4FILES[784])`, `EXCEPTS[786] = dict(EXCEPTS[784], **{'x86-nfs_client': …})`, 머리 설명의 계획 목록.
- `m7_m68k_link.py` 의 `M5DIR` → `08_build/artifacts/m4p786/m5compare`(이전 판 사본 `scratch/p786/m7_m68k_link.py.before786`). 빌더 `scratch/p786/build.py` = `scratch/p784/build.py` 에서 `RID`·`OUT`·`CMD`·`REC`·`rec` 의 `plan` 값·표시 문구만 바꿈.
- 문서: `PROVENANCE.tsv` 새 행, `MODIFICATIONS.md` 한 행, 새 증거 `06_reconstruction/evidence/m68k-nfs_client.md`·`.diff`(같은 이름이 이미 있으면 덧붙임), D180, 계획서 결과 절, 메모리.

### 786.3 관문과 판정(미리 정함)
1. 스테이지 `m4p786-base-stage`: 784 스테이지와의 차이가 `src/bsd/nfs/nfs_client.c`(`files` 의 출처·해시)와 manifest 의 `plan`·`replaced` 뿐. 표지 검사 통과.
2. 전처리 동등성(python): 표지 줄을 빼면 07 본 파일과 같고, `#if` 를 m68k 쪽으로 풀면 T1 변형 파일(`08_build/runs/tools/m5p785-t1-stage/src/bsd/nfs/p785_T1.c`)과 두 m68k 줄의 주석(`:137`·`:170` 자리) 말고 같습니다.
3. x86: `--plan 786 x86gate` 7/7 같음, `m4-x86-inputs-p786-20261109.json` `ok`, 07 본 파일 SHA-256 `26d9d69b…` 불변(`git diff` 없음).
4. M5 205 명령이 784 와 계획 번호 말고 같음. 새 run `m3p786-cc1`(수집): 모두 종료 0.
   - `nfs_client` 말고 204 객체는 `m3p784-cc1` 과 파일째 같고, stderr 204 개도 같음.
   - `nfs_client` 의 stderr 는 줄 번호 `309` → `317`(python: 309 + 4 + 4) 말고 같음.
   - `nfs_client` 는 `P785__T1.o` 와 `m7_m68k_objdiff`(`allow` 빔)로 `canon`·헤더·절·비 STABS 기호가 같음(STABS 는 수만 비교; 파일 이름·줄 번호가 다름).
   - L1 `OBJECT_MATCH`, 사유 없음.
5. `--plan 786 compare`(기록 `m3-m68k-p786-compare-20261109.json`, WORKDIR `08_build/artifacts/m4p786/m5compare`): 784 요약과 다른 키는 다음뿐이어야 합니다(python 으로 미리 계산): `same_non_stabs` 162 → 161, `differ` 43 → 44(`x86-nfs_client` 추가), `object_match` [146,175] → [146,176], `gained` 29 → 30(`x86-nfs_client` 추가), `stage_vs_test_stage` 에 `src/bsd/nfs/nfs_client.c` 추가. `differ_unexpected`·`lost` 는 빔, `byte_identical` 74 그대로.
6. M4 는 바뀐 머리가 없으므로 다시 만들지 않습니다(상태표 불변). `__data` 지표(781)도 그대로입니다(`nfs_client` 객체에는 `__data` 절이 없음: T1 의 절은 `__text` 1224 B 하나, python).
7. M7: `spec`·`common` 새 기록(784 와 같은 수치: 문자열 배치 10/210, 정의 없는 이름 0, DP 최소 0, 상한 4 에서 613·7592 같음). 빌더 단정 통과 → 수집 run `m7p786-a1`, 명령 2 개 종료 0 → 비교:
   - **strip 한 `mach_kernel` 이 원본과 파일째 같음**: 832196 B, SHA-256 `dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75`, 다른 바이트 0.
   - 층 B·C(3809 기호·문자열표)·E 같음, 층 D 는 입력 기여 454 개 모두 같음.
   - `.sys` 는 외부 기호가 원본과 같고, 지역·STABS 수는 기록만 합니다.
- 어느 관문이든 어긋나면 멈추고 원인을 찾습니다.

### 786.4 하지 않는 것·한계
- 바이트 일치는 원본 소스의 증명이 아닙니다. `void` 는 바이트와 맞는 후보이고 선언 표기(원형 유무)는 바이트로 정해지지 않습니다.
- strip 한 커널이 원본과 같다는 것은 링크 옵션이 원래 빌드 명령이라는 증거가 아닙니다(782.5).
- `swapfs` 등 `__const`·`__bss` 미검증 객체를 `OBJECT_MATCH` 로 올리지 않습니다. M5 집계는 코드 검증 208/208(100 %)이 됩니다.
- QEMU 부팅(M8)은 범위 밖입니다. 커밋하지 않습니다.

#### 786.5 codex 검토 판정표(작업 `k6hkfqrko`)
내가 틀렸던 것(먼저): ① 스테이지 관문에 manifest 의 `overlays` 가 바뀐다고 적었으나 바뀌는 것은 `plan`·`replaced`·`files` 입니다(`overlays=OVL`, `stage_m68k.py:704`). ② 전처리 동등성에서 주석이 다른 곳은 `:137` 만이 아니라 두 m68k 줄입니다. ③ `nfs_client` 의 `__data` 가 "바뀌지 않는다" 고 적었으나 그 객체에는 `__data` 절이 없습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 오버레이 꼴이 `check_derived` 를 통과(442 줄, 표지 8) | `:594–631` 열람; 실제 통과는 구현의 `stage` 가 같은 검사를 함 | ⚖️ 실행으로 확인 |
| manifest 의 `files` 도 바뀌고 `overlays` 는 불변 | `stage_m68k.py:704`·`:711` 열람 | ✅ 정정 |
| 주석 차이는 두 자리 | 내 초안의 m68k 줄 두 개에 모두 표지 주석이 있음 | ✅ 정정 |
| 컴파일 줄에 `-Dm68k`(specs) | `specs-m68k:38` 을 python 없이 `tr`·`grep`: `-Dmc68000`·`-Dm68k` | ✅ |
| 표지 주석이 있는 `#if` 가 `-traditional-cpp` 에서 동작 | `swapfs.c` 오버레이가 계획 784 에서 F2 와 같은 객체를 냄(§784.6) | ✅ |
| 다른 도구에 계획 번호 등록 불필요 | `grep -n "\b784\b" 10_tools/reconstruction/*.py` — `stage_m68k.py`·`m7_m68k_link.py` 뿐; `M4HEADERS` 는 `max(k <= PLAN)` (`:653`) | ✅ |
| 빌더의 `rec` `plan='784'` 도 바꿀 것 | `scratch/p784/build.py:232` 열람 | ✅ 반영 |
| 요약 차이 예측(162→161 등) | `D.canon` 비교: T1 과 `m3p432-int` 는 `__TEXT,__text` 만 다름; python 161·44·176·30; `ref_verdict` `NOT_MATCH` | ✅ (실행으로 판정) |
| M7 검사는 옛 차이에 기대지 않음 | `m7_m68k_compare.py:188–191` 열람(차이·자리 없으면 `equal`); `build.py` 에 예상 차이 목록 없음 | ✅ |
| 저장 커널에 T1 바이트를 끼우면 원본과 같음 | 재현 안 함; 새 링크로 판정하며 문서 근거로 쓰지 않음 | ⏭️ |
| `nfs_client` 에 `__data` 없음 | `L.parse(P785__T1.o)` 의 절 = `__text` 1224 B 뿐 | ✅ 정정 |
| 의존 닫힘의 `__LINE__` 은 `MACH_ASSERT 0` 뿐 | `nfs_client.c` 자체 0(python)만 확인; 머리까지의 효과는 관문 4 의 `canon` 비교가 판정 | ⏭️ 관문으로 대체 |
| `kr_run` 은 run 사이 stderr 를 비교하지 않음 | 관문 4 의 비교는 내가 python 으로 함(784 와 같음) | ⏭️ |

### 786.6 결과 (2026-11-09; 커밋 안 함)
- 07: 새 오버레이 `07_kernel/v183.34/m68k/src/bsd/nfs/nfs_client.c`(07 본 파일 434 줄 + 표지 줄 8 = 442 줄). 표지 줄을 빼면 07 본 파일과 같고, m68k 쪽만 고르면 T1 변형 파일과 두 줄의 주석 말고 같습니다(python). 등록은 `OVLFROM`·`MARKERS['plan 786 (m68k)']`(8)·`M4FILES[786]`·`EXCEPTS[786]`(`x86-nfs_client`) 입니다. 07 본 파일은 그대로입니다(SHA-256 `26d9d69b…`, `git diff` 없음).
- 스테이지 `m4p786-base-stage`(1047 파일): 784 스테이지와 다른 파일은 `src/bsd/nfs/nfs_client.c` 하나, manifest 의 다른 키는 `plan`·`replaced`·`files` 입니다. x86 관문 7/7 같음, `m4-x86-inputs-p786-20261109.json` `ok`. M5 명령 205 줄은 784 와 계획 번호 말고 같습니다.
- M5 205 run `m3p786-cc1`(수집): 모두 종료 0. `nfs_client` 말고 204 객체는 `m3p784-cc1` 과 파일째 같고 그 stderr 도 같습니다. `nfs_client` 의 stderr 는 `kfree` 경고의 줄 번호 309 → 317 말고 같습니다.
  - `nfs_client` 는 `P785__T1.o` 와 `canon`·절·비 STABS 기호가 같습니다(`m7_m68k_objdiff`, STABS 867 = 867).
  - L1 `OBJECT_MATCH`, 사유 없음, 텍스트 바이트·재배치 차이·미검증 0.
  - `--plan 786 compare` 요약은 예측과 같습니다: `same_non_stabs` 162 → 161, `differ` 43 → 44, `object_match` [146,175] → [146,176], `gained` 29 → 30(모두 `x86-nfs_client`), `stage_vs_test_stage` 228 → 229. `differ_unexpected`·`lost` 는 빕니다.
- M5 집계: 코드 검증 208/208(100 %, python). 코드 차이가 남은 객체는 없습니다. `__const`·`__bss` 미검증 객체를 `OBJECT_MATCH` 로 올리지는 않습니다.
- M7: `M5DIR` 를 `m4p786/m5compare` 로 바꿨습니다(이전 판 사본 `scratch/p786/m7_m68k_link.py.before786`). `spec`·`common` 새 기록은 784 와 같은 수치입니다(문자열 배치 10/210, 정의 없는 이름 0, DP 최소 0(30/180), 상한 4 에서 613·7592 같음). 빌더 `scratch/p786/build.py` 의 단정을 모두 통과했고, 수집 run `m7p786-a1` 은 명령 2 개 모두 종료 0, 손 검사(입력·도구·manifest) 통과입니다. 입력은 객체 296 개와 `run.cmd`·`run.sh` 뿐이고 원본 커널은 들어가지 않았습니다(입력 해시 대조, python).
- **strip 한 `mach_kernel` 은 원본과 파일째 같습니다**: 832196 B, 다른 바이트 0, SHA-256 `dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75`. 층 B 차이 0, C(3809 기호·문자열표) 같음, D 는 네 절 모두 0, 입력 기여 454 개 모두 같음, E·F 같음. `.sys` 는 외부 기호 3809 개가 원본과 같고 지역 2266·STABS 229318 입니다(기록만). 기록은 `09_validation/reconstruction/m7-m68k-p786-link-20261109.json` 입니다.
- 문서: `PROVENANCE.tsv` 새 행(NeXTMach 출처 유지), `MODIFICATIONS.md` 한 행, 새 증거 `06_reconstruction/evidence/m68k-nfs_client.md`·`.diff`, D180. 상태표와 `__data` 지표(781)는 그대로입니다.
- 한계: 바이트 일치는 원본 소스의 증명이 아닙니다(`void` 는 바이트와 맞는 후보, 선언 표기는 미정). 링크 옵션도 바이트와 맞는 후보입니다. 부팅(M8)은 시험하지 않았습니다.

## 787. M7 전체 재빌드 — 지금의 07 로 296 객체를 한 run 에서 다시 컴파일하고 링크 (코딩 전 계획, 2026-11-09; 07·상태표 불변)
사용자 지시("지금의 07 로 전체를 한 번에 다시 만들어 보는 것")에 따릅니다. 07·도구·상태표는 바꾸지 않습니다.

### 787.1 사실
- 내가 틀렸던 것(먼저): 직전 보고에서 "계획 779 는 `pmap.h` 를 포함하는 M4 45 개만 다시 빌드했다" 고 했으나, §779.3 의 R1(`m4p779-r1`, 미수집)은 M4 76 개 전부를 받아들인 명령으로 다시 컴파일했습니다(RUN 76 줄; 받아들인 객체와 `canon` 이 모두 같고, 파일째 같은 것 35·다른 것 41, python). 45 는 회귀 대상 수였습니다. 빠진 것은 재컴파일이 아니라, 지금의 07 에서 만든 객체 한 벌을 수집해 **링크까지 하는 것** 입니다.
- 지금의 수집 링크 `m7p786-a1` 의 입력: M5 204(`m3p786-cc1`)·R 3·D 13(`m4p781-a1`)·M4 76(run 55 개, 계획 497–780). 92 개(M4·R·D) 모두 `run.cmd` 에 `-o` 가 그 객체인 `RUN` 줄이 하나이고 소스는 스테이지 안(`src/src/…`)입니다(python).
- 스테이지 `m4p786-base-stage`(1047 파일): 출처 07 993·SDK `/NextDeveloper` 41·`darwin01/kernel` 13. 07 출처 파일은 모두 지금의 07 과 SHA-256 이 같습니다(python, 불일치 0).
- M4 76·D 13 의 `-M` 목록을 지금 스테이지와 대조(python; `-imacros` 생성 머리는 `-M` 밖이므로 이 대조에 없고 재빌드가 판정): 42 개는 `pmap.h`(42)·`thread.h`(15) 만 바뀌었고 47 개는 그대로, 객체 자신의 소스가 바뀐 것은 0 입니다. R 3 은 `-M` 줄이 없어 재빌드로만 판정합니다.
- `m4p779-r1` 이후 빌드 입력의 변경은 `swapfs.c`·`nfs_client.c` 의 M5 오버레이뿐입니다(계획 784·786; `m4p779-base-stage` 와 `m4p786-base-stage` 의 전체 트리 대조에서 이 두 경로만 다름, python). M4 는 이 두 파일을 포함하지 않습니다(`-M` 목록).
- 오프라인 예측(python, R1 객체 76 을 `World` 에 넣음): 절 크기 모두 같음; 외부 이름의 변화는 41 객체에 `_pv_head_table`·`_pv_list_zone` 추가뿐; `__common` 613 순서·주소·끝이 원본과 같음(두 이름의 첫 언급은 이미 `M5:cmu_syscalls`).

### 787.2 run A — 컴파일 296 줄 (새 ID `m7p787-cc1`, 수집)
- 소스 = `08_build/runs/tools/m4p786-base-stage` 그대로(다시 만들지 않음). 실행 직전 사전 검사(python): 트리 전체 1047 파일이 manifest 와 같고(생성 파일 포함), 07 출처 파일이 지금의 07 과 같음.
- 컴파일러 지문: `kr_run` 은 `/bin/cc`·`/bin/ld` 등만 해시하고 `/lib/m68k/{as,cc1obj,cpp,cpp-precomp,specs}` 는 해시하지 않습니다(`kr_run.py:39`). 그래서 run A 전과 run B 뒤에 실기에서 `krsha256-default` 로 이 다섯 파일을 읽어(읽기 전용) `08_build/artifacts/m0p413/tools-post.txt` 와 같은지 확인하고 기록합니다.
- 명령 생성기 `scratch/p787/build_cc.py`: `p786_link.json` 의 296 객체마다 그 객체를 만든 run 의 `RUN` 줄을 찾아 **`-o` 값만** `stage/<key>.o`(`M4_locore.o` 꼴)로 바꿉니다. 단정: 줄이 정확히 하나, 소스 토큰 하나(`src/src/…` 또는 `src/generated/…`), 그 소스가 스테이지에 있음, `-M` 없음, 절대 경로 없음. M5 줄은 `m3p786-cc1`, R·D 는 `m4p781-a1`, M4 는 각자의 run.
- 명령 파일 `08_build/artifacts/m7p787/m7p787-cc1.cmd`: `RUN` 296, `EXPECT` 296.

### 787.3 run A 판정(미리 정함; 어긋나면 멈추고 원인을 찾음)
1. run 무결성: `DONE`, `FAILED` 없음, 입력·도구 해시, 모든 명령 종료 0.
2. stderr: 각 객체의 stderr 가 그 줄을 만든 원래 run 의 stderr 와 같음.
3. 객체 비교:
   - M5 204 는 `m3p786-cc1`, R 3·D 13 은 `m4p781-a1`, M4 76 은 `m4p779-r1` 의 같은 객체와 **파일째 같음**.
   - M4 76 은 받아들인 객체와 `canon` 이 같고, `m7_m68k_objdiff` 로 절이 같으며 비 STABS 기호 차이는 더해진 COMMON `_pv_head_table`·`_pv_list_zone` 뿐(받아들인 객체와 파일째 같은 것은 차이 없음).

### 787.4 run B — 링크 (새 ID `m7p787-ln1`, 수집)
- 빌더 `scratch/p787/build_ln.py` = `scratch/p786/build.py` 에서 ① `RID`·`OUT`·`CMD`·`REC`·`plan`·표시 문구 ② `World()` 직후, `objs`·`P`·`paths`·`hashes` 를 잡기 전에 객체 경로·해시를 run A 의 `out/` 으로 바꾸고 `W.P` 를 그 객체로 다시 읽음(절 크기가 받아들인 객체와 같음을 단정; `objs` 의 주소·크기는 L1 기록 그대로). 그 밖의 단정은 그대로입니다.
- 명령: 같은 `ld`·`strip`, 같은 순서 R. 입력은 run A 의 `out/` 사본(해시 대조)뿐입니다.

### 787.5 run B 판정
- 명령 2 개 종료 0, 손 검사(입력·도구·manifest) 통과, 입력에 원본 커널 없음.
- **strip 한 `mach_kernel` 이 원본과 파일째 같음**: 832196 B, 다른 바이트 0, SHA-256 `dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75`. 층 B·C·D·E·F 같음(`m7_m68k_compare.py`).
- `.sys` 는 외부 기호가 원본과 같음; 지역·STABS 수와 `m7p786-a1` 의 `.sys` 와의 차이는 기록만.

### 787.6 문서·한계
- 기록 `09_validation/reconstruction/m7-m68k-p787-build-20261109.json`(두 run, 객체별 판정, 비교 결과, 해시), 계획서 결과 절, 메모리. 07·상태표·`__data` 지표·`M5DIR` 는 바꾸지 않습니다.
- 한계: 빌드 명령은 받아들인 명령을 그대로 쓴 것으로, 커널 Makefile 을 재현한 것은 아닙니다(M5·M4·R·D 의 옵션 묶음이 다름). 바이트 일치는 원본 소스의 증명이 아닙니다. 부팅(M8)은 범위 밖입니다. 커밋하지 않습니다.

#### 787.7 codex 검토 판정표(작업 `kgd9r7ms2`)
내가 틀렸던 것(먼저): ① 직전 보고의 "M4 45 개만 다시 빌드" 는 틀렸습니다(787.1). ② 사전 검사를 07 출처 파일만으로 적어 생성 파일의 변화를 놓칠 수 있었습니다. ③ 컴파일러 본체(`/lib/m68k/*`)가 `kr_run` 의 해시 대상이 아니라는 점을 적지 않았습니다. ④ "07 변경은 오버레이뿐" 은 "빌드 입력의 변경" 으로 좁혀야 합니다(문서 파일도 바뀜).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `kr_run` 해시가 `/lib/m68k/*` 를 뺌 | `kr_run.py:39–41` `ALLOWED_TOOLS` 열람; `m3p786-cc1/tools.actual` 에 없음; `m0p413/tools-post.txt:1–5` 열람 | ✅ 관문 추가 |
| R1 76 줄, 받아들인 줄과 `-o` 말고 같음, 35/41 | 내 python: RUN 76, 모두 일치, 파일째 같음 35·다름 41, `canon` 차이 0 | ✅ |
| `-M` 42/47, `pmap.h` 42·`thread.h` 15 | 내 python 같은 수 | ✅ |
| 출처 993·41·13, 트리 1047 이 manifest 와 같음 | 내 python: 파일 1047, 집합 같음, 해시 불일치 0; 출처 993·41·13 | ✅ 사전 검사에 반영 |
| 779/786 트리는 두 파일만 다름 | 내 python 전체 트리 대조: `nfs_client.c`·`swapfs.c` 뿐, 남는 파일 0 | ✅ 문구 좁힘 |
| `-imacros` 는 `-M` 밖이고 R1 이 지금의 생성 구성을 시험함 | 트리 대조로 `generated/` 차이 없음; `-M` 밖이라는 점은 §779.6 표 | ✅ |
| `N_SO` 에 run 경로·출력 이름이 없음 | 재현 안 함; 관문 3 의 파일째 비교가 판정. 간접 근거: `m3p784`/`m3p786` 의 204 객체가 run ID 가 달라도 파일째 같음 | ⏭️ 관문으로 대체 |
| 치환은 별칭을 잡기 전에 | `scratch/p786/build.py:20–24` 열람 | ✅ 반영 |
| 치환을 넣은 빌더 앞부분이 통과 | 재현 안 함; 내 오프라인 예측(787.1)은 COMMON 까지만 봄. 실행으로 판정 | ⏭️ |
| 로그 이름 `%02d`, 296 줄·명령 길이 문제 없음 | `kr_run.py:246` 열람; 생성기에서 python 으로 296·유일 확인 | ✅ |
| 모든 명령의 `-Isrc/nextdev/bsd` 는 없는 경로 | 재현 안 함; 받아들인 명령 그대로이므로 행동이 바뀌지 않음, 문서에 옮기지 않음 | ⏭️ |

### 787.8 결과 (2026-11-09; 커밋 안 함; 07·도구·상태표 불변)
- 사전 검사: 스테이지 1047 파일이 manifest 와 같고 07 출처 파일이 지금의 07 과 같습니다(python). `/lib/m68k/{as,cc1obj,cpp,cpp-precomp,specs}` 다섯 파일의 해시는 run 전후가 같고 `m0p413/tools-post.txt` 와 같습니다.
- run A `m7p787-cc1`(수집, 컴파일 296): 모두 종료 0, 입력·도구 해시·manifest 통과, stderr 296 개는 각 줄을 만든 원래 run 과 같습니다(경고 있는 것 68).
  - M5 204·R 3·D 13 은 받아들인 객체와 파일째 같습니다.
  - M4 76 은 R1(`m4p779-r1`) 객체와 파일째 같습니다. 받아들인 객체와는 파일째 같은 것 35, 다른 것 41 이며 41 개 모두 `canon`·절이 같고 비 STABS 기호 차이는 더해진 COMMON `_pv_head_table`·`_pv_list_zone` 뿐입니다(`m7_m68k_objdiff`, 76 모두 허용; STABS 수는 41 개에서 다름, 판정하지 않음).
- run B `m7p787-ln1`(수집, `ld` + `strip`): 빌더 단정 모두 통과(`__common` 613 순서·주소·끝, 예측 외부 기호 3809 개, 재배치 자리 차이 0), 명령 2 개 종료 0, 입력은 run A 의 객체 296 개와 `run.cmd`·`run.sh` 뿐이고 원본 커널은 없습니다.
- **지금의 07 로 한 번에 다시 만든 `mach_kernel` 이 원본과 파일째 같습니다**: 832196 B, 다른 바이트 0, SHA-256 `dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75`. 층 B 차이 0, C(3809 기호·문자열표) 같음, D 네 절 0, 입력 기여 454 개 모두 같음, E·F 같음. `m7p786-a1` 의 strip 판과도 같습니다.
- `.sys` 는 외부 기호 3809 개가 원본과 같고, `m7p786-a1` 의 `.sys` 와는 파일이 다릅니다(STABS 229318 → 230285; 새 `pmap.h` 를 읽은 객체의 디버그 기록 때문이며 판정하지 않음).
- M7 끝 조건(표준 문서 M7): L2 충족, 전체 파일 바이트 동일도 충족입니다. 기록은 `09_validation/reconstruction/m7-m68k-p787-build-20261109.json` 입니다.
- 한계: 빌드 명령은 받아들인 명령 그대로(옵션 묶음 18 가지)이며 커널 Makefile 을 재현한 것은 아닙니다. 바이트 일치는 원본 소스의 증명이 아닙니다. 부팅(M8)은 시험하지 않았습니다.

## 788. M8 L3 — 다시 만든 m68k 커널의 QEMU 부팅 시험 (코딩 전 계획, 2026-11-09; 07·상태표 불변)
사용자 지시("남은 분석이 없으면 M8 로 진행", 787 뒤)에 따릅니다. 표준 문서 M8 공통 절차와 x86 §405·406 을 따릅니다.

### 788.1 사실
- 시험할 커널: `08_build/runs/m7p787-ln1/out/mach_kernel`(832196 B, SHA-256 `dff6c51c…`, 07 로 한 번에 다시 만든 것).
- **이 커널은 VM 디스크의 설치본과 같은 바이트입니다**: `/sdmach`·`/odmach`·`/private/tftpboot/mach` 가 한 inode 이고 `03_original/m68k` 와 같습니다(`EMULATION_PLATFORM_PLAN.md:166`, 2026-10-01 기록). 그래서 이 시험의 결과는 원본 커널의 부팅과 구별되지 않습니다. 시험이 보여 주는 것은 "새 이름으로 넣은 파일이 ROM·부트 프로그램·커널·사용자 공간까지 이어진다" 와 절차 자체입니다.
- 커널 판 문자열(python, 파일 오프셋 733465): `NeXT Mach 4.2: Sun Apr 27 13:42:14 PDT 1997; root(rcbuilder):Objects/mk-183.34.obj~4/RELEASE_M68K`.
- ROM v66 의 사용법 문자열(python): `Usage: b [device[(ctrl,unit,part)] [filename] [flags]]`, 부팅 표시 `boot %s%s%s`·`Booting %s from %s`. 표준 문서의 미확인 사항(ROM 에서 새 이름 고르기)은 이 형식으로 시험합니다(동작은 실행으로 판정).
- 디스크 `09_validation/images/m68k/openstep42-m68k-hdd.raw`(1024 MiB, SHA-256 `7097595f…`), NeXT 라벨 `dlV3`, 라벨의 부팅 파일 `sdmach`.
- `vm-common.sh` 의 `--disk` 는 i386·sparc 만 허용합니다(`vm_disk`). `vm-m68k.sh` 는 CD·NIC 를 붙이고 `-display gtk -monitor stdio` 로 띄우며, QMP `/tmp/kr-m68k-qmp.sock` 를 엽니다. 저장 공간 여유 14 GB, QEMU 실행 중 없음, `DISPLAY=:1`.
- ROM 은 NVRAM 이 비어 `System test failed. Error code 91.` 뒤 `NeXT>` 에서 멈춥니다(`QEMU_VM_CONFIGURATIONS.md` §1).

### 788.2 준비(QEMU 실행 없음; 어긋나면 멈춤)
1. 커널 사본 `09_validation/images/m68k/kernels/mach_kernel.l2`(저장소 무시 대상) = run B 의 `out/mach_kernel`, SHA-256 대조.
2. QEMU 꺼짐 확인 → 저장소 디스크 SHA-256 기록 → 시험 디스크 사본 `09_validation/images/m68k/openstep42-m68k-hdd.l2test.raw`(같은 SHA 확인). 사본 경로가 이미 있거나 심볼릭 링크이면 멈추고, 쓰기 전에 `os.path.samefile(사본, 저장소 디스크)` 가 거짓인지 단정합니다(`nextufs mkfile` 은 받은 이미지를 읽기·쓰기로 엽니다).
3. `nextufs fsck -n`(출력으로 판정; 5 단계 뒤 경고 없음) → `nextufs mkfile --from-file` 로 `/sdmachl2` → `--chmod` 0444 → `fsck -n` 다시. 명령은 둘로 나눕니다: `nextufs mkfile --from-file DISK /sdmachl2 HOST`, `nextufs mkfile --chmod DISK /sdmachl2 0444`. `fsck -n` 은 종료 코드만으로 판정하지 않습니다(열기 실패에서도 실패 상태 없이 돌아옴, `setup.c:145–149`): 5 단계와 요약 줄이 모두 있고 오류 출력이 없어야 합니다.
4. 시험 디스크를 읽기 전용으로 확인: `/sdmachl2` 는 일반 파일·0444·uid/gid 0/0·832196 B·SHA 같음; `/sdmach` 등 세 이름의 해시 불변. 시험 디스크 SHA-256 기록. 저장소 디스크 SHA 불변.
5. `vm_disk` 의 허용 조건에 `m68k` 의 `boot` 를 더합니다(한 줄; 오류 문구·머리 설명도). `--snapshot` 필수 조건은 그대로. `bash -n` 과 QEMU 없이 `vm_parse`·`vm_disk` 만 부른 시험(정상·`--snapshot` 없음·`install`·qcow2·512 배수 아님·없는 파일). README·`QEMU_VM_CONFIGURATIONS.md` 에 한 줄씩.

### 788.3 부팅 시험(모두 시험 디스크 + `--snapshot`; GTK 창은 사용자 화면)
- 실행: `bash 11_emulation/scripts/vm-m68k.sh boot --disk …l2test.raw --snapshot --gdb-wait < /dev/null`(모니터 EOF 는 VM 을 끄지 않음, `monitor/hmp.c` 의 `CHR_EVENT_CLOSED` 는 fdset 정리뿐; 띄운 뒤 QEMU 가 살아 있는지 확인), 드라이버 `scratch/p788/qmp_boot.py`(QMP: `qmp_capabilities`·`cont`·`send-key`·`screendump`(`"format":"png"` 명시, 절대 경로, 실행마다 새 디렉터리 `09_validation/images/m68k/logs/l3-boot-20261109/<run>/`)·`stop`·`quit`. `commit`·재설정 금지. 인사·오류·이벤트를 검사하고 소켓 시간 제한; `cont` 뒤 상태가 running 인지 확인한 다음에만 키를 보냄(멈춘 VM 의 입력은 버려짐, `ui/input.c:365`). `(`·`)` 는 `shift` + `9`·`0`.) 화면은 PNG 를 내가 읽어 판단합니다(프레임버퍼라 글자 버퍼 읽기가 없음).
- 부팅 명령: 문서에 있는 꼴 `bsd …` 에 파일 이름을 더한 `bsd sdmachl2 -s` 를 먼저 씁니다. ROM 이 이 꼴을 받지 않으면 `b sd(0,0,0) sdmachl2 -s` 로 바꾸고 그 사실을 기록합니다.
- R0 대조: `NeXT>` 에서 `bsd nosuchkern -s` → 커널이 뜨지 않아야 합니다(이름이 실제로 쓰인다는 대조). 어떤 상태로 끝나든(`NeXT>` 복귀를 요구하지 않음) 시간 제한 3 분 안의 화면을 기록하고 QMP 로 끕니다.
- R1 단일 사용자(새로 띄운 VM, 시간 제한 10 분): `bsd sdmachl2 -s` → ROM 의 부팅 표시에 파일 이름, 커널 판 문자열이 위 문자열과 같음, 루트 셸 `#` → `hostinfo`, `ls -l /sdmachl2` 를 화면으로 기록.
- R2 다중 사용자: `bsd sdmachl2` → 시간 제한(15 분) 안에 로그인 창 또는 콘솔 로그인. 설정 대기(`QEMU_VM_CONFIGURATIONS.md` §1 의 hostname·NetInfo 대기)가 나오면 그 화면과 대응(`c`)을 기록. 로그인은 하지 않습니다(계정을 기록에 남기지 않음; 필요하면 사용자와 상의).
- 종료: `stop`·`quit`, QEMU PID 종료 확인, 시험 디스크·저장소 디스크 SHA 불변.
- R1·R2 사이에 QEMU 를 끄고 새로 띄웁니다(각각 새 snapshot).

### 788.4 판정(미리 정함)
- L3(QEMU) 충족 = R0 이 예상대로 실패하고, R1 이 위 판 문자열로 단일 사용자 셸에 이르고 `hostinfo` 가 나옴. 시작·끝의 디스크 해시가 같음.
- R2 는 도달한 단계(로그인 창 / 대기 / 멈춤)를 기록합니다. 멈추면 같은 시험을 `/sdmach`(설치본)로 돌려 비교합니다. 파일이 같으므로 결과도 같아야 하며, 다르면 환경 차이를 조사합니다.
- 패닉·예외는 화면을 남기고 멈추고 원인을 따로 조사합니다. 기능을 고치지 않습니다.

### 788.5 문서·한계
- 기록 `09_validation/reconstruction/m8-m68k-p788-boot-20261109.json`(해시·명령·화면 파일 목록·판정), 화면은 무시 대상 디렉터리. 계획서 결과 절, 메모리.
- 한계: QEMU 만이며 실기는 없습니다(D067). 커널이 설치본과 같은 바이트이므로 재구성 소스의 추가 증거는 아닙니다. `--snapshot` 이므로 디스크는 바뀌지 않습니다. 커밋하지 않습니다.

#### 788.6 codex 검토 판정표(작업 `kq6d612da`)
내가 틀렸던 것(먼저): ① `/sdmachl2` 가 8 자라서 위험이 줄어든다고 적었으나 근거가 없어 지웠습니다. ② `screendump` 는 형식을 명시하지 않으면 PPM 입니다. ③ `fsck -n` 판정을 "5 단계 뒤 경고 없음" 만으로 적었습니다. ④ `tail` 을 남기면 끝난 뒤 파이프가 기다릴 수 있습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 1. `b sd(0,0,0)` 이면 부트 블록이 이름 앞 바이트를 덮음(오프셋 인용) | 디스어셈블은 재현 안 함. 결론(문서의 `bsd` 꼴을 쓰는 것)은 어느 쪽이든 안전한 쪽이라 채택, 오프셋·덮어쓰기 주장은 문서에 옮기지 않음 | ⚖️ 결론만 |
| 2. 커널·디스크·설치본 해시·라벨 `sdmach` | 내 python: 커널 SHA·판 문자열; 디스크 SHA `7097595f…`; 식별 기록의 m68k 라벨 `kernel: sdmach`; 같은 inode 는 `EMULATION_PLATFORM_PLAN.md:166` | ✅ |
| 3. ROM 사용법 문자열 | 내 python 문자열 추출 | ✅ |
| 4. 8 자 경계 없음 | 재현 안 함; 위 ①로 문구 삭제, `sdmachl2` 는 그대로 씀 | ⏭️ |
| 5. R0 은 유용하나 `NeXT>` 복귀를 요구하지 말 것, 시간 제한 | 실패 경로는 재현 안 함; 요구를 없애는 쪽은 안전 | ✅ 반영 |
| 6. `mkfile` 은 명령 둘로 | `nextufs.1:267`(`--chmod`)·`:270`(`--from-file`) 열람 | ✅ |
| 7. `fsck` 는 열기 실패에도 실패 상태 없이 돌아옴 | `setup.c:145–149`(`Can't open` 뒤 `return (0)`), `session.c:31` 열람 | ✅ 판정 강화 |
| 8. `vm_disk` 허용 추가로 충분 | `vm-common.sh:79–97`·`vm-m68k.sh` 열람(`--disk` 분기에서 `disk`·`snap_args` 설정) | ✅ |
| 9. `send-key` 가 NeXT 키보드로 감 | `next-kbd.c:854` 등록 열람; 실제 동작은 실행으로 | ⚖️ 실행으로 판정 |
| 10. 멈춘 VM 의 키 입력은 버려짐 | `ui/input.c:365` 열람 | ✅ 반영 |
| 11. `screendump` 기본 PPM, 이 기종은 `next-color-video` | `ui-qmp-cmds.c:378` 열람; `next-cube.c:26` include | ✅ 반영 |
| 12. `tail` 대신 stdin `/dev/null` | `monitor/hmp.c` `CHR_EVENT_CLOSED` 열람 | ✅ 반영(띄운 뒤 생존 확인) |
| 13. 사본 별칭 검사 | `nextufs` 가 읽기·쓰기로 엶(`mkfile` 동작은 §405 와 같음) | ✅ 반영 |

### 788.7 결과 (2026-11-09; 커밋 안 함; 07·상태표 불변)
- 준비: 커널 사본 `09_validation/images/m68k/kernels/mach_kernel.l2`, 시험 디스크 `…/openstep42-m68k-hdd.l2test.raw`(SHA-256 `88b35f12…`). `fsck -n` 은 넣기 전 33278 파일·넣은 뒤 33279 파일이고 다섯 단계 모두 통과, 오류 출력 없음. `/sdmachl2` 는 일반 파일·0444·uid/gid 0/0·832196 B·SHA `dff6c51c…`, `/sdmach`·`/odmach` 해시 불변. 전체 감사에서 오류 1 건(`inode 897: hole at logical block 401`)이 나왔으나 저장소 디스크에도 같은 항목이 있어 이번 삽입과 무관합니다. `vm_disk` 는 `m68k boot` 를 허용하도록 고쳤고 `bash -n` 과 오류 경로 6 가지를 시험했습니다.
- R0 대조(`bsd nosuchkern -s`): ROM 이 `boot sd(0,0,0)nosuchkern -s` 로 받았고, 부트 프로그램이 `nosuchkern: not found`·`load failed` 로 `blk0 boot:` 에 멈췄습니다. 이름이 실제로 쓰입니다.
- R1 단일 사용자(`bsd sdmachl2 -s`): 판 문자열 `NeXT Mach 4.2: Sun Apr 27 13:42:14 PDT 1997; root(rcbuilder):Objects/mk-183.34.obj~4/RELEASE_M68K` 가 예측과 같고, 루트 셸에서 `hostinfo`(MC680x0 68040 25 MHz, 32.00 MB, 9 tasks·22 threads), `ls -l` 로 `/sdmachl2` 832196 B 를 확인했습니다.
- R2 다중 사용자(`bsd sdmachl2`): 로그인 창에 이르렀고, 사용자가 로그인해 Workspace 가 떴습니다. Terminal `hostinfo` 도 같은 판 문자열이며 39 tasks·74 threads 입니다. 사용자가 GTK 창에서 Ctrl+C 2 번(`-AUTOMATIC-` 뒤 hostname 대기)과 `c`(뒤 대기)를 입력했습니다(`QEMU_VM_CONFIGURATIONS.md` §1 의 대기와 같음). 계정은 기록하지 않았습니다.
- 표준 문서의 미확인 사항(ROM 에서 새 이름 고르기)은 `bsd 이름 [-s]` 로 해결했습니다. 설치본 `/sdmach` 로의 대조 시험은 R2 가 멈추지 않았으므로 하지 않았습니다.
- 종료: 세 번 모두 QMP `stop`·`quit`, QEMU 종료 확인. 시험 디스크·저장소 디스크 SHA-256 은 시작 전과 같습니다(`88b35f12…`, `7097595f…`).
- 판정: **M8 L3(QEMU) 충족, 다시 만든 m68k 커널이 Workspace 까지 동작합니다.** 기록 `09_validation/reconstruction/m8-m68k-p788-boot-20261109.json`, 화면 `09_validation/images/m68k/logs/l3-boot-20261109/`(무시 대상).
- 한계: QEMU 만이며 실기는 없습니다(D067). 이 커널은 설치본과 같은 바이트이므로 부팅 결과가 재구성 소스의 추가 증거는 아닙니다. 커밋하지 않습니다.

## 789. m68k 결과의 문서 반영과 push 준비 (코딩 전 계획, 2026-11-09)
사용자 지시("관련된 문서들을 update 하고 push 를 위한 준비")에 따릅니다. 커밋·push 는 하지 않습니다.

### 789.1 사실(python·git)
- 작업 트리: 수정 26, 추적 안 된 파일 2645(`09_validation/reconstruction` 2332 포함), 합계 약 48.8 MB, 가장 큰 파일 1.6 MB. `origin/main` 보다 앞선 커밋 4 개는 아직 push 되지 않았습니다(`git ls-remote` 의 `main` 이 로컬 `origin/main` 과 같음).
- 공개 점검: 대기 파일에 `../etc/gcds.cnf` 의 주소·토큰, 홈 경로, 사용자 전자 우편, 사설 주소가 없습니다(`10.0.2.x` 6 건은 QEMU 사용자망 주소; 전자 우편은 원저작 표기 `next.com`·`apple.com` 뿐이며 그대로 둡니다). 07 대기 파일 142 개는 모두 PROVENANCE 행이 있습니다. 스테이지의 07 출처 993 가운데 무시 대상은 `nextdev` 280·`nextdev_private` 34 입니다(x86 과 같은 로컬 전용 입력).
- 재현 문제: 787 의 명령 파일은 `08_build/artifacts/`(무시 대상)에만 있습니다.
- 잘못 생긴 듯한 파일 셋 `=`·`Y`(0 B)·`.text`(22 B, `bindec X- only .data-`)가 저장소 최상위에 있습니다. 사용자 확인 전에는 지우지 않고 커밋 대상에서 뺍니다.

### 789.2 변경(`scratch/p789/apply.py`; 모든 수정은 고정 글자열을 단정)
`README.md`, `02_plan/STATUS.md`, `02_plan/RECONSTRUCTION_PLAN.md` 의 현재 상태 절, `HOWTOCOMPILE.md` 10 절, `HOWTOUSE.md` 6 절, `11_emulation/README.md`, 로컬 전용 `MULTIARCH_RECONSTRUCTION_STANDARD.md`, 새 추적 파일 `06_reconstruction/m68k-l2-compile.cmd`·`m68k-l2-link.cmd`.

### 789.3 push 전 점검
적용 뒤 python 으로: 명령 파일 해시가 787 과 같음, `kr_run.parse_cmdfile` 통과, 문서의 파일 경로·SHA·수치 재확인, 대기 파일 재스캔, 무시 규칙 재확인, 커밋 묶음 제안. 커밋·push 는 사용자 지시 뒤에 합니다.

#### 789.4 codex 검토 판정표(작업 `kli71nzyr`)
내가 틀렸던 것(먼저): ① HOWTOUSE 초안은 `cd` 뒤에 저장소 최상위 기준 명령을 적었습니다. ② "전자 우편 없음" 은 너무 넓었고, 원저작 표기(`next.com`·`apple.com`)는 있습니다. ③ NetInfo 대기는 `c` 만이고 Ctrl+C 는 hostname 대기에만 적혀 있습니다. ④ 스테이징 입력을 빠뜨렸습니다. ⑤ `-o` 경로를 고친 것을 "그대로" 라고 적었습니다.

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| HOWTOUSE 경로 오류 | 초안 열람(`cd` 뒤 `bash 11_emulation/...`) | ✅ 최상위 기준으로 고침 |
| 복사에 새 디렉터리·기존 파일 검사 필요 | 초안 열람; §788 의 단정과 비교 | ✅ `[ ! -e ]` 추가 |
| 스테이징 입력: `s6ln-g1a-stage`+manifest, SDK 와 목록 | `X86[559]='s6ln'`, 경로 존재 python 확인; `stage_m68k.py:564–565` | ✅ 반영 |
| `07_kernel/v183.34/common` 도 필요 | `os.path.exists` False; `overlay_files` 는 없는 디렉터리를 건너뜀(`stage_m68k.py:581–582`) | ❌ 기각(없는 경로) |
| 파서 통과, 새 RID 가능, `src/o` 이름 일치 | `kr_run.py` 의 `parse_cmdfile` 은 빌드 때 호출해 통과(787); `build_ln.py` 가 같은 이름으로 run B 를 돌렸음 | ✅ |
| `-o` 만 고침 | `scratch/p787/build_cc.py` 열람 | ✅ 문구 정정 |
| hostname 은 `c`·Ctrl+C, NetInfo 는 `c` | `QEMU_VM_CONFIGURATIONS.md:99–100` 열람 | ✅ 문구 정정 |
| `fsck` 오류 출력도 봐야 함 | §788.6 | ✅ 반영 |
| 수치 296·3809·613·54/22·22547/22552·18·832196·SHA | 내 run 출력(787·781·788 기록) | ✅ |
| 앞선 커밋 4 개는 로컬 기준 | `git ls-remote` 실행: 원격 `main` = `de3001e3…` = 로컬 `origin/main` | ✅ 확인함 |
| 전자 우편은 있음(원저작 표기) | 전수 python: `next.com`·`apple.com` 도메인뿐, 사용자 주소 0 | ✅ 문구 정정 |
| 앵커 모두 한 번, `.cmd` 공개 가능 | 적용 때 `assert` 로 판정; `.cmd` 는 상대 경로와 `/bin/*` 뿐(`build_cc.py` 단정) | ✅ |
| HOWTO 제목, ROADMAP, `06_reconstruction/README.md`, README 제외 목록 | 각 줄 열람 | ✅ 반영 |

### 789.5 결과 (2026-11-09)
- 적용 뒤 점검(python): `06_reconstruction/m68k-l2-compile.cmd`(RUN 296·EXPECT 296)와 `m68k-l2-link.cmd`(RUN 2·EXPECT 2)가 787 의 명령 파일과 해시가 같고 `kr_run.parse_cmdfile` 을 통과했습니다. 명령 파일의 절대 경로는 `/bin/cc`·`/bin/ld`·`/bin/strip` 뿐입니다. 새 문서의 파일 경로는 모두 있고, 대기 파일 재검사에서 실기 주소·토큰, 홈 경로, 사용자 전자 우편은 0 입니다.
- 사용자 결정: 커밋 4 묶음(권장안), 최상위 `=`·`Y`·`.text` 삭제, README 에 m68k `hostinfo` 화면 추가(`docs/images/qemu-m68k-reconstructed-kernel-hostinfo-20261109.png`).
- 커밋(파일 수): `4d458b3dc` 소스·표 151, `585f2829e` 도구 14, `674040256` 증거·기록 2489, `05c44bef5` 계획·문서 23. 사용자 지시 뒤 `origin/main` 으로 push 했고, 원격 `main` 이 `05c44bef598f7263703bfc694bf3d103451e9256` 로 로컬과 같습니다(이전 커밋 4 개 포함 8 개, fast-forward).
