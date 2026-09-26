# ObjC module 등록·해제 순서와 callback ABI

report51의 caller 주변 검토를 module 등록·해제 본문 전체와 직접 helper로 확장했다. **정적 호출·store·stack 분석이며 실제 모듈을 로드/언로드한 결과 또는 모든 callee의 의미 검증 완료가 아니다.**

## 중요한 callback 인자 누락

등록 callback은 class 항목에서는 `(class, 0)`, category 항목에서는 `(objc_getClass(category.class_name), category)`로 호출된다. 해제 callback도 같은 인자 형태를 사용한다. 등록의 `1ce6cb`, 해제의 `1ce7a0`에서 먼저 push한 category pointer는 getClass 호출 뒤에도 stack에 남고, 반환 Class를 추가로 push하여 callback을 호출한다(`1ce6e3`, `1ce7b1`).

디컴파일은 category를 getClass의 추가 인자처럼 표시하고 callback은 단일 인자처럼 보여준다. 원본의 `ADD ESP,4`는 getClass용 name 인자만 정리하며 category 인자는 유지된다. 그러므로 이 C 표현을 그대로 복원하면 callback ABI를 잃는다. class 경로 `1ce63b`/`1ce81a`와 함께 stack을 확인했으며 실제 callback 실행이나 GCC 2.7 호출 시험은 하지 않았다.

## 등록 사전 검사의 미해결 인자 문제

`objc_registerModule` `1ce0cc`는 `__OBJC,__module_info`를 읽고 class 정의들을 사전 순회한다. `1ce123`에서 `symtab.defs[i]` 값을 읽어 `objc_lookUpClass`(`1ce128`)에 그대로 전달한다. 여기에는 class의 name 위치 `+0x8`을 읽는 명령이 없다. nonzero 조회가 있으면 나중에 1을 반환하고, 없으면 header 추가부터 실제 등록을 진행한다.

직접 callee `objc_lookUpClass` `1ced70`는 인자를 stack의 pseudo class record `+0x8` 위치에 저장한 뒤 class hash table로 Get을 호출한다. 기본 class prototype 초기 기록 `1e560c`의 hash/equality는 record `+0x8`을 **문자열 pointer**로 읽는다. 로컬 헤더 역시 lookup의 인자를 `const char *name`으로 선언한다.

따라서 현재 명령열을 단순히 “올바른 class-name 중복 검사를 마쳤다”로 요약할 수 없다. 이후 등록 pass는 같은 defs 값을 class 구조체 pointer로 사용한다. 실제 로드 caller·module 데이터의 전처리·class table 상태를 확인해야 할 **인자/출처 불일치**로 남긴다. 원본 버그나 실제 실패가 관찰되었다고 단정하거나 name dereference를 임의로 추가하지 않았다. lookup 함수의 `void` 디컴파일 역시 실제 EAX 반환과 구분한다.

## module/section 순회 전제

원본 module record는 version `+0`, size `+4`, symtab `+0xc`를 사용하며 record pointer에 size를 더하고 section remaining에서 size를 뺀다. class/category 수는 symtab의 `+8`/`+a`에서 unsigned word로 확장하고 defs는 `+0xc`에서 읽는다. 로컬 `objc-runtime.h`의 non-PDO 형태와 대응하지만 최종 preprocessor 설정이나 GCC layout 검증을 확정한 것은 아니다.

각 pass는 pointer/remaining의 0 여부를 검사하지만 이 본문에는 매 record마다 `size > 0`, 최소 구조체 길이, `size <= remaining`을 확인하는 분기가 없다. zero size에서는 진행하지 않거나 큰 size에서 remaining이 DWORD wrap하는 산술 가능성이 있다. 이는 잘못된 metadata를 실행한 증거가 아니며 입력 검증 책임이 caller/loader에 있는지 확인해야 한다.

섹션 길이는 `__message_refs`/`__cls_refs`에서 DWORD 단위, `__protocol`에서 `0x14`, `__string_object`에서 `0xc` 단위로 몫을 사용한다. 나머지 바이트가 있다고 이 함수가 별도 오류를 반환하는 분기는 보이지 않는다. Python으로 stride와 tail 계산을 남겼다.

## 등록의 실제 pass 순서

사전 조회가 nonzero인 경로는 1로 끝난다. 그 외 정상적으로 돌아오는 경로에서는 다음 순서로 진행하고 마지막에 0을 반환한다. 이 0이 모든 callee의 실패·의미 검증까지 성공했다는 보장은 아니다.

1. `__objc_addHeader(header, 0)` 후 `__string_object`의 각 항목 첫 DWORD를 `NXConstantString` Class로 설정한다. 이 helper `1ce058`은 객체당 `0xc` stride를 사용한다.
2. `__message_refs` selector를 수정하고, protocol의 instance/class method description name들을 수정한다. 이후 `Protocol`에 `_fixup:numElements:` 메시지를 보낸다(`1ce2a1`). 실제 method 구현은 이번 범위 밖이다.
3. 모든 module의 class들을 `objc_addClass`로 등록한다. 다음 전체 pass에서 class/metaclass method name들을 수정하고 관계 설치 helper를 호출한다(`1ce3cf`).
4. category의 instance/class method name들을 수정한 뒤 `__objc_add_category`를 호출한다(`1ce51e`). version 1 module의 이전 selector-ref 배열도 별도 pass에서 수정한다.
5. `__cls_refs`를 getClass 반환으로 치환한다(`1ce5e4`, `1ce5e9`). 이후 모든 class에 외부 callback과 finishLoading helper를 호출하고, 다음 pass에서 모든 category에 외부 callback과 finishLoading helper를 호출한다.

