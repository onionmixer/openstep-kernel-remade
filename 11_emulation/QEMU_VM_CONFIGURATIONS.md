# QEMU VM 구성 — m68k · SPARC · Intel

커널 디버깅용 가상머신 세 대의 현재 구성이다. 실행은 머신별 스크립트 `scripts/vm-<arch>.sh` 로 한다.

## 0. 공통

### 0.1 QEMU 실행 파일

세 머신 모두 `build/qemu-NeXT-lab/` 의 바이너리 하나씩을 쓴다. `scripts/build-qemu.sh` 가 qemu-NeXT 작업 트리를 트리 밖에서 빌드한다(QEMU 11.0.90).

| 머신 | 실행 파일 | SHA-256 |
|---|---|---|
| Intel | `qemu-system-i386` | `6b12d00f044c6cd40bc3dc1a1219d2d21a7af802d27485702f283bc8a12b604b` |
| SPARC | `qemu-system-sparc` | `fe991d20750bba3b5f8713f794364ef982a3f816b6162f2d3e43797ecee795f8` |
| m68k | `qemu-system-m68k` | `fbb5364332539334ab407a5dca607e095643a55247bd677341b36e21575c943b` (`vm-m68k.sh` 가 확인) |

- 소스: qemu-NeXT `metachicken` `a697703` 에 커밋되지 않은 수정을 더한 작업 트리. 제품 코드는 포크 `onionmixer/qemu-NeXT` 의 최종 `metachicken`(`992ef92`)과 같고 조사용 추적 코드만 더 있다. m68k MMU, FDC, NeXT 플로피, NeXT SCSI DMA, MODE SENSE, NetInfo BIND 수정이 모두 들어 있다.
- libslirp 는 qemu-NeXT 에 고정된 `blanham/libslirp` `ff3ef960…` 를 쓴다(`--force-fallback-for=slirp`). 시스템 libslirp 로는 m68k 게스트의 NeXT 형식 BOOTP 가 끝없이 반복된다.
- libfdt 는 `subprojects/dtc` 로 빌드한다(`--enable-fdt=internal`, 다운로드 없음).
- `qemu-NeXT/build/` 는 쓰지 않는다. 그 안에서 다시 빌드하지 않는다. meson 설정과 `qemu-bundle` 링크가 옛 절대경로를 가리킨다.

### 0.2 머신별 스크립트

| 스크립트 | 모드 | HDD (1 GiB) |
|---|---|---|
| `scripts/vm-i386.sh` | `install`, `boot`, `boot-nocd` | `09_validation/images/i386/openstep42-i386-hdd.raw` |
| `scripts/vm-sparc.sh` | `install`, `boot` | `09_validation/images/sparc/openstep42-sparc-hdd.qcow2` |
| `scripts/vm-m68k.sh` | `install`, `boot` | `09_validation/images/m68k/openstep42-m68k-hdd.raw` |

옵션:
- 화면은 GTK 창이고, 스크립트를 띄운 터미널이 QEMU 모니터다.
- `--snapshot`: HDD 에 쓰지 않는다. 기본은 HDD 에 쓴다. 설치 매체는 항상 읽기 전용이다.
- `--gdb-wait`: 첫 명령 전에 멈춘 채 시작한다(`-S`).
- `--serial`(SPARC): `-nographic -serial mon:stdio`. OBP 가 이 터미널에 뜨고 Ctrl-A x 로 끝낸다. `-qmp` 가 기본 모니터를 끄므로 `mon:stdio` 를 명시해야 Ctrl-A 다중화가 살아 있다.
- `--` 뒤는 QEMU 에 그대로 넘긴다.
- 같은 머신이 이미 떠 있으면(소켓이 응답하면) 두 번째 실행을 거부한다.

### 0.3 설치 매체

경로는 git 이 무시하는 `11_emulation/site.conf` 에만 둔다. 변수 이름은 `scripts/site.conf.example` 에 있다.

