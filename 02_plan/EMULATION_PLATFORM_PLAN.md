# 에뮬레이터 플랫폼 계획 (i386·SPARC·m68k)

구성 정본: [`11_emulation/QEMU_VM_CONFIGURATIONS.md`](../11_emulation/QEMU_VM_CONFIGURATIONS.md). 이 문서는 목적, 배치, 규칙, 남은 일을 적는다.

## 목적과 범위

세 아키텍처의 OPENSTEP 4.2 커널을 QEMU 에서 돌리고 GDB 로 디버깅할 수 있게 한다. 원본 커널을 에뮬레이터에서 돌린 결과를 커널 분석 증거로 쓰는 일과 복원 커널의 빌드·부팅은 각각 별도 계획이 필요하다(`AGENTS.md`).

## 배치

| 경로 | 추적 | 내용 |
|---|---|---|
| `11_emulation/` | README·구성 문서·MANIFEST·`scripts/` 만 | qemu-NeXT, Previous, 빌드, 펌웨어, 호스트 설정, 기록 |
| `12_archive/openstep-iso-remade/` | 없음(README 만) | 폐지된 작업공간 `openstep-iso-remade` 의 기록 전부. 커널 분석 증거가 아니다 |
| `09_validation/images/<arch>/` | 없음 | VM 디스크 |

분류 이유: `01_resources` 는 커널 분석에서 참고가 금지된 외부 소스 자리이고, `08_build/toolchains` 는 복원 커널용 GCC 2.7 자리이며, `10_tools` 는 이 저장소가 소유한 분석 도구 자리다. 외부 git 저장소와 그 빌드·펌웨어는 성격이 달라 독립 최상위로 둔다. 이 저장소는 public 이라, 중첩 저장소·ROM·설치 디스크·비공개 기록은 git 에서 뺀다.

## 규칙

- `11_emulation/qemu-NeXT` 의 커밋되지 않은 작업 트리 수정은 다른 곳에 작업 트리로 존재하지 않는다. `checkout`·`reset`·`stash`·`clean` 을 하지 않고, 그 안에서 `configure` 하지 않는다.
- 세 VM 은 `build/qemu-NeXT-lab/` 의 바이너리 하나씩만 쓴다. 다시 빌드하면 해시가 바뀌므로 `vm-m68k.sh` 의 해시와 구성 문서 표를 함께 고친다.
- 외부 매체 경로는 `11_emulation/site.conf` 에만 둔다. OPENSTEP_BOOTCD 처럼 위치가 바뀔 수 있는 프로젝트는 이름·크기·해시로만 식별한다.
- 실행 스크립트의 기준은 실제로 설치를 완주한 실행의 인자다.
- 계산은 Python, 설계 변경은 계획 → codex 교차검토 → 재검증 → 코딩 순서.

## 상태 (2026-09-30)

| 머신 | 상태 |
|---|---|
| Intel | 설치 완료 |
| m68k | 설치 완료 |
| SPARC | 설치 준비 완료 |

## 남은 일

1. m68k 설치를 마친다(1단계 뒤 `vm-m68k.sh boot` 로 2단계).
2. SPARC 설치(`vm-sparc.sh install`, `boot cdrom`). GTK 화면에서 설치가 끝까지 되는지 확인한다.
3. 세 설치가 끝난 뒤, 각 설치 디스크의 `/mach_kernel` 을 꺼내 해시와 버전을 대조한다.
4. GDB 용 커널 심볼 파일: 이 GDB 는 Mach-O 를 읽지 못하므로 `03_original/<arch>/inventory` 의 심볼을 아키텍처별 ELF 심볼 파일로 만든다.
5. 머신별 GDB 초기화 파일(아키텍처, SPARC·m68k 의 `set endian big`, 접속 명령).

## SPARC 준비 검토와 계획 (2026-09-30, 코딩 전)

**현상**: `vm-sparc.sh install`(QEMU 11.0.90, GTK, HDD 포함)에서 `boot cdrom` 뒤 두 번 모두 같은 치명 오류로 끝났다. 첫 폴트는 커널 `_kernel_trap`(0xf00a8554) 진입, 트랩 9(`data_access_exception`)였다. 그 처리 중 `_printf` 안에서 트랩 0x29(`data_access_error`)가 겹쳐 QEMU 가 error state 로 종료했다.

**참고 문서**: hifialex, "Installing NeXTSTEP 3.3 (SPARC) in QEMU on Linux"(원문 사본 `11_emulation/records/ref-hifialex-nextstep33-sparc/`). NeXTSTEP 3.3·SS-5 기준이라 OPENSTEP 4.2·SS-20 에 그대로 옮기지 않는다.

| 항목 | 문서 | 우리 | 판단 |
|---|---|---|---|
| QEMU 버전 | 8.x 이후 sun4m ESP-SCSI/DMA 회귀(QEMU issue 2620, 2674)로 설치 중 멈춤. 7.2.x 사용 | 11.0.90. 확인된 성공은 6.2(직렬 콘솔, HDD 없음)뿐 | **의심 1순위** |
| 화면 깊이 | 24 비트에서 커널 panic, `-g 1024x768x8` | sun4m 기본값이 8 비트(`hw/sparc/sun4m.c` 892–894 행, `graphic_depth` 초기값 0) | 차이 없음 |
| 콘솔 | GTK 기본 화면 | 성공한 측정은 `-nographic`, 실패는 GTK | 가능성 있음 |
| 호스트 CPU 고정 | `taskset -c 0`: 다중 코어에서 디스크 I/O 경쟁으로 멈춤 | 없음 | 추가 |
| RTC | `-rtc base=utc,clock=host` | 없음 | 추가 |
| 디스크 형식 | qcow2 + 단계별 스냅샷 | raw | qcow2 로 전환(디스크가 아직 비어 있음) |
| 캐시 | `cache=writethrough` | 기본값 | 추가 |
| SCSI ID | 디스크 3, CD 6 | 같음 | 차이 없음 |
| 기계·PROM | SS-5 + `ss5.bin` | SS-20 + OBP 2.22 (6.2 에서 CD 부팅 확인) | 유지 |
| 설치 뒤 | fstab `sd0a`→`sd1a`, hostconfig 정적 값, resolv.conf `10.0.2.3`, lookupd 순서, NetInfo `/machines/broadcasthost` 의 `serves` 삭제 | 해당 없음(설치 전) | 설치 뒤 확인 목록. NetInfo 항목은 m68k 의 부모 바인드 대기에도 대안 |

