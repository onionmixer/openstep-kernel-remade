/* GHIDRADEC_FUNCTION index=2350 start=0xf009bf28 */

/* WARNING: Removing unreachable block (ram,0xf009bfb4) */
/* WARNING: Removing unreachable block (ram,0xf009bf84) */
/* WARNING: Removing unreachable block (ram,0xf009bf9c) */
/* WARNING: Removing unreachable block (ram,0xf009bfc0) */
/* WARNING: Removing unreachable block (ram,0xf009bf30) */

undefined8 _switch_context(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)(param_1 + 0x34) = param_2;
  iVar1 = param_1;
  _save_context();
  if (iVar1 == 0) {
    _active_stacks = *(undefined4 *)(param_3 + 0x2c);
    _active_pcb = *(undefined (**) [676])(param_3 + 0x28);
    _active_threads = param_3;
    if (*(int *)(param_3 + 0xc) != *(int *)(param_1 + 0xc)) {
      _pmap_deactivate(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0xc) + 0x24),param_1,0);
      _pmap_activate(*(undefined4 *)(*(int *)(*(int *)(param_3 + 0xc) + 0xc) + 0x24),param_3,0);
    }
    if (param_1 == 0) {
      _panic(aSwitchContextO);
    }
    _load_context(param_3,param_1);
    iVar1 = param_1;
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=2351 start=0xf009bfd0 */

/* WARNING: Removing unreachable block (ram,0xf009bfd4) */

