/* GHIDRADEC_FUNCTION index=200 start=0xf000f9dc */

/* WARNING: Removing unreachable block (ram,0xf000f9ec) */
/* WARNING: Removing unreachable block (ram,0xf000f9e0) */

undefined8 _crget(undefined4 param_1,undefined4 param_2)

{
  sword *psVar1;
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
  psVar1 = (sword *)0x2a;
  _kalloc();
  _bzero();
  *psVar1 = *psVar1 + 1;
  _cractive = _cractive + 1;
  return CONCAT44(param_2,psVar1);
}
/* GHIDRADEC_FUNCTION index=201 start=0xf000fa18 */

/* WARNING: Removing unreachable block (ram,0xf000fa44) */
/* WARNING: Removing unreachable block (ram,0xf000fa60) */
/* WARNING: Removing unreachable block (ram,0xf000fa1c) */

undefined8 _crfree(sword *param_1,undefined4 param_2)

{
  sword sVar1;
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
  _splusclock();
  sVar1 = *param_1;
  *param_1 = sVar1 + -1;
  if ((sword)(sVar1 + -1) == 0) {
    _kfree(param_1,0x2a);
    _cractive = _cractive + -1;
  }
  _splx();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=202 start=0xf000fa70 */

/* WARNING: Removing unreachable block (ram,0xf000fa84) */
/* WARNING: Removing unreachable block (ram,0xf000fa8c) */
/* WARNING: Removing unreachable block (ram,0xf000fa74) */

undefined8 _crcopy(undefined2 *param_1,undefined4 param_2)

{
  undefined2 *puVar1;
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
  puVar1 = param_1;
  _crget();
  _memcpy();
  _crfree(param_1);
  *puVar1 = 1;
  return CONCAT44(param_2,puVar1);
}
/* GHIDRADEC_FUNCTION index=203 start=0xf000faa4 */

/* WARNING: Removing unreachable block (ram,0xf000fab8) */
/* WARNING: Removing unreachable block (ram,0xf000faa8) */

undefined8 _crdup(undefined2 *param_1,undefined4 param_2)

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
  _crget();
  _memcpy();
  *param_1 = 1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=204 start=0xf000fad0 */

/* WARNING: Removing unreachable block (ram,0xf000fb04) */
/* WARNING: Removing unreachable block (ram,0xf000fb2c) */
/* WARNING: Removing unreachable block (ram,0xf000fae4) */

undefined8 _setsid(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
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
  iVar3 = *_active_u;
  iVar1 = (int)*(sword *)(iVar3 + 0x30);
  _get_posix_proc();
  iVar2 = (int)*(sword *)(iVar3 + 0x30);
  if ((*(int *)(*(int *)(iVar1 + 0x10) + 0xc) == iVar2) || (_pgfind(), iVar2 != 0)) {
    *(undefined *)(dword_F0133DDC + 0x38) = 1;
  }
  else {
    _enterpgrp(iVar3,(int)*(sword *)(iVar3 + 0x30),1);
    *(int *)(dword_F0133DDC + 0x30) = (int)*(sword *)(iVar3 + 0x30);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=205 start=0xf000fb48 */

/* WARNING: Removing unreachable block (ram,0xf000fc60) */
/* WARNING: Removing unreachable block (ram,0xf000fbb8) */
/* WARNING: Removing unreachable block (ram,0xf000fba4) */
/* WARNING: Removing unreachable block (ram,0xf000fbd8) */
/* WARNING: Removing unreachable block (ram,0xf000fca4) */
/* WARNING: Removing unreachable block (ram,0xf000fb7c) */

undefined8 _setpgid(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  int *piVar5;
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
  piVar5 = *(int **)(dword_F0133DDC + 0x24);
  iVar4 = *_active_u;
  if (piVar5[1] < 0) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    goto locret_F000FCAC;
  }
  iVar1 = (int)*(sword *)(iVar4 + 0x30);
  _get_posix_proc();
  iVar3 = *piVar5;
  if ((iVar3 == 0) || (iVar3 == *(sword *)(iVar4 + 0x30))) {
    iVar2 = *(int *)(iVar1 + 0x10);
loc_F000FC28:
    if (*(int *)(*(int *)(iVar2 + 8) + 4) != iVar4) {
      iVar3 = piVar5[1];
      if (iVar3 == 0) {
        piVar5[1] = (int)*(sword *)(iVar4 + 0x30);
      }
      else if ((iVar3 != *(sword *)(iVar4 + 0x30)) &&
              ((_pgfind(), iVar3 == 0 ||
               (*(int *)(iVar3 + 8) != *(int *)(*(int *)(iVar1 + 0x10) + 8))))) goto loc_F000FC90;
      _enterpgrp(iVar4,piVar5[1],0);
      goto locret_F000FCAC;
    }
  }
  else {
    _pfind();
    if ((iVar3 == 0) || (iVar4 = iVar3, _inferior(), iVar4 == 0)) {
      *(undefined *)(dword_F0133DDC + 0x38) = 3;
      goto locret_F000FCAC;
    }
    iVar4 = (int)*(sword *)(iVar3 + 0x30);
    _get_posix_proc();
    if (*(int *)(*(int *)(iVar4 + 0x10) + 8) == *(int *)(*(int *)(iVar1 + 0x10) + 8)) {
      if (*(int *)(iVar3 + 0x28) < 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0xd;
        goto locret_F000FCAC;
      }
      iVar2 = *(int *)(iVar4 + 0x10);
      iVar4 = iVar3;
      goto loc_F000FC28;
    }
  }
loc_F000FC90:
  *(undefined *)(dword_F0133DDC + 0x38) = 1;
locret_F000FCAC:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=206 start=0xf000fcb4 */

/* WARNING: Removing unreachable block (ram,0xf000fd20) */

undefined8 _getpriority(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar4 = 0x15;
  iVar2 = *piVar3;
  if (iVar2 == 1) {
    if (piVar3[1] == 0) {
      piVar3[1] = (int)*(sword *)(*_active_u + 0x2e);
    }
    bVar5 = true;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2e);
      iVar2 = _allproc;
      while( true ) {
        if ((int)sVar1 == piVar3[1]) {
          if (*(char *)(iVar2 + 0x15) < iVar4) {
            iVar4 = (int)*(char *)(iVar2 + 0x15);
          }
          iVar2 = *(int *)(iVar2 + 8);
        }
        else {
          iVar2 = *(int *)(iVar2 + 8);
        }
        if (iVar2 == 0) break;
        sVar1 = *(sword *)(iVar2 + 0x2e);
      }
      bVar5 = iVar4 == 0x15;
    }
  }
  else if (iVar2 < 2) {
    if (iVar2 != 0) {
loc_F000FE1C:
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F000FE50;
    }
    iVar2 = piVar3[1];
    if (iVar2 == 0) {
      iVar2 = *_active_u;
    }
    else {
      _pfind();
    }
    if (iVar2 == 0) {
      bVar5 = true;
    }
    else {
      iVar4 = (int)*(char *)(iVar2 + 0x15);
      bVar5 = iVar4 == 0x15;
    }
  }
  else {
    if (iVar2 != 2) goto loc_F000FE1C;
    if (piVar3[1] == 0) {
      piVar3[1] = (int)*(sword *)(_active_u[7] + 2);
    }
    bVar5 = true;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2c);
      iVar2 = _allproc;
      while( true ) {
        if ((int)sVar1 == piVar3[1]) {
          if (*(char *)(iVar2 + 0x15) < iVar4) {
            iVar4 = (int)*(char *)(iVar2 + 0x15);
          }
          iVar2 = *(int *)(iVar2 + 8);
        }
        else {
          iVar2 = *(int *)(iVar2 + 8);
        }
        if (iVar2 == 0) break;
        sVar1 = *(sword *)(iVar2 + 0x2c);
      }
      bVar5 = iVar4 == 0x15;
    }
  }
  if (bVar5) {
    *(undefined *)(dword_F0133DDC + 0x38) = 3;
  }
  else {
    *(int *)(dword_F0133DDC + 0x30) = iVar4;
  }
locret_F000FE50:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=207 start=0xf000fe58 */

/* WARNING: Removing unreachable block (ram,0xf000fec4) */
/* WARNING: Removing unreachable block (ram,0xf000ffac) */
/* WARNING: Removing unreachable block (ram,0xf000fee0) */
/* WARNING: Removing unreachable block (ram,0xf000ff40) */

undefined8 _setpriority(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  undefined uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar4;
  int iVar5;
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
  bool bVar6;
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
  piVar4 = *(int **)(dword_F0133DDC + 0x24);
  iVar5 = 0;
  iVar2 = *piVar4;
  if (iVar2 == 1) {
    if (piVar4[1] == 0) {
      piVar4[1] = (int)*(sword *)(*_active_u + 0x2e);
    }
    bVar6 = true;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2e);
      iVar2 = _allproc;
      while( true ) {
        if ((int)sVar1 == piVar4[1]) {
          iVar5 = iVar5 + 1;
          _donice(iVar2,piVar4[2]);
          iVar2 = *(int *)(iVar2 + 8);
        }
        else {
          iVar2 = *(int *)(iVar2 + 8);
        }
        if (iVar2 == 0) break;
        sVar1 = *(sword *)(iVar2 + 0x2e);
      }
      bVar6 = iVar5 == 0;
    }
loc_F000FFDC:
    if (!bVar6) goto locret_F000FFF0;
    uVar3 = 3;
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 == 0) {
        iVar2 = piVar4[1];
        if (iVar2 == 0) {
          iVar2 = *_active_u;
        }
        else {
          _pfind();
        }
        if (iVar2 == 0) {
          bVar6 = true;
        }
        else {
          _donice(iVar2,piVar4[2]);
          bVar6 = false;
        }
        goto loc_F000FFDC;
      }
    }
    else if (iVar2 == 2) {
      if (piVar4[1] == 0) {
        piVar4[1] = (int)*(sword *)(_active_u[7] + 2);
      }
      bVar6 = true;
      if (_allproc != 0) {
        sVar1 = *(sword *)(_allproc + 0x2c);
        iVar2 = _allproc;
        while( true ) {
          if ((int)sVar1 == piVar4[1]) {
            iVar5 = iVar5 + 1;
            _donice(iVar2,piVar4[2]);
            iVar2 = *(int *)(iVar2 + 8);
          }
          else {
            iVar2 = *(int *)(iVar2 + 8);
          }
          if (iVar2 == 0) break;
          sVar1 = *(sword *)(iVar2 + 0x2c);
        }
        bVar6 = iVar5 == 0;
      }
      goto loc_F000FFDC;
    }
    uVar3 = 0x16;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar3;
locret_F000FFF0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=208 start=0xf000fff8 */

/* WARNING: Removing unreachable block (ram,0xf001013c) */
/* WARNING: Removing unreachable block (ram,0xf00100e8) */
/* WARNING: Removing unreachable block (ram,0xf0010100) */
/* WARNING: Removing unreachable block (ram,0xf001014c) */
/* WARNING: Removing unreachable block (ram,0xf0010074) */

undefined8 _donice(int *param_1,int param_2)

