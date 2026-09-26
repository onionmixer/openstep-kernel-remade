/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a7fd4 */

undefined4 FUN_001a7fd4(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 uVar4;
  
  uVar4 = 0xfffffd42;
  uVar2 = _objc_msgSend(param_1,PTR_s__delegate_001f9c08,
                        PTR_s_allocateItems_numItems_forKey__001f9c00,param_3,param_4,"IRQ Levels");
  iVar3 = _objc_msgSend(uVar2);
  if (iVar3 != 0) {
    puVar1 = *(undefined4 **)(param_1 + 0x10);
    if (puVar1[1] != 0) {
      _IOFree(*puVar1,puVar1[1] << 2);
    }
    puVar1[1] = 0;
    uVar4 = 0;
  }
  return uVar4;
}

