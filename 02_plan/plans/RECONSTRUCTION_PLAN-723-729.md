# 커널 소스 복원 작업계획 — 보관 §723–729

`02_plan/RECONSTRUCTION_PLAN.md` 의 §723–729(m68k M4 `ev_ioctl.c`(D162), `if_en.c`(D163), `ev_kbd.c`(D164); 이 묶음의 §723 은 `ev_ioctl.c`·`ev_kbd.c` 의 첫 진단입니다)를 절 번호·내용 그대로 옮긴 보관본입니다(2026-11-03, D026 방식, 사용자 지시 “RECONSTRUCTION_PLAN.md 문서에서 진행이 완료된 내용은 기존의 규칙처럼 정리해주세요.”). 본문은 `---` 아래부터입니다.

---

## 723. M4-192 세부 계획 — m68k `ev_ioctl.c`(행 214 와 그 뒤 띠)·`ev_kbd.c`(행 215) 진단 A1 (07 변경 없음; 코딩 전, 2026-11-02)

고른 까닭(python 으로 아직 덮이지 않은 101 행, 최소 87610 B 가운데서 견줌): `ev.c`(§689) 바로 뒤의 [0x4068710, 0x4069eb8) 6056 B, 27 항목입니다(함수 표 합 6056 B, 빈틈 없음). NeXTMach `ev_ioctl.c`(2 함수)·`ev_kbd.c`(21 함수, 정적 `NextNum` 포함)의 23 함수 가운데 22 개가 원본 표에 이름이 있고(`NextNum` 은 이름 없는 0x40694ae), 새 항목은 `process_adb_event` 와 이름 없는 정적 셋입니다(python: 27 = 23 + 4). 이 구간에는 `__bss` 참조가 없어 OBJECT_MATCH 를 목표로 할 수 있습니다. 다른 세션의 §690–722(`m68k-217`)는 이 구간을 건드리지 않았습니다. `m68k-217` 은 `_evsetup_screens` 2 B 불일치와 익명 자료 소유가 풀리지 않아 이 계획에서 다루지 않습니다.

확인한 사실(이번 세션; 원본 풀이 scratch `p723/evk.dis`(scratch `odis.py`, 원본 바이트), 요약 `scratch/p723/notes_ioctl.md`; 수는 python):
- **경계:** 재고는 `m68k-214` 를 [0x4068710, 0x4068894) 388 B(`evioctl`)만 확실하다고 하고, [0x4068894, 0x4068fa2)(`evsioctl` 1592 B + 이름 없는 88·126 B)는 214 와 215 사이 띠로 둡니다. NeXTMach `ev_ioctl.c` 는 `evioctl`·`evsioctl` 둘이고, 이름 없는 두 함수는 `evsioctl` 의 `EVSIOINFO` 갈래(0x4068e96)가 부르는 0x4068f24 와 그 함수만 부르는 0x4068ecc 입니다(원본 전체 훑기: 호출처가 각각 하나). 그래서 `ev_ioctl.c` = [0x4068710, 0x4068fa2) 2194 B, 4 항목, `ev_kbd.c` = [0x4068fa2, 0x4069eb8) 3862 B, 23 항목으로 둡니다. 이것은 호출 근거의 추정입니다(정적 함수가 같은 번역 단위에서만 불린다는 증명이 아님).
- **`ev_ioctl.c` 1997 바뀜(원본 바이트):**
  - `evioctl`: 열림 전에는 `EVIOSSCR`(0xc0186504)만 허용하고 `evsetup_screens(datap)` 를 부르고 그 반환값은 버린 채 정상 꼬리로 갑니다(0x40687b6–0x40687be; NeXTMach `EVIOSV`). `EVIOSV`·`EVIOSC`·`EVIODC` 가 없습니다. `EVIOSM` 은 `MoveTheCursor(*pp, 0)`, `EVIOST` 는 인수 없는 `StartCursor()` 입니다.
  - `evsioctl`: case 번호 40 개(NeXTMach 34 + 새 6)를 실기 `bsd/dev/m68k/evsio.h` 의 이름으로 풀었습니다. 새 것은 `EVSIOPTRLLPE`(3), `EVSIOGDADT`(85), `EVSIOSADS`(86), `EVSIOSADB`(104), `EVSIOCADB`(105), `EVSIOINFO`(106)이고, `EVSIOIDLE`(87)은 case 에 없습니다. `EVSIOLLPE`(2)와 `EVSIOPTRLLPE`(3)는 `keySema++`·`evg->cursorSema++` 를 따로 하고 `LLEventPost` 이하를 한 꼬리로 합칩니다.
  - 그 밖: `waitThreshold` 는 `evg` 의 칸, `EVSIOSKM` 은 `kmem_alloc`/`kmem_free` 대신 `kalloc`/`kfree`, `EVSIOSB` 는 `SetCurBrightness` 뒤 `RecordBrightness()`, `EVSIOSA` 는 `snd_device_vol_set()` 뒤 `snd_device_vol_save()`, `EVSIOINFO` 는 `return evsio_info(datap)`(끝의 `evnewevents` 꼬리를 건너뜀)입니다. 새 case 의 동작: `EVSIOGDADT`(0x4068d7a)는 `*datap = autoDimTime - evg->VertRetraceClock`, `EVSIOSADS`(0x4068d9c)는 값이 0 이 아니면 `autoDimTime = evg->VertRetraceClock; DoAutoDim()`, 0 이면 `UndoAutoDim(); autoDimTime = evg->VertRetraceClock + autoDimPeriod`, `EVSIOSADB`(0x4068e58)는 `dimmedBrightness = *datap` 을 0..61 로 자르고 `autoDimmed` 면 `DoAutoDim()`, `EVSIOCADB`(0x4068e8c)는 `*datap = dimmedBrightness` 입니다.
  - 이름 없는 둘: 0x4068f24 는 `flavor` 가 1 이 아니면 `EINVAL`, `size` 가 0 이면 `size` 를 64 로 두고 0 을 돌려주며(0x4068f40–0x4068f46), `adb_system_info(list, 16)`(0x4064802)가 0 이면 0x4068ecc 가 기본 장치 둘({1,0,1,`mon_rev`}, {1,1,2,`mon_rev`})을 채우고, `size` 를 `min(size, n<<2)`(정수 개수, 부호 없는 비교)로 줄인 뒤 `copyout(list, data, size<<2)` 가 실패하면 `EFAULT`(14), 아니면 0 을 돌려줍니다(0x4068f68–0x4068f96). 틀 256 B 는 `NXEventSystemDevice[16]`(SDK `ev_types.h`)과 맞습니다. `mon_rev` 는 `u_char`(스테이지 `m68k/cpu.h:54`)라 `moveb` 읽기입니다.
  - 자료: `__data` 는 `eventMsg+16`(0x40b123e, `msg_remote_port`)에 쓰고(0x40687fc) `vol_r`·`vol_l`(0x40b20c0, 0x40b20c4)을 읽습니다. `__bss`·`__cstring`·`__const` 참조는 없습니다.
- **`ev_kbd.c` 1997 바뀜(원본 바이트):**
  - `KeyMapping` 이 732 B 입니다(`curMappingStorage` COMMON 732 B 와 `bzero` 0x2dc 가 맞음). 칸 위치는 `shorts`@0, `keyBits[128]`@2, `maxMod`@130, `modDefs[16]`@134, `keyDefs[128]`@198, `numSeqs`@710, `seqDefs`@714, `specialKeys[9]`@718(1 B 패딩), `mapping`@728 입니다. NeXTMach 보다 `specialKeys[9]` 만 늘었습니다. SDK `ev_keymap.h` 의 `NXParsedKeyMapping` 은 이 배치가 아닙니다.
  - 특수 키 코드(`SOUND_UP_KEY` 등 상수)가 사라지고 `curMapping->specialKeys[0..3]`(소리 올림·내림, 밝기 올림·내림)을 읽습니다. `SetKeyMapping` 은 키 매핑 자료의 끝에서 `n`(≤ 9)과 (인덱스, 키) 쌍을 읽어 `specialKeys` 를 채우고, `n` 이 0 이면 정적 `short`(0x40b1256, `InitKbd` 가 `adb_keybd_present()` 값을 담음)이 0 일 때만 기존 값을 복사하며 아니면 NULL 을 돌려줍니다. `keySema++`/`--`, `bcopy` 732 B 입니다.
  - `process_adb_event`(새): 유효·장치 수정자 검사 없이 `DoKbdEvent(key_code, !up_down, deviceMods)`. `AlphaLockFeedback` 은 `adb_keyboard_LED(state)` 를 더 부름. `SetCurBrightness` 는 `evOpenCalled` 면 `evdispatch(4, i, level)` 을 화면마다, 아니면 `vidSetBrightness`. `DoAutoDim` 은 `dimmedBrightness` 쪽으로 어둡게. `DoSpecialKey` 는 `curMapping` null 검사를 먼저 하고 올림 갈래는 `callout_dispatch(4, RecordBrightness, 0)`.
  - 더 읽은 것(교차검토로 확인): `SetCurBrightness` 는 화면을 `screens-1` 에서 0 으로 내려가며 `evdispatch` 합니다(0x4069118–0x406913a; NeXTMach 는 위로). `NextNum` 은 `bp >= endPtr` 이면 0 을 돌려줍니다(0x40694b8–0x40694c0; NeXTMach 는 `>`). `SetKeyMapping` 의 순서 검사에는 첫 수 `0xff` 거부가 없고 두 수를 검사 없이 읽습니다(0x406968a–0x4069692). `ResetKbd` 는 `mapNotDefault` 이면 옛 매핑과 길이를 저장하고 `InitKbd(1)` 뒤에 널이 아닐 때 `kfree` 합니다(0x4069d4a–0x4069d72; NeXTMach 는 먼저 해제). `InitKbd` 는 `adb_keybd_present()` 를 정적에 담고 `SetKeyMapping`(ADB 면 1008 B, 아니면 842 B 배열) 뒤에 `AllKeysUp()` 을 부릅니다(0x4069de2–0x4069dea; NeXTMach 는 앞).
  - 이름 없는 정적 둘: 0x4069364 는 `CalcModBit` 만 부르는 modDefs 순회(키 상태 비트 검사)이고, 0x40694ae 는 NeXTMach `NextNum` 입니다.
  - `CalcModBit` 은 처음에 `alphaLock` 을 저장하고(0x40697e4), 명령+시프트 알파 락 토글은 `map->modDefs[0]` 이 널일 때만 하며(0x4069824–0x4069828), `bit == 0` 이면 `alphaLock = (myFlags >> 16) & 1`(0x4069874–0x406987c), 끝에서 바뀌었을 때만 `AlphaLockFeedback`(0x4069882–0x406988e). `DoCharGen` 은 수정자 전체로 `charSet`/`charCode`, `eventFlags >> 16 & 3` 로 `origCharSet`/`origCharCode` 를 두 번 계산하고, 순서 처리 앞뒤로 `eventFlags` 를 저장·복원하며(0x4069ab0–0x4069ab6, 0x4069b9c–0x4069ba2), 순서 안에 `0xff` 항목(수정자 비트를 켜고 `NX_FLAGSCHANGED` 를 올림)을 처리합니다. `DoKbdEvent` 는 키가 눌려 있지 않은 상태의 올림이면 `AllKeysUp()` 만 하고 돌아옵니다. `AllKeysUp` 은 `modDefs[0]`(알파 락)에 없는 키의 상태 비트를 모두 지우고 `eventsOpen` 이면 `eventFlags &= ~0x3e0000`. `ResetKbd` 는 옛 매핑을 `kfree`.
  - 자료: `__const` 에 배열 둘(0x40ad172 842 B, 0x40ad4bc 1008 B). 842 B 배열은 NeXTMach `defaultMapping` 의 앞 826 B 가 같고, 끝의 가짜 순서 셋(10 B)이 "순서 0 개 + 특수 키 7 쌍"(16 B; 키 값 0x1a·0x02·0x19·0x01·0x58·0x16·0x0f 가 NeXTMach 의 `SOUND_UP_KEY` 등과 같음)으로 바뀐 것입니다(python). 1008 B 배열은 `adb_keybd_present()` 일 때 쓰는 두 번째 기본 매핑으로 NeXTMach 에 없습니다. `__data` [0x40b1252, 0x40b1260) 14 B 는 `downCount`·`downKey`(-1), 정적 `short` 0, `modKeys[7]`(0x51 0x52 0x57 0x54 0x55 0x53 0x56) 와 1 B 패딩입니다.
  - 두 `__const` 배열에는 기호가 없고(원본 기호표에 `defaultMapping` 없음) 외부 기호로 정의되면 원본에 없는 이름이 생기므로 `static` 이어야 합니다.
- **공통:** ev 변수 이름은 §689(D161)처럼 파일 안 `extern` 블록, 머리는 SDK `bsd/dev/m68k/event.h`·`evio.h` 입니다. `evsio.h` 는 실기 `/NextDeveloper/Headers/bsd/dev/m68k/evsio.h`(4886 B, SHA-256 `54978c9d…`, 기록 `s4c-nextdev-headers-20261002.json` 의 값)를 gcds 로 읽어 호스트에서 해시가 같음을 확인했습니다(scratch `p723/m68k_evsio.raw`). 07 에 들일지는 구현 계획에서 여쭙니다(D158 의 `event.h`·`evio.h` 와 같은 로컬 사본 선례).

방법(진단; 07 은 바꾸지 않음; scratch `p723/gen_p723.py` → `08_build/artifacts/m4p723/`):
- 변형 `ioctl_A1`: NeXTMach `ev_ioctl.c` + 위 바뀜 + 파일 안 이름 블록(진단 표시). 진단 `inc` 로 실기 `evsio.h` 를 `bsd/dev/m68k/evsio.h` 에 얹습니다. 정적 함수 이름은 작성 이름 `evsio_info`·`evsio_defaults`(진단 편의).
- 변형 `kbd_A1`: NeXTMach `ev_kbd.c` + 위 바뀜 + 파일 안 `KeyMapping`(732 B)·`unmapped_key_event`·이름 블록. `defaultMapping`(842 B)은 NeXTMach 글에서 끝 열 바이트를 바꾼 것, 두 번째 매핑(1008 B)은 원본 바이트를 C 배열로 옮긴 것(둘 다 `static const`). 정적 함수 이름은 작성 이름(0x4069364 `ModKeysDown`, `NextNum`), 정적 자료 대응은 funcbytes 앵커로 넘깁니다.
- 명세: 바탕 `m0p689-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, `x86_rel` `machdep/i386/dkbad.c`. 객체 `ev_ioctl`(구간 [0x4068710, 0x4068fa2), `rows` `m68k-214`, `partial` `m68k-215`)와 `ev_kbd`(구간 [0x4068fa2, 0x4069eb8), `partial` `m68k-215`). run `m4p723-p1`(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`).
- funcbytes: `ev_ioctl` 앵커 `0x4068f24=_evsio_info`·`0x4068ecc=_evsio_defaults`, `ev_kbd` 앵커 `0x4069364`·`0x40694ae`·`0x40b1252`·`0x40b1254`·`0x40b1256`·`0x40b1258`·`0x40ad172`·`0x40ad4bc`(진단 이름). 일반 funcbytes 는 길이가 다른 함수의 relocation 을 비교하지 않으므로(§719), 길이가 다르면 원본 바이트로 따로 풀어 견줍니다.
- 측정: 종료·경고, 함수별 바이트·재배치 대상, 객체에만 있는 함수, 함수 차례, 절(`ev_ioctl`: `__text` 2194; `ev_kbd`: `__text` 3862, `__const` 1850, `__data` 14, `__bss` 0)과 `__data`·`__const` 의 바이트(재배치 없이 원본과), 기호·COMMON(D136)·미정의, 의존 출처(i386 0).

판정(미리 정함; 07 은 바꾸지 않음):
- 컴파일이 안 되면 원인을 적고 최소 고침의 새 변형을 새 run 으로 돌립니다(기준을 늦추지 않음).
- 되면 함수별 결과를 적고, 다른 함수는 원본 바이트로 다시 읽어 진단 B 를 세웁니다(B 앞에 codex 교차검토).
- 모든 함수·절이 맞으면, 바이트로 가려지지 않는 꼴(`KeyMapping` 의 정의 자리, `evsio.h` 의 07 자리, 정적 함수 이름, 두 매핑 배열 이름, 파일 안 `extern` 블록의 모양)을 구현 전에 여쭙니다. 행 214·215 는 정확한 행이 아니므로(재고 `exact` 0), 두 객체를 받아들여도 덮은 행으로 세는 방법은 구현 계획에서 따로 정합니다.

### 723.1 교차검토(codex `gpt-6.1-sol`; 첫 요청은 범위를 둘로 나누어 task kf1s0nn08(`ev_ioctl`)·k7xd26f76(`ev_kbd`)) 판정과 계획 수정

먼저 제 잘못:
- ① 계획과 노트에 `__data` `eventMsg+16`(0x40b123e)을 "읽는다" 고 적었으나 0x40687fc 는 `movel 0x40c3638,0x40b123e`, 곧 **쓰기**입니다(`msg_remote_port` 설정).
- ② 노트에 `NextNum` 이 NeXTMach 와 같다(`bp > endPtr`)고 적었으나 원본은 `cmpal %a1@(4),%a0; bcss`(0x40694b8–0x40694bc)로 `bp >= endPtr` 일 때 0 입니다.
- ③ "NeXTMach 에 대응하는 이름 있는 25 항목" 은 확인하지 않고 쓴 수였습니다. python 으로 세면 NeXTMach 함수 23 개(`ev_ioctl` 2 + `ev_kbd` 21) 가운데 원본 표에 이름이 있는 것은 22 개(`NextNum` 이 이름 없음)이고 새 항목이 4 개(27 = 23 + 4)입니다. 계획을 고쳤습니다.
- ④ 읽은 바뀜을 계획 글에 다 옮기지 않았습니다. 아래 표의 omission 들(새 `EVSIO*` 네 case 의 동작, `EVIOSSCR` 반환 버림, `SetCurBrightness` 의 내림차순, `SetKeyMapping` 의 `0xff` 거부 없음, `CalcModBit`·`DoCharGen`·`ResetKbd`·`InitKbd` 의 바뀜)은 노트에 일부가 있었으나 계획에는 없었습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `eventMsg+16` 은 0x40687fc 에서 쓰기 | `evk.dis` 0x40687fc `movel 0x40c3638,0x40b123e`(목적지가 둘째 피연산자) | ✅ 위 ①; 계획 고침 |
| `EVIOSSCR` 은 `evsetup_screens(datap)` 의 반환을 버림 | `evk.dis` 0x40687b4–0x40687be(`bsrl`, `addqw #4,%sp`, `braw 0x4068864`) | ✅ 위 ④; 계획에 추가 |
| `EVSIOGDADT`·`SADS`·`SADB`·`CADB` 의 동작이 빠짐(0x4068d7a, 0x4068d9c, 0x4068e58, 0x4068e8c) | 같은 줄들을 다시 읽음; 번호는 python 디코딩(85 IOR, 86 IOW, 104 IOW, 105 IOR) | ✅ 계획에 추가 |
| 0x4068f24 는 `size` 0 이면 `size`=64, 0 을 돌려줌; `size` 는 `min(size, n<<2)`(부호 없는 비교, 정수 개수); `copyout` 은 `size<<2` 바이트, 실패 시 `EFAULT`(14) | 0x4068f3a–0x4068f46, 0x4068f68–0x4068f96(`asll #2`, `cmpl a2@(8),d0; bccs`, `moveq #14`) | ✅ 계획의 표현을 고침 |
| 0x4068ecc 는 지적 없음 | 노트 | ✅ |
| `SetCurBrightness` 가 `screens-1` 에서 0 으로 내려감 | 0x4069118–0x406913a(`movew screens,d2; subqw #1; … dbf`, 인수는 `d2`) | ✅ 계획에 추가; 소스는 내림 순서 고리로 시험 |
| `NextNum` 은 `bp >= endPtr` 에서 0 | 0x40694b8–0x40694c0 | ✅ 위 ② |
| `SetKeyMapping` 은 순서 항목의 `0xff` 거부 없이 두 수를 읽음 | 0x406968a–0x4069692(`jsr` 둘, 반환 검사 없음) | ✅ 계획에 추가 |
| `CalcModBit` 의 `modDefs[0]` 널 검사와 `bit == 0` 대입이 빠짐 | 0x4069824–0x4069828, 0x4069874–0x406987c | ✅ 계획에 추가 |
| `DoCharGen` 의 `eventFlags` 저장·복원이 빠짐 | 0x4069ab0–0x4069ab6, 0x4069b9c–0x4069ba2 | ✅ 계획에 추가 |
| `ResetKbd` 의 순서·널 검사, `InitKbd` 에서 `AllKeysUp()` 이 뒤 | 0x4069d4a–0x4069d72, 0x4069de2–0x4069dea | ✅ 계획에 추가 |
| 나머지 열 함수와 정적 0x4069364 는 지적 없음 | 노트와 `evk.dis` | ⏭️ 사실 주장이 아니라 지적 없음 |

2 차 자기검사: ✅ 행의 근거는 모두 이번 세션에 연 `evk.dis` 줄이고, 계획에 옮긴 주소 40 개가 모두 명령 시작임을 python 으로 확인했습니다(확인 출력: 범위 안 인용 40, 명령 시작 아님 0). 수가 든 행은 python 출력입니다(23/22/4, 27).

계획 수정: 위 ✅ 항목을 §723 의 사실 절에 옮겼습니다. 진단 소스의 `SetCurBrightness` 는 내림 순서 고리, `NextNum` 은 `>=`, `SetKeyMapping` 은 `0xff` 거부 없이, `InitKbd`·`ResetKbd`·`CalcModBit`·`DoCharGen` 은 위 순서대로 씁니다.

### 723.2 진단 결과(runs `m4p723-p1`–`p8`, 2026-11-02)

먼저 제 잘못:
1. 첫 컴파일 run `m4p723-p1` 은 실패했습니다. 두 소스가 `NX_NUMSPECIALKEYS`·`NX_KEYTYPE_*` 를 쓰는데 SDK `bsd/dev/ev_keymap.h` 를 들이지 않았습니다(코딩 전 머리 확인에서 놓침). 머리를 더해 새 run `p2` 로 다시 돌렸고 `p1` 은 실패 기록으로 남깁니다.
2. 생성기 첫 판에서 두 번째 매핑 배열의 머리 주석이 주석 밖으로 새어(`... original bytes 0x40ad4bc`) 구문 오류가 될 뻔했고, 배열 바이트 수 검사(1009 ≠ 1008)로 run 전에 찾아 고쳤습니다.
3. 계획에 쓴 `EVSIOINFO` 정적 함수의 모양(`if (flavor != 1) return EINVAL;` 먼저)은 원본의 블록 차례와 달랐습니다. 원본은 `if (flavor == 1) { … } else return EINVAL;` 뒤에 `copyout` 이 옵니다(B 에서 고침).
4. `SetKeyMapping` 의 특수 키 쌍에서 둘째 값을 `k` 에 담았으나 원본은 `l`(d3)에 담습니다(C 에서 고침).

run 과 결과(함수별 funcbytes; 길이가 같은 함수는 relocation 목표까지 비교):

| run | 변형 | 결과 |
|---|---|---|
| p2 | `ev_ioctl` A1, `ev_kbd` A1 | `ev_ioctl` 2/4(`evioctl`·`evsio_defaults`), `ev_kbd` 18/23. `__const` 1850 B·`__data` 13 B 는 원본 바이트와 같음 |
| p3 | `ev_ioctl` B1–B4, `ev_kbd` KB–KD | `evsio_info` 의 `if (flavor == 1) {…} else` 꼴과 `copyout` 뒤 `if (…) return EFAULT; return 0;` 꼴이 같아짐(삼항 `? EFAULT : 0`·`== 0 ? 0 : EFAULT` 는 2 B 다름); `CalcModBit` 은 `oldAlphaLock != alphaLock`, `AllKeysUp` 은 `int shorts` + `if (i == NEXTNUM())` 로 같아짐; `SetKeyMapping` 은 특수 키 개수를 `numMods` 로 재사용하는 꼴이 2 B 차이까지 가까워짐(별도 `numSpecial` 은 28 B 다름) |
| p4 | `ev_ioctl` C1·C2, `ev_kbd` KE–KH | `SetKeyMapping` 같아짐(둘째 값 `l`); `SetCurBrightness` 는 `short i` + `for (i=screens-1; i!=-1; i--)` 에서 같아짐(`i>=0`·오름차순·지역 한계 변수는 길이가 다름); `evsioctl` 은 오름차순 `short` 한계 변수 꼴이 +2 B |
| p5 | `ev_ioctl` D1·D2, `ev_kbd` KI–KL | **`ev_ioctl` D1: 4/4 함수가 같음**(`EVSIOSMS`·`EVSIOCMS` 의 `short i; for (i=emsp->numScaleLevels-1; i!=-1; i--)`; `i>=0` 는 -8 B). `ev_kbd` KL: 22/23, `DoModCalc` 3 B(원본은 임시값을 d1 에 두고 진단은 d0 에 둠) |
| p6–p8 | `ev_kbd` KM–KY(`DoModCalc` 표기 변형 열세 개; p3–p5 의 여덟 개와 합쳐 21 개) | 모두 `DoModCalc` 3 B 그대로(p3–p5 의 `bit` 지역·`char thisBits`·선언 순서·선언 초기화·`register`·`(int)`·`short thisBits`·`!= 0` 포함): K&R 정의, 피연산자 순서, `0xf`, `== 0`, 지역 `bit`, 선언 순서, 선언 초기화, `register`, `char`/`short`/`unsigned` `thisBits`(둘은 길이가 변함), 암묵 `int`·`int` 반환형, 지역 포인터, `(int)` 형 변환 |

