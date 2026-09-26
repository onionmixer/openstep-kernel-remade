
/* WARNING: Removing unreachable block (ram,0xf003746c) */
/* WARNING: Removing unreachable block (ram,0xf0037358) */
/* WARNING: Removing unreachable block (ram,0xf0037498) */
/* WARNING: Removing unreachable block (ram,0xf00373dc) */

undefined8
_tcp_respond(int param_1,undefined4 *param_2,undefined4 *param_3,undefined4 param_4,
            undefined4 param_5,undefined param_6)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined2 uVar5;
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
  uVar5 = 0;
  iVar6 = 0;
  iVar7 = 0;
  if (param_1 != 0) {
    iVar7 = *(int *)(param_1 + 0x20);
    iVar2 = *(int *)(iVar7 + 0x1c);
    iVar6 = (uint)*(word *)(iVar2 + 0x26) - (uint)*(word *)(iVar2 + 0x24);
    iVar2 = (uint)*(word *)(iVar2 + 0x2a) - (uint)*(word *)(iVar2 + 0x28);
    if (iVar2 < iVar6) {
      iVar6 = iVar2;
    }
    uVar5 = (undefined2)iVar6;
    iVar6 = iVar7 + 0x24;
  }
  puVar3 = (undefined4 *)0x0;
  if (param_3 == (undefined4 *)0x0) {
    _m_get(0,2);
    if (puVar3 == (undefined4 *)0x0) goto locret_F00374A0;
    iVar2 = puVar3[1];
    *(undefined2 *)(puVar3 + 2) = 0x28;
    *(undefined4 *)((int)puVar3 + iVar2) = *param_2;
    *(undefined4 *)((int)puVar3 + iVar2 + 4) = param_2[1];
    *(undefined4 *)((int)puVar3 + iVar2 + 8) = param_2[2];
    *(undefined4 *)((int)puVar3 + iVar2 + 0xc) = param_2[3];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x10) = param_2[4];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x14) = param_2[5];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x18) = param_2[6];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x1c) = param_2[7];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x20) = param_2[8];
    *(undefined4 *)((int)puVar3 + iVar2 + 0x24) = param_2[9];
    param_6 = 0x10;
    param_2 = (undefined4 *)((int)puVar3 + puVar3[1]);
    param_3 = puVar3;
  }
  else {
    _m_freem(*param_3);
    *param_3 = 0;
    param_3[1] = (int)param_2 - (int)param_3;
    *(undefined2 *)(param_3 + 2) = 0x28;
    uVar4 = param_2[4];
    uVar1 = *(undefined2 *)((int)param_2 + 0x16);
    param_2[4] = param_2[3];
    param_2[3] = uVar4;
    *(undefined2 *)((int)param_2 + 0x16) = *(undefined2 *)(param_2 + 5);
    *(undefined2 *)(param_2 + 5) = uVar1;
  }
  param_2[1] = 0;
  *param_2 = 0;
  *(undefined *)(param_2 + 2) = 0;
  *(undefined2 *)((int)param_2 + 10) = 0x14;
  param_2[6] = param_5;
  param_2[7] = param_4;
  *(undefined2 *)((int)param_2 + 0x26) = 0;
  param_2[8] = param_2[8] & 0xffffff | 0x50000000;
  *(undefined *)((int)param_2 + 0x21) = param_6;
  *(undefined2 *)((int)param_2 + 0x22) = uVar5;
  puVar3 = param_3;
  _in_cksum(param_3,0x28);
  *(sword *)(param_2 + 9) = (sword)puVar3;
  *(undefined2 *)((int)param_2 + 2) = 0x28;
  *(char *)(param_2 + 2) = (char)_tcp_ttl;
  _ip_output(param_3,0,iVar6,0,0);
locret_F00374A0:
  return CONCAT44(param_2,iVar7);
}