**계획 — 한 번에 하나씩 바꾸는 부팅 시험**(모두 CD 읽기 전용, `-snapshot`, 설치 언어 선택 `--->` 도달 여부로 판정)
- S1: QEMU 6.2, `-nographic`, CD 만 — 기록된 성공 조건 재현.
- S2: QEMU 11.0.90, `-nographic`, CD 만 — 버전만 바꿈.
- S3: QEMU 11.0.90, GTK, CD 만 — 콘솔만 바꿈.
- S4: 통과한 조합 + HDD.
- 그 결과로 SPARC 용 QEMU 와 콘솔을 정하고, `vm-sparc.sh` 에 `taskset -c 0`, `-rtc base=utc,clock=host`, `cache=writethrough`, qcow2 디스크를 반영한다. 11.0.90 이 실패하면 SPARC 는 검증된 6.2(보관 바이너리) 또는 문서가 권하는 7.2 를 쓴다.

**codex 교차검토 항목**
- QS1: 이 QEMU 소스에서 sun4m 기본 화면 깊이가 8 비트이고, SS-20 의 기본 NIC 모델이 lance 인가.
- QS1 판정(codex gpt-6-astra, 원문 재확인): ✅. `sun4m.c` 1110 행 `default_display = "tcx"`, 886–893 행 기본 1024×768×8, 303 행 `qemu_find_nic_info("lance", true, NULL)`, `vl.c` 1446–1451 행 기본 `-net nic -net user`, 빌드의 `config-host.h` 에 `CONFIG_SLIRP` 있음. 화면 깊이와 NIC 은 문서 구성과 차이가 없다.

**사용자 지시(2026-09-30): 기계 차이일 수 있으니 문서의 펌웨어로 문서의 하드웨어 설정부터 시도한다.**
- `ss5.bin` 확보: 문서 링크 `https://vtda.org/bits/ROMs/Sun/ss5.bin`, 262,144 바이트, SHA-256 `e7f40845504c65f4011278aa3e97a9810aa36775e6c199b715839fbc25eec45e` (`11_emulation/firmware/sun-ss5-ss5.bin`).
- 시험 A: 문서 명령 그대로(`taskset -c 0`, `-M SS-5 -m 64 -bios ss5.bin`, `-rtc base=utc,clock=host`, 디스크 unit 3·CD unit 6 `cache=writethrough`, `-net nic,model=lance -net user`, `-display default -g 1024x768x8`). 바꾸는 것은 ISO(`os42j.iso`)와 QEMU(11.0.90, 기계 차이만 떼어 보려고)뿐. 디스크는 `-snapshot`.
- 시험 B(A 에서 CD 를 못 읽을 때만): CD 를 512 바이트 블록 `scsi-cd` 로.
- codex 확인 QS2: 이 QEMU 에서 문서 명령의 `-drive ...,bus=0,unit=N`(if 생략)이 SS-5 의 SCSI 에 붙는가, SS-5 의 기본 CPU·최대 메모리, `-g 1024x768x8` 이 받아들여지는가.
- QS2 판정(codex, 원문 재확인): ✅. `if=` 생략 드라이브는 SCSI(`sun4m.c` 1108), SS-5 기본 CPU `Fujitsu-MB86904`(1147)·최대 256 MiB(1142), `scsi-cd` 기본 블록 2048 이고 `physical_block_size` 가 있으면 그 값(`scsi-disk.c` 2640–2654).

**QEMU 이슈 2620·2674 (원문 `11_emulation/records/ref-qemu-issues/`)**
- 2620 "Freezes when installing NeXTSTEP 3.3 or OPENSTEP 4.2 RISC version in qemu-system-sparc"(열림). 2024-11-13 댓글: `-M SS-5 -bios ss5-170.bin`(실제 Sun PROM)에서 우리와 같은 `Trap 0x29 (Data Access Error) while interrupts disabled, Error state`(PC `f0002198`). 같은 댓글에서 실제 PROM 없이 기본 OpenBIOS + `scsi-cd,...,physical_block_size=512` + `-vga cg3 -g 1024x768x8` + `taskset -c 1` 로 NeXTSTEP 3.3 설치가 진행됨. 
- 2674 "NextSTEP 3.3 for Sparc graphical glitches"(열림): 설치 뒤 TCX 화면 깨짐(창을 오른쪽으로 옮길 때). 2026-01-07 댓글(2989568921): `-M SS-20` + 실제 PROM `ss20-2.25.bin` + `TI SuperSparc 50`(CG14 패치 트리)에서도 같은 `Trap 0x29` 치명 오류.
- QS3 판정(codex): 2620 인용 셋은 원문과 일치. 2026-01 댓글을 2620 으로 적은 것은 내 오류였고 실제로는 2674 의 댓글이다(원문 재확인).
- 판단: 크래시는 기계(SS-5/SS-20)보다 **최신 QEMU + 실제 Sun PROM** 조합과 관련이 커 보인다. 실제 PROM 으로 성공한 기록은 QEMU 7.2(hifialex)와 6.2(우리 측정)뿐이다. 따라서 시험 A(11.0.90 + SS-5 + `ss5.bin`)는 같은 오류가 날 가능성이 높다.

**시험 계획 (각각 `taskset -c 0`, CD 읽기 전용, 디스크 `-snapshot`, 설치 언어 선택 `--->` 도달로 판정)**
- P1: QEMU 11.0.90, `-M SS-5`, 기본 OpenBIOS, CD `scsi-cd` 512 바이트, `-vga cg3 -g 1024x768x8` — 이슈의 우회가 OPENSTEP 4.2 에도 통하는가.
- P2: QEMU 6.2(보관), `-M SS-5 -bios ss5.bin`, 문서 명령 그대로 — 문서 하드웨어가 옛 QEMU 에서 되는가.
- P3: QEMU 6.2, `-M SS-20` + OBP 2.22 + HDD, CD 512 바이트 — 언어 선택까지 간 조합으로 설치가 되는가.
- codex 확인 QS3: 위 이슈 인용(명령, 오류, 결과)이 저장한 원문과 일치하는가.