| 변수 | 매체 | 크기 | SHA-256 |
|---|---|---|---|
| `OPENSTEP_BOOTCD_ISO` | OPENSTEP_BOOTCD 프로젝트의 부팅 ISO `os42j_boot.iso` | 545,005,568 | `1cb1bb8d5f5d5c023f78c6175c04e9e11fdd6fa2a79edb4f6bac5d57838ebec4` |
| `OS42_SPARC_ISO`, `OS42_M68K_ISO` | 4.2J 설치 CD `os42j.iso` | 541,845,504 | `a624fa9d1642abdd0dacc1ca19b0986ee3aabdee6a8d99317ff5e0863ef50863` |
| (대안) | 4.2 영문 설치 CD `os42e.iso` | 512,514,048 | `943ffacf28d434fec74c5bfb9c674eb84e35da5a77ed51d4c45d9597fc7ddee5` |
| `OS42_M68K_BOOT_FLOPPY` | m68k 부트 플로피 `4.2_Startup_Mach.img` | 1,339,392 | `57f384aa7533a7cbd924ee3c63d9fec0773d1c9847d43422a29876f458ca6046` |

부팅 방식: m68k 는 m68k 전용 부트 플로피로, Intel 은 부트 플로피를 CD 안에 넣은 부팅 ISO 로, SPARC 는 설치 CD 로 직접 부팅한다.

### 0.4 GDB

- 각 VM 은 GDB 스텁을 `/tmp/kr-<arch>-gdb.sock` 에 연다. 연결을 기다릴 뿐 게스트를 멈추지 않는다. QMP 는 `/tmp/kr-<arch>-qmp.sock`.
- 호스트 GDB 는 `gdb-multiarch` 12.1 이다.

```text
(gdb) set architecture i386          # Intel
(gdb) set architecture sparc         # SPARC
(gdb) set endian big
(gdb) set architecture m68k:68040    # m68k
(gdb) set endian big
(gdb) target remote /tmp/kr-<arch>-gdb.sock
```

- SPARC 와 m68k 는 `set endian big` 이 필수다. 실행 파일 없이 붙으면 GDB 가 리틀엔디안으로 해석해 PC 가 뒤집혀 보인다.
- GDB 가 붙으면 게스트가 멈춘다. 설치 중인 VM 에는 붙지 않는다.
- 이 GDB 는 Mach-O 를 읽지 못한다. 커널 심볼을 쓰려면 ELF 심볼 파일로 변환해야 한다(아직 없음).

---


### 0.5 다른 CD 넣기

세 스크립트 모두 `boot --cd ISO|KEY` 로 설치 CD 자리에 다른 CD 를 넣는다(`boot` 에서만). 키는 `site.conf` 의 변수 이름이다. 개발자 CD: `--cd OS42_DEV_ISO`(os42jdev.iso, 470,542,336 B, NeXT UFS, 패키지 DeveloperDoc·DeveloperLibs·DeveloperTools·GNUSource·ProfileLibs). SPARC 는 `--qemu62` 와 함께 쓴다.

## 1. m68k — NeXTstation Color

| 항목 | 값 | 이유 |
|---|---|---|
| 기계·메모리 | `-M next-station-color -m 32M` | 이 포크는 이 기종에 32 MiB 를 넘기면 즉시 종료한다 |
| ROM | `-bios firmware/next-rom-v66-Rev_2.5.bin` (MAME `nexts.zip` 의 v66, SHA-256 `1b753890…d8000a4`) | |
| SCSI | HDD ID 0, CD ID 3(읽기 전용, `install`·`boot` 모두) | 2단계 설치가 CD 를 읽는다 |
| SCSI 호환 | `-global scsi-hd.quirk_mode_page_vendor_specific_next=on -global scsi-hd.quirk_mode_page_format_device_next=on` | MODE SENSE page 0·3 의 NeXT 응답 |
| 플로피 | `install` 에서 부트 플로피 읽기 전용, `-global sysbus-fdc.fallback=288` | 부트 플로피가 정규 크기가 아니다. 이 옵션이 없으면 QEMU 는 1.44 MB·500 kbps 로, ROM 은 1 Mbps 로 읽어 `bfd` 에서 ROM 의 `dma_bytes_moved` 경고로 멈춘다 |
| 사운드 | `-audio driver=none` | |
| 네트워크(`boot`) | `-nic user,model=next-mb8795,id=net0 -object netinfo-server,id=ni0,netdev=net0` | |

