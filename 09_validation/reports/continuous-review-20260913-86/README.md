# 86차 — 장치 제출·주소 공간·copy recovery·PTE 이동

## 결과와 범위

원본 OPENSTEP 바이너리와 그 export만으로 sdstrategy, pagemove, uiomove 및 직접 연결된
copy/lookup/Objective-C dispatch를 분석했다. 일반 함수 9개와 recovery fragment 3개,
명령 head 624개, 본문 1,654 bytes를 원본에서 대조했다. 직접 분기 91개, 직접 CALL 13개,
간접 tail jump 4개와 중요 operand 90개를 확인했다. 계산은 Python만 사용했다.

핵심 결과는 다음과 같다.

- uiomove의 주소 공간 값 1은 copywithin을 부르지만 **오류 EAX를 검사하지 않고**
  iovec·offset·residual을 갱신한다. 값 0/2의 copyin/out 오류 처리와 다르다.
- copywithin/in/out의 짧은 정상 경로는 thread recovery slot을 비우는 구간을 건너뛴다.
  recovery fragment는 별도 함수가 아니라 부모 epilogue로 이어지는 비지역 진입 지점이다.
- pagemove는 PTE DWORD를 목적지에 복사한 후 원본을 0으로 만들고, 마지막에 실제로
  **CR3를 읽고 다시 기록**한다. C에 표시된 CR3 반환만으로는 이 효과를 설명할 수 없다.
- sdstrategy의 제출 성공은 자체 biodone을 호출하지 않는다. Objective-C 메서드가 이후의
  완료를 담당해야 하며 실제 클래스·상속·callback은 아직 미확인이다.

Ghidra 스킬의 전체 본문·디컴파일·참조 대조를 적용했고 DB/원본/기존 확정 보고서는 변경하지 않았다.
독립 계획 교차검토는 수신하지 않았으며 구현·복원·동적 실행을 추가하지 않았다.
기존 보존 파일 807개의 해시가 일치했다. 전체 분석 완료나 native 결함 발생을 주장하지 않는다.

근거는 [증거 JSON](object-lifetime-evidence.json)에 있으며 [범위](SCOPE.md),
[보존 해시](preservation.json), [checkpoint](checkpoint.json), [남은 분석](OPEN_ITEMS.md)을 분리했다.

## 1. uiomove의 주소 공간별 계약

`uiomove(cp,n,direction,U)` (`0x10a384`)의 U 필드는 원본상
`+0` iovec 포인터, `+4` iovec 개수, `+8` offset, `+0xc` 주소 공간 구분,
`+0x14` remaining으로 사용된다. iovec는 주소와 길이 DWORD를 가진다.
이 표기는 원본 사용을 설명하며 외부 header 정의가 아니다.

n이 signed 0 이하이거나 U.remaining이 정확히 0이면 루프를 끝낸다.
iovec 길이가 0이면 포인터를 8 bytes 전진하고 개수를 감소시켜 다시 검사한다.
**iovec 개수가 0인지 확인하는 명령은 없다.** nonzero 길이면 chunk는 unsigned min(n,iov.len)이다.
U.remaining 자체로 chunk를 한 번 더 제한하지 않는다.

| U `+0xc` 값 | direction==0 | direction!=0 | copy 이후 오류 검사 |
| --- | --- | --- | --- |
| 0 또는 2 | copyout(cp,iov.base,chunk) | copyin(iov.base,cp,chunk) | EAX nonzero면 즉시 반환 |
| 1 | copywithin(cp,iov.base,chunk) | copywithin(iov.base,cp,chunk) | **없음** |
| 그 밖의 값 | 호출 없음 | 호출 없음 | copy 없이 진척 필드 갱신 |

성공 또는 검사 없는 경로는 iov.base 증가, iov.len 감소, U.remaining 감소,
U.offset 증가, cp 증가, n 감소를 수행한다 (`0x10a424`–`0x10a432`).
값 0/2에서 copy가 실패하면 이 호출 chunk의 진척 필드는 갱신하지 않지만,
callee가 실제 메모리를 일부 복사했는지는 별개다. 이미 완료된 이전 chunk의 진척도 되돌리지 않는다.