undefined8 _thread_bootstrap_return(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _thread_exception_return();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2352 start=0xf009bfe4 */

/* WARNING: Removing unreachable block (ram,0xf009bffc) */
/* WARNING: Removing unreachable block (ram,0xf009bff4) */

undefined8 _thread_exception_return(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _check_for_ast(*(int *)(_active_threads + 0x28) + 0x234);
  _return_with_state();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2353 start=0xf009c00c */

/* WARNING: Removing unreachable block (ram,0xf009c028) */
/* WARNING: Removing unreachable block (ram,0xf009c020) */

undefined8 _thread_syscall_return(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = *(int *)(_active_threads + 0x28);
  *(undefined4 *)(iVar1 + 0x260) = param_1;
  _check_for_ast(iVar1 + 0x234);
  _return_with_state();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2354 start=0xf009c038 */

undefined8 _thread_set_syscall_return(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)(*(int *)(param_1 + 0x28) + 0x260) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2355 start=0xf009c04c */

/* WARNING: Removing unreachable block (ram,0xf009c08c) */
/* WARNING: Removing unreachable block (ram,0xf009c060) */

undefined8 _start_initial_context(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _pmap_activate(*(undefined4 *)(*(int *)(*(int *)(param_1 + 0xc) + 0xc) + 0x24),param_1,0);
  _active_stacks = *(undefined4 *)(param_1 + 0x2c);
  _active_pcb = *(undefined4 *)(param_1 + 0x28);
  _active_threads = param_1;
  _load_context(param_1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2356 start=0xf009c09c */

sqword _task_map_io_ports(undefined4 param_1,uint param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=2357 start=0xf009c0a8 */

undefined8 _pmap_allocate_mapping(int param_1,undefined4 param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(int *)(param_1 + 0x20) = *(int *)(param_1 + 0x20) + 1;
  if (param_3 != 0) {
    *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2358 start=0xf009c0d4 */

/* WARNING: Removing unreachable block (ram,0xf009c10c) */

undefined8 _pmap_deallocate_mappings(int param_1,undefined4 param_2,int param_3,int param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) - param_4;
  param_3 = *(int *)(param_1 + 0x20) - param_3;
  *(int *)(param_1 + 0x20) = param_3;
  if ((*(int *)(param_1 + 0x24) < 0) || (param_3 < 0)) {
    _panic(aPmapDeallocate);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2359 start=0xf009c11c */

undefined8 _pmap_wire_mapping(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2360 start=0xf009c134 */

undefined8 _pmap_unwire_mapping(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(int *)(param_1 + 0x24) = *(int *)(param_1 + 0x24) + -1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2361 start=0xf009c14c */

/* WARNING: Removing unreachable block (ram,0xf009c2b4) */
/* WARNING: Removing unreachable block (ram,0xf009c274) */
/* WARNING: Removing unreachable block (ram,0xf009c2c8) */
/* WARNING: Removing unreachable block (ram,0xf009c264) */

undefined8 _pmap_bootstrap(uint param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  uint uVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DF98 = 0;
  dword_F013DFB8 = 0;
  dword_F013DFA8 = 0;
  dword_F013DFC8 = 0;
  dword_F013DFE8 = 0;
  dword_F013DFD8 = 0;
  DAT_f013df94 = &_reg_active;
  _reg_active._0_4_ = &_reg_active;
  DAT_f013dfb4 = &_reg_semi_active;
  _reg_semi_active._0_4_ = &_reg_semi_active;
  DAT_f013dfa4 = &_reg_free;
  _reg_free._0_4_ = &_reg_free;
  DAT_f013dfc4 = &_seg_active;
  _seg_active._0_4_ = &_seg_active;
  DAT_f013dfe4 = &_seg_semi_active;
  _seg_semi_active._0_4_ = &_seg_semi_active;
  DAT_f013dfd4 = &_seg_free;
  _seg_free._0_4_ = &_seg_free;
  dword_F013DE1C = &_garbage;
  _garbage = &_garbage;
  uVar3 = param_1 + param_2 * 0x1c;
  iVar5 = 0;
  if (param_1 < uVar3) {
    piVar4 = (int *)(param_1 + 0x14);
    do {
      param_1 = param_1 + 0x1c;
      iVar5 = iVar5 + ((uint)(piVar4[1] - *piVar4) >> ((byte)_page_shift & 0x1f));
      piVar4 = piVar4 + 7;
    } while (param_1 < uVar3);
  }
  iVar7 = 0;
  iVar6 = 0;
  uVar3 = iVar5 * 0x14 + _page_mask & ~_page_mask;
  _vm_alloc_from_regions(uVar3,_page_size);
  _pg_desc_tbl = uVar3;
  _bzero();
  puVar1 = &_tmp_maps;
  do {
    iVar5 = _page_size;
    uVar3 = _econtig + _page_mask & ~_page_mask;
    _econtig = uVar3;
    puVar1[1] = uVar3;
    _pmap_map(uVar3,0,0,iVar5,7,1);
    iVar7 = iVar7 + 1;
    uVar2 = _kernel_pmap;
    _pmap_page_table_entry(_kernel_pmap,_econtig,3);
    *puVar1 = uVar2;
    *(undefined4 *)(DAT_f013dff8 + iVar6) = 0;
    puVar1 = puVar1 + 3;
    iVar6 = iVar6 + 0xc;
    _econtig = _econtig + _page_size;
  } while (iVar7 < 5);
  *param_3 = 0xf0000000;
  *param_4 = 0xff000000;
  return CONCAT44(0xf0111c00,iVar7);
}
/* GHIDRADEC_FUNCTION index=2362 start=0xf009c310 */

/* WARNING: Removing unreachable block (ram,0xf009c494) */
/* WARNING: Removing unreachable block (ram,0xf009c4f8) */
/* WARNING: Removing unreachable block (ram,0xf009c39c) */
/* WARNING: Removing unreachable block (ram,0xf009c4c0) */
/* WARNING: Removing unreachable block (ram,0xf009c594) */
/* WARNING: Removing unreachable block (ram,0xf009c3b4) */
/* WARNING: Removing unreachable block (ram,0xf009c340) */

qword _pmap_map(undefined4 param_1,uint param_2,uint param_3,int param_4,undefined4 param_5,
               uint param_6)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint uVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  dword_F013DEA4 = dword_F013DEA4 + 1;
  if (_pmap_initialized != 0) {
    _panic(aPmapMapPmapIni);
  }
  uVar7 = (param_3 & 0xf) << 0x14 | param_2 >> 0xc;
  uVar4 = *(uint *)((int)register0x00000038 + 0x44) & 0xfffff000;
  uVar1 = *(uint *)((int)register0x00000038 + 0x44) + param_4 + 0xfff;
  uVar8 = uVar1 & 0xfffff000;
  *(uint *)((int)register0x00000038 + 0x44) = uVar4;
  if (uVar4 < uVar8) {
    do {
      while (piVar2 = _kernel_pmap,
            _pmap_page_table_entry(_kernel_pmap,*(undefined4 *)((int)register0x00000038 + 0x44),0),
            piVar2 == (int *)0x0) {
        _pmap_expand(_kernel_pmap,*(undefined4 *)((int)register0x00000038 + 0x44),3);
      }
      if (*(char *)((int)piVar2 + 0xd) == '\x03') {
        iVar5 = *piVar2;
        uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 10 & 0xfc;
      }
      else if (*(char *)((int)piVar2 + 0xd) == '\x02') {
        iVar5 = *piVar2;
        uVar4 = *(word *)((int)register0x00000038 + 0x44) & 0xfc;
      }
      else {
        iVar5 = *piVar2;
        uVar4 = (uint)*(byte *)((int)register0x00000038 + 0x44) << 2;
      }
      uVar4 = *(uint *)(iVar5 + uVar4);
      uVar6 = *(uint *)((int)register0x00000038 + 0x44);
      if ((uVar4 & 3) == 2) {
        if (*(char *)((int)piVar2 + 0xd) == '\x03') {
          if (uVar4 >> 8 != uVar7) {
loc_F009C494:
            _panic(aPmapMapInconsi);
          }
        }
        else {
          if (*(char *)((int)piVar2 + 0xd) == '\x02') {
            uVar6 = param_2 & 0xfffc0000;
          }
          else {
            uVar6 = param_2 & 0xff000000;
          }
          if (uVar4 >> 8 != uVar6 >> 0xc) goto loc_F009C494;
        }
      }
      else {
        iVar5 = *piVar2;
        *(uint *)((int)register0x00000038 + -0xc) = uVar7 << 8;
        piVar3 = _kernel_pmap;
        _vm_to_srmmu_prot(_kernel_pmap,param_5);
        uVar4 = *(uint *)((int)register0x00000038 + -0xc) & 0xffffff60 | ((uint)piVar3 & 7) << 2 |
                (param_6 & 1) << 7 | 2;
        *(uint *)((int)register0x00000038 + -0xc) = uVar4;
        _mmu_writepte(uVar4,iVar5 + (uVar6 >> 10 & 0xfc),
                      *(undefined4 *)((int)register0x00000038 + 0x44),3,0);
        if (*(uint *)((int)register0x00000038 + 0x44) ==
            (*(uint *)((int)register0x00000038 + 0x44) + _page_mask & ~_page_mask)) {
          *(char *)((int)piVar2 + 0xf) = *(char *)((int)piVar2 + 0xf) + '\x01';
          piVar3 = _kernel_pmap;
          uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 0xf & 4;
          *(uint *)((int)piVar2 + uVar4 + 0x10) =
               *(uint *)((int)piVar2 + uVar4 + 0x10) |
               1 << ((byte)(*(uint *)((int)register0x00000038 + 0x44) >> 0xc) & 0x1e);
          piVar3[8] = piVar3[8] + 1;
          piVar3[9] = piVar3[9] + 1;
        }
        if (_level3_only._0_4_ == 0) {
          *(int **)((int)register0x00000038 + -0x10) = piVar2;
          _pmap_gather_pte(_kernel_pmap,(undefined *)((int)register0x00000038 + -0x10),
                           *(undefined4 *)((int)register0x00000038 + 0x44));
        }
      }
      param_2 = param_2 + 0x1000;
      iVar5 = *(int *)((int)register0x00000038 + 0x44);
      uVar7 = uVar7 + 1;
      *(uint *)((int)register0x00000038 + 0x44) = iVar5 + 0x1000U;
    } while (iVar5 + 0x1000U < uVar8);
  }
  return CONCAT44(param_2,uVar1) & 0xfffffffffffff000;
}
/* GHIDRADEC_FUNCTION index=2363 start=0xf009c5c4 */

/* WARNING: Removing unreachable block (ram,0xf009c6ec) */
/* WARNING: Removing unreachable block (ram,0xf009c624) */
/* WARNING: Removing unreachable block (ram,0xf009c60c) */
/* WARNING: Removing unreachable block (ram,0xf009c6cc) */
/* WARNING: Removing unreachable block (ram,0xf009c6f8) */
/* WARNING: Removing unreachable block (ram,0xf009c5f0) */

undefined8 _pmap_change_prot(uint *param_1,int param_2)

{
  int *piVar1;
  undefined2 *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  piVar1 = _kernel_pmap;
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(uint **)((int)register0x00000038 + 0x44) = param_1;
  puVar2 = &_pmap_info;
  dword_F013DEA8 = dword_F013DEA8 + 1;
  if (param_2 != 0) {
    piVar4 = _kernel_pmap + 6;
    _splvm();
    do {
      do {
      } while (*piVar4 != 0);
      piVar3 = piVar4;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    piVar4 = piVar1;
    _pmap_page_table_entry(piVar1,*(undefined4 *)((int)register0x00000038 + 0x44),0);
    if (*(char *)((int)piVar4 + 0xd) == '\x03') {
      uVar5 = *(uint *)((int)register0x00000038 + 0x44) & ~_page_mask;
    }
    else {
      if (*(char *)((int)piVar4 + 0xd) == '\x02') {
        uVar5 = 0xfffc0000;
      }
      else {
        uVar5 = 0xff000000;
      }
      uVar5 = *(uint *)((int)register0x00000038 + 0x44) & uVar5;
    }
    *(uint *)((int)register0x00000038 + 0x44) = uVar5;
    if (*(char *)((int)piVar4 + 0xd) == '\x03') {
      iVar6 = *piVar4;
      uVar5 = *(uint *)((int)register0x00000038 + 0x44) >> 10 & 0xfc;
    }
    else if (*(char *)((int)piVar4 + 0xd) == '\x02') {
      iVar6 = *piVar4;
      uVar5 = *(word *)((int)register0x00000038 + 0x44) & 0xfc;
    }
    else {
      iVar6 = *piVar4;
      uVar5 = (uint)*(byte *)((int)register0x00000038 + 0x44) << 2;
    }
    param_1 = (uint *)(iVar6 + uVar5);
    if ((*param_1 & 3) == 2) {
      piVar3 = piVar1;
      _vm_to_srmmu_prot(piVar1,param_2);
      *(int **)((int)register0x00000038 + -0xc) = piVar4;
      _update_pte((undefined *)((int)register0x00000038 + -0xc),
                  *(undefined4 *)((int)register0x00000038 + 0x44),piVar3,*param_1 >> 7 & 1);
      piVar1[6] = 0;
    }
    _splx(puVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2364 start=0xf009c708 */

/* WARNING: Removing unreachable block (ram,0xf009c774) */
/* WARNING: Removing unreachable block (ram,0xf009c74c) */
/* WARNING: Removing unreachable block (ram,0xf009c79c) */
/* WARNING: Removing unreachable block (ram,0xf009c724) */

undefined8 _pmap_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar1 = 0x28;
  _zinit(0x28,16000,0,0,&aPmap);
  uVar2 = 0xc;
  _pmap_zone = uVar1;
  _zinit(0xc,120000,0,0,aPvEntry);
  uVar1 = 0x20;
  _pv_entry_zone = uVar2;
  _zinit(0x20,64000,0,0,aPoolZone);
  uVar2 = 0xc;
  _pool_zone = uVar1;
  _zinit(0xc,24000,0,0,aGarbageZone);
  _garbage_zone = uVar2;
  _pmap_initialized = 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2365 start=0xf009c7c0 */

/* WARNING: Removing unreachable block (ram,0xf009c824) */
/* WARNING: Removing unreachable block (ram,0xf009c804) */
/* WARNING: Removing unreachable block (ram,0xf009c810) */
/* WARNING: Removing unreachable block (ram,0xf009c870) */
/* WARNING: Removing unreachable block (ram,0xf009c7ec) */

undefined8 _pmap_create(int param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DEAC = dword_F013DEAC + 1;
  if (param_1 == 0) {
    puVar5 = _pmap_zone;
    _zalloc();
    if (puVar5 == (undefined4 *)0x0) {
      _panic(aPmapCreatePmap);
    }
    _bzero(puVar5,0x28);
    puVar5[4] = 0xfff;
    puVar5[3] = 0xfff;
    _pmap_alloc_reg_entry(puVar5);
    uVar2 = 0xf0000;
    uVar4 = *puVar5;
    piVar3 = (int *)*_kernel_pmap;
    iVar1 = -0x10000000;
    do {
      *(int *)((int)register0x00000038 + -0xc) = iVar1;
      uVar2 = uVar2 + 0x1000;
      _set_ptp(uVar4,iVar1,
               (*(uint *)(*piVar3 + (uint)*(byte *)((int)register0x00000038 + -0xc) * 4) >> 2) << 6)
      ;
      iVar1 = uVar2 * 0x1000;
    } while (uVar2 < 0x100000);
    puVar5[6] = 0;
    puVar5[5] = 0;
    puVar5[7] = 1;
  }
  else {
    puVar5 = (undefined4 *)0x0;
  }
  return CONCAT44(param_2,puVar5);
}
/* GHIDRADEC_FUNCTION index=2366 start=0xf009c89c */

/* WARNING: Removing unreachable block (ram,0xf009c928) */
/* WARNING: Removing unreachable block (ram,0xf009c8f0) */
/* WARNING: Removing unreachable block (ram,0xf009c8d4) */
/* WARNING: Removing unreachable block (ram,0xf009c914) */
/* WARNING: Removing unreachable block (ram,0xf009c938) */
/* WARNING: Removing unreachable block (ram,0xf009c8b0) */

undefined8 _pmap_destroy(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DEB0 = dword_F013DEB0 + 1;
  _pmap_print_info();
  if ((param_1 != 0) && (param_1 != _kernel_pmap)) {
    iVar1 = _kernel_pmap;
    _splvm();
    do {
      do {
      } while (*(int *)(param_1 + 0x18) != 0);
      piVar2 = (int *)(param_1 + 0x18);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x18) = 0;
    iVar3 = *(int *)(param_1 + 0x1c) + -1;
    *(int *)(param_1 + 0x1c) = iVar3;
    _splx(iVar1);
    if (iVar3 == 0) {
      _pmap_dealloc_reg_entry(param_1);
      _zfree(_pmap_zone,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2367 start=0xf009c948 */

/* WARNING: Removing unreachable block (ram,0xf009c984) */
/* WARNING: Removing unreachable block (ram,0xf009c9a8) */
/* WARNING: Removing unreachable block (ram,0xf009c968) */

undefined8 _pmap_reference(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = dword_F013DEB4 + 1;
  dword_F013DEB4 = iVar1;
  if (param_1 != 0) {
    _splvm();
    do {
      do {
      } while (*(int *)(param_1 + 0x18) != 0);
      piVar2 = (int *)(param_1 + 0x18);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x18) = 0;
    *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2368 start=0xf009c9b8 */

/* WARNING: Removing unreachable block (ram,0xf009cb60) */
/* WARNING: Removing unreachable block (ram,0xf009cbb8) */
/* WARNING: Removing unreachable block (ram,0xf009caf0) */
/* WARNING: Removing unreachable block (ram,0xf009ca58) */
/* WARNING: Removing unreachable block (ram,0xf009cad4) */
/* WARNING: Removing unreachable block (ram,0xf009ca88) */
/* WARNING: Removing unreachable block (ram,0xf009cb9c) */
/* WARNING: Removing unreachable block (ram,0xf009cb50) */
/* WARNING: Removing unreachable block (ram,0xf009cbd4) */
/* WARNING: Removing unreachable block (ram,0xf009cab8) */

undefined8 _pmap_page_table_entry(undefined4 *param_1,uint param_2,uint param_3)

{
  byte bVar1;
  word wVar2;
  uint uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar7;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar4 = (int *)0x0;
  piVar6 = (int *)0x0;
  *(uint *)((int)register0x00000038 + 0x48) = param_2;
  dword_F013DEB8 = dword_F013DEB8 + 1;
  piVar7 = (int *)(param_2 & 0xfffc0000);
  if (piVar7 == (int *)param_1[4]) {
    piVar4 = (int *)param_1[2];
    goto locret_F009CBE0;
  }
  DAT_f013debc = DAT_f013debc + 1;
  piVar7 = (int *)*param_1;
  bVar1 = *(byte *)((int)register0x00000038 + 0x48);
  iVar5 = *piVar7;
  uVar3 = *(uint *)(iVar5 + (uint)bVar1 * 4) & 3;
  if (uVar3 != 1) {
    if (uVar3 < 2) {
      if (uVar3 != 0) {
loc_F009CAD4:
        _panic(aPmapPageTableE_8);
        goto loc_F009CADC;
      }
    }
    else {
      if (uVar3 != 2) goto loc_F009CAD4;
      piVar4 = piVar7;
      if (param_3 < 2) goto locret_F009CBE0;
      _panic(aPmapPageTableE_7);
    }
    piVar4 = (int *)((uint)piVar7 & (param_3 != 1) - 1);
    goto locret_F009CBE0;
  }
  if (param_3 == 1) {
    _panic(aPmapPageTableE);
    uVar3 = *(uint *)((int)register0x00000038 + 0x48);
  }
  else {
    uVar3 = *(uint *)((int)register0x00000038 + 0x48);
  }
  if ((uVar3 & 0xff000000) == param_1[3]) {
    piVar4 = (int *)param_1[1];
  }
  else {
    piVar4 = (int *)((*(uint *)(iVar5 + (uint)bVar1 * 4) >> 2) << 6);
    _pmap_seg_entry();
    uVar3 = *(uint *)((int)register0x00000038 + 0x48);
    param_1[1] = piVar4;
    param_1[3] = uVar3 & 0xff000000;
  }
loc_F009CADC:
  if (*piVar4 == 0) {
    _panic(aPmapPageTableE_0);
    wVar2 = *(word *)((int)register0x00000038 + 0x48);
  }
  else {
    wVar2 = *(word *)((int)register0x00000038 + 0x48);
  }
  iVar5 = *piVar4;
  piVar7 = (int *)(wVar2 & 0xfc);
  uVar3 = *(uint *)(iVar5 + (int)piVar7) & 3;
  if (uVar3 == 1) {
    if (param_3 == 2) {
      _panic(aPmapPageTableE_1);
      uVar3 = *(uint *)(iVar5 + (int)piVar7);
    }
    else {
      uVar3 = *(uint *)(iVar5 + (int)piVar7);
    }
    piVar6 = (int *)((uVar3 >> 2) << 6);
    _pmap_seg_entry();
    param_1[2] = piVar6;
    param_1[4] = *(uint *)((int)register0x00000038 + 0x48) & 0xfffc0000;
loc_F009CBC0:
    piVar4 = piVar6;
    if (*piVar6 == 0) {
      _panic(aPmapPageTableE_2);
    }
  }
  else {
    if (uVar3 < 2) {
      if (uVar3 != 0) {
loc_F009CBB8:
        _panic(aPmapPageTableE_10);
        goto loc_F009CBC0;
      }
    }
    else {
      if (uVar3 != 2) goto loc_F009CBB8;
      if ((param_3 == 2) || (param_3 == 0)) goto locret_F009CBE0;
      _panic(aPmapPageTableE_9);
    }
    piVar4 = (int *)((uint)piVar4 & (param_3 != 2) - 1);
  }
locret_F009CBE0:
  return CONCAT44(piVar7,piVar4);
}
/* GHIDRADEC_FUNCTION index=2369 start=0xf009cbe8 */

/* WARNING: Removing unreachable block (ram,0xf009cdd0) */
/* WARNING: Removing unreachable block (ram,0xf009cc04) */
/* WARNING: Removing unreachable block (ram,0xf009cc5c) */
/* WARNING: Removing unreachable block (ram,0xf009cde4) */
/* WARNING: Removing unreachable block (ram,0xf009cbfc) */

undefined8 _pmap_scatter_pte(int *param_1,undefined4 *param_2,undefined4 param_3)

{
  int *piVar1;
  undefined uVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  int *piVar9;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  piVar9 = (int *)*param_2;
  _pmap_alloc_seg_entry(param_1,param_3,3);
  piVar1 = param_1;
  _splvm();
  param_1[8] = (int)piVar9;
  iVar8 = *param_1;
  iVar7 = 0;
  iVar5 = 0;
  uVar3 = *(uint *)(*piVar9 + (*(word *)((int)register0x00000038 + 0x4c) & 0xfc));
  do {
    *(uint *)(iVar5 + iVar8) = uVar3;
    uVar3 = uVar3 & 0xff | (uVar3 & 0xffffff00) + 0x100;
    iVar7 = iVar7 + 1;
    iVar5 = iVar5 + 4;
  } while (iVar7 < 0x40);
  uVar2 = 0x40;
  .div(0x40,_pmap_info);
  *(undefined *)((int)param_1 + 0xf) = uVar2;
  iVar5 = _wmap1;
  param_1[4] = _wmap0;
  param_1[5] = iVar5;
  iVar5 = _mmap1;
  if (*(char *)((int)piVar9 + 0xd) == '\x03') {
    uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0xf;
    bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0xc) & 0x1e;
loc_F009CCD4:
    if ((*(uint *)((int)piVar9 + (uVar3 & 4) + 0x18) & 1 << bVar6) == 0) {
      uVar4 = *(undefined4 *)((int)register0x00000038 + 0x4c);
      goto loc_F009CDBC;
    }
loc_F009CD18:
    param_1[6] = _mmap0;
    param_1[7] = iVar5;
    if (*(char *)((int)piVar9 + 0xd) == '\x03') {
      uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0xf;
      bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0xc) & 0x1e;
    }
    else {
      if (*(char *)((int)piVar9 + 0xd) != '\x02') {
        bVar6 = *(byte *)((int)register0x00000038 + 0x4c) >> 5;
        piVar9[bVar6 + 0xc] =
             piVar9[bVar6 + 0xc] & ~(1 << (*(byte *)((int)register0x00000038 + 0x4c) & 0x1f));
        goto loc_F009CDB8;
      }
      uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0x15;
      bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0x12) & 0x1f;
    }
    *(uint *)((int)piVar9 + (uVar3 & 4) + 0x18) =
         *(uint *)((int)piVar9 + (uVar3 & 4) + 0x18) & ~(1 << bVar6);
  }
  else {
    if (*(char *)((int)piVar9 + 0xd) == '\x02') {
      uVar3 = *(uint *)((int)register0x00000038 + 0x4c) >> 0x15;
      bVar6 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0x12) & 0x1f;
      goto loc_F009CCD4;
    }
    if ((piVar9[(*(byte *)((int)register0x00000038 + 0x4c) >> 5) + 0xc] &
        1 << (*(byte *)((int)register0x00000038 + 0x4c) & 0x1f)) != 0) goto loc_F009CD18;
  }
loc_F009CDB8:
  uVar4 = *(undefined4 *)((int)register0x00000038 + 0x4c);
loc_F009CDBC:
  _set_ptp(piVar9,uVar4,*(int *)(param_1[1] + 4) + (uint)*(byte *)((int)param_1 + 0xe) * 0x100);
  *(char *)((int)piVar9 + 0xf) = *(char *)((int)piVar9 + 0xf) + -1;
  _splx(piVar1);
  return CONCAT44(piVar9,param_1);
}
/* GHIDRADEC_FUNCTION index=2370 start=0xf009cdf4 */

/* WARNING: Removing unreachable block (ram,0xf009ce04) */

undefined8 _is_ptes_contiguous(undefined4 *param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
  uint *puVar6;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  param_1 = (undefined4 *)*param_1;
  uVar1 = 0x40;
  .div(0x40,_pmap_info);
  if (*(byte *)((int)param_1 + 0xf) == uVar1) {
    if (param_1[4] == _wmap0) {
      if (param_1[5] == _wmap1) {
        if (param_1[6] == 0) {
          if (param_1[7] == 0) {
            puVar6 = (uint *)*param_1;
            uVar1 = *puVar6 >> 8;
            if ((uVar1 & 0x3f) == 0) {
              *param_2 = 0;
              *param_3 = 0;
              iVar4 = 0;
              uVar2 = *puVar6;
              do {
                uVar3 = *puVar6;
                if (uVar3 >> 8 != uVar1) {
                  uVar5 = 0;
                  goto locret_F009CF1C;
                }
                if ((uVar3 >> 7 & 1) != (uVar2 >> 7 & 1)) {
                  uVar5 = 0;
                  goto locret_F009CF1C;
                }
                if ((uVar3 >> 2 & 7) != (uVar2 >> 2 & 7)) {
                  uVar5 = 0;
                  goto locret_F009CF1C;
                }
                if ((uVar3 & 0x40) != 0) {
                  *param_2 = 1;
                }
                if ((*puVar6 & 0x20) != 0) {
                  *param_3 = 1;
                }
                puVar6 = puVar6 + 1;
                iVar4 = iVar4 + 1;
                uVar1 = uVar1 + 1;
              } while (iVar4 < 0x40);
              uVar5 = 1;
            }
            else {
              uVar5 = 0;
            }
          }
          else {
            uVar5 = 0;
          }
        }
        else {
          uVar5 = 0;
        }
      }
      else {
        uVar5 = 0;
      }
    }
    else {
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 0;
  }
locret_F009CF1C:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=2371 start=0xf009cf24 */

/* WARNING: Removing unreachable block (ram,0xf009d068) */
/* WARNING: Removing unreachable block (ram,0xf009cfc4) */
/* WARNING: Removing unreachable block (ram,0xf009d088) */
/* WARNING: Removing unreachable block (ram,0xf009cf3c) */

undefined8 _pmap_gather_pte(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

{
  undefined *puVar1;
  uint uVar2;
  byte bVar3;
  undefined4 unaff_l0;
  uint *puVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar5;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  puVar1 = (undefined *)((int)register0x00000038 + -0x14);
  param_2 = (undefined4 *)*param_2;
  *(undefined4 **)((int)register0x00000038 + -0x14) = param_2;
  _is_ptes_contiguous(puVar1,(undefined *)((int)register0x00000038 + -0xc),
                      (undefined *)((int)register0x00000038 + -0x10));
  if (puVar1 == (undefined *)0x0) goto locret_F009D090;
  iVar5 = param_2[8];
  if (*(char *)(iVar5 + 0xd) == '\x03') {
    uVar2 = *(uint *)((int)register0x00000038 + 0x4c) & ~_page_mask;
  }
  else {
    if (*(char *)(iVar5 + 0xd) == '\x02') {
      uVar2 = 0xfffc0000;
    }
    else {
      uVar2 = 0xff000000;
    }
    uVar2 = *(uint *)((int)register0x00000038 + 0x4c) & uVar2;
  }
  *(uint *)((int)register0x00000038 + 0x4c) = uVar2;
  puVar4 = (uint *)*param_2;
  *(int *)((int)register0x00000038 + -0x14) = iVar5;
  uVar2 = *puVar4;
  _set_pte((undefined *)((int)register0x00000038 + -0x14),
           *(undefined4 *)((int)register0x00000038 + 0x4c),uVar2 >> 8,uVar2 >> 2 & 7,uVar2 >> 7 & 1,
           *(undefined4 *)((int)register0x00000038 + -0xc),
           *(undefined4 *)((int)register0x00000038 + -0x10));
  *(char *)(iVar5 + 0xf) = *(char *)(iVar5 + 0xf) + -1;
  if (*(char *)(iVar5 + 0xd) == '\x03') {
    uVar2 = *(uint *)((int)register0x00000038 + 0x4c) >> 0xf;
    bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0xc) & 0x1e;
loc_F009D02C:
    iVar5 = (uVar2 & 4) + iVar5;
    *(uint *)(iVar5 + 0x10) = *(uint *)(iVar5 + 0x10) | 1 << bVar3;
  }
  else {
    if (*(char *)(iVar5 + 0xd) == '\x02') {
      uVar2 = *(uint *)((int)register0x00000038 + 0x4c) >> 0x15;
      bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x4c) >> 0x12) & 0x1f;
      goto loc_F009D02C;
    }
    iVar5 = (uint)(*(byte *)((int)register0x00000038 + 0x4c) >> 5) * 4 + iVar5;
    *(uint *)(iVar5 + 0x10) =
         *(uint *)(iVar5 + 0x10) | 1 << (*(byte *)((int)register0x00000038 + 0x4c) & 0x1f);
  }
  _bzero(puVar4,0x100);
  *(undefined *)((int)param_2 + 0xf) = 0;
  param_2[4] = 0;
  param_2[5] = 0;
  param_2[6] = 0;
  param_2[7] = 0;
  param_2[8] = 0;
  _pmap_dealloc_seg_entry(param_2);
locret_F009D090:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2372 start=0xf009d098 */

/* WARNING: Removing unreachable block (ram,0xf009d0c0) */

undefined8 _pmap_getpte(int *param_1,undefined4 param_2,uint *param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  dword_F013DEC0 = dword_F013DEC0 + 1;
  *param_3 = 0;
  piVar1 = param_1;
  _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),0);
  if (piVar1 != (int *)0x0) {
    if (*(char *)((int)piVar1 + 0xd) == '\x03') {
      iVar4 = *piVar1;
      uVar2 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
    }
    else if (*(char *)((int)piVar1 + 0xd) == '\x02') {
      iVar4 = *piVar1;
      uVar2 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
    }
    else {
      iVar4 = *piVar1;
      uVar2 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
    }
    uVar2 = *(uint *)(iVar4 + uVar2);
    *param_3 = uVar2;
    uVar2 = uVar2 >> 8;
    if (*(char *)((int)piVar1 + 0xd) == '\x03') {
      uVar3 = uVar2 & 0xfffff;
    }
    else {
      uVar3 = uVar2 * 0x1000 + (*(uint *)((int)register0x00000038 + 0x48) & 0x3ffff) >> 0xc;
    }
    *param_3 = (uint)(byte)*param_3 | (uVar2 | uVar3) << 8;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2373 start=0xf009d17c */

/* WARNING: Removing unreachable block (ram,0xf009d7e0) */
/* WARNING: Removing unreachable block (ram,0xf009d434) */
/* WARNING: Removing unreachable block (ram,0xf009d708) */
/* WARNING: Removing unreachable block (ram,0xf009d5f8) */
/* WARNING: Removing unreachable block (ram,0xf009d560) */
/* WARNING: Removing unreachable block (ram,0xf009d1e4) */
/* WARNING: Removing unreachable block (ram,0xf009d418) */
/* WARNING: Removing unreachable block (ram,0xf009d5d0) */
/* WARNING: Removing unreachable block (ram,0xf009d644) */
/* WARNING: Removing unreachable block (ram,0xf009d724) */
/* WARNING: Removing unreachable block (ram,0xf009d7b8) */
/* WARNING: Removing unreachable block (ram,0xf009d7e8) */
/* WARNING: Removing unreachable block (ram,0xf009d1ac) */

undefined8 _pmap_remove(int *param_1,undefined4 param_2,undefined4 param_3)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int *piVar5;
  uint uVar6;
  byte bVar10;
  int *piVar7;
  uint uVar8;
  undefined4 uVar9;
  uint uVar11;
  undefined4 unaff_l0;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 *puVar14;
  undefined4 *puVar15;
  undefined4 unaff_l1;
  uint *puVar16;
  int iVar17;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  int *piVar18;
  undefined4 unaff_i0;
  int *piVar19;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar20;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar21;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + -0x14) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x1c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x24) = 0;
  *(undefined4 *)((int)register0x00000038 + -0x2c) = 0;
  piVar19 = param_1;
  if (param_1 != (int *)0x0) {
    iVar4 = dword_F013DEC4 + 1;
    dword_F013DEC4 = iVar4;
    _splvm();
    *(int *)((int)register0x00000038 + -0x34) = iVar4;
    *(uint *)((int)register0x00000038 + -0xc) =
         *(uint *)((int)register0x00000038 + -0x14) & ~_page_mask;
    if ((*(uint *)((int)register0x00000038 + -0x14) & ~_page_mask) <
        *(uint *)((int)register0x00000038 + -0x1c)) {
      param_2 = 1;
      do {
        piVar5 = param_1;
        _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (piVar5 == (int *)0x0) {
          *(uint *)((int)register0x00000038 + -0xc) =
               *(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000;
loc_F009D7C0:
          uVar20 = *(uint *)((int)register0x00000038 + -0xc);
        }
        else {
          if (*(char *)((int)piVar5 + 0xd) == '\x03') {
            uVar20 = *(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000;
          }
          else {
            uVar20 = 0xffffe000;
            if (*(char *)((int)piVar5 + 0xd) == '\x02') {
              uVar20 = *(int *)((int)register0x00000038 + -0xc) + 0x1000000U & 0xff000000;
            }
          }
          if (*(uint *)((int)register0x00000038 + -0x1c) < uVar20) {
            uVar20 = *(uint *)((int)register0x00000038 + -0x1c);
          }
          uVar6 = *(uint *)((int)register0x00000038 + -0xc);
          if (uVar6 < uVar20) {
            do {
              if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                iVar4 = *piVar5;
                uVar6 = uVar6 >> 10 & 0xfc;
              }
              else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
                iVar4 = *piVar5;
                uVar6 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
              }
              else {
                iVar4 = *piVar5;
                uVar6 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
              }
              puVar12 = (uint *)(iVar4 + uVar6);
              puVar16 = puVar12 + 1;
              if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                puVar16 = puVar12 + _pmap_info;
              }
              bVar2 = false;
              bVar3 = false;
              if ((*puVar12 & 3) == 2) {
                cVar1 = *(char *)((int)piVar5 + 0xd);
                *(int *)((int)register0x00000038 + -0x24) =
                     *(int *)((int)register0x00000038 + -0x24) + 1;
                if (cVar1 == '\x03') {
                  uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
                  bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
loc_F009D348:
                  if ((*(uint *)((int)piVar5 + (uVar6 & 4) + 0x10) & 1 << bVar10) == 0) {
                    uVar6 = *puVar12;
                  }
                  else {
                    cVar1 = *(char *)((int)piVar5 + 0xd);
loc_F009D38C:
                    if (cVar1 == '\x03') {
                      uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf & 4;
                      bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
                    }
                    else {
                      bVar10 = *(byte *)((int)register0x00000038 + -0xc);
                      if (cVar1 == '\x02') {
                        bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12);
                        uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15 & 4;
                      }
                      else {
                        uVar6 = (uint)(bVar10 >> 5) << 2;
                      }
                      bVar10 = bVar10 & 0x1f;
                    }
                    *(uint *)((int)piVar5 + uVar6 + 0x10) =
                         *(uint *)((int)piVar5 + uVar6 + 0x10) & ~(1 << bVar10);
                    *(int *)((int)register0x00000038 + -0x2c) =
                         *(int *)((int)register0x00000038 + -0x2c) + 1;
                    uVar6 = *puVar12;
                  }
                }
                else {
                  if (cVar1 == '\x02') {
                    uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
                    bVar10 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
                    goto loc_F009D348;
                  }
                  if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 4] &
                      1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) != 0) {
                    cVar1 = *(char *)((int)piVar5 + 0xd);
                    goto loc_F009D38C;
                  }
                  uVar6 = *puVar12;
                }
                if (uVar6 >> 8 < _physmaxpfn) {
                  iVar4 = (uVar6 >> 8) << 0xc;
                  _vm_valid_page();
                  if (iVar4 != 0) {
                    if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                      uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xfff;
                    }
                    else {
                      uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0x3ffff;
                    }
                    piVar19 = (int *)((*puVar12 >> 8) * 0x1000 + uVar6);
                    if (puVar12 < puVar16) {
                      uVar11 = *(uint *)((int)register0x00000038 + -0xc);
                      uVar6 = *puVar12;
                      do {
                        if ((uVar6 & 0x40) == 0) {
                          if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                            if ((*(uint *)((int)piVar5 + (uVar11 >> 0xf & 4) + 0x18) &
                                1 << ((byte)(uVar11 >> 0xc) & 0x1e)) != 0) goto loc_F009D538;
                            uVar6 = *puVar12;
                          }
                          else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
                            if ((*(uint *)((int)piVar5 + (uVar11 >> 0x15 & 4) + 0x18) &
                                1 << ((byte)(uVar11 >> 0x12) & 0x1f)) != 0) goto loc_F009D538;
                            uVar6 = *puVar12;
                          }
                          else if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 0xc] &
                                   1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) == 0) {
                            uVar6 = *puVar12;
                          }
                          else {
loc_F009D538:
                            bVar2 = true;
                            uVar6 = *puVar12;
                          }
                        }
                        else {
                          bVar2 = true;
                        }
                        if ((uVar6 & 0x20) != 0) {
                          bVar3 = true;
                        }
                        puVar12 = puVar12 + 1;
                        if (puVar16 <= puVar12) break;
                        uVar6 = *puVar12;
                      } while( true );
                    }
                    *(int **)((int)register0x00000038 + -0x10) = piVar5;
                    _set_invalidpte((undefined *)((int)register0x00000038 + -0x10),
                                    *(undefined4 *)((int)register0x00000038 + -0xc));
                    if (*(char *)((int)piVar5 + 0xd) == '\x03') {
                      uVar6 = (*(uint *)((int)register0x00000038 + -0xc) & ~_page_mask) + _page_size
                      ;
                    }
                    else {
                      if (*(char *)((int)piVar5 + 0xd) == '\x02') {
                        uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xfffc0000;
                        iVar4 = 0x40000;
                      }
                      else {
                        uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xff000000;
                        iVar4 = 0x1000000;
                      }
                      uVar6 = uVar6 + iVar4;
                    }
                    piVar18 = piVar19;
                    for (uVar11 = *(uint *)((int)register0x00000038 + -0xc); uVar11 < uVar6;
                        uVar11 = uVar11 + _page_size) {
                      piVar7 = piVar19;
                      _vm_mem_ppi();
                      iVar4 = _pg_desc_tbl;
                      iVar17 = (int)piVar7 * 0x14;
                      puVar13 = (undefined4 *)(_pg_desc_tbl + iVar17);
                      if (bVar2) {
                        piVar7 = piVar18;
                        _vm_phys_to_vm_page();
                        piVar7[7] = piVar7[7] & 0xfffffbff;
                        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 1;
                      }
                      if (bVar3) {
                        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 2;
                      }
                      if (puVar13[1] == 0) {
                        _panic(aPmapRemovePmap);
                        uVar8 = puVar13[2];
                      }
                      else {
                        uVar8 = puVar13[2];
                      }
                      if ((uVar8 >> 8) * 0x1000 - uVar11 == 0) {
                        if ((int *)puVar13[1] != param_1) {
                          puVar14 = (undefined4 *)*puVar13;
                          goto loc_F009D6B0;
                        }
                        puVar14 = *(undefined4 **)(iVar4 + iVar17);
                        if (puVar14 != (undefined4 *)0x0) {
                          *(undefined4 *)(iVar4 + iVar17) = *puVar14;
                          puVar13[1] = puVar14[1];
                          uVar9 = _pv_entry_zone;
                          puVar13[2] = puVar14[2];
                          goto loc_F009D724;
                        }
                        puVar13[1] = 0;
                      }
                      else {
                        puVar14 = (undefined4 *)*puVar13;
loc_F009D6B0:
                        bVar21 = puVar14 == (undefined4 *)0x0;
                        if (!bVar21) {
                          uVar8 = puVar14[2];
                          while( true ) {
                            puVar15 = puVar14;
                            if (((uVar8 >> 8) * 0x1000 - uVar11 == 0) &&
                               (bVar21 = puVar15 == (undefined4 *)0x0, puVar14 = puVar15,
                               (int *)puVar15[1] == param_1)) goto loc_F009D6FC;
                            puVar14 = (undefined4 *)*puVar15;
                            puVar13 = puVar15;
                            if (puVar14 == (undefined4 *)0x0) break;
                            uVar8 = puVar14[2];
                          }
                          bVar21 = true;
                        }
loc_F009D6FC:
                        if (bVar21) {
                          _panic(aPmapRemovePmap_0,puVar14);
                        }
                        uVar9 = _pv_entry_zone;
                        *puVar13 = *puVar14;
loc_F009D724:
                        _zfree(uVar9,puVar14);
                      }
                      piVar18 = (int *)((int)piVar18 + _page_size);
                    }
                    goto loc_F009D744;
                  }
                  *(int **)((int)register0x00000038 + -0x10) = piVar5;
                }
                else {
                  *(int **)((int)register0x00000038 + -0x10) = piVar5;
                }
                _set_invalidpte((undefined *)((int)register0x00000038 + -0x10),
                                *(undefined4 *)((int)register0x00000038 + -0xc));
                cVar1 = *(char *)((int)piVar5 + 0xd);
              }
              else {
loc_F009D744:
                cVar1 = *(char *)((int)piVar5 + 0xd);
              }
              if (cVar1 == '\x03') {
                uVar6 = (*(uint *)((int)register0x00000038 + -0xc) & ~_page_mask) + _page_size;
              }
              else {
                if (cVar1 == '\x02') {
                  uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xfffc0000;
                  iVar4 = 0x40000;
                }
                else {
                  uVar6 = *(uint *)((int)register0x00000038 + -0xc) & 0xff000000;
                  iVar4 = 0x1000000;
                }
                uVar6 = uVar6 + iVar4;
              }
              *(uint *)((int)register0x00000038 + -0xc) = uVar6;
            } while (uVar6 < uVar20);
            cVar1 = *(char *)((int)piVar5 + 0xf);
          }
          else {
            cVar1 = *(char *)((int)piVar5 + 0xf);
          }
          uVar20 = *(uint *)((int)register0x00000038 + -0xc);
          if (cVar1 == '\0') {
            _pmap_dealloc_seg_entry(piVar5);
            goto loc_F009D7C0;
          }
        }
      } while (uVar20 < *(uint *)((int)register0x00000038 + -0x1c));
    }
    _pmap_deallocate_mappings
              (param_1,*(undefined4 *)((int)register0x00000038 + -0x14),
               *(undefined4 *)((int)register0x00000038 + -0x24),
               *(undefined4 *)((int)register0x00000038 + -0x2c));
    _splx(*(undefined4 *)((int)register0x00000038 + -0x34));
  }
  return CONCAT44(param_2,piVar19);
}
/* GHIDRADEC_FUNCTION index=2374 start=0xf009d7f8 */

/* WARNING: Removing unreachable block (ram,0xf009dbd8) */
/* WARNING: Removing unreachable block (ram,0xf009db7c) */
/* WARNING: Removing unreachable block (ram,0xf009da68) */
/* WARNING: Removing unreachable block (ram,0xf009d99c) */
/* WARNING: Removing unreachable block (ram,0xf009d92c) */
/* WARNING: Removing unreachable block (ram,0xf009d89c) */
/* WARNING: Removing unreachable block (ram,0xf009d830) */
/* WARNING: Removing unreachable block (ram,0xf009d83c) */
/* WARNING: Removing unreachable block (ram,0xf009d8b4) */
/* WARNING: Removing unreachable block (ram,0xf009d938) */
/* WARNING: Removing unreachable block (ram,0xf009da34) */
/* WARNING: Removing unreachable block (ram,0xf009db68) */
/* WARNING: Removing unreachable block (ram,0xf009dbc4) */
/* WARNING: Removing unreachable block (ram,0xf009dbf4) */
/* WARNING: Removing unreachable block (ram,0xf009d810) */

undefined8 _pmap_remove_all(uint param_1,int param_2)

{
  char cVar1;
  bool bVar2;
  bool bVar3;
  undefined4 uVar4;
  int *piVar5;
  uint uVar6;
  byte bVar8;
  uint uVar7;
  int iVar9;
  undefined4 *puVar10;
  uint uVar11;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar12;
  undefined4 *puVar13;
  undefined4 unaff_l3;
  int *piVar14;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar12 = (uint *)0x0;
  if ((param_1 < _physmax) && (uVar6 = param_1, _vm_valid_page(), uVar6 != 0)) {
    param_2 = dword_F013DEC8 + 1;
    dword_F013DEC8 = param_2;
    _splvm();
    uVar6 = param_1;
    _vm_mem_ppi();
    puVar13 = (undefined4 *)(_pg_desc_tbl + uVar6 * 0x14);
    piVar14 = (int *)puVar13[1];
    while (piVar14 != (int *)0x0) {
      bVar2 = false;
      bVar3 = false;
      *(uint *)((int)register0x00000038 + -0xc) = ((uint)puVar13[2] >> 8) << 0xc;
      do {
        do {
        } while (piVar14[6] != 0);
        piVar5 = piVar14 + 6;
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      piVar5 = piVar14;
      _pmap_page_table_entry(piVar14,*(undefined4 *)((int)register0x00000038 + -0xc),0);
      if (piVar5 == (int *)0x0) {
loc_F009D924:
        _printf(aPmapXVaX,piVar14,*(undefined4 *)((int)register0x00000038 + -0xc));
        _panic(aPmapRemoveAllP);
      }
      else {
        if (*(char *)((int)piVar5 + 0xd) == '\x03') {
          iVar9 = *piVar5;
          uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
        }
        else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
          iVar9 = *piVar5;
          uVar6 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
        }
        else {
          iVar9 = *piVar5;
          uVar6 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
        }
        puVar12 = (uint *)(iVar9 + uVar6);
        if ((*puVar12 & 3) != 2) goto loc_F009D924;
      }
      if (*(char *)((int)piVar5 + 0xd) == '\x03') {
        if ((*puVar12 >> 8) * 0x1000 + (*(uint *)((int)register0x00000038 + -0xc) & 0xfff) !=
            param_1) {
loc_F009D99C:
          _panic(aPmapRemoveAllP_0);
          goto loc_F009D9A4;
        }
        cVar1 = *(char *)((int)piVar5 + 0xd);
      }
      else {
        if ((*puVar12 >> 8) * 0x1000 + (*(uint *)((int)register0x00000038 + -0xc) & 0x3ffff) !=
            param_1) goto loc_F009D99C;
loc_F009D9A4:
        cVar1 = *(char *)((int)piVar5 + 0xd);
      }
      if (cVar1 == '\x03') {
        uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
        bVar8 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
loc_F009D9F0:
        if ((*(uint *)((int)piVar5 + (uVar6 & 4) + 0x10) & 1 << bVar8) == 0) {
          puVar10 = (undefined4 *)*puVar13;
        }
        else {
loc_F009DA34:
          _panic(aPmapRemoveAllR);
          puVar10 = (undefined4 *)*puVar13;
        }
      }
      else {
        if (cVar1 == '\x02') {
          uVar6 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
          bVar8 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
          goto loc_F009D9F0;
        }
        if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 4] &
            1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) != 0) goto loc_F009DA34;
        puVar10 = (undefined4 *)*puVar13;
      }
      if (puVar10 == (undefined4 *)0x0) {
        puVar13[1] = 0;
      }
      else {
        *puVar13 = *puVar10;
        puVar13[1] = puVar10[1];
        uVar4 = _pv_entry_zone;
        puVar13[2] = puVar10[2];
        _zfree(uVar4);
      }
      uVar6 = (uint)_pmap_info;
      if (uVar6 != 0) {
        uVar11 = *(uint *)((int)register0x00000038 + -0xc);
        do {
          uVar6 = uVar6 - 1;
          uVar7 = *puVar12;
          if ((uVar7 & 0x40) == 0) {
            if (*(char *)((int)piVar5 + 0xd) == '\x03') {
              if ((*(uint *)((int)piVar5 + (uVar11 >> 0xf & 4) + 0x18) &
                  1 << ((byte)(uVar11 >> 0xc) & 0x1e)) != 0) goto loc_F009DB40;
              uVar7 = *puVar12;
            }
            else if (*(char *)((int)piVar5 + 0xd) == '\x02') {
              if ((*(uint *)((int)piVar5 + (uVar11 >> 0x15 & 4) + 0x18) &
                  1 << ((byte)(uVar11 >> 0x12) & 0x1f)) != 0) goto loc_F009DB40;
              uVar7 = *puVar12;
            }
            else if ((piVar5[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 0xc] &
                     1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) == 0) {
              uVar7 = *puVar12;
            }
            else {
loc_F009DB40:
              bVar2 = true;
              uVar7 = *puVar12;
            }
          }
          else {
            bVar2 = true;
          }
          if ((uVar7 & 0x20) != 0) {
            bVar3 = true;
          }
          puVar12 = puVar12 + 1;
        } while (0 < (int)uVar6);
      }
      *(int **)((int)register0x00000038 + -0x10) = piVar5;
      _set_invalidpte((undefined *)((int)register0x00000038 + -0x10),
                      *(undefined4 *)((int)register0x00000038 + -0xc));
      if (bVar2) {
        uVar6 = param_1;
        _vm_phys_to_vm_page();
        *(uint *)(uVar6 + 0x1c) = *(uint *)(uVar6 + 0x1c) & 0xfffffbff;
        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 1;
      }
      if (bVar3) {
        *(byte *)(puVar13 + 4) = *(byte *)(puVar13 + 4) | 2;
        cVar1 = *(char *)((int)piVar5 + 0xf);
      }
      else {
        cVar1 = *(char *)((int)piVar5 + 0xf);
      }
      if (cVar1 == '\0') {
        _pmap_dealloc_seg_entry(piVar5);
      }
      _pmap_deallocate_mappings(piVar14,*(undefined4 *)((int)register0x00000038 + -0xc),1,0);
      piVar14[6] = 0;
      piVar14 = (int *)puVar13[1];
    }
    _splx(param_2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2375 start=0xf009dc04 */

/* WARNING: Removing unreachable block (ram,0xf009dc2c) */

undefined8 _check_ptbl(int *param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar4;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar1 = 0;
  iVar2 = 0;
  do {
    iVar3 = *(int *)(iVar2 + *param_1);
    if (iVar3 != 0) {
      _printf(aCheckPtblPtblA,*param_1,uVar1,iVar3);
      uVar4 = 1;
      goto locret_F009DC4C;
    }
    uVar1 = uVar1 + 1;
    iVar2 = iVar2 + 4;
  } while (uVar1 < 0x40);
  uVar4 = 0;
locret_F009DC4C:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=2376 start=0xf009dc54 */

/* WARNING: Removing unreachable block (ram,0xf009dc68) */

undefined8 _check_pmap(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (*(int *)(param_1 + 8) == 0) {
    _printf(aPmapIs0InSegE);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2377 start=0xf009dc78 */

/* WARNING: Removing unreachable block (ram,0xf009de54) */
/* WARNING: Removing unreachable block (ram,0xf009defc) */
/* WARNING: Removing unreachable block (ram,0xf009ded0) */
/* WARNING: Removing unreachable block (ram,0xf009deb0) */
/* WARNING: Removing unreachable block (ram,0xf009de94) */
/* WARNING: Removing unreachable block (ram,0xf009de7c) */
/* WARNING: Removing unreachable block (ram,0xf009dde4) */
/* WARNING: Removing unreachable block (ram,0xf009dd9c) */
/* WARNING: Removing unreachable block (ram,0xf009dd7c) */
/* WARNING: Removing unreachable block (ram,0xf009dd6c) */
/* WARNING: Removing unreachable block (ram,0xf009dd50) */
/* WARNING: Removing unreachable block (ram,0xf009dd38) */
/* WARNING: Removing unreachable block (ram,0xf009dd18) */
/* WARNING: Removing unreachable block (ram,0xf009dd40) */
/* WARNING: Removing unreachable block (ram,0xf009dd58) */
/* WARNING: Removing unreachable block (ram,0xf009dd74) */
/* WARNING: Removing unreachable block (ram,0xf009dd94) */
/* WARNING: Removing unreachable block (ram,0xf009ddc0) */
/* WARNING: Removing unreachable block (ram,0xf009de70) */
/* WARNING: Removing unreachable block (ram,0xf009de8c) */
/* WARNING: Removing unreachable block (ram,0xf009dea8) */
/* WARNING: Removing unreachable block (ram,0xf009deb8) */
/* WARNING: Removing unreachable block (ram,0xf009ded8) */
/* WARNING: Removing unreachable block (ram,0xf009df20) */
/* WARNING: Removing unreachable block (ram,0xf009df28) */
/* WARNING: Removing unreachable block (ram,0xf009dc98) */

undefined8 _pmap_expand(int *param_1,int *param_2,int param_3)

{
  byte bVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  undefined4 unaff_l0;
  int *piVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar7;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  piVar6 = (int *)0x0;
  *(int **)((int)register0x00000038 + 0x48) = param_2;
  if (param_3 == 1) goto locret_F009DF30;
  piVar2 = (int *)((int)dword_F013DECC + 1);
  dword_F013DECC = piVar2;
  _splvm();
  param_2 = (int *)*param_1;
  bVar1 = *(byte *)((int)register0x00000038 + 0x48);
  iVar4 = *param_2;
  uVar5 = *(uint *)(iVar4 + (uint)bVar1 * 4);
  uVar3 = uVar5 & 3;
  if (uVar3 == 1) {
    param_2 = (int *)0xff000000;
    if ((*(uint *)((int)register0x00000038 + 0x48) & 0xff000000) == param_1[3]) {
      piVar6 = (int *)param_1[1];
    }
    else {
      piVar6 = (int *)((uVar5 >> 2) << 6);
      _pmap_seg_entry();
      uVar3 = *(uint *)((int)register0x00000038 + 0x48);
      param_1[1] = (int)piVar6;
      param_1[3] = uVar3 & 0xff000000;
    }
  }
  else {
    if (uVar3 < 2) {
      if (uVar3 == 0) {
loc_F009DD40:
        _splx(piVar2);
        piVar6 = param_1;
        _pmap_alloc_seg_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),2);
        piVar2 = piVar6;
        _check_ptbl();
        if (piVar2 != (int *)0x0) {
          _panic(aPmapExpandPage);
        }
        piVar2 = piVar6;
        _check_pmap(piVar6);
        _splvm();
        if ((*(uint *)(iVar4 + (uint)bVar1 * 4) & 3) != 0) {
          _splx();
          _pmap_dealloc_seg_entry(piVar6);
          goto locret_F009DF30;
        }
        _set_ptp(param_2,*(undefined4 *)((int)register0x00000038 + 0x48),
                 *(int *)(piVar6[1] + 4) + (uint)*(byte *)((int)piVar6 + 0xe) * 0x100);
        piVar6[8] = (int)param_2;
        param_1[1] = (int)piVar6;
        param_1[3] = *(uint *)((int)register0x00000038 + 0x48) & 0xff000000;
        goto loc_F009DDEC;
      }
    }
    else if (uVar3 == 2) {
      _panic(aPmapExpandPteI);
      goto loc_F009DD40;
    }
    _panic(aPmapExpandPteR);
  }
loc_F009DDEC:
  if (param_3 == 2) goto locret_F009DF30;
  iVar4 = *piVar6;
  uVar7 = *(uint *)((int)register0x00000038 + 0x48) >> 0x10 & 0xfc;
  uVar5 = *(uint *)(iVar4 + uVar7);
  uVar3 = uVar5 & 3;
  if (uVar3 == 1) {
    if ((*(uint *)((int)register0x00000038 + 0x48) & 0xfffc0000) != param_1[4]) {
      iVar4 = (uVar5 >> 2) << 6;
      _pmap_seg_entry();
      uVar3 = *(uint *)((int)register0x00000038 + 0x48);
      param_1[2] = iVar4;
      param_1[4] = uVar3 & 0xfffc0000;
    }
  }
  else {
    if (uVar3 < 2) {
      if (uVar3 == 0) {
        _splx(piVar2);
        param_2 = param_1;
        _pmap_alloc_seg_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),3);
        piVar2 = param_2;
        _check_ptbl();
        if (piVar2 != (int *)0x0) {
          _panic(aPmapExpandPage_0);
        }
        piVar2 = param_2;
        _check_pmap(param_2);
        _splvm();
        if ((*(uint *)(iVar4 + uVar7) & 3) != 0) {
          _splx();
          _pmap_dealloc_seg_entry(param_2);
          goto locret_F009DF30;
        }
        _set_ptp(piVar6,*(undefined4 *)((int)register0x00000038 + 0x48),
                 *(int *)(param_2[1] + 4) + (uint)*(byte *)((int)param_2 + 0xe) * 0x100);
        param_2[8] = (int)piVar6;
        param_1[2] = (int)param_2;
        param_1[4] = *(uint *)((int)register0x00000038 + 0x48) & 0xfffc0000;
        goto loc_F009DF28;
      }
    }
    else if (uVar3 == 2) {
      _panic(aPmapExpandPteI_0);
      goto locret_F009DF30;
    }
    _panic(aPmapExpandPteR_0);
  }
loc_F009DF28:
  _splx(piVar2);
locret_F009DF30:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2378 start=0xf009df38 */

/* WARNING: Removing unreachable block (ram,0xf009dff0) */
/* WARNING: Removing unreachable block (ram,0xf009e1ec) */
/* WARNING: Removing unreachable block (ram,0xf009e1b4) */
/* WARNING: Removing unreachable block (ram,0xf009e42c) */
/* WARNING: Removing unreachable block (ram,0xf009e368) */
/* WARNING: Removing unreachable block (ram,0xf009e338) */
/* WARNING: Removing unreachable block (ram,0xf009e294) */
/* WARNING: Removing unreachable block (ram,0xf009e22c) */
/* WARNING: Removing unreachable block (ram,0xf009e190) */
/* WARNING: Removing unreachable block (ram,0xf009e0b8) */
/* WARNING: Removing unreachable block (ram,0xf009dfcc) */
/* WARNING: Removing unreachable block (ram,0xf009dfb8) */
/* WARNING: Removing unreachable block (ram,0xf009e16c) */
/* WARNING: Removing unreachable block (ram,0xf009e178) */
/* WARNING: Removing unreachable block (ram,0xf009e218) */
/* WARNING: Removing unreachable block (ram,0xf009e288) */
/* WARNING: Removing unreachable block (ram,0xf009e328) */
/* WARNING: Removing unreachable block (ram,0xf009e348) */
/* WARNING: Removing unreachable block (ram,0xf009e424) */
/* WARNING: Removing unreachable block (ram,0xf009e444) */
/* WARNING: Removing unreachable block (ram,0xf009e1d4) */
/* WARNING: Removing unreachable block (ram,0xf009dfe0) */
/* WARNING: Removing unreachable block (ram,0xf009df78) */
/* WARNING: Removing unreachable block (ram,0xf009df9c) */

undefined8
_pmap_enter_dev(int *param_1,int *param_2,uint param_3,uint param_4,int param_5,undefined4 param_6)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint *puVar5;
  uint uVar6;
  int iVar7;
  byte bVar8;
  int *piVar9;
  undefined4 unaff_l0;
  undefined4 *puVar10;
  undefined4 unaff_l1;
  int iVar11;
  undefined4 unaff_l3;
  uint uVar12;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(int **)((int)register0x00000038 + 0x48) = param_2;
  iVar11 = *(int *)((int)register0x00000038 + 0x5c);
  if (param_1 == (int *)0x0) goto locret_F009E44C;
  dword_F013DED0 = dword_F013DED0 + 1;
  if (param_5 == 0) {
    _pmap_remove(param_1,param_2,(int)param_2 + _page_size);
    goto locret_F009E44C;
  }
  if (((uint)param_2 & _page_size - 1U) != 0) {
    _panic(aPmapEnterDevVi);
  }
  puVar10 = (undefined4 *)0x0;
loc_F009DFAC:
  piVar1 = (int *)((param_4 & 0xf) << 0x14);
  uVar12 = (uint)piVar1 | param_3 >> 0xc;
  while( true ) {
    _splvm();
    param_2 = param_1;
    _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),0);
    if (param_2 != (int *)0x0) break;
    _splx(piVar1);
    piVar1 = param_1;
    _pmap_expand(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),3);
  }
  if (*(char *)((int)param_2 + 0xd) == '\x03') {
    iVar3 = *param_2;
    uVar2 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
  }
  else if (*(char *)((int)param_2 + 0xd) == '\x02') {
    iVar3 = *param_2;
    uVar2 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
  }
  else {
    iVar3 = *param_2;
    uVar2 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
  }
  puVar5 = (uint *)(iVar3 + uVar2);
  if ((*puVar5 & 3) == 2) {
    if (*(char *)((int)param_2 + 0xd) == '\x03') {
      if (*puVar5 >> 8 == uVar12) {
        uVar2 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf & 4;
        uVar6 = *(uint *)((int)param_2 + uVar2 + 0x10);
        uVar4 = 1 << ((byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e);
        uVar12 = uVar6 & uVar4;
        if ((iVar11 == 0) || (uVar12 != 0)) {
          if ((iVar11 == 0) && (uVar12 != 0)) {
            if (*(char *)((int)param_2 + 0xd) == '\x03') {
              uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
              bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
loc_F009E130:
              *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) =
                   *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) & ~(1 << bVar8);
            }
            else {
              if (*(char *)((int)param_2 + 0xd) == '\x02') {
                uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
                bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
                goto loc_F009E130;
              }
              bVar8 = *(byte *)((int)register0x00000038 + 0x48) >> 5;
              param_2[bVar8 + 4] =
                   param_2[bVar8 + 4] & ~(1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f));
            }
            _pmap_unwire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
          }
        }
        else {
          *(uint *)((int)param_2 + uVar2 + 0x10) = uVar6 | uVar4;
          _pmap_wire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
        }
        piVar9 = param_1;
        _vm_to_srmmu_prot(param_1,param_5);
        *(int **)((int)register0x00000038 + -0xc) = param_2;
        _update_pte((undefined *)((int)register0x00000038 + -0xc),
                    *(undefined4 *)((int)register0x00000038 + 0x48),piVar9,param_6);
        goto loc_F009E40C;
      }
      uVar2 = *puVar5;
    }
    else {
      uVar2 = *puVar5;
    }
  }
  else {
    uVar2 = *puVar5;
  }
  if ((uVar2 & 3) == 2) {
    _splx(piVar1);
    if (*(char *)((int)param_2 + 0xd) != '\x03') {
      *(int **)((int)register0x00000038 + -0xc) = param_2;
      _pmap_scatter_pte(param_1,(undefined *)((int)register0x00000038 + -0xc),
                        *(undefined4 *)((int)register0x00000038 + 0x48));
    }
    _pmap_remove(param_1,*(int *)((int)register0x00000038 + 0x48),
                 *(int *)((int)register0x00000038 + 0x48) + _page_size);
    goto loc_F009DFAC;
  }
  if (((param_4 != 0) || (_physmax <= param_3)) || (uVar2 = param_3, _vm_valid_page(), uVar2 == 0))
  goto loc_F009E334;
  uVar2 = param_3;
  _vm_mem_ppi();
  iVar3 = _pg_desc_tbl;
  iVar7 = uVar2 * 0x14;
  piVar9 = (int *)(_pg_desc_tbl + iVar7);
  if (piVar9[1] == 0) {
    uVar2 = *(uint *)((int)register0x00000038 + 0x48);
    piVar9[1] = (int)param_1;
    piVar9[2] = (uint)*(byte *)((int)piVar9 + 0xb) | (uVar2 >> 0xc) << 8;
    *(undefined4 *)(iVar3 + iVar7) = 0;
    goto loc_F009E2CC;
  }
  uVar2 = *(uint *)((int)register0x00000038 + 0x48);
  if (puVar10 == (undefined4 *)0x0) {
    _splx(piVar1);
    puVar10 = _pv_entry_zone;
    _zalloc();
    goto loc_F009DFAC;
  }
  puVar10[1] = param_1;
  puVar10[2] = (uint)*(byte *)((int)puVar10 + 0xb) | (uVar2 >> 0xc) << 8;
  *puVar10 = *(undefined4 *)(iVar3 + iVar7);
  *(undefined4 **)(iVar3 + iVar7) = puVar10;
  puVar10 = (undefined4 *)0x0;
