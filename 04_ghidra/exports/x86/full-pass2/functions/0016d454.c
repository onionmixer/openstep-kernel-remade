/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d454 */

void FUN_0016d454(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  undefined4 *puVar5;
  undefined4 *puVar6;
  int local_8;
  
  local_8 = 0;
  puVar1 = DAT_001e7278;
  if (*(int *)(param_1 + 0x14) == 0x41) {
joined_r0x0016d48c:
    puVar2 = puVar1;
    if ((undefined4 **)puVar2 != &DAT_001e7278) {
      puVar1 = (undefined4 *)*puVar2;
      if (*(int *)(param_1 + 0x1c) != puVar2[3]) goto LAB_0016d4bc;
      puVar5 = (undefined4 *)puVar2[1];
      puVar6 = puVar1;
      puVar3 = puVar5;
      if ((undefined4 **)puVar1 != &DAT_001e7278) {
        puVar1[1] = puVar5;
        puVar3 = DAT_001e727c;
      }
      goto LAB_0016d513;
    }
    if (local_8 == 0) {
      _printf(s_pn_notify__PORT_NOT_FOUND_001e00a5);
    }
  }
  else {
    _printf(s_pn_notify__msg_id____d__unrecogn_001e005e,*(int *)(param_1 + 0x14));
  }
  return;
LAB_0016d4bc:
  if (puVar2[2] == *(int *)(param_1 + 0x1c)) {
    *(undefined4 *)(param_1 + 0x10) = puVar2[3];
    *(undefined4 *)(param_1 + 0xc) = 0;
    *(undefined1 *)(param_1 + 3) = 1;
    *(undefined1 *)(param_1 + 0x18) = 2;
    *(undefined1 *)(param_1 + 0x19) = 0x20;
    *(undefined4 *)(param_1 + 0x1c) = puVar2[4];
    iVar4 = _msg_send(param_1,1,0);
    if (iVar4 != 0) {
      _printf(s_pn_notify__msg_send_returned__d_001e0084,iVar4);
    }
    puVar6 = (undefined4 *)*puVar2;
    puVar5 = (undefined4 *)puVar2[1];
    puVar3 = puVar5;
    if ((undefined4 **)puVar6 != &DAT_001e7278) {
      puVar6[1] = puVar5;
      puVar3 = DAT_001e727c;
    }
LAB_0016d513:
    DAT_001e727c = puVar3;
    if ((undefined4 **)puVar5 != &DAT_001e7278) {
      *puVar5 = puVar6;
      puVar6 = DAT_001e7278;
    }
    DAT_001e7278 = puVar6;
    _kfree(puVar2,0x14);
    local_8 = local_8 + 1;
  }
  goto joined_r0x0016d48c;
}

