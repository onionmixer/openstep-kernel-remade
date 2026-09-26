/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001ae7e0 */

undefined4 FUN_001ae7e0(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = _objc_msgSend(param_3,PTR_s_directDevice_001f9c84);
  iVar2 = _objc_msgSend(uVar1,PTR_s_unit_001f9c28);
  if (iVar2 == 0) {
    iVar2 = 0;
    do {
      uVar3 = _objc_msgSend(param_1,PTR_s_alloc_001f9210);
      (&_sgIdMap)[iVar2] = uVar3;
      _objc_msgSend(uVar3,PTR_s_sgInit_controller__001f9a58,iVar2,uVar1);
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    uVar1 = 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}