조작:
1. ROM 은 NVRAM 이 비어 `System test failed. Error code 91.` 뒤 `NeXT>` 에서 멈춘다.
2. 1단계: `vm-m68k.sh install` 후 `NeXT>` 에서 `bfd`.
3. 1단계가 끝나 게스트가 재부팅하면 ROM 으로 돌아온다. QEMU 를 끄고 `vm-m68k.sh boot` 로 다시 띄워 `bsd` 로 2단계를 이어 간다.
4. 설치 뒤에도 `vm-m68k.sh boot` 후 `bsd`. 단일 사용자는 `bsd -s`.

네트워크:
- 이 빌드는 게스트의 NeXT 형식 BOOTP 에 응답해 `en0` 가 `10.0.2.15` 를 받는다. qemu-NeXT 는 호스트명(BOOTPARAM `whoami`)과 넷마스크(ICMP mask; 고정 libslirp 는 이 요청을 버린다)를 알려 주지 않는다.
- 그래서 설치 기본값 `HOSTNAME=-AUTOMATIC-`·`IPNETMASK=-AUTOMATIC-` 로 부팅하면 두 곳에서 기다린다.
  1. `Configuration server not responding to request for hostname` — `c` 또는 Ctrl+C 로 넘어간다.
  2. NetInfo `unable to bind to parent - RPC: Timed out` — `c` 로 넘어간다. QEMU 의 portmap·NetInfo 서버는 브로드캐스트를 `10.0.2.255` 로 온 것만 받는데, 넷마스크가 정해지지 않은 게스트는 다른 주소로 보내는 것으로 보인다(`ifconfig en0` 의 `broadcast` 로 확인).
- 멈추지 않고 로그인 창까지 가려면 단일 사용자에서 정적 값을 넣는다: `mount -u -o rw /`, `echo HOSTNAME=nextvm >> /etc/hostconfig`, `echo IPNETMASK=255.255.255.0 >> /etc/hostconfig`, `sync`, `exit`. 그러면 NetInfo BIND 가 `netinfo-server` 에서 응답을 받는다.

---

## 2. SPARC — SPARCstation 5

| 항목 | 값 | 이유 |
|---|---|---|
| 기계·메모리 | `-M SS-5 -m 64` (CPU 기본값 Fujitsu MB86904) | |
| QEMU | 설치: `--qemu62` 로 Ubuntu QEMU 6.2 (`1:6.2+dfsg-2ubuntu6.31`, `qemu-6.2-ubuntu/qemu-system-sparc`). OpenBIOS·FCode·GTK 모듈은 호스트의 `qemu-system-data`·`qemu-system-gui` 6.2. 설치 뒤 디버깅 기본은 이 빌드 | 이 빌드(11.0.90)에서는 2단계 설치가 커널 spinlock 에서 멈춘다(`SPARC_INSTALL_HANG_NOTES.md`). 두 버전 모두 같은 qcow2 를 연다(헤더 incompatible features 0) |
| 펌웨어 | `-bios` 없음: QEMU 의 OpenBIOS | 이 QEMU 에 실제 Sun PROM(OBP 2.22, `ss5.bin`)을 쓰면 커널이 시작하자마자 `Trap 0x29 (Data Access Error) while interrupts disabled, Error state` 로 QEMU 가 끝난다(QEMU 이슈 2620·2674 와 같은 증상) |
| 화면 | `-g 1024x768x8`. `install` 은 `-vga cg3`, `boot` 는 QEMU 기본 TCX | 설치된 시스템의 윈도 서버는 cg3 에서 `No Display drivers loaded!` 를 반복한다. 참고 자료(이슈 2620, hifialex) 모두 설치 뒤 기본 TCX 8 비트로 부팅했다. 24 비트에서는 커널이 panic 한다(hifialex) |
| CD | `scsi-cd`, SCSI ID 6, `logical_block_size=512,physical_block_size=512`, 읽기 전용 | 512 바이트 블록이어야 부팅된다 |
| HDD | `scsi-hd`, qcow2, `cache=writethrough`. `install` 은 SCSI ID 3, `boot` 는 SCSI ID 0 | OpenBIOS 의 디스크 부팅(`disk`)은 SCSI 3 의 설치본을 찾지 못한다. QEMU 이슈 2620 도 SCSI 3 에 설치하고 `-hda`(SCSI 0)로 부팅했다. qcow2 는 단계별 스냅샷용 |
| 호스트 코어 | `taskset -c 0` | sun4m ESP/DMA 에뮬레이션이 다중 코어에서 큰 디스크 I/O 중 멈출 수 있다 |
| RTC | `-rtc base=utc,clock=host` | |
| NIC | QEMU 기본(lance, user) | |

