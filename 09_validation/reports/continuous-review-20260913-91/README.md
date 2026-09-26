# 91차 — raw I/O 벡터 호출자·완료 대기·VM 접근 검사

OPENSTEP 원본에서 raw I/O 상위 호출자를 연결했다. **여러 벡터가 단일 벡터로 바뀐다는
보장은 선택한 경로에 없다.** 90차 정렬 임시 버퍼의 전제를 닫지 못하는 구체적인 근거다.
실제 file/vnode/controller의 runtime 연결, native fault와 수명은 여전히 별도 확인이 필요하다.
다른 소스는 참고하지 않았고 구현·복원·빌드·동적 실행도 하지 않았다.

## 근거와 검증

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
일반 본문 14개와 synthetic fragment 1개, 명령어 883개/2,408바이트를 원본에서 decode했다.
직접 분기 115개, 직접 호출 35개, 간접 호출 4개, 중요 operand 152개를 대조했다.
명시적 Ghidra WARNING 주석 1개를 보존했으며, 경고 수가 C 표현의 정확도를 보증하지는 않는다.
원본 cdev 초기 표 43행, 포인터 window 2개/7항목, 관련 참조 47행을 확인했다.

[원본 기계 판독 근거](object-lifetime-evidence.json), [체크포인트](checkpoint.json),
[보존 해시](preservation.json), [검토 범위](SCOPE.md), [남은 분석](OPEN_ITEMS.md),
[90차 연결 근거](../continuous-review-20260913-90/README.md)를 함께 보존한다.
주소·개수·크기·비트·해시는 Python으로만 계산했다.

## 1. read/write와 readv/writev는 같은 벡터 조건이 아니다

원본 `_read`/`_write` (`0x10cd54/0x10ce00`)는 전역 `0x1e875c`가 가리키는 실행 문맥의
`+0x24`에서 인자 블록을 읽는다. 인자 블록 `+4/+8`을 스택의 base/length로 복사하고
uio vector count를 1로 설정해 `_rwuio`에 각각 방향 0/1을 넘긴다.
export의 일반 libc형 함수 signature와 달리 이 본문은 표기된 C 인자를 스택에서 읽지 않는다.

`_readv`/`_writev` (`0x10cd8c/0x10ce38`)는 인자 블록의 count를 unsigned로 검사한다.
0–16을 허용하고 그 밖에는 문맥 error BYTE `+0x68`에 `0x16`을 쓴다.
허용 count에 대해 원래 count 그대로, 스택 vector 배열에 `count * 8`바이트를 copyin한다.
최대 배열 복사는 128바이트다. 이 **vector 배열 copyin**의 반환 low BYTE는 error에 저장하고
0일 때만 rwuio에 들어간다. 90차 sdwrite 내부 **데이터 copyin**의 반환 무시와 구분해야 한다.
스택 배열을 먼저 전체 초기화하거나 count 0을 별도 거부하지 않는다.

`_rwuio` (`0x10ceac`)는 fd의 unsigned 범위, NULL/sentinel `0xffff0000`,
읽기/쓰기 file flag mask 1/2를 검사한다. 실패는 error BYTE 9이다.
정상 경로는 uio `+0x14` residual과 `+0xc` segment를 0으로 초기화하고,
각 vector의 signed length가 음수인지, 합산 후 sign bit가 설정되는지 검사한다.
각 단계가 통과하면 총 길이는 `0x7fffffff` 이하로 유지된다. 실패 error는 `0x16`이다.
벡터의 개수나 배열을 합치지 않고 원래 uio를 file operation에 넘긴다.

파일 `+0x14`의 operation 표 첫 DWORD를 `CALL EAX`하며 인자는 `(file,direction,uio)`다.
반환 low BYTE는 error `+0x68`, 시작 residual과 현재 residual의 차는 result DWORD `+0x60`에 쓴다.
파일 offset `+0x1c`도 해당 시도의 차이만큼 증가한다. 따라서 EAX만을 일반 시스템 호출의
최종 반환값으로 읽는 decompiler signature는 충분하지 않다. syscall 진입/복귀 문맥 계약은 별도다.

## 2. vnode → 문자 장치 → sdread/sdwrite의 정적 연결

