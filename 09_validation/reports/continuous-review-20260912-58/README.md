# compat 송신 입력·타입 변환·부분 정리의 정적 검토

## 판정과 증거 범위

송신 copyin에 descriptor 및 payload 범위 검사가 있는 것은 확인했다. 그러나 이것만으로 전체 입력 검증이나 모든 실패의 소유권 정리가 완결되었다고 판정할 수 없다. 특히 long descriptor 길이의 DWORD 계산, 송신과 수신/정리의 타입 인정 범위, 하위 right/VM 함수의 계약은 열린 항목이다.

[원본 대조 증거](copyin-evidence.json)는 함수 본문 6개, 명령어 692개, 본문 바이트 1,887개와 별도 점프 테이블 22개 항목/88바이트를 포함한다. Python으로 Mach-O segment의 VA→파일 offset을 직접 계산하고 보존 decoder의 원본 읽기·명령 길이와 교차 대조했다. 본문 범위와 instruction byte 집합은 정확히 일치하며 직접 분기의 목적지를 확인했다. 이는 디코딩/범위 대조이지 모든 경로의 실행 검증은 아니다.

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다. 입력 fingerprint 26개와 이전 산출물 660개의 보존 해시를 확인했다. Ghidra export는 full-analysis manifest에 대조했다. 공개 소스와 SDK의 현재 fingerprint는 원본 빌드 입력이라는 증명이 아니다.

Ghidra 스킬을 보존된 ASM/C/함수 범위의 읽기 전용 비교에 적용했다. 신규 독립 계획 검토를 확보하지 못한 상태를 유지한다. 새 실행/검증 프로그램, 동적 실행, DB 수정, `07_kernel` 수정 및 GCC 2.7 실빌드는 하지 않았다. 계산은 모두 Python을 사용했다.

## 헤더의 변환 순서

`_ipc_kmsg_copyin_compat` (`0x149628`)는 먼저 `kmsg+0x14`에서 헤더 24바이트를 로컬로 복사한다. `0x14963c`의 CLD와 `0x149642`의 REP MOVSD를 확인했다. 이 복사보다 앞에 전체 헤더 최소 길이를 검사하는 코드는 이 함수에 없다. [이전 송신 경로 검토](../continuous-review-20260912-55/README.md)의 get/호출 경로와 함께 상위 생산자 전제 확인이 남는다. 이를 실제 잘못된 입력의 도달·실행 관측으로 해석하지 않는다.

목적지 이름을 `ipc_object_copyin_header`로 변환하고 실패하면 `0x10000003`을 반환한다. reply 이름이 0이면 reply/type을 0으로 두며, 비제로 reply의 변환 실패에서는 먼저 획득한 목적지 권한을 destroy하고 `0x10000009`를 반환한다. 성공하면 내부 bits를 `(reply_type << 8) | dest_type`으로, remote/local 필드를 객체로 덮어쓴다. size/type/id도 저장한다. Darwin 참고 소스의 별도 OLD_FORMAT 비트 추가는 원본에서 관찰되지 않는다.

저장해 둔 old `msg_simple` 바이트가 **0이 아니면** 본문 descriptor 분석 없이 성공한다. 정확히 1인지만 검사하는 것이 아니다. 따라서 아래 본문 검사는 모든 메시지에 무조건 적용되는 검사가 아니다.

## 본문 길이·타입 검사

복합 메시지의 시작은 `kmsg+0x2c`, 끝은 DWORD 연산으로 계산한 `kmsg+0x14+size`이다. descriptor 시작이 끝보다 작은 동안 진행한다.

| 항목 | 원본 동작 | 실패 결과 |
| --- | --- | --- |
| short descriptor | 남은 범위가 4바이트 이상인지 검사 | `0x10000008` |
| long descriptor | longform일 때 12바이트 이상인지 검사 | `0x10000008` |
| old 포트 타입 | 이름 5 또는 6이면 원소 크기 32비트 요구 | `0x1000000f` |
| inline payload | 계산 길이를 4바이트 정렬한 값과 남은 범위 비교 | `0x10000008` |
| OOL payload | 본문에 주소 슬롯 4바이트가 있는지 검사 | `0x10000008` |
| OOL 획득 | allocation/copyinmap/deallocate 또는 vm_move 상태 검사 | `0x1000000c` |
| 포트 원소 변환 | 각 유효 이름의 copyin 반환값 검사 | `0x1000000a` |

