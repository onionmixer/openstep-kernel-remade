/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b7914 */

int FUN_001b7914(int param_1,undefined4 param_2,undefined4 param_3,char param_4)

{
  char cVar1;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  int local_c;
  undefined *local_8;
  
  local_c = param_1;
  local_8 = PTR_s_Object_001fa4a0;
  _objc_msgSendSuper(&local_c,PTR_s_init_001f924c);
  *(undefined4 *)(param_1 + 4) = param_3;
  *(char *)(param_1 + 0x20) = param_4;
  puVar4 = PTR_s_OutputStream_001f9dc0;
  if (param_4 != '\0') {
    puVar4 = PTR_s_InputStream_001f9dc4;
  }
  uVar2 = _objc_msgSend(puVar4,PTR_s_class_001f9234);
  *(undefined4 *)(param_1 + 8) = uVar2;
  *(undefined4 *)(param_1 + 0x14) = 0;
  uVar2 = _objc_msgSend(PTR_s_List_001f9d80,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar2 = _objc_msgSend(uVar2);
  *(undefined4 *)(param_1 + 0xc) = uVar2;
  uVar2 = _objc_msgSend(PTR_s_NXLock_001f9da4,PTR_s_alloc_001f9210,PTR_s_init_001f924c);
  uVar2 = _objc_msgSend(uVar2);
  *(undefined4 *)(param_1 + 0x10) = uVar2;
  *(int *)(param_1 + 0x28) = param_1 + 0x24;
  *(int *)(param_1 + 0x24) = param_1 + 0x24;
  *(int *)(param_1 + 0x30) = param_1 + 0x2c;
  *(int *)(param_1 + 0x2c) = param_1 + 0x2c;
  *(undefined4 *)(param_1 + 0x54) = 1;
  *(undefined4 *)(param_1 + 0x4c) = 0;
  cVar1 = _objc_msgSend(*(undefined4 *)(param_1 + 4),PTR_s_isEISAPresent_001f9784);
  if (cVar1 == '\0') {
    iVar3 = _page_size * 8;
  }
  else {
    iVar3 = _page_size << 4;
  }
  _objc_msgSend(param_1,PTR_s_setDMASize__001f9780,iVar3);
  _objc_msgSend(param_1,PTR_s_setDescriptorSize__001f977c,_page_size);
  return param_1;
}