**P1–P3 결과 (2026-09-30, `11_emulation/records/sparc-p-tests-20260930/`)**: 세 조합 모두 `boot:` 뒤 설치 언어 선택 `--->` 에 도달했다(직렬 콘솔, 디스크 `-snapshot`, 시험 전후 디스크 해시 동일). P1 = QEMU 11.0.90 + SS-5 + OpenBIOS + CD 512 바이트 + cg3, P2 = QEMU 6.2 + SS-5 + `ss5.bin`, P3 = QEMU 6.2 + SS-20 + OBP 2.22 + CD 512 바이트. 실패한 조합은 QEMU 11.0.90 + 실제 PROM(OBP 2.22) 이었다. 설치 완주는 아직 확인하지 않았다.
- 제안: 설치는 P1 구성(세 VM 이 같은 빌드). 멈추면 P2. `vm-sparc.sh` 변경 전 codex 교차검토.

**`vm-sparc.sh` 변경 계획 (사용자 승인 2026-09-30, 코딩 전)**
- `taskset -c 0` 으로 실행. `-M SS-5 -m 64`, `-bios` 없음(OpenBIOS), `-vga cg3 -g 1024x768x8`, `-rtc base=utc,clock=host`.
- CD: `-device scsi-cd,channel=0,scsi-id=6,drive=cd,logical_block_size=512,physical_block_size=512`, 읽기 전용.
- HDD: SCSI 3, qcow2 `09_validation/images/sparc/openstep42-sparc-hdd.qcow2`(1 GiB), `cache=writethrough`. 전부 0 인 raw 디스크는 지운다. `vm-common.sh` 의 디스크 경로 함수가 확장자를 받게 한다.
- `install` 은 `-boot d`, `boot` 는 `-boot c`. 기본 NIC(lance, user) 유지.
- codex 확인 QS4: 이 QEMU 에서 (a) SS-5 의 `-vga cg3` 가 1024×768×8 을 받아들이는가, (b) `-boot c`/`-boot d` 가 OpenBIOS 에 어떤 방식으로 전달되는가(fw_cfg).
- QS4 판정(codex, 원문 재확인): ✅. cg3 1024×768×8 허용(`sun4m.c` 899–915), 기본 펌웨어 `openbios-sparc32`(80, 688), `-boot` 첫 글자가 fw_cfg `FW_CFG_BOOT_DEVICE` 로 전달(1087).
- 결과: `vm-sparc.sh` 를 위 구성으로 바꿨다. `vm-sparc.sh install --snapshot --serial` 이 설치 언어 선택에 도달했고, QEMU 는 호스트 코어 0 에 묶였으며, qcow2 디스크는 바뀌지 않았다(`11_emulation/records/sparc-vm-script-check-20260930/`). 빈 raw 디스크는 전부 0 임을 확인하고 지웠다.

**정정 (사용자 지적 2026-09-30)**: 설치 언어 선택은 실패한 조합에서도 정상이었다. 크래시는 그 뒤 설치 단계에서 났다. P1–P3 의 판정 기준(언어 선택 도달)은 문제를 가리지 못한다.

**재시험 계획 (코딩 전)**
- 판정 지점을 설치기 뒤로 옮긴다. 직렬 콘솔에서 `--->` 가 나올 때마다 직전 화면을 기록하고 `1` 을 보낸다(언어, 설치 준비, 대상 디스크). 디스크 준비와 1단계 파일 복사까지 진행한다. 끝 조건: QEMU 치명 오류, panic, 1단계 완료 문구, 30 분 초과, 모르는 프롬프트.
- 순서: F0 = 실패했던 조합(QEMU 11.0.90 + SS-20 + OBP 2.22 + CD 512 + HDD)을 직렬 콘솔로 재현해 죽는 단계를 잡는다. 그다음 P1(QEMU 11 + SS-5 + OpenBIOS), P2(6.2 + SS-5 + `ss5.bin`), P3(6.2 + SS-20 + OBP 2.22)가 그 단계를 넘는지 본다.
- 모두 `taskset -c 0`, 디스크 `-snapshot`, ISO 읽기 전용.
- codex 확인 QS5: `-snapshot` 과 `readonly=on` 조건에서 설치기가 디스크를 포맷·복사해도 qcow2·raw 원본 파일과 ISO 가 바뀌지 않는가(QEMU 소스 기준).

**SPARC 설치 뒤 부팅 (2026-09-30, 코딩 전)**
- 1단계 설치(SS-5, OpenBIOS, 디스크 SCSI 3) 완료, qcow2 스냅샷 `phase1-done`. `vm-sparc.sh boot`(`-boot c`, 디스크 SCSI 3)에서 OpenBIOS 가 `Trying disk:a... / Trying disk... / No valid state has been set by load or init-program` 으로 부팅하지 못했다.
- 참고(QEMU 이슈 2620, randrianasulu 2024-11-13): 설치는 디스크 `bus=0,unit=3`(댓글 2207999780), 설치 뒤는 `-M SS-5 -hda <disk>`(= SCSI 0)로 데스크톱까지 부팅(댓글 2208081370). hifialex: 실제 PROM 으로 SCSI 3 부팅 시 fstab `sd0a`→`sd1a` 수정 필요.
- 변경: `vm-sparc.sh boot` 는 디스크를 SCSI 0 에 붙인다(`install` 은 SCSI 3 유지). CD 는 SCSI 6 에 유지(2단계가 CD 를 읽는다).
- codex 확인 QS6: 이 QEMU 의 SS-5 에서 `-hda` 가 SCSI bus 0 unit 0 으로 붙는 것과 `-device scsi-hd,scsi-id=0` 이 같은 위치인가.
- 결과: 디스크를 SCSI 0 에 두자 OpenBIOS 가 설치본에서 부팅해 2단계가 진행됐다.
- 이어서 `No Display drivers loaded!` 반복. 참고 자료대로 설치 뒤에는 `-vga cg3` 를 쓰지 않는다: 이슈 2620 은 설치에만 cg3, 설치 뒤는 `-vga` 없는 `-hda` 부팅(기본 TCX), hifialex 도 기본 TCX `-g 1024x768x8`. 변경: `vm-sparc.sh boot` 는 기본 TCX 1024×768×8(`-vga` 없음), `install` 은 cg3 유지. TCX 기본값은 QS1 에서 확인됨.

