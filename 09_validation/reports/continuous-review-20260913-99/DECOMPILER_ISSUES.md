# 99차 C 표현과 원본 계약의 차이

아래는 선택한 원본 명령과 기존 C export 사이의 한정된 비교다.
디컴파일 전체 실패 수, 원본 결함 수 또는 복원 소스 수정 목록이 아니다.

## Objective-C selector의 stack 재사용

`0x1821de`는 range selector를 먼저 PUSH한다. 그 위에 index, objectAt: selector,
array receiver를 쌓아 `0x1821e8`에서 objc_msgSend를 호출한다.
`0x1821ed`의 ADD ESP,0xc는 위 인자만 제거하여 range selector를 남긴다.
`0x1821f0`에서 반환 receiver를 PUSH하고 `0x1821f1`에서 다시 objc_msgSend를 호출한다.

C는 range를 첫 objectAt: 호출의 추가 인자로 붙이고 다음 호출에서는 selector를 생략한다.
원본은 다음 호출을 위해 아래쪽 stack slot을 미리 준비한 구조다.
selector 문자열과 file-backed 참조를 대조했지만 실제 method binding/구현은 미확인이다.

이어 EDX와 EAX가 각각 count/start로 PUSH되어 task_map_io_ports에 전달된다.
C의 넓은 임시값 표기만으로 물리적 DWORD 인자를 합치거나 formal struct ABI를 확정하지 않는다.
caller는 task_map_io_ports의 반환값을 검사하지 않고 최종 EAX=0으로 돌아온다.

## zalloc의 void C와 EAX 전달

`0x16b790` wrapper는 인자를 준비해 `0x16b799`에서 `0x16b364`를 호출한다.
이후 MOV ESP,EBP / POP EBP / RET만 있어 callee EAX를 유지한다.
PCB 초기화와 kalloc caller는 그 EAX를 소비한다. C의 void 표기는 반환 레지스터가
없다는 근거가 아니다. 반대로 아직 선택하지 않은 하위 allocator의 성공/실패 계약도 확정하지 않는다.

## kmem_alloc_wired의 폭과 오류 경로

C의 undefined1 반환 추론과 별개로 원본 EAX를 추적하면 지역 반환은 0/1/6이다.
vm_map_find 실패는 SETNZ AL 및 AND EAX,0xff로 1로 정규화한다.
backing helper 실패는 map 삭제 경로 뒤 EAX=6이다. 성공 때만 output pointer를 쓴다.
값들이 BYTE에 들어간다고 해서 formal ABI 전체를 BYTE 반환으로 확정하지 않는다.

## 복사·fill의 숨은 전제

memcpy에는 CLD/STD가 없다. C의 전진 pointer loop를 DF 보장의 증거로 쓰지 않는다.
signed 길이 비교는 high-bit DWORD를 짧은 REP 경로로 보낼 수 있으므로 임의 길이의
표준 memcpy 의미로 정규화하지 않는다. 실제 길이 0의 REP는 data access를 하지 않는다.

memset은 param2를 BYTE로 먼저 제한하지 않고 DWORD shift/OR로 pattern을 만든다.
bitmap caller의 0xff는 원본 산식으로 확인했지만 모든 int fill 값의 표준 의미는 주장하지 않는다.
bitmap clear의 ROL DWORD 0xfffffffe/AND BYTE는 bit 0..7의 원본 mask로 확인했다.
이를 C의 signed shift/음수 표현식만으로 이식 가능한 구현이라고 판단하지 않는다.

TSS header/bitmap 복사 사이의 초기화 범위, allocation 실패 검사 부재 및 NULL free 전달은
C 타입을 추측해서 보완하지 않는다. 원본에 존재하는 명령과 하위 계약의 미확인을 구분한다.

[결과](README.md) · [명령·table 증거](object-lifetime-evidence.json) · [후속 항목](OPEN_ITEMS.md)
