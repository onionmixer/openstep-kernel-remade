/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a702c. */
void __cdecl -[IODiskPartition setFormattedInternal:](IODiskPartition *self, SEL a2, char a3)
{
  objc_super v3; // [esp+4h] [ebp-8h] BYREF

  -[IODiskPartition _freePartitions](self, sel__freePartitions); /*0x1a7041*/
  self->_labelValid = 0; /*0x1a7049*/
  v3.receiver = self; /*0x1a705e*/
  v3.super_class = (Class)stru_1FA154.super_class; /*0x1a7067*/
  -[IODisk setFormattedInternal:](&v3, sel_setFormattedInternal_, a3); /*0x1a706e*/
}
