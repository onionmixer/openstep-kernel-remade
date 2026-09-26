/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0013ef04 */

int FUN_0013ef04(int param_1,int *param_2,int *param_3)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int local_8;
  
  local_8 = 0;
  if (param_3 != (int *)0x0) {
    iVar2 = *param_3;
    if (iVar2 == 2) {
      uVar4 = _dirpref(*(undefined4 *)(param_1 + 0x50));
    }
    else {
      uVar4 = *(undefined4 *)(param_1 + 0x48);
    }
    uVar1 = *(ushort *)(param_3 + 1);
    uVar3 = *(uint *)(&_vttoif_tab + iVar2 * 4);
    iVar5 = _ialloc(param_1,uVar4,uVar3 | uVar1);
    if (iVar5 == 0) {
      local_8 = (int)*(char *)(DAT_001e875c + 0x68);
    }
    else {
      *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) | 0x46;
      *(short *)(iVar5 + 100) = (short)(uVar3 | uVar1);
      if ((iVar2 - 3U < 2) || (iVar2 == 9)) {
        iVar6 = param_3[0xe];
        *(int *)(iVar5 + 0x8c) = (int)(short)iVar6;
        *(short *)(iVar5 + 0x38) = (short)iVar6;
      }
      *(int *)(iVar5 + 0x34) = iVar2;
      if (iVar2 == 2) {
        *(undefined2 *)(iVar5 + 0x66) = 2;
      }
      else {
        *(undefined2 *)(iVar5 + 0x66) = 1;
      }
      if (*(short *)(*(int *)(iVar5 + 0x30) + 0x124) == 0) {
        *(undefined2 *)(iVar5 + 0x68) = *(undefined2 *)(*(int *)(_active_u + 0x1c) + 2);
        *(undefined2 *)(iVar5 + 0x6a) = *(undefined2 *)(param_1 + 0x6a);
      }
      else {
        *(undefined2 *)(iVar5 + 0xe4) = *(undefined2 *)(param_1 + 0xe4);
        *(undefined2 *)(iVar5 + 0xe6) = *(undefined2 *)(param_1 + 0xe6);
        *(undefined2 *)(iVar5 + 0x68) = *(undefined2 *)(*(int *)(iVar5 + 0x30) + 0x124);
        *(undefined2 *)(iVar5 + 0x6a) = _nogroup;
      }
      if (((*(byte *)(iVar5 + 0x65) & 4) != 0) &&
         (iVar6 = _groupmember((int)*(short *)(iVar5 + 0x6a)), iVar6 == 0)) {
        *(ushort *)(iVar5 + 100) = *(ushort *)(iVar5 + 100) & 0xfbff;
      }
      _iupdat(iVar5,1);
      if (iVar2 == 2) {
        local_8 = FUN_0013f0a4(iVar5,param_1);
      }
      if (local_8 == 0) {
        uVar1 = *(ushort *)(iVar5 + 0x44);
        *(ushort *)(iVar5 + 0x44) = uVar1 & 0xfffe;
        if ((uVar1 & 0x10) != 0) {
          *(ushort *)(iVar5 + 0x44) = uVar1 & 0xffee;
          _wakeup(iVar5);
        }
        *param_2 = iVar5;
      }
      else {
        *(undefined2 *)(iVar5 + 0x66) = 0;
        *(byte *)(iVar5 + 0x44) = *(byte *)(iVar5 + 0x44) | 0x40;
        _iput(iVar5);
      }
    }
    return local_8;
  }
                    /* WARNING: Subroutine does not return */
  _panic(s_dirmakeinode__no_attributes_001ddeac);
}

