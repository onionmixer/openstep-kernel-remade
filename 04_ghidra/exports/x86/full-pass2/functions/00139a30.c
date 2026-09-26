/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00139a30 */

undefined4 * FUN_00139a30(ushort param_1,int param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  
  puVar1 = (undefined4 *)(&_stable)[(uint)param_1._1_1_ + (param_1 & 0xff) & 0xf];
  do {
    if (puVar1 == (undefined4 *)0x0) {
      return (undefined4 *)0x0;
    }
    if ((*(ushort *)((int)puVar1 + 0x42) == param_1) && (puVar1[0xb] == param_3)) {
      iVar2 = puVar1[0xe];
      if (iVar2 != 0) {
        if (param_2 != 0) {
          if (iVar2 == param_2) goto LAB_00139aa0;
          if (iVar2 == 0) goto LAB_00139a9c;
          if ((*(int *)(param_2 + 0x1c) == *(int *)(iVar2 + 0x1c)) &&
             (iVar2 = (**(code **)(*(int *)(iVar2 + 0x1c) + 0x6c))(iVar2,param_2), iVar2 != 0))
          goto LAB_00139aa0;
        }
        if (puVar1[0xe] != 0) goto LAB_00139aa8;
      }
LAB_00139a9c:
      if (param_2 == 0) {
LAB_00139aa0:
        *(short *)((int)puVar1 + 10) = *(short *)((int)puVar1 + 10) + 1;
        return puVar1;
      }
    }
LAB_00139aa8:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

