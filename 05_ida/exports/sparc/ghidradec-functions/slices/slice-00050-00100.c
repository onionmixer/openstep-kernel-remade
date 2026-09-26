/* GHIDRADEC_FUNCTION index=50 start=0xf0005f5c */

undefined4 _bcmp(uint *param_1,word *param_2,uint param_3)

{
  byte *pbVar1;
  byte bVar2;
  byte bVar3;
  word wVar4;
  word wVar5;
  byte *pbVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  bool bVar12;
  bool bVar13;
  
  if ((int)param_3 < 8) {
    pbVar6 = (byte *)((int)param_2 - (int)param_1);
    bVar13 = SBORROW4(param_3,1);
    iVar7 = param_3 - 1;
    bVar12 = iVar7 < 0;
    goto loc_F0006008;
  }
  uVar8 = (uint)param_1 & 3;
  if (uVar8 != 0) {
    if (uVar8 == 2) {
loc_F0005FA8:
      wVar4 = *(word *)param_1;
      param_1 = (uint *)((int)param_1 + 2);
      if (wVar4 >> 8 != (word)*(byte *)param_2) {
        return 1;
      }
      wVar5 = *param_2;
      param_2 = param_2 + 1;
      param_3 = param_3 - 2;
      bVar12 = (wVar4 & 0xff) == (word)(byte)wVar5;
    }
    else {
      bVar3 = *(byte *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      bVar2 = *(byte *)param_2;
      param_2 = (word *)((int)param_2 + 1);
      param_3 = param_3 - 1;
      bVar12 = bVar3 == bVar2;
      if (uVar8 != 3) {
        if (!bVar12) {
          return 1;
        }
        goto loc_F0005FA8;
      }
    }
    if (!bVar12) {
      return 1;
    }
  }
  uVar9 = (uint)param_2 & 3;
  uVar8 = param_3 & 0xfffffffc;
  param_3 = param_3 & 3;
  if (uVar9 == 0) {
    pbVar6 = (byte *)((int)param_2 - (int)param_1);
    uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
    while( true ) {
      uVar11 = *param_1;
      param_1 = param_1 + 1;
      uVar8 = uVar8 - 4;
      if (uVar11 != uVar9) {
        return 1;
      }
      if (uVar8 == 0) break;
      uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
    }
    bVar13 = SBORROW4(param_3,1);
    iVar7 = param_3 - 1;
    bVar12 = iVar7 < 0;
  }
  else if (uVar9 == 2) {
    uVar9 = (uint)*param_2;
    pbVar6 = (byte *)((int)param_2 + (2 - (int)param_1));
    do {
      uVar10 = uVar9 << 0x10;
      uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
      uVar11 = *param_1;
      param_1 = param_1 + 1;
      uVar8 = uVar8 - 4;
      if (uVar11 != (uVar9 >> 0x10 | uVar10)) {
        return 1;
      }
    } while (uVar8 != 0);
    pbVar6 = pbVar6 + -2;
    bVar13 = SBORROW4(param_3,1);
    iVar7 = param_3 - 1;
    bVar12 = iVar7 < 0;
  }
  else {
    uVar11 = (uint)*(byte *)param_2 << 0x18;
    if (uVar9 == 1) {
      uVar11 = uVar11 | (uint)*(word *)((int)param_2 + 1) << 8;
      pbVar6 = (byte *)((int)param_2 + (3 - (int)param_1));
      do {
        uVar9 = *(uint *)((int)param_1 + (int)pbVar6);
        uVar10 = *param_1;
        param_1 = param_1 + 1;
        uVar8 = uVar8 - 4;
        if (uVar10 != (uVar9 >> 0x18 | uVar11)) {
          return 1;
        }
        uVar11 = uVar9 << 8;
      } while (uVar8 != 0);
      pbVar6 = pbVar6 + -3;
      bVar13 = SBORROW4(param_3,1);
      iVar7 = param_3 - 1;
      bVar12 = iVar7 < 0;
    }
    else {
      iVar7 = ((int)param_2 + 1) - (int)param_1;
      do {
        uVar9 = *(uint *)((int)param_1 + iVar7);
        uVar10 = *param_1;
        param_1 = param_1 + 1;
        uVar8 = uVar8 - 4;
        if (uVar10 != (uVar9 >> 8 | uVar11)) {
          return 1;
        }
        uVar11 = uVar9 << 0x18;
      } while (uVar8 != 0);
      pbVar6 = (byte *)(iVar7 + -1);
      bVar13 = SBORROW4(param_3,1);
      iVar7 = param_3 - 1;
      bVar12 = iVar7 < 0;
    }
  }
loc_F0006008:
  while( true ) {
    if (bVar12 != bVar13) {
      return 0;
    }
    bVar3 = *(byte *)param_1;
    pbVar1 = (byte *)((int)param_1 + (int)pbVar6);
    param_1 = (uint *)((int)param_1 + 1);
    if (bVar3 != *pbVar1) break;
    bVar13 = SBORROW4(iVar7,1);
    iVar7 = iVar7 + -1;
    bVar12 = iVar7 < 0;
  }
  return 1;
}
/* GHIDRADEC_FUNCTION index=51 start=0xf0006138 */

int _memcmp(uint *param_1,uint *param_2,uint param_3)

{
  word wVar1;
  uint uVar2;
  byte *pbVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  bool bVar10;
  bool bVar11;
  
  if (param_1 == param_2) {
    return 0;
  }
  if ((int)param_3 < 8) {
    pbVar3 = (byte *)((int)param_2 - (int)param_1);
    bVar11 = SBORROW4(param_3,1);
    iVar4 = param_3 - 1;
    bVar10 = iVar4 < 0;
  }
  else {
    uVar5 = (uint)param_1 & 3;
    if (uVar5 != 0) {
      if (uVar5 == 2) {
loc_F000618C:
        wVar1 = *(word *)param_1;
        param_1 = (uint *)((int)param_1 + 2);
        iVar8 = (int)(char)*(byte *)param_2;
        iVar7 = (int)(sword)wVar1 >> 8;
        if (iVar7 != iVar8) goto locret_F000625C;
        iVar8 = (int)(char)*(byte *)((int)param_2 + 1);
        param_2 = (uint *)((int)param_2 + 2);
        param_3 = param_3 - 2;
        iVar7 = (int)(char)wVar1;
        bVar10 = iVar7 == iVar8;
      }
      else {
        iVar7 = (int)(char)*(byte *)param_1;
        param_1 = (uint *)((int)param_1 + 1);
        iVar8 = (int)(char)*(byte *)param_2;
        param_2 = (uint *)((int)param_2 + 1);
        param_3 = param_3 - 1;
        bVar10 = iVar7 == iVar8;
        if (uVar5 != 3) {
          if (!bVar10) goto locret_F000625C;
          goto loc_F000618C;
        }
      }
      if (!bVar10) goto locret_F000625C;
    }
    uVar6 = (uint)param_2 & 3;
    uVar5 = param_3 & 0xfffffffc;
    param_3 = param_3 & 3;
    if (uVar6 == 0) {
      pbVar3 = (byte *)((int)param_2 - (int)param_1);
      uVar9 = *(uint *)((int)param_1 + (int)pbVar3);
      while( true ) {
        uVar6 = *param_1;
        param_1 = param_1 + 1;
        uVar5 = uVar5 - 4;
        if (uVar6 != uVar9) break;
        if (uVar5 == 0) {
          bVar11 = SBORROW4(param_3,1);
          iVar4 = param_3 - 1;
          bVar10 = iVar4 < 0;
          goto loc_F00061F4;
        }
        uVar9 = *(uint *)((int)param_1 + (int)pbVar3);
      }
loc_F0006204:
      iVar4 = (int)uVar6 >> 0x18;
      iVar7 = (int)uVar9 >> 0x18;
      if (iVar4 == iVar7) {
        iVar4 = (int)(uVar6 << 8) >> 0x18;
        iVar7 = (int)(uVar9 << 8) >> 0x18;
        if (iVar4 == iVar7) {
          iVar4 = (int)(uVar6 << 0x10) >> 0x18;
          iVar7 = (int)(uVar9 << 0x10) >> 0x18;
          if (iVar4 == iVar7) {
            iVar4 = (int)(char)uVar6;
            iVar7 = (int)(char)uVar9;
          }
        }
      }
      return iVar4 - iVar7;
    }
    if (uVar6 == 2) {
      uVar2 = (uint)*(word *)param_2;
      pbVar3 = (byte *)((int)param_2 + (2 - (int)param_1));
      do {
        uVar9 = uVar2 << 0x10;
        uVar2 = *(uint *)((int)param_1 + (int)pbVar3);
        uVar6 = *param_1;
        param_1 = param_1 + 1;
        uVar9 = uVar2 >> 0x10 | uVar9;
        uVar5 = uVar5 - 4;
        if (uVar6 != uVar9) goto loc_F0006204;
      } while (uVar5 != 0);
      pbVar3 = pbVar3 + -2;
      bVar11 = SBORROW4(param_3,1);
      iVar4 = param_3 - 1;
      bVar10 = iVar4 < 0;
    }
    else {
      uVar9 = (uint)*(byte *)param_2 << 0x18;
      if (uVar6 == 1) {
        uVar9 = uVar9 | (uint)*(word *)((int)param_2 + 1) << 8;
        pbVar3 = (byte *)((int)param_2 + (3 - (int)param_1));
        do {
          uVar2 = *(uint *)((int)param_1 + (int)pbVar3);
          uVar6 = *param_1;
          param_1 = param_1 + 1;
          uVar9 = uVar2 >> 0x18 | uVar9;
          uVar5 = uVar5 - 4;
          if (uVar6 != uVar9) goto loc_F0006204;
          uVar9 = uVar2 << 8;
        } while (uVar5 != 0);
        pbVar3 = pbVar3 + -3;
        bVar11 = SBORROW4(param_3,1);
        iVar4 = param_3 - 1;
        bVar10 = iVar4 < 0;
      }
      else {
        iVar4 = ((int)param_2 + 1) - (int)param_1;
        do {
          uVar2 = *(uint *)((int)param_1 + iVar4);
          uVar6 = *param_1;
          param_1 = param_1 + 1;
          uVar9 = uVar2 >> 8 | uVar9;
          uVar5 = uVar5 - 4;
          if (uVar6 != uVar9) goto loc_F0006204;
          uVar9 = uVar2 << 0x18;
        } while (uVar5 != 0);
        pbVar3 = (byte *)(iVar4 + -1);
        bVar11 = SBORROW4(param_3,1);
        iVar4 = param_3 - 1;
        bVar10 = iVar4 < 0;
      }
    }
  }
loc_F00061F4:
  while( true ) {
    if (bVar10 != bVar11) {
      return 0;
    }
    iVar7 = (int)(char)*(byte *)param_1;
    iVar8 = (int)(char)*(byte *)((int)param_1 + (int)pbVar3);
    param_1 = (uint *)((int)param_1 + 1);
    if (iVar7 != iVar8) break;
    bVar11 = SBORROW4(iVar4,1);
    iVar4 = iVar4 + -1;
    bVar10 = iVar4 < 0;
  }
locret_F000625C:
  return iVar7 - iVar8;
}
/* GHIDRADEC_FUNCTION index=52 start=0xf000637c */

/* WARNING: Instruction at (ram,0xf0006388) overlaps instruction at (ram,0xf0006384)
    */

void _memset(uint *param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  if (6 < (int)param_3) {
    for (; uVar1 = param_3 & 0xfffffffc, ((uint)param_1 & 3) != 0;
        param_1 = (uint *)((int)param_1 + 1)) {
      param_3 = param_3 - 1;
      *(char *)param_1 = (char)param_2;
    }
    param_2 = param_2 & 0xff | (param_2 & 0xff) << 8;
    param_2 = param_2 | param_2 << 0x10;
    do {
      *param_1 = param_2;
      uVar1 = uVar1 - 4;
      param_1 = param_1 + 1;
    } while (uVar1 != 0);
    param_3 = param_3 & 3;
  }
  while( true ) {
    if ((int)param_3 < 1) break;
    *(char *)param_1 = (char)param_2;
    param_3 = param_3 - 1;
    param_1 = (uint *)((int)param_1 + 1);
  }
  return;
}
/* GHIDRADEC_FUNCTION index=53 start=0xf00063e4 */

/* WARNING: Removing unreachable block (ram,0xf0006474) */

undefined8 .mul(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  int iVar33;
  uint uVar34;
  uint uVar35;
  
  if ((param_1 & 0xfffff000) == 0) {
    uVar35 = 0;
    if ((param_1 & 1) != 0) {
      uVar35 = param_2;
    }
    uVar34 = uVar35 >> 1 | (uint)((int)uVar35 < 0) << 0x1f;
    uVar1 = 0;
    if ((param_1 >> 1 & 1) != 0) {
      uVar1 = param_2;
    }
    uVar2 = uVar1 + uVar34;
    param_1 = param_1 >> 2;
    uVar34 = uVar2 >> 1 | (uint)((int)uVar2 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 1) != 0) {
      uVar1 = param_2;
    }
    uVar32 = uVar1 + uVar34;
    uVar34 = uVar32 >> 1 | (uint)((int)uVar32 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 2) != 0) {
      uVar1 = param_2;
    }
    uVar3 = uVar1 + uVar34;
    uVar34 = uVar3 >> 1 | (uint)((int)uVar3 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 4) != 0) {
      uVar1 = param_2;
    }
    uVar4 = uVar1 + uVar34;
    uVar34 = uVar4 >> 1 | (uint)((int)uVar4 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 8) != 0) {
      uVar1 = param_2;
    }
    uVar5 = uVar1 + uVar34;
    uVar34 = uVar5 >> 1 | (uint)((int)uVar5 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 0x10) != 0) {
      uVar1 = param_2;
    }
    uVar6 = uVar1 + uVar34;
    uVar34 = uVar6 >> 1 | (uint)((int)uVar6 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 0x20) != 0) {
      uVar1 = param_2;
    }
    uVar7 = uVar1 + uVar34;
    uVar34 = uVar7 >> 1 | (uint)((int)uVar7 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 0x40) != 0) {
      uVar1 = param_2;
    }
    uVar8 = uVar1 + uVar34;
    uVar34 = uVar8 >> 1 | (uint)((int)uVar8 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 0x80) != 0) {
      uVar1 = param_2;
    }
    uVar9 = uVar1 + uVar34;
    uVar34 = uVar9 >> 1 | (uint)((int)uVar9 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 0x100) != 0) {
      uVar1 = param_2;
    }
    uVar10 = uVar1 + uVar34;
    uVar34 = uVar10 >> 1 | (uint)((int)uVar10 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
    uVar1 = 0;
    if ((param_1 & 0x200) != 0) {
      uVar1 = param_2;
    }
    uVar11 = uVar1 + uVar34;
    uVar35 = ((((((((((((uVar35 & 1) << 0x1e | uVar2 * -0x80000000) >> 1 | uVar32 * -0x80000000) >>
                      1 | uVar3 * -0x80000000) >> 1 | uVar4 * -0x80000000) >> 1 |
                   uVar5 * -0x80000000) >> 1 | uVar6 * -0x80000000) >> 1 | uVar7 * -0x80000000) >> 1
                | uVar8 * -0x80000000) >> 1 | uVar9 * -0x80000000) >> 1 | uVar10 * -0x80000000) >> 1
             | uVar11 * -0x80000000) >> 0x14 | (uVar11 >> 1) << 0xc;
    iVar33 = (int)(uVar11 >> 1 | (uint)((int)uVar11 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f) >> 0x14;
    if (-1 < (int)uVar35) {
      return CONCAT44(iVar33,uVar35);
    }
    return CONCAT44(iVar33,uVar35);
  }
  uVar35 = 0;
  if ((param_1 & 1) != 0) {
    uVar35 = param_2;
  }
  uVar34 = uVar35 >> 1 | (uint)((int)uVar35 < 0) << 0x1f;
  uVar1 = 0;
  if ((param_1 >> 1 & 1) != 0) {
    uVar1 = param_2;
  }
  uVar2 = uVar1 + uVar34;
  uVar32 = param_1 >> 2;
  uVar34 = uVar2 >> 1 | (uint)((int)uVar2 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 1) != 0) {
    uVar1 = param_2;
  }
  uVar3 = uVar1 + uVar34;
  uVar34 = uVar3 >> 1 | (uint)((int)uVar3 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 2) != 0) {
    uVar1 = param_2;
  }
  uVar4 = uVar1 + uVar34;
  uVar34 = uVar4 >> 1 | (uint)((int)uVar4 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 4) != 0) {
    uVar1 = param_2;
  }
  uVar5 = uVar1 + uVar34;
  uVar34 = uVar5 >> 1 | (uint)((int)uVar5 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 8) != 0) {
    uVar1 = param_2;
  }
  uVar6 = uVar1 + uVar34;
  uVar34 = uVar6 >> 1 | (uint)((int)uVar6 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x10) != 0) {
    uVar1 = param_2;
  }
  uVar7 = uVar1 + uVar34;
  uVar34 = uVar7 >> 1 | (uint)((int)uVar7 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x20) != 0) {
    uVar1 = param_2;
  }
  uVar8 = uVar1 + uVar34;
  uVar34 = uVar8 >> 1 | (uint)((int)uVar8 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x40) != 0) {
    uVar1 = param_2;
  }
  uVar9 = uVar1 + uVar34;
  uVar34 = uVar9 >> 1 | (uint)((int)uVar9 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x80) != 0) {
    uVar1 = param_2;
  }
  uVar10 = uVar1 + uVar34;
  uVar34 = uVar10 >> 1 | (uint)((int)uVar10 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x100) != 0) {
    uVar1 = param_2;
  }
  uVar11 = uVar1 + uVar34;
  uVar34 = uVar11 >> 1 | (uint)((int)uVar11 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x200) != 0) {
    uVar1 = param_2;
  }
  uVar12 = uVar1 + uVar34;
  uVar34 = uVar12 >> 1 | (uint)((int)uVar12 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x400) != 0) {
    uVar1 = param_2;
  }
  uVar13 = uVar1 + uVar34;
  uVar34 = uVar13 >> 1 | (uint)((int)uVar13 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x800) != 0) {
    uVar1 = param_2;
  }
  uVar14 = uVar1 + uVar34;
  uVar34 = uVar14 >> 1 | (uint)((int)uVar14 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x1000) != 0) {
    uVar1 = param_2;
  }
  uVar15 = uVar1 + uVar34;
  uVar34 = uVar15 >> 1 | (uint)((int)uVar15 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x2000) != 0) {
    uVar1 = param_2;
  }
  uVar16 = uVar1 + uVar34;
  uVar34 = uVar16 >> 1 | (uint)((int)uVar16 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x4000) != 0) {
    uVar1 = param_2;
  }
  uVar17 = uVar1 + uVar34;
  uVar34 = uVar17 >> 1 | (uint)((int)uVar17 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x8000) != 0) {
    uVar1 = param_2;
  }
  uVar18 = uVar1 + uVar34;
  uVar34 = uVar18 >> 1 | (uint)((int)uVar18 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x10000) != 0) {
    uVar1 = param_2;
  }
  uVar19 = uVar1 + uVar34;
  uVar34 = uVar19 >> 1 | (uint)((int)uVar19 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x20000) != 0) {
    uVar1 = param_2;
  }
  uVar20 = uVar1 + uVar34;
  uVar34 = uVar20 >> 1 | (uint)((int)uVar20 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x40000) != 0) {
    uVar1 = param_2;
  }
  uVar21 = uVar1 + uVar34;
  uVar34 = uVar21 >> 1 | (uint)((int)uVar21 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x80000) != 0) {
    uVar1 = param_2;
  }
  uVar22 = uVar1 + uVar34;
  uVar34 = uVar22 >> 1 | (uint)((int)uVar22 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x100000) != 0) {
    uVar1 = param_2;
  }
  uVar23 = uVar1 + uVar34;
  uVar34 = uVar23 >> 1 | (uint)((int)uVar23 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x200000) != 0) {
    uVar1 = param_2;
  }
  uVar24 = uVar1 + uVar34;
  uVar34 = uVar24 >> 1 | (uint)((int)uVar24 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x400000) != 0) {
    uVar1 = param_2;
  }
  uVar25 = uVar1 + uVar34;
  uVar34 = uVar25 >> 1 | (uint)((int)uVar25 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x800000) != 0) {
    uVar1 = param_2;
  }
  uVar26 = uVar1 + uVar34;
  uVar34 = uVar26 >> 1 | (uint)((int)uVar26 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x1000000) != 0) {
    uVar1 = param_2;
  }
  uVar27 = uVar1 + uVar34;
  uVar34 = uVar27 >> 1 | (uint)((int)uVar27 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x2000000) != 0) {
    uVar1 = param_2;
  }
  uVar28 = uVar1 + uVar34;
  uVar34 = uVar28 >> 1 | (uint)((int)uVar28 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x4000000) != 0) {
    uVar1 = param_2;
  }
  uVar29 = uVar1 + uVar34;
  uVar34 = uVar29 >> 1 | (uint)((int)uVar29 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x8000000) != 0) {
    uVar1 = param_2;
  }
  uVar30 = uVar1 + uVar34;
  uVar34 = uVar30 >> 1 | (uint)((int)uVar30 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((uVar32 & 0x10000000) != 0) {
    uVar1 = param_2;
  }
  uVar32 = uVar1 + uVar34;
  uVar34 = uVar32 >> 1 | (uint)((int)uVar32 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar1 = 0;
  if ((int)param_1 < 0) {
    uVar1 = param_2;
  }
  uVar31 = uVar1 + uVar34;
  uVar34 = uVar31 >> 1 | (uint)((int)uVar31 < 0 != SCARRY4(uVar1,uVar34)) << 0x1f;
  uVar35 = (((((((((((((((((((((((((((((((uVar35 & 1) << 0x1e | uVar2 * -0x80000000) >> 1 |
                                       uVar3 * -0x80000000) >> 1 | uVar4 * -0x80000000) >> 1 |
                                     uVar5 * -0x80000000) >> 1 | uVar6 * -0x80000000) >> 1 |
                                   uVar7 * -0x80000000) >> 1 | uVar8 * -0x80000000) >> 1 |
                                 uVar9 * -0x80000000) >> 1 | uVar10 * -0x80000000) >> 1 |
                               uVar11 * -0x80000000) >> 1 | uVar12 * -0x80000000) >> 1 |
                             uVar13 * -0x80000000) >> 1 | uVar14 * -0x80000000) >> 1 |
                           uVar15 * -0x80000000) >> 1 | uVar16 * -0x80000000) >> 1 |
                         uVar17 * -0x80000000) >> 1 | uVar18 * -0x80000000) >> 1 |
                       uVar19 * -0x80000000) >> 1 | uVar20 * -0x80000000) >> 1 |
                     uVar21 * -0x80000000) >> 1 | uVar22 * -0x80000000) >> 1 | uVar23 * -0x80000000)
                   >> 1 | uVar24 * -0x80000000) >> 1 | uVar25 * -0x80000000) >> 1 |
                uVar26 * -0x80000000) >> 1 | uVar27 * -0x80000000) >> 1 | uVar28 * -0x80000000) >> 1
             | uVar29 * -0x80000000) >> 1 | uVar30 * -0x80000000) >> 1 | uVar32 * -0x80000000) >> 1
           | uVar31 * -0x80000000;
  if ((int)param_1 < 0) {
    uVar34 = uVar34 - param_2;
  }
  if (uVar31 * -0x80000000 == 0) {
    return CONCAT44(uVar34,uVar35);
  }
  return CONCAT44(uVar34,uVar35);
}
/* GHIDRADEC_FUNCTION index=54 start=0xf0006500 */

/* WARNING: Removing unreachable block (ram,0xf0006594) */

qword .umul(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  uint uVar23;
  uint uVar24;
  uint uVar25;
  uint uVar26;
  uint uVar27;
  uint uVar28;
  uint uVar29;
  uint uVar30;
  uint uVar31;
  uint uVar32;
  uint uVar33;
  uint uVar34;
  
  if (((param_1 | param_2) & 0xfffff000) == 0) {
    uVar1 = 0;
    if ((param_1 & 1) != 0) {
      uVar1 = param_2;
    }
    uVar34 = 0;
    if ((param_1 >> 1 & 1) != 0) {
      uVar34 = param_2;
    }
    uVar34 = uVar34 + (uVar1 >> 1);
    param_1 = param_1 >> 2;
    uVar32 = 0;
    if ((param_1 & 1) != 0) {
      uVar32 = param_2;
    }
    uVar32 = uVar32 + (uVar34 >> 1);
    uVar2 = 0;
    if ((param_1 & 2) != 0) {
      uVar2 = param_2;
    }
    uVar2 = uVar2 + (uVar32 >> 1);
    uVar33 = 0;
    if ((param_1 & 4) != 0) {
      uVar33 = param_2;
    }
    uVar33 = uVar33 + (uVar2 >> 1);
    uVar3 = 0;
    if ((param_1 & 8) != 0) {
      uVar3 = param_2;
    }
    uVar3 = uVar3 + (uVar33 >> 1);
    uVar4 = 0;
    if ((param_1 & 0x10) != 0) {
      uVar4 = param_2;
    }
    uVar4 = uVar4 + (uVar3 >> 1);
    uVar5 = 0;
    if ((param_1 & 0x20) != 0) {
      uVar5 = param_2;
    }
    uVar5 = uVar5 + (uVar4 >> 1);
    uVar6 = 0;
    if ((param_1 & 0x40) != 0) {
      uVar6 = param_2;
    }
    uVar6 = uVar6 + (uVar5 >> 1);
    uVar7 = 0;
    if ((param_1 & 0x80) != 0) {
      uVar7 = param_2;
    }
    uVar7 = uVar7 + (uVar6 >> 1);
    uVar8 = 0;
    if ((param_1 & 0x100) != 0) {
      uVar8 = param_2;
    }
    uVar8 = uVar8 + (uVar7 >> 1);
    uVar9 = 0;
    if ((param_1 & 0x200) != 0) {
      uVar9 = param_2;
    }
    uVar9 = uVar9 + (uVar8 >> 1);
    return (qword)(((((((((((((uVar1 & 1) << 0x1e | uVar34 * -0x80000000) >> 1 |
                            uVar32 * -0x80000000) >> 1 | uVar2 * -0x80000000) >> 1 |
                          uVar33 * -0x80000000) >> 1 | uVar3 * -0x80000000) >> 1 |
                        uVar4 * -0x80000000) >> 1 | uVar5 * -0x80000000) >> 1 | uVar6 * -0x80000000)
                      >> 1 | uVar7 * -0x80000000) >> 1 | uVar8 * -0x80000000) >> 1 |
                   uVar9 * -0x80000000) >> 0x14 | (uVar9 >> 1) << 0xc);
  }
  uVar1 = 0;
  if ((param_1 & 1) != 0) {
    uVar1 = param_2;
  }
  uVar34 = uVar1 >> 1 | (uint)((int)uVar1 < 0) << 0x1f;
  uVar32 = 0;
  if ((param_1 >> 1 & 1) != 0) {
    uVar32 = param_2;
  }
  uVar2 = uVar32 + uVar34;
  uVar33 = param_1 >> 2;
  uVar34 = uVar2 >> 1 | (uint)((int)uVar2 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 1) != 0) {
    uVar32 = param_2;
  }
  uVar3 = uVar32 + uVar34;
  uVar34 = uVar3 >> 1 | (uint)((int)uVar3 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 2) != 0) {
    uVar32 = param_2;
  }
  uVar4 = uVar32 + uVar34;
  uVar34 = uVar4 >> 1 | (uint)((int)uVar4 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 4) != 0) {
    uVar32 = param_2;
  }
  uVar5 = uVar32 + uVar34;
  uVar34 = uVar5 >> 1 | (uint)((int)uVar5 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 8) != 0) {
    uVar32 = param_2;
  }
  uVar6 = uVar32 + uVar34;
  uVar34 = uVar6 >> 1 | (uint)((int)uVar6 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x10) != 0) {
    uVar32 = param_2;
  }
  uVar7 = uVar32 + uVar34;
  uVar34 = uVar7 >> 1 | (uint)((int)uVar7 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x20) != 0) {
    uVar32 = param_2;
  }
  uVar8 = uVar32 + uVar34;
  uVar34 = uVar8 >> 1 | (uint)((int)uVar8 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x40) != 0) {
    uVar32 = param_2;
  }
  uVar9 = uVar32 + uVar34;
  uVar34 = uVar9 >> 1 | (uint)((int)uVar9 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x80) != 0) {
    uVar32 = param_2;
  }
  uVar10 = uVar32 + uVar34;
  uVar34 = uVar10 >> 1 | (uint)((int)uVar10 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x100) != 0) {
    uVar32 = param_2;
  }
  uVar11 = uVar32 + uVar34;
  uVar34 = uVar11 >> 1 | (uint)((int)uVar11 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x200) != 0) {
    uVar32 = param_2;
  }
  uVar12 = uVar32 + uVar34;
  uVar34 = uVar12 >> 1 | (uint)((int)uVar12 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x400) != 0) {
    uVar32 = param_2;
  }
  uVar13 = uVar32 + uVar34;
  uVar34 = uVar13 >> 1 | (uint)((int)uVar13 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x800) != 0) {
    uVar32 = param_2;
  }
  uVar14 = uVar32 + uVar34;
  uVar34 = uVar14 >> 1 | (uint)((int)uVar14 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x1000) != 0) {
    uVar32 = param_2;
  }
  uVar15 = uVar32 + uVar34;
  uVar34 = uVar15 >> 1 | (uint)((int)uVar15 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x2000) != 0) {
    uVar32 = param_2;
  }
  uVar16 = uVar32 + uVar34;
  uVar34 = uVar16 >> 1 | (uint)((int)uVar16 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x4000) != 0) {
    uVar32 = param_2;
  }
  uVar17 = uVar32 + uVar34;
  uVar34 = uVar17 >> 1 | (uint)((int)uVar17 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x8000) != 0) {
    uVar32 = param_2;
  }
  uVar18 = uVar32 + uVar34;
  uVar34 = uVar18 >> 1 | (uint)((int)uVar18 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x10000) != 0) {
    uVar32 = param_2;
  }
  uVar19 = uVar32 + uVar34;
  uVar34 = uVar19 >> 1 | (uint)((int)uVar19 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x20000) != 0) {
    uVar32 = param_2;
  }
  uVar20 = uVar32 + uVar34;
  uVar34 = uVar20 >> 1 | (uint)((int)uVar20 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x40000) != 0) {
    uVar32 = param_2;
  }
  uVar21 = uVar32 + uVar34;
  uVar34 = uVar21 >> 1 | (uint)((int)uVar21 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x80000) != 0) {
    uVar32 = param_2;
  }
  uVar22 = uVar32 + uVar34;
  uVar34 = uVar22 >> 1 | (uint)((int)uVar22 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x100000) != 0) {
    uVar32 = param_2;
  }
  uVar23 = uVar32 + uVar34;
  uVar34 = uVar23 >> 1 | (uint)((int)uVar23 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x200000) != 0) {
    uVar32 = param_2;
  }
  uVar24 = uVar32 + uVar34;
  uVar34 = uVar24 >> 1 | (uint)((int)uVar24 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x400000) != 0) {
    uVar32 = param_2;
  }
  uVar25 = uVar32 + uVar34;
  uVar34 = uVar25 >> 1 | (uint)((int)uVar25 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x800000) != 0) {
    uVar32 = param_2;
  }
  uVar26 = uVar32 + uVar34;
  uVar34 = uVar26 >> 1 | (uint)((int)uVar26 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x1000000) != 0) {
    uVar32 = param_2;
  }
  uVar27 = uVar32 + uVar34;
  uVar34 = uVar27 >> 1 | (uint)((int)uVar27 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x2000000) != 0) {
    uVar32 = param_2;
  }
  uVar28 = uVar32 + uVar34;
  uVar34 = uVar28 >> 1 | (uint)((int)uVar28 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x4000000) != 0) {
    uVar32 = param_2;
  }
  uVar29 = uVar32 + uVar34;
  uVar34 = uVar29 >> 1 | (uint)((int)uVar29 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x8000000) != 0) {
    uVar32 = param_2;
  }
  uVar30 = uVar32 + uVar34;
  uVar34 = uVar30 >> 1 | (uint)((int)uVar30 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((uVar33 & 0x10000000) != 0) {
    uVar32 = param_2;
  }
  uVar33 = uVar32 + uVar34;
  uVar34 = uVar33 >> 1 | (uint)((int)uVar33 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  uVar32 = 0;
  if ((int)param_1 < 0) {
    uVar32 = param_2;
  }
  uVar31 = uVar32 + uVar34;
  uVar34 = uVar31 >> 1 | (uint)((int)uVar31 < 0 != SCARRY4(uVar32,uVar34)) << 0x1f;
  if ((int)param_2 < 0) {
    uVar34 = uVar34 + param_1;
  }
  return CONCAT44(uVar34,(((((((((((((((((((((((((((((((uVar1 & 1) << 0x1e | uVar2 * -0x80000000) >>
                                                      1 | uVar3 * -0x80000000) >> 1 |
                                                    uVar4 * -0x80000000) >> 1 | uVar5 * -0x80000000)
                                                   >> 1 | uVar6 * -0x80000000) >> 1 |
                                                 uVar7 * -0x80000000) >> 1 | uVar8 * -0x80000000) >>
                                                1 | uVar9 * -0x80000000) >> 1 | uVar10 * -0x80000000
                                              ) >> 1 | uVar11 * -0x80000000) >> 1 |
                                            uVar12 * -0x80000000) >> 1 | uVar13 * -0x80000000) >> 1
                                          | uVar14 * -0x80000000) >> 1 | uVar15 * -0x80000000) >> 1
                                        | uVar16 * -0x80000000) >> 1 | uVar17 * -0x80000000) >> 1 |
                                      uVar18 * -0x80000000) >> 1 | uVar19 * -0x80000000) >> 1 |
                                    uVar20 * -0x80000000) >> 1 | uVar21 * -0x80000000) >> 1 |
                                  uVar22 * -0x80000000) >> 1 | uVar23 * -0x80000000) >> 1 |
                                uVar24 * -0x80000000) >> 1 | uVar25 * -0x80000000) >> 1 |
                              uVar26 * -0x80000000) >> 1 | uVar27 * -0x80000000) >> 1 |
                            uVar28 * -0x80000000) >> 1 | uVar29 * -0x80000000) >> 1 |
                          uVar30 * -0x80000000) >> 1 | uVar33 * -0x80000000) >> 1 |
                         uVar31 * -0x80000000);
}
/* GHIDRADEC_FUNCTION index=55 start=0xf0006600 */

void .udiv(void)

{
  func_0xf000662c();
  return;
}
/* GHIDRADEC_FUNCTION index=56 start=0xf0006608 */

int .div(uint param_1,uint param_2)

{
  code *pcVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar2 = param_2 ^ param_1;
  if (((int)(param_2 | param_1) < 0) &&
     ((-1 < (int)param_2 || (param_2 = -param_2, (int)param_1 < 0)))) {
    param_1 = -param_1;
  }
  if (param_2 == 0) {
    pcVar1 = (code *)sw_trap(2);
    (*pcVar1)();
  }
  iVar5 = 0;
  if (param_2 <= param_1) {
    iVar6 = 0;
    if (param_1 < 0x8000000) {
      do {
        iVar4 = iVar6;
        param_2 = param_2 * 0x10;
        iVar6 = iVar4 + 1;
      } while (param_2 < param_1 || param_2 - param_1 == 0);
      if (iVar4 + 1 != 0) {
        bVar9 = (int)param_1 < 0;
        goto loc_F0006704;
      }
    }
    else {
      for (; iVar4 = 1, uVar7 = param_2, param_2 < 0x8000000; param_2 = param_2 << 4) {
        iVar6 = iVar6 + 1;
      }
      do {
        param_2 = uVar7;
        iVar3 = iVar4;
        if (param_1 <= param_2) goto loc_F00066A0;
        iVar4 = iVar3 + 1;
        uVar7 = param_2 * 2;
      } while (!CARRY4(param_2,param_2));
      param_2 = (param_2 & 0x7fffffff) + 0x80000000;
loc_F00066A0:
      if (0 < iVar3) {
        param_1 = param_1 - param_2;
        iVar5 = 1;
        iVar4 = iVar3 + -1;
        while( true ) {
          if (iVar4 < 1) break;
          param_2 = param_2 >> 1;
          if ((int)param_1 < 0) {
            param_1 = param_1 + param_2;
            iVar5 = iVar5 * 2 + -1;
            iVar4 = iVar4 + -1;
          }
          else {
            param_1 = param_1 - param_2;
            iVar5 = iVar5 * 2 + 1;
            iVar4 = iVar4 + -1;
          }
        }
      }
      while( true ) {
        iVar4 = iVar6 + -1;
        bVar9 = (int)param_1 < 0;
        if (iVar6 < 1) break;
loc_F0006704:
        iVar5 = iVar5 * 0x10;
        uVar7 = param_2 >> 1;
        iVar6 = iVar4;
        if (bVar9) {
          iVar4 = param_1 + uVar7;
          uVar8 = param_2 >> 2;
          if (iVar4 < 0 == SCARRY4(param_1,uVar7)) {
            iVar3 = iVar4 - uVar8;
            uVar7 = param_2 >> 3;
            if (iVar4 < (int)uVar8) {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + -5;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + -7;
              }
            }
            else {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + -3;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + -1;
              }
            }
          }
          else {
            iVar3 = iVar4 + uVar8;
            uVar7 = param_2 >> 3;
            if (iVar3 < 0 == SCARRY4(iVar4,uVar8)) {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + -0xb;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + -9;
              }
            }
            else {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + -0xd;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + -0xf;
              }
            }
          }
        }
        else {
          iVar4 = param_1 - uVar7;
          uVar8 = param_2 >> 2;
          if ((int)param_1 < (int)uVar7) {
            iVar3 = iVar4 + uVar8;
            uVar7 = param_2 >> 3;
            if (iVar3 < 0 == SCARRY4(iVar4,uVar8)) {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + 5;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + 7;
              }
            }
            else {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + 3;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + 1;
              }
            }
          }
          else {
            iVar3 = iVar4 - uVar8;
            uVar7 = param_2 >> 3;
            if (iVar4 < (int)uVar8) {
              iVar4 = iVar3 + uVar7;
              param_2 = param_2 >> 4;
              if (iVar4 < 0 == SCARRY4(iVar3,uVar7)) {
                param_1 = iVar4 - param_2;
                iVar5 = iVar5 + 0xb;
              }
              else {
                param_1 = iVar4 + param_2;
                iVar5 = iVar5 + 9;
              }
            }
            else {
              param_2 = param_2 >> 4;
              if (iVar3 < (int)uVar7) {
                param_1 = (iVar3 - uVar7) + param_2;
                iVar5 = iVar5 + 0xd;
              }
              else {
                param_1 = (iVar3 - uVar7) - param_2;
                iVar5 = iVar5 + 0xf;
              }
            }
          }
        }
      }
      if (bVar9) {
        iVar5 = iVar5 + -1;
      }
    }
  }
  if ((int)uVar2 < 0) {
    iVar5 = -iVar5;
  }
  return iVar5;
}
/* GHIDRADEC_FUNCTION index=57 start=0xf00068a0 */

