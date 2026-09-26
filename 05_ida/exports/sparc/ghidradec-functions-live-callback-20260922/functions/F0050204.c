
/* WARNING: Removing unreachable block (ram,0xf00502ac) */

undefined8 _isblock(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  sbyte sVar4;
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
  iVar3 = *(int *)(param_1 + 0x38);
  if (iVar3 == 2) {
    sVar4 = (sbyte)((param_3 & 3) << 1);
    iVar2 = 3;
    iVar3 = (int)param_3 >> 2;
loc_F0050270:
    uVar1 = (*(byte *)(param_2 + iVar3) ^ 0xff) & iVar2 << sVar4;
  }
  else {
    if (iVar3 < 3) {
      if (iVar3 == 1) {
        uVar1 = (uint)(((*(byte *)(param_2 + ((int)param_3 >> 3)) ^ 0xff) & 1 << ((byte)param_3 & 7)
                       ) == 0);
        goto locret_F00502B8;
      }
loc_F00502AC:
      _panic(&aIsblock);
      uVar1 = 0;
      goto locret_F00502B8;
    }
    if (iVar3 == 4) {
      sVar4 = (sbyte)((param_3 & 1) << 2);
      iVar2 = 0xf;
      iVar3 = (int)param_3 >> 1;
      goto loc_F0050270;
    }
    if (iVar3 != 8) goto loc_F00502AC;
    uVar1 = *(byte *)(param_2 + param_3) ^ 0xff;
  }
  uVar1 = (uint)(uVar1 == 0);
locret_F00502B8:
  return CONCAT44(param_2,uVar1);
}

