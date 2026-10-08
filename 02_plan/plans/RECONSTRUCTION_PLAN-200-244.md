# 커널 소스 복원 작업계획 — 보관 §200–244

`02_plan/RECONSTRUCTION_PLAN.md` 의 §200–244 를 절 번호·내용 그대로 옮긴 보관본(2026-10-03, D026). 인용 "RECONSTRUCTION_PLAN.md N" 은 이 파일의 같은 번호 절을 가리킨다. 아래는 원문 그대로다.

---

## 200. S5-P173 세부 계획 — `bsd/kern/kern_mman.c` (import·vm_map_entry 필드 이름, 코딩 전, 2026-10-03)

사실(원본 [0x106e30, 0x107304), objects.tsv seq 22: sbrk … ovadvise 12 함수; 다음 0x107304 `_spgrp` 는 kern_proc):
0. 진단 13 실패(`08.err`): :181·:403·:464 `current_task()->map` 에서 `->` 오류 — 이 빌드에서 current_task() 는 kernserv/prototypes.h:62 의 외부용 `current_task_EXTERNAL()` 로 잡힘; 커널용 정의는 kern/thread.h:350 `(current_thread()->task)`. :471 `entry->end` — generated `mach_old_vm_copy.h` 가 MACH_OLD_VM_COPY 1 이라 NeXTMach 는 `end` 를 쓰나 이 트리 vm/vm_map.h:127 은 `vme_end`(links.end).
1. 진단 빌드(07 아님, NeXTMach 원문의 스테이징 사본만 수정): `s5p173-d1`(+kern/thread.h import, `vme_end`) 은 sys/kern_return.h 가 machine/kern_return.h 를, vm/vm_param.h 가 없어 실패; `s5p173-d2`(그 두 import 를 mach/ 로; 선례 plan 162/164/197) 성공 — 12 함수 크기 일치, 1235 vs 1236 B(끝 채움), 비재배치 바이트 차이 0(python).

방법: NeXTMach `bsd/kern_mman.c` 를 07 로 들여 `#import <kern/thread.h>` 추가, `sys/kern_return.h`·`vm/vm_param.h` 를 mach/ 로, obreak 의 `entry->end` 를 `entry->vme_end` 로(표시). 빌드 `iter.py s5p173-itN bsd/kern/kern_mman.c kern_mman 106e30 107304`, 기록.

200 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 스테이징 사본은 NeXTMach 와 네 줄만 다름, 12 함수 비재배치 바이트 차이 0, 끝 0x107303 채움 1 B | 내 python 비교(1235/1236, 차이 0)와 같음 | ✅ |
| `__data` 29 B(`could not sbrk, return = %d\n`) 일치 | 빌드 대조(L1d)로 확정 | ⚖️ |

200 결과: it1(`s5p173-it1`) OBJECT_MATCH 12/12(`__data` 포함). 등급 A(`06_reconstruction/evidence/x86-kern_mman.md`, `.diff`).

## 201. S5-P174 세부 계획 — `bsd/kern/kern_resource.c` (import·사용자 스택 주소, 코딩 전, 2026-10-03)

사실(원본 [0x1085dc, 0x108b84), objects.tsv seq 25: getpriority … ruadd 7 함수; 다음 0x108b84 `_boot`):
0. 진단 13 실패(`11.err`): `sys/time_value.h` 와 `mach/time_value.h` 의 struct time_value 중복 정의, setrlimit :291 USRSTACK 미정의. SDK `bsd/i386/vmparam.h` 에는 USRSTACK 이 없고(m68k 판에만 0x04000000), 원본 setrlimit 은 상수 대신 `u.u_procp` 의 +0x84 를 읽음(0x108997–0x10899f, 0x1089e0–0x1089e8) = SDK `sys/proc.h:393` `vm_offset_t user_stack`(darwin01 kern_resource.c:357–359 도 `p->user_stack` — 구조 참고만).
1. 진단 빌드 `s5p174-d1`(07 아님, NeXTMach 원문 스테이징 사본에서 sys/time_value.h import 제거, vm/vm_param.h → mach/vm_param.h, USRSTACK 두 곳 → `u.u_procp->user_stack`): 7 함수 크기 일치, 1445 vs 1448 B(끝 채움), 비재배치 바이트 차이 0(python).

방법: NeXTMach `bsd/kern_resource.c` 를 07 로 들여 위 세 가지를 표시와 함께 적용(USRSTACK 은 `#if NeXT` 아래 `u.u_procp->user_stack`). 빌드 `iter.py s5p174-itN bsd/kern/kern_resource.c kern_resource 1085dc 108b84`, 기록.

201 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 스테이징 사본은 네 곳만 다름, 비재배치 바이트 1445 일치, 끝 0x108b81–0x108b83 채움 | 내 python 비교와 같음 | ✅ |
| user_stack 은 proc +0x84(디버그 형 정보 bit 1056, 원본 0x10899f·0x1089e8) | 원본 역어셈블 같은 주소 | ✅ |
| 중복된 bsd/sys/time_value.h 는 NeXTMach 사본(SDK 에는 그 경로 없음) | `ls 07_kernel/nextdev/bsd/sys/time_value.h` 없음 | ✅ 사실 0 정정(SDK 가 아니라 NeXTMach 헤더가 mach/time_value.h 와 겹침) |

201 결과: it1(`s5p174-it1`) OBJECT_MATCH 7/7. 등급 A(`06_reconstruction/evidence/x86-kern_resource.md`, `.diff`).

## 202. S5-P175 세부 계획 — `bsd/kern/kern_fork.c` (D024, POSIX 프로세스·u 영역 zone, 코딩 전, 2026-10-03)

사실(원본 [0x106818, 0x106e30), objects.tsv seq 21; 다음 0x106e30 `_sbrk` 는 kern_mman; 역어셈블 `odis.py 106818 106e30`):
0. 함수(B): fork 16, vfork 16, fork1 332, newproc 36, cloneproc 852, uzone_init 72, utask_free 88, uthread_free 24, uarea_init 24, uarea_zero 28, utask_zero 36, switch_unix_context 36. 진단 13 실패는 `u_address`(thread 에는 `_uthread` 만; utask 는 `th->task->u_address`, task.h:96). 진단 빌드 `s5p175-d1`(07 아님, 그 치환만) 은 fork·vfork·utask_free·uarea_init·uarea_zero 크기 일치, 나머지 다름.
1. fork1(isvfork): 맨 앞 `pp = alloc_posix_proc()`; MAXUPRC 계산은 같음; 실패(p2 없음 또는 a > 100) 시 `free_posix_proc(pp)` 뒤 EAGAIN; 성공 시 p1 = u.u_procp, `th = cloneproc(p1, isvfork, pp)`(newproc 대신 직접), thread_dup(current_thread(), th), `th->_uthread->uu_r.r_val1 = p1->p_pid`, r_val2 = 1, `microtime(&th->task->u_address->uu_start)`, `th->task->u_address->uu_acflag = AFORK`, u.u_r.r_val1 = p2->p_pid, thread_resume(th); out: r_val2 = 0.
2. newproc(isvfork): `return cloneproc(u.u_procp, isvfork, alloc_posix_proc())`.
3. cloneproc(rip, isvfork, pp) — utask = rip->task->u_address 를 먼저 둠; pid 탐색은 NeXTMach 와 같되 탐색 뒤 `if (!insert_posix_proc(pp, mpid))` 이면 mpid++ 부터 다시(0x106a8f–0x106a99); freeproc/getproc/panic("no procs") 같음; 새 proc 채우기 순서: p_stat = SIDL, timerclear(p_realtimer.it_value), p_flag = SLOAD | (rip 의 SPAGI|SOUSIG|SXONLY = 0x2108000, python), p_uid, `p_flag |= rip->p_flag & SCTTY`, `p_posix = rip->p_posix`, px = get_posix_proc(rip->p_pid) 에서 pp 로 p_ruid·p_svuid·p_svgid·p_posix_pgrp 복사, pp 의 utime·noctty 비트 0, p_lockf_chan 0, p_pgrp, p_nice, `p_pid = pp->p_pid`, p_ppid, p_pptr, p_osptr/ysptr/cptr 연결, p_time 0, p_cpu 0, sigmask·sigcatch·sigignore, p_tptr 0, p_aptr 0, +0x34 의 short 0, p_sig 0, p_cursig 0, p_debugger 0, pidhash_enter. 이어서 부모 utask 의 cdir·rdir VN_HOLD, crhold(uu_cred), rip->p_flag |= SKEEP, siglock·sigwait·exit_thread 0, th = procdup(rpp, rip), **그 뒤** 새 utask(rpp->task->u_address)의 uu_ofile[0..uu_lastfile] 에 대해 `== (struct file *)0xffff0000` 이면 NULL, 아니면 f_count++ (NeXTMach 는 procdup 전에 부모 쪽을 셈), lock_init(&새 utask->uu_cred_lock, TRUE), uarea_init(th), POSIX 프로세스 그룹 연결(pp->p_pgrpnxt = px->p_pgrpnxt; px->p_pgrpnxt = rpp), allproc 연결, p_stat = SRUN, spl0, SKEEP 해제, return th.
4. uzone_init: `u_task_zone = zinit(sizeof (struct utask) 0x298, TASK_MAX*sizeof 0x53000, 64*sizeof 0xa600, FALSE, "utasks"); u_thread_zone = zinit(sizeof (struct uthread) 0x158, 0x2b000, 0x5600, FALSE, "uthreads")`(문자열 0x1da879·0x1da880, python 으로 읽고 크기 계산).
5. utask_free: zfree(u_task_zone, utask). 새 uthread_free(uthread): zfree(u_thread_zone, uthread). uarea_init·uarea_zero: `th->_uthread`. utask_zero: bzero(ta->u_address, 0x298), ta->proc = 0. 새 switch_unix_context(th): `active_u[0].uthread = th->_uthread; active_u[0].utask = th->task->u_address;`(0x1e875c, 0x1e8758; 이름은 이 트리 sys/user.h 의 active_u 정의를 따름).

방법: NeXTMach `bsd/kern_fork.c` 를 07 로 들여 1–5 를 D024 표시로 작성. 빌드 `iter.py s5p175-itN bsd/kern/kern_fork.c kern_fork 106818 106e30`, 반복, 기록.

202 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0–4 와 5 의 대부분 일치(주소 대조) | 내 역어셈블(`clone.dis`, `odis.py 106cfc 106e30`)과 같음 | ✅ |
| +0x34 short 는 p_xstat | proc.h:330 `u_short p_xstat` 를 엶 | ✅ |
| utask_free 는 uu_ofile_cnt 가 있으면 kfree 둘·cnt 0 뒤 zfree(u_task_zone) — NeXTMach :320 본문 유지 | 역어셈블 0x106d4c–0x106d8c | ✅ 사실 5 문구 정정(zone 이름만 바뀜) |
| switch_unix_context 는 uthread(0x1e875c) 먼저, utask(0x1e8758) 다음 | 0x106e12–0x106e24 | ✅ 순서 반영 |
| posix_proc 플래그는 하위 두 비트만 0(reserved 유지) | 0x106b5b `and byte ptr [edi+0x18], 0xfc` | ✅ (비트필드 두 개 대입으로 작성) |

202 결과: it1(`s5p175-it1`) OBJECT_MATCH 12/12(`__data` 포함), POSIX_KERN 없는 진단 컴파일(`s5p175-noposix`) 종료 0. 등급 A(`06_reconstruction/evidence/x86-kern_fork.md`, `.diff`).

## 203. S5-P176 세부 계획 — `bsd/kern/cmu_syscalls.c` (D024, table() 의 NeXT 변경, 코딩 전, 2026-10-03)

사실(원본 [0x1020ac, 0x102934), objects.tsv seq 12: rpause 164, table 1992, table_fsparam 28; 다음 0x102934 `_task_name`):
0. 진단 13 실패(`00.err`): table() :499 USRSTACK 미정의. 진단 빌드 `s5p176-d2`(07 아님; 스테이징 사본에서 USRSTACK → `p->user_stack`, vm/vm_param.h → mach/vm_param.h): rpause 일치, table 1976 vs 1992, table_fsparam 25 vs 28(끝 채움).
1. table() 차이(역어셈블 `table.dis`):
   a. 루프 머리에서 `dealloc_start = 0;` 뒤 **`dealloc_end = 0;`** 도 저장(0x10222c–0x102236).
   b. TBL_UAREA(0x102374): pfind 실패 시 ESRCH 반환은 같음. 그 뒤 task = p->task; **task_lock(task)**(스핀·xchg); `if (task->thread_count <= 0) { task_unlock(task); u.u_error = ESRCH; return; }`(0x1023a8, 0x1021a8–0x1021b5); th = (thread_t)task->thread_list.next; **thread_reference(th)**; task_unlock(task); fake = kmem_alloc_wait(kernel_pageable_map, round_page(sizeof (struct user)) (0x800)); fake_u(fake, th); **thread_deallocate(th)**; 이어서 data/size/dealloc 는 같음. NeXTMach 의 task_reference/task_deallocate 는 없음.
   c. TBL_ARGUMENTS(0x102418): arg_size == 0 이면 bad(같음), 이어서 **`if (p->user_stack == 0) goto bad;`**(0x102451–0x102459), arg_addr = p->user_stack - arg_size(SDK sys/proc.h:393, plan 201 과 같은 필드). 나머지 같음.
   d. TBL_CPUINFO(0x10268c): `tc.ci_phz = 0`(0x1026d3, phz 대신 상수 0).
   e. 그 밖의 경우(U_TTYD, LOADAVG, FSPARAM, PROCINFO, MACHFACTOR, IOINFO, NETINFO)와 공통 꼬리는 NeXTMach 와 같은 문장으로 보임(빌드 대조로 확정).

방법: NeXTMach `bsd/cmu_syscalls.c` 를 07 로 들여 vm/vm_param.h → mach/ 와 1a–1d 를 D024 표시로 작성. 빌드 `iter.py s5p176-itN bsd/kern/cmu_syscalls.c cmu_syscalls 1020ac 102934`, 반복, 기록.

203 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1a–1d 확인(0x10222c·0x102236, 0x102394–0x1023e8, 0x102451–0x102461, 0x1026d3) | 내가 `table.dis` 에서 읽은 주소와 같음 | ✅ |
| 1e: 나머지 경우·공통 꼬리·rpause·table_fsparam 같음; 점프 표 0x1022ac 는 자료 | 내 rdiff 의 나머지 차이는 점프 표 자료와 레지스터 배정 차이뿐이었음 | ⚖️ 빌드 대조로 확정 |

203 결과: it1(`s5p176-it1`) OBJECT_MATCH 3/3. 등급 A(`06_reconstruction/evidence/x86-cmu_syscalls.md`, `.diff`).

## 204. S5-P177 세부 계획 — `bsd/kern/kern_descrip.c` (D024, FPINPROGRESS 예약·재검사·POSIX 잠금, 코딩 전, 2026-10-03)

사실(원본 [0x103e3c, 0x104c2c), objects.tsv seq 18: getdtablesize … expand_fdlist 23 함수):
0. 진단 13 실패(`04.err`): `current_task()->u_address` 의 `->`(kern_mman 과 같음, plan 200) → `#import <kern/thread.h>`. 진단 빌드 `s5p177-d1`(07 아님, import 만): getdtablesize·getdopt·setdopt·dupit·fset·fgetown·fsetown·fioctl·fstat·ufavail·file_init·free_file·rewhence·flock 은 크기·모양 일치(rdiff 0). 다름: dup 152/136, dup2 292/252, fcntl 1020/972, close 208/176, ufalloc 152/132, falloc 256/252, getf 72/52, closef 120/76, expand_fdlist 244/198.
1. SDK `sys/file.h:119–126`: `#define FPINPROGRESS ((void *)0xffff0000)` 과 NeXT GETF(범위는 `u.u_ofile_cnt`, NULL 과 FPINPROGRESS 면 EBADF). NeXTMach 의 GETF 사용처는 이 매크로로 자동으로 맞음. (plan 202 cloneproc 의 0xffff0000 리터럴은 이 이름이었음 — 뒤에 이름으로 바꿀 후보.)
2. ufalloc(0x1046f0): 빈 칸을 찾으면 r_val1·pofile 0·lastfile 갱신 뒤 **`u.u_ofile[i] = (struct file *)FPINPROGRESS`**(0x10475b) 하고 i 반환.
3. getf(0x104900): `(unsigned)f >= u.u_ofile_cnt` 또는 NULL 이면 EBADF·NULL; `fp == FPINPROGRESS` 면 EBADF 를 설정하고 fp 를 그대로 반환(0x104930–0x104940); 아니면 fp.
4. dup(0x103e60)·fcntl F_DUPFD(0x104110): ufalloc 뒤 **`if (u.u_ofile[fd] != fp) { u.u_ofile[i] = NULL; EBADF; return; }`**, 그 뒤 dupit(인라인). dup2(0x103ef8): GETF, j 범위, r_val1, i==j, expand_fdlist 뒤 **`u.u_ofile[i] != fp` 또는 `u.u_ofile[j] == FPINPROGRESS` 면 EBADF**, u_ofile[j] 가 있으면 vno_lockrelease·munmapfd·closef·u_error=0, 그 뒤 **다시 `u.u_ofile[i] != fp` 면 EBADF**, dupit(j, fp, u_pofile[i]).
5. fcntl: F_SETFL 의 보존 마스크가 `u.u_procp->p_posix ? (FCNTLCANT|_POSIX_FILE_FLAGS) (0x400031b3) : FCNTLCANT (0x21b3)`(0x104208–0x104220; 새 비트 마스크 ~FCNTLCANT 는 그대로; python 계산). SUN_LOCK F_GETLK/SETLK/SETLKW: DTYPE_VNODE 아니면 EBADF 뒤 **`!p_posix` 이거나 vnode v_type != VREG 이면 EINVAL**(0x1042ff–0x104317); l_type 검사·rewhence·음수 길이·start<0·UF_FDLOCK/SLKDONE 같음; VOP_LOCKCTL 오류는 그대로 반환(EWOULDBLOCK→EACCES 변환 없음); F_GETLK 이면 F_UNLCK 일 때 l_type 2 B, 아니면 **rewhence(oldwhence) 없이** 20 B copyout.
6. close(0x104568): closef 뒤 **`if (u.u_procp->p_posix && u.u_error == ENOSPC && (fp->f_flag & FNOSPC)) u.u_error = 0;`**(0x10460b–0x104629).
7. closef(0x104948): f_count > 1 이면 감소 반환; **`if (fp->f_count != 1) panic("fp not one\n")`**; fo_close; crfree; **`if (fp->f_count != 1) panic("fp not one2\n")`**; f_count = 0; free_file(문자열 0x1da669·0x1da675).
8. falloc(0x104800): 인라인된 ufalloc(FPINPROGRESS) 뒤 NeXTMach 의 `u.u_ofile[i] = fp` 가 없음(호출자가 넣음 — plan 179·180 의 copen·socket 등과 맞음).
9. expand_fdlist(0x104b38): 두 kalloc 뒤 **`old_cnt = utask->uu_ofile_cnt` 를 다시 읽어 `n < old_cnt` 면 둘 다 kfree 하고 반환**(0x104b75–0x104b99), 그 밖은 같음.

방법: NeXTMach `bsd/kern_descrip.c` 를 07 로 들여 kern/thread.h import 와 2–9 를 D024 표시로 작성(FPINPROGRESS 이름 사용). 빌드 `iter.py s5p177-itN bsd/kern/kern_descrip.c kern_descrip 103e3c 104c2c`, POSIX 없는 진단 컴파일, 기록.

204 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 3 오류: FPINPROGRESS 경로는 fp 가 아니라 eax 에 남은 uthread 포인터(0x104937 `mov eax, [0x1e875c]`)를 반환 | `odis.py 104900 104948` 다시 읽음: 0x104937–0x104943 에서 eax 를 덮은 뒤 그대로 ret | ✅ 내 오기 정정 — 값 없는 `return;`(K&R)의 결과로 작성 |
| dup·dup2 는 _dupit 호출, F_DUPFD 는 인라인 | 0x103ee9·0x10400c call, 0x10416a–0x1041ba 인라인 | ✅ (dupit 정의 위치상 자연스러움) |
| 나머지 사실 0–2·4–9 맞음, F_SETFL 새 비트 마스크 0xffffde4c 는 두 경우 공통 | 내 역어셈블과 같음(python 마스크 계산) | ✅ |
| close 는 closef 뒤 fp->f_flag 를 읽음 | 0x104623 | ✅ (사실 6 그대로) |

### 204.1 결과
- it1(`s5p177-it1`): 22/23, expand_fdlist 241 vs 244(레지스터 배정). 변형 `s5p177-v1`: a `n < (old_cnt = cnt)`, c `(old_cnt = cnt) > n` 은 차이 169, b `if (n < utask->uu_ofile_cnt) {...} old_cnt = utask->uu_ofile_cnt;` 차이 0 → b.
- it2(`s5p177-it2`): OBJECT_MATCH 23/23(`__data` 포함), POSIX_KERN 없는 진단 컴파일(`s5p177-noposix`) 종료 0.

204 결과: 등급 A(`06_reconstruction/evidence/x86-kern_descrip.md`, `.diff`).

## 205. S5-P178 세부 계획 — `bsd/kern/kern_synch.c` (D024, continuation sleep, 코딩 전, 2026-10-03)

사실(원본 [0x10a588, 0x10abb0), objects.tsv seq 30: sleep 384, sleep_with_continuation 400, sleep_with_continuation_and_deadline 460, rpsleep 176, rpcont 36, wakeup 40, wakeup_one 40, rqinit 40):
0. 진단 13 실패(`12.err`): `sys/machine.h`·`sys/time_value.h`(NeXTMach 헤더)가 SDK `mach/machine.h`·`mach/time_value.h` 와 중복 정의(plan 201 과 같은 종류). 진단 빌드 `s5p178-d1`(07 아님, 두 import 만 제거): rpsleep·rpcont·wakeup·wakeup_one 크기 일치, sleep 376 vs 384, rqinit 48 vs 40, tsleep·slave_start 는 빌드에만 — `_tsleep`·`_slave_start` 기호는 커널에 없음; schedcpu 는 NeXTMach 에서도 `#if !NeXT`.
1. 세 sleep 함수는 같은 몸체(같은 printf 문자열 주소 0x1daa77·0x1daa8e "unix sleep: on slave?\n" 를 공유 — 기호 없는 static inline 도우미가 세 곳에 인라인되었다고 봄): rp = u.u_procp; s = splhigh(); rp 면 p_pri = pri & PMASK; assert_wait(chan, pri > PZERO); pri > PZERO 이면 rp 이고 ISSIG 꼴(issig(1) 호출 — SDK ISSIG_CATCH 와 같은 인자)이면 clear_wait(current_thread(), THREAD_INTERRUPTED, TRUE)·spl0 뒤 psig, 아니면 **deadline 이 있으면 thread_set_timeout(hzto(deadline))**, spl0, ru_nvcsw++, slave 검사 printf, **thread_block_with_continuation(continuation)**, 다시 신호 검사; pri <= PZERO 도 deadline·spl0·ru_nvcsw·printf·thread_block_with_continuation; 끝 spln(s)(= splx), return 0; psig: **continuation 이 있으면 call_continuation(continuation)**, PCATCH 면 1, 아니면 jump_label(&u.u_qsave)(= longjmp).
2. sleep(chan, pri) = 도우미(chan, pri, 0, 0)(0x10a654·0x10a6c8 `push 0` 뒤 thread_block_with_continuation; psig 의 continuation 호출은 상수 접힘으로 없음); sleep_with_continuation(chan, pri, continuation) = 도우미(chan, pri, continuation, 0); sleep_with_continuation_and_deadline(chan, pri, continuation, deadline) = 도우미(chan, pri, continuation, deadline)(0x10a940–0x10a950, 0x10a9d0–0x10a9e0).
3. rqinit: `simple_lock_init(&callout_lock)` 없음(callout 모델 변경, plan 181).
4. NeXTMach 의 printf 문자열은 "unix sleep: on slave?"(개행 없음); 원본은 개행 있음.

방법: NeXTMach `bsd/kern_synch.c` 를 07 로 들여 두 중복 import 제거, sleep 을 static inline 도우미 + 세 진입점으로 작성(D024, 도우미 이름 미복원), rqinit 의 callout_lock 초기화 제거, tsleep·slave_start 는 원본에 없으므로 `#if !NeXT` 로 제외. 빌드 `iter.py s5p178-itN bsd/kern/kern_synch.c kern_synch 10a588 10abb0`, 반복, 기록.

205 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 공유 문자열 주소는 static inline 도우미를 증명하지 않음(재구성 선택) | 맞음 | ⚖️ 사실 1 문구 한정(선택으로 기록) |
| issig(1)(ISSIG_CATCH), clear_wait(…, 2, 1), PMASK 0x7f, PCATCH 0x100, deadline 은 첫 신호 검사 뒤·spl0 앞, call_continuation 은 PCATCH 검사 앞 | 내 역어셈블 같은 주소들 | ✅ |
| 끝은 `_spln`(splx 와 다른 함수, 별칭 없음) → 명시 spln 호출 | 원본 기호표: `_spln` 0x18c1a8, `_splx` 0x18b544; 진단 객체 재배치는 `_splx` | ✅ 사실 1 정정(헤더 매핑 아님 → `spln(s)` 작성) |
| jump_label 주소는 `_longjmp` 와 같은 주소(별칭) | 기호표 `_longjmp`·`_jump_label` 모두 0x186fb0 | ✅ longjmp 유지 |

205 결과: it1(`s5p178-it1`) OBJECT_MATCH 8/8(`__data` 포함). 등급 A(`06_reconstruction/evidence/x86-kern_synch.md`, `.diff`).

## 206. S5-P179 세부 계획 — `bsd/ufs/ufs_dsort.c` (고전 disksort·thread NULL 검사, 코딩 전, 2026-10-03)

