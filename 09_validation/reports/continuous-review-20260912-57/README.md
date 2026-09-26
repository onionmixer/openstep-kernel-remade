# 포트 compat copyout: 권한 이전과 참조 처리

## 판정

compat object copyout은 실패 시 name 출력값을 보장하지 않는다. report56의 상위 함수가 실패한 object를 destroy하고 name을 0으로 만드는 이유가 이 계약과 연결된다. 성공 시 참조가 소비된다는 것은 항상 reference count를 감소시킨다는 뜻은 아니다. 새로운 entry로 소유권을 이전하는 경우와 기존 권한에 병합하며 추가 참조를 감소시키는 경우가 다르다.

[범위](SCOPE.md), [원본·계산 증거](rights-evidence.json), [이전 파일 보존](preservation.json), [남은 분석](OPEN_ITEMS.md)을 보존한다. Ghidra 스킬로 원본 명령·호출 인자·참조 소스를 교차 확인했고 계산은 Python만 사용했다.

본문 5개, 명령 371개, 921바이트와 상위 caller 창 3개·49개 명령을 대조했다. 입력 26개와 이전 파일 654개를 재해시했다. Ghidra 입력은 full-analysis manifest에 일치한다. 동적 실행, 독립 계획 검토, 전체 권한 수명 증명은 아니다.

## `ipc_object_copyout_compat` (`0x0014c198`)

원본 인자는 `(space, object, carried_type, namep)`다. space `+8`의 lock을 획득한 뒤 active 필드 `+0xc`를 검사한다.

- space가 inactive이면 명시적으로 unlock하고 `KERN_INVALID_TASK`(16)를 반환한다. namep를 쓰지 않는다.
- SEND_ONCE가 아닌 경우 reverse lookup으로 같은 object의 기존 name/entry를 찾는다. SEND_ONCE는 이 병합 검색을 건너뛴다.
- 새 entry 획득 실패 시 grow_table을 호출하고 성공하면 active 검사부터 반복한다. wrapper 안에서 grow_table 호출 직전 별도로 unlock하지 않으므로, 성장 helper의 내부 lock 계약을 확인해야 한다.
- entry 획득 후 object를 lock한다. inactive이면 object unlock → 새 entry dealloc → space unlock → `KERN_INVALID_CAPABILITY`(20) 반환이다. object 자체를 이 분기에서 destroy하지 않는다.
- dead-name request 등록 실패 시 entry를 dealloc하고 space lock을 푼 뒤 port request table을 키운다. 성장 성공이면 space lock을 다시 획득해 active 검사부터 반복한다. port unlock은 하위 helper 계약에 의존한다.

request 등록 성공 시 `ipc_space_reference(space)`를 호출하고 entry의 object `+4`, request index `+8`을 기록하며 bits에 `IE_BITS_COMPAT`를 OR한다. request에 전달하는 값은 `space | 1`이다. 공개 `ipc_port.h`의 tagged space 포인터 설명과 대응하지만, 실제 allocator 정렬 보장은 아직 검증하지 않았다.

최종 `0x0014c2f3` 호출은 `ipc_right_copyout(space, name, entry, type, 1, object)`이다. 이후 space를 unlock하고, 성공한 경우에만 `0x0014c309`에서 namep에 이름을 쓴다. 실패 시 namep를 0으로 설정하는 동작은 없다. 상위 caller가 실패 후 슬롯을 명시적으로 0으로 하는 것을 생략하면 같은 계약이 되지 않는다.

`ipc_space_reference` (`0x001506b0`)는 별도 reference lock 아래 space `+4`를 증가시키고 unlock한다. Ghidra의 int 반환은 lock 연산 뒤 EAX를 표현한 것으로, 공개 선언은 void이며 이 caller도 반환값을 소비하지 않는다.

## `ipc_right_copyout` (`0x0014fb2c`) — 이전과 병합의 구분

이 함수는 space와 object가 적절히 lock된 상태, 유효한 carried type 및 entry 불변식을 전제로 한다. 원본의 직접 갱신을 확인했지만 reverse/hash/notification 등의 전이적 구현은 완료하지 않았다.

