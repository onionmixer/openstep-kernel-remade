# SPARC 설치 멈춤 — 원인 추적 메모

QEMU 11.0.90(이 저장소 빌드)으로 OPENSTEP 4.2 SPARC 를 설치할 때 난 두 가지 문제의 증거와, 다음에 원인을 좁힐 방법이다. 설치 자체는 우회했다(아래 "현재 우회"). 이 메모는 원인이 밝혀질 때까지 유지한다.

## 문제 1 — 실제 Sun PROM 에서 커널 시작 직후 치명 오류

- 구성: QEMU 11.0.90, `-M SS-20 -cpu 'TI SuperSparc 50' -m 64`, OBP 2.22(`sun-ss20-obp-2.22-SunOBP2-22_535-1377-07.ROM`), CD SCSI 6(512 바이트 블록), HDD SCSI 3, GTK(TCX).
- 증상: `boot cdrom` 뒤 설치 언어 선택까지 가고, 그 뒤 설치 단계에서 QEMU 가 `qemu: fatal: Trap 0x29 (Data Access Error) while interrupts disabled, Error state` 로 종료. 두 번 모두 레지스터가 같았다(재현성 있음).
- GDB(하드웨어 중단점, 빅엔디안): 치명 오류 전에 `_kernel_trap`(0xf00a8554)에 한 번 진입. `tbr=0xf0002090` 로 트랩 9(`data_access_exception`), `o0=9`, `o1=0xf0109ab4`(트랩 프레임으로 보임). 이어 `_kernel_trap` → `_printf`(0xf001467c) 안에서 트랩 0x29 가 겹쳐 error state. 치명 오류 시점 PC `0xf0003198`(`sys_trap+0x28`).
- 기록하지 못한 것: 첫 폴트의 트랩 프레임 내용, 폴트를 낸 명령의 PC. GDB 스크립트에서 SPARC 레지스터 이름을 잘못 써서(`o6` 대신 `sp`, `i6` 대신 `fp`) 도중에 떨어졌다. 고친 스크립트: `records/sparc-gdb-trace-20260930/trace.gdb`.
- 같은 증상의 외부 보고: QEMU 이슈 2620 댓글 2207999780(`-M SS-5 -bios ss5-170.bin`, PC `f0002198`), 이슈 2674 댓글 2989568921(`-M SS-20 -bios ss20-2.25.bin`). 원문 `records/ref-qemu-issues/`.
- 대조: 같은 PROM 으로 QEMU 6.2 에서는 설치 언어 선택까지 정상(측정 `records/QEMU_SS20_OBP_2_22_MEASUREMENT.md`, 시험 P3). hifialex 는 QEMU 7.2 + `ss5.bin` 으로 설치 완료.

## 문제 2 — OpenBIOS 구성에서 2단계 파일 복사 중 멈춤

- 구성: QEMU 11.0.90, `-M SS-5 -m 64`, OpenBIOS, TCX 1024×768×8, CD SCSI 6(512 바이트), HDD qcow2 SCSI 0, `taskset -c 0`, `-rtc base=utc,clock=host`. 1단계는 같은 구성(HDD SCSI 3, cg3)으로 완료.
- 증상: 2단계 "Install NEXTSTEP" 창에서 `Copying files: 3% done`(파일 `data.classes`, 폴더 `InfoPanel.nib`)에서 멈춤. QEMU 는 `running`.
- PC 표본 20 회 모두 `0xf00c9f54`. 역어셈블(빅엔디안):
  ```
  f00c9f48 save  %sp,-112,%sp
  f00c9f4c ld    [%i0+4], %l1
  f00c9f50 ld    [%l1], %l0
  f00c9f54 ld    [%l0], %o0        <- PC
  f00c9f58 cmp   %o0, 0
  f00c9f5c bne   f00c9f54
  f00c9f64 call  f0096ea8          ; _simple_lock_try (ldstub)
  f00c9f70 be    f00c9f54
  ```
  `_IOInitGeneralFuncs`(0xf00ca080) 바로 앞의 이름 없는 함수. 잠금 워드 `0xf029d690` = `0xff000000`(ldstub 으로 잡힌 상태). 잠금 객체 `0xf029d678` = `f0141fd4 f029d680 f029d690 f029d6a0`.
