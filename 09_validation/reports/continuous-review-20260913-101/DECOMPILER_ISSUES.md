# 101차 디컴파일·분석 경계 주의점

원본 명령을 우선한다. 아래 항목은 C 전체를 폐기하거나 실제 커널 장애를 확정한다는 뜻이 아니다.

| 위치 | 표현 차이 또는 오독 위험 | 원본에서 유지할 사실 |
| --- | --- | --- |
| task_create 0x165a20 | ledger 포함 다섯 인자 C prototype | 자체 인자 읽기는 EBP+8/+0xc/+0x10이며 parent/flag/output이다. |
| kernel_task_create 0x1659ac | 호출의 ghost 인자, 함수의 void 반환 | task_create 호출은 세 PUSH이며 자체 반환 EAX에는 task가 남는다. |
| task_create의 0x165ab1/0x165aba | pmap에 map 인자까지 붙이고 vm_map 인자 누락 | ADD ESP,4 후 남는 세 값과 새 PUSH를 합쳐 vm_map이 네 인자를 받는다. |
| task_reference 0x165c94 | __regparm1 및 미정의 EAX 입력/반환 | 실제 task 입력은 스택 한 인자이며 의미 있는 EAX 입력이 필요하지 않다. |
| thread_deallocate 0x166ea0 | __regparm1/부수적 반환값을 계약으로 해석 | 스택 한 인자, 두 번의 signed TEST/JLE 후보 검사와 잠금 재획득이 핵심이다. |
| thread_dup 0x18ea90 | 구조체 이름으로 전체 PCB 복제 추정 | CLD/REP는 사용자 저장 상태 92바이트만 복사한다. |
| thread_dup 0x18ebb5 | child field를 근거 없이 PID 또는 unsigned로 명명 | child task+0x3c 객체+0x30 WORD를 MOVSX한다. 고수준 필드명은 미확정이다. |
| fp_terminate 0x18a800 | C의 in_CR0 OR 반환식 | 원본 0x18a81c는 CR0 레지스터에 실제 쓰기를 한다. |
| pcb_common_terminate 0x18ec58 | 작은 destructor를 전체 소유권 해제로 간주 | 자체 kfree는 K 블록 28바이트만 지정하며 bitmap 포인터를 따라가지 않는다. |
| reaper 0x168564 | switch 상태명을 scheduler 완료 계약으로 대체 | 원본 14개 DWORD 표와 분기·대기·재검사 경로를 보존한다. |

## 본문 경계와 원본 자체 패턴

6개 fragment는 panic CALL 뒤의 `ADD ESP,4`와 원래 본문으로의 fallthrough다.
독립 호출 ABI나 독립 정상 반환 함수를 만들지 않는다. panic이 실제 반환한다는 주장도 아니다.

MOV로 읽은 레지스터를 TEST하고 같은 TEST로 JNZ하는 45개 패턴을 raw bytes로 확인했다.
메모리를 매번 다시 읽는 것으로 C를 임의 수정하지 않는다. 이 관찰만으로 native deadlock을
재현했다고 할 수도 없다. lock/IRQ/런타임 코드 상태의 전제는 남아 있다.

common/BSS 주소는 파일의 현재 정수 값과 다르다. thread template의 runtime 명시적 writer,
파일의 zero template, FP owner의 BSS 소속을 각각 별도로 기록한다.

정확한 명령 바이트·파일 offset·C 발췌·경고·fragment 연결은
[원본 증거](object-lifetime-evidence.json)에 있다. 미해결 ABI/수명은 [남은 분석](OPEN_ITEMS.md)에 유지한다.
