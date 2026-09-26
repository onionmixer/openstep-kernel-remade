# 78차 — PTE/PV 제거와 실제 page free queue 반환 경계

## 범위와 증거

77차에서 남긴 하위 경계를 OPENSTEP 원본 바이너리와 보존 Ghidra asm/C/메타데이터로
검토했다. 외부 프로젝트 코드나 `01_resources`·`07_kernel`은 참고하지 않았다.
Ghidra 스킬은 기존 export 읽기와 원본 대조에 적용했으며 원본·DB·보존 export는 변경하지 않았다.
구현·빌드·포팅·새 실행 검증 프로그램·동적 실행·새 독립 계획 검토는 없다.

Python으로 선택 본문 6개, 명령어 619개, 1,856바이트의 원본 mapping과 재디코딩,
직접 분기 95곳의 본문 내 목적지, 직접 CALL 20곳의 export 목적지 일치를 확인했다.
선택 본문에 간접 제어 이전은 없다. Ghidra WARNING 주석은 11개이며 경고 수가
의미 차이의 수나 해결된 문제의 수는 아니다. 본문 밖 진입·누락 함수·전체 실행 도달성은
이 국소 검증으로 완료 처리하지 않았다.

전체 명령어 증거·원본 nlist·문자열·계산은
[page-reclaim-evidence.json](page-reclaim-evidence.json), 이전 범위 내 파일 해시는
[preservation.json](preservation.json), 후속 경계는 [OPEN_ITEMS.md](OPEN_ITEMS.md)에 있다.
FUN_0018f7f8과 FUN_00190f90에는 해당 주소의 원본 nlist 이름이 없다. 각각의 panic
문자열이 `pmap_remove_range`, `pmap_deallocate_mappings` 계열이라고 해서 이를 nlist
심볼이 확인된 것처럼 기록하지 않았다.

## 이번에 연결한 반환 단계

| 원본 본문 | 직접 변경하는 대상 | 이것만으로 보장하지 않는 것 |
| --- | --- | --- |
| pmap_remove_all / FUN_0018f7f8 | PTE words, 물리 descriptor의 PV 연결·누적 byte, 일부 page flag | VM object 목록에서 page 제거, 모든 caller의 직렬화 |
| FUN_00190f90 | pmap 통계, PT backing WORD 수, PDE present byte, PT 재사용 queue | backing 물리 페이지를 VM free queue에 반환 |
| vm_page_free | page hash와 object 목록, object WORD 수, page membership byte | page 내용 초기화, 모든 page의 무조건 free queue 삽입 |
| vm_page_addfree | active/inactive 목록 제거, 조건부 VM page free queue 삽입 | 모든 page flag 정규화, wait 해제, allocator의 후속 재사용 |

따라서 매핑 제거, PT backing 재사용, VM page free queue 반환은 같은 사건이 아니다.
원본 명령 순서와 필드 폭을 각 단계별로 구분해야 한다.

## pmap_remove_all — 물리 주소의 PV head를 반복 제거

`0x18fb0c`는 물리 주소 stack 인자 하나를 사용한다. unsigned
vm_first_phys <= pa < vm_last_phys를 통과하지 않으면 spl 호출 없이 반환한다.
통과하면 splvm을 저장하고 pg_first_phys, ptes_per_vm_page, pg_desc_tbl을 이용해
20바이트 간격 descriptor를 계산한다. descriptor+4가 pmap, +8이 VA이며,
descriptor+0은 뒤에 연결된 별도 PV entry다. descriptor+4가 0이면 정리 loop를 건너뛴다.

각 반복은 VA를 저장하고 해당 pmap+0xc lock을 잡는다. directory/PTE 주소를 구하고
첫 PTE에 대해서 다음 조건을 확인한다.

- PDE present, 계산한 PTE 포인터 non-NULL, PTE present가 아니면 `0x18fbd0` panic.
- 첫 PTE & 0xfffff000이 인자 pa와 다르면 `0x18fbe9` panic.
- 첫 PTE의 byte+1 & 2, 즉 DWORD mask 0x200이 설정되면 `0x18fbfc` panic.

인자 자체를 정렬하는 명령은 없다. 이 검사는 모든 sibling PTE의 물리 주소·present·
mask 0x200을 각각 검증하는 것이 아니다. 그룹의 일관성은 생성·변경 경로에서 입증해야 한다.

### CR3 명령의 존재와 도달성은 별개

원본 `0x18fc3b/0x18fc3e`에는 CR3 읽기/재기록이 있고 C 출력에는 빠져 있다.
그러나 이 함수의 해당 직접 흐름에서는 VA와 동일한 EBX page_size로 end를 만든 뒤,
그 end에서 같은 VA를 빼고 EBX와 비교한다. 중간에 CALL이나 EBX/page-size 재로드는 없다.

