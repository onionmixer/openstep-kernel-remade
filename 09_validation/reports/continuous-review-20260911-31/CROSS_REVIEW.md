# 보고서31 교차검토와 root 재검증

독립 검토자는 `/root/vm_contract_review27`이다. 읽기 전용으로 계획/원본/후속 코드를
검토했으며 파일 수정이나 producer 실행을 하지 않았다. 의견은 자동 채택하지 않았다.

## 코딩 전

검토자는 main-map 설정, entry-zone 선택, KVA와 high DS linear의 구분,
kernel object offset=KVA, page busy/absent/page_lock 조건, wire count와 zone의
free-list/lock 조건을 지적했다. root가 원본 vm_map_insert, vm_fault_wire_fast,
vm_page_wire, zalloc/zfree와 pmap_expand를 직접 읽고 PLAN 및 시험에 반영했다.
새 물리 PT 자체의 성공과 preexisting zone/전체 boot ownership은 구분했다.

독립 audit 작성 전에는 kernel/user 권한, data PV와 extension WORD count,
entry pop→free→pop 순서, wire-fast 성공/fallback 비실행, raw shared PT를 재검토했다.
kernel root 0x20c00은 CR3 정렬 root가 아닌 directory slice임을 root도 확인했다.

## protection table의 근거 교정

검토 의견 중 protection table을 raw bytes로 고정한다는 표현은 그대로 적용하지 않았다.
root가 whole listing에서 해당 배열이 BSS이며 0x18ef16 이후 원본 bootstrap이
초기화함을 확인했다. audit는 원본 0x18ef30 jump table과 각 분기의 MOV 즉시값에서
kernel/user 배열 기대값을 Python으로 계산하고 runtime snapshot과 대조한다.

## 사후 적대 검토와 수정

초기 정상 matrix가 통과한 뒤 검토자가 메모리 복사본에 다음 훼손을 적용했다.
root도 Python으로 수정 전에 각각 잘못 통과함을 직접 재현했다.

- 모든 시점의 active high PDE를 제거하고 walk 기록까지 일관되게 갱신한 증거.
- PT frame의 high direct-alias PTE를 제거하고 walk 기록까지 갱신한 증거.
- zone inuse 증가 store의 PC/trace index를 INC 0x16b3c1 대신 바로 앞 분기
  0x16b3bf로 바꾼 증거. 원본 trace와 최종 상태는 유지되어 있었다.

이는 실제 runner 성공이 실패했다는 뜻이 아니라 audit가 불가능한 증거를 받아들이는
검증 오류였다. 첫 문제는 walk의 자기일치만 검사하고 실제 접근 선행조건을 요구하지
않았기 때문이다. 두 번째 종류는 PC의 trace 소속만 확인하고 메모리 쓰기 명령인지
검사하지 않았기 때문이다.

수정 후 모든 시점에 PT frame high alias의 존재·RW·supervisor·정확한 물리 주소와
kernel low/high 공유 PTE 연결·권한을 강제한다. replay는 raw Capstone의 memory
write operand/폭을 검사하고 PUSH/CALL은 stack store로 제한한다. 위 훼손과
readonly direct alias를 음성 대조에 추가해 거절하며 정상 matrix도 재통과했다.

검토자는 수정 구간을 다시 읽고 해당 수정의 추가 필수 누락이나 회귀를 발견하지
못했다고 회신했다. 이것은 별도 실행 승인이 아니라 읽기 전용 코드 검토 결과다.
최종 실행·음성 대조·재현·보존 확인은 root가 별도로 수행한다.

## 남는 한계

조건 분기 edge의 적법성을 검사하지만 모든 CPU flag와 memory operand 유효주소를
별도 CPU로 재실행하지는 않는다. metadata/write replay와 별도 상태 모델은 같은
backend 관찰을 소비한다. inherited startup/seed는 trace와 최종 계약 검증이지
처음부터 전 영역의 CPU write provenance를 새로 수집한 것이 아니다.
합성 선행조건과 단일 실행의 성공을 전체 ownership/경합/하드웨어 증거로 확대하지 않는다.
