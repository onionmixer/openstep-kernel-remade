# PT 생성·회수·재사용의 원본 계약과 미해결 의존성

주소는 기준 x86 binary의 논리 주소다. 심볼이 없는 helper 이름은 공개 Darwin
i386 pmap.c와 원본 제어 흐름을 대조한 역할 명칭이며 원본 심볼 복구를 뜻하지 않는다.
아래 source 해석과 이번 실행 범위를 구분한다. 산술은 Python이다.

## expand의 자원 선택 및 반환

| 원본 위치 | 관찰/계약 |
|---|---|
| 0x190d08–0x190d15 | 대상이 kernel_pmap이면 panic. 사용자 PT와 커널 PT 확장 조건은 다르다. |
| 0x190d1d–0x190d47 | free PT sentinel 비교, 첫 extension dequeue, free count 감소. |
| 0x190d53–0x190d59 | extension+8 → descriptor+8에서 kernel VA를 읽는다. 성공 설치 경로에서 PT를 지우지는 않는다. |
| 0x190d76–0x190d80 | free PT가 없으면 kmem_alloc_wired(kernel_map,&pt,page_size). 비영이면 복귀. |
| 0x190d86–0x190e1a | 신규 성공 시 total PT 증가, extension zalloc, kernel PTE에서 PT physical 주소 추출, descriptor/extension 양방향 연결 및 count/age 초기화. |
| 0x190e20–0x190e38 | SPL 변경 뒤 대상 PDE를 다시 검사한다. |
| 0x190e51–0x190e91 | 타 실행 주체가 먼저 확장했을 조건에서는 extension 연결 해제/zfree/kmem_free 및 total PT 감소. 이번에는 미실행. |
| 0x190e98–0x190f0d | section/owner/age 기록, active queue 등록, 연속 hardware PDE 설치. |
| 0x1907ac–0x1907bc | 호출자 pmap_enter는 expand 뒤 SPL을 다시 얻고 PDE 검사로 돌아간다. expand의 EAX를 오류 코드로 검사하지 않는다. |

이번 실패 실행의 expand 반환 시 EAX=1은 실제 register 관찰이지만 helper의
공개 오류 반환 ABI로 승격하지 않는다. void 형태 공개 소스와 호출자의 무검사
재시도를 함께 보존한다. 반복을 관찰 경계에서 멈춘 것은 정상 실패 반환이 아니다.

## VA 부족과 물리 페이지 부족을 분리

`kmem_alloc_wired(0x173d1c)`는 size를 VM 단위로 반올림하고 map 최소 주소에서
`vm_map_find(map,0,0,&va,size,1)`을 호출한다(0x173d5b). 정상 full map 입력에서
원본 find는 범위 초과를 확인하고 3을 반환한다(0x174bd8–0x174bf9).

0x173d63–0x173d68의 TEST/SETNZ/AND는 비영 결과를 1로 축약한다. 따라서
vm_map_find의 3을 expand까지 그대로 전파하는 모델은 틀리다. find 진입의
0x174aad는 map timestamp(+0x4c)를 증가시키므로 실패에서도 모든 metadata가
불변이라는 모델은 틀리다. 원래 out-pointer store(0x173e3a)는 이 실패에서 미실행이다.

반면 실제 physical page 확보 helper(0x173ebc)는 0x173df1에서 wait=1로 호출된다.
0x173eff의 page alloc이 실패하면 0x173f24–0x173f59에서 wake/sleep하고 다시
할당한다. 준비한 VA 고갈 사례는 이 경로를 실행하지 않는다. 메모리가 부족하면
무조건 즉시 ENOMEM이라는 구현으로 바꾸면 원본 대기 계약을 잃는다.

## 신규 wired allocation 성공에 필요한 다음 증거

1. 원본 kernel_map의 유효 가용 VA, lock/sentinel/hint 및 map-entry zone.
   0x174d49의 zalloc와 entry 연결/분할·제거 수명이 필요하다.
2. kernel_object(0x1f6ea0)의 실제 ref/hash/memq와 map 삽입/제거 연결.
   0x173da2 ref 증가, 0x173dbf delete, 0x173dd5 insert를 우회하지 않는다.