최선 변형의 기록: `ev_ioctl` D1(소스 `08_build/artifacts/m4p723/src/ev_ioctl_D1.c`)과 `ev_kbd` KL(`ev_kbd_KL.c`); funcbytes `m4-m68k-funcbytes-p723-ioctl-D1-20261102.json`·`-kbd-KL-`; 검사 `m4-m68k-p723-checks-20261102.json`(절 크기가 목표와 같음: `ev_ioctl` `__text` 2194, `ev_kbd` `__text` 3862·`__const` 1850·`__data` 13; 원본에 없는 외부 정의·COMMON·미정의 0; `ev_kbd` 의 `__data`·`__const` 가 원본 바이트와 같음). 이 기록은 진단이며 수락 기록이 아닙니다.

현재 상태: `ev_ioctl` 은 진단에서 모든 함수·절이 맞습니다. `ev_kbd` 는 22/23 이고 `DoModCalc` 의 임시값 레지스터(원본 d1, 진단 d0) 3 B 가 남았습니다. 원본 풀이 32 줄에서 `%d0` 는 0 번, `%d1` 은 3 번(임시값의 `moveq`·`andl`·`pushl`) 나오는데(python), 이를 설명하는 표기를 아직 찾지 못했습니다. 이 차이는 바이트로 정해지는 것이므로 기준을 늦추지 않습니다.

## 724. M4-193 D162 구현 계획 — 07 `src/machdep/m68k/ev_ioctl.c`, 07 `nextdev/bsd/dev/m68k/evsio.h`(실기 사본; 코딩 전, 2026-11-02)

사용자 결정(D162, 2026-11-02; AskUserQuestion 답 — 모두 권장안):
- ① 진행 순서: `ev_ioctl.c` 를 먼저 구현·수락하고 `ev_kbd.c` 는 `DoModCalc` 가 풀린 뒤 따로 구현합니다.
- ② `KeyMapping`(732 B)과 ev 변수 이름은 `ev_ioctl.c` 안 블록입니다(D161 꼴; `ev_kbd.c` 도 나중에 자기 안에 같은 정의를 둠).
- ③ m68k `evsio.h` 는 07 로컬 사본 `07_kernel/nextdev/bsd/dev/m68k/evsio.h` 입니다(실기 `/NextDeveloper/Headers/bsd/dev/m68k/evsio.h`, SHA-256 `54978c9d…`, 4886 B를 그대로; D158 의 `event.h`·`evio.h` 선례; 라이선스 TBD D017, 로컬 전용).
- ④ 나머지는 권장대로: 정적 함수 이름 `evsio_info`·`evsio_defaults`, `kalloc`/`kfree` 는 `(vm_offset_t)` 형 변환(D161 ③), ev 변수는 파일 안 `extern` 블록(D161 ①), `NX_NUMSPECIALKEYS` 는 SDK `<bsd/dev/ev_keymap.h>`, `EVSIOLLPE`·`EVSIOPTRLLPE` 본문은 같은 글 두 번, `EVSIOSMS`·`EVSIOCMS` 는 `short i` 하강 고리, 지운 줄은 표지 주석(D154).

방법:
1. 꼴 L(`08_build/artifacts/m4p724/src/ev_ioctl_L.c`) = 진단 D1(§723.2, 4/4)에서 주석을 비운 것입니다. 07 파일 F = D1 + 머리 주석 + 표지(`plan 723 diagnostic` → `plan 724 (D024, D162)` 등 결정 번호)입니다. scratch `p723/gen_p724.py` 가 `ev_ioctl_D1.c` 에서 만듭니다.
   - 머리 주석: NeXTMach `ev_ioctl.c` 머리 주석(1–30 행; `Copyright 1987 NeXT, Inc.`; `#import` 는 32 행부터)을 그대로 두고 그 뒤에 1997 바뀜 목록(§723 의 `ev_ioctl` 항목)과 "작성 선택" 문단을 넣습니다(D013; D161 의 `ev.c` 꼴).
   - 다시 쓴 부분(`include` 블록과 그 뒤 이름 블록(정적 선언 `static int evsio_info();` 포함), `evioctl`, `evsioctl`, 새 정적 둘)은 `plan 724 … BEGIN/END` 구역 전체로 표지합니다. 구역 밖의 바뀐 줄은 줄마다 표지합니다. 구역 밖에서 공백만 다른 줄은 `evsioctl` 도입 주석 안의 한 줄(NeXTMach 159 행의 탭, D1 189 행은 빈 줄) 하나뿐이므로 탭을 되살립니다(공백 차이도 표지 없는 바뀐 줄로 세는 단언을 씀).
   - 단언(python): F 와 L 은 주석을 뺀 토큰·토큰 줄이 같고, L 과 D1 은 토큰이 같으며, NeXTMach 와 견준 표지 없는 바뀐 줄이 0 이어야 합니다.
2. 새 머리 `07_kernel/nextdev/bsd/dev/m68k/evsio.h`: 실기에서 `gcds` 로 읽은 파일(scratch `p723/m68k_evsio.raw`, 호스트 SHA-256 이 기록값과 같음)을 그대로 둡니다. PROVENANCE 행은 `event.h` 행(1225)과 같은 꼴입니다(`nextdev-os42`, 실기 경로, `license TBD (D017)`, 변경 없음 + 파일 SHA-256, `M4HEADERS[724]` 로 `src/bsd/dev/m68k/evsio.h` 에 스테이징, `ev_ioctl.c` 가 읽음, x86 스테이지 매니페스트에 없음).
3. `stage_m68k.py`: `M4FILES[724] = list(M4FILES[689]) + ['ev_ioctl.c']`, `M4HEADERS[724] = list(M4HEADERS[689]) + [('bsd/dev/m68k/evsio.h', 'src/bsd/dev/m68k/evsio.h', '07_kernel/nextdev')]`, `EXCEPTS[724] = dict(EXCEPTS[689])`, 머리말 `--plan` 목록에 724.
4. 회귀(공유 07 머리는 바꾸지 않고 새 머리 하나만 더함):
   - 계획 689 스테이지를 다시 만들어 보관본 `m0p689-a1-stage` 와 같은지, `m0p724-a1-stage` 와의 차이가 `src/machdep/m68k/ev_ioctl.c`·`src/bsd/dev/m68k/evsio.h` 둘뿐인지 봅니다.
   - M5 205 줄을 새 스테이지에서 컴파일(`m3p724-cc1`)해 받아들인 `m3p689-cc1` 의 출력과 직접 견줍니다(`run.json` 만 달라야 함). 생성 명령 파일은 계획 번호만 달라야 합니다.
   - x86 입력(`m4_x86_inputs.py s6ln`)과 `x86gate` 가 앞과 같아야 합니다.
5. 확인 run `m4p724-p1`(F, L): 둘 다 funcbytes 4/4, `__text` 2194, 경고 0, 원본에 없는 외부 정의·COMMON·미정의 0(D136), F 와 L 의 `canon`·`obj_sig` 같음.
6. `-E` run `m4p724-e1`: F 와 L 의 전처리 토큰이 같고 stderr 0, i386 경로 0.
7. 최종 run `m4p724-a1`(명세 `08_build/artifacts/m4p724/spec.json`; `refs` = L 의 객체 SHA-256; 객체 `ev_ioctl`, 구간 [0x4068710, 0x4068fa2), `rows` `m68k-214`, `partial` `m68k-215`, `basis` 는 진단 명세의 것을 그대로(`basis` 가 없으면 `span()` 이 단언으로 멈춤)): `gate.ok` 이어야 합니다. 정적 bss 가 없으므로 OBJECT_MATCH 이고 `ACCEPTED` 는 두 칸 항목(zerofill 없음)입니다. 확인 기록: 의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지, 종료 0, i386 0.
8. 기록: 근거 문서 `06_reconstruction/evidence/m68k-ev_ioctl.md`·`m68k-ev_ioctl.diff`, 상태 도구 `ACCEPTED` 한 항목(두 번 돌려 같음; 앞 행은 그대로임을 대조), 상태표 한 행, PROVENANCE 두 행(`ev_ioctl.c`, `evsio.h`), MODIFICATIONS 한 행(`ev_ioctl.c`; `evsio.h` 는 변경 없는 사본이라 PROVENANCE 만), DECISIONS D162, HANDOFF·메모리·계획 §724.x.

상태 기대(python): 객체 64(OBJECT_MATCH 50, CODE+BSS_INFERRED 14), 행 88/188(행 214 한 줄만 덮음; 행 215 는 `ev_kbd` 가 수락될 때까지 부분 행), 행 최소 바이트 128264 + 388 = 128652 B = 215874 의 59.60%, `object_bytes` 170456 + 2194 = 172650. M7 의무: 공유 머리에서 온 COMMON(`alert_key`·`file_list`·`km`·`km_coni`·`master_cpu`·`timer_*`·`tth*` 등)의 합침(D136), `ev_ioctl.c` 가 `extern` 으로만 쓰는 ev 변수(COMMON 정의는 다른 객체), 정적 `evsio_info`·`evsio_defaults` 의 자리, 불리는 곳(`evsetup_screens`, `MoveTheCursor`, `StartCursor`, `ResetMouse`, `ResetKbd`, `SetKeyMapping`, `SetCurBrightness`, `RecordBrightness`, `SetAttenuation`, `DoAutoDim`, `UndoAutoDim`, `snd_device_vol_set`·`save`, `adb_system_info`, `object_copyin`, `port_release`, `copyin`·`copyout`, `kalloc`·`kfree`, `LLEventPost`, `evnewevents`).

판정(미리 정함): 4–7 단계와 통합 확인 기록 `m4-m68k-p724-checks-20261102.json`(의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지, 종료 0, i386 0, F = L, `-E` 같음)이 모두 `ok` 이고 상태 도구 출력이 위 기대와 같으면 받아들입니다. 어긋나면 어느 단계가 어긋났는지 적고 멈춥니다(기준을 늦추지 않음).

### 724.1 교차검토(codex `gpt-6.1-sol`, task k112toac4) 판정과 계획 수정

먼저 제 잘못: 계획에 NeXTMach 머리를 "1–42 행" 이라고 적었으나 머리 주석은 1–30 행이고 `#import` 는 32 행부터입니다(python 으로 확인; 진단 D1 의 앞 42 행이 NeXTMach 와 같다는 사실을 머리 주석 범위로 잘못 옮겼음). 또 구역 밖의 공백 차이 한 줄과 정적 선언 줄의 표지를 계획에 쓰지 않았고, 최종 판정 문장에서 통합 확인 기록을 빠뜨렸으며, 이전 상태 행 보존과 M7 의 공유 머리 COMMON 합침을 적지 않았습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 머리 주석은 1–30 행, `#import` 는 32 행 | python: 첫 `#import` 줄 32(NeXTMach·D1), D1 앞 42 행 = NeXTMach 앞 42 행 | ✅ 위 잘못; 계획 고침 |
| 구역 밖 공백만 다른 줄은 `evsioctl` 도입 주석의 NeXTMach 159 행 하나 | python difflib: 공백만 다른 쌍 12 개, 함수 몸통 밖은 (159, 189) 하나 | ✅ 탭을 되살림 |
| 정적 선언 줄은 구역으로 덮어야 함 | `ev_ioctl_D1.c:117` | ✅ 이름 블록 구역에 넣음 |
| `span()` 은 `basis` 를 요구 | `m4_m68k_probe.py:159`, 내 진단 명세에 `basis` 있음 | ✅ 구현 명세에도 같은 `basis` |
| `M4HEADERS` 3-튜플·`EXCEPTS[724]` 로 스테이징이 됨, x86 스테이지에는 영향 없음, 이전 계획 선택 불변 | `stage_m68k.py:591–609,770`; 이번 세션 §689 의 스테이징 규칙과 같음 | ⏭️ 구현에서 스테이지를 실제로 만들어 같음을 단언함 |
| 상태 도구가 행 214 를 덮은 것으로 세고 215 는 부분 행, 기대 수치가 맞음 | 이번 세션에 연 `m4_m68k_status.py:196–224`(위 `span()` 의 `rows` 를 `exact` 와 무관하게 셈), python 수치(88/188, 128652, 172650) | ✅ |
| 최종 문장에 통합 확인 기록, 이전 행 보존, M7 COMMON 합침이 빠짐 | §689.1 과 대조 | ✅ 계획에 추가 |
| zerofill 단계는 불필요 | 진단 객체는 `__text` 뿐, L1 OBJECT_MATCH | ✅ |

2 차 자기검사: ✅ 행의 근거는 모두 이번 세션에 연 줄이거나 python 출력입니다(스테이징 행은 구현에서 단언하므로 ⏭️).

### 724.2 구현 결과(2026-11-02)

먼저 제 잘못:
1. §724 첫 판의 머리 주석 범위(1–42 행), 구역 밖 공백 한 줄·정적 선언 표지·통합 확인 기록·이전 행 보존·M7 COMMON 합침 누락(§724.1에서 고침).
2. 검사기 첫 판이 파일 끝 빈 줄 삭제에서 멈췄습니다(고침; 레이아웃뿐인 4 줄은 기록에 남김).
3. 통합 확인 기록의 `p1_ok` 칸에 항상 True 가 되는 자리 표시 코드를 넣었다가, 확인 run 의 F·L 기록(`diag_gate`, `canon`·`obj_sig` 같음, L1 OBJECT_MATCH, `__text` 2194)에서 계산하도록 고쳤습니다.
4. PROVENANCE 행의 `ev_vars.h` 줄 범위에 확인하지 않은 줄(171, 266)을 넣었다가 python 으로 뽑은 목록대로 고쳤습니다.

결과(모두 미리 정한 기준대로):
- 1 07 `07_kernel/src/machdep/m68k/ev_ioctl.c`(505 줄, SHA-256 `1593e2ca…`)는 scratch `p723/gen_p724.py --write` 가 진단 D1 에서 만들었습니다. 원천 검사(`chk724.py`): F = L 토큰·토큰 줄 같음, L = D1 토큰 같음, 표지 없는 바뀐 줄 0(NeXTMach 와 49 hunk; 파일 끝 빈 줄 4 개만 줄어듦), 머리 주석 1–30 행 그대로.
- 2 07 `nextdev/bsd/dev/m68k/evsio.h`: 실기 파일 그대로(SHA-256 `54978c9d…`). `stage_m68k.py` 786 → 789 줄(`M4FILES`·`M4HEADERS`·`EXCEPTS[724]`, 머리말).
- 3 회귀: `m0p689-r724-stage` = 보관본 `m0p689-a1-stage`(1017 파일), `m0p724-a1-stage` 와의 차이는 `ev_ioctl.c`·`evsio.h` 둘뿐입니다. `m5-689.cmd` = 보관본, `m5-724.cmd` 는 계획 번호만 다릅니다. M5 205 `m3p724-cc1` 의 617 파일은 받아들인 `m3p689-cc1` 과 `run.json` 만 다르고, `compare`(`m3-m68k-p724-compare-20261102.json`)는 `differ_unexpected`·`lost` 가 비었고 객체 항목이 p689 와 같으며 `stage_vs_test_stage` 는 두 파일만 늘었습니다. x86 입력(`m4-x86-inputs-p724-20261102.json`)은 `ok` 이고 p689 와 같고, x86gate 는 `plan`·`tool_sha256` 만 다릅니다.
- 4 확인 run `m4p724-p1`(`m4-m68k-probe-p724-p1-20261102.json`): F·L 경고 0, 4/4(`m4-m68k-funcbytes-p724-{F,L}-20261102.json`), `__text` 2194, F = L(`canon`·`obj_sig`).
- 5 `-E` run `m4p724-e1`(`m4-m68k-p724-e1-20261102.json` `ok`): F = L 18499 토큰, stderr 0, i386 0.
- 6 최종 run `m4p724-a1`(`m4-m68k-p724-final-20261102.json`, SHA-256 `3f2b99f6…`; REF = p1 의 L 객체): `gate.ok`, OBJECT_MATCH, funcbytes 4/4. 통합 확인 기록 `m4-m68k-p724-checks-20261102.json` `ok`(의존 171, 저장소 파일 152 의 SHA 사슬에 `evsio.h` 포함; 선택지 = M5 줄; 07 = 스테이지; 원본에 없는 이름 0). 객체 SHA-256 `6b247006…`.
- 7 상태(`m4-m68k-status-p724-20261102.json`, 표 65 → 66 줄; 두 번 돌려 출력 경로 칸만 다름; 이전 행은 그대로): 객체 64(OBJECT_MATCH 50, CODE+BSS_INFERRED 14), 행 **88/188**, **128652 B(59.60%)**, `object_bytes` 172650, 부분 행에 `m68k-215` 추가. 미리 계산한 값과 같습니다.
- 8 기록: 근거 `m68k-ev_ioctl.md`·`m68k-ev_ioctl.diff`(455 줄), PROVENANCE 1231 → 1233 행(일곱 칸), MODIFICATIONS 760 → 761, DECISIONS D162(165 → 166 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D162). 남은 일: `ev_kbd.c`(§723, 22/23; `DoModCalc` 의 임시값 레지스터 3 B).

## 725. M4-194 세부 계획 — m68k `if_en.c`(행 260 나머지) 진단 A1 (07 변경 없음; 코딩 전, 2026-11-02)

고른 까닭(python 으로 남은 후보를 견줌; 이름 있는 원본 항목 가운데 NeXTMach 글에 있는 수; 「NeXTMach 함수」 칸은 §725.1 에서 python 으로 다시 세어 바로잡음 — 처음 쓴 22·24·33·42 는 틀림):

| 후보 | 범위 | 항목 | NeXTMach 함수 / 원본·NeXTMach 공통 이름 |
|---|---|---|---|
| **`if_en.c`(행 260 나머지)** | **[0x408db8a, 0x408fd9e) 8724 B** | **26(이름 없음 3)** | **18 / 17** |
| `nextdbg.c`(행 305) | [0x40954b2, 0x4096386) 3796 B | 12 | 21 / 5 |
| `zs.c`(행 255 일부·256) | [0x4089ce8, 0x408d686) 14750 B | 64(이름 없음 53) | 32 / 10 |
| `video.c`(행 255) | [0x4089786, 0x4089ce8) 1378 B | 12 | 39 / 10 |

`if_en.c` 는 대응이 가장 높고(17 함수), 시작은 받아들인 `if_bus`(§676)의 끝, 끝은 받아들인 `in_bootp`(0x408fd9e)의 시작이라 경계가 양쪽에서 정해져 있습니다. `ev_kbd.c`(§723, `DoModCalc` 3 B)와 `ev_mouse.c`(다른 세션의 §690–722)는 풀리지 않은 차이가 있어 이 계획에서 다루지 않습니다.

확인한 사실(이번 세션; 원본 풀이 scratch `p725/en.dis`(scratch `odis.py`, 원본 바이트), 요약 `scratch/p725/notes.md`; 수는 python):
- 범위 [0x408db8a, 0x408fd9e) 8724 B, 항목 26(함수 표 합 8724 B, 빈틈 없음): 이름 없는 정적 셋(0x408db8a 72 B, 0x408dbd2 68 B, 0x408dc16 82 B)과 이름 있는 23 개입니다. 참고 글은 NeXTMach mk-108.1 `nextif/if_en.c`(997 행)입니다.
- NeXTMach 와 이름이 같은 17 함수: `enprobe`·`enattach`·`eninit`·`en_rx_grabbufs`·`en_rx_dmaintr`·`enoutput`·`enstart`·`en_down`·`en_antijam`·`en_jam`·`en_tx_dmaintr`·`encontrol`·`en_setaddr`·`en_recv`·`en_arp_input`·`en_send`·`en_xmit`. NeXTMach 에만 있는 `ppkt` 는 `DEBUG` 전용입니다. 원본에만 있는 이름은 `en_accept_multicast`(100 B)·`en_bufalloc`(232 B)·`en_rx_devintr`(134 B)·`en_tx_devintr`(122 B)·`en_tx_guard`(98 B)·`enintsetup`(70 B)와 이름 없는 정적 셋이고, 모두 mk-108.1 `nextif/if_en.c` 에 글이 없는 함수입니다("1997 에 새로 생긴" 것인지는 모름 — 원본 바이트로 쓸 대상). 앞의 정적 셋은 §675 에서 `_copywithin` 을 되풀이해 부르는 같은 무리로 보았습니다.
- 구성: 스테이지 `generated/en.h` 는 `NEN 1`, `gdb.h` 는 `GDB 1` 입니다. 그래서 NeXTMach 글의 `GDB` 갈래(`is_ac_ipaddr`, `IFCONTROL_SETIPADDRESS` 정의와 그 분기)가 컴파일되고, 원본 `encontrol` 은 `IFCONTROL_SETFLAGS`(0x40acf6e)·`GETADDR`(0x40acf7f)·`RCVPROMISCUOUS`(0x40acf9b)·`RCVPROMISCOFF`(0x40acfaa)·`ADDMULTICAST`(0x40acfba)·`RMVMULTICAST`(0x40acfc8)·`SETIPADDRESS`(0x40ad8bc) 일곱을 참조합니다(§725.1: 이 중 이 파일이 가진 문자열은 `SETIPADDRESS` 하나로 추정, 나머지는 다른 객체의 외부 상수이며 NeXTMach 글이 처리하는 것은 `SETFLAGS`·`GETADDR`·`SETIPADDRESS`(GDB) 셋뿐 — `RCVPROMISCUOUS`·`RCVPROMISCOFF`·`ADDMULTICAST`·`RMVMULTICAST` 넷은 NeXTMach 글에 없는 처리).
- 자료: `__data` [0x40b245a, 0x40b2892) 1080 B = `etherbcastaddr`(6 B, 0xff×6), `endriver`(50 B, `struct bus_driver`: `enprobe` 0x408dc68, 0, `enattach` 0x408dc7a, … `"en"` 0x40abf99, `eninfo` 포인터), 전역 `crctab`(1024 B = 256 × 4, 표준 CRC-32 표 `0x00000000, 0x77073096, 0xee0e612c, …`; NeXTMach 에 없음; 범위 안에서 `en_rx_dmaintr`(+402 = 0x408e332)만 참조). 앞은 받아들인 `if_bus` 의 끝(0x40b245a), 뒤 0x40b2892 는 `dayyr`(`clock`)입니다.
- 정적 bss: 0x40b5598·0x40b559c·0x40b55a0·0x40b55a4·0x40b55a8 다섯 낱말이 `en_bufalloc`(0x408f5d2)과 `en_recv`(0x408f6ba)에서 쓰입니다(원본 이름 없음). 그래서 CODE+BSS_INFERRED 가 예상됩니다(§725.1: 0x40b5598 은 `en_bufalloc` 만, 나머지 넷은 `en_recv` 만 씁니다).
- 재고 행 260(가능한 시작 [0x408db66, 0x408dc68])은 정확한 행이 아니고 시작이 받아들인 `if_bus` 구간 안에 있어, 이 객체가 받아들여져도 행으로는 덮이지 않고 부분 행으로 남습니다(행 215 와 같은 사정 — 행 214 는 §724 에서 덮였으므로 "214–215" 라 쓴 것은 바로잡음; 덮은 행 셈은 구현 계획에서 따로).
- 머리: NeXTMach import 는 `en.h`·`gdb.h`·`sys/*`·`net/*`·`next/{cpu,scr,psl,vm_param,event_meter,bmap,spl}.h`·`nextdev/{dma,busvar}.h`·`nextif/{if_enreg,if_bus}.h`·`kern/xpr.h`·`netinet/*`(INET 이고 GDB 라서 들임)입니다. 스테이지의 include 뿌리에서 그대로는 찾아지지 않는 것은 python 으로 일곱입니다(`next/scr.h`·`next/psl.h`·`next/vm_param.h`·`next/bmap.h`·`nextdev/busvar.h`·`nextif/if_enreg.h`·`next/spl.h`; §725.1). 이 가운데 새 진단 `inc` 가 필요한 것은 NeXTMach 전용 `nextif/if_enreg.h` 하나(07 사본은 구현 계획에서)이고, 여섯은 아래 대응·삭제로 처리합니다. 대응 선례: `next/spl.h` → `machine/spl.h`, `next/psl.h` → `m68k/psl.h`, `next/bmap.h` → `m68k/bmap.h`, `nextdev/busvar.h` → `dev/busvar.h`(`km`·`in_bootp`), `next/vm_param.h` → `mach/m68k/vm_param.h`(`pmap`), `next/cpu.h` 는 스테이지 `src/bsd/next/cpu.h`(어셈블리 전용; C 에서는 `disk_chip` 등 시험적 정의를 냄, 07 `PROVENANCE`)가 조용히 잡히므로 import 줄을 지우고 쓰는 이름만 파일 안 블록(D107·D110; 이름은 §725.1), `next/scr.h` 는 이 파일이 쓰는 이름이 없어(python) import 줄을 지웁니다.

