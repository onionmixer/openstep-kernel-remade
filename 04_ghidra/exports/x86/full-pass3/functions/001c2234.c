/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001c2234 */

int FUN_001c2234(int param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  int local_c;
  undefined4 local_8;
  
  if (param_3 == 0) {
    local_c = param_1;
    local_8 = _objc_getOrigClass("Object",PTR_s_free_001f921c);
    param_1 = _objc_msgSendSuper(&local_c);
  }
  else {
    local_c = param_1;
    local_8 = _objc_getOrigClass("Object",PTR_s_init_001f924c);
    _objc_msgSendSuper(&local_c);
    piVar2 = (int *)_IOMalloc(0x10);
    *(int **)(param_1 + 4) = piVar2;
    *piVar2 = param_3;
    uVar1 = _objc_msgSend(param_3,PTR_s_code_001f9628);
    *(undefined1 *)(piVar2 + 1) = uVar1;
    iVar3 = _objc_msgSend(param_3,PTR_s_length_001f9624);
    piVar2[2] = iVar3;
    piVar2[3] = 0;
  }
  return param_1;
}