사실(원본 [0x13f90c, 0x1405ec), objects.tsv seq 131; `_disksort` 의 2140 B 는 고전 disksort 152 B(0x13f90c) + 기호 없는 정적 ds_enter_common 1988 B(0x13f9a4, 정렬 프롤로그 python):
0. 진단 13 실패(`75.err`): `next/spl.h` 없음 → `machine/spl.h`(07 tty_pty.c 등과 같은 경로).
1. NeXTMach 은 고전 `disksort(dp, bp)` 를 `#if NeXT #else` 로 빼 두었으나 원본에는 `_disksort`(0x13f90c) 가 있음 — 진단 빌드 `s5p179-d3`(07 아님; 스테이징 사본에서 import 교체와 그 블록을 컴파일) 에서 disksort 152 B·ds_enter_common 1988 B·enter_head/tail·first·remove·init 크기 일치, disksort_free 39 vs 40(끝 채움).
2. disksort_enter(0x140168): 맨 앞에서 `th = current_thread()`(0x140174) 를 읽어 두고, 직접 경로에서 **`if (th) bp->b_rtpri = th->priority;`**(0x1401dc–0x1401e3) 후 ds_enter_common. NeXTMach 은 NULL 검사 없이 `current_thread()->priority`.

방법: NeXTMach `ufs/ufs_dsort.c` 를 07 로 들여 import 교체, 고전 disksort 를 NeXT 에서도 컴파일(조건 바꿈, 표시), disksort_enter 를 2 대로 작성. 빌드 `iter.py s5p179-itN bsd/ufs/ufs_dsort.c ufs_dsort 13f90c 1405ec`, 기록.

206 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 스테이징 사본은 두 곳만 다름; disksort_enter 외 모든 함수 비재배치 바이트 일치, disksort_free 끝 0x1405eb 채움 | 내 rdiff 8 함수 모양 0 | ✅ |
| disksort_enter 의 th NULL 검사(0x140174, 0x1401dc–0x1401e6) | 내 역어셈블 같음 | ✅ |

### 206.1 it 결과
- it1(`s5p179-it1`): 바이트 차이 0 이나 L1 이 ds_enter_common·disksort_first·disksort_remove 에서 재배치 대상 하나씩 다르다고 판정 — 빌드는 `_spldma`, 원본은 `_splbio`(0x18b97c; `_spldma` 0x18bcc8 도 커널에 있음). 내 rdiff(모양 정규화)와 codex 의 비교(재배치 자리 가림) 모두 이 이름 차이를 놓침 → codex 판정표의 "✅" 중 바이트 일치 주장은 재배치 대상 이름까지는 확인하지 않은 것으로 한정.
- 수정: 세 곳 `s = spldma();` → NeXT 에서 `splbio()`.
- it2(`s5p179-it2`): OBJECT_MATCH 9/9.

206 결과: 등급 A(`06_reconstruction/evidence/x86-ufs_dsort.md`, `.diff`).

## 207. S5-P180 세부 계획 — `bsd/ufs/ufs_subr.c` (bufstats 가변 배열·update getthetime, 코딩 전, 2026-10-03)

사실(원본 [0x142884, 0x143024), objects.tsv seq 133: update … locc 12 함수; 앞 0x142008 `_lf_lockctl` 은 다른 객체, locc 의 기호 크기 2556 은 0x143024 이후의 기호 없는 함수들(정렬 프롤로그 0x143024·0x1430a8 …, python)까지 포함):
0. 진단 13 실패(`77.err`): bufstats :407 `NeXT_MIN_CLBYTES`(NeXTMach next/machparam.h:29 에만 있음, SDK 에 없음).
1. 원본 bufstats(0x142e4c): `counts` 크기를 `MAXBSIZE / page_size + 1` 로 실행 중 계산해 스택에 잡음(0x142e55–0x142e69 `div [page_size]`, `sub esp, eax`) = NeXTMach 의 `#else` 쪽 `int counts[MAXBSIZE/CLBYTES+1];`(SDK param.h:169 CLBYTES = CLSIZE*NBPG, NBPG 가 page_size 변수) 의 GNU 가변 길이 배열. 컴파일러가 이를 받아들였다는 것은 원본 바이트가 증거.
2. update(0x142884): `fs->fs_time = time.tv_sec` 대신 지역 timeval 에 getthetime 후 tv_sec(0x142926 근처 `lea eax,[ebp-N]; push; call` 뒤 `mov edx,[ebp-N]`). 나머지는 NeXTMach NeXT 분기와 같음.
3. 진단 빌드 `s5p180-d1`(07 아님; counts 선언만 CLBYTES 꼴로): update 340 vs 344(2 의 차이), 나머지 11 함수 크기 일치(locc 37 vs 40 은 끝 채움).

방법: NeXTMach `ufs/ufs_subr.c` 를 07 로 들여 bufstats 의 counts 를 NeXT 에서도 `MAXBSIZE/CLBYTES+1` 로, update 의 fs_time 을 getthetime 꼴로(표시). 빌드 `iter.py s5p180-itN bsd/ufs/ufs_subr.c ufs_subr 142884 143024`, 기록.

207 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0–3 맞음; 11 함수는 비재배치 바이트·재배치 대상 이름 모두 일치, update 만 getthetime(0x142923–0x14292f) | 내 rdiff·역어셈블과 같음(relcheck 는 update 크기 차이로 뒤가 밀려 이 시점에는 쓸 수 없음) | ✅ |
| bufstats 의 `_bfreelist+0x110` 참조는 원본 `_buf` 주소와 같은 값(이름 식이 다름) | 07 빌드 L1 대조에서 확인 | ⚖️ |

207 결과: it1(`s5p180-it1`) OBJECT_MATCH 12/12(`__data` 포함). 등급 A(`06_reconstruction/evidence/x86-ufs_subr.md`, `.diff`).

## 208. S5-P181 세부 계획 — `bsd/vfs/vfs_bio.c` (D024, vn_devblocksize·brelvp_wakeup·btrash, 코딩 전, 2026-10-03)

사실(원본 [0x119b8c, 0x11b28c), objects.tsv seq 54; 끝에 기호 없는 정적 함수 bsetvp 0x11b244·brelvp 0x11b26c(정렬 프롤로그, 역어셈블 `bio_tail.dis`); fnsizes 의 binval 164 는 그 둘을 합친 값(실제 92)):
0. 진단 13 실패(`30.err`): btodb 인자 1 개 — SDK `sys/param.h:219` NeXT 분기는 `btodb(bytes, blocksize)`; getblk 의 DEV_BSHIFT 도 NeXT 에 없음. 진단 빌드 `s5p181-d2`(07 아님; btodb(x,512)·DEV_BSHIFT 9 임시값): bread·breada·vnReadAhead·breadDirect·bwrite·bdwrite·bawrite·incore·geteblk·getnewbuf_count·biowait·bflush·geterror 크기 일치; 다름: brelse, getblk, brealloc, getnewbuf, biodone, blkflush, binvalfree; 원본에만 brelvp_wakeup·btrash; 빌드에만 vnStartRead·vnCleanBuffer·baddr·bsetvp·brelvp(원본 기호표에 없음).
1. brealloc(0x11a6cc)·blkflush(0x11ac31): `devblksize = VOP_DEVBLOCKSIZE(vp)`(SDK vnode.h:160, v_op+0x80), 음수면 `panic("Couldn't determine device blocksize!\n")`(0x1db5e7·0x1db619 두 사본), btodb(x, devblksize)(u_long size 는 div, int b_bcount 는 idiv — SDK 매크로 그대로). blkflush 는 맨 앞에서 계산, brealloc 은 overlap 검색 직전(vp = bp->b_vp).
2. getblk: DEV_BSHIFT 로 blkno 를 자르는 검사 없음(그 밖 같음).
3. brelse(0x11a288)와 biodone 안의 인라인 사본: `if ((bp->b_flags & (B_NOCACHE|B_DELWRI)) == B_NOCACHE) bp->b_flags |= B_INVAL;`, 그리고 주석이던 `else if (bp->b_flags & B_AGE) flist = &bfreelist[BQ_AGE];` 가 살아 있음. 끝 마스크는 같음(0x4001c8, python).
4. getnewbuf: 끝의 brelvp(bp) 없음(0x11aa28 `b_flags = B_BUSY` 바로 앞).
5. 새 brelvp_wakeup(bp)(0x11af0c): brelse(bp) 본문(인라인) 뒤 brelvp(bp).
6. binvalfree(0x11b020): B_DELWRI 면 `bp->b_iodone = brelvp_wakeup; bp->b_flags |= B_CALL|B_ASYNC;`(0x11b067–0x11b06e) 뒤 notavail·splx·bwrite(인라인), 아니면 같음.
7. 새 btrash(vp)(0x11b158): splhigh 아래 freelist 를 돌며 `bp->b_vp == vp || vp == 0` 이면 `b_flags = (b_flags & ~B_DELWRI) | B_INVAL; brelvp(bp); splx(s); goto loop;`, 끝 splx.
8. bsetvp·brelvp 는 static(파일 끝, 호출보다 뒤 정의라 인라인 안 됨 — 앞쪽 static 선언 필요). vnStartRead·vnCleanBuffer 는 static(breadDirect 에 인라인되어 별도 본문 없음 — 진단 빌드에서도 인라인되어 breadDirect 크기 일치). baddr 는 원본에 없음(사용처 없음 → 제외).

방법: NeXTMach `bsd/vfs_bio.c` 를 07 로 들여 1–8 을 D024 표시로 작성. 빌드 `iter.py s5p181-itN bsd/vfs/vfs_bio.c vfs_bio 119b8c 11b28c`, 크기가 맞으면 relcheck 로 호출 대상 이름 확인, 반복, 기록.

208 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0–7 대체로 맞음; brealloc 시작 0x11a5e4(호출 0x11a6d6), blkflush 0x11ac28(호출 0x11ac3e) | 내가 적은 주소는 호출 근처(0x11a6cc·0x11ac31)였음 — 시작 주소 보충 | ✅ |
| 바뀐 brelse 논리는 brealloc(0x11a837)·biodone(0x11ab47)·brelvp_wakeup(0x11af43) 의 인라인 사본에도 | brelse 를 고치면 인라인 사본도 같이 바뀜 | ✅ (사실 3 보강) |
| binvalfree 의 notavail 안은 splbio, 바깥은 splhigh, bwrite 인라인 | `bio_tail.dis` 0x11b074·0x11b026 | ✅ |
| btrash(0) 은 freelist 에 버퍼가 있으면 계속 다시 고름(흐름상 추론) | 역어셈블 흐름 그대로 — 원본 동작으로 기록만 | ⏭️ |
| 사실 8 의 static 은 원본이 증명하지 않음(재구성 선택), baddr 는 "이 범위에 없음"까지만 | 맞음 | ⚖️ 문구 한정 — 빌드 대조로 판정 |
| 범위 전체 호출 대상 목록(splbio/splhigh 구분) | relcheck 로 07 빌드에서 확인 예정 | ⏭️ |

### 208.1 결과
- 07 경로 `07_kernel/src/bsd/vfs/vfs_bio.c`(진단 13·스테이징 도구의 논리 경로 src/bsd/vfs 를 따름; 새 디렉터리).
- it1: btrash 가 biowait 의 geterror 호출 앞에 잘못 들어가 컴파일 실패 → 기준점을 정의 줄로 고쳐 파일 재생성. it2(`s5p181-it2`): 23/25 — brealloc·blkflush 겹침 검사에서 jae(빌드) vs jge(원본): SDK btodb 의 unsigned 캐스트 때문 → 그 두 곳은 `ep->b_bcount / devblksize`(부호 있는 나눗셈).
- it3(`s5p181-it3`): OBJECT_MATCH 25/25(`__data` 포함).

208 결과: 등급 A(`06_reconstruction/evidence/x86-vfs_bio.md`, `.diff`).

## 209. S5-P182 세부 계획 — `bsd/kern/uipc_socket.c` (mach/exception.h·POSIX EAGAIN·selthreadclear, 코딩 전, 2026-10-03)

사실(원본 [0x114bd4, 0x116120), objects.tsv seq 49: socreate … sohasoutofband 17 함수):
0. 진단 13 실패(`25.err`): `sys/exception.h` — SDK 에 bsd/sys/exception.h 가 없어 NeXTMach 사본이 쓰이고, 그것이 `machine/exception.h` 를 찾다가 실패. SDK 는 `mach/exception.h` 를 가짐.
1. 진단 빌드 `s5p182-d2`(07 아님; 스테이징 사본에서 `#import <sys/exception.h>` → `<mach/exception.h>`, 동반 스테이징 kern_mman·subr_xxx): 14 함수 크기 일치, sosend 1216/1256, soreceive 1688/1724, sohasoutofband 100/104.
2. sosend(0x115068) SS_NBIO 경로(0x11523b–0x115264): `if (first) { error = EWOULDBLOCK; if (u.u_procp->p_posix && (uio->uio_fmode & FPOSIX_PIPE)) error = EAGAIN; }`(uio_fmode +0x10 short, 0x2000 = FPOSIX_PIPE, SDK file.h:85).
3. soreceive(0x115550) SS_NBIO 경로(0x1156a1–0x1156c9): `error = EWOULDBLOCK; if (p_posix && (uio->uio_fmode & FPOSIX_PIPE)) error = EAGAIN;`.
4. sohasoutofband(0x1160b8): selwakeup 뒤 `so->so_rcv.sb_sel = 0` 대신 `selthreadclear(&so->so_rcv.sb_sel)`(plan 187 의 uipc_socket2 와 같은 select 모델).

방법: NeXTMach `bsd/uipc_socket.c` 를 07 로 들여 import 교체와 2–4 를 표시와 함께 작성(POSIX 부분은 `#if POSIX_KERN`). 빌드 `iter.py s5p182-itN bsd/kern/uipc_socket.c uipc_socket 114bd4 116120`, relcheck, POSIX 없는 진단 컴파일, 기록.

209 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 14 함수 일치(재배치 대상 포함), 사실 2–4 확인 | 내 역어셈블과 같음 | ✅ |
| **추가 차이**: sosend 끝 EPIPE 뒤 `thread_doexception(current_thread(), …)` 대신 `exception_from_kernel(EXC_SOFTWARE, EXC_UNIX_BAD_PIPE, 0)`(0x11553b) | `sosend.dis` 0x11553b `call _exception_from_kernel`; 07 subr_xxx.c:117–123 의 같은 대체 선례 | ✅ 채택 — 내 rdiff 는 호출 이름을 가려 놓쳤음 |

### 209.1 결과
- it1(`s5p182-it1`): 15/17 — EAGAIN 검사에서 u.u_procp 읽기와 EWOULDBLOCK 저장의 순서. 변형 `s5p182-v1`(v1 지역 p, v2 삼항, v3 if/else) 모두 차이 0 → v3(plan 188 fifo 와 같은 꼴).
- it2(`s5p182-it2`): OBJECT_MATCH 17/17(`__data` 포함), POSIX_KERN 없는 진단 컴파일(`s5p182-noposix`) 종료 0.

209 결과: 등급 A(`06_reconstruction/evidence/x86-uipc_socket.md`, `.diff`).

## 210. 보류 메모 — `bsd/kern/kern_exec.c` (분석만, 2026-10-03)

- 원본 [0x104c2c, 0x105a3b) + 기호 없는 정적 함수 0x105a3c(execve 가 호출, kern_exit 앞). 진단 빌드(07 아님): `s5p183-d1` sys/exception.h 교체만 → vm/vm_param.h·NeXTMach sys/loader.h 의 헤더들 실패; `s5p183-d2`(vm_param → mach/, sys/loader.h → SDK mach-o/loader.h, 진단 사본에 SDK 헤더 복사) → USRSTACK 두 곳; `s5p183-d3`(ucp = u.u_procp->user_stack, create_unix_stack(map, user_stack) — 원본 0x1057f0 이 두 인자로 proc->user_stack 저장 후 스택을 잡음) → execv·create_unix_stack 일치, load_init_program 380/384, check_exec_access 123(원본 기호 크기 256 은 뒤 영역 포함), **execve 2472/2972**.
- 원본 execve 는 fatfile_getarch·task_secure·get_posix_proc·exception_from_kernel·lock_write/lock_done·load_machfile·정적 0x105a3c 를 부름 → fat 바이너리·POSIX setuid 처리 등 큰 작성 필요. 다른 객체 뒤로 미룸.

## 211. S5-P185 세부 계획 — `bsd/kern/kern_proc.c` (D024, POSIX 프로세스 그룹·세션·posix_proc, 코딩 전, 2026-10-03)

사실(원본 [0x107304, 0x107a78), objects.tsv seq 23; 함수 spgrp … uthread_from_thread 20 개 + 기호 없는 정적 0x10782c; 역어셈블 `odis.py 107304 107a78`):
0. 진단 13 실패(`09.err`): `zone_t` 미정의(kern/zalloc.h import 없음). 진단 빌드 `s5p185-d1`(07 아님, import 만): spgrp·inferior·pfind·pidhash_enter·getproc 크기 일치, pqinit 130/152, 나머지 14 함수는 NeXTMach 에 없음.
1. 객체 경계: posix_proc 함수·*_from_thread 가 이 객체에 속하는지는 원본만으로 확정 불가(4 B 정렬로 이어짐) — 이어진 배치를 근거로 kern_proc 에 두는 재구성 선택. objects.tsv text_end 0x10782c 는 기호 기준 추정값.
2. `proc_count` 는 기호 없는 정적(`__bss` 0x1e56c0), `proc_zone` 은 기호 있는 전역(0x1e94f8) → `zone_t proc_zone;`(static 아님).
3. proc_cache_clear(0x107400): `while (freeproc) { proc_count--; p = freeproc; freeproc = p->p_nxt; zfree(proc_zone, p); }`.
4. pqinit(0x107440): proc_zone = zinit(0x88, 100*max_proc*size(0x3520*max_proc), 0, FALSE, "proc structures"); proc_count = 0; freeproc = 0; p = getproc()(인라인); **bzero(p, sizeof (struct proc))**; allproc 등 NeXTMach 와 같음.
5. pgfind(pgid)(0x1074d8): pgrphash[pgid & 0x3f] 를 pg_hforw 로 돌며 pg_id 비교.
6. enterpgrp(p, pgid, mksess)(0x107504): pgrp = pgfind(pgid)(인라인); px = get_posix_proc(p->p_pid); pgrp 가 없으면 kalloc(sizeof (struct pgrp) 0x14), mksess 면 kalloc(sizeof (struct session) 0x10) 에 s_leader = p, s_count = 1, s_ttyp = 0, s_ttyd = 0, `p->p_flag &= ~SCTTY`, pg_session = sess; 아니면 pg_session = px->p_posix_pgrp->pg_session, s_count++; pg_id, 해시 삽입, pg_jobc = 0, pg_mem = 0. pgrp 가 있고 `pgrp->pg_id == px->p_pgid` 면 반환. `if (p->p_posix) { fixjobc(p, pgrp, 1); fixjobc(p, px->p_posix_pgrp, 0); }`. 옛 그룹 구성원 목록에서 p 제거: `for (pp = &px->p_posix_pgrp->pg_mem; pp; pp = &get_posix_proc((*pp)->p_pid)->p_pgrpnxt) if (*pp == p) { *pp = px->p_pgrpnxt; goto done; }` 뒤 panic("enterpgrp: can't find p on old pgrp")(0x1da8b6); done: 옛 그룹 pg_mem 이 비면 pgdelete; px->p_posix_pgrp = pgrp; px->p_pgrpnxt = pgrp->pg_mem; pgrp->pg_mem = p; p->p_pgrp = px->p_posix_pgrp->pg_id.
7. leavepgrp(p)(0x10765c): 같은 목록 제거이나 반복 조건은 `*pp`(enterpgrp 는 `pp`), panic("leavepgrp(): can't find p in pgrp")(0x1da8da), 그 뒤 빈 그룹 pgdelete, px->p_posix_pgrp = 0, p->p_pgrp = 0.
8. pgdelete(pgrp)(0x1076d8): pgp = &pgrphash[PIDHASH(pg_id)]; 세션 s_ttyp 가 있고 `ttynty(s_ttyp)->t_posix_pgrp == pgrp` 면 그것을 0, 그 nty 의 tty t_pgrp = 0; 해시 사슬에서 제거(없으면 panic("pgdelete: can't find pgrp on hash chain") 0x1da8fc); `--s_count == 0` 이면 s_ttyp 가 있을 때 ttynty(s_ttyp)->t_session = 0, kfree(session, 0x10); kfree(pgrp, 0x14).
9. fixjobc(p, pgrp, entering)(0x107780)와 정적 orphanpg(pg)(0x10782c): 4.4BSD 꼴이나 그룹은 get_posix_proc(...)->p_posix_pgrp, 구성원 사슬은 p_pgrpnxt; SZOMB 5, SSTOP 6, SIGHUP·SIGCONT.
10. get_posix_proc(pid)(0x107898): posix_proc_hash[pid & 0x3f] 를 p_next_posix_proc 로 돌고, 없으면 `char buf[80]; sprintf(buf, "get_posix_proc(): no posix proc struct for pid %d", pid); panic(buf);`(반환문 없음). alloc_posix_proc(): kalloc(32) 에 `__TEXT,__const` 의 0 원형(0x1d10bc, 32 B)을 구조체 대입(`static const struct posix_proc … = { 0 }` 꼴, plan 182 select_zero 와 같음). free_posix_proc(pp): kfree(pp, 32). insert_posix_proc(pp, pid): 있으면 0, 아니면 p_pid 저장·해시 앞 삽입·1. new_posix_proc(pid): 있으면 0, 아니면 kalloc(32)·p_pid·삽입·반환. delete_posix_proc(p): 해시 사슬에서 p->p_pid 를 찾아 제거·kfree(32), 없으면 sprintf·panic("delete_posix_proc(): …").
11. proc_from_thread(th): th 가 0 이면 0, 아니면 th->task->u_address->uu_procp; utask_from_thread: th->task->u_address; uthread_from_thread: th->_uthread.

방법: NeXTMach `bsd/kern_proc.c` 를 07 로 들여 kern/zalloc.h import, 2–11 을 D024 표시로 작성. 빌드 `iter.py s5p185-itN bsd/kern/kern_proc.c kern_proc 107304 107a78`, relcheck, zerofill(proc_count), POSIX 없는 진단 컴파일, 기록(등급은 `__bss`·`__const` 판정에 따름).

211 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 기호 있는 함수 21 개(NeXTMach 에 없는 것 15 개) | symbols.tsv 0x107304–0x107a78 다시 셈: 21 | ✅ 사실 0 정정 |
| 세 *_from_thread 모두 NULL 이면 0(0x107a2a·0x107a46·0x107a62) | 내 역어셈블 같음 | ✅ 사실 11 정정 |
| orphanpg 는 SSTOP 구성원을 찾은 뒤 전체를 다시 돌며 SIGHUP·SIGCONT | 0x10783c·0x10784c–0x10786f | ✅ (사실 9 명시) |
| new_posix_proc 는 alloc_posix_proc 를 부르지 않고 kalloc 뒤 p_pid·링크만 | 0x107987–0x1079a8 | ✅ |
| proc_count static·원형 선언 꼴은 추론(재구성 선택) | 맞음 | ⚖️ |
| 진단 산출물(09.err, s5p185-d1)을 찾지 못함 | 08_build/runs/s5p124-diag-13/stage/_log/09.err, 08_build/runs/s5p185-d1 존재 확인 | ❌ 산출물은 있음(codex 접근 문제) |

### 211.1 it 결과
- it1(`s5p185-it1`): proc_from_thread 분기 배치 반대 → 변형 `s5p185-v1`(v1 삼항·v3 if/else·v4 삼항 차이 19, v2 `if (th) return …; return NULL;` 차이 0) → v2.
- it2(`s5p185-it2`): free_posix_proc 레지스터(eax vs edx — 반환형 void), delete_posix_proc 끝 바이트, utask/uthread_from_thread 분기 배치. **객체 경계 정정**: 함수 앞 채움 바이트를 python 으로 확인 — 0x107304 앞과 0x107a24 앞만 0x00(링커 채움), 나머지는 0x90(컴파일러) → kern_proc 는 [0x107304, 0x107a24)(posix_proc 함수 포함), proc_from_thread·utask_from_thread·uthread_from_thread 는 0x107a24 부터 시작하는 다음 객체(setprivexec 0x107a78 앞도 0x90 이라 kern_prot 쪽) — 사실 1 정정, 세 함수는 kern_prot 작업으로 옮김(07 에서 제거, 사본 보관).
- it3(`s5p185-it3`, 범위 [0x107304, 0x107a24)): free_posix_proc 만 레지스터 차이; 변형 `s5p185-v2`·`v3`(kfree 인자·반환·매개변수 꼴) 효과 없음; it4: `#import <kern/kalloc.h>`(kfree 프로토타입) → 모든 함수 일치, L1 사유 `__bss: unverified` 하나. it5: POSIX 블록을 `#if POSIX_KERN` 으로 감쌈(같은 결과), POSIX 없는 진단(`s5p185-noposix2`) 종료 0(첫 시도 `s5p185-noposix` 는 가드 없어 실패).
- zerofill reference-inferred [0x1e56c0, 0x1e56c4) 4 B(proc_count), 참조 5, Delta 하나; 알려진 배치 27 건(`zerofill-known-s5p185-20261002.json`).

211 결과: 등급 P(`06_reconstruction/evidence/x86-kern_proc.md`, `.diff`). proc_from_thread 등 세 함수는 kern_prot 작업에서 (사본 scratchpad `from_thread.c`, v2 꼴로 바꿔 쓸 것).

## 212. S5-P186 세부 계획 — `bsd/kern/kern_prot.c` (D024, *_from_thread·POSIX setuid/setgid·setsid/setpgid, 코딩 전, 2026-10-03)

사실(원본 [0x107a24, 0x1085dc), 기호 있는 함수 27 개; 0x107a24 앞과 0x1085da–0x1085dc 는 0x00(링커 채움, 211.1); 역어셈블 `odis.py`):
0. 진단 빌드 `s5p186-d1`(NeXTMach 원문 + `#import <kern/thread.h>`, getpid 의 `u_address.uthread` → `_uthread`): getpid·getpgrp·getuid·getgid·setreuid·setregid·setgroups·leavegroup·entergroup·groupmember·crget·crfree·crcopy·crdup 크기 일치; getgroups 224/200, setpgrp 132/124, suser 76/52; NeXTMach 에 없는 것 proc_from_thread·utask_from_thread·uthread_from_thread·setprivexec·getposix·setposix·_setuid·_setgid·setsid·setpgid.
1. 함수 순서(원본 주소순): proc_from_thread, utask_from_thread, uthread_from_thread, setprivexec, getpid, getpgrp, getuid, getgid, getposix, setposix, getgroups, setpgrp, setreuid, _setuid, _setgid, setregid, setgroups, leavegroup, entergroup, groupmember, suser, crget, crfree, crcopy, crdup, setsid, setpgid.
2. *_from_thread(0x107a24/0x107a40/0x107a5c): 211.1 의 v2 꼴(`if (th) return …; return NULL;`), 각각 th->task->u_address->uu_procp, th->task->u_address, th->_uthread(thread+0x84).
3. setprivexec(0x107a78): uap = u.u_ap; `current_thread()->_uthread->uu_r.r_val1 = u.u_procp->p_debugger`(비트 0 부호 확장); `u.u_procp->p_debugger = (uap->arg != 0)`; `return 0`(int 반환).
4. getposix(0x107ba0): `u.u_r.r_val1` = p_posix(proc+0x16 비트 1) 를 0/1 로(shr·and 1, 부호 확장 아님).
5. setposix(0x107bc4): `(unsigned) uap->arg > 1` 이면 r_val1 = -1, u_error = EINVAL(0x16); 아니면 r_val1 = p_posix(부호 확장), p_posix = arg & 1.
6. getgroups(0x107c1c): NeXTMach 와 같은 앞부분 뒤 `if (u.u_procp->p_posix)` 이면 `u.u_error = copyout(u.u_groups, uap->gidset, gidsetsize * sizeof (gid_t))`(int 배열 변환 없음), 아니면 NeXTMach 변환 루프 + copyout; 공통 꼬리(u_error 검사·r_val1).
7. setpgrp(0x107cfc): 마지막 `p->p_pgrp = uap->pgrp` 대신 `enterpgrp(p, uap->pgrp, 0)`.
8. _setuid(0x107e60): uid = (uid_t) uap->uid, ruid = u.u_ruid, px = get_posix_proc(u.u_procp->p_pid); uid < 0 이면 EINVAL; svuid = px->p_svuid(+6); suser() 가 아니면 uid 가 ruid·svuid 어느 것과도 다르면 EPERM, suser 면 `ruid = svuid = uid`; u.u_error = 0; u_cred_lock(); u.u_cred = crcopy(u.u_cred); px->p_ruid = ruid(+4), u.u_ruid = ruid, u.u_uid = uid, u.u_procp->p_uid = uid; u_cred_unlock(); px->p_svuid = svuid.
9. _setgid(0x107f48): 8 과 같은 꼴, rgid = u.u_rgid, svgid = px->p_svgid(+8); 잠금 안에서 u.u_rgid = rgid, u.u_gid = gid 만(px 에 rgid 저장 없음); 끝에 px->p_svgid = svgid.
10. suser(0x108310): 먼저 `current_thread()->task->u_address->uu_procp == 0` 이면 0 반환(active_threads 경유, active_u 아님); u.u_uid != 0 이면 EPERM·0; 아니면 u_acflag |= ASU·1.
11. setsid(0x108474): p = u.u_procp; px = get_posix_proc(p->p_pid); `px->p_pgid == p->p_pid || pgfind(p->p_pid)` 이면 EPERM; 아니면 enterpgrp(p, p->p_pid, 1), u.u_r.r_val1 = p->p_pid. (4.4BSD setsid 와 같은 구조, 그룹은 posix_proc 경유.)
12. setpgid(0x1084d0): uap{pid, pgid}; uap->pgid < 0 이면 EINVAL; curpx = get_posix_proc(curp->p_pid); `uap->pid != 0 && uap->pid != curp->p_pid` 이면 targp = pfind, 없거나 !inferior 면 ESRCH, targpx = get_posix_proc(targp->p_pid), 세션 다르면 EPERM, `targp->p_flag & SEXEC`(0x80000000) 이면 EACCES(0xd); 아니면 targp = curp, targpx = curpx. `SESS_LEADER(targp, targpx)`(SDK sys/proc.h:254) 면 EPERM; `uap->pgid == 0` 이면 `uap->pgid = targp->p_pid`(0x108588–0x10858c 에서 uap 에 되씀), 0 아니고 targp->p_pid 와 같으면 pgfind 생략(0x108594–0x10859a), 그 밖이면 pgfind 결과가 없거나 세션 다르면 EPERM; enterpgrp(targp, uap->pgid, 0).
13. (codex 검토로 정정) `_cractive` 는 원본 `__DATA,__data` 0x1da98c(4 B, crget·crfree·crcopy·crdup 이 0x108374·0x1083ab·0x1083da·0x108417·0x108451 에서 참조), `_rootcred` 는 common 0x1e9058 — NeXTMach `int cractive = 0;`·`struct ucred *rootcred;`(kern_prot.c:329·331) 그대로. `__data` 판정은 빌드 산출로.

방법: NeXTMach `bsd/kern_prot.c` 를 07 로 들여 `#import <kern/thread.h>`·getpid 의 `_uthread`, 2–12 를 D024 표시로 작성(POSIX 의존 부분은 `#if POSIX_KERN` 검토). 빌드 `iter.py s5p186-itN bsd/kern/kern_prot.c kern_prot 107a24 1085dc`, relcheck, POSIX 없는 진단 컴파일, 기록. Darwin 0.1 kern_prot 는 구조 참고도 하지 않음(원본 바이트만).

212 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 사실 0–11 맞음(주소 근거 제시) | 사실 3–11 의 역어셈블은 내가 이 세션에서 직접 읽음(odis 107a78·107ba0·107c1c·107cfc·107e60·107f48·108310·108474); 0 은 s5p186-d1 결과 | ✅ |
| 12 미흡: pgid 0 이면 uap->pgid 에 되씀, 같은 pid 면 pgfind 생략 | `kern_prot.dis` 0x108586–0x10858c·0x108594–0x10859a | ✅ 사실 12 보완 |
| 13 틀림: `_cractive` `__data` 0x1da98c, `_rootcred` common 0x1e9058 | symbols.tsv 해당 행, 역어셈블 참조 5 곳(codex 는 4 곳 — 0x108451 crdup 누락), NeXTMach :329·:331 | ✅ 사실 13 정정(내 오류) |
| _setuid/_setgid 는 허용된 경우에도 suser() 를 먼저 부르고 u_error = 0 으로 지움 | 0x107eaf·0x107ed9, 0x107f97·0x107fc1 | ✅ (사실 8·9 와 같음) |

### 212.1 it 결과
- it1(`s5p186-it1`): setposix 92/88, _setuid 236/232, setpgid 266/268(마지막 함수 — 차이는 원본 끝 링커 채움 0x00 2 B 뿐). 변형 `s5p186-v1`(_setuid 선언 순서 4 × 저장 꼴 3): 연쇄 대입 `u.u_ruid = px->p_ruid = ruid; u.u_procp->p_uid = u.u_uid = uid;` 이면 선언 순서와 무관하게 차이 0 → d0s1. 변형 `s5p186-v2`(setposix 4 꼴): `register int flag = uap->flag; if (flag == 0 || flag == 1) … else …` 만 차이 0 → p4(사실 5 의 `(unsigned) > 1` 은 같은 비교의 다른 표기).
- it2(`s5p186-it2`): 27 함수 모두 일치, OBJECT_MATCH, relcheck 불일치 0.
- POSIX 없는 진단 `s5p186-noposix` 실패(struct posix_proc 불완전) → _setuid·_setgid, setsid·setpgid 를 `#if POSIX_KERN` 으로, setpgrp 는 `#if POSIX_KERN` enterpgrp / `#else` NeXTMach `p->p_pgrp = uap->pgrp`. it3(`s5p186-it3`) 같은 결과(OBJECT_MATCH, relcheck 0), `s5p186-noposix2` 종료 0.

212 결과: 등급 A(`06_reconstruction/evidence/x86-kern_prot.md`, `.diff`). 헤더 변경 없음 → 회귀 불필요. SDK `sys/timeb.h` 의 PROVENANCE 행이 기록 도구로 추가됨(D017, 내용은 gitignore).

## 213. S5-P187 세부 계획 — `bsd/kern/kern_exit.c` (D024, continuation wait·waitpgrp·POSIX 세션, 코딩 전, 2026-10-03)

사실(원본 [0x105ac0, 0x106818), 기호 있는 함수 rexit·exit·do_exit·wait4·wait·wait3·wait1·waitpgrp·init_process 9 개; 0x1059c0 check_exec_access 는 kern_exec 쪽, 0x106818 부터 kern_fork(확정); 역어셈블 `odis.py 105ac0 106818`):
0. 진단 13 실패(`06.err`): `kern/ipc_globals.h` 없음. 진단 `s5p187-d4`(NeXTMach 원문 + ipc_globals.h 제거, sys/kern_return.h → mach/kern_return.h, sys/time_value.h 제거, wait 의 R0/R1 임시 치환; 07 아님): rexit 만 크기 일치(24); exit 36/24, do_exit 1520/1272, wait4 124/128, wait 52/72, wait3 96/80, wait1 780/764, init_process 120/108, waitpgrp 없음. (`s5p187-d1` 은 경로 오류로 run 이 만들어지지 않음, `d2`·`d3` 은 헤더 오류.)
1. exit(rv)(0x105ad8): do_exit(u.u_procp, rv) 뒤 `thread_halt_self_with_continuation(0)` 을 무한 반복(0x105af0–0x105afa).
2. do_exit(p, rv)(0x105afc) — NeXTMach 와 같은 흐름에 다음이 다름:
   a. 맨 앞 `px = get_posix_proc(p->p_pid)`(0x105b0d, [ebp-0x24]).
   b. 열린 파일 루프: `f != NULL && f != FPINPROGRESS`(0x105c50 `cmp ebx, 0xffff0000`), vno_lockrelease 호출(SUN_LOCK 꼴); uu_ofile·uu_pofile 는 포인터(utask+0x150·+0x154), uu_lastfile +0x158.
   c. od_unlock_check 없음.
   d. aptr 블록 뒤 POSIX 블록: `if (p->p_posix && SESS_LEADER(p, px))`: sp = px->p_session; `sp->s_ttyp` 가 있고 `ttynty(sp->s_ttyp)->t_session == sp`(ttynty 한 번 호출, 결과 재사용) 이면 그 nty 의 t_posix_pgrp 가 있으면 pgsignal(…, SIGHUP, 1), ttywait(sp->s_ttyp); 그리고 sp->s_leader = 0(0x105ef6–0x105f44). 이어 `if (p->p_posix) fixjobc(p, get_posix_proc(p->p_pid)->p_posix_pgrp, 0)`(0x105f4b–0x105f68; p_posix 거짓이면 두 블록 모두 건너뜀).
   e. tptr 블록: psignal·wakeup 뒤 `p->p_tptr->p_aptr = 0`(0x106034–0x10603a).
   f. 새 블록(0x106047–0x106096): `if (u.u_prof.pr_lock) { u.u_prof.pr_scale = 0; simple_lock_free(u.u_prof.pr_lock); }`, 이어 u.u_prof.pr_next 사슬을 `kfree(pr, sizeof (struct uuprof))`(0x18) 로 해제(utask+0x248 pr_lock, +0x24c pr_next, +0x25c pr_scale — SDK user.h uuprof).
   g. 끝에 `p->task = TASK_NULL; p->thread = THREAD_NULL`(0x1060b5·0x1060bc), NeXTMach 와 같음.
   h. 문자열: panic("exit") 0x1da847, printf("init exited with %d\n") 0x1da84c.
3. wait1(options, ru, status, pid, cont)(0x1061fc): 매개변수 5 개(마지막은 continuation, wait4/wait/wait3 가 자기 주소를 넘김). f 는 `u.u_wait.f`(uthread+0x88 = SDK user.h `uu_state.ss_wait.f`, `#define u_wait uthread->uu_state.ss_wait`). 앞부분: `if (u.u_error < 0)`(char, 0x106210) 이면 thread_wait_result() 가 THREAD_INTERRUPTED(2)·THREAD_SHOULD_TERMINATE(3) 일 때 `p = u.u_procp; if (u.u_sigintr & sigmask(p->p_cursig)) unix_syscall_return(EINTR); u.u_eosys = RESTARTSYS; unix_syscall_return(0);` 아니면 `u.u_error = 0`; `u.u_error >= 0` 이면 `u.u_wait.f = 0`. 본문 루프는 NeXTMach 와 같되 좀비 정리에서 ruadd/kfree 뒤 `leavepgrp(p); delete_posix_proc(p);`(0x10631b–0x106322). 끝: f 0 이면 ECHILD, WNOHANG 이면 r_val1 = 0·0, 아니면 `u.u_error = -1; sleep_with_continuation((caddr_t)u.u_procp, PWAIT, cont);`(setjmp·goto loop 없음, 반환값 없음).
4. wait4(0x1060ec): `error = wait1(ap->options, &ru, &status, ap->pid, wait4)`; error 면 unix_syscall_return(error); rusage·status copyout 결과를 error 에; 끝에 unix_syscall_return(error)(u.u_error 직접 대입 없음).
5. wait(0x106168): `error = wait1(0, 0, &status, 0, wait); u.u_r.r_val2 = status; unix_syscall_return(error);`(지역 status; PSL_ALLCC·R0/R1 분기 없음).
6. wait3(0x10619c): rup = uap->rup; `error = wait1(uap->options, &ru, &u.u_r.r_val2, 0, wait3)`; error 면 unix_syscall_return(error); rup 면 copyout 결과를 error 에; unix_syscall_return(error).
7. waitpgrp(0x106508), uap{pgrp, status, options}: f(지역) = 0; loop: curproc = u.u_procp; 자식 중 `uap->pgrp == p->p_pgrp` 만, f++; 좀비면 r_val1 = p_pid, `u.u_error = copyout(&p->p_xstat, uap->status, sizeof (int))`(4 B), 오류면 0 반환, p_xstat = 0, p_ru 처리(ruadd·kfree), leavepgrp·delete_posix_proc, 정리(wait1 과 같되 **p_pgrp = 0 없음**), 0 반환; 정지(wait1 과 같은 조건, options 는 uap->options) 면 SWTED, r_val1, 지역 status 계산 뒤 `u.u_error = copyout(&status, uap->status, sizeof (int))`, 0 반환. f 0 이면 u_error = ECHILD; WNOHANG 이면 status = 0, r_val1 = 0, copyout; `setjmp(&u.u_qsave)` 이면 sigintr 검사로 u_error = EINTR 또는 u_eosys = RESTARTSYS; 아니면 sleep(u.u_procp, PWAIT), goto loop. 모든 반환값 0.
8. init_process(0x1067a0): unix_master/unix_release 흔적 없음; 마지막 `p->p_pgrp = p->p_pid` 대신 `if (p->p_pgrp != p->p_pid) enterpgrp(p, p->p_pid, 0);` 그 뒤 p_ppid = 0.

방법: NeXTMach `bsd/kern_exit.c` 를 07 로 들여 헤더 정리(0 의 치환을 07 에 반영, 근거 기록), 1–8 을 D024 표시로 작성(POSIX 부분은 `#if POSIX_KERN`). 빌드 `iter.py s5p187-itN bsd/kern/kern_exit.c kern_exit 105ac0 106818`, relcheck, POSIX 없는 진단 컴파일, 기록. Darwin 0.1 은 원문을 옮기지 않음.

213 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| struct proc 오프셋(0x2e·0x34·0x3c·0x80 등) 일치 | python 으로 proc.h 필드 크기 누적(p_pptr 0x44 … p_aptr 0x80, user_stack 0x84), uuprof pr_lock 0x248·pr_next 0x24c·pr_scale 0x25c·sizeof 0x18 | ✅ |
| 0 미흡: 진단 결과는 역어셈블로 확인 불가 | 맞음 — 진단 결과는 `s5p187-d4` fnsizes 출력이 근거(이 세션에서 실행) | ⚖️ 근거만 보완 |
| 2d: 두 번째 p_posix 검사는 별개(0x105f4e), 비리더 POSIX 프로세스도 fixjobc | kern_exit.dis 0x105efd `je 0x105f70`, 0x105f0b `jne 0x105f4b`, 0x105f4e `test` | ✅ (사실 2d 와 같음) |
| 2f: pr_lock 유무와 상관없이 사슬 해제 | 0x106053 je 0x106073 뒤 0x106073 부터 사슬 | ✅ (사실 2f 와 같음) |
| 2h: 문자열 내용은 역어셈블로 증명 안 됨 | mach_kernel 바이트를 python 으로 읽음: 0x1da847 "exit", 0x1da84c "init exited with %d\n" | ✅ 근거 보완 |
| 3: 정상 continuation 재개 때 u_error = 0 이고 f 는 유지 | 0x10625c–0x106265(u_error = 0 뒤 0x106272 로, f 저장 없음); 새 호출만 0x106268 에서 f = 0 | ✅ 사실 3 명확화 |
| 4: rusage copyout 오류 뒤에도 status copyout 이 error 를 덮어씀 | 0x10612b–0x106153 | ✅ (사실 4 와 같음) |
| 7: waitpgrp 에 p_pgrp = 0 직접 저장은 없으나 leavepgrp 가 지움; 좀비 status copyout 은 p_xstat(2 B)부터 4 B | python 저장 목록 비교(wait1 에는 0x2e 있음, waitpgrp 에는 없음); 07 kern_proc.c:303 leavepgrp `p->p_pgrp = 0`; 0x106561–0x10656b | ✅ (재구성은 바이트대로: 직접 저장 없음, 4 B copyout) |

### 213.1 it 결과
- it1(`s5p187-it1`): struct nty 불완전 → `#import <sys/tty.h>`(plan 211 과 같음). it2(`s5p187-it2`): exit·do_exit·wait4·wait·wait3 크기 일치; wait1 784/780, waitpgrp 668/664, init_process 119/120(마지막 함수, 끝 채움).
- wait1: 변형 `s5p187-v1` — switch 꼴 3 가지(788·784·808 B) 모두 다르고, `register int r = thread_wait_result(); if (r == THREAD_INTERRUPTED || r == THREAD_SHOULD_TERMINATE) … else u.u_error = 0;`(w1) 만 차이 0.
- waitpgrp: `s5p187-v2`(포인터 선언 순서 4 가지) 효과 없음; `s5p187-v3` 에서 uap 를 register 아닌 변수로 하면 크기 일치(b, 차이 89); `v4`(WNOHANG 대입 순서·ECHILD 꼴) 효과 없음; `v5` setjmp 분기를 `if (…) u.u_error = EINTR; else u.u_eosys = RESTARTSYS; return (0);` 로(s1, 차이 7); `v6` 에서 `u.u_r.r_val1 = status = 0;`(t2) 차이 0. 원본의 반환 경로 공유(0x10666a)가 이 꼴의 근거.
- unix_master()/unix_release() 는 NCPUS 1 에서 빈 매크로(stage `kern/parallel.h:72`)라 바이트로 판단 불가 → NeXTMach 원문 유지.
- it3(`s5p187-it3`): 9 함수 모두 일치, OBJECT_MATCH, relcheck 0. POSIX 없는 진단 `s5p187-noposix` 종료 0.

213 결과: 등급 A(`06_reconstruction/evidence/x86-kern_exit.md`, `.diff`). 헤더 변경 없음 → 회귀 불필요.

## 214. S5-P190 세부 계획 — `bsd/ufs/ufs_alloc.c` (D024, 실린더 그룹 byte swap·btodb 2 인자, 코딩 전, 2026-10-03)

사실(원본 함수 verify_and_swap_cg … fserr 18 개, 역어셈블 `odis.py 13b714 13d830`):
0. 객체 경계 [0x13b714, 0x13d830): 0x13b714 앞은 앞 함수의 `ret` 바로 뒤(채움 없음, 4 B 정렬), 0x13b768 앞은 0x90 2 B(컴파일러 채움) → verify_and_swap_cg 는 ufs_alloc 의 첫 함수; 0x13d830 은 확정 객체 ufs_bmap 의 시작. verify_and_swap_cg 를 부르는 call 은 커널 전체 e8 스캔에서 0 건(인라인만 됨; 앞에 정의된 전역 함수라 -O3 에서 인라인되고 본체도 남음).
1. 진단 13 실패: btodb 인자 1 개(SDK sys/param.h:220 은 `btodb(bytes, blocksize)`). 진단 `s5p190-d1`(NeXTMach `ufs/ufs_alloc.c` + `#undef btodb`·`#define btodb(x) ((unsigned)(x) / 512)` 임시, 07 아님): fssleep·fspause·ialloc·dirpref·hashalloc·alloccgblk·mapsearch·fserr 크기 일치; 차이(원본−빌드, python): alloc 20, fsfull −8, realloccg 60, blkpref 76, fragextend 76, alloccg 104, ialloccg 76, free_block 76, ifree 72.
2. verify_and_swap_cg(bp)(0x13b714): cgp = bp->b_un.b_cg; `bp->b_flags & B_ERROR` 면 brelse·0; byte_swap_cylgroup(cgp); `cgp->cg_magic != CG_MAGIC`(0x90255, fs.h:301) 면 byte_swap_cylgroup(cgp)(되돌림)·brelse·0; 아니면 1. byte_swap_cylgroup 는 선언 없음(외부, 0x192ff8).
3. alloc·realloccg: `btodb(size)` → `btodb(size, VOP_DEVBLOCKSIZE(ITOV(ip)))`(v_op+0x80 간접 호출 후 idiv; alloc 1 곳 0x13b855, realloccg 2 곳).
4. fsfull(0x13b8c0): cmesg·umesg 가 레지스터(ebx·esi), which 는 메모리; panic 가지에서 panic 전에 둘을 0 으로(0x13b8f4 `xor esi`·`xor ebx`).
5. blkpref(0x13c0ac): 맨 앞 `if (bap && indx > 0)` 이면 이전 블록 = `bap == &ip->i_db[0]` 이면 bap[indx-1], 아니면 bswap(bap[indx-1])(NXSwapBigLongToHost, plan 178 과 같음); 이후 `bap[indx - 1]` 자리는 모두 그 값; `bap[indx - fs->fs_maxcontig]` 도 같은 조건부 swap(0x13c21c–0x13c248).
6. fragextend·alloccg·ialloccg·free_block·ifree: `bp->b_flags & B_ERROR || cgp->cg_magic != CG_MAGIC` 검사가 `verify_and_swap_cg(bp)` 로 바뀜(그 밖의 조건 — alloccg 의 cs_nbfree, ialloccg 의 cs_nifree — 은 그 뒤 따로, 실패 때 byte_swap_cylgroup·brelse); `cgp->cg_time = time.tv_sec` → `getthetime(&tv); cgp->cg_time = tv.tv_sec`; verify 이후 모든 brelse·bdwrite 앞에 byte_swap_cylgroup(cgp)(fragextend 는 bp->b_un.b_cg 를 다시 읽음, 0x13c602·0x13c61c).
7. 문자열은 NeXTMach 와 같은 것으로 보이나(printf/panic 위치 동일) 빌드의 `__cstring` 비교로 확인.

방법: NeXTMach `ufs/ufs_alloc.c` 를 07 `bsd/ufs/ufs_alloc.c` 로 들여 2–6 을 D024 표시로 작성. 빌드 `iter.py s5p190-itN bsd/ufs/ufs_alloc.c ufs_alloc 13b714 13d830`, relcheck, 기록.

214 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 미흡: 채움 바이트·호출 0 건만으로 경계·인라인을 증명하지 못함 | 맞음 — 경계는 재구성 선택(0x13b714 앞 채움 없음, 0x13b768 앞 0x90), 인라인은 빌드로 확인 예정 | ⚖️ 사실 0 을 "추정" 으로 읽음 |
| 1 미흡: 진단 결과는 산출물 필요 | `s5p190-d1` fnsizes 출력(이 세션 실행), 차이는 python 계산 | ⚖️ 근거 보완 |
| 2 맞음 | 0x13b714–0x13b765 직접 읽음 | ✅ |
| 3 맞음(0x13b862, 0x13bc0f, 0x13bdf8) | `ufs_alloc.dis` 에서 `[reg + 0x80]` 로드 뒤 간접 호출 3 곳 grep | ✅ |
| 4 명령 관찰로는 맞으나 원문 대입은 추정 | 맞음 — 변형으로 정함 | ⚖️ |
| 5 미흡: bap 0 또는 indx <= 0 이면 이전 블록 값이 초기화되지 않음(반환 아님) | 0x13c0be–0x13c0eb | ✅ 사실 5 보완(그 경우 값 미초기화) |
| 6 미흡 표현: B_ERROR 해제는 swap 없이, magic 실패는 되돌림 swap 뒤 | python 호출 순서 추출(함수별 bread·swap·brelse·bdwrite 열)과 같음 | ✅ |
| 7 문자열 내용은 바이너리로 확인됨 | 빌드 `__cstring` 비교로 다시 확인 예정 | ⏭️ (행동 불변) |
| free_block·ifree 끝 wakeup 경로 그대로 | `s5p190-d1` rdiff free_block 차이가 verify 부분에 국한 | ✅ |

### 214.1 it 결과
- it1(`s5p190-it1`): 18 함수 크기 모두 일치(8476 B), blkpref(347 B 차이)·free_block(163 B) 만 다름. free_block: "freeing free block" printf 의 둘째 인자가 `bno + i` 가 아니라 `bno`(원본 0x13d05a `push [ebp+0xc]`; NeXTMach 의 미초기화 i 사용이 고쳐짐) → 수정.
- blkpref: 변형 `s5p190-v1`(조건식·if 꼴 4 가지), `v2`(register 선언·db 변수), `v3`(선언 순서 8 가지) 효과 없음. 원본은 둘째 자리에서 swap 결과를 첫 prevblk 와 같은 스택 슬롯([ebp-0x1c])에 담은 뒤 비교 → `v4` e1b(`(bap != &ip->i_db[0]) ? NXSwapBigLongToHost(…) : …` 꼴, 둘째 자리는 `prevblk = …; if (prevblk + blkstofrags(…) != nextblk)`) 차이 0.
- fsfull 의 `cmesg = umesg = 0;`(사실 4 의 추정) 은 it1 에서 바로 일치.
- it2(`s5p190-it2`): 18 함수 모두 일치, OBJECT_MATCH, relcheck 0. verify_and_swap_cg 인라인 확인(빌드에서도 호출 없음).

214 결과: 등급 A(`06_reconstruction/evidence/x86-ufs_alloc.md`, `.diff`). 헤더 변경 없음 → 회귀 불필요. SDK `ufs/quotas.h` PROVENANCE 행이 기록 도구로 추가됨(D017).

## 215. S5-P191 세부 계획 — `bsd/ufs/ufs_inode.c` (D024, inode byte swap·inode_cache_clear·btodb 2 인자, 코딩 전, 2026-10-03)

사실(원본 [0x1405ec, 0x142008), 기호 있는 함수 new_inode … iaccess 15 개; 0x1405ec 앞 0x00(링커 채움); 역어셈블 `ufs_inode.dis`):
0. 진단 13 실패: btodb 인자 1 개. 진단 `s5p191-d1`(NeXTMach `ufs/ufs_inode.c` + 임시 btodb, 07 아님): new_inode·ihinit·iput·irele·idrop·iinactive·iflush·ilock·iunlock·iaccess 크기 일치; iget 1112/1128, iupdat 352/396, itrunc 3236/3348, indirtrunc 440/412, inode_cache_clear 없음. remque/insque 는 kern/queue.h 인라인(원본에도 호출 없음).
1. inode_cache_clear()(0x140664, new_inode 와 ihinit 사이): (가) `while ((ip = ifreeh) != NULL)`: iget 의 free list 제거와 같은 꼴(`if (iq = ip->i_freef) iq->i_freeb = &ifreeh; ifreeh = iq; ip->i_freef = NULL; ip->i_freeb = NULL;`), mfs_uncache(ITOV(ip)), `ip->i_flag = IRELEASE_TO_ZONE`(0x8000, SDK inode.h:222) 뒤 `|= ILOCKED`(ILOCK 꼴), `ITOV(ip)->v_count != 0` 이면 panic("free inode isn't")(0x1ddfb0), remque(ip)(인라인). (나) inode_list 를 돌며 `i_flag & IRELEASE_TO_ZONE`(short 부호 검사) 인 것을 목록에서 빼고(첫 원소면 inode_list 갱신) `zfree(vm_info_zone, ip->i_vnode.vm_info)`, `zfree(inode_zone, ip)`.
2. iget(0x140798): `ip->i_ic = dp->di_ic` 구조체 대입 → `byte_swap_inode_in(dp, ip)`(0x140b29, 인자 순서 dp, ip).
3. iupdat(0x140eb4): `dp->di_ic = ip->i_ic` → `byte_swap_inode_out(ip, dp)`(0x140fc7); 사용자 마운트 때 `dp->di_uid`·`di_gid` 는 i_ruid·i_rgid 를 부호 확장해 32 비트 bswap 한 값의 하위 16 비트(0x140fdc–0x140ff2; NXSwap…Long 을 short 에 대입한 꼴 — 원본 동작 그대로). ASSERT 흔적 없음(원래 컴파일 안 됨).
4. itrunc(0x141014): btodb 3 곳(nblocks, `btodb(bsize)`, `btodb(oldspace - newspace)`)이 `btodb(…, VOP_DEVBLOCKSIZE(ITOV(ip 또는 oip)))`(간접 호출 0x14163a·0x141abf·0x141bfe); iupdat 는 인라인되어 3 의 변경이 함께 들어감.
5. indirtrunc(0x141cb8): `nblocks = btodb(fs->fs_bsize, VOP_DEVBLOCKSIZE(ITOV(ip)))`(0x141d19), `nb = NXSwapBigLongToHost(bap[i])` 두 곳(0x141dd8·0x141e39).
6. byte_swap_inode_in/out 은 선언 없음(외부 0x1930b8·0x1931b8).

방법: NeXTMach `ufs/ufs_inode.c` 를 07 `bsd/ufs/ufs_inode.c` 로 들여 1–5 를 D024 표시로 작성(architecture/byte_order.h import). 빌드 `iter.py s5p191-itN bsd/ufs/ufs_inode.c ufs_inode 1405ec 142008`, relcheck, 기록.

215 codex 검토 판정(코딩 전; 첫 검토 k4t0602kd 가 늦어 범위를 줄인 재검토도 받음, 두 회신 모두 판정):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 미흡: 진단 결과는 산출물 필요 | `s5p191-d1` fnsizes 출력(이 세션 실행) | ⚖️ 근거 보완 |
| 1 맞음, 단 ifreet 은 갱신하지 않음 | `ufs_inode.dis` 0x140664–0x14073b 에 `_ifreet` 참조 없음(grep) | ✅ 사실 1 보완(ifreet 그대로) |
| 2 맞음(dp, ip) | 0x140b27 push ebx(ip)·0x140b28 push edi(dp) | ✅ |
| 3 맞음; 양수 id 는 0x0000, 음수는 0xffff 저장, itrunc 인라인 3 곳도 같음 | 0x140fdc–0x140ff2, bswap 위치 grep(0x1412fc·0x141598·0x14195c 등) | ✅ |
| 4 미흡: 세 VOP 호출 모두 ITOV(oip) | 0x141beb–0x141bf7 `[ebp+8]`(oip)+0xc 확인 | ✅ 사실 4 정정(모두 oip) |
| 5 맞음 | 0x141d06–0x141d28, 0x141dd8, 0x141e39 | ✅ |
| 6 선언 없음은 소스 수준 판단 | 맞음 | ⚖️ |
| iget 은 new_inode 를 인라인(코드 생성 차이) | NeXTMach 순서상 new_inode 가 iget 앞 — 자동 인라인 | ✅ (변경 불필요) |

### 215.1 it 결과
- it1(`s5p191-it1`): iget·iupdat·indirtrunc 등 13 함수 일치; inode_cache_clear 212/216, itrunc 3252/3236. itrunc: 원본은 MACH_NBC 블록(IUNLOCK·mfs_trunc·ILOCK)을 fast link 검사 **앞**에 둠(0x141034–0x141098) → 07 에서 순서 이동.
- inode_cache_clear: 변형 `s5p191-v1`(첫 루프 iq 와 둘째 루프 next 를 한 변수로, 선언 순서 4 가지 — 모두 차이 6) → `s5p191-v2` g1(`prev = inode_list = ip->inode_list;`) 차이 0.
- iupdat 의 uid/gid 저장은 NXSwapHostLongToBig 로 씀(32 비트 swap 이름은 바이트로 구별 불가 — 선택 기록).
- it2(`s5p191-it2`): 15 함수 모두 일치, OBJECT_MATCH, relcheck 0.

215 결과: 등급 A(`06_reconstruction/evidence/x86-ufs_inode.md`, `.diff`). 헤더 변경 없음 → 회귀 불필요.

## 216. S5-P194 세부 계획 — `bsd/ufs/ufs_vfsops.c` (D024, superblock byte swap·장치 블록 크기, 코딩 전, 2026-10-03)

사실(원본 [0x143024, 0x143c80), 함수 11 개(codex 검토로 정정, 처음 12 는 오기) 중 기호는 sbupdate 하나; 역어셈블 `ufs_vfsops.dis`):
0. 객체 경계: 0x143024 앞 0x00(링커 채움, 앞은 확정 ufs_subr 끝 0x143021). ufs_vfsops 표(`_ufs_vfsops` 0x1de3c8)의 항목 = mount 0x143024, unmount 0x14379c, root 0x1438cc, statfs 0x143934, sync 0x1439e4, vget 0x143be4, mountroot 0x1430a8 → NeXTMach 순서(ufs_mount, ufs_mountroot, mountfs, ufs_unmount, unmount1, ufs_root, ufs_statfs, ufs_sync, sbupdate, getmdev, ufs_vget)와 함수 시작점(python 으로 ret 뒤 `push ebp` 탐색)이 맞음. 0x143c80(36 B)은 ufs_vnodeops 표 0x80 항목(vn_devblocksize, 기호 없는 정적) → ufs_vnodeops 쪽, 끝은 0x143c80.
1. 진단 13 실패: `nextdev/voldev.h` 없음. 진단 `s5p194-d1`(NeXTMach `ufs/ufs_vfsops.c` + voldev.h import 제거, 07 아님): ufs_mount 132·ufs_mountroot 220·ufs_unmount 20·ufs_root 104·ufs_statfs 176·ufs_sync 20·getmdev 128·ufs_vget 156 원본과 같음; mountfs 1560/1392, unmount1 284/308, sbupdate 364/296. voldev.h 없이도 컴파일됨(vol_notify_cancel 은 암시 선언).
2. unmount1: 진단은 QUOTA 가지(iflush(dev, m_qinod)·closedq·두 번째 iflush)가 들어감 — QUOTA 는 0 으로 정의되어 `#ifdef QUOTA` 가 참. 원본에는 그 호출이 없음(iflush 한 번, 0x1437c7) → `#if QUOTA` 로 고침(재구성 선택). 그 밖은 NeXTMach 와 같음.
3. mountfs(0x143184): VOP_OPEN 성공 뒤 `devbsize = VOP_DEVBLOCKSIZE(*devvpp)`(0x143212); 0 이면 VOP_CLOSE(…, 1, u.u_cred)·binval(*devvpp)·`return (ENOTBLK)`(15). superblock 읽기 `bread(*devvpp, SBLOCK / devbsize, SBSIZE)`(SBLOCK 바이트 8192, **부호 없는** 나눗셈 0x143272 → devbsize 는 unsigned); remount 로 찾은 경우 `bp = mp->m_bufp; fsp = tp->b_un.b_fs; byte_swap_superblock(fsp); goto modify_now`(0x1433d4–0x1433e6); 새 mount 는 found 뒤 `fsp = tp->b_un.b_fs; byte_swap_superblock(fsp);` 다음 magic·크기 검사(NeXTMach 와 같음); modify_now 의 쓰기 가지는 `byte_swap_superblock(fsp); bwrite(tp); … (EROFS 처리) …; byte_swap_superblock(fsp);`(0x143426·0x143468); cs 요약 루프는 bcopy 뒤 `byte_swap_ints(space, size / sizeof (int))`(0x1435d7). 나머지 NeXTMach 와 같음.
4. sbupdate(mp)(0x1439f8): 맨 앞 `devbsize = VOP_DEVBLOCKSIZE(mp->m_devvp)`, `< 0` 이면 반환(0x143a29); `getblk(mp->m_devvp, SBLOCK / devbsize, fs->fs_sbsize)`(부호 있는 나눗셈 → int); bcopy 뒤 `byte_swap_superblock(bp->b_un.b_fs)`; 다섯 필드 0(NeXTMach 와 같은 순서); cs 루프는 bcopy 뒤 `byte_swap_ints(bp->b_un.b_addr, size / sizeof (int))`.
5. byte_swap_superblock·byte_swap_ints 는 선언 없음(외부 0x192c74·0x192c20).

방법: NeXTMach `ufs/ufs_vfsops.c` 를 07 `bsd/ufs/ufs_vfsops.c` 로 들여 voldev.h import 를 빼고(근거 1, 재구성 선택) 2–4 를 D024 표시로 작성. 빌드 `iter.py s5p194-itN bsd/ufs/ufs_vfsops.c ufs_vfsops 143024 143c80`, relcheck, 기록(정적 함수는 이름 없이 순서로 대응).

216 codex 검토 판정(코딩 전; 첫 검토 ky24btyh8 와 범위를 줄인 재검토 둘 다):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0: 함수는 11 개 | NeXTMach 순서 11 이름을 셈(ufs_mount … ufs_vget) | ✅ 사실 0 정정(내 오기) |
| 1 미흡: 진단 결과는 산출물 필요 | `s5p194-d1` fnsizes 출력(이 세션 실행) | ⚖️ 근거 보완 |
| 2 맞음(iflush 한 번, `#if QUOTA`) | 0x1437c6 push 하나 뒤 0x1437c7 call; 07_kernel/generated/quota.h `#define QUOTA 0` | ✅ |
| 3: unsigned 나눗셈이 변수 형을 증명하지는 않음; 0 크기 가지의 VOP_CLOSE 인자는 rdonly 에 따른 플래그·1 | 맞음 — 형은 빌드로 정함; 0x143231–0x14324c 확인 | ⚖️ |
| 재검토: `SBLOCK / devbsize` 는 틀림(NeXTMach SBLOCK 은 1024 단위 8), BBSIZE 를 써야 함 | SDK `07_kernel/nextdev/bsd/ufs/fs.h` NeXT 가지 `#define SBLOCK ((daddr_t)(BBLOCK + BBSIZE))`(바이트, "device blocks 로 변환은 코드 몫" 주석) — 이 트리는 SDK 헤더를 씀 | ❌ 기각(codex 는 NeXTMach 헤더 기준) |
| 4 맞음; 0 크기는 검사 없이 나눗셈 | 0x143a27 `test esi,esi`·`jl` 만 | ✅ (사실 4 와 같음) |
| 5 맞음 | — | ✅ |
| 그 밖의 NeXTMach 와의 차이 없음 | — | ⏭️ |

### 216.1 it 결과
- it1(`s5p194-it1`): 11 함수 중 mountfs 만 1560/1536(형태 같음). 원본 프레임 `sub esp, 0x84` 와 빌드 `0x44` — 지역 슬롯이 모두 0x40 아래로 밀림 → 쓰이지 않는 64 B 지역 변수; 변형 `s5p194-v1`(선언 위치 4 가지 모두 차이 0) 중 h1(맨 앞 `char unused[64];`) 선택 — 이름·위치는 바이트로 정할 수 없음(추정 표시).
- it2(`s5p194-it2`): sbupdate 3 B(장치 블록 크기 레지스터 esi/ebx). `s5p194-v2` 선언 위치·register 5 가지 효과 없음; `s5p194-v3` m1(블록 크기를 `size` 변수에 담음 — 원본 루프의 size 도 esi) 차이 0.
- it3(`s5p194-it3`): 11 함수 모두 일치, OBJECT_MATCH, relcheck 0.

216 결과: 등급 A(`06_reconstruction/evidence/x86-ufs_vfsops.md`, `.diff`). 헤더 변경 없음 → 회귀 불필요.

## 217. S5-P195 세부 계획 — `bsd/ufs/ufs_vnodeops.c` (D024, 장치 블록 크기·POSIX·디렉터리 byte swap, 코딩 전, 2026-10-03)

사실(원본 [0x143c80, 0x145e44), 함수 36 개 중 기호는 rdwri·ufs_nlinks 둘; 역어셈블 `ufs_vnodeops.dis`, `rwip.dis`):
0. 객체 경계: 시작은 plan 216 사실 0(0x143c80 은 표 항목 0x80 의 정적 함수), 끝 0x145e44 는 확정 ipc_entry 시작. `_ufs_vnodeops` 표(0x1de480) 항목 0–31 은 NeXTMach 표 순서와 같고(ufs_open 0x143ca4 … ufs_nlinks 0x145e2c), 항목 32(vn_devblocksize) = 0x143c80, 33·34(vn_prepagein·vn_apageout) = 0 — SDK `struct vnodeops` 의 `#if NeXT` 세 항목. 함수 시작점(python)은 0x143c80 + NeXTMach 정의 순서 35 개.
1. 진단 13 실패: ufs/quota.h 없음. 진단 `s5p195-d1`(NeXTMach `ufs/ufs_vnodeops.c` + `#undef QUOTA`·임시 DEV_BSIZE 512·getattr 의 dbtob 2 인자, 07 아님): 35 개 중 27 개 크기 일치(chown1 은 QUOTA 를 끄면 일치 — `#ifdef QUOTA` 4 곳은 `#if QUOTA` 로). 다른 것: getattr 344/336, setattr 652/536, link 344/304, lockctl 24/160, strategy 604/588, pageout 624/620, rwip 1092/960, 0x143c80 없음.
2. 0x143c80(이름 없음, `ufs_devblocksize` 로 씀): `return (VOP_DEVBLOCKSIZE(((struct mount *)vp->v_vfsp->vfs_data)->m_devvp));`(vnode+0x24 → vfs+0x128 → mount+8). 표에 ufs_nlinks 뒤 추가.
3. ufs_getattr: `va_blocks = btosb(dbtob(ip->i_blocks, VOP_DEVBLOCKSIZE(vp)))`(0x14437f imul, shr 9); IFBLK 의 va_blocksize = `VOP_DEVBLOCKSIZE(vp)`(0x1443a6, BLKDEV_IOSIZE 대신), IFCHR 는 MAXBSIZE 그대로.
4. ufs_setattr: 맨 앞 `px = get_posix_proc(u.u_procp->p_pid)`(0x1443f9); atime·mtime 의 OWNER 실패 때 `px->p_posix_utime`(+0x18 비트 0) 이 0 이면 out, 아니면 `iaccess(ip, IWRITE)` 오류면 out, 성공이면 `u.u_error = 0` 하고 계속(0x144592–0x1445bc, 0x1445fa–0x14461c); chtime 의 ctime 은 `getthetime(&tv); ip->i_ctime = tv.tv_sec`(0x144633).
5. ufs_link: suser 검사 앞 `if (u.u_procp->p_posix && (sip->i_mode & IFMT) == IFDIR) return (EPERM);`(0x144c09–0x144c29).
6. ufs_lockctl: `return (lf_lockctl(vp, ld, cmd));`(0x14559b; NeXTMach 의 `#if` 두 정의 대신).
7. ufs_strategy: if 앞에서 `VOP_DEVBLOCKSIZE(bp->b_vp)` 를 한 번 구하고 두 rdwri 의 오프셋을 `(off_t) bp->b_blkno * 그 값`(imul) 으로.
8. ufs_pageout: 루프 끝 `ip->i_flag |= (IUPD|ICHG);` 뒤 `ip->i_mode &= ~(ISUID|ISGID);`(무조건, 0x145da9).
9. rwip: 맨 앞 `resid = uio->uio_resid`(0x143e41); bmap 뒤 `if (u.u_error == ENOSPC && rw == UIO_WRITE && resid - uio->uio_resid > 0 && u.u_procp->p_posix) { u.u_error = 0; break; }`(0x143fa7–0x143fcb → 0x143ef4 → 루프 뒤 0x14423a); 디렉터리면 uiomove 앞 `byte_swap_dir_block_in(bp->b_un.b_addr, bp->b_bcount)`(0x144138), 뒤 `byte_swap_dir_block_out(bp)`(0x144173). 나머지 NeXTMach 와 같음.
10. byte_swap_dir_block_in/out·lf_lockctl·get_posix_proc 은 선언 여부를 빌드로 확인.

방법: NeXTMach `ufs/ufs_vnodeops.c` 를 07 `bsd/ufs/ufs_vnodeops.c` 로 들여 quota.h 를 `#if QUOTA` 안에 두고(나머지 QUOTA 가지도 `#if`), DEV_BSIZE 를 쓰던 자리를 7 로 바꾸고, 2–9 를 D024 표시로 작성(POSIX 부분은 `#if POSIX_KERN`). 빌드 `iter.py s5p195-itN bsd/ufs/ufs_vnodeops.c ufs_vnodeops 143c80 145e44`, `ordsizes.py`, relcheck, POSIX 없는 진단, 기록.

217 codex 검토 판정(코딩 전; 첫 검토 k29op8nzy 와 범위를 줄인 재검토 둘 다):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 2 맞음(재검토: 표 위치는 역어셈블로 확인 안 됨) | python 으로 `__data` 의 `_ufs_vnodeops` 0x1de480 를 읽음: 항목 32 = 0x143c80, 33·34 = 0 | ✅ |
| 3–8 맞음(주소 제시) | 3·4·5·6·8 은 이 세션에서 해당 역어셈블을 직접 읽음; 7 은 s5p195-d1 rdiff(imul 두 곳) | ✅ |
| 9 맞음; 재검토: "나머지 같음" 은 검사 범위보다 넓음 | 맞음 — 빌드로 확인 | ⚖️ |
| 그 밖의 의미 차이 없음 | — | ⏭️ |

### 217.1 it 결과
- it1(`s5p195-it1`): 첫 빌드에서 36 함수 모두 일치(OBJECT_MATCH), relcheck 0; POSIX 없는 진단 `s5p195-noposix` 종료 0.
- 기록 도구가 공통 기호 `_ufsBufferRead` 를 원본 정의에서 찾지 못해 멈춤 → symbols.tsv 에 ufsDirectRead·ufsBufferRead 가 없음(원본에 없는 변수, NeXTMach 에서만 선언·미사용) → 07 에서 선언 제거. it2(`s5p195-it2`) 같은 결과(OBJECT_MATCH, relcheck 0); 선언 제거만이라 POSIX 없는 진단은 it1 결과를 그대로 씀.

217 결과: 등급 A(`06_reconstruction/evidence/x86-ufs_vnodeops.md`, `.diff`). 헤더 변경 없음 → 회귀 불필요.

## 218. S5-P196 세부 계획 — `bsd/ufs/ufs_dir.c` (D024, 디렉터리 블록 byte swap, 코딩 전, 2026-10-03)

사실(원본 [0x13de14, 0x13f90c), 함수 17 개 중 기호는 brelse_and_swap·dirlook·direnter·diraddentry·dirremove·blkatoff 6 개; 역어셈블 `ufs_dir.dis`):
0. 객체 경계: 앞은 확정 ufs_bmap 끝 0x13de14, 뒤는 확정 ufs_dsort 시작 0x13f90c; 구간 안에 0x00 채움 경계 없음(python). 함수 시작점(ret 뒤 push ebp, python) = brelse_and_swap(신규, 32 B) + NeXTMach 정의 순서 16 개(dirlook … dircheckpath).
1. 진단 13 실패: ufs/quota.h 없음. 진단 `s5p196-d1`(NeXTMach `ufs/ufs_dir.c` + `#undef QUOTA`, 07 아님): dirprepareentry·dirmakeinode·dirmakedirect·dirmangled·dirbad·dirbadname·dirempty 크기 일치(dirmakeinode 는 QUOTA 를 꺼야 일치 — `#ifdef QUOTA` 3 곳을 `#if QUOTA` 로). 다른 것: dirlook 872/832, direnter 1068/1052, dircheckforname 624/592, dirrename 448/424, dirfixdotdot 600/592, diraddentry 220/204, dirremove 688/672, blkatoff 216/208, dircheckpath(끝까지) 672/631.
2. brelse_and_swap(bp)(0x13de14, 전역): `if (bp) { byte_swap_dir_block_out(bp); brelse(bp); }`. 호출은 없고 모두 인라인(앞에 정의된 전역).
3. blkatoff: B_ERROR 검사 뒤 `byte_swap_dir_block_in(bp->b_un.b_addr, bp->b_bcount)`(0x13f504). dircheckpath 는 blkatoff 를 인라인(같은 swap 포함).
4. 함수별 호출 열(python 추출)로 보면 디렉터리 버퍼의 brelse 는 모두 swap_out + brelse(= brelse_and_swap): dirlook 3 곳(NeXTMach :150·:207·:250), direnter 1(:471), dircheckforname 3(:523·:595·:611), dirfixdotdot 1(:833), dirremove 1(:1340), dircheckpath 2(:1559·:1578); blkatoff 의 B_ERROR brelse(:1376)는 swap 없음.
5. 디렉터리 버퍼의 bwrite 앞에는 `byte_swap_dir_block_out(bp)`: dirrename(:696), dirfixdotdot(:792), diraddentry(:891; :908 은 `bad:` 아래 도달 불가 코드), dirmakedirect(:1170), dirremove(:1295).
6. byte_swap_dir_block_in/out 은 선언 없음(외부 0x193308·0x1932bc).

방법: NeXTMach `ufs/ufs_dir.c` 를 07 `bsd/ufs/ufs_dir.c` 로 들여 quota.h·QUOTA 가지를 `#if QUOTA` 로, brelse_and_swap 을 파일 앞(첫 함수)에 두고 2–5 를 D024 표시로 작성. 빌드 `iter.py s5p196-itN bsd/ufs/ufs_dir.c ufs_dir 13de14 13f90c`, `ordsizes.py`, relcheck, 기록.

218 codex 검토 판정(코딩 전; 첫 검토 khlrinb1b 와 범위를 줄인 재검토 둘 다):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 2·3 맞음(0x13de20·0x13de26, 0x13f504, dircheckpath 인라인 0x13f7a3) | `ufs_dir.dis` 직접 읽음 | ✅ |
| 4 미흡: dircheckpath 의 B_ERROR 해제 0x13f78c 도 swap 없음 | python: swap 없는 brelse 는 0x13f4f1(blkatoff)·0x13f78c(dircheckpath 안 인라인 blkatoff) 둘뿐 — 사실 3(인라인)과 같은 것 | ✅ 사실 4 보완 |
| 5 맞음(0x13e961·0x13eb05·0x13ece9·0x13f17c·0x13f359), :908 대응 쓰기 없음 | python: swap_out 17 회, 다음 호출은 모두 brelse 또는 bwrite | ✅ |
| 그 밖의 누락 없음 | — | ⏭️ |

### 218.1 it 결과 — 보류(미기록)
- it1(`s5p196-it1`): 17 함수 중 14 개 크기 일치; dircheckforname 632/624, dirrename 436/448, dircheckpath 663/671(끝 ret 0x13f90a 까지).
- dirrename: 대상이 디렉터리이고 원본이 디렉터리가 아니면 `EISDIR`(0x13e8ee `mov eax, 0x15`; NeXTMach 는 ENOTDIR) → 변형 측정 `s5p196-v10` 차이 0.
- dircheckforname: 바깥 NULL 검사 제거(`s5p196-v1`)·register 조합(`v3`·`v4`) 효과 없음; `s5p196-v5` w2(이 함수 안에서는 brelse_and_swap 대신 `{ byte_swap_dir_block_out(bp); brelse(bp); }` 직접 코드 + `int slotfreespace = 0;`) 차이 0 — 원본은 인라인 함수 경계 없이 bp 를 메모리에서 읽음.
- dircheckpath: 직접 코드(x1, `v6`)로 `bp = NULL` 과 스택 정리 순서는 맞음; 남은 차이는 인라인된 blkatoff 의 bp 하나(원본은 eax 에 두고 swap_in 호출 동안 [ebp-0xc] 에 보관, 빌드는 ebx) 와 그에 따른 프레임 0x10/0xc. blkatoff 선언 순서(`v7`), dircheckpath 선언·조건식(`v8`), blkatoff 본문 표기(`v9`) 모두 효과 없음.
- 상태: dircheckpath 하나 미해결이라 OBJECT_MATCH 아님 → 기록하지 않음. 작업본은 scratchpad `ufs_dir_wip.c`(w2·x1·EISDIR 반영)에 보관하고 07 에서는 뺌(출처 행 없는 파일을 남기지 않음). 나중에 다시 시도.

## 219. S5-P197 세부 계획 — `uxkern/ux_exception.c` (D024 전면 작성, Mach 3 호환 포트 API, 코딩 전, 2026-10-03)

사실(원본 [0x171cb4, 0x172038), 함수 4 개 중 기호는 ux_handler_init·catch_exception_raise; 역어셈블 `ux_exception.dis`):
0. 경계: 0x171cb4 앞 0x00(링커 채움), 0x172038 은 확정 vm_fault 시작. 함수 시작점(python): 0x171cb4(380 B, 기호 없음 = ux_handler), 0x171e30 ux_handler_init(128), 0x171eb0 catch_exception_raise(188), 0x171f6c(204, 기호 없음 = ux_exception, 정적).
1. 진단 13 실패: machine/exception.h → mach/machine/exception.h, sys/message.h → mach_ipc_xxxhack.h 없음. NeXTMach 원문은 Mach 2.5 IPC(kern_obj_t, kern/ipc_pobj.h, ipc_copyin.h) 기준이라 그대로는 못 씀 → 원본 바이트로 전면 작성(D024). 이름 매핑 `port_allocate → port_allocate_EXTERNAL` 등은 NeXTMach `kern/mach_user_internal.h`(:41·:42·:45·:47)와 같음 — 이 헤더를 07 로 들여 씀(출처 행 추가). Darwin 0.1 은 구조(함수 4 개·정적 lock·정적 self 포트)만 대조, 원문 미사용.
2. 데이터: 정적 `ux_handler_init_lock`(`__bss` 0x1e7280, simple_lock 인라인 xchg), 정적 `ux_handler_self`(`__bss` 0x1e7284), 전역 `ux_exception_port`(common 0x1e9070). NeXTMach 의 ux_handler_task 없음.
3. ux_handler()(정적): `current_task()->kernel_vm_space = TRUE`(task+0x50); `ux_handler_self = task_self()`; simple_lock; port_set_allocate(self, &set)·port_allocate(self, &local)·port_set_add(self, set, local) 각각 실패 때 panic(문자열 0x1e082c·0x1e0851·0x1e0872); `object_copyin(current_task(), local, MSG_TYPE_PORT, FALSE, &ux_exception_port)` 실패 때 panic(0x1e0892); thread_wakeup(&ux_exception_port); simple_unlock; `task_name("ux_except")`; 루프: exc_msg(msg_header_t + int[16], 0x58 B) 의 msg_local_port = set, msg_size = sizeof; msg_receive(&h, 0, 0) == RCV_SUCCESS 이면 `rep_port = exc_msg.h.msg_remote_port`(받은 요청의 것), exc_server(&exc, &rep) 참이면 msg_send(&rep.h, 0, 0), rep_port 가 0 아니면 port_deallocate(self, rep_port); 그 밖에 `r != RCV_TOO_LARGE`(-204, SDK mach/message.h:675) 이면 panic("exception_handler") — 너무 큰 메시지는 무시하고 계속(NeXTMach 의 kalloc 큰 버퍼 경로 없음).
4. ux_handler_init(): lock 초기화(0)·ux_exception_port = 0; `kernel_thread(kernel_task_create(kernel_task, 0), ux_handler, 0)`; simple_lock; ux_exception_port 가 0 이면 `thread_sleep(&ux_exception_port, &lock, FALSE)`(반환), 아니면 simple_unlock.
5. catch_exception_raise(exception_port, thread_port, task_port, exception, code, subcode): signal = 0, ret = KERN_SUCCESS; `object_copyin(current_task(), thread_port, MSG_TYPE_PORT, FALSE, &kport)` 실패면 ret = KERN_INVALID_ARGUMENT; 성공이면 thread = convert_port_to_thread(kport), port_release(kport), thread 가 NULL 이면 ret = 4, 아니면 ux_exception(exception, code, subcode, &signal, &thread->_uthread->uu_code), signal 이면 thread_psignal, thread_deallocate. 끝에 port_deallocate(ux_handler_self, task_port), port_deallocate(ux_handler_self, thread_port), return ret. task 변환·task_deallocate 없음.
6. ux_exception(정적): NeXTMach 와 같은 switch(machine_exception 먼저; BAD_ACCESS 는 code == KERN_INVALID_ADDRESS 면 SIGSEGV 아니면 SIGBUS 등).

방법: 07 `uxkern/ux_exception.c` 를 새로 작성(D024, NeXTMach 의 머리 주석·저작권 고지 유지, 함수 본문은 원본 바이트 기준), NeXTMach `kern/mach_user_internal.h` 를 07 로 채택. 빌드 `iter.py s5p197-itN uxkern/ux_exception.c ux_exception 171cb4 172038`, relcheck, zerofill(정적 두 개), 기록.

219 codex 검토 판정(코딩 전; 첫 검토 ky3c7uz3p 와 범위를 줄인 재검토 둘 다):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0·2 미흡: 이름 없는 두 함수의 이름·static, 정적 변수 이름, ux_handler_task 부재는 추정 | 맞음 — 이름은 재구성 선택(기호 없음), static 은 기호 부재가 근거 | ⚖️ |
| 3 맞음(task+0x50, msg 0x4/0xc/0x10, 0x58 버퍼, -204); 선언 꼴은 추정 | message.h:493–501 msg_header_t(0x18 B), task.h:109 kernel_vm_space(오프셋은 빌드로 확인) | ✅/⚖️ |
| 4·5 맞음(0x171e30–0x171eaf, 0x171eb9–0x171f69, thread+0x84·uthread+0x74, 실패 4) | `ux_exception.dis` 직접 읽음; uu_code 오프셋은 앞서 계산한 uthread 배치와 같음 | ✅ |
| 6 맞음(jump table 해석: code 1 이면 SIGSEGV) | 0x171fc0 이후 바이트(`83 fe 01 75 0b`, 0x171fc5 SIGBUS 10) 직접 읽음 | ✅ |

### 219.1 it 결과
- it1(`s5p197-it1`): ux_handler_init·ux_exception 크기 일치; ux_handler 392/380 — 명령은 같고 두 포트 변수 슬롯이 [ebp-0x84]·[ebp-0x88](원본 [ebp-4]·[ebp-8]) → `s5p197-v1` m1(메시지 버퍼를 for 블록 안에서 선언 — 포트 변수가 먼저 스택에 놓임) 차이 0. catch_exception_raise 192/188 → `v2`(if/else·선언 순서), `v3`(task 지역 변수 + ret 먼저, d2), `v4` e1(thread NULL 처리를 else 쪽에) 차이 0.
- it2(`s5p197-it2`): ux_handler_init 의 kernel_thread 인자 순서(원본은 kernel_task_create 를 먼저 호출) → `s5p197-v5` f1(별도 문장의 지역 변수) 차이 0.
- it3(`s5p197-it3`): 4 함수 모두 일치, relcheck 0; `__bss` 8 B(정적 lock·self) zerofill reference-inferred [0x1e7280, 0x1e7288)(참조 15, Delta 0x1e6e44), 알려진 배치 28 건(`zerofill-known-s5p197-20261002.json`).
- `kern/mach_user_internal.h` 는 NeXTMach 원문 그대로 07 `src/kern/` 에 채택(바이트 동일 확인 `cmp`), PROVENANCE·MODIFICATIONS 행 직접 추가.

219 결과: 등급 P(`06_reconstruction/evidence/x86-ux_exception.md`, `.diff`). 다른 객체가 쓰지 않는 새 헤더 하나 추가 → 회귀 불필요(기존 객체는 이 헤더를 import 하지 않음).

## 220. S5-P198 세부 계획 — `bsd/kern/subr_prf.c` (D024, stdarg·vlog·_printf, 코딩 전, 2026-10-03)

사실(원본 [0x10c0d8, 0x10cca4), 함수 18 개 중 기호 14 개; 역어셈블 `prf.dis`(0x10c290–0x10c328)·`prf2.dis`(jump table 0x10c328–0x10c478 뒤), 그 밖은 `odis.py`):
0. 경계: 0x10c0d8 앞 0x00(앞은 확정 subr_log 끝 0x10c0d7), 뒤는 확정 subr_xxx 시작 0x10cca4. 함수 순서 = printf, uprintf, tprintf, sprintf, log, vlog, logpri(정적 0x10c248), _printf, prf, puts(정적 0x10c974), printn(정적 0x10c9a8), panic_init, panic, tablefull, harderr, putchar, logchar, tputchar(정적 0x10cbac). NeXTMach 순서와 다른 점: sprintf 가 tprintf 뒤(NeXTMach 는 파일 끝), vlog 가 log 뒤, _printf 가 logpri 뒤(둘 다 신규).
1. 진단 13 실패: mach_ldebug.h·next/printf.h·mon/global.h 없음. `s5p198-d1`(셋 제거, 07 아님)은 SDK `sys/printf.h`(stdarg 원형 `prf(const char *, va_list, int, struct tty *)`)와 충돌, `struct reg_desc` 없음 → 4.2 는 stdarg 판이고 reg_desc/TOCONS 는 SDK `kernserv/printf.h`(reg_values·reg_desc·TOCONS…TOSTR·같은 원형)에 있음.
2. printf/uprintf/tprintf/log/sprintf: NeXTMach 와 같은 흐름에 인자 목록만 va_list(`lea [ebp+0xc]` 등). uprintf 는 tp 가 NULL 이면 값 없이 반환(0x10c111). log 는 logwakeup() 뒤에 `splx(s)` 를 한 번 더 부름(0x10c20c).
3. vlog(level, fmt, ap)(0x10c220): `if (prf(fmt, ap, TOCONS | TOLOG, (struct tty *)0)) logwakeup(); return 0;`(level 미사용).
4. _printf(flags, ttyp, fmt, ...)(0x10c274): `return prf(fmt, ap, flags, ttyp);`(ap 는 fmt 다음).
5. prf: NeXTMach 와 같은 switch(%l·x/X·d/D/u·o/O·c·b·s·%·C·r/R·n/N·L; jump table 0x10c328, 'c'-0x25 색인 0..0x53)를 `va_arg(ap, …)` 로(값 읽기 `add [ebp+0xc], 4; mov [..-4]`). L 은 `log_wakeup = 0`(0x10c958). %r 의 rd_format 출력은 재귀 prf 대신 `_printf(flags, ttyp, rd->rd_format, field)`(0x10c824 call `__printf`, push edi(field)·rd_format·ttyp·flags) — 원본 prf 안에 자기 호출 없음(grep).
6. panic(s)(0x10ca6c): bootopt = RB_AUTOBOOT(0); panic_lock 아래 panicstr 이 있으면 `cpu_number() == paniccpu`(0 과 비교) 면 RB_NOSYNC(4), 아니면 unlock·halt_cpu; 없으면 panicstr = s, paniccpu = cpu_number()(0); unlock; printf("panic: (Cpu %d) %s\n", paniccpu, s); printf("panic: %s\n", version); mini_mon("panic", "System Panic", boothowto); `boot(RB_PANIC, bootopt, "")`(0x10cb16, 셋째 인자 빈 문자열 0x1dac66). mon_global·ROM 버전 printf·mach_ldebug 없음.
7. tablefull/harderr/putchar/logchar/puts/printn/tputchar/panic_init 는 NeXTMach 와 같은 것으로 보임(빌드로 확인). 문자열 순서(0x1dac18…) "0x"·"???"·"???"·"0123456789abcdef"·panic 문자열들 — NeXTMach 리터럴 순서와 같음.

방법: NeXTMach `bsd/subr_prf.c` 를 07 로 들여 mach_ldebug.h·next/printf.h·mon/global.h 대신 `kernserv/printf.h`, stdarg 로 바꾸고, 2–6 을 D024 표시로 작성(함수 순서 1 대로 이동). 빌드 `iter.py s5p198-itN bsd/kern/subr_prf.c subr_prf 10c0d8 10cca4`, ordsizes, relcheck, 기록.

220 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 맞음(0x10c0d6 ret 뒤 0x00, 순서) | 0x10c0d8 앞 바이트 `ec5dc300`(python), 함수 순서는 symbols + 정적 호출 대상 | ✅ |
| 2·3·4·6 맞음(0x10c111, 0x10c20c, 0x10c220, 0x10c274, 0x10ca9c, 0x10cb0e–0x10cb16) | 이 세션에서 `odis.py 10c0d8 10c290`·`10ca58 10cca4` 직접 읽음; 빈 문자열 0x1dac66 은 python 으로 읽음 | ✅ |
| (내 확인) 5 의 %r 재귀 | prf2.dis 0x10c813–0x10c829 `call __printf` | ✅ 사실 5 확정 |

### 220.1 it 결과
- it1(`s5p198-it1`): 18 함수 중 sprintf 만 48/56 — 원본은 대상 포인터를 지역 변수에 복사해 그 주소를 넘김(0x10c192 `mov [ebp-4], ebx`) → `char *p = s; … (struct tty *)&p; *p++ = 0; return p - s;`. prf(1764 B, jump table 포함)·puts·printn·panic 등은 첫 빌드에서 크기 일치(주소 차이는 python).
- it2(`s5p198-it2`): 18 함수 모두 일치, OBJECT_MATCH, relcheck 0.

220 결과: 등급 A(`06_reconstruction/evidence/x86-subr_prf.md`, `.diff`). 기록 도구가 SDK `sys/printf.h` 의 PROVENANCE 행을 추가(D017; kernserv/printf.h 는 이미 07 nextdev 에 있음). 헤더 변경 없음 → 회귀 불필요.

## 221. S5-P199 세부 계획 — `vm/vm_unix.c` (D024, Mach 3 u 영역·gc_control, 코딩 전, 2026-10-03)

사실(원본 [0x17bd28, 0x17c4e0), 함수 16 개 모두 기호 있음; 역어셈블 `vm_unix.dis`):
0. 경계: 앞은 확정 vm_synchronize 끝 0x17bd28(정렬, 채움 없음), 뒤는 확정 vm_user 시작 0x17c4e0. 함수: useracc, vslock, vsunlock, swapon, procdup, chgprot, unix_pid, task_by_unix_pid, task_by_pid, vm_object_special, device_pagein, device_pageout, device_dealloc, fake_u, gc_init, gc_control. NeXTMach 의 subyte…fuiword 는 이 객체에 없음(`#if defined(sun) || BALANCE` 반대 가지 — 이 판에서는 제외 조건으로 둠).
1. 진단 13 실패: kern/ipc_globals.h 없음. `s5p199-d2`(ipc_globals 제거, vm/vm_param.h → mach/vm_param.h, sys/port.h → mach/port.h, 07 아님): sys/time_value.h 중복, procdup·fake_u 의 `u_address`, task_by_pid 의 kern_obj_t 오류 → 아래 2–7.
2. useracc/vslock/vsunlock/chgprot/unix_pid/swapon/vm_object_special/device_*: NeXTMach 와 같은 흐름(current_task()->map = active_threads->task(+0xc)->map(+0xc); vsunlock 의 vm_page_set_modified 는 `pg->…flag &= ~0x20`(0x17bdec `and byte [eax+0x1e], 0xdf`) — 매크로 전개로 확인 예정).
3. procdup(child, parent)(0x17be44): task_create(parent->task, parent->task != kernel_task, &task)(0x17be58–0x17be6b; NeXTMach 는 TRUE); 실패 printf; child->task = task; `task_deallocate(task)`(0x17be8f, 신규); task->proc = child(+0x3c); thread_create; 실패 printf; `thread_deallocate(thread)`(0x17bebd, 신규); `compute_priority(thread, FALSE)`(인자 2 개); bcopy(parent utask, task utask, sizeof (struct utask) = 0x298); `bzero(&task->u_address->uu_prof, sizeof (struct uuprof))`(+0x248, 0x18, 신규); uu_ofile_cnt = 0; expand_fdlist; ofile·pofile bcopy; `thread->task->u_address->uu_procp = child`; ru·cru bzero; uu_outime = 0; return thread.
4. task_by_unix_pid(0x17c034): NeXTMach 조건 뒤 `if (p->task) task_reference(p->task)`; `*t = p->task`; `if (suser() && current_task()->proc) current_task()->proc->p_debugger = 1`(0x17c087–0x17c09f); unix_master/release 흔적 없음(NCPUS 1 빈 매크로). task_by_pid 에 인라인됨.
5. task_by_pid(0x17c0c0): `object_copyout(self, t, MSG_TYPE_PORT, &t)`(kern_obj_t 캐스트 없음).
6. fake_u(up, thread)(0x17c2c4): utask = thread->task->u_address, uthread = thread->_uthread; `up->u_pcb = *(thread->pcb)` 없음; 나머지 NeXTMach 와 같음(comm 0x11 B, arg 0x20, cred, signal 0x84, code, ttyp, ttyd, ru, 시간, cru).
7. gc_init()(0x17c40c): `simple_lock_init(&gc_lock); gc_active = 0;`. gc_control()(0x17c428, 시스템 호출, uap = u.u_ap): suser() 아니면 반환; simple_lock(&gc_lock); gc_active 가 0 이면 gc_active = 1·unlock, `uap->flags & 1` 이면 mfs_cache_clear·vm_object_cache_clear·inode_cache_clear·rnode_cache_clear·proc_cache_clear, `& 2` 면 zone_gc, `& 4` 면 zone_reclaim, 다시 lock·gc_active = 0; 끝에 simple_unlock. gc_lock·gc_active 는 기호 있는 전역(0x1f7478·0x1f7474).

방법: NeXTMach `vm/vm_unix.c` 를 07 로 들여 헤더 정리(1), 2–7 을 D024 표시로(gc_init/gc_control 은 작성). 빌드 `iter.py s5p199-itN vm/vm_unix.c vm_unix 17bd28 17c4e0`, relcheck, 기록.

221 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 3·4·6·7 맞음(0x17be53–0x17bfbe, 0x17c043–0x17c09f·인라인 0x17c0da–0x17c13b, 0x17c2d0–0x17c408, 0x17c40f–0x17c4d3) | `vm_unix.dis` 직접 읽음 | ✅ |
| 5 미흡: kern_obj_t 캐스트 유무는 바이트로 불명 | 맞음 — 이 트리에 kern_obj_t 형이 없어 캐스트 없이 씀(재구성 선택) | ⚖️ |

### 221.1 it 결과
- it1(`s5p199-it1`): 16 함수 중 procdup 만 384/380. task_create 둘째 인자: 조건식 꼴(`s5p199-v1` k1–k3, setne 생성) 효과 없음; 원본은 `edx = 1` 뒤 kernel_task 이면 0 → `s5p199-v2` l1(`boolean_t inherit = TRUE; if (parent->task == kernel_task) inherit = FALSE;`) 오프셋 200 까지 일치; 남은 차이는 expand_fdlist·두 bcopy 의 크기를 자식(task)의 복사된 uu_lastfile 로 계산(0x17bf0b–) → `s5p199-v3` 차이 0.
- it2(`s5p199-it2`): 16 함수 모두 일치, OBJECT_MATCH, relcheck 0.

221 결과: 등급 A(`06_reconstruction/evidence/x86-vm_unix.md`, `.diff`). 헤더 변경 없음 → 회귀 불필요.

## 222. S5-P202 세부 계획 — `bsd/specfs/spec_vfsops.c` (NeXTMach 원문 그대로, 2026-10-03)

사실:
0. inventory 의 "spec_vnodeops.c" 구간 [0x139b14, 0x13a588) 의 앞 세 함수 — spec_badop(0x139b14, 20 B, 기호 있음), 0x139b28(116 B), 0x139b9c(12 B) — 는 `_spec_vfsops` 표(`__data` 0x1dd6a8, python 으로 읽음: badop×4, 0x139b28, badop, 0x139b9c)의 항목 = NeXTMach `specfs/spec_vfsops.c` 의 spec_badop·spec_sync·spec_mountroot. 0x139b14 앞은 0x00(링커 채움). 0x139ba8 뒤는 ret 바로 뒤(정렬)라 경계를 바이트로 정할 수 없음 → NeXTMach 파일 구성대로 spec_vfsops = [0x139b14, 0x139ba8), 나머지는 spec_vnodeops(재구성 선택).
1. 진단 `s5p202-d1`(NeXTMach 원문, 07 아님) 세 함수 크기 20·116·12 = 원본. spec_sync 의 정적 spec_lock 은 `__bss`(원본 0x1e5a30, 기호 없음).
2. 방법: NeXTMach `specfs/spec_vfsops.c` 를 07 `bsd/specfs/spec_vfsops.c` 로 그대로 들임(편집 없음). 빌드 `s5p202-it1`, relcheck, zerofill(spec_lock), 기록(등급은 `__bss` 판정에 따름).

### 222.1 결과
- `s5p202-it1`: 3 함수 모두 일치(MATCH 2, MATCH_UNVERIFIED 1 — 정적 bss 참조), relcheck 0. 남은 것은 `__bss` 4 B(spec_lock).
- codex 검토: 사실 0·1 맞음(8 번째 워드 0x63657073 은 다음 문자열 "spec" 의 시작 — 표 항목은 7 개, 계획과 같음). zerofill reference-inferred [0x1e5a30, 0x1e5a34)(참조 3, Delta 0x1e5974), 알려진 배치 29 건(`zerofill-known-s5p202-20261002.json`).

222 결과: 등급 P(`06_reconstruction/evidence/x86-spec_vfsops.md`). 편집 없음.

## 223. S5-P201 세부 계획 — `bsd/specfs/spec_vnodeops.c` (D024, set_blocksize·s_size 블록 크기·getthetime, 코딩 전, 2026-10-03)

사실(원본 [0x139ba8, 0x13a588), 함수 19 개(기호 setattr·access·link·fsync·lockctl·fid·realvp 7 개); 역어셈블 `spec_vnodeops.dis`(todis.py — jump table 건너뜀)):
0. 경계: 앞은 plan 222 의 spec_vfsops 끝 0x139ba8(재구성 선택), 뒤 0x13a588 은 기호 logswap(다른 객체, 채움 없음). `_spec_vnodeops` 표(0x1dd6d0, python 으로 읽음) 항목 0–31 은 NeXTMach 표와 같고 32 = 0x13a374(vn_devblocksize), 33·34 = 0.
1. 진단 `s5p201-d1`(NeXTMach 원문 + 임시 DEV_BSIZE, 07 아님)과 함수별 크기(원본/빌드): open 376/356, close 248/248, rdwr 656/648, ioctl 72/72, select 64/64, inactive 128/100, getattr 204/196, setattr 148/124, access·link·fsync·dump·noop·fid·cmp·realvp·strategy 같음, lockctl 12/60, 0x13a374(16 B) 없음.
2. spec_open: VBLK 에서 d_open 이 0 이면 `set_blocksize(sp, dev)`(0x139cf3–0x139cf8; 기호 _set_blocksize 0x1395f0 — spec_subr 쪽).
3. spec_rdwr: `bn = lbn * (bdevsize / DEV_BSIZE)`, `rablock = bn + (bdevsize / DEV_BSIZE)` 의 DEV_BSIZE 가 `sp->s_size`(+0x48, 부호 없는 나눗셈 0x139f39). set_blocksize 가 bdevsw d_psize(장치 블록 크기)를 s_size 에 넣으므로 4.2 에서는 s_size 가 블록 크기 — 필드 이름은 07 snode.h(NeXTMach) 그대로 씀.
4. spec_inactive: 맨 앞 `px = get_posix_proc(u.u_procp->p_pid); px->p_posix_utime = 1;`(0x13a145–0x13a14c), kfree 앞 `px->p_posix_utime = 0`(0x13a196).
5. spec_getattr: realvp 없음 가지에서 `getthetime(&tv)` 뒤 atime/mtime/ctime = tv(`time` 대신); VBLK 의 va_blocksize = `VOP_DEVBLOCKSIZE(vp)`(0x13a254–0x13a260, BLKDEV_IOSIZE 대신), VCHR 는 MAXBSIZE.
6. spec_setattr: chtime 이면 `getthetime(&tv); sp->s_ctime = tv`.
7. 0x13a374(이름 없음, spec_link 뒤): `return (VTOS(vp)->s_size);`(spec_devblocksize 로 씀), 표 항목 32.
8. spec_lockctl(0x13a4c4): `return (EINVAL)`(NeXTMach 의 SUN_LOCK 가지 klm 코드 대신).

방법: NeXTMach `specfs/spec_vnodeops.c` 를 07 로 들여 2–8 을 D024 표시로(POSIX 부분은 POSIX_KERN). 빌드 `iter.py s5p201-itN bsd/specfs/spec_vnodeops.c spec_vnodeops 139ba8 13a588`, tdiff, relcheck, 기록.

223 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 2·4·5·6·8 맞음(0x139cef–0x139cf8, 0x13a139–0x13a14c·0x13a196, 0x13a1c9–0x13a268, 0x13a2e8–0x13a2fe, 0x13a4c4) | `spec_vnodeops.dis` 직접 읽음 | ✅ |
| 3 미흡: set_blocksize 가 +0x48 에 무엇을 넣는지 이 역어셈블로는 불명 | `todis.py 1395f0 139648`: 0x139619 `call [bdevsw+0x10]`(d_psize), 0x139620 `mov [ebx+0x48], eax` | ✅ 사실 3 근거 보완 |
| 7 미흡: 표 항목 32 는 역어셈블로 불명 | python 으로 `__data` 0x1dd6d0 표 읽음: 항목 32 = 0x13a374 | ✅ |

### 223.1 it 결과 — 보류(미기록)
- it1(`s5p201-it1`): struct proc/posix_proc 불완전 → `#import <sys/proc.h>`. it2(`s5p201-it2`): 19 함수 중 18 개 일치(rdwr·inactive·getattr·setattr·devblocksize·lockctl 모두 첫 빌드에서 일치), spec_open 만 200 B 차이 — 명령 수·크기는 같고 레지스터 배정만 다름: 원본은 dev 를 ebx, error 를 eax 에 두고 set_blocksize 호출 동안 [ebp-8] 에 저장(caller-save), 빌드는 error 를 ebx 에 둠.
- 변형: error/flag/dev 의 register·선언 위치(`s5p201-v1`·`v2`·`v3`), 조건식 꼴(`v4` r1·r2, `v5` r4–r6), 초기화(`v6`) 효과 없음; `v4` r3(성공 때 그 자리에서 s_count++ 후 반환)은 9 B 차이까지 — 원본은 저장한 error 를 되읽어 공통 검사로 감.
- 상태: spec_open 하나 미해결이라 OBJECT_MATCH 아님 → 기록하지 않음. 작업본 scratchpad `spec_vnodeops_wip.c`(2–8 + sys/proc.h 반영)에 보관, 07 에서는 뺌. 이 객체의 set_blocksize 는 spec_subr(0x1395f0) 쪽.

## 224. S5-P203 세부 계획 — `bsd/specfs/spec_subr.c` (D024, set_blocksize, 코딩 전, 2026-10-03)

사실(원본 [0x1395d8, 0x139b14), 앞은 확정 fifo_vnodeops 끝, 뒤는 spec_vfsops(plan 222); 기호 bdevvp·set_blocksize·specvp·makespecvp·sunsave·stillopen·isclosing·other_specvp·slookup·smark, 정적 ssave(0x139860)·sfind(0x139a30); 역어셈블 `todis.py`):
0. 진단 13 은 spec_vnodeops 보류 메모의 "0x1395f0 호출 대상" 때문이었음 — 이제 기호 `_set_blocksize`(0x1395f0) 가 이 객체의 함수. 진단 `s5p203-d1`(NeXTMach 원문) 은 `dbtob(rsize)` 인자 1 개로 실패.
1. bdevvp(0x1395d8): NeXTMach 와 같음(specvp(NULL, dev, VBLK)).
2. set_blocksize(sp, dev)(0x1395f0, 신규 전역, bdevvp 와 specvp 사이): `major(dev) < nblkdev && (size = bdevsw[major(dev)].d_psize)` 이면 rsize = (*size)(dev); rsize 가 -1 이 아니면 `sp->s_size = rsize`(dbtob 없음 — 블록 크기), `sp->s_bdevvp` 가 있고 그 snode 의 s_size 가 0 이면 그것도 rsize, 반환; 그 밖에는 `sp->s_size = 0`(0x139638).
3. specvp(0x139648): bdevvp·set_blocksize 가 인라인됨(앞에 정의된 전역). NeXTMach 의 "real block device" 가지에서 d_psize·dbtob 크기 계산이 빠지고(v_type·v_vfsp·s_bdevvp 만), `if (sfind == NULL) { … ssave(sp); }` 뒤 항상 `set_blocksize(sp, dev)`(0x139759–0x1397a3) 후 return STOV(sp).
4. 나머지 함수는 빌드로 비교.

방법: NeXTMach `specfs/spec_subr.c` 를 07 로 들여 2·3 을 D024 표시로. 빌드 `iter.py s5p203-itN bsd/specfs/spec_subr.c spec_subr 1395d8 139b14`, relcheck, 기록.

224 codex 검토 판정(코딩 전): 사실 1·2·3 맞음(0x1395e4, 0x139620·0x139633·0x139638, 0x139723·0x13973c–0x13974d·0x139759–0x1397a3) — 내가 `todis.py 1395d8 1397b0` 로 직접 읽은 내용과 같음 ✅.

### 224.1 결과
- `s5p203-it1`: 첫 빌드에서 12 함수 모두 일치, OBJECT_MATCH, relcheck 0. 224 결과: 등급 A(`06_reconstruction/evidence/x86-spec_subr.md`, `.diff`). 이전 보류 사유(0x1395f0 이름 없는 호출 대상)는 기호 `_set_blocksize` 로 해소.

## 225. S5-P204 세부 계획 — `bsd/netinet/ip_input.c` (D024, MULTICAST·bootp.h·icmp_error 5 인자, 코딩 전, 2026-10-03)

사실(원본 [0x125f54, 0x127280), 앞은 확정 ip_icmp 끝, 0x127280 은 0x00 채움 뒤 ip_output; 함수 14 개 모두 기호; 역어셈블 `ipintr.dis`·`ipdo.dis`(todis.py)):
0. 진단 13 실패: mon/bootp.h 없음(SDK 는 `netinet/bootp.h`, IPPORT_BOOTPC). 진단 `s5p204-d2`(NeXTMach 원문 + IPPORT_BOOTPC 68 임시 정의, 07 아님): ip_reass·ip_freef·ip_enq·ip_deq·ip_slowtimo·ip_drain·ip_rtaddr·save_rte·ip_srcroute·ip_stripoptions 크기 일치; ip_init 260/252, ipintr 1244/1048, ip_dooptions 816/812, ip_forward 1008/1006(끝 0x00 2 B 포함).
1. ip_init: `ip_id = time.tv_sec & 0xffff` → `getthetime(&tv); ip_id = tv.tv_sec`(지역 timeval, 하위 16 비트 저장).
2. ip_dooptions: 끝의 `icmp_error(ip, type, code, ifp)` 에 5 번째 인자 `(struct in_addr *)0`(0x126c76 `push 0`; plan 169·170 과 같은 꼴).
3. ipintr: (가) `struct ifnet *ifp` 를 0 으로 초기화(0x126061); (나) BOOTP 비교가 `ui->ui_dport == htons(IPPORT_BOOTPC)`(0x12630b `mov eax, 0x44; ror ax, 8` — 상수 접기 안 된 htons); (다) 주소 목록 검사 뒤, INADDR_BROADCAST/ANY 검사 앞에 Deering 멀티캐스트 처리(0x12636d–0x126404): `if (IN_MULTICAST(ntohl(ip->ip_dst.s_addr))) { if (ip_mrouter) { ip->ip_id = htons(ip->ip_id); if (ip_mforward(ip, ifp) != 0) { m_freem(dtom(ip)); goto next; } ip->ip_id = ntohs(ip->ip_id); if (ip->ip_p == IPPROTO_IGMP) goto ours; } IN_LOOKUP_MULTI(ip->ip_dst, ifp, inm); if (inm == NULL) { m_freem(dtom(ip)); goto next; } goto ours; }` — IN_LOOKUP_MULTI·IFP_TO_IA 는 SDK netinet/in_var.h:81·121.
4. ip_forward 크기 차이 2 B 는 끝 채움(0x12727e–0x127280).

방법: NeXTMach `netinet/ip_input.c` 를 07 로 들여 mon/bootp.h → netinet/bootp.h, 1–3 을 D024 표시로(멀티캐스트는 `#if MULTICAST`). 빌드 `iter.py s5p204-itN bsd/netinet/ip_input.c ip_input 125f54 127280`, relcheck, 기록.

225 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1 맞음(0x12602d–0x12603a getthetime) | tdiff(s5p204-d2) 의 `lea; push; call; mov di, [ebp-N]` 와 같음 | ✅ |
| 2 틀림: icmp_error 는 struct in_addr 를 값으로 받음(NeXTMach ip_icmp.c:51–56) | 07 `bsd/netinet/ip_icmp.c:55` `struct in_addr *dest; /* plan 170 (authored): a pointer in the original (0x125665) */` — 확정 객체의 원본 기준 형식은 포인터, udp_usrreq.c:234 도 `(struct in_addr *)0` | ❌ 기각(codex 는 NeXTMach 판 기준) |
| 3 맞음; inm 지역 변수 필요 | 맞음 | ✅ |

### 225.1 it 결과 — 텍스트 일치, `__bss` 는 D025 로 참조 추론, 등급 P (기록 완료)
- it1(`s5p204-it1`): ipintr·ip_init·ip_dooptions 일치; ip_forward 21 B — 원본은 icmp_error 의 dest 를 `&dest` 로 넘김(0x127261 `lea eax, [ebp-4]`) → 수정. it2(`s5p204-it2`): 14 함수 텍스트 모두 일치(MATCH 12, MATCH_UNVERIFIED 2 = 정적 `__bss` 참조하는 save_rte·ip_srcroute), relcheck 0.
- zerofill(`s5p204-zerofill-check-ip_input-20261002.json`): 참조 8 개 모두 Delta 0x1e4548 하나, 후보 [0x1e5908, 0x1e59ac)(164 B, 정적 ip_srcrt), 정렬·zero-fill 구간·기호 없음·겹침 없음 통과, 음성 검사 통과 — 그러나 `field_targets_in_range` 가 거짓: 0x126dc9 의 scattered 재배치(`lea ebx, [eax + 0x1e5904]`, ip_srcroute 의 배열 첨자 `… - 1` 계산)가 필드 값으로 구간 시작 −4 를 가짐 → 도구 결론 `fail`.
- 판단: 이 필드는 scattered 재배치의 덧셈 상수(r_value = 구간 시작, 필드 = 시작 − 4)이고 Delta 는 다른 7 개와 같음. 도구 규칙(plan 84·D019 계열: 비 pcrel 필드의 목표는 구간 안)을 scattered 기록에 대해서는 r_value 기준으로 보도록 고칠지는 **사용자 결정 사항** — 결정 전에는 기록하지 않음. 작업본 scratchpad `ip_input_wip.c`, 07 에서는 뺌.


- D025(2026-10-03 사용자 결정): scattered 재배치는 r_value 로 범위를 검사한다. `zerofill_check.py` 수정 후 기존 zerofill JSON 30건 재실행: 28건 불변, ip_input 은 의도대로 reference-inferred, s5p36-kalloc-pre 는 D019 이전 산출물이라 달라졌고 기록된 s5p58 kalloc 결과에는 영향 없음.
- 재판정 `09_validation/reconstruction/s5p204-zerofill-check-ip_input-20261002.json`: 참조 8건, Delta 0x1e4548 하나, 후보 [0x1e5908, 0x1e59ac) (static ip_srcrt 164 B), scattered addend -4·1·4, 음성 검사 검출. 알려진 배치 `zerofill-known-s5p204-20261002.json`(30건).
- 기록 중 공통 심볼 검사 정정: `_etherbroadcastaddr` 공통 크기 8(선언 [6]) 이 원본 다음 심볼 간격 6 을 넘어 기록 도구가 멈췄다. 원본에서 이 심볼은 if_ether 의 초기화 정의(__data)라 공통이 공간을 차지하지 않는다. 크기 검사는 원본 __common 심볼에만 적용하도록 도구를 고쳤다.
- 기록: objects_partial +1, functions +14, PROVENANCE +2(ip_input.c, SDK netinet/bootp.h 채택). 등급 **P**.

## 226. S5-P206 세부 계획 — `rpc/bootparam_xdr.c`·`rpc/mountxdr.c`·`net/if_loop.c` (D024, 코딩 전, 2026-10-03)

ip_output(175 절)은 이번에도 보류 유지(체크섬 2 바이트 저장 꼴 하나; 30 가지 변형 실패 기록 그대로). 07 의 `bsd/netinet/ip_output.c` 는 PROVENANCE 행 없는 유일한 07 소스(전수 검사: `.gitkeep` 4 개 외 이것 하나) — 175 절 결정대로 두고, 이번 회차에서 새로 만드는 작업본은 기록 전까지 scratchpad 에 둔다.

사실(진단 `s5p206-d1`–`d3`, NeXTMach 원문, 07 아님; 원본 역어셈블 todis.py):
1. bootparam_xdr [0x1387e8, 0x138a90) 680 B(앞은 확정 xdr_reference 끝 0x1387e8, 0x138a90 은 `_xdr_fhstatus`): 9 함수 크기 원본/NM 같음(마지막 xdr_bp_getfile_res 132/131 은 끝 채움 1 B, 합 680 = 구간). 수정 없이 채택 후보.
2. mountxdr [0x138a90, 0x138ad0) 64 B: 원본에는 `_xdr_fhstatus` 하나뿐(symbols.tsv 에 `_xdr_path`·`_xdr_mountbody`·`_xdr_mountlist`·`_xdr_groups`·`_xdr_exportbody`·`_xdr_exports` 없음; `_xdr_fhandle` 은 0x13412c 다른 객체). NM 은 xdr_fhstatus 64/64 + 빌드 전용 6 개. → xdr_path 부터 끝까지를 `#ifndef KERNEL` 로 감싼다(작성, D024 표시; NM 이 이미 xdr_fhandle 을 같은 방식으로 감쌈).
3. if_loop [0x11f43c, 0x11f560) 292 B(0x11f560 은 `_VENIP_PRIVATE`): logetbuf 20/20, looutput 80/80 같음.
   - locontrol 124/64: (가) SETADDR 에서 `if_flags(ifp) | IFF_UP | IFF_RUNNING`(0x11f4c9 `or al,0x41`); (나) 그 밖 분기 앞에 `strcmp(command, IFCONTROL_ADDMULTICAST) == 0 || strcmp(command, IFCONTROL_ADDMULTICAST) == 0`(0x11f4d8·0x11f4ea 모두 0x1d1255 = `_IFCONTROL_ADDMULTICAST`; RMV 는 0x1d1263 인데 쓰이지 않음 — 원본 그대로 두 번 ADD) 이면 `((struct ifreq *)data)->ifr_addr.sa_family != AF_INET`(0x11f4f9 `cmp word [edi+0x10],2`) 일 때 error = EAFNOSUPPORT(0x2f); 아니면 EINVAL(0x16). error 는 ebx, 0 으로 시작.
   - loattach 68/62: 플래그 인자 0x808(0x11f526) = IFF_LOOPBACK(0x8, net/netif.h:30) | IFF_MULTICAST(0x800, SDK net/if.h:110); 나머지 인자는 빌드와 같음.

방법:
- bootparam_xdr: NeXTMach `rpc/bootparam_xdr.c` 그대로 07 `bsd/rpc/bootparam_xdr.c`. `iter.py s5p206-bpN bsd/rpc/bootparam_xdr.c bootparam_xdr 1387e8 138a90`, relcheck, 기록.
- mountxdr: NeXTMach `rpc/mountxdr.c` + 2. `iter.py s5p206-mxN bsd/rpc/mountxdr.c mountxdr 138a90 138ad0`.
- if_loop: NeXTMach `net/if_loop.c` + 3(작성 표시, 멀티캐스트 분기는 `#if MULTICAST`, `net/if.h` import). `iter.py s5p206-loN bsd/net/if_loop.c if_loop 11f43c 11f560`.

226 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1 bootparam_xdr 구간·9 함수 합 680, 끝 1 B 채움 | python: 0x138a90−0x1387e8 = 680, 진단 크기 합 680 | ✅ |
| 2 mountxdr 구간에 `_xdr_fhstatus` 만(ret 0x138acd 뒤 채움 2 B) | symbols.tsv 3665 행, 다른 6 이름 grep 0 건, `_xdr_fhandle` 0x13412c(3664 행) | ✅ |
| 3 locontrol: 0x41, 두 strcmp 모두 0x1d1255, sa_family(+0x10) 와 2, 0x2f/0x16 | todis 0x11f4a0–0x11f518; 원본 문자열 0x1d1255 `add-multicast`·0x1d1263 `rmv-multicast`·0x1d1212 `setaddr`; errno.h:110 EAFNOSUPPORT 47, :61 EINVAL 22; socket.h:123 AF_INET 2 | ✅ |
| 4 loattach 0x808 = IFF_LOOPBACK\|IFF_MULTICAST, 근거 `if.h:101` | 값은 맞음. 인용 줄은 틀림: if.h:101 은 IFF_LOOPBACK, IFF_MULTICAST 는 :110 | ⚖️ 값 ✅, 줄번호 ❌ |
| 5 if 와 단일 case switch 구별 불가, if 먼저 | 판단 의견 — 빌드로 확인 | ⏭️ |

### 226.1 결과 — 세 객체 A
- bootparam_xdr: `s5p206-bp1`(NeXTMach 그대로) 첫 빌드 OBJECT_MATCH, relcheck 0. SDK 밖 헤더 `rpcsvc/bootparams.h`(NeXTMach) 채택.
- mountxdr: `s5p206-mx1`(xdr_path 이하 `#ifndef KERNEL`) OBJECT_MATCH, relcheck 0. SDK `rpcsvc/mount.h` 사본(D017, 로컬) 채택 행.
- if_loop: it1(`s5p206-lo1`) 함수 크기는 모두 맞으나 locontrol 레지스터 배정이 다름(원본은 data 를 edi 에 두고 ifp 를 스택에서 다시 읽음; 빌드는 반대). 변형 `s5p206-lov1` v1(분기 안 지역 ifr)·v2(switch)·v3(error 뒤 함수 범위 ifr)·v5·v6(register) 모두 50 B 차이, **v4(함수 범위 `struct ifreq *ifr = data` 를 error 보다 먼저)** 차이 0 → 07 에 `#if MULTICAST` 로 적용(`plan 226.1`). it2(`s5p206-lo2`) OBJECT_MATCH, relcheck 0. `-DMULTICAST` 없이 컴파일(`s5p206-nomc`) 성공(경고는 NeXTMach 원문과 같은 if_attach 인자 5).
- 기록: objects_confirmed 162→165, functions +14, PROVENANCE +5(소스 3, 헤더 2).

## 227. S5-P207 세부 계획 — `next/ufs_machdep.c`·`next/dkbad.c` (NeXTMach 그대로, 코딩 전, 2026-10-03)

사실(진단 `s5p207-d3`·`d4`, NeXTMach 원문, 07 아님):
1. ufs_machdep [0x19335c, 0x1934ec) 400 B(`_allocbuf` 0x19335c, 다음 기호 `_sendsig` 0x1934ec 는 unix_signal): allocbuf 380/380, bfree 20/17(끝 채움 3 B 로 봄, 합 400). 스테이징의 미해결 include 4 개(cpu_data.h·features.h·cpu_number.h)는 컴파일에 영향 없음(빌드 성공) — 기록 시 재스테이징으로 다시 확인.
2. dkbad [0x187fec, 0x188044) 88 B(`_isbad`, 다음 기호 `_dma_initialize` 0x188044 는 기록된 dma 부분 객체): isbad 88/88.
같은 회차에 진단만 한 것(채택 안 함): `next/shutdown.c`(s5p207-d1, proc/task 구조 사용으로 컴파일 실패 — kern_exit 의 POSIX·proc 판과 따로 계획), `kernserv/kern_server_handler.c`(s5p207-d2, MIG 생성 `kern_server_handler.h`·`kern_server_server.c` 없음).

방법: NeXTMach 원문 그대로 07 `machdep/i386/ufs_machdep.c`·`machdep/i386/dkbad.c`. `iter.py s5p207-umN machdep/i386/ufs_machdep.c ufs_machdep 19335c 1934ec`, `iter.py s5p207-dkN machdep/i386/dkbad.c dkbad 187fec 188044`, relcheck, 기록.


227 codex 검토 판정(코딩 전에 요청, 회신은 코딩 중 도착 — 아래 검증 후 기록):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| __TEXT 는 vmaddr 0x100000, 파일 오프셋 0 | 이번 세션의 모든 todis/odis 가 `va-0x100000` 으로 원본과 일치 | ✅ |
| allocbuf 끝 `ret` 0x1934d5 뒤 nop 2, bfree 0x1934d8–0x1934e8, 0x1934e9–eb 는 00 | python 바이트: 0x1934d4 `5d c3 90 90 55 89 e5`, 0x1934e6 `ec 5d c3 00 00 00` | ✅ |
| isbad 끝 ret 0x188043, 바로 `_dma_initialize` 0x188044 | 0x188040 `89 ec 5d c3`; symbols.tsv `_dma_initialize` 0x188044 | ✅ |
| CLBYTES 가 `_page_size` 로 풀려야 그대로 컴파일이 맞음 | symbols.tsv `_page_size` 0x1e0d0c; 빌드 s5p207-um1 relcheck 0 | ✅(빌드로 해결) |

### 227.1 결과 — 두 객체 A
- ufs_machdep `s5p207-um1`, dkbad `s5p207-dk1`: NeXTMach 그대로 첫 빌드 OBJECT_MATCH, relcheck 0. objects_confirmed 165→167, functions +3, PROVENANCE +3(소스 2, 헤더 1).

## 228. S5-P208 세부 계획 — physio·physstrat 객체 `bsd/kern/kern_physio.c` (NeXTMach 두 파일 조합, D024, 코딩 전, 2026-10-03)

사실(원본 todis 0x11eb50–0x11ed58; 진단 `s5p208-d1` = NeXTMach `bsd/vm_swp.c` 에서 minphys 를 `next/machdep.c` 의 physstrat 로 바꾸고 btodb 2 인자로 한 스테이징 사본, 07 아님):
1. 객체 [0x11eb50, 0x11ed58) 520 B: `_physio` 0x11eb50(448 B, 채움 포함), `_physstrat` 0x11ed10(72 B, 끝 0x00 1 B); 앞 0x11eb50 은 확정 vfs_xxx 끝, 0x11ed58 은 `_null_init`(확정 af 객체). symbols.tsv 에 `_minphys`·`_swap`·`_swdone`·`_swkill` 없음. MACH 빌드에서 NeXTMach vm_swp.c 는 `#if MACH #else` 로 swap 계열이 빠지고 physio·minphys 만 남음.
2. physstrat: NeXTMach `next/machdep.c:1477–1491` 과 같음(0x11ed25 `test byte [ebx+1],0x20` = B_DIRTY 0x2000, 0x11ed32 `test byte [ebx],2` = B_DONE; buf.h:164·:146). 진단 크기 71/72(끝 채움).
3. physio: (가) 블록 번호는 블록 크기 분기 없이 `btodb(uio->uio_offset, blocksize)`(0x11ec16 `xor edx,edx; div dword [ebp+0x20]`; SDK `sys/param.h:220` 의 2 인자 btodb = unsigned 나눗셈) — NeXT 4.2 의 2 인자 btodb 꼴(plan 214 등과 같음); (나) 함수 첫머리 `mov dword [ebp-8], 0`(0x11eb64) — [ebp-8] 은 vslock/vsunlock 에 넘기는 `a`(0x11ec56 `mov [ebp-8], ecx` = bp->b_un.b_addr) → `char *a = 0;`. 진단에서 차이는 (나) 7 B 뿐(448/440, 나머지 꼴 동일).

방법: 07 `bsd/kern/kern_physio.c` 를 NeXTMach `bsd/vm_swp.c`(머리말·import·physio) + `next/machdep.c` physstrat(고지 보존, 함수 단위 출처 기록)로 만들고, minphys 는 원본에 없으므로 빼고(작성 표시), MACH 아닌 swap 블록은 원문 그대로 둔다. 3(가)(나) 작성 표시. 파일 이름은 objects.tsv 후보 이름(kern_physio.c; Darwin 은 이름만 참고, 본문 미사용). `iter.py s5p208-itN bsd/kern/kern_physio.c kern_physio 11eb50 11ed58`, relcheck, 기록(fn_source 에 physstrat 의 machdep.c 출처).

228 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1 구간·크기 448/72/520, 기호 없음 확인. 단 objects.tsv:64 가 physstrat 를 별도 후보 객체(machdep.c)로 두므로 한 객체라는 주장은 과함 | objects.tsv seq 62(physio)·63(machdep.c, physstrat) 은 이름 기반 신뢰도 C 후보. 원본 바이트 0x11ed0c `5d c3 90 90 55 89`: physio 와 physstrat 사이 채움이 nop(0x90) = 같은 객체 안 정렬, physstrat 뒤 0x11ed57 은 0x00(객체 사이 채움, 이 커널의 링커 채움) | ⚖️ 사실 ✅, 결론 ❌(한 객체 유지) |
| 2 physstrat B_DIRTY 0x2000·B_DONE 2, machdep.c:1477 | todis 0x11ed25·0x11ed32, buf.h:164·:146, machdep.c 1477–1491 (계획의 1476–1490 은 내 오기 → 정정) | ✅ |
| 3 무조건 나눗셈(off_t unsigned), [ebp-8] = a | todis 0x11ec13–0x11ec1b·0x11eb64·0x11ec56·0x11ec7f; 진단 s5p208-d1 은 08_build/runs/s5p208-d1/stage 에 있음 | ✅ |
| 4 그 밖 차이 없음(useracc 인자, MACH 의 splbio 위치) | 진단 tdiff 에서 차이는 0x11eb64 하나 | ✅ |

### 228.1 결과 — A
- 07 `bsd/kern/kern_physio.c`(scratchpad 작업본에서 옮김). `s5p208-it1` 첫 빌드 OBJECT_MATCH, relcheck 0. physstrat 의 함수 출처는 functions.tsv 에 `next/machdep.c:1477`. objects_confirmed 167→168, functions +2, PROVENANCE +1.
- 기록 중 내 실수 정정: 셸 heredoc 의 백틱이 명령 치환되어 MODIFICATIONS 행의 "marked `plan 228`" 가 빈 문자열이 됨 → 그 한 행을 고침(다른 표에는 이 문구 없음, grep 0 건).
- 기록 도구(scratchpad `record_object.py`·`record_partial.py`)가 MODIFICATIONS·증거 문서의 날짜를 2026-10-02 로 고정하고 있었음 → 실행 날짜를 쓰도록 고침. 이미 기록된 행의 날짜는 바꾸지 않음(보고에 명시).

## 229. S5-P212 세부 계획 — boot·unmount_all·kill_tasks·proc_shutdown·fd_shutdown 객체 `bsd/kern/kern_shutdown.c` (NeXTMach 두 파일 조합 + 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis 0x108b84–0x109128 `shut.dis`·`procsh.dis`; 진단 `s5p212-d3` = NeXTMach `next/shutdown.c` 에 `next/machdep.c` 의 waittime·boot(작성판)·unmount_all·kill_tasks 를 넣은 스테이징 사본, 07 아님):
1. 객체 [0x108b84, 0x109128) 1444 B. 기호 `_boot` 0x108b84, `_unmount_all` 0x108ca0, `_kill_tasks` 0x108d40, `_proc_shutdown` 0x108e80, `_fd_shutdown` 0x1090e4; 다음 `_sigvec` 0x109128(kern_sig). 함수 사이 채움은 nop(0x108c9f 뒤 없음, 0x108d3d–3f `90 90 90`, 0x108e7d–7f `90 90 90`) → 한 객체; 앞 0x108b81–83 `00 00 00`, 뒤 0x109127 `00` 은 링커 채움. objects.tsv 는 seq 26(machdep.c)·27(kern_shutdown.c,shutdown.c) 로 나눠 두었으나 이름 기반 후보. `__data` 의 `_waittime`(0x1da990, −1) 과 문자열(0x1da994 `%d `, 0x1da998 `unmounting %s ... `, … 0x1da9e9 `continuing\n`)도 이 객체.
2. boot(작성): `md_prepare_for_shutdown(paniced, howto, command)`(0x108b99) → NeXTMach 의 `(howto&RB_NOSYNC)==0 && waittime < 0 && bfreelist[0].b_forw` 블록(acctp 해제, sync, unmount_all) 다음 `en_down` 루프 대신 `if_down_all()`(0x108bfa), 바쁜 버퍼 루프는 같고 `DELAY(40000 * iter)` 대신 `us_spin(40000 * iter)`(0x108c56–0x108c66, 곱 40000 = 5^4·64); 그 뒤 od/NCPUS/splhigh/mon_call 부분 없이 `md_shutdown_devices(...)`·`md_do_shutdown(...)`(0x108c80·0x108c91). 진단 크기 284/284, 꼴 차이 0.
3. unmount_all: NeXTMach 와 같고 문자열만 `"unmounting %s ... "`(원문 `/%s`). 진단 160/160 차이 0.
4. kill_tasks: 비기본 pset 을 없앤 뒤 `pset = queue_first(&all_psets)` 를 다시 읽음(0x108da0–0x108dc7 → 0x108dc7; NeXTMach 는 다시 읽지 않음). 원본 320 / 진단 324.
5. proc_shutdown: (가) `us_delay(4000000)` 자리에 `ns_sleep(2000000000)` 두 번(0x108f0f–0x108f22, 64 비트 인자), `us_delay(1000000)` 자리에 `ns_sleep(1000000000)`(0x108f57); (나) 파일 루프에서 `f != FPINPROGRESS`(SDK sys/file.h:119 `(void *)0xffff0000`, 0x109005) 도 검사, SUN_LOCK 의 `vno_lockrelease(f)` 호출(0x109011; `sun_lock.h` = 1); (다) 끝에 `thread_wakeup((int)&reaper_queue)`(0x1090b4–0x1090bd, thread_wakeup_prim(…,0,0)), `ns_sleep(2000000000)`, `printf("continuing\n")`. 원본 612 / 진단 552.
6. fd_shutdown: 다음 항목을 closef 전에 저장(0x1090f8 `mov esi,[ebx]`, 0x109114 `mov ebx,esi`). 원본 68(끝 채움 포함) / 진단 53.

방법: 07 `bsd/kern/kern_shutdown.c` = NeXTMach `next/shutdown.c`(머리말·import·proc_shutdown·fd_shutdown) 앞에 `next/machdep.c` 의 waittime·unmount_all·kill_tasks(원문, 고지 보존, 함수 단위 출처)와 작성한 boot 를 원본 순서(boot, unmount_all, kill_tasks, proc_shutdown, fd_shutdown)로 둔다. 2–6 은 작성 표시(`plan 229`). 필요한 import(sys/buf.h·reboot.h·vfs.h, kern/task.h·thread.h·processor.h, vm/vm_map.h·vm_kern.h, sun_lock.h)는 빌드로 확정. 파일 이름은 objects.tsv 후보 이름 kern_shutdown.c(Darwin 은 구조만). `iter.py s5p212-itN bsd/kern/kern_shutdown.c kern_shutdown 108b84 109128`, relcheck, 기록.

229 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1 범위 1444, 채움(0x1090e2–e3 nop 포함), `_waittime`·문자열 | python 바이트: 0x108b81 `00 00 00`, 0x108d3c `c3 90 90 90`, 0x108e7d `90 90 90`, 0x1090e2 `90 90`, 0x109127 `00`; 문자열 0x1da994–0x1da9e9 | ✅ |
| 2 boot 호출 순서·40000×iter | shut.dis 0x108b99–0x108c91 | ✅ |
| 3 unmount_all 문자열, NeXTMach machdep.c:1352 `/%s` | machdep.c 1352 열람 | ✅ |
| 4 kill_tasks 재읽기, NeXTMach :1385–1388 에는 없음 | machdep.c 1385–1388 열람 | ✅ |
| 5 ns_sleep 2e9 두 번·1e9, FPINPROGRESS, vno_lockrelease 는 NeXTMach 에도 SUN_LOCK 아래(:101), 끝 세 단계 | procsh.dis, file.h:119, shutdown.c 99–102 열람 | ✅ (vno_lockrelease 는 원문 그대로, `sun_lock.h` import 만 필요) |
| 6 fd_shutdown 다음 항목 저장, NeXTMach :139–143 | shutdown.c 139–143 열람 | ✅ |
| 7 proc/utask 오프셋 일치, 다른 차이 없음; 진단 크기 쌍의 순서를 표시하라 | procsh.dis 오프셋; 계획의 "진단 324/320"·"552/612"·"53/68" 은 내 표기가 원본/진단 순서와 뒤섞여 있었음 → "원본 N / 진단 M" 으로 고침 | ✅ (내 표기 오류) |

### 229.1 결과 — A
- 07 `bsd/kern/kern_shutdown.c`(scratchpad 작업본에서 옮김). it1(`s5p212-it1`) 컴파일 실패: `reaper_queue` 선언 없음 → 작성 블록 안에 `extern queue_head_t reaper_queue;`(07 `kern/thread.c:110` 정의와 같은 형). it2(`s5p212-it2`) 5 함수 모두 일치, OBJECT_MATCH(`__data` 포함), relcheck 0.
- 기록: objects_confirmed 168→169(파일 기준 행 수), functions +5(boot·unmount_all·kill_tasks 는 `next/machdep.c` 출처), PROVENANCE +1. MODIFICATIONS·증거 문서 날짜는 이번부터 실행 날짜(2026-10-03).

## 230. S5-P214 세부 계획 — core() 객체 `bsd/kern/kern_core.c` (NeXTMach kern_sig.c 의 core + 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis `core.dis` 0x103824–0x103e3c; 진단 `s5p214-d2` = NeXTMach `bsd/kern_sig.c` 에서 core 만 남긴 스테이징 사본 + SDK mach-o/loader.h, 07 아님 — m68k 의 NeXT_THREAD_STATE_* 로 컴파일 실패):
1. 객체 [0x103824, 0x103e3c) 1560 B, 기호 `_core` 하나. 앞 0x103822–23 `00 00`(add_profil 뒤 링커 채움), 뒤 0x103e3b `00`, 다음 기호는 `_getdtablesize` 0x103e3c(kern_descrip); kern_sig 본체(`_sigvec` 0x109128)와는 떨어진 다른 객체. objects.tsv seq 17 은 이름 기반 후보 `kern_sig.c`. 파일 이름은 kern_core.c 로 둔다(검증 불가, 기록).
2. 앞부분(SXONLY 검사, uid/gid, u_rpause, rlimit, task_halt, pcb_synch, `/cores/core.%d`(0x1da62a) → 실패 시 `core`(0x1da639) 로 vn_create 재시도, va_nlink 검사, VOP_SETATTR, ACORE)은 NeXTMach core 와 같은 흐름. 차이: va_nlink != 1 이면 `error = EFAULT; goto out;`(0x1039a7 `mov ebx,0xe`; NeXTMach 는 u.u_error 에 넣음).
3. 스레드 상태: `nflavors = 20`(0x103a09, 정수 개수) 로 `thread_getstatus(current_thread(), THREAD_STATE_FLAVOR_LIST, flavors, &nflavors)`(0x103a30), 실패 시 `panic("core flavor list")`(0x1da63e), `nflavors /= 2`(0x103a4f `shr`), `tstate_size += sizeof(struct thread_state_flavor) + flavors[i].count*sizeof(int)` 루프(0x103a80–0x103ab1). SDK `mach/thread_status.h:89–95`(THREAD_STATE_FLAVOR_LIST 0, struct thread_state_flavor). flavors 는 −0xb0..−0x60 = 80 B → 10 개.
4. command_size = segment_count·sizeof(segment_command)(56) + thread_count·sizeof(thread_command)(8) + tstate_size·thread_count(0x103ab3–0x103ad2), header_size = + sizeof(mach_header)(0x1c), `kmem_alloc_wired(kernel_map, &header, header_size)`(0x103aed; NeXTMach 는 `header = kmem_alloc(...)`).
5. segment 루프: 조건에 error 검사 없음(`while (segment_count > 0)`, 0x103b54·0x103c76–0x103c83); 나머지(vm_region·LC_SEGMENT·vm_protect·vn_rdwr)는 NeXTMach 와 같음.
6. thread 루프: `tc->cmdsize = sizeof(struct thread_command) + tstate_size`, 각 flavor 마다 `*(struct thread_state_flavor *)(header+hoffset) = flavors[i]`, `thread_getstatus(thread, flavors[i].flavor, header+hoffset, &flavors[i].count)`, `hoffset += flavors[i].count*sizeof(int)`(0x103cd0–0x103d9f).
7. 스택 배치(주소를 쓰는 지역): vattr −0x40, core_name −0x60(32 B), flavors −0xb0, vp −0xb4, nflavors −0xb8, header −0xbc, vmoffset −0xc0, size … offset −0xdc. core_name 길이는 이 배치에서 29–32 B → `char core_name[32]` 로 둠(추론, 빌드로 확인).

방법: 07 `bsd/kern/kern_core.c` = NeXTMach `bsd/kern_sig.c` 의 머리말·import(헤더는 07 관례로: `mach/vm_param.h`, `mach-o/loader.h`)와 core() 본문, 2–7 작성 표시(`plan 230`). 나머지 kern_sig 함수는 이 파일에 두지 않음(kern_sig 본체는 따로 계획). `iter.py s5p214-itN bsd/kern/kern_core.c kern_core 103824 103e3c`, relcheck, 기록(함수 출처: NeXTMach kern_sig.c:1162).

230 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1 범위·채움 맞음, 그러나 다음 기호는 `_getdtablesize` 0x103e3c | symbols.tsv 1066 행 `_getdtablesize` 0x103e3c | ✅ 내 문구 오류 → 사실 1 정정(결론 "다른 객체" 는 그대로) |
| 2 앞부분 흐름·문자열·EFAULT | core.dis 0x103830–0x1039ea, 문자열 3 개 이번 세션에 python 으로 읽음 | ✅ |
| 3 flavor 조회·tstate_size | core.dis 0x103a09–0x103ab1 | ✅ |
| 4 크기 식·kmem_alloc_wired | core.dis 0x103ab3–0x103aed | ✅ |
| 5 segment 루프는 개수만 검사, vn_rdwr 결과 버림 | core.dis 0x103c59 뒤 저장 없음 | ✅ (작성본은 `error = vn_rdwr(...)` 를 두되 루프 조건에서 error 를 뺌 — 죽은 대입이면 같은 코드, 빌드로 확인) |
| 6 thread 루프 | core.dis 0x103cd0–0x103d9f | ✅ |
| 7 core_name 32 B 는 상한일 뿐, NeXTMach 의 `[20]`(kern_sig.c:1185) 도 가능 | kern_sig.c 1185 열람. 20 B 배열이 −0x60 에 놓일 수 있는지는 gcc 2.7 의 스택 슬롯 정렬에 달림 | ⚖️ 채택: `[20]` 과 `[32]` 를 변형으로 빌드해 정함 |
| 8 그 밖 오프셋은 NeXTMach 흐름과 일치 | core.dis 해당 주소 | ✅ |

### 230.1 결과 — A
- it1(`s5p214-it1`) 컴파일 실패: 07 vm_map.h 에는 `map->nentries` 가 없고 `map->hdr.nentries`(원본 map+0x1c) → 고침. it2: 크기 같고 13 B 차이 — 스필 슬롯 두 개가 뒤바뀜(원본 tstate_size −0xec·hoffset −0xf0). tstate_size 선언을 hoffset 앞(command_size 줄)으로 옮김(`plan 230.1`). it3(`s5p214-it3`) OBJECT_MATCH, relcheck 0.
- core_name 크기 변형 `s5p214-cv1`: 20·24·28 B 는 120–124 B 차이, 32 B 만 일치 → codex 7 의 의문을 빌드로 정리.
- 기록: objects_confirmed 169→170, functions +1, PROVENANCE +1.

## 231. S5-P215 세부 계획 — kern_sig 본체 `bsd/kern/kern_sig.c` (NeXTMach + POSIX·4.2 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis 0x109128–0x10a384, `issig.dis`; 진단 `s5p215-d1` = NeXTMach `bsd/kern_sig.c` 에서 core 를 빼고 헤더(`mach/vm_param.h`)·`aston()`→`ast_on(cpu_number(), AST_UNIX)`·SIGMSG/SIGEMSG 제거·`thread->_uthread` 로 고친 스테이징 사본, 07 아님):
0. 객체 [0x109128, 0x10a384) 4700 B(앞은 확정 kern_shutdown, 뒤 0x10a382–83 `00 00`). 기호 17 개 순서·원본 크기: sigvec 288, setsigvec 408, sigblock 92, sigsetmask 84, sigcont 16, sigpause 96, sigstack 140, kill 348, killpg 56, killpg1 216, gsignal 40, pgsignal 80, psignal 868, issig 1176, stop 40, psig 704, sigpending 48. 진단에서 killpg·killpg1·sigstack·stop 은 꼴 차이 0, psig 702 는 한 곳.
1. cantmask(sigvec…sigpause 에서만, NeXTMach 도 sigpause 뒤 `#undef`): `u.u_procp->p_posix`(proc+0x16 비트 1) 이면 `sigmask(SIGKILL)|sigmask(SIGSTOP)`(마스크 0xfffefeff), 아니면 SIGCONT 포함(0xfffafeff) — setsigvec 0x1092a6, sigblock 0x109411, sigsetmask 0x109469, sigpause 0x1094cc.
2. sigvec: SIGCONT 를 SIG_IGN 으로 바꾸는 것은 POSIX 프로세스면 허용(0x109207–0x109217 `test byte [proc+0x16],2`); SIGMSG/SIGEMSG 블록 없음; setsigvec 뒤 `u.u_sigreturn = (int (*)())u.u_ar0[EDX]`(0x109227–0x109237, utask+0x138 = SDK user.h `uu_sigreturn`(#ifdef i386), ar0[9]).
3. setsigvec: 무시 처리 조건이 `sv_handler == SIG_IGN || (p->p_posix && sv_handler == SIG_DFL && sig == SIGCHLD)`(0x10931c–0x109334); SIG_DFL 일 때 POSIX 면 `u.u_signal[sig] = SIG_DFL`(0x1093ab–0x1093b9) 후 p_sigcatch 해제.
4. sigcont(새 함수, 0x109490): `unix_syscall_return(EINTR)`. sigpause: 끝의 `for(;;) sleep(&u, PSLEP)` 대신 `sleep_with_continuation((caddr_t)&u, PSLEP, sigcont)`(0x1094e6–0x1094f2).
5. kill: POSIX 프로세스면 `pp = get_posix_proc(p->p_pid)` 로 `suser()` 또는 u_uid/u_ruid 가 pp->p_ruid/p_svuid 와 같거나, signo == SIGCONT 이고 두 프로세스의 `get_posix_proc(..)->p_session` 이 같으면 `u.u_error = 0` 후 진행, 아니면 EPERM(0x1095d8–0x109692); 아니면 NeXTMach 의 uid 검사. SDK proc.h:257–274 posix_proc(p_ruid +4, p_svuid +6, p_posix_pgrp +0x10, pg_session +8).
6. gsignal: `if (pgid && (pgrp = pgfind(pgid))) pgsignal(pgrp, sig, 0)`(0x1097f8). pgsignal(새, 0x109820): `if (pgrp) for (p = pgrp->pg_mem; p; p = get_posix_proc(p->p_pid)->p_pgrpnxt) if (checkctty == 0 || p->p_flag & SCTTY) psignal(p, sig);`(SCTTY 0x40000000, proc.h:568).
7. psignal: 무시·보류 판정에서 POSIX 프로세스의 SIGCONT 는 제외(`!(p->p_posix && mask == sigmask(SIGCONT))`, 0x1098bc–0x1098e4); switch 에 SIGMSG/SIGEMSG case 없음(0x10991a 점프 표 sig 15–22).
8. issig(catch)(인자 하나; SDK param.h:130–134 `issig(0)`/`issig(1)`; 원본 호출 sleep 0x10a600 `push 1`, check_for_ast 0x192a95 `push 0`): sigbits 가 있으면 `if (catch && (p->p_flag & STRC)) { sig_unlock(p); return (TRUE); }`(0x109cd8–0x109ce2 → 0x10a04c); 추적 정지 경로의 `pcb_synch(p->thread)` 는 i386 에서도 호출(0x109d53); SIG_DFL 이고 p_ppid == 0 이면 `u.u_cursig = 0; u.u_sig &= ~mask;`(0x109f2f–0x109f43); 기본 동작 switch 에 SIGMSG/SIGEMSG 없음(0x109f4c 점프 표 sig 16–28).
9. psig: `panic("psig action")` 대신 `log(LOG_WARNING, "psig: processing masked or ignored signal\n")`(0x10a195–0x10a19c, 문자열 0x1daa23).
10. sigpending(새, 0x10a354): `u.u_error = copyout((caddr_t)&u.u_procp->p_sig, (caddr_t)uap->set, sizeof (int))`.

방법: 07 `bsd/kern/kern_sig.c` = NeXTMach `bsd/kern_sig.c`(core 는 kern_core.c 로 이미 분리, 이 파일에서는 뺌) + 헤더 정리 + 1–10 작성(`plan 231`, POSIX 부분은 `#if POSIX_KERN`). SIGMSG/SIGEMSG 부분은 원본에 없으므로 지움(수정 기록). `iter.py s5p215-itN bsd/kern/kern_sig.c kern_sig 109128 10a384`, relcheck, no-POSIX 컴파일 확인, 기록.

231 codex 검토 판정(코딩 전; 진단 `s5p215-d2` 는 계획 1–10 을 반영한 스테이징 사본):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 범위 4700·17 함수 크기·뒤 채움 | python 4700, symbols.tsv | ✅ (진단 산출물은 08_build/runs/s5p215-d1·d2 에 있음) |
| 1 cantmask 두 마스크(0xfffefeff/0xfffafeff) | 원본 0x1092a6·0x109411·0x109469·0x1094cc | ✅ |
| 2 sigvec SIGCONT·u_sigreturn | 원본 0x109202–0x109237, user.h:147 | ✅ |
| 3 setsigvec | 원본 0x10931c–0x1093c1 | ✅ |
| 4 sigcont·sigpause | 원본 0x109490·0x1094e6–0x1094f2 | ✅ |
| 5 kill POSIX(양수 pid 만), killpg1 은 옛 검사 그대로 | 원본 0x1095d8–0x109692; 진단에서 killpg1 꼴 차이 0 | ✅ |
| 6 gsignal·pgsignal | 원본 0x1097f8–0x109862 | ✅ |
| 7 psignal SIGCONT 예외, 점프 표 15–22·9–28 | 원본 0x1098bc–0x1098f8; 진단 d2 에서 psignal 꼴 차이 0 | ✅ |
| 8 issig(catch)·pcb_synch·p_ppid == 0 경로 | 원본 0x109cd8·0x109d53·0x109f28–0x109f46 | ✅ |
| 9 psig log | 원본 0x10a18b–0x10a19c | ✅ |
| 10 sigpending | 원본 0x10a354–0x10a37b | ✅ |
| 추가: sigvec 은 신호 32 를 거부(`sig-1 > 30`), NeXTMach :138 은 `sig > NSIG` | 원본 0x109141 `cmp edx,0x1e`; 진단 d2 의 같은 자리 즉값이 다름(python 바이트 비교, 0x109143). tdiff 는 즉값을 정규화해서 놓쳤음 | ✅ 채택: `sig >= NSIG` |
| 추가: thread +0x84 uthread·aston → AST_UNIX | 계획 방법에 이미 반영(`thread->_uthread`, `ast_on(…, AST_UNIX)`) | ✅ |

진단 d2 결과: kill 을 뺀 16 함수가 크기·꼴 일치. kill 은 364/348 — 레지스터 배정(원본: uap→esi, pp→edi, p 는 스택). 변형 `s5p215-kv1`(선언 위치·register 6 가지), `kv2`(인라인 도우미 3 가지), `kv3`(조건식 꼴 5 가지) 모두 불일치.

### 231.1 결과 — A
- 07 `bsd/kern/kern_sig.c`(scratchpad 작업본 + codex 추가 지적의 `sig >= NSIG`). it1(`s5p215-it1`) kill 만 364/348. 변형 `s5p215-kv4`(선언 순서 5 가지)·`kv5`(지역 cred·비교 순서·signo 지역 등 5 가지) 불일치(signo 지역 변수는 p 를 스택으로 보내지만 다른 차이를 만듦), `kv6` 의 세 꼴(POSIX 분기가 자기 psignal 호출과 return 을 가짐) 모두 차이 0 → NeXTMach 원문 줄을 그대로 두는 꼴(y3)을 적용(`plan 231.1`).
- it2: 바이트 차이 0, 외부 이름 하나 다름 — 빌드 `_thread_exception_abort`, 원본 0x1584d4 `_mach_msg_abort_rpc`(새 IPC; 07 kern/thread.c:1750 과 같은 호출) → 고침. it3 OBJECT_MATCH, relcheck 0.
- `-DPOSIX_KERN`·`-D_POSIX_SOURCE` 없이 컴파일(`s5p215-noposix`) 실패: gsignal/pgsignal 이 struct pgrp·SCTTY 사용 → `#if POSIX_KERN` 안에 두고 그 밖은 NeXTMach gsignal. it4(`s5p215-it4`) OBJECT_MATCH, relcheck 0; `s5p215-noposix2` 컴파일 성공.
- 기록: objects_confirmed 170→171, functions +17(sigcont·pgsignal·sigpending 은 작성 출처), PROVENANCE +1.
- 교훈: tdiff.py 는 즉값을 정규화하므로 상수 차이(sigvec 의 NSIG 경계)를 보이지 않는다 → 꼴 비교 뒤에는 L1(바이트) 결과로 확인한다.

## 232. S5-P216 세부 계획 — `bsd/kern/init_main.c` (NeXTMach + main·init_task·lightning_bolt 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis `initmain.dis` 0x102934–0x103088; 진단 `s5p216-d1` = NeXTMach 원문, 헤더(machine/vm_types.h, vm/vm_param.h, kern/ipc_globals.h)로 실패):
0. 객체 [0x102934, 0x103088) 1876 B(앞 0x102931–33 `00`, 뒤 0x103085–87 `00`; 0x102931 앞은 확정 cmu_syscalls 끝). 함수: task_name 0x102934(64), main 0x102974(1212), init_task 0x102e30(116), lightning_bolt 0x102ea4(72), bhinit 0x102eec(40), binit 0x102f14(284), cinit 0x103030(76), 기호 없는 정적 함수 0x10307c(9 B + 채움 3)(`xor eax,eax; ret`, main 이 `objc_setClassHandler` 에 넘김, 0x102d00).
1. `__DATA,__data` [0x1da000, 0x1da034) 52 B: dk_ndrive(=4), cmask(0x12), vm_initial_limit_stack {0x80000, 0x7fffffff}·data {0x600000, 0x7fffffff}·core {0, 0x7fffffff}, 문자열 "kernel idle"(0x1da020)·"init"(0x1da02c). NeXTMach 의 선언 순서(dk_ndrive … cmask, task_name 뒤 vm_initial_limit_*)와 같음. 원본에 `_tz`·`_phz` 기호 없음 → 그 두 정의는 뺌.
2. task_name: NeXTMach 와 같은 꼴(strlen 인라인, `length > 16 ? 17 : length + 1`).
3. main(작성; NeXTMach 골격): pqinit … pidhash_enter, `p->task = kernel_task`, `s = splhigh(); splx(s);`(timer_switch 없음), `calloutInitialize()`, `switch_unix_context(current_thread())`; p_stat·p_flag·p_nice·siglock·sigwait·exit_thread·u_procp; crget·cmask·lastfile·rlimit 루프·세 limit(NeXTMach 순서); POSIX 초기화(0x102aa4–0x102b6e): `pgrphash[i] = posix_proc_hash[i] = 0`(64 개), `px = new_posix_proc(0)` 후 p_posix_pgrp = &pgrp0, p_pgrpnxt = 0, p_ruid = cr_ruid, p_svuid = cr_uid, p_svgid = cr_gid, p_lockf_chan = 0, p_posix_utime = p_posix_noctty = 0, `pgrphash[0] = &pgrp0`, pgrp0 = {hforw 0, mem p, session &session0, jobc 0}, session0 = {1, p, 0, 0}; `gc_init()`; kmem_suballoc(512 KB, TRUE)(wait_for_space 저장 없음); `ns_hardclock_init()`; mfs_init; cred lock·crhold·rootcred·NOGROUP 루프(qtinit·timestamp_init·startrtclock 없음); mbinit·cinit; `s = splnet()`(NeXTMach splimp)·ifinit·domaininit·splx; bhinit·dnlc_init; rdir/cdir; CPU 루프에서 thread_create·`thread_bind(th, processor_ptr[i])`·`thread_start(th, idle_thread)`(인자 2)·`thread_doswapin(th)`·thread_resume; binit; recompute_priorities; `lightning_bolt(0, 0)`; kernel_thread(kernel_task, f, 0) 로 reaper·swapin·sched·netisr; `_objcInit()`·`objc_setClassHandler(정적 함수)`·`kmEnableAnimation()`·`autoconf()`·`setconf()`·`loattach()`; u_error = 0·vfs_mountroot; u_rpause = 0xf(boottime = time 없음); file_init; `th = newproc(0)`, task->kernel_privilege = FALSE, init_proc = pfind(1); `ux_handler_init()`, `port_reference(ux_exception_port)`, `task_set_special_port(th->task, TASK_EXCEPTION_PORT, ux_exception_port)`; `thread_start(th, init_task)`·thread_resume; `power_init()`; `pageoutThread = kernel_thread(kernel_task, vm_pageout, 0)`; vol_start_thread·pnotify_start; p_flag |= SLOAD|SSYS; task_name("kernel idle"); thread_terminate·thread_halt_self.
4. init_task(작성): task_name("init"); `u.u_ar0 = USER_REGS(current_thread())`(0x102e6b–0x102e91, 07 machdep/i386/thread.h:182 의 매크로 꼴); `load_init_program()`; `thread_exception_return()`.
5. lightning_bolt(a0, entry)(작성): `thread_wakeup((int)&lbolt)`; entry 가 0 이면 `calloutEntryAllocate(lightning_bolt, 0)`; `calloutEntryDispatchDelayed(entry, calloutDeadlineFromInterval(1000000000LL))`.
6. bhinit·binit·cinit: NeXTMach 와 같은 흐름(빌드로 비교; binit 의 b_rtpri 는 +0x3c).

방법: 07 `bsd/kern/init_main.c` = NeXTMach `bsd/init_main.c`(머리말·전역·task_name·bhinit·binit·cinit) + 3–5 작성(`plan 232`) + 끝의 정적 클래스 처리 함수. 헤더는 07 관례로 정리(mach/vm_param.h 등, kern/ipc_globals.h 제거). 옛 IPC·MACH_XP 부분은 원본에 없으므로 뺌. `iter.py s5p216-itN bsd/kern/init_main.c init_main 102934 103088`, relcheck, 기록.

232 codex 검토 판정(코딩 전; 진단 `s5p216-d3` = 계획을 반영한 스테이징 사본):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 범위·채움·함수 크기 맞음, 단 cinit 은 76 B(88 은 정적 함수 포함) | 0x10307c−0x103030 = 76(python), 진단 d3 cinit 76/76 | ✅ → 사실 0 정정 |
| 1 `__data` 내용·`_tz`/`_phz` 없음(선언 순서는 바이트로 증명 불가) | 원본 바이트 0x1d9ff0–0x1da040 덤프, symbols.tsv | ✅ (순서는 빌드 L1 로 확인) |
| 2 task_name | initmain.dis 0x102934–0x102970 | ✅ |
| 3 main 순서 맞음, 단 `u_cdir`(0x102c23) 를 `u_rdir` 보다 먼저 지움 — 계획이 뒤바뀜 | 0x102c23 의 저장은 `[u+0x164]`, 0x102c33 은 `[u+0x160]`. uu_cdir = +0x160, uu_rdir = +0x164(proc_shutdown 0x10904c·0x109076 — OBJECT_MATCH 로 기록된 kern_shutdown 에서 같은 오프셋) → 원본은 rdir 먼저, 계획대로 | ❌ 기각(오프셋 오인) |
| 3 pgrp0.pg_id 는 저장하지 않음(0 초기화) | 작업본도 pg_id 를 쓰지 않음 | ✅ |
| 4 init_task·5 lightning_bolt·6 bhinit/binit/cinit | initmain.dis 해당 주소; 진단 d3 에서 일곱 함수 크기 일치, 꼴 차이는 재배치 주소 표기뿐 | ✅ |

### 232.1 결과 — A
- 07 `bsd/kern/init_main.c`(scratchpad 작업본). it1(`s5p216-it1`) 첫 빌드 OBJECT_MATCH(`__text`·`__data`), relcheck 0. it2: main 의 POSIX 초기화를 `#if POSIX_KERN` 으로 감쌈 → OBJECT_MATCH, relcheck 0; `-DPOSIX_KERN` 없이 컴파일(`s5p216-noposix`) 성공.
- 기록: objects_confirmed 171→172, functions +8(main 은 NeXTMach 골격 + 작성, lightning_bolt·정적 classHandler 는 작성 출처), PROVENANCE +1. 첫 기록 시도는 정적 함수의 출처가 없어 도구가 쓰기 전에 멈춤(표 행 수 변화 없음 확인) → fn_source 추가 후 기록.

## 233. S5-P218 세부 계획 — `bsd/kern/kern_clock.c` (NeXTMach + 4.2 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis 0x10349c–0x103822; 진단 `s5p218-d1` = 아래 방법을 반영한 스테이징 사본, 07 아님 — 8 함수 크기·꼴 일치):
0. 객체 [0x10349c, 0x103822) 902 B: hardclock 340, gatherstats 104, timeout 44, untimeout 20, hzto 148, ticks_to_timeval 32, profil 132, add_profil 82. 앞은 확정 kern_acct 끝(0x10349c, 채움 0), 뒤 0x103822–23 `00 00` 다음 core(plan 230). profil 끝 0x1037cf 바로 뒤 add_profil 0x1037d0(채움 없음, 정렬상 필요 없음) — objects.tsv 는 add_profil 을 이름 기반 후보 subr_prof.c(seq 16) 로 따로 두지만, NeXTMach 은 profil 을 kern_clock.c 에 두고 원본에서 둘이 붙어 있으므로 한 객체로 둔다(추론, 기록).
1. 원본에 `_callfree`·`_calltodo`·`_callout_lock`·`_softclock`·`_phz`·`_hardclock_usec_mark` 없음, `_callout`(common)·`_ncallout`(다른 객체 __data) 있음 → callout 표 처리(softclock·callout 큐)를 뺌.
2. hardclock(0x10349c): NeXTMach 의 USERMODE 부분(SOWEUPC + `aston()` → need_ast |= AST_UNIX(0x1034d3–0x1034df), ITIMER_VIRTUAL), CPU rlimit·ITIMER_PROF 부분만 남고, 끝에 `gatherstats(pc, ps)`(0x1035e0). usec_elapsed·clock_tick·master_cpu·BUMPTIME·callout 큐 없음; `tick` 은 전역(0x1dee34).
3. gatherstats: NeXTMach 와 같음(GPROF 없음).
4. timeout(fun, arg, t) = `ns_timeout(fun, arg, ticks_to_ns_time(t), 0)`(0x103663–0x103675), untimeout = `ns_untimeout(fun, arg)`(0x10368f).
5. hzto: splhigh/splx 없이 `getthetime(&now)`(0x1036a8) 를 쓰고 time 대신 now.
6. ticks_to_timeval: NeXTMach 와 같음(ASSERT 없음).
7. profil: 네 필드 저장 뒤 `pr_lock` 이 0 이면 `simple_lock_alloc()` 후 초기화(0x103788–0x10379c), pr_next 목록을 kfree(…, 0x18) 로 풀고 pr_next = 0(0x1037a2–0x1037c0).
8. add_profil(작성): pr_scale 이 0 이 아니면 `kalloc(sizeof (struct uuprof))`(0x18) 에 네 필드를 넣고 pr_next 목록 앞에 붙임(0x1037e3–0x103813). SDK user.h uuprof(pr_lock, pr_next, pr_base, pr_size, pr_off, pr_scale).

방법: 07 `bsd/kern/kern_clock.c` = NeXTMach `bsd/kern_clock.c` 머리말·import(07 관례: mach/machine.h·mach/time_value.h·mach/boolean.h, kern/ast.h; i386/clock.h·vax·balance·next/us_timer.h·busvar.h 제거) + 2–8(`plan 233`). `iter.py s5p218-itN bsd/kern/kern_clock.c kern_clock 10349c 103822`, relcheck, 기록(add_profil 은 작성 출처).

233 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 크기·경계 맞음, add_profil 이 같은 원본 객체라는 것은 추론 | python 크기, 0x103822 `00 00`; 계획 0 에 이미 "추론" 으로 적음 | ✅ (기록에 inferred 명시) |
| 1 없는 기호 6 개, `_callout` common·`_ncallout`/`_tick` __data; ncallout 정의 객체는 알 수 없음 | symbols.tsv | ✅ (작업본은 NeXTMach 대로 `int ncallout;` 잠정 정의 — common 이 다른 객체의 __data 정의로 합쳐짐) |
| 2 hardclock·3 gatherstats·4 timeout/untimeout·5 hzto·6 ticks_to_timeval | 원본 todis, 진단 s5p218-d1 꼴 차이 0 | ✅ |
| 7 profil 에 lock 획득/해제 없음, 8 add_profil 은 기존 pr_scale 검사 | 원본 0x103788–0x1037c0·0x1037e3; 작업본이 그대로임 | ✅ |
| codex 가 s5p218-d1 에 L1 비교기를 돌려 OBJECT_MATCH 라고 함 | codex 출력은 근거로 쓰지 않음 — 07 빌드의 L1 로 확인 | ⏭️ |

### 233.1 결과 — A
- 07 `bsd/kern/kern_clock.c`(scratchpad 작업본; profil 의 kfree 인자를 `(vm_offset_t)` 로 — 경고 제거). `s5p218-it1` 첫 빌드 OBJECT_MATCH, relcheck 0.
- 기록: objects_confirmed 172→173, functions +8(add_profil 은 작성 출처), PROVENANCE +1. add_profil 의 객체 소속은 추론으로 증거 문서에 적음.

## 234. S5-P219 세부 계획 — 나노초 타이머 객체 `kern/ns_timer.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis 0x160478–0x160adc, `ustimer.dis`):
0. 객체 [0x160478, 0x160adc) 1636 B, 함수 17 개: ns_hardclock_init 56, ns_timeout 48, ns_abstimeout 28, ns_untimeout 28, ns_sleep 116, ns_time_to_timeval 88, timeval_to_ns_time 144, ns_time_to_tsval 92, ticks_to_ns_time 68, sched_usec_elapsed 132, get_calendar_time_value 88, set_calendar_time_value 84, microtime 200, microboot 88, us_timeout 188, us_abstimeout 160, us_untimeout 28. 앞 0x160476–77 `00 00`(miniMon 쪽 끝), 뒤 0x160ad9–db `00`(다음 power_callout). 함수 사이는 nop 채움이거나 정렬이 맞아 채움 없음 — 0x00 채움 없음 → 한 객체로 둔다(채움 없는 이음매 0x1604af|b0, 0x1604df|e0, 0x1604fb|fc, 0x160713|14, 0x160a1f|20 다섯 곳은 바이트로 증명 불가, 추론 — codex 정정). 근거: microtime·microboot·get_calendar_time_value 는 ns_time_to_timeval 의 64/32 나눗셈이, us_timeout·us_abstimeout 은 timeval_to_ns_time 의 곱셈이 인라인된 꼴 → 같은 파일 앞쪽 정의의 -O3 인라인.
1. 데이터: `_ns_per_tick` common(0x1f6530, 8 B); microtime 의 정적 이전 값 `__DATA,__data` 0x1df21c(8 B, 0 으로 초기화된 정적), sched_usec_elapsed 의 정적 이전 값 `__DATA,__bss` 0x1e5e44(8 B) → `__bss` 는 참조 추론(P) 예상.
2. 64/32 나눗셈: msw/lsw 를 차례로 `divl` 하는 인라인(몫을 제자리에 저장, 나머지 출력) — ns_time_to_timeval(0x1605a4–0x1605bf, 1e9), ns_time_to_tsval(1000), sched_usec_elapsed(1000), 인라인된 microtime·microboot·get_calendar_time_value. 정적 inline 함수 + `asm("divl …")`(eax/edx 출력, 제수는 "rm") 로 작성.
3. 함수별(원본 주소 순): ns_hardclock_init: `ns_per_tick = NSEC_PER_SEC / hz; hardclock_init(ns_per_tick)`. ns_timeout: `calloutDispatchDelayed(proc, arg, time + clock_value(System))`(pri 안 씀). ns_abstimeout: `calloutDispatchDelayed(proc, arg, deadline)`. ns_untimeout: `calloutRemove(proc, arg); return TRUE`. ns_sleep: `s = splnet()`(Darwin splhigh), ns_timeout(wakeup, &delay, delay, …) 인라인, `sleep(&delay, PZERO - 1)`, splx. ns_time_to_timeval: 나눗셈 후 tv_sec = 몫 하위, tv_usec = 나머지 / 1000. timeval_to_ns_time: `((ns_time_t)tv_sec * 1000000 + tv_usec) * 1000`. ns_time_to_tsval: 1000 으로 나눈 64 비트 몫을 low_val/high_val 로. ticks_to_ns_time: 부호 없는 ticks × ns_per_tick. sched_usec_elapsed: now = clock_value(System), 정적 이전 값이 0 이면 now 로, (now − 이전)/1000 의 하위 32 비트 반환, 이전 = now. get_calendar_time_value(tvp): ns_time_to_timeval(clock_value(Calendar), tvp) 꼴. set_calendar_time_value(tvp): `set_clock(Calendar, (ns_time_t)seconds * NSEC_PER_SEC + (ns_time_t)microseconds * 1000)`. microtime: `s = splusclock(); now = clock_value(Calendar);` 이전 값이 now 보다 크고 차가 NSEC_PER_SEC 미만이면 now = 이전; 이전 = now; splx(s); ns_time_to_timeval(now, tvp). microboot: ns_time_to_timeval(clock_value(System), tvp). us_timeout/us_abstimeout/us_untimeout: ns_timeout/ns_abstimeout/ns_untimeout 에 timeval_to_ns_time(tvp) 를 넘기는 꼴.

방법: 07 `kern/ns_timer.c` 를 원본 바이트로 작성(Darwin `kern/ns_timer.c` 는 함수 목록·구조만 참고, 본문 미사용). 헤더 kernserv/clock_timer.h·kern/time_stamp.h·mach/time_value.h, callout·clock 함수는 지역 extern 선언. `iter.py s5p219-itN kern/ns_timer.c ns_timer 160478 160adc`, relcheck, `__bss` zerofill 검사, 기록(P 예상).

234 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1 17 함수·크기 맞음; 채움 없는 이음매는 3 곳이 아니라 5 곳(0x1604af, 0x1604df, 0x1604fb, 0x160713, 0x160a1f) | 이번 세션의 이음매 바이트 표(ns_timeout·ns_abstimeout 끝도 `89 ec 5d c3`) | ✅ → 사실 0 정정 |
| 2 데이터: ns_per_tick common, 0x1df21c(__data)·0x1e5e44(__bss) 는 각각 microtime·sched_usec_elapsed 만 참조 | 원본 todis 참조 주소 | ✅ |
| 3 sched_usec_elapsed 는 몫을 입력에 되쓰지 않음(하위 몫만 반환), 나머지/1000 은 부호 있는 idiv | ustimer.dis·todis 0x160764–0x16078b, 0x1605d1 | ✅ (작업본의 되쓰기 저장이 사라지는지는 빌드로 확인) |
| 4 함수별 동작·상수·Calendar 0/System 1·PZERO−1(24)·부호 | 원본 todis; clock_timer.h:28·param.h:89 열람 | ✅ |

### 234.1 결과 — P
- 07 `kern/ns_timer.c`(scratchpad 작업본). it1(`s5p219-it1`): ns_timeout 64/48, sched_usec_elapsed 128/132. 변형 `s5p219-v1` t1(`time += clock_value(System)` — 원본은 time 을 호출 전에 읽음) 차이 0, t2·t3 불일치; `s5p219-v2` u1(값으로 받아 하위 몫만 돌려주는 나눗셈 도우미) 차이 0(codex 3 의 지적과 같은 꼴).
- it2: get_calendar_time_value 만 프레임 4 B 차이(ns_time_to_timeval 인라인 꼴). 변형 `s5p219-v3` g1(지역 now 를 제자리 나눗셈) 차이 0, g3(인라인) 8 B 차이 → g1 적용(`plan 234.1`).
- it3(`s5p219-it3`): `__text`·`__data`(microtime 정적, 0x1df21c) 일치, relcheck 0; `__bss` 는 zerofill 검사(`s5p219-zerofill-check-ns_timer-20261003.json`) 참조 8 개·Delta 0x1e57d8 하나·후보 [0x1e5e44, 0x1e5e4c)·음성 검사 검출 → reference-inferred. 알려진 배치 `zerofill-known-s5p219-20261003.json`(31 건).
- 기록 도구: 이 파일은 참조 본문이 없으므로 기준을 `authored:` 로 기록하도록 scratchpad `record_partial.py` 에 kind `authored` 추가(PROVENANCE 출처 `authored`, diff 는 /dev/null 대비). 기록: objects_partial 25→26, functions +17, PROVENANCE +1.

## 235. S5-P220 세부 계획 — `kern/mach_clock.c` (Mach4 + 4.2 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis `machclock.dis` 0x15bc30–0x15c100; 진단 `s5p220-d1` = Mach4 원문, timer_elt 의 chain 없음으로 실패):
0. 객체 [0x15bc30, 0x15c100) 1232 B: clock_interrupt 376, init_timeout_element 28, set_timeout 104, reset_timeout 116, init_timeout 20, host_get_time 56, host_set_time 108, host_adjust_time 204, mach_clock_bootstrap 136(0x15c024–0x15c0ab), 기호 없는 정적 함수 0x15c0ac(84, 채움 포함) — 91 절(0x15c0ac 와 mach_clock_bootstrap 사이 `90`, 끝 뒤 `00`). 앞은 확정 lock 끝.
1. `__data` [0x1dee30, 0x1dee68): hz=100, tick=10000, time{0,0}, timedelta=0, tickdelta=0, tickadj=5, bigadj=1000000, mtime=0, 문자열 "mappable_time_init"(0x1dee54, Mach4 는 "mapable") — Mach4 선언 순서에서 elapsed_ticks 만 빠짐(원본 `_elapsed_ticks` 없음; `_timer_lock`·`_timer_head` 도 없음 → timer_lock 은 정적, `__bss` 0x1e5ba8). 다음 0x1dee68 `_avenrun` 은 mach_factor.
2. clock_interrupt: Mach4 의 STAT_TIME timer_bump·CPU 상태(processor_ptr[0]->state == PROCESSOR_IDLE)·cpu_ticks 증가와 같음; thread_quantum_update 는 `!(thread->state & TH_IDLE)` 일 때만(0x15bcb6); master_cpu 에서 timer 큐·elapsed_ticks·softclock 없이 time-of-day 만: timedelta 가 있으면 delta 계산과 함께 `time_of_boot −= / += tickdelta * 1000`(64 비트, 0x15bd02–0x15bd4c; `_time_of_boot` common 0x1f63e0), time_value_add_usec, update_mapped_time.
3. init_timeout_element(telt)(새 전역): `telt->call.func = 정적 처리 함수; telt->call.spec_proto = telt; telt->call.status = 0`(+8·+0x10·+0x1c, 07 `kern/thread_call_private.h:49` 의 배치). 정적 처리 함수(0x15c0ac): splsched·timer_lock, fcn/param 읽기, set = TELT_UNSET, unlock·splx, `(*fcn)(param)`.
4. set_timeout(telt, interval): splsched·lock, `calloutEntryDispatchDelayed(&telt->call, calloutDeadlineFromInterval(ticks_to_ns_time(interval)))`, set = TELT_SET, unlock·splx. reset_timeout: set 이면 `calloutEntryRemove(&telt->call)`, TELT_UNSET, TRUE; 아니면 FALSE(Mach4 의 두 return 꼴). init_timeout: `simple_lock_init(&timer_lock)` 만.
5. host_get_time: Mach4 와 같음. host_set_time: splhigh, time = new_time, update_mapped_time, `set_calendar_time_value(&time)`(resettodr 대신), splx. host_adjust_time: Mach4 와 같되 splclock 대신 splhigh(0x15bf96).
6. mach_clock_bootstrap(새 전역, Mach4 mapable_time_init 꼴): kmem_alloc_wired(kernel_map, &mtime, page_size) 실패 시 panic("mappable_time_init"), bzero(mtime, page_size), `s = splhigh(); get_calendar_time_value(&time); update_mapped_time(&time); splx(s)`.

방법: 07 `kern/mach_clock.c` = Mach4 `kernel/kern/mach_clock.c`(고지 보존) + 2–6(`plan 235`), softclock·timeout 호환부·timeopen/timeclose·elapsed_ticks·timer_head 제거. `iter.py s5p220-itN kern/mach_clock.c mach_clock 15bc30 15c100`, relcheck, zerofill(timer_lock), 기록(P 예상).

## 236. S5-P221 세부 계획 — `rpc/pmap_krmt.c` (NeXTMach, pmap_krmtcall 제거, 코딩 전, 2026-10-03)

사실(진단 `s5p221-d1` = NeXTMach `rpc/pmap_krmt.c`, 07 아님):
1. 객체 [0x136114, 0x136250) 316 B: `_xdr_rmtcall_args` 224, `_xdr_rmtcallres` 92(끝 채움 포함); 앞 0x136113 `00` 한 바이트(0x136111–12 는 pmap_prot 의 `pop ebp; ret`; codex 정정), 뒤 0x136250 은 확정 rpc_callmsg. 진단 크기 224/224, 91/92(채움).
2. NeXTMach 의 `pmap_krmtcall` 은 원본 기호에 없음(symbols.tsv 에 `_pmap_krmtcall` 없음, 07 의 호출처 grep 0 건) → `#ifdef notdef` 로 뺌(작성 표시).

방법: NeXTMach 원문 + 2. `iter.py s5p221-itN bsd/rpc/pmap_krmt.c pmap_krmt 136114 136250`, relcheck, 기록.

235 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 범위·크기·0x15c0ac 콜백(정적·한 객체는 추론) | python 크기, 0x15c0ab nop·0x15c0ff 00 | ✅ |
| 1 `__data` 순서 맞음, 단 문자열은 **mappable**_time_init | 이번 세션 덤프 0x1dee54 `6d 61 70 70 61 62 6c 65 …` | ✅ 내 오기 → 사실 1·6 정정, 작업본 문자열 고침 |
| 2 clock_interrupt(idle 검사·thread_quantum_update 조건·time_of_boot 부호·한 번 정규화) | machclock.dis 0x15bc3f–0x15bd9e | ✅ |
| 3 init_timeout_element 오프셋·콜백 | 0x15bdae–0x15bdb8·0x15c0ac–0x15c0fe | ✅ |
| 4 set/reset/init_timeout | 0x15bdc4–0x15bea0 | ✅ |
| 5 host_get/set/adjust_time(splhigh, set_calendar_time_value) | 0x15beb4–0x15c022 | ✅ |
| 6 mach_clock_bootstrap | 0x15c024–0x15c0aa | ✅ (문자열만 정정) |
| 7 basepri 미사용·assert 없음·timeout/untimeout 은 kern_clock(0x103658) 에 있음 | 작업본도 그렇게 씀; timeout 은 plan 233 객체 | ✅ (설명 보충) |

### 235.1 결과 — P
- 07 `kern/mach_clock.c`(scratchpad 작업본 + 문자열 정정). `s5p220-it1` 첫 빌드에서 `__text`·`__data` 일치, relcheck 0. `__bss` timer_lock: zerofill(`s5p220-zerofill-check-mach_clock-20261003.json`) 참조 11 개·Delta 0x1e56a0 하나·후보 [0x1e5ba8, 0x1e5bac)·음성 검사 검출 → reference-inferred. 알려진 배치 `zerofill-known-s5p220-20261003.json`(32 건).
- 기록 도구 `record_partial.py` 에 kind `mach4`(Mach4 커밋 69fa778…) 추가; 라이선스 칸은 CMU-UTAH-MACH4.txt. 기록: objects_partial 26→27, functions +10, PROVENANCE +1.

## 237. S5-P222 세부 계획 — uname 객체 `bsd/kern/kern_uname.c` (전면 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis 0x10b464–0x10b600):
1. 객체 [0x10b464, 0x10b600) 412 B, `_uname` 하나. 앞 0x10b463 `00`(확정 kern_time 끝), 뒤는 채움 없이 확정 kern_xxx(0x10b600) — 정렬이 맞아 경계는 바이트로 증명 불가(앞의 0x00 채움으로 객체 시작은 확실). 파일 이름은 정할 근거가 없어 `kern_uname.c` 로 둠(기록). 참조 소스에 커널 uname 시스템 호출 없음(Darwin Libc gen.subproj/uname.c 는 사용자 수준 함수) → 전면 작성.
2. `__data` 문자열(0x1dab89–): "NEXTSTEP", "%d", "%d", "386 AT", "486 AT", "486SX AT", "586 AT", "586SX AT", "Unknown AT".
3. 동작: uap = u.u_ap(첫 인자 = utsname 포인터); 지역 buf(−0x20, 32 B)·len(−0x24). `u.u_error = copyoutstr("NEXTSTEP", name+0x00, 32, &len)`, 0 이 아니면 반환; hostname → +0x20; `sprintf(buf, "%d", 0)` → +0x40; `sprintf(buf, "%d", 4)` → +0x60; `machine_slot[0].cpu_subtype`(0x1e8e08) 로 3/4/0x84/5/0x85(SDK mach/machine.h:265–269 CPU_SUBTYPE_386 … 586SX) 별 문자열, 그 밖 "Unknown AT" → +0x80. 앞의 네 단계 뒤 u_error 검사(마지막 결과는 저장만, 0x10b5f3).
4. struct utsname 정의는 SDK 사본에 없음 → 파일 안에 다섯 32 B 필드로 정의(작성).

방법: 위대로 작성(scratchpad `uname_wip.c`). `iter.py s5p222-itN bsd/kern/kern_uname.c kern_uname 10b464 10b600`, relcheck, 기록(출처 authored).

236 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1·3 구간·크기 | python, symbols.tsv | ✅ |
| 2 앞 채움은 0x136113 하나뿐(0x136111–12 는 `5d c3`) | 이번 세션 바이트 0x136110 `ec 5d c3 00` | ✅ 내 오기 → 사실 1 정정 |
| 4 `_pmap_krmtcall` 기호 없음; 직접 호출 대상 검색은 기호 없는 구현의 부재까지 증명하지 못함; 07 grep 은 원본 증거가 아님 | symbols.tsv grep 0 건 | ⚖️ 사실 채택, 문구는 "원본 기호에 없음" 으로 한정 |
| 5 XDR 두 함수는 NeXTMach 와 일치, pmap_rmt.c 에도 같은 본문 → 파일 판정 불가 | pmap_rmt.c 93–137 열람: 같은 함수 + 사용자 수준 broadcast 함수들 | ✅ (커널판 pmap_krmt.c 선택은 추론으로 기록) |

### 236.1 결과 — A
- 07 `bsd/rpc/pmap_krmt.c`(pmap_krmtcall 을 `#ifdef notdef`). `s5p221-it1` 첫 빌드 OBJECT_MATCH, relcheck 0. 기록: objects_confirmed +1, functions +2, PROVENANCE +1.

237 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 1 구간·이웃(다음 `_gethostid` 0x10b600); 커널 uname 은 참조에 없으나 Darwin Libc 에 사용자 수준 uname 있음 | symbols.tsv; `01_resources/upstream/darwin01/Libc/gen.subproj/uname.c` 존재 확인 | ✅ → 문구 한정 |
| 2 문자열 주소 | 이번 세션 덤프 | ✅ |
| 3 copyoutstr 다섯 호출·switch·u_error; 마지막 결과는 검사 없음 | todis 0x10b483–0x10b5f3 | ✅ → 사실 3 정정(작업본은 이미 그 꼴) |
| 4 스택 배치 맞음, struct utsname 형은 구현 선택 | 계획 4 에 "작성" 으로 적음 | ✅ |

### 237.1 결과 — A
- 07 `bsd/kern/kern_uname.c`(scratchpad 작업본). it1 컴파일 실패(hostname 선언 없음) → 함수 안 `extern char hostname[];`. it2(`s5p222-it2`) OBJECT_MATCH(`__data` 포함), relcheck 0.
- 기록 도구 `record_object.py` 에도 kind `authored`·`mach4` 추가. 기록: objects_confirmed +1, functions +1(authored), PROVENANCE +1(출처 authored).

## 238. S5-P223 세부 계획 — `kern/power.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis `power.dis` 0x160adc–0x160e84):
0. 객체 [0x160adc, 0x160e84) 936 B: power_callout 248, power_init 292, kern_PMSetPowerState 44, kern_PMGetPowerEvent 232, kern_PMGetPowerStatus 40, kern_PMSetPowerManagement 44, kern_PMRestoreDefaults 36(채움 포함). 앞 0x160ad9–db `00`(ns_timer 끝), 뒤 0x160e81–83 `00`. (61 절의 이전 보류 사유 "옛 callout API" 는 plan 234·235 의 callout 선언으로 해소.)
1. 데이터: `__data` 0x1df224(4 B, 0 으로 초기화된 정적 "초기화됨" 표시, power_init 만 참조) — ns_timer 의 `__data`(0x1df21c–0x1df223) 바로 뒤; `__bss` 0x1e5e4c(4 B, 정적 시스템 상태, 세 switch 에서 씀).
2. 정적 전력 사건 처리(인라인되어 기호 없음): `PMGetPowerEvent(&event)` 가 0 이면 event 별로 — 1·9: 상태 = PM_STANDBY(1), `PMSetPowerState(PM_SYSTEM_DEVICE, 1)`; 2·8·10: 상태 = PM_SUSPENDED(2)·설정, 상태 = PM_READY(0)·설정; 3·4·11: 상태가 READY 가 아니면 READY·설정, 이어서 7 과 함께 `PMUpdateClock()`; 5·6: 없음(점프 표 0x160b10·0x160c20·0x160d70, 07 kern/power.h:87–97 의 값); 사건 포인터가 있으면 저장; 반환값 = PMGetPowerEvent 결과. PM_SYSTEM_DEVICE 는 인자 1(`push 1`).
3. power_callout(arg, entry): 위 처리(포인터 0), entry 가 0 이면 `calloutEntryAllocate(power_callout, 0)`, `calloutEntryDispatchDelayed(entry, calloutDeadlineFromInterval(1010000000))`(0x3c336080).
4. power_init: 정적 초기화 표시가 0 이면 `PMConnect()` 가 0 일 때 power_callout(0, 0)(인라인), 상태 = READY, 표시 = 1.
5. kern_PM*: `host != &realhost` 이면 KERN_INVALID_HOST(0x16), 아니면 각각 PMSetPowerState(device, state)·위 처리(event 포인터)·PMGetPowerStatus·PMSetPowerManagement(device, state)·PMRestoreDefaults().

방법: 07 `kern/power.c` 를 원본 바이트로 작성(07 `kern/power.h`(Darwin 사본, 기록됨) 의 형·상수 사용; Darwin power.c 본문은 쓰지 않음). `iter.py s5p223-itN kern/power.c power 160adc 160e84`, relcheck, `__bss` zerofill, 기록(P 예상, 출처 authored).

238 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 크기·채움 | python 936, 바이트 | ✅ |
| 1 0x1df224(__data, power_init 만)·0x1e5e4c(__bss, 세 switch·power_init) | power.dis 참조 주소 | ✅ |
| 2 사건→동작 매핑, `push 1`, 사건 저장은 kern_PMGetPowerEvent 에서만 | 점프 표 세 개(이번 세션 python 으로 읽음), power.h:87–97 | ✅ |
| 3 callout·1010000000 | power.dis 0x160ba4–0x160bcc | ✅ |
| 4 PMConnect 실패여도 상태·표시를 설정 | power.dis 0x160bef → 0x160cdd | ✅ (작업본 그대로) |
| 5 kern_PM* | power.dis | ✅ |

### 238.1 결과 — P
- 07 `kern/power.c`(scratchpad 작업본). `s5p223-it1` 첫 빌드에서 `__text`·`__data` 일치, relcheck 0. `__bss` system_state: zerofill(`s5p223-zerofill-check-power-20261003.json`) 참조 16 개·Delta 0x1e5aa0 하나·후보 [0x1e5e4c, 0x1e5e50)·음성 검사 검출 → reference-inferred. 알려진 배치 `zerofill-known-s5p223-20261003.json`(33 건).
- 기록: objects_partial +1, functions +7(authored), PROVENANCE +1.

## 239. S5-P224 세부 계획 — `kern/miniMon.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis `minimon.dis` 0x1600cc–0x160478):
0. 객체 [0x1600cc, 0x160478) 940 B(앞 0x1600ca–cb `00`, 뒤 0x160476–77 `00`). 함수 순서: 정적 명령 해석(0x1600cc, 명령 비교 인라인), miniMonInit(0x1601b8, 24), miniMonLoop(0x1601d0, 336; 줄 입력 인라인), 정적 continue(0x160320, `return 0`), 정적 help(0x16032c), safe_prf(0x1603b4, 92), 정적 reset(0x160410, kdp_reset 후 1), 정적 gdb(0x160424, `_kernDebuggerLock` 을 xchg 로 잡으면 miniMonGdb(line) 후 풀고 그 값, 못 잡으면 두 메시지 후 1).
1. `__data` [0x1defb8, 0x1df21c) 612 B: miniMonCommands 표(12 B 항목 7 개 + 끝 0) = continue/continue 함수, reboot/miniMonReboot, halt/miniMonHalt, gdb/정적 gdb, reset/정적 reset, help/정적 help(설명 0), ?/정적 help(설명 0); 이어서 표 초기화 문자열이 역순으로("?", "help", "Reset debugger state", "reset", … "continue"), 그 뒤 함수에서 쓰는 문자열이 쓰인 순서로("Ambiguous command - type '?' for help\n" 두 번, "Invalid command …", "System Panic:\n", "%s\n", "(Type 'r' to reboot or 'm' for monitor)", "\nRebooting...", "", "\n", "NEXTSTEP Mini-monitor\n", "%s> ", "Mini-monitor commands:\n", "?,help - Print this message\n", "%s - %s\n" 두 번, "Couldn't acquire debugger lock:\n", "exit from monitor and try again.\n"). Darwin 표의 forcegdb 없음.
2. `__bss`: 정적 줄 버퍼 0x1e5dc4(128 B), safe_prf 의 정적 버퍼 0x1e5bc4(512 B). common: `_kernDebuggerLock`(0x1f6524), `miniMonState`(0x1f6528).
3. miniMonLoop(prompt, panic, state): miniMonState = state; panic 이면 "System Panic:\n", `safe_prf("%s\n", panicstr)`, "(Type 'r' …)" 를 찍고 miniMonTryGetchar() 를 돌며 'r' 이면 "\nRebooting..." 후 `miniMonReboot("")`, 'm' 이면 "\n" 후 루프 탈출; 이어서 "NEXTSTEP Mini-monitor\n", 반복: `safe_prf("%s> ", prompt)`, 줄 입력(최대 127 자; '\r' 은 '\n' 출력 후, '\n' 에서 끝; '\b' 는 ' ' 뒤 줄 시작이 아니면 '\b' 와 한 칸 뒤로; ^U 는 처음으로 돌아가 '\n'; 넘치면 '\b',' ','\b'), 해석 결과가 0 이면 반환.
4. safe_prf(fmt, …): 정적 버퍼에 `prf(fmt, &args, 8, &p)`(stdarg; 8 = 버퍼 출력 플래그) 후 NUL, 문자마다 miniMonPutchar.
5. 명령 해석: 두 표(miniMonCommands, miniMonMDCommands)에서 앞부분 일치(공백·탭·\n·\0 에서 끝) 를 찾고, 둘 이상이면 "Ambiguous …" 후 TRUE, 하나면 그 함수(line), 없으면 "Invalid …" 후 TRUE. help: "Mini-monitor commands:\n", "?,help - …", 두 표의 설명 있는 항목을 "%s - %s\n".

방법: 07 `kern/miniMon.c` 를 원본 바이트로 작성(07 kern/miniMon.h·miniMonPrivate.h(Darwin 사본, 기록됨) 의 형 사용; Darwin miniMon.c 본문은 쓰지 않음; 문자열은 원본 바이트에서). `iter.py s5p224-itN kern/miniMon.c miniMon 1600cc 160478`, relcheck, zerofill(두 정적 버퍼), 기록(P 예상, authored).

239 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 miniMonLoop 은 336 B, safe_prf 는 92 B(내 숫자는 기호 간격이라 뒤 정적 함수 포함) | python: 0x160320−0x1601d0 = 336, 0x160410−0x1603b4 = 92 | ✅ 내 오기 → 사실 0 정정 |
| 1 명령 표·문자열 목록과 순서 | 이번 세션 덤프와 같음 | ✅ |
| 2 버퍼 128·512 B 는 배치에 맞으나 선언 크기는 바이트로 증명 불가 | zerofill 검사로 배치 확인 예정 | ⚖️ |
| 3 ^U 는 남은 길이를 되돌리지 않음 | minimon.dis 0x1602c4–0x1602d0 | ✅ (작업본 그 꼴) |
| 4 safe_prf | 0x1603c1–0x160408 | ✅ |
| 5 명령 이름을 다 읽으면 뒤 문자는 무시(`helpXYZ` 도 help) | 0x1600f8–0x160118 | ✅ (작업본 mm_match 그 꼴) |

### 239.1 결과 — P
- 07 `kern/miniMon.c`. it1 컴파일 실패(panicstr 재선언) → 제거, kern/lock.h import. it2(`s5p224-it2`): `__data` 일치, miniMonLoop 332/336 — 원본은 두 번째 safe_prf 뒤에서 인자를 걷어 냄(0x160201 `add esp,0xc`). 변형 `s5p224-v1` p1(빈 do-while(0))·p2(세 번째 출력을 do-while(0) 안에) 차이 0, p3(빈 블록) 불일치 → p1 적용(원래 구문은 모름, 표시). it3(`s5p224-it3`) `__text`·`__data` 일치, relcheck 0; `__bss` 두 버퍼 zerofill(`s5p224-zerofill-check-miniMon-20261003.json`) 참조 6 개·Delta 하나·후보 [0x1e5bc4, 0x1e5e44) 640 B → reference-inferred. 알려진 배치 34 건.
- 기록: objects_partial +1, functions +8(authored; 정적 5 개 포함), PROVENANCE +1.

## 240. S5-P225 세부 계획 — i386 시스템 시계 `machdep/i386/machine_clock.c` (전면 작성, D024, 코딩 전, 2026-10-03)

사실(원본 todis `mclk.dis` 0x187844–0x187fec):
0. 객체 [0x187844, 0x187fec) 1960 B(앞 0x187842–43 `00`, 뒤 0x187fe9–eb `00`, 다음 확정 dkbad). 함수 순서: system_timer_dispatch 216, hardclock_init 20, statclock_init(빈 함수, 8 B 뒤 nop), 정적 0x187938(기계 hardclock, 70), us_spin_calibrate 192, clock_timer_init 344, clock_value 60, set_clock 88, clock_attributes 44, timer_attributes 28, set_timer_expire_func 24, set_timer 188(0x187c8c–0x187d44), 정적 0x187d48(시스템 시각 읽기, 332), event_get 344(정적 시각 읽기가 인라인된 꼴, 하위 32 비트 반환).
1. `__bss`: 0x1e75c4 = 07 `machdep/i386/io_inline.h:110` outb 의 `static int xxx`(`lock incl`), 0x1e75d0 시스템 시각(ns, 8 B, 틱마다 +10000000), 0x1e75d8·0x1e75da 카운터 마지막 값·재적재 값(u16), 0x1e75dc 타이머 기한(8 B), 0x1e75e4 만료 함수, 0x1e75e8 hardclock 사용 표시.
2. `__TEXT,__const` 0x1d14a0: 포트 표 {0x40, 0x41, 0x42}, 시계 속성 두 개(0x1d14ac = System {최대, 10000000}, 0x1d14bc = Calendar {최대, 1000000000}), 타이머 속성(0x1d14cc {최대, 10000000}). `__data`: us_spin_us_const = 0x2000(0x1e17f8), 문자열 "clock_timer_constant 1/2/3".
3. system_timer_dispatch(irq, state, ipl): 시각 += 10000000, 마지막 값 = 재적재 값; state 가 있으면 pc = state+0x38, ps = (eflags+0x42 의 비트 1(VM) 이면 3, 아니면 cs & 3), 없으면 0; 지역 {pc, ps, ipl}; 표시가 있으면 정적 hardclock(&지역); 만료 함수가 있고 기한이 0 이 아니며 기한 ≤ 시각이면 기한 = 0 후 함수(0, 0, 0).
4. 정적 hardclock(f): `clock_interrupt(tick, f->ps == 3, f->ipl == 0)`, `hardclock(f->pc, (f->ipl << 8) | f->ps)`. hardclock_init: 표시 = 1. statclock_init: 없음.
5. us_spin_calibrate: outb(0x43, 0x30), splusclock, outb(포트, 0xff) 두 번, us_spin(1), outb(0x43, 0), inb 두 번으로 카운터, splx; 경과 = 0xffff − 카운터; us_spin_us_const = (1193167 / 경과) × us_spin_us_const(32 비트 곱) / 1000000(첫 나눗셈 부호 있음, 둘째 부호 없음).
6. clock_timer_init: intr_register_irq(0, system_timer_dispatch, 0, 6), intr_enable_irq(0); timeval(usec = 0) 을 readtodc 로 읽어 time_of_boot = timeval_to_ns_time; splusclock; outb(0x43, 0x34); 타이머 해상도(64 비트, `__udivdi3`)를 1 이하가 될 때까지 10 으로 나눈 횟수 n(나눈 뒤 값이 0 이면 panic "…1"), n = 9 − n(> 5 면 panic "…2"), 1193167 을 n 번 10 으로 나눔, 0xffff 초과면 panic "…3"; 마지막·재적재 값 = 그 값, outb 하위·상위; splx.
7. clock_value(which): now = 정적 시각 읽기; Calendar 면 + time_of_boot, System 이면 그대로, 그 밖 0. set_clock(which, ns): Calendar 면 splusclock 아래 time_of_boot = ns − 시각, splx, ns_time_to_timeval 후 writetodc. clock_attributes: System → 0x1d14ac, Calendar → 0x1d14bc, 그 밖 0. timer_attributes: 0 → 0x1d14cc. set_timer_expire_func(which, f): 아직 없으면 등록. set_timer(which, ns): 0 이면 기한 = ((ns + 9999999) / 10000000) × 10000000 + 시각(splusclock 아래).
8. 정적 시각 읽기: splusclock; now = 시각, last = 마지막 값; outb(0x43, 0); 카운터 읽기 → 마지막 값; splx; 카운터 > last 면 now += 10000000; now += (재적재 − 카운터) × 1000000000 / 1193167. event_get: 같은 계산의 하위 32 비트.

방법: 07 `machdep/i386/machine_clock.c` 를 원본 바이트로 작성(Darwin 같은 이름 파일은 판이 달라 구조 참고만; 07 io_inline.h·kernserv/clock_timer.h 사용). `iter.py s5p225-itN machdep/i386/machine_clock.c machine_clock 187844 187fec`, relcheck, zerofill, 기록(P 예상, authored).

240 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 크기 맞음; 다음 기호는 `_isbad`(dkbad 객체) | symbols.tsv | ✅ (표현 보충) |
| 1 `__bss` 항목·`time_of_boot` 은 `__common` | mclk.dis 참조 | ✅ |
| 2 `__const`(포트 32 비트 셋, 속성 세 개)·`__data` | 이번 세션 덤프 | ✅ |
| 3·4 dispatch·hardclock 감싸개 | mclk.dis | ✅ |
| 5 곱은 32 비트로 잘림 | 0x187a19 `imul` | ✅ → 문구 정정(작업본은 32 비트 곱) |
| 6 panic 1 은 나눈 뒤 값이 0 인지 검사 | 0x187ae7–0x187afd | ✅ → 문구 정정(작업본 `res == 0`) |
| 7·8 API·시각 읽기·event_get | mclk.dis | ✅ |

### 240.1 it 결과 — 보류(미기록)
- it1 컴파일 실패(clock_types_t·NSEC_PER_TICK·`func` 이름 충돌) → int·MC_NSEC_PER_TICK·매개변수 이름 바꿈. it2: 1651/1960 — 원본은 07 `machdep/i386/timer_inline.h`(Darwin 사본, 기록됨)의 timer_set_ctl·timer_latch·timer_read(union 으로 두 바이트)·timer_write 와 그 안의 포트 표 `_timer_cnt_port_`(`__const` 0x1d14a0) 를 씀 → 다시 작성(it3, 1949). 정적 시각 읽기: 64 비트 변수에 곱하는 꼴(`delta *= 1000000000`) 과 선언 순서(delta, now) 로 맞춤(변형 `s5p225-v1`·`v2`).
- clock_value·clock_attributes: switch 안 case 본문 순서 System → Calendar → default(it5). system_timer_dispatch: VM 검사 방향과 ipl 을 먼저 지역 변수에 복사(변형 `s5p225-v3` d1·`v4` d5). set_timer: `system_time + t`(변형 `s5p225-v5` s1). clock_timer_init: kernserv/ns_timer.h 원형(timeval_to_ns_time 의 64 비트 반환) 필요(it8).
- 남은 차이(it8 `s5p225-it8`, 1957/1960): clock_timer_init 의 reload 저장(원본 `mov eax,esi; mov [reload],ax`; 변형 `v6`–`v10` 의 18 가지 꼴 모두 불일치), us_spin_calibrate 의 지역 배치(원본은 카운터와 0xffff−카운터를 같은 스택 슬롯에 저장, union 은 저장 안 함). 나머지 12 함수는 꼴 일치(data 배치 미확정 때문에 일부 MATCH_UNVERIFIED).
- 작업본은 scratchpad `machine_clock_wip_it8.c` 에 두고 07 에서는 뺌(출처 행 없는 07 파일을 남기지 않음). 나중에 다시 시도.

## 241. S5-P226 세부 계획 — i386 `machdep/i386/machdep.c` (작성 + NeXTMach addupc, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis `i386machdep.dis` 0x18cc28–0x18d208):
0. 객체 [0x18cc28, 0x18d208) 1504 B(앞 0x18cc25–27 `00`, 뒤 0x18d206–07 `00`; 함수 사이 nop): halt_thread, reboot_mach, led_msg, mini_mon, nmi_prf, addupc, halt_cpu, 정적 prettyPrint(0x18cf54), md_prepare_for_shutdown, md_shutdown_devices, md_do_shutdown, machine_table_setokay(−1), machine_table(0), us_spin(0x18d1e4 — 바로 앞 nop 채움으로 같은 객체).
1. `__data` [0x1e227c, 0x1e2422): mini_mon 의 재시작 안내문, "restart", "panic", "" 두 개(하나는 죽은 가지의 문자열), 언어별 안내 6 개(영·불·독·서·이·스웨덴), "Hltd", "Please wait until it's safe\nto turn off the computer.\n". `__bss` 0x1e7730 = io_inline outb 의 정적 카운터. common: reboot_how·nmi_stay·prettyShutdown(short)·rebootflag 등.
2. halt_thread: `boot(RB_BOOT, reboot_how)`. reboot_mach(how): kernel_task 가 있으면 reboot_how = how, `calloutDispatch(halt_thread, 0)`(Darwin 의 thread_call_func 대신), 없으면 `boot(RB_BOOT, how | RB_NOSYNC)`. led_msg: `outb(0xcaf − i, msg[i])` 4 번.
3. mini_mon(prompt, title, locr0): s = splhigh(); restart/panic = 문자열 비교(인라인 repe cmpsb); panic 이면 locr0 = 현재 ebp; saved = 1; restart 면 `DoAlert(title, 안내문)`, 아니면 `DoAlert(title, "")`(Darwin 의 DoSafeAlert 대신); panic 이면 kmdumplog(); restart 면 kmtrygetc() 루프('r' → reboot_mach(RB_AUTOBOOT), 'h' → reboot_mach(RB_HALT), −1 이 아니면 끝) 후 out 으로; 아니면 `do miniMonLoop(prompt, panic, locr0); while (panic)`; out: saved 이고 nmi_stay 가 0 이면 DoRestore(), nmi_stay = 0, splx(s).
4. nmi_prf: `prf(fmt, &x1, 1, 0)`. addupc(pc, pr, ticks): NeXTMach next/machdep.c:1545 의 계산을 uuprof 목록(pr_next)마다 시도, 범위 안이면 copyin/copyout(또는 pr_scale = 0) 후 끝.
5. halt_cpu(howto): glLanguage(0–5, 그 밖은 영어) 안내를 정적 prettyPrint, kmDisableAnimation, led_msg("Hltd")(인라인), intr_disbl, machine_slot[0].running = FALSE, howto & 0x10000 이면 `PMSetPowerState(PM_SYSTEM_DEVICE, PM_OFF)`, 무한 hlt. prettyPrint: printf 후 prettyShutdown 이면 kmGraphicPanelString.
6. md_prepare_for_shutdown: howto & RB_HALT 면 prettyPrint(kmLocalizeString(…))(인라인). md_shutdown_devices: `_io_setDriverPowerState(PM_OFF)`. md_do_shutdown: rebootflag = 1; RB_HALT 나 paniced == RB_PANIC 이면 halt_cpu(인라인); howto & 0x400000 이면 CMOS 6 번에 0x10, 0x800000 이면 0x20 을 OR(정적 valToCMOS 인라인); intr_disbl; keyboard_reboot; 무한 hlt.
7. us_spin(us): `while (us--) { i = us_spin_us_const; while (i--) ; }`.

방법: 07 `machdep/i386/machdep.c` 를 원본 바이트로 작성(addupc 는 NeXTMach 원문 + 목록 루프, 나머지는 작성; 문자열은 원본 그대로). `iter.py s5p226-itN machdep/i386/machdep.c machdep 18cc28 18d208`, relcheck, zerofill, 기록.

241 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 범위·함수 목록 맞음; us_spin 의 같은 객체 소속은 채움 바이트만으로 증명되지 않음 | 0x18d1e0 `c3 90 90 90` | ⚖️ 사실 ✅, 소속은 추론으로 기록 |
| 1 문자열 순서 맞음; 두 번째 빈 문자열을 가리키는 코드는 없음 — "죽은 가지의 문자열" 은 추론 | 이번 세션 덤프 | ⚖️ 추론으로 기록(작업본의 else 가지로 재현 시도) |
| 2·3 halt_thread·reboot_mach·led_msg·mini_mon(DoAlert, 비교 길이 8·6) | i386machdep.dis | ✅ |
| 4 addupc 오프셋·`and dl,0xfe`·부호 없는 범위 검사 | i386machdep.dis 0x18ce08–0x18ce9c | ✅ |
| 5 halt_cpu·prettyPrint; RB_POWERDOWN 은 SDK reboot.h 에 없고 NeXTMach next/reboot.h:19 | reboot.h 열람(SDK 에 없음) | ✅ (작업본은 파일 안에 정의) |
| 6 md_*: CMOS 처리는 0x400000 이 우선인 배타 분기 | 0x18d144–0x18d1b6 | ✅ (작업본 else if) |
| 7 us_spin | 0x18d1e4–0x18d205 | ✅ |

### 241.1 결과 — P
- 07 `machdep/i386/machdep.c`(새 파일, 같은 이름 07 파일 없음 확인). it1(`s5p226-it1`): `__data` 맞음, addupc 4 B 차이 — 원본은 copyin 실패 때 반복 변수가 아니라 인자 pr(첫 버퍼)의 pr_scale 을 0 으로 함(0x18ce65) → 반복 변수 따로 둠. it2: us_spin 만 다름; 변형 `s5p226-v1`(형·register·volatile·지역)·`v2`(goto·for) 불일치, `v3` x1(부호 없는 us·i 를 `> 0` 로 검사) 차이 0 → 적용(`plan 241.1`). it3(`s5p226-it3`) `__text`·`__data` 일치, relcheck 0; `__bss` io_inline 정적 카운터 셋 zerofill(`s5p226-zerofill-check-machdep-20261003.json`) 참조 8 개·Delta 하나·후보 [0x1e7730, 0x1e773c) → reference-inferred. 알려진 배치 35 건.
- 기록: objects_partial +1, functions +14, PROVENANCE +1(출처 `authored+nextmach` 로 수기 정정 — 도구는 authored 만 적음; 행 수·열 수 확인).


## 242. S5-P227 세부 계획 — `vm/vnode_pager.c` (NeXTMach 원문 + 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis `vnp.dis` 0x17c944–0x17e1e8):
0. 객체 [0x17c944, 0x17e1e8) 6308 B(앞 0x17c942–43 `00`; 뒤는 채움 없이 NXFlush 가 이어짐 — 끝 경계는 추론). 함수: vnode_pager_vput, vnode_pager_vget, vnode_pager_allocpage, vnode_pager_findpage(allocpage 인라인), pagerfile_pager_create, 정적 0x17cd58(pagerfile_bmap; 조회와 deallocpage 인라인), vnode_pager_create, vnode_pager_setup(create 인라인), vnode_pagein, vnode_pageout, vnode_has_page, vnode_pager_file_init, vnode_pager_shutdown, mach_swapon, vswap_allocate, vnode_alloc(vswap_allocate·pagerfile_pager_create 인라인), vnode_pager_truncate, vnode_dealloc(deallocpage·방문 기록·truncate 인라인), vnode_uncache, vnode_pager_init. deallocpage·조회·방문 기록은 기호가 없음(정적, 모두 인라인).
1. 데이터: `__data` [0x1e0e58, 0x1e0f36) 222 B = 정적 int(초기값 0, 방문한 페이저 파일 수) + 문자열 "vnode_pager_allocpage", "vnode_pager_deallocpage", "vnode_pageout: failed!\n", "vnode_has_page: failed lookup", "vnode_has_page called on non-default pager", "vnode_deallocpage: error truncating %s, error = %d\n", "vnode pager structures". `__bss` [0x1e7288, 0x1e7314) 140 B = 정적 pager_files(8), pager_file_count(4), pager_file_list[16](64), 방문 목록 pf_entry[16](64). common: vstruct_lock(0x1f747c), vstruct_zone(0x1f7480).
2. 07 `vm/vnode_pager.h`(Darwin 사본, 이미 기록됨)의 pager_file(pf_hint +0x24, MAXPAGERFILES 16)·pf_entry(index:8, offset:24) 배치가 원본 오프셋과 맞음(allocpage 의 +0x24, 목록 0x40 B).
3. allocpage: 힌트 바이트(pf_hint/8)부터 검색, 끝에 `--pf_pfree; pf_hint = page`(NeXTMach 의 "is full" printf 없음). findpage: preferPf 가 NULL 이면 목록이 비었을 때 KERN_FAILURE(5), 아니면 첫 항목.
4. pagerfile_pager_create: zalloc_noblock·kalloc_noblock(kget/zget 정의 변경), 직접 지도는 index = 0 초기화. bmap(정적): 조회(범위·간접/직접) → B_READ 면 결과, 찾았으면 힌트 < offset 일 때만 deallocpage(인라인) 후 새로 할당, 아니면 KERN_SUCCESS; 지도 확장(간접/직접 네 경우, kalloc_noblock·bzero·kfree)과 findpage. NeXTMach 의 panic 두 개(bad index·0 index) 없음.
5. create: zalloc, `bzero(vs, sizeof *vs)`(0x18), is_device = FALSE, count 1, pager 설정, vs_vp, swapfile FALSE, VN_HOLD(인라인 v_count++), vput. setup: unix_master 는 빈 매크로; `vm_object_cache_object(vm_object_lookup(...), TRUE)`.
6. pagein(m, errorp): swapfile 이면 bmap(B_READ) 실패 시 PAGER_ABSENT(1), 아니면 오프셋·vp 를 pager_file_list 로; ABSENT 가 아니면 `VOP_PAGEIN(vp, m, f_offset)`(v_op+0x74), errorp 가 있으면 `*errorp = vp->vm_info->error`(+0x34); vput; 결과 반환. pmon·event_meter·XPR 없음.
7. pageout: NeXTMach 와 같은 흐름(MACH_NBC 크기 제한 포함), 실패 시 vput 후 PAGER_ERROR(2), `VOP_PAGEOUT(vp, VM_PAGE_TO_PHYS(m), size, f_offset)`(+0x78), 성공 시 clean·pmap_clear_modify, 아니면 printf. pmon 없음.
8. has_page: unix_master/release 없음(빈 매크로), 나머지 NeXTMach. file_init: NeXTMach + `pf_hint = 0`(pf_count 다음). shutdown: NeXTMach(VN_RELE → vn_rele). mach_swapon: suser 뒤 `u.u_error = 0`(0x17d7fc, uthread+0x68), 나머지 NeXTMach. vswap_allocate: 짝수 pass 에서만 ufs_vnodeops 비교(nfs 비교 없음), 쓰지 않는 지역(statfs 0x40 B) 유지.
9. truncate(pf_entry): `hipage > offset` 이거나 swapfs_enabled 이면 끝; lock_write; 새 hipage 찾기; truncpage = hipage+1; lowat 이 0 이 아니고 truncpage > lowat 이고 vnode_size ≥ ptoa(truncpage) 면 vattr_null·va_size·u.u_cred 바꿔 VOP_SETATTR(vp, &vattr, cred)(3 인자), 실패면 printf; lock_done.
10. dealloc: vget 인라인, 방문 수 = 0; swapfile 이면 간접(j 는 부호 없는 비교)/직접 지도마다 deallocpage 후 방문 기록(같은 index 면 offset 최댓값), kfree, pf_count--; 아니면 VTEXT 해제, pager = null, vn_rele(VAGE 없음); 방문 목록마다 truncate; zfree. uncache(void): vm_info 와 pager 가 있을 때만, NeXTMach 의 잠금 해제/복구 + mfs_uncache + vm_object_uncache. init: zinit(0x18, 10000×0x18, page_size, FALSE, 이름), simple_lock_init, queue_init(pager_file_count = 1 없음).

방법: NeXTMach `vm/vnode_pager.c` 를 바탕으로 헤더를 07 관례(mach/mach_types.h·mach/boolean.h 등, pmon·event_meter·mach_swapon.h 제거 — MS_PREFER 는 파일 안에 정의)로 바꾸고, 위 차이는 원본 바이트를 근거로 함수 단위 작성(`plan 242` 표시, Darwin 은 구조만 참고). scratchpad 작업본을 `wipbuild.py s5p227-itN vm/vnode_pager.c vnode_pager 17c944 17e1e8 mk-108.1/vm/vnode_pager.c WIP` 로 빌드(07 미변경), 맞으면 07 에 넣고 iter·relcheck·zerofill·기록.

242 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 4 의 "bad index"·"0 index" panic 은 NeXTMach 가 아니라 Darwin(vnode_pager.c:418·431) 것; 원본 bmap 에 없음 | NeXTMach grep(panic 은 248·320·853·863 뿐), Darwin grep 418·431 | ✅ 내 오기 → 사실 4 정정: 두 panic 은 Darwin 에만 있고 원본에 없음 |
| bmap 안 deallocpage 범위 panic 은 남아 있음 | vnp.dis 0x17ce33 `push 0x1e0e72`(“vnode_pager_deallocpage”) | ✅ (사실 10 의 인라인 deallocpage 와 같은 내용, 보충) |
| 0·1 정적 함수 구분·`__bss` 끝(방문 목록 길이)은 추론 | 방문 목록 참조는 시작 0x1e72d4 만; 길이는 07 헤더 MAXPAGERFILES 16 에서 | ⚖️ 추론으로 기록 |
| 8 vswap_allocate 의 0x40 B 지역이 statfs 라는 것은 추론 | 0x17d917 `sub esp,0x40`, 타입 정보 없음 | ⚖️ NeXTMach 원문(쓰지 않는 fstat) 에서 온 추론으로 기록 |
| 10 원본 vnode_uncache 는 반환값을 두지 않음(void), 07 헤더는 `int` | vnp.dis 0x17e19a–0x17e1a2 eax 설정 없음; 07 vnode_pager.h:131 `int vnode_uncache();` | ✅ → 계획 보충: 07 vnode_pager.h 의 선언을 NeXTMach vnode_pager.h 처럼 `void` 로 고치고(MODIFICATIONS 기록), 헤더를 포함하는 확정 객체 회귀 검사(호출부는 반환값을 쓰지 않음: nfs_client·ufs_inode·vfs_vnode·ufs_vnodeops grep) |
| 2·3·5·6·7·9 맞음; 8 홀수 pass 는 검사 없이 받음 | vnp.dis 0x17d952–0x17d95d | ✅ (계획 문구와 같음) |

### 242.1 결과 — P
- scratchpad 작업본(NeXTMach 원문 + `plan 242` 표시 작성 줄)을 `wipbuild.py` 로 빌드(07 미변경, 07 vnode_pager.h 는 void 선언 사본으로 덮음). it1(`s5p227-it1`): 19 함수 꼴 일치, truncate 와 dealloc 만 다름. 변형 `s5p227-v1` t1(조건을 뒤집어 lock_done 후 return) 이 truncate 차이 0 → 적용(it2). it2: dealloc 의 visit_file 에서 `max()` 함수 호출 → MAX 매크로(원본은 인라인 비교 후 무조건 저장)(it3) → `__text`·`__data` 차이 0.
- 07 에 넣음: `vm/vnode_pager.c`(새 파일), `vm/vnode_pager.h` 의 vnode_uncache 를 void 로(행 131). it4(`s5p227-it4`) 07 에서 같은 결과, relcheck 0. `__bss` zerofill(`s5p227-zerofill-check-vnode_pager-20261003.json`) 참조 57 개·Delta 하나·후보 [0x1e7288, 0x1e7314) 140 B → reference-inferred; 알려진 배치 36 건(`zerofill-known-s5p227-20261003.json`). 헤더 회귀 `s5p227-r00`–`r05`(kern_mman, vm_pager, vm_init, vm_policy, syscall_subr, ufs_inode) 모두 OBJECT_MATCH.
- 기록: objects_partial +1, functions +20(truncate 인용을 NeXTMach 329–356 으로 수기 정정 — 처음 적은 328–354 는 주석 줄부터였음), PROVENANCE +1(vnode_pager.c) 과 vnode_pager.h 행을 restoration edit 로 정정, MODIFICATIONS +2, 헤더 diff `06_reconstruction/evidence/x86-vnode_pager_h.diff`. 행 수·열 수 확인.

## 243. S5-P228 세부 계획 — `vm/vm_kern.c` (NeXTMach 원문 + Mach4 copyinmap + 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis `vmkern.dis` 0x173ad4–0x174600):
0. 객체 [0x173ad4, 0x174600) 2860 B(앞 0x173ad3 `00` 한 바이트, 앞 객체 vm_init 확정; 뒤는 채움 없이 vm_map_init — 끝 경계 추론). 함수 순서: kmem_alloc 312, kmem_realloc 272, kmem_alloc_wired 300, kmem_alloc_pageable 72, kmem_free 44 + 정적 0x173ebc(페이지 할당 도우미, 기호 없음), kmem_suballoc 208, kmem_init 68, copyinmap 80, copyoutmap 80, kmem_alloc_zone 304, kmem_mb_alloc 632, kmem_alloc_wait 156, kmem_free_wakeup 76.
1. `__data` [0x1e09fc, 0x1e0a73) 119 B: "kmem_realloc" 두 번(합치지 않음), "kmem_suballoc 1/2/3", "You fool!", "mb_map abused even more than usual"(앞은 vm_fault 문자열이 채움 없이 끝남, 뒤는 "maps"). common: kernel_map(0x1e8de8) 참조.
2. kmem_alloc(map, addrp, size): object = vm_object_allocate(size)(반올림 전 size) 후 공통 몸체(정적 kmem_alloc_prim 이 인라인된 꼴, kmem_alloc_wired·kmem_alloc_zone 도 같은 몸체): size 반올림, addr = vm_map_min(map), `r = vm_map_find(map, object != kernel_object ? object : NULL, 0, &addr, size, TRUE) != KERN_SUCCESS`(비교 결과를 대입 — setne), 실패면 kernel_object 가 아닐 때 vm_object_deallocate 후 r(=1) 반환; kernel_object 면 offset = addr, vm_object_reference, vm_map_lock(lock_write + timestamp++), vm_map_delete, vm_map_insert(map, object, offset, addr, addr+size), vm_map_unlock; 도우미(object, offset, size, canblock) 가 실패하면 vm_map_lock·vm_map_delete·vm_map_unlock 후 KERN_RESOURCE_SHORTAGE(6); 성공이면 vm_map_pageable(map, addr, addr+size, FALSE), *addrp = addr, KERN_SUCCESS. wired 는 object = kernel_object·canblock TRUE, zone 은 kernel_object·canblock 인자.
3. 도우미(0x173ebc, 정적, kmem_free 뒤에 정의 — 앞쪽에 선언 필요): size 가 0 이 아니면 반복 — vm_object_lock, `vm_page_alloc(object, offset)`(sequential TRUE) 이 NULL 이면 vm_object_unlock, canblock 이 아니면 FALSE, 아니면 VM_WAIT 후 다시 잠그고 재시도; 얻으면 unlock, vm_page_zero_fill, busy = FALSE, size −= PAGE_SIZE, offset += PAGE_SIZE; 끝에 TRUE.
4. kmem_realloc(map, oldaddr, oldsize, newaddrp, newsize): oldmin/oldmax/oldsize·newsize 반올림, vm_map_find(map, NULL, 0, &newaddr, newsize, TRUE) 결과도 `!= KERN_SUCCESS` 대입꼴(실패면 그 값 1 반환); vm_map_lookup_entry 를 newaddr 로 한 번(결과 안 봄, newentry), oldmin 으로 한 번 — 실패면 panic "kmem_realloc"; object = oldentry->object, vm_object_reference, vm_object_lock, size != oldsize 면 panic "kmem_realloc"(둘째 문자열), size = newsize, unlock; newentry->object = object, offset = 0; vm_map_unlock(lock_done 만 — 대응하는 lock 없음); 도우미(object, oldsize, newsize, TRUE)(결과 무시); vm_map_pageable(map, newaddr, newaddr+newsize, FALSE); *newaddrp; KERN_SUCCESS.
5. kmem_alloc_pageable(map, addrp, size): addr = vm_map_min, kr = vm_map_find(..., round_page(size), TRUE), 성공일 때만 *addrp, kr 반환. kmem_free: NeXTMach(vm_map_remove).
6. kmem_suballoc(parent, min, max, size, pageable): size 반올림, vm_object_reference(vm_submap_object), addr = vm_map_min(parent), vm_map_find(parent, vm_submap_object, 0, &addr, size, TRUE) 실패면 panic "kmem_suballoc 1"; pmap_reference; map = vm_map_create(pmap, addr, addr+size, pageable) NULL 이면 panic "…2"; vm_map_submap 실패면 panic "…3"; *min = addr, *max = addr+size; map 반환(NeXTMach 의 printf 없음).
7. kmem_init: NeXTMach(VM_MIN_KERNEL_ADDRESS 0, MACH_XP 없음). copyinmap·copyoutmap: Mach4 vm/vm_kern.c:1031–1072 원문과 같은 흐름(kernel_pmap 이면 bcopy·0, current_map() == map 이면 copyin/copyout, 아니면 1).
8. kmem_mb_alloc: NeXTMach + 맵 검사가 `map != mb_map && map != swapfs_bit_map && map != swapfs_rem_map` 이면 panic "You fool!"; 페이지 할당은 vm_page_alloc_sequential(object, cur_off, FALSE). kmem_alloc_wait·kmem_free_wakeup: NeXTMach.

방법: NeXTMach `vm/vm_kern.c` 를 바탕으로(머리말·역사 보존), vm_move·copy_user_to_physical_page·MACH_XP 부분과 malloc_debug 를 빼고(원본에 없음), 위 2–6 은 원본 바이트로 작성(`plan 243` 표시, Darwin 은 구조만), copyinmap/copyoutmap 은 Mach4 원문(출처 기록), 헤더는 07 관례. scratchpad 작업본을 `wipbuild.py s5p228-itN vm/vm_kern.c vm_kern 173ad4 174600 vm/vm_kern.c WIP` 로 빌드, 맞으면 07 에 넣고 iter·relcheck·기록.

243 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0 앞 함수 이름은 vm_mem_init(0x173a68) | symbols.tsv; 확정 표 객체 이름은 x86-vm_init(vm_init.c) | ⚖️ 사실 ✅ — 계획의 "vm_init" 은 객체 이름이라 틀리지 않음, 함수는 vm_mem_init 으로 보충 |
| 8 mb_alloc 는 max_protection == 7, protection == 3 을 따로 검사(NeXTMach 는 둘 다 VM_PROT_DEFAULT) | vmkern.dis 0x174371·0x174377; 07 nextdev/mach/vm_prot.h:94·100(DEFAULT = 3, ALL = 7); NeXTMach vm_kern.c:480–481 | ✅ → 사실 8 정정: max_protection == VM_PROT_ALL(작성 줄) |
| 4 realloc 는 옛 페이지 재매핑 호출이 없음(Darwin 은 kmem_remap_pages); oldmin 은 trunc, oldmax·newsize 는 round | vmkern.dis 0x173c15–0x173c37, 0x173ceb–0x173d03 | ✅ 문구 보충(계획의 도우미 호출 내용과 같음) |
| 1·2·3·5·6·7 맞음(2 의 객체 선택은 Darwin 과 반대) | vmkern.dis 0x173b0e–0x173b22 등 이번 세션 열람 | ✅ |

### 243.1 결과 — A
- scratchpad 작업본을 `wipbuild.py` 로 빌드(07 미변경; 작업본에만 있는 kern/thread.h 때문에 동반 소스 vm_user.c·syscall_subr.c 와 함께 스테이징 — wipbuild 에 COMPANION 추가). it1·it2 컴파일 오류(헤더, 07 vm_map.h 의 vme_start/vme_end·vm_map_first_entry 이름) 정리 후 it3: kmem_alloc·wired·zone 만 다름 — 원본은 size 반올림 전에 addr = vm_map_min(map) 을 읽음 → 순서 바꿈(it4) → OBJECT_MATCH.
- 07 에 넣음: `vm/vm_kern.c`(새 파일). copyinmap/copyoutmap 앞에 Mach4 고지 원문과 출처 주석을 넣음(바이트 영향 없음). it5 OBJECT_MATCH·relcheck 0, it6(고지 추가 뒤) OBJECT_MATCH.
- 기록: objects_confirmed +1, functions +14(정적 kmem_alloc_pages 포함; 작성 함수·Mach4 함수 인용은 fn_source 로), PROVENANCE +1, MODIFICATIONS +1. 행 수·열 수 확인.

## 244. S5-P229 세부 계획 — i386 `machdep/i386/io_prim.c` (전면 작성, D024, Darwin 은 구조만, 코딩 전, 2026-10-03)

사실(원본 todis 0x18c9d4–0x18cacc):
0. 객체 [0x18c9dc, 0x18cac8) 236 B(앞 0x18c9da–db `00 00`, 앞 객체 intr(P); 뒤 0x18cac5–c7 `00 00 00`, 다음 객체 kern_machdep(A)). 함수: inb 20, inw 20, inl 20, outb 24, outw 24, outl 24, linw 48, loutw 56(정렬 nop 포함 크기).
1. inb/inw/inl/outb/outw/outl 은 07 `machdep/i386/io_inline.h`(Darwin 사본, 기록됨)의 inline 함수를 static 없이 실체화한 꼴: inl 도 반환을 `and eax,0xffff` 로 자름(헤더의 unsigned short 반환과 같음), outl 은 data 를 `mov ax` 로 16 비트만 읽음(헤더의 unsigned short 인자와 같음). 각 out* 은 자기 static 카운터를 `lock incl`(0x1e7724·0x1e7728·0x1e772c).
2. linw(port, addr, count): `while (count-- > 0) *addr++ = inw(port);`(부호 없는 count — `mov eax,esi; dec esi; test eax,eax`), loutw: `while (count-- > 0) outw(port, *addr++);`(outw 인라인, 카운터 0x1e7728 공유).
3. `__bss` 12 B = 세 카운터(추론 배치 예상). `__data` 없음.

방법: 07 새 파일 `machdep/i386/io_prim.c` 를 작성 — `#define DEFINE_INLINE_FUNCTIONS` 후 `#import <machdep/i386/io_inline.h>`, linw·loutw(D024, `plan 244`; Darwin io_prim.c 는 구조만). iter·relcheck·zerofill·기록(P 예상, authored).

244 codex 검토 판정(코딩 전):
| codex 주장 | 내 검증 | 결과 |
|---|---|---|
| 0–2 맞음; outl 은 ax 만 채우고 `out dx,eax` 로 32 비트 쓰기(위 16 비트 미설정) | todis 0x18ca4f `mov ax,[ebp+0xc]`, 0x18ca53 `out dx,eax` | ✅ (사실 1 의 "16 비트만 읽음" 과 같음, 쓰기 폭 보충) |
| 3 `__bss` 크기·`__data` 없음은 추론 | 참조 셋뿐 | ⚖️ L1·zerofill 로 확인 |

### 244.1 결과 — P
- 07 `machdep/i386/io_prim.c`(새 파일, 작성). it1(`s5p229-it1`): `__text` 일치(표의 끝 0x18cac5 + 뒤 채움 3 B), relcheck 0; `__bss` zerofill(`s5p229-zerofill-check-io_prim-20261003.json`) 참조 4 개·Delta 하나·후보 [0x1e7724, 0x1e7730) → reference-inferred; 알려진 배치 37 건(`zerofill-known-s5p229-20261003.json`).
- 기록: objects_partial +1, functions +8(inb–outl 은 io_inline.h 정의라 fn_source 로 Darwin 사본 줄 인용 — record_partial 이 헤더 정의 함수를 fn_source 로 받게 고침), PROVENANCE +1, MODIFICATIONS +1. 행 수·열 수 확인.

