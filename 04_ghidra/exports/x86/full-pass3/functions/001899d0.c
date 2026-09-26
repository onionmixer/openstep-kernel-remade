/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001899d0 */

void _dbf_handler(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = **(int **)(_active_threads + 0x28);
  do {
    DAT_001f7960 = 8;
    DAT_001f7964 = param_1;
    DAT_001f7968 = *(undefined4 *)(iVar1 + 0x20);
    DAT_001f796c = *(undefined2 *)(iVar1 + 0x4c);
    DAT_001f7970 = *(undefined4 *)(iVar1 + 0x24);
    DAT_001f795c = *(undefined4 *)(iVar1 + 0x28);
    DAT_001f7958 = *(undefined4 *)(iVar1 + 0x2c);
    DAT_001f7954 = *(undefined4 *)(iVar1 + 0x30);
    DAT_001f7950 = *(undefined4 *)(iVar1 + 0x34);
    DAT_001f7948 = *(undefined4 *)(iVar1 + 0x3c);
    DAT_001f7944 = *(undefined4 *)(iVar1 + 0x40);
    DAT_001f7940 = *(undefined4 *)(iVar1 + 0x44);
    DAT_001f793c = *(undefined2 *)(iVar1 + 0x54);
    DAT_001f7938 = *(undefined2 *)(iVar1 + 0x48);
    DAT_001f7934 = *(undefined2 *)(iVar1 + 0x58);
    _dbf_state = *(undefined2 *)(iVar1 + 0x5c);
    _kernel_trap(&_dbf_state);
  } while( true );
}

