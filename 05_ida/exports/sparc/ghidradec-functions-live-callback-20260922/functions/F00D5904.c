
/* WARNING: Removing unreachable block (ram,0xf00d5c74) */
/* WARNING: Removing unreachable block (ram,0xf00d5c88) */
/* WARNING: Removing unreachable block (ram,0xf00d5c7c) */
/* WARNING: Removing unreachable block (ram,0xf00d5c94) */
/* WARNING: Removing unreachable block (ram,0xf00d5910) */

undefined8
-[KeyMap _parseKeyMapping:length:into:]
          (undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined2 *param_5)

{
  byte bVar1;
  int iVar2;
  uint uVar3;
  undefined2 *puVar4;
  word *pwVar5;
  uint uVar6;
  word wVar7;
  uint uVar8;
  int iVar9;
  int iVar10;
  undefined4 unaff_l0;
  int iVar11;
  undefined4 unaff_l1;
  undefined4 unaff_l3;
  undefined4 unaff_l4;
  undefined4 unaff_l5;
  undefined4 unaff_l6;
  undefined4 unaff_l7;
  undefined4 unaff_i0;
  undefined4 unaff_i1;
  undefined4 unaff_i2;
  uint uVar12;
  undefined4 unaff_i3;
  undefined4 unaff_i4;
  undefined4 unaff_i5;
  undefined4 unaff_fp;
  undefined4 unaff_i7;
  bool bVar13;
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
  iVar11 = -1;
  _bzero(param_5,0x4f0);
  *(undefined4 *)(param_5 + 0x42) = 0xffffffff;
  *(undefined4 *)(param_5 + 100) = 0xffffffff;
  *(undefined4 *)(param_5 + 0x166) = 0xffffffff;
  *(int *)((int)register0x00000038 + -0x1c) = param_3 + param_4;
  *(int *)((int)register0x00000038 + -0x20) = param_3;
  *(undefined4 *)((int)register0x00000038 + -0x18) = 1;
  *(int *)(param_5 + 0x274) = param_3;
  *(int *)(param_5 + 0x276) = param_4;
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  *(uint *)((int)register0x00000038 + -0x18) = uVar3;
  *param_5 = (sword)uVar3;
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  iVar2 = 0;
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  if (uVar3 != 0) {
    do {
      uVar8 = 0;
      if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
        if (*(int *)((int)register0x00000038 + -0x18) == 0) {
          *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
          uVar8 = (uint)*(byte *)pwVar5;
        }
        else {
          *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
          uVar8 = (uint)*pwVar5;
        }
      }
      if (0xf < uVar8) {
        param_1 = 0;
        goto locret_F00D5F7C;
      }
      if (*(int *)(param_5 + 0x42) < (int)uVar8) {
        *(uint *)(param_5 + 0x42) = uVar8;
      }
      *(undefined4 *)(param_5 + uVar8 * 2 + 0x44) = *(undefined4 *)((int)register0x00000038 + -0x20)
      ;
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
      iVar9 = 0;
      if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
        if (*(int *)((int)register0x00000038 + -0x18) == 0) {
          *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
          uVar12 = (uint)*(byte *)pwVar5;
        }
        else {
          *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
          uVar12 = (uint)*pwVar5;
        }
      }
      else {
        uVar12 = 0;
      }
      if (uVar12 != 0) {
        do {
          pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
              uVar6 = (uint)*(byte *)pwVar5;
            }
            else {
              *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
              uVar6 = (uint)*pwVar5;
            }
          }
          else {
            uVar6 = 0;
          }
          if ((0x7f < uVar6) || (bVar1 = *(byte *)((int)param_5 + uVar6 + 2), (bVar1 & 0x10) != 0))
          goto loc_F00D5F3C;
          iVar9 = iVar9 + 1;
          *(byte *)((int)param_5 + uVar6 + 2) = bVar1 | (byte)uVar8 & 0xf | 0x10;
        } while (iVar9 < (int)uVar12);
      }
      iVar2 = iVar2 + 1;
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
    } while (iVar2 < (int)uVar3);
  }
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  *(uint *)(param_5 + 100) = uVar3;
  iVar2 = 0;
  puVar4 = param_5;
  do {
    if (iVar2 < (int)uVar3) {
      *(undefined4 *)(puVar4 + 0x66) = *(undefined4 *)((int)register0x00000038 + -0x20);
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
      uVar8 = 0;
      if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
        if (*(int *)((int)register0x00000038 + -0x18) == 0) {
          *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
          uVar8 = (uint)*(byte *)pwVar5;
        }
        else {
          *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
          uVar8 = (uint)*pwVar5;
        }
      }
      if (*(int *)((int)register0x00000038 + -0x18) == 0) {
        if (uVar8 != 0xff) goto loc_F00D5BD4;
        *(undefined4 *)(puVar4 + 0x66) = 0;
      }
      else if (uVar8 == 0xffff) {
        *(undefined4 *)(puVar4 + 0x66) = 0;
      }
      else {
loc_F00D5BD4:
        iVar9 = 0;
        *(byte *)((int)param_5 + iVar2 + 2) = *(byte *)((int)param_5 + iVar2 + 2) | 0x20;
        iVar10 = 1;
        if (*(uint *)(param_5 + 0x42) < 0x80000000) {
          do {
            if ((uVar8 & 1) != 0) {
              iVar10 = iVar10 << 1;
            }
            iVar9 = iVar9 + 1;
            uVar8 = (int)uVar8 >> 1;
          } while (iVar9 <= (int)*(uint *)(param_5 + 0x42));
        }
        iVar9 = 0;
        if (0 < iVar10) {
          pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          do {
            wVar7 = 0;
            if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
              if (*(int *)((int)register0x00000038 + -0x18) == 0) {
                *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
                wVar7 = (word)*(byte *)pwVar5;
              }
              else {
                *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
                wVar7 = *pwVar5;
              }
            }
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              if (wVar7 == 0xff) goto loc_F00D5CC0;
            }
            else if (wVar7 == 0xffff) {
loc_F00D5CC0:
              if (iVar11 < 0) {
                iVar11 = 0;
              }
            }
            iVar9 = iVar9 + 1;
            pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          } while (iVar9 < iVar10);
        }
      }
    }
    else {
      *(undefined4 *)(puVar4 + 0x66) = 0;
    }
    iVar2 = iVar2 + 1;
    puVar4 = puVar4 + 2;
  } while (iVar2 < 0x80);
  pwVar5 = *(word **)((int)register0x00000038 + -0x20);
  uVar3 = 0;
  if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
    if (*(int *)((int)register0x00000038 + -0x18) == 0) {
      *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
      uVar3 = (uint)*(byte *)pwVar5;
    }
    else {
      *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
      uVar3 = (uint)*pwVar5;
    }
  }
  *(uint *)(param_5 + 0x166) = uVar3;
  if (iVar11 < (int)uVar3) {
    iVar11 = 0;
    pwVar5 = *(word **)((int)register0x00000038 + -0x20);
    puVar4 = param_5;
    if (uVar3 != 0) {
      do {
        *(undefined4 *)(puVar4 + 0x168) = *(undefined4 *)((int)register0x00000038 + -0x20);
        pwVar5 = *(word **)((int)register0x00000038 + -0x20);
        iVar2 = 0;
        if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
          if (*(int *)((int)register0x00000038 + -0x18) == 0) {
            *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
            uVar3 = (uint)*(byte *)pwVar5;
          }
          else {
            *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
            uVar3 = (uint)*pwVar5;
          }
        }
        else {
          uVar3 = 0;
        }
        if (uVar3 == 0) {
          iVar2 = *(int *)(param_5 + 0x166);
        }
        else {
          uVar8 = *(uint *)((int)register0x00000038 + -0x20);
          do {
            if (uVar8 < *(uint *)((int)register0x00000038 + -0x1c)) {
              if (*(int *)((int)register0x00000038 + -0x18) == 0) {
                iVar9 = uVar8 + 1;
              }
              else {
                iVar9 = uVar8 + 2;
              }
              *(int *)((int)register0x00000038 + -0x20) = iVar9;
            }
            uVar8 = *(uint *)((int)register0x00000038 + -0x20);
            if (uVar8 < *(uint *)((int)register0x00000038 + -0x1c)) {
              if (*(int *)((int)register0x00000038 + -0x18) == 0) {
                iVar9 = uVar8 + 1;
              }
              else {
                iVar9 = uVar8 + 2;
              }
              *(int *)((int)register0x00000038 + -0x20) = iVar9;
            }
            iVar2 = iVar2 + 1;
            uVar8 = *(uint *)((int)register0x00000038 + -0x20);
          } while (iVar2 < (int)uVar3);
          iVar2 = *(int *)(param_5 + 0x166);
        }
        iVar11 = iVar11 + 1;
        puVar4 = puVar4 + 2;
      } while (iVar11 < iVar2);
      pwVar5 = *(word **)((int)register0x00000038 + -0x20);
    }
    uVar3 = 0;
    if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
      if (*(int *)((int)register0x00000038 + -0x18) == 0) {
        *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
        uVar3 = (uint)*(byte *)pwVar5;
      }
      else {
        *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
        uVar3 = (uint)*pwVar5;
      }
    }
    if (9 < uVar3) {
      param_1 = 0;
      goto locret_F00D5F7C;
    }
    if (uVar3 != 0) {
      param_5[0x272] = 0xffff;
      puVar4 = param_5 + 8;
      while ((int)param_5 <= (int)(puVar4 + -1)) {
        puVar4[0x269] = 0xffff;
        puVar4 = puVar4 + -1;
      }
      iVar11 = 0;
      if (uVar3 != 0) {
        do {
          pwVar5 = *(word **)((int)register0x00000038 + -0x20);
          uVar8 = 0;
          bVar13 = false;
          if (pwVar5 < *(word **)((int)register0x00000038 + -0x1c)) {
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
              uVar8 = (uint)*(byte *)pwVar5;
            }
            else {
              *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
              uVar8 = (uint)*pwVar5;
            }
            pwVar5 = *(word **)((int)register0x00000038 + -0x20);
            bVar13 = pwVar5 < *(word **)((int)register0x00000038 + -0x1c);
          }
          if (bVar13) {
            if (*(int *)((int)register0x00000038 + -0x18) == 0) {
              *(byte **)((int)register0x00000038 + -0x20) = (byte *)((int)pwVar5 + 1);
              wVar7 = (word)*(byte *)pwVar5;
            }
            else {
              *(word **)((int)register0x00000038 + -0x20) = pwVar5 + 1;
              wVar7 = *pwVar5;
            }
          }
          else {
            wVar7 = 0;
          }
          if (8 < uVar8) goto loc_F00D5F3C;
          iVar11 = iVar11 + 1;
          param_5[uVar8 + 0x26a] = wVar7;
        } while (iVar11 < (int)uVar3);
      }
      iVar11 = 0;
      puVar4 = param_5;
      do {
        uVar3 = (uint)(word)puVar4[0x26a];
        iVar11 = iVar11 + 1;
        if (uVar3 != 0xffff) {
          *(byte *)((int)param_5 + uVar3 + 2) = *(byte *)((int)param_5 + uVar3 + 2) | 0x60;
        }
        puVar4 = puVar4 + 1;
      } while (iVar11 < 7);
      goto locret_F00D5F7C;
    }
  }
loc_F00D5F3C:
  param_1 = 0;
locret_F00D5F7C:
  return CONCAT44(param_2,param_1);
}