실패 상수 이름은 보존 SDK `mach/message.h`의 INVALID_DEST, INVALID_REPLY, MSG_TOO_SMALL, INVALID_TYPE, INVALID_MEMORY, INVALID_RIGHT와 대응한다. 이 표는 호출된 함수가 정상적으로 반환한다는 전제에서의 분기이며 fault/panic 이후 복구 보장이 아니다.

길이 계산은 `0x149850`의 IMUL, ADD 7, 논리 SHR 3이다. 정확한 기계식은 `(((number * bits) + 7) & 0xffffffff) >> 3`이며 overflow 검사 분기는 없다. short 필드의 최대값은 number 4095, bits 255로, Python 계산상 product+7은 1044232이므로 이 곱셈·덧셈 자체는 DWORD에 들어간다. long 필드의 전체 표현 가능 범위에는 DWORD를 넘는 곱이 있다. 따라서 long의 개수와 산출 바이트 길이가 항상 일치한다고 결론 내릴 수 없다. 유효 메시지 생산자의 제한과 이후 원소 순회에 대한 별도 증명이 필요하다. 산술 확인만 수행했으며 변조 메시지나 실행 테스트는 만들지 않았다.

unused 비트는 지우고 long descriptor의 short name/size/count 부분은 0으로 정리한다. 이 mutation은 뒤쪽 포트 변환이 모두 끝나기 전에 수행된다. 전체 메시지 바이트를 실패 전 상태로 되돌리는 로직은 아니다.

## 권한 타입 점프 테이블

`_ipc_object_copyin_type` (`0x14bb40`)는 unsigned 입력이 `0x15`를 초과하면 panic 경로로 간다. 그 이하는 `0x14bb58`의 원본 DWORD 테이블을 인덱싱한다. 테이블은 함수 본문 범위에 포함되지 않는 데이터이므로 별도로 원본 바이트를 확인했다.

| 입력 타입 | 반환 타입 |
| --- | --- |
| 0 | 0 |
| 5, 16 | 16 |
| 6, 17, 19, 20 | 17 |
| 18, 21 | 18 |
| 나머지 | panic 호출 경로 |

이 송신 본문에서 helper를 호출하는 조건은 이름 5/6뿐이다. 따라서 **이 분기를 통과한 포트 descriptor**는 내부 타입 16/17로 변환된다. 이름은 원소 copyin보다 먼저 descriptor에 저장한다. 원소 값 0과 `0xffffffff`는 변환하지 않고 그대로 건너뛴다. RECEIVE 변환 후 circularity 검사 결과가 참이면 bits에 `0x40000000`을 추가할 뿐, 이 위치에서 오류로 반환하지 않는다. OOL 또는 포트 descriptor를 처리했으면 마지막에 COMPLEX 비트를 추가한다.

[수신 검토](../continuous-review-20260912-56/README.md)의 copyout과 이번 cleanup은 이름 16..21을 포트로 분류한다. 반면 이 old copyin은 해당 이름을 old 포트로 분류하거나 정규화하지 않는다. “5/6의 변환을 확인했으므로 모든 내부 포트 타입의 출처가 검증되었다”는 결론은 성립하지 않는다. 실제 허용 old 타입, 호출 경로별 생산자, 복합 플래그 및 도달 조건을 함께 검토해야 한다. 여기서는 타입 인정 범위의 차이를 기록하며, 실제 panic/오류 발생이나 악용 가능성을 확정하지 않는다.

## copyin wrapper의 반환값과 map 제한

`_ipc_object_copyin_header` (`0x14c15c`) 및 `_ipc_object_copyin_compat` (`0x14c11c`)의 Ghidra C는 `void`이지만 원본은 실패/성공 경로 모두 callee의 EAX를 그대로 유지하여 반환한다. caller는 실제로 EAX를 검사한다. 복원 시 void로 옮기면 안 된다.

