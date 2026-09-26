# compat 송신 입력과 부분 정리 검토

원본 kmsg copyin, 권한 타입 변환, object copyin wrapper, copyinmap, clean_partial의 본문을 읽고 type/length 검증과 실패 시 정리 범위를 연결한다. 정적 본문·분기·테이블을 원본과 대조하며 모든 계산은 Python으로 수행한다.

권한 lookup/copyin의 실제 소유권·락, VM 이동·deallocate, circularity 및 동시 실행은 이 단계에서 전부 검증하지 않는다. 공개 소스의 동일 이름을 원본 ABI나 전체 검증의 대체물로 사용하지 않는다.

Ghidra 스킬을 보존 export의 읽기 전용 검토에 적용한다. 신규 독립 계획 검토가 확보되지 않아 새 실행/검증 프로그램·동적 실행·커널 구현·GCC 2.7 실빌드는 하지 않는다.
