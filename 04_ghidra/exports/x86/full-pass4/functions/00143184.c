/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00143184 */

/* WARNING: Removing unreachable block (ram,0x001434fc) */

int FUN_00143184(int *param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  int *piVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  uint local_88;
  void *local_60;
  byte *local_54;
  int local_50;
  int *local_4c;
  int local_48 [17];
  
  local_4c = (int *)0x0;
  local_50 = 0;
  if (DAT_001de3f0 == 0) {
    _ihinit();
    DAT_001de3f0 = 1;
  }
  uVar7 = 3;
  if ((*(byte *)(param_3 + 0xc) & 1) != 0) {
    uVar7 = 1;
  }
  iVar4 = (*(code *)**(undefined4 **)(*param_1 + 0x1c))
                    (param_1,uVar7,*(undefined4 *)(_active_u + 0x1c));
  if (iVar4 != 0) {
    return iVar4;
  }
  bVar2 = true;
  uVar5 = (**(code **)(*(int *)(*param_1 + 0x1c) + 0x80))(*param_1);
  if (uVar5 == 0) {
    uVar7 = 3;
    if ((*(byte *)(param_3 + 0xc) & 1) != 0) {
      uVar7 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))(*param_1,uVar7,1,*(undefined4 *)(_active_u + 0x1c))
    ;
    _binval(*param_1);
    return 0xf;
  }
  local_54 = (byte *)_bread(*param_1,(int)(0x2000 / (ulonglong)uVar5),0x2000);
  iVar4 = 0;
  piVar3 = _mounttab;
  if ((*local_54 & 4) == 0) {
    while (local_4c = piVar3, local_4c != (int *)0x0) {
      iVar1 = local_4c[3];
      if ((iVar1 != 0) && (*(short *)(*param_1 + 0x2c) == (short)local_4c[1])) {
        if ((*(byte *)(param_3 + 0xc) & 0x40) != 0) {
          iVar6 = *(int *)(local_54 + 0x20);
          _byte_swap_superblock(iVar6);
          local_50 = iVar1;
          goto LAB_00143414;
        }
        local_4c = (int *)0x0;
        iVar4 = 0x10;
        bVar2 = false;
        goto LAB_00143707;
      }
      piVar3 = (int *)local_4c[8];
    }
    _vol_notify_cancel((int)*(short *)(*param_1 + 0x2c));
    piVar3 = _mounttab;
    if ((*(uint *)(param_3 + 0xc) & 0x40) == 0) {
      while (local_4c = piVar3, local_4c != (int *)0x0) {
        if (local_4c[3] == 0) goto LAB_0014337a;
        piVar3 = (int *)local_4c[8];
      }
      local_4c = (int *)_kalloc(0x24);
      _bzero(local_4c,0x24);
      if (local_4c == (int *)0x0) {
        iVar4 = 0x18;
        goto LAB_00143714;
      }
      local_4c[8] = (int)_mounttab;
      _mounttab = local_4c;
LAB_0014337a:
      *(int **)(param_3 + 0x128) = local_4c;
      *local_4c = param_3;
      local_4c[3] = (int)local_54;
      *(undefined2 *)(local_4c + 1) = 0xffff;
      local_4c[2] = *param_1;
      iVar6 = *(int *)(local_54 + 0x20);
      _byte_swap_superblock(iVar6);
      if (((*(int *)(iVar6 + 0x55c) != 0x11954) || (0x2000 < (int)*(uint *)(iVar6 + 0x30))) ||
         (*(uint *)(iVar6 + 0x30) < 0x564)) {
        iVar4 = 0x16;
        goto LAB_00143714;
      }
      local_50 = _geteblk(*(undefined4 *)(iVar6 + 0x68));
      local_4c[3] = local_50;
      _bcopy(*(void **)(local_54 + 0x20),*(void **)(local_50 + 0x20),*(size_t *)(iVar6 + 0x68));
LAB_00143414:
      if ((*(byte *)(param_3 + 0xc) & 1) == 0) {
        *(undefined1 *)(DAT_001e875c + 0x68) = 0;
        _byte_swap_superblock(iVar6);
        _bwrite(local_54);
        if (*(char *)(DAT_001e875c + 0x68) == '\x1e') {
          *(undefined1 *)(DAT_001e875c + 0x68) = 0;
          if (*param_1 == _rootvp) {
                    /* WARNING: Subroutine does not return */
            _panic(s_Root_device_is_physically_write_p_001de416);
          }
          *(byte *)(param_3 + 0xc) = *(byte *)(param_3 + 0xc) | 1;
        }
        _byte_swap_superblock(iVar6);
      }
      else {
        _brelse(local_54);
      }
      local_54 = (byte *)0x0;
      iVar1 = *(int *)(local_50 + 0x20);
      if ((*(uint *)(param_3 + 0xc) & 1) == 0) {
        if (*(char *)(iVar1 + 0xd1) == '\x01') {
          *(undefined1 *)(iVar1 + 0xd1) = 2;
        }
        else {
          *(undefined1 *)(iVar1 + 0xd1) = 3;
        }
        *(undefined1 *)(iVar1 + 0xd0) = 1;
        *(undefined1 *)(iVar1 + 0xd2) = 0;
        if ((*(byte *)(param_3 + 0xc) & 0x40) != 0) {
          *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
          _sbupdate(local_4c);
          return 0;
        }
      }
      else {
        if ((*(uint *)(param_3 + 0xc) & 0x40) != 0) {
          pcVar9 = s_mountfs__can_t_remount_ro_001de458;
          goto LAB_0014349e;
        }
        *(undefined1 *)(iVar1 + 0xd0) = 0;
        *(undefined1 *)(iVar1 + 0xd2) = 1;
      }
      *(undefined4 *)(param_3 + 0x10) = *(undefined4 *)(iVar1 + 0x30);
      iVar6 = (*(int *)(iVar1 + 0x34) + -1 + *(int *)(iVar1 + 0x9c)) / *(int *)(iVar1 + 0x34);
      local_60 = (void *)_kalloc(*(int *)(iVar1 + 0x9c));
      if (local_60 != (void *)0x0) {
        iVar8 = 0;
        if (0 < iVar6) {
          do {
            local_88 = *(uint *)(iVar1 + 0x30);
            if (iVar6 < iVar8 + *(int *)(iVar1 + 0x38)) {
              local_88 = (iVar6 - iVar8) * *(int *)(iVar1 + 0x34);
            }
            local_54 = (byte *)_bread(local_4c[2],
                                      *(int *)(iVar1 + 0x98) + iVar8 <<
                                      ((byte)*(undefined4 *)(iVar1 + 100) & 0x1f),local_88);
            if ((*local_54 & 4) != 0) {
              _kfree(local_60,*(undefined4 *)(iVar1 + 0x9c));
              goto LAB_00143707;
            }
            _bcopy(*(void **)(local_54 + 0x20),local_60,local_88);
            _byte_swap_ints(local_60,local_88 >> 2);
            *(void **)(iVar1 + 0x2d8 + (iVar8 >> ((byte)*(undefined4 *)(iVar1 + 0x60) & 0x1f)) * 4)
                 = local_60;
            local_60 = (void *)((int)local_60 + local_88);
            _brelse(local_54);
            iVar8 = iVar8 + *(int *)(iVar1 + 0x38);
          } while (iVar8 < iVar6);
        }
        if (*(char *)(iVar1 + 0xd2) == '\0') {
          _sbupdate(local_4c);
        }
        *(byte *)(iVar1 + 0xd3) = *(byte *)(iVar1 + 0xd3) & 0xfc;
        iVar4 = (*(int *)(iVar1 + 0x28) * *(int *)(iVar1 + 0x3c)) / 100;
        *(int *)(iVar1 + 0x8c) = iVar4;
        *(int *)(iVar1 + 0x88) = iVar4;
        if (iVar4 < 0x65) {
          iVar4 = iVar4 * 2;
        }
        else {
          iVar4 = iVar4 + 100;
        }
        *(int *)(iVar1 + 0x88) = iVar4;
        iVar4 = (*(int *)(iVar1 + 0x2c) * *(int *)(iVar1 + 0xb8)) / 100;
        *(int *)(iVar1 + 0x94) = iVar4;
        if (0x32 < iVar4) {
          *(undefined4 *)(iVar1 + 0x94) = 0x32;
        }
        *(undefined4 *)(iVar1 + 0x90) = *(undefined4 *)(iVar1 + 0x94);
        *(undefined2 *)(local_4c + 1) = *(undefined2 *)(local_4c[2] + 0x2c);
        *(int *)(param_3 + 0x14) = (int)(short)local_4c[1];
        *(undefined4 *)(param_3 + 0x18) = 0;
        _copystr(param_2,iVar1 + 0xd4,0x1ff,local_48);
        _bzero((void *)(iVar1 + 0xd4 + local_48[0]),0x200 - local_48[0]);
        return 0;
      }
      iVar4 = 0xc;
      goto LAB_00143714;
    }
    *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) & 0xffffffbf;
    pcVar9 = s_mountfs__illegal_remount_request_001de3f4;
LAB_0014349e:
    _printf(pcVar9);
    iVar4 = 0x16;
  }
LAB_00143707:
  if (iVar4 == 0) {
    iVar4 = 5;
  }
LAB_00143714:
  if (local_4c != (int *)0x0) {
    local_4c[3] = 0;
  }
  if (local_50 != 0) {
    _brelse(local_50);
  }
  if (local_54 != (byte *)0x0) {
    _brelse(local_54);
  }
  if (bVar2) {
    uVar7 = 3;
    if ((*(byte *)(param_3 + 0xc) & 1) != 0) {
      uVar7 = 1;
    }
    (**(code **)(*(int *)(*param_1 + 0x1c) + 4))(*param_1,uVar7,1,*(undefined4 *)(_active_u + 0x1c))
    ;
    _binval(*param_1);
  }
  return iVar4;
}