Python/SymPy로 DWORD 모듈러 식을 검산하면 `(VA + P - VA) mod 2^32 == P`다.
따라서 `0x18fc39`의 JBE는 이 흐름에서 항상 성립하며 CR3 fallthrough로 가지 않는다.
77차 pmap_remove의 start/end 독립 인자에 대한 큰 구간 분기와 혼동하지 않는다.
외부 중간 진입·메모리 손상·자기 수정까지 불가능하다고 주장하는 전역 도달성 증명은 아니다.

kernel_pmap이거나 pmap+0x18이 0이 아닌 무효화 gate에서, 실제 VA < end인 동안
0x1000 간격 INVLPG를 실행한다. kernel은 기본 segment, 다른 pmap은 FS override다.
VA+page_size가 wrap하면 unsigned VA < end 검사를 통과하지 않을 수 있다.
예를 들어 Python의 조건부 VA=0xfffff000, P=0x2000 예시는 end=0x1000으로 이 loop에
들어가지 않는다. 이런 입력이 정상 실행에 도달한다는 뜻은 아니다. 작은 구간 통계 갱신은
loop를 건너뛴 경우에도 존재한다.

### 원본 변경 순서

1. 앞서 설명한 INVLPG 경로를 실행한다. PTE를 먼저 지운 뒤 무효화한다고 순서를 바꾸지 않는다.
2. descriptor+0이 있으면 그 PV entry의 +0/+4/+8을 descriptor에 복사하고
   `0x18fc92`에서 pv_entry_zone에 zfree한다. 없으면 descriptor+4만 0으로 쓴다.
   비어 있는 head의 다른 필드까지 0으로 초기화한다고 가정하지 않는다.
3. signed 양수 ptes_per_vm_page만큼 PTE words를 처리한다. 각 word의 mask 0x40이면
   같은 원래 pa로 vm_phys_to_vm_page를 호출하고 반환 page+0x1e에 AND 0xdf,
   descriptor+0x10에 OR 1을 한다. mask 0x20이면 descriptor+0x10에 OR 2를 한다.
4. 각 PTE DWORD를 0으로 쓰고 포인터를 4바이트 전진시킨다. sibling마다 별도의
   pa 값을 재계산하거나 변환 결과 NULL을 검사하지 않는다.
5. FUN_00190f90(pmap,VA,1,0,1)을 호출한 뒤 pmap lock을 해제한다.
   그 뒤 갱신된 descriptor+4를 읽어 다음 pmap을 처리하며 마지막에 splx한다.

PV head의 승격/해제가 PTE clear보다 먼저인 점과, backing accounting이 pmap unlock보다
먼저인 점을 보존했다. 직접 vm_page_free나 object 목록 unlink는 없다. PV entry allocator,
descriptor 및 object 저장소의 정상 비별칭·수명 전제와 다른 writer의 직렬화는 남아 있다.

## FUN_0018f7f8 — PTE 포인터 구간과 PV 한 항목 제거

이 함수는 pmap/start/end/마지막 제어값의 stack 인자 네 개를 사용한다. 자체 spl이나
pmap lock 획득은 없다. 77차 pmap_remove의 splvm 호출만으로 모든 SMP·PV 직렬화가
입증됐다고 보지 않는다.

start의 PDE가 없거나 계산한 PTE 포인터가 0이면 하위 통계 helper도 호출하지 않고 반환한다.
end는 별도로 PTE 포인터로 변환하며 PDE가 없으면 0으로 둔다. 시작과 끝 PTE 포인터의
`& ~page_mask` 값이 다르면 끝을 `(시작 PTE + ptes_per_vm_page*4 + page_mask) & ~page_mask`
의 DWORD 결과로 교체한다. 본문은 이 PTE 포인터 한계까지 순회하며 VA end를 매번 비교하는
단순 주소 loop가 아니다. page_mask/그룹 크기와 상위 section chunk 계약을 연결해야 한다.

첫 PTE present가 없으면 해당 그룹 전체를 ptes_per_vm_page*4만큼 건너뛰고 VA를
page_size만큼 증가시킨다. 첫 PTE가 present이면 제거 그룹 수를 한 번 증가시키고,
첫 PTE의 mask 0x200이면 별도 수를 한 번 증가시킨다. sibling present를 각각 세지 않는다.
Python 예시에서 첫 word가 0이고 뒤 word만 present인 그룹은 전체 clear를 건너뛴다.
그런 불일치 그룹이 유효하다는 판단이나 실제 사고 주장은 하지 않았다.

