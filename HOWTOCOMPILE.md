# HOWTOCOMPILE — OPENSTEP 4.2 실기에서 x86 커널 빌드하기

이 문서는 `07_kernel/` 의 복원 소스를 OPENSTEP 4.2 i386 실기에서 컴파일하고 링크해
`mach_kernel` 을 만드는 방법을 적습니다. 2026-10-08 에 이 절차로 만든 커널은 원본
`03_original/x86/binaries/mach_kernel` 과 바이트 단위로 같았습니다(run `s6p404-ln1`,
SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`,
1,117,920 B). 근거와 경위는 `02_plan/RECONSTRUCTION_PLAN.md` 393–405 절에 있습니다.

## 1. 준비물

| 항목 | 내용 |
|---|---|
| 빌드 호스트 | OPENSTEP 4.2 i386 실기. 컴파일러 `cc-744.13`(`NeXT Software, Inc. version cc-744.13, gcc version 2.7.2.1`) |
| 실기 도구 | `/bin/cc`, `/bin/as`, `/bin/ld`, `/bin/strip`, `/usr/bin/mig`, `/lib/cpp`, `/lib/i386/*`, 라이브러리 `/lib/libcc.a`. 도구 16 개의 해시(실기 = i386 VM)는 `08_build/toolchains/real-i386-20261001/sha256-vs-vm.json`, `/usr/lib/migcom3` 은 `real-only-20261002.json`(로컬 전용 디렉터리). 실행할 때 kr_run 이 해시를 검사하는 것은 `kr_run.py` 의 `ALLOWED_TOOLS` 9 개뿐입니다(`/lib/i386/cc1obj` 등 백엔드와 `/lib/libcc.a` 는 실행 시 검사하지 않음; `/lib/libcc.a` 는 2026-10-08 krsha256 으로 원본 보관본 `03_original/x86/userland/binaries/lib/libcc.a` 와 같음을 따로 확인) |
| 파일 공유 | 실기가 호스트의 `NeXT_DRIVER/` 디렉터리를 NFS 로 `/ndrv` 에 마운트합니다. 이 저장소는 실기에서 `/ndrv/openstep-kernel-remade` 입니다 |
| 원격 실행 | 호스트의 `NeXT_DRIVER/bin/gcds` 와 저장소 밖 설정 파일 `NeXT_DRIVER/etc/gcds.cnf` 로 실기에 명령을 보냅니다. 주소·계정은 이 설정 파일에만 있고 저장소에는 넣지 않습니다 |
| 호스트 | Python 3(도구 실행), 이 저장소, `01_resources/` 의 참조 원문(Darwin 0.1·NeXTMach·Mach4), 실기에서 읽어 온 SDK 머리 사본 `07_kernel/nextdev/` 와 그 위에 쓴 작성 머리 `07_kernel/nextdev_private/`(둘 다 로컬 전용, D017·D018·D023 — 공개 저장소에는 없으므로 따로 갖춰야 함), krsha256 도구 `08_build/runs/tools/target/krsha256-default`, 이전 기록(`06_reconstruction/l2_build_forms.tsv`, 그 행이 가리키는 `08_build/runs/<run>/` 의 실행 기록·스테이징 manifest, 기준선 `09_validation/reconstruction/s6-l2-baseline-20261008/`) |

연결 확인(호스트의 `NeXT_DRIVER/` 에서):

```sh
GCDS_CONF=etc/gcds.cnf ./bin/gcds next 'cc -v; ls -l /bin/ld /bin/strip /lib/libcc.a'
```

실기 재부팅, 커널 교체, 데몬 재시작은 사용자가 합니다. 빌드 출력은 모두 NFS 위 `08_build/runs/<RID>/` 에 씁니다.
예외: G3 묶음(원본 ObjC 모듈 이름이 절대 경로인 객체 19 개)은 실기의 심볼릭 링크
`/BinarySourceCache_Mario1A/mk/mk-183.34.4` → `/ndrv/openstep-kernel-remade/08_build/runs/ABSROOT` 가
있어야 합니다(사용자가 한 번 만들어 둠, 계획 304). kr_run 은 명령 파일에 `ABSROOT` 가 있으면 실행마다
`08_build/runs/ABSROOT` 를 그 실행의 `src/src` 로 다시 걸고 끝나면 지웁니다.

## 2. 소스와 컴파일 꼴

- 복원 소스: `07_kernel/src/`(Darwin `kernel/` 경로 꼴), 생성 머리 `07_kernel/generated/`
  (`10_tools/reconstruction/gen_config_headers.py` 가 `06_reconstruction/config_options.tsv` 로 만듦;
  `--check` 로 확인), SDK 머리 사본 `07_kernel/nextdev/`, 작성 머리 `07_kernel/nextdev_private/`.
- 객체마다 컴파일 명령은 `06_reconstruction/l2_build_forms-s6p398.tsv` 의 `argv`·`runin_dir`·
  `stage_options` 열에 있습니다(402 행: 기록된 객체 385 + 데이터만 있는 객체 17). 이 표는
  `python3 10_tools/reconstruction/l2_forms_s6p398.py OUT.tsv OUT_EXPECT.json` 으로 다시 만들 수 있습니다.
- 커널 C 파일의 기본 꼴(예):

  ```
  /bin/cc -arch i386 -static -fwritable-strings -traditional-cpp -nostdinc
    -imacros src/generated/meta_features.h -DARCH_PRIVATE -D_KERNEL -DKERNEL
    -DKERNEL_PRIVATE -DDRIVER_PRIVATE -DKERNEL_BUILD -DINET -DMACH -DMULTICAST
    -DPOSIX_KERN -D_POSIX_SOURCE -DNeXT -D_NEXT_SOURCE -Isrc/generated -Isrc/src
    -Isrc/src/bsd -Isrc/src/bsd/include -Isrc/src/machdep -Isrc/components
    -Isrc/components/architecture -Isrc/components/driverkit-1 -Isrc/nextdev
    -Isrc/nextdev/bsd -Isrc/nextdev/ansi -g -O3 -fno-omit-frame-pointer
    -c src/src/<경로>.c -o stage/<이름>.o
  ```

  libDriver(`-fwritable-strings` 없음, 일부 `-DMACH_USER_API`), ObjC 런타임(`-O`), libc(대부분 `-O4`,
  일부 `-funroll-all-loops`, `pagesize.c` 는 `-O3`) 등은 표의 꼴을 그대로 씁니다. `-fno-common` 은 쓰지 않습니다
  (`08_build/GCC27_COMPATIBILITY.md`).

## 3. 스테이징

먼저 생성 머리를 만들고 확인합니다.

```sh
python3 10_tools/reconstruction/gen_config_headers.py
python3 10_tools/reconstruction/gen_config_headers.py --check
```

컴파일은 실기에서 `08_build/runs/<RID>/src/` 아래의 스테이징 사본으로 합니다. 스테이징은
호스트에서 `stage_headers.py` 가 소스와 그 include 닫힘을 모읍니다.

```sh
python3 10_tools/reconstruction/stage_headers.py --prefer-07 --nextdev --bsd-set nextos \
    --mach-set sdk STAGE_DIR bsd/kern/tty.c [다른 소스 ...]
```

- 결과 `STAGE_DIR.manifest.json` 에 파일마다 출처와 SHA-256 이 적힙니다. 최종 빌드는
  07 밖에서 읽는 파일이 없어야 합니다(아래 5 절의 `cc -M` 검사).
- 첫 인자는 스테이징 디렉터리입니다. `--help` 같은 낱말을 첫 위치에 주면 그 이름의 디렉터리가
  만들어지니 주의하십시오.

## 4. 실행 규약: kr_run

모든 빌드는 `10_tools/reconstruction/kr_run.py` 로 합니다. 명령 파일(`RUN`·`RUNIN`·`EXPECT` 줄)을
받아 실기에서 실행하고, 입력·도구·출력을 SHA-256 으로 검증합니다.

```sh
python3 10_tools/reconstruction/kr_run.py prepare RID STAGE_DIR CMDFILE   # 08_build/runs/RID 생성(같은 RID 재사용 금지)
python3 10_tools/reconstruction/kr_run.py launch  RID                     # 실기에서 run.sh 시작(gcds)
python3 10_tools/reconstruction/kr_run.py wait    RID                     # DONE/FAILED 까지 기다림
python3 10_tools/reconstruction/kr_run.py collect RID                     # 검증 뒤 stage/ -> out/ 공개
```

- 허용 도구는 `kr_run.py` 의 `ALLOWED_TOOLS` 와 해시 기록에 있는 것뿐입니다. 실행 스크립트가 빌드 전에
  실기 도구 해시를 검사합니다.
- 실패하면 `08_build/runs/<RID>/stage/_log/NN.err` 를 먼저 보고, 새 RID 로 다시 실행합니다.
- RID 는 정규식 `^[a-z0-9][a-z0-9._-]{2,60}$`(3–61 자, 첫 글자는 소문자나 숫자)에 맞아야 하고, 한 번 쓴 RID 는
  다시 쓰지 않습니다(`08_build/runs/REGISTRY`).
- `wait` 는 실행이 끝나고 실기의 LOCK 이 풀릴 때까지 최대 1,800 초 기다립니다(명령행으로 바꾸는 옵션 없음).
  더 오래 걸리면 `wait` 를 다시 부릅니다.

## 5. 전체 커널 빌드(402 객체)

객체는 스테이징 방식이 같은 묶음 G1·G2a·G2b·G3·G4·G5·G6 으로 나눠 빌드합니다
(`l2_rebuild.py groups` 로 확인). 묶음마다:

```sh
export L2_FORMS=06_reconstruction/l2_build_forms-s6p398.tsv
export L2_EXPECT=06_reconstruction/l2_expect-s6p398.json
G=G1; RID=<새 RID, 예: s6l5-g1a>
python3 10_tools/reconstruction/l2_rebuild.py prepare $G $RID
python3 10_tools/reconstruction/kr_run.py prepare $RID 08_build/runs/tools/$RID-stage 08_build/runs/tools/$RID.cmd
python3 10_tools/reconstruction/kr_run.py launch $RID
python3 10_tools/reconstruction/kr_run.py wait $RID
python3 10_tools/reconstruction/kr_run.py collect $RID
python3 10_tools/reconstruction/l2_rebuild.py check $G $RID 09_validation/reconstruction/s6-l1-$G-$RID.json
```

- `prepare` 는 객체마다 `cc -M` 줄과 컴파일 줄을 씁니다. `check` 는 (a) 객체가 모두 나왔는지,
  (b) `cc -M` 의존이 모두 07 에서 왔는지, (c) 원본과의 L1 비교가 기준선(또는 `L2_EXPECT` 의 기대)과
  같은지 봅니다. 결과의 `deps_not_from_07` 이 비어 있어야 합니다.
- `check` 는 통과/실패로 끝나지 않습니다(문제가 있어도 정상 종료). 결과 json 에서 `problem`, `same_as_baseline`/
  `expected_ok`, `deps_group_vs_singleton_differ`, `deps_not_from_07` 를 모두 확인해야 합니다. `l2_link.py` 는
  `problem`·기준선/기대 불일치만 거부합니다.
- G1(312 객체)은 실기에서 수십 분 걸립니다.
- 같은 접두어(예: `s6l5`)로 일곱 묶음을 모두 빌드하면 링크 입력이 갖춰집니다.

## 6. 링크와 strip

링크 순서와 명령은 `l2_link.py` 가 만듭니다. Darwin 0.1 의 커널 빌드 규칙
`LDOBJS=${LDOBJS_PREFIX} ${OBJS} subr_prof.o ioconf.o ${LDOBJS_SUFFIX}`(`conf/Makefile.template:232`; PREFIX = libc 객체,
SUFFIX = libDriver·libobjc 묶음, `conf/Makefile.i386:68–69`)와 `${LDOBJS} $(MACH_OFILES) vers.o … ${LIBS}`(`:386–387`)
를 따릅니다. 재구성 링크 목록에는 `subr_prof.o` 가 없습니다(Darwin `conf/files:391` 에서 `subr_prof.c` 는 주석 처리됨; 이 목록으로 링크한 결과가 원본과 같음).

```sh
RID=<새 RID, 예: s6p406-ln1>
python3 10_tools/reconstruction/l2_link.py prepare $RID s6l5      # 5 절 빌드의 RID 접두어
python3 10_tools/reconstruction/kr_run.py prepare $RID 08_build/runs/tools/$RID-src 08_build/runs/tools/$RID.cmd
python3 10_tools/reconstruction/kr_run.py launch $RID
python3 10_tools/reconstruction/kr_run.py wait $RID
python3 10_tools/reconstruction/kr_run.py collect $RID
```

실기에서 실행되는 명령은 넷입니다.

```
/bin/ld -r -o stage/libDriver_kern.o <libDriver 객체 67 개, 마지막 vers.o>     # driverkit-1/libDriver/Makefile:631
/bin/ld -r -o stage/libkobjc.o <ObjC 런타임 객체 17 개, 마지막 objc_vers.o>    # objc/Makefile.postamble:155
/bin/ld -static -e _start -segaddr __TEXT 0x100000 -segaddr __LINKEDIT 0x780000 \
    -segalign 0x1000 -force_cpusubtype_ALL -u __muldi3 -o stage/mach_kernel.sys \
    <libc·OBJS·ioconf 303 개> stage/libDriver_kern.o stage/libkobjc.o <mach 스텁 14 개> <vers.o> -lcc
/bin/strip -x -o stage/mach_kernel stage/mach_kernel.sys                    # conf/Makefile.template:272
```

링크 목록과 근거(데이터만 있는 객체의 자리 등)는 `08_build/runs/tools/$RID.link.json` 에 남습니다.

## 7. 원본과 비교

```sh
python3 10_tools/reconstruction/l2_compare.py 08_build/runs/$RID/out/mach_kernel \
    03_original/x86/binaries/mach_kernel 09_validation/reconstruction/s6-l2-link-$RID.json
cmp 08_build/runs/$RID/out/mach_kernel 03_original/x86/binaries/mach_kernel && echo identical
```

`l2_compare.py` 는 Mach-O 머리·로드 명령·절 바이트(다른 구간)·기호·공통 기호 주소를 비교합니다.

## 8. QEMU 부팅용 판

원본(= 이 빌드 결과) 커널은 이 저장소의 QEMU 에서 IDE 인터럽트가 잠겨 부팅되지 않습니다.
QEMU 에서는 `_intr_handler` 12 B 를 고친 판을 씁니다.

```sh
python3 10_tools/runtime/make_i386_pic_kernel.py --in 08_build/runs/$RID/out/mach_kernel OUT
```

출력 SHA-256 은 `304cb696924f4e389c8365371d386bfa8ea0fa56ea8aac4bb4fc546dc735250f` 이어야 합니다.
시험 디스크와 부팅 방법은 `11_emulation/README.md`, `11_emulation/QEMU_VM_CONFIGURATIONS.md` 에 있습니다.

## 9. 주의

- `01_resources/`·`03_original/` 은 읽기만 합니다. 소스 편집은 `07_kernel/` 에서만 합니다.
- NFS 위로 읽기 전용 파일을 `cp -p` 하면 빈 파일이 될 수 있습니다. `cat src > dst` 로 복사하고
  호스트에서 SHA-256 을 확인하십시오.
- gcds 로 `ps` 를 실행하면 멈출 수 있습니다. 실기 `sort` 는 `-k` 대신 `+N` 을 씁니다.
- 07 을 고친 뒤에는 5–7 절을 다시 돌려, 결과가 원본과 같은지 확인합니다.
