/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00140548 */

void _disksort_init(void *param_1)

{
  int iVar1;
  code *pcVar2;
  
  _bzero(param_1,0x28);
  if (DAT_001f50ec == 0) {
    if ((*(byte *)((int)param_1 + 0xc) & 1) == 0) goto LAB_001405a5;
    iVar1 = (*DAT_001f50dc)(param_1);
    if (iVar1 != 0) goto LAB_001405a5;
    *(byte *)((int)param_1 + 0xc) = *(byte *)((int)param_1 + 0xc) & 0xfe;
    pcVar2 = DAT_001f50e8;
  }
  else {
    if (((*(byte *)((int)param_1 + 0xc) & 1) != 0) ||
       (*(int *)((int)param_1 + 0x10) != (int)param_1 + 0x10)) goto LAB_001405a5;
    *(byte *)((int)param_1 + 0xc) = *(byte *)((int)param_1 + 0xc) | 1;
    pcVar2 = DAT_001f50e4;
  }
  (*pcVar2)(param_1);
LAB_001405a5:
  *(int *)((int)param_1 + 0x14) = (int)param_1 + 0x10;
  *(int *)((int)param_1 + 0x10) = (int)param_1 + 0x10;
  *(undefined4 *)((int)param_1 + 0x18) = 0x14;
  *(undefined4 *)((int)param_1 + 0x24) = 0;
  return;
}