**SPARC 설치를 QEMU 6.2 로 (사용자 결정 2026-09-30, 코딩 전)**
- 2단계 멈춤(원인 추적 메모 `11_emulation/SPARC_INSTALL_HANG_NOTES.md`)의 우회로, SPARC 설치만 QEMU 6.2(Ubuntu `1:6.2+dfsg-2ubuntu6.31`)로 한다. 비교가 깨끗하도록 바꾸는 것은 QEMU 바이너리 하나다.
- 바이너리를 `11_emulation/qemu-6.2-ubuntu/qemu-system-sparc` 로 복사하고 SHA-256 `1760627d…e7ea3` 로 고정. 데이터 파일(OpenBIOS·TCX·cg3 FCode)은 호스트 `qemu-system-data 6.2` 의 `/usr/share/qemu`.
- `vm-sparc.sh --qemu62`: 같은 구성(SS-5, OpenBIOS, install=SCSI 3·cg3, boot=SCSI 0·TCX, CD 512, `taskset -c 0`, RTC)을 6.2 로 실행.
- 디스크: 현재(11 에서 멈춘) 상태를 스냅샷 `phase2-hang-q11` 로 남기고 `phase1-done` 으로 되돌려 2단계를 6.2 로 다시 한다.
- 확인: qcow2 헤더 incompatible features 가 0 이어야 6.2 가 연다(Python 으로 헤더 직접 읽기). codex 확인 QS7: 11.0.90 `qemu-img` 가 만든 이 qcow2 가 기능 비트 측면에서 6.2 에 호환되는가.
- 검증(2026-09-30): QS7 codex 인용 줄(`block/qcow2.h:255–264`, `qcow2.c:3804–3842`, `:1383–1387`, `:520–523`, `qcow2-snapshot.c:169–173`, `qcow2-cluster.c:1052–1054`)을 직접 열어 확인 → ✅. 실측: 11.0.90 `qemu-img` 로 만든 빈 qcow2 를 6.2 가 열고 CD 로 커널 a.out 적재까지 진행. 실제 디스크 `-snapshot` 부팅에서 6.2 로 2단계 복사 화면 도달. `phase2-hang-q11` 스냅샷 후 `phase1-done` 으로 되돌림, `qemu-img check` 오류 없음.
- 결과(2026-09-30): 6.2 로 2단계 설치 완주, 기본 설정 후 종료 → 스냅샷 `install-done`. 11.0.90 `-snapshot` 부팅에서 Workspace 도달(느림), GDB `target remote` 로 pc·psr·sp 읽기 확인. 세 머신 설치 완료 → 다음은 설치된 `/mach_kernel` 추출·해시·버전 대조.

## 설치된 커널 대조 계획 (2026-09-30, 코딩 전)

목적: 세 VM 디스크에 설치된 커널 파일이 분석 기준(`03_original/<arch>/binaries/mach_kernel`)과 같은 바이트인지 확인한다. 플랫폼 준비 검사다. 에뮬레이터 실행 결과를 커널 의미의 증거로 쓰지 않는다. 디스크는 읽기만 한다.

입력(사실 확인 끝):
- i386 `openstep42-i386-hdd.raw`, m68k `openstep42-m68k-hdd.raw` 는 그대로 읽는다. SPARC 는 qcow2 를 `qemu-img convert -O raw` 로 scratch 에 푼다. 스냅샷 `install-done` 을 `-l` 로 따로 풀어 현재 층과 해시가 같은지 확인한다.
- 세 디스크 모두 NeXT 라벨 `dlV3`: secsize 1024, front 160, 파티션 0 base 0, 4.3BSD, bsize/fsize 8192/1024 → UFS 시작 = (160+0)×1024 = 163840. 슈퍼블록 매직 `0x00011954` 는 세 디스크 모두 **big-endian**(i386 포함), 첫 위치가 163840 으로 라벨 계산과 같다.
- 라벨 체크섬은 라벨 사본의 `label_blkno`(0x04) 를 0 으로 놓고 계산할 때 모든 사본에서 저장값과 같다. SPARC 는 블록 0·15 사본이 없다(블록 0 은 0 으로 채워짐). i386 은 MBR 파티션 항목이 모두 0 이다.
- m68k 라벨의 부팅 커널 이름은 `sdmach`, i386·SPARC 는 `mach_kernel`. 그래서 루트의 커널 후보(`mach_kernel`, `sdmach`, `odmach`, 이름에 mach·kernel 이 든 정규 파일)를 모두 뽑는다.

방법:
1. 도구 `10_tools/runtime/installed_kernel_identity.py`(새로 작성, 읽기 전용): 라벨 파싱·체크섬, 라벨 계산 UFS 시작과 매직 첫 위치 일치 검사, UFS1 big-endian 읽기(직접·1·2·3단 간접 블록, 빈 블록 0 채움, 마지막 블록은 크기만큼), 루트 목록, 커널 후보 추출, Fat(`CAFEBABE`) 이면 슬라이스별 분리, 모든 해시·크기·차이는 Python.
2. 읽기 검증 두 가지: (a) 같은 코드로 `os42j.iso`(UFS 시작 163840)의 `/mach_kernel` 을 읽어 provenance SHA-256 `f3b57f87…` 와 같아야 한다. (b) 추출한 각 파일을 OPENSTEP_BOOTCD 의 기존 `ufsread.py cat` 결과와 바이트 비교한다(독립 구현 교차 확인). 둘 중 하나라도 어긋나면 결과를 쓰지 않는다.
3. 대조: 각 후보의 SHA-256 을 `03_original` 기준과 비교. 버전 문자열은 바이트에서 `NeXT Mach ` 로 시작하는 NUL 종료 문자열을 뽑는다. i386 은 추가로 `os42j.iso` Fat 의 i386 슬라이스(인덱스 1)와 OPENSTEP_BOOTCD 부팅 ISO 의 `/mach_kernel` 과도 비교한다(설치 매체가 이 ISO 다).
4. 다르면: 바이트 차이 개수·구간을 Python 으로 세고, Mach-O load command 로 각 구간이 속한 세그먼트·섹션을 적는다. 해석(패치 성격 등)은 가설로만 적는다.

산출:
- 추출 파일: `09_validation/images/<arch>/extracted/`(무시됨, 원본 저작물).
- 보고: `09_validation/runtime/installed-kernel-identity-20260930.json` 과 요약 md. 해시·크기·버전 문자열·비교 결과·확립하지 않는 것.