void .urem(void)

{
  func_0xf00068cc();
  return;
}
/* GHIDRADEC_FUNCTION index=58 start=0xf00068a8 */

uint .rem(uint param_1,uint param_2)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  bool bVar9;
  
  uVar4 = param_1;
  if (((int)(param_2 | param_1) < 0) &&
     ((-1 < (int)param_2 || (param_2 = -param_2, (int)param_1 < 0)))) {
    uVar4 = -param_1;
  }
  uVar6 = param_2;
  if (param_2 == 0) {
    pcVar1 = (code *)sw_trap(2);
    (*pcVar1)();
  }
  if (uVar6 <= uVar4) {
    iVar5 = 0;
    if (uVar4 < 0x8000000) {
      do {
        iVar3 = iVar5;
        uVar6 = uVar6 * 0x10;
        iVar5 = iVar3 + 1;
      } while (uVar6 < uVar4 || uVar6 - uVar4 == 0);
      if (iVar3 + 1 != 0) {
        bVar9 = (int)uVar4 < 0;
        goto loc_F00069A4;
      }
    }
    else {
      for (; iVar3 = 1, uVar7 = uVar6, uVar6 < 0x8000000; uVar6 = uVar6 << 4) {
        iVar5 = iVar5 + 1;
      }
      do {
        uVar6 = uVar7;
        iVar2 = iVar3;
        if (uVar4 <= uVar6) goto loc_F0006940;
        iVar3 = iVar2 + 1;
        uVar7 = uVar6 * 2;
      } while (!CARRY4(uVar6,uVar6));
      uVar6 = (uVar6 & 0x7fffffff) + 0x80000000;
loc_F0006940:
      if (0 < iVar2) {
        uVar4 = uVar4 - uVar6;
        iVar3 = iVar2 + -1;
        while( true ) {
          if (iVar3 < 1) break;
          uVar6 = uVar6 >> 1;
          if ((int)uVar4 < 0) {
            uVar4 = uVar4 + uVar6;
            iVar3 = iVar3 + -1;
          }
          else {
            uVar4 = uVar4 - uVar6;
            iVar3 = iVar3 + -1;
          }
        }
      }
      while( true ) {
        iVar3 = iVar5 + -1;
        bVar9 = (int)uVar4 < 0;
        if (iVar5 < 1) break;
loc_F00069A4:
        uVar7 = uVar6 >> 1;
        iVar5 = iVar3;
        if (bVar9) {
          iVar3 = uVar4 + uVar7;
          uVar8 = uVar6 >> 2;
          if (iVar3 < 0 == SCARRY4(uVar4,uVar7)) {
            iVar2 = iVar3 - uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar3 < (int)uVar8) {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
            else {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
          }
          else {
            iVar2 = iVar3 + uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar2 < 0 == SCARRY4(iVar3,uVar8)) {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
            else {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
          }
        }
        else {
          iVar3 = uVar4 - uVar7;
          uVar8 = uVar6 >> 2;
          if ((int)uVar4 < (int)uVar7) {
            iVar2 = iVar3 + uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar2 < 0 == SCARRY4(iVar3,uVar8)) {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
            else {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
          }
          else {
            iVar2 = iVar3 - uVar8;
            uVar4 = uVar6 >> 3;
            if (iVar3 < (int)uVar8) {
              iVar3 = iVar2 + uVar4;
              uVar6 = uVar6 >> 4;
              if (iVar3 < 0 == SCARRY4(iVar2,uVar4)) {
                uVar4 = iVar3 - uVar6;
              }
              else {
                uVar4 = iVar3 + uVar6;
              }
            }
            else {
              uVar6 = uVar6 >> 4;
              if (iVar2 < (int)uVar4) {
                uVar4 = (iVar2 - uVar4) + uVar6;
              }
              else {
                uVar4 = (iVar2 - uVar4) - uVar6;
              }
            }
          }
        }
      }
      if (bVar9) {
        uVar4 = uVar4 + param_2;
      }
    }
  }
  if ((int)param_1 < 0) {
    uVar4 = -uVar4;
  }
  return uVar4;
}
/* GHIDRADEC_FUNCTION index=59 start=0xf0006b40 */

int .stret8(int param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int unaff_i0;
  int iVar3;
  int unaff_fp;
  int unaff_i7;
  
  if ((param_2 & 0xfff) == *(uint *)(unaff_i7 + 8)) {
    iVar3 = *(int *)(unaff_fp + 0x40);
    do {
      uVar1 = param_2 - 4;
      bVar2 = 3 < (int)param_2;
      *(undefined4 *)(iVar3 + uVar1) = *(undefined4 *)(param_1 + uVar1);
      param_2 = uVar1;
    } while (uVar1 != 0 && bVar2);
    return iVar3;
  }
  return unaff_i0;
}
/* GHIDRADEC_FUNCTION index=60 start=0xf0006b80 */

int .stret2(int param_1,uint param_2)

{
  uint uVar1;
  bool bVar2;
  int unaff_i0;
  int iVar3;
  int unaff_fp;
  int unaff_i7;
  
  if ((param_2 & 0xfff) == *(uint *)(unaff_i7 + 8)) {
    iVar3 = *(int *)(unaff_fp + 0x40);
    do {
      uVar1 = param_2 - 2;
      bVar2 = 1 < (int)param_2;
      *(undefined2 *)(iVar3 + uVar1) = *(undefined2 *)(param_1 + uVar1);
      param_2 = uVar1;
    } while (uVar1 != 0 && bVar2);
    return iVar3;
  }
  return unaff_i0;
}
/* GHIDRADEC_FUNCTION index=61 start=0xf0006bc0 */

/* WARNING: Removing unreachable block (ram,0xf0006bc8) */

undefined8 __ip_umul(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  uVar1 = param_2;
  .umul();
  *param_3 = param_1;
  param_3[1] = uVar1;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=62 start=0xf0006be4 */

/* WARNING: Removing unreachable block (ram,0xf0006bec) */

undefined8 __ip_mul(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  uVar1 = param_2;
  .mul();
  *param_3 = param_1;
  param_3[1] = uVar1;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=63 start=0xf0006c08 */

/* WARNING: Removing unreachable block (ram,0xf0006c10) */

void __ip_umulcc(undefined4 param_1,undefined4 param_2,undefined4 *param_3)

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
  .umul();
  *param_3 = param_1;
  param_3[1] = param_2;
  func_0xf0006c84();
  return;
}
/* GHIDRADEC_FUNCTION index=64 start=0xf0006c48 */

/* WARNING: Removing unreachable block (ram,0xf0006c50) */

undefined8 __ip_mulcc(uint param_1,uint param_2,uint *param_3,undefined4 param_4,uint *param_5)

{
  uint uVar1;
  undefined4 unaff_l0;
  int iVar2;
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
  uVar1 = param_2;
  .mul();
  *param_3 = param_1;
  param_3[1] = uVar1;
  iVar2 = (param_1 >> 0x1f) << 3;
  if (param_1 == 0) {
    iVar2 = 4;
  }
  *param_5 = *param_5 & 0xff0fffff | iVar2 << 0x14;
  return CONCAT44(param_2,1);
}
/* GHIDRADEC_FUNCTION index=65 start=0xf0006ca4 */

/* WARNING: Removing unreachable block (ram,0xf0006cbc) */

void __ip_udiv(undefined4 param_1,int param_2,undefined4 param_3,int *param_4)

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
  
  if (param_2 == 0) {
    func_0xf0006e84();
    return;
  }
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
  iVar1 = *param_4;
  sub_F0006E8C(param_1,iVar1,param_2);
  if (iVar1 != 0) {
    func_0xf0006d6c(0xffffffff);
    return;
  }
  func_0xf0006d6c();
  return;
}
/* GHIDRADEC_FUNCTION index=66 start=0xf0006ce0 */

/* WARNING: Removing unreachable block (ram,0xf0006cf8) */

undefined8 __ip_div(uint param_1,int param_2,uint *param_3,int *param_4)

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
  
  if (param_2 == 0) {
    func_0xf0006e84();
    return CONCAT44(param_2,param_1);
  }
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
  iVar1 = *param_4;
  sub_F0006E98(param_1,iVar1,param_2);
  if (iVar1 < 0) {
    if ((iVar1 != -1) || (-1 < (int)param_1)) {
      param_1 = 0x80000000;
    }
  }
  else if ((iVar1 != 0) || (0x7fffffff < param_1)) {
    param_1 = 0x7fffffff;
  }
  *param_3 = param_1;
  return 1;
}
/* GHIDRADEC_FUNCTION index=67 start=0xf0006d7c */

/* WARNING: Removing unreachable block (ram,0xf0006d94) */

void __ip_udivcc(undefined4 param_1,int param_2,undefined4 *param_3,int *param_4)

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
  
  if (param_2 == 0) {
    func_0xf0006e84();
    return;
  }
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
  iVar1 = *param_4;
  sub_F0006E8C(param_1,iVar1,param_2);
  if (iVar1 != 0) {
    param_1 = 0xffffffff;
  }
  *param_3 = param_1;
  func_0xf0006c28(param_1);
  return;
}
/* GHIDRADEC_FUNCTION index=68 start=0xf0006dd4 */

