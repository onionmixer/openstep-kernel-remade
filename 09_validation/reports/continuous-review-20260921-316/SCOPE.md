# 범위

원본 OPENSTEP x86 binary에서 생성된 full-pass5 warning export 및 원본 바이트로 검증된 각 정적 검토 checkpoint만 사용했다. Python으로 warning record·string instance·fragment, 검토 완료·미완료 entry, checkpoint pass 상태 및 추적 파일 해시를 재계산했다.

범위는 Unknown calling convention warning coverage mapping이다. warning 정확성, ABI, parameter storage, return convention 및 runtime 상태는 범위 밖이다.
