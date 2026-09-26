/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001370b4 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */

void _svc_getreq(void)

{
  uint uVar1;
  undefined4 *puVar2;
  int iVar3;
  auth_stat aVar4;
  uint uVar5;
  int in_stack_00000004;
  uint local_a0;
  undefined4 *local_88;
  int local_54;
  uint local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined4 *local_44;
  undefined4 local_40;
  undefined4 *local_3c;
  int local_28;
  uint local_24;
  undefined4 local_20;
  undefined4 local_1c;
  undefined4 *local_18;
  undefined4 local_14;
  undefined4 *local_c;
  
  if (_rqcred_head == (undefined4 *)0x0) {
    local_88 = (undefined4 *)_kalloc(0x4b0);
  }
  else {
    local_88 = _rqcred_head;
    _rqcred_head = (undefined4 *)*_rqcred_head;
  }
  local_18 = local_88;
  local_c = local_88 + 100;
  local_3c = local_88 + 200;
  do {
    iVar3 = (*(code *)**(undefined4 **)(in_stack_00000004 + 8))();
    if (iVar3 != 0) {
      local_54 = local_28;
      local_50 = local_24;
      local_4c = local_20;
      local_48 = local_1c;
      local_44 = local_18;
      local_40 = local_14;
      aVar4 = __authenticate();
      if (aVar4 == AUTH_OK) {
        local_a0 = 0xffffffff;
        uVar5 = 0;
        for (puVar2 = DAT_001e5a1c; puVar2 != (undefined4 *)0x0; puVar2 = (undefined4 *)*puVar2) {
          if (puVar2[1] == local_54) {
            uVar1 = puVar2[2];
            if (local_50 == uVar1) {
              (*(code *)puVar2[3])(&local_54);
              goto LAB_001372c2;
            }
            if (uVar1 < local_a0) {
              local_a0 = uVar1;
            }
            if (uVar5 < uVar1) {
              uVar5 = uVar1;
            }
          }
        }
        (**(code **)(*(int *)(in_stack_00000004 + 8) + 0xc))();
        (**(code **)(*(int *)(in_stack_00000004 + 8) + 0x10))();
      }
      else {
        (**(code **)(*(int *)(in_stack_00000004 + 8) + 0xc))();
      }
    }
LAB_001372c2:
    iVar3 = (**(code **)(*(int *)(in_stack_00000004 + 8) + 4))();
    if (iVar3 == 0) {
      (**(code **)(*(int *)(in_stack_00000004 + 8) + 0x14))();
      goto LAB_001372df;
    }
    if (iVar3 != 1) {
LAB_001372df:
      *local_88 = _rqcred_head;
      _rqcred_head = local_88;
      return;
    }
  } while( true );
}

