/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x0011d1a4 */

void _getdirentries(void)

{
  undefined4 *puVar1;
  undefined1 uVar2;
  undefined4 local_28;
  undefined4 local_24;
  int local_20;
  undefined4 *local_1c;
  undefined4 local_18;
  int local_14;
  undefined4 local_10;
  int local_8;
  
  puVar1 = *(undefined4 **)(DAT_001e875c + 0x24);
  uVar2 = _getvnodefp(*puVar1,&local_20);
  *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
  if (*(char *)(DAT_001e875c + 0x68) == '\0') {
    if ((*(byte *)(local_20 + 8) & 1) == 0) {
      *(undefined1 *)(DAT_001e875c + 0x68) = 9;
    }
    else {
      while( true ) {
        local_28 = puVar1[1];
        local_24 = puVar1[2];
        local_1c = &local_28;
        local_18 = 1;
        local_14 = *(int *)(local_20 + 0x1c);
        local_10 = 0;
        local_8 = puVar1[2];
        if (local_14 < 0) break;
        uVar2 = (**(code **)(*(int *)(*(int *)(local_20 + 0x18) + 0x1c) + 0x3c))
                          (*(int *)(local_20 + 0x18),&local_1c,*(undefined4 *)(local_20 + 0x20));
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
        if (puVar1[2] != local_8) goto LAB_0011d27a;
        *(undefined4 *)(local_20 + 0x1c) = 0xfffffc00;
      }
      uVar2 = _getfakedirentries(*(undefined4 *)(local_20 + 0x18),&local_1c,
                                 *(undefined4 *)(local_20 + 0x20));
      *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
LAB_0011d27a:
      if (*(char *)(DAT_001e875c + 0x68) == '\0') {
        uVar2 = _copyout(local_20 + 0x1c,puVar1[3],4);
        *(undefined1 *)(DAT_001e875c + 0x68) = uVar2;
        *(int *)(DAT_001e875c + 0x60) = puVar1[2] - local_8;
        *(int *)(local_20 + 0x1c) = local_14;
      }
    }
  }
  return;
}

