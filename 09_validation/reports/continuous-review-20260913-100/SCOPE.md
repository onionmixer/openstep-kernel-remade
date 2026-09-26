# 100차 범위·계획

99차 미완료였던 zone allocator와 초기화 전제를 원본에서 연결한다.
현재 목표는 OPENSTEP 원본 분석뿐이며 외부 소스·01_resources·07_kernel을 참고하지 않는다.
복원·구현·빌드·포팅·실행·에뮬레이션은 하지 않는다. 모든 계산은 Python이다.

## 검토 순서

1. 99차 checkpoint와 범위 내 입력·보존 경로를 새로 해시 대조한다.
2. zone 할당/해제, 초기화, backing-space 선택과 공급의 원본 본문·호출 인자를 읽는다.
3. page-size writer와 초기 pool 공급을 boot call edge에 연결하되 실제 부팅 관찰과 구분한다.
4. 최초 zero-fill과 재사용 시 초기값, NULL·panic·대기·성공 반환을 분리한다.
5. 원본 size table, DWORD 산식, BYTE flags, stack/반환 ABI, branch와 fragment를 검증한다.
6. 신규 분석 보고서와 증거만 저장한 뒤 원본·기존 보고서 보존 및 새 산출물을 재검증한다.

Ghidra 스킬의 함수·호출·제어 흐름 대조 절차를 기존 export와 raw bytes에 적용한다.
live Ghidra/IDA DB는 수정하지 않는다. 새 독립 Codex 계획 검토는 받지 않았으며,
앞선 실패를 통과로 표시하거나 우회 재시도하지 않는다. 구현 코드는 작성하지 않는다.

## 본문과 증거의 분모

일반 본문 25개와 panic fallthrough fragment 9개, 총 34개 본문의
2,213개 명령/6,719바이트를 원본에서 재디코드했다.
직접 분기 275개, 직접 CALL 155개, 간접 JMP 3개, 핵심 명령 202개,
register-only spin 패턴 11개, memset static footprint 경로 46개다.
입력 108개와 기존 보존 경로 894개를 검사했다.
C 경고 33행은 fragment C의 겹치는 문맥도 포함하므로 독립 결함 수가 아니다.

일반 본문은 kalloc_init, zinit, backing-space 선택, zone_bootstrap/zone_init,
zone allocation 본체, zget_space, zalloc/zalloc_noblock/zget, kalloc/kfree/zfree,
extent 선택/추가, kmem_alloc_zone, vm_set_page_size, i386_init, vm_mem_init,
vm_page_startup, setup_main, bzero, vm_alloc_from_regions, memset, start다.
정확한 주소·body 범위·명령은 JSON에 보존한다.

기존 full-pass5 ASM 5,253개를 manifest와 대조한 조사에서 지정한 global displacement
write와 초기화 직접 CALL 17개를 얻었다. 모두 선택 본문에 포함한다.
population hash는 742617851f014a94309d47296900fc5e27b5ad5a862f588590559fe5f334471d다.
이는 alias/bulk/함수 밖 writer와 indirect caller의 완전성 증명이 아니다.

memset은 기존 무조건 CFG 경로의 MOV 목적지 구간을 집계했다.
길이 0..65536과 alignment 산식 524,296개, flags 항등식 512개는 Python 정적 검사다.
CPU 실행, native 메모리 읽기, 동시성 재현, VM fault/권한 검증은 수행하지 않았다.

[결과](README.md) · [원본 증거](object-lifetime-evidence.json) · [남은 분석](OPEN_ITEMS.md)