조작: `vm-sparc.sh install` 은 `-boot d` 라 OpenBIOS 가 CD 로 바로 부팅한다. `boot:` 에서 Enter 를 누르거나 10 초를 기다리면 설치 언어 선택 `--->` 가 나온다. 설치 뒤는 `vm-sparc.sh boot`(`-boot c`).

스냅샷(QEMU 가 꺼진 상태에서):

```sh
QI=11_emulation/build/qemu-NeXT-lab/qemu-img
D=09_validation/images/sparc/openstep42-sparc-hdd.qcow2
$QI snapshot -c NAME $D     # 만들기
$QI snapshot -l $D          # 목록
$QI snapshot -a NAME $D     # 되돌리기
```

상태: 설치 완료(2026-09-30). 1단계는 이 빌드, 2단계는 `--qemu62` 로 했다. 스냅샷 `install-done` 이 설치·기본 설정을 마치고 종료한 상태다. `phase2-hang-q11` 은 이 빌드에서 2단계가 멈춘 상태다. 설치된 디스크는 이 빌드(`vm-sparc.sh boot`)로도 부팅되어 로그인 뒤 Workspace 까지 뜨고(느림), GDB 접속·레지스터 읽기가 된다.

주의: `-display none` 으로 디스크 부팅하면 두 버전 모두 OPENSTEP booter 가 `Unhandled Exception 0x00000021`(PC `0x0008a1bc`)로 멈춘다. 헤드리스 시험은 `-display vnc=unix:/tmp/kr-sparc-vnc.sock` 을 쓴다(유닉스 소켓 경로는 108 바이트 미만). 이 빌드에는 VNC keymap 이 없어 `could not find keymap file for language 'en-us'` 로 끝나므로, `keymaps/en-us` 만 담은 디렉터리를 `-L` 로 더한다(펌웨어 탐색은 그대로).

설치 뒤 확인할 것(NeXTSTEP 3.3 SPARC 설치 기록에서): 첫 부팅이 단일 사용자로 떨어지면 `/etc/fstab` 의 root 장치(`sd0a`/`sd1a`), 네트워크는 hostconfig 정적 값(`INETADDR=10.0.2.15`, `ROUTER=10.0.2.2`, `IPNETMASK=255.255.255.0`, `IPBROADCAST=10.0.2.255`), DNS 는 `10.0.2.3`. 부팅 중 NetInfo 부모 검색에서 기다리면 `c` 로 넘기거나, NetInfo 의 `/machines/broadcasthost` 에서 `serves` 속성을 지운다.

---

## 3. Intel — PC

### 3.1 설치 매체

별도 프로젝트 **OPENSTEP_BOOTCD** 가 만든 El Torito 부팅 ISO `os42j_boot.iso` 를 쓴다(0.3 절). 원본 4.2J CD 는 UFS 라서 PC 에서 그대로 부팅되지 않는다. 이 ISO 는 2.88 MB Intel 부트 플로피를 CD 안에 넣었고, 다음 수정을 담았다.
- 부트 플로피: 커널의 8259 PIC EOI 수정, `Boot Drivers` 에 EIDE 추가, EIDE 설정 `Version` 4.01→4.03.
- CD 안의 UFS: EIDE 드라이버 4.01→4.03, 커널에 같은 PIC 수정, EIDE `Default.table` 이중 채널.

그 프로젝트는 위치가 바뀔 수 있으므로 이 저장소는 이름·크기·해시로만 식별하고 경로는 `site.conf` 에만 둔다.

### 3.2 구성

