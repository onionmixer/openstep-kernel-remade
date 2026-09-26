# 101차 범위와 검토 절차

100차의 PCB/K 수명 미완료 항목 중 생성, 사용자 상태 복제, 참조 감소, 종료와 reaper를
OPENSTEP 원본만으로 연결한다. `01_resources`, `07_kernel`, 다른 프로젝트 소스와
외부 문헌은 열거나 근거로 사용하지 않는다. 이전 보고서의 범위 밖 보존 항목도 다시 열지 않는다.

## 진행 절차

1. 100차 checkpoint, 범위 내 입력 및 보존 자료의 해시를 재검증한다.
2. 선택한 원본 본문과 기존 ASM/C/metadata를 대조하고 직접 호출·정리 순서를 추적한다.
3. 실제 스택 인자, DWORD/WORD/BYTE 폭, 분기 표, REP 복사 구간을 Python으로 확인한다.
4. 지역적 no-write/no-free 사실과 실제 누수·수명 안전성의 전체 증명을 구분한다.
5. 직접 caller 모집단을 manifest와 대조하되 alias/간접 호출의 완전성으로 확장하지 않는다.
6. 신규 보고서·증거만 저장하고 원본/기존 보고서 보존과 신규 산출물을 다시 검증한다.

모든 계산은 Python이다. Ghidra 스킬의 대조 절차를 기존 export에 적용한다.
live Ghidra/IDA DB 변경, 실행·에뮬레이션, 복원·구현·빌드·포팅은 하지 않는다.
새 독립 Codex 계획 검토를 받지 않았다. 앞선 검토 실패를 통과로 표시하거나 우회하지 않는다.

## 검증 분모

일반 본문 26개, 분석 fragment 6개, 총 32개 본문의 명령 2,058개와 6,289바이트다.
직접 분기 215개, 직접 CALL 164개, 간접 전이 1개를 재디코드했다.
핵심 명령 215개, register-only spin 45개, reaper table 14개 항목,
thread template 명시적 MOV 33개를 기록했다. 입력 102개와 기존 보존 경로 901개를 검사한다.
C warning 13행은 fragment 문맥을 포함하므로 독립 결함 수가 아니다.
fragment는 panic 뒤 ADD ESP,4의 3바이트 원본과 fallthrough를 확인한 것이며,
fragment C 전체를 독립 함수의 의미로 인정하지 않는다.

일반 본문은 kernel_task_create, task_create/deallocate/reference/terminate,
thread_init/create/deallocate/deallocate_interrupt/reference/terminate/force_terminate,
reaper_thread_continue, pcb_module_init/init/common_init, thread_user_state/dup,
pcb_terminate/common_terminate, fp_terminate, PCdestroy, pmap_create, vm_map_create,
task_hold와 task_dowait다. 정확한 이름·주소·범위는 JSON에 보존한다.

ASM 모집단은 full-pass5/functions의 5,253개 파일이며 각각 기존 manifest와 일치한다.
모집단 SHA-256은 742617851f014a94309d47296900fc5e27b5ad5a862f588590559fe5f334471d다.
지정한 직접 CALL target의 hit 25개만 원본에서 재디코드했다.
이는 전체 lifecycle/alias writer/함수 밖 코드 또는 모든 caller의 의미 분석이 아니다.

파일 zero template, common thread template, BSS FP owner를 구분한다.
file-backed가 아닌 영역을 raw offset의 임의 바이트로 읽어 초기값을 만들지 않는다.
정적 참조 수/부호/복사 산식은 실행·동시성 실험이 아니다.

[결과](README.md) · [증거](object-lifetime-evidence.json) · [미완료](OPEN_ITEMS.md)
