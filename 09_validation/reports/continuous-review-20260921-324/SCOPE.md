# 범위

원본 OPENSTEP x86 binary에서 생성된 full-pass5 warning export, 원본 바이트와 238·249·250·251차 증거·checkpoint만 사용했다. Python으로 warning record·instance·entry, raw indirect JMP bytes와 각 checkpoint pass 상태를 재검증했다.

범위는 Treating indirect jump as call warning coverage mapping이다. warning 정확성, indirect target, ABI, parameter storage, return convention 및 runtime 상태는 범위 밖이다.
