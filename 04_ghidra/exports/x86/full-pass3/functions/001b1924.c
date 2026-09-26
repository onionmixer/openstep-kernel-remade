/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b1924 */

int FUN_001b1924(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = _msg_send(param_3,1,0);
  if (iVar1 != 0) {
    uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,iVar1);
    _IOLog("%s: _performSpecialKeyMsg msg_send returned %d\n",uVar2);
  }
  if (iVar1 == -0x66) {
    _objc_msgSend(param_1,PTR_s_setSpecialKeyPort_keyFlavor_keyP_001f99e4,
                  *(undefined4 *)(param_1 + 0x134),*(undefined4 *)(param_3 + 0x1c),0);
  }
  _IOFree(param_3,0x38);
  return param_1;
}