| 입력 권한과 기존 entry | 직접 처리 |
|---|---|
| SEND_ONCE | object unlock, entry bits에 SEND_ONCE와 uref 1 설치. 참조 수를 직접 감소시키지 않는다. |
| SEND, 기존 SEND | 추가 send-right 수와 object reference를 감소시키고 entry uref 증가. 경계값은 별도 분기. |
| SEND, 기존 RECEIVE만 있음 | 추가 object reference를 감소시키고 entry에 SEND와 uref 설치. |
| SEND, 기존 권한 없음 | object unlock 후 hash insert, entry에 SEND와 uref 설치. 직접 ref 감소 없이 소유권을 이전한다. |
| RECEIVE, 기존 SEND 있음 | receiver/name 갱신, 추가 object reference 감소, hash delete, RECEIVE bit 설치. |
| RECEIVE, 기존 권한 없음 | receiver/name과 RECEIVE bit 설치. 직접 ref 감소 없이 이전한다. |

RECEIVE의 이전 destination이 nonzero이면 이후 object_release를 호출한다. 이 destination의 transit 상태·추가 참조와 최종 해제까지 모두 검증한 것은 아니다.

### user-reference 비교 경계

원본은 기존 SEND entry의 하위 word를 `0xfffe`와 비교한다. Python 계산으로 65534이며 다음 값은 65535다. 이 경계에서 overflow 인자가 0이면 object를 unlock하고 `KERN_UREFS_OVERFLOW`(19)를 반환하며 권한·참조를 소비하지 않는다.

overflow 인자가 nonzero이면 entry bits를 유지하고 추가 send-right와 object reference를 감소시킨 뒤 성공한다. compat caller는 인자를 1로 고정하므로, 유효한 SEND 경로에서 이 경계의 overflow 오류는 compat caller로 반환되지 않는다. 참조 소스의 'maximum에 고정' 설명을 실제 원본 비교값과 구분해 기록했다. 잘못된 entry bits 또는 범위 밖 uref까지 이 규칙으로 보장하지 않는다.

## destination 변환은 일반 권한 copyout과 다르다

`ipc_object_copyout_dest` (`0x0014bfa4`)는 들어올 때 object가 이미 locked/active라는 계약이다. 첫 동작으로 object reference를 감소시키고 destination 권한을 소비한다. 수신 space에 새 SEND 권한을 설치하는 함수가 아니다.

- SEND이면 send-right 수를 감소시킨다. 마지막 send-right이고 no-senders request가 있으면 request를 분리하고 mscount를 저장한다. receiver가 요청 space와 같으면 receiver name, 아니면 0을 출력한다. unlock 뒤 필요하면 no-senders notification을 호출한다.
- SEND_ONCE이며 receiver가 같은 space이면 send-once 수를 감소시키고 이름을 출력한다.
- SEND_ONCE인데 receiver가 달라졌으면 앞서 감소시킨 reference를 복구한 뒤 unlock하고 send-once notification에 넘긴다. 출력 이름은 0이다. notification이 실제로 참조를 소비하는 과정은 추가 검증 대상이다.
- 그 밖의 type은 panic 경로다. type 검사보다 reference 감소가 먼저 있으므로 잘못된 type의 무해한 실패 처리를 가정하지 않는다.

Ghidra는 이 함수에 `undefined4` 반환과 `uVar2`를 붙였지만, 공개 선언은 void이고 실제 상위 caller도 EAX를 검사하지 않는다. 결과 이름은 `namep`로 전달된다. incidental EAX를 상태값으로 복원하면 안 된다.

## `ipc_object_destroy` (`0x0014bd68`)의 원본/참조 차이

원본은 type 16에서 release_receive, 17에서 release_send, 18에서 send-once notification을 호출한다. 다른 type은 이 본문에서 아무 release 호출 없이 반환한다.

Darwin 참조의 default는 panic이다. 원본의 범위 밖 분기를 그 참조 코드로 교체하면 동일한 동작이 아니다. 또한 destroy가 모든 정수 type에 대해 자원을 정리한다고 판단할 수 없다. report56에서 확인한 type 정규화 전제와 연결하여 송신 copyin 단계의 carried-type 생산자를 검증해야 한다.

release_send/release_receive/notification의 전체 참조 회수·포트 파괴·실패 처리는 아직 완료하지 않았다. 함수 이름이나 참조 소스의 'consumes a ref' 설명만으로 원본의 전이적 수명까지 통과시키지 않는다.

## 다음 경계

원본의 명시적 갱신과 공개 소스의 계약은 대응되지만, 성장 함수는 참조 버전과 인자 수가 다르며 lock 해제·재획득 규칙은 더 확인해야 한다. 다음은 reverse lookup, entry/dead-name request table 성장, notification·최종 port release, copyin의 type/길이 검증이다.

이번 결과는 full-binary 의미 완료, 실제 동시 실행·부팅, GCC 2.7 실컴파일 또는 후속 아키텍처 검증을 의미하지 않는다. 원본 DB/export와 참조 소스 및 복원 커널은 수정하지 않았다.
