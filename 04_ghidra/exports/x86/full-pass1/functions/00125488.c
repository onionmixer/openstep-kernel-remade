/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00125488 */

undefined4 *
_in_pcblookup(undefined4 *param_1,uint param_2,short param_3,int param_4,short param_5,uint param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  undefined4 *local_10;
  
  local_10 = (undefined4 *)0x0;
  uVar4 = 3;
  puVar1 = (undefined4 *)*param_1;
  do {
    if (puVar1 == param_1) {
      return local_10;
    }
    if (*(short *)(puVar1 + 6) == param_5) {
      uVar3 = 0;
      if (puVar1[5] == 0) {
        if (param_4 != 0) goto LAB_001254e2;
      }
      else {
        if (param_4 != 0) {
          if (param_4 == puVar1[5]) goto LAB_001254e7;
          goto LAB_0012553b;
        }
LAB_001254e2:
        uVar3 = 1;
      }
LAB_001254e7:
      uVar2 = puVar1[3];
      if (uVar2 == 0) {
        if (param_2 != 0) goto LAB_0012551e;
      }
      else {
        if (param_2 != 0) {
          if (((*(short *)(puVar1 + 4) == param_3) && ((uVar2 & 0xf0) != 0xe0)) &&
             (param_2 == uVar2)) goto LAB_0012551f;
          goto LAB_0012553b;
        }
LAB_0012551e:
        uVar3 = uVar3 + 1;
      }
LAB_0012551f:
      if (((uVar3 == 0) || ((param_6 & 1) != 0)) &&
         ((uVar3 < uVar4 && (uVar4 = uVar3, local_10 = puVar1, uVar3 == 0)))) {
        return puVar1;
      }
    }
LAB_0012553b:
    puVar1 = (undefined4 *)*puVar1;
  } while( true );
}

