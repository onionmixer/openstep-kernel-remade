# 다운로드 시도 — 실패 기록

작업 디렉터리는 이 파일이 있는 `source-package`였다.

```sh
apt-get -o Acquire::Retries=0 -o Acquire::http::Timeout=15 --download-only source qemu=1:6.2+dfsg-2ubuntu6.31
```

실제 도구 응답의 종료 코드는100이었다. orig/debian/dsc 모두
`kr.archive.ubuntu.com`의 주소를 알아낼 수 없다는 오류로 실패했다.
이는 원시 stdout 로그 파일이 아니라 도구 응답의 요약 기록이다.
정확한 URI/해시는 상위 디렉터리의 `package-identity.json`에 보존돼 있다.

`--download-only`였으므로 빌드·설치·소스 코드 실행을 요청하지 않았다.
실패 후 source package 파일은 확보되지 않았다. 미러 설정 또는 권한을 바꾸지 않았다.
