/* Ghidra decompiler output, not reconstructed GCC 2.7 source.
 * Binary SHA-256: 33469393c0843fc741942c3ae9d91d838467d72abd647dcf2e5bf499a3f14890; entry: 0x001a723c */

void FUN_001a723c(int param_1,undefined4 param_2,int param_3,int param_4)

{
  int *piVar1;
  short sVar2;
  int iVar3;
  char cVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  uint uVar7;
  int local_2c;
  undefined4 local_28;
  char local_24 [32];
  
  piVar1 = (int *)(param_4 + 0x94 + param_3 * 0x30);
  uVar5 = _objc_msgSend(param_1,PTR_s_physicalDisk_001f9c58);
  uVar6 = _objc_msgSend(uVar5,PTR_s_name_001f9228,param_3 + 0x61);
  _sprintf(local_24,"%s%c",uVar6);
  _objc_msgSend(param_1,PTR_s_setName__001f947c,local_24);
  _objc_msgSend(param_1,PTR_s_setDriveName__001f9c78,"IODiskPartition Partition");
  _objc_msgSend(param_1,PTR_s_setLocation__001f9484,0);
  _objc_msgSend(param_1,PTR_s_setDiskSize__001f9c60,piVar1[1]);
  _objc_msgSend(param_1,PTR_s_setBlockSize__001f9c64,*(undefined4 *)(param_4 + 0x30));
  uVar6 = _objc_msgSend(uVar5,PTR_s_unit_001f9c28);
  _objc_msgSend(param_1,PTR_s_setUnit__001f9478,uVar6);
  cVar4 = _objc_msgSend(uVar5,PTR_s_isWriteProtected_001f9cb0);
  _objc_msgSend(param_1,PTR_s_setWriteProtected__001f9c9c,(int)cVar4);
  sVar2 = *(short *)(param_4 + 0x44);
  iVar3 = *piVar1;
  uVar7 = _objc_msgSend(param_1,PTR_s_physicalBlockSize_001f9c54);
  _objc_msgSend(param_1,PTR_s_setPartitionBase__001f9c24,
                (sVar2 + iVar3) * (*(uint *)(param_4 + 0x30) / uVar7));
  *(int *)(param_1 + 0x1a4) = param_3;
  local_2c = param_1;
  local_28 = _objc_getOrigClass("IOLogicalDisk",PTR_s_setFormattedInternal__001f9ca0,1);
  _objc_msgSendSuper(&local_2c);
  *(undefined1 *)(param_1 + 0x1a8) = 1;
  _objc_msgSend(param_1,PTR_s_registerUnixDisk__001f9c74,param_3);
  return;
}

