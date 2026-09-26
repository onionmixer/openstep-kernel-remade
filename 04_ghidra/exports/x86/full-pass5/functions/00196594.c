/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00196594 */

undefined4 FUN_00196594(int param_1,undefined4 param_2,uint param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_lock_001f9220);
  if ((((param_3 & 0xa0000000) != 0) && (*(int *)(param_1 + 0x114) != 1)) &&
     (*(int *)(param_1 + 0x114) != 3)) {
    iVar1 = _suser();
    if (iVar1 == 0) {
      uVar2 = 0xd;
    }
    else if (*(int *)(param_1 + 0x114) == 4) {
      uVar2 = 0x10;
    }
    else {
      if (DAT_001e7768 == 0) {
        iVar1 = _BasicAllocateConsole();
      }
      else {
        iVar1 = _objc_msgSend(DAT_001e7768,PTR_s_allocateConsoleInfo_001f949c);
      }
      *(int *)(param_1 + 0x110) = iVar1;
      if (iVar1 == 0) {
        *(undefined4 *)(param_1 + 0x110) = _basicConsole;
      }
      (**(code **)(*(int *)(param_1 + 0x110) + 4))
                (*(int *)(param_1 + 0x110),3,0,1,PTR_s_Alert_001e38b0);
      *(undefined4 *)(param_1 + 0x118) = *(undefined4 *)(param_1 + 0x114);
      *(undefined4 *)(param_1 + 0x114) = 3;
      *(int *)(param_1 + 0x11c) = *(int *)(param_1 + 0x11c) + 1;
    }
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x108),PTR_s_unlock_001f9474);
  return uVar2;
}

