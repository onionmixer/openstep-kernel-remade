# 사용자 공간 시스템 라이브러리 원본 (x86 실기, 분석 준비)

계획: `02_plan/RECONSTRUCTION_PLAN.md` 167 절. 향후 cthreads·libsys(libc) 분석/복원을 위한 원본 보존이며,
아직 분석·복원 결과가 아니다.

- `binaries/` (git 제외, `/03_original/**/binaries/*`): OPENSTEP 4.2 i386 실기에서 읽기 전용으로
  `cat` 복사한 원본. 실기 `krsha256` 과 호스트 SHA-256 이 같은 것만 보관한다.
  - `NextLibrary/Frameworks/System.framework/Versions/A/System` — libc·cthreads 를 담은 시스템 라이브러리
    (m68k·i386·SPARC universal; `/lib/libsys_s.A.dylib` 가 가리킴), `System_profile`(프로파일판).
  - `usr/shlib/libsys_s.B.shlib` — 호환용 고정 주소 공유 라이브러리(로컬 `ref/openstep/workspace/libsys.bin` 과 같은 파일).
  - `usr/lib/dyld`, `lib/{crt0,crt1,gcrt0,gcrt1,dylib1,bundle1}.o`, `lib/libcc.a`, `lib/libcc_dynamic.a`.
  - `NextDeveloper/Headers/…/*.p` — 로컬 헤더 사본과 다른 cpp-precomp 헤더 5 개의 실기 판.
  - `slices/` — universal 파일에서 잘라낸 아키텍처별 조각(오프셋은 각 `macho.json` 의 `fat_*`).
- `inventory/`: `files.json`(경로·크기·SHA-256·권한·mtime), `headers-sha256.tsv`(실기 `/NextDeveloper/Headers`
  의 ansi·architecture·bsd·mach·mach-o·machkit·objc·remote·streams 575 파일 해시와 로컬
  `ref/openstep/headers` 사본 대조: 같음 570, 다름 5(모두 `.p`)), 바이너리별 `macho.json`·`symbols.tsv`·
  `strings.tsv`(`10_tools/prepare.py` 의 `parse_macho` 로 만든 원시 인벤토리, 함수 경계·디컴파일 아님).
- 비교용 소스 후보: Darwin 0.1 `Libc-1`(`01_resources/upstream/darwin01/Libc`, APSL 1.0). OPENSTEP 4.2 판과
  같다고 가정하지 않는다. 라이선스: 원본 바이너리는 NeXT 저작물(공개 저장소에 올리지 않음).
