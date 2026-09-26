/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0016d3ec */

void FUN_0016d3ec(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  if (*(int *)(param_1 + 0x14) == 0x76543) {
    puVar2 = (undefined4 *)_kalloc(0x14);
    puVar2[2] = *(undefined4 *)(param_1 + 0x1c);
    puVar2[3] = *(undefined4 *)(param_1 + 0x20);
    puVar2[4] = *(undefined4 *)(param_1 + 0x28);
    puVar1 = puVar2;
    if ((undefined4 **)DAT_001e727c != &DAT_001e7278) {
      *DAT_001e727c = puVar2;
      puVar1 = DAT_001e7278;
    }
    DAT_001e7278 = puVar1;
    puVar2[1] = DAT_001e727c;
    *puVar2 = &DAT_001e7278;
    DAT_001e727c = puVar2;
  }
  else {
    _printf(s_notify_server__bogus_msg_id_on_p_001e0028,*(int *)(param_1 + 0x14));
  }
  return;
}

