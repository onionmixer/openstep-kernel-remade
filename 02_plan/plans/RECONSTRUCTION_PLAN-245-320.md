# 커널 소스 복원 작업계획 — 보관 §245–320

`02_plan/RECONSTRUCTION_PLAN.md` 의 §245–320 을 절 번호·내용 그대로 옮긴 보관본(2026-10-05, D026 방식, 사용자 지시 “완료된 작업은 완료 문서로 분리”). 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킨다. 아래는 원문 그대로다.

---

## 245. S5-P230 세부 계획 — `bsd/kern/tty.c` (NeXTMach 원문 + POSIX termios 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis `tty.dis` 0x10daf0–0x111c00; 진단 `s5p230-d4` = NeXTMach `bsd/tty.c` + 진단용 우회(cons 선언, km 대체, 표 크기 NSPEEDS), 07 아님):
0. 객체 [0x10daf0, 0x111c00) 16656 B — 앞(soo_close 끝)·뒤(pty_init) 모두 채움 없는 이음매(경계 추론). 기호 있는 함수 42 개: ttysetspec 632, ttychars 76, ttywflush 28, ttywait 96, ttyflush 180, ttrstrt 72, ttstart 52, ttioctl 3376, ttnread 56, ttselect 208, ttyopen 436, ttylclose 32, ttyclose 328, ttymodem 376, nullmodem 52, ttypend 112, ttyinput 468, ttyblkin 504, ttcooked 2424, ttyoutput 904, ttread 1196, ttycheckoutq 160, ttwrite 1300, ttyrub 424, ttyrubo 56, ttyretype 184, ttyecho 188, ttyoutstr 48, ttcheckwakeup 48, ttwakeup 104, tty_ld_install 248, tty_ld_remove 132, ttydevstart 20, ttydevstop 32, ttyselwait 100, ttselwakeup 72, ttsettermios 884, ttgettermios 880, ttynty 156, nullioctl 12.
1. 진단에서 크기가 같은 함수: ttywflush, ttyflush, ttrstrt, ttstart, ttylclose, ttypend, ttycheckoutq, ttyrubo, tty_ld_install, tty_ld_remove, ttydevstart, ttydevstop(꼴은 빌드로 확인). NeXTMach 의 ttbreakc·ttyout 은 원본에 기호 없음(원본의 ttyoutstr·ttcheckwakeup 이 대응 후보), ttsettermios·ttgettermios·ttynty·nullioctl 은 NeXTMach 에 없음.
2. 4.2 는 07 `nextdev/bsd/sys/tty.h`(SDK 사본, 기록됨)의 `struct nty`(t, t_nforw, t_session, t_posix_pgrp, t_pflags +0x10, t_quote, t_min, t_time) 와 TP_* 플래그를 씀: 예) ttysetspec 은 tp = np->t(+0) 와 tp->t_flags(+0x3c)·np->t_pflags 로 특수 문자 집합을 TP_IEXTEN·TP_ISIG·TP_IXON 등에 따라 만듦(0x10daf0–0x10dd65). ttynty(tp)(0x111b58): 0 이면 panic "ttynty(0)", 정적 목록 머리(`__bss` 0x1e56c4)를 t 로 찾고, 없으면 spltty 아래 새 nty 를 할당·NTYDEFAULTS 꼴로 초기화해 앞에 넣음(세부는 작성 단계에서 바이트로).
3. `__data` [0x1dacec, 0x1dafe8) 764 B: partab[256], maptab[128], tthiwat[32]·ttlowat[32](16 번째부터 4.2 값: 3000,3000,3000,4000,4000,2000… / 400,600,600…), tthog[32](모두 1024), ttydefaults(14 B), 문자열("ttrstrt", "tty%d: raw input overrun\n" 두 번, "^\b", cbreak·canon overrun, 공백 8, "({)}!|^~'`", "ttwrite", "ttyrub", "\b \b", "\b", "ttynty(0)"), 끝 0x1dafe5–e7 `00` 뒤 linesw(다른 객체). `__bss` 0x1e56c4(nty 목록 머리, 4 B 추론). 외부: cdevsw(+0x10·+0x14 를 major 로 색인), linesw, nldisp, hz, active_u, tk_nin/tk_nout, lbolt, cons, cons_tp.

방법: 함수가 많아 단계로 나눔. (가) NeXTMach `bsd/tty.c` 를 07 관례로 들여(next/cons.h·kmreg.h 대체, 표 크기 NSPEEDS 와 원본 값) 데이터·크기 같은 함수부터 맞춤. (나) nty 를 쓰는 함수들(ttysetspec, ttioctl, ttyopen/close, ttyinput/blkin, ttcooked, ttyoutput, ttread, ttwrite, rub/echo 계열, select 계열)과 새 함수(ttsettermios·ttgettermios·ttynty·nullioctl·ttyoutstr·ttcheckwakeup)를 원본 바이트로 작성(`plan 245` 표시). 각 단계 결과는 245.N 으로 기록하고, 단계마다 새로 확인한 사실(함수 세부)을 적은 뒤 진행. 작업본은 scratchpad 에 두고 `wipbuild.py`(COMPANION 으로 kern/thread.h 등) 로 빌드, OBJECT_MATCH(또는 bss 만 추론인 P) 일 때만 07 에 넣고 기록.

245 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 기호 있는 함수는 42 가 아니라 40 개; 크기는 다음 기호까지(nop 포함) | symbols.tsv Python 집계 40 | ✅ 내 오기 → 사실 0 정정: 40 개(나열한 이름 수와 같음) |
| 1 ttcheckwakeup 은 ttbreakc 대응이 아님 — `(t_flags & 0x22)` 이고 rawq 개수 < t_min 이고 t_time == 0 이면 0, 아니면 1; ttyoutstr 는 NeXTMach ttyout 과 같은 동작 | tty.dis 0x111180–0x1111ac, 0x111150–0x11117c; NeXTMach tty.c:1913–1932 | ✅ 사실 1 정정 |
| 2 ttynty: spltty 를 0 검사보다 먼저, 찾으면 목록에서 떼어 머리로 옮김, 없으면 kalloc(24) 후 t·TP_DEFAULT(0x1c251a1c)·quote '\\'·min 1·time 0·session/pgrp 0 | tty.dis 0x111b61–0x111bdc; TP_DEFAULT 를 07 tty.h 플래그로 Python 계산 = 0x1c251a1c | ✅ 사실 2 보충 |
| 3 데이터 764 B·표·문자열·끝 3 바이트, cdevsw 항목 44 B(+0x10 d_ioctl, +0x14 d_stop) | 이번 세션 덤프, tty.dis 0x10ea1d·0x10de8e | ✅ |
| 1 의 "크기 같음" 은 원본 역어셈블만으로 확인 불가 | 진단 빌드 크기 비교 결과임 | ⚖️ 빌드 꼴 비교로 확인 예정(이미 방법에 적음) |

245 보충 사실(코딩 전, 내 확인): partab 은 NeXTMach 와 191 바이트 다름 — 영숫자와 `_` 에 0100 비트를 더했고(XOR 0100), 128–255 는 07 대신 0100(Python 대조). maptab 128 B 는 NeXTMach 와 같음.

### 245.1 진행 — 1단계(작업본, 07 미변경)
- scratchpad `mk_tty.py`(NeXTMach tty.c + 원본 partab·tthiwat/ttlowat/tthog[32] 값) + 편집 묶음 `tty_e1.py`–`tty_e12.py` 로 `tty_wip.c` 생성, `wipbuild.py s5p230-itN`(COMPANION vm_user.c·syscall_subr.c). it10 까지 40 함수 중 30 개 꼴 일치(진단 대조 `fnall.py`).
- 확인된 4.2 변경(원본 바이트 근거, 작성 표시 `plan 245`): nty 인자(ttnread·ttyecho·ttyretype·ttyrub·ttysetspec·ttcheckwakeup), ttynty 와 정적 목록, TP_CLOCAL(ttywait·ttymodem·nullmodem·ttselect), selthreadcache/selthreadclear(select 계열·ttwakeup·ttyclose), nextc3·TTY_QUOTE(ttyretype·ttyrub), 콘솔 변경 때 이전 콘솔에 ioctl `_IO('k', 8)`(이름 KMIOCDISABLCONS 는 Darwin 0.1 bsd/dev/kmreg_com.h:92 에서), ttyclose 의 POSIX 세션 정리, ttyout → ttyoutstr, ttbreakc 는 정적 인라인. 변형으로 정한 꼴: ttyecho `s5p230-v1` e1(c &= 0377 두 곳), ttysetspec `s5p230-v2` s5(선언 순서·sizeof 루프).
- 남은 함수: ttyopen, ttyinput, ttyblkin, ttioctl, ttcooked, ttyoutput, ttread, ttwrite, ttsettermios, ttgettermios.
- (계속) it19 까지 34/40: ttyclose(POSIX·selthreadclear), ttyopen(POSIX 제어 터미널·enterpgrp·NTYDEFAULTS), ttyinput·ttyblkin(TP_CREAD·log 넘침·ttcheckwakeup·TP_IEXTEN, `--n >= 0`), ttyoutput(TP_OPOST·TP_ONLCR·TP_CS8, 지역 열 변수, NEWLINE/RETURN 안쪽 switch, TAB1 비교·`(col + 8) & ~07`, concept 100 루프 변수 = 지연값 — 변형 `s5p230-v3`–`v9`, h1 일치), ttyflowctl 인라인의 stopc 검사. ttyinput/blkin 의 log 를 위해 sys/syslog.h import.
- 남은 함수: ttioctl, ttcooked, ttread, ttwrite, ttsettermios, ttgettermios.
- (계속) tdiff 는 즉시값을 정규화해 상수 차이를 숨김 → 정확 바이트 비교 `fnbytes.py` 를 만들어 다시 확인: ttstart 마스크에 TS_OUTPUTFULL(0x4000000) 이 빠져 있었음(ttstart 와 그 인라인 4 곳) → 고침. ttwrite(TP_CLOCAL·POSIX EAGAIN 은 if 문·POSIX 배경 쓰기·OPOST 8 비트 제거 루프는 기존 변수 ce 를 계수기로 — 변형 `s5p230-v10`–`v16`, u1a 일치). it22 까지 35/40 바이트 일치.
- (계속) ttread 작성(it26 일치): RAW/CBREAK 에서 POSIX VMIN/VTIME(getthetime 경과 계산, untimeout/timeout(wakeup, qp)), TP_CLOCAL·POSIX 배경 읽기(pg_jobc 0 이면 EIO)·NBIO 반환은 두 곳에 같은 if 문, 캐리어 판정은 int 변수, CCEQ(\377 제외)·ttbreakc 는 매크로(eofc/brkc 를 0377 로 마스크, CRMOD 절 없음), TS_INPUTAVAIL 검사. 36/40 바이트 일치.
- (계속) ttcooked 작성(it29 일치): 4.4BSD 식 오류 문자 처리(IGNBRK·BRKINT·PARMRK·INPCK·IGNPAR), ISTRIP·LNCH, 특수 판정은 t_spec 이동(ttyspec), IEXTEN(lnext·flush)·ISIG(intr/quit/susp)·IXON·IGNCR/ICRNL/INLCR·LCASE, cbreak(ttcheckwakeup·IMAXBEL·log), cooked 편집(QUOT·erase+EUC SS2·kill+ECHOK/CRTKIL·ALTWERASE 단어 지우기·rprnt), putit(t_quote·MIN), endcase(IEXTEN·DECCTQ). 특수 판정은 변수 없이 레이블 분기, CCEQ 는 양쪽 char 비교(`s5p230-v17`–`v21`, r1 일치). 37/40 바이트 일치, `__data` 일치.
- (계속) ttgettermios 작성(it31 일치): BSD t_flags + nty pflags → SDK sys/termios.h 의 struct termios(iflag/oflag/cflag/lflag, c_cc 17 칸, 속도 바이트). CSIZE switch 에 CS5 case, lflag 에 `flags & (NOFLSH|TOSTOP|MDMBUF|ECHO)` 를 저장 앞에서 OR, 초기화 순서 iflag·oflag·lflag·cflag(`s5p230-v22`–`v27`). 38/40.
- (계속) ttsettermios 작성(it33 일치): termios → t_flags/pflags/특수 문자(역변환). 원본은 짝수/임의 패리티 선택에서 c_lflag 의 0x80 비트를 검사함(바이트대로 작성, 주석). 39/40 — 남은 것 ttioctl.
- (계속) ttioctl 작성(it36–it37): 배경 검사 switch 의 대상 확대(termios set·DRAIN·START/STOP·SBRK/CBRK, NTTYDISC 검사 없음), POSIX TIOCSPGRP(pgfind·isctty·세션 검사)·TIOCGPGRP(ENOTTY), SETP·LBIS·LBIC·LSET 뒤 NTYDEFAULTS, FIONREAD 는 int, STI 는 u_char, TIOCGETA/SETA/SETAW/SETAF(ispeed 보정·CLOCAL 변화·ICANON 전환·VMIN/VTIME 변화 감지 — gcc 가 두 바이트 비교를 dword 마스크 비교로 합침)·DRAIN, case 배치 순서 SCONS 를 WINSZ 뒤로, canon 은 `(c_lflag & ICANON) != 0`(`s5p230-v28`–`v32`). 마지막 재배치 차이 1 건은 ttyrub 점프 표의 NEWLINE 칸 → `case NEWLINE` 을 CTLECH 묶음에 추가(it37).

### 245.2 결과 — P
- 07 `bsd/kern/tty.c`(새 파일, 작업본 정리 it38 후 넣음). it39(`s5p230-it39`) 07 에서 `__text`(40 함수)·`__data` 일치, relcheck 0. `__bss` zerofill(`s5p230-zerofill-check-tty-20261003.json`) 후보 [0x1e56c4, 0x1e56c8)(정적 ntys) → reference-inferred; 알려진 배치 38 건(`zerofill-known-s5p230-20261003.json`).
- 기록: objects_partial +1, functions +40(새 함수 6 개는 fn_source 로 작성 인용), PROVENANCE +1, MODIFICATIONS +1. 행 수·열 수 확인. nty 의 POSIX 필드는 조건 없이 씀(원본은 POSIX_KERN 빌드).

## 246. S5-P231 세부 계획 — i386 `bsd/dev/i386/mem.c`(/dev/mem·kmem·null; 전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis 0x194bf4–0x194dfc):
0. 객체 [0x194bf4, 0x194dfc) 520 B(앞 0x194bf2–f3 `00 00`, 앞은 cons 계열 cnputc; 뒤는 채움 없이 kd_slmwd — 끝 경계 추론). 함수: mmread 24, mmwrite 24, mmrw 472.
1. `__data` [0x1e36a0, 0x1e36a5) "mmrw\0"(앞 0x1e369c nchrdev = 0x2b 는 다른 객체). `__bss` 없음.
2. mmread/mmwrite: `return mmrw(dev, uio, UIO_READ / UIO_WRITE)`(dev 는 short 로 넘김).
3. mmrw(dev, uio, rw): `while (uio_resid > 0 && error == 0)`; iov_len == 0 이면 iov++, iovcnt−− 후 < 0 이면 panic "mmrw", continue. `switch (minor(dev))`:
   - 0(물리 메모리): v = trunc_page(uio_offset); `uio_offset >= mem_size`(부호 없음) 이면 fault; s = splvm(); where = vm_map_min(kernel_map); vm_map_find(kernel_map, 0, 0, &where, PAGE_SIZE, TRUE) 실패면 splx·fault; pmap_enter(kernel_map->pmap, where, v, VM_PROT_READ|VM_PROT_WRITE, TRUE); o = uio_offset − v; c = min(PAGE_SIZE − o, iov_len); error = uiomove(where + o, c, rw, uio); vm_map_remove(kernel_map, where, where + PAGE_SIZE); splx; continue.
   - 1(kmem): c = iov_len; kernacc(uio_offset, c, rw == UIO_READ) 실패면 fault; error = uiomove(uio_offset, c, rw, uio); continue.
   - 2(null): rw == UIO_READ 면 0 반환; c = iov_len.
   그 뒤 error 면 break, 아니면 iov_base += c, iov_len −= c, uio_offset += c, uio_resid −= c. 끝에 error 반환; fault: EFAULT(14).

방법: 07 새 파일 `bsd/dev/i386/mem.c` 를 원본 바이트로 작성(D024, `plan 246`; Darwin 0.1 bsd/dev/i386/mem.c 는 구조만). 헤더는 07 관례. scratchpad 작업본 → `wipbuild.py`(override 대상이 없으므로 iter.py 로 07 에서 직접, 실패 시 작업본 회수), relcheck, 기록(A 예상).

246 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 잘못된 minor 는 0x194c90·0x194ca3 → 0x194db8 로 가서 c(edi) 를 설정하지 않은 채 uio 갱신 — EFAULT 아님 | todis 0x194c89–0x194dc7 | ✅ 사실 3 보충: switch 에 default 없음(c 미설정 경로 그대로) |
| 크기는 상수가 아니라 page_size 변수, min 은 부호 없는 비교 | 0x194cdf·0x194d27·0x194d52; min 0x10cd37 `jbe`; 07 mach/vm_param.h:108 `PAGE_SIZE` = page_size | ✅ (PAGE_SIZE 매크로가 그렇게 펼쳐짐 — 문구 보충) |
| `__bss` 없음은 객체 소속 추론 | 참조 없음 | ⚖️ L1 로 확인 |

### 246.1 결과 — A
- 07 `machdep/i386/mem.c`(새 파일, 07 에 bsd/dev/i386 가 없어 i386 machdep 쪽에 둠). it1 컴파일 실패(EFAULT — sys/errno.h), it2(`s5p231-it2`) OBJECT_MATCH, relcheck 0. 기록: objects_confirmed +1, functions +3, PROVENANCE +1, MODIFICATIONS +1.

## 247. S5-P232 세부 계획 — i386 `machdep/i386/in_cksum.c` (전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis `incksum.dis` 0x18b2ac–0x18b514):
0. 객체 [0x18b2ac, 0x18b514) 616 B, 함수 in_cksum 하나(ret 0x18b511, 뒤 0x18b512–13 `00 00`, 다음 객체 intr(P); 앞 0x18b2ab `00` 한 바이트, 앞 객체 idt(A)). `__data`·`__bss` 없음(참조 없음).
1. 체크섬 루프는 인라인 asm 한 덩어리가 세 번 인라인된 꼴(0x18b2d7–0x18b342, 0x18b3ab–0x18b416, 0x18b48d–0x18b4f8): 입력 eax = 누적 합, ecx = 길이, esi = 버퍼; 길이 끝의 1·2·3 바이트를 먼저 더하고(test cl,1/2, movzx …[esi+ecx−3/−2/−1]), `adc eax,0`, `shr ecx,3` 로 8 바이트 단위 두 dword 씩 add/adc 루프, 끝에 32→16 비트 접기(`mov edx,eax; shr edx,16; add ax,dx; adc eax,0`). 결과는 16 비트(`and 0xffff` 또는 `not di` 후 16 비트).
2. in_cksum(m, len): sum = 0; `while (len > m->m_len)` 이면 i = m_len, sum = cksum(mtod(m), i, sum), m = m_next, len −= i, i 가 홀수면 느린 경로(다음 mbuf 들에서 첫 바이트를 `<< 8` 로 더하고 나머지를 cksum, 끝까지 남으면 첫 바이트 `<< 8` 를 더하고 `0xffff & ~cksum(cp, len − 1, sum)` 반환); 끝으로 `0xffff & ~cksum(mtod(m), len, sum)`. m_len 은 short(movsx), mtod 는 m_dat 기준 m_off 덧셈.

방법: 07 새 파일 `machdep/i386/in_cksum.c` 를 원본 바이트로 작성(D024, D027 — asm 명령 순서는 원본 그대로이므로 Darwin 0.1 machdep/i386/in_cksum.c 와 같아질 수 있음을 기록; Darwin 은 구조만 참고). 정적 inline 함수 + asm 제약(eax/ecx/esi). iter·relcheck·기록(A 예상).

247 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 데이터 주소는 `m + m->m_off`(+4) — "m_dat 기준" 은 근거 없음 | 07 nextdev sys/mbuf.h:75 `mtod(x,t) ((t)((int)(x) + (x)->m_off))`, m_off +4 | ✅ 내 문구 정정: mtod = m + m_off |
| 느린 경로의 `<< 8` 는 직전 처리 길이 i 가 홀수일 때만(0x18b375–0x18b37b, 0x18b441–0x18b446) | incksum.dis 해당 줄 | ✅ 사실 2 보충 |
| `__data`·`__bss` 없음은 참조 없음에서의 추론 | 참조 0 | ⚖️ L1 로 확인 |
| 세 asm 덩어리(0x18b2d7·0x18b3ab·0x18b48d, 109 B) 바이트 동일, eax/ecx/esi 역할, 부호 있는 비교·short m_len·마지막 보수 | incksum.dis | ✅ |

### 247.1 결과 — A
- 07 `machdep/i386/in_cksum.c`(새 파일, D027). it1(`s5p232-it1`) OBJECT_MATCH(614 B + 뒤 채움 2 B), relcheck 0. 기록: objects_confirmed +1, functions +1, PROVENANCE +1(라이선스 칸에 Darwin 과 같아질 수 있음 명시), MODIFICATIONS +1.

## 248. S5-P233 세부 계획 — i386 `machdep/i386/i386_init.c` (전면 작성 + getargs 계열, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis `i386init.dis` 0x18aafc–0x18b184):
0. 객체 [0x18aafc, 0x18b184) 1672 B(앞 0x18aafa–fb `00 00`, 앞 객체 gdt(A); 뒤는 채움 없이 locate_idt(idt 객체, A) — 끝 경계는 확정 객체 시작). 함수(사이 nop): i386_init 0x18aafc, 정적 0x18abd0(zero_fill_data), 정적 0x18ac28(machine_configure), 정적 0x18acf8(size_memory), bios_extdata_addr, alloc_cnvmem, alloc_pages, getargs, isargsep, argstrcpy, getval.
1. `__data` [0x1e19b4, 0x1e1a03): kernargs[] = {{"nbuf", &nbuf}, {"rootdev", rootdevice}, {"maxmem", &maxmem}, {0, 0}} 와 그 뒤 문자열 "maxmem"·"rootdev"·"nbuf"(역순), cnvmem = 0(0x1e19e8)·extmem = 0(0x1e19ec), "__DATA", "alloc_pages". `__bss`(정적): 0x1e75fc·0x1e7600(alloc_cnvmem 의 free_ptr·end_ptr), 0x1e7604 first_addr, 0x1e7608 last_addr, 0x1e760c maxmem, 0x1e7610 first_addr0, 0x1e7614 last_addr0(배치는 zerofill 로 판정).
2. 부트 구조체(물리 0x11000, 헤더 없음 — 파일 안에서 오프셋만 정의): +0x2 bootString, +0xb0 convmem, +0xb4 extmem, +0xb8 boot_file(64), +0x138 first_addr0, +0x154 numBootDrivers, +0x168 driverConfig[](8 B, size 는 +4).
3. i386_init(): cnvmem/extmem 을 부트 구조체에서; zero_fill_data(); machine_configure(); intr_initialize(); us_spin_calibrate(); page_size = 0x2000; vm_set_page_size(); getargs(bootString); size_memory(); num_regions = 1; mem_region[0].base/first = first_addr, last = last_addr; pmap_bootstrap(mem_region, 1, &virtual_avail, &virtual_end); locate_gdt(gdt + 0xc0000000); locate_idt(idt + 0xc0000000); dbf_init(); mem_region[0].last −= round_page(0x1000)(msgbuf 크기 4 KB); pmsgbuf = 그 값. (Darwin 의 idt_copy·idt_page_protect 없음.)
4. zero_fill_data: Darwin 과 같은 흐름(getsegbyname("__DATA"), firstsect/nextsect, S_ZEROFILL 이면 bzero(addr, size)). machine_configure: EFLAGS AC 시험(486 미만이면 hlt 반복), cr0 의 CD·NW 해제 + wbinvd(캐시 켜기), fp_configure(); machine_slot[0].is_cpu = running = TRUE, cpu_type = 7; EFLAGS ID 가 바뀌면 cpuid(1) 의 family == 5 일 때 cpu_subtype = 5(586), 아니면 cpu_config 의 fpu 종류가 2(하드웨어) 면 4(486), 아니면 0x84(486SX). size_memory: Darwin 과 같은 계산(드라이버 크기 합, maxmem 이 있으면 그 KB, 아니면 extmem KB → mem_size, first_addr0 round, last_addr0 = trunc(cnvmem KB), first_addr = round(end_of_image), last_addr = trunc(end_of_memory)).
5. bios_extdata_addr: cnvmem*1024. alloc_cnvmem(size, align): 정적 포인터 초기화(first_addr0, last_addr0 그대로 — pmap_phys_to_kern 없음), 정렬·범위 검사(부호 없음). alloc_pages(size): pmap_initialized 면 panic("alloc_pages"), first_phys_addr += round_page(size) 후 그 이전 값을 반환하지 않고 새 값을… (원본 0x18ae18–0x18ae1f: eax = 이전 first, ebx = 이전 + size → 저장, 반환값은 eax 아님 — 바이트로 확인 후 작성).
6. getargs(args): strncpy(boot_file, bootstruct boot_file, 64); Darwin 과 같은 인자 해석(‘-’ 플래그 a/s/d/f → boothowto 1/2/4/0x200000; 이름=값은 kernargs 를 strncmp(args, name, cp − args) 로 찾아 getval NUM/STR). isargsep·argstrcpy·getval: NeXTMach machargs.c 와 같은 꼴(원본 바이트로 확인).

방법: 07 새 파일 `machdep/i386/i386_init.c` 를 원본 바이트로 작성(D024, `plan 248`; getargs 계열은 NeXTMach next/machargs.c 를 바탕으로 4.2 꼴로, 나머지는 작성; Darwin 0.1 machdep/i386/i386_init.c 는 구조만). iter·relcheck·zerofill·기록.

248 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| alloc_pages 는 이전 first_phys_addr 를 반환(0x18ae18 eax, 0x18ae1f 저장, eax 유지) | i386init.dis 0x18ae18–0x18ae2b | ✅ 사실 5 정정(계획 문장이 불완전했음) |
| AC 검사는 popfd 뒤 다시 읽지 않고 edx 를 그대로 검사(hlt 가지는 실제로 닿지 않음), ID 검사는 popfd 뒤 다시 읽어 설정 여부 검사 | 0x18ac31–0x18ac43, 0x18ac84–0x18ac96 | ✅ 사실 4 보충(Darwin is486_or_higher·get_cpuid 와 같은 꼴) |
| argstrcpy 는 끝에 NUL 을 씀(0x18b074) — NeXTMach machargs.c:353 판은 안 씀 | NeXTMach machargs.c 353–362 열람, 0x18b074 `mov byte ptr [ecx], 0` | ✅ 작성 때 NUL 포함 |
| kernargs 비교는 `strncmp(args, name, cp − args)` 만(접두어 허용) | 0x18af48–0x18af59 | ✅ (계획 6 과 같음) |
| 나머지(경계·함수·데이터·bss·부트 오프셋·호출 순서·size_memory·alloc_cnvmem·getval) 맞음 | 이번 세션 열람(getval 뒷부분 0x18b100–0x18b180 포함) | ✅ |

### 248.1 결과 — P
- it1(`s5p233-it1`, 07 새 파일): 8 개 기호 함수·정적 zero_fill_data·size_memory 일치, machine_configure 만 차이. 변형 `s5p233-v1`(hlt 루프를 `if (!is486_or_higher()) for (;;) hlt` 로 — 원본은 hlt 뒤 hlt 로 되돌아감, 다시 검사 안 함), `s5p233-v2`(is586 끝을 `if (pid.family != 5) return FALSE; return TRUE` 로 — 원본 `mov edx,1; cmp al,5; je; xor edx,edx`) 로 일치(w1). it2 `__text` 0 차이.
- it3(`s5p233-it3`, NeXT 고지·출처 주석만 추가, 섹션 내용 it2 와 같음): L1 `__text`·`__data` 0 차이, relcheck 0. `__bss` 28 B zerofill(`s5p233-zerofill-check-i386_init-20261003.json`) [0x1e75fc, 0x1e7618) reference-inferred(바로 뒤가 intr 의 0x1e7618). `__TEXT,__const` 4 B `18 00 20 00` 은 참조 없음(cpu_inline.h ltr/lldt 선택자, intr.c 와 같은 선례) → 미배치.
- 0 의 "뒤는 채움 없이" 는 부정확: `__text` 1669 B 뒤 0x18b181–83 `00` 3 B, 다음 기호 0x18b184.
- 출처: isargsep·getval 은 NeXTMach next/machargs.c:344·365 와 같음(diff 확인), argstrcpy 는 `*to = 0` 한 줄 추가, getargs 는 고침. NeXT, Inc. 고지를 파일에 둠(D013). PROVENANCE 는 nextmach next/machargs.c 기준, 나머지 7 함수는 fn_source 로 작성(D024) 표시.
- 기록: objects_partial +1(34), functions +11(1980), PROVENANCE +1(609), MODIFICATIONS +1. record_partial.py 에 선택 키 const_note(참조 없는 `__const` 미배치 허용) 추가.

## 249. S5-P234 세부 계획 — i386 `machdep/i386/pc_support/PCtimers.c` (전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03)

이전 보류(plan 42 대, "callout API")의 원인이던 옛 callout API 는 power.c(plan 235)·ns_timer.c(plan 234)에서 작성으로 다뤘으므로 다시 연다. 원본 역어셈블 `pctimers.dis`(작업 디렉터리)만 근거로 쓴다.

0. 객체 [0x1a19c8, 0x1a1b60) 408 B: `__text` 405 B(ret 0x1a1b5c) + 뒤 `00` 3 B, 다음 객체 PCemulateREAL(A) 0x1a1b60. 앞 0x1a19c7 `00` 1 B, 앞 객체 PCresume(P, ret 0x1a19c6). 함수: 이름 없는 정적 둘 0x1a19c8(타임아웃 만료), 0x1a19e8(틱 만료), 기호 있는 PCscheduleTimers 0x1a1a00, PCdeliverTimers 0x1a1aa4, PCtimersPending 0x1a1abc, PCcancelTimers 0x1a1ad4, PCcancelAllTimers 0x1a1af8. 데이터 섹션 참조 없음.
1. 필드(07 PCpublic.h struct PCcontext): +0x48 running, +0x5c runOptions, +0x60 timeout, +0x64 tick(모두 unsigned/boolean), +0x74 pendingCallbacks, +0x78 pendingTimers, +0x7c expectedTimers. 비트 2 = PC_CALL_TIMEOUT, 4 = PC_CALL_TICK.
2. 0x1a19c8(ctx): expected&2 이면 { running 이면 pending|=2; expected&=~2 }. 0x1a19e8(ctx): expected&4 이면 { pending|=4; expected&=~4 }.
3. PCscheduleTimers(ctx)(두 인라인): pending&=~2; expected&2 이면 calloutRemove(0x1a19c8, ctx); runOptions&2 이면 calloutDispatchDelayed(0x1a19c8, ctx, calloutDeadlineFromInterval((u64)(timeout*1000)))(32 비트 곱 후 상위 0) 하고 expected|=2, 아니면 expected&=~2. 이어서 pending&4 이면 { callbacks|=4; pending&=~4 }; expected&4 가 아니고 runOptions&4 이면 같은 꼴로 tick·0x1a19e8 예약 후 expected|=4.
4. PCdeliverTimers: callbacks |= pending&6; pending &= ~6. PCtimersPending: (pending&6) != 0(setne). PCcancelTimers: calloutRemove(0x1a19c8, ctx); calloutRemove(0x1a19e8, ctx). PCcancelAllTimers(thread): shared = thread->pcb->PCpriv ? PCpriv->shared : 0(+0x28, +0xec, +0); i = 0..7 에서 PCcancelTimers(&shared->contexts[i]) 인라인(+0x88, 간격 0x84).
5. 선언: calloutRemove·calloutDispatchDelayed·calloutDeadlineFromInterval 은 원형 없는 extern(ns_timer.c 와 같은 꼴), deadline 은 unsigned long long.

방법: 07 새 파일을 원본 바이트로 작성(D024, `plan 249`). PCprivate.h 포함(PCresume.c 와 같은 머리글). Darwin 0.1 PCtimers.c 는 구조만(thread_call → callout 으로 다름), 비트 연산 꼴은 바이트가 정하므로 Darwin 과 비슷해질 수 있음 — D027 처럼 기록. iter·relcheck·기록(A 예상: 데이터 없음).

249 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 405 B 코드 + 3 B `00` = 408 B, 앞 0x1a19c7 `00`, 함수 시작 5 개는 symbols.tsv 와 같음, 데이터 참조 없음 | python 405/3/408 계산, pctimers.dis(0x1a19c6 ret, 0x1a1b5c ret), symbols.tsv | ✅ (계획과 같음) |
| PCemulateREAL 객체는 0x1a1b60 시작, 공개 기호 `_PCemulateREAL` 은 0x1a25a4 | symbols.tsv 0x1a1b00–0x1a2600 에 `_PCemulateREAL` 0x1a25a4 하나, objects_confirmed x86-PCemulateREAL 0x1a1b60 | ✅ 보충(계획 문구 "객체 0x1a1b60" 은 맞음) |
| 1: 필드 오프셋·크기 0x84 | 내 python 계산(sigcontext 18 단어 → running 0x48 … expectedTimers 0x7c, 크기 0x84) | ✅ |
| 2–3: 분기·호출 인자 순서(콜백, ctx[, deadline]), ×1000 은 32 비트 곱 후 상위 0 | pctimers.dis 0x1a1a07–0x1a1a97 | ✅ |
| 4: shared 가 0 이어도 검사 없이 루프(0x88 기준 주소를 calloutRemove 에 넘김) | 0x1a1b0d `mov [ebp-4],0`, 0x1a1b14–1a 만 조건, 0x1a1b24 이후 검사 없음 | ✅ 보충(Darwin threadPCShared 인라인 꼴 그대로 — 초안이 이미 그렇게 됨) |
| 5: 원형 유무·반환형 표기는 바이트로 증명 불가 | 맞음 — 빌드 결과로 판정 | ⚖️ 계획 5 를 "선택, 빌드로 확인" 으로 읽음 |

### 249.1 결과 — A
- it1(`s5p234-it1`, 07 새 파일): 7 함수 모두 바이트는 맞으나 정적 두 함수가 파일 끝에 놓임(gcc 2.7 은 주소가 아직 쓰이지 않은 정적 함수를 미뤄 냄). it2(`s5p234-it2`): 정적 함수 앞에 원형 선언과 그 주소를 쓰는 인라인 예약 함수(PCstartTimeout·PCstartTick)를 두어 원본 순서 — OBJECT_MATCH(405 B + 뒤 채움 3 B), relcheck 0.
- 기록: objects_confirmed +1(179), functions +7(1987), PROVENANCE +1(610), MODIFICATIONS +1. 옛 보류(plan 42 대 PCtimers "callout API") 해소.

## 250. S5-P235 세부 계획 — `bsd/netinet/ip_mroute.c` 멀티캐스트 라우팅 없는 판(스텁 3 개, 전면 작성, D024, 코딩 전, 2026-10-03)

0. 객체 [0x12c1e0, 0x12c204) 36 B: `__text` 33 B(ret 0x12c200) + 뒤 `00` 3 B, 다음 객체 nfs_client(A) 0x12c204. 앞 0x12c1de–df `00 00`(igmp_sendreport ret 0x12c1dd).
1. ip_mrouter_cmd 0x12c1e0: 인자 안 씀, `return 0x2d`(EOPNOTSUPP 45). ip_mrouter_done 0x12c1ec: `return 0`(뒤 nop 3). ip_mforward 0x12c1f8: `return 0`.
2. `__data` [0x1dbf54, 0x1dbf5c) 8 B: `_ip_mrouter` 0x1dbf54 = 0(struct socket *), `_ip_mrtproto` 0x1dbf58 = 0 — 둘 다 초기값 있는 정의(심볼표 type 0xf, section 4). 0x1dbf5c 는 nfs_export(A) 쪽 참조(0x12cda7)라 이 객체 밖. 참조: ip_mrouter 는 raw_cb·ip_input·ip_output·igmp 에서.
3. 근거 원문 없음: Darwin 0.1 ip_mroute.c 의 `#ifndef MROUTING` 쪽은 `ip_mrtproto` 만 있고 함수가 없다 → 원본 바이트로 작성.
방법: 07 새 파일 `bsd/netinet/ip_mroute.c`(plan 250). iter·relcheck·기록(A 예상, `__data` L1).

## 251. S5-P236 세부 계획 — `bsd/netinet/igmp.c` (MULTICAST 1.x 꼴, 전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

원본 역어셈블 `08_build/runs/tools/s5p235-igmp.dis` 만 근거로 쓴다.

0. 객체 [0x12bc2c, 0x12c1e0) 1460 B: `__text` 1458 B(ret 0x12c1dd) + 뒤 `00 00`. 앞 객체 udp_usrreq(A) 끝 0x12bc2c(채움 없음). 함수 6: igmp_init 0x12bc2c, igmp_input 0x12bc40, igmp_joingroup 0x12bf04, igmp_leavegroup 0x12bf78(빈 함수), igmp_fasttimo 0x12bf80, igmp_sendreport 0x12c044(전역, 기호 있음).
1. `__data` [0x1dbf20, 0x1dbf54) 52 B(내용 50 B + `00 00`): 0x1dbf20 sockproto {2, 2}(PF_INET, IPPROTO_IGMP), 0x1dbf24 igmpsrc sockaddr_in {AF_INET}(sin_addr 0x1dbf28), 0x1dbf34 igmpdst {AF_INET}(0x1dbf38), 0x1dbf44 igmp_timers_are_running = 0(초기값 있는 정적 int), 0x1dbf48 "mget", 0x1dbf4d "mget"(MGET 매크로 두 번의 panic 문자열). 앞 0x1dbf14–1f 는 udp_usrreq 의 "udp_usrreq". `__bss`: 정적 igmp_all_hosts_group 0x1e59ac(4 B, zerofill 로 확인 예정). `__common`: igmpstat 0x1eee70(9 개 카운터 0x24 B: rcv_total, tooshort, badsum, queries, badqueries, reports, badreports, ourreports, snd_reports).
2. igmp_init: all_hosts = htonl(0xe0000001)(bswap 상수).
3. igmp_input(m, ifp)(인자 두 개, iphlen 없음): ++rcv_total; ip = mtod; iphlen = ip_hl<<2; igmplen = ip_len(short, movsx); igmplen < 8 → tooshort, m_freem, return. minlen = iphlen + 8; (m_off > MMAXOFF(0x7c) || m_len < minlen) 이고 m_pullup 실패 → tooshort, return. m_off += iphlen; m_len −= iphlen; igmp = mtod; in_cksum(m, igmplen) ≠ 0 → badsum, m_freem, return. m_off −= iphlen; m_len += iphlen; ip = mtod. switch(igmp_type): 0x11 질의 — ++queries; ifp == loifp 면 break; ip_dst ≠ all_hosts → badqueries, m_freem, return; IN_FIRST_MULTI(step, inm, in_ifaddr) 루프에서 inm_ifp == ifp && timer == 0 && addr ≠ all_hosts 면 timer = (ntohl(in_ifaddr 의 +4 주소) + ipstat 첫 칸 + ntohl(inm_addr)) % 50 + 1(부호 없는 div), running = 1. 0x12 보고 — ++reports; loifp 면 break; !IN_MULTICAST(ntohl(group)) || group ≠ ip_dst → badreports, m_freem, return; (ntohl(ip_src) & IN_CLASSA_NET) == 0 이면 IFP_TO_IA(ifp, ia)(ia_ifp +0x20, ia_next +0x40) 후 ia 면 ip_src = htonl(ia_subnet +0x30); IN_LOOKUP_MULTI(group, ifp, inm)(ia_multiaddrs +0x44, inm_next +0x14) 찾으면 timer = 0, ++ourreports. 그 밖 type 은 그대로. 끝: igmpsrc.sin_addr = ip_src; igmpdst.sin_addr = ip_dst; raw_input(m, &igmproto, &igmpsrc, &igmpdst).
4. igmp_joingroup(inm): s = splnet(); addr == all_hosts || inm_ifp == loifp 면 timer = 0, 아니면 igmp_sendreport(inm); timer = 같은 난수식; running = 1; splx(s). igmp_fasttimo: running 이 0 이면 return; s = splnet(); running = 0; 전체 루프에서 timer 가 0 이 아니면 −1 후 0 이 되면 sendreport, 아니면 running = 1; splx(s).
5. igmp_sendreport(inm): MGET(m, M_DONTWAIT, MT_HEADER) 인라인(SDK sys/mbuf.h:171), NULL 이면 return; MGET(mopts, M_DONTWAIT, MT_IPMOPTS(14)), NULL 이면 m_free(m) 후 return. m_off = 0x74(MMAXOFF − 8), m_len = 8; igmp: type 0x12, code 0, group = inm_addr, cksum 0 후 in_cksum(m, 8). m_off −= 20; m_len += 20; ip: tos 0, len 28, off 0, p 2, src 0, dst = igmp_group(저장 순서 +1, +2, +6, +9, +0xc, +0x10). imo = mtod(mopts): ifp = inm_ifp, ttl = 1, loop = (ip_mrouter != 0). ip_output(m, 0, 0, IP_MULTICASTOPTS(2), mopts); m_free(mopts); ++snd_reports.
6. 선언: igmp.h·igmp_var.h 는 SDK·07 에 없음 → struct igmp·igmpstat·상수를 이 파일 안에 정의(i386_init 의 부트 구조체와 같은 처리). in_multi·IN_*_MULTI·ip_moptions 는 SDK in_var.h·ip_var.h. loifp 는 if_loop.c 의 netif_t.

방법: 07 새 파일 `bsd/netinet/igmp.c`(plan 251). iter·relcheck·zerofill·기록(`__bss` 때문에 P 예상).

250·251 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 250: 경계·채움·주소·반환값 맞음, 0x1dbf54/58 = 0, 0x1dbf5c 는 `_findexivp` 쪽(즉값 0x12cda7) | 이번 세션 바이트 덤프(0x12c1e0–0x12c204), 0x1dbf5c 즉값 검색 결과 0x12cda7, 그 앞 기호 python 조회 `_findexivp`(nfs_export 객체 안) | ✅ |
| 250: ip_mrouter 참조 5 곳, Darwin `#ifndef MROUTING` 은 ip_mrtproto 만 | 즉값 검색 0x12140a·0x121494·0x126386·0x1274ee·0x12c1b0(codex 는 명령 시작 주소), Darwin ip_mroute.c:76–78 | ✅ |
| 251: 경계·데이터 배치·bss·카운터·분기·오프셋·난수식·sendreport 저장·ip_output 순서 맞음 | igmp.dis 열람, 데이터 덤프, python 0x1eee70 + 9×4 = 0x1eee94 = `_exported` | ✅ |
| 난수식의 주소 씨앗은 루프 중에도 전역 머리 `in_ifaddr` 의 ia_addr | 0x12bdab `mov eax,[in_ifaddr]`, 0x12bf36 같음 | ✅ 보충(초안 매크로가 IA_SIN(in_ifaddr) 로 이미 그렇게 함) |
| sendreport 는 IP 버전·ID·TTL·체크섬, ip_moptions 나머지를 초기화하지 않음 | 0x12c179–0x12c1b8 저장 6 개 + imo 3 개뿐 | ✅ 보충(초안도 그 저장만) |
| `= 0` 초기화·static 은 배치·참조에서의 추론 | 맞음 — `__data` 배치로 판정 | ⚖️ 빌드로 확인 |

### 250.1 결과 — A
- 07 `bsd/netinet/ip_mroute.c`(새 파일). it1(`s5p235-it1`) OBJECT_MATCH(33 B + 뒤 채움 3 B, `__data` 8 B 기호 배치), relcheck 0. 기록: objects_confirmed +1(180), functions +3, PROVENANCE +1, MODIFICATIONS +1.

### 251.1 결과 — P
- it1(`s5p236-it1`, 07 새 파일): igmp_fasttimo 만 다름(원본은 step 을 스택 8 B 에 두고 s 만 ebx; 빌드는 step 을 레지스터 쌍에). 변형 `s5p236-v1`(선언 순서·register 6 가지) 무효, `v2` 의 `&step` 를 쓰는 꼴(i)과 `v3` 의 `(void) &step`(l) 이 일치 — 뒤의 것을 택하고 표시.
- it2(`s5p236-it2`): `__text` 0, `__data` 50 B L1d(추정 배치 0x1dbf20) 0, relcheck 0. `__bss` 4 B zerofill(`s5p236-zerofill-check-igmp-20261003.json`) [0x1e59ac, 0x1e59b0) reference-inferred; 알려진 배치 40 건(`zerofill-known-s5p236-20261003.json`).
- 기록: objects_partial +1(35), functions +6(1996), PROVENANCE +1(612), MODIFICATIONS +1.

## 252. S5-P237 세부 계획 — i386 `machdep/i386/pc_support/PCexception.c` (전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03)

이전 보류(plan 71 앞, "0x1e875c 구조체 +0x68 이름 미정")는 plan 212 kern_prot.c suser 에서 `u.u_error`(SDK sys/user.h:350·372 — `active_u[cpu_number()].uthread->uu_error`, char, active_u+4 = uthread)로 바이트 일치가 확인되어 풀렸다. 근거: `08_build/runs/tools/s5p237-pcexc.dis`.

0. 객체 [0x1a13a0, 0x1a15c4) 548 B: `__text` 547 B(ret 0x1a15c2) + 뒤 `00` 1 B, 다음 객체 PCresume(P) 0x1a15c4. 앞 0x1a139d–9f `00` 3 B, 앞 객체 PCinit(A). 함수: PCexception 0x1a13a0(372 B, 기호), 정적 0x1a1514(페이지 폴트 continuation, 175 B). 데이터 없음.
1. PCexception(thread, state): context = threadPCContext(thread) 인라인(shared = pcb +0x28 → +0xec → +0; shared 가 0 이 아니고 currentContext(+0x84) ≤ 7(부호 없는 비교) 이면 &contexts[i](+0x88, 0x84 간격), 아니면 0). context->running(+0x48) 이 0 이면 return FALSE.
2. trapno(state +0x30) == 14(T_PAGE_FAULT): saved = u.u_error(movsx, 지역 int); u.u_error = 0; va = cr2; result = vm_fault(thread->task(+0xc)->map(+0xc), va & ~page_mask, (err(+0x34) & 2) ? 3 : 1, 0, 0); u.u_error = saved. result ≠ 0 이면 trapNum(+0x4c) = trapno, errCode(+0x50) = err 그대로, exceptionResult(+0x54) = result; exception_with_continuation(1, result, va, 정적 0x1a1514); 그 뒤 exceptionResult ≠ 0 이면 callHandler(+0x58) = 1, PCcallMonitor(thread, state). result == 0 이면 공통 끝으로.
3. 그 밖: trapno == 7 && EM_bit(+0x6c) == 0 → fp_noextension(state); 아니면 eflags(state +0x40)의 VM 비트(바이트 +0x42 & 2 = 0x20000) 면 PCemulateREAL(thread, state), 아니면 PCemulatePROT(thread, state) — 0 이면 return FALSE.
4. 공통 끝: callHandler == 0 이고 (pendingCallbacks(+0x74) ≠ 0 || PCtimersPending(context)) 면 PCcallMonitor(thread, state); thread_exception_return(). (반환값 없는 경로 — Darwin 과 같은 꼴.)
5. 정적 continuation: thread = active_threads[0](current_thread); state = USER_REGS(thread)(07 machdep/i386/thread.h:182 — pcb +0x70 save_area 가 있으면 +0x84, 아니면 thread_user_state(thread)); context 인라인; exceptionResult ≠ 0 → callHandler = 1, PCcallMonitor; 이어서 4 와 같은 끝.

방법: 07 새 파일(plan 252). Darwin 0.1 PCexception.c 구조 + u_error 저장·복원(sys/user.h). iter·relcheck·기록(A 예상).

252 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0–5 모두 바이트와 맞음(경계 372 + 175 B, 0x1a15c3 `00`, 오프셋·분기·vm_fault 인자·continuation 인자·USER_REGS) | pcexc.dis 열람, python 547/548/372/175 계산 | ✅ |
| 두 context 조회 결과가 0 이어도 검사 없이 역참조(0x1a13ea, 0x1a157a) | 0x1a13e8 `xor ebx,ebx` 뒤 0x1a13ea `cmp [ebx+0x48],0`; 0x1a1578 뒤 0x1a157a 같음 | ✅ 보충(Darwin threadPCContext 인라인 그대로의 꼴) |
| 0x1e875c = active_u[0].uthread, +0x68 = uu_error 는 user.h 대응에서 온 해석 | 맞음 — plan 212 kern_prot.c suser 가 `u.u_error` 로 같은 바이트(objects 기록)로 근거 보강 | ⚖️ 해석임을 기록 |
| 데이터 없음은 이 조각만으로 증명 불가 | 맞음 — 빌드 L1 로 확인 | ⚖️ |

### 252.1 결과 — P
- 07 `machdep/i386/pc_support/PCexception.c`(새 파일). it1(`s5p237-it1`) `__text` 547 B 0 차이(두 함수 모두), relcheck 0. `__TEXT,__const` 4 B `18 00 20 00`(cpu_inline.h ltr/lldt, PCresume·vm_machdep 와 같은 선례) 미배치 → P. 데이터·bss 없음.
- 기록: objects_partial +1(36), functions +2(1998), PROVENANCE +1(613), MODIFICATIONS +1. record_partial.py 는 bss 없이 const_note 만 있는 경우도 받도록 고침. 옛 보류(plan 71 앞 "0x1e875c +0x68") 해소.

## 253. S5-P238 — machine_clock.c 재시도(plan 240 작업본 it8, 2026-10-03) — 보류 유지

- 07 에 작업본을 잠시 넣어 `s5p238-it1` 빌드(12 함수 중 10 일치, 앞과 같음) 후 다시 뺌(출처 행 없는 07 파일 금지; 작업본은 scratchpad `machine_clock_wip_it8.c` 그대로).
- us_spin_calibrate: 카운터를 16 비트 지역(count)으로 받아 splx 뒤 elapsed 에 옮기는 꼴(`s5p238-v1` c)이 스택 슬롯 위치만 4 B 어긋남 — 원본은 맨 위 [ebp−4] 에 쓰이지 않는 슬롯이 하나 더 있음. 선언 순서·형(`v2`), 지역 union·여분 변수(`v3` e2·e3), reg·s·count·elapsed 주소 취득(`v4`)은 무효이고, 쓰이지 않는 주소 취득 지역 변수를 맨 앞에 두는 꼴(`v3` e1)만 일치 — 근거 없는 인공 변수라 채택하지 않음.
- clock_timer_init 의 reload 저장(`mov eax,esi; mov [reload],ax`): 새 6 꼴(`s5p238-v5` k2·k5–k9: 16 비트 지역 경유, 연쇄 대입+캐스트, timer_write 인자 바꿈, 순서 바꿈) 모두 불일치. 이전 18 꼴과 합쳐 24 꼴 불일치.
- 판정: 보류 유지(두 차이 모두 레지스터 배정·스필 쪽; 원본 원문 단서가 더 생기면 재시도).

## 254. S5-P239 세부 계획 — i386 `machdep/i386/APM_i386.c` (전원 관리 PM*, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03)

근거: `08_build/runs/tools/s5p239-apm.dis`(0x1871e0–0x1877fc).

0. 객체 [0x1871e8, 0x1877f8) 1552 B: `__text` 1549 B(ret 0x1877f4) + 뒤 `00` 3 B, 다음 객체 checksum_16(A) 0x1877f8. 앞 0x1871e6–e7 `00 00`, 앞 객체 bios(P, [0x1871d4, 0x1871e6)). 함수: 정적 0x1871e8(GDT 항목 설정, 536 B), PMConnect 0x187400, PMDisconnect 0x187454, PMSetCpuState 0x187460, PMSetPowerState 0x1874ec, PMGetPowerEvent 0x1875b0, PMGetPowerStatus 0x18762c, PMSetPowerManagement 0x1876d8, PMRestoreDefaults 0x187770, PMUpdateClock 0x1877e4.
1. `__data` [0x1e17d8, 0x1e17f6) "Power management is enabled.\n"(30 B) + `00 00`, 다음 0x1e17f8 은 machine_clock 의 us_spin_us_const. `__bss`: 0x1e75b4 BIOS 진입 오프셋(정적), 0x1e75b8 연결 표시(정적 boolean), 0x1e75bc·0x1e75c0 버전 major·minor(정적 구조체 unsigned 두 칸).
2. 부트 구조체(0x11000) apm 칸: +0x368 major(u16), +0x36a minor(u16), +0x36c cs32 base, +0x370 cs16 base, +0x374 ds base, +0x378 cs length, +0x37c ds length, +0x380 entry offset, +0x388 connected. i386 판 kernBootStruct.h 는 참조 자료에 없음(Darwin 에는 ppc 판뿐) → 파일 안에 필요한 칸만 정의(i386_init 과 같은 처리).
3. 정적 GDT 설정: gdt(전역 포인터) 의 APMCODE32(+0x78), APMCODE16(+0x80), APMDATA(+0x88) 항목을 07 desc_inline.h 의 map_code·map_code_16·map_data 인라인(KERNEL_LINEAR_BASE 0xc0000000 + base, length, KERN_PRIV, FALSE)으로 채움, 끝에 BIOS 진입 오프셋 = +0x380.
4. PMConnect: 버전 major·minor 를 u16 에서 저장; connected ≠ 0 이면 표시 = 1, 정적 GDT 설정, printf(문자열), return 0; 아니면 return PM_R_NO_PM(0x3e80086). PMDisconnect: return 0.
5. APM BIOS 호출 인라인(biosBuf_t 지역, 07 bios.h): ah = 0x53, al = 기능(5 idle, 6 busy, 7 setstate, 8 disable, 9 default, 0xa getstatus, 0xb getevent), cs = 0x78, ds = 0x10, addr = 진입 오프셋; bios32(&bb); CF 가 0 이면 성공, 아니면 ah == 0 → PM_R_UNKNOWN(0x3e80101), 그 밖 0x3e80000 | ah.
6. PMSetCpuState: 연결이면 switch(IDLE → idle 호출, BUSY → busy 호출, 그 밖 ret = 0) 후 `ret == 0` 이면 PM_R_BAD_STATE(성공 0 도 BAD_STATE 로 가는 꼴 그대로); 비연결이면 IDLE 일 때 hlt; return 0.
7. PMSetPowerState(device, state): device == {1, PM_SYSTEM}(32 비트 비교 1) 이면 _io_setDriverPowerState(state); 연결이면 같은 장치이고 state 가 READY(0)·OFF(3) 면 BAD_STATE; du(번호·형 8 비트씩)·su 로 bx·cx 설정 후 setstate 호출 결과 반환; 비연결 PM_R_NOT_CONNECTED(0x3e80003).
8. PMGetPowerEvent(event): getevent 호출, 성공이면 *event = bx(u16 0 확장), return 0. PMGetPowerStatus(status): bx = 1 로 getstatus, 성공이면 line = bh, batt = bl, life = cl(0xff 면 −1) 를 32 비트 세 칸에. PMSetPowerManagement(device, state): 연결이고 device == 1 이면 bx = 0xffff, cx = (state ≠ 0) & 1 로 disable(8) 호출; 장치가 다르면 PM_R_BAD_ID(0x3e80009). PMRestoreDefaults: bx = 0xffff 로 default(9) 호출. PMUpdateClock: readtodc(&time)(Darwin 은 주석 처리).

방법: 07 새 파일 `machdep/i386/APM_i386.c`(plan 254). BIOS 호출 인라인은 같은 파일 안에 작성(Darwin APM_BIOS.h 는 구조만, 결과가 비슷할 수 있음 — D027). kern/power.h·bios.h·desc_inline.h·seg.h 는 07 것. iter·relcheck·zerofill·기록(`__bss` 때문에 P 예상).

254 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0–8 모두 바이트와 맞음(경계 1549 + 3 B, 문자열 30 B, bss 4 곳, 부트 오프셋, GDT 항목·접근 바이트, BIOS 기능 번호·오류 상수) | apm.dis 열람, python 1549/1552/30 계산 | ✅ |
| biosBuf_t 48 B: AH +5, AL +4, BX +8, CX +0xc, CS +0x20, DS +0x22, flags +0x28, addr +0x2c | python 으로 07 bios.h 배치 계산(크기 0x30) — 지역 −0x30 기준 ah −0x2b, cs −0x10, flags −8, addr −4 가 역어셈블과 같음 | ✅ |
| 7 보충: BX = 장치 번호 비트 0–7 | 장치 형 비트 16–23 의 하위 8 비트(나머지 버림), CX = state 하위 16 비트 | 0x18752c–0x18756e(`mov bl,dl`, `shr eax,8; and eax,0xff00`, `or dx,ax`) | ✅ 보충(초안의 du 8 비트 비트필드 꼴과 같음) |
| 6 보충: CPU 상태 함수는 BIOS 오류(0 아님)를 성공으로 삼킴 | 0x1874d2 `test eax,eax; jne 0x1874e5`(return 0) | ✅ 보충(초안 `ret == FALSE` 꼴 그대로) |
| bss 이름·static 은 쓰임과 Darwin 에서의 해석 | 맞음 — 배치로 판정 | ⚖️ |

### 254.1 결과 — P
- it1(`s5p239-it1`, 07 새 파일): 세 곳 차이 — (a) 정적 세그먼트 설정은 부트 구조체 기준 주소(0x11000 + 0x370 꼴 disp32)로 접근해야 함(apm_config 포인터로는 12 B 짧음), (b) idle·busy 인라인은 각자 if/else(공유 도우미면 PMSetCpuState 의 분기 대상이 바뀜), (c) disable 호출은 CX 를 BX 보다 먼저 설정.
- it2(`s5p239-it2`): `__text` 1549 B·`__data` 30 B(L1d, 추정 배치 0x1e17d8) 0 차이, relcheck 0. `__bss` 16 B zerofill(`s5p239-zerofill-check-APM_i386-20261003.json`) [0x1e75b4, 0x1e75c4) reference-inferred; 알려진 배치 41 건(`zerofill-known-s5p239-20261003.json`).
- 기록: objects_partial +1(37), functions +10(2008), PROVENANCE +1(614), MODIFICATIONS +1.

## 255. S5-P240 세부 계획 — i386 `machdep/i386/bios_asm.s`(`__bios32`, 첫 어셈블리 소스, 전면 작성, D024·D027, 코딩 전, 2026-10-03)

배경: 남은 후보 중 vol.c(필요 헤더 voldev.h·insertmsg.h 가 SDK·07 에 없고 NeXTMach 판은 옛 IPC; Darwin 소스 진단은 stage_headers 가 darwin01 덮어쓰기를 거부 — D021 대로)와 kern_server.c(NeXTMach 원문 진단 `s5p240-d3` 이 옛 IPC 헤더 mach_ipc_xxxhack.h 등으로 컴파일 실패)는 작업량이 커서 뒤로 둔다. 어셈블리는 S1 probe(GCC27_COMPATIBILITY.md:5, `.s` 전처리 포함)가 통과했고 iter.py 의 cc 명령(-traditional-cpp)으로 `.s` 도 컴파일된다고 보고 처음으로 시험한다. 근거: `08_build/runs/tools/s5p240-bios32.dis`(바이트 포함).

0. 객체 [0x187108, 0x1871d4) 204 B: `__text` 201 B(ret 0x1871d0) + 뒤 `00` 3 B, 다음 객체 bios(P) `_bios32` 0x1871d4. 앞은 catch(A) 끝 0x187107 ret, 채움 없음. 기호 `__bios32`(C 이름 `_bios32`) 하나.
1. `__data` [0x1e17c0, 0x1e17d8) 24 B: 0 으로 초기화된 4 B 칸 6 개 — +0 save_es, +4 save_eax, +8 save_edx, +0xc save_flag, +0x10 new_eax, +0x14 new_edx(이름은 Darwin 구조 참고, 쓰임으로 확인). 앞 0x1e17ba–bf 는 idt 객체의 `_idt_base`.
2. 명령열(바이트 그대로): enter 0,0; pushal; push es/fs/gs; pushfd; edx = arg; 버퍼 +0x20(cs) 를 text 안 far call 피연산자의 선택자 칸(0x187166)에, +0x2c(addr) 를 오프셋 칸(0x187162)에 씀; ebx/ecx/edi/esi/ebp ← +8/+0xc/+0x14/+0x18/+0x1c; save_edx = edx; new_eax ← +4; new_edx ← +0x10; `pushw` +0x22(ds); eax ← new_eax; edx ← new_edx(8b 15 꼴); `popw %ds`; cli; `.byte 0x9a` + 오프셋 4 B + 선택자 2 B(text 안 자료); pushfd; **`pushw %ax; movw $0x10,%ax; movw %ax,%ds; popw %ax`**(Darwin 은 `mov $KDSSEL,%eax` 로 eax 를 덮음 — 원본은 eax 보존); save_eax = eax; popl eax; save_flag(16 비트) = ax; save_es = es; new_edx = edx; edx = save_edx; 버퍼 +0x10 = new_edx, +4 = save_eax, +0x24(es) = save_es(16), +0x28(flags) = save_flag(16), +8/+0xc/+0x14/+0x18/+0x1c = ebx/ecx/edi/esi/ebp; popfd; pop gs/fs/es; popal; leave; ret.
3. 소스: 07 새 파일 `machdep/i386/bios_asm.s`, 머리글 없이 이 파일 안에서 오프셋·선택자를 정의(asm.h·assym.h 는 07 에 없음). 바이트가 Darwin bios_asm.s 와 대부분 같을 수 있음(D027) — 다른 곳은 2 의 ds 적재 4 명령.
4. 빌드: iter.py 그대로(`.s` 를 같은 cc 로). 실패하면(전처리·문법) 원인 기록 후 07 에서 회수. 등급: `__data` 가 추정 배치이고 L1d 로 확인되면 A 후보, 아니면 P.

255 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0·2: 경계 201/204 B, 이웃, 명령열·far call 칸(0x187162/0x187166)·ax 보존 ds 재적재 맞음; save_es·save_flag 는 16 비트로만 접근 | s5p240-bios32.dis 열람, python 201/204 | ✅ |
| 1 정정: `_idt_base` 는 0x1e17ba–bd(4 B), 0x1e17be–bf 는 `00` 채움 | 07 idt.c:117 `unsigned int idt_base`, 데이터 덤프 0 | ✅ 내 문구 정정(앞 객체 끝 + 채움 2 B) |
| 2 보충: `pushw` 앞에 `movw 0x22(%edx),%ax`(0x18714d) 가 따로 있음 | dis 0x18714d `668b4222` | ✅ 초안에 이미 두 명령 |
| Darwin 과의 차이는 ds 재적재 묶음뿐 | Darwin bios_asm.s 와 대조(이름·주석 외) | ✅ |
| stage_headers 는 darwin01 덮어쓰기 거부(:355) | 이번 세션 실행 출력 "kind 'darwin01' must be mach4 or nextmach" | ✅ |
| `.s` probe 는 전처리를 시험하지 않음(-traditional-cpp 없음, 매크로 없음) | probes-kernel.cmd:5, asm_probe.s 열람 | ✅ 내 배경 문구 정정 → 초안을 전처리 비의존(#define 없이 숫자, `/* */` 주석)으로 바꿈; 빌드가 그 확인 |

### 255.1 결과 — A(첫 어셈블리 객체)
- 07 `machdep/i386/bios_asm.s`(새 파일, 전처리 비의존). it1(`s5p240-it1`) OBJECT_MATCH 이나 far call 칸 레이블이 기호로 나옴 → `L` 접두 지역 레이블로 바꿈. it2(`s5p240-it2`) OBJECT_MATCH(201 B + 뒤 채움 3 B), `__data` 24 B L1d(추정 배치 0x1e17c0), relcheck 0. 빌드 명령(cc -traditional-cpp … -c x.s)이 `.s` 를 원본 바이트로 조립함을 확인(전처리 여부는 이 파일로는 미확인).
- 기록: objects_confirmed +1(181), functions +1(2009), PROVENANCE +1(615), MODIFICATIONS +1. record_object.py 는 어셈블리 레이블에 fn_source 를 받도록 고침.

## 256. S5-P241 세부 계획 — `kern/callout.c`(callout 계열 14 기호, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03)

근거: `08_build/runs/tools/s5p241-callout.dis`(0x169120–0x16a160). 참조 원문 없음(NeXTMach·Mach4 에 callout* 없음); Darwin 0.1 `kern/thread_call.c` 가 같은 구조의 후대 판(이름 thread_call_*, 내부 저장 768 칸, tvalspec) — 구조만 참고.

0. 객체 [0x169124, 0x16a158) 4148 B, 앞뒤 채움 없음(앞 0x169123 ret = swapper 끝, 뒤 0x16a158 은 기호 없는 다음 함수). 기호: calloutInitialize 0x169124, calloutDeadlineFromInterval 0x1691e8, calloutDispatch 0x169208, calloutDispatchUnique 0x1692d8, calloutDispatchDelayed 0x1693ec, calloutRemove 0x16957c, calloutRemoveAll 0x16966c, calloutEntryAllocate 0x169784, calloutEntryFree 0x1697c4, calloutEntryDispatch 0x16982c, calloutEntryDispatchWithArgument 0x1698b8, calloutEntryDispatchDelayed 0x169944, calloutEntryDispatchWithArgumentDelayed 0x169a80, calloutEntryRemove 0x169bbc. 이름 없는 정적: 0x169c64(깨우기: 잠금 풀고 pending 깨움, 필요하면 스레드 수 쪽도), 0x169cb0(호출 스레드 continuation), 0x169e0c(활성화 스레드 continuation), 0x169ea0(활성화 스레드 본체), 0x169f44(지연 타이머 만료 함수), 0x16a140(호출 스레드 본체).
1. `__data` [0x1dfcbc, 0x1dfce8) 44 B: 초기화 표시 int 0(0x1dfcbc), "internalEntryAllocate"(0x1dfcc0, 22 B), "calloutEntryFree"(0x1dfcd6, 17 B), `00` 1 B; 다음 0x1dfce8 `_zone_ignore_overflow`. 앞 0x1dfcba–bb 는 swapper 쪽 채움.
2. `__bss` [0x1e6a44, 0x1e726c) 2088 B: 내부 엔트리 64 칸 × 32 B(0x1e6a44), 단순 잠금 0x1e7244, 큐 머리 free 0x1e7248·pending 0x1e7250·delayed 0x1e7258, 정수 pending 수 0x1e7260·active 수 0x1e7264·스레드 수 0x1e7268.
3. 엔트리(32 B): +0/+4 큐 연결, +8 함수, +0xc 인자, +0x10 기본 인자(Allocate 의 둘째 인자), +0x14 기한(u64), +0x1c 상태(0 IDLE, 1 PENDING, 2 DELAYED).
4. 잠금: splsched 뒤 `while (lock) ; xchg(lock, 1)` 꼴(lock 이 0 이 될 때까지 읽기만 하다가 xchg, 실패하면 반복) — 풀기는 `xchg(lock, 0)`. 07 의 simple_lock 인라인이 이 꼴인지 확인, 아니면 파일 안 인라인.
5. calloutInitialize: 표시가 0 이면 잠금 0, 세 큐 init(pending, delayed, free 순으로 저장), 64 칸을 free 끝에 enqueue_tail, kernel_thread(kernel_task, 0x169ea0, 0), set_timer_expire_func(0, 0x169f44), 표시 = 1. calloutDeadlineFromInterval(ns64): clock_value(1) + ns.
6. calloutDispatch(func, arg): 표시가 0 이면 return; 잠금; free 가 비면 panic("internalEntryAllocate") 후 다시 검사해 비면 엔트리 0, 아니면 dequeue_head; func·arg, +0x10 = 0, 기한 0; pending 끝에 넣고 pending 수++, 상태 1; 0x169c64; splx. calloutDispatchUnique(func, arg): pending 에서 같은 func·arg 를 찾으면 잠금 풀고 끝, 없으면 Dispatch 와 같음. calloutDispatchDelayed(func, arg, deadline64): 엔트리 할당 뒤 기한 설정, delayed 큐를 기한 순(같은 기한이면 그 뒤, 작은 쪽 앞)으로 insque, 상태 2; 머리가 이 엔트리면 지연 타이머 설정(now = clock_value(1); 기한 < now 면 0, 아니면 min(기한 − now, timer_attributes(0) 의 첫 u64) 를 set_timer(0, ·)); 잠금 풀고 splx.
7. calloutRemove(func, arg): pending 에서 첫 일치를 빼고(pending 수−−) 없으면 delayed 에서; 뺀 엔트리 상태 0, 내부 저장 범위면 free 로; 잠금 해제·splx. calloutRemoveAll: 두 큐에서 모두 뺌.
8. calloutEntryAllocate(func, arg): kalloc(32), +8 func, +0xc 0, +0x10 arg, 기한·상태 0. calloutEntryFree(e): 상태 ≠ 0 이면 잠금 풀고 panic("calloutEntryFree"); kfree(e, 32). EntryDispatch(e): 상태 0 이면 +0xc = +0x10, 기한 0, pending 에 넣고 깨우기; 아니면 잠금만 풀기. WithArgument(e, arg): +0xc = arg 로 같음. Delayed(e, deadline) / WithArgumentDelayed(e, arg, deadline): delayed 삽입과 타이머 설정(6 과 같은 꼴). EntryRemove(e): 상태 1 이면 pending 에서(수−−), 2 면 delayed 에서, 상태 0, 내부 저장이면 free 로.
9. 깨우기 0x169c64: 필요 = (active 수 + pending 수 > 스레드 수); 잠금 풀고 thread_wakeup_prim(&pending 수, 1, 0); 필요면 thread_wakeup_prim(&스레드 수, 1, 0).
10. 호출 스레드 continuation 0x169cb0: self = current; 잠금; pending 수 > 0 인 동안: 머리 dequeue(pending 수−−), func·arg 보관, 상태 0, 내부 저장이면 free 로 넣고 엔트리 0; active++; 잠금 풀고 spl0; func(arg, 엔트리); splsched; 잠금; active−−. 끝나면 스레드 수 − active > 4 가 아니면 assert_wait(&pending 수, 0) 후 잠금 풀고 thread_block_with_continuation(0x169cb0); 그렇지 않으면 스레드 수−−, 잠금 풀고 spl0, thread_terminate(self), thread_halt_self.
11. 활성화 0x169e0c(continuation)·0x169ea0(본체, 먼저 stack_privilege(current)): 잠금; 스레드 수 < active + pending 이면 스레드 수++, 잠금 풀고 kernel_thread(self->task, 0x16a140, 0), thread_block_with_continuation(0x169e0c); 아니면 assert_wait(&스레드 수, 0), 잠금 풀고 thread_block_with_continuation(0x169e0c). 0x16a140: stack_privilege(current); 0x169cb0().
12. 지연 만료 0x169f44: now = clock_value(1); 지역 큐 머리 init; splsched; 잠금; delayed 머리부터 기한 ≤ now 인 것을 빼어 상태 0 으로 지역 큐 끝에; 남은 머리가 있으면 6 과 같은 타이머 설정; 지역 큐에서 하나씩 꺼내 pending 끝에(수++, 상태 1), 깨우기 꼴(잠금 풀고 wakeup, 다시 잠금); 끝으로 잠금 풀고 splx.

방법: 07 새 파일 `kern/callout.c`(plan 256, 이름은 원본 기호, 정적 함수·변수 이름은 작성). queue.h 매크로(07 kern/queue.h — enqueue_tail·dequeue_head·remqueue·insque)와 simple_lock 꼴은 07 에 있는 것을 쓰고 바이트로 확인. iter·relcheck·zerofill·기록(`__bss` 때문에 P 예상). 크기가 커서 바이트 차이는 함수별로 좁힌다.

256 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 정정: 0x16a158 은 기호 `_kern_timestamp`(이름 없는 함수 아님) | symbols.tsv 1861 행 `0x16a158 _kern_timestamp` | ✅ 내 문구 정정(경계는 그대로) |
| 8 정정: calloutEntryRemove 는 상태가 1·2 가 아니면 바로 잠금 해제(0 으로 두기·free 반환 없음) | dis 0x169c08 `cmp eax,2; jne 0x169c4d`(잠금 해제) | ✅ 작성 때 그 꼴 |
| 1–7·9–12 맞음; 07 queue.h(enqueue_tail·dequeue_head·remqueue·insque·queue_init) 저장 순서와 SDK `mach/i386/simple_lock.h`(07_kernel/nextdev) 의 잠금 꼴이 원본과 같음 | 내가 연 07 queue.h:134–233, nextdev/mach/i386/simple_lock.h | ✅ (07 kern/lock.h 는 MACH_SLOCKS 가 0 이면 simple_lock 을 빈 매크로로 덮음 — 빌드에서 확인) |
| calloutEntryFree 는 panic 앞에서 잠금을 풀고, panic 이 돌아오면 다시 풀고 kfree | dis 0x1697f5–0x16980a | ✅ 보충(계획 8 과 같은 꼴) |
| 할당 panic 뒤 재검사에서도 비면 엔트리 0 을 그대로 씀(0x169254–0x16927f) | dis 0x169260 `xor edx,edx` 뒤 0x16927c 저장 | ✅ 보충(dequeue_head 의 0 반환 그대로) |
| `__bss` 경계는 참조에서의 추론 | 맞음 — zerofill 로 판정 | ⚖️ |

### 256.1 결과 — P
- it1(`s5p241-it1`) 컴파일 실패(thread_terminate 재선언 — kern/thread.h:286 에 있음, stack_privilege 와 함께 extern 삭제). it2(`s5p241-it2`): 4148 B 같은 크기, 바이트 5 개 차이 — 모두 calloutEntryFree 의 ebx/esi 뒤바뀜.
- 변형 `s5p241-v1`–`v4`(선언 위치·register·K&R·캐스트·분기 꼴 등 15 가지) 중 인자를 `void *` 로 받아 형 있는 지역에 담는 꼴(p)만 일치 — 적용, 표시.
- it3(`s5p241-it3`): `__text` 4148 B·`__data` 43 B(L1d, 추정 배치 0x1dfcbc) 0 차이, relcheck 0. `__bss` 2088 B zerofill(`s5p241-zerofill-check-callout-20261003.json`) [0x1e6a44, 0x1e726c) reference-inferred; 알려진 배치 42 건(`zerofill-known-s5p241-20261003.json`).
- 기록: objects_partial +1(38), functions +20(2029), PROVENANCE +1(616), MODIFICATIONS +1.

## 257. S5-P242 세부 계획 — `kern/kdp.c`(원격 디버거 프로토콜 + UDP, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03)

근거: `08_build/runs/tools/s5p242-kdp.dis`(0x161f4c–0x162d80). 참조: NeXTMach·Mach4 에 kdp 없음. Darwin 0.1 `kern/kdp.c`·`kern/kdp_udp.c` 는 같은 모듈의 후대 판 — 원본은 이 둘을 한 객체(한 파일)로 가짐; 구조만 참고. 07 헤더 kern/kdp_internal.h·kdp_protocol.h·kdp.h(Darwin 사본, 기록됨), SDK net/etherdefs.h·netinet/udp_var.h.

0. 객체 [0x161f4c, 0x162d80) 3636 B: `__text` 3634 B(ret 0x162d7d) + `00 00`, 다음 wait_queue_init(다른 객체). 앞 0x161f4b `00`(queue 객체 끝). 함수(사이 nop): kdp_packet 0x161f4c(기호), 정적 처리기 unknown 0x16202c, connect 0x162058, disconnect 0x1620e8, hostinfo 0x162168, suspend 0x1621b4, resumecpus 0x1621fc, writemem 0x162244, readmem 0x1622b0, maxbytes 0x162324, regions 0x16236c, writeregs 0x1623dc, readregs 0x162444, 정적 kdp_reply 0x1624a8, kdp_send 0x1626dc, kdp_poll 0x1628f4, kdp_raise_exception 0x162a24(기호; kdp_connection_wait·kdp_send_exception·kdp_handler 인라인), kdp_reset 0x162d40(기호).
1. `__data` [0x1df274, 0x1df51d) 681 B + `00` 3 B: 디스패치 표 15 칸(0x1df274, Darwin 순서: connect, disconnect, hostinfo, regions, maxbytes, readmem, writemem, readregs, writeregs, unknown, unknown, suspend, resumecpus, unknown, unknown), kdp_packet·kdp_unknown 메시지 4 개, exception_message 표 7 칸(0x1df358, "Unknown"…"Breakpoint" — 문자열은 표 뒤에 역순), 패닉·안내 문자열("kdp_reply", "kdp_send", "kdp_poll", "kdp: bad sequence %d (want %d)\n", 연결 대기 2 줄, "Continuing...", "Rebooting...", "Connected to remote debugger.", "kdp: exception ack timeout", "kdp_raise_exception with NULL state\n", "%s exception (%x,%x,%x)\n", "kdp_raise_exception", "Remote debugger disconnected.\n"). 앞 0x1df260–73 은 다른 객체 문자열.
2. `__bss` [0x1e5e50, 0x1e6a44) 3060 B: exception_seq(u8, 0x1e5e50), pkt {data 1516 B, off, len, input}(0x1e5e54, 0x5f8 B; off 0x1e6440, len 0x1e6444, input 0x1e6448), saved_reply(0x1e644c, 0x5f8 B). `__common`: kdp(0x1f66a0, kdp_glob_t), adr(0x1f66c0). udp_ttl·ip_id 는 다른 객체의 전역.
3. kdp_packet(pkt, len, reply_port): 지역 정렬 버퍼 unsigned[385](0x604 B) 에 bcopy; plen < 8 또는 hdr.len ≠ plen → safe_prf("kdp_packet bad len pkt %d hdr %d\n", plen, hdr.len), FALSE; is_reply → safe_prf("kdp_packet reply recvd req %x seq %x\n", request, seq), FALSE; request > 0xe → safe_prf("kdp_packet bad request %x len %d seq %x key %x\n", …), FALSE; ret = dispatch[req](rd, len, reply_port); bcopy(rd, pkt, *len); return ret.
4. 처리기는 Darwin kdp.c 와 같은 꼴(i386 경로, copywithin, maxbytes 0x400, regions {0, 0x40000000, VM_PROT_ALL}); unknown 만 safe_prf("kdp_unknown request %x len %d seq %x key %x\n", …) 후 FALSE.
5. kdp_reply/kdp_send/kdp_poll: Darwin kdp_udp.c 꼴(정렬 지역 ui·ip, ip_sum 인라인, enaddr_copy=bcopy 6, ETHERTYPE_IP 0x800, 포트 0x473) — 차이: 송수신은 kdp_machdep 의 함수 kdp_en_send_pkt·kdp_en_recv_pkt 를 직접 호출(함수 포인터·kdp_register_send_receive 없음), kdp_poll 의 "no debugger device" 검사 없음.
6. kdp_raise_exception(exception, code, subcode, saved_state): s = kdp_intr_disbl(); state 0 이면 safe_prf("kdp_raise_exception with NULL state\n"); exception ≠ 6 이면 index(>6 또는 0 이면 0) 로 safe_prf("%s exception (%x,%x,%x)\n", …)(kprintf 없음); kdp_flush_cache; kdp.saved_state = state; pkt.input 이면 kdp_panic("kdp_raise_exception"); 연결 안 됐으면 connection_wait 인라인(안내 2 줄, exception_seq = 0, kmtrygetc 'c'/'r', poll, CONNECT·seq 검사), 됐으면 send_exception 인라인(300 회, kdp_us_spin(100000), 시간 초과 시 safe_prf·kdp_reset()); 연결이면 is_halted = 1, handler 인라인(재전송·순서 검사 safe_prf), 끊기면 safe_prf("Remote debugger disconnected.\n"); kdp_flush_cache; kdp_intr_enbl(s). kdp_reset: Darwin 과 같음.

방법: 07 새 파일 `kern/kdp.c`(plan 257; Darwin 두 파일 구조를 한 파일에, 위 차이만 작성). iter·relcheck·zerofill·기록(`__bss` 때문에 P 예상).

257 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 경계·함수 맞음; "한 파일" 은 바이트로 증명 안 됨 | — | ⚖️ 문구를 "한 객체" 로 읽음(한 파일로 작성하는 것은 선택) |
| 1–4 맞음(표 15 칸·exception_message 역순 문자열·끝 0x1df51d + `00` 3 B·bss 칸·kdp_glob_t 오프셋·kdp_packet 인자 순서·처리기) | kdp.dis·데이터 덤프(이번 세션) | ✅ |
| 5: 원본 UDP 포트는 0x473(1139)(0x162528·0x162762·0x1629b8), 07 kdp_protocol.h:66 은 41139 → 명시 필요 | dis 세 곳 `mov eax,0x473`/`cmp ax,0x473`, 헤더 :66 41139 | ✅ kdp.c 안에서 KDP_REMOTE_PORT 를 1139 로 다시 정의(헤더는 Darwin 사본 그대로, 다른 사용처 없음 — 07 grep 1 곳) |
| 6: 재전송은 `timeout_count = 300; … while (ack && timeout_count--)` 꼴이라 최대 301 회 | dis 0x162b88 `mov ebx,0x12c`, 0x162c11 `dec ebx; cmp ebx,-1` | ✅ 문구 정정(코드 꼴은 같음) |
| 문자열 "Continuing...", "Rebooting...", "Connected to remote debugger.", ack timeout 은 끝에 `\n` | 데이터 덤프 0x1df454–0x1df4ab | ✅ 작성 때 바이트 그대로 |

### 257.1 결과 — kdp A, kdp_udp P(객체 둘로 정정)
- 한 파일 빌드: it1 실패(netinet/ip.h 의 ip_timestamp 가 Mach ipc_port.h 매크로와 충돌 → BSD 망 헤더를 mach_types.h 보다 먼저), it2 4130 B(handler·connection_wait 가 따로 나옴 → inline 지정), it3 4094 B — kdp_packet 이 kdp_raise_exception 안에 두 번 인라인됨(나머지 17 함수 크기는 원본과 같음).
- 원인 확인: 큰 죽은 코드를 kdp_packet 에 넣으면(`s5p242-v2`) 원본처럼 호출로 남음 → 원본에서는 kdp_packet 이 그 자리에서 인라인될 수 없었음. 자연스러운 꼴(`v3`: DO_ALIGN 실행 조건, K&R 정의, 함수 포인터 지역)은 무효. 원본 이미지에 kdp_packet 주소 참조 없음(심볼표 값뿐). 0x1624a8 이음매는 채움 0 B 이고 `__data` 가 0x1df358 에서 4 B 정렬로 다시 시작 → **객체 둘(kdp.o [0x161f4c, 0x1624a8), kdp_udp.o [0x1624a8, 0x162d80))** 로 보고 파일을 나눔(codex 가 "한 파일" 은 증명 안 됨이라 한 지적과 맞음; 계획 0 의 "한 객체" 는 내 오판).
- it4(`s5p242-it4`, kern/kdp.c) OBJECT_MATCH(1372 B, `__data` 225 B L1d 0x1df274), relcheck 0 → A. it5(`s5p242-it5`, kern/kdp_udp.c) `__text` 2262 B·`__data` 453 B(L1d 0x1df358) 0 차이, relcheck 0, `__bss` 3060 B zerofill(`s5p242-zerofill-check-kdp_udp-20261003.json`) [0x1e5e50, 0x1e6a44) reference-inferred → P. 알려진 배치 43 건(`zerofill-known-s5p242-20261003.json`).
- 기록: objects_confirmed +1(182), objects_partial +1(39), functions +18(2047), PROVENANCE +2(618), MODIFICATIONS +2.

## 258. S5-P243 세부 계획 — i386 `machdep/i386/unix_signal.c` (sendsig·sigreturn·machine_exception, 작성 + NeXTMach 신호 로직, D024·D013, Darwin 은 구조만, 코딩 전, 2026-10-03)

근거: `08_build/runs/tools/s5p243-usig.dis`(0x1934ec–0x193a98). 이전 진단(plan 76 대 `s5p49-pre-1`): Darwin 판 1416 B 대 원본 1452 B. 원본은 Darwin 의 4.4BSD p_sigacts 대신 NeXTMach `next/machdep.c:1082` sendsig·`:1172` sigreturn 의 u 영역 신호 필드를 쓰고, i386 sigcontext·선택자 검사는 Darwin 판 구조.

0. 객체 [0x1934ec, 0x193a98) 1452 B, 앞 ufs_machdep(A) 끝 뒤 `00` 3 B(0x1934e9–eb), 뒤 채움 없음(다음 startup_early 0x193a98, unix_startup). 함수: sendsig 0x1934ec, sigreturn 0x19372c, machine_exception 0x193a54. 데이터 없음.
1. sendsig(catcher, sig, mask)(인자 3, NeXTMach 꼴): thread = current_thread(); state = USER_REGS(thread)(pcb +0x70 → +0x84, 없으면 thread_user_state); oonstack = u.u_onstack(utask +0x14c); `!u.u_onstack && (u.u_sigonstack(+0x13c) & sigmask(sig))` 면 scp = (struct sigcontext *)u.u_sigsp(+0x148) − 1, u.u_onstack = 1; 아니면 scp = state->frame.esp(+0x44) 기준 − 1; fp = scp − 1(sigframe 12 B). frame.sig = sig; sig 가 SIGILL(4)·SIGFPE(8) 면 frame.code = u.u_code(uthread +0x74), u.u_code = 0, 아니면 0(SIGEMT 없음); frame.scp = scp; copyout(frame, fp, 12) 실패 → bad. PC_SUPPORT: threadPCContext(thread) 가 있고 running 이면 oonstack |= 2, running = FALSE. context(sigcontext 0x48 B): onstack, mask, eax(+0x2c), ebx(+0x20), ecx(+0x28), edx(+0x24), edi(+0x10), esi(+0x14), ebp(+0x18), esp(+0x44), ss(+0x48 u16), eflags(+0x40), eip(+0x38), cs(+0x3c u16); eflags 의 VM(바이트 +0x42 & 2) 이면 v_ds(+0x50)·v_es(+0x4c)·v_fs(+0x54)·v_gs(+0x58) 를 쓰고 eflags &= ~EFL_VM, 아니면 ds(+0xc)·es(+8)·fs(+4)·gs(+0). copyout(context, scp, 0x48) 실패 → bad. state: eip = catcher, cs = 0x63, esp = fp, ss = 0x6b, ds = es = 0x6b, fs = gs = 0. bad: u.u_signal[SIGILL](utask +0x40) = SIG_DFL; p = u.u_procp(utask +0) 의 p_sigignore(+0x20)·p_sigcatch(+0x24)·p_sigmask(+0x1c) 에서 sigmask(SIGILL) 를 지움(순서 그대로); psignal(u.u_procp, SIGILL).
2. sigreturn()(인자 없음, NeXTMach 꼴): uap = u.u_ap(uthread +0x24); state; copyin(uap->sigcntxp, &context, 0x48) 실패면 return; VM 이 아니면 Darwin 의 선택자 검사 6 개(cs·ds·es·fs·gs·ss, 07 sel_inline.h valid_user_*_selector) 중 하나라도 실패면 return(EINVAL 저장 없음). u.u_eosys = JUSTRETURN(uthread +0x69 = 1); u.u_onstack = sc_onstack & 1; u.u_procp->p_sigmask = sc_mask & 0xfffafeff(~(sigmask(SIGKILL)|sigmask(SIGCONT)|sigmask(SIGSTOP))); 레지스터 복원(Darwin 순서), eflags = (sc_eflags & 0x50fd7) | 0x202(EFL_USERCLR·USERSET), eip·cs; VM 이면 ds..gs = 0, v_* = sc_*, eflags |= EFL_VM, 아니면 ds..gs = sc_*(16 비트 저장); sc_onstack & 2 면 PC context 가 있을 때 running = TRUE. 반환값 없음.
3. machine_exception(exception, code, subcode, unix_signal, unix_code): Darwin 과 같음(EXC_BAD_INSTRUCTION → SIGILL, EXC_ARITHMETIC → SIGFPE, code 저장, TRUE; 그 밖 FALSE).

방법: 07 새 파일 `machdep/i386/unix_signal.c`(plan 258). sendsig·sigreturn 의 BSD 부분은 NeXTMach next/machdep.c 를 바탕(고지 유지, D013), i386 부분은 원본 바이트대로 작성(Darwin 구조 참고, D027). iter·relcheck·기록(A 예상).

258 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0·1·3 맞음(경계·인자·u 영역 칸 순서·SIGILL/SIGFPE 만·bad 경로 순서·machine_exception, subcode 안 씀) | usig.dis 열람; 오프셋은 codex 의 python 계산과 내 계획 값이 같음(utask +0x13c/+0x148/+0x14c/+0x40, uthread +0x24/+0x69/+0x74, proc +0x1c/+0x20/+0x24) | ✅ |
| 2 정정: "반환값 없음" → 명시적 반환값 대입 없음; copyin 실패 때는 eax 에 copyin 결과가 남음 | dis 0x193776 call copyin, 0x19377d jne 0x193a49(에필로그, eax 그대로) | ✅ 문구 정정(초안 `return;` K&R 꼴과 같음) |
| 선택자: CS·SS 는 0 거부·사용자 권한 필요, DS–GS 는 0 허용·LDT 는 권한 검사 없음 | 07 sel_inline.h:72–120 열람 | ✅ (Darwin 의 valid_user_* 그대로) |
| PC 경로 둘 다 context 확인 뒤 running 접근; sendsig bad 경로는 u_onstack·u_code 를 되돌리지 않음 | dis 0x1935ba–0x1935fb, 0x193a0c–0x193a42 | ✅ 보충(초안과 같음) |

### 258.1 결과 — A
- 07 `machdep/i386/unix_signal.c`(새 파일, NeXT 고지 유지). it1 실패(EFL_USERCLR — `machine/psl.h`), it2(`s5p243-it2`) OBJECT_MATCH(1452 B), relcheck 0. 기록: objects_confirmed +1(183), functions +3(2050), PROVENANCE +1(619, nextmach next/machdep.c 기준·작성 부분 표시), MODIFICATIONS +1.

## 259. S5-P244 세부 계획 — i386 `machdep/i386/unix_startup.c` (startup_early·startup, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-03)

근거: `08_build/runs/tools/s5p244-ustart.dis`(0x193a98–0x193e58). 참조: NeXTMach next/machdep.c:733·:797(m68k 판, valloc 꼴), Darwin 0.1 machdep/i386/unix_startup.c(구조만; buffer_map_sizer·niobuf·TCP 크기 조정·bufinit 있음 — 원본에는 없음).

0. 객체 [0x193a98, 0x193e58) 960 B: `__text` 958 B(ret 0x193e55) + `00 00`, 다음 pagemove 0x193e58(다른 객체). 앞은 unix_signal(A) 끝, 채움 없음. 함수: startup_early 0x193a98, startup 0x193b80.
1. `__data` [0x1e289c, 0x1e294a) 174 B: nbuf·nmfsbuf·bufpages·show_space(모두 초기값 0 인 int, 이 순서), "physical memory = %d.%d%d megabytes.\n"(0x1e28ac), "using %d buffers containing %d.%d%d megabytes of memory\n"(0x1e28d2), "available memory = %d.%d%d megabytes. vm_page_free_count = %x\n"(0x1e290b); 다음 0x1e294a "pagemove" 는 다른 객체. buffer_map 은 common(0x1f7b2c).
2. startup_early(): rp = mem_region; v = firstaddr = rp->first_phys_addr(+0x14, 변환 없음); valloc(cfree, struct cblock(64 B), nclist); valloc(ncache, struct ncache(72 B), ncsize); nbuf == 0 이면 nbuf = (mem_size / 50) >> page_shift(atop), 255 초과면 255; nbuf ≤ 15 면 16; bufpages = (0x2000 / page_size) × nbuf(MAXBSIZE / page_size); valloc(buf, struct buf(68 B), nbuf); nmfsbuf == 0 이면 nmfsbuf = nbuf / 2(부호 있는 나눗셈); bzero(firstaddr, v − firstaddr); rp->first_phys_addr = pmap_resident_extract(kernel_pmap, v).
3. startup(firstaddr): cons.t_dev = makedev(12, 0)(0xc00, cons +0x38 u16) 전에 cons_tp = &cons; kminit(); panic_init(); printf(version); mem_size(부호 없음)로 "physical memory" 줄(MEG = 0x100000, MEG/10 = 0x19999); firstaddr = round_page(firstaddr); vm_map_find(kernel_map, vm_object_allocate(0), 0, &firstaddr, 8 MB, TRUE); vm_map_remove(kernel_map, firstaddr, firstaddr + 8 MB); buffers = firstaddr; size = round_page(buffers + nbuf × MAXBSIZE) − buffers; base = bufpages / nbuf, residual = bufpages % nbuf(부호 있는 idiv); buffer_map = kmem_suballoc(kernel_map, &firstaddr, &buffer_max, size, TRUE); vm_map_find(buffer_map, vm_object_allocate(size), 0, &firstaddr, size, FALSE); i < nbuf(부호 없음) 루프: thisbsize = page_size × (i < residual ? base + 1 : base), curbuf = buffers + i × MAXBSIZE, vm_map_pageable(buffer_map, curbuf, curbuf + thisbsize, FALSE); nbytes = bufpages << page_shift(부호 있는 int)로 "using" 줄, nbytes = vm_page_free_count << page_shift 로 "available" 줄; mb_map = kmem_suballoc(kernel_map, &mbutl, &embutl, nmbclusters << 10, FALSE). bufinit 없음, ASSERT 없음.

방법: 07 새 파일 `machdep/i386/unix_startup.c`(plan 259). iter·relcheck·기록(데이터 기호 배치, A 예상).

259 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0–3 맞음(경계 958 + 2 B, 함수 사이 nop 0x193b7d–7f, 데이터 4 칸 + 문자열 3, 구조체 크기 64/72/68, cons_tp → t_dev 순서, VM 호출 인자) | ustart.dis 열람, python 958/960/174 | ✅ |
| 나눗셈 부호: mem_size/50 은 부호 없음, 255·16 비교는 부호 있음, page_size 나눗셈 부호 없음, nmfsbuf/2 부호 있음, bufpages/nbuf 는 idiv, 루프·residual 비교는 부호 없음 | dis 0x193ae1 div, 0x193af7 jle, 0x193b0a jg, 0x193b1d div, 0x193b4c–53 sar, 0x193c6a idiv, 0x193ce7 jbe | ✅ 보충(int nbuf·unsigned i 꼴) |
| physical memory 줄은 부호 없는 계산, using·available 은 부호 있는 idiv; VM 호출 반환값 미검사 | dis 0x193bbf div, 0x193d40·0x193dc3 idiv | ✅ 보충(mem_size 는 vm_size_t, nbytes 는 int) |

### 259.1 결과 — A
- 07 `machdep/i386/unix_startup.c`(새 파일). it1(`s5p244-it1`): startup 만 다름 — 원본은 버퍼 끝 + page_mask 를 v 의 스택 칸에 저장. 변형 `s5p244-v1` A(`v = round_page(v); size = v − buffers;`) 일치(C·E·F 무효). it2(`s5p244-it2`) OBJECT_MATCH(958 B + 채움 2 B, `__data` 174 B 기호 배치), relcheck 0. 기록: objects_confirmed +1(184), functions +2, PROVENANCE +1, MODIFICATIONS +1.

## 260. S5-P246 세부 계획 — `kern/mach_fat.c`(fatfile_getarch, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-04)

근거: `08_build/runs/tools/s5p246-fat.dis`. 참조: NeXTMach·Mach4 에 없음; Darwin 0.1 kern/mach_fat.c 는 후대 판(매핑 없이 data_ptr 를 바로 읽고, vnode_size 검사는 `#if 0`) — 원본은 그 이전 꼴. 구조만 참고.

0. 객체 [0x15c948, 0x15ca74) 300 B: `__text` 297 B(ret 0x15ca70) + `00` 3 B, 다음 load_machfile 0x15ca74(mach_loader, 다른 객체). 앞 0x15c945–47 `00` 3 B(앞 객체 끝 ret 0x15c944). 함수 fatfile_getarch 하나, 데이터 없음.
1. fatfile_getarch(vp, header, archret): pager = vnode_pager_setup(vp, FALSE, TRUE); nfat_arch = 바이트 뒤집은 header->nfat_arch(+4); end_of_archs = 8 + nfat_arch × 20; end_of_archs > vp->vm_info->vnode_size(부호 없는 비교; vnode 의 vm_info 포인터 → +0x14) 면 return LOAD_BADMACHO(2); size = round_page(end_of_archs), 0 이면 LOAD_BADMACHO; addr = 0; vm_allocate_with_pager(kernel_map, &addr, size, TRUE, pager, 0) ≠ 0 이면 return LOAD_NOSPACE(5); arch = addr + 8 에서 nfat_arch 개(`nfat_arch-- > 0`, 부호 있음) 동안 swap(cputype) == machine_slot[0].cpu_type(+4) 이면 grade = grade_cpu_subtype(swap(cpusubtype)), grade > best_grade(부호 있음, 초기 0) 면 기억; best 없으면 lret = LOAD_BADARCH(1), 있으면 archret 다섯 칸(cputype, cpusubtype, offset, size, align) 을 swap 해 저장하고 lret = 0; vm_map_remove(kernel_map, addr, addr + size); return lret.
2. 선언: load_return_t·LOAD_* 는 Darwin kern/mach_loader.h 와 같은 값 — 07 에 mach_loader.h 가 없으므로 파일 안에 정의(값만, 구조 참고). fat 구조체는 SDK mach-o/fat.h, 바이트 뒤집기는 SDK architecture/byte_order.h(NXSwapBigLongToHost·IntToHost), struct vm_info 는 07 kern/mfs.h.

방법: 07 새 파일 `kern/mach_fat.c`(plan 260). iter·relcheck·기록(A 예상).

260 codex 검토 판정(코딩 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0–1 맞음(경계·인자·vnode_pager_setup(vp, 0, 1)·vnode_size 부호 없는 비교·반올림·할당 인자 6 개·실패값 5·루프·machine_slot+4·복사 순서·vm_map_remove·반환) | s5p246-fat.dis 열람 | ✅ |
| 32 비트 연산, pager 결과·vm_info 포인터 검사 없음 | dis 0x15c961 저장만, 0x15c97b 바로 역참조 | ✅ 보충(작성 꼴 그대로) |
| 다음 객체 경계·typedef 이름·헤더는 바이트로 증명 안 됨 | 맞음 — 뒤 채움 3 B 는 정렬로 봄; 이름·헤더는 선택 | ⚖️ |

### 260.1 결과 — A
- 07 `kern/mach_fat.c`(새 파일). it1(`s5p246-it1`) cpu_number() 호출이 생김(07 헤더에서는 함수) → `machine_slot[0]`. it2(`s5p246-it2`) OBJECT_MATCH(297 B + 채움 3 B), relcheck 0. 기록: objects_confirmed +1(185), functions +1, PROVENANCE +1, MODIFICATIONS +1.

## 261. S5-P247 세부 계획 — `kern/mach_net.c`(IP 데이터그램의 Mach 메시지 전달, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-04)

근거: `08_build/runs/tools/s5p247-mnet.dis`(0x15d6b8–0x15de68). 참조: NeXTMach kern/mach_net.c 는 옛 IPC(진단 `s5p245-d1` — ipc_statistics.h 등 없어 컴파일 실패), Darwin 0.1 kern/mach_net.c 는 같은 Mach 3 IPC 구조의 후대 판 — 구조만 참고.

0. 객체 [0x15d6b8, 0x15de68)(뒤 끝 ret·채움은 dis 끝 확인): 앞 0x15d6b5–b7 `00` 3 B(mach_loader 끝) — 0x15d8d0 이 아니라 0x15d6b8 에서 시작(netipc_msg_send 가 0x15d6b8 의 정적 함수를 부름). 함수: 정적 mach_net_output 0x15d6b8, netipc_msg_send 0x15d8d0, netipc_listen 0x15d8f8, netipc_ignore 0x15d9c0, find_listener 0x15dabc, mach_net_init 0x15db48, netipc_msg_release 0x15dc1c, receive_ip_datagram 0x15dc34(find_listener 인라인).
1. `__data` [0x1def10, 0x1def4d) + `00` 3 B: 정적 cached_route {0}(struct route 20 B), "mget"(MGET 패닉), "net listener zone", "mach_net messages". 앞 0x1def08 "__USER" 는 mach_loader 쪽. `__bss`: 정적 ip_msg_template(mach_msg_header_t 24 B, 0x1e5bac). `__common`: listener_zone 0x1f63fc, listeners[16](lbucket 8 B) 0x1f6400, mach_net_kmsg_zone 0x1f6480.
2. mach_net_output(kmsg): u.u_cred->cr_uid(utask +0x1c → +2, u_short) ≠ 0 이면 return(current_proc 아님); msgh_size(+0x18) += ikm_delta(+0x10); msgh_bits(+0x14) 부호 비트(COMPLEX) 또는 size ≤ 0x2b 면 return; size = ip_len(movsx +0x2e) ≤ 20 또는 > msgh_size − 24 면 return(부호 없는 비교); unix_master/release 없음; mbuf 루프: NeXT MGET(M_WAIT, MT_DATA) 인라인, 실패면 m_freem(top) 후 return; size ≥ page_size/2(부호 없음) 면 NeXT MCLGET 인라인(m_off = 클러스터 − m, m_len 0x400, m_type?? +0xc = 1) 후 m_len ≠ page_size 면 len = MIN(MLEN 0x70, size) 아니면 MIN(page_size, size), 작으면 MIN(MLEN, size); bcopy·체인 연결. cached_route: ro_dst 주소(+0x14 → 0x1def18) ≠ ip_dst(+0x28 of ip_msg) 이면 RTFREE(ro_rt)(rt_refcnt +0x26 u16 이 1 이면 rtfree, 아니면 감소) 후 ro_rt = 0; ip_output(top, 0, &cached_route, IP_FORWARDING|IP_ALLOWBROADCAST(0x21)) — 인자 4 개.
3. netipc_msg_send(kmsg): msgh_id(+0x28) ≠ 1959(0x7a7) 이면 FALSE, 아니면 mach_net_output 후 TRUE.
4. netipc_listen(server, src_addr, dst_addr, src_port, dst_port, protocol, ipc_port): uid ≠ 0 → KERN_NO_ACCESS(8); ipc_port == 0 → KERN_INVALID_ARGUMENT(4); lp = zalloc(listener_zone); 필드 저장 순서 src_addr(+4), src_port(+0xc), dst_addr(+8), dst_port(+0xe), ipc_port(+0x10); ipc_object_reference(ipc_port); 버킷 = listeners[protocol & 15](u_char); splnet·잠금(SDK simple_lock), lp->next = head, head = lp, 풀기·splx; ipc_kobject_set(ipc_port, 0, IKOT_NETIPC(0x11)); 0.
5. netipc_ignore(server, ipc_port): result = KERN_FAILURE(5); ipc_port 0 → 4; 버킷마다 Darwin 과 같은 제거 루프(ipc_object_release), 반환 result.
6. find_listener(src_addr, src_port, dst_addr, dst_port, protocol): Darwin 과 같은 순서(dst_port, src_port, src_addr, dst_addr), 앞으로 옮기기, lp->ipc_port 반환.
7. mach_net_init(): listener_zone = zinit(20, 2000, 20, FALSE, "net listener zone"); 템플릿 bits = 0x11, size = 0x7ec(2048 − 20), remote = local = 0, id = 1959(+0x14, msgh_reserved 저장 없음); 버킷 잠금 0; mach_net_kmsg_zone = zinit(2048, 0x2000, 2048, FALSE, "mach_net messages"); zchange(zone, 0, 0, 0, 0); kmem_alloc_wired(kernel_map, &data, 0x2000); zcram(zone, data, 0x2000).
8. netipc_msg_release(kmsg): zfree(mach_net_kmsg_zone, kmsg). receive_ip_datagram(mp): Darwin 꼴(ip_hl > 5 면 ip_stripoptions, m_off > MMAXOFF(0x7c) 또는 m_len < 24 면 m_pullup, find_listener 인라인, 0 이면 FALSE, spl0, zget, 실패면 m_freem·splnet·TRUE; ikm_size = −3, +0xc = 0, +0x10 = 0; ip_len += hl<<2, ip_off >>= 3(부호 있음); space = 0x7d4; 복사 루프(MIN(m_len, space), m_free); delta 계산; header = 템플릿(rep movsd 6); size −= space; remote = port; ipc_object_reference(port); ipc_mqueue_send(kmsg, 0x10000, 0, 0); splnet; TRUE).

방법: 07 새 파일 `kern/mach_net.c`(plan 261). iter·relcheck·zerofill·기록(`__bss` 때문에 P 예상).

261 codex 검토 판정(코딩 전 — 초안은 스크래치 진단 빌드만, 07 미변경):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0–8 대체로 맞음(0x15d8e0 이 0x15d6b8 을 부름, 끝 ret 0x15de67·채움 없음, 데이터·bss·인자·상수) | mnet.dis 열람 | ✅ (계획 0 의 "뒤 끝은 dis 끝 확인" → 채움 0 B) |
| 2 정정: +0xc 저장 1 은 m_cltype = MCL_STATIC(m_type 은 +0xa, 앞서 저장) | SDK sys/mbuf.h MCLGET(`m_cltype = MCL_STATIC`), dis 0x15d751·0x15d80d | ✅ 문구 정정(코드는 매크로 그대로) |
| 7 정정: 저장 안 하는 칸은 msgh_seqno(+0x10) | SDK mach/message.h 헤더 구조 열람 | ✅ 문구 정정 |
| 비교 부호: 크기 검사 jbe/ja(부호 없음), receive 의 m_off·m_len 부호 없음, 루프 jg 부호 있음 | dis 0x15d6f3·0x15d700·0x15d70b·0x15dc69·0x15dc70·0x15d83c | ✅ 보충(Darwin 꼴의 sizeof 비교 그대로) |
| ip_output 반환값을 보지 않음(Darwin 은 검사) | dis 0x15d8c1 뒤 바로 에필로그 | ✅ 차이 추가(초안 `(void) ip_output(...)`) |
| MCLGET 확장·delta 계산 세부 | dis 0x15d7b2–0x15d818, 0x15ddfb–0x15de30 | ✅ (SDK 매크로·Darwin 식 그대로) |
| (내 진단) 클러스터 길이 비교는 MCLBYTES(1024) 가 아니라 CLBYTES(page_size 기반) | 스크래치 빌드 `s5p247-w2`(+4 B) → `w3` CLBYTES 로 0 차이 | ✅ 초안 수정 |

### 261.1 결과 — P
- 스크래치 진단(07 미변경) `s5p247-w1`(mig_errors.h 없음 → 뺌), `w2`(mach_net_output +4 B: 클러스터 길이 비교를 MCLBYTES 로 씀), `w3`(CLBYTES) 텍스트 0 차이.
- 07 `kern/mach_net.c`(새 파일) it1(`s5p247-it1`): `__text` 1968 B·`__data` 61 B(L1d 0x1def10) 0 차이, relcheck 0, `__bss` 24 B zerofill(`s5p247-zerofill-check-mach_net-20261004.json`) [0x1e5bac, 0x1e5bc4) reference-inferred; 알려진 배치 44 건(`zerofill-known-s5p247-20261004.json`).
- 기록: objects_partial +1(40), functions +8(2061), PROVENANCE +1(622), MODIFICATIONS +1.

## 262. S5-P248 세부 계획 — `kern/mach_loader.c`(Mach-O 적재, 전면 작성, D024·D027, Darwin 은 구조만, 코딩 전, 2026-10-04)

근거: `08_build/runs/tools/s5p248-mload.dis`(0x15ca74–0x15d6b8). 참조: NeXTMach·Mach4 에 없음; Darwin 0.1 kern/mach_loader.c 가 같은 구조의 후대 판(get_macho_vnode 만 4.4BSD namei 판으로 크게 다름) — 구조만 참고.

0. 객체 [0x15ca74, 0x15d6b8) 3140 B: `__text` 3137 B(ret 0x15d6b4) + `00` 3 B, 다음 mach_net 0x15d6b8(plan 261). 앞 mach_fat(A) 끝 채움 뒤. 함수(사이 nop): load_machfile 0x15ca74(기호), 정적 parse_machfile 0x15cb1c, load_segment 0x15ce08, load_unixthread 0x15d0d4, load_thread 0x15d158, load_threadstate 0x15d21c, load_threadstack 0x15d270, load_threadentry 0x15d2d4, load_fvmlib 0x15d338, load_idfvmlib 0x15d3e8, load_dylinker 0x15d3fc, get_macho_vnode 0x15d57c. 데이터 없음(0x1def08 "__USER" 는 이 객체 참조 없음).
1. load_result_t(0x14 B): +0 mach_header, +4 entry_point, +8 user_stack, +0xc thread_count, +0x10 비트(unixproc 1, dynlinker 2). load_return_t 값은 Darwin kern/mach_loader.h 와 같음(07 에 없음 → 파일 안 정의). vm_map: links prev +0xc·next +0x10, min +0x14, max +0x18, nentries +0x1c, entries_pageable +0x20, pmap +0x24; entry vme_start +8·vme_end +0xc(07 vm/vm_map.h).
2. load_machfile(vp, header, file_offset, macho_size, result): Darwin 과 같음(old_map = current_task()->map, pmap_reference, vm_map_create(pmap, min, max, entries_pageable), result 없으면 지역, `*result = (load_result_t){0}`(memset 0x14 + 첫 칸 0), parse_machfile(..., 0, 0, result), 실패면 vm_map_deallocate(map) 후 반환, 성공이면 task->map = map, vm_map_deallocate(old_map), 0).
3. parse_machfile: Darwin 과 같은 흐름(depth > 6 → 4, depth++, cputype·check_cpu_subtype → 1, filetype switch(점프 표 7 칸), vnode_pager_setup(vp, 0, 1), 28 + sizeofcmds > macho_size → 2, round_page 0 → 2, vm_allocate_with_pager(kernel_map, &addr, size, TRUE, pager, file_offset) 실패 → 5, pass 1·2 루프(cmd 점프 표 14 칸: SEGMENT·THREAD·UNIXTHREAD·LOADFVMLIB·IDFVMLIB·LOAD_DYLINKER, 그 밖 0), offset 초과면 vm_map_remove 후 2, dylinker 중복이면 4 로 바로 루프 탈출, 끝에 load_dylinker, vm_map_remove, depth 1 이고 thread_count 0 이면 4). load_segment 에 넘기는 end_of_file 은 vp->vm_info->vnode_size.
4. load_segment: Darwin 과 같은 흐름(파일 범위 검사, vmsize·copysize 부호 검사, vm_map_find, 임시 맵·pmap_create, 마지막 페이지 0 채우기 경로, protect 두 번) — 차이: 끝의 mach_header 기록 조건이 `fileoff == 0` 만(filesize 검사 없음).
5. load_unixthread·load_thread·load_threadstate·stack·entry·load_fvmlib·load_idfvmlib·load_dylinker: Darwin 과 같은 흐름(LOAD_RESOURCE 7, thread_create(current_task()), vrele 대신 vn_rele, dylinker 의 TRUE 재시도·entry 보정·dynlinker 비트).
6. get_macho_vnode(path, header, file_offset, macho_size, vpp) — 옛 BSD 꼴로 작성: lookupname(path, UIO_SYSSPACE, FOLLOW_LINK, 0, &vp) 실패 → 4; check_exec_access(vp) 실패 → 6(LOAD_PROTECT), bad; vn_rdwr(UIO_READ, vp, &hdr, 0x1c, 0, UIO_SYSSPACE, 1, 0) 실패 → 4; magic == MH_MAGIC 면 *header = hdr(28 B), *file_offset = 0, *macho_size = vp->vm_info->vnode_size; FAT_MAGIC 또는 바이트 뒤집은 FAT_MAGIC 면 fatfile_getarch(vp, &hdr, &fat_arch) 실패 → 그 값, vn_rdwr(..., 0x1c, fat_arch.offset, ...) 실패 → 4, magic ≠ MH_MAGIC → 2, *header = hdr, *file_offset = fat_arch.offset, *macho_size = fat_arch.size; 그 밖 → 2; 성공이면 *vpp = vp, 0; bad 는 vn_rele(vp) 후 오류값.

방법: 07 새 파일 `kern/mach_loader.c`(plan 262). iter·relcheck·기록(데이터 없음, A 예상).

262 codex 검토 판정(코딩 전 — 초안은 스크래치 진단 `s5p248-w1`–`w3` 만, 07 미변경):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| **내 오류**: "NeXTMach 에 없음" 은 틀림 — mk-108.1 kern/mach_loader.c(487 줄) 있음 | 파일 열람: `load_machfile(vp, header, needargs)`·`parse_machfile(vp, map, header, depth, lib_version, needargs)`, dylinker·fat·load_result 없음 | ✅ 정정: NeXTMach 판은 있으나 원본과 인자·구성이 크게 다른 옛 판이라 바탕으로 쓰지 않음(원본은 Darwin 판 구조에 가까움) — 출처에 명시 |
| 0–2 맞음; "__USER" 는 0x15c6d4·0x15c704 에서 참조(이 객체 밖); 점프 표 둘은 `__text` 안 자료 | odis 0x15c6c8–0x15c710 에서 0x1def08 참조 확인 | ✅ |
| 3: 점프 표 대상(filetype 1·2·5 / 3·6 / 4 / 7, cmd 1·4·5·6·7·14), offset 비교 부호 없음 | 내 python 점프 표 읽기와 같음 | ✅ |
| 4·6 맞음(부호 검사, fileoff==0, lookupname·check_exec_access·vn_rdwr 인자, 오류값) | mload.dis 해당 주소 | ✅ |
| 5 보충: thread 상태 세 함수의 언더플로 검사는 실효 없음(unsigned) | dis 0x15d228–0x15d263 등 `test edi; jne` 만 | ✅ 기록(Darwin 꼴 `if (total_size < 0)` 그대로 — 최적화로 사라짐) |

### 262.1 결과 — A
- 스크래치 진단(07 미변경) `s5p248-w1`(staging 에 mach-o/loader.h 없음 → companion), `w2`(get_macho_vnode 만 4 B 짧음: 지역 배치·분기 순서), `w3`(Darwin 의 is_fat 꼴, fat_arch 를 header 보다 먼저 선언) OBJECT_MATCH.
- 07 `kern/mach_loader.c`(새 파일) it1·it2(`s5p248-it2`, 머리말에 NeXTMach 판 미사용 이유 추가) OBJECT_MATCH(3137 B + 채움 3 B), relcheck 0. 기록: objects_confirmed +1(186), functions +12, PROVENANCE +1, MODIFICATIONS +1.

## 263. S5-P249 세부 계획 — `kern/exception.c`(Mach4 원문 + 바이트가 요구하는 수정) 와 `ipc/ipc_mqueue.h` 원형 복원(코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명으로 세 트리 확인): NeXTMach mk-108.1 kern/exception.c(304 줄, 옛 IPC — 쓰지 않음), Mach4 kernel/kern/exception.c(1003 줄, D022 기본 참조 — 바탕), Darwin 0.1 kern/exception.c(1089 줄, 구조만). 근거 `08_build/runs/tools/s5p249-exc.dis`, 스크래치 진단 `s5p249-w1`–`w6`(07 미변경), 초안 차이 `08_build/runs/tools/s5p249-exception-mach4-vs-draft.diff`.

0. 객체 [0x1568d8, 0x157958) 4224 B: 함수 exception_with_continuation 0x1568d8, exception 0x1569c0, exception_from_kernel 0x156aac, exception_try_task 0x156be0, exception_no_server 0x156c90, exception_raise 0x156cc8, exception_parse_reply 0x1573ec, exception_raise_continue 0x15746c, exception_raise_continue_slow 0x1574b0, exception_raise_continue_fast 0x1577a8(끝 ret 뒤 `00 00`), 다음 host_processors 0x157958. `__data` 0x1deb58: "exception", exc_port_proto(0x1deb64), exc_code_proto(0x1deb68), exception_raise_misses(0x1deb6c), "exception_raise" 두 개 — exc_RetCode_proto 없음.
1. Mach4 판과의 차이(바이트 근거, Darwin 구조 참고로 작성):
   a. exception() 본문은 `__inline__` exception_with_continuation(…, continuation)(전역 기호) 이 되고 `self->exc_func = continuation`(thread +0x38) 를 패닉 검사 뒤에 저장; exception() 은 thread_exception_return 을 넘겨 부름(인라인), exception_from_kernel 은 exc_func·ith_exc·code·subcode 를 저장했다가 0 을 넘겨 부른 뒤 되돌림(인라인).
   b. exception_raise 빠른 경로의 receiver 검사에 `(self->exc_func == 0) ||`; 느린 경로·느린 continuation 의 ipc_mqueue_receive continuation 인자를 `exc_func ? exception_raise_continue : IMQ_NULL_CONTINUE` 로; 성공 시 `exc_func` 이 있으면 call_continuation, 없으면 return(continue_slow), continue_fast 는 call_continuation 후 thread_exception_return.
   c. continue_slow 의 정지 루프: reply port 를 놓고 thread_halt_self_with_continuation(0) 뒤 ith_rpc_reply 로 다시 잡음, IP_VALID 검사와 MACH_RCV_PORT_DIED.
   d. exc_RetCode_proto 를 없애고 parse_reply 는 exc_code_proto 와 비교.
   e. Darwin 의 OLD_FORMAT·ikm_sender·process_terminate_self·빠른 경로 `#if 0` 은 원본에 없음(바이트상 빠른 경로 있음, 오류 코드 꼴 Mach4).
   f. ipc_mqueue_receive 호출은 인자 8 개(Mach4 꼴).
2. `ipc/ipc_mqueue.h`(07, Darwin 사본): ipc_mqueue_receive 원형이 인자 9 개(…, ipc_kmsg_t *list) 인데 원본 함수(0x14acd4)는 [ebp+0x24] 까지 8 개만 쓰고 원본 exception 의 호출도 8 개 → 원형을 8 개로 고침(복원 수정, 표시, 출처 행·diff 갱신). 07 의 .c 에서 ipc_mqueue_receive 를 부르는 곳은 없음(grep 0) → 다른 객체 코드에 영향 없음; 포함 객체 4 개(ipc_port·ipc_pset·ipc_notify·mach_net) 회귀 빌드로 확인.
3. 스크래치 진단: Mach4 + 위 수정(`w6`, 헤더 덮어씀) OBJECT_MATCH(`__text` 4222 B·`__data` 60 B 기호 배치 0 차이).

방법: 07 새 파일 `kern/exception.c` = Mach4 원문(CMU 고지 유지) + 위 수정(plan 263 표시, D024·D027); 07 `ipc/ipc_mqueue.h` 원형 수정. iter·relcheck·회귀 4 개·기록(A 예상).

263 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 경계·함수·데이터 배치 맞음, exc_RetCode_proto 없음(parse_reply 가 exc_code_proto 를 0x157408·0x15760f·0x1577dd 에서 읽음) | exc.dis 열람 | ✅ |
| 변경 a–e 는 바이트가 뒷받침(+0x38 저장, receiver 검사 0x156ea0, continuation 선택 0x1573ae·0x1575a6, 정지 루프, call_continuation, 빠른 경로 있음, OLD_FORMAT·ikm_sender 없음, task_terminate) | exc.dis 해당 주소 | ✅ |
| 2: 원본 ipc_mqueue_receive 는 8 인자, 원본의 직접 호출 19 곳 모두 8 인자 | 내 스캔(19 곳; 0x157496·0x1575bb add esp,0x20; 0x1527b0·0x153e3a push 8 개) | ✅ 헤더 수정 타당 |
| **내 오류**: `__data` 60 B 는 틀림, w6 은 56 B(0x1deb58–0x1deb90, 다음 "host_processors") | w6 L1 json size 56 | ✅ 정정(60 B 는 RetCode 원형이 남은 w5) |
| 1b 보충: exception_raise_continue 의 receive 는 continuation 을 항상 exception_raise_continue(0x157488) 로 | dis 0x157488 `push 0x15746c` | ✅ 초안 그대로(그 호출은 바꾸지 않음) |

### 263.1 결과 — A
- 07 `ipc/ipc_mqueue.h` ipc_mqueue_receive 원형을 8 인자로(복원 수정, 표시, PROVENANCE 행 갱신, diff `x86-ipc_mqueue_h.diff`, MODIFICATIONS +1). 회귀 `s5p249-rg00`–`rg03`: ipc_pset·ipc_port·ipc_notify OBJECT_MATCH, mach_net P 그대로.
- 07 `kern/exception.c`(Mach4 원문 + plan 263 표시 11 곳) it1(`s5p249-it1`) OBJECT_MATCH(4222 B + 채움 2 B, `__data` 56 B 기호 배치), relcheck 0. 기록: objects_confirmed +1(187), functions +10(2083), PROVENANCE +1(exception) + SDK mach/mig_errors.h 채택 1(625), MODIFICATIONS +2.

## 264. S5-P250 세부 계획 — `kern/ipc_kobject.c`(Mach4 원문 + 바이트가 요구하는 수정, 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인): Mach4 kernel/kern/ipc_kobject.c(바탕, D022), Darwin 0.1 kern/ipc_kobject.c(구조만), NeXTMach mk-108.1 에는 같은 이름 파일 없음(확인 필요 — codex 검토 항목). 근거 `08_build/runs/tools/s5p250-kobj.dis`, 스크래치 `s5p250-w1`–`w4`(07 미변경), 초안 차이 `08_build/runs/tools/s5p250-ipc_kobject-mach4-vs-draft.diff`.

0. 객체 [0x1581a8, 0x15846c) 708 B: ipc_kobject_server 0x1581a8, ipc_kobject_set 0x15839c, ipc_kobject_destroy 0x1583d4, ipc_kobject_notify 0x158420(끝 ret 0x158469 뒤 `00 00`), 다음 mach_msg_send_from_kernel(ipc_mig, 0x15846c). 앞은 exception(plan 263) 끝 뒤 채움.
1. Mach4 판과의 차이: (a) 응답 크기 ikm_less_overhead(2048)(kalloc 0x800, ikm_size 0x800); (b) 서버 루틴 앞에 `#if MACH_NET` netipc_msg_send(request) 이면 RetCode = MIG_NO_REPLY(Darwin 구조); (c) 루틴 목록은 mach, mach_port, mach_host, mach_debug(MACH_DEBUG), driverServer(DRIVERKIT) — device·device_pager·mach4·norma·machine 루틴 없음; (d) check_simple_locks() 호출 두 곳 없음(원본에 해당 호출 없음; 07 lock.h 는 MACH_SLOCKS 가 참이라 함수로 남음); (e) ipc_kobject_destroy 에 `#if MACH_NET` IKOT_NETIPC → netipc_ignore(IP_NULL, port) case(Darwin 구조), PAGER·PAGER_TERMINATING case 는 Mach4 그대로.
2. 데이터: printf/panic 문자열과 RetCodeType(0x1dec14) — 스크래치 L1d 일치.
3. 스크래치 진단 `w4` OBJECT_MATCH(`__text` 706 B, `__data` L1d).

방법: 07 새 파일 `kern/ipc_kobject.c` = Mach4 원문(CMU 고지 유지) + 위 수정(plan 264 표시). iter·relcheck·기록(A 예상).

264 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 진입점 4 개 0x1581a8·0x15839c·0x1583d4·0x158420, ret 0x158469 뒤 `00 00`, 명령 706 B | kobj.dis 재생성(odis 0x1581a8–0x15846c) 279 행 ret 0x158469·280 행 `00 00`; python 0x158469−0x1581a8+1 = 706 | ✅ |
| kalloc 0x800(0x1581b1)·ikm_size 0x800(0x1581dc), netipc_msg_send(0x158225) 참이면 MIG_NO_REPLY(0x158232), 디스패치 mach→mach_port→mach_host→mach_debug→driverServer(0x158240–0x15827c), check_simple_locks 호출 없음 | dis 해당 주소(`push 0x800`, `mov [ebx+8],0x800`, `mov [ebx+0x30],0xfffffecf`, call 5 개 순서) | ✅ |
| destroy: 형 9→vm_object_pager_wakeup·8→vm_object_destroy·0x11→netipc_ignore(0, port); notify: id 0x41·0x42·0x45–0x48, 장치 형 0xc 일 때 ds_notify | dis 0x1583de–0x158417·0x158436–0x158458 | ✅(바이트는 동작만 정함, C case 순서는 Mach4 그대로 둠) |
| 데이터 0x1debec "ipc_kobject_server: dropping request\n", 0x1dec14 `02 20 01 10`, 0x1dec18 "ipc_object_destroy: strange destination rights", 91 B | 원본 바이트 python 읽기; 0x1dec47−0x1debec = 91 | ✅ |
| NeXTMach mk-108.1 에 ipc_kobject.c 없음 | `find 01_resources/upstream -name "ipc_kobject*"` → mach4·darwin01 만 | ✅(계획의 "확인 필요" 해소) |
| **보충**: 1e 의 "PAGER_TERMINATING case 는 Mach4 그대로" 는 값이 다름 — 원본 9, Mach4 헤더 15(ipc_kobject.h:68); 장치 형도 원본 0xc, Mach4 10 | Mach4 ipc_kobject.h:63·:68 열람(10, 15); 07 kern/ipc_kobject.h:78 `IKOT_PAGER_TERMINATING 9`·:81 `IKOT_DEVICE 12` | ⚖️ 사실, 단 C 본문 변경은 아님 — 값은 이미 07 에 있는 헤더에서 옴; 기록문에 명시 |

### 264.1 결과 — A
- 07 새 파일 `kern/ipc_kobject.c`(Mach4 원문 + plan 264 표시 6 곳) it1(`s5p250-it1`) OBJECT_MATCH(706 B + 채움 2 B, `__data` 91 B L1d), relcheck 0. 기록: objects_confirmed +1, functions +4, PROVENANCE +1, MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-ipc_kobject.md`·`.diff`.

## 265. S5-P251 세부 계획 — `kern/ipc_mig.c`(Mach4 원문 + 구 IPC 진입점 작성) 와 `ipc/ipc_kmsg.h` 원형 2 개 복원(코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name ipc_mig.c`): Mach4 kernel/kern/ipc_mig.c(바탕, D022), Darwin 0.1 kern/ipc_mig.c(구조만 — msg_send 계열이 있는 유일한 참조), NeXTMach mk-108.1 에는 같은 이름 파일 없음(구 IPC 는 kern/ipc_basics.c 등 다른 꼴, 미사용). 근거 `08_build/runs/tools/s5p251-mig.dis`, 스크래치 `s5p251-w1`(Mach4 그대로: device/device_types.h 없음으로 실패)·`w2`(07 미변경), 초안 차이 `08_build/runs/tools/s5p251-ipc_mig-mach4-vs-draft.diff`·`s5p251-ipc_kmsg_h-draft.diff`.

0. 객체 [0x15846c, 0x159000) 2964 B(명령 2963 B, mig_strncpy ret 0x158ffe 뒤 `00` 1 B): mach_msg_send_from_kernel 0x15846c, mach_msg_abort_rpc 0x1584d4, mach_msg 0x158534, msg_send_from_kernel 0x1586d4, msg_send 0x158774, msg_receive 0x1588d4, msg_rpc 0x1589fc, mig_get_reply_port 0x158f88, mig_dealloc_reply_port 0x158fb4, mig_strncpy 0x158fc8; 다음 thread_go(0x159000). 앞은 ipc_kobject(plan 264) 끝.
1. Mach4 판과의 차이(바이트 근거):
   a. ipc_kmsg_get_from_kernel 은 인자 4 개(msg, size, delta, kmsgp) — 원본 함수 0x147688 은 [ebp+8]–[ebp+0x14] 만 씀; 호출 5 곳(0x158497·0x158567·0x1586f9·0x1587c3·0x158a4a) 모두 push 4 개(codex 검토로 정정, 처음엔 "4 곳"). mach_msg_send_from_kernel·mach_msg 는 delta 0.
   b. mach_msg: ipc_mqueue_send 인자 4 개(IMQ_NULL_CONTINUE), ipc_kmsg_copyout 인자 4 개(원본 0x149158 은 [ebp+0x14] 까지), 본문 오류·성공 때 put_to_kernel 크기 = msgh_size + ikm_delta(0x158692·0x1586ba: [kmsg+0x18]+[kmsg+0x10]).
   c. Mach4 의 mach_msg_rpc_from_kernel 꼭지(panic), mig_put_reply_port, fast_send_right_lookup 이후 port_name_to_*·syscall_* 는 원본에 없음(기호 표 0) → 지움(표시).
   d. 구 IPC 진입점 4 개(msg_send_from_kernel, msg_send, msg_receive, msg_rpc)는 Mach4 에 없음 → 원본 바이트로 작성(D024, `#if MACH_IPC_COMPAT`, plan 265 표시). 흐름은 바이트가 정하며 Darwin 0.1 과 비슷함(D027): 4 바이트 올림과 delta, MSG_SIZE_MAX(0x2000) 검사, copyin_compat 실패 때 ikm_free, SEND_NOTIFY 면 panic, SEND_SWITCH·SEND_TIMEOUT 에 따른 send 두 꼴, 중단 때 thread_should_halt 루프와 SEND_INTERRUPT, msg_rpc 의 커널 객체 빠른 경로(ipc_kobject_server, ip_seqno++), 응답 포트 pset 제거, 중단 뒤 msg_receive 재호출(인라인), copyout_compat 뒤 msgh_size += ikm_delta. Darwin 과 다른 점: MACH_RCV_OLD_FORMAT 없음(receive 선택 인자 = option & 0x100; SDK message.h 에 이름 없음), assert 없음, ipc_kmsg_get_from_kernel 인자 4 개.
   e. mig_strncpy 는 Mach4 꼴(void, int len — 반환값 없음, jle 부호 비교), Darwin 의 vm_size_t 꼴 아님.
   f. device/device_types.h 포함 삭제(쓰던 syscall_device_* 가 없음), mach_ipc_compat.h 포함 추가.
2. `ipc/ipc_kmsg.h`(07, Darwin 사본): ipc_kmsg_get_from_kernel 의 option 인자, ipc_kmsg_copyout 의 list 인자를 지움(복원 수정, 표시). 07 의 .c 에서 두 함수를 부르는 곳 없음(grep 0) → 다른 객체 코드에 영향 없음; 직접 포함 객체(ipc_notify·thread_swap·thread·mach_net·ipc_kobject) 회귀 빌드로 확인.
3. 데이터: panic 문자열 6 개([0x1dec47, 0x1decb5) 110 B: "mach_msg_send_from_kernel", "mach_msg", "msg_send_from_kernel", "msg_send notify", "msg_rpc notify", "mig_dealloc_reply_port") — 스크래치 L1d 일치.
4. 스크래치 진단 `w2`(헤더 덮어씀) OBJECT_MATCH(`__text` 2963 B, 함수 10 개 MATCH, `__data` L1d), relcheck 0.

방법: 07 새 파일 `kern/ipc_mig.c` = Mach4 원문(CMU 고지 유지) + 위 수정(plan 265 표시, D024·D027); 07 `ipc/ipc_kmsg.h` 원형 2 개 수정. iter·relcheck·회귀 5 개·기록(A 예상).

## 266. S5-P252 세부 계획 — `ipc/ipc_mqueue.c`(Mach4 원문 + 바이트가 요구하는 수정, 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name ipc_mqueue.c`): Mach4 kernel/ipc/ipc_mqueue.c(바탕, D022), Darwin 0.1 ipc/ipc_mqueue.c(구조만), NeXTMach mk-108.1 에는 ipc/ 디렉터리와 같은 이름 파일 없음. 근거 `08_build/runs/tools/s5p252-mqueue.dis`, 스크래치 `s5p252-w1`(Mach4 그대로: 원형·thread_block 인자 오류)–`w5`(07 미변경), 초안 차이 `08_build/runs/tools/s5p252-ipc_mqueue-mach4-vs-draft.diff`.

0. 객체 [0x14a634, 0x14af44) 2320 B(명령 2318 B, receive ret 0x14af41 뒤 `00 00`): ipc_mqueue_init 0x14a634, _move 0x14a654, _changed 0x14a728, _send 0x14a764, _send_interrupt 0x14aa34, _copyin 0x14ab94, _receive 0x14acd4; 다음 ipc_notify_init_port_deleted(ipc_notify, A). 앞은 ipc_marequest 쪽 채움(0x14a631–0x14a633).
1. Mach4 판과의 차이(바이트 근거):
   a. ipc_mqueue_send 인자 4 개(continuation 추가 — 07 ipc_mqueue.h 원형과 같음); 받는 쪽이 성공일 때 option & MACH_SEND_SWITCH 면 thread_go_and_switch(continuation, receiver)(0x14aa18–0x14aa1c, 0x14a919), 아니면 thread_go.
   b. 막힐 때 thread_block_with_continuation(0)(0x14a872) — 07 sched_prim.h 의 thread_block 은 인자 없음.
   c. send 의 ith_wait_result 처리: THREAD_INTERRUPTED·THREAD_SHOULD_TERMINATE(2·3) 이면 MACH_SEND_INTERRUPTED, TIMED_OUT(1) 이면 time_out = 0, 그 밖은 아무것도 안 하고 다시 돎(0x14a8aa–0x14a8d7; panic 호출 없음) → THREAD_RESTART·default case 지움.
   d. ipc_mqueue_send_interrupt 는 Mach4 에 없음 → 원본 바이트로 작성(D024, 표시): ip_lock_try 실패면 MACH_MSG_IPC_KERNEL(0x800), 죽은 포트면 MACH_SEND_INVALID_DEST, imq_lock_try 실패면 0x800, ip_msgcount++ 뒤 포트 풀고, 받는 쪽 고르기는 Mach4 send 의 크기 비교 꼴(OLD_FORMAT·trailer 없음 — Darwin 의 같은 이름 루틴과 다름, D027; codex 검토로 정정: Darwin 이 루틴에 scatter 검사는 원래 없음).
   e. receive: continuation 이 있으면 thread_block_with_continuation(continuation), 없으면 (0)(0x14add1–0x14ade2, 두 호출이 하나로 합쳐진 꼴); 안쪽 wait_result 처리는 c 와 같음(panic 없음); 바깥 default 는 panic("ipc_mqueue_receive: strange ith_state")(0x14aea4) 그대로.
2. 데이터: "ipc_mqueue_receive: strange ith_state" [0x1de72e, 0x1de754) 38 B — 스크래치 L1d 일치.
3. 스크래치 진단 `w5` OBJECT_MATCH(`__text` 2318 B, 함수 7 개 MATCH), relcheck 0.

방법: 07 새 파일 `ipc/ipc_mqueue.c` = Mach4 원문(CMU 고지 유지) + 위 수정(plan 266 표시 10 곳, D024·D027). 헤더 수정 없음. iter·relcheck·기록(A 예상).

265 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 진입점 10 개, ret 0x158ffe 뒤 `00` 1 B, 2964 B | 앞서 낸 symbols 목록(0x15846c–0x158fc8, 다음 0x159000), s5p251-mig.dis 끝 ret 0x158ffe | ✅ |
| **내 오류**: get_from_kernel 호출은 4 곳이 아니라 5 곳 | `grep -c _ipc_kmsg_get_from_kernel s5p251-mig.dis` = 5(주소 5 개 확인) | ✅ 본문 정정 |
| 1b: send 4 인자, copyout 4 인자, put_to_kernel 크기 [kmsg+0x18]+[kmsg+0x10], too-large 0x18 | dis 0x1585bc–0x1585c6, 0x15866c–0x158674, 0x158692·0x1586ba, 0x158658 | ✅ |
| 1c: 지운 함수의 기호 없음; Mach4 thread_get/set_state_KERNEL 도 없음 | symbols.tsv grep 0 건; Mach4 ipc_mig.c:684·:701 은 fast_send_right_lookup(:416) 뒤라 이미 지운 범위 | ✅(목록에 이름만 보탬, 행동 변화 없음) |
| 1d: receive 선택 인자 = option & 0x100(OLD_FORMAT 없음), msg_rpc 안에 msg_receive 호출 없음(인라인) | dis 0x15893d–0x158940·0x158d79·0x158e44 `and eax,0x100`; `grep "call 0x1588d4"` 0 건 | ✅ |
| 보탬: 원본 ipc_mqueue_receive 호출은 8 인자(Darwin 은 9 번째 0) | dis `add esp,0x20` 4 곳(0x15861c·0x158951·0x158d8b·0x158e58 — codex 의 0x15894f 는 바로 앞 명령); Darwin ipc_mig.c 의 receive 호출 끝 `&kmsg, &seqno, 0` | ✅(07 원형은 plan 263 에서 이미 8 인자) |
| 1e: jle 부호 비교는 Mach4 int len 과 맞으나 반환형은 바이트로 못 정함 | dis 0x158fd6 `jle`; 반환값을 eax 에 두지 않음 | ⚖️ 사실, Mach4 void 꼴 유지 |
| 2·3·4: 07 의 .c 호출 0, 데이터 110 B 다음 "thread_handoff", w2 OBJECT_MATCH | 앞선 grep 0 건, python 데이터 읽기(0x1decb5 "thread_handoff"), w2 L1 json | ✅ |

### 265.1 결과 — A
- 07 `ipc/ipc_kmsg.h`: ipc_kmsg_get_from_kernel(option 없음)·ipc_kmsg_copyout(list 없음) 원형을 4 인자로(복원 수정, 표시, PROVENANCE 행 갱신, diff `x86-ipc_kmsg_h.diff` 다시 냄, MODIFICATIONS +1). 회귀 `s5p251-rg00`–`rg04`: ipc_notify·thread_swap·thread·ipc_kobject OBJECT_MATCH, mach_net P 그대로.
- 07 새 파일 `kern/ipc_mig.c`(Mach4 원문 + plan 265 표시, 구 IPC 진입점 4 개 작성) it1(`s5p251-it1`) OBJECT_MATCH(2963 B + 채움 1 B, `__data` 110 B L1d), relcheck 0. 기록: objects_confirmed +1, functions +10, PROVENANCE +1, MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-ipc_mig.md`·`.diff`.

266 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 앞 `00` 3 개, ret 0x14af41, 뒤 `00 00`, 2318/2320 B | s5p252-mqueue.dis 0x14af41 ret·0x14af42; 앞서 낸 바이트 `c3 00 00 00 55`(0x14a630–0x14a634); python 2320 | ✅ |
| 1a–c: switch 비트 0x20000(0x14aa18)·thread_go_and_switch(0x14a919)·thread_block_with_continuation(0)(0x14a872)·send wait_result 1/2·3/그 밖 | dis 해당 주소(앞서 연 send 디스어셈블) | ✅ |
| **내 오류**: Darwin send_interrupt 에는 scatter 검사가 없음(OLD_FORMAT·trailer 만) | Darwin ipc_mqueue.c:625 이후 루틴 본문 열람(scatter 0 건, OLD_FORMAT·REQUESTED_TRAILER_SIZE 있음) | ✅ 본문 정정 |
| 1d: 반환 0x800(0x14aa51)·0x10000003(0x14aa66)·0x800(0x14aa9b), msgcount++ 뒤 unlock | dis 371·378·397 행, 0x14aab1–0x14aab6 | ✅ |
| 1e: receive 호출 합침(0x14ade2), 안쪽 1/2·3/그 밖 재시도(0x14ae71–0x14ae9f), 바깥 default panic(0x14aea4·0x14aea9) | dis 0x14add1–0x14ade7, 0x14ae6e–0x14aeb1 | ✅ |
| 2·3: 데이터 38 B, w5 일치 | python 문자열 길이 38·0x1de754; w5 L1 json OBJECT_MATCH | ✅ |
| 보탬: Darwin MACH_SEND_SWITCH 0x80000(SDK 0x20000), Mach4 THREAD_RESTART 3(07 은 4, SHOULD_TERMINATE 3) | Darwin mach/message.h:455, Mach4 kern/sched_prim.h:49 열람 | ✅ 기록(값은 07·SDK 헤더에서 오며 바이트와 맞음) |
| 보탬: 초안 주석의 "simple message" 는 원본이 확인하지 않는 가정 | 원본 send_interrupt 에 msgh_bits 검사 없음(dis 0x14aa34–0x14ab90) | ✅ 주석 고침(코드 변화 없음) |

### 266.1 결과 — A
- 07 새 파일 `ipc/ipc_mqueue.c`(Mach4 원문 + plan 266 표시 10 곳, ipc_mqueue_send_interrupt 작성) it1(`s5p252-it1`) OBJECT_MATCH(2318 B + 채움 2 B, `__data` 38 B L1d), relcheck 0. 헤더 수정 없음. 기록: objects_confirmed +1, functions +7, PROVENANCE +1, MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-ipc_mqueue.md`·`.diff`.

## 267. S5-P253 세부 계획 — `ipc/ipc_init.c`(Mach4 원문 + 바이트가 요구하는 수정, 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name ipc_init.c`): Mach4 kernel/ipc/ipc_init.c(바탕, D022), Darwin 0.1 ipc/ipc_init.c(구조만), NeXTMach mk-108.1 에는 같은 이름 파일 없음. 근거 `08_build/runs/tools/s5p253-init.dis`, 스크래치 `s5p253-w1`(Mach4 그대로: ZONE_EXHAUSTIBLE·IPC_ZONE_TYPE 없음으로 실패)·`w2`(07 미변경), 초안 차이 `08_build/runs/tools/s5p253-ipc_init-mach4-vs-draft.diff`.

0. 객체 [0x146dc0, 0x146f38) 376 B: ipc_bootstrap 0x146dc0, ipc_init 0x146ed8(ret 0x146f37, 채움 없음); 앞은 ipc_hash 끝 ret 0x146dbd 뒤 `00 00`; 다음 ipc_kmsg_enqueue(ipc_kmsg).
1. Mach4 판과의 차이(바이트 근거):
   a. zone 4 개: zinit(size, max, size, FALSE, 이름) 다음 zchange(zone, FALSE, FALSE, TRUE, FALSE)(0x146de1–0x146ea6: 매번 push 0·이름, 이어 zchange push 0,1,0,0,zone). Mach4 의 IPC_ZONE_TYPE·ZONE_EXHAUSTIBLE 은 07 zalloc.h 에 없음(07 zinit 은 pageable 인자, zchange 는 5 인자). Darwin 과 같은 꼴(D027).
   b. ipc_init: `#if MACH_OLD_VM_COPY`(생성 설정 1) task_create(TASK_NULL, FALSE, &ipc_soft_task) 가 실패하면 panic("ipc_init"), ipc_soft_map = ipc_soft_task->map(0x146ede–0x146f08). Darwin 의 page zero vm_allocate 와 ipc_kernel_copy_map 은 원본에 없음(kmem_suballoc 호출 1 번, vm_allocate 호출 없음).
   c. ipc_soft_task·ipc_soft_map 정의(07 vm_kern.h:79 에 ipc_soft_map extern 있음) — 원본 기호 0x1f6248·0x1f6244(common), 스크래치에서도 common.
   d. NORMA_IPC 블록·assert 는 설정상 코드 없음(원본에 ipc_space_create_special 2 번만).
2. 데이터 [0x1de6bc, 0x1de70d) 81 B: ipc_kernel_map_size 0x100000, ipc_space_max 0x205, ipc_tree_entry_max 0x10000, ipc_port_max 0x5a20, ipc_pset_max 0x4c8(07 kern/mach_param.h 식으로 python 계산 일치), 문자열 "ipc spaces"·"ipc tree entries"·"ipc ports"·"ipc port sets"·"ipc_init"; 뒤 `00 00 00` 다음 ipc_marequest_max(0x1de710). 스크래치 기호 배치 일치.
3. 스크래치 진단 `w2` OBJECT_MATCH(`__text` 376 B, 함수 2 개 MATCH, `__data` 81 B), relcheck 0.

방법: 07 새 파일 `ipc/ipc_init.c` = Mach4 원문(CMU 고지 유지) + 위 수정(plan 267 표시 8 곳, D024·D027). 헤더 수정 없음. iter·relcheck·기록(A 예상).

267 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 376 B, ret 0x146f37 채움 없음, 앞 ret 0x146dbd 뒤 `00 00`; 앞 함수 이름은 _ipc_hash_info(0x146d54) | s5p253-init.dis; symbols.tsv 행 `1538 0x146d54 _ipc_hash_info`(108 B → 0x146dc0) | ✅(이름 보탬: ipc_hash 객체의 _ipc_hash_info) |
| 1: zinit (size,max,size,0,name)·zchange (zone,0,0,1,0) 4 쌍, task_create(0,0,&ipc_soft_task)·panic·map 저장, kmem_suballoc 1 번, vm_allocate 없음 | dis 0x146de1–0x146ea6·0x146ede–0x146f25(앞서 연 전문) | ✅ |
| 1c: 세 변수 common, 원본 0x1f622c·0x1f6244·0x1f6248(파일 바이트 없음) | symbols.tsv 해당 3 행(section 6); 스크래치 기호 type 1 value 4(python 파싱) | ✅ |
| 1d: NORMA·assert 없음은 설정 결과, `#if MACH_OLD_VM_COPY` 자리는 바이트로 못 정함 | 생성 norma_ipc·mach_assert 0, mach_old_vm_copy 1 | ⚖️ 사실 — 아래 NeXTMach 꼴로 자리를 정함 |
| 2·3: 데이터 81 B 값·문자열, 뒤 `00 00 00`·ipc_marequest_max 0x400, w2 일치 | python 바이트 읽기(앞서 낸 출력), w2 L1 json | ✅ |
| **누락**: NeXTMach 에 같은 이름 파일은 없지만 kern/ipc_globals.c 가 ipc_init 과 세 변수를 가짐(:127–129, :429), pmap = PMAP_NULL(:482)은 원본에 없음 | ipc_globals.c:127–129·:429–495 열람; :475–477 task_create·panic, :479–483 `#if MACH_OLD_VM_COPY` map·pmap | ✅ 채택 — 사용자 기준(2026-10-04 "기준은 mach4, mach2, darwin 은 코드 참고용")대로 soft task 부분을 NeXTMach 꼴로 바꿈: task_create 는 조건 없이, map 저장만 `#if MACH_OLD_VM_COPY`(pmap 줄 없음). 스크래치 `w3` OBJECT_MATCH(바이트 같음) |

### 267.1 결과 — A
- 07 새 파일 `ipc/ipc_init.c`(Mach4 원문 + plan 267 표시, soft task 부분은 NeXTMach kern/ipc_globals.c:475–480 꼴) it1(`s5p253-it1`) OBJECT_MATCH(376 B, `__data` 81 B 기호 배치), relcheck 0. 헤더 수정 없음. 기록: objects_confirmed +1, functions +2, PROVENANCE +1, MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-ipc_init.md`·`.diff`.
- 보류: 0x15a628–0x15a67c 의 ds_notify·vm_object_pager_wakeup·send_notification·task_secure(84 B). 원래 파일 이름을 바이트로 정할 수 없고, Darwin 의 파일 배치(send_notification 이 ipc_xxx.c 에 있음)는 기준 근거가 아님(2026-10-04 사용자 지시). ipc_xxx(A) 경계는 그대로 둠. [2026-10-08: D056 으로 해제 — 07 kern/ipc_xxx.c 끝에 둠, plan 392]

## 268. S5-P254 세부 계획 — `ipc/mach_msg.c`(Mach4 원문 + 바이트가 요구하는 수정) 와 `ipc/ipc_kmsg.h` 원형 2 개 복원(코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name mach_msg.c`): Mach4 kernel/ipc/mach_msg.c(바탕, D022; 구 IPC 트랩 msg_send_trap·msg_receive_trap·msg_rpc_trap·msg_receive_continue 도 MACH_IPC_COMPAT 로 포함), Darwin 0.1 ipc/mach_msg.c(참고만), NeXTMach mk-108.1 에는 같은 이름 파일 없음(mach4/libmach·darwin01/Libc 의 같은 이름 파일은 사용자 공간 판, 무관). 근거 `08_build/runs/tools/s5p255-mach_msg.dis`, 스크래치 `s5p255-w1`–`w10`(07 미변경), 초안 차이 `08_build/runs/tools/s5p255-mach_msg-mach4-vs-draft.diff`·`s5p255-ipc_kmsg_h-draft.diff`.

0. 객체 [0x1525a8, 0x154b28) 9600 B(채움 없음, ret 0x154b27): mach_msg_send, mach_msg_receive, mach_msg_receive_continue, mach_msg_trap(5192 B), mach_msg_continue, mach_msg_interrupt, msg_return_translate, msg_send_trap, msg_send_switch_continue, msg_receive_trap, msg_rpc_trap, msg_receive_continue; 앞 mach_port_kernel_object ret 0x1525a6 뒤 `00`; 다음 mach_port_names_helper.
1. Mach4 판과의 차이(바이트 근거, plan 268 표시 43 곳):
   a. CONTINUATIONS: 원본에 continuation 함수·스레드 상태 저장이 있음 → Mach4 i386/kernel/Makerules:34 의 `-DCONTINUATIONS` 를 파일 맨 앞 `#define` 으로(다른 객체 빌드 옵션은 그대로).
   b. ipc_kmsg_get 은 인자 4 개(msg, size, delta, kmsgp; 원본 0x14758c 는 [ebp+0x14] 까지): Mach 꼴 호출은 delta 0(0x1525cc·0x1535ad·0x1539ce·0x153bd4 `push 0`), 구 IPC 트랩은 4 바이트 올림 차이(send_delta).
   c. ipc_mqueue_send 4 번째 인자: IMQ_NULL_CONTINUE, msg_send_trap 의 SEND_SWITCH 갈래만 msg_send_switch_continue(0x1543e4). SEND_SWITCH(0x20) 면 MACH_SEND_SWITCH(0x20000) 를 더함 — msg_send_trap·msg_rpc_trap 의 SEND_NOTIFY 갈래(0x154374–0x154381, 0x154758–0x154765)와 그 밖 갈래(별도 호출 두 꼴, 0x1543dc·0x1547d4).
   d. Mach 꼴 ipc_kmsg_put 크기 = msgh_size + ikm_delta(14 곳; 예 mach_msg_send 오류 갈래 0x1526ec `add edx,[eax+0x10]`), 빠른 경로 reply_size 도 + ikm_delta(2 곳), 빠른 경로 get 뒤 ikm_delta = 0(0x152b8f `mov [esi+0x10],0`).
   e. 구 IPC 트랩: 받기 크기 = (option & RCV_LARGE) ? rcv_size : MACH_MSG_SIZE_MAX(0x1544e8–0x1544f5 등 3 곳), 받은 메시지가 rcv_size 보다 크면 ipc_kmsg_destroy 후 RCV_TOO_LARGE(-204, 번역 없이; 0x154552·0x1549d5, continue 는 thread_syscall_return 0x154ad0), copyout_compat 뒤 msgh_size += ikm_delta, assert 없음.
   f. msg_rpc_trap: ipc_mig msg_rpc(plan 265)와 같은 커널 객체 빠른 경로(ipc_kobject_server, ip_seqno++, copyout_reply 로 감; 0x154640–0x154732)와 receive_reply 꼬리표 — 원본 바이트로 작성(D024).
   g. msg_send_switch_continue: thread_syscall_return(SEND_SUCCESS)(0x154448–0x154455) — Mach4 에 없음, 작성(D024). 07 ipc/mach_msg.h:106 에 원형 있음.
2. `ipc/ipc_kmsg.h`(07): ipc_kmsg_get 의 option 인자, ipc_kmsg_copyout_pseudo 의 list 인자를 지움(원본 0x1491ac 는 [ebp+0x10] 까지 = 3 인자). 07 의 .c 에서 두 함수를 부르는 곳 없음(grep 0) → 포함 객체 회귀로 확인.
3. 데이터 [0x1dea9c, 0x1deada) 62 B: "msg_return_translate: %x -> interrupted\n", "msg_return_translate" — 앞 ipc_table_dnrequests_size(0x1dea98), 뒤 "mach_port_get_re…"; 스크래치 L1d 일치.
4. 스크래치 진단 `w10` OBJECT_MATCH(`__text` 9600 B, 함수 12 개 MATCH), relcheck 0.

방법: 07 새 파일 `ipc/mach_msg.c` = Mach4 원문(CMU 고지 유지) + 위 수정(plan 268 표시, D024·D027); 07 `ipc/ipc_kmsg.h` 원형 2 개 수정. iter·relcheck·회귀(ipc_kmsg.h 포함 객체)·기록(A 예상).

268 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 9600 B, 0x1525a7 `00`, ret 0x154b27, mach_msg_trap 5192 B | python 바이트 `c3 00 55`(0x1525a6–0x1525a8), 0x154b28−0x1525a8 = 9600, fnbytes 5192 | ✅ |
| 1: ipc_kmsg_get 호출 6 곳(Mach 꼴 4 곳 delta 0, 구 트랩 2 곳 send_delta), copyout_pseudo 4 곳 3 인자, ipc_mqueue_send 16 곳 중 continuation 은 0x15441e(msg_send_switch_continue) 한 곳만 | s5p255-mach_msg.dis grep: get 6·pseudo 4·send 16; 0x1543e4 `push 0x154448` → 0x15441e call | ✅ |
| 1d 보충: ipc_kmsg_put 28 곳, delta 더하기 16 곳(소스 식 14 + reply_size 2 와 맞음); ikm_delta = 0 저장은 0x152b4f·0x152b8f·0x153547 세 곳 | grep put 28; dis 547·1357 행 `mov [ecx+0x10],0`(나머지 둘은 ikm_check_initialized 매크로가 냄, 07 ipc_kmsg.h) | ✅ 본문 주소 보탬(행동 변화 없음) |
| 1e·f: 구 IPC 받기 3 곳 RCV_LARGE 선택·RCV_TOO_LARGE 직접 반환·delta 더하기, msg_rpc_trap 빠른 경로 | dis 0x1544e8·0x154966·0x154a60, 0x154552·0x1549d5·0x154ad0, 0x154640–0x154732(앞서 연 전문) | ✅ |
| 2·3·4: 원형(0x14758c 4 인자, 0x1491ac 3 인자), 07 .c 호출 0, 데이터 62 B, w10 일치 | 앞서 낸 인자 슬롯 집계; grep 0 건; python 데이터 위치 0x1dea9c(1 곳); w10 L1 json | ✅ |
| **누락**: NeXTMach 에 같은 이름 파일은 없지만 kern/ipc_basics.c 가 mach_msg(:768)·msg_send_trap(:1444)·msg_receive_trap(:1557)·msg_rpc_trap(:1816) 를 가짐 | ipc_basics.c 해당 행 열람: msg_copyin/msg_queue 를 쓰는 옛 커널 IPC 구현(원본은 ipc_kmsg_get·ipc_mqueue_send 호출) | ⚖️ 사실 — 참조 줄에 "있으나 다른 구현이라 쓰지 않음" 으로 기록. 같은 파일의 msg_send_from_kernel 도 plan 265 와 같은 이유로 쓰지 않음 |

### 268.1 결과 — A
- 07 `ipc/ipc_kmsg.h`: ipc_kmsg_get(option 없음)·ipc_kmsg_copyout_pseudo(list 없음) 원형 복원(표시, PROVENANCE 행 갱신, diff `x86-ipc_kmsg_h.diff` 다시 냄, MODIFICATIONS +1). 회귀 `s5p255-rg00`–`rg06`·`s5p255-rh00`: ipc_notify·thread_swap·thread·ipc_kobject·ipc_mig·ipc_init·ipc_mqueue OBJECT_MATCH, mach_net P 그대로.
- 07 새 파일 `ipc/mach_msg.c`(Mach4 원문 + plan 268 표시 43 곳) it1(`s5p255-it1`) OBJECT_MATCH(9600 B, `__data` 62 B L1d), relcheck 0. 기록: objects_confirmed +1, functions +12, PROVENANCE +1, MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-mach_msg.md`·`.diff`.

## 269. S5-P256 세부 계획 — `ipc/ipc_kmsg.c`(Mach4 원문 + MACH_OLD_VM_COPY 등 바이트가 요구하는 수정) 와 `ipc/ipc_kmsg.h` ipc_kmsg_copyout_body 원형 복원(코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name ipc_kmsg.c`): Mach4 kernel/ipc/ipc_kmsg.c(바탕, D022), Darwin 0.1 ipc/ipc_kmsg.c(참고만), NeXTMach mk-108.1 에는 같은 이름 파일 없음; 옛 IPC 의 out-of-line 처리는 NeXTMach kern/ipc_copyin.c:708(`#if MACH_OLD_VM_COPY` vm_move 로 ipc_soft_map 에 옮김)가 같은 생각 — 그 꼴을 따름. 근거 `08_build/runs/tools/s5p256-kmsg.dis`, 스크래치 `s5p256-w1`–`w9`(07 미변경), 초안 차이 `08_build/runs/tools/s5p256-ipc_kmsg-mach4-vs-draft.diff`·`s5p256-ipc_kmsg_h-draft.diff`.

0. 객체 [0x146f38, 0x14a0d8) 12704 B(명령 12702 B, copyout_compat ret 뒤 `00 00`): ipc_kmsg_enqueue … ipc_kmsg_copyout_compat 25 개(ipc_kmsg_copyin_body 기호 없음); 앞 ipc_init(plan 267) ret 0x146f37, 다음 ipc_marequest_init. `__data` 없음, common _ipc_kmsg_cache(원본 0x1f6258).
1. Mach4 판과의 차이(바이트 근거, plan 269 표시 25 곳):
   a. ipc_kmsg_rmqueue 의 IKM_BOGUS 저장 없음(0x146f98–0x146fc5).
   b. ipc_kmsg_free: IKM_SIZE_NETWORK 은 아무것도 안 함, DRIVERKIT IKM_SIZE_DEVICE → KernDeviceInterruptMsgRelease(0x147569), MACH_NET IKM_SIZE_NETIPC → netipc_msg_release(0x147575); 그 밖 kfree. ikm_free 를 쓰는 곳마다 인라인(0x14764d·0x14774d·0x1477a1 등).
   c. ipc_kmsg_get(msg, size, delta, kmsgp): delta > 0 이면 MACH_SEND_MSG_TOO_SMALL(0x1475a2), copyinmsg 크기 size + delta(0x14761d), ikm_delta = delta(0x14766c). ipc_kmsg_get_from_kernel 도 같은 꼴(bcopy size + delta, 0x1476b4–0x1476ca). (07 ipc_kmsg.h 원형은 plan 265·268 에서 이미 4 인자.)
   d. ipc_kmsg_put_to_kernel 은 bcopy(&kmsg->ikm_header, msg, size)(0x147783) — Mach4 의 memcpy·DIPC assert 아님.
   e. MACH_OLD_VM_COPY(생성 설정 1): out-of-line 비포트 자료는 ipc_soft_map 에 있음 — clean_body·clean_partial 은 vm_deallocate(ipc_soft_map, data, length)(0x147180 등), copyin·copyin_compat 은 vm_move(map, addr, ipc_soft_map, length, dealloc, &copy)(0x14828c·0x14993b), copyout_body·copyout_compat 은 vm_move(ipc_soft_map, data, map, length, FALSE, &addr) 뒤 vm_deallocate(ipc_soft_map, data, length)(0x1490ce·0x14a08d), use_page_lists·steal_pages 계산 없음. `#else` 에 Mach4 글을 남김.
   f. ipc_kmsg_copyin_body 는 원본에 기호가 없고 몸이 ipc_kmsg_copyin 안에 있음(916 B, 0x148008) → 몸을 ipc_kmsg_copyin 안으로 옮김(static 으로는 인라인되지 않음, w4).
   g. ipc_kmsg_copyin_compat_from_kernel 은 Mach4 에 없음 → 원본 바이트로 작성(D024; Darwin 참고만, D027): dest COPY_SEND·reply MAKE_SEND copyin_from_kernel, msgh_bits = copyin_type 두 개, msg_simple 이면 끝, 형 기술자의 msgt_unused 지우기(0x149b7c)·longform 이면 머리 칸 지우기, 포트면 새 이름·copyin_from_kernel·RECEIVE 순환 검사, complex 면 COMPLEX 비트.
2. `ipc/ipc_kmsg.h`(07): ipc_kmsg_copyout_body 를 Mach4 꼴 (saddr, eaddr, space, map) 으로(원본 copyout 0x149180–0x149192 이 &header+1, header+size, space, map 을 넘김). 07 에서 부르는 곳은 ipc/mach_msg.c:1249(Mach4 꼴 인자) 하나 — 회귀에 mach_msg 포함.
3. 스크래치 진단 `w9` OBJECT_MATCH(`__text` 12702 B, 함수 25 개 MATCH), relcheck 0.

방법: 07 새 파일 `ipc/ipc_kmsg.c` = Mach4 원문(CMU 고지 유지) + 위 수정(plan 269 표시, D024·D027); 07 `ipc/ipc_kmsg.h` copyout_body 원형 수정. iter·relcheck·회귀(ipc_kmsg.h 포함 객체 + mach_msg)·기록(A 예상).

269 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 12704 B, ret 0x14a0d5 뒤 `00 00`, 함수 25 개·copyin_body 기호 없음, common _ipc_kmsg_cache | python 바이트 `5d c3 00 00 55 89`(0x14a0d4–), 0x14a0d8−0x146f38 = 12704; w9 기호(type 1 value 4); symbols.tsv 0x1f6258 | ✅ |
| 1a–d·f·g: IKM_BOGUS 없음, free 경우, get 의 delta·bcopy, 합친 copyin, compat_from_kernel 동작 | s5p256-kmsg.dis 해당 주소(앞서 연 전문) | ✅ |
| **보탬**: get_from_kernel 에는 delta > 0 검사가 없음(“같은 꼴”이 검사까지 뜻하지 않음) | dis 0x147688–0x1476ea(검사 없음); 초안도 검사 없음 | ✅ 본문 뜻 분명히 함(코드 변화 없음) |
| **보탬**: ipc_soft_map 해제는 clean(0x147300)·copyout_body(0x148f00)·copyout_dest(0x149609)·copyout_compat(0x149f77)에도 있음; 포트 자료의 사용자 map 해제 0x148256·0x1498fe; copyout_pseudo 가 copyout_body 를 0x149414 에서 부름 | dis 해당 9 주소 `call _vm_deallocate`/`_ipc_kmsg_copyout_body` 확인, vm_deallocate 모두 11 곳 | ✅ 앞의 넷은 clean_body·clean_partial 의 인라인(소스 수정 두 곳에서 나옴), 포트 해제는 Mach4 글 그대로 |
| 2·3: copyout_body 원형, 07 호출 mach_msg.c:1249 하나, w9 일치 | grep 결과(앞서 낸 출력), w9 L1 json | ✅ 회귀에 mach_msg 포함 |
| 참조: NeXTMach ipc_copyin.c:708·ipc_copyout.c:683 은 vm_move 꼴의 국소 모형이나 함수 전체로는 Mach4 틀이 더 가까움; compat_from_kernel 은 Darwin 이 가장 가까운 이름 있는 참조 | ipc_copyout.c:680–690 열람(`#if MACH_OLD_VM_COPY` map 선택) | ✅ 참조 줄과 기록문에 반영 |

### 269.1 결과 — A
- 07 `ipc/ipc_kmsg.h`: ipc_kmsg_copyout_body 원형을 Mach4 꼴로(표시, PROVENANCE 행 갱신, diff `x86-ipc_kmsg_h.diff` 다시 냄, MODIFICATIONS +1). 회귀 `s5p256-rg00`–`rg08`: ipc_notify·thread_swap·thread·ipc_kobject·ipc_mig·ipc_init·ipc_mqueue·mach_msg OBJECT_MATCH, mach_net P 그대로.
- 07 새 파일 `ipc/ipc_kmsg.c`(Mach4 원문 + plan 269 표시 25 곳, copyin_body 합침, copyin_compat_from_kernel 작성) it1(`s5p256-it1`) OBJECT_MATCH(12702 B + 채움 2 B), relcheck 0. 기록: objects_confirmed +1, functions +25, PROVENANCE +1, MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-ipc_kmsg.md`·`.diff`.

## 270. S5-P260 세부 계획 — `bsd/kern/qsort.c`(참조 원문 없음, 원본 바이트로 작성 D024; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name qsort.c`): Darwin 0.1 kernel/bsd/kern/qsort.c(4.4BSD Bentley–McIlroy 판 — med3·swapfunc, 원본과 다른 알고리즘, 쓰지 않음)·Libc 판(사용자 공간), Mach4·NeXTMach 에는 커널 qsort 없음(`grep -rl mthresh` 0 건). 근거 `08_build/runs/tools/s5p260-qsort.dis`, 초안 `08_build/runs/tools/s5p260-qsort-draft.c`, 스크래치 `s5p260-w1`·`w2`(07 미변경).

0. 객체 [0x10ba60, 0x10bd48) 744 B(명령 742 B, 정적 qst ret 0x10bd45 뒤 `00 00`): 기호 _qsort 하나, 그 뒤 기호 없는 정적 함수 0x10bb88(qsort 가 0x10bab0 에서 부름, 자기 자신을 0x10bd05·0x10bd25 에서 부름); 앞 thread_psignal ret 0x10ba5e 뒤 `00`, 다음 logopen(subr_log). 파일 이름은 바이트로 정할 수 없음 — bsd/kern 배치(kern_sig 와 subr_log 사이)와 Darwin 의 이름을 따라 `bsd/kern/qsort.c`.
1. 바이트가 보이는 알고리즘(4.3BSD C 라이브러리 qsort 와 같은 꼴 — 글이 닮을 수밖에 없음, D027 의 취지): 정적 변수 4 개 qcmp(0x1dac04)·qsz(0x1dac08)·thresh(0x1dac0c, size×4)·mthresh(0x1dac10, size×6); qsort: n ≤ 1 이면 끝, n ≥ 4 면 qst(base, max) 후 hi = base + thresh, 처음 THRESH 개 중 최소를 맨 앞으로 바꾸고(바이트 단위), 보초를 둔 삽입 정렬(0x10bb18–0x10bb7b). qst: 셋의 중앙값(lo ≥ mthresh 일 때, 0x10bbb8), 분할 교환(0x10bc40–0x10bcd9), 작은 쪽 재귀·큰 쪽 반복(lo ≥ thresh, 0x10bcf5–0x10bd36).
2. 데이터: 정적 변수 넷이 `__data`(0x1dac04–0x1dac14, 0)에 있음 → 0 초기값을 적음(초기값 없으면 `__bss` 로 감, w1). 스크래치 w2 L1d 일치.
3. 스크래치 진단 `w2` OBJECT_MATCH(`__text` 742 B, qsort + 정적 qst), relcheck 0.
4. 사용권: 참조 원문을 옮긴 것이 아니라 바이트에서 쓴 글이나 4.3BSD(UC Berkeley) qsort 와 닮음 — 파일 머리 주석에 밝힘. BSD 고지를 붙일지는 사용자 판단 사항(D013)으로 보고 때 알림.

방법: 07 새 파일 `bsd/kern/qsort.c` = 위 초안(plan 270 표시, D024). iter·relcheck·기록(A 예상, PROVENANCE kind authored).

270 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 744 B(명령 742 B + `00 00`), _qsort 만 기호, 0x10bb88 은 0x10bab0·0x10bd05·0x10bd25 에서 불림 | symbols.tsv 행 `2547 0x10ba60 _qsort`; s5p260-qsort.dis(앞서 연 전문) | ✅ |
| 1·2·3: 정적 넷·×4·×6, 흐름, `__data` 16 B 0, w2 일치 | dis 0x10ba78–0x10ba96; 섹션 표(python, __data 0x1da000–0x1e56be); w2 L1 json | ✅ |
| 보탬: dis 295 행(0x10bd46)은 채움 2 B 를 명령으로 푼 것 | dis 295 행 `add byte ptr [eax], al`(295 행이 마지막) | ✅ 기록(본문 0 은 이미 "채움 `00 00`") |
| 보탬: 표준 원형은 size_t(Darwin stdlib.h:125), 초안은 int | Darwin stdlib.h:125 열람; 원본 커널 안에 qsort 직접 호출 0 곳(odis 전 범위 grep), 07 에 qsort 선언·호출 없음 | ⚖️ 사실, i386 에서는 같은 바이트 — 원본이 쓴 형은 바이트로 못 정함; 원형 선언이 생기면 그때 맞춤 |
| 보탬: 2.11BSD 에 남은 Berkeley qsort.c(Regents 고지)와 매우 비슷하다는 외부 자료 | 외부 URL 은 열지 않음(01_resources 밖) | ⚠️ 미확인 — 계보는 계획 4 와 같은 뜻으로 기록; BSD 고지를 붙일지는 사용자 판단(D013) |

### 270.1 결과 — A
- 07 새 파일 `bsd/kern/qsort.c`(원본 바이트로 작성, plan 270) it1(`s5p260-it1`) OBJECT_MATCH(742 B + 채움 2 B, `__data` 16 B L1d), relcheck 0. 기록: objects_confirmed +1, functions +1, PROVENANCE +1(kind authored), MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-qsort.md`·`.diff`. BSD 고지 여부는 사용자 판단 사항으로 남김.

## 271. S5-P261 세부 계획 — `bsd/ufs/ufs_byte_order.c`(참조 원문 없음, 원본 바이트로 작성 D024; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name ufs_byte_order.c`): Darwin 0.1 bsd/ufs/ufs/ufs_byte_order.c(4.4BSD 구조체용 뒤 판 — sbin/sbout·cgin/cgout 등 함수 구성이 다름, 구조만 참고 D027), Mach4·NeXTMach 에는 정의 없음(07 의 ufs 파일들이 byte_swap_superblock·byte_swap_cylgroup 등을 부름 — 계획 214–216 에서 바이트로 넣은 호출; codex 검토로 정정: NeXTMach ufs 에는 호출 없음). 구조체 배치는 OPENSTEP 4.2 SDK 헤더(bsd/ufs/fs.h·inode.h·fsdir.h, bsd/dev/disk_label.h, bsd/sys/disktab.h, architecture/i386/byte_order.h). 근거 `08_build/runs/tools/s5p261-byteorder.dis`, 초안 `08_build/runs/tools/s5p261-ufs_byte_order-draft.c`, 스크래치 `s5p261-w1`–`w3`·`v1`–`v8`(07 미변경; 스크래치 스테이지에만 SDK disk_label.h·disktab.h 를 덮어씀).

0. 객체 [0x192c20, 0x19335c) 1852 B(명령 1849 B, dir_block_in ret 0x193358 뒤 `00 00 00`): byte_swap_ints, _shorts, _superblock, _disklabel_in, _disklabel_out, 기호 없는 정적 함수 0x192e28(184 B, disktab_in·_out 이 부름), _disktab_in, _disktab_out, _partition, _csum, _cylgroup, _inode_in, _inode_out, _dir_block_out, _dir_block_in; 앞 _i386_backtrace(trap 쪽) 뒤, 다음 allocbuf(ufs_machdep).
1. 바이트가 보이는 내용(디스크는 빅엔디언, NXSwapLong = bswap, NXSwapShort = ror 8):
   a. ints·shorts: 인덱스 루프. superblock·cylgroup 은 이 둘을 인라인해서 씀(fs_sblkno 부터 50 개 int, fs_cgrotor, fs_cpc, fs_postbl 256 short, fs_magic; cg_time … cg_magic).
   b. disklabel_in: 디스크의 압축된 꼬리(dl_un + dl_checksum, 6682 B)를 2×(NPART+1) = 18 B 위로 옮김(뒤에서부터, 0x192ce8–0x192cff), 머리 int 5 개·dl_checksum, disktab_in, dl_version > DL_V2 면 dl_v3_checksum 아니면 dl_bad[NBAD=1670]. disklabel_out 은 거꾸로(부호 없는 앞쪽부터 옮김).
   c. 정적 함수(디스크탭 머리 int 5·short 6·d_boot0_blkno 2, 파티션 8 개 byte_swap_partition, 부호 없는 루프)는 원본처럼 인라인되지 않고 제자리에 놓이려면 SDK 의 NXSwapBig*ToHost 감쌈을 써야 함(v3; NXSwapLong 를 바로 쓰면 -g -O3 에서 인라인됨, w3·v1·v2).
   d. disktab_in/out: 파티션을 임시 구조체를 거쳐 2×(i+1) B 씩 옮김(in 은 뒤에서부터, out 은 앞에서부터).
   e. csum: do-while, 부호 있는 정수 비교(jl, 0x192fef). inode_in/out: icommon 포인터, IC_FASTLINK 가 아니면 db[12]·ib[3], 맞으면 bcopy 60 B, ic_spare 루프는 부호 없는 비교. dir_block_out(bp)·dir_block_in(addr, count): 항목마다 d_ino·d_reclen·d_namlen, reclen < 12 면 멈춤.
2. 데이터 없음. 스크래치 진단 `v8` OBJECT_MATCH(`__text` 1849 B, 15 함수 MATCH), relcheck 0.
3. 07 에 넣을 때 SDK bsd/dev/disk_label.h·bsd/sys/disktab.h 는 stage_headers(--nextdev)가 SDK 에서 읽음(D017: 사본은 gitignored nextdev). 다른 07 파일의 호출(원형 없는 K&R 호출)은 바뀌지 않음 — 이 파일은 헤더를 내보내지 않음.

방법: 07 새 파일 `bsd/ufs/ufs_byte_order.c` = 초안(plan 271, D024). iter·relcheck·기록(A 예상, PROVENANCE kind authored).

## 272. S5-P262 세부 계획 — `machdep/i386/sys_machdep.c`(NeXTMach next/sys_machdep.c + resuba; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name sys_machdep.c`): NeXTMach mk-108.1 next/sys_machdep.c(바탕 — TRACE 가 꺼져 있으면 함수 없음, m68k 판), Darwin 0.1 machdep/i386/sys_machdep.c(참고만 — i386 판에 빈 resuba() 가 있음), Mach4 에는 같은 이름 파일 없음. 근거 원본 바이트, 초안 차이 `08_build/runs/tools/s5p262-sys_machdep-nextmach-vs-draft.diff`, 스크래치 `s5p262-w1`(07 미변경).

0. 객체 [0x191e48, 0x191e50) 8 B(명령 7 B `55 89 e5 89 ec 5d c3` + `00`): _resuba 하나; 앞 initrootnet(swapgeneric, 보류) ret 0x191e47, 다음 _user_trap(trap.c). 데이터 없음.
1. 차이: (a) `#import <nextdev/busvar.h>` 지움(m68k 버스 헤더, i386 SDK·07 에 없음; 이 파일에서 쓰는 이름 없음), (b) 빈 `resuba()` 를 TRACE 블록 앞에 더함(원본 0x191e48, D024 — Darwin i386 판에도 같은 빈 함수가 있음, D027). TRACE 블록은 NeXTMach 그대로(꺼짐).
2. 스크래치 진단 `w1` OBJECT_MATCH(`__text` 7 B).

방법: 07 새 파일 `machdep/i386/sys_machdep.c` = NeXTMach 원문(고지 유지) + 위 수정(plan 272 표시). iter·relcheck·기록(A 예상).

272 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 범위·바이트(`55 89 e5 89 ec 5d c3 00`), 앞 initrootnet ret 0x191e47, 다음 user_trap 0x191e50 | 앞서 낸 python 바이트 출력·symbols.tsv 3 행 | ✅ |
| busvar.h 를 지워도 쓰는 이름 없음, TRACE 가 꺼지면 함수는 resuba 뿐 | NeXTMach sys_machdep.c 열람(TRACE 밖은 포함문뿐); w1 기호 `_resuba` 하나 | ✅ |
| **보탬**: 헤더가 만드는 common 기호(_bufhash·_bfreelist·_file_list 등 11 개)가 있음 — "데이터 없음"은 할당된 데이터 구역이 없다는 뜻으로 적을 것 | w1 python 파싱: 구역은 `__text` 7 B 뿐, common 11 개 | ✅ 기록(다른 객체와 같은 D021 헤더 잠정 정의, 링크 때 합쳐짐) |
| resuba 가 swapgeneric 이나 trap 에 속할 가능성은 바이트로 배제 못 함; Darwin i386 sys_machdep.c:74 의 빈 resuba 와 NeXTMach swapgeneric.c 에 resuba 없음이 근거 | Darwin sys_machdep.c:74–76 열람; NeXTMach swapgeneric.c grep 0 건 | ⚖️ 사실 — 객체 경계는 추정(이 기록에 밝힘), w1 은 `__text` 일치 확인 |
| resuba 는 원본 바이트로 작성, Darwin 은 보조 근거로 기록 | — | ✅ fn_source 를 authored 로 기록 |

271 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0·1a·1b·1d·1e·2: 범위·15 함수 배치·구조체 오프셋·복사 방향·DL_V2 부호 있는 비교·루프 부호·데이터 없음·v8 일치 | 앞서 연 s5p261-byteorder.dis 전문, SDK fs.h·inode.h·disk_label.h·disktab.h 열람, python(0x2c+0x94 = 0xc0, 0x2c+0x92 = 0xbe, 0x240−0x22e = 18, 6680+2 = 6682), v8 L1 json | ✅ |
| **내 오류 1**: NeXTMach ufs 에는 byte_swap 호출이 없음 | `grep -rln byte_swap 01_resources/upstream/nextmach/` → netinet·next in_cksum.c 뿐(무관) | ✅ 본문 정정 |
| **내 오류 2**: 초안 주석 "disktab 이 2 B 앞" 은 틀림 — 파티션 배열이 2 B 앞(dl+0xbe 대 0xc0) | 위 python 계산 | ✅ 주석 고침(코드 변화 없음, v9) |
| Darwin 에도 같은 이름 함수가 여럿 있으나 배치·구현이 다름 — "정의 없음" 표현을 좁힐 것 | Darwin ufs_byte_order.c grep: ints·shorts·csum·inode_in/out 등(sbin/sbout·cgin/cgout 이름) | ✅ 초안 머리 주석 고침 |
| 1c: 감쌈 함수가 인라인을 막는다는 설명은 인과가 증명되지 않음 | 변형 w3(NXSwapLong: 인라인)·v3(NXSwapBig*ToHost: 제자리) 비교뿐 | ⚖️ 사실 — 관찰("이 꼴에서 원본처럼 남음")로만 적음 |
| byte_swap_ints 호출(ufs_vfsops.c:416·715)은 char * 를 넘김 — ABI 는 같으나 형은 다름 | ufs_vfsops.c:416 열람(space 는 caddr_t) | ⚖️ 사실, 원형 없는 호출이라 바이트 같음 |
| dir 함수의 reclen < 12 는 버퍼 끝 검사 아님 | 바이트 그대로 | ✅ 기록(행동은 원본 그대로) |

### 271.1 결과 — A
- 07 새 파일 `bsd/ufs/ufs_byte_order.c`(원본 바이트로 작성, plan 271, 주석 정정본 v9) it1(`s5p261-it1`) OBJECT_MATCH(1849 B + 채움 3 B), relcheck 0. 기록: objects_confirmed +1, functions +15, PROVENANCE +1(kind authored) + SDK 헤더 채택 2(bsd/dev/disk_label.h·bsd/sys/disktab.h, gitignored nextdev, D017), MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-ufs_byte_order.md`·`.diff`.

### 272.1 결과 — A
- 07 새 파일 `machdep/i386/sys_machdep.c`(NeXTMach 원문 + plan 272) it1(`s5p262-it1`) OBJECT_MATCH(7 B + 채움 1 B), relcheck 0. 기록: objects_confirmed +1, functions +1, PROVENANCE +1 + SDK 헤더 채택 1(bsd/sys/mtio.h), MODIFICATIONS +1; 객체 경계는 추정임을 기록문에 밝힘.

## 273. S5-P263 세부 계획 — `machdep/i386/trap.c`(원본 바이트로 작성 D024, Darwin 구조·NeXTMach u 영역 관용구) 와 Darwin `machdep/i386/machdep_call.h` 채택(코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name trap.c`): Darwin 0.1 machdep/i386/trap.c(구조 — kernel_trap·도우미·machdep_call·mach_kernel_trap·_i386_backtrace 는 바이트가 이 꼴을 요구, D027), NeXTMach mk-108.1 next/trap.c(m68k, 기준 — u.u_error 저장, u_prof/addupc, uu_qsave/uu_eosys 시스템 호출 반환, CS_RPAUSE fspause), Mach4 i386/kernel/i386/trap.c(다른 설계, 미사용). Darwin 원문 그대로는 4.4BSD p_stats·P_PROFIL·ERESTART 로 컴파일 안 됨(`s5p263-d3`). 근거 `08_build/runs/tools/s5p263-trap.dis`(skipdata 판 — 표가 코드 안에 있음), 초안 `08_build/runs/tools/s5p263-trap-draft.c`, Darwin 과의 차이 `s5p263-trap-darwin-vs-draft.diff`, 스크래치 `s5p263-w1`·`w2`(07 미변경; 스크래치 스테이지에만 Darwin machdep_call.h 를 덮어씀).

0. 객체 [0x191e50, 0x192c20) 3536 B(명령 3535 B + `00`): user_trap, kernel_trap, 기호 없는 정적 kernel_pagefault(0x1923e0)·kernel_debug_trap(0x192438)·kernel_try_recover(0x1924a0)·kernel_recover_thread(0x1924e0), machdep_call, mach_kernel_trap, unix_syscall, unix_syscall_return, check_for_ast, _i386_backtrace; switch 표 3 개가 `__text` 안에(0x191ea8 18 칸·0x192124 16 칸·0x1922d8 18 칸). 앞 resuba(plan 272), 다음 byte_swap_ints(plan 271).
1. 바이트가 보이는 NeXT 쪽(Darwin 과 다름): user_trap 은 u.u_procp 가 있으면 u.u_ru.ru_stime 를 잡고, 페이지 오류 때 u.u_error 를 저장·0·복원(0x191fc1–0x192011), 끝에 u.u_prof.pr_scale 이면 ticks 를 계산해 addupc(eip, &u.u_prof, ticks)(0x192065–0x1920db). kernel_trap 의 페이지 오류도 current_thread() 가 있으면 u.u_error 저장·복원(0x19218a–0x192200), GDB 경로는 DoAlert("Kernel Trap", "")·printf·_i386_backtrace·kdp_raise_exception·DoRestore·panic. unix_syscall 은 u 영역 꼴: u.u_error = 0, sysent 선택·fuword, copyin 실패 때 eax·CF, uu_r.r_val1 = 0·r_val2 = edx, setjmp(&uthread->uu_qsave)(원본 _setjmp = _set_label 같은 주소 0x186f88; setjmp 로 써야 GCC 가 지역 변수를 모두 스택에 둠 — w1 은 set_label 이라 312 B, w2 는 428 B 일치), 아니면 uu_eosys = NORMALRETURN·uu_rpswhich = 0·uu_rpsfs = 0·(*sy_call)()·error = uu_error, 끝에 unix_syscall_return(error). unix_syscall_return(error): USER_REGS, ENOSPC 면 fspause(0) 이 참이면 u.u_eosys = RESTARTSYS·error = uu_error, NORMALRETURN 이면 eax/edx/CF, RESTARTSYS 면 eip −= 7, uu_error = error, thread_exception_return. check_for_ast: u.u_procp, SOWEUPC·u_prof 면 addupc(eip, &u.u_prof, 1), CHECK_SIGNALS 면 p_cursig 또는 issig(0) 이면 psig, csw_needed 면 u.u_ru.ru_nivcsw++·thread_block_with_continuation(thread_exception_return), AST_FP_EXTEN 이면 fp_ast.
2. 데이터 [0x1e280c, 0x1e289a) 142 B: "" · "Kernel Trap" · "unexpected kernel trap %x eip %x\n" · "continued after kernel trap" · "frame %x called by %x " · "args %x %x %x %x\n" · "invalid frame pointer %x\n"(원본 1 곳), 뒤 `00` 채움, 다음 _nbuf(0x1e289c) — 스크래치 L1d 일치.
3. `__TEXT,__const` 4 B(`18 00 20 00`)는 cpu_inline.h 의 쓰지 않는 ltr()/lldt() 인라인이 내는 참조 없는 상수 — PCresume·fp_support(P) 와 같은 꼴; 원본 `__const` 에 같은 4 B 가 9 곳이라 자리를 정할 수 없음 → 등급 P(나머지 일치).
4. 스크래치 `w2`: `__text` 3535 B 0 차이(12 함수 MATCH, 참조 176 개 0 차이), `__data` 142 B L1d 일치, `__const` 만 배치 못 함. relcheck 0.
5. 헤더: Darwin machdep/i386/machdep_call.h(machdep_call_t, machdep_call_table, machdep_call_count)를 07 에 그대로 채택(APSL, PROVENANCE 행) — 07 의 다른 Darwin machdep 헤더(trap.h·err_inline.h 등)와 같은 방식. 07 의 다른 .c 가 이 헤더를 쓰지 않으므로 다른 객체에 영향 없음.

방법: 07 새 파일 `machdep/i386/trap.c` = 초안(plan 273, D024·D027), `machdep/i386/machdep_call.h` = Darwin 그대로. iter·relcheck·기록(P 예상, record_partial 의 const_note).

## 274. S5-P264 세부 계획 — `machdep/i386/pcb.c`(D024·D027: 바이트가 요구하는 문장 = Darwin 0.1 pcb.c 의 문장; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name pcb.c`): Darwin 0.1 machdep/i386/pcb.c(문장이 원본과 같음), Mach4 i386/kernel/i386/pcb.c(다른 설계, 미사용), NeXTMach mk-108.1 next/pcb.c(m68k, 미사용). D022 에 따라 machdep 는 Darwin 구조만 참고 — 그러나 이 객체는 D027(in_cksum 선례)과 같은 경우: 원본 바이트대로 쓰면 Darwin 문장과 같아짐. 진단 `s5p264-d2`(Darwin 원문 그대로, 스크래치) OBJECT_MATCH, 초안 `s5p264-w1`(Darwin 문장에서 주석만 뺀 것; python 으로 주석·공백 말고 코드가 같음을 확인) OBJECT_MATCH. 근거 `08_build/runs/tools/s5p264-pcb.dis`, 초안 `s5p264-pcb-draft.c`, 차이 `s5p264-pcb-darwin-vs-draft.diff`.

0. 객체 [0x18d208, 0x18ec70) 6760 B(명령 6757 B + `00 00 00`): stack_attach … pcb_common_terminate 34 개 기호 + 기호 없는 정적 2 개; 앞 0x18d206 ret 뒤 `00 00`, 다음 pmap_pt_entry(pmap).
1. 데이터: `__TEXT,__const` 340 B @0x1d14e8, `__DATA,__data` 4 B @0x1e2478 — 스크래치 L1d 일치. relcheck 0.
2. 사용권·출처 표기: 이 파일의 C 문장은 Darwin 0.1(APSL 1.0, Apple 1999·NeXT 1992 저작권) 그대로 — "독자 작성"이라 하지 않고 PROVENANCE/MODIFICATIONS·파일 머리에 그대로 밝힘(D027). 사용권 판단은 사용자(D017); 보고 때 알림. plan 273 trap.c 의 Darwin 꼴 부분도 같은 표기로 고침.

방법: 07 새 파일 `machdep/i386/pcb.c` = 초안(plan 274). iter·relcheck·기록(A 예상, PROVENANCE 는 darwin01 원문 바탕 + 주석 제거로 적음).

273 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| **내 오류**: 3535 B 는 "명령"이 아니라 `__text` 크기 — 그 안에 switch 표 3 개 208 B 가 있음 | python 18×4+16×4+18×4 = 208 | ✅ 표현 정정(아래 273.1 과 기록문은 "`__text` 3535 B, 그중 표 208 B") |
| 표 3 개 풀이·12 함수·u 영역 오프셋·데이터 142 B·뒤 `00 00` 뒤 _nbuf | 앞서 python 으로 푼 표(같은 값), 앞서 연 dis 전문, w2 L1 json | ✅ |
| setjmp: _setjmp·_set_label 같은 주소는 사실, 다만 "지역 변수를 모두 스택에" 는 관찰 이상으로 일반화한 것 | symbols.tsv 2736 행(_set_label)·2754 행(_setjmp) 0x186f88; w1 312 B → w2 428 B 일치 | ⚖️ 표현을 "이 컴파일러에서 setjmp 로 써야 원본과 같은 코드가 나옴(관찰)" 으로 좁힘 |
| `__const` 4 B 는 원본 9 곳, 자리 못 정함 → P 가 맞음 | 앞서 python 으로 찾은 9 곳과 같음 | ✅ |
| relcheck 0 결과가 보존되지 않음 | w2 relcheck 실행 출력 "mismatches: 0"(앞서 이 세션) | ⚖️ it1 에서 다시 돌려 기록문에 남김 |
| machdep_call.h 는 Darwin 과 바이트 같음, 07 의 다른 .c 가 포함하지 않음(gdt.c 는 기호만 참조) | grep(앞서) | ✅ |
| **누락 1**: 빈 EAGAIN·ENOMEM·ENFILE case 는 코드가 없어 바이트로 확인 못 함 | — | ✅ "NeXTMach next/trap.c 에서 온 것, 코드 없음" 주석 붙임 |
| **누락 2**: 초안 머리 "structure only" 와 Darwin 고지 삭제가 실제 남은 Darwin 글 양과 맞지 않음 | 차이 파일 | ✅ Darwin 의 APSL·NeXT 저작권 고지를 그대로 앞에 붙이고, Darwin 꼴 부분은 Darwin 문장 그대로임을 머리에 밝힘(pcb.c 초안도 같게) |

### 273.1 결과 — P
- 07 새 파일 `machdep/i386/trap.c`(plan 273, Darwin APSL·NeXT 고지 유지, Darwin 꼴 부분은 Darwin 문장 그대로임을 머리에 밝힘) it1(`s5p263-it1`): `__text` 3535 B(그중 표 208 B) 0 차이·12 함수 MATCH, `__data` 142 B L1d, `__TEXT,__const` 4 B 만 배치 못 함 → P. relcheck 0. 07 `machdep/i386/machdep_call.h` = Darwin 그대로(PROVENANCE +1). 기록: objects_partial +1, functions +12, PROVENANCE +1(trap.c), MODIFICATIONS +1; 근거 `06_reconstruction/evidence/x86-trap.md`·`.diff`.

274 codex 검토 판정(07 반영 전):

| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| **내 오류**: 앞 객체 ret 은 0x18d205(0x18d206–07 이 채움) | python 바이트 `5d c3 00 00 55`(0x18d204–) | ✅ 정정 |
| 기호 없는 정적 2 개 = task_update_io_bmap(0x18d610)·set_thread_v86_state(0x18e510) | w1 기호 값 + 0x18d208 | ✅ |
| `__const` [0x1d14e8, 0x1d163c), `__data` "pcb\0" [0x1e2478, 0x1e247c), 다른 기록과 겹치지 않음 | python 바이트 "pcb\0"; L1 json | ✅ |
| common 3 개(pcb_zone·stack_pointers·empty_stacks) | w1 python 파싱 | ✅ 기록에 보탬 |
| 초안은 Darwin 과 토큰이 같음(4752 개) — 바이트 일치는 원본의 C 글을 증명하지 못함 | 앞서 python 비교(주석·공백 말고 같음) | ✅ |
| **출처 표기**: 이 초안은 Darwin 문장을 옮긴 것이므로 D027(바이트에서 쓴 글이 닮은 경우)이 아니라 Darwin 바탕 파일 — 쓰려면 darwin01 로 기록하고 Apple·NeXT 고지 전부 유지해야 함; D022 는 machdep 에서 Darwin 을 구조 참고로만 둠 | DECISIONS.md D022·D027 문언, in_cksum.c 선례(직접 쓴 글) | ✅ 사실 — **D022 와 충돌하므로 사용자 결정이 필요**: pcb(Darwin 그대로 일치)·pmap(대부분 Darwin 그대로 일치)·trap(Darwin 문장 일부)을 Darwin 바탕으로 둘지 정해야 함. 그때까지 pcb 는 07 에 넣지 않음 |

### 273.2 결과 고침 — P (D029 반영)
- 사용자 결정 D029(2026-10-04, "Darwin 바탕 허용")에 따라 07 `machdep/i386/trap.c` 를 Darwin 0.1 원문 바탕 + plan 273 표시 수정 15 곳으로 다시 만듦: u 영역(user_trap·kernel_trap 페이지 오류), DoAlert, 디버거 경로 조건 제거(생성 설정 GDB 0 — if_venip 이 GDB 0 으로 일치 — 인데 원본은 이 경로를 가짐), unix_syscall·unix_syscall_return·check_for_ast 는 NeXTMach 꼴. it2(`s5p263-it2`) 결과는 273.1 과 같음(`__text` 0 차이, `__data` L1d, `__const` 배치 못 함 → P), relcheck 0.
- 273.1 의 기록(authored)을 지우고 다시 기록: objects_partial −1 +1, functions −12 +12, PROVENANCE −1 +1(darwin01), MODIFICATIONS −1 +1 — 지우기 전후 행 수를 python 으로 확인(41→40→41, 2209→2197→2209, 640→639→640, 230→229→230).

### 274.1 결과 — A (D029)
- 07 새 파일 `machdep/i386/pcb.c` = Darwin 0.1 원문 그대로(고지 전부 포함, D029) it1(`s5p264-it1`) OBJECT_MATCH(6757 B + 채움 3 B, `__const` 340 B·`__data` 4 B L1d), relcheck 0. 기록: objects_confirmed +1, functions +36(정적 2 포함), PROVENANCE +1(darwin01, "none (verbatim, D029)"), MODIFICATIONS +1.

## 275. 진행 메모 — `machdep/i386/pmap.c`(D029: Darwin 0.1 바탕 + 수정; 스크래치 진단만, 2026-10-04)

- Darwin 원문 그대로(`s5p265-d2`, Darwin pmap_private.h·pmap_inline.h 를 스크래치에만 덮어씀): 원본과 다른 함수는 pmap_bootstrap(804/1096 B)·pmap_attribute(원본은 KERN_INVALID_ARGUMENT 만 돌려줌, 0x1914d0)·없는 compress_data_from_phys(0x191490)·uncompress_data_to_phys(0x1914a8) 뿐, 나머지는 일치.
- 초안(`08_build/runs/tools/s5p265-*`, 스크래치 `s5p265-w1`·변형 `va`–`vj`): attribute·compress 둘은 일치. pmap_bootstrap 은 원본 꼴(pmap_map 세 번 인라인: 물리 메모리 V==P, 64 MB VM_PROT_NONE — zone_map_sizer·buffer_map_sizer 없음, 부트 매개 블록 0x11000 의 VESA 프레임 버퍼 필드 +0x185c 가 0 이 아니면 그 영역을 매핑하고 커널 주소를 +0x1854 에 둠, 이어 pmap_enable_pg 인라인)으로 크기 1096 B 까지 맞췄으나, VBE 블록 첫머리 78 B 가 레지스터 할당으로 다름(원본은 size 를 edx 에 두고 물리 주소를 두 번 읽음; 초안은 size 를 [ebp−0x18] 에 흘림). 식 꼴·변수 위치·const·volatile·지역 포인터 등 20 여 변형이 모두 같은 78 B 또는 더 나쁨.
- 부트 매개 블록의 VESA 필드는 참조 정의가 없음(Darwin 은 ppc 판만) — 이름은 쓰임새에서 붙인 것(작성, D024).
- 다음: 남은 78 B 를 더 시험하거나, 다른 객체를 먼저 함. 07 에는 아직 넣지 않음.

## 276. S5-P266 세부 계획 — `machdep/i386/cons.c`(NeXTMach next/cons.c + POSIX 제어 터미널 작성; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명 확인, `find 01_resources/upstream -name cons.c`): NeXTMach mk-108.1 next/cons.c(바탕 — 함수 구성이 원본과 같음: cnclose 없음), Darwin 0.1 bsd/dev/i386/cons.c(4.4BSD 인자, cnclose·kprintf 있음, 미사용)·bsd/dev/ppc/cons.c(미사용), Mach4 kernel/device/cons.c(다른 설계). 07 위치는 NeXTMach `next/` 파일 선례(ufs_machdep.c·dkbad.c·sys_machdep.c·다음 객체 mem.c 가 `machdep/i386/`)를 따름 — Darwin 파일 배치는 근거 아님. 근거 `08_build/runs/tools/s5p266-cons.dis`, 차이 `s5p266-cons-nextmach-vs-draft.diff`, 스크래치 `s5p266-w1`(NeXTMach 그대로: next/cons.h 없음으로 실패)·`w2`(07 미변경).

0. 객체 [0x1948f8, 0x194bf4) 764 B(명령 762 B + `00 00`): cnopen(400 B), cnread, cnwrite, cnioctl, cnselect, cngetc, cnputc; 앞 autoconf_i386 쪽, 다음 mmread(mem.c). 원본 데이터 참조는 cdevsw(+0, +8, +0xc — conf.c 소유)·active_u(0x1e8758, 6 회)·cons_tp(0x1e98bc, 16 회)뿐이라 이 객체가 정의하는 `__data` 는 없다고 추정(바이트 사실 아님; 스크래치 산출물도 `__text` 만).
1. NeXTMach 판과의 차이(바이트 근거, plan 276 표시 6 곳):
   a. `#import <next/cons.h>`(m68k, cons·cons_tp 잠정 정의) 대신 `extern struct tty cons, *cons_tp;`(07 tty.c plan 245 와 같음).
   b. cnopen: POSIX 제어 터미널 — ttynty(cons_tp)·get_posix_proc, p_posix 면 세션 지도자·s_ttyp 0·t_session 0·!p_posix_noctty 일 때 u_ttyp/u_ttyd·t_session·s_ttyp·t_posix_pgrp·t_pgrp = p_pgid·SCTTY(0x194937–0x1949c1); 아니면 SCTTY 가 없을 때 u_ttyp/u_ttyd·t_session·s_ttyp, t_pgrp 가 0 이면 enterpgrp(pp, p_pid, 0)(ttyopen 은 1 — 원본 0x194a21 `push 0`)·t_posix_pgrp·t_pgrp, 아니면 p_pgrp ≠ t_pgrp 일 때 enterpgrp(pp, t_pgrp, 0); SCTTY 는 설정 안 함(0x1949d0–0x194a58). ttyopen(tty.c plan 245) 꼴을 따름.
   c. cnioctl TIOCNOTTY: get_posix_proc, cons_tp = &cons, 세션 지도자면 s_ttyp·s_ttyd = 0, SCTTY 지움(0x194af0–0x194b3a) — syioctl(tty_tty.c plan 156) 꼴.
2. 스크래치 `w2` OBJECT_MATCH(`__text` 762 B, 7 함수 MATCH), relcheck 0.

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0: 7 함수 시작·순서, 764 B, cnopen 400 B, 이웃 autoconf_i386.m·mem.c 일치 | `symbols.tsv:723-728`, `objects.tsv:273`, python `0x194bf4-0x1948f8=764`, `0x194a88-0x1948f8=400` | ✅ |
| 0: "`__data` 없음"은 디스어셈블만으로는 성립 안 함 | dis 의 `[0x1e…]` 참조 전수(active_u 6, cons_tp 16)와 cdevsw 색인 참조(dis:108,130,150) 확인 | ⚖️ 문구를 추정으로 고침 |
| 1b: enterpgrp 셋째 인자 0 이 0x194a21·0x194a4e, SCTTY 는 POSIX 경로 0x1949c1 에서만 설정 | dis:78,93(`push 0`), `0x40000000` 전수 1 건(dis:54) | ✅ |
| 1c: TIOCNOTTY 경로 일치; syioctl 은 u_ttyp/u_ttyd 도 지움 | dis:181 `and …0xbfffffff`, `tty_tty.c:71-86` | ✅(계획은 "꼴" 비교만 — 바꿀 것 없음) |
| 3: 다른 차이 없음 | diff 훅 4 개(@@ -17,-26,-37,-80) 를 열어 a·b·c 에 대응 확인 | ✅ |
| 4: machdep/i386 배치가 선례와 일치 | `PROVENANCE.tsv:586,634` | ✅ |
| 5: Darwin ppc/cons.c 누락 | `find 01_resources/upstream -name cons.c` 4 건 | ✅ 참조 줄에 추가 |

방법: 07 새 파일 `machdep/i386/cons.c` = NeXTMach 원문(고지 유지) + 위 수정(plan 276, D014·D024). iter·relcheck·기록(A 예상).

### 결과(2026-10-04)

07 `src/machdep/i386/cons.c` 배치, `s5p266-it1` OBJECT_MATCH(762/764 B, 7 함수 MATCH), relcheck 0. 기록: objects_confirmed 197→198, functions 2209→2216, PROVENANCE 640→641, MODIFICATIONS +1 줄, 증거 `06_reconstruction/evidence/x86-cons.{md,diff}`.

## 277. S5-P267 세부 계획 — `machdep/i386/rtc.c`(Mach4 i386at/rtc.c 바탕 + 원본 바이트 수정; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명, `find 01_resources/upstream -name rtc.c`): Mach4 i386/kernel/i386at/rtc.c(바탕, rtc.h 함께), Darwin 0.1 bsd/dev/i386/rtc.c(코드 참고 — splusclock·writetodc(tp)·j%100 이 같음; 세기 레지스터는 없음), NeXTMach 없음. 07 위치는 Mach4 i386 기계 의존 파일이므로 `machdep/i386/`(rtc.h 도 같은 곳, Mach4 원문 그대로). 근거 `08_build/runs/tools/s5p267-rtc.dis`, 차이 `s5p267-rtc-mach4-vs-draft.diff`, 스크래치 `s5p267-w1`(machine/ 경로 없음)·`w2`(이 트리 kern/time_out.h 는 Mach 형 필요)·`w3`.

0. 객체 [0x194e44, 0x19554c) 1800 B, 함수 8 개(rtcinit, rtcget, rtcput, yeartoday, hexdectodec, dectohexdec, readtodc, writetodc); 앞 kdasm 객체(0x194dfc–; 가장 가까운 앞 기호 kd_slmscd 0x194e28), 다음 ev.c(_defaultEventSources). `__data` 0x1e36a8 부터 52 B(first_rtcopen_ever = 1, month[12]; 앞 기호 nchrdev 0x1e369c 는 conf 쪽). 원본의 직접 호출(python E8 검색): writetodc 1 회(0x187c1c), readtodc 2 회(0x1877ec·0x187a6b), rtcput 직접 호출 없음(writetodc 안에 인라인).
1. Mach4 판과의 차이(바이트 근거, plan 277 표시):
   a. (빌드용 수정 — 바이트 근거 아님) 머리: `i386/machspl.h`·`i386at/rtc.h` → `machdep/i386/machspl.h`·`machdep/i386/rtc.h`; `kern/time_out.h` 빼기(쓰는 이름 없음).
   b. rtcput(regs, century): save_rtc 뒤 `outb(RTC_ADDR, 0x32); outb(RTC_DATA, century)`(0x194fa1–0x194fb0, century 는 int — `mov edx,[ebp+0xc]`).
   c. splclock/spl5 → splusclock 3 곳(0x19503b, 0x195245, 0x195472).
   d. readtodc: 시간대 보정 없음(MACH_KERNEL 아닌 가지의 tz 코드 없음).
   e. writetodc(tp) time_t *tp: `*tp` 두 번 읽음(0x1952e0·0x195364, 부호 있는 idiv), diff = 0.
   f. 연도: rtc_yr = dectohexdec(j % 100), century = dectohexdec(j / 100)(0x1953b5 idiv 100, 0x1953fb movsx → int), rtcput(&rtclk, century)(인라인, 0x195509–0x195518).
2. 스크래치 `w3`: 8 함수 MATCH(`__text` 1800 B), `__data` 52 B L1d 차이 0, relcheck 0. `__bss` 14 B(쓰이지 않는 static rtc[RTC_NREG], Mach4·Darwin 둘 다 있음)는 원본에서 위치는 물론 있는지도 바이트로 정할 수 없음 → 배치 불가로 두고 P 등급 예상(trap.c 와 같은 처리). 쓰이지 않는 `extern struct timeval time;`·`extern struct timezone tz;` 선언은 Mach4 원문대로 둠(코드 영향 없음).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0: 범위 1800 B·8 함수·`__data` 52 B 맞음; 가장 가까운 앞 기호는 kd_slmscd 0x194e28 | python `0x19554c-0x194e44=1800`, symbols.tsv `_kd_slmscd 0x194e28`, w3 L1d 0 | ⚖️ 사실 맞음 — "앞" 표현을 객체·기호로 나눠 고침 |
| 1a 는 빌드 수정이지 바이트 근거 아님 | diff 확인 | ✅ 문구 보강 |
| 1b century 쓰기·int 형 | dis:117 이하(0x194f84 루프 뒤 0x194fa1 `push 0x32`, 0x194faa `mov edx,[ebp+0xc]`) | ✅ |
| 1c splusclock 3 곳 | dis:201·392·595 | ✅ |
| 1d tz 없음; 초안에 쓰이지 않는 tz 선언 남음 | dis:366 이하 `*tp` 저장까지 tz 참조 없음; draft:106 | ✅ 선언은 그대로 둔다고 명시 |
| 1e `*tp` 두 번·idiv | dis:443·497 | ✅ |
| 1f 100 나눗셈·century int·인라인 rtcput | dis:526·644 | ✅ |
| 그 밖의 차이 없음, rtcget 유효성 검사 우선순위 버그 보존(dis:40 이후 분기 없음) | dis:40–48 확인; w3 MATCH | ✅ |
| 4: bss 는 위치뿐 아니라 존재도 미확정 | draft:55 `static unsigned char rtc[RTC_NREG];` 미참조 | ✅ 문구 고침 |
| 5: "다른 호출 없음" → "직접 호출 없음" | python E8 검색 출력 | ✅ 문구 고침 |

방법: 07 새 파일 `machdep/i386/rtc.c` = Mach4 원문(고지 유지) + 위 수정(plan 277, D014·D024), `machdep/i386/rtc.h` = Mach4 원문 그대로. iter·relcheck·record_partial(bss 메모).

### 결과(2026-10-04)

07 `src/machdep/i386/rtc.c`(초안 그대로)·`rtc.h`(Mach4 원문, SHA-256 일치) 배치, `s5p267-it1`: 8 함수 MATCH, `__text`·`__data` 차이 0, relcheck 0; `__bss` 14 B 는 zerofill_check 참조 0 건(`09_validation/reconstruction/s5p267-zerofill-check-rtc-20261002.json`, conclusion fail) → **P**. record_partial.py 에 `bss_unreferenced`(참조 0 건일 때만 허용, bios.c 선례) 추가. 기록: objects_partial 41→42 줄, functions 2216→2224, PROVENANCE 641→643(rtc.c·rtc.h), MODIFICATIONS +1 줄, 증거 `06_reconstruction/evidence/x86-rtc.{md,diff}`.

## 278. S5-P268 세부 계획 — `machdep/i386/kdasm.s`(Mach4 i386at/kdasm.S 바탕; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): Mach4 i386/kernel/i386at/kdasm.S(바탕), Darwin 0.1 bsd/dev/i386/kdasm.s(코드 참고 — cld 두 줄이 없는 점이 원본과 같음; `machdep/i386/asm.h` 의 `##` 붙임 사용), NeXTMach 없음. 근거 `08_build/runs/tools/s5p268-kdasm.dis`·`s5p268-kdasm.hex`, 차이 `s5p268-kdasm-mach4-vs-draft.diff`, 스크래치 `s5p268-w2`(wipasm.py: 07 bios_asm.s 를 운반용으로 스테이징하고 초안을 같은 디렉터리에 넣음; 07 미변경).

0. 객체 [0x194dfc, 0x194e44) 72 B(명령 69 B, 0x194e27 `00` 1 B 정렬, 끝 0x194e41–43 `00` 3 B): kd_slmwd(0x194dfc), kd_slmscu(0x194e10), kd_slmscd(0x194e28); 앞 mem.c(확정, 끝 0x194dfc), 다음 rtcinit(plan 277). 데이터 참조 없음(객체 판단; 스크래치 산출물도 `__text` 만).
1. Mach4 판과의 차이(plan 278 표시):
   a. `#include <mach/machine/asm.h>`(07·SDK 에 없음; 들이면 `_ ## x` 붙임을 -traditional-cpp 에서, `.p2align` 을 NeXT as 에서 따로 확인해야 함 — 미시험) 대신 ENTRY 를 `.globl _x / .align 2 / _x:` 로 풀어 씀 — 함수 사이 정렬 채움 `00`(0x194e27)이 `.align 2`(채움 값 없음)와 맞음; 끝 0x194e41–43 `00 00 00` 은 객체 경계 채움.
   b. kd_slmwd·kd_slmscu 의 `cld` 삭제: 원본 0x194e06–0x194e0a `66 8b 45 10 | f3 66 ab`, 0x194e1e–0x194e20 `39 fe | f3 66 a5` 에 `fc` 없음. kd_slmscd 의 std/cld 는 그대로(0x194e38 `fd`, 0x194e3c `fc`).
2. `start`·`count`·`value`·`from`·`to` 는 Mach4 의 `#define` 을 그대로 둠 — 스크래치 `w2` 가 이 빌드 명령(cc -traditional-cpp … -c x.s)에서 .s 가 전처리됨을 보임(plan 255 bios_asm 은 전처리 없이 썼으므로 이번이 첫 확인).
3. 스크래치 `w2` OBJECT_MATCH(69/72 B, 3 함수 MATCH).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0: 범위·채움·시작 주소 맞음; 바로 앞 객체는 cons.c 가 아니라 mem.c | `objects.tsv:274`(mem.c 0x194bf4–0x194dfc), objects_confirmed `x86-mem 0x194bf4 0x194dfc A` | ✅ 내 오기 — 고침 |
| 1a: Mach4 asm.h 의 `#error` 는 `__STDC__` 가 없을 때뿐이고 이 cc 는 `-traditional` 이 아니면 `__STDC__` 정의 | toolchain specs:8 `%{!traditional: -D__STDC__}`; 명령은 `-traditional-cpp` | ✅ 이유 문구 고침(헤더 미보유·미시험으로) |
| 1a: 끝 3 B 는 ENTRY 가 아니라 경계 채움 | hex 확인 | ✅ 문구 보강 |
| 1b cld 삭제·kd_slmscd std/cld 유지 | `s5p268-kdasm.hex`(`f366ab`, `39fef366a5`, `fdf366a5fc`) | ✅ |
| 2: 전처리됨이 산출물로 보임 | w2 MATCH(정의 이름이 그대로면 어셈블 실패) | ✅ |
| 5: 그 밖 차이·누락 참조 없음 | diff, `find 01_resources -iname kdasm.s` 2 건 | ✅ |

방법: 07 새 파일 `machdep/i386/kdasm.s` = Mach4 원문(Olivetti·CMU 고지 유지) + 위 수정(plan 278, D014). iter·relcheck·기록(A 예상).

### 결과(2026-10-04)

07 `src/machdep/i386/kdasm.s` 배치, `s5p268-it1` OBJECT_MATCH(69/72 B, 3 함수 MATCH), relcheck 0 → **A**. 기록: objects_confirmed 198→199 줄, functions 2224→2227, PROVENANCE 643→644, MODIFICATIONS +1 줄, 증거 `06_reconstruction/evidence/x86-kdasm.{md,diff}`.

## 279. S5-P269 세부 계획 — `bsd/nfs/nfs_server.c`(NeXTMach nfs/nfs_server.c 바탕; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명, `find 01_resources/upstream -name nfs_server.c`): NeXTMach mk-108.1 nfs/nfs_server.c(바탕)만 있음(Mach4·Darwin 0.1 에 같은 이름 없음). 근거 `08_build/runs/tools/s5p269-nfs_server.dis`, 차이 `s5p269-nfs_server-nextmach-vs-draft.diff`, 초안 `s5p269-nfs_server_draft.c`, 스크래치 `s5p269-d1`…`d7`·`w8`(07 미변경).

0. 객체 [0x12cffc, 0x12ea98) 6812 B: 이 범위의 기호는 nfs_svc 하나, 나머지 27 함수는 기호 없음(원본 기호표에는 외부 기호 0xf 와 ObjC 표지 0x3 만 있고 지역 기호가 없음 — 이름 없음은 static 재구성과 맞지만 원 소스의 연결 속성을 증명하지는 않음). 앞 nfs_export(확정, 끝 0x12cffc), 다음 0x12ea98(nfs_subr 확정 시작). `__data` [0x1dbf60, 0x1dc2be) 862 B(rfsfreesp, rfssize, nfs_chars, nfsd_count, nfsreadmap, rfsdisptab, nfs_portmon, 문자열), 다음 기호 nrnode 0x1dc2c0. svstat 은 common.
1. 진단 d1(원문 그대로): 함수 31 개 모두 전역 기호로 나와 순서·크기가 다름(7115 B).
2. static 과 출력 순서(d2·d3): nfs_svc 밖의 함수를 static 으로 하면 인라인 가능한 함수는 파일 끝으로 미뤄짐. rfs_* 무리는 앞쪽 static 선언 목록 순서대로 나옴(d3: 목록 순서를 바꾸면 출력 순서가 따라 바뀜); 다만 보조 함수 무리는 fhtovp 가 먼저 선언됐어도 sattr_to_vattr 가 먼저 나와 "처음 선언 순서"가 일반 규칙이라고는 할 수 없음(컴파일러 내부 기제는 미확정, 순서는 빌드로 맞춤). 원본 순서에 맞는 선언 목록: fhtovp, rfs_dispatch, mbuf_to_iov, sattr_to_vattr, hostinlist, checkauth, eqaddr, rfsput, rfsget, rfs_getattr, rfs_link, rfs_lookup, rfs_mkdir, rfs_setattr, rfs_read, rfs_readlink, rfs_remove, rfs_rename, rfs_rmdir, rfs_statfs, rfs_symlink, rfs_error, rfs_null, nullfree, rfs_rddirfree, rfs_rdfree, rfs_rlfree(같은 크기 쌍은 원본 rfsdisptab(0x1dbff4, 24 B 항목) 으로 확인: remove 0x12e600, rename 0x12e6d4, link 0x12deb4, rmdir 0x12e7dc, null 0x12ea24, ROOT/WRITECACHE 칸의 error 0x12ea18 — d6→d7 에서 순서 교정). 인라인되지 않는 큰 함수(nfs_svc, rfs_write+mbuf_to_iov, rfs_create, rfs_readdir, rfs_dispatch)는 원문 순서대로 앞에 남음. eqaddr·rfsget·rfsput 은 인라인되어 따로 없음.
3. `__data` 순서: 원본은 rfsfreesp(0x1dbf60)·rfssize 가 nfs_chars 앞 → struct rfsspace·두 변수 정의를 nfs_chars 앞으로 옮김.
4. rfs_write·rfs_setattr: `ILOCK(ip); iupdat(ip, TRUE); IUNLOCK(ip);` 대신 `(void) VOP_FSYNC(vp, u.u_cred)`(원본 0x12d352–0x12d363, 0x12e2fe–0x12e30e: v_op+0x48 = vn_fsync, 인자 vp·u.u_cred; iupdat 호출 없음).
5. rfs_setattr 의 확장 블록에 iov·uio 지역 없음(원본 프레임 0x84, 0 바이트 지역 zero 가 [ebp−0x81]) → `#if !MACH` 안으로.
6. 보고 문구: 원본 `__data` 문자열(0x1dc1a8…0x1dc292)은 "nfs_server: bad proc number from %s\n" 등 6 개와 "NFS request from unprivileged port from %s\n" — 모두 `inet_ntoa(&req->rq_xprt->xp_raddr.sin_addr)` 인자(원본 `add eax, 0x14; push eax` — 이 커널 inet_ntoa 는 포인터를 받음, 07 in.c:580). weak authentication 문구는 그대로이고 인자만 주소.
7. rfs_dispatch: tmpcr·exi 도 NULL 로 초기화(원본 0x12d7f2 `[ebp−0x14]`, 0x12d800 `[ebp−0x20]` 0 저장).
8. 스크래치 `w8`(표시 주석만 더한 최종 초안) OBJECT_MATCH: `__text` 6812 B·`__data` 862 B 차이 0, 28 함수 MATCH, relcheck 0. common 은 헤더 잠정 정의(D021 헤더 묶음)로 다른 객체와 같은 꼴.

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 초안 산출물이 원본과 일치(28 함수, `__text`·`__data` 0, 재배치 0) | w8 cmpobj OBJECT_MATCH·relcheck 0 | ✅ |
| 범위·이웃(0x12ea97 ret 뒤 0x12ea98 nfs_subr) | dis 끝·objects_partial `x86-nfs_subr 0x12ea98` | ✅ |
| 기호표가 0xf 만 가진다는 말은 틀림(0x3 도 있음); 이름 없음은 static 을 증명하지 않음 | symbols.tsv type 집계(0x3 100, 0xf 3651) | ✅ 내 문구 오류 — 고침 |
| `__data` [0x1dbf60, 0x1dc2be) 내용 일치, svstat common 여부는 원본으로 확정 불가 | w8 `__data` 862 B L1 0, symbols(nrnode 0x1dc2c0) | ✅ |
| "처음 선언 순서"는 일반 규칙으로 뒷받침 안 됨(fhtovp 가 먼저 선언됐는데 sattr_to_vattr 가 먼저) | draft:98·103, w8 순서 | ✅ 내 일반화 과함 — 문구 좁힘 |
| 같은 크기 쌍의 이름은 dispatch 표로 확인됨 | python 으로 rfsdisptab 18 항목 읽음 | ✅ 근거 바꿈 |
| VOP_FSYNC(v_op+0x48)·setattr 프레임 0x84·[ebp−0x81]·7 문자열·inet_ntoa 주소·dispatch 0 저장 | dis 해당 주소, 문자열 python 으로 읽음 | ✅ |
| diff 에 2–7 밖의 변경 없음 | diff 확인 | ✅ |
| 바이트로 알 수 없는 것: 쓰이지 않는 선언, `#if !MACH` 위치, SECURE_NFS 아래 rootname 의 static | — | ⏭️ 사실로서 받아들임(PROVENANCE 에 "구성된 빌드 일치" 로만 적음) |

방법: 07 새 파일 `bsd/nfs/nfs_server.c` = NeXTMach 원문(고지 유지) + 위 수정(plan 279, D014·D024; 선언 목록은 작성). iter·relcheck·기록(A 예상).

### 결과(2026-10-04)

07 `src/bsd/nfs/nfs_server.c` 배치(초안 주석 문구만 좁힘), `s5p269-it1` OBJECT_MATCH(6812 B, 28 함수 MATCH, `__data` 차이 0), relcheck 0 → **A**. 기록: objects_confirmed 199→200 줄, functions 2227→2255(+28), PROVENANCE 644→645, MODIFICATIONS +1 줄, 증거 `06_reconstruction/evidence/x86-nfs_server.{md,diff}`.

## 280. S5-P270 세부 계획 — 확정 P 객체 `bsd/nfs/nfs_subr.c` 의 끝 보완: rlock_timeout(작성; 코딩 전 — 스크래치 진단만, 2026-10-04)

배경: plan 186(S5-P159)은 nfs_subr 범위를 다음 기호 _rlock_timeout 0x12fd1c 앞에서 끝냈고 기록은 [0x12ea98, 0x12fd1b) P. 그러나
0. 원본 0x12fd18 `ec 5d c3 | 90 | 55 89 e5` — runlock 의 ret(0x12fd1a) 뒤 채움이 **0x90**(같은 객체 안 컴파일러 정렬; 객체 사이 링커 채움은 0x00 — plan 211 kern_proc 근거)이고, 0x12fde6 `89 ec 5d c3 | 00 00 | 55 89` — 0x12fdea–eb 의 `00 00` 은 객체 뒤 링커 채움(채움이 필요 없는 경계 0x12cffc·0x12ea98 에는 채움이 없음). 따라서 rlock_timeout(0x12fd1c, 180 B)과 기호 없는 static 함수(0x12fdd0, 26 B)는 nfs_subr 객체의 끝이고, `__text` 는 [0x12ea98, 0x12fdea) 4946 B(+ `00 00`). 근거 `08_build/runs/tools/s5p270-rlock_timeout.dis`.
1. 참조: NeXTMach·Mach4·Darwin 0.1 어디에도 rlock_timeout 없음(`grep -rn rlock_timeout 01_resources/upstream` 0 건). SDK nfs/rnode.h 에 `RTIMEDOUT 0x20`(`#if NeXT`)과 RUNLOCK 의 RTIMEDOUT 해제가 있음 — 같은 기능의 흔적.
2. rlock_timeout(rp, secs)(작성, 바이트 근거): 루프 `while ((r_flags & RLOCKED) && r_thread != current_thread())`(0x12fda5–0x12fdac 회전 루프, 0x12fd2c–0x12fd34; current_thread = active_threads[0]) 안에서 RTIMEDOUT 이면 rlockretimeout++·return 1(0x12fd36–0x12fd46); 아니면 RWANT, s = splhigh(), timeout(정적 함수, rp, secs * hz), sleep(rp, PINOD=10), untimeout(정적 함수, rp) 가 0 이면 rlocktimeout++·RTIMEDOUT·splx·return 1(0x12fd81–0x12fd9a), 아니면 splx. 루프 뒤 r_thread = current_thread(), r_count++, RLOCKED, return 0(0x12fdb2–0x12fdc3).
3. 정적 함수(0x12fdd0, 이름 없음 → 재구성 이름 `rlock_awaken`; 이름과 `#if NeXT` 묶음은 바이트로 정할 수 없는 선택): rlock_awaken_count++; rp 가 있으면 wakeup(rp).
4. 세 계수기 rlock_awaken_count(0x1ef018)·rlockretimeout(0x1ef01c)·rlocktimeout(0x1ef020)는 원본 section 6(공용) 기호 → 초기값 없는 전역 선언.
5. 원본 호출처: 0x133e1d(nfs_vnodeops 쪽, `push 5; push edi`) 하나(python E8 검색).
6. 스크래치 `s5p270-w1`(07 nfs_subr.c + 위 작성 코드를 파일 끝에 `#if NeXT` 로): [0x12ea98, 0x12fdec) `__text` 4948 B 차이 0, 23 함수 중 22 MATCH + newname MATCH_UNVERIFIED(static newnum `__bss`, 이전과 같음), `__data` 차이 0.

방법: 07 `bsd/nfs/nfs_subr.c` 끝에 위 코드 추가(plan 280, D024). iter(범위 12ea98 12fdec)·relcheck·zerofill_check 재실행; 기존 기록(objects_partial 1 행, functions 21 행, PROVENANCE 1 행)은 새 실행 기준으로 바꿔 씀(지우고 다시 기록, 행 수 검증), MODIFICATIONS 에 한 줄 추가. 등급 P 유지(__bss 참조 추정).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 0x12fd1b `90`, 0x12fdea–eb `00 00` 맞음; `__text` 끝은 0x12fdea, 채움 규칙은 "채움이 필요할 때 0" 으로 한정 | python 바이트(0x12fd18 `ec5dc390 5589e557`, 0x12cff8·0x12ea94 는 ret 바로 뒤 55); w1 `__text` 4946 B | ✅ 문구 고침 |
| rlock_timeout·정적 함수 흐름·상수·인자 일치 | dis 직접 읽음, w1 차이 0 | ✅ |
| 세 계수기는 원본 section 6, 초안은 4 B common 세 개 | symbols.tsv 2627–2630, w1 기호(type 1, value 4) | ✅ |
| 호출처 0x133e1d 하나, 인자 rp·5 | python E8 검색, odis2 0x133e1a `push 5`·`push edi` | ✅ 문구 보강 |
| 정적 함수 이름·`#if NeXT` 는 바이트 근거 없음 | — | ✅ 선택임을 명시 |

### 결과(2026-10-04)

07 `src/bsd/nfs/nfs_subr.c` 끝에 작성 코드 추가(정적 함수 이름이 재구성 선택임을 주석으로 표시), `s5p270-it1`: `__text` [0x12ea98, 0x12fdea) 4946 B·`__data` 차이 0, 22 MATCH + newname MATCH_UNVERIFIED, relcheck 0. zerofill 재실행(알려진 배치에서 nfs_subr 자신을 뺀 `zerofill-known-s5p270-20261004.json` 43 건) → 0x1e59b0 참조 추정(4 참조, Delta 0x1e43c0) → **P 유지**. 기존 행을 지우고 다시 기록(백업 scratchpad `bak280/`): objects_partial 42→41→42 줄, functions 2255→2234→2257(nfs_subr 21→23 행), PROVENANCE 645→644→645, MODIFICATIONS +1 줄; 증거 `x86-nfs_subr.md` 는 새 내용 + 이전(plan 186) 기록을 인용으로 보존, `.diff` 는 NeXTMach 대비 전체로 갱신.

## 281. S5-P271 세부 계획 — `bsd/nfs/nfs_vfsops.c`(NeXTMach nfs/nfs_vfsops.c 바탕 + 원본 바이트 수정; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): NeXTMach mk-108.1 nfs/nfs_vfsops.c(바탕)만 있음. 근거 `08_build/runs/tools/s5p271-nfs_vfsops.dis`, 차이 `s5p271-nfs_vfsops-nextmach-vs-draft.diff`, 초안 `s5p271-nfs_vfsops_draft.c`, 스크래치 `s5p271-d1`(sun_nfs.h 없음)…`d10`·`w11`(07 미변경).

0. 객체 [0x12fdec, 0x1311f7) 5131 B + `00`(0x1311f7; 다음 0x1311f8 은 nfs_vnodeops 쪽, 이 구간 유일한 0 채움 — python 검색). 앞 nfs_subr(plan 280, 끝 0x12fdea + `00 00`). 기호는 nfs_badop 하나; 원본 `nfs_vfsops` 표(0x1dc560, python 으로 읽음) = mount 0x1309c4, unmount 0x130f38, root 0x130fc4, statfs 0x130fe4, sync 0x131094, badop 0x1310c4, mountroot 0x12fdec. `__data` 중 이 객체 몫 [0x1dc560, 0x1dca1a) 1210 B(`00 00` 뒤 다음 기호 nfs_cto 0x1dca1c).
1. 헤더: NeXTMach nfs/nfs_mount.h 가 `#import <sun_nfs.h>`(설정 헤더) 를 요구하는데 07 generated 에 없음 → `06_reconstruction/config_options.tsv` 에 `sun_nfs SUN_NFS sun_nfs.h 1 hypothesis`(근거: 원본 _nfs_vfsops·_nfs_svc, NeXTMach conf/files `OPTIONS/sun_nfs`) 한 행 추가 후 gen_config_headers.py 로 생성(스크래치는 import 를 뺀 nfs_mount.h 로 진단). nfs_mount.h 자체는 NeXTMach 사본이 스테이징으로 들어옴(기록 때 adopt).
2. static: nfs_badop 밖의 함수는 기호가 없어 static(표·전방 선언 포함). 표가 함수 정의보다 앞이라 함수는 원문 순서로 나오고, pmap_rmtcall·callrpc·itoa·hostpath 는 인라인되거나 쓰이지 않아 따로 없음; addr_to_str(0x1310d8)가 끝.
3. nfs_mountroot(0x12fdec–0x130341): rtc_get/inittodr 블록 없음; getfile 이 ETIMEDOUT 이면 한 번만 `printf(getfile_wait_msg, 이름)`(전역 static 포인터 0x1dc5bc → 문자열 0x1dc57c "No bootparam server responding to GETFILE \"%s\"; still trying\n" — 표 뒤 `__data`), 실패면 "RPC error during bootparam request: %d\n", 대기 문구를 냈으면 "Bootparam response received\n"; private 쪽은 같은 꼴에 EINVAL(0x16)이면 "Using /private from root mount point\n" 후 0 반환(0x13006a–0x13007e).
4. pmap_rmtcall(인라인): clntkudp_create 실패 시 panic 을 먼저(0x1304c5–0x1304d3, 0x13073e–0x13074c), resp_addr 포트 기록 없음(호출은 resp_addr 0, `push 0`) → `if (resp_addr)` 로 감쌈(인자 상수 0 이라 코드 없음; 원 소스 표현은 바이트로 정할 수 없는 재구성 선택).
5. whoami(0x130344–0x1306a4): 함수 안 static `whoami_done`(0x1dc76c, `__data`)으로 한 번만 실행; 브로드캐스트 주소를 sa 와 함께 bootparam_addr 에도 bcopy(0x130409–0x130411); pmap_rmtcall 의 resp_addr 0; "whoami: no domain name" 없음; rtentry·sin 지역은 `#if !NeXT` 로(프레임 0x8c).
6. getfile(0x1306a8–0x1308ad): tv = {5, 0}; whoami() 를 조건 없이 부름; callrpc 대신 pmap_rmtcall(&bootparam_addr, …, tv, 0) 5 회; 성공 끝에 "NFS mounting \"%s\" from  %s:%s\n"(fileid, server_name, server_path).
7. nfs_unmount(0x130f38): rflush·rinval 뒤 EBUSY 검사(NeXT 앞 검사 아님), rp_rmhash·rinactive 뒤 VN_RELE.
8. 이름 없는 static 둘의 이름(getfile_wait_msg, whoami_done)은 재구성 선택.
9. 스크래치 `w11`(표시 주석 포함): `__text` 5131 B·`__data` 1210 B 차이 0, 12 함수(7 MATCH + 5 MATCH_UNVERIFIED — `__bss`), relcheck 0. `__bss` 52 B(nfslock·nfs_minmap·bootparam_addr static) zerofill 미리보기 [0x1e59b4, 0x1e59e8) 참조 추정(8 참조, Delta 하나; `s5p271-w11-zerofill-preview.json`) → P 예상.

방법: config 행 추가·헤더 생성, 07 새 파일 `bsd/nfs/nfs_vfsops.c` = NeXTMach 원문(고지 유지) + 위 수정(plan 281, D014·D024). iter·relcheck·zerofill(알려진 배치 s5p270 목록)·record_partial.

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 표 7 항목·범위·채움 맞음; 데이터 범위는 `__data` 섹션 전체가 아니라 객체 몫 | python 표 읽기, dis 0x1311f6 ret·0x1311f7 `00`, symbols nfs_cto | ✅ 문구 고침 |
| sun_nfs 추가는 가설로 정당, 07·스테이징에 SUN_NFS 를 실제로 검사하는 곳 없음(주석뿐) | `grep -rn SUN_NFS 07_kernel/src 07_kernel/nextdev`(주석 4 건) | ✅ |
| 3·5–7 원본 지지 | dis 해당 주소(앞서 직접 읽음) | ✅ |
| 4: `if (resp_addr)` 는 그럴듯하나 바이트로 확정 불가 | — | ✅ 선택임을 명시 |
| 비활성 `!MACH` nfs_swapvp: 정의는 static, 전방 선언은 비static | draft:97·319 | ✅ 선언도 static 으로(d12) |
| zerofill 미리보기 입력 이름이 d10 이나 SHA 는 w11 과 같음 | sha256sum 두 산출물 같음 | ✅ 기록 때 07 빌드로 다시 실행 |

### 결과(2026-10-04)

- 설정: `06_reconstruction/config_options.tsv` 에 `sun_nfs SUN_NFS sun_nfs.h 1 hypothesis` 추가(52→53 줄), gen_config_headers 로 `07_kernel/generated/sun_nfs.h` 생성, `meta_features.h` 에 import 한 줄 추가됨. 기록 단계에서 채택된 실기 SDK `bsd/nfs/nfs_mount.h` 도 KERNEL_BUILD 에서 `<sun_nfs.h>` 를 들여옴 → 원 빌드에 이 설정 헤더가 있었다는 근거로 행 근거 보강. SUN_NFS 를 검사하는 소스·헤더 없음(grep); 회귀 `s5p271-rg00`…`rg07`(nfs_export, nfs_xdr, uipc_socket2, nfs_common, nfs_client, kern_synch, nfs_server = OBJECT_MATCH, nfs_subr = 기록과 같은 P) 변화 없음.
- 07 `src/bsd/nfs/nfs_vfsops.c`(d12: 비활성 nfs_swapvp 선언도 static), `s5p271-it1`·`it2`(SDK nfs_mount.h 채택 뒤, 산출물 SHA 같음): `__text` 5131 B·`__data` 차이 0, 7 MATCH + 5 MATCH_UNVERIFIED, relcheck 0; zerofill [0x1e59b4, 0x1e59e8) 참조 추정(8 참조, Delta 0x1e40ec) → **P**. 기록: objects_partial 42→43 줄, functions 2257→2269(+12), PROVENANCE 645→648(채택 헤더 bootparam.h·nfs_mount.h 2 행 + nfs_vfsops.c), MODIFICATIONS +1 줄; 알려진 배치 `zerofill-known-s5p271-20261004.json`(nfs_subr·nfs_vfsops 더해 45 건).

## 282. S5-P272 세부 계획 — `bsd/nfs/nfs_vnodeops.c`(NeXTMach nfs/nfs_vnodeops.c 바탕 + 원본 바이트 수정; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): NeXTMach mk-108.1 nfs/nfs_vnodeops.c(바탕)만 있음. 근거 `08_build/runs/tools/s5p272-nfs_vnodeops.dis`, 차이 `s5p272-nfs_vnodeops-nextmach-vs-draft.diff`, 초안 `s5p272-nfs_vnodeops_draft.c`, 스크래치 `s5p272-d1`(dbtob 인자)…`d19`·`w21`(07 미변경).

0. 객체 [0x1311f8, 0x13412c) 12084 B(앞 nfs_vfsops 끝 0x1311f7 `00`, 다음 nfs_xdr 확정 0x13412c). 기호: nfswrite, async_daemon, sync_vp, sync_vp_invalidate 넷. 원본 `nfs_vnodeops` 표(0x1dca20, python): 0–31 은 NeXTMach 표 순서(22·23·26 = nfs_badop), 24 lockctl 0x1337a0, 32 = 0x134120(devblocksize), 33·34 = 0. `__data` 몫 [0x1dca1c, 0x1dcd05) 745 B(nfs_cto 부터).
1. static: 위 넷 밖의 함수는 static(표가 정의 앞이라 원문 순서로 나옴). NeXTMach 의 `static sync_vp()` 는 전역으로.
2. 블록 크기: SDK nfs.h `NFS_BLOCKSIZE 1024 /* no more DEV_BSIZE */`, 원본 `and edi, 0xfffffc00`(0x131486, 0x13391d) → DEV_BSIZE 를 NFS_BLOCKSIZE 로(식 6 곳, 주석 제외; 일곱째 NFS_BLOCKSIZE 는 새 nfs_devblocksize 반환); SDK 의 2 인자 dbtob; `&(int)bp->b_resid` 는 `(int *)&bp->b_resid`.
3. nfs_client.c(plan 199) 형태의 인자: nfs_cache_check(vp, mtime, size, flag) — open 0(0x131239), setattr 2(0x131b9b); nfs_purge_caches(vp, flag)(close 0x1312a0); nfs_validate_caches(…, 0)(0x13158c·0x131e64·0x133ad8, 그리고 lookup 이 인라인된 create 0x132004·remove 0x1325fa); nfsgetattr(…, 0)(getattr·access).
4. nfs_open·nfs_inactive: error = 0 초기화(`xor ebx, ebx`).
5. rwvp: r_size 를 늘릴 때 vp->vm_info->vnode_size 도 r_size 까지(0x1316b7–0x1316bc; 원본은 같은 레지스터 값을 저장 → r_size 로 비교).
6. nfsread: ESTALE 이면 "NFS read error ESTALE to host %10s fh " + printfhandle(인라인) + "\n"(0x13196e–0x1319d5).
7. nfs_setattr: time 대신 getthetime(&tv)(블록 지역), 오류면 PURGE_ATTRCACHE(SDK nfs_clnt.h) — rfscall 실패·NFS 오류 두 곳(0x131bc4, 0x131be8). create·mkdir 의 크기 차이는 인라인된 setattr 로 함께 맞음.
8. do_bio: devbsize = VOP_DEVBLOCKSIZE(vp)(v_op+0x80 간접 호출) 한 번, dbtob(b_blkno, devbsize).
9. async_daemon: thread_swappable 대신 stack_privilege(current_thread()); 중단 경로에서 async_bufhead 를 먼저 떼고 iodone; 마지막 데몬 경로에서 do_bio 뒤 다음 요청을 다시 읽음(NeXTMach 는 같은 bp 반복); 쓰이지 않는 rp 없음(setjmp 때문에 스택 칸이 생김).
10. nfs_lockctl: EINVAL 판(`#if SUN_LOCK && !NeXT` — 원본 0x1337a0 은 EINVAL 본문만 보여 주고 조건 표기는 재구성 선택; SUN_LOCK 은 1 이지만 원본 12 B).
11. 새 함수: 전역 sync_vp_invalidate(vp, flag)(mfs_fsync_invalidate 뒤 RDIRTY 면 flush_vp; 0x1337f8, nfs_client.c 가 부름), static nfs_devblocksize() = NFS_BLOCKSIZE(표 32).
12. nfs_pagein(0x1338c0, 1316 B): 시작에 객체 잠금 아래 m->nfspagereq = TRUE, 모든 반환 앞에서 FALSE(vm_page 둘째 낱말 bit 11, OLD_VM_CODE; mfs_prim.c 가 검사); 자격 없음 경로에 runlock; size 는 NFS_BLOCKSIZE 정렬; nfs_validate_caches 를 두 읽기 길 앞에서 무조건; 직접 읽기에서 순차면 lbn+1 미리읽기에 더해 nfsslowlink 일 때 lbn+2·lbn+3 을 VOP_BMAP 하고 breadDirect 뒤 vnReadAhead; 오류 문구 판정은 error(bp->b_error 아님). 매크로 이름 NFS_PAGEREQ 는 재구성 선택.
13. nfs_pageout: rlock 대신 `if (rlock_timeout(rp, 5) == 1) return(PAGER_ERROR);`(0x133e1a–0x133e2a; plan 280).
14. 스크래치 `w21`(표시 주석 포함, d19 와 산출물 SHA 같음): `__text` 12084 B·`__data` 745 B 차이 0, 39 함수 37 MATCH + 2 MATCH_UNVERIFIED, relcheck 0. `__bss` 8 B(async_daemon_ready·count static) zerofill 미리보기 [0x1e59e8, 0x1e59f0) 참조 추정(8 참조, Delta 하나; `s5p272-w21-zerofill-preview.json`, 알려진 배치 s5p271) → P 예상.

방법: 07 새 파일 `bsd/nfs/nfs_vnodeops.c` = NeXTMach 원문(고지 유지) + 위 수정(plan 282, D014·D024). iter·relcheck·zerofill·record_partial.

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| DEV_BSIZE 교체는 식 6 곳(일곱째는 devblocksize 반환) | 초안 `NFS_BLOCKSIZE` 7 줄 중 1 줄이 `return (NFS_BLOCKSIZE)` | ✅ 내 셈 오류 — 고침 |
| validate 호출처 0x132004·0x1325fa 누락 | dis 1354·1842 행; NeXTMach create:1105·remove:1240 이 nfs_lookup 호출(인라인) | ✅ 보충 |
| lockctl 조건 표기는 바이트로 정할 수 없음 | 0x1337a0 `mov eax, 0x16` 만 | ✅ 선택임을 주석·계획에 명시 |
| 초안 주석 0x13335b 는 틀림, 간접 호출은 0x1332f9 | dis 0x1332f3 `mov eax,[eax+0x80]`, 0x1332f9 `call eax` | ✅ 내 오기 — 고침 |
| 범위·표 0–34·데이터 몫(경계는 추정)·마스크·인자·ESTALE·getthetime·PURGE·데몬·read-ahead·pageout·nfspagereq bit 11 일치 | 앞서 직접 읽은 dis 와 같음, w21 차이 0 | ✅ |

### 결과(2026-10-04)

07 `src/bsd/nfs/nfs_vnodeops.c`(d20: 주석 주소·lockctl 주석 고침), `s5p272-it1`: `__text` 12084 B·`__data` 745 B 차이 0, 37 MATCH + 2 MATCH_UNVERIFIED, relcheck 0; zerofill [0x1e59e8, 0x1e59f0) 참조 추정(8 참조, Delta 0x1e27c8) → **P**. 기록: objects_partial 43→44 줄, functions 2269→2308(+39), PROVENANCE 648→649, MODIFICATIONS +1 줄; 알려진 배치 `zerofill-known-s5p272-20261004.json`(46 건). 이로써 NFS 구간 [0x12cffc, 0x13412c) 의 nfs_server·nfs_subr·nfs_vfsops·nfs_vnodeops 가 모두 기록됨.

## 283. S5-P273 세부 계획 — `machdep/i386/ev.c`(이벤트 드라이버 기계 의존부, 원본 바이트에서 작성 D024·D027; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명, `find 01_resources/upstream -name ev.c`): NeXTMach mk-108.1 nextdev/ev.c(같은 이벤트 드라이버 영역의 m68k 본체 — 공유 메모리는 evopen/evmmap 경로이고 이 세 함수의 대응 함수 없음, 미사용), Darwin 0.1 bsd/dev/ev.c(구조 참고 — 같은 세 함수), Mach4 없음. 07 위치는 기계 의존 파일이라 `machdep/i386/`(cons.c 와 같은 판단; Darwin 배치는 근거 아님). 근거 `08_build/runs/tools/s5p273-ev.dis`, 초안 `s5p273-ev_draft.c`, Darwin 대비 차이 `s5p273-ev-darwin-vs-draft.diff`, 스크래치 `s5p273-w1`·`w2`(헤더 스테이징 실패)·`w3`(COMPANION 으로 kern_port.h·vm_kern.h·driverkit 헤더 스테이징; 07 미변경).

0. 객체 [0x19554c, 0x195758) 524 B(객체 뒤 채움 없음, 함수 사이 0x1956af `90`): defaultEventSources(12 B, `__data` 0x1e36dc 의 표 주소 반환), createEventShmem(0x195558), destroyEventShmem(0x1956b0); 앞 rtc.c(plan 277) 끝, 다음 kmDevice.m 쪽. `__data` [0x1e36dc, 0x1e3795) 185 B: 표 {"EventSrcPCPointer", "EventSrcPCKeyboard", NULL} 뒤에 문자열이 Keyboard·Pointer·IOLog 문구 3 개 순서로 놓임(objects.tsv 의 data_max 0x1e3765 는 마지막으로 참조되는 문자열의 시작).
1. createEventShmem: *owner = NULL; IOGetKernPort → 실패 KERN_INVALID_ARGUMENT(4); convert_port_to_map → 실패면 port_release 후 4; port_release; round_page(size)(page_mask); kmem_alloc_wired(kernel_map, …) 실패면 vm_map_deallocate·KERN_NO_SPACE(3); *owner_addr = vm_map_min(task_map)(+0x14); vm_map_find(task_map, 0, 0, owner_addr, size, TRUE) 실패면 IOLog·3; 페이지마다 pmap_extract(kernel_pmap) 가 0 이면 IOLog·kmem_free(kernel_map, *shmem_addr, size)(반올림 전 size)·3, 아니면 pmap_enter(task_map->pmap(+0x24), …, VM_PROT_READ|VM_PROT_WRITE, TRUE); *owner = task_map; 0.
2. destroyEventShmem: owner 가 NULL 이면 4; 페이지마다 pmap_remove; vm_map_remove 결과가 0 아니면 IOLog; kmem_free; vm_map_deallocate; krtn 반환.
3. 작성 원칙: 원본 바이트에서 작성(D024), Darwin 0.1 은 구조 참고 — 결과가 Darwin 원문과 사실상 같음(D027); `//` 주석과 ANSI 원형 대신 C89 주석·K&R 정의(GCC 2.7, 산출물 같음), 고지는 이 프로젝트 작성 문구.
4. 스크래치 `w3`: OBJECT_MATCH(`__text` 524 B, 3 함수 MATCH, `__data` L1d 차이 0).

방법: 07 새 파일 `machdep/i386/ev.c`(작성). iter·relcheck·record_object(authored, A 예상).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 맞음, 단 함수 사이 0x1956af `90` 이 있음 | python 바이트 0x1956a8 `5b5e5f89ec5dc390 5589e5` | ✅ 문구 보강 |
| `__data` [0x1e36dc, 0x1e3795) 맞음, 문자열 물리 순서 Keyboard·Pointer·IOLog 3 개 | python 바이트 덤프, w3 `__data` 185 B | ✅ 문구 보강 |
| createEventShmem·destroyEventShmem 단계(4/3 반환, page_mask, +0x14, +0x24, 반올림 전/후 size, 보호 3·wired 1) 일치 | dis 직접 읽음, w3 MATCH | ✅ |
| D024/D027 작성으로 다루는 것은 D029 와 충돌, Darwin 바탕+고지로 해야 함 | DECISIONS.md:33 D029 원문: 대상은 "Mach4·NeXTMach 에 대응 판이 없는 i386 machdep 파일", "그 밖에서는 … Darwin 은 코드 참고". ev.c 의 Darwin 경로는 bsd/dev(machdep 아님) → D029 범위 밖, D027(:31) 적용; 선례 APM_i386.c(작성, D027) | ❌ 기각(근거: D029 범위 문구). 다만 초안이 Darwin 과 사실상 같다는 점과 식별자·구성이 Darwin 을 따른다는 점은 D027 대로 PROVENANCE/MODIFICATIONS 에 명시 |
| 바이트로 정할 수 없는 것: C 선언·주석 | — | ✅ 기록에 명시 |
| NeXTMach ev.c 는 "무관"이 아니라 대응 함수가 없는 것 | NeXTMach ev.c:159 evopen 등 | ✅ 문구 고침 |

### 결과(2026-10-04)

07 `src/machdep/i386/ev.c`(작성), `s5p273-it1` OBJECT_MATCH(524 B, 3 함수, `__data` L1d 0), relcheck 0 → **A**. 기록: objects_confirmed 200→201 줄, functions 2308→2311, PROVENANCE 649→650(license 칸에 Darwin 근접 명시), MODIFICATIONS +1 줄.

## 284. S5-P274 세부 계획 — `driverkit/memcpy.c`(_IOCopyMemory, 원본 바이트에서 작성 D024·D027; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명, `find 01_resources/upstream -name memcpy.c` 6 건): Darwin 0.1 driverkit-1/libDriver/i386/memcpy.c(구조 참고 — 같은 _IOCopyMemory), Darwin libDriver/ppc 판(같은 _IOCopyMemory 이나 바이트 반복 구현, 미사용)·Libc i386/ppc·kernel/machdep/{i386,ppc}/libc 판(다른 함수, 미사용), NeXTMach·Mach4 없음. 07 위치는 기존 driverkit 파일(ddm.c)과 같은 `driverkit/`. 근거 `08_build/runs/tools/s5p274-memcpy.dis`, 초안 `s5p274-memcpy_draft.c`, Darwin 대비 `s5p274-memcpy-darwin-vs-draft.diff`, 스크래치 `s5p274-w1`(COMPANION driverkit/ddm.c 로 driverkit 헤더 스테이징; 07 미변경).

0. 객체 [0x1a5618, 0x1a5711) 249 B + `00 00 00`(0x1a5711–13); 앞 generalFuncs.m 끝 0x1a5615 + 채움, 다음 0x1a5714(IODisk.m 쪽). 데이터 없음.
1. _IOCopyMemory(src, dst, copyLen, copyUnitSize): src·dst NULL·같음·길이 0 이면 반환(0x1a5621–0x1a5645); 단위 0 → 1, 2 초과 → 4; 단위 1 이면 rep movsb 후 반환; 아니면 정렬까지 바이트 복사(rep movsb — 복사 수를 copyLen 으로 제한하지 않음, 0x1a567e–0x1a5692; 길이·포인터 보정), 단위 2 면 rep movsw(길이 산술 >> 1, 0x1a569d), 아니면 rep movsd(산술 >> 2, 0x1a56af); 나머지 1–3 바이트를 switch 낙하로 복사(0x1a56c6–0x1a5705).
2. 작성 원칙: 원본 바이트에서 작성(D024), Darwin 은 구조 참고 — rep movs 를 GNU inline asm 으로(`asm`, `__inline__`, 캐스트 좌변 `UNS(p) +=` — GNU 확장, cc-744.13 빌드로 확인), 결과가 Darwin 원문과 사실상 같음(D027). D029 는 Darwin kernel/machdep 파일에 한정이라 해당 없음(plan 283 판정과 같음).
3. 스크래치 `w1`: OBJECT_MATCH(249 B, 1 함수).

방법: 07 새 파일 `driverkit/memcpy.c`(작성). iter·relcheck·record_object(authored, A 예상).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 249 B·앞뒤 `00` 채움·다음 IODisk.m 0x1a5714 | python 바이트(0x1a5710 `c3 000000 5589e5`), objects.tsv | ✅ |
| 단계 일치; 정렬 복사 수는 copyLen 으로 제한 안 함, 나눗셈은 산술 시프트 | dis 0x1a567e–0x1a5692, 0x1a569d·0x1a56af `sar` | ✅ 문구 보강 |
| GNU 확장은 cc-744.13 빌드·바이트 일치로 이 형태가 지원됨이 확인됨; D027 이 맞고 D029 는 machdep 한정 | GCC27_COMPATIBILITY.md:35, DECISIONS.md:31·33 | ✅ |
| ppc 판도 _IOCopyMemory 를 정의함("다른 함수" 아님) | ppc/memcpy.c 의 _IOCopyMemory 정의 확인 | ✅ 내 오기 — 고침 |
| 매크로 이름·asm 제약·캐스트 좌변 표기는 재구성 선택 | — | ✅ 기록에 명시 |

### 결과(2026-10-04)

07 `src/driverkit/memcpy.c`(작성), `s5p274-it1` OBJECT_MATCH(249 B), relcheck 0 → **A**. 기록: objects_confirmed 201→202 줄, functions 2311→2312, PROVENANCE 650→651, MODIFICATIONS +1 줄.

## 285. S5-P275 세부 계획 — `driverkit/label_subr.c`(checksum16·check_label, 원본 바이트에서 작성 D024·D027, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/label_subr.c(구조 참고)·label_subr.h(두 함수 선언, 사용처 IODiskPartition.m), NeXTMach·Mach4 없음. 근거 `08_build/runs/tools/s5p275-label_subr.dis`, 초안 `s5p275-label_subr_draft.c`, Darwin 대비 `s5p275-label_subr-darwin-vs-draft.diff`, 스크래치 `s5p275-w1`(헤더 스테이징 실패)·`w2`(07 미변경).

0. 객체 [0x1bda48, 0x1bdb8b) 323 B + `00`; 앞 disk_label.c 쪽(0x1bd9a4 put_disk_label …), 다음 audio_snd_reply_ret_device 0x1bdb8c. 문자열 3 개는 `__TEXT,__cstring`(0x1d8bfc "Bad disk label magic number", 0x1d8c18 "Label in wrong location", 0x1d8c30 "Label checksum error").
1. **빌드 플래그**: 원본 문자열이 `__cstring` 에 있으므로 이 객체는 `-fwritable-strings` 없이 컴파일된 것으로 강하게 추정(커널 본체 객체의 문자열은 `__data`, 예 0x1e370d; 바이트만으로 증명되지는 않음). Darwin libDriver Makefile:63·70 의 커널 플래그(`-static … -traditional-cpp`, `-fwritable-strings` 없음)와 맞음. 빌드 명령은 공통 템플릿에서 `-fwritable-strings` 하나만 뺌(`wipbuild_nows.py`; 07 빌드용 `iter` 도 같은 변형, 기록의 빌드 칸에 명시). 그 밖의 플래그는 같음 — w2 일치. Darwin Makefile:67 은 `-O2` 지만 `-O2` 시험 `s5p275-o2` 는 checksum16 이 인라인되지 않아 247 B 로 불일치, `-O3` 만 일치.
2. checksum16(wp, n): 빅엔디언 short 합(ror ax, 8), 상·하위 16 비트 더하고 65535 넘으면 65535 뺌; check_label 안에 인라인되어 같은 고리가 한 번 더 있음(0x1bdb27–0x1bdb54).
3. check_label(raw_label, block_num): 버전(bswap) 이 DL_V1·DL_V2 면 size 7240·checksum 위치 +0x1c46, DL_V3 면 size 0x230·+0x22e, 아니면 문구 1; label_blkno ≠ block_num 이면 문구 2; blkno 칸 0, cksum 읽고 0 으로, sum = checksum16(raw, size >> 1), 다르면 문구 3; 같으면 blkno·cksum 복원 후 NULL.
4. 레이블 오프셋 상수(DISK_LABEL_DL_*·SIZEOF_*): Darwin 은 생성 헤더 driverkit/diskstruct.h(SDK·07 에 없음)에 둠 → disk_label.c(plan 286)와 함께 쓰도록 07 에 작성 헤더 `driverkit/diskstruct.h` 를 두고(값은 두 객체의 바이트로 확인, plan 286) 이 파일은 그것을 import(초안의 지역 정의는 그 헤더로 옮김; 같은 이름은 재구성 선택). DL_V1–V3 는 SDK bsd/dev/disk_label.h.
5. 스크래치 `w2`(COMPANION driverkit/ddm.c·bsd/ufs/ufs_byte_order.c 로 헤더 스테이징): OBJECT_MATCH(323 B, 2 함수, `__cstring` 문자열 내용 확인).

방법: 07 새 파일 `driverkit/label_subr.c`(작성). `-fwritable-strings` 없는 iter 변형으로 빌드·relcheck·record_object(authored, 빌드 칸에 플래그 명시, A 예상).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·`00` 1 B·앞 put_disk_label·다음 0x1bdb8c·`__cstring` 문자열 3 개 | python 바이트 0x1bdb84 `…c3 00 5589e5`, 문자열 읽음 | ✅ |
| 스크래치 명령은 표준과 `-fwritable-strings` 하나만 다름; 문자열 `__data` 예 0x1e370d | 두 명령 낱말 diff(경로 빼고 그 플래그 하나) | ✅ |
| Makefile 은 `-O2`, 스크래치는 `-O3` — 모든 플래그가 증명된 것은 아님 | `s5p275-o2` 빌드: 247 B 불일치(checksum16 비인라인) | ✅ 사실 추가(-O3 만 일치) |
| 스크래치 323 B 는 문자열 주소 피연산자 3 곳(재배치)만 다르고 `__cstring` 73 B 같음 | cmpobj OBJECT_MATCH(문자열 내용 검사) | ✅ |
| "-fwritable-strings 없이 컴파일됨"은 강한 추론이지 바이트만의 증명이 아님 | — | ✅ 문구 좁힘 |
| Darwin label_subr.h 참조 누락 | find 결과 label_subr.h 확인 | ✅ 보충 |

## 286. S5-P276 세부 계획 — `driverkit/disk_label.c` + 작성 헤더 `driverkit/diskstruct.h`(원본 바이트에서 작성 D024·D027, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/i386/disk_label.c(구조 참고)·ppc/disk_label.c(미사용)·driverkit/diskstruct.h(생성 헤더, 같은 이름·값), Mach4 kernel/scsi/disk_label.c(다른 판 — Mach 레이블 처리, 미사용), NeXTMach 없음. 근거 `08_build/runs/tools/s5p276-disk_label.dis`, 초안 `s5p276-disk_label_draft.c`·`s5p276-diskstruct_draft.h`, Darwin 대비 `s5p276-disk_label-darwin-vs-draft.diff`·`s5p276-diskstruct-darwin-vs-draft.diff`, 스크래치 `s5p276-w1`(bsd/string.h 없음)·`w2`·`w3`(헤더 최종본), label_subr 의 헤더 사용 판 `s5p275-w3`(07 미변경).

0. 객체 [0x1bd3e8, 0x1bda47) 1631 B + `00`; 앞 snd_server 쪽(0x1bd3e7 `00`), 다음 label_subr(plan 285) 0x1bda48. 8 함수 전역(get_partition, get_disktab, get_dl_un, get_disk_label, put_partition, put_disktab, put_dl_un, put_disk_label). 문자열·데이터 없음.
1. 각 함수는 packed 빅엔디언 레이블과 SDK bsd/dev/disk_label.h 구조 사이를 칸마다 변환: 4 B 는 bswap, 2 B 는 ror 8, 1 B 는 그대로, 문자열 칸은 bcopy(길이 MAXMPTLEN 16, MAXFSTLEN 8 등); disktab 은 NBOOTS 개 boot 블록 번호와 NPART 개 partition(간격 46 B), dl_un 은 NBAD 개 낱말; get/put_disk_label 은 dl_checksum(+0x1c46)과 dl_v3_checksum(+0x22e)을 short 로.
2. 오프셋 상수 43 개(DISK_LABEL_DL_*·DISKTAB_D_*·PARTITION_P_*·SIZEOF_{DISK_LABEL_T,DL_UN_T,PARTITION_T})는 07 작성 헤더 `driverkit/diskstruct.h` 에 둠 — 값은 두 객체(disk_label·label_subr)를 이 헤더로 빌드해 원본과 같음으로 확인(SIZEOF_DL_UN_T 는 뺄셈으로만 쓰여 0x1c48·0x230 두 크기로 6680 이 정해짐; 일치가 확인하는 것은 실효 값이지 원 소스의 이름이 아님); Darwin 의 SIZEOF_DISKTAB_T(514)는 쓰이지 않아 넣지 않음(확인 불가). 이름·값은 Darwin 생성 헤더와 같음(D027).
3. 빌드: plan 285 와 같이 `-fwritable-strings` 없는 변형(이 객체는 문자열이 없어 플래그 영향 없음 — 같은 libDriver 묶음으로 같은 명령 사용). Darwin 의 `#import <bsd/string.h>`(SDK 에 없음)는 빼고 bcopy 는 암시 선언.
4. 작성 원칙(D030 로 확정): 원본 바이트에서 확인한 이 프로젝트 작성(D024·D027) — 본문은 Darwin 0.1 원문과 거의 같은 텍스트임을 파일 머리·PROVENANCE 에 명시("구조만 참고" 아님), Darwin 고지는 넣지 않음(D017); `inline` → `__inline__`, "m68k→m88k" 같은 맞지 않는 Darwin 주석은 i386 에 맞게 고침.
5. 스크래치 `w3`: disk_label OBJECT_MATCH(1631 B, 8 함수), `s5p275-w3`: 헤더를 쓰는 label_subr OBJECT_MATCH.

방법: 07 새 파일 `driverkit/diskstruct.h`·`driverkit/disk_label.c`(작성) 와 plan 285 의 `driverkit/label_subr.c`(헤더 import 판). iter_nows·relcheck·record_object(authored, 빌드 칸에 `-fwritable-strings` 없음 명시) 두 객체, 헤더는 PROVENANCE 한 행.

## 287. S5-P277 세부 계획 — `driverkit/audio_mulaw.c`(원본 바이트·데이터에서 작성 D024·D027, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/audio_mulaw.c(텍스트 거의 같음 — `#import` 이후 같음, D030)만 있음. 근거 `08_build/runs/tools/s5p277-audio_mulaw.dis`, 초안 `s5p277-audio_mulaw_draft.c`, Darwin 대비 `s5p277-audio_mulaw-darwin-vs-draft.diff`, 스크래치 `s5p277-w1`(범위 짧게 줌)·`w2`(07 미변경).

0. 객체 [0x1be9c0, 0x1beb56) 406 B + `00 00`; 앞 audio_peak.c 쪽(0x1be9be–bf `00`), 다음 strtol 0x1beb58(확정). 전역 audio_makeIMuLawTab·audio_freeIMuLawTab·audio_shortToMulaw·audio_byteToMulaw 와 끝의 정적 비교 함수(0x1beb1c, qsort 에 넘김 — 주소가 쓰여 파일 끝으로 미뤄짐). `__TEXT,__const` audio_muLaw[256](0x1d5ee4, 512 B), `__DATA,__data` 정적 iMuLaw = 0(0x1e53cc, 4 B; 0 초기화라 `__data`).
1. audio_makeIMuLawTab: iMuLaw 가 있으면 반환; IOMalloc(0x4000); 256 개 {mu, linear = audio_muLaw[i] >> 2} 와 포인터 표; qsort(포인터 표, 256, 4, 비교); i 0..16383, k −8192 부터 d1/d2 로 j 를 옮기며 iMuLaw[i] = mutab[j]->mu.
2. 나머지 셋: freeIMuLawTab(IOFree 16384), shortToMulaw(p >>= 2 후 범위 끝 처리), byteToMulaw(iMuLaw[p + 8192]).
3. 빌드: libDriver 묶음이라 `-fwritable-strings` 없는 변형(plan 285; 이 객체는 문자열 없음). 작성 원칙 D024·D027·D030 — 본문·표는 Darwin 원문과 거의 같은 텍스트임을 파일 머리·PROVENANCE 에 명시(표 값은 원본 `__const` 와 바이트 일치로 확인), Darwin 고지는 넣지 않음.
4. 스크래치 `w2`: OBJECT_MATCH(406 B, `__const` 512 B·`__data` 4 B 차이 0), relcheck 0.

방법: 07 새 파일 `driverkit/audio_mulaw.c`(작성). iter_nows·relcheck·record_object(authored, 빌드 칸 명시, A 예상).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 8 기호·앞 `00`(0x1bd3e7)·끝 ret 0x1bda46·뒤 `00` | python 바이트 0x1bd3e0 `…c3 00 5589e556`, 0x1bda40 `…c3 00 5589e553` | ✅ |
| 칸 변환·고리(NBOOTS 1, NPART 7·간격 46, NBAD 1670)·checksum 위치 일치 | dis 0x1bd535·0x1bd62e·0x1bd668 등 | ✅ |
| 헤더 43 값 모두 쓰임; SIZEOF_DL_UN_T 는 뺄셈으로만 — 실효 값만 확인, 이름은 아님 | 사용 매크로 집계(정의 43·사용 43), 0x1bdab2·0x1bdad4 | ✅ 문구 보강 |
| 본문이 Darwin 과 거의 같은데 "작성·구조만 참고"는 근거 없음 — Darwin 고지·출처 규칙을 따라야 | diff 확인(거의 같음) | ⚖️ 사실은 인정 → 사용자 결정 요청 → **D030 "D027 작성 유지"**(고지 없이 작성으로 두되 "거의 같음" 명시); 파일 머리·PROVENANCE 문구를 그에 맞게 고침(ev.c·memcpy.c 포함, 재빌드 동일) |
| 초안의 "m68k→m88k" 주석은 i386 바이트로 뒷받침 안 됨 | 초안 두 주석 | ✅ i386 에 맞게 고침 |
| bsd/string.h 빼도 안전(SDK 에 없음, `_bcopy` 재배치 유지; ansi/string.h 는 bcopy 를 memmove 로 바꿈) | w3 오류 기록 없음, 재배치 확인 | ✅ |

### 결과(2026-10-04, plan 285·286)

07 `src/driverkit/diskstruct.h`(작성 헤더)·`label_subr.c`·`disk_label.c` 배치. `-fwritable-strings` 없는 iter_nows 로 `s5p275-it1` label_subr OBJECT_MATCH(323 B, `__cstring` 문자열 내용 확인), `s5p276-it1` disk_label OBJECT_MATCH(1631 B, 8 함수), relcheck 둘 다 0 → **A** 둘. 기록: objects_confirmed 202→204 줄, functions 2312→2322, PROVENANCE 651→654(두 .c + 헤더), MODIFICATIONS +2 줄; 빌드 칸에 libDriver 플래그 명시(record_object.py 에 `build_note` 추가). D030 에 따라 파일 머리·PROVENANCE 에 "Darwin 0.1 과 거의 같은 텍스트" 명시.

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 [0x1be9c0, 0x1beb56)+`00 00`·비교 함수 0x1beb1c(0x1bea22 에서 qsort 로)·audio_muLaw 512 B·iMuLaw 0 | dis, python 바이트 | ✅ |
| 함수 넷·비교 함수 일치, 406 B 는 재배치 13 곳만 다름 | w2 OBJECT_MATCH·relcheck 0 | ✅ |
| 표 256 개가 원본 512 B 와 바이트 같음 | cmpobj `__const` 0 차이 | ✅ |
| 파일 머리 범위 0x1beb3f 는 비교 함수 안에서 끝남 → 0x1beb55 | dis 0x1beb55 마지막 명령 | ✅ 내 오기 — 고침 |
| diff·계획의 "구조 참고" 문구가 D030 이후 낡음; `#import` 이후 Darwin 과 같음 | diff 다시 만듦, 계획 참조 줄 고침 | ✅ |
| FIXME 주석·쓰이지 않는 IMULAWOFFSET/MASK 는 바이트 근거 없음 | — | ⏭️ D030(거의 같은 텍스트) 대로 둠, 기록에 명시 |

### 결과(2026-10-04)

07 `src/driverkit/audio_mulaw.c`(작성, D030 문구, 범위 고침), iter_nows `s5p277-it1` OBJECT_MATCH(406 B, 5 함수, `__const`·`__data` 0), relcheck 0 → **A**. 기록: objects_confirmed 204→205 줄, functions 2322→2327, PROVENANCE 654→655, MODIFICATIONS +1 줄.

## 288. S5-P278 세부 계획 — `driverkit/audio_peak.c`(원본 바이트에서 작성 D024·D027·D030, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/audio_peak.c(본문 거의 같음)·audio_peak.h(원형만), NeXTMach·Mach4 없음. 근거 `08_build/runs/tools/s5p278-audio_peak.dis`, 초안 `s5p278-audio_peak_draft.c`, Darwin 대비 `s5p278-audio_peak-darwin-vs-draft.diff`, 스크래치 `s5p278-w1`(지역 헤더 없음)·`w2`(07 미변경).

0. 객체 [0x1be71c, 0x1be9be) 674 B + `00 00`; 앞 audio_mix.c 쪽, 다음 audio_mulaw(plan 287) 0x1be9c0. 전역 6 함수(audio_mulaw8_peak, audio_linear16_peak, audio_linear8_peak, audio_clear_peaks, audio_max_peak, audio_add_peak). 데이터 없음; mulaw8_peak 은 audio_muLaw(`__const`, plan 287)를 읽음.
1. 머리: Darwin 의 지역 헤더 "audio_peak.h"·"audio_mulaw.h"(원형만, SDK·07 에 없음) 대신 `bsd/sys/types.h` 와 `extern const short audio_muLaw[];` — 이 파일의 함수는 ANSI 정의라 원형이 따로 필요 없음(산출물 같음).
2. 빌드: libDriver 묶음 — `-fwritable-strings` 없는 변형(plan 285; 문자열 없음).
3. 스크래치 `w2`: OBJECT_MATCH(674 B, 6 함수).

방법: 07 새 파일 `driverkit/audio_peak.c`(작성, D030 문구). iter_nows·relcheck·record_object(A 예상).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 6 기호 674 B·`00 00`·앞 audio_mix·다음 audio_makeIMuLawTab·audio_muLaw 읽기 3 곳 | symbols.tsv, dis 0x1be753·0x1be78f·0x1be7ab | ✅ |
| 머리 대체는 이 번역 단위에서 안전(char·short 는 포인터 대상이라 승격 없음, extern 은 audio_mulaw.h 와 같음) | Darwin audio_peak.h·audio_mulaw.h 원형 대조 | ✅ |
| 6 함수 일치, 차이는 audio_muLaw 재배치 3 곳뿐 | w2 OBJECT_MATCH | ✅ |
| FIXME(devIsUnary) 주석 3 개는 Darwin 에서 온 설명이지 바이트 사실 아님 | 0x1be8ac–0x1be918 에 해당 검사 없음 | ⏭️ D030(거의 같은 텍스트)대로 두고 기록에 명시 |
| PROVENANCE·MODIFICATIONS 에도 D030 문구 | — | ✅ 기록 때 반영 |

### 결과(2026-10-04)

07 `src/driverkit/audio_peak.c`(작성, D030 문구), iter_nows `s5p278-it1` OBJECT_MATCH(674 B, 6 함수), relcheck 0 → **A**. 기록: objects_confirmed 205→206 줄, functions 2327→2333, PROVENANCE 655→656, MODIFICATIONS +1 줄.

## 289. S5-P279 세부 계획 — `driverkit/audio_mix.c`(원본 바이트에서 작성 D024·D027·D030, libDriver 빌드 플래그; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/audio_mix.c(텍스트 거의 같음)·audio_mix.h(원형)·audio_types.h·bsd/dev/audioTypes.h(열거값), NeXTMach·Mach4 없음. 근거 `08_build/runs/tools/s5p279-audio_mix.dis`, 초안 `s5p279-audio_mix_draft.c`, Darwin 대비 `s5p279-audio_mix-darwin-vs-draft.diff`, 스크래치 `s5p279-w1`(limits.h)·`w2`(boolean_t)·`w3`(2156 B)·`w4`(07 미변경).

0. 객체 [0x1bdef0, 0x1be71c) 2092 B(채움 없음 — 앞 snd_reply 끝 0x1bdeef ret, 뒤 audio_peak 0x1be71c); 전역 14 함수. 문자열 4 개는 `__cstring`("Audio: unrecognized format %d in scaleSamples/resample/convMono/mix\n").
1. 머리: Darwin 지역 헤더(audioLog.h, audio_mix.h, audio_peak.h, audio_mulaw.h → audio_types.h, bsd/dev/audioTypes.h; SDK·07 에 없음) 대신 이 파일에 IOAudioDataFormat 열거(Linear16 0·Mulaw8 1·Linear8 3 은 원본 비교값으로 정해짐; Unset −1·Alaw8 2·AES 4 는 Darwin audioTypes.h 값, 바이트로 시험되지 않음), audio_mix.h 의 원형 14 개, audio_muLaw·audio_shortToMulaw(unsigned char 반환 — 원형 필요)·IOLog 선언, `mach/boolean.h`·`limits.h`(SDK ansi). `//` 주석은 C 주석으로.
2. audio_resample22To44: 원본(0x1be268, 28 B)은 audio_convertMonoToStereo(src, dest, count, format) 만 부름 — Darwin 의 channelCount 검사와 스테레오 가지 없음(매개변수는 Darwin 원형대로 둠; 바이트로 정할 수 없음).
3. 빌드: libDriver 묶음 — `-fwritable-strings` 없는 변형(plan 285; 문자열이 `__cstring`).
4. 스크래치 `w4`: OBJECT_MATCH(2092 B, 14 함수, `__cstring` 문자열 내용 확인), relcheck 0.

방법: 07 새 파일 `driverkit/audio_mix.c`(작성, D030 문구). iter_nows·relcheck·record_object(A 예상).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위 2092 B·14 기호·경계 채움 없음(함수 사이 nop 은 있음) | dis 0x1bdeef·0x1be71b, symbols | ✅ |
| IOLog 5 곳이 문자열 4 개를 씀(0x1be366·0x1be46e 가 convMono 공유) | w4 `__cstring` 4 문자열, 초안 IOLog 5 줄 | ✅ |
| 열거값 중 바이트가 정하는 것은 0·1·3 뿐, −1·2·4 는 Darwin 값 | dis 의 비교 상수 확인 | ✅ 문구 좁힘(초안·계획) |
| 원형 14 개는 audio_mix.h 와 같음, shortToMulaw unsigned char 일치; bcopy 원형 없음(암시) | 초안 확인 | ✅ (bcopy 암시 선언은 disk_label 과 같은 처리, 산출물 일치) |
| resample22To44 수정 맞음(0x1be268–0x1be283) | dis | ✅ |
| scaleSamples·convertStereoToMono·audio_mix 일치, 재배치 27 곳 밖 같음 | w4 OBJECT_MATCH | ✅ |
| hppa·FIXME 주석은 참고 텍스트지 i386 사실 아님; 기록에 출처·판·라이선스 명시 | — | ✅ 기록에 명시 |

### 결과(2026-10-04)

07 `src/driverkit/audio_mix.c`(작성, D030 문구, 열거 주석 좁힘), iter_nows `s5p279-it1` OBJECT_MATCH(2092 B, 14 함수, `__cstring` 확인), relcheck 0 → **A**. 기록: objects_confirmed 206→207 줄, functions 2333→2347, PROVENANCE 656→657, MODIFICATIONS +1 줄.

## 290. S5-P280 세부 계획 — `driverkit/snd_reply.c`(원본 바이트에서 작성 D024·D027·D030) + `driverkit/snd_msgs.h`(NeXTMach nextdev/snd_msgs.h 바탕 + 수정); 코딩 전 — 스크래치 진단만, 2026-10-04

참조(파일명, `find 01_resources/upstream -name 'snd_reply*' -o -name snd_msgs.h`): Darwin 0.1 driverkit-1/libDriver/Kernel/snd_reply.c(텍스트 거의 같음)·snd_reply.h(원형), NeXTMach mk-108.1 nextdev/snd_reply.c(같은 이름이나 다른 API — snd_reply_*(port, …) 가 스스로 msg_send 하고 kern_return_t 반환; 원본의 audio_snd_reply_*(msg, …) 꼴 대응 함수 없음, 미사용), 헤더는 NeXTMach nextdev/snd_msgs.h(바탕)·Darwin kernel/bsd/dev/snd_msgs.h(코드 참고). 근거 `08_build/runs/tools/s5p280-snd_reply.dis`, 초안 `s5p280-snd_reply_draft.c`·`s5p280-snd_msgs_draft.h`, 차이 `s5p280-snd_reply-darwin-vs-draft.diff`·`s5p280-snd_msgs-nextmach-vs-draft.diff`, 스크래치 `s5p280-w1`(07 미변경).

0. 객체 [0x1bdb8c, 0x1bdef0) 868 B(경계 채움 없음; 앞 label_subr 끝 `00`, 뒤 audio_mix 0x1bdef0): 전역 15 함수(audio_snd_reply_ret_device … ret_formats)와 인라인되는 정적 snd_reply_with_tag. `__DATA,__data` 16 B: 정적 snd_type_ool_template(0x1e53bc, 12 B: 비트 낱말 0x60000000 = longform·deallocate, long_name 9, long_size 8, number 0)·snd_type_int_template(0x1e53c8, 4 B: name 2·size 32·number 1·inline) — 디스어셈블의 `_sndPort+0x8`·`+0x14` 참조; 앞은 outPort 0x1e53ac·inPort 0x1e53b0·sndPort 0x1e53b4(다른 객체), 뒤는 audio_mulaw 의 iMuLaw 0x1e53cc. 배치는 L1d 추정.
1. 헤더(NeXTMach 바탕 + 수정, plan 290 표시): `kern/mach_types.h`·`sys/message.h` → SDK `mach/mach_types.h`·`mach/message.h`; snd_ret_samples_t 에 timeStamp(원본 ret_samples 0x1bdcb8 이 +0x20 에 쓰고 크기 0x24); snd_ret_stream_formats_t 와 SND_MSG_RET_STREAM_FORMATS(KERN_BASE+20 = 0x140 — ret_formats 의 msg_id 로 확인) 추가. 07 위치는 `driverkit/snd_msgs.h`(07_kernel/nextmach 는 원문 그대로만, nextdev_private 는 gitignore 대상이라 둘 다 맞지 않음), snd_reply.c 는 `#import "snd_msgs.h"`.
2. snd_reply.c: Darwin 지역 헤더 snd_reply.h(원형만) 대신 `bsd/sys/types.h` 와 위 헤더; 함수는 ANSI 정의라 원형 불필요. `//` 주석은 C 주석으로. 작성 원칙 D024·D027·D030(거의 같은 텍스트 명시, 고지 없음).
3. 빌드: libDriver 묶음 — `-fwritable-strings` 없는 변형(plan 285; 문자열 없음).
4. 스크래치 `w1`: OBJECT_MATCH(868 B, 15 함수, `__data` 16 B L1d 0).

방법: 07 새 파일 `driverkit/snd_msgs.h`(NeXTMach 바탕, 고지 유지)·`driverkit/snd_reply.c`(작성). iter_nows·relcheck·record_object(A 예상), 헤더 PROVENANCE 한 행.

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·15 기호·`__data` 템플릿 두 개(0x1e53bc 12 B, 0x1e53c8 4 B)와 비트 배치 맞음; 이웃 데이터의 이름·소유는 추정 | python 바이트(…00000060 09000800 00000000 02200110), dis 0x1bdc54–0x1bdc6f | ✅ |
| 헤더 추가(timeStamp +0x20·크기 0x24, stream formats 0x30·5 낱말, ID 0x140)는 바이트가 요구; 필드 이름·unsigned 는 Darwin 에서, include 경로 두 곳은 빌드 선택 | dis 0x1bdcc9–0x1bdce6, 0x1bdea9 `0x140` | ✅ 기록에 명시 |
| 다른 응답 구조체는 NeXTMach·Darwin 헤더에서 필드·순서 같음(u_int 표기만 다름) | diff 확인 | ✅ |
| NeXTMach snd_reply.c 는 API 친척이지 함수 대응판 아님 → D030 | NeXTMach :105 msg_send 꼴, 원본 0x1bdb8f 꼴 | ✅ |
| "every instruction checked" 는 표본 점검보다 넓은 말 | 산출물 전체가 원본과 비교됨(cmpobj OBJECT_MATCH = 모든 바이트) | ⚖️ 문구 유지(근거: 객체 전체 비교) |
| 스크래치 manifest 가 snd_reply.c 를 NeXTMach nextdev/ev.c 로 표기 | manifest 1652 행 확인 — wipbuild 의 운반용 override 참조(내용은 초안) | ✅ 사실; 기록은 07 의 it 실행으로 하므로 영향 없음, 스크래치 표기 한계로 명시(ev·memcpy·label_subr·disk_label·audio_* 스크래치도 같음) |

### 결과(2026-10-04)

07 `src/driverkit/snd_msgs.h`(NeXTMach 바탕 + plan 290 수정, 고지 유지)·`snd_reply.c`(작성, D030 문구), iter_nows `s5p280-it1` OBJECT_MATCH(868 B, 15 함수, `__data` 16 B L1d 0), relcheck 0 → **A**. 기록: objects_confirmed 207→208 줄, functions 2347→2362, PROVENANCE 657→659(snd_reply.c·snd_msgs.h), MODIFICATIONS +2 줄.

## 291. S5-P281 세부 계획 — `bsd/kern/kern_exec.c`(NeXTMach bsd/kern_exec.c 바탕 + 원본 바이트 수정·작성; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): NeXTMach mk-108.1 bsd/kern_exec.c(바탕), Darwin 0.1 bsd/kern/kern_exec.c(코드 참고 — 4.4BSD 인자 판, fat·load_return_to_errno·ROUND_PTR 꼴), Mach4 없음. 이전 분석 plan 210(보류 메모, `s5p183-d1`…`d3`). 근거 `08_build/runs/tools/s5p281-kern_exec.dis`, 초안 `s5p281-kern_exec_draft.c`, 차이 `s5p281-kern_exec-nextmach-vs-draft.diff`, 스크래치 `s5p281-d1`(헤더)·`d2`(plan 210 의 d3 판: execve 2472/2972)…`d10`(07 미변경).

0. 객체 [0x104c2c, 0x105abd) + `00 00 00`, 다음 rexit 0x105ac0(kern_exit). 함수: execv, execve(2972 B), create_unix_stack, load_init_program, check_exec_access, 기호 없는 정적 0x105a3c(load_return_to_errno). `__data` [0x1da684, 0x1da847) 451 B(uprintf 문구·init_program_name·init_args·init_attempts·other_init); init_exec_args 는 common.
1. plan 210 에서 정한 것(그대로 가져옴): `sys/exception.h`→`mach/exception.h`, `vm/vm_param.h`→`mach/vm_param.h`, `sys/loader.h`→SDK `mach-o/loader.h`; create_unix_stack(map, user_stack) 가 proc->user_stack 저장; ucp = u_procp->user_stack.
2. 머리(plan 291): SDK `mach-o/fat.h`, `kern/mfs.h`(vm_info), SDK `kernserv/c_utils.h`(ROUND_PTR); load_result_t·LOAD_* 를 07 mach_loader.c 와 같은 꼴로 이 파일에 정의; load_machfile·fatfile_getarch extern, 정적 load_return_to_errno 원형.
3. execve(원본 0x104c54–0x1057ef):
   a. exdata 에 fat_header; resid 검사 `resid > sizeof(exdata) − MIN(mach_header, fat_header)`(0x18); MH_MAGIC → is_fat 0, FAT_MAGIC/FAT_CIGAM → 1, MH_CIGAM → EBADARCH(84), 그 밖 #! 처리(0x104e51–0x104ed1).
   b. 인자 수집 뒤: is_fat 이면 fatfile_getarch(vp, fat_header, &fat_arch) → 실패면 load_return_to_errno; vn_rdwr 로 fat_arch.offset 의 mach_header(0x1c B) 읽기, resid 면 EBADEXEC(83), magic 이 MH_MAGIC 아니면 ENOEXEC; load_machfile(vp, mach_header, fat_arch.offset, fat_arch.size, &load_result), 아니면 load_machfile(vp, mach_header, 0, vp->vm_info->vnode_size, &load_result); 실패면 load_return_to_errno(0x105251–0x10533e).
   c. 추적 중이 아니면 px = get_posix_proc(p_pid), u_cred_lock() 아래 자격 복사·uid/gid, u_cred_unlock() 뒤 px->p_svgid·p_ruid(=uu_ruid)·p_svuid; 추적 중이면 exception_from_kernel(EXC_BREAKPOINT, 0, 0)(0x105344–0x10540f).
   d. vp 놓은 뒤 load_result.unixproc 이고 create_unix_stack(map, load_result.user_stack) 실패면 load_return_to_errno(LOAD_NOSPACE)(0x10548b–0x1054c3); 인자 복사 조건은 needargs 대신 unixproc; 뒤에 dynlinker 면 SP −4 하고 mach_header 를 suword(블록 지역 변수 — 레지스터 배정이 맞는 꼴), u_ar0[PC] = entry_point(0x1055e3–0x105619).
   e. 신호 정리에 uu_sigintr = 0 추가(0x105681); 끝에 p_flag |= SEXEC(0x105785).
4. load_init_program: 주소 올림을 ROUND_PTR(char, …)(SDK c_utils.h, COMPILER_BUG 16)로 — 원본 `add eax, 0x8f; and al, 0xf0`.
5. load_return_to_errno(0x105a3c): LOAD_* → 0, EBADARCH, EBADMACHO, ESHLIBVERS, ENOMEM, EACCES, 나머지 EBADEXEC(원본 점프 표 0x105a50, 값 0·0x54·0x56·0x55·0xc·0xd·0x53).
6. 스크래치 `d10`: OBJECT_MATCH(`__text` 3729 B, 6 함수, `__data` 0), relcheck 0. 스크래치는 COMPANION(kern/mach_loader.c·kern/mach_fat.c·machdep/i386/unix_signal.c·bsd/kern/kern_resource.c)과 SDK c_utils.h 덮어쓰기로 헤더 스테이징.

방법: 07 새 파일 `bsd/kern/kern_exec.c` = NeXTMach 원문(고지 유지) + 위 수정(plan 210·291 표시, D014·D024). iter·relcheck·기록(A 예상; SDK kernserv/c_utils.h·mach-o/fat.h 는 기록 때 nextdev 채택).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| kernserv/c_utils.h 는 07 에 없고 스크래치는 스테이징 사본; Darwin 판은 APSL 고지 | 실기 SDK /NextDeveloper/Headers/kernserv/c_utils.h 머리 "Copyright (c) 1992 NeXT, Inc." 확인 — 스크래치에 덮어쓴 것은 이 SDK 판(Darwin 판 아님) | ⚖️ 사실 보충: 채택할 것은 SDK 판, 기록 때 nextdev 로 채택하고 PROVENANCE 행(D017)을 남김 |
| 표시 없는 편집 줄(px, ucp, 스택 주소, ROUND_PTR 두 곳) | 초안 확인 | ✅ 표시 보충(d12); 나머지 표시 없는 줄은 plan 표시 주석이 붙은 블록 안 |
| 범위·정적 함수·점프 표·`__data`·3a–3e·ROUND_PTR 일치 | dis 해당 주소, w11 L1 | ✅ |

### 결과(2026-10-04, plan 291)

07 `src/bsd/kern/kern_exec.c`(d12), `s5p281-it1` OBJECT_MATCH(3729 B, 6 함수, `__data` 0), relcheck 0 → **A**. 기록: objects_confirmed 208→209 줄, functions 2362→2368, PROVENANCE 659→661(kern_exec.c + 채택 SDK kernserv/c_utils.h), MODIFICATIONS +1 줄.

### 사용자 지시 반영(2026-10-04): 재구현만, 기능 추가·개선 금지

점검 결과 원본 바이트가 요구하지 않는 수정 셋을 되돌림 — 컴파일되지 않는 코드에 붙인 `static`: nfs_vfsops.c 의 `#if !MACH` nfs_swapvp 선언·정의(plan 281 codex 제안을 받아들였던 것), nfs_server.c 의 `#if SECURE_NFS` rootname(plan 279), nfs_vnodeops.c 의 SUN_LOCK 판 nfs_lockctl(plan 282). NeXTMach 원문으로 복원, 재빌드 산출물 같음(`s5p271-it3`, `s5p269-it2`, `s5p272-it2`), PROVENANCE SHA·MODIFICATIONS 갱신. 앞으로 codex 가 바이트와 무관한 정리·일관성 수정을 제안하면 받아들이지 않음(메모리 no-feature-additions).

## 292. S5-P282 세부 계획 — `machdep/i386/start.s`(Darwin 0.1 원문 바탕, D029; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명, `find 01_resources/upstream -name start.s`): Darwin 0.1 kernel/machdep/i386/start.s(바탕 — 일치하는 Mach4·NeXTMach 원문 판 없음: NeXTMach next/locore.s 는 m68k, Mach4 i386/kernel/i386at/boothdr.S 의 `_start` 는 멀티부트 헤더·boot_entry 로 가는 다른 설계, Mach4 i386/boot 판들은 부트로더), Darwin ppc/start.s(미사용). 근거 `08_build/runs/tools/s5p282-start.dis`, 초안 `s5p282-start_draft.s`, Darwin 대비 `s5p282-start-darwin-vs-draft.diff`, 스크래치 `s5p282-w1`(asm_help.h 없음)·`w2`(경로)·`w3`(SDK architecture/i386/asm_help.h·reg_help.h 덮어쓰기; 07 미변경).

0. 객체 [0x1860dc, 0x186135) 89 B + `00 00 00`; 앞 miniMonMachdep(확정, 끝 ret 0x1860db), 다음 _trp_divr 0x186138. 기호 _start; `__data` [0x1e17b0, 0x1e17be) 14 B: _gdt_limit(word)·_gdt_base(long)·_idt_limit·_idt_base(.align 3, 원본 0 값).
1. 수정(최소, plan 292 표시): ① `#import <assym.h>`(생성 헤더, 이 트리에 없음) 대신 쓰는 네 선택자를 원본 값으로 정의 — LCODESEL 0x48·LDATASEL 0x50(0x1860f1·0x1860f8), KCSSEL 0x08·KDSSEL 0x10(0x186110·0x186117). ② Darwin 이 주석 처리한 BIOS 재부팅 플래그 두 줄(`movw $0x1234,%ax; movw %ax,0x472`)이 원본에는 있음(0x1860dc–0x1860e0) → 주석 해제. 그 밖(Darwin 의 `//` 주석 포함)은 원문 그대로 — w3 가 이 꼴로 어셈블됨을 보임.
2. 지역 레이블 start1·vstart 는 빌드 산출물에 기호로 남음(원본 기호표에는 없음 — 링크 때 지역 기호 제거); 바이트·재배치에는 영향 없음.
3. 스크래치 `w3`: OBJECT_MATCH(`__text` 89 B, `__data` 14 B).

방법: 07 새 파일 `machdep/i386/start.s` = Darwin 0.1 원문(Apple·NeXT·CMU 고지 유지) + 위 수정(D029, D014). SDK asm_help.h·reg_help.h 는 기록 때 nextdev 채택. iter·relcheck·record_object(base darwin01, A 예상).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·`00` 3 B·다음 _trp_divr, `__text` 89 B 일치 | dis, w3 L1 | ✅ |
| `__data` 14 B·네 기호·8 B 정렬 | symbols.tsv, python 바이트 | ✅ |
| 선택자 값은 바이트가 요구하나 assym.h 대체 자체는 빌드 선택 | — | ✅ 계획에 "빌드 선택" 으로 이미 적음 |
| BIOS 두 줄 필수(원본 `66 b8 34 12 66 a3 72 04 00 00`), 그 밖 차이 없음 | python 바이트 0x1860dc | ✅ |
| Mach4 i386at/boothdr.S 에도 `_start` 가 있어 "대응 판 없음"은 과함 | boothdr.S 확인: 멀티부트 헤더로 시작하는 다른 설계 | ✅ 문구를 "일치하는 원문 판 없음"으로 고침(D029 판단은 유지) |
| 지역 레이블 기호는 바이트·재배치 영향 없음; 언제 지워졌는지는 알 수 없음 | w3 재배치 확인 | ✅ 문구 존중 |

### 결과(2026-10-04)

07 `src/machdep/i386/start.s`(Darwin 원문 + plan 292 두 곳), `s5p282-it1` OBJECT_MATCH(89 B, `__data` 14 B), relcheck 0 → **A**. 기록: objects_confirmed 209→210 줄, functions 2368→2369(_start 하나 — record_object.py 가 `_` 없는 어셈블러 지역 레이블을 함수로 세지 않게 고침), PROVENANCE 661→664(채택 SDK architecture/i386/asm_help.h·reg_help.h + start.s), MODIFICATIONS +1 줄.

## 293. S5-P283 세부 계획 — `driverkit/IOMallocLow.c`·`driverkit/machdepFuncs.c`(원본 바이트에서 작성 D024·D027·D030; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명, `find 01_resources/upstream -iname 'IOMallocLow*' -o -iname 'machdepFuncs*'`): Darwin 0.1 driverkit-1/libDriver/Kernel/IOMallocLow.m·libDriver/i386/machdepFuncs.m 만 있음(Mach4·NeXTMach 같은 이름 파일 없음). 머리 SDK `driverkit/i386/kernelDriver.h`(실기 /NextDeveloper/Headers, SHA-256 e9dfc1d4…, 605 B; Darwin 판 driverkit-1/driverkit/i386/kernelDriver.h 는 미사용)·SDK `kernserv/queue.h`(449d846d…, 8495 B; 07 에는 이 SDK 원문에 plan 141.2 의 KERNEL_PRIVATE 전환 분기(→ kern/queue.h)를 넣은 nextdev_private/kernserv/queue.h 가 이미 있음 — PROVENANCE.tsv:421; Darwin kernel/kernserv/queue.h 는 HISTORY 를 빼고 비슷한 KERNEL_PRIVATE 분기를 넣은 판, 미사용). 실기에서 `cat` 으로 08_build/runs/tools/sdk293/ 에 옮겨 호스트 SHA-256 일치 확인.

0. 원본: _IOMallocLow 0x1c87e0, _IOFreeLow 0x1c8864, _IOBreakToDebugger 0x1c88ec(symbols.tsv). 앞 -[IOVPCodeDisplay setIntValues:forParameter:count:](0x1c865c, ret 뒤 `00` 1 B), 뒤 `00` 12 B 다음 sub_1C8900. IOMallocLow 객체 [0x1c87e0, 0x1c88eb) 267 B + `00` 1 B; machdepFuncs 객체 [0x1c88ec, 0x1c88f4) 8 B(`55 89 e5 cc 89 ec 5d c3`). `__cstring` "IOFreeLow: buf 0x%x not found\n"(파일 0xd994c, 31 B). 전역 _dmaBufQueue 는 `__common` 0x1f7490(기호로 주어짐; 빌드 객체도 common 8 B).
1. 두 이름 모두 objc.json 모듈 76 개에 없음(python 재검색: Malloc/machdep/Funcs 를 담은 모듈 이름은 swapgeneric.m·Kernel/generalFuncsPrivate.m 뿐) → C 로 빌드. 문자열이 `__cstring` 에 있으므로 libDriver 꼴(-fwritable-strings 없음, -O3; plan 285 와 같음).
2. 본문: Darwin 원문 그대로(공백 포함), 머리 주석만 D030 문구("nearly the same as Darwin 0.1 …", Apple·NeXT 고지 없음)로 바꿈. 바이트가 요구하는 수정 없음.
3. 스크래치: `s5p283-w3`(IOMallocLow; SDK 두 머리 덮어쓰기, COMPANION driverkit/ddm.c·machdep/i386/dma.c) OBJECT_MATCH(`__text` 267 B, 함수 2, `__cstring`); `s5p283-w4`(machdepFuncs) OBJECT_MATCH(8 B). w1 은 machdepFuncs 성공 실행(status 0, w4 와 같은 객체 SHA-256 40798d69…), w2 는 실패 실행(kernelDriver.h 없음) — 둘 다 재사용 안 함.

4. queue.h(codex 지적 후 재진단): 07 의 nextdev_private/kernserv/queue.h(사설 분기 → 07 kern/queue.h)로 빌드하면 `s5p283-c1` NOT_MATCH(241 B 대 267 B). 원본은 SDK 매크로 꼴 — SDK queue_enter 는 queue_empty 로 갈라 네 칸을 쓰고 queue_remove 는 queue_field 두 줄, 07 kern/queue.h 는 prev 비교 꼴. 두 머리는 같은 가드 `_KERN_QUEUE_H_` 를 쓰므로 SDK 원문을 먼저 읽으면 그 매크로가 남음(w3). KERNEL_PRIVATE 를 빼고 빌드하면 dma_exported.h → mach/mach_types.h 의 커널 머리가 깨짐(`s5p283-k1`, 버림). 즉 libDriver 객체는 SDK 원문 queue.h 로 컴파일된 것이고, plan 141.2 분기는 커널 객체용 작성분.
5. 그래서 빌드 도구만 고침: `stage_headers.py` 에 `--public-sdk NAME`(반복 가능, SDK 경로)을 더해 그 이름은 nextdev_private 작성판을 건너뛰고 SDK 원문(07_kernel/nextdev/<NAME>, 없으면 실기 사본)을 읽게 하고 매니페스트에 남김. 이 두 객체(그리고 앞으로 같은 꼴의 libDriver 객체)는 `--public-sdk kernserv/queue.h` 로 빌드. 07 소스·nextdev_private 판·다른 객체는 그대로(기본 동작 불변 — 회귀로 확인).

방법: 07 새 파일 둘(plan 293 표시, D024·D027·D030). SDK `driverkit/i386/kernelDriver.h`·`kernserv/queue.h`(원문) 를 07_kernel/nextdev 에 채택(D017, gitignored; PROVENANCE 행). iter_nows 에 PUBLIC_SDK 환경 변수로 위 옵션 전달 → relcheck → record_object(A 예상, authored, build_note: no -fwritable-strings, --public-sdk kernserv/queue.h). MODIFICATIONS 에 두 파일 행(“nearly the same as Darwin 0.1 …”, D030). 기본 옵션 불변 확인: stage_headers 단위 시험 + 07 queue.h 쓰는 확정 객체 몇 개 regress.

### codex 교차검토 판정(2026-10-04, 1차)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| Darwin queue.h 는 APSL 머리만 다른 게 아니라 HISTORY 를 빼고 KERNEL_PRIVATE 분기를 넣음 | `diff sdk293/queue.h darwin01/kernel/kernserv/queue.h`; Darwin :39 `#ifdef KERNEL_PRIVATE` … `#import <kern/queue.h>` | ✅ 참조 줄 고침 |
| 07 에 이미 SDK+사설 분기 queue.h(PROVENANCE:421)가 있고 w3 는 원문 SDK 판을 씀 — 07 판으로 시험해야 함 | `ls 07_kernel/nextdev_private/kernserv/queue.h`, `diff` = plan 141.2 삽입 두 곳, PROVENANCE.tsv:421 확인; 07 판 스크래치 `s5p283-c1` NOT_MATCH | ✅ 중요: 4·5 항 추가(도구 옵션) |
| w1 은 성공(status 0, w4 와 같은 SHA) | `08_build/runs/s5p283-w1/out/run.json`: status [['00','0']], F__machdepFuncs.o sha256 40798d69… = w4 | ✅ 내 오기, 고침 |
| 기록 단계에 MODIFICATIONS(D030 문구) 누락 | DECISIONS.md:34 D030 “file head + PROVENANCE/MODIFICATIONS” | ✅ 방법에 추가 |
| AGENTS.md:6 의 Darwin 고지 규칙과 D030 이 어긋남 | AGENTS.md:6, DECISIONS.md:34 | ⚖️ D030 은 사용자 확정 예외(2026-10-04 “D027 작성 유지”), 초안은 D030 대로 — 행동 변화 없음 |
| 주소·범위·채움·문자열 31 B·SDK 크기/해시·모듈 76, 초안 본문 = Darwin | 앞서 python 으로 같은 값 얻음(범위 0x1c88ea·0x1c88f3, 틈 1, 문자열), `diff` 결과 머리 주석만 다름 | ✅ |

### codex 교차검토 판정(2026-10-04, 2차 — 4·5 항과 도구 변경)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| SDK queue_enter 는 queue_empty 로 갈라 두 링크를 쓰고 queue_remove 는 queue_field 두 줄, 07 kern/queue.h 는 prev 저장·head 비교 꼴; w3 일치·c1 불일치 | 두 머리 매크로 본문 출력(awk), w3/c1 L1 결과 | ✅ 진단 유지 |
| mach_pick 은 closure(:230)와 매니페스트(:499) 두 곳에서 불림 — 같은 이름 집합을 써야 함; 이름·SDK 해시 검사, 없으면 실패 | `grep -n "mach_pick(" stage_headers.py`(변경 전) = :193 정의, :230, :499 | ✅ 전역 PUBLIC_SDK 하나를 두 호출이 같이 봄; 사설판 없음·MACH_KERNEL_STRIPPED·실기 목록 밖이면 SystemExit; SDK 해시는 기존 매니페스트 검사(nxsha_all)가 그대로 함 |
| bsd_pick 은 kernserv/queue.h 에 손댈 필요 없음 | bsd_pick 은 src/bsd/ 머리만 받음(select 안 :233, 변경 후 줄번호) | ✅ |
| w3 매니페스트는 수동 덮어쓰기 뒤에도 사설판 해시를 적음 — 옵션으로 다시 만들 것 | `input.actual:172` = 449d846d…(SDK), `s5p283-w3-stage.manifest.json:567` = nextdev_private 5c8b39e2… | ✅ 최종 it1 은 옵션으로 스테이징 — 매니페스트에 `public-sdk` 행·`public_sdk` 키 확인 |
| AGENTS.md:6 과 D030 문구가 어긋나니 커밋 전에 맞출 것 | AGENTS.md:6, DECISIONS.md:34 | ⚖️ 1차와 같은 지적 — D030 은 사용자 확정; AGENTS.md 는 사용자 파일이라 고치지 않고 보고에 남김 |

### 결과(2026-10-04)

- 도구: `10_tools/reconstruction/stage_headers.py` 에 `--public-sdk NAME`(plan 293 표시; 도움말·PUBLIC_SDK·mach_pick 조건·인자 검사·매니페스트 행/키). 단위 시험 `test_stage_headers_subst.py` 19건 통과; 잘못된 이름(kernserv/lock.h) 거부 확인. 옵션 없는 회귀 `s5p283-rg00` vfs_vnode·`rg01` uipc_usrreq OBJECT_MATCH, 둘 다 여전히 nextdev_private/kernserv/queue.h 스테이징.
- 07 `src/driverkit/IOMallocLow.c`: `s5p283-it1`(PUBLIC_SDK=kernserv/queue.h) OBJECT_MATCH(`__text` 267 B, 함수 2, `__cstring`), relcheck 0 → **A**. 07 `src/driverkit/machdepFuncs.c`: `s5p283-it2` OBJECT_MATCH(8 B), relcheck 0 → **A**.
- 기록: objects_confirmed 210→212 줄, functions 2369→2372, PROVENANCE 664→668(채택 SDK driverkit/i386/kernelDriver.h·kernserv/queue.h(07_kernel/nextdev, gitignored) + 두 파일), MODIFICATIONS 253→255 줄. 근거 06_reconstruction/evidence/x86-IOMallocLow.md·x86-machdepFuncs.md.

## 294. S5-P284 세부 계획 — `driverkit/generalFuncs.c`(원본 바이트에서 작성 D024·D027·D030; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명, `find 01_resources/upstream -iname 'generalFuncs*'`): Darwin 0.1 driverkit-1/libDriver/Kernel/generalFuncs.m(본문 바탕 — 원본과 거의 같음), libDriver/User/generalFuncs.m(사용자 판, 미사용), Kernel/generalFuncsPrivate.m(다른 객체, 원본에 ObjC 모듈 있음), driverkit/generalFuncs.h(머리). Mach4·NeXTMach 같은 이름 파일 없음.

0. 원본: _IOMalloc 0x1a5448 … _IOAlignmentToSize 0x1a55fc(14 함수, symbols.tsv), 끝 ret 0x1a5614 + `00` 3 B, 다음 __IOCopyMemory 0x1a5618(memcpy 객체, plan 284). 앞은 Kernel/IOConfigTable.m 의 메서드들(+[IOConfigTable newForConfigData:] 0x1a53e4 등). 객체 [0x1a5448, 0x1a5615) 461 B(+3 = 464). `__cstring` "%d(d) (UNDEFINED)"(0x1d6ea8). `__bss` 0x1e8688(IOFindNameForValue 의 sprintf·반환 두 참조로 주소만 확인; 이름 noValue·크기 80 B 는 후보 원문 Darwin generalFuncs.m:152 에서 온 것으로 zero-fill 이라 미검증 — reference-inferred).
1. generalFuncs.m 은 objc.json 모듈 76 개에 없음(generalFuncsPrivate.m 만 있음) → plan 293 과 같이 C, libDriver 꼴(-fwritable-strings 없음, -O3).
2. Darwin 본문 대비 수정(plan 294 표시):
   ① `#import <machkit/NXLock.h>` 를 들이지 않음 — Objective-C 머리(objc/Object.h, @interface)라 C 빌드에서 쓸 수 없음(빌드 선택; 이 파일은 NXLock 을 쓰지 않음).
   ② IOGetTimestamp: 원본은 `push 1; call _clock_value; mov [ebx],eax; mov [ebx+4],edx`(0x1a54ff–0x1a5508) → `*nsp = clock_value(System);` 와 지역 선언 `extern ns_time_t clock_value();`(07 kern/ns_timer.c:19 와 같은 꼴). Darwin 의 clock_get_counter/tvalspec 계산은 원본에 없음.
   ③ IOLog: 원본은 `push 3`(0x1a551f) = LOG_ERR → `vlog(LOG_ERR, …)`(Darwin 은 LOG_INFO 6).
   그 밖(IODelay 의 DELAY = SDK bsd/i386/machparam.h:51 us_spin, IOSleep·IOScheduleFunc 의 64 비트 곱, IOFindNameForValue/ValueForName, IOSizeToAlignment/AlignmentToSize, `#ifdef DEBUG` iotaskTest)은 Darwin 그대로.
3. 머리: Darwin 의 import 목록 그대로(① 제외). 07 스테이징에서 SDK mach/mach_interface.h·mach/mach_user_internal.h·bsd/dev/ldd.h·bsd/dev/disk.h(실기 목록 해시 6bde4f4a…·b96918ad…·2366d251…·8173a3f6…; 기록 때 nextdev 채택), bsd/sys/callout.h 는 KERNEL_STRIPPED 규칙대로 07 nextmach/sys/callout.h(`func`·CALLOUT_PRI_THREAD 4 동일), driverkit/memcpy.h 는 plan 81.1 규칙대로 Darwin driverkit-1(스테이징만).
4. 스크래치: `s5p284-c3`(Darwin 원문 + ①) 함수 크기 IOGetTimestamp 만 다름(76 대 28 B); `d1`(+②) IOLog 1 바이트 DIFF; `e1`(+③) `__text` 13 MATCH + 1 MATCH_UNVERIFIED(IOFindNameForValue — `__bss` 참조), 461 B. zerofill(알려진 배치 46 건 목록 s5p272) noValue 80 B → [0x1e8688, 0x1e86d8) reference-inferred → **P**(선례 tty·igmp·APM_i386 등). w1·w2·w3·w4·c1·c2 는 머리 찾기 중간 실행(재사용 안 함). 스크래치 매니페스트는 덮어쓴 머리를 사설판/다른 이름으로 적을 수 있음(plan 293 2차 판정) — 최종은 07 스테이징으로 다시 만듦.

방법: 07 새 파일 `driverkit/generalFuncs.c` = Darwin 본문 + 위 ①②③(머리 주석 D030 문구, Apple·NeXT 고지 없음). iter_nows·relcheck·zerofill(새 known 목록에 noValue 추가) → record_partial(P, authored, build_note libDriver). PROVENANCE·MODIFICATIONS(“nearly the same as Darwin 0.1 driverkit-1/libDriver/Kernel/generalFuncs.m”, D030).

### codex 교차검토 판정(2026-10-04)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| noValue[80] 은 원본 사실이 아님 — 주소만 참조로 확인, 이름·80 B 는 후보 원문에서 옴 | Darwin generalFuncs.m:152 `static char noValue[80];`; zf284.json conclusion reference-inferred | ✅ 0 항 문구 고침 |
| 수정 ①②③ 만 Darwin 과 다르고 각각 필요·최소 | 앞서 `diff` 결과 세 곳만 다름; c3→d1→e1 L1 결과(76→28 B, IOLog 1 B) | ✅ |
| 머리 해석은 계획대로; 3 항 “import 목록 그대로”는 “① 제외” 여야 함 | plan 3 항 문구 확인 | ✅ 문구 고침; 실제 해석은 07 스테이징으로 확인 예정 |
| P 등급이 선례(tty·igmp)와 일관 | 앞서 objects_partial 선례 grep(plan :429·:571) | ✅ |

### 결과(2026-10-04)

- AGENTS.md: 사용자 선택 “1”에 따라 Darwin 고지 규칙 줄에 D030 예외를 덧붙임(DECISIONS.md D030 행에도 적음).
- 07 `src/driverkit/generalFuncs.c`(스크래치 e1 과 같은 본문 + D030 머리 주석), `s5p284-it1`: `__text` 461 B 차이 0(13 MATCH + 1 MATCH_UNVERIFIED), relcheck 0. 스테이징 머리 해석은 3 항대로(매니페스트 확인). zerofill(`s5p284-zerofill-check-generalFuncs-20261004.json`, 알려진 배치 46 건 s5p272) [0x1e8688, …) reference-inferred → **P**. 새 알려진 배치 목록 `zerofill-known-s5p284-20261004.json`(47 건).
- 기록: objects_partial 44→45 줄, functions 2372→2386, PROVENANCE 668→674(채택 SDK mach/mach_interface.h·mach_user_internal.h·bsd/dev/ldd.h·bsd/dev/disk.h·bsd/dev/m68k/dma.h + generalFuncs.c), MODIFICATIONS 255→256 줄. record_partial.py 에 build_note(libDriver 빌드 조건) 지원 추가.

## 295. S5-P285 진단 — `bsd/ufs/ufs_lockf.c`(lf_lockctl, 원본 바이트에서 작성 D024; 스크래치 진단만, 2026-10-04) — 보류

참조(파일명): SDK bsd/ufs/lockf.h(Berkeley 7.1 2/1/91, lf_svnode·lockf 구조 — 원본 오프셋과 일치), Darwin 0.1 bsd/ufs/ufs/ufs_lockf.c(4.4BSD-Lite 8.4, 64 비트 off_t·TAILQ 판 — 코드 참고만), Mach4·NeXTMach 에 같은 이름 파일 없음. 원본 C 판(Net/2 계열 ufs_lockf.c)은 01_resources 에 없음.

- 원본 [0x142008, 0x142884) 2172 B, 기호는 _lf_lockctl 하나 + 정적 12 개(IDA 0x1420e4…0x14286c); `__data` 문자열 "lf_free_svnode: cannot find shadow vnode in hash list"·"lf_findoverlap: default"(0x1de054·0x1de08a), `__common` _lf_svnode_hash 0x1f6110. 상수: PLOCK 35(+5), PCATCH, EAGAIN 11, EDEADLK 78, F_GETLK 7, F_SETLK 8, off_t 는 KERNEL 에서 u_long.
- 초안(scratchpad `lfwip/ufs_lockf_wip_g1.c`, Net/2 꼴 lf_setlock·lf_clearlock·lf_getlock·lf_getblock·lf_findoverlap·lf_addblock·lf_split·lf_wakelock + NeXT lf_get_svnode·lf_free_svnode·lf_rmblock·lf_free): `s5p285-g1` 크기 2172 B 일치, `__data` 배치(L1d), 13 함수 중 11 MATCH.
- 남은 차이(레지스터 배정만): lf_setlock 18 B(원본 block=edi·priority/needtolink=esi, 빌드는 반대), lf_clearlock 38 B(원본 ovcase 를 lf 와 같은 ebx 에 둠, 빌드는 caller-save 로 스택 0xc 슬롯).
- 무효 시험: 선언 순서(v1 c1·c2·s1·s2), `register int ovcase`(h), -O2(같음)·-O1(나쁨)·`-fno-caller-saves`(나쁨), 루프 표현(c4 for/break, c6 `!= 0`, c7·c8 초기화 꼴), lf_setlock 우선순위 식(s4)·교착 검사 변수(s5·s6). goto 루프(c3)는 ovcase 를 ebx 에 두나 루프 배치가 달라짐 — 원본은 while 루프 배치.
- 실패 실행: `s5p285-optO2-1`·`s5p285-optO-1` 은 대문자 ID 로 kr_run 이 거부(“bad ID”) — 재사용 안 함, 소문자 `s5p285-o2-1`·`s5p285-o1-1` 로 다시 함.
- 덤프 진단 `s5p285-dg-1`(`-O3 -dg -dl`, 초안 g1 그대로; 08_build/runs/s5p285-dg-1/ufs_lockf.c.lreg·.greg): lf_clearlock 의 ovcase(의사 27)는 “used 6 times … crosses 1 call; pref AREG” — 루프 안 참조 가중으로 caller-save 이익 조건(사용 > 4×호출)을 넘어 eax+저장으로 감; lf(23)와 충돌 없음. lf_setlock 은 배정 순서 `33 27 54 68 57 30 22 34 23 29 28` — block(23, 17회·호출 7)이 needtolink(29)·priority(28)보다 먼저 esi 를 가져감(원본은 반대). 즉 원본 원문은 ovcase 참조 수/루프 구조와 setlock 변수 구성이 이 초안과 다름 — 단서 없음.
- 판정: 보류(07 에 넣지 않음). 07 에 넣을 때는 계획·codex 교차검토부터.

## 296. S5-P286 진단 — 첫 ObjC 객체 `NXSpinLock.m`(libDriver Kernel/NXSpinLock.m; 스크래치 진단만, 2026-10-04) — 모듈 이름 방식 결정 대기

- 원본: 모듈 "Kernel/NXSpinLock.m"(objc.json 모듈 0x2090cc), 메서드 init 0x1a8cf8·free 0x1a8d50·lock 0x1a8d9c·unlock 0x1a8dc4, `__text` [0x1a8cf8, 0x1a8dd9) 225 B(앞 IODirectDevice.m 의 마지막 메서드 ret 0x1a8cf7, 뒤 NXConditionLock 0x1a8ddc).
- 스크래치 빌더 `wipbuild_objc.py`(scratchpad; 더미 .c 로 머리 스테이징 후 .m 을 넣고 libDriver 꼴 -O3·-fwritable-strings 없음으로 빌드). Darwin 0.1 driverkit-1/libDriver/Kernel/NXSpinLock.m 본문 그대로, SDK machkit/NXLock.h·objc/*.h·streams/streams.h·ansi setjmp.h 를 머리로.
- `s5p286-d4`: l1_compare `--place-from-objc` 로 `__text` 225 B 메서드 4 개 MATCH, `__class`·`__meta_class`·`__inst_meth`·`__protocol`·`__cat_cls_meth`·`__cat_inst_meth`·`__instance_vars` L1d 0 차이, 리터럴 참조 내용 확인 — 다만 `__module_info`·`__symbols` 미배치: 모듈 이름이 "src/src/driverkit/NXSpinLock.m"(cc 에 준 경로)이라 원본 모듈과 짝을 못 지음.
- `s5p286-e1`: 같은 본문 맨 앞에 `# 1 "Kernel/NXSpinLock.m"` 한 줄 → 모듈 이름이 원본과 같아지고 **OBJECT_MATCH**(object_reasons 없음). 즉 모듈 이름은 컴파일러가 보는 파일 이름(e1 은 cc 인자는 d4 와 같고 줄 표지로 바꿈)에서 오며, 원본 쪽 이름은 원본 바이트의 사실. 작업 디렉터리 방식(D031)이 이름을 맞추는지는 plan 297 의 빌드로 따로 확인.
- 원본 모듈 이름 76 개 = 상대 57(예 Kernel/X.m, IODevice.m, eisa/…, i386/…) + 절대 19(/BinarySourceCache_Mario1A/mk/mk-183.34.4/… — driverkit·bsd/dev·machdep 의 커널 쪽 .m).
- 결정 필요(사용자): 모듈 이름을 무엇으로 재현할지 — 아래 보고의 선택지. 결정 전에는 ObjC 객체를 07 에 넣지 않음.

## 297. S5-P287 세부 계획 — ObjC 빌드 경로(D031 “빌드 디렉터리 재현”)와 첫 객체 `NXSpinLock.m`(코딩 전, 2026-10-04)

목표: 상대 모듈 이름(57 개)을 소스 수정 없이 맞추는 빌드 경로를 만들고, 첫 객체 NXSpinLock.m 을 07 에 넣어 OBJECT_MATCH 로 기록. 절대 이름 19 개는 이번 범위 밖(실기 경로가 필요 — 사용자 작업, 별도 요청).

1. `10_tools/reconstruction/kr_run.py`(plan 297 표시): 명령 파일에 `RUNIN <dir> <tool> <args…>` 추가.
   - `<dir>`: 실행 디렉터리 기준 상대 경로, `src/` 로 시작, ARG_RE, `..` 금지, 절대 경로 금지.
   - `<args>`: RUN 과 같은 검사. 단어 맨 앞의 `@R/` 또는 `-I@R/`(붙여 쓴 꼴) 하나만 실행 디렉터리 절대 경로(`$R/`, run.sh 가 이미 정의)로 바꿈 — 그 밖의 `@R`·두 번 이상은 거부. prepare 는 `<dir>` 가 복사된 src 트리에 실제 디렉터리로 있는지 확인.
   - run.sh 줄: `(cd <dir> && <tool> <args>) > stage/_log/NN.out 2> stage/_log/NN.err; echo "NN $?" >> stage/_log/status`(RUN 과 같은 번호·로그 규칙).
   - 기존 RUN·EXPECT·검사는 그대로(기본 동작 불변). 시험: parse_cmdfile 양성 1·음성 4(`..`, 절대 dir, src/ 밖 dir, 단어 중간 `@R`), prepare 로 만든 run.sh 줄 확인; 기존 test_kr_run_tools 그대로 통과.
2. 07 배치: libDriver ObjC 는 원래 디렉터리 구조로 `07_kernel/src/driverkit/libDriver/<모듈 이름>`(예: `libDriver/Kernel/NXSpinLock.m`). 빌드 = `RUNIN src/src/driverkit/libDriver /bin/cc …템플릿 플래그(libDriver 꼴: -fwritable-strings 없음, -O3)… -I@R/src/… -imacros @R/src/generated/meta_features.h -c Kernel/NXSpinLock.m -o @R/stage/F__NXSpinLock.o`. 이미 07 에 있는 libDriver C 파일(driverkit/memcpy.c 등)은 옮기지 않음(모듈 이름이 없음).
3. 머리: stage_headers 가 07 의 .m 원본을 스캔해 머리를 스테이징하는지 `--list` 로 먼저 확인. SDK machkit/·objc/·streams/·ansi 머리는 D022 대로 SDK 판(`--nextdev` 뿌리; 07_kernel/nextdev 채택은 기록 때). Darwin 판이 먼저 잡히면 계획을 고쳐 다시 검토.
4. 스크래치 빌더 iter_objc.py(scratchpad): 07 에서 스테이징 → 위 RUNIN 명령 → collect → l1_compare `--place-from-image --place-from-objc`(ObjC 비교, S1-D) → OBJECT_MATCH 여부.
5. record_object ObjC 모드(scratchpad 도구): 시작 주소는 L1 의 `__text` 배치(“given by objc metadata”); 함수 행은 목적 파일의 메서드 기호(`-[NXSpinLock init]` 등, 원본 기호표에는 없음 — sym 칸에 메서드 이름, 07 행 번호는 `@implementation` 안 `- init` 줄); 경계는 앞뒤 원본 바이트. objects_confirmed 증거에 `__OBJC` 섹션 배치(L1 결과)를 남김.
6. NXSpinLock.m: Darwin 0.1 driverkit-1/libDriver/Kernel/NXSpinLock.m 본문 그대로, 머리 주석만 D030 문구(“nearly the same as Darwin 0.1 …”, Apple·NeXT 고지 없음). 수정 없음(`s5p286-d4`/`e1` 로 본문 일치 확인).

검증: kr_run 시험, 기존 확정 객체 1–2 개 회귀(RUN 경로 불변), iter_objc 로 07 NXSpinLock OBJECT_MATCH, relcheck(외부 재배치 이름).

### codex 교차검토 판정(2026-10-04, plan 296·297)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 296 사실(모듈 0x2090cc, 메서드 주소, 225 B, 57/19) 맞음 | 앞서 python 계산(57·19)·objc.json·L1 결과 | ✅ |
| d4·e1 의 cc 인자는 같고 e1 은 줄 표지로 이름을 바꿈 — “cc 입력 경로 = 이름”은 추론 | 두 cmd 의 인자 `src/src/driverkit/NXSpinLock.m` 동일, e1 원본 첫 줄 `# 1 "Kernel/NXSpinLock.m"` | ✅ 296 문구 고침; 297 빌드로 확인 |
| `-I@R/…` 는 계획 문구(단어 맨 앞만)로는 거부됨 | 계획 1813 행 문구 확인 | ✅ `-I@R/` 붙여 쓴 꼴을 명시해 허용·검사 |
| RUNIN 안전 경계 유지 가능; dir 존재 확인을 더할 것; 로그 번호·입력 해시·LOCK 순서 유지 | kr_run.py 154–185 행(LOCK→입력 해시→명령→재해시) 확인 | ✅ prepare 에 dir 존재 확인 추가 |
| `--prefer-07` 에서 07 의 .m 이 잡히고 machkit·objc·streams 는 SDK, setjmp.h 는 SDK ansi 판이 src/bsd/include 로 스테이징, kernserv/lock.h 는 nextdev_private | 뿌리별 파일 존재 확인(Darwin 뿌리에 machkit·objc/Object.h·streams 없음, setjmp.h 는 Darwin bsd/include 에만) | ⚖️ 코드 읽기와 일치; 실제는 07 배치 뒤 `--list`·매니페스트로 확인 |
| 스크래치 매니페스트는 더미 .c(NeXTMach)라 .m 출처 근거가 아님 | s5p286-d4-stage.manifest.json 확인 | ✅ 기록은 07 스테이징 실행으로만 |

### 결과(2026-10-04, plan 297)

- 도구: `kr_run.py` 에 RUNIN(plan 297 표시; 문서 줄·parse_cmdfile·prepare 의 디렉터리 존재 확인·run.sh `(cd DIR && …)` 생성, `@R/`·`-I@R/` → `$R/`). 새 시험 `test_kr_run_runin.py` 10/10, 기존 `test_kr_run_tools.py` 7/7. RUN 경로는 그대로.
- 07 `src/driverkit/libDriver/Kernel/NXSpinLock.m`(Darwin 본문 그대로 + D030 머리 주석; 처음 초안이 import 앞 `#define KERNEL`·`KERNEL_PRIVATE`·`ARCH_PRIVATE` 세 줄을 빠뜨린 것을 넣기 전에 바로잡음). 스테이징 `--list`: machkit·objc·streams·ansi 는 SDK, kernserv/lock.h 는 nextdev_private(codex 판정과 일치).
- `s5p287-it1`(RUNIN src/src/driverkit/libDriver … Kernel/NXSpinLock.m): **OBJECT_MATCH** — `#line` 없이 모듈 이름 일치, `__text` 225 B 메서드 4, `__OBJC` 전 섹션 일치; relcheck 0 → **A**.
- 기록(scratchpad `record_objc.py`: 메서드 단위 함수 행, nextdev 뿌리 SDK 머리 채택): objects_confirmed 212→213 줄, functions 2386→2390, PROVENANCE 674→693(채택 SDK 18: ansi/setjmp.h·mach/mach.h·mach_host.h·mach_init.h·machkit/NXLock.h·objc 5·streams/streams.h·ansi machine/i386 stddef·stdarg·setjmp·stdtypes + NXSpinLock.m), MODIFICATIONS 256→257 줄.

## 298. S5-P288 세부 계획 — `libDriver/Kernel/NXConditionLock.m`·`NXLock.m`(D024·D027·D030·D031; 코딩 전 — 스크래치 진단만, 2026-10-04)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/NXConditionLock.m·NXLock.m(본문 바탕), User/ 판(사용자 공간, 미사용); Mach4·NeXTMach 같은 이름 없음.

0. 원본: 모듈 "Kernel/NXConditionLock.m"(0x2090dc) `__text` [0x1a8ddc, 0x1a8fd5) 505 B 메서드 8, `00` 3 B; "Kernel/NXLock.m"(0x2090ec) [0x1a8fd8, 0x1a90b7) 223 B 메서드 4, `00` 1 B; 다음 generalFuncsPrivate.m 의 _IOInitGeneralFuncs 0x1a90b8. 모듈 순서 NXSpinLock → NXConditionLock → NXLock → generalFuncsPrivate(objc.json 모듈 주소 순).
1. 스크래치 `s5p288-nxcondit-1`·`s5p288-nxlock-1`(Darwin 본문 + 진단용 `#line`): 둘 다 OBJECT_MATCH(`__text`·`__OBJC` 전부). 바이트가 요구하는 수정 없음.
2. 방법: 07 `src/driverkit/libDriver/Kernel/NXConditionLock.m`·`NXLock.m` = Darwin 본문 그대로(import 앞 `#define` 줄 포함) + D030 머리 주석. iter_objc(RUNIN, `#line` 없음) → relcheck → record_objc(A 예상).

## 299. S5-P289 세부 계획 — `libDriver/Kernel/generalFuncsPrivate.m`(D024·D027·D030·D031) + l1_compare 의 메서드 없는 ObjC 모듈 처리(코딩 전, 2026-10-04)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/generalFuncsPrivate.m(본문 바탕), Darwin kernel/driverkit/autoconfCommon.m 의 `_io_vm_task_buf`(같은 판단을 커널 쪽 함수로 옮긴 Darwin 판 — 원본에는 그 기호가 없음); Mach4·NeXTMach 같은 이름 없음.

0. 원본: 모듈 "Kernel/generalFuncsPrivate.m"(0x2090fc, 클래스·카테고리 0) `__text` [0x1a90b8, 0x1a9404) 844 B, 전역 18 + 정적 ioThreadStart(0x1a9140); 다음 ObjC 메서드 0x1a9404(IOBufDevice.m). `__bss` 16 B — 참조로 0x1e86ec 추정(정적 threadArgFcn·threadArgArg·libInitialized·threadArgLock 후보).
1. 스크래치 `s5p288-gfq-1`(Darwin 본문, machine/param.h 를 빈 파일로 덮어씀) 함수 크기 차이 3: IOSetUNIXError(8 대 20), IOVmTaskForBuf(16 대 48), Darwin 의 IOMapPhysicalIntoIOTaskUnaligned(원본에 없음).
2. 수정(plan 299 표시):
   ① IOSetUNIXError: 원본은 `mov eax,[active_u+4]; mov dl,[ebp+8]; mov [eax+0x68],dl`(0x1a9253–0x1a925b) = `u.u_error = errno`(u = active_u[cpu_number()], u_error = uthread->uu_error 0x68). Darwin 의 `#warning`·`#if 0` 대신 대입을 살림.
   ② IOVmTaskForBuf: 원본은 `(b_flags & 0x4000010) == 0x10` 이면 `_io_vm_task(b_proc->task)`(0x1a9300–0x1a9311), 아니면 `_io_vm_task_self()`(0x1a931c) → `B_PHYS|B_KERNSPACE` 판단을 이 함수 안에 씀(Darwin 은 `_io_vm_task_buf` 호출). 이를 위해 `<sys/proc.h>` import 추가(빌드 필요; `->task` — `<sys/buf.h>` 는 driverkit/kernelDriver.h:15 가 이미 들임).
   ③ IOMapPhysicalIntoIOTaskUnaligned 를 뺌(원본에 없음).
   ④ `#import <machine/param.h>` 를 들이지 않음: OPENSTEP 4.2 머리 집합(SDK·NeXTMach·07)에 이 이름이 없고(SDK 는 bsd/machine/machparam.h), 이 객체는 그 머리에서 쓰는 것이 없음(빈 파일로 `__text` 일치) — 빌드 선택.
   `s5p288-gfr-1`(①②③ + 빈 machine/param.h): `__text` 0 차이(16 MATCH + 3 MATCH_UNVERIFIED — `__bss` 참조), `__module_info`·`__symbols` ObjC 메타데이터 배치 0 차이.
3. 도구: `l1_compare.py` 는 메서드가 없는 목적 파일에도 “method correspondence incomplete” 를 붙임(placements_from_methods 의 placed=False). 수정: 메서드 기호가 0 개면 대응할 것이 없으므로 그 사유를 붙이지 않음(메서드가 있으면 지금과 같음). 시험 `test_objc_compare.py` 그대로 통과 + 메서드 없는 모듈 양성 1 건.
4. `__bss` 16 B 는 zerofill 로 배치 확인 → 참조 추정이면 **P**(선례 generalFuncs).

방법: 07 `src/driverkit/libDriver/Kernel/generalFuncsPrivate.m` = Darwin 본문 + ①–④ + D030 머리 주석; iter_objc → relcheck → zerofill → record(P; record_objc 에 P 모드 추가 또는 record_partial 확장).

### codex 교차검토 판정(2026-10-04, plan 298·299)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 298 범위·채움(3 B·1 B)·메서드·모듈 순서 맞음, 두 스크래치 OBJECT_MATCH | 앞서 python(0x3·0x1)·L1 결과 | ✅ |
| ①–③ 원본 바이트로 뒷받침(b_proc 0x2c, task 0x68, 플래그 값) | buf.h:149 B_PHYS 0x10·:173 B_KERNSPACE 0x04000000, gfr-1 `__text` 0 차이 | ✅ |
| `<sys/buf.h>` 는 kernelDriver.h 가 이미 들임 — `<sys/proc.h>` 만 필요 | 스테이징 사본 kernelDriver.h:15 `#import <sys/buf.h>` | ✅ ② 고침 |
| ① 설명에 `mov dl,[ebp+8]` 빠짐 | odis 0x1a9258 | ✅ 고침 |
| machine/param.h 를 뺀 최종 파일로 따로 빌드 확인 필요(스크래치는 빈 머리) | 계획 확인; 페이지 매크로는 mach/vm_param.h:108·127 | ✅ 07 빌드로 확인 |
| 메서드 없는 경우 예외는 섹션 관문이 남아 안전; 음성 시험(메서드 없는 객체의 `__module_info`·`__text` 변조) 추가 | l1_compare.py:390–402 확인 | ✅ 시험 추가 |
| `__bss` 는 P 유지 | zerofill 선례 | ✅ |

### 결과(2026-10-04, plan 298·299)

- 298: 07 `libDriver/Kernel/NXConditionLock.m`·`NXLock.m`(Darwin 본문 + D030 머리 주석, diff 로 주석 외 차이 없음 확인). `s5p288-it1`·`it2`(RUNIN) 모두 OBJECT_MATCH(메서드 8·4), relcheck 0 → **A** 둘. 기록: objects_confirmed 213→215 줄, functions 2390→2402, PROVENANCE 693→695, MODIFICATIONS 257→259 줄.
- 299 도구: `l1_compare.py` 메서드 기호 0 개면 “method correspondence incomplete” 를 붙이지 않음(plan 299 표시). `test_objc_compare.py` 13/13, 새 `test_objc_nomethod.py` 5/5(양성 3, 음성 2: `__module_info` 크기·`__text` 바이트 변조 → NOT_MATCH).
- 299: 07 `libDriver/Kernel/generalFuncsPrivate.m`(Darwin 본문 + ①–④ + D030 머리; 처음 최종본이 `#define ARCH_PRIVATE 1` 을 빠뜨린 것을 넣기 전에 바로잡음). `s5p289-it1`: `__text` 844 B 0 차이(16 MATCH + 3 MATCH_UNVERIFIED), `__module_info`·`__symbols` 0 차이, relcheck 0; zerofill(`s5p289-zerofill-check-generalFuncsPrivate-20261004.json`, 알려진 배치 47) [0x1e86ec, 0x1e86fc) reference-inferred → **P**. 새 알려진 배치 목록 `zerofill-known-s5p289-20261004.json`(48). 기록: objects_partial 45→46 줄, functions 2402→2421, PROVENANCE 695→697(채택 SDK driverkit/kernelDriver.h + 본 파일), MODIFICATIONS 259→260 줄.

## 300. S5-P290 세부 계획 — libDriver ObjC 분류(진단)와 `Kernel/IONetbufQueue.m`·`Kernel/kernelDiskMethods.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

- 분류(scratchpad `triage.py`, 진단만·07 미변경): 상대 이름 모듈 중 Darwin 0.1 driverkit-1/libDriver 에 같은 경로 파일이 있는 49 개에서 plan 297–299 의 4 개를 뺀 45 개를 Darwin 본문 + 진단용 `#line` 으로 빌드해 ObjC L1. 1 차(`s5p290-NN-*`, 머리는 07·SDK 만): OBJECT_MATCH 2(IONetbufQueue, kernelDiskMethods), 나머지 43 은 빌드 실패 — 대부분 Darwin 전용 driverkit 비공개 머리(plan 81.1 규칙상 Darwin driverkit-1 에서 옴)를 진단 머리 찾기가 찾지 못함, IONetwork·IOSCSIController 는 SDK 머리와의 차이로 컴파일 오류. 2 차(`s5p291-NN-*`, 진단 뿌리에 07 nextmach·Darwin driverkit-1·libDriver·Darwin 커널 뿌리 추가)는 진행 중 — 결과는 모듈별 계획에서만 근거로 쓰고, 07 빌드는 늘 stage_headers 규칙으로.
- objc 런타임 8 모듈(HashTable.m·List.m·Object.m·Protocol.m·maptable.m·objc-class.m·objc-load.m·objc-runtime.m)은 01_resources 에 참조 원문이 없음 — 뒤로 미룸.

0. 원본:
   - "Kernel/IONetbufQueue.m"(objc.json 모듈 0x20912c) `__text` [0x1a9968, 0x1a9ad3) 363 B, 메서드 7(init·initWithMaxCount:·free·count·maxCount·enqueue:·dequeue), 뒤 `00` 1 B, 다음 0x1a9ad4.
   - "Kernel/kernelDiskMethods.m"(0x20917c, 카테고리 2: IODisk(kernelDiskMethods)·IODisk(kernelDiskMethodsPrivate)) `__text` [0x1ac298, 0x1ac3d6) 318 B, 메서드 7, 뒤 `00 00`, 다음 0x1ac3d8.
1. 스크래치 `s5p290-10-*`·`s5p290-15-*`(Darwin 본문 + `#line`): 둘 다 OBJECT_MATCH. 바이트가 요구하는 수정 없음.
2. 방법: 07 `src/driverkit/libDriver/Kernel/IONetbufQueue.m`·`kernelDiskMethods.m` = Darwin 본문 그대로(주석 뒤 첫 줄부터 — `#define` 줄 포함) + D030 머리 주석. iter_objc(RUNIN) → relcheck → record_objc(A 예상). 07 스테이징 매니페스트로 머리를 다시 확인(스크래치 매니페스트는 더미 .c 이름). 기록: 파일·메서드 단위 PROVENANCE, MODIFICATIONS(“nearly the same as Darwin 0.1 …”), 새로 필요한 SDK 머리 채택 행.

### codex 교차검토 판정(2026-10-05, plan 300)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈 주소·카테고리 수·범위·메서드 7·채움 1/2 B, 두 L1 OBJECT_MATCH | 앞서 python 출력(0x1a9968–0x1a9ad3, pad 00; 0x1ac298–0x1ac3d6, pad 0000) | ✅ |
| 스크래치 머리는 07 선택과 같으나 매니페스트가 더미 .c 이름 — 07 배치 뒤 매니페스트 재확인 | plan 297 판정과 같은 지적 | ✅ 방법에 추가 |
| 45 는 49 에서 4 개 뺀 수 | python: libDriver 경로 일치 모듈 49 | ✅ 고침 |
| 기록 단계(PROVENANCE·MODIFICATIONS·SDK 채택) 명시 | record_objc 가 하는 일 확인(채택·행 추가) | ✅ 방법에 명시 |

### 결과(2026-10-05, plan 300)

- `s5p292-it1`·`it2` 는 준비 뒤 시작 거부(분류 실행이 실기 LOCK 을 잡고 있었음) — ID 소모, 재사용 안 함.
- 07 `libDriver/Kernel/IONetbufQueue.m`·`kernelDiskMethods.m`(Darwin 본문 + D030 머리; 공통 `mkfinal.py` 로 주석 블록만 건너뜀). `s5p292-it3`·`it4`(RUNIN) OBJECT_MATCH(메서드 7·7), relcheck 0 → **A** 둘. 기록: objects_confirmed 215→217 줄, functions 2421→2435, PROVENANCE 697→708(채택 SDK 머리 포함), MODIFICATIONS 260→262 줄.
- 분류 2 차(`s5p291-NN-*`) 끝: 43 개 중 OBJECT_MATCH 8(IOBufDevice·IOTokenRing·IODisplay·EventDriver·EventInput·EventIO·IOEventSource·KeyMap), `__bss` 만 남은 것 1(i386/IOVPCodeDisplay), NOT_MATCH 7, 빌드 실패 27(오디오·eisa/pci/pcmcia·SCSI 등 — 머리 차이).

## 301. S5-P291 세부 계획 — `Kernel/IOBufDevice.m`·`Kernel/IOEventSource.m`·`Kernel/KeyMap.m`(A)·`i386/IOVPCodeDisplay.m`(P)(D024·D027·D030·D031; 코딩 전, 2026-10-05)

분류 2 차의 OBJECT_MATCH 8 중 진단 머리가 07·SDK·Darwin driverkit-1(plan 81.1)뿐인 것(IOBufDevice·IOEventSource·KeyMap)과 `__bss` 만 남은 IOVPCodeDisplay. 나머지 5(IOTokenRing·IODisplay·EventDriver·EventInput·EventIO)는 SDK 에 없는 커널 BSD 머리(net/tokensr.h, bsd/dev/evio.h·ev_private.h·kmreg_com.h·i386/ConsoleSupport.h)를 진단에서 Darwin 커널 뿌리로 채웠음 — bsd-set 규칙상 07 빌드는 그 머리를 쓸 수 없으므로 따로 계획(NeXTMach nextdev/evio.h 도 있음 — 파일명 확인).

0. 원본(objc.json·L1 `s5p291-08/24/25/44`):
   - "Kernel/IOBufDevice.m"(0x20910c, 클래스 1·카테고리 1) `__text` [0x1a9404, 0x1a95c7) 451 B 메서드 8, `00` 1 B, 다음 함수 0x1a95c8. 0x1a95c8–0x1a9693 은 기호 없는 C 함수 4 개(`_if_private` 를 부르고 메시지를 보냄); 그 사이와 IONetwork 첫 메서드 0x1a9694 앞의 채움은 모두 `90`(GCC 의 목적 파일 안 정렬), IOBufDevice 끝 뒤는 `00`(링커의 목적 파일 사이 채움) → 그 코드는 IONetwork 메서드와 같은 목적 파일이고 IOBufDevice 객체에 속하지 않음. IONetwork.m 원문의 어느 부분인지는 미정(Darwin IONetwork.m 에 해당 함수 없음).
   - "Kernel/IOEventSource.m"(0x20920c) [0x1b37bc, 0x1b3aa2) 742 B 메서드 8, `00 00`, 다음 0x1b3aa4.
   - "Kernel/KeyMap.m"(0x20921c) [0x1b3aa4, 0x1b4a31) 3981 B 메서드 12, `00` 3 B, 다음 0x1b4a34.
   - "i386/IOVPCodeDisplay.m"(0x20934c) [0x1c6c44, 0x1c87df) 7067 B 함수 15(메서드 14), `00` 1 B, 다음 _IOMallocLow 0x1c87e0(plan 293). `__data` 52 B(0x1e5420)·`__TEXT,__const` 256 B(0x1d637c) L1d 일치, `__bss` 12 B 는 L1 이 참조로 [0x1e873c, 0x1e8748) 추정(zerofill 로 확인).
   네 경우 모두 끝 뒤 0 바이트 다음이 함수 머리 `55 89 e5`(python 확인).
1. 스크래치(Darwin 본문 + 진단 `#line`): 앞 셋 OBJECT_MATCH, IOVPCodeDisplay 는 `__bss` 미확인만. 수정 없음.
2. 도구(scratchpad record_objc.py): ① 끝 뒤 경계: `00` 채움(1–3 B, 링커의 목적 파일 사이 채움)이 있으면 그 다음이 함수 머리(`55 89 e5`)·기호·IMP 여야 하고, 채움이 0 B 면 다음 위치가 원본 기호나 다른 모듈의 IMP 여야 함(소유는 채움 근거로만 — 객체 안 정렬은 `90`). 지금은 “다음 기호/IMP” 까지가 모두 0 이어야 해서 IOBufDevice 처럼 기호 없는 C 함수가 뒤에 오면 실패. 메서드의 07 행 번호는 해당 `@implementation 클래스(카테고리)` … `@end` 안의 정의에서만 찾음(선언 제외). 스테이징 하위 프로세스 반환값 확인. ② P 모드: L1 사유가 `__DATA,__bss: unverified` 하나뿐이고 zerofill 결론이 reference-inferred 이며 그 zerofill 의 입력 목적 파일 SHA-256·섹션 크기가 최종 L1 의 것과 같을 때만 objects_partial 에 기록(열: unverified_sections = bss 메모), 함수 행 validation·근거 문서의 판정 문구도 P 로.
3. 방법: 07 `src/driverkit/libDriver/Kernel/IOBufDevice.m`·`IOEventSource.m`·`KeyMap.m`, `src/driverkit/libDriver/i386/IOVPCodeDisplay.m` = Darwin 본문(mkfinal.py) + D030 머리. iter_objc(RUNIN src/src/driverkit/libDriver) → 07 스테이징 매니페스트로 머리 확인(Darwin 커널 뿌리 머리가 끼면 멈추고 재계획) → relcheck → record_objc(A 셋, P 하나; IOVPCodeDisplay 는 zerofill 알려진 배치 48 건 목록으로).

### codex 교차검토 판정(2026-10-05, plan 301)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·크기·메서드 수·채움·다음 함수 머리 맞음; IOVPCodeDisplay `__bss` 는 추정 | 앞서 python(0 바이트 수 1/2/3/1, `5589e5`) | ✅ |
| 0x1a95c8–0x1a9693 소속은 위치만으로 증명 안 됨 — “미귀속”으로 | capstone: IOBufDevice ret 0x1a95c6 뒤 `00`, 네 함수 사이·0x1a9694 앞은 `90 90 90` | ⚖️ 채움 바이트로 IOBufDevice 소속은 아님을 보임(같은 목적 파일 = IONetwork 메서드 쪽); IONetwork.m 원문 대응은 미정으로 0 항 고침 |
| 오버라이드 머리는 07 선택과 같음 — 최종 매니페스트 확인은 여전히 필요 | plan 300 과 같은 지적 | ✅ |
| 경계 규칙만으로 소유를 증명 못함 | 위 채움 근거 | ✅ 규칙을 `00` 채움(링커)·`90`(객체 안) 구분으로 강화 |
| P 모드는 zerofill 입력 SHA·섹션 크기를 최종 L1 과 묶고, 하드코딩된 A 문구 모두 바꿀 것 | record_objc2 초안의 판정 문구 확인 | ✅ 반영 |
| mline 이 선언 줄을 먼저 잡을 수 있음(IOBufDevice 카테고리 선언, IOVPCodeDisplay 비공개 선언) | Darwin IOBufDevice.m:47 근처 `@interface` 안 선언 확인 필요 → 아래 수정으로 해당 `@implementation` 안만 검색 | ✅ 반영; 스테이징 반환값 확인도 추가 |

### 결과(2026-10-05, plan 301)

- record_objc.py(scratchpad) 갱신: 경계(링커 `00` 채움 / 0 B 면 알려진 시작), ret 끝 확인, 메서드 줄은 해당 `@implementation 클래스(카테고리)` 안에서만, 스테이징 반환값 확인, P 모드(zerofill 입력 SHA·크기를 최종 L1 과 묶음). 이전 판은 record_objc_v1.py 로 보관. 기록된 libDriver 메서드 행 58 개 전부 인용 줄이 맞는 `@implementation` 안 정의임을 python 으로 확인(v1 기록분 포함, 오류 0).
- 07 `libDriver/Kernel/IOBufDevice.m`·`IOEventSource.m`·`KeyMap.m`: `s5p293-it1`–`it3` OBJECT_MATCH(메서드 8·8·12), relcheck 0, 스테이징 매니페스트는 07·SDK·Darwin driverkit-1 + 늘 있던 Darwin machdep/machine·ppc 조건 분기 머리 → **A** 셋. 기록: objects_confirmed 217→220 줄, functions 2435→2463, PROVENANCE 708→717(채택 SDK 머리 포함), MODIFICATIONS 262→265 줄.
- IOVPCodeDisplay: `s5p293-it4` `__text` 7067 B 0 차이(14 MATCH + 1 MATCH_UNVERIFIED), `__data`·`__const` L1d 일치, relcheck 0 — 그러나 zerofill_check 가 참조 섹션 `__text` 를 기호로만 배치해 “no symbol placement” 로 fail(ObjC `__text` 는 전역 기호 없음; `s5p293-zerofill-check-IOVPCodeDisplay-20261005.json`). 기록 못 함 → 07 에서 파일을 뺌(출처 행 없는 07 파일 금지, plan 253 선례; 최종본은 scratchpad 에 보관). plan 302 뒤 다시.

## 302. S5-P292 세부 계획 — zerofill_check 의 ObjC 참조 섹션 배치(`--place-from-l1`)와 `i386/IOVPCodeDisplay.m`(P)(코딩 전, 2026-10-05)

0. `10_tools/reconstruction/l1_compare.py`(plan 302 표시): 결과 JSON 에 `inputs`(이미지·목적 파일 경로별 SHA-256)를 더함 — 다른 출력·판정은 그대로.
1. `10_tools/reconstruction/zerofill_check.py`(plan 302 표시): 선택 인자 `--place-from-l1 L1.json`. L1 의 `inputs` 가 이번 `--image`·`--obj` 의 SHA-256 과 같아야 함(없거나 다르면 거부). 기호로 Δ 를 못 얻은 참조 섹션에 한해, L1 에서 그 섹션이 같은 색인·크기(> 0, 파일에 있는 섹션, zero-fill·리터럴 아님)이고 배치가 “given by objc metadata” 또는 “given by symbol”, byte_differences 0, refs_differ 0, refs_unverified 0 일 때만 Δ = L1 주소 − 목적 파일 섹션 주소. “inferred, verified by L1d” 는 쓰지 않음(참조에서 추정한 배치). 기호 Δ 가 있는데 L1 과 다르면 문제로 기록(fail). 결과에 섹션별 Δ 출처(symbol/l1) 를 남김. 인자 없으면 동작 불변.
2. 시험 `test_zerofill_l1place.py`: 양성 — IOVPCodeDisplay 인자 없이 fail·있으면 reference-inferred(출처 l1), C 대조 generalFuncs.c(`s5p284-it1`) 결과가 인자 유무로 같음(출처 symbol). 음성 — 같은 경로의 목적 파일 1 바이트 변경, 이미지 변경, L1 의 배치를 “inferred, verified by L1d” 로 바꿈, `inputs` 없음, 기호 섹션의 L1 주소를 바꿔 충돌 — 모두 거부·fail. 기존 `test_zerofill_conclude.py` 통과.
3. IOVPCodeDisplay: 07 `src/driverkit/libDriver/i386/IOVPCodeDisplay.m`(scratchpad 최종본, Darwin 본문 + D030 머리) 다시 넣고 iter_objc → zerofill(`--place-from-l1`, 알려진 배치 48 건 목록) → reference-inferred 면 record_objc P 모드.

### codex 교차검토 판정(2026-10-05, plan 302)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| L1 JSON 에 목적 파일 해시가 없어 묶음 확인 불가 | L1 키 `object, sections, functions, methods, object_verdict, object_reasons, placements` — 해시 없음(python) | ✅ l1_compare 에 `inputs` 추가(0 항) |
| “inferred, verified by L1d” 는 참조에서 추정한 배치 — 허용하지 말 것; 0 차이·미확인 0·크기·색인·비리터럴 조건 | l1_compare.py:222 `infer`(참조로 Δ 추정) 확인 | ✅ 1 항 좁힘 |
| 기호 Δ 충돌은 오류로 | zerofill_check source_deltas 확인 | ✅ |
| 시험 부족(같은 경로 변경·이미지 변경·배치 바꿈·필드 없음·충돌), generalFuncsPrivate 는 ObjC | 계획 2 항 확인; generalFuncsPrivate.m 은 .m | ✅ 2 항 넓힘, C 대조는 generalFuncs.c |
| plan 301 결과 블록 사실 맞음 | — | ✅ |

### 결과(2026-10-05, plan 302)

- 도구: `l1_compare.py` 결과에 `inputs`(이미지·목적 파일 SHA-256); `zerofill_check.py --place-from-l1`(L1 `inputs` 일치 필수, “given by objc metadata”/“given by symbol”·0 차이·참조 차이·미확인 0·같은 색인·크기·비리터럴·비 zero-fill 만, 기호 Δ 와 다르면 문제, `delta_source` 기록). 시험: 새 `test_zerofill_l1place.py` 8/8(양성 3: ObjC 인자 없이 fail·있으면 reference-inferred, C 대조 generalFuncs 불변; 음성 5: 같은 경로 목적 파일 변경·이미지 변경·추정 배치·inputs 없음·기호/L1 충돌), `test_zerofill_conclude.py` 8/8, `test_objc_compare.py` 13/13, `test_objc_nomethod.py` 5/5.
- 07 `libDriver/i386/IOVPCodeDisplay.m` 다시 넣음(scratchpad 최종본). `s5p294-it1`: `__text` 7067 B 0 차이(14 MATCH + 1 MATCH_UNVERIFIED), `__data`·`__const` L1d, relcheck 0; zerofill(`--place-from-l1`, 알려진 배치 48) [0x1e873c, 0x1e8748) reference-inferred(참조 4, Δ 0x1e5e48) → **P**. 새 알려진 배치 목록 `zerofill-known-s5p294-20261005.json`(49).
- 기록 중 record_objc P 모드 문구의 괄호 실수로 한 번 멈춤(그 전에 SDK 머리 채택 5 행만 씀 — 이 객체가 실제로 쓰는 머리라 유효); 고쳐 다시 실행. 기록: objects_partial 46→47 줄, functions 2463→2477(메서드 14; L1 의 `_gamma8` 은 `__const` 데이터), PROVENANCE 717→723(채택 SDK driverkit/IOFrameBufferDisplay.h·IODisplay.h·displayDefs.h 등 5 + 본 파일), MODIFICATIONS 265→266 줄.

## 303. S5-P293 세부 계획 — 커널 BSD 비공개 머리 6 개(작성, D030) + `Kernel/IOTokenRing.m`·`IODisplay.m`·`EventDriver.m`·`EventInput.m`·`EventIO.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

0. 원본(분류 2 차 L1, Darwin 본문 + 진단 `#line` 모두 OBJECT_MATCH):
   - "Kernel/IOTokenRing.m" `__text` [0x1aaea0, 0x1abaeb) 3147 B 함수 41(`__data`·`__const` L1d 포함)
   - "Kernel/IODisplay.m" [0x1af058, 0x1af23f) 487 B 11
   - "Kernel/EventDriver.m" [0x1af240, 0x1b1e1a) 11226 B 39(`__data`·`__const`)
   - "Kernel/EventInput.m" [0x1b1e1c, 0x1b34be) 5794 B 43
   - "Kernel/EventIO.m" [0x1b34c0, 0x1b37bc) 764 B 11(`__const`)
1. 머리: 이 다섯은 SDK 에 없는 커널 비공개 BSD 머리를 씀 — bsd/dev/evio.h, bsd/dev/machine/ev_private.h, bsd/dev/i386/ev_private.h, bsd/dev/kmreg_com.h, bsd/dev/i386/ConsoleSupport.h, bsd/net/tokensr.h(이 경로들은 SDK 에 없음 — 다만 SDK 에는 bsd/dev/machine/evio.h 가 있어 ARCH_INCLUDE 로 아키텍처별 evio.h 를 들이며, 미러에는 m68k/evio.h 만 있고 i386 판이 없음; bsd-set 규칙상 Darwin 에서 가져올 수 없음). 같은 이름 확인: NeXTMach 에는 nextdev/evio.h 만 있음 — 진단 `s5p295-nm-2`(EventIO, NeXTMach evio.h)는 옛 m68k IPC 머리(sys/port.h·sys/message.h → 생성 머리 mach_ipc_xxxhack.h)를 요구해 컴파일 실패, Darwin i386/ev_private.h 와 DefaultWC* 매크로가 겹침 → 4.2 커널이 쓴 판과 다른 옛 판(plan 292 의 “일치하는 원문 판 없음” 선례와 같은 판단). 나머지 5 개는 Mach4·NeXTMach 에 같은 이름 없음.
   → D030(Darwin 전용 파일, kernel/machdep 밖, 대응 판 없음)에 따라 `07_kernel/nextdev_private/bsd/dev/…`·`bsd/net/tokensr.h` 에 Darwin 0.1 본문 그대로 + 프로젝트 작성 머리 주석(“nearly the same as Darwin 0.1 kernel/bsd/…”, Apple·NeXT 고지 없음). stage_headers 는 bsd-set 에서 nextdev_private/bsd/X 를 SDK 보다 먼저 읽음(plan 132). PROVENANCE 파일별 행(authored, D030).
2. 방법(사용자 결정 뒤): 머리 6 개를 넣은 뒤 각 .m(mkfinal.py, D030 머리) → iter_objc(RUNIN) → 07 스테이징 매니페스트에 Darwin 커널 뿌리 BSD 머리가 남지 않았는지 확인 → relcheck → record_objc(A 예상 다섯).
3. 검증 기준: 머리 채택 뒤 새로 빌드한 L1 에서 다섯 모두 OBJECT_MATCH 이고 매니페스트의 bsd/dev·bsd/net 머리가 07(nextdev_private)·SDK 에서만 옴; 조건 분기 때문에 남는 미해결(예 bsd/dev/ppc/ev_private.h)은 목록으로 남기고 i386 컴파일에 쓰이지 않음을 확인. 하나라도 어긋나면 그 모듈만 멈추고 재계획.

### codex 교차검토 판정(2026-10-05, plan 303)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 다섯 객체 범위·크기·함수 수 맞음, 여섯 머리 사용 | 앞서 python(L1 다섯)·오버라이드 목록 | ✅ |
| SDK 에 bsd/dev/machine/evio.h(ARCH_INCLUDE)와 m68k/evio.h 가 있음 — “SDK 에 없음”은 정확한 경로로 한정 | `ls` SDK bsd/dev/machine: event.h·evio.h·evsio.h; bsd/dev/m68k/evio.h 있음, bsd/dev/i386 에는 없음 | ✅ 1 항 고침 |
| NeXTMach evio.h 를 직접 대체로 쓰지 않는 근거는 충분하나 4.2 원본 머리를 증명하지는 않음 | s5p295-nm-2 00.err(mach_ipc_xxxhack.h), DefaultWC* 재정의 | ✅ 문구 존중 |
| D030 은 “바이트로 쓴 글이 Darwin 과 같아진 경우”를 다룸 — 머리 6 개를 통째로 옮기며 고지를 빼는 것은 사용자 결정 필요 | DECISIONS.md:34 D030 문구 | ✅ 사용자 결정 요청 |
| stage_headers 는 실제 쓰인 철자로 nextdev_private 를 잡음; machine/ev_private.h 는 `#if __i386__` 선택 | stage_headers.py:168–180, Darwin machine/ev_private.h:29–35 | ✅ |
| 조건 분기의 미해결(ppc) 처리와 채택 뒤 새 빌드 L1 을 기준에 넣을 것 | — | ✅ 3 항 고침 |

### 결과(2026-10-05, plan 303 — IOTokenRing 제외)

- 사용자 결정 D032(“D030 처럼 작성(고지 없음)”) 기록. 머리 6 개 `07_kernel/nextdev_private/bsd/dev/evio.h`·`machine/ev_private.h`·`i386/ev_private.h`·`kmreg_com.h`·`i386/ConsoleSupport.h`, `bsd/net/tokensr.h`(Darwin 본문 그대로, D032 머리 주석), PROVENANCE 6 행(731→737; codex 판정 뒤 열을 바로잡음 — revision = Darwin kernel-1.tar.gz SHA-256, original_path = darwin01/kernel/<경로>, evidence = 쓰는 객체의 근거 문서), MODIFICATIONS 6 행(270→276).
- 07 `libDriver/Kernel/IODisplay.m`·`EventDriver.m`·`EventInput.m`·`EventIO.m`(mkfinal.py): `s5p295-it2`–`it5` OBJECT_MATCH(L1 항목 11·39·43·11 — EventDriver·EventIO 는 그중 하나씩이 `__TEXT,__const` 데이터 `_init_msg.157`·`_coalesce.118` 이라 함수는 11·38·43·10), relcheck 0; 매니페스트의 bsd/dev·bsd/net 머리는 07(nextdev_private)·SDK 뿐. 미해결 목록은 닫힘이 모든 조건 분기를 따라간 결과로 ppc 만이 아님(hppa·sparc ConsoleSupport.h, machdep/m88k/xpr.h, mon/mon_service.h, vm/vm_external.h, machine/cpu_data.h 등 — 앞선 커널 객체들과 같은 종류); i386 빌드는 성공 → **A** 넷.
- record_objc 보강(scratchpad; 이전 판 record_objc_v2.py): `@implementation` 안에서는 `;` 로 끝나는 줄도 정의(IODisplay.m 의 `- (IOConsoleInfo *)allocateConsoleInfo;` 꼴), ObjC 모듈 안 C 함수(정적 EventListener·EvPeriodicCallout) 행, 메서드 없는 모듈(EventIO)은 `__text` 기호 배치 허용. 첫 시도에서 IODisplay 는 머리 채택 1 행(driverkit/machine/driverTypesPrivate.h, 실제 사용) 뒤 멈춤 — 다시 실행. 메서드 인용 162 행 전부 해당 `@implementation` 안(python, 오류 0). 기록: objects_confirmed 220→224 줄, functions 2477→2579, PROVENANCE 723→731(채택 머리 포함), MODIFICATIONS 266→270 줄.
- IOTokenRing(`s5p295-it1`): 스테이징 실패 — tokensr.h 가 들이는 SDK `objc/hashtable.h` 는 미러·실기 모두 `hashtable2.h` 를 가리키는 심볼릭 링크(실기 `ls -l`, 내용 SHA-256 b013a36b… = 목록의 hashtable2.h)인데 실기 해시 목록은 정규 파일만 담아 stage_headers 가 거부. iter_objc 가 stage_headers 반환값을 보지 않아 깨진 스테이지로 빌드까지 감(고침 필요). 07 의 IOTokenRing.m 은 빼 둠(출처 행 없는 07 파일 금지).

## 303a. S5-P293a 세부 계획 — SDK 심볼릭 링크 별칭(objc/hashtable.h)과 IOTokenRing(코딩 전, 2026-10-05)

1. `stage_headers.py`(plan 303a 표시): 실기 목록의 `target_symlinks`(예 `/NextDeveloper/Headers/objc/hashtable.h` → `hashtable2.h`)를 근거로 삼음. nextdev 뿌리 파일 확인에서 경로가 목록에 정규 파일로 없을 때, 그 경로가 `target_symlinks` 에 정확히 있고, 대상이 Headers 안의 정규 파일(링크 사슬·밖으로 나감 거부)이며, 대상의 목록 해시가 읽은 파일 내용과 같을 때만 받아들이고 매니페스트에 “real-machine symlink to <대상>” 을 남김. 미러 경로 자체도 같은 대상을 가리키는 링크여야 함. 07_kernel/nextdev 사본(정규 파일)은 같은 규칙으로 확인하고 “materialized copy of the real-machine symlink” 로 기록. 범위: 미러의 심볼릭 링크는 2 개(X11 → Headers 밖, objc/hashtable.h)뿐이고 mach-set·bsd-set 이름에는 링크가 없음(python 확인) — mach_pick 의 `_no_symlink` 거부와 bsd_pick 은 그대로; `--list` 는 지금처럼 확인 없이 목록만 냄(기존 동작).
2. record_objc 의 nextdev 채택도 같은 별칭 규칙(PROVENANCE 에 링크 사실 기록). iter_objc 는 stage_headers 반환값이 0 이 아니면 멈춤.
3. 시험: stage_headers 단위 시험 통과 + `--list`/스테이징으로 IOTokenRing 성공, 다른 확정 객체 회귀 1 개.
4. IOTokenRing: 07 에 다시 넣고 iter_objc → 매니페스트 기준(plan 303 3 항) → relcheck → record_objc(A 예상).

### codex 교차검토 판정(2026-10-05, plan 303 결과·303a)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| plan 303 결과 수치(A 4 행·머리 6 행·224/2579/737) 맞음 | 앞서 기록 출력 | ✅ |
| 미해결이 ppc 만이 아님(hppa·sparc·m88k·mon·vm_external 등) | python: it2–it5 매니페스트 unresolved 목록 | ✅ 결과 문구 고침 |
| L1 항목 39·11 중 하나씩은 `__const` 데이터 — 함수 38·10 | L1 functions(`_coalesce.118` `__TEXT,__const` 확인), functions.tsv 증가 38·10 | ✅ 고침 |
| 별칭 규칙은 실기 목록의 symlink 기록을 근거로, 정확한 별칭·대상·포함·사슬 거부 | s4c 목록 `target_symlinks` 에 `objc/hashtable.h → hashtable2.h` 있음(python) | ✅ 303a 1 항 고침 |
| `--list`·mach_pick·bsd_pick 경로도 같은 확인을 | 미러 링크 2 개뿐(X11·hashtable.h), mach/bsd 이름엔 없음(python) | ⚖️ 해당 경로에 링크가 없어 범위 밖으로 명시(1 항), `--list` 는 기존 동작 |
| PROVENANCE 6 행 열 의미 틀림(revision 칸에 결정 번호, original_path “none”, 근거 문서 엉뚱), MODIFICATIONS 없음 | PROVENANCE 머리 `destination·source_id·revision_or_sha256·original_path·license_reference·changes·evidence`, 행 확인 | ✅ 바로잡음(행 수 그대로 737), MODIFICATIONS 6 행 추가 |

### 결과(2026-10-05, plan 303a)

- `stage_headers.py`: `symlink_alias()`(실기 목록 `target_symlinks` 의 정확한 항목, 대상은 Headers 안 정규 파일·사슬/밖 거부) — nextdev 뿌리 확인에서 목록에 정규 파일로 없는 경로를 그 별칭 규칙으로만 받아들이고, 미러는 같은 대상을 가리키는 링크여야 함; 매니페스트 “real-machine symlink to …”(07 사본이면 “materialized copy …”). 시험 `test_stage_headers_subst.py` 19/19; 단위 확인 hashtable.h → hashtable2.h, hashtable2.h·X11 은 None.
- scratchpad: iter_objc 는 스테이징 실패 시 멈춤, record_objc 의 nextdev 채택은 별칭 인식(PROVENANCE 에 “materialized copy of the real-machine symlink” 표기).
- 07 `libDriver/Kernel/IOTokenRing.m` 다시 넣음: `s5p296-it1` OBJECT_MATCH(함수 30 + `__const` 문자열 11), relcheck 0; 매니페스트 bsd/net/tokensr.h 는 nextdev_private, objc/hashtable.h 는 별칭 → **A**. 기록: objects_confirmed 224→225 줄, functions 2579→2609, PROVENANCE 737→744(07_kernel/nextdev/objc/hashtable.h 등 채택 + 본 파일; tokensr.h 행의 근거 문서를 x86-IOTokenRing.md 로 갱신), MODIFICATIONS 276→278 줄.
- 회귀 `s5p296-rg1`(NXSpinLock, 바뀐 stage_headers): OBJECT_MATCH; 섹션 바이트는 s5p287-it1 과 모두 같고, 목적 파일 해시 차이는 stab 의 실행 디렉터리 절대 경로(RUNIN `@R`)뿐(python 비교).

## 304. S5-P294 세부 계획 — 절대 모듈 이름 빌드(D033, kr_run `ABSROOT`)와 첫 객체들(코딩 전, 2026-10-05)

진단(`s5p297-NN-*`, scratchpad `triage_abs.py`, Darwin 0.1 kernel/<경로> 본문 + 진단 `#line`, 커널 꼴 -fwritable-strings 유지): 절대 이름 19 개 중 OBJECT_MATCH 4 — driverkit/KernLock.m(`__text` 0x17e70c 305 B 8), driverkit/KernBusInterrupt.m(0x17facc 1291 B 12), driverkit/KernStringList.m(0x181a60 568 B 6), bsd/dev/i386/EventSrcPCPointer.m(0x1a00e4 2531 B 15) 합 4695 B(python); NOT_MATCH 5(KernBus·KernBusMemory·KernDevice·KernDeviceDescription·kmGraphics), 빌드 실패 10. 모두 Darwin 커널 트리에 같은 경로 파일 있음.

1. 실기(사용자 작업): `/BinarySourceCache_Mario1A/mk/mk-183.34.4` → `/ndrv/openstep-kernel-remade/08_build/runs/ABSROOT` 심볼릭 링크(디렉터리 `/BinarySourceCache_Mario1A/mk` 만들기 포함). 지금 실기에 `/BinarySourceCache_Mario1A` 없음(2026-10-05 gcds `ls -ld /BinarySourceCache_Mario1A` → “/BinarySourceCache_Mario1A not found”). `08_build/runs/` 는 git 무시 대상(.gitignore:63).
2. `kr_run.py`(plan 304 표시): 명령 파일 지시 `ABSROOT`(인자 없음, 한 번만).
   - prepare: `src/src/.krabs` 표지 파일(내용 = 실행 ID)을 walk_regular 전에 만들어 input.expected·전후 재해시에 들게 함.
   - run.sh(LOCK·입력 해시 확인 뒤): `08_build/runs/ABSROOT` 가 있으면 심볼릭 링크일 때만 지우고(정규 파일·디렉터리면 fail), `ln -s <ID>/src/src` 로 만들고 결과 확인; `/BinarySourceCache_Mario1A/mk/mk-183.34.4/.krabs` 내용이 실행 ID 와 같은지 확인, 아니면 fail.
   - 정리: ABSROOT 링크를 지우는 `absclean` 을 모든 fail 경로·정상 끝·`trap`(HUP INT TERM)에서 LOCK 해제 전에 부름; 정리 실패 시 그 사실을 FAILED 에 남김. 충돌로 남은 링크는 다음 잠긴 실행이 위 규칙으로 처리.
   - RUN·RUNIN 인자 중 `@ABS/` 로 시작하는 단어만 `/BinarySourceCache_Mario1A/mk/mk-183.34.4/` 로 바꿈(ABSROOT 지시가 있을 때만; 그 밖의 `@ABS` 거부).
   - ABSROOT 없는 명령 파일은 동작 불변. 시험: parse 양성·음성(ABSROOT 없이 `@ABS`, ABSROOT 두 번, 단어 중간 `@ABS`) + run.sh 생성 줄 확인, 기존 시험 그대로.
   - 실기 링크가 없는 지금(아래 1 의 확인 출력) 실제 실행은 사용자 링크 뒤.
2a. 탐침(링크 뒤, 기록 전): `#line` 없이 `@ABS/driverkit/KernLock.m` 을 컴파일해 `__module_info` 의 이름이 정확히 “/BinarySourceCache_Mario1A/mk/mk-183.34.4/driverkit/KernLock.m” 인지 확인(cc·cpp 가 링크를 실제 경로로 바꾸는지 검사). 다르면 멈추고 재계획.
3. 07 배치: 커널 트리 .m 은 원래 경로 그대로 `07_kernel/src/<경로>`(예 `src/driverkit/KernLock.m`, `src/bsd/dev/i386/EventSrcPCPointer.m`) — 스테이징 src/src/<경로> = ABSROOT/<경로> 이므로 cc 에 `@ABS/driverkit/KernLock.m` 을 주면 모듈 이름이 원본과 같음. 빌드 꼴은 커널(-fwritable-strings 유지, -O3)이며 스크래치 iter_objc_abs.py 로.
4. 첫 객체(사용자 링크·탐침 뒤): 위 OBJECT_MATCH 4 개를 하나씩 — 원본 바이트로 확인한 본문(진단에서 Darwin 0.1 kernel/<경로> 와 거의 같음; D030 으로 공개). 이 파일들은 Darwin kernel 트리(driverkit/·bsd/dev/i386/) 파일로 Mach4·NeXTMach 에 같은 이름 없음(`find 01_resources/upstream -name` 확인: Darwin kernel 판만, EventSrcPCPointer.m 은 ppc 판도 있음) → D029(machdep 는 아님)·D030(“Darwin kernel/machdep 밖”) 중 어느 쪽인지 계획에서 분류: driverkit/·bsd/dev/ 는 kernel/machdep 밖이라 D030(작성, 고지 없음, nearly the same) 이 기본; 다르게 판단되면 사용자 결정.

### codex 교차검토 판정(2026-10-05, plan 304)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| ABSROOT 는 LOCK 안에서만 만들고 지우며, 기존 항목이 링크인지 확인·`rm`/`ln` 결과 확인·모든 실패·신호에서 정리·정리 뒤 LOCK 해제 | kr_run.py 의 fail()·LOCK 순서 확인 | ✅ 2 항 고침 |
| 표지 파일을 walk_regular 전에 만들어 입력 해시에 넣을 것; `find stage` 에는 안 들어감 | prepare 순서 확인 | ✅ |
| 링크를 지난 절대 경로가 모듈 이름에 그대로 남는지는 미검증(진단은 `#line`) | 진단 원본 첫 줄이 `# 1 "…"` 임 | ✅ 2a 탐침 추가 |
| D030 이 이 넷을 덮음, 새 결정 불필요; “본문은 Darwin” 표현은 바이트로 확인한 본문으로 | D029·D030 행 | ✅ 4 항 문구 고침 |
| 수치(19 = 4/5/10, 4695 B, .gitignore:63) 맞음; 실기 부재의 근거 출력이 계획에 없음 | 이 세션 gcds 출력 “not found” | ✅ 1 항에 명령·출력 적음 |

### 결과(2026-10-05, plan 304 — 도구 부분)

- `kr_run.py`(plan 304 표시): `ABSROOT` 지시·`@ABS/` 치환(RUN·RUNIN), prepare 가 `src/src/.krabs`(실행 ID)를 입력 해시 전에 만듦, run.sh: 도구 해시 확인 뒤 기존 ABSROOT 가 링크면 지우고(링크 아닌 것이면 fail) `ln -s <ID>/src/src`, 절대 경로로 표지 확인, `absclean` 을 fail()·정상 끝(LOCK 해제 전)·`trap 'fail signal' 1 2 15` 에서. ABSROOT 없는 명령 파일은 그대로. 실기 sh 가 `[ -h ]`·`trap`·역따옴표 비교를 지원함을 gcds 로 확인(h-ok, cmp-ok).
- 시험: 새 `test_kr_run_absroot.py` 12/12(임시 RUNS/REGISTRY·도구 해시 대역; 실제 REGISTRY 불변 확인), `test_kr_run_runin.py` 10/10, `test_kr_run_tools.py` 7/7.
- 다음: 사용자 실기 링크 → 2a 탐침(`#line` 없이 모듈 이름 확인) → 첫 객체.
- 실기 링크(사용자 지시 “telnet 으로 만드세요”, 2026-10-05): tools/nxrun.sh(root) 로 `mkdir /BinarySourceCache_Mario1A`, `mkdir …/mk`, `ln -s /ndrv/openstep-kernel-remade/08_build/runs/ABSROOT /BinarySourceCache_Mario1A/mk/mk-183.34.4` — 만들기 전 `ls -ld` “not found”, 뒤 `ls -ld` 로 링크 확인.
- 2a 탐침 `s5p298-probe-1`(scratchpad wipbuild_abs.py: ABSROOT + `@ABS/driverkit/KernLock.m`, Darwin 0.1 kernel/driverkit/KernLock.m 원문 그대로 — `#line` 없음, 커널 꼴 -fwritable-strings 유지): 목적 파일의 모듈 이름 = “/BinarySourceCache_Mario1A/mk/mk-183.34.4/driverkit/KernLock.m”(cc 가 링크를 실제 경로로 바꾸지 않음), ObjC L1 OBJECT_MATCH(메서드 8, `__module_info`·`__symbols` 메타데이터 배치 0 차이); 실행 끝에 ABSROOT 링크 지워짐 확인. → D033 방식 확인.
- 07 `src/driverkit/KernLock.m`·`KernBusInterrupt.m`·`KernStringList.m`, `src/bsd/dev/i386/EventSrcPCPointer.m`(D030 머리; scratchpad iter_objc_abs.py: ABSROOT + `@ABS/<경로>`, 커널 꼴): `s5p298-it1`–`it3`·`it6` OBJECT_MATCH(메서드 8·12·6, EventSrcPCPointer 15 항목 = 메서드 14 + `__const`), relcheck 0 → **A** 넷. 스테이징: Kern*.h(src/driverkit)는 비 BSD 이름의 기존 07→Darwin 규칙(스테이징만), EventSrcPCPointer 는 bsd/dev/i386/EventSrcPCPointer.h·PCPointer.h·PCPointerDefs.h 를 D032 작성 머리로 `07_kernel/nextdev_private/bsd/dev/i386/` 에 둠(PROVENANCE 743→746, MODIFICATIONS 277→280).
- 실패 ID: `s5p298-it4`(07 에 `src/bsd/dev/i386` 디렉터리가 없어 복사 실패 → 스테이저가 Darwin 사본으로 넘어감; 출력 없음·쓰지 않음), `s5p298-it5`(EventSrcPCPointer.h 없음) — 재사용 안 함.
- 고지 잔류 수정: mkfinal 이 맨 앞 `//` 줄에서 건너뛰기를 멈춰 EventSrcPCPointer.m 에 NeXT 저작권·HISTORY `/* */` 블록이, Darwin 판 그대로 옮긴 PCPointer.h 에 `//` 저작권 블록이 남았음 → 둘 다 지움(주석이라 바이트 영향 없음; PCPointer.h PROVENANCE SHA 갱신). mkfinal 은 이제 본문에 Copyright·All rights reserved·APPLE_LICENSE 가 남으면 멈춤. 이미 기록된 작성 파일 전부 grep — 남은 것은 Darwin 바탕(고지 유지)으로 기록된 driverkit/ddm.c 뿐.
- 기록: objects_confirmed 225→229 줄, functions 2609→2649, PROVENANCE 746→750, MODIFICATIONS 280→284 줄.

## 305. S5-P295 세부 계획 — `src/driverkit/KernBus.m`(P)·`src/driverkit/KernDevice.m`(A)(D024·D027·D030·D033; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 kernel/driverkit/KernBus.m·KernDevice.m(같은 이름은 Darwin 만). 진단 `s5p297-02-*`·`-05-*`(Darwin 본문 + 진단 `#line`, 커널 꼴).

0. 원본(L1·python):
   - "…/driverkit/KernBus.m" `__text` [0x17e840, 0x17f749) 3849 B, 메서드 51(45 MATCH + 6 MATCH_UNVERIFIED — `__bss` 참조), `00` 3 B 뒤 0x17f74c 함수 머리; `__data` 8 B(0x1e0fc8) L1d; `__bss` 12 B 참조로 [0x1e7318, 0x1e7324) 추정.
   - "…/driverkit/KernDevice.m" [0x17ffd8, 0x180a5f) 2695 B, `__text` 항목 25(MATCH 24 + `_IOSendInterrupt` MATCH_UNVERIFIED), `00` 1 B 뒤 0x180a60; `__const` 88 B(0x1d1390)·`__data` 24 B(0x1e0fd0) L1d.
1. KernDevice 수정(plan 305 표시, 바이트가 요구): `IOSendInterrupt` 끝의 `thread_call_enter(&msg->callout);` → 원본은 `call _calloutEntryDispatch`(0x1802d7, 인자 `lea eax,[ebx+0x34]` = &msg->callout); 원본 기호표에 `_thread_call_enter` 없음. 07 bsd/kern/subr_log.c:63 선례대로 지역 선언 `extern void calloutEntryDispatch(void *);` 를 두고 호출을 바꿈. callout 필드 초기화(func·spec_proto·status)는 이미 바이트 일치라 그대로.
2. KernBus: 수정 없음. `__bss` 는 zerofill(`--place-from-l1`, 알려진 배치 49 건 목록)으로 확인 → reference-inferred 면 **P**.
3. 방법: 07 `src/driverkit/KernBus.m`·`KernDevice.m`(mkfinal.py — 고지 검사 포함, D030 머리) → iter_objc_abs(ABSROOT) → 매니페스트 확인(BSD 이름은 07·SDK 만; src/driverkit 비공개 머리는 기존 07→Darwin 규칙) → relcheck → KernDevice A, KernBus zerofill 뒤 P(record_objc).

### codex 교차검토 판정(2026-10-05, plan 305; 첫 요청은 codex 용량 초과로 실패, 재요청)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·크기·채움·데이터·const·bss 주소, Bus 메서드 51 맞음; “모두 MATCH” 는 45 + 6 | python Counter(45 MATCH, 6 MATCH_UNVERIFIED) | ✅ 문구 고침 |
| 원본 0x1802d3–0x1802d7 `[ebx+0x34]` 를 넣고 `_calloutEntryDispatch` 호출; 다른 Device 항목은 일치 | odis 0x1802bb–0x1802e5, 스크래치 relcheck 불일치 1(오프셋 0x300) | ✅ |
| 지역 선언이 최소·선례와 같음 | subr_log.c:63, callout.c:437 | ✅ |
| record_objc 근거 문서가 C 함수까지 “methods” 로 셈 | record_objc.py:123 틀 확인 | ✅ 틀을 “N functions (M methods)” 로 고치고 기존 근거 6 개(EventDriver·EventInput·EventIO·IOTokenRing·KernLock·KernBusInterrupt) 바로잡음 |

### 결과(2026-10-05, plan 305)

- 07 `src/driverkit/KernBus.m`(Darwin 본문 + D030 머리)·`KernDevice.m`(+ plan 305 두 줄). `s5p299-it1`: KernBus `__text` 0 차이(45 MATCH + 6 MATCH_UNVERIFIED), relcheck 0; zerofill(`--place-from-l1`, 알려진 배치 49) [0x1e7318, 0x1e7324) reference-inferred(참조 10, Δ 0x1e565c) → **P**. `s5p299-it2`: KernDevice OBJECT_MATCH, relcheck 0 → **A**.
- 새 알려진 배치 목록 `zerofill-known-s5p299-20261005.json`(50).
- 기록: objects_partial 47→48 줄, objects_confirmed 229→230 줄, functions 2649→2725, PROVENANCE 750→755(채택 머리 포함), MODIFICATIONS 284→286 줄.

## 306. S5-P296 세부 계획 — `src/driverkit/KernBusMemory.m`·`KernDeviceDescription.m`(D024·D027·D030·D033; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 kernel/driverkit/KernBusMemory.m·KernDeviceDescription.m(Darwin 만). 진단 `s5p297-03-*`·`-06-*`(Darwin 본문, NOT_MATCH), `s5p300-d1`·`s5p300-e1`·`-f1`·`-g1`(ABSROOT, `#line` 없음).

0. 원본(python): "…/driverkit/KernBusMemory.m" `__text` [0x17f74c, 0x17fac9) 893 B 항목 8(메서드 7 + 정적 _KernBusMemoryCreateMapping), `00` 3 B 뒤 0x17facc(KernBusInterrupt, 기록됨). "…/driverkit/KernDeviceDescription.m" [0x180a60, 0x181a60) 4096 B 항목 30(메서드 26 + 정적 C 함수), 채움 0 B 로 KernStringList 0x181a60(기록됨, 메서드 IMP); `__data` 181 B(0x1e0fe8) L1d.
1. KernBusMemory 수정(plan 306 표시): `_KernBusMemoryCreateMapping` 에서 `length = round_page(length);` 를 `vm_map_find` 앞에서 `virtAddr = trunc_page(*destAddr);` 바로 뒤로 옮김 — 원본은 find 에 반올림 전 length(esi)를 넘기고(0x17f78d push esi, 0x17f797 call _vm_map_find), find 뒤에 `~page_mask & *destAddr`·`(page_mask + length) & ~page_mask` 를 함께 계산. 진단 `s5p300-d1` OBJECT_MATCH(8 항목).
2. KernDeviceDescription 수정(plan 306 표시): `-[KernDeviceDescription(Parsing) _isShared:]` — 원본(0x181730, 84 B)은 `sprintf(buf, "Share %s", key)` 뒤 `self` 에 셀렉터 `stringForKey:`(메시지 참조 0x1f932c → “stringForKey:”, python) 를 보내고, `freeString:` 없이 `'y'`/`'Y'` 면 1, 아니면 0 을 곧장 돌려줌. Darwin 은 `[_configTable valueForStringKey:]`·`freeString:`·`result` 변수. 시험한 꼴: `result` 유지(e1, 80 B), 판정식 직접 return(f1, 레지스터로 계산), `if ((shareKey = [self stringForKey:buf]) && ((*shareKey == 'y') || (*shareKey == 'Y'))) return YES; else return NO;`(g1) → OBJECT_MATCH(30 항목). g1 꼴을 씀(`result` 선언 제거 포함).
3. 방법: 07 `src/driverkit/KernBusMemory.m`·`KernDeviceDescription.m`(mkfinal.py 고지 검사, D030 머리 + 위 수정) → iter_objc_abs(ABSROOT) → 매니페스트 확인 → relcheck → record_objc(A 예상 둘).

### codex 교차검토 판정(2026-10-05, plan 306; 기본 모델 두 번 용량 초과 실패 → 사용자 지시로 gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·항목 수·채움(893 B·8·3 B / 4096 B·30·0 B), `__data` 181 B 0x1e0fe8 | 앞서 python 출력 | ✅ |
| 0x17f78d `push esi`(반올림 전 length)·0x17f797 call — 반올림을 find 뒤로 옮기는 것이 필요·최소 | odis2 0x17f74c–0x17f7a0 출력 | ✅ |
| 0x1f932c → 0x202420 “stringForKey:”, `freeString:` 없음, 원본 84 B | macho.json 섹션 표로 읽은 python 출력 | ✅ |
| 최종 빌드 relcheck 결과를 남길 것 | — | ✅ 아래 결과에 남김 |

### 결과(2026-10-05, plan 306)

- 07 `src/driverkit/KernBusMemory.m`·`KernDeviceDescription.m`(mkfinal.py 고지 검사, D030 머리 + plan 306 수정). `s5p301-it1`·`it2`(ABSROOT) OBJECT_MATCH(8·30 항목), relcheck 0·0 → **A** 둘.
- 기록: objects_confirmed 230→232 줄, functions 2725→2763, PROVENANCE 755→757, MODIFICATIONS 286→288 줄.

## 307. S5-P297 세부 계획 — `libDriver/Kernel/SCSIGeneric.m`(D024·D027·D030·D031) + 객체별 빌드 정의 `-DMACH_USER_API`(코딩 전, 2026-10-05)

0. 원본(python): 모듈 "Kernel/SCSIGeneric.m"(objc.json 0x2091bc) `__text` [0x1ae7c8, 0x1af058) 2192 B 항목 22, 채움 0 B 로 IODisplay 0x1af058(기록됨, 메서드 IMP); `__data` 8 B(0x1e517c) L1d, `__cstring` 134 B 내용 확인.
1. 진단: Darwin 본문(분류 `s5p291-19-*`) NOT_MATCH — Darwin 이 더한 메서드 `- registerLoudly`(원본 메서드 목록에 없음) 때문. 그 메서드를 뺀 `s5p302-sg1`: `__text` 22 MATCH, 그러나 `__inst_meth`·`__cat_inst_meth` 에서 참조 2 개씩 다름 — 메서드 형식 문자열의 `client` 인자: 원본 `I`(unsigned int), 빌드 `^{vm_map=…}`(python 으로 objc.json 과 빌드 메서드 목록 비교; executeRequest:buffer:client:senseBuf: 등). 07 nextdev_private/mach/mach_types.h(plan 136 작성 분기 `_KERNEL && !MACH_USER_API`)가 `vm_task_t = vm_map_t` 를 줌; SDK 공개 판은 `task_t = mach_port_t`, `vm_task_t = task_t`. SDK 판을 통째로 쓰면(`s5p302-sh1`) kern_types.h·ipc_types.h 와 형 충돌. `-DMACH_USER_API` 를 더한 `s5p302-si1` → **OBJECT_MATCH**(22 항목, 모든 `__OBJC`).
2. 이 정의를 libDriver 공통 꼴로 할 수 있는지 회귀(`s5p302-rm1`–`rm15`·`rc1`–`rc10`, 기록된 libDriver 25 개를 `-DMACH_USER_API` 로): 24 개는 기록 때와 같은 판정, **generalFuncs 는 `_IOFree` 가 DIFF**(kfree 인자 레지스터 eax→edx — 원형 보임 여부가 바뀜). → 공통 꼴이 아님. 원본 바이트(형식 문자열 `I`)가 요구하는 것은 **공개 포트 형 `vm_task_t`** 이고, `-DMACH_USER_API` 는 plan 136 분기를 통해 그것을 재현하는 객체별 빌드 정의일 뿐 원본이 이 매크로를 썼다는 사실은 아님(SDK 판은 조건 없이 공개 형 — 더 나은 4.2 조건의 근거는 없음). 선례: plan 293 `--public-sdk`, 객체별 빌드 꼴 기록. 근거 사본: 회귀 출력 `09_validation/reconstruction/s5p302-regress-mach-user-api-20261005.txt`, si1 비교 `s5p302-si1-l1-SCSIGeneric-F-20261005.json`.
3. 수정(plan 307 표시): SCSIGeneric.m 에서 `- registerLoudly` 메서드(4 줄)를 뺌 — 원본 메서드 목록·`__text` 에 없음. 그 밖은 Darwin 본문 그대로.
4. 도구(scratchpad): iter_objc 의 `EXTRA_DEFS`(지금 진단용)를 기록용으로 씀 — build_note 에 `-DMACH_USER_API` 와 근거를 남김. record_objc 는 그대로.
5. 방법: 07 `src/driverkit/libDriver/Kernel/SCSIGeneric.m`(mkfinal 고지 검사, D030 머리 + 3) → `EXTRA_DEFS=-DMACH_USER_API` iter_objc → 매니페스트 → relcheck → record_objc(A 예상).

### codex 교차검토 판정(2026-10-05, plan 307; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| objc.json 의 executeRequest:… client 형식 `I`, 소스 형은 vm_task_t, registerLoudly 는 원본 목록에 없음, si1 cmd 에 `-DMACH_USER_API` | objc.json:7254–7258 열람, 앞서 python 비교 | ✅ |
| 바이트는 공개 포트 형을 요구할 뿐 매크로 자체는 원본 사실이 아님 — 문구를 그렇게 | SDK mach_types.h:167–180 조건 없음 확인 | ✅ 2 항 문구 고침 |
| registerLoudly 제거는 필요·최소 | Darwin SCSIGeneric.m:79–82 | ✅ |
| 회귀 출력·si1 비교가 scratchpad 에만 있음 — 근거로 남길 것 | — | ✅ 09_validation 으로 복사 |

### 결과(2026-10-05, plan 307)

- 07 `libDriver/Kernel/SCSIGeneric.m`(Darwin 본문 − registerLoudly + D030 머리, plan 307 표시). `s5p303-it1`(`EXTRA_DEFS=-DMACH_USER_API`, RUNIN) OBJECT_MATCH(22 항목), relcheck 0 → **A**. build_note 에 객체별 정의와 근거 기록.

## 308. S5-P298 세부 계획 — `libDriver/IODirectDevice.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/IODirectDevice.m(본문 바탕); 머리 SDK driverkit/IODirectDevice.h(07 nextdev — 이 클래스에 `- deviceDescription`·`- setDeviceDescription:` 선언). Mach4·NeXTMach 같은 이름 없음.

0. 원본(python): 모듈 "IODirectDevice.m"(objc.json 0x2090bc, 클래스 1·카테고리 4) `__text` [0x1a82e8, 0x1a8cf8) 2576 B `__text` 항목 28(정적 _IODirectDeviceThread 0x1a82e8 + 메서드 27; L1 의 29 번째 항목은 `__const`), 앞 `00` 3 B, 끝 채움 0 B 로 NXSpinLock 0x1a8cf8(기록됨); `__const` 24 B(0x1d5c60) L1d, `__cstring` 119 B.
1. 진단: Darwin 본문(분류) NOT_MATCH — 메서드 크기 6 곳 다름. 원본은 Darwin 이 뒤에 더한 것이 없는 판:
   ① `IODirectDevicePrivate` 의 `local_device_interrupts[NUM_LOCAL_INTS]`·`#define NUM_LOCAL_INTS` 없음(IOMalloc 8 B — `push 8`).
   ② `enableInterrupt:` 의 빠른 경로 없음(원본 0x1a894c 60 B: attachInterruptPort 확인 → `_changeInterrupt:to:YES`).
   ③ `disableInterrupt:` 빠른 경로 없음(0x1a8988 32 B).
   ④ `_changeInterrupt:to:` 의 local_device_interrupts 대입 없음.
   ⑤ `setDeviceDescription:` 에 `[super setDeviceDescription:]` 없음(0x1a85d8: ivar 대입 + `_delegate` 메시지만).
   ⑥ `free` 에 ArchPPC→freePPC 분기 없음(원본 비교 2·3 만; Arch enum NONE,EISA,HPPA,SPARC,ArchPPC).
   ⑦ `initFromDeviceDescription:` 은 `bzero` 대신 `device_interrupts`(+4)·`memory_mappings`(+0) 순으로 0 대입.
   ⑧ 원본에 `- deviceDescription`(0x1a85c8, 16 B, `return _deviceDescription` = [self+0x108]) 이 있음 — Darwin 에는 없음.
   진단 `s5p305-de1`(①–⑤), `df1`(+⑥⑦, 크기 일치·위치 어긋남), `dg1`(+⑧, 대입 순서 하나 DIFF), `dh1`(⑦ 순서 바꿈) → **OBJECT_MATCH**(L1 항목 29 = `__text` 28 + `__const` 1). (`s5p305-dd1` 은 분류가 LOCK 을 쥐어 시작 거부 — 소모.)
2. 방법: 07 `src/driverkit/libDriver/IODirectDevice.m` = dh1 본문(mkfinal 고지 검사, D030 머리 — Darwin 고지 없음, 각 수정에 plan 308 표시; PROVENANCE·MODIFICATIONS 에 “nearly the same as Darwin 0.1 driverkit-1/libDriver/IODirectDevice.m”) → iter_objc(RUNIN, 정의 추가 없음) → 매니페스트(Kern*.h 는 비 BSD 07→Darwin 규칙) → relcheck → record_objc(A 예상).

### codex 교차검토 판정(2026-10-05, plan 308; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 범위·길이·앞 `00` 3 B·끝 0 B·`__const` 24·`__cstring` 119 맞음 | 앞서 python 출력 | ✅ |
| 항목 수: `__text` 28(메서드 27 + 스레드 함수), L1 29 번째는 `__const` | python Counter(`__text` 28, `__const` 1) | ✅ 고침 |
| 수정 ①–⑧ 모두 원본 명령으로 뒷받침·최소(메서드 주소·크기 열거) | 앞서 fdis·odis2 확인과 같음 | ✅ |
| 진단 초안에 Darwin APSL 고지가 남음 — D030 머리·기록 문구 필요 | 07 최종본(mkfinal) 머리 확인, 고지 grep 0; 진단 초안은 07 에 넣지 않음 | ⚖️ 최종본은 이미 D030 꼴; 계획 2 항에 기록 문구 명시 |

### 결과(2026-10-05, plan 308)

- 07 `libDriver/IODirectDevice.m`(dh1 본문 + plan 308 표시 8 곳 + D030 머리). `s5p306-it1`(RUNIN) OBJECT_MATCH, relcheck 0 → **A**.

## 309. S5-P299 세부 계획 — `libDriver/IODeviceDescription.m`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/IODeviceDescription.m(본문 바탕); SDK driverkit/IODeviceDescription.h(07 nextdev)에는 아래 Darwin 추가 메서드 선언이 없음(Darwin 판 IODeviceDescription.h:58–59·IODeviceDescriptionPrivate.h:44–52 에만 있음).

0. 원본(python·objc.json): 모듈 "IODeviceDescription.m"(0x2090ac, 클래스 1·카테고리 3) `__text` [0x1a7e0c, 0x1a82e5) 1241 B 메서드 20(init … `(Private) _fetchRangeList:returnedNum:` 0x1a8268 이 마지막), `00` 3 B 뒤 0x1a82e8(IODirectDevice, 기록됨); `__cstring` 23 B.
1. 수정(plan 309 표시): 원본 메서드 목록에 없는 Darwin 추가 메서드 여섯을 뺌 — `getDevicePath:maxLength:useAlias:`·`matchDevicePath:`(본 구현), `lookUpProperty:value:length:selector:isString:`·`property_IODeviceClass:length:`·`property_IODeviceType:length:`·`nodeName`(Private 카테고리). 그 밖은 Darwin 본문 그대로.
2. 진단 `s5p307-da1`(위 수정 + 진단 `#line`) OBJECT_MATCH(20 항목). (분류에서 보인 `_fetchRangeList` 크기 차이는 다음 모듈과의 경계를 IMP 로 잰 탓 — 실제 128 B 로 같음.)
3. 방법: 07 `src/driverkit/libDriver/IODeviceDescription.m`(mkfinal 고지 검사, D030 머리 — Darwin 고지 없음, 빠진 자리에 plan 309 표시; 파일 머리·PROVENANCE·MODIFICATIONS 에 “nearly the same as Darwin 0.1 driverkit-1/libDriver/IODeviceDescription.m”) → iter_objc(RUNIN) → relcheck → record_objc(A 예상).

### codex 교차검토 판정(2026-10-05, plan 309; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·클래스 1·카테고리 3·메서드 20·범위 1241 B·뒤 3 B, L1 OBJECT_MATCH | 앞서 python·L1 출력 | ✅ |
| 여섯 메서드는 원본 목록에 없고 Darwin 머리에만 선언, 07 SDK 머리엔 없음 — 제거가 최소 | grep(Darwin IODeviceDescription.h:58–59, Private.h:44–52; 07 머리에 없음) | ✅ |
| 기록 문구 요구를 3 항에 명시, 진단 초안의 Apple 고지를 옮기지 말 것 | 최종본 고지 grep 0 | ✅ 3 항 고침 |

### 결과(2026-10-05, plan 309)

- 07 `libDriver/IODeviceDescription.m`. `s5p307-it1`(RUNIN) OBJECT_MATCH(20), relcheck 0 → **A**.

## 310. S5-P300 세부 계획 — `libDriver/Kernel/IOEthernetDebugger.m` + 머리 `driverkit/IOEthernetPrivate.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명, 모든 트리): Darwin 0.1 driverkit-1/libDriver/Kernel/IOEthernetDebugger.m(본문 바탕)·driverkit-1/driverkit/IOEthernetPrivate.h·kernel/kern/kdp_en_debugger.h 만 있음; Mach4·NeXTMach·SDK·07 에 같은 이름 없음(find). Darwin 파일 HISTORY(IOEthernetDebugger.m:34–36): “29 May 1997 … Added debugger registration call, and made en_send_pkt() and en_recv_pkt static” — 원본은 그 변경 전 판.

0. 원본(python·objc.json·symbols.tsv): 모듈 "Kernel/IOEthernetDebugger.m"(0x20914c, 카테고리 1 `IOEthernet(EthernetDebugger)`) `__text` [0x1aace0, 0x1aae9e) 446 B — C 함수 `_reserveDebuggerLock`·`_releaseDebuggerLock`·`_en_recv_pkt`(0x1aad58)·`_en_send_pkt`(0x1aad8c) + 메서드 셋(registerAsDebuggerDevice 0x1aadb4, reserveDebuggerLock 0x1aae10, releaseDebuggerLock 0x1aae68); 뒤 `00` 2 B 로 0x1aaea0(IOTokenRing, 기록됨). `__data` 5 B(0x1e5150 `_debuggerIplRoutine`·`__kernDebuggerLocked`), `__bss` 16 B(0x1e8700), `__cstring` 37 B.
1. 진단: Darwin 본문(분류 `s5p291-12-6`) NOT_MATCH — C 함수 넷은 맞고 메서드 셋이 다름. 원인: 원본 `registerAsDebuggerDevice`(0x1aadb4, 92 B)에는 `kdp_register_send_receive(&en_send_pkt, &en_recv_pkt)` 호출이 없음(바로 methodFor: 두 번 → debuggerDevice 대입); 원본 심볼표(외부만 남음)에 `_kdp_register_send_receive` 없음(strings.tsv grep 0), `_en_recv_pkt`·`_en_send_pkt` 는 형 0xf(외부) — Darwin 은 `static`. 07 kdp_machdep.c 의 `kdp_en_send_pkt`/`kdp_en_recv_pkt`(L1 MATCH, 원본 0x185dc0/0x185dd4)가 이 두 함수를 직접 부름. 나머지 두 메서드는 명령이 같고 참조만 어긋났던 것(메서드 대응 미완 탓).
2. 수정(plan 310 표시): ① `en_recv_pkt`·`en_send_pkt` 의 앞 선언·정의에서 `static` 을 뺌(원본 외부 심볼); ② `registerAsDebuggerDevice` 의 `kdp_register_send_receive(...)` 호출과 그 주석을 뺌; ③ 그 함수만 선언하던 `#import <kern/kdp_en_debugger.h>` 를 뺌(4.2 에 그 함수 없음; 07 에 그 머리 없음 — 빌드에 필요한 변경). 그 밖은 Darwin 본문 그대로.
3. 진단 `s5p310-e1`(위 수정 + 진단 `# 1 "Kernel/IOEthernetDebugger.m"`, 분류와 같은 머리 대체·`-DMACH_USER_API`): `__text` 7 항목 MATCH_UNVERIFIED, 사유 `__DATA,__bss: unverified` 하나뿐(텍스트 446 B, `__OBJC` 전부 맞음). (`s5p310-d1`·`d2` 는 머리 대체 없이 돌려 빌드 실패 — 소모.)
4. 머리: `driverkit/IOEthernetPrivate.h` 는 SDK 에 없는 Darwin driverkit-1 전용 파일(D030 대상 — libDriver 와 같은 driverkit 파일). 07 `nextdev_private/driverkit/IOEthernetPrivate.h` 에 Darwin 본문 그대로, 프로젝트 작성 머리 주석(고지 없음) + “nearly the same as Darwin 0.1 driverkit-1/driverkit/IOEthernetPrivate.h”(stage_headers mach_pick 이 `authored` 로 고름 — 이 자리가 없으면 Darwin 으로 조용히 떨어지므로 07 에 둠).
5. 방법: 07 `src/driverkit/libDriver/Kernel/IOEthernetDebugger.m`(mkfinal 고지 검사, D030 머리) → iter_objc(RUNIN; `-DMACH_USER_API` 없이 먼저, 필요하면 plan 307 처럼 객체별 정의로 기록) → 매니페스트·SDK 머리 채택(adopt_headers) → relcheck → zerofill(`--place-from-l1`) → record_objc(`__bss` 배치가 zerofill 로 확정되면 A, 아니면 P — D019).

### codex 교차검토 판정(2026-10-05, plan 310; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| symbols.tsv 921–922(`_en_recv_pkt`·`_en_send_pkt`), 2595·2601(`_releaseDebuggerLock`·`_reserveDebuggerLock`) 모두 형 0xf | `sed -n` 로 그 파일 줄 열람(줄 921 = 색인 919 등, 첫 줄은 열 이름) | ✅ |
| `kdp_register_send_receive` 는 symbols.tsv·strings.tsv 에 없음 | `grep -c` 0·0 | ✅ |
| 원본 0x1aadb4 는 CALL 둘(0x1ce960 objc_msgSend)뿐, 92 B | Ghidra 내보내기 001aadb4.asm `grep CALL` 2 줄(0x1aadd3·0x1aadec); 앞서 odis2 디스어셈블; python 0x1aae10−0x1aadb4 = 92 | ✅ |
| 세 수정은 최소이고 바이트가 요구; import(45 줄)는 그 호출만을 위함 | Darwin 파일 grep: `kdp_` 는 45·105 줄뿐, en_* 는 66·72·175·188; HISTORY 34–36 줄이 같은 변경을 적음 | ✅ |
| kdp_machdep.c 273–285 가 en_send_pkt·en_recv_pkt 를 직접 부름 | 앞서 sed 255–295 열람(277·284 줄 호출) | ✅ |
| nextdev_private/driverkit/… 가 mach_pick 에서 `authored` 로 골라짐; 근거는 D030(D032 는 커널 비공개 머리) | stage_headers.py 215–237·240–254 열람 | ✅ 계획 4 항이 이미 D030 근거 |
| 수치 446·92·2·5·16·37 맞음 | python(446, 92, 2), 문자열 “reserveDebuggerLock: already locked\n” + NUL = 37(python), strings.tsv:452 | ✅ |
| `__bss` 미확인인데 “A 예상”은 이름 — D019 조건부로 | 계획 3 항 사유 확인 | ✅ 5 항 문구 고침 |

### 결과(2026-10-05, plan 310)

- 07 `libDriver/Kernel/IOEthernetDebugger.m`(Darwin 본문 + plan 310 표시 3 곳 + D030 머리), `nextdev_private/driverkit/IOEthernetPrivate.h`(D030 머리, 본문 그대로). `s5p310-it1`(RUNIN, 정의 추가 없음): `__text`·`__data`·`__OBJC` 전부 맞고 `__bss` 만 미확인, relcheck 0. zerofill(`--place-from-l1`): `__bss` 16 B [0x1e8700, 0x1e8710) 참조 추정(참조 15, Delta 0x1e83e8 하나, 음성 검사 검출) → **P**(D019). 알려진 배치 51 개 `zerofill-known-s5p310-20261005.json`.
- 기록: objects_partial 48→49 줄, functions 2833→2840, PROVENANCE 763→766(IOEthernet.h SDK 채택·.m·머리), MODIFICATIONS 291→293 줄.

## 311. S5-P301 세부 계획 — `libDriver/IOLogicalDisk.m` + 머리 `driverkit/SCSIDisk.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명, 모든 트리): Darwin 0.1 driverkit-1/libDriver/IOLogicalDisk.m(본문 바탕; 같은 자리 `IOLogicalDisk.m.crasher` 는 쓰지 않음)·driverkit-1/driverkit/IOLogicalDisk.h; SDK driverkit/IOLogicalDisk.h 있음; Mach4·NeXTMach·07 에 같은 이름 없음(find). `driverkit/SCSIDisk.h` 는 Darwin driverkit-1 에만 있음(SDK 없음).

0. 원본(python·objc.json): 모듈 "IOLogicalDisk.m"(0x20907c, 클래스 1·카테고리 1) `__text` [0x1a5e40, 0x1a639a) 1370 B, 메서드 17(IOLogicalDisk 16 + `(private) _diskParamCommon:length:deviceOffset:bytesToMove:` 0x1a6288); 앞은 IODisk `needsManualPolling`(0x1a5e34, `c3` 뒤 `00` 3 B), 뒤 `00` 2 B 로 0x1a639c(IODiskPartition `probe:`). 원본 메서드 목록에 Darwin 의 `+commonReadWrite::::::::`·`(private) computePartition:length:byteOffset:bytesToMove:`·`+(private) reblock::::::::` 없음.
1. 원본 명령(odis2 0x1a5e40–0x1a5ff0): readAt/readAsyncAt/writeAt/writeAsyncAt 은 `_diskParamCommon`(selector 0x1f9cb8) 하나를 부르고 결과가 0 이면 `_physicalDisk`(self+0x184)에 블록 오프셋·bytesToMove·buffer·actualLength|pending·client 를 넘김; write 둘은 먼저 self 에 인자 없는 메시지(selector 0x1f9cb0, `al` 검사) → 참이면 `0xfffffd31`(IO_R_NOT_WRITABLE = −719). 이것은 Darwin 의 `#else KERNEL` 판(“not updated for reblocking”; write 는 `isWriteProtected` 검사)과 같은 꼴에 `client:` 인자만 더한 것 — 재블록이 없는 판(셀렉터 이름의 대응은 3 항 진단의 `__message_refs` 내용 일치로 확인).
2. 수정(plan 311 표시): ① `#ifdef KERNEL` 쪽 read/write 네 메서드를 `#else` 판 본문 + `client:(vm_task_t)client` 인자·전달로 바꿈; ② `+commonReadWrite::::::::`·`computePartition:…`·`+reblock::::::::` 구현과 `(private)` 선언 둘을 뺌(원본 목록에 없음). `#else KERNEL` 판·그 밖은 Darwin 본문 그대로.
3. 진단 `s5p311-a1`(위 수정 + 진단 `# 1 "IOLogicalDisk.m"`, 분류와 같은 머리 대체·`-DMACH_USER_API`) → **OBJECT_MATCH**(17 항목, `__OBJC` 전부 바이트 0 차이).
4. 머리: `driverkit/SCSIDisk.h`(이 파일이 import; 이 객체 바이트에는 쓰이지 않음)는 SDK 에 없는 Darwin driverkit-1 파일 → plan 310 처럼 07 `nextdev_private/driverkit/SCSIDisk.h` 에 D030 사본(본문 그대로, 고지 없는 머리 주석, “nearly the same as Darwin 0.1 driverkit-1/driverkit/SCSIDisk.h”). .m 의 import 는 그대로 둠(바이트가 요구하지 않는 소스 변경을 피함).
5. 방법: 07 `src/driverkit/libDriver/IOLogicalDisk.m`(mkfinal 고지 검사, D030 머리) → iter_objc(RUNIN; 정의 추가 없이 먼저) → 매니페스트·SDK 머리 채택 → relcheck → record_objc(A 예상 — `__bss` 없음). 기록: IOLogicalDisk.m 과 SCSIDisk.h 둘 다 파일 머리·PROVENANCE·MODIFICATIONS 에 “nearly the same as Darwin 0.1 <file>”(D030).

### codex 교차검토 판정(2026-10-05, plan 311; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| objc.json: 모듈 IOLogicalDisk.m, 메서드 16 + (private) 1, commonReadWrite·computePartition·reblock 셀렉터 없음 | python(objc.json methods 에서 세 이름 0 건; 앞서 소유자별 17 건 목록) | ✅ |
| read/write 네 메서드 92·92·124·124 B, `_diskParamCommon` → 0 검사 → `_physicalDisk` 호출, write 는 먼저 쓰기 보호 검사 후 0xfffffd31 | python(IMP 차 92, 92, 124, 124), 앞서 odis2 0x1a5e40–0x1a5ff0 | ✅ |
| 범위 1370 B, 앞 `00` 3 B, 뒤 `00` 2 B, 0x1a639c = IODiskPartition probe: | 앞서 python(이웃 IMP 목록·바이트) | ✅ |
| 초안 차이는 계획과 같고 세 이름은 남지 않음; 설명 주석(body.m 64)은 불필요 | grep(세 이름은 plan 311 주석에만); 주석은 “모든 수정에 plan N 표시” 규칙의 표시 | ⚖️ 사실은 맞음, 주석은 규칙상 남김 |
| a1 OBJECT_MATCH 17 MATCH | 앞서 python Counter | ✅ |
| SCSIDisk.h 는 SDK·Mach4·NeXTMach 에 없음, D030 사본 맞음; 두 파일 모두 “nearly the same” 기록을 계획에 명시할 것 | find(앞서 실행: Darwin 에만), SDK 목록 grep 결과 IOLogicalDisk.h 만 | ✅ 5 항 고침 |

### 결과(2026-10-05, plan 311)

- 07 `libDriver/IOLogicalDisk.m`(Darwin 본문 + plan 311 표시 4 곳 + D030 머리), `nextdev_private/driverkit/SCSIDisk.h`(D030). `s5p311-it1`(정의 추가 없음): `__text` 17 MATCH 이나 `__inst_meth`·`__cat_inst_meth` 형식 문자열 참조 4 개씩 다름 — read/write 네 메서드의 `client` 가 `^{vm_map=…}`(원본 `I`, objc.json 형식 `…I32`). plan 307 과 같은 원인이므로 같은 객체별 정의 `-DMACH_USER_API` 로 `s5p311-it2` → **OBJECT_MATCH**(17), relcheck 0 → **A**. build_note 에 정의와 근거.
- 기록: objects_confirmed 235→236 줄, functions 2840→2857, PROVENANCE 766→775(SDK 머리 7 채택·.m·SCSIDisk.h), MODIFICATIONS 293→295 줄.

## 312. S5-P302 세부 계획 — `libDriver/Kernel/SCSIDiskPrivate.m` + 머리 `driverkit/SCSIDiskPrivate.h`·`SCSIDiskTypes.h`·`SCSIDiskThread.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명, 모든 트리): Darwin 0.1 driverkit-1/libDriver/Kernel/SCSIDiskPrivate.m(본문 바탕)·driverkit-1/driverkit/SCSIDiskPrivate.h 만 있음(find); Mach4·NeXTMach·SDK 에 같은 이름 없음. 세 머리는 SDK driverkit/ 에 없음(SDK 에는 IODiskPartition.h·align.h·scsiTypes.h, bsd/dev/scsireg.h 있음).

0. 원본(python·objc.json): 모듈 "Kernel/SCSIDiskPrivate.m"(0x20919c, 카테고리 `SCSIDisk(Private)` 1) `__text` [0x1acbc8, 0x1ad8af) 3303 B — 메서드 12 + 정적 `moveString`(0x1aceec, 92 B); 앞은 SCSIDisk `controller`(0x1acbb8, 채움 없음), 뒤 `00` 1 B 로 0x1ad8b0(`SCSIDisk(Thread) doSdBuf:`). 원본 목록에 Darwin 의 `initResourcesWithThreadCount:`·`reacquireTarget`·`requestReleaseTarget`·`getCharValues:forParameter:count:`·`reserveNonZeroLunsOnTarget:`·`releaseNonZeroLunsOnTarget:` 없음(분류 L1 “missing” 6 개).
1. 원본 명령(odis2 0x1acf48–0x1ad0fc): `initResources`(228 B)는 큐 둘 초기화 → `_ioQLock`·`_ejectLock` alloc/initWith: → `setLastReadyState:` → `_numDiskIos`(+0x1c4)=0·`_ejectPending`(+0x1c8)=0·비트필드 바이트 +0x18a `and 0xfc`(`_isReserved`·`_isRegistered`)·`_numThreads`(+0x18c)=0 → `IOForkThread(sdIoThread, self)` 를 `ebx` 0..5(`cmp ebx,5; jle`)로 6 번 — Darwin `initResourcesWithThreadCount:` 본문에 개수 `NUM_SD_THREADS_MAX`(6, Darwin SCSIDisk.h)를 넣은 꼴. `free`(208 B)는 스레드 중단 sdBuf → `_isReserved` 이면 `[_controller releaseTarget:lun:forOwner:]` 만(`releaseNonZeroLunsOnTarget:` 없음) → `[_ioQLock free]` → super free. Darwin HISTORY(SCSIDiskPrivate.m:30)가 Radar 2260508 등을 30-Jul-98 변경으로 적음.
2. 수정(plan 312 표시): ① `initResources` 를 `initResourcesWithThreadCount:` 본문(개수 = `NUM_SD_THREADS_MAX`)으로 하고 `initResourcesWithThreadCount:` 메서드를 뺌; ② `free` 의 `#if 1 // Radar Fix #2260508` 블록을 뺌; ③ `reacquireTarget`·`requestReleaseTarget`·`getCharValues:forParameter:count:`·`reserveNonZeroLunsOnTarget:`·`releaseNonZeroLunsOnTarget:` 를 뺌. 그 밖은 Darwin 본문 그대로.
3. 진단 `s5p312-a1`(위 수정 + 진단 `# 1 "Kernel/SCSIDiskPrivate.m"`, 분류와 같은 머리 대체·`-DMACH_USER_API`) → **OBJECT_MATCH**(13 항목, `__OBJC` 전부). 이 파일은 Darwin 본문 안에 `#define MACH_USER_API 1` 을 가짐.
4. 머리: `driverkit/SCSIDiskPrivate.h`·`SCSIDiskTypes.h`·`SCSIDiskThread.h` 는 Darwin driverkit-1 전용 → plan 310·311 처럼 07 `nextdev_private/driverkit/` 에 D030 사본(본문 그대로, 고지 없는 머리 주석, “nearly the same as Darwin 0.1 driverkit-1/driverkit/<file>”). SCSIDiskPrivate.h 의 선언 가운데 원본에 없는 메서드(`initResourcesWithThreadCount:`, Radar 2260508 둘)는 바이트에 영향이 없어 그대로 두고 기록에 적음(바이트가 요구하지 않는 변경을 피함).
5. 방법: 07 `src/driverkit/libDriver/Kernel/SCSIDiskPrivate.m`(mkfinal 고지 검사, D030 머리) → iter_objc(RUNIN; 정의 추가 없이 먼저 — 파일 안 `#define MACH_USER_API`) → 매니페스트·SDK 머리 채택 → relcheck → record_objc(A 예상 — `__bss` 없음). 기록: .m 과 머리 셋 모두 파일 머리·PROVENANCE·MODIFICATIONS 에 “nearly the same as Darwin 0.1 <file>”(D030).

### codex 교차검토 판정(2026-10-05, plan 312; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| objc.json: 모듈 0x20919c, SCSIDisk(Private) 메서드 12(IMP 있음), 여섯 셀렉터 0 건 | python(12, 모두 IMP; 여섯 각 0) | ✅ |
| initResources 228 B·루프 6 번, free 208 B·releaseTarget 한 번, 앞 0x1acbc7 `c3`, 0x1ad8af `00`, 0x1ad8b0 doSdBuf: | python 바이트(0xc3, 0x00), 앞서 odis2·IMP 목록 | ✅ |
| 초안 차이는 2 항과 같고, 더한 것은 plan 312 주석 넷뿐; 빠진 메서드 이름은 주석에만 | grep body.m(72·325·334·820 줄 주석뿐) | ✅ |
| a1 OBJECT_MATCH 13 MATCH, `__text` 3303 B 차이 0 | 앞서 python 출력 | ✅ |
| 세 머리는 Darwin 에만 있고 D030 사본·선언 유지가 규칙과 plan 310·311 에 맞음 | find(Darwin driverkit-1 에만) | ✅ |

### 결과(2026-10-05, plan 312)

- 07 `libDriver/Kernel/SCSIDiskPrivate.m`(Darwin 본문 + plan 312 표시 4 곳 + D030 머리), `nextdev_private/driverkit/SCSIDiskPrivate.h`·`SCSIDiskTypes.h`·`SCSIDiskThread.h`(D030). `s5p312-it1`(RUNIN, 정의 추가 없음 — 파일 안 `#define MACH_USER_API`) OBJECT_MATCH(13), relcheck 0 → **A**.
- 기록: objects_confirmed 236→237 줄, functions 2857→2870, PROVENANCE 775→780(IODiskPartition.h SDK 채택·.m·머리 셋), MODIFICATIONS 295→299 줄.

## 313. S5-P303 진단 — `libDriver/IODisk.m`(결정 대기, 2026-10-05)

0. 원본: 모듈 "IODisk.m" 메서드 38(objc.json). Darwin 이 더한 `property_IODeviceType:length:`·`property_IODeviceClass:length:` 는 원본 목록에 없음.
1. 진단(분류와 같은 머리 대체·`-DMACH_USER_API`, 진단 `# 1 "IODisk.m"`): 두 메서드를 빼고(`s5p313-a1`) 원본 0x1a5b38 `setLogicalDisk:`(`_nextLogicalDisk == nil || diskId == nil` 이면 대입; Darwin 의 GROK_APPLE·#else 두 갈래와 다름)와 0x1a5b58 `registerDevice`(`!_isPhysical` 이면 `[super registerDevice]` 없이 out)를 원본대로 고친 `s5p313-b1`: `__text` 37 MATCH, `stringFromReturn:` 은 바이트 0 차이·참조만 다름 — `__data` 88 B 가운데 앞 48 B(`diskIoReturnValues`)는 맞고 뒤 40 B 는 빌드에만 있는 `readyStateValues`(원본 심볼·문자열 없음).
2. 원인: Darwin `#ifdef DDM_DEBUG` 블록. DDM_DEBUG 는 Device_ddm.h:33–38 에서 `KERNEL && KERNEL_BUILD` 일 때만 정의(= XPR_DEBUG 0). Darwin libDriver/Makefile:70 의 커널 플래그는 `-static -DNCPUS=1 -D_KERNEL -DKERNEL -DMACH_USER_API -DDRIVER_PRIVATE`(KERNEL_BUILD 없음; 내보낸 System.framework 머리로 빌드). 우리 libDriver 꼴은 커널 소스 머리를 쓰므로 `-DKERNEL_BUILD` 가 필요 — `-UKERNEL_BUILD` 진단 `s5p313-c1` 은 mach/features.h → machdep/i386/features.h 없음으로 빌드 실패.
3. 결정 필요: (가) IODisk.m 의 `#ifdef DDM_DEBUG` 를 원본 바이트대로 빠지게 하는 소스 수정(예 `#if DDM_DEBUG`, 4.2 원문 근거 없음) / (나) libDriver 빌드에서 DDM_DEBUG 가 정의되지 않게 하는 빌드 꼴(머리 쪽 조정 필요) / (다) 보류. 사용자 결정까지 07 에 넣지 않음.

## 314. S5-P304 세부 계획 — `libDriver/Kernel/SCSIDisk.m` + `nextdev_private/driverkit/SCSIDisk.h` 수정(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/SCSIDisk.m(본문 바탕), 머리 driverkit-1/driverkit/SCSIDisk.h(plan 311 D030 사본); Mach4·NeXTMach·SDK 에 같은 이름 없음.

0. 원본(python·objc.json): 모듈 "Kernel/SCSIDisk.m"(0x20918c, 클래스 1) `__text` [0x1ac3d8, 0x1acbc8) 2032 B 메서드 21, 앞 `00` 2 B, 뒤 채움 없이 SCSIDiskPrivate(기록됨); `__data` 12 B(0x1e5170, `diskUnit` 등), 원본 SCSIDisk ivar 목록(이미지 0x20844c, 14 개)에 Darwin 의 `_allowLoans:1` 없음(`_isReserved`·`_isRegistered` b1 @0x18a 뒤 `_numThreads` @0x18c).
1. 원본 명령과 Darwin 의 차이(odis2·fdis):
   ① probe:(0x1ac3d8, 456 B): Radar 2005639 스레드 수 질의 없음 — `[diskId initResources]` 만; LUN 루프 `Lun<SCSI_NLUNS`(`cmp …,7; jle`; Darwin 은 `#if 0` 갈래); reserveTarget 뒤 `_isReserved = 1`·Radar 2260508 비 0 LUN 예약/해제 없음; SCSIDiskInit 뒤 `setDeviceDescription:` 없음; 실패 갈래에 `_isReserved = 0` 없음; 등록 루프에서 `or byte [ebx+0x18a],1`(`_isReserved = 1`) 뒤 setDeviceKind:·setIsPhysical:·registerDevice·`_isRegistered = 1`.
   ② updateReadyState(0x1ac88c, 168 B)·isDiskReady:(0x1ac9d0, 120 B): Darwin 의 `if (NO == _isReserved) …` 이른 반환 없음.
   ③ 원본 목록에 Darwin 의 `synchronizeCache`·`getDevicePath:maxLength:useAlias:`·`matchDevicePath:`·`property_IOUnit:length:`·`property_IODeviceType:length:` 없음.
   ④ ivar 목록에 `_allowLoans` 없음 → SCSIDisk.h 수정 필요(바이트: `__instance_vars` 참조 19 개 차이 `s5p314-a1`).
2. 수정(plan 314 표시): SCSIDisk.m — ①②③을 원본대로(빠진 Radar 블록은 지우고 표시 주석); SCSIDisk.h — `_allowLoans:1` 를 뺌(`_isRegistered:1;` 로 끝냄).
3. 진단 `s5p314-b1`(위 수정 + 수정한 머리 + 진단 `# 1 "Kernel/SCSIDisk.m"`, `-DMACH_USER_API`) → **OBJECT_MATCH**(21 항목, `__data`·`__OBJC` 전부).
4. 영향: SCSIDisk.h 는 이미 기록한 IOLogicalDisk(plan 311)·SCSIDiskPrivate(plan 312)가 import — 1 비트 필드 제거는 배치를 바꾸지 않지만 07 에서 둘을 다시 빌드해 같은 판정(OBJECT_MATCH, 객체 SHA)을 확인하고 기록에 남김.
5. 방법: 07 `src/driverkit/libDriver/Kernel/SCSIDisk.m`(mkfinal 고지 검사, D030 머리) + 07 SCSIDisk.h 수정(plan 314 표시, PROVENANCE 행의 SHA 갱신) → iter_objc(RUNIN; 정의 추가 없이 먼저, 형식 문자열이 `vm_task_t` 를 요구하면 plan 307 꼴 `-DMACH_USER_API`) → relcheck → record_objc(A 예상, `__bss` 없음) → IOLogicalDisk·SCSIDiskPrivate 재빌드 확인. 기록: “nearly the same as Darwin 0.1 <file>”(D030).

### codex 교차검토 판정(2026-10-05, plan 314; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| probe:·updateReadyState·isDiskReady: 원본 명령이 1 항 설명과 같음 | 앞서 odis2(0x1ac3d8–0x1ac5a0)·fdis 두 메서드 | ✅ |
| ivar 목록 0x20844c 14 개, `_allowLoans` 없음 | 앞서 img.py 로 이미지에서 해독한 출력(14 줄) | ✅ |
| 모듈 0x20918c, 메서드 21 에 다섯 셀렉터 없음, 2032 B | python(0x1ac3d8+2032 = 0x1acbc8 True), 앞서 objc.json 목록 | ✅ |
| 초안 차이는 계획 수정뿐, 머리는 `_allowLoans` 제거만 | 앞서 diff·grep(plan 314 표시 줄) | ✅ |
| b1: 21 MATCH, 모든 섹션 차이 0 | python(b1.json 섹션별 byte_differences 0) | ✅ |
| 07 에서 SCSIDisk.h 를 import 하는 .m 은 IOLogicalDisk.m·SCSIDiskPrivate.m 뿐 — 4 항 재확인으로 충분 | grep(그 둘 + 머리 SCSIDiskPrivate.h·SCSIDiskThread.h 의 import) | ✅ |
| “계획 단계 codex 교차검토가 아직 남음” | 이 회신 자체가 그 교차검토(gpt-6-luna) | ❌ 기각 |

### 결과(2026-10-05, plan 314)

- 07 `libDriver/Kernel/SCSIDisk.m`(Darwin 본문 + plan 314 표시 + D030 머리), `nextdev_private/driverkit/SCSIDisk.h`(`_allowLoans` 제거, plan 314 표시). `s5p314-it1`(RUNIN, 정의 추가 없음) OBJECT_MATCH(21), relcheck 0 → **A**.
- 머리 수정 뒤 재빌드: IOLogicalDisk `s5p314-rl1`(`-DMACH_USER_API`)·SCSIDiskPrivate `s5p314-rs1` 모두 OBJECT_MATCH; 이전 객체(`s5p311-it2`·`s5p312-it1`)와 모든 섹션 바이트·재배치(기호 이름 기준)가 같고 -g stab 의 SCSIDisk 구조체 형 기술(`_allowLoans`)만 다름 — 두 근거 파일에 덧붙임.
- 도구(scratchpad): record_objc 의 메서드 정의 탐색이 들여 쓴 정의(`␠- (void)setLastReadyState`)도 찾게 함(plan 314 표시). 첫 기록 시도는 표를 바꾸기 전에 멈춤(줄 수 그대로 확인), 남은 기록용 스테이지를 지우고 다시 실행.
- 기록: objects_confirmed 237→238 줄, functions 2870→2891, PROVENANCE 780→781(+ SCSIDisk.h 행 갱신), MODIFICATIONS 299→301 줄.

## 315. S5-P305 — libDriver 객체별 빌드 꼴 `-DMACH_USER_API -UKERNEL_PRIVATE`(plan 307 확장; 코딩 전, 2026-10-05)

0. 근거(참조 후보): Darwin 0.1 driverkit-1/libDriver/Makefile:70 `KERN_CFLAGS= -static -DNCPUS=1 -D_KERNEL -DKERNEL -DMACH_USER_API -DDRIVER_PRIVATE` — libDriver 는 MACH_USER_API 를 주고 KERNEL_PRIVATE·KERNEL_BUILD 를 주지 않으며, 머리는 System.framework PrivateHeaders·Headers(Makefile:63 COMMON_CFLAGS)에서 찾음. 우리 libDriver 꼴(템플릿 s5p107)은 `-DKERNEL_PRIVATE -DKERNEL_BUILD` 를 주고 커널 소스 머리를 씀.
1. 바이트 근거: (가) IODiskPartition — 원본 메서드 형식의 `client` 는 `I`(공개 `vm_task_t`); `-DMACH_USER_API` 만 주면 bsd/dev/voldev.h 의 `#if KERNEL_PRIVATE` → kern/kern_port.h 사슬이 공개 mach_types.h 와 충돌(`s5p316-c1` 실패), `-DMACH_USER_API -UKERNEL_PRIVATE`(`s5p316-g1`) → OBJECT_MATCH. (나) volCheck — `-DKERNEL_PRIVATE` 면 IODisk.h → clock_timer.h → … → 커널 kern/queue.h(같은 guard `_KERN_QUEUE_H_`)가 먼저 들어와 원본(SDK kernserv/queue.h 꼴 `queue_enter`)과 다름(`s5p315-v1`), `-UKERNEL_PRIVATE`(`s5p315-x1`·`y1`)로 맞음.
2. 결정: plan 307 처럼 **객체별 빌드 정의**로 둠(공통 꼴로 바꾸지 않음 — KERNEL_BUILD 제거는 우리 머리에서 빌드 불가 `s5p313-c1`, 기록된 libDriver 객체의 회귀 없이 공통화하지 않음). iter_objc `EXTRA_DEFS="-DMACH_USER_API -UKERNEL_PRIVATE"`(템플릿의 `-DKERNEL_PRIVATE` 뒤에 `-U` 가 와서 취소), record 의 build_note 에 정의·근거.

## 316. S5-P306 세부 계획 — `libDriver/IODiskPartition.m`(D024·D027·D030·D031·D032, plan 315 꼴; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/IODiskPartition.m(본문 바탕); SDK driverkit/IODiskPartition.h(07 nextdev — ivar `_partition`·`_labelValid`·`_blockDeviceOpen`·`_rawDeviceOpen`·`_IODiskPartition_reserved[4]`); Mach4·NeXTMach 같은 이름 없음.

0. 원본(python·objc.json·이미지 ivar 목록 0x208114): 모듈 "IODiskPartition.m"(0x20908c, 클래스 1·카테고리 1) `__text` [0x1a639c, 0x1a758b) 4591 B 메서드 23, 앞 `00` 2 B(IOLogicalDisk), 뒤 `00` 1 B 로 volCheck 0x1a758c; ivar 5 개(SDK 머리와 같음 — Darwin 의 `_physicalPartition`·`_partitionWaitLock`·`_probeTime`·`_hfsValid` 없음); 메서드 목록에 Darwin 의 `_initPartition:physicalPartition:disktab:` 대신 `_initPartition:disktab:`.
1. 수정(plan 316 표시; 원본 명령 odis2 대조):
   ① i386 에서 컴파일되는 Darwin 추가 메서드 여섯을 뺌: `requestRelease`·`waitForProbe:`·`property_IODeviceType:length:`·`property_IODeviceClass:length:`·`property_IOPartitionNumber:length:`·`registerLoudly`(원본 목록에 없음). `#ifdef GROK_APPLE`(ppc 전용) 안의 getDevicePath·HFS 메서드는 i386 바이트에 영향 없어 그대로 둠.
   ② 없는 ivar 사용 제거: `_physicalPartition`(probe·NeXTpartitionOffset·_initPartition), `_partitionWaitLock`(probe 두 곳·free), `_probeTime`(probe); `_initPartition:disktab:` 로 선언·정의·호출 둘.
   ③ readAt/readAsyncAt: Darwin 이 `#if 0 // radar 1669467` 로 막은 라벨 검사가 원본에 있음(0x1a6dfc: `_labelValid` 검사 → IOLog “%s: Read attempt with no valid label” → −706).
   ④ checkSafeConfig: 원본은 세 경우마다 `IOLog("%s: %s on partition != 0\n"` / `with open block devices` / `with other partitions open`, `[self name]`, op)(문자열 0x1d72c0·0x1d72dc·0x1d72fc) 후 IO_R_BUSY(−725).
   ⑤ NeXTpartitionOffset·readLabel·writeLabel: Darwin 의 `[[super class] commonReadWrite …]`(재블록) 대신 `[physDisk readAt:/writeAt: <블록> length: buffer: actualLength:&bytesXfr client:IOVmTaskSelf()]`(0x1a6c4c·0x1a68b4·0x1a6b7e 근처); readLabel 의 `blocksize = [physDisk blockSize]` 와 그 주석 없음.
   ⑥ probe:(0x1a639c, 1016 B): 재시도 15 회(`cmp ebx,0xe; jle`, Darwin `DELAY_AT_PROBE 0` → 15, 플로피 예외 없음); 재사용 갈래의 `IOLog("\n")` 없음; 새 인스턴스는 `init` 바로 뒤 `registerDevice`, `setDeviceDescription:` 없음, 끝의 `if(ld == nil) registerDevice` 없음; `blockSize` → `setPhysicalBlockSize:` → `diskSize` 순서; 라벨 없을 때 `setPartitionBase:0` 없음.
2. 진단 `s5p316-g1`(위 수정 + 진단 `# 1`, `-DMACH_USER_API -UKERNEL_PRIVATE`) → **OBJECT_MATCH**(23, `__data`·`__OBJC` 전부).
3. 머리(07 에 없음): D030 — `nextdev_private/driverkit/kernelDiskMethodsPrivate.h`·`disk_label.h`(Darwin driverkit-1; SDK 의 bsd/dev/disk_label.h 는 다른 파일), `src/driverkit/libDriver/label_subr.h`(따옴표 import, Darwin libDriver); D032 — `nextdev_private/bsd/dev/voldev.h`(NeXTMach nextdev/voldev.h 는 옛 판: `kern/kern_port.h` 를 조건 없이 import 하고 옛 구조체를 드러냄; 그 판으로 빌드하면 `nextdev/insertmsg.h` → `sys/message.h` → `mach_ipc_xxxhack.h`(옛 Mach IPC)가 없어 실패 — `s5p315-n1`·`m4`), `nextdev_private/bsd/dev/i386/disk.h`(SDK bsd/dev/i386 에 없음). 모두 본문 그대로, 고지 없는 머리 주석 + “nearly the same as Darwin 0.1 <file>”.
4. 방법: 07 `src/driverkit/libDriver/IODiskPartition.m`(mkfinal, D030 머리) → `EXTRA_DEFS="-DMACH_USER_API -UKERNEL_PRIVATE"` iter_objc(RUNIN) → relcheck → record_objc(A 예상).

## 317. S5-P307 세부 계획 — `libDriver/volCheck.m`(D024·D027·D030·D031·D032, plan 315 꼴; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/volCheck.m·volCheckPrivate.h·driverkit/volCheck.h; Mach4·NeXTMach·SDK 에 같은 이름 없음.

0. 원본: 모듈 "volCheck.m"(0x20909c, 클래스·카테고리 없음) `__text` [0x1a758c, 0x1a7e0c) 2176 B — 외부 함수 6 + 정적 5(L1 placement given by symbol), 뒤 채움 없이 IODeviceDescription(기록됨); `__bss` 20 B(0x1e86d8 추정).
1. 수정(plan 317 표시): `volCheckCmdHandler` 의 VC_REGISTER — Darwin `#if 1`(`lastReadyState`) 대신 `#else` 갈래(`readyState = [diskObj updateReadyState]; [diskObj setLastReadyState:readyState];`)가 원본(원본에 sel 0x1f9cbc 뒤 0x1f9c6c `setLastReadyState:` 호출). `#if 1` → `#if 0` 한 줄.
2. 진단 `s5p315-y1`(위 수정 + 진단 `# 1 "volCheck.m"`, `-DMACH_USER_API -UKERNEL_PRIVATE`): 텍스트 11 항목 바이트 0 차이(MATCH 6·MATCH_UNVERIFIED 5), 사유는 `__DATA,__bss: unverified` 하나 → zerofill `--place-from-l1` 로 **P** 예상(D019).
3. 머리: D030 — `nextdev_private/driverkit/volCheck.h`, `src/driverkit/libDriver/volCheckPrivate.h`(따옴표 import); voldev.h 는 plan 316 과 같음.
4. 방법: 07 `src/driverkit/libDriver/volCheck.m`(mkfinal, D030 머리) → plan 315 꼴 iter_objc → relcheck → zerofill → record_objc.

### codex 교차검토 판정(2026-10-05, plans 315–317; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| Makefile:70 KERN_CFLAGS 맞음; 단 머리는 PrivateHeaders·Headers 둘 다(Makefile:63) — “내보낸 머리”는 좁음 | sed Makefile:61–63 | ✅ 315-0 문구 고침 |
| voldev.h 의 kern_port.h 는 `#if KERNEL_PRIVATE` 안 | 앞서 스테이징 사본 34–45 줄 열람 | ✅ |
| 객체별 꼴은 plan 307 과 맞지만 “더 안전”은 새 정의 짝의 전체 회귀 결과가 아님 | 315-2 는 공통화하지 않는 이유로만 씀(회귀 결과라고 하지 않음) | ⚖️ 사실 맞음, 문구는 이미 “회귀 없이 공통화하지 않음” |
| IODiskPartition ivar 5 개 = SDK 머리, 메서드 23 에 `_initPartition:disktab:`, 여섯 없음 | 앞서 img.py 해독·objc.json 목록 | ✅ |
| ①–⑥ 원본 명령과 맞고 초안 차이는 계획 + 설명 주석 | 앞서 odis2·fdis 대조, g1 OBJECT_MATCH | ✅ |
| GROK_APPLE(ppc) 갈래를 두는 것이 맞음 | Darwin IODiskPartition.m:79–81 `#ifdef ppc` | ✅ |
| **NeXTMach voldev.h 는 `nextdev/insertmsg.h` 를 import 하고 그 파일은 있음 — “없음” 서술 틀림** | sed NeXTMach voldev.h:11–14, ls insertmsg.h 있음; NeXTMach 뿌리를 더한 `s5p315-m4` 는 `mach_ipc_xxxhack.h` 없음으로 실패 | ✅ 내 서술이 틀림 — 316-3 고침(쓸 수 없는 근거는 kern_port.h 무조건 import·옛 IPC 머리) |
| kernelDiskMethodsPrivate.h 에 D032 도 적을지 | driverkit-1 파일 → D030 만으로 충분(D030 이 driverkit 파일을 직접 다룸) | ⚖️ D030 으로 기록 |
| volCheck VC_REGISTER 는 0x1f9cbc(updateReadyState) → 0x1f9c6c(setLastReadyState:), 초안 차이는 `#if 1`→`#if 0` 한 줄 | 앞서 fdis·diff | ✅ |
| y.json 은 OBJECT_MATCH 가 아님(`__bss` 미확인) — P 예상이 맞음 | 앞서 python 출력 | ✅ |

### 결과(2026-10-05, plans 315–317)

- 07 `libDriver/IODiskPartition.m`(plan 316 표시), `libDriver/volCheck.m`(plan 317 표시), 머리 7 개(D030: nextdev_private/driverkit/kernelDiskMethodsPrivate.h·disk_label.h·volCheck.h, src/driverkit/libDriver/label_subr.h·volCheckPrivate.h; D030·D032: nextdev_private/bsd/dev/voldev.h·i386/disk.h). 스테이징 매니페스트에서 모두 07 사본을 읽음 확인.
- `s5p316-it1`(`EXTRA_DEFS="-DMACH_USER_API -UKERNEL_PRIVATE"`, RUNIN) OBJECT_MATCH(23), relcheck 0 → **A**.
- `s5p317-it1`(같은 꼴) `__text` 차이 0, `__bss` 만 미확인 → zerofill `--place-from-l1`: 20 B [0x1e86d8, 0x1e86ec) 참조 추정(참조 63, Delta 0x1e7c18 하나, 음성 검사 검출) → **P**. 알려진 배치 52 개 `zerofill-known-s5p317-20261005.json`. relcheck 0.
- 기록: objects_confirmed 238→239 줄, objects_partial 49→50 줄, functions 2891→2925, PROVENANCE 781→791(SDK 머리 채택 1·.m 둘·머리 7), MODIFICATIONS 301→310 줄.

### plan 313 계속 — 사용자 결정 D034 뒤 세부 계획(코딩 전, 2026-10-05)

0. 원본: 모듈 "IODisk.m"(0x20906c, 클래스 1) `__text` [0x1a5714, 0x1a5e3d) 1833 B 메서드 38, 앞 `00` 3 B, 뒤 `00` 3 B 로 IOLogicalDisk 0x1a5e40(기록됨); `__data` 48 B(0x1e50c4, `diskIoReturnValues` 6 항목).
1. 수정(plan 313 표시): ① `property_IODeviceType:length:`·`property_IODeviceClass:length:` 를 뺌; ② `setLogicalDisk:` 를 원본(0x1a5b38) 대로 `if((_nextLogicalDisk == nil) || (diskId == nil)) _nextLogicalDisk = diskId;`(GROK_APPLE 아닌 갈래); ③ `registerDevice` 의 `!_isPhysical` 갈래에서 `ret = [super registerDevice];` 를 뺌(원본 0x1a5b58: 바로 out); ④ D034 — `#ifdef DDM_DEBUG` → `#if DDM_DEBUG`(readyStateValues 표).
2. 진단 `s5p313-f1`(위 수정 + 진단 `# 1 "IODisk.m"`, 정의 추가 없음) → **OBJECT_MATCH**(38, `__data`·`__OBJC` 전부). `-DMACH_USER_API` 를 준 `s5p313-e1` 도 같음 — 정의를 더하지 않음(필요 없음).
3. 방법: 07 `src/driverkit/libDriver/IODisk.m`(mkfinal 고지 검사, D030 머리) → iter_objc(RUNIN, 정의 추가 없음) → relcheck → record_objc(A 예상). Darwin 전용 머리는 driverkit/volCheck.h 하나이고 plan 317 의 07 사본(nextdev_private/driverkit/volCheck.h)을 씀.

### codex 교차검토 판정(2026-10-05, plan 313·D034; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·메서드 38·두 property 없음·1833 B·앞뒤 `00` 3 B | 앞서 python(1833, 3) | ✅ |
| setLogicalDisk:·registerDevice 원본 명령이 계획과 같음 | 앞서 fdis·odis2 | ✅ |
| D034 의 “문자열 없음”은 넓음 — strings.tsv 에 “Not Ready”(0xd6a94) 있음 | grep strings.tsv | ✅ D034 문구 좁힘 |
| 초안 차이는 계획 넷 + 설명 주석; 초안 머리에 Darwin·NeXT 고지가 남음 | 주석은 plan 표시 규칙; 07 최종본(mkfinal)은 고지 grep 0, D030 머리 | ⚖️ 최종본은 이미 D030 꼴 |
| f.json OBJECT_MATCH 38, `__data` 48 B 차이 0 | 앞서 python | ✅ |

### 결과(2026-10-05, plan 313)

- 07 `libDriver/IODisk.m`(Darwin 본문 + plan 313 표시 넷 + D030 머리). `s5p313-it1`(RUNIN, 정의 추가 없음) OBJECT_MATCH(38), relcheck 0 → **A**.

## 318. S5-P308 세부 계획 — `libDriver/Kernel/SCSIDiskThread.m` + 머리 `driverkit/SCSIStructInlines.h`(D024·D027·D030·D031; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/SCSIDiskThread.m·driverkit/SCSIStructInlines.h 만 있음(find; Mach4·NeXTMach·SDK·07 없음).

0. 원본(python·objc.json): 모듈 "Kernel/SCSIDiskThread.m"(0x2091ac, 카테고리 `SCSIDisk(Thread)` 1) `__text` [0x1ad8b0, 0x1ae7c8) 3864 B — 메서드 7 + 정적 `sdIoThread`(0x1adf7c)·`sdThreadDequeue`; 앞은 SCSIDiskPrivate(`00` 1 B, 기록됨), 뒤 채움 없이 SCSIGeneric `deviceStyle` 0x1ae7c8(기록됨).
1. 진단(분류와 같은 머리 대체, 진단 `# 1`):
   ① Darwin 본문 그대로는 빌드 실패(`s5p318-a1`): 파일 첫머리 `#define MACH_USER_API 1`·`#undef KERNEL_PRIVATE` 상태에서 첫 import kernserv/prototypes.h → printf.h → tty.h → proc.h → user.h(07 nextdev, SDK 판)가 자기 줄 39 에서 kernserv/lock.h 를 import 하고 줄 135 에서 `lock_data_t` 를 쓰는데, KERNEL_PRIVATE 가 없으면 07 kernserv/lock.h 는 plan 136 의 kern/lock.h 갈래 대신 SDK 공개 본문(`lock_data_t` 없음)을 줌. SDK bsd/sys/user.h 도 KERNEL 에서 `lock_data_t` 를 씀.
   ② `#undef KERNEL_PRIVATE` 한 줄만 뺀 판(v2, MACH_USER_API 유지)은 빌드됨; 둘 다 뺀 판(v1)도 빌드되나 형식 문자열 참조가 더 다름.
   ③ 원본 doSdBuf:(0x1ad8b0, 1740 B; Darwin 본문 빌드 `s5p319-b1` 은 1768 B): 끝의 `if (scsiReq.driverStatus == SR_IOST_CHKSV) sdBuf->scsiReq->senseData = scsiReq.senseData;`(Darwin 주석 포함) 블록이 없음(원본 0x1ad8b0+0x6a1 에서 바로 `bytesXfr`·`status` 대입).
   ④ 원본 sdThreadDequeue(692 B; 빌드 688 B): `queue_remove` 전개가 SDK kernserv/queue.h 꼴(volCheck 와 같음) → 스테이징 `--public-sdk kernserv/queue.h`(plan 293 도구).
   v2 + ③ + `--public-sdk kernserv/queue.h`(`s5p319-f1`) → **OBJECT_MATCH**(9 항목, `__OBJC` 전부).
2. 수정(plan 318 표시): ③ 블록을 뺌(바이트가 요구); `#undef KERNEL_PRIVATE` 한 줄을 뺌 — **빌드 전용 변경**(우리 머리 묶음은 이 정의 없이 user.h 의 `lock_data_t` 를 줄 수 없음; 이 줄이 4.2 원문에 없었다는 근거는 아님 — 원본 libDriver 는 System.framework PrivateHeaders 로 빌드돼 머리 사슬이 다름). 그 밖은 Darwin 본문 그대로(`#define MACH_USER_API 1` 유지 — 형식 문자열에 필요).
3. 머리: `driverkit/SCSIStructInlines.h` → D030 사본 `nextdev_private/driverkit/SCSIStructInlines.h`(본문 그대로, 고지 없는 머리 주석, “nearly the same as Darwin 0.1 driverkit-1/driverkit/SCSIStructInlines.h”). 나머지 Darwin 머리(SCSIDisk*.h·volCheck.h)는 이미 07 사본(진단은 Darwin SCSIDisk.h 를 썼으나 `_allowLoans` 1 비트 차이는 배치 무관 — 07 빌드로 확인).
4. 방법: 07 `src/driverkit/libDriver/Kernel/SCSIDiskThread.m`(mkfinal, D030 머리) → iter_objc(RUNIN, `PUBLIC_SDK=kernserv/queue.h`, 정의 추가 없음) → relcheck → record_objc(A 예상; build_note 에 `--public-sdk kernserv/queue.h` 와 근거).

### codex 교차검토 판정(2026-10-05, plan 318; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈 0x2091ac·메서드 7·3864 B·이웃 | 앞서 python(0x1ae7c8−0x1ad8b0 = 3864), objc.json IMP 0x1ae7c8 = SCSIGeneric deviceStyle | ✅ |
| doSdBuf: sense 복사 없음, v2 바이트 일치; sdThreadDequeue 는 SDK queue_remove 꼴 | 앞서 bdiff·디스어셈블, f1 OBJECT_MATCH | ✅ |
| “빌드 1768 B” 는 v2 기준이 아님 | msizes `s5p319-b1`(Darwin 본문) 1768 | ✅ 문구에 실행 ID 를 밝힘 |
| 첫 원인은 guard 충돌이 아니라 KERNEL_PRIVATE 없을 때 공개 갈래에 `lock_data_t` 가 없는 것(user.h 가 스스로 kernserv/lock.h import) | 07 nextdev user.h:39 import, kern/lock.h 에 lock_data_t 정의 | ✅ 1-① 문구 고침 |
| sense 블록 자리의 plan 318 주석은 범위 밖 — 지울 것 | 모든 수정 자리에 plan 표시 규칙 | ❌ 기각(규칙상 남김) |
| `#undef` 제거는 빌드 전용으로 허용, 원문에 없었다는 증명은 아님 | 계획 2 항이 이미 같은 단서 | ✅ |
| 초안 머리에 APSL 고지 — D030 머리 필요 | 07 최종본(mkfinal) 고지 grep 0 | ⚖️ 최종본은 이미 D030 꼴 |
| v2.json OBJECT_MATCH 9 | 앞서 python | ✅ |

### 결과(2026-10-05, plan 318)

- 07 `libDriver/Kernel/SCSIDiskThread.m`(plan 318 표시 둘 + D030 머리), `nextdev_private/driverkit/SCSIStructInlines.h`(D030). `s5p318-it1`(RUNIN, `PUBLIC_SDK=kernserv/queue.h`; 매니페스트 `public_sdk` 확인) OBJECT_MATCH(9), relcheck 0 → **A**.
- 도구(scratchpad): record_objc 가 명세의 `public_sdk` 를 머리 채택 스테이징에도 넘김(plan 318 표시).
- 기록: objects_confirmed 240→241 줄, functions 2963→2972, PROVENANCE 792→794, MODIFICATIONS 311→313 줄.

## 319. S5-P309 세부 계획 — `libDriver/Kernel/IONetwork.m` 작성(D024·D027·D031; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/IONetwork.m 은 4.4BSD `struct ifnet`(`_ifp`·`_device`) 판으로 원본과 다른 구현 — 본문으로 쓰지 않음; SDK driverkit/IONetwork.h(07 nextdev: ivar `netif_t _netif`·`_IONetwork_reserved[4]`, 프로토콜 IONetworkDeviceMethods)와 SDK bsd/net/netif.h(`if_attach`·`if_private`·`if_*`/`if_*_set`)를 따름; Mach4·NeXTMach 같은 이름 없음.

0. 원본(python·objc.json·symbols.tsv): 모듈 "Kernel/IONetwork.m"(0x20911c, 클래스 1) `__text` [0x1a95c8, 0x1a9965) 925 B — 정적 함수 4(0x1a95c8·0x1a95f8·0x1a9630·0x1a965c; 원본 기호표에 없음, 이미지 안 참조는 `if_attach` 호출의 push 뿐) + 메서드 18; 앞 `00` 1 B(IOBufDevice shutdownUnit:), 뒤 `00` 3 B 로 IONetbufQueue init 0x1a9968(기록됨). ivar 목록 = SDK 머리(`_netif` @4, reserved[4]); Darwin 의 `getIONetworkIfnet`·`property_IODeviceClass:length:` 없음.
1. 원본 명령(odis2): 정적 넷은 `if_private(netif)` 가 0 이 아니면 각각 `finishInitialization`·`outputPacket:address:`·`allocateNetbuf`·`performCommand:data:`(셀렉터 참조 0x1f9b78·74·70·6c) 를 보내고, 아니면 −1(getbuf 는 0). `initForNetworkDevice:…` 는 `[super init]` 뒤 `_netif = if_attach(init, 0, output, getbuf, control, name, unit, type, mtu, flags, 0, device)`, `return self`. `free` 는 `if_detach(_netif)` 뒤 super free. `handleInputPacket:extra:` 는 `if_ipackets_set(_netif, if_ipackets(_netif)+1)` 뒤 `if_handle_input(_netif, pkt, extra)`. 카운터 15 개는 `if_{i,o}{packets,errors}`·`if_collisions` 와 `_set`.
2. 작성(전부 plan 319): 위 그대로. 정적 넷은 파일 앞에 원형만 두고 정의는 `@end` 뒤 — NeXT cc 는 메서드 본문을 파일 끝에서 내보내고, `-O3` 에서 주소가 아직 쓰이지 않은 정적 함수는 인라인 후보로 미뤄 메서드 뒤에 나옴(`s5p320-a1`: 바이트는 같고 위치만 뒤); 사용 뒤 정의하면 정의 즉시 나와 원본처럼 앞에 놓임(IODirectDevice 의 IODirectDeviceThread 와 같은 꼴). 이 설명은 진단 결과와 맞는 **개연성 있는 설명**이며 컴파일러 소스로 확인한 사실은 아님. `-O2`(`s5p320-b1`)는 순서는 맞으나 분기 배치가 달라 틀림. 정적 함수 이름은 원본에 남지 않아 설명적으로 붙임.
3. 진단 `s5p320-c1`(위 작성본 + 진단 `# 1 "Kernel/IONetwork.m"`, 정의 추가 없음) → **OBJECT_MATCH**(22, `__OBJC` 전부).
4. 방법: 07 `src/driverkit/libDriver/Kernel/IONetwork.m`(프로젝트 작성 머리 — D024, 원본 바이트에서 작성, Darwin 본문 아님; 기록에 “Darwin 0.1 IONetwork.m 은 다른(ifnet) 판이라 쓰지 않음”) → iter_objc(RUNIN) → relcheck → record_objc(A 예상).

### codex 교차검토 판정(2026-10-05, plan 319; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·메서드 18·925 B·앞 1/뒤 3 B·이웃·정적 넷 기호 없음 | 앞서 python·grep symbols.tsv(0 건) | ✅ |
| 정적 넷·메서드 동작, 셀렉터 해독, if_attach 인자 순서 = netif.h, NETIFCLASS_REAL = 0 | 앞서 odis2·img.py 셀렉터, netif.h 99–110 열람, grep `NETIFCLASS_REAL = 0` | ✅ |
| 기능 추가 없음; 정적 함수 이름은 프로젝트가 붙인 이름(원본 사실 아님); import 이름 확인은 relcheck 필요 | c1 python(22, 925 B, 차이 0) | ✅ 기록에 이름이 작성임을 적고 relcheck 수행 |
| 컴파일러 순서 설명은 개연성 있으나 미증명 | — | ✅ 2 항 문구에 명시 |

### 결과(2026-10-05, plan 319)

- 07 `libDriver/Kernel/IONetwork.m`(원본 바이트에서 작성, 프로젝트 머리). `s5p319-it1`(RUNIN, 정의 추가 없음) OBJECT_MATCH(22), relcheck 0 → **A**.

## 320. S5-P310 세부 계획 — `libDriver/Kernel/IOSCSIController.m`(D024·D027·D030·D031, plan 315 꼴; 코딩 전, 2026-10-05)

참조(파일명): Darwin 0.1 driverkit-1/libDriver/Kernel/IOSCSIController.m(본문 바탕); SDK driverkit/IOSCSIController.h(원본 ivar 목록과 같은 이름: `_reserveQ`·`_IOSCSIController_reserved0[62]`·`_reserveCount`·`_reserveLock`·`_worstCaseAlign`·`_IOSCSIController_reserved1[4]`); Mach4·NeXTMach 같은 이름 없음.

0. 원본(python·objc.json·이미지 ivar 목록): 모듈 "Kernel/IOSCSIController.m"(0x20916c, 클래스 1·카테고리 1) `__text` [0x1abaec, 0x1ac296) 1962 B 메서드 22(본 21 + `(private) searchReserveQ:lun:`); 앞 `00` 1 B(IOTokenRing, 기록됨), 뒤 `00` 2 B 로 IODisk(kernelDiskMethods) 0x1ac298(기록됨); `__data` 4 B(0x1e516c `scUnitNum`).
1. Darwin 이 더한 것(원본 목록에 없음): `releaseReservationElement:`·`releaseAllUnitsForOwner:`(대여 기능 — SCSIDisk 의 reacquire/requestRelease 짝, plan 314), `executeRequest:ioMemoryDescriptor:`·`executeSCSI3Request:ioMemoryDescriptor:`, `property_IODeviceClass:length:`·`property_IODeviceType:length:`.
2. 수정(plan 320 표시): ① 위 여섯 메서드를 뺌; ② `reserveElt` 의 `lender` 필드 제거, `reserveSCSI3Target:…` 는 이미 예약돼 있으면 바로 `rtn = 1`(대여 없음), 새 원소에 `lender = nil` 없음; ③ `releaseSCSI3Target:…` 는 `releaseReservationElement:` 대신 `queue_remove`·`IOFree`·`_reserveCount--`(Darwin 의 그 메서드 else 갈래와 같음); ④ `initFromDeviceDescription:` 의 간접 장치 갈래 `else [self setDeviceDescription:deviceDescription];` 없음(원본 0x1abaec: `deviceStyle` 이 직접 장치가 아니면 바로 setUnit: 쪽으로 감).
3. 진단: Darwin 본문 빌드 실패(`IOMemoryDescriptor` 형 없음, `s5p321-a1`·`b1`); ①–③ 뒤 `s5p321-d1` 은 initFromDeviceDescription: 크기만 다름(356 대 340); ④ 더한 `s5p321-e1`(`-DMACH_USER_API -UKERNEL_PRIVATE`) → **OBJECT_MATCH**(22, `__data`·`__OBJC` 전부). 정의 없이(`c1`)는 형식 문자열 참조가 다르고(`client` = `I` 필요), `-DMACH_USER_API` 만(`f1`)으로는 KERNEL_PRIVATE 로 커널 kern/queue.h 의 queue 매크로가 쓰여 free·reserveSCSI3Target·releaseSCSI3Target 크기가 다름(172/224/224 대 184/232/220) — plan 315 꼴을 씀.
4. 방법: 07 `src/driverkit/libDriver/Kernel/IOSCSIController.m`(mkfinal, D030 머리, “nearly the same as Darwin 0.1 …”) → `EXTRA_DEFS="-DMACH_USER_API -UKERNEL_PRIVATE"` iter_objc(RUNIN) → relcheck → record_objc(A 예상). Darwin 전용 머리는 쓰지 않음(분류 대체 목록에 upstream 없음).

### codex 교차검토 판정(2026-10-05, plan 320; gpt-6-luna)

| codex 주장 | 내 검증 방법 | 결과 |
|---|---|---|
| 모듈·메서드 22·여섯 없음·1962 B·앞 1/뒤 2 B | 앞서 python | ✅ |
| 원본 ivar 6 개(0x208400) | 앞서 cmpcls(img.py) 출력 | ✅ |
| **SDK 미러에 IOSCSIController.h 가 없다** — 인용을 고칠 것 | `ls -la` 로 파일 있음(1995-09-28, 2605 B), grep 31·36·40·41 줄에 같은 ivar 이름; 미러 경로 일부가 심볼릭 링크 | ❌ 기각 |
| 원본 동작(간접 갈래 setDeviceDescription: 없음, 예약 중이면 바로 1, release 는 제거·IOFree(28)·감소) | odis2: IOMalloc 앞 `push 0x1c`; 앞서 fdis | ✅ |
| 초안 차이는 계획대로 + 주석; 초안 머리에 APSL 고지 | 07 최종본은 mkfinal 로 고지 제거(grep 0) | ⚖️ 최종본은 이미 D030 꼴 |
| e.json OBJECT_MATCH, f.json 은 음성 결과 | 앞서 python | ✅ |

### 결과(2026-10-05, plan 320)

- 07 `libDriver/Kernel/IOSCSIController.m`(Darwin 본문 + plan 320 표시 + D030 머리). `s5p320-it1`(`EXTRA_DEFS="-DMACH_USER_API -UKERNEL_PRIVATE"`, RUNIN) OBJECT_MATCH(22), relcheck 0 → **A**.