확립하지 않는 것: 실행 중인 커널 이미지가 파일과 같다는 것, 런타임 동작.

codex 교차검토 (QK1, gpt-6-astra: "검증 (a)+(b) 로 잘못된 추출을 잡기에 충분한가") 판정:

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| ISO 의 UFS 는 bsize/fsize 8192/2048, 디스크는 8192/1024 라 (a) 는 fsize 1024 경로를 시험하지 않는다 | Python 으로 ISO 슈퍼블록 @163840+8192 를 읽음: bsize 8192, fsize 2048, nindir 2048 | ✅ 채택 |
| 직접+1단 간접 용량 16,875,520 B 라 커널 크기에 2단 간접은 필요 없다 | Python: 12×8192 + 2048×8192 = 16875520 | ✅ |
| (b) 는 독립이 아니다: provenance 의 ISO 추출도 같은 OPENSTEP_BOOTCD 리더를 썼다 | `provenance.json:54` `cd_structure_tooling` 확인 | ✅ 채택: (b) 는 보조 교차 확인으로만 쓰고, 독립 근거로 아래 할당 검사를 더한다 |
| ufsread 는 0 인 간접 포인터가 논리 위치를 차지하지 않아 뒤 데이터가 밀릴 수 있다 | `ufsread.py:67–68`(`frag == 0` 이면 아무것도 넣지 않고 return), `:80–89`(ib[0] 다음 바로 ib[1]) 확인 | ✅ 채택: 새 도구는 논리 블록 번호로 주소를 구하고, 구멍(0 포인터)이 있으면 추출을 멈춘다 |
| 이름 첫 일치만 쓰고 symlink 를 풀지 않는다 | `ufsread.py:155–167` lookup, `:233–234` symlink 분기가 `pass` 확인. codex 는 `:232` 라 했으나 그 줄은 `readfile` 호출(한 줄 차이) | ⚖️ 채택(줄번호는 내 확인값): 루트 이름 중복이면 멈춤, 모드 확인, symlink 는 대상 기록, 하드 링크는 inode 번호로 묶음 |
| 삭제된 디렉터리 항목·할당 상태를 검사하지 않는다 | ufsread 전체에 cylinder group 읽기 없음(`cg` grep: `cgstart` 계산뿐) | ✅ 채택: inode 의 iused 비트, 데이터·간접 프래그먼트의 free 비트(할당됨)를 cg 맵으로 확인 |
| 슈퍼블록 첫 매직만으로는 부족 | 라벨 계산 163840 = 매직 첫 위치는 이미 확인. 백업 슈퍼블록·파티션 경계는 미확인 | ✅ 채택: cg0 백업 슈퍼블록 기하 필드 일치, fs 크기 ≤ 파티션 크기 |
| (추가, 내 판단) 파일 끝 프래그먼트 | codex 제안 반영 | `di_blocks`(512 B 단위)가 데이터+간접 프래그먼트 수에서 계산한 값과 같아야 한다 |

결과 (2026-10-01, `09_validation/runtime/installed-kernel-identity-20261001.json`):
- SPARC: 설치된 `/mach_kernel` = `03_original/sparc` (SHA-256 `287ababa…`, mk-183.34 RELEASE_SPARC 1997-04-27). 변환한 raw 는 스냅샷 `install-done` 과 같은 해시.
- m68k: 디스크에 `/mach_kernel` 이 없다. `/sdmach`·`/odmach`·`/private/tftpboot/mach` 가 한 inode(nlink 3)이고 `03_original/m68k` (`dff6c51c…`, RELEASE_M68K)와 같다. 라벨의 부팅 커널도 `sdmach`.
- i386: 설치된 `/mach_kernel`(`/private/tftpboot/mach_kernel` 과 같은 inode) = OPENSTEP_BOOTCD 설치 CD 의 i386 슬라이스 = `os42j.iso` i386 슬라이스(mk-183.34, 1997-04-27)에 12 바이트 PIC 패치. `patch_kernel_pic.py` 의 PATCHES 를 원본 슬라이스에 적용하면(헤더의 __TEXT vmaddr 0x100000, fileoff 0) 설치본과 같다. **`03_original/x86`(mk-183.34.4, 1999-01-26, 1,117,920 B)와는 다른 빌드다.** 실기(R0–R4)는 기준 커널을 돌리지만 i386 VM 은 아니다.
- 읽기 검증: `os42j.iso` 컨테이너 SHA-256 이 provenance 와 같음, 추출 파일 전부 `ufsread.py` 와 바이트 동일, 세 디스크 전체 디렉터리 14,628 개 파싱 오류 0, 커널 inode 의 이름 수 = nlink.
- 바이트에서 확인한 형식 사실(계획 때 가정과 달랐던 것): cylinder group 은 고정 배치(cg_magic @980, inode 맵 @724, free 맵 @984, 네 이미지 1,153 개 cg 에서 맵 popcount = cg_cs), 디렉터리 블록 1024 B, `fs_fsbtodb` 0 이라 `di_blocks` 는 프래그먼트 수, 부팅 CD 는 라벨 UFS(3016704) 앞에 다른 UFS(231424, El Torito 플로피로 보임)가 있어 CD 참조에는 "첫 매직 = 라벨 시작" 검사를 쓰지 않는다.
- 남은 결정(사용자): i386 VM 에서 기준 커널(mk-183.34.4)로 디버깅하려면 그 커널을 VM 디스크에 넣는 별도 계획이 필요하다.

## i386 VM 에 분석 기준 커널 추가 계획 (2026-10-01, 사용자 승인 "신중하게 진행", 코딩 전)

목표: i386 VM 디스크에 `03_original/x86/binaries/mach_kernel`(mk-183.34.4, SHA-256 `33469393…`)을 **바이트 그대로** 새 이름 `/mach_kernel.183.34.4` 로 넣는다. 기존 `/mach_kernel`(1997 + PIC 수정)은 그대로 두어 되돌아갈 길로 쓴다. 부팅 프롬프트에서 `hd()mach_kernel.183.34.4` 로 고른다(디스크의 `/usr/standalone/i386/BootHelp.txt`: `<<device>kernel> <arguments>`, 예 `hd(1,b)mach_kernel`).