| 항목 | 값 | 이유 |
|---|---|---|
| 기본 장치 | `-nodefaults` | 없으면 QEMU 가 IDE 2차 마스터에 빈 CD 를 만들고 게스트가 그것을 root 로 골라 `vfs_mountroot: error=15` 로 panic 한다 |
| 기계·CPU·메모리 | `-M pc -cpu pentium3 -m 64` | |
| 화면 | `-vga cirrus` | `-nodefaults` 가 기본 VGA 도 없앤다 |
| IDE | HDD 1차 마스터(index 0), CD 2차 마스터(index 2, 읽기 전용) | OPENSTEP EIDE 드라이버는 마스터 없는 채널을 포기한다. 실기와 같은 배치 |
| 재부팅 | `-no-reboot` | 설치기의 재부팅이 QEMU 종료가 된다 |

`--` 뒤의 추가 인자에는 IDE 장치를 넣지 않는다.

### 3.3 설치 절차

1. `vm-i386.sh install`: CD 부팅. 언어 선택(영어 `1`) → `Type 1 to prepare to install OPENSTEP.` → 대상 디스크 → 1단계 복사. 끝나면 QEMU 가 종료된다.
2. `vm-i386.sh boot`: HDD 부팅, CD 유지. 2단계 그래픽 설치기(Configure.app 장치 요약 → 패키지 → 복사). 끝나면 QEMU 가 종료된다.
3. `vm-i386.sh boot-nocd`: 설치된 시스템.

- 커널 로그는 부팅 프롬프트에서 `-v`.
- `boot --cd ISO|KEY`: CD 자리(IDE 2차 마스터)에 다른 CD 를 넣는다(경로 또는 `site.conf` 키). 게스트의 `/usr/filesystems/CDROM.fs` 는 ISO 9660·Rock Ridge 도 읽는다.
- 다른 커널로 부팅: `boot:` 에서 `hd()커널이름 -v`(디스크의 `BootHelp.txt`: `<<device>kernel> <arguments>`).
- 전원을 끄면 `It's safe to turn off the computer.` 에서 멈추는 것이 정상이다. 모니터에서 `quit`.

### 3.4 커널

이 ISO 로 설치한 커널은 이 저장소의 x86 분석 기준과 다르다.

| 커널 | 버전 | 크기 |
|---|---|---|
| 분석 기준 `03_original/x86` (i386 실기 `/mach_kernel`) | `mk-183.34.4`, 1999-01-26 | 1,117,920 |
| 4.2J CD 의 i386 슬라이스 | `mk-183.34`, 1997-04-27 | 1,113,724 |

이 ISO 는 CD 안의 커널에 PIC EOI 수정(12 바이트)을 넣는다. 설치된 `/mach_kernel` 은 이 ISO 의 i386 슬라이스와 바이트가 같다(4.2J i386 슬라이스 + 12 바이트, 4절).

---

## 4. 상태와 설치된 커널 (2026-10-01)

| 머신 | 상태 | 설치된 커널 파일 | 분석 기준(`03_original`)과 |
|---|---|---|---|
| Intel | 설치 완료, `boot-nocd` 로 부팅 | `/mach_kernel`, mk-183.34 (1997-04-27) + PIC 수정 12 바이트 | **다름**: 기준은 mk-183.34.4 (1999-01-26) |
| Intel (추가 커널) | `boot:` 에서 `hd()mach_kernel.183.34.4.pic -v` 로 부팅, `hostinfo` 에 mk-183.34.4·1999 확인 | `/mach_kernel.183.34.4.pic` = 기준 + `_intr_handler` 12 바이트(`10_tools/runtime/make_i386_pic_kernel.py`). 원본 그대로인 `/mach_kernel.183.34.4` 도 있으나 이 QEMU 에서는 IDE 인터럽트가 잠겨 부팅되지 않는다 | 12 바이트만 다름 |
| m68k | 설치 완료 | `/sdmach` = `/odmach` (같은 inode, `/mach_kernel` 없음), mk-183.34 RELEASE_M68K | 같음 |
| SPARC | 설치 완료(`install-done`) | `/mach_kernel`, mk-183.34 RELEASE_SPARC | 같음 |

근거: `09_validation/runtime/installed-kernel-identity-20261001.json`, 도구 `10_tools/runtime/installed_kernel_identity.py`(읽기 전용, root 불필요). 이 대조는 디스크의 파일만 본다. QEMU 안에서 실행 중인 이미지가 파일과 같다는 것은 확립하지 않는다.