값 1에서 copywithin이 복구 오류 `0xe`를 반환해도 필드들은 전진한다.
uiomove의 반환 EAX는 이후 다른 copy 결과로 덮일 수도 있으므로 최초 오류 보존도 자체 보장하지 않는다.
값이 범위 밖이면 copy 없이 필드가 전진할 수 있는 지역 분기다. 실제 입력 범위를 확인하기 전에는
잘못된 공간 값이나 remaining 불일치가 native에서 발생한다고 결론 내리지 않는다.

85차 UFS strategy의 local U는 이 값을 1로 설정했다. 따라서 그 경로는 FS 기반 사용자 copy가
아니라 copywithin 경로로 연결된다. 그러나 그 주소가 physical 주소와 같은 선형 매핑이라는 것은
copywithin 자체가 보장하지 않는다. uiomove 오류/진척과 상위 UFS의 low-BYTE 오류 저장 및
그 뒤 write 제출을 함께 검토해야 한다.

## 2. copywithin/in/out와 recovery slot

선택한 부모는 copywithin `0x189c1c`, copyin `0x189a5c`, copyout `0x189cec`이다.
모두 먼저 `[active_threads]+0x74`에 recovery entry 주소를 저장한다.
이전 recovery 값을 저장하거나 복원하는 방식이 아니라 새 값으로 덮어쓴다.

| 부모 | 저장되는 recovery entry | 정상 긴 경로의 clear | 짧은 성공 jump의 목적지 |
| --- | --- | --- | --- |
| copywithin | `0x189cd0` | `0x189cc4` | `0x189ce1` |
| copyin | `0x189b18` | `0x189b0d` | `0x189b29` |
| copyout | `0x189e70` | `0x189e62` | `0x189e81` |

길이를 signed 비교하여 15 이하이면 짧은 경로를 선택한다.
그 경로들은 EAX=0 후 표의 epilogue로 jump하므로 recovery clear를 통과하지 않는다.
길이 0으로 직접 호출해도 같은 지역 분기이며, 음수 DWORD의 유효성도 이 함수들이 자체 거르지 않는다.
uiomove의 n<=0 선행 종료가 모든 copy 함수의 모든 호출자를 보호하는 것은 아니다.

recovery fragment들은 각각 thread slot을 0으로 만들고 EAX=`0xe`를 설정한 뒤
바로 부모 epilogue로 fall-through한다. fragment 자체에 prologue나 RET는 없다.
export의 synthetic C `return 0xe`를 독립 호출 가능한 ABI 함수로 해석하면 안 된다.
실제 trap이 언제 EIP를 이 주소로 바꾸는지, 부모 EBP/stack/register를 어떻게 보존하는지,
짧은 성공 뒤 남은 recovery 주소가 언제 없어지는지는 아직 native 검증이 필요하다.

### 실제 segment와 복사 순서

copywithin은 기본 segment의 source와 ES destination으로 REP MOVSB/MOVSD를 사용한다.
copyin의 REP에는 **FS source override**가 있다. tail BYTE 읽기도 FS를 사용한다.
Ghidra C는 copyin의 REP 부분에서 이를 일반 pointer copy처럼 표현하므로 그대로 믿을 수 없다.
copyout은 기본 source에서 읽고 destination에 FS override를 붙인 BYTE/WORD/DWORD 저장을 한다.
이 선택 본문에는 자체 CLD/STD가 없다. DS/ES/FS의 실제 descriptor와 DF 상태는 별도 전제다.

copywithin/in은 긴 경로에서 source를 DWORD 경계로 맞춘 후 DWORD bulk, 나머지 BYTE를 복사한다.
나머지 BYTE는 해당되는 경우 offset 2, 1, 0 순서다. source/destination overlap에 대해
역방향 복사를 선택하지 않으므로 일반 memmove 계약으로 확장하지 않는다.
copyout의 긴 경로는 alignment prefix 후 잔여 DWORD 수에 따른 중간 entry와
16-byte 반복을 사용한다. Python으로 prefix·초기 부분 bulk·전체 block·tail의 길이 합을 확인했다.
이는 실제 page fault 없는 메모리 복사 실행을 검증한 것이 아니다.

## 3. pagemove와 pmap_pt_entry

`pagemove(src,dst,len)` (`0x193e58`)는 길이의 low mask `0xfff`만 확인하고,
정렬이 맞지 않으면 원본 `pagemove` panic 문자열 경로로 간다.
source/destination 주소 정렬, 서로 겹치지 않음, destination mapping이 비어 있음은 자체 검사하지 않는다.
루프는 signed len>0일 때만 실행한다. aligned 음수 길이나 0이면 이동 없이 마지막 CR3 작업으로 간다.

