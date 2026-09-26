# kernserv 관리 요청 dispatch와 MIG stub 정적 검토

## 판정과 증거

report53의 함수 포인터는 서버별 handler 테이블로 복사되어 실제 관리 요청에 사용된다. `load_objc`의 메시지 형식 검사는 존재하지만, 주소가 가리키는 Mach-O 이미지의 유효성 검사는 이 stub에 없다. 메시지 형식 검사와 모듈 검증을 구분해야 한다.

[범위](SCOPE.md), [바이트·테이블·계산 증거](dispatch-evidence.json), [이전 파일 보존](preservation.json), [남은 분석](OPEN_ITEMS.md)을 보존한다. Ghidra 스킬의 함수·참조·타입 교차 확인을 보존 export에 적용했고, 원본 DB/export/참조 소스/복원 커널은 수정하지 않았다.

Python으로 본문 4개, 명령 236개, 703바이트를 원본과 대조했다. 별도 main 호출 창 4개에는 명령 111개가 있다. 전체 main 의미 검증으로 집계하지 않는다. 입력 23개를 지문 기록하고 이전 파일 636개를 재해시했다. Ghidra 자료는 full-analysis manifest에 대조했다. 원본 LC_SEGMENT를 직접 파싱한 파일 위치와 기존 디코더의 명령 바이트가 일치한다. 독립 계획 검토나 동적 실행을 대체하는 검증은 아니다.

## 원형 테이블 → 서버별 테이블 → stub

`_kern_serv_proto`는 `0x001d1284`에서 시작한다. Python 계산으로 15 DWORD, 60바이트이며 처음은 arg=0, 다음은 wait=0이다. 나머지 함수 포인터는 보존 Darwin `kernserv/kern_server.c`의 initializer 순서와 대응된다.

| 요청 | 원형 callback 슬롯 | 실제 callback | 관리 메시지 ID | MIG stub |
|---|---|---|---|---|
| shutdown | `+0x24` (`0x001d12a8`) | `0x0016cc88` | 107 | `0x0016da3c` |
| load_objc | `+0x38` (`0x001d12bc`) | `0x0016c96c` | 112 | `0x0016dc38` |

`_kern_server_main`은 `0x0016c1ec`의 REP MOVSD로 원형을 스택 `EBP-0x3c`에 복사한다. `0x0016c1f1`은 첫 arg에 `EBP-0x40`, 즉 kalloc 결과를 담은 서버 포인터 변수의 주소를 저장한다. callback은 그 주소를 역참조하여 서버 구조체를 얻는다. 스택의 포인터 변수, 서버 구조체, 모듈 header는 서로 다른 대상이다.

부팅 listener 획득 창에서는 `thread_self()` 결과를 기다리기 전에 이미 special-port 번호와 출력 포인터가 push되어 있다. `0x0016c2c3`의 실제 호출 인자는 `(thread_self 결과, 2, &boot_listener)`이다. Ghidra C의 `_thread_self(2,&local_48)` 및 한 인자 `_thread_get_special_port_EXTERNAL(...)` 표현을 실제 선언으로 채택하면 안 된다. main의 다른 유사 호출도 전부 완료했다고 주장하지 않는다.

## 관리 handler 진입 조건

`0x0016c727`에서 일반 port dispatch를 먼저 호출한다. 반환값이 `MIG_BAD_ID`이고, 그때 메시지의 local port가 main에 보관된 boot listener 값과 같을 때만 `0x0016c74b`에서 `kern_serv_handler(message, &table)`을 호출한다. 이후 handler 반환값 검사 없이 서비스 반복으로 돌아간다.

이 비교는 이 호출자의 라우팅 조건이다. sender 인증, port right 생성·이전, 수신 커널의 권한 검증 전체가 입증된 것은 아니다. 특히 일반 dispatch는 PP_server 경로에서 메시지 local port를 uarg로 바꾸므로, main의 두 번째 비교가 항상 최초 수신 포트 값을 사용한다고 일반화하면 안 된다.

## `kern_serv_handler` (`0x0016d650`)

먼저 스택 reply를 구성한다. simple=1, 크기=32, type은 요청에서 복사, local port=0, remote port는 요청 remote port, ID는 요청 ID+100, RetCodeType=`0x10012002`, 초기 RetCode=`MIG_BAD_ID`이다. 헤더의 unused 부분을 명시적으로 초기화하는 명령은 이 본문에 없지만, 이것만으로 실제 전송 결과나 정보 노출을 판정하지 않는다.

`(msg_id - 100)`의 unsigned 결과가 `0xc` 이하인지 검사한다. 따라서 선택 범위는 100부터 112이며 테이블은 13개 슬롯이다. 인덱스식 `0x001d1180 + msg_id*4`의 실제 첫 슬롯은 Python 계산으로 `0x001d1310`이다. `0x001d1180`부터 무조건 테이블 데이터라고 오해하지 않는다. 범위 밖 또는 NULL stub이면 `MIG_BAD_ID`를 직접 반환하고 reply를 보내지 않는다.

선택된 stub에는 `(request, reply, table)`을 전달한다. reply RetCode가 `MIG_NO_REPLY`이면 handler는 0을 반환한다. 그 외에는 `msg_send`의 결과를 반환하므로 **handler 반환값은 callback의 업무 결과와 같지 않다**. 업무 결과는 reply의 RetCode에 있다.

전송 옵션은 `(~wait_u32) >> 31`, timeout 인자는 wait 값 그대로다. 원형의 wait=0이면 옵션은 `SEND_TIMEOUT`, timeout은 0이다. SDK defs의 `waittime 10000`을 이 서버 reply의 wait 값으로 대입하면 안 된다. 실제 전송·스케줄링 효과는 msg_send 하위 분석이 필요하다.

