/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a5b58 */

int FUN_001a5b58(int param_1)

{
  char cVar1;
  undefined4 uVar2;
  int unaff_ESI;
  int local_c;
  undefined *local_8;
  
  if (*(char *)(param_1 + 0x116) != '\0') {
    *(undefined4 *)(param_1 + 0x108) = 0;
    uVar2 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_new_001f9468);
    *(undefined4 *)(param_1 + 0x11c) = uVar2;
    *(undefined4 *)(param_1 + 0x13c) = 0;
    *(undefined4 *)(param_1 + 0x140) = 0;
    *(undefined4 *)(param_1 + 0x144) = 0;
    *(undefined4 *)(param_1 + 0x148) = 0;
    *(undefined4 *)(param_1 + 0x14c) = 0;
    *(undefined4 *)(param_1 + 0x150) = 0;
    *(undefined4 *)(param_1 + 0x154) = 0;
    *(undefined4 *)(param_1 + 0x158) = 0;
    *(undefined4 *)(param_1 + 0x15c) = 0;
    *(undefined4 *)(param_1 + 0x160) = 0;
    *(undefined4 *)(param_1 + 0x164) = 0;
    *(undefined4 *)(param_1 + 0x168) = 0;
    *(undefined4 *)(param_1 + 0x16c) = 0;
    *(undefined4 *)(param_1 + 0x170) = 0;
    local_c = param_1;
    local_8 = PTR_s_IODevice_001fa108;
    unaff_ESI = _objc_msgSendSuper(&local_c,PTR_s_registerDevice_001f948c);
    if (unaff_ESI != 0) {
      uVar2 = _objc_msgSend(param_1,PTR_s_class_001f9234,PTR_s_conformsTo__001f9238,&DAT_001fddb8);
      cVar1 = _objc_msgSend(uVar2);
      if (cVar1 == '\0') {
        uVar2 = _objc_msgSend(param_1,PTR_s_class_001f9234,PTR_s_name_001f9228);
        uVar2 = _objc_msgSend(uVar2);
        uVar2 = _objc_msgSend(param_1,PTR_s_name_001f9228,uVar2);
        _IOLog("Warning: %s, class %s, does not conform to IOPhysicalDiskMethods\n",uVar2);
      }
      else {
        _volCheckRegister(param_1,(int)*(short *)(*(int *)(param_1 + 0x118) + 0x22),
                          (int)*(short *)(*(int *)(param_1 + 0x118) + 0x20));
      }
    }
  }
  return unaff_ESI;
}