{
  sword sVar1;
  sword sVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
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
  sVar1 = *(sword *)(*(int *)(_active_u + 0x1c) + 2);
  if ((((sVar1 == 0) || (sVar2 = *(sword *)(*(int *)(_active_u + 0x1c) + 6), sVar2 == 0)) ||
      (sVar1 == *(sword *)(param_1 + 0xb))) || (sVar2 == *(sword *)(param_1 + 0xb))) {
    if (0x14 < param_2) {
      param_2 = 0x14;
    }
    if (param_2 < -0x14) {
      param_2 = -0x14;
    }
    iVar3 = (int)*(char *)((int)param_1 + 0x15);
    if (param_2 < iVar3) {
      _suser();
      if (iVar3 == 0) {
        *(undefined *)(dword_F0133DDC + 0x38) = 0xd;
        goto locret_F0010174;
      }
      piVar6 = (int *)param_1[0x1a];
    }
    else {
      piVar6 = (int *)param_1[0x1a];
    }
    iVar3 = (uint)*(byte *)((int)param_1 + 0x15) << 0x18;
    iVar5 = piVar6[0x12];
    *(char *)((int)param_1 + 0x15) = (char)param_2;
    param_2 = (iVar5 + ((iVar3 >> 0x18) - (iVar3 >> 0x1f) >> 1)) - param_2 / 2;
    _task_priority(piVar6,param_2,0);
    do {
      do {
      } while (*piVar6 != 0);
      piVar4 = piVar6;
      _simple_lock_try();
    } while (piVar4 == (int *)0x0);
    param_1 = (int *)piVar6[7];
    if (piVar6 + 7 != param_1) {
      iVar3 = param_1[0x15];
      while( true ) {
        if (iVar3 < param_2) {
          _thread_max_priority(param_1,param_1[100],param_2);
        }
        piVar4 = param_1;
        _thread_priority(param_1,param_2,1);
        if (piVar4 != (int *)0x0) break;
        param_1 = (int *)param_1[4];
        if (piVar6 + 7 == param_1) goto loc_F0010170;
        iVar3 = param_1[0x15];
      }
      *(undefined *)(dword_F0133DDC + 0x38) = 1;
    }
loc_F0010170:
    *piVar6 = 0;
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 1;
  }
locret_F0010174:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=209 start=0xf001017c */

/* WARNING: Removing unreachable block (ram,0xf00102e0) */
/* WARNING: Removing unreachable block (ram,0xf00101f4) */
/* WARNING: Removing unreachable block (ram,0xf0010280) */
/* WARNING: Removing unreachable block (ram,0xf00101b4) */

undefined8 _setrlimit(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar7;
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
  puVar7 = *(uint **)(dword_F0133DDC + 0x24);
  if (*puVar7 < 6) {
    uVar1 = puVar7[1];
    piVar8 = _active_u + *puVar7 * 2 + 0x98;
    _copyin(uVar1,(undefined *)((int)register0x00000038 + -0x10),8);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0010310;
    iVar2 = *(int *)((int)register0x00000038 + -0xc);
    if ((piVar8[1] < *(int *)((int)register0x00000038 + -0x10)) || (piVar8[1] < iVar2)) {
      _suser();
      if (iVar2 == 0) goto locret_F0010310;
      uVar1 = *puVar7;
    }
    else {
      uVar1 = *puVar7;
    }
    if (uVar1 == 3) {
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
      if (*piVar8 < iVar2) {
        iVar6 = *piVar8;
        uVar1 = ~_page_mask;
        iVar3 = *(int *)(_active_threads + 0xc);
        *(uint *)((int)register0x00000038 + -0x14) = *(int *)(*_active_u + 0x84) - iVar2 & uVar1;
        iVar4 = *(int *)(iVar3 + 0xc);
        _vm_allocate(iVar4,(undefined *)((int)register0x00000038 + -0x14),
                     (iVar2 + _page_mask & uVar1) - (iVar6 + _page_mask & uVar1),0);
      }
      else {
        iVar3 = *piVar8;
        uVar1 = ~_page_mask;
        uVar5 = *(int *)(*_active_u + 0x84) - *piVar8 & uVar1;
        iVar4 = *(int *)(*(int *)(_active_threads + 0xc) + 0xc);
        *(uint *)((int)register0x00000038 + -0x14) = uVar5;
        _vm_deallocate(iVar4,uVar5,(iVar3 + _page_mask & uVar1) - (iVar2 + _page_mask & uVar1));
      }
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
      if (iVar4 != 0) goto loc_F00102F8;
    }
    else {
      iVar2 = *(int *)((int)register0x00000038 + -0x10);
    }
    *piVar8 = iVar2;
    piVar8[1] = *(int *)((int)register0x00000038 + -0xc);
  }
  else {
loc_F00102F8:
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
locret_F0010310:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=210 start=0xf0010318 */

/* WARNING: Removing unreachable block (ram,0xf0010354) */

undefined8 _getrlimit(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined uVar3;
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
  uVar1 = **(uint **)(dword_F0133DDC + 0x24);
  if (uVar1 < 6) {
    iVar2 = _active_u + uVar1 * 8 + 0x260;
    _copyout(iVar2,(*(uint **)(dword_F0133DDC + 0x24))[1],8);
    uVar3 = (undefined)iVar2;
  }
  else {
    uVar3 = 0x16;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = uVar3;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=211 start=0xf001036c */

/* WARNING: Removing unreachable block (ram,0xf00103f8) */
/* WARNING: Removing unreachable block (ram,0xf00103a4) */

undefined8 _getrusage(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar2;
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
  piVar2 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = *piVar2;
  if (iVar1 == -1) {
    iVar1 = _active_u + 0x1b4;
  }
  else {
    if (iVar1 != 0) {
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      goto locret_F001040C;
    }
    _thread_read_times(_active_threads,(undefined *)((int)register0x00000038 + -0x18),
                       (undefined *)((int)register0x00000038 + -0x10));
    iVar1 = _active_u;
    *(undefined4 *)(_active_u + 0x16c) = *(undefined4 *)((int)register0x00000038 + -0x18);
    *(undefined4 *)(iVar1 + 0x170) = *(undefined4 *)((int)register0x00000038 + -0x14);
    iVar1 = _active_u;
    *(undefined4 *)(_active_u + 0x174) = *(undefined4 *)((int)register0x00000038 + -0x10);
    *(undefined4 *)(iVar1 + 0x178) = *(undefined4 *)((int)register0x00000038 + -0xc);
    iVar1 = _active_u + 0x16c;
  }
  _copyout(iVar1,piVar2[1],0x48);
  *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
locret_F001040C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=212 start=0xf0010414 */

/* WARNING: Removing unreachable block (ram,0xf0010428) */
/* WARNING: Removing unreachable block (ram,0xf001041c) */

undefined8 _ruadd(int param_1,int param_2)

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
  int *piVar2;
  undefined4 unaff_i1;
  int *piVar3;
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
  _timevaladd(param_1,param_2);
  _timevaladd(param_1 + 8,param_2 + 8);
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    *(int *)(param_1 + 0x10) = *(int *)(param_2 + 0x10);
  }
  piVar2 = (int *)(param_1 + 0x14);
  iVar1 = 0xc;
  piVar3 = (int *)(param_2 + 0x14);
  do {
    iVar1 = iVar1 + -1;
    *piVar2 = *piVar2 + *piVar3;
    piVar3 = piVar3 + 1;
    piVar2 = piVar2 + 1;
  } while (0 < iVar1);
  return CONCAT44(piVar3,piVar2);
}
/* GHIDRADEC_FUNCTION index=213 start=0xf0010484 */

/* WARNING: Removing unreachable block (ram,0xf00105b4) */
/* WARNING: Removing unreachable block (ram,0xf0010564) */
/* WARNING: Removing unreachable block (ram,0xf00104ec) */
/* WARNING: Removing unreachable block (ram,0xf00104dc) */
/* WARNING: Removing unreachable block (ram,0xf00104e4) */
/* WARNING: Removing unreachable block (ram,0xf00104f4) */
/* WARNING: Removing unreachable block (ram,0xf0010594) */
/* WARNING: Removing unreachable block (ram,0xf00105c4) */
/* WARNING: Removing unreachable block (ram,0xf0010490) */

undefined8 _boot(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  uint *puVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  int iVar5;
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
  _md_prepare_for_shutdown(param_1,param_2,param_3);
  if ((((param_2 & 4) == 0) && (_waittime < 0)) && (dword_F0133DE4 != 0)) {
    _waittime = 0;
    if (_acctp != 0) {
      _acctp = 0;
      _vn_rele();
    }
    _sync();
    iVar4 = 0;
    _unmount_all();
    _if_down_all();
    iVar5 = 0;
    do {
      puVar2 = _buf + _nbuf * 0x11 + -0x11;
      iVar3 = 0;
      if (_buf <= puVar2) {
        uVar1 = *puVar2;
        while( true ) {
          if ((uVar1 & 10) == 8) {
            iVar3 = iVar3 + 1;
          }
          puVar2 = puVar2 + -0x11;
          if (puVar2 < _buf) break;
          uVar1 = *puVar2;
        }
      }
      if (iVar3 == 0) break;
      _printf(&DAT_f010b1d8,iVar3);
      if (iVar3 != iVar5) {
        iVar4 = 0;
      }
      _us_spin(iVar4 * 40000);
      iVar4 = iVar4 + 1;
      iVar5 = iVar3;
    } while (iVar4 < 0x14);
  }
  _md_shutdown_devices(param_1,param_2,param_3);
  _md_do_shutdown(param_1,param_2,param_3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=214 start=0xf00105d4 */

/* WARNING: Removing unreachable block (ram,0xf0010680) */
/* WARNING: Removing unreachable block (ram,0xf001065c) */
/* WARNING: Removing unreachable block (ram,0xf0010638) */
/* WARNING: Removing unreachable block (ram,0xf0010600) */
/* WARNING: Removing unreachable block (ram,0xf00105f0) */
/* WARNING: Removing unreachable block (ram,0xf00105e0) */
/* WARNING: Removing unreachable block (ram,0xf00105e8) */
/* WARNING: Removing unreachable block (ram,0xf00105f8) */
/* WARNING: Removing unreachable block (ram,0xf0010608) */
/* WARNING: Removing unreachable block (ram,0xf0010644) */
/* WARNING: Removing unreachable block (ram,0xf0010674) */
/* WARNING: Removing unreachable block (ram,0xf0010694) */
/* WARNING: Removing unreachable block (ram,0xf00105d8) */

undefined8 _unmount_all(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined8 *puVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar3;
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
  _proc_shutdown();
  _kill_tasks();
  _mfs_cache_clear();
  _vm_object_cache_clear();
  _fd_shutdown();
  _vm_object_shutdown();
  _vnode_pager_shutdown();
  piVar1 = (int *)*_rootvfs;
  while (piVar1 != (int *)0x0) {
    _printf(aUnmountingS,piVar1 + 8);
    iVar3 = *piVar1;
    _dounmount();
    puVar2 = &aFailed_0;
    if (piVar1 == (int *)0x0) {
      puVar2 = (undefined8 *)&aDone;
    }
    _printf(puVar2);
    piVar1 = (int *)iVar3;
  }
  _vn_rele(_rootdir);
  piVar1 = _rootvfs;
  _dounmount();
  if (piVar1 != (int *)0x0) {
    _printf(aRootUnmountFai);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=215 start=0xf00106a4 */

/* WARNING: Removing unreachable block (ram,0xf00107fc) */
/* WARNING: Removing unreachable block (ram,0xf00107bc) */
/* WARNING: Removing unreachable block (ram,0xf0010748) */
/* WARNING: Removing unreachable block (ram,0xf00106dc) */
/* WARNING: Removing unreachable block (ram,0xf00106b8) */
/* WARNING: Removing unreachable block (ram,0xf001072c) */
/* WARNING: Removing unreachable block (ram,0xf0010790) */
/* WARNING: Removing unreachable block (ram,0xf00107e4) */
/* WARNING: Removing unreachable block (ram,0xf0010814) */
/* WARNING: Removing unreachable block (ram,0xf00106a8) */

undefined8 _kill_tasks(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined *puVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 *puVar6;
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
  iVar2 = 0;
  _pmap_create();
  _vm_map_create();
  do {
    do {
    } while (_all_psets_lock != 0);
    puVar3 = &_all_psets_lock;
    _simple_lock_try();
  } while (puVar3 == (undefined4 *)0x0);
  puVar3 = _all_psets;
  if ((undefined4 **)_all_psets != &_all_psets) {
    do {
      puVar6 = (undefined4 *)DAT_f013510c._0_4_;
      if (puVar3 != (undefined4 *)_default_pset) {
        _all_psets_lock = 0;
        _processor_set_destroy(puVar3);
        do {
          do {
          } while (_all_psets_lock != 0);
          puVar3 = &_all_psets_lock;
          _simple_lock_try();
          puVar6 = _all_psets;
        } while (puVar3 == (undefined4 *)0x0);
      }
      puVar3 = puVar6;
    } while ((undefined4 **)puVar6 != &_all_psets);
  }
  _all_psets_lock = 0;
  do {
    do {
    } while (unk_F0135118._0_4_ != 0);
    puVar4 = unk_F0135118;
    _simple_lock_try();
  } while (puVar4 == (undefined *)0x0);
  while (iVar1 = DAT_f01350ec._0_4_, DAT_f01350f4 != 0) {
    DAT_f01350ec._0_4_ = iVar1;
    _pset_remove_task(_default_pset,iVar1);
    iVar5 = *(int *)(iVar1 + 0xc);
    if ((iVar5 != _kernel_map) && (iVar5 != iVar2)) {
      *(int *)(iVar1 + 0xc) = iVar2;
      _vm_map_reference(iVar2);
      unk_F0135118._0_4_ = 0;
      _vm_map_remove(iVar5,*(undefined4 *)(iVar5 + 0x14),*(undefined4 *)(iVar5 + 0x18));
      do {
        do {
        } while (unk_F0135118._0_4_ != 0);
        puVar4 = unk_F0135118;
        _simple_lock_try();
      } while (puVar4 == (undefined *)0x0);
    }
  }
  DAT_f01350ec._0_4_ = iVar1;
  unk_F0135118._0_4_ = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=216 start=0xf0010844 */

/* WARNING: Removing unreachable block (ram,0xf0010b40) */
/* WARNING: Removing unreachable block (ram,0xf0010af4) */
/* WARNING: Removing unreachable block (ram,0xf0010aa0) */
/* WARNING: Removing unreachable block (ram,0xf0010a34) */
/* WARNING: Removing unreachable block (ram,0xf0010a18) */
/* WARNING: Removing unreachable block (ram,0xf0010990) */
/* WARNING: Removing unreachable block (ram,0xf0010920) */
/* WARNING: Removing unreachable block (ram,0xf00108f0) */
/* WARNING: Removing unreachable block (ram,0xf0010898) */
/* WARNING: Removing unreachable block (ram,0xf0010874) */
/* WARNING: Removing unreachable block (ram,0xf001087c) */
/* WARNING: Removing unreachable block (ram,0xf00108a4) */
/* WARNING: Removing unreachable block (ram,0xf0010910) */
/* WARNING: Removing unreachable block (ram,0xf001096c) */
/* WARNING: Removing unreachable block (ram,0xf0010a0c) */
/* WARNING: Removing unreachable block (ram,0xf00109f8) */
/* WARNING: Removing unreachable block (ram,0xf0010a90) */
/* WARNING: Removing unreachable block (ram,0xf0010ad8) */
/* WARNING: Removing unreachable block (ram,0xf0010b30) */
/* WARNING: Removing unreachable block (ram,0xf0010b4c) */
/* WARNING: Removing unreachable block (ram,0xf0010858) */

undefined8 _proc_shutdown(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int iVar5;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int iVar6;
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
  iVar5 = *(int *)(*(int *)(_active_threads + 0xc) + 0x3c);
  iVar3 = 1;
  _pfind();
  if ((iVar3 != 0) && (iVar3 != iVar5)) {
    _task_suspend(*(undefined4 *)(iVar3 + 0x68));
  }
  iVar3 = 2;
  _pfind();
  if ((iVar3 != 0) && (iVar3 != iVar5)) {
    _task_suspend(*(undefined4 *)(iVar3 + 0x68));
  }
  _printf(aKillingAllProc);
  if (_allproc != 0) {
    sVar1 = *(sword *)(_allproc + 0x32);
    iVar3 = _allproc;
    while( true ) {
      if (sVar1 == 0) {
        iVar3 = *(int *)(iVar3 + 8);
      }
      else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
        if (iVar3 == iVar5) {
          iVar3 = *(int *)(iVar3 + 8);
        }
        else {
          _psignal(iVar3,0xf);
          iVar3 = *(int *)(iVar3 + 8);
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
      if (iVar3 == 0) break;
      sVar1 = *(sword *)(iVar3 + 0x32);
    }
  }
  _ns_sleep(0,2000000000);
  _ns_sleep(0,2000000000);
  if (_allproc != 0) {
    sVar1 = *(sword *)(_allproc + 0x32);
    iVar3 = _allproc;
    while( true ) {
      if (sVar1 == 0) {
        iVar3 = *(int *)(iVar3 + 8);
      }
      else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
        if (iVar3 == iVar5) {
          iVar3 = *(int *)(iVar3 + 8);
        }
        else {
          _psignal(iVar3,9);
          iVar3 = *(int *)(iVar3 + 8);
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
      if (iVar3 == 0) break;
      sVar1 = *(sword *)(iVar3 + 0x32);
    }
  }
  _ns_sleep(0,1000000000);
  if (_allproc != 0) {
    sVar1 = *(sword *)(_allproc + 0x32);
    iVar3 = _allproc;
    while( true ) {
      if (sVar1 == 0) {
        iVar3 = *(int *)(iVar3 + 8);
      }
      else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
        if (iVar3 == iVar5) {
          iVar3 = *(int *)(iVar3 + 8);
        }
        else if (*(int *)(iVar3 + 0x78) == 0) {
          *(int *)(iVar3 + 0x78) = _active_threads;
          _printf(&DAT_f010b238);
          _do_exit(iVar3,1);
          iVar3 = _allproc;
        }
        else {
          _thread_block();
          iVar3 = _allproc;
        }
      }
      else {
        iVar3 = *(int *)(iVar3 + 8);
      }
      if (iVar3 == 0) break;
      sVar1 = *(sword *)(iVar3 + 0x32);
    }
  }
  _printf(&DAT_f010b240);
  if (_allproc != 0) {
    iVar5 = *(int *)(_allproc + 0x68);
    iVar3 = _allproc;
    do {
      iVar6 = *(int *)(iVar5 + 0x38);
      bVar2 = false;
      iVar5 = 0;
      if (*(uint *)(iVar6 + 0x154) < 0x80000000) {
        iVar4 = *(int *)(iVar6 + 0x14c);
        do {
          iVar4 = *(int *)(iVar4 + iVar5 * 4);
          if (iVar4 == 0) {
loc_F0010AAC:
            iVar4 = *(int *)(iVar6 + 0x150);
          }
          else {
            if (iVar4 != -0x10000) {
              _vno_lockrelease(iVar4);
              *(undefined4 *)(*(int *)(iVar6 + 0x14c) + iVar5 * 4) = 0;
              _closef(iVar4);
              bVar2 = true;
              goto loc_F0010AAC;
            }
            iVar4 = *(int *)(iVar6 + 0x150);
          }
          *(undefined *)(iVar4 + iVar5) = 0;
          iVar5 = iVar5 + 1;
          if (*(int *)(iVar6 + 0x154) < iVar5) break;
          iVar4 = *(int *)(iVar6 + 0x14c);
        } while( true );
      }
      if (*(int *)(iVar6 + 0x15c) == 0) {
        iVar5 = *(int *)(iVar6 + 0x160);
      }
      else {
        *(undefined4 *)(iVar6 + 0x15c) = 0;
        _vn_rele();
        bVar2 = true;
        iVar5 = *(int *)(iVar6 + 0x160);
      }
      if (iVar5 != 0) {
        *(undefined4 *)(iVar6 + 0x160) = 0;
        _vn_rele();
        bVar2 = true;
      }
      iVar6 = _allproc;
      if (!bVar2) {
        iVar6 = *(int *)(iVar3 + 8);
      }
      if (iVar6 == 0) break;
      iVar5 = *(int *)(iVar6 + 0x68);
      iVar3 = iVar6;
    } while( true );
  }
  _thread_wakeup_prim(&_reaper_queue,0,0);
  _ns_sleep(0,2000000000);
  _printf(aContinuing);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=217 start=0xf0010b5c */

/* WARNING: Removing unreachable block (ram,0xf0010b88) */

undefined8 _fd_shutdown(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  undefined4 unaff_l0;
  undefined4 *puVar2;
  undefined4 unaff_l1;
  undefined4 *puVar3;
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
  if ((undefined4 **)_file_list != &_file_list) {
    sVar1 = *(sword *)((int)_file_list + 0xe);
    puVar2 = _file_list;
    while( true ) {
      puVar3 = (undefined4 *)*puVar2;
      while (0 < sVar1) {
        _closef(puVar2);
        sVar1 = *(sword *)((int)puVar2 + 0xe);
      }
      if ((undefined4 **)puVar3 == &_file_list) break;
      sVar1 = *(sword *)((int)puVar3 + 0xe);
      puVar2 = puVar3;
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=218 start=0xf0010bb8 */

/* WARNING: Removing unreachable block (ram,0xf0010c9c) */
/* WARNING: Removing unreachable block (ram,0xf0010d08) */
/* WARNING: Removing unreachable block (ram,0xf0010c68) */

undefined8 _sigvec(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int iVar5;
  int *piVar6;
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
  piVar4 = *(int **)(dword_F0133DDC + 0x24);
  iVar5 = *piVar4;
  if (((iVar5 - 1U < 0x1f) && (iVar5 != 9)) && (iVar5 != 0x11)) {
    piVar6 = (int *)((int)register0x00000038 + -0x18);
    if (piVar4[2] != 0) {
      *(int *)((int)register0x00000038 + -0x18) = _active_u[iVar5 + 0xc];
      *(int *)((int)register0x00000038 + -0x14) = _active_u[iVar5 + 0x2d];
      *(undefined4 *)((int)register0x00000038 + -0x10) = 0;
      uVar3 = 1 << ((byte)(iVar5 - 1U) & 0x1f);
      if ((_active_u[0x4e] & uVar3) != 0) {
        *(undefined4 *)((int)register0x00000038 + -0x10) = 1;
      }
      if ((_active_u[0x4f] & uVar3) != 0) {
        *(uint *)((int)register0x00000038 + -0x10) = *(uint *)((int)register0x00000038 + -0x10) | 2;
      }
      piVar1 = piVar6;
      _copyout(piVar6,piVar4[2],0xc);
      *(char *)(dword_F0133DDC + 0x38) = (char)piVar1;
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0010D10;
    }
    iVar2 = piVar4[1];
    if (iVar2 != 0) {
      _copyin(iVar2,piVar6,0xc);
      *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        if (((iVar5 == 0x13) && (*piVar6 == 1)) && ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0)) {
          *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        }
        else {
          _setsigvec(iVar5,piVar6);
        }
      }
    }
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
locret_F0010D10:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=219 start=0xf0010d18 */

/* WARNING: Removing unreachable block (ram,0xf0010e7c) */
/* WARNING: Removing unreachable block (ram,0xf0010d4c) */
/* WARNING: Removing unreachable block (ram,0xf0010f44) */
/* WARNING: Removing unreachable block (ram,0xf0010d30) */

undefined8 _setsigvec(int *param_1,int *param_2)

{
  uint uVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  uint uVar6;
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
  iVar5 = *_active_u;
  uVar6 = 1 << ((char)param_1 - 1U & 0x1f);
  _splusclock();
  do {
    do {
    } while (*(int *)(iVar5 + 0x70) != 0);
    piVar2 = (int *)(iVar5 + 0x70);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  _active_u[(int)(param_1 + 3)] = *param_2;
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
    uVar1 = 0xfffafeff;
  }
  else {
    uVar1 = 0xfffefeff;
  }
  _active_u[(int)param_1 + 0x2d] = param_2[1] & uVar1;
  if ((param_2[2] & 2U) == 0) {
    uVar1 = _active_u[0x4f] & ~uVar6;
  }
  else {
    uVar1 = _active_u[0x4f] | uVar6;
  }
  _active_u[0x4f] = uVar1;
  if ((param_2[2] & 1U) == 0) {
    uVar1 = _active_u[0x4e] & ~uVar6;
  }
  else {
    uVar1 = _active_u[0x4e] | uVar6;
  }
  _active_u[0x4e] = uVar1;
  if (*param_2 == 1) {
loc_F0010E44:
    *(uint *)(iVar5 + 0x18) = *(uint *)(iVar5 + 0x18) & ~uVar6;
    if ((uVar6 & 0x1ef8) != 0) {
      piVar2 = *(int **)(iVar5 + 0x68);
      param_1 = piVar2 + 7;
      do {
        do {
        } while (*piVar2 != 0);
        piVar3 = piVar2;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      piVar2 = (int *)*param_1;
      if (param_1 != piVar2) {
        iVar4 = piVar2[0x21];
        while( true ) {
          *(uint *)(iVar4 + 0x4c) = *(uint *)(iVar4 + 0x4c) & ~uVar6;
          piVar2 = (int *)piVar2[4];
          if (param_1 == piVar2) break;
          iVar4 = piVar2[0x21];
        }
      }
      **(undefined4 **)(iVar5 + 0x68) = 0;
    }
    *(uint *)(iVar5 + 0x20) = *(uint *)(iVar5 + 0x20) | uVar6;
    *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) & ~uVar6;
  }
  else {
    if ((*(uint *)(iVar5 + 0x14) & 0x4000) == 0) {
      uVar1 = *(uint *)(iVar5 + 0x20);
    }
    else if (*param_2 == 0) {
      if (param_1 == (int *)0x14) goto loc_F0010E44;
      uVar1 = *(uint *)(iVar5 + 0x20);
    }
    else {
      uVar1 = *(uint *)(iVar5 + 0x20);
    }
    *(uint *)(iVar5 + 0x20) = uVar1 & ~uVar6;
    if (*param_2 == 0) {
      if ((*(uint *)(iVar5 + 0x14) & 0x4000) == 0) {
        uVar1 = *(uint *)(iVar5 + 0x24);
      }
      else {
        _active_u[(int)(param_1 + 3)] = 0;
        uVar1 = *(uint *)(iVar5 + 0x24);
      }
      uVar6 = uVar1 & ~uVar6;
    }
    else {
      uVar6 = *(uint *)(iVar5 + 0x24) | uVar6;
    }
    *(uint *)(iVar5 + 0x24) = uVar6;
  }
  *(undefined4 *)(iVar5 + 0x70) = 0;
  _spl0();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=220 start=0xf0010f54 */

/* WARNING: Removing unreachable block (ram,0xf0010fbc) */
/* WARNING: Removing unreachable block (ram,0xf0010f6c) */

undefined8 _sigblock(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar2;
  undefined4 unaff_l3;
  int iVar3;
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
  puVar2 = *(uint **)(dword_F0133DDC + 0x24);
  iVar3 = *_active_u;
  _splusclock();
  *(undefined4 *)(dword_F0133DDC + 0x30) = *(undefined4 *)(iVar3 + 0x1c);
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
    uVar1 = 0xfffafeff;
  }
  else {
    uVar1 = 0xfffefeff;
  }
  *(uint *)(iVar3 + 0x1c) = *(uint *)(iVar3 + 0x1c) | *puVar2 & uVar1;
  _spl0();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=221 start=0xf0010fcc */

/* WARNING: Removing unreachable block (ram,0xf001102c) */
/* WARNING: Removing unreachable block (ram,0xf0010fe4) */

undefined8 _sigsetmask(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint *puVar2;
  undefined4 unaff_l3;
  int iVar3;
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
  puVar2 = *(uint **)(dword_F0133DDC + 0x24);
  iVar3 = *_active_u;
  _splusclock();
  *(undefined4 *)(dword_F0133DDC + 0x30) = *(undefined4 *)(iVar3 + 0x1c);
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
    uVar1 = 0xfffafeff;
  }
  else {
    uVar1 = 0xfffefeff;
  }
  *(uint *)(iVar3 + 0x1c) = *puVar2 & uVar1;
  _spl0();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=222 start=0xf001103c */

/* WARNING: Removing unreachable block (ram,0xf0011040) */

undefined8 _sigcont(undefined4 param_1,undefined4 param_2)

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
  _unix_syscall_return(4);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=223 start=0xf0011050 */

/* WARNING: Removing unreachable block (ram,0xf00110c8) */

undefined8 _sigpause(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  uint *puVar2;
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
  iVar3 = *_active_u;
  puVar2 = *(uint **)(dword_F0133DDC + 0x24);
  _active_u[0x50] = *(int *)(iVar3 + 0x1c);
  *(uint *)(iVar3 + 0x28) = *(uint *)(iVar3 + 0x28) | 0x200;
  if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
    uVar1 = 0xfffafeff;
  }
  else {
    uVar1 = 0xfffefeff;
  }
  *(uint *)(iVar3 + 0x1c) = *puVar2 & uVar1;
  _sleep_with_continuation(&_active_u,0x28,_sigcont);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=224 start=0xf00110d8 */

/* WARNING: Removing unreachable block (ram,0xf0011134) */
/* WARNING: Removing unreachable block (ram,0xf0011100) */

undefined8 _sigstack(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int *piVar3;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar2 = piVar3[1];
  if (iVar2 != 0) {
    iVar1 = _active_u + 0x144;
    _copyout(iVar1,iVar2,8);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto locret_F0011168;
  }
  iVar2 = *piVar3;
  if (iVar2 != 0) {
    _copyin(iVar2,(undefined *)((int)register0x00000038 + -0x10),8);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar2;
    iVar2 = _active_u;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      *(undefined4 *)(_active_u + 0x144) = *(undefined4 *)((int)register0x00000038 + -0x10);
      *(undefined4 *)(iVar2 + 0x148) = *(undefined4 *)((int)register0x00000038 + -0xc);
    }
  }
locret_F0011168:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=225 start=0xf0011170 */

/* WARNING: Removing unreachable block (ram,0xf0011268) */
/* WARNING: Removing unreachable block (ram,0xf00111ec) */
/* WARNING: Removing unreachable block (ram,0xf00111ac) */
/* WARNING: Removing unreachable block (ram,0xf001131c) */
/* WARNING: Removing unreachable block (ram,0xf0011334) */
/* WARNING: Removing unreachable block (ram,0xf00111e4) */
/* WARNING: Removing unreachable block (ram,0xf0011254) */
/* WARNING: Removing unreachable block (ram,0xf00112dc) */
/* WARNING: Removing unreachable block (ram,0xf0011308) */

undefined8 _kill(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  int iVar2;
  int iVar3;
  undefined uVar4;
  uint uVar5;
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
  piVar7 = *(int **)(dword_F0133DDC + 0x24);
  uVar5 = piVar7[1];
  if (0x20 < uVar5) {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
    goto locret_F0011348;
  }
  iVar2 = *piVar7;
  if (iVar2 < 1) {
    if (iVar2 == -1) {
      _killpg1(uVar5,0,1);
      uVar4 = (undefined)uVar5;
    }
    else if (iVar2 == 0) {
      _killpg1(uVar5,0,0);
      uVar4 = (undefined)uVar5;
    }
    else {
      iVar2 = piVar7[1];
      _killpg1(iVar2,-*piVar7,0);
      uVar4 = (undefined)iVar2;
    }
  }
  else {
    _pfind();
    if (iVar2 != 0) {
      if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
        if (*(sword *)(_active_u[7] + 2) != 0) {
          if (*(sword *)(_active_u[7] + 2) != *(sword *)(iVar2 + 0x2c)) {
            uVar4 = 1;
            goto loc_F0011344;
          }
          goto loc_F00112CC;
        }
        iVar6 = piVar7[1];
      }
      else {
        iVar3 = (int)*(sword *)(iVar2 + 0x30);
        _get_posix_proc();
        iVar6 = iVar3;
        _suser();
        if (iVar6 == 0) {
          sVar1 = *(sword *)(_active_u[7] + 2);
          if ((((sVar1 != *(sword *)(iVar3 + 4)) && (sVar1 != *(sword *)(iVar3 + 6))) &&
              (sVar1 = *(sword *)(_active_u[7] + 6), sVar1 != *(sword *)(iVar3 + 4))) &&
             (sVar1 != *(sword *)(iVar3 + 6))) {
            if (piVar7[1] == 0x13) {
              iVar6 = (int)*(sword *)(iVar2 + 0x30);
              _get_posix_proc();
              iVar3 = *(int *)(iVar6 + 0x10);
              iVar6 = (int)*(sword *)(*_active_u + 0x30);
              _get_posix_proc();
              if (*(int *)(iVar3 + 8) == *(int *)(*(int *)(iVar6 + 0x10) + 8)) goto loc_F001128C;
            }
            uVar4 = 1;
            goto loc_F0011344;
          }
        }
loc_F001128C:
        *(undefined *)(dword_F0133DDC + 0x38) = 0;
loc_F00112CC:
        iVar6 = piVar7[1];
      }
      if (iVar6 != 0) {
        _psignal(iVar2);
      }
      goto locret_F0011348;
    }
    uVar4 = 3;
  }
loc_F0011344:
  *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
locret_F0011348:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=226 start=0xf0011350 */

/* WARNING: Removing unreachable block (ram,0xf001137c) */

undefined8 _killpg(undefined4 param_1,undefined4 param_2)

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
  uVar1 = (*(undefined4 **)(dword_F0133DDC + 0x24))[1];
  if (uVar1 < 0x21) {
    _killpg1(uVar1,**(undefined4 **)(dword_F0133DDC + 0x24),0);
    *(char *)(dword_F0133DDC + 0x38) = (char)uVar1;
  }
  else {
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=227 start=0xf0011394 */

/* WARNING: Removing unreachable block (ram,0xf00114a8) */
/* WARNING: Removing unreachable block (ram,0xf0011470) */

undefined8 _killpg1(int param_1,int param_2,int param_3)

{
  sword sVar1;
  int iVar2;
  undefined4 unaff_l0;
  int iVar3;
  undefined4 unaff_l1;
  int iVar4;
  uint uVar5;
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
  uVar5 = 0;
  if (((param_3 == 0) && (param_2 == 0)) &&
     (param_2 = (int)*(sword *)(*_active_u + 0x2e), param_2 == 0)) {
    uVar5 = 3;
  }
  else {
    iVar4 = 0;
    if (_allproc != 0) {
      sVar1 = *(sword *)(_allproc + 0x2e);
      iVar3 = _allproc;
      do {
        if ((sVar1 == param_2) || (param_3 != 0)) {
          if (*(sword *)(iVar3 + 0x32) == 0) {
            iVar3 = *(int *)(iVar3 + 8);
          }
          else if ((*(uint *)(iVar3 + 0x28) & 2) == 0) {
            if ((param_3 == 0) || (iVar3 != *_active_u)) {
              if (((*(sword *)(_active_u[7] + 2) == 0) ||
                  (*(sword *)(_active_u[7] + 2) == *(sword *)(iVar3 + 0x2c))) ||
                 ((param_1 == 0x13 && (iVar2 = iVar3, _inferior(), iVar2 != 0)))) {
                iVar4 = iVar4 + 1;
                if (param_1 != 0) {
                  _psignal(iVar3,param_1);
                }
              }
              else {
                if (param_3 != 0) {
                  iVar3 = *(int *)(iVar3 + 8);
                  goto loc_F00114B4;
                }
                uVar5 = 1;
              }
              iVar3 = *(int *)(iVar3 + 8);
            }
            else {
              iVar3 = *(int *)(iVar3 + 8);
            }
          }
          else {
            iVar3 = *(int *)(iVar3 + 8);
          }
        }
        else {
          iVar3 = *(int *)(iVar3 + 8);
        }
loc_F00114B4:
        if (iVar3 == 0) break;
        sVar1 = *(sword *)(iVar3 + 0x2e);
      } while( true );
    }
    if (uVar5 == 0) {
      uVar5 = (iVar4 != 0) - 1 & 3;
    }
  }
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=228 start=0xf00114dc */

/* WARNING: Removing unreachable block (ram,0xf0011500) */
/* WARNING: Removing unreachable block (ram,0xf00114ec) */

undefined8 _gsignal(int param_1,undefined4 param_2)

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
  if ((param_1 != 0) && (iVar1 = param_1, _pgfind(), iVar1 != 0)) {
    _pgsignal();
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=229 start=0xf0011510 */

/* WARNING: Removing unreachable block (ram,0xf0011554) */
/* WARNING: Removing unreachable block (ram,0xf001154c) */

sqword _pgsignal(int param_1,uint param_2,int param_3)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar1;
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
    for (iVar1 = *(int *)(param_1 + 4); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0xc)) {
      if ((param_3 == 0) || ((*(uint *)(iVar1 + 0x28) & 0x40000000) != 0)) {
        _psignal(iVar1,param_2);
      }
      iVar1 = (int)*(sword *)(iVar1 + 0x30);
      _get_posix_proc();
    }
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=230 start=0xf0011574 */

/* WARNING: Removing unreachable block (ram,0xf001198c) */
/* WARNING: Removing unreachable block (ram,0xf001195c) */
/* WARNING: Removing unreachable block (ram,0xf0011940) */
/* WARNING: Removing unreachable block (ram,0xf001191c) */
/* WARNING: Removing unreachable block (ram,0xf00118a8) */
/* WARNING: Removing unreachable block (ram,0xf001185c) */
/* WARNING: Removing unreachable block (ram,0xf00117b0) */
/* WARNING: Removing unreachable block (ram,0xf0011764) */
/* WARNING: Removing unreachable block (ram,0xf0011728) */
/* WARNING: Removing unreachable block (ram,0xf0011700) */
/* WARNING: Removing unreachable block (ram,0xf0011734) */
/* WARNING: Removing unreachable block (ram,0xf0011774) */
/* WARNING: Removing unreachable block (ram,0xf0011968) */
/* WARNING: Removing unreachable block (ram,0xf00118a0) */
/* WARNING: Removing unreachable block (ram,0xf00118fc) */
/* WARNING: Removing unreachable block (ram,0xf0011938) */
/* WARNING: Removing unreachable block (ram,0xf0011954) */
/* WARNING: Removing unreachable block (ram,0xf0011984) */
/* WARNING: Removing unreachable block (ram,0xf00119a0) */
/* WARNING: Removing unreachable block (ram,0xf00116c4) */

undefined8 _psignal(int param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  uint uVar7;
  undefined4 unaff_l3;
  uint uVar8;
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
  if (0x20 < param_2) goto locret_F00119A8;
  iVar6 = *(int *)(param_1 + 0x68);
  uVar7 = 1 << ((char)param_2 - 1U & 0x1f);
  if ((iVar6 == 0) || (*(int *)(iVar6 + 0x50) != 0)) goto locret_F00119A8;
  uVar2 = *(uint *)(param_1 + 0x28);
  uVar8 = 0;
  if ((uVar2 & 0x10) == 0) {
    uVar2 = *(uint *)(param_1 + 0x14);
    if (((uVar2 & 0x4000) == 0) || (uVar7 != 0x40000)) {
      if ((*(uint *)(param_1 + 0x20) & uVar7) != 0) goto locret_F00119A8;
      uVar2 = *(uint *)(param_1 + 0x14);
    }
    if (((uVar2 & 0x4000) == 0) || (uVar7 != 0x40000)) {
      uVar2 = *(uint *)(param_1 + 0x1c);
      uVar8 = 3;
      if ((uVar2 & uVar7) != 0) goto loc_F0011628;
      uVar2 = *(uint *)(param_1 + 0x24);
    }
    else {
      uVar2 = *(uint *)(param_1 + 0x24);
    }
    uVar2 = -(uint)((uVar2 & uVar7) != 0);
    uVar8 = uVar2 & 2;
  }
loc_F0011628:
  if (param_2 != 0) {
    uVar2 = *(uint *)(param_1 + 0x18) | uVar7;
    *(uint *)(param_1 + 0x18) = uVar2;
    if (7 < param_2 - 0xf) goto def_F0011658;
    uVar2 = *(uint *)((param_2 - 0xf) * 4 + -0xffee9a0);
    switch(param_2) {
    case :
      uVar2 = *(uint *)(param_1 + 0x28);
      if (((uVar2 & 0x10) == 0) && (uVar8 == 0)) goto loc_F001169C;
      goto loc_F00116BC;
    case :
    case :
      goto def_F0011658;
    :
      uVar2 = *(uint *)(param_1 + 0x18);
      uVar4 = 0x40000;
      break;
    case :
loc_F001169C:
      uVar2 = *(uint *)(param_1 + 0x18);
      uVar4 = 0x330000;
    }
    uVar2 = uVar2 & ~uVar4;
    *(uint *)(param_1 + 0x18) = uVar2;
  }
def_F0011658:
loc_F00116BC:
  if (uVar8 == 3) goto locret_F00119A8;
  _splusclock();
  iVar1 = _active_threads;
  iVar5 = _active_threads;
  if (iVar6 != *(int *)(_active_threads + 0xc)) {
    do {
      do {
      } while (*(int *)(iVar6 + 0x28) != 0);
      piVar3 = (int *)(iVar6 + 0x28);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    iVar5 = *(int *)(iVar6 + 0x1c);
    if (iVar6 + 0x1c == iVar5) {
      *(undefined4 *)(iVar6 + 0x28) = 0;
      _splx(uVar2);
      goto locret_F00119A8;
    }
    _thread_reference(iVar5);
    *(undefined4 *)(iVar6 + 0x28) = 0;
  }
  if (param_2 == 9) {
    if ('\0' < *(char *)(param_1 + 0x15)) {
      *(undefined *)(param_1 + 0x15) = 0;
      _thread_max_priority(iVar5,*(undefined4 *)(iVar5 + 400),10);
      _thread_priority(iVar5,10,0);
    }
    uVar4 = *(uint *)(param_1 + 0x28);
  }
  else {
    uVar4 = *(uint *)(param_1 + 0x28);
  }
  if ((uVar4 & 0x10) == 0) {
    if (uVar8 != 0) {
      if (param_2 != 0x13) goto loc_F0011980;
      _task_resume(iVar6);
      *(undefined *)(param_1 + 0x13) = 3;
def_F00117E0:
      goto loc_F0011980;
    }
    switch(param_2) {
    case :
      while (0 < *(int *)(iVar6 + 0x44)) {
        _task_resume(iVar6);
      }
      *(undefined *)(param_1 + 0x13) = 3;
      while (0 < *(int *)(iVar5 + 0x8c)) {
        _thread_resume(iVar5);
      }
      _clear_wait(iVar5,3,0);
      _splx(uVar2);
      if (iVar5 != iVar1) {
        _mach_msg_abort_rpc(iVar5);
        _thread_deallocate(iVar5);
      }
      goto locret_F00119A8;
    :
      goto def_F00117E0;
    case :
    case :
    case :
    case :
      uVar8 = *(uint *)(param_1 + 0x18);
loc_F00118F0:
      *(uint *)(param_1 + 0x18) = uVar8 & ~uVar7;
      break;
    case :
    case :
    case :
    case :
      if (param_2 == 0x11) {
        uVar8 = *(uint *)(iVar5 + 0x4c);
      }
      else {
        if (*(int *)(param_1 + 0x44) == _init_proc) {
          _psignal(param_1,9);
          uVar8 = *(uint *)(param_1 + 0x18);
          goto loc_F00118F0;
        }
        uVar8 = *(uint *)(iVar5 + 0x4c);
      }
      if ((uVar8 & 4) == 0) {
        *(uint *)(param_1 + 0x18) = *(uint *)(param_1 + 0x18) & ~uVar7;
        if (*(int *)(iVar6 + 0x44) == 0) {
          *(uint *)(param_1 + 0x3c) = param_2;
          _psignal(*(undefined4 *)(param_1 + 0x44),0x14);
          _stop(param_1);
        }
      }
      else if ((param_1 == *_active_u) && (*(char *)(param_1 + 0x13) != '\x05')) {
        _need_ast = _need_ast | 0x20;
      }
      break;
    case :
      _task_resume(iVar6);
      *(undefined *)(param_1 + 0x13) = 3;
    }
  }
  else {
    if (*(char *)(param_1 + 0x13) == '\x06') goto loc_F001198C;
loc_F0011980:
    _clear_wait(iVar5,2,1);
  }
loc_F001198C:
  _splx(uVar2);
  if (iVar5 != iVar1) {
    _thread_deallocate_interrupt(iVar5);
  }
locret_F00119A8:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=231 start=0xf00119b0 */

/* WARNING: Removing unreachable block (ram,0xf0011a38) */
/* WARNING: Removing unreachable block (ram,0xf0011edc) */
/* WARNING: Removing unreachable block (ram,0xf0011e84) */
/* WARNING: Removing unreachable block (ram,0xf0011e6c) */
/* WARNING: Removing unreachable block (ram,0xf0011ccc) */
/* WARNING: Removing unreachable block (ram,0xf0011ca4) */
/* WARNING: Removing unreachable block (ram,0xf0011c5c) */
/* WARNING: Removing unreachable block (ram,0xf0011c2c) */
/* WARNING: Removing unreachable block (ram,0xf0011c10) */
/* WARNING: Removing unreachable block (ram,0xf0011bb8) */
/* WARNING: Removing unreachable block (ram,0xf0011b44) */
/* WARNING: Removing unreachable block (ram,0xf00119f4) */
/* WARNING: Removing unreachable block (ram,0xf0011ba8) */
/* WARNING: Removing unreachable block (ram,0xf0011bd4) */
/* WARNING: Removing unreachable block (ram,0xf0011c24) */
/* WARNING: Removing unreachable block (ram,0xf0011c54) */
/* WARNING: Removing unreachable block (ram,0xf0011c74) */
/* WARNING: Removing unreachable block (ram,0xf0011cbc) */
/* WARNING: Removing unreachable block (ram,0xf0011e48) */
/* WARNING: Removing unreachable block (ram,0xf0011e74) */
/* WARNING: Removing unreachable block (ram,0xf0011e9c) */
/* WARNING: Removing unreachable block (ram,0xf0011a30) */
/* WARNING: Removing unreachable block (ram,0xf0011a68) */
/* WARNING: Removing unreachable block (ram,0xf00119d8) */

undefined8 _issig(int param_1,undefined4 *param_2)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int iVar6;
  uint uVar7;
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
  iVar6 = *_active_u;
  if (_master_cpu != 0) {
    _panic(aIssigNotOnMast);
  }
  do {
    do {
    } while (*(int *)(iVar6 + 0x70) != 0);
    piVar5 = (int *)(iVar6 + 0x70);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  iVar2 = *(int *)(iVar6 + 0x74);
  do {
    if (iVar2 == 0) {
      if (*(int *)(iVar6 + 0x78) == 0) {
        param_2 = &_active_u;
loc_F0011AB8:
        do {
loc_F0011ABC:
          if (*(char *)(dword_F0133DDC + 0x48) != '\0') {
            *(uint *)(dword_F0133DDC + 0x4c) =
                 *(uint *)(dword_F0133DDC + 0x4c) |
                 1 << (*(char *)(dword_F0133DDC + 0x48) - 1U & 0x1f);
            *(undefined *)(dword_F0133DDC + 0x48) = 0;
          }
          iVar2 = dword_F0133DDC;
          uVar8 = (*(uint *)(dword_F0133DDC + 0x4c) | *(uint *)(iVar6 + 0x18)) &
                  ~*(uint *)(iVar6 + 0x1c);
          uVar7 = *(uint *)(iVar6 + 0x28) & 0x10;
          if (uVar7 == 0) {
            uVar8 = uVar8 & ~*(uint *)(iVar6 + 0x20);
          }
          if ((*(uint *)(iVar6 + 0x28) & 0x1000) != 0) {
            uVar8 = uVar8 & 0xffccffff;
          }
          if (uVar8 == 0) {
            *(undefined *)(iVar6 + 0x17) = 0;
            uVar8 = 0;
            *(undefined *)(dword_F0133DDC + 0x48) = 0;
            goto def_F0011DF0;
          }
          if ((param_1 != 0) && (uVar7 != 0)) goto loc_F0011F04;
          _ffs();
          cVar1 = (char)uVar8;
          uVar7 = 1 << (cVar1 - 1U & 0x1f);
          if ((uVar7 & 0x1ef8) == 0) {
            uVar3 = *(uint *)(iVar6 + 0x18);
          }
          else {
            *(char *)(iVar2 + 0x48) = cVar1;
            *(uint *)(dword_F0133DDC + 0x4c) = *(uint *)(dword_F0133DDC + 0x4c) & ~uVar7;
            uVar3 = *(uint *)(iVar6 + 0x18);
          }
          *(char *)(iVar6 + 0x17) = cVar1;
          *(uint *)(iVar6 + 0x18) = uVar3 & ~uVar7;
          if ((*(uint *)(iVar6 + 0x28) & 0x1010) != 0x10) goto loc_F0011D70;
          _psignal(*(undefined4 *)(iVar6 + 0x44),0x14);
          *(int *)(iVar6 + 0x6c) = _active_threads;
          _pcb_synch();
          piVar5 = *(int **)(iVar6 + 0x68);
          do {
            do {
            } while (*piVar5 != 0);
            piVar4 = piVar5;
            _simple_lock_try();
          } while (piVar4 == (int *)0x0);
          iVar2 = piVar5[0x11];
          piVar5[0x11] = iVar2 + 1;
          *piVar5 = 0;
          if (iVar2 + 1 == 1) {
            _task_hold(piVar5);
            *(undefined4 *)(iVar6 + 0x74) = 1;
            *(undefined4 *)(iVar6 + 0x70) = 0;
            _task_dowait(piVar5,1);
            _thread_hold(_active_threads);
          }
          else {
            *(undefined4 *)(iVar6 + 0x74) = 1;
            *(undefined4 *)(iVar6 + 0x70) = 0;
          }
          *(undefined *)(iVar6 + 0x13) = 6;
          *(uint *)(iVar6 + 0x28) = *(uint *)(iVar6 + 0x28) & 0xffffffdf;
          _wakeup(*(undefined4 *)(iVar6 + 0x44));
          _thread_block();
          do {
            do {
            } while (*(int *)(iVar6 + 0x70) != 0);
            piVar5 = (int *)(iVar6 + 0x70);
            _simple_lock_try();
          } while (piVar5 == (int *)0x0);
          *(undefined4 *)(iVar6 + 0x74) = 0;
          uVar8 = (uint)*(char *)(iVar6 + 0x17);
          if (0x20 < (int)uVar8) {
            _clear_wait(_active_threads,2,0);
            *(int *)(iVar6 + 0x78) = _active_threads;
            *(undefined4 *)(iVar6 + 0x70) = 0;
            _task_hold(*(undefined4 *)(_active_threads + 0xc));
            _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
                    /* WARNING: Subroutine does not return */
            _exit(uVar8 - 0x20);
          }
          if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto loc_F0011F04;
          if ((*(uint *)(iVar6 + 0x28) & 0x10) != 0) goto loc_F0011D24;
          if ((uVar7 & 0x1ef8) == 0) {
            uVar8 = *(uint *)(iVar6 + 0x18);
loc_F0011D60:
            *(uint *)(iVar6 + 0x18) = uVar8 | uVar7;
          }
          else {
loc_F0011D4C:
            *(uint *)(dword_F0133DDC + 0x4c) = *(uint *)(dword_F0133DDC + 0x4c) | uVar7;
          }
        } while( true );
      }
      iVar2 = *(int *)(iVar6 + 0x78);
    }
    else {
      iVar2 = *(int *)(iVar6 + 0x78);
    }
    *(undefined4 *)(iVar6 + 0x70) = 0;
    if (iVar2 != 0) {
      uVar8 = 0;
      if (_active_threads == iVar2) goto locret_F0011F14;
      _thread_hold();
    }
    _thread_block();
    if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) {
loc_F0011F08:
      uVar8 = 1;
locret_F0011F14:
      return CONCAT44(param_2,uVar8);
    }
    do {
      do {
      } while (*(int *)(iVar6 + 0x70) != 0);
      piVar5 = (int *)(iVar6 + 0x70);
      _simple_lock_try();
    } while (piVar5 == (int *)0x0);
    iVar2 = *(int *)(iVar6 + 0x74);
  } while( true );
loc_F0011D24:
  if (uVar8 == 0) goto loc_F0011ABC;
  uVar7 = 1 << (*(char *)(iVar6 + 0x17) - 1U & 0x1f);
  if ((*(uint *)(iVar6 + 0x1c) & uVar7) != 0) {
    if ((uVar7 & 0x1ef8) != 0) goto loc_F0011D4C;
    uVar8 = *(uint *)(iVar6 + 0x18);
    goto loc_F0011D60;
  }
loc_F0011D70:
  iVar2 = _active_u[uVar8 + 0xc];
  if (iVar2 == 1) {
    uVar7 = *(uint *)(iVar6 + 0x28);
  }
  else {
    if (iVar2 < 2) {
      if (iVar2 != 0) goto def_F0011DF0;
      if (*(sword *)(iVar6 + 0x32) == 0) {
        *(undefined *)(dword_F0133DDC + 0x48) = 0;
        *(uint *)(dword_F0133DDC + 0x4c) = *(uint *)(dword_F0133DDC + 0x4c) & ~uVar7;
        goto loc_F0011AB8;
      }
      switch(uVar8) {
      case :
      case :
      case :
      case :
      case :
        goto loc_F0011AB8;
      case :
        uVar7 = *(uint *)(iVar6 + 0x28);
        break;
      case :
      case :
      case :
        if (*(int *)(iVar6 + 0x44) == _init_proc) {
          _psignal(iVar6,9);
          goto loc_F0011ABC;
        }
        uVar7 = *(uint *)(iVar6 + 0x28);
        break;
      :
def_F0011DF0:
        *(undefined4 *)(iVar6 + 0x70) = 0;
        goto locret_F0011F14;
      }
      if ((uVar7 & 0x10) == 0) {
        _psignal(*(undefined4 *)(iVar6 + 0x44),0x14);
        _stop(iVar6);
        *(undefined4 *)(iVar6 + 0x74) = 1;
        *(undefined4 *)(iVar6 + 0x70) = 0;
        _thread_block();
        do {
          do {
          } while (*(int *)(iVar6 + 0x70) != 0);
          piVar5 = (int *)(iVar6 + 0x70);
          _simple_lock_try();
        } while (piVar5 == (int *)0x0);
        *(undefined4 *)(iVar6 + 0x74) = 0;
        if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) {
loc_F0011F04:
          *(undefined4 *)(iVar6 + 0x70) = 0;
          goto loc_F0011F08;
        }
      }
      goto loc_F0011ABC;
    }
    if (iVar2 != 3) goto def_F0011DF0;
    uVar7 = *(uint *)(iVar6 + 0x28);
  }
  if ((uVar7 & 0x10) == 0) {
    _printf(&aIssig);
  }
  goto loc_F0011ABC;
}
/* GHIDRADEC_FUNCTION index=232 start=0xf0011f1c */

/* WARNING: Removing unreachable block (ram,0xf0011f3c) */
/* WARNING: Removing unreachable block (ram,0xf0011f20) */

undefined8 _stop(int param_1,undefined4 param_2)

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
  _task_suspend_nowait(*(undefined4 *)(param_1 + 0x68));
  *(undefined *)(param_1 + 0x13) = 6;
  *(uint *)(param_1 + 0x28) = *(uint *)(param_1 + 0x28) & 0xffffffdf;
  _wakeup(*(undefined4 *)(param_1 + 0x44));
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=233 start=0xf0011f4c */

/* WARNING: Removing unreachable block (ram,0xf0011fd4) */
/* WARNING: Removing unreachable block (ram,0xf00122c4) */
/* WARNING: Removing unreachable block (ram,0xf0012288) */
/* WARNING: Removing unreachable block (ram,0xf0012270) */
/* WARNING: Removing unreachable block (ram,0xf001219c) */
/* WARNING: Removing unreachable block (ram,0xf00120d0) */
/* WARNING: Removing unreachable block (ram,0xf0011f8c) */
/* WARNING: Removing unreachable block (ram,0xf0012090) */
/* WARNING: Removing unreachable block (ram,0xf00120e4) */
/* WARNING: Removing unreachable block (ram,0xf00121bc) */
/* WARNING: Removing unreachable block (ram,0xf0012280) */
/* WARNING: Removing unreachable block (ram,0xf00122b4) */
/* WARNING: Removing unreachable block (ram,0xf0011fcc) */
/* WARNING: Removing unreachable block (ram,0xf0012004) */
/* WARNING: Removing unreachable block (ram,0xf0011f70) */

undefined8 _psig(undefined4 param_1,undefined4 param_2)

{
  char cVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  uint uVar6;
  undefined4 unaff_l4;
  int iVar7;
  undefined4 unaff_l5;
  int iVar8;
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
  iVar5 = *_active_u;
  if (_master_cpu != 0) {
    _panic(aPsigNotOnMaste);
  }
  do {
    do {
    } while (*(int *)(iVar5 + 0x70) != 0);
    piVar2 = (int *)(iVar5 + 0x70);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  iVar3 = *(int *)(iVar5 + 0x74);
  do {
    if (iVar3 == 0) {
      if (*(int *)(iVar5 + 0x78) == 0) {
        cVar1 = *(char *)(iVar5 + 0x17);
        iVar3 = (int)cVar1;
        uVar6 = 1 << (cVar1 - 1U & 0x1f);
        if ((iVar3 == 0) || (((uVar6 & 0x1ef8) != 0 && (iVar3 != *(char *)(dword_F0133DDC + 0x48))))
           ) {
loc_F0012248:
          *(undefined4 *)(iVar5 + 0x70) = 0;
        }
        else {
          if (((int)*(char *)(dword_F0133DDC + 0x40) & 0x80U) != 0) {
            _rpcont();
          }
          iVar7 = _active_u[iVar3 + 0xc];
          if (iVar7 == 0) {
            *(word *)(_active_u + 0x90) = *(word *)(_active_u + 0x90) | 0x10;
            switch(iVar3) {
            case :
            case :
            case :
            case :
            case :
            case :
            case :
            case :
            case :
              *(int *)(dword_F0133DDC + 4) = iVar3;
              *(int *)(iVar5 + 0x78) = _active_threads;
              *(undefined4 *)(iVar5 + 0x70) = 0;
              _task_hold(*(undefined4 *)(_active_threads + 0xc));
              iVar5 = *(int *)(_active_threads + 0xc);
              _task_dowait(iVar5,0);
              _core();
              if (iVar5 != 0) {
                iVar3 = iVar3 + 0x80;
              }
              break;
            :
              *(int *)(iVar5 + 0x78) = _active_threads;
              *(undefined4 *)(iVar5 + 0x70) = 0;
              _task_hold(*(undefined4 *)(_active_threads + 0xc));
              _task_dowait(*(undefined4 *)(_active_threads + 0xc),0);
              break;
            case :
            case :
            case :
            case :
              goto loc_F0012248;
            }
                    /* WARNING: Subroutine does not return */
            _exit(iVar3);
          }
          if ((iVar7 == 1) || ((*(uint *)(iVar5 + 0x1c) & uVar6) != 0)) {
            _log(4,aPsigProcessing);
          }
          *(undefined *)(dword_F0133DDC + 0x38) = 0;
          _splusclock();
          uVar4 = *(uint *)(iVar5 + 0x28);
          if ((uVar4 & 0x100000) != 0) {
            if (1 < iVar3 - 4U) {
              _active_u[iVar3 + 0xc] = 0;
              *(uint *)(iVar5 + 0x24) = *(uint *)(iVar5 + 0x24) & ~uVar6;
            }
            uVar6 = 0;
            uVar4 = *(uint *)(iVar5 + 0x28);
          }
          if ((uVar4 & 0x200) == 0) {
            iVar8 = *(int *)(iVar5 + 0x1c);
          }
          else {
            iVar8 = _active_u[0x50];
            *(uint *)(iVar5 + 0x28) = uVar4 & 0xfffffdff;
          }
          *(uint *)(iVar5 + 0x1c) = *(uint *)(iVar5 + 0x1c) | _active_u[iVar3 + 0x2d] | uVar6;
          *(undefined *)(iVar5 + 0x17) = 0;
          if ((0x1ef8 >> (cVar1 - 1U & 0x1f) & 1U) != 0) {
            *(undefined *)(dword_F0133DDC + 0x48) = 0;
          }
          *(undefined4 *)(iVar5 + 0x70) = 0;
          _spl0();
          _active_u[0x6a] = _active_u[0x6a] + 1;
          _sendsig(iVar7,iVar3,iVar8);
        }
locret_F00122D4:
        return CONCAT44(param_2,param_1);
      }
      iVar3 = *(int *)(iVar5 + 0x78);
    }
    else {
      iVar3 = *(int *)(iVar5 + 0x78);
    }
    *(undefined4 *)(iVar5 + 0x70) = 0;
    if (iVar3 != 0) {
      if (_active_threads == iVar3) goto locret_F00122D4;
      _thread_hold();
    }
    _thread_block();
    if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto locret_F00122D4;
    do {
      do {
      } while (*(int *)(iVar5 + 0x70) != 0);
      piVar2 = (int *)(iVar5 + 0x70);
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    iVar3 = *(int *)(iVar5 + 0x74);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=234 start=0xf00122dc */

/* WARNING: Removing unreachable block (ram,0xf0012300) */

undefined8 _sigpending(undefined4 param_1,undefined4 param_2)

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
  iVar1 = *_active_u + 0x18;
  _copyout(iVar1,**(undefined4 **)(dword_F0133DDC + 0x24),4);
  *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=235 start=0xf0012318 */

/* WARNING: Removing unreachable block (ram,0xf00123d0) */
/* WARNING: Removing unreachable block (ram,0xf0012404) */
/* WARNING: Removing unreachable block (ram,0xf00123bc) */

undefined8 _uiomove(int param_1,uint param_2,int param_3,undefined4 *param_4)

{
  int iVar1;
  undefined4 unaff_l0;
  uint uVar2;
  undefined4 unaff_l1;
  int *piVar3;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int iVar4;
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
  iVar4 = 0;
  while ((0 < (int)param_2 && (param_4[5] != 0))) {
    piVar3 = (int *)*param_4;
    uVar2 = piVar3[1];
    if (uVar2 == 0) {
      *param_4 = piVar3 + 2;
      param_4[1] = param_4[1] + -1;
    }
    else {
      if (param_2 < uVar2) {
        uVar2 = param_2;
      }
      iVar1 = param_4[3];
      if (iVar1 == 1) {
        if (param_3 == 0) {
          iVar1 = *piVar3;
          iVar4 = param_1;
        }
        else {
          iVar4 = *piVar3;
          iVar1 = param_1;
        }
        _copywithin(iVar4,iVar1,uVar2);
        iVar1 = *piVar3;
      }
      else if (iVar1 < 2) {
        if (iVar1 == 0) {
loc_F00123AC:
          if (param_3 == 0) {
            iVar4 = param_1;
            _copyout(param_1,*piVar3,uVar2);
          }
          else {
            iVar4 = *piVar3;
            _copyin(iVar4,param_1,uVar2);
          }
          if (iVar4 != 0) break;
          iVar1 = *piVar3;
        }
        else {
          iVar1 = *piVar3;
        }
      }
      else {
        if (iVar1 == 2) goto loc_F00123AC;
        iVar1 = *piVar3;
      }
      param_1 = param_1 + uVar2;
      *piVar3 = iVar1 + uVar2;
      piVar3[1] = piVar3[1] - uVar2;
      param_2 = param_2 - uVar2;
      param_4[5] = param_4[5] - uVar2;
      param_4[2] = param_4[2] + uVar2;
    }
  }
  return CONCAT44(param_2,iVar4);
}
/* GHIDRADEC_FUNCTION index=236 start=0xf0012454 */

/* WARNING: Removing unreachable block (ram,0xf0012504) */
/* WARNING: Removing unreachable block (ram,0xf00124ec) */
/* WARNING: Removing unreachable block (ram,0xf001246c) */

undefined8 _ureadc(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  do {
    if (param_2[1] == 0) {
      _panic(&aUreadc);
      piVar3 = (int *)*param_2;
    }
    else {
      piVar3 = (int *)*param_2;
    }
    if (piVar3[1] < 1) {
      iVar1 = param_2[1];
    }
    else {
      if (0 < param_2[5]) break;
      iVar1 = param_2[1];
    }
    param_2[1] = iVar1 + -1;
    *param_2 = *param_2 + 8;
  } while( true );
  iVar1 = param_2[3];
  if (iVar1 == 1) {
    *(char *)*piVar3 = (char)param_1;
    iVar2 = *piVar3;
loc_F0012524:
    iVar1 = piVar3[1];
  }
  else if (iVar1 < 2) {
    iVar2 = *piVar3;
    if (iVar1 == 0) {
      _subyte(iVar2,param_1);
loc_F0012510:
      if (iVar2 < 0) {
        uVar4 = 0xe;
        goto locret_F0012554;
      }
      iVar2 = *piVar3;
      goto loc_F0012524;
    }
    iVar1 = piVar3[1];
  }
  else {
    iVar2 = *piVar3;
    if (iVar1 == 2) {
      _suibyte(iVar2,param_1);
      goto loc_F0012510;
    }
    iVar1 = piVar3[1];
  }
  *piVar3 = iVar2 + 1;
  piVar3[1] = iVar1 + -1;
  uVar4 = 0;
  param_2[5] = param_2[5] + -1;
  param_2[2] = param_2[2] + 1;
locret_F0012554:
  return CONCAT44(param_2,uVar4);
}
/* GHIDRADEC_FUNCTION index=237 start=0xf001255c */

/* WARNING: Removing unreachable block (ram,0xf00125f8) */
/* WARNING: Removing unreachable block (ram,0xf0012610) */
/* WARNING: Removing unreachable block (ram,0xf0012624) */
/* WARNING: Removing unreachable block (ram,0xf0012588) */

undefined8 _uwritec(undefined4 *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  uint *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  uint uVar4;
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
  uVar3 = 0xffffffff;
  if (0 < (int)param_1[5]) {
    do {
      if ((int)param_1[1] < 1) {
        _panic(&aUwritec);
        puVar2 = (uint *)*param_1;
      }
      else {
        puVar2 = (uint *)*param_1;
      }
      if (puVar2[1] != 0) {
        iVar1 = param_1[3];
        if (iVar1 == 1) {
          uVar4 = (uint)*(byte *)*puVar2;
        }
        else if (iVar1 < 2) {
          if (iVar1 == 0) {
            uVar4 = *puVar2;
            _fubyte();
          }
          else {
loc_F0012620:
            uVar4 = 0;
            _panic(aUwritecBogusUi);
          }
        }
        else {
          if (iVar1 != 2) goto loc_F0012620;
          uVar4 = *puVar2;
          _fuibyte();
        }
        uVar3 = uVar4 & 0xff;
        if ((int)uVar4 < 0) {
          uVar3 = 0xffffffff;
        }
        else {
          *puVar2 = *puVar2 + 1;
          puVar2[1] = puVar2[1] - 1;
          param_1[5] = param_1[5] + -1;
          param_1[2] = param_1[2] + 1;
        }
        goto locret_F0012670;
      }
      iVar1 = param_1[1];
      *param_1 = puVar2 + 2;
      param_1[1] = iVar1 + -1;
    } while (iVar1 + -1 != 0);
    uVar3 = 0xffffffff;
  }
locret_F0012670:
  return CONCAT44(param_2,uVar3);
}
/* GHIDRADEC_FUNCTION index=238 start=0xf0012678 */

/* WARNING: Removing unreachable block (ram,0xf00127f4) */
/* WARNING: Removing unreachable block (ram,0xf0012784) */
/* WARNING: Removing unreachable block (ram,0xf0012744) */
/* WARNING: Removing unreachable block (ram,0xf0012720) */
/* WARNING: Removing unreachable block (ram,0xf0012838) */
/* WARNING: Removing unreachable block (ram,0xf00126b0) */
/* WARNING: Removing unreachable block (ram,0xf001280c) */
/* WARNING: Removing unreachable block (ram,0xf0012840) */
/* WARNING: Removing unreachable block (ram,0xf001273c) */
/* WARNING: Removing unreachable block (ram,0xf0012754) */
/* WARNING: Removing unreachable block (ram,0xf001278c) */
/* WARNING: Removing unreachable block (ram,0xf0012848) */
/* WARNING: Removing unreachable block (ram,0xf0012684) */

undefined8 _sleep(undefined4 param_1,uint param_2)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
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
  bool bVar6;
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
  iVar4 = *_active_u;
  piVar2 = _active_u;
  _splusclock();
  if (iVar4 != 0) {
    *(byte *)(iVar4 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,0x19 < (int)param_2);
  if ((int)param_2 < 0x1a) {
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla_0);
    }
    _thread_block_with_continuation(0);
  }
  else {
    if (iVar4 != 0) {
      if ((*(uint *)(_active_threads + 0x18c) & 3) == 0) {
        uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
        if ((uVar1 != 0) &&
           (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
            ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
          iVar3 = 1;
          _issig();
          if (iVar3 != 0) goto loc_F0012734;
        }
        goto loc_F0012754;
      }
loc_F0012734:
      _clear_wait(_active_threads,2,1);
      _spl0();
      bVar6 = (param_2 & 0x100) == 0;
loc_F0012858:
      uVar5 = 1;
      if (bVar6) {
                    /* WARNING: Subroutine does not return */
        _longjmp(dword_F0133DDC + 0x28);
      }
      goto locret_F0012870;
    }
loc_F0012754:
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(0);
    if (iVar4 != 0) {
      bVar6 = (param_2 & 0x100) == 0;
      if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto loc_F0012858;
      uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
      if ((uVar1 != 0) &&
         (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
          ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
        iVar4 = 1;
        _issig();
        bVar6 = (param_2 & 0x100) == 0;
        if (iVar4 != 0) goto loc_F0012858;
      }
    }
  }
  _splx(piVar2);
  uVar5 = 0;
locret_F0012870:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=239 start=0xf0012878 */

/* WARNING: Removing unreachable block (ram,0xf0012a60) */
/* WARNING: Removing unreachable block (ram,0xf001298c) */
/* WARNING: Removing unreachable block (ram,0xf0012954) */
/* WARNING: Removing unreachable block (ram,0xf001293c) */
/* WARNING: Removing unreachable block (ram,0xf0012a40) */
/* WARNING: Removing unreachable block (ram,0xf0012a0c) */
/* WARNING: Removing unreachable block (ram,0xf00128b0) */
/* WARNING: Removing unreachable block (ram,0xf0012a38) */
/* WARNING: Removing unreachable block (ram,0xf0012920) */
/* WARNING: Removing unreachable block (ram,0xf0012944) */
/* WARNING: Removing unreachable block (ram,0xf0012984) */
/* WARNING: Removing unreachable block (ram,0xf00129f4) */
/* WARNING: Removing unreachable block (ram,0xf0012a48) */
/* WARNING: Removing unreachable block (ram,0xf0012884) */

undefined8 _sleep_with_continuation(undefined4 param_1,uint param_2,int param_3)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
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
  bool bVar6;
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
  iVar4 = *_active_u;
  piVar2 = _active_u;
  _splusclock();
  if (iVar4 != 0) {
    *(byte *)(iVar4 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,0x19 < (int)param_2);
  if ((int)param_2 < 0x1a) {
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla_0);
    }
    _thread_block_with_continuation(param_3);
  }
  else {
    if (iVar4 != 0) {
      if ((*(uint *)(_active_threads + 0x18c) & 3) == 0) {
        uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
        if ((uVar1 != 0) &&
           (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
            ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
          iVar3 = 1;
          _issig();
          if (iVar3 != 0) goto loc_F0012934;
        }
        goto loc_F0012954;
      }
loc_F0012934:
      _clear_wait(_active_threads,2,1);
      _spl0();
loc_F0012A58:
      if (param_3 != 0) {
        _call_continuation(param_3);
      }
      uVar5 = 1;
      if ((param_2 & 0x100) == 0) {
                    /* WARNING: Subroutine does not return */
        _longjmp(dword_F0133DDC + 0x28);
      }
      goto locret_F0012A84;
    }
loc_F0012954:
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(param_3);
    if (iVar4 != 0) {
      if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto loc_F0012A58;
      uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
      if ((uVar1 != 0) &&
         (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
          ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
        iVar4 = 1;
        _issig();
        if (iVar4 != 0) goto loc_F0012A58;
      }
    }
  }
  _splx(piVar2);
  uVar5 = 0;
locret_F0012A84:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=240 start=0xf0012a8c */

/* WARNING: Removing unreachable block (ram,0xf0012cac) */
/* WARNING: Removing unreachable block (ram,0xf0012bbc) */
/* WARNING: Removing unreachable block (ram,0xf0012b84) */
/* WARNING: Removing unreachable block (ram,0xf0012b74) */
/* WARNING: Removing unreachable block (ram,0xf0012b50) */
/* WARNING: Removing unreachable block (ram,0xf0012c8c) */
/* WARNING: Removing unreachable block (ram,0xf0012c58) */
/* WARNING: Removing unreachable block (ram,0xf0012c48) */
/* WARNING: Removing unreachable block (ram,0xf0012ac4) */
/* WARNING: Removing unreachable block (ram,0xf0012c50) */
/* WARNING: Removing unreachable block (ram,0xf0012c84) */
/* WARNING: Removing unreachable block (ram,0xf0012b34) */
/* WARNING: Removing unreachable block (ram,0xf0012b58) */
/* WARNING: Removing unreachable block (ram,0xf0012b7c) */
/* WARNING: Removing unreachable block (ram,0xf0012bb4) */
/* WARNING: Removing unreachable block (ram,0xf0012c24) */
/* WARNING: Removing unreachable block (ram,0xf0012c94) */
/* WARNING: Removing unreachable block (ram,0xf0012a98) */

undefined8
_sleep_with_continuation_and_deadline(undefined4 param_1,uint param_2,int param_3,int param_4)

{
  uint uVar1;
  int *piVar2;
  int iVar3;
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
  bool bVar6;
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
  iVar4 = *_active_u;
  piVar2 = _active_u;
  _splusclock();
  if (iVar4 != 0) {
    *(byte *)(iVar4 + 0x11) = (byte)param_2 & 0x7f;
  }
  _assert_wait(param_1,0x19 < (int)param_2);
  if ((int)param_2 < 0x1a) {
    if (param_4 != 0) {
      _hzto(param_4);
      _thread_set_timeout();
    }
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla_0);
    }
    _thread_block_with_continuation(param_3);
  }
  else {
    if (iVar4 != 0) {
      if ((*(uint *)(_active_threads + 0x18c) & 3) == 0) {
        uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
        if ((uVar1 != 0) &&
           (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
            ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
          iVar3 = 1;
          _issig();
          if (iVar3 != 0) goto loc_F0012B48;
        }
        goto loc_F0012B6C;
      }
loc_F0012B48:
      _clear_wait(_active_threads,2,1);
      _spl0();
loc_F0012CA4:
      if (param_3 != 0) {
        _call_continuation(param_3);
      }
      uVar5 = 1;
      if ((param_2 & 0x100) == 0) {
                    /* WARNING: Subroutine does not return */
        _longjmp(dword_F0133DDC + 0x28);
      }
      goto locret_F0012CD0;
    }
loc_F0012B6C:
    if (param_4 != 0) {
      _hzto(param_4);
      _thread_set_timeout();
    }
    _spl0();
    bVar6 = _master_cpu != 0;
    _active_u[0x6b] = _active_u[0x6b] + 1;
    if (bVar6) {
      _printf(aUnixSleepOnSla);
    }
    _thread_block_with_continuation(param_3);
    if (iVar4 != 0) {
      if ((*(uint *)(_active_threads + 0x18c) & 3) != 0) goto loc_F0012CA4;
      uVar1 = *(uint *)(iVar4 + 0x18) | *(uint *)(*(int *)(_active_threads + 0x84) + 0x4c);
      if ((uVar1 != 0) &&
         (((*(uint *)(iVar4 + 0x28) & 0x10) != 0 ||
          ((uVar1 & ~(*(uint *)(iVar4 + 0x20) | *(uint *)(iVar4 + 0x1c))) != 0)))) {
        iVar4 = 1;
        _issig();
        if (iVar4 != 0) goto loc_F0012CA4;
      }
    }
  }
  _splx(piVar2);
  uVar5 = 0;
locret_F0012CD0:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=241 start=0xf0012cd8 */

/* WARNING: Removing unreachable block (ram,0xf0012d88) */
/* WARNING: Removing unreachable block (ram,0xf0012d40) */
/* WARNING: Removing unreachable block (ram,0xf0012d4c) */
/* WARNING: Removing unreachable block (ram,0xf0012da4) */
/* WARNING: Removing unreachable block (ram,0xf0012d2c) */

undefined8
_rpsleep(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
        undefined4 param_5)

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
  *(undefined4 *)((int)register0x00000038 + 0x44) = param_1;
  *(undefined4 *)((int)register0x00000038 + 0x48) = param_2;
  *(undefined4 *)((int)register0x00000038 + 0x4c) = param_3;
  *(undefined4 *)((int)register0x00000038 + 0x50) = param_4;
  *(undefined4 *)((int)register0x00000038 + 0x54) = param_5;
  *(undefined4 *)((int)register0x00000038 + -0x14) = 1;
  if (((int)(char)*(byte *)(dword_F0133DDC + 0x40) & 0x80U) == 0) {
    *(byte *)(dword_F0133DDC + 0x40) = *(byte *)(dword_F0133DDC + 0x40) | 0x80;
    _uprintf(aSSSPausing,_active_u + 8,*(undefined4 *)((int)register0x00000038 + 0x50),
             *(undefined4 *)((int)register0x00000038 + 0x54));
  }
  _bcopy(dword_F0133DDC + 0x28,(undefined *)((int)register0x00000038 + -0x10),8);
  iVar1 = dword_F0133DDC + 0x28;
  _setjmp();
  if (iVar1 == 0) {
    (**(code **)((int)register0x00000038 + 0x44))
              (*(undefined4 *)((int)register0x00000038 + 0x48),
               *(undefined4 *)((int)register0x00000038 + 0x4c));
  }
  else {
    *(undefined4 *)((int)register0x00000038 + -0x14) = 0;
  }
  _bcopy((undefined *)((int)register0x00000038 + -0x10),dword_F0133DDC + 0x28,8);
  uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
  if (((int)*(char *)(dword_F0133DDC + 0x40) & 0x80U) == 0) {
    _rpcont();
    uVar2 = *(undefined4 *)((int)register0x00000038 + -0x14);
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=242 start=0xf0012db8 */

/* WARNING: Removing unreachable block (ram,0xf0012dd8) */

undefined8 _rpcont(undefined4 param_1,undefined4 param_2)

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
  *(undefined *)(dword_F0133DDC + 0x40) = 0;
  _uprintf(aSContinuing,_active_u + 8);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=243 start=0xf0012de8 */

/* WARNING: Removing unreachable block (ram,0xf0012e00) */
/* WARNING: Removing unreachable block (ram,0xf0012e08) */
/* WARNING: Removing unreachable block (ram,0xf0012dec) */

undefined8 _wakeup(undefined4 param_1,undefined4 param_2)

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
  uVar1 = param_1;
  _splusclock();
  _thread_wakeup_prim(param_1,0,0);
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=244 start=0xf0012e18 */

/* WARNING: Removing unreachable block (ram,0xf0012e30) */
/* WARNING: Removing unreachable block (ram,0xf0012e38) */
/* WARNING: Removing unreachable block (ram,0xf0012e1c) */

undefined8 _wakeup_one(undefined4 param_1,undefined4 param_2)

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
  uVar1 = param_1;
  _splusclock();
  _thread_wakeup_prim(param_1,1,0);
  _splx(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=245 start=0xf0012e48 */

undefined8 _rqinit(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  iVar2 = 0;
  puVar1 = _qs;
  do {
    *(undefined **)(puVar1 + 4) = puVar1;
    *(undefined **)puVar1 = puVar1;
    iVar2 = iVar2 + 1;
    puVar1 = puVar1 + 8;
  } while (iVar2 < 0x20);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=246 start=0xf0012e78 */

/* WARNING: Removing unreachable block (ram,0xf0012ea8) */
/* WARNING: Removing unreachable block (ram,0xf0012e98) */

undefined8 _gettimeofday(undefined4 param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined *puVar1;
  undefined4 unaff_l1;
  int *piVar2;
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
  piVar2 = *(int **)(dword_F0133DDC + 0x24);
  puVar1 = (undefined *)((int)register0x00000038 + -0x10);
  if (*piVar2 != 0) {
    _microtime(puVar1);
    _copyout(puVar1,*piVar2,8);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar1;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=247 start=0xf0012ec0 */

/* WARNING: Removing unreachable block (ram,0xf0012f08) */
/* WARNING: Removing unreachable block (ram,0xf0012ee4) */

undefined8 _settimeofday(undefined4 param_1,undefined4 param_2)

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
  iVar1 = **(int **)(dword_F0133DDC + 0x24);
  if (iVar1 != 0) {
    _copyin(iVar1,(undefined *)((int)register0x00000038 + -0x10),8);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      _setthetime((undefined *)((int)register0x00000038 + -0x10));
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=248 start=0xf0012f18 */

/* WARNING: Removing unreachable block (ram,0xf0012f30) */
/* WARNING: Removing unreachable block (ram,0xf0012f7c) */
/* WARNING: Removing unreachable block (ram,0xf0012f1c) */

undefined8 _setthetime(int *param_1,undefined4 param_2)

{
  int *piVar1;
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
  piVar1 = param_1;
  _suser();
  if (piVar1 != (int *)0x0) {
    _getthetime((undefined *)((int)register0x00000038 + -0x10));
    _boottime = _boottime + (*param_1 - *(int *)((int)register0x00000038 + -0x10));
    DAT_f013516c = 0;
    iVar3 = *param_1;
    *(int *)((int)register0x00000038 + -0x18) = iVar3;
    iVar2 = param_1[1];
    *(int *)((int)register0x00000038 + -0x14) = iVar2;
    *(int *)((int)register0x00000038 + -0x20) = iVar3;
    *(int *)((int)register0x00000038 + -0x1c) = iVar2;
    _host_set_time(dword_F0135174,(undefined *)((int)register0x00000038 + -0x20));
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=249 start=0xf0012f8c */

undefined8 _getthetime(int *param_1)

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
  int iVar1;
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
  do {
    iVar1 = *_mtime;
    *(int *)((int)register0x00000038 + -0x10) = iVar1;
    *(int *)((int)register0x00000038 + -0xc) = _mtime[1];
  } while (iVar1 != _mtime[2]);
  *param_1 = iVar1;
  param_1[1] = *(int *)((int)register0x00000038 + -0xc);
  return CONCAT44(iVar1,param_1);
}

