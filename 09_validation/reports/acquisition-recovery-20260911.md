# 소스 수집 복구 — 2026-09-11

사용자 터미널에서 다운로드한 kernel/driverkit 입력은 `not a gzip file`로 실패했지만,
`file` 및 헤더 확인 결과 실제로는 정상 plain tar였다. 기존 검사기가 확장자만 보고
gzip을 강제한 것이 원인이다.

검사기를 실제 헤더 기반으로 변경했다. 모든 tar 멤버의 데이터를 읽고,
gzip인 경우 압축 스트림까지 검증한 후 기존 `.part`를 완료 파일로 이름 변경했다.
다시 다운로드하거나 원본 바이트를 재압축하지 않았다.

`python3 10_tools/fetch_sources.py`: 종료 코드 0, 여섯 항목 모두 `acquired`.
Git 2개는 고정 commit과 clean 상태, 파일 4개는 SHA-256으로 기록했다.
자료를 추출하거나 커널에 병합한 상태는 아니다.
초기 준비 보고서의 DNS 실패 기록은 당시의 결과이며 현재 수집 상태는 해결되었다.

오프라인 회귀검사:

```sh
python3 -m unittest discover -s 10_tools -p 'test_fetch_sources.py' -v
```

plain tar + .tar.gz 확장자, gzip tar 수용 및 잘린 payload/HTML 거부를 확인한다.
