# 전체·부분 메시지 cleanup의 소유권 경계

보고서 66의 지연 메시지 파괴 다음 단계로 cleanup 본문과 free dispatch를 검토했다. **cleanup은 임의 입력을 안전하게 검증하는 parser가 아니다.** 부분 cleanup은 이미 변환한 권한 prefix만 정리하면서 OOL 버퍼는 원래 descriptor 전체 크기로 해제한다. 참고 Darwin의 같은 함수 이름을 그대로 채택하면 ABI와 메시지 형식이 달라진다.

Ghidra 스킬을 보존 export 읽기 전용 대조에 적용했으며 원본 명령어를 판단 기준으로 삼았다. 계산은 모두 Python이다. 문서·정적 증거만 추가했고 구현·새 실행 검증 프로그램·동적 실행·GCC 2.7 빌드는 하지 않았다. 이전 턴은 보고서 66과 검증 증거를 확정한 실제 진전이며, 그 checkpoint를 재검증한 뒤 진행했다.

## 증거

[정적 증거](kmsg-cleanup-evidence.json)는 원본 주소/파일 offset·명령어 바이트·독립 디코딩·분기와 호출·caller window·계산·입력 해시를 담는다. [보존 목록](preservation.json)은 기존 확정 자료를 잇는다.

| 함수 | 주소 | instruction heads | 본문 바이트 |
|---|---|---:|---:|
| ipc_kmsg_clean_body | 0x14707c | 108 | 281 |
| ipc_kmsg_clean | 0x14719c | 146 | 381 |
| ipc_kmsg_clean_partial | 0x147320 | 206 | 555 |
| ipc_kmsg_free | 0x147550 | 26 | 54 |
| ipc_object_destroy | 0x14bd68 | 32 | 64 |

Python 집계는 5개 본문, 518개 instruction heads, 1335바이트, 직접 분기 83개, 호출 23개다. 별도의 copyin caller window는 2개, 68개 instruction heads다. C의 명시적 WARNING은 0개지만 아래와 같은 실제 해석 차이가 있다. 이 수치는 전체 커널의 의미 검증 coverage가 아니다.

## 공통 body parser: 원본 ABI와 형식

0x14707c의 인자는 `(start_address, end_address)`다. unsigned start < end 동안 descriptor를 읽는다. 원본 clean과 clean_partial은 같은 로직을 본문에 펼쳐 놓았으며 clean_body를 직접 CALL하지 않는다.

descriptor 첫 DWORD의 byte+3에서 inline(bit 0x10), longform(bit 0x20)을 추출한다. 짧은 형식은 name byte+0, size-in-bits byte+1, count=(word+2 & 0xfff), descriptor 크기 4다. 긴 형식은 name word+4, size word+6, count DWORD+8, 크기 12다. 원본에서 이 cleanup 로직은 deallocate bit(0x40)를 검사하지 않는다. 전송 시의 원본 주소 deallocate 요청과, 이미 메시지가 소유하게 된 버퍼를 cleanup하는 것은 다른 단계다.

byte length는 원본 IMUL의 하위 DWORD → ADD 7 → logical SHR 3 순서다. 즉 `(((count * bitsize) mod 2^32 + 7) mod 2^32) >> 3`이다. inline 이동량은 `(length + 3) & 0xfffffffc`다. 큰 정수의 무제한 곱셈/나눗셈으로 원본을 모델링하면 안 된다. 원본에는 이 계산의 overflow를 별도 reject하는 분기가 없다.

`unsigned(name - 0x10) <= 5`가 port 분류다. 실제 object_destroy를 호출할 때는 원소값 0/-1을 건너뛴다. inline port 배열은 data + count*4가 end를 넘는 동안 count를 감소시킨다. OOL port 배열은 data 슬롯의 pointer를 사용하고 descriptor count 전체를 순회한다.

중요하게도 inline clip은 **권한 순회 count만** 줄인다. 이미 저장한 byte length를 다시 계산하지 않으므로 다음 descriptor 주소는 원래 length로 이동한다. Python의 조건부 예시에서 data=0x1000, end=0x1008, count=3, size=32이면 권한 순회 count는 2로 줄어도 byte length는 12, 다음 주소는 0x100c다. 이는 실제 메모리 실행 시험이 아니라 원본 수식의 예시다.

