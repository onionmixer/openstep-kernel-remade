# HOWTOUSE — 복원한 x86 커널 쓰기

`HOWTOCOMPILE.md` 의 절차로 만든 커널을 확인하고, QEMU 에서 부팅해 보는 방법을 적습니다.
2026-10-08 에 이 절차로 07 에서 만든 커널이 원본과 바이트 단위로 같았고, 그 커널에 QEMU 용 12 B PIC 수정을
더한 판이 QEMU i386 에서 Workspace 까지 부팅됐습니다(`02_plan/RECONSTRUCTION_PLAN.md` 402–406 절). PIC 수정이 없는
판의 QEMU 부팅(IDE 잠김이 예상되는 대조 시험)은 아직 하지 않았습니다.

## 1. 빌드 결과물

링크 실행 `08_build/runs/<RID>/out/` 에 다음이 생깁니다.

| 파일 | 내용 |
|---|---|
| `mach_kernel` | `strip -x` 한 커널. 원본 `03_original/x86/binaries/mach_kernel` 과 같아야 합니다(SHA-256 `33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890`, 1,117,920 B) |
| `mach_kernel.sys` | strip 전 링크 결과. 지역 기호와 디버그 STAB 이 남아 있습니다. 절 배치(주소·크기)는 `mach_kernel` 과 같고, `__LINKEDIT` 세그먼트와 기호표(LC_SYMTAB)가 다릅니다 |
| `libDriver_kern.o`, `libkobjc.o` | `ld -r` 로 묶은 libDriver·ObjC 런타임 중간 객체 |

## 2. 원본과 같은지 확인

```sh
cmp 08_build/runs/<RID>/out/mach_kernel 03_original/x86/binaries/mach_kernel && echo identical
python3 10_tools/reconstruction/l2_compare.py 08_build/runs/<RID>/out/mach_kernel \
    03_original/x86/binaries/mach_kernel 09_validation/reconstruction/s6-l2-link-<RID>.json
```

07 을 고쳤다면 결과가 원본과 다를 수 있습니다. 그때는 `l2_compare.py` 출력의 절별 차이 구간과 기호 차이를 보고
원인을 찾습니다.

## 3. QEMU(i386)에서 부팅하기

QEMU 와 VM 구성은 `11_emulation/README.md`, `11_emulation/QEMU_VM_CONFIGURATIONS.md` 를 따릅니다.
VM 디스크 `09_validation/images/i386/openstep42-i386-hdd.raw` 에는 OPENSTEP 4.2 가 설치되어 있어야 합니다.

### 3.1 QEMU 용 PIC 판 만들기

원본(= 복원) 커널은 이 QEMU 에서 IDE 인터럽트가 잠겨 부팅되지 않습니다(가짜 IRQ15 에 EOI 가 없음).
`_intr_handler` 의 12 B 만 고친 판을 만듭니다.

```sh
python3 10_tools/runtime/make_i386_pic_kernel.py --in 08_build/runs/<RID>/out/mach_kernel \
    09_validation/images/i386/kernels/mach_kernel.l2.pic
```

도구는 입력이 기준 SHA-256 과 같고 출력이 `304cb696924f4e389c8365371d386bfa8ea0fa56ea8aac4bb4fc546dc735250f`
일 때만 파일을 씁니다. 07 을 고쳐 결과가 원본과 달라지면 이 도구는 멈춥니다(그때는 고칠 바이트 위치를 다시 확인해야 함).

### 3.2 시험 디스크 만들기

저장소의 VM 디스크는 그대로 두고 사본에 커널을 넣습니다. QEMU 가 꺼진 상태에서 합니다.

```sh
I=09_validation/images/i386
N=11_emulation/nextufs/nextufs
cp $I/openstep42-i386-hdd.raw $I/openstep42-i386-hdd.l2test.raw
sha256sum $I/openstep42-i386-hdd.raw $I/openstep42-i386-hdd.l2test.raw     # 둘이 같아야 함
$N fsck -n $I/openstep42-i386-hdd.l2test.raw                               # 쓰지 않는 검사
$N mkfile --from-file $I/openstep42-i386-hdd.l2test.raw /mach_kernel.l2.pic $I/kernels/mach_kernel.l2.pic
$N mkfile --chmod     $I/openstep42-i386-hdd.l2test.raw /mach_kernel.l2.pic 0444
$N fsck -n $I/openstep42-i386-hdd.l2test.raw
```

