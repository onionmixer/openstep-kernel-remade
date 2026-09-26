# 보고서35 교차검토 및 root 재검증

검토자 `/root/vm_contract_review27`에게 코딩 전 예외 스택/쓰기 cardinality 확장
계획 검토를 요청했다. 검토자는 원본·보존 JSON만 읽었고 producer/main이나 파일
변경을 수행하지 않았다. root는 Ghidra 스킬에 따라 보존된 원본 ASM을 직접 대조했다.

## 코딩 전 확인

- REP MOVSD와 zero unrolled MOV의 구분. 17b384는 ECX=0xc 반복 뒤 종료 head의
  write0을 남긴다. PUSHAD의 backend hook 주소 순서와 세그먼트 PUSH 폭도 구분한다.
- handler 시작 injectedESP에는 합성 error/frame가 있고 root return slot은
  이전 copy caller의710000이다. fault 이전 trace는 CALL이 없는 경로다.
- 186d40 EBP 계산,186d4a의 trap-base EBX 저장 및 kernel_trap의 실제 PUSH/POP을
  통한 복구,186d69 ESP←EBX를 연결한다. checkpoint를 임의 값 seed로 삼지 않는다.
- POPAD는 savedESP를 건너뛴다. IRETD의 ESP 효과가 decoder metadata에서
  누락돼도 원본 mnemonic에 따라 명시적으로 동권한 복귀를 모델링한다.
- VM/NT/권한변경/alternate stack은 지원 범위 밖이며 위반 시 거부한다.

## 직접 재현한 감사 누락

root는32의 CALL186d63 반환값을deadbeef로 바꾸고 모든 stack snapshot/cursor/
saved_frame을 일관되게 갱신했다. 기존32 전체 감사가 허용하고 새 CALL 검사가
거부함을 확인했다. 이 반례를 공식 대조에 고정했다.

그 뒤 검토자가 새 모델 자체에서 다음을 발견했고 root가 모두 Python으로 재현했다.

- copyout 저장 EBX slot70ffe8을 at_fault/injected/중간/최종 raw에 일관되게
  바꾸어도, 실제 POP EBX는deadbeef를 읽지만 final CPU는12341111이라고 기록한
  모순이 old full audit와 new cardinality/stack 모두 통과했다.
- IRETD 직전 checkpoint의 NT/CS/SS를 바꾸어도 시작점만 지원 조건을 검사하여
  old full audit와 새 검사 모두 통과했다.

추가 코딩 전에 known POP/POPAD 값 연결, full/partial/high-byte alias 쓰기시
invalidate, 실제 IRETD 시점 지원 조건 검사를 다시 교차검토했다. EBX뿐 아니라
ESI/EDI와 POPAD 일반 레지스터도 대상으로 했다. unknown 산술값을 임의로 복원하지 않는다.

구현 중 PUSH 단일 값 변수와 known dict의 이름 충돌로 TypeError가 발생했다.
root 정상행/대조 실행과 검토자 코드 읽기에서 확인해 push_known으로 분리했다.
이 예외는 대조 성공으로 세지 않았으며 고친 뒤 전체 검사와 대조를 다시 실행했다.

## 보완 후 독립 확인

root의 전체31–34 행 검사와 별개로 검토자는 각 보고서의 첫/마지막 대표행을
읽기 전용으로 확인했다. POP EBX/ESI/EDI 모순은 known POP/final, IRETD 현재
NT는 실행시 VM/NT 검사, CS/SS는 checkpoint 지원 조건에서 거절됨을 확인했다.
검토자 의견을 원본 실행 자체의 독립 증명으로 삼지 않으며 범위는 제한된 회귀다.