방법(진단; 07 은 바꾸지 않음; scratch `p725/gen_p725.py` → `08_build/artifacts/m4p725/`):
- 변형 A1 = NeXTMach `if_en.c` 의 함수 17 개 + 위 머리 대응 + 파일 안 이름 블록 + 데이터(`etherbcastaddr`·`endriver`는 NeXTMach 글, `crctab` 는 원본 바이트를 C 배열로) + 1997 새 함수 아홉의 `extern` 선언(진단 이름 `en_accept_multicast` 등; 본문 없음). 새 함수 본문은 A1 결과를 본 뒤 원본 바이트로 읽어 진단 B 에서 씁니다. 그 밖은 NeXTMach 그대로입니다.
- 명세: 바탕 `m0p724-a1-stage`, `m5_line` `08_build/artifacts/m5p494/final.cmd`, 객체 `if_en`, `m4_id` `{"range": ["0x408db8a", "0x408fd9e"], "rows": [], "partial": ["m68k-259", "m68k-260"], "basis": …}`(§725.1 E8: 행 259 도 겹침), `x86_rel` `machdep/i386/dkbad.c`, 진단 `inc` `nextif/if_enreg.h`(NeXTMach 사본). run `m4p725-p1`(REGISTRY 0 건 확인함; `wait` 뒤 `collect` 없이 `compare`).
- funcbytes `-p725-A1-`: 대응 `0x408db8a`·`0x408dbd2`·`0x408dc16` 은 새 정적이라 A1 에서는 없고, 자료 앵커 `0x40b245a=_etherbcastaddr`·`0x40b2460=_endriver`·`0x40b2492=_crctab`.
- 측정: 종료·경고, 함수별 바이트·재배치 대상(길이가 다르면 relocation 은 미비교), 객체에만 있는 함수, 절(`__text` 8724 목표는 새 함수 아홉이 빠져 작음 — 함수 단위로만 판정), `__data` 1080 B 를 원본과 바이트로, `__const`·`__cstring` 의 문자열, 기호·COMMON(D136)·미정의, 의존 출처(i386 0).

판정(미리 정함; 07 은 바꾸지 않음):
- 컴파일이 안 되면 원인을 적고 최소 고침의 새 변형을 새 run 으로 돌립니다.
- 되면 NeXTMach 와 이름이 같은 17 함수의 결과(같음 / 길이 다름 / 바이트 다름)를 적고, 다른 함수와 새 함수 아홉을 원본 바이트로 풀어 진단 B 를 세웁니다(B 앞에 codex 교차검토).
- 모든 함수·절·자료가 맞으면 바이트로 가려지지 않는 꼴(`crctab`·새 정적의 이름, `if_enreg.h` 의 07 자리, 정적 bss 이름)을 구현 전에 여쭙니다.

### 725.1 codex 교차검토 판정 (2026-11-02; 코딩 전, 전건 재검증)

codex 회신은 근거가 아니라 검증 대상으로만 썼고, 아래 "내 검증" 칸은 이 세션에서 실제로 연 파일·실행한 python/명령입니다.

**내 잘못 (먼저)**

| # | 내가 쓴 것 | 바로잡음 | 내 검증 |
|---|---|---|---|
| E1 | 후보표 「NeXTMach 함수」 22·24·33·42 | **18·21·32·39** (공통 이름 17·5·10·10 은 맞음) | python 함수 머리 세기 `scratch/p725/fcount3.py` → if_en 18, nextdbg 21, zs 32, video 38; video.c 는 머리가 공백으로 시작하는 `vidMoveCursor`(498) 한 개가 빠져 39 — 열 0 의 `{` 42 개에서 함수가 아닌 179(정적 구조체)·194(배열)·833(`Gamma`)을 빼 39 임을 줄을 열어 확인; 공통 이름은 함수 표와 python 으로 대조 |
| E2 | "스테이지에 없는 것은 `if_enreg.h` 하나" | 스테이지 include 뿌리에서 그대로 찾아지지 않는 import 는 **일곱** | python: R 의 import 38 줄을 11 개 include 뿌리에 대 보니 없는 것 = `next/scr.h`·`next/psl.h`·`next/vm_param.h`·`next/bmap.h`·`nextdev/busvar.h`·`nextif/if_enreg.h`·`next/spl.h` |
| E3 | `IFCONTROL_*` 일곱을 GDB 갈래가 만드는 것처럼 씀 | NeXTMach 글은 `SETFLAGS`·`GETADDR`·`SETIPADDRESS`(GDB) 셋만 처리하고 문자열을 **가진** 것은 `SETIPADDRESS`(R:157) 하나뿐 | R:157·696–712 를 열어 봄; 스테이지 `net/netif.h:59–65` 는 `SETFLAGS`~`RMVMULTICAST` 를 extern 으로만 선언, `net/netif.c:44–45` 가 `RCVPROMISC*` 를 정의; 원본 기호표 열 개 모두 `__const`, `SETIPADDRESS`(0x40ad8bc)는 앞의 `_kern_serv_proto`(0x40acfe6)와 거리가 멀고 `__const` 안에서 `set-ipaddress\0` 14 B 가 다른 상수 사이에 있음 — 어느 객체가 가졌는지는 아직 증명하지 못함(R:157 이 이 파일에 정의하므로 추정) |
| E4 | "행 214–215 와 같은 사정" | 행 214 는 §724 에서 이미 덮임, 같은 사정은 **행 215** | `06_reconstruction/m68k-m4-status.tsv:8` (`ev_ioctl`: rows `m68k-214`, partial `m68k-215`); 같은 표 34행 `if_bus` 의 partial 에 이미 `m68k-258,259,260` |
| E5 | "모두 1997 새 함수" | mk-108.1 `if_en.c` 에 글이 **없다**는 사실뿐 — 언제 생겼는지는 모름 | python: R 의 함수 18 개 중 여섯 이름 없음 |
| E6 | `next/cpu.h` 를 "쓰는 이름만 파일 안 블록" 이라고만 씀 | 스테이지에 `src/bsd/next/cpu.h` 가 **있어** import 줄을 두면 조용히 잡힘 — 그 파일은 어셈블리 전용(C 에서는 `disk_chip` 등 시험적 정의를 냄) | 스테이지 `src/bsd/next/cpu.h` 281 줄 확인, `07_kernel/PROVENANCE.tsv:1114` "ASSEMBLY ONLY … no C source may include it"; D107·D110 선례 |
| E8 | `m4_id` 의 partial 을 `m68k-260` 만 적음 | 범위 [0x408db8a,0x408fd9e) 와 겹치는 재고 행은 **259(`if_bus.c`, 가능한 끝 [0x408db66,0x408dc68])와 260** — 첫 `probe compare` 가 `AssertionError ('rows', ['m68k-259'])` 로 멈춤(run `m4p725-p1`, 컴파일은 끝난 뒤) | `m4_m68k_probe.span` 소스(150–177 줄 근처)와 `m68k-m4-inventory.tsv:63,64` 를 열어 봄 |
| E9 | A1 에 새 함수 아홉의 `extern` 선언을 둔다고 씀 | R 글은 그 함수들을 부르지 않으므로 선언은 아무 효과가 없어 A1 에는 두지 않음(호출은 B 에서 생김) | 변형 A1 소스에 호출이 없음(R 의 함수 이름 대조, 위 python) |
| E7 | 계획에 없던 것 | 아래 725.2 에서 채움: `if_rbusget` 인수 수, `en_send`·`dma_sync_cache`, A1 에서 예상되는 차이, 정적 bss 비교, `__data` 비교 방법, 함수 순서·길이가 다른 함수의 원본 대조, 소유/외부 문자열 구분, 이름 목록 | 아래 각 행 |

**codex 주장**

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 범위 8724 B, 항목 26(이름 23·없음 3), 모두 `confirmed=1`, 빈틈 없음 | python: `06_reconstruction/m68k-functions.tsv` 에서 [0x408db8a,0x408fd9e) 항목 26, 이름 없음 3, 합 8724, 이어짐 True, confirmed {'1'}; 다른 세 후보도 항목 수 12·64·12, 범위 길이 3796·14750·1378 | ✅ |
| 17 공통 이름의 진입점·크기·R 정의 줄(160, 167, 191, 274, 313, 416, 471, 535, 545, 563, 611, 684, 722, 828, 908, 932, 958) | python 으로 codex 표를 함수 표와 R 머리 세기(`fcount3.py`)에 대조: 불일치 0 | ✅ |
| 원본에만 있는 여섯(`en_accept_multicast` 0x408e0b6 100 B, `en_rx_devintr` 0x408e11a 134, `en_tx_guard` 0x408ec2e 98, `en_tx_devintr` 0x408ec90 122, `enintsetup` 0x408f58c 70, `en_bufalloc` 0x408f5d2 232) | 같은 python 대조 불일치 0; 합 756 B, 이름 없는 셋 222 B, 공통 17 개 7746 B, 총 8724 B | ✅ |
| "mk-108.1 에 없음이지 도입 시기가 아님" | E5 로 받음 | ✅ |
| R 997 행, 함수 몸체 18 개 | `wc -l` = 997; E1 의 python | ✅ |
| 이름 없는 셋의 호출자 | python: 전체 `__text` 를 objdump 로 풀어 세 주소가 피연산자인 줄을 센 결과 0x408db8a 2 곳, 0x408dbd2 11 곳, 0x408dc16 3 곳, 범위 밖 0; 이미지 전체의 4 바이트 big-endian 절대 주소 검색 6 곳(0x408df98·0x408e142·0x408e152·0x408f75a·0x408f816·0x408f82c)도 모두 범위 안 `__text`; codex 가 든 호출 줄 수와 내 이전 노트(eninit·en_rx_devintr·en_rx_dmaintr·en_tx_dmaintr·encontrol·enintsetup·en_recv / en_jam·en_tx_dmaintr·en_recv)가 같음 | ✅ ("파일 소속은 추정" 이라는 단서도 받음) |
| 자료 [0x40b245a,0x40b2892): 6 + 50 + 1024 = 1080, 사이에 다른 기호 없음, `crctab` 는 반사형 IEEE CRC-32 표 전체 | python: 기호표에서 이 구간 시작 기호 넷(`etherbcastaddr`·`endriver`·`crctab`·뒤의 `dayyr`), 256 낱말 전부 `0xedb88320` 생성표와 일치, 6+50+1024 = 1080 = 0x438; `endriver` 50 B 바이트 `0408dc68 0 0408dc7a …` 확인 | ✅ (기호가 없다는 것이 소속의 증명은 아님 — 단서 받음) |
| `crctab` 의 기준 참조 = `en_rx_dmaintr`+402 = 0x408e332 | `en.dis` 의 0x408e332 `lea 0x40b2492,%a3` 열어 봄 | ✅ |
| 구성 `NEN 1`·`GDB 1` | `generated/en.h`·`gdb.h` 를 `cat` 으로 열어 봄 | ✅ |
| 일곱 `IFCONTROL_*` 참조 줄과 주소 | `en.dis` 줄 1790·1804·1815·1826·1908·1926·2040 에서 0x408f1a2→0x40acf6e, 0x408f1d8→0x40acf7f, 0x408f1fc→0x40ad8bc, 0x408f220→0x40acfba, 0x408f31a→0x40acf9b, 0x408f358→0x40acfc8, 0x408f4ae→0x40acfaa 확인; 이름은 기호표 17–25 줄 | ✅ |
| "GDB 는 일곱을 설명하지 못함" | E3 | ✅ |
| 정적 bss 다섯의 사용처(0x40b5598 은 `en_bufalloc` 만, 나머지는 `en_recv`) | `en.dis` 로 다섯 주소의 모든 줄을 뽑아 봄: 5598 은 0x408f5da·0x408f6aa(`en_bufalloc` 0x408f5d2–0x408f6ba 안), 559c·55a0·55a4·55a8 은 0x408f700–0x408f9fe(`en_recv` 안) | ✅ |
| 이웃: `if_bus` 끝 0x408db8a, `in_bootp` 시작 0x408fd9e | `m68k-m4-status.tsv:34,35`; PROVENANCE 1219·1124 줄은 `if_bus.c`·`in_bootp.c` 행 | ✅ |
| 행 260 이 정확하지 않아 부분 행 | `m68k-m4-inventory.tsv:64` (exact 0, 시작 [0x408db66,0x408dc68], 끝 0x408fd9e, 8502–8760 B) | ✅ |
| `if_rbusget` 은 R 가 2 인수, 스테이지 머리는 3 인수 → 컴파일 오류 | R:383 `if_rbusget (dh2end(dhp), HDR_SIZE + len)`; 스테이지 `src/bsd/nextif/if_bus.h:34` `netbuf_t if_rbusget(en_dmabuf_t, caddr_t, int);`; 원본 0x408e3cc–0x408e3d4 에서 `pea a1@(14)`, `a2`, `a5` 셋을 밀고 `bsrl 0x408db66`, 뒤에 `addqw #8` + `addqw #4` | ✅ |
| `next/cpu.h` 이름이 필요: `slot_id_bmap`, `P_ENET`, `P_ENETX_CSR`, `P_ENETR_CSR`, `I()`, `I_ENETX_DMA`, `I_ENETR_DMA` (`SLOT_ID`·`SLOT_ID_BMAP`·`slot_id` 포함) | R 에서 grep: 163, 236, 239, 253, 257, 831, 836, 961, 962; NeXTMach `next/cpu.h` 줄 92–116(커널·비어셈블리 갈래 95–98)·139·140·151·213·226·227 열어 봄; 스테이지 `src/bsd/m68k/cpu.h` 에 이 이름들이 없음을 grep 으로 확인(출력 0) | ✅ (오히려 E6: 스테이지 `next/cpu.h` 가 조용히 잡히는 점은 codex 가 말하지 않음) |
| `next/scr.h` 는 R 가 쓰는 이름이 없음 | python: `scr.h` 의 이름 34 개 가운데 `if_en.c`(주석 제외)에 쓰이는 것 0, grep 도 import 줄(64)뿐 | ✅ → import 줄을 지움 |
| `bmap.h` 대응이 `bmap_chip`·`bm_drw`·TPE/HEARTBEAT 를 줌, 시험적(COMMON) 정의도 줌 | 스테이지 `src/bsd/m68k/bmap.h` 13–56·83–90 열어 봄 (`volatile struct bmap_chip *bmap_chip;` 와 `BMAP_TPE_RXSEL`·`HEARTBEAT`·`TPE`); R:570–590·658 사용; 원본 COMMON 목록(`scratch/p725/refs.txt`)에 `_bmap_chip` | ✅ (D136 감사 대상) |
| `dma_chan` 이 R 가 쓰는 멤버를 모두 갖고 248 B | `nextdev/dma.h` 는 스테이지·07 `nextmach` 가 SHA-256 `d0fb71f0…` 로 같고(=1997 배치, D119), D119 가 248 B, 원본 0x408dd08 `pea 0xf8` | ✅ (멤버 이름 하나하나는 컴파일이 가림) |
| `en_softc` 가 R 의 배치로는 1306 B, 원본은 1324 곱 | 원본 0x408dc8c `mulsw #1324` 만 확인; **1306 은 검증하지 않음** | ⚠️ 1324 만 씀, 크기 차이는 A1 컴파일 결과로 측정 |
| `event_get`·`event_delta` 정의를 마련해야 함 | R 는 NeXTMach `kern/xpr.h:88`(`machine/xpr.h`)과 `next/xpr.h:18`(`next/eventc.h`)을 거쳐 얻고(`next/eventc.h:88` 가 `event_get` 정의), 스테이지는 `kern/xpr.h:119`(`machdep/machine/xpr.h`)→`machdep/m68k/xpr.h:44`(`machdep/m68k/eventc.h`)로 이어짐을 열어 봄 — 실제로 정의가 들어오는지는 `-E` 로 확인 | ✅ → A1 에서 `-E` 로 정의가 들어오는지 확인(암시 선언이면 조용히 컴파일되므로) |
| `dma_sync_cache` 는 원본에 없고 원본은 `cache_flush` | 기호표: `_dma_sync_cache` 없음, `_cache_flush` 는 0x406760a; 스테이지 `dma.h` 에 둘 다 선언 없음(grep 0) → 암시 선언; 원본 0x408f7de·0x408f9f6·0x408fbee 의 `bsrl 0x406760a` | ✅ |
| 눈에 띄는 차이들(`enattach` 의 `dma_init`·`install_scanned_intr`, `en_rx_dmaintr` 의 CRC·`en_accept_multicast`·`dbg_from_ether`·3 인수 `if_rbusget`, `enoutput` 의 `en_accept_multicast`·`m_copy`·`if_handle_input`, `enstart` 의 `en_tx_guard`, `en_antijam` 의 `enstart` 호출, `encontrol` 의 `kalloc`·멀티캐스트, `en_recv`·`en_xmit` 의 `cache_flush`, `en_send` 인수 셋) | python 으로 각 주소의 호출 대상을 함수 표 이름으로 풀었음(0x408dd66·0x408ddf8→`dma_init`, 0x408dd7e·0x408de1e→`install_scanned_intr`, 0x408e396·0x408e5ba→`en_accept_multicast`, 0x408e3be→`dbg_from_ether`, 0x408e5d2→`m_copy`, 0x408e5e6→`if_handle_input`, 0x408e754 `pea` + 0x408e75a→`en_tx_guard`·`timeout`, 0x408e812→`enstart`, 0x408f262·0x408f482→`kalloc`, 0x408f7de·0x408f9f6·0x408fbee→`cache_flush`); R 에서 grep: `dma_init` 은 239·257(`eninit`), `install_scanned_intr`·`en_accept_multicast`·`m_copy` 없음, `timeout (en_jam…)` 529, 556 의 `enstart` 호출은 주석, `dma_sync_cache` 856·903·970; `en_send` 는 R:932 이 두 인수, 원본 0x408fac2–0x408faca 이 `fp@(8)`·`fp@(12)`·`fp@(16)` 셋을 읽고 R:939 의 `bcopy(tp,bp,len)` 에 해당하는 호출이 없음(0x408faba–0x408fb90 전부 읽음) | ✅ |
| 원본에 `en_pkt`·`en_pkt_hdr`(0x40c8ef8·0x40c8f08)가 있고 R 의 `en_rpkt1`·`en_rpkt2`·`en_tpkt`·`en_proto`·`ep` 는 없음 | 기호표: `_en_pkt` 0x40c8ef8, `_en_pkt_hdr` 0x40c8f08, 나머지 다섯 이름 없음; R:821–826 열어 봄; 원본 `en_send` 가 0x40c8f08~ 를 읽음 | ✅ |
| `ntohs`·`netif` 머리·`bus_driver` 50 B | **검증하지 않음**(계획에 옮기지 않음; 컴파일·비교가 가림) | ⏭️ |
| `endriver` 가 재배치를 가지므로 날 객체와 연결된 원본의 바이트 비교는 다름; funcbytes 의 자료 앵커는 `__data` 를 검증하지 않음 | `m68k_funcbytes.py` 머리말(1–33 줄)을 열어 봄: 함수 단위 바이트·재배치 비교이며 `__data` 내용 비교는 없음 | ✅ → 725.2 에서 자료 비교 방법을 정함 |
| `__const` 일곱은 대부분 외부 참조이고 소유 문자열이 아님 | E3 | ✅ |
| 여섯 개의 import 대응 뒤 "`if_enreg.h` 만 진단 머리가 더 필요" 가 옳은 표현 | E2 의 python | ✅ |

**2차 자기검사**: 위 ✅ 행마다 근거 칸의 파일 줄·python 출력은 이 세션에서 실제로 연 것입니다(codex 가 인용한 줄번호를 그대로 옮긴 곳은 없고, 줄번호는 모두 내가 연 줄입니다). 연 적이 없는 것(1306 B, `ntohs`, `netif` 머리, `bus_driver`)은 ⚠️·⏭️ 로 두고 계획에는 쓰지 않았습니다. codex 가 틀린 주장은 없었습니다(단, 스테이지 `next/cpu.h` 가 있다는 사실은 codex 도 놓쳤고 위 E6 으로 제가 보탰습니다).

### 725.2 진단 A1 의 구체 사양 (725·725.1 을 고침; 코딩 전)

**머리(M)** — 원본 NeXTMach import 38 줄 가운데:
- 그대로 잡히는 것: `en.h`·`gdb.h`·`sys/*`·`net/*`·`next/event_meter.h`(07 `nextmach` 사본, `EVENTMETER 0`)·`nextdev/dma.h`(1997 배치)·`net/etherdefs.h`·`nextif/if_bus.h`(스테이지, 3 인수 `if_rbusget`)·`kern/xpr.h`·`netinet/*`.
- 대응: `next/spl.h`→`machine/spl.h`, `next/psl.h`→`m68k/psl.h`, `next/bmap.h`→`m68k/bmap.h`, `nextdev/busvar.h`→`dev/busvar.h`, `next/vm_param.h`→`mach/m68k/vm_param.h`, `nextif/if_enreg.h`→진단 `inc`(NeXTMach 사본).
- 지움: `next/scr.h`(쓰는 이름 없음). `next/cpu.h` 는 줄을 지우고 파일 안 블록으로 대신: `extern int slot_id, slot_id_bmap;` + `SLOT_ID`·`SLOT_ID_BMAP`·`P_ENETX_CSR`·`P_ENETR_CSR`·`P_ENET`·`I()`·`I_ENETX_DMA`·`I_ENETR_DMA` 를 NeXTMach `next/cpu.h` 의 커널 갈래(95–98)·139·140·151·213·226·227 줄 그대로.
- `-E` 로 `event_get`·`event_delta` 가 `static inline` 정의로 들어오는지 확인합니다(없으면 암시 선언이라 조용히 컴파일되므로).

**A1 에서 NeXTMach 글에 더하는 변경은 하나뿐**: `if_rbusget (dh2end(dhp), HDR_SIZE + len)` 은 스테이지 머리의 3 인수와 맞지 않아(R:383) 컴파일이 안 되므로 진단 자리 인수 `(caddr_t) 0` 을 둘째 자리에 넣고 표시합니다. `en_rx_dmaintr` 의 결과는 A1 에서 판정하지 않고 B 에서 원본(0x408e3cc–0x408e3d4)으로 씁니다.

**새 함수 아홉**: A1 에는 `extern` 선언만(진단 이름), 이름 없는 정적 셋은 본문이 없으므로 호출처가 있는 함수(`eninit` 등)의 호출은 A1 에서 원본과 다릅니다.

**A1 에서 이미 알려진 차이(예상 결과; 새로 발견한 것으로 세지 않음)**:
- `en_send`: 인수 수(원본 3, R 2)·첫 `bcopy`·헤더 복사; `en_recv`·`en_xmit`: `dma_sync_cache`(암시 선언, 미정의 기호) 대 `cache_flush`.
- `enattach`: `dma_init`·`install_scanned_intr`; `en_rx_dmaintr`: CRC·`en_accept_multicast`·`dbg_from_ether`·3 인수 `if_rbusget`; `enoutput`: `en_accept_multicast`·`m_copy`·`if_handle_input`; `enstart`: `en_tx_guard`; `en_antijam`: `enstart` 호출; `encontrol`: `kalloc`·멀티캐스트·promiscuous.
- 기호: R 의 `en_rpkt1`·`en_rpkt2`·`en_tpkt`·`en_proto`·`ep` (원본에는 `en_pkt`·`en_pkt_hdr`); `en_recv` 의 정적 셋(원본은 다섯 낱말); `en_softc` 의 크기(원본 1324 곱; R 쪽 크기는 컴파일 결과로 잼).
- `__const`: A1 이 가지는 문자열은 `SETIPADDRESS` 하나(14 B, 원본 0x40ad8bc 의 소유는 추정); 다른 여섯은 외부 참조.

