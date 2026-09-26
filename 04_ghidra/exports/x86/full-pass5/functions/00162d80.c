/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00162d80 */

void _wait_queue_init(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  iVar3 = 0;
  puVar1 = &_wait_queue;
  iVar2 = 0;
  do {
    *(undefined4 **)((int)&DAT_001f6a14 + iVar2) = puVar1;
    *(undefined4 **)((int)&_wait_queue + iVar3 * 2) = puVar1;
    *(undefined4 *)((int)&_wait_lock + iVar3) = 0;
    iVar3 = iVar3 + 4;
    puVar1 = puVar1 + 2;
    iVar2 = iVar2 + 8;
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x3b);
  return;
}

