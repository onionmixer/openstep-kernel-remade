/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00160518 */

void _ns_sleep(undefined4 param_1,undefined4 param_2)

{
  longlong lVar1;
  undefined4 uVar2;
  longlong lVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  
  uVar2 = _splnet();
  lVar1 = CONCAT44(param_2,param_1);
  lVar3 = _clock_value(1);
  _calloutDispatchDelayed(_wakeup,&param_1,lVar3 + lVar1);
  uVar5 = 0x18;
  puVar4 = &param_1;
  _sleep((uint)puVar4);
  _splx(uVar2,puVar4,uVar5);
  return;
}

