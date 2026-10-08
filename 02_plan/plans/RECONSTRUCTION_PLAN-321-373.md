# 커널 소스 복원 작업계획 — 보관 §321–373

`02_plan/RECONSTRUCTION_PLAN.md` 의 §321–373 을 절 번호·내용 그대로 옮긴 보관본(2026-10-07, D026 방식, 사용자 지시 “완료된 작업은 완료 문서로 분리해도 됩니다”). 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킨다. 아래는 원문 그대로다.

## 321. S5-P311 세부 계획 — `libDriver/IODevice.m`(D024·D027·D030·D031, plan 315 꼴; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/IODevice.m(본문 바탕); SDK driverkit/IODevice.h(07 nextdev — ivar `_unit`·`_deviceName`·`_location`·`_deviceKind`·`_IODevice_reserved[4]` = 원본 ivar 목록); Darwin 비공개 머리 IODeviceParams.h·IODeviceDescriptionPrivate.h·IODeviceKernPrivate.h 는 07 에 사본 없이 Darwin 에서 스테이징(plan 308·309 와 같은 규칙); Mach4·NeXTMach 같은 이름 없음.

0. 원본(python·objc.json): 모듈 "IODevice.m"(0x20904c, 클래스 1·카테고리 3) `__text` [0x1a3d0c, 0x1a521f) 5395 B — 메서드 46 + 함수 6(외부 `_IOGetObjectForDeviceName` 와 정적 5); 앞 `00` 2 B, 뒤 `00` 1 B 로 IOConfigTable valueForStringKey: 0x1a5220; `__data` 297 B(0x1e4f98, IONamedValue 반환값 표 등), `__bss` 32 B(0x1e8668 추정).
1. Darwin 이 더한 것(i386 에서 컴파일되고 원본 목록에 없음) 20 개를 뺌: `deviceDescription`·`setDeviceDescription:`·`getDevicePath:maxLength:useAlias:`·`matchDevicePath:`·`lookUpProperty:…`(둘)·`lookUpStringProperty:…`·`property_IODriverNames:length:`·`property_IODevicePath:length:`·`getStringPropertyList:…`·`matchStringPropertyList:…`·`registerLoudly`·`serverConnect:taskPort:`(본·GlobalParameter)·`lookUpByStringPropertyList:…`·`getStringPropertyList:…`(GlobalParameter)·`getByteProperty:…`·`callDeviceMethod:…`·`property_IODeviceClass:length:`·`property_IODeviceType:length:`. `#else !KERNEL`·`#if 0` 안의 것은 그대로.
2. 원본 대로 고침(plan 321 표시): ① `initFromDeviceDescription:`(0x1a4124, 12 B)는 `return self` 만(`__deviceDescription` ivar 없음); ② `registerDevice`(0x1a416c)는 registerLoudly 조건 없이 `_location[0]` 이면 “Registering: %s at %s\n”, 아니면 “Registering: %s\n”(원본 문자열 0x1d6ca4·0x1d6cbc), 장치 경로·slot 로그 없음; ③ `unregisterDevice` 는 registerLoudly 조건 없이, 목록 원소가 있을 때 “Unregistering Device: %s\n”(0x1d6cd0); ④ `addToBdevswFromDescription:open:close:strategy:dump:psize:isTape:`(원본 셀렉터, Darwin 의 `ioctl:` 인자 없음 — `IOAddToBdevswAt` 도 SDK devsw.h 대로 ioctl 없이); ⑤ 반환값 이름 표의 “Privilege Violation” 은 원본 철자 “Privelege Violation”(원본 0x1d6c2c).
3. 진단: Darwin 본문은 빌드 실패(분류 `s5p304-00-4`, `s5p318-e1`). 1·2 를 차례로 넣은 `s5p322-a1`…`e1`: 정의 없이(`c1`)는 큐 매크로·형식 문자열이 달라 크게 다르고, plan 315 꼴 `-DMACH_USER_API -UKERNEL_PRIVATE` 의 `s5p322-e1` → 텍스트 52 항목 바이트 0 차이, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
4. 방법: 07 `src/driverkit/libDriver/IODevice.m`(mkfinal, D030 머리) → plan 315 꼴 iter_objc(RUNIN) → relcheck → zerofill `--place-from-l1` → record_objc.

### codex 교차검토 판정(2026-10-05, plan 321; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·메서드 46·20 개 없음·`ioctl:` 없는 셀렉터·5395 B·앞 2/뒤 1 B | 앞서 python·objc.json 목록 | ✅ |
| initFromDeviceDescription: 은 self 반환뿐, registerDevice 두 문자열·registerLoudly 없음 | 앞서 odis2·img.py 문자열 | ✅ |
| unregisterDevice 의 로그는 “조건 없이”가 아니라 목록 원소가 있을 때 | 앞서 odis2(0x1a4271 `je` 뒤 IOLog) | ✅ 2-③ 문구 고침 |
| 표 0x1e4fc0 = −705, 0x1d6c2c “Privelege Violation” | img.py: −705, 문자열 확인; return.h IO_R_PRIVILEGE | ✅ |
| 뺀 20 개는 모두 i386 KERNEL 에서 컴파일됨(제거 필요) | 앞서 #if 구간 목록과 대조 | ✅ |
| 초안 차이는 계획대로 + 주석; 최종본은 D030 머리 필요 | 07 최종본은 mkfinal(고지 검사) | ✅ |
| e.json 은 `__bss` 만 미확인 | 앞서 python | ✅ |
| Darwin 머리 직접 스테이징은 plan 308·309 와 같고 규칙상 허용 | 두 매니페스트 확인(앞서) | ✅ |

### 결과(2026-10-05, plan 321)

- 07 `libDriver/IODevice.m`(Darwin 본문 + plan 321 표시 + D030 머리). `s5p321-it1`(plan 315 꼴, RUNIN) `__text` 차이 0, `__bss` 만 미확인 → zerofill: 32 B [0x1e8668, 0x1e8688) 참조 추정(참조 96, Delta 0x1e6050 하나, 음성 검사 검출) → **P**. relcheck 0. 알려진 배치 53 개 `zerofill-known-s5p321-20261005.json`.

## 322. S5-P312 세부 계획 — `libDriver/Kernel/IOEthernet.m` 작성(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/IOEthernet.m 은 4.4BSD(`struct ifnet`·mbuf·bpf, `en_arpcom`)로 고친 판이라 그 부분은 쓰지 않음 — Darwin 본문의 공통 부분(DriverCmd·타임아웃·멀티캐스트 비교·출력)과 같은 시대 netif 판인 07 IOTokenRing.m(plan 303, OBJECT_MATCH)을 본보기로, 원본 명령에서 작성; SDK driverkit/IOEthernet.h(ivar `_isRunning`·`_promiscEnabled`·`_driverCmd`·`_absTimeout`·`_multiLock`·`_multiAddr`·`_multicastQueue`·`_netif`·`_ethernetAddress`·reserved[4] = 원본 ivar 목록), bsd/net/etherdefs.h·netif.h; 머리 driverkit/IOEthernetPrivate.h 는 plan 310 의 07 D030 사본; Mach4·NeXTMach 같은 이름 없음.

0. 원본(python·objc.json·odis3): 모듈 "Kernel/IOEthernet.m"(0x20913c, 클래스 2·카테고리 1) `__text` [0x1a9f1c, 0x1aacdf) 3523 B — 정적 타임아웃 함수(0x1a9f1c) + DriverCmd 5 + IOEthernet 24 + PrivateMethods 5 = 35 항목; 앞 `00` 3 B(IORemoveFromVfssw 쪽), 뒤 `00` 1 B 로 `_reserveDebuggerLock` 0x1aace0(IOEthernetDebugger, 기록됨). `__TEXT,__const` 84 B(0x1d5c78: “add-multicast”·“promiscuous-on”·“rmv-multicast”·“promiscuous-off” 와 0 으로 찬 메시지 틀 24 B), `__data` 12 B(0x1e5144 “en”·“Ethernet”), `__bss` 4 B(0x1e86fc 장치 수).
1. 원본과 Darwin 의 차이(전부 원본 명령으로 확인):
   ① DriverCmd: `_param`·`param`·`send:withParam:` 없음 — `send:` 하나(IOTokenRing 의 DriverCmdtr 와 같은 꼴, 메서드 크기 104·72·16·80·208 동일).
   ② initFromDeviceDescription:: en_arpcom·mbuf 선택 없음; DriverCmd 생성 뒤 `_multiLock = [NXLock new]`·`queue_init`; 이름·종류·단위 뒤 `registerDevice`.
   ③ free: `_multiLock` 이 있으면 잠그고 멀티캐스트 큐를 비운(IOFree 20 B) 뒤 unlock·free.
   ④ isUnwantedMulticastPacket:: searchMulti: 를 `_multiLock` lock/unlock 로 감쌈.
   ⑤ performLoopback:: 빈 함수가 아니라 그룹 비트가 있고 원치 않는 패킷이 아니면 `allocateNetbuf` 로 복사(`nb_write`, 길이 + 14)해 `[_netif handleInputPacket:extra:0]`.
   ⑥ inputPacket:extra:·getDriverCmd·allocateIfnet·property_IODeviceClass:length: 없음; `resetAndEnable:` 은 YES 반환(원본 0x1aa800); attachToNetworkWithAddress: 는 IONetwork 생성 → registerAsDebuggerDevice → 주소 IOLog.
   ⑦ performCommand:data:: SETFLAGS(무시)·GETADDR(bcopy 6)·promiscuous-on/off(send 5/6)·add/rmv-multicast(enableMulticast:/disableMulticast:)·그 밖 EINVAL — 마지막 넷은 모듈 자신의 `static const char` 문자열(원본 `__const`; 전역 `_IFCONTROL_*` 0x1d12xx 가 아님; 이름은 원본에 남지 않아 붙인 이름).
   ⑧ PrivateMethods: enqueueMulticast:/dequeueMulticast: 없음 — enableMulticast:/disableMulticast: 가 `_multiLock` 아래에서 큐를 직접 고치고 `_multiAddr` 에 복사한 뒤 `send:7`/`send:8`; commandRequestOccurred 는 `[_driverCmd param]` 대신 `&_multiAddr`, TERMINATE 에 큐 비우기 없음.
   ⑨ `IOEthernetDeviceCount` 는 초기값 없는 정적 변수(원본 `__bss`; `= 0` 이면 `__data` 로 감).
2. 진단(분류와 같은 머리 대체, 진단 `# 1 "Kernel/IOEthernet.m"`): `s5p323-a1`(정의 없음)은 free·enable/disableMulticast 크기 다름(커널 queue 매크로); `-UKERNEL_PRIVATE`(`b1`)는 enableMulticast: 만 8 B 큼 → 이미 있을 때 unlock 후 return 하는 꼴(`c1`)로 `__text` 35 항목 바이트 0 차이(L1 의 39 항목 = `__text` 35 + `__const` 문자열 4), `__data` 후보 둘 → ⑨(`d1`)로 사유 `__DATA,__bss: unverified` 하나.
3. 빌드 꼴: `EXTRA_DEFS=-UKERNEL_PRIVATE`(파일 안 `#define MACH_USER_API 1`; plan 315 와 같은 근거의 부분 꼴).
4. 방법: 07 `src/driverkit/libDriver/Kernel/IOEthernet.m`(프로젝트 작성 머리 — D024, 원본 바이트에서 작성, Darwin 공통 부분은 거의 그대로 → 기록에 “Darwin 0.1 IOEthernet.m 의 공통 부분과 거의 같음, 4.4BSD 부분은 쓰지 않음”) → iter_objc(RUNIN) → relcheck → zerofill(`__bss` 4 B; 참조 수가 적으면 D019 기준 확인) → record_objc.

### codex 교차검토 판정(2026-10-05, plan 322; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·클래스 2·카테고리 1·3523 B·이웃 맞음; **함수는 39 가 아니라 35**(L1 39 = `__text` 35 + `__const` 4) | python Counter(d.json: `__text` 35, `__const` 4 — 정적 문자열 넷) | ✅ 0·2 항 고침(내 수치가 틀림) |
| ①–⑧ 원본 명령과 맞음(DriverCmd 크기, NXLock, IOFree 20, lock 감쌈, +14, 지역 문자열, 7/8, &_multiAddr, TERMINATE) | 앞서 odis3 덤프 대조 | ✅ |
| ⑨ 저장 위치는 맞으나 원문의 이름·초기값 철자는 바이트로 알 수 없음 | 기록에 이름·꼴은 재구성이라고 적음 | ✅ |
| 기능 추가 없음; 정적 이름·주석은 재구성/참조 텍스트로 기록할 것 | — | ✅ 파일 머리·기록 문구 |
| d.json 사유는 `__bss` 하나; zerofill 참조 2·Delta 하나 → 참조 추정(D019 단일 참조 예외 불필요) | 앞서 zerofill 시험 출력 | ✅ |
| D030 로 프로젝트 작성 + “공통 부분은 Darwin 0.1 IOEthernet.m 과 거의 같음” 기록이 맞음 | DECISIONS D030 | ✅ |

### 결과(2026-10-05, plan 322)

- 07 `libDriver/Kernel/IOEthernet.m`(원본 바이트에서 작성, D030 머리). `s5p322-it1`(`EXTRA_DEFS=-UKERNEL_PRIVATE`, RUNIN; IOEthernetPrivate.h 는 07 사본) `__text` 35 항목 차이 0, `__bss` 만 미확인 → zerofill 4 B [0x1e86fc, 0x1e8700) 참조 추정(참조 2, Delta 0x1e6df0, 음성 검사 검출) → **P**. relcheck 0. 알려진 배치 54 개 `zerofill-known-s5p322-20261005.json`.

## 323. S5-P313 세부 계획 — `libDriver/Kernel/IOConfigTable.m`(D024·D027·D030·D031·D035; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/IOConfigTable.m(본문 바탕); SDK driverkit/IOConfigTable.h(ivar `_private` = 원본); Darwin 비공개 머리 configTableKern.h·configTablePrivate.h 는 plan 308·309·321 처럼 Darwin 에서 스테이징; i386 kernBootStruct.h 는 어느 트리에도 없음(D035).

0. 원본(python·objc.json): 모듈 "Kernel/IOConfigTable.m"(0x20905c, 클래스 1·카테고리 1) `__text` [0x1a5220, 0x1a5447) 551 B — 메서드 6 + 외부 `_strstr`(0x1a52cc); 앞은 IODevice(기록됨, `00` 1 B), 뒤 `00` 1 B 로 `_IOMalloc` 0x1a5448(generalFuncs, 기록됨). 원본 메서드 목록 = Darwin 과 같음.
1. 수정(plan 323 표시): ① D035 — `#import <machdep/i386/kernBootStruct.h>` 를 지역 정의로 바꿈: `newFromSystemConfig`(0x1a5384)가 넘기는 주소 0x134fc → config 오프셋 0x24fc(python: 0x134fc − 0x11000)인 `KERNBOOTSTRUCT`(그 칸만)과 `KERNSTRUCT_ADDR`(0x11000); ② `newForConfigData:`(0x1a53e4, 명령 99 B + 정렬 `00` 1 B)는 `[[self alloc] init]` 이 아니라 `[self alloc]` 만(원본에 init 메시지 없음).
2. 진단 `s5p324-a1`(①만)·`b1`(plan 315 꼴): newForConfigData: 만 다름(115 대 100 B); ② 더한 `s5p324-c1`(정의 추가 없음) → **OBJECT_MATCH**(7).
3. 방법: 07 `src/driverkit/libDriver/Kernel/IOConfigTable.m`(mkfinal, D030 머리) → iter_objc(RUNIN, 정의 추가 없음) → relcheck → record_objc(A 예상).

### codex 교차검토 판정(2026-10-05, plan 323·D035; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·메서드 6·551 B·앞뒤 `00`·`_strstr`·`_IOMalloc` | 앞서 python·grep symbols.tsv | ✅ |
| 0x1a5387 `push 0x134fc`, newForConfigData: 는 alloc 한 번뿐 | 앞서 odis3 | ✅ |
| “100 B” 는 명령 99 B + 정렬 00 1 B | python(0x1a5447 앞 `c3 00`) | ✅ 1 항 문구 고침 |
| i386 kernBootStruct.h 는 어느 트리에도 없고(ppc 판뿐), 지역 정의 오프셋은 i386_init.c 의 지역 정의와 모순 없음(전체 크기는 미정) | 앞서 find | ✅ |
| Darwin 대비 차이는 두 곳뿐 | 앞서 작성 내용 | ✅ |
| c.json OBJECT_MATCH 7 | 앞서 python | ✅ |

### 결과(2026-10-05, plan 323)

- 07 `libDriver/Kernel/IOConfigTable.m`(Darwin 본문 + plan 323 표시 + D030 머리). `s5p323-it1`(RUNIN, 정의 추가 없음) OBJECT_MATCH(7), relcheck 0 → **A**.

## 324. S5-P314 세부 계획 — 커널 트리 `machdep/i386/swapgeneric.m`(D024·D027·D033·D035; 코딩 전, 2026-10-05)

참조(파일명, 모든 트리): Darwin 0.1 kernel/machdep/i386/swapgeneric.m(본문 바탕), NeXTMach mk-108.1/next/swapgeneric.c(m68k 판 — `strcpy(rootfs.bo_fstype,"4.3"/"nfs")` 꼴은 같으나 장치·구조가 달라 본문으로 쓰지 않음); i386 kernBootStruct.h 없음(D035); Darwin 비공개 머리 driverkit/IODeviceParams.h 는 Darwin 에서 스테이징, SCSIDisk.h 는 07 사본(plan 311·314).

0. 원본(python·objc.json·symbols.tsv): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/machdep/i386/swapgeneric.m"(0x208fcc, 클래스 없음) `__text` [0x191848, 0x191e48) 1536 B — `_setconf`·`_gets`·`_getfsname`·정적 scsiControllerDetected(0x191c68)·`_initrootnet`(0x191d4c, 앞 채움 `90` = 같은 객체 안 정렬); 앞 `00` 2 B(`_pmap_page_protect` 쪽), 뒤 채움 없이 `_resuba` 0x191e48(sys_machdep, 기록됨); `__data` 476 B(0x1e2630: boottype·boothowto·genericconf·문자열 — 커널 꼴 -fwritable-strings), `__bss` 8 B.
1. 원본과 Darwin 의 차이(odis3·원본 문자열):
   ① D035 — `#import <machdep/i386/kernBootStruct.h>` 대신 지역 정의: `magicCookie` +0xa4(0x110a4 와 KERNBOOTMAGIC 0xa7a7a7a7 비교), `rootdev` +0xac(0x110ac).
   ② `boothowto` 초기값 0(원본 0x1e2634 = 0; Darwin 은 RB_DEBUG — 07 의 SDK reboot.h 로는 정의도 안 됨).
   ③ setconf: 마법수 검사 뒤 `strcpy(rootfs.bo_fstype,"4.3")`(원본 0x191877: “4.3” 4 바이트를 `_rootfs` 0x1e98f0 로; `#import <sys/bootconf.h>` 추가 — rootfs 선언); 재시도의 DoSafeAlert(“Root Device?”)·`panelUp`·끝의 `alert_done()` 없음(원본 문자열·호출 없음); NFS 갈래는 `strcpy(rootfs.bo_fstype,"nfs")` 만(“mounting nfs root”·nfsbootdevname·mountroot·`rootdev = NODEV` 없음), 디스크 갈래에 `mountroot = ffs_mountroot` 없음.
   ④ `initrootnet` 은 Darwin 의 `#if 0` 을 풀어 컴파일(원본 0x191d4c, 252 B, 문자열 “initrootnet: …” 이 원본 `__data` 에 있음).
2. 진단(분류와 같은 머리 대체, 진단 `# 1 "/BinarySourceCache_…/swapgeneric.m"`, 커널 꼴 KEEPWS): `s5p325-a1`(①만) RB_DEBUG 없음으로 실패; ②(`b1`) setconf 780 대 688 B; ③(`c1`·`d1`) 함수 넷 맞음·`__data` 일부; ④(`e1`) → `__text` 5 함수 바이트 0 차이, `__data` 476 B 맞음, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법(사용자 결정 D036 — D029 처럼): 07 `src/machdep/i386/swapgeneric.m` = Darwin 0.1 원문(Apple·NeXT 고지 유지) + 1 항 수정(각 자리에 plan 324 표시) → iter_objc_abs(ABSROOT, 커널 꼴) → relcheck → zerofill `--place-from-l1` → record_objc(logical = src/machdep/i386/swapgeneric.m) 뒤 PROVENANCE 행을 darwin01(kernel-1.tar.gz, APSL, D029/D036)로, MODIFICATIONS 에 복원 수정 행.

### codex 교차검토 판정(2026-10-05, plan 324·D036; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·1536 B·함수 다섯·내부 채움 `90`·이웃 | 앞서 python·symbols.tsv | ✅ |
| 0x110a4/0x110ac, boothowto 0, “4.3”/“nfs” → `_rootfs`(bo_fstype 오프셋 0), 알림·mountroot 없음, initrootnet 252 B | 앞서 odis3·img.py·bootconf.h | ✅ |
| 초안 차이는 계획대로, 고지(1–44 줄) 그대로 | diff 1–40 줄 동일 확인 | ✅ |
| e.json `__bss` 만 미확인 | 앞서 python | ✅ |
| D036 은 “쓸 수 있는 대응 판 없음”이 아니라 “i386 바탕으로 쓸 판 없음”(공통 논리는 NeXTMach 에도 있음) | NeXTMach swapgeneric.c 88–92(버스 표)·203–209(bo_fstype) 열람 | ✅ D036 문구 좁힘 |

### 결과(2026-10-05, plan 324)

- 07 `src/machdep/i386/swapgeneric.m`(Darwin 0.1 원문 + Apple·NeXT 고지 유지 + plan 324 수정, D029/D036). `s5p324-it1`(ABSROOT, 커널 꼴) `__text` 5 함수 차이 0, `__data` 476 B 맞음, `__bss` 만 미확인 → zerofill 8 B [0x1e773c, 0x1e7744) 참조 추정(참조 9, Delta 0x1e6e78, 음성 검사 검출) → **P**. relcheck 0. 알려진 배치 55 개 `zerofill-known-s5p324-20261005.json`.
- 기록: record_objc 뒤 PROVENANCE 행을 darwin01(kernel-1.tar.gz, APSL, D029/D036)로, MODIFICATIONS 행의 출처를 Darwin 으로 고침; 근거 diff 는 Darwin 원문 대비로 다시 만듦.

## 325. S5-P315 세부 계획 — 커널 트리 `driverkit/i386/autoconf_i386.m`(D024·D027·D030·D033·D035; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 kernel/driverkit/i386/autoconf_i386.m 만 있음(Mach4·NeXTMach·SDK 에 같은 이름 없음) — Darwin kernel/driverkit 의 KernLock.m 등(plan 304–306)과 같은 D030 처리; driverkit/i386/EISAKernBus.h·PCMCIA.h·PCMCIAKernBus.h·PCIKernBus.h 는 어느 트리에도 없음(원본 커널에도 그 클래스 없음 — objc.json 의 EISA/PCI/PCMCIA 클래스는 *DeviceDescription·IOPCMCIATuple 뿐); i386 kernBootStruct.h 없음(D035).

0. 원본(python·symbols.tsv·objc.json): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/driverkit/i386/autoconf_i386.m"(0x208fdc, 클래스 없음) `__text` [0x193f34, 0x1948f6) 2498 B — `_probeNativeDevices`·정적 configureDriver·`_eisa_present`·`_eisa_id`·`_configureThread`·`_probeHardware`·`_probeDirectDevices`·`_findBootConfigString`·정적 bootDriverInit(9 함수); 앞 `00` 3 B, 뒤 `00` 2 B 로 `_cnopen` 0x1948f8; `__data` 925 B(0x1e2954), `__bss` 5 B.
1. 수정(plan 325 표시): ① 빌드 전용 — 위 네 머리 import 를 뺌(어느 트리에도 없고 이 파일은 그 안의 것을 쓰지 않음; 바이트 무관). ② D035 — kernBootStruct.h 대신 지역 정의: `numBootDrivers` +0x154(원본 `cmp [0x11154]`), `driverConfig` +0x168(i386_init.c 의 지역 정의와 같음), `config` +0x24fc(원본 `mov esi,0x134fc`), `CONFIG_SIZE` = 13×4096(원본 `cmp eax,0xd000`; Darwin ppc 판은 12×4096).
2. 진단 `s5p326-a1`(위 수정 + 진단 `# 1`, 커널 꼴 KEEPWS, 정의 추가 없음): 9 함수 바이트 0 차이(MATCH 7, eisa_present·eisa_id 는 `__bss` 참조로 MATCH_UNVERIFIED), `__data` 925 B 맞음, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법: 07 `src/driverkit/i386/autoconf_i386.m`(mkfinal, D030 머리 — plan 304 의 Kern*.m 와 같은 꼴, “nearly the same as Darwin 0.1 kernel/driverkit/i386/autoconf_i386.m”) → iter_objc_abs(ABSROOT, 커널 꼴) → relcheck → zerofill → record_objc(logical = src/driverkit/i386/autoconf_i386.m).

### codex 교차검토 판정(2026-10-05, plan 325; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·2498 B·9 함수·이웃 맞음; **configureThread 는 정적이 아니라 외부** | grep symbols.tsv `_configureThread` 있음(형 0xf), Darwin 정의도 외부 | ✅ 0 항 고침(내 서술이 틀림) |
| 0x134fc·0xd000·0x11154·[edi+ebx*8+0x168] | 앞서 odis3 | ✅ |
| 네 머리는 어느 트리에도 없고 이 파일은 그 머리의 이름을 쓰지 않음; 원본에 그 클래스 없음 → import 제거는 빌드 전용 | 앞서 find·objc.json 클래스 목록 | ✅ |
| 초안 차이는 계획대로 | — | ✅ |
| a.json 9 함수 차이 0, `__data` 925 B, `__bss` 만 미확인 | 앞서 python | ✅ |
| D030 처리(KernLock 과 같음) | DECISIONS D029/D030, PROVENANCE KernLock 행 | ✅ |

### 결과(2026-10-05, plan 325)

- 07 `src/driverkit/i386/autoconf_i386.m`(D030 머리 + plan 325 표시). `s5p325-it1`(ABSROOT, 커널 꼴) `__text` 9 함수 차이 0, `__data` 925 B 맞음, `__bss` 만 미확인 → zerofill 5 B [0x1e7744, 0x1e7749) 참조 추정(참조 4, Delta 0x1e668c, 음성 검사 검출) → **P**. relcheck 0. 알려진 배치 56 개.

## 326. S5-P316 세부 계획 — 커널 트리 `bsd/dev/i386/km.m`(D013·D024·D029·D033·D035·D037; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/km.m(본문 바탕, 4.4BSD termios 판), NeXTMach mk-108.1 nextdev/km.c(m68k 판 — 4.2 의 tty 처리와 같은 옛 꼴), Darwin ppc km.m(쓰지 않음).

0. 원본(python·symbols.tsv·objc.json): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/i386/km.m"(0x208ffc, 클래스 없음) `__text` [0x196d14, 0x1975cd) 2233 B — 외부 18(kmopen … kmGraphicPanelString, kmselect 포함) + 정적 kmstart(0x197134)·kmoutput(0x1971e4); 뒤 `00` 3 B 로 0x1975d0(다음 모듈 메서드); `__data` 1 B, `__bss` 4 B.
1. 원본과 Darwin 의 차이(odis3·원본 상수):
   ① D035 — kernBootStruct.h 대신 지역 정의 `graphicsMode` +0x14c(원본 `cmp [0x1114c],0`).
   ② kmopen: termios 초기화 대신 NeXTMach km.c:262–273 꼴 — `t_addr = 0`, `t_oproc = kmstart`, `t_line = NTTYDISC`(2), 닫혀 있으면 `ttychars`, `t_flags` = EVENP|ODDP|ECHO|CRMOD|CRTBS|CTLECH|CRTERA|CRTKIL|PRTERA(= 0x140700d8, python 확인), `t_erase = 0x7f`, `t_ispeed = t_ospeed = B9600`, `t_state = TS_CARR_ON`(NeXTMach 은 `TS_ISOPEN|TS_CARR_ON`); 열려 있고 TS_XCLUDE 이며 `u.u_uid != 0` 이면 EBUSY.
   ③ kmclose/kmread/kmwrite/kmioctl: 옛 linesw 인자(`l_close(tp)`, `l_read(tp, uio)`, `l_write(tp, uio)`, `l_ioctl(tp, cmd, data, flag)`, `ttioctl(tp, cmd, data, flag)`), kmioctl 의 TIOCSETA* 갈래 없음.
   ④ kmselect(0x197024) 있음 — NeXTMach km.c:310–318 꼴(`l_select(tp, rw)`); Darwin 에는 없음.
   ⑤ kmstart(정적, int 반환 0): NeXTMach km.c:320–348 꼴(TTLOWAT·직접 깨우기) — `softint_sched` 대신 `calloutDispatchUnique(kmoutput, tp)`, `timeout` 대신 `ns_timeout(kmoutput, tp, KM_LOWAT_DELAY, CALLOUT_PRI_THREAD)`, `t_wsel = 0` 대신 `selthreadclear(&t_wsel)`.
   ⑥ kmoutput(정적): NeXTMach km.c:350–388 꼴 + `ttynty(tp)` 먼저(선언 순서), 8 비트 조건 `(t_flags & (RAW|LITOUT|PASS8OUT)) || !(t_pflags & TP_OPOST) || CSIZE == CS8` 이면 `ndqb(…, 0)`(07 tty.c:1976–1978 과 같은 꼴), `MIN()` 매크로, 출력은 `[kmId kmPutc:]`, 지연 문자는 `ns_timeout(ttrstrt, tp, ticks_to_ns_time(cc & 0x7f), CALLOUT_PRI_THREAD)`, 다시 돌릴 때 `calloutDispatchUnique`, 끝 깨우기는 ⑤ 와 같음.
   ⑦ kmgetc: `cnputc` 를 원형 없이 선언(원본은 int 로 넘김). ⑧ kminit: `FBAllocateVBEConsole()` 먼저, NULL 이면 `BasicAllocateConsole()`. ⑨ Darwin 의 전역 `km_tty[]` 없음(원본 기호 없음).
2. 진단(분류와 같은 머리 대체, 진단 `# 1`, 커널 꼴 KEEPWS, 정의 추가 없음): `s5p327-a1`…`j1` 로 차례로 맞춰 `j1` → 20 함수 바이트 0 차이(MATCH 18·MATCH_UNVERIFIED 2), `__data` 1 B 맞음, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법(D037): 07 `src/bsd/dev/i386/km.m` = Darwin 0.1 원문(Apple·NeXT 고지 유지) + 위 수정(각 자리 plan 326 표시, NeXTMach 에서 온 부분은 저장소·커밋·경로:줄을 적고 머리에 NeXTMach km.c 고지 줄) → iter_objc_abs(ABSROOT) → relcheck → zerofill → record_objc 뒤 PROVENANCE 를 darwin01 + NeXTMach 부분(D013)으로, MODIFICATIONS 출처 고침, 근거 diff 는 Darwin 원문 대비.

### codex 교차검토 판정(2026-10-06, plan 326·D037; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·2233 B·20 함수(kmselect 0x197024, 정적 둘)·다음 IMP 0x1975d0 | 앞서 python·symbols.tsv·objc.json | ✅ |
| ①–⑨ 원본 명령·NeXTMach 줄·tty.c:1976 과 맞음; 플래그 OR = 0x140700d8 | 앞서 odis3·python | ✅ |
| Darwin 대비 차이는 계획대로, 고지 그대로; j1 이후는 주석만 | diff(j1 스테이징 대 초안: 주석·고지 줄만) | ✅ |
| j.json `__bss` 만 미확인 | 앞서 python | ✅ |
| NeXTMach 출처(저장소·커밋 f6bdb9c3…·줄)·고지 줄 맞음 | 앞서 sed 로 줄 확인 | ✅ |

### 결과(2026-10-06, plan 326)

- 07 `src/bsd/dev/i386/km.m`(Darwin 원문 + 고지 유지 + plan 326 수정, NeXTMach 부분은 출처·고지 줄, D037). 첫 07 빌드 `s5p326-it1` 은 Darwin 전용 머리 bsd/dev/i386/kmDevice.h·km.h·BasicConsole.h·PCKeyboardDefs.h 가 스테이징되지 않아 실패(07 은 BSD 머리를 Darwin 에서 가져오지 않음) → D032 사본 넷을 `nextdev_private/bsd/dev/i386/` 에 두고 `s5p326-it2`(ABSROOT): `__text` 20 함수 차이 0, `__bss` 만 미확인 → zerofill 4 B [0x1e777c, 0x1e7780) 참조 추정(참조 2, Delta 0x1e6d98, 음성 검사 검출) → **P**. relcheck 0. 알려진 배치 57 개.
- 기록: PROVENANCE km.m 행을 darwin01+nextmach(D029/D037, D013)로, 머리 넷 행(D032); MODIFICATIONS 출처 고침과 머리 넷 행; 근거 diff 는 Darwin 원문 대비.

## 327. S5-P317 세부 계획 — 커널 트리 `bsd/dev/i386/kmDevice.m`(D024·D027·D030·D032·D033·D035; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/kmDevice.m(본문 바탕)·kmWaitCursor.h·kbd_entries.h, Darwin ppc 판(쓰지 않음). NeXTMach mk-108.1·Mach4 에 같은 이름 파일 없음(find) → 같은 디렉터리의 EventSrcPCPointer(plan 304)와 같이 D030(프로젝트 작성, Darwin 고지 없음, "nearly the same as Darwin 0.1").

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/i386/kmDevice.m"(objc 0x208fec, 클래스 kmDevice 하나, ivar·메서드 목록 Darwin 과 같음 — cmpcls) `__text` [0x195758, 0x196d12) 5562 B + `00` 2 B → 0x196d14(km), 31 함수(정적 kmDeviceDrawCursor 0x19585c 포함, DoSafeAlert 없음); `__data` 0x1e3798 1760 B; `__bss` 48 B.
1. 원본과 Darwin 의 차이(odis3·ddiff):
   ① D035 — kernBootStruct.h 대신 지역 정의 `graphicsMode` +0x14c(원본 `cmp [0x1114c],0`).
   ② `mach_title` = "NeXT Mach Operating System"(원본 `__data` +0xf0).
   ③ kmOpen: `case SCM_ALERT` 는 증가 없이 break; default 는 `suser()` 인자 없음(0 이면 EACCES 0xd; 07 kernserv/prototypes.h `int suser(void)`), SCM_OTHER 이면 EBUSY, O_POPUP 갈래 없음, `fbp[ALERT] = AllocConsole()`(NULL 이면 basicConsole) → `Init(…, SCM_ALERT, FALSE, TRUE, alert_title)` → savedFbMode·fbMode=SCM_ALERT·alertRefCount++ 차례.
   ④ drawRect:/eraseRect: `fbMode == SCM_ALERT` 이면 EBUSY(원본 `cmp …,3`); getStatus: `fbMode == SCM_TEXT` 이면 KMS_SEE_MSGS(원본 `cmp …,1`).
   ⑤ disableCons: Darwin `#if 0` 블록이 켜져 있음(원본 32 B, SCM_TEXT→SCM_OTHER).
   ⑥ animationCtl: STOP/SUSPEND 에 `ns_untimeout`·STOP 때 상태 0 없음. ⑦ canBecomeOwner: `kmDeviceAnimationState = -1` 없음.
   ⑧ DoAlert(2 인자)가 본체: DoSafeAlert 없음, saveUnder 는 늘 FALSE, SCM_ALERT 면 증가 없음, 창 Init 뒤에 alert 모드 진입·증가; `-doAlert:msg:` 는 `DoAlert(windowTitle, msg)`.
   ⑨ powerOffRequest: `boot(RB_BOOT, 0x90000, "")` — 4.2 SDK bsd/i386/reboot.h 에 RB_POWERDOWN·RB_EJECT 없음 → machdep.c(plan 241)처럼 파일 안 지역 정의로 Darwin 0.1 bsd/i386/reboot.h:52,55 의 이름·값 0x00010000·0x00080000(합 0x90000, python). 공유 reboot.h 에 넣지 않는 까닭: machdep.c:27 이 `RB_POWERDOWN 0x10000` 을 따로 정의(다른 토큰이라 재정의 경고).
   ⑩ kmWaitCursor.h: 커서 X·Y 가 원본 448·300(0x1c0·0x12c; Darwin (320-8)·256), 너비·높이·비트맵은 같음.
   ⑪ dumpMsgBuf: Darwin `msgbufp` 대신 4.2 이름 `pmsgbuf`(원본 0x196980·0x1969c9 `mov edx,[0x1dac14]`, symbols.tsv `_pmsgbuf` 0x1dac14; 07 bsd/sys/msgbuf.h:51, subr_log.c:45) — codex 지적으로 추가.
2. 진단(머리 대체, 진단 `# 1`, KEEPWS, 정의 추가 없음): `s5p328-a1`(suser·RB_POWERDOWN 빌드 실패)…`e1` → 31 함수 바이트 차이 0 이지만 `_msgbufp` 참조 2 미확인(처음 "`__bss` 만" 이라 적은 것은 틀림) → ⑪ 뒤 `f1`: MATCH 16·MATCH_UNVERIFIED 15, `__data` 1760 B 차이 0, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법: 07 `src/bsd/dev/i386/kmDevice.m` = D030 머리 주석 + Darwin 본문(고지 없음) + 위 수정(각 자리 plan 327 표시). D032 사본 `nextdev_private/bsd/dev/i386/kmWaitCursor.h`(⑩ 값만 plan 327 수정)·`kbd_entries.h`; ⑨ 는 파일 안 정의. → iter_objc_abs(ABSROOT) → relcheck → zerofill → record_objc, PROVENANCE(D030·D032)·MODIFICATIONS, 근거 diff 는 D030 관례대로 /dev/null 대비(autoconf_i386 와 같음; 처음 "Darwin 원문 대비" 라 적은 것을 고침).

### codex 교차검토 판정(2026-10-06, plan 327; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| dumpMsgBuf 는 `msgbufp` 가 아니라 `_pmsgbuf`(0x1dac14); e.json 에 "symbol _msgbufp not in image" 2 건 | grep s5p328-e.json:713–714; odis3 0x196980·0x1969c9; symbols.tsv:2424; msgbuf.h:51 | ✅ 채택(⑪, 내 "`__bss` 만" 기록이 틀림) → `f1` 에서 사유 `__bss` 하나 |
| 범위 5562 B, 0x196d12 `00 00`, 0x196d14 = _kmopen, 31 함수 | 앞서 python(l1 json 집계)·img.rd(0x196d10) = `5dc300005589` | ✅ |
| ①–⑩ 원본 명령·상수(0x1114c, 0x90000, 448·300, EACCES 13, EBUSY 16, 제목 문자열) | 앞서 odis3·ddiff·python | ✅ |
| `__bss` 48 B 는 참조 추정 [0x1e774c,0x1e777c) — 모듈 소속은 독립 확증 아님 | zerofill 결과로 확인 예정(결과 절) | ⚖️ P 등급 정의와 같음 |
| 처음 계획(공유 reboot.h)은 machdep.c:27 과 재정의 충돌, EventInput.m:840 은 `#if __nrw__` 안 | grep 07(machdep.c:27, EventInput.m:834–840) | ✅ (codex 회신 전에 이미 파일 안 정의로 바꿈) |
| D030/D032 가 맞음 — nextmach·mach4 에 같은 이름 없음 | find 01_resources/upstream(이름 셋) | ✅ |
| 초안에 고지 문구 없음 | mkfinal 검사·kbd/kmWaitCursor body() 검사(assert) | ✅ |

### 결과(2026-10-06, plan 327)

- 07 `src/bsd/dev/i386/kmDevice.m`(D030 머리 + Darwin 본문 + plan 327 수정 ①–⑪)과 D032 사본 `nextdev_private/bsd/dev/i386/kmWaitCursor.h`(X·Y 만 plan 327)·`kbd_entries.h`·`keycodes.h`. 첫 07 빌드 `s5p327-it1` 은 본문 643 행의 `bsd/dev/i386/keycodes.h` 사본이 없어 컴파일 실패 → D032 사본 추가 후 `s5p327-it2`(ABSROOT): 31 함수 차이 0(MATCH 16·MATCH_UNVERIFIED 15), `__data` 1760 B 차이 0, 사유 `__DATA,__bss: unverified` 하나. relcheck 0. zerofill 48 B [0x1e774c, 0x1e777c) 참조 추정(참조 66, Delta 0x1e5358 하나, 음성 검사 검출; km 의 [0x1e777c, 0x1e7780) 바로 앞) → **P**. 알려진 배치 58 개(`zerofill-known-s5p327-20261006.json`).
- 기록: record_objc — functions.tsv 3144→3175, objects_partial 55→56, PROVENANCE 807→808, MODIFICATIONS 325→326; 머리 셋 행(D032) PROVENANCE 808→811, MODIFICATIONS 326→329. 근거 `06_reconstruction/evidence/x86-kmDevice.md`·`.diff`.

## 328. S5-P318 세부 계획 — 커널 트리 `bsd/dev/SCSIDiskKern.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/SCSIDiskKern.m(본문 바탕)·driverkit-1/driverkit/SCSIDiskKern.h. NeXTMach mk-108.1·Mach4 에 같은 이름 파일 없음(find) → D030(프로젝트 작성, Darwin 고지 없음; EventSrcPCPointer·kmDevice 와 같음).

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/SCSIDiskKern.m"(objc 0x208fac, 클래스 0) `__text` [0x18335c, 0x184176) 3610 B(앞 `00` 3 B, 뒤 `00` 2 B → _sgopen 0x184178), 12 함수(외부 9: sd_init_idmap·sd_idmap·sdopen·sdclose·sdread·sdwrite·sdstrategy·sdioctl·sdsize, 정적 3: sdminphys 0x1840d0·sd_dev_to_id 0x1840ec·sd_phys_dev_id 0x18414c; sd_prevent_eject 없음); `__data` [0x1e1268, 0x1e137c) 276 B(첫 64 B 가 SCSIDisk_dev); `__bss` 588 B(= SCSIDiskIdMap 576 + int 셋, python).
1. 원본과 Darwin 의 차이(odis3·fdis):
   ① sdopen: waitForProbe:·이동식 매체 PREVENT·단위별 maxTransfer 없음; isDiskReady: 뒤 `maxTransfer == 0` 이면 `IOGetObjectForDeviceName("sc0", &controller)`(실패 시 `IOPanic("sdopen: can't find controller object")`) → `maxTransfer = [controller maxTransfer]`(원본 0x1834d8–0x183513, 문자열 0x1e134c·0x1e1350).
   ② 전역 `static unsigned int maxTransfer`(bss, sd_raw_major 뒤 0x1e756c; sdminphys `jbe` 로 부호 없음), SCSIDisk_Data_t 는 physbuf 하나(IOMalloc 0x44), sdminphys·DKIOCINFO 는 전역을 씀.
   ③ `SCSIDisk_dev[NUM_SD_DEV] = { 0 }` — 원본에서 `__data` 0x1e1268(bss 아님; 초기자 없으면 bss 652 B 로 64 B 큼).
   ④ sd_init_idmap: SCSIDisk_dev 를 포인터로 훑음(원본 edi = 0x1e1268, `add edi,4`).
   ⑤ sdclose: kprintf·synchronizeCache·ALLOW MEDIUM REMOVAL 없음. ⑥ sdstrategy: B_DONE 검사 없음.
   ⑦ sdioctl: `cmd` 는 int(원본 case 비교 jg/jl, 원형도); `part` 는 첫 switch 안에서 계산; `unit > NUM_SD_DEV`(원본 `cmp ecx,0x10; jg`); Darwin `#if 0` 의 raw 장치 검사 켬(원본 0x183a2b–0x183a38); DKIOCGLOCATION 두 곳 없음; DKIOCGLABEL/SLABEL 은 `userData` 로 copyout/copyin(원본 call 0x183bfb·0x183c27); DKIOCEJECT 는 PREVENT/ALLOW 없이 eject.
   ⑧ sd_prevent_eject 없음(원형·정의).
   ⑨ 빌드만: `#import <sys/types.h>` 를 sys/systm.h 앞에(4.2 SDK systm.h 는 daddr_t·dev_t 를 정의하지 않아 `s5p329-b1` 파싱 오류).
2. 진단(머리 대체, 진단 `# 1`, KEEPWS): `s5p329-a1`…`j1` → 12 함수 바이트 차이 0(MATCH 4·MATCH_UNVERIFIED 8), `__data` 276 B 차이 0(0x1e1268), 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법: 07 `src/bsd/dev/SCSIDiskKern.m` = D030 머리 + Darwin 본문(고지 없음) + 위 수정(각 자리 plan 328 표시) → iter_objc_abs(ABSROOT) → relcheck → zerofill → record_objc, 근거 diff 는 D030 관례대로 /dev/null 대비.

### codex 교차검토 판정(2026-10-06, plan 328; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·범위 3610 B·앞 `00`×3·뒤 `00`×2·12 함수 크기·0x44·문자열·`__data` 276 B | 앞서 python(l1 json 집계, img.rd 앞뒤 바이트)·odis3 | ✅ |
| ①–⑧ 원본 명령 주소(0x1834d8–0x183513, 0x1840de `jbe`, 0x183a22 `cmp ecx,0x10; jg`, 0x183a2b–0x183a38, 0x183bfb·0x183c27, 0x183cf1–0x183d10) | 앞서 orig.dis 를 읽고 수정·진단 `j1` 차이 0 | ✅ |
| ⑨ 는 빌드만(바이트 요구 아님) | 계획에 이미 "빌드만" | ✅ (새 사실 없음) |
| Darwin 의 쓰이지 않는 `int err;`(D:173) 삭제는 바이트 요구가 아님 | sed Darwin 170–176(`int err; int unit;`) | ✅ 채택 — sdopen 에 `int err; int unit;` 되돌림(미사용 지역은 -O3 코드에 영향 없음, 07 빌드로 확인) |
| GROK_APPLE 갈래(F:544)가 `part` 를 초기화 전에 씀 | sed final.m 518–522·542–546 | ⚖️ 사실이나 i386 에서 컴파일되지 않는 Darwin ppc 갈래 — 수정 없음 |
| `__bss` 588 B 참조 18, Delta 하나, [0x1e7324,0x1e7570) | zerofill_check(`s5p328-zerofill-check-SCSIDiskKern-20261006.json`): 참조 18, Delta 0x1e6178, 같은 범위 | ✅ |
| D030 맞음, 고지 문구 없음(bknight 주석은 고지 아님) | find(0)·mkfinal 검사 | ✅ |

### 결과(2026-10-06, plan 328)

- 07 `src/bsd/dev/SCSIDiskKern.m`(D030 머리 + Darwin 본문 + plan 328 수정 ①–⑨, sdopen 의 쓰이지 않는 `int err; int unit;` 은 Darwin 대로). `s5p328-it1`(ABSROOT): 12 함수 차이 0(MATCH 4·MATCH_UNVERIFIED 8), `__data` 276 B 차이 0, 사유 `__DATA,__bss: unverified` 하나. relcheck 0. zerofill 588 B [0x1e7324, 0x1e7570) 참조 추정(참조 18, Delta 0x1e6178, 음성 검사 검출) → **P**. 알려진 배치 59 개(`zerofill-known-s5p328-20261006.json`).
- 기록: record_objc — functions.tsv 3175→3187, objects_partial 56→57, PROVENANCE 811→812, MODIFICATIONS 329→330. 근거 `06_reconstruction/evidence/x86-SCSIDiskKern.md`·`.diff`.

## 329. S5-P319 세부 계획 — 커널 트리 `bsd/dev/SCSIGenericKern.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/SCSIGenericKern.m. NeXTMach·Mach4 에 같은 이름 없음(find 0) → D030.

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/SCSIGenericKern.m"(objc 0x208fbc, 클래스 0) `__text` [0x184178, 0x18494c) 2004 B(앞 `00` 2 B 는 SCSIDiskKern 뒤, 뒤 바로 _IOInitDDM), 5 함수(외부 sgopen·sgclose·sgioctl, 정적 sgDevToId 0x18447c·sg_doiocreq); `__data` 0x1e137c 33 B; `__bss` 4 B(`static int sg_major` — 쓰이지 않음, 참조 0).
1. 원본과 Darwin 의 차이(odis3·fdis): ① sgioctl `cmd` 는 int(원본 case 비교 jg/jl); ② SGIOCSTL·SGIOCSTL3 의 `isRoot:` 는 4.2 `suser()`(인자 없음, 원본 0x1842cc·0x184318 `call _suser; movsx edx,al`); ③ SGIOCRST: `if (!suser())` 이면 `rtn = u.u_error`(원본 0x184434–0x184447, `_active_u+0x4` 의 +0x68 바이트).
2. 진단: `s5p330-a1`(p_ucred 빌드 실패)…`c1` → 5 함수 MATCH, `__data` 33 B 차이 0, 사유 `__DATA,__bss: unverified` 하나. `__bss` 는 참조 0 이라 zerofill 은 참조 추정이 아니라 "unreferenced"(bios·intr 선례 P) — record_objc 가 받는지 기록 때 확인.
3. 방법: 07 `src/bsd/dev/SCSIGenericKern.m` = D030 머리 + Darwin 본문 + 위 수정(plan 329 표시) → iter_objc_abs → relcheck → zerofill → 기록.

## 330. S5-P320 세부 계획 — 커널 트리 `bsd/dev/i386/EventSrcPCKeyboard.m`(D024·D027·D030·D032·D033; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/EventSrcPCKeyboard.m·EventSrcPCKeyboard.h·PCKeymap.c. NeXTMach·Mach4 에 같은 이름 없음(find 0) → D030, PCKeymap.c·머리는 D032 사본.

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/i386/EventSrcPCKeyboard.m"(objc 0x20901c, 클래스 1) `__text` [0x19f0a0, 0x1a00e1) 4161 B(앞 `00` 3 B, 뒤 `00` 3 B → EventSrcPCPointer 0x1a00e4), 28 함수(메서드 27, 정적 autoRepeatCallout); `__TEXT,__const` 0x1d554a 882 B(PCDefaultKeymap, Darwin PCKeymap.c 와 바이트 같음); `__data` 0x1e488c 301 B.
1. 원본과 Darwin 의 차이: ① canBecomeOwner: 끝 `return drtn` 없음(원본 0x19f71f 앞에서 eax 를 다시 넣지 않음; IOLog 갈래는 IOLog 의 값); ② relinquishOwnership: 자동 반복 중지·수식키 초기화(downRepeatTime·codeToRepeat·scheduleAutoRepeat·updateEventFlags:·deviceDependentFlags·eventFlags) 없음(원본 0x19ff48 첫 호출이 super relinquishOwnership:); ③ getIntValues: EVSIOGKEYS 갈래 없음(4.2 SDK evsio.h 에 정의 없음).
2. 진단: `s5p331-a1`(PCKeymap.c 미스테이징)·`b1`(EVSIOGKEYS)·`c1`(크기 차이 둘) → `d1` **OBJECT_MATCH**(29 MATCH).
3. 방법: 07 `src/bsd/dev/i386/EventSrcPCKeyboard.m` = D030 머리 + Darwin 본문 + 위 수정(plan 330 표시); D032 사본 `nextdev_private/bsd/dev/i386/PCKeymap.c`·필요한 머리(EventSrcPCKeyboard.h 등, 07 빌드에서 확인) → iter_objc_abs → relcheck → 기록(A).

### codex 교차검토 판정(2026-10-06, plans 329·330; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 329·330 의 범위·크기·채움·함수 목록·`__data`·`__TEXT,__const` 0x1d554a 882 B·다음 모듈 0x1a00e4 | 앞서 python(l1 json 집계, img.rd 앞뒤 바이트)·objc.json | ✅ |
| sgioctl 부호 있는 비교·`suser()` 결과 직접 전달(0x1842cc·0x184318 `movsx edx,al`)·SGIOCRST `_active_u+4` 의 +0x68 | 앞서 orig.dis grep(-B3 -A6) | ✅ |
| canBecomeOwner: eax 를 다시 넣지 않음; 타입 문자열 `i12@8:12@16`(int 반환) | 앞서 odis3 0x19f6b8–0x19f728; 진단 `d1` OBJECT_MATCH(메서드 타입 문자열 포함) | ✅ |
| EVSIOGKEYS 갈래·relinquishOwnership: 앞부분 없음(첫 호출 0x19ff6e 가 objc_msgSendSuper) | 앞서 odis3 0x19ff48–0x19fff8 | ✅ |
| PCDefaultKeymap 882 B 가 Darwin PCKeymap.c 와 같음 | 진단 `d1` 의 `__TEXT,__const` 차이 0 | ✅ |
| sg_major 4 B: 원본 텍스트에 원본 `__bss` 참조 0 — 원본 배치·소속은 확인 안 됨 | 진단 `c1` 의 함수 data_sections 에 `__bss` 없음 | ✅ 채택 — 329 의 `__bss` 를 "참조 0, 원본 배치 미확인"으로 기록 |
| D030 맞음(같은 이름 없음), 고지 문구 없음 | find(0)·mkfinal 검사 | ✅ |

### 결과(2026-10-06, plans 329·330)

- plan 329: 07 `src/bsd/dev/SCSIGenericKern.m`(D030, plan 329 수정 ①–③). `s5p329-it1`(ABSROOT): 5 함수 MATCH, `__data` 33 B 차이 0, 사유 `__DATA,__bss: unverified` 하나. relcheck 0. zerofill: 참조 0(결론 fail, records 없음) → `__bss` 4 B(sg_major)는 참조 없음·원본 배치 미확인으로 **P**(bios 선례). 기록 도구 record_objc(scratchpad)에 record_partial 과 같은 `bss_unreferenced` 경로를 더함(zerofill 결론 fail·참조 0·records 없음일 때만). 기록: functions.tsv 3215→3220, objects_partial 57→58, PROVENANCE 815→816, MODIFICATIONS 333→334.
- plan 330: 07 `src/bsd/dev/i386/EventSrcPCKeyboard.m`(D030, plan 330 수정 ①–③)과 D032 사본 `nextdev_private/bsd/dev/i386/EventSrcPCKeyboard.h`·`PCKeymap.c`. `s5p330-it1`(ABSROOT): **OBJECT_MATCH**(29 MATCH, `__TEXT,__const` 882 B·`__data` 301 B 포함), relcheck 0 → **A**. 기록: functions.tsv 3187→3215, objects_confirmed 244→245, PROVENANCE 812→813→815(사본 둘), MODIFICATIONS 330→331→333.

## 331. S5-P321 세부 계획 — 커널 트리 `bsd/dev/i386/PCPointer.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/PCPointer.m. NeXTMach·Mach4 에 같은 이름 없음(find 0) → D030. `machdep/i386/features.h` 는 어느 트리에도 없음(find: features.h 는 07 mach·nextmach sys, Darwin mach·machdep/machine 뿐).

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/i386/PCPointer.m"(objc 0x20903c, 클래스 1) `__text` [0x1a0ac8, 0x1a0d49) 641 B(앞 `00` 1 B, 뒤 `00` 3 B), 9 함수(PCPatoi + 메서드 8); `__data` 0x1e4ad2 164 B(L1d); `__bss` 8 B.
1. Darwin 과의 차이: 코드 차이 없음. 빌드만 — Darwin 의 `#undef KERNEL_BUILD` 를 뺌: 있으면 mach/features.h 가 machdep/machine/features.h → machdep/i386/features.h(없음)로 가서 `s5p332-a1` 실패. 빼면 meta_features.h 를 씀(SCSIDiskThread plan 318 의 `#undef KERNEL_PRIVATE` 제거와 같은 빌드 전용 처리).
2. 진단: `s5p332-a1`(features.h)…`b1` → 9 함수 바이트 차이 0(MATCH 7·MATCH_UNVERIFIED 2), `__data` 164 B 차이 0, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법: 07 `src/bsd/dev/i386/PCPointer.m` = D030 머리 + Darwin 본문 + 위 빌드 전용 수정(plan 331 표시) → iter_objc_abs → relcheck → zerofill → 기록.

## 332. S5-P322 세부 계획 — 커널 트리 `driverkit/autoconfCommon.m`(D024·D027·D030·D033; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/driverkit/autoconfCommon.m·autoconfCommon.h. NeXTMach·Mach4 에 같은 이름 없음(find) → D030. 4.2 쪽 이름은 07 의 것: `kernel_proc`(07 bsd/kern/kern_proc.c:56), `rootcred`(07 bsd/kern/kern_prot.c:480), `IOTaskGetPort`(07 src/driverkit/libDriver/Kernel/generalFuncsPrivate.m:203), `u_cred_lock_init`·`uu_cred_lock`(07 nextdev bsd/sys/user.h:135–138, 07 kern_fork.c:365 과 같은 꼴).

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/driverkit/autoconfCommon.m"(objc 0x208f1c, 클래스 0) `__text` [0x17e234, 0x17e70a) 1238 B(앞 `00` 3 B, 뒤 `00` 2 B → _KernLockAcquire 0x17e70c), 16 함수(외부 12 + 정적 IOTaskInit 0x17e2e0·autoconfInt 0x17e4e8·registerIndirClasses 0x17e538·probePseudoDevices 0x17e58c; _io_sendPowerMessage 는 인라인; `_io_vm_task_buf` 없음); `__data` 0x1e0f49 127 B(L1d); `__bss` 4 B(autoconfLock, 0x1e7314 참조).
1. 원본과 Darwin 의 차이(odis3·fdis): ① IOTaskInit: `proc = kernel_proc` 를 kernel_vm_space 앞에(원본 0x17e348–0x17e351), 이어 `u_cred_lock_init(&u_address->uu_cred_lock)`(lock_init(+0x38→+0x20, 1), 0x17e358–0x17e361)·`uu_cred = rootcred`(+0x1c)·`uu_procp = kernel_proc`(+0); `IOTask = IOTaskGetPort(itk_sself)`(+0x6c, call 0x17e398 → 0x1a9264). ② `_io_vm_task_buf` 없음(원본 기호 없음, 0x17e3a8 이 _io_vm_task_self). ③ _io_sendPowerMessage: `IOObjectNumber i` 초기화 없음(원본 0x17e5f8 뒤 `xor ebx,ebx` 대신 루프 정렬 `90 90`, 0x17e67c 쪽도 같음).
2. 진단: `s5p333-a1`(kernproc)…`c1` → 16 함수 바이트 차이 0(MATCH 14·MATCH_UNVERIFIED 2), `__data` 127 B 차이 0, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법: 07 `src/driverkit/autoconfCommon.m` = D030 머리 + Darwin 본문 + 위 수정(plan 332 표시) → iter_objc_abs → relcheck → zerofill → 기록.

### codex 교차검토 판정(2026-10-06, plans 331·332; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| plan 332 함수 수는 외부 12 + 정적 4 = 16(계획의 "외부 13" 은 틀림) | python(s5p333-c.json 이름 16, 정적 넷 뺀 12) | ✅ 채택 — 계획 고침(내 오기) |
| PCPointer 주석 "either way" 근거 없음(`#undef` 판은 빌드 실패) | s5p332-a1 실패 로그 | ✅ 채택 — 주석을 "그 빌드는 실패, 빼면 맞음"으로 고침 |
| 두 모듈 범위·채움·`__data`·`__bss`(PCPointer 8 B: nextUnit·activePointerDevice; autoconfCommon 4 B 0x1e7314) | 앞서 python(l1 json, img.rd), orig.dis 0x17e284 | ✅ |
| IOTaskInit 원본 명령(0x17e348–0x17e398)·task/utask 오프셋(task.h:96·97·109·120, user.h:118·127·135) | 앞서 fdis 맞대기·진단 `c1` 차이 0, task.h·user.h grep | ✅ |
| 전원 루프 두 곳 ebx 초기화 없음(0x17e5fe·0x17e68e `90 90`) | 앞서 img.rd 원시 바이트 | ✅ |
| `KERNEL_BUILD` 빼도 안전(-imacros meta_features.h 와 같은 선택), machdep/i386/features.h 없음 | features.h:49 읽음·find | ✅ |
| D030 맞음, 고지 문구 없음 | find·mkfinal 검사 | ✅ |

### 결과(2026-10-06, plans 331·332)

- plan 331: 07 `src/bsd/dev/i386/PCPointer.m`(D030, 빌드 전용 plan 331 한 곳). `s5p331-it1`(ABSROOT): 9 함수 차이 0(MATCH 7·MATCH_UNVERIFIED 2), `__data` 164 B 차이 0, 사유 `__bss` 하나. relcheck 0. zerofill 8 B [0x1e8660, 0x1e8668) 참조 추정(참조 4, Delta 0x1e7fb8, 음성 검사 검출) → **P**. 알려진 배치 60 개(`zerofill-known-s5p331-20261006.json`). 스테이징이 SDK `driverkit/machine/driverServer.h` 를 07 nextdev 에 그대로 들임(SDK 와 cmp 같음, PROVENANCE nextdev-os42 행). 기록: functions.tsv 3220→3229, objects_partial 58→59, PROVENANCE 816→817(SDK 머리)→818, MODIFICATIONS 334→335.
- plan 332: 07 `src/driverkit/autoconfCommon.m` 을 두었으나 첫 07 빌드 `s5p332-it1` 이 `dev/busvar.h` 없음으로 컴파일 실패(진단은 Darwin bsd/dev/busvar.h 를 직접 썼음). busvar.h 는 NeXTMach nextdev/busvar.h(m68k 버스 구조체 + `struct pseudo_init`)와 Darwin bsd/dev/busvar.h(`pseudo_init` 만) 둘 다 있고, stage_headers 의 NeXTMach 디렉터리(`NEXTMACH_DIRS`)에 `dev` 가 없음 → 머리 출처는 사용자 결정 필요(보류, 기록 없음).

### codex 교차검토 판정(2026-10-06, plan 333; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 2901 B·앞 채움 없음(0x181c97 `c3`)·뒤 `00`×3·0x1827f0 은 MIG 정적 루틴·21 함수·`__data` 0x1e109d 126 B | 앞서 python·img.rd(`89ec5dc3` / `0000005589e5`)·symbols(0x182a0c _driverServer_server)·진단 `d1` | ✅ |
| 키 문자열 넷이 원본 `__data` 에 있고 모두 쓰임 | 진단 `d1` `__data` 126 B 차이 0, OBJECT_MATCH | ✅ |
| 빠진 다섯 함수는 원본 기호 없음 | 앞서 msizes(`orig ?`) | ✅ |
| `__bss` 절 없음; sys/buf.h COMMON 선언 10 개는 이 비교로 검증 안 됨 | — (행동 바뀌지 않음, 근거 문서에 단서로 적음) | ⚖️ |
| EISAKernBus.h·같은 이름 파일 없음, 고지 없음 | find·mkfinal 검사 | ✅ |

### 결과(2026-10-06, plan 333)

- 07 `src/driverkit/driverServerXXX.m`(D030, plan 333 수정 ①②). `s5p333-it1`(ABSROOT): **OBJECT_MATCH**(21 MATCH), relcheck 0 → **A**. codex 단서: `__bss` 절은 없고 sys/buf.h 의 COMMON 선언 10 개(텍스트 참조 없음)는 이 비교로 검증되지 않음 — 근거 문서에 적음. 기록: functions.tsv 3229→3250, objects_confirmed 245→246, PROVENANCE 818→819, MODIFICATIONS 335→336.

## 333. S5-P323 세부 계획 — 커널 트리 `driverkit/driverServerXXX.m`(D024·D027·D030·D033, D035 와 같은 지역 정의; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/driverkit/driverServerXXX.m·.h. NeXTMach·Mach4 에 같은 이름 없음(find) → D030. `driverkit/i386/EISAKernBus.h` 는 어느 트리에도 없음(find 0; plan 325 와 같음).

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/driverkit/driverServerXXX.m"(objc 0x208f9c, 클래스 0) `__text` [0x181c98, 0x1827ed) 2901 B(앞 채움 없음 — 0x181c97 `c3`, 뒤 `00` 3 B → 0x1827f0 은 다음 MIG 모듈의 정적 루틴, _driverServer_server 0x182a0c), 21 함수(dev_server_init … kern_IOMapDeviceMemory); `__data` 0x1e109d 126 B(L1d); `__bss` 없음.
1. 원본과 Darwin 의 차이: ① `#import <driverkit/i386/EISAKernBus.h>` 대신 이 파일이 쓰는 자원 키 넷(IO_PORTS_KEY "I/O Ports"·MEM_MAPS_KEY "Memory Maps"·IRQ_LEVELS_KEY "IRQ Levels"·DMA_CHANNELS_KEY "DMA Channels")을 파일 안에 정의 — 값은 Darwin ppc/PPCKernBus.h:56–59 와 같고 원본 `__data` 문자열과 바이트로 맞음(kernBootStruct 의 D035 와 같은 "파일마다 지역 정의"). ② Darwin 전용 kern_IOLookUpByStringPropertyList·kern_IOGetStringPropertyList·kern_IOGetByteProperty·kern_IOServerConnect·kern_IOCallDeviceMethod 없음(원본 기호 없음; kern_IOSetCharValues 0x181eb0 다음이 kern_IOGetEISADeviceConfig 0x181eec).
2. 진단: `s5p334-a1`(EISAKernBus.h)·`b1`(키 미정의)·`c1`(함수 5 개 남음) → `d1` **OBJECT_MATCH**(21 MATCH).
3. 방법: 07 `src/driverkit/driverServerXXX.m` = D030 머리 + Darwin 본문 + 위 수정(plan 333 표시) → iter_objc_abs → relcheck → 기록(A).

## 334. S5-P324 세부 계획 — 커널 트리 `bsd/dev/vol.c`(D013·D029·D036·D038; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/vol.c(바탕), NeXTMach mk-108.1 nextdev/vol.c(옛 Mach IPC 판 — `s5p336-b` 에서 mach_ipc_xxxhack.h·nextdev/*.h 없음으로 컴파일 불가). 사용자 결정 D038(D036 처럼).

0. 원본(python·l1_compare): C 객체(ObjC 모듈 아님) `__text` [0x184bb8, 0x185a8c) 3796 B(앞 `00` 2 B — 0x184bb5 `c3` 뒤, 뒤 채움 없음 → _kdp_getstate 0x185a8c), 16 함수(volopen·volclose·volioctl·vol_notify_dev·vol_notify_com·vol_notify_cancel·vol_panel_request·vol_panel_remove·vol_panel_disk_num·vol_panel_disk_label·vol_panel_get_entry·vol_port_death·vol_start_thread·vol_check_manual_poll·vol_check_set_poll·vol_thread; vol_notify_port 는 객체에 없음); `__data` 0x1e13ec 810 B; `__bss` 24 B(진단 추정 0x1e7588). objects.tsv 233 의 "volDriver.m" 후보는 틀림(이 구간 전체가 vol.c).
1. 원본과 Darwin 의 차이: 없음 — 진단 `s5p336-d7`(Darwin 원문 그대로, NeXTMach 스테이징 덮어쓰기 + 빠진 머리 덮어쓰기)에서 16 함수 바이트 차이 0(MATCH 5·MATCH_UNVERIFIED 11), `__data` 810 B 차이 0, 사유 `__DATA,__bss: unverified` 하나.
2. 방법(D038): 07 `src/bsd/dev/vol.c` = Darwin 0.1 원문 그대로(Apple·NeXT 고지 유지) → iter.py(커널 C 꼴, 07 스테이징; 진단에서 덮어쓴 머리가 07 규칙으로 풀리는지 확인) → relcheck → zerofill → 기록(PROVENANCE darwin01, D029/D036/D038), 근거 diff 는 Darwin 원문 대비.

### codex 교차검토 판정(2026-10-06, plans 334·335; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 334 범위·채움(앞 `00`×2, 뒤는 객체 안 `90`)·16 함수·`__data` 810 B·`__bss` 24 B(배치는 추정) | 앞서 python(l1 json, img.rd `5dc30000`/`5589e5…`) | ✅ |
| vol_notify_port 는 `#if SUPPORT_PORT_DEVICE`(vol.c:394), insertmsg.h:21 에서 0 | sed vol.c 394·insertmsg.h 21 | ✅ |
| 진단 실패 run 은 `s5p336-b`(내 계획 "b1" 은 틀림) | ls 08_build/runs, REGISTRY | ✅ 채택 — 계획 고침 |
| NeXTMach vol.c 는 port_alloc·kernel_thread_noblock 을 쓰고 원본은 ipc_port_alloc·kernel_thread(Darwin 과 같음) | — 사실 확인만 하지 않음, D038 근거 보강(행동 같음) | ⏭️ |
| objects.tsv 의 volDriver.m 후보는 틀림 | 진단 d7 이 이 구간 전체를 vol.c 로 맞춤 | ✅ (objects.tsv 는 옛 목록이라 고치지 않음) |
| 07 스테이징은 sys/callout.h 를 07 nextmach 판으로 풂(진단은 SDK 판) → 실제 07 빌드로 확인 | python bsd_pick('sys/callout.h', True) = nextmach07 | ✅ — 07 빌드로 확인 |
| 335 설계가 dev/busvar.h 를 풀고 검증 경로를 그대로 탐; `dev/m68k/autoconf.h` 는 이미 sdk07 → "다른 dev/* 는 None" 문구 틀림 | python bsd_pick 두 이름 | ✅ 채택 — 문구 고침 |
| NeXTMach busvar.h 는 이 소비자에서 컴파일됨(진단 s5p337-a1 성공) | 진단 a1 결과 | ✅ |
| 시험이 부족(실제 스테이징 바이트·manifest·불일치 거부·not_adopted) | 계획 3 을 읽음 | ✅ 채택 — 시험 (d)–(f) 추가 |

### 결과(2026-10-06, plan 334)

- 07 `src/bsd/dev/vol.c` = Darwin 0.1 원문 그대로(cmp 같음, 고지 유지, D038). `s5p334-it1`(07 스테이징 — sys/callout.h 는 07 nextmach 판): 16 함수 차이 0(MATCH 5·MATCH_UNVERIFIED 11), `__data` 810 B 차이 0, 사유 `__bss` 하나. relcheck 0. zerofill 24 B [0x1e7588, 0x1e75a0) 참조 추정(참조 28, Delta 0x1e6388, 음성 검사 검출) → **P**. 알려진 배치 61 개(`zerofill-known-s5p334-20261006.json`). 기록(record_partial, darwin01): functions.tsv 3250→3266, objects_partial 59→60, PROVENANCE 819→820, MODIFICATIONS 336→337.

## 335. S5-P325 세부 계획 — `dev/busvar.h` 를 NeXTMach 판으로(D039) + autoconfCommon 마무리(plan 332; 코딩 전, 2026-10-06)

1. 사실: autoconfCommon.m 은 `#import <dev/busvar.h>` 에서 `struct pseudo_init`·`pseudo_inits[]` 만 씀. NeXTMach mk-108.1 nextdev/busvar.h 는 m68k 버스 구조체 + 같은 `pseudo_init`(167–171 행); Darwin bsd/dev/busvar.h 는 `pseudo_init` 만. 진단 `s5p337-a1`(dev/busvar.h 를 NeXTMach 판으로 덮어씀): 16 함수 차이 0, 사유 `__bss` 하나 — Darwin 판 진단 `s5p333-c1` 과 같음. 07 빌드 `s5p332-it1` 은 stage_headers 가 `dev/busvar.h` 를 풀지 못해 실패(bsd_pick: `dev` 는 NEXTMACH_DIRS 에 없고 nextdev_private·SDK 에도 없음).
2. 도구(10_tools/reconstruction/stage_headers.py, plan 335·D039 표시): `NEXTMACH_RENAME = {'dev/busvar.h': 'nextdev/busvar.h'}` — bsd_pick 이 NEXTMACH_DIRS 갈래 다음에 이 표의 이름이면 `07_kernel/nextmach/nextdev/busvar.h`(prefer-07, kind nextmach07) 또는 NeXTMach `mk-108.1/nextdev/busvar.h`(kind nextmach)를 돌려줌; 돌려주는 출처 경로는 `nextdev/busvar.h` 라 기존 verify_nextmach(고정 커밋 blob 대조)·07 사본 대조가 그대로 적용. 다른 이름은 지금 동작 그대로(예: `dev/m68k/autoconf.h` 는 지금처럼 sdk07); 새 갈래는 기존 private·SDK·NEXTMACH_DIRS 갈래 뒤.
3. 시험: 10_tools/reconstruction/test_stage_headers_rename.py — (a) bsd_pick('dev/busvar.h') → kind nextmach, 출처 nextdev/busvar.h, 파일이 NeXTMach 원본; (b) prefer07 이고 07 사본이 있으면 nextmach07; (c) bsd_pick('dev/nosuch.h') → None, bsd_pick('dev/m68k/autoconf.h', True) 는 지금처럼 sdk07; (d) 실제 스테이징(임시 디렉터리)에서 `src/bsd/dev/busvar.h` 바이트가 NeXTMach 원본과 같고 manifest 출처가 NeXTMach 고정 커밋; (e) 07 사본이 원본과 다르면(임시 복사본으로 흉내) 스테이징 거부; (f) 07 사본이 없으면 bsd_not_adopted 에 들어가고, 있으면 들어가지 않음; (g) 기존 test_stage_headers_subst.py 통과(임시 디렉터리에만 씀).
4. 들임: NeXTMach nextdev/busvar.h 원문을 `07_kernel/nextmach/nextdev/busvar.h` 에 그대로(verify_nextmach 로 blob 대조, SHA-256), PROVENANCE 행 kind nextmach(D013·D039, 고지는 파일 안), MODIFICATIONS 행.
5. autoconfCommon: 07 파일은 그대로(plan 332), `s5p332-it2`(ABSROOT) → relcheck → zerofill → record_objc(P 예상).

### 결과(2026-10-06, plan 335)

- stage_headers.py: `NEXTMACH_RENAME`(dev/busvar.h → nextdev/busvar.h)와 bsd_pick 의 새 갈래(기존 갈래 뒤), plan 335·D039 표시(607→617 행). 시험 `test_stage_headers_rename.py` 10 개 통과(선택 a–c2, 임시 디렉터리 실제 스테이징 d1–d3·f1, 구성요소 수준 불일치 e·사본 없음 f2 — e 는 스테이징 본체가 아니라 그 본체가 쓰는 bsd_pick·verify_nextmach 로 확인), 기존 test_stage_headers_subst.py 19 개 통과, 저장소에 남은 파일 없음(git status).
- 들임: `07_kernel/nextmach/nextdev/busvar.h` = NeXTMach 고정 커밋 blob 과 같음(verify_nextmach, SHA-256 09f1f0b8…), PROVENANCE 820→821, MODIFICATIONS 337→338.
- autoconfCommon(plan 332): `s5p332-it2`(ABSROOT; manifest 의 src/bsd/dev/busvar.h 출처 = 07 nextmach 사본, NeXTMach 커밋 대조): 16 함수 차이 0(MATCH 14·MATCH_UNVERIFIED 2), `__data` 127 B 차이 0, 사유 `__bss` 하나. relcheck 0. zerofill 4 B [0x1e7314, 0x1e7318) 참조 추정(참조 5, Delta 0x1e6bd0, 음성 검사 검출) → **P**. 알려진 배치 62 개(`zerofill-known-s5p332-20261006.json`). 기록: functions.tsv 3266→3282, objects_partial 60→61, PROVENANCE 821→822, MODIFICATIONS 338→339.

## 336. S5-P326 세부 계획 — 커널 트리 `bsd/dev/i386/kmGraphics.m`(D024·D027·D030·D032·D033·D040; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/kmGraphics.m·NSPanel.h·TimesItalic14.h·kmFontPriv.h(ppc 판은 쓰지 않음). NeXTMach·Mach4 에 같은 이름 없음(find) → .m 은 D030; 패널·글꼴 데이터는 사용자 결정 D040(원본 바이트로 작성).

0. 원본(python·l1_compare): 모듈 "/BinarySourceCache_Mario1A/mk/mk-183.34.4/bsd/dev/i386/kmGraphics.m"(objc 0x20900c, 카테고리 KmGraphics 하나) `__text` [0x1975d0, 0x197985) 949 B(앞 `00` 3 B, 뒤 `00` 3 B → _kmLocalizeString 0x197988), 메서드 2(graphicPanelString: 840 B, drawGraphicPanel: 109 B; eraserect·blit_bm·image_bitmap 은 인라인); `__TEXT,__const` [0x1d1648, 0x1d54dc) 16020 B = NSPanel 13728 B(312×176, 2 bpp) + bits_array 736 B(0x1d4be8) + Times_Italic_14 1556 B(0x1d4ec8; 이름 "Times-Italic-14", size 14, bbx {17,15,-3,-4}, 96 항목 × 16 B, bits 포인터 0x1d4be8); `__data` 0x1e3e7c 24 B; `__bss` 3781 B(진단 객체의 크기 — kmTextBitmap 3744 B = 288×52×2/8 + 정적 int 9·char 1; 원본 배치는 참조 추정, 0x1e7780 부터).
1. 원본과 Darwin 의 차이: ① NSPanel.h: 패널 312×176(Darwin 352×264; drawGraphicPanel 0x19792a–0x197964 의 상수 0x138·0xb0·0xa4·0x98 = 312·176·(640−312)/2·(480−176)/2), 텍스트 원점 TEXT_X 12·TEXT_Y 62(image_bitmap 0x1978e1 `add ax,0xc`·0x1978f0 `add dx,0x3e`), 텍스트 크기 W = WIDTH−2·TEXT_X = 288·H = HEIGHT−2·TEXT_Y = 52(graphicPanelString 0x1975ff·0x197609 상수 0x120·0x34), 패널 배열 13728 B 는 원본 0x1d1648 바이트 그대로; TEXTBASELINE 없음(쓰이지 않음). ② TimesItalic14.h: 원본의 bits_array 736 B·Times_Italic_14 구조체 값(이름·크기·bbx·96 항목)을 그대로(Darwin 은 "Charcoal-12" 다른 글꼴). ③ kmGraphics.m: TEXT_COLOR = KM_COLOR_BLACK(3; blit_bm 인라인 0x1977cc `mov [ebp-0x28],3`); 정적 `panel_width, panel_height`(bss 0x1e8620·0x1e8624, text_width 앞)에 drawGraphicPanel 이 패널 크기를 저장; graphicPanelString 의 ypos 는 세로 가운데 `YMARGIN + (text_height − (lines − 1) * deflead) / 2`(0x197697–0x1976b5; Darwin 은 TEXTBASELINE).
2. 진단(머리 덮어쓰기, 진단 `# 1`, KEEPWS): `s5p335-a1`(Darwin 그대로: const·data·두 메서드 다름)…`e1` → 메서드 2·const 3 객체 바이트 차이 0(MATCH 3·MATCH_UNVERIFIED 2), `__data` 24 B 차이 0, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법: 07 `src/bsd/dev/i386/kmGraphics.m` = D030 머리 + Darwin 본문 + ③(plan 336 표시); `nextdev_private/bsd/dev/i386/NSPanel.h`·`TimesItalic14.h` = 프로젝트 작성(D024·D040, 원본 바이트에서 python 으로 만든 배열, 머리에 원본 주소·크기·공개 판단은 사용자 D017); `kmFontPriv.h` = D032 사본(Darwin 본문, 고지 없음) → iter_objc_abs → relcheck → zerofill → 기록.

### codex 교차검토 판정(2026-10-06, plan 336; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·범위 949 B(840+109)·앞뒤 `00`×3·const 16020 B(13728+736+1556)·`__data` 24 B | 앞서 python(l1 json, img.rd) | ✅ |
| NSPanel 13728 B·bits_array 736 B·Times_Italic_14 96 항목이 원본 바이트와 같음 | python: 헤더 배열을 다시 읽어 img.rd 와 비교(panel True, bits True, 96 항목 True) | ✅ |
| 코드 수정(색 3, 패널 312×176·164×152, panel_width/height 순서, TEXT_X/Y 12/62, W/H 288/52, ypos 식)이 원본 명령과 맞음 | 앞서 fdis·odis3 맞대기, 진단 e1 차이 0 | ✅ |
| TEXTBASELINE 빼도 안전 | grep body.m(쓰는 곳 없음) | ✅ |
| `__bss` 3781 B 는 진단 객체 크기, 원본 소속은 참조 추정 | 계획 문구 | ✅ 채택 — 문구 고침 |
| D030/D040/D032 분류, 고지 없음 | find·grep | ✅ |

### 결과(2026-10-06, plan 336 — 기록 보류)

- 07 `src/bsd/dev/i386/kmGraphics.m`(D030 + plan 336 ③), `nextdev_private/bsd/dev/i386/NSPanel.h`·`TimesItalic14.h`(D024·D040, 원본 바이트), `kmFontPriv.h`(D032) 를 둠. 스테이징 manifest: 세 머리 모두 07 nextdev_private 에서. `s5p336-it1`(ABSROOT): 메서드 2 + const 3 차이 0(MATCH 3·MATCH_UNVERIFIED 2), `__data` 24 B 차이 0(배치 "inferred, verified by L1d"), 사유 `__bss` 하나. relcheck 0.
- zerofill(`--place-from-l1`): 참조 33, Delta 0x1e3430 하나, 음성 검사 검출이지만 **결론 fail** — `__data` 의 `fb`(kmTextBitmap 포인터)가 bss 를 가리키는데 `__data` 배치가 L1d 추정이라 plan 302 규칙(“inferred, verified by L1d” 는 쓰지 않음)으로 Δ 를 얻지 못함("referring section __data has no symbol placement"). 규칙을 넓히는 것은 plan 302 의 검증 기준을 바꾸는 일이라 사용자 결정 필요 → 기록하지 않음(functions·objects·PROVENANCE·MODIFICATIONS 행 없음).

## 337. S5-P327 세부 계획 — 커널 트리 `bsd/dev/i386/BasicConsole.c`(D024·D027·D030·D035; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/BasicConsole.c. NeXTMach·Mach4 에 같은 이름 없음(find 0) → D030.

0. 원본(python·l1_compare): C 객체 `__text` [0x1979e4, 0x197ca0) 700 B(앞 채움 없음 — 0x1979e3 `c3`(kmLocalized 쪽), 뒤도 없음 → 0x197ca0 다음 객체), 함수 2(VGASetGraphicsMode 628 B, BasicAllocateConsole 72 B); `__TEXT,__const` 0x1d54dc 110 B(miscOutData·sequencerData·crtData·attrData·gfxData·paletteVals, L1d); `__bss` 12 B(진단 추정 0x1e8648).
1. Darwin 과의 차이: ① D035 — kernBootStruct.h 대신 지역 정의(BasicAllocateConsole 이 포인터만 선언, 칸은 쓰지 않음 — 구조체는 자리만); ② BasicAllocateConsole: 4.2 판은 `FBAllocateVBEConsole()` 을 먼저 부르고 0 이면 640×480 IODisplayInfo 로 VGAAllocateConsole(원본 0x197c62 call 0x19ecb8, 0x197c69 `jne` 로 그 값 반환, 0x197c7c·0x197c86 상수 0x280·0x1e0, 0x197c91 call 0x19b760; km.m kminit(plan 326)과 같은 순서); FBAllocateVBEConsole 선언은 Darwin 머리에 없어 파일 안 extern(빌드용). ③ `#import <bsd/i386/param.h>`(4.2 SDK 에 없음 — 첫 07 빌드 `s5p337-it1` 이 이 머리와 VGAConsole.h 없음으로 실패)를 4.2 SDK 의 `<bsd/i386/machparam.h>` 로 바꿈: 원본 VGASetGraphicsMode 는 `us_spin` 을 4 번 부르고(DELAY(10)), 그 매크로가 SDK machparam.h:51 에 있음. (처음 "빼도 같은 결과"라 적은 것은 틀림 — `s5p338-e1`·`s5p337-it2` 모두 `_DELAY not in image` 미확인 참조 4, relcheck 불일치 4.) VGAConsole.h 는 D032 사본.
2. 진단(chase_c, 머리 덮어쓰기): `s5p338-a`(kernBootStruct.h)·`b1`(BasicAllocateConsole 다름)·`c1`(NULL 미정의) → `d1` 함수 2·const 6 바이트 차이 0, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 방법: 07 `src/bsd/dev/i386/BasicConsole.c` = D030 머리 + Darwin 본문 + ①②(plan 337 표시) → iter.py(커널 C) → relcheck → zerofill → record_partial(authored).

### codex 교차검토 판정(2026-10-06, plan 337; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 700 B·앞뒤 채움 없음·함수 628(끝 `90` 포함)/72·const 6 배열 110 B | 앞서 python(l1 json, img.rd `89ec5dc3`/`89ec5dc35589e583`) | ✅ |
| BasicAllocateConsole 원본 명령(0x197c62·0x197c69·0x197c7c·0x197c86·0x197c91, bzero 0x88) | 앞서 odis3 0x197c58–0x197ca0 | ✅ |
| 0x197ca0 은 VGAConsole 의 정적 FlipCursor | VGAConsole 진단(bdiff FlipCursor 0x197ca0 차이 0) | ✅ |
| 자리 채움 멤버 4 B 는 크기의 근거가 아님 | final.c 주석 | ✅ 채택 — 주석에 "placeholder" 명시 |
| bss 셋 중 원본 참조는 첫째뿐 → P 는 zerofill 로 | zerofill: 참조 24 모두 오프셋 0, 결론 reference-inferred | ✅ (기록 문구에 "첫 4 B 만 참조" 명시) |
| D030·고지 없음 | find·mkfinal 검사 | ✅ |

### 결과(2026-10-06, plan 337)

- 07 `src/bsd/dev/i386/BasicConsole.c`(D030, plan 337 ①–③), D032 사본 `nextdev_private/bsd/dev/i386/VGAConsole.h`. 07 빌드: `s5p337-it1` 실패(bsd/i386/param.h·VGAConsole.h 미스테이징), `s5p337-it2`(param.h 뺌) 는 `_DELAY` 미확인 참조 4·relcheck 불일치 4 → ③ 을 SDK machparam.h 로 고쳐 `s5p337-it3`: 함수 2 차이 0, const 110 B 차이 0(L1d), 사유 `__bss` 하나, relcheck 0. zerofill 12 B [0x1e8648, 0x1e8654) 참조 추정(참조 24 — 모두 첫 4 B, Delta 0x1e831c, 음성 검사 검출) → **P**. 알려진 배치 63 개(`zerofill-known-s5p337-20261006.json`). 기록(record_partial, authored): functions.tsv 3282→3284, objects_partial 61→62, PROVENANCE 822→823→824(VGAConsole.h), MODIFICATIONS 339→340→341.

## 338. S5-P328 세부 계획 — 커널 트리 `bsd/dev/i386/VGAConsole.c`(D024·D027·D030·D032, ohlfs12.h 는 D013·D021·D039 방식; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/VGAConsole.c·VGAConsPriv.h·ohlfs12.h; NeXTMach mk-108.1 nextdev/ohlfs12.h(같은 글꼴 데이터 — Darwin 판에는 Apple/APSL 고지 블록·DRIVER_PRIVATE 가드·끝 주석이 더 있음). VGAConsole.c·VGAConsPriv.h 는 NeXTMach·Mach4 에 없음 → D030·D032.

0. 원본(python·l1_compare): C 객체 `__text` [0x197ca0, 0x19ba15) 15733 B(앞 채움 없음 — BasicConsole 끝 0x197c9f `c3`, 뒤 `00` 3 B → 0x19ba18), 16 함수(정적 FlipCursor·BltChar·FBPutC·SetTitle·InitWindow·Init·Restore·vga_write_bpp2packd32_to_bpp4planar·DrawRect(VGABlitRect 인라인), 외부 _VGAAllocateConsole 0x19b54c·SVGAAllocateConsole·VGAAllocateConsole, 정적 Free·EraseRect·PutC·GetSize); `__data` 0x1e41fc 1287 B(ohlfs12 글꼴 포함, 기호 배치); `__bss` 12 B(진단 추정 0x1e8654).
1. 원본과 Darwin 의 차이: ① Init: `console->window_type = mode` 를 화면 지우기 검사 **뒤**에(원본 0x19aca1 `cmp [edi],3` 이 이전 값을 보고, 0x19ada9 에서 저장). ② VGABlitRect(DrawRect 인라인): 채움 픽셀 0xaa·`0x02 <<`(원본 0x19b462 `or dl,0xaa`, 0x19b4cb `mov eax,2`; Darwin 0x55·0x01).
2. 진단(chase_c): `s5p339-a4`(Init 차이 — 정적 구간 28 B 김)·`b1`(DrawRect 2 B)·`c1` → 16 함수 바이트 차이 0(MATCH 6·MATCH_UNVERIFIED 10), `__data` 1287 B 차이 0, 사유 `__DATA,__bss: unverified` 하나 → zerofill 로 **P** 예상.
3. 머리: VGAConsPriv.h = D032 사본(Darwin 본문); ohlfs12.h 는 NeXTMach 판을 07 `nextmach/nextdev/ohlfs12.h` 에 그대로 들이고(verify_nextmach, D013), stage_headers `NEXTMACH_RENAME` 에 `dev/i386/ohlfs12.h → nextdev/ohlfs12.h` 한 줄 추가(plan 338, D039 와 같은 방식 — VGAConsPriv.h 가 `"ohlfs12.h"` 로 들임, 논리 경로 src/bsd/dev/i386/ohlfs12.h); test_stage_headers_rename.py 에 이 이름의 선택·스테이징 바이트 시험 추가.
4. 방법: 07 `src/bsd/dev/i386/VGAConsole.c` = D030 머리 + Darwin 본문 + ①②(plan 338 표시) → iter.py(커널 C) → relcheck → zerofill → record_partial(authored).

### codex 교차검토 판정(2026-10-06, plan 338; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 15733 B·뒤 `00`×3·16 함수 크기·`__data` 1287 B·bss 12 B(배치 추정) | 앞서 python(l1 json, img.rd) | ✅ |
| 두 수정의 원본 명령(0x19aca1 `cmp [edi],3`, 0x19ada9 저장, 0x19b462 `or dl,0xaa`, 0x19b4cb `mov eax,2`) | 앞서 odis3·fdis | ✅ |
| NeXTMach ohlfs12 1152 B 가 원본 `__data` 첫머리와 같음 | python: 배열을 읽어 img.rd(0x1e41fc) 에서 찾음 — 오프셋 0 | ✅ |
| Darwin ohlfs12.h 는 Apple/APSL 고지 블록도 있음(계획의 "가드·주석뿐"은 틀림) | head Darwin ohlfs12.h | ✅ 채택 — 계획 고침 |
| quoted include 는 포함 머리의 논리 디렉터리 기준이라 `dev/i386/ohlfs12.h` 로 bsd_pick 에 감 → 대응표로 풀림; 시험에 이 경로 포함 권고 | 07 빌드 `s5p338-it1` manifest: src/bsd/dev/i386/ohlfs12.h ← 07_kernel/nextmach/nextdev/ohlfs12.h(NeXTMach 커밋 대조), 미해결 0; 시험 a2·b2 추가 | ✅ |
| VGAConsole 은 param.h 불필요(DELAY 없음) | grep final.c — DELAY·us_spin 없음 | ✅ |
| D030·고지 없음 | find·mkfinal 검사 | ✅ |

### 결과(2026-10-06, plan 338)

- stage_headers `NEXTMACH_RENAME` 에 `dev/i386/ohlfs12.h → nextdev/ohlfs12.h`(plan 338) 추가, 시험 12 개 통과(a2·b2 추가). 들임: `07_kernel/nextmach/nextdev/ohlfs12.h`(NeXTMach blob 대조, SHA-256 475527fc…), D032 사본 `nextdev_private/bsd/dev/i386/VGAConsPriv.h`. 07 `src/bsd/dev/i386/VGAConsole.c`(D030, ①②). `s5p338-it1`: 16 함수 차이 0(MATCH 6·MATCH_UNVERIFIED 10), `__data` 1287 B 차이 0, 사유 `__bss` 하나, relcheck 0; 스테이징은 SDK displayRegisters.h·ascii_codes.h 를 07 nextdev 에 그대로 들임(nextdev-os42 행). zerofill 12 B [0x1e8654, 0x1e8660) 참조 추정(참조 264 — 모두 첫 4 B, Delta 0x1e43d8, 음성 검사 검출) → **P**. 알려진 배치 64 개. 기록: functions.tsv 3284→3300, objects_partial 62→63, PROVENANCE 824→826(머리 둘)→828(SDK 둘)→829, MODIFICATIONS 341→343→344.

## 339. S5-P329 세부 계획 — zerofill_check `--place-from-l1` 이 L1d 추정 배치를 받도록(D041) + kmGraphics 기록(plan 336; 코딩 전, 2026-10-06)

1. 사실: plan 302 는 `--place-from-l1` 에서 “inferred, verified by L1d” 배치를 쓰지 않음(zerofill_check.py:150 의 placement 조건, 시험 test_zerofill_l1place.py N3). l1_compare 의 이 배치는 이미 배치된 섹션의 참조가 모두 한 Δ 를 가리키고(`infer`, 후보 하나일 때만), 그 섹션의 모든 바이트·재배치가 맞을 때(sec_ok 'ok' = 바이트 차이 0·참조 차이 0·참조 미확인 0)만 붙음(l1_compare.py:264–276, 341–342). zero-fill 섹션은 추정의 출처로 쓰이지 않으므로(l1_compare.py:226) 이 Δ 가 bss 에서 나올 수 없음 — 다만 zero-fill 도 추정 **대상**은 되어 주소를 받고(244–246, 검증은 안 됨), `__data` 안 bss 포인터의 재배치 확인은 그 bss 추정 Δ 를 씀 → 서로 연관된 일관성 근거이지 bss 의 독립 증명이 아님(기록 문구에 적음; 처음 "l1 이 배치하지 않음" 이라 쓴 것은 틀림).
2. 도구(10_tools/reconstruction/zerofill_check.py, plan 339·D041 표시): usable 의 placement 조건에 “inferred, verified by L1d” 를 더함(다른 조건 — 같은 색인·크기·주소 있음·byte_differences 0·refs_differ 0·refs_unverified 0·zero-fill/cstring/리터럴 아님 — 그대로). 이 배치로 얻은 Δ 의 출처는 `l1-inferred`(기존 `l1` 과 구별). 기호 Δ 와 다르면 지금처럼 문제(fail).
3. 시험(test_zerofill_l1place.py): N3 을 D041 에 맞게 바꿈 — 추정 배치(다른 조건 충족)는 이제 쓰이고 출처 `l1-inferred`(양성); 새 음성 — 추정 배치인데 refs_unverified 1 → 안 씀, byte_differences 1 → 안 씀. (codex 권고 채택) 추가 음성 — refs_differ 1, 날 "inferred" 배치, 추정 배치의 Δ 가 기호 Δ 와 충돌(fail·symbol 출처 유지); 실제 회귀 — kmGraphics(`s5p336-it1`)로 참조 34·Δ 0x1e3430 하나·후보 [0x1e7780, 0x1e8645)·`__data` 출처 l1-inferred·음성 검사 검출. 나머지 양성·음성과 test_zerofill_conclude.py 그대로 통과.
4. kmGraphics: `s5p336-it1` 목적 파일·L1 으로 zerofill 다시(알려진 배치 64 개) → reference-inferred 면 record_objc(P), 알려진 배치 목록 늘림. plan 336 결과 절에 기록.

### codex 교차검토 판정(2026-10-06, plan 339; gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| L1d 표시 조건(후보 하나·sec_ok ok) 설명 맞음 | l1_compare.py 222–246·264–276·334–342 읽음 | ✅ |
| zero-fill 은 출처로는 안 쓰이나 대상으로는 배치됨(계획의 "배치하지 않음" 틀림); `__data` 의 fb 재배치 확인은 bss 추정 Δ 를 씀 → 일관성 근거 | sed l1_compare.py 244–246, kmGraphics L1 의 bss 'inferred' | ✅ 채택 — 계획·기록 문구 고침 |
| 바꾼 규칙으로 kmGraphics: 참조 34·Δ 0x1e3430·[0x1e7780,0x1e8645) | 내 scratch 시뮬레이션과 정식 실행 결과 같음 | ✅ |
| 다른 기록된 zerofill 결론은 다시 돌려도 바뀌지 않음(출처 기록만 늘 수 있음) | — 기록 파일은 고정, 행동 바뀌지 않음 | ⏭️ |
| 시험 보강(refs_differ·날 inferred·충돌·kmGraphics 회귀) | 시험에 N3c·N3d·N3e·P5 추가 | ✅ 채택 |

### 결과(2026-10-06, plans 339·336)

- zerofill_check.py: `--place-from-l1` 이 “inferred, verified by L1d” 배치도 받음(나머지 조건 그대로), 출처 `l1-inferred`(plan 339·D041 표시). test_zerofill_l1place.py 14 개 통과(N3 → P4 양성, N3a–N3e 음성, P5 kmGraphics 회귀; 인자의 알려진 배치 목록은 plan 302 당시 `zerofill-known-s5p289-20261004.json` — 최신 목록은 IOVPCodeDisplay 배치가 이미 있어 P2 가 겹침으로 실패하므로), test_zerofill_conclude.py 8 개 통과.
- kmGraphics(plan 336): zerofill 다시(`s5p336-zerofill-check-kmGraphics-20261006.json`; 이전 fail 결과는 scratchpad 로 옮김) → reference-inferred(참조 34, Δ 0x1e3430, [0x1e7780, 0x1e8645), 음성 검사 검출) → **P**. 알려진 배치 65 개(`zerofill-known-s5p339-20261006.json`). 기록: functions.tsv 3300→3302, objects_partial 63→64, PROVENANCE 829→830→833(머리 셋), MODIFICATIONS 344→345→348.

## 340. S5-P330 세부 계획 — 커널 트리 `bsd/dev/i386/kmLocalized.c`(D024·D027·D030; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 kernel/bsd/dev/i386/kmLocalized.m(ppc 판 있음, 쓰지 않음). NeXTMach·Mach4 에 같은 이름 없음(find) → D030.

0. 원본: C 객체 `__text` [0x197988, 0x1979e4) 92 B(kmLocalizeString 하나; 앞 `00` 3 B — 0x197984 `c3 00 00 00`, 뒤 채움 없음 → VGASetGraphicsMode 0x1979e4); `__data` 0x1e3e94 872 B(kmLocalizedStrings 표와 문자열, 기호 배치); bss 없음. objects.tsv 282 의 후보 이름은 kmLocalized.m 이지만 원본 objc.json 에 이 파일의 ObjC 모듈 기록이 없음(bsd/dev/i386 의 .m 모듈은 kmDevice·km·kmGraphics·EventSrcPCKeyboard·EventSrcPCPointer·PCPointer 뿐) → `.c` 로 둠(원본에 이 파일의 ObjC 모듈 기록이 없고, 본문에 ObjC 문법이 없으며, C 빌드가 맞음 — 원래 컴파일 언어는 추정; codex 지적으로 문구 고침).
1. Darwin 과의 차이: 본문 차이 없음. 07 파일 이름만 `.c`(위 근거; 본문에 ObjC 코드 없음).
2. 진단(chase_c, C 꼴): `s5p341-a5`(chase 반복의 마지막) **OBJECT_MATCH**(함수 1, `__data` 872 B = 표 140 B + 문자열 732 B).
3. 방법: 07 `src/bsd/dev/i386/kmLocalized.c` = D030 머리(“nearly the same as Darwin 0.1 kernel/bsd/dev/i386/kmLocalized.m”, C 로 둔 까닭 표시) + Darwin 본문 → iter.py → relcheck → record_object(A).

### codex 교차검토 판정·결과(2026-10-06, plan 340)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 92 B·앞 `00`×3·뒤 없음·`__data` 872 B(표 140 + 문자열 732)·bss 없음 | 앞서 python(img.rd `c3000000`/`5589e583`, l1 json); python 140+732=872 | ✅ |
| 진단 참조는 a1 이 아니라 a5 | ls 09_validation(`s5p341-a5` 만 있음) | ✅ 채택 — 계획 고침 |
| bsd/dev/i386 ObjC 모듈은 6 개뿐, kmLocalized 없음 | python objc.json(클래스 없는 .m 17 개도 기록 있음) | ✅ |
| "4.2 는 C 로 컴파일됨" 은 증명 아님 — 추정으로 적을 것 | 계획·머리 주석 | ✅ 채택 — 문구 고침 |
| 머리 주석만 다름, D030, 고지 없음 | diff·find·mkfinal 검사 | ✅ |

- 07 `src/bsd/dev/i386/kmLocalized.c`(D030). `s5p340-it1`: **OBJECT_MATCH**, relcheck 0 → **A**. 기록(record_object, authored): functions.tsv 3302→3303, objects_confirmed 246→247, PROVENANCE 833→834, MODIFICATIONS 348→349. 근거 문서의 앞 객체 문구를 바로잡음(0x197984 의 `c3` 은 kmGraphics drawGraphicPanel: 끝 — 처음 "km.m" 으로 잘못 적음).

## 341. 진행 메모 — 커널 트리 `bsd/dev/i386/FBConsole.c`(진단만, 07 아님; 2026-10-06)

- 원본 객체 [0x19ba18, 0x19f0a0) 추정: 정적 FlipCursor·Erase·BltChar·FBPutC·SetTitle·InitWindow·Init·DrawRect(0x19e23c, 1424 B)·EraseRect(0x19e7cc, 1112 B), 외부 FBAllocateConsole(0x19ec24)·FBAllocateVBEConsole(0x19ecb8, 212 B)·VBEModeInfo2IODisplayInfo(0x19ed8c, 540 B), 정적 Free·Restore·PutC·GetSize. FBAllocateVBEConsole·VBEModeInfo2IODisplayInfo 는 어느 참조 트리에도 없음(D024 작성 필요).
- 진단 `s5p340-a`…`i`(scratchpad `fbc/body.c`, Darwin 바탕)로 지금까지 맞춘 것: FBPutC 첫머리 `window_type == SCM_GRAPHIC` 이면 return; InitWindow save-under 의 `if (save)` 없음; Init 색 상수(8 비트 1-is-white 0x55/0xff/0/0x55/0xaa, 그 밖 0x63/0xef/0/0xf5/0xfa, 15 비트 0x295f/0x7bde/0/0x294a/0x5294, 24 비트 0xff5555ff/…/0xffaaaaaa)·화면 지우기 검사는 이전 window_type·TEXT 창은 디스플레이 3/4 크기·SCM_GRAPHIC 는 아무것도 안 함·ALERT 는 save-under 1 → FlipCursor…Init 7 함수 바이트 차이 0.
- 남은 것: DrawRect·EraseRect(원본은 pixelEncoding 으로 색 4 개 표를 만드는 정적 함수(panic 문구 "FBConsole/Fill: bogus bitsPerPixel" 공유, 2·8 비트는 정적 표 {3,2,1,0}·{0xff,0xf6,0xf2,0})를 인라인하고 VIDEO 640×480 기준 지역 x·y 로 그림 — 초안은 크기 1328/1072 대 원본 1424/1112, 프레임 0x4c 대 0x58), VBE 함수 둘, Restore(132 대 144). 시행착오가 길어 보류하고 다른 큰 구간을 먼저 봄.

## 342. S5-P331 세부 계획 — libDriver 오디오 9 모듈(`Kernel/IOAudio.m` 외 8; D024·D027·D030·D031·D032·D042·D043; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리 find): 9 소스와 지역 머리 16 개(AudioChannel·AudioCommand·AudioStream·InputStream·OutputStream·audioLog·audio_kern_server·audio_mix·audio_msgs·audio_mulaw·audio_peak·audio_server·audio_types·portFuncs·snd_reply·snd_server .h), driverkit/IOAudioPrivate.h, bsd/dev/audioTypes.h, audioReply.defs 는 Darwin 0.1 에만 있음 → D030/D032. bsd/dev/snd_msgs.h 는 NeXTMach mk-108.1/nextdev/snd_msgs.h 가 있으나 그대로는 컴파일 안 됨(`s5p344-snm1`: kern/mach_types.h·sys/message.h 없음), 07 `src/driverkit/snd_msgs.h`(plan 290 판)로는 snd_server 가 SND_STREAM_FORMAT_* 없음으로 실패(`s5p344-sn71`; audio_kern_server 는 그 판으로도 bss 만 미검증 `s5p344-ak71`) → 시험한 두 판으로는 부족(07 판을 더 늘릴 수 있는지는 증명하지 않음; 늘리면 원본이 요구하지 않는 저작이 되므로 Darwin 본문 사본을 둠), D032. 07 `src/driverkit/snd_msgs.h`(snd_reply.c 용, NeXTMach 고지 유지)는 그대로. SoundKit/NXSoundParameterTags.h 는 D042(실기 원본). SDK driverkit/IOAudio.h 는 실기 목록 판 그대로.

0. 원본(l1 json, python): `__text` 연속 [0x1b4a34, 0x1bd3e7) — IOAudio 11164 B(0x1b4a34) · AudioChannel 4037(0x1b75d0) · AudioStream 4207(0x1b8598) · InputStream 1612(0x1b9608) · OutputStream 3845(0x1b9c54) · AudioCommand 467(0x1bab5c) · audio_kern_server 1654(0x1bad30) · audio_server 4416(0x1bb3a8) · snd_server 3839(0x1bc4e8); 모듈 이름 "Kernel/<이름>.m"(D031, RUNIN). `__bss`: IOAudio 8 B, audio_kern_server 4 B(나머지 없음). python: `__text` 합 35241 B, 범위 35251 B(모듈 사이 채움 0·3·1·0·3·1·2·0 = 10 B), 9 객체 절 크기 합 53634 B(진단 l1 json).
1. 진단(scratchpad `aud/<모듈>/wip.m`, Darwin 본문 + 아래 수정, 머리는 ovr 대체, `EXTRA_DEFS=-DMACH_USER_API`(plan 307 꼴), `PUBLIC_SDK=kernserv/queue.h`): OBJECT_MATCH 7 — AudioChannel `s5p343-acq1`, AudioStream `asq1`, InputStream `inq1`, OutputStream `oux1`, AudioCommand `cmq1`, audio_server `svq1`, snd_server `snq1`; 사유 `__DATA,__bss: unverified` 하나 — IOAudio `ioq1`, audio_kern_server `akq1`.
2. 원본이 요구하는 본문 수정(Darwin 대비, plan 342 표시):
   ① IOAudio.m: `_is22KRateSupported` 호출(속도 44100 강제)과 그 메서드 없음; `NX_SoundDeviceInputGainLeft` 뒤 `break;` + `case NX_SoundDeviceInputGainRight: [self _setInputGainRight:]` 있음.
   ② OutputStream.m: `audio_resample22To44` 호출 6 곳 인자 4 개(channelCount 없음); CONV_SWAP|CONV_22_44 의 if/else 대신 `in_count /= 2;`; `kernReplyPort == PORT_NULL` 검사 없음.
   ③ Kernel/audio_mix.h: `audio_resample22To44` 원형 인자 4 개(②와 짝; 07 audio_mix.c(plan 279, A)는 쓰지 않는 다섯째 인자를 그대로 둠 — 자체 완결이라 이 머리를 읽지 않음, 바이트 영향 없음).
3. 빌드 전용 수정(바이트 무관):
   ④ AudioStream.h·snd_server.m: `<driverkit/NXSoundParameterTags.h>` → `<SoundKit/NXSoundParameterTags.h>`(D042; SDK `driverkit/IOAudio.h:11` 도 `<SoundKit/NXSoundParameterTags.h>` 를 import — 4.2 의 이름).
   ⑤ IOAudioPrivate.h·AudioStream.m: `<bsd/machine/limits.h>` → `<limits.h>`(SDK ansi; D043 진단으로 결정 — 4.2 SDK 에 bsd/machine/limits.h 없음).
   ⑥ audio_kern_server.m: `<audio/audio_msgs.h>` → `"audio_msgs.h"`(같은 Kernel/audio_msgs.h 하나만 둠; Darwin 은 설치 경로).
   ⑦ AudioChannel.m: `<bsd/string.h>`(4.2 SDK·Darwin 모두 없음 — 모의 스테이징에서 유일한 새 미해결) → `<bsd/strings.h>`(SDK, 진단 ovr 이 이 파일을 그 이름으로 넣었던 것과 같은 내용; SDK ansi/string.h 는 bzero 를 memset 매크로로 바꾸므로 쓰지 않음).
4. 배치(07):
   - 소스 9 개: `src/driverkit/libDriver/Kernel/<모듈>.m` — mkfinal D030 머리(원본 범위) + 본문.
   - 지역 머리 16 개: 같은 디렉터리(quoted 이름은 포함 파일 디렉터리에서 풀림 — stage_headers closure 와 cc 모두) — 머리 주석만 D030 문구로 바꾼 본문 그대로(③④ 만 수정).
   - `nextdev_private/driverkit/IOAudioPrivate.h`(D030, ⑤), `nextdev_private/bsd/dev/audioTypes.h`·`snd_msgs.h`(D032, Darwin kernel/bsd/dev 본문).
   - `nextdev/SoundKit/NXSoundParameterTags.h`: 실기 `/NextLibrary/Frameworks/SoundKit.framework/Headers/NXSoundParameterTags.h` 그대로(1893 B, sha256 92e1ccc9f5a1c37356d7d9bf49dc18a3c326ab1e2a3bf16e4e260682c7add21f — 2026-10-06 gcds krsha256 로 다시 확인, 호스트 사본 `08_build/runs/tools/soundkit-d042/` 와 같음). 목록 `09_validation/reconstruction/s5p342-soundkit-headers-20261006.json`(새로 만듦: 실기 경로·크기·sha256·확인 명령).
   - SDK 머리 7 개를 `nextdev/` 에 그대로 채택(nextdev-os42, 실기 목록 sha256 대조 — 모두 목록의 일반 파일이고 미러와 같음, 07 에 없음): driverkit/IOAudio.h, driverkit/i386/directDevice.h, driverkit/machine/directDevice.h, objc/objc-runtime.h, kernserv/kern_server_reply.h, kernserv/kern_server_reply_types.h, kernserv/kern_server_types.h(모의 스테이징에서 07 밖 SDK 미러로 풀린 전부; 앞선 libDriver 빌드 매니페스트의 mach/bsd_not_adopted 는 비어 있음 — 같은 상태로 맞춤).
   - `generated/audioReply.h`: MIG 생성물. 입력 `src/driverkit/libDriver/Kernel/audioReply.defs`(D030 사본) + SDK `mach/std_types.defs`·`mach/machine/machine_types.defs`·`mach/i386/machine_types.defs`·`architecture/ARCH_INCLUDE.h`(machine_types.defs:9 가 include; 실기 목록 대조, s5p61 스테이징 방식). 명령 Darwin libDriver Makefile 꼴 `/usr/bin/mig -arch i386 -Isrc/nextdev -header … -user … -server … audioReply.defs`, 반복 실행과 `-nostdinc` 판이 같아야 함(`s5p342-mig1`), 진단에 쓴 `08_build/runs/tools/audio-diag/audioReply.h` 와 비교. generated/README 에 한 줄 더함. audio.h 는 9 모듈이 쓰지 않아 만들지 않음.
5. 도구(stage_headers.py, plan 342 표시): `nextdev/SoundKit/…` 는 /NextDeveloper/Headers 목록에 없어 지금은 매니페스트에 "sha256 None; differs from the real machine" 가 잘못 적힘 → 위 SoundKit 목록에 있는 이름은 07 사본(심볼릭 링크 아님)의 sha256 이 목록 값과 같아야 하고(다르면 실패), 행에 실기 경로·sha256·D042 를 적는다. 목록에 없는 nextdev 이름은 지금 그대로. 시험 `test_stage_headers_soundkit.py`(양성: 실제 스테이징 행; 음성: 바뀐 사본 실패, 심볼릭 링크 거부, 목록에 없는 이름은 옛 경로). `--list` 는 매니페스트 검사 전에 끝나므로 이 검사를 하지 않음(지금 동작 그대로). 기존 시험(rename 12, subst, kr_run 등) 회귀.
6a. 코딩 전 모의 스테이징(scratchpad `k07sim` = 07 사본 + 위 배치, stage_headers 상수만 바꿔 closure 호출): 9 모듈 모두 지역 머리·IOAudioPrivate(nextdev_private)·audioTypes/snd_msgs(nextdev_private)·SoundKit(07 nextdev)·audioReply.h(generated) 로 풀림; 미해결은 ⑦ 전 `bsd/string.h`(AudioChannel)·`machdep/hppa/pmap.h`(hppa 분기) 말고는 기존 libDriver 빌드(`s5p329-it1` 매니페스트)와 같은 9 개.
6. 빌드·검사: 모듈마다 `PUBLIC_SDK=kernserv/queue.h EXTRA_DEFS=-DMACH_USER_API iter_objc.py s5p342-<약칭>1 driverkit/libDriver Kernel/<모듈>.m <모듈>` → relcheck → IOAudio·audio_kern_server 는 zerofill(참조 없으면 bios 선례 P) → record_objc. 매니페스트에 unresolved 중 ovr 로 풀던 이름이 남지 않는지 확인.
7. 예상: OBJECT_MATCH 7(A), 2 개는 zerofill 결과에 따라 A/P. 범위 합 python 으로 기록.
8. 바꾸지 않는 것: IOAudioPrivate.h:86 의 `_is22KRateSupported` 선언(메서드는 없지만 선언은 바이트 무관 — 원본이 요구하지 않는 수정은 안 함).

### codex 교차검토 판정(2026-10-06, plan 342, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| AudioChannel.m:52 `<bsd/string.h>` 미해결 — 처리 필요 | 모의 스테이징(k07sim, closure)에서 같은 미해결; 진단 ovr `bsd/string.h=…/bsd/strings.h` | ✅ (codex 회신 전 내가 먼저 찾아 ⑦ 로 넣음) |
| 지역 머리·IOAudioPrivate·audioTypes/snd_msgs·SoundKit·audioReply.h 배치가 풀림 | 같은 모의 스테이징 출력(9 모듈 모두, 출처 07 사본) | ✅ |
| RUNIN 은 `-I@R/…` 절대 인자여야 함 | scratchpad iter_objc.py: `-Isrc/` → `-I@R/` 치환 줄을 읽음 | ✅ 이미 그렇게 동작 |
| 새 파일로 기존 07 해석이 바뀌지 않음 | 07 + Darwin kernel 전수 grep(6 이름) — 다른 포함 없음 | ✅ |
| SoundKit 행은 일반 nextdev 분기에서, nxsha 와 분리 | stage_headers.py main() 읽음; 초안 extra_real() 을 그 분기 앞에 둠 | ✅ |
| 목록 JSON 생성을 명시 | 계획 문구 | ✅ 채택 |
| 심볼릭 링크 거부 시험 추가 | — | ✅ 채택 |
| 기존 시험 회귀 위험 낮음 | 수정 전 실행: rename 12/0 실패, subst 19/0 실패 | ✅ (수정 뒤 다시 실행) |
| 수정 분류(바이트·빌드 전용) 일관 | 최종 초안 대 진단 본문 python diff: 차이는 import 3 곳뿐 | ✅ |
| D032 는 “쓸 수 있는 판 없음”이면 되나 “시험한 판이 부족”으로 좁혀 적을 것 | DECISIONS.md:36 문구; snm1·sn71 오류 기록 | ⚖️ 채택 — 문구 고침 |
| MIG 에 ARCH_INCLUDE.h 빠짐 | machine_types.defs:9 읽음; 4 파일 실기 목록 sha 일치(python) | ✅ (회신 전에 고침) |
| SDK IOAudio.h 채택 단계 필요 | 모의 스테이징의 07 밖 파일 전수: SDK 7 개(IOAudio.h 말고 6 개 더) | ⚖️ codex 는 하나만 짚음 — 7 개 모두 채택으로 고침 |
| 주소·크기·판정 재현, 합 35241 / 범위 35251 / 채움 10 | 내 python(l1 json) | ✅ |

### 결과(2026-10-06, plan 342)

- 도구: stage_headers.py `EXTRA_LIST`/`extra_real()`(plan 342 표시) + 목록 `09_validation/reconstruction/s5p342-soundkit-headers-20261006.json`. 시험: test_stage_headers_soundkit.py 13/0 실패(07 소스를 둔 뒤 실제 스테이징 포함), rename 12/0, subst 19/0, gen_config_headers --check 통과.
- MIG `s5p342-mig1`(스테이징 `08_build/runs/tools/s5p342-stage-mig.py`, 입력 5 개 실기 목록·07 대조): audioReply.h·r_·n_(-nostdinc) 세 출력과 진단 헤더 모두 sha256 08c5c0f8… 같음 → `07_kernel/generated/audioReply.h`, README 에 한 줄.
- 07 배치: 소스 9, 지역 머리 16 + audioReply.defs, nextdev_private 3, SoundKit 1, SDK 채택 7. 매니페스트: mach/bsd_not_adopted 빔, 미해결은 기존 9 개(+AudioChannel 의 hppa 분기 1), SoundKit 행은 실기 경로·D042. IOAudioPrivate.h 행의 “real machine … sha256 None” 은 SDK 에 없는 작성 머리를 적는 기존 문구(IOEthernetPrivate.h `s5p310-it1` 도 같음) — 이번 변경과 무관, 그대로 둠.
- 빌드(07, RUNIN, `-DMACH_USER_API`, `--public-sdk kernserv/queue.h`): **OBJECT_MATCH 7** — AudioChannel `s5p342-ac1`, AudioStream `as1`, InputStream `in1`, OutputStream `ou1`, AudioCommand `cm1`, audio_server `sv1`, snd_server `sn1`; IOAudio `io1`·audio_kern_server `ak1` 는 사유 `__DATA,__bss: unverified` 하나. relcheck 9 개 모두 0.
- zerofill(알려진 배치 `zerofill-known-s5p339`): IOAudio reference-inferred(참조 5, Δ 0x1e417c, [0x1e8710, 0x1e8718) — IOEthernetDebugger `__bss` 끝 0x1e8710 바로 뒤), audio_kern_server reference-inferred(참조 13, Δ 0x1e7e60, [0x1e8718, 0x1e871c)); 음성 검사 둘 다 검출. 겹침 없음(python) → `zerofill-known-s5p342-20261006.json` 67 개. 두 객체 **P**.
- 기록 도구(scratchpad record_objc): 앞뒤 채움이 없을 때 다음 시작이 기호·IMP 가 아니어도, 이미 검증 기록된 함수 시작(functions.tsv)이고 `55 89 e5` 이면 받음(plan 342 표시) — audio_server 뒤 0x1bc4e8 은 snd_server 의 정적 snd_set_stream_format(기호 없음, `sn1` MATCH). 첫 시도는 표를 쓰기 전에 멈춤(grep 0 확인).
- 기록(python 대조): functions.tsv 3303→3548(+245 = 9 객체 `__text` 함수 합), objects_confirmed 247→254, objects_partial 64→66, PROVENANCE 834→872(소스 9 + 머리·defs 20 + 생성 1 + SoundKit 1 + SDK 7; 작성 머리 행의 3 열은 선례대로 Darwin 압축 파일 sha256), MODIFICATIONS 349→378. 공용 파일 설명은 `06_reconstruction/evidence/x86-IOAudio.md` 끝 절.
- 범위(python): 이번 35241 B. 누적 A 253 객체 487684 B(57.28%), P 65 객체 197807 B(23.23%), A+P **80.51%**(원본 `__text` 851436 B, 남은 165945 B).

## 343. S5-P332 세부 계획 — libDriver MIG 생성 C 3 개(EventServer.c·audioServer.c·audioReplyUser.c; D030·D017; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Event.defs·audio.defs·audioReply.defs 는 Darwin 0.1 driverkit-1/libDriver/Kernel 에만 있음(NeXTMach·Mach4·SDK 에 없음, find) → .defs 는 D030 사본(audioReply.defs 는 plan 342 에서 둠). 생성 C 는 Darwin libDriver Makefile 규칙(EVENT_CFILES·AUDIO_CFILES, 559–608 행)으로 만듦: `mig -arch i386 -user /dev/null Event.defs`, `mig -arch i386 -user /dev/null audio.defs`, `mig -arch i386 -server /dev/null audioReply.defs` + audioReplyUser.c 에 sed 두 줄(`/msg_send/s/MSG_OPTION_NONE, 0/SEND_TIMEOUT|SEND_SWITCH, 1000/`, `/msg_rpc/s/RCV_TIMEOUT, 0/RCV_TIMEOUT|SEND_SWITCH, 1000/`).

0. 원본(symbols.tsv, l1, python): 빈 구간 [0x1bee8b, 0x1c6c44) 32185 B 의 앞부분 — `_Event_server` 0x1bee8c(정적 `__XEv*` 9 개 포함 `__text` 1392 B), `_audio_server` 0x1bf3fc(5081 B, 뒤 채움 3 B), `__NXAudioReplyStreamStatus` 0x1c07d8·`__NXAudioReplyRecordedData` 0x1c086c(320 B); 다음 `_initDmaLock` 0x1c0918 부터는 이 계획 밖. `__TEXT,__const` 144·472·48 B(MIG 검사 상수·routines 표). 합 `__text` 6793 B.
1. 진단(07 아님): MIG `s5p345-migd1`(Darwin .defs + SDK std_types·mach_types·machine_types×2·ARCH_INCLUDE, 실기 목록 대조) → audioReply.h 는 07 generated/audioReply.h 와 같은 바이트. 07 사본 + 생성 C 로 스테이징(scratchpad diag.py, stage_headers 상수만 바꿈), libDriver C 꼴(`-fwritable-strings` 없음, -O3): EventServer `s5p345-ev1`, audioServer `s5p345-au1`, audioReplyUser(sed 뒤) `s5p345-ar1` 모두 **OBJECT_MATCH**(함수·`__const` 차이 0). 미해결 include 는 기존 9 개뿐.
2. 07 배치:
   - `src/driverkit/libDriver/Kernel/Event.defs`·`audio.defs`: D030 사본(머리 주석만 교체, mkhdr).
   - `src/driverkit/libDriver/EventServer.c`·`audioServer.c`·`audioReplyUser.c`: MIG 출력 그대로(generated-mig; 머리 주석을 넣지 않음 — 생성물 바이트 그대로 둬 재생성으로 검사 가능). iter_nows 가 07 src 에서 스테이징할 수 있는 자리(Darwin 은 `$(OBJROOT)/$(MACHINE)KernRelease` 빌드 디렉터리에서 만들고 -I 로 찾음 — 자리는 같지 않음). audioReplyUser.c 는 “MIG 출력 + Makefile 의 결정적 치환”으로 기록. generated/README 에 이 생성 C 와 재생성 명령을 가리키는 줄을 더함.
   - MIG run `s5p343-mig1`: 07 .defs 3 개 + SDK 5 개(실기 목록 대조, 스테이징 스크립트 `08_build/runs/tools/s5p343-stage-mig.py`), 명령은 Darwin 꼴에 `-Isrc/nextdev` 와 버리는 쪽 출력 이름만 붙임. 반복 실행과 `-nostdinc` 판이 같아야 함. 진단 출력과 바이트 비교.
   - sed: kr_run 은 sed 를 허용 도구로 갖지 않고 인자에 `|` 를 받지 않으므로, 호스트 스크립트 `08_build/runs/tools/s5p343-sed-audioReplyUser.py` 가 Darwin sed 두 줄과 같은 치환을 줄 단위로 함(패턴이 있는 줄에서 첫 일치만 바꿈 = sed `s` 기본; 바뀐 줄이 정확히 2 개가 아니면 실패). 입력·출력 sha256 기록.
3. 빌드·검사: `iter_nows.py s5p343-<약칭>1 driverkit/libDriver/<이름>.c <이름> LO HI` → relcheck → 기록(record_object, generated-mig 이므로 license 문구는 생성물·D030 .defs·SDK D017).
4. 바꾸지 않는 것: 생성 헤더 Event.h·audio.h 는 쓰는 곳이 없어 두지 않음; driverServerServer.c(0x1827f0, Darwin kernel conf/Makefile.template 의 `-typed … -DKERNEL_SERVER` 규칙, 입력 PrivateHeaders driverServer.defs)는 다음 계획.
5. 예상: 3 객체 A, 6793 B.
6. SDK `mach/msg_type.h`(audioReplyUser.c 가 include; 07 에 없음 — `s5p345-ar1` 매니페스트 mach_not_adopted) 는 실기 목록과 같은 SDK 판을 그대로 채택(record_object 의 adopt_headers 단계, 선례대로 PROVENANCE 행).
7. 기록 도구(scratchpad record_object, plan 343 표시): 종류 `generated-mig` 추가(REV = run·도구 해시, 함수 행 인용 = 생성 파일:줄, diff 기준 = MIG 원출력) + fline 이 MIG 꼴(이름 다음 줄에 괄호)을 찾도록 보완(첫 패턴이 실패할 때만).

### codex 교차검토 판정(2026-10-06, plan 343, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| Makefile 규칙(user/server 쪽 /dev/null, -arch, -newipc·-typed 없음) 을 계획이 그대로 따름 | Makefile 559–608 읽음(앞서) | ✅ |
| sed 는 줄마다 첫 일치만, 바뀌는 줄 2 개(201·373), msg_rpc 식은 이 파일에서 효과 없음 | grep msg_send/msg_rpc(201·373 만, msg_rpc 0); 호스트 sed 출력 = python 치환 출력(cmp) | ✅ |
| 주소·크기 1392/5081/320 = 6793, `__const` 144/472/48, audio 뒤 00×3 | 내 python(l1 json·symbols) | ✅ |
| 진단 세 객체 OBJECT_MATCH 재현 | 내 l1 json(ev1·au1·ar1) | ✅ |
| 생성 C 를 머리 주석 없이 둠 = generated-mig 선례와 맞음; 출력에 고지 문구 없음 | PROVENANCE generated-mig 행·generated/README; 출력 grep(copyright 등) | ✅ (grep 결과는 아래 기록 때 다시 확인) |
| mach/msg_type.h 가 07 에 없음 — 채택 필요 | 매니페스트 mach_not_adopted, 07 파일 없음, SDK sha = 실기 목록(python) | ✅ 채택 — 6 항 |
| 스테이징 전체 폐포에 Darwin 전이 파일(ppc 등)이 남음 — “직접 include” 로 한정해 말할 것 | 기존 libDriver 빌드와 같은 꼴(plan 342 모의 스테이징) | ⚖️ 사실, 새 문제 아님 — 문구 한정 |
| BUILD_DIR 설명 부정확 | Makefile:332 `$(OBJROOT)/$(MACHINE)KernRelease` | ✅ 채택 — 문구 고침 |
| -nostdinc 재생성 비교·README 줄 | 선례 s5p61·s5p342 | ✅ 채택 |

### 결과(2026-10-06, plan 343)

- 07: `Kernel/Event.defs`·`audio.defs`(D030, mkhdr — PLAN 인자를 더하면서 한 번 잘못 고친 것을 바로잡고 AudioChannel.h 재생성으로 회귀 확인). 스테이징 스크립트 `08_build/runs/tools/s5p343-stage-mig.py`(SDK 5 + .defs 3).
- MIG: `s5p343-mig1` 은 스크립트를 잘못 고친 채 스테이징해(audioReply.defs·SDK 4 개만) 실패 — 버린 run. `s5p343-mig2`: EventServer.c·audioServer.c 는 본·r_(반복)·n_(-nostdinc)·진단 `s5p345-migd1` 네 판이 같음. audioReplyUser.c 는 User 파일이 `-header` 로 준 이름을 include 하므로(1 행만 다름 확인) Darwin 기본 이름 audioReply.h 로 `s5p343-mig3` 을 따로 돌림 — `s5p343-mig4`(-nostdinc)·`s5p345-migd1` 과 같은 바이트, 함께 나온 audioReply.h 는 07 generated/audioReply.h 와 같음.
- sed: `08_build/runs/tools/s5p343-sed-audioReplyUser.py`(로그 `s5p343-sed-audioReplyUser.log`): 바뀐 줄 2(201·373), 출력 = 호스트 sed 출력(cmp). 07 `src/driverkit/libDriver/{EventServer,audioServer,audioReplyUser}.c`, generated/README 에 재생성 경로 줄.
- 빌드(iter_nows): `s5p343-mev1` EventServer, `mau1` audioServer, `mar1` audioReplyUser 모두 **OBJECT_MATCH**, relcheck 0 → **A**.
- 기록 도구(scratchpad record_object, plan 343 표시): 종류 generated-mig·fline MIG 꼴(위 7 항). 기록 중 adopt_headers 가 SDK `mach/msg_type.h` 를 07 nextdev 에 채택(실기 목록 sha 23994527…).
- 기록(python 대조): functions.tsv 3548→3598(+50 = 10+38+2), objects_confirmed 254→257, PROVENANCE 872→876(객체 3 + msg_type.h), MODIFICATIONS 378→381. 근거 x86-EventServer/audioServer/audioReplyUser .md·.diff(앞 둘 diff 비어 있음 = MIG 출력 그대로, 셋째는 sed 두 줄).
- 범위(python): 이번 6793 B. 누적 A 256 객체 494477 B(58.08%), P 65 객체 197807 B(23.23%), A+P **81.31%**.

## 344. S5-P333 세부 계획 — 커널 트리 `driverkit/driverServerServer.c`(MIG 생성, driverServer.defs 4.2 판; D024·D030·D017; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): driverServer.defs 는 Darwin 0.1 driverkit-1/libDriver 에만 있음(NeXTMach·Mach4·4.2 SDK 에 없음 — SDK 에는 driverkit/machine/driverServer.h 뿐). 생성 규칙은 Darwin kernel `conf/Makefile.template` 의 DEVSERV(PrivateHeaders/driverkit/driverServer.defs 를 driverkit/ 로 복사, `mig -typed -MD -arch i386 $(MIGKSFLAGS)` = `-I. -I.. -I$SRC -DKERNEL -DKERNEL_SERVER`, `-server driverServerServer.c`), 소스 목록 `conf/files:522 ./driverkit/driverServerServer.c optional driverkit`.

0. 원본: [0x1827f0, 0x18335c) 2924 B(앞 00×3 — driverServerXXX 끝 0x1827ed, plan 333; 뒤는 SCSIDiskKern 0x18335c, plan 328). 함수 21: 기호 `_driverServer_server` 0x182a0c·`_driverServer_server_routine` 0x182a84 + 정적 19. 서버는 msg_id 2700(0xa8c)부터 0x26 까지(39 칸) 검사, 루틴 표 0x1e11c8 의 비어 있지 않은 칸 19 개 = Darwin MIG 표의 18–38 칸(_IOLookupByObjectNumber … _PMRestoreDefaults)과 같은 자리; Darwin 의 39–43 칸(_IOCallDeviceMethod·_IOServerConnect·_IOLookUpByStringPropertyList·_IOGetStringPropertyList·_IOGetByteProperty)은 원본에 없음(python, 표 읽음).
1. 진단(07 아님, `s5p346-*`): Darwin defs 그대로는 4.2 driverTypes.h 에 IOByteParameter 가 없어 컴파일 실패(`ds2`). 1–397 행(뒤 5 루틴 제외, `migd2`) + 기본 mig 는 `_driverServer_server_routine` 이 없고 크기 다름(`ds3`). `-newipc`(migcom3, s5p61 선례; `-Isrc/generated` 로 07 norma_vm.h) 은 함수 크기가 EISA 셋 말고 같고 요청 포트를 +0xc(msgh_local_port)로 읽음(`ds4`; 원본 +8). `-DMACH_IPC_FLAVOR` 를 더하면 defs 33–36 행의 `KernelServer` 가 켜져 msgh_request_port = msgh_remote_port → `ds5` **OBJECT_MATCH**(`__text` 2921 B + 뒤 00×3, `__data` 332 B). `-typed` 는 -newipc 에서 출력에 영향 없음(`migd3` n_/t_ 같음).
2. 07 배치:
   - `src/driverkit/driverServer.defs`: D030 사본(Darwin kernel 의 DEVSERVDIR 자리 driverkit/) — 머리 주석 교체(mkhdr, PLAN=plan 344) + 끝의 5 루틴 삭제(원본 루틴 표가 요구; plan 344 표시 주석 한 줄). 그 밖 본문 그대로(쓰이지 않는 type IOByteParameter 정의도 둠).
   - `src/driverkit/driverServerServer.c`: MIG 출력 그대로(generated-mig, plan 343 과 같은 방식).
   - MIG run `s5p344-mig1`: 스테이징 `08_build/runs/tools/s5p344-stage-mig.py`(07 defs + SDK 5 개(std_types·mach_types·machine_types×2·ARCH_INCLUDE) 실기 목록 대조 + 07 generated/*.h), 명령 `/usr/bin/mig -typed -newipc -arch i386 -Isrc/generated -Isrc/nextdev -DKERNEL -DKERNEL_SERVER -DMACH_IPC_FLAVOR …` + 같은 run 안 반복(r_)·-typed 없는 판(u_)·`-nostdinc` 판(n_) — `migd3` 의 -typed 비교는 norma_vm.h 오류 상태였으므로 근거로 쓰지 않음. 서버 C 는 헤더를 include 하지 않으므로 이름을 달리해도 됨(출력 비교로 확인). 진단 `migd5` 출력과 바이트 비교.
   - `-newipc`·`-DMACH_IPC_FLAVOR` 는 Darwin Makefile 에 글자로 없는 선택: 원본 바이트(요청 포트 오프셋 +8, server_routine 존재·함수 크기)가 근거. generated/README 에 재생성 줄.
2a. 머리 채택(codex 지적, 매니페스트로 확인): 생성 C 가 직접 읽는 `driverkit/driverTypesPrivate.h`·`driverkit/driverServerXXX.h` 와 SDK `driverkit/machine/driverTypesPrivate.h` 의 ARCH_INCLUDE 로 읽히는 `driverkit/i386/driverTypesPrivate.h` 가 07 이 아니라 Darwin 에서 옴(`s5p346-ds5` 매니페스트) — 모두 SDK·Mach4·NeXTMach 에 없음 → D030 사본: `nextdev_private/driverkit/driverTypesPrivate.h`·`nextdev_private/driverkit/i386/driverTypesPrivate.h`(머리 주석만 교체), `src/driverkit/driverServerXXX.h`(driverServerXXX.m 이 D030 작성이므로 같은 취급). SDK `mach/mig_support.h`(mach_not_adopted)는 record_object 의 adopt_headers 로 채택.
2b. 회귀: 위 세 Darwin 머리는 이미 기록된 6 객체의 빌드에서도 Darwin 대체 경로로 읽혔음(IODisplay `s5p295-it2`, autoconf_i386 `s5p325-it1`, kmDevice `s5p327-it2`, PCPointer `s5p331-it1`, driverServerXXX `s5p333-it1`, kmLocalized `s5p340-it1`). 07 사본은 주석만 달라 바이트 영향이 없어야 함 → 각 run 매니페스트의 인자(sources·public_sdk 등)로 다시 스테이징해 같은 cmd 로 빌드(새 run ID)하고 목적 파일 sha256 이 같은지 확인.
3. 빌드·검사: kernel C 꼴(`-fwritable-strings` 있음, iter.py, plan 형식 그대로) `iter.py s5p344-it1 driverkit/driverServerServer.c driverServerServer 0x1827f0 0x18335c` → relcheck → record_object(generated-mig).
4. 예상: A, 2921 B(+3 채움).

### codex 교차검토 판정(2026-10-06, plan 344, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 표: 기준 0xa8c, 범위 0x26, 0x1e11c8, 비어 있지 않은 칸 18–27·30–38 = Darwin 18–38 | 내 odis3(0x182a4d·0x182a53·0x182a97)·python 표 읽기·migd1 routines[] 대조 | ✅ |
| 뒤 5 루틴 삭제가 최소 변경, 남은 msg id 그대로; skip 으로 두면 범위가 길어짐 | 원본 범위 검사 0x26(=39 칸)과 Darwin 표 44 칸 | ✅ |
| ds5 OBJECT_MATCH, text 2921·data 332, 앞뒤 00×3 | 내 l1(ds5.json)·python(2924 = 2921+3, 앞 0x1827ed–0x1827f0) | ✅ |
| MACH_IPC_FLAVOR 는 요청 포트 말고도 바꾸는 것이 있음(type unsigned 줄, ipc_port 형·release 호출 등); 전체 L1 일치가 근거 | defs 33–45 읽음; ds4→ds5 크기 변화는 EISA 셋(+28 B 씩, 내 크기 표) | ⚖️ 사실 — 기록 문구에 “요청 포트만”이라 쓰지 않음 |
| 실기 mig 래퍼는 -newipc 에 NEW_MACH_IPC 만 정의, MACH_IPC_FLAVOR 는 정의 안 함 → 원본 바이트에 근거한 재구성 선택으로 기록 | migd3/4 경고(“overriding previous definition of unsigned”) = MACH_IPC_FLAVOR 미정의 | ✅ (계획에 이미 그렇게 적음) |
| driverTypesPrivate.h·i386/driverTypesPrivate.h·driverServerXXX.h 가 Darwin 직접, mig_support.h 미채택 | ds5 매니페스트 python | ✅ 채택 — 2a 항 |
| -nostdinc 판 비교 추가, migd3 -typed 비교는 오류 상태 | migd3 00.err(norma_vm.h 없음) | ✅ 채택 |
| ds5 컴파일 경고(convert_port_to_dev 포인터→정수) 기록 | (빌드 때 err 로그 확인) | ⏭️ 기록만 |
| (codex 밖, 내가 찾음) 같은 Darwin 머리를 이미 기록된 6 객체가 써 왔음 | 모든 s5p*-stage 매니페스트 python 검색 | 2b 회귀 추가 |

### 결과(2026-10-06, plan 344)

- 07: `src/driverkit/driverServer.defs`(D030, 1–397 행 + 끝 plan 344 주석), `nextdev_private/driverkit/driverTypesPrivate.h`·`i386/driverTypesPrivate.h`, `src/driverkit/driverServerXXX.h`(D030). 스테이징 `08_build/runs/tools/s5p344-stage-mig.py`(SDK 5 + defs + generated 51).
- MIG `s5p344-mig1`: 본·r_(반복)·u_(-typed 없음)·n_(-nostdinc) 과 진단 `s5p346-migd5` 다섯 판 같은 바이트, stderr 비어 있음 → `src/driverkit/driverServerServer.c`(고지 문구 0), generated/README 줄.
- 빌드 `s5p344-it1`(iter.py, kernel C 꼴): **OBJECT_MATCH**(21 함수, `__text` 2921 B, `__data` 332 B), relcheck 0, 매니페스트에 Darwin driverkit 머리 없음 → **A**. 기록 중 adopt_headers 가 SDK `mach/mig_support.h` 채택.
- 회귀 2b(`08_build/runs/*-rg1`, scratchpad regress344.py): 6 객체 모두 같음 — 기준은 모든 섹션 바이트·재배치·stab 아닌 기호(전체 sha 는 `-g` stab 의 줄 번호가 머리 주석 길이를 따라 달라짐 — kmLocalized 에서 확인, `__text`·`__data` 같고 L1 OBJECT_MATCH). 스테이징 차이는 위 세 머리뿐.
- 기록(python 대조): functions.tsv 3598→3619(+21), objects_confirmed 257→258, PROVENANCE 876→882(객체·mig_support.h·D030 4), MODIFICATIONS 381→386.
- 범위(python): 이번 2921 B. 누적 A 257 객체 497398 B(58.42%), P 65 객체 197807 B(23.23%), A+P **81.65%**(남은 156231 B).

## 345. S5-P334 세부 계획 — libDriver 버스·디스플레이 5 모듈(`eisa/IOEISADirectDevice.m`·`eisa/IOEISADeviceDescription.m`·`pcmcia/IOPCMCIADeviceDescription.m`·`pcmcia/IOPCMCIATuple.m`·`Kernel/IOSVGADisplay.m`) + 쓰는 Darwin·SDK 머리 채택(D024·D027·D030·D031; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리 find): 다섯 소스는 Darwin 0.1 driverkit-1/libDriver 에만 있음 → D030. `driverkit/i386/EISAKernBus.h`·`PCMCIAKernBus.h`·`PCMCIATuple.h`(와 PCIKernBus.h·PCMCIAPool.h)는 어느 트리·SDK 목록에도 없음; 원본 커널에도 EISAKernBus·PCIKernBus 클래스 없음(objc.json — KernBus 계열만).

0. 원본(진단 l1 json, python): IOEISADirectDevice [0x1c0918, 0x1c133b) 2595 B·32 함수(정적 initDmaLock 포함)·`__bss` 16 B; IOEISADeviceDescription [0x1c133c, 0x1c1745) 1033 B·11; IOPCMCIADeviceDescription [0x1c2084, 0x1c2233) 431 B·4; IOPCMCIATuple [0x1c2234, 0x1c2387) 339 B·5; IOSVGADisplay [0x1c52f4, 0x1c6c41) 6477 B·31·`__bss` 16 B. 합 10875 B.
1. 진단(scratchpad `bus/<모듈>/wip.m`, 모듈 이름 줄 + Darwin 본문, `EXTRA_DEFS=-DMACH_USER_API`): Darwin 그대로는 IOSVGADisplay 만 빌드됨(`s5p347-svc1`: `__bss` 만 미검증). 나머지는 없는 머리로 실패(`s5p347-eisadia3`·`eisadea3`·`pmd3`·`pmt2`). 아래 수정 뒤: IOEISADirectDevice `s5p347-edc1`(`__bss` 만 미검증), IOEISADeviceDescription `eec1`·IOPCMCIADeviceDescription `pmc1`·IOPCMCIATuple `ptb1` **OBJECT_MATCH**.
2. 수정(plan 345 표시):
   ① 네 소스: 없는 `#import <driverkit/i386/{EISAKernBus,PCMCIAKernBus,PCMCIATuple}.h>` 삭제 — “빌드 전용”이 아니라 **필요한 빌드 적응, 이 i386 컴파일에서 원본과 대조해 검증됨**(없는 머리가 원래 어떤 선언을 줬는지는 모름; 예: IOEISADeviceDescription 의 `getEISASlotNumber:slotID:usingDeviceDescription:` 는 선언이 없어 반환형이 id 로 처리되지만 OBJECT_MATCH — eec1 컴파일 경고 3 행).
   ② IOEISADeviceDescription: 쓰는 키 `IO_PORTS_KEY "I/O Ports"`·`DMA_CHANNELS_KEY "DMA Channels"` 를 파일 안에 정의(plan 333 driverServerXXX.m 과 같은 값; 문자열은 원본 cstring 과 일치). IOPCMCIADeviceDescription: `PCMCIA_TUPLE_LIST "PCMCIA_TUPLE_LIST"`(원본 파일 오프셋 0xd8dd4 의 문자열과 같음 — 키 이름 = 문자열).
   ③ IOEISADirectDevice: `#import <kern/assert.h>` 더함(원본 바이트로 확인한 구성 보정 — 없으면 `ASSERT(...)` 가 함수 `_ASSERT` 호출로 컴파일되어 reserveDMALock +20 B·releaseDMALock +16 B(`s5p347-edb1`); 07 kern/assert.h 는 MACH_ASSERT 0 에서 빈 매크로, 원본과 같음).
   ④ IOEISADeviceDescription: Private 범주의 `property_IODeviceType:length:` 삭제(원본 메서드 목록에 없음 — 바이트가 요구).
3. 07 배치: `src/driverkit/libDriver/{eisa,pcmcia,Kernel}/<모듈>.m`(mkfinal D030 머리). 머리 채택(모의 스테이징에서 07 밖으로 풀린 것 중 다른 아키텍처 분기(ppc·machdep/machine 등 12 개 — closure 는 조건을 평가하지 않음, 기존 빌드와 같은 꼴)를 뺀 전부): Darwin driverkit-1/driverkit 의 EventDriver.h·IODeviceDescriptionPrivate.h·IODirectDevicePrivate.h·IODisplayPrivate.h·IOProperties.h·IOVGAShared.h·i386/IOEISADeviceDescriptionPrivate.h·i386/IOPCMCIADeviceDescriptionPrivate.h·i386/IOPCMCIATuplePrivate.h → `nextdev_private/driverkit/…` D030 사본(SDK 에 없음 — 실기 목록 확인); Darwin kernel/driverkit 의 KernBus.h·KernBusMemory.h·KernDevice.h·KernDeviceDescription.h → `src/driverkit/` D030 사본(KernBus.m 등이 D030 작성, plan 304–306); SDK driverkit/IOSVGADisplay.h·i386/IOPCMCIADeviceDescription.h·i386/IOPCMCIATuple.h → `nextdev/` 그대로(실기 목록 sha 대조). 새 미해결은 IOSVGADisplay 의 hppa/ppc/sparc ConsoleSupport.h(다른 아키텍처 분기)뿐.
4. 회귀: 위 Darwin 머리 13 개를 이미 기록된 16 run 이 대체 경로로 읽음(s5p293-it2, s5p295-it2…it5, s5p298-it2, s5p299-it1·it2, s5p301-it1·it2, s5p306-it1, s5p307-it1, s5p321-it1, s5p325-it1, s5p327-it2, s5p333-it1) → plan 344 의 regress 방식(같은 인자로 다시 스테이징·같은 cmd, 섹션 바이트·재배치·stab 아닌 기호 비교).
5. 빌드·검사: `iter_objc.py s5p345-<약칭>1 driverkit/libDriver <dir>/<모듈>.m <모듈>`(EXTRA_DEFS=-DMACH_USER_API) → relcheck → `__bss` 둘은 zerofill → record_objc.
6. 남은 것(이 계획 밖): IOPCIDirectDevice·IOPCIDeviceDescription(PCI 버스 메서드 선언의 unsigned char 인자 — 원본에서 작성 필요), IOPCMCIADirectDevice(unmapAttributeMemory 2 B 차이), IOFrameBufferDisplay(메서드 크기 차이 3 곳). 기록된 객체가 대체 경로로 읽는 나머지 Darwin 머리(rec-stage 매니페스트의 Darwin 머리 52 개 중 다른 아키텍처 15 개를 뺀 37 개 중 이 계획·plan 344 밖 — kern/parallel.h, ipc/ipc_machdep.h 등)는 따로 정리.

### codex 교차검토 판정(2026-10-06, plan 345, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 진단 본문에 계획에 없는 키 정의(MEM_MAPS·IRQ_LEVELS, PCMCIA_SOCKET·WINDOW)가 있음 — 쓰이지 않음 | 07 초안(scratchpad p345/*.m) grep: 0 건 — 최종본은 쓰는 키만 정의 | ✅ 사실, 초안은 이미 반영 |
| “빌드 전용” 근거 과함 — 없는 머리의 선언은 모름; eec1 경고(getEISASlotNumber… 반환 id) | eec1 00.err 3 행 확인 | ✅ 채택 — ①·③ 문구 고침 |
| L1 재실행 5 개 결과·범위·크기·함수 83·bss 16/16 | 내 python(앞서 0 항) | ✅ |
| ASSERT: edb1 에 `_ASSERT` 미정의, +20/+16 B; edc1 에는 없음; assert.h·mach_assert.h 경로 | 내 macho 기호 확인·내 크기 표 | ✅ |
| 키 문자열 세 개의 원본 위치·참조 일치 | 내 python(원본 검색·객체 cstring) | ✅ |
| IOSVGADisplay 는 다른 키(“Display Mode” 등)도 씀 — “키”는 버스 자원 키로 한정 | Darwin 본문 그대로 OBJECT 일치(svc1, bss 만) | ⚖️ 문구 한정(이 모듈은 수정 없음) |
| property_IODeviceType:length: 원본에 없음 | 앞서 objc.json 11 메서드 목록 | ✅ |
| 채택 목록 13+3 은 빠짐없음, 다만 closure 는 ppc 등 12 개 더(조건 미평가) | 내 모의 스테이징에서 같은 걸러냄 | ✅ 문구 고침 |
| 회귀 16 run 정확; 37 은 52−15 | 내 python: 같은 16 run; rec-stage Darwin 머리 52, 다른 아키텍처 15, 나머지 37 | ✅ 문구 고침 |
| mkfinal 은 표시 줄이 남은 본문을 받으면 고지를 못 지움 — 표시 줄을 떼고 넘길 것 | 초안은 `split('\n',1)[1]` 로 표시 줄 뗌, mkfinal 5 개 모두 성공 | ✅ 이미 그렇게 함 |

### 345a. 덧붙임(codex 1 차 검토 뒤 발견, 코딩 전) — `pcmcia/IOPCMCIADirectDevice.m`

- 원본 [0x1c1cb8, 0x1c2081) 969 B, 함수 2(mapAttributeMemoryTo:findSpace:·unmapAttributeMemory), `__bss` 없음.
- 진단: 없는 머리 import 를 빼면(`s5p347-pxc1`) `List` 미선언; `<objc/List.h>` 를 더하면(`pxd1`) unmapAttributeMemory 만 2 B 다름 — 원본은 `[window memoryInterface]`·`[window attributeMemory]` 의 반환을 `test al,al`(BOOL) 로 검사, 빌드는 선언이 없어 `test eax,eax`. 두 셀렉터를 BOOL 반환으로 선언(구현 없는 범주 interface, 메타데이터 없음)한 `pxe1` **OBJECT_MATCH**.
- 수정(plan 345 표시): 없는 `PCMCIAKernBus.h`·`PCMCIAPool.h` import 삭제(빌드 전용), 쓰는 키 `PCMCIA_SOCKET_LIST`·`PCMCIA_WINDOW_LIST` 를 같은 이름의 문자열로 정의(원본 파일 오프셋 0xd8dac·0xd8dc0 의 문자열), `#import <objc/List.h>`(빌드 전용), `@interface Object(...) - (BOOL)memoryInterface; - (BOOL)attributeMemory; @end`(원본 바이트에서 작성, D024 — 없는 머리에 있던 선언의 반환형).
- 이 덧붙임은 codex 2 차 검토에 넣음.

### 345b. 덧붙임(코딩 전) — `pci/IOPCIDirectDevice.m`·`pci/IOPCIDeviceDescription.m`

- 원본: IOPCIDirectDevice [0x1c1748, 0x1c1b85) 1085 B·10 함수(정적 getThePCIBus 는 인라인), IOPCIDeviceDescription [0x1c1b88, 0x1c1cb6) 302 B·3 함수; `__bss` 없음.
- 진단: 없는 `PCIKernBus.h` import 삭제만으로는 `KernBus` 미선언(`pdb1`)·`IOTypePCI` 미정의(`peb1`). `<driverkit/KernBus.h>` 를 더하면 차이: direct 의 `+getPCIConfigSpace:withDeviceDescription:` −4 B·`+setPCIConfigSpace:withDeviceDescription:` 같은 크기지만 바이트 다름(원본은 get·set 모두 address 인자를 `movzx eax,bl` 로 넘김 — 0x1c184b·0x1c1941, 단일 레지스터 호출 0x1c1a32·0x1c1b1e), 설명자의 `_initWithDelegate:` +4 B(원본은 `[thePCIBus isPCIPresent]` 를 `cmp al,1` — BOOL 반환). 원본 메서드 목록에 없는 `property_IODeviceType:length:`·`property_IOSlotName:length:` 삭제. 선언을 더한 `pde1`·`ped1` **OBJECT_MATCH**. 선언 형은 원본 바이트를 재현하는 최소 재구성(없는 PCIKernBus.h 의 실제 선언과 같다는 증명은 아님 — ABI 가 같은 다른 표기도 가능).
- 수정(plan 345 표시): 없는 머리 import 삭제(빌드 적응), `#import <driverkit/KernBus.h>`(빌드 적응), 구현 없는 범주 interface 로 선언(원본 바이트에서 작성, D024): direct `- (IOReturn)getRegister:(unsigned char)… device:(unsigned char)… function:(unsigned char)… bus:(unsigned char)… data:(unsigned long *)…;`·`setRegister:… data:(unsigned long)…;`, 설명자 `- (BOOL)isPCIPresent;`; 설명자의 두 property 메서드 삭제(바이트가 요구).
- 345a·345b 는 codex 2 차 검토 뒤 07 에 넣음.
- 머리 추가 채택(모의 스테이징, codex 2 차 지적 확인): SDK driverkit/i386/IOPCMCIADirectDevice.h·PCI.h·IOPCIDirectDevice.h·IOPCIDeviceDescription.h → `nextdev/` 그대로(실기 목록 대조), Darwin driverkit/i386/IOPCIDeviceDescriptionPrivate.h → `nextdev_private/driverkit/i386/` D030.
- 문구: 345a·345b 의 import 삭제·더한 import·선언도 plan 345 ① 과 같이 “이 i386 컴파일에서 원본과 대조해 검증한 빌드 적응/재구성 선언”(없는 머리가 그것을 줬다는 것은 추정). 07 본문의 주석도 그렇게 씀.

### codex 2 차 교차검토 판정(2026-10-06, plan 345a·345b, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| IOPCMCIADirectDevice 진단 본문의 `PCMCIA_TUPLE_LIST` 는 안 쓰임 | Darwin 원문 grep(SOCKET 73·WINDOW 81·134 행만) — 345a 에도 둘만 적음 | ✅ 07 본문에서 뺌 |
| 세 객체 OBJECT_MATCH·범위·크기·함수 수(합 2356 B·15) | 내 python(345a·345b 범위) | ✅ |
| BOOL 검사 바이트(test al,al·cmp al,1) | 내 odis3·fdis(앞서) | ✅ |
| setRegister 쪽도 movzx(0x1c1941) — 345b 에 빠짐 | odis3 0x1c1938–0x1c1950 | ✅ 채택 — 345b 고침 |
| 선언 형은 최소 재구성이지 원래 선언의 증명은 아님 | — (해석) | ✅ 채택 — 문구 |
| property 두 메서드 원본에 없음 | 앞서 objc.json 목록 | ✅ |
| PCMCIA 두 키 문자열 위치·참조 | 앞서 python 검색(0xd8dac·0xd8dc0) | ✅ |
| 머리 5 개 추가 채택 필요 | 내 모의 스테이징(같은 5 개) | ✅ 채택 |
| 345 본문 제목·“남은 것” 항목 갱신 | — | ✅ 결과 절에서 갱신 |

### 결과(2026-10-06, plan 345·345a·345b)

- 07: 소스 8(`libDriver/eisa/` 2, `pcmcia/` 3, `pci/` 2, `Kernel/IOSVGADisplay.m`), D030 머리 14(nextdev_private/driverkit 10, src/driverkit Kern* 4), SDK 머리 7(nextdev). 진단 주석은 모두 최종 문구로 바꿈(“diag” 0 건), 쓰지 않는 키 정의 없음.
- 빌드(07, RUNIN, `-DMACH_USER_API`): OBJECT_MATCH 6 — IOEISADeviceDescription `s5p345-ee1`, IOPCMCIADeviceDescription `pm1`, IOPCMCIATuple `pt1`, IOPCMCIADirectDevice `px1`, IOPCIDirectDevice `pd1`, IOPCIDeviceDescription `pe1`; `__bss` 만 미검증 2 — IOEISADirectDevice `ed1`, IOSVGADisplay `sv1`. relcheck 8 개 모두 0, 매니페스트에 Darwin driverkit 머리·미채택 없음.
- zerofill(알려진 배치 `zerofill-known-s5p342`): IOEISADirectDevice reference-inferred(참조 27, Δ 0x1e7700, [0x1e871c, 0x1e872c)), IOSVGADisplay reference-inferred(참조 16, Δ 0x1e61ac, [0x1e872c, 0x1e873c)) — audio_kern_server 끝 0x1e871c 와 IOVPCodeDisplay 시작 0x1e873c 사이를 빈틈없이 채움; 겹침 없음(python) → `zerofill-known-s5p345-20261006.json` 69 개. 두 객체 **P**.
- 회귀(`*-rg2`, scratchpad regress345.py): 16 run 모두 같음(섹션 바이트·재배치·stab 아닌 기호). 새 i386/IOPCIDeviceDescriptionPrivate.h 는 기존 사용자 없음; SDK 사본은 미러와 같은 바이트.
- 기록(python 대조): functions.tsv 3619→3717(+98 = 8 객체 함수 합), objects_confirmed 258→264, objects_partial 66→68, PROVENANCE 882→911(객체 8 + 머리 21), MODIFICATIONS 386→408(객체 8 + D030 머리 14).
- 범위(python): 이번 13231 B(10875 + 2356). 누적 A 263 객체 501557 B(58.91%), P 67 객체 206879 B(24.30%), A+P **83.20%**(남은 143000 B).
- 남은 것: IOFrameBufferDisplay(진단 `s5p347-fbd1`: getIntValues:forParameter:count: +200 B·setIntValues:forParameter:count: +36 B, 나머지 메서드 크기 같음), 기록된 객체가 대체 경로로 읽는 나머지 Darwin 머리 — rec-stage 매니페스트의 37 개 중 지금 07 사본이 있는 12 개를 뺀 25 개(python; driverkit 16, src/driverkit 7, src/ipc/ipc_machdep.h, src/kern/parallel.h).

## 346. S5-P335 세부 계획 — 기록된 객체가 Darwin 대체 경로로 읽는 나머지 머리 25 개를 07 에 둠(자기 완결; D013·D021·D030; 코딩 전, 2026-10-06)

배경: stage_headers 는 07·SDK 에 없는 이름을 Darwin 에서 그대로 읽는다(매니페스트에 darwin01 출처로 남지만 mach/bsd_not_adopted 로는 잡히지 않음). rec-stage 매니페스트 213 개를 python 으로 훑으면 다른 아키텍처 분기를 뺀 Darwin 머리 37 개가 쓰였고, plan 344·345 뒤 07 사본이 없는 것이 25 개(plan 345 결과 절).

0. 대상(python, 모든 트리 find·SDK 실기 목록):
   - Darwin driverkit-1/driverkit 16(SDK·Mach4·NeXTMach 에 같은 이름 없음): EventInput.h, IOBufDevice.h, IODeviceKernPrivate.h, IODeviceParams.h, IOPower.h, KeyMap.h, SCSIDiskKern.h, SCSIGeneric.h, SCSIGenericPrivate.h, configTableKern.h, configTablePrivate.h, driverServer.h, i386/IOVPCodeDisplay.h, i386/driverServer.h, i386/vpCode.h, memcpy.h → `07_kernel/nextdev_private/driverkit/…` D030 사본(머리 주석만 교체).
   - Darwin kernel/driverkit 6(SDK·Mach4·NeXTMach 에 없음): KernBusInterrupt.h, KernBusInterruptPrivate.h, KernBusPrivate.h, KernDevicePrivate.h, KernLock.h, autoconfCommon.h → `07_kernel/src/driverkit/` D030 사본(대응 .m 들이 D030 작성, plans 304–306·332).
   - `KernStringList.h`: SDK 에 있음(/NextDeveloper/Headers/driverkit/KernStringList.h, 실기 목록 sha256 20d12c31…; Darwin 판 = 라이선스 블록 + SDK 바이트) → SDK 판 그대로 `07_kernel/src/driverkit/KernStringList.h`(KernStringList.m 의 quoted import 가 이 자리를 먼저 찾음; nextdev-os42 출처). (codex 지적으로 고침 — 처음엔 Darwin 전용으로 분류.)
   - `kern/parallel.h`: Mach4 에 없고 NeXTMach mk-108.1/kern/parallel.h 가 있음 → D022(비 BSD kern/·ipc/ 는 SDK, 없으면 Mach4 기본; Mach4 에 없어 NeXTMach) 에 따라 NeXTMach 판(고지 유지, D013)을 `07_kernel/src/kern/parallel.h` 로. Darwin 과의 차이: 첫 조건이 `KERNEL_BUILD` 대신 `defined(KERNEL) && !defined(KERNEL_FEATURES)`, else 쪽이 `<mach/features.h>` 대신 `<sys/features.h>`, `#else`/`#endif` 뒤 주석 표기. 이 빌드는 KERNEL 정의·KERNEL_FEATURES 미정의라 두 판 모두 `<cpus.h>` 를 씀 — 회귀로 확인.
   - `ipc/ipc_machdep.h`: Mach4 kernel/ipc/ipc_machdep.h 가 있음 → Mach4 판(고지 유지)을 `07_kernel/src/ipc/ipc_machdep.h` 로. 차이는 `defined(alpha)` 대 `defined(__alpha)` 뿐(i386 무관).
1. 회귀: 이 25 개 중 하나라도 Darwin 에서 읽은 기록 run 37 개(python; s5p155-it2 … s5p333-it1, EXPECT 출력 51) 전부를 다시 스테이징·같은 cmd 로 빌드(새 ID `-rg3`). 비교를 강화한 regress346.py: 섹션마다 segname·sectname·addr·size·align·flags·바이트·재배치, stab 아닌 기호마다 이름·type·sect·desc·value 가 같아야 하고, 스테이징·빌드·collect 실패나 EXPECT 누락은 실패로 셈, 끝에 전체 합격/불합격. 스테이징 차이 기준선: 같은 run 을 지금 07(변경 전)로 모의 스테이징한 목록 — 거기서 이번 25 개와 parallel.h 가 끌어오는 `src/bsd/sys/features.h` 말고 달라지면 실패(기록 당시 매니페스트와 지금의 차이 15 경로는 이전 계획들의 결과로 따로 적음).
2. 모의 스테이징으로 미리 확인: 25 개를 둔 07 사본에서 37 run 의 소스 closure 를 다시 만들어, Darwin 출처(다른 아키텍처 분기 제외)가 0 이 되는지, NeXTMach parallel.h 의 `<sys/features.h>` 가 07·SDK 로 풀리는지.
3. 기록: PROVENANCE·MODIFICATIONS 행(D030 23 개: 압축 파일 sha256; parallel.h: nextmach 커밋·경로; ipc_machdep.h: mach4 커밋·경로), 근거 문서 `06_reconstruction/evidence/x86-self-contained-headers-s5p346.md`(대상·회귀 결과).
4. 기록 표(functions·objects)는 바뀌지 않음(객체 바이트 같음이 조건).
5. 모의 스테이징 결과(코딩 전, scratchpad k07sim + Darwin 원문 사본): 37 run 모두 Darwin 머리(다른 아키텍처 분기 제외) 0. NeXTMach parallel.h 를 쓰는 11 run(모두 C 소스)의 closure 에 `src/bsd/sys/features.h`(07_kernel/nextmach 사본)가 새로 들어오고, 그것이 읽는 `machine/DEFAULT.h` 가 새 미해결(KERNEL_FEATURES 분기 — 이 빌드에서는 쓰이지 않음). `generated/sun_nfs.h` 는 원래 meta_features.h 로 들어오던 것(처음에 새것으로 잘못 적음).

### codex 교차검토 판정(2026-10-06, plan 346, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| KernStringList.h 는 SDK 에 있음(실기 목록·sha, Darwin = 라이선스 + SDK 바이트) | python: 목록에 있음, sha 20d12c31… 일치, Darwin 판이 SDK 바이트로 끝남 | ✅ 채택 — 0 항 고침(내 앞선 확인은 driverkit-1 쪽만 SDK 를 봤음) |
| 나머지 24 개는 다른 이름·경로 대응판 없음(SDK machine/driverServer.h 는 ARCH_INCLUDE 껍데기) | 내 find·SDK 목록(앞서), src/driverkit 12 개 SDK 대조 | ✅ |
| 정책 근거는 D022 가 더 정확 | DECISIONS D021·D022 문구 | ✅ 채택 — 문구 |
| 자리·해석 경로(mach_pick·prefer07; kern/ 은 bsd_pick 밖) | stage_headers.py select()/MACH_MAP 읽음(앞서), 모의 스테이징 | ✅ |
| parallel.h 두 판 모두 cpus.h; 11 소비 run 은 모두 C | s5p110-diag6.cmd 정의(KERNEL·KERNEL_BUILD), 내 37 run 목록 | ✅ |
| ipc_machdep.h 는 alpha/__alpha 만 | diff(앞서) | ✅ |
| features.h 가 새로 들어오고 machine/DEFAULT.h 가 새 미해결; sun_nfs.h 는 원래 있던 것 | features.h:21 `#import <machine/DEFAULT.h>`, meta_features.h:49 `#import <sun_nfs.h>` | ✅ 채택 — 5 항 고침 |
| 기록 매니페스트와 지금 closure 사이에 이미 15 경로 차이 — 기준선을 변경 전 closure 로 | (회귀 때 확인) | ✅ 채택 — 1 항 |
| 37 run 모두 표준 옵션, EXPECT 51 | 내 python(특수 옵션 없음 확인); 51 은 회귀 스크립트가 셈 | ✅ / 51 은 실행 때 확인 |
| regress 비교 강화(addr·align·flags·desc), 실패를 실패로 | regress345.py 읽음 — 반환 코드 안 봄 | ✅ 채택 — regress346.py |
| rec-stage 매니페스트는 지금 221 개 | (plan 345 기록으로 늘어남) | ✅ |


### 결과(2026-10-06, plan 346)

- 07: D030 사본 22, SDK KernStringList.h 1, NeXTMach parallel.h 1, Mach4 ipc_machdep.h 1(고정 커밋 blob 대조). mkhdr 고지 검사 통과.
- 회귀(scratchpad regress346.py, `*-rg3`): 37 run·EXPECT 51. 변경 전 closure 기준선(`p346/baseline.json`) 대비 스테이징 차이는 허용 26 경로 안(25 + `src/bsd/sys/features.h`). 객체 50/51 이 섹션(addr·align·flags·바이트·재배치)·stab 아닌 기호(desc 포함)까지 같음. 예외 s5p155-it2 sys_generic(F·N): 정적 지역 기호 이름 번호만 `_flags.110`→`_flags.112`(type·sect·value 같음), 섹션 바이트·재배치 같음, 다시 만든 F 의 L1 OBJECT_MATCH, 원본 기호표에 번호 붙은 정적 지역 기호 0 개 → 원본과 대조할 수 있는 차이 아님, 받아들임(근거 문서에 적음).
- 기록: PROVENANCE 911→936(+25), MODIFICATIONS 408→432(+24 = D030 22 + NeXTMach 1 + Mach4 1; SDK 사본은 선례대로 행 없음). 근거 `06_reconstruction/evidence/x86-self-contained-headers-s5p346.md`. functions·objects 표 변화 없음.
- 이로써 rec-stage 매니페스트 기준 Darwin 대체 경로 머리(다른 아키텍처 분기 제외) 0.

## 347. S5-P336 세부 계획 — libDriver `Kernel/IOFrameBufferDisplay.m`(D024·D027·D030·D031·D032; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): Darwin 0.1 driverkit-1/libDriver/Kernel/IOFrameBufferDisplay.m 만 있음 → D030. 머리: driverkit/IOFrameBufferShared.h(Darwin 만, SDK 없음) → D030 사본, bsd/dev/i386/FBConsole.h(Darwin kernel 만, SDK 없음) → D032 사본(`nextdev_private/bsd/dev/i386/`).

0. 원본(진단 l1, python): `__text` [0x1c2388, 0x1c52f2) 12138 B·29 함수(정적 StdFBDisplayCursor16 1068·Cursor8 876·Cursor32 764 + 메서드 26), 뒤 2 B 채움 → IOSVGADisplay 0x1c52f4. `__DATA,__data` 4 B(L1d), `__bss` 없음.
1. 진단(scratchpad `bus/IOFrameBufferDisplay/wip.m`): Darwin 그대로는 `IOClassFramebuffer` 미정의로 실패(`s5p347-fbc1`); 원본 메서드 목록에 없는 두 메서드를 빼면 배치 못 함(`fbd1`: getIntValues +200 B·setIntValues +36 B); 아래 ③④ 뒤 `fbe1`(Cursor8 +16 B), ⑤ 뒤 `fbf1`(Cursor8 크기는 같고 4 바이트 다름 — 0x1c2ac5 에서 첫 분기 결과를 `mov dl,cl` 로 레지스터에 둠), ⑥ 뒤 `fbg1` **OBJECT_MATCH**.
2. 수정(plan 347 표시; ②–⑥ 은 원본 명령·메타데이터가 요구, ⑥ 의 map32to256 정의 삭제는 선택적 정리):
   ① (적용 안 함) `unMapFrameBuffer:length:` 는 Darwin 에서 이미 `#if 0`(1262–1352 행) 안 — 바이트 무관, 07 본문은 Darwin 그대로 둠(codex 지적; 진단 본문에서는 지웠음).
   ② `property_IODeviceClass:length:` 삭제(같음; IOClassFramebuffer 를 쓰는 유일한 곳).
   ③ getIntValues:forParameter:count: 의 `IO_SET_PENDING_DISPLAY_MODE`(strncmp·find_parameter·strtol) 분기 삭제 — 원본의 strncmp 는 둘 다 "IOGetDisplayModeInfo:".
   ④ setIntValues:forParameter:count: 의 `STDFB_BM38_TO_BM256_MAP` 분기: “논리 팔레트 256 B 확장”(크기 두 가지·채움 루프) 없이 `count != STDFB_BM38_TO_BM256_MAP_SIZE` 면 오류, 없으면 `IOMalloc(STDFB_BM38_TO_BM256_MAP_SIZE * sizeof(int))`(원본 0x400), int 단위 복사(원본 0x1c4317–0x1c435e).
   ⑤ map32to256 의 마지막 변환 `directToLogical[logicalValue + 1024]` 없음(원본 Cursor8 에 두 번째 표 조회 없음).
   ⑥ 그 계산을 StdFBDisplayCursor8 안에서 `dst` 에 바로 대입(원본은 두 분기 모두 dst 의 스택 자리 [ebp-0x24] 에 저장 — inline 함수 반환으로는 첫 분기가 레지스터에 남음). 쓰이지 않게 된 map32to256 정의는 07 본문에서 뺌(바이트 무관).
   이 원문 꼴은 원본 바이트를 재현하는 재구성(실제 4.2 원문이 이 꼴이었다는 증명은 아님).
3. 07 배치: `src/driverkit/libDriver/Kernel/IOFrameBufferDisplay.m`(mkfinal D030 머리), 머리 2 개(위). 이 둘이 활성 i386 구성이 더 요구하는 머리의 전부; closure 는 조건을 평가하지 않아 꺼진 분기(ppc·NCPUS>1·비 KERNEL_BUILD 등)의 파일·미해결 이름도 담음.
4. 빌드·검사: `iter_objc.py s5p347-it1 driverkit/libDriver Kernel/IOFrameBufferDisplay.m IOFrameBufferDisplay`(EXTRA_DEFS=-DMACH_USER_API) → relcheck → record_objc. 두 머리를 기록된 다른 run 이 Darwin 에서 읽었으면 회귀.
5. 예상: A, 12138 B.

### codex 교차검토 판정(2026-10-06, plan 347, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 진단 본문 차이는 여섯 수정뿐, fbg1 스테이징 소스와 같은 바이트 | 내 diff(Darwin 대 wip, 9 묶음) | ✅ |
| ① unMapFrameBuffer 는 이미 `#if 0` 안 — 바이트가 요구하지 않음 | awk: 1262 `#if 0`, 1352 `#endif 0` | ✅ 채택 — ① 적용 안 함 |
| ③ 원본 getter 의 strncmp 둘 다 "IOGetDisplayModeInfo:" | 내 odis3(0x1c3f2a·0x1c3f71) | ✅ |
| ④ BM38 분기 0x100 검사·IOMalloc(0x400)·int 복사, 확장 없음 | 내 odis3(0x1c4317–0x1c435e) | ✅ |
| ⑤⑥ Cursor8 두 분기 모두 [ebp-0x24] 저장, 마지막 표 조회 없음; fbf1 은 4 바이트 차이(크기 같음) | 내 odis3(0x1c2ac5·0x1c2adc)·fdis | ✅ 문구 고침 |
| L1: OBJECT_MATCH·29 함수·12138 B·data 4 B | 내 l1(fbg1 json) | ✅ |
| 쓰이지 않는 map32to256 은 빼도 됨(-g 기록·전체 해시는 바뀔 수 있음, 최종 L1 로 확인) | — | ✅ 채택 — 빼고 최종 빌드로 확인 |
| 머리 둘의 자리·부재 확인; closure 문구 한정 | 내 find·SDK 목록·모의 스테이징 | ✅ 문구 고침 |
| “재구성이지 원문 증명 아님” 유지 | — | ✅ |

### 결과(2026-10-06, plan 347)

- 07: `src/driverkit/libDriver/Kernel/IOFrameBufferDisplay.m`(D030 머리; ②–⑥ 적용, ① 은 Darwin 그대로(`#if 0`), map32to256 정의 뺌), 머리 `nextdev_private/driverkit/IOFrameBufferShared.h`(D030)·`nextdev_private/bsd/dev/i386/FBConsole.h`(D030/D032).
- 빌드 `s5p347-it1`(07, RUNIN, `-DMACH_USER_API`): **OBJECT_MATCH**(29 MATCH, `__text` 12138 B, `__data` 4 B L1d), relcheck 0, 매니페스트 미채택·Darwin 머리 0 → **A**.
- 기록(python 대조): functions.tsv 3717→3746(+29), objects_confirmed 264→265, PROVENANCE 936→939(객체 + 머리 2), MODIFICATIONS 432→435.
- 범위(python): 이번 12138 B. 누적 A 264 객체 513695 B(60.33%), P 67 객체 206879 B(24.30%), A+P **84.63%**(남은 130862 B).

## 348. S5-P337 세부 계획 — 커널 MIG 서버 4 개(`mach/exc_server.c`·`mach_host_server.c`·`mach_port_server.c`·`mach_server.c`; 4.2 SDK .defs; 코딩 전, 2026-10-06)

참조: 입력 .defs 는 4.2 SDK `mach/exc.defs`·`mach_host.defs`·`mach_port.defs`·`mach.defs`(실기 목록 대조; Darwin·Mach4·NeXTMach 판을 쓰지 않음 — D022 SDK 우선). 생성 규칙은 Darwin kernel `conf/Makefile.template`(MACH·MACH_HOST 는 `mig -typed -MD $(MIGKSFLAGS)` = `-DKERNEL -DKERNEL_SERVER`, MACH_PORT 는 `mig -untyped -MD $(MIGKSFLAGS)`(601 행), `-server X_server.c`; EXC 는 `mig -MD $(MIGFLAGS) -header exc.h -server exc_server.c` = `-DKERNEL` 만, `-typed` 없음), 소스 목록 `conf/files:487–490 ./mach/*_server.c standard`.

0. 원본(진단 l1, python): exc_server [0x16df30, 0x16e030) 256 B·2 함수(`__TEXT,__const` 28 B); mach_host_server [0x16e030, 0x16efc8) 3992 B·36; mach_port_server [0x16efc8, 0x16f950) 2440 B·21; mach_server [0x16f950, 0x171248) 6392 B·57. 합 13080 B. `__DATA,__data`: 392·264·900 B. 그 뒤 [0x171248, 0x171cb4) 2668 B 는 mach_debug_server 영역(루틴 표 0x1e07d0 의 처리기 9 개 + `_mach_debug_server`·`_routine`) — SDK 에 mach_debug.defs 가 없어 이 계획 밖.
1. 진단(07 아님): MIG `s5p348-migd1`(SDK .defs 9 개 + 07 generated): `-typed -newipc -DKERNEL -DKERNEL_SERVER` 로 mach_host(`s5p348-machhost1`)·mach_port(`machport1`)·mach(`mach1`) **OBJECT_MATCH**; `-newipc` 없이는 mach_port.defs 가 MIG 오류(새 IPC 전용 형). exc 는 같은 꼴로 259 B·DIFF(`exc1`), Darwin 규칙 그대로 `-DKERNEL` 만(`-newipc`·`-typed`·KERNEL_SERVER 없음, `s5p348-migd2` b_)으로 **OBJECT_MATCH**(`excb1`, 256 B); `-newipc -DKERNEL` 판(a_)은 KERNEL_SERVER 판과 같은 출력.
   `-newipc` 는 plan 344 와 같은 근거(Darwin Makefile 에 글자로 없음, 원본 바이트가 요구). KernelServer 조건은 .defs 마다 다름: mach.defs·mach_host.defs 는 `KERNEL_SERVER && defined(NEW_MACH_IPC)`, mach_port.defs 는 `KERNEL_SERVER` 만(그러나 새 IPC 형이라 `-newipc` 없이는 MIG 오류), exc.defs 는 KernelServer 선언 없음(KernelUser 만) — exc 의 `-newipc` 판은 mach_msg_header_t·mach_port_t 꼴, 맞는 판은 msg_header_t·port_t 꼴. 맞는 생성 조합이지 원래 명령줄의 증명은 아님.
2. 07 배치: `src/mach/{exc,mach_host,mach_port,mach}_server.c` = MIG 출력 그대로(generated-mig, plan 343·344 와 같은 방식). MIG run `s5p348-mig1`: 스테이징 `08_build/runs/tools/s5p348-stage-mig.py`(SDK .defs 8 + ARCH_INCLUDE.h 실기 목록 대조 + 07 generated), 네 출력 + 반복(r_)·`-nostdinc`(n_) 판이 같아야 하고 진단 출력과 같은 바이트여야 함(서버 C 는 -header 이름을 include 하지 않음 — codex·내 grep). mach_port 는 Darwin 규칙대로 `-untyped` 로 만들고 `-typed` 판과 같은지 비교(다르면 바이트로 정함). generated/README 에 재생성 줄.
3. 모의 스테이징(07 사본 + 생성 C): 활성 i386 구성에서 07 밖 머리 0, 새 미해결 0(closure 문자 그대로는 꺼진 분기의 Darwin machdep/machine·ppc 머리 10 개와 기존 미해결 9 개를 담음 — 기존 빌드와 같음). mach/bsd 미채택 0.
4. 빌드·검사: kernel C 꼴 `iter.py s5p348-<약칭>1 mach/<X>_server.c <X>_server LO HI` → relcheck → record_object(generated-mig).
5. 예상: 4 객체 A, 13080 B(text 함수 116).

### codex 교차검토 판정(2026-10-06, plan 348, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| Darwin 규칙의 mach_port 는 `-untyped` | Makefile.template:601 읽음 | ✅ 채택 — 0 항·2 항 고침 |
| 네 객체 OBJECT_MATCH·범위·크기·함수 116; exc1 은 불일치 | 내 l1 json(앞서)·python | ✅ |
| KernelServer 조건이 .defs 마다 다름(mach_port 는 KERNEL_SERVER 만, exc 는 없음) | mach_port.defs:64–67·exc.defs:72–75·mach_host.defs:129–131 읽음 | ✅ 채택 — 1 항 고침(내가 일반화해 잘못 적음) |
| exc 의 맞는 판은 옛 IPC 꼴(msg_header_t·port_t) | b_exc_server.c(앞서 diff) | ✅ |
| 서버 C 는 -header 이름을 include 하지 않고 고지·날짜·경로 없음 | 내 grep(#include 목록) | ✅ |
| closure 문자 그대로는 꺼진 분기의 07 밖 파일 10 개 | 기존 빌드와 같은 꼴(plan 345·347 과 같음) | ✅ 문구 고침 |
| mach_debug 영역은 처리기 9 + 디스패치 2, 2668 B | 내 python(원본 표 0x1e07d0 읽음, 11 함수 시작) | ✅ 문구 고침(“정적 셋”은 틀림) |
| SDK 입력은 .defs 8 + ARCH_INCLUDE.h | 진단 스테이징 목록 | ✅ 고침 |
| 기록에 입력·도구 해시·명령·생성물 해시, SDK .defs 의 CMU 고지는 따로 | — | ✅ 기록 때 반영 |

### 결과(2026-10-06, plan 348)

- MIG: `s5p348-mig1` 은 mach_port 를 Darwin 규칙의 `-untyped` 로 만들다 실패(4.2 mig 래퍼가 `-untyped` 를 cpp 로 넘겨 ARCH_INCLUDE·natural_t 가 깨짐 — 래퍼 `-* ) cppflags` 분기) — 버린 run. `s5p348-mig2`: exc(`-DKERNEL` 만)·mach_host·mach_port·mach(`-typed -newipc -DKERNEL -DKERNEL_SERVER`) 네 출력이 반복·`-nostdinc` 판·진단 출력과 같은 바이트. 07 `src/mach/{exc,mach_host,mach_port,mach}_server.c`(MIG 출력 그대로), generated/README 줄.
- 빌드(iter.py, kernel C 꼴): `s5p348-ex1`·`mh1`·`mp1`·`mc1` 모두 **OBJECT_MATCH**, relcheck 0, 미채택 0 → **A** 4.
- 기록(python 대조): functions.tsv 3746→3862(+116 = 2+36+21+57), objects_confirmed 265→269, PROVENANCE 939→943, MODIFICATIONS 435→439.
- 범위(python): 이번 13080 B. 누적 A 268 객체 526775 B(61.87%), P 67 객체 206879 B(24.30%), A+P **86.17%**(남은 117782 B).

## 349. S5-P338 세부 계획 — 커널 MIG 서버 `mach_debug/mach_debug_server.c`(처음 제안은 Darwin 0.1 판 — 아래 “349 수정 계획”(Mach4 바탕)으로 대체됨; D013·D022·D024; 코딩 전, 2026-10-06)

참조(파일명, 모든 트리): mach_debug.defs·mach_debug_types.defs 는 Mach4(include/mach_debug)·NeXTMach(mk-108.1/kern)·Darwin(kernel/mach_debug) 에 있음, 4.2 SDK 에 없음. 생성 규칙 Darwin kernel `conf/Makefile.template:607–619`(`-header mach_debug.h -server mach_debug_server.c`, MIGKSFLAGS), `conf/files:491 ./mach_debug/mach_debug_server.c optional mach_debug`.

0. 원본(python): 영역 [0x171248, 0x171cb4) 2668 B — 함수 11(처리기 9 + `_mach_debug_server` 0x171838·`_mach_debug_server_routine` 0x1718b0), 마지막 처리기 끝 뒤 00 채움. 서버는 msg_id 3000(0xbb8)부터 0x15 까지(22 칸) 검사, 루틴 표 0x1e07d0 의 비어 있지 않은 칸 5·6·7·8·9·10·11·14·15.
1. 판 선택: Darwin 판의 표 칸 5–15 가 원본과 같음(6 = host_zone_free_space_info — Mach4 판에는 없음, 그 자리 skip), Darwin 은 22–26(host_machine_info·vm_reallocate·host_zone_collect·host_vm_region·enable_bluebox)이 더 있음. Mach4 판은 6 번을 새로 작성해야 하고 16–21 을 설정 매크로로 꺼야 함 → Darwin 판을 바탕(같은 디렉터리의 07 hash_info.h·ipc_info.h 가 Darwin 판·고지 유지로 들어온 선례, plan 22·60.1). NeXTMach 판은 옛 꼴(kern/ 경로, MACH_IPC_STATS)이라 쓰지 않음.
2. 진단(07 아님): `s5p349-migd1`(Mach4·Darwin 그대로, 둘 다 루틴 16); Darwin 1–199 행(`migd2`)은 host_zone_info 만 +8 B(`md1`); 거기에 mach_debug_types.defs 의 `zone_name_t = struct[20] of natural_t` 를 Mach4 꼴 `struct[80] of char` 로 바꾸면(`migd3`) **OBJECT_MATCH**(`s5p349-md2`, 11 MATCH, `__text` 2665 B → [0x171248, 0x171cb1), 뒤 00×3). 명령 `mig -typed -newipc -arch i386 -Isrc/generated -Isrc/nextdev -Isrc/<defs root> -DKERNEL -DKERNEL_SERVER`(plan 348 과 같은 꼴; `-newipc` 근거 같음).
3. 07 배치(darwin01, APSL·NeXT·CMU 고지 유지, 수정 줄 plan 349 표시, PROVENANCE·MODIFICATIONS):
   - `src/mach_debug/mach_debug.defs`: Darwin 1–199 행 + 끝에 plan 349 주석(22–26 번 루틴 없음 — 원본 표 22 칸).
   - `src/mach_debug/mach_debug_types.defs`: zone_name_t 한 줄을 `struct[80] of char` 로(원본 host_zone_info 크기가 요구; Mach4 와 같은 꼴).
   - `src/mach_debug/mach_debug_server.c`: MIG 출력 그대로(generated-mig). MIG run `s5p349-mig1`(스테이징 스크립트 `08_build/runs/tools/s5p349-stage-mig.py`: 07 .defs 2 + SDK 5 + 07 generated), 반복·`-nostdinc` 판 비교.
   - 서버 C 가 읽는 Darwin 머리 mach_debug_types.h·zone_info.h·host_machine_info.h(진단은 Darwin 대체 경로): 같은 디렉터리 선례대로 Darwin 판 그대로(고지 유지, darwin01) 07 에 둠 — Mach4 판(mach_debug_types.h·zone_info.h)으로 바꾸는 것은 바이트 영향 확인이 필요하므로 이 계획에서는 하지 않음; codex 의견 확인.
4. 빌드·검사: kernel C 꼴 `iter.py s5p349-it1 mach_debug/mach_debug_server.c mach_debug_server 0x171248 0x171cb4` → relcheck → record_object(generated-mig). 새 머리를 이미 기록된 run 이 Darwin 에서 읽었으면 회귀.
5. 예상: A, 2665 B.

### codex 교차검토 판정(2026-10-06, plan 349, gpt-6.1-sol) — 판 선택을 Mach4 바탕으로 바꿈

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 원본 표(3000–3021, 22 칸, 채운 칸 5–11·14–15)와 Darwin 대응; 199 행에서 자르는 것이 최소 | 내 python(0x1e07d0 읽음)·migd 표 비교(앞서) | ✅ |
| md2 OBJECT_MATCH; zone_name_t 형은 MIG 기술자(name 8·size 8·count 2000)와 곱셈 코드를 바꿈 — 원본 기술자 0x1e0710 도 그 값 | 내 l1(md2) | ✅(기술자 해석은 codex 수치, 기록에 넣지 않음) |
| D022 는 SDK 에 없는 Mach 이름에 Mach4 를 기본 참고로, Darwin 은 구조 참고로 정함 — 같은 디렉터리 선례는 새 Darwin 채택의 근거가 아님; Mach4 바탕이 맞음 | DECISIONS.md:26 D022·:28 D024 원문 읽음 | ✅ 채택 — 내 근거가 규칙에서 벗어났음 |
| Mach4 바탕에서 16–21 을 끄려고 MACH_IPC_DEBUG=0 을 쓰면 7–11 도 사라짐 — 선택적 skip 필요 | Mach4 defs 64·188 행 조건 읽음 | ✅ 채택 — 16–21 블록을 skip 6 줄로 바꿈 |
| C 머리: 두 판 모두 zone_name_t 는 char[80], zone_info_t 배치 같음; Mach4 판에는 free-space 구조체가 없어 더해야 함; host_machine_info.h 는 Mach4 umbrella 로 피할 수 있음; 기록된 run 은 세 머리를 안 읽음 | Darwin zone_info.h:85 이후 읽음, Mach4 mach_debug_types.h import 목록 | ✅ |
| 처리기 14 + 디스패치 2(“루틴 16”이 아님); Darwin 규칙은 `-untyped`(615 행); 래퍼는 -typed/-untyped 를 cpp 로 넘김 | Makefile 은 plan 348 에서 같은 꼴 확인 | ✅ 문구 고침 |

새 방향(코딩 전 진단 `s5p349-migd4`·`md4`): Mach4 mach_debug.defs(6 번 skip → host_zone_free_space_info 루틴 작성, 16–21 → skip 6), Mach4 mach_debug_types.defs(+ free-space 형 4 줄), C 머리 Mach4 mach_debug_types.h·vm_info.h·zone_info.h(+ free-space 구조체). 작성 줄은 D024 표시, 구조는 Darwin 참고. 결과에 따라 이 절을 다시 고쳐 codex 2 차 검토.

### 349 수정 계획(codex 1 차 판정 반영, Mach4 바탕; 코딩 전)

- 진단 `s5p349-migd4`(MIG)·`s5p349-md4`(빌드): 아래 입력으로 **OBJECT_MATCH**(11 MATCH, `__text` 2665 B [0x171248, 0x171cb1)). Mach4 다섯 파일은 고정 커밋 69fa7787 blob 과 같음(python, verify_pinned).
- 07 배치(mach4 출처, CMU·Mach4 고지 유지, 작성 줄은 D024 표시 “plan 349”, 구조는 Darwin 0.1 참고라고 적음):
  - `src/mach_debug/mach_debug.defs`: Mach4 include/mach_debug/mach_debug.defs + ① 6 번 `skip; /* host_ipc_bucket_info */` 자리에 `routine host_zone_free_space_info(host; out info: zone_free_space_info_array_t, CountInOut, Dealloc; out chunks: zone_free_space_chunk_array_t, CountInOut, Dealloc)` 작성(원본 표 칸 6 = 0x17141c 처리기), ② 16–21 의 조건부 블록을 `skip;` 6 줄로(원본 표 칸 16–21 비어 있음; MACH_IPC_DEBUG 로 끄면 7–11 도 사라지므로 선택적).
  - `src/mach_debug/mach_debug_types.defs`: Mach4 판 + free-space 형 4 줄(zone_free_space_info_t = struct[3] of integer_t 등). zone_name_t 는 Mach4 그대로 `struct[80] of char`(원본 기술자와 맞음).
  - C 머리: `src/mach_debug/mach_debug_types.h`·`vm_info.h` = Mach4 그대로; `src/mach_debug/zone_info.h` = Mach4 + free-space 구조체 2 개(작성, 구조 Darwin). ipc_info.h·hash_info.h 는 07 기존 판(plan 22·60.1) 그대로. host_machine_info.h 는 필요 없음.
  - `src/mach_debug/mach_debug_server.c`: MIG 출력 그대로(generated-mig). MIG run `s5p349-mig1`(스테이징 스크립트가 07 .defs 2 + SDK 5 + 07 generated 를 둠), `-typed -newipc -arch i386 -Isrc/generated -Isrc/nextdev -Isrc/src -DKERNEL -DKERNEL_SERVER`, 반복·`-nostdinc` 판 비교, 진단 출력과 같은 바이트.
- 회귀: 기록된 run 의 rec-stage 매니페스트에 이 머리들을 읽은 것이 있으면(codex: 0) 회귀. zalloc.c 진단은 mach_debug/zone_info.h 를 읽으므로 이 계획 뒤에 07 판으로 다시 함.
- 빌드·검사·기록은 위 4·5 항 그대로.

### codex 2 차 교차검토 판정(2026-10-06, 349 수정 계획, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| md4 입력은 Mach4 대비 열거한 수정뿐; 생성 표 22 칸·채운 칸 5–11·14–15, 칸 6 → 0x17141c | 내 verify_pinned(Mach4 다섯 파일)·diff 줄 수(89·7·16)·원본 표 python(앞서) | ✅ |
| md4 OBJECT_MATCH(11 함수, text 2665, data 292) | 내 l1(md4.json) | ✅ |
| 머리: Mach4 mach_debug_types.h·vm_info.h, 수정 zone_info.h, 07 ipc_info.h·hash_info.h; 섞여도 이 서버에는 바이트 영향 없음 | md4 매니페스트·OBJECT_MATCH | ✅ |
| 매니페스트의 07 출처 표기는 모의(07 사본) 경로 — 07 에는 아직 없음 | diag.py 가 K07 을 사본으로 바꿔 부름(내 스크립트) | ✅ 기록에 적음 |
| 작성 블록 전체(포인터 typedef 포함)에 표시·원본 주소·Darwin 구조 참고 기록 | 초안 p349/*: 블록마다 plan 349 (D024) 주석 | ✅ |
| `-Isrc/src` 와 입력 `src/src/mach_debug/mach_debug.defs` | kr_run 이 stage 를 run 의 src/ 로 복사(앞선 run 들) | ✅ 채택 |
| SDK 입력은 .defs 4 + ARCH_INCLUDE.h | 스테이징 스크립트 FILES | ✅ |
| 앞선 Darwin 바탕 제안을 대체로 표시 | — | ✅ 제목 고침 |
| 기록된 run 226 개 중 세 머리를 읽은 것 0 | (plan 349 1 차에서 같은 결론) | ✅ |

### 결과(2026-10-06, plan 349)

- 07: `src/mach_debug/mach_debug.defs`·`mach_debug_types.defs`·`zone_info.h`(Mach4 + plan 349 작성 줄), `mach_debug_types.h`·`vm_info.h`(Mach4 그대로), `mach_debug_server.c`(MIG 출력 그대로). 스테이징 `08_build/runs/tools/s5p349-stage-mig.py`. 진단 매니페스트(s5p349-md*)의 07 출처 표기는 07 사본(scratchpad) 경로 — 07 에 실제로 둔 것은 이 기록 때.
- MIG `s5p349-mig1`(첫 launch 는 실기 연결 실패로 시작 안 됨, 같은 ID 로 다시 launch): 본·r_·n_(-nostdinc)·진단 migd4 네 판 같은 바이트.
- 빌드 `s5p349-it1`(iter.py, kernel C 꼴): **OBJECT_MATCH**(11 MATCH, text 2665 B, data L1d), relcheck 0, 미채택 0, mach_debug 머리 모두 07 → **A**.
- 기록(python 대조): functions.tsv 3862→3873(+11), objects_confirmed 269→270, PROVENANCE 943→949(객체 + 파일 5), MODIFICATIONS 439→445.
- 범위(python): 이번 2665 B. 누적 A 269 객체 529440 B(62.18%), P 67 객체 206879 B(24.30%), A+P **86.48%**(남은 115117 B).

## 350. S5-P339 세부 계획 — 커널 `kern/zalloc.c`(Mach4 바탕, D044·D022·D024; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): `zalloc.c` 는 Mach4 `kernel/kern/zalloc.c`(971 행, 고정 커밋 69fa7787 blob 과 SHA-256 a35adc87… 같음)·NeXTMach `mk-108.1/kern/zalloc.c`·Darwin 0.1 `kernel/kern/zalloc.c` 에 있음. 07 `src/kern/zalloc.h` 는 Darwin 판 그대로(앞선 계획) — zone 구조체(lock_ipl·last_insert·pageable 등 비트 필드·free_space)가 4.2 원본 코드와 맞음.

0. 원본(python): 영역 [0x16a360, 0x16c1c4) 7780 B, 전역 함수 19 + static 3(심볼 없음: 0x16a360 zone_free_space_lookup, 0x16af6c zone_free_space_select, 0x16b364 zalloc_canblock — 빌드 객체의 위치로 확정), 끝 1 B 00 채움(0x16c1c3). `__data` 168 B(0x1dfce8): zone_ignore_overflow=1, zone_map=0, zone_map_size=0xc00000, zdata_size=0x69000, 문자열, zone_check=0, zone_gc_allowed=1, zone_gc_last_tick=0, zone_gc_max_rate=0.
1. 4.2 꼴(진단으로 확정): Darwin 판과 비교해 ① zone_map_size 는 초기값 12 MB(zone_map_sizer 없음), ② zget_space 는 kmem_alloc_zone 실패 시 panic 없이 0, ③ zone_free_space_reclaim 은 void 이고 스스로 zget_space_lock 을 풀고 모은 페이지를 kmem_free, ④ host_zone_collect 없음, ⑤ 전역 zone_gc(전 zone 의 zone_collect 뒤 reclaim)·consider_zone_gc·zone_reclaim 있음, ⑥ zdata_size 0x69000(python: 430080 = 420 × 1024 — Mach4 원문 값과 같음), ⑦ host_zone_free_space_info 는 `actual1 < *infoCnt` 일 때 info 버퍼를 새로 잡음(원본 0x16be9b `jbe`; Darwin 은 `>`), ⑧ MACH_OLD_VM_COPY=1(07 generated) → host_zone_info 등은 vm_move 경로.
2. 진단(07 아님, scratchpad): `s5p350-x1`(Darwin 판에 1 의 차이를 넣은 dw2) **OBJECT_MATCH**(22 MATCH, text 7779 B, data 차이 0). 이어 Mach4 바탕 초안 z4 `s5p350-z4a1` **OBJECT_MATCH**(22 MATCH, Darwin 대체 경로 EXTRA_ROOTS 없이), 비-stab 심볼표 68 개가 x1 과 같음.
3. 07 배치: `src/kern/zalloc.c` = Mach4 원문(CMU·Utah 고지 유지) 바탕, 수정·작성 줄에 `plan 350` 표시(103 행), 파일 머리에 plan 350 설명 주석. python difflib(물리 행, codex 판정 반영 뒤 초안): Mach4 971 행 중 593 행 유지, 378 행 제거, 1072 행 추가(초안 1665 행).
   - Mach4 그대로 쓰는 부분: 고지·머리말, include 목록(+ `<mach_old_vm_copy.h>`, plan 267 선례), zone_zone·zone_ignore_overflow·zone_map·zone_map_size·zdata·zdata_size, all_zones_lock 등, zcram·zget·zfree·consider_zone_gc 본문(zone_count_up → count++ 만), host_zone_info 대부분(zi_* 필드·MACH_OLD_VM_COPY 갈래만 고침), zone_check, zone_gc_* 변수.
   - 제거(원본에 없음): zone_page_table 과 zone_page_* 5 함수·zone_add_free_page_list(모두 6 함수), zalloc_next_space 등 3 변수, Mach4 zone_gc 본문, zone_init 의 페이지 표 설정, zalloc 의 check_simple_locks()(07 lock.h 에서 MACH_SLOCKS 일 때 정의 없음; plan 264 선례)와 ZONE_COLLECTABLE 갈래.
   - 작성(D024, 원본 바이트에서; 구조는 Darwin 0.1 참고, 주석은 새로 씀): ADD_TO_ZONE(주소순 삽입·last_insert)·REMOVE_FROM_ZONE 의 last_insert 줄, zone_lock 3 매크로 본문(pageable·splhigh/lock_ipl), free-space 구조체 3·전역(zone_free_space[8] 등)·인라인 도우미·hint 함수, zone_free_space_lookup·add·collect·reclaim·alloc·select, zget_space 의 풀 할당 부분(`space_to_add` 의 `= 0` 초기화도 뺌 — 남기면 8 B 늘어 NOT_MATCH, `s5p350-z4b1`), zone_bootstrap 의 풀 설정, zalloc_canblock(Mach4 zalloc 본문을 canblock 판으로 고침)·zalloc·zalloc_noblock, zcollectable·zchange, zone_gc 본문, zone_reclaim, host_zone_free_space_info(MACH_OLD_VM_COPY 갈래만 — 원본이 요구하는 꼴).
   - 주석의 원본 주소 14 개(13 행)는 python 표(빌드 객체 위치 + 0x16a360 = 원본 심볼표)와 대조.
4. 빌드·검사: kernel C 꼴 `iter.py s5p350-it1 kern/zalloc.c zalloc 0x16a360 0x16c1c4` → relcheck → 공통 심볼 확인(F 객체에 `__bss` 없음 — zerofill_check 대상 아님; 36.1 절차대로 이름별 원본 `__common` 주소와 크기 ≤ 다음 심볼까지 간격을 python 으로 확인, 13/13 통과·합 116 B·범위 128 B [0x1f6db0, 0x1f6e30); 공통 심볼 13 개: zone_zone·zone_min·zone_max·zdata·zget_space_lock·zone_free_space·zone_free_space_count·_zone_default_space_hint·_zone_default_space·all_zones_lock·first_zone·last_zone·num_zones) → record_object(fn_source: 원본에 Mach4 같은 이름이 없는 11 함수와 `_zget_space`(줄 찾기가 158 행 원형을 잡으므로 정의 행으로) 지정; PROVENANCE 행 mach4 + plan 350 설명, MODIFICATIONS, evidence x86-zalloc.md/.diff, functions.tsv). 스테이지에 07 밖 머리가 실제로 읽히면 plan 346 방식으로 처리.
5. 예상: A(공통 심볼은 앞선 커널 객체와 같이 이름·간격 확인으로 인정). 객체 `__text` 7779 B, 범위 집계는 끝 00 1 B 포함 7780 B.

### codex 교차검토 판정(2026-10-07, plan 350, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 7780 B = text 7779 + 00 1 B, `__data` 168 B @0x1dfce8 초기값, 0x69000 = 430080 | 내 python(이미지 0x16c1c3 = 00, `__data` 8 값, 420×1024) | ✅ |
| 전역 19 + static 3, 공통 13, 비-stab 68, x1·z4a1 심볼표 같음 | 내 python(심볼표·두 객체 비교) | ✅ |
| 583/389/1073 은 split 의 빈 끝 항목 포함 셈 — 물리 행은 971/1655 | `wc -l`(971·1655), python `len(split('\n'))` = 972 | ✅ 물리 행으로 고침(고친 초안 기준 593/378/1072) |
| 주소 표기는 14 개가 13 행에 있음 | python(13 행, 14 개) | ✅ 문구 고침 |
| zone_page_* 는 5 함수 + zone_add_free_page_list = 6 | Mach4 zalloc.c:578·594·617·636·659·676 읽음 | ✅ 고침 |
| `space_to_add = 0` 제거 줄(z4.c:822)에 표시 없음; Mach4 문구를 남길 수 있는지 확인 필요 | z4.c:822, Mach4:272 읽음; 초기화를 되살린 `s5p350-z4b1` 은 text 7787 B NOT_MATCH, 다시 뺀 `s5p350-z4c1` OBJECT_MATCH | ⚖️ 표시 누락은 사실 — 초기화는 원본이 요구해 뺀 채 `plan 350` 표시를 붙임 |
| 지운 Mach4 printf/lock 주석은 남길 수 있음 | Mach4:426–436 읽음, 주석만이라 되살림(z4c1 OBJECT_MATCH) | ✅ 채택 |
| Darwin 에만 있는 긴 주석 줄 복사 없음 | 내 python(Mach4 에 없고 Darwin 에 같은 주석 줄: 0 — 걸린 31 행은 모두 `*` 로 시작하는 코드 줄) | ✅(코드 줄이 Darwin 과 같은 것은 같은 원본 바이트를 내는 작성 코드라 피할 수 없음 — 기록에 “구조 Darwin 참고” 로 적음) |
| 기능 추가 없음; `<` 는 원본 0x16be9b `jbe` 와 맞음 | 내 capstone(0x16be99 `cmp [ecx], esi`·0x16be9b `jbe`) | ✅ |
| 진단 매니페스트의 `src/kern/zalloc.c` 출처 표기(nextmach)는 기록에 쓰면 안 됨 — 07 에서 새로 스테이징 | wipbuild 가 NeXTMach 를 source-override 로 놓고 WIP 로 덮어씀(내 스크립트) | ✅ 07 빌드(iter.py)로 기록 |
| MACH_OLD_VM_COPY=1 고정에서만 검증됨 | 07 generated/mach_old_vm_copy.h:1 읽음 | ✅ 기록에 적음 |
| 공통 13 개는 원본 `__common` 에 맞고 합 116 B / 범위 128 B; F 객체에 zero-fill 절이 없어 zerofill_check 가 쓰이지 않음 | 내 python(13/13, 116, 0x80); zerofill_check 를 돌려 “not a single zero-fill section” 확인 | ✅ 4 항 문구 고침 |
| record_object 는 Mach4 에 없는 함수에 fn_source 가 필요하고, `zget_space` 는 158 행 원형을 잡음 | record_object.py:60–72 읽음; z4.c:158 은 `;` 로 안 끝남 | ✅ fn_source 12 개 |
| record_object 는 늘 A 로 적음 — P 경로 없음; 7779/7780 구분 | record_object.py 의 O 행 'A' 고정 읽음 | ✅ 5 항 고침(A 예상 근거·7779/7780 구분) |

### 결과(2026-10-07, plan 350)

- 07: `src/kern/zalloc.c`(Mach4 바탕, plan 350 표시 103 행, SHA-256 586e7303…). codex 판정 반영: `space_to_add` 줄 표시, Mach4 printf/lock 주석 되살림(`s5p350-z4c1` OBJECT_MATCH).
- 빌드 `s5p350-it1`(iter.py, 07 에서 스테이징; 07 밖 행은 기록된 다른 커널 객체와 같은 ppc·machine 머리 7 개뿐): **OBJECT_MATCH**(22 MATCH, text 7779 B, data 차이 0), relcheck 0. `-fno-common` N 판은 text·data 차이 0, `__common` 배치는 후보 9 개라 미정(공통 심볼은 이름·간격 확인 13/13).
- 기록(python 대조): functions.tsv 3873→3895(+22), objects_confirmed 270→271, PROVENANCE 949→950, MODIFICATIONS 445→446, evidence `x86-zalloc.md`·`.diff` → **A**.
- 범위(python, 앞선 집계와 같은 end−start 합): 이번 7779 B. 누적 A 270 객체 537219 B(63.10%), P 67 객체 206879 B(24.30%), A+P **87.39%**(남은 107338 B).

## 351. S5-P340 세부 계획 — 커널 MIG 출력 `kernserv/kern_server_handler.c`·`kern_server_reply_user.c`(4.2 SDK .defs; D022; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): kern_server.defs·kern_server_reply.defs 는 4.2 SDK `kernserv/`(실기 목록과 같은 사본)·NeXTMach mk-108.1 kernserv·Darwin 0.1 kernel/kernserv 에 있음; Mach4 에 없음. NeXTMach `kern_server_handler.c`·`.h` 는 손으로 쓴 옛 판(.c 가 `kern_server_server.c` 를 #import, .h 에 struct kern_serv 직접 정의) — 4.2 원본 배치(전역 kern_serv_handler 뒤 static 13 개)와 다름. Darwin 0.1 은 이 둘을 MIG 로 만듦: `conf/Makefile.template:621–651`(kernserv 디렉터리 안에서 `mig -MD $(MIGFLAGS) -header kern_server.h -sheader kern_server_handler.h -user /dev/null -handler kern_server_handler.c`, reply 는 `-header kern_server_reply.h -user kern_server_reply_user.c -server /dev/null`; MIGFLAGS = `-I. -I.. -I… -DKERNEL`, 443 행), `conf/files:484–485`. 4.2 실기 `/usr/bin/mig`(1994-05-10, 1236 B, SHA-256 6341c61c…f3 — kr_run tools.actual 의 값과 같음) 는 `-sheader`·`-handler` 를 migcom 에 넘김(2026-10-07 gcds 로 읽음; `-newipc` 없으면 /usr/lib/migcom, SHA-256 b9d62a00…88).

0. 원본(python): kern_server_handler [0x16d650, 0x16dca8) 1624 B(앞 kern_notify 끝 0x16d64d 뒤 00×3), 전역 `_kern_serv_handler` 0x16d650 + static `_X*` 13 개, `__const` 132 B 0x1d12c0; kern_server_reply_user [0x16dca8, 0x16df30) 646 B + 00×2(다음 `_exc_server` 0x16df30), 전역 kern_serv_panic·kern_serv_section_by_name·kern_serv_log_data, `__const` 48 B 0x1d1344.
1. 진단(07 아님): MIG `s5p351-migd1`(stage 경로 이름) — 함께 나온 kern_server.h·kern_server_reply.h 는 SDK 판과 SHA-256 같음. 빌드 `s5p351-h1x3`(handler, include 줄만 기본 이름으로 고친 사본) **OBJECT_MATCH**(35 MATCH, text 1624, `__const` L1d), `s5p351-r1x2`(reply user 그대로) **OBJECT_MATCH**(11 MATCH, text 646, `__const` L1d). MIG `s5p351-migd2`: RUNIN `src/nextdev/kernserv` 에서 `-sheader kern_server_handler.h`(기본 이름)·`-handler @R/stage/kern_server_handler.c` → .c 는 `#include "kern_server_handler.h"` 이고 stage 경로 판과 그 한 줄만 다름; src 에 생긴 머리와 stage 판 머리 SHA-256 같음. → 호스트 수정 없이 Darwin 규칙과 같은 출력.
2. 07 배치(generated-mig, plan 343·348 방식):
   - `src/kernserv/kern_server_handler.c` = MIG `-handler` 출력 그대로(RUNIN 판).
   - `src/kernserv/kern_server_handler.h` = MIG `-sheader` 출력 그대로(.c 가 따옴표로 include → 같은 디렉터리; SDK 에 없는 이름).
   - `src/kernserv/kern_server_reply_user.c` = MIG `-user` 출력 그대로. 이것이 따옴표로 읽는 `kern_server_reply.h` 는 stage_headers 가 논리 이름 `src/kernserv/kern_server_reply.h` → `--mach-set sdk --prefer-07` 로 07 nextdev(SDK) 판을 고름(stage_headers.py:340–348·255–261) — MIG 출력이 SDK 판과 같으므로 07 에 따로 두지 않음(D022).
   - MIG run `s5p351-mig1`: 스테이징 `08_build/runs/tools/s5p351-stage-mig.py`(SDK kernserv 2 + std_types 계열 4 + ARCH_INCLUDE.h 실기 목록 대조 + 07 generated), 본 판(RUNIN, src 에 생기는 머리)·같은 run 의 stage 판(머리를 stage/ 로, .c 는 include 한 줄만 다름)·반복(r_)·`-nostdinc`(n_) 판을 비교; 07 에 두는 머리는 stage 로 나온 검증된 사본(RUNIN 판과 같은 SHA-256 확인). generated/README 에 재생성 줄.
3. 빌드·검사: kernel C 꼴 `iter.py s5p351-it1 kernserv/kern_server_handler.c kern_server_handler 0x16d650 0x16dca8`, `s5p351-it2 kernserv/kern_server_reply_user.c kern_server_reply_user 0x16dca8 0x16df30` → relcheck → record_object(generated-mig).
4. 예상: 둘 다 A. 객체 text 1624 B·646 B(합 2270 B); 범위 집계(end−start, reply 뒤 00×2 포함) 1624 B·648 B(합 2272 B).
5. 다음(plan 352): kern_server.c(NeXTMach 바탕, D024; Darwin 판에만 있는 kern_serv_load_objc·kern_serv_kernel_task_port 는 작성) — SDK kern_server.h 를 07 nextdev 로 들임.

### codex 교차검토 판정(2026-10-07, plan 351, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·크기·`__const`(132 B @0x1d12c0, 48 B @0x1d1344)·앞 00×3·뒤 00×2·함수 14/3 맞음; text 합 2270, end−start 합 2272 — 구분 필요 | 내 python(빌드 객체·이미지 0x16d64d·0x16df2e) | ✅ 4 항 고침 |
| “35/11 MATCH” 는 상수 묶음 포함 수 | L1 json 의 functions 항목에 const 묶음 포함 | ✅(기록 문구는 함수 수로) |
| 생성 kern_server.h·kern_server_reply.h = SDK | 내 sha256(d5b6a9b4…·983f2c55…) | ✅ |
| Darwin 행(443·629·files:484) 맞음 | Makefile.template 621–651·443, files:481–485 읽음 | ✅ |
| 래퍼 날짜·본문은 남은 기록이 필요 | gcds 로 krsha256(6341c61c…, 1236 B) — run tools.actual 과 같음 | ✅ 해시를 계획에 적음 |
| RUNIN: 디렉터리·@R 처리 맞음; src 에 생긴 파일은 출력 검증을 안 받으므로 stage 판을 함께 만들어 대조하고 그 사본을 둠 | kr_run.py:11–16·98–116 읽음; migd2 에서 두 머리 sha256 같음 | ✅ 2 항 고침 |
| RUNIN 은 Darwin 의 include 표기와 출력을 재현할 뿐 당시 명령을 증명하지 않음; -MD 없음 | 래퍼는 `-MD` 를 버림(`-MD ) shift`) — 실기 래퍼 원문 | ⚖️ 사실 — 기록 문구를 “Darwin 규칙과 같은 출력” 으로 둠; -MD 는 래퍼가 무시하므로 생략해도 같은 출력 |
| 세 파일을 07 src/kernserv/ 에; reply 머리는 SDK 판으로(복제 금지) | stage_headers.py:255–261·340–348 읽음 | ✅ 2 항 고침 |
| MIG 판 채택은 원본 바이트로 뒷받침(NeXTMach 는 kern_server_server.c import) | NeXTMach handler.c:10–11 읽음; h1x3·r1x2 OBJECT_MATCH | ✅ |
| 기록: generated-mig, SDK 입력 해시·도구 해시·명령·반복/-nostdinc 같음, generated/README; 진단 매니페스트의 NeXTMach 표기는 쓰지 않음 | plan 343·348 결과 절 형식 | ✅ |
| 회귀: s5p342-ak1 이 reply 머리를, 7 객체가 types 머리를 읽음 — 이번 배치로 선택·바이트 안 바뀜 | 내 python(rec-stage 매니페스트 전수: kernserv/kern_server* 행은 types·reply_types·reply 만, 모두 07 nextdev) — 새 파일 이름(handler.h 등)을 읽는 기록 객체 0 | ✅ 회귀 불필요 |

### 결과(2026-10-07, plan 351)

- MIG `s5p351-mig1`(스테이징 `08_build/runs/tools/s5p351-stage-mig.py`, 명령 `s5p351-mig1.cmd`): RUNIN 판 handler C·머리, stage 판, 반복(r_)·`-nostdinc`(n_) 판이 include 한 줄(머리 이름) 말고 같음; RUNIN 으로 src 에 생긴 머리 = stage 판 머리(sha256 e954f3a0…); 진단 migd1·migd2 출력과 같은 바이트.
- 07: `src/kernserv/kern_server_handler.c`·`kern_server_handler.h`·`kern_server_reply_user.c`(MIG 출력 그대로). `kern_server_reply.h` 는 스테이징이 07 nextdev(SDK) 판을 고름(it2 매니페스트). generated/README 에 재생성 줄.
- 빌드 `s5p351-it1`(handler) **OBJECT_MATCH**(text 1624, `__const` L1d), `s5p351-it2`(reply user) **OBJECT_MATCH**(text 646, `__const` L1d); relcheck 0 둘 다; 07 밖 행은 기록된 다른 커널 객체와 같은 machine·ppc 머리뿐.
- 기록(python 대조): functions.tsv 3895→3912(+14, +3), objects_confirmed 271→273, PROVENANCE 950→953(객체 2 + 머리 1), MODIFICATIONS 446→448, evidence `x86-kern_server_handler.md`·`x86-kern_server_reply_user.md` → **A** 둘.
- 범위(python, end−start 합): 이번 1624 + 646 = 2270 B. 누적 A 272 객체 539489 B(63.36%), P 67 객체 206879 B(24.30%), A+P **87.66%**(남은 105068 B).

## 352. S5-P341 세부 계획 — 커널 `kernserv/kern_server.c`(NeXTMach 바탕, D024·D013·D022; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): kern_server.c 는 NeXTMach mk-108.1 kernserv(고정 커밋 f6bdb9c3 blob 과 SHA-256 cdeb66c7… 같음)·Darwin 0.1 kernel/kernserv 에 있음; Mach4 에 없음, SDK 에 .c 없음. → D024: NeXTMach 바탕, Darwin 은 구조 참고. 머리는 07 판(SDK `kernserv/kern_server_types.h`·`kern_server_reply_types.h`·`kern_server_reply.h`, plan 351 의 MIG `kern_server_handler.h`).

0. 원본(python): [0x16c1c4, 0x16d20c) 4168 B = text 4166 B + 00×2(다음 kern_notify 0x16d20c), 전역 23 + static 5(심볼 없음 — kern_serv_dispatch 0x16c758, kern_serv_send_log 0x16cf28, kern_serv_log_init 0x16d004, kern_serv_log_free 0x16d054, kern_serv_interrupt_server 0x16d164; 빌드 객체 위치), `__TEXT,__const` 60 B 0x1d1284(kern_serv_proto), `__DATA,__data` 380 B 0x1dfd90(문자열; -fwritable-strings), 공통 심볼 없음.
1. 진단(07 아님): Darwin 판(`s5p352-d3x1`)은 NOT_MATCH(text 4146 B): ① kern_serv_log_init 끝의 printf("kern_serv_log_init: log 0x%x log.last 0x%x, log.base 0x%x\n", …) 가 원본에 있음(원본 0x16d044 호출, 문자열 0x1dfed1) — Darwin 은 `#if DIAGNOSTIC`, NeXTMach 는 조건 없음; ② kern_serv_callout 은 원본에서 `calloutDispatchUnique(kern_serv_interrupt_server, ksp->server_thread)` 를 부름 — Darwin 은 thread_call_func, NeXTMach 는 softint_sched; ③ SDK kern_server_reply_types.h 에는 Darwin·NeXTMach 판에 있는 `#import <kern/xpr.h>` 가 없어 log_entry_t(struct xprbuf) 가 불완전 → kern_server.c 가 kern/xpr.h 를 import. 이 셋을 고친 Darwin 판 `s5p352-d5x1` **OBJECT_MATCH**(29 MATCH). NeXTMach 바탕 초안 n1 `s5p352-n1x1` **OBJECT_MATCH**(29 MATCH, Darwin 대체 경로 없이).
2. 07 배치: `src/kernserv/kern_server.c` = NeXTMach 원문(NeXT 고지 유지) + plan 352 표시 31 행(python difflib 물리 행, codex 판정 반영 뒤 초안: NeXTMach 1122 행 중 1089 유지, 33 제거, 72 추가; 초안 1161 행). 바뀌는 것:
   - import: 07 에 없는 옛 이름(sys/mig_errors.h·sys/notify.h·kern/ipc_ptraps.h·kern/mach_traps.h·kern/ipc_notify.h·vm/vm_param.h·next/spl.h; sys/printf.h 는 07 SDK 판이 있어 그대로 둠)을 4.2 이름(mach/mig_errors.h·mach/notify.h·mach/mach_traps.h·kernserv/kern_notify.h·mach/vm_param.h·machine/spl.h)으로, `"kernobjc.h"`(KERNOBJC), `<kern/xpr.h>` 추가.
   - 코드(원본 바이트가 요구; Darwin 0.1 과 같은 꼴): 전역 kernel_port → ksp->kernel_port(= kern_serv_kernel_task_port()), kern_serv_proto 끝에 kern_serv_load_objc, panic 호출은 ksp->bootstrap_port(쓰이지 않게 된 지역 bootstrap_port 선언은 NeXTMach 그대로 둠), kernel_ipc_space·ipc_kernel·reply_port 대입 제거, KERN_SERV_INMSG_SIZE → kern_servMaxRequestSize, RCV_INTERRUPTED 의 thread_should_halt 제거, RCV_TOO_LARGE 에서 새 크기를 kfree 전에 읽음, 기본 알림의 `pn_proc == 0` → `pn_proc`, vm_read 의 kernel_port → ksp->kernel_port, softint_sched → calloutDispatchUnique(plan 326 km.m 처럼 `void *` 원형을 더함; softint_sched 원형 줄은 그대로 둠), kern_serv_interrupt_server 는 send_notification(…NOTIFY_MSG_ACCEPTED…).
   - 작성(D024, 구조 Darwin 참고, 주석 새로): kern_serv_load_objc(원본 0x16c96c)·kern_serv_shutdown 의 KERNOBJC 블록·kern_serv_kernel_task_port(원본 0x16d1bc).
   - 그대로 둔 NeXTMach 표기(바이트 영향 없음, 진단 일치로 확인): (task_t)·(vm_task_t) 형 변환, `#if DEBUG`·`#ifdef DEBUG` 블록(빌드에 DEBUG 정의 없음), kalloc 결과 형 변환 없음, reply_port 주석(대입만 뺌). log_init 의 조건 없는 printf 는 원본이 요구하는 NeXTMach 텍스트(바이트에 영향 있음).
3. 빌드·검사: kernel C 꼴 `iter.py s5p352-it1 kernserv/kern_server.c kern_server 0x16c1c4 0x16d20c` → relcheck → record_object(nextmach; fn_source: NeXTMach 에 없는 kern_serv_load_objc·kern_serv_kernel_task_port). 07 스테이징에서 07 밖 머리가 읽히면 plan 346 방식으로 처리.
4. 예상: A, text 4166 B(범위 집계 end−start 는 기록 도구가 text 끝으로 적음).

### codex 교차검토 판정(2026-10-07, plan 352, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 4168 = text 4166 + 00×2, 전역 23 + static 5, static 주소·`__const` 60 B @0x1d1284·`__data` 380 B @0x1dfd90·공통 없음; printf 0x16d044·문자열 0x1dfed1·callout·send_notification 호출 | 내 python(빌드 객체 위치·이미지·0x1dfd90+380 = 0x1dff0c 안) | ✅ |
| “29 MATCH” = 함수 28 + kern_serv_proto | L1 json | ✅ 기록 문구는 함수 수로 |
| 줄 수(1122/1081/41/71, 27)는 그 시점 초안 값 — 지금 초안과 다름 | 내 python 재계산(지금 1122/1089/33/72, 31 행) | ✅ 고침 |
| sys/printf.h·kern/ipc_ptraps.h 삭제에 표시 없음 | n1.c import 블록 읽음 | ✅ sys/printf.h 는 되살리고 mach_traps.h 줄 표시에 ipc_ptraps.h·mach_traps.h 대체임을 적음 |
| sys/printf.h 는 07 에 있음(계획이 틀림) | `ls 07_kernel/nextdev/bsd/sys/printf.h` | ✅ 내 오기 — import 되살림, `s5p352-n3x1` OBJECT_MATCH |
| 지역 bootstrap_port·reply 주석·softint_sched 원형은 지우지 않아도 됨 | 되살린 n3x1 빌드 OBJECT_MATCH | ✅ 채택 |
| 조건 없는 printf 는 바이트 영향 — 바이트 무관 목록에 넣으면 안 됨 | d3x1(조건부) NOT_MATCH, d4x1(조건 없음) callout 만 남음 | ✅ 문구 고침 |
| `#ifdef DEBUG` 은 DEBUG 가 정의되면(0 이라도) 켜짐 — 검증 안 됨 | 빌드 명령 -D 목록(DEBUG 없음)·n3x1 일치 | ⚖️ 이 빌드에선 꺼짐 확인; NeXTMach 원문 유지 |
| calloutDispatchUnique `void *` 원형은 구현(callout_func_t)과 다름 | 07 km.m:87(plan 326) 같은 원형 선례, callout.c:296 정의 | ⚖️ 선례대로 둠(i386 ABI 같음; 다른 아키텍처 때 다시 봄) |
| kern/xpr.h 를 이 파일에서 import — D023 목록 밖이므로 SDK 머리를 고치지 않는 지금 방식이 맞음; 07 kern/xpr.h 는 Darwin 판 | PROVENANCE:214 읽음 | ✅ |
| 진단 매니페스트는 NeXTMach 대체·kern/xpr.c 동반 — 기록은 07 새 스테이징으로; Darwin 대체 행은 쓰이지 않는 갈래 | wipbuild 동작(내 스크립트) | ✅ |
| fn_source: NeXTMach 에 없는 2 함수는 3 요소로, interrupt_server 작성 본문도 표시; fline 이 dispatch·log_init·log_free 의 원형 줄을 잡음 | record_object.py:60–72, n1.c:71·76·80 원형, :474·1039·1054 정의 | ✅ 5 개 fn_source 지정 |

### 결과(2026-10-07, plan 352)

- 07: `src/kernserv/kern_server.c`(NeXTMach 바탕, plan 352 표시 31 행, SHA-256 37506b37…). codex 판정 반영: sys/printf.h import·지역 bootstrap_port·softint_sched 원형·reply 주석 되살림(`s5p352-n3x1` OBJECT_MATCH).
- 빌드 `s5p352-it1`(iter.py, 07 스테이징): **OBJECT_MATCH**(함수 28 + kern_serv_proto, text 4166, `__const`·`__data` 차이 0), relcheck 0. 스테이지의 07 밖 행은 컴파일이 읽지 않는 갈래(ppc, `!KERNEL_BUILD` 의 machine/features.h, ddmPrivate.h `!KERNEL` 의 objc/objc.h — D046 으로 들인 objc-1 트리에서 찾아짐)뿐.
- 기록(python 대조): functions.tsv 3912→3940(+28), objects_confirmed 273→274, PROVENANCE 953→954, MODIFICATIONS 448→449, evidence `x86-kern_server.md`·`.diff` → **A**.
- 범위(python, end−start 합): 이번 4166 B. 누적 A 273 객체 543655 B(63.85%), P 67 객체 206879 B(24.30%), A+P **88.15%**(남은 100902 B).

## 353·354. 진단 메모(코딩 전, 2026-10-07) — `bsd/netinet/tcp_input.c`, `bsd/specfs/spec_vnodeops.c`

- 353 tcp_input.c [0x12857c, 0x129d8c) 6160 B(함수 6: tcp_reass·tcp_input·tcp_dooptions·tcp_pulloutofband·tcp_xmit_timer·tcp_mss). SDK 4.2 tcp_var.h 는 Net/2 꼴(max_rcvd 없음, t_rttmin·t_softerror). 원본은 tcp_xmit_timer(tp)(인자 1, tp->t_rtt +0x5a 사용, 0x129b90)를 세 곳(0x128b24·0x128f5e·0x129489)에서, tcp_dooptions 를 두 곳에서, tcp_mss 를 dooptions(0x129afd)·tcp_output(0x129fad)에서 부름 — 4.3BSD-Net/2 꼴. NeXTMach(Reno, `max_rcvd` 줄만 뺀 진단 `s5p353-t1x1`) 은 text 5579 B, 함수 크기 reass 464/448·input 4680/4944·dooptions 180/148·xmit_timer 없음·mss 143/300. 참고 트리에 Net/2 원문 없음 → 원문 확보 여부는 사용자 결정 사항(보류).
- 354 spec_vnodeops.c [0x139ba8, 0x13a588) 2528 B, 함수 19(전역 7: setattr·access·link·fsync·lockctl·fid·realvp, 나머지 static). NeXTMach 바탕 초안(scratchpad spec/s2.c): VBLK open 뒤 set_blocksize(원본 호출 0x139cf8), rdwr 의 음수 오프셋 검사 없음·블록 크기 sp->s_size, inactive 의 p_posix_utime 켬/끔(0x13a14c), getattr·setattr 의 getthetime, getattr VBLK 블록 크기 VOP_DEVBLOCKSIZE, spec_lockctl 은 EINVAL 만(0x13a4c4), spec_devblocksize 작성(0x13a374, vnodeops 표 0x1dd6d0 칸 32), sys/proc.h import. `s5p354-s3x1`: 19 함수 크기 모두 같고 18 MATCH; spec_open 만 레지스터 배정 차이(원본: dev→EBX, error→EAX caller-save [ebp-8], (int)dev→[ebp-0xc]; 빌드: dev→ESI, error·(int)dev→EBX). 시험한 변형(모두 그대로): error 비-register, VBLK 바로 return(크기 −8), 선언 순서·register 조합 5 가지, 루프 앞 error=0 제거, nvp 위치, -O2(`s5p354-oa1`, 전체 크기 다름). 미해결 — 다른 대상 뒤 다시 봄.
- 355 ufs_dir.c [0x13de14, 0x13f90c) 6904 B, 함수 17(전역 6: brelse_and_swap·dirlook·direnter·diraddentry·dirremove·blkatoff + static 11; “전역 7” 은 내 오기 — plan 370 codex 지적). NeXTMach 바탕 진단 초안(scratchpad ud/u6.c): `#ifdef QUOTA` → generated quota.h 가 `QUOTA 0` 이라 `#if` 로; brelse_and_swap(bp) 작성(0x13de14: `if (bp) { byte_swap_dir_block_out(bp); brelse(bp); }`, 다른 곳엔 -O3 로 인라인); 디렉터리 버퍼 brelse 11 곳 → brelse_and_swap, bwrite 5 곳 앞에 byte_swap_dir_block_out; blkatoff 의 bread 뒤 byte_swap_dir_block_in(bp->b_un.b_addr, bp->b_bcount)(0x13f504); dircheckforname 의 slotfreespace = 0(0x13e5d1)·iget 실패 경로는 null 검사 없는 swap+brelse·`.` 분기 순서 뒤집음; dirrename 의 대상 디렉터리·원본 비-디렉터리는 EISDIR(0x13e8ee); dirlook 의 entryoffsetinblock = 0(0x13de47)·찾은 경로 swap+brelse. `s5p355-u6x1`: 16/17 MATCH, dircheckpath 만 레지스터 배정 차이(인라인된 blkatoff 의 bp: 원본 EAX+caller-save [ebp-0xc], 빌드 EBX; 원본 프레임 4 B 큼). blkatoff 를 return 하나 꼴로 바꾼 u7 은 blkatoff 도 달라져 버림. spec_open(354)과 같은 부류 — 미해결.
- 354·355 레지스터 배정: codex(gpt-6.1-sol)에 가설만 물음 — 제안 5 개를 직접 빌드: spec_open 의 VCHR 결과 분리(`s5p354-a11`, 크기 −8)·VBLK break 꼴(`a21`, 그대로 200 B)·인라인 도우미(`a31`, 크기 −8), blkatoff 의 인라인 swap 도우미(`s5p355-b11`, 그대로)·성공 갈래 먼저(`b21`, 더 나쁨) → 모두 기각(측정). 원본 B 의 명령 바이트 671 대 u6 663(codex 수치를 python 으로 다시 셈: 6904−6895 = 9 중 끝 채움 1).

## 356. S5-P342 세부 계획 — 커널 ObjC 런타임 9 모듈(`objc/*.m`, `except.c`; D045·D046·D047·D030·D022; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): Object.m·except.c·hashtable.m·maptable.m·objc-class.m·objc-errors.m·objc-load.m·objc-runtime.m·objc-sel.m 은 Darwin 0.1 objc-1(01_resources/upstream/darwin01/objc, D046)에만 있음; Mach4·NeXTMach·Darwin kernel 에 같은 이름 없음 → D030/D047(작성, "nearly the same as Darwin 0.1 objc-1 <file>", Apple 고지 넣지 않음). 원본 문자열의 모듈 이름은 상대 이름(`Object.m`·`maptable.m`·`objc-class.m`·`objc-load.m`·`objc-runtime.m` 등) → objc 디렉터리 안에서 컴파일됨.

0. 빌드 꼴(진단으로 확정): objc-1 Makefile.preamble:26–27 `KERNEL_CFLAGS= -DMACH -DKERNEL -DKERNEL_PRIVATE -DMACH_USER_API -D_KERNEL`, common.make:108 `OPTIMIZATION_CFLAG = -O`. 우리 템플릿(s5p110-diag6) 에서 `-O3`→`-O`, `-D_POSIX_SOURCE`·`-DPOSIX_KERN` 뺌, `-DMACH_USER_API`·`-Isrc/src/objc` 더함, -fwritable-strings 없음(문자열은 `__cstring`: maptable 의 6 문자열 0x1d9b78… 확인), RUNIN `src/src/objc`(모듈 이름 = 파일 이름). 근거: -O3 은 static 을 끝으로 미룸(maptable `s5p356-m1`), -O2 는 강도 감소로 어긋남(`m2`), -O 일치(`m3`); `_POSIX_SOURCE` 가 있으면 SDK string.h 의 bcopy→memmove 매크로가 꺼져 hashtable·Object·objc-sel 이 어긋남(`h0`·`h1`·`p*`); `-DPOSIX_KERN` 이면 SDK tty.h 가 sys/proc.h 를 읽어 except.c 가 pid_t 로 실패(`bexcept`), 둘 다 빼면 일치(`jexcept`).
1. 진단(07 아님, 같은 플래그 `s5p356-u*`): maptable 24·hashtable 40·Object 77·except 13·objc-class 48·objc-errors 5·objc-load 8·objc-sel 10 MATCH **OBJECT_MATCH**, objc-runtime 37 MATCH(+ `__bss` 2 미확인 → zerofill). 원본 text 구간(L1): Object [0x1c9be8, +2801), except [0x1ca960, +1369), hashtable [0x1caebc, +4182), maptable [0x1cbf14, +3143), objc-class [0x1ccb5c, +4530), objc-errors [0x1cdd10, +303), objc-load [0x1cdf30, +2593), objc-runtime [0x1cec30, +5052), objc-sel [0x1cffec, +1108); 합 25081 B(python).
2. 07 배치:
   - `src/objc/` 에 9 소스 + 실제로 읽히는 objc-1 머리(진단 스테이지 닫힘 — 07 스테이징으로 다시 확인해 확정): objc-1 본문 그대로, 머리 주석만 D030 문구로 바꿈(plan 342 audio 파일 선례). PROVENANCE: `authored`(D030/D047), 원본 경로 darwin01/objc/<file>·objc-1.tar.gz sha256, "nearly the same as Darwin 0.1 objc-1 <file>".
   - objc-load.m·objc-runtime.m 의 `#include <NXString.h>` 는 원문 그대로 두고 `-Isrc/src/objc` 로 찾음; stage_headers 가 꺾쇠 이름을 objc 디렉터리에서 찾지 못하므로 빌드 도구가 COMPANION 으로 objc/NXString.h 닫힘을 함께 스테이징(진단은 따옴표로 바꾼 사본이었음 — 07 에서는 원문 그대로 일치 재확인).
   - SDK 머리 들이기(07 nextdev, 실기 목록 대조, plan 136 방식): ansi/ctype.h·bsd/syslog.h·mach/cthreads.h·mach/i386/cthreads.h·mach/machine/cthreads.h·mach-o/dyld.h·mach-o/ldsyms.h·mach-o/rld.h(진단 스테이지에서 07 밖 SDK 미러로 찾아진 것; 07 스테이징 결과로 확정).
3. 빌드 도구: scratchpad `iter_objcrt.py`(iter_objc.py 꼴 + 위 플래그 + COMPANION) — 명령 파일은 08_build/runs/tools 에 남음. 기록의 build_note 에 플래그 차이와 근거를 적음.
4. 빌드·검사·기록: 모듈마다 07 에서 `s5p356-r<mod>` → OBJECT_MATCH, relcheck 0 → record_object(authored, D030 문구) → A; objc-runtime 은 zerofill_check 로 `__bss` → P 또는 A. 이미 기록된 객체 중 새 07 머리를 읽는 것이 있으면 회귀.
5. 범위 밖(다음 계획): [0x1c88f4, 0x1c9be8) 4852 B·[0x1ca6dc, 0x1ca960) 644 B(다른 ObjC 클래스 모듈 — HashTable.m·Protocol.m 등 후보), objc-globaltext(0x1cde40, 프로토타입 상수), KernelZone zone 층(0x1cdeb0, 128 B, 작성), objc_msgSend 계열(0x1ce960, 720 B, objc-msg-i386*.s), Mach `_EXTERNAL` 스텁(0x1d0440, MIG `-DMACH_USER_API`), libgcc(0x1d0f68).

### codex 교차검토 판정(2026-10-07, plan 356, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈 구간·크기·합 25081 B 맞음; “MATCH 수” 는 함수 수가 아님 | 내 python(L1 json 의 text 크기·주소 합) | ✅ 기록은 함수 수로 |
| -O3/-O2/-O 근거는 L1 판정; “강도 감소” 설명은 디스어셈블 인용이 필요 | m2 의 NXResetMapTable 비교(진단 중 sbs: 원본은 진입 jmp·포인터 하나, -O2 는 dec/cmp 회전·포인터 둘) | ⚖️ 문구를 “-O 만 일치” 로 줄임 |
| `_POSIX_SOURCE` → `__STRICT_ANSI__` → string.h BSD 매크로 꺼짐(standards.h:6, string.h:108) | 두 파일 읽음, h0 의 bcopy ↔ 원본 _memmove(0x101504) 확인 | ✅ |
| except.c 는 두 정의를 모두 둔 hexcept 에서도 일치 — POSIX_KERN 근거는 “두 정의가 없을 때도 일치” 로 한정 | hexcept·jexcept 결과(내 run) | ✅ 문구 고침 |
| m3 은 MACH_USER_API 없이도 일치 — 모든 모듈에 필요하다는 근거는 없음(Makefile 근거) | m3 명령에 MACH_USER_API 없음 | ✅ “Makefile 근거, 필요성 미검증” 으로 |
| 템플릿의 나머지 정의(KERNEL_BUILD·INET·MULTICAST·NeXT·_NEXT_SOURCE·DRIVER_PRIVATE·ARCH_PRIVATE·-imacros)는 하나씩 시험 안 됨 | — | ✅ “일치하는 진단 플래그 확인, 역사적 템플릿 정의는 미검증” 으로 기록 |
| maptable 문자열 6 개 모두 원본 `__cstring` | 내 python(앞서 push 상수 → 섹션) | ✅ |
| D030/D047 처리는 선례와 같음; 기록 도구의 기본 문구 “no reference text” 는 쓰지 말 것 | PROVENANCE:716·MODIFICATIONS:264·293 읽음 | ✅ PROVENANCE 3 열은 objc-1.tar.gz sha256, 4 열 darwin01/objc/<file> |
| 실제로 읽히는 objc 머리 15 개(목록) — COPYALL 스테이지는 상위 집합 | 실기 `cc -M` 으로 확정(run `s5p356-dep2`) | ⏳ 결과로 확정 |
| `<NXString.h>` 는 기록 때도 동반 스테이징이 필요; 원문 그대로 다시 확인 | stage_headers.py:343–348 읽음(꺾쇠는 소스 기준 후보 없음) | ✅ |
| SDK 8 개는 실기 목록에 있음; cthreads·dyld 는 KERNEL 에서 안 읽힐 수 있음 | -M 결과로 확정 | ⏳ |
| **회귀**: 07 `src/objc/` 에 objc-1 머리를 두면 `<objc/...>` 가 SDK 판 대신 그것을 고름 — 기록 매니페스트 85 개 영향 | 내 python: rec-stage 매니페스트 84 개가 nextdev/objc/*.h 를 읽음; stage_headers.py:270–292(07 사본 우선)·ROOTS(src 가 루트) | ✅ 채택 — 07 위치를 루트 이름과 겹치지 않는 `src/objc-runtime/` 로 바꿈(objc-1 소스의 꺾쇠 include 는 `<objc/zone.h>` 뿐 → SDK 판) |
| objc-runtime 은 `__bss` 때문에 NOT_MATCH — zerofill 은 소유를 증명하지 않으므로 P | zerofill_check.py 머리 주석 | ✅ |
| Object 는 메서드 심볼 때문에 record_objc.py; 두 기록 도구 모두 소스만 재스테이징 — 동반 스테이징 연결 필요 | record_object.py:32·43–57, record_objc.py:33–83 | ✅ 도구 보완(스크래치) |

### 356 수정 계획(codex 판정 반영; 코딩 전)

- 07 위치: `07_kernel/src/objc-runtime/`(9 소스 + -M 으로 확인한 objc-1 머리, D030 머리 주석). 빌드는 RUNIN `src/src/objc-runtime`, `-Isrc/src/objc-runtime`.
- 플래그 기록: “일치하는 진단 플래그(-O, `-D_POSIX_SOURCE`·`-DPOSIX_KERN` 없음, `-DMACH_USER_API`, objc 디렉터리 -I, writable strings 없음); 템플릿의 나머지 정의는 미검증; objc-1 Makefile.preamble:26–27·common.make:108 과 같은 방향”.
- 머리: 실기 `cc -M`(s5p356-dep3)이 보여 준 것만 07 에 둠/들임 — objc-1 머리 15(Object·Protocol·error·hashtable·maptable·objc-class·objc-config·objc-load·objc-private·objc-runtime·objc·typedstream·NXString·NXCharacterSet·unichar .h), SDK 4(mach-o/ldsyms.h·mach-o/rld.h·ansi/ctype.h·bsd/syslog.h; 기록 매니페스트 중 읽는 것 0). cthreads·dyld 는 글자 닫힘에만 있고 컴파일이 읽지 않음 — 스테이지의 07 밖 행으로 남으며 기록에 “읽지 않는 갈래” 로 적음.
- 기록: .m 은 record_objc.py, except.c·hashtable 등 C 함수만인 모듈은 record_object.py(모듈 기록이 있으면 record_objc) — 어느 쪽이든 동반 스테이징을 포함하도록 스크래치 도구 보완, PROVENANCE 문구는 위 판정대로; objc-runtime 은 P.

### codex 2 차 교차검토 판정(2026-10-07, 356 수정 계획, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| -M 결과로 objc-1 머리 15·SDK 4 가 맞음; 기록 매니페스트 중 넷을 읽는 것 없음 | 내 python(dep3 00–08.out 파싱, rec-stage 전수) | ✅ |
| `src/objc-runtime/` 는 어떤 루트·MACH_MAP 과도 겹치지 않음; 84 매니페스트 영향 없음 | stage_headers.py:91(ROOTS)·270–292 읽음; objc-1 꺾쇠 include 는 `<objc/zone.h>` 뿐 | ✅ |
| 객체 파일 전체가 아니라 섹션·재배치·ObjC 검증으로 판정(머리 주석 줄 수로 stab 줄이 바뀜) | L1 이 stab 을 비교하지 않음(앞선 기록과 같음) | ✅ |
| except.c 의 NeXT 고지 블록은 `#ifdef SHLIB` 뒤에 있어 앞 주석만 바꾸면 남음 | except.c:20–35 읽음; 초안 파일 전수 검사(다른 파일엔 남은 고지 없음) | ✅ 그 블록도 바꿈(지시문 유지) |
| 읽지 않는 cthreads·dyld 를 기록 도구가 들이지 않도록 명시 | — | ✅ 수정 계획 머리 항목에 적음 |
| 계획의 dep2 → dep3 | 계획 1508 행 | ✅ 고침 |

## 357. S5-P343 세부 계획 — 도구 `10_tools/reconstruction/stage_headers.py`: `components/` 의 Darwin 대응을 architecture·driverkit-1 로 한정(D046 참고 트리 objc-1 배제; 코딩 전, 2026-10-07)

0. 사실: stage_headers.py:149–155 `darwin_of` 와 :136–145 `logical_of` 는 `components/X` 를 darwin01 최상위(D01) 전체에 대응시킴. 설명 주석 :72–74 은 `-Isrc/components` 를 architecture·driverkit-1 용으로 적음. D046 으로 `01_resources/upstream/darwin01/objc/`(objc-1, 참고 전용)가 생긴 뒤로 `<objc/X.h>` 는 `-Isrc/components` 가 `-Isrc/nextdev` 보다 앞서므로 `components/objc/X.h`(Darwin objc-1)로 스테이징됨.
1. 영향(python, 앞서 실행): nextdev/objc/*.h 를 읽는 기록 rec-stage 매니페스트 84 개를 지금 다시 스테이징하면 84 개 모두 `components/objc/objc.h`(darwin01/objc) 행이 생김. 기록된 매니페스트 중 이미 그 행을 가진 것은 `s5p352-it1-rec-stage`(kern_server.c) 하나 — 실기 `cc -M`(run `s5p352-dep1`)으로 컴파일러가 objc/*.h 를 읽지 않음을 확인(읽는 것은 ddmPrivate.h·Device_ddm.h). plan 356 의 07 빌드(`s5p356-r1*`)는 streams.h 의 `<objc/error.h>` 를 `components/objc/error.h` 로 스테이징함(읽는지 미확인 — 고친 뒤 다시 빌드).
2. 수정(plan 357 표시): `COMPONENT_DIRS = ('architecture', 'driverkit-1')` — `darwin_of` 는 `components/<d>/...` 에서 d 가 이 목록일 때만 darwin01/<d>/... 를 돌려주고, 그 밖의 `components/...` 는 None. `logical_of` 는 darwin01/<d> 가 목록 밖이면 SystemExit(스테이징 대상 밖) — objc-1·Libc 는 참고 전용. 설명 주석 :72 에 한정 사실을 적음.
3. 시험 `10_tools/reconstruction/test_stage_headers_components.py`(임시 디렉터리만): a) darwin_of('components/objc/objc.h') is None, b) darwin_of('components/architecture/byte_order.h')·('components/driverkit-1/driverkit/IODevice.h') 는 그대로, c) logical_of(darwin01/objc/objc.h) 는 SystemExit, d) 실제 스테이징 1 건(nextdev/objc 를 읽는 기록 소스 하나): `components/objc/` 행 없음·`nextdev/objc/objc.h` 는 07 SDK 판, e) 이미 있는 시험(test_stage_headers_soundkit.py·test_stage_headers_rename.py) 통과.
4. 회귀: 84 매니페스트를 다시 스테이징해 `components/objc` 행 0, 그 밖의 선택 변화는 이번 수정과 무관한 것만(수정 전후 두 번 스테이징해 차이를 이번 수정 탓인 것만 셈). s5p352 kern_server 는 다시 빌드해 OBJECT_MATCH 와 매니페스트에서 그 행이 빠진 것을 기록. plan 356 모듈은 고친 뒤 다시 빌드(`s5p356-r2*`)해 `<objc/error.h>` 가 07 nextdev(SDK) 판으로 바뀐 상태에서도 OBJECT_MATCH 인지 확인 — 다르면 objc-1 error.h 를 쓰는 근거로 따로 판단.

### codex 교차검토 판정(2026-10-07, plan 357, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 행 번호: logical_of 138–146, darwin_of 149–155; 설명 :72 는 architecture, :74 가 driverkit | stage_headers.py 읽음 | ✅ 고침 |
| 84 매니페스트의 행은 글자 닫힘이지 컴파일러가 읽는다는 증거는 아님; s5p352 rec-stage2 에도 같은 행 | — | ✅ 문구 그대로(“스테이징됨”) |
| 목록(architecture·driverkit-1)은 지금 쓰임에 완전; Libc 는 어디서도 안 쓰임 | 내 python(기록 매니페스트 components/ 하위 이름: architecture·driverkit-1 뿐) | ✅ |
| **logical_of 를 SystemExit 로 바꾸면 closure() 가 모든 루트(D01 포함)에 대해 미리 부르므로(:346, ROOTS :91–93) 스테이징이 깨짐** — darwin_of 만 한정 | :343–347·:91–93 읽음 | ✅ 채택 — logical_of 는 그대로, darwin_of 만 한정 |
| 한정은 경로 정규화 뒤에 확인(../ 로 벗어나지 못하게) | — | ✅ 채택 |
| 시험 보강: Libc 거부·logical_of 왕복·일반 include 후보·정규화 경계·--prefer-07/--nextdev 유무; test_stage_headers_subst.py 도 | — | ✅ 채택 |
| 회귀: 같은 입력·플래그로 수정 전/후 짝 스테이징(모든 기록 매니페스트), plan 356 재빌드에 cc -M 도 | — | ✅ 채택 |
| plan 350–352 기록 객체 중 Darwin ObjC 머리를 실제로 읽은 것 없음(kern_server 의 cc -M) | dep1 00.out 내가 확인(앞서) | ✅ |

### 357 수정 계획(codex 판정 반영)

- 코드: `COMPONENT_DIRS = ('architecture', 'driverkit-1')`; `darwin_of` 의 `components` 갈래에서 정규화한 나머지 경로의 첫 이름이 목록에 있고 `..` 로 시작하지 않을 때만 darwin01 경로를 돌려줌(그 밖은 None). logical_of·select·closure 는 손대지 않음. 설명 주석 :72 근처에 한정을 적음. 모두 plan 357 표시.
- 시험 `test_stage_headers_components.py`: darwin_of 의 objc·Libc·`components/../kernel/x`·`components/architecture/../objc/x` 는 None, architecture·driverkit-1 은 그대로; logical_of 왕복(darwin01/architecture, darwin01/driverkit-1, darwin01/objc 는 이름만 만들어짐); 실제 스테이징 2 건(ObjC 머리를 읽는 기록 소스 하나, --nextdev 유무)에서 components/objc 행 없음·nextdev/objc/objc.h 는 07 판; 기존 시험 soundkit·rename·subst 통과.
- 회귀: 기록된 rec-stage 매니페스트 전부를 수정 전 사본 도구와 수정 뒤 도구로 같은 인자로 스테이징해 비교 — 달라지는 것은 components/objc 행이 빠지고 그 이름이 nextdev(07 SDK)로 가는 것뿐이어야 함.

### 결과(2026-10-07, plan 357)

- 도구: `10_tools/reconstruction/stage_headers.py`(수정 전 사본 SHA-256 9dd7d0f7…, 수정 뒤 582589fc…): `COMPONENT_DIRS = ('architecture', 'driverkit-1')`, `darwin_of` 는 `components/...` 를 정규화한 경로의 둘째 이름이 목록에 있을 때만 darwin01 로 대응(plan 357 표시); 설명 주석 갱신. logical_of·select·closure 그대로.
- 시험: 새 `test_stage_headers_components.py` 11 개 통과(첫 실행에서 `components/architecture/../objc/...` 가 architecture 접두로 빠져나가는 결함을 잡아 판정을 함수 첫머리의 정규화로 옮김); 기존 soundkit 13·rename 12·subst 19 통과.
- 회귀(짝 스테이징, 수정 전 사본 대 수정 뒤, 같은 인자): 기록 rec-stage 매니페스트 231 개 중 146 같음, 85 는 `components/objc/*`(darwin01/objc) 행이 빠지고 그 이름이 07 `nextdev/objc/*`(SDK) 로 돌아감 — 그 밖의 선택·미해결 변화 0; 돌아간 행이 기록 매니페스트에 있던 경우 해시 모두 같음(기록에 없던 2 행은 s5p352 kern_server 의 것).

### 결과(2026-10-07, plan 356)

- 07: `src/objc-runtime/` 에 9 소스 + objc-1 머리 15(본문 원문 그대로, 앞 고지 주석을 D030 머리 주석으로; except.c 는 `#ifdef SHLIB` 뒤 NeXT 고지 블록도), `nextdev/` 에 SDK 4(mach-o/ldsyms.h·mach-o/rld.h·ansi/ctype.h·bsd/syslog.h, 실기 목록 sha256 대조). 빌드 도구 scratchpad `iter_objcrt.py`(명령 파일 08_build/runs/tools/s5p356-r2*.cmd), objc-load·objc-runtime 은 COMPANION `objc-runtime/NXString.h`(원문 `<NXString.h>` 그대로).
- plan 357 수정 뒤 빌드 `s5p356-r2*`: maptable·hashtable·Object·except·objc-class·objc-errors·objc-load·objc-sel **OBJECT_MATCH**, objc-runtime 은 text·data 일치 + `__bss` 8 B 미확인 → zerofill_check `reference-inferred`(참조 16, Δ 하나, [0x1e8748, 0x1e8750)) → **P**. 스테이지의 07 밖 행은 컴파일이 읽지 않는 cthreads·dyld·ppc·machine 갈래뿐; streams.h 의 `<objc/error.h>` 는 07 nextdev SDK 판.
- s5p352 kern_server.c 를 고친 도구로 다시 빌드(`s5p352-it2`): OBJECT_MATCH, 스테이지에 components/objc 행 없음(nextdev/objc 2 행) — 기존 기록(s5p352-it1)은 컴파일러가 objc 머리를 읽지 않음(s5p352-dep1)이라 그대로 둠.
- 기록 도구 scratchpad `record_objc356.py`(record_objc.py 바탕: 동반 스테이징·읽지 않는 행 허용 목록·D030/D047 문구·모듈 기록 없는 파일·한 줄 정의·`__S()` 정의·16 B 정렬 앞 00 최대 15 B). 기록(python 대조): functions.tsv 3940→4186(+246), objects_confirmed 274→282(+8), objects_partial 68→69(+1), PROVENANCE 954→982(객체 9 + 머리 19), MODIFICATIONS 449→458, evidence `x86-objc-*.md`·`.diff`.
- 범위(python, end−start 합): A 281 obj 563684 B (66.20%), P 68 obj 211931 B (24.89%), A+P 91.09%, rem 75821.

## 358. S5-P344 세부 계획 — ObjC 런타임 클래스 모듈 `List.m`·`Protocol.m`(D047·D030; plan 356 과 같은 꼴; 코딩 전, 2026-10-07)

참조: objc-1 List.m·Protocol.m(darwin01/objc); Mach4·NeXTMach·Darwin kernel 에 없음; SDK 는 List.h·Protocol.h 공개 머리만(빌드는 objc-runtime 디렉터리의 따옴표 include). 원본 objc.json: 0x1c88f4–0x1c9be8 의 메서드 57 개는 List 29·HashTable 28, 0x1ca6dc–0x1ca960 은 Protocol 5; 모듈 기록 List.m·Protocol.m 있음.

0. 진단(07 아님, plan 356 통일 플래그, `s5p358-dlist`·`dprotocol`): List **OBJECT_MATCH**(29 MATCH, text 1704 B @0x1c9540), Protocol **OBJECT_MATCH**(8 MATCH, text 644 B @0x1ca6dc). HashTable.m([0x1c88f4, 0x1c9540) 3148 B, python)은 HashTable.h 와 hashtable.h 가 같은 디렉터리에 있어야 해 kr_run 의 대소문자 충돌 검사(kr_run.py:72–73)에 걸림 — 이 계획 밖(도구 결정 필요, 따로).
1. 07: `src/objc-runtime/List.m`·`Protocol.m` + 머리 `List.h`(새로; Protocol.h 는 있음) — 본문 원문 그대로, 앞 고지 주석을 D030 머리 주석으로(plan 356 과 같은 변환). 읽히는 머리는 07 빌드 뒤 실기 `cc -M` 으로 확인해 기록.
2. 빌드·기록: `iter_objcrt.py s5p358-r1list List.m List`·`s5p358-r1proto Protocol.m Protocol` → OBJECT_MATCH, relcheck 0 → `record_objc356.py`(모듈 기록 있음) → A 둘. PROVENANCE: 소스 2 + List.h.
3. 예상 범위: 1704 + 644 = 2348 B.

### codex 교차검토 판정(2026-10-07, plan 358, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| List [0x1c9540, +1704), 29 메서드; Protocol [0x1ca6dc, +644), 5 메서드 + static 3(MATCH 8 의 내역); 합 2348; HashTable 3148 B·28 메서드; 모듈 기록 0x20936c·0x20938c | 내 python(L1 json·objc.json 메서드 owner 집계·구간 차) | ✅ |
| 클래스·메타클래스 배치 등 새 메타데이터 처리 필요 없음 | 진단 L1 의 __OBJC 섹션 판정(내 출력) | ✅ |
| 07 src/objc-runtime/List.h 는 SDK objc/List.h 선택을 가리지 않음(루트 밖, 따옴표 include 만 찾음; plan 357) | stage_headers.py:91 ROOTS, plan 357 시험 h | ✅ |
| Protocol 기록 명세에 plan 356 의 읽지 않는 행 허용 목록을 넣을 것 | record_objc356.py 의 INACT 처리 | ✅ 채택 |
| 대소문자 규칙은 재현성·무결성 통제로 문서화됨(계획 :149 QR3, :70, 011-099:16); 경로 전체를 비교하므로 두 머리가 같은 디렉터리일 필요는 없음 — 선택지: 다른 include 디렉터리·이름 바꾼 사본·좁은 예외 | 계획 :149·:70·011-099:16 읽음; kr_run.py:68–74 | ✅ HashTable.m 은 사용자 결정 사항으로 남김 |

### 결과(2026-10-07, plan 358)

- 07: `src/objc-runtime/List.m`·`Protocol.m`·`List.h`(D030 머리 주석, 본문 원문 그대로). 빌드 `s5p358-r1list`·`r1proto` **OBJECT_MATCH**(29·8 MATCH). 실기 cc -M(`s5p358-deplist`·`depproto`): List 는 List.h·Object.h·objc.h·objc-class.h·typedstream.h, Protocol 은 plan 356 머리만.
- 기록: functions.tsv 4186→4223(+37), objects_confirmed 282→284, PROVENANCE 982→985(객체 2 + List.h), MODIFICATIONS +2 → **A** 둘.
- 범위(python): 이번 2348 B. A 283 obj 566032 B (66.48%), P 68 obj 211931 B (24.89%), A+P 91.37%, rem 73473.
- 남은 HashTable.m(3148 B)은 kr_run 대소문자 충돌 규칙(무결성 통제, QR3)과 얽혀 사용자 결정 대기.

## 359. S5-P345 세부 계획 — ObjC 런타임 `HashTable.m`(D049 별도 디렉터리; D047·D030; 코딩 전, 2026-10-07)

0. 원본: 빈 구간 [0x1c88f4, 0x1c9540) 3148 B 중 코드 [0x1c8900, 0x1c953d) 3133 B(앞 00×12, 뒤 00×3; python), HashTable 메서드 28(objc.json), 모듈 기록 `HashTable.m`. objc-1 HashTable.m 은 `"HashTable.h"`·`"NXStringTable.h"`·`"objc-private.h"`·`<stdlib.h>`·`<stdio.h>`·`<string.h>` 를 import(HashTable.m:32–40); HashTable.h 는 `"Object.h"`·`"hashtable.h"`·`"typedstream.h"`(:36–38); NXStringTable.h 는 `"HashTable.h"`(:36) 만, objc-1 의 다른 기록 모듈은 NXStringTable.h 를 쓰지 않음(grep).
1. 07(D049): `src/objc-runtime/HashTable/` 에 HashTable.m·HashTable.h·NXStringTable.h(D030 머리 주석, 본문 원문 그대로). 소문자 전체 경로가 상위의 hashtable.h·hashtable.m 과 다르므로 kr_run.py:68–74 검사는 그대로 통과(규칙 변경 없음).
2. 빌드: `iter_objcrt.py` 에 하위 디렉터리 선택(SUBDIR)을 더한 판 — RUNIN `src/src/objc-runtime/HashTable`, `-Isrc/src/objc-runtime/HashTable -Isrc/src/objc-runtime`(앞이 이 디렉터리), 나머지 플래그는 plan 356 과 같음. stage_headers 는 따옴표 이름을 포함 파일의 디렉터리와 루트에서만 찾으므로, 상위 objc-runtime 머리(objc-private.h 등)는 COMPANION 으로 함께 스테이징(실기 cc -M 으로 읽기 확인).
3. 진단·기록: 07 에서 빌드 → OBJECT_MATCH 이면 relcheck → record_objc356(모듈 HashTable.m, companion, 읽지 않는 행 허용) → A. PROVENANCE: 소스 + 머리 2.
4. 예상: A, 3148 B.

### codex 교차검토 판정(2026-10-07, plan 359, gpt-6.1-sol)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 3148 B 는 감싸는 빈 구간 — 앞 00×12, 코드 [0x1c8900, 0x1c953d) 3133 B, 뒤 00×3 | 내 python(이미지 바이트) | ✅ 0 항 고침(최종 L1 로 확정) |
| HashTable.m import 는 35–40(32 는 SHLIB 조건 shlib.h); NXStringTable.h 를 쓰는 다른 파일(NXBundle.m·NXStringTable.m)은 원본 모듈 기록 없음 | objc-1 파일 읽음 | ✅ |
| kr_run 이 이 배치를 받음(경로 전체·디렉터리 이름 비교, RUNIN 규칙) | kr_run.py:62–74·102–116·196 읽음 | ✅ |
| `-I objc-runtime/HashTable` 다음 `-I objc-runtime`; stage 는 상위 머리를 못 따라가므로 COMPANION `objc-runtime/objc-private.h` 로 닫힘 확보; 실제 읽기는 cc -M 로 | stage_headers.py:343–357 읽음 | ✅ 채택 |
| 컴파일 피연산자는 `HashTable.m`(이름 그대로) | iter_objcrt 명령 꼴 | ✅ |
| 기록 도구: logical 은 하위 경로, 같은 COMPANION·허용 목록; **셀렉터 첫 이름만 비교해 겹치는 메서드(initKeyDesc:… / newKeyDesc:…)의 줄을 잘못 고름**; 앞 채움을 4 B 만 봄; 새 머리 2 개 PROVENANCE 는 따로 | HashTable.m:111·116·125·132·138 읽음; record_objc356.py 해당 줄 | ✅ 도구 고침(셀렉터 전체 비교·16 B) |

### 결과(2026-10-07, plan 359)

- 07(D049): `src/objc-runtime/HashTable/HashTable.m`·`HashTable.h`·`NXStringTable.h`(D030 머리 주석). 빌드 `s5p359-r1ht`(SUBDIR=HashTable, COMPANION objc-runtime/objc-private.h) **OBJECT_MATCH**(35 MATCH, text [0x1c8900, 0x1c953d) 3133 B), 실기 cc -M `s5p359-depht`.
- 기록 도구 보완: 셀렉터 전체(빈 키워드·중첩 괄호 형·`//` 주석·여러 줄 정의 포함) 비교, 앞 채움 16 B. 기록: functions.tsv 4223→4258(+35), objects_confirmed 284→285, PROVENANCE 985→988(머리 2 + 객체 1), MODIFICATIONS +1 → **A**.
- 원래 record_objc.py 가 첫 키워드만 비교해, 이미 기록된 행 중 겹치는 셀렉터 14 묶음이 같은 줄을 인용하고 있었음(EventInput·KernBusInterrupt·KernBus·KernDevice·KernBusMemory·IODevice·AudioStream·IOSVGADisplay·IOFrameBufferDisplay·Object·List) → 새 비교로 17 행의 인용 줄 번호를 고침(functions.tsv 행 수 4258 그대로; 수정 전 사본 scratchpad functions.before-selfix.tsv; Object.m 225·233, IOFrameBufferDisplay.m 1297·1469·1474, EventInput.m 411 등 원문 줄을 열어 확인).
- 범위(python): 이번 3133 B. A 284 obj 569165 B (66.85%), P 68 obj 211931 B (24.89%), A+P 91.74%, rem 70340.

## 360. S5-P346 세부 계획 — ObjC 런타임 남은 조각 `objc-globaltext.m`·`objc-msg.s`·zone 층(D047·D030·D024; 코딩 전, 2026-10-07)

0. 원본(python·L1 진단, plan 356 통일 플래그):
   - objc-globaltext.m: `__text` [0x1cde40, 0x1cdeb0) 112 B — 프로토타입 상수 7(NXPtrPrototype …NXObjectMapPrototype, const 라 `__text` 에 놓임); 진단 `s5p360-dgt` **OBJECT_MATCH**(7). 모듈 기록 없음(objc.json).
   - objc-msg.s: [0x1ce960, 0x1cec30) 720 B — objc_msgSend·objc_msgSendSuper·_objc_msgForward·objc_msgSendv; objc-msg.s 는 `-DKERNEL` 이면 objc-config.h 가 `OBJC_COLLECTING_CACHE` 를 정의하지 않아 objc-msg-i386-**lock**.s 를 include(codex 지적으로 고침; 원본 0x1ce964 `andl 0x1e5604`(__objc_multithread_mask) = lock.s:70); text 717 B [0x1ce960, 0x1cec2d) + 뒤 00×3; 진단 `s5p360-dmsg` **OBJECT_MATCH**(4).
   - zone 층: [0x1cdeb0, 0x1cdf30) 128 B — static 4(realloc·malloc·free 감쌈, destroy 빈 함수) + NXDefaultMallocZone·NXZoneFromPtr·NXCreateZone·NXNameZone·NXZoneCalloc, `__data` KernelZone 16 B @0x1e55e4 = {0x1cdeb0, 0x1cdec4, 0x1cded4, 0x1cdee8}(python). objc-1 에 없음; Darwin 0.1 kernel/driverkit/objc_support.m 은 같은 이름이지만 kalloc 을 직접 씀 — 4.2 는 malloc 계열(07 kern/kalloc.c, plan 기록 P)을 부름. 작성 초안 `objc-zone.c`(D024, 원래 파일 이름은 알 수 없음 — 이름은 재구성 선택) 진단 `s5p360-dzone` **OBJECT_MATCH**(9, `__data` 포함).
1. 07: `src/objc-runtime/objc-globaltext.m`·`objc-msg.s`·`objc-msg-i386-lock.s`(D030/D047 머리 주석, 본문 원문 그대로; objc-msg.s 의 다른 아키텍처 include 줄은 원문 그대로 둠 — 읽히지 않음), `src/objc-runtime/objc-zone.c`(D024 작성, Darwin objc_support.m 은 구조 참고).
2. 빌드·기록: iter_objcrt.py(필요하면 .s 도 같은 RUNIN 명령) → OBJECT_MATCH → relcheck → 기록. 기록 도구는 데이터 전용 모듈(globaltext 의 `NAME = {` 정의 줄)과 .s 의 레이블 줄(`_objc_msgSend:`)을 찾도록 보완, zone 층은 작성 문구(D024).
3. 예상: A 셋, 112 + 717 + 128 = 957 B(python; 채움 3 B 제외).
4. 범위 밖: objc-globaldata.m(`__data` 만, `__text` 없음), Mach `_EXTERNAL` 스텁(0x1d0440–), libgcc(0x1d0f68–).

### codex 교차검토(kpvz2wdv0, gpt-6.1-sol) 판정 — plan 360

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| `-DKERNEL` 이면 `OBJC_COLLECTING_CACHE` 가 꺼져 lock 판이 include 됨; 계획의 nolock 은 틀림 | darwin01/objc/objc-config.h:33–37(`!defined(KERNEL) && !defined(SHLIB)`), 07 objc-config.h:20 같음, objc-msg.s:35–42 읽음; 원본 0x1ce960 바이트 `8b442404 89c1 230d 04561e00` = andl 0x1e5604, symbols.tsv:416 `__objc_multithread_mask`; lock.s:68–71 같은 꼴 | ✅ 채택 — 0·1 항 고침(내 오기) |
| msg text 717 B, 끝 0x1cec2d, 뒤 00×3; 합 957 B | python `0x1cec2d-0x1ce960`=717, 112+717+128=957; 원본 0x1cec28 `ff89ec5dc3000000`; s5p360-dmsg L1 json size 717 | ✅ 채택 — 3 항 고침 |
| globaltext [0x1cde40,0x1cdeb0)·zone [0x1cdeb0,0x1cdf30) 맞음, KernelZone 16 B @0x1e55e4 = 4 포인터 | python 112·128; 원본 0x1e55e4 4 워드 = 0x1cdeb0·0x1cdec4·0x1cded4·0x1cdee8; symbols.tsv:196 | ✅ |
| kern_* 이름은 원본 심볼에 없음(재구성 선택) | symbols.tsv grep `kern_realloc`·`kern_malloc` 0 건(static) | ✅ 머리 주석에 적음 |
| zone: KernelZone 초기화·단순 진입점은 Darwin objc_support.m 과 거의 같으니 "구조만 참고" 는 과소 기술 | objc_support.m:161–196(kern_destroy·KernelZone·NXDefaultMallocZone·NXZoneFromPtr·NXCreateZone·NXNameZone) 과 초안 대조; 감쌈 3 개·NXZoneCalloc 은 다름(kalloc/kfree 대 malloc 계열, kern_malloc 대 calloc) | ⚖️ 부분채택 — D027/D030 대로 해당 부분 "nearly the same as Darwin 0.1 kernel/driverkit/objc_support.m", 감쌈·calloc 은 원본 바이트 작성으로 구분해 적음 |
| .s 는 RUNIN objc 디렉터리, `-traditional-cpp` 로 전처리; `__OBJC,__meth_var_names`·`__message_refs`·`__cstring` 도 냄; 레이블 lock.s 68·198·361·399 | s5p360-dmsg.cmd 읽음; L1 json 섹션 4 개(10·4·31 B); `grep -n '^[A-Za-z_]*:'` lock.s → 68·198·361·399 | ✅ 기록 도구는 include 된 lock.s 레이블 줄 인용 |
| globaltext 7 개는 함수가 아닌 데이터 정의; `CC_NO_MACH_TEXT_SECTIONS` pragma 에 의존 | globaltext.m:25–27 pragma, `^const NX` 7 건(49·52·57·61·74·78·82) | ✅ 기록 kind 를 data 로 |
| `_zoneRealloc` [0x1e55e0,0x1e55e4) 는 인접 경계일 뿐(globaldata) | symbols.tsv:446; globaldata.m:55 | ✅ 범위 밖 유지 |

### 결과(2026-10-07, plan 360)

- 07: `src/objc-runtime/objc-globaltext.m`·`objc-msg.s`·`objc-msg-i386-lock.s`(D030/D047 머리 주석, 본문 Darwin 0.1 objc-1 원문 그대로), `src/objc-runtime/objc-zone.c`(D024/D027 작성; 머리 주석에 objc_support.m 과 거의 같은 부분과 다른 부분을 나눠 적음).
- 빌드(07): `s5p360-r1gt` OBJECT_MATCH(7), `s5p360-r1zone` OBJECT_MATCH(9, `__data` 포함), `s5p360-r1msg` OBJECT_MATCH(4; lock.s 를 스테이징, 다른 아키텍처 include 10 개는 미해결로 읽히지 않음). relcheck 불일치 0(셋).
- 기록 도구 `record_objc360.py`(kind data·asm·authored, label_file, extra_files): functions.tsv 4258→4271(+9 zone, +4 msg; globaltext 데이터 7 개는 행 없음), objects_confirmed 285→288, PROVENANCE 988→992(4 파일), MODIFICATIONS +4. 인용 줄(lock.s:55·185·348·386, globaltext.m:35–68) 열어 확인.
- 범위(python): 이번 957 B. A 287 obj 570122 B (66.96%), P 68 obj 211931 B (24.89%), A+P 91.85%, rem 69383.

## 361. S5-P347 세부 계획 — Mach 사용자 API 스텁 14 개(`mach/<routine>.c`, `mig -i`, `<routine>_EXTERNAL`; 4.2 SDK mach.defs; 코딩 전, 2026-10-07)

참조: 생성 규칙은 Darwin 0.1 kernel `conf/Makefile.template` — MACH_FFILES/MACH_OFILES(458–496), MACH_FILES 규칙(503–532)의 두 번째 `$(MIG) -MD $(MIGFLAGS) -header mach_interface.h -i -server /dev/null mach.defs`(`-typed` 없음, MIGFLAGS = `-I. -I.. -I$$REL_SOURCE_DIR -DKERNEL`, 443), 컴파일 규칙 `$(KCC) -c $(CFLAGS) -DMACH_USER_API -D$*=$*_EXTERNAL $(MACHDIR)/$*.c`(689–691). 입력 .defs 는 plan 348 과 같이 4.2 SDK `mach/mach.defs`(실기 목록 대조; D022 SDK 우선).

0. 원본(python): `__text` [0x1d0440, 0x1d0f68) 2856 B 에 `_EXTERNAL` 함수 14 개, 코드 합 2837 B(각 c3 로 끝, 뒤 00 채움 0–3 B): port_allocate 199·port_deallocate 172·port_set_add 190·port_set_allocate 199·port_set_deallocate 172·task_set_special_port 190·thread_get_special_port 215·thread_set_special_port 190·vm_deallocate 190·vm_read 245 · port_set_backlog 190·vm_allocate 243·vm_protect 223·vm_write 219(링크 순서는 알파벳 두 묶음 — 4.2 Makefile 의 목록 순서이며 객체 바이트와 무관). Darwin 목록 19 개 중 port_set_remove·port_status·task_get_special_port·thread_abort·thread_suspend 의 **`_EXTERNAL` 스텁**은 원본에 없음(같은 이름의 커널 함수는 있음 — symbols.tsv:2458·2460·2994·3067·3135). 각 객체는 옛 IPC `msg_rpc` 꼴(port_allocate: msg_id 0x81c=2076, 응답 0x880=2176)이고 요청 형 서술자와 응답 검사 상수(`static const msg_type_t`·`msg_type_long_t`, 예 vm_allocate.c:80·vm_write.c:88)를 `__TEXT,__const`(원본 0x1d10bc–0x1d69b0 안, port_allocate 는 0x1d6800 8 B)에 둔다.
1. 진단(07 아님): MIG `s5p361-migi1`(plan 348 스테이징 스크립트 재사용, RUNIN src/migi): `/usr/bin/mig -arch i386 -I…/generated -I…/nextdev -DKERNEL -header mach_interface.h -i -server /dev/null mach.defs` → 루틴 55 개 .c + mach_interface.h. 생성 mach_interface.h 는 4.2 SDK `mach/mach_interface.h`·07 nextdev 사본·실기 목록과 SHA-256 같음(b96918ad…, python). 컴파일 진단 `diag_migi.py`(07 사본 + 생성 .c, kernel C 꼴 + `-DMACH_USER_API -D<r>=<r>_EXTERNAL`): `s5p361-dpa`·`s5p361-d<루틴 이름에서 _ 뺀 것>` 13 개 — **14 개 모두 OBJECT_MATCH**(`__text` 0 차이·참조 차이 0, `__TEXT,__const` 0 차이; text 합 2837 B, `__const` 합 176 B = [0x1d6800, 0x1d68b0) 연속, 객체당 8–20 B; python). 스테이징 closure 의 07 밖 Darwin machdep/ppc 머리 10 개는 꺼진 분기(plan 348 과 같은 꼴) — 실기 cc -M 로 확인 예정.
2. 07 배치: `src/mach/<routine>.c` 14 개 = MIG 출력 그대로(generated-mig, plan 348 과 같은 방식), `src/mach/mach_interface.h` 는 **두지 않음**: 생성 .c 의 `#include "mach_interface.h"` 는 논리 경로 src/mach/mach_interface.h 가 되고, 스테이징(`--mach-set sdk`)이 이를 07 nextdev 의 SDK 사본(실기 목록 대조, 생성 머리와 같은 바이트)으로 채움 — 진단 매니페스트 s5p361-dpa-stage 의 `mach-set: real machine /NextDeveloper/Headers/mach/mach_interface.h`·`replaces 07_kernel/src/mach/mach_interface.h`(stage_headers.py:268–275 mach_pick). 07 빌드에서 확인; 생성 머리는 run 출력으로만 기록. 쓰지 않는 루틴 41 개는 두지 않음. MIG run: 361.1 의 kr_run 보완 뒤 `RUNIN stage/migi`·`stage/migi_r`(반복)·`stage/migi_n`(`-nostdinc`) 에서 각각 `-header mach_interface.h`(같은 이름) → 세 판의 .c 55 개·머리가 문자 그대로 같고 진단 출력과 같아야 함, 출력은 kr_run 출력 매니페스트(대상 쪽 SHA-256)에 들어감. (이미 돌린 `s5p361-mig2` 는 r_/n_ 머리 이름이 달라 include 줄만 다르고 C 출력이 src/ 에 떨어져 매니페스트 밖 — 쓰지 않는 run.) Darwin 규칙의 첫 `-typed -i` 실행(mach_kernloader.h)은 같은 .c 를 두 번째 실행이 덮어쓰므로 재현하지 않음.
3. 빌드·검사: kernel C 꼴(iter.py 꼴 + `-DMACH_USER_API -D<r>=<r>_EXTERNAL`; 새 스크립트 `iter_migi.py`) → OBJECT_MATCH(`__text` + `__TEXT,__const` 바이트 0 차이) → relcheck → 실기 cc -M 1 회(머리 읽기 확인) → record_object(generated-mig; 함수 이름 `_<r>_EXTERNAL` 은 정의 줄 `<r> (` 를 fn_source 로 인용; `__const` 의 static 형 검사 상수는 함수 행 없음).
4. 예상: 14 객체 A, 2837 B(운영 빌드·relcheck·cc -M·기록 검사가 통과하는 조건). 기록: 입력 closure·도구 해시·명령·선택 출력 해시·반복/`-nostdinc` 비교·선택 14/생략 41 목록; mach_interface.h 는 07 에 두지 않으므로 행 없음(evidence 에 생성 머리 = SDK 사본 해시와 스테이징 선택을 적음), generated/README 에 plan 361 MIG 출력 줄 추가; `_<r>_EXTERNAL` 은 생성 정의 줄 39(`mig_external kern_return_t <r> (`)를 fn_source 로; 원본 배치 순서는 관찰된 배치로만 적음.
5. 범위 밖: libgcc `__muldi3`·`__udivdi3`(0x1d0f68–), objc-globaldata.m.

### codex 교차검토(ktn7rlwxj, gpt-6.1-sol) 판정 — plan 361

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| r_/n_ 판 `-header` 이름이 생성 C 첫 줄 include 에 들어가 문자 그대로 비교가 깨짐 | s5p361-mig2 실행 후 `diff` — port_allocate.c 1 행만 다름; python 정규화 대조 55 개 모두 그 줄만 다름 | ✅ 채택 — 같은 이름, 다른 디렉터리(361.1) |
| `-i` 출력 C 가 src/migi 에 떨어져 kr_run 출력 매니페스트 밖 | kr_run.py:18(“outputs must go to stage/”), 258–259(`find stage -type f` → output.manifest), 103(RUNIN 은 `src/` 만); migi1 output.manifest 에 .c 없음 | ✅ 채택 — 361.1 도구 보완 |
| 수치(2837+19=2856, `__const` 176 B 연속, 루틴별 크기·msg id) | 내 python(원본 바이트·14 L1 json); port_deallocate.c·vm_write.c msg_id 2077/2177·2027/2127 grep | ✅ |
| 빠진 다섯은 `_EXTERNAL` 스텁만 없고 커널 함수는 있음 | symbols.tsv grep: _port_set_remove 2458, _port_status 2460, _task_get_special_port 2994, _thread_abort 3067, _thread_suspend 3135 | ✅ 채택 — 0 항 문구 고침(내 과장) |
| `__const` 는 응답 검사뿐 아니라 요청 형 서술자·`msg_type_long_t` 포함 | vm_allocate.c:79–80(`addressType`), vm_write.c:87–88(`msg_type_long_t dataType`) 읽음 | ✅ 채택 — 문구 고침 |
| `-MD` 생략 무해(래퍼가 버림) | 08_build/toolchains/real-i386-20261001/mig 의 `-MD ) shift;;` 읽음 | ✅ |
| 첫 `-typed -i` 실행 생략 타당(같은 파일을 덮어씀, mach_kernloader.h 를 읽지 않음) | Makefile.template:503–532 읽음; 생성 .c 의 include 는 `"mach_interface.h"` 와 mach/ 4 개뿐(port_allocate.c:1–5) | ✅(재현 명령의 근거이지 역사적 명령의 증명은 아님) |
| 규칙 근거: D022 SDK, generated-mig 그대로, D017 | plan 348·PROVENANCE mach_server 행(앞서 읽음) | ✅ |
| mach_interface.h 셋(생성·SDK·07 nextdev) 8152 B 같은 해시, 실기 목록 일치 | 내 python(b96918ad…, 실기 목록 True) | ✅ |
| 기존 07 에 bare `"mach_interface.h"` include 없음, 스테이징은 SDK 사본을 고름 | `grep -rln '"mach_interface.h"\|<mach_interface.h>' 07_kernel` → 0 파일; stage_headers.py:268·290 은 361 실행 뒤 기록 때 다시 열어 문구 확정 | ✅(겹침은 같은 바이트라 무해) |
| `_EXTERNAL` 함수의 정의 줄은 14 개 모두 39 행 | `sed -n 39p` 14 파일 — 모두 `mig_external kern_return_t <r> (` | ✅ |
| 4.2 Makefile 목록 순서라는 말은 확인 불가 | 근거 없음(내 추정) | ✅ 채택 — “관찰된 배치” 로 고침 |
| generated/README 갱신 | 07_kernel/generated/README 20–35 행 읽음 — plan 343·344·348·349·351 MIG 출력이 모두 여기 적혀 있음 | ✅ 채택 — 내 판단(해당 없음)이 틀림, README 에 plan 361 줄 추가 |

### 361.1 kr_run 보완 — RUNIN 을 `stage/<이름>` 에서도(코딩 전)

- 문제: `mig -i` 는 루틴마다 .c 를 현재 디렉터리에 쓰고(래퍼에 출력 디렉터리 선택 없음 — mig 래퍼 읽음), kr_run 은 RUNIN 디렉터리를 `src/` 아래로만 받아(kr_run.py:103–105) 출력이 대상 쪽 출력 매니페스트(`find stage -type f`)에 들어가지 않음.
- 보완: `parse_cmdfile` 이 RUNIN 디렉터리로 `stage/<이름>`(한 단계, `[A-Za-z0-9_]+`, `_log` 제외)도 받음. `prepare` 는 그런 디렉터리를 SRC 존재 검사에서 빼고, run.sh 의 `mkdir stage stage/_log` 바로 뒤에 `mkdir stage/<이름>`(중복 없이, 실패하면 fail)을 넣음. 그 밖의 규칙(@R, 허용 도구, 인자 문자, `..` 금지, EXPECT)은 그대로; 출력은 stage/ 안이라 “outputs must go to stage/” 와 맞음. 문서 줄 갱신.
- 시험: test_kr_run_runin.py 에 — stage/migi 수락, `stage` 자체 거부(기존 ‘dir outside src’ 시험 유지), `stage/_log` 거부, `stage/a/b` 거부, `stage/..`·`stage/x;y` 거부, 그리고 run.sh 생성 부분을 함수로 떼어 `mkdir stage/migi` 가 한 번, `mkdir stage stage/_log` 뒤에 오는지 확인. 기존 runin·absroot·tools 시험 통과.
- 회귀: 이미 쓴 cmd 파일 몇 개로 prepare 의 run.sh 가 보완 전후 같은지(src RUNIN 만 쓰는 cmd) — 실제 prepare 는 ID 를 태우므로 run.sh 생성 함수를 직접 불러 비교.
- 그 뒤 MIG run `s5p361-mig3`(RUNIN stage/migi·migi_r·migi_n, 각각 `-header mach_interface.h`; EXPECT 각 판의 14 개 .c 와 머리).

#### codex 교차검토(k4r2dv7sx, gpt-6.1-sol) 판정 — 361.1

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| stage 하위 디렉터리는 run.sh 에서 `mkdir stage stage/_log` 뒤에 만들어야 함(prepare 에서 만들면 “stage exists”) | kr_run.py:217 `[ -d stage ] && fail`, :222 mkdir 읽음 | ✅(계획과 같음) |
| 출력은 `find stage` 재귀로 매니페스트에 들어가고 collect 는 파일 집합·해시·크기 확인 뒤 out 으로 옮김, 중첩 경로도 그대로 | kr_run.py:239–243·296–345 읽음(`rel[len('stage/'):]`) | ✅ |
| walk_regular 가 디렉터리 이름도 소문자 충돌 표에 넣으므로 `stage/migi`·`stage/MIGI` 는 실행 뒤 collect 에서야 거부 → 앞에서 거부, `_LOG` 도 거부 | kr_run.py:61–72 읽음(`dns + fns`, `rel.lower()`) | ✅ 채택 — parse 단계 거부 |
| 인자 검사는 절대 경로·`@R/stage/_log/status` 를 막지 않음(기존 한계, 이번 변경과 무관) | kr_run.py:108–114 읽음 — `..` 와 @R 꼴만 검사 | ✅ 기존 한계로 기록, 범위 밖 |
| `(cd DIR && …)` 는 하위 셸, 로그·status 는 부모 기준; 입력은 `@R/src/…` 로, `-header mach_interface.h` 는 cwd 에 씀 | kr_run.py:231–235 읽음 | ✅ cmd 를 그렇게 씀 |
| EXPECT 는 stage 기준 상대(`migi/port_allocate.c`) | kr_run.py:323–325 `os.path.join(rdir,'stage',e)` | ✅ |
| 4.2 래퍼에 출력 디렉터리 선택 없음; Mach4 는 `-i <prefix>` 를 받지만 4.2 래퍼는 `-i` 단독 | 4.2 mig 래퍼 `-[qQvVtTrRsSiPp] )` 읽음; mach4/mig/mig.sh:46 `-i ) sawI=1; migflags="$migflags $1 $2"` 읽음 | ✅(migcom 의 문서 밖 동작은 미확인 — 쓰지 않음) |
| 07 에 mach_interface.h 를 두지 않아도 스테이징이 SDK 사본을 줌 | stage_headers.py:177·268–270·287–290·358–359 내가 읽음(앞) | ✅ |
| 시험 추가: `_LOG`·대소문자 충돌, 같은 디렉터리 반복은 mkdir 1 번, RUN/src RUNIN/stage RUNIN 섞기, ABSROOT 와 함께, 이름 꼴(빈 이름·끝 `/`·`//`·`.`·문장부호·@R), prepare 자체(임시 RUNS 고정물), mkdir 실패 시 fail | test_kr_run_absroot.py:35–60 의 임시 RUNS·REGISTRY·tool_hashes 고정물 읽음 | ✅ 채택 — 고정물로 prepare 시험 |
| collect 의 중첩 출력 시험 | collect 는 대상 쪽 파일(input.actual 등)이 있어야 해 고정물이 큼 — 실제 run `s5p361-mig3` 의 collect 로 확인 | ⚖️ 부분 — 실 run 으로 대신 |
| 회귀는 보완 **전** run.sh 를 먼저 고정하고 같은 입력으로 바이트 비교 | — | ✅ 채택 — 보완 전 kr_run 으로 임시 고정물 prepare, run.sh 저장 후 비교 |

### 결과(2026-10-07, plan 361·361.1)

- 361.1 kr_run: RUNIN `stage/<이름>`(한 단계, `_log` 아님, 대소문자 충돌 parse 단계 거부), run.sh 가 `mkdir stage stage/_log` 뒤 디렉터리마다 `mkdir … || fail`. 시험 test_kr_run_runin.py 10→32(새 22: parse 15·prepare 7) 통과, 보완 전 kr_run 으로는 새 시험 11 개 실패(변경을 잡음); absroot 12·tools 7 통과. 회귀: 보완 전 kr_run 사본으로 cmd 5 개(s5p361-dpa·s5p359-depht·s5p348-mig2·s5p361-mig2·s5p298-it2 — RUN·src RUNIN·ABSROOT)를 임시 RUNS 에서 prepare 한 run.sh·input.expected 10 개가 보완 뒤와 바이트 같음.
- MIG `s5p361-mig3`(stage/migi·migi_r·migi_n): 판마다 56 파일(.c 55 + 머리), 세 판·진단 s5p361-migi1 과 모두 같은 바이트, 출력 매니페스트에 .c 165; 머리 = SDK 사본(b96918ad…). 쓰지 않은 run: s5p361-mig2(r_/n_ 머리 이름, C 출력 src 밖).
- 07: `src/mach/<r>.c` 14 개 = s5p361-mig3 출력 그대로(diff 0 B 14 개), `src/mach/mach_interface.h` 는 두지 않음 — 빌드 스테이징 14 개 모두 07 nextdev SDK 사본을 고름; generated/README 에 plan 361 줄.
- 빌드 `iter_migi.py` `s5p361-r1<루틴>` 14 개 **OBJECT_MATCH**(`__text` + `__TEXT,__const` 0 차이), relcheck 0, 미채택 0, 미해결은 기존 9 개 그대로. 실기 cc -M `s5p361-depmach`(port_allocate): 읽은 머리 40 개 모두 07 쪽, Darwin ppc 등 07 밖 10 개는 읽히지 않음.
- 기록(record_object, generated-mig, fn_source = 생성 정의 줄 39): functions.tsv 4271→4285, objects_confirmed 288→302, PROVENANCE 992→1006, MODIFICATIONS 465→479 → **A** 14.
- 범위(python): 이번 2837 B. A 301 obj 572959 B (67.29%), P 68 obj 211931 B (24.89%), A+P **92.18%**, rem 66546.

## 362. S5-P348 세부 계획 — libgcc `__muldi3`·`__udivdi3`(D050 참고 원문 확보; 코딩 전, 2026-10-07)

0. 원본(python): `__text` [0x1d0f68, 0x1d0fb4) `__muldi3` 76 B, [0x1d0fb4, 0x1d10bc) `__udivdi3` 264 B(= `__text` 끝), 합 340 B; `__TEXT,__const` [0x1d68b0, 0x1d69b0) 256 B = `__clz_tab`(지역 심볼, 원본 심볼 표에 없음; `__const` 끝과 같음, 바로 앞은 plan 361 MIG 상수).
1. 링크 근거: Darwin 0.1 `conf/Makefile.i386:63–64` `LIBS_P= -lcc`·`LIBS= -lcc`, `conf/Makefile.i386:55–59` LDFLAGS 끝 `-u __muldi3`(커널 안에서 부르는 곳이 없어도 `__muldi3` 를 끌어옴), `conf/Makefile.template:386–387` 링크 줄 `${LDOBJS} $(MACH_OFILES) vers.o ${LDFLAGS2} ${LIBS}` — libgcc 함수가 `_EXTERNAL` 스텁 바로 뒤에 놓이는 배치와 맞음. 실기 `/lib/libcc.a`(77600 B, fat) i386 판 `_muldi3.o`·`_udivdi3.o` 의 `__text`(otool -t, 읽기 전용)가 원본 바이트와 같음(python). 이 근거들은 원래 커널이 도구 체인 라이브러리를 링크했다는 판단을 강하게 뒷받침하지만, 어느 아카이브·명령이었는지를 유일하게 증명하지는 않음(codex 지적으로 문구 낮춤). 같은 libcc.a 가 `03_original/x86/userland/binaries/lib/libcc.a`(77600 B, SHA-256 bccd689e…, files.json 실기 대조)로 이미 보존돼 있고, 그 i386 판 구성원의 `__text`·`__const` 바이트가 원본과 같음(python, 재배치 0).
2. 재현 진단(07 아님): 실기 NeXT GCC 2.7.2 `/NextDeveloper/Source/GNU/gcc/libgcc2.c`(configure:2597–2618 의 링크 파일 tconfig.h = `#include "i386/xm-next.h"`, tm.h = `#include "i386/next.h"`, Makefile.in INCLUDES `-I. -I$(srcdir) -I$(srcdir)/config`, `-DIN_GCC -DIN_LIBGCC2 -D__GCC_FLOAT_NOT_NEEDED -DL_<name>`, Makefile.in:254 `LIBGCC2_CFLAGS = -O2 … -g1`) — `s5p362-depgcc` 은 기본 precomp cpp 에서 실패, `s5p362-depgcc2`(`-traditional-cpp`, `-O2`): `__text` 76·264 B 원본과 같은 바이트, `_udivdi3` 의 `__const` 256 B 가 원본 0x1d68b0 표와 같음(python find 1 곳). cc -M 으로 읽은 GCC 원문 14 개(두 판 같음): libgcc2.c·longlong.h·defaults.h·machmode.h·machmode.def·config/i386/{bsd,gas,i386,next,unix,xm-i386,xm-next}.h·config/next/{nextstep.h,nextstep.def}; 그 밖은 SDK 머리(ansi stddef 등)와 생성 tconfig.h·tm.h.
3. 확보(D050): 위 GCC 원문 14 개 + 라이선스·판 근거(COPYING·COPYING.LIB·README, version.c)를 실기에서 `cat`(cp -p 금지 — 빈 파일 함정)으로 `01_resources/upstream/next-gcc-2.7.2/` 아래 같은 상대 경로로 들이고, 대상 쪽 krsha256 과 호스트 SHA-256 을 대조; `01_resources/manifests/next-gcc-2.7.2.json`(파일별 SHA-256·크기·실기 경로), acquisition.json 에 출처 1 개, SOURCES.md 문단(GPL v2, libgcc2.c 의 libgcc 예외 문구 인용).
4. 07·기록 방식(D051, 사용자 결정 “-lcc 링크로 둠”): 07 에 libgcc 소스를 두지 않음. 두 객체는 새 표 `06_reconstruction/objects_toolchain.tsv`(objects_confirmed 와 같은 열, 등급 `L` = 도구 체인 라이브러리 구성원)에 기록 — 원본 범위, “/lib/libcc.a(_muldi3.o)” 구성원과 그 바이트 근거(실기 otool -t, 커널 바이트 일치), 재현 근거(s5p362-depgcc2 와 3 항 확보 뒤 01 원문으로 다시 하는 정식 run `s5p362-lg1`: 확보 사본을 스테이징해 같은 명령, `__text`·`__const` 바이트 일치를 l1_compare 로). functions.tsv 에는 두 함수 행(source_id `toolchain-libcc`, 인용 = 01 원문 libgcc2.c 의 정의 줄). PROVENANCE 행은 07 파일이 없으므로 두지 않고 01 쪽 SOURCES.md·manifest 로. 커버리지 집계는 A·P 와 따로 L 을 보고. 링크 단계(재구성 커널 전체 링크)는 이번 범위 밖 — 그때 `-lcc`·`-u __muldi3` 를 Darwin Makefile.i386 대로.
5. 예상: 2 객체, 340 B(+`__const` 256 B).

### codex 교차검토(kgombfgjz, gpt-6.1-sol) 판정 — plan 362

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 크기·주소(76·264·256 B, `__const` 끝 0x1d69b0), 바이트 일치 | 내 python(원본·진단 .o); 보존 libcc.a i386 판(fat 의 cputype 7 조각, ar 구성원) `_muldi3.o`/`_udivdi3.o` 섹션 대조 True·재배치 0 | ✅ |
| libcc.a 가 03_original/x86/userland 에 이미 보존(77600 B, bccd689e…) | files.json:106–112 읽음, 파일 해시 python | ✅ 채택 — 근거를 이 사본으로 |
| 객체 파일 전체가 아니라 섹션 바이트 동일로 기록 | 위 대조가 섹션 단위 | ✅ |
| `__udivdi3` 는 `--place-from-image` 만으로 `__const: unverified` → `--place __TEXT,__const=0x1d68b0` 필요 | l1_compare 두 번 실행: NOT_MATCH ['__TEXT,__const: unverified'] → place 붙여 OBJECT_MATCH | ✅ 채택 — 정식 run 에 명시 |
| `___clz_tab` 은 함수 행이 아니라 데이터 근거 | L1 함수 목록에 나옴 | ✅ 함수 행 2 개만 |
| `-traditional-cpp`·생성 머리·`-g1` 생략은 진단 재현 선택(역사적 명령의 증명 아님); `-g1` 이 바이트를 바꾸는지 같은 도구로 확인 | Makefile.in:254(실기 gcds 로 앞서 읽음) `-O2 … -g1` | ✅ 채택 — 정식 run 에 `-g1` 판 추가, 문구 “재현 선택” |
| `-M` 에 `-O2` 가 없음 — 같은 전처리 옵션으로 다시 | s5p362-depgcc2.cmd 1–2 행 읽음 | ✅ 채택 — 정식 run 에서 `-O2 -M` |
| 진단 run 의 input.expected 는 외부 GCC·SDK 입력을 묶지 않음 → 정식 run 은 확보 사본·SDK 사본을 스테이징 | input.expected 읽음(src/gen 2 개뿐) | ✅ 채택 |
| 함께 들일 파일 COPYING·COPYING.LIB·README·version.c(18 개), 고지 그대로, libgcc 예외는 그 판 문구 | — | ✅ 채택 |
| 06_reconstruction/README.md:20 의 compared/high 는 A·A*·P 만 → L 정의와 규칙 확장, 07_kernel/README.md 표 목록 갱신 | 06_reconstruction/README.md 15–25·07_kernel/README.md 1–10 읽음 | ✅ 채택 |
| `implementation_path` 에 아카이브 구성원 표기, `__const` 범위는 근거 파일에 | — | ✅ 채택 |
| 표를 읽는 기존 도구 없음 | 내 grep(10_tools·09_validation) 0 건 | ✅ |
| 실기 gcds 응답 없음으로 Makefile.in:254 등 미확인(codex 쪽) | 나는 gcds 로 Makefile.in:254·configure:2597–2618·libgcc2.c krsha256(a5031115…) 를 앞서 읽음 | ⏭️ codex 환경 한계 |

### 362 수정 계획(위 판정 반영)

- 3 항 확보 18 개(GCC 원문 14 + COPYING·COPYING.LIB·README·version.c) — 실기 `cat` 으로 01 에, 대상 krsha256 과 호스트 SHA-256 대조, manifest·acquisition.json·SOURCES.md.
- 정식 run `s5p362-lg1`: 스테이징 = 확보 사본 14 + 생성 tconfig.h·tm.h + 실기 목록으로 대조한 SDK 머리 5(ansi/stddef.h 등, 07 nextdev 또는 SDK 미러); 명령: `-O2 -M`(두 판), `-O2` 컴파일(두 판), `-O2 -g1` 컴파일(두 판, 바이트 영향 확인). L1: muldi3 `--place-from-image`, udivdi3 `--place-from-image --place __TEXT,__const=0x1d68b0`.
- 기록: `06_reconstruction/objects_toolchain.tsv`(objects_confirmed 와 같은 열; source 칸 = `03_original/x86/userland/binaries/lib/libcc.a(i386: _muldi3.o)` 등, grade `L`), functions.tsv 2 행(source_id `toolchain-libcc`, source_revision = 확보 manifest, 인용 = 01 libgcc2.c 정의 줄, implementation_path = 아카이브 구성원), 근거 파일에 `__const` 범위·구성원 해시·진단/정식 run. 06_reconstruction/README.md 에 L 정의와 compared/high 규칙 확장, 07_kernel/README.md 표 목록. 커버리지는 L 을 따로.

### 결과(2026-10-07, plan 362)

- 확보(D050): `01_resources/upstream/next-gcc-2.7.2/` 18 파일(합 291501 B), 대상 krsha256 = 호스트 SHA-256·크기(18/18), `manifests/next-gcc-2.7.2.json`, acquisition.json 출처 +1(형식 indent=2 유지, diff 는 추가만), SOURCES.md 문단(이전 Net/2 문단이 objc-1 문단 사이에 끼어 있던 것을 그 뒤로 옮김).
- 정식 run `s5p362-lg1`(스테이징 `s5p362-stage-libgcc.py` 21 파일): `-O2 -M` 두 판이 21 개 모두 읽음; `-O2` 객체 섹션 = 진단 s5p362-depgcc2; `-g1` 판 섹션 바이트 같음; L1 muldi3 OBJECT_MATCH, udivdi3 OBJECT_MATCH(`--place __TEXT,__const=0x1d68b0`). 보존 libcc.a i386 구성원 섹션 = 원본.
- 기록(D051): 새 표 `06_reconstruction/objects_toolchain.tsv` 2 행(등급 L), functions.tsv 4285→4287(source_id toolchain-libcc), 근거 `evidence/x86-libcc-libgcc2.md`, 06_reconstruction/README.md·07_kernel/README.md 에 L 정의. 07 에 소스 없음·PROVENANCE 행 없음.
- 범위(python): A 301 obj 572959 B (67.29%), P 68 obj 211931 B (24.89%), L 2 obj 340 B (0.04%); A+P 92.18%, A+P+L 92.22%, rem 66206.

## 363. S5-P349 세부 계획 — `bsd/dev/i386/EventShmemLock.s`(+`.h`)·`bsd/dev/i386/kbd_entries.m`(D030·D032; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): EventShmemLock.s/.h·kbd_entries.m/.h 는 Darwin 0.1 kernel/bsd/dev/i386(ppc 판·machine 판 머리도 있음)에만 있음 — NeXTMach mk-108.1·Mach4·SDK 목록에 같은 이름 없음(find·실기 목록 grep 0) → D030(.s·.m)·D032(.h).

0. 원본(python·L1): ev_lock·ev_unlock·ev_try_lock `__text` [0x1a0d4c, 0x1a0d8d) 65 B(앞 0x1a0d49 뒤 00×3, 뒤 00×3 → 0x1a0d90; 지역 레이블 `_spin` 은 원본 심볼 표에 없음); keyboard_reboot·StealKeyEvent·steal_keyboard_event·register_keyboard_entries `__text` [0x1a0d90, 0x1a0e46) 182 B + `__DATA,__data` 8 B @0x1e4b78(뒤 00×2 → 0x1a0e48 `_PCcreate`). Darwin files.i386:69 `bsd/dev/i386/EventShmemLock.s optional event`.
1. 진단(07 아님, `diag_k07.py` — 07 사본 + Darwin 원문, kernel C 꼴 -O3·-fwritable-strings): `s5p363-devl2`(EventShmemLock.s, 머리 EventShmemLock.h 를 nextdev_private/bsd/dev/i386 에) **OBJECT_MATCH**(4: 레이블 3 + `_spin`), `s5p363-dkbd4`(kbd_entries.m, 기존 D032 kbd_entries.h) **OBJECT_MATCH**(4, `__data` 0 차이). Darwin 원문 그대로 맞음. (`s5p363-dkbd1–3` 은 wipbuild_abs 의 스테이징 경로를 잘못 준 실패 run.)
2. 07: `src/bsd/dev/i386/EventShmemLock.s`·`src/bsd/dev/i386/kbd_entries.m`(D030 머리 주석, 본문 Darwin 원문 그대로 — 첫 코드 줄 앞의 Apple·NeXT 고지·설명 주석을 머리 주석으로 바꿈, kbd_entries.h 사본 선례와 같음), `nextdev_private/bsd/dev/i386/EventShmemLock.h`(D032, 같은 방식). 모두 “nearly the same as Darwin 0.1 kernel/bsd/dev/i386/<file>”.
3. 빌드·검사: kernel C 꼴로 07 에서(진단과 같은 명령, 스테이징만 07) → OBJECT_MATCH → relcheck → 실기 cc -M(둘) → 기록. kbd_entries.m 은 ObjC 모듈 기록 없음(objc.json 에 이름 없음)이라 ABSROOT 불필요. 기록 도구: record_objc360(kind asm: 레이블 줄 — `.h` 의 `LEAF(_ev_lock, 0)` 꼴도 찾도록 보완, `_spin:`; kind 기본: kbd_entries 의 C 함수), 문구 D030/D032, ref_path darwin01/kernel/bsd/dev/i386/…, extra_files 로 EventShmemLock.h PROVENANCE·MODIFICATIONS.
4. 예상: A 2, 65 + 182 = 247 B.

### codex 교차검토(klxgjifbo, gpt-6.1-sol) 판정 — plan 363

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·채움(65 B·182 B·`__data` 8 B, 채움 00×3·00×3·00×2, 합 255 B) | 내 python(원본 0x1a0d44–0x1a0e4c 바이트)·두 L1 json | ✅ |
| `__data` “inferred, verified by L1d” 는 파일 기반 섹션이라 A 에 충분 | 06_reconstruction/README.md:24 읽음(A = OBJECT_MATCH + 경계 증명서) | ✅ |
| 링크 순서 PCPointer.m → EventShmemLock.s → kbd_entries.m(Darwin files.i386:68–70), PCPointer 끝 0x1a0d49 | files.i386:66–70 읽음; evidence/x86-PCPointer.md 의 [0x1a0ac8, 0x1a0d49) | ✅ |
| EventShmemLock.h 는 DRIVER_PRIVATE 아래 asm — 현재 C/ObjC 소비자 없음(선언은 SDK ev_types.h) | 내 grep(07·Darwin) — .s 와 machine 판 머리뿐 | ✅ |
| Darwin PS2Keyboard.m:670 도 StealKeyEvent 정의(files.i386 에 없음, 현재 충돌 없음) | PS2Keyboard.m:668–672 읽음 | ✅ 근거에 적음 |
| `.s` 는 Darwin 에서 S_RULE(`${KCC} -c ${SFLAGS}`)로 따로 — 우리 명령은 C 꼴 플래그로 맞춘 재현 선택 | Makefile.template:280–288·Makefile.i386:49 `KCC=cc -static -nostdinc -nostdlib -traditional-cpp` 읽음 | ✅ 기록에 “재현 선택” |
| 코드는 머리의 LEAF 55·76·93, `_spin:` 60(지역 레이블, 함수 행 아님) | EventShmemLock.h grep(55·60·66·76·81·93·101) | ✅ 기록 도구 보완(LEAF), `_spin` 은 행에서 뺌 |
| D030/D032 문구 “body verbatim, head replaced”, 판 해시 | PROVENANCE kbd_entries.h 행 선례 | ✅ |
| cc -M 실제 의존 보존 | — | ✅ 계획대로 |

### 결과(2026-10-07, plan 363)

- 07: `src/bsd/dev/i386/EventShmemLock.s`·`src/bsd/dev/i386/kbd_entries.m`(D030), `nextdev_private/bsd/dev/i386/EventShmemLock.h`(D032) — 본문 Darwin 원문 그대로, 첫 코드 줄 앞 고지·설명 주석을 머리 주석으로.
- 빌드(`iter_k07.py`, 07 에서 스테이징): `s5p363-r1evl` OBJECT_MATCH(4: 레이블 3 + 지역 `_spin`), `s5p363-r1kbd` OBJECT_MATCH(4, `__data` 0 차이); relcheck 0 둘; 실기 cc -M `s5p363-depevl`(4 파일)·`s5p363-depkbd`(148 파일) 모두 07 쪽.
- 기록(record_objc360 — `LEAF(` 줄 찾기·지역 레이블 제외 보완): functions.tsv 4287→4294(+3 +4; 인용 줄 EventShmemLock.h:25·46·63, kbd_entries.m:40·48·60·70 열어 확인), objects_confirmed 302→304, PROVENANCE 1006→1009(.s·.h·.m), MODIFICATIONS 479→482 → **A** 2.
- 범위(python): 이번 247 B. A 303 obj 573206 B (67.32%), P 68 obj 211931 B (24.89%), L 2 obj 340 B (0.04%); A+P 92.21%, A+P+L 92.25%, rem 65959.
- 조사 메모: `devswAndVfssw.m`(0x1a9ad3–0x1a9f1c, 1097 B, libDriver/Kernel, 모듈 기록 없음)은 Darwin 판이 4.2 SDK 머리와 어긋남(`seltrue` 선언 없음 — SDK systm.h 에 없고 Darwin 커널 systm.h:136 에만; `D_TAPE`·`putc_fcn_t` 없음, `IOAddToBdevsw` 형이 SDK devsw.h:36 과 다름; 진단 `s5p364-ddevsw1/2`) → 원본 바이트로 작성(D024) 대상, 뒤로 둠. 0x15a628 의 84 B 는 plan 245–320:621 대로 보류 유지. [2026-10-08: D056 으로 해제 — 07 kern/ipc_xxx.c 끝에 둠, plan 392]

## 364. S5-P350 세부 계획 — `machdep/i386/locore.s`(D029; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): Darwin 0.1 kernel/machdep/i386/locore.s(바탕), NeXTMach mk-108.1 next/locore.s(m68k — 쓸 수 없음), Mach4 i386/kernel/i386/locore.S(다른 계보; 원본 구간 이름 268 개 중 0 개, Darwin locore.s 단어에는 268 개 모두 — python) → D029(Mach4·NeXTMach 에 쓸 수 있는 i386 판 없음, Darwin 원문 바탕·고지 유지, 다른 부분만 plan 표시).

0. 원본(python): `__text` [0x186138, 0x186fdc) — 앞 start.s(plan 292) 끝 0x186135 뒤 00×3; 심볼 268(_trp_divr … _longjmp). Darwin files.i386 의 locore.s 자리는 start.s 다음.
1. assym: Darwin locore.s 는 생성 머리 `<assym.h>`(Makefile.template:1075–1082 genassym.c → `cc -S` → genassym.awk)를 import. Mach4 에는 assym.h 가 없고 `.sym`→`i386asm.h` 방식. Darwin genassym.c 는 4.2 머리로 컴파일되지 않음(`s5p364-dga1`: confdep.h(config 생성, TIMEZONE·MAXUSERS·DST 뿐 — NeXTMach src/config/mkmakefile.c:950–955) 없음; `s5p364-dga2`(진단용 빈 confdep.h): `struct proc` 에 `p_priority`·`p_siglist` 없음, genassym.c:98·100). locore.s 가 쓰는 assym 값은 6 개(KDSSEL·LDATASEL·NULLSEL·EBP·ERR·EFL; `trapno` 는 주석에만) → plan 292 start.s 선례대로 `#import <assym.h>` 대신 원본 값으로 지역 정의(빌드 선택): KDSSEL 0x10·LDATASEL 0x50·NULLSEL 0(0x186d27·0x186d31·0x186d38 `mov ax`), EBP 0x18(0x186d40 `lea ebp,[esp+0x18]`), ERR 0x34·EFL 0x40(0x186de6/0x186dea).
2. 바이트가 요구하는 수정(plan 364 표시): `__call_with_stack` 끝이 Darwin `call *%eax; 0: hlt; jmp 0b` 가 아니라 `jmp *%eax`(원본 0x186f86 `ff e0`, 그 뒤 `_setjmp` 까지 4 B 짧음).
3. 진단(07 아님, diag_k07): `s5p364-dloc1`(원문 그대로: assym.h 없음 실패), `s5p364-dloc2`(1 항만: 끝 네 심볼이 4 B 밀림, 그 앞 차이는 모두 재배치 자리), `s5p364-dloc3`(1·2 항) **OBJECT_MATCH**(268).
4. 07: `src/machdep/i386/locore.s` = Darwin 원문(Apple·NeXT 고지 유지) + 1·2 항(plan 364 표시, 1 항은 “빌드 선택”). 빌드 iter_k07(kernel C 꼴; Darwin S_RULE 는 SFLAGS — 재현 선택으로 적음) → relcheck → cc -M → 기록(record_object, darwin01 바탕, LEAF 줄은 fn_source 또는 도구 보완).
5. 예상: A 1, 3747 B(+뒤 00×1 → 0x186fdc `_catch_interrupt`).

### codex 교차검토(k8o95l662, gpt-6.1-sol) 판정 — plan 364

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| text 는 3747 B([0x186138, 0x186fdb)), 뒤 00×1, 앞 00×3 | dloc3 L1 json size 3747; 원본 0x186fd8 `0000c300 5589…`; symbols.tsv `_catch_interrupt` 0x186fdc | ✅ 채택 — 5 항 고침(내 오기 3748) |
| 원본 이름 268 개·주소 266(별칭 _setjmp/_set_label, _longjmp/_jump_label); Darwin 단어에 268, Mach4 0 | 내 python | ✅ |
| 여섯 값이 모든 사용처(5·5·5·5·3·3)에서 같음, 그 밖 assym 이름 없음, trapno 는 주석뿐 | 내 python: 주석 뺀 소스 사용 횟수 = 원본 명령 개수(5·5·5·5·3·3), trapno 0 | ✅ |
| `jmp *%eax` 는 0x186f86(진단 주석 0x186f7e 틀림) | 원본 0x186f7c 12 B `8b4424048b64240889e5ffe0` | ✅ 채택 — 07 표시 주석은 0x186f86 |
| 그 밖 비재배치 차이 없음 | dloc2 차이 구간 목록(앞서 내 python: 모두 재배치 자리) + dloc3 OBJECT_MATCH | ✅ |
| 지역 정의는 plan 292·D029 와 맞음(빌드 선택 표시) | start.s:38–43·PROVENANCE:664 읽음 | ✅ |
| 지역 레이블 trap_handler·interrupt 는 행에서 빼고, 매크로 진입은 호출 줄에, GPROF mcount 는 제외 | L1 함수 이름 270(지역 2) | ✅ 기록 때 |
| Darwin 134 행에 폼피드 — splitlines 쓰면 줄 번호 밀림 | locore.s 의 `\x0c` 1 개, 134 행 `//\x0c` | ✅ 채택 — 줄 번호는 `\n` 으로 셈 |

### 결과(2026-10-07, plan 364)

- 07: `src/machdep/i386/locore.s` = Darwin 0.1 원문(Apple·NeXT·CMU 고지 유지, D029) + plan 364 두 곳(assym 값 6 개 지역 정의 — 빌드 선택; `__call_with_stack` 끝 `jmp *%eax`, 원본 0x186f86).
- 빌드 `s5p364-r1loc`(iter_k07, 07 에서) **OBJECT_MATCH**(268), relcheck 0, 실기 cc -M `s5p364-deploc` 3 파일 모두 07 쪽.
- 기록(record_object, darwin01 바탕, fn_source = 매크로 호출·LEAF/X_LEAF 줄 268 개를 `\n` 기준으로 07·Darwin 양쪽에서 찾아 같은 줄 내용 확인): functions.tsv 4294→4562(+268), objects_confirmed 304→305, PROVENANCE 1009→1010, MODIFICATIONS 482→483 → **A**.
- 범위(python): 이번 3747 B. A 304 obj 576953 B (67.76%), P 68 obj 211931 B (24.89%), L 2 obj 340 B (0.04%); A+P 92.65%, A+P+L 92.69%, rem 62212.

## 365. 진단 메모 — `machdep/i386/machine_clock.c` 남은 3 B(plan 240.1 이어서; 07 손대지 않음, 2026-10-07)

- 대상: clock_timer_init 끝 원본 `mov [0x1e75d8],si; mov eax,esi; mov [0x1e75da],ax`(0x187b47–0x187b56) 뒤 timer_write 가 `last_count` 를 전역에서 두 번 읽음. plan 240.1 의 18 꼴(대입 순서·연쇄·형변환·인라인 설정 함수)은 모두 두 저장을 `si` 에서 바로 함.
- 이번 시도(scratchpad `mcs/`, diag_k07 run `s5p365-mc*`):
  - 구조체 멤버 꼴(Darwin `system_clock` 처럼 시각·last·reload 를 한 구조체로; 원본 bss 0x1e75d0·d8·da 연속) s1–s3: 저장 꼴 그대로(둘 다 si), 구조체 때문에 `__bss` 배치가 모호해져 L1 은 더 나빠짐.
  - 반환값 꼴 t1(`reload = mc_timer_const(count)`, unsigned short 를 돌려주는 인라인): **원본과 같은 `mov eax,esi; mov [reload],ax` 가 나옴**, 그러나 timer_write 가 전역 대신 스택 사본(`[ebp-0x14]`)을 읽고 크기 1957 B. t2(연쇄)·t3(unsigned int 반환)은 아님.
  - 계산 전체를 인라인 함수로 u1·u2: 두 저장 모두 ax, 스택 사본 남음(1953 B). u3 은 t1 과 같은 꼴.
- 판단: 두 번째 저장이 eax 를 거치는 것은 반환값(또는 그에 준하는 별도 값)으로 보이나, 그 꼴이 timer_write 인자 처리(전역 재읽기)까지 바꿔서 아직 같은 꼴을 못 찾음. 보류 유지(작업본 machine_clock_wip_it8.c, 07 에 없음). 다음 시도 후보: timer_write 인자를 다른 식(예 `reload` 나 반환값)으로, timer_inline.h 의 인자 형.

## 366. S5-P351 세부 계획 — `bsd/netinet/in_bootp.c`(NeXTMach 바탕 + 작성, D013·D022·D024·D027; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): NeXTMach mk-108.1 `nextif/in_bootp.c`(바탕, 4.3BSD API — SDK 머리와 맞음), Darwin 0.1 `kernel/bsd/netinet/in_bootp.c`(1997 4.4Lite 이식판 — `uio_rw`·`MSG_WAITALL`·`sin_len`·`if_eflags` 로 4.2 머리에 컴파일 안 됨, `s5p366-dbp2`; 구조·문구 참고), Mach4 없음. 앞선 plan 52 는 Darwin 판만 탐침(`if_eflags`).

0. 원본(python·IDA 사본 scratchpad/ida): `__text` [0x124154, 0x124e0e) 3258 B + 00×2(→0x124e10); 함수 13(원본 순서): in_bootp 484, 정적 initnet 360, buildpacket 240, in_bootp_bptombuf 380(내보냄), sendrequest 852, openconsole 112, closeconsole 24, processreply 324, setaddress 140, makeifreq 100, kmgets 196, timeout 28, promisctimeout 18. `__data` 0x1dbaac 정적 플래그(0) + 문자열("NeXT", "mget", 안내문, "Network responded!\n", "%L", "Configuring Network", "%s", "\n").
1. 4.2 판의 성격: Darwin HISTORY 의 1994-01 “Allow Sexy Net Init while netbooting / Function prototype cleanup” 판(4.4 이식 전)에 해당 — 진입 함수 먼저·정적 원형, 콘솔은 alert 패널(정적 `alertShowing`), `kmgets` 줄 입력, processreply 는 `kmioctl`, 끝 `if (!error) closeconsole` 는 Darwin 꼴; `u.u_qsave`/setjmp, `if_output_mbuf`, 옛 mbuf(MGET/MCLGET·m_more), ifioctl 3 인자, `if_flags` 의 IFF_AUTOCONF 는 NeXTMach 꼴.
2. 진단(07 아님, diag_k07): `s5p366-dbp1`(NeXTMach 그대로: mon/bootp.h·nextdev/kmreg.h 없음, sys/boolean.h 가 machine/boolean.h 를 찾지 못함), `dbp3`(머리 세 줄을 SDK `netinet/bootp.h`·07 `bsd/dev/kmreg_com.h`(D032)·`mach/boolean.h` 로: `alert_key` 만 실패), `dbp4`(아래 3 항 수정: 함수 순서·크기 모두 원본과 같고 buildpacket 만 4 B 짧음), `dbp5`(ip_id htons: 12/13, initnet 1 B), `dbp6`(IFF_NOTRAILERS) **OBJECT_MATCH**(13, `__data` 0 차이).
3. 07 `src/bsd/netinet/in_bootp.c` = NeXTMach 원문(NeXT 고지·HISTORY 유지, D013) + plan 366 수정(각 자리 표시):
   ① 머리 세 줄(위 2 항, 빌드에 필요 — 4.2 SDK·07 사본 이름);
   ② 정적 원형 목록·`static boolean_t alertShowing = FALSE;`·함수 순서(in_bootp 를 맨 앞으로; 원본 순서) — 바이트(함수 배치·정적)가 요구;
   ③ initnet·buildpacket·timeout·promisctimeout·getpacket·sendrequest·setaddress 를 static(원본 기호 표에 없음), promisctimeout 은 `return (0)`(원본 `xor eax,eax`);
   ④ initnet: `IFF_UP | IFF_NOTRAILERS`(원본 `or al,0x21`), `htons(IPPORT_BOOTPC)`(원본 0x12445d `ror cx,8`); buildpacket: `htons(ip_id++)`, `rootdir` 조건 없이 `nv_version = 1`; bptombuf: ether_header 만큼 m_off/m_len 조정 없음;
   ⑤ sendrequest: 6 번째 인자 `struct vnode **console_vpp`, `while (TRUE)`(alert_key 없음), `htons(IPPORT_BOOTPS)`, 20 초 뒤 `*console_vpp == NULL` 이면 openconsole 후 printf 안내(“Type Control-C …” 문구 — 원본 문자열), 응답 받으면 안내했었으면 printf("Network responded!\n"), ETIMEDOUT 꼬리·alert_done 없음;
   ⑥ openconsole·closeconsole·processreply·kmgets(와 ② 의 원형 목록·alertShowing): **Darwin 0.1 텍스트를 가져와 원본 바이트로 확인**(codex 지적 뒤 고침 — 처음 적은 “원본 바이트로 작성(D024)/D027” 은 사실과 다름) → D053 대로 Darwin 출처 표시: openconsole 은 `u.u_qsave` 저장·복원 사이에 alert(Darwin 에 없는 부분), closeconsole 은 플래그 0 후 alert_done(조건 없음), processreply 는 kmioctl TIOCFLUSH·kmgets, noecho/echo 함수 없음;
   ⑦ in_bootp: sendrequest 에 `&vp`, 끝 `if (!error) closeconsole(vp)`.
4. 빌드·검사: iter_k07 → relcheck → 실기 cc -M → zerofill(`__bss` 없음 — 확인) → 기록(record_object, nextmach 바탕, 작성 함수 행은 D024/D027 문구).
5. 예상: A 1, 3258 B.

### codex 교차검토(kgxks3tnt, gpt-6.1-sol) 판정 — plan 366

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모든 동작 변경이 3①–⑦ 안, 목록 밖 변경 없음; 다만 `in_bootp` 의 명시 `int`, timeout 의 `static void`(암시 int 대신)는 따로 적어야 | w4/w6 생성 스크립트의 치환 목록 = 내 수정 전체; NeXTMach :711·:241 읽음 | ✅ 채택 — MODIFICATIONS 문구에 넣음 |
| 계획의 “machine/boolean.h” 는 바꾼 줄이 아니라 오류 메시지 — 바꾼 줄은 sys/boolean.h | NeXTMach :20 `#import <sys/boolean.h>` | ✅ 채택 — 2 항 고침(내 오기) |
| client port 는 `ror cx,8`(ax 아님) | 원본 0x12445d `ror cx, 8`(odis3) | ✅ 채택 — 4 항 고침(내 오기) |
| 13 함수·3258 B·끝 00×2(다음 `_in_pcballoc` 0x124e10) | 내 fsz.py(크기·순서), L1 OBJECT_MATCH | ✅ |
| kmgets 본문은 Darwin 과 글자 그대로, 원형 목록은 공백 빼면 Darwin :90–123 과 같음, processreply 도 거의 Darwin | 내 python: kmgets 같음 True, 원형 목록 True; processreply 는 내가 Darwin 본문을 옮겨 쓴 것 | ✅ **내 기록이 틀림** — “원본 바이트로 작성(D024)/D027” 이 아니라 Darwin 텍스트 사용 → 사용자 결정 D053(Darwin 출처 표시, APSL 고지 추가) |
| D030 은 해당 없음(NeXTMach 대응 판 있음) | D030 조건(DECISIONS:34) | ✅ |
| 머리 세 바꿈은 맞는 파일(SDK·07 사본), 스테이징의 Darwin ppc 머리 5 개는 manifest 일 뿐 — cc -M 으로 확인 | 실기 cc -M `s5p366-depbp`: 읽은 80 개 모두 07 | ✅ |
| `__data` 178 B [0x1dbaac, 0x1dbb5e) 순서(플래그, "NeXT", "mget", 안내, "Network responded!", "%L", "Configuring Network", "%s", "\\n") | L1 `__data` 0 차이; 원본 문자열 덤프(앞서 python) | ✅ 근거 파일에 적음 |
| D013 기록에 NeXTMach 원래 함수 줄 | 기록 functions.tsv 의 nextmach:N 인용 | ✅ (07 줄은 기록 뒤 정의 줄로 고침 — 아래) |

### 결과(2026-10-07, plan 366)

- 07: `src/bsd/netinet/in_bootp.c` = NeXTMach 원문(NeXT 고지) + Darwin APSL 고지(“plan 366 (Darwin)” 부분용) + plan 366 표시 29 곳.
- 빌드 `s5p366-r1bp`(iter_k07) **OBJECT_MATCH**(13, `__data` 0 차이), relcheck 0, 실기 cc -M `s5p366-depbp` 80 파일 모두 07.
- 기록 도구 record_object: 원본이 다른 객체의 초기화된 `__data` 정의로 둔 공통 심볼(_etherbroadcastaddr·_nmbclusters)은 크기 검사에서 뺌(record_partial.py:50 과 같은 규칙; 쓰기 전 단언에서 멈췄던 것). 기록 뒤 함수 행 5 개의 07 줄이 여러 줄 원형의 첫 줄을 가리켜 정의 줄로 고침(223·306·455·729·771), PROVENANCE·MODIFICATIONS 출처 칸을 `nextmach+darwin01`(D053).
- 표: functions.tsv 4562→4575, objects_confirmed 305→306, PROVENANCE 1010→1011, MODIFICATIONS 483→484 → **A**.
- 범위(python): 이번 3258 B. A 305 obj 580211 B (68.14%), P 68 obj 211931 B (24.89%), L 2 obj 340 B; A+P 93.04%, A+P+L 93.08%, rem 58954.

## 367. 진단 메모 — `bsd/ufs/ufs_lockf.c`(plan 295 이어서, D052 Net/2 원문 확보 뒤; 07 손대지 않음)

- D052: TUHS Net/2 `sys/ufs/ufs_lockf.c`(7.7 Berkeley 7/2/91)·`lockf.h` 확보(manifests/net2-ufs-lockf.json, SOURCES.md).
- 대조: 4.2 판은 NeXT 변형(lf_svnode·posix_proc·LF_NOWAIT·lf_free)이라 Net/2 와 구조가 다름; 작업본 g1 은 이미 원본 바이트 꼴. 원본 lf_setlock 은 `priority | PCATCH` 를 sleep 자리에서 계산(0x14224c `or ah,1`) — 작업본과 같음.
- 시도(diag_k07 `s5p367-lf*`): g1 재현 56 B(setlock 18·clearlock 38); c9(Net/2 꼴 svnode 지역 변수) 같은 코드; r1–r3(`register` 조합) 같은 코드. 보류 유지.

## 368. S5-P352 세부 계획 — `bsd/netinet/tcp_input.c`(4.3BSD-Net/2 바탕, D048·D013·D024; plan 353 이어서; 코딩 전, 2026-10-07)

참조(파일명, 모든 트리): 4.3BSD-Net/2 `sys/netinet/tcp_input.c`(D048, 바탕), NeXTMach mk-108.1 `netinet/tcp_input.c`(4.3-Reno, 두 줄 꼴 참고), Darwin 0.1 판(4.4Lite, 쓰지 않음), Mach4 없음.

0. 원본(python·L1): `__text` [0x12857c, 0x129d8c) 6160 B — tcp_reass 448·tcp_input 4944·tcp_dooptions 148·tcp_pulloutofband 112·tcp_xmit_timer 208·tcp_mss 298 + 00×2(→0x129d8c `_tcp_output`) — 객체 text 6158 B, 다음 기호까지 6160 B(codex 지적으로 고침); `__data` 은 L1 기호 배치 0 차이.
1. 진단(07 아님, diag_k07 `s5p368-tn*`; 초안 scratchpad tcp/): n3(plan 353 초안 n2 + SB_NOTIFY 두 번째 자리·tcp_mssdflt) — 크기 tcp_input −28, 나머지 같음, tcp_reass MATCH; n4(ip_hl·MAX) tcp_input −16; n5(SYN_RECEIVED) tcp_input MATCH, tcp_mss 만 DIFF; n6–n8 tcp_mss 꼴 맞춤 **OBJECT_MATCH**; n9 — 초안의 tcp_mss(디컴파일로 다시 쓴 Reno 꼴)를 Net/2 원문 tcp_mss 로 되돌리고 세 곳만 고쳐 **OBJECT_MATCH**(Darwin 텍스트 없음); n10 — Net/2 원문에 아래 수정만 plan 368 표시로 다시 적용 **OBJECT_MATCH**(6).
2. 07 `src/bsd/netinet/tcp_input.c` = Net/2 원문(Berkeley 고지 유지) + plan 368(표시 15):
   ① include 를 4.2 SDK 이름(`#import <sys/…>`·`<net/…>`·`<netinet/…>`, `kern/queue.h`; Net/2 의 "malloc.h" 는 빼고) — 빌드 필요;
   ② IP 옵션 검사 `((struct ip *)ti)->ip_hl > (sizeof (struct ip) >> 2)`·`ip_stripoptions((struct ip *)ti, 0)` — 원본 0x12877a 꼴, NeXTMach :210–211 과 같음;
   ③ 4.2 mbuf/sockbuf/sockaddr(헤더에 없는 필드): `m_pkthdr` 줄 삭제, `m_data`→`m_off` 두 곳, `M_BCAST`→`in_broadcast(ti->ti_dst)` 두 곳, `sin_len`·`sa_len` 줄 삭제, `SB_NOTIFY`→`(SB_WAIT)||sb_sel` 두 곳;
   ④ `rcv_wnd = MAX(…)`(원본 인라인 비교 0x128cbd–0x128cdb, NeXTMach :365 과 같음);
   ⑤ 첫 상태 switch 에 `case TCPS_SYN_RECEIVED:` 를 SYN_SENT 와 함께(원본 0x128ce9–0x128cf9 범위 검사), RST 처리 뒤 `if (tp->t_state == TCPS_SYN_RECEIVED) break;`(원본 0x128ec3) — 원본 바이트로 작성(D024);
   ⑥ tcp_mss: `if (offer && mss > offer) mss = offer; mss = MAX(mss, 32);`(원본 0x129cec–0x129d04), RTV_* 블록은 4.2 머리에 RTV_MTU 등이 없어 꺼짐(원문 그대로).
3. 빌드·검사: iter_k07 → relcheck → 실기 cc -M → 기록(record_object, base `net2`(새 종류: TUHS URL·manifest sha256) — 도구에 net2 종류 추가 필요).
4. 예상: A 1, 6158 B(+ 00×2).

### codex 교차검토(kwvk9k48v, gpt-6.1-sol) 판정 — plan 368

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모든 변경이 2①–⑥ 안, 표시 15, 목록 밖 구현 변경 없음 | n10 생성 스크립트의 치환 목록 = 내 수정 전체 | ✅ |
| tcp_mss 298 B + 00×2, 객체 text 6158 B(계획의 300·6160 은 채움 포함) | 원본 0x129d89 `ret`, 0x129d8a `00 00`(odis3) | ✅ 채택 — 0·4 항 고침(내 표기 오류) |
| 인용 주소 다섯(0x12877a·0x128cbd–0x128cdb·0x128ce9–0x128cf9·0x128ec3·0x129cec–0x129d04) | 내 디스어셈블(앞서 0x128c9c–·0x128e68–·0x129c60–) | ✅ |
| Darwin 텍스트 추가 없음(tcp_mss 는 Net/2 원문에서 sa_len·offer·MAX 만 다름) | 내 python diff(Net/2 대비 96 줄; n9 이 Net/2 tcp_mss 로 OBJECT_MATCH) | ✅ D053 문제 없음 |
| RTV_* 블록은 4.2 route.h 에 RTV 없어 꺼짐, m_pkthdr·m_data·M_BCAST·sa_len·sin_len 은 4.2 구조에 없음, SB_WAIT·sb_sel 있음 | OBJECT_MATCH(코드 바이트가 꺼진 블록을 포함하지 않음) + 진단 컴파일 오류 이력(plan 353) | ✅ |
| malloc.h 없앰은 빌드 조정, in_broadcast 두 호출은 원본 0x128d25·0x1299af | L1 참조 차이 0 | ✅ |
| Net/2 판 7.25 (Berkeley) 6/30/90, 함수 줄 97·204·1208·1255·1285·1369 | net2 tcp_input.c:33 및 각 줄 sed | ✅ 기록에 씀 |
| NeXTMach 에서 가져온 줄(include 꼴 :22–46, ip_hl :210–211, MAX :365)은 D013 대로 NeXTMach 출처·고지 필요 — NeXTMach 파일은 CMU 고지 + Berkeley 고지 | NeXTMach tcp_input.c:1–21 읽음(CMU 1987 고지) | ✅ 채택 — 07 파일에 “plan 368 (NeXTMach)” 부분과 CMU 고지를 적고 PROVENANCE 를 `net2+nextmach` 로 |
| tcp_mssdflt 는 tcp_subr.c:49 정의, 여기서는 extern 만 | 07 tcp_subr.c:49 grep | ✅ |

### 결과(2026-10-07, plan 368)

- 07: `src/bsd/netinet/tcp_input.c` = Net/2 원문(Berkeley 고지) + NeXTMach 고지 블록(“plan 368 (NeXTMach)” 부분용, CMU 1987) + plan 368 표시 16.
- 빌드 `s5p368-r1tcp`(iter_k07) **OBJECT_MATCH**(6), relcheck 0, 실기 cc -M `s5p368-deptcp` 58 파일 모두 07.
- 기록(record_object, 새 종류 `net2` — TUHS URL·manifest; 함수 인용 net2 :97·204·1208·1255·1285·1369, 07 정의 줄 112·219·1225·1272·1302·1386 확인): functions.tsv 4575→4581, objects_confirmed 306→307, PROVENANCE 1011→1012(`net2+nextmach`), MODIFICATIONS 484→485 → **A**.
- 범위(python): 이번 6158 B. A 306 obj 586369 B (68.87%), P 68 obj 211931 B (24.89%), L 2 obj 340 B; A+P 93.76%, A+P+L 93.80%, rem 52796.

## 369. 진단 메모 — `bsd/dev/i386/FBConsole.c`(plan 341 이어서; 07 손대지 않음, 2026-10-07)

- 도구: diag_k07(07 사본 + 작업본, 진단용 머리 nextdev_private/bsd/dev/i386/FBConsPriv.h·nextdev_private/bsd/i386/param.h·src/bsd/dev/i386/ohlfs12.h — 모두 Darwin 0.1 사본, 07 에 둘 때는 D032 절차 필요), 함수별 비교 scratchpad `fbc/fmatch.py`(재배치 바이트 가림, 원본 [0x19ba18, 0x19f0a0) 안 최적 위치), 정렬 `alf.sh`.
- 기준선 `s5p369-fb1`(plan 341 작업본 body.c): 16 함수 중 11 같음(FlipCursor·Erase·BltChar·FBPutC·SetTitle·InitWindow·Init·FBAllocateConsole·Free·PutC·GetSize).
- 이번에 맞춘 것(작업본 scratchpad `fbc/v5.c`, 원본 바이트로 작성 D024):
  - `FBAllocateVBEConsole`(0x19ecb8, 212 B)·`VBEModeInfo2IODisplayInfo`(0x19ed8c, 540 B): 참조 트리에 없는 함수. 부트 매개변수 블록(0x11000)의 +0x1854 프레임버퍼·+0x1858 VBE 모드 정보(NeXT 압축 꼴: mode·attributes·width·height·rowBytes·bpp·memoryModel·R/G/B 마스크 크기·위치·+20 physBase)를 지역 정의(D035 꼴); IODisplayInfo 채우기(flags 2, parameters = mode, memorySize = height × rowBytes, 알 수 없는 bpp 는 modeUnavailableFlag |= MODE_OTHER_INVALID), 색 루프는 `n = bpp − pos − 1` 을 루프 앞에서 — `s5p369-fb5` 두 함수 0 차이.
  - `Restore`(0x19efcc, 132 B): `if (save)` 없음, `IOFree`(kfree 아님), saveBits = 0 없음, 오류 갈래 먼저 — `s5p369-fb7` 0 차이.
- 남은 것: DrawRect(원본 1424 B, 작업본 1328)·EraseRect(1112, 1072). 색 표 계산(R·G 최댓값·시프트를 루프 밖에서, B 시프트는 안에서)·좌표 식은 작업본 꼴이 원본과 같음(내가 j1 에서 바꿔 본 꼴은 틀림 — 되돌림). 원본은 지역 공간이 큼(DrawRect 0x58 대 0x4c, EraseRect 0x5c 대 0x54)·`width − 640` 을 스택에 내렸다 다시 읽음 — 레지스터 배정 차이, 원인 미확정. 다음 시도 후보: 지역 변수 선언·형(예 table·value 의 위치), km_drawrect 필드 접근 꼴.

## 370. S5-P353 세부 계획 — `bsd/specfs/spec_vnodeops.c`·`bsd/ufs/ufs_dir.c` 남은 레지스터 차이 해결(plan 354·355 이어서; 코딩 전, 2026-10-07)

0. 원인(GCC 덤프 `-dg -dl` 로 확인): 값을 돌려주지 않는 함수를 암시적 `int` 로 부르면 호출이 eax 를 세우는 `call_value` 가 되어, 그 호출을 건너 사는 의사 레지스터가 eax 와 충돌 → eax 대신 피호출 보존 레지스터(ebx·esi)로 감. 원본은 그 값을 eax 에 두고 호출 앞뒤로만 스택에 저장(caller-save) — 호출되는 함수가 `void` 로 선언된 꼴.
   - spec_open: `error`(의사 28) 가 eax 와 충돌(`s5p370-spdg` greg “28 conflicts: … 0”), 원인 호출 `set_blocksize`(원본 0x139cf8; 07 spec_subr.c:64 정의는 반환값 없음).
   - dircheckpath(blkatoff 인라인): `bp`(의사 68) 가 eax 와 충돌(`s5p371-uddg`), 원인 호출 `byte_swap_dir_block_in`(원본 0x13f7a3; 07 ufs_byte_order.c:286–287 `void` 정의, Darwin ufs/ufs/ufs_byte_order.h:63 `void` 원형(:64 는 _out — codex 지적으로 고침)).
1. 진단(07 아님, diag_k07): spec_vnodeops `s5p370-spe7`(s5 + `void set_blocksize();`) **OBJECT_MATCH**(19), `spe8`(e7 에서 plan 354 의 `int error`(register 뺌)를 원문 `register int error` 로 되돌림) **OBJECT_MATCH** — 그 수정은 불필요해 뺌. 시험한 다른 꼴(`s5p370-spe1`·e3·e4·e5·e6: error 초기화·VBLK 대입 꼴·register dev)은 그대로 200 B. ufs_dir: `s5p371-udv1–v3`(void 선언을 꺼진 `#if QUOTA` 안에 넣어 무효 — 내 실수), `udw1`·`udw2`(void 선언을 첫 함수 앞에) 311→5 B, `udw3`(+ brelse void) 5 B, `udw4`(dircheckpath 루프의 `brelse_and_swap(bp)` 한 자리를 NeXTMach 원문 `brelse(bp)` 앞에 `byte_swap_dir_block_out(bp)` 를 둔 꼴로 — 원본 0x13f80f–0x13f820 `bp = NULL` 이 스택 정리 앞) **OBJECT_MATCH**(17), `udw5` 같음.
2. 07:
   - `src/bsd/specfs/spec_vnodeops.c` = NeXTMach mk-108.1 specfs/spec_vnodeops.c + plan 354 수정(plan 354 메모의 목록, `int error` 제외) + plan 370 `void set_blocksize();` 선언(spec_open 앞; 빌드 선택 — 원본 선언 위치는 알 수 없음, 반환형은 원본 바이트가 요구).
   - `src/bsd/ufs/ufs_dir.c` = NeXTMach mk-108.1 ufs/ufs_dir.c + plan 355 수정(`#if QUOTA`, brelse_and_swap 작성, 각 자리의 swap·brelse_and_swap, entryoffsetinblock·slotfreespace 초기화, 분기 순서, EISDIR, blkatoff 의 byte_swap_dir_block_in) + plan 370: `void byte_swap_dir_block_in(); void byte_swap_dir_block_out();` 선언(빌드 선택, 반환형은 원본이 요구), dircheckpath 루프 한 자리는 `byte_swap_dir_block_out(bp); brelse(bp);`(원본 바이트).
3. 빌드·검사: iter_k07 → relcheck → 실기 cc -M → 기록(record_object, nextmach 바탕, 작성 함수 brelse_and_swap·spec_devblocksize 는 D024).
4. 예상: A 2 — spec_vnodeops [0x139ba8, 0x13a588) 2528 B·ufs_dir [0x13de14, 0x13f90b) 6903 B + 00×1(L1·python).

### 367.1 진단 메모 — ufs_lockf 반환형(plan 370 의 원인 찾기 방법 적용; 07 손대지 않음)

- `-Wimplicit`: 암시적 선언은 panic·sleep·bcopy·wakeup 뿐(보조 함수는 작업본 g1 이 정적 원형을 둠). `void panic/bcopy/wakeup`(s5p372-lfvd1–3) 효과 없음.
- 반대로 작업본의 `static void` 보조 함수를 Net/2 꼴(K&R, 반환형 없음 = int)로: `lf_wakelock` 을 int 로 하면 **lf_clearlock MATCH**(`s5p372-lfiw`, 13 중 12, 남은 18 B) — 원본은 ovcase 를 ebx 에 두는데, 이는 ovcase 가 사는 동안 lf_wakelock 호출이 eax 를 세우는(call_value) 꼴. lf_addblock·lf_free·lf_split·lf_free_svnode 를 함께 int 로 해도 같음(lfib·ic·id·ie).
- 남은 lf_setlock 18 B: `priority`(원본 esi)·`block`(원본 edi)이 맞바뀜(작업본 block 의사 23: 17 회·110 insn, priority 의사 28: 4 회·49 insn; lock 은 ebx). `register`·선언 순서 4 꼴(lfw1–w4) 그대로. 다음 후보: block 참조 수를 바꾸는 원문 꼴(교착 검사 변수, lf_addblock 인자 등).

### codex 교차검토(ko7hdqoze, gpt-6.1-sol) 판정 — plan 370

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 두 후보의 변경은 모두 plan 354/355/370 표시 안, 표시 없는 것은 `#ifdef QUOTA`→`#if QUOTA` 세 곳(빌드 필요, generated quota.h `QUOTA 0`) | 내 diff(NeXTMach 대비; spec 66 줄·ufs_dir 63 줄) | ✅ — `#if QUOTA` 세 곳에도 plan 370 표시를 넣음 |
| 원인 주장 맞음: spec 의사 28·ufs 의사 68 이 call_value 로 eax 와 충돌; 원본 0x139cf5/0x139cfd·0x13f7a0/0x13f7ab 저장·복원 | 내 덤프 읽기(앞서), 원본 디스어셈블(앞서 0x13f798–0x13f7b4) | ✅ |
| 원본 반환형 선언 위치·형은 바이트로 유일하게 증명되지 않음(재구성 선택) | — | ✅ 기록에 “빌드 선택” 으로 |
| Darwin ufs_byte_order.h:63 이 _in, :64 가 _out | 그 두 줄 sed | ✅ 채택 — 0 항 고침(내 오기) |
| set_blocksize 정의(07 spec_subr.c:64)는 암시적 int — `void` 선언과 형식상 불일치(동작은 같음) | spec_subr.c:58–80 읽음 | ✅ 채택 — 기록에 불일치 명시, spec_subr.c 는 바꾸지 않음 |
| 선언은 각 번역 단위 안이라 다른 기록 객체에 영향 없음 | 별도 컴파일 | ✅ |
| spec 2528 B 채움 없음·19 함수, ufs_dir 6903 B + 00×1·17 함수, data 228·368 B | 내 python(L1 json, 원본 0x13f90b `00`) | ✅ 채택 — 4 항 고침 |
| plan 355 메모의 “전역 7” 은 6 | symbols.tsv 범위 안 전역 6(python) | ✅ 채택 — 메모 고침(내 오기) |
| 작성 함수 spec_devblocksize [0x13a374, 0x13a384)·brelse_and_swap [0x13de14, 0x13de34) 은 D024 출처로; x86-ufs_bmap.md:8 의 “brelse_and_swap 미배정” 에 정리 메모 | x86-ufs_bmap.md:8 읽음 | ✅ 채택 — 기록 때 반영 |

### 결과(2026-10-07, plan 370)

- 07: `src/bsd/specfs/spec_vnodeops.c`(NeXTMach + plan 354 + plan 370 `void set_blocksize();`), `src/bsd/ufs/ufs_dir.c`(NeXTMach + plan 355 + plan 370 `#if QUOTA` 표시·void 선언 둘·dircheckpath 한 자리).
- 빌드(iter_k07) `s5p370-r1sp` **OBJECT_MATCH**(19), `s5p370-r1ud` **OBJECT_MATCH**(17); relcheck 0 둘; 실기 cc -M `s5p370-depsp` 75·`s5p370-depud` 56 파일 모두 07.
- 기록(record_object, nextmach; 작성 함수 spec_devblocksize·brelse_and_swap 은 D024 fn_source): functions.tsv 4581→4617(+19 +17; spec_getattr 의 07 줄을 원형 줄 70 에서 정의 줄 527 로 고침 — 36 행 전수 검사), objects_confirmed 307→309, PROVENANCE 1012→1014, MODIFICATIONS 485→487; x86-ufs_bmap.md 에 brelse_and_swap 정리 메모 → **A** 2.
- 범위(python): 이번 2528 + 6903 B. A 308 obj 595800 B (69.98%), P 68 obj 211931 B (24.89%), L 2 obj 340 B; A+P 94.87%, A+P+L 94.91%, rem 43365.

## 371. 진단 메모 — plan 370 방법(암시적 int ↔ void 반환형)을 남은 차이에 적용(07 손대지 않음, 2026-10-07)

- machine_clock(plan 240·365): `-Wimplicit` 로 암시적 선언 8 개(clock_interrupt·hardclock·splusclock·us_spin·splx·readtodc·panic·writetodc). 값 없는 6 개를 void 로 한 꼴들(`s5p373-mca`–`mcd`)은 함수별 차이 그대로(us_spin_calibrate 27·clock_timer_init 45 — fmatch, 재배치 바이트 가림, bss 배치 미확정 영향 포함) → 이 원인 아님.
- ip_output(D028, 07 파일 그대로 `s5p373-ipw`): 함수 9 중 8 같음, ip_output 1584 대 1588 B. `void bcopy`(`ipb`)·`void m_freem/rtfree`(`ipc`) 그대로; ip_mloopback 을 포함한 꼴(`ipa`·`ipd`)은 파일 안 static 정의와 충돌해 빌드 실패(시험 실수). 남은 차이(루프 안 `map + 10` 을 따로 레지스터에 만드는 꼴)는 배정이 아니라 식 결합 쪽으로 보임.
- ufs_lockf 는 367.1(lf_wakelock int 로 lf_clearlock 해결, lf_setlock 18 B 남음).

## 372. S5-P354 세부 계획 — `bsd/ufs/ufs_lockf.c`(Net/2 바탕 D052 + 작성 D024; plan 295·367 이어서; 코딩 전, 2026-10-07)

0. 원본: [0x142008, 0x142884) 2172 B(L1 로 text·채움 확정), 함수 13(전역 lf_lockctl + 정적 12), `__data` 문자열 둘, `__common` lf_svnode_hash.
1. 진단: plan 295 작업본 g1(`s5p367-lfg1`, 13 중 11) → `s5p372-lfiw`(lf_wakelock 을 Net/2 처럼 int: lf_clearlock MATCH) → `s5p372-lflo`(Net/2 원문의 `lock = overlap; /* for debug output below */` 두 줄을 되살림: **OBJECT_MATCH 13**) → `s5p372-lfcand`(머리를 Net/2 고지 + plan 372 설명으로, Net/2 와 다른 줄에 줄 끝 plan 372 표시 35 + 머리 언급 2: **OBJECT_MATCH 13**).
2. 성격(python, 주석·디버그 블록 빼고 줄 비교): Net/2 에도 있는 8 함수는 대부분 Net/2 줄(setlock 87/109·clearlock 38/42·getlock 17/19·getblock 9/12·findoverlap 52/54·addblock 16/16·split 23/26·wakelock 14/14), 다른 줄은 4.2 SDK `<ufs/lockf.h>`(lf_svnode·lf_posix_procp·LF_NOWAIT)·NeXT 할당(lf_free)·교착 검사(posix_proc 사슬)·우선순위(+5, sleep 의 `| PCATCH`). lf_lockctl·lf_get_svnode·lf_free_svnode·lf_rmblock·lf_free 는 Net/2 에 없음 → 원본 바이트로 작성(D024).
3. 07 `src/bsd/ufs/ufs_lockf.c` = Net/2 고지(Berkeley) + plan 372 머리 + 작업본 본문(Net/2 와 다른 줄마다 plan 372 표시). PROVENANCE `net2+authored`(Net/2 함수 줄 인용, 작성 함수는 D024). Darwin 0.1(4.4Lite) 은 코드 참고만(plan 295 머리 문구는 Net/2 확보 전 것이라 바꿈).
4. 빌드·검사: iter_k07 → relcheck → 실기 cc -M → zerofill(`__common` 만, bss 없음 확인) → 기록.
5. 예상: A 1, 약 2172 B.
6. codex 교차검토(kolkszvuh, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 정적 함수 정의 앞 반환형 줄 8개(cand2 183·358·416·442·471·548·590·632)와 원형 선언 71–79 에 표시 없음 | python 으로 cand2 해당 줄 출력(`static int` 등, 표시 없음); Net/2 는 같은 함수를 static 없이 정의 | ✅ 채택: 반환형 줄에 "static (Net/2 has an external K&R definition)", 원형 9줄에 plan 372 표시 |
| 표시는 37 이 아니라 줄 끝 35 + 머리 2 | python: 줄 끝 `/* plan 372 */` 35, plan 372 포함 줄 37, 나머지 둘은 머리 40·44 | ✅ 채택: 1항 문구 고침 |
| 출발점 실행 이름은 s5p367-lfg1 | `08_build/runs/s5p367-lfg1` 있음 | ✅ 채택: 1항에 적음 |
| Net/2 정의 줄 setlock 69·clearlock 291·getlock 359·getblock 393·findoverlap 423·addblock 531·split 559·wakelock 605 | python 으로 Net/2 원문 각 줄 확인: 7개 맞음, getblock 은 393 이 반환형 줄 `struct lockf *`, 정의 줄은 **394** | ⚖️ 부분: 394 로 기록 |
| NeXT 전용 5 함수(lf_lockctl·lf_get_svnode·lf_free_svnode·lf_rmblock·lf_free)에 Darwin 복사 없음 | grep: Net/2 `ufs/*.c`·`lockf.h`, Darwin 0.1 `ufs/ufs/ufs_lockf.c` 에 이 이름 0건 | ✅ (작성 D024) |
| `__text` 2172 B [0x142008,0x142884), `__data` 78 B, 함수 13 | python: 0x142884-0x142008 = 2172; 빌드 객체 `__text` 2172·`__data` 78; L1 MATCH 13 | ✅ |
| commons `_lf_svnode_hash`(256)·`_file_list`(8) | 빌드 객체 기호표: `_file_list` 8, `_lf_svnode_hash` 256 (N_UNDF+값) | ✅ 채택: 0항에 `_file_list` 추가 기록 |
| int lf_wakelock·`lock = overlap` 각각이 원본 원문이었다는 증명은 없음 | 맞음: 바이트는 두 변경을 함께 넣은 결과가 일치한다는 것만 보임 | ✅ 채택: 머리 주석을 "진단 빌드에서 원본 레지스터 사용을 재현; 원문이었다는 증명은 아님" 으로 낮춤 |

7. 결과: 최종본(`s5p372-lffin2`, 주석 안 표시는 "(plan 372)" 로 — 줄 끝 `/* */` 를 블록 주석 안에 넣은 첫 시도 `s5p372-lffin` 은 컴파일 실패) OBJECT_MATCH 13. 0항 보충: `__common` 은 `_lf_svnode_hash` 256 B 와 헤더에서 오는 `_file_list` 8 B.
8. 07 반영: `07_kernel/src/bsd/ufs/ufs_lockf.c`(= `s5p372-lffin2` 원본). 첫 빌드 `s5p372-it1` OBJECT_MATCH 였으나 실기 cc -M `s5p372-depl` 에서 `bsd/ufs/lockf.h` 하나가 07 밖(SDK 사본)이라 adopt_headers 로 `07_kernel/nextdev/bsd/ufs/lockf.h`(D017, 실기 SHA 일치, PROVENANCE 1행) → `s5p372-it2` **OBJECT_MATCH**(13), relcheck 0, 실기 cc -M `s5p372-depl2` 52 헤더 모두 07, cc -M 실행의 객체 = it2 객체(SHA 같음). zerofill 대상 없음(`__bss` 없음; commons 2 는 이름으로 원본에서 찾음).
9. 기록: record_object(`net2:ufs/ufs_lockf.c`, 작성 5 함수 fn_source D024) → functions +13(4630)·objects_confirmed +1(310 줄)·PROVENANCE +1(1016; 종류 `net2+authored`, D052 매니페스트·Net/2 SHA 로 고침)·MODIFICATIONS +1(488). 기록기가 Net/2 함수 8 행의 "edited file" 줄을 원형 선언 줄(72–80)로 잡아 정의 줄로 고침; python 으로 인용 21 개(Net/2 8·07 정의 13) 모두 함수 정의 줄 확인.
- 범위(python): 이번 2172 B. A 309 obj 597972 B (70.23%), P 68 obj 211931 B (24.89%), L 2 obj 340 B; A+P 95.12%, A+P+L 95.16%, rem 41193.

## 373. S5-P355 세부 계획 — `machdep/i386/pmap.c`(D029: Darwin 0.1 바탕 + 수정; plan 275 이어서; 코딩 전, 2026-10-07)

(실행 이름 `s5p373-ip*`·`s5p373-mc*` 는 plan 371 진단 메모의 것이고, 이 계획은 `s5p373-pv*`·`s5p373-pm*`.)

0. 원본: `__text` [0x18ec70, 0x191846) 11222 B + `00` 2 B → 다음 _setconf 0x191848; 앞은 pcb(0x18ec6c `c3` + `00` 3 B, plan 274). `__data` [0x1e247c, 0x1e262e) 434 B. `__bss` 4 B = pmap_update(0x191144) 안 `static last_tick`(Darwin pmap.c:1641). `__TEXT,__const` 4 B `18 00 20 00` 은 참조 없음(cpu_inline.h ltr/lldt 선택자; intr.c·i386_init·PCexception 선례) → 미배치. 예상 등급 **P**.
1. 진단: plan 275 의 남은 78 B(VBE 블록, 0x18f17c–0x18f1e1) — 원본은 물리 주소 칸을 두 번 읽고 size 를 edx 에 둠. `s5p373-pv1`(s5p265-va 무대, 변형 4): p0(=s5p265-va a) 78 B, **p1**(지역 `phys = …vbe_phys` 를 블록 첫 선언으로) **0**, p2(`phys + size + (phys - start)`) 함수 크기 1108 B(원본 1096), **p3**(선언 뒤 대입, phys 먼저) **0**. p1 의 L1: text·data 0 차이, 함수 49(MATCH 48 + pmap_update MATCH_UNVERIFIED — `__bss`).
2. 07 후보 `scratch pmapwip/cand.c` = Darwin 0.1 pmap.c(sha256 a7493c5a…) + plan 373 표시 수정:
   a. pmap_bootstrap 앞 지역 KERNBOOTSTRUCT(D035, 쓰는 칸만: +0x1854 vbeFrameBuffer, +0x185c vbeWidth, +0x185e vbeHeight, +0x1860 vbeRowBytes, +0x186c vbePhysBase; 오프셋은 원본 0x18f16c–0x18f1b4, 이름은 우리 것 — FBConsole 작업본의 VBEModeInfo 해석과 같은 칸 이름).
   b. pmap_bootstrap: 64 MB 만(zone_map_sizer·buffer_map_sizer 없음) + VBE 블록(0x18f16c–0x18f29a, D024; `phys` 먼저 선언, `size = rowBytes * height`, `end = round_page(size + 2 * phys - start)`, vbeFrameBuffer = va + phys − start).
   c. copy_from_phys 뒤에 compress_data_from_phys(0x191490)·uncompress_data_to_phys(0x1914a8) 작성(D024).
   d. pmap_attribute 는 KERN_INVALID_ARGUMENT 만(0x1914d0).
   진단 `s5p373-pmc1`(07 복사본 + cand.c): text·data 0 차이, 49 함수(48 + pmap_update). 실기 cc -M `s5p373-pmd1`: 헤더 106 중 07 밖은 Darwin `machdep/i386/pmap_private.h`(sha256 9f7f8c9f…)·`pmap_inline.h`(dbd48a71…) 둘.
3. 헤더: 이름이 같은 파일은 Darwin 0.1 에만 있음(`find 01_resources/upstream ../ref -name pmap_private.h -o -name pmap_inline.h`; Mach4 는 intel/pmap.c·pmap.h 뿐) → 둘을 07 `src/machdep/i386/` 에 Darwin 원문 그대로(D029, PROVENANCE darwin01 "none (verbatim)"). 기존 기록 객체 무대 중 이 두 이름을 가진 것은 없음(tools 매니페스트 grep: s5p44-pre·s5p374-pm0 진단뿐) → 회귀 대상 없음.
4. 출처: D029 가 이름으로 정한 경우(계획 274 판정 "pcb.c·pmap.c·trap.c"). Mach4 `i386/kernel/intel/pmap.c` 는 같은 이름 파일로 있으나 D029 가 이 파일을 Darwin 바탕으로 정함(pcb·trap 과 같은 처리). PROVENANCE darwin01, 작성 함수 2 개와 VBE 블록 D024, Apple·NeXT 고지 유지.
5. 빌드·검사: 07 배치 → iter_k07 → L1(text·data 0) → relcheck → 실기 cc -M(모두 07) → zerofill_check(`__bss` 4 B) → 기록(P; `__const` 4 B 미배치) → 범위 갱신.
6. codex 교차검토(k9mu3b3ja, gpt-6.1-sol) 판정:

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| pmap `last_tick` 은 참조로 [0x1e773c, 0x1e7740) — 기록된 swapgeneric `__bss` [0x1e773c, 0x1e7744)(objects_partial.tsv:53)와 4 B 겹침; swapgeneric 참조 9 개는 +4 만 가리키고 앞 4 B 는 참조 없는 `_nfsbootdevname` | objects_partial.tsv:53 열람; `s5p324-zerofill-check-swapgeneric-20261005.json` field_target_offsets [4], candidate [1996604, 1996612]; `s5p324-it1` 객체 `__bss` 8 B = `_nfsbootdevname` +0x0·`_gc` +0x4(python); zerofill-known-s5p345 에서 0x1e7744 부터 autoconf_i386 | ✅ 채택 → 373.1 |
| "p2 1108 B" 는 차이 수가 아니라 함수 크기 | 내 fcmp 출력 "size 1108 (orig 1096) diffs 363" | ✅ 문구 고침 |
| 그 밖의 수치(11222·434·채움 3/2·49 = 48 + 1·헤더 106·SHA 앞자리) | 앞서 내 python·L1·cc -M 출력과 같음 | ✅ |
| 바뀐 덩이 5 개 모두 plan 373 표시 안, Apple·NeXT 고지 그대로 | `diff` 덩이 5 개(344a345,362 / 411,413c429 / 414a431,446 / 1842a1875,1901 / 1873,1908c1932) 직접 확인 | ✅ |
| 구조체 오프셋이 원본 주소와 맞음 | python 배치 계산: 0x12854·0x1285c·0x1285e·0x12860·0x1286c | ✅ |
| D029 는 Mach4 대응 판이 없다는 것이 아니라 pmap.c 를 이름으로 정한 것 | DECISIONS.md:33 문언 | ✅ 4 항 문구 고침 |
| P 기록에 `__const` 미배치·zerofill 음성 검사·pmap_update 신뢰도 중간 유지 | intr 선례(objects_partial x86-intr 행) | ✅ 기록 때 반영 |

### 373.1 swapgeneric `__bss` 고침(codex 지적, 원본 바이트 근거)
- 사실: pmap_update 의 명령 4 곳이 0x1e773c 를 직접 가리키고(pmap 이 소유하는 `static last_tick`), swapgeneric `gc` 참조는 0x1e7740, 0x1e7744 부터는 autoconf_i386 `__bss`(참조 추정). 링크 순서도 text 와 같음(pmap 0x18ec70 → swapgeneric 0x191848 → … autoconf_i386 0x193f34). 그러므로 원본 swapgeneric 의 `__bss` 는 `gc` 4 B 뿐이고, 07 의 Darwin 줄 `static char *nfsbootdevname;`(`#else /* NFSCLIENT */`, 07 swapgeneric.m:93) 는 원본에 없던 것으로 봄 — 4.2 판은 nfs 루트에서 nfsbootdevname 을 쓰지 않음(plan 324, 07 :218), 원본에 `_nfs_mountroot` 기호도 없음(NFSCLIENT 아님).
- 수정: 07 swapgeneric.m:93 을 지우고 plan 373 표시 주석. 다시 빌드해 text·data 차이 0 그대로, `__bss` 4 B → zerofill_check [0x1e7740, 0x1e7744) 확인 → objects_partial swapgeneric 행 고침(행 수 그대로). 알려진 배치 목록은 새 파일(zerofill-known-s5p373)로: swapgeneric [0x1e7740, 0x1e7744), pmap [0x1e773c, 0x1e7740).
- 결과(373·373.1): 07 `machdep/i386/pmap.c`(= cand.c, VBE 주석 끝 0x18f29a 로 고친 것)·`pmap_private.h`·`pmap_inline.h`(Darwin 원문 그대로, SHA 일치). `s5p373-it1` text·data 0 차이, 49 함수(48 MATCH + pmap_update MATCH_UNVERIFIED), `__const` 미배치, relcheck 0, 실기 cc -M `s5p373-dep1` 106 헤더 모두 07(객체 = it1). zerofill(알려진 배치 `zerofill-known-s5p373a`: s5p345 목록 − 옛 swapgeneric + objc-runtime [0x1e8748, 0x1e8750)) → reference-inferred [0x1e773c, 0x1e7740)(참조 4, Δ 0x1e49ac, 음성 검사 검출) → **P**.
- swapgeneric(373.1): 07 swapgeneric.m:93 지움(표시 주석). `s5p373-sg1`(s5p324-it1 과 같은 명령): text·data·__OBJC 0 차이, relcheck 0, 객체 차이는 `__bss` 크기와 그 재배치 값뿐. zerofill(`zerofill-known-s5p373b` = a + pmap) → [0x1e7740, 0x1e7744)(참조 9, Δ 0x1e6e7c, 음성 검사 검출). 새 알려진 배치 목록 `zerofill-known-s5p373-20261007.json`(71).
- 기록: record_partial → objects_partial +1(70 줄), functions +49(4679; pmap_update 는 intr 선례대로 medium·MATCH_UNVERIFIED 문구로 고침), PROVENANCE +1 pmap +2 헤더(1019), MODIFICATIONS +1 pmap +1 swapgeneric(490); swapgeneric 행(objects_partial·PROVENANCE SHA·근거 md·diff) 고침, 행 수 그대로. python 으로 인용 96 개(Darwin 47 + 07 정의 49) 모두 정의 줄 확인.
- 출처 칸 고침(373.2 참고).
- 범위(python): 이번 11222 B. A 309 obj 597972 B (70.23%), P 69 obj 223153 B (26.21%), L 2 obj 340 B; A+P 96.44%, A+P+L 96.48%, rem 29971.

