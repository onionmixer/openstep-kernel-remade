# 222차 정적 검토 — 현재 export 기준 `__text` 분할 재검산

원본 OPENSTEP x86 `mach_kernel`과 그 원본에서 얻은 full-pass5 metadata만 사용해
`__text`의 현재 분할을 Python으로 다시 계산했다. 재부팅·QEMU·외부 소스·구현은 사용하지 않았다.

`__text`의 851,436바이트는 export 함수 본문 824,512바이트, 정의 데이터
6,368바이트, undefined/정렬 범위 20,556바이트로 나뉜다. 세 집합의 교집합은 모두
0이고 합집합은 정확히 `__text` 크기와 같아, 이 metadata 기준 미표현 바이트는 0이다.
함수 본문은 5,253개 분석 단위에서 계산했으며 coverage metadata의 orphan instruction
range도 0개다.

이는 현재 export/분류 자료의 일관성 검증이다. 모든 함수의 의미, 실제 실행 가능성,
간접 진입점, decompiler 해석, runtime alias·동시성·하드웨어 동작을 증명하지 않는다.

정확한 입력 해시·범위·Python 계산 결과는
[text-partition-revalidation.json](text-partition-revalidation.json)에, 재현 검증은
[checkpoint.json](checkpoint.json)에 보존했다.
