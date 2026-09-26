# 359차 정적 검토 — full-pass5 분석 manifest와 기준 바이너리 대조

full-pass5 manifest는 기준 mach_kernel SHA-256과 일치하는 binary_sha256, Ghidra 12.1, x86:LE:32:default 언어, gcc compiler spec, image base 0x00100000 및 분석 옵션 기록을 가진다.

이 manifest는 분석 프로젝트·loader·compiler-spec·분석 설정의 재현 기록이다. 여기의 gcc compiler spec은 분석 도구 설정이며 OPENSTEP ABI, 원래 컴파일러 또는 GCC 2.7 호환성의 확정 근거가 아니다.
