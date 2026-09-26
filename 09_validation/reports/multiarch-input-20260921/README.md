# OPENSTEP 4.2J m68k·SPARC 입력 확보

## 결과

사용자가 제공한 `os42j.iso`는 ISO 9660이 아닌 4.3BSD UFS 설치 매체다. Python으로
계산한 UFS 시작 위치는 논리 블록 80, 바이트 offset 163,840이다. 원본 ISO UFS의
`/mach_kernel`은 m68k·i386·SPARC 세 슬라이스를 가진 Fat Mach-O다.

| 대상 | 보존 경로 | 크기 | SHA-256 | byte order |
|---|---|---:|---|---|
| Fat container | `03_original/installation-media/os42j/binaries/mach_kernel.universal` | 3,391,352 | `f3b57f877218adf9e0814f69c5494aca74e7c7b4e9dbd395156cce78d62de148` | Fat header big-endian |
| m68k | `03_original/m68k/binaries/mach_kernel` | 832,196 | `dff6c51c952add68ce326d861150df799737b9476bad95e51976b36683ba5d75` | big-endian |
| SPARC | `03_original/sparc/binaries/mach_kernel` | 1,441,656 | `287ababa091f5f64b42cad2d289f0e828d88127cba858ba8fe440f88ae65b8e1` | big-endian |

UFS `/odmach`와 `/sdmach`는 각각 m68k 슬라이스와 바이트 동일함을 Python 비교로 확인했다.
각 Fat entry의 offset, size, raw CPU type과 원본 ISO 해시는
[provenance](../../../03_original/installation-media/os42j/provenance.json)에 보존했다.

## 원시 Mach-O inventory 검증

`10_tools/inventory_thin_macho.py`는 기대 byte order와 raw CPU type을 인자로 받아,
magic 또는 CPU type이 다르면 실패한다. m68k에는 `big`/`0x6`, SPARC에는 `big`/`0xe`를
지정했다. 각 inventory의 원본 해시, big-endian magic, segment·section 파일 범위,
심볼·문자열 TSV 행 수를 독립 Python으로 재검사한 결과는
[raw-inventory-validation.json](raw-inventory-validation.json)에 있다.

## IDA 초기 자동분석

IDA Pro 9.3의 새 작업 DB를 아키텍처별 경로에만 만들고, `ida_auto.auto_wait()` 후
processor와 `inf_is_be()`를 export했다. m68k는 `68K`·32비트·big-endian으로, SPARC는
`sparcb`·32비트·big-endian으로 확인됐다. IDA가 찾은 함수 후보는 m68k 3,214개, SPARC
5,075개다. 이는 함수 경계의 확정이나 coverage가 아니다.

SPARC의 자동 Mach-O loader는 `sparcl` processor와 little-endian DB를 만들었으므로
즉시 거부했다. 거부 DB·로그는
`05_ida/databases/sparc-os42j-ida-loader-little-endian-rejected.i64`와
`05_ida/exports/sparc/failures/`에 보존했다. 별도 `-psparcb` probe가 big-endian을
확인한 뒤에만 정상 SPARC DB를 만들었다. 원본 해시·CPU type·magic·processor·endianness·
전용 경로 검증 결과는
[ida-initial-validation.json](ida-initial-validation.json)에 있다.

## IDA 함수별 assembly corpus

유효한 각 IDA DB에서만 함수 후보별로 주소, IDA가 읽은 바이트, assembly 텍스트를
`05_ida/exports/<arch>/functions/`에 export했다. m68k는 3,214개 파일·181,736개 행,
SPARC는 5,075개 파일·241,098개 행이다. 각 행을 대상 원본 Mach-O의 file-backed segment에
Python으로 역매핑하여 원본 바이트와 대조했다. 두 검증 결과는
[m68k assembly validation](m68k-ida-function-asm-validation.json)과
[SPARC assembly validation](sparc-ida-function-asm-validation.json)에 있다.

이 corpus의 함수 경계, 이름, code/data 분류는 IDA 자동분석 가설이다. assembly 행의
file-backed 원본 바이트 일치만 확인했다. 아키텍처 사이 또는 x86 자료와 함수 수·coverage를
합산하지 않는다. provenance→inventory→IDA→assembly의 해시 연결, 전용 경로, SPARC
거부 기록 및 문서 링크의 최종 교차 검증은
[separation-and-integrity-validation.json](separation-and-integrity-validation.json)에 있다.

## 원본 nlist·함수 시작 주소 감사

원본 `symbols.tsv`의 모든 nlist 행을 Mach-O 기본 type과 segment 범위로 분류했다. m68k는
3,809개, SPARC는 4,531개 원시 심볼 행이 inventory의 nlist 수와 일치한다. absolute symbol은
주소가 load segment 밖이어도 별도 분류했고, 두 대상 모두 non-absolute unmapped 심볼은 0개다.
IDA 함수 후보 시작점은 m68k 3,214개와 SPARC 5,075개 모두 각 원본 `__text` 범위 안에 있다.

이 결과는 주소 범위 검증일 뿐 symbol·함수의 의미 또는 함수 경계 완전성을 확정하지 않는다.
근거는 [m68k address audit](m68k-symbol-and-function-address-validation.json) 및
[SPARC address audit](sparc-symbol-and-function-address-validation.json)에 있다.

## `__text` 전체 IDA item inventory

함수 후보 목록과 별도로, 각 canonical big-endian IDA DB에서 원본 `__text`의 모든 바이트를
연속적인 code·data·unknown item으로 export했다. 각 TSV 행의 주소, file offset, 길이, hex
바이트를 원본 Mach-O에 Python으로 대조했고, 두 대상 모두 공백·겹침 없이 `__text` 전 구간을
덮으며 모든 export 바이트가 원본과 일치한다.

IDA kind은 도구의 분류 가설이며 함수 의미 또는 code/data의 최종 판정이 아니다. 검증 결과는
[m68k text-unit validation](m68k-ida-text-units-validation.json)과
[SPARC text-unit validation](sparc-ida-text-units-validation.json)에 있다.

## 모든 Mach-O load range IDA item inventory

canonical DB는 보존하고 각각의 복사 working DB에서 `__PAGEZERO`을 제외한 모든
file-backed 및 zero-fill virtual Mach-O segment range를 순차 IDA item으로 export했다. m68k는
312,514개, SPARC는 622,394개 item이 각 range를 공백·겹침 없이 덮는다. file-backed row의
`original_bytes`는 모두 원본 binary file offset에 Python으로 대조했으며, zero-fill virtual
range는 원본 파일 바이트가 없으므로 file offset·원본 byte 비교를 부여하지 않았다.

m68k DB item value는 모든 file-backed range에서 원본과 일치한다. SPARC DB item value는
`__DATA`에서 3,592바이트, `__OBJC`에서 1,091바이트, `__LINKEDIT`에서 122,696바이트가
원본과 다르다. 따라서 두 값을 별도 `ida_bytes`·`original_bytes` 열로 보존하고 raw 근거에는
후자만 사용한다. `__PAGEZERO`은 file byte가 없는 address-zero guard range로 명시적으로
제외했다. item kind은 계속 IDA 가설이며 DB 값 차이는 relocation·runtime memory·의미를
확정하지 않는다. SPARC 차이는 54개 연속 byte run으로 재감사했으며 DB 값 byte 분포 `ff`
127,377개·`f0` 2개와 각 run의 원본 window를 별도 보존했다. 독립 검증은
[all-load-units validation](all-load-units-validation.json), 차이 범위 감사는
[SPARC file-backed IDA-value-difference audit](sparc-file-backed-ida-value-differences-audit.json)에
있다.

load export 뒤 copied working DB는 각각 canonical DB와 현재 SHA-256이 다르며, 같은 byte size를
유지한다. 이 확인에서는 canonical DB와 working DB를 혼용하지 않고, load-range의 binary 근거는
항상 original file `original_bytes`로 한정한다. 이 hash 분리 기록은
[IDA load-export working-copy isolation audit](ida-load-export-working-copy-isolation-audit.json)에
있다. DB 차이의 원인이나 분석 의미는 판정하지 않는다.

