/* GHIDRADEC_FUNCTION index=1550 start=0xf006f940 */

undefined8 _enqueue_tail(int param_1,int *param_2)

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
  *param_2 = param_1;
  puVar1 = *(undefined4 **)(param_1 + 4);
  param_2[1] = (int)puVar1;
  *puVar1 = param_2;
  *(int **)(param_1 + 4) = param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1551 start=0xf006f960 */

undefined8 _dequeue_head(int *param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar1;
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
  piVar1 = (int *)*param_1;
  if (piVar1 == param_1) {
    piVar1 = (int *)0x0;
  }
  else {
    *(int **)(*piVar1 + 4) = param_1;
    *param_1 = *piVar1;
  }
  return CONCAT44(param_2,piVar1);
}
/* GHIDRADEC_FUNCTION index=1552 start=0xf006f990 */

undefined8 _dequeue_tail(int param_1,undefined4 param_2)

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
  iVar1 = *(int *)(param_1 + 4);
  if (iVar1 == param_1) {
    iVar1 = 0;
  }
  else {
    **(int **)(iVar1 + 4) = param_1;
    *(undefined4 *)(param_1 + 4) = *(undefined4 *)(iVar1 + 4);
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=1553 start=0xf006f9c0 */

undefined8 _remqueue(undefined4 param_1,int *param_2)

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
  *(int *)(*param_2 + 4) = param_2[1];
  *(int *)param_2[1] = *param_2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1554 start=0xf006f9e4 */

undefined8 _insque(int *param_1,int *param_2)

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
  *param_1 = *param_2;
  param_1[1] = (int)param_2;
  *(int **)(*param_2 + 4) = param_1;
  *param_2 = (int)param_1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1555 start=0xf006fa08 */

undefined8 _remque(int *param_1,undefined4 param_2)

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
  *(int *)(*param_1 + 4) = param_1[1];
  *(int *)param_1[1] = *param_1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1556 start=0xf006fa2c */

/* WARNING: Removing unreachable block (ram,0xf006faf8) */
/* WARNING: Removing unreachable block (ram,0xf006fa88) */
/* WARNING: Removing unreachable block (ram,0xf006fb18) */
/* WARNING: Removing unreachable block (ram,0xf006fab0) */
/* WARNING: Removing unreachable block (ram,0xf006fa44) */

undefined8 _kdp_packet(undefined4 param_1,uint *param_2,undefined4 param_3)

{
  uint uVar1;
  undefined4 unaff_l0;
  undefined *puVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint uVar3;
  undefined *puVar4;
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
  puVar2 = (undefined *)((int)register0x00000038 + -0x610);
  uVar3 = *param_2;
  _bcopy(param_1,puVar2,0x604);
  uVar1 = *(uint *)((int)register0x00000038 + -0x610);
  if ((uVar3 < 8) || ((uVar1 & 0xffff) != uVar3)) {
    _safe_prf(aKdpPacketBadLe,uVar3,*(uint *)((int)register0x00000038 + -0x610) & 0xffff);
    puVar4 = (undefined *)0x0;
  }
  else if ((uVar1 & 0x1000000) == 0) {
    uVar3 = uVar1 >> 0x19;
    if (uVar3 < 0xf) {
      puVar4 = puVar2;
      (**(code **)(unk_F01100B8 + uVar3 * 4))(puVar2,param_2,param_3);
      _bcopy(puVar2,param_1,*param_2);
    }
    else {
      _safe_prf(aKdpPacketBadRe,uVar3,uVar1 & 0xffff,uVar1 >> 0x10 & 0xff,
                *(undefined4 *)((int)register0x00000038 + -0x60c));
      puVar4 = (undefined *)0x0;
    }
  }
  else {
    _safe_prf(aKdpPacketReply,uVar1 >> 0x19,uVar1 >> 0x10 & 0xff);
    puVar4 = (undefined *)0x0;
  }
  return CONCAT44(param_2,puVar4);
}
/* GHIDRADEC_FUNCTION index=1557 start=0xf0070a0c */

/* WARNING: Removing unreachable block (ram,0xf0070b14) */
/* WARNING: Removing unreachable block (ram,0xf0070af4) */
/* WARNING: Removing unreachable block (ram,0xf0070ad0) */
/* WARNING: Removing unreachable block (ram,0xf0070a7c) */
/* WARNING: Removing unreachable block (ram,0xf0070a28) */
/* WARNING: Removing unreachable block (ram,0xf0070a74) */
/* WARNING: Removing unreachable block (ram,0xf0070aa4) */
/* WARNING: Removing unreachable block (ram,0xf0070abc) */
/* WARNING: Removing unreachable block (ram,0xf0070b0c) */
/* WARNING: Removing unreachable block (ram,0xf0070b1c) */
/* WARNING: Removing unreachable block (ram,0xf0070a10) */

undefined8 _kdp_raise_exception(uint param_1,undefined4 param_2,undefined4 param_3,int param_4)

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
  _kdp_intr_disbl();
  if (param_4 == 0) {
    _safe_prf(aKdpRaiseExcept);
  }
  if (param_1 != 6) {
    if ((6 < param_1) || (uVar2 = param_1, param_1 == 0)) {
      uVar2 = 0;
    }
    _safe_prf(aSExceptionXXX,*(undefined4 *)(unk_F01101A8 + uVar2 * 4),param_1,param_2,param_3);
  }
  _kdp_flush_cache();
  dword_F013C40C = param_4;
  if (dword_F012FF24 != 0) {
    _kdp_panic(aKdpRaiseExcept_0);
  }
  if (dword_F013C408 == 0) {
    sub_F0070810();
  }
  else {
    sub_F0070944(param_1,param_2,param_3);
  }
  if (dword_F013C408 != 0) {
    DAT_f013c410._0_4_ = 1;
    sub_F00706FC(param_4);
    if (dword_F013C408 == 0) {
      _safe_prf(aRemoteDebugger);
    }
  }
  _kdp_flush_cache();
  _kdp_intr_enbl(uVar1);
  return CONCAT44(param_2,&_kdp);
}
/* GHIDRADEC_FUNCTION index=1558 start=0xf0070b2c */

undefined8 _kdp_reset(undefined4 param_1,undefined4 param_2)

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
  DAT_f013c414 = 0;
  _kdp = 0;
  dword_F013C408 = 0;
  DAT_f013c410._0_4_ = 0;
  uRamf013c404 = 0;
  byte_F013C416 = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1559 start=0xf0070b58 */

undefined8 _wait_queue_init(void)

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
  iVar3 = 0;
  iVar2 = 0;
  puVar1 = _wait_queue;
  do {
    *(undefined **)(puVar1 + 4) = puVar1;
    *(undefined **)puVar1 = puVar1;
    *(undefined4 *)(_wait_lock + iVar2) = 0;
    iVar2 = iVar2 + 4;
    iVar3 = iVar3 + 1;
    puVar1 = puVar1 + 8;
  } while (iVar3 < 0x3b);
  return CONCAT44(_wait_lock,iVar3);
}
/* GHIDRADEC_FUNCTION index=1560 start=0xf0070b9c */

/* WARNING: Removing unreachable block (ram,0xf0070bd8) */
/* WARNING: Removing unreachable block (ram,0xf0070bc4) */
/* WARNING: Removing unreachable block (ram,0xf0070bd0) */
/* WARNING: Removing unreachable block (ram,0xf0070c04) */
/* WARNING: Removing unreachable block (ram,0xf0070bb4) */

undefined8 _sched_init(undefined4 param_1,undefined4 param_2)

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
  DAT_f013c468._0_4_ = _recompute_priorities;
  DAT_f013c468._4_4_ = 0;
  _init_timeout_element();
  uVar1 = _hz;
  .div(_hz,10);
  _min_quantum = uVar1;
  _wait_queue_init();
  _pset_sys_bootstrap();
  DAT_f013c1b4._0_4_ = _action_queue;
  _action_queue._0_4_ = _action_queue;
  _action_lock = 0;
  _sched_tick = 0;
  _sched_usec = 0;
  _ast_init();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1561 start=0xf0070c14 */

/* WARNING: Removing unreachable block (ram,0xf0070c20) */

