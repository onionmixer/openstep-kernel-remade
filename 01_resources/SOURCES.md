# 자료와 출처

2026-09-11 웹 목록 확인. 아래 위치의 확인과 실제 소스 다운로드 완료는 다르다.
수집 상태와 파일 해시/commit은 `manifests/acquisition.json`을 기준으로 한다.

| ID | 위치 | 역할 / 확인 범위 |
|---|---|---|
| mach4 | https://github.com/openmach/mach4 | Mach 4 보관 소스. README는 i386 릴리스의 MK83 계보를 설명한다. Mach 공통부·i386 비교 후보이며 OPENSTEP 구현과 같다고 가정하지 않는다. |
| nextmach | https://github.com/johnsonjh/NeXTMach/tree/master/mk-108.1 | NeXT 쪽 선행 소스 비교 후보. 웹에서 bsd, kern, vm, next, nextdev, kernserv 등의 디렉터리를 확인했다. 대상 mk-183.34.4와 버전 차이를 따로 검증한다. |
| darwin01 | https://sourceforge.net/projects/aapl-darwin/files/Darwin-0.1/ | 후대 계보 비교 후보. kernel-1.tar.gz, driverkit-139.1-1.tar.gz, architecture-1.tar.gz, APPLE_LICENSE.txt를 우선 수집한다. 내부 소스 버전과 아키텍처 범위는 다운로드 후 확인해야 한다. |

사용자 제공 NeXTMach 주소는
`https://github.laiyagushi.com/johnsonjh/NeXTMach/tree/master/mk-108.1`이다.
해당 미러는 이번 웹 접근에 실패하여 같은 owner/repository/path의 GitHub 주소를 사용한다.
미러와 GitHub 내용의 동일성은 검증하지 않았다.
SourceForge 주소의 `ttps://`는 `https://`로 정정하고 추적 query는 생략했다.

`fetch_sources.py`는 Git 저장소를 `upstream/mach4`, `upstream/nextmach`에 수집한다.
NeXTMach에서 우선 비교할 하위 경로는 `mk-108.1/`이다.
최초 수집 commit을 기록하고, 재실행으로 기존 checkout을 자동 갱신하지 않는다.
기존 파일의 해시가 잠금 기록과 다르면 오류로 처리한다.
Darwin 파일은 `archives/`에 저장하며 자동으로 커널 트리에 병합하지 않는다.
현재 수집본의 `kernel-1.tar.gz`와 `driverkit-139.1-1.tar.gz`는 이름과 달리
압축되지 않은 tar이다. 원래 파일명과 바이트는 그대로 보존한다.
`architecture-1.tar.gz`는 gzip tar이다. 압축 해제 시 `-z`를 강제하지 않고 실제 형식을 사용한다.
아카이브의 경로·링크를 검사한 후 `upstream/darwin01/`에 추출했다.
추출된 파일별 해시는 `manifests/darwin-extraction.json`에 있다.
라이선스 원문은 보존했으며, 복원 트리로 도입할 때의 개별 라이선스 검토는 별도로 수행한다.
자체 계산 SHA-256은 이후 변경 검사용이며 발행자 서명 검증을 뜻하지 않는다.

## 로컬 기준 자료

- `../../ref/openstep/ps2/mach_kernel`: 기준 커널의 최초 보존 출처.
- `../../openstep-matrox-remade/reference/original-binaries/mach_kernel.OS42-20260819`:
  같은 SHA-256의 두 번째 보관본. 별도 파일로 기준을 중복하지 않고 출처 기록을 남긴다.
- 위 두 경로의 `.i64`: 서로 다른 시점의 기존 IDA 분석 DB.
  `05_ida/snapshots/`에 별도 보관한다. 작업 복사본을 IDA에서 열어 입력 경로는 확인했으나
  DB 내부 바이트 패치 여부와 기존 분석의 정확성은 미검증이다.
- `local_mirrors/headers`, `local_mirrors/makefiles`, `local_mirrors/nextdev-doc`:
  기존 `ref/openstep/` 자료를 가리키는 상대 심볼릭 링크.
  이 링크들은 불변 스냅샷이 아니다. 해당 헤더를 복원 근거로 채택할 때 파일 해시를 기록한다.

각 도입 파일에 원 출처, commit/아카이브 해시, 원 경로, 라이선스 표시와 수정 내용을 기록한다.
새 프로젝트에 일괄 라이선스를 부여하거나 서로 다른 소스를 무조건 합치지 않는다.
