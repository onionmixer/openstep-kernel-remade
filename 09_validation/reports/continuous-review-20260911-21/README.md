# 신중한 추가 검토 21 — 페이징 초기화와 주소 공간 해석

## 판정

분석 전체의 완전성은 아직 입증되지 않았다. 이번 검토는 기존 보고서 20의
세그먼트 주소 차이에 실제 초기 페이지 테이블을 연결하고, 부팅에 필수인
CPU 상태 변경 및 할당 함수 반환값의 디컴파일 누락을 구체화했다.
원본 커널의 결함을 발견했다는 뜻은 아니다.

| 검토 항목 | 결과 |
|---|---|
| 원본 `_pmap_bootstrap`와 정상 경로 callees | 합성 부팅 입력 4조건, 원본 명령 실행 2,006,438회, 고유 명령 380개 |
| 낮은/높은 선형 주소의 페이지 테이블 대조 | 40쌍 모두 같은 물리 주소, supervisor/writable 확인 |
| 페이징 활성화 후 높은 GDTR를 사용한 REP | 원본 REP 6곳, 총 96시험 통과 |
| CR0/CR3 관련 원본 명령 대조 | 10곳 검토: high-pcode 없음 9곳, phi 연산만 있음 1곳 |
| `_alloc_pages` 반환값 | 원본은 이전 할당 포인터를 EAX로 반환; 24시험 일치, 기존 C는 `void` |
| 원본 명령 패치 / 호출 mock | 없음 / 없음 |

모든 수치·주소·비트 연산·해시는 Python으로 계산했다. 실행은 Unicorn의
조건부 모델 결과이며 실기기 부팅 검증이 아니다.

## 원본에서 확인한 페이징 동작

`_pmap_bootstrap` (`0x0018eee8`)는 conventional memory에서 page directory를
할당하고 root 포인터를 directory 내부의 `0xc00` 오프셋으로 이동한다.
해당 root를 기준으로 초기 물리 메모리 매핑과 추가 비활성 매핑을 만든다.
이후 높은 영역 directory entry들을 낮은 영역으로 복사한다.

원본 꼬리 부분은 다음 상태 변경을 포함한다.

```text
0018f2a3  MOV EBX,CR0
...       directory entry 복사와 directory 물리 주소 계산
0018f317  MOV [EAX+4],EDX
0018f31a  MOV CR3,EDX
0018f31d  OR EBX,0x80010000
0018f323  MOV CR0,EBX
```

합성 입력은 물리 메모리 끝 `0x800000`/`0xc00000`, conventional 할당 시작
`0x20000`/`0x31000`, VM page size `0x2000`, page mask `0x1fff`,
페이지 테이블 할당 시작 `0x400000`, `_pmap_initialized == 0`이다.
부팅 입력 및 물리 RAM은 시험용으로 설정했지만, `_alloc_cnvmem`,
`_alloc_pages`, `FUN_0018ecc0`, `_bzero`, `_memset`는 호출을 대체하지 않고
원본 코드를 실행했다. 원본 `_gdt_init`도 사전 실행했다.

네 조건 모두 CR0는 `0x11`에서 `0x80010011`로 바뀌었고, CR3와 pmap에
저장된 directory 물리 주소가 일치했다. callee-saved 레지스터와 반환 후
스택도 확인했다. 실행된 bootstrap/callee 명령은 원본 바이트와 대조했다.

독립 Python two-level page walker는 GDT, page directory, 코드 인접 영역,
스택, 복사 버퍼 및 물리 메모리 끝 경계 등을 검사했다. `offset`과
`0xc0000000 + offset`은 선택한 present 페이지에서 같은 물리 주소를 가리켰다.
물리 메모리 끝부터 시작하는 비활성 페이지는 present가 아니었고,
`0xa0000`/`0x100000` 경계의 PTE bit 3 설정도 확인했다.
directory 비교에서는 하드웨어 모델이 갱신할 수 있는 accessed bit를 제외했다.

## 이전 세그먼트 시험의 해석을 좁힘

[보고서 20](../continuous-review-20260911-20/README.md)은 페이징이 꺼진 조건에서
ES base가 `0xc0000000`이면 원본 REP의 선형 목적지와 flat raw-pcode 목적지가
다르다는 사실을 확인했다. 그 자체로 커널의 실제 복사 오류를 뜻하지 않았다.

