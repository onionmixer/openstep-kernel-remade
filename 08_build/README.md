# 빌드 환경과 산출물

최종 컴파일러는 **GCC 2.7**이다. [호환 기준](GCC27_COMPATIBILITY.md)에 따라
정확한 패치 버전/NeXT 수정판·target을 고정하고 전체 커널 컴파일·링크를 검증한다.

- `configs/`: architecture/target별 빌드 명세, compiler/MIG/linker 옵션.
- `toolchains/`: 고정 버전 도구의 로컬 설치 위치.
- `logs/`: 실행 명령, 환경, 시작/종료 시각과 exit status.
- `artifacts/<arch>/<run-id>/`: object, map, 커널, SHA-256 manifest.

아직 빌드 명령은 확정하지 않았다. `environment.json`은 준비 당시 PATH의 도구 목록이며
OPENSTEP 커널을 빌드할 수 있다는 검증 결과가 아니다.
P3에서 freestanding C/assembly, 구형 Objective-C, Mach-O relocation/link,
MIG message layout, generated headers를 각각 확인한다.
makefile 복원 후 소스 revision·toolchain·config·출력 해시를 한 run manifest로 묶는다.
