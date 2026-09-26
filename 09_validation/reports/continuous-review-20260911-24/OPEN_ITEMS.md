# 잔여 분석 의무 — 보고서24 이후

report23의 의무를 계승한다. 자료 확보와 한정된 실행 검증은 전체 의미 검증·구현
완료가 아니다. 이번에 줄인 공백과 아직 남은 범위를 분리한다.

| 의무 | 현재 확인한 범위 | 여전히 필요한 근거 |
|---|---|---|
| 예외 진입·복귀 | 높은 CS의 CPU 모델 #PF 관찰, 명시적 same-CPL frame 주입 후 원본 trap/VM lookup miss/recover/IRETD/EFAULT | native IDT 전달·CPU error/frame 생성, CPL 전환, 대체 스택, 다른 예외, 정상 page-in 뒤 fault 명령 재시작 |
| 사용자 주소 공간 | 합성 A/B root의 copyin/out, 추가 high-CS copyout | 원본 사용자 pmap 생성, 비연속 물리 페이지, 추가 권한·limit 조건 |
| 전체 문맥 전환 | 원본 CR3 비교·쓰기 조각 및 최종 CS far jump 별도 실행 | 실제 스레드 선택과 LDT/TSS·스택·CS를 하나의 원본 경로에서 연결 |
| FS/descriptor | 초기 GDT와 이번 same-CPL frame의 원본 POP FS 복원 | 모든 POP FS 출처, descriptor alias 쓰기, 권한·limit·비동기 상태 불변 조건 |
| recover 수명 | 정상 짧은 copy 성공 후 잔존, 이번 fault 경로의 해제 | 모든 관련 호출자·후속 trap·비지역 복구 경로의 수명 |
| 부팅 | 초기 pmap/GDT/IDT와 제한된 relocation·CS 설정 | 전체 i386_init, 비디오·메모리 구성·할당 실패·펌웨어·최종 상태 |
| ABI·타입·함수 경계 | 선택 함수 및 trap frame 계약 | 미해결 인자·간접 호출·숨은 ABI·구조체·fragment·비복귀 전파 |
| CPU 부작용 표현 | 기존 CR/IF/FS 모델 실험, 이번 IRETD/C-return 불일치의 실행 근거 | 교정안을 별도 작업 사본에 통합하고 모든 관련 소비자 회귀 검증 |
| 동시성·장치 | 선택 I/O 순서와 이번 경합 없는 read-lock 획득·해제 | 실제 경합·interrupt·MMIO·동적 alias·TLB/cache·오류/재시작 |
| 도구 교차 검증 | 기존 정본 보존, 독립 Python 원본/trace 대조 | 검증 교정안 최종 작업 사본·재추출, 동일 원본 IDA 대조·실패 원인 처리 |
| 공개 소스 대응 | 부분적인 소스·SDK·원본 대응 | 소스 계보·채택 근거·타입/ABI 추적 및 확정 불가능한 부분을 포함한 복원 명세 |

다음 예외 분석에서는 이번 empty-map 실패와 다른 원본 VM 결과를 조사해 page-in
성공·재시작 또는 mapped-entry 보호 실패로 연결할 조건을 먼저 교차검토해야 한다.
native 전달 한계는 사라진 것으로 처리하지 않는다. 다른 CPU backend나 원본의
하드웨어 계약을 이용할 경우에도 자동 프레임 생성의 관찰 근거를 따로 확보한다.

GCC 2.7 구현·컴파일·링크·부팅 및 후속 아키텍처는 별도 단계다. 원래 주석·매크로·
파일 구성을 바이너리만으로 유일하게 복원했다는 주장을 목표 완료의 근거로 삼지 않는다.