각 반복의 실제 순서는 다음과 같다.

1. kernel_pmap과 source 주소로 pmap_pt_entry를 부른다.
2. kernel_pmap과 destination 주소로 다시 부른다.
3. source PTE DWORD를 읽고 destination PTE에 저장한다.
4. source PTE DWORD를 0으로 만든다.
5. 두 주소를 `0x1000`씩 증가시키고 len을 같은 크기만큼 감소시킨다.

마지막에는 `MOV EAX,CR3` (`0x193ebf`)와 `MOV CR3,EAX` (`0x193ec2`)가 있다.
Ghidra C의 `return in_CR3`는 이 실제 제어 레지스터 쓰기를 드러내지 않는다.
이 지역 명령은 확인했지만 전 CPU TLB 처리나 대상 주소 공간의 활성 상태까지 증명하지 않는다.
INVLPG, PV/reference/dirty 회계 갱신이나 자체 pmap lock은 이 본문에 없다.

`pmap_pt_entry(P,va)` (`0x18ec70`)는 `[P] + (va>>22)*4`의 PDE present bit만 검사한다.
없으면 0, 있으면 `(PDE & 0xfffff000) + ((va>>10)&0xffc)`를 반환한다.
반환된 PTE 자체의 present 상태는 검사하지 않고 여기서 page table을 할당하지도 않는다.
pagemove는 이 함수의 NULL 반환을 검사하지 않고 역참조한다.

source/destination이 같은 PTE라면 destination 저장 뒤 source clear가 같은 slot을 0으로 만든다.
앞으로 겹치는 mapping 이동 역시 미리 덮어쓸 수 있다. 이는 원본 store 순서의 조건부 결과이며
85차 allocbuf가 실제 alias/overlap을 넘긴다는 증명이 아니다. caller의 주소/크기/가용 mapping
invariant를 확인해야 한다. 물리 payload를 복사하는 함수라기보다 PTE를 옮기는 함수라는 점도 구분한다.

고정 이동 단위 `0x1000`과 runtime page_size를 혼동하지 않았다.
이번에 읽은 `_page_size`의 원본 `__data` 파일 값은 0이다. 이는 부팅 후 값이 0이라는 뜻이 아니며,
이전 부팅 코드의 대입 명령에 관한 결론과 파일 초기값은 서로 다른 근거다.
kernel_map/kernel_pmap은 `__common`, disk table/control은 `__bss`이므로 runtime 값으로 읽지 않았다.

## 4. sdstrategy와 device lookup

`sdstrategy` (`0x183920`)는 B device WORD `+0x1e`를 signed 확장해 lookup `0x1840ec`에 넘긴다.
lookup은 WORD의 low byte에서 unit=`(dev>>3)&0x1f`, partition=`dev&7`을 얻는다.
unit<=15만 허용하고 unit마다 36-byte 간격의 `0x1e7324` row를 선택한다.
partition 0–6은 row의 `+4+partition*4` pointer를 읽는다.
partition 7은 device high byte가 runtime DWORD `0x1e7564`와 같으면 NULL,
다르면 row 첫 pointer를 반환한다. row 내용 및 등록 writer는 아직 미확인이다.

객체가 있으면 flags의 `(B.flags & 0x4000010)==0x10`일 때만
`[[[B+0x2c]+0x68]+0xc]`에서 client map을 가져오고, 아니면 kernel_map을 사용한다.
84차 stack direct flags `0x2000001`은 이 식에서 kernel_map 쪽이다.
이 선택이 physical 주소를 자동으로 선형 주소로 바꾸는 것은 아니다.

객체에 `blockSize` 메시지를 보내고 결과가 정확히 0이면 오류 경로다.
nonzero를 이후 offset 환산이나 길이 정렬 검사에 사용하지는 않는다.
read mask `0x1`에 따라 다음 메시지를 선택한다.

- `readAsyncAt:length:buffer:pending:client:`
- `writeAsyncAt:length:buffer:pending:client:`

원본 stack 인자는 receiver, selector, B.block, B.request, B.data, B 자체인 pending,
선택한 client map이다. method 반환이 0이면 sdstrategy도 0을 반환하며 **자체 biodone은 없다.**
실제 method의 완료 책임과 콜백 흐름을 별도로 연결해야 한다.