/* WARNING: Removing unreachable block (ram,0xf0006dec) */

uint __ip_divcc(uint param_1,int param_2,uint *param_3,int *param_4)

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
  
  if (param_2 != 0) {
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
    iVar1 = *param_4;
    sub_F0006E98(param_1,iVar1,param_2);
    if (iVar1 < 0) {
      if ((iVar1 != -1) || (-1 < (int)param_1)) {
        param_1 = 0x80000000;
      }
    }
    else if ((iVar1 != 0) || (0x7fffffff < param_1)) {
      param_1 = 0x7fffffff;
    }
    *param_3 = param_1;
    func_0xf0006c68(param_1);
    return param_1;
  }
  return 0xfffffffe;
}
/* GHIDRADEC_FUNCTION index=69 start=0xf0006f88 */

/* WARNING: Control flow encountered unimplemented instructions */
/* WARNING: Removing unreachable block (ram,0xf0007008) */
/* WARNING: Removing unreachable block (ram,0xf000702c) */
/* WARNING: Removing unreachable block (ram,0xf0007050) */
/* WARNING: Removing unreachable block (ram,0xf000709c) */
/* WARNING: Removing unreachable block (ram,0xf0006fec) */
/* WARNING: Removing unreachable block (ram,0xf00070ac) */
/* WARNING: Removing unreachable block (ram,0xf0007060) */
/* WARNING: Removing unreachable block (ram,0xf000703c) */
/* WARNING: Removing unreachable block (ram,0xf0007018) */
/* WARNING: Removing unreachable block (ram,0xf0006fdc) */

void multiply_check(void)

