/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a5b58. */
id __cdecl -[IODisk registerDevice](IODisk *self, SEL a2)
{
  id v2; // esi
  id v3; // eax
  id v4; // eax
  objc_super v6; // [esp+8h] [ebp-8h] BYREF

  if ( self->_isPhysical )
  {
    self->_nextLogicalDisk = nullptr; /*0x1a5b70*/
    self->_LogicalDiskLock = +[Object new](aNxlock, sel_new); /*0x1a5b8d*/
    self->_readOps = 0; /*0x1a5b93*/
    self->_bytesRead = 0; /*0x1a5b9d*/
    self->_readTotalTime = 0; /*0x1a5ba7*/
    self->_readLatentTime = 0; /*0x1a5bb1*/
    self->_readRetries = 0; /*0x1a5bbb*/
    self->_readErrors = 0; /*0x1a5bc5*/
    self->_writeOps = 0; /*0x1a5bcf*/
    self->_bytesWritten = 0; /*0x1a5bd9*/
    self->_writeTotalTime = 0; /*0x1a5be3*/
    self->_writeLatentTime = 0; /*0x1a5bed*/
    self->_writeRetries = 0; /*0x1a5bf7*/
    self->_writeErrors = 0; /*0x1a5c01*/
    self->_otherRetries = 0; /*0x1a5c0b*/
    self->_otherErrors = 0; /*0x1a5c15*/
    v6.receiver = self; /*0x1a5c26*/
    v6.super_class = (Class)stru_1FA104.super_class; /*0x1a5c2f*/
    v2 = -[IODevice registerDevice](&v6, sel_registerDevice); /*0x1a5c3b*/
    if ( v2 )
    {
      v3 = -[Object class](self, sel_class); /*0x1a5c58*/
      if ( (unsigned __int8)objc_msgSend(v3, sel_conformsTo_) )
      {
        volCheckRegister(self, *((_WORD *)self->_devAndIdInfo + 17), *((_WORD *)self->_devAndIdInfo + 16)); /*0x1a5cb9*/
      }
      else
      {
        v4 = -[Object class](self, sel_class); /*0x1a5c7c*/
        objc_msgSend(v4, sel_name); /*0x1a5c85*/
        -[IODevice name](self, sel_name); /*0x1a5c93*/
        IOLog("Warning: %s, class %s, does not conform to IOPhysicalDiskMethods\n");
      }
    }
  }
  return v2; /*0x1a5cc3*/
}