lookup NULL 또는 blockSize==0이면 B error WORD=6이다.
제출 method가 nonzero를 반환하면 같은 객체에 `errnoFromReturn:` 메시지를 보내고
그 결과 low WORD를 B error에 저장한다. 두 오류 경로는 flags `0x4` 후 biodone을 호출하고
EAX=`0xffffffff`를 반환한다. 자체 residual 저장은 없다.
errno method가 0을 반환하는지 여부에 따라 flag/WORD 일관성이 달라질 수 있으므로
실제 구현과 허용 입력을 확인하기 전에는 nonzero WORD 보장을 주장하지 않는다.

## 5. objc_msgSend — C 호출 표현과 실제 tail dispatch

`0x1ce960`의 실제 원본은 self와 selector를 원래 stack에서 읽는다.
`self & __objc_multithread_mask`가 nonzero면 빠른 cache 조회,
0이면 nil 확인 후 messageLock을 사용하는 조회로 간다. nil은 EAX=0인 채 RET한다.
파일 초기 mask는 `0xffffffff`, lock은 0이지만 runtime writer는 이번 범위에서 확정하지 않았다.

class의 `+0x20` cache에서 mask와 slot 배열을 읽고 selector pointer를 비교한다.
충돌하면 index를 증가시키고 mask를 다시 적용한다. hit은 entry `+8`의 IMP를 읽는다.
miss는 `0x1cd868`의 lookup/load-cache helper를 호출해 얻은 EAX를 사용한다.

네 종료 지점 `0x1ce995`, `0x1ce9c3`, `0x1cea27`, `0x1cea5d`는 **CALL이 아니라 JMP EAX**다.
스택에 보존했던 ESI/EDI를 복구하고, 잠금 경로이면 messageLock을 먼저 0으로 만든 뒤 IMP로 이동한다.
따라서 원래 method 인자와 caller의 반환 주소를 사용하는 tail dispatch다.
Ghidra의 무인자 간접 함수 호출/void 표현을 method ABI로 채택하지 않았다.
잠금은 원본 memory XCHG 반복이며, 이 동작을 C의 LOCK/UNLOCK 표기만으로 대체하지 않는다.
cache miss helper의 실패/forwarding·상속·동시 등록 정책은 아직 남는다.

## 6. 원본 selector와 실제 구현 후보

`__message_refs`의 `0x1f93a8`, `0x1f93ac`, `0x1f93b0`, `0x1f93b4`를
원본 문자열 `blockSize`, readAsync, writeAsync, errnoFromReturn로 대조했다.
정확한 export selector reference 45개를 수집하고 `__inst_meth`에 있는 한정 tuple 10개를
selector/type encoding/IMP pointer로 확인했다. 아직 소유 class·상속 및 실제 sdstrategy 객체와
연결하지 않았으므로 **실행 대상 확정이 아닌 후보**다.

| selector | 원본 metadata의 IMP 후보 |
| --- | --- |
| blockSize | `0x1a5724` |
| readAsyncAt:length:buffer:pending:client: | `0x1a5e9c`, `0x1a6e64`, `0x1ac7fc` |
| writeAsyncAt:length:buffer:pending:client: | `0x1a5f74`, `0x1a6f34`, `0x1ac85c` |
| errnoFromReturn: | `0x1a4a20`, `0x1a5d60`, `0x1a9568` |

category/protocol 성격의 다른 section 참조를 같은 tuple layout이나 IMP로 가정하지 않았다.
명령 영역의 inferred selector DATA reference도 실제 정적 pointer 저장과 구분했다.
원본 type encoding 문자열은 증거에 보존하되 그 숫자를 stack ABI에 곧바로 대입하지 않았다.

## 7. 아직 확정하지 않은 것

실제 disk class/IMP/완료 callback, phys/linear mapping, trap의 recovery 실행,
짧은 copy 뒤 slot 정리, DS/ES/FS와 DF, pagemove의 전 CPU 상태 및 PV/TLB 회계,
uio의 모든 입력 invariant는 미완료다. selected 함수의 byte/분기 대조와 정수 예시는
이 native·전역 요건을 대신하지 않는다. 전체 원본 분석 목표는 계속 활성 상태다.