**측정(추가)**: ① 종료·경고, ② 함수별 바이트·재배치 대상(funcbytes `-p725-A1-`; 길이가 다른 함수는 재배치 미비교이므로 `opdiff.py` 식 구조 대조와 원본 대조를 따로), ③ 객체에만 있는 함수와 **순서**, ④ **`__data` 1080 B**: 별도 python 으로 — 재배치 없는 바이트(`etherbcastaddr`, `crctab`, `endriver` 의 상수 낱말)는 원본과 같은지, `endriver` 의 포인터 칸 넷(probe·attach·name·info)은 재배치 대상이 원본 0x408dc68·0x408dc7a·0x40abf99·0x40c9460 에 해당하는지, ⑤ **정적 bss**: 객체의 지역 bss 크기(R 의 정적 셋 12 B)와 원본 다섯 낱말 20 B, ⑥ `__const`·`__cstring` 문자열(소유/외부 구분), ⑦ 기호·COMMON(D136; 스테이지 `bmap.h` 의 `bmap_chip` 시험적 정의 등)·**미정의 기호**(`dma_sync_cache` 등 A1 전용 이름 목록 만들기), ⑧ 의존 출처(i386 0).

판정 기준은 725 와 같고, 컴파일이 안 되면 원인을 적은 뒤 최소 고침의 새 변형을 새 run 으로 돌립니다(`m4p725-p1` 은 REGISTRY 0 건 확인됨).

### 725.3 진단 A1 결과 (run `m4p725-p1`, 2026-11-02; 07 변경 없음)

- 소스: `08_build/artifacts/m4p725/src/if_en_A1.c`(`scratch/p725/gen_p725.py`, SHA-256 `ec4945d4de23…`), NeXTMach `if_en.c`(SHA `e75ab5260452…`) 대비 94 줄 차이(머리 대응, `next/cpu.h` 이름 블록, `crctab`, `if_rbusget` 자리 인수). 명세 `08_build/artifacts/m4p725/spec.json`.
- 첫 `probe compare` 는 `m4_id.partial` 에 `m68k-259` 가 빠져 멈췄습니다(E8). 고친 뒤: 컴파일 종료 0·경고 0·의존 목록 종료 0, i386 머리 0. `undefined_not_in_original` = `_dma_sync_cache` 하나(예상한 A1 전용 이름).
- 함수(`m4-m68k-funcbytes-p725-A1-20261102.json`): 26 중 **2 개만 바이트·재배치 대상까지 같음** — `enprobe`(18 B)·`en_arp_input`(170 B). `en_down` 은 같은 길이(54 B)에 1 바이트 다름·재배치 0. 나머지 14 개(17 공통 가운데)는 길이가 다름(객체/원본 B): `enattach` 182/592, `eninit` 444/336, `en_rx_grabbufs` 132/156, `en_rx_dmaintr` 352/900, `enoutput` 220/324, `enstart` 242/302, `en_antijam` 56/88, `en_jam` 762/1034, `en_tx_dmaintr` 422/1104, `encontrol` 220/952, `en_setaddr` 114/122, `en_recv` 500/854, `en_send` 262/224, `en_xmit` 394/516. 원본 전용 아홉(정적 셋 + 이름 있는 여섯)은 객체에 없음. 객체에만 있는 함수 없음.
- 절: `__text` 4544 B(원본 8724 B), `__data` 1080 B(재배치 칸 4 개×4 B = 16 B 를 뺀 1064 B 모두 원본 [0x40b245a,0x40b2892) 과 같음; `etherbcastaddr`·`crctab` 는 칸 전체가 같고, `endriver` 의 포인터 칸 넷은 재배치: `enprobe`(객체 +0)·`enattach`(+0x12 = `enprobe` 크기 18)·`"en"`(`__cstring` 첫 낱말)·`eninfo`(COMMON) — 원본 0x408dc68·0x408dc7a·0x40abf99·0x40c9460 과 같은 대상), `__cstring` 289 B, `__const` 14 B(`set-ipaddress\0` — `IFCONTROL_SETIPADDRESS` 하나만 소유, 예상대로), `__bss` 12 B(R 의 `en_recv` 정적 셋; 원본은 다섯 낱말 20 B).
- 기호: COMMON 36 가운데 원본 기호표에 없는 것은 `en_proto`·`en_rpkt1`·`en_rpkt2`·`en_tpkt`(1558 B 씩)·`ep`(8 B) 다섯(예상한 A1 전용 이름); `en_softc` COMMON 은 **1306 B**(원본 곱수 1324 와 18 B 차이 — codex 가 말한 1306 은 이 컴파일로 확인됨); 헤더의 시험적 정의 COMMON(`bufpages`·`nbuf`·`nmbclusters`·`etherbroadcastaddr` 는 원본에서 초기화된 자료)은 D136 대로 M7 의무.
- 판정: 위 판정 기준 둘째에 해당 — 컴파일은 되었고 17 공통 함수 중 같은 것은 **2 개(`enprobe`·`en_arp_input`)**, `en_down` 은 1 바이트 차이, 나머지 14 개는 길이가 달라 원본 바이트로 풀어 쓸 대상입니다. 다음은 진단 B(원본 바이트로 쓴 함수와 NeXTMach 와의 차이)이며, B 앞에 codex 교차검토를 합니다.

### 725.4 진단 B 진행 (run `m4p725-p2`~`p8`, 2026-11-02; 07 변경 없음; 진행 중)

원본 바이트(`scratch/p725/en.dis`, 메모 `scratch/p725/b_notes.md`)로 쓴 함수와 NeXTMach 글의 차이를 한 파일(`scratch/p725/b/*.c` 조각을 `scratch/p725/build_b.py` 가 A1 머리·`enprobe` 와 이어 붙임)로 모아 run 마다 변형(`if_en_B1`~`B7D`, 명세 `08_build/artifacts/m4p725/spec_b*.json`)을 컴파일하고 `m68k_funcbytes.py` 로 26 항목을 원본과 견줬습니다. 함수는 서로 독립이라 한 변형 파일에 함수마다 다른 꼴을 담아 run 한 번에 여러 꼴을 시험합니다.

| run | 변형 | 같은 함수 / 26 | 비고 |
|---|---|---|---|
| p2 | B1 | (컴파일 실패) | `m68k_page_size` 중복 선언, `en_tx_guard` 형 충돌, `IFCONTROL_RCVPROMISC*` 선언 없음, `volatile` 인수 경고, `if_handle_input` 인수 형 |
| p3 | B2 | 11 | `en_softc` COMMON 1324 B(원본 곱수와 같음), 정적 bss 20 B, `__data` 1080 B, 미정의·COMMON 새 이름 없음 |
| p4 | B3 | 15 | 지역 변수 순서, `found` 꼴, 부호 있는 `char *bp`, `(dma_chip != 313) ? … : …` 순서 |
| p5 | B4 | 19 | `ETHERMTU + 1`(원본 `cmpal #1455`), CRC 식 순서, `i = 0` 위치, `enstart (is - en_softc)` |
| p6 | B5A~D | 20 | `en_jam` 일치(`goto` 로 `again`/`linkup` 배치), `en_xmit` 6 B 차이로 접근 |
| p7 | B6A~D | **21** | `en_xmit` 일치(안쪽 고리의 `goto wait` 꼴 `XK`) |
| p8 | B7A~D | 21 | 남은 다섯 함수의 꼴 시험(아래), 개선 없음 |

최선: `08_build/artifacts/m4p725/src/if_en_B6A.c`(SHA-256 앞 12 자리는 이 run 기록 참고) — **26 중 21 함수가 바이트·재배치 대상까지 같음**: 정적 `en_putreg`·`en_regok`, `enprobe`, `enattach`, `eninit`, `en_rx_grabbufs`, `en_accept_multicast`, `en_rx_devintr`, `en_rx_dmaintr`, `enoutput`, `enstart`, `en_down`, `en_antijam`, `en_jam`, `en_tx_guard`, `en_tx_devintr`, `encontrol`, `en_setaddr`, `enintsetup`, `en_arp_input`, `en_xmit`.

**남은 다섯**(원본 바이트가 정한 것과 아직 모르는 꼴):
- `en_getreg`(정적, 0x408db8a, 72 B): 길이는 같고 `return c` 블록 자리만 다름(원본은 비교 분기 바로 뒤, 우리는 맨 끝). `do-while`·`while(1)`·`goto` 등 여덟 꼴을 시험했으나 같은 자리로 나옴.
- `en_tx_dmaintr`(1104 B): 2 B — `time.tv_sec - is_last_rx.tv_sec > 2` 의 상수 2 가 원본은 `d6`, 우리는 `d7` 에 놓임(레지스터 배정).
- `en_bufalloc`(232 B): 첫 가지의 `mem_region[0].first_phys_addr` 를 원본은 주소 레지스터 `a1` 에 두고 `a1+1023` 다음 `+ m68k_page_size`, 우리는 `d0` 에 두고 `psz+1023` 다음 `+p`.
- `en_recv`(854 B 대 852 B): 원본은 `rdma` 가 `a5`, 우리는 `d3`(주소 레지스터 부족으로 자료 레지스터); 선언 순서·`register` 시험으로 바뀌지 않음.
- `en_send`(224 B 대 226 B): `ip_src`/`ip_dst` 맞바꿈을 원본은 `movel _en_pkt_hdr+30,…` 절대 주소로, 우리는 `lea _en_pkt_hdr+34,%a0` 뒤 `a0@(-4)` 로 cse 가 묶음.

**원본 바이트가 정한 것(이름·꼴은 작성, D024)**: `struct en_softc` 1324 B(원본 `mulsl #1324`); 새 칸 `is_tpe_count`(+522)·`is_rxstate`(+534, 부호 없음: `switch` 가 `bhis`)·`is_multicast`(+1314, 6 B 항목 표)·`is_nmulticast`(+1318)·`is_txstat`(+1322, `u_char`); 플래그 `0x20`(받기 방식 갱신 대기)·`0x40`(송신 감시 시간 초과); 정적 보조 셋은 레지스터 바이트 읽기(재시도 17 번 — §725.6 에서 python 으로 바로잡음; `copywithin` 가 14 를 돌리면 재시도)·쓰기·접근 가능 확인(최대 10 번, `delay(1000)`); `dma_chip == 313` 갈림이 곳곳에; GDB 상자 `en_pkt[4]`·`en_pkt_hdr`(42 B)·`dbgstack`; `crctab` 로 받은 프레임이 한 바이트 밀린 것을 CRC 잔여값 `0xdebb20e3` 으로 가림; `encontrol` 에 `ADDMULTICAST`·`RMVMULTICAST`·`RCVPROMISCUOUS`·`RCVPROMISCOFF` 처리(`RMVMULTICAST` 는 표가 없으면 다음 비교로 넘어가 `EINVAL`); `en_recv` 는 인수 넷 `(sport, minlen, locked, ipaddr)` 이고 포인터를 돌려줌; `en_send(port, bp, len)`.

다음: 남은 다섯의 꼴을 더 시험(변형 묶음), 모두 같아지면 07 판(PROVENANCE·MODIFICATIONS·`if_enreg.h` 07 사본·`stage_m68k.py` 등록)과 M5·상태표·기록은 구현 계획으로 나눠 진행합니다. B 단계 시작 전에 요청한 codex 교차검토는 §725.1 로 끝났고, 위 새 함수·꼴에 대한 두 번째 교차검토는 07 판 계획 앞에 합니다.

### 725.5 진단 B 남은 다섯 — 다음 변형 묶음 계획 (코딩 전; 2026-11-02)

**미리 적는 잘못**: §725.2 는 "B 앞에 codex 교차검토"를 약속했는데, 저는 그 검토 없이 B 의 run `m4p725-p2`~`p8` 을 돌렸습니다. 진단(07 불변)이라 되돌릴 것은 없지만 순서를 어긴 것이므로, 아래 계획을 코딩 전에 codex 에 보이고 결과를 전건 재검증한 뒤 다음 묶음을 만듭니다. 07 판 계획 앞에는 B 전체(새 함수·꼴)에 대한 검토를 한 번 더 합니다.

**판정 기준(미리 정함; 결과를 보고 느슨하게 하지 않음)**: 대상 함수가 `m68k_funcbytes.py` 로 "SAME"(길이·바이트·재배치 대상 같음)이어야 합니다. 이미 같은 21 함수는 바뀌면 안 됩니다(변형 묶음마다 21 개가 그대로인지 확인). C89 꼴이고 원본 바이트가 요구하지 않는 줄은 더하지 않습니다. 같아진 꼴이 둘 이상이면 가장 단순한 꼴을 고르고, 바이트로 가려지지 않으면 사용자에게 여쭙습니다.

**대상과 가설(모두 원본 바이트 근거, python/objdump 로 확인한 차이)**
1. `en_getreg`(정적 72 B): 원본은 `cmpl; beqs retry; clrl d0; moveb c,d0; bras end; retry: …; bges top; clrl d0`, 우리는 `bnes ret_c; …; clrl d0; bras end; ret_c: …`. 시험한 꼴(do-while+return, +continue, +goto, while(1), for(;;), 형 `int`, `char c`, `register i`)은 모두 `return c` 가 끝으로 감. 새 가설: 결과 변수 + `break`, 두 번째 `return` 이 아닌 고리 밖 문장, `i++ <= 15` 를 `if` 안에 둠, `c` 를 `int` 로 받음.
2. `en_tx_dmaintr`(2 B): 상수 2 의 임시가 원본 d6, 우리 d7. 가설: 지역 변수 선언 순서·`timedout` 계산을 `if` 문으로·`flags` 지역 제거.
3. `en_bufalloc`(14 B): 원본은 `first_phys_addr` 를 a1(주소 레지스터)에 두고 `a1 + 1023` 다음 `+ m68k_page_size`; 두 번째 가지의 `addaw #1582,a1` 은 주소 레지스터 덧셈 — `p` 가 포인터 형일 가능성. 가설: `p` 를 `char *`(또는 `caddr_t`)로 두고 `roundup((vm_offset_t)p + 1024, …)`·`(int)p` 캐스트.
4. `en_recv`(2 B 짧음): 원본은 `rdma` a5·`regs` a3·`tdma` d4·`rp` d3·`len` d2, 우리는 `rdma` 가 d3. 가설: 지역 변수 수(우리가 하나 더 씀)·선언 순서·`len` 초기화 유무(원본에 `clrl d2` 없음)·`tdma` 를 쓰는 자리.
5. `en_send`(2 B 김): 원본은 `movel _en_pkt_hdr+30,a3@(26)` 절대 주소, 우리는 `lea _en_pkt_hdr+34,a0` 뒤 `a0@(-4)`. 가설: 맞바꿈 두 줄 사이에 다른 식, `struct ip` 복사를 `bcopy` 가 아닌 멤버 단위, 헤더 구조체를 다른 꼴로.

**방법**: `scratch/p725/gen_b6.py` 꼴의 변형 생성기(함수마다 한 꼴, 변형 이름 대문자·숫자), run 한 번에 네 변형, `cmpv.sh` 로 비교, 21 함수 유지 확인. REGISTRY 확인 후 `m4p725-p9` 부터. 계산(바이트 수·차이 수)은 python/도구 출력으로만 적습니다.

### 725.6 §725.5 codex 교차검토 판정과 변형 묶음 결과 (run `m4p725-p9`~`p11`, 2026-11-02)

**내 잘못 (먼저)**: ① §725.4 에 "재시도 16 번"이라 썼는데 python 으로 `i = 0; do { 호출 } while (i++ <= 15)` 를 돌리면 모두 실패할 때 **17 번** 부릅니다(`calls 17`) — 바로잡습니다(codex 5③ 이 맞음). ② 변형 RV2 는 `bp` 선언을 앞으로 옮기며 뒤의 선언을 지우지 않아 "redeclaration" 으로 컴파일이 안 됐습니다(B9B·B9D 객체 없음). ③ 비교 도구에 지역 정적 bss 대응(`0x40b5598=_done.NN` 등)을 넣지 않아 `en_bufalloc` 의 "refs 3" 차이를 코드 차이로 오해했습니다 → `scratch/p725/cmpv.py` 가 객체의 `_done.N` 등을 이름으로 찾아 대응시키게 고침.

| codex 주장 | 내 검증(실제 run) | 판정 |
|---|---|---|
| 1① `en_getreg`: `int r; do { if (copywithin(…) != 14) { r = c; goto out; } } while (i++ <= 15); r = 0; out: return r;` | run p9 변형 A·C: `en_getreg` SAME (72 B) | ✅ 채택 |
| 1② `break` + `if (i > 16) r = 0` | 변형 B: 80 B(길이 다름) | ❌ |
| 2① `char *p` 로 시작, `roundup((vm_offset_t)p + 1024, …)` | 변형 A: `en_bufalloc` 232 B, 17 B 다름 | ❌ |
| 2② `q = (vm_offset_t)p; q += 1024; p = (char *)roundup(q, …)` + 반복문 `(int)p` | 변형 C(정적 bss 대응 포함): `en_bufalloc` SAME | ✅ 채택 |
| 3① `len` 계산 분리 | p10 변형 A(`len -= FCS_SIZE`): `en_recv` 852 B 그대로 | ❌ (효과 없음) |
| 3③ `tdma` 를 정수로 | p9 A·C: `en_recv` 852 B 그대로 | ❌ (효과 없음) |
| 3② 지역 변수 통합 | `rp`/`bp` 통합은 `rp` 가 조건 밖에서 정해져 의미가 달라져 시험하지 않음 | ⏭️ |
| 4① `bp->ip` 복사를 `long` 다섯으로 | p9/p10: `en_send` 218 B(원본 224); 구조체 복사 226 B | ⚖️ 길이가 원본 사이에 끼어 아직 아님 |
| 4② `struct in_addr` 대입 | 위 두 복사 꼴 모두에서 같은 길이 | ❌ |
| 5① 단계별 RTL 비교 | 실제 NeXT cc 의 RTL 덤프 옵션은 시험하지 않음 | ⏭️ (필요하면 다음) |
| 5② 개별 성공본을 합쳐 SAME 재확인 | 마지막에 합본으로 다시 함(아래 결과가 합본) | ✅ 계획에 반영 |
| 5③ 17 회 | python `calls 17` | ✅ |

**결과**: p9 변형 C/p10 변형 D(=`scratch/p725/B9A.base.c`, `08_build/artifacts/m4p725/src/if_en_B9A.c`, SHA-256 앞 16자리 `6464a1ae284f…`)가 **26 중 23 함수 SAME**(합본). 남은 셋: `en_tx_dmaintr`(1104 B, 2 B: 상수 2 임시 레지스터 d6/d7 — 선언 순서 셋·`timedout`/`guard` 한 변수·`? 1 : 0`·`register` 로도 안 바뀜), `en_recv`(852 B 대 854 B: `rdma` 가 d3 인 것은 `len`·`tdma`·선언 순서·`register` 로 안 바뀜), `en_send`(218~226 B 대 224 B: 원본은 `lea a3@(34),a2` 가 다섯 번째 복사 뒤에 있어 `&bp->udp` 를 담은 지역 포인터가 있는 듯하나 `up = &bp->udp` 꼴(S10~S12)은 220 B/224 B 이지만 바이트가 다름).

다음: 남은 셋에 새 가설(원본 어셈블리 줄 단위 재독, 필요하면 NeXT cc 의 RTL 덤프 `-dr` 로 단계별 비교) 후 변형 묶음 `p12` 부터. 07 불변.

### 725.7 남은 셋의 가설과 다음 묶음 계획 (코딩 전; 2026-11-02)

현재 23/26(B9A). 남은 `en_send`·`en_recv`·`en_tx_dmaintr` 의 원본 어셈블리를 다시 읽어 세운 가설(모두 시험 전; 시험은 판정 기준 §725.5 그대로):

1. `en_send`: 원본의 `lea %a3@(34),%a2` 는 `bp->ip = en_pkt_hdr.ip`(20 B, `move_by_pieces`)의 **목적지 끝 포인터**(bp+14 에서 5 번 후증가한 값 = bp+34)를 cse 가 살려 두고, 뒤의 `bp->udp.uh_sport` 저장을 "더 싼 주소" `a2@` 로 바꾼 것으로 보입니다(다른 udp 저장은 `a3@(36…)` 그대로). 우리 객체에서는 같은 끝 포인터가 **원본 쪽**(`lea _en_pkt_hdr+34,%a0`)으로 살아남아 맞바꿈 읽기에 쓰입니다. 시험: 복사와 맞바꿈 사이의 식 순서·`bp` 를 쓰는 방식(예: 복사 직전에 `struct ip *` 지역 변수)이 어느 끝 포인터가 살아남는지 바꾸는지.
2. `en_recv`: 원본은 두 번째 블록에서 `&regs->en_rxmode` 를 자료 레지스터(d2)에 두고(주소 레지스터가 모자람), `rdma` 가 a5·`regs` 가 a3·함수 주소가 a4/a2 입니다. 우리는 주소 레지스터를 하나 더 쓰는 지역 값이 있다고 봅니다. 시험: 두 번째 블록의 `en_putreg/en_getreg` 호출 인수를 `&regs->…` 식 대신 한 지역 포인터로 쓰기, `regs` 를 `register` 가 아닌 일반 지역으로, `rdma` 를 쓰는 `do { } while` 을 `for (;;)` 로.
3. `en_tx_dmaintr`: 상수 2 의 임시 레지스터만 다름(2 B). 시험: 상수를 같은 블록에서 두 번 쓰는 식(`> 2` 와 `switch` 의 `case 2:`)이 서로 다른 블록이 되도록 `timedout` 계산을 `else` 가지 안으로, 또는 `time` 비교를 `<` 꼴로.

**방법**: 위 시험을 `scratch/p725/gen_b11.py`(B9A 기준, 한 묶음 네 변형), run `m4p725-p12`. 합본 SAME 은 기존 23 함수가 그대로인지 확인. 시험하기 전에 codex 에 가설 1~3 을 보이고 후보를 받아 전건 재검증합니다.

### 725.8 §725.7 codex 교차검토 판정과 묶음 결과 (run `m4p725-p12`~`p14`, 2026-11-02)

**내 잘못 (먼저)**: §725.7 의 가설 1 은 최선본 B9A 가 아니라 그 앞 구조체 복사 꼴(B6A 등)의 객체를 설명했습니다. B9A 는 `bp->ip` 를 `long` 다섯 대입으로 복사해 `lea _en_pkt_hdr+26/+30` 뒤 간접 읽기가 나옵니다(codex 4 가 맞음; 객체를 열어 확인). 또 `gen_b12.py` 는 B9A 의 `len` 이 이미 `- (int)en_pkt[epi]; len -= FCS_SIZE;` 로 쪼개져 있음을 잊고 시작해 한 번 `AssertionError` 로 멈췄습니다.

| codex 주장 | 내 검증(실제 run) | 판정 |
|---|---|---|
| 1① `en_send`: 복사 뒤 `.s_addr` 대입 | p12 변형 A·D: 226 B(원본 224) | ❌ |
| 1② `ip = &bp->ip; *ip++ = hdr.ip; ((struct udphdr *)ip)->uh_sport` | p12 변형 B: 226 B | ❌ |
| 1③ 목적지 `char *p` 만 증가 | p12 변형 C: 226 B | ❌ |
| 2① `rxmode` 를 정수로 | p12 C: `en_recv` 852 B 그대로 | ❌ |
| 2② 호출 분리(`mode = en_getreg(…); mode |= 0x80;`) | p12 A·D: 850 B | ❌ |
| 2③ `regs->en_fill` 만 `((volatile struct en_regs *)P_ENET)->en_fill` 로 | p12 B: `en_recv` **854 B(길이 같음)**, 70 B 다름·정적 이름 7 | ✅ 부분 채택(원본도 이 읽기만 주소를 다시 만듦) |
| 3① `delta` 중간값 | p12 A·C: `en_tx_dmaintr` 5 B 다름(악화) | ❌ |
| 3② `now` 지역 구조체 | p12 B·D: 2 B 그대로 | ❌ |
| 4 `en.dis:1548`(`moveq #2,%d6`)·`1558`(`movel _time,%d6`)·`2298`(`movel %a3,%d2`) | 줄을 열어 확인: 맞음 | ✅ |

**결과**: 최선본은 B9A 에 2③ 을 더한 `08_build/artifacts/m4p725/src/if_en_B12A.c`(SHA-256 앞 16 자리 `099f6fb50cb9…`; 합본 26 중 23 SAME 유지). `en_recv` 는 길이 854 B 로 맞았고 남은 차이는 (a) 원본은 `moveb fill,%d1; moveq #-16,%d5; orl %d5,%d1`(자료 레지스터 전폭 `orl`, 확장 없음)인데 우리는 `orib #-16; extbl`, (b) 원본은 `movel epi,%d1; subl %a2@(0,%d1:l:4),%d0`(식 끝에서 `epi` 를 다시 읽는 메모리 피연산자 뺄셈)인데 우리는 포인터를 먼저 읽어 보관, (c) 원본은 `&en_softc[0].is_addr` 를 `moveq #4,%d5; addil #_en_softc,%d5` 로 만드는데 우리는 `pea _en_softc+4`. (a)·(c) 를 바꾸려는 꼴(`0xfffffff0`·`(u_int)-16`·`~0xf`·`is` 포인터·`(int)en_softc + 4`·`sizeof (netif_t)`; run p13·p14)은 모두 같은 객체를 냈고, `len` 을 석 줄로 나누면(p14) 오히려 848 B 로 달라졌습니다. 따라서 원본의 `len` 식은 한 식이고 `(int)en_pkt[epi]` 가 `dd_next` 읽기보다 뒤에 평가되는 꼴이 필요합니다(다음 시험).

