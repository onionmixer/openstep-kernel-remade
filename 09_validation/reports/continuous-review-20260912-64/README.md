# IPC 순회 삭제와 table 크기·메모리 관리

## 결과와 증거 범위

순회는 child 포인터를 부모 방향으로 잠시 바꾸며 진행한다. next의 delete 인자는 실제 node zfree로 이어지고, finish 자체는 역전된 경로를 복구하지 않는다. table realloc은 단순 데이터 복사가 아니라 기존 backing object를 새 map entry와 공유하는 경로다. table 크기 수열은 참고 Darwin과 원본에 차이가 있으므로 원본 초기값 및 명령어의 산술을 별도로 기록했다.

대상은 OPENSTEP x86 mk-183.34.4, SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다. Ghidra 스킬은 보존 export 읽기 전용 대조에 적용했다. 계산·집계·해시·VA/file offset 대조는 모두 Python이다. [정적 증거](traverse-table-evidence.json)에 full body 명령어, 원본 bytes, 독립 decoding, 분기/call 목적지, 경고 및 조건부 크기 산술을 남겼다.

| 함수 | 주소 | instruction heads | body bytes |
| --- | --- | ---: | ---: |
| traverse_start | `0x151618` | 37 | 85 |
| traverse_next | `0x151670` | 225 | 658 |
| traverse_finish | `0x151910` | 15 | 34 |
| table_fill | `0x151934` | 61 | 146 |
| table_init | `0x1519c8` | 134 | 379 |
| table_alloc | `0x151b44` | 23 | 63 |
| table_realloc | `0x151b84` | 21 | 52 |
| table_free | `0x151bb8` | 20 | 46 |
| kmem_realloc | `0x173c0c` | 104 | 266 |
| vm_set_page_size | `0x17a9b4` | 26 | 83 |

Python 집계: 10개 본문, 666개 명령어, 1812 bytes, 직접 branch 80개, CALL 23개. 별도의 page-size 설정 window 2개 명령어와 초기 데이터 3개 DWORD도 검증했다. 입력 fingerprint 40개와 이전 파일 696개를 확인했다. WARNING 12개 중 traverse_next의 9개는 unreachable block, kmem_realloc의 2개와 vm_set_page_size의 1개는 panic에 대한 non-return 주석이다. 경고 수를 곧바로 결함 수나 미확보 byte 수로 해석하지 않는다.

Mach-O load command를 Python에서 따로 해석하여 보존 디코더의 매핑과 비교했고, 본문 byte의 중복/누락 및 직접 branch의 instruction head를 검사했다. 도구가 정한 함수 경계 밖까지 의미적으로 증명했다는 뜻은 아니다. 참고는 보존 Darwin `ipc_splay.c/.h`, `ipc_table.c/.h`, `vm_kern.c`이며 동일 빌드 소스라는 보장은 없다.

## 순회의 임시 상태와 종료 규칙

start는 비어 있지 않은 root를 assemble한 다음 왼쪽으로 내려간다. `0x15164f`에서 current.left를 이전 parent로 바꾸고 내려가는 방식으로 경로를 뒤집는다. 가장 왼쪽 node를 tree.ltree(`+8`), parent를 tree.rtree(`+0x10`)에 저장하고 current 포인터를 반환한다. 빈 root는 0을 반환하며 다른 tree 필드를 초기화하지 않는다.

순회 중 ltree/rtree는 보통 splay 조회의 좌우 tree root가 아니라 current/parent 저장소다. 일부 child도 실제 자식 대신 상위 경로를 가리킨다. 따라서 일반 lookup/insert나 별도 순회를 중간에 끼워 넣어도 된다고 가정할 수 없다. 참고 소스는 순회 중 tree가 locked라고 설명하지만 `ist_lock/ist_unlock` 매크로는 no-op이며 원본 start/next/finish에도 자체 lock 획득이 없다. 실제 배타성은 caller의 namespace 계약에 의존한다.

next(delete=0)는 current.right가 있으면 그 pointer를 parent로 바꾸고 오른쪽 subtree의 왼쪽 끝으로 내려간다. 오른쪽이 없으면 parent로 올라가면서 뒤집힌 child를 복구한다. unsigned key 비교로 왼쪽에서 올라온 경우와 오른쪽에서 올라온 경우를 구분한다. 왼쪽에서 올라오면 parent를 다음 entry로 반환하고, 오른쪽에서 올라오면 더 올라간다. 정상 BST의 고유 key와 유효 current/parent가 전제다.

