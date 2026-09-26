# Codex 교차검토 — 보고서28

## 코딩 전 검토

`/root/vm_contract_review27`에 읽기 전용 검토를 요청하고 코드 작성 전에 결과를
받았다. 원본 alloc/free/startup과 새 cached seed 제안을 별도 회신으로 검토했다.
root도 동일 ASM과 Darwin vm_resident/pageout 소스를 직접 읽어 대조했다.

- reserve의 signed 비교와 equality 허용, empty 선행 반환, thread privilege
  참조 조건을 구별해야 한다. 실제 시험은 empty/below/equal/above를 분리했다.
- tabled 제거 탐색에 NULL 종료 검사가 없으므로 hash/memq 멤버십을 원본 init으로
  구성해야 한다. 정상 free와 cached addfree를 다른 seed로 실행한다.
- addfree는 직접 호출 시 중복 free를 막지 않는다. free/fictitious 비트 해제,
  active/inactive 큐 및 caller 잠금 전제를 확인해야 한다.
- template를 임의의 zero bytes로 대체하면 busy/clean 초기값을 놓친다. zero BSS를
  확인한 뒤 원본 startup prefix를 실행하고 결과 전체를 대조한다.
- prefix가 queue lock을 0으로 초기화하므로 caller lock=1 준비는 prefix 이후다.
- pageout 임계값은 할당 후 count 기준이고 last_alloc는 sequential 인자 0이어도
  갱신된다. policy=0 조건의 인자 대조를 policy 실행으로 확대하지 않는다.
- cached seed에서 busy를 API로 해제하는 것은 합성 준비 경계다. 원본 pageout의
  매핑 제거·wakeup을 실행한 것으로 부르지 않는다. 별도 합성 frame을 사용하고
  fixture A/B root 전체 PDE/PTE에서 해당 frame의 매핑이 없는지 확인한다.

검토 의견 자체를 원본 증거로 취급하지 않았다. 위 조건은 원본 주소/상태 검사와
독립 Python metadata 모델에 반영했다. 전체 원본 VM/PV 소유권은 여전히 미검증이다.

## 실행 뒤 후속 검토와 수정

동일 검토자에게 실행 코드와 독립 audit를 읽기 전용으로 검토하도록 요청했다.
원본 계약/상태 전이의 불일치는 발견하지 못했으나 audit의 누락을 지적했다.

- 초기 audit는 scenario의 reserved/privilege 값을 독립 계산하지 않고 기록을
  채택했으며, seed별 operation schedule과 operation 이름→원본 entry 대응을
  별도로 검사하지 않았다. root가 해당 코드를 확인하고 지적을 수용했다.
- 수정 audit는 scenario에서 전체 호출 순서·인자·원본 entry·reserve/privilege를
  독립 도출한다. 최초 object/page/hash/queue 상태도 독립 기대값과 대조한다.
  reserve equality/privilege/entry/seed operation/seed label을 손상시킨 음성 대조를
  추가하여 각각 거절되는 것을 확인했다.
- 허용 범위 밖 쓰기 거절 hook은 관측 함수의 call()에만 적용된다. startup prefix는
  별도 원본 trace·template/queue 결과로 검사하며 같은 hook 범위로 주장하지 않는다.
- 물리 frame 무매핑은 실행 fixture의 A/B 스캔 근거다. 독립 audit가 PDE/PTE를
  다시 스캔했다고 주장하지 않는다.

root는 함수 call의 허용 쓰기 영역 검사, object/descriptor 주변 guard 및 원본
last_alloc store의 양성 hook 관찰을 추가했다. 최종 원시 결과로 독립 검산 및
음성 대조를 다시 실행했다. 검토자는 코딩/파일 수정/fixture 실행을 하지 않았다.

수정 뒤 읽기 전용 재검토에서도 scenario/schedule/entry/초기 상태 검사로 지적한
누락이 해소됐고 문서의 prefix hook·무매핑 스캔·동일 backend 한정이 정확하다는
회신을 받았다. root의 실제 재현/해시 대조 결과와 이 정적 검토 의견은 구별한다.

모든 수치 계산은 Python이다. 같은 backend 기록의 독립 검산이며 독립 하드웨어
실행이나 실제 scheduler/pageout/경합을 검증한 것은 아니다.
