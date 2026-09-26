/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6d68. */
int __cdecl -[IODiskPartition eject](IODiskPartition *self, SEL a2)
{
  id v2; // esi
  int result; // eax
  objc_super v4; // [esp+8h] [ebp-8h] BYREF

  v2 = -[IOLogicalDisk physicalDisk](self, sel_physicalDisk); /*0x1a6d80*/
  result = -[IODiskPartition checkSafeConfig:](self, sel_checkSafeConfig_, "eject"); /*0x1a6d8f*/
  if ( !result ) /*0x1a6d99*/
  {
    -[IODiskPartition _freePartitions](self, sel__freePartitions); /*0x1a6da3*/
    self->_labelValid = 0; /*0x1a6da8*/
    v4.receiver = self; /*0x1a6db8*/
    v4.super_class = (Class)stru_1FA154.super_class; /*0x1a6dc1*/
    -[IODisk setFormattedInternal:](&v4, sel_setFormattedInternal_, 0); /*0x1a6dc8*/
    if ( (unsigned __int8)objc_msgSend(v2, sel_needsManualPolling) ) /*0x1a6dd5*/
      vol_check_manual_poll(); /*0x1a6de1*/
    return (int)objc_msgSend(v2, sel_ejectPhysical); /*0x1a6dee*/
  }
  return result; /*0x1a6df6*/
}