사전 사실(바이트로 확인):
- 오프라인 쓰기 도구 `ufswrite.py`(OPENSTEP_BOOTCD)는 쓰지 않는다. free 비트맵 위치를 `cgstart`(회전 오프셋 포함) 기준으로 계산하는데, 전체 트리가 참조하는 프래그먼트 중 free 로 표시된 수를 세면 `cgbase`(`frag % fpg`) 기준이 os42j.iso·i386 디스크 모두 0, `cgstart` 기준은 i386 디스크 700 이다. i386 디스크는 64 개 cg 중 60 개가 회전돼 있어 그 도구는 사용 중 블록을 할당할 수 있다.
  - 부수 발견: 그 도구로 고친 `os42j_boot.iso` 는 중복 참조 0, 참조 중인데 free 표시 171 프래그먼트(EIDE_reloc 42×2 등). 원본 os42j.iso 는 0. 읽기 전용 매체라 설치 결과에는 영향이 없었다(i386 디스크 0).
- 대신 **게스트가 직접 복사**한다: 설치된 시스템에 `/usr/filesystems/CDROM.fs`(이름 "CDROM (ISO 9660)", `CDROM_reloc` 에 Rock Ridge 코드)가 있다. 할당·회계는 게스트 파일시스템 코드가 한다.
- 기준 커널 `_intr_handler`(0x18c85c)에도 PIC 수정 대상과 같은 코드가 있다: IRQ15 에서 슬레이브 ISR 만 보고 스퓨리어스면 EOI 없이 `jmp 0x18c9d0`(0x18c89f–0x18c8a5). 즉 **수정하지 않은 기준 커널은 QEMU 에서 IDE 인터럽트가 영구히 잠길 수 있다**(OPENSTEP_BOOTCD `06_analysis/01_pic_interrupt_bug.md` 의 관측 경로). 이번 단계는 원본 그대로 넣고, 잠김이 실제로 보이면 수정본을 별도 파일로 둘지 사용자 결정으로 넘긴다.
- 크기 1,117,920 B = 블록 137 개(1 단 간접 필요), 루트 파일시스템 여유는 충분.

절차:
1. 백업: 디스크를 `09_validation/images/i386/openstep42-i386-hdd.before-kernel-add.raw` 로 복사, 두 파일 SHA-256 일치 확인(`be4c7679…` 이어야 한다, 04절 대조 때 값).
2. 전달 ISO: `genisoimage -R -V XFER` 로 `09_validation/images/i386/xfer-mk-183.34.4.iso`(무시됨)에 `mach_kernel.183.34.4` 하나. `isoinfo -R -x` 로 되읽어 SHA-256 이 기준과 같아야 한다.
3. `vm-i386.sh boot --cd FILE`: `boot` 모드에서 IDE 2 의 CD 를 FILE 로 바꾼다(다른 구성 그대로). `--` 뒤에 IDE 장치를 넣지 않는 규칙 유지.
4. 사용자(게스트 안): 로그인 → Terminal 에서 root(`su`) → CD 가 마운트된 경로 확인(`df`) →
   `cp /XFER/mach_kernel.183.34.4 /mach_kernel.183.34.4` → `chmod 444 /mach_kernel.183.34.4` → `cmp` 로 CD 원본과 비교 → `sync` → 전원 끄기.
5. 호스트 검증(읽기 전용): `installed_kernel_identity.py` 로 새 파일 SHA-256 = 기준, 기존 `/mach_kernel` 해시 불변(`00e49892…`), 모든 cg 맵 = cg_cs, 전체 트리 참조 프래그먼트 중 free 표시 0·중복 0.
6. 사용자: `vm-i386.sh boot-nocd` → `boot:` 에서 `hd()mach_kernel.183.34.4 -v` → `hostinfo` 가 `mk-183.34.4 … 1999` 인지 확인. 그 뒤 나(GDB): 사용자가 알려 준 뒤에만 붙여 PC 가 커널 범위인지 확인.

되돌리기: 백업 raw 를 제자리로 복사(해시 확인). 기존 커널 파일은 건드리지 않으므로 `boot:` 에서 Enter 만 치면 지금과 같은 부팅이다.

codex 교차검토 (QK2, gpt-6-astra: "1–6 단계로 VM 이 부팅 불가·조용한 손상이 될 수 없고 잘못된 복사는 부팅 전에 잡힌다") 판정:

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 5 단계 검사가 6 단계 전에 강제되지 않는다. 도구는 차이를 출력만 하고 실패로 끝나지 않으며 새 경로의 존재를 요구하지 않는다 | `installed_kernel_identity.py:526`(비교 루프), `:559`(출력만) 확인. 종료 코드는 구조 오류일 때만 0 이 아니다 | ✅ 채택: 기대 해시를 받아 하나라도 다르면 0 이 아닌 코드로 끝나는 검증 도구를 따로 두고, 통과해야만 6 단계 |
| 도구는 약속한 파일시스템 전체 검사를 하지 않는다(루트 후보만, cg 는 필요할 때만, 소유권 추적 없음) | `:441` `extract_image` 는 루트만, `:197` `cg()` 는 요청된 cg 만, `:279` 는 할당 비트만 확인. 전체 감사는 이번 세션에 임시 스크립트로만 했다 | ✅ 채택: 전체 트리 감사(중복 참조 0, 참조 중인데 free 0, 모든 cg 맵 = cg_cs, 도달 inode 의 iused)를 도구 함수로 넣는다 |
| `sync → 전원 끄기` 가 불충분 | 계획 4 단계 문구 확인 | ✅ 채택: Workspace 의 Power Off 로 정상 종료하고 `It's safe to turn off` 화면 뒤에만 QEMU 종료. 비정상 종료면 기존 커널로 부팅해 복구 후 다시 검증 |
| 정확한 복사여도 6 단계에서 IDE 잠김이 날 수 있으니 첫 부팅은 `--snapshot` | 계획의 PIC 항목(`:180`)과 `vm-common.sh:62` 확인 | ✅ 채택: 첫 기준 커널 부팅은 `boot-nocd --snapshot` |
| `--cd` 는 `boot` 에만, IDE 인덱스 유지 | `vm-common.sh:20` 옵션 파서, `vm-i386.sh:15,21` 확인 | ✅ 채택 |
| 백업·복원은 QEMU 가 꺼진 상태여야 한다 | — | ✅ 채택(사실상 기존 규칙, 명시) |
| Rock Ridge·부트 선택기 문제는 근거 없음 | — | ⏭️ 해당 없음. 대신 ISO 를 `isoinfo -R` 로 되읽어 확인하고, 게스트에서 `cmp` |

