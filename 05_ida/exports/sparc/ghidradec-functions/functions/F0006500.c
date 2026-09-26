
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