OOL이면 length가 비영일 때 port 배열은 kfree(data,length), 그 밖의 데이터는 vm_deallocate(ipc_soft_map,data,length)로 정리한다. vm_deallocate의 반환 상태를 검사하지 않는다. OOL 다음 항목으로는 pointer 슬롯 크기만큼 이동한다. inline 자체 데이터 저장소는 이 단계에서 별도 free하지 않는다.

### 길이 0이어도 원본에는 포인터 읽기가 있다

standalone body의 0x147158, clean의 0x1472d8, partial prefix의 0x147430은 먼저 `MOV EAX,[cursor]`를 실행하고 그 뒤 length==0을 검사한다. partial 마지막 항목도 0x14751c에서 pointer를 읽고 0x14751e에서 length를 검사한다. Ghidra C는 non-port/zero-length 경로에서 이 읽기가 없는 형태로 표현한다. 따라서 “length가 0이면 OOL 슬롯을 읽지 않는다”는 결론은 원본과 다르다.

이 함수들은 descriptor 시작 주소가 end 미만인지만 확인하며, descriptor 전체·OOL pointer 슬롯·전체 payload가 유효하게 들어 있는지를 매번 확인하지 않는다. inline port clip도 DWORD 주소 계산의 wraparound, descriptor 자체의 유효성, OOL 저장소 크기까지 보장하는 일반 bounds checker가 아니다. 안전성은 선행 acquisition/validation과 자료 구조 불변식까지 확인해야 한다. 이번 정적 차이를 외부 입력으로 도달 가능한 취약점이나 exploitability 판정으로 확대하지 않는다.

## ipc_kmsg_clean: request → header → complex body

0x1471a8에서 header bits(kmsg+0x14)를 먼저 저장한다. marequest(kmsg+0xc)가 있으면 0x1471b3에서 marequest_destroy를 호출한다. 이후 remote(+0x1c), local(+0x20)을 각각 현재 메모리에서 읽고 유효값이면 object_destroy를 호출한다. disposition은 저장한 bits의 low byte와 다음 byte다. callback 뒤 header bits를 다시 읽는 방식이 아니다.

저장한 bits의 sign bit가 켜져 있으면 body를 정리한다. body 시작은 kmsg+0x2c, 끝은 kmsg+0x14+msgh_size(+0x18)로 계산한다. 원본은 complex 여부 외에 Darwin의 OLD_FORMAT 분기를 두지 않고 항상 위의 typed descriptor 로직을 사용한다.

이 함수는 marequest·remote·local·body slots를 0으로 지우지 않고, kmsg 버퍼 자체도 free하지 않는다. 따라서 반복 호출이 안전한 idempotent cleanup이라고 간주할 수 없다. marequest_destroy의 알림과 권한 정리가 다시 메시지 파괴를 일으킬 수 있으며, 이를 직렬화하는 thread별 지연 큐는 [보고서 66](../continuous-review-20260912-66/README.md)의 kmsg_destroy 경로와 연결된다. 그 큐 구조가 cleanup 대상의 임의 중복 삽입을 허용한다는 뜻은 아니다.

## ipc_kmsg_clean_partial: ABI와 마지막 항목

실제 ABI는 `(kmsg, end_descriptor_address, do_last, processed_count)`다. 첫 단계에서 remote를 object_destroy로 **무조건** 전달한다(0x147337). 일반 clean과 달리 0/-1 검사를 하지 않는다. local은 검사한다. marequest를 읽거나 destroy하지 않으며 참고 compat 소스의 marequest==NULL 조건도 원본 assert로 확인하지 않는다. header COMPLEX bit 검사 없이 kmsg+0x2c부터 end_address 전까지 공통 body cleanup을 실행한다.

do_last가 0이면 여기서 끝난다. 비영이면 원래 end_address에서 마지막 descriptor를 별도로 해독한다. prefix 순회의 cursor와 독립된 주소다. 마지막 항목이 port이면 **processed_count 인자만큼** 원소를 순회하며 0/-1을 건너뛴다. 이 수를 descriptor count나 메시지 끝에 맞춰 다시 제한하지 않는다.

마지막 항목이 OOL이고 length가 비영이면 port/non-port 구분에 따라 kfree 또는 vm_deallocate를 한다. length는 processed_count가 아니라 descriptor의 원래 count와 size로 계산한다. 예를 들어 원래 count=3, size=32, 이미 처리한 prefix=1이면 권한 검사 대상은 첫 slot에 해당하는 4바이트지만 OOL 해제 크기는 전체 12바이트다. prefix 원소 중 NULL/dead가 있었다면 실제 object_destroy 호출 수는 processed_count보다 작을 수 있다.

