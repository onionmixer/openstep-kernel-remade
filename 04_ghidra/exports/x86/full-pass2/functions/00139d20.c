/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139d20 */

undefined4 FUN_00139d20(int param_1,undefined4 param_2,int param_3)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  byte bStack_5;
  
  if (param_3 < 2) {
    iVar4 = _set_label((int *)(DAT_001e875c + 0x28));
    if (iVar4 != 0) {
      iVar4 = *(int *)(param_1 + 0x30);
      pbVar1 = (byte *)(iVar4 + 0x40);
      *pbVar1 = *pbVar1 & 0xf7;
      _wakeup(iVar4);
      return 4;
    }
    iVar4 = *(int *)(param_1 + 0x30);
    *(int *)(iVar4 + 100) = *(int *)(iVar4 + 100) + -1;
    iVar5 = _stillopen((int)*(short *)(iVar4 + 0x42),*(undefined4 *)(param_1 + 0x28));
    if (iVar5 == 0) {
      uVar2 = *(ushort *)(iVar4 + 0x42);
      uVar3 = *(uint *)(param_1 + 0x28);
      if (uVar3 == 4) {
        (*(code *)(&PTR__nulldev_001e2f3c)[(short)(uVar2 >> 8) * 0xb])((int)(short)uVar2,param_2);
      }
      else if (uVar3 < 5) {
        if (uVar3 == 3) {
          _bflush(*(undefined4 *)(iVar4 + 0x3c),0xffffffff,0xffffffff);
          _binval(*(undefined4 *)(iVar4 + 0x3c));
          bStack_5 = (byte)(uVar2 >> 8);
          (*(code *)(&PTR__nodev_001e2cf8)[(uint)bStack_5 * 6])((int)(short)uVar2,param_2);
        }
      }
      else if (uVar3 == 8) {
        _printf(s_spec_close__got_a_VFIFO____001dd777);
      }
      return 0;
    }
  }
  return 0;
}