첫 PTE frame이 vm_first_phys/vm_last_phys 범위 밖이면 PV나 page flag 처리를 하지 않고
그룹 PTE를 0으로 만든다. 범위 안이면 descriptor를 구하고 각 PTE의 0x40/0x20을
pmap_remove_all과 같은 page/descriptor byte에 반영한 뒤 0으로 만든다.

중요한 차이는 **PTE clear가 PV membership 검사보다 먼저**라는 것이다.
descriptor+4가 0이면 `0x18f98b`, (pmap,VA) 쌍이 head나 연결 PV entry에서 발견되지
않으면 `0x18f9f1` panic이다. 이때 이전 PTE 변경을 rollback하는 명령은 없다.
head 일치 시 다음 PV를 승격하거나 +4를 0으로 쓰고, 체인 일치 시 predecessor.next를
변경한다. 별도 PV entry는 `0x18fa05`에서 zfree한다.

마지막 FUN_00190f90 인자는 원래 start, 제거 그룹 수, 첫 PTE mask 0x200 그룹 수,
원래 마지막 제어값이다. 직접 일반 오류 코드나 clear/PV 변경의 복구를 제공하지 않는다.
ptes_per_vm_page가 signed 양수가 아닌 경우·page_size 불일치·포인터 wrap의 정상 도달성은
아직 입증되지 않았다. 이를 임의로 정상 상태로 가정하거나 확정된 native 결함으로 발표하지 않는다.

## FUN_00190f90 — pmap 통계와 PT backing 재사용

stack 인자는 pmap, VA, removed, unwired, release다. 본문 진입 직후 pmap+0x14에서
unwired DWORD를, pmap+0x10에서 removed DWORD를 먼저 뺀다. 그 뒤 kernel_pmap이면
return하며, kernel이 아니어도 section_size로 정렬한 VA의 PDE가 없으면 return한다.
이런 skip보다 통계 갱신이 앞선다.

PDE가 있으면 해당 물리 descriptor+0xc의 backing 포인터를 구한다.

1. backing+0x1a WORD를 zero-extend해 unwired DWORD와 unsigned 비교한다. 부족하면
   `0x191001` panic, 충분하면 WORD에서 DI를 뺀다.
2. backing+0x18 WORD와 removed DWORD를 unsigned 비교한다. 부족하면
   `0x19101b` panic, 충분하면 WORD를 감소시킨다.
3. release가 0이 아니고 감소한 +0x18 WORD가 0이면 signed 양수 ptes_per_vm_page만큼
   PDE의 낮은 byte에 AND 0xfe를 한다. PTE clear와 달리 DWORD 전체를 0으로 쓰지 않는다.
4. backing의 기존 queue 연결을 제거하고 pt_active_count를 감소시킨다. pt_free_queue
   tail에 연결하고 `0x191076`에서 tail을 저장한 뒤 `0x19107c`에서 pt_free_count를 증가시킨다.

첫 underflow 검사 이전에 pmap 통계가 바뀌며, 두 번째 검사 이전에는 backing의 unwired
WORD도 바뀔 수 있다. panic 경로가 무변경·원자적 rollback이라고 볼 수 없다.
Ghidra C는 마지막 tail 저장을 free count 증가 뒤로 표현한다. 원본의 순서를 따른다.
자체 lock, spl, TLB 무효화, VM page free 또는 물리 메모리 zeroing 호출은 없다.
PT backing을 재사용 queue에 넣는 것과 VM free page 반환은 별개다.

## vm_page_free — hash/object detach 뒤 조건부 addfree

`0x17b540`은 NULL 검사 없이 page 인자에서 시작한다. page+0x20의 mask 4가 설정되면
`((offset >> (page_shift & 31)) + object) & vm_page_hash_mask`로 8바이트 bucket을 찾는다.
splimp, bucket lock 아래 hash head 또는 연결의 page+0x10 next를 변경한다.
head가 아니면 목표 page를 찾을 때까지 연결을 따라가며 NULL 탈출 분기는 없다.
membership flag·bucket 함수·체인 존재의 일관성이 전제다.

bucket unlock과 splx **후에** object 목록을 제거한다. page+8은 next, +0xc는 prev이며
object sentinel 여부에 따라 object+0/+4 또는 이웃 page+8/+0xc를 갱신한다.
object+0x1a WORD를 감소시키고 page+0x20의 mask 4를 지운다. 77차 캐시 조건에 사용된
object+0x1a가 이 경로에서 목록 제거 시 감소한다는 원본 연결을 확보했지만, 모든 writer를
보지 않고 외부 구조체의 세부 의미를 가져오지는 않는다.

