/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001aa678 */

undefined4 FUN_001aa678(int param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  undefined4 *puVar1;
  int iVar2;
  
  if (*(char *)(param_1 + 0x128) == '\0') {
    _nb_free(param_3);
  }
  else {
    puVar1 = (undefined4 *)_nb_map(param_3);
    *puVar1 = *param_4;
    *(undefined2 *)(puVar1 + 1) = *(undefined2 *)(param_4 + 1);
    *(undefined4 *)((int)puVar1 + 6) = *(undefined4 *)(param_1 + 0x150);
    *(undefined2 *)((int)puVar1 + 10) = *(undefined2 *)(param_1 + 0x154);
    iVar2 = _nb_size(param_3);
    if (iVar2 < 0x3c) {
      _nb_grow_bot(param_3,0x3c - iVar2);
    }
    _objc_msgSend(param_1,PTR_s_transmit__001f9b3c,param_3);
  }
  return 0;
}

