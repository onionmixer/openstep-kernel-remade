
/* WARNING: Removing unreachable block (ram,0xf0050354) */

undefined8 _clrblock(int param_1,int param_2,uint param_3)

{
  sbyte sVar1;
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
  iVar2 = *(int *)(param_1 + 0x38);
  if (iVar2 == 2) {
    iVar3 = (int)param_3 >> 2;
    sVar1 = (sbyte)((param_3 & 3) << 1);
    iVar2 = 3;
loc_F0050328:
    *(byte *)(param_2 + iVar3) = *(byte *)(param_2 + iVar3) & ~(byte)(iVar2 << sVar1);
  }
  else {
    if (iVar2 < 3) {
      if (iVar2 == 1) {
        *(byte *)(param_2 + ((int)param_3 >> 3)) =
             *(byte *)(param_2 + ((int)param_3 >> 3)) & ~(byte)(1 << ((byte)param_3 & 7));
        goto locret_F005035C;
      }
    }
    else {
      if (iVar2 == 4) {
        iVar3 = (int)param_3 >> 1;
        sVar1 = (sbyte)((param_3 & 1) << 2);
        iVar2 = 0xf;
        goto loc_F0050328;
      }
      if (iVar2 == 8) {
        *(undefined *)(param_2 + param_3) = 0;
        goto locret_F005035C;
      }
    }
    _panic(aClrblock);
  }
locret_F005035C:
  return CONCAT44(param_2,param_1);
}
