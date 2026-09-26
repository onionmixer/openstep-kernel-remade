/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013e9f8 */

int FUN_0013e9f8(uint param_1,uint param_2,uint param_3)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int local_8;
  
  iVar3 = 0;
  while ((*(ushort *)(param_1 + 0x44) & 1) != 0) {
    *(ushort *)(param_1 + 0x44) = *(ushort *)(param_1 + 0x44) | 0x10;
    _sleep(param_1);
  }
  uVar1 = *(ushort *)(param_1 + 0x44);
  *(ushort *)(param_1 + 0x44) = uVar1 | 1;
  if ((*(short *)(param_1 + 0x66) == 0) || (*(uint *)(param_1 + 0x6c) < 0x18)) {
    *(ushort *)(param_1 + 0x44) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(param_1 + 0x44) = uVar1 & 0xffee;
      _wakeup(param_1);
    }
LAB_0013ec0e:
    iVar3 = 0;
  }
  else {
    iVar2 = _blkatoff(param_1,0,&local_8);
    if (iVar2 == 0) {
      iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
    }
    else if (*(int *)(local_8 + 0xc) != *(int *)(param_3 + 0x48)) {
      if ((*(short *)(local_8 + 0x12) == 2) && (*(short *)(local_8 + 0x14) == 0x2e2e)) {
        *(short *)(param_3 + 0x66) = *(short *)(param_3 + 0x66) + 1;
        *(byte *)(param_3 + 0x44) = *(byte *)(param_3 + 0x44) | 0x40;
        _iupdat(param_3,1);
        _dnlc_remove(param_1 + 0xc,&DAT_001dde54);
        *(undefined4 *)(local_8 + 0xc) = *(undefined4 *)(param_3 + 0x48);
        _dnlc_enter(param_1 + 0xc,&DAT_001dde57,param_3 + 0xc,0);
        _byte_swap_dir_block_out(iVar2);
        _bwrite(iVar2);
        iVar2 = 0;
        if (*(char *)(DAT_001e875c + 0x68) == '\0') {
          uVar1 = *(ushort *)(param_1 + 0x44);
          *(ushort *)(param_1 + 0x44) = uVar1 & 0xfffe;
          if ((uVar1 & 0x10) != 0) {
            *(ushort *)(param_1 + 0x44) = uVar1 & 0xffee;
            _wakeup(param_1);
          }
          if (param_2 != 0) {
            uVar1 = *(ushort *)(param_3 + 0x44);
            *(ushort *)(param_3 + 0x44) = uVar1 & 0xfffe;
            if ((uVar1 & 0x10) != 0) {
              *(ushort *)(param_3 + 0x44) = uVar1 & 0xffee;
              _wakeup(param_3);
            }
            while ((*(ushort *)(param_2 + 0x44) & 1) != 0) {
              *(ushort *)(param_2 + 0x44) = *(ushort *)(param_2 + 0x44) | 0x10;
              _sleep(param_2);
            }
            *(byte *)(param_2 + 0x44) = *(byte *)(param_2 + 0x44) | 1;
            if (*(short *)(param_2 + 0x66) != 0) {
              *(short *)(param_2 + 0x66) = *(short *)(param_2 + 0x66) + -1;
              *(byte *)(param_2 + 0x44) = *(byte *)(param_2 + 0x44) | 0x40;
              _iupdat(param_2,1);
            }
            uVar1 = *(ushort *)(param_2 + 0x44);
            *(ushort *)(param_2 + 0x44) = uVar1 & 0xfffe;
            if ((uVar1 & 0x10) != 0) {
              *(ushort *)(param_2 + 0x44) = uVar1 & 0xffee;
              _wakeup(param_2);
            }
            while ((*(ushort *)(param_3 + 0x44) & 1) != 0) {
              *(ushort *)(param_3 + 0x44) = *(ushort *)(param_3 + 0x44) | 0x10;
              _sleep(param_3);
            }
            *(byte *)(param_3 + 0x44) = *(byte *)(param_3 + 0x44) | 1;
          }
          goto LAB_0013ec0e;
        }
        iVar3 = (int)*(char *)(DAT_001e875c + 0x68);
      }
      else {
        FUN_0013f5ac(param_1,s_mangled____entry_001dde43,0);
        iVar3 = 0x16;
      }
    }
    if (iVar2 != 0) {
      _byte_swap_dir_block_out(iVar2);
      _brelse(iVar2);
    }
    uVar1 = *(ushort *)(param_1 + 0x44);
    *(ushort *)(param_1 + 0x44) = uVar1 & 0xfffe;
    if ((uVar1 & 0x10) != 0) {
      *(ushort *)(param_1 + 0x44) = uVar1 & 0xffee;
      _wakeup(param_1);
    }
  }
  return iVar3;
}