남은 셋 그대로: `en_tx_dmaintr`(2 B, d6/d7), `en_recv`(70 B, 위 (a)~(c)), `en_send`(218~226 B 대 224 B).

판단: 같은 방식의 변형 묶음을 더 돌려도 얻는 것이 줄고 있습니다. 다음은 (1) `en_recv` 의 `len` 한 식에서 `en_pkt[epi]` 읽기를 `dd_next` 뒤로 미루는 꼴, (2) 실제 NeXT cc 의 중간 표현(`-dr`) 비교 가능성 확인(kr_run 의 명령 검사가 허용하는지), (3) 그래도 안 풀리면 사용자에게 세 함수의 현재 차이와 선택지(계속 / 그 함수만 원본 바이트 기반 어셈블리 `.s` 로 구현할지 여부 — 이 프로젝트의 선례 `monitor.s` 등)를 여쭙습니다.

### 725.9 마지막 묶음 계획 (코딩 전; 2026-11-02)

kr_run 의 명령 검사(`parse_cmdfile`, `ARG_RE`)는 `-dr` 같은 인수를 막지 않지만, 우리 쪽 RTL 만 나오고 원본과 견줄 RTL 은 없어 "왜 이렇게 나왔나"만 알려 줍니다 — 이번에는 쓰지 않습니다(필요하면 다음).

시험 대상(B12A 기준, 판정 기준은 §725.5 그대로):
1. `en_recv` (a) 원본 `moveb fill,%d1; moveq #-16,%d5; orl %d5,%d1`: 자료 레지스터 전폭 `orl`, 확장 없음 — `(x | -16)` 의 하위 4 비트만 쓰이므로 상위 비트가 쓰레기여도 값이 같다는 점은 python 으로 확인(아래). 시험: `u_char` 지역 변수에 읽고 `| -16`, 읽기를 `int` 지역 변수에 받기.
2. `en_recv` (b) `len` 식에서 `en_pkt[epi]` 가 `dd_next` 읽기 뒤: `x = (…삼항…);` 지역 변수에 받은 뒤 `len = x - (int)en_pkt[epi] - FCS_SIZE;`, 그리고 `if/else` 로 대입.
3. `en_send`: `up = (struct udphdr *)(&bp->ip + 1)` 을 복사 뒤에 두고 `up->uh_sport` 만 그것으로.
4. `en_tx_dmaintr`: 새 가설 없음(상수 2 의 임시가 d6 이어야 함; 이 임시와 동시에 사는 값이 원본은 d7, 우리는 d6 에 있다고 추정) — 이번 묶음에서는 `flags`·`tpe` 선언 위치만 바꿔 시험.
그래도 안 풀리면 사용자에게 선택지를 여쭙습니다(계속 / 세 함수만 원본 바이트 기반 `.s` — 원본이 C 로 컴파일된 것이므로 소스 충실도 면에서 사용자 판단이 필요).

### 725.10 마지막 묶음 결과와 멈춤 (run `m4p725-p15`, 2026-11-02)

**내 잘못 (먼저)**: ① 앞서 사용자께 "저장소의 `next-gcc-2.7.2` 로 `jump.c`·`local-alloc.c`·`cse.c` 를 읽겠다"고 제안했는데, 열어 보니 그 디렉터리는 18 개 파일(`config/i386`·`config/next`·`libgcc2.c`·`longlong.h` 등)뿐이고 `m68k.md`·`cse.c` 가 없습니다. 확인 없이 제안한 것은 제 잘못입니다. ② §725.9 의 codex 검토는 호출이 사용자 중단으로 끝나 받지 못했고, 사용자 지시("작업을 재개합니다")에 따라 그 검토 없이 아래 묶음을 돌렸습니다(진단, 07 불변).

시험(B12A 기준, 변형 B14A~D): `en_recv` 의 `u_char`/`int` 지역 변수로 받은 `en_fill`(X1·X2), `len` 식을 지역 변수로 나눔(X3)·`if/else` 로 대입(X4), `en_send` 의 `up = (struct udphdr *)(&bp->ip + 1)`(Y1), `en_tx_dmaintr` 의 `flags`/`tpe` 선언 위치(Z1·Z2). 결과: 합본 23/26 그대로이고 `en_recv` 는 852·856·862·848 B(원본 854), `en_send` 는 220·218·220·218 B(원본 224), `en_tx_dmaintr` 는 2 B 그대로. 개선 없음 — 같은 방식의 소스 꼴 시험은 여기서 멈춥니다.

python 확인: `(x | -16)` 에서 상위 비트가 쓰레기인 채 전폭 `orl` 한 값과 부호 확장 뒤 `|` 한 값은 모든 바이트 값 256 × 4 가지 상위 비트에서 같다(불일치 0) — 원본의 `moveb; moveq #-16,d5; orl d5,d1` 은 값이 올바르며, 우리 소스에서 이 SImode `orl` 을 내는 꼴은 아직 못 찾음.

남은 셋은 컴파일러 내부 선택(레지스터 배정·블록 배치·확장 생략)이라 소스 꼴만으로 닿지 않을 수 있습니다. 선택지는 사용자 결정이 필요합니다(아래 질문).

### 725.11 공개 GCC 2.7.2.3 소스 읽기 결과 (사용자 허락, 2026-11-02; run `m4p725-p16`·`p17`)

사용자가 "공개 GCC 2.7.2 소스 읽기"를 허락했습니다(가져와 쓰지 않음; `https://sources.debian.org/data/main/g/gcc272/2.7.2.3-15/` 의 `local-alloc.c`·`jump.c`·`global.c`·`regclass.c`·`stmt.c`·`cse.c`·`combine.c`·`expr.c`·`fold-const.c`·`config/m68k/m68k.{md,c,h}` 를 ignored 디렉터리 `scratch/p725/gccsrc/` 에만 둠; NeXT cc 와 다를 수 있어 후보로만 씀, 바이트로 확인).

- **풀림 — `en_recv` 의 `moveq #-16,%d5; orl %d5,%d1`**: `m68k.md` 의 `iorsi3` 는 상수 피연산자에 제약 `K`(−128..127 밖)만 허용하므로 `−16` 은 레지스터에 둔 `orl` 로 나옵니다. 우리가 `orib #-16; extbl` 을 낸 이유는 `char` 값에 `| -16` 이 들어 `fold` 가 `(int)(c | (char)-16)` 로 줄였기 때문이고, `−16` 이 담기지 않는 `unsigned char` 로 읽으면 SImode 가 남습니다. 시험(run p15·p16): `((u_char)((volatile struct en_regs *)P_ENET)->en_fill | -16)` 꼴과 `u_char` 지역 변수 꼴이 모두 원본과 같은 `orl` 을 냄(차이 보기에서 이 줄이 사라짐). → 채택: `en_recv` 의 `en_fill` 은 `u_char` 로 읽음.
- **미해결 (b)** 원본은 `movel epi,%d1; subl %a2@(0,%d1:l:4),%d0`(식 끝에서 `epi` 를 다시 읽는 메모리 피연산자), 우리는 `en_pkt[epi]` 를 `cmpiw #313` 앞에서 읽어 둠. 한 식·세 줄 분할·`if/else`·지역 변수·`volatile` 읽기(p14·p15·p17) 모두 안 바뀜.
- **미해결 (c)** 원본의 `moveq #4,%d5; addil #_en_softc,%d5`(우리는 `pea _en_softc+4`). `expr.c` `plus_expr` 는 정수 상수와 상수 주소의 합을 `plus_constant` 로 접으므로, 4 가 트리의 `INTEGER_CST` 가 아니라 cse 가 나중에 4 로 아는 값이어야 함. `&en_softc[u0].is_addr`(u0 = 0 지역)·`&en_softc->is_addr`·형 변환 꼴(p17)은 864·852·852 B 로 안 맞음.
- `en_send`·`en_tx_dmaintr` 는 그대로(218~226 B 대 224 B, 2 B).

최선본: `08_build/artifacts/m4p725/src/if_en_B15A.c`(SHA-256 앞 16 자리 위 출력; 26 중 23 SAME; `en_recv` 는 852 B, 원본 854 B).

### 725.12 `en_recv` (b)·(c) 의 원인 추정과 다음 묶음 계획 (코딩 전; 2026-11-02)

공개 GCC 2.7.2.3 `fold-const.c` 3338~3385 줄(스크래치 사본)을 읽어 세운 추정입니다. 모두 컴파일·바이트로 확인하기 전에는 사실이 아닙니다.

- **(b)**: `A - B` 에서 `A` 가 삼항(`COND_EXPR`)이고 `B` 가 단순 `VAR_DECL`/`PARM_DECL` 이 아니면 `fold` 가 `save_expr(B)` 를 **조건 앞에** 평가하는 `COMPOUND_EXPR` 로 바꿉니다(`arg0` 가 `COND_EXPR` 인 분기). 그래서 우리 객체는 `en_pkt[epi]` 를 `cmpiw #313` 앞에서 읽습니다. 원본은 삼항이 먼저 계산돼 `d0` 에 남은 뒤 `movel epi,%d1; subl %a2@(0,%d1:l:4),%d0; movel %d0,%d2; subql #4,%d2` — 삼항이 뺄셈의 피연산자가 아닌 시점(변수에 담긴 뒤)에 빼는 꼴. 시험: 삼항을 이미 있는 `int` 변수(`dmacsr`)에 담았다가 `len = dmacsr - (int)en_pkt[epi] - FCS_SIZE`(새 지역 변수 `endp` 를 쓴 X3 은 레지스터가 하나 더 들어 862 B 로 나빠졌음), `if/else` 로 `len` 에 대입 뒤 `len = len - … - …`.
- **(c)**: 원본의 `moveq #4,%d5; addil #_en_softc,%d5` 는 `expr.c` `plus_expr` 가 `plus_constant` 로 접지 못한 합 — 4 가 트리의 `INTEGER_CST` 가 아닐 때. 시험: `(char *)en_softc + (int)&((struct en_softc *)0)->is_addr`(NULL 기준 `offsetof` 꼴; 트리가 `INTEGER_CST` 로 접히지 않을 가능성, 추정).
- 변형 묶음 `B17A~D`(기준 B15A), run `m4p725-p18`. 판정 기준은 §725.5 그대로. 기존 23 함수 유지 확인.

### 725.13 §725.12 codex 검토 판정과 묶음 결과 (run `m4p725-p18`·`p19`, 2026-11-02)

**내 잘못 (먼저)**: §725.12 의 (b) 설명에서 `fold` 가 `save_expr` 를 쓰는 조건을 "비단순 `VAR_DECL`/`PARM_DECL`"이라고만 적었는데, 소스(`fold-const.c` 3355~3358)는 "`SAVE_EXPR` 가 아니고, (`VAR_DECL`·`PARM_DECL` 이 아니거나 부작용 표시가 있음)" 이며 분배한 가지가 `TREE_CONSTANT` 이면 저장을 건너뜁니다(codex 지적이 맞음; 줄을 열어 확인). (c) 에서 "cse 가 나중에 4 로 아는 값이어야 한다"고 단정한 것도 과했습니다(트리 종류와 RTL 상수는 별개).

| codex 주장 | 내 검증(실제 run) | 판정 |
|---|---|---|
| (b) `fold-const.c:3338` 은 `B` 를 조건 앞에 저장하되 예외(상수·`SAVE_EXPR`)가 있음 | 3338·3355~3358 줄 열어 확인 | ✅ (내 서술 보정) |
| (b) 후보 `dmacsr = C ? T : F; len = dmacsr - … ` | p18 A: `en_recv` 860 B(새 장수명 변수로 레지스터 배정이 무너짐: `moveml d2-d6`) | ❌ |
| (b) 후보 `if (C) len = T; else len = F; len -= …` | p18 B: 846 B; 읽기는 삼항 뒤로 가지만 `len` 이 양쪽 가지에서 `d2` 로 먼저 대입되고 `subl %d0,%d2` 라 원본(`d0` 에서 빼고 나중에 `d2` 로 옮김)과 다름 | ❌ |
| (b) 추가 시험: 삼항을 `(u_int)`/`(u_long)`/`(int)(char *)` 로 감쌈 | p19 A·B·D: 852 B, 여전히 `en_pkt[epi]` 를 `cmpiw #313` 앞에서 읽음 | ❌ |
| (c) 후보 NULL 기준 `offsetof` 꼴 | p18 B·D: `pea _en_softc+4` 그대로(접힘) | ❌ |
| (c) 후보 `int off = 4;` | p18 C: `pea _en_softc+4` 그대로 | ❌ |
| (c) 추가 시험: `&en_softc[dma_chip].is_addr`(분기 안에서 `dma_chip == 0`) | p19 C·D: `pea _en_softc+4` 그대로(cse 가 인덱스를 0 으로 접음) | ❌ |
| 변수 분리 확정 불가(`jump.c:1969` cross-jump) | 줄 열어 `if (cross_jump && simplejump_p (insn))` 확인 | ✅ |

**결과**: 합본 26 중 23 SAME 그대로(최선본 B15A). `en_recv`(b)·(c), `en_send`, `en_tx_dmaintr` 는 소스 꼴 시험으로 풀리지 않았습니다(run `m4p725-p1`~`p19`, 변형 약 70 개). 소스 읽기로 알아낸 것(풀린 것): `u_char` 읽기가 SImode `orl` 을 만든다.

판단: 남은 네 곳은 컴파일러 내부 선택이라 같은 방식의 시험은 얻는 것이 거의 없습니다. 사용자 결정이 필요합니다(아래 질문 재제시).

### 725.14 선택지 1: 컴파일러 중간 표현(RTL 덤프) 비교와 `cse.c`·`combine.c` 읽기 계획 (코딩 전; 2026-11-02)

사용자 결정: "일단 1을 진행" — 소스 꼴 시험 대신 컴파일러 내부를 본다.

1. **RTL 덤프 시험(진단, 07 불변)**: 실제 NeXT `cc` 에 `-dr`(.rtl, expand 직후)·`-dj`(.jump)·`-ds`(.cse)·`-dc`(.combine)·`-dl`(.lreg)·`-dg`(.greg) 를 더해 최선본 `B15A` 의 `en_recv`/`en_send`/`en_tx_dmaintr` 를 컴파일합니다. kr_run 의 `parse_cmdfile` 은 인수를 `ARG_RE` 로만 검사하므로 막지 않는다고 읽었으나(`-d?` 가 문자 집합 안), 덤프 파일은 소스 옆(`src/…/*.c.rtl`)에 써지므로 `input changed during build` 검사(kr_run.py 의 `cmp -s input.actual2 input.expected`)에 걸려 run 이 "실패"로 끝나도 덤프는 남는지 먼저 확인합니다. 새 run 번호 `m4p725-d1`(소문자, REGISTRY 확인). 실패하면 덤프 없이 멈추고 그 사실을 적습니다.
2. **무엇을 보나**: (b) `en_pkt[epi]` 읽기가 어느 단계에서 `cmpiw #313` 앞에 놓이는지(expand 직후 `.rtl` 에서 이미 앞이면 fold/expand 의 순서, 아니면 cse/combine); (c) 원본의 `moveq #4,%d5; addil #_en_softc,%d5` 가 되려면 어떤 RTL(`(plus (reg) (symbol_ref))`)이 cse 이후 남아야 하는지 — 우리 `.cse` 에서 `pea _en_softc+4` 가 만들어지는 자리를 찾고 `cse.c` `fold_rtx` 의 `PLUS` 분기를 읽어 접히지 않는 조건을 구함.
3. **판정**: 얻은 조건을 만족하는 소스 꼴을 하나씩 세워 시험(§725.5 기준 그대로). 조건을 못 찾으면 사용자에게 알리고 선택지(2·3)를 다시 여쭙니다. 원본에는 RTL 이 없으므로 덤프는 "우리가 왜 이렇게 냈나"만 알려 주고, 원본과 같아졌는지는 항상 바이트로 판정합니다.

### 725.15 선택지 1 결과: RTL 덤프와 소스 읽기 (run `m4p725-d1`, 2026-11-02)

**내 잘못 (먼저)**: §725.14 는 덤프가 "항상 소스 옆"에 써진다고 했고 `kr_run` 검사에 걸려 run 이 실패할 수 있다고 봤습니다. codex 가 드라이버가 `-dumpbase %b.c` 를 넘기므로 덤프는 **현재 디렉터리**에 써진다고 바로잡았고, `kr_run.py` 를 열어 확인했습니다: 끝의 `cmp -s input.actual2 input.expected` 는 준비 때 정한 파일 목록(`files + run.cmd + run.sh`)만 다시 해시하므로 새 파일은 run 을 실패시키지 않으며(254 줄 근처), `RUNIN stage/rtl` + `@R/` 경로(209~246 줄)로 덤프를 `stage/rtl` 에 모을 수 있습니다. 또 `-dJ`·`-df` 를 넣지 않았다는 지적도 맞았습니다(이번 run 에 `-dr -dj -ds -dc -dl -dg -dJ -df` 모두 넣음).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| 덤프 문자·확장자 대응 맞음(+`-dJ→.jump2`, `-df→.flow`) | run `m4p725-d1`: `if_en_B15A.c.{rtl,jump,cse,combine,lreg,greg,jump2,flow}` 8 개 생성됨(`stage/rtl/`) | ✅ |
| 덤프는 현재 디렉터리 | `RUNIN stage/rtl` 에서 `stage/rtl/` 에 생김 | ✅ |
| `kr_run` 검사는 새 덤프로 실패하지 않음, 덤프 삭제 없음 | `kr_run.py` 205~256 줄을 열어 확인; run 상태 `00 0` | ✅ |
| `RUNIN stage/<dir>` 지원 | 위 run 이 그대로 동작 | ✅ |

**원인 확인 (b)**: 덤프 `if_en_B15A.c.rtl` 의 `en_recv` 에서 `epi` 읽기(insn 345)·`en_pkt[epi]` 읽기(349)가 `cmpiw #313`(350~352) **앞**에 이미 있습니다 — 즉 expand 단계에서 이미 앞이며 cse/combine 때문이 아닙니다. `fold-const.c` 3338~3385 줄(`arg0` 가 `COND_EXPR` 이고 `arg1`(= `(int)en_pkt[epi]`)이 단순 `VAR_DECL`·`PARM_DECL`·상수가 아닐 때 `save_expr(arg1)` 을 조건 앞에 평가) 와 일치합니다. `tree.c` 의 `save_expr` 는 `TREE_CONSTANT` 이거나 `TREE_READONLY && !TREE_SIDE_EFFECTS` 이면 `SAVE_EXPR` 로 감싸지 않으므로, `arg1` 이 읽기 전용 객체면 분배된 가지마다 계산되고 두 가지의 같은 꼬리가 cross-jump 로 합쳐져 원본처럼 합류점 뒤에 `movel epi,%d1; subl mem,%d0` 이 남을 수 있습니다(추정, 시험 전). 같은 식에서 삼항을 `dmacsr` 같은 변수로 먼저 받는 꼴(B17A)은 `subl mem` 은 안 나오고 레지스터 배정이 무너짐.

**원인 추정 (c)**: `expr.c` `plus_expr` 는 `INTEGER_CST` + 상수 주소를 `plus_constant` 로 접어 `pea sym+4` 를 만듭니다. 원본의 `moveq #4,%d5; addil #sym,%d5` 는 `expand_binop(add_optab, op0 = CONST_INT 4, op1 = symbol_ref)` 가 `op0` 을 레지스터로 강제하는 경로(트리에서 4 가 `INTEGER_CST` 가 아니었거나 `mode != ptr_mode` 였음)에서만 나옵니다. 우리 덤프는 같은 자리가 expand 때 이미 `(const (plus (symbol_ref en_softc) 4))` 입니다(`.rtl` 1224 줄). `int off = 4`·NULL 기준 `offsetof`·`&en_softc[dma_chip]` 도 expand 나 cse 가 접습니다(p18·p19). 접히지 않는 원본 소스 꼴은 아직 모름.

**남은 셋(`en_recv` (b)·(c), `en_send`, `en_tx_dmaintr`)은 풀리지 않음.** 위 덤프로 (b) 는 `fold` 단계의 문제임을 알았고, 읽기 전용 피연산자 꼴을 시험 후보로 가집니다. 덤프 5 MB × 8 은 `08_build/runs/m4p725-d1/` 에 둠(필요 없어지면 삭제).

### 725.16 (b) 풀림: 읽기 전용 원소 (run `m4p725-p20`, 2026-11-02)

덤프(§725.15)가 가리킨 `fold-const.c`/`tree.c` 조건(읽기 전용 피연산자는 `save_expr` 가 `SAVE_EXPR` 로 감싸지 않아 삼항의 가지마다 뺄셈이 분배되고 같은 꼬리가 cross-jump 로 합쳐짐)을 시험했습니다: `len = (…삼항…) - (int)((struct en_pkt *const *)en_pkt)[epi] - FCS_SIZE;`(변형 B19A·B·C: `const` 한정 포인터 배열로 읽기). 결과 `en_recv` 는 **850 B**(852 B 에서 변함)이고, 차이 보기에서 `epi` 를 합류 뒤에 다시 읽는 `subl mem` 줄들이 사라져 **남은 차이는 (c) 하나**(`pea _en_softc+4` 대 `moveq #4,%d5; addil #_en_softc,%d5; movel %d5,%sp@-`, 4 B)입니다. 합본 23/26 그대로, `en_send` 218 B·`en_tx_dmaintr` 2 B 도 그대로.

주의(사용자께 나중에 여쭐 항목): 이 `const` 한정 읽기는 **바이트로 가려지지 않는 작성 꼴**입니다. 원본이 어떤 선언·식으로 읽기 전용 원소 읽기를 만들었는지는 모릅니다(예: `en_pkt` 를 `struct en_pkt *const en_pkt[4]` 로 선언하고 `en_bufalloc` 에서 형 변환으로 채움). 최선본: `08_build/artifacts/m4p725/src/if_en_B19A.c`(SHA-256 앞 16 자리 위 출력).

### 725.17 `en_tx_dmaintr` 의 d6/d7 원인과 `en_send` 시험 (run `m4p725-p21`, 2026-11-02)

**내 잘못 (먼저)**: 이번 묶음(B20A~D: `en_pkt_hdr` 를 `volatile`/`const` 로, 맞바꿈을 `volatile long` 으로)은 §725.16 에서 정한 순서(계획 → codex 검토 → 코딩)를 따르지 않고 "cse 가 절대 주소를 접지 않게 할 수 있다"는 추정만으로 바로 돌렸습니다. 진단(07 불변)이라 되돌릴 것은 없고, 결과는 모두 ❌ 입니다(`en_send` 220·218·218·218 B, 원본 224 B).

**`en_tx_dmaintr` 의 2 B 원인(확인된 부분)**: 우리 객체와 원본의 함수 전체에서 `d6`/`d7` 에 값을 싣는 재적재(reload) 명령 24 개를 python 으로 차례대로 견주니(`moveq #imm`·`movew %a2,…` 등) **24 개 중 하나(5 번째, 첫 `moveq #2`)만** 원본 `d6`, 우리 `d7` 이고, 나머지 23 개는 같습니다. `reload1.c`(`allocate_reload_reg`, 4749~4860 줄 읽음)는 스필 레지스터를 `i = last_spill_reg` 부터 **돌려 가며**(`i = (i + 1) % n_spills`) 고르므로, 직전 재적재가 `d6`(`moveq #3`)이면 다음은 `d7` 이 되는 게 정상입니다. 원본은 그 사이 사슬(chain) 순서에서 `d7` 을 쓰는 재적재가 하나 더 있어 포인터가 한 바퀴 돌았거나, `d7` 이 그 자리에서 쓸 수 없었다고 읽힙니다. 이는 소스 한 줄로 고칠 수 있는 성격이 아니라 **같은 함수 안 앞쪽 재적재 개수/순서**(블록 순서, 분기 모양)가 원본과 다르다는 뜻이며, 아직 어느 문장 때문인지 모릅니다.

**`en_recv` (c)**: 덤프에서 우리 `pea _en_softc+4` 는 expand 때 이미 `(const (plus (symbol_ref en_softc) 4))` 입니다. 원본의 `moveq #4; addil #sym` 은 `expand_binop(add, CONST_INT 4, symbol_ref)` 경로이며 트리가 `INTEGER_CST` 로 접히지 않는 꼴이어야 하는데 못 찾음(시험한 꼴 §725.11·13·15).

