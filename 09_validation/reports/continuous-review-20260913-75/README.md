# 75차 — 원본 부팅의 페이지 크기·예약 메모리·clearing

## 결과와 한계

74차의 초기 상태 질문을 원본 호출 경로로 좁혔다. `_i386_init`은 page_size에 0x2000을
기록하며, `_vm_page_startup`은 당시 page_size의 8배로 zdata_size를 덮어쓴 뒤 영역 확보와
clearing을 수행한다. `_vm_mem_init`에서 이 호출은 zone bootstrap보다 앞선다.
정상 호출·메모리 접근과 값 유지라는 전제하에서는 8192-byte 페이지, mask 8191,
shift 13, zdata 예약 65536바이트로 연결된다. 실제 CPU 부팅에 성공했다는 판정은 아니다.

원본만 사용했다. 다른 프로젝트 소스·복원 코드·외부 구조체 정의는 참고하지 않았다.
Ghidra 스킬로 보존 본문과 디컴파일을 대조했고, 원본·DB·이전 export는 수정하지 않았다.
모든 매핑·주소·개수·비트·해시·산술은 Python으로 계산했다. 구현·빌드·포팅·동적 실행은 없다.

근거: [범위](SCOPE.md), [명령·표·심볼·산술](boot-reserve-evidence.json),
[보존 해시](preservation.json), [남은 경계](OPEN_ITEMS.md).

