/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013e19c */

/* WARNING: Type propagation algorithm not settling */

int _direnter(uint param_1,char *param_2,int param_3,uint param_4,uint param_5,undefined4 param_6,
             uint *param_7)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  undefined1 uVar4;
  uint *puVar5;
  char *pcVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  uint local_1c [4];
  int local_c;
  
  iVar9 = 0;
  cVar1 = *param_2;
  pcVar6 = param_2;
  while (cVar1 != '\0') {
    if (*pcVar6 == '/') {
      return 0xd;
    }
    pcVar6 = pcVar6 + 1;
    iVar9 = iVar9 + 1;
    cVar1 = *pcVar6;
  }
  if (iVar9 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_direnter_001dde14);
  }
  if ((*param_2 != '.') || ((iVar9 != 1 && ((iVar9 != 2 || (param_2[1] != '.')))))) {
    local_1c[1] = 0;
    local_c = 0;
    if (param_3 != 0) {
      while ((*(byte *)(param_5 + 0x44) & 1) != 0) {
        *(byte *)(param_5 + 0x44) = *(byte *)(param_5 + 0x44) | 0x10;
        _sleep(param_5);
      }
      uVar2 = *(ushort *)(param_5 + 0x44);
      *(ushort *)(param_5 + 0x44) = uVar2 | 1;
      sVar3 = *(short *)(param_5 + 0x66);
      uVar7 = (undefined1)(uVar2 | 1);
      uVar4 = (undefined1)(uVar2 >> 8);
      if (sVar3 == 0) {
        *(ushort *)(param_5 + 0x44) = CONCAT11(uVar4,uVar7) & 0xfffe;
        if ((uVar2 & 0x10) != 0) {
          *(ushort *)(param_5 + 0x44) = uVar2 & 0xffee;
          _wakeup(param_5);
        }
        return 2;
      }
      if (sVar3 == 0x7fff) {
        *(ushort *)(param_5 + 0x44) = CONCAT11(uVar4,uVar7) & 0xfffe;
        if ((uVar2 & 0x10) != 0) {
          *(ushort *)(param_5 + 0x44) = uVar2 & 0xffee;
          _wakeup(param_5);
        }
        return 0x1f;
      }
      *(short *)(param_5 + 0x66) = sVar3 + 1;
      *(byte *)(param_5 + 0x44) = *(byte *)(param_5 + 0x44) | 0x40;
      _iupdat(param_5,1);
      uVar2 = *(ushort *)(param_5 + 0x44);
      *(ushort *)(param_5 + 0x44) = uVar2 & 0xfffe;
      if ((uVar2 & 0x10) != 0) {
        *(ushort *)(param_5 + 0x44) = uVar2 & 0xffee;
        _wakeup(param_5);
      }
    }
    while ((*(ushort *)(param_1 + 0x44) & 1) != 0) {
      *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x10;
      _sleep(param_1);
    }
    *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 1;
    if ((*(ushort *)(param_1 + 100) & 0xf000) == 0x4000) {
      if (*(short *)(param_1 + 0x66) == 0) {
        iVar8 = 2;
      }
      else {
        iVar8 = _iaccess(param_1,0x40);
        if ((iVar8 == 0) &&
           ((((param_3 != 2 || ((*(ushort *)(param_5 + 100) & 0xf000) != 0x4000)) ||
             (param_4 == param_1)) ||
            ((iVar8 = _iaccess(param_5,0x80), iVar8 == 0 &&
             (iVar8 = FUN_0013f66c(param_5,param_1), iVar8 == 0)))))) {
          puVar5 = local_1c + 1;
          iVar8 = FUN_0013e5c8(param_1,param_2,iVar9,puVar5,local_1c);
          if (iVar8 == 0) {
            if (local_1c[0] == 0) {
              iVar8 = _iaccess(param_1,0x80);
              if ((iVar8 == 0) &&
                 ((param_3 != 0 || (iVar8 = FUN_0013ef04(param_1,&param_5,param_6), iVar8 == 0)))) {
                iVar8 = _diraddentry(param_1,param_2,iVar9,puVar5,param_5,param_4);
                if (iVar8 == 0) {
                  if (param_7 == (uint *)0x0) {
                    if (param_3 == 0) {
                      _irele(param_5);
                    }
                  }
                  else {
                    while ((*(byte *)(param_5 + 0x44) & 1) != 0) {
                      *(byte *)(param_5 + 0x44) = *(byte *)(param_5 + 0x44) | 0x10;
                      _sleep(param_5);
                    }
                    *(byte *)(param_5 + 0x44) = *(byte *)(param_5 + 0x44) | 1;
                    *param_7 = param_5;
                  }
                }
                else if (param_3 == 0) {
                  if ((*(ushort *)(param_5 + 100) & 0xf000) == 0x4000) {
                    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -1;
                  }
                  *(undefined2 *)(param_5 + 0x66) = 0;
                  *(byte *)(param_5 + 0x44) = *(byte *)(param_5 + 0x44) | 0x40;
                  _irele(param_5);
                  param_5 = 0;
                }
              }
            }
            else if (param_3 == 1) {
              _iput(local_1c[0]);
              iVar8 = 0x11;
            }
            else if (param_3 == 0) {
              if (param_7 == (uint *)0x0) {
                _iput(local_1c[0]);
              }
              else {
                *param_7 = local_1c[0];
                iVar8 = 0x11;
              }
            }
            else if (param_3 == 2) {
              iVar8 = FUN_0013e838(param_4,param_5,param_1,param_2,iVar9,local_1c[0],puVar5);
              _iput(local_1c[0]);
              if (*(short *)(local_1c[0] + 0x66) == 0) {
                _vnode_uncache(local_1c[0] + 0xc);
              }
            }
          }
        }
      }
    }
    else {
      iVar8 = 0x14;
    }
    iVar9 = local_c;
    if (local_c != 0) {
      _byte_swap_dir_block_out(local_c);
      _brelse(iVar9);
    }
    if ((iVar8 != 0) && (param_3 != 0)) {
      *(short *)(param_5 + 0x66) = *(short *)(param_5 + 0x66) + -1;
      *(byte *)(param_5 + 0x44) = *(byte *)(param_5 + 0x44) | 0x40;
    }
    uVar2 = *(ushort *)(param_1 + 0x44);
    *(ushort *)(param_1 + 0x44) = uVar2 & 0xfffe;
    if ((uVar2 & 0x10) != 0) {
      *(ushort *)(param_1 + 0x44) = uVar2 & 0xffee;
      _wakeup(param_1);
    }
    return iVar8;
  }
  if (param_3 == 2) {
    return 0x42;
  }
  if ((param_7 != (uint *)0x0) && (iVar9 = _dirlook(param_1,param_2,param_7), iVar9 != 0)) {
    return iVar9;
  }
  return 0x11;
}

