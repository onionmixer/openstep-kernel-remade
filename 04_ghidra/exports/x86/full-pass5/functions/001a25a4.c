/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a25a4 */

undefined4 _PCemulateREAL(int param_1,int param_2)

{
  char cVar1;
  ushort uVar2;
  short sVar3;
  bool bVar4;
  undefined4 uVar5;
  int iVar6;
  int in_FS_OFFSET;
  undefined4 local_10;
  
  if (*(int *)(param_2 + 0x30) == 0xd) {
    local_10 = 0;
    bVar4 = false;
    uVar2 = *(ushort *)(param_2 + 0x3c);
    sVar3 = *(short *)(param_2 + 0x38);
    iVar6 = 0;
    do {
      *(code **)(param_1 + 0x74) = __analysis_fragment_001a2614;
      cVar1 = *(char *)(in_FS_OFFSET + (uint)uVar2 * 0x10 + (uint)(ushort)(sVar3 + (short)iVar6));
      *(undefined4 *)(param_1 + 0x74) = 0;
      if (cVar1 == 'f') {
        local_10 = 1;
      }
      else if (cVar1 != -0x10) {
        if ((*(code **)(&DAT_001e4b80 + (uint)(byte)(cVar1 + 0x70) * 4) != (code *)0x0) &&
           (iVar6 = (**(code **)(&DAT_001e4b80 + (uint)(byte)(cVar1 + 0x70) * 4))
                              (param_1,param_2,iVar6,local_10), iVar6 != 0)) {
          bVar4 = true;
        }
        break;
      }
      iVar6 = iVar6 + 1;
    } while (iVar6 < 0xf);
    if (!bVar4) {
      uVar5 = FUN_001a2384(param_1,param_2);
      return uVar5;
    }
  }
  else {
    if (*(int *)(param_2 + 0x30) != 6) {
      uVar5 = FUN_001a2384(param_1,param_2);
      return uVar5;
    }
    iVar6 = FUN_001a1b60(param_1,param_2);
    if (iVar6 == 0) {
      uVar5 = FUN_001a2384(param_1,param_2);
      return uVar5;
    }
  }
  return 1;
}