이번에는 원본 bootstrap이 페이징을 켜고 반환한 뒤, 원본 `_i386_init`의
GDT 재설정 호출 구간을 실행했다. GDTR base가 `0xc0000000 + gdt`로 바뀐 상태에서
ES selector `0x10`을 로드하고 원본 MOV FS 명령으로 FS selector `0x50`을 로드했다.
그 상태의 REP 6곳을 count `1`/`3`, DF `0`/`1`로 실행했다.

96시험 모두 높은 선형 목적지가 페이지 테이블을 통해 낮은 물리 목적지로
연결되어 예상 바이트가 복사되었다. ECX, ESI, EDI의 최종 값도 확인했다.
따라서 **이 초기 매핑 조건에서는 주소 차이가 물리 복사 결과의 차이로 이어지지 않는다.**
다만 raw-pcode를 전체 커널에서 어떻게 해석해야 하는지에 관한 전역적인
주소 공간 규약까지 입증한 것은 아니다. REP 단일 구간 시험이지 전체
`copyin`/`copyinmsg` 호출과 예외 복구 시험도 아니다.

## 디컴파일에서 빠진 내용

이전 보고서 18의 독립 Ghidra 추출을 재사용하고 해시로 입력을 고정했다.
그때의 `_pmap_bootstrap` C와 canonical C는 정규화 후 같다.
원본 CR0 읽기, 최종 CR3/CR0 쓰기 및 OR 명령의 raw-pcode는 존재하지만
대응 high-pcode에는 없다. 함수 전체에서도 명시적 CR0/CR3 varnode를 쓰는
연산을 찾지 못했다. 즉 기존 C만으로는 페이징 활성화 부작용을 복원할 수 없다.
CR3 재로드의 TLB 효과 전체를 이번 실행으로 검증했다는 뜻은 아니다.

`0x0018f0ae`에는 phi/MULTIEQUAL 연산이 있으므로 “관련 주소에 high 연산이
전혀 없다”라고 일괄 판정하면 부정확하다. 검사 스크립트의 최초 가정이
여기서 실패했고, 실제 추출을 확인하여 phi-only와 완전 부재를 분리했다.
이는 원본 코드의 실행 실패가 아니다.

또한 `_alloc_pages` (`0x0018adf0`)의 기존 C 선언은
`void _alloc_pages(int param_1)`이다. 하지만 원본은 기존 할당 포인터를
EAX에 남기고 전역 포인터만 증가시킨다. 알려진 명령 전체를 재검색한 결과
직접 호출 1곳 (`0x0018ed04`)은 반환 EAX를 저장하고 NULL 여부를 검사한다.
정상 초기화 조건에서 이전 포인터 반환과 크기 반올림은 24시험 모두 일치했다.
포인터 wraparound 시험은 산술 의미 검사이며 실제 사용 가능한 할당의 증거가 아니다.
정확한 포인터 typedef/인자 signedness, 간접 호출 및 panic 경로는 별도 과제다.

로컬 Darwin 참조 `machdep/i386/pmap.c`의 `pmap_enable_pg`에도 double mapping,
CR3 설치, CR0 PG/WP 설정 구조가 있다. 이는 비교 자료이며 해당 소스가
OPENSTEP 원본과 동일하다는 증거로 사용하지 않았다.

## 남은 검증과 보존 범위

- 비디오 매핑 분기와 다른 부팅 메모리 구성, 할당 실패는 미검증이다.
- 전체 `_i386_init`, 최종 far jump, 실제 펌웨어·인터럽트·태스크 전환은 실행하지 않았다.
- 이후 사용자 pmap에서 낮은 선형 주소가 다른 물리 페이지를 가리킬 때의 copy/FS 규약이 남아 있다.
- 보고서 20의 POP FS 출처 및 alias를 통한 descriptor 쓰기 문제도 미해결이다.
- Ghidra/IDA 원본 DB, 기존 보고서, 원본 바이너리와 `07_kernel`은 변경하지 않았다.
- GCC 2.7 구현·컴파일·부팅 검증은 수행하지 않았다. 전체 분석 완료로 판정하지 않는다.

## 재현과 증거

프로젝트 루트에서 실행한다.

```sh
python3 -B 09_validation/reports/continuous-review-20260911-21/paging_review.py
python3 -B 09_validation/reports/continuous-review-20260911-21/representation_review.py
python3 -B 09_validation/reports/continuous-review-20260911-21/verify_artifacts.py
```

[페이징 실행 코드](paging_review.py), [페이징 결과](paging-review.json),
[표현·반환값 검토 코드](representation_review.py), [표현 검토 결과](representation-review.json),
[보존 검사 코드](verify_artifacts.py), [입력 해시](input-hashes.json),
[보존 검사 결과](verification.json), [산출물 해시](artifact-hashes.json).