**상태**: 합본 26 중 23 SAME 그대로(최선본 B19A: `en_recv` 850 B(원본 854 B, 차이 (c) 하나), `en_send` 218 B, `en_tx_dmaintr` 2 B). 남은 셋은 모두 컴파일러 내부 선택(스필 순서, 상수 접기, cse 비용)이며 지금까지 약 80 변형으로 안 풀림.

## 726. M4-194 구현 계획 — m68k `if_en.c`: 세 함수를 파일 범위 `asm` 으로 (코딩 전; 2026-11-02)

**사용자 결정(2026-11-02, AskUserQuestion 선택지 2 → D163 후보)**: `en_tx_dmaintr`·`en_recv`·`en_send` 는 소스 꼴 시험(약 80 변형, §725.4~17)으로 풀리지 않아 **원본 바이트 기반 어셈블리**로 구현합니다. 원본은 C 로 컴파일된 것이므로 소스 충실도 면의 예외이고, 선례는 `in_cksum.c` 의 `oc_cksum`(D111: 한 파일 끝의 파일 범위 `asm`, 다만 그 함수는 원본이 손으로 쓴 어셈블리)입니다.

**방법(진단 → 구현 순서; 판정 기준 "26 함수 모두 SAME, 자료·문자열·bss 같음")**
1. 골격: 최선본 `if_en_B19A.c` 의 세 함수를 NeXT `cc -S` 로 낸 어셈블리를 골격으로 삼습니다(컴파일러가 아는 `jbsr`·`jbcc` 꼴과 지역 레이블 규칙을 그대로 쓰기 위해). kr_run 의 `RUNIN stage/asm`(§725.15)으로 `-S` 를 한 번 돌려 `.s` 를 받습니다. 새 run `m4p725-s1`.
2. 원본 바이트로 패치: 골격과 원본의 차이(세 함수 합쳐 `d6/d7` 한 곳, `pea`/`moveq+addil` 한 곳, `lea` 한 곳 — python 으로 확인한 차이)만 고칩니다. 지역 레이블은 `Len…` 접두로 이름을 바꿔 파일의 다른 `L` 레이블과 겹치지 않게 하고, 정적 bss 네 낱말(`rx_active` 등)은 asm 안 `.lcomm`.
3. 배치: C 함수 사이에 파일 범위 `asm("…")` 블록을 둡니다(원본 함수 순서 보존; D111 선례처럼 `.text` 로 시작). 호출하는 C 쪽 정적 함수(`en_getreg` 등)·COMMON 기호는 이름으로 참조.
4. 확인: 진단 probe + `m68k_funcbytes.py` 26/26 SAME(재배치 대상 포함), 절 크기(`__text` 8724 B, `__data` 1080, `__bss` 20, `__const` 14, `__cstring`)와 COMMON·미정의 기호 비교(`datachk.py`), STABS 가 없는 함수 때문에 L1/L2 판정이 어떻게 되는지(D111 `in_cksum` 이 OBJECT_MATCH 였으므로 같을 것으로 보나 확인 전).
5. 그 뒤 구현: `07_kernel/src/machdep/m68k/if_en.c`, `07_kernel/nextmach/nextif/if_enreg.h`(사본), `stage_m68k.py` 등록(`M4FILES`·`M4HEADERS`·`EXCEPTS`), M5 run·x86 게이트·zerofill(CODE+BSS_INFERRED 예상), 상태 도구 ACCEPTED, 기록·PROVENANCE·MODIFICATIONS·DECISIONS·증거 문서·HANDOFF·메모리. 이 단계는 4 가 끝난 뒤 별도 절(§727)로 계획합니다.
6. 바이트로 가려지지 않는 이름·꼴은 07 쓰기 전에 AskUserQuestion 으로 여쭙습니다(정적 보조 셋의 이름, `ENF_RXMODE`/`ENF_TXGUARD`, `is_tpe_count`·`is_rxstate`·`is_multicast`·`is_nmulticast`·`is_txstat`, `en_pkt`·`en_pkt_hdr`·`dbgstack`, `crctab`, `en_pkt` 읽기 전용 읽기 꼴(b), `u_char` 읽기 꼴, `if_enreg.h` 07 자리, 정적 bss 이름).

**위험(미리 적음)**: (가) 파일 범위 `asm` 은 GCC 2.7 의 문자열 이어 쓰기·줄바꿈 규칙에 의존(precedent: `in_cksum.c` 의 `asm("` 여러 줄); (나) 어셈블러가 가지(branch) 크기를 원본과 다르게 고르면 바이트가 달라짐 → 원본이 쓴 `bnes`/`bnew`/`bras`/`braw` 를 `jb…` 로 두고 결과로 확인, 안 맞으면 명시 꼴(`bne.w` 등)로; (다) 함수의 STABS(N_FUN) 가 사라짐 → 4 에서 확인; (라) 정적 bss 가 asm `.lcomm` 이라 C 쪽 `done`(en_bufalloc) 정적과 순서가 원본(559 8 → 559c…)과 맞아야 함.

### 726.1 §726 codex 검토 판정과 asm 진단 결과 (run `m4p725-s1`·`p22`·`p23`, 2026-11-02; 07 불변)

**내 잘못 (먼저)**: 첫 asm 변형(run `m4p725-p22`)은 컴파일러 어셈블러가 `FATAL: Symbol LC7 already defined` 로 멈췄습니다 — 골격의 문자열 레이블 `LC<n>` 이 C 쪽 새 컴파일의 `LC<n>` 과 겹쳤는데, 계획은 `L<n>` 지역 레이블만 이름을 바꾼다고 적었습니다(codex ② 지적이 맞았고 `LENC<n>` 으로 바꿔 해결). 또 골격을 처음 자를 때 `.cstring` 문자열 블록(함수 앞에 놓임)을 빠뜨려 다음 함수의 문자열이 끼어들었습니다(고침).

| codex 주장 | 내 검증 | 판정 |
|---|---|---|
| `N_FUN` 부재 자체는 funcbytes·L1 실패 원인이 아님, 함수 라벨·`.globl` 누락은 대응을 깨뜨림 | funcbytes(비 STABS 심볼 사용) 26/26 SAME; probe `full_span True`·`missing_names []`·`extra_names []`; `.globl` 포함 | ✅ |
| 레이블 이름 변경만으로 부족: 문자열/상수 레이블 참조, 섹션 상태 | `LC7` 중복으로 실제 실패 → `LENC<n>`; 블록 끝마다 `.text` 로 복귀 | ✅ |
| `.lcomm` 순서·이름 대응 문제, `cmpv.py` 가 점 있는 이름만 모음 | `cmpv.py` 가 `_rx_*`·`_epi` 를 놓침 → 고침; 객체의 bss 순서 `_done.64`(10164)·`_rx_active`(10168)·`_rx_cached`(10172)·`_rx_init`(10176)·`_epi`(10180) 가 원본 0x40b5598·559c·55a0·55a4·55a8 순서 | ✅ |
| 재배치 종류가 C 결과와 달라질 수 있음; funcbytes 는 VANILLA 만 받음 | `m68k_funcbytes.py` 머리말대로 VANILLA 이외면 종료하는데 종료하지 않고 26/26 SAME | ✅ (재배치 형식까지 같음) |
| 가지 크기·명시 크기 문법 미검증 | 골격의 `jb…` 를 그대로 써서 해당 없음(원본과 바이트 같음) | ✅ |
| 골격은 B19A 전체 TU 로, `d6/d7` 차이 오프셋 0x1a8·0x1aa | `cc -S` 는 전체 TU(`m4p725-s1`); python: 0x408eeb2−0x408ed0a = 0x1a8, 0x408eeb4−0x408ed0a = 0x1aa | ✅ |
| `datachk.py` 는 자료 재배치 대상을 검증하지 않고 COMMON·미정의 심볼도 비교하지 않음 | 맞음(내가 만든 도구; 재배치 칸 16 B 를 가림) → 이번엔 COMMON·미정의를 따로 비교: COMMON 34 개 중 원본 기호표에 없는 것 0, 미정의 68 개 중 0; `endriver` 의 포인터 칸 넷은 §725.3 에서 대상까지 확인 | ✅ |

**결과(변형 `if_en_C1.c` = B19A 에서 `en_tx_dmaintr`·`en_recv`·`en_send` 를 원본 바이트 기반 파일 범위 `asm` 으로 바꿈; `scratch/p725/gen_asm726.py`)**: ① funcbytes **26/26 SAME**(재배치 대상 포함; 정적 `en_getreg`·`en_putreg`·`en_regok` 포함) ② 절: `__text` 8724 B(= 원본 범위 8724 B), `__data` 1080 B(재배치 칸 16 B 를 뺀 1064 B 원본과 같음), `__bss` 20 B, `__const` 14 B, `__cstring` 345 B(= 원본 소유 12 문자열 331 B + 링크 때 합쳐지는 `10MB Ethernet\0` 14 B; 나머지 12 개는 원본 주소 0x40abf99~0x40ac0e4 와 같은 순서·내용) ③ probe: `full_span True`, `judgement provisional`(L1 이유는 `__DATA,__bss: unverified` 하나 — CODE+BSS_INFERRED 경로, 선례 `ev.c`), `missing_names []`, `extra_names []`, `undefined_not_in_original []`, 컴파일 경고 0.

바이트는 맞았으므로, 남은 일은 07 쓰기와 기록입니다. 07 을 쓰기 전에 바이트로 가려지지 않는 이름·꼴을 사용자께 여쭙니다(§726 6번).

## 727. M4-194 D163 구현 계획 — 07 `src/machdep/m68k/if_en.c`, 07 `nextmach/nextif/if_enreg.h`(코딩 전, 2026-11-02)

사용자 결정(D163, 2026-11-02; AskUserQuestion 답):
- ① 세 함수 `en_tx_dmaintr`·`en_recv`·`en_send` 는 파일 범위 `asm`(§726; 선택지 2). 소스 충실도 면의 예외이고 선례는 D111(`in_cksum.c`)입니다.
- ② 정적 보조 셋의 이름: `en_getreg`(0x408db8a)·`en_putreg`(0x408dbd2)·`en_regok`(0x408dc16). 원본에 기호가 없어 바이트로 가려지지 않는 이름입니다.
- ③ `struct en_softc` 의 새 칸: `is_tpe_count`(+522 int)·`is_rxstate`(+534 `u_int`)·`is_multicast`(+1314 `struct ether_addr *`)·`is_nmulticast`(+1318 int)·`is_txstat`(+1322 `u_char`), 플래그 `ENF_RXMODE`(0x20)·`ENF_TXGUARD`(0x40). 오프셋·크기·부호는 원본 바이트로 확정(§725).
- ④ GDB 전역은 진단 선언 그대로: `vm_offset_t dbgstack;` `struct en_pkt {ether; ip; udp; char pad[536]}`(578 B) `struct en_pkt *en_pkt[4];` 이름 없는 구조체 변수 `en_pkt_hdr`(42 B). 전역 기호 이름은 원본 기호표가 정합니다(COMMON).
- ⑤ 레지스터 상수(0x04·0x80·0x8e·0x41·0xa1·0xa2·0x40·0x0f·313 등)는 숫자로 두고 뜻은 주석으로 적습니다. 새 매크로 없음. `if_enreg.h` 는 NeXTMach 원문 그대로 `07_kernel/nextmach/nextif/if_enreg.h` 에 둡니다(D013/D104 선례).

방법:
1. 꼴 F(`08_build/artifacts/m4p727/src/if_en_F.c`) = 진단 C1(`m4p725/src/if_en_C1.c`, SHA-256 `5cf00e8f…`, 26/26)에 머리 주석·표지·상수 주석을 더한 것이고, 꼴 L = F 에서 주석을 비운 것입니다. scratch `p727/gen_p727.py` 가 C1 에서 만듭니다(`--write` 로 07 파일도 씀).
   - 표지: `plan 725 diagnostic:` → `plan 727 (D024, D163):` 등 결정 번호(헤더 경로 바꿈은 D104, `next/cpu.h` 이름 블록은 D110 꼴), `plan 726 (D163)` → `plan 727 (D163)`.
   - 머리 주석: NeXTMach `if_en.c` 머리(HISTORY 포함, 처음 `#import <en.h>` 앞까지)를 그대로 두고 그 뒤에 1997 바뀜 목록과 "작성 선택" 문단을 넣습니다(D013; D161·D162 꼴). 바뀜 목록은 아래 python 비교로 만든 함수별 차이이고, 작성 선택은 ②–⑤ 와 `u_char` 읽기·goto 꼴·세 함수 asm 입니다.
   - 구역: 다시 쓴 함수와 새 함수, 새 구조체 칸, GDB 선언, `crctab`, 세 asm 블록은 `plan 727 … BEGIN/END` 로 표지합니다. NeXTMach 와 같은 함수는 표지하지 않습니다. 함수별 같음/다름은 python(`fcount3.funcs` 로 NeXTMach·C1 의 함수 글을 견줌)으로 정하고, 예비 비교(`fcount3.funcs`, 아직 단언 아님)에서 NeXTMach 의 `ppkt`·`en_tx_dmaintr`·`en_recv`·`en_send` 는 C1 에 C 글로 없습니다(`ppkt` 는 NeXTMach `if_en.c:741` 의 `#if	DEBUG` 안 `:742` 에 정의되고, m68k 빌드에는 `DEBUG` 가 없음(§689.1); 앞 셋은 asm).
   - 상수 주석: `if_enreg.h` 의 레지스터 비트 이름으로 값이 정확히 분해되는 경우만 이름을 적고(예: txmask `0x8e` = `0x80|0x08|0x04|0x02` = READYIE|UNDERFLOWIE|COLLIE|COLL16IE 처럼 python 이 분해해 확인한 것만), 이름이 없는 값은 "no name in if_enreg.h" 로 적습니다. 주석은 코드를 바꾸지 않으므로 L 과 F 의 토큰이 같아야 합니다.
   - 단언(python): F 와 L 의 토큰·토큰 줄이 같고, L 과 C1 의 토큰이 같으며(주석 밖 글이 진단과 같음), NeXTMach 와 견준 표지 없는 바뀐 줄이 0 이어야 합니다. 머리 주석 보존도 단언합니다.
2. 새 머리 `07_kernel/nextmach/nextif/if_enreg.h`: `01_resources/upstream/nextmach/mk-108.1/nextif/if_enreg.h` 그대로(SHA-256 `01f3be2b…`, 86 줄; 진단 사본과 같음을 이미 확인). PROVENANCE 한 행(`nextmach`, 변경 없음, `if_en.c` 가 읽음, m68k 만), MODIFICATIONS 는 변경이 없으니 행 없음(D162 의 `evsio.h` 선례).
3. `stage_m68k.py`: `M4FILES[727] = list(M4FILES[724]) + ['if_en.c']`, `M4HEADERS[727] = list(M4HEADERS[724]) + [('nextif/if_enreg.h', 'src/bsd/nextif/if_enreg.h')]`(`if_bus.h` 와 같은 자리), `EXCEPTS[727] = dict(EXCEPTS[724])`, docstring `--plan` 목록에 727.
4. 회귀(공유 07 머리는 바꾸지 않고 새 머리 하나만 더함): 계획 724 스테이지를 다시 만들어 보관본 `m0p724-a1-stage` 와 같은지, 새 스테이지 `m0p727-a1-stage` 와의 차이가 `src/machdep/m68k/if_en.c`·`src/bsd/nextif/if_enreg.h` 둘뿐인지 봅니다. M5 205 줄을 새 스테이지에서 컴파일(`m3p727-cc1`)해 받아들인 `m3p724-cc1` 의 출력과 직접 견줍니다(`run.json` 만 달라야 함; 명령 파일은 계획 번호만 달라야 함). x86 입력(`m4_x86_inputs.py s6ln`)과 `x86gate` 가 앞과 같아야 합니다.
5. 확인 run `m4p727-p1`(F, L; 진단 때와 달리 `inc` 없이 스테이지 헤더 `nextif/if_enreg.h` 를 읽음):
   - funcbytes **26/26 SAME**(정적 셋 포함, 재배치 대상까지), 경고 0.
   - 절: `__text` 8724 B(= 구간 [0x408db8a, 0x408fd9e) 8724 B), `__data` 1080 B(재배치 칸을 뺀 1064 B 같음, `endriver` 포인터 넷은 대상까지), `__bss` 20 B(순서 `_done.64`·`_rx_active`·`_rx_cached`·`_rx_init`·`_epi` ↔ 원본 0x40b5598·559c·55a0·55a4·55a8), `__const` 14 B, `__cstring` 345 B.
   - 원본 기호표에 없는 외부 정의·COMMON·미정의 0(D136), F 와 L 의 `canon`·`obj_sig` 같음, F 와 진단 C1 객체의 `canon` 같음. `canon`(절 바이트·재배치)과 `obj_sig`(비 STABS 기호, STABS 개수)는 STABS 내용을 비교하지 않으므로, STABS 문자열(포함 파일 이름 등)은 두 객체에서 따로 뽑아 차이를 기록합니다(관문 아님; §727.1).
6. `-E` run `m4p727-e1`: F 와 L 의 전처리 토큰이 같고 stderr 0, i386 경로 0.
7. 최종 run `m4p727-a1`(명세 `08_build/artifacts/m4p727/spec.json`; 객체 `if_en`, `m4_id` `{"range":["0x408db8a","0x408fd9e"],"rows":[],"partial":["m68k-259","m68k-260"],"basis":…}`(진단 명세의 `basis` 그대로), `refs` = p1 의 L 객체 SHA-256, `bss_inferred: ["if_en"]`): `gate.ok`, 등급 `CODE+BSS_INFERRED`(L1 이유 `__DATA,__bss: unverified` 하나뿐이어야 함). 그다음 zerofill(`m5_m68k_zerofill.py`): 후보 [0x40b5598, 0x40b55ac) 20 B, 받아들인 다른 bss 자리와의 겹침 0(python), 결론 `reference-inferred`. 확인 기록(의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지, 종료 0, i386 0, `-E` 같음, F = L, 원본에 없는 이름 0).
8. 상태 도구 `ACCEPTED` 에 넷 칸 항목(zerofill 기록) 하나를 더하고 두 번 돌려 같음을 보며 앞 행이 그대로임을 대조합니다.
9. 기록: 근거 `06_reconstruction/evidence/m68k-if_en.md`·`m68k-if_en.diff`(NeXTMach 대비), 상태표 한 행, PROVENANCE 두 행(`if_en.c`, `if_enreg.h`; 일곱 칸, 경로당 한 행), MODIFICATIONS 한 행(`if_en.c`), DECISIONS D163, HANDOFF·메모리(둘 다 21/26 이라 적힘 → 고침)·계획 §727.x. 큰 RTL 덤프(`08_build/runs/m4p725-d1`, 약 5 MB × 8)는 기록이 끝난 뒤 지웁니다(디스크 97%).

상태 기대(python): 객체 64 → 65(OBJECT_MATCH 50, CODE+BSS_INFERRED 14 → 15), 행 88/188 그대로(행 259·260 은 `exact` 0 이라 이미 부분 행에 있고 덮이지 않음), 행 최소 바이트 128652 B(59.60%) 그대로, `object_bytes` 172650 + 8724 = 181374(python). 부분 행 목록 그대로(259·260 이미 포함).

M7 의무(적어 둠): COMMON 34 개와 미정의 68 개의 합침(D136), 정적 bss 다섯(`_done.64`·`_rx_*`·`_epi`)의 자리와 이름이 asm `.lcomm` 이라는 점, 세 asm 함수가 C 가 아니라 바이트 기반 어셈블리라는 점(M6/M7 때 C 로 다시 쓰자는 요구가 생기면 §725 의 시험이 근거), `endriver`·`eninfo`·`crctab`·`en_pkt`·`en_pkt_hdr`·`dbgstack`·`etherbcastaddr` 의 정의 자리.

판정(미리 정함): 4–8 단계와 통합 확인 기록이 모두 `ok` 이고 상태 도구 출력이 위 기대와 같으면 받아들입니다. 어긋나면 어느 단계가 어긋났는지 적고 멈춥니다(기준을 늦추지 않음).

위험(미리 적음): (가) 07 `if_en.c` 는 진단 C1 의 글을 쓰되 표지·주석만 바뀌므로 객체가 같아야 하나, 주석 안의 `*/`·문자열 이스케이프 오류가 asm 블록 글을 깨뜨릴 수 있음 → L 과 C1 토큰 단언과 p1 의 26/26 이 막음. (나) 스테이지의 `nextif/if_enreg.h` 를 진단은 `-I` 로 읽었고 07 은 스테이지 헤더로 읽어 STABS 의 포함 파일 이름이 다름 → `canon`·`obj_sig` 비교로 확인. (다) `fcount3` 함수 찾기가 K&R 꼴을 놓칠 수 있음 → 표지 단언(표지 없는 바뀐 줄 0)이 최종 보증.

### 727.1 §727 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-02)

먼저 제 잘못: §727 첫 판 5 단계는 "`canon`·`obj_sig` 로 STABS 경로 차이를 확인"하도록 읽혔으나 두 함수는 STABS 내용을 보지 않습니다(고침: 위 5 단계). 또 첫 판에 상수 주석 예시를 "READYIE|UNDERFLOWIE|COLL16IE..." 로 얼버무렸고(COLLIE 빠짐; python: `0x8e == 0x80|0x08|0x04|0x02`), 고쳤습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 단계 누락 없음 | §724·§689.1 을 이번 세션에 읽고 대조(스테이징·회귀·p1·-E·a1·zerofill·확인 기록·상태 도구·기록 모두 §727 에 있음) | ✅ |
| 상태 기대 수치 맞음(65/50/15, 88/188, 128652, 181374) | python: 172650 + 8724 = 181374, 0x40b55ac - 0x40b5598 = 20; `m4_m68k_status.py` 102–114(`tiled_rows` 는 `exact != '1'` 제외)와 `seen_rows` 는 `rows` 로만 늘어남을 읽음 | ✅ |
| 행 259·260 은 exact 0 | `m68k-m4-inventory.tsv` 63·64행을 열음(259, 260 모두 `exact` 칸 0; codex 의 "63행" 은 259 만 해당) | ✅ (줄 번호는 63·64 로 고쳐 받음) |
| 2-튜플 등록은 `07_kernel/nextmach` 를 가리킴, `if_bus.h` 와 같은 꼴 | `stage_m68k.py:599–601`(root 기본값), `:170`(`if_bus.h` 항목) | ✅ |
| 파일 범위 asm 은 실제 개행·`\"`·`\\12\\0` 을 가져 주석 제거기가 문자열을 보존해야 함 | `if_en_C1.c:911–916`(`asm("` 뒤 실제 개행, `.ascii \"…\\12\\0\"`); 쓸 `strip_comments` 는 `gen_p724.py` 의 것으로 따옴표 안을 건너뛰고 `\\` 를 처리함 | ✅ (L 과 C1 토큰 단언이 보증) |
| `canon`·`obj_sig` 는 STABS 내용을 안 봄 | `m3_m68k_diag.py:34–43`(절 바이트와 재배치만), `l2_prefix_diff.py:48–53`(`stabs=` 개수) | ✅ (위 잘못; 5 단계 고침) |

2 차 자기검사: ✅ 행의 근거는 이번 세션에 연 줄이거나 python 출력입니다(codex 가 준 줄 번호 `3492`·`3498`·`3509`·`2022`·`3086` 등은 옮기지 않았습니다).

### 727.2 구현 결과(2026-11-02)

먼저 제 잘못:
1. 07 파일 첫 판의 `next/cpu.h` 이름 블록 주석이 줄 목록에서 `I_ENETX`·`I_ENETR` 의 254·255 행을 빠뜨렸습니다(진단 때부터 있던 오기). PROVENANCE 줄 범위를 `next/cpu.h` 에서 다시 대조하다 찾았고, 주석을 고친 뒤 파일 SHA 가 바뀌어 M5(`m3p727-cc2`)·확인(`m4p727-p2`)·`-E`(`m4p727-e2`)·최종(`m4p727-a2`) 을 새 run 번호로 다시 돌렸습니다. 첫 판 run(`m3p727-cc1`, `m4p727-p1`, `-e1`, `-a1`)은 REGISTRY 에 남고 기록 파일은 새 run 으로 덮었습니다. 객체 SHA-256 은 두 판이 같습니다(주석만 바뀜).
2. 생성기 첫 판이 `fcount3` 의 줄 번호로 함수 범위를 잡았는데, 그 도구는 문자열 안의 줄바꿈을 지워 asm 블록 뒤 줄 번호가 밀립니다. 함수 이름은 머리 줄에서, 범위는 0 열 `{`·`}` 로 직접 잡도록 고쳤습니다. 또 거친 비교로 `en_arp_input` 이 NeXTMach 와 다르다고 적었으나 정확히 비교하니 같습니다(바뀐 함수는 열한 개).
3. 원천 검사 첫 판은 함수 앞 주석과 빈 줄을 표지 없는 바뀐 줄로 셌습니다(구역을 앞 주석·빈 줄과 합치도록 고침). `-E` 검사기의 렉서는 문자열 안 줄바꿈을 단언으로 막았습니다(asm 블록은 실제 줄바꿈이 있는 문자열이라 F·L 에 같게 허용하도록 고침).
4. PROVENANCE 초안이 `next/cpu.h` 의 고지를 "(c) NeXT" 로 적었습니다(실제 "(c) 1986 NeXT"; 파일을 열어 고침). 머리 주석에 "구역은 바뀐 줄만"이라고 쓸 뻔했으나 합쳐진 구역에 같은 줄이 섞이므로 문장을 고쳤습니다.
5. §727 첫 판 5 단계의 STABS 검사 문장(§727.1)과 상수 주석 예시(COLLIE 빠짐)를 고쳤습니다.

