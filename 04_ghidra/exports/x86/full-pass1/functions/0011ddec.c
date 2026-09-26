/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011ddec */

void _forceclose(short param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  for (puVar2 = _file_list; (undefined4 **)puVar2 != &_file_list; puVar2 = (undefined4 *)*puVar2) {
    if ((((*(short *)((int)puVar2 + 0xe) != 0) && (*(short *)(puVar2 + 3) == 1)) &&
        (iVar1 = puVar2[6], iVar1 != 0)) &&
       (((*(int *)(iVar1 + 0x28) == 4 || (*(int *)(iVar1 + 0x28) == 9)) &&
        (*(short *)(iVar1 + 0x2c) == param_1)))) {
      puVar2[2] = puVar2[2] & 0xfffffffc;
    }
  }
  return;
}