더 올라갈 parent가 없으면 `0x1518c8`에서 조립된 current를 tree.root에 저장하고 0을 반환한다. 이 0은 더 이상 방문할 node가 없다는 의미이며 tree가 비었다는 뜻은 아니다. finish는 root가 있을 때 cached name을 실제 root key로 설정하고 tail들을 self-pointer로 바꿀 뿐이다. child 연결을 따라가거나 미완료 경로를 복구하는 loop는 없다.

따라서 정상 사용 계약은 start → 반환 node들을 next로 모두 처리 → next의 0 → finish이다. 중간에 break한 후 finish만 부르는 것을 일반적인 취소/복구 방식으로 채택할 근거가 없다. start가 0을 반환했거나 next가 0으로 끝난 뒤 next를 다시 호출하는 NULL/current 검증도 원본에는 없다. 전체 caller의 중도 종료와 재진입 여부는 다음 분석 과제다.

## next(delete != 0): current를 실제 해제하는 경로

어떤 nonzero delete 값도 삭제 경로로 간다. 단순 표시만 하거나 나중에 finish에서 몰아서 해제하는 방식이 아니다. node의 권한/object ref, hash unlink, request 알림은 이 helper가 처리하지 않으므로 caller가 먼저 정리/이동해야 한다.

| current의 연결 상태 | 원본 zfree 호출 | 다음 상태 |
| --- | --- | --- |
| children 없음, parent 없음 | `0x1516b0` | tree.root=0, 반환 0 |
| children 없음, current key < parent key | `0x1516db` | parent.left를 NULL로, parent를 다음 entry로 반환 |
| children 없음, 그 외 parent 방향 | `0x151700` | parent.right를 NULL로, 위쪽 복구 계속 |
| left 없음, right 있음 | `0x15172b` | 저장해 둔 right subtree에서 왼쪽 탐색 |
| left 있음, right 없음 | `0x151749` | 저장해 둔 left subtree를 이용해 위쪽 복구 |
| children 모두 있음 | `0x151874` | left subtree의 최대 key로 대체, 원래 right를 연결한 뒤 오른쪽 순회 |

각 호출은 `zfree(ipc_tree_entry_zone, old_current)`이다. 필요한 key 방향이나 child/parent를 해제 전에 읽거나 따로 저장하며, 해제 후의 진행은 그 저장된 값과 대체 node를 사용한다. 정상 tree·allocator 수명 전제 아래의 직접 데이터 흐름 확인이며 임의 alias까지 무해하다는 증명은 아니다.

마지막 node를 해제한 경로는 root만 0으로 만들고 ltree/rtree 등 다른 cached 필드를 모두 지우지 않는다. 그 값이 아직 유효한 current라는 가정으로 next를 재호출할 수 없다. finish도 빈 root일 때 이런 필드를 지우지 않는다.

children이 모두 있을 때는 상수 `0xffffffff`를 찾는 splay primitive로 left subtree의 최대 key를 올린다. 조립 후 원래 current.right를 `0x151863`에서 읽고 `0x151866`에서 대체 node에 연결한 뒤 old_current를 해제한다. 이는 [보고서 63](../continuous-review-20260912-63/README.md)의 table 이동에서 `traverse_next(move,1)`가 실제 tree node를 해제하는 지점을 보완한다. global hash 삭제/권한 table 복사는 caller에서 이보다 앞서 수행된다.

## traverse_next의 unreachable 경고

원본 `0x151778`은 비교 레지스터를 DWORD 최댓값으로 설정한다. `0x15177f JNC`의 unsigned `MAX >= key`는 항상 참이므로 바로 뒤 왼쪽 탐색 블록은 정상 entry 경로에서 선택되지 않는다. `0x151808` 이후 같은 상수 비교의 `0x15180f JNC`도 항상 참이어서 뒤 fallthrough가 선택되지 않는다.

반면 `0x1517e5 JBE`는 `MAX <= key`, 즉 key==MAX일 때의 분기다. 이를 무조건 참으로 바꾸면 안 된다. Python 증거에 unsigned 영역 경계의 predicate를 기록했다. 경고 대상 블록의 bytes와 직접 분기는 전부 보존했으며, 상수 분기 설명을 전역 jump-in·임의 손상 상태·전체 CFG의 전수 증명으로 확대하지 않는다.

## table 크기 목록: 파일 초기값과 runtime 설정의 분리