원본 `_vnodefops` `0x1db710` 첫 항목은 `_vno_rw` (`0x11b984`)이다.
vno_rw는 file `+0x18`의 vnode와 원래 uio 포인터를 사용한다.
쓰기의 isrofile 실패는 `0x1e`, 일부 vnode type/flag 조합은 mfs_io로 분기한다.
그 밖에는 vnode `+0x1c`의 operation 표 `+8`을 호출하고 원래 uio를 그대로 전달한다.
type 값 8에서는 uio `+0x10` WORD에 file flags의 low WORD를 저장하지만,
이것이 vector count나 segment를 단일 벡터 형태로 바꾸지는 않는다.

원본 `_spec_vnodeops` `0x1dd6d0`의 `+8`은 `0x139e18`이다.
진단 문자열 `spec_rdwr`와 본문을 대조했다. direction은 0/1만 허용하고 그 밖은 panic 경로다.
읽기의 residual 0은 type 검사 이전에 반환 0으로 끝난다.
vnode `+0x28`의 type 값 4에서는 문자 장치 경로로 들어간다.
`[[vnode+0x30]+0x42]`의 dev WORD에서 major high BYTE를 얻고,
`major * 44`를 더한 cdev read/write slot `+8/+12`를 선택한다.
호출 인자는 sign-extend한 dev WORD와 **원래 uio**다. count를 1로 제한하는 분기는 없다.

초기 `_cdevsw`는 `0x1e2f38`, `_nchrdev`의 초기값은 43이다.
Python으로 계산한 1,892바이트의 표 끝은 nchrdev 주소 `0x1e369c`와 일치한다.
초기 행 14의 read slot `0x1e31a8`은 sdread `0x1835d8`, write slot `0x1e31ac`은
sdwrite `0x183790`이다. 다른 DWORD에는 함수를 포함한 원래 값만 보존하고 전부 함수로 타입화하지 않았다.

이 연결은 **해당 file/vnode operation과 cdev 초기 행이 실제로 선택되는 조건부 경로**다.
runtime major 설치·표 교체·file/vnode 생성까지 증명한 것은 아니다.
다만 선택한 상위 경로가 여러 벡터를 그대로 전달한다는 사실은 90차의 미확정 전제를 좁힌다.

## 3. 임시 버퍼 문제에 대한 새 조건과 예외

90차 sdread/sdwrite는 정렬이 맞지 않을 때 첫 vector만 임시 버퍼로 바꾸고 segment를 1로 쓴다.
physio는 uio count가 남으면 다음 vector로 이동한다. 이번 상위 경로에서는 이 count를
단일화하지 않으므로, 다음 vector의 base까지 segment 1로 취급해도 되는지 증명되지 않았다.
실제 정렬 응답·강제 page 정렬 설정·vector 내용과 controller override는 여전히 필요하다.

count 0도 readv/writev 입구에서 허용된다. rwuio는 residual 0으로 file operation을 호출한다.
spec_rdwr의 읽기는 residual 0이면 일찍 반환하지만, type 4의 **쓰기에는 같은 조기 반환이 없다**.
따라서 해당 정적 dispatch와 sdwrite의 isFormatted 검사 통과를 가정하면, copy 크기가 0이었던
스택 vector 배열을 sdwrite가 먼저 참조하는 경로를 배제할 수 없다.
이는 배열 밖 접근의 확정이 아니라, 초기화되지 않은 첫 slot 참조의 조건부 경로다.
일반 write의 길이 0은 count 1의 초기화된 vector를 쓰므로 같은 사례로 합치지 않는다.

첫 vector가 길이 0이고 이후 vector가 양수인 경우도 남는다. 90차 physio는 이런 vector에서
전송 루프를 건너뛰지만, 자체 초기화하지 않은 B residual을 끝부분에서 검사한다.
기존 B의 상태에 따라 다음 vector까지 진행하는지 달라질 수 있으므로 zero-vector 전처리와
단위별 B 초기화/재사용을 후속 확인해야 한다.

## 4. 완료 대기는 strategy 반환값과 별개

`_physstrat` (`0x11ed10`)는 `(B,strategy,priority)`를 받고 strategy(B)를 먼저 호출한다.
그 반환값은 검사하지 않는다. B BYTE `+1`의 `0x20`이 설정되면 바로 epilogue로 간다.
DWORD flags로 계산하면 이 마스크는 `0x2000`이다.
그렇지 않으면 splbio 후 B의 low BYTE 완료 마스크 2가 설정될 때까지
`sleep(B,priority)`하고 **B 메모리의 완료 비트를 매번 다시 읽는다**. 끝에서는 splx한다.
90차 physio가 전달하는 priority는 `0x14`이다.