원본 해시·big-endian processor 설정과 all-load-range 원본 mapping을 합친 초기 분석 전제조건
closure도 m68k·SPARC 각각에서 통과했다. 이는 함수 경계나 동작의 완료 판정이 아니라 이후
정적 검토가 사용할 입력·주소·바이트 근거가 닫혔다는 뜻이다. 근거는
[multiarch analysis-prerequisite closure](multiarch-analysis-prerequisite-closure.json)에 있다.

OS42J source ISO·UFS에서 확보한 Fat container와 m68k·SPARC thin slice도 다시 대조했다.
ISO와 container의 SHA-256·byte count, Fat header의 big-endian arch entry, slice offset/size,
slice bytes, big-endian thin header와 raw Mach-O inventory까지 모두 provenance와 일치한다.
이는 input acquisition 및 raw inventory의 closure이며 의미 분석 결과가 아니다. 근거는
[multiarch input-acquisition/inventory closure](multiarch-input-acquisition-inventory-closure.json)에
있다.

전체 분석 계획의 1번(해시 일치 분석 환경)과 2번(listing·분류·원본 mapping)도 x86의 기존
전체 audit 및 m68k·SPARC closure를 함께 교차해 완료 조건을 만족함을 확인했다. 이 판단은
두 prerequisite task에만 한정하며 의미 분석 완료 주장이 아니다. 근거는
[task 1·2 completion audit](task-1-2-completion-audit.json)에 있다.

m68k `__text`에서 IDA가 unknown으로 남긴 연속 6바이트는 인접 data item, 원본 심볼 값,
함수 assembly 표기 및 big-endian m68k decode만으로 code/data를 확정하지 않았다. DB를
수정하지 않고 unknown으로 보존했으며, 근거와 보류 결론은
[unknown-unit review](m68k-unknown-text-unit-review.json)에 있다.

## IDA xref inventory

각 canonical big-endian IDA DB에서 전체 xref를 별도 TSV로 export했다. 모든 `from`
endpoint가 원본 Mach-O mapped 영역 안에 있음을 Python으로 확인했다. `to` endpoint는
mapped/outside 범주만 기록하며, outside destination을 오류·호출·포인터 의미로 단정하지
않는다. 결과는 [m68k xref validation](m68k-ida-xref-validation.json)과
[SPARC xref validation](sparc-ida-xref-validation.json)에 있다.

## IDA Hex-Rays capability probe

원본 해시, canonical processor, big-endian 설정을 확인한 전용 IDA DB에서 Hex-Rays 모듈의
초기화 가능 여부만 검사했다. m68k와 SPARC 모두 모듈 import는 됐지만 plugin 초기화는
`false`였다. 따라서 이 설치에서 두 대상의 Hex-Rays pseudocode는 만들지 않았고, 기존 IDA
assembly·xref·원본 바이트 자료만 정적 근거로 유지한다. capability 기록은
[m68k](../../../05_ida/exports/m68k/decompiler-capability.json),
[SPARC](../../../05_ida/exports/sparc/decompiler-capability.json), 그리고 원본 해시를 Python으로
재계산한 [독립 검증](ida-decompiler-capability-validation.json)에 있다.

이는 DB 설정 또는 byte order 오류가 아니라 현재 로컬 IDA 설치에 m68k·SPARC Hex-Rays
architecture plugin file과 `plugins.cfg` entry가 없는 상태와도 일치한다. 따라서 이 설치에서
IDA Hex-Rays 재시도는 하지 않고 IDA assembly·xref export만 유지한다. decompiler 자료가 필요할
경우에는 명시적 big-endian 설정을 검증한 별도 Ghidra capability probe를 먼저 수행한다. 범위와
한계는 [IDA Hex-Rays architecture-availability audit](ida-hexrays-architecture-availability-audit.json)에
있다.

## IDA 내부 Ghidra decompiler 후보 검토

