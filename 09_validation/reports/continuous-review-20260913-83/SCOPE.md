# 83차 원본 분석 계획 — pager I/O의 위·아래 계약

82차의 [미완료 목록](../continuous-review-20260913-82/OPEN_ITEMS.md)에 따라
원본 pager I/O의 상위 반환 처리와 원본 vnodeops가 가리키는 실제 함수 본문을 연결한다.
OPENSTEP 원본과 파생 ASM/C·심볼·참조만 사용한다. 외부/복원 소스는 열지 않는다.

## 선정 대상

- 상위 dispatch: vm_pager_get, vm_pager_put, vm_pager_has_page.
- 직접 pageout caller: vmp_push, vmp_push_all.
- 원본 표의 I/O targets: NFS 0x1338c0/0x133de4, UFS 0x145848/0x145bbc,
  FIFO 0x139444, SPEC 0x139b14.
- 본문 조사 후 원본 NFS 표 +0x50의 직접 mapping target 0x133884를 추가한다.
  출력 인자와 반환값, read/write block 크기 산술을 연결하기 위한 작은 원본 본문이다.

## 검증 순서와 제한

1. 82차 checkpoint·입력·보존 해시를 현재 파일과 대조한다.
2. 전체 ASM/C를 읽고 원본 file mapping, 명령 길이, 분기/CALL과 핵심 폭·순서를 확인한다.
3. 상위 dispatch의 실제 반환 레지스터, pageout 실패 후 page/object 상태,
   filesystem callback의 credential·잠금·부분 I/O와 오류 반환을 구분한다.
4. 필요한 인접 caller window·원본 표·문자열만 제한적으로 연결한다.
   callback 호출 성공이나 asynchronous write 제출을 저장소 영속성으로 확대하지 않는다.
5. 모든 계산은 Python의 일회성 디코딩·정수·바이트·해시 연산으로 수행한다.
   유한 예시는 native 실행이나 동시성 검증이 아니다.
6. 증거 JSON, 상세 보고서, 미완료 목록, 보존 목록, checkpoint를 저장하고 재검증한다.

독립 계획 교차검토 미수신 상태를 성공으로 바꾸거나 실패한 요청을 재시도/우회하지 않는다.
새 verifier·emulator·커널 구현 코드를 만들지 않는다. 기존 Ghidra export에 스킬의
본문·참조 대조 절차를 적용하며 live DB/UI, 원본/export와 이전 확정 보고서는 변경하지 않는다.
이 국소 검토가 끝나도 전역 함수·경로·경고·실패와 native 분석의 완료를 주장하지 않는다.
