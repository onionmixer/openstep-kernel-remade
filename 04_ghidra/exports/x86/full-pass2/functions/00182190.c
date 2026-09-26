/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x00182190 */

undefined4 _kern_dev_map_port_com(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined8 uVar5;
  
  uVar1 = _objc_msgSend(param_1,PTR_s_deviceDescription_001f9378);
  uVar1 = _objc_msgSend(uVar1,PTR_s_resourcesForKey__001f9344,s_I_O_Ports_001e10cb);
  iVar2 = _objc_msgSend(uVar1,PTR_s_count_001f92d8);
  iVar4 = 0;
  if (0 < iVar2) {
    do {
      uVar3 = _objc_msgSend(uVar1,PTR_s_objectAt__001f92e8,iVar4,PTR_s_range_001f9278);
      uVar5 = _objc_msgSend(uVar3);
      _task_map_io_ports(*(undefined4 *)(param_2 + 0xc),uVar5,param_3);
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar2);
  }
  return 0;
}

