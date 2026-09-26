
undefined8 _vfs_getnum(byte *param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
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
  byte *pbVar4;
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
  pbVar2 = param_1 + param_2;
  iVar3 = -1;
  if (param_1 < pbVar2) {
    bVar1 = *param_1;
    pbVar4 = param_1;
    while( true ) {
      if (bVar1 != 0xff) {
        param_2 = 0;
        bVar1 = *pbVar4;
        while( true ) {
          if (((int)(char)bVar1 >> ((byte)param_2 & 0x1f) & 1U) == 0) {
            *pbVar4 = bVar1 | (byte)(1 << ((byte)param_2 & 0x1f));
            iVar3 = ((int)pbVar4 - (int)param_1) * 8 + param_2;
            goto locret_F00244E0;
          }
          param_2 = param_2 + 1;
          if (7 < param_2) break;
          bVar1 = *pbVar4;
        }
      }
      pbVar4 = pbVar4 + 1;
      if (pbVar2 <= pbVar4) break;
      bVar1 = *pbVar4;
    }
    iVar3 = -1;
  }
locret_F00244E0:
  return CONCAT44(param_2,iVar3);
}
