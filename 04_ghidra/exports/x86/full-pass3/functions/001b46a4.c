/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001b46a4 */

int FUN_001b46a4(int param_1,undefined4 param_2,uint param_3,char param_4,int param_5)

{
  uint *puVar1;
  byte bVar2;
  byte bVar3;
  undefined *puVar4;
  
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),PTR_s_lock_001f9220);
  if (*(int *)(param_1 + 0x4ec) != 0) {
    bVar2 = *(byte *)(param_3 + 6 + param_1);
    if (param_4 == '\x01') {
      puVar1 = (uint *)(param_5 + (param_3 >> 5) * 4);
      *puVar1 = *puVar1 | 1 << ((byte)param_3 & 0x1f);
      if ((bVar2 & 0x10) != 0) {
        _objc_msgSend(param_1,PTR_s__doModCalc_keyBits__001f9944,param_3,param_5);
      }
      if ((bVar2 & 0x20) == 0) goto LAB_001b4788;
      param_5 = 1;
      puVar4 = PTR_s__doCharGen_direction__001f9940;
    }
    else {
      bVar3 = (byte)param_3 & 0x1f;
      puVar1 = (uint *)(param_5 + (param_3 >> 5) * 4);
      *puVar1 = *puVar1 & (-2 << bVar3 | 0xfffffffeU >> 0x20 - bVar3);
      if ((bVar2 & 0x20) != 0) {
        _objc_msgSend(param_1,PTR_s__doCharGen_direction__001f9940,param_3,(int)param_4);
      }
      puVar4 = PTR_s__doModCalc_keyBits__001f9944;
      if ((bVar2 & 0x10) == 0) goto LAB_001b4788;
    }
    _objc_msgSend(param_1,puVar4,param_3,param_5);
  }
LAB_001b4788:
  _objc_msgSend(*(undefined4 *)(param_1 + 0x4f4),PTR_s_unlock_001f9474);
  return param_1;
}