결과(모두 미리 정한 기준대로):
- 1 07 `07_kernel/src/machdep/m68k/if_en.c`(2007 줄, SHA-256 `78ccf37360eb4dc88a01d15590d0e5953e855d6965ba9d0b6584f0d1bf051c04`)는 scratch `p727/gen_p727.py --write` 가 진단 C1 에서 만들었습니다. 원천 검사(`chk727.py`): F = L 토큰, L = C1 토큰, 표지 없는 바뀐 줄 0(NeXTMach 와 92 hunk, BEGIN/END 구역 12), 머리 주석 보존.
- 2 07 `nextmach/nextif/if_enreg.h`: NeXTMach 원문 그대로(SHA-256 `01f3be2b…`). `stage_m68k.py` 789 → 792 줄(`M4FILES`·`M4HEADERS`·`EXCEPTS[727]`, 머리말).
- 3 회귀: `m0p724-r727-stage` = 보관본 `m0p724-a1-stage`(1019 파일), `m0p727-a2-stage`(1021)와의 차이는 `if_en.c`·`if_enreg.h` 둘뿐입니다. `m5-724.cmd` = 보관본, `m5-727.cmd` 는 계획 번호만 다릅니다. M5 205 `m3p727-cc2` 의 617 파일은 받아들인 `m3p724-cc1` 과 `run.json` 만 다르고, `compare`(`m3-m68k-p727-compare-20261102.json`)는 `differ_unexpected`·`lost` 가 비었고 객체 항목이 p724 와 같으며 `stage_vs_test_stage` 는 두 파일만 늘었습니다. x86 입력(`m4-x86-inputs-p727-20261102.json`)은 `ok` 이고 p724 와 같고 x86gate 는 `plan`·`tool_sha256` 만 다릅니다(x86 스테이지는 이 파일을 읽지 않아 주석 수정 뒤에는 다시 돌리지 않음).
- 4 확인 run `m4p727-p2`(`m4-m68k-probe-p727-p1-20261102.json`, 확인 기록 `m4-m68k-p727-p1checks-20261102.json` `ok`): F·L 경고 0, 26/26(`m4-m68k-funcbytes-p727-{F,L}-20261102.json`), 절 8724/1080/20/14/345, `__data` 재배치 칸 밖 1064 B 같음, `__cstring` 소유 331 B 같음, bss 차례 `done.64`·`rx_active`·`rx_cached`·`rx_init`·`epi`, 원본에 없는 미정의·COMMON 0(COMMON 34, 미정의 68), F = L, F = 진단 C1(`canon`·`obj_sig`; STABS 는 소스 경로 이름과 줄 번호만 다름).
- 5 `-E` run `m4p727-e2`(`m4-m68k-p727-e1-20261102.json` `ok`): F = L 14536 토큰, stderr 0, i386 0.
- 6 최종 run `m4p727-a2`(`m4-m68k-p727-final-20261102.json`, SHA-256 `a5f48ef1…`): `gate.ok`, funcbytes 26/26, L1 이유 `__DATA,__bss: unverified` 하나, 판정 provisional. 영 채움 `m4-m68k-zerofill-p727-20261102.json`(SHA-256 `ea9e0db8…`): `reference-inferred`, 후보 [0x40b5598, 0x40b55ac)(20 B), 다른 영 채움 기록과 겹침 0(python). 확인 기록 `m4-m68k-p727-checks-20261102.json`(`ok`, SHA-256 `12091a73…`): 의존 88(저장소 파일 74 의 SHA 사슬), 선택지 = M5 줄, 07 = 스테이지, `if_enreg.h` = NeXTMach 파일. 객체 SHA-256 `d7f60e9a…`.
- 7 상태(`m4-m68k-status-p727-20261102.json`, 표 66 → 67 줄; 두 번 돌려 출력 경로 칸만 다름; 이전 행은 그대로): 객체 **65**(OBJECT_MATCH 50, CODE+BSS_INFERRED 15), 행 **88/188**, **128652 B(59.60퍼센트)**, `object_bytes` **181374**. 미리 계산한 값과 같습니다(행 259·260 은 `exact` 0 이라 부분 행으로 남음).
- 8 기록: 근거 `m68k-if_en.md`·`m68k-if_en.diff`(2175 줄), PROVENANCE 1233 → 1235 행(일곱 칸, `if_en.c`·`if_enreg.h`), MODIFICATIONS 761 → 762, DECISIONS D163(166 → 167 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D163). 남은 일: `ev_kbd.c`(22/23; `DoModCalc` 의 임시값 레지스터 3 B).

## 728. M4-195 세부 계획 — m68k `ev_kbd.c`(행 215) `DoModCalc` 의 d0/d1 3 B: 컴파일러 레지스터 선택 진단 (07 변경 없음; 코딩 전, 2026-11-02)

고른 까닭: 남은 큰 단위 가운데 `ev_kbd.c`(구간 [0x4068fa2, 0x4069eb8), 23 함수)는 진단 `ev_kbd_KL.c` 가 22/23 입니다(§723.2). 남은 한 함수 `DoModCalc`(원본 0x40698a8, 110 B)는 길이가 같고 다른 바이트는 셋(오프셋 0x1c·0x1e·0x21; 함수 기록 `m4-m68k-funcbytes-p723-kbd-KL-20261102.json`)뿐입니다. 원본 풀이(`scratch/p723/evk.dis`)는 `moveq #15,d1; andl d2,d1; movel d1,sp@-`(`CalcModBit` 인수 `thisBits & 0xf`)이고 진단 객체는 d0 입니다. 원본 32 줄 가운데 `%d0` 는 0 번, `%d1` 은 3 번 나옵니다(python). 21 개의 소스 표기 변형(§723.2)이 모두 d0 로 남았습니다.

사실(열어 확인함, 공개 GCC 2.7.2.3 소스 `scratch/p725/gccsrc`, 읽기 전용):
- `reload1.c:702` 의 `last_spill_reg = -1` 은 `reload()` 시작(함수마다)에서 설정됩니다. `allocate_reload_reg`(`:4745–4860`)는 `i = last_spill_reg` 에서 시작해 `spill_regs[]` 를 돌려 가며 처음 맞는 레지스터를 고릅니다. `potential_reload_regs[]` 의 차례는 `order_regs_for_reload`(`:3606`)가 정하되(고정·명시 사용 레지스터가 뒤로, 나머지는 의사 레지스터가 가진 `reg_n_refs` 합이 적은 순), 실제 `spill_regs[]` 는 뒤에 번호순으로 다시 정렬됩니다(`:3771–3777`; §728.1 에서 고침).
- m68k.h 에 `REG_ALLOC_ORDER` 가 없습니다(grep 0 건): 지역 할당은 레지스터 번호 차례(d0 먼저)로 봅니다.
- §725.17 에서 `en_tx_dmaintr` 의 d6/d7 차이를 같은 회전으로 설명했습니다(24 곳 가운데 5 번째만 달랐음). 이번 d0/d1 도 같은 종류인지(임시값이 reload 레지스터인지 지역 할당 결과인지) 아직 모릅니다.

가설(검증 전; 결과로 가려냄):
- H1 임시값 `thisBits & 0xf` 의 의사 레지스터가 지역 할당(`local-alloc`)에서 d0 를 받았고, 원본은 그 시점에 d0 가 다른 수명과 겹쳐 d1 이었다(원본에 소스에는 안 보이는 겹치는 임시값이 있었다).
- H2 임시값이 reload 레지스터이고, 원본은 같은 함수에서 앞서 d0 를 쓴 reload 가 하나 더 있어 회전으로 d1 이 되었다(`last_spill_reg`).
- H3 그 밖(`combine`·`cse` 의 결과로 `moveq #15` 의 의사 레지스터가 둘로 갈라지는 차이 등).

방법(07 변경 없음; scratch 와 `08_build/artifacts/m4p728`):
1. 진단 `ev_kbd_KL.c` 를 `-dr -dj -ds -dc -dl -dg -dJ -df` 로 컴파일하는 kr_run 한 번(`RUNIN`, §725.14 꼴: 같은 스테이지 `m4p723p8-stage` 에서; run `m4p728-d1`). 덤프는 8 개 패스 파일이고 실행 중 디스크를 쓰는 양은 약 15 MB 입니다.
2. python 으로 `DoModCalc` 구간만 뽑아(스크립트 `scratch/p728/dumpfn.py`) 의사 레지스터 번호, 각 패스의 `reg_renumber`/수명, `.lreg`(지역 할당)와 `.greg`(전역 할당·reload 뒤) 에서 임시값의 배정 경로를 읽습니다. 임시값이 지역 할당 몫인지 reload 몫인지부터 가립니다.
3. 가려진 쪽의 GCC 소스(`local-alloc.c` 의 수량 우선순위·`find_free_reg`·`qty_phys_sugg`/`qty_phys_copy_sugg`, 또는 `reload1.c` 의 회전)를 읽어, 원본의 d1 을 낳을 수 있는 소스 차이를 가설로 세웁니다. 원본에 없는 기능은 더하지 않습니다(바이트가 요구하는 꼴만).
4. 가설마다 소스 변형을 새 run(`m4p728-p1`…)으로 시험합니다. 판정(미리 정함): `DoModCalc` 110 B 가 바이트와 재배치 대상까지 같고 나머지 22 함수가 그대로 같으며 절 크기가 §723 의 기록(`__text` 3862, `__const` 1850, `__data` 13)과 같으면 해결입니다. 원본 바이트를 근거로 한 꼴만 인정합니다.
5. 풀리지 않으면 멈추고 보고합니다. D163 선례(`asm`)는 사용자 결정이 필요하므로 제가 정하지 않습니다.

기준(미리 정함): 기준을 결과를 본 뒤 낮추지 않습니다. 변형 수는 제한하지 않되 매 묶음마다 이유(가설)를 적습니다.

### 728.1 §728 codex 교차검토(`gpt-6.1-sol`) 판정과 계획 수정 (코딩 전, 2026-11-02)

먼저 제 잘못:
1. "`order_regs_for_reload` 가 spill 차례를 정한다, 배정된 횟수가 적은 순" 이라고 썼습니다. 실제는 `reg_n_refs` 합이고(`reload1.c:3628–3637`), `spill_regs[]` 는 번호순으로 다시 정렬됩니다(`:3771–3777`, `compare_spill_regs` `:3714–3720`). 계획 문장을 위처럼 고쳤습니다.
2. 방법 1단계가 §725.14 를 가리켰으나 근거는 결과가 담긴 §725.15 와 실제 명령 파일 `probe.d1.cmd` 입니다.
3. 2단계가 "지역 할당 몫인지 reload 몫인지" 만 가르려 했습니다. 지역 할당·전역 할당·reload 셋을 가려야 합니다(`global_alloc` 이 끝에서 `reload` 를 부릅니다, `global.c:573–580`). 또 H1–H3 에 지역 할당의 선호(`qty_phys_sugg`·`qty_phys_copy_sugg`)와 전역 할당의 선호(`regs_someone_prefers`·`hard_reg_preferences`)를 빠뜨렸습니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `reload1.c:702` 는 `reload()`(446 행 시작) 안, 함수마다 `-1` | 446–448·696–702 행을 열음 | ✅ |
| `spill_regs[]` 는 번호순 재정렬(3717–3720, 3771–3777) | 3711–3722, 3768–3779 행을 열음(`compare_spill_regs`, `qsort`) | ✅ (정렬 위치 3714–3720 으로 고쳐 받음) |
| `order_regs_for_reload` 는 `reg_n_refs` 합(3628–3637) | 3622–3637 행을 열음 | ✅ (위 잘못 1) |
| `REG_ALLOC_ORDER` 가 `m68k.h` 에 없음 | 제가 직접 grep(출력 없음) | ✅ |
| 선호 레지스터가 d0 를 비워 두고도 d1 을 고르게 할 수 있음(`local-alloc.c:1466–1476`, `1791–1835`, `2143–2150`) | 세 곳을 열음: 선호가 있으면 `find_free_reg(…, just_try_suggested=1)` 를 먼저 부르고, 하드 레지스터 복사가 선호를 기록함 | ✅ 새 가설 H4 |
| 수량 결합과 우선순위(`1851–1879`, `qty_compare` `1579–1600`) | 두 곳을 열음 | ✅ |
| 수명 연장(`2019–2057`) | 열음(`PARALLEL` 출력·`REG_INC` 로 죽는 시점 연장) | ✅ |
| 지역 할당 자격(`local-alloc.c:460–477`)과 `global.c:388`, 전역 선호(`945–961`, `990–1067`) | 모두 열음: 한 블록·죽음 1 회가 아니면 전역 할당 몫, 전역은 선호를 피하거나 따름 | ✅ 새 가설 H5 |
| `regs_live_at_death` 식별자는 세 파일에 없음 | 제가 `local-alloc.c` 에서 `regs_live_at` 만 찾았음(`regs_live_at_death` 는 제 계획에 안 썼음; 질문 문구였음) | ⏭️ 계획에 안 들어감 |
| d0·d1 은 같은 클래스(`m68k.h:518–527`) | 열음: `DATA_REGS` 0x000000ff | ✅ |
| `dump_local_alloc` 은 배정표만 출력(`local-alloc.c:2373–2380`) | 열음 | ✅ 추출기는 `.lreg` 머리의 배정표와 RTL 의 의사 레지스터를 함께 읽음 |
| `DoModCalc` 3 B 차이(0x1c·0x1e·0x21), 길이 110, `%d0` 0 번·`%d1` 3 번(`evk.dis:1377–1379`) | 함수 기록 JSON(앞서 제가 열음)과 python 계수, `evk.dis` 1375–1380 행을 열음 | ✅ |
| 새 덤프는 입력 재해시 목록에 안 들어감(`kr_run.py:248–255`) | 246–256 행을 열음(`RUNIN`, 입력 재해시는 253–254 행) | ✅ (§725.15 의 관측과 같음) |

계획 수정(방법에 더함):
- 0단계: 덤프 옵션을 붙인 컴파일이 기존 KL 객체(`Q723__ev_kbd_KL.o`)를 재현하는지(`canon`·`obj_sig`) 먼저 봅니다. 재현하지 않으면 덤프 해석을 쓰지 않습니다.
- 2단계: 의사 레지스터마다 지역 할당(`.lreg` 의 `Register N in R`)·전역 할당(`.greg`)·reload 중 어느 쪽에서 배정되었는지 python 으로 가립니다.
- 가설 추가: H4 하드 레지스터 복사에서 생긴 선호(`qty_phys_sugg`·`copy_sugg`) 때문에 d1; H5 한 블록·죽음 1 회 조건을 못 채워 전역 할당 몫이 되고 전역 선호가 d1 로 이끈다.
- 공개 GCC 2.7.2.3 소스는 NeXT cc 의 확정 구현이 아니라 후보입니다(기존 한계 유지). 변형이 맞는지는 항상 원본 바이트와의 비교로만 판정합니다.

2 차 자기검사: ✅ 행은 모두 이번 세션에 직접 연 줄이거나 제가 돌린 출력입니다. codex 가 준 줄 번호 가운데 `regclass.c:911–975` 는 열지 않았으므로 계획에 옮기지 않았고, 계획에 쓴 줄 번호는 위에서 연 것뿐입니다.

### 728.2 덤프 결과와 가설 H6, 변형 묶음 계획 (코딩 전; 2026-11-02)

덤프 run `m4p728-d1`(덤프 옵션을 붙인 KL 컴파일): 객체가 기존 KL 객체(`m4p723-p5`)와 `canon`·`obj_sig` 같음(0단계 통과; 파일 해시는 STABS 경로 때문에 다름).

관찰(`.lreg`·`.greg` 에서 `DoModCalc`; 스크립트 `scratch/p728/dumpfn.py`):
- `.lreg` 에는 임시값 의사 레지스터가 없습니다. 삽입 22 는 `(set (mem:SI (pre_dec sp)) (and:SI (reg 30) (const_int 15)))` 이고, `moveq #15,dN; andl d2,dN` 의 dN 은 **reload 가 만든 레지스터**입니다. `.greg` 머리에 `Need 1 reg of class DATA_REGS (for insn 22)` 와 `Spilling reg 0.` 가 있습니다. 의사 레지스터 셋은 28→a0, 29→d3, 30→d2 입니다.
- 이 진단의 `DoModCalc` 안 `CalcModBit`·`LLEventPost` 호출은 `(call_insn (call (mem:QI (symbol_ref …)) …))` 로 d0 를 설정하지 않습니다(그 지점에서 `void` 로 알려져 있어서; `CalcModBit` 는 `SetKeyMapping`(615 행)에서 정의(622 행)보다 먼저 불려 그 호출만 암묵 `int` 라 d0 를 설정합니다, §728.3). 같은 덤프의 `int` 함수 호출(`process_device_mods`, `DoKbdEvent`)은 `(call_insn (set (reg:SI 0 d0) (call …)))` 입니다.

소스로 이어 본 고리(공개 GCC 2.7.2.3, 모두 열음):
- `calls.c:1604–1613` 반환 모드가 `VOIDmode` 가 아니면 `valreg` 를 잡고, `calls.c:379–398` 이 `valreg` 가 있으면 `gen_call_value` 를 냅니다. 따라서 `int`(또는 암묵 `int`) 함수의 호출은 값을 안 써도 `d0` 를 명시합니다.
- `flow.c:2478–2486` 가 명시된 하드 레지스터를 `regs_ever_live` 에 표시하고, `reload1.c:486` 이 reload 시작에서 `regs_explicitly_used = regs_ever_live`(의사 레지스터 배정을 합치기 전)로 복사합니다.
- `reload1.c:3651–3654` 에서 명시 사용 레지스터는 `uses += large + 1` 로 뒤로 밀리고, `3680–3711` 에서 사용 횟수가 0 인 레지스터가 먼저 `potential_reload_regs[]` 에 들어갑니다. 그래서 d0 가 명시 사용이면 `Spilling reg 0` 대신 d1 이 먼저 spill 됩니다.
- 따라서 H6: 원본 `DoModCalc` 에서 `CalcModBit` 또는 `LLEventPost` 의 호출이 값을 반환하는 호출(`int`)이어서 d0 가 명시 사용이었다. 코드에는 값이 쓰이지 않으므로 바이트에는 d0 가 나타나지 않고, 삽입 22 의 reload 임시값만 d1 이 됩니다. (0x1c, 0x1e, 0x21 세 바이트가 그 레지스터 번호 자리입니다.)

원본 글과의 관계(전수 확인): NeXTMach `nextdev/ev_kbd.c` 에는 `extern` 이 한 줄도 없고(grep 0 건; 함수 선언은 `void AllKeysUp();` 한 줄뿐), `LLEventPost` 는 NeXTMach `*.h` 어디에도 선언이 없으며(주석 한 줄뿐), 스테이지의 어느 `.h` 에도 없습니다(grep 0 건). 즉 NeXTMach 글은 `LLEventPost` 를 선언하지 않은 채 부르므로 암묵 `int` 호출입니다. 진단 KL 의 `extern void LLEventPost();`(70 행)은 제가 이름 블록에 넣은 선언입니다. NeXTMach `CalcModBit` 정의는 `void CalcModBit(…)`(510 행)입니다.

묶음 계획(진단 변형; 07 변경 없음; 기반 `ev_kbd_KL.c`):
- KZ1: 70 행 `extern void LLEventPost();` 를 지운다(NeXTMach 와 같게 암묵 `int`).
- KZ2: `void CalcModBit` 정의를 `int CalcModBit`(몸통 그대로, 반환 없음)로 바꾼다. NeXTMach 와 다른 꼴이므로 KZ1 이 안 되면의 대비입니다.
- KZ3: KZ1 + KZ2.
판정(미리 정함): `DoModCalc` 가 바이트와 재배치 대상까지 같고, 나머지 22 함수와 절 크기(`__text` 3862, `__const` 1850, `__data` 13)가 그대로이면 해결입니다. 해결된 변형 가운데 NeXTMach 글에 더 가까운 것(KZ1)을 택하되, 다른 함수의 `extern`(`adb_keyboard_LED` 등)은 바이트가 요구하지 않는 한 건드리지 않습니다. 해결이 없으면 멈추고 보고합니다.

### 728.3 §728.2 codex 교차검토(`gpt-6.1-sol`) 판정 (코딩 전, 2026-11-03)

먼저 제 잘못: §728.2 가 "이 진단의 `CalcModBit` 호출은 d0 를 설정하지 않는다"고 일반화했으나, `SetKeyMapping`(615 행)의 호출은 정의(622 행)보다 앞이라 암묵 `int` 로 d0 를 설정합니다(`.greg` 5011–5015). 위 문장을 고쳤습니다. 또 `calls.c:379–398` 은 `pop` 갈래이고 일반 갈래는 `395–406` 입니다.

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `valreg` 생성 `calls.c:1604`, 일반 `gen_call_value` 는 397–405 | 395–406 행을 열음 | ✅ (인용을 395–406 으로 고침) |
| 호출 결과 `SET` 의 `regs_ever_live` 는 `flow.c:2046`, 2478–2486 은 읽기 쪽 | 2040–2048 행을 열음(`mark_set_1` 의 `regs_ever_live[i] = 1`), 2478–2486 은 앞서 열음(사용 쪽) | ✅ (§728.2 는 사용 쪽만 인용했음; 설정 쪽 2046 을 더함) |
| `reload1.c:486` 복사, 3651–3661 가중치, 3681–3711 후보 배열 | 앞서 열음 | ✅ |
| 단일 spill 은 `1840–1889` 에서 배열 앞부터 클래스에 맞는 후보, `new_spill_reg` 2216–2232 | 1838–1895, 2206–2232 행을 열음 | ✅ |
| 예외: 그룹 요구(1611–1804), `possible_group_p`(1854–1873), 이전 spill 되돌림(1549–1583), `SMALL_REGISTER_CLASSES` 없으면 명시 사용 레지스터가 `bad_spill_regs`→`forbidden_regs`(3660, 708–710) | 3656–3662, 706–711, 1838–1895 를 열음(나머지 1611–1804·1549–1583 은 열지 않음) | ✅ 앞의 셋(1854–1873 포함 `1838–1895`, 3660, 708–710) / ⏭️ 1549–1583·1611–1804 는 계획에 옮기지 않음 |
| 최종 명령별 reload 배정은 `spill_regs` 번호순 정렬 뒤 `4733–4779` 의 순환 | 앞서 열음(`3771–3777`, `4745–4800`) | ✅ (이번 함수는 spill 이 하나라 영향 없음) |
| `.greg` 5584 `Need 1 reg of class DATA_REGS`, 5588 `Spilling reg 0` | 5582–5590 행을 열음 | ✅ |
| `.greg` `process_device_mods` 111–115, `DoKbdEvent` 221–225 는 d0 `SET` + `REG_UNUSED`; DoModCalc 의 `CalcModBit` 5677–5680·`LLEventPost` 5768–5771 은 `SET` 없음 | 5675–5681, 5766–5772 를 열음; 111·221 행은 앞서 grep 으로 열음 | ✅ |
| 5011–5015 `SetKeyMapping` 의 `CalcModBit` 는 d0 `SET` | 5009–5016 행을 열음 | ✅ (위 잘못) |
| NeXTMach `ev_kbd.c` `extern` 0 건; `LLEventPost` 는 `*.h` 에 주석 1 건뿐, 스테이지 `.h` 0 건 | 제가 `grep -rIa` 로 같은 결과(스테이지 `.h` 643 개 중 0, NeXTMach `.h` 중 `ev_vars.h` 1) | ✅ |
| `extern` 부재와 함수 선언 부재는 다른 주장: NeXTMach `ev_kbd.c:36` 에 `void AllKeysUp();` | 35–37 행을 열음 | ✅ (계획의 "선언이 한 줄도 없고" 를 "`extern` 이 없고 `LLEventPost` 선언은 없다"로 고침) |
| KZ1 은 `DoCharGen` 등 다른 `LLEventPost` 호출에도 d0 `SET` 을 추가해 다른 함수를 깨뜨릴 수 있음(`.flow:9098`) | 9096–9100 행을 열음(호출에 `SET` 없음) | ✅ 판정에 "나머지 함수 전부 같음" 을 함수별 바이트·재배치로 명시 |
| KZ2 는 `CalcModBit` 자신의 코드를 바꿀 수 있음 | 가능성 | ⏭️ 결과로 확인 |
| 바이트 일치가 원본의 반환형이 `int` 였다는 증명은 아님 | 동의 | ✅ H6 를 지지하는 재현으로 판정 |