loc_F009E2CC:
  if ((int *)piVar9[1] == param_1) {
    iVar3 = *(int *)((int)register0x00000038 + 0x48);
    if (((uint)piVar9[2] >> 8) * 0x1000 - iVar3 != 0) {
      iVar3 = *piVar9;
      goto loc_F009E2FC;
    }
  }
  else {
    iVar3 = *piVar9;
loc_F009E2FC:
    if ((*(int **)(iVar3 + 4) != param_1) ||
       ((*(uint *)(iVar3 + 8) >> 8) * 0x1000 - *(int *)((int)register0x00000038 + 0x48) != 0)) {
      _panic(aPmapEnterDevWr);
    }
loc_F009E334:
    iVar3 = *(int *)((int)register0x00000038 + 0x48);
  }
  _pmap_allocate_mapping(param_1,iVar3,iVar11);
  *(int **)((int)register0x00000038 + -0xc) = param_2;
  piVar9 = param_1;
  _vm_to_srmmu_prot(param_1,param_5);
  _set_pte((undefined *)((int)register0x00000038 + -0xc),
           *(undefined4 *)((int)register0x00000038 + 0x48),uVar12,piVar9,param_6,0,0);
  if (iVar11 != 0) {
    if (*(char *)((int)param_2 + 0xd) == '\x03') {
      uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
      bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
    }
    else {
      if (*(char *)((int)param_2 + 0xd) != '\x02') {
        bVar8 = *(byte *)((int)register0x00000038 + 0x48) >> 5;
        param_2[bVar8 + 4] =
             param_2[bVar8 + 4] | 1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f);
        goto loc_F009E40C;
      }
      uVar12 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
      bVar8 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
    }
    *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) =
         *(uint *)((int)param_2 + (uVar12 & 4) + 0x10) | 1 << bVar8;
  }
