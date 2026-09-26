# 원본 참조 수명·재사용의 정적 근거

근거는 [static-evidence.json](static-evidence.json)의 원본 바이트 해독, 보존 Ghidra listing, 호출자 문맥과 참조 소스 식별자다. Ghidra 함수명은 보존 export의 이름이며 모든 호출자 함수의 의미 검증을 완료했다는 뜻이 아니다. Darwin 소스는 비교 자료이지 OPENSTEP 원문과 동일하다는 증거가 아니다.

## 생성·참조·해제 계약

| 원본 위치 | 정적으로 확인한 동작 | 아직 입증하지 않은 것 |
|---|---|---|
| `18f648..18f650` | size가 0이 아니면 EAX=0으로 반환, zalloc을 호출하지 않음 | 모든 caller에서 가능한 size 값과 도달 조건 |
| `18f676..18f68b` | pmap 구조체의 `0x1c` 바이트를 bzero, PD 생성 후 ref_count=1, lock=0 | GCC 2.7 구조체 layout 및 실제 컴파일 |
| `18f7bb..18f7bd` | NULL reference는 lock/참조 증가를 건너뜀 | 새 동적 nullable 호출 시험 |
| `18f7d7..18f7e5` | lock 획득, `[pmap+8]` 증가, lock 반환 | 경합·overflow·비동기 실행 |
| `18f6a5..18f6a7` | NULL destroy는 즉시 epilogue로 이동 | 새 동적 nullable 호출 시험 |
| `18f6cc..18f6e6` | ref_count 감소 후 lock 반환; 감소 결과가 0이 아니면 PD 반환을 건너뜀 | 잘못된 참조 수·중복 해제 입력의 실제 도달 가능성 |
| `18f756..18f797` | 마지막 참조일 때 슬롯 사용 수 감소, full→partial 큐 재삽입, 선택 bitmap 비트 해제 | 다중 backing 큐 수명·동시성 |
| `18f7a2` | 슬롯 반환 후 pmap zone element 반환 | 마지막 참조가 아닌 경로의 새 연속 실행 |

비NULL pmap의 refcount 증가·감소 경로는 모두 `18b964`와 `18b544`를 호출한다. 저장된 대상의 `18b964` listing은 현재 IPL 값을 읽고 반환하는 코드다. 참고 소스의 `SPLVM` 이름만으로 실제 하드웨어 마스킹이나 동시성 보호를 추가 가정하지 않는다. `18b544`에는 CLI/STI 및 다른 분기가 있으며 기존 synthetic 호출 결과를 비동기 IRQ 검증으로 확대하지 않는다.

## 재사용 시 zero 범위가 중요하다

기존 PD backing을 얻는 `18f429..18f484` 경로는 alloc_count 증가, 필요 시 free-PD 큐 제거, bitmap의 빈 비트 선택, root 설정을 수행한다. 이 경로에는 PD 전체 bzero가 없다. `18f58c`는 root의 정렬과 물리 주소를 확인·설정하고 kernel PDE 영역을 복사한다. 생성 루틴의 bzero 대상은 PD가 아니라 pmap 구조체다.

따라서 다음을 구별해야 한다.

- fresh backing의 초기 zero 상태;
- pmap 구조체 재사용 시 초기화;
- 반환된 PD 슬롯의 기존 사용자 PDE 상태;
- 커널 PDE 재복사.

참고 `pmap_destroy` 주석은 유효 매핑이 없는 pmap만 호출하도록 요구한다. 원본 destroy 본문도 사용자 PDE 전체를 지우지 않는다. report41의 create_slot1 종료 상태를 다시 읽어 양쪽 슬롯의 사용자 PDE 영역 `0xc00` 바이트가 모두 0이고 refcount가 각각 1임을 8개 보존 사례에서 확인했다. 이는 해당 보존 prefix의 전제를 확인한 것이며 새 슬롯 재사용 실행을 했다는 뜻이 아니다.

## 직접 호출자 대조

보존 code-units의 instruction head 286,091개 중 길이가 5인 head 31,181개의 원본 바이트를 읽고 `E8 rel32`의 목적지를 Python으로 계산했다. 선택 대상에 대한 결과가 보존 references.tsv의 직접 호출 목록과 정확히 일치했다. indirect/far/prefix 포함 다른 호출 형식이나 미식별 코드의 부재를 증명한 것은 아니다.

| 대상 | 직접 호출 위치 | 보존 함수명 |
|---|---|---|
| create | `1070bd` | `_smmap` |
| create | `108d51` | `_kill_tasks` |
| create | `15ceb2` | `FUN_0015ce08` |
| create | `15d45a` | `FUN_0015d3fc` |
| create | `1658ad` | `_map_fd` |
| create | `165ab1` | `_task_create` |
| create | `177a91` | `_vm_map_fork` |
| reference | `15ca8f` | `_load_machfile` |
| reference | `174018` | `_kmem_suballoc` |
| destroy | `17482d` | `_vm_map_deallocate` |
| destroy | `176119` | `_vm_map_entry_delete` |
| destroy | `17654d` | `_vm_map_delete` |
| destroy | `1779ae` | `_vm_map_copy` |

`_kmem_suballoc`은 원본 `174014`에서 부모 map의 `+0x24` 필드를 읽어 reference하고, `174029..17402d`에서 같은 필드를 새 map 생성에 전달한다. `_load_machfile`의 reference도 map의 `+0x24` 필드를 사용한다. 이는 공유 pmap의 참조 수명이 별도 분석되어야 함을 보여 주지만 각 caller의 전체 성공·오류·rollback 수명을 검증하지는 않는다.

destroy 직접 호출 문맥에는 앞선 `vm_map_delete` 호출이 관찰된다. 특히 `_vm_map_deallocate`는 map refcount 감소 후 필요한 경로에서 map lock과 전체 범위 delete를 수행하고 `pmap_destroy(map->pmap)` 및 map zone 반환을 호출한다. 이 순서 확인만으로 모든 사용자 매핑이 실제 제거됐다고 단정하지 않는다. `vm_map_delete`의 성공·반환·중첩 map과 pmap 참조 수명의 연속 검증은 남아 있다.

map refcount의 계속 반환 조건은 `17480b..17480d`의 signed greater-than인 반면 pmap destroy의 계속 반환 조건은 `18f6e4..18f6e6`의 nonzero다. 유효 참조 수의 호출 전제를 확인하지 않고 두 코드를 같은 함수로 모델링하면 안 된다. 이것은 정적 분기 차이이며 실제 커널 오류나 도달 가능한 underflow를 발견했다는 주장이 아니다.

## 완료/미완료 판정

이번에 완료한 것은 정적 호출 목록·선택 함수 본문 바이트 해독·보존 prefix의 사전조건 검사다. 독립 계획 교차검토, 새 producer/consumer, 새 연속 실행, 기록 변조 대조 및 같은 backend 재현성은 아직 수행하지 않았다. 이전 report41의 성공 지표를 이번 경로의 검증 결과로 사용하지 않는다.
