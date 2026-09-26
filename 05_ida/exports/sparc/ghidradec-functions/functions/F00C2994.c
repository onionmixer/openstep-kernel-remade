
/* WARNING: Removing unreachable block (ram,0xf00c2b78) */
/* WARNING: Removing unreachable block (ram,0xf00c2bb4) */
/* WARNING: Removing unreachable block (ram,0xf00c2b70) */

undefined8 sub_F00C2994(undefined4 *param_1,undefined4 param_2)

{
  byte bVar1;
  sword sVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  undefined4 unaff_l0;
  sword *psVar8;
  undefined4 unaff_l1;
  byte bVar9;
  byte bVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  int iVar11;
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
  psVar8 = (sword *)*param_1;
  iVar11 = *(int *)(param_1[6] + 0x34);
  if (psVar8 != (sword *)0x0) {
    pbVar5 = (byte *)(psVar8 + psVar8[1] * 6 + 2);
    if (_ms_speedlaw != 0) {
      iVar6 = _ms_speedlimit;
      if (*(sword *)(param_1 + 7) != 0) {
        iVar6 = _ms_speedlimit << 1;
      }
      iVar4 = (int)*(char *)(psVar8 + psVar8[1] * 6 + 2);
      if (iVar4 < 0) {
        iVar4 = -iVar4;
      }
      iVar7 = (int)(char)pbVar5[1];
      if (iVar7 < 0) {
        iVar7 = -iVar7;
      }
      if ((iVar6 < iVar4) || (iVar6 < iVar7)) {
        _ms_speed_count._0_4_ = _ms_speed_count._0_4_ + 1;
      }
      if (iVar6 < iVar4) {
        iVar4 = iVar4 - iVar6 >> 1;
        if (0 < (char)*pbVar5) {
          iVar4 = -iVar4;
        }
        iVar4 = (char)*pbVar5 + iVar4;
        if (_ms_maxspeed < iVar4) {
          *pbVar5 = (byte)_ms_maxspeed;
        }
        else {
          iVar3 = -_ms_maxspeed;
          if (-_ms_maxspeed <= iVar4) {
            iVar3 = iVar4;
          }
          *pbVar5 = (byte)iVar3;
        }
      }
      if (iVar6 < iVar7) {
        iVar6 = iVar7 - iVar6 >> 1;
        if (0 < (char)pbVar5[1]) {
          iVar6 = -iVar6;
        }
        iVar6 = (char)pbVar5[1] + iVar6;
        if (_ms_maxspeed < iVar6) {
          pbVar5[1] = (byte)_ms_maxspeed;
        }
        else {
          iVar4 = -_ms_maxspeed;
          if (-_ms_maxspeed <= iVar6) {
            iVar4 = iVar6;
          }
          pbVar5[1] = (byte)iVar4;
        }
      }
    }
    bVar1 = pbVar5[2];
    if (*(sword *)(param_1 + 7) == 0) {
      bVar10 = 0;
      bVar9 = 0;
    }
    else {
      bVar9 = *pbVar5 & 1;
      bVar10 = pbVar5[1] & 1;
      *pbVar5 = (char)*pbVar5 >> 1;
      pbVar5[1] = (char)pbVar5[1] >> 1;
    }
    sVar2 = psVar8[1];
    psVar8[1] = sVar2 + 1;
    pbVar5 = pbVar5 + 0xc;
    if (*psVar8 <= (sword)(sVar2 + 1)) {
      psVar8[1] = 0;
      pbVar5 = (byte *)(psVar8 + 2);
    }
    if (psVar8[1] == *(sword *)(param_1 + 2)) {
      if (_ms_overrun_msg != 0) {
        _printf(aMouseBufferFlu);
      }
      sub_F00C2698(param_1);
      pbVar5 = (byte *)(psVar8 + 2);
      _ms_overrun_cnt = _ms_overrun_cnt + 1;
      *(byte *)(psVar8 + 3) = bVar1;
    }
    else {
      pbVar5[2] = bVar1;
    }
    *pbVar5 = bVar9;
    pbVar5[1] = bVar10;
    iVar6 = *(int *)(iVar11 + 0x34);
    if (iVar6 != 0) {
      _MouseIntHandler(iVar6,*(undefined4 *)(iVar11 + 0x38),param_1);
    }
  }
  return CONCAT44(param_2,param_1);
}
