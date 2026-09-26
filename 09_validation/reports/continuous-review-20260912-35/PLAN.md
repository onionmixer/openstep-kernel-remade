# 보고서35 계획 — 예외 handler와 기존 소비자 감사 회귀

상태: 코딩 전 원본/기록 검토와 독립 교차검토를 진행한다. 전체 목표는 유지한다.
기존 확정 보고서/입력/원본/DB/export 및07_kernel은 수정하지 않는다.
모든 계산·주소·계수·해시는 Python으로 처리한다.

## 검토 대상과 사전 정정

보고서34에서 발견한 실제 CALL/RET 연결 및 write metadata 누락을 기존32의
예외 handler 및31/33/34 일반 호출 기록에 재검토한다. 기존 producer/main은
호출하지 않고 보존된 JSON과 원본 Mach-O 명령을 읽는다. 이 단계의 새 실행은
감사 재실행이며 원래 CPU producer를 새로 실행한 것이라고 주장하지 않는다.

독립 검토자 vm_contract_review27에게 코딩 전 계획 교차검토를 요청했다.
root는 원본1861cc,186d20,17b200 및32 audit와 실제 JSON을 직접 확인했다.
REP 대상은17b384의 REP MOVSD(f3a5)이지 STOSD가 아니다. zero는 별도 unrolled
MOV DWORD들이다. REP는 각12 write 뒤 마지막 ECX0 head를 남기는 backend 특성이 있다.
PUSHAD hook8 write는 낮은 주소부터 기록된다. segment PUSH의 operand size2와
backend write width4/ESP 감소4를 구분한다. 이 기록형식을 native 보장으로 삼지 않는다.

## 구현 전 정한 감사 범위

- opcode/operand 위치로 명령당 write 개수/폭 검사. TEST access 오표기는 배제한다.
  MOVZX/MOVSX/setne는 확인한 register destination만 지원한다. 알 수 없는 형태는 거부한다.
- 기존32 injected boundary부터 ESP/EBP를 추적한다. 원본 ordinary PUSH/CALL/RET,
  PUSHAD와 savedESP, segment PUSH/POP, POPAD의 ESP slot 건너뛰기, 동권한 IRETD의
  실제 EIP/CS/EFLAGS 읽기 및 복귀 후 copy epilogue의 최종RET를 연결한다.
- caller RET slot은 이전 copy 호출의710000 입력이다. 시작 injected ESP 자체를
  일반 함수 return slot으로 가정하지 않는다. 예외 프레임은 명시적 합성 입력이다.
- 186d4a MOV EBX,ESP와 저장/복원된 EBX를 통해186d69 MOV ESP,EBX를 검사한다.
  중간 GPR를 checkpoint 값으로 무조건 다시 seed하지 않는다. 추적하지 않은 값은
  unknown으로 취급하며 모든 GPR/flags/일반EA 의미 모델이라고 주장하지 않는다.
- 기존32 원래 감사도 읽기 전용으로 병행하여 메모리 replay/frame snapshot/zero/
  queue/PTE/ABI 계약을 유지한다. 31/33/34도 기존 감사와 새 stack/cardinality를 적용한다.
- coherent stack 훼손, PUSHAD 주소·savedESP, segment width/주소, 실제 RET/IRETD,
  REP terminal write, TEST fake write의 거부를 확인한다. 일반 replay만의 거부와 구분한다.
- 이전 Python 감사 코드의 accessbit/abstract trace 소비자를 inventory로 남긴다.
  문자열 패턴 inventory를 전체 의미 검증이나 발견한 모든 취약점 목록이라고 하지 않는다.

정상행/반례 검사, 동일 입력 감사 재실행, 이전 manifest 보존 및 새 해시 검증 후
범위 내 결과만 확정한다. native 예외 전달/다중CPU/실TLB, 실제 자원 재사용·수명,
전체ABI/소비자/IDA/공개소스 계보/GCC2.7 빌드·부팅/후속CPU 의무는 미완료로 유지한다.

## 추가 반례에 따른 설계 수정

독립 검토자가 후반 POP EBX raw와 최종 CPU가 다른데도 통과하는 반례 및 실제
IRETD 직전 NT/CS/SS 모순을 발견했다. root가 모두 Python으로 직접 재현했다.
추가 수정 전에 POP/POPAD로 얻은 known 값의 checkpoint/final 연결과 full/partial/
high-byte alias write시 invalidate, IRETD 실행시점의 지원 조건 검사를 교차검토했다.
unknown 값을 관찰 checkpoint에서 채우지는 않는다. EBX 외 ESI/EDI 및 POPAD로
복원하는 일반 레지스터에도 같은 원칙을 적용한다. 이는 일반 산술/flags 모델이 아니다.
