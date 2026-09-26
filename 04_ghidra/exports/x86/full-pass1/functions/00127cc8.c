/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00127cc8 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 _ip_setmoptions(undefined4 param_1,int *param_2,int param_3)

{
  byte bVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined4 *puVar7;
  int *piVar8;
  uint local_30;
  undefined4 uVar9;
  int local_18;
  undefined2 local_14;
  uint local_10;
  
  uVar9 = 0;
  if (*param_2 == 0) {
    uVar2 = _splimp();
    iVar3 = _mfree;
    *param_2 = _mfree;
    if (iVar3 == 0) {
      iVar3 = _m_more(1,0xe);
      *param_2 = iVar3;
    }
    else {
      if (*(short *)(iVar3 + 10) != 0) {
                    /* WARNING: Subroutine does not return */
        _panic(&DAT_001dbe15);
      }
      *(undefined2 *)(*param_2 + 10) = 0xe;
      _DAT_001e917c = _DAT_001e917c + -1;
      _DAT_001e9198 = _DAT_001e9198 + 1;
      _mfree = *(int *)*param_2;
      *(undefined4 *)*param_2 = 0;
      *(undefined4 *)(*param_2 + 4) = 0xc;
    }
    _splx(uVar2);
    iVar3 = *param_2;
    if (iVar3 == 0) {
      return 0x37;
    }
    puVar7 = (undefined4 *)(iVar3 + *(int *)(iVar3 + 4));
    *puVar7 = 0;
    *(undefined1 *)(puVar7 + 1) = 1;
    *(undefined1 *)((int)puVar7 + 5) = 1;
    *(undefined2 *)((int)puVar7 + 6) = 0;
  }
  piVar8 = (int *)(*param_2 + *(int *)(*param_2 + 4));
  switch(param_1) {
  case 3:
    if ((param_3 != 0) && (*(short *)(param_3 + 8) == 4)) {
      iVar3 = *(int *)(*(int *)(param_3 + 4) + param_3);
      iVar4 = _in_ifaddr;
      if (iVar3 == 0) {
        *piVar8 = 0;
        goto LAB_00128093;
      }
      for (; (iVar4 != 0 && (*(int *)(iVar4 + 4) != iVar3)); iVar4 = *(int *)(iVar4 + 0x40)) {
      }
      local_30 = 0;
      if (iVar4 != 0) {
        local_30 = *(int *)(iVar4 + 0x20);
      }
      if (local_30 != 0) {
        *piVar8 = local_30;
        goto LAB_00128093;
      }
LAB_00128059:
      uVar9 = 0x31;
      goto LAB_00128093;
    }
    break;
  case 4:
    if ((param_3 != 0) && (*(short *)(param_3 + 8) == 1)) {
      *(undefined1 *)(piVar8 + 1) = *(undefined1 *)(*(int *)(param_3 + 4) + param_3);
      goto LAB_00128093;
    }
    break;
  case 5:
    if (((param_3 != 0) && (*(short *)(param_3 + 8) == 1)) &&
       (bVar1 = *(byte *)(*(int *)(param_3 + 4) + param_3), bVar1 < 2)) {
      *(byte *)((int)piVar8 + 5) = bVar1;
      goto LAB_00128093;
    }
    break;
  case 6:
    if (((param_3 != 0) && (*(short *)(param_3 + 8) == 8)) &&
       (puVar5 = (uint *)(param_3 + *(int *)(param_3 + 4)), (*puVar5 & 0xf0) == 0xe0)) {
      iVar3 = _in_ifaddr;
      if (puVar5[1] == 0) {
        local_18 = 0;
        local_14 = 2;
        local_10 = *puVar5;
        _rtalloc(&local_18);
        if (local_18 == 0) goto LAB_00128059;
        local_30 = *(uint *)(local_18 + 0x2c);
        _rtfree(local_18);
      }
      else {
        for (; (iVar3 != 0 && (*(uint *)(iVar3 + 4) != puVar5[1])); iVar3 = *(int *)(iVar3 + 0x40))
        {
        }
        local_30 = 0;
        if (iVar3 != 0) {
          local_30 = *(uint *)(iVar3 + 0x20);
        }
      }
      if (local_30 != 0) {
        iVar3 = 0;
        if (*(ushort *)((int)piVar8 + 6) != 0) {
          do {
            if ((((uint *)piVar8[iVar3 + 2])[1] == local_30) &&
               (*(uint *)piVar8[iVar3 + 2] == *puVar5)) break;
            iVar3 = iVar3 + 1;
          } while (iVar3 < (int)(uint)*(ushort *)((int)piVar8 + 6));
          if (iVar3 < (int)(uint)*(ushort *)((int)piVar8 + 6)) {
            uVar9 = 0x30;
            goto LAB_00128093;
          }
        }
        if (iVar3 == 0x14) {
          uVar9 = 0x3b;
        }
        else {
          iVar4 = _in_addmulti(*puVar5,local_30);
          piVar8[iVar3 + 2] = iVar4;
          if (iVar4 == 0) {
            uVar9 = 0x37;
          }
          else {
            *(short *)((int)piVar8 + 6) = *(short *)((int)piVar8 + 6) + 1;
          }
        }
        goto LAB_00128093;
      }
      goto LAB_00128059;
    }
    break;
  case 7:
    if (((param_3 != 0) && (*(short *)(param_3 + 8) == 8)) &&
       (puVar5 = (uint *)(param_3 + *(int *)(param_3 + 4)), (*puVar5 & 0xf0) == 0xe0)) {
      iVar3 = _in_ifaddr;
      if (puVar5[1] == 0) {
        local_30 = 0;
      }
      else {
        for (; (iVar3 != 0 && (*(uint *)(iVar3 + 4) != puVar5[1])); iVar3 = *(int *)(iVar3 + 0x40))
        {
        }
        local_30 = 0;
        if (iVar3 != 0) {
          local_30 = *(int *)(iVar3 + 0x20);
        }
        if (local_30 == 0) goto LAB_00128059;
      }
      uVar6 = 0;
      if (*(ushort *)((int)piVar8 + 6) != 0) {
        do {
          if (((local_30 == 0) || (*(int *)(piVar8[uVar6 + 2] + 4) == local_30)) &&
             (*(uint *)piVar8[uVar6 + 2] == *puVar5)) break;
          uVar6 = uVar6 + 1;
        } while ((int)uVar6 < (int)(uint)*(ushort *)((int)piVar8 + 6));
      }
      if (uVar6 != *(ushort *)((int)piVar8 + 6)) {
        _in_delmulti(piVar8[uVar6 + 2]);
        while ((int)(uVar6 + 1) < (int)(uint)*(ushort *)((int)piVar8 + 6)) {
          piVar8[uVar6 + 2] = piVar8[uVar6 + 3];
          uVar6 = uVar6 + 1;
        }
        *(short *)((int)piVar8 + 6) = *(short *)((int)piVar8 + 6) + -1;
        goto LAB_00128093;
      }
      goto LAB_00128059;
    }
    break;
  default:
    uVar9 = 0x2d;
    goto LAB_00128093;
  }
  uVar9 = 0x16;
LAB_00128093:
  if ((*piVar8 == 0) && (piVar8[1] == 0x101)) {
    _m_free(*param_2);
    *param_2 = 0;
  }
  return uVar9;
}