undefined8 _thread_timeout(undefined4 param_1,undefined4 param_2)

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
  _clear_wait(param_1,1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1562 start=0xf0070c30 */

/* WARNING: Removing unreachable block (ram,0xf0070c7c) */
/* WARNING: Removing unreachable block (ram,0xf0070c58) */
/* WARNING: Removing unreachable block (ram,0xf0070c88) */
/* WARNING: Removing unreachable block (ram,0xf0070c38) */

undefined8 _thread_set_timeout(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined *puVar2;
  int *piVar3;
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
  
  iVar1 = _active_threads;
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
  puVar2 = DAT_f0134000;
  _splusclock();
  do {
    do {
    } while (*(int *)(iVar1 + 0x20) != 0);
    piVar3 = (int *)(iVar1 + 0x20);
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  if ((*(uint *)(iVar1 + 0x4c) & 1) != 0) {
    _set_timeout(iVar1 + 0x118,param_1);
  }
  *(undefined4 *)(iVar1 + 0x20) = 0;
  _splx(puVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1563 start=0xf0070c98 */

/* WARNING: Removing unreachable block (ram,0xf0070cc4) */
/* WARNING: Removing unreachable block (ram,0xf0070cac) */

undefined8 _thread_timeout_setup(int param_1,undefined4 param_2)

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
  *(code **)(param_1 + 0x140) = _thread_timeout;
  *(int *)(param_1 + 0x144) = param_1;
  _init_timeout_element(param_1 + 0x118);
  *(code **)(param_1 + 0x178) = _thread_depress_timeout;
  *(int *)(param_1 + 0x17c) = param_1;
  _init_timeout_element(param_1 + 0x150);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1564 start=0xf0070cd4 */

/* WARNING: Removing unreachable block (ram,0xf0070d88) */
/* WARNING: Removing unreachable block (ram,0xf0070d28) */
/* WARNING: Removing unreachable block (ram,0xf0070d04) */
/* WARNING: Removing unreachable block (ram,0xf0070cfc) */
/* WARNING: Removing unreachable block (ram,0xf0070df0) */
/* WARNING: Removing unreachable block (ram,0xf0070d64) */
/* WARNING: Removing unreachable block (ram,0xf0070e20) */
/* WARNING: Removing unreachable block (ram,0xf0070cf0) */

undefined8 _assert_wait(uint param_1,int param_2)

{
  undefined4 *puVar1;
  undefined *puVar2;
  int *piVar3;
  undefined4 *puVar4;
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
  
  puVar1 = _active_threads;
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
  puVar2 = (undefined *)0xf0110000;
  if (_active_threads[0xf] != 0) {
    _printf(aAssertWaitAlre);
    puVar2 = aAssertWait;
    _panic(aAssertWait);
  }
  _splusclock();
  if (param_1 == 0) {
    do {
      do {
      } while (puVar1[8] != 0);
      piVar7 = puVar1 + 8;
      _simple_lock_try();
    } while (piVar7 == (int *)0x0);
    if (param_2 == 0) {
      uVar5 = puVar1[0x13] | 9;
    }
    else {
      uVar5 = puVar1[0x13] | 1;
    }
    puVar1[0x13] = uVar5;
    puVar1[8] = 0;
  }
  else {
    uVar5 = param_1;
    if ((int)param_1 < 0) {
      uVar5 = ~param_1;
    }
    .rem(uVar5,0x3b);
    iVar6 = uVar5 * 8;
    piVar7 = (int *)(_wait_lock + uVar5 * 4);
    do {
      do {
      } while (*piVar7 != 0);
      piVar3 = piVar7;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    do {
      do {
      } while (puVar1[8] != 0);
      piVar3 = puVar1 + 8;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    *puVar1 = _wait_queue + iVar6;
    puVar4 = *(undefined4 **)(_wait_queue + iVar6 + 4);
    puVar1[1] = puVar4;
    *puVar4 = puVar1;
    *(undefined4 **)(_wait_queue + iVar6 + 4) = puVar1;
    puVar1[0xf] = param_1;
    if (param_2 == 0) {
      uVar5 = puVar1[0x13] | 9;
    }
    else {
      uVar5 = puVar1[0x13] | 1;
    }
    puVar1[0x13] = uVar5;
    puVar1[8] = 0;
    *piVar7 = 0;
  }
  _splx(puVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1565 start=0xf0070e30 */

/* WARNING: Removing unreachable block (ram,0xf0070fd0) */
/* WARNING: Removing unreachable block (ram,0xf0070eec) */
/* WARNING: Removing unreachable block (ram,0xf0070ea0) */
/* WARNING: Removing unreachable block (ram,0xf0070e50) */
/* WARNING: Removing unreachable block (ram,0xf0070ec8) */
/* WARNING: Removing unreachable block (ram,0xf0070f50) */
/* WARNING: Removing unreachable block (ram,0xf0070fec) */
/* WARNING: Removing unreachable block (ram,0xf0070e34) */

undefined8 _clear_wait(int *param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int *piVar3;
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
  int *piVar5;
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
  piVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (param_1[8] != 0);
    piVar5 = param_1 + 8;
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  if (param_3 == 0) {
    uVar4 = param_1[0xf];
  }
  else {
    if ((param_1[0x13] & 8U) != 0) goto def_F0070F78;
    uVar4 = param_1[0xf];
  }
  bVar6 = uVar4 == 0;
  if (!bVar6) {
    param_1[8] = 0;
    uVar2 = uVar4;
    if ((int)uVar4 < 0) {
      uVar2 = ~uVar4;
    }
    .rem(uVar2,0x3b);
    piVar5 = (int *)(_wait_lock + uVar2 * 4);
    do {
      do {
      } while (*piVar5 != 0);
      piVar3 = piVar5;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    do {
      do {
      } while (param_1[8] != 0);
      piVar3 = param_1 + 8;
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if (param_1[0xf] == uVar4) {
      *(int *)(*param_1 + 4) = param_1[1];
      uVar4 = 0;
      *(int *)param_1[1] = *param_1;
      param_1[0xf] = 0;
    }
    *piVar5 = 0;
    bVar6 = uVar4 == 0;
  }
  if (bVar6) {
    uVar4 = param_1[0x13];
    if (param_1[0x53] != 0) {
      _reset_timeout(param_1 + 0x46);
    }
    switch(uVar4 & 0xf) {
    case :
    case :
    case :
      param_1[0x13] = uVar4 & 0xfffffffe | 4;
      param_1[0x11] = param_2;
      _thread_setrun(param_1,1);
      break;
    case :
    case :
    case :
    case :
    case :
      param_1[0x13] = uVar4 & 0xfffffffe;
      param_1[0x11] = param_2;
    }
  }
def_F0070F78:
  param_1[8] = 0;
  _splx(piVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1566 start=0xf0070ffc */

/* WARNING: Removing unreachable block (ram,0xf0071180) */
/* WARNING: Removing unreachable block (ram,0xf00710e0) */
/* WARNING: Removing unreachable block (ram,0xf0071054) */
/* WARNING: Removing unreachable block (ram,0xf0071028) */
/* WARNING: Removing unreachable block (ram,0xf00710a0) */
/* WARNING: Removing unreachable block (ram,0xf0071160) */
/* WARNING: Removing unreachable block (ram,0xf00711ac) */
/* WARNING: Removing unreachable block (ram,0xf0071010) */

undefined8 _thread_wakeup_prim(uint param_1,int param_2,int param_3)

{
  undefined *puVar1;
  uint uVar2;
  int *piVar3;
  undefined4 unaff_l0;
  int *piVar4;
  undefined4 unaff_l1;
  int *piVar5;
  undefined4 unaff_l3;
  int *piVar6;
  undefined4 unaff_l4;
  int *piVar7;
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
  uVar2 = param_1;
  if ((int)param_1 < 0) {
    uVar2 = ~param_1;
  }
  .rem(uVar2,0x3b);
  puVar1 = _wait_queue;
  piVar7 = (int *)(_wait_queue + uVar2 * 8);
  _splusclock();
  piVar5 = (int *)(_wait_lock + uVar2 * 4);
  do {
    do {
    } while (*piVar5 != 0);
    piVar4 = piVar5;
    _simple_lock_try();
  } while (piVar4 == (int *)0x0);
  piVar4 = (int *)*piVar7;
  if (piVar7 == piVar4) {
loc_F00711A8:
    *piVar5 = 0;
    _splx(puVar1);
    return CONCAT44(param_2,param_1);
  }
  uVar2 = piVar4[0xf];
  do {
    piVar6 = (int *)*piVar4;
    if (uVar2 == param_1) {
      do {
        do {
        } while (piVar4[8] != 0);
        piVar3 = piVar4 + 8;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      *(int *)(*piVar4 + 4) = piVar4[1];
      *(int *)piVar4[1] = *piVar4;
      piVar4[0xf] = 0;
      if (piVar4[0x53] == 0) {
        uVar2 = piVar4[0x13];
      }
      else {
        _reset_timeout(piVar4 + 0x46);
        uVar2 = piVar4[0x13];
      }
      switch(uVar2 & 0xf) {
      case :
      case :
      case :
        piVar4[0x13] = uVar2 & 0xfffffffe | 4;
        piVar4[0x11] = param_3;
        _thread_setrun(piVar4,1);
        break;
      case :
      case :
      case :
      case :
      case :
      case :
      case :
      :
        _panic(aThreadWakeup);
        break;
      case :
      case :
      case :
      case :
      case :
        piVar4[0x13] = uVar2 & 0xfffffffe;
        piVar4[0x11] = param_3;
      }
      piVar4[8] = 0;
      if (param_2 != 0) goto loc_F00711A8;
    }
    if (piVar7 == piVar6) goto loc_F00711A8;
    uVar2 = piVar6[0xf];
    piVar4 = piVar6;
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1567 start=0xf00711bc */

/* WARNING: Removing unreachable block (ram,0xf00711d0) */
/* WARNING: Removing unreachable block (ram,0xf00711c4) */

undefined8 _thread_sleep(undefined4 param_1,undefined4 *param_2,undefined4 param_3)

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
  _assert_wait(param_1,param_3);
  *param_2 = 0;
  _thread_block_with_continuation(0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1568 start=0xf00711e0 */

/* WARNING: Removing unreachable block (ram,0xf0071200) */
/* WARNING: Removing unreachable block (ram,0xf007121c) */
/* WARNING: Removing unreachable block (ram,0xf00711e4) */

undefined8 _thread_bind(int param_1,undefined4 param_2)

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
  iVar1 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar2 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  *(undefined4 *)(param_1 + 0x194) = param_2;
  *(undefined4 *)(param_1 + 0x20) = 0;
  _splx(iVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1569 start=0xf007122c */

/* WARNING: Removing unreachable block (ram,0xf0071314) */
/* WARNING: Removing unreachable block (ram,0xf00712ec) */
/* WARNING: Removing unreachable block (ram,0xf007134c) */
/* WARNING: Removing unreachable block (ram,0xf0071280) */
/* WARNING: Removing unreachable block (ram,0xf0071248) */

undefined8 _thread_select(int *param_1,undefined4 param_2)

{
  undefined8 *puVar1;
  int *piVar2;
  int iVar3;
  int *piVar4;
  int iVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar6;
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
  param_1[0x49] = 1;
  if (0 < param_1[0x42]) {
    piVar6 = param_1;
    _choose_thread(param_1);
    param_1[0x48] = _min_quantum;
    goto locret_F00713E0;
  }
  do {
    do {
    } while (DAT_f01350c0._0_4_ != 0);
    puVar1 = &DAT_f01350c0;
    _simple_lock_try();
    piVar6 = _active_threads;
  } while (puVar1 == (undefined8 *)0x0);
  if (unk_F01350C8 == 0) {
    if ((_active_threads[0x13] != 4) ||
       (((int *)_active_threads[0x65] != (int *)0x0 && ((int *)_active_threads[0x65] != param_1))))
    goto loc_F007134C;
    DAT_f01350c0._0_4_ = 0;
    piVar4 = _active_threads + 8;
    do {
      do {
      } while (*piVar4 != 0);
      piVar2 = piVar4;
      _simple_lock_try();
    } while (piVar2 == (int *)0x0);
    if (piVar6[0x1c] != _sched_tick) {
      _update_priority(piVar6);
    }
    piVar6[8] = 0;
    iVar5 = piVar6[0x18];
  }
  else {
    iVar5 = DAT_f01350c0._4_4_ * 8;
    piVar6 = *(int **)(_default_pset + iVar5);
    piVar4 = (int *)(_default_pset + iVar5);
    if (piVar4 == piVar6) {
      DAT_f01350c0._4_4_ = DAT_f01350c0._4_4_ + -1;
loc_F007134C:
      piVar6 = param_1;
      _choose_pset_thread(param_1,_default_pset);
    }
    else {
      if (piVar6 == piVar4) {
        piVar6 = (int *)0x0;
      }
      else {
        *(int **)(*piVar6 + 4) = piVar4;
        *(int *)(_default_pset + iVar5) = *piVar6;
      }
      piVar6[2] = 0;
      unk_F01350C8 = unk_F01350C8 + -1;
      if ((0 < unk_F01350C8) && ((DAT_f0135128 & 2) != 0)) {
        piVar2 = (int *)*piVar4;
        while (piVar4 == piVar2) {
          piVar4 = piVar4 + -2;
          DAT_f01350c0._4_4_ = DAT_f01350c0._4_4_ + -1;
          piVar2 = (int *)*piVar4;
        }
      }
      DAT_f01350c0._0_4_ = 0;
    }
    iVar5 = piVar6[0x18];
  }
  iVar3 = dword_F013512C;
  if (iVar5 == 2) {
    iVar3 = piVar6[0x17];
  }
  param_1[0x48] = iVar3;
locret_F00713E0:
  return CONCAT44(param_2,piVar6);
}
/* GHIDRADEC_FUNCTION index=1570 start=0xf00713e8 */

/* WARNING: Removing unreachable block (ram,0xf0071438) */
/* WARNING: Removing unreachable block (ram,0xf00716f4) */
/* WARNING: Removing unreachable block (ram,0xf00716cc) */
/* WARNING: Removing unreachable block (ram,0xf007163c) */
/* WARNING: Removing unreachable block (ram,0xf00715d4) */
/* WARNING: Removing unreachable block (ram,0xf00715f4) */
/* WARNING: Removing unreachable block (ram,0xf00714e0) */
/* WARNING: Removing unreachable block (ram,0xf0071668) */
/* WARNING: Removing unreachable block (ram,0xf00714d4) */
/* WARNING: Removing unreachable block (ram,0xf00714fc) */
/* WARNING: Removing unreachable block (ram,0xf007161c) */
/* WARNING: Removing unreachable block (ram,0xf0071634) */
/* WARNING: Removing unreachable block (ram,0xf007167c) */
/* WARNING: Removing unreachable block (ram,0xf00716ec) */
/* WARNING: Removing unreachable block (ram,0xf007140c) */
/* WARNING: Removing unreachable block (ram,0xf0071440) */
/* WARNING: Removing unreachable block (ram,0xf007145c) */

undefined8 _thread_invoke(int param_1,int param_2,int param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_l0;
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
  if (param_1 == param_3) {
    do {
      do {
      } while (*(int *)(param_1 + 0x20) != 0);
      piVar1 = (int *)(param_1 + 0x20);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    *(undefined4 *)(param_3 + 0x20) = 0;
    *(uint *)(param_3 + 0x4c) = *(uint *)(param_3 + 0x4c) & 0xfffffff7;
    if (param_2 != 0) {
      uVar5 = 1;
      _spl0();
      _call_continuation(param_2);
      goto locret_F0071700;
    }
  }
  else {
    do {
      do {
      } while (*(int *)(param_3 + 0x20) != 0);
      piVar1 = (int *)(param_3 + 0x20);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (*(int *)(param_1 + 0x30) == _active_stacks) {
      uVar2 = *(uint *)(param_3 + 0x4c);
loc_F0071650:
      if ((uVar2 & 0x100) == 0) {
        uVar2 = *(uint *)(param_3 + 0x4c);
      }
      else {
        if (((uVar2 & 0x200) != 0) ||
           (iVar3 = param_3, _stack_alloc_try(param_3,_thread_continue), iVar3 == 0)) {
loc_F007167C:
          _thread_swapin(param_3);
          *(undefined4 *)(param_3 + 0x20) = 0;
          uVar5 = 0;
          _c_thread_invoke_misses = _c_thread_invoke_misses + 1;
          goto locret_F0071700;
        }
        uVar2 = *(uint *)(param_3 + 0x4c);
      }
    }
    else {
      uVar2 = *(uint *)(param_3 + 0x4c);
      if (param_2 == 0) goto loc_F0071650;
      uVar4 = uVar2 & 0x300;
      if (uVar4 == 0x100) {
        *(uint *)(param_3 + 0x4c) = uVar2 & 0xfffffef7;
        *(undefined4 *)(param_3 + 0x20) = 0;
        _need_ast = _need_ast & 0xfffffffc | *(uint *)(param_3 + 0x18c);
        _switch_unix_context(param_3);
        _stack_handoff(param_1,param_3);
        do {
          do {
          } while (*(int *)(param_1 + 0x20) != 0);
          piVar1 = (int *)(param_1 + 0x20);
          _simple_lock_try();
        } while (piVar1 == (int *)0x0);
        iVar3 = *(int *)(param_1 + 0x4c);
        *(int *)(param_1 + 0x34) = param_2;
        if (iVar3 == 0xc) {
loc_F00715E8:
          *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100;
          _thread_setrun(param_1,0);
loc_F0071624:
          *(undefined4 *)(param_1 + 0x20) = 0;
        }
        else {
          if (0xc < iVar3) {
            if (iVar3 != 0xf) {
              if (iVar3 < 0x10) {
                if (iVar3 == 0xd) goto loc_F0071600;
                if (iVar3 == 0xe) goto loc_F00715E8;
              }
              else {
                if (iVar3 == 0x16) {
                  uVar2 = *(uint *)(param_1 + 0x4c);
                  goto loc_F00715AC;
                }
                if (iVar3 == 0x84) {
                  *(undefined4 *)(param_1 + 0x4c) = 0x184;
                  goto loc_F0071624;
                }
              }
              goto loc_F007161C;
            }
loc_F0071600:
            uVar2 = *(uint *)(param_1 + 0x4c);
loc_F0071604:
            *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb | 0x100;
            goto loc_F0071624;
          }
          if (iVar3 == 5) {
            uVar2 = *(uint *)(param_1 + 0x4c);
            goto loc_F0071604;
          }
          if (iVar3 < 6) {
            if (iVar3 == 4) goto loc_F00715E8;
loc_F007161C:
            _panic(aThreadInvoke);
            goto loc_F0071624;
          }
          if (7 < iVar3) goto loc_F007161C;
          uVar2 = *(uint *)(param_1 + 0x4c);
loc_F00715AC:
          *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb | 0x100;
          if (*(int *)(param_1 + 0x48) == 0) goto loc_F0071624;
          *(undefined4 *)(param_1 + 0x48) = 0;
          *(undefined4 *)(param_1 + 0x20) = 0;
          _thread_wakeup_prim(param_1 + 0x48,0,0);
        }
        _c_thread_invoke_hits = _c_thread_invoke_hits + 1;
        _spl0();
        _call_continuation(*(undefined4 *)(param_3 + 0x34));
        uVar5 = 1;
        goto locret_F0071700;
      }
      if ((0x100 < uVar4) && (uVar4 == 0x200)) goto loc_F007167C;
    }
    *(undefined4 *)(param_3 + 0x20) = 0;
    *(uint *)(param_3 + 0x4c) = uVar2 & 0xfffffef7;
    _need_ast = _need_ast & 0xfffffffc | *(uint *)(param_3 + 0x18c);
    _switch_unix_context(param_3);
    _c_thread_invoke_csw = _c_thread_invoke_csw + 1;
    _switch_context(param_1,param_2,param_3);
    _thread_dispatch();
  }
  uVar5 = 1;
locret_F0071700:
  return CONCAT44(param_2,uVar5);
}
/* GHIDRADEC_FUNCTION index=1571 start=0xf0071708 */

/* WARNING: Removing unreachable block (ram,0xf0071728) */
/* WARNING: Removing unreachable block (ram,0xf0071720) */

undefined8 _thread_continue(int param_1,undefined4 param_2)

{
  undefined4 unaff_l0;
  code *pcVar1;
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
  pcVar1 = *(code **)(_active_threads + 0x34);
  if (param_1 != 0) {
    _thread_dispatch(param_1);
  }
  _spl0();
  (*pcVar1)();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1572 start=0xf0071740 */

/* WARNING: Removing unreachable block (ram,0xf0071780) */
/* WARNING: Removing unreachable block (ram,0xf0071770) */
/* WARNING: Removing unreachable block (ram,0xf0071794) */
/* WARNING: Removing unreachable block (ram,0xf0071750) */

undefined8 _thread_block_with_continuation(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
  undefined4 uVar4;
  int iVar5;
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
  
  uVar2 = _processor_ptr;
  iVar1 = _active_threads;
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
  puVar3 = DAT_f0134800;
  _splusclock();
  _need_ast = _need_ast & 0xfffffffb;
  do {
    uVar4 = uVar2;
    _thread_select(uVar2);
    iVar5 = iVar1;
    _thread_invoke(iVar1,param_1,uVar4);
  } while (iVar5 == 0);
  _splx(puVar3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1573 start=0xf00717a4 */

/* WARNING: Removing unreachable block (ram,0xf00717ec) */
/* WARNING: Removing unreachable block (ram,0xf00717c8) */
/* WARNING: Removing unreachable block (ram,0xf00717dc) */
/* WARNING: Removing unreachable block (ram,0xf00717b4) */

undefined8 _thread_run(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined *puVar3;
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
  
  uVar2 = _processor_ptr;
  iVar1 = _active_threads;
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
  puVar3 = DAT_f0134800;
  _splusclock();
  while (iVar4 = iVar1, _thread_invoke(iVar1,param_1,param_2), iVar4 == 0) {
    param_2 = uVar2;
    _thread_select();
  }
  _splx(puVar3);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1574 start=0xf00717fc */

/* WARNING: Removing unreachable block (ram,0xf0071930) */
/* WARNING: Removing unreachable block (ram,0xf0071840) */
/* WARNING: Removing unreachable block (ram,0xf0071908) */
/* WARNING: Removing unreachable block (ram,0xf0071914) */
/* WARNING: Removing unreachable block (ram,0xf0071814) */

undefined8 _thread_dispatch(int param_1,undefined4 param_2)

{
  int *piVar1;
  uint uVar2;
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
  do {
    do {
    } while (*(int *)(param_1 + 0x20) != 0);
    piVar1 = (int *)(param_1 + 0x20);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  if (*(int *)(param_1 + 0x34) != 0) {
    *(uint *)(param_1 + 0x4c) = *(uint *)(param_1 + 0x4c) | 0x100;
    _stack_free(param_1);
  }
  uVar2 = *(uint *)(param_1 + 0x4c) & 0xfffffcff;
  if (uVar2 == 0xc) {
loc_F0071914:
    _thread_setrun(param_1,0);
  }
  else {
    if ((int)uVar2 < 0xd) {
      if (uVar2 != 5) {
        if ((int)uVar2 < 6) {
          if (uVar2 == 4) goto loc_F0071914;
        }
        else if ((int)uVar2 < 8) {
          uVar2 = *(uint *)(param_1 + 0x4c);
loc_F00718E4:
          *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb;
          if (*(int *)(param_1 + 0x48) != 0) {
            *(undefined4 *)(param_1 + 0x48) = 0;
            *(undefined4 *)(param_1 + 0x20) = 0;
            _thread_wakeup_prim(param_1 + 0x48,0,0);
            goto locret_F007193C;
          }
          goto loc_F0071938;
        }
        goto loc_F0071930;
      }
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    else {
      if (uVar2 != 0xf) {
        if ((int)uVar2 < 0x10) {
          if (uVar2 == 0xd) goto loc_F0071920;
          if (uVar2 == 0xe) goto loc_F0071914;
        }
        else {
          if (uVar2 == 0x16) {
            uVar2 = *(uint *)(param_1 + 0x4c);
            goto loc_F00718E4;
          }
          if (uVar2 == 0x84) goto loc_F0071938;
        }
loc_F0071930:
        _panic(aThreadDispatch);
        goto loc_F0071938;
      }
loc_F0071920:
      uVar2 = *(uint *)(param_1 + 0x4c);
    }
    *(uint *)(param_1 + 0x4c) = uVar2 & 0xfffffffb;
  }
loc_F0071938:
  *(undefined4 *)(param_1 + 0x20) = 0;
locret_F007193C:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1575 start=0xf0071944 */

/* WARNING: Removing unreachable block (ram,0xf0071990) */

undefined8 _compute_priority(int param_1,undefined4 param_2)

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
  if (*(int *)(param_1 + 0x60) == 2) {
    iVar1 = *(int *)(param_1 + 0x50);
  }
  else {
    iVar1 = *(int *)(param_1 + 0x50) - (*(uint *)(param_1 + 0x6c) >> 0x19);
    if (iVar1 < 0) {
      iVar1 = 0;
    }
    if (-1 < *(int *)(param_1 + 100)) {
      *(int *)(param_1 + 100) = iVar1;
      goto locret_F0071998;
    }
  }
  _set_pri(param_1,iVar1,param_2);
locret_F0071998:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1576 start=0xf00719a0 */

undefined8 _compute_my_priority(int param_1,undefined4 param_2)

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
  iVar1 = *(int *)(param_1 + 0x50) - (*(uint *)(param_1 + 0x6c) >> 0x19);
  if (iVar1 < 0) {
    iVar1 = 0;
  }
  *(int *)(param_1 + 0x58) = iVar1;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1577 start=0xf00719c8 */

/* WARNING: Removing unreachable block (ram,0xf00719f0) */
/* WARNING: Removing unreachable block (ram,0xf0071a38) */
/* WARNING: Removing unreachable block (ram,0xf00719e8) */

undefined8 _recompute_priorities(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
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
  puVar1 = _recompute_priorities_timer;
  _sched_tick = _sched_tick + 1;
  _set_timeout(_recompute_priorities_timer,_hz);
  _sched_usec_elapsed();
  _sched_usec = _sched_usec * 5 + (int)puVar1 * 3;
  if (_sched_usec < 0) {
    _sched_usec = _sched_usec + 7;
  }
  _sched_usec = _sched_usec >> 3;
  if (_sched_thread_id != 0) {
    _clear_wait(_sched_thread_id,0,0);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1578 start=0xf0071a48 */

/* WARNING: Removing unreachable block (ram,0xf0071aac) */
/* WARNING: Removing unreachable block (ram,0xf0071ae0) */
/* WARNING: Removing unreachable block (ram,0xf0071a78) */

undefined8 _update_priority(int param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  byte bVar3;
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
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar2 = _sched_tick;
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
  iVar1 = *(int *)(param_1 + 0x70);
  *(int *)(param_1 + 0x70) = _sched_tick;
  uVar4 = iVar2 - iVar1;
  if (*(int *)(param_1 + 0x10c) == *(int *)(param_1 + 0xf8)) {
    iVar2 = *(int *)(param_1 + 0xf0) - *(int *)(param_1 + 0x108);
    *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0xf0);
  }
  else {
    iVar2 = param_1 + 0xf0;
    _timer_delta(iVar2,param_1 + 0x108);
  }
  if (*(int *)(param_1 + 0x104) == *(int *)(param_1 + 0xe8)) {
    iVar1 = *(int *)(param_1 + 0xe0) - *(int *)(param_1 + 0x100);
    *(int *)(param_1 + 0x100) = *(int *)(param_1 + 0xe0);
  }
  else {
    iVar1 = param_1 + 0xe0;
    _timer_delta(iVar1,param_1 + 0x100);
  }
  iVar2 = iVar2 + iVar1;
  *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0x110) + iVar2;
  .umul(iVar2,*(undefined4 *)(*(int *)(param_1 + 400) + 0x178));
  *(int *)(param_1 + 0x114) = *(int *)(param_1 + 0x114) + iVar2;
  if (uVar4 < 0x1f) {
    iVar2 = uVar4 * 8;
    *(int *)(param_1 + 0x68) = *(int *)(param_1 + 0x68) + *(int *)(param_1 + 0x110);
    *(int *)(param_1 + 0x6c) = *(int *)(param_1 + 0x6c) + *(int *)(param_1 + 0x114);
    uVar4 = *(uint *)(param_1 + 0x68);
    bVar3 = (byte)*(int *)(_wait_shift + iVar2 + 4);
    if (*(int *)(_wait_shift + iVar2 + 4) < 1) {
      *(uint *)(param_1 + 0x68) =
           (uVar4 >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) -
           (uVar4 >> (-bVar3 & 0x1f));
      *(uint *)(param_1 + 0x6c) =
           (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) -
           (*(uint *)(param_1 + 0x6c) >> (-(char)*(undefined4 *)(_wait_shift + iVar2 + 4) & 0x1fU));
    }
    else {
      *(uint *)(param_1 + 0x68) =
           (uVar4 >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) +
           (uVar4 >> (bVar3 & 0x1f));
      *(uint *)(param_1 + 0x6c) =
           (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(_wait_shift + iVar2) & 0x1f)) +
           (*(uint *)(param_1 + 0x6c) >> ((byte)*(undefined4 *)(_wait_shift + iVar2 + 4) & 0x1f));
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x68) = 0;
    *(undefined4 *)(param_1 + 0x6c) = 0;
  }
  *(undefined4 *)(param_1 + 0x110) = 0;
  *(undefined4 *)(param_1 + 0x114) = 0;
  if ((*(int *)(param_1 + 0x60) != 2) && (*(int *)(param_1 + 100) < 0)) {
    iVar2 = *(int *)(param_1 + 0x50) - (*(uint *)(param_1 + 0x6c) >> 0x19);
    if (iVar2 < 0) {
      iVar2 = 0;
    }
    *(int *)(param_1 + 0x58) = iVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1579 start=0xf0071bfc */

/* WARNING: Removing unreachable block (ram,0xf0071c34) */
/* WARNING: Removing unreachable block (ram,0xf0071c14) */

undefined8 _run_queue_enqueue(int param_1,int *param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
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
  uVar4 = param_2[0x16];
  if (0x1f < uVar4) {
    _printf(aRunQueueEnqueu,uVar4);
    uVar4 = 0x1f;
  }
  do {
    do {
    } while (*(int *)(param_1 + 0x100) != 0);
    piVar1 = (int *)(param_1 + 0x100);
    _simple_lock_try();
  } while (piVar1 == (int *)0x0);
  iVar2 = uVar4 * 8 + param_1;
  *param_2 = iVar2;
  puVar3 = *(undefined4 **)(iVar2 + 4);
  param_2[1] = (int)puVar3;
  *puVar3 = param_2;
  *(int **)(iVar2 + 4) = param_2;
  if (*(uint *)(param_1 + 0x104) < uVar4) {
    *(uint *)(param_1 + 0x104) = uVar4;
  }
  else {
    iVar2 = *(int *)(param_1 + 0x108);
    if (iVar2 != 0) goto loc_F0071C8C;
    *(uint *)(param_1 + 0x104) = uVar4;
  }
  iVar2 = *(int *)(param_1 + 0x108);
loc_F0071C8C:
  *(int *)(param_1 + 0x108) = iVar2 + 1;
  param_2[2] = param_1;
  *(undefined4 *)(param_1 + 0x100) = 0;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1580 start=0xf0071ca0 */

/* WARNING: Removing unreachable block (ram,0xf0071d6c) */
/* WARNING: Removing unreachable block (ram,0xf0071cbc) */

undefined8 _thread_setrun(int param_1,int param_2)

{
  undefined4 uVar1;
  undefined *puVar2;
  undefined *puVar3;
  undefined *puVar4;
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
  if (*(int *)(param_1 + 0x70) != _sched_tick) {
    _update_priority(param_1);
  }
  uVar1 = unk_F01350CC._0_4_;
  if ((int)DAT_f01350d4._0_4_ < 1) {
    if (*(int *)(param_1 + 0x194) == 0) {
      puVar4 = _default_pset;
    }
    else {
      _need_ast = _need_ast | 4;
      puVar4 = _master_processor;
    }
    _run_queue_enqueue(puVar4,param_1);
    if ((param_2 != 0) && (*(int *)(_active_threads + 0x58) < *(int *)(param_1 + 0x58))) {
      *(undefined4 *)(_processor_ptr + 0x124) = 0;
      _need_ast = _need_ast | 4;
    }
  }
  else {
    puVar4 = *(undefined **)(unk_F01350CC._0_4_ + 0x10c);
    puVar3 = *(undefined **)(unk_F01350CC._0_4_ + 0x110);
    puVar2 = puVar3;
    if (puVar4 != unk_F01350CC) {
      *(undefined **)(puVar4 + 0x110) = puVar3;
      puVar2 = (undefined *)unk_F01350CC._4_4_;
    }
    unk_F01350CC._4_4_ = puVar2;
    if (puVar3 != unk_F01350CC) {
      *(undefined **)(puVar3 + 0x10c) = puVar4;
      puVar4 = (undefined *)unk_F01350CC._0_4_;
    }
    unk_F01350CC._0_4_ = puVar4;
    DAT_f01350d4._0_4_ = DAT_f01350d4._0_4_ + -1;
    *(int *)(uVar1 + 0x118) = param_1;
    *(undefined4 *)(uVar1 + 0x114) = 3;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1581 start=0xf0071dbc */

/* WARNING: Removing unreachable block (ram,0xf0071df0) */
/* WARNING: Removing unreachable block (ram,0xf0071de4) */
/* WARNING: Removing unreachable block (ram,0xf0071dc0) */

undefined8 _set_pri(int param_1,undefined4 param_2,int param_3)

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
  iVar1 = param_1;
  _rem_runq();
  *(undefined4 *)(param_1 + 0x58) = param_2;
  if (iVar1 != 0) {
    if (param_3 == 0) {
      _run_queue_enqueue();
    }
    else {
      _thread_setrun(param_1,1);
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1582 start=0xf0071e00 */

/* WARNING: Removing unreachable block (ram,0xf0071e28) */

undefined8 _rem_runq(int *param_1,undefined4 param_2)

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
  int iVar2;
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
  iVar2 = param_1[2];
  if (iVar2 != 0) {
    do {
      do {
      } while (*(int *)(iVar2 + 0x100) != 0);
      piVar1 = (int *)(iVar2 + 0x100);
      _simple_lock_try();
    } while (piVar1 == (int *)0x0);
    if (iVar2 == param_1[2]) {
      *(int *)(*param_1 + 4) = param_1[1];
      *(int *)param_1[1] = *param_1;
      *(int *)(iVar2 + 0x108) = *(int *)(iVar2 + 0x108) + -1;
      param_1[2] = 0;
      *(undefined4 *)(iVar2 + 0x100) = 0;
    }
    else {
      *(undefined4 *)(iVar2 + 0x100) = 0;
      iVar2 = 0;
    }
  }
  return CONCAT44(param_2,iVar2);
}
/* GHIDRADEC_FUNCTION index=1583 start=0xf0071e8c */

/* WARNING: Removing unreachable block (ram,0xf0071f60) */
/* WARNING: Removing unreachable block (ram,0xf0071f3c) */
/* WARNING: Removing unreachable block (ram,0xf0071f74) */
/* WARNING: Removing unreachable block (ram,0xf0071eac) */

undefined8 _choose_thread(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 unaff_l0;
  int *piVar2;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
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
    do {
    } while (param_1[0x40] != 0);
    piVar2 = param_1 + 0x40;
    _simple_lock_try();
  } while (piVar2 == (int *)0x0);
  if (0 < param_1[0x42]) {
    iVar1 = param_1[0x41];
    piVar2 = param_1 + iVar1 * 2;
    for (; -1 < iVar1; iVar1 = iVar1 + -1) {
      piVar3 = (int *)*piVar2;
      if (piVar2 != piVar3) {
        if (piVar3 == piVar2) {
          piVar3 = (int *)0x0;
        }
        else {
          *(int **)(*piVar3 + 4) = piVar2;
          *piVar2 = *piVar3;
        }
        piVar3[2] = 0;
        param_1[0x41] = iVar1;
        param_1[0x40] = 0;
        param_1[0x42] = param_1[0x42] + -1;
        param_1 = piVar3;
        goto locret_F0071F80;
      }
      piVar2 = piVar2 + -2;
    }
    _panic(aChooseThread);
  }
  param_1[0x40] = 0;
  iVar1 = param_1[0x4b];
  piVar2 = (int *)(iVar1 + 0x100);
  do {
    do {
    } while (*piVar2 != 0);
    piVar3 = piVar2;
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  _choose_pset_thread(param_1,iVar1);
locret_F0071F80:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1584 start=0xf0071f88 */

/* WARNING: Removing unreachable block (ram,0xf0072068) */
/* WARNING: Removing unreachable block (ram,0xf0072048) */

undefined8 _choose_pset_thread(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar4;
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
  if (0 < *(int *)(param_2 + 0x108)) {
    iVar2 = *(int *)(param_2 + 0x104);
    piVar3 = (int *)(param_2 + iVar2 * 8);
    if (-1 < iVar2) {
      while( true ) {
        piVar4 = (int *)*piVar3;
        if (piVar3 != piVar4) break;
        iVar2 = iVar2 + -1;
        piVar3 = piVar3 + -2;
        if (iVar2 < 0) goto loc_F0072044;
      }
      if (piVar4 == piVar3) {
        piVar4 = (int *)0x0;
      }
      else {
        *(int **)(*piVar4 + 4) = piVar3;
        *piVar3 = *piVar4;
      }
      piVar4[2] = 0;
      iVar1 = *(int *)(param_2 + 0x108) + -1;
      *(int *)(param_2 + 0x108) = iVar1;
      if (iVar1 < 1) goto loc_F007202C;
      if ((*(uint *)(param_2 + 0x168) & 2) == 0) {
        *(int *)(param_2 + 0x104) = iVar2;
      }
      else if (piVar3 == (int *)*piVar3) {
        do {
          piVar3 = piVar3 + -2;
          iVar2 = iVar2 + -1;
        } while (piVar3 == (int *)*piVar3);
loc_F007202C:
        *(int *)(param_2 + 0x104) = iVar2;
      }
      else {
        *(int *)(param_2 + 0x104) = iVar2;
      }
      *(undefined4 *)(param_2 + 0x100) = 0;
      goto locret_F0072108;
    }
loc_F0072044:
    _panic(aChoosePsetThre);
  }
  *(undefined4 *)(param_2 + 0x100) = 0;
  do {
    do {
    } while (*(int *)(param_2 + 0x118) != 0);
    piVar3 = (int *)(param_2 + 0x118);
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  if (*(int *)(param_1 + 0x114) == 1) {
    bVar5 = param_1 == _master_processor;
    *(undefined4 *)(param_1 + 0x114) = 2;
    if (bVar5) {
      iVar2 = *(int *)(param_2 + 0x110);
      if (param_2 + 0x10c == iVar2) {
        *(int *)(param_2 + 0x10c) = param_1;
      }
      else {
        *(int *)(iVar2 + 0x10c) = param_1;
      }
      *(int *)(param_1 + 0x110) = iVar2;
      *(int *)(param_1 + 0x10c) = param_2 + 0x10c;
      *(int *)(param_2 + 0x110) = param_1;
    }
    else {
      iVar2 = *(int *)(param_2 + 0x10c);
      if (param_2 + 0x10c == iVar2) {
        *(int *)(param_2 + 0x110) = param_1;
      }
      else {
        *(int *)(iVar2 + 0x110) = param_1;
      }
      *(int *)(param_1 + 0x10c) = iVar2;
      *(int *)(param_1 + 0x110) = param_2 + 0x10c;
      *(int *)(param_2 + 0x10c) = param_1;
    }
    *(int *)(param_2 + 0x114) = *(int *)(param_2 + 0x114) + 1;
  }
  *(undefined4 *)(param_2 + 0x118) = 0;
  piVar4 = *(int **)(param_1 + 0x11c);
locret_F0072108:
  return CONCAT44(param_2,piVar4);
}
/* GHIDRADEC_FUNCTION index=1585 start=0xf0072110 */

/* WARNING: Removing unreachable block (ram,0xf007221c) */
/* WARNING: Removing unreachable block (ram,0xf0072248) */
/* WARNING: Removing unreachable block (ram,0xf0072328) */
/* WARNING: Removing unreachable block (ram,0xf00721c4) */
/* WARNING: Removing unreachable block (ram,0xf0072184) */
/* WARNING: Removing unreachable block (ram,0xf0072170) */
/* WARNING: Removing unreachable block (ram,0xf00721bc) */
/* WARNING: Removing unreachable block (ram,0xf00722fc) */
/* WARNING: Removing unreachable block (ram,0xf0072334) */
/* WARNING: Removing unreachable block (ram,0xf0072308) */
/* WARNING: Removing unreachable block (ram,0xf007233c) */
/* WARNING: Removing unreachable block (ram,0xf007213c) */

void _idle_thread_continue(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int *piVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  int *piVar8;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  int *piVar9;
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
  
  iVar1 = _processor_ptr;
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
  piVar8 = (int *)(_processor_ptr + 0x118);
  piVar9 = (int *)(_processor_ptr + 0x108);
  do {
    _PMSetCpuState(0);
    iVar2 = *piVar8;
    while (((iVar2 == 0 && (unk_F01350C8 == 0)) && (*piVar9 == 0))) {
      if ((_need_ast & 0xfffffff8) != 0) {
        _splusclock();
        _need_ast = _need_ast & 0xfffffff8;
        _spl0();
      }
      iVar2 = *piVar8;
    }
    uVar3 = 1;
    _PMSetCpuState(1);
    _splusclock();
    iVar2 = *(int *)(iVar1 + 0x114);
    while (iVar2 != 3) {
      if (iVar2 != 2) {
        if (iVar2 == 4 || iVar2 == 5) {
          iVar2 = *piVar8;
          if (iVar2 != 0) {
            *piVar8 = 0;
            _thread_setrun(iVar2,0);
          }
loc_F0072308:
          _thread_block_with_continuation(_idle_thread_continue);
        }
        else {
          _printf(0xf0110588,*(undefined4 *)(_processor_ptr + 0x114),0);
          _panic(aIdleThread);
        }
        goto loc_F007233C;
      }
      iVar2 = *(int *)(iVar1 + 300);
      do {
        do {
        } while (*(int *)(iVar2 + 0x118) != 0);
        piVar5 = (int *)(iVar2 + 0x118);
        _simple_lock_try();
      } while (piVar5 == (int *)0x0);
      if (*(int *)(iVar1 + 0x114) == 2) {
        _no_dispatch_count._0_4_ = _no_dispatch_count._0_4_ + 1;
        *(int *)(iVar2 + 0x114) = *(int *)(iVar2 + 0x114) + -1;
        iVar7 = *(int *)(iVar1 + 0x10c);
        iVar6 = *(int *)(iVar1 + 0x110);
        if (iVar2 + 0x10c == iVar7) {
          *(int *)(iVar2 + 0x110) = iVar6;
        }
        else {
          *(int *)(iVar7 + 0x110) = iVar6;
        }
        if (iVar2 + 0x10c == iVar6) {
          *(int *)(iVar2 + 0x10c) = iVar7;
        }
        else {
          *(int *)(iVar6 + 0x10c) = iVar7;
        }
        *(undefined4 *)(iVar1 + 0x114) = 1;
        *(undefined4 *)(iVar2 + 0x118) = 0;
        goto loc_F0072308;
      }
      *(undefined4 *)(iVar2 + 0x118) = 0;
      iVar2 = *(int *)(iVar1 + 0x114);
    }
    iVar2 = *piVar8;
    *piVar8 = 0;
    *(undefined4 *)(iVar1 + 0x114) = 1;
    uVar4 = dword_F013512C;
    if (*(int *)(iVar2 + 0x60) == 2) {
      uVar4 = *(undefined4 *)(iVar2 + 0x5c);
    }
    *(undefined4 *)(iVar1 + 0x120) = uVar4;
    *(undefined4 *)(iVar1 + 0x124) = 1;
    _thread_run(_idle_thread_continue);
loc_F007233C:
    _splx(uVar3);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1586 start=0xf0072350 */

/* WARNING: Removing unreachable block (ram,0xf00723c4) */
/* WARNING: Removing unreachable block (ram,0xf0072388) */
/* WARNING: Removing unreachable block (ram,0xf0072364) */
/* WARNING: Removing unreachable block (ram,0xf00723b8) */
/* WARNING: Removing unreachable block (ram,0xf00723cc) */
/* WARNING: Removing unreachable block (ram,0xf007235c) */

undefined8 _idle_thread(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
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
  
  iVar1 = _active_threads;
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
  iVar2 = _active_threads;
  _stack_privilege(_active_threads);
  _splusclock();
  *(undefined4 *)(iVar1 + 0x50) = 0;
  *(undefined4 *)(iVar1 + 0x58) = 0;
  do {
    do {
    } while (*(int *)(iVar1 + 0x20) != 0);
    piVar3 = (int *)(iVar1 + 0x20);
    _simple_lock_try();
  } while (piVar3 == (int *)0x0);
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(uint *)(iVar1 + 0x4c) = *(uint *)(iVar1 + 0x4c) | 0x80;
  *(int *)(_processor_ptr + 0x11c) = iVar1;
  _splx(iVar2);
  _thread_block_with_continuation(_idle_thread_continue);
  _idle_thread_continue();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1587 start=0xf00723dc */

/* WARNING: Removing unreachable block (ram,0xf007240c) */
/* WARNING: Removing unreachable block (ram,0xf0072400) */
/* WARNING: Removing unreachable block (ram,0xf0072414) */
/* WARNING: Removing unreachable block (ram,0xf00723e8) */

void _sched_thread_continue(void)

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
  do {
    _compute_mach_factor();
    if ((_sched_tick & 1) != 0) {
      _do_thread_scan(0);
    }
    _assert_wait(0,0);
    _thread_block_with_continuation(_sched_thread_continue);
  } while( true );
}
/* GHIDRADEC_FUNCTION index=1588 start=0xf0072428 */

/* WARNING: Removing unreachable block (ram,0xf007244c) */
/* WARNING: Removing unreachable block (ram,0xf0072454) */
/* WARNING: Removing unreachable block (ram,0xf0072440) */

undefined8 _sched_thread(undefined4 param_1,undefined4 param_2)

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
  _sched_thread_id = _active_threads;
  _assert_wait(0,0);
  _thread_block_with_continuation(_sched_thread_continue);
  _sched_thread_continue();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1589 start=0xf0072464 */

/* WARNING: Removing unreachable block (ram,0xf0072564) */
/* WARNING: Removing unreachable block (ram,0xf0072484) */
/* WARNING: Removing unreachable block (ram,0xf007250c) */
/* WARNING: Removing unreachable block (ram,0xf007258c) */
/* WARNING: Removing unreachable block (ram,0xf0072468) */

undefined8 _do_runq_scan(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 unaff_l0;
  int *piVar5;
  undefined4 unaff_l1;
  int *piVar6;
  int iVar7;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar8;
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
  iVar4 = param_1;
  _splusclock();
  do {
    do {
    } while (*(int *)(param_1 + 0x100) != 0);
    piVar5 = (int *)(param_1 + 0x100);
    _simple_lock_try();
  } while (piVar5 == (int *)0x0);
  iVar7 = *(int *)(param_1 + 0x108);
  if (0 < iVar7) {
    piVar5 = (int *)(param_1 + *(int *)(param_1 + 0x104) * 8);
    do {
      piVar1 = (int *)*piVar5;
      iVar2 = _stuck_count;
      while (_stuck_count = iVar2, piVar5 != piVar1) {
        piVar6 = (int *)*piVar1;
        if (((piVar1[0x13] & 0xfU) == 4) && (1 < (uint)(_sched_tick - piVar1[0x1c]))) {
          if (iVar2 == 0x80) {
            *(undefined4 *)(param_1 + 0x100) = 0;
            _splx(iVar4);
            uVar8 = 1;
            goto locret_F0072598;
          }
          piVar6[1] = piVar1[1];
          iVar3 = _do_thread_scan_debug;
          _stuck_count = iVar2 + 1;
          *(int *)piVar1[1] = *piVar1;
          *(int *)(param_1 + 0x108) = *(int *)(param_1 + 0x108) + -1;
          piVar1[2] = 0;
          *(int **)(_stuck_threads + iVar2 * 4) = piVar1;
          if (iVar3 != 0) {
            _printf(aDoRunqScanAddi,piVar1);
          }
        }
        iVar7 = iVar7 + -1;
        piVar1 = piVar6;
        iVar2 = _stuck_count;
      }
      piVar5 = piVar5 + -2;
    } while (0 < iVar7);
  }
  *(undefined4 *)(param_1 + 0x100) = 0;
  _splx(iVar4);
  uVar8 = 0;
locret_F0072598:
  return CONCAT44(param_2,uVar8);
}
/* GHIDRADEC_FUNCTION index=1590 start=0xf00725a0 */

/* WARNING: Removing unreachable block (ram,0xf0072650) */
/* WARNING: Removing unreachable block (ram,0xf007261c) */
/* WARNING: Removing unreachable block (ram,0xf00725cc) */
/* WARNING: Removing unreachable block (ram,0xf00725fc) */
/* WARNING: Removing unreachable block (ram,0xf0072644) */
/* WARNING: Removing unreachable block (ram,0xf007265c) */
/* WARNING: Removing unreachable block (ram,0xf00725b4) */

undefined8 _do_thread_scan(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar4;
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
  do {
    puVar1 = _default_pset;
    _do_runq_scan();
    if (puVar1 == (undefined *)0x0) {
      puVar1 = _master_processor;
      _do_runq_scan();
    }
    while (0 < _stuck_count) {
      iVar2 = _stuck_count + -1;
      iVar4 = *(int *)(_stuck_threads + iVar2 * 4);
      _stuck_count = iVar2;
      *(undefined4 *)(_stuck_threads + iVar2 * 4) = 0;
      _splusclock();
      do {
        do {
        } while (*(int *)(iVar4 + 0x20) != 0);
        piVar3 = (int *)(iVar4 + 0x20);
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      if ((*(uint *)(iVar4 + 0x4c) & 0xf) == 4) {
        _update_priority(iVar4);
        _thread_setrun(iVar4,1);
      }
      *(undefined4 *)(iVar4 + 0x20) = 0;
      _splx(iVar2);
    }
  } while (puVar1 != (undefined *)0x0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1591 start=0xf007268c */

/* WARNING: Removing unreachable block (ram,0xf0072698) */

undefined8 _thread_wakeup(undefined4 param_1,undefined4 param_2)

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
  _thread_wakeup_prim(param_1,0,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1592 start=0xf00726a8 */

undefined8 _thread_wait_result(undefined4 param_1,undefined4 param_2)

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
  return CONCAT44(param_2,*(undefined4 *)(_active_threads + 0x44));
}
/* GHIDRADEC_FUNCTION index=1593 start=0xf00726c0 */

/* WARNING: Removing unreachable block (ram,0xf00726c4) */

undefined8 _thread_block(undefined4 param_1,undefined4 param_2)

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
  _thread_block_with_continuation(0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1594 start=0xf00726d4 */

/* WARNING: Removing unreachable block (ram,0xf0072708) */

undefined8 _swtch_continue(undefined4 param_1,undefined4 param_2)

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
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x108)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 300) + 0x108))) {
    uVar1 = 1;
  }
  _thread_syscall_return(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1595 start=0xf0072718 */

/* WARNING: Removing unreachable block (ram,0xf0072720) */

undefined8 _swtch(undefined4 param_1,undefined4 param_2)

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
  _thread_block_with_continuation(_swtch_continue);
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x108)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 300) + 0x108))) {
    uVar1 = 1;
  }
  return CONCAT44(param_2,uVar1);
}
/* GHIDRADEC_FUNCTION index=1596 start=0xf0072760 */

/* WARNING: Removing unreachable block (ram,0xf00727b4) */
/* WARNING: Removing unreachable block (ram,0xf007277c) */

undefined8 _swtch_pri_continue(undefined4 param_1,undefined4 param_2)

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
  if (-1 < *(int *)(_active_threads + 100)) {
    _thread_depress_abort(_active_threads);
  }
  uVar1 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x108)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 300) + 0x108))) {
    uVar1 = 1;
  }
  _thread_syscall_return(uVar1);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1597 start=0xf00727c4 */

/* WARNING: Removing unreachable block (ram,0xf00727e4) */
/* WARNING: Removing unreachable block (ram,0xf00727fc) */
/* WARNING: Removing unreachable block (ram,0xf00727d8) */

undefined8 _swtch_pri(undefined4 param_1,undefined4 param_2)

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
  
  iVar1 = _active_threads;
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
  _thread_depress_priority(_active_threads,_min_quantum);
  _thread_block_with_continuation(_swtch_pri_continue);
  if (-1 < *(int *)(iVar1 + 100)) {
    _thread_depress_abort(iVar1);
  }
  uVar2 = 0;
  if ((0 < *(int *)(_processor_ptr + 0x108)) ||
     (0 < *(int *)(*(int *)(_processor_ptr + 300) + 0x108))) {
    uVar2 = 1;
  }
  return CONCAT44(param_2,uVar2);
}
/* GHIDRADEC_FUNCTION index=1598 start=0xf007283c */

/* WARNING: Removing unreachable block (ram,0xf0072860) */
/* WARNING: Removing unreachable block (ram,0xf0072858) */

undefined8 _thread_switch_continue(undefined4 param_1,undefined4 param_2)

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
  if (-1 < *(int *)(_active_threads + 100)) {
    _thread_depress_abort(_active_threads);
  }
  _thread_syscall_return(0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=1599 start=0xf0072870 */

/* WARNING: Removing unreachable block (ram,0xf00729c8) */
/* WARNING: Removing unreachable block (ram,0xf0072a14) */
/* WARNING: Removing unreachable block (ram,0xf0072970) */
/* WARNING: Removing unreachable block (ram,0xf0072928) */
/* WARNING: Removing unreachable block (ram,0xf00728c8) */
/* WARNING: Removing unreachable block (ram,0xf00728e8) */
/* WARNING: Removing unreachable block (ram,0xf0072948) */
/* WARNING: Removing unreachable block (ram,0xf00729dc) */
/* WARNING: Removing unreachable block (ram,0xf0072988) */
/* WARNING: Removing unreachable block (ram,0xf0072a2c) */
/* WARNING: Removing unreachable block (ram,0xf00728b8) */

undefined8 _thread_switch(int param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  uint uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar5;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 uVar6;
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
  
  iVar1 = _active_threads;
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
  iVar5 = 0;
  if (param_2 == 1) {
    _thread_depress_priority(_active_threads,param_3);
  }
  else if (param_2 < 2) {
    if (param_2 != 0) {
      uVar6 = 4;
      goto locret_F0072A38;
    }
  }
  else {
    if (param_2 != 2) {
      uVar6 = 4;
      goto locret_F0072A38;
    }
    _thread_will_wait_with_timeout(_active_threads);
  }
  if (param_1 == 0) {
loc_F00729F8:
    if ((param_1 != 0) && (iVar5 == 0xf)) {
      uVar6 = 4;
      goto locret_F0072A38;
    }
loc_F0072A14:
    _thread_block_with_continuation(_thread_switch_continue);
    iVar5 = *(int *)(iVar1 + 100);
  }
  else {
    iVar5 = *(int *)(*(int *)(iVar1 + 0xc) + 0x88);
    _ipc_object_translate(iVar5,param_1,0,(undefined *)((int)register0x00000038 + -0xc));
    if (iVar5 != 0) goto loc_F00729F8;
    uVar4 = *(uint *)(*(int *)((int)register0x00000038 + -0xc) + 8);
    puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc);
    if ((-1 < (int)uVar4) ||
       (puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc), (uVar4 & 0xffff) != 1)) {
loc_F00729E8:
      *puVar2 = 0;
      goto loc_F0072A14;
    }
    param_2 = *(int *)(*(int *)((int)register0x00000038 + -0xc) + 0x14);
    _splusclock();
    do {
      do {
      } while (*(int *)(param_2 + 0x20) != 0);
      piVar3 = (int *)(param_2 + 0x20);
      _simple_lock_try();
    } while (piVar3 == (int *)0x0);
    if ((*(int *)(param_2 + 400) != *(int *)(iVar1 + 400)) ||
       (iVar5 = param_2, _rem_runq(), iVar5 == 0)) {
      *(undefined4 *)(param_2 + 0x20) = 0;
      _splx(puVar2);
      puVar2 = *(undefined4 **)((int)register0x00000038 + -0xc);
      goto loc_F00729E8;
    }
    *(undefined4 *)(param_2 + 0x20) = 0;
    _splx(puVar2);
    **(undefined4 **)((int)register0x00000038 + -0xc) = 0;
    iVar5 = _processor_ptr;
    if (*(int *)(param_2 + 0x60) == 2) {
      *(undefined4 *)(_processor_ptr + 0x120) = *(undefined4 *)(param_2 + 0x5c);
      *(undefined4 *)(iVar5 + 0x124) = 1;
    }
    _thread_run(_thread_switch_continue,param_2);
    iVar5 = *(int *)(iVar1 + 100);
  }
  uVar6 = 0;
  if (-1 < iVar5) {
    _thread_depress_abort(iVar1);
    uVar6 = 0;
  }
locret_F0072A38:
  return CONCAT44(param_2,uVar6);
}