- 호출한 쪽 `i7=0xf018127c` 는 커널 이미지(`0xf0000000`–`0xf016ff78`) 밖, 즉 부팅 뒤 적재된 드라이버 코드. 그 주변은 `call 0xf00f1870` 을 두 번 부르는 함수.
- `psr=0x048004e0`(PIL 4). CPU 하나에서 잡힌 잠금을 기다리므로 잡은 쪽이 풀지 않으면 끝나지 않는다.
- 증거: `records/sparc-phase2-hang-20260930/`(화면, 레지스터, GDB 출력).
- 외부 설명: QEMU 이슈 2620 댓글 2173014660(mcayland, 2024-10-23) — SPARC32 DMA 또는 ESP 구현의 타이밍 버그가 큰 디스크 I/O 에서 드러나고, 전송이 끝난 뒤 NeXT 드라이버가 만족하지 않아 멈춘다. 별도 iothread 가 악화시킨다. `taskset` 으로 CPU 하나에 고정하면 설치가 끝나는 경우가 많다고 했으나, 우리는 `taskset -c 0` 에서도 멈췄다.

## 재현과 원인 (2026-10-01, QEMU 6.2)

QEMU 6.2 로 설치를 마친 뒤 개발자 CD(`--cd OS42_DEV_ISO`)에서 ProfileLibs.pkg 를 설치하고 GNUSource.pkg 를 여는 중 Workspace 가 멈췄다(호스트 CPU 100 %). **PC·호출자가 QEMU 11 의 2 단계 멈춤과 같다**: GDB 표본 20 회 모두 `pc 0xf00c9f54`, `i7 0xf018127c`, `psr 0x048004e7`(PIL 4, S 1, ET 1). 따라서 QEMU 11 만의 문제가 아니다.

바이트·메모리로 확인한 사실:
- 멈춘 함수 `0xf00c9f48` 은 커널 자신의 ObjC 메서드 표에서 `-[NXConditionLock unlockWith:]` 이다(클래스 구조체 `0xf0141fd4`, 이름 `NXConditionLock`, 메서드 표 `0xf01441d8`: `unlockWith:` 0xf00c9f48, `lockWhen:` 0xf00c9ee0, `unlock` 0xf00c9eb8, `lock` 0xf00c9ea0 …).
- 이번 잠금 객체 `0xf029d218`(isa `0xf0141fd4`) → 내부 구조 `0xf029d220` = {simple lock `0xf029d230`, mutex, 조건값}. simple lock 워드 = `0xff000000`(잡힘).
- `lockWhen:`(0xf00c9ee0–0xf00c9f44) 순서: `_lock_write`(mutex) → 조건 비교 → 다르면 simple lock 이 0 이 될 때까지 돌고 `_simple_lock_try` → `_lock_done`(mutex 해제) → `_thread_sleep(조건 주소, simple lock, 0)`. `unlockWith:` 는 simple lock 이 0 이 될 때까지 돈다.
- 호출한 적재 코드 `0xf0181258`: `objc_msgSend(obj, "lock")` 다음 `objc_msgSend(obj, "unlockWith:", 1)`, `obj` = `[0xf0181fe0]` = `0xf029d218`.
- 스택(0xf0104000–0xf0108000 메모리에서 프레임을 따라감): 적재 코드 ← `_esp_finish+0x1cc` ← `_espsvc+0x234` ← `_esp_poll+0x90` ← `interrupt+0xb08` ← `_assert_wait+0x14c`.

해석: 어떤 스레드가 `lockWhen:` 에서 simple lock 을 잡은 채 `_thread_sleep` → `_assert_wait` 안에 있을 때 인터럽트가 들어왔고, 인터럽트 경로의 ESP 완료 처리(`esp_poll` → `espsvc` → `esp_finish` → 드라이버 완료 콜백)가 같은 `NXConditionLock` 에 `unlockWith:1` 을 보낸다. 그 simple lock 은 가로막힌 스레드가 쥐고 있고 CPU 는 하나라 풀릴 수 없다 → 영구 대기. 즉 **게스트 커널/드라이버의 경합 창**(simple lock 을 쥔 채 인터럽트를 받는 구간)이다. 실기에서는 SCSI 명령 완료가 수 ms 뒤라 스레드가 먼저 잠든다. QEMU 의 ESP 는 명령을 거의 즉시 끝내 완료 인터럽트가 이 창에 떨어지기 쉽다(가설: 타이밍 차이. QEMU 가 사양을 어긴다는 증거는 아니다).

