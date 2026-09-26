/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a6010. */
int __cdecl -[IOLogicalDisk connectToPhysicalDisk:](IOLogicalDisk *self, SEL a2, id a3)
{
  signed __int8 v3; // al
  signed __int8 v4; // al
  signed __int8 v5; // al
  id v6; // eax

  self->_physicalDisk = a3; /*0x1a601b*/
  -[IODisk setIsPhysical:](self, sel_setIsPhysical_, 0); /*0x1a602b*/
  self->_physicalBlockSize = (unsigned int)objc_msgSend(a3, sel_blockSize); /*0x1a603d*/
  v3 = (unsigned __int8)objc_msgSend(a3, sel_isRemovable); /*0x1a604b*/
  -[IODisk setRemovable:](self, sel_setRemovable_, v3); /*0x1a605c*/
  v4 = (unsigned __int8)objc_msgSend(a3, sel_isFormatted); /*0x1a606c*/
  -[IODisk setFormattedInternal:](self, sel_setFormattedInternal_, v4); /*0x1a607d*/
  v5 = (unsigned __int8)objc_msgSend(a3, sel_isWriteProtected); /*0x1a608a*/
  -[IODisk setWriteProtected:](self, sel_setWriteProtected_, v5); /*0x1a609b*/
  -[IODisk setLogicalDisk:](self, sel_setLogicalDisk_, 0); /*0x1a60ad*/
  v6 = objc_msgSend(a3, sel_devAndIdInfo); /*0x1a60ba*/
  -[IOLogicalDisk setDevAndIdInfo:](self, sel_setDevAndIdInfo_, v6); /*0x1a60c8*/
  return 0; /*0x1a60d2*/
}
