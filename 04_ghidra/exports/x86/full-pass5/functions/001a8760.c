/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a8760 */

undefined4 FUN_001a8760(int param_1,undefined4 param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 local_1c [4];
  undefined4 local_18;
  undefined4 local_10;
  undefined4 local_8;
  
  uVar3 = 0x1100;
  if (*(int *)(param_1 + 0x10c) == 0) {
    uVar1 = 0xfffffd21;
  }
  else {
    do {
      local_18 = 0x18;
      local_10 = *(undefined4 *)(param_1 + 0x10c);
      iVar2 = _msg_receive(local_1c,uVar3,0);
      if (iVar2 == -0xcc) {
        return 0xfffffd1f;
      }
      if ((iVar2 != 0) && (iVar2 != -0xcb)) {
        uVar1 = _objc_msgSend(param_1,PTR_s_deviceKind_001f9cc4,iVar2);
        uVar1 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar1);
        _IOLog("%s: %s waitForInterrupt: msg_receive returns %d\n",uVar1);
        return 0xfffffd41;
      }
      if ((uVar3 & 0x100) != 0) {
        if (iVar2 == -0xcb) {
          uVar3 = 0x1000;
        }
        else {
          _thread_block();
        }
      }
    } while (iVar2 != 0);
    *param_3 = local_8;
    uVar1 = 0;
  }
  return uVar1;
}

