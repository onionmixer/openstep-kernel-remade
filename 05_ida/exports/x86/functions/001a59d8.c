/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1a59d8. */
int __cdecl -[IODisk getIntValues:forParameter:count:](
        IODisk *self,
        SEL a2,
        unsigned int *a3,
        char *a4,
        unsigned int *a5)
{
  int i; // eax
  unsigned int v7; // [esp+Ch] [ebp-44h]
  objc_super v8; // [esp+10h] [ebp-40h] BYREF
  _DWORD v9[14]; // [esp+18h] [ebp-38h]

  v7 = *a5; /*0x1a59e9*/
  if ( !*a5 ) /*0x1a59e9*/
    v7 = 512; /*0x1a59f0*/
  if ( !strcmp(a4, "IODiskStats") ) /*0x1a5a07*/
  {
    v9[0] = self->_readOps; /*0x1a5a15*/
    v9[1] = self->_bytesRead; /*0x1a5a1e*/
    v9[2] = self->_readTotalTime; /*0x1a5a27*/
    v9[3] = self->_readLatentTime; /*0x1a5a30*/
    v9[4] = self->_readRetries; /*0x1a5a39*/
    v9[5] = self->_readErrors; /*0x1a5a42*/
    v9[6] = self->_writeOps; /*0x1a5a4b*/
    v9[7] = self->_bytesWritten; /*0x1a5a54*/
    v9[8] = self->_writeTotalTime; /*0x1a5a5d*/
    v9[9] = self->_writeLatentTime; /*0x1a5a66*/
    v9[10] = self->_writeRetries; /*0x1a5a6f*/
    v9[11] = self->_writeErrors; /*0x1a5a78*/
    v9[12] = self->_otherRetries; /*0x1a5a81*/
    v9[13] = self->_otherErrors; /*0x1a5a8a*/
    *a5 = 0; /*0x1a5a8d*/
    for ( i = 0; i <= 13; ++i ) /*0x1a5a93*/
    {
      if ( *a5 == v7 ) /*0x1a5a9d*/
        break; /*0x1a5a9d*/
      a3[i] = v9[i]; /*0x1a5aa6*/
      ++*a5; /*0x1a5aa9*/
    }
    return 0; /*0x1a5aaf*/
  }
  if ( !strcmp(a4, "IOIsADisk") ) /*0x1a5ac4*/
  {
    *a5 = 0; /*0x1a5ac8*/
    return 0; /*0x1a5ad0*/
  }
  if ( !strcmp(a4, "IOIsAPhysicalDisk") ) /*0x1a5ae6*/
  {
    *a5 = 1; /*0x1a5b10*/
    *a3 = self->_isPhysical != 0; /*0x1a5b28*/
    return 0; /*0x1a5b2a*/
  }
  else
  {
    v8.receiver = self; /*0x1a5af8*/
    v8.super_class = (Class)stru_1FA104.super_class; /*0x1a5b01*/
    return -[IODevice getIntValues:forParameter:count:](&v8, sel_getIntValues_forParameter_count_, a3, a4, a5); /*0x1a5b08*/
  }
}
