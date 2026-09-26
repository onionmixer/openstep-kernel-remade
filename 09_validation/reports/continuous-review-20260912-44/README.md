# NXMap callback의 원본 정적 계약

NXMap prototype 데이터가 가리키는 callback 본문과 실제 호출자의 인자 준비·반환값 사용을 대조했다. **정적 계약 근거를 추가한 단계이며 전체 함수 의미 검증이나 동적 실행 완료가 아니다.**

## callback별 확인 결과

아래 인자는 원본 호출자가 stack에 준비하는 순서다. 정확한 원본 C typedef를 확보했다는 뜻은 아니다.

| 원본 entry | 관찰된 호출 인자 | 원본 본문의 동작 |
|---|---|---|
| `1cca20` pointer hash | table, key | table을 읽지 않고 32-bit key와 그 상위 word의 XOR를 EAX로 반환 |
| `1cca98` pointer equality | table, stored key, query key | key 값의 동등 비교; EAX는 정확히 0 또는 1 |
| `1ccb3c` no-free | table, key, value | 인자를 읽지 않고 반환; EAX를 0으로 만들지 않음 |
| `1cca80` object hash | table, key | key에 `hash` 메시지를 보내고 EAX를 그대로 전달 |
| `1ccb1c` object equality | table, stored key, query key | stored key에 `isEqual:` 메시지로 query key 전달; 반환 AL을 부호 확장하여 EAX로 반환 |
| `1ccb44` object free | table, key, value | key에 `free` 메시지 전달; value 인자는 직접 읽지 않음 |

`NXResetMapTable`의 `1cc14d..1cc158`에서 free callback에 value, key, table 순으로 PUSH하는 것을 확인했다. 따라서 `__mapNoFree(void)`나 object-free의 일부 인자만 표시한 디컴파일 결과를 callback typedef의 전체 인자 개수로 사용하면 안 된다. no-free의 EAX는 함수 자체가 정의하지 않으며 호출자가 반환값을 소비하지 않는다.

object-free wrapper에는 value에 별도로 메시지를 보내는 코드가 없다. 이는 method 내부 부작용이나 key/value가 같은 객체인 경우까지 포함하여 value가 절대로 해제되지 않는다는 증명이 아니다. 실제 객체 소유권·method 동작은 별도 검증 대상이다.

## `void` hash와 실제 반환값 사용의 불일치

Ghidra는 `__mapObjectHash`를 `void`로 출력했다. 그러나 원본 `1cca8e`의 메시지 호출 뒤 epilogue는 EAX를 바꾸지 않으며, `NXMapMember`의 `1cc21b` 호출 바로 뒤 `1cc21d`는 EAX를 EBX에 저장해 hash 계산에 사용한다. `NXMapGet`의 `1cc313..1cc315`도 동일한 반환값 소비를 보인다.

따라서 이 wrapper를 반환값 없는 복원 함수로 채택해서는 안 된다. 다만 이것만으로 원본 typedef의 모든 타입·수식자나 GCC 2.7에서의 정확한 함수 포인터 호출 규약을 확정하지 않는다. DB의 함수 prototype도 변경하지 않았다.

## equality의 반환 폭과 호출 방향

`1ccb33`은 `MOVSX EAX,AL`이다. 결과를 0/1로 정규화하는 명령이 아니다. AL의 가능한 값을 Python으로 계산하면 다음 구분이 생긴다.

| AL | 부호 확장한 정수 | lookup의 nonzero 판정 |
|---|---:|---|
| `00` | 0 | 거짓 |
| `01` | 1 | 참 |
| `7f` | 127 | 참 |
| `80` | -128 | 참 |
| `ff` | -1 | 참 |

AL 값 256개에 대한 계산은 부호 확장 결과의 nonzero 여부가 원래 AL의 nonzero 여부와 같음을 확인했다. **이는 수학적 명령 해석 점검이며 해당 값들을 반환하는 실제 객체를 실행한 시험이 아니다.** 로컬 `objc.h`는 BOOL을 char로 선언하지만, 이번 부호 확장의 직접 근거는 원본 MOVSX다.

lookup은 저장 key와 query key가 pointer로 같으면 callback을 생략하고 참으로 처리한다. 다를 때에는 callback에 `(table, stored_key, query_key)`를 전달한다. object callback은 stored key를 receiver로 사용한다. 사용자 method의 대칭성을 별도로 검증하지 않고 receiver와 인자를 뒤바꾸어서는 안 된다.

## hash callback과 bucket 선택은 별개

pointer hash 본문은 `MOVZX EAX,word [EBP+0xe]`와 `XOR EAX,[EBP+0xc]`이다. little-endian 인자 배치에서 이는 다음의 32-bit 비트 연산과 대응한다.

`h = key XOR (key >> 16)`

lookup caller는 callback 결과를 다시 변환한다. 원본 shift·subtract·add 순서를 Python으로 계산하여 다음 식과 대조했다.

`t = (h & 0xffff) XOR (h >> 16)`

`mixed = (h + 65521 * t) modulo 2^32`

그 뒤 EDX를 0으로 만들고 unsigned DIV를 수행하여 나머지를 bucket index로 사용한다. callback 결과를 곧바로 bucket index로 쓰거나, 32-bit wrap을 생략한 무제한 정수 식으로 바꾸면 동일 동작을 보장할 수 없다. 경계 key 예시 7개를 계산했으나 전체 lookup 실행이나 hash 충돌·삭제·재배치 검증은 아니다. divisor인 bucket 수의 유효성 역시 caller 생성 경로에서 확인해야 한다.

## selector와 nil의 제한적 근거

원본 이미지의 selector 슬롯을 직접 읽어 `1f9d60→2072ec→hash`, `1f9838→205ea8→isEqual:`, `1f921c→201920→free`를 확인했다. 이들은 이미지 초기 값이며 런타임 selector 등록·재배치를 실행해 확인한 값은 아니다.

저장된 `objc_msgSend` 본문에는 receiver가 0인 경우 EAX=0으로 RET하는 `1ce9d6..1ce9da` 경로가 있다. 이는 해당 branch의 정적 사실이다. 비NULL 객체의 method cache·lookup·forwarding·lock·method 구현까지 이번에 검증한 것으로 확대하지 않는다.

## 자료와 보존

callback 본문 6개와 caller/dispatcher 문맥 4개의 원본 명령 363개, 본문 바이트 881개를 대조했다. selector 슬롯 3개, hash 계산 예시 7개, AL 부호 확장 계산 256개를 [진단 근거](callback-evidence.json)에 보존했다. 이 수치는 Python 집계 결과다.

근거 입력 38개와 이전 보존 파일 576개의 해시를 확인했다. Ghidra 스킬로 보존 ASM/C/참조 자료를 읽기 전용으로 사용했고 원본·DB·export·이전 보고서를 수정하지 않았다. 독립 교차검토 미수신 조건은 유지했으며 새 실행·검증 프로그램, 복원 C 코드 또는 GCC 2.7 빌드는 작성·실행하지 않았다.

[검토 범위](SCOPE.md) · [원본 및 계산 근거](callback-evidence.json) · [보존 목록](preservation.json) · [남은 분석](OPEN_ITEMS.md)
