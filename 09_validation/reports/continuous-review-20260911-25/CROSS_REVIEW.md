# 계획 재확인 — 코딩 전

이전 PLAN의 독립 검토를 유지하고, 이번 실행 범위는 `/root/trap_plan_review`에
다시 제시했다. 모든 의견은 원본 ASM/SDK와 Python으로 재확인한다.

시험 범위: A/B root, copyout/msg, entry/sentinel hint, destination offset
0x100/0x1100, flags2/0x602, 길이1. protection1은 원본 반환2와 EFAULT까지,
protection3은 0x17817c **직전**까지만 실행한다. 양쪽 하드웨어 PTE는 RO다.
후자는 소프트웨어 VM protection 허용과 PTE RO 상태의 분기 대조이며 page-in
성공으로 집계하지 않는다. 원본 pmap/map 생성 전체를 검증한 fixture도 아니다.

검토자가 추가로 지적한 초기화 순서 조건을 채택했다: 원본 lock_init(map,1)은
DF=0에서, copy 실행 전에 수행한다. 그 뒤 copy caller/GPR/ESP/시험 flags를
준비한다. fault 후 원본 lock_init을 호출하면 관찰한 fault 상태가 훼손되므로
사용하지 않는다. fault 후에는 명시적 CPU frame 주입만 하고 원본 stub으로 진입한다.

Python 계산과 관찰 근거를 혼동하지 않는다. VM/PTE page 크기 혼동으로 거부한
이전 Codex 의견은 PLAN에 그대로 보존한다. 새 코드의 통과가 Codex 의견 자체의
정확성이나 전체 분석 완료를 뜻하지 않는다.

## 코딩 후 읽기 전용 검토

첫 실행 후 같은 독립 검토자가 코드와 JSON을 읽었다. 중대한 frame/protection
모델 오류는 찾지 못했으나 handler 후 버퍼 해시가 JSON에 없다는 증거 누락을
지적했다. runtime 비교만으로 offline 검산까지 주장하지 않도록 final buffer
해시와 map/entry/uthread/recover/counter/guard를 추가 기록하고 별도 검산했다.
거절 완료의 최종 DS/ES/SS/FS/GS/CS/CR0/CR4도 fault 스냅샷과 명시적으로 비교한다.
독립 검토자는 파일을 변경하거나 에뮬레이션을 실행하지 않았다.