진행 (2026-10-01): 백업 `openstep42-i386-hdd.before-kernel-add.raw` = 원래 디스크(`be4c7679…`). 전달 ISO 를 `isoinfo -R -x` 로 되읽어 기준과 같음. 사용자가 게스트에서 `cp`·`cmp` 후 종료. 게이트 `verify_i386_kernel_add.py` 통과(`09_validation/runtime/i386-kernel-add-verify-20261001.json`): 감사 오류 0, `/mach_kernel.183.34.4` (inode 364, 0444, 1,117,920 B) = 기준, `/mach_kernel` 불변. 참조 프래그먼트 +1110 = 커널 1104(데이터 137 + 간접 1 블록 × 8) + 기타 6, inode +2. 다음: `boot-nocd --snapshot` 으로 첫 부팅.

첫 부팅 결과 (2026-10-01, `boot-nocd --snapshot`, `hd()mach_kernel.183.34.4 -v`): 커널은 지정한 파일로 올라왔다. 부팅 중 `hc0: interrupt timeout, cmd: 0xc4`(READ MULTIPLE, status 0x58 = DRDY|DSC|DRQ) → 재시도 → `hc0: interrupt timeout, cmd: 0xec` → `hc0: ATA drive 0 is not present.` 로 멈춤(사용자 화면 `report_001.png`). QMP `info pic`(읽기 전용):
```
pic1: irr=40 imr=2f isr=00 hprio=0 irq_base=48 rr_sel=1 elcr=0c fnm=0
pic0: irr=04 imr=b8 isr=04 hprio=0 irq_base=40 rr_sel=1 elcr=00 fnm=0
```
슬레이브에 IRQ14 대기(irr 0x40, 마스크 열림), 마스터는 cascade 대기(irr 0x04, 마스크 열림)인데 마스터 ISR 비트 2(0x04)가 남아 전달되지 못한다. PIC 결함 분석 문서의 잠김 상태와 같은 모양(그 문서는 IRQ15, 여기는 IRQ14). 즉 원본 기준 커널은 이 QEMU 에서 IDE 가 잠긴다. 디스크는 `-snapshot` 이라 기록되지 않았다.

## UFS 쓰기 도구 검토 (2026-10-01)

OPENSTEP_BOOTCD 도구의 결함(이미지 바이트로 확인): ① `ufswrite.py`·`ufsfsck.py` free 비트맵 위치를 `cgstart` 기준으로 계산(올바른 `cgbase` 기준이면 참조 중 free 0, 도구 기준 i386 700) ② `ufs_cg.py` cg 를 2048 B 만 읽음(i386 cg 크기 3072, free 맵 끝 3000) ③ `ufswrite.py` uid/gid 를 112/116 에 씀(실제 4/6: `/me` inode 에 uid·gid 20) ④ 직접 블록 뒤 마지막 블록을 프래그먼트로 할당 ⑤ `ufsread.py` 0 간접 포인터에서 논리 위치 밀림.

`ostrich/nextufs`(MIT 표기, 커밋 `6ef2908` 2026-04-28, C 약 2.3 만 줄) 검토, scratch 복사본에서만 실행:
- 라벨 사본 위치(7680 간격 4 벌), cg 배치 상수(@724/@980/@984), cg 크기(슈퍼블록 `cg_size`), 프래그먼트 → `cg×fpg + local`(cgbase) 모두 측정과 같다. 간접 블록 3 단, `mkfile --from-file`, chmod/chown 지원.
- `info` 가 세 디스크의 라벨(7680/0/15360)·slice 163840 을 맞게 찾는다. `fsck -n` 세 디스크 모두 이상 없음, i386 `26928 files, 232867 used` = 우리 감사 inode 26928·참조 232867.
- `mkfile --from-file` 로 PIC 수정본(12 B, SHA-256 `304cb696…`)을 i386 복사본에 넣음: 우리 감사 오류 0, fsck 이상 없음, 내용 해시 일치, 배치 = 게스트 `cp` 결과와 같은 1104 프래그먼트(데이터 137 + 간접 1 블록), uid/gid @4/6 = 0, 참조 +1104. 바뀐 영역은 cg 0 데이터·헤더/맵·inode 블록과 1 차 슈퍼블록뿐, front porch(라벨·부트) 불변.
- fsck 가 cg 5 의 `cg_b[0][0]` 을 1 늘린 손상을 `SUMMARY INFORMATION BAD` 로 잡는다. 단 `-n` 에서도 종료 코드 0 → 출력으로 판정해야 한다.
- 주의: fsck 코드는 4.3BSD fsck 구조(`pass5`, `<ufs/fs.h>`)인데 원 저작권 표기가 없다. 코드를 이 저장소에 들여오지 않고 고정 커밋을 빌드해 도구로만 쓰거나 참고만 한다.

## i386 디스크에 PIC 수정본 기준 커널 넣기 (2026-10-01, 사용자 결정: nextufs 사용, 코딩 전)

- 도구: `ostrich/nextufs` 커밋 `6ef2908` 을 `11_emulation/nextufs/`(무시됨)에 두고 빌드. 이 저장소에는 코드를 넣지 않는다. 실행 파일 SHA-256 을 MANIFEST 에 기록.
- 커널 파일: `10_tools/runtime/make_i386_pic_kernel.py` 가 `03_original/x86` 에서 만든다. 원래 바이트(VA 0x18c88e `7d0f`, 0x18c89f `ff05187a1f00e926010000 9090`)를 확인한 뒤에만 바꾸고(`7d13`, `b062e620e928010000 90909090`), 결과가 12 바이트 차이·SHA-256 `304cb696…` 이어야 쓴다. 출력은 `09_validation/images/i386/kernels/`(무시됨).
- 쓰기 전: QEMU i386 가 꺼져 있음(`/proc` 명령줄로 확인), 실제 디스크 SHA-256 = scratch 시험에 쓴 사본의 원본, 백업 `openstep42-i386-hdd.before-pic-add.raw`(해시 일치).
- 쓰기: `nextufs mkfile --from-file DISK /mach_kernel.183.34.4.pic FILE` → `--chmod ... 0444`.
- 쓴 뒤 게이트(모두 통과해야 부팅): `verify_i386_kernel_add.py` 에 `.pic` 항목 추가(해시 = 생성 결과), 전체 감사 오류 0, 기존 두 커널 해시 불변, `nextufs fsck -n` 출력에 5 단계 뒤 경고 줄이 없음(종료 코드는 믿지 않음), 바뀐 영역이 front porch 밖.
- 부팅: `boot-nocd --snapshot` 에서 `hd()mach_kernel.183.34.4.pic -v`. 이상 없으면 스냅샷 없이 쓰는 부팅은 사용자 확인 뒤.

