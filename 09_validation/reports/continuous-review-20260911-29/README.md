# 신중한 추가 검토29 — 부재 페이지 할당·zero-fill·새 managed 매핑·재시작

## 판정

명시적인 합성 익명 object/PT/물리 frame 준비 위에서 원본 copyout의 nonpresent
fault를 관찰하고, 원본 vm_fault → allocator → zero-fill → pmap_enter → IRETD
→ fault 명령 재실행과 실제 payload 기록까지 연결했다. 함수 patch/call mock이나
fault 후 API PTE 수정/추가 translation flush로 원본 성공을 대신하지 않았다.

| Python 집계 | 결과 |
|---|---:|
| fresh 연결 사례 | 16 |
| 원본 zero-fill DWORD store | 32,768 |
| 원본 새 PTE store | 32 |
| handler 명령 방문 | 61,664 |
| 훼손 관찰 자료를 거절한 음성 대조 | 19 |

matrix: A/B roots, copyout/copyoutmsg, VM page 안의 hardware halves에 속한
대상 offset 0x100/0x1100, caller flags 0x2/0x602. 각 복사는 단일 byte다.
다중 byte/VM 경계 복사, copyin/read fault, 모든 flags 조합의 검증은 아니다.

## 무엇이 원본 실행이고 무엇이 합성인가

F25의 bootstrap 기반 high-CS/DS/SS와 FS 준비를 재사용한다. 원본 startup prefix로
page template/queue를 초기화하고, 원본 page init/free로 detached free seed를 만든다.
object/hash/managed descriptor arena와 PT pair/extension은 합성 입력이다.
보고서28의 caller-held object/queue lock을 해제한 뒤 fault 처리에 진입한다.
pager/shadow/copy 없음, policy=0, reserve/minimum/target=0, free page가 있는 조건이다.

active root의 user 영역을 비우고 연속 PT pair를 준비한다. 공유 high supervisor
mapping은 유지한다. 사전 원본 MOV CR3 이후에는 flat-CS calibration을 다시 호출하지
않는다. active root에는 frame의 high alias만 있지만 inactive root의 bootstrap
aliases는 남아 있으며 별도로 기록했다. 이것을 전체 원본 PV 소유권으로 해석하지 않는다.

PT helper는 VA section 기준 PDE0로 PT descriptor/extension을 찾는다. 따라서
기존 fixture의 private PDE1 table만 재사용하지 않는다. extension의 descriptor,
physical address, owner, section, queue를 일관되게 준비하고 resident/wired count는
빈 사용자 mapping 기준으로 시작한다. 실제 원본 pmap_init/expand를 수행한 것은 아니다.

CPU model의 실제 nonpresent fault 뒤 error=2인 CPU frame을 **명시적으로 주입**한다.
이는 관찰한 NP write 원인에 맞춘 시험 입력이지 CPU 자체 error-code/frame 생성의
검증이 아니다. 그 이후 원본 vector stub/alltraps/kernel_trap/vm_fault/IRETD를 실행한다.

## 연결된 원본 근거

- lookup miss의 EAX=0에서 원본 allocator가 준비된 free page를 꺼내 object에 연결한다.
  allocator template REP의 ECX/ESI/EDI/DF 진행을 매 방문 관찰한다.
- zero-fill은 원본 page physical field를 사용해 DS:[physical]에 쓰며 high direct
  alias로 접근한다. 모든 zero DWORD store와 loop 진행을 검사한다. zero helper
  반환 직후 frame 전체가 0임을 매핑 및 최종 복사 결과와 분리해 관찰한다.
- managed bounds를 통과하고 빈 PV head에 user pmap/VA를 등록한다. user pmap을
  kernel pmap으로 바꾸거나 managed 범위를 비워 우회하지 않았다.
- 원본 통계 helper가 pmap resident DWORD와 PT extension count WORD를 증가시키고,
  target VM page의 hardware PTE들을 실제로 쓴다. wired count는 그대로다.
- 원본 vm_fault가 0으로 반환하고 saved frame 변경 없이 IRETD가 fault PC로 돌아온다.
  해당 명령의 CPU/segment/flags 문맥과 실제 single-byte payload 기록을 확인한다.
  나머지 frame은 zero, 기존 A/B/kernel copy buffers는 불변이다.

## 독립 검산과 재현

실행 코드와 별개의 audit는 원본 Mach-O를 직접 읽고 Capstone으로 trace의 원본
call/return/branch/IRETD 연결을 대조한다. 사례 입력에서 object/page/hash/queue,
pmap/descriptor arena/extension의 전체 예상 바이트를 도출하여 각 단계와 비교한다.
PTE/PV/통계/zero-fill write의 주소·폭·값과 최종 payload를 별도로 검사한다.
handler의 기록된 CPU write가 문서화한 stack/metadata/target 영역 밖이면 거절한다.
하드웨어 page-table A/D 갱신은 이 CPU write-hook 범위와 구별한다.

seed/startup의 빈 trace 및 fault terminal head를 잘못 허용한 초기 audit 허점을
후속 교차검토로 발견했고 root가 직접 재현·수정했다. 필수 alias 목록 검사도 보완했다.
[계획](PLAN.md), [교차검토와 수정 근거](CROSS_REVIEW.md), [음성 대조](negative-controls.json).

이 독립 검산은 같은 backend의 관찰 자료를 대상으로 한다. alias walk와 frame
reference scan은 실행 측 결과를 소비하며 독립 하드웨어/전체 walker 검증이 아니다.
다른 root의 보존은 root directory와 기존 buffer 범위로 한정하며 공유 high PT의
A/D까지 불변이라는 뜻이 아니다. prefix/seed/사전 CR3는 별도 trace/상태 검사이며
handler write-hook 검사의 적용 대상이 아니다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-29/missing_page_review.py
python3 -B 09_validation/reports/continuous-review-20260911-29/audit_results.py
python3 -B 09_validation/reports/continuous-review-20260911-29/test_audit.py
python3 -B 09_validation/reports/continuous-review-20260911-29/reproduce_results.py
python3 -B 09_validation/reports/continuous-review-20260911-29/verify_artifacts.py
```

[원시 사례](missing-page-cases.json), [집계](missing-page-summary.json),
[독립 audit](independent-audit.json), [최근 진단](latest-diagnostic.json),
[재현 해시](reproducibility.json), [실행 전 보존](preservation-before.json),
[실행 후 보존](preservation-after.json), [입력 해시](input-hashes.json),
[최종 보존 검증](verification.json), [산출물 해시](artifact-hashes.json),
[잔여 분석](OPEN_ITEMS.md).

Ghidra 스킬에 따라 정본 export와 원본 명령, 공개 소스의 참고 해석, 합성 준비,
실제 실행 관찰을 분리했다. 모든 계산은 Python이다. 원본 binary/DB/export,
reference sources, 이전 보고서, 07_kernel을 보존한다. 전체 커널/VM 의미 분석,
native CPU frame, 실제 pager/PT 생성·소유권, GCC 2.7 구현·빌드·부팅, 후속
아키텍처를 이번 결과로 완료 처리하지 않는다.