3. 0x173eff 원본 page allocation, 0x173f8d zero-fill, 0x173f92 busy 해제.
   free page 부족은 별도 scheduler/pageout 진행 조건이 필요하다.
4. 0x173e2f의 wiring 및 실제 kernel PTE 설치. kmem_alloc_wired는 이 호출 뒤
   EAX를 검사하지 않고 out VA를 저장/0 반환하므로 반환0만으로 PTE 성공을
   대신할 수 없다. 가능한 wiring 실패의 선행조건도 추가 분석 대상이다.
5. kernel VA를 확장 helper가 직접 역변환하는 0x190da6–0x190de5를 관찰한다.
   lookup 실패 시 physical 값이 0이 되는 raw 경로를 단순 정상 성공으로 모델링하지 않는다.
6. extension zone(0x1f7ab4)의 원본 zalloc. 0x16b3b7–0x16b3d9의 기존 free
   element pop과 zone backing 신규 성장은 구별한다. expand는 zalloc NULL을
   검사하지 않고 extension을 역참조하므로 이를 정상 ENOMEM 반환으로 바꾸지 않는다.
7. 실제 descriptor/extension/PV/kernel wired mapping과 user PDE 설치, total/active
   counts, 경쟁 정리 및 마지막 해제까지 소유권을 이어 검증한다.

이 의존성 목록은 신규 성공을 검증했다는 뜻이 아니다. 이번 free PT 재사용 성공을
위 과정의 대체로 취급하지 않는다. kernel PDE를 사전 준비하는 경우에도 그 합성
경계를 분명히 하고 전체 kernel pmap 생성은 계속 미완료로 남겨야 한다.

## 회수와 잔여 bit

원본 pmap_remove(0x18fa44)는 활성 user pmap에서 대상 범위에 맞는 TLB invalidation을
먼저 실행하고 remove helper에 free_table=1을 전달한다(0x18fae1–0x18fae9).

- 0x18f8b4–0x18f8c8은 NP VM 묶음을 count/PV 제거 없이 건너뛴다.
- present managed 묶음은 dirty/reference를 검사하고 각 PTE를 0으로 쓴다
  (0x18f94c–0x18f97c). dirty이면 phys→vm_page lookup 0x178894와 clean bit
  변경까지 발생한다. 이번 scalar-read 사례는 dirty=0, reference 변화만 다룬다.
- PV head의 마지막 mapping 제거는 pmap 필드만 0으로 만들며 VA 등 잔여 필드를
  반드시 모두 지우지는 않는다(0x18f9bc). byte 모델은 이 잔여를 보존한다.
- deallocate helper(0x190f90)는 pmap DWORD 및 extension WORD count를 감소시키고,
  free_table이며 alloc_count=0일 때만 PDE valid bit를 지워 active→free로 이동한다.
- PDE 변경은 `AND byte [ESI],0xfe`(0x191040)이다. 권한·Accessed 등 나머지 bit를
  삭제하는 full-DWORD zero store로 대체하면 안 된다.
- free PT는 다시 쓰기 전에 모든 PTE가 NP이고 count가 0이어야 한다. NP 잔여
  bit까지 전체 byte zero라고 일반화하지 않는다. 0xdeadbe00 시험 값은 NP이지만
  wired 잔여 bit를 포함하므로 present mapping의 wired count와 구분해야 한다.

## 준비 코드 검산에서 확인한 memset 분기

새 kernel map lock 초기화(0x15b54c)는 0x15b553에서 길이 12를 push하고 bzero
→ memset으로 내려간다. memset의 0x101669 간접 jump는 원본 table
`0x101670 + (12 - 1) * 4`의 값을 사용한다. Python에서 table 값을 읽어 이
특정 준비 호출을 검산한다. 이 허용을 모든 간접 jump의 무조건 허용으로 넓히지 않는다.

GCC 2.7 복원에서는 위 폭/bit/반환/대기/assembly 경계를 유지해야 한다. 이 문서는
복원 C 코드나 실제 GCC 2.7 컴파일 결과가 아니다.
