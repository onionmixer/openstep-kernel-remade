# 복원 증거와 대응표

도구 출력(04/05)과 복원 구현(07)을 연결하는 검토 계층이다.

- `functions.tsv`: 기준 바이너리 함수 ↔ 참고 소스 ↔ 복원 구현 대응.
- `types.tsv`: 구조체·필드 offset, 크기, alignment, 호출 ABI의 증거.
- `subsystems.tsv`: 큰 단위의 범위와 진행 상태.
- `evidence/`: 판단 근거. `templates/function.md`를 복사하여 시작한다.

상태는 `unmapped → candidate → compared → implemented → static_verified → runtime_verified`.
근거 없는 항목은 `unknown`, 상충하면 `conflicting`으로 기록한다.
신뢰도는 `low/medium/high`이며 검증 상태와 독립적이다.
심볼명 일치나 디컴파일 유사성만으로 `verified`로 올리지 않는다.
각 행의 원본 SHA-256과 VA를 함께 유지하며 architecture별로 분리한다.
후보 소스에는 정확한 commit/아카이브 해시와 파일/함수 위치가 필요하다.

함수 대응표는 의도적으로 header만 생성한다. 원시 nlist 심볼은 함수 경계가 아니므로
정적 인벤토리의 전체 심볼을 복원 함수로 일괄 등록하지 않는다.

`compared` + `high`: 후보 소스를 기록된 옵션으로 빌드한 목적 파일에서 그 함수가 L1 MATCH(바이트와 모든 참조를 재현, 참조하는 데이터 섹션도 검증)이고, 목적 파일이 등급 A·A\*(`objects_confirmed.tsv`) 또는 P(`objects_partial.tsv`)인 경우. 함수 단위 결과이며 목적 파일 전체 배치의 증명이 아니다.
도구 체인 라이브러리 구성원(등급 L, `objects_toolchain.tsv`, D051): 원래 커널 빌드가 소스로 컴파일하지 않고 `-lcc` 로 링크한 라이브러리 구성원(libgcc `__muldi3`·`__udivdi3`). 행은 보존된 라이브러리 구성원(`03_original/.../libcc.a(i386: <member>)`)의 섹션 바이트가 원본과 같고, 확보 참고 원문(D050)으로 다시 빌드한 목적 파일이 L1 OBJECT_MATCH 인 경우에만 둔다. 이 함수 행의 `compared` + `high` 는 그 OBJECT_MATCH 를 뜻하며, `source_id` 는 `toolchain-libcc`, `implementation_path` 는 아카이브 구성원이다(07 소스 없음). 커버리지는 A·P 와 따로 보고한다.
`compared` + `medium`: 함수 바이트와 참조가 모두 같으나(L1 MATCH_UNVERIFIED) 미검증 의존이 `zerofill_check.py` 결론이 `reference-inferred` 또는 `reference-inferred-single`(D019: 참조가 하나뿐이라 음성 검사만 구조상 미검출, 그 참조는 scattered·pc-relative 아님, 다른 검사 모두 통과)인 zero-fill 섹션뿐인 경우(결론이 `fail` 이면 이 분류를 쓰지 않는다).
역사적 원 소스의 동일성과 실행 동작은 이것으로 확정되지 않는다.
`objects_confirmed.tsv` 의 등급 A 는 L1 OBJECT_MATCH 와 앞뒤 경계 증명서(최소 정렬 채움, 값 00)가 모두 성립한 경우, A\* 는 OBJECT_MATCH 이지만 경계 증명서 일부가 성립하지 않은 경우(사유는 gap 열·근거 파일).
`objects_data.tsv`(계획 398): `__text` 가 없는 데이터만 있는 목적 파일(설정 표·판 문자열 등). `sections` 열에 재빌드 L1 이 정한 원본 절 배치(절=시작+크기)를 적고, 등급 A 는 L1 OBJECT_MATCH(기호 없는 절은 `--place` 로 명시 배치, build 열에 적음)이며 앞뒤 빈 곳이 정렬 채움(`00`)뿐인 경우(`l2_coverage.py` 결과). text 범위가 없으므로 A/P 의 text 커버리지에는 들어가지 않는다.
`objects_partial.tsv` 의 등급 P(부분 검증, 계획 46.1–46.2)는 OBJECT_MATCH 가 아니다: 목록(`unverified_sections`)에 적은 섹션을 뺀 모든 파일 기반 섹션의 바이트·참조가 일치하고(바이트 차이·참조 차이·미지원 참조·모호 배치 없음), 목록의 섹션은 참조가 전혀 없어 배치할 수 없는 것(unreferenced)이거나 참조로만 위치를 추정한 zero-fill(`zerofill_check.py` 결론 reference-inferred 또는 reference-inferred-single — 후자는 D019 에 따라 행에 "단일 참조" 를 적고, 이웃 확정으로 위치가 독립 고정되면 재판정)이며, 경계 증명서가 성립한 경우. `l2_placement` 열(계획 408, D063)은 링크한 커널에서 미검증 절의 배치를 증명한 결과입니다: 링크 입력 순서대로 정렬해 이어 붙인 배치가 strip 전 링크 결과의 절 끝·기호·STAB 과 모두 맞고, 그 절이 기록된 위치와 같거나(`__bss`) 원본 바이트와 같습니다(`__const`). 기호·STAB 이 없는 기여는 "order-dependent" 로 적습니다. 이 열은 등급을 바꾸지 않습니다.
참조 소스에 없는 코드를 원본 바이트에 맞춰 새로 쓴 함수(D016, 계획 48 W1–W6)는 `source_id` 를 `darwin01+authored` 처럼 표시하고 비고에 작성 범위·근거 주소·diff 를 적는다(역사적 원문이라는 주장이 아님).
후보 소스를 원본에 맞게 고친 경우("복원 수정", D014)는 `source_revision` 에 `+ restoration edit` 를 붙이고 `07_kernel/MODIFICATIONS.md` 에 기록한다. 바이트로 확정된 목적 파일 범위는 `objects_confirmed.tsv`,
자동 생성 후보는 `objects.tsv`(S2-A)·`function_candidates.tsv`(S2-B, 신뢰도 최대 medium).