원본 데이터 `0x1dea94`는 entry descriptor count=128, `0x1dea98`는 dnrequest descriptor count=64이다. page_size 전역 `0x1e0d0c`의 파일 값은 0이다. 이를 곧바로 table 초기화 시 page 크기로 사용하면 안 된다.

보존된 `0x18ab2b` 명령은 page_size에 `0x2000`을 저장하고, 바로 다음 `0x18ab35`에서 vm_set_page_size를 호출한다. 해당 window가 실행된다는 조건 아래 Python 계산은 page_size=8192, page_mask=8191, page_shift=13이다. 이 VM page 크기를 x86 하드웨어 PTE page 크기와 자동으로 동일시하지 않는다. 실제 부팅에서 table_init 전에 이 경로를 거쳤고 이후 변경이 없다는 실행/전역 수명 증거는 별도 과제다.

vm_set_page_size는 먼저 page_mask=page_size-1을 저장하고 비트 조건을 검사한다. 실패는 panic이다. 통과하면 shift를 증가시켜 `1 << shift`가 page_size가 될 때까지 반복한다. 0도 최초 비트 조건은 통과하므로 이 검사만으로 page_size>0이 보장되는 것은 아니다. 정상 설정 window는 양의 값을 제공한다. 이 함수도 잘못된 0을 안전한 기본값으로 보정하지 않는다.

table_fill은 `(array, num, minimum_elements, element_size)`를 받아 byte size=1부터 page_size 미만의 2의 거듭제곱을 사용한다. minimum*element_size 이상일 때 unsigned division으로 element 수를 저장한다. 이후 page_size 간격으로 진행하며 15번마다 간격을 두 배로 한다. minimum 곱과 shift/add는 DWORD 산술이며 일반 인자의 0 element_size/overflow/잘못된 page_size 방어는 없다. num=0이면 쓰지 않고 반환한다.

table_init은 fill을 CALL하지 않고 같은 계산을 inline으로 수행한다. entry array는 count*4 bytes를 kalloc하고 count-1개를 최소 4 entries, stride 16으로 만든다. 마지막 descriptor는 바로 이전 값을 복사한다(`0x151a81`). dnrequest array는 최소 2 entries, stride 8이며 마지막 descriptor에 0을 저장한다(`0x151b31`). kalloc 실패를 검사하는 원본 branch는 없으므로 초기화 성공을 가정하는 코드다. 재호출 시 기존 array를 해제하거나 보존하는 처리도 없다.

참고 Darwin은 entry count를 512로 두며 table_fill의 증가 간격을 `PAGE_SIZE << 3`에서 제한한다. 원본은 count 128이고 generic fill의 `0x1519b5` 및 inline init의 `0x151a6b/0x151b1f`에서 간격을 조건 없이 두 배로 한다. 배열 길이나 최대값을 참고 소스에서 그대로 가져오면 원본과 다른 정책이 된다.

## 조건부 크기 산술 결과

Python으로 원본의 정수식에서 유한 크기 수열을 계산했다. 조건은 파일의 count 기본값이 변경되지 않고, 위 page-size 설정이 완료되며, kalloc과 초기화가 정상 진행되는 것이다. CPU/커널 실행이나 실제 runtime 배열을 관찰한 결과가 아니다.

| 목록 | descriptor 수 | 목록 메모리 bytes | 최소 element 수 | 최대 element 수 | 최대 table bytes | 마지막 값 |
| --- | ---: | ---: | ---: | ---: | ---: | --- |
| entries | 128 | 512 | 4 | 1893376 | 30294016 | 이전 최댓값 반복 |
| dnrequests | 64 | 256 | 2 | 174080 | 1392640 | 0 |

수열 전체는 JSON에 보존했다. entries의 앞부분은 4, 8, 16, 32, 64, 128, 256, 512, 1024, 1536으로 이어진다. 종료 중복을 제외한 엄격 증가, 모든 저장 byte-size의 DWORD 범위, entries 최댓값이 MACH_PORT_DEAD의 index 상한 이하임을 Python으로 확인했다. entries 최대 name 경계는 `0x1ce40000`으로 계산된다.

이는 앞선 grow_table의 양의 osize와 name shift 상한을 기본 설정 조건에서 뒷받침한다. count/page_size가 부팅 중 변경되는 경우, 특수 space의 다른 descriptor 사용, 임의 손상·overflow 또는 전체 caller에 대한 무조건적 보장은 아니다. dnrequest의 마지막 0과 entries의 마지막 중복이라는 다른 sentinel 계약도 유지해야 한다.