handler는 ID나 헤더 필드를 읽기 전에 전체 버퍼 범위를 별도로 검증하지 않는다. 이는 수신 경로의 최소 헤더 보장 검증을 생략해도 된다는 뜻이 아니다.

## shutdown stub (`0x0016da3c`)

- 요청 `msg_size == 24`, `msg_simple == 1`을 요구한다. 실패하면 reply RetCode=`MIG_BAD_ARGUMENTS`.
- table `+0x24`의 callback이 NULL이면 `MIG_BAD_ID`.
- callback이 있으면 `callback(table.arg)`를 호출한다.
- callback이 제어를 반환한 경우 그 반환값과 무관하게 reply RetCode를 `MIG_NO_REPLY`로 설정한다.

SDK의 `simpleroutine shutdown`과 대응된다. 그러나 원형 callback은 report53에서 확인한 비복귀 shutdown 경로이므로 정상 설정에서 stub의 호출 이후까지 실행된다고 보장할 수 없다. 형식 오류나 NULL callback 분기는 `MIG_NO_REPLY`로 덮어쓰지 않으므로, simpleroutine이라는 이유만으로 모든 분기에서 reply가 없다고 할 수 없다.

## load_objc stub (`0x0016dc38`)

- 요청 `msg_size == 32`, `msg_simple == 1`을 요구한다.
- 요청 `+0x18`의 DWORD가 `0x001d1308`에서 읽은 `0x10012002`와 정확히 같아야 한다. 해당 값은 Python 비트 분해에서 name=2, size=32, number=1, inline=1, longform/deallocate/unused=0이다. old IPC의 단일 inline INTEGER_32 descriptor와 대응한다.
- 형식 오류는 `MIG_BAD_ARGUMENTS`, table `+0x38`의 NULL callback은 `MIG_BAD_ID`를 reply에 쓴다.
- callback이 있으면 `callback(table.arg, request[+0x1c])`를 호출하고 EAX를 reply RetCode로 보존한다. 성공 시 reply simple와 크기를 재설정한다.

이 본문은 header 값의 NULL, Mach-O magic, mapped extent, relocation 또는 내용의 일관성을 검사하지 않는다. 정수 값을 report53의 `kern_serv_load_objc`에 그대로 전달한다. 그 callback이 돌아오는 경우 항상 0을 반환하므로 모듈 등록 결과가 여기까지 복구되어 전달되는 것은 아니다. sender가 임의 주소를 실제로 전달할 수 있다는 보안 판정에는 port/loader 경로의 추가 증거가 필요하다.

## 일반 dispatch (`0x0016c758`)의 주의점

`0x0016c764`에서 서버 `+0x4b4`의 last_rec_index를 읽은 **뒤** `0x0016c771`에서 서버 NULL 여부를 검사한다. Ghidra C에서는 먼저 NULL을 검사하는 모양이므로 원본의 메모리 접근 순서가 숨겨진다. Darwin 소스의 `int i = ksp->last_rec_index;`도 NULL 검사보다 앞에 있다. 실제 NULL 호출 또는 fault 관찰을 주장하는 것은 아니다.

last_unrec_port에 해당하면 `MIG_BAD_ID`; last_rec_port이면 cached index로 곧바로 항목을 선택한다. 그 외에는 50개 port mapping을 검색하고 발견 시 cache를 갱신한다. cache index 범위와 proc non-NULL을 보장하는 것은 이 본문 밖의 불변식이다.

PP_handler는 `(request, uarg)`를 호출하고 반환값을 사용한다. PP_server는 8192바이트 reply를 할당하고 request의 local port를 uarg로 변경한 뒤 `(request, reply)`를 호출한다. callback의 EAX 대신 reply RetCode를 확인한다. `MIG_NO_REPLY`이면 0, 그 외에는 msg_send 결과를 사용하고 reply를 해제한다. local port를 원래대로 복구하는 명령은 이 본문에 없다. Darwin 참조에도 이전 값을 local 변수에 저장하지만 복구하는 대입은 없다.

최종 결과가 `RCV_IN_PROGRESS`(-200)이면 그때 request local port를 last_unrec_port로 저장하고 `MIG_BAD_ID`로 변환한다. 이 동작은 미발견 경로뿐 아니라 callback이 같은 sentinel을 반환하는 경우에도 조건상 적용된다. allocator 실패, callback의 request 수정, cache 무효화 및 재진입의 실제 효과는 미완료다.

## 수신 창에서 남는 경계

main은 초기에 48바이트 메시지 버퍼를 할당한다. 수신 시 보관된 port_set과 버퍼 크기를 헤더에 쓰고 `RCV_TIMEOUT|RCV_INTERRUPT|RCV_LARGE`, timeout=1000으로 msg_receive를 호출한다. `RCV_TOO_LARGE`면 메시지에 보고된 새 크기를 저장하고 기존 버퍼를 해제·재할당한 뒤 다시 수신한다.

`RCV_TIMED_OUT`는 바깥 서비스 반복으로 돌아가지만 `RCV_INTERRUPTED`는 성공 반환과 같은 dispatch 전 처리 위치로 간다. 따라서 주석의 '다시 수신' 설명만으로 원본이 즉시 재수신한다고 판단하면 안 된다. 인터럽트 반환 시 헤더 내용이 무엇인지와 msg_receive의 책임은 추가 분석이 필요하다.

이 단계는 main의 notification queue 수명, 모든 port mapping 변경자, msg_receive/send의 내부 계약 또는 모듈 이미지의 매핑·해제를 완료하지 않았다. 공개 소스 대응은 원본 소스 동일성이나 GCC 2.7 실컴파일 증명이 아니다.
