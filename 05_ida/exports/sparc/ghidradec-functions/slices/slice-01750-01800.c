/* GHIDRADEC_FUNCTION index=1750 start=0xf0080234 */

undefined8 _mach_server(uint *param_1,uint *param_2)

{
  code *pcVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  *param_2 = (*param_1 & 0xff00) >> 8;
  param_2[1] = 0x20;
  param_2[2] = param_1[3];
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = param_1[5] + 100;
  param_2[6] = dword_F011166C;
  if ((param_1[5] - 2000 < 0x68) &&
     (pcVar1 = *(code **)(param_1[5] * 4 + -0xfef0a74), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1751 start=0xf00802d0 */

undefined8 _mach_server_routine(int param_1,undefined4 param_2)

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
  undefined4 uVar2;
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
  uVar1 = *(int *)(param_1 + 0x14) - 2000;
  if (uVar1 < 0x68) {
    uVar2 = *(undefined4 *)(unk_F01114CC + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1752 start=0xf0080dd4 */

undefined8 _mach_debug_server(uint *param_1,uint *param_2)

{
  code *pcVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar2;
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
  *param_2 = (*param_1 & 0xff00) >> 8;
  param_2[1] = 0x20;
  param_2[2] = param_1[3];
  param_2[3] = 0;
  param_2[4] = 0;
  param_2[5] = param_1[5] + 100;
  param_2[6] = dword_F0111790;
  if ((param_1[5] - 3000 < 0x16) &&
     (pcVar1 = *(code **)(param_1[5] * 4 + -0xfef17a8), pcVar1 != (code *)0x0)) {
    (*pcVar1)(param_1,param_2);
    uVar2 = 1;
  }
  else {
    param_2[7] = 0xfffffed1;
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1753 start=0xf0080e70 */

undefined8 _mach_debug_server_routine(int param_1,undefined4 param_2)

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
  undefined4 uVar2;
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
  uVar1 = *(int *)(param_1 + 0x14) - 3000;
  if (uVar1 < 0x16) {
    uVar2 = *(undefined4 *)(unk_F0111738 + uVar1 * 4);
  }
  else {
    uVar2 = 0;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1754 start=0xf0081058 */

/* WARNING: Removing unreachable block (ram,0xf00810a4) */
/* WARNING: Removing unreachable block (ram,0xf008108c) */
/* WARNING: Removing unreachable block (ram,0xf00810d0) */
/* WARNING: Removing unreachable block (ram,0xf008107c) */

undefined8 _ux_handler_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
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
  dword_F0130F5C = 0;
  _ux_exception_port = 0;
  _kernel_task_create(_kernel_task,0);
  _kernel_thread();
  do {
    do {
    } while (dword_F0130F5C != 0);
    puVar1 = &dword_F0130F5C;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  if (_ux_exception_port == 0) {
    _thread_sleep(&_ux_exception_port,&dword_F0130F5C,0);
  }
  else {
    dword_F0130F5C = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1755 start=0xf00810ec */

/* WARNING: Removing unreachable block (ram,0xf0081190) */
/* WARNING: Removing unreachable block (ram,0xf008116c) */
/* WARNING: Removing unreachable block (ram,0xf0081130) */
/* WARNING: Removing unreachable block (ram,0xf0081124) */
/* WARNING: Removing unreachable block (ram,0xf0081154) */
/* WARNING: Removing unreachable block (ram,0xf0081174) */
/* WARNING: Removing unreachable block (ram,0xf008119c) */
/* WARNING: Removing unreachable block (ram,0xf0081110) */

undefined8
_catch_exception_raise
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6)

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
  undefined4 uVar2;
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
  uVar2 = 0;
  *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
  iVar1 = *(int *)(_active_threads + 0xc);
  _object_copyin(iVar1,param_2,6,0,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 != 0) {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    _convert_port_to_thread();
    _port_release(*(undefined4 *)((int)register0x00000038 + -0xc));
    if (iVar1 != 0) {
      sub_F00811AC(param_4,param_5,param_6,(undefined *)((int)register0x00000038 + -0x10),
                   *(int *)(iVar1 + 0x84) + 0x44);
      if (*(int *)((int)register0x00000038 + -0x10) != 0) {
        _thread_psignal(iVar1);
      }
      _thread_deallocate(iVar1);
      goto loc_F008118C;
    }
  }
  uVar2 = 4;
loc_F008118C:
  _port_deallocate_EXTERNAL(dword_F0130F60,param_3);
  _port_deallocate_EXTERNAL(dword_F0130F60,param_2);
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1756 start=0xf008128c */

/* WARNING: Removing unreachable block (ram,0xf0082348) */
/* WARNING: Removing unreachable block (ram,0xf0082310) */
/* WARNING: Removing unreachable block (ram,0xf00822dc) */
/* WARNING: Removing unreachable block (ram,0xf0082250) */
/* WARNING: Removing unreachable block (ram,0xf008221c) */
/* WARNING: Removing unreachable block (ram,0xf0082ca0) */
/* WARNING: Removing unreachable block (ram,0xf0082c68) */
/* WARNING: Removing unreachable block (ram,0xf0082c34) */
/* WARNING: Removing unreachable block (ram,0xf0082bb8) */
/* WARNING: Removing unreachable block (ram,0xf0082b84) */
/* WARNING: Removing unreachable block (ram,0xf0082eac) */
/* WARNING: Removing unreachable block (ram,0xf0082e68) */
/* WARNING: Removing unreachable block (ram,0xf0082e0c) */
/* WARNING: Removing unreachable block (ram,0xf0082d78) */
/* WARNING: Removing unreachable block (ram,0xf0082d98) */
/* WARNING: Removing unreachable block (ram,0xf0082d24) */
/* WARNING: Removing unreachable block (ram,0xf0082cdc) */
/* WARNING: Removing unreachable block (ram,0xf0082ae0) */
/* WARNING: Removing unreachable block (ram,0xf0082a64) */
/* WARNING: Removing unreachable block (ram,0xf0082a30) */
/* WARNING: Removing unreachable block (ram,0xf00829c8) */
/* WARNING: Removing unreachable block (ram,0xf0082984) */
/* WARNING: Removing unreachable block (ram,0xf0082928) */
/* WARNING: Removing unreachable block (ram,0xf00828d4) */
/* WARNING: Removing unreachable block (ram,0xf0082870) */
/* WARNING: Removing unreachable block (ram,0xf0082804) */
/* WARNING: Removing unreachable block (ram,0xf0082788) */
/* WARNING: Removing unreachable block (ram,0xf0082760) */
/* WARNING: Removing unreachable block (ram,0xf0082710) */
/* WARNING: Removing unreachable block (ram,0xf00826dc) */
/* WARNING: Removing unreachable block (ram,0xf0082670) */
/* WARNING: Removing unreachable block (ram,0xf0082640) */
/* WARNING: Removing unreachable block (ram,0xf008260c) */
/* WARNING: Removing unreachable block (ram,0xf0082590) */
/* WARNING: Removing unreachable block (ram,0xf0082548) */
/* WARNING: Removing unreachable block (ram,0xf0082514) */
/* WARNING: Removing unreachable block (ram,0xf00824ec) */
/* WARNING: Removing unreachable block (ram,0xf00824a8) */
/* WARNING: Removing unreachable block (ram,0xf008244c) */
/* WARNING: Removing unreachable block (ram,0xf00823e8) */
/* WARNING: Removing unreachable block (ram,0xf0082388) */
/* WARNING: Removing unreachable block (ram,0xf0082170) */
/* WARNING: Removing unreachable block (ram,0xf0082100) */
/* WARNING: Removing unreachable block (ram,0xf008209c) */
/* WARNING: Removing unreachable block (ram,0xf0082018) */
/* WARNING: Removing unreachable block (ram,0xf0081ff8) */
/* WARNING: Removing unreachable block (ram,0xf0081fb4) */
/* WARNING: Removing unreachable block (ram,0xf0081ee0) */
/* WARNING: Removing unreachable block (ram,0xf0081f1c) */
/* WARNING: Removing unreachable block (ram,0xf0081e54) */
/* WARNING: Removing unreachable block (ram,0xf0081df4) */
/* WARNING: Removing unreachable block (ram,0xf0081dcc) */
/* WARNING: Removing unreachable block (ram,0xf0081d8c) */
/* WARNING: Removing unreachable block (ram,0xf0081d38) */
/* WARNING: Removing unreachable block (ram,0xf0081ce8) */
/* WARNING: Removing unreachable block (ram,0xf0081c94) */
/* WARNING: Removing unreachable block (ram,0xf0081c54) */
/* WARNING: Removing unreachable block (ram,0xf0081c1c) */
/* WARNING: Removing unreachable block (ram,0xf0081bb8) */
/* WARNING: Removing unreachable block (ram,0xf0081b90) */
/* WARNING: Removing unreachable block (ram,0xf0081b50) */
/* WARNING: Removing unreachable block (ram,0xf0081afc) */
/* WARNING: Removing unreachable block (ram,0xf0081830) */
/* WARNING: Removing unreachable block (ram,0xf00817ec) */
/* WARNING: Removing unreachable block (ram,0xf00818ec) */
/* WARNING: Removing unreachable block (ram,0xf0081898) */
/* WARNING: Removing unreachable block (ram,0xf0081768) */
/* WARNING: Removing unreachable block (ram,0xf008171c) */
/* WARNING: Removing unreachable block (ram,0xf00816ec) */
/* WARNING: Removing unreachable block (ram,0xf00815b8) */
/* WARNING: Removing unreachable block (ram,0xf0081564) */
/* WARNING: Removing unreachable block (ram,0xf0081670) */
/* WARNING: Removing unreachable block (ram,0xf008161c) */
/* WARNING: Removing unreachable block (ram,0xf00814ec) */
/* WARNING: Removing unreachable block (ram,0xf00814c8) */
/* WARNING: Removing unreachable block (ram,0xf0081474) */
/* WARNING: Removing unreachable block (ram,0xf0081400) */
/* WARNING: Removing unreachable block (ram,0xf00813d0) */
/* WARNING: Removing unreachable block (ram,0xf0081328) */
/* WARNING: Removing unreachable block (ram,0xf0081390) */
/* WARNING: Removing unreachable block (ram,0xf00813ec) */
/* WARNING: Removing unreachable block (ram,0xf008143c) */
/* WARNING: Removing unreachable block (ram,0xf0081490) */
/* WARNING: Removing unreachable block (ram,0xf00814e0) */
/* WARNING: Removing unreachable block (ram,0xf0081518) */
/* WARNING: Removing unreachable block (ram,0xf0081654) */
/* WARNING: Removing unreachable block (ram,0xf0081684) */
/* WARNING: Removing unreachable block (ram,0xf008159c) */
/* WARNING: Removing unreachable block (ram,0xf00815cc) */
/* WARNING: Removing unreachable block (ram,0xf0081708) */
/* WARNING: Removing unreachable block (ram,0xf0081754) */
/* WARNING: Removing unreachable block (ram,0xf0081938) */
/* WARNING: Removing unreachable block (ram,0xf00818d0) */
/* WARNING: Removing unreachable block (ram,0xf00817d0) */
/* WARNING: Removing unreachable block (ram,0xf0081800) */
/* WARNING: Removing unreachable block (ram,0xf0081ab8) */
/* WARNING: Removing unreachable block (ram,0xf0081b34) */
/* WARNING: Removing unreachable block (ram,0xf0081b64) */
/* WARNING: Removing unreachable block (ram,0xf0081b98) */
/* WARNING: Removing unreachable block (ram,0xf0081c0c) */
/* WARNING: Removing unreachable block (ram,0xf0081c40) */
/* WARNING: Removing unreachable block (ram,0xf0081c6c) */
/* WARNING: Removing unreachable block (ram,0xf0081ccc) */
/* WARNING: Removing unreachable block (ram,0xf0081cfc) */
/* WARNING: Removing unreachable block (ram,0xf0081d70) */
/* WARNING: Removing unreachable block (ram,0xf0081da0) */
/* WARNING: Removing unreachable block (ram,0xf0081dd4) */
/* WARNING: Removing unreachable block (ram,0xf0081e38) */
/* WARNING: Removing unreachable block (ram,0xf0081e68) */
/* WARNING: Removing unreachable block (ram,0xf0081ecc) */
/* WARNING: Removing unreachable block (ram,0xf0081f8c) */
/* WARNING: Removing unreachable block (ram,0xf0081fe4) */
/* WARNING: Removing unreachable block (ram,0xf0082000) */
/* WARNING: Removing unreachable block (ram,0xf0082054) */
/* WARNING: Removing unreachable block (ram,0xf00820b8) */
/* WARNING: Removing unreachable block (ram,0xf0082144) */
/* WARNING: Removing unreachable block (ram,0xf00821a0) */
/* WARNING: Removing unreachable block (ram,0xf00823c8) */
/* WARNING: Removing unreachable block (ram,0xf00823fc) */
/* WARNING: Removing unreachable block (ram,0xf0082488) */
/* WARNING: Removing unreachable block (ram,0xf00824bc) */
/* WARNING: Removing unreachable block (ram,0xf00824f4) */
/* WARNING: Removing unreachable block (ram,0xf0082530) */
/* WARNING: Removing unreachable block (ram,0xf0082580) */
/* WARNING: Removing unreachable block (ram,0xf00825ac) */
/* WARNING: Removing unreachable block (ram,0xf008262c) */
/* WARNING: Removing unreachable block (ram,0xf0082654) */
/* WARNING: Removing unreachable block (ram,0xf0082698) */
/* WARNING: Removing unreachable block (ram,0xf00826fc) */
/* WARNING: Removing unreachable block (ram,0xf0082730) */
/* WARNING: Removing unreachable block (ram,0xf0082774) */
/* WARNING: Removing unreachable block (ram,0xf00827c4) */
/* WARNING: Removing unreachable block (ram,0xf008284c) */
/* WARNING: Removing unreachable block (ram,0xf00828b4) */
/* WARNING: Removing unreachable block (ram,0xf00828e8) */
/* WARNING: Removing unreachable block (ram,0xf0082964) */
/* WARNING: Removing unreachable block (ram,0xf0082998) */
/* WARNING: Removing unreachable block (ram,0xf00829d0) */
/* WARNING: Removing unreachable block (ram,0xf0082a50) */
/* WARNING: Removing unreachable block (ram,0xf0082aa4) */
/* WARNING: Removing unreachable block (ram,0xf0082b00) */
/* WARNING: Removing unreachable block (ram,0xf0082d0c) */
/* WARNING: Removing unreachable block (ram,0xf0082d4c) */
/* WARNING: Removing unreachable block (ram,0xf0082d88) */
/* WARNING: Removing unreachable block (ram,0xf0082dd4) */
/* WARNING: Removing unreachable block (ram,0xf0082e48) */
/* WARNING: Removing unreachable block (ram,0xf0082e7c) */
/* WARNING: Removing unreachable block (ram,0xf0082eb4) */
/* WARNING: Removing unreachable block (ram,0xf0082ba4) */
/* WARNING: Removing unreachable block (ram,0xf0082bf8) */
/* WARNING: Removing unreachable block (ram,0xf0082c54) */
/* WARNING: Removing unreachable block (ram,0xf0082c98) */
/* WARNING: Removing unreachable block (ram,0xf00821e8) */
/* WARNING: Removing unreachable block (ram,0xf008223c) */
/* WARNING: Removing unreachable block (ram,0xf00822a0) */
/* WARNING: Removing unreachable block (ram,0xf00822fc) */
/* WARNING: Removing unreachable block (ram,0xf0082340) */
/* WARNING: Removing unreachable block (ram,0xf008235c) */
/* WARNING: Removing unreachable block (ram,0xf00812e4) */

undefined8
_vm_fault(undefined4 param_1,undefined4 *param_2,undefined4 param_3,undefined4 param_4,
         undefined4 param_5)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int *piVar4;
  sword sVar7;
  undefined4 *puVar5;
  int iVar6;
  uint uVar8;
  int *piVar9;
  int *piVar10;
  int iVar11;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar12;
  undefined4 unaff_l3;
  int *piVar13;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar14;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar15;
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
  *(undefined4 **)((int)register0x00000038 + -0x34) = param_2;
  *(undefined4 *)((int)register0x00000038 + -0x3c) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x44) = param_4;
  *(undefined4 *)((int)register0x00000038 + -0x4c) = param_5;
  DAT_f013c264._0_4_ = DAT_f013c264._0_4_ + 1;
loc_F00812BC:
  puVar2 = (undefined *)((int)register0x00000038 + 0x44);
  _vm_map_lookup(puVar2,*(undefined4 *)((int)register0x00000038 + -0x34),
                 *(undefined4 *)((int)register0x00000038 + -0x3c),
                 (undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),
                 (undefined *)((int)register0x00000038 + -0x14),
                 (undefined *)((int)register0x00000038 + -0x18),
                 (undefined *)((int)register0x00000038 + -0x1c),
                 (undefined *)((int)register0x00000038 + -0x20));
  if (puVar2 == (undefined *)0x0) {
    bVar1 = true;
    if (*(int *)((int)register0x00000038 + -0x1c) != 0) {
      *(undefined4 *)((int)register0x00000038 + -0x3c) =
           *(undefined4 *)((int)register0x00000038 + -0x18);
    }
    iVar3 = *(int *)((int)register0x00000038 + -0x10);
    piVar13 = (int *)0x0;
    do {
      do {
      } while (*(int *)(iVar3 + 0x10) != 0);
      piVar4 = (int *)(iVar3 + 0x10);
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    param_2 = &_vm_stat;
    iVar3 = *(int *)((int)register0x00000038 + -0x14);
    piVar4 = *(int **)((int)register0x00000038 + -0x10);
    sVar7 = *(sword *)(piVar4 + 0x11);
    *(sword *)(piVar4 + 6) = *(sword *)(piVar4 + 6) + 1;
loc_F0081384:
    do {
      *(sword *)(piVar4 + 0x11) = sVar7 + 1;
loc_F0081390:
      piVar9 = piVar4;
      _vm_page_lookup(piVar4,iVar3);
      if (piVar9 == (int *)0x0) goto loc_F0081A74;
      uVar8 = piVar9[8];
      if ((uVar8 & 0x2000000) != 0) {
        piVar9[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar9[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar9,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        _vm_page_free(piVar9);
        _vm_page_queue_lock = 0;
        piVar4[4] = 0;
        piVar9 = *(int **)((int)register0x00000038 + -0x10);
        *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
        if (piVar4 != piVar9) {
          piVar9 = piVar9 + 4;
          do {
            do {
            } while (*piVar9 != 0);
            piVar4 = piVar9;
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          uVar8 = piVar13[8];
          piVar13[8] = uVar8 & 0x7fffffff;
          if ((uVar8 & 0x40000000) != 0) {
            piVar13[8] = uVar8 & 0x3fffffff;
            _thread_wakeup_prim(piVar13,0,0);
          }
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar5 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar5 == (undefined4 *)0x0);
          goto loc_F0081DA0;
        }
        goto loc_F0081DC0;
      }
      if ((int)uVar8 < 0) {
        piVar9[8] = uVar8 | 0x40000000;
        _assert_wait(piVar9,*(int *)((int)register0x00000038 + -0x44) == 0);
        if (bVar1) {
          bVar1 = false;
          _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                              *(undefined4 *)((int)register0x00000038 + -0xc));
        }
        piVar4[4] = 0;
        _thread_block();
        iVar12 = *(int *)(_active_threads + 0x44);
        do {
          do {
          } while (piVar4[4] != 0);
          piVar9 = piVar4 + 4;
          _simple_lock_try();
        } while (piVar9 == (int *)0x0);
        if (iVar12 != 4) goto loc_F00815E4;
        piVar4[4] = 0;
        piVar9 = *(int **)((int)register0x00000038 + -0x10);
        *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
        if (piVar4 != piVar9) {
          piVar9 = piVar9 + 4;
          do {
            do {
            } while (*piVar9 != 0);
            piVar4 = piVar9;
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          uVar8 = piVar13[8];
          piVar13[8] = uVar8 & 0x7fffffff;
          if ((uVar8 & 0x40000000) != 0) {
            piVar13[8] = uVar8 & 0x3fffffff;
            _thread_wakeup_prim(piVar13,0,0);
          }
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar5 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar5 == (undefined4 *)0x0);
          _vm_page_free(piVar13);
          iVar3 = *(int *)((int)register0x00000038 + -0x10);
          sVar7 = *(sword *)(iVar3 + 0x44);
          goto loc_F0082C80;
        }
        goto loc_F0082C8C;
      }
      if ((uVar8 & 0x4000000) == 0) {
        uVar8 = piVar9[10];
        goto loc_F0081858;
      }
      piVar10 = (int *)piVar4[8];
      iVar3 = iVar3 + piVar4[9];
      if (piVar10 == (int *)0x0) {
        if (piVar4 != *(int **)((int)register0x00000038 + -0x10)) {
          piVar9[8] = uVar8 & 0x7bffffff;
          if ((uVar8 & 0x40000000) != 0) {
            piVar9[8] = uVar8 & 0x3bffffff;
            _thread_wakeup_prim(piVar9,0,0);
          }
          do {
            do {
            } while (_vm_page_queue_lock != 0);
            puVar5 = &_vm_page_queue_lock;
            _simple_lock_try();
          } while (puVar5 == (undefined4 *)0x0);
          _vm_page_free(piVar9);
          _vm_page_queue_lock = 0;
          piVar4[4] = 0;
          *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
          piVar4 = *(int **)((int)register0x00000038 + -0x10);
          do {
            do {
            } while (piVar4[4] != 0);
            piVar10 = piVar4 + 4;
            _simple_lock_try();
            piVar9 = piVar13;
          } while (piVar10 == (int *)0x0);
        }
        _vm_page_zero_fill(piVar9);
        DAT_f013c254._0_4_ = DAT_f013c254._0_4_ + 1;
        piVar13 = (int *)0x0;
        piVar9[8] = piVar9[8] & 0xfbffffff;
        uVar8 = piVar9[10];
loc_F0081858:
        if ((*(uint *)((int)register0x00000038 + -0x3c) & uVar8) != 0) {
          piVar4[4] = 0;
          piVar9 = *(int **)((int)register0x00000038 + -0x10);
          *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
          if (piVar4 != piVar9) {
            piVar9 = piVar9 + 4;
            do {
              do {
              } while (*piVar9 != 0);
              piVar4 = piVar9;
              _simple_lock_try();
            } while (piVar4 == (int *)0x0);
            uVar8 = piVar13[8];
            piVar13[8] = uVar8 & 0x7fffffff;
            if ((uVar8 & 0x40000000) != 0) {
              piVar13[8] = uVar8 & 0x3fffffff;
              _thread_wakeup_prim(piVar13,0,0);
            }
            do {
              do {
              } while (_vm_page_queue_lock != 0);
              puVar5 = &_vm_page_queue_lock;
              _simple_lock_try();
            } while (puVar5 == (undefined4 *)0x0);
            goto loc_F0081DA0;
          }
          goto loc_F0081DC0;
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        uVar8 = piVar9[7];
        if ((uVar8 & 0x8000) != 0) {
          iVar3 = *piVar9;
          piVar10 = (int *)piVar9[1];
          *(int **)(iVar3 + 4) = piVar10;
          if (piVar10 != &_vm_page_queue_inactive) {
            *piVar10 = iVar3;
            iVar3 = _vm_page_queue_inactive;
          }
          _vm_page_queue_inactive = iVar3;
          piVar9[7] = piVar9[7] & 0xffff7fff;
          _vm_page_inactive_count = _vm_page_inactive_count + -1;
          DAT_f013c254._4_4_ = DAT_f013c254._4_4_ + 1;
          uVar8 = piVar9[7];
        }
        if ((uVar8 & 0x4000) == 0) {
          uVar8 = piVar9[7];
        }
        else {
          iVar3 = *piVar9;
          piVar10 = (int *)piVar9[1];
          *(int **)(iVar3 + 4) = piVar10;
          if (piVar10 != &_vm_page_queue_active) {
            *piVar10 = iVar3;
            iVar3 = _vm_page_queue_active;
          }
          _vm_page_queue_active = iVar3;
          piVar9[7] = piVar9[7] & 0xffffbfff;
          _vm_page_active_count = _vm_page_active_count + -1;
          uVar8 = piVar9[7];
        }
        if ((uVar8 & 0x1000) != 0) {
          iVar3 = *piVar9;
          piVar10 = (int *)piVar9[1];
          *(int **)(iVar3 + 4) = piVar10;
          if (piVar10 != &_vm_page_queue_free) {
            *piVar10 = iVar3;
            iVar3 = _vm_page_queue_free;
          }
          _vm_page_queue_free = iVar3;
          piVar9[7] = piVar9[7] & 0xffffefff;
          _vm_page_free_count = _vm_page_free_count + -1;
          DAT_f013c254._4_4_ = DAT_f013c254._4_4_ + 1;
        }
        _vm_page_queue_lock = 0;
        uVar8 = piVar9[8] | 0x80000000;
        goto loc_F0081EFC;
      }
      if (piVar4 == *(int **)((int)register0x00000038 + -0x10)) {
        piVar9[8] = uVar8 & 0xfbffffff;
        piVar13 = piVar9;
      }
      else {
        *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
        uVar8 = piVar9[8];
        piVar9[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar9[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar9,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        _vm_page_free(piVar9);
        _vm_page_queue_lock = 0;
      }
      do {
        do {
          piVar9 = piVar10 + 4;
        } while (*piVar9 != 0);
        _simple_lock_try();
      } while (piVar9 == (int *)0x0);
      piVar4[4] = 0;
      sVar7 = *(sword *)(piVar10 + 0x11);
      piVar4 = piVar10;
    } while( true );
  }
  goto locret_F0082EC0;
loc_F0081A74:
  if (piVar4[10] == 0) {
    piVar10 = *(int **)((int)register0x00000038 + -0x10);
loc_F0081AA4:
    if (piVar4 == piVar10) goto loc_F0081AB4;
    iVar12 = piVar4[10];
  }
  else {
    if ((*(int *)((int)register0x00000038 + -0x44) != 0) &&
       (*(int *)((int)register0x00000038 + -0x1c) == 0)) {
      piVar10 = *(int **)((int)register0x00000038 + -0x10);
      goto loc_F0081AA4;
    }
loc_F0081AB4:
    piVar9 = piVar4;
    _vm_page_alloc_sequential(piVar4,iVar3,1);
    if (piVar9 == (int *)0x0) {
      piVar4[4] = 0;
      piVar9 = *(int **)((int)register0x00000038 + -0x10);
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      if (piVar4 != piVar9) {
        piVar9 = piVar9 + 4;
        do {
          do {
          } while (*piVar9 != 0);
          piVar4 = piVar9;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        uVar8 = piVar13[8];
        piVar13[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar13[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar13,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        _vm_page_free(piVar13);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
        _vm_page_queue_lock = 0;
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(sword *)(iVar3 + 0x44) = *(sword *)(iVar3 + 0x44) + -1;
      }
      if (bVar1) {
        _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                            *(undefined4 *)((int)register0x00000038 + -0xc));
      }
      _vm_object_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
      do {
        do {
        } while (_vm_pages_needed_lock != 0);
        puVar5 = &_vm_pages_needed_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
loc_F0082528:
      _thread_wakeup_prim(&_vm_pages_needed,0,0);
      _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
      goto loc_F00812BC;
    }
    iVar12 = piVar4[10];
  }
  if (iVar12 != 0) {
    if ((*(int *)((int)register0x00000038 + -0x44) != 0) &&
       (piVar10 = *(int **)((int)register0x00000038 + -0x10),
       *(int *)((int)register0x00000038 + -0x1c) == 0)) goto loc_F0081E78;
    piVar4[4] = 0;
    piVar10 = piVar4 + 4;
    if (bVar1) {
      bVar1 = false;
      _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                          *(undefined4 *)((int)register0x00000038 + -0xc));
    }
    iVar12 = piVar4[10];
    _vm_pager_get(iVar12,piVar9,*(undefined4 *)((int)register0x00000038 + -0x4c));
    if (iVar12 == 0) goto loc_F0081C30;
    if (iVar12 == 2) goto loc_F0081C84;
    do {
      do {
      } while (*piVar10 != 0);
      piVar14 = piVar10;
      _simple_lock_try();
    } while (piVar14 == (int *)0x0);
    piVar10 = *(int **)((int)register0x00000038 + -0x10);
    if (piVar4 == *(int **)((int)register0x00000038 + -0x10)) goto loc_F0081E78;
    uVar8 = piVar9[8];
    piVar9[8] = uVar8 & 0x7fffffff;
    if ((uVar8 & 0x40000000) != 0) {
      piVar9[8] = uVar8 & 0x3fffffff;
      _thread_wakeup_prim(piVar9,0,0);
    }
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar5 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar5 == (undefined4 *)0x0);
    _vm_page_free(piVar9);
    _vm_page_queue_lock = 0;
  }
  piVar10 = *(int **)((int)register0x00000038 + -0x10);
loc_F0081E78:
  if (piVar4 == piVar10) {
    piVar13 = piVar9;
  }
  piVar14 = (int *)piVar4[8];
  iVar3 = iVar3 + piVar4[9];
  if (piVar14 == (int *)0x0) goto loc_f0081e98;
  do {
    do {
    } while (piVar14[4] != 0);
    piVar9 = piVar14 + 4;
    _simple_lock_try();
  } while (piVar9 == (int *)0x0);
  if (piVar4 != *(int **)((int)register0x00000038 + -0x10)) {
    *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
  }
  piVar4[4] = 0;
  sVar7 = *(sword *)(piVar14 + 0x11);
  piVar4 = piVar14;
  goto loc_F0081384;
loc_F0081C30:
  do {
    do {
    } while (*piVar10 != 0);
    piVar9 = piVar10;
    _simple_lock_try();
  } while (piVar9 == (int *)0x0);
  piVar9 = piVar4;
  _vm_page_lookup(piVar4,iVar3);
  DAT_f013c254._8_4_ = DAT_f013c254._8_4_ + 1;
  _pmap_clear_modify(piVar9[9]);
  uVar8 = piVar9[8];
  goto loc_F0081F5C;
loc_F0081C84:
  do {
    do {
    } while (*piVar10 != 0);
    piVar14 = piVar10;
    _simple_lock_try();
  } while (piVar14 == (int *)0x0);
  uVar8 = piVar9[8];
  piVar9[8] = uVar8 & 0x7fffffff;
  if ((uVar8 & 0x40000000) != 0) {
    piVar9[8] = uVar8 & 0x3fffffff;
    _thread_wakeup_prim(piVar9,0,0);
  }
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar5 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  _vm_page_free(piVar9);
  _vm_page_queue_lock = 0;
  piVar4[4] = 0;
  piVar9 = *(int **)((int)register0x00000038 + -0x10);
  *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
  if (piVar4 != piVar9) {
    piVar9 = piVar9 + 4;
    do {
      do {
      } while (*piVar9 != 0);
      piVar4 = piVar9;
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    uVar8 = piVar13[8];
    piVar13[8] = uVar8 & 0x7fffffff;
    if ((uVar8 & 0x40000000) != 0) {
      piVar13[8] = uVar8 & 0x3fffffff;
      _thread_wakeup_prim(piVar13,0,0);
    }
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar5 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar5 == (undefined4 *)0x0);
loc_F0081DA0:
    _vm_page_free(piVar13);
    iVar3 = *(int *)((int)register0x00000038 + -0x10);
    _vm_page_queue_lock = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(sword *)(iVar3 + 0x44) = *(sword *)(iVar3 + 0x44) + -1;
  }
loc_F0081DC0:
  if (bVar1) {
    _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                        *(undefined4 *)((int)register0x00000038 + -0xc));
  }
  _vm_object_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
  puVar2 = (undefined *)0xa;
  goto locret_F0082EC0;
loc_f0081e98:
  if (piVar4 != piVar10) {
    piVar4[4] = 0;
    *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
    do {
      do {
      } while (piVar10[4] != 0);
      piVar14 = piVar10 + 4;
      _simple_lock_try();
      piVar9 = piVar13;
      piVar4 = piVar10;
    } while (piVar14 == (int *)0x0);
  }
  _vm_page_zero_fill(piVar9);
  DAT_f013c254._0_4_ = DAT_f013c254._0_4_ + 1;
  uVar8 = piVar9[8];
  piVar13 = (int *)0x0;
loc_F0081EFC:
  piVar9[8] = uVar8 & 0xfbffffff;
  uVar8 = piVar9[8];
loc_F0081F5C:
  if ((((uVar8 & 0x4000000) == 0) && ((piVar9[7] & 0xc000U) == 0)) && ((int)uVar8 < 0)) {
    piVar10 = *(int **)((int)register0x00000038 + -0x10);
  }
  else {
    _panic(aVmFaultAbsentO);
    piVar10 = *(int **)((int)register0x00000038 + -0x10);
  }
  piVar14 = piVar9;
  if (piVar4 != piVar10) {
    if ((*(uint *)((int)register0x00000038 + -0x3c) & 2) == 0) {
      *(uint *)((int)register0x00000038 + -0x18) =
           *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffd;
      piVar9[8] = piVar9[8] | 0x200000;
    }
    else {
      _vm_page_copy(piVar9,piVar13);
      piVar13[8] = piVar13[8] & 0xfbffffff;
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_activate(piVar9);
      _vm_page_deactivate(piVar9);
      if (*(int *)((int)register0x00000038 + -0x20) == 0) {
        _pmap_remove_all(piVar9[9]);
      }
      _vm_page_queue_lock = 0;
      uVar8 = piVar9[8];
      piVar9[8] = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        piVar9[8] = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(piVar9,0,0);
      }
      piVar4[4] = 0;
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      piVar4 = *(int **)((int)register0x00000038 + -0x10);
      DAT_f013c264._4_4_ = DAT_f013c264._4_4_ + 1;
      do {
        do {
        } while (piVar4[4] != 0);
        piVar10 = piVar4 + 4;
        _simple_lock_try();
      } while (piVar10 == (int *)0x0);
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      _vm_object_collapse(piVar4);
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + 1;
      piVar14 = piVar13;
    }
  }
  if ((piVar14[7] & 0xc000U) != 0) {
    _panic(aVmFaultActiveO);
  }
  iVar3 = *(int *)((int)register0x00000038 + -0x10);
loc_F008210C:
  iVar3 = *(int *)(iVar3 + 0x1c);
  if (iVar3 == 0) goto loc_F00827EC;
  if ((*(uint *)((int)register0x00000038 + -0x3c) & 2) == 0) {
    *(uint *)((int)register0x00000038 + -0x18) =
         *(uint *)((int)register0x00000038 + -0x18) & 0xfffffffd;
    uVar8 = piVar14[8] | 0x200000;
    goto loc_F00827E8;
  }
  iVar12 = iVar3 + 0x10;
  _simple_lock_try();
  if (iVar12 == 0) goto loc_f0082158;
  iVar11 = *(int *)((int)register0x00000038 + -0x14);
  *(sword *)(iVar3 + 0x18) = *(sword *)(iVar3 + 0x18) + 1;
  iVar11 = iVar11 - *(int *)(iVar3 + 0x24);
  iVar12 = iVar3;
  _vm_page_lookup(iVar3,iVar11);
  bVar15 = iVar12 == 0;
  if ((bVar15) || (-1 < (int)*(uint *)(iVar12 + 0x20))) {
    if (!bVar15) goto loc_F0082724;
    iVar12 = iVar3;
    _vm_page_alloc_sequential(iVar3,iVar11,1);
    if (iVar12 == 0) {
      uVar8 = piVar14[8];
      piVar14[8] = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        piVar14[8] = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(piVar14,0,0);
      }
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_activate(piVar14);
      _vm_page_queue_lock = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      piVar9 = *(int **)((int)register0x00000038 + -0x10);
      *(sword *)(iVar3 + 0x18) = *(sword *)(iVar3 + 0x18) + -1;
      piVar4[4] = 0;
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      if (piVar4 != piVar9) {
        piVar9 = piVar9 + 4;
        do {
          do {
          } while (*piVar9 != 0);
          piVar4 = piVar9;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        uVar8 = piVar13[8];
        piVar13[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar13[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar13,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        _vm_page_free(piVar13);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
        _vm_page_queue_lock = 0;
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(sword *)(iVar3 + 0x44) = *(sword *)(iVar3 + 0x44) + -1;
      }
      if (bVar1) {
        _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                            *(undefined4 *)((int)register0x00000038 + -0xc));
      }
      _vm_object_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
      do {
        do {
        } while (_vm_pages_needed_lock != 0);
        puVar5 = &_vm_pages_needed_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      goto loc_F0082528;
    }
    if (*(int *)(iVar3 + 0x28) == 0) goto loc_F0082724;
    piVar4[4] = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    if (bVar1) {
      bVar1 = false;
      _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                          *(undefined4 *)((int)register0x00000038 + -0xc));
    }
    iVar6 = *(int *)(iVar3 + 0x28);
    _vm_pager_has_page(iVar6,iVar11 + *(int *)(iVar3 + 0x2c));
    do {
      do {
      } while (*(int *)(iVar3 + 0x10) != 0);
      piVar10 = (int *)(iVar3 + 0x10);
      _simple_lock_try();
    } while (piVar10 == (int *)0x0);
    if (*(int **)(iVar3 + 0x20) != piVar4) {
      uVar8 = *(uint *)(iVar12 + 0x20);
loc_F00825E4:
      *(uint *)(iVar12 + 0x20) = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        *(uint *)(iVar12 + 0x20) = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(iVar12,0,0);
      }
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_free(iVar12);
      _vm_page_queue_lock = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      _vm_object_deallocate(iVar3);
      do {
        do {
        } while (piVar4[4] != 0);
        piVar10 = piVar4 + 4;
        _simple_lock_try();
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
      } while (piVar10 == (int *)0x0);
      goto loc_F008210C;
    }
    if (*(sword *)(iVar3 + 0x18) == 1) {
      uVar8 = *(uint *)(iVar12 + 0x20);
      goto loc_F00825E4;
    }
    do {
      do {
      } while (piVar4[4] != 0);
      piVar10 = piVar4 + 4;
      _simple_lock_try();
      bVar15 = iVar6 == 0;
    } while (piVar10 == (int *)0x0);
    if (!bVar15) {
      uVar8 = *(uint *)(iVar12 + 0x20);
      *(uint *)(iVar12 + 0x20) = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        *(uint *)(iVar12 + 0x20) = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(iVar12,0,0);
      }
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_free(iVar12);
      _vm_page_queue_lock = 0;
      bVar15 = iVar6 == 0;
    }
loc_F0082724:
    if (bVar15) {
      _vm_page_copy(piVar14,iVar12);
      *(uint *)(iVar12 + 0x20) = *(uint *)(iVar12 + 0x20) & 0xfbffffff;
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _pmap_remove_all(piVar9[9]);
      *(uint *)(iVar12 + 0x1c) = *(uint *)(iVar12 + 0x1c) & 0xfffffbff;
      _vm_page_activate(iVar12);
      _vm_page_queue_lock = 0;
      uVar8 = *(uint *)(iVar12 + 0x20);
      *(uint *)(iVar12 + 0x20) = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        *(uint *)(iVar12 + 0x20) = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(iVar12,0,0);
      }
      sVar7 = *(sword *)(iVar3 + 0x18);
    }
    else {
      sVar7 = *(sword *)(iVar3 + 0x18);
    }
    *(undefined4 *)(iVar3 + 0x10) = 0;
    *(sword *)(iVar3 + 0x18) = sVar7 + -1;
    uVar8 = piVar14[8] & 0xffdfffff;
loc_F00827E8:
    piVar14[8] = uVar8;
loc_F00827EC:
    if ((piVar14[7] & 0xc000U) != 0) {
      _panic(aVmFaultActiveO_0);
    }
    uVar8 = *(uint *)((int)register0x00000038 + -0x18);
    if (bVar1) {
loc_F0082CB0:
      bVar1 = true;
      if ((uVar8 & 2) != 0) {
        piVar14[8] = piVar14[8] & 0xffdfffff;
      }
      if ((piVar14[7] & 0xc000U) != 0) {
        _panic(aVmFaultActiveO_1);
      }
      piVar4[4] = 0;
      _pmap_enter(*(undefined4 *)(*(int *)((int)register0x00000038 + 0x44) + 0x24),
                  *(undefined4 *)((int)register0x00000038 + -0x34),piVar14[9],
                  *(uint *)((int)register0x00000038 + -0x18) & ~piVar14[10],
                  *(undefined4 *)((int)register0x00000038 + -0x1c));
      do {
        do {
        } while (piVar4[4] != 0);
        piVar9 = piVar4 + 4;
        _simple_lock_try();
      } while (piVar9 == (int *)0x0);
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      if (*(int *)((int)register0x00000038 + -0x44) == 0) {
        _vm_page_activate(piVar14);
      }
      else if (*(int *)((int)register0x00000038 + -0x1c) == 0) {
        _vm_page_unwire(piVar14);
      }
      else {
        _vm_page_wire(piVar14);
      }
      _vm_page_queue_lock = 0;
      uVar8 = piVar14[8];
      piVar14[8] = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        piVar14[8] = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(piVar14,0,0);
      }
      piVar4[4] = 0;
      piVar9 = *(int **)((int)register0x00000038 + -0x10);
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      if (piVar4 != piVar9) {
        piVar9 = piVar9 + 4;
        do {
          do {
          } while (*piVar9 != 0);
          piVar4 = piVar9;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        uVar8 = piVar13[8];
        piVar13[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar13[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar13,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        _vm_page_free(piVar13);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
        sVar7 = *(sword *)(iVar3 + 0x44);
        goto loc_F0082E94;
      }
      goto loc_F0082EA0;
    }
    piVar4[4] = 0;
    puVar2 = (undefined *)((int)register0x00000038 + 0x44);
    _vm_map_lookup(puVar2,*(undefined4 *)((int)register0x00000038 + -0x34),
                   *(uint *)((int)register0x00000038 + -0x3c) & 0xfffffffd,
                   (undefined *)((int)register0x00000038 + -0xc),
                   (undefined *)((int)register0x00000038 + -0x24),
                   (undefined *)((int)register0x00000038 + -0x28),
                   (undefined *)((int)register0x00000038 + -0x2c),
                   (undefined *)((int)register0x00000038 + -0x1c),
                   (undefined *)((int)register0x00000038 + -0x20));
    do {
      do {
      } while (piVar4[4] != 0);
      piVar9 = piVar4 + 4;
      _simple_lock_try();
    } while (piVar9 == (int *)0x0);
    if (puVar2 != (undefined *)0x0) {
      uVar8 = piVar14[8];
      piVar14[8] = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        piVar14[8] = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(piVar14,0,0);
      }
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_activate(piVar14);
      _vm_page_queue_lock = 0;
      piVar4[4] = 0;
      piVar9 = *(int **)((int)register0x00000038 + -0x10);
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      if (piVar4 != piVar9) {
        piVar9 = piVar9 + 4;
        do {
          do {
          } while (*piVar9 != 0);
          piVar4 = piVar9;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        uVar8 = piVar13[8];
        piVar13[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar13[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar13,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        _vm_page_free(piVar13);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
        _vm_page_queue_lock = 0;
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(sword *)(iVar3 + 0x44) = *(sword *)(iVar3 + 0x44) + -1;
      }
      _vm_object_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
      goto locret_F0082EC0;
    }
    bVar1 = true;
    if ((*(int *)((int)register0x00000038 + -0x24) == *(int *)((int)register0x00000038 + -0x10)) &&
       (uVar8 = *(uint *)((int)register0x00000038 + -0x18),
       *(int *)((int)register0x00000038 + -0x28) == *(int *)((int)register0x00000038 + -0x14))) {
      *(uint *)((int)register0x00000038 + -0x18) =
           uVar8 & *(uint *)((int)register0x00000038 + -0x2c);
      if ((piVar14[8] & 0x200000U) != 0) {
        *(uint *)((int)register0x00000038 + -0x18) =
             uVar8 & *(uint *)((int)register0x00000038 + -0x2c) & 0xfffffffd;
      }
      uVar8 = *(uint *)((int)register0x00000038 + -0x18);
      if ((*(int *)((int)register0x00000038 + -0x1c) == 0) ||
         (uVar8 == *(uint *)((int)register0x00000038 + -0x3c))) goto loc_F0082CB0;
      uVar8 = piVar14[8];
      piVar14[8] = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        piVar14[8] = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(piVar14,0,0);
      }
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_activate(piVar14);
      _vm_page_queue_lock = 0;
      piVar4[4] = 0;
      piVar9 = *(int **)((int)register0x00000038 + -0x10);
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      if (piVar4 != piVar9) {
        piVar9 = piVar9 + 4;
        do {
          do {
          } while (*piVar9 != 0);
          piVar4 = piVar9;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        uVar8 = piVar13[8];
        piVar13[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar13[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar13,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
        goto loc_F0082C68;
      }
    }
    else {
      uVar8 = piVar14[8];
      piVar14[8] = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        piVar14[8] = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(piVar14,0,0);
      }
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_activate(piVar14);
      _vm_page_queue_lock = 0;
      piVar4[4] = 0;
      piVar9 = *(int **)((int)register0x00000038 + -0x10);
      *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
      if (piVar4 != piVar9) {
        piVar9 = piVar9 + 4;
        do {
          do {
          } while (*piVar9 != 0);
          piVar4 = piVar9;
          _simple_lock_try();
        } while (piVar4 == (int *)0x0);
        uVar8 = piVar13[8];
        piVar13[8] = uVar8 & 0x7fffffff;
        if ((uVar8 & 0x40000000) != 0) {
          piVar13[8] = uVar8 & 0x3fffffff;
          _thread_wakeup_prim(piVar13,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar5 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar5 == (undefined4 *)0x0);
loc_F0082C68:
        _vm_page_free(piVar13);
        iVar3 = *(int *)((int)register0x00000038 + -0x10);
        sVar7 = *(sword *)(iVar3 + 0x44);
loc_F0082C80:
        _vm_page_queue_lock = 0;
        *(undefined4 *)(iVar3 + 0x10) = 0;
        *(sword *)(iVar3 + 0x44) = sVar7 + -1;
      }
    }
loc_F0082C8C:
    if (bVar1) {
      _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                          *(undefined4 *)((int)register0x00000038 + -0xc));
    }
    _vm_object_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
  }
  else {
    *(uint *)(iVar12 + 0x20) = *(uint *)(iVar12 + 0x20) | 0x40000000;
    _assert_wait(iVar12,*(int *)((int)register0x00000038 + -0x44) == 0);
    uVar8 = piVar14[8];
    piVar14[8] = uVar8 & 0x7fffffff;
    if ((uVar8 & 0x40000000) != 0) {
      piVar14[8] = uVar8 & 0x3fffffff;
      _thread_wakeup_prim(piVar14,0,0);
    }
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar5 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar5 == (undefined4 *)0x0);
    _vm_page_activate(piVar14);
    _vm_page_queue_lock = 0;
    *(undefined4 *)(iVar3 + 0x10) = 0;
    piVar9 = *(int **)((int)register0x00000038 + -0x10);
    *(sword *)(iVar3 + 0x18) = *(sword *)(iVar3 + 0x18) + -1;
    piVar4[4] = 0;
    *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
    if (piVar4 != piVar9) {
      piVar9 = piVar9 + 4;
      do {
        do {
        } while (*piVar9 != 0);
        piVar4 = piVar9;
        _simple_lock_try();
      } while (piVar4 == (int *)0x0);
      uVar8 = piVar13[8];
      piVar13[8] = uVar8 & 0x7fffffff;
      if ((uVar8 & 0x40000000) != 0) {
        piVar13[8] = uVar8 & 0x3fffffff;
        _thread_wakeup_prim(piVar13,0,0);
      }
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar5 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar5 == (undefined4 *)0x0);
      _vm_page_free(piVar13);
      iVar3 = *(int *)((int)register0x00000038 + -0x10);
      _vm_page_queue_lock = 0;
      *(undefined4 *)(iVar3 + 0x10) = 0;
      *(sword *)(iVar3 + 0x44) = *(sword *)(iVar3 + 0x44) + -1;
    }
    if (bVar1) {
      _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                          *(undefined4 *)((int)register0x00000038 + -0xc));
    }
    _thread_block();
    iVar3 = *(int *)(_active_threads + 0x44);
    _vm_object_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
    if (iVar3 != 0) {
      puVar2 = (undefined *)0x0;
      goto locret_F0082EC0;
    }
  }
  goto loc_F00812BC;
loc_f0082158:
  piVar4[4] = 0;
  do {
    do {
    } while (piVar4[4] != 0);
    piVar10 = piVar4 + 4;
    _simple_lock_try();
    iVar3 = *(int *)((int)register0x00000038 + -0x10);
  } while (piVar10 == (int *)0x0);
  goto loc_F008210C;
loc_F00815E4:
  if (iVar12 == 0) goto loc_F0081390;
  piVar4[4] = 0;
  piVar9 = *(int **)((int)register0x00000038 + -0x10);
  *(sword *)(piVar4 + 0x11) = *(sword *)(piVar4 + 0x11) + -1;
  if (piVar4 == piVar9) goto loc_F0082EA0;
  piVar9 = piVar9 + 4;
  do {
    do {
    } while (*piVar9 != 0);
    piVar4 = piVar9;
    _simple_lock_try();
  } while (piVar4 == (int *)0x0);
  uVar8 = piVar13[8];
  piVar13[8] = uVar8 & 0x7fffffff;
  if ((uVar8 & 0x40000000) != 0) {
    piVar13[8] = uVar8 & 0x3fffffff;
    _thread_wakeup_prim(piVar13,0,0);
  }
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar5 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar5 == (undefined4 *)0x0);
  _vm_page_free(piVar13);
  iVar3 = *(int *)((int)register0x00000038 + -0x10);
  sVar7 = *(sword *)(iVar3 + 0x44);
loc_F0082E94:
  _vm_page_queue_lock = 0;
  *(undefined4 *)(iVar3 + 0x10) = 0;
  *(sword *)(iVar3 + 0x44) = sVar7 + -1;
loc_F0082EA0:
  if (bVar1) {
    _vm_map_lookup_done(*(undefined4 *)((int)register0x00000038 + 0x44),
                        *(undefined4 *)((int)register0x00000038 + -0xc));
  }
  _vm_object_deallocate(*(undefined4 *)((int)register0x00000038 + -0x10));
  puVar2 = (undefined *)0x0;
locret_F0082EC0:
  return CONCAT44(param_2,puVar2);
}
/* GHIDRADEC_FUNCTION index=1757 start=0xf0082ec8 */

/* WARNING: Removing unreachable block (ram,0xf0082efc) */
/* WARNING: Removing unreachable block (ram,0xf0082f20) */
/* WARNING: Removing unreachable block (ram,0xf0082edc) */

undefined8 _vm_fault_wire(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  uint uVar3;
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
  uVar3 = *(uint *)(param_2 + 0xc);
  _pmap_pageable(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_2 + 8),uVar3,0);
  for (uVar2 = *(uint *)(param_2 + 8); uVar2 < uVar3; uVar2 = uVar2 + _page_size) {
    iVar1 = param_1;
    _vm_fault_wire_fast(param_1,uVar2,param_2);
    if (iVar1 != 0) {
      _vm_fault(param_1,uVar2,0,1,0);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1758 start=0xf0082f44 */

/* WARNING: Removing unreachable block (ram,0xf0082fcc) */
/* WARNING: Removing unreachable block (ram,0xf0082fbc) */
/* WARNING: Removing unreachable block (ram,0xf0082f98) */
/* WARNING: Removing unreachable block (ram,0xf0082fac) */
/* WARNING: Removing unreachable block (ram,0xf0082fc4) */
/* WARNING: Removing unreachable block (ram,0xf0082ffc) */
/* WARNING: Removing unreachable block (ram,0xf0082f68) */

undefined8 _vm_fault_unwire(int param_1,int param_2)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
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
  uVar4 = *(uint *)(param_2 + 0xc);
  iVar3 = *(int *)(param_1 + 0x24);
  do {
    do {
    } while (_vm_page_queue_lock != 0);
    puVar1 = &_vm_page_queue_lock;
    _simple_lock_try();
  } while (puVar1 == (undefined4 *)0x0);
  for (uVar5 = *(uint *)(param_2 + 8); uVar5 < uVar4; uVar5 = uVar5 + _page_size) {
    iVar2 = iVar3;
    _pmap_extract(iVar3,uVar5);
    if (iVar2 == 0) {
      _panic(aUnwirePageNotI);
    }
    _pmap_change_wiring(iVar3,uVar5,0);
    _vm_phys_to_vm_page(iVar2);
    _vm_page_unwire();
  }
  _vm_page_queue_lock = 0;
  _pmap_pageable(iVar3,*(undefined4 *)(param_2 + 8),uVar4,1);
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1759 start=0xf008300c */

/* WARNING: Removing unreachable block (ram,0xf00831d8) */
/* WARNING: Removing unreachable block (ram,0xf008319c) */
/* WARNING: Removing unreachable block (ram,0xf0083160) */
/* WARNING: Removing unreachable block (ram,0xf008313c) */
/* WARNING: Removing unreachable block (ram,0xf00830f8) */
/* WARNING: Removing unreachable block (ram,0xf00830cc) */
/* WARNING: Removing unreachable block (ram,0xf0083088) */
/* WARNING: Removing unreachable block (ram,0xf0083070) */
/* WARNING: Removing unreachable block (ram,0xf00830b4) */
/* WARNING: Removing unreachable block (ram,0xf00830dc) */
/* WARNING: Removing unreachable block (ram,0xf0083128) */
/* WARNING: Removing unreachable block (ram,0xf0083154) */
/* WARNING: Removing unreachable block (ram,0xf0083184) */
/* WARNING: Removing unreachable block (ram,0xf00831c4) */
/* WARNING: Removing unreachable block (ram,0xf0083214) */
/* WARNING: Removing unreachable block (ram,0xf0083028) */

undefined8 _vm_fault_copy_entry(undefined4 *param_1,undefined4 param_2,int param_3,int param_4)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  uint uVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  int iVar9;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 *puVar10;
  undefined4 unaff_i1;
  undefined4 uVar11;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  int iVar12;
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
  iVar9 = *(int *)(param_4 + 0x10);
  iVar8 = 0;
  iVar12 = *(int *)(param_4 + 0x14);
  iVar1 = *(int *)(param_3 + 0xc) - *(int *)(param_3 + 8);
  _vm_object_allocate();
  uVar7 = *(uint *)(param_3 + 8);
  *(int *)(param_3 + 0x10) = iVar1;
  *(undefined4 *)(param_3 + 0x14) = 0;
  uVar11 = *(undefined4 *)(param_3 + 0x20);
  puVar10 = param_1;
  if (uVar7 < *(uint *)(param_3 + 0xc)) {
    puVar10 = &_vm_page_free_count;
    do {
      do {
        do {
        } while (*(int *)(iVar1 + 0x10) != 0);
        piVar2 = (int *)(iVar1 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      do {
        iVar3 = iVar1;
        _vm_page_alloc_sequential(iVar1,iVar8,1);
        if (iVar3 == 0) {
          *(undefined4 *)(iVar1 + 0x10) = 0;
          do {
            do {
            } while (_vm_pages_needed_lock != 0);
            puVar4 = &_vm_pages_needed_lock;
            _simple_lock_try();
          } while (puVar4 == (undefined4 *)0x0);
          _thread_wakeup_prim(&_vm_pages_needed,0,0);
          _thread_sleep(&_vm_page_free_count,&_vm_pages_needed_lock,0);
          do {
            do {
            } while (*(int *)(iVar1 + 0x10) != 0);
            piVar2 = (int *)(iVar1 + 0x10);
            _simple_lock_try();
          } while (piVar2 == (int *)0x0);
        }
      } while (iVar3 == 0);
      do {
        do {
        } while (*(int *)(iVar9 + 0x10) != 0);
        piVar2 = (int *)(iVar9 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      iVar5 = iVar9;
      _vm_page_lookup(iVar9,iVar8 + iVar12);
      if (iVar5 == 0) {
        _panic(aVmFaultCopyWir);
      }
      _vm_page_copy(iVar5,iVar3);
      *(undefined4 *)(iVar9 + 0x10) = 0;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      _pmap_enter(param_1[9],uVar7,*(undefined4 *)(iVar3 + 0x24),uVar11,0);
      do {
        do {
        } while (*(int *)(iVar1 + 0x10) != 0);
        piVar2 = (int *)(iVar1 + 0x10);
        _simple_lock_try();
      } while (piVar2 == (int *)0x0);
      do {
        do {
        } while (_vm_page_queue_lock != 0);
        puVar4 = &_vm_page_queue_lock;
        _simple_lock_try();
      } while (puVar4 == (undefined4 *)0x0);
      _vm_page_activate(iVar3);
      _vm_page_queue_lock = 0;
      uVar6 = *(uint *)(iVar3 + 0x20);
      *(uint *)(iVar3 + 0x20) = uVar6 & 0x7fffffff;
      if ((uVar6 & 0x40000000) != 0) {
        *(uint *)(iVar3 + 0x20) = uVar6 & 0x3fffffff;
        _thread_wakeup_prim(iVar3,0,0);
      }
      iVar3 = _page_size;
      *(undefined4 *)(iVar1 + 0x10) = 0;
      uVar7 = uVar7 + iVar3;
      iVar8 = iVar8 + iVar3;
    } while (uVar7 < *(uint *)(param_3 + 0xc));
  }
  return CONCAT44(uVar11,puVar10);
}
/* GHIDRADEC_FUNCTION index=1760 start=0xf0083244 */

/* WARNING: Removing unreachable block (ram,0xf0083484) */
/* WARNING: Removing unreachable block (ram,0xf0083430) */
/* WARNING: Removing unreachable block (ram,0xf00833cc) */
/* WARNING: Removing unreachable block (ram,0xf00833a0) */
/* WARNING: Removing unreachable block (ram,0xf0083314) */
/* WARNING: Removing unreachable block (ram,0xf00832cc) */
/* WARNING: Removing unreachable block (ram,0xf0083328) */
/* WARNING: Removing unreachable block (ram,0xf00833b8) */
/* WARNING: Removing unreachable block (ram,0xf00833ec) */
/* WARNING: Removing unreachable block (ram,0xf0083448) */
/* WARNING: Removing unreachable block (ram,0xf008349c) */
/* WARNING: Removing unreachable block (ram,0xf00832a0) */

undefined8 _vm_fault_wire_fast(int param_1,int param_2,int param_3)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar9;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar10;
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
  DAT_f013c264._0_4_ = DAT_f013c264._0_4_ + 1;
  if ((*(uint *)(param_3 + 0x18) & 0xa0000000) != 0) {
    uVar8 = 5;
    goto locret_F00834A8;
  }
  uVar7 = *(uint *)(param_3 + 0x1c);
  iVar1 = *(int *)(param_3 + 8);
  iVar6 = *(int *)(param_3 + 0x14);
  iVar9 = *(int *)(param_3 + 0x10);
  do {
    do {
    } while (*(int *)(iVar9 + 0x10) != 0);
    piVar2 = (int *)(iVar9 + 0x10);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(sword *)(iVar9 + 0x18) = *(sword *)(iVar9 + 0x18) + 1;
  *(sword *)(iVar9 + 0x44) = *(sword *)(iVar9 + 0x44) + 1;
  iVar3 = iVar9;
  _vm_page_lookup(iVar9,(param_2 - iVar1) + iVar6);
  if (((iVar3 == 0) || ((*(uint *)(iVar3 + 0x20) & 0x84000000) != 0)) ||
     ((uVar7 & *(uint *)(iVar3 + 0x28)) != 0)) {
loc_F00833DC:
    *(undefined4 *)(iVar9 + 0x10) = 0;
    *(sword *)(iVar9 + 0x44) = *(sword *)(iVar9 + 0x44) + -1;
    _vm_object_deallocate();
    uVar8 = 5;
  }
  else {
    do {
      do {
      } while (_vm_page_queue_lock != 0);
      puVar4 = &_vm_page_queue_lock;
      _simple_lock_try();
    } while (puVar4 == (undefined4 *)0x0);
    _vm_page_wire(iVar3);
    _vm_page_queue_lock = 0;
    uVar5 = *(uint *)(iVar3 + 0x20);
    *(uint *)(iVar3 + 0x20) = uVar5 & 0xfbffffff | 0x80000000;
    if (*(int *)(iVar9 + 0x1c) == 0) {
      bVar10 = (uVar7 & 2) == 0;
    }
    else {
      bVar10 = (uVar7 & 2) == 0;
      if (!bVar10) {
        *(uint *)(iVar3 + 0x20) = uVar5 & 0x7bffffff;
        if ((uVar5 & 0x40000000) != 0) {
          *(uint *)(iVar3 + 0x20) = uVar5 & 0x3bffffff;
          _thread_wakeup_prim(iVar3,0,0);
        }
        do {
          do {
          } while (_vm_page_queue_lock != 0);
          puVar4 = &_vm_page_queue_lock;
          _simple_lock_try();
        } while (puVar4 == (undefined4 *)0x0);
        _vm_page_unwire(iVar3);
        _vm_page_queue_lock = 0;
        goto loc_F00833DC;
      }
      *(uint *)(iVar3 + 0x20) = uVar5 & 0xfbffffff | 0x80200000;
    }
    if (!bVar10) {
      *(uint *)(iVar3 + 0x20) = *(uint *)(iVar3 + 0x20) & 0xffdfffff;
    }
    *(undefined4 *)(iVar9 + 0x10) = 0;
    _pmap_enter(*(undefined4 *)(param_1 + 0x24),param_2,*(undefined4 *)(iVar3 + 0x24),uVar7,1);
    do {
      do {
      } while (*(int *)(iVar9 + 0x10) != 0);
      piVar2 = (int *)(iVar9 + 0x10);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    uVar7 = *(uint *)(iVar3 + 0x20);
    *(uint *)(iVar3 + 0x20) = uVar7 & 0x7fffffff;
    if ((uVar7 & 0x40000000) != 0) {
      *(uint *)(iVar3 + 0x20) = uVar7 & 0x3fffffff;
      _thread_wakeup_prim(iVar3,0,0);
    }
    *(undefined4 *)(iVar9 + 0x10) = 0;
    *(sword *)(iVar9 + 0x44) = *(sword *)(iVar9 + 0x44) + -1;
    _vm_object_deallocate();
    uVar8 = 0;
  }
locret_F00834A8:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=1761 start=0xf00834b0 */

/* WARNING: Removing unreachable block (ram,0xf0083518) */
/* WARNING: Removing unreachable block (ram,0xf0083508) */
/* WARNING: Removing unreachable block (ram,0xf00834f4) */
/* WARNING: Removing unreachable block (ram,0xf00834dc) */
/* WARNING: Removing unreachable block (ram,0xf00834d4) */
/* WARNING: Removing unreachable block (ram,0xf00834e4) */
/* WARNING: Removing unreachable block (ram,0xf0083500) */
/* WARNING: Removing unreachable block (ram,0xf0083510) */
/* WARNING: Removing unreachable block (ram,0xf0083520) */
/* WARNING: Removing unreachable block (ram,0xf00834cc) */

undefined8 _vm_mem_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar1;
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
  puVar1 = _mem_region;
  _vm_page_startup(_mem_region,_num_regions,_virtual_avail);
  _virtual_avail = puVar1;
  _zone_bootstrap();
  _vm_object_init();
  _vm_map_init();
  _kmem_init(_virtual_avail,_virtual_end);
  _pmap_init(_mem_region,_num_regions);
  _zone_init();
  _kalloc_init();
  _vm_pager_init();
  _vm_user_init();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1762 start=0xf0083698 */

/* WARNING: Removing unreachable block (ram,0xf00836b8) */
/* WARNING: Removing unreachable block (ram,0xf008369c) */

undefined8 _kmem_alloc(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
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
  uVar1 = param_3;
  _vm_object_allocate(param_3);
  sub_F0083530(param_1,param_2,param_3,1,uVar1,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1763 start=0xf00836c8 */

/* WARNING: Removing unreachable block (ram,0xf00837d4) */
/* WARNING: Removing unreachable block (ram,0xf00837a4) */
/* WARNING: Removing unreachable block (ram,0xf0083764) */
/* WARNING: Removing unreachable block (ram,0xf008373c) */
/* WARNING: Removing unreachable block (ram,0xf008372c) */
/* WARNING: Removing unreachable block (ram,0xf0083754) */
/* WARNING: Removing unreachable block (ram,0xf0083780) */
/* WARNING: Removing unreachable block (ram,0xf00837c0) */
/* WARNING: Removing unreachable block (ram,0xf00837e8) */
/* WARNING: Removing unreachable block (ram,0xf008370c) */

undefined8 _kmem_realloc(int param_1,uint param_2,int param_3,undefined4 *param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar5;
  undefined4 unaff_i1;
  int iVar6;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  uint uVar7;
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
  uVar1 = ~_page_mask;
  iVar6 = (param_2 + param_3 + _page_mask & uVar1) - (param_2 & uVar1);
  uVar7 = param_5 + _page_mask & uVar1;
  iVar2 = param_1;
  _vm_map_find(param_1,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar7,1);
  uVar5 = (uint)(iVar2 != 0);
  if (uVar5 == 0) {
    _vm_map_lookup_entry
              (param_1,*(undefined4 *)((int)register0x00000038 + -0xc),
               (undefined *)((int)register0x00000038 + -0x10));
    iVar2 = param_1;
    _vm_map_lookup_entry(param_1,param_2 & uVar1,(undefined *)((int)register0x00000038 + -0x14));
    if (iVar2 == 0) {
      _panic(aKmemRealloc);
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
    }
    else {
      iVar2 = *(int *)((int)register0x00000038 + -0x14);
    }
    iVar2 = *(int *)(iVar2 + 0x10);
    _vm_object_reference(iVar2);
    do {
      do {
      } while (*(int *)(iVar2 + 0x10) != 0);
      piVar3 = (int *)(iVar2 + 0x10);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if (*(int *)(iVar2 + 0x14) != iVar6) {
      _panic(aKmemRealloc_0);
    }
    *(uint *)(iVar2 + 0x14) = uVar7;
    *(undefined4 *)(iVar2 + 0x10) = 0;
    iVar4 = *(int *)((int)register0x00000038 + -0x10);
    *(int *)(iVar4 + 0x10) = iVar2;
    *(undefined4 *)(iVar4 + 0x14) = 0;
    _lock_done(param_1);
    sub_F00838B4(iVar2,iVar6,uVar7,1);
    _vm_map_pageable(param_1,*(int *)((int)register0x00000038 + -0xc),
                     *(int *)((int)register0x00000038 + -0xc) + uVar7,0);
    uVar5 = 0;
    *param_4 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(iVar6,uVar5);
}
/* GHIDRADEC_FUNCTION index=1764 start=0xf0083804 */

/* WARNING: Removing unreachable block (ram,0xf0083820) */

undefined8 _kmem_alloc_wired(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  sub_F0083530(param_1,param_2,param_3,1,_kernel_object,1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1765 start=0xf0083830 */

/* WARNING: Removing unreachable block (ram,0xf008385c) */

undefined8 _kmem_alloc_pageable(int param_1,undefined4 *param_2,int param_3)

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
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
  _vm_map_find(param_1,0,0,(undefined *)((int)register0x00000038 + -0xc),
               param_3 + _page_mask & ~_page_mask,1);
  if (param_1 == 0) {
    param_1 = 0;
    *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1766 start=0xf0083884 */

/* WARNING: Removing unreachable block (ram,0xf00838a4) */

undefined8 _kmem_free(undefined4 param_1,uint param_2,int param_3)

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
  _vm_map_remove(param_1,param_2 & ~_page_mask,param_2 + param_3 + _page_mask & ~_page_mask);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1767 start=0xf00839d0 */

/* WARNING: Removing unreachable block (ram,0xf0083a6c) */
/* WARNING: Removing unreachable block (ram,0xf0083a40) */
/* WARNING: Removing unreachable block (ram,0xf0083a24) */
/* WARNING: Removing unreachable block (ram,0xf0083a10) */
/* WARNING: Removing unreachable block (ram,0xf0083a2c) */
/* WARNING: Removing unreachable block (ram,0xf0083a58) */
/* WARNING: Removing unreachable block (ram,0xf0083a80) */
/* WARNING: Removing unreachable block (ram,0xf00839ec) */

undefined8
_kmem_suballoc(int param_1,undefined4 *param_2,int *param_3,int param_4,undefined4 param_5)

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
  uint uVar2;
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
  uVar2 = param_4 + _page_mask & ~_page_mask;
  _vm_object_reference(_vm_submap_object);
  *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
  iVar1 = param_1;
  _vm_map_find(param_1,_vm_submap_object,0,(undefined *)((int)register0x00000038 + -0xc),uVar2,1);
  if (iVar1 != 0) {
    _panic(aKmemSuballoc1);
  }
  _pmap_reference(*(undefined4 *)(param_1 + 0x24));
  iVar1 = *(int *)(param_1 + 0x24);
  _vm_map_create(iVar1,*(int *)((int)register0x00000038 + -0xc),
                 *(int *)((int)register0x00000038 + -0xc) + uVar2,param_5);
  if (iVar1 == 0) {
    _panic(aKmemSuballoc2);
  }
  _vm_map_submap(param_1,*(int *)((int)register0x00000038 + -0xc),
                 *(int *)((int)register0x00000038 + -0xc) + uVar2,iVar1);
  if (param_1 != 0) {
    _panic(aKmemSuballoc3);
  }
  *param_2 = *(undefined4 *)((int)register0x00000038 + -0xc);
  *param_3 = *(int *)((int)register0x00000038 + -0xc) + uVar2;
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1768 start=0xf0083aa4 */

/* WARNING: Removing unreachable block (ram,0xf0083ab8) */
/* WARNING: Removing unreachable block (ram,0xf0083ae4) */
/* WARNING: Removing unreachable block (ram,0xf0083aa8) */

undefined8 _kmem_init(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = param_1;
  _pmap_kernel();
  _vm_map_create();
  *(undefined4 *)((int)register0x00000038 + -0xc) = 0xf0000000;
  _kernel_map = uVar1;
  _vm_map_find();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1769 start=0xf0083af4 */

/* WARNING: Removing unreachable block (ram,0xf0083b14) */
/* WARNING: Removing unreachable block (ram,0xf0083b44) */

undefined8 _copyinmap(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (*(int *)(param_1 + 0x24) == _kernel_pmap) {
    _bcopy(param_2,param_3);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    if (*(int *)(*(int *)(_active_threads + 0xc) + 0xc) == param_1) {
      uVar1 = param_2;
      _copyin(param_2,param_3,param_4);
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1770 start=0xf0083b58 */

/* WARNING: Removing unreachable block (ram,0xf0083b78) */
/* WARNING: Removing unreachable block (ram,0xf0083ba8) */

undefined8 _copyoutmap(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar1;
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
  if (*(int *)(param_1 + 0x24) == _kernel_pmap) {
    _bcopy(param_2,param_3);
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
    if (*(int *)(*(int *)(_active_threads + 0xc) + 0xc) == param_1) {
      uVar1 = param_2;
      _copyout(param_2,param_3,param_4);
    }
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1771 start=0xf0083bbc */

/* WARNING: Removing unreachable block (ram,0xf0083bd8) */

undefined8
_kmem_alloc_zone(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

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
  sub_F0083530(param_1,param_2,param_3,1,_kernel_object,param_4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1772 start=0xf0083be8 */

/* WARNING: Removing unreachable block (ram,0xf0083e90) */
/* WARNING: Removing unreachable block (ram,0xf0083e6c) */
/* WARNING: Removing unreachable block (ram,0xf0083df8) */
/* WARNING: Removing unreachable block (ram,0xf0083dc8) */
/* WARNING: Removing unreachable block (ram,0xf0083da4) */
/* WARNING: Removing unreachable block (ram,0xf0083d10) */
/* WARNING: Removing unreachable block (ram,0xf0083c68) */
/* WARNING: Removing unreachable block (ram,0xf0083c1c) */
/* WARNING: Removing unreachable block (ram,0xf0083c44) */
/* WARNING: Removing unreachable block (ram,0xf0083c8c) */
/* WARNING: Removing unreachable block (ram,0xf0083d68) */
/* WARNING: Removing unreachable block (ram,0xf0083e04) */
/* WARNING: Removing unreachable block (ram,0xf0083dd0) */
/* WARNING: Removing unreachable block (ram,0xf0083e58) */
/* WARNING: Removing unreachable block (ram,0xf0083e74) */
/* WARNING: Removing unreachable block (ram,0xf0083eb0) */
/* WARNING: Removing unreachable block (ram,0xf0083c04) */

undefined8 _kmem_mb_alloc(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar5;
  uint uVar6;
  undefined4 unaff_l3;
  int iVar7;
  undefined4 unaff_l4;
  int iVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar9;
  undefined4 unaff_i1;
  uint uVar10;
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
  if (param_1 != _mb_map) {
    _panic(aYouFool);
  }
  uVar10 = param_2 + _page_mask & ~_page_mask;
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  iVar7 = *(int *)(param_1 + 0x10);
  if (iVar7 == param_1 + 0xc) {
    _lock_done(param_1);
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
    iVar7 = param_1;
    _vm_map_find(param_1,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar10,1);
    if (iVar7 == 0) {
      _vm_map_pageable(param_1,*(int *)((int)register0x00000038 + -0xc),
                       *(int *)((int)register0x00000038 + -0xc) + uVar10,0);
      uVar9 = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
    else {
      uVar9 = 0;
    }
    goto locret_F0083EBC;
  }
  if ((((iVar7 == *(int *)(param_1 + 0xc)) && (-1 < *(int *)(iVar7 + 0x18))) &&
      (*(int *)(iVar7 + 8) == *(int *)(param_1 + 0x14))) &&
     (((*(int *)(iVar7 + 0x20) == 7 && (*(int *)(iVar7 + 0x1c) == 3)) &&
      ((*(int *)(iVar7 + 0x24) == 1 && (*(sword *)(iVar7 + 0x28) != 0)))))) {
    iVar1 = *(int *)(param_1 + 0x18);
  }
  else {
    _panic(aMbMapAbusedEve);
    iVar1 = *(int *)(param_1 + 0x18);
  }
  uVar3 = *(uint *)(iVar7 + 0xc);
  if (uVar3 <= iVar1 - uVar10) {
    iVar1 = *(int *)(iVar7 + 8);
    iVar4 = *(int *)(iVar7 + 0x14);
    *(uint *)((int)register0x00000038 + -0xc) = uVar3;
    iVar8 = *(int *)(iVar7 + 0x10);
    uVar3 = (uVar3 - iVar1) + iVar4;
    *(uint *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) + uVar10;
    do {
      do {
      } while (*(int *)(iVar8 + 0x10) != 0);
      piVar2 = (int *)(iVar8 + 0x10);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    uVar5 = uVar3;
    for (uVar6 = uVar10 >> ((byte)_page_shift & 0x1f); uVar6 != 0; uVar6 = uVar6 - 1) {
      iVar1 = iVar8;
      _vm_page_alloc_sequential(iVar8,uVar5,0);
      if (iVar1 == 0) goto joined_r0xf0083db8;
      _vm_page_zero_fill(iVar1);
      iVar4 = _page_size;
      *(uint *)(iVar1 + 0x20) = *(uint *)(iVar1 + 0x20) & 0x7fffffff;
      uVar5 = uVar5 + iVar4;
    }
    uVar10 = *(uint *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(iVar8 + 0x10) = 0;
    if (uVar10 < *(uint *)(iVar7 + 0xc)) {
      do {
        do {
          do {
          } while (*(int *)(iVar8 + 0x10) != 0);
          piVar2 = (int *)(iVar8 + 0x10);
          _simple_lock_try();
        } while (piVar2 == (int *)0x0);
        iVar1 = iVar8;
        _vm_page_lookup(iVar8,uVar3);
        _vm_page_wire();
        *(undefined4 *)(iVar8 + 0x10) = 0;
        _pmap_enter(*(undefined4 *)(param_1 + 0x24),uVar10,*(undefined4 *)(iVar1 + 0x24),
                    *(undefined4 *)(iVar7 + 0x1c),1);
        uVar10 = uVar10 + _page_size;
        uVar3 = uVar3 + _page_size;
      } while (uVar10 < *(uint *)(iVar7 + 0xc));
    }
    _lock_done(param_1);
    uVar9 = *(undefined4 *)((int)register0x00000038 + -0xc);
    goto locret_F0083EBC;
  }
loc_F0083DF8:
  uVar9 = 0;
  _lock_done(param_1);
locret_F0083EBC:
  return CONCAT44(uVar10,uVar9);
joined_r0xf0083db8:
  while (uVar3 < uVar5) {
    uVar5 = uVar5 - _page_size;
    _vm_page_lookup(iVar8,uVar5);
    _vm_page_free();
  }
  *(undefined4 *)(iVar8 + 0x10) = 0;
  *(uint *)(iVar7 + 0xc) = *(int *)(iVar7 + 0xc) - uVar10;
  goto loc_F0083DF8;
}
/* GHIDRADEC_FUNCTION index=1773 start=0xf0083ec4 */

/* WARNING: Removing unreachable block (ram,0xf0083f60) */
/* WARNING: Removing unreachable block (ram,0xf0083f48) */
/* WARNING: Removing unreachable block (ram,0xf0083f1c) */
/* WARNING: Removing unreachable block (ram,0xf0083eec) */
/* WARNING: Removing unreachable block (ram,0xf0083f10) */
/* WARNING: Removing unreachable block (ram,0xf0083f78) */
/* WARNING: Removing unreachable block (ram,0xf0083f58) */
/* WARNING: Removing unreachable block (ram,0xf0083f68) */
/* WARNING: Removing unreachable block (ram,0xf0083ed8) */

undefined8 _kmem_alloc_wait(int param_1,int param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar3;
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
  uVar2 = param_2 + _page_mask & ~_page_mask;
  do {
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    _lock_set_recursive(param_1);
    *(undefined4 *)((int)register0x00000038 + -0xc) = *(undefined4 *)(param_1 + 0x14);
    iVar1 = param_1;
    _vm_map_find(param_1,0,0,(undefined *)((int)register0x00000038 + -0xc),uVar2,1);
    _lock_clear_recursive(param_1);
    if (iVar1 == 0) {
      _lock_done(param_1);
    }
    else {
      if ((uint)(*(int *)(param_1 + 0x18) - *(int *)(param_1 + 0x14)) < uVar2) {
        _lock_done(param_1);
        uVar3 = 0;
        goto locret_F0083F90;
      }
      _assert_wait(param_1,1);
      _lock_done(param_1);
      _thread_block();
    }
  } while (iVar1 != 0);
  uVar3 = *(undefined4 *)((int)register0x00000038 + -0xc);
locret_F0083F90:
  return CONCAT44(iVar1,uVar3);
}
/* GHIDRADEC_FUNCTION index=1774 start=0xf0083f98 */

/* WARNING: Removing unreachable block (ram,0xf0083fdc) */
/* WARNING: Removing unreachable block (ram,0xf0083fcc) */
/* WARNING: Removing unreachable block (ram,0xf0083fe4) */
/* WARNING: Removing unreachable block (ram,0xf0083f9c) */

undefined8 _kmem_free_wakeup(int param_1,uint param_2,int param_3)

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
  uint uVar1;
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
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  uVar1 = param_2 + param_3 + _page_mask;
  _vm_map_delete(param_1,param_2 & ~_page_mask,uVar1 & ~_page_mask);
  _thread_wakeup_prim(param_1,0,0);
  _lock_done(param_1);
  return CONCAT44(uVar1,param_1);
}
/* GHIDRADEC_FUNCTION index=1775 start=0xf0083ff4 */

/* WARNING: Removing unreachable block (ram,0xf008408c) */
/* WARNING: Removing unreachable block (ram,0xf0084058) */
/* WARNING: Removing unreachable block (ram,0xf0084030) */
/* WARNING: Removing unreachable block (ram,0xf0084074) */
/* WARNING: Removing unreachable block (ram,0xf00840a0) */
/* WARNING: Removing unreachable block (ram,0xf008400c) */

undefined8 _vm_map_init(undefined4 param_1,undefined4 param_2)

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
  uVar1 = 0x50;
  _zinit(0x50,0x19000,0,0,&aMaps);
  uVar2 = 0x2c;
  _vm_map_zone = uVar1;
  _zinit(0x2c,0x100000,0,0,aNonKernelMapEn);
  uVar1 = 0x2c;
  _vm_map_entry_zone = uVar2;
  _zinit(0x2c,_kentry_data_size,0,0,aKernelMapEntri);
  _vm_map_kentry_zone = uVar1;
  _zchange();
  _zcram(_vm_map_zone,_map_data,_map_data_size);
  _zcram(_vm_map_kentry_zone,_kentry_data,_kentry_data_size);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1776 start=0xf00840b0 */

/* WARNING: Removing unreachable block (ram,0xf00840d4) */
/* WARNING: Removing unreachable block (ram,0xf0084124) */
/* WARNING: Removing unreachable block (ram,0xf00840bc) */

undefined8
_vm_map_create(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
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
  iVar1 = _vm_map_zone;
  _zalloc();
  if (iVar1 == 0) {
    _panic(aVmMapCreate);
  }
  iVar2 = iVar1 + 0xc;
  *(int *)(iVar1 + 0x10) = iVar2;
  *(int *)(iVar1 + 0xc) = iVar2;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = param_4;
  *(undefined4 *)(iVar1 + 0x28) = 0;
  *(undefined4 *)(iVar1 + 0x30) = 1;
  *(undefined4 *)(iVar1 + 0x24) = param_1;
  *(undefined4 *)(iVar1 + 0x2c) = 1;
  *(undefined4 *)(iVar1 + 0x14) = param_2;
  *(undefined4 *)(iVar1 + 0x18) = param_3;
  *(undefined4 *)(iVar1 + 0x48) = 0;
  *(undefined4 *)(iVar1 + 0x44) = 0;
  *(int *)(iVar1 + 0x40) = iVar2;
  *(int *)(iVar1 + 0x38) = iVar2;
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  _lock_init(iVar1,1);
  *(undefined4 *)(iVar1 + 0x4c) = 0;
  *(undefined4 *)(iVar1 + 0x34) = 0;
  *(undefined4 *)(iVar1 + 0x3c) = 0;
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1777 start=0xf0084140 */

/* WARNING: Removing unreachable block (ram,0xf0084178) */
/* WARNING: Removing unreachable block (ram,0xf0084164) */

undefined8 __vm_map_entry_create(int param_1,undefined4 param_2)

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
  iVar1 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    iVar1 = _vm_map_entry_zone;
  }
  _zalloc();
  if (iVar1 == 0) {
    _panic(aVmMapEntryCrea);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1778 start=0xf0084188 */

/* WARNING: Removing unreachable block (ram,0xf00841b0) */

undefined8 __vm_map_entry_dispose(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
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
  uVar1 = _vm_map_kentry_zone;
  if (*(int *)(param_1 + 0x14) != 0) {
    uVar1 = _vm_map_entry_zone;
  }
  _zfree(uVar1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1779 start=0xf00841c0 */

/* WARNING: Removing unreachable block (ram,0xf00841e0) */

undefined8 _vm_map_reference(int param_1,undefined4 param_2)

{
  int *piVar1;
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
  if (param_1 != 0) {
    do {
      do {
      } while (*(int *)(param_1 + 0x34) != 0);
      piVar1 = (int *)(param_1 + 0x34);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x34) = 0;
    *(int *)(param_1 + 0x30) = *(int *)(param_1 + 0x30) + 1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1780 start=0xf008420c */

/* WARNING: Removing unreachable block (ram,0xf008427c) */
/* WARNING: Removing unreachable block (ram,0xf0084258) */
/* WARNING: Removing unreachable block (ram,0xf0084274) */
/* WARNING: Removing unreachable block (ram,0xf008428c) */
/* WARNING: Removing unreachable block (ram,0xf008422c) */

undefined8 _vm_map_deallocate(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
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
  if (param_1 != 0) {
    do {
      do {
      } while (*(int *)(param_1 + 0x34) != 0);
      piVar1 = (int *)(param_1 + 0x34);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x34) = 0;
    iVar2 = *(int *)(param_1 + 0x30) + -1;
    *(int *)(param_1 + 0x30) = iVar2;
    if (iVar2 < 1) {
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      _vm_map_delete(param_1,*(undefined4 *)(param_1 + 0x14),*(undefined4 *)(param_1 + 0x18));
      _pmap_destroy(*(undefined4 *)(param_1 + 0x24));
      _zfree(_vm_map_zone,param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1781 start=0xf008429c */

/* WARNING: Removing unreachable block (ram,0xf008439c) */
/* WARNING: Removing unreachable block (ram,0xf00843cc) */
/* WARNING: Removing unreachable block (ram,0xf00842d8) */

undefined8 _vm_map_insert(int param_1,int param_2,int param_3,uint param_4,uint param_5)

{
  int iVar1;
  int *piVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  if (param_4 < *(uint *)(param_1 + 0x14)) {
    uVar5 = 1;
  }
  else if ((*(uint *)(param_1 + 0x18) < param_5) || (param_5 <= param_4)) {
    uVar5 = 1;
  }
  else {
    iVar4 = param_1;
    _vm_map_lookup_entry(param_1,param_4,(undefined *)((int)register0x00000038 + -0xc));
    uVar5 = 3;
    if (iVar4 == 0) {
      iVar4 = *(int *)((int)register0x00000038 + -0xc);
      if (((((param_2 == 0) && (iVar4 != param_1 + 0xc)) && (*(uint *)(iVar4 + 0xc) == param_4)) &&
          (((*(uint *)(iVar4 + 0x18) & 0xa0000000) == 0 && (*(int *)(iVar4 + 0x24) == 1)))) &&
         ((*(int *)(iVar4 + 0x1c) == 3 &&
          ((*(int *)(iVar4 + 0x20) == 7 && (*(sword *)(iVar4 + 0x28) == 0)))))) {
        iVar1 = *(int *)(iVar4 + 0x10);
        _vm_object_coalesce(iVar1,0,*(undefined4 *)(iVar4 + 0x14),0,param_4 - *(int *)(iVar4 + 8),
                            param_5 - param_4);
        uVar5 = 0;
        if (iVar1 != 0) {
          *(uint *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (param_5 - *(int *)(iVar4 + 0xc));
          *(uint *)(iVar4 + 0xc) = param_5;
          goto locret_F00844A0;
        }
      }
      piVar2 = (int *)(param_1 + 0xc);
      __vm_map_entry_create();
      piVar2[2] = param_4;
      piVar2[3] = param_5;
      piVar2[4] = param_2;
      piVar2[5] = param_3;
      piVar2[6] = piVar2[6] & 0x5fffffff;
      piVar2[6] = piVar2[6] & 0xedffffff;
      if (*(int *)(param_1 + 0x2c) != 0) {
        piVar2[9] = 1;
        piVar2[7] = 3;
        piVar2[8] = 7;
        *(undefined2 *)(piVar2 + 10) = 0;
      }
      *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + 1;
      *piVar2 = iVar4;
      piVar3 = *(int **)(iVar4 + 4);
      iVar1 = *piVar2;
      piVar2[1] = (int)piVar3;
      *piVar3 = (int)piVar2;
      *(int **)(iVar1 + 4) = piVar2;
      *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) + (piVar2[3] - piVar2[2]);
      if ((*(int *)(param_1 + 0x40) == iVar4) && ((uint)piVar2[2] <= *(uint *)(iVar4 + 0xc))) {
        *(int **)(param_1 + 0x40) = piVar2;
      }
      uVar5 = 0;
    }
  }
locret_F00844A0:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1782 start=0xf00844a8 */

/* WARNING: Removing unreachable block (ram,0xf00845a8) */
/* WARNING: Removing unreachable block (ram,0xf008455c) */
/* WARNING: Removing unreachable block (ram,0xf00844c4) */

undefined8 _vm_map_lookup_entry(int param_1,uint param_2,undefined4 *param_3)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  bool bVar5;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x3c) != 0);
    piVar1 = (int *)(param_1 + 0x3c);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  puVar3 = *(undefined4 **)(param_1 + 0x38);
  *(undefined4 *)(param_1 + 0x3c) = 0;
  puVar2 = (undefined4 *)(param_1 + 0xc);
  if (puVar3 == puVar2) {
    puVar3 = *(undefined4 **)(param_1 + 0x10);
  }
  if (puVar3 < puVar2) {
    puVar2 = (undefined4 *)puVar3[1];
    puVar3 = *(undefined4 **)(param_1 + 0x10);
  }
  else {
    bVar5 = true;
    if (puVar3 == puVar2) goto loc_F0084584;
    uVar4 = 1;
    if (param_2 < (uint)puVar3[3]) {
      *param_3 = puVar3;
      goto locret_F00845C8;
    }
  }
  while( true ) {
    bVar5 = puVar3 == puVar2;
loc_F0084584:
    if (bVar5) goto loc_F008458C;
    if (param_2 < (uint)puVar3[3]) break;
    puVar3 = (undefined4 *)puVar3[1];
  }
  if (param_2 < (uint)puVar3[2]) {
loc_F008458C:
    *param_3 = *puVar3;
    do {
      do {
      } while (*(int *)(param_1 + 0x3c) != 0);
      piVar1 = (int *)(param_1 + 0x3c);
      _simple_lock_try();
      uVar4 = 0;
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x38) = *param_3;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  else {
    *param_3 = puVar3;
    do {
      do {
      } while (*(int *)(param_1 + 0x3c) != 0);
      piVar1 = (int *)(param_1 + 0x3c);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 **)(param_1 + 0x38) = puVar3;
    *(undefined4 *)(param_1 + 0x3c) = 0;
    uVar4 = 1;
  }
locret_F00845C8:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=1783 start=0xf00845d0 */

/* WARNING: Removing unreachable block (ram,0xf0084700) */
/* WARNING: Removing unreachable block (ram,0xf00846c8) */
/* WARNING: Removing unreachable block (ram,0xf0084640) */
/* WARNING: Removing unreachable block (ram,0xf00846f4) */
/* WARNING: Removing unreachable block (ram,0xf008467c) */
/* WARNING: Removing unreachable block (ram,0xf00845dc) */

undefined8
_vm_map_find(int param_1,undefined4 param_2,undefined4 param_3,uint *param_4,int param_5,int param_6
            )

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
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
  int iVar5;
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
  uVar4 = *param_4;
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_6 == 0) {
loc_F00846E4:
    iVar5 = param_1;
    _vm_map_insert(param_1,param_2,param_3,uVar4,uVar4 + param_5);
    _lock_done(param_1);
  }
  else {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (uVar4 < uVar2) {
      uVar4 = uVar2;
    }
    if (uVar4 <= *(uint *)(param_1 + 0x18)) {
      if (uVar4 == uVar2) {
        iVar5 = *(int *)(param_1 + 0x40);
        if (iVar5 != param_1 + 0xc) {
          uVar4 = *(uint *)(iVar5 + 0xc);
        }
      }
      else {
        iVar5 = param_1;
        _vm_map_lookup_entry(param_1,uVar4,(undefined *)((int)register0x00000038 + -0xc));
        if (iVar5 != 0) {
          uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0xc);
        }
        iVar5 = *(int *)((int)register0x00000038 + -0xc);
      }
      while( true ) {
        uVar2 = uVar4 + param_5;
        if ((*(uint *)(param_1 + 0x18) < uVar2) || (uVar2 < uVar4)) break;
        iVar3 = *(int *)(iVar5 + 4);
        if (iVar3 == param_1 + 0xc) {
          *param_4 = uVar4;
loc_F00846B4:
          do {
            do {
            } while (*(int *)(param_1 + 0x3c) != 0);
            piVar1 = (int *)(param_1 + 0x3c);
            _simple_lock_try();
          } while (piVar1 == (int *)0x0);
          *(int *)(param_1 + 0x38) = iVar5;
          *(undefined4 *)(param_1 + 0x3c) = 0;
          goto loc_F00846E4;
        }
        if (uVar2 <= *(uint *)(iVar3 + 8)) {
          *param_4 = uVar4;
          goto loc_F00846B4;
        }
        uVar4 = *(uint *)(iVar3 + 0xc);
        iVar5 = iVar3;
      }
    }
    _lock_done(param_1);
    iVar5 = 3;
  }
  return CONCAT44(param_2,iVar5);
}
/* GHIDRADEC_FUNCTION index=1784 start=0xf0084710 */

/* WARNING: Removing unreachable block (ram,0xf00847e0) */
/* WARNING: Removing unreachable block (ram,0xf00847d4) */
/* WARNING: Removing unreachable block (ram,0xf0084714) */

undefined8 __vm_map_clip_start(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
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
  piVar1 = param_1;
  __vm_map_entry_create();
  *piVar1 = *param_2;
  piVar1[1] = param_2[1];
  piVar1[2] = param_2[2];
  piVar1[3] = param_2[3];
  piVar1[4] = param_2[4];
  piVar1[5] = param_2[5];
  piVar1[6] = param_2[6];
  piVar1[7] = param_2[7];
  piVar1[8] = param_2[8];
  piVar1[9] = param_2[9];
  piVar1[10] = param_2[10];
  piVar1[3] = param_3;
  param_2[5] = param_2[5] + (param_3 - param_2[2]);
  param_2[2] = param_3;
  param_1[4] = param_1[4] + 1;
  *piVar1 = *param_2;
  piVar2 = *(int **)(*param_2 + 4);
  iVar3 = *piVar1;
  piVar1[1] = (int)piVar2;
  *piVar2 = (int)piVar1;
  *(int **)(iVar3 + 4) = piVar1;
  if ((param_2[6] & 0xa0000000U) == 0) {
    _vm_object_reference(piVar1[4]);
  }
  else {
    _vm_map_reference(piVar1[4]);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1785 start=0xf00847f0 */

/* WARNING: Removing unreachable block (ram,0xf00848b8) */
/* WARNING: Removing unreachable block (ram,0xf00848ac) */
/* WARNING: Removing unreachable block (ram,0xf00847f4) */

undefined8 __vm_map_clip_end(int *param_1,int *param_2,int param_3)

{
  int *piVar1;
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
  piVar1 = param_1;
  __vm_map_entry_create();
  *piVar1 = *param_2;
  piVar1[1] = param_2[1];
  piVar1[2] = param_2[2];
  piVar1[3] = param_2[3];
  piVar1[4] = param_2[4];
  piVar1[5] = param_2[5];
  piVar1[6] = param_2[6];
  piVar1[7] = param_2[7];
  piVar1[8] = param_2[8];
  piVar1[9] = param_2[9];
  piVar1[10] = param_2[10];
  param_2[3] = param_3;
  piVar1[2] = param_3;
  piVar1[5] = piVar1[5] + (param_3 - param_2[2]);
  param_1[4] = param_1[4] + 1;
  *piVar1 = (int)param_2;
  piVar2 = (int *)param_2[1];
  iVar3 = *piVar1;
  piVar1[1] = (int)piVar2;
  *piVar2 = (int)piVar1;
  *(int **)(iVar3 + 4) = piVar1;
  if ((param_2[6] & 0xa0000000U) == 0) {
    _vm_object_reference(piVar1[4]);
  }
  else {
    _vm_map_reference(piVar1[4]);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1786 start=0xf00848c8 */

/* WARNING: Removing unreachable block (ram,0xf00849f0) */
/* WARNING: Removing unreachable block (ram,0xf008496c) */
/* WARNING: Removing unreachable block (ram,0xf0084918) */
/* WARNING: Removing unreachable block (ram,0xf008493c) */
/* WARNING: Removing unreachable block (ram,0xf00849cc) */
/* WARNING: Removing unreachable block (ram,0xf00849f8) */
/* WARNING: Removing unreachable block (ram,0xf00848d0) */

undefined8 _vm_map_submap(int param_1,uint param_2,uint param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
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
  uVar3 = 4;
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    param_2 = *(uint *)(param_1 + 0x14);
  }
  if (*(uint *)(param_1 + 0x18) < param_3) {
    param_3 = *(uint *)(param_1 + 0x18);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar2 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  iVar1 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar2 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 4);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  else if (*(uint *)(iVar1 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 0xc,iVar1,param_2);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
  }
  if (param_3 < *(uint *)(iVar1 + 0xc)) {
    __vm_map_clip_end(param_1 + 0xc,iVar1,param_3);
  }
  iVar2 = *(int *)((int)register0x00000038 + -0xc);
  if ((((*(uint *)(iVar2 + 8) == param_2) && (*(uint *)(iVar2 + 0xc) == param_3)) &&
      (-1 < (int)*(uint *)(iVar2 + 0x18))) &&
     ((iVar1 = *(int *)(iVar2 + 0x10), iVar1 == _vm_submap_object &&
      ((*(uint *)(iVar2 + 0x18) & 0x10000000) == 0)))) {
    *(undefined4 *)(iVar2 + 0x10) = 0;
    _vm_object_deallocate(iVar1);
    uVar3 = 0;
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    *(undefined4 *)(iVar2 + 0x10) = param_4;
    *(uint *)(iVar2 + 0x18) = *(uint *)(iVar2 + 0x18) | 0x20000000;
    _vm_map_reference();
  }
  _lock_done(param_1);
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=1787 start=0xf0084a08 */

/* WARNING: Removing unreachable block (ram,0xf0084ca8) */
/* WARNING: Removing unreachable block (ram,0xf0084c50) */
/* WARNING: Removing unreachable block (ram,0xf0084b98) */
/* WARNING: Removing unreachable block (ram,0xf0084a98) */
/* WARNING: Removing unreachable block (ram,0xf0084a78) */
/* WARNING: Removing unreachable block (ram,0xf0084a54) */
/* WARNING: Removing unreachable block (ram,0xf0084a88) */
/* WARNING: Removing unreachable block (ram,0xf0084b50) */
/* WARNING: Removing unreachable block (ram,0xf0084bb8) */
/* WARNING: Removing unreachable block (ram,0xf0084c74) */
/* WARNING: Removing unreachable block (ram,0xf0084cc4) */
/* WARNING: Removing unreachable block (ram,0xf0084a0c) */

undefined8 _vm_map_protect(int param_1,uint param_2,uint param_3,uint param_4,int param_5)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
  undefined4 unaff_i1;
  int iVar9;
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
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    param_2 = *(uint *)(param_1 + 0x14);
  }
  if (*(uint *)(param_1 + 0x18) < param_3) {
    param_3 = *(uint *)(param_1 + 0x18);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar9 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar9 == 0) {
    *(undefined4 *)((int)register0x00000038 + -0xc) =
         *(undefined4 *)(*(int *)((int)register0x00000038 + -0xc) + 4);
  }
  else if (*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 8) < param_2) {
    __vm_map_clip_start(param_1 + 0xc,*(int *)((int)register0x00000038 + -0xc),param_2);
    iVar9 = *(int *)((int)register0x00000038 + -0xc);
    goto loc_F0084AB8;
  }
  iVar9 = *(int *)((int)register0x00000038 + -0xc);
loc_F0084AB8:
  if (iVar9 == param_1 + 0xc) {
    iVar9 = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
    uVar1 = *(uint *)(iVar9 + 8);
    while (uVar1 < param_3) {
      if ((*(uint *)(iVar9 + 0x18) & 0x20000000) != 0) {
        _lock_done(param_1);
        uVar8 = 4;
        goto locret_F0084CD0;
      }
      if ((param_4 & *(uint *)(iVar9 + 0x20)) != param_4) {
        _lock_done(param_1);
        uVar8 = 2;
        goto locret_F0084CD0;
      }
      iVar9 = *(int *)(iVar9 + 4);
      if (iVar9 == param_1 + 0xc) {
        iVar9 = *(int *)((int)register0x00000038 + -0xc);
        goto loc_F0084B1C;
      }
      uVar1 = *(uint *)(iVar9 + 8);
    }
    iVar9 = *(int *)((int)register0x00000038 + -0xc);
  }
loc_F0084B1C:
  if (iVar9 != param_1 + 0xc) {
    uVar1 = *(uint *)(iVar9 + 8);
    while (uVar1 < param_3) {
      if (param_3 < *(uint *)(iVar9 + 0xc)) {
        __vm_map_clip_end(param_1 + 0xc,iVar9,param_3);
      }
      uVar1 = *(uint *)(iVar9 + 0x1c);
      if (param_5 == 0) {
        *(uint *)(iVar9 + 0x1c) = param_4;
      }
      else {
        *(uint *)(iVar9 + 0x20) = param_4;
        *(uint *)(iVar9 + 0x1c) = param_4 & uVar1;
      }
      uVar3 = *(uint *)(iVar9 + 0x1c);
      if (uVar3 == uVar1) {
        iVar9 = *(int *)(iVar9 + 4);
      }
      else if (*(int *)(iVar9 + 0x18) < 0) {
        _lock_write(*(undefined4 *)(iVar9 + 0x10));
        *(int *)(*(int *)(iVar9 + 0x10) + 0x4c) = *(int *)(*(int *)(iVar9 + 0x10) + 0x4c) + 1;
        _vm_map_lookup_entry
                  (*(undefined4 *)(iVar9 + 0x10),*(undefined4 *)(iVar9 + 0x14),
                   (undefined *)((int)register0x00000038 + -0x10));
        uVar1 = *(int *)(iVar9 + 0x14) + (*(int *)(iVar9 + 0xc) - *(int *)(iVar9 + 8));
        if (*(int *)((int)register0x00000038 + -0x10) != *(int *)(iVar9 + 0x10) + 0xc) {
          do {
            iVar7 = *(int *)((int)register0x00000038 + -0x10);
            uVar3 = *(uint *)(iVar7 + 8);
            if (uVar1 <= uVar3) break;
            uVar6 = *(uint *)(iVar9 + 0x14);
            if (uVar3 < uVar6) {
              uVar3 = uVar6;
            }
            uVar4 = *(uint *)(iVar7 + 0xc);
            if (*(uint *)(iVar7 + 0xc) < uVar1) {
              uVar4 = uVar1;
            }
            if ((*(uint *)(iVar7 + 0x18) & 0x10000000) == 0) {
              uVar5 = *(uint *)(iVar9 + 0x1c) & 7;
            }
            else {
              uVar5 = *(uint *)(iVar9 + 0x1c) & 0xfffffffd;
            }
            _pmap_protect(*(undefined4 *)(param_1 + 0x24),(uVar3 - uVar6) + *(int *)(iVar9 + 8),
                          (uVar4 - uVar6) + *(int *)(iVar9 + 8),uVar5);
            iVar2 = *(int *)(*(int *)((int)register0x00000038 + -0x10) + 4);
            iVar7 = *(int *)(iVar9 + 0x10);
            *(int *)((int)register0x00000038 + -0x10) = iVar2;
          } while (iVar2 != iVar7 + 0xc);
        }
        _lock_done(*(undefined4 *)(iVar9 + 0x10));
        iVar9 = *(int *)(iVar9 + 4);
      }
      else {
        if ((*(uint *)(*(int *)((int)register0x00000038 + -0xc) + 0x18) & 0x10000000) == 0) {
          uVar3 = uVar3 & 7;
        }
        else {
          uVar3 = uVar3 & 0xfffffffd;
        }
        _pmap_protect(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(iVar9 + 8),
                      *(undefined4 *)(iVar9 + 0xc),uVar3);
        iVar9 = *(int *)(iVar9 + 4);
      }
      if (iVar9 == param_1 + 0xc) break;
      uVar1 = *(uint *)(iVar9 + 8);
    }
  }
  _lock_done(param_1);
  uVar8 = 0;
locret_F0084CD0:
  return CONCAT44(iVar9,uVar8);
}
/* GHIDRADEC_FUNCTION index=1788 start=0xf0084cd8 */

/* WARNING: Removing unreachable block (ram,0xf0084dbc) */
/* WARNING: Removing unreachable block (ram,0xf0084d44) */
/* WARNING: Removing unreachable block (ram,0xf0084d6c) */
/* WARNING: Removing unreachable block (ram,0xf0084dd8) */
/* WARNING: Removing unreachable block (ram,0xf0084cfc) */

undefined8 _vm_map_inherit(int param_1,uint param_2,uint param_3,int param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined4 unaff_l0;
  uint uVar4;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar5;
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
  if (param_4 < 3) {
    if (param_4 < 0) {
      uVar5 = 4;
    }
    else {
      _lock_write(param_1);
      *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
      if (param_2 < *(uint *)(param_1 + 0x14)) {
        param_2 = *(uint *)(param_1 + 0x14);
      }
      if (*(uint *)(param_1 + 0x18) < param_3) {
        param_3 = *(uint *)(param_1 + 0x18);
      }
      if (param_3 < param_2) {
        param_2 = param_3;
      }
      iVar1 = param_1;
      _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
      uVar4 = *(uint *)((int)register0x00000038 + -0xc);
      if (iVar1 == 0) {
        uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 4);
      }
      else if (*(uint *)(uVar4 + 8) < param_2) {
        __vm_map_clip_start(param_1 + 0xc,uVar4,param_2);
      }
      uVar2 = param_1 + 0xc;
      if (uVar4 != uVar2) {
        uVar3 = *(uint *)(uVar4 + 8);
        while (param_2 = uVar2, uVar3 < param_3) {
          if (param_3 < *(uint *)(uVar4 + 0xc)) {
            __vm_map_clip_end(param_1 + 0xc,uVar4,param_3);
          }
          *(int *)(uVar4 + 0x24) = param_4;
          uVar4 = *(uint *)(uVar4 + 4);
          if (uVar4 == uVar2) break;
          uVar3 = *(uint *)(uVar4 + 8);
        }
      }
      _lock_done(param_1);
      uVar5 = 0;
    }
  }
  else {
    uVar5 = 4;
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1789 start=0xf0084dec */

/* WARNING: Removing unreachable block (ram,0xf0084f30) */
/* WARNING: Removing unreachable block (ram,0xf0085068) */
/* WARNING: Removing unreachable block (ram,0xf00850c4) */
/* WARNING: Removing unreachable block (ram,0xf0085080) */
/* WARNING: Removing unreachable block (ram,0xf008501c) */
/* WARNING: Removing unreachable block (ram,0xf0084f8c) */
/* WARNING: Removing unreachable block (ram,0xf0084e3c) */
/* WARNING: Removing unreachable block (ram,0xf0084e64) */
/* WARNING: Removing unreachable block (ram,0xf0084fec) */
/* WARNING: Removing unreachable block (ram,0xf0085078) */
/* WARNING: Removing unreachable block (ram,0xf0085058) */
/* WARNING: Removing unreachable block (ram,0xf00850e8) */
/* WARNING: Removing unreachable block (ram,0xf0084f08) */
/* WARNING: Removing unreachable block (ram,0xf00850fc) */
/* WARNING: Removing unreachable block (ram,0xf0084df4) */

undefined8 _vm_map_pageable(int param_1,uint param_2,uint param_3,int param_4)

{
  uint uVar1;
  sword sVar3;
  uint uVar2;
  undefined4 unaff_l0;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar7;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar8;
  bool bVar9;
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
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    param_2 = *(uint *)(param_1 + 0x14);
  }
  if (*(uint *)(param_1 + 0x18) < param_3) {
    param_3 = *(uint *)(param_1 + 0x18);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar6 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  iVar4 = *(int *)((int)register0x00000038 + -0xc);
  if (iVar6 == 0) {
    iVar4 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 4);
  }
  else if (*(uint *)(iVar4 + 8) < param_2) {
    __vm_map_clip_start(param_1 + 0xc,iVar4,param_2);
  }
  *(int *)((int)register0x00000038 + -0xc) = iVar4;
  if (param_4 == 0) {
    iVar6 = *(int *)((int)register0x00000038 + -0xc);
    if (iVar6 != param_1 + 0xc) {
      param_2 = 0xfdffffff;
      uVar5 = *(uint *)(iVar6 + 8);
      while (uVar5 < param_3) {
        if (param_3 < *(uint *)(iVar6 + 0xc)) {
          __vm_map_clip_end(param_1 + 0xc,iVar6,param_3);
        }
        sVar3 = *(sword *)(iVar6 + 0x28) + 1;
        *(sword *)(iVar6 + 0x28) = sVar3;
        if (sVar3 == 1) {
          if (-1 < (int)*(uint *)(iVar6 + 0x18)) {
            if ((*(uint *)(iVar6 + 0x18) & 0x2000000) == 0) {
              iVar4 = *(int *)(iVar6 + 0x10);
            }
            else {
              if ((*(uint *)(iVar6 + 0x1c) & 2) != 0) {
                _vm_object_shadow(iVar6 + 0x10,iVar6 + 0x14,
                                  *(int *)(iVar6 + 0xc) - *(int *)(iVar6 + 8));
                *(uint *)(iVar6 + 0x18) = *(uint *)(iVar6 + 0x18) & 0xfdffffff;
                goto loc_F008502C;
              }
              iVar4 = *(int *)(iVar6 + 0x10);
            }
            if (iVar4 != 0) {
              iVar6 = *(int *)(iVar6 + 4);
              goto loc_F0085030;
            }
            iVar4 = *(int *)(iVar6 + 0xc) - *(int *)(iVar6 + 8);
            _vm_object_allocate();
            *(int *)(iVar6 + 0x10) = iVar4;
            *(undefined4 *)(iVar6 + 0x14) = 0;
          }
loc_F008502C:
          iVar6 = *(int *)(iVar6 + 4);
        }
        else {
          iVar6 = *(int *)(iVar6 + 4);
        }
loc_F0085030:
        if (iVar6 == param_1 + 0xc) break;
        uVar5 = *(uint *)(iVar6 + 8);
      }
    }
    bVar9 = param_1 != _kernel_map;
    if (bVar9) {
      _lock_set_recursive(param_1);
      _lock_write_to_read(param_1);
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
    else {
      _lock_done(param_1);
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
    uVar2 = param_1 + 0xc;
    if (uVar5 != uVar2) {
      uVar1 = *(uint *)(uVar5 + 8);
      while (param_2 = uVar2, uVar1 < param_3) {
        if (*(sword *)(uVar5 + 0x28) == 1) {
          _vm_fault_wire(param_1,uVar5);
          uVar5 = *(uint *)(uVar5 + 4);
        }
        else {
          uVar5 = *(uint *)(uVar5 + 4);
        }
        if (uVar5 == uVar2) break;
        uVar1 = *(uint *)(uVar5 + 8);
      }
    }
    bVar8 = !bVar9;
    if (!bVar8) {
      _lock_clear_recursive(param_1);
      bVar8 = !bVar9;
    }
  }
  else {
    if (iVar4 == param_1 + 0xc) {
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
    else {
      uVar5 = *(uint *)(iVar4 + 8);
      while (uVar5 < param_3) {
        if (*(sword *)(iVar4 + 0x28) == 0) {
          _lock_done(param_1);
          uVar7 = 4;
          goto locret_F0085108;
        }
        iVar4 = *(int *)(iVar4 + 4);
        if (iVar4 == param_1 + 0xc) {
          uVar5 = *(uint *)((int)register0x00000038 + -0xc);
          goto loc_F0084ED4;
        }
        uVar5 = *(uint *)(iVar4 + 8);
      }
      uVar5 = *(uint *)((int)register0x00000038 + -0xc);
    }
loc_F0084ED4:
    uVar2 = param_1 + 0xc;
    bVar8 = false;
    if (uVar5 != uVar2) {
      uVar1 = *(uint *)(uVar5 + 8);
      while (bVar8 = false, param_2 = uVar2, uVar1 < param_3) {
        if (param_3 < *(uint *)(uVar5 + 0xc)) {
          __vm_map_clip_end(param_1 + 0xc,uVar5,param_3);
        }
        sVar3 = *(sword *)(uVar5 + 0x28);
        *(sword *)(uVar5 + 0x28) = sVar3 + -1;
        if (sVar3 == 1) {
          _vm_fault_unwire(param_1,uVar5);
          uVar5 = *(uint *)(uVar5 + 4);
        }
        else {
          uVar5 = *(uint *)(uVar5 + 4);
        }
        bVar8 = false;
        if (uVar5 == uVar2) break;
        uVar1 = *(uint *)(uVar5 + 8);
      }
    }
  }
  if (bVar8) {
    uVar7 = 0;
  }
  else {
    _lock_done(param_1);
    uVar7 = 0;
  }
locret_F0085108:
  return CONCAT44(param_2,uVar7);
}
/* GHIDRADEC_FUNCTION index=1790 start=0xf0085110 */

/* WARNING: Removing unreachable block (ram,0xf0085118) */

undefined8 _vm_map_entry_unwire(undefined4 param_1,int param_2)

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
  _vm_fault_unwire(param_1,param_2);
  *(undefined2 *)(param_2 + 0x28) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1791 start=0xf008512c */

/* WARNING: Removing unreachable block (ram,0xf0085198) */
/* WARNING: Removing unreachable block (ram,0xf00851a8) */
/* WARNING: Removing unreachable block (ram,0xf00851b4) */
/* WARNING: Removing unreachable block (ram,0xf0085140) */

undefined8 _vm_map_entry_delete(int param_1,int *param_2)

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
  if (*(sword *)(param_2 + 10) != 0) {
    _vm_map_entry_unwire(param_1,param_2);
  }
  *(int *)(param_1 + 0x1c) = *(int *)(param_1 + 0x1c) + -1;
  *(int *)param_2[1] = *param_2;
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)(param_1 + 0x28) = *(int *)(param_1 + 0x28) - (param_2[3] - param_2[2]);
  if ((param_2[6] & 0xa0000000U) == 0) {
    _vm_object_deallocate(param_2[4]);
  }
  else {
    _vm_map_deallocate(param_2[4]);
  }
  __vm_map_entry_dispose(param_1 + 0xc,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1792 start=0xf00851c4 */

/* WARNING: Removing unreachable block (ram,0xf0085314) */
/* WARNING: Removing unreachable block (ram,0xf00852e0) */
/* WARNING: Removing unreachable block (ram,0xf0085294) */
/* WARNING: Removing unreachable block (ram,0xf0085204) */
/* WARNING: Removing unreachable block (ram,0xf0085220) */
/* WARNING: Removing unreachable block (ram,0xf00852bc) */
/* WARNING: Removing unreachable block (ram,0xf0085304) */
/* WARNING: Removing unreachable block (ram,0xf0085320) */
/* WARNING: Removing unreachable block (ram,0xf00851d0) */

sqword _vm_map_delete(int param_1,uint param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 *puVar5;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 *puVar8;
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
  iVar6 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  puVar5 = *(undefined4 **)((int)register0x00000038 + -0xc);
  if (iVar6 == 0) {
    puVar5 = *(undefined4 **)(*(int *)((int)register0x00000038 + -0xc) + 4);
  }
  else {
    if ((uint)puVar5[2] < param_2) {
      __vm_map_clip_start(param_1 + 0xc,puVar5,param_2);
    }
    do {
      do {
      } while (*(int *)(param_1 + 0x3c) != 0);
      piVar1 = (int *)(param_1 + 0x3c);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_1 + 0x38) = *puVar5;
    *(undefined4 *)(param_1 + 0x3c) = 0;
  }
  if (param_2 <= *(uint *)(*(int *)(param_1 + 0x40) + 8)) {
    *(undefined4 *)(param_1 + 0x40) = *puVar5;
  }
  if (puVar5 != (undefined4 *)(param_1 + 0xc)) {
    uVar2 = puVar5[2];
    while (uVar2 < param_3) {
      if (param_3 < (uint)puVar5[3]) {
        __vm_map_clip_end(param_1 + 0xc,puVar5,param_3);
      }
      puVar8 = (undefined4 *)puVar5[1];
      param_2 = puVar5[2];
      iVar7 = puVar5[3];
      iVar6 = puVar5[4];
      if (*(sword *)(puVar5 + 10) != 0) {
        _vm_map_entry_unwire(param_1,puVar5);
      }
      if (iVar6 == _kernel_object) {
        _vm_object_page_remove(iVar6,puVar5[5],puVar5[5] + (iVar7 - param_2));
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      else {
        iVar3 = *(int *)(param_1 + 0x2c);
      }
      if (iVar3 == 0) {
        _vm_object_pmap_remove(iVar6,puVar5[5],puVar5[5] + (iVar7 - param_2));
        uVar4 = *(undefined4 *)(param_1 + 0x24);
      }
      else {
        uVar4 = *(undefined4 *)(param_1 + 0x24);
      }
      _pmap_remove(uVar4,param_2,iVar7);
      _vm_map_entry_delete(param_1,puVar5);
      if (puVar8 == (undefined4 *)(param_1 + 0xc)) break;
      puVar5 = puVar8;
      uVar2 = puVar8[2];
    }
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=1793 start=0xf0085340 */

/* WARNING: Removing unreachable block (ram,0xf0085390) */
/* WARNING: Removing unreachable block (ram,0xf008539c) */
/* WARNING: Removing unreachable block (ram,0xf0085348) */

undefined8 _vm_map_remove(int param_1,uint param_2,uint param_3)

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
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    param_2 = *(uint *)(param_1 + 0x14);
  }
  if (*(uint *)(param_1 + 0x18) < param_3) {
    param_3 = *(uint *)(param_1 + 0x18);
  }
  if (param_3 < param_2) {
    param_2 = param_3;
  }
  iVar1 = param_1;
  _vm_map_delete(param_1,param_2,param_3);
  _lock_done(param_1);
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1794 start=0xf00853ac */

/* WARNING: Removing unreachable block (ram,0xf00853b8) */

undefined8 _vm_map_check_protection(int param_1,uint param_2,uint param_3,uint param_4)

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
  undefined4 uVar2;
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
  iVar1 = param_1;
  _vm_map_lookup_entry(param_1,param_2,(undefined *)((int)register0x00000038 + -0xc));
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  else {
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    if (param_2 < param_3) {
      do {
        if (iVar1 == param_1 + 0xc) {
          uVar2 = 0;
          goto locret_F0085424;
        }
        if (param_2 < *(uint *)(iVar1 + 8)) {
          uVar2 = 0;
          goto locret_F0085424;
        }
        if ((*(uint *)(iVar1 + 0x1c) & param_4) != param_4) {
          uVar2 = 0;
          goto locret_F0085424;
        }
        param_2 = *(uint *)(iVar1 + 0xc);
        iVar1 = *(int *)(iVar1 + 4);
      } while (param_2 < param_3);
    }
    uVar2 = 1;
  }
locret_F0085424:
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1795 start=0xf008542c */

/* WARNING: Removing unreachable block (ram,0xf00855f0) */
/* WARNING: Removing unreachable block (ram,0xf0085554) */
/* WARNING: Removing unreachable block (ram,0xf00854f0) */
/* WARNING: Removing unreachable block (ram,0xf00854a0) */
/* WARNING: Removing unreachable block (ram,0xf0085490) */
/* WARNING: Removing unreachable block (ram,0xf0085620) */
/* WARNING: Removing unreachable block (ram,0xf0085534) */
/* WARNING: Removing unreachable block (ram,0xf008557c) */
/* WARNING: Removing unreachable block (ram,0xf008560c) */
/* WARNING: Removing unreachable block (ram,0xf0085464) */

undefined8 _vm_map_copy_entry(int param_1,int param_2,int param_3,int param_4)

{
  undefined4 uVar1;
  int *piVar2;
  undefined4 unaff_l0;
  undefined4 uVar3;
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
  bool bVar4;
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
  if (((*(uint *)(param_3 + 0x18) & 0x20000000) == 0) &&
     ((*(uint *)(param_4 + 0x18) & 0x20000000) == 0)) {
    if (*(sword *)(param_4 + 0x28) != 0) {
      _vm_map_entry_unwire(param_2,param_4);
    }
    if (*(int *)(param_2 + 0x2c) == 0) {
      _vm_object_pmap_remove
                (*(undefined4 *)(param_4 + 0x10),*(int *)(param_4 + 0x14),
                 *(int *)(param_4 + 0x14) + (*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8)));
      uVar1 = *(undefined4 *)(param_2 + 0x24);
    }
    else {
      uVar1 = *(undefined4 *)(param_2 + 0x24);
    }
    _pmap_remove(uVar1,*(undefined4 *)(param_4 + 8),*(undefined4 *)(param_4 + 0xc));
    if (*(sword *)(param_3 + 0x28) == 0) {
      if ((*(uint *)(param_3 + 0x18) & 0x2000000) == 0) {
        bVar4 = false;
        if (*(int *)(param_1 + 0x2c) == 0) {
          do {
            do {
            } while (*(int *)(param_1 + 0x34) != 0);
            piVar2 = (int *)(param_1 + 0x34);
            _simple_lock_try();
          } while (piVar2 == (int *)0x0);
          *(undefined4 *)(param_1 + 0x34) = 0;
          bVar4 = *(int *)(param_1 + 0x30) != 1;
        }
        if (bVar4) {
          _vm_object_pmap_copy
                    (*(undefined4 *)(param_3 + 0x10),*(int *)(param_3 + 0x14),
                     *(int *)(param_3 + 0x14) + (*(int *)(param_3 + 0xc) - *(int *)(param_3 + 8)));
          uVar1 = *(undefined4 *)(param_3 + 0x10);
        }
        else {
          _pmap_protect(*(undefined4 *)(param_1 + 0x24),*(undefined4 *)(param_3 + 8),
                        *(undefined4 *)(param_3 + 0xc),*(uint *)(param_3 + 0x1c) & 0xfffffffd);
          uVar1 = *(undefined4 *)(param_3 + 0x10);
        }
      }
      else {
        uVar1 = *(undefined4 *)(param_3 + 0x10);
      }
      uVar3 = *(undefined4 *)(param_4 + 0x10);
      _vm_object_copy(uVar1,*(undefined4 *)(param_3 + 0x14),
                      *(int *)(param_3 + 0xc) - *(int *)(param_3 + 8),param_4 + 0x10,param_4 + 0x14,
                      (undefined *)((int)register0x00000038 + -0xc));
      if (*(int *)((int)register0x00000038 + -0xc) != 0) {
        *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 0x2000000;
      }
      *(uint *)(param_4 + 0x18) = *(uint *)(param_4 + 0x18) | 0x2000000;
      *(uint *)(param_3 + 0x18) = *(uint *)(param_3 + 0x18) | 0x10000000;
      *(uint *)(param_4 + 0x18) = *(uint *)(param_4 + 0x18) | 0x10000000;
      if ((*(uint *)(param_3 + 0x1c) & 4) != 0) {
        *(uint *)(param_4 + 0x1c) = *(uint *)(param_4 + 0x1c) | *(uint *)(param_4 + 0x20) & 4;
      }
      _vm_object_deallocate(uVar3);
      _pmap_copy(*(undefined4 *)(param_2 + 0x24),*(undefined4 *)(param_1 + 0x24),
                 *(int *)(param_4 + 8),*(int *)(param_4 + 0xc) - *(int *)(param_4 + 8),
                 *(undefined4 *)(param_3 + 8));
    }
    else {
      _vm_fault_copy_entry(param_2,param_1,param_4,param_3);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1796 start=0xf0085630 */

/* WARNING: Removing unreachable block (ram,0xf0085a30) */
/* WARNING: Removing unreachable block (ram,0xf0085a38) */
/* WARNING: Removing unreachable block (ram,0xf00859cc) */
/* WARNING: Removing unreachable block (ram,0xf00859dc) */
/* WARNING: Removing unreachable block (ram,0xf00859ec) */
/* WARNING: Removing unreachable block (ram,0xf00859f0) */
/* WARNING: Removing unreachable block (ram,0xf0085998) */
/* WARNING: Removing unreachable block (ram,0xf0085950) */
/* WARNING: Removing unreachable block (ram,0xf0085930) */
/* WARNING: Removing unreachable block (ram,0xf0085964) */
/* WARNING: Removing unreachable block (ram,0xf00858b0) */
/* WARNING: Removing unreachable block (ram,0xf0085850) */
/* WARNING: Removing unreachable block (ram,0xf0085808) */
/* WARNING: Removing unreachable block (ram,0xf00857b8) */
/* WARNING: Removing unreachable block (ram,0xf0085788) */
/* WARNING: Removing unreachable block (ram,0xf008571c) */
/* WARNING: Removing unreachable block (ram,0xf00856f8) */
/* WARNING: Removing unreachable block (ram,0xf0085690) */
/* WARNING: Removing unreachable block (ram,0xf008567c) */
/* WARNING: Removing unreachable block (ram,0xf00856bc) */
/* WARNING: Removing unreachable block (ram,0xf0085748) */
/* WARNING: Removing unreachable block (ram,0xf0085768) */
/* WARNING: Removing unreachable block (ram,0xf0085798) */
/* WARNING: Removing unreachable block (ram,0xf00857d0) */
/* WARNING: Removing unreachable block (ram,0xf0085824) */
/* WARNING: Removing unreachable block (ram,0xf008587c) */
/* WARNING: Removing unreachable block (ram,0xf00858e8) */
/* WARNING: Removing unreachable block (ram,0xf0085914) */
/* WARNING: Removing unreachable block (ram,0xf0085948) */
/* WARNING: Removing unreachable block (ram,0xf0085984) */
/* WARNING: Removing unreachable block (ram,0xf00859ac) */
/* WARNING: Removing unreachable block (ram,0xf00856a8) */
/* WARNING: Removing unreachable block (ram,0xf0085a60) */
/* WARNING: Removing unreachable block (ram,0xf0085a74) */
/* WARNING: Removing unreachable block (ram,0xf0085a58) */

undefined8 _vm_map_copy(int param_1,int param_2,uint param_3,int param_4,uint param_5,int param_6)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l3;
  int iVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint uVar9;
  undefined4 unaff_l7;
  uint uVar10;
  undefined4 unaff_i0;
  undefined4 uVar11;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar12;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  *(int *)((int)register0x00000038 + -0x14) = param_4;
  uVar10 = param_3 + param_4;
  uVar9 = param_5 + param_4;
  *(undefined4 *)((int)register0x00000038 + -0x24) = *(undefined4 *)((int)register0x00000038 + 0x5c)
  ;
  if ((uVar10 < param_3) || (uVar9 < param_5)) {
    uVar11 = 3;
    goto locret_F0085A80;
  }
  if (param_2 == param_1) {
loc_F0085690:
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  }
  else {
    if (param_2 < param_1) {
      _lock_write(param_2);
      *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + 1;
      goto loc_F0085690;
    }
    _lock_write(param_1);
    *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
    _lock_write(param_2);
    *(int *)(param_2 + 0x4c) = *(int *)(param_2 + 0x4c) + 1;
  }
  iVar2 = *(int *)(param_2 + 0x2c);
  *(undefined4 *)((int)register0x00000038 + -0x1c) = 0;
  if ((iVar2 == 0) || (*(int *)(param_1 + 0x2c) == 0)) goto loc_F0085760;
  iVar2 = param_2;
  _vm_map_check_protection(param_2,param_5,uVar9,1);
  if (iVar2 == 0) {
loc_F0085730:
    *(undefined4 *)((int)register0x00000038 + -0x1c) = 2;
  }
  else if (param_6 == 0) {
    iVar2 = param_1;
    _vm_map_check_protection(param_1,param_3,uVar10,2);
    if (iVar2 == 0) goto loc_F0085730;
loc_F0085760:
    puVar5 = (undefined *)((int)register0x00000038 + -0xc);
    _vm_map_lookup_entry(param_2,param_5,puVar5);
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if (*(uint *)(iVar2 + 8) < param_5) {
      __vm_map_clip_start(param_2 + 0xc,iVar2,param_5);
    }
    _vm_map_lookup_entry(param_1,param_3,puVar5);
    iVar1 = *(int *)((int)register0x00000038 + -0xc);
    if (*(uint *)(iVar1 + 8) < param_3) {
      __vm_map_clip_start(param_1 + 0xc,iVar1,param_3);
    }
    bVar13 = false;
    if (iVar2 == iVar1) {
      _vm_map_lookup_entry(param_2,param_5,puVar5);
      iVar2 = *(int *)((int)register0x00000038 + -0xc);
      bVar13 = iVar2 == iVar1;
    }
    if (!bVar13) {
      if (param_5 < uVar9) {
        uVar3 = *(uint *)(iVar2 + 0xc);
        do {
          if (uVar9 < uVar3) {
            __vm_map_clip_end(param_2 + 0xc,iVar2,uVar9);
          }
          if (uVar10 < *(uint *)(iVar1 + 0xc)) {
            __vm_map_clip_end(param_1 + 0xc,iVar1,uVar10);
          }
          if ((uint)(*(int *)(iVar2 + 8) + (*(int *)(iVar1 + 0xc) - *(int *)(iVar1 + 8))) <
              *(uint *)(iVar2 + 0xc)) {
            __vm_map_clip_end(param_2 + 0xc,iVar2);
          }
          if ((uint)(*(int *)(iVar1 + 8) + (*(int *)(iVar2 + 0xc) - *(int *)(iVar2 + 8))) <
              *(uint *)(iVar1 + 0xc)) {
            __vm_map_clip_end(param_1 + 0xc,iVar1);
          }
          if ((*(uint *)(iVar2 + 0x18) & 0x80000000) == 0) {
            if ((*(uint *)(iVar1 + 0x18) & 0x80000000) != 0) {
              iVar4 = *(int *)(iVar1 + 0xc);
              goto loc_F00858C0;
            }
            _vm_map_copy_entry(param_2,param_1,iVar2,iVar1);
            uVar3 = *(uint *)(iVar2 + 0xc);
          }
          else {
            iVar4 = *(int *)(iVar1 + 0xc);
loc_F00858C0:
            iVar4 = iVar4 - *(int *)(iVar1 + 8);
            if ((*(uint *)(iVar2 + 0x18) & 0x80000000) == 0) {
              uVar11 = *(undefined4 *)(iVar2 + 8);
              _lock_set_recursive(param_2);
              iVar8 = param_2;
            }
            else {
              uVar11 = *(undefined4 *)(iVar2 + 0x14);
              iVar8 = *(int *)(iVar2 + 0x10);
            }
            if ((*(uint *)(iVar1 + 0x18) & 0x80000000) == 0) {
              iVar6 = *(int *)(iVar1 + 8);
              _lock_set_recursive(param_1);
              iVar12 = param_1;
            }
            else {
              iVar12 = *(int *)(iVar1 + 0x10);
              iVar6 = *(int *)(iVar1 + 0x14);
              iVar7 = iVar6 + iVar4;
              if (iVar12 != iVar8) {
                _lock_write(iVar12);
                *(int *)(iVar12 + 0x4c) = *(int *)(iVar12 + 0x4c) + 1;
                _vm_map_delete(iVar12,iVar6,iVar7);
                _vm_map_insert(iVar12,0,0,iVar6,iVar7);
                _lock_done(iVar12);
              }
            }
            _vm_map_copy(iVar12,iVar8,iVar6,iVar4,uVar11,0,0);
            if (param_1 == iVar12) {
              _lock_clear_recursive(param_1);
            }
            if (param_2 == iVar8) {
              _lock_clear_recursive(param_2);
              uVar3 = *(uint *)(iVar2 + 0xc);
            }
            else {
              uVar3 = *(uint *)(iVar2 + 0xc);
            }
          }
          iVar1 = *(int *)(iVar1 + 4);
          iVar2 = *(int *)(iVar2 + 4);
          if (uVar9 <= uVar3) goto loc_f0085a04;
          uVar3 = *(uint *)(iVar2 + 0xc);
        } while( true );
      }
      iVar2 = *(int *)(param_2 + 0x2c);
      goto loc_F0085A08;
    }
  }
  else {
    iVar2 = param_1;
    _vm_map_insert(param_1,0,0,param_3,uVar10);
    *(int *)((int)register0x00000038 + -0x1c) = iVar2;
    if (iVar2 == 0) goto loc_F0085760;
  }
loc_F0085A40:
  iVar1 = *(int *)((int)register0x00000038 + -0x24);
loc_F0085A44:
  if (iVar1 != 0) {
    _vm_map_delete(param_2,param_5,param_5 + *(int *)((int)register0x00000038 + -0x14));
  }
  _lock_done(param_2);
  if (param_2 == param_1) {
    uVar11 = *(undefined4 *)((int)register0x00000038 + -0x1c);
  }
  else {
    _lock_done(param_1);
    uVar11 = *(undefined4 *)((int)register0x00000038 + -0x1c);
  }
locret_F0085A80:
  return CONCAT44(param_2,uVar11);
loc_f0085a04:
  iVar2 = *(int *)(param_2 + 0x2c);
loc_F0085A08:
  iVar1 = *(int *)((int)register0x00000038 + -0x24);
  if (iVar2 != 0) goto loc_F0085A40;
  goto loc_F0085A44;
}
/* GHIDRADEC_FUNCTION index=1797 start=0xf0085a88 */

/* WARNING: Removing unreachable block (ram,0xf0085c94) */
/* WARNING: Removing unreachable block (ram,0xf0085be8) */
/* WARNING: Removing unreachable block (ram,0xf0085b34) */
/* WARNING: Removing unreachable block (ram,0xf0085d70) */
/* WARNING: Removing unreachable block (ram,0xf0085ca4) */
/* WARNING: Removing unreachable block (ram,0xf0085ab4) */
/* WARNING: Removing unreachable block (ram,0xf0085aa4) */
/* WARNING: Removing unreachable block (ram,0xf0085af0) */
/* WARNING: Removing unreachable block (ram,0xf0085da0) */
/* WARNING: Removing unreachable block (ram,0xf0085d84) */
/* WARNING: Removing unreachable block (ram,0xf0085b44) */
/* WARNING: Removing unreachable block (ram,0xf0085c4c) */
/* WARNING: Removing unreachable block (ram,0xf0085dc4) */
/* WARNING: Removing unreachable block (ram,0xf0085a90) */

undefined8 _vm_map_fork(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int *piVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar7;
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
  _lock_write(param_1);
  *(int *)(param_1 + 0x4c) = *(int *)(param_1 + 0x4c) + 1;
  iVar1 = 0;
  _pmap_create();
  _vm_map_create();
  piVar7 = *(int **)(param_1 + 0x10);
  if (piVar7 == (int *)(param_1 + 0xc)) {
loc_F0085DBC:
    *(undefined4 *)(iVar1 + 0x28) = *(undefined4 *)(param_1 + 0x28);
    _lock_done(param_1);
    return CONCAT44(param_2,iVar1);
  }
  uVar4 = piVar7[6];
  do {
    if ((uVar4 & 0x20000000) != 0) {
      _panic(aVmMapForkEncou);
    }
    iVar2 = piVar7[9];
    if (iVar2 == 1) {
      piVar3 = (int *)(iVar1 + 0xc);
      __vm_map_entry_create();
      *piVar3 = *piVar7;
      piVar3[1] = piVar7[1];
      piVar3[2] = piVar7[2];
      piVar3[3] = piVar7[3];
      piVar3[4] = piVar7[4];
      piVar3[5] = piVar7[5];
      piVar3[6] = piVar7[6];
      piVar3[7] = piVar7[7];
      piVar3[8] = piVar7[8];
      piVar3[9] = piVar7[9];
      piVar3[10] = piVar7[10];
      *(undefined2 *)(piVar3 + 10) = 0;
      piVar3[4] = 0;
      piVar3[6] = piVar3[6] & 0x7fffffff;
      *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
      *piVar3 = *(int *)(iVar1 + 0xc);
      piVar5 = *(int **)(*(int *)(iVar1 + 0xc) + 4);
      iVar2 = *piVar3;
      piVar3[1] = (int)piVar5;
      *piVar5 = (int)piVar3;
      *(int **)(iVar2 + 4) = piVar3;
      if ((piVar7[6] & 0x80000000U) == 0) {
        _vm_map_copy_entry(param_1,iVar1,piVar7,piVar3);
      }
      else {
        iVar2 = iVar1;
        _vm_map_copy(iVar1,piVar7[4],piVar3[2],piVar3[3] - piVar3[2],piVar7[5],0,0);
        if (iVar2 != 0) {
          _printf(aVmMapForkCopyI);
          piVar7 = (int *)piVar7[1];
          goto loc_F0085DAC;
        }
      }
      piVar7 = (int *)piVar7[1];
    }
    else if (iVar2 < 2) {
      if (iVar2 == 0) {
        iVar2 = 0;
        if ((piVar7[6] & 0x80000000U) == 0) {
          _vm_map_create(0,piVar7[2],piVar7[3],1);
          *(undefined4 *)(iVar2 + 0x2c) = 0;
          piVar3 = (int *)(iVar2 + 0xc);
          __vm_map_entry_create();
          *piVar3 = *piVar7;
          piVar3[1] = piVar7[1];
          piVar3[2] = piVar7[2];
          piVar3[3] = piVar7[3];
          piVar3[4] = piVar7[4];
          piVar3[5] = piVar7[5];
          piVar3[6] = piVar7[6];
          piVar3[7] = piVar7[7];
          piVar3[8] = piVar7[8];
          piVar3[9] = piVar7[9];
          piVar3[10] = piVar7[10];
          *(int *)(iVar2 + 0x1c) = *(int *)(iVar2 + 0x1c) + 1;
          *piVar3 = *(int *)(iVar2 + 0xc);
          piVar5 = *(int **)(*(int *)(iVar2 + 0xc) + 4);
          iVar6 = *piVar3;
          piVar3[1] = (int)piVar5;
          *piVar5 = (int)piVar3;
          *(int **)(iVar6 + 4) = piVar3;
          piVar7[6] = piVar7[6] | 0x80000000;
          piVar7[4] = iVar2;
          piVar7[5] = piVar7[2];
        }
        piVar3 = (int *)(iVar1 + 0xc);
        __vm_map_entry_create();
        *piVar3 = *piVar7;
        piVar3[1] = piVar7[1];
        piVar3[2] = piVar7[2];
        piVar3[3] = piVar7[3];
        piVar3[4] = piVar7[4];
        piVar3[5] = piVar7[5];
        piVar3[6] = piVar7[6];
        piVar3[7] = piVar7[7];
        piVar3[8] = piVar7[8];
        piVar3[9] = piVar7[9];
        piVar3[10] = piVar7[10];
        _vm_map_reference(piVar3[4]);
        *(int *)(iVar1 + 0x1c) = *(int *)(iVar1 + 0x1c) + 1;
        *piVar3 = *(int *)(iVar1 + 0xc);
        piVar5 = *(int **)(*(int *)(iVar1 + 0xc) + 4);
        iVar2 = *piVar3;
        piVar3[1] = (int)piVar5;
        *piVar5 = (int)piVar3;
        *(int **)(iVar2 + 4) = piVar3;
        _pmap_copy(*(undefined4 *)(iVar1 + 0x24),*(undefined4 *)(param_1 + 0x24),piVar3[2],
                   piVar7[3] - piVar7[2]);
        piVar7 = (int *)piVar7[1];
      }
      else {
        piVar7 = (int *)piVar7[1];
      }
    }
    else {
      piVar7 = (int *)piVar7[1];
    }
loc_F0085DAC:
    if (piVar7 == (int *)(param_1 + 0xc)) goto loc_F0085DBC;
    uVar4 = piVar7[6];
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1798 start=0xf0085dd4 */

/* WARNING: Removing unreachable block (ram,0xf0086034) */
/* WARNING: Removing unreachable block (ram,0xf0085fe4) */
/* WARNING: Removing unreachable block (ram,0xf0085f94) */
/* WARNING: Removing unreachable block (ram,0xf0085f58) */
/* WARNING: Removing unreachable block (ram,0xf0085f24) */
/* WARNING: Removing unreachable block (ram,0xf0085f00) */
/* WARNING: Removing unreachable block (ram,0xf0085e84) */
/* WARNING: Removing unreachable block (ram,0xf0085e00) */
/* WARNING: Removing unreachable block (ram,0xf0085e54) */
/* WARNING: Removing unreachable block (ram,0xf0085ea4) */
/* WARNING: Removing unreachable block (ram,0xf0085f10) */
/* WARNING: Removing unreachable block (ram,0xf0085f2c) */
/* WARNING: Removing unreachable block (ram,0xf0085f7c) */
/* WARNING: Removing unreachable block (ram,0xf0085fb4) */
/* WARNING: Removing unreachable block (ram,0xf0085ff4) */
/* WARNING: Removing unreachable block (ram,0xf0085fd0) */
/* WARNING: Removing unreachable block (ram,0xf0085de4) */

undefined8
_vm_map_lookup(int *param_1,uint param_2,uint param_3,int *param_4,undefined4 *param_5,int *param_6)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  int iVar6;
  undefined4 unaff_l3;
  uint uVar7;
  undefined4 unaff_l4;
  uint uVar8;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  uint *puVar9;
  undefined4 unaff_l7;
  uint *puVar10;
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
  puVar10 = *(uint **)((int)register0x00000038 + 0x5c);
  puVar9 = *(uint **)((int)register0x00000038 + 0x60);
  iVar3 = *param_1;
loc_F0085DE4:
  do {
    _lock_read(iVar3);
    do {
      do {
      } while (*(int *)(iVar3 + 0x3c) != 0);
      piVar1 = (int *)(iVar3 + 0x3c);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    iVar5 = *(int *)(iVar3 + 0x38);
    *(undefined4 *)(iVar3 + 0x3c) = 0;
    *param_4 = iVar5;
    if (((iVar5 == iVar3 + 0xc) || (param_2 < *(uint *)(iVar5 + 8))) ||
       (*(uint *)(iVar5 + 0xc) <= param_2)) {
      iVar6 = iVar3;
      _vm_map_lookup_entry(iVar3,param_2,(undefined *)((int)register0x00000038 + -0xc));
      iVar5 = *(int *)((int)register0x00000038 + -0xc);
      if (iVar6 != 0) {
        *param_4 = iVar5;
        uVar4 = *(uint *)(iVar5 + 0x18);
        goto loc_F0085E70;
      }
loc_F0085F2C:
      _lock_done(iVar3);
      uVar11 = 1;
      goto locret_F008606C;
    }
    uVar4 = *(uint *)(iVar5 + 0x18);
loc_F0085E70:
    if ((uVar4 & 0x20000000) == 0) {
      uVar4 = *(uint *)(iVar5 + 0x1c);
      if ((param_3 & uVar4) != param_3) {
        _lock_done(iVar3);
        uVar11 = 2;
        goto locret_F008606C;
      }
      uVar7 = (uint)(*(sword *)(iVar5 + 0x28) != 0);
      *puVar9 = uVar7;
      if (uVar7 != 0) {
        uVar4 = *(uint *)(iVar5 + 0x1c);
        param_3 = uVar4;
      }
      uVar7 = *(uint *)(iVar5 + 0x18) >> 0x1f ^ 1;
      iVar6 = iVar3;
      uVar8 = param_2;
      if (uVar7 == 0) {
        iVar6 = *(int *)(iVar5 + 0x10);
        uVar8 = (param_2 - *(int *)(iVar5 + 8)) + *(int *)(iVar5 + 0x14);
        _lock_read(iVar6);
        iVar2 = iVar6;
        _vm_map_lookup_entry(iVar6,uVar8,(undefined *)((int)register0x00000038 + -0x10));
        iVar5 = *(int *)((int)register0x00000038 + -0x10);
        if (iVar2 == 0) {
          _lock_done(iVar6);
          goto loc_F0085F2C;
        }
      }
      if ((*(uint *)(iVar5 + 0x18) & 0x2000000) == 0) {
loc_F0085FA4:
        iVar2 = *(int *)(iVar5 + 0x10);
loc_F0085FA8:
        if (iVar2 != 0) {
          iVar3 = *(int *)(iVar5 + 8);
          goto loc_F0086000;
        }
        iVar2 = iVar6;
        _lock_read_to_write();
        if (iVar2 == 0) {
          iVar3 = *(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 8);
          _vm_object_allocate();
          *(int *)(iVar5 + 0x10) = iVar3;
          *(undefined4 *)(iVar5 + 0x14) = 0;
          _lock_write_to_read(iVar6);
          iVar3 = *(int *)(iVar5 + 8);
loc_F0086000:
          *param_6 = (uVar8 - iVar3) + *(int *)(iVar5 + 0x14);
          *param_5 = *(undefined4 *)(iVar5 + 0x10);
          if (uVar7 == 0) {
            do {
              do {
              } while (*(int *)(iVar6 + 0x34) != 0);
              piVar1 = (int *)(iVar6 + 0x34);
              _simple_lock_try();
            } while (piVar1 == (int *)0x0);
            *(undefined4 *)(iVar6 + 0x34) = 0;
            uVar7 = (uint)(*(int *)(iVar6 + 0x30) == 1);
          }
          *puVar10 = uVar4;
          uVar11 = 0;
          **(uint **)((int)register0x00000038 + 100) = uVar7;
locret_F008606C:
          return CONCAT44(param_2,uVar11);
        }
      }
      else {
        if ((param_3 & 2) == 0) {
          uVar4 = uVar4 & 0xfffffffd;
          goto loc_F0085FA4;
        }
        iVar2 = iVar6;
        _lock_read_to_write();
        if (iVar2 == 0) {
          _vm_object_shadow(iVar5 + 0x10,iVar5 + 0x14,*(int *)(iVar5 + 0xc) - *(int *)(iVar5 + 8));
          *(uint *)(iVar5 + 0x18) = *(uint *)(iVar5 + 0x18) & 0xfdffffff;
          _lock_write_to_read(iVar6);
          iVar2 = *(int *)(iVar5 + 0x10);
          goto loc_F0085FA8;
        }
      }
      if (iVar6 != iVar3) {
        _lock_done(iVar3);
      }
      goto loc_F0085DE4;
    }
    iVar5 = *(int *)(iVar5 + 0x10);
    *param_1 = iVar5;
    _lock_done(iVar3);
    iVar3 = iVar5;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1799 start=0xf0086074 */

/* WARNING: Removing unreachable block (ram,0xf0086090) */
/* WARNING: Removing unreachable block (ram,0xf0086088) */

undefined8 _vm_map_lookup_done(undefined4 param_1,int param_2)

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
  if (*(int *)(param_2 + 0x18) < 0) {
    _lock_done(*(undefined4 *)(param_2 + 0x10));
  }
  _lock_done(param_1);
  return CONCAT44(param_2,param_1);
}

