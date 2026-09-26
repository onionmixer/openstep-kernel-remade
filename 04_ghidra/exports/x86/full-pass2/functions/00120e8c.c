/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00120e8c */

undefined4 *
_if_attach(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
          undefined4 param_5,undefined4 param_6,undefined2 param_7,undefined4 param_8,
          undefined2 param_9,undefined2 param_10,uint param_11,undefined4 param_12)

{
  undefined4 *puVar1;
  bool bVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  byte local_c;
  byte local_b;
  undefined4 local_a;
  
  bVar2 = false;
  puVar3 = _ifnet;
  do {
    if (puVar3 == (undefined4 *)0x0) {
LAB_00120ebc:
      if (!bVar2) {
        puVar3 = (undefined4 *)_kalloc(0x60);
        _bzero(puVar3,0x60);
      }
      *puVar3 = param_6;
      puVar3[1] = param_8;
      *(undefined2 *)(puVar3 + 2) = param_7;
      *(undefined2 *)((int)puVar3 + 10) = param_9;
      *(undefined2 *)(puVar3 + 3) = param_10;
      puVar3[4] = 0;
      puVar3[6] = 0;
      puVar3[10] = _ifqmaxlen;
      puVar3[0xc] = param_1;
      puVar3[0xd] = param_3;
      puVar3[0xe] = param_5;
      puVar3[0xf] = param_2;
      puVar3[0x10] = param_4;
      puVar3[0x16] = param_12;
      puVar3[5] = param_11;
      puVar3[0x11] = 0;
      puVar3[0x12] = 0;
      puVar3[0x13] = 0;
      puVar3[0x14] = 0;
      puVar3[0x15] = 0;
      if (!bVar2) {
        piVar5 = (int *)&_ifnet;
        puVar1 = _ifnet;
        while ((puVar1 != (undefined4 *)0x0 &&
               (iVar4 = *piVar5, param_11 <= *(uint *)(iVar4 + 0x14)))) {
          puVar1 = *(undefined4 **)(iVar4 + 0x5c);
          piVar5 = (int *)(iVar4 + 0x5c);
        }
        puVar3[0x17] = *piVar5;
        *piVar5 = (int)puVar3;
      }
      puVar1 = DAT_001e58d8;
      if (puVar3[5] == 0) {
        for (; puVar1 != (undefined4 *)0x0; puVar1 = (undefined4 *)puVar1[2]) {
          (*(code *)*puVar1)(puVar1[1],puVar3);
        }
        if (_hostid == 0) {
          if (((code *)puVar3[0xe] != (code *)0x0) &&
             (iVar4 = (*(code *)puVar3[0xe])(puVar3,"getaddr",&local_c), iVar4 == 0)) {
            local_a._0_2_ = CONCAT11(local_a._1_1_ ^ local_b,(byte)local_a ^ local_c);
            _hostid = (uint)(local_a._2_2_ >> 8) | (local_a._2_2_ & 0xff) << 8 |
                      ((ushort)local_a & 0xff00) << 8 | local_a << 0x18;
          }
        }
      }
      return puVar3;
    }
    if (((undefined *)*puVar3 == &DAT_001d1271) && (puVar3[5] == param_11)) {
      bVar2 = true;
      goto LAB_00120ebc;
    }
    puVar3 = (undefined4 *)puVar3[0x17];
  } while( true );
}

