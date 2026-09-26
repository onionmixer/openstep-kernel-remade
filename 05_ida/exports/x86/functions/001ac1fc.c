/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: ps2 snapshot; requested VA: 0x1ac1fc. */
void *__cdecl -[IOSCSIController allocateBufferOfLength:actualStart:actualLength:](
        IOSCSIController *self,
        SEL a2,
        unsigned int a3,
        void **a4,
        unsigned int *a5)
{
  unsigned int v5; // ebx
  void *v6; // edx
  unsigned int worstCaseAlign; // eax

  v5 = a3 + 2 * self->_worstCaseAlign; /*0x1ac212*/
  v6 = (void *)IOMalloc(v5); /*0x1ac21b*/
  *a4 = v6; /*0x1ac21d*/
  *a5 = v5; /*0x1ac222*/
  worstCaseAlign = self->_worstCaseAlign; /*0x1ac224*/
  if ( worstCaseAlign > 1 ) /*0x1ac22d*/
    return (void *)(((unsigned int)v6 + worstCaseAlign - 1) & -worstCaseAlign); /*0x1ac23a*/
  else
    return v6; /*0x1ac22f*/
}
