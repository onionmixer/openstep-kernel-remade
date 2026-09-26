
/* WARNING: Removing unreachable block (ram,0xf0054814) */

undefined8 _ipc_hash_local_lookup(int param_1,uint param_2,uint *param_3,int *param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 unaff_l0;
  int iVar4;
  undefined4 unaff_l1;
  uint uVar5;
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
  uVar5 = *(uint *)(param_1 + 0x18);
  uVar1 = param_2 >> 6;
  iVar4 = *(int *)(param_1 + 0x14);
  urem(uVar1,uVar5);
  iVar2 = *(int *)(iVar4 + uVar1 * 0x10 + 0xc);
  uVar6 = 0;
  if (iVar2 != 0) {
    do {
      iVar3 = iVar4 + iVar2 * 0x10;
      uVar1 = uVar1 + 1;
      if (*(uint *)(iVar3 + 4) == param_2) {
        uVar6 = 1;
        *param_3 = iVar2 << 8 | *(uint *)(iVar4 + iVar2 * 0x10) >> 0x18;
        *param_4 = iVar3;
        goto locret_F00548A0;
      }
      if (uVar1 == uVar5) {
        uVar1 = 0;
      }
      iVar2 = *(int *)(iVar4 + uVar1 * 0x10 + 0xc);
    } while (iVar2 != 0);
    uVar6 = 0;
  }
locret_F00548A0:
  return CONCAT44(param_2,uVar6);
}

