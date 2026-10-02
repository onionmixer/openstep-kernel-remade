# 결정 기록

| ID | 상태 | 결정 / 근거 |
|---|---|---|
| D001 | 확정 | x86 우선. 기준은 동일 해시의 로컬 OPENSTEP 4.2 mk-183.34.4 파일 |
| D002 | 확정 | 참고 원본(01), 기준 바이너리(03), 도구 분석(04/05), 판단(06), 실제 커널 소스(07)를 분리 |
| D003 | 확정 | 기존 두 IDA DB는 스냅샷으로 각각 보존. 임의로 서로 덮거나 분석을 통합하지 않음 |
| D004 | 잠정 | NeXTMach 수집 URL은 GitHub의 동일 owner/repo 경로 사용. 사용자 미러와 내용 동일성은 미검증 |
| D005 | 확인 필요 | “mach”가 m68k를 뜻하는지 확인. 확정 전에는 future_arch 예약 경로 사용 |
| D006 | 일부 확정 | 최종 컴파일러 GCC 2.7 필수. 정확한 2.7.x/NeXT 수정판과 네이티브/크로스 경로는 Mach-O·ObjC ABI·MIG probe로 고정 |
| D007 | 확정 | 원문 소스 텍스트의 완전 일치와 기능/ABI 재구성을 구분하여 성과 보고 |
| D008 | 사용자 확정 | 최종 결과물은 GCC 2.7에서 컴파일 가능해야 함. 모든 대상 CPU에 적용하고 실제 전체 컴파일·링크 로그로 검증 |
| D009 | 사용자 확정 | 전체 바이너리 역어셈블/디컴파일 자료 확보를 먼저 완료. 서브시스템별 구현 병행 제안은 보류하고 전체 분석을 연속 진행 |
| D010 | 사용자 확정 | 계산은 반드시 Python 사용. 주소/offset 변환, 크기/차이, 개수/비율/coverage 등의 파생 계산을 Python으로 수행하고 근거를 남김 |
| D011 | 사용자 확정 | 2026-10-01: 분석 전용 제한(2026-09-13) 철회. 소스 복원·빌드·시험 착수, 참고 코드 참고 허용. 참고 코드는 원본 바이트와 대조한 근거가 있을 때만 채택 |
| D012 | 사용자 확정 | 2026-10-01: i386 은 OPENSTEP 실기에서 빌드(NFS `/ndrv` + gcds), 결과물 시험은 QEMU. 실기 재부팅·커널 교체·데몬 재기동은 사용자가 수행 |
| D013 | 사용자 확정 | 2026-10-01 변경: NeXTMach 유래 코드도 공개 저장소에 커밋할 수 있다(라이선스 판단은 사용자 책임). 조건: 파일·함수·식별자 단위로 출처(저장소 URL, 커밋, 경로:줄)와 원 표기(CMU 등)를 PROVENANCE·MODIFICATIONS 에 기록. Darwin 0.1(APSL)·Mach4 는 기존대로 라이선스 표기와 출처 기록이 있을 때만 커밋. (이전: 잠정 — NeXTMach 코드 커밋 금지) |
| D014 | 사용자 확정 | 2026-10-01: "복원 수정" 허용 — 후보 소스가 원본과 다른 판일 때 원본 역어셈블 근거가 있는 부분만 최소로 고친다(RECONSTRUCTION_PLAN 19 절 R1–R5: 근거 범위 명시, 최소 수정, MODIFICATIONS.md·diff·PROVENANCE 기록(APSL 2.1(c)), 함수당 변형 3 회, 빌드 전 예측) |
| D015 | 사용자 확정 | 2026-10-01: 원본 `struct thread` 0x7c·0x80 필드 이름은 NeXTMach `mk-108.1/kern/thread.h:218–221` 의 `tmp_address`·`tmp_object` 를 쓴다(역할은 원본 바이트로 확인, 이름은 NeXTMach 유래로 기록) |
| D016 | 사용자 확정 | 2026-10-01: 참조 소스(Darwin 0.1·NeXTMach·Mach4)에 없는 코드를 원본 바이트에 맞춰 **새로 작성**해도 된다("네 새로 써도 됩니다. 신중하게 작업하세요."). 규칙은 RECONSTRUCTION_PLAN 48 절 W1–W5(참조 텍스트로 안 될 때만, 최소·근거 범위 명시, 작성 표시 주석과 MODIFICATIONS·PROVENANCE 기록, L1 MATCH 필수, 빌드 전 예측). 첫 적용: `kern/time_stamp.c` `kern_timestamp`, `kern/ipc_sched.c` `thread_handoff` |
| D017 | 사용자 확정 | 2026-10-02: 라이선스 판단은 "모두 구현한 뒤에" 사용자가 정한다. 그때까지 참조 소스에 없는 독립 새 파일·참조 밖 헤더도 만들거나 들여올 수 있되, 파일마다 PROVENANCE 에 출처와 "license TBD(D017)" 를 적고 원 고지가 있으면 그대로 보존한다(D013·W6 의 "독립 새 파일 라이선스는 사용자 판단" 을 구현 완료 시점으로 미룸). 공개 저장소 커밋 여부는 별도 확인 |
| D018 | 사용자 확정 | 2026-10-02: S4-C — BSD 헤더(`machine/limits.h` 등 Darwin 소스 트리에 없는 시스템 헤더)는 **실기 OPENSTEP 4.2 `/NextDeveloper/Headers`** 판을 기준으로 쓴다(안 B; RECONSTRUCTION_PLAN 40 절 조사: `ansi/i386/limits.h` 1992 NeXT, `bsd/machine/` 에 `limits.h`·`param.h` 없음). 실기에서는 읽기 전용으로 가져오고, 출처(실기 경로·SHA-256)·원 고지를 기록, 라이선스는 D017. 객체마다 원본 바이트(L1)로 판정하는 방식은 그대로 |
| D019 | 사용자 확정 | 2026-10-02: 참조가 하나뿐인 zero-fill 섹션은 `zerofill_check.py` 의 다른 검사(정렬·zero-fill 섹션 안·원본 심볼 없음·알려진 배치와 겹침 없음·대상 오프셋 범위)를 모두 통과하고 실패 사유가 "단일 참조라 음성 검사 미검출" 뿐이면 **reference-inferred-single** 로 기록한다. 객체 등급은 P 까지(A 불가), 그 섹션에 의존하는 함수는 medium, 아닌 함수는 high; P 행에 "단일 참조" 명시; 이웃 확정으로 위치가 독립 고정되면 재판정 |
| D020 | 사용자 확정 | 2026-10-02: BSD 쪽 소스의 기준 판은 **NeXTMach mk-108.1**(4.3BSD 계열)로 한다("네. NeXTMach 로 하세요."). 근거: RECONSTRUCTION_PLAN 79.2 — 실기 OPENSTEP 4.2 SDK 의 BSD 구조체 13 개 중 10 개가 NeXTMach 와 같고 Darwin 과 다름(1 개 셋 다 같음, 2 개 셋 다 다르나 SDK 가 NeXTMach 에 가까움); 78 절 Darwin BSD 진단 17 컴파일 중 1 일치; 80 절 pcb `p_pid`(원본 `short`). 이미 확정된 BSD 쪽 객체(strtol 등)와 Darwin BSD 헤더 채택분은 바이트로 검증된 범위에서 유지하되, 같은 이름 헤더의 판 선택은 객체별로 원본 바이트로 다시 판정한다. 출처 기록은 D013(NeXTMach 저장소·커밋·경로:줄, 원 고지) |
| D021 | 사용자 확정 | 2026-10-02: BSD 헤더 적용 방식은 **B — BSD 헤더 묶음을 통째로 NeXTMach/SDK 판으로 교체**("B 로 가는게 맞습니다. 신중하게 진행하세요."). 이후 작업은 **NeXTMach(mk-108.1)·실기 SDK(/NextDeveloper/Headers)를 기준**으로 하고, Darwin 0.1 은 코드 구조 참고용으로만 쓴다("이후에도 darwin 은 코드의 구조만 참고하고 NeXTMach/SDK 를 기준으로 작업이 진행되어야 합니다."). 이미 확정된 객체는 교체 뒤 회귀로 다시 확인한다(RECONSTRUCTION_PLAN 130–131). 대량 작성 허용 범위(130 절 질문 2)는 아직 답을 받지 않았다 |
| D022 | 사용자 확정 | 2026-10-02: D021 을 비-BSD 헤더에도 적용한다 — **실기 SDK(/NextDeveloper/Headers)에 있는 이름(`mach/`·`kernserv/`·`architecture/`·`driverkit/` 등)은 SDK 판으로 교체**("1 네 SDK 로 변경하세요."). SDK 에 없는 Mach 쪽 이름(`kern/`·`ipc/`·`vm/`·`machdep/` 등)의 **기본 참고는 Mach4**("기본 참고는 mach4 가 되는게 맞습니다."); Darwin 0.1 은 구조 참고용. 참고 판은 후보이며 원본 바이트 근거가 있어야 채택한다(AGENTS.md). 적용 순서와 회귀는 RECONSTRUCTION_PLAN 134 |
| D023 | 사용자 확정 | 2026-10-02: SDK 판이 커널 비공개 분기를 뺀 공개판인 7 개(`mach/mach_types.h`, `mach/std_types.h`, `mach/mach_traps.h`, `kernserv/lock.h`, `kernserv/clock_timer.h`, `kernserv/ns_timer.h`, `kernserv/prototypes.h`)는 **A — SDK 본문을 그대로 두고 비공개 분기를 작성**해 `07_kernel/nextdev_private/` 에 둔다("A"). 분기 내용은 Mach4 구조를 기본 참고로 하고 원본 바이트(객체 동일)로 확인되는 최소만 넣는다. RECONSTRUCTION_PLAN 136 |
| D024 | 사용자 확정 | 2026-10-02: 원본 바이트에서의 작성 범위는 **B — 작성 표시(D016) 아래 함수 단위 작성까지 허용**("B 로 진행합니다."). 조건: 객체마다 원본과 OBJECT_MATCH(또는 기존 등급 규칙), 작성 줄은 파일에 표시하고 MODIFICATIONS 에 근거(원본 주소)를 남긴다. 기준 판은 NeXTMach/SDK(Mach 내부는 Mach4 기본 참고), Darwin 은 구조 참고. 계획 → codex(코딩 전) → 검증 → 코드 순서, 계산은 Python. RECONSTRUCTION_PLAN 145~ |