loc_F009E40C:
  if (_level3_only._0_4_ == 0) {
    *(int **)((int)register0x00000038 + -0xc) = param_2;
    _pmap_gather_pte(param_1,(undefined *)((int)register0x00000038 + -0xc),
                     *(undefined4 *)((int)register0x00000038 + 0x48));
  }
  _splx(piVar1);
  if (puVar10 != (undefined4 *)0x0) {
    _zfree(_pv_entry_zone,puVar10);
  }
locret_F009E44C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2379 start=0xf009e454 */

/* WARNING: Removing unreachable block (ram,0xf009e488) */

undefined8
_pmap_enter_range(undefined4 param_1,uint param_2,int param_3,undefined4 param_4,int param_5,
                 undefined4 param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 uVar1;
  undefined4 uVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar3;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar2 = *(undefined4 *)((int)register0x00000038 + 0x5c);
  uVar3 = param_2 + param_5;
  uVar1 = *(undefined4 *)((int)register0x00000038 + 0x60);
  for (; param_2 < uVar3; param_2 = param_2 + _page_size) {
    _pmap_enter_dev(param_1,param_2,param_3,param_4,param_6,uVar2,uVar1);
    param_3 = param_3 + _page_size;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2380 start=0xf009e4ac */

/* WARNING: Removing unreachable block (ram,0xf009e4c8) */

undefined8
_pmap_enter(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
           undefined4 param_5)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  _pmap_enter_dev(param_1,param_2,param_3,0,param_4,1,param_5);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2381 start=0xf009e4d8 */

/* WARNING: Removing unreachable block (ram,0xf009e52c) */

undefined8
_pmap_enter_cache_spec
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,int param_6)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DED4 = dword_F013DED4 + 1;
  _pmap_enter_dev(param_1,param_2,param_3,0,param_4,param_6 != 2,param_5);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2382 start=0xf009e53c */

/* WARNING: Removing unreachable block (ram,0xf009e594) */
/* WARNING: Removing unreachable block (ram,0xf009e57c) */

undefined8 _pmap_enter_shared_range(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar3;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DED8 = dword_F013DED8 + 1;
  uVar3 = param_2 + param_3 + _page_mask;
  uVar1 = ~_page_mask;
  uVar2 = _kernel_pmap;
  for (; param_2 < (uVar3 & uVar1); param_2 = param_2 + _page_size) {
    _kernel_pmap = uVar2;
    _pmap_resident_extract(uVar2,param_4);
    _pmap_enter(param_1,param_2,uVar2,3,1);
    param_4 = param_4 + _page_size;
    uVar2 = _kernel_pmap;
  }
  _kernel_pmap = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2383 start=0xf009e5b8 */

/* WARNING: Removing unreachable block (ram,0xf009e72c) */
/* WARNING: Removing unreachable block (ram,0xf009e6dc) */
/* WARNING: Removing unreachable block (ram,0xf009e654) */
/* WARNING: Removing unreachable block (ram,0xf009e5f0) */
/* WARNING: Removing unreachable block (ram,0xf009e5fc) */
/* WARNING: Removing unreachable block (ram,0xf009e66c) */
/* WARNING: Removing unreachable block (ram,0xf009e70c) */
/* WARNING: Removing unreachable block (ram,0xf009e748) */
/* WARNING: Removing unreachable block (ram,0xf009e5d0) */

undefined8 _pmap_copy_on_write(int *param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int *piVar6;
  uint *puVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  puVar7 = (uint *)0x0;
  if ((param_1 < _physmax) && (piVar6 = param_1, _vm_valid_page(), piVar6 != (int *)0x0)) {
    iVar1 = dword_F013DEDC + 1;
    dword_F013DEDC = iVar1;
    _splvm();
    piVar6 = param_1;
    _vm_mem_ppi();
    puVar5 = (undefined4 *)(_pg_desc_tbl + (int)piVar6 * 0x14);
    if (puVar5[1] != 0) {
      for (; puVar5 != (undefined4 *)0x0; puVar5 = (undefined4 *)*puVar5) {
        piVar6 = (int *)puVar5[1];
        *(uint *)((int)register0x00000038 + -0xc) = ((uint)puVar5[2] >> 8) << 0xc;
        do {
          do {
          } while (piVar6[6] != 0);
          piVar2 = piVar6 + 6;
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        param_1 = piVar6;
        _pmap_page_table_entry(piVar6,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (param_1 == (int *)0x0) {
loc_F009E6DC:
          _panic(aPmapCopyOnWrit_1);
        }
        else {
          if (*(char *)((int)param_1 + 0xd) == '\x03') {
            iVar4 = *param_1;
            uVar3 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
          }
          else if (*(char *)((int)param_1 + 0xd) == '\x02') {
            iVar4 = *param_1;
            uVar3 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
          }
          else {
            iVar4 = *param_1;
            uVar3 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
          }
          puVar7 = (uint *)(iVar4 + uVar3);
          if ((*puVar7 & 3) != 2) goto loc_F009E6DC;
        }
        uVar3 = *puVar7 & 0x1c;
        if (((uVar3 == 4) || (uVar3 == 0xc)) || (uVar3 == 0x1c)) {
          piVar2 = piVar6;
          _vm_to_srmmu_prot(piVar6,1);
          *(int **)((int)register0x00000038 + -0x10) = param_1;
          _update_pte((undefined *)((int)register0x00000038 + -0x10),
                      *(undefined4 *)((int)register0x00000038 + -0xc),piVar2,*puVar7 >> 7 & 1);
        }
        piVar6[6] = 0;
      }
    }
    _splx(iVar1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2384 start=0xf009e758 */

/* WARNING: Removing unreachable block (ram,0xf009e8f0) */
/* WARNING: Removing unreachable block (ram,0xf009e834) */
/* WARNING: Removing unreachable block (ram,0xf009e7b8) */
/* WARNING: Removing unreachable block (ram,0xf009e7d0) */
/* WARNING: Removing unreachable block (ram,0xf009e8ac) */
/* WARNING: Removing unreachable block (ram,0xf009e94c) */
/* WARNING: Removing unreachable block (ram,0xf009e788) */

undefined8 _pmap_move_page(uint param_1,int param_2,uint param_3)

{
  char cVar1;
  int *piVar2;
  byte bVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  uint *puVar7;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(uint *)((int)register0x00000038 + 0x44) = param_1;
  dword_F013DEE0 = dword_F013DEE0 + 1;
  if ((param_3 & _page_mask) != 0) {
    _panic(aPmapMovePagePa);
  }
  uVar4 = *(uint *)((int)register0x00000038 + 0x44);
  param_3 = uVar4 + param_3;
  piVar2 = _kernel_pmap;
  while (uVar4 < param_3) {
    _kernel_pmap = piVar2;
    _pmap_page_table_entry(piVar2,uVar4,0);
    if (piVar2 == (int *)0x0) {
      _panic(aPmapMovePageFr);
      cVar1 = cRam0000000d;
    }
    else {
      cVar1 = *(char *)((int)piVar2 + 0xd);
    }
    if (cVar1 == '\x03') {
      iVar5 = *piVar2;
      uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 10 & 0xfc;
    }
    else if (cVar1 == '\x02') {
      iVar5 = *piVar2;
      uVar4 = *(word *)((int)register0x00000038 + 0x44) & 0xfc;
    }
    else {
      iVar5 = *piVar2;
      uVar4 = (uint)*(byte *)((int)register0x00000038 + 0x44) << 2;
    }
    puVar7 = (uint *)(iVar5 + uVar4);
    if ((*puVar7 & 3) != 2) {
      _panic(aPmapMovePageNu);
    }
    if (*(char *)((int)piVar2 + 0xd) == '\x03') {
      uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 0xf & 4;
      bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x44) >> 0xc) & 0x1e;
    }
    else {
      if (*(char *)((int)piVar2 + 0xd) == '\x02') {
        bVar3 = (byte)(*(uint *)((int)register0x00000038 + 0x44) >> 0x12);
        uVar4 = *(uint *)((int)register0x00000038 + 0x44) >> 0x15 & 4;
      }
      else {
        bVar3 = *(byte *)((int)register0x00000038 + 0x44);
        uVar4 = (uint)(bVar3 >> 5) << 2;
      }
      bVar3 = bVar3 & 0x1f;
    }
    uVar6 = *(uint *)((int)piVar2 + uVar4 + 0x10);
    param_1 = (uint)*(byte *)((int)piVar2 + 0xd);
    uVar4 = *puVar7 >> 2 & 7;
    _srmmu_to_vm_prot(uVar4);
    if (param_1 == 3) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + _page_size;
    }
    else if (param_1 == 2) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x40000;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x1000000;
    }
    _pmap_remove(_kernel_pmap,*(undefined4 *)((int)register0x00000038 + 0x44),iVar5);
    iVar5 = _page_size;
    if ((param_1 != 3) && (iVar5 = 0x1000000, param_1 == 2)) {
      iVar5 = 0x40000;
    }
    _pmap_enter_range(_kernel_pmap,param_2,(*puVar7 >> 8) << 0xc,*puVar7 >> 0x1c,iVar5,uVar4,
                      *puVar7 >> 7 & 1,uVar6 & 1 << bVar3);
    if (param_1 == 3) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + _page_size;
    }
    else if (param_1 == 2) {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x40000;
    }
    else {
      iVar5 = *(int *)((int)register0x00000038 + 0x44) + 0x1000000;
    }
    *(int *)((int)register0x00000038 + 0x44) = iVar5;
    if (param_1 == 3) {
      param_2 = param_2 + _page_size;
    }
    else if (param_1 == 2) {
      param_2 = param_2 + 0x40000;
    }
    else {
      param_2 = param_2 + 0x1000000;
    }
    piVar2 = _kernel_pmap;
    uVar4 = *(uint *)((int)register0x00000038 + 0x44);
  }
  _kernel_pmap = piVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2385 start=0xf009e9c4 */

/* WARNING: Removing unreachable block (ram,0xf009ebb4) */
/* WARNING: Removing unreachable block (ram,0xf009eb20) */
/* WARNING: Removing unreachable block (ram,0xf009ea1c) */
/* WARNING: Removing unreachable block (ram,0xf009ea50) */
/* WARNING: Removing unreachable block (ram,0xf009eb40) */
/* WARNING: Removing unreachable block (ram,0xf009e9f4) */
/* WARNING: Removing unreachable block (ram,0xf009ea00) */

undefined8 _pmap_protect(int *param_1,uint *param_2,uint *param_3,int param_4)

{
  char cVar1;
  int iVar2;
  int *piVar3;
  uint *puVar4;
  uint uVar5;
  int *piVar6;
  int iVar7;
  undefined4 unaff_l0;
  uint *puVar8;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if (param_1 != (int *)0x0) {
    iVar2 = dword_F013DEE4 + 1;
    dword_F013DEE4 = iVar2;
    if (param_4 == 0) {
      _pmap_remove(param_1,param_2,param_3);
    }
    else {
      _splvm();
      do {
        do {
        } while (param_1[6] != 0);
        piVar3 = param_1 + 6;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      *(uint **)((int)register0x00000038 + -0xc) = param_2;
      puVar4 = param_2;
joined_r0xf009ea30:
      if (puVar4 < param_3) {
        piVar3 = param_1;
        _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (piVar3 != (int *)0x0) goto loc_f009ea5c;
        *(uint *)((int)register0x00000038 + -0xc) =
             *(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000;
        goto loc_F009EBA0;
      }
      param_1[6] = 0;
      _splx(iVar2);
    }
  }
  return CONCAT44(param_2,param_1);
loc_f009ea5c:
  if (*(char *)((int)piVar3 + 0xd) == '\x03') {
    puVar8 = (uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x40000U & 0xfffc0000);
  }
  else {
    puVar8 = (uint *)0xffffe000;
    if (*(char *)((int)piVar3 + 0xd) == '\x02') {
      puVar8 = (uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x1000000U & 0xff000000);
    }
  }
  if (param_3 < puVar8) {
    puVar8 = param_3;
  }
  puVar4 = *(uint **)((int)register0x00000038 + -0xc);
  if (puVar4 < puVar8) {
    do {
      if (*(char *)((int)piVar3 + 0xd) == '\x03') {
        iVar7 = *piVar3;
        uVar5 = (uint)puVar4 >> 10 & 0xfc;
      }
      else if (*(char *)((int)piVar3 + 0xd) == '\x02') {
        iVar7 = *piVar3;
        uVar5 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
      }
      else {
        iVar7 = *piVar3;
        uVar5 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
      }
      param_2 = (uint *)(iVar7 + uVar5);
      if ((*param_2 & 3) == 2) {
        piVar6 = param_1;
        _vm_to_srmmu_prot(param_1,1);
        *(int **)((int)register0x00000038 + -0x10) = piVar3;
        _update_pte((undefined *)((int)register0x00000038 + -0x10),
                    *(undefined4 *)((int)register0x00000038 + -0xc),piVar6,*param_2 >> 7 & 1);
        cVar1 = *(char *)((int)piVar3 + 0xd);
      }
      else {
        cVar1 = *(char *)((int)piVar3 + 0xd);
      }
      if (cVar1 == '\x03') {
        puVar4 = (uint *)((*(uint *)((int)register0x00000038 + -0xc) & ~_page_mask) + _page_size);
      }
      else if (cVar1 == '\x02') {
        puVar4 = (uint *)((*(uint *)((int)register0x00000038 + -0xc) & 0xfffc0000) + 0x40000);
      }
      else {
        puVar4 = (uint *)((*(uint *)((int)register0x00000038 + -0xc) & 0xff000000) + 0x1000000);
      }
      *(uint **)((int)register0x00000038 + -0xc) = puVar4;
    } while (puVar4 < puVar8);
loc_F009EBA0:
    puVar4 = *(uint **)((int)register0x00000038 + -0xc);
  }
  goto joined_r0xf009ea30;
}
/* GHIDRADEC_FUNCTION index=2386 start=0xf009ebc4 */

/* WARNING: Removing unreachable block (ram,0xf009ec18) */
/* WARNING: Removing unreachable block (ram,0xf009ec0c) */

undefined8 _pmap_page_protect(undefined4 param_1,int param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DEE8 = dword_F013DEE8 + 1;
  if (param_2 == 5) {
loc_F009EC0C:
    _pmap_copy_on_write(param_1);
  }
  else {
    if (param_2 < 6) {
      if (param_2 == 1) goto loc_F009EC0C;
    }
    else if (param_2 == 7) goto locret_F009EC20;
    _pmap_remove_all(param_1);
  }
locret_F009EC20:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2387 start=0xf009ec28 */

/* WARNING: Removing unreachable block (ram,0xf009edc0) */
/* WARNING: Removing unreachable block (ram,0xf009eca0) */
/* WARNING: Removing unreachable block (ram,0xf009ec84) */
/* WARNING: Removing unreachable block (ram,0xf009ec54) */
/* WARNING: Removing unreachable block (ram,0xf009ec6c) */
/* WARNING: Removing unreachable block (ram,0xf009ec98) */
/* WARNING: Removing unreachable block (ram,0xf009ee6c) */
/* WARNING: Removing unreachable block (ram,0xf009ee74) */
/* WARNING: Removing unreachable block (ram,0xf009ec40) */

undefined8 _pmap_change_wiring(int param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  byte bVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  iVar2 = dword_F013DEEC + 1;
  dword_F013DEEC = iVar2;
  _splvm();
  iVar3 = param_1;
  _pmap_page_table_entry(param_1,*(undefined4 *)((int)register0x00000038 + 0x48),0);
  if (iVar3 == 0) {
    _panic(aPmapChangeWiri);
    cVar1 = cRam0000000d;
  }
  else {
    cVar1 = *(char *)(iVar3 + 0xd);
  }
  if (cVar1 == '\x03') {
    cVar1 = *(char *)(iVar3 + 0xd);
  }
  else {
    _splx(iVar2);
    *(int *)((int)register0x00000038 + -0xc) = iVar3;
    iVar3 = param_1;
    _pmap_scatter_pte(param_1,(undefined *)((int)register0x00000038 + -0xc),
                      *(undefined4 *)((int)register0x00000038 + 0x48));
    iVar2 = iVar3;
    _splvm();
    cVar1 = *(char *)(iVar3 + 0xd);
  }
  if (cVar1 == '\x03') {
    uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf & 4;
    bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
  }
  else {
    bVar5 = *(byte *)((int)register0x00000038 + 0x48);
    if (cVar1 == '\x02') {
      bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12);
      uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15 & 4;
    }
    else {
      uVar4 = (uint)(bVar5 >> 5) << 2;
    }
    bVar5 = bVar5 & 0x1f;
  }
  uVar4 = *(uint *)(uVar4 + iVar3 + 0x10) & 1 << bVar5;
  if ((param_3 == 0) || (uVar4 != 0)) {
    if ((param_3 != 0) || (uVar4 == 0)) goto loc_F009EE74;
    if (*(char *)(iVar3 + 0xd) == '\x03') {
      uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
      bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
loc_F009EE30:
      iVar6 = (uVar4 & 4) + iVar3;
      *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) & ~(1 << bVar5);
    }
    else {
      if (*(char *)(iVar3 + 0xd) == '\x02') {
        uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
        bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
        goto loc_F009EE30;
      }
      iVar6 = (uint)(*(byte *)((int)register0x00000038 + 0x48) >> 5) * 4 + iVar3;
      *(uint *)(iVar6 + 0x10) =
           *(uint *)(iVar6 + 0x10) & ~(1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f));
    }
    _pmap_unwire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
    goto loc_F009EE74;
  }
  if (*(char *)(iVar3 + 0xd) == '\x03') {
    uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0xf;
    bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0xc) & 0x1e;
loc_F009ED84:
    iVar6 = (uVar4 & 4) + iVar3;
    *(uint *)(iVar6 + 0x10) = *(uint *)(iVar6 + 0x10) | 1 << bVar5;
  }
  else {
    if (*(char *)(iVar3 + 0xd) == '\x02') {
      uVar4 = *(uint *)((int)register0x00000038 + 0x48) >> 0x15;
      bVar5 = (byte)(*(uint *)((int)register0x00000038 + 0x48) >> 0x12) & 0x1f;
      goto loc_F009ED84;
    }
    iVar6 = (uint)(*(byte *)((int)register0x00000038 + 0x48) >> 5) * 4 + iVar3;
    *(uint *)(iVar6 + 0x10) =
         *(uint *)(iVar6 + 0x10) | 1 << (*(byte *)((int)register0x00000038 + 0x48) & 0x1f);
  }
  _pmap_wire_mapping(param_1,*(undefined4 *)((int)register0x00000038 + 0x48));
loc_F009EE74:
  _splx(iVar2);
  return CONCAT44(iVar3,param_1);
}
/* GHIDRADEC_FUNCTION index=2388 start=0xf009ee84 */

/* WARNING: Removing unreachable block (ram,0xf009eea8) */

undefined8 _pmap_resident_extract(int *param_1,undefined4 param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar3;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  dword_F013DEF0 = dword_F013DEF0 + 1;
  _pmap_page_table_entry(param_1,param_2,0);
  if (param_1 == (int *)0x0) {
    iVar3 = 0;
  }
  else {
    if (*(char *)((int)param_1 + 0xd) == '\x03') {
      iVar3 = *param_1;
      uVar1 = *(uint *)((int)register0x00000038 + 0x48) >> 10 & 0xfc;
    }
    else if (*(char *)((int)param_1 + 0xd) == '\x02') {
      iVar3 = *param_1;
      uVar1 = *(word *)((int)register0x00000038 + 0x48) & 0xfc;
    }
    else {
      iVar3 = *param_1;
      uVar1 = (uint)*(byte *)((int)register0x00000038 + 0x48) << 2;
    }
    uVar1 = *(uint *)(iVar3 + uVar1);
    iVar3 = 0;
    if ((uVar1 & 3) == 2) {
      if (*(char *)((int)param_1 + 0xd) == '\x03') {
        uVar2 = (uVar1 >> 8) << 0xc;
        uVar1 = *(uint *)((int)register0x00000038 + 0x48) & 0xfff;
      }
      else {
        uVar1 = (uVar1 >> 8) << 0xc;
        uVar2 = *(uint *)((int)register0x00000038 + 0x48) & 0x3ffff;
      }
      iVar3 = uVar1 + uVar2;
    }
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2389 start=0xf009ef58 */

/* WARNING: Removing unreachable block (ram,0xf009efa0) */
/* WARNING: Removing unreachable block (ram,0xf009ef8c) */
/* WARNING: Removing unreachable block (ram,0xf009efb0) */
/* WARNING: Removing unreachable block (ram,0xf009ef70) */

undefined8 _pmap_extract(int param_1,undefined4 param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  iVar1 = dword_F013DEF4 + 1;
  dword_F013DEF4 = iVar1;
  _splvm();
  do {
    do {
    } while (*(int *)(param_1 + 0x18) != 0);
    piVar2 = (int *)(param_1 + 0x18);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  iVar3 = param_1;
  _pmap_resident_extract(param_1,param_2);
  *(undefined4 *)(param_1 + 0x18) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=2390 start=0xf009efc0 */

/* WARNING: Removing unreachable block (ram,0xf009f0d4) */
/* WARNING: Removing unreachable block (ram,0xf009f040) */
/* WARNING: Removing unreachable block (ram,0xf009eff4) */
/* WARNING: Removing unreachable block (ram,0xf009f058) */
/* WARNING: Removing unreachable block (ram,0xf009f220) */
/* WARNING: Removing unreachable block (ram,0xf009efd8) */

undefined8 _pmap_clear_page_attrib(int *param_1,uint param_2)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
  undefined *puVar4;
  byte bVar5;
  int iVar6;
  undefined4 unaff_l0;
  int *piVar7;
  undefined4 unaff_l1;
  int *piVar8;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DEF8 = dword_F013DEF8 + 1;
  piVar1 = param_1;
  _vm_mem_ppi();
  piVar7 = (int *)(_pg_desc_tbl + (int)piVar1 * 0x14);
  _splvm();
  *(byte *)(piVar7 + 4) = *(byte *)(piVar7 + 4) & ~(byte)param_2;
  piVar8 = (int *)piVar7[1];
  if (piVar8 == (int *)0x0) {
loc_F009F220:
    _splx(piVar1);
    return CONCAT44(param_2,param_1);
  }
  uVar2 = piVar7[2];
  do {
    *(uint *)((int)register0x00000038 + -0xc) = (uVar2 >> 8) << 0xc;
    do {
      do {
      } while (piVar8[6] != 0);
      piVar3 = piVar8 + 6;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    param_1 = piVar8;
    _pmap_page_table_entry(piVar8,*(undefined4 *)((int)register0x00000038 + -0xc),0);
    if (param_1 != (int *)0x0) {
      if (*(char *)((int)param_1 + 0xd) == '\x03') {
        iVar6 = *param_1;
        uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
      }
      else if (*(char *)((int)param_1 + 0xd) == '\x02') {
        iVar6 = *param_1;
        uVar2 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
      }
      else {
        iVar6 = *param_1;
        uVar2 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
      }
      puVar4 = (undefined *)((int)register0x00000038 + -0x10);
      if ((*(uint *)(iVar6 + uVar2) & 3) == 2) {
        *(int **)((int)register0x00000038 + -0x10) = param_1;
        _set_pte_modref(puVar4,*(undefined4 *)((int)register0x00000038 + -0xc),param_2 & 1,
                        param_2 & 2);
        if (puVar4 != (undefined *)0x0) {
          if (puVar4 == (undefined *)0x2) {
            if (*(char *)((int)param_1 + 0xd) == '\x03') {
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
            }
            else {
              if (*(char *)((int)param_1 + 0xd) != '\x02') {
                bVar5 = *(byte *)((int)register0x00000038 + -0xc) >> 5;
                param_1[bVar5 + 0xc] =
                     param_1[bVar5 + 0xc] | 1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f);
                goto loc_F009F174;
              }
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
            }
            *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) =
                 *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) | 1 << bVar5;
          }
loc_F009F174:
          if (puVar4 == (undefined *)0x1) {
            if (*(char *)((int)param_1 + 0xd) == '\x03') {
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
            }
            else {
              if (*(char *)((int)param_1 + 0xd) != '\x02') {
                bVar5 = *(byte *)((int)register0x00000038 + -0xc) >> 5;
                param_1[bVar5 + 0xc] =
                     param_1[bVar5 + 0xc] &
                     ~(1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f));
                goto loc_F009F1FC;
              }
              uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
              bVar5 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
            }
            *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) =
                 *(uint *)((int)param_1 + (uVar2 & 4) + 0x18) & ~(1 << bVar5);
          }
        }
      }
    }
loc_F009F1FC:
    piVar8[6] = 0;
    piVar7 = (int *)*piVar7;
    if ((piVar7 == (int *)0x0) || (piVar8 = (int *)piVar7[1], piVar8 == (int *)0x0))
    goto loc_F009F220;
    uVar2 = piVar7[2];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=2391 start=0xf009f230 */

/* WARNING: Removing unreachable block (ram,0xf009f284) */
/* WARNING: Removing unreachable block (ram,0xf009f2ec) */
/* WARNING: Removing unreachable block (ram,0xf009f294) */
/* WARNING: Removing unreachable block (ram,0xf009f2d4) */
/* WARNING: Removing unreachable block (ram,0xf009f45c) */
/* WARNING: Removing unreachable block (ram,0xf009f49c) */
/* WARNING: Removing unreachable block (ram,0xf009f248) */

undefined8 _pmap_check_page_attrib(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int *piVar3;
  byte bVar4;
  int iVar5;
  uint *puVar6;
  uint *puVar7;
  undefined4 unaff_l0;
  int *piVar8;
  undefined4 unaff_l1;
  int *piVar9;
  int *piVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DEFC = dword_F013DEFC + 1;
  _vm_mem_ppi();
  piVar8 = (int *)(_pg_desc_tbl + param_1 * 0x14);
  uVar1 = *(byte *)(piVar8 + 4) & param_2;
  uVar11 = 1;
  if (uVar1 != param_2) {
    _splvm();
    piVar9 = (int *)piVar8[1];
    if (piVar9 != (int *)0x0) {
      uVar2 = piVar8[2];
      piVar10 = piVar8;
      do {
        *(uint *)((int)register0x00000038 + -0xc) = (uVar2 >> 8) << 0xc;
        do {
          do {
          } while (piVar9[6] != 0);
          piVar3 = piVar9 + 6;
          _simple_lock_try();
        } while (piVar3 == (int *)0x0);
        piVar3 = piVar9;
        _pmap_page_table_entry(piVar9,*(undefined4 *)((int)register0x00000038 + -0xc),0);
        if (piVar3 != (int *)0x0) {
          if (*(char *)((int)piVar3 + 0xd) == '\x03') {
            iVar5 = *piVar3;
            uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 10 & 0xfc;
          }
          else if (*(char *)((int)piVar3 + 0xd) == '\x02') {
            iVar5 = *piVar3;
            uVar2 = *(word *)((int)register0x00000038 + -0xc) & 0xfc;
          }
          else {
            iVar5 = *piVar3;
            uVar2 = (uint)*(byte *)((int)register0x00000038 + -0xc) << 2;
          }
          puVar6 = (uint *)(iVar5 + uVar2);
          if ((*puVar6 & 3) == 2) {
            puVar7 = puVar6 + 1;
            if (*(char *)((int)piVar3 + 0xd) == '\x03') {
              puVar7 = puVar6 + _pmap_info;
            }
            while (puVar6 < puVar7) {
              if ((*puVar6 & 0x40) == 0) {
                if (*(char *)((int)piVar3 + 0xd) == '\x03') {
                  uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0xf;
                  bVar4 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0xc) & 0x1e;
loc_F009F3D8:
                  if ((*(uint *)((int)piVar3 + (uVar2 & 4) + 0x18) & 1 << bVar4) != 0) {
                    bVar4 = *(byte *)(piVar8 + 4);
                    goto loc_F009F41C;
                  }
                  uVar2 = *puVar6;
                }
                else {
                  if (*(char *)((int)piVar3 + 0xd) == '\x02') {
                    uVar2 = *(uint *)((int)register0x00000038 + -0xc) >> 0x15;
                    bVar4 = (byte)(*(uint *)((int)register0x00000038 + -0xc) >> 0x12) & 0x1f;
                    goto loc_F009F3D8;
                  }
                  if ((piVar3[(*(byte *)((int)register0x00000038 + -0xc) >> 5) + 0xc] &
                      1 << (*(byte *)((int)register0x00000038 + -0xc) & 0x1f)) != 0) {
                    bVar4 = *(byte *)(piVar8 + 4);
                    goto loc_F009F41C;
                  }
                  uVar2 = *puVar6;
                }
              }
              else {
                bVar4 = *(byte *)(piVar8 + 4);
loc_F009F41C:
                *(byte *)(piVar8 + 4) = bVar4 | 1;
                uVar2 = *puVar6;
              }
              puVar6 = puVar6 + 1;
              if ((uVar2 & 0x20) != 0) {
                *(byte *)(piVar8 + 4) = *(byte *)(piVar8 + 4) | 2;
              }
            }
            if (*(char *)((int)piVar3 + 0xd) != '\x03') {
              _panic(aPmapCheckPageA);
            }
            if ((*(byte *)(piVar8 + 4) & param_2) == param_2) {
              piVar9[6] = 0;
              _splx(uVar1);
              uVar11 = 1;
              goto locret_F009F4A8;
            }
          }
        }
        piVar9[6] = 0;
        piVar10 = (int *)*piVar10;
        if ((piVar10 == (int *)0x0) || (piVar9 = (int *)piVar10[1], piVar9 == (int *)0x0)) break;
        uVar2 = piVar10[2];
      } while( true );
    }
    _splx(uVar1);
    uVar11 = 0;
  }
locret_F009F4A8:
  return CONCAT44(param_2,uVar11);
}
/* GHIDRADEC_FUNCTION index=2392 start=0xf009f4b0 */

/* WARNING: Removing unreachable block (ram,0xf009f4dc) */
/* WARNING: Removing unreachable block (ram,0xf009f4c8) */

undefined8 _pmap_clear_modify(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if ((param_1 < _physmax) && (uVar1 = param_1, _vm_valid_page(), uVar1 != 0)) {
    _pmap_clear_page_attrib(param_1,1);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2393 start=0xf009f4ec */

/* WARNING: Removing unreachable block (ram,0xf009f518) */
/* WARNING: Removing unreachable block (ram,0xf009f504) */

undefined8 _pmap_is_modified(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar2 = 0;
  if ((param_1 < _physmax) && (uVar1 = param_1, _vm_valid_page(), uVar1 != 0)) {
    _pmap_check_page_attrib(param_1,1);
    uVar2 = (uint)(param_1 != 0);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2394 start=0xf009f530 */

/* WARNING: Removing unreachable block (ram,0xf009f55c) */
/* WARNING: Removing unreachable block (ram,0xf009f548) */

undefined8 _pmap_clear_reference(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  if ((param_1 < _physmax) && (uVar1 = param_1, _vm_valid_page(), uVar1 != 0)) {
    _pmap_clear_page_attrib(param_1,2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2395 start=0xf009f56c */

/* WARNING: Removing unreachable block (ram,0xf009f598) */
/* WARNING: Removing unreachable block (ram,0xf009f584) */

undefined8 _pmap_is_referenced(uint param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  uVar2 = 0;
  if ((param_1 < _physmax) && (uVar1 = param_1, _vm_valid_page(), uVar1 != 0)) {
    _pmap_check_page_attrib(param_1,2);
    uVar2 = (uint)(param_1 != 0);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=2396 start=0xf009f5b0 */

/* WARNING: Removing unreachable block (ram,0xf009f5e0) */

undefined8 _pmap_collect(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 *puVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DF00 = dword_F013DF00 + 1;
  puVar1 = _garbage;
  if ((undefined4 **)_garbage != &_garbage) {
    do {
      _garbage_collect(puVar1);
      puVar1 = (undefined4 *)*puVar1;
    } while ((undefined4 **)puVar1 != &_garbage);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2397 start=0xf009f600 */

/* WARNING: Removing unreachable block (ram,0xf009f704) */
/* WARNING: Removing unreachable block (ram,0xf009f6bc) */
/* WARNING: Removing unreachable block (ram,0xf009f6fc) */
/* WARNING: Removing unreachable block (ram,0xf009f70c) */
/* WARNING: Removing unreachable block (ram,0xf009f670) */

undefined8 _pmap_activate(int *param_1,int param_2)

{
  undefined4 unaff_l0;
  int *piVar1;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DF04 = dword_F013DF04 + 1;
  if (((_active_pmap != param_1) || (param_1[5] == 0)) || (*(int **)(param_1[5] + 8) != param_1)) {
    DAT_f013df08 = DAT_f013df08 + 1;
    do {
      do {
      } while (param_1[6] != 0);
      piVar1 = param_1 + 6;
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if ((param_1 == _kernel_pmap) || (*(int *)(*(int *)(param_2 + 0xc) + 0x4c) != 0)) {
      piVar1 = (int *)0x0;
      param_1[5] = _context_table;
    }
    else {
      piVar1 = param_1;
      _pmap_alloc_context();
      *(uint *)(_contexts + (int)piVar1 * 4) =
           (*(int *)(*(int *)(*param_1 + 4) + 4) + (uint)*(byte *)(*param_1 + 0xe) * 0x400 >> 6) <<
           2 | 1;
    }
    _mmu_flushctx(piVar1);
    _vac_ctxflush(piVar1);
    _mmu_setctx(piVar1);
    _active_pmap = param_1;
    param_1[6] = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2398 start=0xf009f728 */

undefined8 _pmap_deactivate(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=2399 start=0xf009f734 */

undefined8 _pmap_kernel(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  if (!in_DECOMPILE_MODE) {
    *(undefined4 *)(in_CWP * 0x40 + 0x8000) = unaff_i0;
    *(undefined4 *)((in_CWP * 0x10 + 1) * 4 + 0x8000) = unaff_i1;
    *(undefined4 *)((in_CWP * 0x10 + 2) * 4 + 0x8000) = unaff_i2;
    *(undefined4 *)((in_CWP * 0x10 + 3) * 4 + 0x8000) = unaff_i3;
    *(undefined4 *)((in_CWP * 0x10 + 4) * 4 + 0x8000) = unaff_i4;
    *(undefined4 *)((in_CWP * 0x10 + 5) * 4 + 0x8000) = unaff_i5;
    *(undefined4 *)((in_CWP * 0x10 + 6) * 4 + 0x8000) = unaff_fp;
    *(undefined4 *)((in_CWP * 0x10 + 7) * 4 + 0x8000) = unaff_i7;
    *(undefined4 *)((in_CWP * 0x10 + 8) * 4 + 0x8000) = unaff_l0;
    *(undefined4 *)((in_CWP * 0x10 + 9) * 4 + 0x8000) = unaff_l1;
    *(undefined4 *)((in_CWP * 0x10 + 10) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xb) * 4 + 0x8000) = unaff_l3;
    *(undefined4 *)((in_CWP * 0x10 + 0xc) * 4 + 0x8000) = unaff_l4;
    *(undefined4 *)((in_CWP * 0x10 + 0xd) * 4 + 0x8000) = unaff_l5;
    *(undefined4 *)((in_CWP * 0x10 + 0xe) * 4 + 0x8000) = unaff_l6;
    *(undefined4 *)((in_CWP * 0x10 + 0xf) * 4 + 0x8000) = unaff_l7;
  }
  dword_F013DF10 = dword_F013DF10 + 1;
  return CONCAT44(param_2,_kernel_pmap);
}