`m68k-text-map.tsv`·`m68k-text-objects.tsv`(계획 415, M2-1): m68k 원본(`03_original/m68k/binaries/mach_kernel`) `__TEXT,__text` 의 외부 기호를 이름으로 x86 재빌드 객체 402 개(계획 409 기록)에 대응시킨 **후보 지도**입니다.
앞의 표는 주소순 구간(같은 대응 객체가 이어지는 최대 구간, `unmapped` 는 대응 없음), 뒤의 표는 x86 객체마다 m68k 에 나타나는 구간 수와 분류(contiguous·split·absent·no_external_text_symbol)입니다.
구간 끝은 다음 구간 첫 기호까지의 상한이며 정적·이름 없는 코드가 어느 쪽인지는 정하지 않았습니다. 이름이 같다는 것은 x86 짝의 후보일 뿐 m68k 소스 파일이나 객체 경계의 확정이 아닙니다(도구 `10_tools/reconstruction/m2_m68k_text_map.py`, 기록 `09_validation/reconstruction/m2-m68k-text-map-20261009.json`).
`m68k-text-boundaries.tsv`(계획 416, M2-2): 위 구간 사이 경계. 이름 없는 함수(정적 함수)를 코드 참조로 소유 객체에 귀속하고, 창 안의 모든 이름 없는 진입점이 앞·뒤 객체로 정해지며 역어셈 의심(`.word`·목록 밖 기호·미확인 진입)이 없을 때만 `decided=1` 입니다.
규칙에 따른 경계이며 내용 일치나 소스 확정이 아닙니다(검증: 계획 414 의 m68k 재빌드 OBJECT_MATCH 34 객체와 대조, 기록 `09_validation/reconstruction/m2-m68k-boundaries-20261009.json`).
`m68k-text-boundaries-data.tsv`(계획 417, M2-3): 같은 경계를 자료 절 표(함수 포인터)로만 쓰이는 정적 함수까지 귀속해 다시 판정한 것입니다(`decided_416` 열은 앞 표의 판정). 자료 항목 소유는 외부 자료 기호의 x86 정의 객체, 또는 이웃 외부 자료 기호와 소유가 맞는 코드 참조 주소로 정합니다(기록 `09_validation/reconstruction/m2-m68k-data-owner-20261009.json`).
`m68k-text-boundaries-order.tsv`(계획 418, M2-4): 위에 더해, 코드가 참조하는 자료 항목을 앞·뒤 외부 자료 기호(x86 직접 정의·링크 위치 있음)의 링크 순서 사이에 있는 참조 객체 소유로 받아들여 다시 판정한 것입니다(`__data`·`__const` 의 객체 배치가 `__text` 링크 순서와 같다는 관찰에 근거; 기록 `09_validation/reconstruction/m2-m68k-data-order-20261009.json`).
`m68k-data-map.tsv`(계획 419, M2-5): m68k 원본 `__DATA,__data`·`__TEXT,__const` 의 객체 후보 구간입니다. 닻은 x86 이 직접 정의한 외부 자료 기호(a)와 계획 418 의 항목 규칙을 통과한 코드 참조 주소(b)이며, `next_first` 는 상한일 뿐 경계가 아닙니다. 미참조 이름 없는 자료는 놓지 않았고, `unmapped#k` 는 계획 415 구간이지 확인된 객체가 아닙니다(기록 `09_validation/reconstruction/m2-m68k-data-map-20261009.json`).
`m68k-text-unmapped.tsv`(계획 420, M2-6): x86 짝이 없는 m68k `__text` 구간을 NeXTMach mk-108.1 빌드 목록(`conf/files`·`conf/files.NeXT`, `locore.s`·`scb.s`, `fpsp/*.sa`)의 같은 이름 정의로 나눈 **약한 후보**(1990 판 파일 이름)입니다. `note` 의 "absorption candidate" 는 같은 x86 객체 구간 사이에 낀 구간입니다(기록 `09_validation/reconstruction/m2-m68k-unmapped-20261009.json`).
`m68k-text-regroup.tsv`(계획 421, M2-7): split x86 객체와 m68k 전용 주소 묶음의 m68k 객체 후보입니다. `kind=x86` 은 한 split x86 객체의 구간 사이에 낀 대응 없는 묶음을 그 객체로 합친 것(감쌈), `kind=file` 은 NeXTMach 1990 파일 이름 후보(약함)이며, 연속 x86 객체는 합치지 않습니다(기록 `09_validation/reconstruction/m2-m68k-regroup-20261009.json`).
`m68k-objects.tsv`(계획 423, M2-9): 위 m68k 표들을 합친 **객체 후보 목록**입니다. 종류 `x86`(이름 대응 연속 객체)·`bracket`·`file`(약한 후보)·`unassigned`·`data-only`·`data-unlinked`, 시작·끝은 `lo == hi` 이면 정확, 아니면 경계 창입니다. 진입점은 함수 후보이며 함수 수 확정이 아닙니다(기록 `09_validation/reconstruction/m2-m68k-objects-20261009.json`).
`m68k-functions.tsv`(계획 424, M2-10): m68k 원본 진입점 3,570 의 함수 후보 표입니다. `confirmed=1` 은 RECONSTRUCTION_PLAN `:78` 함수 범위 규칙을 목록 도달 분석으로 적용해 [진입점, 다음 진입점) 이 함수 범위로 확인된 것(내용 일치 아님), 아니면 사유를 적습니다. `class` 의 `data label` 은 `__text` 안 자료 이름입니다(기록 `09_validation/reconstruction/m2-m68k-functions-20261009.json`).
`config_options-m68k.tsv`(계획 434, D068): m68k 가 x86 `config_options.tsv` 와 다르거나 x86 표에 없는 구성 값(덮어쓰기)입니다. 열은 x86 표와 같고, `gen_config_headers.py --arch m68k` 가 `07_kernel/v183.34/m68k/generated/` 를 만듭니다. m68k 실효 구성 = x86 표 + 이 표.
`m68k-text-boundaries-built.tsv`(계획 439): §418 경계 표에 다시 만든 m68k 객체(run `m3p438-cc1`)로 정한 결과 열(`decided_439`·`boundary_439`·`basis_439`)을 더한 새 판입니다. 규칙: 한쪽 OBJECT_MATCH 의 L1 자리(·끝), 둘 다 아니면 가린 첫 64 B 의 진입점 유일 일치 + a 쪽 전체 비교 관문. 계획 439 에서 k=191·193 이 결정되었고, k=130 은 관문 불통과 뒤 계획 440 의 규칙 4(a 꼬리 64 B + b 머리 64 B 가 한 진입점에서 맞닿음; 사용자 지시로 결과를 본 뒤 정한 규칙, 음성 시험 172 맞음·0 틀림)로 0x403a056 이 되었습니다.
