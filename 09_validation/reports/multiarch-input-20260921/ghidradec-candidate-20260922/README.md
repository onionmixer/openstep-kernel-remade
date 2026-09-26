# GhidraDec 후보 런타임 검증

이 디렉터리는 전역 IDA 설치 전에 실시한 격리 빌드 및 런타임 검증 기록이다.
GhidraDec 소스는 커밋 `35afec3d588407de8e2aae5330f26dea857c26bd`로 고정했고, 공식 IDA SDK v9.3 소스는 커밋 `d5db59ab4e9d2ae92038e9520082affd0da6fe20`으로 고정했다.

`assessment.json`과 두 런타임 로그는 m68k와 SPARC 모두에서 플러그인이 로드되고, 각각 Ghidra의 68040 및 SparcV9 32-bit 언어를 선택했음을 보존한다. 두 실행 모두 네이티브 decompiler 요청의 시간 초과로 C 출력을 만들지 못했다.

따라서 이 후보는 현재 Linux IDA 9.3 환경에 전역 설치할 수 없다. 임시 `/tmp` 빌드 산출물은 보존하거나 IDA 설치 디렉터리에 복사하지 않는다. Linux 전송 시간 초과를 해결한 뒤, 원본 DB가 아닌 복사본에서 m68k와 SPARC 각각 최소 한 함수의 C 출력·원본 바이트·big-endian 언어 선택을 다시 검증해야 한다.

이 결과는 원본 커널의 함수 경계, 코드/데이터 구분, ABI 또는 동작의 증거가 아니다. 후속 decompiler 출력도 원본 바이트로 별도 검증하기 전에는 가설로 취급한다.