마지막에 page+0x1e & 8이 0일 때만 vm_page_addfree를 호출한다. 이미 free라는 판정으로
addfree를 건너뛰어도 앞선 hash/object detach는 수행될 수 있다. 객체 포인터, offset,
hash-next와 page 데이터 전체를 이 본문에서 0으로 초기화하지 않는다.
object lock이나 active/inactive queue lock도 직접 획득하지 않는다. 77차 caller는
page queue lock을 잡고 vm_page_free를 호출하며, 전체 caller의 계약은 별도로 확인해야 한다.

## vm_page_addfree — queue 상태와 C의 lock 쓰기 누락

`0x17b5f8`은 page+0x1e & 2이면 active 목록을 제거하고 수를 감소시킨 뒤 해당 mask를 지운다.
이후 & 1이면 inactive 목록에 대해서도 독립적으로 수행한다. else-if가 아니므로 두 flag가
동시에 설정된 입력을 검산할 때도 둘 다 검사한다. 그런 입력의 실제 목록 유효성은 미확인이다.

그 다음 page+0x20 & 8이 설정되어 있으면 free queue 삽입 없이 반환한다. 이 mask의
외부 이름은 사용하지 않았다. active/inactive 제거보다 이 검사가 뒤라는 점이 중요하다.

그 외에는 splimp 후 free queue lock `0x1f7418`을 획득한다. 원본은
`0x17b691` EAX=1, `0x17b696` XCHG로 실제 lock word에 1을 쓰고 경쟁 시 재시도한다.
보존 C에는 LOCK/UNLOCK 표시는 있지만 이 획득 값 쓰기가 빠져 있다. C를 그대로 lock
동작의 완전한 표현으로 취급하지 않는다.

free queue tail 연결, page+0x1e OR 8, vm_page_free_count 증가를 완료한 뒤
`0x17b6d5`에서 lock을 풀고 저장한 spl을 복원한다. 이 helper 자체에는 이미 free인지
거르는 page+0x1e & 8 검사가 없다. vm_page_free의 직접 호출 경계가 이 검사를 제공한다.
다른 호출자의 중복 삽입 방지 계약은 미완료다. 자체 active/inactive queue lock, wait 해제,
page payload 초기화나 모든 flag 초기화 호출은 없다.

원본 spin 3곳은 메모리 load가 아닌 바로 다음 TEST로 되돌아가는 `75fc`를 포함한다.
디컴파일 C의 반복 메모리 읽기와 동일한 native 진행성을 보장하지 않는다.

## vm_phys_to_vm_page — 영역별 검색과 hole

`0x178894`는 num_regions로 정한 28바이트 stride 목록을 앞에서부터 검색한다.
region+0x14 <= pa < region+0x18인 첫 영역에서,
`((pa >> (page_shift & 31)) - region+4) * 48 + region+0`의 DWORD 값을 반환한다.
맞는 영역이 없으면 0이다. 입력 정렬 검사나 descriptor 배열 범위 검사는 직접 없다.
비정렬 pa도 해당 영역에 들면 shift 결과에 해당하는 record를 받을 수 있다.

Python의 가상 영역 예시에서 broad vm_first_phys/vm_last_phys 사이에 있어도 영역 사이
hole이면 0을 반환한다. 따라서 pmap 제거 함수의 broad 물리 범위 검사만으로 이 helper의
성공이 논리적으로 보장되지는 않는다. 성공 뒤 page+0x1e를 바로 수정하는 caller는 실제
메모리 지도·PTE 생성·descriptor 범위의 일관성에 의존한다. 실제 커널에 hole PTE가 있거나
NULL 접근이 발생했다고 주장한 것이 아니다.

## 보존 및 미완료 경계

원본 SHA-256은 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`이다.
이번 입력 24개와 이전 범위 내 보존 파일 759개의 해시, 원본 문자열 7곳을 확인했다.
계산은 Python의 Capstone 재디코딩·유한 산술·SymPy 모듈러 식으로 수행했다.
스킬이 유도한 원본/디컴파일 대조를 통해 lock 쓰기 누락, 갱신 순서 차이, CR3의 국소
도달성 차이를 문서화했다. 이 결과는 emulator/native 실행 또는 독립 agent 검토가 아니다.

VM page의 free queue 삽입까지 직접 경로를 연결했으나 object 종료·pager/wait,
PTE/PV 생성과 alias 불변식, PT/PD 재사용, 모든 caller의 lock·native TLB/IRQ 검증은 남아 있다.
전체 원본 분석 목표는 아직 완료되지 않았다.