- `mkfile` 은 `--from-file` 없이 쓰면 문자열을 파일로 씁니다. 바이너리는 꼭 `--from-file` 을 씁니다.
- 넣은 뒤 `$N mount … DIR -o ro` 로 읽기 전용 마운트해 파일 크기·권한·해시를 확인하고 `fusermount -u DIR` 로 풉니다.
- 원본 판(PIC 수정 없음)도 대조용으로 `/mach_kernel.l2` 같은 이름으로 넣을 수 있습니다.

### 3.3 부팅

```sh
bash 11_emulation/scripts/vm-i386.sh boot-nocd \
    --disk 09_validation/images/i386/openstep42-i386-hdd.l2test.raw --snapshot
```

- `--disk` 는 `--snapshot` 과 함께일 때만 받습니다. 게스트가 쓴 내용은 임시 덧층에만 남고 디스크 파일은 바뀌지 않습니다.
- QEMU 창(GTK)에 `boot:` 프롬프트가 뜨면 **10 초 안에** 다음을 입력하고 Return 을 누릅니다.
  `-v` 는 커널 진단 메시지를 화면에 보여 줍니다.

  ```
  hd()mach_kernel.l2.pic -v
  ```

- 첫 화면 첫 줄에 판 문자열이 나옵니다.
  `NeXT Mach 4.2: Tue Jan 26 11:21:50 PST 1999; root(rcbuilder):Objects/mk-183.34.4.obj~2/RELEASE_I386`
- 로그인 뒤 Terminal 에서 `hostinfo` 를 실행하면 같은 판 문자열이 나옵니다(OPENSTEP 에는 `uname` 이 없습니다).
- 시작 직후의 10 초를 놓치지 않으려면 `--gdb-wait` 로 멈춘 채 띄운 뒤 QMP(`/tmp/kr-i386-qmp.sock`)로 `cont` 를 보내
  시작할 수 있습니다. QMP `screendump`(절대 경로)로 화면을 파일로 남길 수 있습니다.

### 3.4 끄기

- QEMU 를 띄운 터미널은 QEMU 모니터입니다. `quit` 을 입력하면 끝납니다. QMP 로는 `stop` 다음 `quit` 을 보냅니다.
- 모니터의 `commit` 은 `--snapshot` 덧층의 내용을 디스크 파일에 써 버리므로 쓰지 않습니다.
- 끝난 뒤 시험 디스크의 SHA-256 이 부팅 전과 같은지 확인합니다.

## 4. 실기에서 쓰기(사용자 작업)

실기의 커널 교체와 재부팅은 사용자가 합니다. 복원 커널은 실기 디스크의 `/mach_kernel`(SHA-256 33469393…)과
같은 바이트이고, 실기에서 실행 중인 커널의 판 문자열도 같습니다. 다만 복원 결과 파일 자체로 실기를 새로 부팅해 본
시험은 아직 없습니다. 복원 커널(또는 07 을 고친 커널)을 실기에서 시험하려면:

- 기존 `/mach_kernel` 을 바꾸지 말고 다른 이름(예: `/mach_kernel.test`)으로 복사합니다. NFS 에서 복사할 때는
  `cp -p` 대신 `cat src > dst` 로 복사하고 실기에서 SHA-256 을 확인합니다.
- 재부팅한 뒤 `boot:` 프롬프트에서 `hd()mach_kernel.test -v` 로 그 파일을 고릅니다. 실기에는 PIC 판이 필요 없습니다.
- 문제가 생기면 다시 재부팅합니다. 프롬프트에서 아무것도 입력하지 않으면 10 초 뒤 기본 설정으로 시작합니다(BootHelp).
  기본 커널 파일은 실기 설정에 따르므로, 시험 전에 기존 `/mach_kernel` 이 그대로인지 확인해 두십시오.

## 5. 디버깅 참고

- 각 VM 은 GDB 스텁을 `/tmp/kr-<arch>-gdb.sock`(i386 은 `/tmp/kr-i386-gdb.sock`) 에 엽니다(`QEMU_VM_CONFIGURATIONS.md` 0.4 절).
- 호스트의 GDB 는 Mach-O 를 읽지 못합니다. `mach_kernel.sys` 의 기호를 쓰려면 ELF 기호 파일로 바꿔야 합니다
  (아직 도구가 없음). 함수 주소는 `03_original/x86/inventory/symbols.tsv` 에서 찾을 수 있습니다.
- 소스를 고치고 다시 만드는 방법은 `HOWTOCOMPILE.md` 를 봅니다.