{
  undefined4 unaff_g1;
  undefined8 in_g2_3;
  uint uVar1;
  byte unaff_l0;
  uint *unaff_l1;
  uint uVar2;
  int in_TL;
  
  if ((1 << (unaff_l0 & 0x1f) &
      *(uint *)((uint)(in_TL == 1) * 0x6000 + (uint)(in_TL == 2) * 0x6004 +
                (uint)(in_TL == 3) * 0x6008 + (uint)(in_TL == 4) * 0x600c)) != 0) {
    return;
  }
  uVar2 = *unaff_l1;
  if (uVar2 >> 0x1e != 2) {
    sys_trap();
    return;
  }
  unk_F010A7C0._0_8_ = in_g2_3;
  unk_F010A7C0._8_4_ = unaff_g1;
  if ((uVar2 >> 0xd & 1) == 0) {
    uVar1 = uVar2 & 0x1f;
    sub_F0007114(uVar1,uVar2 << 0x13);
  }
  else {
    uVar1 = (int)(uVar2 << 0x13) >> 0x13;
  }
  sub_F0007114(uVar2 >> 0xe & 0x1f,uVar1);
  uVar2 = uVar2 >> 0x13 & 0x3f;
  if (uVar2 == 10) {
    .umul();
    sub_F00071D8();
  }
  else if (uVar2 == 0xb) {
    .mul();
    sub_F00071D8();
  }
  else if (uVar2 == 0x1a) {
    .umul();
    sub_F00071D8();
  }
  else {
    if (uVar2 != 0x1b) {
      sys_trap();
      return;
    }
    .mul();
    sub_F00071D8();
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=70 start=0xf00072a0 */

uint * _memcpy(uint *param_1,uint *param_2,uint param_3)

{
  undefined uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  uint *puVar6;
  undefined *puVar7;
  uint uVar8;
  uint uVar9;
  
  puVar5 = param_1;
  if ((int)param_3 < 10) {
    puVar7 = (undefined *)((int)param_2 - (int)param_1);
    goto loc_F0007424;
  }
  uVar9 = (uint)param_2 & 3;
  if (uVar9 != 0) {
    if (uVar9 != 2) {
      uVar1 = *(undefined *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(undefined *)param_1 = uVar1;
      puVar5 = (uint *)((int)param_1 + 1);
      param_3 = param_3 - 1;
      if (uVar9 == 3) goto loc_F0007300;
    }
    uVar2 = *(undefined2 *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    *(char *)puVar5 = (char)((word)uVar2 >> 8);
    *(char *)((int)puVar5 + 1) = (char)uVar2;
    puVar5 = (uint *)((int)puVar5 + 2);
    param_3 = param_3 - 2;
  }
loc_F0007300:
  uVar9 = (uint)puVar5 & 3;
  if (uVar9 == 0) {
    puVar7 = (undefined *)((int)param_2 - (int)puVar5);
    uVar9 = param_3 & 0xfffffffc;
    do {
      uVar8 = uVar9 - 4;
      *puVar5 = *(uint *)(puVar7 + (int)puVar5);
      bVar3 = 3 < (int)uVar9;
      puVar5 = puVar5 + 1;
      uVar9 = uVar8;
    } while (uVar8 != 0 && bVar3);
    param_3 = param_3 & 3;
  }
  else if (uVar9 == 2) {
    uVar8 = *param_2;
    *(sword *)puVar5 = (sword)(uVar8 >> 0x10);
    puVar5 = (uint *)((int)puVar5 + 2);
    uVar9 = param_3 - 2 & 0xfffffffc;
    puVar7 = (undefined *)((int)param_2 + (4 - (int)puVar5));
    do {
      uVar4 = uVar8 << 0x10;
      uVar8 = *(uint *)(puVar7 + (int)puVar5);
      uVar9 = uVar9 - 4;
      *puVar5 = uVar8 >> 0x10 | uVar4;
      puVar5 = puVar5 + 1;
    } while (uVar9 != 0);
    puVar7 = puVar7 + -2;
    param_3 = param_3 - 2 & 3;
  }
  else {
    uVar8 = *param_2;
    *(char *)puVar5 = (char)(uVar8 >> 0x18);
    puVar6 = (uint *)((int)puVar5 + 1);
    if (uVar9 == 3) {
      uVar9 = param_3 - 1 & 0xfffffffc;
      puVar7 = (undefined *)((int)param_2 + (4 - (int)puVar6));
      do {
        uVar4 = uVar8 << 8;
        uVar8 = *(uint *)(puVar7 + (int)puVar6);
        uVar9 = uVar9 - 4;
        *puVar6 = uVar8 >> 0x18 | uVar4;
        puVar6 = puVar6 + 1;
      } while (uVar9 != 0);
      puVar7 = puVar7 + -3;
      puVar5 = puVar6;
      param_3 = param_3 - 1 & 3;
    }
    else {
      *(sword *)puVar6 = (sword)(uVar8 >> 8);
      puVar5 = (uint *)((int)puVar5 + 3);
      uVar9 = param_3 - 3 & 0xfffffffc;
      puVar7 = (undefined *)((int)param_2 + (4 - (int)puVar5));
      do {
        uVar4 = uVar8 << 0x18;
        uVar8 = *(uint *)(puVar7 + (int)puVar5);
        uVar9 = uVar9 - 4;
        *puVar5 = uVar8 >> 8 | uVar4;
        puVar5 = puVar5 + 1;
      } while (uVar9 != 0);
      puVar7 = puVar7 + -1;
      param_3 = param_3 - 3 & 3;
    }
  }
loc_F0007424:
  while (0 < (int)param_3) {
    *(undefined *)puVar5 = puVar7[(int)puVar5];
    puVar5 = (uint *)((int)puVar5 + 1);
    param_3 = param_3 - 1;
  }
  return param_1;
}
/* GHIDRADEC_FUNCTION index=71 start=0xf0007438 */

int _strlen(uint *param_1)

{
  char cVar1;
  word wVar2;
  int iVar3;
  uint uVar4;
  
  uVar4 = (uint)param_1 & 3;
  iVar3 = 0;
  if (uVar4 != 0) {
    if (uVar4 != 2) {
      cVar1 = *(char *)param_1;
      param_1 = (uint *)((int)param_1 + 1);
      if (uVar4 == 3) {
        if (cVar1 == '\0') {
          return 0;
        }
        iVar3 = 1;
        goto loc_F00074B8;
      }
      if (cVar1 == '\0') {
        return 0;
      }
      iVar3 = 1;
    }
    wVar2 = *(word *)param_1;
    param_1 = (uint *)((int)param_1 + 2);
    if (wVar2 >> 8 == 0) {
      return iVar3;
    }
    if ((wVar2 & 0xff) == 0) {
      return iVar3 + 1;
    }
    iVar3 = iVar3 + 2;
  }
loc_F00074B8:
  while( true ) {
    while( true ) {
      uVar4 = *param_1;
      param_1 = param_1 + 1;
      if (((uVar4 + 0x7efefeff ^ uVar4) & 0x81010100) != 0x81010100) break;
      iVar3 = iVar3 + 4;
    }
    if ((uVar4 & 0xff000000) == 0) {
      return iVar3;
    }
    if ((uVar4 & 0xff0000) == 0) {
      return iVar3 + 1;
    }
    if ((uVar4 & 0xff00) == 0) break;
    if ((uVar4 & 0xff) == 0) {
      return iVar3 + 3;
    }
    iVar3 = iVar3 + 4;
  }
  return iVar3 + 2;
}
/* GHIDRADEC_FUNCTION index=72 start=0xf0007528 */

undefined8 _strcpy(uint *param_1,uint *param_2)

{
  word wVar1;
  uint uVar2;
  char cVar4;
  undefined2 uVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  uint *puVar5;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  uVar2 = (uint)param_2 & 3;
  puVar5 = param_1;
  if (uVar2 != 0) {
    if (uVar2 != 2) {
      cVar4 = *(char *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(char *)param_1 = cVar4;
      if (uVar2 == 3) {
        puVar5 = (uint *)((int)param_1 + 1);
        if (cVar4 == '\0') goto locret_F00078C0;
        goto loc_F00075A0;
      }
      puVar5 = (uint *)((int)param_1 + 1);
      if (cVar4 == '\0') goto locret_F00078C0;
    }
    wVar1 = *(word *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    *(char *)puVar5 = (char)(wVar1 >> 8);
    if (wVar1 >> 8 == 0) goto locret_F00078C0;
    *(char *)((int)puVar5 + 1) = (char)wVar1;
    puVar5 = (uint *)((int)puVar5 + 2);
    if ((wVar1 & 0xff) == 0) goto locret_F00078C0;
  }
loc_F00075A0:
  uVar2 = (uint)puVar5 & 3;
  if (uVar2 == 0) {
    do {
      while( true ) {
        uVar2 = *param_2;
        param_2 = param_2 + 1;
        if (((uVar2 + 0x7efefeff ^ uVar2) & 0x81010100) != 0x81010100) break;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
      }
      if ((uVar2 & 0xff000000) == 0) goto loc_F00078C8;
      if ((uVar2 & 0xff0000) == 0) goto loc_F00078D4;
      if ((uVar2 & 0xff00) == 0) goto loc_F00078E4;
      *puVar5 = uVar2;
      puVar5 = puVar5 + 1;
    } while ((uVar2 & 0xff) != 0);
    goto locret_F00078C0;
  }
  if (uVar2 == 2) {
    uVar8 = *param_2;
    param_2 = param_2 + 1;
    if ((uVar8 & 0xff000000) == 0) goto loc_F00078C8;
    uVar2 = uVar8;
    if ((uVar8 & 0xff0000) == 0) {
loc_F00078D4:
      *(sword *)puVar5 = (sword)(uVar2 >> 0x10);
      return CONCAT44(param_2,param_1);
    }
    if ((uVar8 & 0xff00) == 0) {
loc_F00078E4:
      *(sword *)puVar5 = (sword)(uVar2 >> 0x10);
      *(char *)((int)puVar5 + 2) = '\0';
      return CONCAT44(param_2,param_1);
    }
    uVar3 = (undefined2)(uVar8 >> 0x10);
    if ((uVar8 & 0xff) == 0) {
      *(undefined2 *)puVar5 = uVar3;
      *(sword *)((int)puVar5 + 2) = (sword)uVar8;
    }
    else {
      *(undefined2 *)puVar5 = uVar3;
      puVar5 = (uint *)((int)puVar5 + 2);
      do {
        while( true ) {
          uVar7 = uVar8 << 0x10;
          if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
          if ((uVar7 & 0xff0000) == 0) goto loc_F00078F8;
          uVar8 = *param_2;
          param_2 = param_2 + 1;
          uVar6 = uVar8 >> 0x10;
          uVar2 = uVar6 | uVar7;
          if (((uVar2 + 0x7efefeff ^ uVar2) & 0x81010100) != 0x81010100) break;
          *puVar5 = uVar2;
          puVar5 = puVar5 + 1;
        }
        if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
        if ((uVar7 & 0xff0000) == 0) goto loc_F00078D4;
        if ((uVar6 & 0xff00) == 0) goto loc_F00078E4;
        *puVar5 = uVar2;
        puVar5 = puVar5 + 1;
      } while ((uVar6 & 0xff) != 0);
    }
    goto locret_F00078C0;
  }
  uVar6 = *param_2;
  param_2 = param_2 + 1;
  bVar9 = (uVar6 & 0xff000000) == 0;
  cVar4 = (char)(uVar6 >> 0x18);
  uVar8 = uVar6;
  if (uVar2 == 3) {
    if (bVar9) goto loc_F00078C8;
    if ((uVar6 & 0xff0000) != 0) {
      if ((uVar6 & 0xff00) != 0) {
        if ((uVar6 & 0xff) != 0) {
          *(char *)puVar5 = cVar4;
          puVar5 = (uint *)((int)puVar5 + 1);
loc_F0007708:
          do {
            uVar7 = uVar6 << 8;
            if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
            if ((uVar7 & 0xff0000) == 0) {
loc_F00078F8:
              *(sword *)puVar5 = (sword)(uVar7 >> 0x10);
              return CONCAT44(param_2,param_1);
            }
            if ((uVar7 & 0xff00) == 0) {
              *(sword *)puVar5 = (sword)(uVar6 >> 8);
              *(char *)((int)puVar5 + 2) = '\0';
              return CONCAT44(param_2,param_1);
            }
            uVar6 = *param_2;
            param_2 = param_2 + 1;
            uVar8 = uVar6 >> 0x18 | uVar7;
            if (((uVar8 + 0x7efefeff ^ uVar8) & 0x81010100) == 0x81010100) {
              *puVar5 = uVar8;
              puVar5 = puVar5 + 1;
              goto loc_F0007708;
            }
            if ((uVar7 & 0xff000000) == 0) goto loc_F00078C8;
            if ((uVar7 & 0xff0000) == 0) goto loc_F00076AC;
            if ((uVar7 & 0xff00) == 0) goto loc_F00076A4;
            *puVar5 = uVar8;
            puVar5 = puVar5 + 1;
          } while (uVar6 >> 0x18 != 0);
          goto locret_F00078C0;
        }
        goto loc_F00076A0;
      }
      goto loc_F00076A4;
    }
  }
  else {
    if (bVar9) {
loc_F00078C8:
      *(char *)puVar5 = '\0';
      return CONCAT44(param_2,param_1);
    }
    if ((uVar6 & 0xff0000) != 0) {
      if ((uVar6 & 0xff00) != 0) {
        if ((uVar6 & 0xff) != 0) {
          *(char *)puVar5 = cVar4;
          *(sword *)((int)puVar5 + 1) = (sword)(uVar6 >> 8);
          puVar5 = (uint *)((int)puVar5 + 3);
          do {
            while( true ) {
              uVar2 = uVar6 << 0x18;
              if (uVar2 == 0) goto loc_F00078C8;
              uVar6 = *param_2;
              param_2 = param_2 + 1;
              uVar7 = uVar6 >> 8;
              uVar8 = uVar7 | uVar2;
              if (((uVar8 + 0x7efefeff ^ uVar8) & 0x81010100) != 0x81010100) break;
              *puVar5 = uVar8;
              puVar5 = puVar5 + 1;
            }
            if (uVar2 == 0) goto loc_F00078C8;
            if ((uVar7 & 0xff0000) == 0) goto loc_F00076AC;
            if ((uVar7 & 0xff00) == 0) goto loc_F00076A4;
            *puVar5 = uVar8;
            puVar5 = puVar5 + 1;
          } while ((uVar7 & 0xff) != 0);
          goto locret_F00078C0;
        }
loc_F00076A0:
        *(char *)((int)puVar5 + 3) = (char)uVar6;
      }
loc_F00076A4:
      *(char *)((int)puVar5 + 2) = (char)(uVar8 >> 8);
    }
  }
loc_F00076AC:
  *(char *)puVar5 = (char)(uVar8 >> 0x18);
  *(char *)((int)puVar5 + 1) = (char)(uVar8 >> 0x10);
locret_F00078C0:
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=73 start=0xf000791c */

/* WARNING: Control flow encountered unimplemented instructions */

void _strncpy(uint *param_1,uint *param_2,int param_3)

{
  word wVar1;
  uint uVar2;
  char cVar3;
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
  int iVar4;
  undefined4 unaff_i3;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 unaff_i4;
  undefined2 uVar8;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar9;
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
  if (param_3 < 9) {
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
    halt_unimplemented();
  }
  uVar2 = (uint)param_2 & 3;
  if (uVar2 != 0) {
    if (uVar2 != 2) {
      cVar3 = *(char *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      param_3 = param_3 + -1;
      *(char *)param_1 = cVar3;
      if (uVar2 == 3) {
        param_1 = (uint *)((int)param_1 + 1);
        if (cVar3 == '\0') {
          halt_unimplemented();
        }
        goto loc_F00079AC;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if (cVar3 == '\0') {
        halt_unimplemented();
      }
    }
    wVar1 = *(word *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    param_3 = param_3 + -2;
    *(char *)param_1 = (char)(wVar1 >> 8);
    if (wVar1 >> 8 == 0) {
      halt_unimplemented();
    }
    *(char *)((int)param_1 + 1) = (char)wVar1;
    param_1 = (uint *)((int)param_1 + 2);
    if ((wVar1 & 0xff) == 0) {
      halt_unimplemented();
    }
  }
loc_F00079AC:
  uVar2 = (uint)param_1 & 3;
  if (uVar2 == 0) {
    do {
      while( true ) {
        iVar4 = param_3 + -4;
        if (iVar4 == 0 || param_3 < 4) {
          halt_unimplemented();
        }
        uVar2 = *param_2;
        param_2 = param_2 + 1;
        param_3 = iVar4;
        if (((uVar2 + 0x7efefeff ^ uVar2) & 0x81010100) != 0x81010100) break;
        *param_1 = uVar2;
        param_1 = param_1 + 1;
      }
      if ((uVar2 & 0xff000000) == 0) {
        *(char *)param_1 = '\0';
        halt_unimplemented();
      }
      uVar8 = (undefined2)(uVar2 >> 0x10);
      if ((uVar2 & 0xff0000) == 0) {
        *(undefined2 *)param_1 = uVar8;
        halt_unimplemented();
      }
      if ((uVar2 & 0xff00) == 0) {
        *(undefined2 *)param_1 = uVar8;
        *(char *)((int)param_1 + 2) = '\0';
        halt_unimplemented();
      }
      *param_1 = uVar2;
      param_1 = param_1 + 1;
    } while ((uVar2 & 0xff) != 0);
  }
  else if (uVar2 == 2) {
    uVar2 = *param_2;
    param_2 = param_2 + 1;
    if ((uVar2 & 0xff000000) == 0) {
      *(char *)param_1 = '\0';
    }
    else {
      uVar8 = (undefined2)(uVar2 >> 0x10);
      if ((uVar2 & 0xff0000) == 0) {
        *(undefined2 *)param_1 = uVar8;
      }
      else if ((uVar2 & 0xff00) == 0) {
        *(undefined2 *)param_1 = uVar8;
        *(char *)((int)param_1 + 2) = '\0';
      }
      else if ((uVar2 & 0xff) == 0) {
        *(undefined2 *)param_1 = uVar8;
        *(sword *)((int)param_1 + 2) = (sword)uVar2;
      }
      else {
        *(undefined2 *)param_1 = uVar8;
        param_1 = (uint *)((int)param_1 + 2);
        iVar4 = param_3 + -2;
        do {
          while( true ) {
            if (iVar4 < 4) {
              halt_unimplemented();
            }
            uVar5 = uVar2 << 0x10;
            if ((uVar5 & 0xff000000) == 0) {
              *(char *)param_1 = '\0';
              halt_unimplemented();
            }
            uVar8 = (undefined2)uVar2;
            if ((uVar5 & 0xff0000) == 0) {
              *(undefined2 *)param_1 = uVar8;
              halt_unimplemented();
            }
            uVar2 = *param_2;
            param_2 = param_2 + 1;
            uVar6 = uVar2 >> 0x10;
            uVar7 = uVar6 | uVar5;
            if (((uVar7 + 0x7efefeff ^ uVar7) & 0x81010100) != 0x81010100) break;
            *param_1 = uVar7;
            param_1 = param_1 + 1;
            iVar4 = iVar4 + -4;
          }
          if ((uVar5 & 0xff000000) == 0) {
            *(char *)param_1 = '\0';
            halt_unimplemented();
          }
          if ((uVar5 & 0xff0000) == 0) {
            *(undefined2 *)param_1 = uVar8;
            halt_unimplemented();
          }
          if ((uVar6 & 0xff00) == 0) {
            *(undefined2 *)param_1 = uVar8;
            *(char *)((int)param_1 + 2) = '\0';
            halt_unimplemented();
          }
          *param_1 = uVar7;
          param_1 = param_1 + 1;
          iVar4 = iVar4 + -4;
        } while ((uVar6 & 0xff) != 0);
      }
    }
  }
  else {
    uVar5 = *param_2;
    param_2 = param_2 + 1;
    bVar9 = (uVar5 & 0xff000000) != 0;
    uVar8 = (undefined2)(uVar5 >> 8);
    cVar3 = (char)(uVar5 >> 0x18);
    if (uVar2 == 3) {
      if (bVar9) {
        if ((uVar5 & 0xff0000) == 0) {
          *(char *)param_1 = cVar3;
          *(char *)((int)param_1 + 1) = '\0';
        }
        else if ((uVar5 & 0xff00) == 0) {
          *(undefined2 *)((int)param_1 + 1) = uVar8;
          *(char *)param_1 = cVar3;
        }
        else if ((uVar5 & 0xff) == 0) {
          *(char *)param_1 = cVar3;
          *(undefined2 *)((int)param_1 + 1) = uVar8;
          *(char *)((int)param_1 + 3) = '\0';
        }
        else {
          *(char *)param_1 = cVar3;
          param_1 = (uint *)((int)param_1 + 1);
          iVar4 = param_3 + -1;
          do {
            while( true ) {
              uVar2 = uVar5 << 8;
              if (iVar4 < 4) {
                halt_unimplemented();
              }
              if ((uVar2 & 0xff000000) == 0) {
                *(char *)param_1 = '\0';
                halt_unimplemented();
              }
              uVar8 = (undefined2)(uVar5 >> 8);
              if ((uVar2 & 0xff0000) == 0) {
                *(undefined2 *)param_1 = uVar8;
                halt_unimplemented();
              }
              if ((uVar2 & 0xff00) == 0) {
                *(undefined2 *)param_1 = uVar8;
                *(char *)((int)param_1 + 2) = '\0';
                halt_unimplemented();
              }
              uVar5 = *param_2;
              param_2 = param_2 + 1;
              uVar6 = uVar5 >> 0x18 | uVar2;
              if (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100) break;
              *param_1 = uVar6;
              param_1 = param_1 + 1;
              iVar4 = iVar4 + -4;
            }
            if ((uVar2 & 0xff000000) == 0) {
              *(char *)param_1 = '\0';
              halt_unimplemented();
            }
            if ((uVar2 & 0xff0000) == 0) {
              *(undefined2 *)param_1 = uVar8;
              halt_unimplemented();
            }
            if ((uVar2 & 0xff00) == 0) {
              *(undefined2 *)param_1 = uVar8;
              *(char *)((int)param_1 + 2) = '\0';
              halt_unimplemented();
            }
            *param_1 = uVar6;
            param_1 = param_1 + 1;
            iVar4 = iVar4 + -4;
          } while (uVar5 >> 0x18 != 0);
        }
      }
      else {
        *(char *)param_1 = '\0';
      }
    }
    else if (bVar9) {
      if ((uVar5 & 0xff0000) == 0) {
        *(char *)param_1 = cVar3;
        *(char *)((int)param_1 + 1) = '\0';
      }
      else if ((uVar5 & 0xff00) == 0) {
        *(undefined2 *)((int)param_1 + 1) = uVar8;
        *(char *)param_1 = cVar3;
      }
      else if ((uVar5 & 0xff) == 0) {
        *(char *)param_1 = cVar3;
        *(undefined2 *)((int)param_1 + 1) = uVar8;
        *(char *)((int)param_1 + 3) = '\0';
      }
      else {
        *(char *)param_1 = cVar3;
        *(undefined2 *)((int)param_1 + 1) = uVar8;
        param_1 = (uint *)((int)param_1 + 3);
        iVar4 = param_3 + -3;
        do {
          while( true ) {
            uVar2 = uVar5 << 0x18;
            if (iVar4 < 4) {
              halt_unimplemented();
            }
            if (uVar2 == 0) {
              *(char *)param_1 = '\0';
              halt_unimplemented();
            }
            uVar5 = *param_2;
            param_2 = param_2 + 1;
            uVar6 = uVar5 >> 8;
            uVar7 = uVar6 | uVar2;
            if (((uVar7 + 0x7efefeff ^ uVar7) & 0x81010100) != 0x81010100) break;
            *param_1 = uVar7;
            param_1 = param_1 + 1;
            iVar4 = iVar4 + -4;
          }
          if (uVar2 == 0) {
            *(char *)param_1 = '\0';
            halt_unimplemented();
          }
          uVar8 = (undefined2)(uVar7 >> 0x10);
          if ((uVar6 & 0xff0000) == 0) {
            *(undefined2 *)param_1 = uVar8;
            halt_unimplemented();
          }
          if ((uVar6 & 0xff00) == 0) {
            *(undefined2 *)param_1 = uVar8;
            *(char *)((int)param_1 + 2) = '\0';
            halt_unimplemented();
          }
          *param_1 = uVar7;
          param_1 = param_1 + 1;
          iVar4 = iVar4 + -4;
        } while ((uVar6 & 0xff) != 0);
      }
    }
    else {
      *(char *)param_1 = '\0';
    }
  }
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}
/* GHIDRADEC_FUNCTION index=74 start=0xf0007fac */

int _ffs(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (param_1 != 0) {
    do {
      iVar2 = iVar2 + 1;
      uVar1 = param_1 & 1;
      param_1 = param_1 >> 1;
    } while (uVar1 == 0);
  }
  return iVar2;
}
/* GHIDRADEC_FUNCTION index=75 start=0xf0007fd0 */

void _memmove(uint *param_1,uint *param_2,uint param_3)

{
  undefined uVar1;
  undefined2 uVar2;
  bool bVar3;
  uint uVar4;
  uint *puVar5;
  undefined *puVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if ((int)param_2 <= (int)param_1) {
    iVar7 = (int)param_2 - (int)param_1;
    if (iVar7 < 0) {
      iVar7 = -iVar7;
    }
    if (iVar7 < (int)param_3) {
      puVar6 = (undefined *)((int)param_1 + param_3);
      iVar7 = param_3 - (int)puVar6;
      do {
        puVar6 = puVar6 + -1;
        uVar9 = param_3 - 1;
        bVar3 = 0 < (int)param_3;
        *puVar6 = puVar6[(int)((int)param_2 + iVar7)];
        param_3 = uVar9;
      } while (uVar9 != 0 && bVar3);
      return;
    }
  }
  uVar9 = (uint)param_2 & 3;
  if ((int)param_3 < 10) {
    puVar6 = (undefined *)((int)param_2 - (int)param_1);
    goto loc_F0008170;
  }
  puVar5 = param_1;
  if (uVar9 != 0) {
    if (uVar9 != 2) {
      uVar1 = *(undefined *)param_2;
      param_2 = (uint *)((int)param_2 + 1);
      *(undefined *)param_1 = uVar1;
      param_1 = (uint *)((int)param_1 + 1);
      param_3 = param_3 - 1;
      puVar5 = param_1;
      if (uVar9 == 3) goto loc_F000804C;
    }
    uVar2 = *(undefined2 *)param_2;
    param_2 = (uint *)((int)param_2 + 2);
    *(char *)param_1 = (char)((word)uVar2 >> 8);
    *(char *)((int)param_1 + 1) = (char)uVar2;
    param_3 = param_3 - 2;
    puVar5 = (uint *)((int)param_1 + 2);
  }
loc_F000804C:
  uVar9 = (uint)puVar5 & 3;
  if (uVar9 == 0) {
    puVar6 = (undefined *)((int)param_2 - (int)puVar5);
    param_1 = puVar5;
    uVar9 = param_3 & 0xfffffffc;
    do {
      uVar8 = uVar9 - 4;
      *param_1 = *(uint *)(puVar6 + (int)param_1);
      bVar3 = 3 < (int)uVar9;
      param_1 = param_1 + 1;
      uVar9 = uVar8;
    } while (uVar8 != 0 && bVar3);
    param_3 = param_3 & 3;
  }
  else if (uVar9 == 2) {
    uVar8 = *param_2;
    *(sword *)puVar5 = (sword)(uVar8 >> 0x10);
    param_1 = (uint *)((int)puVar5 + 2);
    uVar9 = param_3 - 2 & 0xfffffffc;
    puVar6 = (undefined *)((int)param_2 + (4 - (int)param_1));
    do {
      uVar4 = uVar8 << 0x10;
      uVar8 = *(uint *)(puVar6 + (int)param_1);
      uVar9 = uVar9 - 4;
      *param_1 = uVar8 >> 0x10 | uVar4;
      param_1 = param_1 + 1;
    } while (uVar9 != 0);
    puVar6 = puVar6 + -2;
    param_3 = param_3 - 2 & 3;
  }
  else {
    uVar8 = *param_2;
    *(char *)puVar5 = (char)(uVar8 >> 0x18);
    param_1 = (uint *)((int)puVar5 + 1);
    if (uVar9 == 3) {
      uVar9 = param_3 - 1 & 0xfffffffc;
      puVar6 = (undefined *)((int)param_2 + (4 - (int)param_1));
      do {
        uVar4 = uVar8 << 8;
        uVar8 = *(uint *)(puVar6 + (int)param_1);
        uVar9 = uVar9 - 4;
        *param_1 = uVar8 >> 0x18 | uVar4;
        param_1 = param_1 + 1;
      } while (uVar9 != 0);
      puVar6 = puVar6 + -3;
      param_3 = param_3 - 1 & 3;
    }
    else {
      *(sword *)param_1 = (sword)(uVar8 >> 8);
      param_1 = (uint *)((int)puVar5 + 3);
      uVar9 = param_3 - 3 & 0xfffffffc;
      puVar6 = (undefined *)((int)param_2 + (4 - (int)param_1));
      do {
        uVar4 = uVar8 << 0x18;
        uVar8 = *(uint *)(puVar6 + (int)param_1);
        uVar9 = uVar9 - 4;
        *param_1 = uVar8 >> 8 | uVar4;
        param_1 = param_1 + 1;
      } while (uVar9 != 0);
      puVar6 = puVar6 + -1;
      param_3 = param_3 - 3 & 3;
    }
  }
loc_F0008170:
  while (0 < (int)param_3) {
    *(undefined *)param_1 = puVar6[(int)param_1];
    param_1 = (uint *)((int)param_1 + 1);
    param_3 = param_3 - 1;
  }
  return;
}
/* GHIDRADEC_FUNCTION index=76 start=0xf00081ac */

sqword _strcmp(char *param_1,uint *param_2)

{
  word wVar1;
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
  uint *puVar3;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar4;
  uint uVar5;
  undefined4 unaff_i4;
  uint uVar6;
  undefined4 unaff_i5;
  uint uVar7;
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
  while( true ) {
    uVar6 = (uint)param_2 & 3;
    if (((uint)param_1 & 3) == 0) break;
    uVar6 = (uint)*param_1;
    uVar7 = (uint)(char)*(byte *)param_2;
    param_1 = param_1 + 1;
    puVar3 = (uint *)((int)param_2 + 1);
    if (uVar6 != uVar7) goto loc_F00084CC;
    param_2 = puVar3;
    if (uVar6 == 0) goto locret_F0008468;
  }
  if (uVar6 == 0) {
    uVar7 = *param_2;
    puVar3 = param_2;
    while( true ) {
      uVar6 = *(uint *)((int)puVar3 + ((int)param_1 - (int)param_2));
      puVar3 = puVar3 + 1;
      if ((uVar6 != uVar7) || (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100)) break;
      uVar7 = *puVar3;
    }
  }
  else if (uVar6 == 2) {
    uVar5 = *(word *)param_2 | 0xffff0000;
    puVar3 = (uint *)((int)param_2 + 2);
    iVar2 = (int)param_1 - (int)puVar3;
    uVar4 = (uint)*(word *)param_2;
    do {
      if (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) == 0x81010100) {
        uVar5 = *puVar3;
      }
      else {
        uVar5 = 0;
      }
      uVar6 = *(uint *)((int)puVar3 + iVar2);
      puVar3 = puVar3 + 1;
      uVar7 = uVar5 >> 0x10 | uVar4 << 0x10;
    } while ((uVar6 == uVar7) &&
            (uVar4 = uVar5, ((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) == 0x81010100));
  }
  else {
    uVar4 = *(byte *)param_2 | 0xffffff00;
    puVar3 = (uint *)((int)param_2 + 1);
    uVar7 = (uint)*(byte *)param_2 << 0x18;
    if (uVar6 == 1) {
      wVar1 = *(word *)puVar3;
      uVar4 = (uint)wVar1 | uVar4 << 0x10;
      puVar3 = (uint *)((int)param_2 + 3);
      uVar7 = uVar7 | (uint)wVar1 << 8;
      iVar2 = (int)param_1 - (int)puVar3;
      while( true ) {
        if (((uVar4 + 0x7efefeff ^ uVar4) & 0x81010100) == 0x81010100) {
          uVar4 = *puVar3;
        }
        else {
          uVar4 = 0;
        }
        uVar6 = *(uint *)(iVar2 + (int)puVar3);
        puVar3 = puVar3 + 1;
        uVar7 = uVar4 >> 0x18 | uVar7;
        if ((uVar6 != uVar7) || (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100)) break;
        uVar7 = uVar4 << 8;
      }
    }
    else {
      iVar2 = (int)param_1 - (int)puVar3;
      while( true ) {
        if (((uVar4 + 0x7efefeff ^ uVar4) & 0x81010100) == 0x81010100) {
          uVar4 = *puVar3;
        }
        else {
          uVar4 = 0;
        }
        uVar6 = *(uint *)(iVar2 + (int)puVar3);
        puVar3 = puVar3 + 1;
        uVar7 = uVar4 >> 8 | uVar7;
        if ((uVar6 != uVar7) || (((uVar6 + 0x7efefeff ^ uVar6) & 0x81010100) != 0x81010100)) break;
        uVar7 = uVar4 << 0x18;
      }
    }
  }
  iVar2 = ((int)uVar6 >> 0x18) - ((int)uVar7 >> 0x18);
  if (iVar2 == 0) {
    if (((int)uVar6 >> 0x18 & 0xffU) == 0) {
locret_F0008468:
      return ZEXT48(puVar3) << 0x20;
    }
    uVar4 = (int)(uVar6 << 8) >> 0x18;
    iVar2 = uVar4 - ((int)(uVar7 << 8) >> 0x18);
    if (iVar2 == 0) {
      if ((uVar4 & 0xff) == 0) goto locret_F0008468;
      uVar4 = (int)(uVar6 << 0x10) >> 0x18;
      iVar2 = uVar4 - ((int)(uVar7 << 0x10) >> 0x18);
      if (iVar2 == 0) {
        if ((uVar4 & 0xff) == 0) goto locret_F0008468;
loc_F00084CC:
        iVar2 = (int)(char)uVar6 - (int)(char)uVar7;
      }
    }
  }
  return CONCAT44(puVar3,iVar2);
}
/* GHIDRADEC_FUNCTION index=77 start=0xf00084e8 */

sqword _strncmp(char *param_1,uint *param_2,int param_3)

{
  word wVar1;
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
  uint *puVar3;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  uint uVar4;
  undefined4 unaff_i4;
  uint uVar5;
  undefined4 unaff_i5;
  uint uVar6;
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
  if (7 < param_3) {
    do {
      uVar5 = (uint)param_2 & 3;
      puVar3 = param_2;
      if (((uint)param_1 & 3) == 0) {
        if (uVar5 == 0) {
          iVar2 = (int)param_1 - (int)param_2;
          uVar6 = *param_2;
          goto loc_F0008740;
        }
        if (uVar5 == 2) {
          uVar4 = (uint)*(word *)param_2;
          puVar3 = (uint *)((int)param_2 + 2);
          iVar2 = (int)param_1 - (int)puVar3;
          goto loc_F00086B0;
        }
        puVar3 = (uint *)((int)param_2 + 1);
        uVar6 = (uint)*(byte *)param_2 << 0x18;
        if (uVar5 != 1) {
          iVar2 = (int)param_1 - (int)puVar3;
          goto loc_F0008578;
        }
        wVar1 = *(word *)puVar3;
        puVar3 = (uint *)((int)param_2 + 3);
        uVar6 = uVar6 | (uint)wVar1 << 8;
        iVar2 = (int)param_1 - (int)puVar3;
        goto loc_F0008618;
      }
      param_3 = param_3 + -1;
      if (param_3 < 0) break;
      uVar5 = (uint)*param_1;
      uVar6 = (uint)(char)*(byte *)param_2;
      param_1 = param_1 + 1;
      puVar3 = (uint *)((int)param_2 + 1);
      if (uVar5 != uVar6) goto loc_F0008810;
      param_2 = puVar3;
    } while (uVar5 != 0);
    goto locret_F00087AC;
  }
  iVar2 = (int)param_1 - (int)param_2;
  puVar3 = param_2;
loc_F0008830:
  do {
    param_3 = param_3 + -1;
    if (param_3 < 0) break;
    uVar5 = (uint)(char)*(byte *)((int)puVar3 + iVar2);
    uVar6 = (uint)(char)*(byte *)puVar3;
    puVar3 = (uint *)((int)puVar3 + 1);
    if (uVar5 != uVar6) goto loc_F0008810;
  } while (uVar5 != 0);
locret_F00087AC:
  return ZEXT48(puVar3) << 0x20;
loc_F0008740:
  if (param_3 + -4 < 0) goto loc_F0008830;
  uVar5 = *(uint *)((int)puVar3 + iVar2);
  puVar3 = puVar3 + 1;
  if ((uVar5 != uVar6) || (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100))
  goto loc_F00087B4;
  uVar6 = *puVar3;
  param_3 = param_3 + -4;
  goto loc_F0008740;
  while( true ) {
    uVar5 = *(uint *)((int)puVar3 + iVar2);
    puVar3 = puVar3 + 1;
    uVar6 = uVar4 >> 0x10 | uVar6;
    if ((uVar5 != uVar6) ||
       (param_3 = param_3 + -4, ((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100)) break;
loc_F00086B0:
    uVar6 = uVar4 << 0x10;
    uVar4 = *puVar3;
    if (param_3 < 4) {
      puVar3 = (uint *)((int)puVar3 + -2);
      iVar2 = iVar2 + 2;
      goto loc_F0008830;
    }
  }
loc_F00087B4:
  iVar2 = ((int)uVar5 >> 0x18) - ((int)uVar6 >> 0x18);
  if (iVar2 != 0) {
locret_F0008824:
    return CONCAT44(puVar3,iVar2);
  }
  if (((int)uVar5 >> 0x18 & 0xffU) != 0) {
    uVar4 = (int)(uVar5 << 8) >> 0x18;
    iVar2 = uVar4 - ((int)(uVar6 << 8) >> 0x18);
    if (iVar2 == 0) {
      if ((uVar4 & 0xff) == 0) goto locret_F00087AC;
      uVar4 = (int)(uVar5 << 0x10) >> 0x18;
      iVar2 = uVar4 - ((int)(uVar6 << 0x10) >> 0x18);
      if (iVar2 == 0) {
        if ((uVar4 & 0xff) == 0) goto locret_F00087AC;
loc_F0008810:
        iVar2 = (int)(char)uVar5 - (int)(char)uVar6;
      }
    }
    goto locret_F0008824;
  }
  goto locret_F00087AC;
loc_F0008618:
  uVar4 = *puVar3;
  if (param_3 < 4) goto loc_f0008624;
  uVar5 = *(uint *)(iVar2 + (int)puVar3);
  puVar3 = puVar3 + 1;
  uVar6 = uVar4 >> 0x18 | uVar6;
  if ((uVar5 != uVar6) || (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100))
  goto loc_F00087B4;
  uVar6 = uVar4 << 8;
  param_3 = param_3 + -4;
  goto loc_F0008618;
loc_f0008624:
  puVar3 = (uint *)((int)puVar3 + -3);
  iVar2 = iVar2 + 3;
  goto loc_F0008830;
loc_F0008578:
  uVar4 = *puVar3;
  if (param_3 < 4) goto loc_f0008584;
  uVar5 = *(uint *)(iVar2 + (int)puVar3);
  puVar3 = puVar3 + 1;
  uVar6 = uVar4 >> 8 | uVar6;
  if ((uVar5 != uVar6) || (((uVar5 + 0x7efefeff ^ uVar5) & 0x81010100) != 0x81010100))
  goto loc_F00087B4;
  uVar6 = uVar4 << 0x18;
  param_3 = param_3 + -4;
  goto loc_F0008578;
loc_f0008584:
  puVar3 = (uint *)((int)puVar3 + -1);
  iVar2 = iVar2 + 1;
  goto loc_F0008830;
}
/* GHIDRADEC_FUNCTION index=78 start=0xf000885c */

undefined8 _rpause(undefined4 param_1,int param_2)

{
  byte bVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  int *piVar3;
  undefined4 unaff_i1;
  int iVar4;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar4 = _active_u;
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
  if ((*piVar3 != 0x1c) || (piVar3[1] != 0x7fffffff)) goto loc_F00088F8;
  iVar2 = piVar3[2];
  bVar1 = *(byte *)(_active_u + 0x25c);
  piVar3 = (int *)(bVar1 & 8);
  if (iVar2 == 1) {
    *(byte *)(_active_u + 0x25c) = bVar1 & 0xf7;
  }
  else {
    param_2 = _active_u;
    if (iVar2 < 2) {
      if (iVar2 != 0) {
loc_F00088F8:
        *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
        iVar4 = param_2;
        goto locret_F0008928;
      }
    }
    else {
      if (iVar2 != 2) goto loc_F00088F8;
      *(byte *)(_active_u + 0x25c) = bVar1 | 8;
    }
  }
  if ((bVar1 & 8) == 0) {
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
  }
  else {
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0x7fffffff;
  }
locret_F0008928:
  return CONCAT44(iVar4,piVar3);
}
/* GHIDRADEC_FUNCTION index=79 start=0xf0008930 */

/* WARNING: Removing unreachable block (ram,0xf000903c) */
/* WARNING: Removing unreachable block (ram,0xf0009054) */
/* WARNING: Removing unreachable block (ram,0xf0008bbc) */
/* WARNING: Removing unreachable block (ram,0xf0008b90) */
/* WARNING: Removing unreachable block (ram,0xf0008b40) */
/* WARNING: Removing unreachable block (ram,0xf0008b24) */
/* WARNING: Removing unreachable block (ram,0xf0008cb0) */
/* WARNING: Removing unreachable block (ram,0xf0008c98) */
/* WARNING: Removing unreachable block (ram,0xf0008c3c) */
/* WARNING: Removing unreachable block (ram,0xf0008be8) */
/* WARNING: Removing unreachable block (ram,0xf0008d40) */
/* WARNING: Removing unreachable block (ram,0xf0008e98) */
/* WARNING: Removing unreachable block (ram,0xf0008fa4) */
/* WARNING: Removing unreachable block (ram,0xf0008a38) */
/* WARNING: Removing unreachable block (ram,0xf0008fac) */
/* WARNING: Removing unreachable block (ram,0xf0008d18) */
/* WARNING: Removing unreachable block (ram,0xf0008dac) */
/* WARNING: Removing unreachable block (ram,0xf0008c20) */
/* WARNING: Removing unreachable block (ram,0xf0008c78) */
/* WARNING: Removing unreachable block (ram,0xf0008ca0) */
/* WARNING: Removing unreachable block (ram,0xf0008cf4) */
/* WARNING: Removing unreachable block (ram,0xf0008e0c) */
/* WARNING: Removing unreachable block (ram,0xf0008b68) */
/* WARNING: Removing unreachable block (ram,0xf0008bb0) */
/* WARNING: Removing unreachable block (ram,0xf0008bc4) */
/* WARNING: Removing unreachable block (ram,0xf0009020) */
/* WARNING: Removing unreachable block (ram,0xf0009074) */
/* WARNING: Removing unreachable block (ram,0xf0008954) */

undefined8 _table(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  int *piVar6;
  int *piVar7;
  undefined4 unaff_l0;
  undefined *puVar8;
  undefined4 unaff_l1;
  undefined4 *puVar9;
  int *piVar10;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  uint uVar11;
  undefined4 unaff_l5;
  int *piVar12;
  undefined4 unaff_l6;
  uint uVar13;
  undefined4 unaff_l7;
  int *piVar14;
  undefined4 unaff_i0;
  int iVar15;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar16;
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
  piVar12 = *(int **)(dword_F0133DDC + 0x24);
  piVar14 = (int *)0x0;
  iVar15 = 0;
  if (piVar12[3] < 0) {
    iVar1 = *piVar12;
    _machine_table_setokay();
    if (((iVar1 != 0) && (0 < iVar1)) && (iVar1 == 1)) {
      iVar15 = 1;
      piVar12[3] = -piVar12[3];
      goto loc_F00089CC;
    }
  }
  else {
loc_F00089CC:
    *(undefined4 *)(dword_F0133DDC + 0x30) = 0;
    if (*piVar12 != 1) goto loc_F00090C4;
    if (((piVar12[1] == (int)*(sword *)(*_active_u + 0x30)) || (piVar12[1] == 0)) &&
       (piVar12[3] == 1)) {
      iVar1 = piVar12[3];
      while (0 < iVar1) {
        iVar5 = *piVar12;
        piVar10 = (int *)0x0;
        uVar13 = 0;
        _machine_table(iVar5,piVar12[1],piVar12[2],iVar1,piVar12[4],iVar15);
        if (iVar5 != 0) {
          if (iVar5 < 1) goto def_F0008A80;
          if (iVar5 == 1) {
            iVar1 = piVar12[2];
            goto loc_F000908C;
          }
          goto loc_F0008FD4;
        }
        switch(*piVar12) {
        case :
          piVar7 = _active_u + 0x5a;
          if (_active_u[0x59] == 0) {
            *(undefined2 *)((int)register0x00000038 + -0xba) = 0xffff;
            piVar7 = (int *)((int)register0x00000038 + -0xba);
          }
          uVar11 = 2;
          break;
        case :
          iVar1 = piVar12[1];
          _pfind();
          if (iVar1 != 0) {
            piVar10 = *(int **)(iVar1 + 0x68);
            do {
              do {
              } while (*piVar10 != 0);
              piVar7 = piVar10;
              _simple_lock_try();
            } while (piVar7 == (int *)0x0);
            uVar11 = 0x7cc;
            if (0 < piVar10[9]) {
              iVar1 = piVar10[7];
              _thread_reference(iVar1);
              *piVar10 = 0;
              piVar10 = _kernel_pageable_map;
              _kmem_alloc_wait(_kernel_pageable_map,_page_mask + 0x7cc & ~_page_mask);
              _fake_u();
              _thread_deallocate(iVar1);
              uVar13 = (int)piVar10 + (_page_mask + 0x7cc & ~_page_mask);
              piVar7 = piVar10;
              break;
            }
            *piVar10 = 0;
          }
loc_F00089A4:
          *(undefined *)(dword_F0133DDC + 0x38) = 3;
          goto locret_F00090D4;
        case :
          if ((piVar12[1] == 0) && (piVar12[3] == 1)) {
            puVar8 = _avenrun;
            goto loc_F0008E04;
          }
          goto loc_F0008FD4;
        :
def_F0008A80:
          goto loc_F0008FD4;
        case :
          iVar1 = piVar12[1];
          piVar7 = (int *)((int)register0x00000038 + -0x18);
          _table_fsparam(iVar1,piVar7);
          if (iVar1 != 0) goto loc_F0008E20;
          goto loc_F0008FD4;
        case :
          iVar1 = piVar12[1];
          _pfind();
          if (iVar1 == 0) goto loc_F00089A4;
          uVar11 = piVar12[4];
          uVar3 = *(undefined4 *)(*(int *)(iVar1 + 0x68) + 0xc);
          if ((uVar11 == 0) || (iVar1 = *(int *)(iVar1 + 0x84), iVar1 == 0)) goto def_F0008A80;
          _vm_map_reference(uVar3);
          piVar10 = _kernel_pageable_map;
          _kmem_alloc_wait(_kernel_pageable_map,uVar11 + _page_mask & ~_page_mask);
          uVar4 = ~_page_mask;
          uVar13 = (int)piVar10 + _page_mask + uVar11 & uVar4;
          piVar7 = _kernel_pageable_map;
          _vm_map_copy(_kernel_pageable_map,uVar3,piVar10,uVar11 + _page_mask & uVar4,
                       iVar1 - uVar11 & uVar4,0,0);
          if (piVar7 != (int *)0x0) {
            _kmem_free_wakeup(_kernel_pageable_map,piVar10,uVar11 + _page_mask & ~_page_mask);
            _vm_map_deallocate(uVar3);
            goto loc_F0008FD4;
          }
          _vm_map_deallocate(uVar3);
          piVar7 = (int *)(uVar13 - uVar11);
          piVar6 = (int *)(uVar13 - 0xc);
          if (*(int *)(uVar13 - 0xc) != 0) {
            iVar1 = (int)piVar6 - (int)piVar7;
            do {
              if (iVar1 == 0) break;
              piVar6 = piVar6 + -1;
              iVar1 = (int)piVar6 - (int)piVar7;
            } while (*piVar6 != 0);
          }
          _bzero(piVar7,(int)piVar6 - (int)piVar7);
          break;
        case :
          if (piVar12[1] < 0) {
            piVar12[1] = -piVar12[1];
          }
          iVar1 = piVar12[1];
          _pfind();
          if (iVar1 == 0) goto loc_F00089A4;
          if (*(char *)(iVar1 + 0x13) == '\0') {
            _bzero((undefined *)((int)register0x00000038 + -0x58),0x30);
            *(undefined4 *)((int)register0x00000038 + -0x44) = 0;
          }
          else {
            *(int *)((int)register0x00000038 + -0x58) = (int)*(sword *)(iVar1 + 0x2c);
            *(int *)((int)register0x00000038 + -0x54) = (int)*(sword *)(iVar1 + 0x30);
            *(int *)((int)register0x00000038 + -0x50) = (int)*(sword *)(iVar1 + 0x32);
            *(int *)((int)register0x00000038 + -0x4c) = (int)*(sword *)(iVar1 + 0x2e);
            *(undefined4 *)((int)register0x00000038 + -0x40) = *(undefined4 *)(iVar1 + 0x28);
            if (*(int *)(iVar1 + 0x68) == 0) {
              uVar3 = 3;
            }
            else {
              iVar5 = *(int *)(*(int *)(iVar1 + 0x68) + 0x38);
              if (*(int *)(iVar5 + 0x164) == 0) {
                iVar2 = -1;
              }
              else {
                iVar2 = (int)*(sword *)(iVar5 + 0x168);
              }
              *(int *)((int)register0x00000038 + -0x48) = iVar2;
              _bcopy(iVar5 + 8,(undefined *)((int)register0x00000038 + -0x3c),0x10);
              *(undefined *)((int)register0x00000038 + -0x2c) = 0;
              uVar3 = 2;
              if ((*(uint *)(iVar1 + 0x28) & 0x400) == 0) {
                uVar3 = 1;
              }
            }
            *(undefined4 *)((int)register0x00000038 + -0x44) = uVar3;
          }
          uVar11 = 0x30;
          piVar7 = (int *)((int)register0x00000038 + -0x58);
          break;
        case :
          if ((piVar12[1] != 0) || (piVar12[3] != 1)) goto loc_F0008FD4;
          puVar8 = _mach_factor;
loc_F0008E04:
          piVar7 = (int *)((int)register0x00000038 + -0x28);
          _bcopy(puVar8,piVar7,0xc);
          *(undefined4 *)((int)register0x00000038 + -0x1c) = 1000;
loc_F0008E20:
          uVar11 = 0x10;
          break;
        case :
          if ((piVar12[1] == 0) && (piVar12[3] == 1)) {
            *(undefined4 *)((int)register0x00000038 + -0x6c) = 0;
            piVar7 = (int *)((int)register0x00000038 + -0x80);
            *(undefined4 *)((int)register0x00000038 + -0x80) = _cnt;
            *(undefined4 *)((int)register0x00000038 + -0x7c) = DAT_f0133fcc._0_4_;
            *(undefined4 *)((int)register0x00000038 + -0x78) = DAT_f0133fc8._0_4_;
            uVar11 = 0x28;
            *(undefined4 *)((int)register0x00000038 + -0x74) = DAT_f0133fc4._0_4_;
            *(undefined4 *)((int)register0x00000038 + -0x70) = _hz;
            _bcopy(_cp_time,(undefined *)((int)register0x00000038 + -0x68),0x10);
            uVar4 = piVar12[4];
            goto loc_F0008FF8;
          }
          goto loc_F0008FD4;
        case :
          if ((piVar12[1] != 0) || (piVar12[3] != 1)) goto loc_F0008FD4;
          iVar1 = 0;
          *(undefined4 *)((int)register0x00000038 + -0x98) = _tk_nin;
          *(undefined4 *)((int)register0x00000038 + -0x94) = _tk_nout;
          *(undefined4 *)((int)register0x00000038 + -0x90) = _dk_busy;
          *(undefined4 *)((int)register0x00000038 + -0x8c) = _dk_ndrive;
          for (puVar9 = _ifnet; puVar9 != (undefined4 *)0x0; puVar9 = (undefined4 *)puVar9[0x17]) {
            iVar1 = iVar1 + 1;
          }
          *(int *)((int)register0x00000038 + -0x88) = iVar1;
          uVar11 = 0x14;
          piVar7 = (int *)((int)register0x00000038 + -0x98);
          break;
        case :
          bVar16 = _ifnet == (undefined4 *)0x0;
          iVar1 = piVar12[1];
          puVar9 = _ifnet;
          if (!bVar16) {
            do {
              bVar16 = puVar9 == (undefined4 *)0x0;
              if (iVar1 == 0) goto loc_F0008F60;
              puVar9 = (undefined4 *)puVar9[0x17];
              iVar1 = iVar1 + -1;
            } while (puVar9 != (undefined4 *)0x0);
            bVar16 = true;
          }
loc_F0008F60:
          puVar8 = (undefined *)((int)register0x00000038 + -0xa4);
          if (bVar16) goto def_F0008A80;
          *(undefined4 *)((int)register0x00000038 + -0xb8) = puVar9[0x11];
          *(undefined4 *)((int)register0x00000038 + -0xb4) = puVar9[0x12];
          *(undefined4 *)((int)register0x00000038 + -0xb0) = puVar9[0x13];
          uVar11 = 0x1c;
          *(undefined4 *)((int)register0x00000038 + -0xac) = puVar9[0x14];
          *(undefined4 *)((int)register0x00000038 + -0xa8) = puVar9[0x15];
          _strncpy(puVar8,*puVar9,6);
          _strlen();
          ((undefined *)((int)register0x00000038 + -8) + (int)puVar8)[-0x9c] =
               *(char *)((int)puVar9 + 9) + '0';
          ((undefined *)((int)register0x00000038 + -8) + (int)puVar8)[-0x9b] = 0;
          piVar7 = (int *)((int)register0x00000038 + -0xb8);
        }
        uVar4 = piVar12[4];
loc_F0008FF8:
        if (uVar4 < uVar11) {
          uVar11 = uVar4;
        }
        if (uVar11 != 0) {
          if (iVar15 == 0) {
            _copyout(piVar7,piVar12[2],uVar11);
            piVar14 = piVar7;
          }
          else {
            piVar14 = (int *)piVar12[2];
            _copyin(piVar14,(undefined *)((int)register0x00000038 + -200),uVar11);
            if (piVar14 == (int *)0x0) {
              _bcopy((undefined *)((int)register0x00000038 + -200),piVar7,uVar11);
            }
          }
        }
        if (piVar10 != (int *)0x0) {
          _kmem_free_wakeup(_kernel_pageable_map,piVar10,uVar13 - (int)piVar10);
        }
        if (piVar14 != (int *)0x0) {
          *(char *)(dword_F0133DDC + 0x38) = (char)piVar14;
          break;
        }
        iVar1 = piVar12[2];
loc_F000908C:
        piVar12[2] = iVar1 + piVar12[4];
        piVar12[3] = piVar12[3] + -1;
        piVar12[1] = piVar12[1] + 1;
        *(int *)(dword_F0133DDC + 0x30) = *(int *)(dword_F0133DDC + 0x30) + 1;
loc_F00090C4:
        iVar1 = piVar12[3];
      }
      goto locret_F00090D4;
    }
loc_F0008FD4:
    if (*(int *)(dword_F0133DDC + 0x30) != 0) goto locret_F00090D4;
  }
  *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
locret_F00090D4:
  return CONCAT44(param_2,iVar15);
}
/* GHIDRADEC_FUNCTION index=80 start=0xf00090dc */

/* WARNING: Removing unreachable block (ram,0xf0009144) */
/* WARNING: Removing unreachable block (ram,0xf0009110) */

sqword _table_fsparam(undefined4 param_1,uint param_2)

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
  if (_mounttab != 0) {
    for (iVar1 = *(int *)(_mounttab + 0x20); iVar1 != 0; iVar1 = *(int *)(iVar1 + 0x20)) {
    }
  }
  return (qword)param_2 << 0x20;
}
/* GHIDRADEC_FUNCTION index=81 start=0xf000915c */

/* WARNING: Removing unreachable block (ram,0xf0009184) */
/* WARNING: Removing unreachable block (ram,0xf0009160) */

undefined8 _task_name(uint param_1,undefined4 param_2)

{
  uint uVar1;
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
  uVar1 = param_1;
  _strlen();
  iVar2 = 0x11;
  if (uVar1 < 0x11) {
    iVar2 = uVar1 + 1;
  }
  _bcopy(param_1,_active_u + 8,iVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=82 start=0xf00091a0 */

/* WARNING: Removing unreachable block (ram,0xf0009658) */
/* WARNING: Removing unreachable block (ram,0xf000962c) */
/* WARNING: Removing unreachable block (ram,0xf0009618) */
/* WARNING: Removing unreachable block (ram,0xf00095fc) */
/* WARNING: Removing unreachable block (ram,0xf00095e4) */
/* WARNING: Removing unreachable block (ram,0xf00095c8) */
/* WARNING: Removing unreachable block (ram,0xf00095b4) */
/* WARNING: Removing unreachable block (ram,0xf0009598) */
/* WARNING: Removing unreachable block (ram,0xf0009578) */
/* WARNING: Removing unreachable block (ram,0xf0009568) */
/* WARNING: Removing unreachable block (ram,0xf0009558) */
/* WARNING: Removing unreachable block (ram,0xf0009544) */
/* WARNING: Removing unreachable block (ram,0xf000951c) */
/* WARNING: Removing unreachable block (ram,0xf00094f4) */
/* WARNING: Removing unreachable block (ram,0xf00094e0) */
/* WARNING: Removing unreachable block (ram,0xf00094bc) */
/* WARNING: Removing unreachable block (ram,0xf00094a8) */
/* WARNING: Removing unreachable block (ram,0xf000945c) */
/* WARNING: Removing unreachable block (ram,0xf000944c) */
/* WARNING: Removing unreachable block (ram,0xf000943c) */
/* WARNING: Removing unreachable block (ram,0xf000942c) */
/* WARNING: Removing unreachable block (ram,0xf00093d4) */
/* WARNING: Removing unreachable block (ram,0xf00093bc) */
/* WARNING: Removing unreachable block (ram,0xf0009394) */
/* WARNING: Removing unreachable block (ram,0xf0009218) */
/* WARNING: Removing unreachable block (ram,0xf00091dc) */
/* WARNING: Removing unreachable block (ram,0xf00091cc) */
/* WARNING: Removing unreachable block (ram,0xf00091c0) */
/* WARNING: Removing unreachable block (ram,0xf00091d4) */
/* WARNING: Removing unreachable block (ram,0xf00091e8) */
/* WARNING: Removing unreachable block (ram,0xf00092f4) */
/* WARNING: Removing unreachable block (ram,0xf00093b0) */
/* WARNING: Removing unreachable block (ram,0xf00093c4) */
/* WARNING: Removing unreachable block (ram,0xf0009424) */
/* WARNING: Removing unreachable block (ram,0xf0009434) */
/* WARNING: Removing unreachable block (ram,0xf0009444) */
/* WARNING: Removing unreachable block (ram,0xf0009454) */
/* WARNING: Removing unreachable block (ram,0xf000949c) */
/* WARNING: Removing unreachable block (ram,0xf00094b4) */
/* WARNING: Removing unreachable block (ram,0xf00094c4) */
/* WARNING: Removing unreachable block (ram,0xf00094e8) */
/* WARNING: Removing unreachable block (ram,0xf0009508) */
/* WARNING: Removing unreachable block (ram,0xf0009530) */
/* WARNING: Removing unreachable block (ram,0xf000954c) */
/* WARNING: Removing unreachable block (ram,0xf0009560) */
/* WARNING: Removing unreachable block (ram,0xf0009570) */
/* WARNING: Removing unreachable block (ram,0xf0009588) */
/* WARNING: Removing unreachable block (ram,0xf00095a0) */
/* WARNING: Removing unreachable block (ram,0xf00095c0) */
/* WARNING: Removing unreachable block (ram,0xf00095d0) */
/* WARNING: Removing unreachable block (ram,0xf00095f4) */
/* WARNING: Removing unreachable block (ram,0xf0009604) */
/* WARNING: Removing unreachable block (ram,0xf0009624) */
/* WARNING: Removing unreachable block (ram,0xf000964c) */
/* WARNING: Removing unreachable block (ram,0xf0009660) */
/* WARNING: Removing unreachable block (ram,0xf00091a4) */

undefined8 _main(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
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
  _pqinit();
  iVar7 = _kernel_proc;
  *(int *)(_kernel_task + 0x3c) = _kernel_proc;
  *(undefined2 *)(iVar7 + 0x30) = 0;
  _pidhash_enter(iVar7);
  *(int *)(iVar7 + 0x68) = _kernel_task;
  _splusclock();
  _splx();
  _calloutInitialize();
  _switch_unix_context(_active_threads);
  *(undefined *)(iVar7 + 0x13) = 3;
  *(undefined *)(iVar7 + 0x15) = 0;
  *(undefined4 *)(iVar7 + 0x70) = 0;
  *(undefined4 *)(iVar7 + 0x74) = 0;
  *(undefined4 *)(iVar7 + 0x78) = 0;
  *(uint *)(iVar7 + 0x28) = *(uint *)(iVar7 + 0x28) | 3;
  piVar1 = _active_u;
  *_active_u = iVar7;
  _crget();
  _active_u[7] = (int)piVar1;
  *(sword *)((int)_active_u + 0x16a) = (sword)_cmask;
  _active_u[0x55] = -1;
  uVar4 = 0;
  do {
    piVar1 = _active_u;
    uVar5 = uVar4 + 1;
    _active_u[uVar4 * 2 + 0x99] = 0x7fffffff;
    piVar1[uVar4 * 2 + 0x98] = 0x7fffffff;
    piVar1 = _active_u;
    uVar4 = uVar5;
  } while (uVar5 < 6);
  _active_u[0x9e] = _vm_initial_limit_stack;
  piVar1[0x9f] = DAT_f010a7dc;
  piVar1 = _active_u;
  iVar6 = 0;
  _active_u[0x9c] = _vm_initial_limit_data;
  piVar1[0x9d] = DAT_f010a7e4;
  piVar1 = _active_u;
  _active_u[0xa0] = _vm_initial_limit_core;
  iVar3 = 0;
  piVar1[0xa1] = DAT_f010a7ec;
  do {
    *(undefined4 *)((int)&_pgrphash + iVar3) = 0;
    *(undefined4 *)(_posix_proc_hash + iVar3) = 0;
    iVar6 = iVar6 + 1;
    iVar3 = iVar3 + 4;
  } while (iVar6 < 0x40);
  iVar3 = 0;
  _new_posix_proc();
  *(undefined **)(iVar3 + 0x10) = _pgrp0;
  *(undefined4 *)(iVar3 + 0xc) = 0;
  *(undefined2 *)(iVar3 + 4) = *(undefined2 *)(_active_u[7] + 6);
  *(undefined2 *)(iVar3 + 6) = *(undefined2 *)(_active_u[7] + 2);
  _px = iVar3;
  *(undefined2 *)(iVar3 + 8) = *(undefined2 *)(_active_u[7] + 4);
  *(undefined4 *)(iVar3 + 0x14) = 0;
  *(uint *)(iVar3 + 0x18) = *(uint *)(iVar3 + 0x18) & 0x3fffffff;
  _pgrphash = _pgrp0;
  DAT_f0134794._0_4_ = iVar7;
  DAT_f0134794._4_4_ = _session0;
  _pgrp0._0_4_ = 0;
  DAT_f0134794._12_4_ = 0;
  _session0._0_4_ = 1;
  _session0._4_4_ = iVar7;
  _session0._8_4_ = 0;
  _session0._12_2_ = 0;
  _gc_init();
  uVar2 = _kernel_map;
  _kmem_suballoc(_kernel_map,(undefined *)((int)register0x00000038 + -0xc),
                 (undefined *)((int)register0x00000038 + -0x10),0x80000,1);
  _kernel_pageable_map = uVar2;
  _ns_hardclock_init();
  iVar7 = 1;
  _mfs_init();
  _lock_init(_active_u + 8,1);
  *(sword *)_active_u[7] = *(sword *)_active_u[7] + 1;
  _rootcred = _active_u[7];
  do {
    iVar3 = iVar7 * 2;
    iVar7 = iVar7 + 1;
    iVar3 = iVar3 + _active_u[7];
    *(undefined2 *)(iVar3 + 10) = 0xffff;
  } while (iVar7 < 0x10);
  iVar6 = 0;
  _mbinit();
  _cinit();
  _splnet();
  _ifinit();
  iVar8 = 0;
  _domaininit();
  _splx(iVar3);
  iVar7 = 0;
  _bhinit();
  _dnlc_init();
  _active_u[0x58] = 0;
  _active_u[0x57] = 0;
  do {
    if (*(int *)((int)&_machine_slot + iVar7) != 0) {
      _thread_create(_kernel_task,(undefined *)((int)register0x00000038 + -0x14));
      _thread_bind(*(undefined4 *)((int)register0x00000038 + -0x14),
                   *(undefined4 *)((int)&_processor_ptr + iVar8));
      _thread_start(*(undefined4 *)((int)register0x00000038 + -0x14),_idle_thread);
      _thread_doswapin(*(undefined4 *)((int)register0x00000038 + -0x14));
      _thread_resume(*(undefined4 *)((int)register0x00000038 + -0x14));
    }
    iVar8 = iVar8 + 4;
    iVar6 = iVar6 + 1;
    iVar7 = iVar7 + 0x20;
  } while (iVar6 < 1);
  _binit();
  _recompute_priorities();
  _lightning_bolt(0,0);
  _kernel_thread(_kernel_task,_reaper_thread,0);
  _kernel_thread(_kernel_task,_swapin_thread,0);
  _kernel_thread(_kernel_task,_sched_thread,0);
  _kernel_thread(_kernel_task,_netisr_thread,0);
  __objcInit();
  _objc_setClassHandler(sub_F0009194);
  _kmEnableAnimation();
  _autoconf();
  _setconf();
  _loattach();
  *(undefined *)(dword_F0133DDC + 0x38) = 0;
  _vfs_mountroot();
  *(undefined *)(_active_u + 0x97) = 0xf;
  _file_init();
  iVar7 = 0;
  _newproc();
  iVar3 = *(int *)(iVar7 + 0xc);
  *(int *)((int)register0x00000038 + -0x14) = iVar7;
  uVar2 = 1;
  *(undefined4 *)(iVar3 + 0x4c) = 0;
  _pfind();
  _init_proc = uVar2;
  _kmDisableAnimation();
  _ux_handler_init();
  _port_reference(_ux_exception_port);
  _task_set_special_port
            (*(undefined4 *)(*(int *)((int)register0x00000038 + -0x14) + 0xc),3,_ux_exception_port);
  _thread_start(*(undefined4 *)((int)register0x00000038 + -0x14),_init_task);
  _thread_resume(*(undefined4 *)((int)register0x00000038 + -0x14));
  _power_init();
  iVar7 = _kernel_task;
  _kernel_thread(_kernel_task,_vm_pageout,0);
  _pageoutThread = iVar7;
  _vol_start_thread();
  _pnotify_start();
  *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 3;
  _task_name(aKernelIdle);
  _thread_terminate(_active_threads);
  _thread_halt_self();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=83 start=0xf0009670 */

/* WARNING: Removing unreachable block (ram,0xf0009698) */
/* WARNING: Removing unreachable block (ram,0xf00096a0) */
/* WARNING: Removing unreachable block (ram,0xf0009678) */

undefined8 _init_task(undefined4 param_1,undefined4 param_2)

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
  _task_name(&aInit);
  *dword_F0133DDC = *(int *)(_active_threads + 0x28) + 0x234;
  _load_init_program();
  _thread_exception_return();
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=84 start=0xf00096b0 */

/* WARNING: Removing unreachable block (ram,0xf00096f4) */
/* WARNING: Removing unreachable block (ram,0xf00096dc) */
/* WARNING: Removing unreachable block (ram,0xf000970c) */
/* WARNING: Removing unreachable block (ram,0xf00096c0) */

undefined8 _lightning_bolt(undefined4 param_1,code *param_2)

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
  _thread_wakeup_prim(_lbolt,0,0);
  if (param_2 == (code *)0x0) {
    param_2 = _lightning_bolt;
    _calloutEntryAllocate(_lightning_bolt,0);
  }
  uVar1 = 0;
  uVar2 = 1000000000;
  _calloutDeadlineFromInterval(0,1000000000);
  _calloutEntryDispatchDelayed(param_2,uVar1,uVar2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=85 start=0xf000971c */

undefined8 _bhinit(undefined4 param_1,undefined4 param_2)

{
  undefined *puVar1;
  undefined4 *puVar2;
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
  puVar1 = _bufhash;
  iVar3 = 0;
  puVar2 = (undefined4 *)(_bufhash + 4);
  do {
    puVar2[1] = puVar1;
    *puVar2 = puVar1;
    iVar3 = iVar3 + 1;
    puVar2 = puVar2 + 3;
    puVar1 = puVar1 + 0xc;
  } while (iVar3 < 0x10);
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=86 start=0xf0009754 */

/* WARNING: Removing unreachable block (ram,0xf0009840) */
/* WARNING: Removing unreachable block (ram,0xf00097c4) */
/* WARNING: Removing unreachable block (ram,0xf0009898) */
/* WARNING: Removing unreachable block (ram,0xf00097b4) */

undefined8 _binit(undefined4 param_1,undefined4 param_2)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  int iVar6;
  int iVar7;
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
  puVar1 = &_bfreelist;
  puVar5 = &dword_F0133DE4;
  do {
    puVar5[3] = puVar1;
    puVar5[2] = puVar1;
    puVar5[1] = puVar1;
    *puVar5 = puVar1;
    *puVar1 = 0x40000;
    iVar3 = _bufpages;
    iVar6 = _nbuf;
    puVar1 = puVar1 + 0x11;
    puVar5 = puVar5 + 0x11;
  } while (puVar1 < &_buf);
  iVar7 = 0;
  iVar2 = _bufpages;
  .div(_bufpages,_nbuf);
  .rem(iVar3,iVar6);
  if (0 < iVar6) {
    param_2 = 0x10008;
    iVar6 = 0;
    do {
      puVar1 = (undefined4 *)(_buf + iVar6);
      *(undefined2 *)((int)puVar1 + 0x1e) = 0xffff;
      iVar4 = _buffers;
      puVar1[5] = 0;
      puVar1[8] = iVar4 + iVar7 * 0x2000;
      iVar4 = iVar2;
      if (iVar7 < iVar3) {
        iVar4 = iVar2 + 1;
      }
      .umul(iVar4,_page_size);
      puVar1[6] = iVar4;
      puVar1[0xf] = 0;
      if (puVar1[6] == 0) {
        puVar1[1] = DAT_f0133eb0._0_4_;
        puVar1[2] = unk_F0133EAC;
        DAT_f0133eb0._0_4_[2] = puVar1;
        DAT_f0133eb0._0_4_ = puVar1;
      }
      else {
        puVar1[1] = DAT_f0133e6c._0_4_;
        puVar1[2] = unk_F0133E68;
        *(undefined4 **)(DAT_f0133e6c._0_4_ + 8) = puVar1;
        DAT_f0133e6c._0_4_ = puVar1;
      }
      puVar1[0x10] = 0;
      *puVar1 = 0x10008;
      _brelse(puVar1);
      iVar7 = iVar7 + 1;
      iVar6 = iVar6 + 0x44;
    } while (iVar7 < _nbuf);
  }
  return CONCAT44(param_2,iVar3);
}
/* GHIDRADEC_FUNCTION index=87 start=0xf00098c0 */

undefined8 _cinit(void)

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
  undefined *puVar2;
  undefined4 unaff_i1;
  undefined4 *puVar3;
  undefined4 *puVar4;
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
  puVar2 = DAT_f0134000;
  puVar3 = (undefined4 *)(_cfree + 0x3fU & 0xffffffc0);
  puVar1 = (undefined4 *)(_cfree + _nclist * 0x40 + -0x40);
  if (puVar3 < puVar1) {
    puVar2 = DAT_f010f000;
    do {
      puVar4 = puVar3;
      *puVar4 = _cfreelist;
      puVar3 = puVar4 + 0x10;
      _cfreecount = _cfreecount + 0x34;
      _cfreelist = puVar4;
    } while (puVar3 < puVar1);
  }
  return CONCAT44(puVar3,puVar2);
}
/* GHIDRADEC_FUNCTION index=88 start=0xf0009928 */

/* WARNING: Removing unreachable block (ram,0xf0009a38) */
/* WARNING: Removing unreachable block (ram,0xf0009a04) */
/* WARNING: Removing unreachable block (ram,0xf0009998) */
/* WARNING: Removing unreachable block (ram,0xf00099e4) */
/* WARNING: Removing unreachable block (ram,0xf0009a28) */
/* WARNING: Removing unreachable block (ram,0xf0009984) */
/* WARNING: Removing unreachable block (ram,0xf0009934) */

undefined8 _sysacct(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined uVar2;
  undefined4 unaff_l0;
  int *piVar3;
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
  piVar3 = *(int **)(dword_F0133DDC + 0x24);
  iVar1 = dword_F0133DDC;
  _suser();
  if (iVar1 != 0) {
    if (_savacctp != 0) {
      _acctp = _savacctp;
      _savacctp = 0;
    }
    iVar1 = *piVar3;
    if (iVar1 == 0) {
      *(int *)((int)register0x00000038 + -0xc) = _acctp;
      if (_acctp != 0) {
        _acctp = 0;
        _vn_rele();
      }
    }
    else {
      _lookupname(iVar1,0,1,0,(undefined *)((int)register0x00000038 + -0xc));
      *(char *)(dword_F0133DDC + 0x38) = (char)iVar1;
      iVar1 = *(int *)((int)register0x00000038 + -0xc);
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        uVar2 = 0xd;
        if ((*(int *)(iVar1 + 0x28) == 1) &&
           (uVar2 = 0x1e, (*(uint *)(*(int *)(iVar1 + 0x24) + 0xc) & 1) == 0)) {
          bVar4 = _acctp != 0;
          _acctp = iVar1;
          if (bVar4) {
            _vn_rele();
          }
          if (_acctcred != 0) {
            _crfree();
          }
          iVar1 = *(int *)(_active_u + 0x1c);
          _crdup();
          _acctcred = iVar1;
        }
        else {
          *(undefined *)(dword_F0133DDC + 0x38) = uVar2;
          _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xc));
        }
      }
    }
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=89 start=0xf0009a4c */

/* WARNING: Removing unreachable block (ram,0xf0009b2c) */
/* WARNING: Removing unreachable block (ram,0xf0009c64) */
/* WARNING: Removing unreachable block (ram,0xf0009c20) */
/* WARNING: Removing unreachable block (ram,0xf0009bf8) */
/* WARNING: Removing unreachable block (ram,0xf0009b9c) */
/* WARNING: Removing unreachable block (ram,0xf0009b7c) */
/* WARNING: Removing unreachable block (ram,0xf0009b00) */
/* WARNING: Removing unreachable block (ram,0xf0009ab4) */
/* WARNING: Removing unreachable block (ram,0xf0009a8c) */
/* WARNING: Removing unreachable block (ram,0xf0009af8) */
/* WARNING: Removing unreachable block (ram,0xf0009b6c) */
/* WARNING: Removing unreachable block (ram,0xf0009b8c) */
/* WARNING: Removing unreachable block (ram,0xf0009ba8) */
/* WARNING: Removing unreachable block (ram,0xf0009c08) */
/* WARNING: Removing unreachable block (ram,0xf0009c44) */
/* WARNING: Removing unreachable block (ram,0xf0009cd4) */
/* WARNING: Removing unreachable block (ram,0xf0009cf4) */
/* WARNING: Removing unreachable block (ram,0xf0009a84) */

undefined8 _acct(undefined4 param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined uVar7;
  uint uVar8;
  int iVar9;
  undefined4 unaff_l0;
  undefined4 unaff_l1;
  undefined *puVar10;
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
  if (_savacctp != 0) {
    (**(code **)(*(int *)(*(int *)(_savacctp + 0x24) + 4) + 0xc))
              (*(int *)(_savacctp + 0x24),(undefined *)((int)register0x00000038 + -0x48));
    iVar2 = _acctresume;
    .umul(_acctresume,*(undefined4 *)((int)register0x00000038 + -0x40));
    .div();
    if (iVar2 < *(int *)((int)register0x00000038 + -0x38)) {
      _acctp = _savacctp;
      _savacctp = 0;
      _printf(aAccountingResu);
    }
  }
  iVar2 = _acctp;
  if (_acctp != 0) {
    piVar1 = (int *)(_acctp + 0x24);
    *(sword *)(_acctp + 6) = *(sword *)(_acctp + 6) + 1;
    (**(code **)(*(int *)(*piVar1 + 4) + 0xc))
              (*piVar1,(undefined *)((int)register0x00000038 + -0x48));
    iVar6 = _acctsuspend;
    .umul(_acctsuspend,*(undefined4 *)((int)register0x00000038 + -0x40));
    .div();
    uVar8 = 0;
    if (iVar6 < *(int *)((int)register0x00000038 + -0x38)) {
      do {
        _acctbuf[uVar8] = *(undefined *)(_active_u + uVar8 + 8);
        iVar6 = _active_u;
        uVar8 = uVar8 + 1;
      } while (uVar8 < 10);
      uVar3 = *(undefined4 *)(_active_u + 0x16c);
      _compress(uVar3,*(undefined4 *)(_active_u + 0x170));
      DAT_f01349fa._0_2_ = (undefined2)uVar3;
      uVar3 = *(undefined4 *)(iVar6 + 0x174);
      _compress(uVar3,*(undefined4 *)(iVar6 + 0x178));
      DAT_f01349fa._2_2_ = (undefined2)uVar3;
      puVar10 = (undefined *)((int)register0x00000038 + -0x50);
      _microtime(puVar10);
      _timevalsub(puVar10,_active_u + 0x238);
      uVar3 = *(undefined4 *)((int)register0x00000038 + -0x50);
      _compress(uVar3,*(undefined4 *)((int)register0x00000038 + -0x4c));
      DAT_f01349fa._4_2_ = (undefined2)uVar3;
      DAT_f01349fa._6_4_ = *(undefined4 *)(_active_u + 0x238);
      DAT_f01349fa._10_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 6);
      DAT_f01349fa._12_2_ = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 8);
      *(undefined4 *)((int)register0x00000038 + -0x50) = *(undefined4 *)(iVar6 + 0x174);
      *(undefined4 *)((int)register0x00000038 + -0x4c) = *(undefined4 *)(iVar6 + 0x178);
      _timevaladd(puVar10,iVar6 + 0x16c);
      iVar4 = *(int *)((int)register0x00000038 + -0x50);
      .umul(iVar4,_hz);
      iVar9 = *(int *)((int)register0x00000038 + -0x4c);
      .div(iVar9,_tick);
      if (iVar4 + iVar9 == 0) {
        DAT_f01349fa._14_2_ = 0;
      }
      else {
        iVar5 = *(int *)(iVar6 + 0x180) + *(int *)(iVar6 + 0x184) + *(int *)(iVar6 + 0x188);
        .div(iVar5,iVar4 + iVar9);
        DAT_f01349fa._14_2_ = (undefined2)iVar5;
      }
      iVar6 = *(int *)(iVar6 + 0x198) + *(int *)(iVar6 + 0x19c);
      _compress(iVar6,0);
      DAT_f01349fa._16_2_ = (undefined2)iVar6;
      DAT_f01349fa._18_2_ = 0xffff;
      if (*(int *)(_active_u + 0x164) != 0) {
        DAT_f01349fa._18_2_ = *(undefined2 *)(_active_u + 0x168);
      }
      DAT_f01349fa[0x14] = (undefined)*(undefined2 *)(_active_u + 0x240);
      uVar7 = 1;
      uVar3 = *(undefined4 *)(_active_u + 0x1c);
      *(undefined4 *)(_active_u + 0x1c) = _acctcred;
      _vn_rdwr(1,iVar2,_acctbuf,0x20,0,1,3,0);
      *(undefined *)(dword_F0133DDC + 0x38) = uVar7;
      *(undefined4 *)(_active_u + 0x1c) = uVar3;
    }
    else {
      _savacctp = _acctp;
      _acctp = 0;
      _printf(aAccountingSusp);
    }
    _vn_rele(iVar2);
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=90 start=0xf0009d04 */

/* WARNING: Removing unreachable block (ram,0xf0009d24) */

undefined8 _compress(int param_1,int param_2)

{
  undefined4 unaff_l0;
  uint uVar1;
  undefined4 unaff_l1;
  int iVar2;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  uint uVar3;
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
  uVar3 = 0;
  uVar1 = param_1 * 0x40;
  if (param_2 != 0) {
    .div(param_2,0x3d09);
    uVar1 = uVar1 + param_2;
  }
  for (; 0x1fff < (int)uVar1; uVar1 = (int)uVar1 >> 3) {
    uVar3 = uVar1 & 4;
    iVar2 = iVar2 + 1;
  }
  if ((uVar3 != 0) && (uVar1 = uVar1 + 1, 0x1fff < (int)uVar1)) {
    uVar1 = (int)uVar1 >> 3;
    iVar2 = iVar2 + 1;
  }
  return CONCAT44(uVar3,iVar2 * 0x2000 + uVar1);
}
/* GHIDRADEC_FUNCTION index=91 start=0xf0009d8c */

/* WARNING: Removing unreachable block (ram,0xf0009f54) */
/* WARNING: Removing unreachable block (ram,0xf0009ee8) */
/* WARNING: Removing unreachable block (ram,0xf0009e6c) */
/* WARNING: Removing unreachable block (ram,0xf0009dc8) */
/* WARNING: Removing unreachable block (ram,0xf0009e50) */
/* WARNING: Removing unreachable block (ram,0xf0009eb8) */
/* WARNING: Removing unreachable block (ram,0xf0009f38) */
/* WARNING: Removing unreachable block (ram,0xf0009f60) */
/* WARNING: Removing unreachable block (ram,0xf0009d98) */

undefined8 _hardclock(undefined4 param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
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
  iVar2 = 1;
  uVar4 = param_2;
  _clock_value();
  iVar5 = uVar4 - (uint)_last_hardclock;
  __udivdi3((iVar2 - (int)((qword)_last_hardclock >> 0x20)) - (uint)(uVar4 < (uint)_last_hardclock),
            iVar5,0,1000);
  _last_hardclock = CONCAT44(iVar2,uVar4);
  if ((param_2 & 0x40) == 0) {
    iVar2 = *_active_u;
    if ((iVar2 != 0) && (_active_u[0x96] != 0)) {
      *(uint *)(iVar2 + 0x28) = *(uint *)(iVar2 + 0x28) | 0x200000;
      _need_ast = _need_ast | 0x20;
    }
    if ((_active_u[0x85] != 0) || (_active_u[0x86] != 0)) {
      piVar3 = _active_u + 0x83;
      _itimerdecr(piVar3,iVar5);
      if (piVar3 == (int *)0x0) {
        _psignal(*_active_u,0x1a);
      }
    }
  }
  if ((*_active_u != 0) && ((*(uint *)(iVar1 + 0x4c) & 0x80) == 0)) {
    if ((_active_u[0x98] != 0x7fffffff) &&
       (_thread_read_times(iVar1,(undefined *)((int)register0x00000038 + -0x18),
                           (undefined *)((int)register0x00000038 + -0x10)),
       _active_u[0x98] <
       *(int *)((int)register0x00000038 + -0x10) + *(int *)((int)register0x00000038 + -0x18) + 1)) {
      _psignal(*_active_u,0x18);
      if (_active_u[0x98] < _active_u[0x99]) {
        _active_u[0x98] = _active_u[0x98] + 5;
      }
    }
    if ((_active_u[0x89] != 0) || (_active_u[0x8a] != 0)) {
      piVar3 = _active_u + 0x87;
      _itimerdecr(piVar3,iVar5);
      if (piVar3 == (int *)0x0) {
        _psignal(*_active_u,0x1b);
      }
    }
  }
  _gatherstats(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=92 start=0xf0009f70 */

undefined8 _gatherstats(undefined4 param_1,uint param_2)

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
  uint uVar2;
  int iVar3;
  undefined4 unaff_i2;
  undefined *puVar4;
  undefined4 unaff_i3;
  byte bVar6;
  int iVar5;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _dk_busy;
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
  if ((param_2 & 0x40) == 0) {
    uVar2 = (uint)('\0' < *(char *)(*_active_u + 0x15));
  }
  else {
    uVar2 = 2;
    if (((*(uint *)(_active_threads + 0x4c) & 0x80) != 0) && ((param_2 & 0xf00) == 0)) {
      uVar2 = 3;
    }
  }
  iVar5 = 0;
  puVar4 = _dk_time;
  iVar3 = uVar2 * 4;
  *(int *)(_cp_time + iVar3) = *(int *)(_cp_time + iVar3) + 1;
  do {
    bVar6 = (byte)iVar5;
    iVar5 = iVar5 + 1;
    if ((iVar1 >> (bVar6 & 0x1f) & 1U) != 0) {
      *(int *)puVar4 = *(int *)puVar4 + 1;
    }
    puVar4 = (undefined *)((int)puVar4 + 4);
  } while (iVar5 < 4);
  return CONCAT44(iVar3,_cp_time);
}
/* GHIDRADEC_FUNCTION index=93 start=0xf000a028 */

/* WARNING: Removing unreachable block (ram,0xf000a044) */
/* WARNING: Removing unreachable block (ram,0xf000a02c) */

undefined8 _timeout(undefined4 param_1,undefined4 param_2,undefined4 param_3)

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
  uVar1 = param_2;
  _ticks_to_ns_time(param_3);
  _ns_timeout(param_1,param_2,param_3,uVar1,0);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=94 start=0xf000a054 */

/* WARNING: Removing unreachable block (ram,0xf000a05c) */

undefined8 _untimeout(undefined4 param_1,undefined4 param_2)

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
  _ns_untimeout(param_1,param_2);
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=95 start=0xf000a06c */

/* WARNING: Removing unreachable block (ram,0xf000a0f8) */
/* WARNING: Removing unreachable block (ram,0xf000a0d4) */
/* WARNING: Removing unreachable block (ram,0xf000a0b8) */
/* WARNING: Removing unreachable block (ram,0xf000a0e0) */
/* WARNING: Removing unreachable block (ram,0xf000a110) */
/* WARNING: Removing unreachable block (ram,0xf000a070) */

undefined8 _hzto(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
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
  _getthetime((undefined *)((int)register0x00000038 + -0x10));
  uVar2 = _hz;
  iVar4 = *param_1 - *(int *)((int)register0x00000038 + -0x10);
  if (iVar4 < 0x20c0b4) {
    iVar1 = param_1[1] - *(int *)((int)register0x00000038 + -0xc);
    .div(iVar1,1000);
    iVar1 = iVar4 * 1000 + iVar1;
    uVar2 = _tick;
    .div(_tick,1000);
    .div(iVar1,uVar2);
  }
  else {
    iVar3 = 0x7fffffff;
    .div(0x7fffffff,_hz);
    iVar1 = 0x7fffffff;
    if (iVar4 <= iVar3) {
      .umul(iVar4,uVar2);
      iVar1 = iVar4;
    }
  }
  return CONCAT44(param_2,iVar1);
}
/* GHIDRADEC_FUNCTION index=96 start=0xf000a120 */

/* WARNING: Removing unreachable block (ram,0xf000a140) */
/* WARNING: Removing unreachable block (ram,0xf000a14c) */
/* WARNING: Removing unreachable block (ram,0xf000a130) */

undefined8 _ticks_to_timeval(undefined4 param_1,undefined4 *param_2)

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
  
  uVar1 = _hz;
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
  .div(param_1,_hz);
  *param_2 = uVar2;
  uVar2 = param_1;
  .rem(param_1,uVar1);
  .umul();
  param_2[1] = uVar2;
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=97 start=0xf000a160 */

/* WARNING: Removing unreachable block (ram,0xf000a1cc) */
/* WARNING: Removing unreachable block (ram,0xf000a1a8) */

undefined8 _profil(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
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
  bool in_DECOMPILE_MODE;
  int in_CWP;
  
  iVar1 = _active_u;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  *(undefined4 *)(_active_u + 0x24c) = *puVar3;
  *(undefined4 *)(iVar1 + 0x250) = puVar3[1];
  *(undefined4 *)(iVar1 + 0x254) = puVar3[2];
  puVar3 = (undefined4 *)puVar3[3];
  *(undefined4 **)(iVar1 + 600) = puVar3;
  if (*(int *)(iVar1 + 0x244) == 0) {
    _simple_lock_alloc();
    *(undefined4 **)(iVar1 + 0x244) = puVar3;
    *puVar3 = 0;
  }
  iVar2 = *(int *)(iVar1 + 0x248);
  if (iVar2 == 0) {
    *(undefined4 *)(iVar1 + 0x248) = 0;
  }
  else {
    for (iVar4 = *(int *)(iVar2 + 4); _kfree(iVar2,0x18), iVar4 != 0; iVar4 = *(int *)(iVar4 + 4)) {
      iVar2 = iVar4;
    }
    *(undefined4 *)(iVar1 + 0x248) = 0;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=98 start=0xf000a1ec */

/* WARNING: Removing unreachable block (ram,0xf000a210) */

undefined8 _add_profil(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 unaff_l0;
  undefined4 *puVar3;
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
  
  iVar1 = _active_u;
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
  puVar3 = *(undefined4 **)(dword_F0133DDC + 0x24);
  if (*(int *)(_active_u + 600) != 0) {
    iVar2 = 0x18;
    _kalloc();
    *(undefined4 *)(iVar2 + 8) = *puVar3;
    *(undefined4 *)(iVar2 + 0xc) = puVar3[1];
    *(undefined4 *)(iVar2 + 0x10) = puVar3[2];
    *(undefined4 *)(iVar2 + 0x14) = puVar3[3];
    *(undefined4 *)(iVar2 + 4) = *(undefined4 *)(iVar1 + 0x248);
    *(int *)(iVar1 + 0x248) = iVar2;
  }
  return CONCAT44(param_2,param_1);
}
/* GHIDRADEC_FUNCTION index=99 start=0xf000a24c */

/* WARNING: Removing unreachable block (ram,0xf000a72c) */
/* WARNING: Removing unreachable block (ram,0xf000a6b8) */
/* WARNING: Removing unreachable block (ram,0xf000a5f8) */
/* WARNING: Removing unreachable block (ram,0xf000a564) */
/* WARNING: Removing unreachable block (ram,0xf000a4b4) */
/* WARNING: Removing unreachable block (ram,0xf000a440) */
/* WARNING: Removing unreachable block (ram,0xf000a3a4) */
/* WARNING: Removing unreachable block (ram,0xf000a348) */
/* WARNING: Removing unreachable block (ram,0xf000a2ec) */
/* WARNING: Removing unreachable block (ram,0xf000a2d8) */
/* WARNING: Removing unreachable block (ram,0xf000a31c) */
/* WARNING: Removing unreachable block (ram,0xf000a370) */
/* WARNING: Removing unreachable block (ram,0xf000a3e0) */
/* WARNING: Removing unreachable block (ram,0xf000a454) */
/* WARNING: Removing unreachable block (ram,0xf000a4d4) */
/* WARNING: Removing unreachable block (ram,0xf000a5c8) */
/* WARNING: Removing unreachable block (ram,0xf000a634) */
/* WARNING: Removing unreachable block (ram,0xf000a714) */
/* WARNING: Removing unreachable block (ram,0xf000a734) */
/* WARNING: Removing unreachable block (ram,0xf000a2d0) */

undefined8 _core(undefined4 param_1,int param_2)

{
  sword sVar1;
  undefined uVar4;
  int iVar2;
  int *piVar3;
  undefined4 *puVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 unaff_l0;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  undefined4 unaff_l1;
  undefined *puVar11;
  int iVar12;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  int iVar13;
  undefined4 unaff_l5;
  int *piVar14;
  undefined4 unaff_l6;
  int iVar15;
  undefined4 unaff_l7;
  int iVar16;
  undefined4 unaff_i0;
  uint uVar17;
  uint uVar18;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  int iVar19;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool in_DECOMPILE_MODE;
  int in_CWP;
  undefined auStackX_0 [92];
  int aiStack_b8 [46];
  
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
  if ((*(uint *)(*_active_u + 0x28) & 0x2000000) == 0) {
    *(undefined2 *)(_active_u[7] + 2) = *(undefined2 *)(_active_u[7] + 6);
    *(undefined2 *)(*_active_u + 0x2c) = *(undefined2 *)(_active_u[7] + 6);
    *(undefined2 *)(_active_u[7] + 4) = *(undefined2 *)(_active_u[7] + 8);
    *(undefined *)(_active_u + 0x97) = 0;
    piVar14 = *(int **)(_active_threads + 0xc);
    iVar16 = piVar14[3];
    uVar17 = 0;
    if ((uint)_active_u[0xa0] <= *(uint *)(iVar16 + 0x28)) goto locret_F000A750;
    _task_halt(piVar14);
    _pcb_synch(_active_threads);
    puVar11 = (undefined *)((int)register0x00000038 + -0x48);
    *(undefined *)(dword_F0133DDC + 0x38) = 0;
    _vattr_null(puVar11);
    *(undefined4 *)((int)register0x00000038 + -0x48) = 1;
    *(undefined2 *)((int)register0x00000038 + -0x44) = 0x1a4;
    puVar8 = (undefined *)((int)register0x00000038 + -0x68);
    _sprintf(puVar8,aCoresCoreD,(int)*(sword *)(*_active_u + 0x30));
    _vn_create(puVar8,1,puVar11,0,0x80,(undefined *)((int)register0x00000038 + -0xbc),_active_u[7]);
    *(char *)(dword_F0133DDC + 0x38) = (char)puVar8;
    sVar1 = *(sword *)((int)register0x00000038 + -0x34);
    if (*(char *)(dword_F0133DDC + 0x38) != '\0') {
      *(undefined *)(dword_F0133DDC + 0x38) = 0;
      _vattr_null(puVar11);
      *(undefined4 *)((int)register0x00000038 + -0x48) = 1;
      *(undefined2 *)((int)register0x00000038 + -0x44) = 0x1a4;
      uVar4 = 0x18;
      _vn_create(&aCore,1,puVar11,0,0x80,(undefined *)((int)register0x00000038 + -0xbc),_active_u[7]
                );
      *(undefined *)(dword_F0133DDC + 0x38) = uVar4;
      sVar1 = *(sword *)((int)register0x00000038 + -0x34);
      if (*(char *)(dword_F0133DDC + 0x38) != '\0') goto loc_F000A3C8;
    }
    iVar9 = 0xe;
    if (sVar1 == 1) {
      _vattr_null((undefined *)((int)register0x00000038 + -0x48));
      *(undefined4 *)((int)register0x00000038 + -0x30) = 0;
      (**(code **)(*(int *)(*(int *)((int)register0x00000038 + -0xbc) + 0x1c) + 0x18))
                (*(int *)((int)register0x00000038 + -0xbc),
                 (undefined *)((int)register0x00000038 + -0x48),_active_u[7]);
      *(undefined4 *)((int)register0x00000038 + -0xc0) = 0x14;
      puVar8 = (undefined *)((int)register0x00000038 + -0xb8);
      *(word *)(_active_u + 0x90) = *(word *)(_active_u + 0x90) | 8;
      iVar13 = piVar14[9];
      iVar9 = *(int *)(iVar16 + 0x1c);
      iVar15 = _active_threads;
      _thread_getstatus(_active_threads,0,puVar8,(undefined *)((int)register0x00000038 + -0xc0));
      if (iVar15 != 0) {
        _panic(aCoreFlavorList);
      }
      iVar15 = 0;
      uVar18 = 0;
      uVar17 = *(uint *)((int)register0x00000038 + -0xc0) >> 1;
      *(uint *)((int)register0x00000038 + -0xc0) = uVar17;
      if (uVar17 != 0) {
        do {
          uVar18 = uVar18 + 1;
          iVar15 = iVar15 + 8 + *(int *)(puVar8 + 4) * 4;
          puVar8 = puVar8 + 8;
        } while (uVar18 < uVar17);
      }
      iVar10 = iVar15;
      .umul(iVar15,iVar13);
      iVar10 = (iVar13 + iVar9 * 7) * 8 + iVar10;
      iVar19 = iVar10 + 0x1c;
      iVar12 = 0x1c;
      _kmem_alloc_wired(_kernel_map,(undefined *)((int)register0x00000038 + -0xc4),iVar19);
      *(undefined4 *)((int)register0x00000038 + -200) = 0;
      puVar5 = *(undefined4 **)((int)register0x00000038 + -0xc4);
      *puVar5 = 0xfeedface;
      uVar17 = _page_mask;
      puVar5[1] = dword_F0134764;
      uVar17 = iVar19 + uVar17 & ~uVar17;
      puVar5[2] = dword_F0134768;
      puVar5[3] = 4;
      puVar5[4] = iVar9 + iVar13;
      puVar5[5] = iVar10;
      for (; 0 < iVar9; iVar9 = iVar9 + -1) {
        iVar10 = iVar16;
        _vm_region(iVar16,(undefined *)((int)register0x00000038 + -200),
                   (undefined *)((int)register0x00000038 + -0xcc),
                   (undefined *)((int)register0x00000038 + -0xd0),
                   (undefined *)((int)register0x00000038 + -0xd4),
                   (undefined *)((int)register0x00000038 + -0xd8),
                   (undefined *)((int)register0x00000038 + -0xdc),
                   (undefined *)((int)register0x00000038 + -0xe0),
                   (undefined *)((int)register0x00000038 + -0xe4));
        iVar2 = *(int *)((int)register0x00000038 + -0xc4);
        if (iVar10 == 3) break;
        uVar7 = *(undefined4 *)((int)register0x00000038 + -200);
        uVar6 = *(undefined4 *)((int)register0x00000038 + -0xcc);
        uVar18 = *(uint *)((int)register0x00000038 + -0xd0);
        *(undefined4 *)(iVar2 + iVar12) = 1;
        iVar2 = iVar2 + iVar12;
        *(undefined4 *)(iVar2 + 4) = 0x38;
        *(undefined4 *)(iVar2 + 0x18) = uVar7;
        *(undefined4 *)(iVar2 + 0x1c) = uVar6;
        *(uint *)(iVar2 + 0x20) = uVar17;
        *(undefined4 *)(iVar2 + 0x24) = uVar6;
        *(uint *)(iVar2 + 0x2c) = uVar18;
        *(undefined4 *)(iVar2 + 0x30) = 0;
        *(undefined4 *)(iVar2 + 0x28) = *(undefined4 *)((int)register0x00000038 + -0xd4);
        if ((uVar18 & 1) == 0) {
          _vm_protect(iVar16,uVar7,uVar6,0,uVar18 | 1);
        }
        if ((*(uint *)((int)register0x00000038 + -0xd4) & 1) != 0) {
          _vn_rdwr(1,*(undefined4 *)((int)register0x00000038 + -0xbc),
                   *(undefined4 *)((int)register0x00000038 + -200),
                   *(undefined4 *)((int)register0x00000038 + -0xcc),uVar17,0,1,0);
        }
        iVar12 = iVar12 + 0x38;
        uVar17 = uVar17 + *(int *)((int)register0x00000038 + -0xcc);
        *(int *)((int)register0x00000038 + -200) =
             *(int *)((int)register0x00000038 + -200) + *(int *)((int)register0x00000038 + -0xcc);
      }
      do {
        do {
        } while (*piVar14 != 0);
        piVar3 = piVar14;
        _simple_lock_try();
      } while (piVar3 == (int *)0x0);
      iVar16 = piVar14[7];
      if (0 < iVar13) {
        param_2 = iVar15 + 8;
        do {
          iVar9 = *(int *)((int)register0x00000038 + -0xc4);
          uVar17 = 0;
          *(undefined4 *)(iVar9 + iVar12) = 4;
          *(int *)(iVar9 + iVar12 + 4) = param_2;
          iVar12 = iVar12 + 8;
          puVar5 = (undefined4 *)((int)register0x00000038 + -0xb8);
          puVar8 = (undefined *)((int)register0x00000038 + -8);
          if (*(int *)((int)register0x00000038 + -0xc0) != 0) {
            do {
              iVar9 = *(int *)((int)register0x00000038 + -0xc4);
              uVar17 = uVar17 + 1;
              *(undefined4 *)(iVar9 + iVar12) = *(undefined4 *)(puVar8 + -0xb0);
              *(undefined4 *)(iVar9 + iVar12 + 4) = *(undefined4 *)(puVar8 + -0xac);
              _thread_getstatus(iVar16,*puVar5,iVar9 + iVar12 + 8,puVar5 + 1);
              iVar12 = iVar12 + 8 + puVar5[1] * 4;
              puVar5 = puVar5 + 2;
              puVar8 = puVar8 + 8;
            } while (uVar17 < *(uint *)((int)register0x00000038 + -0xc0));
          }
          iVar13 = iVar13 + -1;
          iVar16 = *(int *)(iVar16 + 0x10);
        } while (0 < iVar13);
      }
      *piVar14 = 0;
      iVar9 = 1;
      _vn_rdwr(1,*(undefined4 *)((int)register0x00000038 + -0xbc),
               *(undefined4 *)((int)register0x00000038 + -0xc4),iVar19,0,1,1,0);
      _kmem_free(_kernel_map,*(undefined4 *)((int)register0x00000038 + -0xc4),iVar19);
    }
    _vn_rele(*(undefined4 *)((int)register0x00000038 + -0xbc));
    uVar17 = (uint)(iVar9 == 0);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar9;
  }
  else {
loc_F000A3C8:
    uVar17 = 0;
  }
locret_F000A750:
  return CONCAT44(param_2,uVar17);
}