이 차이는 실패 원소와 아직 변환하지 않은 후속 이름을 object pointer로 잘못 파괴하지 않으면서, 이미 할당한 전체 OOL 저장소를 반납하는 데 중요하다. processed_count의 정확성과 전체 allocation ownership은 caller 조건이다.

### 선택 copyin caller의 원본 근거

0x1482cd부터의 window에서 copyin_type 호출 후 descriptor type을 변환한 값으로 덮어쓰고, local index `[EBP-0x40]`를 0으로 만든다. object_copyin 실패 분기 0x148332는 0x148078로 간다. 그 위치는 index, 1, 현재 descriptor 주소, kmsg 순서로 push하여 clean_partial(kmsg,descriptor,1,index)를 호출한다.

성공한 변환은 0x14835f에서 slot에 저장되고, NULL/dead를 건너뛴 경우도 0x148364에서 index를 증가시킨다. 실패 원소는 index 증가 전에 빠져나간다. 따라서 이 인자는 “reference를 실제 증가시킨 개수”가 아니라 **앞에서 처리한 slot prefix 길이**다. clean_partial이 그 prefix 내부에서 다시 0/-1을 건너뛰는 이유와 맞는다.

이 window는 부분 정리의 ABI와 index 연결을 뒷받침한다. 전체 copyin 입구·모든 failure 경로·다른 caller의 개수 제한·allocation provenance를 이번에 새로 완결한 것은 아니다.

## Port classifier와 object_destroy dispatch는 같은 범위가 아니다

cleanup의 port classifier는 0x10~0x15를 포괄하지만 object_destroy는 다음 경우만 처리한다.

| type | 직접 처리 |
|---|---|
| 0x10 | release_receive(object) |
| 0x11 | release_send(object) |
| 0x12 | notify_send_once(object) |
| 그 외 | 직접 동작 없이 반환 |

즉 send-once는 여기서 release_sonce를 직접 호출하는 것이 아니라 알림을 통해 소비한다. 다른 port-class type이 들어와도 object_destroy가 자동 변환하거나 panic하지 않는다. copyin caller의 type rewrite는 이 계약에 중요한 연결점이지만 모든 생성자의 정상화를 검증한 것은 아니다.

## ipc_kmsg_free: 모든 비양수 값이 같은 처리가 아니다

원본은 kmsg+8의 DWORD를 비교하여 -2이면 KernDeviceInterruptMsgRelease, -3이면 netipc_msg_release를 호출한다. -1이면 직접 동작 없이 반환한다. 그 외 값은 0과 다른 음수 표현을 포함해 kfree(kmsg,size)로 넘긴다. 이 dispatch 관찰은 그런 나머지 값이 유효한 allocation size라는 보장이 아니다.

참고 헤더의 IKM_SIZE_NETWORK=-1, DEVICE=-2, NETIPC=-3과 맞지만 NORMA=0 주석만 보고 원본에 별도 NORMA 해제가 있다고 덧붙이면 안 된다. kmsg_destroy의 signed size>0 빠른 kfree 경로와 나머지 ipc_kmsg_free 호출은 보고서 66과 이어진다. 특수 release의 buffer 재사용·소유자 복귀·queue locking은 아직 직접 호출 대상까지 검증하지 않았다.

## 참고 소스와 완료 경계

Darwin의 `ipc_kmsg_clean_body(kmsg, number)`는 후대 descriptor 형식을 사용한다. 원본의 대응 비교 대상은 이름이 아니라 `(saddr,eaddr)`를 받는 `ipc_kmsg_clean_body_compat`다. partial도 Darwin의 `(kmsg,number,paddr,length)`가 아니라 `clean_partial_compat(kmsg,eaddr,dolast,number)`와 비교해야 한다. 원본은 non-port OOL에 vm_deallocate(ipc_soft_map,...)를 사용하므로 vm_map_copy_discard를 사용하는 후대 compile branch를 임의 채택할 수 없다.

이번에 확인한 것은 선택된 전체 본문의 제어 흐름·ABI·메모리 읽기 순서·정리 호출과 bounded caller 연결이다. 실제 모든 입력의 범위·reference ownership, VM deallocation 성공, native 경합, DriverKit/network release 및 GCC 2.7 복원 구현의 정확성은 아직 아니다. [남은 작업](OPEN_ITEMS.md)을 계속 추적한다.
