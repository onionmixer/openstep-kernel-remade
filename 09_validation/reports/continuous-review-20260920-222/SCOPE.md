# 범위

원본 x86 `mach_kernel`의 SHA-256과 full-pass5의 `functions.json`·`coverage.json`만
사용했다. Python은 `__text` VA `0x001012d0`, 크기 851,436바이트의 반열린 범위에
각 함수 본문, 정의 데이터, undefined 범위를 교집합으로 제한한 뒤 합집합 길이와
쌍별 겹침을 계산했다.

이 검토는 원본 실행, QEMU, 재부팅, 참조 소스, kernel 구현·빌드, Ghidra DB 변경,
함수 의미 또는 모든 동적 간접 진입점 분석을 포함하지 않는다.