codex 교차검토 (QK3: "쓴 뒤 게이트가 nextufs 가 낼 수 있는 손상을 모두 잡는다") → ✅ 채택 3 건(`verify_i386_kernel_add.py:43,47,55` 확인): 다른 파일 내용·이름·권한 변화와 free 공간 바이트 변화를 게이트가 못 본다. 대응 `10_tools/runtime/compare_ufs_images.py`: 전체 트리(경로·inode·mode·uid·gid·nlink·크기·내용 해시) 전후 비교 + 바뀐 1 KiB 프래그먼트가 허용 영역(새 파일·부모 디렉터리 블록, cg 블록, 1 차 슈퍼블록, 실린더 요약, 해당 inode 레코드) 안인지 검사. 시험: 정상 쌍 통과, 다른 파일 1 바이트 변경·free 공간 1 바이트 변경 모두 실패로 잡음.

실행 (2026-10-01): 백업 `openstep42-i386-hdd.before-pic-add.raw` = 디스크 = scratch 시험 원본(`73b8a60e…`). `nextufs mkfile --from-file` + `--chmod 0444` → `nextufs fsck -n` 5 단계 뒤 경고 없음(`09_validation/runtime/i386-pic-add-nextufs-fsck-20261001.txt`), 게이트 통과(`i386-pic-add-verify-20261001.json`), 전후 비교 통과(`i386-pic-add-compare-20261001.json`: 슈퍼블록 1, cg 2, inode 블록 2, 실린더 요약 1, 파일·디렉터리 데이터 1090 KiB). 다음: `boot-nocd --snapshot` 에서 `hd()mach_kernel.183.34.4.pic -v`.

PIC 수정본 부팅 관찰 (2026-10-01, `boot-nocd --snapshot`, `hd()mach_kernel.183.34.4.pic -v`): IDE 잠김 없이 로그인·Workspace 까지 뜸(느림). Workspace 대기 중 GDB 로 PC 30 표본(붙였다 떼기, 표본마다 VM 이 잠깐 멈춤): 커널 모드 29·사용자 1, 그중 `_idle_thread_continue` 21, `__TEXT` 밖 커널 모드 0x6000 대 6, `_flt_page` 1, `_splhigh` 1. 같은 때 호스트 QEMU CPU 80–93 %. idle 루프(0x164684–)는 실행 큐를 확인하며 돌고 `_PMSetCpuState`(0x187460, 안에 `hlt` @0x1874e4)를 부른다. 해석(가설): 게스트는 계산이 아니라 무언가를 기다려 느리다. 부팅 로그의 `Setting hostname to -AUTOMATIC-`·nmserver 재초기화와 NIC 없는 구성으로 보아 이름 서비스 시간 초과가 후보(m68k 에서 정적 hostconfig 로 사라진 대기와 같은 종류). 확인은 정적 hostconfig 로 바꾼 뒤 비교.
- 사용자 확인(2026-10-01): 이 부팅에서 `hostinfo` 가 커널 이름과 `PST 1999` 를 보여 준다 → 실행 중인 커널은 mk-183.34.4 빌드(PIC 수정본). 12 바이트 차이는 `_intr_handler` 의 스퓨리어스 분기뿐.

## 개발자 패키지 설치 (2026-10-01)

- 준비: 세 스크립트에 `boot --cd ISO|KEY`(공통 파서, `site.conf` 키 `OS42_DEV_ISO` = os42jdev.iso). 설치 전 백업: SPARC 스냅샷 `before-devtools`, i386·m68k `*.before-devtools.raw`(해시 일치).
- SPARC(QEMU 6.2): ProfileLibs 설치 뒤 GNUSource 를 여는 중 멈춤. 원인 분석은 `11_emulation/SPARC_INSTALL_HANG_NOTES.md` "재현과 원인"(NXConditionLock 경합, ESP 완료 인터럽트 경로). 대응 결정 대기, 디스크는 멈춘 상태 그대로.
- m68k: 사용자 설치 완료. 디스크 읽기 확인: 영수증 DeveloperTools·DeveloperLibs·DeveloperDoc·GNUSource·ProfileLibs, `nextufs fsck -n` 5 단계 뒤 경고 없음(33278 files, 506581 used). `/bin/cc` 는 NeXT `cc-744.13` 드라이버. `/lib/{i386,m68k,sparc}/` 에 `as`·`cc1obj`·`cc1objplus`·`cc1plus`·`cpp`·`cpp-precomp`·`specs` 가 있고 `cc1obj`·`cc1plus` 에 문자열 `2.7.2.1` — **GCC 2.7.2.1 기반 NeXT 컴파일러가 세 아키텍처 백엔드를 모두 갖는다**(실행 확인 전, 바이트의 문자열 관찰). `/usr/lib/migcom` 있음. 남은 공간 약 493 MB.
- i386: 사용자 설치 완료(기존 1997+PIC 커널로 부팅). 디스크 읽기 확인: 영수증 5 개, `nextufs fsck -n` 경고 없음(37675 files, 521511 used), 세 커널 해시 불변(`00e49892…`, `33469393…`, `304cb696…`). `/lib/{i386,m68k,sparc}/cc1obj` SHA-256 앞 16 자리가 m68k 디스크와 같다(`33044bea…`, `694cec5b…`, `ed859c51…`) → 두 설치의 컴파일러 백엔드 파일이 같다. `/bin/cc`·`/bin/as`·`/bin/ld` 크기도 m68k 와 같고 `/usr/lib/migcom` 은 크기가 다르다(i386 91236, m68k 91256).
- SPARC ESP 경합 대응(QEMU 수정)은 사용자 지시로 별도 인계 문서 `11_emulation/HANDOFF_SPARC_ESP.md`(git 무시, 로컬) 에 정리했다. 증거 `11_emulation/records/sparc-devtools-hang-20261001/`.