Ghidra C는 priority 인자와 sleep의 두 번째 인자를 누락한다. 원본의 `EBP+0x10 → EDI → PUSH EDI`
연결로 보완했다. strategy가 실패를 반환하기만 하고 완료 비트를 게시하지 않는다면
이 함수 자체는 그 반환값으로 대기를 끝내지 못한다. 선택한 sdstrategy/완료 IMP의 계약과
모든 override·비동기 경로의 exactly-once 완료는 구분해야 한다.
비동기 skip 분기에서 B를 언제 해제해도 되는지는 이 본문으로 확인되지 않는다.

## 5. useracc/vslock/vsunlock와 VM 전제

`useracc` (`0x17bd28`)는 `_page_mask`로 start를 아래로, `address+length+mask`를 위로
정렬하고 `vm_map_check_protection`을 호출한다. 모든 계산은 DWORD이며 자체 overflow 검사는 없다.
세 번째 인자가 1이면 protection 값 1, 아니면 2다. physio의 읽기 값 1은 useracc 인자 0/보호값 2,
쓰기 값 0은 인자 1/보호값 1로 이어진다. 외부 protection 상수 정의를 가져오지 않았다.
map은 `T=DWORD[0x1e8b54]`에 대해 `DWORD[DWORD[T+0xc]+0xc]`에서 얻는다.
`useracc`의 C는 void이지만 호출 뒤 epilogue는 **EAX를 보존**하며 physio가 이 값을 검사한다.

`vslock` (`0x17bd68`)은 같은 map/정렬 구간을 `vm_map_pageable(...,0)`에 전달한다.
wrapper 자체는 EAX를 보존하지만 90차 physio는 그 반환값을 성공 조건으로 검사하지 않는다.
실제 wiring 실패/부분 실패와 이후 전송의 관계는 vm_map_pageable 본문·상위 계약이 필요하다.

`vsunlock` (`0x17bd9c`)은 direction이 비영이면 map `+0x24`에서 얻은 대상으로
각 page 주소의 pmap_extract, vm_phys_to_vm_page를 호출한 뒤 반환 객체 BYTE `+0x1e`를
`& 0xdf`로 수정한다. local NULL 검사는 없다. 여기서 지워지는 마스크는 `0x20`이며,
정확한 페이지 상태 의미는 외부 구조체 대신 원본의 다른 writer와 대조해야 한다.
loop는 page_size만큼 진행하면서 page_mask를 다시 읽는다. 끝에서 map도 다시 얻어
`vm_map_pageable(...,1)`을 호출한다. map/geometry 안정성, extract 실패와 페이지 소유권은 미확정이다.

`vm_phys_to_vm_page` (`0x178894`)는 원본 region 표를 28바이트 stride로 검사한다.
물리 주소가 행 `+0x14 <= PA < +0x18`이면, `(PA >> page_shift) - row[+4]`에
48바이트 stride를 적용하고 row 첫 DWORD를 더한 포인터를 반환한다.
shift count는 x86의 low 5비트 적용을 받는다. 일치 행이 없으면 0을 반환한다.
따라서 vsunlock의 무조건 BYTE 접근에 필요한 PA coverage/region 초기화는 별도 전제다.
__common 전역의 파일 영역을 runtime 값으로 읽지는 않았다.

## 6. VM 권한 검사: 디컴파일 loop와 원본의 차이

`vm_map_check_protection` (`0x1765fc`)에는 map `+0x3c` 잠금과 `+0x38` hint를 다루는
레지스터 TEST 반복이 있다. LOAD/TEST/JNZ 주소는 각각
`0x176610/0x176612/0x176614`, `0x176664/0x176666/0x176668`,
`0x176694/0x176696/0x176698`이며 분기 원본 바이트는 모두 `75fc`다.
**JNZ는 LOAD가 아니라 TEST로 돌아간다.** 읽어 온 EAX가 비영이면 해당 loop 안에서는
메모리를 다시 읽지 않는다. Ghidra의 `while (*piVar1 != 0)`는 이 차이를 숨긴다.
XCHG 뒤 별도의 재시도 분기는 LOAD로 돌아간다. 실제 contention이나 정지 재현을 주장하지 않는다.