selector patch는 저장된 pointer와 `sel_registerName`의 EAX가 다를 때만 store한다. 각 경로의 위치와 배치는 다음과 같다.

| call 주소 | selector 저장 위치 |
|---|---|
| `1ce1b4` | message-ref DWORD 배열 |
| `1ce21f` | protocol instance description의 name, header `+4`와 entry stride `8` |
| `1ce257` | protocol class description의 name, 같은 배치 |
| `1ce375` | class method list의 name, header `+8`와 entry stride `0xc` |
| `1ce3b1` | metaclass method list의 name, 같은 배치 |
| `1ce4c2` | category instance method name |
| `1ce4f6` | category class method name |
| `1ce590` | version 1 module의 이전 selector-ref 배열 |

class 관계 설치 후 metaclass version이 3 또는 4이고 class protocol pointer가 nonzero이면 class/metaclass의 protocol pointer에서 4를 뺀다. version 3에서 조정 후에도 class pointer가 nonzero이면 로그 후 양쪽 pointer를 0으로 만든다. 정확한 전처리/구형 metadata 형태와 callee의 version 설정을 확인하기 전 이를 모든 버전 공통 처리로 일반화하지 않는다.

등록이 여러 pass로 metadata와 전역 table을 수정하므로 하나의 원자적 transaction으로 요약하지 않는다. 직접 본문에는 오류 시 이전 selector/class/header 상태를 모두 복구하는 공통 rollback이 없다. callback, message dispatch, 할당·관계 설치 등의 실패/재진입은 별도 의무다.

## lifecycle helper는 일반 메시지 전송과 다르다

class finish/start helper는 metaclass의 `+0x1c`에서 시작하는 연결 목록을 따라 **마지막 method list**를 고른다(`1cdf30`). 그 list에서 selector pointer가 같은 method의 IMP를 찾고 직접 호출한다. category helper는 category의 class-method list를 사용하고 target class를 이름으로 조회한다. 따라서 이를 아무 method나 상속 검색하는 일반 objc_msgSend로 대체할 근거가 없다.

직접 method-list lookup `1cd52c`는 header `+4`의 count, `+8`에서 시작하는 method, stride `0xc`, entry `+8`의 IMP를 사용한다. 이름 문자열 strcmp가 아니라 selector pointer 비교다. count loop는 signed 감소 분기를 사용하며 모든 unsigned count를 정상 지원한다고 가정하지 않는다.

초기 selector 문자열을 원본에서 읽어 `finishLoading:`과 `startUnloading`임을 확인했다. finish 호출 인자는 `(class, selector, header)`, start 호출 인자는 `(class, selector)`다. 이 IMP들의 실제 구현과 side effect는 아직 검증하지 않았다.

로컬 `objc-class.h`에는 `Release3CompatibilityBuild`에 따라 linked methods와 methodLists pointer-array의 선언이 달라진다. 이번 helper의 연결 목록 사용만으로 전체 runtime의 빌드 매크로를 확정하지 않는다. flags/변환/다른 접근 경로를 함께 확인해야 한다.

## 해제는 등록을 그대로 뒤집지 않는다

`objc_unregisterModule` `1ce740`는 먼저 모든 category의 외부 callback과 startUnloading helper를 호출한다. 그 뒤 모든 class의 외부 callback과 startUnloading helper를 호출한다. 이어 category 제거 pass, class 제거 pass를 진행한다. 즉 lifecycle callback은 해당 제거 호출들보다 앞선다.

이후 `__meth_var_names` 섹션의 `[address, address+size)`로 selector unload를 호출하고(`1ce909`), `__selector_strs`에도 같은 형태로 호출한다(`1ce936`). 마지막으로 `__objc_removeHeader`(`1ce942`)를 호출한다. [report51](../continuous-review-20260912-51/README.md)의 unload는 주소 범위 안의 base-table node를 unlink할 뿐 문자열 자체를 free하지 않는다.

이 본문은 selector patch를 원래 name pointer로 되돌리지 않고, Protocol fixup·constant-string isa·class-ref store도 역변환하지 않는다. 모듈 메모리의 실제 해제/재사용, 캐시 flush와 class/category 제거 helper의 내부 처리는 아직 별도 확인 대상이다. 여기서 구조상 callback 순서를 확인한 것을 안전한 전체 unload 완료로 확대하지 않는다.

## 실제 외부 caller와 다음 검증

metadata 직접 call을 원본에서 확인한 결과 등록은 `kern_serv_load_objc`의 `16c980`과 `FUN_00194890`의 `1948d9`, 해제는 `kern_serv_shutdown`의 `16cca0`에 연결된다. 이 caller들의 module 주소·자료 출처·잠금·실패 반환 소비와 실제 메모리 수명을 다음에 확인해야 한다. 간접 호출은 이 선택 검색의 범위 밖이다.

본문 13개에서 명령 경계 1,066개·본문 바이트 2,832개와 직접 분기 목적지를 대조했다. callback stack 구간과 section/record 산술은 별도 JSON에 있다. 입력 해시 46개와 이전 보존 파일 해시 624개가 일치했다.

Ghidra 스킬의 읽기 전용 절차로 디컴파일 인자 누락과 원본 stack·metadata 전제를 분리했다. 모든 계산은 Python이며 원본·reference·DB/export·이전 보고서를 수정하지 않았다. 독립 계획 검토 미수신 상태를 유지하고 신규 실행/검증 프로그램·복원 코드·GCC 2.7 빌드를 진행하지 않았다.

[원본·산술 증거](modules-evidence.json) · [보존 목록](preservation.json) · [범위](SCOPE.md) · [남은 분석](OPEN_ITEMS.md)
