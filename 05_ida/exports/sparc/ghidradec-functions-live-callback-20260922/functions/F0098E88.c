
/* WARNING: Removing unreachable block (ram,0xf0098f8c) */
/* WARNING: Removing unreachable block (ram,0xf0098f78) */
/* WARNING: Removing unreachable block (ram,0xf0098fec) */
/* WARNING: Removing unreachable block (ram,0xf0098f30) */
/* WARNING: Removing unreachable block (ram,0xf0098eb0) */
/* WARNING: Type propagation algorithm not settling */

qword _in_cksum(undefined4 *param_1,uint param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  byte *pbVar5;
  byte *pbVar6;
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
  pbVar6 = (byte *)0x0;
  if (((int)*(sword *)(param_1 + 2) < (int)param_2) || ((param_2 & 1) != 0)) {
    uVar2 = 0;
    iVar3 = param_1[1];
    while( true ) {
      pbVar5 = (byte *)((int)param_1 + iVar3);
      if (uVar2 == 0xffffffff) {
        pbVar5 = pbVar5 + 1;
        param_2 = param_2 - 1;
        pbVar6 = pbVar6 + *(byte *)((int)param_1 + iVar3);
        uVar2 = (int)*(sword *)(param_1 + 2) - 1;
      }
      else {
        uVar2 = (uint)*(sword *)(param_1 + 2);
      }
      param_1 = (undefined4 *)*param_1;
      if ((int)param_2 < (int)uVar2) {
        uVar2 = param_2;
      }
      param_2 = param_2 - uVar2;
      if (0 < (int)uVar2) {
        if (((uint)pbVar5 & 1) == 0) {
          iVar3 = (int)uVar2 >> 1;
          pbVar4 = pbVar5;
          _ocsum(pbVar5,iVar3);
          pbVar6 = pbVar6 + (int)pbVar4;
          if ((uVar2 & 1) != 0) {
            uVar2 = 0xffffffff;
            pbVar6 = pbVar6 + (uint)pbVar5[iVar3 * 2] * 0x100;
          }
        }
        else {
          uVar2 = uVar2 - 1;
          bVar1 = *pbVar5;
          pbVar5 = pbVar5 + 1;
          pbVar4 = pbVar5;
          _ocsum(pbVar5,(int)uVar2 >> 1);
          *(sword *)((int)register0x00000038 + -10) = (sword)pbVar4;
          _swab((undefined *)((int)register0x00000038 + -10),
                (undefined *)((int)register0x00000038 + -10),2);
          pbVar6 = pbVar6 + (uint)*(word *)((int)register0x00000038 + -10) + (uint)bVar1 * 0x100;
          if ((uVar2 & 1) == 0) {
            uVar2 = 0xffffffff;
          }
          else {
            pbVar6 = pbVar6 + pbVar5[((int)uVar2 >> 1) * 2];
          }
        }
      }
      if (param_2 == 0) break;
      while( true ) {
        if (param_1 == (undefined4 *)0x0) {
          _printf(aCksumOutOfData);
          goto loc_F0098FF8;
        }
        if (*(sword *)(param_1 + 2) != 0) break;
        param_1 = (undefined4 *)*param_1;
      }
      iVar3 = param_1[1];
    }
loc_F0098FF8:
    uVar2 = ((uint)pbVar6 & 0xffff) + ((int)pbVar6 >> 0x10);
    uVar2 = (uVar2 & 0xffff) + ((int)uVar2 >> 0x10);
  }
  else {
    uVar2 = (int)param_1 + param_1[1];
    _ocsum(uVar2,(int)param_2 >> 1);
  }
  return CONCAT44(param_2,~uVar2) & 0xffffffff0000ffff;
}

