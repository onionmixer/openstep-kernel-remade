/* Hex-Rays analysis output; not reconstructed GCC 2.7 source.
 * Database: matrox snapshot; requested VA: 0x1ac298. */
void __cdecl -[IODisk completeTransfer:withStatus:actualLength:](
        IODisk *self,
        SEL a2,
        void *a3,
        int a4,
        unsigned int a5)
{
  if ( a4 ) /*0x1ac2a4*/
    *(_BYTE *)a3 |= 4u; /*0x1ac2a6*/
  *((_WORD *)a3 + 14) = (unsigned __int16)-[IODisk errnoFromReturn:](self, sel_errnoFromReturn_, a4); /*0x1ac2ba*/
  *((_DWORD *)a3 + 10) = *((_DWORD *)a3 + 5) - a5; /*0x1ac2c4*/
  biodone(a3); /*0x1ac2c8*/
}