## 검증 범위

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`다.
Python으로 Mach-O file-backed mapping과 nlist를 읽고 Capstone 4.0.2 x86 32-bit로
재디코딩했다. 보존된 inclusive body range와 실제 명령 바이트 합집합을 대조했다.

| entry | 원본 심볼 또는 분석용 이름 | 본문 바이트 | 명령 |
|---|---|---:|---:|
| 0x1860dc | `_start` | 89 | 23 |
| 0x18aafc | `_i386_init` | 209 | 46 |
| 0x15c828 | `_setup_main` | 285 | 63 |
| 0x173a68 | `_vm_mem_init` | 107 | 28 |
| 0x17a9b4 | `_vm_set_page_size` | 83 | 26 |
| 0x17aa08 | `_vm_page_startup` | 1024 | 286 |
| 0x178964 | `_vm_alloc_from_regions` | 105 | 42 |
| 0x101600 | `_bzero` | 22 | 11 |
| 0x101630 | `_memset` | 367 | 127 |
| 0x16af6c | descriptor selector helper（원본 nlist 이름 없음） | 88 | 39 |

10개 본문, 691개 명령, 2379바이트다. 직접 분기 60개에는 far jump 2개가 포함된다.
CALL은 67개, 간접 jump는 3개다. 간접 jump table 3개의 91개 word를 원본에서 읽고,
지역적 입력 범위상 도달 가능한 46개 entry가 선택된 memset 본문의 명령 시작점을
가리키는지 확인했다. 표의 모든 entry가 도달 가능한 것은 아니다.

Ghidra의 실제 `/* WARNING:` 주석은 6개다. 함수가 호출하는 printf 문자열에 포함된
`WARNING`은 디컴파일러 경고와 구분했다. 이 범위에서 앞선 보고서와 같은 register-only
spin 패턴은 발견하지 않았지만, 모든 형태의 대기나 하위 함수 대기가 없다는 뜻은 아니다.
현재 입력 36개, 이전 보존·보고서 파일 741개와 직전 입력 27개를 재검증했다.
선택된 본문의 재디코딩 성공을 모든 하위 callee 의미의 검증으로 확대하지 않는다.

## 1. 부팅 호출 순서 — 명령으로 확인한 연결

| 위치 | 관찰한 순서 | 아직 필요한 전제 |
|---|---|---|
| `_start` | GDT/IDT 초기화 CALL → far jump → `_i386_init` → far jump → `_startup_early` → `_setup_main` | descriptor·분절 상태, 하위 CALL의 정상 복귀 |
| `_i386_init` | page_size=0x2000 → `_vm_set_page_size` → 인자/메모리 설정 → region 설정 → pmap bootstrap | 인자 처리·메모리 지도·pmap의 실제 변경 |
| `_setup_main` | clock timer, runqueue, scheduler 초기화 → `_vm_mem_init` | 앞선 callee가 page 설정을 바꾸지 않는지 |
| `_vm_mem_init` | page startup → zone bootstrap → object init → map init → kmem init → pmap init → zone init → kalloc init | 각 하위 동작·전역 값의 수명 |

직접적인 핵심 주소는 `_start`의 0x18610b/0x186129,
`_setup_main`의 0x15c83a, `_vm_mem_init`의 0x173a7e/0x173a88/0x173abb/0x173ac0다.
`_vm_page_startup`에는 mem_region, num_regions, virtual_avail을 인자로 넘기며,
돌아온 EAX를 virtual_avail에 쓴다. startup 자체의 마지막 EAX는 **입력 세 번째 word**다
(0x17adfd). 이 반환을 “계산된 새로운 끝 주소”로 가정하지 않는다.

`_start`의 원본에는 CLD, segment register 설정, selector 0x48의 far jump와
selector 0x8의 far jump가 있다. 이를 생략한 C 호출 목록은 부팅 환경을 완전히 표현하지
못한다. 마지막 CALL 뒤는 0x186134의 HLT이며, 무조건 자기 자신으로 점프하는 명령이
아니다. Ghidra의 무한 do-loop 표현을 실제 interrupt/wakeup 동작의 근거로 삼지 않는다.
이번 검증은 far offset과 selector bytes를 확인했을 뿐 descriptor 내용·권한·native 전환을
검증한 것이 아니다.

`_setup_main`의 나머지 직접 CALL과 store도 보존했지만 task/thread/IPC 초기화가 전부
성공한다는 결론은 내리지 않는다. 마지막에는 first_thread global word를 EAX로 반환하며,
디컴파일의 `thread_act_t` 타입은 여기서 독립적으로 확정하지 않았다.

## 2. 페이지 크기와 region 초기 입력

`_i386_init`의 0x18ab2b는 page_size에 0x2000을 직접 쓴다. 이어지는 0x18ab35가
`_vm_set_page_size`다. 이 함수는 page_mask를 먼저 `page_size - 1`로 기록하고
`page_size & page_mask`가 nonzero이면 panic CALL(0x17a9ce)에 들어간다.
0이면 shift를 0으로 만들고, `1 << (shift의 하위 5비트)`가 page_size와 같아질 때까지
shift를 증가시킨다. 정상 0x2000 입력의 mask=8191, shift=13은 Python으로 계산했다.

page_size=0을 명시적으로 거부하는 검사는 없다. 0도 앞의 비트 검사를 통과하지만
DWORD shift의 가능한 결과 중 0은 없으므로, 값이 유지되면 shift 검색은 종료하지 않는다.
이것은 그 입력에서의 정적 관찰이지 실제 초기화가 0으로 진입했다는 주장이나 외부에서
그 값을 넣을 수 있다는 주장이 아니다. page_size=1은 shift=0 경로다.
panic 이후의 실제 비복귀 계약도 callee 검증과 구분한다.

`_i386_init`은 num_regions=1을 쓰고 첫 region의 +0x10 및 +0x14에 global 0x1e7604를,
+0x18에 global 0x1e7608을 복사한 뒤 pmap bootstrap을 호출한다. 그 뒤 마지막에는
`round_page(0x1000)`만큼 region+0x18을 감소시켜 같은 값을 pmsgbuf에 기록한다.
page 설정이 유지되는 조건에서는 이 예약은 8192바이트다. 메모리 상하한을 만드는
0x18acf8과 pmap bootstrap 내부를 여기서 완료 처리하지 않으므로 실제 숫자 주소와
전체 사용 가능 용량은 아직 확정하지 않는다.

전체 보존 asm의 직접 MOV 검색에서 page_size store와 mask/shift 설정 위치를 찾았지만,
주소가 레지스터·별칭·테이블로 전달되는 모든 간접 writer를 배제한 결과는 아니다.
따라서 “언제나 8192이고 변경 불가능”이라고 일반화하지 않는다.

## 3. 초기 region 할당의 실제 반환 계약

`_vm_alloc_from_regions(size, alignment)`는 global mem_region 배열을 앞에서부터
검색한다. 원본 LEA 조합과 반복 증가량은 record stride 28바이트를 나타낸다.
각 record의 +0x14를 다음 할당 위치, +0x18을 상한으로 사용한다.

계산은 DWORD 폭으로 `aligned = (cursor - 1 + alignment) & -alignment`,
`end = aligned + size`다. 상한과 end를 unsigned 비교하여 들어맞는 첫 region이면
+0x14에 end를 기록한다(0x1789aa). 반환 EAX는 end가 아니라 **aligned**다.
0x1789ac 이후 epilogue는 이 EAX를 변경하지 않는다. Ghidra의 `void` 선언과 bare return은
원본의 주소 반환을 누락하므로 채택하지 않는다. 실제 caller도 이 EAX를 zdata 등에 쓴다.

맞는 region이 없으면 원본 문자열 `vm_mem_alloc_from_regions`를 넘겨 panic을 호출한다.
별도의 실패 상태나 NULL을 설정해서 복귀하는 분기는 없다. 그렇다고 모든 입력에서
반환 주소가 nonzero라고 단정하지는 않는다. region 시작값과 정렬 조건도 필요하다.

함수 자체에는 lock, zero-fill, size 덧셈 overflow, alignment=0 또는 2의 거듭제곱 여부,
region 배열의 저장 용량을 검사하는 코드가 없다. cursor가 정렬되며 생긴 앞쪽 공백도
다시 목록에 넣지 않는다. 이런 전제는 부팅 caller·메모리 지도에서 검증해야 한다.
예시 DWORD wrap와 정렬 결과는 evidence에 별도 산술로 남겼으며 실행 실험은 아니다.

## 4. vm_page_startup의 단계와 zdata 초기값

`_vm_page_startup(regions, count, return_word)`은 먼저 여러 초기 word/byte와 queue를
기록한다. free/active/inactive head는 자신을 가리키도록 설정하고 lock word를 0으로
만든다. 0x1f745e·0x1f7461 등의 일부 byte는 기존 상위 비트를 보존하며 중간 store를
거친다. 따라서 해당 전역 객체 전체를 일괄 0으로 초기화한다고 말할 수 없다.
Ghidra가 합친 최종 비트식과 실제 중간 메모리 쓰기 순서를 구분했다.

처리 순서는 다음과 같다.

1. 전달 region들의 +0x14를 page-round하고 +0x18을 page-truncate하여 그 차이를
   DWORD로 합한다. 총합을 page_shift로 줄인 값이 bucket 자동 설정의 입력이다.
   bucket_count가 0일 때만 1에서 시작해 충분해질 때까지 두 배로 늘린다.
   기존 값이 nonzero이면 그대로 사용하며 `count & (count-1)`가 nonzero이면
   경고 printf를 호출하고 계속한다. 파일의 bucket_count는 0이지만 실제 진입값은
   별도 조건이다. 범위 역전·합계 overflow를 명시적으로 거부하는 코드는 없다.
2. bucket_count×8바이트를 alignment 4로 확보하고 bzero를 호출한다. 이어 각 bucket의
   word를 다시 0으로 쓰는 반복도 원본에 있다. hash_mask는 bucket_count-1이다.
3. **현재 page_size×8을 zdata_size에 기록**(0x17abf5)한다. 이를 size로, page_size를
   alignment로 region allocator에 전달(0x17abfd)하고 EAX를 zdata에 기록(0x17ac02),
   bzero를 호출한다(0x17ac0f). 파일 초기 zdata_size=430080은 이 경로의 예약 크기가 아니다.
   page_size=8192 유지 조건에서 예약은 65536바이트다. allocator failure/panic 시
   이미 바뀐 크기 등을 rollback하는 transaction은 없다.
4. map_data는 800바이트, kentry_data는 90112바이트를 각각 alignment 4로 확보·clear한다.
5. 각 전달 region의 당시 남은 정렬 범위에 대해 페이지 수×48바이트의 record 배열을
   region allocator에서 확보하고 region+0에 포인터를 쓴다. **이 allocator는 global
   region의 cursor를 바꾸므로** 뒤의 bzero 크기는 확보 전 계산값을 단순 재사용하지 않고
   갱신된 region cursor로 다시 계산한다(0x17acc3 이후). 같은 배열을 인자로 받은 정상
   caller에서는 할당 전 용량·clear 용량·최종 사용 페이지 수가 동일하다고 가정하면 안 된다.
6. free_count를 0으로 만들고, 각 region의 +0x14/+0x18을 실제로 round/truncate하여
   저장한다. +4/+8에는 shift한 하한/상한, +0xc에는 그 차이를 쓰고 전역 free_count에
   더한다. +0의 record 배열을 stride 48로 순회하며 +0x24에 증가하는 region 페이지
   주소를 쓰고, +0/+4의 free-queue 링크를 연결한 뒤 +0x1e byte에 0x8을 OR한다.
   외부 page 구조체의 필드 이름·bit 정의를 가져오지 않았다.
7. 마지막에 vm_pages_needed_lock을 0으로 쓰고 세 번째 입력 word를 EAX로 반환한다.

정상적인 원래 메모리 지도, 양의 페이지 크기, 올바른 정렬, 충분한 공간과 유효한 mapping이
필요하다. 이 본문에는 각 확보 결과를 NULL 검사하는 코드가 없으며, 실패해도 초기 상태를
되돌려 재시작할 수 있다는 보장을 하지 않는다. region count×stride의 pointer 범위와
페이지 수 연산도 DWORD이므로 임의 입력을 안전하게 처리하는 일반 API로 확대하지 않는다.

## 5. bzero와 memset의 원본 clearing 경로

`_bzero`는 `(destination, 0, supplied_size)`를 `_memset`으로 전달한다(0x10160d).
memset은 원래 destination을 local에 보존하고 마지막 EAX로 반환한다.
아래 표는 원본 table와 그 앞의 연산을 함께 대조한 결과다.

| table 주소 | 읽은 word 수 | 이 진입 경로에서 가능한 index | 해석 |
|---|---:|---|---|
| 0x101670 | 31 | 0..30 | size 1..31의 byte/word/dword store 조합 |
| 0x1017c0 | 31 | 0..6 | 긴 경로의 8바이트 정렬 전 prefix |
| 0x101900 | 29 | 0, 4, 8, 12, 16, 20, 24, 28 | `remaining & 0x1c`에 따른 큰 블록 진입 |

두 번째 표의 나머지 항목 중에는 현재 선택 본문 밖을 가리키는 것도 있다. 하지만 앞에서
prefix=`8-(destination&7)`로 제한하므로 이 진입점의 정상 연산에서는 그 항목을 고르지
않는다. 이를 이번 경로의 누락된 실행 명령이라고 세지 않았다. 다른 진입/fragment의
전체 분류는 별도 분석 항목으로 남긴다.

짧은 경로는 size-1의 unsigned 범위 검사로 0 및 범위 밖 값을 건너뛴다. 긴 경로 선택의
CMP/JG는 signed 비교이므로 상위 비트가 켜진 size도 일반적인 큰 unsigned 길이처럼
처리한다고 가정할 수 없다. 검증한 zdata 크기는 그 범위에 해당하지 않는다.

긴 경로는 필요 시 prefix를 쓴 뒤 정렬된 부분을 32바이트 단위로 처리하고 마지막 작은
나머지를 쓴다. page-aligned destination과 size=65536, fill=0의 조건에서는 진입 시
mask 나머지가 0이고, 표는 먼저 주소/남은 길이를 조정하는 0x10198b로 간다. 이후
0x101974부터의 DWORD store 묶음이 채우는 길이는 Python 산술로 2048×32=65536이다.
메모리 접근이 정상이라면 지정 영역 clearing으로 연결된다. 이는 실제 메모리 dump나
fault-free 실행 증거가 아니며, 동적 emulator를 돌린 결과도 아니다.

일반 fill 인자의 경우 원본은 먼저 하위 byte로 자르지 않고 전체 word의 shift/OR로
DWORD 패턴을 만든다. Python 예시에서 fill=0x100이면 패턴 bytes는 `00 01 01 01`이다.
따라서 모든 int 값에 대해 표준적인 byte-replication 동작이라고 일반화하지 않는다.
이번 bzero 경로의 fill=0에서는 이 차이가 없으며 패턴은 모든 byte가 0이다.
memset 자체에는 주소 유효성 검사나 fault 복구 wrapper가 없다.

## 6. zone descriptor의 미기록 필드에 대한 조건부 연결

selector helper(0x16af6c)를 원본으로 재검토했다. zone+0x14가 nonzero이면 종료하며,
count와 1을 signed 비교하여 count<=1이면 +0x3c에 쓰지 않고 종료한다. 후보가 있을 때는
크기를 정렬해 기준에 맞는 첫 descriptor를 선택하고 그때만 +0x1c/+0x3c를 기록한다.

74차의 zone bootstrap에서 count=1 상태로 이 selector가 호출되는 경로는 따라서
zone의 +0x3c를 초기화하지 않는다. 이번에 확보한 startup의 reserve clearing 근거와
연결하면, **default free list가 처음 비어 있고, 첫 zone 저장소가 그 clear된 reserve에서
나오며, 중간에 해당 byte를 덮어쓰지 않는다면** +0x3c는 0으로 남는다.
이는 0x44 요청이 정렬된 0x50 영역 안에 +0x3c word를 포함한다는 Python 계산과 맞는다.

그러나 default descriptor의 `__common` 영역이 실제로 언제 초기화되는지, 초기 진입
이전 코드·loader가 어떤 값을 제공하는지는 아직 닫히지 않았다. 그러므로 이 조건부
연결을 실제 첫 부팅의 무조건 보장 또는 모든 zone 할당의 zero-fill 보장으로 바꾸지 않는다.

## 다음 경계

이번 결과로 페이지 크기와 zdata 예약을 만드는 직접 경로, clearing 호출의 실제 동작,
zone 이전의 순서는 확인했다. 원본 loader·메모리 지도·pmap 변경과 초기값 유지,
free-space reclaim/GC·주소 재사용, VM/page/대기 계약은 남아 있다.
[후속 목록](OPEN_ITEMS.md)의 원본 분석을 계속하며, 전체 목표는 미완료로 유지한다.
