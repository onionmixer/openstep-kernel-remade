# 105차 디컴파일 표현 검토

원본 명령에 근거한 차이와, C에도 이미 있는 실제 계약을 분리한다.
DB·C export는 수정하지 않았으며 원본 코드에 동작을 보충하거나 정상화하지 않았다.

## 메모리 재검사처럼 보이는 spin

RW lock과 host 통계/대기 경로의 C는 `while (*interlock != 0)`처럼 보인다.
선택 원본의 다수 backedge는 MOV 이후의 TEST EAX,EAX로 돌아가므로 loop 내부에서
메모리를 다시 load하지 않는다. 예: 0x15b5dc load, 0x15b5de TEST,
0x15b5e0 JNZ→0x15b5de. strict 29개, NOP를 허용하면 30개를 확인했다.
XCHG/old==1에서 앞 load로 재시도하는 경로와 이 내부 loop는 다르다.
값 변경·interrupt·컨텍스트·도달성이 완결되지 않았으므로 actual hang은 미확정이다.

유한 wait_time loop의 C도 매번 flag/count를 검사하는 듯 보인다. 원본
0x15b638/0x15b6c4/0x15b81c/0x15b938의 load 뒤 해당 backedge는 TEST로 돌아가며
EDX만 감소한다. 이 4개는 snapshot을 검사하는 유한 countdown으로 따로 기록했다.
파일 wait_time=0과 runtime 값 불변은 같은 판정이 아니다.

## SPL의 CLI/STI와 게시 순서

splsched 0x18be68과 splx 0x18b544의 C에는 CLI/STI가 나타나지 않는다.
실제는 진입 CLI, pending callback 전 STI/후 CLI, 정상 epilogue 전 STI가 있다.
이에 따라 단순한 IRQ-disable 함수나 원래 IF를 저장/복구하는 함수로 대체해서 읽으면 안 된다.

현재 수준 0x1e7714는 raw에서 진입 직후 새 수준으로 게시된다. C는 일부 게시를 마지막
대입으로 옮긴다. callback record의 수준을 게시하는 경로도 원본 시점으로 따로 검토했다.
mask shadow 0x1e771c도 raw에서는 OUT 전에 저장되는데 C는 OUT 뒤에 배치한다.
raw는 각 OUT 다음의 LOCK INC가 따로 존재하지만 C는 counter +2로 합친다.
동시 관찰·callback·장치 수명을 검토할 때 C의 재배열을 원본 실행 순서로 사용하지 않는다.

thread_sleep 0x163320은 splx 후 전달받은 interlock을 해제한다. C의 함수 호출 순서도
이는 보존하지만, splx의 CLI/STI/callback 누락을 고려하지 않으면 whole critical section을
과대평가할 수 있다. 실제 교착/경쟁은 후속 caller·IRQ 분석이 필요하다.

## 오류로 오인하지 않을 실제 계약

- lock_read_to_write는 reader 감소 후 충돌 시 1 반환이다. C에도 보이며 성공 0과
  실패 후 read 상실을 이름이나 다른 API 관례에 맞춰 바꾸지 않는다.
- lock_try_read_to_write는 충돌 시 0/read 유지, 선점 후 다른 reader가 남으면 sleep할 수 있다.
  sleep bit 검사도 없다는 사실은 원본에 있다. try=항상 비차단이라는 추론은 부정확하다.
- try_read/write 역시 자체 sleep CALL이 없다는 것과 interlock이 즉시 완료된다는 것은 다르다.
- recursive identity는 set/clear_recursive API가 관리하는 필드다. 일반 write에서
  owner 기록이 C에 누락된 것으로 간주하지 않는다.
- reader WORD/depth 부분의 modulo 가감은 원본 폭이다. C의 short/ushort만 보고
  자체 overflow/underflow guard가 있다고 보충하지 않는다.
- host_stack_usage는 stack_statistics의 기존 max 입력을 먼저 초기화한다.
  104차의 callee 내부 무초기화 사실은 유지되지만, 이 caller의 미초기화 읽기는 확인되지 않는다.
- host의 크기 식은 실제로 count*0xff4의 DWORD 산술이다. 다른 통계 정의에 맞춰
  count*0x1000이나 전체 페이지 카운터라고 바꾸지 않는다.
- memset alignment table의 일부 fragment는 명목상 jump table에 있어도 해당 경로의
  index 생성 범위에서는 도달하지 않는다. 표 전체 export를 실행 coverage로 해석하지 않는다.

경고 8줄과 관련 C 발췌, 원본 instruction/table 값은 [증거](object-lifetime-evidence.json)에 있다.
경고 수를 결함 수로 보거나, 경고가 없는 함수를 ABI/동시성 검증 완료로 처리하지 않는다.

[결과](README.md) · [남은 분석](OPEN_ITEMS.md)
