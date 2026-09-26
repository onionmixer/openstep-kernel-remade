/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b9608 */

int FUN_001b9608(int param_1)

{
  uint *puVar1;
  undefined4 uVar2;
  uint *puVar3;
  uint uVar4;
  int iVar5;
  uint *puVar6;
  size_t sVar7;
  uint *puVar8;
  int local_10;
  uint local_c;
  
  uVar2 = _kern_serv_kernel_task_port();
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_lock_001f9220);
  puVar1 = *(uint **)(param_1 + 0x2c);
  while( true ) {
    if ((uint *)(param_1 + 0x2c) == puVar1) {
      _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
      *(undefined1 *)(param_1 + 0x78) = 1;
      return param_1;
    }
    if ((*puVar1 < puVar1[3]) && (puVar1[3] < puVar1[1])) break;
    puVar1 = (uint *)puVar1[0xf];
  }
  puVar3 = (uint *)_IOMalloc(0x44);
  puVar6 = puVar1;
  puVar8 = puVar3;
  for (iVar5 = 0x11; iVar5 != 0; iVar5 = iVar5 + -1) {
    *puVar8 = *puVar6;
    puVar6 = puVar6 + 1;
    puVar8 = puVar8 + 1;
  }
  sVar7 = puVar1[3] - *puVar1;
  local_c = puVar1[4] - sVar7;
  local_10 = puVar1[2] - puVar1[3];
  iVar5 = _vm_allocate_EXTERNAL(uVar2,puVar3,sVar7,1);
  if (iVar5 != 0) {
    _IOLog("Audio: cannot allocate record memory\n");
    _IOFree(puVar3,0x44);
    _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
    *(undefined1 *)(param_1 + 0x78) = 1;
    return param_1;
  }
  puVar1[8] = 0;
  puVar1[10] = 0;
  _bcopy((void *)*puVar1,(void *)*puVar3,sVar7);
  iVar5 = _vm_deallocate_EXTERNAL(uVar2,*puVar1,puVar1[4]);
  if (iVar5 != 0) {
    _IOLog("Audio: vm_deallocate: %s\n","MACH ERR");
  }
  iVar5 = _vm_allocate_EXTERNAL(uVar2,puVar1,local_c,1);
  if (iVar5 != 0) {
    _IOLog("Audio: cannot allocate record memory\n");
    local_10 = 0;
    local_c = 0;
  }
  puVar1[4] = local_c;
  puVar1[1] = local_c + *puVar1;
  puVar1[3] = *puVar1;
  puVar1[2] = local_10 + *puVar1;
  puVar3[4] = sVar7;
  uVar4 = sVar7 + *puVar3;
  puVar3[1] = uVar4;
  puVar3[2] = uVar4;
  puVar3[3] = uVar4;
  puVar3[0xc] = 1;
  puVar3[0xb] = 1;
  uVar4 = *(uint *)(param_1 + 0x2c);
  if (param_1 + 0x2cU == uVar4) {
    *(uint **)(param_1 + 0x2c) = puVar3;
    *(uint **)(param_1 + 0x30) = puVar3;
    puVar3[0xf] = uVar4;
    puVar3[0x10] = uVar4;
  }
  else {
    puVar3[0x10] = param_1 + 0x2cU;
    puVar3[0xf] = uVar4;
    *(uint **)(param_1 + 0x2c) = puVar3;
    *(uint **)(uVar4 + 0x40) = puVar3;
  }
  _objc_msgSend(*(undefined4 *)(param_1 + 0x28),PTR_s_unlock_001f9474);
  *(undefined1 *)(param_1 + 0x78) = 0;
  return param_1;
}

