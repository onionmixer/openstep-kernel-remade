
/* WARNING: Removing unreachable block (ram,0xf000ab00) */
/* WARNING: Removing unreachable block (ram,0xf000ac58) */
/* WARNING: Removing unreachable block (ram,0xf000acb0) */
/* WARNING: Removing unreachable block (ram,0xf000aef4) */
/* WARNING: Removing unreachable block (ram,0xf000ade0) */
/* WARNING: Removing unreachable block (ram,0xf000acc8) */
/* WARNING: Removing unreachable block (ram,0xf000ac1c) */
/* WARNING: Removing unreachable block (ram,0xf000ac90) */
/* WARNING: Removing unreachable block (ram,0xf000ab58) */
/* WARNING: Removing unreachable block (ram,0xf000ad38) */

undefined8 _fcntl(undefined4 param_1,undefined4 param_2)

{
  sword sVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  undefined4 unaff_l0;
  undefined *puVar8;
  undefined4 unaff_l1;
  int iVar9;
  uint *puVar10;
  undefined4 unaff_l3;
  byte *pbVar11;
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
  puVar10 = *(uint **)(dword_F0133DDC + 0x24);
  uVar4 = *puVar10;
  if ((((uint)_active_u[0x56] <= uVar4) ||
      (iVar9 = *(int *)(_active_u[0x53] + uVar4 * 4), iVar9 == 0)) || (iVar9 == -0x10000))
  goto loc_F000ADC8;
  pbVar11 = (byte *)(_active_u[0x54] + uVar4);
  switch(puVar10[1]) {
  case :
    uVar4 = puVar10[2];
    if (0xff < uVar4) goto loc_F000AE38;
    _ufalloc();
    if ((int)uVar4 < 0) break;
    if (iVar9 == *(int *)(_active_u[0x53] + *puVar10 * 4)) {
      _dupit(uVar4,iVar9,(int)(char)(*pbVar11 & 0xfe));
      break;
    }
    *(undefined4 *)(_active_u[0x53] + uVar4 * 4) = 0;
    goto loc_F000ADC8;
  case :
    *(uint *)(dword_F0133DDC + 0x30) = *pbVar11 & 1;
    break;
  case :
    *pbVar11 = *pbVar11 & 0xfe | (byte)puVar10[2] & 1;
    break;
  case :
    *(int *)(dword_F0133DDC + 0x30) = *(int *)(iVar9 + 8) + -1;
    break;
  case :
    uVar4 = *(uint *)(iVar9 + 8);
    if ((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) {
      uVar2 = 0x21b3;
    }
    else {
      uVar2 = 0x400031b3;
    }
    puVar8 = (undefined *)((int)register0x00000038 + -0x24);
    uVar7 = puVar10[2] + 1;
    *(uint *)((int)register0x00000038 + -0x24) = (uVar7 & 4) >> 2;
    iVar3 = iVar9;
    _fioctl(iVar9,0x8004667e,puVar8);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar3;
    if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
      *(uint *)((int)register0x00000038 + -0x24) = (uVar7 & 0x40) >> 6;
      iVar3 = iVar9;
      _fioctl(iVar9,0x8004667d,puVar8);
      *(char *)(dword_F0133DDC + 0x38) = (char)iVar3;
      if (*(char *)(dword_F0133DDC + 0x38) == '\0') {
        *(uint *)(iVar9 + 8) = uVar4 & uVar2 | uVar7 & 0xffffde4c;
      }
      else {
        *(uint *)((int)register0x00000038 + -0x24) = *(uint *)(iVar9 + 8) >> 2 & 1;
        _fioctl(iVar9,0x8004667e,puVar8);
      }
    }
    break;
  case :
    _fgetown(iVar9,dword_F0133DDC + 0x30);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar9;
    break;
  case :
    _fsetown(iVar9,puVar10[2]);
    *(char *)(dword_F0133DDC + 0x38) = (char)iVar9;
    break;
  case :
  case :
  case :
    if (*(sword *)(iVar9 + 0xc) == 1) {
      if (((*(uint *)(*_active_u + 0x14) & 0x4000) == 0) ||
         (*(int *)(*(int *)(iVar9 + 0x18) + 0x28) != 1)) goto loc_F000AE38;
      uVar4 = puVar10[2];
      _copyin(uVar4,(undefined *)((int)register0x00000038 + -0x20),0x14);
      *(char *)(dword_F0133DDC + 0x38) = (char)uVar4;
      if ((uVar4 & 0xff) != 0) break;
      sVar1 = *(sword *)((int)register0x00000038 + -0x20);
      if (sVar1 == 2) {
        if (puVar10[1] != 7) {
          uVar4 = *(uint *)(iVar9 + 8) & 2;
loc_F000ADBC:
          if (uVar4 == 0) goto loc_F000ADC8;
        }
loc_F000ADDC:
        puVar8 = (undefined *)((int)register0x00000038 + -0x20);
        _rewhence(puVar8,iVar9,0);
        *(char *)(dword_F0133DDC + 0x38) = (char)puVar8;
        if (((uint)puVar8 & 0xff) != 0) break;
        iVar5 = *(int *)((int)register0x00000038 + -0x18);
        iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        if (iVar5 < 0) {
          *(int *)((int)register0x00000038 + -0x18) = -iVar5;
          *(int *)((int)register0x00000038 + -0x1c) = iVar3 + iVar5;
          iVar3 = *(int *)((int)register0x00000038 + -0x1c);
        }
        if (-1 < iVar3) {
          if ((puVar10[1] != 7) && (*(sword *)((int)register0x00000038 + -0x20) != 3)) {
            *pbVar11 = *pbVar11 | 4;
            *(uint *)(*_active_u + 0x28) = *(uint *)(*_active_u + 0x28) | 0x20000000;
          }
          uVar4 = *(uint *)(iVar9 + 0x18);
          puVar8 = (undefined *)((int)register0x00000038 + -0x20);
          (**(code **)(*(int *)(uVar4 + 0x1c) + 0x60))
                    (uVar4,puVar8,puVar10[1],*(undefined4 *)(iVar9 + 0x20),
                     (int)*(sword *)(*_active_u + 0x30));
          *(char *)(dword_F0133DDC + 0x38) = (char)uVar4;
          if (((uVar4 & 0xff) == 0) && (puVar10[1] == 7)) {
            if (*(sword *)((int)register0x00000038 + -0x20) == 3) {
              uVar4 = puVar10[2];
              uVar6 = 2;
            }
            else {
              uVar4 = puVar10[2];
              uVar6 = 0x14;
            }
            _copyout(puVar8,uVar4,uVar6);
            *(char *)(dword_F0133DDC + 0x38) = (char)puVar8;
          }
          break;
        }
      }
      else if (sVar1 < 3) {
        if (sVar1 == 1) {
          if (puVar10[1] != 7) {
            uVar4 = *(uint *)(iVar9 + 8) & 1;
            goto loc_F000ADBC;
          }
          goto loc_F000ADDC;
        }
      }
      else if (sVar1 == 3) goto loc_F000ADDC;
loc_F000AE38:
      *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
      break;
    }
loc_F000ADC8:
    *(undefined *)(dword_F0133DDC + 0x38) = 9;
    break;
  :
    *(undefined *)(dword_F0133DDC + 0x38) = 0x16;
  }
  return CONCAT44(param_2,param_1);
}