## table 메모리 wrapper

| 함수 | 원본 호출/반환 계약 |
| --- | --- |
| alloc(size) | size < page_size이면 kalloc(size), 그 외 kmem_alloc(kalloc_map,&local,size); kmem 오류는 포인터 0 |
| realloc(old_size,old_table,new_size) | kmem_realloc(kalloc_map,old_table,old_size,&local,new_size); 오류는 포인터 0 |
| free(size,table) | size < page_size이면 kfree(table,size), 그 외 kmem_free(kalloc_map,table,size) |

page_size와 같은 크기는 VM 경로다. wrapper 자체에는 namespace lock이나 NULL/old-size 정합성 검사가 없다. realloc wrapper는 old table을 직접 free하지 않으며 C 라이브러리 realloc처럼 이전 포인터를 자동 폐기한다고 해석해서는 안 된다. free는 반환 status 계약이 없는 void 함수이며 내부 helper의 EAX를 외부 status로 채택하지 않는다.

## kmem_realloc: 복사가 아닌 backing object 공유

원본 인자는 `(map, oldaddr, oldsize, newaddrp, newsize)`이다. page_mask로 oldmin을 내림 정렬하고 oldaddr+oldsize의 끝을 올림 정렬하여 old span을 계산한다. newsize도 올림 정렬한다. 덧셈은 DWORD wrap이므로 유효 크기·주소와 page-mask 조건이 필요하다. 반환 포인터는 새 정렬 영역의 base이며 oldaddr의 내부 offset을 더하는 동작은 없다.

`0x173c48`에서 vm_map_find(map,NULL,0,&local,new_span,TRUE)를 호출한다. 실패값을 `0x173c52 SETNZ`와 `AND EAX,0xff`로 1로 정규화하고 출력은 쓰지 않는다. 참고 Darwin의 `return kr`와 다른 관찰이다. table_realloc wrapper는 nonzero 여부만 사용하므로 그 차이를 숨길 수 있지만 원본 kmem API의 status 범위는 별도로 보존해야 한다.

성공하면 새 주소와 oldmin에 대해 vm_map_lookup_entry를 호출한다. 새 entry lookup 반환값은 검사하지 않고 old lookup 실패는 panic이다. old entry `+0x10`의 backing object를 읽어 vm_object_reference를 호출한다. object `+0x10` lock을 잡은 후 object `+0x14` size가 old span과 같은지 검사하며 다르면 panic한다. 이 lock에는 `0x173ca4 MOV` 뒤 `0x173ca8`이 TEST로만 되돌아가는 register-only wait가 있다.

정상 경로는 object.size를 new span으로 바꾸고 unlock한다. `0x173cd8`에서 새 entry.object에 같은 object 포인터를 저장하고 `0x173cdb`에서 offset=0으로 만든다. lock_done(map) 뒤 `FUN_00173ebc(object,old_span,new_span,1)`와 vm_map_pageable(map,newbase,newbase+new_span,0)를 호출한다. pageable의 반환 status는 확인하지 않은 채 newaddrp를 쓰고 0을 반환한다.

이 본문에는 old entry 제거/free나 데이터 bcopy 호출이 없다. object 공유와 별도 old-table free라는 앞선 grow_table의 구조를 확인한 것이며, 하위 helper의 모든 page 생성·wire·alias·오류 처리를 검증한 것은 아니다. map lock 획득은 이 본문에서 별도 호출로 드러나지 않으므로 vm_map_find/lookup의 lock 계약도 추적해야 한다. 참고 Darwin은 명시적 vm_map_lock/find_entry와 remap_pages/alloc_pages를 사용하므로 구현 순서를 그대로 대체할 수 없다.

## 남은 작업과 보존

다음은 space 생성/파괴와 growing 대기, traversal의 모든 caller 및 VM map/page helper의 수명·실패 계약이다. 전체 [OPEN_ITEMS](OPEN_ITEMS.md)를 유지했다. 신규 독립 계획 검토가 확보되지 않은 상태에서 새 실행 검증 프로그램·동적 실행·구현은 하지 않았다. 원본·참고 소스·DB·기존 export/확정 보고서·07_kernel은 보존했다. GCC 2.7 실컴파일·Mach-O 링크·부팅 및 전체 원본 의미 분석은 미완료다.