header wrapper는 `(space, name, objectp, typep)`를 받으며 `ipc_right_lookup_write(space,name,&entry)` 성공 후 `ipc_right_copyin_header(space,name,entry,objectp,typep)`를 호출한다. compat wrapper는 `(space,name,old_type,dealloc,objectp)`에서 lookup 후 `ipc_right_copyin_compat(space,name,entry,old_type,dealloc,objectp)`를 호출한다. 원본 PUSH와 epilogue에 근거한 ABI이다. Darwin의 `kern_return_t` 선언은 보조 대응 자료이며, 주석의 lock/ref 약속을 하위 원본 검증 대신 사용하지 않는다.

`_copyinmap` (`0x1740d0`)는 map의 pmap이 kernel_pmap이면 bcopy 후 0, 현재 thread의 task map이면 copyin 상태, 다른 map이면 복사 없이 1을 반환한다. 임의의 외부 map을 일반적으로 복사하는 구현이 아니다. 송신 OOL 포트 경로는 이 반환값을 검사한다. 이전 수신 copyoutmap 호출의 결과 무시와는 다르다. bcopy/copyin의 fault 처리 및 VM 전체 계약은 별도 범위이다.

## OOL 및 부분 실패 정리

OOL 포트에서는 kalloc→copyinmap→요청 시 원본 map vm_deallocate 순이다. copyinmap 또는 deallocate 실패는 새 배열을 kfree하고 이전 descriptor까지만 정리한다. 성공한 원본 map deallocate는 이후 포트 권한 변환보다 먼저 일어난다. 뒤의 권한 변환 실패가 원본 사용자 메모리를 복원하는 트랜잭션은 이 함수에 없다. OOL 비포트는 `vm_move(map,source,ipc_soft_map,length,dealloc,&copy)` 결과를 검사하고 성공한 주소를 슬롯에 저장한다. 길이 0은 주소를 0으로 저장하며 이 분기에서는 VM 해제/이동을 호출하지 않는다.

`_ipc_kmsg_clean_partial` (`0x147320`)는 다음 범위를 처리한다.

1. 내부 헤더의 목적지 및 유효 reply 권한을 destroy한다.
2. 본문 시작부터 실패 descriptor 이전까지 순회한다. 포트 원소의 0/`0xffffffff`를 건너뛰고 destroy하며, 비제로 길이 OOL은 포트 배열이면 kfree, 비포트이면 ipc_soft_map에서 vm_deallocate한다. 완료된 inline 포트 배열에는 end_descriptor를 넘는 계산 끝을 줄이는 별도 루프도 있다. 이 주소 계산 자체의 wrap/잘못된 metadata까지 안전하다는 증명은 아니다.
3. `dolast=0`이면 현재 descriptor는 처리하지 않는다. 권한 원소 copyin 실패에서만 caller가 `dolast=1`과 현재 원소 인덱스를 전달한다. 이 인덱스는 **처리한 prefix의 길이**로, 앞에서 건너뛴 null/dead 원소도 포함한다. 실제 획득한 유효 권한 수와 같다고 이름 붙이면 부정확하다. cleanup은 그 prefix를 순회하면서 sentinel을 다시 건너뛴다.
4. 현재 descriptor의 OOL 정리는 prefix 바이트만이 아니라 descriptor의 전체 계산 길이로 배열을 해제한다. 이때 descriptor 이름은 이미 내부 타입으로 바뀌어 있다.

이 함수는 kmsg allocation 자체를 해제하지 않으며 필드/슬롯을 0으로 되돌리지 않는다. 이전 msg_send 분석에서 copyin 실패 후 caller가 kmsg allocation만 해제하는 순서와 대응한다. 권한·VM callee의 실패/락/소유권을 아직 모두 대조하지 않았으므로 “어떤 실패에서도 누수나 중복 해제가 없다”고 판정하지 않는다.

Darwin의 `ipc_kmsg_clean_partial_compat`, `ipc_kmsg_copyin_compat`, `ipc_object_copyin_*`, `copyinmap`은 대응 자료로 읽었다. 원본 clean_partial에는 앞선 body 정리가 직접 포함되어 있으며, Darwin의 추가 정렬·새 VM copy 분기를 원본 동작으로 채택하지 않는다. 확인된 VM 호출은 참고 소스의 MACH_OLD_VM_COPY 계열과 대응한다.

## 다음 범위

[남은 항목](OPEN_ITEMS.md)의 right lookup/copyin 실제 구현과 타입/참조/락 계약을 우선 연결한다. 전체 의미 분석과 실컴파일·부팅 완료를 선언하지 않는다.