경합 창의 범위(원본 바이트, capstone 4.0.2 역어셈블):
- `_thread_sleep`(0xf00711bc) = `_assert_wait` 호출 → `_thread_block_with_continuation` 호출. simple lock 은 `_assert_wait` 동안 계속 잡혀 있다.
- `_assert_wait`(0xf0070cd4) 는 앞에서 `_splusclock`(0xf0070d04) 으로 인터럽트 레벨을 올리고 끝에서 `_splx`(호출 0xf0070e20) 로 되돌린다. 스택의 `_assert_wait+0x14c` = 0xf0070e20 = 그 `_splx` 호출 → **올린 레벨을 낮추는 순간 대기 중이던 ESP 인터럽트가 들어왔다.**
- 따라서 `lockWhen:` 의 `_simple_lock_try` 뒤부터 `thread_block` 이 잠금을 놓기까지 들어오는(또는 `_assert_wait` 안에서 보류됐다가 `_splx` 에서 풀리는) SCSI 완료 인터럽트는 모두 멈춤으로 이어진다. 이 창은 게스트 코드 자체에 있어 실기에도 있다. 실기에서는 완료가 수 ms 뒤라 스레드가 대개 먼저 잠든다.
- 결론: ESP 완료 지연은 확률을 실기 수준으로 낮추는 대응이지 제거가 아니다. 창을 없애는 것은 게스트 수정뿐이다. 지연의 효과는 같은 부하를 반복해 멈춤 빈도를 재야 판단할 수 있다.

다음 선택지:
1. QEMU(qemu-NeXT 포크)의 ESP 완료 인터럽트에 가상 시간 지연을 넣는다 — 게스트 커널은 바이트 그대로. 별도 계획 필요.
2. 게스트 커널을 고친다(i386 PIC 처럼) — 커널이 기준과 달라진다.
3. 재시도 — 확률적 경합이라 통과할 수 있으나 보장되지 않는다.

## 다음에 할 조사

1. 멈추는 순간의 SCSI/DMA 를 기록한다: 같은 구성으로 `-trace events=FILE`(패턴 `esp_*`, `espdma_*`, `ledma_*`, `sparc32_dma_*`)을 켜고 설치를 재현한다. 멈춘 뒤 마지막 명령·전송 길이·IRQ 상태를 본다.
2. 멈춘 드라이버를 특정한다: `0xf018127c` 주변 코드 바이트를 GDB 로 떠서, 설치 CD 의 SPARC 드라이버(`*.config/*_reloc`)와 바이트를 대조한다(CD UFS 는 ISO 오프셋 163,840 바이트, 보관 도구 `12_archive/openstep-iso-remade/tools/openstep_ufs_reader.py`).
3. 잠금을 잡은 쪽을 찾는다: 멈추기 전에 `_simple_lock_try`·잠금 워드 주소에 하드웨어 워치포인트를 걸어 마지막으로 잡은 PC 를 기록한다.
4. 문제 1 은 고친 `trace.gdb` 로 첫 폴트의 트랩 프레임과 폴트 PC 를 기록한다.
5. 두 문제를 QEMU 6.2·7.2 와 11.0.90 의 `hw/scsi/esp.c`, `hw/dma/sparc32_dma.c`, `target/sparc` 변경 이력과 대조한다.

## 현재 우회

SPARC 설치는 QEMU 6.2(Ubuntu 22.04 패키지 `1:6.2+dfsg-2ubuntu6.31`, SHA-256 `1760627d…e7ea3`)로 한다. 설치된 디스크를 QEMU 11.0.90 으로 부팅·디버깅할 수 있는지는 별도로 확인한다.
