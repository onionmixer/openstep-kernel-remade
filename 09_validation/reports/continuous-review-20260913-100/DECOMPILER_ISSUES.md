# 100차 디컴파일 표현 차이

## 1. vm_alloc_from_regions의 반환 주소 누락

0x178964 C의 formal 반환은 void이고 성공 때 단순 return으로 표시된다.
원본은 0x178998..0x17899e에서 정렬된 시작 주소를 EAX에 만들고,
0x1789a3에서 EDX=start+size를 계산한다. 허용 범위면 region cursor를 EDX로 갱신하고
0x1789ac에서 EAX를 변경하지 않는 epilogue로 간다.
따라서 성공 EAX는 end가 아니라 base다. vm_page_startup은 0x17ac02에서 이 EAX를
zdata pointer로 저장한다. void C만으로 초기 메모리 출처를 추적하면 반환 연결이 빠진다.
panic 이후 실제 복귀와 callee 전체 성공 보장은 별도 문제다.

## 2. zalloc wrapper의 void 반환 추론

zalloc 0x16b790은 두 번째 인자 1, zalloc_noblock 0x16b7a4는 0을 전달한다.
각 CALL 뒤 MOV ESP,EBP / POP EBP / RET는 callee EAX를 유지한다.
두 C의 void 표기는 실제 반환 레지스터 소비를 없애는 근거가 아니다.
zalloc(…,1)을 항상 성공하거나 항상 non-NULL이라고 읽는 것도 정확하지 않다.
원본 본체에는 over-limit flag mask 4에 따른 NULL 반환 경로가 있다.

## 3. Spin의 memory reread를 C loop로 보충하지 않는다

선택 본문에는 MOV memory→EAX, TEST EAX,EAX, JNZ 같은 TEST 주소의 패턴이 11개 있다.
JNZ bytes는 75fc이며 back edge가 MOV로 돌아가지 않는다.
예: 0x16b3a0의 load 뒤 0x16b3a4는 0x16b3a2로, 0x16ae0f는 0x16ae0d로 간다.
C의 while(*lock!=0) 또는 global while 표기와 달리 이 지역 back edge에는 새 memory load가 없다.
실제 lock 값·도달 상태·interrupt/register 변경·코드 변경까지 관찰하지 않았으므로
native deadlock을 확정하지 않는다. 그러나 C를 원본과 같은 volatile 재읽기 loop라고 할 수도 없다.

## 4. start의 hardware 명령 표현 누락

start 0x1860dc의 원본에는 CLD, far JMP 두 개, segment register MOV, 마지막 HLT가 있다.
C는 주로 초기화 함수 호출과 무한 loop로 표시하며 이 명령들을 보존하지 않는다.
far offset/selector bytes는 확인했지만 당시 descriptor와 CPU 상태 전체는 미확인이다.
부팅 entry에 CLD가 있다는 사실만으로 이후 모든 copy caller의 DF=0을 보장하지 않는다.
HLT 원본을 실제 JMP loop로 치환해 설명하지 않는다.

## 5. 반환 폭·fragment·초기값

kmem_alloc_zone의 undefined1 추론과 별개로 원본 EAX 지역 반환은 0/1/6이다.
output pointer는 성공 때만 쓴다. 값 범위와 formal ABI 폭의 증명은 구분한다.

panic fallthrough fragment는 각각 ADD ESP 명령이며 독립 callable ABI가 아니다.
fragment C가 parent의 긴 후속 문맥을 재구성하면서 인자를 생략하거나 warning을 반복하는 것을
새 함수 구현이나 별도 원본 오류로 세지 않는다. stack adjustment와 다음 head만 대조했다.

zinit의 부분 필드 쓰기·기존 flags 보존, backing-space selector의 no-match 경로,
zone 할당의 no-scrub는 실제 원본 동작이다. 이를 decompiler 오류라고 몰거나
선의의 zero-fill/포인터 초기화를 C 해석에 추가하지 않는다.

[결과](README.md) · [명령 증거](object-lifetime-evidence.json)