계획 보강: 판정에서 "나머지 22 함수와 절"은 함수별 바이트와 재배치 대상 전체, `__const`·`__data` 는 크기뿐 아니라 내용(원본 바이트와의 비교)입니다. 기전 확인으로 결과 변형의 `.flow` d0 `SET`과 `.greg` 의 `Spilling reg` 도 덤프로 봅니다(해결된 변형 하나에 대해 `m4p728-d2`).

2 차 자기검사: ✅ 행은 모두 이번 세션에 연 줄이거나 제가 돌린 출력입니다. 코드로 열지 않은 `1549–1583`, `1611–1804` 는 판정에서 ⏭️ 로 두었고 계획에 옮기지 않았습니다.

### 728.4 묶음 결과: `DoModCalc` 풀림 (run `m4p728-p1`·`p2`·`d2`, 2026-11-03; 07 변경 없음)

먼저 제 잘못: 첫 funcbytes 호출에 이름 없는 정적(`ModKeysDown`, `NextNum`)과 자료의 주소 대응을 빠뜨려 14/23 으로 나왔습니다(KL 기록의 `mapping` 을 열어 같은 대응을 넣어 다시 돌림). 또 §723.2 의 "경고 0" 이라는 인상과 달리 KL 도 컴파일 경고 15 줄이 있었음을 이번에 확인했습니다(`m4-m68k-probe-p723-p5-20261102.json` 의 KL 컴파일 `warnings` 15).

결과:
- 원인(H6 확인): `LLEventPost`(과 `CalcModBit`)를 값을 반환하는 호출로 만들면 d0 가 명시 사용이 되어 reload 임시값이 d1 이 됩니다. 덤프 `m4p728-d1`(KL): `Spilling reg 0.`, `DoModCalc` 의 두 호출에 d0 `SET` 없음. 덤프 `m4p728-d2`(KZ4): `Spilling reg 1.`, 두 호출 모두 `(set (reg:SI 0 d0) (call …))`, `Hard regs used: 0 1 2 3 8 14 15`.
- 변형(모두 KL 에서 파생; 소스 `08_build/artifacts/m4p728/src/ev_kbd_KZ*.c`):
  - KZ1: `extern void LLEventPost();` 를 지움(NeXTMach 글처럼 선언 없음) → **23/23**, 컴파일 경고 15(KL 과 같은 15: `process_device_mods`·`CalcModBit`·`DoKbdEvent` 가 암묵 `int` 으로 불린 뒤 `void` 로 정의되어 "type mismatch with previous implicit declaration" 셋씩 다섯 줄).
  - KZ2: `int CalcModBit` 만 → 23/23, 경고 10. KZ3: KZ1 + KZ2 → 23/23, 경고 10.
  - KZ4: KZ1 + 세 정의(`process_device_mods`·`CalcModBit`·`DoKbdEvent`)의 `void` 를 뺌(암묵 `int`) → **23/23, 경고 0**(run `m4p728-p2`; funcbytes `m4-m68k-funcbytes-p728-KZ4-20261103.json`).
- 모든 변형: `__text` 3862, `__const` 1850, `__data` 13 이고 `__const`·`__data` 가 원본 바이트와 같으며 원본에 없는 미정의·COMMON 이름 0. 세 변형의 `canon` 이 같고, `obj_sig` 는 KZ1 과 KZ3 이 같으며 KZ2 는 STABS 개수만 다릅니다(KZ1 1645, KZ2 1635; python: 다른 항목은 `stabs` 하나뿐, 기호표 차이 0).
- 풀이가 바이트가 요구하는 것은 "`DoModCalc` 안의 `LLEventPost` 호출이 값을 반환하는 호출(d0 명시)" 입니다. 원본의 반환형이 `int` 였다는 역사적 증명은 아닙니다(§728.3).

판정(미리 정한 대로): `DoModCalc` 가 바이트와 재배치 대상까지 같고 나머지 22 함수와 절이 그대로이므로 해결입니다. 바이트로 가려지지 않는 것(경고를 두는 KZ1 꼴 대 경고 없는 KZ4 꼴)은 07 쓰기 전에 사용자께 여쭙습니다.

## 729. M4-196 D164 구현 계획 — 07 `src/machdep/m68k/ev_kbd.c`(행 215 부분; 코딩 전, 2026-11-03)

사용자 결정(D164, 2026-11-03; AskUserQuestion 답):
- ① 컴파일 경고: "NeXTMach 글 그대로 + `known_warnings`". 세 정의(`process_device_mods`·`CalcModBit`·`DoKbdEvent`)는 NeXTMach 처럼 `void` 로 두고, 정의보다 먼저 암묵 `int` 로 불리므로 나는 경고 15 줄(§728.4)을 최종 명세의 `known_warnings["ev_kbd"]` 로 정확히 기록합니다(선례 `snd_unix`, `m4p646`).
- ② 이름 없는 정적 둘(원본 0x4069364, 0x40694ae)은 `ModKeysDown`·`NextNum`.
- ③ 앞선 결정에서 이어받음(새 질문 없음): `KeyMapping` 732 B 와 ev 변수 이름은 파일 안 블록(D162 ②, D161 ①), 지운 줄은 표지 주석(D154), 그리고 §728 의 풀이: `LLEventPost` 는 NeXTMach 처럼 선언 없이 부릅니다(암묵 `int`; d0 가 명시 사용이 되어 `DoModCalc` 의 reload 임시값이 d1 이 됨).

방법(§724·§727 의 순서; 07 파일 F 는 진단 변형 KZ1 에서 만듭니다):
1. F = `08_build/artifacts/m4p728/src/ev_kbd_KZ1.c`(KL 에서 `extern void LLEventPost();` 한 줄만 뺀 것; 23/23) + 머리 주석 + 표지, L = F 에서 주석을 비운 것. scratch `p728/gen_p729.py` 가 `p727/gen_p727.py` 의 구역·표지 논리를 이 파일 이름·표지 문구(`plan 723 diagnostic` → `plan 729 (D024, D164)` 등)로 바꾸어 만듭니다(`--write [--force]` 로 07 파일도 씀).
   - 머리 주석: NeXTMach `ev_kbd.c` 머리(고지·HISTORY, 첫 `#import` 앞까지)를 그대로 두고 그 뒤에 1997 바뀜 목록(함수별 같음/다름은 python 비교로 정함)과 "작성 선택"(②·③, 경고 15 줄이 `known_warnings` 라는 점) 문단을 넣습니다(D013).
   - 구역: 바뀐 함수·새 함수·이름 블록·자료는 `plan 729 … BEGIN/END`, 지운 줄은 표지 주석(D154). 같은 함수라도 합쳐진 구역에 섞일 수 있음을 머리 주석에 적습니다.
   - 단언(python): F 와 L 의 토큰·토큰 줄이 같고, L 과 KZ1 의 토큰이 같으며(주석 밖 글이 진단과 같음), NeXTMach 와 견준 표지 없는 바뀐 줄이 0 이어야 합니다. 머리 주석 보존도 단언합니다.
2. `stage_m68k.py`: `M4FILES[729] = list(M4FILES[727]) + ['ev_kbd.c']`, `M4HEADERS[729] = list(M4HEADERS[727])`(새 머리 없음: 진단이 쓴 SDK `bsd/dev/m68k/event.h`·`bsd/dev/ev_keymap.h` 와 `dev/m68k/monreg.h`·`video.h` 는 이미 스테이지에 있음 — 구현에서 단언), `EXCEPTS[729] = dict(EXCEPTS[727])`, 머리말 `--plan` 목록에 729.
3. 회귀: 계획 727 스테이지를 다시 만들어 보관본 `m0p727-a2-stage` 와 같은지, 새 스테이지 `m0p729-a1-stage` 와의 차이가 `src/machdep/m68k/ev_kbd.c` 하나뿐인지 봅니다. M5 205 줄을 새 스테이지에서 컴파일(`m3p729-cc1`)해 받아들인 `m3p727-cc2` 출력과 견줍니다(`run.json` 만 달라야 함, `compare` 의 `differ_unexpected`·`lost` 비어야 하고 `stage_vs_test_stage` 는 `ev_kbd.c` 하나만 늘어야 함). x86 입력과 `x86gate` 가 앞과 같아야 합니다.
4. 확인 run `m4p729-p1`(F, L): funcbytes 23/23(이름 없는 정적과 자료의 주소 대응 포함: `0x4069364=_ModKeysDown 0x40694ae=_NextNum 0x40b1252=_downCount 0x40b1254=_downKey 0x40b1256=_adbKeyboard 0x40b1258=_modKeys 0x40ad172=_defaultMapping 0x40ad4bc=_adbMapping`), 절 `__text` 3862·`__const` 1850·`__data` 13 이고 `__const`·`__data` 가 원본 바이트와 같으며, 원본에 없는 외부 정의·COMMON·미정의 0, F = L(`canon`·`obj_sig`), F 와 KZ1 객체의 `canon` 같음, 경고는 F 와 L 이 같은 15 줄(경로 이름만 다름).
5. `-E` run `m4p729-e1`: F 와 L 의 전처리 토큰이 같고 stderr 에 경고 외 줄이 없으며 i386 경로 0.
6. 최종 run `m4p729-a1`(명세 `08_build/artifacts/m4p729/spec.json`; 객체 `ev_kbd`, `m4_id` `{"range":["0x4068fa2","0x4069eb8"],"rows":[],"partial":["m68k-215"],"basis":…}`(진단 명세의 `basis`), `refs` = p1 의 L 객체 SHA-256, `known_warnings["ev_kbd"]` = F 컴파일의 stderr 정확히 15 줄): `gate.ok`, 정적 bss 가 없으므로 OBJECT_MATCH, `ACCEPTED` 는 두 칸 항목. 확인 기록: 의존 SHA 사슬, 선택지 = M5 줄, 07 = 스테이지, 종료 0, i386 0, `-E` 같음, 경고 = `known_warnings`.
7. 상태 도구에 `ACCEPTED` 한 항목을 더하고 두 번 돌려 같음과 이전 행 보존을 봅니다.
8. 기록: 근거 `06_reconstruction/evidence/m68k-ev_kbd.md`·`m68k-ev_kbd.diff`, 상태표 한 행, PROVENANCE 한 행(`ev_kbd.c`; 일곱 칸; NeXTMach `nextdev/ev_kbd.c`, `nextdev/ev_vars.h`·`next/scr.h`·`next/cpu.h` 등 이름 줄은 진단 표지에서 python 으로 뽑은 줄 범위를 원본에서 열어 확인), MODIFICATIONS 한 행, DECISIONS D164, HANDOFF·메모리·계획 §729.x.

상태 기대(python): 객체 66(OBJECT_MATCH 51, CODE+BSS_INFERRED 15), 행 88/188 그대로(행 215 는 `exact` 0 이라 부분 행으로 남음), 행 최소 바이트 128652 B(59.60%) 그대로, `object_bytes` 181374 + 3862 = 185236(0x4069eb8 - 0x4068fa2 = 3862). 부분 행 목록 그대로(215 이미 포함).

M7 의무(적어 둠): 정적 `ModKeysDown`·`NextNum`·`adbKeyboard`·`adbMapping` 등의 자리, `ev_vars.h` 변수들이 이 파일에서는 `extern` 이라는 점(COMMON 정의는 다른 객체), 경고 15 줄은 컴파일러의 "암묵 선언 뒤 `void` 정의" 경고로 NeXTMach 글과 같은 원인이라는 점.

판정(미리 정함): 3–7 단계와 통합 확인 기록이 모두 `ok` 이고 상태 도구 출력이 위 기대와 같으면 받아들입니다. 어긋나면 어느 단계가 어긋났는지 적고 멈춥니다(기준을 늦추지 않음).

위험(미리 적음): (가) F 는 `LLEventPost` 를 선언하지 않으므로 다른 함수의 reload 에도 영향이 있을 수 있음 → p1 의 23/23 이 막음(KZ1 이 이미 23/23). (나) 경고 15 줄의 정확한 글(경로·줄 번호)이 F 에 묶임 → 최종 run 직전에 F 가 고정이어야 하고, 주석 수정 뒤에는 명세를 다시 만듦. (다) 07 쓰기 전 재생성 규칙: 표지·주석 문구를 고치면 파일 SHA 가 바뀌어 M5·p1·e1·a1 을 새 run 번호로 다시 돌려야 하므로, 07 을 쓰기 전에 PROVENANCE 에 넣을 모든 줄 범위(`ev_vars.h`·`scr.h`·`cpu.h` 이름 줄)를 원본에서 열어 확인합니다(§727.2 잘못 1 재발 방지).

### 729.1 §729 codex 교차검토(`gpt-6.1-sol`) 판정과 계획 수정 (코딩 전, 2026-11-03)

먼저 제 잘못 (중요):
1. 사용자께 "NeXTMach 글은 `process_device_mods`·`CalcModBit`·`DoKbdEvent` 를 정의보다 먼저 부르고 `void` 로 정의해 경고 15 줄을 낸다"고 말씀드리고 "NeXTMach 글 그대로 + `known_warnings`" 를 고르시게 했습니다. 틀린 전제였습니다. NeXTMach `nextdev/ev_vars.h:49·51·55` 에 `extern void DoKbdEvent();`·`extern void process_device_mods();`·`extern void CalcModBit();` 가 있고(`ev_kbd.c` 는 `ev_vars.h` 를 import), 경고는 제가 진단의 `ev_vars.h` 이름 블록에서 이 선행 선언을 뺐기 때문에 생긴 것입니다. 열어 확인했고(`ev_vars.h` 44–58 행), 선행 선언을 넣은 두 변형을 시험했습니다(§728.5). 사용자 결정 ①(D164 ①)은 이 전제가 틀렸으므로 다시 여쭙니다.
2. §729 의 "M7 의무"에 쓴 "NeXTMach 글과 같은 원인" 문장도 틀렸습니다(위).
3. §729 2단계가 네 헤더를 모두 "SDK" 라고 불렀으나 스테이지 manifest 의 원천은 다릅니다: `monreg.h` ← `07_kernel/nextmach/nextdev/monreg.h`(NeXTMach 사본), `video.h`·`event.h`·`ev_keymap.h` ← `07_kernel/nextdev/...`(실기 SDK 사본).

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `known_warnings` 는 객체별로 `err_lines` 를 경로·줄 번호·순서까지 정확히 비교하고 변형별로 다른 목록을 줄 수 없음; 최종 run 의 형식은 `src/src/machdep/m68k/ev_kbd.c:<줄>:` | `m4_m68k_probe.py:380–395` 를 열음(`c['err_lines'] == kw[c['target']]`), `vrel`(100–106)·`-c` 줄(218–222)을 열음; 선례 `snd_unix` 도 F 경로 | ✅ (이번에는 선행 선언이 있는 변형이 경고 0 이라 해당 없을 수 있음) |
| 상태 기대(66/51/15, 88/188, 128652, 185236)가 맞고 행 215 는 `exact` 0 | 제가 같은 값을 python 으로 앞서 계산(inventory 행 215 `exact` 0, 3862 B) | ✅ |
| 네 헤더가 스테이지에 있음(4 개) | `find` 로 확인, manifest 로 원천 확인 | ✅ (위 잘못 3) |
| 출처: `ev_vars.h` 93–95, 175–193, 208–228, 235–238, 258–276 행과 `scr.h:106–107`; `specialKeys`·`evg`·`screens`·`dimmedBrightness`·ADB 선언은 원문 그대로가 아님; `next/cpu.h` 는 KZ1 에서 직접 옮긴 이름 블록 없음 | `KZ1` 에 `cpu.h` 0 건(grep). 줄 범위는 PROVENANCE 를 쓸 때 원본을 열어 python 으로 대조하기로 함 | ⚠️ 줄 범위는 아직 미확인(계획에 옮기지 않음) / `cpu.h` ✅ |
| 경고 원인 보정(`ev_vars.h:49·51·55` 에 선행 `extern void`) | `ev_vars.h` 44–58 행을 열음 | ✅ (위 잘못 1) |
| `defaultMapping` 변경(KZ1:286)처럼 개별 표지 없는 차이가 있어 문구 치환만으로는 부족, BEGIN/END 와 "표지 없는 변경 0" 검사 유지 | 검사 유지(§727 과 같은 단언) | ✅ |

2 차 자기검사: ✅ 행의 근거는 모두 이번 세션에 연 줄이거나 제가 돌린 출력입니다. 출처 줄 범위 행은 ⚠️ 로 두었고 어떤 문서에도 옮기지 않았습니다.

### 728.5 선행 선언 변형 결과 (run `m4p728-p3`, 2026-11-03; 07 변경 없음)

- KZ5 = KZ1 + 이름 블록에 `extern void DoKbdEvent(); extern void process_device_mods(); extern void CalcModBit();` → **23/23, 경고 0**.
- KZ6 = KZ1 + NeXTMach `ev_vars.h` 의 `/* ev_kbd.c */` 선언 아홉 줄(`DoKbdRepeat`, `DoKbdEvent`, `ResetKbd`, `process_device_mods`, `process_kbd_event`, `DoAutoDim`, `UndoAutoDim`, `CalcModBit`, `unsigned char *SetKeyMapping()`) 전부 → **23/23, 경고 0**.
- 두 변형 모두 `LLEventPost` 는 선언이 없어 `DoModCalc` 의 d0 명시 사용은 그대로입니다. 즉 이 파일에서 바이트가 요구하는 것은 `LLEventPost` 의 암묵 `int` 뿐이고, 나머지 선행 선언은 바이트에 영향이 없습니다. KZ6 이 NeXTMach `ev_vars.h` 의 선언과 같으므로 가장 충실하고 경고도 없습니다.

### 729.2 사용자 재결정과 §729 의 고침 (코딩 전, 2026-11-03)

사용자 결정(D164 ①의 재결정, AskUserQuestion): "ev_vars.h 선언 아홉 줄(KZ6)". §729 를 다음처럼 고칩니다(나머지는 그대로).
- 결정 ①: `known_warnings` 를 쓰지 않습니다. 이름 블록에 NeXTMach `ev_vars.h:48–56` 의 `/* ev_kbd.c */` 선언 아홉 줄을 그대로 둡니다(KZ6: `LLEventPost` 는 NeXTMach 처럼 선언 없음). 경고 0, 바이트 같음(§728.5).
- 1단계 기반: `ev_kbd_KZ1.c` 가 아니라 `ev_kbd_KZ6.c`(23/23, 경고 0). 단언의 "L 과 KZ1 의 토큰이 같음"은 KZ6 으로 바꿉니다.
- 4단계 경고: F·L 모두 0 줄. 6단계: 명세에 `known_warnings` 없음, `gate.ok` 는 경고 0 으로 정합니다. 확인 기록의 "경고 = `known_warnings`" 는 "경고 0".
- M7 의무의 "경고 15 줄…" 문장은 지웁니다(틀렸음, §729.1).
- 이름 블록의 표지 문구: 진단의 "the NeXTMach nextdev/ev_vars.h and next/scr.h names ev_kbd.c uses" 를 다음으로 고칩니다. "NeXTMach `nextdev/ev_vars.h` (`/* ev_kbd.c */` 선언 아홉 줄 48–56 그대로; `KeyMapping` 형은 208–228 에 1997 필드를 더한 꼴) 과 `next/scr.h:106–107`(BRIGHT_MAX, BRIGHT_MIN)의 이름·값·선언; `evg`·`screens`·`dimmedBrightness`·ADB 이름은 이 둘에 없는 재구성". PROVENANCE 에 넣을 줄 범위는 python 으로 원본을 열어 뽑은 목록만 씁니다: `ev_vars.h` 48–56, 93–95, 175, 177, 180, 182–183, 186–187, 189–190, 193, 208, 218, 221, 228, 230–232, 235–238, 258–259, 261–262, 264–265, 267, 270–272, 275–276 은 이름이 나타나는 줄(맞는지는 PROVENANCE 를 쓸 때 줄 내용으로 다시 대조), `scr.h` 106–107.

### 729.3 구현 결과(2026-11-03)

먼저 제 잘못:
1. 사용자께 경고 처리를 여쭐 때 "NeXTMach 글이 경고 15 줄을 낸다"는 틀린 전제를 말씀드렸습니다(codex 가 `ev_vars.h:49·51·55` 를 짚음; §729.1). 선행 선언을 넣어 시험하고 다시 여쭈어 재결정되었습니다.
2. 생성기 첫 판이 NeXTMach 의 큰 블록 주석 한가운데에 "지운 줄" 표지 주석을 넣어 주석이 일찍 닫히고 코드가 새는 파일을 만들었습니다(`L` 과 `KZ6` 의 토큰 비교가 7512 대 7433 으로 막았습니다). 주석 안에서는 구분자 없는 줄로 쓰도록 고쳤습니다. 또 이름 블록 표지 안에 `/* ev_kbd.c */` 를 넣어 주석을 닫아 버린 것도 같은 검사로 찾았습니다.
3. 함수 범위 찾기가 `} /* SetKeyMapping */` 처럼 닫는 줄에 주석이 붙은 함수를 놓쳐 `CalcModBit` 를 삼켰고, 머리 줄 끝의 표지 주석을 주석 끝으로 오인했습니다(둘 다 고침, 함수 수 22 → 23).
4. 근거 문서 초안에 `__const` 끝 주소(0x40ad8bc → 0x40ad8ac)를 잘못 썼고 표 몇 칸이 표지 주석보다 자세히 단정했습니다(열어 고침).

결과(모두 미리 정한 기준대로):
- 1 07 `07_kernel/src/machdep/m68k/ev_kbd.c`(975 줄, SHA-256 `7f617d1687407afe0cd3d974805752ad8b1ba0d44996845c56e37690fba59f93`)는 scratch `p728/gen_p729.py --write` 가 KZ6 에서 만들었습니다. 원천 검사(`chk729.py`): F = L 토큰, L = KZ6 토큰, 표지 없는 바뀐 줄 0(NeXTMach 와 84 hunk, BEGIN/END 구역 10), 머리 주석 보존.
- 2 `stage_m68k.py` 792 → 795 줄(`M4FILES`·`M4HEADERS`·`EXCEPTS[729]`, 머리말). 새 머리 없음.
- 3 회귀: `m0p727-r729-stage` = 보관본 `m0p727-a2-stage`(1021 파일), `m0p729-a1-stage`(1022)와의 차이는 `ev_kbd.c` 하나뿐입니다. M5 205 `m3p729-cc1` 의 617 파일은 받아들인 `m3p727-cc2` 와 `run.json` 만 다르고 `compare` 는 `differ_unexpected`·`lost` 가 비었으며 `stage_vs_test_stage` 는 `ev_kbd.c` 만 늘었습니다. x86 입력은 `ok` 이고 p727 과 같으며 x86gate 는 `plan`·`tool_sha256` 만 다릅니다.
- 4 확인 run `m4p729-p1`(`m4-m68k-p729-p1checks-20261103.json` `ok`): F·L 경고 0, 23/23, 절 3862/13/1850, `__data`·`__const` 원본 바이트와 같음, 원본에 없는 이름 0(COMMON 7, 미정의 36), F = L = KZ6(`canon`; STABS 는 소스 경로만 다름).
- 5 `-E` run `m4p729-e1`: F = L 22185 토큰, stderr 0, i386 0.
- 6 최종 run `m4p729-a1`(`m4-m68k-p729-final-20261103.json`, SHA-256 `40ab97b4…`): `gate.ok`, L1 OBJECT_MATCH, funcbytes 23/23. 확인 기록 `m4-m68k-p729-checks-20261103.json`(`ok`, SHA-256 `8619165e…`): 의존 152(저장소 파일 135 의 SHA 사슬), 선택지 = M5 줄, 07 = 스테이지. 객체 SHA-256 `4ff02ad8…`.
- 7 상태(`m4-m68k-status-p729-20261103.json`, 표 67 → 68 줄; 두 번 돌려 출력 경로 칸만 다름; 이전 행은 그대로): 객체 **66**(OBJECT_MATCH 51, CODE+BSS_INFERRED 15), 행 **88/188** 그대로(행 215 는 `exact` 0), **128652 B(59.60퍼센트)**, `object_bytes` **185236**. 미리 계산한 값과 같습니다.
- 8 기록: 근거 `m68k-ev_kbd.md`·`m68k-ev_kbd.diff`(930 줄), PROVENANCE 1235 → 1236 행, MODIFICATIONS 762 → 763, DECISIONS D164(167 → 168 행).

판정(미리 정한 대로): 관문을 모두 통과해 받아들였습니다(D164).