본문은 start를 포함하는 entry를 hint/연결 목록에서 찾은 뒤 구간을 검사한다.
entry 시작이 현재 위치보다 크거나 sentinel을 만나거나 `(entry[+0x1c] & requested) != requested`이면 0,
연속 entry 끝으로 진행해 end까지 도달하면 1이다. hint 잠금은 entry 순회 전체를 보호하지 않으며
상위 map lock·entry 수명·동시 변경 전제는 열려 있다.

start entry를 찾은 이후에는 `end <= start`이면 바로 1로 간다.
예를 들어 mask `0xfff`, 주소 `0xfffff800`, 길이 `0x2000`의 Python DWORD 계산은
start `0xfffff000`, end `0x2000`이다. 그러나 시작 entry를 찾지 못하면 그 전에 실패하므로
이를 무조건적인 검증 통과나 native 우회로 단정하지 않는다.
0 길이여도 비정렬 주소라면 정렬된 구간이 비어 있지 않을 수 있다.

## 7. 오류 후 재시도와 buffered spec 경로

rwuio는 error가 있으면 `fspause(file.flags & 0x1000)`를 호출하고, 비영 반환 시 uio를
새로 만들지 않고 다시 시도한다. segment 초기화와 vector 합산 지점으로 돌아가는 것은 아니다.
다만 `_fspause` (`0x13ba10`)는 다음 조건을 모두 요구한다:

- 문맥 `+0x6c` 포인터와 signed BYTE `+0x70`이 비영. 두 필드는 검사 전에 0으로 소비한다.
- error BYTE가 `0x1c`, active_u `+0x260` BYTE의 마스크 8이 설정됨, 입력 인자가 0.
- error를 0으로 바꾼 뒤 호출한 rpsleep이 비영을 반환함.

조건 불충족은 0을 반환한다. rpsleep이 0이면 error `0x1c`를 복구하고 0이다.
그러므로 90차 임시 버퍼 해제 뒤 재호출 가능성을 논하려면 이 문맥 writer와 error 경로를
추가로 보여야 한다. 현재 원본 근거만으로 자동 재시도나 use-after-free를 확정하지 않는다.

spec_rdwr의 type 값 3은 별도 buffered 경로다. 원본 상수 8,192바이트로 offset을 나누어
chunk와 chunk 내 위치를 만들고, 장치 자료 `+0x48`로 다시 나눠 실제 B block을 계산한다.
후자 DIV의 자체 0 검사와 곱셈 overflow 검사는 없다. 읽기는 bread/breada 또는 음수 block의
zeroed geteblk, 쓰기는 full chunk getblk 또는 partial bread를 사용한다.
전송량은 signed 비교로 `B.request-B.residual` 이하로 줄인다. B error이면 brelse 후 5를 반환한다.

uiomove 결과를 보존한 뒤 읽기는 brelse, 쓰기는 flag/경계에 따라 bwrite/bawrite/bdwrite를 수행하고,
그 뒤 uiomove 결과를 검사한다. 즉 **copy 실패를 보고도 해당 buffer writeback 호출을 건너뛰지 않는다**.
buffer writeback 자체 EAX가 최종 error를 대체하지 않으며 실제 오류 전파·부분 갱신은 별도 분석이다.

panic 다음 `0x139e3e`는 원본 `ADD ESP,4` 3바이트이며 기존 export가 synthetic fragment로 분리했다.
이 fragment의 C 출력은 뒤쪽 공통 코드까지 따라가지만 독립 ABI 함수로 보지 않는다.
원본의 인접 fall-through를 기록했을 뿐 panic의 non-return 여부를 새로 입증하지 않았다.
spec C의 direction `code *`, 불안정한 임시 스택 포인터와 누락 호출 인자는 그대로 복원 타입이 될 수 없다.

## 판정

기존 보존 항목 837개와 현재 입력 52개를 재해시했다. Ghidra 스킬의 함수·참조 대조 절차가
호출 인자, 표 연결, register-only loop와 fragment 경계 해석을 검증하는 데 사용됐다.
새 독립 교차검토 결과는 없으며 미수신을 통과로 보지 않는다. 새 스크립트 파일/에뮬레이터/
DB 수정/외부 소스 참조는 없었다. 전체 원본 분석은 계속 미완료다.