Yagi와 GhidraDec을 전역 IDA 설치 후보로 검토했다. Yagi의 공식 지원표는 SPARC를 지원하지만
68000은 미지원으로 명시하므로 m68k·SPARC를 함께 다뤄야 하는 현재 목적을 충족하지 않는다.
[Yagi 공식 README](https://github.com/airbus-cert/Yagi)를 참고한다.

GhidraDec은 현재 로컬 Ghidra 12.1 및 IDA SDK 9.3 대상과 일치하며, 독립된 copied DB에서
m68k와 SPARC의 big-endian processor 설정을 검증했다. 초기 무인 시험은 두 대상 모두 timeout으로
C 출력을 만들지 못했지만, 원본·DB의 새 복사본에서 batch 및 live-callback 회귀 경로를 분리해
재시험한 결과 양쪽 모두 댓글 질의·응답과 decompile 응답 뒤 C 출력을 만들었다. m68k는 Ghidra
`68040.sla`, SPARC는 `SparcV9_32.sla`를 선택했다.

초기 실패의 고정 source·SDK commit, Python hash, RPATH 없는 빌드 artifact와 runtime·protocol log는
[GhidraDec candidate assessment](ghidradec-candidate-20260922/README.md)에, 성공한 후속 두 경로의
원본 hash·C output·protocol evidence는 [follow-up assessment](ghidradec-candidate-followup-20260922/README.md)에
보존했다. 일반 IDA GUI 선택 디컴파일 자동 시험은 아직 유효하게 완료되지 않았으므로 plugin binary를
IDA 설치 또는 영구 user plugin 경로에 배치하지 않는다. 이는 후보 도구 검증일 뿐 함수 경계·코드/데이터
분류·ABI·동작의 증거가 아니다. [GhidraDec 공식 README](https://github.com/GregoryMorse/GhidraDec)는 Linux에서
무인 IDA 회귀 자동화를 아직 향후 작업으로 명시한다.

이후 사용자가 GUI 검증이 아니라 headless 분석용 전역 설치를 승인했다. RPATH 없는 동일 plugin과
Ghidra 12.1 경로를 설정하는 `idat-ghidradec` wrapper를 로컬 IDA 9.3 전역 경로에 설치하고, temporary
user plugin 경로 없이 m68k·SPARC copied DB에서 다시 C output을 생성했다. 설치 파일·원본 hash·protocol
log·output 검증은 [GhidraDec global headless installation](ghidradec-global-install-20260922/README.md)에
보존했고, 반복 사용 형식은 `10_tools/IDA_GHIDRADEC_HEADLESS.md`에 기록했다.

## xref endpoint text-item audit

원본 big-endian Mach-O segment 범위 안에 모든 xref `from` 주소가 있음을 다시 확인하고,
source와 destination을 exported text-item의 code·data·unknown 분류 및 mapped 범위와
교차했다. m68k의 241,893개 출발점은 code 241,827개와 `__text` 밖 mapped 영역 66개였고,
SPARC의 311,716개 출발점은 code 303,068개·data 706개·`__text` 밖 mapped 영역 7,942개였다.
도착점은 m68k에서 code 227,382개·data 250개·unknown 1개·`__text` 밖 mapped 12,534개·원본
mapped 밖 1,726개였고, SPARC에서는 code 283,717개·data 289개·`__text` 밖 mapped 25,238개·
원본 mapped 밖 2,472개였다. 이 수치는 Python으로 계산했다.

m68k unknown 도착점은 보류한 6바이트 범위의 첫 바이트 하나이며, 출발점 원본 code item과
IDA xref 행은 [unknown-unit review](m68k-unknown-text-unit-review.json)에 추가했다. 단일
xref와 IDA 분류만으로는 code/data를 확정할 수 없으므로 unknown 상태와 DB는 변경하지 않았다.
IDA의 item kind·xref type·`iscode` 값은 호출·포인터·제어 흐름·함수 경계의 의미를 확정하지
않는다. 원본 해시 재계산과 각 원시 값 분포는
[xref source-kind audit](xref-source-kind-audit.json)에 보존했다.

## raw `__OBJC` word-layout audit

원본 Mach-O section 이름과 file-backed 범위만 사용해 `__OBJC` 영역을 별도 감사했다. m68k
원본에는 `__OBJC` section이 없고, SPARC 원본에는 20개가 있으며 모두 file-backed·4바이트
정렬이었다. SPARC의 18,065개 32비트 big-endian word 값 중 2,111개는 0, 5,985개는 원본의
어느 section 가상 범위와 일치했고, 9,969개는 어느 section 범위와도 일치하지 않았다. 수치는
Python으로 계산했다.

이는 32비트 값을 주소 후보로 세어 원본 layout을 확인한 결과일 뿐이다. 값이 pointer인지,
어떤 Objective-C field·class·method인지는 판정하지 않으며, m68k의 section 부재도 기능적
차이를 뜻하지 않는다. 원본 해시와 section별 분포는
[raw `__OBJC` word-layout audit](objc-word-layout-audit.json)에 보존했다.

## raw `__OBJC` NUL-section export

SPARC 원본의 `__OBJC` section 중 header flag가 `0x2`인 세 file-backed 영역을 NUL-delimited
raw byte record로 export했다. `__OBJC,__class_names`·`__meth_var_types`·`__meth_var_names`의
record 수는 각각 782개·1,458개·5,287개이며, 총 7,527개다. m68k 원본에는 이 조건의 section과
record가 없다. 모든 수치는 Python으로 계산했다.

각 record의 address·file offset·hex bytes는 원본에서 계산했고, TSV record를 재조합한 bytes와
section payload SHA-256을 원본과 독립 대조했다. 출력은
[SPARC raw record TSV](../../../03_original/sparc/inventory/objc-nul-sections.tsv),
[export validation](objc-nul-section-export-validation.json),
[TSV reconstruction validation](objc-nul-section-tsv-validation.json)에 있다. section flag와
NUL 구분은 raw layout 사실일 뿐, record를 class·selector·type 또는 동작 의미로 해석하지 않는다.

## SPARC `__OBJC` NUL-section xref endpoint audit

canonical SPARC IDA xref의 도착점 중 위 세 raw NUL section 범위에 들어오는 행은 4,293개였다.
`__class_names` 368개, `__meth_var_types` 1,627개, `__meth_var_names` 2,298개로 분포했고, 모두
exported record 시작 주소와 일치했다. Python으로 계산한 이 결과는 주소 경계 교차 사실이며,
IDA xref type 값이나 record text를 selector·type·pointer·호출 동작으로 해석하지 않는다. 근거는
[SPARC NUL-section xref endpoint audit](sparc-objc-nul-xref-endpoint-audit.json)에 보존했다.

같은 4,293개 xref의 출발점도 원본 section 범위와 교차했다. 모두 `__OBJC` segment 및
`__text` 밖에 있었으며, section별 분포는 raw `__OBJC` table section에만 기록됐다. 이 사실은
주소 배치만 뜻하며 field·pointer·호출·문자열 의미를 확정하지 않는다. 원본 hash 및 section별
분포는 [SPARC NUL-section xref source audit](sparc-objc-nul-xref-source-audit.json)에 있다.

## direct-call instruction edge corpus

원본 instruction bytes에서 계산한 target이 canonical IDA type-17 xref 목적지와 정확히 일치하는
direct-call edge를 전수 export했다. m68k는 long-relative BSR 10,521개와 absolute-long JSR
22개, SPARC는 relative CALL 17,607개다. 각 TSV row의 source bytes와 target 계산은 원본에
독립 대조했다. 모든 수치는 Python으로 계산했다.

이 corpus는 direct control-transfer edge만 확정한다. callee의 동작·인자·반환·ABI·함수 의미는
아직 확정하지 않는다. 근거는 [export validation](direct-call-edge-export-validation.json),
[TSV validation](direct-call-edge-tsv-validation.json),
[m68k edge TSV](../../../05_ida/exports/m68k/direct-call-edges.tsv),
[SPARC edge TSV](../../../05_ida/exports/sparc/direct-call-edges.tsv)에 있다.

전체 direct-call corpus의 call-adjacent item도 원본 bytes로 대조했다. m68k 10,543개 CALL의
직후 item은 모두 code이며 직전 item은 code 10,541개·data 2개다. SPARC 17,607개 CALL의
post-delay item은 모두 code이고, 직전 item과 delay slot은 각각 code 17,605개·data 2개다.
이는 static adjacency와 현재 code/data 분류의 관측일 뿐 argument preparation·delay-slot 실행·
call return·reachability·function boundary·calling convention·ABI·동작을 확정하지 않는다. 근거는
[multiarch direct-call adjacency audit](multiarch-direct-call-adjacency-audit.json)에 있다.

non-code adjacency 여섯 건도 raw context와 현재 candidate ownership으로 개별 대조했다. m68k는
0x4064f22·0x406587e의 두 CALL이 같은 target 0x40648ac 앞 data `0001`에 인접한다. SPARC는
0xf007537c·0xf00a8be8의 predecessor-data와 0xf00f09f8·0xf00f38e0의 delay-slot data가
각각 관측된다. 이는 data semantics·argument preparation·delay-slot 실행·call return·
reachability·function boundary·ABI·동작을 확정하지 않는다. 근거는
[direct-call adjacency noncode exceptions audit](direct-call-adjacency-noncode-exceptions-audit.json)에 있다.

## startup entry and direct-call review

원본 `_start` 전이는 m68k의 absolute-long JMP와 SPARC의 branch displacement를 Python으로
계산해 각 raw symbol·code item·xref와 교차했다. 이어지는 startup sequence에서 m68k의
`_m68k_init`·`_startup_early`·`_setup_main`·`_start_initial_context`, SPARC의
`_module_setup`·`_sparc_init`·`_setup_main`·`_start_initial_context`으로 향하는 direct-call
instruction 네 개씩도 원본 encoding·raw symbol·xref와 일치한다.

이는 entry 전이와 call edge만 확정한다. callee behavior·인자·반환·ABI·startup outcome은
확정하지 않는다. 근거는 [entry transition audit](entry-transition-audit.json)과
[startup direct-call audit](startup-direct-call-edge-audit.json)에 있다.

양 아키텍처의 startup direct-call 네 개씩에 대해 바로 앞·call·바로 뒤 code item을 원본
bytes와 재대조했다. m68k `_start_initial_context` 바로 앞의 `move.l d0,-(sp)`와 SPARC
CALL의 delay-slot code item처럼 인접한 정적 사실을 보존하지만, 인자값·calling convention·
ABI·return value·side effect는 확정하지 않는다. 근거는
[startup direct-call adjacency audit](startup-direct-call-adjacency-audit.json)에 있다.

startup callee 여덟 entry는 모두 raw symbol·원본 code item·IDA 후보 시작점에 일치한다.
SPARC 네 entry는 모두 `9de3bf98`로 시작하며 IDA는 이를 `save %sp,-0x68,%sp`로 표시한다.
이는 entry boundary와 opening-instruction pattern의 근거이며, complete function extent·ABI·인자·
반환·동작은 확정하지 않는다. 근거는
[startup callee entry-candidate audit](startup-callee-entry-candidate-audit.json)에 있다.

SPARC startup callee 네 후보는 각각 후보 범위 안에 원본 `ret`/`restore` code pair 하나를
가진다. 이는 lexical return pair 존재만 보이며, 모든 경로의 도달성·특정 caller로의 복귀·
반환값·ABI·의미는 확정하지 않는다. 근거는
[SPARC startup callee lexical-return audit](sparc-startup-callee-lexical-return-audit.json)에 있다.

m68k startup callee 네 후보도 각각 후보 범위 안에 원본 `UNLK`/`RTS` code pair 하나를 가진다.
이는 lexical return pair 존재만 보이며, 모든 경로의 도달성·특정 caller로의 복귀·반환값·ABI·
의미는 확정하지 않는다. 근거는
[m68k startup callee lexical-return audit](m68k-startup-callee-lexical-return-audit.json)에 있다.

## full function-candidate lexical-exit audit

IDA 함수 후보 전체를 raw return opcode로 분류했다. m68k 3,214개 중 3,019개는 `RTS`를 하나
이상 포함하고 195개는 포함하지 않는다. SPARC 5,075개 중 4,936개는 `ret` 또는 `retl`을 하나
이상 포함하고 139개는 포함하지 않는다. 관측한 모든 return code item은 원본 big-endian bytes와
대조했다. return 부재는 후보 경계·non-returning·간접 전이 검토 대상일 뿐 함수 오류나 의미의
증거는 아니다. 근거는 [lexical-exit audit](function-candidate-lexical-exit-audit.json),
[m68k candidate TSV](../../../05_ida/exports/m68k/function-candidate-lexical-exits.tsv),
[SPARC candidate TSV](../../../05_ida/exports/sparc/function-candidate-lexical-exits.tsv)에 있다.

raw direct-call target과 이 분류를 교차하면 m68k 264개 edge가 lexical exit 없는 후보 50개를,
SPARC 356개 edge가 그러한 후보 59개를 향한다. m68k의 후보 시작점 밖 target 5개는 별도 보류한다.
이는 호출되는 raw control-flow review target의 우선순위일 뿐, non-returning behavior·잘못된
boundary·ABI·의미의 증거는 아니다. 근거는
[direct-call target lexical-exit coverage](direct-call-target-lexical-exit-coverage.json)에 있다.

고유 direct-call target entry도 원본 bytes로 다시 대조했다. m68k 2,313개는 lexical-exit 있는
후보 2,262개·없는 후보 50개·후보 시작점 밖 1개로, SPARC 2,607개는 lexical-exit 있는 후보
2,548개·없는 후보 59개로 분류된다. entry mnemonic은 IDA 관측값으로 함께 보존했지만, entry
bytes·mnemonic·lexical exit은 function boundary·prologue semantics·calling convention·ABI·
인자 위치·반환값·동작을 확정하지 않는다. 근거는
[direct-call target entry observations](direct-call-target-entry-observations.json)에 있다.

같은 entry 관측에서 m68k 고유 target의 첫 raw 2-byte prefix는 `4856` 1,673개와 `4e56` 562개가
가장 많고, IDA는 각각 `pea`·`link`로 표시한다. SPARC의 고유 target 2,465개는 IDA가 `save`로
표시한다. 이 분포는 raw entry bytes와 IDA disassembly의 분포일 뿐, conventional prologue·
function ownership·calling convention·ABI를 확정하지 않는다. 같은
[direct-call target entry observations](direct-call-target-entry-observations.json)에 있다.

entry의 raw operand field도 별도로 보존했다. m68k `LINK` entry 562개의 signed 16-bit immediate는
`-4` 159개·`-8` 81개·`-12` 42개 등이 가장 많다. SPARC IDA `save` entry 2,465개는 모두 raw
`i` bit 1, `rs1` field 14, `rd` field 14이며 signed 13-bit immediate는 `-104` 1,895개가 가장
많다. 이는 instruction-level raw operand 분포일 뿐 stack frame·local·argument·function boundary·
calling convention·ABI·동작을 확정하지 않는다. 근거는
[direct target entry frame-operand observations](direct-target-entry-frame-operand-observations.json)에 있다.

entry/exit 구조를 직접 교차하면 m68k `LINK` direct target 562개 중 6개는 lexical exit가 없고,
나머지 target의 lexical exit item 561개는 모두 IDA `unlk` 인접이다. SPARC IDA `save` target
2,465개 중 12개는 lexical exit가 없고, lexical exit item 2,462개는 `restore` 인접 2,460개,
`ldub`·`clrb` 인접 각 1개다. 이는 raw entry/return-adjacent pattern일 뿐 stack frame·return
execution·path·function boundary·calling convention·ABI·동작을 확정하지 않는다. 근거는
[direct target entry-exit structure audit](direct-target-entry-exit-structure-audit.json)에 있다.

SPARC의 두 non-`restore` return-adjacent item은 raw symbol `_strncpy` 0xf000791c의 세 `ret` pair 중
두 개다. 이 후보는 direct caller 30개와 contiguous code item 418개·1,680 bytes를 가지며, 세
delay-slot raw bytes는 `91ef4000`·`f60e4000`·`c02e0000`이다. 이는 bounded layout·caller·return
adjacency 관측일 뿐 delay-slot 실행·return behavior·path reachability·function boundary·ABI·
동작을 확정하지 않는다. 근거는
[SPARC save-ret nonrestore exception audit](sparc-save-ret-nonrestore-exception-audit.json)에 있다.

같은 `_strncpy` 후보 내부의 type-19 direct branch 101개도 raw big-endian `disp22`를 Python으로
계산해 xref와 대조했다. branch target은 모두 후보 내부이며 lexical `ret` 세 주소를 직접 target으로
하는 branch는 0개다. mnemonic 분포는 `ba` 37개·`bne` 33개·`be` 8개·`ba,a` 8개 등이다. 이는
direct branch graph 관측일 뿐 fall-through·path reachability·delay-slot 실행·return behavior·
complete boundary·ABI·동작을 확정하지 않는다. 근거는
[SPARC strncpy internal-branches audit](sparc-strncpy-internal-branches-audit.json)에 있다.

m68k `LINK` direct target 중 no-exit 후보 다섯 개도 caller encoding·entry·contiguous candidate layout·
terminal item을 원본 bytes로 대조했다. caller edge는 135개이고 entry signed immediate는 0 네 개·
`-4` 한 개, terminal mnemonic은 `bra.l` 네 개·`bsr.l` 한 개다. 비후보 `_mini_mon`은 기존 별도
감사를 유지한다. 이 결과는 terminal reachability·function behavior·calling convention·ABI·인자·
반환값·완전한 함수 경계를 확정하지 않는다. 근거는
[m68k LINK direct-target no-exit candidates audit](m68k-link-direct-target-noexit-candidates-audit.json)에 있다.

같은 다섯 후보 안의 type-19 direct branch 31개는 각 m68k big-endian Bcc/DBcc displacement를
Python으로 계산하여 xref target·source/target 원본 item bytes와 대조했다. target은 후보 내부 17개와
후보 밖 14개로 분포한다. 이는 direct target과 후보 범위의 관계만 보존하며, 분기 조건·fall-through·
path reachability·terminal behavior·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[m68k LINK no-exit candidate branches audit](m68k-link-noexit-candidate-branches-audit.json)에 있다.

이 후보 밖 target 14개가 향한 두 주소 `0x4001826`·`0x4001836`도 공유 도착점으로 독립 재감사했다.
두 주소의 모든 type-19 inbound branch 21개는 big-endian displacement 계산·xref·source 및 target
원본 item bytes에 일치한다. 첫 주소는 `_copywithin` 후보 안이고, 둘째 주소는 후보 밖이며, 두 주소에서
각각 세 개의 연속 code item window를 기록했다. 이 구조는 branch 조건·fall-through·실행·return behavior·
path reachability·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[m68k shared external branch targets audit](m68k-shared-external-branch-targets-audit.json)에 있다.

SPARC 함수 후보 밖 여덟 `__text` 범위의 type-19 direct branch source 232개도 big-endian `disp22`를
Python으로 계산하여 xref·source·delay-slot·target 원본 item bytes와 대조했다. source는 모두 현재 IDA
code item이고 delay-slot도 모두 code item이다. target은 후보 61개와 후보 밖 171개이며, 가장 큰 범위
`0xf0003aa4..0xf0004e70`에 source 209개가 있다. post-delay item은 code 217개·data 1개·text item 없음
14개로 기록했다. 이는 gap의 code ownership·분기 조건·delay-slot 실행·fall-through·path reachability·
함수 경계·ABI·동작을 확정하지 않는다. 근거는
[SPARC candidate-gap direct branches audit](sparc-candidate-gap-direct-branches-audit.json)에 있다.

m68k 함수 후보 밖 76개 `__text` 범위의 standard Bcc/DBcc type-19 source 2,429개도 big-endian
displacement를 Python으로 계산해 xref·source·즉시 다음 item·target 원본 mapping과 대조했다. target은
후보 57개·후보 밖 2,372개이며, target mapping은 text item start 2,428개와 text item 시작점이 아닌
mapped address 1개로 분리했다. 다음 item은 code 2,427개·data 2개다. 같은 source 모집단의 FPU branch
18개와 absolute-long `jmp` 2개도 별도 raw decoder로 target field·xref·source·다음 item·target code item에
대조했다. 이는 gap code ownership·분기 조건·fall-through·path reachability·함수 경계·ABI·동작을 확정하지
않는다. 근거는 [m68k candidate-gap Bcc/DBcc branches audit](m68k-candidate-gap-bcc-dbcc-branches-audit.json),
[m68k candidate-gap remaining type-19 transfers audit](m68k-candidate-gap-remaining-type19-transfers-audit.json)에 있다.

두 아키텍처의 위 raw-verified candidate-gap direct transfer를 gap topology로 Python 집계했다. m68k는
2,449개 중 같은 gap target 2,382개·다른 gap target 8개·후보 target 59개이며, 다른 gap edge는 네 gap
쌍에만 있다. SPARC는 232개 중 같은 gap target 171개·후보 target 61개이고 다른 gap edge는 없다. 이
집계는 입력 raw-audit report와 candidate TSV의 SHA-256을 보존한다. 직접 edge의 범위 관계일 뿐 gap code
ownership·분기 조건·실행·fall-through·path reachability·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[candidate-gap direct-transfer topology audit](candidate-gap-direct-transfer-topology-audit.json)에 있다.

동일 후보-gap source에서 raw-verified direct call까지 합친 직접 전이 분모도 별도로 고정했다. m68k는
call 1,127개와 branch 2,449개, 총 3,576개가 87개 gap에 있고 call target은 모두 후보 시작점이다.
SPARC는 call 28개와 branch 232개, 총 260개가 여덟 gap에 있으며 call target도 모두 후보 시작점이다.
각 입력 corpus·candidate TSV·원본 binary SHA-256을 보존했다. 이는 직접 edge의 주소 범위 관계일 뿐
gap code ownership·실행·경로·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[candidate-gap all-direct-transfer topology audit](candidate-gap-all-direct-transfer-topology-audit.json)에 있다.

이 직접 전이 gap의 bounded original `__text` layout도 item-by-item으로 원본 bytes에 재대조했다. m68k
87개 span은 총 63,004바이트이며 현재 item은 code 17,430개·data 37개, SPARC 여덟 span은 총 6,120바이트이며
code 1,431개·data 3개다. 각 span의 concatenated item bytes는 원본 span과 일치하고 span SHA-256을 기록했다.
현재 item 분류와 bounded layout은 gap code ownership·함수 경계·실행·도달성·ABI·동작을 확정하지 않는다. 근거는
[candidate-gap bounded text-layout audit](candidate-gap-bounded-text-layout-audit.json)에 있다.

m68k `JSR` raw opcode-pattern도 `__text` 전체에서 census했다. 1,761개 중 absolute-long 형식 22개는
원본 32-bit target field·type-17 xref·이미 검증된 direct-call corpus와 일치한다. 나머지 1,739개는
`4e90`–`4e95` raw effective-address word 형식이며 원본 파일 bytes만으로 runtime target을 확정하지 않는다.
모든 source item은 원본 bytes에 일치하고 다음 text item은 모두 현재 code item이다. 이것은 opcode-pattern과
정적 xref 분포일 뿐 call 실행·return behavior·effective-address 값·runtime target·함수 경계·ABI·동작을
확정하지 않는다. 근거는 [m68k JSR opcode-pattern census audit](m68k-jsr-opcode-pattern-census-audit.json)에 있다.

SPARC 원본 `op=2/op3=0x38` code-item pattern도 전체 census했다. 6,264개는 원본 big-endian bytes와
일치하며 current IDA mnemonic은 `ret` 4,716개·`call` 737개·`jmp` 462개·`retl` 334개·`ret!` 15개로
관측된다. source는 후보 5,857개·후보 gap 407개, raw `i` bit는 0이 927개·1이 5,337개이고 다음 text item은
code 6,262개·data 2개다. 이는 raw field와 도구 관측의 분포일 뿐 instruction semantics·register value·
runtime target·실행·return behavior·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[SPARC op2/op3=0x38 census audit](sparc-op2-op3-38-census-audit.json)에 있다.

m68k `JMP` raw opcode-pattern도 `__text` 전체에서 census했다. 164개 중 absolute-long 형식 42개는
원본 32-bit target field·type-19 xref·target code item에 일치한다. 나머지 122개는 `4ed0`–`4ed2` 또는
`4efb` raw effective-address word 형식이며 original file bytes만으로 runtime target을 확정하지 않는다.
이는 opcode-pattern과 직접 xref의 구조 사실일 뿐 JMP 실행·effective-address 값·runtime target·도달성·
함수 경계·ABI·동작을 확정하지 않는다. 근거는
[m68k JMP opcode-pattern census audit](m68k-jmp-opcode-pattern-census-audit.json)에 있다.

m68k `__text` source의 type-19 direct transfer 전체 28,285개도 raw encoder 전수 audit을 통과했다.
big-endian Bcc/DBcc/FPU branch displacement와 absolute-long JMP target field를 Python으로 계산해 모두 xref
target 및 원본 mapping에 일치시켰다. source는 후보 25,836개·candidate gap 2,449개이고 target은 code-item
start 28,282개·mapped text item 시작점 밖 주소 3개다. source 직후 item은 code 28,255개·data 30개이며, 이
33개 경계 예외는 raw context로 보존했다. 이는 direct transfer의 encoding·주소 관계일 뿐 branch condition·
실행·fall-through·path reachability·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[m68k all type-19 direct-transfer audit](m68k-all-type19-direct-transfers-audit.json)에 있다.

SPARC `__text` source의 standard `op=0/op2=2` type-19 branch 전체 31,743개도 raw encoder 전수 audit을
통과했다. 모든 big-endian `disp22` target은 type-19 xref와 target code item에 일치한다. source는 후보
31,511개·candidate gap 232개이며 delay-slot item은 code 31,741개·data 2개, post-delay item은 code
31,702개·data 2개·text item 없음 39개다. unique branch 43개의 raw boundary context를 보존했다. 이는 direct
branch encoding·주소 관계일 뿐 branch condition·delay-slot 실행·fall-through·path reachability·함수
경계·ABI·동작을 확정하지 않는다. 근거는
[SPARC all standard type-19 branch audit](sparc-all-standard-type19-branches-audit.json)에 있다.

standard branch 형식 밖의 SPARC `op3=0x38` type-19 xref도 별도 보존했다. 105개 candidate source에서
690개 xref edge가 681개 고유 candidate target으로 향하며 source·target code item과 최대 세 predecessor
item은 모두 원본 big-endian bytes에 일치한다. 이는 IDA가 제시한 xref target set의 raw-address 대조이지
instruction으로부터 target을 계산한 결과가 아니다. register value·runtime target·dispatch semantics·
실행·도달성·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[SPARC op3=0x38 type-19 xref census audit](sparc-op3-38-type19-xref-census-audit.json)에 있다.

별도로 type-3 xref를 가진 `op3=0x38` 259개는 직전 raw `sethi`의 high-22 field와 현재 signed low-13 field를
Python으로 조합해 target을 계산했다. 모두 type-3 xref와 original target item에 일치한다. source는 candidate
gap 255개·candidate 4개이고 target item은 code 252개·data 7개이며 delay-slot item은 모두 현재 code item이다.
이는 제한된 two-item raw address construction일 뿐 transfer execution·delay-slot 실행·도달성·함수 경계·ABI·
동작을 확정하지 않는다. 근거는
[SPARC sethi/op3=0x38 type-3 target audit](sparc-sethi-op3-38-type3-targets-audit.json)에 있다.

위 계산 target 중 현재 data item인 7개 edge와 6개 고유 target도 별도 bounded-window audit을 통과했다.
각 `sethi`/`op3=0x38` raw field 계산·target data item·전후 두 item window는 원본 big-endian bytes에 일치한다.
data item은 그대로 유지한다. 이 raw boundary 근거는 code/data 재분류·transfer 실행·delay-slot 실행·도달성·
함수 경계·ABI·동작을 확정하지 않는다. 근거는
[SPARC sethi/op3=0x38 data-target window audit](sparc-sethi-op3-38-data-target-windows-audit.json)에 있다.

m68k type-19 계산 target 중 text item 시작점이 아닌 3개 edge와 2개 고유 주소도 bounded-window audit을
통과했다. 각 big-endian target field 계산·target-relative 원본 4바이트·포함 item·전후 두 item window가
원본에 일치한다. 이는 instruction boundary나 code/data 분류를 바꾸지 않는 raw mapping 근거이며 branch
실행·도달성·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[m68k type-19 non-item-target window audit](m68k-type19-nonitem-target-windows-audit.json)에 있다.

함수 후보 전체의 시작 item도 원본 bytes로 census했다. m68k 후보 3,214개는 모두 current code item이며 raw
`LINK` word `4e56` 시작이 742개, 그중 direct-call target start와 주소가 겹치는 것은 561개다. SPARC 후보
5,075개도 모두 current code item이며 raw `save` `op=2/op3=0x3c` 시작이 4,725개, 그중 direct-call target
start와 겹치는 것은 2,465개다. 이는 raw entry pattern과 address overlap일 뿐 stack frame·함수 경계·호출 규약·
ABI·인자·반환값·실행·동작을 확정하지 않는다. 근거는
[all-candidate entry-pattern audit](all-candidate-entry-patterns-audit.json)에 있다.

두 big-endian 원본의 control-transfer opcode coverage도 raw count와 기존 audit 분모로 closure했다. m68k는
BSR 10,521개·non-BSR Bcc 28,097개·DBcc 113개·JSR 1,761개·JMP 164개가 각각 해당 audit/corpus와 일치한다.
SPARC는 `CALL` op=1 17,607개·standard branch `op=0/op2=2` 31,743개·`op=2/op3=0x38` 6,264개가 해당
audit/census와 일치한다. 각 입력 report와 원본 binary hash도 보존했다. 이는 static coverage closure일 뿐
instruction semantics·register value·runtime target·실행·도달성·함수 경계·ABI·동작을 확정하지 않는다. 근거는
[multiarch control-transfer coverage closure audit](multiarch-control-transfer-coverage-closure-audit.json)에 있다.

lexical-exit 부재의 호출 대상은 caller encoding→target entry→candidate terminal을 원본 bytes로
하나의 정적 근거 체인으로 연결했다. m68k는 후보 50개와 caller edge 264개, SPARC는 후보 59개와
caller edge 356개가 각각 Python target 계산·type-17 xref·entry/terminal 원본 code item에
일치한다. 이 체인은 entry에서 terminal로의 path, call return·reachability·boundary·ABI·동작을
확정하지 않는다. 근거는
[called no-exit candidate endpoint-chain audit](called-noexit-candidate-endpoint-chain-audit.json)에 있다.

이 직접 호출 no-exit 후보의 후보 범위 layout도 전수 원본 bytes로 대조했다. m68k 후보 50개는
연속 code item 1,543개·6,452 bytes, SPARC 후보 59개는 860개·3,516 bytes만 포함한다. 이것은
candidate range 안의 raw code-only 연속성일 뿐 entry에서 terminal까지의 도달성·complete function
boundary·control flow·ABI·동작을 확정하지 않는다. 근거는
[called no-exit candidate text-layout audit](called-noexit-candidate-text-layout-audit.json)에 있다.

lexical exit가 있는 호출 대상도 entry와 후보 범위 안의 raw return opcode를 대조했다. m68k는 후보
2,262개·caller edge 10,274개·lexical exit code item 2,317개, SPARC는 후보 2,548개·caller edge
17,251개·lexical exit code item 2,578개다. 이는 direct-call corpus와 entry/return endpoint의
원본-byte 대응이며, entry→exit 경로·call return·reachability·function boundary·calling
convention·ABI·동작을 확정하지 않는다. 근거는
[called lexical-exit candidate endpoints audit](called-lexical-exit-candidate-endpoints-audit.json)에 있다.

이 return opcode의 인접 item도 원본 bytes로 확인했다. m68k `RTS` 직전 item 2,317개는 모두 code지만
1개는 현재 후보 범위 밖이며, IDA는 2,218개를 `unlk`로 표시한다. SPARC `ret`/`retl`의 delay slot
2,578개는 code 2,576개·data 2개이고 3개는 후보 범위 밖이며, IDA는 2,462개를 `restore`로 표시한다.
이는 return-adjacent item과 현재 후보 경계의 관측일 뿐 return 실행·return target·path
reachability·function boundary·calling convention·ABI·동작을 확정하지 않는다. 근거는
[called lexical-exit adjacency audit](called-lexical-exit-adjacency-audit.json)에 있다.

네 return-adjacency 예외도 개별 원본 boundary item과 direct caller를 대조했다. m68k
`_simple_unlock` 0x40018c2의 `RTS` 바로 앞은 별도 `RTS`이고 candidate end 다음은 `moveq #1,d0`다.
SPARC `sub_F0007114`와 `sub_F00071D8`의 두 번째 `retl` 뒤는 각각 raw data `01000000`이며,
`_syncfpu`의 두 번째 `retl` 뒤는 다음 code item `03000004`다. 이 raw layout은 code/data 재분류,
delay-slot 실행, return behavior·reachability·function boundary·ABI·동작을 확정하지 않는다. 근거는
[called lexical-exit adjacency exceptions audit](called-lexical-exit-adjacency-exceptions-audit.json)에 있다.

SPARC의 두 raw data `01000000`은 Capstone 4.0.2의 `CS_MODE_BIG_ENDIAN` independent decoder가 각각
`nop`으로 표시한다. IDA text item은 그대로 data로 유지한다. decoder 표시 하나만으로 code/data
재분류, delay-slot 실행, reachability·function boundary·ABI·동작을 확정하지 않는다. 근거는
[SPARC return-delay data independent-decoder observation](sparc-return-delay-data-independent-decoder-observation.json)에 있다.

최다 호출 lexical-exit 부재 후보 두 개를 raw tail transfer로 확인했다. m68k `_copyoutmsg`의
마지막 branch `60ff0000016a`는 Python 계산으로 0x4001836(현재 후보 범위 밖)으로 향하고, SPARC
`.udiv`의 `1080000b`는 0xf000662c(다음 `.div` 후보 안)으로 향한다. 양쪽 branch는 원본
big-endian bytes와 type-19 xref로 대조했다. 이는 return 부재의 구체적 제어 흐름 근거이며,
target 의미·ABI·값·동작은 확정하지 않는다. 근거는
[high-call no-exit tail-transfer audit](high-call-noexit-tail-transfer-audit.json)에 있다.

lexical exit 없는 후보 전체의 마지막 code item도 원본 bytes와 대조했다. m68k 195개는 `bra`
114개·`jmp` 36개·`rte` 8개 등을, SPARC 139개는 `nop` 59개·`ba,a` 15개·`illtrap` 9개·`restore`
9개 등을 보인다. mnemonic은 IDA disassembly 관측이므로 tail transfer·trap·boundary의 의미를
확정하지 않는다. 근거는 [terminal-item audit](noexit-candidate-terminal-item-audit.json),
[m68k terminal TSV](../../../05_ida/exports/m68k/noexit-candidate-terminal-items.tsv),
[SPARC terminal TSV](../../../05_ida/exports/sparc/noexit-candidate-terminal-items.tsv)에 있다.

이 중 직접 무조건 branch terminal을 전수 계산했다. m68k 114개는 same candidate 25개·other
candidate 80개·후보 범위 밖 9개이고, SPARC 15개는 same candidate 8개·other candidate 7개다.
모든 computed target은 원본 big-endian bytes와 type-19 xref에 일치한다. 이는 raw static
control-transfer 분포이고 path reachability·complete boundary·ABI·동작을 확정하지 않는다.
근거는 [terminal direct-branch audit](noexit-terminal-direct-branch-audit.json),
[m68k branch TSV](../../../05_ida/exports/m68k/noexit-terminal-direct-branches.tsv),
[SPARC branch TSV](../../../05_ida/exports/sparc/noexit-terminal-direct-branches.tsv)에 있다.

lexical-exit 부재 후보의 terminal `jmp`/`call`도 분리했다. m68k `jmp` 36개 중 20개는
absolute-long direct jump로 원본 target과 type-19 xref가 일치하며, 16개는 register-indirect
jump라 runtime target을 미확정으로 유지한다. SPARC terminal `call` 4개는 relative direct
encoding과 type-17 xref가 일치한다. 근거는
[terminal jump/call transfer audit](noexit-terminal-jump-call-transfer-audit.json),
[m68k transfer TSV](../../../05_ida/exports/m68k/noexit-terminal-jump-call-transfers.tsv),
[SPARC transfer TSV](../../../05_ida/exports/sparc/noexit-terminal-jump-call-transfers.tsv)에 있다.

m68k register-indirect terminal jump 16개는 직전 최대 세 code item의 원본 bytes를 대조했다.
window 관측은 register restore 5개·indexed memory load 8개·absolute memory load 2개·미해결
1개다. 이것은 target register의 제한된 provenance 관측이고 runtime value·jump target·ABI·
동작은 확정하지 않는다. 근거는
[m68k indirect-jump provenance audit](m68k-terminal-indirect-jump-provenance-audit.json)에 있다.

indexed memory-load window 8개는 raw `LEA` base부터 연속으로 code-item start를 가리키는
big-endian pointer word 112개를 보인다. 각 pointer word와 target code-item start는 원본 bytes로
대조했다. 이는 잠재 target 집합의 보수적 관측이며 pointer run이 완전한 dispatch table인지,
index bound·runtime 선택·reachability·ABI·동작은 확정하지 않는다. 근거는
[m68k indexed-jump pointer-run audit](m68k-indexed-jump-pointer-run-audit.json)에 있다.

absolute-memory provenance 두 사례도 원본 파일만으로 target을 확정할 수 없다. `_call_continuation`
terminal jump register는 stack-derived load 뒤에 오며, `_mon_exit`의 `_reboot_vector`는 file
offset 0의 non-file-backed `__DATA,__common`에 있다. 따라서 두 runtime target을 미해결로
유지한다. 근거는 [m68k absolute indirect-jump unresolved audit](m68k-absolute-indirect-jump-unresolved-audit.json)에 있다.

SPARC lexical-exit 부재 후보의 terminal `restore`/`return` 13개는 바로 앞에 `jmp` 12개 또는
`ba` 1개가 있다. pair의 원본 big-endian bytes를 대조했고, `ba` 한 건의 disp22 target은
type-19 xref와 일치한다. 이는 static delay-slot adjacency evidence이며 architectural execution·
reachability·return behavior·ABI·의미를 확정하지 않는다. 근거는
[SPARC restore/return window audit](sparc-noexit-restore-return-window-audit.json)에 있다.

m68k lexical-exit 부재 후보의 terminal BSR.L 18개는 모두 원본 target 계산과 type-17 xref에
일치한다. 다음 fall-through address는 원본 code item이며 후보 범위 밖 17개·다른 후보 1개다.
이는 call 뒤 static code address와 현재 IDA 후보 경계의 검토 근거이고, call return·reachability·
candidate ownership·ABI·동작을 확정하지 않는다. 근거는
[m68k terminal BSR fall-through audit](m68k-noexit-terminal-bsr-fallthrough-audit.json)에 있다.

SPARC lexical-exit 부재 후보의 terminal `nop` 59개도 바로 앞에 `jmp` 55개 또는 `ba` 4개가
있다. 모든 pair의 원본 big-endian bytes를 대조했고, `ba` 네 건은 disp22 target과 type-19
xref가 일치한다. 이것도 static delay-slot adjacency evidence이며 execution·reachability·
return behavior·ABI·의미를 확정하지 않는다. 근거는
[SPARC nop window audit](sparc-noexit-nop-window-audit.json)에 있다.

m68k lexical-exit 부재 후보의 terminal `RTE` 8개는 앞 최대 두 code item과 함께 원본
big-endian bytes를 대조했다. 이는 일반 `RTS`와 다른 raw exception-return opcode 관측이며,
exception frame validity·runtime control target·reachability·ABI·동작을 확정하지 않는다. 근거는
[m68k RTE window audit](m68k-noexit-rte-window-audit.json)에 있다.

SPARC lexical-exit 부재 후보의 terminal `illtrap` 9개도 원본 4-byte big-endian instruction
word와 후보 경계로 대조했다. 이는 raw trap opcode 관측이며 trap handling·runtime reachability·
control target·ABI·동작을 확정하지 않는다. 근거는
[SPARC illtrap terminal audit](sparc-noexit-illtrap-terminal-audit.json)에 있다.

no-exit terminal analysis coverage를 전수 집계했다. m68k 195개 중 176개 terminal item 형식은
전용 정적 감사로 다뤘고 19개가 남은 review queue에 있다. SPARC 139개 중 100개 형식을 다뤘고
39개가 남았다. 이는 bounded static audit coverage이며 함수 경계·reachability·ABI·의미 완료율은
아니다. 근거는 [terminal analysis coverage audit](noexit-terminal-analysis-coverage-audit.json),
[m68k review queue](../../../05_ida/exports/m68k/noexit-terminal-review-queue.tsv),
[SPARC review queue](../../../05_ida/exports/sparc/noexit-terminal-review-queue.tsv)에 있다.

m68k 남은 queue의 terminal JSR 5개도 검증했다. absolute-long direct 4개는 원본 target과
type-17 xref가 일치하고 register-indirect 1개는 target을 미확정으로 유지한다. fall-through는
다른 후보 4개·후보 범위 밖 1개다. 이는 static call/fall-through 및 경계 검토 근거이며 call
return·reachability·ABI·동작을 확정하지 않는다. 근거는
[m68k terminal JSR fall-through audit](m68k-noexit-terminal-jsr-fallthrough-audit.json)에 있다.

m68k queue의 나머지 terminal 14개(`subi`·FPU·conditional branch·state-save 등)는 마지막 세
code item과 candidate end 다음 text item을 원본 big-endian bytes로 대조했다. data/unknown
경계를 code로 강제하지 않은 raw boundary 관측이며, transfer semantics·reachability·function
boundary·ABI·동작을 확정하지 않는다. 근거는
[m68k remaining terminal-window audit](m68k-remaining-noexit-terminal-window-audit.json)에 있다.

SPARC queue의 나머지 terminal 39개(`mov` 17개·`st` 8개·`bset` 4개·`ld` 3개 등)도 마지막 세
code item과 candidate end 다음 text item을 원본 big-endian bytes로 대조했다. 이는 code/data
경계를 바꾸지 않은 raw boundary 관측이며, transfer semantics·reachability·function boundary·ABI·
동작을 확정하지 않는다. 근거는
[SPARC remaining terminal-window audit](sparc-remaining-noexit-terminal-window-audit.json)에 있다.

후속 JSR·remaining-window 감사를 포함한 closure에서는 m68k terminal candidate 195개와 SPARC
139개 모두가 하나의 raw encoding 또는 bounded raw-window 감사에 배정됐고, 미배정은 양쪽 모두
0개다. 이는 terminal byte/인접 window coverage의 종료 조건일 뿐 transfer semantics·path
reachability·function boundary·calling convention·ABI·return behavior·동작의 완료 조건은 아니다.
근거는 [no-exit terminal raw-coverage closure audit](noexit-terminal-raw-coverage-closure-audit.json)에 있다.

## direct-call function-candidate coverage

direct-call edge source를 현재 IDA 함수 후보 범위와 교차했다. SPARC 17,607개 중 17,579개는
후보 범위 하나에, 28개는 후보 범위 밖에 있었다. m68k 10,543개 중 9,416개는 후보 범위 하나에,
1,127개는 후보 범위 밖에 있었다. target 후보 시작점 일치는 SPARC 17,607개 전체와 m68k
10,538개였다. 이 수치는 Python으로 계산했다.

m68k의 후보 범위 밖 source 1,127개는 원본 `__text`의 66개 gap에 분포한다. 가장 큰 세 gap은
각각 163개·110개·58개 source를 포함하며, code/data나 missing function의 증거로 단정하지
않는다. 이 gap들은 함수 경계·제어 흐름 의미 검증의 우선 review target이다. 근거는
[function-candidate coverage](direct-call-function-candidate-coverage.json)와
[m68k gap audit](m68k-direct-call-outside-function-candidates.json)에 있다.

66개 m68k gap 모두에서 gap 시작·끝 item과 첫·마지막 direct-call source를 원본 big-endian bytes로
대조했다. source가 겹치는 gap endpoint를 제거한 표본은 120개이며, 각 BSR/JSR target은 Python
encoding 계산과 type-17 xref 및 원본 target code item에 일치한다. 이는 gap 경계와 endpoint
control-transfer의 제한된 관측이며, 함수 ownership·완전한 경계·call return·reachability·ABI·
동작을 확정하지 않는다. 근거는
[m68k gap boundary-endpoint audit](m68k-direct-call-gap-boundary-endpoints-audit.json)에 있다.

m68k gap의 direct-call source 1,127개 전부도 source encoding·Python target 계산·type-17 xref와
직후 text item을 대조했다. 직후 item은 모두 원본 code item이며 같은 candidate-gap 안에 있다.
이는 call 뒤의 정적 인접 주소 관측일 뿐 call return·실행·함수 ownership·reachability·ABI·동작을
확정하지 않는다. 근거는
[m68k gap direct-call next-item audit](m68k-gap-direct-call-next-item-audit.json)에 있다.

SPARC의 후보 범위 밖 source 28개는 원본 `__text` 0xf0003aa4–0xf0004e70 gap 하나에
모여 있으며, 28개 CALL instruction bytes를 원본 big-endian bytes와 모두 대조했다. 이 역시
함수 누락·code/data 오류·ABI·동작의 증거가 아니라 제한된 함수 경계 review target이다. 근거는
[SPARC gap audit](sparc-direct-call-outside-function-candidates.json)에 있다.

같은 28개 CALL은 각각 직전 instruction·CALL·delay slot·직후 instruction의 code window와 target
entry를 원본 big-endian bytes로 대조했다. CALL `disp30` target은 Python으로 계산해 type-17 xref와
일치했고, target은 모두 원본 code item 및 현재 IDA 후보 시작점이었다. raw symbol edge 수는
`_flush_writebuffers` 13개·`_not_serviced` 13개·`_printf`와 `_l15_async_fault` 각 1개다. 이는
정적 CALL window·target 관측일 뿐 delay-slot 실행·call return·gap ownership·reachability·ABI·
동작을 확정하지 않는다. 근거는
[SPARC gap direct-call window audit](sparc-gap-direct-call-window-audit.json)에 있다.

이 28개 CALL의 delay slot과 delay-slot 다음 item도 각각 모두 원본 code item이며 같은 gap 안에
있다. 이는 SPARC delayed-control-transfer의 정적 item adjacency만 보존하며 delay-slot 실행,
CALL의 복귀, reachability, 함수 경계, ABI 및 동작을 확정하지 않는다. 같은
[SPARC gap direct-call window audit](sparc-gap-direct-call-window-audit.json)에 있다.

이 SPARC gap 직전의 IDA 후보는 원본 branch `10bffe81`와 delay slot `9c100017` 뒤에서
끝나며, Python으로 계산한 branch target 0xf00034a0은 gap 밖이다. gap으로 들어오는 direct
control xref 152개도 모두 gap 내부 source에서 출발한다. 이 관측은 gap을 단순 fall-through나
독립 함수로 확정하지 않으며, runtime reachability·interrupt behavior·ABI·의미는 미확정이다.
근거는 [SPARC gap boundary observation](sparc-direct-call-gap-boundary-observation.json)에 있다.

## m68k noncandidate direct-call target review

m68k에서 후보 함수 시작점과 일치하지 않은 direct-call 다섯 건은 모두 원본 raw symbol
`_mini_mon`의 0x4093976으로 향한다. 다섯 BSR.L source와 target의 첫 code item
`4e56fefc`는 원본 `__text` 바이트와 각각 대조했다. 이 결과는 해당 주소가 direct-call
destination 및 code-item start임을 강하게 뒷받침하지만, IDA 후보 범위에 없는 사실만으로
함수 경계·ABI·인자·반환·callee semantics를 확정하지 않는다. 근거는
[m68k noncandidate target review](m68k-direct-call-target-noncandidate-review.json)에 있다.

`_mini_mon` 0x4093976은 raw symbol, 이 주소로 계산되는 BSR.L 다섯 개, 첫 code item
`4e56fefc`, 이후 첫 lexical `UNLK`/`RTS` code pair `4e5e`/`4e75`를 원본 big-endian
bytes에서 모두 대조했다. 이는 제한된 함수 경계 review evidence이며, lexical exit까지의
도달성·전체 extent·calling convention·argument·return·ABI·callee behavior는 확정하지 않는다.
근거는 [m68k mini_mon boundary evidence](m68k-mini-mon-boundary-evidence.json)에 있다.

같은 제한 구간에서 raw prologue·register save/restore·lexical exit와 `a6` relative code item
20개를 원본 bytes에 대조했다. 관측된 positive offset은 0x8부터 0x20까지, negative offset은
-0x12c부터 -0xff까지다. frame-like layout 가설에는 근거가 추가되지만, positive offset을
인자나 negative offset을 local variable로 확정하지 않으며 ABI·type·value·동작도 미확정이다.
근거는 [m68k mini_mon frame-access observation](m68k-mini-mon-frame-access-observation.json)에 있다.

`_mini_mon` 시작부터 첫 lexical `RTS` 직후까지의 연속 text item 347개도 원본 big-endian bytes로
대조했다. 이 구간에는 code 346개뿐 아니라 0x4093b2e의 2-byte IDA data item `02d6` 하나가 있다.
그러므로 이 bounded range를 연속 code 또는 완전한 함수 extent로 확정하지 않는다. direct control
xref는 구간 안으로 66개(구간 밖 source 5개), 구간 밖으로 37개를 보이지만, 이 분포도
reachability·ownership·ABI·인자·반환값·동작을 확정하지 않는다. 근거는
[m68k mini_mon bounded text-layout audit](m68k-mini-mon-bounded-text-layout-audit.json)에 있다.

## retained m68k unknown bytes

0x409ce56–0x409ce5c의 원본 `c1e000000000`은 canonical IDA에서 여섯 1-byte unknown unit으로
남아 있다. m68k big-endian Capstone은 이를 sequential `muls.w`·`ori.b`로 해석할 수 있지만,
그 해석은 code/data 구분이나 도달성을 증명하지 않으며 기존 FPU operand xref 관측과 함께 decisive
evidence가 되지 않는다. 그러므로 DB를 수정하지 않고 unknown 상태를 보존한다. 근거는
[independent decoder observation](m68k-unknown-independent-decoder-observation.json)에 있다.

## 30회 연속 정적 감사

원본 provenance부터 text unit·xref·Capstone 관측·unknown 보류·경로 격리까지 서로 다른
30개 정적 감사를 순차 수행했다. 25개 불변식 통과와 5개 비확정 관측을 구분해 보존하며,
함수 경계·symbol 의미·decoder 해석을 과장하지 않았다. 상세 내용은
[30회 연속 감사](../multiarch-continuous-20260921/README.md)에 있다.

2026-09-22에는 새 전용 경로에서 원본 hash·big-endian IDA 조건·xref endpoint·unknown 보류·
SPARC raw `__OBJC` NUL-section evidence를 포함한 별도 30회 감사를 수행했다. 통과 28개와
비확정 관측 2개를 분리했으며, 상세 내용은
[2026-09-22 30회 연속 감사](../multiarch-continuous-20260922/README.md)에 있다.

동일 불변식을 새 전용 경로에서 다시 순차 대조한 continuation 2 감사도 통과 28개와 비확정
관측 2개를 분리해 보존했다. 상세 내용은
[2026-09-22 continuation 2 30회 감사](../multiarch-continuous-20260922-continuation2/README.md)에 있다.

steps3 전용 경로의 30단계 순차 감사도 통과 28개와 비확정 관측 2개를 분리해 보존했다. 상세
내용은 [2026-09-22 steps3 30단계 감사](../multiarch-continuous-20260922-steps3/README.md)에 있다.

## 범위

이 결과는 원본 입력의 보존·형식·byte order만 확정한다. m68k/SPARC의 함수 경계, 의미,
ABI, decompiler 정확성, 소스 복원, 빌드 및 실행은 아직 판정하지 않았다. 이후 정적 분석은
[다중 아키텍처 계획](../../../02_plan/MULTIARCH_STATIC_ANALYSIS.md)의 byte order 불변식을
따른다.
