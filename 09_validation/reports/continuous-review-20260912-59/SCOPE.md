# 송신 권한 lookup/copyin의 원본 계약

이전 보고서 58의 미완료 항목에서 right lookup, entry lookup, header/body right copyin, receive clear를 원본 본문으로 연결한다. 권한 이전과 복제의 차이, entry 소멸/죽은 이름 변환, 락 해제 순서 및 Ghidra 표현 차이를 기록한다.

읽기 중 발견한 락 대기 분기의 register 재검사 여부는 원본 바이트로 확인한다. 이전 보고서 57에서 검토한 함수의 같은 패턴도 제한적으로 확인하여 과거의 lock 요약이 경합 성공의 증명으로 오해되지 않도록 한다. 전체 커널의 락 전수 분석이나 runtime 패치 유무 확인을 대신하지 않는다.

계산은 모두 Python으로 수행한다. Ghidra 스킬을 보존 export에 읽기 전용으로 적용한다. 신규 독립 계획 검토 미확보 상태이며 새 검증 프로그램·동적 실행·DB/원본/07_kernel 수정·GCC 2.7 실빌드는 하지 않는다. 실패한 독립 검토를 재요청하거나 우회하지 않는다.
