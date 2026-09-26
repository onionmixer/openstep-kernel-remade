/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013f1a4 */

/* WARNING: Type propagation algorithm not settling */

int _dirremove(uint param_1,char *param_2,int param_3,int param_4)

{
  short *psVar1;
  char cVar2;
  short sVar3;
  ushort uVar4;
  int iVar5;
  uint uVar6;
  char *pcVar7;
  int iVar8;
  int local_1c [3];
  int local_10;
  int local_c;
  undefined4 *local_8;
  
  uVar6 = 0xffffffff;
  pcVar7 = param_2;
  do {
    if (uVar6 == 0) break;
    uVar6 = uVar6 - 1;
    cVar2 = *pcVar7;
    pcVar7 = pcVar7 + 1;
  } while (cVar2 != '\0');
  iVar5 = ~uVar6 - 1;
  if (iVar5 == 0) {
                    /* WARNING: Subroutine does not return */
    _panic(s_dirremove_001ddeda);
  }
  if (*param_2 == '.') {
    if (iVar5 == 1) {
      return 0x16;
    }
    if ((iVar5 == 2) && (param_2[1] == '.')) {
      return 0x42;
    }
  }
  local_1c[0] = 0;
  local_c = 0;
  while ((*(ushort *)(param_1 + 0x44) & 1) != 0) {
    *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x10;
    _sleep(param_1);
  }
  *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 1;
  if ((*(ushort *)(param_1 + 100) & 0xf000) == 0x4000) {
    iVar8 = _iaccess(param_1,0xc0);
    if (iVar8 == 0) {
      local_1c[1] = 2;
      iVar8 = FUN_0013e5c8(param_1,param_2,iVar5,local_1c + 1,local_1c);
      if (iVar8 == 0) {
        if ((local_1c[0] == 0) || ((param_3 != 0 && (param_3 != local_1c[0])))) {
          iVar8 = 2;
        }
        else if (((((*(byte *)(param_1 + 0x65) & 2) == 0) ||
                  (sVar3 = *(short *)(*(int *)(_active_u + 0x1c) + 2), sVar3 == 0)) ||
                 (*(short *)(param_1 + 0x68) == sVar3)) || (*(short *)(local_1c[0] + 0x68) == sVar3)
                ) {
          if (*(int *)(local_1c[0] + 0x18) == 0) {
            if (((param_4 == 0) || ((*(ushort *)(local_1c[0] + 100) & 0xf000) != 0x4000)) ||
               ((*(short *)(local_1c[0] + 0x66) == 2 &&
                (iVar5 = FUN_0013f5e4(local_1c[0],*(undefined4 *)(param_1 + 0x48)), iVar5 != 0)))) {
              _dnlc_remove(param_1 + 0xc,param_2);
              if ((local_1c[2] & 0x3ffU) == 0) {
                *local_8 = 0;
              }
              else {
                psVar1 = (short *)((int)local_8 + (4 - local_10));
                *psVar1 = *psVar1 + *(short *)(local_8 + 1);
              }
              _byte_swap_dir_block_out(local_c);
              _bwrite(local_c);
              local_c = 0;
              *(byte *)(param_1 + 0x44) = *(byte *)(param_1 + 0x44) | 0x42;
              *(byte *)(local_1c[0] + 0x44) = *(byte *)(local_1c[0] + 0x44) | 0x40;
              if (*(char *)(DAT_001e875c + 0x68) == '\0') {
                if (0 < *(short *)(local_1c[0] + 0x66)) {
                  if ((param_4 == 0) || ((*(ushort *)(local_1c[0] + 100) & 0xf000) != 0x4000)) {
                    *(short *)(local_1c[0] + 0x66) = *(short *)(local_1c[0] + 0x66) + -1;
                  }
                  else {
                    *(short *)(local_1c[0] + 0x66) = *(short *)(local_1c[0] + 0x66) + -2;
                    *(short *)(param_1 + 0x66) = *(short *)(param_1 + 0x66) + -1;
                    _dnlc_remove(local_1c[0] + 0xc,&DAT_001ddee4);
                    _dnlc_remove(local_1c[0] + 0xc,&DAT_001ddee6);
                    _itrunc(local_1c[0],0);
                  }
                }
              }
              else {
                iVar8 = (int)*(char *)(DAT_001e875c + 0x68);
              }
            }
            else {
              iVar8 = 0x42;
            }
          }
          else {
            iVar8 = 0x10;
          }
        }
        else {
          iVar8 = 1;
        }
      }
    }
  }
  else {
    iVar8 = 0x14;
  }
  if ((local_1c[0] != 0) && (_iput(local_1c[0]), *(short *)(local_1c[0] + 0x66) == 0)) {
    _vnode_uncache(local_1c[0] + 0xc);
  }
  iVar5 = local_c;
  if (local_c != 0) {
    _byte_swap_dir_block_out(local_c);
    _brelse(iVar5);
  }
  uVar4 = *(ushort *)(param_1 + 0x44);
  *(ushort *)(param_1 + 0x44) = uVar4 & 0xfffe;
  if ((uVar4 & 0x10) != 0) {
    *(ushort *)(param_1 + 0x44) = uVar4 & 0xffee;
    _wakeup(param_1);
  }
  return iVar8;
}

